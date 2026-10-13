#include <atomic>
#include <chrono>
#include <cstdlib>
#include <cstdio>
#include <mutex>
#include <string>
#include <thread>
#include <variant>
#include <vector>

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include "recompui/config.h"
#include "recompinput/recompinput.h"
#include "recompinput/input_binding.h"
#include "recompinput/profiles.h"
#include "ultramodern/ultramodern.hpp"

#include "tooie_cheats.h"
#include "tooie_speedup.h"
#include "tooie_toast.h"

extern uint64_t total_vis;

namespace {
    using namespace std::chrono_literals;

    constexpr auto poll_interval = 10ms;

    std::once_flag started;

    constexpr auto speed_up_input = recompinput::GameInput::SPEED_UP;

    template <typename T>
    T option(const std::string& name, T fallback) {
        try {
            return std::get<T>(recompui::config::get_config("cheats").get_option_value(name));
        } catch (...) {
            return fallback;
        }
    }

    // Whether any keyboard key or controller button bound to Speed-Up (Controls tab, Cheats section) is held.
    bool key_down() {
        // Pressing the key to bind it in the Controls tab should not switch the speed-up on.
        if (recompinput::binding::is_binding()) {
            return false;
        }
        bool down = false;
        for (int profile : { recompinput::profiles::get_sp_keyboard_profile_index(), recompinput::profiles::get_sp_controller_profile_index() }) {
            if (profile < 0) {
                continue;
            }
            for (size_t b = 0; b < recompinput::num_bindings_per_input; b++) {
                down = down || recompinput::get_input_digital(0, recompinput::profiles::get_input_binding(profile, speed_up_input, b));
            }
        }
        return down;
    }

    // Test hook for headless runs, where no key can be pressed: TOOIE_SPEEDUP_HOLD=<from ms>:<to ms>
    // acts as the Speed-Up key being held between those two times after the game started.
    struct TestHold {
        bool active = false;
        long from = 0;
        long to = 0;
    };

    TestHold parse_test_hold() {
        TestHold t;
        if (const char* v = std::getenv("TOOIE_SPEEDUP_HOLD")) {
            t.active = std::sscanf(v, "%ld:%ld", &t.from, &t.to) == 2;
        }
        return t;
    }

    void set_speed(uint32_t factor, bool announce) {
        ultramodern::set_speed_multiplier(factor);
        if (announce) {
            tooie::toast::show(factor > 1 ? "Speed-up x" + std::to_string(factor) : "Speed-up off");
        }
    }

    void worker() {
        TestHold test = parse_test_hold();
        auto begin = std::chrono::steady_clock::now();
        bool on = false;
        bool was_down = false;
        auto last_log = begin;
        uint64_t last_vis = total_vis;
        for (;;) {
            std::this_thread::sleep_for(poll_interval);

            // With the test hook on, log the VI rate once a second so a headless run can check the speed.
            if (test.active && std::chrono::steady_clock::now() - last_log >= 1s) {
                std::printf("speedup: x%u, %llu VIs in the last second\n", ultramodern::get_speed_multiplier(), (unsigned long long)(total_vis - last_vis));
                std::fflush(stdout);
                last_vis = total_vis;
                last_log = std::chrono::steady_clock::now();
            }

            bool down = key_down();
            if (test.active) {
                long ms = (long)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - begin).count();
                down = down || (ms >= test.from && ms < test.to);
            }

            // Off unless "Enable cheats" and "Speed-up" are both on. Turning either off while the
            // speed-up is running puts the game back to normal speed.
            const bool allowed = tooie::cheats::enabled() && option<bool>(tooie::speedup::enabled_option, true);
            if (!allowed) {
                down = false;
                if (on) {
                    on = false;
                    set_speed(1, true);
                }
                was_down = false;
                continue;
            }

            bool toggle = option<bool>(tooie::speedup::toggle_option, false);
            uint32_t factor = (uint32_t)option<double>(tooie::speedup::factor_option, 3.0);
            if (factor < 2) {
                factor = 2;
            } else if (factor > 4) {
                factor = 4;
            }

            bool want = on;
            if (toggle) {
                if (down && !was_down) {
                    want = !on;
                }
            } else {
                want = down;
            }
            was_down = down;

            if (want != on) {
                on = want;
                set_speed(on ? factor : 1, true);
            } else if (on && ultramodern::get_speed_multiplier() != factor) {
                // The factor option changed while the speed-up was running.
                set_speed(factor, false);
            }
        }
    }
}

void tooie::speedup::register_input() {
    recompinput::set_game_input_name(speed_up_input, "Speed-Up");
    // Listed in the Controls tab under its own "Cheats" heading, apart from the other hotkeys.
    recompinput::set_game_input_section(speed_up_input, "Cheats");
    recompinput::set_game_input_description(speed_up_input,
        "Runs the game faster while held (or switches it on and off, with Speed-up toggle on). "
        "Works only while Enable cheats and Speed-up are on in the Cheats tab.");
    recompinput::set_default_mapping_for_keyboard(speed_up_input, { recompinput::InputField::keyboard(SDL_SCANCODE_F2) });
    recompinput::set_default_mapping_for_controller(speed_up_input, {});
}

void tooie::speedup::add_options(recomp::config::Config& cheats, const std::string& master_option) {
    cheats.add_bool_option(enabled_option, "Speed-up",
        "Lets the Speed-Up key (F2 unless changed in the Cheats section of the Controls tab) run the game faster. Off means the key does nothing.",
        true);
    cheats.add_number_option(factor_option, "Speed-up factor",
        "How much faster the game runs while the speed-up is active.",
        2, 4, 1, 0, false, 3);
    cheats.add_bool_option(toggle_option, "Speed-up toggle",
        "Press the Speed-Up key to switch the speed-up on and off instead of holding it.",
        false);
    for (const std::string* id : { &enabled_option, &factor_option, &toggle_option }) {
        cheats.add_option_hidden_dependency(*id, master_option, false);
    }
    // The factor and toggle rows grey out while the speed-up itself is off.
    std::vector<recomp::config::ConfigValueVariant> off{ false };
    cheats.add_option_disable_dependency(factor_option, enabled_option, off);
    cheats.add_option_disable_dependency(toggle_option, enabled_option, off);
}

void tooie::speedup::start() {
    std::call_once(started, [] {
        std::thread(worker).detach();
    });
}
