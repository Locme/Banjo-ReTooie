#ifndef __TOOIE_WATER_CAMERA_H__
#define __TOOIE_WATER_CAMERA_H__

#include <cstdint>
#include <string>

#include "recomp.h"

namespace recomp::config {
    class Config;
}

namespace tooie {
    // Water camera (src/gameplay/water_camera.cpp), QOL tab: a switch with seven toggles under it.
    inline const std::string water_camera_option = "water_camera";
    inline const std::string water_camera_waterline_option = "water_camera_waterline";
    inline const std::string water_camera_splash_option = "water_camera_splash";
    inline const std::string water_camera_bob_option = "water_camera_bob";
    inline const std::string water_camera_drag_option = "water_camera_drag";
    inline const std::string water_camera_follow_option = "water_camera_follow";
    inline const std::string water_camera_torpedo_option = "water_camera_torpedo";
    inline const std::string water_camera_look_up_option = "water_camera_look_up";
}

namespace tooie::water_camera {
    void add_options(recomp::config::Config& qol);

    // Run once per camera step from the free camera's hook (func_8010FC38), after the game's camera, or the
    // free camera, has placed the camera at `camera` and before the matrices are built. `player_state` is
    // Banjo's state and `banjo` his position. `ctx` is the hook's, for the game's camera line test.
    void apply(uint8_t* rdram, recomp_context* ctx, uint32_t camera, uint32_t player_state, const float banjo[3]);

    // True while Banjo is under water and the Look Up Under Water toggle is on: the free camera may then
    // go further below him, to look up at the surface, down to this many degrees of elevation.
    bool look_up_under_water(uint32_t player_state);
    constexpr float look_up_low_limit = -60.0f;

    // True while Banjo is under water (swimming below the surface, not floating on it).
    bool under_water(uint32_t player_state);
}

#endif
