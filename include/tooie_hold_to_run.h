#ifndef __TOOIE_HOLD_TO_RUN_H__
#define __TOOIE_HOLD_TO_RUN_H__

#include <cstdint>
#include <string>

#include "recomp.h"

// Hold to run (src/gameplay/hold_to_run.cpp, L 2026-10-14): while the Run control (Controls tab,
// not bound by default) is held, Banjo-Kazooie, Banjo alone and Kazooie alone run faster than their
// normal run, with a sprint animation.
namespace tooie::hold_to_run {
    // QOL > Running: on (the default) lets the Run control run.
    inline const std::string option = "running";

    // Names the Run control and leaves it unbound by default. Call before
    // recompui::config::finalize(), which loads the controls config.
    void register_input();

    // Call once per frame from the game thread (tooie_warp_tick): reads the player's state and
    // swaps the run animation.
    void tick(uint8_t* rdram, recomp_context* ctx);

    // Applies the Run control to player 1's stick as the game is about to read it: while Run is held
    // and the stick is tilted, the tilt is made full so the game runs. Safe to call more than once per frame.
    void apply(float* x, float* y);

    // While on, the animation the player is playing is drawn with the dive pose (body flat, limbs still;
    // src/gameplay/dive.cpp). Call once per frame from the game thread.
    void set_dive_pose(uint8_t* rdram, recomp_context* ctx, bool on);

    // Whether the Run control is held right now (noclip moves 5x faster while it is).
    bool held();
}

#endif
