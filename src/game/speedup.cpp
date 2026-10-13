#include <atomic>
#include <chrono>
#include <cstdlib>
#include <cstdio>
#include <mutex>
#include <string>
#include <thread>
#include <variant>

#include "SDL2/SDL.h"

#include "recompui/config.h"
#include "ultramodern/ultramodern.hpp"

#include "tooie_speedup.h"
#include "tooie_toast.h"

extern uint64_t total_vis;

namespace {
    using namespace std::chrono_literals;

    constexpr auto poll_interval = 10ms;

    std::once_flag started;

    template <typename T>
    T option(const std::string& name, T fallback) {
        try {
            return std::get<T>(recompui::config::get_general_config().get_option_value(name));
        } catch (...) {
            return fallback;
        }
    }

    bool key_down() {
        const Uint8* keys = SDL_GetKeyboardState(nullptr);
        return keys != nullptr && keys[SDL_SCANCODE_F2] != 0;
    }

    // Test hook for headless runs, where no key can be pressed: TOOIE_SPEEDUP_HOLD=<from ms>:<to ms>
    // acts as F2 being held between those two times after the game started.
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

void tooie::speedup::start() {
    std::call_once(started, [] {
        std::thread(worker).detach();
    });
}
