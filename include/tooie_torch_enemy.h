#ifndef __TOOIE_TORCH_ENEMY_H__
#define __TOOIE_TORCH_ENEMY_H__

#include <cstdint>
#include <string>

#include <vector>
#include "recomp.h"

namespace recomp::config {
    class Config;
}

// Cut Content: Torch enemy (src/gameplay/torch_enemy.cpp). The angry torch cut from Glitter Gulch Mine
// (actor 0x2AE, overlay chstatictorch), brought back in the Flooded Caves: it lights up the dark around it,
// chases Banjo when he comes near and lunges to burn him.
namespace tooie::torch_enemy {
    inline const std::string option = "cut_torch_enemy";

    void add_option(recomp::config::Config& general);

    // Once per frame on the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram, recomp_context* ctx);

    // Maps whose setup places the actor, best match first. The 0x14-byte prop entries are read without
    // knowing where the list starts: the id (a halfword) is searched at every position, grouped by position
    // modulo 0x14, and the map's count is that of its commonest group. Used by the Aim sweep, which warps
    // there to spawn enemies that only work where they live.
    std::vector<uint16_t> maps_placing(uint8_t* rdram, recomp_context* ctx, uint16_t actor_id);
}

#endif
