// Canary Mary rubber banding (handoff 4.53).
//
// Each frame of a race, Mary's speed rule runs: func_80803218_chhandcart in the
// Glitter Gulch Mine cart race and func_80802724_chclockworkmouse in Cloud
// Cuckooland. a0 is Mary, a1 the player. It compares how far round the course
// each is (func_80105AE8, 0 to 1) and moves Mary's speed (f32 at Mary + 0x24)
// towards a target at her acceleration times the frame time (func_800D8FF8):
//
//   race                 normal pace  you ahead  you behind   accel/s
//   mine cart, race 1        75          85         65          20
//   mine cart, race 2        80          90         70          30
//   clouds, race 1          165         180        140          45
//   clouds, race 2          185         200        170          65
//
// "You ahead" is the rubber band: once you lead by 2% (0.5% in the second cloud
// race) she speeds up past her normal pace. If she gets 10% ahead the race is
// lost, and the game's own code handles that. Bit 19 of Mary + 0x64 marks the
// second (Cheato page) race.
//
// A hook at the entry of both rules calls tooie_canary_mary_rule. Original lets
// the game's rule run. Fair runs the same rule without the "you ahead" catch-up.
// Easy is Fair with her normal pace at 85%.

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <variant>

#include "recomp.h"
#include "funcs.h"
#include "recompui/config.h"

#include "tooie_game.h"
#include "tooie_hooks.h"
#include "tooie_canary_mary.h"

namespace {
    struct RaceRule {
        float pace[2];
        float slow_down[2];   // how far under her pace she drops while you are behind
        float accel[2];
        float behind[2];      // how far behind (in course progress) counts as behind
        float lost;           // Mary this far ahead ends the race
    };

    constexpr RaceRule mine_cart = { { 75.0f, 80.0f }, { 10.0f, 10.0f }, { 20.0f, 30.0f },
                                     { 655 / 65536.0f, 1310 / 65536.0f }, 6553 / 65536.0f };
    constexpr RaceRule clouds = { { 165.0f, 185.0f }, { 25.0f, 15.0f }, { 45.0f, 65.0f },
                                  { 0.009994507f, 0.004989624f }, 0.099990845f };

    tooie::canary_mary::Mode mode() {
        try {
            return static_cast<tooie::canary_mary::Mode>(std::get<uint32_t>(
                recompui::config::get_config(tooie::qol_tab_id).get_option_value(tooie::canary_mary::mode_option)));
        } catch (...) {
            return tooie::canary_mary::Mode::Fair;
        }
    }

    uint32_t rd_word(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<uint32_t*>(rdram + (addr - 0x80000000u));
    }

    float rd_float(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<float*>(rdram + (addr - 0x80000000u));
    }

    void wr_float(uint8_t* rdram, uint32_t addr, float value) {
        *reinterpret_cast<float*>(rdram + (addr - 0x80000000u)) = value;
    }

    // How far round the course an actor is, 0 to 1.
    float course_progress(uint8_t* rdram, recomp_context* ctx, uint32_t actor) {
        recomp_context call = *ctx;
        call.r4 = (int32_t)actor;
        func_80105AE8(rdram, &call);
        return call.f0.fl;
    }

    float frame_time(uint8_t* rdram, recomp_context* ctx) {
        recomp_context call = *ctx;
        func_800D8FF8(rdram, &call);
        return call.f0.fl;
    }
}

extern "C" int tooie_canary_mary_rule(uint8_t* rdram, recomp_context* ctx, int race) {
    using tooie::canary_mary::Mode;
    const Mode chosen = mode();
    if (chosen == Mode::Original) {
        return 0;
    }

    const RaceRule& rule = (race == 0) ? mine_cart : clouds;
    const uint32_t mary = (uint32_t)ctx->r4;
    const uint32_t player = (uint32_t)ctx->r5;

    const float player_progress = (rd_word(rdram, player + 0x7C) & 0xFFF) != 0 ? course_progress(rdram, ctx, player) : 1.0f;
    const float mary_progress = course_progress(rdram, ctx, mary);
    if (player_progress <= mary_progress - rule.lost) {
        // The race is lost: the game's rule ends it.
        return 0;
    }

    const int second = (rd_word(rdram, mary + 0x64) >> 19) & 1;
    const float pace = rule.pace[second] * (chosen == Mode::Easy ? 0.85f : 1.0f);
    const float step = rule.accel[second] * frame_time(rdram, ctx);
    float speed = rd_float(rdram, mary + 0x24);

    if (player_progress <= mary_progress - rule.behind[second]) {
        // You are behind: she eases off, as in the original.
        if (speed > pace - rule.slow_down[second]) {
            speed -= step;
        }
    } else if (speed < pace) {
        speed = std::min(speed + step, pace);
    } else if (speed > pace) {
        // Never past her normal pace (also brings her down after a switch from Original).
        speed = std::max(speed - step, pace);
    }
    wr_float(rdram, mary + 0x24, speed);

    static const bool log = std::getenv("TOOIE_MARY_LOG") != nullptr;
    if (log) {
        static int frames = 0;
        if (++frames % 15 == 0) {
            std::printf("[canary mary] race %d%s you %.3f mary %.3f speed %.1f\n", race, second ? " (2nd)" : "", player_progress, mary_progress, speed);
            std::fflush(stdout);
        }
    }
    return 1;
}
