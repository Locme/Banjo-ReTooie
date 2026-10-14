#ifndef __TOOIE_PHOTO_MODE_H__
#define __TOOIE_PHOTO_MODE_H__

#include <cstdint>
#include <string>

#include "recomp.h"

// Photo mode (handoff 4.82, src/gameplay/photo_mode.cpp): the Photo Mode key (F10, bindable in the
// Controls tab) freezes the game, hides the HUD and flies the camera freely. A takes a screenshot,
// Start cycles frozen / 1/8 / 1/4 speed, B or the Photo Mode key goes back to the game.
namespace recomp::config {
    class Config;
}

namespace tooie::photo_mode {
    inline const std::string look_option = "photo_look";
    inline const std::string exposure_option = "photo_exposure";
    inline const std::string contrast_option = "photo_contrast";
    inline const std::string saturation_option = "photo_saturation";
    inline const std::string warmth_option = "photo_warmth";
    inline const std::string vignette_option = "photo_vignette";
    inline const std::string grain_option = "photo_grain";
    inline const std::string crop_option = "photo_crop";
    inline const std::string grid_option = "photo_grid";
    inline const std::string dof_option = "photo_dof";

    // Adds photo mode's filter rows to the QOL tab (used only while photo mode is on).
    void add_options(recomp::config::Config& qol);

    // Names the Photo Mode key and sets its default bindings (before the controls config loads).
    void register_input();

    // Starts the thread that watches the Photo Mode key.
    void start();

    bool active();

    // The photo crop's width / height while photo mode is on, 0 for none. Screenshots keep only the frame.
    float crop_aspect();

    // The field of view the game sets, zoomed while photo mode is on (tooie_set_fov).
    float adjust_fov(float fov);

    // Takes player 1's input while photo mode is on: the controls drive the camera and the game
    // sees an idle pad.
    void apply_input(uint16_t* buttons, float* x, float* y);

    // Once per frame on the game thread (tooie_warp_tick): enters and leaves, and slows game time.
    void tick(uint8_t* rdram, recomp_context* ctx);

    // From the camera controller hook (tooie_free_camera) with the viewport camera; returns true
    // when photo mode placed the camera.
    bool place_camera(uint8_t* rdram, recomp_context* ctx, uint32_t camera);
}

#endif
