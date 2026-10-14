#ifndef __TOOIE_FREE_CAMERA_H__
#define __TOOIE_FREE_CAMERA_H__

#include <cstdint>
#include <string>

#include "recomp.h"

namespace tooie {
    // Twin-stick (free) camera (src/gameplay/free_camera.cpp), QOL tab.
    inline const std::string free_camera_option = "free_camera";
    inline const std::string free_camera_invert_x_option = "free_camera_invert_x";
    inline const std::string free_camera_invert_y_option = "free_camera_invert_y";
    inline const std::string free_camera_speed_option = "free_camera_speed";
    inline const std::string photo_mode_collision_option = "photo_mode_collision";
    enum class FreeCameraSpeed : uint32_t { Slow, Normal, Fast };
}

namespace tooie::free_camera {
    bool enabled();

    // The game's camera line test (func_800FAB50, 45-unit radius): moves `to` back to where the line
    // from `from` first hits, and gives that surface's normal. Returns whether it hit.
    bool sweep_line(uint8_t* rdram, recomp_context* ctx, const float from[3], float to[3], float normal[3]);
}

#endif
