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
}
