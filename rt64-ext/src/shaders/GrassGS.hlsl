//
// RT64
//

// Banjo-Tooie: 3D grass as real blades. Each triangle of the level's green ground is drawn again through this
// geometry shader, which grows blades on it: one per cell of a grid over the world's x and z (coarser further
// away), each a flat, tapering blade of two segments and a tip (one triangle for chunky blades), turned any way, leaning in the wind (a noise
// field rolling across the field) and pushed away from Banjo and his trail. The blades keep the ground's own
// texture coordinates and colours at their root, so the pixel shader colours them from the ground under them
// (and keeps only green ground); the root's height goes in the flat colour's alpha (RasterPS.hlsl).
//
// Every blade is 5 vertices of 18 values (GrassVertex), 11 blades to an invocation (D3D12 allows 1024 values out of
// one; anything added to GrassVertex means fewer blades, here and in rt64_scene_effects.cpp), 32 invocations a triangle, and the draw is repeated for as many passes as its largest triangle needs
// (RasterParams.grassShell is the pass, 1 to the count in grassShells' low bits).

#include "shared/rt64_raster_params.h"

#include "FbRendererCommon.hlsli"

[[vk::push_constant]] ConstantBuffer<RasterParams> gConstants : register(b0, space0);

#define GRASS_BLADES_PER_INVOCATION 11
#define GRASS_INVOCATIONS 32
#define GRASS_PASS_MASK 0xFFFFu

static const uint GrassTrailPoints = 12;

struct GrassVertex {
    float4 position : SV_POSITION;
    float2 uv : TEXCOORD;
    float4 smoothColor : COLOR0;
    nointerpolation float4 flatColor : COLOR1;
    // Banjo's fur's place on his model (RasterVS.hlsl); unused here, but the shaders on both sides have it.
    float4 furAnchor : TEXCOORD1;
};

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

// Smooth value noise, for the wind.
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

float4 GrassToClip(float3 world) {
    const float4 w = float4(world, 1.0f);
    return float4(dot(FrParams.grassWorldToClip[0], w), dot(FrParams.grassWorldToClip[1], w), dot(FrParams.grassWorldToClip[2], w), dot(FrParams.grassWorldToClip[3], w));
}

float4 GrassDirToClip(float3 dir) {
    const float4 d = float4(dir, 0.0f);
    return float4(dot(FrParams.grassWorldToClip[0], d), dot(FrParams.grassWorldToClip[1], d), dot(FrParams.grassWorldToClip[2], d), dot(FrParams.grassWorldToClip[3], d));
}

float3 GrassToWorld(float4 clip) {
    const float4 w = float4(dot(FrParams.grassClipToWorld[0], clip), dot(FrParams.grassClipToWorld[1], clip), dot(FrParams.grassClipToWorld[2], clip), dot(FrParams.grassClipToWorld[3], clip));
    return w.xyz / w.w;
}

// The ground's position as RasterVS made it, back to the same space before its screen scale and offset.
float4 GrassUnscale(float4 position) {
#ifdef __spirv__
    position.y = -position.y;
#endif
    position.xy = (position.xy - gConstants.screenOffset * position.w) / gConstants.screenScale;
    return position;
}

float4 GrassRescale(float4 position) {
    position.xy = position.xy * gConstants.screenScale + gConstants.screenOffset * position.w;
#ifdef __spirv__
    position.y = -position.y;
#endif
    return position;
}

#define GRASS_MAX_LEVEL 8

// The grid's level for a distance from the camera: one more for every doubling past the near distance.
uint GrassDistanceLevel(float distanceToCamera) {
    return uint(min(max(floor(log2(max(distanceToCamera, 1.0f) / FrParams.grassBlades.x)), 0.0f), float(GRASS_MAX_LEVEL)));
}

// The level a triangle this far from the camera is drawn at: its distance's level, or coarser until its cells
// fit in the passes drawn. A level's cells are 2^level of the finest grid's cells across.
uint GrassTriangleLevel(float distanceToCamera, float2 extent, float capacity) {
    uint level = GrassDistanceLevel(distanceToCamera);
    for (; level < GRASS_MAX_LEVEL; level++) {
        const float2 cells = floor(extent / (FrParams.grassBlades.w * exp2(float(level)))) + 2.0f;
        if (cells.x * cells.y <= capacity) {
            break;
        }
    }
    return level;
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

// Emits the blade's vertex at (s, t). Pixelated blades are drawn bigger, by one N64 pixel each way (2 / 240 of the
// screen's height before its scale, as RasterVS's positions), with their (s, t) going along, so RasterPS can keep
// whole N64-sized blocks whose centre is in the real blade.
void GrassEmitBlade(inout TriangleStream<GrassVertex> stream, GrassVertex root, float4 rootClip, float s, float t, bool chunky,
    float2 grow, float3 side, float3 middle, float3 tip)
{
    GrassVertex v = root;
    if (grow.x > 0.0f) {
        s *= grow.x;
        t = 0.5f + (t - 0.5f) * grow.y;
        v.furAnchor = float4(s, t, 1.0f, 0.0f);
    }

    v.position = GrassRescale(rootClip + GrassDirToClip(GrassBladePoint(s, t, chunky, side, middle, tip)));
    stream.Append(v);
}

// Banjo-Tooie: Kazooie's feathers. Little flat feathers are scattered over each of her triangles (as many as its area
// holds, at random places that stay put on it as she moves), each a card from a spot on her surface, pointing down
// her body and lifted a little off it, so they overlap like a bird's. A card's texture coordinates are those of the
// surface under each of its corners, so it shows the texture it lies on (L), while whether it is a feather at all
// is up to her colour at its root; the pixel shader cuts it to a feather's shape and shades it (FeatherCard in
// Fur.hlsli). Its place across and along the feather goes in the fur anchor, with its shade.
#define FEATHERS_PER_INVOCATION 14

uint FeatherHash(uint a, uint b) {
    uint h = a * 0x8DA6B343u ^ b * 0xD8163841u ^ 0x6C8E9CF5u;
    h ^= h >> 13;
    h *= 0x5BD1E995u;
    h ^= h >> 15;
    h *= 0x27D4EB2Du;
    h ^= h >> 16;
    return h;
}

float FeatherRandom(uint a, uint b) {
    return float(FeatherHash(a, b) & 0xFFFFu) / 65535.0f;
}

void FeatherEmit(inout TriangleStream<GrassVertex> stream, GrassVertex v, float4 rootClip, float3 offset, float2 uvOffset, float s, float t, float shade) {
    v.position = GrassRescale(rootClip + GrassDirToClip(offset));
    v.uv += uvOffset;
    v.furAnchor.xyz = float3(s, t, shade);
    stream.Append(v);
}

void FeatherCards(triangle GrassVertex input[3], uint primitive, uint instance, inout TriangleStream<GrassVertex> stream) {
    const bool npcFeathers = (gConstants.grassShells & RASTER_FEATHER_NPC) != 0;
    const float4 params = npcFeathers ? FrParams.npcFeatherParams : FrParams.featherParams;
    const uint pass = gConstants.grassShell - 1;
    const uint passes = max(gConstants.grassShells & GRASS_PASS_MASK, 1u);

    float4 clip[3];
    float3 world[3];
    for (int k = 0; k < 3; k++) {
        clip[k] = GrassUnscale(input[k].position);
        world[k] = GrassToWorld(clip[k]);
    }

    float3 normal = cross(world[1] - world[0], world[2] - world[0]);
    const float normalLength = length(normal);
    if (normalLength <= 1e-4f) {
        return;
    }
    normal /= normalLength;

    // Outward: towards the camera for a triangle the camera sees the front of, away from it otherwise (the winding
    // on screen tells which); always towards it on a thin part seen from both sides (her wings and crest).
    const float2 s0 = clip[0].xy / max(clip[0].w, 1e-5f);
    const float2 s1 = clip[1].xy / max(clip[1].w, 1e-5f);
    const float2 s2 = clip[2].xy / max(clip[2].w, 1e-5f);
    const float screenArea = (s1.x - s0.x) * (s2.y - s0.y) - (s2.x - s0.x) * (s1.y - s0.y);
    const float3 camera = float3(FrParams.grassWorldX.w, FrParams.grassWorldY.w, FrParams.grassWorldZ.w);
    const float3 center = (world[0] + world[1] + world[2]) / 3.0f;
    const bool facesCamera = dot(normal, camera - center) > 0.0f;
    const bool twoSided = (gConstants.grassShells & RASTER_GRASS_EDGES) != 0;
    if (facesCamera != ((screenArea > 0.0f) || twoSided)) {
        normal = -normal;
    }
    // A wing is two sheets back to back: only the one whose front the camera sees grows feathers, as the other's,
    // lit from behind, poked through dark (L). (Not on a feathered NPC: Canary Mary's parts are single sheets drawn
    // both ways round, which lost all their feathers to this.)
    if (twoSided && !npcFeathers && (screenArea <= 0.0f)) {
        return;
    }

    // How many feathers the triangle holds; one too big for a pass's worth gets fewer, bigger ones.
    const float area = 0.5f * normalLength;
    // (Her wings, thin and partly cut out, get more for the same cover.)
    const float wanted = area * params.z * (twoSided ? 1.8f : 1.0f);
    const float capacity = float(passes * GRASS_INVOCATIONS * FEATHERS_PER_INVOCATION);
    const float grow = sqrt(max(wanted / capacity, 1.0f));
    const float count = min(wanted, capacity);
    const uint start = (pass * GRASS_INVOCATIONS + instance) * FEATHERS_PER_INVOCATION;
    if (float(start) >= count) {
        return;
    }

    // Down her body: straight down, along the surface; on a part facing up or down, along the triangle.
    float3 down = float3(0.0f, -1.0f, 0.0f) - normal * (-normal.y);
    if (length(down) < 0.25f) {
        down = world[1] - world[0];
        down -= normal * dot(down, normal);
    }
    down = normalize(down);

    // A wing (a thin part seen from both sides) has its feathers along it instead, the way its texture runs
    // (L: on her wing they go out towards the tips, not down).
    if (twoSided) {
        const float3 e1 = world[1] - world[0];
        const float3 e2 = world[2] - world[0];
        const float2 d1 = input[1].uv - input[0].uv;
        const float2 d2 = input[2].uv - input[0].uv;
        const float det = d1.x * d2.y - d2.x * d1.y;
        if (abs(det) > 1e-6f) {
            // Where the texture's second coordinate grows: towards the wing's yellow tips.
            float3 runs = (e2 * d1.x - e1 * d2.x) / det;
            runs -= normal * dot(runs, normal);
            if (length(runs) > 1e-5f) {
                down = normalize(runs);
            }
        }
    }
    const float3 across = cross(normal, down);

    // How the texture runs over the triangle's plane, so each corner of a feather shows the texture under it.
    const float3 edge1 = world[1] - world[0];
    const float3 edge2 = world[2] - world[0];
    const float g11 = dot(edge1, edge1);
    const float g12 = dot(edge1, edge2);
    const float g22 = dot(edge2, edge2);
    const float gramDet = g11 * g22 - g12 * g12;
    const float2 uvEdge1 = input[1].uv - input[0].uv;
    const float2 uvEdge2 = input[2].uv - input[0].uv;

    for (uint i = 0; i < FEATHERS_PER_INVOCATION; i++) {
        const uint index = start + i;
        const float last = count - float(index);
        if (last <= 0.0f) {
            break;
        }
        const uint seed = FeatherHash(primitive, index);
        // Part of a feather: the last one only sometimes.
        if ((last < 1.0f) && (FeatherRandom(seed, 9u) >= last)) {
            break;
        }

        float w1 = FeatherRandom(seed, 1u);
        float w2 = FeatherRandom(seed, 2u);
        if (w1 + w2 > 1.0f) {
            w1 = 1.0f - w1;
            w2 = 1.0f - w2;
        }
        const float w0 = 1.0f - w1 - w2;
        const float4 rootClip = clip[0] * w0 + clip[1] * w1 + clip[2] * w2;

        // Turned a little either way, lifted off her surface, the tip curling back down to it.
        const float noisiness = npcFeathers ? FrParams.npcFeatherStyle.x : FrParams.featherStyle.x;
        const float turn = (FeatherRandom(seed, 3u) - 0.5f) * 1.4f * noisiness;
        const float3 along = down * cos(turn) + across * sin(turn);
        const float3 side = cross(normal, along);
        const float size = grow * lerp(1.0f - 0.4f * noisiness, 1.0f + 0.4f * noisiness, FeatherRandom(seed, 4u));
        const float featherLength = params.x * size;
        const float halfWidth = 0.5f * params.y * size;
        const float lift = params.w * featherLength;
        // A feather starts a third of its length behind its root, so the top edges no feather grows over are
        // covered too: her wings' and the top of her head (L: not all the way up, bald on top).
        const float back = 0.35f * featherLength;
        const float3 rootOffset = -normal * (0.1f * featherLength) - along * back;
        const float3 tipOffset = along * (featherLength - back) + normal * (lift * 0.5f);
        const float shade = lerp(1.0f - 0.36f * noisiness, 1.0f + 0.2f * noisiness, FeatherRandom(seed, 5u));

        GrassVertex v;
        v.position = 0.0f;
        v.uv = input[0].uv * w0 + input[1].uv * w1 + input[2].uv * w2;
        v.smoothColor = input[0].smoothColor * w0 + input[1].smoothColor * w1 + input[2].smoothColor * w2;
        v.flatColor = input[0].flatColor;
        // (w: her fur mark at its root, RasterVS.hlsl.)
        v.furAnchor = float4(0.0f, 0.0f, 0.0f, input[0].furAnchor.w * w0 + input[1].furAnchor.w * w1 + input[2].furAnchor.w * w2);
        const float3 corners[4] = {
            rootOffset - side * halfWidth, rootOffset + side * halfWidth, tipOffset - side * halfWidth, tipOffset + side * halfWidth
        };
        for (uint c = 0; c < 4; c++) {
            float2 uvOffset = 0.0f;
            if (gramDet > 1e-8f) {
                const float a = dot(corners[c], edge1);
                const float b = dot(corners[c], edge2);
                uvOffset = uvEdge1 * ((g22 * a - g12 * b) / gramDet) + uvEdge2 * ((g11 * b - g12 * a) / gramDet);
            }
            FeatherEmit(stream, v, rootClip, corners[c], uvOffset, ((c & 1u) != 0) ? 1.0f : -1.0f, (c >= 2u) ? 1.0f : 0.0f, shade);
        }
        stream.RestartStrip();
    }
}

[maxvertexcount(GRASS_BLADES_PER_INVOCATION * 5)]
[instance(GRASS_INVOCATIONS)]
void GSMain(triangle GrassVertex input[3], uint instance : SV_GSInstanceID, uint primitive : SV_PrimitiveID, inout TriangleStream<GrassVertex> stream) {
    if ((gConstants.grassShells & RASTER_FEATHER_CARDS) != 0) {
        FeatherCards(input, primitive, instance, stream);
        return;
    }

    const uint passes = max(gConstants.grassShells & GRASS_PASS_MASK, 1u);
    const uint pass = gConstants.grassShell - 1;
    const float4 params = FrParams.grassParams;

    float4 clip[3];
    float3 world[3];
    for (int k = 0; k < 3; k++) {
        clip[k] = GrassUnscale(input[k].position);
        world[k] = GrassToWorld(clip[k]);
    }

    // Ground facing up only, unless the texture has grass along an edge: then any way it faces.
    const bool edges = (gConstants.grassShells & RASTER_GRASS_EDGES) != 0;
    float3 normal = cross(world[1] - world[0], world[2] - world[0]);
    const float normalLength = length(normal);
    if ((normalLength <= 1e-4f) || (!edges && (abs(normal.y) < 0.6f * normalLength))) {
        return;
    }

    // The grid lies in the plane of the two axes the triangle faces least along: x and z for ground, z and y for a
    // wall facing along x, x and y for one facing along z (as grassBladePasses in rt64_framebuffer_renderer.cpp).
    const float3 facingAxes = abs(normal);
    const uint plane = ((facingAxes.y >= facingAxes.x) && (facingAxes.y >= facingAxes.z)) ? 0 : ((facingAxes.x >= facingAxes.z) ? 1 : 2);

    // How far the triangle is from the camera, and its grid.
    const float3 camera = float3(FrParams.grassWorldX.w, FrParams.grassWorldY.w, FrParams.grassWorldZ.w);
    const float3 center = (world[0] + world[1] + world[2]) / 3.0f;
    const float radius = max(max(distance(world[0], center), distance(world[1], center)), distance(world[2], center));
    const float triangleDistance = max(distance(center, camera) - radius, 0.0f);
    if (triangleDistance > params.z) {
        return;
    }

    const float2 p0 = GrassPlane(world[0], plane), p1 = GrassPlane(world[1], plane), p2 = GrassPlane(world[2], plane);
    const float2 low = min(min(p0, p1), p2);
    const float2 high = max(max(p0, p1), p2);
    const float capacity = float(passes * GRASS_INVOCATIONS * GRASS_BLADES_PER_INVOCATION);
    const uint level = GrassTriangleLevel(triangleDistance, high - low, capacity);
    const float baseCell = FrParams.grassBlades.w;
    const float cell = baseCell * exp2(float(level));
    const float2 first = floor(low / cell);
    const float2 count = floor(high / cell) - first + 1.0f;
    const uint cellCount = uint(count.x * count.y);
    const uint start = (pass * GRASS_INVOCATIONS + instance) * GRASS_BLADES_PER_INVOCATION;
    if (start >= cellCount) {
        return;
    }

    // For telling which side of each edge a point lies on, in the grid's plane.
    const float2 a = p0, b = p1, c = p2;
    const float area = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
    if (abs(area) < 1e-4f) {
        return;
    }

    // Whether the triangle reaches into the box of cells roads and paths marked (grassMask): most don't, and skip the lookups.
    const float2 maskLow = FrParams.grassMask.xy;
    const float2 maskHigh = maskLow + float2(FrParams.grassMask.w, FrParams.grassLook.y) * FrParams.grassMask.z;
    const float2 worldLow = min(min(world[0].xz, world[1].xz), world[2].xz);
    const float2 worldHigh = max(max(world[0].xz, world[1].xz), world[2].xz);
    const bool masked = (FrParams.grassMask.w > 0.0f) && all(worldHigh >= maskLow) && all(worldLow <= maskHigh);

    const float4 wind = FrParams.grassWind;
    const float2 windDir = normalize(wind.xy);
    const float time = wind.z;
    const float height = params.x;
    const float4 trailBounds = FrParams.grassTrailBounds;
    const float trailRadius = FrParams.grassPlayer.w;

    for (uint i = 0; i < GRASS_BLADES_PER_INVOCATION; i++) {
        const uint index = start + i;
        if (index >= cellCount) {
            break;
        }

        const float2 coarseIndex = first + float2(index % uint(count.x), index / uint(count.x));
        const float2 cellIndex = GrassFinestCell(coarseIndex, level);
        const float4 r = GrassHash4(float3(cellIndex, float(plane) * 1009.0f));
        if (r.w > params.w) {
            continue;
        }

        // A point somewhere in its finest cell, if it is in this triangle.
        const float2 spot = (cellIndex + 0.1f + 0.8f * r.xy) * baseCell;
        const float w1 = ((spot.x - a.x) * (c.y - a.y) - (c.x - a.x) * (spot.y - a.y)) / area;
        const float w2 = ((b.x - a.x) * (spot.y - a.y) - (spot.x - a.x) * (b.y - a.y)) / area;
        const float w0 = 1.0f - w1 - w2;
        if ((w0 < 0.0f) || (w1 < 0.0f) || (w2 < 0.0f)) {
            continue;
        }

        const float3 root = world[0] * w0 + world[1] * w1 + world[2] * w2;
        const float cameraDistance = distance(root, camera);
        const float fade = saturate(1.0f - cameraDistance / params.z);
        if (fade < 0.02f) {
            continue;
        }

        // Further out than the triangle's nearest point, the blade goes by its own distance's level: hidden where
        // that level no longer shows it, and thinning away (not getting shorter: that read as grass growing as Banjo
        // walks up) over the last fifth of the way to the next level when that one won't, so the triangle can step
        // a level coarser without anything vanishing at once.
        const uint bladeLevel = max(GrassDistanceLevel(cameraDistance), level);
        if (!GrassShownAt(coarseIndex, level, bladeLevel)) {
            continue;
        }
        // Shown at the blade's level, so whether the next level shows it too is that one step more.
        float lodShrink = 1.0f;
        if ((bladeLevel < GRASS_MAX_LEVEL) && !GrassShownAt(GrassCoarseCell(coarseIndex, level, bladeLevel), bladeLevel, bladeLevel + 1)) {
            const float nextDistance = FrParams.grassBlades.x * exp2(float(bladeLevel + 1));
            lodShrink = saturate((nextDistance - cameraDistance) / (nextDistance * 0.2f));
            if (lodShrink < 0.02f) {
                continue;
            }
        }

        // Only in patches; toward a patch's edge the blades thin out and get shorter.
        // None under a road or dirt the game lays over the ground (grassMask, marked from those decals' triangles).
        if (masked) {
            const int2 maskCell = int2(floor((root.xz - FrParams.grassMask.xy) / FrParams.grassMask.z));
            const int2 maskCells = int2(FrParams.grassMask.w, FrParams.grassLook.y);
            if (all(maskCell >= 0) && all(maskCell < maskCells)) {
                const uint bit = uint(maskCell.y * maskCells.x + maskCell.x);
                if ((grassMask[bit >> 5] >> (bit & 31)) & 1) {
                    continue;
                }
            }
        }
        const float patch = GrassPatch(root.xz);
        if (patch <= GrassHash1(float3(cellIndex, 53.0f)) * 0.6f) {
            continue;
        }

        GrassVertex v;
        v.position = 0.0f;
        v.uv = input[0].uv * w0 + input[1].uv * w1 + input[2].uv * w2;
        v.smoothColor = input[0].smoothColor * w0 + input[1].smoothColor * w1 + input[2].smoothColor * w2;
        v.flatColor = float4(input[0].flatColor.rgb, root.y);
        v.furAnchor = 0.0f;
        const float4 rootClip = clip[0] * w0 + clip[1] * w1 + clip[2] * w2;

        // Wind: a noise field drifting along the wind bends the blades, with a quick flutter of their own.
        const float2 windUV = root.xz / FrParams.grassBlades.y + windDir * time * FrParams.grassBlades.z;
        const float gust = GrassNoise(windUV) * 0.75f + GrassNoise(windUV * 2.7f + 13.0f) * 0.25f;
        float2 bend = windDir * wind.w * (0.04f + 0.32f * gust);
        bend += float2(-windDir.y, windDir.x) * 0.06f * sin(time * 4.0f + r.z * 6.2832f);

        // Pushed away from Banjo and where he has just been.
        float pressed = 0.0f;
        if (all(root.xz >= trailBounds.xy) && all(root.xz <= trailBounds.zw)) {
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

        // Full height until the last part of the reach, then lower toward its end (not all the way: a slope from
        // near to far read as the grass growing as Banjo walks up).
        const float bladeHeight = height * lerp(1.0f - FrParams.grassPatches.w, 1.0f, r.y) * lerp(0.35f, 1.0f, saturate(fade / 0.3f)) *
            lerp(0.3f, 1.0f, patch);
        // Wider with distance as the grid thins out (smoothly, by the blade's own distance), and by the thickness.
        const float widen = clamp(cameraDistance / FrParams.grassBlades.x, 1.0f, exp2(float(bladeLevel + 1))) * exp2(float(level - min(level, GrassDistanceLevel(triangleDistance))));
        const bool chunky = FrParams.grassStyle.x > 0.5f;
        const bool pixelated = FrParams.grassStyle.y > 0.5f;
        const float bladeWidth = 2.4f * (chunky ? 1.04f * FrParams.grassStyle.z : 1.0f) * widen * FrParams.grassPatches.z * lerp(0.75f, 1.25f, r.x) * lodShrink;
        const float lean = min(length(bend), 0.95f);
        const float rise = bladeHeight * sqrt(1.0f - lean * lean * 0.85f);
        const float3 side = float3(facing.x, 0.0f, facing.y) * (bladeWidth * 0.5f);
        const float3 tipBend = float3(bend.x, 0.0f, bend.y) * bladeHeight;
        const float3 middle = float3(0.0f, rise * 0.55f, 0.0f) + tipBend * 0.3f;
        const float3 tip = float3(0.0f, rise, 0.0f) + tipBend;

        // Pixelated: how much bigger to draw the blade for one block (grassStyle.w N64 pixels) more each way across
        // and along it.
        float2 grow = 0.0f;
        if (pixelated) {
            const float pixel = FrParams.grassStyle.w * 2.0f / 240.0f;
            const float w = max(rootClip.w, 1e-3f);
            const float across = length(GrassDirToClip(side).xy) / w;
            const float along = length(GrassDirToClip(tip).xy) / w;
            grow = float2(1.0f + min(pixel / max(across, 1e-4f), 400.0f), 1.0f + min(2.0f * pixel / max(along, 1e-4f), 400.0f));
        }

        // Chunky: one triangle, in one flat colour (GrassBlade in Grass.hlsli).
        GrassEmitBlade(stream, v, rootClip, -1.0f, 0.0f, chunky, grow, side, middle, tip);
        GrassEmitBlade(stream, v, rootClip, 1.0f, 0.0f, chunky, grow, side, middle, tip);
        if (!chunky) {
            GrassEmitBlade(stream, v, rootClip, -0.75f, 0.55f, chunky, grow, side, middle, tip);
            GrassEmitBlade(stream, v, rootClip, 0.75f, 0.55f, chunky, grow, side, middle, tip);
        }
        GrassEmitBlade(stream, v, rootClip, 0.0f, 1.0f, chunky, grow, side, middle, tip);
        stream.RestartStrip();
    }
}
