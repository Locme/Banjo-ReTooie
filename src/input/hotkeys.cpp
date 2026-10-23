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
        "Switches the interpolation check on and off. It tints a model red when its blend between game frames looks wrong.", SDL_SCANCODE_UNKNOWN, "Interpolation Debug");
    add(GameInput::BLEND_MODE, "Blend Mode",
        "Steps through the interpolation blend modes, for finding what blends wrong. Graphics > Debug picks one from a list.", SDL_SCANCODE_UNKNOWN, "Interpolation Debug");
    add(GameInput::FREEZE, "Freeze",
        "Freezes the game on two of its frames, again and again, so you can change the blend mode and compare the frames blended between them. Press again to carry on.", SDL_SCANCODE_UNKNOWN, "Interpolation Debug");
    add(GameInput::WARP_AGAIN, "Warp Again",
        "Warps to the last place picked in the Warp tab. Works while the Warp tab is on in the Cheats tab.", SDL_SCANCODE_UNKNOWN, "Debug");
    add(GameInput::PICK_MODEL, "Pick Model",
        "Steps a green highlight through the models on screen, nearest the middle first, for tagging how one blends between game frames.", SDL_SCANCODE_UNKNOWN, "Interpolation Debug");
    add(GameInput::TAG_MODEL, "Tag Model",
        "Steps the picked model's blend between game frames: default (the custom rule: characters blend with vertices, the rest snaps), snap, vertex, untagged. Shows in the custom blend mode.", SDL_SCANCODE_UNKNOWN, "Interpolation Debug");
    add(GameInput::SAVE_TAGS, "Save Tags",
        "Writes the tagged models to interp_tags.txt in the Dev Files folder next to the save files, to send in for the port's defaults.", SDL_SCANCODE_UNKNOWN, "Interpolation Debug");
    add(GameInput::UNSAVE_TAG, "Unsave Tag",
        "Removes the picked model's tag, from the game and from interp_tags.txt.", SDL_SCANCODE_UNKNOWN, "Interpolation Debug");
    add(GameInput::MODEL_EFFECTS, "Model Effects",
        "Turns the screen effects (ambient occlusion, outlines, fog, bloom and the rest) off and on for the picked model: it is drawn over them as the game draws it. Save Tags keeps it.", SDL_SCANCODE_UNKNOWN, "Interpolation Debug");
    add(GameInput::PARALLAX_PICK, "Parallax Pick Mode",
        "Frees the mouse as a crosshair and highlights the texture under it. Left click steps its parallax shape (then off), right click its depth (Shift + wheel in 10% steps), middle click its shadows; Shift + left click puts it back to the built-in choice and the wheel picks a layer deeper. The Save Pick key writes the one under the cursor to parallax_tags.txt in the Dev Files folder next to the save files and Delete Saved Pick takes it back out.", SDL_SCANCODE_UNKNOWN, "Pick Modes");
    add(GameInput::EFFECTS_PICK, "Shader Effects Pick Mode",
        "Frees the mouse as a crosshair and highlights the texture under it. Left click steps the shader effect it gets: Disable, Grass, Deep Snow, Ice Reflection, Shiny Reflection (Screen-space reflections show only on shiny surfaces, water and ice), Lamp (a lit lamp that Ray tracing lights the scene from), then back to the built-in choice; Shift + left click puts it back at once and the wheel picks a layer deeper. The Save Pick key writes the one under the cursor to shader_effect_tags.txt in the Dev Files folder next to the save files and Delete Saved Pick takes it back out.", SDL_SCANCODE_UNKNOWN, "Pick Modes");
    add(GameInput::INTERP_PICK, "Interpolation Pick Mode",
        "Frees the mouse as a crosshair; the model or character under it is highlighted. Left click steps how it blends between game frames: snap, vertex, untagged, then default; middle click turns its screen effects off or on; Shift + left click puts it back to default. Needs a frame rate above Original. The Save Pick key writes the one under the cursor to interp_tags.txt in the Dev Files folder next to the save files and Delete Saved Pick takes it back out.", SDL_SCANCODE_UNKNOWN, "Pick Modes");
    add(GameInput::MATERIAL_PICK, "Ray Tracing Material Pick Mode",
        "Frees the mouse as a crosshair and highlights the texture under it, for giving it a production PBR material in Graphics > Ray tracing: Albedo (the base colour it is tinted by), Roughness (0 a mirror, 100 a wide brushed lobe), Metalness (0 a plain surface, 100 a metal that reflects in its albedo colour with no diffuse of its own) and Emissive (light it gives off into the traced scene) and Subsurface (light that a lamp or the sun behind it carries through). Left click gives the texture a material or switches its material off (the port ships built-in ones; Shift + left click puts the built-in choice back), middle click steps a preset (Mirror, Brushed metal, Gold, Plastic, Rubber, Glowing, Wax, Leaf), Shift + wheel changes the chosen property (Ctrl for fine steps); right click or keys 1 to 7 choose which, key 8 steps the preset and key 9 is Show All and the wheel alone picks a layer deeper. The Save Pick key writes the one under the cursor to rt_material_tags.txt in the Dev Files folder next to the save files and Delete Saved Pick takes it back out.", SDL_SCANCODE_UNKNOWN, "Pick Modes");
    add(GameInput::PICK_SAVE, "Save Pick",
        "In a pick mode, saves the texture or model under the cursor, only that one, to its file in the Dev Files folder next to the save files.", SDL_SCANCODE_UNKNOWN, "Pick Modes");
    add(GameInput::PICK_DELETE, "Delete Saved Pick",
        "In a pick mode, puts the texture or model under the cursor back to the built-in choice and deletes its save from its file in the Dev Files folder.", SDL_SCANCODE_UNKNOWN, "Pick Modes");
    add(GameInput::PICK_COPY, "Copy Pick",
        "In a pick mode, copies the pick of the texture or model under the cursor.", SDL_SCANCODE_UNKNOWN, "Pick Modes");
    add(GameInput::PICK_PASTE, "Paste Pick",
        "In a pick mode, gives the texture or model under the cursor the copied pick (not saved until you save it).", SDL_SCANCODE_UNKNOWN, "Pick Modes");
    add(GameInput::PICK_UNDO, "Undo Pick",
        "In a pick mode, takes back the last change to a texture or model (clicks, pastes, Shift + wheel depth, Delete Saved Pick), one at a time.", SDL_SCANCODE_UNKNOWN, "Pick Modes");
    add(GameInput::SUN_MOVE, "Move Sun",
        "Hold it and turn the mouse wheel to move the level's sun, for the ray traced light and the sun shadows: the wheel turns it round the compass, Ctrl + wheel raises or lowers it, Shift for fine steps. It stays where you put it until the game closes; Save Sun Location keeps it. With Day and Night on it stands there all day (the moon keeps its own path at night).", SDL_SCANCODE_UNKNOWN, "Ray Trace Debug");
    add(GameInput::SUN_SAVE, "Save Sun Location",
        "Saves where the sun stands in this level to sun.txt in the Dev Files folder next to the save files. The game reads it back at start, and you can send it in for the levels' built-in suns.", SDL_SCANCODE_UNKNOWN, "Ray Trace Debug");
    add(GameInput::VOLUMETRIC_SAVE, "Save Volumetric Settings",
        "Saves the volumetric settings now showing (mist, fog and its preset, cloud type) as this level's line in volumetric.txt in the Dev Files folder next to the save files. They are used for this level from then on, whatever the options say; edit the file to change them.", SDL_SCANCODE_UNKNOWN, "Volumetric");
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

std::string tooie::hotkeys::binding_text(recompinput::GameInput input) {
    std::string text;
    for (int profile : { recompinput::profiles::get_sp_keyboard_profile_index(), recompinput::profiles::get_sp_controller_profile_index() }) {
        if (profile < 0) {
            continue;
        }
        for (size_t b = 0; b < recompinput::num_bindings_per_input; b++) {
            const std::string name = recompinput::profiles::get_input_binding(profile, input, b).to_string();
            if (!name.empty()) {
                text += (text.empty() ? "" : ", ") + name;
            }
        }
    }
    return text;
}
