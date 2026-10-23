#ifndef __TOOIE_MOTION_AIM_H__
#define __TOOIE_MOTION_AIM_H__

#include <cstdint>
#include <string>

#include "recomp.h"

namespace recomp::config {
    class Config;
}

// Mouse and gyro aiming (handoff 4.58 and 4.59, src/input/motion_aim.cpp): in first person the mouse
// and a controller's gyro turn the view directly, on top of the stick. Strengths are the General tab's
// Mouse Sensitivity and Gyro Sensitivity (0 turns each off).
namespace tooie::motion_aim {
    inline const std::string invert_y_option = "motion_aim_invert_y";

    void add_options(recomp::config::Config& qol);

    // From each pad read for player 1: collects the mouse and gyro motion since the last read.
    void collect();

    // The mouse and gyro motion in degrees (yaw positive to the left, pitch positive upwards) since the last
    // call, for the free camera's orbit. Always drains it.
    void take_orbit(float* yaw, float* pitch);

    // Once per frame on the game thread (tooie_warp_tick): turns the first-person view.
    void tick(uint8_t* rdram, recomp_context* ctx);
}

#endif
