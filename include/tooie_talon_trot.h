#ifndef __TOOIE_TALON_TROT_H__
#define __TOOIE_TALON_TROT_H__

#include <cstdint>
#include <string>

#include "recomp.h"

// Talon Trot toggle (src/gameplay/talon_trot.cpp, handoff 4.54): in Toggle mode the trot started with
// Z + C-left keeps going after Z is let go, until Z or C-left is pressed again.
namespace tooie::talon_trot {
    enum class Mode : uint32_t { Hold, Toggle };
    inline const std::string mode_option = "talon_trot";

    // Call once per frame from the game thread (tooie_warp_tick): reads the player's state.
    void tick(uint8_t* rdram, recomp_context* ctx);
    // Applies the toggle to player 1's buttons as the game is about to read them. Safe to call more
    // than once per frame.
    void apply(uint16_t* buttons);
}

#endif
