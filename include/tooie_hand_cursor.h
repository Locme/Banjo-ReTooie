#ifndef __TOOIE_HAND_CURSOR_H__
#define __TOOIE_HAND_CURSOR_H__

#include <string>

namespace recomp::config {
    class Config;
}

// The cursor is the save select's pointing hand wherever it shows over the game window (the Start menu,
// the ESC menu, the other menus) (L, 2026-10-24; src/input/hand_cursor.cpp). On by default.
namespace tooie::hand_cursor {
    inline const std::string option = "hand_cursor";

    void add_option(recomp::config::Config& graphics);

    // Each pass of the window's event loop (main thread): puts the hand or the system cursor in place.
    void update();
}

#endif
