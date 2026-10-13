#ifndef __TOOIE_PROGRESS_CHEATS_H__
#define __TOOIE_PROGRESS_CHEATS_H__

#include "recomp.h"

// Cheats that use the game's flags (src/gameplay/progress_cheats.cpp): the Cheato codes and Unlock all moves.
namespace tooie::progress_cheats {
    // Call once per frame from the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram, recomp_context* ctx);
}

#endif
