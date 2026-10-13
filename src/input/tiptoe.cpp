#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <variant>

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include "recompui/config.h"

#include "tooie_game.h"
#include "tooie_tiptoe.h"

namespace {
    using namespace std::chrono_literals;
    using Clock = std::chrono::steady_clock;

    constexpr uint16_t button_b = 0x4000;

    // The left stick's tilt while tiptoeing, as a fraction of the stick range. Measured headless
    // (tilt: state): under 0.20 stands, 0.20 creeps (31), 0.25 to 0.40 tiptoes (2), 0.45 to 0.50 walks (3),
    // 0.60 and up runs (4). The cap sits in the middle of the tiptoe band.
    constexpr float tiptoe_tilt = 0.35f;

    // A press shorter than this still reaches the game as B (a moment late).
    constexpr auto tap_time = 200ms;
    // How long the delayed B tap is shown to the game, enough for it to read it.
    constexpr auto pulse_time = 150ms;

    tooie::input::TiptoeButton cached_button = tooie::input::TiptoeButton::B;
    Clock::time_point cached_at{};

    tooie::input::TiptoeButton chosen_button(Clock::time_point now) {
        // The option is read a few times a second, not on every pad read.
        if (cached_at == Clock::time_point{} || now - cached_at > 250ms) {
            cached_at = now;
            try {
                cached_button = static_cast<tooie::input::TiptoeButton>(std::get<uint32_t>(
                    recompui::config::get_config(tooie::qol_tab_id).get_option_value(tooie::input::tiptoe_option)));
            } catch (...) {
                cached_button = tooie::input::TiptoeButton::B;
            }
        }
        return cached_button;
    }

    // Whether any connected game controller has its stick pressed in.
    bool stick_click_held(SDL_GameControllerButton which) {
        for (int i = 0; i < SDL_NumJoysticks(); i++) {
            if (!SDL_IsGameController(i)) {
                continue;
            }
            // Already open elsewhere: SDL hands back the same handle and counts the reference.
            SDL_GameController* pad = SDL_GameControllerOpen(i);
            if (pad == nullptr) {
                continue;
            }
            const bool down = SDL_GameControllerGetButton(pad, which) != 0;
            SDL_GameControllerClose(pad);
            if (down) {
                return true;
            }
        }
        return false;
    }

    bool was_held = false;
    Clock::time_point held_since{};
    Clock::time_point pulse_until{};
}

void tooie::input::apply_tiptoe(uint16_t* buttons, float* x, float* y) {
    const auto now = Clock::now();
    const TiptoeButton button = chosen_button(now);

    bool held = false;
    switch (button) {
    case TiptoeButton::B:
        held = (*buttons & button_b) != 0;
        break;
    case TiptoeButton::LeftStick:
        held = stick_click_held(SDL_CONTROLLER_BUTTON_LEFTSTICK);
        break;
    case TiptoeButton::RightStick:
        held = stick_click_held(SDL_CONTROLLER_BUTTON_RIGHTSTICK);
        break;
    case TiptoeButton::Off:
        break;
    }

    if (held && !was_held) {
        held_since = now;
    } else if (!held && was_held && button == TiptoeButton::B && now - held_since < tap_time) {
        // A tap: give B to the game now that it is over.
        pulse_until = now + pulse_time;
    }
    was_held = held;

    if (button == TiptoeButton::B) {
        if (held) {
            *buttons &= ~button_b;
        }
        if (now < pulse_until) {
            *buttons |= button_b;
        }
    }

    if (held) {
        const float magnitude = std::sqrt(*x * *x + *y * *y);
        if (magnitude > tiptoe_tilt) {
            const float scale = tiptoe_tilt / magnitude;
            *x *= scale;
            *y *= scale;
        }
    }
}
