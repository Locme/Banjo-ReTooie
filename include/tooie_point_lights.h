#pragma once

// Point Lights (src/gameplay/point_lights.cpp, docs/point-lights.md): WIP tab, off by default. Lamps light what is
// near them, per pixel on the GPU, on top of the light the game gives it (rt64-ext rt64_scene_lights.h).
#include <cstdint>
#include <string>
#include <vector>

#include "librecomp/config.hpp"

namespace tooie::point_lights {
    inline const std::string option = "point_lights";
    // How strong the lamps' light is, in percent (100 = as set in the list).
    inline const std::string strength_option = "point_lights_strength";

    void add_options(recomp::config::Config& graphics);
    // Once per game frame from tooie_warp_tick: the lamps and the camera to RT64.
    void tick(uint8_t* rdram);
    // The console's lights command (src/game/console.cpp): its words after "lights"; returns what to print.
    std::string console(uint8_t* rdram, const std::vector<std::string>& args);
}
