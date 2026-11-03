#include <array>
#include <atomic>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "recomp.h"
#include "funcs.h"

#include "tooie_cheats.h"
#include "tooie_debug.h"
#include "tooie_race_warp.h"
#include "tooie_hooks.h"
#include "tooie_progress_cheats.h"

// Cheats that work through the game's own flags: the ten Cheato codes (plus HOMING), Unlock all moves
// and Learn Every Move.
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

    // 100% complete: the flags of a save with everything done except Hag 1, plus two counters the game
    // keeps as numbers (lowest bit first): Jiggywiggy's challenges done (11 = all, the Hag 1 battle open)
    // and Honey B's health upgrades (5 = all).
#include "complete_flags.inc"
    constexpr int32_t jiggywiggy_count_flag = 0x35C;

    // Beat Hag 1: what the game sets when she is beaten (0x043), Bottles' energy restored in the ending
    // (0x578), and the Hag 1 and ending replays (global flags, shared by all three files).
    constexpr int32_t beat_hag_flags[] = { 0x043, 0x578, 0xBD4, 0xBFC, 0xBFD, 0xBFE, 0xBFF };
    // Whether the file being played has everything complete_check_ranges lists (checked about once a
    // second on the game thread, read by the Cheats tab to show Beat Hag 1).
    std::atomic<bool> file_complete{false};
    constexpr int32_t honey_b_count_flag = 0x4EA;

    // Dragon Kazooie is a learned "ability" flag, not a form (ScriptHawk's toggle flips the same flag):
    // Humba's Isle o' Hags pool sets and clears it.
    constexpr int32_t dragon_kazooie_flag = 0x3EC;

    // Frames between checks. A cheat only needs to take hold within a fraction of a second.
    constexpr int check_interval = 10;

    // What the Cheato and Stop 'n' Swop cheats switched on, per save file (by slot + 1, as Bottles' Revenge
    // keeps its intro tries; 0 is a debug warp with no file open), so a cheat switched off only undoes
    // what it set in the file being played, and a code typed in another file's Code Chamber stays.
    constexpr int file_count = 9;
    std::array<std::array<bool, cheato_count>, file_count> set_by_us{};
    std::array<std::array<bool, swop_count>, file_count> swop_set_by_us{};
    constexpr gpr save_slot_addr = (int32_t)0x8012B3F1;   // the open save file, -1 for none
    constexpr gpr game_mode_addr = (int32_t)0x8012B3F2;   // 2 in a replay, which swaps in flags of its own
    int frame_counter = 0;

    // The flag the getter is currently asked about, saved at its entry for the hook at its return.
    thread_local int32_t pending_flag = -1;
    // Set while this file reads a flag as the save has it: the getter's hook then leaves the answer alone
    // (Unlock all moves and the race warp's stand-ins would otherwise report flags that aren't set).
    thread_local bool raw_read = false;

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

    // The flag as the save file has it, without the getter hook's overrides. Used by the cheats that write
    // flags, so with Unlock all moves on Learn Every Move still writes the moves it reports as learned.
    bool flag_get_raw(uint8_t* rdram, recomp_context* ctx, int32_t flag) {
        const bool was = raw_read;
        raw_read = true;
        const bool value = flag_get(rdram, ctx, flag);
        raw_read = was;
        return value;
    }

    void flag_set(uint8_t* rdram, recomp_context* ctx, int32_t flag, bool value) {
        recomp_context saved = *ctx;
        ctx->r4 = (uint64_t)(int64_t)flag;
        ctx->r5 = value ? 1 : 0;
        func_800DA3B8(rdram, ctx);
        *ctx = saved;
    }

    // Writes a number into `bits` flags from `first` on, lowest bit first (func_800DA7A8).
    void flag_set_value(uint8_t* rdram, recomp_context* ctx, int32_t first, int32_t value, int32_t bits) {
        recomp_context saved = *ctx;
        ctx->r4 = (uint64_t)(int64_t)first;
        ctx->r5 = (uint64_t)(int64_t)value;
        ctx->r6 = (uint64_t)(int64_t)bits;
        func_800DA7A8(rdram, ctx);
        *ctx = saved;
    }

    // Reloads the area Banjo is in, the way the warp changes maps (src/debug/warp.cpp), so what the
    // flags changed is redrawn.
    void reload_area(uint8_t* rdram, recomp_context* ctx, const char* why, int count) {
        const uint16_t map = tooie::debug::current_map(rdram);
        const uint8_t exit = rdram[((0x80127630u + 0x13) ^ 3u) - 0x80000000u];
        std::printf("[%s] set %d flags, reloading map 0x%X exit %u\n", why, count, map, exit);
        std::fflush(stdout);
        recomp_context saved = *ctx;
        ctx->r4 = map;
        ctx->r5 = exit;
        ctx->r6 = 1;
        func_800A7990(rdram, ctx);
        *ctx = saved;
    }

    // Banjo is in a level of a save being played, with no map change under way: the game's level id
    // (0x8012762C) is 0x0F..0x1B but not 0x11, as for saving (src/game/timer_save.cpp). Not in the
    // intro or a cutscene map, where a reload would cut the scene short.
    bool in_level(uint8_t* rdram) {
        const int level = MEM_BU(0, (gpr)(int32_t)0x8012762C);
        return tooie::debug::can_warp() && level >= 0x0F && level < 0x1C && level != 0x11 &&
            MEM_B(0x12, (gpr)(int32_t)0x80127630) == 0;
    }
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
            if (!flag_get_raw(rdram, ctx, f)) {
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
            reload_area(rdram, ctx, "unlock", count);
        }
        unlock_was_on = true;
    } else if (!unlock_on) {
        unlock_was_on = false;
    }

    // Learn Every Move (L, 2026-10-16), once each time the option is switched on: the moves for real,
    // where Unlock all moves only makes them count as learned. Saving keeps them.
    static bool learn_was_on = false;
    const bool learn_on = tooie::cheats::is_on("cheat_learn_moves");
    if (learn_on && !learn_was_on && in_level(rdram)) {
        int count = 0;
        for (int32_t f = first_move_flag; f <= last_move_flag; f++) {
            if (!flag_get_raw(rdram, ctx, f)) {
                flag_set(rdram, ctx, f, true);
                count++;
            }
        }
        if (count > 0) {
            reload_area(rdram, ctx, "learn-moves", count);
        }
        learn_was_on = true;
    } else if (!learn_on) {
        learn_was_on = false;
    }

    // 100% complete, once each time the option is switched on (while a save is being played). Like
    // Unlock everything it only adds: saving keeps it and switching it off undoes nothing.
    static bool complete_was_on = false;
    const bool complete_on = tooie::cheats::is_on("cheat_complete");
    if (complete_on && !complete_was_on && in_level(rdram)) {
        int count = 0;
        for (const auto& range : complete_ranges) {
            for (int32_t f = range[0]; f <= range[1]; f++) {
                if (!flag_get_raw(rdram, ctx, f)) {
                    flag_set(rdram, ctx, f, true);
                    count++;
                }
            }
        }
        flag_set_value(rdram, ctx, jiggywiggy_count_flag, 11, 4);
        flag_set_value(rdram, ctx, honey_b_count_flag, 5, 3);
        reload_area(rdram, ctx, "complete", count);
        complete_was_on = true;
    } else if (!complete_on) {
        complete_was_on = false;
    }

    // Is the file 100% (for Beat Hag 1 to show)? Checked every sixth check, about once a second.
    static int complete_check_counter = 0;
    if (++complete_check_counter >= 6) {
        complete_check_counter = 0;
        bool all = tooie::debug::can_warp();
        for (const auto& range : complete_check_ranges) {
            for (int32_t f = range[0]; all && f <= range[1]; f++) {
                all = flag_get(rdram, ctx, f);
            }
        }
        if (all != file_complete.load()) {
            std::printf("[complete] file is %s100%%\n", all ? "" : "not ");
            std::fflush(stdout);
        }
        file_complete = all;
    }

    // Beat Hag 1, once each time the option is switched on (only shown once the file is 100%).
    static bool beat_hag_was_on = false;
    const bool beat_hag_on = tooie::cheats::is_on("cheat_beat_hag");
    if (beat_hag_on && !beat_hag_was_on && in_level(rdram) && file_complete) {
        int count = 0;
        for (int32_t f : beat_hag_flags) {
            if (!flag_get_raw(rdram, ctx, f)) {
                flag_set(rdram, ctx, f, true);
                count++;
            }
        }
        reload_area(rdram, ctx, "beat-hag", count);
        beat_hag_was_on = true;
    } else if (!beat_hag_on) {
        beat_hag_was_on = false;
    }

    // Dragon Kazooie: while on, Kazooie is the dragon (in every save played); switching it off makes her
    // Kazooie again. Left off and untouched, the save's own state (Humba's pool) stands. The area reloads
    // so her model changes.
    static bool dragon_was_on = false;
    const bool dragon_on = tooie::cheats::is_on("cheat_dragon_kazooie");
    if (in_level(rdram)) {
        const bool is_dragon = flag_get(rdram, ctx, dragon_kazooie_flag);
        if ((dragon_on && !is_dragon) || (!dragon_on && dragon_was_on && is_dragon)) {
            flag_set(rdram, ctx, dragon_kazooie_flag, dragon_on);
            reload_area(rdram, ctx, "dragon", 1);
        }
        dragon_was_on = dragon_on;
    }

    // The Cheato and Stop 'n' Swop flags: only while a save file is being played (not the title, the game
    // select or a replay's own flags), and undone only in the file they were set in.
    const int file = (int8_t)MEM_B(0, save_slot_addr) + 1;
    if (tooie::debug::can_warp() && MEM_BU(0, game_mode_addr) != 2 && file >= 0 && file < file_count) {
        auto& ours = set_by_us[file];
        for (size_t i = 0; i < cheato_count; i++) {
            const bool want = tooie::cheats::is_on(cheato_list[i].option);
            if (want) {
                if (!flag_get_raw(rdram, ctx, cheato_list[i].flag)) {
                    flag_set(rdram, ctx, cheato_list[i].flag, true);
                    ours[i] = true;
                }
            } else if (ours[i]) {
                // Only undo what this cheat switched on, so a code typed in the Code Chamber stays.
                flag_set(rdram, ctx, cheato_list[i].flag, false);
                ours[i] = false;
            }
        }

        auto& swop_ours = swop_set_by_us[file];
        const bool swop = tooie::cheats::is_on("cheat_stop_n_swop");
        for (size_t i = 0; i < swop_count; i++) {
            if (swop) {
                if (!flag_get_raw(rdram, ctx, swop_flags[i])) {
                    flag_set(rdram, ctx, swop_flags[i], true);
                    swop_ours[i] = true;
                }
            } else if (swop_ours[i]) {
                flag_set(rdram, ctx, swop_flags[i], false);
                swop_ours[i] = false;
            }
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
    if (raw_read) {
        return;
    }
    bool race_value = false;
    if (tooie::race_warp::override_flag(pending_flag, race_value)) {
        ctx->r2 = race_value ? 1 : 0;
        return;
    }
    if (pending_flag >= first_move_flag && pending_flag <= last_move_flag && tooie::cheats::is_on("cheat_all_moves")) {
        ctx->r2 = 1;
    }
}

bool tooie::progress_cheats::complete_reached() {
    return file_complete.load();
}

bool tooie::progress_cheats::get_flag(uint8_t* rdram, recomp_context* ctx, int32_t flag) {
    return flag_get(rdram, ctx, flag);
}

void tooie::progress_cheats::set_flag(uint8_t* rdram, recomp_context* ctx, int32_t flag, bool value) {
    flag_set(rdram, ctx, flag, value);
}

int32_t tooie::progress_cheats::get_item(uint8_t* rdram, recomp_context* ctx, int32_t item) {
    recomp_context saved = *ctx;
    ctx->r4 = (uint64_t)(int64_t)item;
    func_800D1A04(rdram, ctx);
    const int32_t value = (int32_t)ctx->r2;
    *ctx = saved;
    return value;
}

void tooie::progress_cheats::set_item(uint8_t* rdram, recomp_context* ctx, int32_t item, int32_t value) {
    recomp_context saved = *ctx;
    ctx->r4 = (uint64_t)(int64_t)item;
    ctx->r5 = (uint64_t)(int64_t)value;
    ctx->r6 = 0; // no counter pop-up
    func_800D1864(rdram, ctx);
    *ctx = saved;
}

bool tooie::progress_cheats::play_sound(uint8_t* rdram, recomp_context* ctx, int32_t sound, float volume) {
    const uint32_t player = (uint32_t)MEM_W(0, (gpr)(int32_t)0x80135490); // player pointers, player 0 first
    if (player < 0x80000000u || player >= 0x81000000u) {
        return false;
    }
    recomp_context call = *ctx;
    call.r29 = (int32_t)(((uint32_t)ctx->r29 - 0x200) & ~0xFu);
    call.r4 = (int32_t)player;
    call.r5 = (uint64_t)(int64_t)sound;
    uint32_t bits;
    std::memcpy(&bits, &volume, sizeof(bits));
    call.r6 = (int32_t)bits;
    func_8009DE38(rdram, &call);
    return true;
}
