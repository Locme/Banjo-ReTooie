#ifndef __TOOIE_TIPTOE_H__
#define __TOOIE_TIPTOE_H__

#include <cstdint>
#include <string>

// Tiptoe hotkey (src/input/tiptoe.cpp, handoff 4.56): a game input in the Controls tab (Hotkeys),
// Left stick click on a controller by default. While it is held, the left stick's tilt is capped to
// the tiptoe band, so Banjo tiptoes at any tilt.
namespace tooie::input {
    // Names the Tiptoe hotkey and gives it its default binding. Call before
    // recompui::config::finalize(), which loads the controls config.
    void register_input();

    // Applies the tiptoe button to player 1's input as the game is about to read it. The stick
    // values are the fractions (-1 to 1) of the stick range. Safe to call more than once per frame.
    void apply_tiptoe(uint16_t* buttons, float* x, float* y);
}

#endif
