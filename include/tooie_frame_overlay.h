#ifndef __TOOIE_FRAME_OVERLAY_H__
#define __TOOIE_FRAME_OVERLAY_H__

#include <string>

#include "librecomp/config.hpp"

// Frame rate overlay (src/game/frame_overlay.cpp): frame rate, frame time and
// interpolation figures in the top left corner, behind one Graphics option.
namespace tooie::frame_overlay {
    inline const std::string option = "frame_rate_overlay";

    // Adds the option to the Graphics tab. It applies as soon as it changes.
    void add_option(recomp::config::Config& graphics);
    // Starts the thread that updates the overlay (safe to call more than once).
    void start();
}

#endif
