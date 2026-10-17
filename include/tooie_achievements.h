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
        int portrait = -1;          // its icon: a talking-head portrait id (gczoomboxdata), -1 for none
    };
    std::vector<PauseEntry> pause_entries();

    // The unlock pop-up, drawn by the game at the end of its 2D (src/gameplay/totals_checklist.cpp, from
    // tooie_draw2d_mark) so its icon is the game's own portrait art, texture packs included.
    struct Popup {
        std::string name;
        int points = 0;
        int portrait = -1;
    };
    // The pop-up to show next, if one is waiting; taken off the queue.
    bool take_popup(Popup& out);
    void draw_popup(uint8_t* rdram, recomp_context* ctx, uint32_t gfx);
}

#endif
