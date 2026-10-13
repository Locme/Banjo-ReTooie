#ifndef __TOOIE_PLAYER_CHEATS_H__
#define __TOOIE_PLAYER_CHEATS_H__

#include <cstdint>

#include "recomp.h"

// Cheats that change how the player moves (src/gameplay/player_cheats.cpp): Levitate and Infinite jumps.
namespace tooie::player_cheats {
    // Call once per frame from the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram, recomp_context* ctx);
}

#endif
