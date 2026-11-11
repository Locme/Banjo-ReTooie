#ifndef __TOOIE_LEVEL_BOX_H__
#define __TOOIE_LEVEL_BOX_H__

#include <cstdint>
#include <vector>

#include "recomp.h"

// The extent of the current level, measured with the game's own collision (src/gameplay/level_box.cpp).
// Rays are cast straight down on a grid round Banjo; where one meets ground, the grid keeps that height. The box holds
// the ground joined to Banjo's (small gaps allowed), padded by a grid step. The box
// frames an overhead view of the whole level (the console's look overview), and the height grid is there for a
// level map.
namespace tooie::level_box {
    struct Box {
        uint16_t map = 0xFFFF;
        float min[3] = { 0, 0, 0 };
        float max[3] = { 0, 0, 0 };
        int hits = 0;              // grid points with ground joined to Banjo's (the box's)
        // The height grid: cols x rows points, step units apart, the first at (origin_x, origin_z). A point with no
        // ground under it holds no_ground.
        float origin_x = 0, origin_z = 0, step = 0;
        int cols = 0, rows = 0;
        std::vector<float> heights;
        std::vector<uint8_t> in_level; // 1 where the point's ground is joined to Banjo's
    };
    constexpr float no_ground = -1.0e9f;

    // Measures the current map round `centre` (Banjo's position), or gives the box measured before on this map.
    // Runs the game's line test, so it must be called from a game hook with that hook's registers. False when no ray
    // met ground.
    bool measure(uint8_t* rdram, recomp_context* ctx, const float centre[3], Box& out);

    // Writes the box's height grid as a greyscale PGM picture, one pixel a grid point, +z down: the level's ground
    // from dark (low) to white (high), other ground dark grey, no ground black. False when it cannot be written.
    bool save_picture(const Box& box, const char* path);

    // How high a camera over the middle of the box, looking straight down with this vertical field of view (degrees)
    // and picture aspect (width over height), must be for all of the level's ground to be in the picture, each point
    // at its own height, with `margin` (1.1 = a tenth more) to spare.
    float overview_height(const Box& box, float fov, float aspect, float margin);
}

#endif
