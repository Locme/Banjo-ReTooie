#ifndef __TOOIE_HONEYCOMB_GLITTER_H__
#define __TOOIE_HONEYCOMB_GLITTER_H__

#include <cstdint>
#include <string>

#include "recomp.h"

// Back-Port: Glittering honeycombs (src/gameplay/honeycomb_glitter.cpp, handoff 4.63): health
// honeycombs sparkle like Banjo-Kazooie's.
namespace tooie::honeycomb_glitter {
    inline const std::string option = "glitter_honeycombs";

    // Call once per frame from the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram, recomp_context* ctx);
}

#endif
