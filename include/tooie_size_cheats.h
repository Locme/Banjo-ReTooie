#ifndef __TOOIE_SIZE_CHEATS_H__
#define __TOOIE_SIZE_CHEATS_H__

#include <cstdint>

#include "recomp.h"

// Cheats > Big head, Small head, Big body, Tiny body (src/gameplay/size_cheats.cpp), called from Snout
// jiggle's draw hooks (src/gameplay/snout_jiggle.cpp).
namespace tooie::size_cheats {
    // func_800DE498 has settled on the model it draws.
    void model(uint8_t* rdram, uint32_t model);
    // func_800DCF48: bone's matrix in $v0, about to be pushed; may point $v0 at a scaled copy.
    void bone(uint8_t* rdram, recomp_context* ctx, int bone);
}

#endif
