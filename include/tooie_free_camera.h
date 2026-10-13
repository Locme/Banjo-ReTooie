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
    // With the free camera on, the right stick click steps the camera distance, so first person
    // (C-up) gets a button of its own.
    inline const std::string first_person_button_option = "first_person_button";
    enum class FirstPersonButton : uint32_t { Off, DpadUp, LeftStick };
}

namespace tooie::free_camera {
    bool enabled();
    // Applies the free camera's buttons to player 1's input as the game is about to read it: the
    // right stick click no longer reaches the game as C-up (it steps the camera distance instead)
    // and the first person button gives C-up.
    void apply_buttons(uint16_t* buttons);
}

#endif
