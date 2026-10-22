#ifndef __TOOIE_PARALLAX_PICK_H__
#define __TOOIE_PARALLAX_PICK_H__

// Parallax pick mode (src/debug/parallax_pick.cpp): the Parallax Pick Mode key frees the mouse as a crosshair, the
// texture under it is highlighted, and clicks set that texture's parallax: its shape, depth and shadows, or off.
// The picks are kept in parallax_tags.txt in the Dev Files folder next to the save files and override the built-in list
// (parallax_textures[] in picture_filters.cpp), which they can be folded into.
#include <algorithm>
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
        shape_grass = 6,
        shape_wood = 7,
        shape_bark = 8,
        shape_brick = 9,
        shape_dirt = 10,
        shape_metal = 11,
        shape_leaves = 12,
        shape_tiles = 13,
        shape_sand = 14,
        shape_smooth = 15,
        shape_ice = 16,
        shape_count = 17
    };
    // Right click's depth steps: 100%, 25, 50, 150, 200, 300%.
    constexpr int depth_count = 6;
    struct Pick {
        bool off = false;
        uint8_t shape = shape_stone;
        uint8_t depth = 0;
        // Shift + wheel's depth in 10% steps (1 to 31), over depth when not 0.
        uint8_t fine = 0;
        bool shadows = true;
        int depth_percent() const;
        // As SetSceneParallaxTextures takes it: shape's low 3 bits, shape's bit 4 << 3 (RASTER_PARALLAX_SHAPE_TOP), no
        // shadows << 6, shape's bit 3 << 7. The depth goes as fine_depth().
        uint8_t style() const { return uint8_t((shape & 0x7) | ((shape & 0x10) >> 1) | (shadows ? 0 : 0x40) | ((shape & 0x8) << 4)); }
        // The depth in 10% steps (0: 100%), as SetSceneParallaxTextures' fine depths take it; 25% goes as 30%.
        uint8_t fine_depth() const {
            const int percent = depth_percent();
            return (percent == 100) ? 0 : uint8_t(std::clamp((percent + 5) / 10, 1, 31));
        }
    };

    // Starts watching the key and the mouse and loads parallax_tags.txt (once).
    void start();
    // Bumped each time a pick changes, so the texture list is rebuilt.
    uint32_t version();
    // Each texture picked, with its pick.
    void for_each(const std::function<void(uint64_t hash, const Pick& pick)>& visit);
}

#endif
