#ifndef __TOOIE_SAVE_STATE_H__
#define __TOOIE_SAVE_STATE_H__

#include <cstdint>

#include "recomp.h"

// Save states (handoff 4.14, src/gameplay/save_state.cpp): the Save State key (Insert) keeps one
// snapshot of the game in memory, and the Load State key (Home) goes back to it. In a level only;
// lost when the game closes.
namespace tooie::save_state {
    // Names the two keys and sets their default bindings (before the controls config loads).
    void register_input();

    // Starts the thread that watches the keys.
    void start();

    // Once per frame on the game thread (tooie_warp_tick): takes or restores the snapshot.
    void tick(uint8_t* rdram, recomp_context* ctx);

    // Freeze (the Freeze key, src/debug/interp_check.cpp): holds the game on
    // two game frames, put back every two frames, so the blend mode can be switched on a still scene.
    // In a level only; a map change or Load State ends it (freeze_on() then reads false).
    void set_freeze(bool on);
    bool freeze_on();
    // True while the game is actually being held (sound is muted).
    bool frozen();
}

#endif
