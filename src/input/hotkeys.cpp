// Rebindable keys for the debugging and capture functions (see include/tooie_hotkeys.h).
// The Debug section has no default keys (L, 2026-10-14): bind them in the Controls tab.

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include "recompinput/recompinput.h"
#include "recompinput/input_binding.h"
#include "recompinput/profiles.h"

#include "tooie_hotkeys.h"

namespace {
    using recompinput::GameInput;

    void add(GameInput input, const char* name, const char* description, SDL_Scancode key, const char* section) {
        recompinput::set_game_input_name(input, name);
        recompinput::set_game_input_description(input, description);
        recompinput::set_game_input_section(input, section);
        if (key != SDL_SCANCODE_UNKNOWN) {
            recompinput::set_default_mapping_for_keyboard(input, { recompinput::InputField::keyboard(key) });
        } else {
            recompinput::set_default_mapping_for_keyboard(input, {});
        }
        recompinput::set_default_mapping_for_controller(input, {});
    }
}

void tooie::hotkeys::register_inputs() {
    add(GameInput::HIDE_HUD, "Hide HUD",
        "Hides and shows the HUD, the portraits and the text boxes, for screenshots and videos.", SDL_SCANCODE_F1, "Hotkeys");
    add(GameInput::SCREENSHOT, "Screenshot",
        "Saves a picture of the game to the screenshots folder. Hold it for a burst.", SDL_SCANCODE_F12, "Hotkeys");
    add(GameInput::EFFECT_VIEW, "Effect Debug View",
        "Steps to the next effect debug view (hold Shift to go back). Graphics > Debug picks one from a list.", SDL_SCANCODE_UNKNOWN, "Debug");
    add(GameInput::EFFECT_COMPARE, "Effect Compare",
        "Splits the picture: the effects on the left, the original on the right.", SDL_SCANCODE_UNKNOWN, "Debug");
    add(GameInput::INTERP_CHECK, "Interpolation Check",
        "Switches the interpolation check on and off. It tints a model red when its blend between game frames looks wrong.", SDL_SCANCODE_UNKNOWN, "Debug");
    add(GameInput::BLEND_MODE, "Blend Mode",
        "Steps through the interpolation blend modes, for finding what blends wrong. Graphics > Debug picks one from a list.", SDL_SCANCODE_UNKNOWN, "Debug");
    add(GameInput::WARP_AGAIN, "Warp Again",
        "Warps to the last place picked in the Warp tab. Works while the Warp tab is on in the Cheats tab.", SDL_SCANCODE_UNKNOWN, "Debug");
    add(GameInput::PICK_MODEL, "Pick Model",
        "Steps a green highlight through the models on screen, nearest the middle first, for tagging how one blends between game frames.", SDL_SCANCODE_UNKNOWN, "Debug");
    add(GameInput::TAG_MODEL, "Tag Model",
        "Steps the picked model's blend between game frames: default, snap, vertex, untagged. Shows in the custom blend mode.", SDL_SCANCODE_UNKNOWN, "Debug");
    add(GameInput::SAVE_TAGS, "Save Tags",
        "Writes the tagged models to interp_tags.txt next to the save files, to send in for the port's defaults.", SDL_SCANCODE_UNKNOWN, "Debug");
    add(GameInput::UNSAVE_TAG, "Unsave Tag",
        "Removes the picked model's tag, from the game and from interp_tags.txt.", SDL_SCANCODE_UNKNOWN, "Debug");
}

bool tooie::hotkeys::down(recompinput::GameInput input) {
    // Pressing the key to bind it in the Controls tab should not trigger it.
    if (recompinput::binding::is_binding()) {
        return false;
    }
    bool down = false;
    for (int profile : { recompinput::profiles::get_sp_keyboard_profile_index(), recompinput::profiles::get_sp_controller_profile_index() }) {
        if (profile < 0) {
            continue;
        }
        for (size_t b = 0; b < recompinput::num_bindings_per_input; b++) {
            down = down || recompinput::get_input_digital(0, recompinput::profiles::get_input_binding(profile, input, b));
        }
    }
    return down;
}
