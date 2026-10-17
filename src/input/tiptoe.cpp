#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include "recompinput/recompinput.h"
#include "recompinput/input_binding.h"
#include "recompinput/profiles.h"

#include "tooie_tiptoe.h"
#include "tooie_hotkeys.h"

namespace {
    using namespace std::chrono_literals;
    using Clock = std::chrono::steady_clock;

    // The left stick's tilt while tiptoeing, as a fraction of the stick range. Measured headless
    // (tilt: state): under 0.20 stands, 0.20 creeps (31), 0.25 to 0.40 tiptoes (2), 0.45 to 0.50 walks (3),
    // 0.60 and up runs (4). The cap sits in the middle of the tiptoe band.
    constexpr float tiptoe_tilt = 0.35f;

    constexpr auto tiptoe_input = recompinput::GameInput::TIPTOE;

    // Whether any keyboard key or controller button bound to Tiptoe (Controls tab, Hotkeys) is held.
    bool key_down() {
        return tooie::hotkeys::down(tiptoe_input);
    }

    // Test hook for headless runs, where no key can be pressed: TOOIE_TIPTOE_HOLD=<from ms>:<to ms>
    // acts as the Tiptoe key being held between those two times after the first pad read.
    struct TestHold {
        bool active = false;
        long from = 0;
        long to = 0;
        Clock::time_point begin = Clock::now();
    };

    TestHold& test_hold() {
        static TestHold t = [] {
            TestHold h;
            if (const char* v = std::getenv("TOOIE_TIPTOE_HOLD")) {
                h.active = std::sscanf(v, "%ld:%ld", &h.from, &h.to) == 2;
            }
            return h;
        }();
        return t;
    }
}

void tooie::input::register_input() {
    recompinput::set_game_input_section(tiptoe_input, "Movement");
    recompinput::set_game_input_name(tiptoe_input, "Tiptoe");
    recompinput::set_game_input_description(tiptoe_input,
        "Hold to tiptoe at any left stick tilt, so Banjo never creeps or runs by accident.");
    recompinput::set_default_mapping_for_keyboard(tiptoe_input, {});
    recompinput::set_default_mapping_for_controller(tiptoe_input, { recompinput::InputField::controller_digital(SDL_CONTROLLER_BUTTON_LEFTSTICK) });
}

void tooie::input::apply_tiptoe(uint16_t*, float* x, float* y) {
    bool held = key_down();
    TestHold& test = test_hold();
    if (test.active) {
        const long ms = (long)std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - test.begin).count();
        held = held || (ms >= test.from && ms < test.to);
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
