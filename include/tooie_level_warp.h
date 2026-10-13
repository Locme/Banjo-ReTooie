#ifndef __TOOIE_LEVEL_WARP_H__
#define __TOOIE_LEVEL_WARP_H__

// Level warp (src/game/level_warp.cpp, handoff 4.80): a "Debug" tab in the menu, shown while
// Cheats > Warp tab is on (needs Enable cheats), lists 42 places; picking one closes the menu and warps there with
// the game's own map change. F9 repeats the last warp.
namespace tooie::level_warp {
    // Adds the menu tab and its Cheats option. Call after tooie::cheats::create_tab(), and with the other tabs, before recompui::config::finalize().
    void create_tab();

    // Shows or hides the tab to match the Cheats switches. Cheats calls it when "Enable cheats" changes.
    void refresh();

    // Starts the F9 key-watching thread (safe to call more than once).
    void start();
}

#endif
