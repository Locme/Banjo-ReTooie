// Enemy spawner (Cheats tab, Enemies).
//
// A drop-down of the game's enemies with a Spawn button beside it (the button is RecompFrontend's
// recompui::config::set_option_button). Each press spawns the picked enemy a few steps in front of
// Banjo, facing him, with func_80108474(actor id, f32 pos[3], yaw), the game's spawn-by-id the test
// room uses (src/gameplay/test_room.cpp). Presses are queued and spawned on the game thread, one a frame.
//
// The list is every enemy in that spawn table (gemarkersDll, ids 0xB6 to 0x545). Enemies the game
// builds from shared data instead (Gruntlings and the like, overlay chbaddieDll) are not in the table.
// Many enemies follow a route or use props that only exist in their own world and crash elsewhere
// (the test room's "crashes here" entries, notes/test-room.md); their names say "(own world)".
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
    };

    // Alphabetical, as the drop-down shows them. The option saves the actor id.
    constexpr Enemy enemies[] = {
        { 0x19A, "Beehive (own world)" },
        { 0x30F, "Big Fish (own world)" },
        { 0x3E6, "Biggafoot" },
        { 0x3E5, "Bigfoot (own world)" },
        { 0x35F, "Blubbul" },
        { 0x440, "Boltoid (own world)" },
        { 0x2C1, "Clinker (own world)" },
        { 0x1EF, "Dragunda" },
        { 0x486, "Floatus Floatsum" },
        { 0x31E, "Frazzle (own world)" },
        { 0x476, "Germ (own world)" },
        { 0x12D, "Ghost (own world)" },
        { 0x401, "Gobgoyle" },
        { 0x133, "Gruntydactyl (own world)" },
        { 0x3E9, "Hothand (own world)" },
        { 0x462, "Hothead (own world)" },
        { 0x35E, "Inky" },
        { 0x37C, "Mingy Jongo" },
        { 0x19C, "Minjo (own world)" },
        { 0x112, "Moggy warrior (own world)" },
        { 0x399, "Mucoid" },
        { 0x43E, "Nutta (own world)" },
        { 0x46B, "Pansie (own world)" },
        { 0x3AB, "Rocknut" },
        { 0x426, "S'Hard (own world)" },
        { 0x111, "Snapdragon" },
        { 0x39A, "Soarasaur (own world)" },
        { 0x113, "Sput Sput (own world)" },
        { 0x3BD, "Spy-I-Cam (own world)" },
        { 0x29A, "Swellbelly" },
        { 0x3BE, "Tintup (own world)" },
        { 0x2AE, "Torch enemy" },
        { 0x3FF, "Toxi-Gag (own world)" },
        { 0x3F0, "Toxi-Klang (own world)" },
        { 0x443, "Twinkly, blue (own world)" },
        { 0x444, "Twinkly, green (own world)" },
        { 0x445, "Twinkly, red (own world)" },
        { 0x131, "Ugger" },
        { 0x1DA, "Unga Bunga (own world)" },
        { 0x43F, "Washup (own world)" },
        { 0x35C, "Whirlweed (own world)" },
        { 0x213, "Zubba (own world)" },
    };
    constexpr uint16_t default_enemy = 0x111;

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
        "Pick an enemy, then press Spawn: each press puts one in front of Banjo (when the menu pauses the game, they appear as it closes). Enemies marked (own world) crash the game outside the world they belong to. Gruntlings and other enemies the game builds from shared data are not in the list.",
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
    if (!spawn_in_front(rdram, ctx, id)) {
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
