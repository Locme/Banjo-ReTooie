#ifndef __TOOIE_HOLD_TO_RUN_H__
#define __TOOIE_HOLD_TO_RUN_H__

#include <cstdint>

#include "recomp.h"

// Hold to run (src/gameplay/hold_to_run.cpp, L 2026-10-14): while the Run control (Controls tab,
// not bound by default) is held, Banjo-Kazooie, Banjo alone and Kazooie alone run faster than their
// normal run, with a sprint animation.
namespace tooie::hold_to_run {
    // Names the Run control and leaves it unbound by default. Call before
    // recompui::config::finalize(), which loads the controls config.
    void register_input();

    // Call once per frame from the game thread (tooie_warp_tick): reads the player's state and
    // swaps the run animation.
    void tick(uint8_t* rdram, recomp_context* ctx);

    // Applies the Run control to player 1's buttons as the game is about to read them: when Run
    // shares the B button, B is held back while running and a short tap is passed on as a B press.
    // Safe to call more than once per frame.
    void apply(uint16_t* buttons, float x, float y);
}

#endif
