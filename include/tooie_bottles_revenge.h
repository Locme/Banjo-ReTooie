#ifndef __TOOIE_BOTTLES_REVENGE_H__
#define __TOOIE_BOTTLES_REVENGE_H__

#include <cstdint>
#include <string>

#include "recomp.h"

namespace recomp::config {
    class Config;
}

// Cut Content: Bottles' Revenge (handoff 4.77, src/gameplay/bottles_revenge.cpp). The two-player mode
// cut from the game: Devil Bottles follows Banjo, and player 2 (the second controller) possesses enemies.
namespace tooie::bottles_revenge {
    inline const std::string option = "bottles_revenge";

    void add_option(recomp::config::Config& general);

    // Once per frame on the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram, recomp_context* ctx);
}

#endif
