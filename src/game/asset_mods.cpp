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
// Replace: a file mods/assets/asset_<id>.bin is loaded in place of that asset, at any size. The game
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
#include <filesystem>
#include <fstream>
#include <mutex>
#include <set>
#include <string>
#include <thread>
#include <vector>

#include "recomp.h"
#include "librecomp/game.hpp"
#include "librecomp/mods.hpp"
#include "recompui/config.h"
#include "miniz.h"

#include "tooie_asset_mods.h"
#include "tooie_game.h"
#include "tooie_hooks.h"
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
            const uint8_t* src = rom.data() + e.offset;
            std::vector<uint8_t> bytes;
            const char* ext = ".bin";
            if (e.kind == kind_gldb || !e.compressed) {
                bytes.assign(src, src + e.size);
                if (e.kind == kind_gldb) {
                    ext = ".raw";
                }
            } else if (e.size > 2) {
                size_t out_len = 0;
                void* out = tinfl_decompress_mem_to_heap(src + 2, e.size - 2, &out_len, 0);
                if (out == nullptr) {
                    failed++;
                    continue;
                }
                bytes.assign((uint8_t*)out, (uint8_t*)out + out_len);
                mz_free(out);
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
    std::set<uint32_t> replaced_ids;
    steady::time_point last_scan;
    bool scanned = false;

    void rescan_if_due() {
        auto now = steady::now();
        if (scanned && now - last_scan < std::chrono::seconds(2)) {
            return;
        }
        scanned = true;
        last_scan = now;
        std::set<uint32_t> ids;
        std::error_code ec;
        for (const auto& entry : fs::directory_iterator(mods_folder(), ec)) {
            std::string name = entry.path().filename().string();
            unsigned id = 0;
            char tail[8] = {};
            if (std::sscanf(name.c_str(), "asset_%x%7s", &id, tail) == 2 && std::strcmp(tail, ".bin") == 0) {
                ids.insert(id);
            }
        }
        if (ids != replaced_ids) {
            printf("[assets] %zu replacement assets in %s\n", ids.size(), mods_folder().string().c_str());
            fflush(stdout);
        }
        replaced_ids = std::move(ids);
    }
}

void tooie::asset_mods::tick() {
    bool want = dump_wanted();
    if (want && !dump_requested_before && !dump_running.exchange(true)) {
        std::thread(dump_all).detach();
    }
    dump_requested_before = want;
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
    {
        std::lock_guard lock{mods_mutex};
        rescan_if_due();
        if (!replaced_ids.contains(id)) {
            return 0;
        }
    }
    {
        std::ifstream in(mods_folder() / file_name(id, ".bin"), std::ios::binary);
        if (!in) {
            return 0;
        }
        bytes.assign(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>());
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
    printf("[assets] asset 0x%04X replaced (%zu bytes)\n", id, bytes.size());
    fflush(stdout);
    return 1;
}
