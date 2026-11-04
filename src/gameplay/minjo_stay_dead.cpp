// Minjos stay dead (Gameplay > Difficulty, off by default): a Minjo (actor 0x19C) that has been killed does not
// come back.
//
// How a Minjo comes back (headless, 2026-11-04): every placed object of a map, enemies included, is spawned once
// when the map loads (gccubeDll_entrypoint_0 hands the map's actor props to gspropsDll_entrypoint_1, which spawns
// each through func_80108DC0). A killed Minjo's object is removed (func_800FFAB0). The game then leaves it out of
// that map while Banjo stays in the same world (Wasteland and Quagmire, back and forth for 4 minutes), and spawns it
// again after a trip to another world (Spiral Mountain or Mayahem Temple and back). There is no timer in that.
//
// So: func_80800358_chbadjinjo, the Minjo's set-up when it spawns, removes it at once when func_800D395C says so
// (a game mode where Minjos are not wanted). With the option on, that answer is also "remove" for a Minjo this
// session has seen killed, so the game's own path takes it out. A Minjo is known by the save file, the map and
// where it spawns (its prop's position, which never changes), so the record does not depend on object or marker
// addresses, which change from load to load. A Minjo's marker (object +0) is noted at its set-up, so that its
// removal later in the same map is counted as a kill. Kept for this run of the program only, not in the save.
//
// TOOIE_MINJO_LOG=1 logs each Minjo set-up, kill and kept-out Minjo. TOOIE_MINJO_ALL_KILLED=1 (with the option on)
// keeps every Minjo out as if it had been killed, to test the keeping out on its own.

#include <cmath>
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
#include "tooie_hooks.h"
#include "tooie_rdram.h"

namespace {
    // The save file open (the byte the console's load waits on).
    constexpr uint32_t open_file_addr = 0x8012B3F1;

    // A Minjo's spawn spot, to the nearest 4 units, in one save file and map.
    using Key = std::tuple<uint8_t, uint16_t, int32_t, int32_t, int32_t>;

    std::set<Key> killed;
    // Live Minjos in the current map: marker -> its key.
    std::map<uint32_t, Key> live;
    uint16_t live_map = 0xFFFF;

    bool log_on() {
        static const bool log = std::getenv("TOOIE_MINJO_LOG") != nullptr;
        return log;
    }

    bool option_on() {
        try {
            return std::get<bool>(recompui::config::get_general_config().get_option_value(tooie::damage::minjos_stay_dead_option));
        } catch (...) {
            return false;
        }
    }

    bool all_killed() {
        static const bool all = std::getenv("TOOIE_MINJO_ALL_KILLED") != nullptr;
        return all;
    }

    int32_t spot(float v) {
        return (int32_t)std::lround(v / 4.0f);
    }
}

// func_80800358_chbadjinjo after func_800D395C (its answer in $v0, nonzero removes the Minjo); $s0 the Minjo, still at
// the spot it was spawned at.
extern "C" void tooie_minjo_spawn(uint8_t* rdram, recomp_context* ctx) {
    const uint32_t object = (uint32_t)ctx->r16;
    if (!tooie::rdram::valid_ptr(object)) {
        return;
    }
    const uint16_t map = tooie::debug::current_map(rdram);
    if (map != live_map) {
        live.clear();
        live_map = map;
    }
    const float x = tooie::rdram::read_float(rdram, object + 0x04);
    const float y = tooie::rdram::read_float(rdram, object + 0x08);
    const float z = tooie::rdram::read_float(rdram, object + 0x0C);
    const Key key{ tooie::rdram::read_byte(rdram, open_file_addr), map, spot(x), spot(y), spot(z) };
    const bool keep_out = ctx->r2 == 0 && option_on() && (killed.count(key) != 0 || all_killed());
    if (keep_out) {
        ctx->r2 = 1;
    } else if (ctx->r2 == 0) {
        live[tooie::rdram::read_word(rdram, object)] = key;
    }
    if (log_on()) {
        std::printf("[minjo] set-up at %.0f %.0f %.0f, map 0x%X: %s\n", x, y, z, map, keep_out ? "killed before, kept out" : "spawned");
        std::fflush(stdout);
    }
}

// func_800FFAB0 entry: an object is being removed ($a0).
extern "C" void tooie_minjo_removed(uint8_t* rdram, recomp_context* ctx) {
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
    // Only a removal in the map it was spawned in counts as a kill (a map change clears the list instead).
    if (std::get<1>(key) != tooie::debug::current_map(rdram)) {
        return;
    }
    killed.insert(key);
    if (log_on()) {
        std::printf("[minjo] killed: map 0x%X, health bytes %u %u %u\n", std::get<1>(key),
            tooie::rdram::read_byte(rdram, object + 0x5C), tooie::rdram::read_byte(rdram, object + 0x5D), tooie::rdram::read_byte(rdram, object + 0x5E));
        std::fflush(stdout);
    }
}
