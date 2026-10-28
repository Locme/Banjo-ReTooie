//
// RT64
//

// Banjo-Tooie: a hash of a cell of a grid, for the deep snow's glints and noise.

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_SHADERS_CELLHASH_HLSLI
#define RT64_EXT_SHADERS_CELLHASH_HLSLI

#include "FbRendererCommon.hlsli"

// A hash of a cell of a grid, three values from 0 to 1.
float3 SceneCellHash(float2 cell) {
    uint2 c = uint2(int2(cell) + 0x8000);
    uint h = c.x * 0x8DA6B343u ^ c.y * 0xD8163841u;
    h ^= h >> 13;
    h *= 0x5BD1E995u;
    h ^= h >> 15;
    const uint h2 = h * 0x27D4EB2Du;
    const uint h3 = h2 * 0x165667B1u;
    return float3(h & 0xFFFF, h2 & 0xFFFF, h3 & 0xFFFF) / 65535.0f;
}

#endif // RT64_EXT_SHADERS_CELLHASH_HLSLI
