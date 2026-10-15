#ifndef __TOOIE_TEXTURE_SWEEP_H__
#define __TOOIE_TEXTURE_SWEEP_H__

#include <cstdint>
#include <string>

#include "recomp.h"

// Texture dump and texture sweep (src/game/texture_sweep.cpp), General > Developer:
// saves every texture the game draws to texture_dump/ in the app-data folder, for
// making texture packs. The sweep warps through every known map so nobody has to play.
namespace tooie {
    inline const std::string texture_dump_option = "texture_dump";
    enum class TextureDump : uint32_t { Off, WhilePlaying, SweepAllMaps };
}

namespace tooie::texture_sweep {
    // Call once per frame from the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram);
    // Adds the camera turn to the player's buttons while a sweep looks around a map.
    void apply_input(uint16_t* buttons);
    // True while a sweep is warping around, so nothing saves the game meanwhile.
    bool sweeping();
}

#endif
