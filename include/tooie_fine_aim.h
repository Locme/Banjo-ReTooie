#ifndef __TOOIE_FINE_AIM_H__
#define __TOOIE_FINE_AIM_H__

#include <cstdint>
#include <string>

#include "recomp.h"

// Fine aim (src/gameplay/fine_aim.cpp, handoff 4.57): in first person the left stick turns the view
// slower, always or while the Fine Aim key (Controls tab, Hotkeys) is held.
namespace tooie::fine_aim {
    enum class Mode : uint32_t { Off, HoldKey, Always };
    enum class Speed : uint32_t { Slow, Medium, Fast };
    inline const std::string mode_option = "fine_aim";
    inline const std::string speed_option = "fine_aim_speed";

    // Adds the Fine Aim key to the Controls tab (R / right trigger by default).
    void register_input();
    // Call once per frame from the game thread (tooie_warp_tick): reads the player's state.
    void tick(uint8_t* rdram, recomp_context* ctx);
    // How much of the game's own first-person turning to keep this frame: 1 when fine aim is off
    // or not held, else 0.25, 0.4 or 0.6. Game thread only.
    float view_scale();
    // Whether Banjo is in first person (as of the last tick): state 152 entered with C-up held just before.
    bool in_first_person();
    // The game's first-person shooter sections (Targitzan's Temple and the like): states 202 (walking), 209, 210 and 216 (firing), where
    // the stick walks and turns the view. Not first person above, which is C-up's look-around (state 152).
    bool in_shooter();
    // Whether the game has Banjo, not the player (a scripted walk or puzzle, talking, a cutscene, dead), as
    // of the last tick. False in first person. The free camera leaves the game's camera alone then.
    bool game_has_player();
    // Controller 1's N64 buttons on each pad read (from src/gameplay/free_camera.cpp's apply_input), for
    // the C-up that starts first person. Pad thread.
    void note_buttons(uint16_t buttons);
}

#endif
