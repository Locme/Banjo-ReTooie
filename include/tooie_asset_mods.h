#ifndef __TOOIE_ASSET_MODS_H__
#define __TOOIE_ASSET_MODS_H__

#include <string>

// Asset dump and replacement by id (src/game/asset_mods.cpp, handoff 4.88/4.89): General >
// the DEV tab > Dump assets, and asset_<id>.bin files in mods/assets loaded in place of the game's.
namespace tooie {
    inline const std::string asset_dump_option = "asset_dump";
}

namespace tooie::asset_mods {
    // Call once per frame from the game thread (tooie_warp_tick): starts the dump when it is switched on.
    void tick();
}

#endif
