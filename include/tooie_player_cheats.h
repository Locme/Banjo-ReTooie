#ifndef __TOOIE_PLAYER_CHEATS_H__
#define __TOOIE_PLAYER_CHEATS_H__

#include <cstdint>

#include "recomp.h"

// Cheats that change how the player moves (src/gameplay/player_cheats.cpp): Infinite Jumps (Levitate)
// and Fly anywhere.
namespace tooie::player_cheats {
    // Call once per frame from the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram, recomp_context* ctx);
    // Call on every read of player 1's buttons: while flying with Fly anywhere on, B stops the flight
    // instead of reaching the game.
    void apply_input(uint16_t* buttons);
}

#endif
