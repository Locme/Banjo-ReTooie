#ifndef __TOOIE_ASSET_MODS_H__
#define __TOOIE_ASSET_MODS_H__

#include <cstddef>
#include <filesystem>
#include <functional>
#include <string>

// Asset dump and replacement by id (src/game/asset_mods.cpp, handoff 4.88/4.89): General >
// the DEV tab > Dump assets, and asset_<id>.bin files loaded in place of the game's, from mods/assets
// or from the assets/ folder of a mod that has an assets.json (such as a model mod).
namespace tooie {
    inline const std::string asset_dump_option = "asset_dump";
}

namespace tooie::asset_mods {
    // Call once per frame from the game thread (tooie_warp_tick): starts the dump when it is switched on.
    void tick();

    // The asset mod content type (main.cpp): a mod with an assets.json was switched on or off,
    // or the mod list was reordered. `order` is the mod's place in the mod list.
    void enable_mod(const std::string& mod_id, const std::filesystem::path& root, size_t order);
    void disable_mod(const std::string& mod_id);
    void reorder(const std::function<size_t(const std::string&)>& order_of);
}

#endif
