#ifndef __TOOIE_FREE_CAMERA_H__
#define __TOOIE_FREE_CAMERA_H__

#include <cstdint>
#include <string>

namespace tooie {
    // Twin-stick (free) camera (src/gameplay/free_camera.cpp), QOL tab.
    inline const std::string free_camera_option = "free_camera";
    inline const std::string free_camera_invert_x_option = "free_camera_invert_x";
    inline const std::string free_camera_invert_y_option = "free_camera_invert_y";
    inline const std::string free_camera_speed_option = "free_camera_speed";
    enum class FreeCameraSpeed : uint32_t { Slow, Normal, Fast };
}

namespace tooie::free_camera {
    bool enabled();
}

#endif
