//
// RT64
//

// Banjo-Tooie: the Voxel Layer's cut cells (src/gameplay/voxel_layer.cpp, RT64::SetSceneVoxelCuts). Banjo digs into
// the level's ground and walls; where he has, the level's own surface is left out and the cells' faces, drawn by the
// game, show instead. The cells are 18 units, square to the world's axes, in a hash table of four words a slot (x, y,
// z, 1 when used) after a header of twelve (slot count, a power of 2 or 0; cells; 0; 0; the lowest cell's x, y, z; 0;
// the highest cell's x, y, z; 0).
//
// A point of the level's surface is over a cut cell when the cell a cell's size behind it is cut (a solid cell is all
// behind the surface, at most a cell under it). The surface's normal from screen slopes can point either way, so
// both sides are tried: the cell in front of a surface is never cut (cut cells are behind the level's surfaces), so
// the one in front never answers by mistake.

#pragma once
#ifndef RT64_EXT_SHADERS_VOXEL_CUTS_HLSLI
#define RT64_EXT_SHADERS_VOXEL_CUTS_HLSLI

static const float VoxelCellSize = 18.0f;

bool VoxelCellCut(StructuredBuffer<uint> cuts, int3 cell) {
    const uint slots = cuts[0];
    if (slots == 0u) {
        return false;
    }
    const uint mask = slots - 1u;
    uint h = ((uint(cell.x) * 73856093u) ^ (uint(cell.y) * 19349663u) ^ (uint(cell.z) * 83492791u)) & mask;
    [loop]
    for (uint k = 0u; k < 32u; k++) {
        const uint b = 12u + h * 4u;
        if (cuts[b + 3u] == 0u) {
            return false;
        }
        if ((int(cuts[b]) == cell.x) && (int(cuts[b + 1u]) == cell.y) && (int(cuts[b + 2u]) == cell.z)) {
            return true;
        }
        h = (h + 1u) & mask;
    }
    return false;
}

// How much of a point's row of cells is cut round it: the row of cells a cell's size along the normal's main axis
// (side: -1 or 1), and in that row the four cells nearest the point blended by its place among their middles, so
// the edge of a cut curves between the cells' middles instead of following their square sides (L, 2026-11-13: "less
// sharp squares"); the smooth surface drawn there (src/gameplay/voxel_layer.cpp) meets it near the same curve.
float VoxelRowCut(StructuredBuffer<uint> cuts, float3 world, uint axis, float side) {
    float3 q = world;
    q[axis] += side * VoxelCellSize;
    const uint t1 = (axis + 1u) % 3u, t2 = (axis + 2u) % 3u;
    const float3 f = q / VoxelCellSize - 0.5f;
    const float2 g = float2(f[t1], f[t2]);
    const float2 g0 = floor(g);
    const float2 w = g - g0;
    int3 cell;
    cell[axis] = int(floor(q[axis] / VoxelCellSize));
    // Never past the cut cells: the cell the point is over must be cut itself. Otherwise, at a hole's inner corner
    // (three cut cells round one that isn't), the blend reaches into the corner of the whole cell, whose surface then
    // goes while nothing is drawn behind it, and the empty inside of the world shows (L, 2026-11-13).
    cell[t1] = int(floor(q[t1] / VoxelCellSize));
    cell[t2] = int(floor(q[t2] / VoxelCellSize));
    if (!VoxelCellCut(cuts, cell)) {
        return 0.0f;
    }
    float sum = 0.0f;
    uint count = 0u;
    [unroll] for (int k = 0; k < 4; k++) {
        const int2 o = int2(k & 1, k >> 1);
        cell[t1] = int(g0.x) + o.x;
        cell[t2] = int(g0.y) + o.y;
        const float weight = ((o.x != 0) ? w.x : 1.0f - w.x) * ((o.y != 0) ? w.y : 1.0f - w.y);
        if (VoxelCellCut(cuts, cell)) {
            sum += weight;
            count++;
        }
    }
    // At a hole's edge or outer corner (two cut cells of the four or fewer) the cut stays further inside, as if it were
    // tested at 0.9 rather than 0.75: there the smooth surface's corner stops short of the half-way curve, and the
    // level behind a thin cliff showed past it in a tan wedge at a wall hole's corner (Jinjo Village, 2026-11-17).
    // Three of four (inside the hole, beside one whole cell) keep 0.75: tighter, strips of the wall stayed across
    // the hole there.
    if (count == 4u) {
        return 1.0f;
    }
    return (count == 3u) ? sum : sum * (0.75f / 0.9f);
}

// Whether a point of the level's surface (its normal either way round) lies over the cut cells.
bool VoxelSurfaceCut(StructuredBuffer<uint> cuts, float3 world, float3 normal) {
    if (cuts[0] == 0u) {
        return false;
    }
    // Outside the cut cells' bounds (with the two cells round them the test looks at) nothing is cut: most of a level
    // draw's pixels stop here, before any look in the table.
    const float3 lo = (float3(int3(asint(cuts[4]), asint(cuts[5]), asint(cuts[6]))) - 2.0f) * VoxelCellSize;
    const float3 hi = (float3(int3(asint(cuts[8]), asint(cuts[9]), asint(cuts[10]))) + 3.0f) * VoxelCellSize;
    if (any(world < lo) || any(world > hi)) {
        return false;
    }
    const float3 a = abs(normal);
    const uint axis = (a.x >= a.y) ? ((a.x >= a.z) ? 0u : 2u) : ((a.y >= a.z) ? 1u : 2u);
    // (Cut inside the cells' half-way curve, at 0.75, a quarter of a cell from the cut cells' middles: the smooth
    // surface's rim lies about half way, so the level's edge always overlaps it and nothing behind the wall shows
    // between them. At 0.65 a sloped wall's cut reached under a hole's floor, and the level behind showed in a sliver.)
    return max(VoxelRowCut(cuts, world, axis, -1.0f), VoxelRowCut(cuts, world, axis, 1.0f)) >= 0.75f;
}

#endif
