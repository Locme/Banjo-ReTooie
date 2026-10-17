// Asset dump and asset replacement (handoff 4.88 and 4.89): models, animations, sprites, text and
// the rest of the game's assets, by id.
//
// The game's assets sit in one table in the ROM: at 0x5180 a count, then a word per asset
// (after 0xFFFFFFFF), each holding the asset's offset into the data after the table (word >> 6),
// whether it is compressed (bit 4) and its kind (the low 4 bits; 0 is a model, starting 0x0000000B
// like Banjo-Kazooie's). An asset's size is the next offset minus its own. Compressed assets are a
// 16-bit size (in 16-byte units) followed by raw deflate. Kind 10 (234 entries) is loaded another
// way (_gldbDll_entrypoint_0) and is dumped as it is in the ROM.
//
// Dump: DEV tab > Dump assets writes every asset to asset_dump/ in the app-data folder,
// decompressed, as asset_<id>.bin (id in hex, 4 digits), with assets.txt listing id, kind and size.
// Files that are already there are left alone. ROM data: it stays out of the repo.
//
// Replace: a file mods/assets/asset_<id>.bin is loaded in place of that asset, at any size. A mod
// can carry them too: a mod folder (or a .zip that mod_zips.cpp unpacks into one) with an
// assets.json and an assets/ folder of asset_<id>.bin files. While that mod is on in the Mods menu
// its files count, ahead of mods/assets, in the mod list's order. Switching it on or off in a level
// reloads the area (the game's own map change, back in through the exit last used), so a model
// mod shows or goes at once; elsewhere it counts from the next area load. The game
// loads assets by id in func_800D5B34; banjotooie.us.toml hooks it before it fetches the asset
// (0x800D5BF4). When a replacement exists the hook allocates game heap for it with the game's own
// heap_alloc, copies the file in and skips to the end of the function, where the game records the
// pointer as if it had loaded the asset itself. The folder is looked at again every 2 seconds, so a
// file added while playing counts from the next time the game loads that asset (another area).
//
// Headless: TOOIE_ASSET_DUMP=1 dumps whatever the setting says, TOOIE_ASSET_DUMP_DIR=<dir> and
// TOOIE_ASSET_MODS_DIR=<dir> change the folders, TOOIE_ASSET_LOG=1 logs every asset the game loads.

#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <filesystem>
#include <functional>
#include <fstream>
#include <map>
#include <mutex>
#include <set>
#include <span>
#include <string>
#include <thread>
#include <vector>

#include "recomp.h"
#include "librecomp/game.hpp"
#include "librecomp/mods.hpp"
#include "recompui/config.h"
#include "miniz.h"

#include "tooie_asset_mods.h"
#include "tooie_debug.h"
#include "tooie_game.h"
#include "tooie_hooks.h"
#include "tooie_original_honeycomb.h"
#include "tooie_toast.h"

extern "C" void heap_alloc(uint8_t* rdram, recomp_context* ctx);

namespace {
    namespace fs = std::filesystem;
    using steady = std::chrono::steady_clock;

    constexpr uint32_t table_rom = 0x5180;
    constexpr uint32_t kind_gldb = 10;

    struct Entry {
        uint32_t offset;
        uint32_t size;
        uint32_t kind;
        bool compressed;
    };

    uint32_t rom_word(std::span<const uint8_t> rom, uint32_t at) {
        if (at + 4 > rom.size()) {
            return 0;
        }
        return (uint32_t(rom[at]) << 24) | (uint32_t(rom[at + 1]) << 16) | (uint32_t(rom[at + 2]) << 8) | rom[at + 3];
    }

    // The asset table as the ROM has it. Empty when the ROM is not the one expected.
    std::vector<Entry> read_table(std::span<const uint8_t> rom) {
        std::vector<Entry> entries;
        const uint32_t count = rom_word(rom, table_rom);
        if (count == 0 || count > 0x10000 || rom_word(rom, table_rom + 4) != 0xFFFFFFFF) {
            return entries;
        }
        const uint32_t words = table_rom + 8;
        const uint32_t data = words + count * 4;
        for (uint32_t id = 0; id + 1 < count; id++) {
            uint32_t word = rom_word(rom, words + id * 4);
            uint32_t next = rom_word(rom, words + (id + 1) * 4);
            Entry e{data + (word >> 6), (next >> 6) - (word >> 6), word & 0xF, ((word >> 4) & 1) != 0};
            if ((next >> 6) < (word >> 6)) {
                e.size = 0;
            }
            entries.push_back(e);
        }
        return entries;
    }

    fs::path dump_folder() {
        if (const char* env = std::getenv("TOOIE_ASSET_DUMP_DIR")) {
            return fs::path(env);
        }
        return recomp::get_config_path() / "asset_dump";
    }

    fs::path mods_folder() {
        if (const char* env = std::getenv("TOOIE_ASSET_MODS_DIR")) {
            return fs::path(env);
        }
        return recomp::mods::get_mods_directory() / "assets";
    }

    std::string file_name(uint32_t id, const char* ext) {
        char buf[32];
        snprintf(buf, sizeof(buf), "asset_%04X%s", id, ext);
        return buf;
    }

    // One asset as the game would load it (decompressed). Empty when it can't be read.
    std::vector<uint8_t> rom_asset(std::span<const uint8_t> rom, const std::vector<Entry>& table, uint32_t id) {
        std::vector<uint8_t> bytes;
        if (id >= table.size()) {
            return bytes;
        }
        const Entry& e = table[id];
        if (e.size == 0 || e.offset + e.size > rom.size()) {
            return bytes;
        }
        const uint8_t* src = rom.data() + e.offset;
        if (e.kind == kind_gldb || !e.compressed) {
            bytes.assign(src, src + e.size);
        } else if (e.size > 2) {
            size_t out_len = 0;
            void* out = tinfl_decompress_mem_to_heap(src + 2, e.size - 2, &out_len, 0);
            if (out != nullptr) {
                bytes.assign((uint8_t*)out, (uint8_t*)out + out_len);
                mz_free(out);
            }
        }
        return bytes;
    }

    // ---- Dump ----

    std::atomic<bool> dump_running{false};
    bool dump_requested_before = false;

    void dump_all() {
        std::span<const uint8_t> rom = recomp::get_rom();
        std::vector<Entry> table = read_table(rom);
        if (table.empty()) {
            fprintf(stderr, "[assets] asset table not found in the ROM, nothing dumped\n");
            dump_running = false;
            return;
        }
        fs::path folder = dump_folder();
        std::error_code ec;
        fs::create_directories(folder, ec);
        std::ofstream list(folder / "assets.txt");
        list << "# id  kind  size  (kind 0 = model; kind 10 is kept as in the ROM, .raw)\n";
        uint32_t written = 0, failed = 0;
        for (uint32_t id = 0; id < table.size(); id++) {
            const Entry& e = table[id];
            if (e.size == 0 || e.offset + e.size > rom.size()) {
                continue;
            }
            std::vector<uint8_t> bytes = rom_asset(rom, table, id);
            const char* ext = e.kind == kind_gldb ? ".raw" : ".bin";
            if (bytes.empty()) {
                failed++;
                continue;
            }
            char line[64];
            snprintf(line, sizeof(line), "%04X  %2u  %u\n", id, e.kind, (unsigned)bytes.size());
            list << line;
            fs::path path = folder / file_name(id, ext);
            if (fs::exists(path, ec)) {
                continue;
            }
            std::ofstream out(path, std::ios::binary);
            out.write((const char*)bytes.data(), bytes.size());
            written++;
        }
        printf("[assets] dumped %u assets to %s (%u could not be unpacked)\n", written, folder.string().c_str(), failed);
        fflush(stdout);
        tooie::toast::show("Assets dumped: " + std::to_string(written) + " new files");
        dump_running = false;
    }

    bool dump_wanted() {
        if (std::getenv("TOOIE_ASSET_DUMP") != nullptr) {
            return true;
        }
        try {
            return std::get<bool>(recompui::config::get_config(tooie::wip_tab_id).get_option_value(tooie::asset_dump_option));
        } catch (...) {
            return false;
        }
    }

    // ---- Replacement ----

    std::mutex mods_mutex;
    std::map<uint32_t, fs::path> replaced_ids;
    struct ModAssets {
        std::string mod_id;
        fs::path folder;
        size_t order;
    };
    std::vector<ModAssets> mod_folders;
    // A mod was switched on or off: reload the area so its models load again.
    std::atomic<bool> refresh_wanted{false};
    // The game-state block: +0x13 is the exit the area was entered by.
    constexpr gpr game_state_addr = (int32_t)0x80127630;
    steady::time_point last_scan;
    bool scanned = false;

    void rescan_if_due() {
        auto now = steady::now();
        if (scanned && now - last_scan < std::chrono::seconds(2)) {
            return;
        }
        scanned = true;
        last_scan = now;
        std::map<uint32_t, fs::path> ids;
        std::vector<fs::path> folders;
        for (const ModAssets& m : mod_folders) {
            folders.push_back(m.folder);
        }
        folders.push_back(mods_folder());
        for (const fs::path& folder : folders) {
            std::error_code ec;
            for (const auto& entry : fs::directory_iterator(folder, ec)) {
                std::string name = entry.path().filename().string();
                unsigned id = 0;
                char tail[8] = {};
                if (std::sscanf(name.c_str(), "asset_%x%7s", &id, tail) == 2 && std::strcmp(tail, ".bin") == 0) {
                    ids.try_emplace(id, entry.path());  // the first folder that has it wins
                }
            }
        }
        if (ids != replaced_ids) {
            printf("[assets] %zu replacement assets (%zu from mods)\n", ids.size(), mod_folders.size());
            fflush(stdout);
        }
        replaced_ids = std::move(ids);
    }
}

void tooie::asset_mods::enable_mod(const std::string& mod_id, const std::filesystem::path& root, size_t order) {
    std::error_code ec;
    if (!fs::is_directory(root / "assets", ec)) {
        fprintf(stderr, "[assets] mod %s has assets.json but no assets folder next to it\n", mod_id.c_str());
        return;
    }
    std::lock_guard lock{mods_mutex};
    std::erase_if(mod_folders, [&](const ModAssets& m) { return m.mod_id == mod_id; });
    mod_folders.push_back({mod_id, root / "assets", order});
    std::stable_sort(mod_folders.begin(), mod_folders.end(), [](const ModAssets& a, const ModAssets& b) { return a.order < b.order; });
    scanned = false;
    refresh_wanted = true;
    printf("[assets] mod %s on: its assets load in place of the game's\n", mod_id.c_str());
    fflush(stdout);
}

void tooie::asset_mods::disable_mod(const std::string& mod_id) {
    std::lock_guard lock{mods_mutex};
    std::erase_if(mod_folders, [&](const ModAssets& m) { return m.mod_id == mod_id; });
    scanned = false;
    refresh_wanted = true;
    printf("[assets] mod %s off\n", mod_id.c_str());
    fflush(stdout);
}

void tooie::asset_mods::reorder(const std::function<size_t(const std::string&)>& order_of) {
    std::lock_guard lock{mods_mutex};
    for (ModAssets& m : mod_folders) {
        m.order = order_of(m.mod_id);
    }
    std::stable_sort(mod_folders.begin(), mod_folders.end(), [](const ModAssets& a, const ModAssets& b) { return a.order < b.order; });
    scanned = false;
}

void tooie::asset_mods::tick(uint8_t* rdram) {
    // Back-Port: Original honeycomb switched: reload the area so the combs load again.
    static int honeycomb_before = -1;
    const int honeycomb_now = tooie::original_honeycomb::enabled() ? 1 : 0;
    if (honeycomb_before != -1 && honeycomb_now != honeycomb_before) {
        refresh_wanted = true;
    }
    honeycomb_before = honeycomb_now;
    // Mods switched on at startup land here on the title screen, where nothing needs reloading.
    if (refresh_wanted.exchange(false) && tooie::debug::can_warp()) {
        uint16_t map = tooie::debug::current_map(rdram);
        uint8_t exit = MEM_B(0x13, game_state_addr);
        printf("[assets] reloading the area (map 0x%X, exit %u) for the switched mod\n", map, exit);
        fflush(stdout);
        tooie::debug::request_warp(map, exit);
    }
    bool want = dump_wanted();
    if (want && !dump_requested_before && !dump_running.exchange(true)) {
        std::thread(dump_all).detach();
    }
    dump_requested_before = want;
}

std::vector<uint8_t> tooie::asset_mods::asset_bytes(uint32_t id) {
    fs::path path;
    {
        std::lock_guard lock{mods_mutex};
        rescan_if_due();
        auto found = replaced_ids.find(id);
        if (found != replaced_ids.end()) {
            path = found->second;
        }
    }
    if (!path.empty()) {
        std::ifstream in(path, std::ios::binary);
        return std::vector<uint8_t>(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>());
    }
    std::span<const uint8_t> rom = recomp::get_rom();
    return rom_asset(rom, read_table(rom), id);
}

// Hooked in func_800D5B34 (load asset by id) before it fetches the asset. Returns 1 when a
// replacement was loaded: $a3 then holds its address and the game carries on as if it loaded it.
extern "C" int tooie_asset_replace(uint8_t* rdram, recomp_context* ctx) {
    const uint32_t id = (uint32_t)MEM_W(0x30, ctx->r29);
    static const bool log = std::getenv("TOOIE_ASSET_LOG") != nullptr;
    if (log) {
        const uint32_t table = (uint32_t)MEM_W(-0x4700, (gpr)(int32_t)0x80120000) & 0x0FFFFFFF;
        const uint32_t word = rom_word(recomp::get_rom(), table + id * 4);
        printf("[assets] load 0x%04X (table at ROM 0x%X, kind %u)\n", id, table, word & 0xF);
        fflush(stdout);
    }

    std::vector<char> bytes;
    fs::path path;
    {
        std::lock_guard lock{mods_mutex};
        rescan_if_due();
        auto found = replaced_ids.find(id);
        if (found != replaced_ids.end()) {
            path = found->second;
        }
    }
    if (!path.empty()) {
        std::ifstream in(path, std::ios::binary);
        if (in) {
            bytes.assign(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>());
        }
    } else if (id == tooie::original_honeycomb::health_model && tooie::original_honeycomb::enabled()) {
        // A model mod of the same comb wins over the back-port; the back-port is built from the ROM.
        static std::vector<uint8_t> built;
        if (built.empty()) {
            std::span<const uint8_t> rom = recomp::get_rom();
            std::vector<Entry> table = read_table(rom);
            built = tooie::original_honeycomb::build(rom_asset(rom, table, tooie::original_honeycomb::bk_model),
                                                     rom_asset(rom, table, tooie::original_honeycomb::health_model));
            if (built.empty()) {
                fprintf(stderr, "[assets] Original honeycomb: could not build the comb, Tooie's is used\n");
            }
        }
        bytes.assign(built.begin(), built.end());
    }
    if (bytes.empty()) {
        return 0;
    }

    // Game heap for it, the way the game allocates an asset it reads from the ROM.
    recomp_context saved = *ctx;
    ctx->r4 = (gpr)(int32_t)((bytes.size() + 15) & ~size_t(15));
    heap_alloc(rdram, ctx);
    const gpr ptr = ctx->r2;
    *ctx = saved;
    if ((uint32_t)ptr == 0) {
        fprintf(stderr, "[assets] no room in the game's heap for asset 0x%04X (%zu bytes); the original is used\n", id, bytes.size());
        return 0;
    }
    for (size_t i = 0; i < bytes.size(); i++) {
        MEM_B((int32_t)i, ptr) = (int8_t)bytes[i];
    }
    ctx->r7 = ptr;
    printf("[assets] asset 0x%04X replaced (%zu bytes) at 0x%08X\n", id, bytes.size(), (uint32_t)ptr);
    fflush(stdout);
    return 1;
}
