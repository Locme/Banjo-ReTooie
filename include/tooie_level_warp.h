#ifndef __TOOIE_LEVEL_WARP_H__
#define __TOOIE_LEVEL_WARP_H__

#include <cstddef>
#include <string>
#include <vector>

namespace recomp::config {
    class Config;
}

// Level warp (src/game/level_warp.cpp, handoff 4.80): a "Warp" tab in the menu, shown while
// DEV > Additional Tabs > Warp tab is on, lists the places; picking one closes the menu and warps there with
// the game's own map change. F9 repeats the last warp.
namespace tooie::level_warp {
    // Adds the menu tab. Call with the other tabs, before recompui::config::finalize().
    void create_tab();

    // Adds the Warp tab switch to the DEV tab's config.
    void add_option(recomp::config::Config& dev);

    // Shows or hides the tab to match its switch.
    void refresh();

    // Starts the F9 key-watching thread (safe to call more than once).
    void start();

    // The places the Warp tab lists, as "Group: Name", in the tab's order (for the developer console).
    std::vector<std::string> place_names();

    // Warps to place `index` of place_names() as a pick in the tab does (and F9 then repeats it). False if there is
    // no such place.
    bool warp_to_place(size_t index);
}

#endif
