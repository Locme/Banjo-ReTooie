#ifndef __TOOIE_CHEATS_H__
#define __TOOIE_CHEATS_H__

#include <cstdint>

namespace recomp::config {
    class Config;
}

// Cheats (src/game/cheats.cpp). Everything stays off, and its rows hidden, until the
// "Enable cheats" master switch is on.
namespace tooie::cheats {
    // Adds the "Cheats" tab. Call before recompui::config::finalize().
    void create_tab();

    // Every game starts with cheats off (L, 2026-10-19: leftover cheats hinder bug testing): turns the master
    // switch off, which resets every cheat, and saves. Call right after recompui::config::finalize().
    void reset_on_start();

    // Starts the thread that applies the cheats to game memory. Call once the game's RDRAM exists.
    void start(uint8_t* rdram);

    // True when the master switch is on. Anything that records progress or achievements should check it.
    bool enabled();

    // True when this cheat's option (for example "cheat_levitate") is on and the master switch is on.
    // Cheap enough to call every frame from the game thread.
    bool is_on(const char* option);

    // The Cheats tab's config (looked up each time: the tab list moves its configs as tabs are added).
    recomp::config::Config& config();
}

#endif
