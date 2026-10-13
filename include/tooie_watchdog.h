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

    // Wraps the renderer context so every presented frame is counted.
    std::unique_ptr<ultramodern::renderer::RendererContext> wrap(
        std::unique_ptr<ultramodern::renderer::RendererContext> inner);
}

#endif
