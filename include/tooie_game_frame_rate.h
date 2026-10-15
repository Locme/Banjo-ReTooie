#ifndef __TOOIE_GAME_FRAME_RATE_H__
#define __TOOIE_GAME_FRAME_RATE_H__

#include <cstdint>
#include <string>

#include "librecomp/config.hpp"

// Game frame rate (src/game/game_frame_rate.cpp): how often the game itself
// updates, as opposed to the Interpolation option, which only changes how often
// frames are presented and blended.
namespace tooie::game_frame_rate {
    enum class Mode : uint32_t { Original, Fps30, Fps60, Fps120, Unlocked };
    inline const std::string option = "game_frame_rate";
    // Talking-head portraits step every game frame above 30 FPS (else 30 a second).
    inline const std::string smooth_talking_heads_option = "smooth_talking_heads";

    // Adds the option to the Graphics tab. It applies from the next game frame.
    void add_option(recomp::config::Config& graphics);

    // Game time in ms since the game started, from each frame's delta time.
    // With TOOIE_PAD_GAME_TIME=1 the pad script and TOOIE_TELEPORT run on it,
    // so a headless run that can't keep up (120 FPS) gets the same inputs.
    uint32_t game_ms();
    bool pad_on_game_time();
}

#endif
