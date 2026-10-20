// Enemy spawner (Cheats tab, Enemies).
//
// A drop-down of the game's enemies with a Spawn button beside it (the button is RecompFrontend's
// recompui::config::set_option_button). Each press spawns the picked enemy a few steps in front of
// Banjo, facing him, with func_80108474(actor id, f32 pos[3], yaw), the game's spawn-by-id the test
// room uses (src/gameplay/test_room.cpp). Presses are queued and spawned on the game thread, one a frame.
//
// The list is every enemy in that spawn table (gemarkersDll, ids 0xB6 to 0x545). Every enemy a map
// places comes from the same table too: Quagmire's ground enemies, called Gruntlings in older notes, are
// actor 0x131 (chdiggerground, listed as Ugger). Many enemies follow a route or use props that only exist
// where they live and crash elsewhere (the test room's "crashes here" entries, notes/test-room.md, and
// headless spawns that hit null reads). Those say "(only where it lives)" and only spawn while the area
// already has one of them (a live object whose +0x10 is the actor's entry); otherwise a press does nothing.
//
// Headless test aid: TOOIE_ENEMY_SPAWN=<hex id>[@ms][,<hex id>@ms...] spawns each enemy once, ms after
// the game loop first runs, whenever a save is being played.

#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <mutex>
#include <string>
#include <variant>
#include <vector>

#include "recomp.h"
#include "funcs.h"
#include "recompui/config.h"
#include "tooie_cheats.h"
#include "tooie_debug.h"
#include "tooie_enemy_spawner.h"
#include "tooie_rdram.h"

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
        { 0x19A, "Beehive (only where it lives)", 0x80086D10 },
        { 0x30F, "Big Fish (only where it lives)", 0x80086D90 },
        { 0x310, "Big Fish 2 (only where it lives)", 0x80086D98 },
        { 0x3E5, "Bigfoot (only where it lives)", 0x80086338 },
        { 0x3E6, "Biggafoot", 0 },
        { 0x44E, "Biggafoot 2 (only where it lives)", 0x80086348 },
        { 0x35F, "Blubbul", 0 },
        { 0x440, "Boltoid (only where it lives)", 0x800864F0 },
        { 0x2C1, "Clinker (only where it lives)", 0x800873A8 },
        { 0x2BF, "Clinker 2 (only where it lives)", 0x800873B0 },
        { 0x2C0, "Clinker 3 (only where it lives)", 0x800873B8 },
        { 0x1EF, "Dragunda", 0 },
        { 0x153, "Evil spirit", 0 },
        { 0x482, "Eyeball", 0 },
        { 0x483, "Eyeball 2", 0 },
        { 0x3BF, "Factory robot (only where it lives)", 0x80086228 },
        { 0x3A2, "Flamer", 0 },
        { 0x349, "Floater", 0 },
        { 0x486, "Floatus Floatsum", 0 },
        { 0x31E, "Frazzle (only where it lives)", 0x80086DB8 },
        { 0x363, "Freezy", 0 },
        { 0x2FF, "Freezy 2", 0 },
        { 0x476, "Germ (only where it lives)", 0x80087698 },
        { 0x12D, "Ghost (only where it lives)", 0x80085D50 },
        { 0x1E0, "Ghost 2 (only where it lives)", 0x80085D58 },
        { 0x401, "Gobgoyle", 0 },
        { 0x402, "Gobgoyle 2 (only where it lives)", 0x80087588 },
        { 0x133, "Gruntydactyl (only where it lives)", 0x80085CA8 },
        { 0x134, "Gruntydactyl 2 (only where it lives)", 0x80085CB0 },
        { 0x3E9, "Hothand (only where it lives)", 0x80087598 },
        { 0x400, "Hothand 2 (only where it lives)", 0x800875A0 },
        { 0x462, "Hothead (only where it lives)", 0x800865C8 },
        { 0x35E, "Inky", 0 },
        { 0x31F, "Lagoon fish", 0 },
        { 0x300, "Lake monster", 0 },
        { 0x37C, "Mingy Jongo", 0 },
        { 0x19C, "Minjo (only where it lives)", 0x80086968 },
        { 0x112, "Moggy warrior (only where it lives)", 0x80085CC8 },
        { 0x399, "Mucoid", 0 },
        { 0x398, "Mucoid 2", 0 },
        { 0x3A0, "Mucoid 3", 0 },
        { 0x43E, "Nutta (only where it lives)", 0x800864E0 },
        { 0x47F, "Onion", 0 },
        { 0x46B, "Pansie (only where it lives)", 0x80086650 },
        { 0x2FC, "Piranha (only where it lives)", 0x80086DD0 },
        { 0x2FD, "Piranha 2 (only where it lives)", 0x80086DD8 },
        { 0x2FE, "Piranha 3 (only where it lives)", 0x80086DE0 },
        { 0x3AB, "Rocknut", 0 },
        { 0x426, "S'Hard (only where it lives)", 0x80086648 },
        { 0x243, "Shadow baddie", 0 },
        { 0x111, "Snapdragon", 0 },
        { 0x39A, "Soarasaur (only where it lives)", 0x80086028 },
        { 0x113, "Sput Sput (only where it lives)", 0x80086F20 },
        { 0x123, "Sput Sput 2 (only where it lives)", 0x80086F28 },
        { 0x3BD, "Spy-I-Cam (only where it lives)", 0x80086218 },
        { 0x4E9, "Squits", 0 },
        { 0x16F, "Stinger", 0 },
        { 0x29A, "Swellbelly", 0 },
        { 0x3BE, "Tintup (only where it lives)", 0x80086220 },
        { 0x2AE, "Torch enemy", 0 },
        { 0x3FF, "Toxi-Gag (only where it lives)", 0x80087518 },
        { 0x3F0, "Toxi-Klang (only where it lives)", 0x80087440 },
        { 0x442, "Twinkly 4 (only where it lives)", 0x800864F8 },
        { 0x446, "Twinkly 5 (only where it lives)", 0x80086508 },
        { 0x44D, "Twinkly 6 (only where it lives)", 0x80086500 },
        { 0x443, "Twinkly, blue (only where it lives)", 0x80086510 },
        { 0x444, "Twinkly, green (only where it lives)", 0x80086518 },
        { 0x445, "Twinkly, red (only where it lives)", 0x80086520 },
        { 0x131, "Ugger", 0 },
        { 0x1DA, "Unga Bunga (only where it lives)", 0x80085AF0 },
        { 0x1DB, "Unga Bunga 2 (only where it lives)", 0x80085AF8 },
        { 0x43F, "Washup (only where it lives)", 0x800864E8 },
        { 0x35C, "Whirlweed (only where it lives)", 0x80085F28 },
        { 0x35D, "Whirlweed 2 (only where it lives)", 0x80085F30 },
        { 0x213, "Zubba (only where it lives)", 0x800865C0 },
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

    // Spawns the enemy in front of Banjo. False when there is no player to spawn it by.
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
        const float pos[3] = {
            read_float(rdram, pos_ptr) + std::sin(rad) * spawn_distance,
            read_float(rdram, pos_ptr + 4),
            read_float(rdram, pos_ptr + 8) + std::cos(rad) * spawn_distance,
        };
        // Facing back at Banjo.
        const uint32_t object = spawn(rdram, ctx, id, pos, std::fmod(yaw + 180.0f, 360.0f));
        printf("[enemy-spawner] actor 0x%X at %.0f %.0f %.0f: object 0x%08X\n", id, pos[0], pos[1], pos[2], object);
        fflush(stdout);
        return true;
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
    const Enemy* enemy = find_enemy(id);
    if (enemy != nullptr && enemy->home_entry != 0 && !actor_present(rdram, enemy->home_entry)) {
        // It would crash here: drop the press.
        printf("[enemy-spawner] actor 0x%X not spawned: none in this area (it only works where it lives)\n", id);
        fflush(stdout);
    } else if (!spawn_in_front(rdram, ctx, id)) {
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
