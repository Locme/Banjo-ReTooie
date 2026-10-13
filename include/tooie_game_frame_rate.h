#ifndef __TOOIE_GAME_FRAME_RATE_H__
#define __TOOIE_GAME_FRAME_RATE_H__

#include <cstdint>
#include <string>

#include "librecomp/config.hpp"

// Game frame rate (src/game/game_frame_rate.cpp): how often the game itself
// updates, as opposed to the Framerate option, which only changes how often
// frames are presented and blended.
namespace tooie::game_frame_rate {
    enum class Mode : uint32_t { Original, Fps30, Fps60 };
    inline const std::string option = "game_frame_rate";

    // Adds the option to the Graphics tab. It applies from the next game frame.
    void add_option(recomp::config::Config& graphics);
}

#endif
