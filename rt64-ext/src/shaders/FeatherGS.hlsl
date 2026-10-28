//
// RT64
//

// Banjo-Tooie: Kazooie's (and Canary Mary's) feathers. Each triangle of the character is drawn again through this
// geometry shader, which scatters little flat feathers over it (FeatherCards below). A triangle that holds more than
// one pass's worth is drawn in several passes (RasterParams.grassShell is the pass, 1 to the count in grassShells' low bits).

#include "shared/rt64_raster_params.h"

#include "FbRendererCommon.hlsli"

[[vk::push_constant]] ConstantBuffer<RasterParams> gConstants : register(b0, space0);

#define FEATHER_INVOCATIONS 32
#define FEATHER_PASS_MASK 0xFFFFu
// (Kept as it was when this shader also grew the 3D grass's blades.)
#define FEATHER_MAX_VERTICES 55

struct FeatherVertex {
    float4 position : SV_POSITION;
    float2 uv : TEXCOORD;
    float4 smoothColor : COLOR0;
    nointerpolation float4 flatColor : COLOR1;
    // Banjo's fur's place on his model (RasterVS.hlsl); unused here, but the shaders on both sides have it.
    float4 furAnchor : TEXCOORD1;
};

float4 FeatherToClip(float3 world) {
    const float4 w = float4(world, 1.0f);
    return float4(dot(FrParams.grassWorldToClip[0], w), dot(FrParams.grassWorldToClip[1], w), dot(FrParams.grassWorldToClip[2], w), dot(FrParams.grassWorldToClip[3], w));
}

float4 FeatherDirToClip(float3 dir) {
    const float4 d = float4(dir, 0.0f);
    return float4(dot(FrParams.grassWorldToClip[0], d), dot(FrParams.grassWorldToClip[1], d), dot(FrParams.grassWorldToClip[2], d), dot(FrParams.grassWorldToClip[3], d));
}

float3 FeatherToWorld(float4 clip) {
    const float4 w = float4(dot(FrParams.grassClipToWorld[0], clip), dot(FrParams.grassClipToWorld[1], clip), dot(FrParams.grassClipToWorld[2], clip), dot(FrParams.grassClipToWorld[3], clip));
    return w.xyz / w.w;
}

// The ground's position as RasterVS made it, back to the same space before its screen scale and offset.
float4 FeatherUnscale(float4 position) {
#ifdef __spirv__
    position.y = -position.y;
#endif
    position.xy = (position.xy - gConstants.screenOffset * position.w) / gConstants.screenScale;
    return position;
}

float4 FeatherRescale(float4 position) {
    position.xy = position.xy * gConstants.screenScale + gConstants.screenOffset * position.w;
#ifdef __spirv__
    position.y = -position.y;
#endif
    return position;
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

void FeatherEmit(inout TriangleStream<FeatherVertex> stream, FeatherVertex v, float4 rootClip, float3 offset, float2 uvOffset, float s, float t, float shade) {
    v.position = FeatherRescale(rootClip + FeatherDirToClip(offset));
    v.uv += uvOffset;
    v.furAnchor.xyz = float3(s, t, shade);
    stream.Append(v);
}

void FeatherCards(triangle FeatherVertex input[3], uint primitive, uint instance, inout TriangleStream<FeatherVertex> stream) {
    const bool npcFeathers = (gConstants.grassShells & RASTER_FEATHER_NPC) != 0;
    const float4 params = npcFeathers ? FrParams.npcFeatherParams : FrParams.featherParams;
    const uint pass = gConstants.grassShell - 1;
    const uint passes = max(gConstants.grassShells & FEATHER_PASS_MASK, 1u);

    float4 clip[3];
    float3 world[3];
    for (int k = 0; k < 3; k++) {
        clip[k] = FeatherUnscale(input[k].position);
        world[k] = FeatherToWorld(clip[k]);
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
    const bool twoSided = (gConstants.grassShells & RASTER_FEATHER_TWO_SIDED) != 0;
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
    const float capacity = float(passes * FEATHER_INVOCATIONS * FEATHERS_PER_INVOCATION);
    const float grow = sqrt(max(wanted / capacity, 1.0f));
    const float count = min(wanted, capacity);
    const uint start = (pass * FEATHER_INVOCATIONS + instance) * FEATHERS_PER_INVOCATION;
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

        FeatherVertex v;
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


[maxvertexcount(FEATHER_MAX_VERTICES)]
[instance(FEATHER_INVOCATIONS)]
void GSMain(triangle FeatherVertex input[3], uint instance : SV_GSInstanceID, uint primitive : SV_PrimitiveID, inout TriangleStream<FeatherVertex> stream) {
    FeatherCards(input, primitive, instance, stream);
}
