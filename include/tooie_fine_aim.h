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
    // Whether Banjo is in first person (as of the last tick).
    bool in_first_person();
}

#endif
