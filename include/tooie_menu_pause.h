#ifndef __TOOIE_MENU_PAUSE_H__
#define __TOOIE_MENU_PAUSE_H__

#include <cstdint>
#include <string>

#include "recomp.h"

// Pause Special Menu (src/gameplay/menu_pause.cpp, L 2026-10-19): QOL option, on by default. While the
// ESC menu is open during play, the game stands still as if Start were pressed, without the pause
// menu or any HUD of its own drawn over it, and the music plays on.
namespace tooie::menu_pause {
    inline const std::string option = "pause_special_menu";

    // Called by the main thread's event loop with whether a menu takes the input (update_gfx in main.cpp).
    void set_menu_open(bool open);

    // True while the game thread is held by the pause (the watchdog doesn't count it as a hang).
    bool active();

    // Call at the start of each game frame from the game thread (tooie_warp_tick). Waits there while
    // the pause applies.
    void tick(uint8_t* rdram, recomp_context* ctx);
}

#endif
