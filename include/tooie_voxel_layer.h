#ifndef __TOOIE_VOXEL_LAYER_H__
#define __TOOIE_VOXEL_LAYER_H__

#include <cstdint>
#include <string>
#include <vector>

#include "recomp.h"

namespace recomp::config {
    class Config;
}

// Gameplay > Voxel Layer (src/gameplay/voxel_layer.cpp, notes/voxel-layer-plan.md): Banjo digs into the level's
// ground and walls with his attacks and eggs. The layer is behind the
// level's own surface, so the level looks and plays as it always did until he strikes it.
namespace tooie::voxel_layer {
    inline const std::string option = "voxel_layer";
    // How much Banjo breaks (percent): his blows' power and reach.
    inline const std::string strength_option = "voxel_strength";
    // How deep the layer behind the level's surface is, in metres, by the level's ground: soft ground (sand, dirt,
    // grass, clay, snow), stone (stone, sandstone, brick, ice) and rock (rock, dark stone, ash rock, gold ore).
    inline const std::string depth_soft_option = "voxel_depth_soft";
    inline const std::string depth_stone_option = "voxel_depth_stone";
    inline const std::string depth_rock_option = "voxel_depth_rock";

    void add_options(recomp::config::Config& general);

    // Once per game frame, from tooie_warp_tick: Banjo's attacks, eggs, falling debris; a map change resets it.
    void tick(uint8_t* rdram, recomp_context* ctx);

    // From tooie_players_draw (inside the 3D scene, after the game's physics): keeps Banjo out of the voxels and adds
    // the voxels to the frame's display list.
    void draw(uint8_t* rdram, recomp_context* ctx);

    // The console's voxel command (docs/console.md). Runs on the game thread. A reply starting "ERR " is an error.
    std::string console(uint8_t* rdram, recomp_context* ctx, const std::vector<std::string>& args);
}

#endif
