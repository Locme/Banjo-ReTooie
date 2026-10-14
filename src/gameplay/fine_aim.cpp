// Fine aim (handoff 4.57).
//
// In first person (C-up; player state 152, measured headless) the left stick moves
// the aim and turns the view. The game ignores tilts under about 0.45 of the stick's
// range (headless: 0.45 does nothing, 0.5 just moves the aim, 0.6 turns about 40
// degrees in 2 s and 1.0 over 90). With Fine aim on, the tilt past that dead zone is
// scaled before the game reads it, so the speed drops evenly instead of the stick
// going dead: always, or while R is held (R still reaches the game). Speeds are 25%,
// 40% and 60%.

#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <variant>

#include "recomp.h"
#include "recompui/config.h"

#include "tooie_game.h"
#include "tooie_fine_aim.h"

namespace {
    using namespace std::chrono_literals;
    using Clock = std::chrono::steady_clock;

    // Player 0's PlayerState pointer (see src/gameplay/player_cheats.cpp).
    constexpr uint32_t player_table = 0x80135490;
    constexpr uint32_t state_offset = 0x120;   // PlayerState -> state block
    constexpr uint32_t state_current = 0x4;    // state block -> current state id
    constexpr uint32_t state_first_person = 152;

    constexpr uint16_t button_r = 0x0010;
    constexpr float dead_zone = 0.45f;

    std::atomic<uint32_t> player_state{0};

    tooie::fine_aim::Mode cached_mode = tooie::fine_aim::Mode::Off;
    float cached_scale = 0.4f;
    Clock::time_point cached_at{};

    void read_options(Clock::time_point now) {
        // The options are read a few times a second, not on every pad read.
        if (cached_at != Clock::time_point{} && now - cached_at <= 250ms) {
            return;
        }
        cached_at = now;
        try {
            auto& qol = recompui::config::get_config(tooie::qol_tab_id);
            cached_mode = static_cast<tooie::fine_aim::Mode>(std::get<uint32_t>(qol.get_option_value(tooie::fine_aim::mode_option)));
            switch (static_cast<tooie::fine_aim::Speed>(std::get<uint32_t>(qol.get_option_value(tooie::fine_aim::speed_option)))) {
            case tooie::fine_aim::Speed::Slow: cached_scale = 0.25f; break;
            case tooie::fine_aim::Speed::Fast: cached_scale = 0.6f; break;
            default: cached_scale = 0.4f; break;
            }
        } catch (...) {
            cached_mode = tooie::fine_aim::Mode::Off;
        }
    }

    uint32_t rd_word(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<uint32_t*>(rdram + (addr - 0x80000000u));
    }

    bool valid_ptr(uint32_t p) {
        return p >= 0x80000000u && p < 0x80800000u;
    }
}

void tooie::fine_aim::tick(uint8_t* rdram, recomp_context* ctx) {
    (void)ctx;
    uint32_t player = rd_word(rdram, player_table);
    uint32_t state = valid_ptr(player) ? rd_word(rdram, player + state_offset) : 0;
    player_state = valid_ptr(state) ? rd_word(rdram, state + state_current) : 0;
}

bool tooie::fine_aim::in_first_person() {
    return player_state.load() == state_first_person;
}

void tooie::fine_aim::apply(uint16_t buttons, float* x, float* y) {
    if (player_state.load() != state_first_person) {
        return;
    }
    read_options(Clock::now());
    if (cached_mode == Mode::Always || (cached_mode == Mode::HoldR && (buttons & button_r) != 0)) {
        const float magnitude = std::sqrt(*x * *x + *y * *y);
        if (magnitude > dead_zone) {
            const float scale = (dead_zone + (magnitude - dead_zone) * cached_scale) / magnitude;
            *x *= scale;
            *y *= scale;
        }
    }
}
