#ifndef __TOOIE_GAME_FRAME_RATE_H__
#define __TOOIE_GAME_FRAME_RATE_H__

#include <cstdint>
#include <string>

#include "librecomp/config.hpp"

// Game frame rate (src/game/game_frame_rate.cpp): how often the game itself
// updates, as opposed to the Interpolation option, which only changes how often
// frames are presented and blended.
namespace tooie::game_frame_rate {
    // Values are saved by key; the new ones go at the end. Uncapped keeps the key "Unlocked".
    enum class Mode : uint32_t { Original, Fps30, Fps60, Fps120, Uncapped, Fps40, Fps175, Fps240 };
    inline const std::string option = "game_frame_rate";
    // DEV tab: Force Interpolation in cutscenes (on by default).
    inline const std::string force_scene_interpolation_option = "force_scene_interpolation";
    // DEV tab: Force Interpolation in the gameplay demo (off by default, L 2026-10-16).
    inline const std::string force_demo_interpolation_option = "force_demo_interpolation";
    // DEV tab: Talking heads at 20 FPS (off by default, L 2026-10-16).
    inline const std::string talking_heads_20_option = "talking_heads_20fps";

    // Adds the option to the Graphics tab. It applies from the next game frame.
    void add_option(recomp::config::Config& graphics);
    void add_dev_options(recomp::config::Config& dev);

    // Game time in ms since the game started, from each frame's delta time.
    // With TOOIE_PAD_GAME_TIME=1 the pad script and TOOIE_TELEPORT run on it,
    // so a headless run that can't keep up (120 FPS) gets the same inputs.
    uint32_t game_ms();
    bool pad_on_game_time();
}

#endif
