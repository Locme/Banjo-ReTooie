#ifndef __TOOIE_JIGGY_DANCE_H__
#define __TOOIE_JIGGY_DANCE_H__

#include <cstdint>
#include <string>

#include "recomp.h"

// Back-Port: Get Jiggy animation (src/gameplay/jiggy_dance.cpp): Banjo does Banjo-Kazooie's jiggy jig
// when he collects a Jiggy, instead of Tooie's pose.
namespace tooie::jiggy_dance {
    inline const std::string option = "backport_jiggy_dance";

    // Call once per frame from the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram, recomp_context* ctx);
}

#endif
