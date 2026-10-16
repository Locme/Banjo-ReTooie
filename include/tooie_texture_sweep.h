#ifndef __TOOIE_TEXTURE_SWEEP_H__
#define __TOOIE_TEXTURE_SWEEP_H__

#include <cstdint>
#include <string>

#include "recomp.h"
#include "librecomp/config.hpp"

// Texture dump and texture sweep (src/game/texture_sweep.cpp), DEV tab:
// saves every texture the game draws to texture_dump/ in the app-data folder, for
// making texture packs. The sweep warps through every known map so nobody has to play.
namespace tooie {
    inline const std::string texture_dump_option = "texture_dump";
    enum class TextureDump : uint32_t { Off, WhilePlaying, SweepAllMaps };
}

namespace tooie::texture_sweep {
    // Call once per frame from the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram);
    // Asks "Start the texture sweep?" when Sweep all maps is picked in the menu.
    void add_prompt(recomp::config::Config& config);
    // Adds the camera turn to the player's buttons while a sweep looks around a map.
    void apply_input(uint16_t* buttons);
    // True while a sweep is warping around, so nothing saves the game meanwhile.
    bool sweeping();
}

#endif
