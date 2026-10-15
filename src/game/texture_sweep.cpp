// Texture dump and texture sweep (DEV tab > Texture dump), for making texture packs.
//
// "While playing" starts RT64's own texture dumper (lib-patches/rt64.patch adds
// RT64::SetTextureDumpDirectory so it runs without the debugger window) in
// texture_dump/raw/ in the app-data folder. RT64 writes each texture once, by its
// RT64 hash, as raw TMEM and RDRAM files; RT64's texture_hasher tool turns that folder
// into an rt64.json with Rice hashes too. RT64 only decodes textures on the GPU, so each
// newly dumped texture is also decoded here (a CPU copy of lib/rt64/src/shaders/
// TextureDecoder.hlsli) and saved as texture_dump/png/<hash>.png, on a thread of its own.
// texture_dump/png/rt64.json lists every PNG by its RT64 hash, so that folder is a
// texture pack as it stands.
//
// "Sweep all maps" also warps to every map in map_names.inc (multiplayer maps, the title
// screen and the game select left out; cutscene maps last), waits for the map to load and
// fade in, holds C-right to turn the camera around, and moves on. Progress is written to
// texture_dump/sweep.txt as it goes. A sweep only runs when the option is picked while the
// game is running: left on from an earlier run it does nothing, not even dumping, so it never
// warps anyone around in normal play. Picking it again after the game stopped mid-sweep
// carries on after the map it stopped in and skips that map. When the sweep is done it warps
// back to where it started and stops dumping; the option then does nothing until picked again.
//
// Warping through maps every few seconds loads a texture pack's replacements much faster
// than normal play. RT64 keeps replacements nobody uses until its pool (2/3 of video memory)
// fills, and with a 4K pack on top of large framebuffers that ran L's GPU out of memory
// (vmaCreateImage 0xFFFFFFFE, then a driver crash). While a sweep runs, the pool is capped at
// sweep_pool_limit so the last maps' replacements are freed as new ones load.
//
// Everything written is ROM-derived: it stays in the app-data folder, never in the repo.
//
// Headless: TOOIE_TEXTURE_DUMP=play|sweep sets the option whatever the menu says,
// TOOIE_TEXTURE_SWEEP_MAPS=AF,B8,... sweeps only those maps (hex), and
// TOOIE_TEXTURE_DUMP_DIR=<dir> writes there instead of the app-data folder.

#include <algorithm>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <filesystem>
#include <fstream>
#include <functional>
#include <mutex>
#include <set>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#include "recomp.h"
#include "librecomp/game.hpp"
#include "recompui/config.h"

#include "common/rt64_load_types.h"

#include "tooie_debug.h"
#include "tooie_game.h"
#include "tooie_texture_sweep.h"
#include "tooie_toast.h"
#include "tooie_vram_log.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_WRITE_STATIC
#include "../../lib/rt64/src/contrib/stb/stb_image_write.h"

namespace RT64 {
    // lib/rt64/src/hle/rt64_rdp_tmem.h (from lib-patches/rt64.patch).
    typedef std::function<void(const std::filesystem::path &basePath, const uint8_t *tmem, const LoadTile &loadTile, uint16_t width, uint16_t height, uint32_t tlut)> TextureDumpCallback;
    void SetTextureDumpDirectory(const std::filesystem::path &directory, TextureDumpCallback callback);
    // lib/rt64/src/render/rt64_texture_cache.h (from lib-patches/rt64.patch).
    void SetReplacementPoolLimit(uint64_t bytes);
}

namespace {
    namespace fs = std::filesystem;
    using steady = std::chrono::steady_clock;
    using namespace std::chrono_literals;

    struct MapName {
        uint16_t id;
        const char* name;
    };

    constexpr MapName map_names[] = {
#include "map_names.inc"
    };

    // Not swept: the title screen and game select (no file being played there), the
    // multiplayer arenas, which set up two to four players and share their textures with
    // the one-player maps, and cutscenes that crash when entered straight from another map
    // (0xAC, Banjo's house is destroyed: its intro character plays an animation the earlier
    // intro scenes set up, and reads a null pointer in chanim_entrypoint_6 without them).
    constexpr uint16_t skipped_maps[] = {
        0x158, 0x18B,
        0x164, 0x165, 0x166, 0x17B, 0x17C, 0x182, 0x183, 0x188, 0x189,
        0xAC,
    };

    // ---- Texture decoding (lib/rt64/src/shaders/TextureDecoder.hlsli and Formats.hlsli) ----

    constexpr uint32_t tmem_bytes = 0x1000;
    constexpr uint32_t tmem_palette = 0x800;
    constexpr uint32_t tmem_mask8 = 0xFFF;
    constexpr uint32_t tmem_mask16 = 0x7FF;
    constexpr uint8_t fmt_rgba = 0, fmt_yuv = 1, fmt_ci = 2, fmt_ia = 3, fmt_i = 4;
    constexpr uint8_t siz_4b = 0, siz_8b = 1, siz_16b = 2, siz_32b = 3;
    constexpr uint32_t tt_rgba16 = 2 << 14, tt_ia16 = 3 << 14;

    struct Rgba {
        uint8_t r, g, b, a;
    };

    Rgba gray(uint32_t i, uint32_t a = 255) { return {(uint8_t)i, (uint8_t)i, (uint8_t)i, (uint8_t)a}; }

    Rgba from_i4(uint32_t v) { return gray((v << 4) | v); }

    Rgba from_ia4(uint32_t v) {
        uint32_t i = v & 0b1110;
        i = (i << 4) | (i << 1) | (i >> 2);
        return gray(i & 0xFF, (v & 1) ? 255 : 0);
    }

    Rgba from_ia8(uint32_t v) {
        uint32_t i = (v >> 4) & 0xF, a = v & 0xF;
        return gray((i << 4) | i, (a << 4) | a);
    }

    Rgba from_rgba16(uint32_t v) {
        uint32_t r = (v >> 11) & 0x1F, g = (v >> 6) & 0x1F, b = (v >> 1) & 0x1F;
        return {(uint8_t)((r << 3) | (r >> 2)), (uint8_t)((g << 3) | (g >> 2)), (uint8_t)((b << 3) | (b >> 2)), (uint8_t)((v & 1) ? 255 : 0)};
    }

    Rgba from_ia16(uint32_t v) { return gray((v >> 8) & 0xFF, v & 0xFF); }

    struct TmemReader {
        const uint8_t* tmem;
        uint32_t address;
        uint32_t stride;
        bool odd_row;

        // implLoadTMEM: odd rows have their 32-bit words swapped in pairs.
        uint32_t load(uint32_t relative, uint32_t mask, uint32_t or_address) const {
            uint32_t final_address;
            if (odd_row && stride > 0) {
                uint32_t row_start = (relative / stride) * stride;
                uint32_t word = ((relative - row_start) / 4) ^ 1;
                final_address = address + row_start + word * 4 + (relative & 3);
            } else {
                final_address = address + relative;
            }
            return tmem[((final_address & mask) | or_address) & tmem_mask8];
        }
    };

    // sampleTMEM for one texel.
    Rgba sample(const uint8_t* tmem, int x, int y, uint8_t siz, uint8_t fmt, uint32_t address, uint32_t stride, uint32_t tlut, uint32_t palette) {
        const bool odd_column = x & 1;
        const bool rgba32 = fmt == fmt_rgba && siz == siz_32b;
        const bool uses_tlut = tlut > 0;
        const uint32_t shift = rgba32 ? 2 : siz;
        const uint32_t mask = (rgba32 || uses_tlut) ? tmem_mask16 : tmem_mask8;
        const TmemReader reader{tmem, address, stride, (y & 1) != 0};

        const uint32_t pixel_address = y * stride + (((uint32_t)x << shift) >> 1);
        const uint32_t v0 = reader.load(pixel_address + 0, mask, 0);
        const uint32_t v1 = reader.load(pixel_address + 1, mask, 0);
        const uint32_t v4 = (v0 >> (odd_column ? 0 : 4)) & 0xF;

        if (uses_tlut) {
            uint32_t palette_address = siz == siz_4b
                ? tmem_palette + (palette << 7) + (v4 << 3)
                : tmem_palette + (v0 << 3);
            uint32_t value = tmem[(palette_address + 1) & tmem_mask8] | (tmem[palette_address & tmem_mask8] << 8);
            if (tlut == tt_rgba16) {
                return from_rgba16(value);
            }
            if (tlut == tt_ia16) {
                return from_ia16(value);
            }
            return {0, 0, 0, 255};
        }

        const uint32_t pixel_address2 = rgba32 ? pixel_address : pixel_address + 2;
        const uint32_t or_address = rgba32 ? (tmem_bytes >> 1) : 0;
        const uint32_t v2 = reader.load(pixel_address2 + 0, mask, or_address);
        const uint32_t v3 = reader.load(pixel_address2 + 1, mask, or_address);

        switch (siz) {
            case siz_4b:
                switch (fmt) {
                    case fmt_ci: return gray((palette << 4) | v4);
                    case fmt_ia: return from_ia4(v4);
                    case fmt_i:
                    case fmt_rgba: return from_i4(v4);
                    default: return {0, 0, 0, 255};
                }
            case siz_8b:
                switch (fmt) {
                    case fmt_ia: return from_ia8(v0);
                    case fmt_i:
                    case fmt_rgba:
                    case fmt_ci: return gray(v0);
                    default: return {0, 0, 0, 255};
                }
            case siz_16b:
                switch (fmt) {
                    case fmt_rgba: return from_rgba16(v1 | (v0 << 8));
                    case fmt_ia: return from_ia16(v1 | (v0 << 8));
                    case fmt_ci:
                    case fmt_i: return {(uint8_t)v0, (uint8_t)v1, (uint8_t)v0, (uint8_t)v1};
                    default: return {0, 0, 0, 255};
                }
            case siz_32b:
                switch (fmt) {
                    case fmt_rgba: return {(uint8_t)v0, (uint8_t)v1, (uint8_t)v2, (uint8_t)v3};
                    case fmt_ci:
                    case fmt_ia:
                    case fmt_i:
                        return odd_column
                            ? Rgba{(uint8_t)v0, (uint8_t)v1, (uint8_t)v0, (uint8_t)v1}
                            : Rgba{(uint8_t)v2, (uint8_t)v3, (uint8_t)v2, (uint8_t)v3};
                    default: return {0, 0, 0, 255};
                }
            default:
                return {0, 0, 0, 255};
        }
    }

    // ---- PNG writer thread ----

    struct DumpedTexture {
        std::string name;  // RT64 hash, 16 hex digits
        std::vector<uint8_t> tmem;
        RT64::LoadTile tile;
        uint16_t width;
        uint16_t height;
        uint32_t tlut;
    };

    std::mutex queue_mutex;
    std::condition_variable queue_cv;
    std::deque<DumpedTexture> queue;
    fs::path png_folder;
    std::atomic<uint32_t> new_pngs{0};
    std::once_flag writer_flag;

    void write_png(const DumpedTexture& t, const fs::path& folder) {
        fs::path path = folder / (t.name + ".png");
        std::error_code ec;
        if (fs::exists(path, ec)) {
            return;
        }
        const uint32_t address = uint32_t(t.tile.tmem) << 3;
        const uint32_t stride = uint32_t(t.tile.line) << 3;
        std::vector<uint8_t> rgba(size_t(t.width) * t.height * 4);
        for (int y = 0; y < t.height; y++) {
            for (int x = 0; x < t.width; x++) {
                Rgba c = sample(t.tmem.data(), x, y, t.tile.siz, t.tile.fmt, address, stride, t.tlut, t.tile.palette);
                uint8_t* p = &rgba[(size_t(y) * t.width + x) * 4];
                p[0] = c.r; p[1] = c.g; p[2] = c.b; p[3] = c.a;
            }
        }
        // Write to a temporary name first, so a game that stops halfway leaves no broken PNG.
        fs::path temp = path;
        temp += ".part";
        if (stbi_write_png(temp.string().c_str(), t.width, t.height, 4, rgba.data(), t.width * 4)) {
            fs::rename(temp, path, ec);
            if (!ec) {
                new_pngs++;
            }
        }
    }

    void writer_thread() {
        while (true) {
            DumpedTexture t;
            fs::path folder;
            {
                std::unique_lock lock{queue_mutex};
                queue_cv.wait(lock, [] { return !queue.empty(); });
                t = std::move(queue.front());
                queue.pop_front();
                folder = png_folder;
            }
            if (!folder.empty()) {
                write_png(t, folder);
            }
        }
    }

    // Called by RT64 on its renderer thread for each texture it dumps the first time.
    void on_texture_dumped(const fs::path& base_path, const uint8_t* tmem, const RT64::LoadTile& tile, uint16_t width, uint16_t height, uint32_t tlut) {
        std::string name = base_path.filename().string();
        name = name.substr(0, name.find('.'));
        DumpedTexture t{name, std::vector<uint8_t>(tmem, tmem + tmem_bytes), tile, width, height, tlut};
        {
            std::lock_guard lock{queue_mutex};
            queue.push_back(std::move(t));
        }
        queue_cv.notify_one();
    }

    // texture_dump/png/rt64.json: every PNG there by its RT64 hash, so the folder loads as a pack.
    void write_pack_database(const fs::path& folder) {
        std::error_code ec;
        std::vector<std::string> hashes;
        for (const auto& entry : fs::directory_iterator(folder, ec)) {
            if (entry.path().extension() == ".png") {
                hashes.push_back(entry.path().stem().string());
            }
        }
        std::sort(hashes.begin(), hashes.end());
        std::ofstream out(folder / "rt64.json");
        out << "{\n    \"configuration\": {\n        \"autoPath\": \"rt64\",\n        \"configurationVersion\": 3,\n"
               "        \"hashVersion\": 5,\n        \"defaultOperation\": \"stream\",\n        \"defaultShift\": \"half\"\n    },\n"
               "    \"textures\": [\n";
        for (size_t i = 0; i < hashes.size(); i++) {
            out << "        { \"hashes\": { \"rt64\": \"" << hashes[i] << "\" }, \"path\": \"" << hashes[i] << "\" }"
                << (i + 1 < hashes.size() ? ",\n" : "\n");
        }
        out << "    ]\n}\n";
    }

    // ---- Option and folders ----

    tooie::TextureDump option_value() {
        static const char* env = std::getenv("TOOIE_TEXTURE_DUMP");
        if (env != nullptr) {
            if (std::strcmp(env, "sweep") == 0) return tooie::TextureDump::SweepAllMaps;
            if (std::strcmp(env, "play") == 0) return tooie::TextureDump::WhilePlaying;
            return tooie::TextureDump::Off;
        }
        uint32_t value = 0;
        try {
            value = std::get<uint32_t>(recompui::config::get_config(tooie::wip_tab_id).get_option_value(tooie::texture_dump_option));
        } catch (...) {
        }
        return static_cast<tooie::TextureDump>(value);
    }

    fs::path dump_folder() {
        if (const char* env = std::getenv("TOOIE_TEXTURE_DUMP_DIR")) {
            return fs::path(env);
        }
        return recomp::get_config_path() / "texture_dump";
    }

    void start_dumping(const fs::path& root) {
        std::call_once(writer_flag, [] { std::thread(writer_thread).detach(); });
        std::error_code ec;
        fs::create_directories(root / "png", ec);
        {
            std::lock_guard lock{queue_mutex};
            png_folder = root / "png";
        }
        RT64::SetTextureDumpDirectory(root / "raw", on_texture_dumped);
        printf("[texture-dump] dumping to %s\n", root.string().c_str());
        fflush(stdout);
    }

    void stop_dumping(const fs::path& root) {
        RT64::SetTextureDumpDirectory({}, nullptr);
        // Let the PNGs already queued finish before listing them.
        for (int i = 0; i < 200; i++) {
            {
                std::lock_guard lock{queue_mutex};
                if (queue.empty()) {
                    break;
                }
            }
            std::this_thread::sleep_for(10ms);
        }
        write_pack_database(root / "png");
        printf("[texture-dump] stopped\n");
        fflush(stdout);
    }

    // ---- Sweep ----

    enum class Phase { Idle, WaitForFile, Warping, Settling, Turning, Returning, Done };

    // Times per map: the wipe-out and load before the map shows, the fade-in, and the camera turn.
    constexpr auto load_timeout = 25s;
    constexpr auto settle_time = 3s;
    constexpr auto turn_time = 6s;
    // C-right is pressed in pulses; each press swings the camera an eighth of a turn.
    constexpr auto turn_pulse = 400ms;
    constexpr auto turn_press = 150ms;
    constexpr uint16_t c_right = 0x0001;
    constexpr uint64_t sweep_pool_limit = 1024ull * 1024 * 1024;

    struct Target {
        uint16_t map;
        std::string name;
    };

    fs::path root;
    bool dumping = false;
    bool first_tick = true;
    // Set when "Sweep all maps" is picked in this run; cleared when the sweep ends.
    bool armed = false;
    bool pool_capped = false;
    tooie::TextureDump last_value = tooie::TextureDump::Off;
    Phase phase = Phase::Idle;
    std::vector<Target> targets;
    size_t next_target = 0;
    uint16_t start_map = 0;
    steady::time_point phase_start;
    uint32_t pngs_at_map_start = 0;
    std::atomic<bool> turning{false};
    std::atomic<int64_t> turn_start_ns{0};

    bool is_cutscene(const char* name) { return std::strncmp(name, "Cutscene", 8) == 0; }

    std::vector<Target> all_targets() {
        std::vector<Target> list;
        if (const char* env = std::getenv("TOOIE_TEXTURE_SWEEP_MAPS")) {
            std::stringstream items(env);
            std::string item;
            while (std::getline(items, item, ',')) {
                uint16_t id = (uint16_t)std::strtoul(item.c_str(), nullptr, 16);
                const char* name = "?";
                for (const MapName& m : map_names) {
                    if (m.id == id) name = m.name;
                }
                list.push_back({id, name});
            }
            return list;
        }
        for (int pass = 0; pass < 2; pass++) {
            for (const MapName& m : map_names) {
                if (std::find(std::begin(skipped_maps), std::end(skipped_maps), m.id) != std::end(skipped_maps)) {
                    continue;
                }
                // Places first, cutscenes last: a cutscene can end the game's own way (the
                // credits go back to the title), so they come when nothing else is left.
                if (is_cutscene(m.name) == (pass == 0)) {
                    continue;
                }
                list.push_back({m.id, m.name});
            }
        }
        return list;
    }

    void log_line(const std::string& line) {
        std::ofstream out(root / "sweep.txt", std::ios::app);
        out << line << "\n";
        out.flush();
        printf("[texture-sweep] %s\n", line.c_str());
        fflush(stdout);
    }

    std::string hex(uint16_t map) {
        char buf[16];
        snprintf(buf, sizeof(buf), "0x%03X", map);
        return buf;
    }

    enum class Progress { None, Unfinished, Finished };

    // Reads sweep.txt: the maps already done, and whether the sweep finished.
    Progress read_progress(std::set<uint16_t>& done) {
        std::ifstream in(root / "sweep.txt");
        if (!in) {
            return Progress::None;
        }
        std::string line;
        bool finished = false;
        bool any = false;
        int open_map = -1;
        while (std::getline(in, line)) {
            unsigned map = 0;
            char word[16] = {};
            if (std::sscanf(line.c_str(), "%15s %x", word, &map) < 1) {
                continue;
            }
            any = true;
            std::string w = word;
            if (w == "start") {
                open_map = (int)map;
            } else if (w == "done" || w == "skipped" || w == "missed") {
                done.insert((uint16_t)map);
                open_map = -1;
            } else if (w == "finished") {
                finished = true;
            } else if (w == "begin") {
                done.clear();
                finished = false;
                open_map = -1;
            }
        }
        if (!any) {
            return Progress::None;
        }
        if (finished) {
            return Progress::Finished;
        }
        if (open_map >= 0) {
            // The game stopped in this map last time: leave it out.
            done.insert((uint16_t)open_map);
            log_line("skipped " + hex((uint16_t)open_map) + " (the game stopped here last time)");
        }
        return Progress::Unfinished;
    }

    void begin_sweep(bool resume) {
        targets = all_targets();
        next_target = 0;
        std::set<uint16_t> done;
        const Progress progress = resume ? read_progress(done) : Progress::None;
        if (progress == Progress::Unfinished) {
            std::vector<Target> left;
            for (const Target& t : targets) {
                if (!done.contains(t.map)) left.push_back(t);
            }
            log_line("resume, " + std::to_string(left.size()) + " of " + std::to_string(targets.size()) + " maps left");
            targets = std::move(left);
        } else {
            std::error_code ec;
            fs::remove(root / "sweep.txt", ec);
            log_line("begin, " + std::to_string(targets.size()) + " maps");
        }
        phase = Phase::WaitForFile;
    }

    void enter(Phase p) {
        phase = p;
        phase_start = steady::now();
    }

    void warp_next(uint8_t* rdram) {
        if (next_target >= targets.size()) {
            log_line("finished");
            tooie::toast::show("Texture sweep finished");
            if (start_map != 0 && start_map != tooie::debug::current_map(rdram)) {
                tooie::debug::request_warp(start_map, 0);
            }
            enter(Phase::Done);
            armed = false;
            return;
        }
        const Target& t = targets[next_target];
        log_line("start " + hex(t.map) + " " + t.name);
        tooie::toast::show("Texture sweep " + std::to_string(next_target + 1) + "/" + std::to_string(targets.size()) + ": " + t.name);
        pngs_at_map_start = new_pngs.load();
        tooie::debug::request_warp(t.map, 0);
        enter(Phase::Warping);
    }

    void finish_map(const char* word) {
        const Target& t = targets[next_target];
        const std::string vram = tooie::vram_log::summary();
        log_line(std::string(word) + " " + hex(t.map) + " " + std::to_string(new_pngs.load() - pngs_at_map_start) + " new textures" + (vram.empty() ? "" : ", " + vram));
        next_target++;
    }

    void sweep_tick(uint8_t* rdram) {
        auto elapsed = steady::now() - phase_start;
        switch (phase) {
            case Phase::WaitForFile:
                if (tooie::debug::can_warp()) {
                    start_map = tooie::debug::current_map(rdram);
                    warp_next(rdram);
                }
                break;
            case Phase::Warping:
                if (tooie::debug::current_map(rdram) == targets[next_target].map) {
                    enter(Phase::Settling);
                } else if (elapsed > load_timeout) {
                    finish_map("missed");
                    warp_next(rdram);
                }
                break;
            case Phase::Settling:
                if (elapsed > settle_time) {
                    turn_start_ns = steady::now().time_since_epoch().count();
                    turning = true;
                    enter(Phase::Turning);
                }
                break;
            case Phase::Turning:
                if (elapsed > turn_time) {
                    turning = false;
                    finish_map("done");
                    warp_next(rdram);
                }
                break;
            default:
                break;
        }
    }

    void stop_sweep() {
        if (phase != Phase::Idle && phase != Phase::Done) {
            log_line("stopped");
        }
        turning = false;
        phase = Phase::Idle;
    }
}

void tooie::texture_sweep::tick(uint8_t* rdram) {
    tooie::TextureDump value = option_value();
    if (value == tooie::TextureDump::SweepAllMaps && !first_tick && last_value != tooie::TextureDump::SweepAllMaps) {
        armed = true;
    }
    if (value == tooie::TextureDump::SweepAllMaps && std::getenv("TOOIE_TEXTURE_DUMP") != nullptr && first_tick) {
        // Headless runs set the sweep from the environment: that counts as picking it.
        armed = true;
    }
    const tooie::TextureDump picked = value;
    if (value == tooie::TextureDump::SweepAllMaps && !armed) {
        // Left on from an earlier run, or finished: nothing runs until it is picked again.
        if (first_tick) {
            tooie::toast::show("Texture sweep is idle after a restart: pick it again in General to carry on");
        }
        value = tooie::TextureDump::Off;
    }
    const bool want_dump = value != tooie::TextureDump::Off;
    if (want_dump && !dumping) {
        root = dump_folder();
        start_dumping(root);
        dumping = true;
    }

    if (value == tooie::TextureDump::SweepAllMaps) {
        if (phase == Phase::Idle || phase == Phase::Done) {
            // Picked: carry on with an unfinished sweep, or start a new one.
            begin_sweep(true);
            if (!tooie::debug::can_warp()) {
                tooie::toast::show("Texture sweep: load a save file to start");
            }
        }
        sweep_tick(rdram);
    } else if (phase != Phase::Idle && phase != Phase::Done) {
        stop_sweep();
    }

    const bool cap = value == tooie::TextureDump::SweepAllMaps;
    if (cap != pool_capped) {
        RT64::SetReplacementPoolLimit(cap ? sweep_pool_limit : 0);
        pool_capped = cap;
    }

    if (!want_dump && dumping) {
        stop_dumping(root);
        dumping = false;
    }
    last_value = picked;
    first_tick = false;
}

void tooie::texture_sweep::apply_input(uint16_t* buttons) {
    if (!turning.load()) {
        return;
    }
    auto since = steady::now().time_since_epoch() - steady::duration(turn_start_ns.load());
    if (since % turn_pulse < turn_press) {
        *buttons |= c_right;
    }
}

bool tooie::texture_sweep::sweeping() {
    return phase != Phase::Idle && phase != Phase::Done && phase != Phase::WaitForFile;
}
