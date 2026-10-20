#ifndef __TOOIE_MENU_PAUSE_H__
#define __TOOIE_MENU_PAUSE_H__

#include <cstdint>
#include <string>

#include "recomp.h"

// Pause Special Menu (src/gameplay/menu_pause.cpp, L 2026-10-19): QOL option, on by default. While the
// ESC menu is open during play, gameplay stands still as if Start were pressed, without the pause
// menu or any HUD of its own, the shader effects keep running, and the pause menu's music plays.
namespace tooie::menu_pause {
    inline const std::string option = "pause_special_menu";

    // Called by the main thread's event loop with whether a menu takes the input (update_gfx in main.cpp).
    void set_menu_open(bool open);

    // Call each game frame from the game thread (tooie_warp_tick), after photo mode's: freezes the
    // frame's delta time and handles the pause music while the pause applies.
    void tick(uint8_t* rdram, recomp_context* ctx);
}

#endif
