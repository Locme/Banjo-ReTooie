#ifndef __TOOIE_ACHIEVEMENTS_H__
#define __TOOIE_ACHIEVEMENTS_H__

#include <cstdint>
#include <string>
#include <vector>

#include "recomp.h"

// Achievements (src/game/achievements.cpp, handoff 4.85): the Xbox Live Arcade version's twelve
// achievements, unlocked from the game's own progress flags, with a pop-up and an Achievements tab.
namespace tooie::achievements {
    // The settings menu tab's id (shown with DEV > Additional Tabs > Achievements tab).
    inline const std::string tab_id = "achievements";

    // Adds the Achievements tab and loads what was unlocked before. Call before recompui::config::finalize().
    void create_tab();

    // Call once per frame from the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram, recomp_context* ctx);

    // The pause menu's Achievements page (src/gameplay/pause_settings.cpp opens it, a Totals sub page of
    // its own; src/gameplay/totals_checklist.cpp draws it).
    constexpr uint8_t pause_sub_page = 0x7E;

    // One achievement as the pause page shows it, in the XBLA order.
    struct PauseEntry {
        std::string name;
        std::string description;
        int points = 0;
        bool unlocked = false;
        std::string unlocked_at;    // "YYYY-MM-DD HH:MM", empty when locked
        int count = -1;             // counted achievements: the count so far, else -1
        int goal = 0;
    };
    std::vector<PauseEntry> pause_entries();
}

#endif
