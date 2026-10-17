#ifndef __TOOIE_TORCH_ENEMY_H__
#define __TOOIE_TORCH_ENEMY_H__

#include <cstdint>
#include <string>

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

    // DEV > Sound test: plays game sound 0x4000 | n at Banjo when the number changes.
    inline const std::string sound_test_option = "dev_sound_test";
    void add_sound_test_option(recomp::config::Config& dev);

    // Once per frame on the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram, recomp_context* ctx);
}

#endif
