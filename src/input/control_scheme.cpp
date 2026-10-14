// D-pad control scheme (handoff 4.60).
//
// The XBLA version offered a scheme where the D-pad walks Banjo and LB + D-pad act as the
// C-buttons. Here LB is the N64 L button by default, which Banjo-Tooie leaves unused in play, so
// L + D-pad gives the C-buttons and L itself is not passed on while the D-pad is used with it.
// The D-pad bits are taken out of the input, which also turns the D-pad cheats off.

#include <cmath>
#include <variant>

#include "recompui/config.h"
#include "tooie_control_scheme.h"

namespace {
    enum Scheme : uint32_t {
        Original = 0,
        DPad = 1,
    };

    constexpr uint16_t button_l = 0x0020;
    constexpr uint16_t d_up = 0x0800, d_down = 0x0400, d_left = 0x0200, d_right = 0x0100;
    constexpr uint16_t c_up = 0x0008, c_down = 0x0004, c_left = 0x0002, c_right = 0x0001;
    constexpr uint16_t d_all = d_up | d_down | d_left | d_right;
    // A left stick tilted past this takes over from the D-pad.
    constexpr float stick_deadzone = 0.2f;

    uint32_t scheme() {
        try {
            return std::get<uint32_t>(recompui::config::get_general_config().get_option_value(tooie::control_scheme::option));
        } catch (...) {
            return Original;
        }
    }
}

void tooie::control_scheme::add_option(recomp::config::Config& general) {
    general.add_enum_option(option, "Control scheme",
        "<recomp-color primary>D-pad</recomp-color>: the D-pad walks Banjo (unless the left stick is pushed), "
        "and holding L (LB) makes the D-pad the C-buttons. The D-pad cheats are off in this scheme.",
        {
            {Original, "original", "Original"},
            {DPad, "dpad", "D-pad"},
        },
        Original);
}

void tooie::control_scheme::apply(uint16_t* buttons, float* x, float* y) {
    const uint16_t dpad = *buttons & d_all;
    if (scheme() != DPad) {
        return;
    }
    *buttons &= ~d_all;
    if (dpad == 0) {
        return;
    }
    if (*buttons & button_l) {
        *buttons &= ~button_l;
        if (dpad & d_up) *buttons |= c_up;
        if (dpad & d_down) *buttons |= c_down;
        if (dpad & d_left) *buttons |= c_left;
        if (dpad & d_right) *buttons |= c_right;
        return;
    }
    if (std::fabs(*x) > stick_deadzone || std::fabs(*y) > stick_deadzone) {
        return;
    }
    float dx = (dpad & d_right ? 1.0f : 0.0f) - (dpad & d_left ? 1.0f : 0.0f);
    float dy = (dpad & d_up ? 1.0f : 0.0f) - (dpad & d_down ? 1.0f : 0.0f);
    if (dx != 0.0f && dy != 0.0f) {
        dx *= 0.7071f;
        dy *= 0.7071f;
    }
    *x = dx;
    *y = dy;
}
