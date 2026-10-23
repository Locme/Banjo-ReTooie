#ifndef __TOOIE_DAMAGE_H__
#define __TOOIE_DAMAGE_H__

#include <cstdint>
#include <string>

#include "recomp.h"

// Enemies do double damage (General > Gameplay) and Cheats > One-hit enemies (src/gameplay/damage_mods.cpp).
namespace tooie::damage {
    inline const std::string double_damage_option = "double_damage";

    // General > Gameplay > Enemy aim (src/gameplay/damage_mods.cpp): how far ahead Klungo's potions aim.
    enum class Aim : uint32_t { Original, Better, Sharp };
    inline const std::string aim_option = "enemy_aim";
    inline const std::string aim_chance_option = "enemy_aim_chance";
    inline const std::string homing_option = "enemy_aim_homing";
    inline const std::string strafe_option = "enemy_strafe";
    inline const std::string faster_attacks_option = "enemy_faster_attacks";
    // Once per frame (tooie_warp_tick): measures the player's movement for Enemy aim.
    void aim_tick(uint8_t* rdram);

    // Whether Take No Damage (Cheato: HONEYKING, game flag 0x53C) is on, read on the game thread. Hits then
    // leave Banjo where he is instead of putting him in the hurt state.
    bool no_damage_on(uint8_t* rdram, recomp_context* ctx);
}

#endif
