#ifndef __TOOIE_BOSS_RUSH_H__
#define __TOOIE_BOSS_RUSH_H__

#include <cstdint>
#include <string>

#include "recomp.h"

namespace recomp::config {
    class Config;
}

// Boss rush (src/gameplay/boss_rush.cpp): General > Boss rush fights the 13 bosses one after another with
// the game's own Boss Replay, whatever the save file has reached.
namespace tooie::boss_rush {
    inline const std::string option = "boss_rush";

    void add_option(recomp::config::Config& general);

    // Call once per frame from the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram, recomp_context* ctx);
}

#endif
