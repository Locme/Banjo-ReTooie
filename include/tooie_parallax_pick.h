#ifndef __TOOIE_PARALLAX_PICK_H__
#define __TOOIE_PARALLAX_PICK_H__

// Parallax pick mode (src/debug/parallax_pick.cpp): the Parallax Pick Mode key frees the mouse as a crosshair, the
// texture under it is highlighted, and clicks set that texture's parallax: its shape, depth and shadows, or off.
// The picks are kept in parallax_tags.txt in the Dev Files folder next to the save files and override the built-in list
// (parallax_textures[] in picture_filters.cpp), which they can be folded into.
#include <cstdint>
#include <functional>

namespace tooie::parallax_pick {
    // A texture's parallax as picked.
    enum Shape : uint8_t {
        shape_stone = 0,
        shape_bumpy = 1,
        shape_inverted = 2,
        shape_cracks = 3,
        shape_terraced = 4,
        shape_rounded = 5,
        shape_count = 6
    };
    // Depth steps, as RASTER_PARALLAX_DEPTH bits: 100%, 25, 50, 150, 200, 300%.
    constexpr int depth_count = 6;
    struct Pick {
        bool off = false;
        uint8_t shape = shape_stone;
        uint8_t depth = 0;
        bool shadows = true;
        // As SetSceneParallaxTextures takes it: shape, depth << 3, no shadows << 6.
        uint8_t style() const { return uint8_t(shape | (depth << 3) | (shadows ? 0 : 0x40)); }
    };

    // Starts watching the key and the mouse and loads parallax_tags.txt (once).
    void start();
    // Bumped each time a pick changes, so the texture list is rebuilt.
    uint32_t version();
    // Each texture picked, with its pick.
    void for_each(const std::function<void(uint64_t hash, const Pick& pick)>& visit);
}

#endif
