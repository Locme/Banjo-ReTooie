// Back-Port: Get Jiggy animation (L, 2026-10-13: "BK jiggy dance").
//
// Tooie still carries Banjo-Kazooie's jig code (bsjig, the same as BK's bsjig.c): state 0x44 with
// animation 0x2E, 4.3 s, Banjo's fist-pump jig. Nothing in Tooie enters that state any more. A Jiggy
// is collected through player interrupt 0x35 (flag 0x1A in the interrupt handler func_80099B94), which
// starts state 0x34: the same bsjig file's second jig, animation 0x282 for 3.6 s with Kazooie out,
// under the black bars and the celebration camera. Its update leaves the state when the animation
// stops, so swapping that state's animation for BK's 0x2E at 4.3 s plays the old dance in Tooie's
// own sequence, with Tooie's jingle, camera and Jiggy count. Only the animation in the player's own
// ROM is used.
//
// Debug: TOOIE_JIGGY_DANCE=1 forces it on; TOOIE_JIGGY_DANCE_TEST=<ms> raises interrupt 0x35 that
// long after the game starts (the celebration without a Jiggy); TOOIE_JIGGY_DANCE_LOG=1 logs it.

#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <variant>

#include "recomp.h"
#include "funcs.h"
#include "recompui/config.h"

#include "tooie_jiggy_dance.h"

namespace {
    using Clock = std::chrono::steady_clock;

    // Player 0's PlayerState pointer (see src/gameplay/player_cheats.cpp).
    constexpr uint32_t player_table = 0x80135490;
    constexpr uint32_t state_offset = 0x120;   // PlayerState -> state block
    constexpr uint32_t state_current = 0x4;    // state block -> current state id

    constexpr uint32_t celebrate_state = 0x34; // Tooie's Jiggy pose (bsjig, animation 0x282)
    constexpr uint32_t celebrate_interrupt = 0x35;
    constexpr uint32_t bk_jig_anim = 0x2E;     // BK's jiggy jig (ASSET_2E_ANIM_BSJIG_JIGGY)
    constexpr uint32_t bk_jig_duration = 0x4089999A; // 4.3f, as BK's bsjig_jiggy_init sets it

    uint32_t rd_word(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<uint32_t*>(rdram + (addr - 0x80000000u));
    }

    bool valid_ptr(uint32_t p) {
        return p >= 0x80000000u && p < 0x81000000u;
    }

    bool log_on() {
        static const bool on = std::getenv("TOOIE_JIGGY_DANCE_LOG") != nullptr;
        return on;
    }

    bool chosen(Clock::time_point now) {
        static const bool forced = std::getenv("TOOIE_JIGGY_DANCE") != nullptr;
        static bool cached = false;
        static Clock::time_point cached_at{};
        if (forced) {
            return true;
        }
        // The option is read a few times a second, not every frame.
        if (cached_at == Clock::time_point{} || now - cached_at > std::chrono::milliseconds(250)) {
            cached_at = now;
            try {
                cached = std::get<bool>(recompui::config::get_general_config().get_option_value(tooie::jiggy_dance::option));
            } catch (...) {
                cached = false;
            }
        }
        return cached;
    }

    // A copy of the game's context with room below its stack, for calling game functions from the tick.
    recomp_context call_context(recomp_context* ctx, uint32_t player) {
        recomp_context call = *ctx;
        call.r29 = ctx->r29 - 0x100;
        call.r4 = (int32_t)player;
        return call;
    }

    void play_bk_jig(uint8_t* rdram, recomp_context* ctx, uint32_t player) {
        recomp_context call = call_context(ctx, player);
        baanim_getAnimCtrlPtr(rdram, &call);
        const int32_t anim_ctrl = (int32_t)call.r2;
        if (!valid_ptr((uint32_t)anim_ctrl)) {
            return;
        }
        // As bsjig_jiggy_init: reset, no blend, animation 0x2E for 4.3 s, played once.
        call.r4 = anim_ctrl;
        anctrl_reset(rdram, &call);
        call.r4 = anim_ctrl;
        call.r5 = 0;
        anctrl_setSmoothTransition(rdram, &call);
        call.r4 = anim_ctrl;
        call.r5 = bk_jig_anim;
        anctrl_setIndex(rdram, &call);
        call.r4 = anim_ctrl;
        call.r5 = (int32_t)bk_jig_duration;
        anctrl_setDuration(rdram, &call);
        call.r4 = anim_ctrl;
        call.r5 = 1;
        anctrl_setPlaybackType(rdram, &call);
        call.r4 = anim_ctrl;
        anctrl_start(rdram, &call);
    }

    uint32_t last_state = 0;
}

void tooie::jiggy_dance::tick(uint8_t* rdram, recomp_context* ctx) {
    static const Clock::time_point started = Clock::now();
    const auto now = Clock::now();
    const uint32_t player = rd_word(rdram, player_table);
    if (!valid_ptr(player)) {
        last_state = 0;
        return;
    }
    const uint32_t block = rd_word(rdram, player + state_offset);
    if (!valid_ptr(block)) {
        last_state = 0;
        return;
    }
    const uint32_t state = rd_word(rdram, block + state_current);

    static const long test_ms = [] {
        const char* v = std::getenv("TOOIE_JIGGY_DANCE_TEST");
        return v != nullptr ? std::atol(v) : -1L;
    }();
    static bool test_done = false;
    if (test_ms >= 0 && !test_done && now - started > std::chrono::milliseconds(test_ms)) {
        test_done = true;
        recomp_context call = call_context(ctx, player);
        call.r5 = celebrate_interrupt;
        func_8009E7C8(rdram, &call); // bs_checkInterrupt
        if (log_on()) {
            std::printf("[jiggy dance] raised interrupt 0x35 (result %d)\n", (int)call.r2);
            std::fflush(stdout);
        }
    }

    if (state == celebrate_state && last_state != celebrate_state && chosen(now)) {
        play_bk_jig(rdram, ctx, player);
        if (log_on()) {
            std::printf("[jiggy dance] Jiggy pose started (from state 0x%X): playing BK's jig\n", last_state);
            std::fflush(stdout);
        }
    }
    last_state = state;
}
