#ifndef __TOOIE_TRANSFORM_MENU_H__
#define __TOOIE_TRANSFORM_MENU_H__

#include <cstdint>
#include <string>

#include "recomp.h"

// Transform Anywhere Menu (src/gameplay/transform_menu.cpp, L 2026-11-03): QOL option, off by default, separate
// from Transform Anywhere. While it is on, the Transform key opens a menu over the frozen game showing every form
// the save file has already unlocked (Humba's forms once changed into, Mumbo once played, Banjo and Kazooie once
// Split Up is learnt, ...). The d-pad or stick picks one, A changes into it, B goes back.
namespace tooie::transform_menu {
    inline const std::string option = "transform_menu";

    // Whether the QOL option is on (or TOOIE_TRANSFORM_MENU is set headless).
    bool enabled();

    // Whether the menu is up now.
    bool is_open();

    // The console's transformmenu command (src/game/console.cpp): opens (true) or closes (false) the menu on the next
    // game frame, as the Transform key would.
    void request(bool open);

    // Call once per frame from the game thread (tooie_warp_tick), after the frame's delta time is written.
    void tick(uint8_t* rdram, recomp_context* ctx);

    // Draws the menu on top of the game's 2D (tooie_draw2d_mark, last mark). gfx is the graphics context, whose
    // first word is the display list pointer.
    void draw(uint8_t* rdram, recomp_context* ctx, uint32_t gfx);

    // The N64 pad filter (pad_script.cpp): while the menu is up the game gets no buttons and no stick, and the
    // menu reads them instead. Buttons held when it closes are kept from the game until let go.
    void apply_input(uint16_t* buttons, float* x, float* y);
}

#endif
