#include <atomic>
#include <cstdio>
#include <mutex>

#include "ultramodern/ultramodern.hpp"

#include "tooie_app_state.h"
#include "tooie_watchdog.h"

namespace RT64 {
    // rt64-ext/src/hle/rt64_present_queue_ext.cpp.
    void SetWindowSurfaceAvailable(bool available, uint32_t timeoutMs);
}

namespace {
    std::mutex state_mutex;
    bool background = false;
}

void tooie::app_state::enter_background() {
    std::lock_guard lock{ state_mutex };
    if (background) {
        return;
    }
    background = true;
    ultramodern::set_suspended(true);
    tooie::watchdog::set_suspended(true);
    // The saving thread writes each change a few ms after it, so this is only for a change made just now.
    ultramodern::flush_save_file();
    std::printf("[app] In the background: the game is stopped\n");
    std::fflush(nullptr);
}

void tooie::app_state::enter_foreground() {
    std::lock_guard lock{ state_mutex };
    if (!background) {
        return;
    }
    background = false;
    tooie::watchdog::set_suspended(false);
    ultramodern::set_suspended(false);
    std::printf("[app] Back in the foreground: the game goes on\n");
    std::fflush(nullptr);
}

bool tooie::app_state::in_background() {
    std::lock_guard lock{ state_mutex };
    return background;
}

void tooie::app_state::set_window_surface(bool available) {
    // Android also reports the surface as ready on every size change; only a change is logged.
    static std::atomic<bool> surface_available{ true };
    if (surface_available.exchange(available) != available) {
        std::printf("[app] The window %s\n", available ? "has a surface again" : "is losing its surface");
    }
    RT64::SetWindowSurfaceAvailable(available, 2000);
}
