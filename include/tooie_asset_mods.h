#ifndef __TOOIE_ASSET_MODS_H__
#define __TOOIE_ASSET_MODS_H__

#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <functional>
#include <span>
#include <string>
#include <vector>

// Asset dump and replacement by id (src/game/asset_mods.cpp, handoff 4.88/4.89): General >
// the DEV tab > Dump assets, and asset_<id>.bin files loaded in place of the game's, from mods/assets
// or from the assets/ folder of a mod that has an assets.json (such as a model mod).
namespace tooie {
    inline const std::string asset_dump_option = "asset_dump";
}

namespace tooie::asset_mods {
    // Call once per frame from the game thread (tooie_warp_tick): starts the dump when it is switched
    // on, and reloads the area after an asset mod was switched on or off.
    void tick(uint8_t* rdram);

    // The asset mod content type (main.cpp): a mod with an assets.json was switched on or off,
    // or the mod list was reordered. `order` is the mod's place in the mod list.
    void enable_mod(const std::string& mod_id, const std::filesystem::path& root, size_t order);
    void disable_mod(const std::string& mod_id);
    void reorder(const std::function<size_t(const std::string&)>& order_of);

    // Asset `id` as the game loads it now: an asset mod's file when one replaces it, else decompressed from the
    // ROM. Empty when it can't be read.
    std::vector<uint8_t> asset_bytes(uint32_t id);
    // Asset `id` from the ROM, whatever replaces it.
    std::vector<uint8_t> rom_asset_bytes(uint32_t id);
    // Asset `id` from the given ROM image (such as the stored ROM read before the game has started).
    std::vector<uint8_t> rom_asset_bytes(std::span<const uint8_t> rom, uint32_t id);
    // Asset `id`'s kind in the ROM's table (the low 4 bits of its word: 0 a model), or -1 for no such asset. The
    // ROM must be loaded (the game started).
    int asset_kind(uint32_t id);
}

#endif
