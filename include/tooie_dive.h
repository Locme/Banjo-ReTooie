#ifndef __TOOIE_DIVE_H__
#define __TOOIE_DIVE_H__

#include <cstdint>
#include <string>

#include "recomp.h"

// Dive (src/gameplay/dive.cpp, L 2026-10-21): an optional mid-air lunge for Banjo-Kazooie, on the Run
// button (B on a controller). QOL > Dive turns it on; it is off by default, so the game plays as it
// always did until then.
namespace tooie::dive {
    // QOL > Dive: off (the default) leaves B in the air to the game.
    inline const std::string option = "dive";

    // Call once per game state update from tooie_warp_tick: starts, drives and ends the dive.
    void tick(uint8_t* rdram, recomp_context* ctx);

    // Applies to player 1's buttons as the game is about to read them: while a dive could start, B is
    // kept from the game so the game's own B move doesn't fire with it. Safe to call more than once per frame.
    void apply(uint16_t* buttons);
}

#endif
