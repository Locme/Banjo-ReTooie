#pragma once

// Volumetric mist, fog and clouds (src/gameplay/volumetric.cpp): WIP tab, all off by default. Drawn by the scene effects
// pass (rt64-ext/src/shaders/SceneEffectsPS.hlsl, VolScatter and VolSky).
#include <cstdint>
#include <string>

#include "librecomp/config.hpp"

namespace tooie::volumetric {
    // Mist: ground-hugging banks, a real volume along each pixel's ray (0 off, 100 thickest).
    inline const std::string mist_option = "volumetric_mist";
    // Mist that settles over water and at the foot of a waterfall: strength (0 off, 100 thickest) and how high it hangs
    // (world units), each.
    inline const std::string mist_water_option = "volumetric_mist_water";
    inline const std::string mist_water_height_option = "volumetric_mist_water_height";
    inline const std::string mist_fall_option = "volumetric_mist_fall";
    inline const std::string mist_fall_height_option = "volumetric_mist_fall_height";
    // Fog through the whole scene, from the preset below (0 off, 100 as the preset is designed).
    inline const std::string fog_option = "volumetric_fog";
    // The fog's presets, the settings of Vapor's presets (MIT licence, see notes/third-party/vapor-LICENSE.txt).
    // Order matches kVolAlbedo in SceneEffectsPS.hlsl; new ones go at the end.
    enum class FogPreset : uint32_t { Default, Bright, Hell, Murky, Poison, Sponza, Pillar };
    inline const std::string fog_preset_option = "volumetric_fog_preset";
    // The same settings as Graphics > Fog: how far from Banjo it begins, and its colour (the preset's own, or Haze, Mist, Dusk, Gloom).
    enum class FogColour : uint32_t { Preset, Haze, Mist, Dusk, Gloom };
    inline const std::string fog_start_option = "volumetric_fog_start";
    inline const std::string fog_colour_option = "volumetric_fog_colour";
    // Clouds forced onto the sky of every level without the day and night cycle (or with it: they replace its clouds).
    // The type's number in the shader is the value minus 1 (Fair is 1).
    enum class Clouds : uint32_t { Off, Fair, Scattered, Overcast, Stormy, Wispy, Sunset, Thunderstorm };
    inline const std::string clouds_option = "volumetric_clouds";
    // The cloud shape, each 0 to 100 with 50 the type's own: amount (how much of the sky), height (low enough to sit on the
    // horizon), size (how thick the layer is) and speed.
    inline const std::string cloud_amount_option = "volumetric_cloud_amount";
    inline const std::string cloud_height_option = "volumetric_cloud_height";
    inline const std::string cloud_size_option = "volumetric_cloud_size";
    inline const std::string cloud_speed_option = "volumetric_cloud_speed";
    // Read Dev Files/volumetric.txt: per level mist, fog, cloud type and cloud shape.
    inline const std::string file_option = "volumetric_use_file";

    void add_options(recomp::config::Config& graphics);
    // Once per game frame from tooie_warp_tick (after day_night::tick, which sets its own clouds first).
    void tick(uint8_t* rdram);

    // The Save Volumetric Settings key opens a panel of buttons in the pick worker (src/debug/parallax_pick.cpp), one
    // per setting and Save All, each writing that setting (as showing now) into this level's line of volumetric.txt.
    // 0 cloud type, 1 cloud shape (cover, height, thickness, speed), 2 mist (strength and floor height), 3 fog
    // strength, 4 fog preset.
    constexpr int setting_count = 5;
    const char* setting_name(int setting);
    // Whether this level's line lacks the setting as it is showing now.
    bool setting_unsaved(int setting);
    // Saves one setting, or all of them for -1. False when it could not be written.
    bool save_setting(int setting);
}
