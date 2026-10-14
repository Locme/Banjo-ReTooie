#ifndef __TOOIE_CONTROL_SCHEME_H__
#define __TOOIE_CONTROL_SCHEME_H__

#include <cstdint>
#include <string>

namespace recomp::config {
    class Config;
}

// D-pad control scheme (handoff 4.60, src/input/control_scheme.cpp): General > Control scheme.
// With "D-pad", the D-pad walks Banjo at full tilt (diagonals too) unless the left stick is pushed,
// and while L (LB) is held the D-pad acts as the C-buttons instead. The D-pad cheats are off then.
namespace tooie::control_scheme {
    inline const std::string option = "control_scheme";

    void add_option(recomp::config::Config& general);

    // Applies the scheme to player 1's input as the game is about to read it.
    void apply(uint16_t* buttons, float* x, float* y);
}

#endif
