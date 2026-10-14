#ifndef __TOOIE_FINE_AIM_H__
#define __TOOIE_FINE_AIM_H__

#include <cstdint>
#include <string>

#include "recomp.h"

// Fine aim (src/gameplay/fine_aim.cpp, handoff 4.57): in first person the left stick turns the view
// slower, always or while R is held.
namespace tooie::fine_aim {
    enum class Mode : uint32_t { Off, HoldR, Always };
    enum class Speed : uint32_t { Slow, Medium, Fast };
    inline const std::string mode_option = "fine_aim";
    inline const std::string speed_option = "fine_aim_speed";

    // Call once per frame from the game thread (tooie_warp_tick): reads the player's state.
    void tick(uint8_t* rdram, recomp_context* ctx);
    // Scales player 1's left stick as the game is about to read it. Safe to call more than once per frame.
    void apply(uint16_t buttons, float* x, float* y);
    // Whether Banjo is in first person (as of the last tick).
    bool in_first_person();
}

#endif
