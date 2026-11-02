#ifndef __TOOIE_ENEMY_SPAWNER_H__
#define __TOOIE_ENEMY_SPAWNER_H__

#include <cstdint>
#include <string>
#include <vector>

#include "recomp.h"

namespace recomp::config {
    class Config;
}

// Enemy spawner (src/gameplay/enemy_spawner.cpp): the Cheats tab's "Enemy spawner" row is a drop-down of
// the game's enemies with a Spawn button beside it; each press spawns the picked enemy in front of Banjo
// through the game's own spawn-by-id (func_80108474, as the test room does).
namespace tooie::enemy_spawner {
    inline const std::string option = "cheat_enemy_spawner";

    // Adds the row to the Cheats tab, hidden while master_option is off.
    void add_options(recomp::config::Config& cheats, const std::string& master_option);

    // The enemies the drop-down lists, by name, and a spawn of one of them by position in that list (developer
    // console). Same as picking it and pressing Spawn: the spawn happens on the next game frame.
    std::vector<std::string> names();
    bool spawn(size_t index);
    // Drops a spawn that is still waiting (the master switch went off).
    void reset();

    // Call once per frame from the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram, recomp_context* ctx);
}

#endif
