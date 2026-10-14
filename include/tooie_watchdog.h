#ifndef __TOOIE_WATCHDOG_H__
#define __TOOIE_WATCHDOG_H__

#include <memory>

#include "ultramodern/renderer_context.hpp"

// Hang watchdog (src/debug/watchdog.cpp). It never stops or alters the game: it only
// writes a note to logs/hangs.log when no frame has been presented for a few seconds.
namespace tooie::watchdog {
    // Starts the watchdog thread (safe to call more than once). It arms itself when the
    // first frame is presented, so it stays quiet if frames are never reported.
    void start();

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
