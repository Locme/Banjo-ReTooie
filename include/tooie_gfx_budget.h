#pragma once

#include <cstdint>

#include "recomp.h"

// The game's per-frame drawing memory (src/display/gfx_budget.cpp).
namespace tooie::gfx_budget {
    // True while this frame's display list and matrix buffers have enough left
    // for the game's own drawing, so extras (extended draw distance, HD
    // shadows) may add to them. Call from the game thread while it draws.
    bool room_for_extras(uint8_t* rdram);
    // How full the last completed frame's display list was (0 to 1, 0 before the first).
    float last_list_fraction();
    // Call when the frame's display list is complete: logs an overflow.
    void frame_end(uint8_t* rdram);
    // Call at the entry of each model draw (func_800DE498): counts it for the
    // report written when the list gets full.
    void note_model(uint8_t* rdram, recomp_context* ctx);
    // Call once func_800DE498 has settled on the model asset it draws (0x10C($sp) at 0x800DE774).
    void note_model_kind(uint8_t* rdram, uint32_t model);
    // The bytes frame interpolation's tags added this frame: part 0 the 3D scene, 1 the 2D.
    void note_tags(int part, uint32_t bytes);
}
