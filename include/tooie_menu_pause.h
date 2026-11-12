#ifndef __TOOIE_MENU_PAUSE_H__
#define __TOOIE_MENU_PAUSE_H__

#include <cstdint>
#include <string>

#include "recomp.h"
#include "recompui/config.h"

// Pause Special Menu (src/gameplay/menu_pause.cpp, L 2026-10-19): QOL option, on by default. While the
// ESC menu is open during play, gameplay stands still as if Start were pressed, without the pause
// menu or any HUD of its own, the shader effects keep running, and the pause menu's music plays.
namespace tooie::menu_pause {
    inline const std::string option = "pause_special_menu";
    // QOL > Menu > Menu Slide (2026-11-10, on by default): the Esc menu slides in and out like the rows of the
    // Start menu, with the Start menu's sounds (2026-11-12: a pair for each wave of rows coming in, and the two
    // the Start menu plays as it shuts).
    inline const std::string slide_option = "esc_menu_slide";

    // Whether Menu Slide is on (any thread).
    bool slide_enabled();
    // A sound of the Esc menu's slide: queues the Start menu's sound for it (and, for the slide out, the one
    // that follows it), played on the game thread by tick(). Called by the menu on the main thread.
    void slide_sound(recompui::config::SlideSound sound);

    // Called by the main thread's event loop with whether a menu takes the input (update_gfx in main.cpp).
    void set_menu_open(bool open);

    // False while the game would not open its own Start menu (a cutscene or a map change during play), and
    // Pause Special Menu is on: Esc and the menu button then don't open the menu (L, 2026-10-20). Read on the
    // main thread; set by tick().
    bool open_allowed();

    // True while the pause applies (game thread). The frozen delta time is only written at the end of
    // tooie_warp_tick, so the ticks before it read the game's own delta time and ask this instead.
    bool pausing();

    // Call each game frame from the game thread (tooie_warp_tick), after photo mode's: freezes the
    // frame's delta time and handles the pause music while the pause applies.
    void tick(uint8_t* rdram, recomp_context* ctx);
}

#endif
