#ifndef __TOOIE_TRANSFORM_ANYWHERE_H__
#define __TOOIE_TRANSFORM_ANYWHERE_H__

#include <cstdint>
#include <string>

#include "recomp.h"

// Transform anywhere (src/gameplay/transform_anywhere.cpp, L 2026-10-15): QOL option, on by default
// (since 2026-10-19; config.cpp turns a saved "off" on once).
// Once Banjo has jumped in a world's Humba Wumba pool and changed at least once, the Transform key
// changes him into that world's form where he stands, and back, with the game's own spin-up
// transformation. Humba says her line for the form on the 1st, 3rd, 5th... change.
namespace tooie::transform_anywhere {
    inline const std::string option = "transform_anywhere";

    // Names the Transform control and sets its default binding (keyboard T). Call before
    // recompui::config::finalize(), which loads the controls config.
    void register_input();

    // Call once per frame from the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram, recomp_context* ctx);
}

#endif
