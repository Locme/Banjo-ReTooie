// Fine aim (handoff 4.57).
//
// In first person (C-up; player state 152, measured headless) the left stick turns
// the view. With Fine aim on (always, or while the Fine Aim key is held: Controls tab,
// Hotkeys; R by default, which still reaches the game) the view turns at 25%, 40% or
// 60% of the game's speed. Scaling the stick did not work: the game's turn speed
// barely depends on the tilt (headless, full tilt scaled to 0.67 still turned at 89%).
// So src/input/motion_aim.cpp takes back part of each frame's turn instead.

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

#include "recomp.h"
#include "recompinput/recompinput.h"
#include "recompinput/input_binding.h"
#include "recompinput/profiles.h"
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

    constexpr auto fine_aim_input = recompinput::GameInput::FINE_AIM;
    
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

    // Whether any keyboard key or controller button bound to Fine Aim is held.
    bool key_down() {
        if (recompinput::binding::is_binding()) {
            return false;
        }
        bool down = false;
        for (int profile : { recompinput::profiles::get_sp_keyboard_profile_index(), recompinput::profiles::get_sp_controller_profile_index() }) {
            if (profile < 0) {
                continue;
            }
            for (size_t b = 0; b < recompinput::num_bindings_per_input; b++) {
                down = down || recompinput::get_input_digital(0, recompinput::profiles::get_input_binding(profile, fine_aim_input, b));
            }
        }
        return down;
    }

    uint32_t rd_word(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<uint32_t*>(rdram + (addr - 0x80000000u));
    }

    bool valid_ptr(uint32_t p) {
        return p >= 0x80000000u && p < 0x80800000u;
    }
}

void tooie::fine_aim::register_input() {
    recompinput::set_game_input_name(fine_aim_input, "Fine Aim");
    recompinput::set_game_input_description(fine_aim_input,
        "Hold to turn the first-person view (C-up) slower, when QOL > Fine aim is set to Hold key.");
    recompinput::set_default_mapping_for_keyboard(fine_aim_input, { recompinput::InputField::keyboard(SDL_SCANCODE_R) });
    recompinput::set_default_mapping_for_controller(fine_aim_input, { recompinput::InputField::controller_analog(SDL_CONTROLLER_AXIS_TRIGGERRIGHT, true) });
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

float tooie::fine_aim::view_scale() {
    if (player_state.load() != state_first_person) {
        return 1.0f;
    }
    read_options(Clock::now());
    if (cached_mode == Mode::Always || (cached_mode == Mode::HoldKey && key_down())) {
        return cached_scale;
    }
    return 1.0f;
}
