#pragma once

// Volumetric shadows (src/gameplay/volumetric_shadows.cpp): WIP tab, off by default. Light in a thin haze with the scenery's
// shadows cut out of it, from the sun and from the nearest lamps. Drawn by rt64-ext/src/render/rt64_volumetric_shadows.cpp
// with its own maps and passes: it doesn't use the sun shadows or ray tracing.
#include <string>

#include "librecomp/config.hpp"

namespace tooie::volumetric_shadows {
    // The sun's shafts (0 off, 100 strongest).
    inline const std::string sun_option = "volumetric_shadows_sun";
    // The lamps' glow (0 off, 100 strongest) and how many of the nearest lamps have it (1 or 2).
    inline const std::string lamps_option = "volumetric_shadows_lamps";
    inline const std::string lamp_count_option = "volumetric_shadows_lamp_count";
    // How thick the haze the light shows in is (1 to 100).
    inline const std::string haze_option = "volumetric_shadows_haze";
    // The light's map and the shafts' detail.
    enum class Quality : uint32_t { Low, Medium, High };
    inline const std::string quality_option = "volumetric_shadows_quality";
    // How far round the camera the sun's shafts reach, in world units.
    inline const std::string distance_option = "volumetric_shadows_distance";

    void add_options(recomp::config::Config& graphics);
    // Once per game frame from tooie_warp_tick.
    void tick();
    // Whether the sun's shafts are on, and how far round the camera they need the world drawn (0 when off): the culling
    // hooks keep what is off screen within it, as it can still stand in the sun's way (src/game/widescreen.cpp).
    float sun_distance();
    // Whether the lamps' glow is on: the level's lights are sent to the renderer then (src/gameplay/hd_shadows.cpp).
    bool lamps_on();
}
