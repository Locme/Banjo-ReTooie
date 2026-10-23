#pragma once

// Volumetric mist, fog and clouds (src/gameplay/volumetric.cpp): WIP tab, all off by default. Drawn by the scene effects
// pass (rt64-ext/src/shaders/SceneEffectsPS.hlsl, VolScatter and VolSky).
#include <cstdint>
#include <string>

#include "librecomp/config.hpp"

namespace tooie::volumetric {
    // Mist: ground-hugging banks, a real volume along each pixel's ray (0 off, 100 thickest).
    inline const std::string mist_option = "volumetric_mist";
    // Fog through the whole scene, from the preset below (0 off, 100 as the preset is designed).
    inline const std::string fog_option = "volumetric_fog";
    // The fog's presets, the settings of Vapor's presets (MIT licence, see notes/third-party/vapor-LICENSE.txt).
    // Order matches kVolAlbedo in SceneEffectsPS.hlsl; new ones go at the end.
    enum class FogPreset : uint32_t { Default, Bright, Hell, Murky, Poison, Sponza, Pillar };
    inline const std::string fog_preset_option = "volumetric_fog_preset";
    // Clouds forced onto the sky of every level without the day and night cycle (or with it: they replace its clouds).
    // The type's number in the shader is the value minus 1 (Fair is 1).
    enum class Clouds : uint32_t { Off, Fair, Scattered, Overcast, Stormy, Wispy, Sunset, Thunderstorm };
    inline const std::string clouds_option = "volumetric_clouds";
    // Read Dev Files/volumetric.txt: per level mist, fog, cloud type and cloud shape.
    inline const std::string file_option = "volumetric_use_file";

    void add_options(recomp::config::Config& graphics);
    // Once per game frame from tooie_warp_tick (after day_night::tick, which sets its own clouds first).
    void tick(uint8_t* rdram);
}
