#ifndef __TOOIE_MENU_MOUSE_H__
#define __TOOIE_MENU_MOUSE_H__

#include <cstdint>
#include <string>

#include "recomp.h"

namespace recomp::config {
    class Config;
}

// The mouse in the game's own menus (L, 2026-10-19; src/input/menu_mouse.cpp): the pause menu's rows and
// the save select's spots follow the cursor and take a left click as A; a right click is B.
namespace tooie::menu_mouse {
    inline const std::string enabled_option = "menu_mouse";

    inline const std::string free_hand_option = "menu_mouse_free_hand_v3";

    void add_options(recomp::config::Config& qol);

    // Once per frame on the game thread (tooie_warp_tick): works out what is under the cursor.
    void tick(uint8_t* rdram, recomp_context* ctx);

    // From each pad read for player 1: the stick and buttons that move the game's menu there.
    void apply_input(uint16_t* buttons, float* x, float* y);
}

#endif
