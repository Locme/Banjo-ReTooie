//
// RT64 extension: Point Lights (WIP tab, src/gameplay/point_lights.cpp, docs/point-lights.md).
//
// Banjo-Tooie draws nothing with the N64's hardware lighting: every vertex carries a colour the game lit on the CPU
// (0 lit vertices in Wooded Hollow and Mayahem Temple, Banjo included), so the lamps can't go in as RSP lights the way
// the Mario Party 3 port does it. Lighting the vertex colours instead lit only what the game left dark: much of the
// level is drawn at full vertex colour with the colour in its texture, and the colour combiner wraps a shade above
// full rather than holding it. So the lamps light the finished picture, per pixel, in the scene effects pass
// (SceneEffectsPS.hlsl PointLampsAt): each pixel's world position and facing from the depth, its colour brightened
// by the lamps near it, the way the traced lamps' light is added there.
//
// The lamps: the lit lamps the renderer found by their textures the frame before (the same ones the traced lights use,
// SetSceneLampLights), and the level's list from the port (lamps placed with the console). The game's own lights
// (Glowbos, torches) are left out: the game lights the vertices round them itself already.
//
// Written for this port on RT64 (https://github.com/rt64/rt64), after the Mario Party 3 port's Point Lights.
//

#pragma once

#include <cstdint>

namespace RT64 {
    // Lamps lit at once, the nearest the camera.
    constexpr uint32_t ScenePointLightMax = 8;

    struct ScenePointLamp {
        float x, y, z;
        float radius;  // the light is gone here
        float r, g, b; // 0 to 1, already times the strength
    };

    // The switch and the strength (1 = as set in the lamp list), from the port. Off by default.
    void SetScenePointLights(bool enabled, float strength);
    bool ScenePointLights();
    // The level's own list (world space) and where the camera is, from the port once a game frame.
    void SetScenePointLamps(const ScenePointLamp *lamps, uint32_t count, const float camera[3]);
    // The lit lamps the renderer found by their textures (four floats each: x, y, z, reach), once a frame.
    void SetScenePointTextureLamps(const float *xyzr, uint32_t count);
    // The scene effects pass: the lamps for this frame, nearest the camera first; returns how many (0 to ScenePointLightMax).
    uint32_t ScenePointLampsForFrame(ScenePointLamp *out);
};
