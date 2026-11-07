#ifndef __TOOIE_WATCHDOG_H__
#define __TOOIE_WATCHDOG_H__

#include <cstdint>
#include <memory>

#include "ultramodern/renderer_context.hpp"

// Hang watchdog (src/debug/watchdog.cpp). It never stops or alters the game: it only writes to
// logs/hangs.log (and, for a long hang on Windows, logs/hang_<time>.dmp) when the game stops sending
// frames, the screen stops being presented, or the window stops handling events.
namespace tooie::watchdog {
    // Starts the watchdog thread (safe to call more than once). Each watched part arms itself at
    // its first sign of life, so nothing is reported before it has started.
    // rdram goes into the hang dump.
    void start(uint8_t* rdram);

    // Start-up timing for the console log: "[startup] 12.3 s <what>", seconds since the first call (main(), with nullptr: starts the clock only).
    void startup_mark(const char* what);

    // Called by the main thread's event loop each time round (update_gfx in main.cpp).
    void note_window_update();
    // Called on the game thread each controller read; only used by TOOIE_TEST_HANG=game:...
    void note_game_input();
    // While the app is away (tooie::app_state), nothing sends frames or handles events: no hang is reported then.
    void set_suspended(bool suspended);

    // What the renderer reported at the last presented frame (the frame rate overlay shows it).
    struct RendererInfo {
        ultramodern::renderer::GraphicsApi api = ultramodern::renderer::GraphicsApi::Auto;
        float resolution_scale = 0.0f;
        uint32_t display_rate = 0;
    };
    RendererInfo renderer_info();

    // Wraps the renderer context so every presented frame is counted.
    std::unique_ptr<ultramodern::renderer::RendererContext> wrap(
        std::unique_ptr<ultramodern::renderer::RendererContext> inner);
}

#endif
