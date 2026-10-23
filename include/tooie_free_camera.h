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
    inline const std::string free_camera_ease_back_option = "free_camera_ease_back";
    inline const std::string free_camera_smooth_walls_option = "free_camera_smooth_walls";
    inline const std::string free_camera_hover_option = "free_camera_hover";
    // WIP tab (Graphics config, graphics.json).
    inline const std::string free_camera_floor_clearance_option = "free_camera_floor_clearance";
    inline const std::string free_camera_look_up_option = "free_camera_look_up";
    inline const std::string free_camera_orbit_option = "free_camera_orbit";
    inline const std::string free_camera_rb_distance_option = "free_camera_rb_distance";
    inline const std::string photo_mode_collision_option = "photo_mode_collision";
    enum class FreeCameraSpeed : uint32_t { Slow, Normal, Fast };
    enum class FreeCameraMouse : uint32_t { Off, Always, Hold };
    enum class FreeCameraEaseBack : uint32_t { Off, Flying, Always };
}

namespace tooie::free_camera {
    bool enabled();

    // The camera controller of the last viewport stepped (func_8010FC38's argument), 0 before any.
    uint32_t last_controller();

    // The game's camera line test (func_800FAB50, 45-unit radius): moves `to` back to where the line
    // from `from` first hits, and gives that surface's normal. Returns whether it hit.
    bool sweep_line(uint8_t* rdram, recomp_context* ctx, const float from[3], float to[3], float normal[3]);
}

#endif
