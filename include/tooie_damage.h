#ifndef __TOOIE_DAMAGE_H__
#define __TOOIE_DAMAGE_H__

#include <string>

// Enemies do double damage (General > Gameplay) and Cheats > One-hit enemies (src/gameplay/damage_mods.cpp).
namespace tooie::damage {
    inline const std::string double_damage_option = "double_damage";
}

#endif
