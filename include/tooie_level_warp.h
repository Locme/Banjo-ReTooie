#ifndef __TOOIE_LEVEL_WARP_H__
#define __TOOIE_LEVEL_WARP_H__

// Level warp (src/game/level_warp.cpp, handoff 4.80): a "Debug" tab in the menu, shown while
// General > Debug tab is on, lists 42 places; picking one closes the menu and warps there with
// the game's own map change. F9 repeats the last warp.
namespace tooie::level_warp {
    // Adds the menu tab and its General option. Call with the other tabs, before recompui::config::finalize().
    void create_tab();

    // Starts the F9 key-watching thread (safe to call more than once).
    void start();
}

#endif
