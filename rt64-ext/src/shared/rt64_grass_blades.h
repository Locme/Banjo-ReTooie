//
// RT64
//

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_SHARED_RT64_GRASS_BLADES_H
#define RT64_EXT_SHARED_RT64_GRASS_BLADES_H

#include "shared/rt64_hlsl.h"

// Banjo-Tooie: 3D grass (notes/cheap-grass-plan.md). Each grass ground draw's blades are worked out once on the CPU
// (rt64_grass.cpp) and kept for as long as the draw is seen: where each blade stands, its height and look, and which
// of the draw's triangles it stands on and where on it. They are kept in tiles of the world, each tile's blades in
// the order of a random rank, so drawing the first part of a tile draws an even, thinner spread of the same blades.
// Each frame the CPU picks the tiles in view and how many of each one's blades to draw, and every ground draw with
// any draws them with one instanced draw of GRASS_BLADE_VERTICES vertices a blade, straight after itself, with its own
// material (GrassBladeVS.hlsl): the pixel shader colours a blade by the ground under its root, so it takes the
// level's own texture, vertex colours and fog.
//
// The shapes are drawn indexed (GRASS_SHAPE_INDICES, uploaded by the renderer), so a corner shared by two triangles
// is worked out once: SV_VertexID is the corner. A near blade: seven corners (the root's edges and middle, the bend's
// edges and middle, the tip) in six triangles, its middle a raised ridge so the blade reads as rounded; a blade further
// away: one triangle (the root's edges and the tip); a flower or clover: a stem (its three corners) and six diamonds of
// four corners each (a flower's five petals and centre, a clover's six lobes).
#define GRASS_BLADE_VERTICES 18
#define GRASS_BLADE_MID_VERTICES 3
#define GRASS_FLOWER_VERTICES 39
#define GRASS_SHAPE_NEAR_FIRST 0
#define GRASS_SHAPE_MID_FIRST 18
#define GRASS_SHAPE_FLOWER_FIRST 21
// A near blade of a level whose plants need a finer shape (GRASS_PLANT_RIBBON: kelp, ferns, broad leaves): nineteen
// corners, six rows of three up its length (at 0, 0.18, ... 0.9 of it) and the tip, in twenty-two triangles.
#define GRASS_RIBBON_VERTICES 66
#define GRASS_SHAPE_RIBBON_FIRST 60
#define GRASS_SHAPE_INDEX_COUNT 126

// The plants a level grows (FrameParams.grassWater.y; rt64_grass.cpp's SceneGrassLevelLook, GrassBladeVS.hlsl's
// GrassFormOf and FlowerFormOf): meadow grass; seabed kelp and eelgrass; dry grass with ferns among it; stiff dry straw;
// a short mown lawn; frosted spikes; grass with broad jungle leaves among it; long curling dune grass; desert straw;
// rusty industrial weeds; scorched straw by lava; pastel candy grass. Each has two grasses and two flowers of its own.
#define GRASS_PLANT_MEADOW 0
#define GRASS_PLANT_KELP 1
#define GRASS_PLANT_FERN 2
#define GRASS_PLANT_STRAW 3
#define GRASS_PLANT_LAWN 4
#define GRASS_PLANT_FROST 5
#define GRASS_PLANT_JUNGLE 6
#define GRASS_PLANT_DUNE 7
#define GRASS_PLANT_DESERT 8
#define GRASS_PLANT_INDUSTRY 9
#define GRASS_PLANT_LAVA 10
#define GRASS_PLANT_CANDY 11
#define GRASS_PLANT_RIBBON(plant) (((plant) == GRASS_PLANT_KELP) || ((plant) == GRASS_PLANT_FERN) || ((plant) == GRASS_PLANT_JUNGLE))
// RASTER_GRASS_BLADES and RASTER_GRASS_MID (rt64_raster_params.h) mark a blade pass in RasterParams.grassShells.

// A blade's place is kept as where it stands in its tile (GrassTileDraw.origin): across and along in 10 bits each
// over the tile's width (a quarter of a unit), and up in 12 bits over the tile's height range (a quarter of a unit on
// a tile a thousand units high), so a root never floats over or sinks into its ground. Its height, in 12 bits, goes up to this.
#define GRASS_TILE_SIZE 256.0f
// A blade's info.x: its triangle in its draw (20 bits), the way up the ground's slope there (4 bits, a turn in 16ths),
// its kind (4 bits: 0 grass, 1 to 6 a flower's colour, 7 a clover) and how steep the slope is (4 bits, its rise over
// its run in quarters).
// The trodden ground's map (FrameParams.grassPress, the renderer's grassPressCells): GRASS_PRESS_SIZE cells each way of
// GRASS_PRESS_CELL world units, wrapping round, each two words. The first: when it was last trodden (in 1/GRASS_PRESS_TICKS
// of a second, 16 bits), the way its grass was pushed (8 bits, a turn in 256ths), how near the middle of the path it is
// (8 bits, 0 never trodden). The second: the ground's height there (16 bits, signed), which 2048-unit square of the
// world it is in (4 bits x, 4 bits z) and how steeply the ground rises the way the grass was pushed (8 bits, 64ths).
// Banjo's feet press the grass within GRASS_PRESS_RADIUS of the path they take.
#define GRASS_PRESS_SIZE 256
#define GRASS_PRESS_CELL 8.0f
#define GRASS_PRESS_RADIUS 24.0f
#define GRASS_PRESS_TICKS 20.0f
#define GRASS_HEIGHT_MAX 16.0f

#ifdef HLSL_CPU
namespace interop {
#endif
    // A blade, in 16 bytes (a field of millions of them is kept for each level): the triangle of its ground draw it
    // stands on (counted from the draw's first; low 24 bits) and, in the top 8 bits, the colour of the flower it carries
    // (0: none, GrassBladeVS.hlsl's palette from 1); where its root is in its tile (GRASS_TILE_SIZE above: across, along
    // and up in 10, 10 and 12 bits); where on its triangle (two 8-bit barycentric weights, of the first two corners), its
    // turn and lean (8 bits each, 0 to 1 of a turn and of the most lean); and its rank (low 12 bits: 0 to 1, the share of
    // the tile drawn before it is), width (8 bits: 0 to 1 of GrassMaxWidth) and height (top 12 bits: 0 to
    // GRASS_HEIGHT_MAX). (It was 32 bytes with floats; L asked for cheaper grass, 2026-11-13.)
    struct GrassBlade {
        uint4 info;
    };

    // A ground draw's blades this frame: its first tile in the frame's tile list, how many near tiles there are from
    // it, then how many mid-distance tiles after those, and where the draw's triangles start in the index buffer; then
    // how many flower tiles there are after the mid-distance ones.
    struct GrassSlot {
        uint4 info;
        uint4 flowers;
    };

    // A tile drawn this frame: its first blade in the blade buffer, how many of its blades are drawn, where its blades
    // start among the slot's instances, and the share of the tile kept (asfloat: 0 to 1, or 1.15 when it is all drawn
    // and no blade shrinks; GrassBladeVS.hlsl); then the corner its blades' places count from (xyz) and its height
    // range (w).
    struct GrassTileDraw {
        uint4 info;
        float4 origin;
    };
#ifdef HLSL_CPU
};
#endif

#endif // RT64_EXT_SHARED_RT64_GRASS_BLADES_H
