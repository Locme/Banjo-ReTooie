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
// Headless test hook: TOOIE_INTERP_CHECK=1 starts with it on.

#include <atomic>
#include <chrono>
#include <cstdlib>
#include <mutex>
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

    void worker() {
        bool was_down = false;
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
        }
    }
}

void tooie::interp_check::start() {
    std::call_once(started, [] {
        if (const char* v = std::getenv("TOOIE_INTERP_CHECK"); v != nullptr && v[0] == '1') {
            on = true;
        }
        std::thread(worker).detach();
    });
}

bool tooie::interp_check::enabled() {
    return on.load(std::memory_order_relaxed);
}
