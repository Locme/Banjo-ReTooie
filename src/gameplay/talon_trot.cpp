#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
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
#include "tooie_hotkeys.h"
#include "tooie_talon_trot.h"
#include "tooie_rdram.h"

namespace {
    using namespace std::chrono_literals;
    using Clock = std::chrono::steady_clock;

    // Player 0's PlayerState pointer (see src/gameplay/player_cheats.cpp).
    constexpr uint32_t player_table = 0x80135490;
    constexpr uint32_t state_offset = 0x120;   // PlayerState -> state block
    constexpr uint32_t state_current = 0x4;    // state block -> current state id

    constexpr uint16_t button_z = 0x2000;
    constexpr uint16_t button_cl = 0x0002;

    // On N64 the trot starts with C-left while Z is held (bainput_should_trot) and lasts while Z is held.
    // State ids measured headless: 7 is the crouch Z gives on its own, 23 the trot ending after Z is let go.
    bool is_trot_state(uint32_t state) {
        switch (state) {
        case 20:  // trotting in place
        case 21:  // trot turning or landing
        case 22:  // trotting
        case 8:   // trot jump
        case 113: // falling off a ledge while trotting
            return true;
        default:
            return false;
        }
    }

    // A state outside the trot for this long ends the toggle (a swim, a hit, a transformation).
    constexpr auto leave_time = 100ms;

    constexpr auto trot_input = recompinput::GameInput::TALON_TROT;
    // The Talon Trot control pushes Z + C-left into the pad this long, enough for the game to start the trot.
    constexpr auto start_hold = 150ms;
    bool chord_prev = false;
    Clock::time_point start_until{};

    // A Z press ends the toggle after this delay, unless the control (LT + RT) completes first: the first
    // trigger of the pair is a Z press too.
    constexpr auto z_end_delay = 80ms;
    Clock::time_point z_end_at{};

    std::atomic<uint32_t> player_state{0};

    tooie::talon_trot::Mode cached_mode = tooie::talon_trot::Mode::Toggle;
    Clock::time_point cached_at{};

    tooie::talon_trot::Mode chosen_mode(Clock::time_point now) {
        // The option is read a few times a second, not on every pad read.
        if (cached_at == Clock::time_point{} || now - cached_at > 250ms) {
            cached_at = now;
            try {
                cached_mode = static_cast<tooie::talon_trot::Mode>(std::get<uint32_t>(
                    recompui::config::get_config(tooie::qol_tab_id).get_option_value(tooie::talon_trot::mode_option)));
            } catch (...) {
                cached_mode = tooie::talon_trot::Mode::Toggle;
            }
        }
        return cached_mode;
    }

    using tooie::rdram::read_word;
    using tooie::rdram::valid_ptr;

    bool latched = false;
    // Z and C-left as the player holds them, to see fresh presses.
    uint16_t prev_raw = 0;
    // The Z held to start the trot has to be let go before a Z press can end it.
    bool z_released = false;
    bool was_trotting = false;
    Clock::time_point left_trot_at{};

    void log_change(const char* what, uint32_t state) {
        static const bool log = std::getenv("TOOIE_TROT_LOG") != nullptr;
        if (log) {
            std::printf("[talon trot] %s (state %u)\n", what, state);
            std::fflush(stdout);
        }
    }
}

void tooie::talon_trot::register_input() {
    recompinput::set_game_input_section(trot_input, "Movement");
    recompinput::set_game_input_name(trot_input, "Talon Trot");
    recompinput::set_game_input_description(trot_input,
        "Starts Kazooie's Talon Trot where Banjo stands (the same as Z + C-left). On a controller, hold LT and RT together. In Toggle mode (QOL > Talon Trot) the trot keeps going after you let go, until you press it again. In Hold mode the trot lasts while either trigger is held.");
    recompinput::set_default_mapping_for_keyboard(trot_input, {});
    recompinput::InputField chord = recompinput::InputField::controller_analog(SDL_CONTROLLER_AXIS_TRIGGERRIGHT, true);
    const recompinput::InputField lt = recompinput::InputField::controller_analog(SDL_CONTROLLER_AXIS_TRIGGERLEFT, true);
    chord.modifier_type = lt.input_type;
    chord.modifier_id = lt.input_id;
    recompinput::set_default_mapping_for_controller(trot_input, { chord });
}

void tooie::talon_trot::tick(uint8_t* rdram, recomp_context* ctx) {
    (void)ctx;
    uint32_t player = read_word(rdram, player_table);
    uint32_t state = valid_ptr(player) ? read_word(rdram, player + state_offset) : 0;
    player_state = valid_ptr(state) ? read_word(rdram, state + state_current) : 0;
}

void tooie::talon_trot::apply(uint16_t* buttons) {
    const auto now = Clock::now();
    const uint32_t state = player_state.load();
    const bool trotting = is_trot_state(state);
    const uint16_t raw = *buttons & (button_z | button_cl);
    const uint16_t pressed = raw & ~prev_raw;
    prev_raw = raw;

    // The control (LT + RT by default) as a fresh press.
    const bool chord = tooie::hotkeys::down(trot_input);
    const bool chord_pressed = chord && !chord_prev;
    chord_prev = chord;

    if (chord_pressed && !(latched && trotting)) {
        // Start the trot as Z + C-left would.
        start_until = now + start_hold;
        log_change("start (control)", state);
    }
    if (now < start_until) {
        *buttons |= button_z | button_cl;
    }

    if (chosen_mode(now) != Mode::Toggle) {
        latched = false;
        z_end_at = Clock::time_point{};
        was_trotting = trotting;
        return;
    }

    if (trotting && !was_trotting && !latched) {
        latched = true;
        z_released = (raw & button_z) == 0;
        log_change("on", state);
    }
    if (trotting) {
        left_trot_at = now;
    }
    was_trotting = trotting;

    if (!latched) {
        return;
    }
    if ((raw & button_z) == 0) {
        z_released = true;
    }
    if ((pressed & button_z) && z_released && z_end_at == Clock::time_point{}) {
        z_end_at = now + z_end_delay;
    }
    const bool z_ends = z_end_at != Clock::time_point{} && now >= z_end_at;
    if (chord_pressed || ((pressed & button_cl) && now >= start_until) || z_ends) {
        start_until = Clock::time_point{};
        z_end_at = Clock::time_point{};
        // Ended by the player: hand Z back, so letting go of it ends the trot as usual.
        latched = false;
        log_change("off (button)", state);
        return;
    }
    if (!trotting && now - left_trot_at > leave_time) {
        latched = false;
        z_end_at = Clock::time_point{};
        log_change("off (left the trot)", state);
        return;
    }
    *buttons |= button_z;
}
