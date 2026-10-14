// Interpolation check (a debug aid for frame interpolation, handoff 4.15).
//
// F7 switches it on and off; a toast says which. While it is on,
// model_tagging.cpp tints a model red for about a third of a second when its
// blend between game frames looks wrong, and prints a line for it to the
// console (logs/console.log on Windows):
//   * jumped: it moved much further in one game frame than the frame before,
//     so the in-between frames smear it across the gap;
//   * bones not blended: some of its matrices could not be paired with last
//     frame's, so those parts move at the game's own rate.
// Only frame rates above Original blend, so it shows nothing at Original.
//
// Headless test hooks: TOOIE_INTERP_CHECK=1 starts with it on; TOOIE_BLEND_MODE=<0-4> picks the F8 blend mode.

#include <atomic>
#include <chrono>
#include <cstdlib>
#include <mutex>
#include <string>
#include <thread>

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include "tooie_interp_check.h"
#include "tooie_toast.h"

namespace {
    using namespace std::chrono_literals;

    std::once_flag started;
    std::atomic<bool> on{false};
    std::atomic<int> mode{0};
    constexpr int mode_count = 5;

    void worker() {
        bool was_down = false;
        bool mode_was_down = false;
        for (;;) {
            std::this_thread::sleep_for(10ms);
            const Uint8* keys = SDL_GetKeyboardState(nullptr);
            bool down = keys != nullptr && keys[SDL_SCANCODE_F7] != 0;
            if (down && !was_down) {
                bool now = !on.load();
                on = now;
                tooie::toast::show(now ? "Interpolation check on" : "Interpolation check off");
            }
            was_down = down;
            bool mode_down = keys != nullptr && keys[SDL_SCANCODE_F8] != 0;
            if (mode_down && !mode_was_down) {
                int now = (mode.load() + 1) % mode_count;
                mode = now;
                tooie::toast::show(std::string("Blend mode: ") + tooie::interp_check::blend_mode_name(now));
            }
            mode_was_down = mode_down;
        }
    }
}

void tooie::interp_check::start() {
    std::call_once(started, [] {
        if (const char* v = std::getenv("TOOIE_INTERP_CHECK"); v != nullptr && v[0] == '1') {
            on = true;
        }
        // Headless: TOOIE_BLEND_MODE=<0-4> starts in that blend mode.
        if (const char* v = std::getenv("TOOIE_BLEND_MODE"); v != nullptr) {
            mode = std::atoi(v) % mode_count;
        }
        std::thread(worker).detach();
    });
}

int tooie::interp_check::blend_mode() {
    return mode.load(std::memory_order_relaxed);
}

const char* tooie::interp_check::blend_mode_name(int m) {
    switch (m) {
        case 1: return "no tags (RT64 matches on its own)";
        case 2: return "tags, no vertex blending";
        case 3: return "camera untagged";
        case 4: return "models snap, camera blends";
        default: return "normal";
    }
}

bool tooie::interp_check::enabled() {
    return on.load(std::memory_order_relaxed);
}
