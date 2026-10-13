#include <array>
#include <cstdint>
#include <cstdio>
#include <cstdlib>

#include "recomp.h"
#include "funcs.h"

#include "tooie_cheats.h"
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

    // Move n is learned when game flag 237 + n is set (0xED = beak barge), for the 60 moves 237..296.
    constexpr int32_t first_move_flag = 237;
    constexpr int32_t last_move_flag = 296;

    // Frames between checks. A cheat only needs to take hold within a fraction of a second.
    constexpr int check_interval = 10;

    std::array<bool, cheato_count> set_by_us{};
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

    // Headless test aid: once a second, print each Cheato flag as the game's own getter reads it.
    static const bool log = std::getenv("TOOIE_PLAYER_LOG") != nullptr;
    static int log_counter = 0;
    if (log && ++log_counter >= 6) {
        log_counter = 0;
        std::printf("[flags]");
        for (size_t i = 0; i < cheato_count; i++) {
            std::printf(" %d", flag_get(rdram, ctx, cheato_list[i].flag) ? 1 : 0);
        }
        std::printf("\n");
        std::fflush(stdout);
    }
}

// Hooks on the flag getter (see banjotooie.us.toml): the entry notes which flag is asked about, and the
// return reports the moves as learned while Unlock all moves is on. The save is never touched.
extern "C" void tooie_flag_get_enter(uint8_t* rdram, recomp_context* ctx) {
    pending_flag = (int32_t)ctx->r4;
}

extern "C" void tooie_flag_get_leave(uint8_t* rdram, recomp_context* ctx) {
    if (pending_flag >= first_move_flag && pending_flag <= last_move_flag && tooie::cheats::is_on("cheat_all_moves")) {
        ctx->r2 = 1;
    }
}
