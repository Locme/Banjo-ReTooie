#ifndef __TOOIE_PHOTO_MODE_H__
#define __TOOIE_PHOTO_MODE_H__

#include <cstdint>

#include "recomp.h"

// Photo mode (handoff 4.82, src/gameplay/photo_mode.cpp): the Photo Mode key (F10, bindable in the
// Controls tab) freezes the game, hides the HUD and flies the camera freely. A takes a screenshot,
// Start cycles frozen / 1/8 / 1/4 speed, B or the Photo Mode key goes back to the game.
namespace tooie::photo_mode {
    // Names the Photo Mode key and sets its default bindings (before the controls config loads).
    void register_input();

    // Starts the thread that watches the Photo Mode key.
    void start();

    bool active();

    // Takes player 1's input while photo mode is on: the controls drive the camera and the game
    // sees an idle pad.
    void apply_input(uint16_t* buttons, float* x, float* y);

    // Once per frame on the game thread (tooie_warp_tick): enters and leaves, and slows game time.
    void tick(uint8_t* rdram, recomp_context* ctx);

    // From the camera controller hook (tooie_free_camera) with the viewport camera; returns true
    // when photo mode placed the camera.
    bool place_camera(uint8_t* rdram, uint32_t camera);
}

#endif
