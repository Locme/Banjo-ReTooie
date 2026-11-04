// Enemy Respawn (Gameplay > Difficulty): Original, or Never, where an enemy you have killed does not come back. And
// Minjos Stay Dead (Gameplay > Difficulty, off by default), the same for Minjos (actor 0x19C) alone.
//
// How enemies come back (headless, 2026-11-04): a map's placed objects, enemies included, are all spawned as the map
// loads (gccubeDll_entrypoint_0 hands the map's actor props to gspropsDll_entrypoint_1, which spawns each through
// func_80108DC0). Leaving a map and coming back spawns its enemies again (Wasteland's three Uggers on every visit).
// There is no respawn timer to scale; L had asked for 1/2x to 3x of one.
//
// With Never, the spawn of a placed enemy that this run of the game has seen killed is skipped: a hook just before
// gspropsDll_entrypoint_1's call to func_80108DC0 jumps past it. An enemy is the prop's actor id (+0x08) on the enemy
// spawner's list (tooie::enemy_spawner::is_enemy); it is known by the save file, the map, its prop's position (+0x00,
// three halves) and that id, which stay the same from load to load. A hook just after the call notes the object's
// marker (object +0) with that key, and the object-removal hook (func_800FFAB0) counts the removal of a noted enemy as
// a kill when it happens in its own map, not during a map change, and near Banjo (the game removes far objects too). Kept for this run of the program only, not in the
// save.
//
// Minjos were first kept out from their own set-up (func_80800358_chbadjinjo), but that runs only on a Minjo's
// first visit to its map; the map spawns it every time, so it is kept out here like the rest.
//
// TOOIE_RESPAWN_LOG=1 logs kills and skipped spawns. TOOIE_RESPAWN_ALL_KILLED=1 (with Never or Minjos Stay Dead on)
// skips every placed enemy they cover as if it had been killed, to test the skipping on its own.

#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <tuple>
#include <variant>

#include "recomp.h"
#include "recompui/config.h"
#include "tooie_damage.h"
#include "tooie_debug.h"
#include "tooie_enemy_spawner.h"
#include "tooie_hooks.h"
#include "tooie_player_cheats.h"
#include "tooie_rdram.h"

namespace {
    // The save file open (the byte the console's load waits on).
    constexpr uint32_t open_file_addr = 0x8012B3F1;

    // Save file, map, the prop's position and its actor id.
    using Key = std::tuple<uint8_t, uint16_t, int16_t, int16_t, int16_t, uint16_t>;

    std::set<Key> killed;
    // Enemies spawned in the current map: marker -> key.
    std::map<uint32_t, Key> live;
    uint16_t live_map = 0xFFFF;

    bool log_on() {
        static const bool log = std::getenv("TOOIE_RESPAWN_LOG") != nullptr;
        return log;
    }

    bool all_killed() {
        static const bool all = std::getenv("TOOIE_RESPAWN_ALL_KILLED") != nullptr;
        return all;
    }

    bool never_on() {
        try {
            return static_cast<tooie::damage::EnemyRespawn>(std::get<uint32_t>(recompui::config::get_general_config().get_option_value(
                tooie::damage::enemy_respawn_option))) == tooie::damage::EnemyRespawn::Never;
        } catch (...) {
            return false;
        }
    }

    // The game also removes objects as Banjo goes far from them (each area chunk's objects come and go; Wasteland's
    // Uggers were removed 2500 to 3700 units away just after it loaded), so only a removal this close to Banjo is
    // a kill.
    constexpr float kill_range = 1500.0f;

    bool near_banjo(uint8_t* rdram, uint32_t object) {
        float p[3];
        if (!tooie::player_cheats::position(rdram, p)) {
            return false;
        }
        float d2 = 0.0f;
        for (int k = 0; k < 3; k++) {
            const float d = tooie::rdram::read_float(rdram, object + 0x04 + 4 * k) - p[k];
            d2 += d * d;
        }
        return d2 < kill_range * kill_range;
    }

    constexpr uint16_t minjo_actor = 0x19C;

    bool minjos_on() {
        try {
            return std::get<bool>(recompui::config::get_general_config().get_option_value(tooie::damage::minjos_stay_dead_option));
        } catch (...) {
            return false;
        }
    }

    uint16_t prop_actor(uint8_t* rdram, uint32_t prop) {
        return (uint16_t)tooie::rdram::read_half(rdram, prop + 0x08);
    }

    Key key_of(uint8_t* rdram, uint32_t prop) {
        return Key{ tooie::rdram::read_byte(rdram, open_file_addr), tooie::debug::current_map(rdram),
            tooie::rdram::read_half(rdram, prop + 0x00), tooie::rdram::read_half(rdram, prop + 0x02),
            tooie::rdram::read_half(rdram, prop + 0x04), prop_actor(rdram, prop) };
    }
}

// gspropsDll_entrypoint_1 just before it spawns a prop ($s1) through func_80108DC0: nonzero skips the spawn.
extern "C" int tooie_respawn_skip(uint8_t* rdram, recomp_context* ctx) {
    const uint32_t prop = (uint32_t)ctx->r17;
    if (!tooie::rdram::valid_ptr(prop) || !tooie::enemy_spawner::is_enemy(prop_actor(rdram, prop))) {
        return 0;
    }
    if (!never_on() && !(minjos_on() && prop_actor(rdram, prop) == minjo_actor)) {
        return 0;
    }
    const Key key = key_of(rdram, prop);
    const bool skip = all_killed() || killed.count(key) != 0;
    if (skip && log_on()) {
        std::printf("[respawn] kept out: actor 0x%X at %d %d %d, map 0x%X\n", std::get<5>(key), std::get<2>(key), std::get<3>(key),
            std::get<4>(key), std::get<1>(key));
        std::fflush(stdout);
    }
    return skip ? 1 : 0;
}

// gspropsDll_entrypoint_1 just after the spawn: $v0 the new object (0 if none), $s1 the prop.
extern "C" void tooie_respawn_spawned(uint8_t* rdram, recomp_context* ctx) {
    const uint16_t map = tooie::debug::current_map(rdram);
    if (map != live_map) {
        live.clear();
        live_map = map;
    }
    const uint32_t object = (uint32_t)ctx->r2;
    const uint32_t prop = (uint32_t)ctx->r17;
    if (!tooie::rdram::valid_ptr(object) || !tooie::rdram::valid_ptr(prop) || !tooie::enemy_spawner::is_enemy(prop_actor(rdram, prop))) {
        return;
    }
    live[tooie::rdram::read_word(rdram, object)] = key_of(rdram, prop);
}

// func_800FFAB0 entry: an object is being removed ($a0).
extern "C" void tooie_respawn_removed(uint8_t* rdram, recomp_context* ctx) {
    if (live.empty()) {
        return;
    }
    const uint32_t object = (uint32_t)ctx->r4;
    if (!tooie::rdram::valid_ptr(object)) {
        return;
    }
    const auto it = live.find(tooie::rdram::read_word(rdram, object));
    if (it == live.end()) {
        return;
    }
    const Key key = it->second;
    live.erase(it);
    if (tooie::debug::map_change_busy(rdram) || std::get<1>(key) != tooie::debug::current_map(rdram) ||
        !near_banjo(rdram, object)) {
        return;
    }
    killed.insert(key);
    if (log_on()) {
        std::printf("[respawn] killed: actor 0x%X at %d %d %d, map 0x%X\n", std::get<5>(key), std::get<2>(key), std::get<3>(key),
            std::get<4>(key), std::get<1>(key));
        std::fflush(stdout);
    }
}
