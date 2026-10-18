#ifndef __TOOIE_HOTKEYS_H__
#define __TOOIE_HOTKEYS_H__

#include <string>

#include "recompinput/input_types.h"

// The function keys that used to be fixed (F1 hide HUD, F6 effect view, F7 interpolation check, F8
// compare, F9 warp again, F12 screenshot) as game inputs in the Controls tab, so they can be rebound.
// The Controls tab lists them under "Hotkeys", or "Debug" for the debugging ones.
namespace tooie::hotkeys {
    // Names the inputs and gives them their default keys. Call before recompui::config::finalize().
    void register_inputs();

    // Whether any key or button bound to the input (keyboard or controller profile) is held. False
    // while a binding is being picked in the Controls tab.
    bool down(recompinput::GameInput input);

    // What the input is bound to, keyboard first then controller, joined by ", ", in promptfont's glyphs (as the
    // Controls tab shows them); empty when it is unbound.
    std::string binding_text(recompinput::GameInput input);
}

#endif
