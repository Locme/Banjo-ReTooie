#ifndef __TOOIE_FRAME_OVERLAY_H__
#define __TOOIE_FRAME_OVERLAY_H__

#include <cstdint>
#include <string>

#include "librecomp/config.hpp"

// Frame rate overlay (src/game/frame_overlay.cpp): frame rate, frame time, stutter,
// interpolation, location, renderer and extras in the top left corner, behind one
// Graphics option.
namespace tooie::frame_overlay {
    // An enum since the hotkey and Compact were added (it was a bool named "frame_rate_overlay").
    inline const std::string option = "frame_rate_overlay_mode";

    enum class Mode : uint32_t { Off, Compact, Full };

    // Names the Frame Rate Overlay hotkey and gives it its default binding (F3). Call
    // before recompui::config::finalize(), which loads the controls config.
    void register_input();
    // Adds the option to the Graphics tab. It applies as soon as it changes.
    void add_option(recomp::config::Config& graphics);
    // Starts the threads that update the overlay and watch its hotkey (safe to call more than once).
    void start(uint8_t* rdram);
    // Called by the audio output for each chunk the game hands over: how much was
    // still queued, and whether the chunk was sped up to cut latency.
    void note_audio_chunk(uint64_t queued_us, bool sped_up);
}

#endif
