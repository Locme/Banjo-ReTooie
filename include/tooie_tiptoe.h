#ifndef __TOOIE_TIPTOE_H__
#define __TOOIE_TIPTOE_H__

#include <cstdint>
#include <string>

// Dedicated tiptoe button (src/input/tiptoe.cpp, handoff 4.56): while the chosen button is held, the
// left stick's tilt is capped to the tiptoe band, so Banjo tiptoes at any tilt.
namespace tooie::input {
    enum class TiptoeButton : uint32_t { Off, B, LeftStick, RightStick };
    inline const std::string tiptoe_option = "tiptoe_button";

    // Applies the tiptoe button to player 1's input as the game is about to read it. The stick
    // values are the fractions (-1 to 1) of the stick range. Safe to call more than once per frame.
    void apply_tiptoe(uint16_t* buttons, float* x, float* y);
}

#endif
