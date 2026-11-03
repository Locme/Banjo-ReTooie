// Fine aim (handoff 4.57).
//
// In first person (C-up; player state 152, measured headless) the left stick turns
// the view. With Fine aim on (always, or while the Fine Aim key is held: Controls tab,
// Hotkeys; R by default, which still reaches the game) the view turns at 25%, 40% or
// 60% of the game's speed. Scaling the stick did not work: the game's turn speed
// barely depends on the tilt (headless, full tilt scaled to 0.67 still turned at 89%).
// So src/input/motion_aim.cpp takes back part of each frame's turn instead.
//
// State 152 is not first person only: it is also the game walking Banjo itself (door walk-ins, loading
// zones, Mumbo, Heggy, Master Jiggywiggy and King Jingaling calling him over and the puzzle that follows,
// Dragunda's hold). Mouse aim in those moved the game's scripted cameras (Jiggywiggy's jigsaw puzzle). So
// state 152 counts as first person only when C-up was held just before it began; game_has_player() is
// true in 152 otherwise and in the other states where the game has Banjo, for the free camera.

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
#include "tooie_hotkeys.h"
#include "tooie_rdram.h"

namespace {
    using namespace std::chrono_literals;
    using Clock = std::chrono::steady_clock;

    // Player 0's PlayerState pointer (see src/gameplay/player_cheats.cpp).
    constexpr uint32_t player_table = 0x80135490;
    constexpr uint32_t state_offset = 0x120;   // PlayerState -> state block
    constexpr uint32_t state_current = 0x4;    // state block -> current state id
    constexpr uint32_t state_first_person = 152;
    // C-up held this long before state 152 began makes it first person.
    constexpr auto c_up_window = 1000ms;
    constexpr uint16_t button_c_up = 0x0008;

    constexpr auto fine_aim_input = recompinput::GameInput::FINE_AIM;
    
    std::atomic<uint32_t> player_state{0};
    // Whether this stretch of state 152 is first person (game thread, read by the pad thread's helpers).
    std::atomic<bool> first_person{false};
    // When C-up was last seen held on controller 1 (note_buttons, pad thread), in steady clock ticks.
    std::atomic<int64_t> c_up_at{0};

    // Player states where the game has Banjo, not the player (as src/game/console.cpp's locked_state): none (0),
    // 152 (see the top), the locked states for signposts, talking and cutscenes, and dead (0x41).
    bool locked_state(uint32_t s) {
        return s == 0 || s == state_first_person || s == 0x97 || s == 0x93 || s == 0x92 || s == 0x5D || s == 0x75 ||
            s == 0x9A || s == 0x41;
    }

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
        return tooie::hotkeys::down(fine_aim_input);
    }

    using tooie::rdram::read_word;
    using tooie::rdram::valid_ptr;

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
    uint32_t player = read_word(rdram, player_table);
    uint32_t state = valid_ptr(player) ? read_word(rdram, player + state_offset) : 0;
    const uint32_t current = valid_ptr(state) ? read_word(rdram, state + state_current) : 0;
    const uint32_t before = player_state.exchange(current);
    if (current != state_first_person) {
        first_person = false;
    } else if (before != state_first_person) {
        // Just entered: first person if the player asked for it with C-up, else the game is walking Banjo.
        const int64_t at = c_up_at.load();
        first_person = at != 0 && Clock::now().time_since_epoch().count() - at <=
            std::chrono::duration_cast<Clock::duration>(c_up_window).count();
    }
}

void tooie::fine_aim::note_buttons(uint16_t buttons) {
    if ((buttons & button_c_up) != 0) {
        c_up_at = Clock::now().time_since_epoch().count();
    }
}

bool tooie::fine_aim::in_first_person() {
    return player_state.load() == state_first_person && first_person.load();
}

bool tooie::fine_aim::game_has_player() {
    return locked_state(player_state.load()) && !in_first_person();
}

float tooie::fine_aim::view_scale() {
    if (!in_first_person()) {
        return 1.0f;
    }
    read_options(Clock::now());
    if (cached_mode == Mode::Always || (cached_mode == Mode::HoldKey && key_down())) {
        return cached_scale;
    }
    return 1.0f;
}
