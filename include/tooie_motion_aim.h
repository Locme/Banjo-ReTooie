#ifndef __TOOIE_MOTION_AIM_H__
#define __TOOIE_MOTION_AIM_H__

#include <cstdint>
#include <string>

#include "recomp.h"

namespace recomp::config {
    class Config;
}

// Mouse and gyro aiming (handoff 4.58 and 4.59, src/input/motion_aim.cpp): in first person the mouse
// and a controller's gyro turn the view directly, on top of the stick; in the first-person shooter sections they
// turn Banjo left and right. Strengths are the General tab's
// Mouse Sensitivity and Gyro Sensitivity (0 turns each off).
namespace tooie::motion_aim {
    inline const std::string invert_y_option = "motion_aim_invert_y";
    // Direct analog aim: in first person the left stick's tilt sets how fast the view turns (the game's own
    // turn is nearly the same at any tilt), like a modern shooter. The reticle stays at the centre.
    inline const std::string direct_option = "direct_analog_aim";
    inline const std::string direct_speed_option = "direct_analog_aim_speed";
    enum class DirectSpeed : uint32_t { Slow, Medium, Fast };
    // Instant shooter view: in the first-person shooter sections the view turns and tilts all the way to where Banjo
    // aims each frame, instead of at the game's capped speed, which kept it turning after the mouse stopped.
    inline const std::string instant_shooter_view_option = "instant_shooter_view";

    void add_options(recomp::config::Config& qol);

    // The left stick the game is about to read (-1 to 1, right and up positive), from the end of each pad read.
    // With direct analog aim on in first person it centres the stick the game is given (the view is turned from
    // the one kept here).
    void note_stick(float* x, float* y);

    // From each pad read for player 1: collects the mouse and gyro motion since the last read.
    void collect();

    // The mouse and gyro motion in degrees (yaw positive to the left, pitch positive upwards) since the last
    // call, for the free camera's orbit. Always drains it.
    void take_orbit(float* mouse_yaw, float* mouse_pitch, float* gyro_yaw, float* gyro_pitch);

    // Once per frame on the game thread (tooie_warp_tick): turns the first-person view.
    void tick(uint8_t* rdram, recomp_context* ctx);
}

#endif
