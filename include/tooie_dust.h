#pragma once

// Volumetric dust (src/gameplay/dust.cpp): Graphics > WIP > Volumetrics. Replaces the textured puffs of the run, sprint,
// Talon Trot, quick turn, landing and skid dust with small clouds the scene effects pass draws as part of its volumetric march
// (rt64-ext/src/shaders/SceneEffectsPS.hlsl, VolDust).
#include <cstdint>
#include <string>

#include "librecomp/config.hpp"

namespace tooie::dust {
    inline const std::string option = "volumetric_dust";

    void add_options(recomp::config::Config& graphics);
    // Once per game frame from tooie_warp_tick (after volumetric::tick): moves the clouds and hands them to the renderer.
    void tick(uint8_t* rdram);
    // How many dust triggers there have been since the last call (puffs made within 0.75 s of one count are one), for the
    // character surface layer's dirt, 5% each (picture_filters.cpp). Counted with the option off too: the game's own puffs
    // dirty him just the same.
    float take_exposure();
}
