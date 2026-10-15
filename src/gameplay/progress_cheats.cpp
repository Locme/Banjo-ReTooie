#include <array>
#include <cstdint>
#include <cstdio>
#include <cstdlib>

#include "recomp.h"
#include "funcs.h"

#include "tooie_cheats.h"
#include "tooie_debug.h"
#include "tooie_race_warp.h"
#include "tooie_hooks.h"
#include "tooie_progress_cheats.h"

// Cheats that work through the game's own flags: the ten Cheato codes (plus HOMING) and Unlock all moves.
//
// The flag numbers are the N64 ones from the decomp's include/gameflags.h. They are not the XBLA ones
// the report lists: here a cheat's "active" flag is 0x534 + n (FEATHERS is 0x534), and HOMING is 0x5A3.
namespace {
    struct Cheato {
        const char* option;
        int32_t flag;
    };

    constexpr Cheato cheato_list[] = {
        { "cheato_feathers", 0x534 },
        { "cheato_eggs", 0x535 },
        { "cheato_fallproof", 0x536 },
        { "cheato_honeyback", 0x537 },
        { "cheato_jukebox", 0x538 },
        { "cheato_getjiggy", 0x539 },
        { "cheato_superbanjo", 0x53A },
        { "cheato_superbaddy", 0x53B },
        { "cheato_honeyking", 0x53C },
        { "cheato_nestking", 0x53D },
        { "cheato_homing", 0x5A3 },
    };
    constexpr size_t cheato_count = sizeof(cheato_list) / sizeof(cheato_list[0]);

    // The N64 game's Stop 'n' Swop flags (gameflags.h): the blue and pink mystery eggs are "acquired" when the
    // game sees the Banjo-Kazooie link. The overlay that spawns them (0x80800024) reads these flags.
    // The yellow egg only has a "hatched" flag, so it is left alone.
    constexpr int32_t swop_flags[] = { 0x3E3, 0x3E5 };
    constexpr size_t swop_count = sizeof(swop_flags) / sizeof(swop_flags[0]);

    // Move n is learned when game flag 237 + n is set (0xED = beak barge), for the 60 moves 237..296.
    constexpr int32_t first_move_flag = 237;
    constexpr int32_t last_move_flag = 296;

    // Unlock everything (handoff 4.72): the N64 flags (decomp include/gameflags.h, the same ids the report
    // lists) for every world, hub path, station, silo, warp pad and Cheato code, and the doors and shortcuts
    // the report names that have a flag of their own. Set once when the option is switched on; the area
    // then reloads so everything in it is redrawn, and saving keeps it.
    constexpr int32_t unlock_ranges[][2] = {
        { 0x392, 0x39A },  // worlds Mayahem Temple .. Cauldron Keep
        { 0x32D, 0x333 },  // Jamjars' silos
        { 0x3AC, 0x3D5 },  // warp pads in every world (0x3D1..0x3D3 and the CK ones past 0x3D5 are unused)
        { 0x06C, 0x07A },  // Cheato codes: typeable and available
        { 0x1B4, 0x1B7 },  // Grunty Industries battery doors
    };
    constexpr int32_t unlock_flags[] = {
        0x391,                                   // Isle o' Hags: the bridge to Hailfire Peaks
        0x3E9, 0x3EA, 0x3F0,                     // Isle o' Hags: Pine Grove doors and Kazooie's boulder
        0x436,                                   // Cauldron Keep drawbridge
        0x1AB,                                   // Grunty Industries main entrance
        0x096, 0x163, 0x164, 0x1CF, 0x1D0, 0x403, // Chuffy's stations
        0x042, 0x04B, 0x446,                     // Cheato: NESTKING, the Jiggywiggy special, HOMING
        0x0D5,                                   // Mayahem Temple prison compound
        0x3AA,                                   // Spiral Mountain Jinjo door
        0x3EE,                                   // the first warp pad
    };

    // Frames between checks. A cheat only needs to take hold within a fraction of a second.
    constexpr int check_interval = 10;

    std::array<bool, cheato_count> set_by_us{};
    std::array<bool, swop_count> swop_set_by_us{};
    int frame_counter = 0;

    // The game's flag getter and setter (func_800DA298 and func_800DA3B8), called on the game thread
    // with a copy of the hook's context so the caller's registers stay untouched.
    bool flag_get(uint8_t* rdram, recomp_context* ctx, int32_t flag) {
        recomp_context saved = *ctx;
        ctx->r4 = (uint64_t)(int64_t)flag;
        func_800DA298(rdram, ctx);
        bool value = (int32_t)ctx->r2 != 0;
        *ctx = saved;
        return value;
    }

    void flag_set(uint8_t* rdram, recomp_context* ctx, int32_t flag, bool value) {
        recomp_context saved = *ctx;
        ctx->r4 = (uint64_t)(int64_t)flag;
        ctx->r5 = value ? 1 : 0;
        func_800DA3B8(rdram, ctx);
        *ctx = saved;
    }

    // The flag the getter is currently asked about, saved at its entry for the hook at its return.
    thread_local int32_t pending_flag = -1;
}

void tooie::progress_cheats::tick(uint8_t* rdram, recomp_context* ctx) {
    if (++frame_counter < check_interval) {
        return;
    }
    frame_counter = 0;

    // TOOIE_SET_FLAGS=<flag>[-<flag>][,...] (hex): sets those game flags once a map is loaded, for
    // headless tests that need progress (the Totals checklist, src/gameplay/totals_checklist.cpp).
    static bool test_flags_done = false;
    if (!test_flags_done && tooie::debug::can_warp()) {
        test_flags_done = true;
        if (const char* list = std::getenv("TOOIE_SET_FLAGS")) {
            int count = 0;
            for (const char* p = list; *p;) {
                char* end = nullptr;
                const long first = std::strtol(p, &end, 16);
                long last = first;
                if (*end == '-') {
                    last = std::strtol(end + 1, &end, 16);
                }
                for (long f = first; f <= last; f++) {
                    flag_set(rdram, ctx, (int32_t)f, true);
                    count++;
                }
                p = (*end == ',') ? end + 1 : end;
                if (end == p && *p) {
                    break;
                }
            }
            std::printf("[flags] set %d flags from TOOIE_SET_FLAGS\n", count);
            std::fflush(stdout);
        }
    }

    // Unlock everything, once each time the option is switched on (while a save is being played).
    static bool unlock_was_on = false;
    const bool unlock_on = tooie::cheats::is_on("cheat_unlock_everything");
    if (unlock_on && !unlock_was_on && tooie::debug::can_warp()) {
        // Only flags that were still clear count, so a save that already has everything isn't reloaded.
        int count = 0;
        auto unlock = [&](int32_t f) {
            if (!flag_get(rdram, ctx, f)) {
                flag_set(rdram, ctx, f, true);
                count++;
            }
        };
        for (const auto& range : unlock_ranges) {
            for (int32_t f = range[0]; f <= range[1]; f++) {
                unlock(f);
            }
        }
        for (int32_t f : unlock_flags) {
            unlock(f);
        }
        for (int32_t f = first_move_flag; f <= last_move_flag; f++) {
            unlock(f);
        }
        if (count > 0) {
            const uint16_t map = tooie::debug::current_map(rdram);
            const uint8_t exit = rdram[((0x80127630u + 0x13) ^ 3u) - 0x80000000u];
            std::printf("[unlock] set %d flags, reloading map 0x%X exit %u\n", count, map, exit);
            std::fflush(stdout);
            // The map change as the warp makes it (src/debug/warp.cpp), on a copy of the context.
            recomp_context saved = *ctx;
            ctx->r4 = map;
            ctx->r5 = exit;
            ctx->r6 = 1;
            func_800A7990(rdram, ctx);
            *ctx = saved;
        }
        unlock_was_on = true;
    } else if (!unlock_on) {
        unlock_was_on = false;
    }

    for (size_t i = 0; i < cheato_count; i++) {
        const bool want = tooie::cheats::is_on(cheato_list[i].option);
        if (want) {
            if (!flag_get(rdram, ctx, cheato_list[i].flag)) {
                flag_set(rdram, ctx, cheato_list[i].flag, true);
                set_by_us[i] = true;
            }
        } else if (set_by_us[i]) {
            // Only undo what this cheat switched on, so a code typed in the Code Chamber stays.
            flag_set(rdram, ctx, cheato_list[i].flag, false);
            set_by_us[i] = false;
        }
    }

    const bool swop = tooie::cheats::is_on("cheat_stop_n_swop");
    for (size_t i = 0; i < swop_count; i++) {
        if (swop) {
            if (!flag_get(rdram, ctx, swop_flags[i])) {
                flag_set(rdram, ctx, swop_flags[i], true);
                swop_set_by_us[i] = true;
            }
        } else if (swop_set_by_us[i]) {
            flag_set(rdram, ctx, swop_flags[i], false);
            swop_set_by_us[i] = false;
        }
    }

    // Headless test aid: once a second, print each Cheato flag as the game's own getter reads it.
    static const bool log = std::getenv("TOOIE_PLAYER_LOG") != nullptr;
    static int log_counter = 0;
    if (log && ++log_counter >= 6) {
        log_counter = 0;
        std::printf("[flags]");
        for (size_t i = 0; i < cheato_count; i++) {
            std::printf(" %d", flag_get(rdram, ctx, cheato_list[i].flag) ? 1 : 0);
        }
        std::printf(" | swop %d %d", flag_get(rdram, ctx, 0x3E3) ? 1 : 0, flag_get(rdram, ctx, 0x3E5) ? 1 : 0);
        std::printf(" | moves 236:%d 237:%d 265:%d 296:%d 297:%d\n", flag_get(rdram, ctx, 236) ? 1 : 0,
            flag_get(rdram, ctx, 237) ? 1 : 0, flag_get(rdram, ctx, 265) ? 1 : 0,
            flag_get(rdram, ctx, 296) ? 1 : 0, flag_get(rdram, ctx, 297) ? 1 : 0);
        std::fflush(stdout);
    }
}

// Hooks on the flag getter (see banjotooie.us.toml): the entry notes which flag is asked about, and the
// return reports the moves as learned while Unlock all moves is on. The save is never touched.
extern "C" void tooie_flag_get_enter(uint8_t* rdram, recomp_context* ctx) {
    pending_flag = (int32_t)ctx->r4;
}

extern "C" void tooie_flag_get_leave(uint8_t* rdram, recomp_context* ctx) {
    bool race_value = false;
    if (tooie::race_warp::override_flag(pending_flag, race_value)) {
        ctx->r2 = race_value ? 1 : 0;
        return;
    }
    if (pending_flag >= first_move_flag && pending_flag <= last_move_flag && tooie::cheats::is_on("cheat_all_moves")) {
        ctx->r2 = 1;
    }
}
