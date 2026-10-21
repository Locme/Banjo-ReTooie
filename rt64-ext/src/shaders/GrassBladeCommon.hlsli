//
// RT64
//

// Banjo-Tooie: what instanced 3D grass's culling pass (GrassCullCS.hlsl) and its blades' vertex shader
// (GrassBladeVS.hlsl) share. FrParams must be declared before this is included.

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_SHADERS_GRASSBLADECOMMON_HLSLI
#define RT64_EXT_SHADERS_GRASSBLADECOMMON_HLSLI

#define GRASS_MAX_LEVEL 8

float GrassHash1(float3 p) {
    uint3 c = uint3(int3(p) + 0x8000);
    uint h = c.x * 0x8DA6B343u ^ c.y * 0xD8163841u ^ c.z * 0xCB1AB31Fu;
    h ^= h >> 13;
    h *= 0x5BD1E995u;
    h ^= h >> 15;
    return float(h & 0xFFFFu) / 65535.0f;
}

float4 GrassHash4(float3 p) {
    return float4(GrassHash1(p), GrassHash1(p + 101.0f), GrassHash1(p + 211.0f), GrassHash1(p + 307.0f));
}

// Smooth value noise, for the wind and the patches.
float GrassNoise(float2 p) {
    const float2 i = floor(p);
    const float2 f = frac(p);
    const float2 u = f * f * (3.0f - 2.0f * f);
    const float a = GrassHash1(float3(i, 7.0f));
    const float b = GrassHash1(float3(i + float2(1.0f, 0.0f), 7.0f));
    const float c = GrassHash1(float3(i + float2(0.0f, 1.0f), 7.0f));
    const float d = GrassHash1(float3(i + float2(1.0f, 1.0f), 7.0f));
    return lerp(lerp(a, b, u.x), lerp(c, d, u.x), u.y);
}

// How much grass grows at a point: 1 inside a patch, falling to 0 over its soft edge and outside it.
float GrassPatch(float2 xz) {
    const float4 patches = FrParams.grassPatches;
    if (patches.x >= 0.999f) {
        return 1.0f;
    }

    const float2 p = xz / patches.y;
    const float n = GrassNoise(p + 41.0f) * 0.7f + GrassNoise(p * 2.6f + 97.0f) * 0.3f;
    const float threshold = lerp(0.8f, 0.2f, patches.x);
    return smoothstep(threshold, threshold + 0.1f, n);
}

// A world position in the grid's plane (0: x and z, 1: z and y, 2: x and y).
float2 GrassPlane(float3 world, uint plane) {
    return (plane == 0) ? world.xz : ((plane == 1) ? world.zy : world.xy);
}

float4 GrassToClipWith(float4 rows[4], float3 world) {
    const float4 w = float4(world, 1.0f);
    return float4(dot(rows[0], w), dot(rows[1], w), dot(rows[2], w), dot(rows[3], w));
}

float4 GrassToClip(float3 world) {
    const float4 w = float4(world, 1.0f);
    return float4(dot(FrParams.grassWorldToClip[0], w), dot(FrParams.grassWorldToClip[1], w), dot(FrParams.grassWorldToClip[2], w), dot(FrParams.grassWorldToClip[3], w));
}

float4 GrassDirToClip(float3 dir) {
    const float4 d = float4(dir, 0.0f);
    return float4(dot(FrParams.grassWorldToClip[0], d), dot(FrParams.grassWorldToClip[1], d), dot(FrParams.grassWorldToClip[2], d), dot(FrParams.grassWorldToClip[3], d));
}

// The grid's level for a distance from the camera: one more for every doubling past the near distance.
uint GrassDistanceLevel(float distanceToCamera) {
    return uint(min(max(floor(log2(max(distanceToCamera, 1.0f) / FrParams.grassBlades.x)), 0.0f), float(GRASS_MAX_LEVEL)));
}

// Every blade belongs to a cell of the finest grid and never moves. A cell of a coarser level shows the blade of
// one of its four cells a level finer, picked by a hash of the coarse cell (so every blade a coarse level shows,
// every finer level shows too): moving nearer only adds blades and moving away only takes them away.
float2 GrassQuadrant(float2 coarse, uint level) {
    const uint q = min(uint(GrassHash1(float3(coarse, 613.0f + float(level))) * 4.0f), 3u);
    return float2(float(q & 1u), float(q >> 1u));
}

float2 GrassFinestCell(float2 coarse, uint level) {
    float2 c = coarse;
    for (uint l = level; l > 0; l--) {
        c = c * 2.0f + GrassQuadrant(c, l);
    }
    return c;
}

// The cell of a coarser level that holds a cell of this level.
float2 GrassCoarseCell(float2 cell, uint level, uint coarser) {
    float2 c = cell;
    for (uint l = level; l < coarser; l++) {
        c = floor(c * 0.5f);
    }
    return c;
}

// Whether the blade a cell of this level shows is still shown at a coarser level.
bool GrassShownAt(float2 coarse, uint level, uint coarser) {
    float2 c = coarse;
    for (uint l = level + 1; l <= coarser; l++) {
        const float2 parent = floor(c * 0.5f);
        if (any(GrassQuadrant(parent, l) != (c - parent * 2.0f))) {
            return false;
        }
        c = parent;
    }
    return true;
}

// A blade's shape: s across it (-1 to 1 at the root), t up it (0 root, 1 tip). The spine runs from the root through
// the middle (t 0.55, where the blade is 0.75 as wide) to the tip; a chunky blade is one straight triangle.
float3 GrassBladePoint(float s, float t, bool chunky, float3 side, float3 middle, float3 tip) {
    const float3 spine = chunky ? tip * t : ((t < 0.55f) ? middle * (t / 0.55f) : lerp(middle, tip, (t - 0.55f) / 0.45f));
    return spine + side * s;
}

#endif // RT64_EXT_SHADERS_GRASSBLADECOMMON_HLSLI
