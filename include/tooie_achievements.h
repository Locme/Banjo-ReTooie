#ifndef __TOOIE_ACHIEVEMENTS_H__
#define __TOOIE_ACHIEVEMENTS_H__

#include <cstdint>

#include "recomp.h"

// Achievements (src/game/achievements.cpp, handoff 4.85): the Xbox Live Arcade version's twelve
// achievements, unlocked from the game's own progress flags, with a pop-up and an Achievements tab.
namespace tooie::achievements {
    // Adds the Achievements tab and loads what was unlocked before. Call before recompui::config::finalize().
    void create_tab();

    // Call once per frame from the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram, recomp_context* ctx);
}

#endif
