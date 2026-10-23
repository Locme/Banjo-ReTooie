// Enemy spawner (Cheats tab, Enemies).
//
// A drop-down of the game's enemies with a Spawn button beside it (the button is RecompFrontend's
// recompui::config::set_option_button). Each press spawns the picked enemy a few steps in front of
// Banjo, facing him, on the ground there, with func_80108474(actor id, f32 pos[3], yaw), the game's
// spawn-by-id the test room uses (src/gameplay/test_room.cpp). Presses are queued and spawned on the game
// thread, one a frame. Enemies that live in water go in the nearest water instead (the game's line test
// against water surfaces, searched outward in rings), with a notice; with no water nearby, a notice says
// so and nothing spawns.
//
// The list is every enemy in that spawn table (gemarkersDll, ids 0xB6 to 0x545). Every enemy a map
// places comes from the same table too: Quagmire's ground enemies, called Gruntlings in older notes, are
// actor 0x131 (chdiggerground, listed as Ugger). Some enemies follow a route or use props that only exist
// where they live and crash elsewhere: the 16 that still hit null reads or broke the heap in a headless
// sweep away from home (Spiral Mountain, 2026-10-20). Those say "(only where it lives)" and only spawn
// while the area already has one of them (a live object whose +0x10 is the actor's entry); otherwise a
// press shows a notice and does nothing. Passing them a prop of their own, or the nearest route
// (func_8010856C), did not help; Spiral Mountain has no routes at all.
//
// Headless test aids: TOOIE_ENEMY_SPAWN=<hex id>[@ms][,<hex id>@ms...] spawns each enemy once, ms after
// the game loop first runs, whenever a save is being played. TOOIE_ENEMY_SWEEP=<hex id>,... reloads the
// area before each enemy and watches it 20 s, so pass-overs between its "begin" and "end" lines are its
// own (TOOIE_ENEMY_SWEEP_START=<ms> when to start). TOOIE_ENEMY_ANYWHERE=1 lets the guarded ones spawn.

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include "librecomp/game.hpp"
#include <map>
#include <mutex>
#include <string>
#include <variant>
#include <vector>

#include "recomp.h"
#include "funcs.h"
#include "recompui/config.h"
#include "tooie_aim_trace.h"
#include "tooie_cheats.h"
#include "tooie_debug.h"
#include "tooie_dev_files.h"
#include "tooie_enemy_spawner.h"
#include "tooie_memory_guard.h"
#include "tooie_rdram.h"
#include "tooie_torch_enemy.h"
#include "tooie_toast.h"

namespace {
    struct Enemy {
        uint16_t id;
        const char* name;
        // For enemies that crash away from where they live: the actor's entry in the game's syscall table
        // (gemarkersDll's pointer for the id), which a live object of that actor holds at +0x10. They only
        // spawn while one is already in the area. 0 for enemies that spawn anywhere.
        uint32_t home_entry;
    };

    // Alphabetical, as the drop-down shows them. The option saves the actor id.
    constexpr Enemy enemies[] = {
        { 0x19A, "Beehive", 0 },
        { 0x30F, "Big Fish (only where it lives)", 0x80086D90 },
        { 0x310, "Big Fish 2 (only where it lives)", 0x80086D98 },
        { 0x3E5, "Bigfoot", 0 },
        { 0x3E6, "Biggafoot", 0 },
        { 0x44E, "Biggafoot 2", 0 },
        { 0x35F, "Blubbul", 0 },
        { 0x440, "Boltoid", 0 },
        { 0x2C1, "Clinker (only where it lives)", 0x800873A8 },
        { 0x2BF, "Clinker 2", 0 },
        { 0x2C0, "Clinker 3", 0 },
        { 0x1EF, "Dragunda", 0 },
        { 0x153, "Evil spirit", 0 },
        { 0x482, "Eyeball", 0 },
        { 0x483, "Eyeball 2", 0 },
        { 0x3BF, "Factory robot", 0 },
        { 0x3A2, "Flamer", 0 },
        { 0x349, "Floater", 0 },
        { 0x486, "Floatus Floatsum", 0 },
        { 0x31E, "Frazzle (only where it lives)", 0x80086DB8 },
        { 0x363, "Freezy", 0 },
        { 0x2FF, "Freezy 2", 0 },
        { 0x476, "Germ (only where it lives)", 0x80087698 },
        { 0x12D, "Ghost (only where it lives)", 0x80085D50 },
        { 0x1E0, "Ghost 2", 0 },
        { 0x401, "Gobgoyle", 0 },
        { 0x402, "Gobgoyle 2", 0 },
        { 0x133, "Gruntydactyl", 0 },
        { 0x134, "Gruntydactyl 2", 0 },
        { 0x3E9, "Hothand", 0 },
        { 0x400, "Hothand 2 (only where it lives)", 0x800875A0 },
        { 0x462, "Hothead", 0 },
        { 0x35E, "Inky", 0 },
        { 0x31F, "Lagoon fish", 0 },
        { 0x300, "Lake monster", 0 },
        { 0x37C, "Mingy Jongo", 0 },
        { 0x19C, "Minjo", 0 },
        { 0x112, "Moggy warrior", 0 },
        { 0x399, "Mucoid", 0 },
        { 0x398, "Mucoid 2", 0 },
        { 0x3A0, "Mucoid 3", 0 },
        { 0x43E, "Nutta", 0 },
        { 0x47F, "Onion", 0 },
        { 0x46B, "Pansie", 0 },
        { 0x2FC, "Piranha", 0 },
        { 0x2FD, "Piranha 2", 0 },
        { 0x2FE, "Piranha 3", 0 },
        { 0x3AB, "Rocknut", 0 },
        { 0x426, "S'Hard", 0 },
        { 0x243, "Shadow baddie", 0 },
        { 0x111, "Snapdragon", 0 },
        { 0x39A, "Soarasaur", 0 },
        { 0x113, "Sput Sput (only where it lives)", 0x80086F20 },
        { 0x123, "Sput Sput 2", 0 },
        { 0x3BD, "Spy-I-Cam (only where it lives)", 0x80086218 },
        { 0x4E9, "Squits", 0 },
        { 0x16F, "Stinger", 0 },
        { 0x29A, "Swellbelly", 0 },
        { 0x3BE, "Tintup", 0 },
        { 0x2AE, "Torch enemy", 0 },
        { 0x3FF, "Toxi-Gag", 0 },
        { 0x3F0, "Toxi-Klang", 0 },
        { 0x442, "Twinkly 4", 0 },
        { 0x446, "Twinkly 5 (only where it lives)", 0x80086508 },
        { 0x44D, "Twinkly 6 (only where it lives)", 0x80086500 },
        { 0x443, "Twinkly, blue (only where it lives)", 0x80086510 },
        { 0x444, "Twinkly, green (only where it lives)", 0x80086518 },
        { 0x445, "Twinkly, red (only where it lives)", 0x80086520 },
        { 0x131, "Ugger", 0 },
        { 0x1DA, "Unga Bunga (only where it lives)", 0x80085AF0 },
        { 0x1DB, "Unga Bunga 2", 0 },
        { 0x43F, "Washup", 0 },
        { 0x35C, "Whirlweed (only where it lives)", 0x80085F28 },
        { 0x35D, "Whirlweed 2", 0 },
        { 0x213, "Zubba", 0 },
    };
    constexpr uint16_t default_enemy = 0x111;

    // The object array (as the test room walks it).
    constexpr uint32_t object_array_pointer = 0x80136EE0;
    constexpr uint32_t object_first = 0x04;
    constexpr uint32_t object_last = 0x08;
    constexpr uint32_t object_base = 0x10;
    constexpr uint32_t object_size = 0x9C;
    constexpr uint32_t object_actor_entry = 0x10;
    constexpr int max_objects = 2048;

    constexpr uint32_t player_table = 0x80135490;
    constexpr uint32_t player_pos_ptr = 0xE4;
    constexpr uint32_t player_yaw_ptr = 0xF8;
    constexpr gpr game_state_addr = (int32_t)0x80127630;
    // How far in front of Banjo a new enemy appears.
    constexpr float spawn_distance = 250.0f;

    // Presses waiting for the game thread, oldest first.
    std::mutex queue_mutex;
    std::vector<uint16_t> queue;

    struct EnvRequest {
        uint16_t id = 0;
        uint32_t delay_ms = 0;
    };
    bool env_read = false;
    std::vector<EnvRequest> env_requests;
    size_t env_next = 0;
    std::chrono::steady_clock::time_point env_started;

    void read_env() {
        env_read = true;
        env_started = std::chrono::steady_clock::now();
        const char* v = std::getenv("TOOIE_ENEMY_SPAWN");
        if (v == nullptr) {
            return;
        }
        std::string list{v};
        size_t pos = 0;
        while (pos < list.size()) {
            size_t comma = list.find(',', pos);
            unsigned id = 0, delay = 0;
            if (std::sscanf(list.substr(pos, comma - pos).c_str(), "%x@%u", &id, &delay) >= 1 && id != 0) {
                env_requests.push_back({ (uint16_t)id, delay });
            }
            pos = comma == std::string::npos ? list.size() : comma + 1;
        }
    }

    // Spawns with a copy of the hook's context, the position in a scratch area below the stack
    // (as the test room's spawn does).
    uint32_t spawn(uint8_t* rdram, recomp_context* ctx, uint16_t id, const float pos[3], float yaw) {
        recomp_context saved = *ctx;
        const uint32_t sp = (uint32_t)ctx->r29;
        const uint32_t vec = (sp - 0x100) & ~0xFu;
        tooie::rdram::write_float(rdram, vec + 0, pos[0]);
        tooie::rdram::write_float(rdram, vec + 4, pos[1]);
        tooie::rdram::write_float(rdram, vec + 8, pos[2]);
        ctx->r29 = (int32_t)(vec - 0x40);
        ctx->r4 = id;
        ctx->r5 = (int32_t)vec;
        ctx->r6 = (int32_t)yaw;
        func_80108474(rdram, ctx);
        const uint32_t object = (uint32_t)ctx->r2;
        *ctx = saved;
        return object;
    }

    // The game's line test against the map's collision (func_800BEF00(from, to, normal, kind)): true on a hit,
    // with *hit_y the height where the line meets it. Kind water_surface finds only water surfaces (the
    // probe the player's swim check makes, object +0x88's default); kind floor finds solid ground, not water.
    constexpr uint32_t water_surface = 0x1F00;
    constexpr uint32_t floor = 0x20020;

    bool line_hit(uint8_t* rdram, recomp_context* ctx, float x, float z, float from_y, float to_y, uint32_t kind, float* hit_y) {
        using namespace tooie::rdram;
        recomp_context saved = *ctx;
        const uint32_t vec = ((uint32_t)ctx->r29 - 0x100) & ~0xFu;
        write_float(rdram, vec + 0x00, x);
        write_float(rdram, vec + 0x04, from_y);
        write_float(rdram, vec + 0x08, z);
        write_float(rdram, vec + 0x10, x);
        write_float(rdram, vec + 0x14, to_y);
        write_float(rdram, vec + 0x18, z);
        ctx->r29 = (int32_t)(vec - 0x40);
        ctx->r4 = (int32_t)vec;
        ctx->r5 = (int32_t)(vec + 0x10);
        ctx->r6 = (int32_t)(vec + 0x20);
        ctx->r7 = (int32_t)kind;
        func_800BEF00(rdram, ctx);
        const bool hit = (uint32_t)ctx->r2 != 0;
        *hit_y = read_float(rdram, vec + 0x14);
        *ctx = saved;
        return hit;
    }

    // Enemies that live in water, and of those the ones that sit on the bottom.
    bool lives_in_water(uint16_t id) {
        switch (id) {
            case 0x29A: case 0x2FC: case 0x2FD: case 0x2FE: case 0x300: case 0x30F: case 0x310:
            case 0x31E: case 0x31F: case 0x35C: case 0x35D: case 0x35E: case 0x35F:
                return true;
        }
        return false;
    }
    bool sits_on_bottom(uint16_t id) {
        return id == 0x35C || id == 0x35D || id == 0x35F;
    }

    // Where in the water nearest (x, y, z) a water enemy goes: false when there is none within reach.
    // Searches outward in rings, looking for a water surface from a little above to well below y.
    bool nearest_water(uint8_t* rdram, recomp_context* ctx, uint16_t id, const float at[3], float out[3]) {
        constexpr float step = 250.0f;
        constexpr float reach = 8000.0f;
        for (float r = 0.0f; r <= reach; r += step) {
            const int count = r == 0.0f ? 1 : (int)std::ceil(2.0f * 3.14159265f * r / step);
            for (int i = 0; i < count; i++) {
                const float angle = 2.0f * 3.14159265f * i / count;
                const float x = at[0] + std::sin(angle) * r;
                const float z = at[2] + std::cos(angle) * r;
                float surface = 0.0f;
                if (!line_hit(rdram, ctx, x, z, at[1] + 1500.0f, at[1] - 3000.0f, water_surface, &surface)) {
                    continue;
                }
                // The bottom: some water (Spiral Mountain's moat) has none to find within reach.
                float bottom = 0.0f;
                const bool has_bottom = line_hit(rdram, ctx, x, z, surface - 5.0f, surface - 3000.0f, 0, &bottom);
                if (has_bottom && surface - bottom < 120.0f) {
                    continue; // too shallow to swim in
                }
                if (sits_on_bottom(id) && !has_bottom) {
                    continue;
                }
                out[0] = x;
                out[2] = z;
                out[1] = sits_on_bottom(id) ? bottom : has_bottom ? std::max(bottom + 60.0f, surface - 250.0f) : surface - 250.0f;
                return true;
            }
        }
        return false;
    }

    const Enemy* find_enemy(uint16_t id) {
        for (const Enemy& enemy : enemies) {
            if (enemy.id == id) {
                return &enemy;
            }
        }
        return nullptr;
    }

    // Whether a live object of the actor with this entry is in the area.
    bool actor_present(uint8_t* rdram, uint32_t entry) {
        using namespace tooie::rdram;
        const uint32_t array = read_word(rdram, object_array_pointer);
        if (!valid_ptr(array)) {
            return false;
        }
        const uint32_t first = read_word(rdram, array + object_first);
        const uint32_t last = read_word(rdram, array + object_last);
        if (!valid_ptr(first) || !valid_ptr(last) || last < first || (last - first) / object_size >= max_objects) {
            return false;
        }
        const int count = (int)((last - first) / object_size) + 1;
        for (int i = 0; i < count; i++) {
            const uint32_t object = array + object_base + (uint32_t)i * object_size;
            if (valid_ptr(read_word(rdram, object)) && read_word(rdram, object + object_actor_entry) == entry) {
                return true;
            }
        }
        return false;
    }

    // The enemy's name for notices, without the "(only where it lives)" note.
    std::string short_name(uint16_t id) {
        const Enemy* enemy = find_enemy(id);
        if (enemy == nullptr) {
            char buf[16];
            std::snprintf(buf, sizeof(buf), "Actor 0x%X", id);
            return buf;
        }
        std::string name{enemy->name};
        const size_t note = name.find(" (");
        return note == std::string::npos ? name : name.substr(0, note);
    }

    // Spawns the enemy in front of Banjo, on the ground there; a water enemy goes in the nearest water
    // instead, or not at all when there is none. False when there is no player to spawn it by.
    bool spawn_in_front(uint8_t* rdram, recomp_context* ctx, uint16_t id) {
        using namespace tooie::rdram;
        const uint32_t player = read_word(rdram, player_table);
        if (!valid_ptr(player)) {
            return false;
        }
        const uint32_t pos_ptr = read_word(rdram, player + player_pos_ptr);
        const uint32_t yaw_ptr = read_word(rdram, player + player_yaw_ptr);
        if (!valid_ptr(pos_ptr) || !valid_ptr(yaw_ptr)) {
            return false;
        }
        const float yaw = read_float(rdram, yaw_ptr);
        const float rad = yaw * 3.14159265f / 180.0f;
        float pos[3] = {
            read_float(rdram, pos_ptr) + std::sin(rad) * spawn_distance,
            read_float(rdram, pos_ptr + 4),
            read_float(rdram, pos_ptr + 8) + std::cos(rad) * spawn_distance,
        };
        if (lives_in_water(id)) {
            float water[3];
            if (!nearest_water(rdram, ctx, id, pos, water)) {
                printf("[enemy-spawner] actor 0x%X not spawned: no water near Banjo\n", id);
                fflush(stdout);
                tooie::toast::show(short_name(id) + " lives in water and there is none nearby, so it was not spawned");
                return true;
            }
            pos[0] = water[0];
            pos[1] = water[1];
            pos[2] = water[2];
            tooie::toast::show(short_name(id) + " lives in water: spawned in the nearest water");
        } else {
            // On the ground in front of Banjo (he may be on a ledge or in the air).
            float ground = 0.0f;
            if (line_hit(rdram, ctx, pos[0], pos[2], pos[1] + 300.0f, pos[1] - 2000.0f, floor, &ground)) {
                pos[1] = ground;
            }
        }
        // Facing back at Banjo.
        const float facing = std::fmod(yaw + 180.0f, 360.0f);
        const uint32_t object = spawn(rdram, ctx, id, pos, facing);
        printf("[enemy-spawner] actor 0x%X at %.0f %.0f %.0f: object 0x%08X\n", id, pos[0], pos[1], pos[2], object);
        fflush(stdout);
        return true;
    }
}

namespace {
    // Spawns the enemy, or drops it when it can't go here. False to try again next frame (no player yet).
    bool spawn_now(uint8_t* rdram, recomp_context* ctx, uint16_t id) {
        const Enemy* enemy = find_enemy(id);
        // TOOIE_ENEMY_ANYWHERE=1 (headless) spawns them anyway, to test fixes for the crashes.
        static const bool anywhere = std::getenv("TOOIE_ENEMY_ANYWHERE") != nullptr;
        if (enemy != nullptr && enemy->home_entry != 0 && !anywhere && !actor_present(rdram, enemy->home_entry)) {
            // It would crash here: drop the press.
            printf("[enemy-spawner] actor 0x%X not spawned: none in this area (it only works where it lives)\n", id);
            fflush(stdout);
            tooie::toast::show(short_name(id) + " only works where it lives, so it was not spawned here");
            return true;
        }
        return spawn_in_front(rdram, ctx, id);
    }

    // The baseline pass (id 0, no enemy) is kept; each enemy's line lists what ran with it alive and not in the baseline.
    std::map<std::string, uint64_t> aim_baseline;
    // A sweep that found its pending marker (the game crashed or hung with that enemy alive) carries on
    // from the file it wrote: the enemy is logged as a crash and the ones already recorded are skipped.
    bool aim_resumed = false;
    std::vector<uint16_t> aim_done;

    std::filesystem::path aim_pending_path() {
        return tooie::dev_files::path("aim_sweep_pending.txt");
    }
    void aim_pending_set(uint16_t id) {
        std::ofstream(aim_pending_path(), std::ios::trunc) << std::hex << id << '\n';
    }
    void aim_pending_clear() {
        std::error_code ec;
        std::filesystem::remove(aim_pending_path(), ec);
    }

    void aim_sweep_record(uint16_t id) {
        const auto counts = tooie::aim_trace::capture_end();
        aim_pending_clear();
        if (id == 0) {
            aim_baseline = counts;
            if (aim_resumed) {
                return; // already in the file
            }
        }
        const Enemy* enemy = find_enemy(id);
        std::ofstream out(tooie::dev_files::path("aim_sweep.txt"), (id == 0 && !aim_resumed) ? std::ios::trunc : std::ios::app);
        if (!out.good()) {
            return;
        }
        char head[96];
        std::snprintf(head, sizeof(head), "0x%X %s:", id, id == 0 ? "(no enemy: baseline)" : (enemy ? enemy->name : "?"));
        out << head;
        for (const auto& [name, n] : counts) {
            if (id == 0 || aim_baseline.find(name) == aim_baseline.end()) {
                out << ' ' << name << '=' << n;
            }
        }
        out << '\n';
    }

    void aim_sweep_note(uint16_t id, const char* text) {
        const Enemy* enemy = find_enemy(id);
        std::ofstream out(tooie::dev_files::path("aim_sweep.txt"), std::ios::app);
        out << "0x" << std::hex << id << std::dec << ' ' << (enemy ? enemy->name : "?") << ": " << text << '\n';
    }

    // Headless sweep: TOOIE_ENEMY_SWEEP=<hex id>,<hex id>,... reloads the area before each enemy, so only
    // that one is alive, spawns it in front of Banjo and watches it for a while. Pass-overs logged
    // between its "begin" and "end" lines are its own (the guard forgets the places it has seen first).
    struct Sweep {
        std::vector<uint16_t> ids;
        size_t next = 0;
        int phase = 0; // 0 waiting to start, 1 area reloading, 2 settling, 3 watching
        std::chrono::steady_clock::time_point since;
        uint32_t start_ms = 160000;
        // Aim sweep, enemies that only work where they live: the maps that place one, and the one being tried.
        std::vector<uint16_t> maps;
        size_t attempt = 0;
        bool maps_known = false;
    } sweep;
    bool sweep_read = false;

    void sweep_tick(uint8_t* rdram, recomp_context* ctx) {
        using clock = std::chrono::steady_clock;
        if (!sweep_read) {
            sweep_read = true;
            if (const char* v = std::getenv("TOOIE_ENEMY_SWEEP")) {
                std::string list{v};
                size_t pos = 0;
                while (pos < list.size()) {
                    size_t comma = list.find(',', pos);
                    unsigned id = 0;
                    if (std::sscanf(list.substr(pos, comma - pos).c_str(), "%x", &id) == 1 && id != 0) {
                        sweep.ids.push_back((uint16_t)id);
                    }
                    pos = comma == std::string::npos ? list.size() : comma + 1;
                }
            }
            if (const char* v = std::getenv("TOOIE_ENEMY_SWEEP_START")) {
                sweep.start_ms = (uint32_t)std::strtoul(v, nullptr, 10);
            }
            sweep.since = clock::now();
        }
        // DEV > Aim sweep: with the option on and no env list, sweep every enemy that spawns anywhere.
        static bool aim_sweep_running = false;
        if (!aim_sweep_running && sweep.next >= sweep.ids.size() && tooie::aim_trace::sweep_requested() && tooie::debug::can_warp()) {
            aim_sweep_running = true;
            sweep.ids.clear();
            sweep.ids.push_back(0); // the first pass has no enemy: what runs anyway
            for (const Enemy& enemy : enemies) {
                if (enemy.home_entry == 0) {
                    sweep.ids.push_back(enemy.id);
                }
            }
            // Last, the ones that crash away from home: Banjo is warped to a map that places one first.
            for (const Enemy& enemy : enemies) {
                if (enemy.home_entry != 0) {
                    sweep.ids.push_back(enemy.id);
                }
            }
            sweep.maps_known = false;
            sweep.attempt = 0;
            aim_resumed = false;
            aim_done.clear();
            {
                std::ifstream pending(aim_pending_path());
                unsigned crashed = 0;
                if (pending && (pending >> std::hex >> crashed)) {
                    aim_resumed = true;
                    aim_sweep_note((uint16_t)crashed, "CRASHED or HUNG the game while alive (skipped on resume)");
                    aim_done.push_back((uint16_t)crashed);
                    std::ifstream prev(tooie::dev_files::path("aim_sweep.txt"));
                    std::string line;
                    while (std::getline(prev, line)) {
                        unsigned id = 0;
                        if (std::sscanf(line.c_str(), "0x%x", &id) == 1) {
                            aim_done.push_back((uint16_t)id);
                        }
                    }
                    sweep.ids.erase(std::remove_if(sweep.ids.begin(), sweep.ids.end(), [&](uint16_t id) {
                        return id != 0 && std::find(aim_done.begin(), aim_done.end(), id) != aim_done.end();
                    }), sweep.ids.end());
                }
            }
            sweep.next = 0;
            sweep.phase = 0;
            sweep.start_ms = 0;
            sweep.since = clock::now();
        }
        if (sweep.next >= sweep.ids.size()) {
            return;
        }
        const auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(clock::now() - sweep.since).count();
        const bool ready = tooie::debug::can_warp() && MEM_B(0x12, game_state_addr) == 0;
        const uint16_t id = sweep.ids[sweep.next];
        switch (sweep.phase) {
            case 0:
                if (ms >= sweep.start_ms && ready) {
                    uint16_t map = tooie::debug::current_map(rdram);
                    const Enemy* guarded = find_enemy(id);
                    if (aim_sweep_running && guarded != nullptr && guarded->home_entry != 0) {
                        if (!sweep.maps_known) {
                            sweep.maps = tooie::torch_enemy::maps_placing(rdram, ctx, id);
                            sweep.maps_known = true;
                            sweep.attempt = 0;
                        }
                        if (sweep.attempt < sweep.maps.size()) {
                            map = sweep.maps[sweep.attempt];
                        }
                    }
                    tooie::debug::request_warp(map, 0, true);
                    sweep.phase = 1;
                    sweep.since = clock::now();
                }
                break;
            case 1:
                if (ms >= 3000 && ready) {
                    sweep.phase = 2;
                    sweep.since = clock::now();
                }
                break;
            case 2:
                if (ms >= 8000 && ready) {
                    const Enemy* guarded = find_enemy(id);
                    if (aim_sweep_running && guarded != nullptr && guarded->home_entry != 0 && !actor_present(rdram, guarded->home_entry)) {
                        // Wrong map (or the list was misread): try the next one, up to five.
                        if (++sweep.attempt < std::min<size_t>(sweep.maps.size(), 5)) {
                            sweep.phase = 0;
                            sweep.since = clock::now() - std::chrono::milliseconds(sweep.start_ms);
                        }
                        else {
                            aim_sweep_note(id, sweep.maps.empty() ? "no map places it" : "none of the first maps that place it had one alive");
                            sweep.next++;
                            sweep.maps_known = false;
                            sweep.phase = 0;
                            sweep.since = clock::now() - std::chrono::milliseconds(sweep.start_ms);
                            if (sweep.next >= sweep.ids.size()) {
                                aim_sweep_running = false;
                                tooie::aim_trace::sweep_finished();
                                tooie::toast::show("Aim sweep done: aim_sweep.txt (Dev Files folder)");
                            }
                        }
                        break;
                    }
                    tooie::memory_guard::forget_sites();
                    printf("[enemy-sweep] begin 0x%X\n", id);
                    fflush(stdout);
                    if (aim_sweep_running) {
                        tooie::aim_trace::capture_begin();
                        aim_pending_set(id);
                    }
                    if (id != 0) {
                        spawn_now(rdram, ctx, id);
                    }
                    sweep.phase = 3;
                    sweep.since = clock::now();
                }
                break;
            case 3:
                if (ms >= (aim_sweep_running ? 12000 : 20000)) {
                    printf("[enemy-sweep] end 0x%X\n", id);
                    fflush(stdout);
                    if (aim_sweep_running) {
                        aim_sweep_record(id);
                    }
                    sweep.next++;
                    sweep.maps_known = false;
                    sweep.phase = 0;
                    sweep.since = clock::now() - std::chrono::milliseconds(sweep.start_ms);
                    if (sweep.next >= sweep.ids.size() && aim_sweep_running) {
                        aim_sweep_running = false;
                        tooie::aim_trace::sweep_finished();
                        tooie::toast::show("Aim sweep done: aim_sweep.txt (Dev Files folder)");
                    }
                }
                break;
        }
    }
}

void tooie::enemy_spawner::add_options(recomp::config::Config& cheats, const std::string& master_option) {
    std::vector<recomp::config::ConfigOptionEnumOption> entries;
    for (const Enemy& enemy : enemies) {
        char key[16];
        std::snprintf(key, sizeof(key), "enemy_%X", enemy.id);
        entries.push_back(recomp::config::ConfigOptionEnumOption(enemy.id, key, enemy.name));
    }
    cheats.add_enum_option(option, "Enemy spawner",
        "Pick an enemy, then press Spawn: each press puts one in front of Banjo (when the menu pauses the game, they appear as it closes). Enemies marked (only where it lives) would crash anywhere else, so they only spawn in an area that already has one; elsewhere Spawn does nothing.",
        entries, (uint32_t)default_enemy);
    cheats.add_option_hidden_dependency(option, master_option, false);
    recomp::config::Config* config = &cheats;
    recompui::config::set_option_button(option, "Spawn", [config] {
        const recomp::config::ConfigValueVariant value = config->get_option_value(option);
        const uint32_t* id = std::get_if<uint32_t>(&value);
        if (id == nullptr || *id == 0) {
            return;
        }
        std::lock_guard lock{queue_mutex};
        queue.push_back((uint16_t)*id);
    });
}

void tooie::enemy_spawner::reset() {
    std::lock_guard lock{queue_mutex};
    queue.clear();
}

void tooie::enemy_spawner::tick(uint8_t* rdram, recomp_context* ctx) {
    if (!env_read) {
        read_env();
    }
    sweep_tick(rdram, ctx);
    uint16_t id = 0;
    bool from_env = false;
    if (env_next < env_requests.size() && tooie::debug::can_warp()) {
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - env_started).count();
        if (elapsed >= env_requests[env_next].delay_ms) {
            id = env_requests[env_next].id;
            from_env = true;
        }
    }
    if (id == 0) {
        std::lock_guard lock{queue_mutex};
        if (queue.empty()) {
            return;
        }
        // Presses made while cheats are off (or have since gone off), or with no save being played, are dropped.
        if (!tooie::cheats::enabled() || !tooie::debug::can_warp()) {
            queue.clear();
            return;
        }
        id = queue.front();
    }
    // Wait for a save being played, outside a map change.
    if (!tooie::debug::can_warp() || MEM_B(0x12, game_state_addr) != 0) {
        return;
    }
    if (!spawn_now(rdram, ctx, id)) {
        return;
    }
    if (from_env) {
        env_next++;
    } else {
        std::lock_guard lock{queue_mutex};
        if (!queue.empty()) {
            queue.erase(queue.begin());
        }
    }
}
