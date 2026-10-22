//
// RT64
//

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_SHARED_RT64_GRASS_INSTANCES_H
#define RT64_EXT_SHARED_RT64_GRASS_INSTANCES_H

#include "shared/rt64_hlsl.h"

// Banjo-Tooie: 3D grass drawn with GPU instancing (as in MangoButtermilch's Unity-Grass-Instancer, MIT). The CPU hands
// over the grass ground's triangles near the camera, grouped into world chunks; a compute pass (GrassCullCS.hlsl) works
// out the blades each one grows, drops those out of view (frustum culling) and those hidden behind what last frame drew
// in front of them (occlusion culling, against GrassHiZCS.hlsl's depth pyramid), and packs what is left per ground draw.
// Each ground draw then draws its blades as one instanced draw (GrassBladeVS.hlsl, 9 vertices a blade).
#define GRASS_CULL_GROUP 64
// The depth pyramid: its fine level keeps the farthest depth of each 8 x 8 pixels, its coarse level of each 8 x 8 of those.
#define GRASS_HIZ_FINE 8
#define GRASS_HIZ_COARSE 8
// FrameParams.grassCull.x.
#define GRASS_CULL_FRUSTUM 0x1u
#define GRASS_CULL_OCCLUSION 0x2u
#define GRASS_CULL_CHUNKS 0x4u
// GrassTriangle.info.x: the grid's level (bits 0 to 3), its plane (4 and 5), and grass along its edges (6).
#define GRASS_TRIANGLE_EDGES 0x40u
// The vertices of one blade (three triangles; a chunky blade uses the first).
#define GRASS_BLADE_VERTICES 9
// Banjo-Tooie: Graphics > Ray tracing: the culling pass also writes the blades it kept near the camera as triangles
// (GRASS_BLADE_VERTICES world positions each, float4) for the traced effects' structures (BuildSceneBVH), at most this
// many blades; their count is the last uint of the slot counts. Unused blades' corners are NaN (no triangle).
#define GRASS_RAY_BLADES 131072u

#ifdef HLSL_CPU
namespace interop {
#endif
    // A triangle of grass ground (world positions: level ground has no model transform).
    struct GrassTriangle {
        // The corners (w: the triangle's distance from the camera, for the first).
        float4 p0;
        float4 p1;
        float4 p2;
        // The corners' vertex indices (for their texture coordinates and colours) and the ground draw's slot.
        uint4 vertices;
        // Level, plane and edges (GRASS_TRIANGLE_EDGES), its chunk, its first candidate blade and its grid's cells along a row.
        uint4 info;
        // The grid's first cell (x and y in its plane), then its cell count.
        float4 first;
    };

    // A chunk of grass ground: the box its blades can reach into.
    struct GrassChunk {
        float4 low;
        float4 high;
    };

    // A ground draw with blades: where its blades start in the blade buffer and how many there can be at most, then the
    // screen scale and offset its draw has (RasterParams).
    struct GrassSlot {
        uint4 info;
        float4 screen;
    };

    // A blade that is drawn: its root (w: its height), turn, width and rise, the ground's texture coordinates there and
    // its lean, then the ground's colours there (half floats: smooth red and green, blue and alpha, flat red and green,
    // flat blue and the level-of-detail thinning).
    struct GrassBladeInstance {
        float4 root;
        float4 shape;
        float4 uvBend;
        uint4 colors;
    };

    struct GrassCullCB {
        uint triangleCount;
        uint candidateCount;
        uint chunkCount;
        uint slotCount;
        // The ray-traced blades: how many there can be (0: none) and how far from the camera they go.
        uint rayBlades;
        float rayReach;
        uint pad0;
        uint pad1;
    };

    struct GrassHiZCB {
        uint2 sourceSize;
        uint2 targetSize;
    };
#ifdef HLSL_CPU
};
#endif

#endif // RT64_EXT_SHARED_RT64_GRASS_INSTANCES_H
