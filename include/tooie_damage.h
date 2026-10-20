#ifndef __TOOIE_DAMAGE_H__
#define __TOOIE_DAMAGE_H__

#include <cstdint>
#include <string>

#include "recomp.h"

// Enemies do double damage (General > Gameplay) and Cheats > One-hit enemies (src/gameplay/damage_mods.cpp).
namespace tooie::damage {
    inline const std::string double_damage_option = "double_damage";

    // Whether Take No Damage (Cheato: HONEYKING, game flag 0x53C) is on, read on the game thread. Hits then
    // leave Banjo where he is instead of putting him in the hurt state.
    bool no_damage_on(uint8_t* rdram, recomp_context* ctx);
}

#endif
