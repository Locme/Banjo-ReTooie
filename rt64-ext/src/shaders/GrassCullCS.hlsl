//
// RT64
//

// Banjo-Tooie: instanced 3D grass's culling pass (rt64_grass_instances.h). Built twice:
//
// - With CHUNK_PASS, one thread per chunk of grass ground: whether any of the chunk can be seen past what last frame
//   drew in front of it (occlusion culling, on the coarse level of the depth pyramid). It also clears the ground
//   draws' blade counts for the blade pass.
// - Without, one thread per candidate blade: one cell of the grid over a grass triangle (finer near the camera, as
//   the blades always were), whose blade is worked out (where in the cell, whether it is on the triangle, under a
//   road, in a patch, shown at its distance) and dropped when it is out of view (frustum culling) or hidden behind
//   last frame's depth (occlusion culling). What is left is added to its ground draw's blades, packed from the start,
//   ready for the instanced draw (GrassBladeVS.hlsl).
//
// With ray tracing, the chunk pass also clears the ray-traced blades (NaN corners: no triangle) and the blade pass
// writes the blades it keeps near the camera there as triangles, for the traced effects (GRASS_RAY_BLADES).

#include "shared/rt64_frame_params.h"
#include "shared/rt64_grass_instances.h"

[[vk::push_constant]] ConstantBuffer<GrassCullCB> gConstants : register(b0);
ConstantBuffer<FrameParams> FrParams : register(b1, space0);
StructuredBuffer<uint> grassMask : register(t70, space0);

StructuredBuffer<GrassTriangle> gTriangles : register(t1, space1);
StructuredBuffer<GrassChunk> gChunks : register(t2, space1);
StructuredBuffer<GrassSlot> gSlots : register(t3, space1);
StructuredBuffer<float2> gTexcoords : register(t4, space1);
StructuredBuffer<float4> gColors : register(t5, space1);
Texture2D<float> gHiZFine : register(t6, space1);
Texture2D<float> gHiZCoarse : register(t7, space1);
RWStructuredBuffer<uint> gChunkVisible : register(u8, space1);
RWStructuredBuffer<uint> gSlotCounts : register(u9, space1);
RWStructuredBuffer<GrassBladeInstance> gBlades : register(u10, space1);
RWStructuredBuffer<float4> gRayBlades : register(u11, space1);

#include "GrassBladeCommon.hlsli"

static const uint GrassTrailPoints = 12;

// How far behind last frame's depth something must be to count as hidden: a share of what is left of the depth
// range there, so about the same share of the distance near and far (3% of it).
static const float GrassOcclusionSlack = 0.03f;

uint GrassCullFlags() {
    return uint(FrParams.grassCull.x);
}

// A point in last frame's picture: its pixel (in the depth pyramid's fine texels) and depth, or false when it was
// behind the camera.
bool GrassLastFrame(float3 world, out float3 texel) {
    const float4 c = GrassToClipWith(FrParams.grassPrevWorldToClip, world);
    texel = 0.0f;
    if (c.w <= 1e-3f) {
        return false;
    }

    const float2 ndc = (c.xy / c.w) * FrParams.grassPrevScreen.xy + FrParams.grassPrevScreen.zw;
    const float2 size = FrParams.grassCull.yz;
    texel = float3(float2(ndc.x * 0.5f + 0.5f, 0.5f - ndc.y * 0.5f) * size, c.z / c.w);
    return true;
}

// Whether a screen box (fine texels, low and high) whose nearest depth is nearest lies behind last frame's depth all
// over it. Small boxes read the fine level, bigger ones the coarse level; boxes bigger still count as seen.
bool GrassHidden(float2 low, float2 high, float nearest, uint most) {
    const float2 size = FrParams.grassCull.yz;
    if (any(high < 0.0f) || any(low >= size) || (nearest <= 0.0f)) {
        // Off last frame's picture (or reaching the camera): nothing known there.
        return false;
    }

    int2 a = int2(floor(max(low, 0.0f)));
    int2 b = int2(floor(min(high, size - 1.0f)));
    bool fine = true;
    if ((b.x - a.x + 1) * (b.y - a.y + 1) > int(most)) {
        a /= int(GRASS_HIZ_COARSE);
        b /= int(GRASS_HIZ_COARSE);
        fine = false;
        if ((b.x - a.x + 1) * (b.y - a.y + 1) > int(most)) {
            return false;
        }
    }

    float farthest = 0.0f;
    for (int y = a.y; y <= b.y; y++) {
        for (int x = a.x; x <= b.x; x++) {
            farthest = max(farthest, fine ? gHiZFine.Load(int3(x, y, 0)) : gHiZCoarse.Load(int3(x, y, 0)));
        }
    }

    return nearest > farthest + (1.0f - farthest) * GrassOcclusionSlack;
}

#ifdef CHUNK_PASS

[numthreads(GRASS_CULL_GROUP, 1, 1)]
void CSMain(uint index : SV_DispatchThreadID) {
    if (index < gConstants.slotCount) {
        // Each slot's draw arguments for drawing it indirectly: vertices a blade, blades, first vertex, first blade.
        gSlotCounts[index * 4 + 0] = GRASS_BLADE_VERTICES;
        gSlotCounts[index * 4 + 1] = 0;
        gSlotCounts[index * 4 + 2] = 0;
        gSlotCounts[index * 4 + 3] = 0;
    }

    if (index < gConstants.rayBlades) {
        const float nan = asfloat(0x7FC00000u);
        for (uint v = 0; v < GRASS_BLADE_VERTICES; v++) {
            gRayBlades[index * GRASS_BLADE_VERTICES + v] = float4(nan, nan, nan, 1.0f);
        }

        if (index == 0) {
            gSlotCounts[gConstants.slotCount * 4] = 0;
        }
    }

    if (index >= gConstants.chunkCount) {
        return;
    }

    bool visible = true;
    if ((GrassCullFlags() & GRASS_CULL_OCCLUSION) != 0) {
        const GrassChunk chunk = gChunks[index];
        float2 low = 1e30f;
        float2 high = -1e30f;
        float nearest = 1e30f;
        bool behind = false;
        for (uint c = 0; c < 8; c++) {
            const float3 corner = float3(((c & 1) != 0) ? chunk.high.x : chunk.low.x, ((c & 2) != 0) ? chunk.high.y : chunk.low.y, ((c & 4) != 0) ? chunk.high.z : chunk.low.z);
            float3 texel;
            if (!GrassLastFrame(corner, texel)) {
                behind = true;
                break;
            }

            low = min(low, texel.xy);
            high = max(high, texel.xy);
            nearest = min(nearest, texel.z);
        }

        visible = behind || !GrassHidden(low - 1.0f, high + 1.0f, nearest, 64);
    }

    gChunkVisible[index] = visible ? 1u : 0u;
}

#else

// The triangle a candidate blade belongs to: the last whose first candidate is at or before it.
uint GrassFindTriangle(uint candidate) {
    uint low = 0;
    uint high = gConstants.triangleCount;
    while ((high - low) > 1) {
        const uint middle = (low + high) / 2;
        if (gTriangles[middle].info.z <= candidate) {
            low = middle;
        }
        else {
            high = middle;
        }
    }

    return low;
}

uint GrassPackHalves(float a, float b) {
    return f32tof16(a) | (f32tof16(b) << 16);
}

[numthreads(GRASS_CULL_GROUP, 1, 1)]
void CSMain(uint candidate : SV_DispatchThreadID) {
    if ((candidate >= gConstants.candidateCount) || (gConstants.triangleCount == 0)) {
        return;
    }

    const GrassTriangle tri = gTriangles[GrassFindTriangle(candidate)];
    const uint flags = GrassCullFlags();
    const uint slot = tri.vertices.w;
    if ((slot >= gConstants.slotCount) || (((flags & GRASS_CULL_CHUNKS) != 0) && (gChunkVisible[tri.info.y] == 0))) {
        return;
    }

    const uint index = candidate - tri.info.z;
    const uint level = tri.info.x & 0xFu;
    const uint plane = (tri.info.x >> 4) & 0x3u;
    const bool edges = (tri.info.x & GRASS_TRIANGLE_EDGES) != 0;
    const float3 world[3] = { tri.p0.xyz, tri.p1.xyz, tri.p2.xyz };
    const float4 params = FrParams.grassParams;
    const float3 camera = float3(FrParams.grassWorldX.w, FrParams.grassWorldY.w, FrParams.grassWorldZ.w);

    const float3 normal = cross(world[1] - world[0], world[2] - world[0]);
    const float normalLength = length(normal);
    const float2 a = GrassPlane(world[0], plane), b = GrassPlane(world[1], plane), c = GrassPlane(world[2], plane);
    const float area = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
    if ((normalLength <= 1e-4f) || (abs(area) < 1e-4f)) {
        return;
    }

    const float baseCell = FrParams.grassBlades.w;
    const uint countX = max(tri.info.w, 1u);
    const float2 coarseIndex = tri.first.xy + float2(float(index % countX), float(index / countX));
    const float2 cellIndex = GrassFinestCell(coarseIndex, level);
    const float4 r = GrassHash4(float3(cellIndex, float(plane) * 1009.0f));
    if (r.w > params.w) {
        return;
    }

    // A point somewhere in its finest cell, if it is on this triangle.
    const float2 spot = (cellIndex + 0.1f + 0.8f * r.xy) * baseCell;
    const float w1 = ((spot.x - a.x) * (c.y - a.y) - (c.x - a.x) * (spot.y - a.y)) / area;
    const float w2 = ((b.x - a.x) * (spot.y - a.y) - (spot.x - a.x) * (b.y - a.y)) / area;
    const float w0 = 1.0f - w1 - w2;
    if ((w0 < 0.0f) || (w1 < 0.0f) || (w2 < 0.0f)) {
        return;
    }

    const float3 root = world[0] * w0 + world[1] * w1 + world[2] * w2;
    const float cameraDistance = distance(root, camera);
    const float fade = saturate(1.0f - cameraDistance / params.z);
    if (fade < 0.02f) {
        return;
    }

    // Further out than the triangle's nearest point, the blade goes by its own distance's level: hidden where that
    // level no longer shows it, and thinning away (not getting shorter: that read as grass growing as Banjo walks up)
    // over the last fifth of the way to the next level when that one won't.
    const uint bladeLevel = max(GrassDistanceLevel(cameraDistance), level);
    if (!GrassShownAt(coarseIndex, level, bladeLevel)) {
        return;
    }
    float lodShrink = 1.0f;
    if ((bladeLevel < GRASS_MAX_LEVEL) && !GrassShownAt(GrassCoarseCell(coarseIndex, level, bladeLevel), bladeLevel, bladeLevel + 1)) {
        const float nextDistance = FrParams.grassBlades.x * exp2(float(bladeLevel + 1));
        lodShrink = saturate((nextDistance - cameraDistance) / (nextDistance * 0.2f));
        if (lodShrink < 0.02f) {
            return;
        }
    }

    // None under a road, a path or a stone floor the game lays over the ground (grassMask).
    if (FrParams.grassMask.w > 0.0f) {
        const int2 maskCell = int2(floor((root.xz - FrParams.grassMask.xy) / FrParams.grassMask.z));
        const int2 maskCells = int2(FrParams.grassMask.w, FrParams.grassLook.y);
        if (all(maskCell >= 0) && all(maskCell < maskCells)) {
            const uint bit = uint(maskCell.y * maskCells.x + maskCell.x);
            if ((grassMask[bit >> 5] >> (bit & 31)) & 1) {
                return;
            }
        }
    }

    // Only in patches; toward a patch's edge the blades thin out and get shorter.
    const float patch = GrassPatch(root.xz);
    if (patch <= GrassHash1(float3(cellIndex, 53.0f)) * 0.6f) {
        return;
    }

    // Full height until the last part of the reach, then lower toward its end (not all the way: a slope from near to
    // far read as the grass growing as Banjo walks up).
    const float height = params.x;
    const float bladeHeight = height * lerp(1.0f - FrParams.grassPatches.w, 1.0f, r.y) * lerp(0.35f, 1.0f, saturate(fade / 0.3f)) *
        lerp(0.3f, 1.0f, patch);
    // Wider with distance as the grid thins out (smoothly, by the blade's own distance only, so it never jumps as the
    // camera moves), and by the thickness.
    const float widen = clamp(cameraDistance / FrParams.grassBlades.x, 1.0f, exp2(float(bladeLevel + 1)));
    const bool chunky = FrParams.grassStyle.x > 0.5f;
    const float bladeWidth = 2.4f * (chunky ? 1.04f * FrParams.grassStyle.z : 1.0f) * widen * FrParams.grassPatches.z * lerp(0.75f, 1.25f, r.x) * lodShrink;

    // Frustum culling: a ball round the blade (its whole height either way, as it can lean) must reach into the view.
    if ((flags & GRASS_CULL_FRUSTUM) != 0) {
        const float3 center = root + float3(0.0f, bladeHeight * 0.5f, 0.0f);
        const float radius = bladeHeight + bladeWidth;
        for (uint p = 0; p < 5; p++) {
            if ((dot(FrParams.grassFrustum[p].xyz, center) + FrParams.grassFrustum[p].w) < -radius) {
                return;
            }
        }
    }

    // (Occlusion culling is by chunk only, in the chunk pass: last frame's depth tested blade by blade hid blades
    // behind where Banjo or the camera had just been.)

    // Wind: a noise field drifting along the wind bends the blades, with a quick flutter of their own.
    const float4 wind = FrParams.grassWind;
    const float2 windDir = normalize(wind.xy);
    const float time = wind.z;
    const float2 windUV = root.xz / FrParams.grassBlades.y + windDir * time * FrParams.grassBlades.z;
    const float gust = GrassNoise(windUV) * 0.75f + GrassNoise(windUV * 2.7f + 13.0f) * 0.25f;
    float2 bend = windDir * wind.w * (0.04f + 0.32f * gust);
    bend += float2(-windDir.y, windDir.x) * 0.06f * sin(time * 4.0f + r.z * 6.2832f);

    // Pushed away from Banjo and where he has just been.
    const float4 trailBounds = FrParams.grassTrailBounds;
    const float trailRadius = FrParams.grassPlayer.w;
    if (all(root.xz >= trailBounds.xy) && all(root.xz <= trailBounds.zw)) {
        float pressed = 0.0f;
        float2 push = 0.0f;
        for (uint t = 0; t <= GrassTrailPoints; t++) {
            const float4 trail = (t == GrassTrailPoints) ? float4(FrParams.grassPlayer.xyz, 1.0f) : FrParams.grassTrail[t];
            if ((trail.w == 0.0f) || (trail.z < -1e8f) || (abs(root.y - trail.z) > 80.0f)) {
                continue;
            }

            const float2 away = root.xz - trail.xy;
            const float awayLength = length(away);
            if (awayLength >= trailRadius) {
                continue;
            }

            const float strength = trail.w * smoothstep(trailRadius, 0.0f, awayLength);
            push += (awayLength > 0.001f ? away / awayLength : windDir) * strength;
            pressed = max(pressed, strength);
        }
        bend = lerp(bend, 0.0f, saturate(pressed)) + push * 1.1f;
    }

    // On a slope or a wall, leaning out from it (toward the camera's side, the one that shows).
    if (edges) {
        float3 outward = normal / normalLength;
        outward *= (dot(outward, camera - root) < 0.0f) ? -1.0f : 1.0f;
        bend += outward.xz * (1.0f - abs(outward.y)) * 0.6f;
    }

    // A little lean of its own, then no further over than lying almost flat.
    const float yaw = r.z * 6.2832f;
    const float2 facing = float2(cos(yaw), sin(yaw));
    bend += float2(-facing.y, facing.x) * (r.x - 0.5f) * 0.35f;
    const float bendLength = length(bend);
    if (bendLength > 0.95f) {
        bend *= 0.95f / bendLength;
    }
    const float lean = min(length(bend), 0.95f);
    const float rise = bladeHeight * sqrt(1.0f - lean * lean * 0.85f);

    // The ground's texture coordinates and colours at the root, as its own vertices have them.
    const uint3 v = tri.vertices.xyz;
    const float2 uv = gTexcoords[v.x] * w0 + gTexcoords[v.y] * w1 + gTexcoords[v.z] * w2;
    const float4 smoothColor = gColors[v.x] * w0 + gColors[v.y] * w1 + gColors[v.z] * w2;
    const float4 flatColor = gColors[v.x];

    uint place;
    InterlockedAdd(gSlotCounts[slot * 4 + 1], 1u, place);
    const GrassSlot slotInfo = gSlots[slot];
    if (place >= slotInfo.info.y) {
        return;
    }

    GrassBladeInstance blade;
    blade.root = float4(root, bladeHeight);
    blade.shape = float4(yaw, bladeWidth, rise, 0.0f);
    blade.uvBend = float4(uv, bend);
    blade.colors = uint4(GrassPackHalves(smoothColor.r, smoothColor.g), GrassPackHalves(smoothColor.b, smoothColor.a),
        GrassPackHalves(flatColor.r, flatColor.g), GrassPackHalves(flatColor.b, 0.0f));
    gBlades[slotInfo.info.x + place] = blade;

    // Ray tracing: the blade as the vertex shader draws it (without the pixelated blades' growth), when it is near.
    if ((gConstants.rayBlades > 0) && (cameraDistance < gConstants.rayReach)) {
        uint rayPlace;
        InterlockedAdd(gSlotCounts[gConstants.slotCount * 4], 1u, rayPlace);
        if (rayPlace < gConstants.rayBlades) {
            static const uint corners[GRASS_BLADE_VERTICES] = { 0, 1, 2, 1, 3, 2, 2, 3, 4 };
            static const float2 cornerST[5] = { float2(-1.0f, 0.0f), float2(1.0f, 0.0f), float2(-0.75f, 0.55f), float2(0.75f, 0.55f), float2(0.0f, 1.0f) };
            const float3 side = float3(facing.x, 0.0f, facing.y) * (bladeWidth * 0.5f);
            const float3 tipBend = float3(bend.x, 0.0f, bend.y) * bladeHeight;
            const float3 middle = float3(0.0f, rise * 0.55f, 0.0f) + tipBend * 0.3f;
            const float3 tip = float3(0.0f, rise, 0.0f) + tipBend;
            const uint vertices = chunky ? 3 : GRASS_BLADE_VERTICES;
            for (uint k = 0; k < vertices; k++) {
                const uint corner = (chunky && (k == 2)) ? 4 : corners[k];
                const float3 at = root + GrassBladePoint(cornerST[corner].x, cornerST[corner].y, chunky, side, middle, tip);
                gRayBlades[rayPlace * GRASS_BLADE_VERTICES + k] = float4(at, 1.0f);
            }
        }
    }
}

#endif
