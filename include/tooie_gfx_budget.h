#pragma once

#include <cstdint>

// The game's per-frame drawing memory (src/display/gfx_budget.cpp).
namespace tooie::gfx_budget {
    // True while this frame's display list and matrix buffers have enough left
    // for the game's own drawing, so extras (extended draw distance, HD
    // shadows) may add to them. Call from the game thread while it draws.
    bool room_for_extras(uint8_t* rdram);
    // Call when the frame's display list is complete: logs an overflow.
    void frame_end(uint8_t* rdram);
}
