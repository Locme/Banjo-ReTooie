//
// RT64
//

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_SHARED_RT64_SCENE_EFFECTS_H
#define RT64_EXT_SHARED_RT64_SCENE_EFFECTS_H

#include "shared/rt64_hlsl.h"

// Banjo-Tooie: the sun shadow map (SunShadowMap.hlsli). Its half width in world units is the Sun shadow distance
// setting (SUN_SHADOW_MAP_DEFAULT_HALF before there was one), packed into SceneEffectsCB.shadows.y in steps of
// SUN_SHADOW_MAP_HALF_STEP. The size in texels keeps the default's detail (2048 over 3000) as the square grows, up
// to SUN_SHADOW_MAP_MAX_SIZE; past that each texel covers more ground.
#define SUN_SHADOW_MAP_SIZE 2048
#define SUN_SHADOW_MAP_MAX_SIZE 4096
#define SUN_SHADOW_MAP_DEFAULT_HALF 3000.0f
#define SUN_SHADOW_MAP_HALF_STEP 50.0f
#define SUN_SHADOW_MAP_VIEW_FLAG 1000000.0f
// The far map: a second, coarser square over the whole level (SUN_SHADOW_MAP_FAR_HALF each way round the camera),
// drawn beside the near one in the same depth texture (the near map at x 0, the far one at x = the near map's size).
// Past the near map's edge the shadows come from it. Its half width is larger than the setting can go, which is how
// the map's pass tells the two apart.
#define SUN_SHADOW_MAP_FAR_HALF 24000.0f
#define SUN_SHADOW_MAP_FAR_SIZE 4096
// The far map's middle does not follow the camera: it sits at the camera's place rounded to whole cells of this
// many world units (x and z, at height 0), so the map stays right for many frames and is drawn again only now and
// then (when the camera crosses into another cell, the sun moves or the level may have changed). A power of two, so
// the rounding (x * (1 / cell) + 0.5, then floor) comes out the same on the CPU and in shaders.
#define SUN_SHADOW_MAP_FAR_CELL 8192.0f

// Banjo-Tooie: the traced scene's geometry table (gRayGeometries, 16 bytes an entry): the level's geometries from entry 0,
// the models' from SCENE_RAY_MAX_GEOMETRIES (their instance's custom index), then the ray tracing materials' records from
// SCENE_RAY_MATERIAL_BASE (record 0 is none).
#define SCENE_RAY_MAX_GEOMETRIES 8192u
#define SCENE_RAY_MATERIAL_BASE (2u * SCENE_RAY_MAX_GEOMETRIES)

inline unsigned int SunShadowMapSize(float halfWidth) {
    if (halfWidth > SUN_SHADOW_MAP_FAR_HALF - 1.0f) {
        return (unsigned int)(SUN_SHADOW_MAP_FAR_SIZE);
    }
    // Whole steps of 256 texels, rounded up (without ceil, the same on the CPU and in shaders).
    const float steps = halfWidth / SUN_SHADOW_MAP_DEFAULT_HALF * float(SUN_SHADOW_MAP_SIZE) / 256.0f;
    const unsigned int whole = (unsigned int)(steps);
    const unsigned int wanted = (whole + ((float(whole) < steps) ? 1u : 0u)) * 256u;
    return (wanted < (unsigned int)(SUN_SHADOW_MAP_SIZE)) ? (unsigned int)(SUN_SHADOW_MAP_SIZE) : ((wanted > (unsigned int)(SUN_SHADOW_MAP_MAX_SIZE)) ? (unsigned int)(SUN_SHADOW_MAP_MAX_SIZE) : wanted);
}

#ifdef HLSL_CPU
namespace interop {
#endif
    // Banjo-Tooie: screen-space effects drawn over the 3D world before the HUD (SceneEffectsPS.hlsl).
    struct SceneEffectsCB {
        // The projection's depth terms: ndc z = (a * z + b) / (c * z + d) for a view-space z. The depth is
        // the projected z / w, in [0, 1] over the 3D world.
        float4 depthTerms;
        // The projection's x and y scales, then the target's width and height.
        float4 projection;
        // Ambient occlusion strength (0 off, 1 strongest), its radius in world units, unused, then the rim light strength (0 off, 1 strongest).
        float4 ambientOcclusion;
        // Fog strength (0 off, 1 the most), the distance it starts at, the distance over which it
        // thickens, then the underwater tint (0 off: not under water, 1 strongest).
        float4 fog;
        // The fog's color (rgb), then the outlines: 0 off, else strength (0 to 1, above 0) + 2 * (thickness - 1)
        // for a thickness of 1 to 4.
        float4 fogColor;
        // The debug view (0 none, 1 the effects alone as grey, 2 depth, 3 normals, 4 water mask), the day and night
        // cycle's cloud shape packed with F8 compare (see PackSceneClouds), a time in seconds, then the heat haze (0 off,
        // 1 strongest; 2 + strength when it only rises above warm surfaces).
        float4 view;
        // Water reflections strength (0 off), 1 when the water mask was drawn this frame (2: and Modern water draws
        // the water, from the mask and its colours), bounce light (0 off, 1 strongest), then the water waves'
        // strength (0 off, 1 strongest).
        float4 water;
        // Bloom strength (0 off), depth of field strength (0 off, 1 strongest; negative: focused on Banjo), eye adaptation strength
        // (0 off, 1 strongest), then the underwater haze (0 to 1).
        float4 bloom;
        // A view-space position's world x and z: dot(position, xyz) + w. Lets the water waves stay in place.
        float4 worldX;
        float4 worldZ;
        // The same for world y: its xyz is also the normal of level ground, in view space.
        float4 worldY;
        // The light shafts' sun: its direction in view space (towards it), then the strength (0 off, 1 strongest).
        // While the day and night cycle is on, w is negative: -(1 + the moon's phase (0 to 7) * 131072 + 65536
        // when it snows + rain (0 to 255) * 256 + the shafts' strength (0 to 255) + the lightning (0 to 0.99)).
        float4 sun;
        // Banjo's ripples: three rings' world x, world z and age in seconds (below 0 for none) in xyz; the w
        // components hold Banjo's world x, z and y (y below -1e8 when there is no Banjo), for the fog.
        float4 rippleX;
        float4 rippleZ;
        float4 rippleAge;
        // Sun shadows: strength (0 off, 1 strongest), how far towards the sun a shadow is looked for in world
        // units, the day and night cycle's tint of the 3D world (0 off, else 1 + its three channels in 7 bits
        // each, steps of 0.01, then three flags, bit 0 fireflies, bit 1 clouds, bit 2 northern lights: exact as a float below 2^24; negative for no lens
        // flare), then the softness (0 to 0.99) plus 2 to leave Banjo's own shadow out, plus 4 * (the day and night cycle's
        // mist strength (0 to 100) + 128 * when it shows (0 mornings, 1 mornings and nights, 2 always) + 512 * how wet the
        // ground is (0 to 31) + 16384 when raindrops land on the screen). The reach is negative when the sun
        // shadow map was drawn this frame.
        float4 shadows;
    };
#ifdef HLSL_CPU
    // Push constants: Vulkan guarantees only 256 bytes (NVIDIA allows no more), and going over can lose the device.
    static_assert(sizeof(SceneEffectsCB) <= 256, "SceneEffectsCB is bigger than the 256 bytes of push constants");
#endif

    // Banjo-Tooie: the bloom passes (BloomPS.hlsl): the source's texel size, the pass (0 bright parts at a
    // quarter of the size, 1 blur across, 2 blur down, 3 measure the average brightness, 4 move the adapted
    // brightness towards it, 5 down to an eighth, 6 the quarter and eighth glows together), then the brightness threshold (0 to 1), or for pass 4 how far to move (0 to 1).
    // Pass 7 is Modern water's ripple simulation on a grid round the player (height, speed per cell): params.y
    // is unused, waterSim holds how many cells the grid moved since the last step (x, z: read from there), then
    // the player in grid cells, and waterPush how hard the player pushes the water down this step, over how
    // many cells, a splash's extra push, then how much of each cell's movement is kept per step.
    struct BloomCB {
        float4 params;
        float4 waterSim;
        float4 waterPush;
    };
#ifdef HLSL_CPU
};
#endif

#endif // RT64_EXT_SHARED_RT64_SCENE_EFFECTS_H
