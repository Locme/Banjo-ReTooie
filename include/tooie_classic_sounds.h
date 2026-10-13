#ifndef __TOOIE_CLASSIC_SOUNDS_H__
#define __TOOIE_CLASSIC_SOUNDS_H__

#include <cstdint>
#include <string>

#include "recomp.h"

// Back-Port: Old Banjo sounds (src/gameplay/classic_sounds.cpp, handoff 4.64): Banjo-Kazooie's jump
// sounds in place of Tooie's.
namespace tooie::classic_sounds {
    inline const std::string option = "classic_jump_sounds";

    // Call once per frame from the game thread (tooie_warp_tick): keeps the jump sound table in step
    // with the option.
    void tick(uint8_t* rdram);
}

#endif
