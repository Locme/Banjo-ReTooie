//
// RT64
//

// Banjo-Tooie: displaced ground, where the device has hull and domain shaders (D3D12, and Vulkan with
// tessellationShader). Level ground whose texture is in the parallax list, with a floor-like shape (cracks, terraced
// slabs, rounded cobbles, bumpy dirt and so on), is drawn through these in place of its own draw: the hull shader cuts
// each triangle finer near the camera, and the domain shader pushes every new vertex straight down by how deep the
// texture's surface lies there (the same depth Parallax.hlsli finds, ParallaxDepthAt), so the cracks, gaps and grooves
// are real dips in the ground: they change its outline, hide what lies behind them and take the depth buffer with them.
// Straight down in the world, and nothing at all within a few units of the triangle's own edges: the same direction
// for every vertex and no height where it meets another draw, so no crack can open between pieces of ground (the
// game's meshes carry no smooth normals to displace along). The vertex shader leaves the ground where it is
// (RASTER_GROUND_DISPLACE, RasterVS.hlsl) and gives each corner's place in the world in furAnchor, as for the water.
// The pixel shader darkens the deeper parts (the anchor's w, RasterPS.hlsl; -1 on walls, which keep their parallax).
//
// Built twice from this file: HSMain (hull) and DSMain (domain). Both use the ubershader's vertex and pixel shaders,
// whose outputs and inputs GroundVertex matches (as WaterTess.hlsl's WaterVertex).

#include "shared/rt64_raster_params.h"

#include "FbRendererCommon.hlsli"
#include "Parallax.hlsli"

[[vk::push_constant]] ConstantBuffer<RasterParams> gConstants : register(b0, space0);

struct GroundVertex {
    float4 position : SV_POSITION;
    float2 uv : TEXCOORD;
    float4 smoothColor : COLOR0;
    nointerpolation float4 flatColor : COLOR1;
    float4 furAnchor : TEXCOORD1;
};

struct GroundPatch {
    float edges[3] : SV_TessFactor;
    float inside : SV_InsideTessFactor;
};

// How far from a triangle's edges the ground is left as it is, in world units.
static const float GroundEdgeMargin = 24.0f;
// Faces steeper than this (the share of the normal that points up) are walls: left alone.
static const float GroundFloorShare = 0.7f;

// Where a world point lands before the draw's screen scale and offset (as WaterTess.hlsl).
float4 GroundClip(float3 world) {
    const float4 p = float4(world, 1.0f);
    return float4(dot(FrParams.waterWorldToClip[0], p), dot(FrParams.waterWorldToClip[1], p), dot(FrParams.waterWorldToClip[2], p), dot(FrParams.waterWorldToClip[3], p));
}

// How finely an edge between two world points is cut: by its length alone (one piece per few units, never more than the
// cap), so the new vertices stay put in the world as the camera moves and the ground doesn't swim; uncut past the reach,
// where the dips have faded out. By the edge alone, so the triangles either side of it cut it the same way and no cracks
// open. (The camera's distance is to the nearest point on the edge, so a big triangle under the camera is still cut.)
float GroundEdgeFactor(float3 a, float3 b) {
    const float4 params = FrParams.groundParams;
    const float3 ab = b - a;
    const float t = saturate(dot(FrParams.waterCamera.xyz - a, ab) / max(dot(ab, ab), 1e-4f));
    if (distance(a + ab * t, FrParams.waterCamera.xyz) > params.w) {
        return 1.0f;
    }
    return clamp(length(ab) / abs(params.z), 1.0f, params.y);
}

// Whether all three corners lie past one side of the screen (with room for the dips to reach back in).
bool GroundOffScreen(float4 a, float4 b, float4 c) {
    const float m = 1.15f;
    if ((a.w <= 0.0f) && (b.w <= 0.0f) && (c.w <= 0.0f)) {
        return true;
    }
    return ((a.x > a.w * m) && (b.x > b.w * m) && (c.x > c.w * m)) || ((a.x < -a.w * m) && (b.x < -b.w * m) && (c.x < -c.w * m)) ||
        ((a.y > a.w * m) && (b.y > b.w * m) && (c.y > c.w * m)) || ((a.y < -a.w * m) && (b.y < -b.w * m) && (c.y < -c.w * m));
}

GroundPatch GroundPatchConstants(InputPatch<GroundVertex, 3> patch) {
    GroundPatch p;
    const float3 a = patch[0].furAnchor.xyz;
    const float3 b = patch[1].furAnchor.xyz;
    const float3 c = patch[2].furAnchor.xyz;
    p.edges[0] = p.edges[1] = p.edges[2] = 1.0f;
    p.inside = 1.0f;
    const float3 normal = cross(b - a, c - a);
    const float normalLength = length(normal);
    // A wall, or a sliver: drawn as it is.
    if ((normalLength <= 1e-6f) || (abs(normal.y) < GroundFloorShare * normalLength)) {
        return p;
    }
    // Off screen: left out (a factor of 0 draws nothing).
    if (GroundOffScreen(GroundClip(a), GroundClip(b), GroundClip(c))) {
        p.edges[0] = p.edges[1] = p.edges[2] = 0.0f;
        p.inside = 0.0f;
        return p;
    }
    // (Edge 0 is the one across from vertex 0.)
    p.edges[0] = GroundEdgeFactor(b, c);
    p.edges[1] = GroundEdgeFactor(c, a);
    p.edges[2] = GroundEdgeFactor(a, b);
    p.inside = max(p.edges[0], max(p.edges[1], p.edges[2]));
    return p;
}

[domain("tri")]
[partitioning("fractional_odd")]
[outputtopology("triangle_cw")]
[outputcontrolpoints(3)]
[patchconstantfunc("GroundPatchConstants")]
[maxtessfactor(16.0f)]
GroundVertex HSMain(InputPatch<GroundVertex, 3> patch, uint i : SV_OutputControlPointID) {
    return patch[i];
}

[domain("tri")]
GroundVertex DSMain(GroundPatch p, float3 w : SV_DomainLocation, const OutputPatch<GroundVertex, 3> patch) {
    GroundVertex v;
    v.position = patch[0].position * w.x + patch[1].position * w.y + patch[2].position * w.z;
    v.uv = patch[0].uv * w.x + patch[1].uv * w.y + patch[2].uv * w.z;
    v.smoothColor = patch[0].smoothColor * w.x + patch[1].smoothColor * w.y + patch[2].smoothColor * w.z;
    v.flatColor = patch[0].flatColor;
    v.furAnchor = patch[0].furAnchor * w.x + patch[1].furAnchor * w.y + patch[2].furAnchor * w.z;
    // (How much of the dips may show here: 0 on the edge of the displaced ground and where another draw lies over it,
    // the vertex shader's anchor w.)
    const float dipShare = saturate(v.furAnchor.w);
    v.furAnchor.w = 0.0f;

    const float3 a = patch[0].furAnchor.xyz;
    const float3 b = patch[1].furAnchor.xyz;
    const float3 c = patch[2].furAnchor.xyz;
    const float3 normal = cross(b - a, c - a);
    const float normalLength = length(normal);
    const float3 world = v.furAnchor.xyz;
    const float cameraDistance = distance(world, FrParams.waterCamera.xyz);
    // Left as it is on a wall or a sliver, far off, and (below) at the triangle's own edges.
    float fade = 1.0f - smoothstep(FrParams.groundParams.w * 0.75f, FrParams.groundParams.w, cameraDistance);
    if ((normalLength <= 1e-6f) || (abs(normal.y) < GroundFloorShare * normalLength) || (FrParams.groundParams.x <= 0.0f)) {
        fade = 0.0f;
    }
    // (The pixel shader's anchor w: -1 on a wall or a sliver, which is shaded as it was drawn, with its parallax.)
    const bool wall = (normalLength <= 1e-6f) || (abs(normal.y) < GroundFloorShare * normalLength);
    float depthAt = 0.0f;
    if (fade > 0.0f) {
        // The distance to each edge: the corner's share of the triangle's height over that edge.
        const float d0 = w.x * normalLength / max(length(c - b), 1e-4f);
        const float d1 = w.y * normalLength / max(length(a - c), 1e-4f);
        const float d2 = w.z * normalLength / max(length(b - a), 1e-4f);
        fade *= smoothstep(0.0f, GroundEdgeMargin, min(d0, min(d1, d2)));
        fade *= dipShare;
    }
    if (fade > 0.0f) {
        // The draw's first texture, as the pixel shader finds it (the ubershader's tile lookups, RasterPS.hlsl).
        const uint instanceIndex = instanceRenderIndices[gConstants.renderIndex].instanceIndex;
        const RenderParams rp = DynamicRenderParams[instanceIndex];
        const OtherMode otherMode = { rp.omL, rp.omH };
        const uint globalTileIndex = instanceRenderIndices[gConstants.renderIndex].rdpTileIndex;
        RDPTile rdpTile = RDPTiles[globalTileIndex];
        if (!renderFlagDynamicTiles(rp.flags)) {
            rdpTile.cms = renderCMS0(rp.flags);
            rdpTile.cmt = renderCMT0(rp.flags);
            rdpTile.nativeSampler = renderFlagNativeSampler0(rp.flags);
        }
        const GPUTile gpuTile = GPUTiles[globalTileIndex];
        const bool heightMap = gpuTileFlagHasHeight(gpuTile.flags);
        GPUTile heightTile = gpuTile;
        if (heightMap) {
            heightTile = ParallaxHeightTile(gpuTile);
        }
        const uint bits = gConstants.nightLight;
        const uint shape = ((bits >> 25) & 0x7u) | (((bits & RASTER_PARALLAX_SHAPE_HIGH) != 0) ? 8u : 0u);
        const float2 range = float2((bits >> 8) & 0xFF, (bits >> 16) & 0xFF) / 255.0f;

        // The texture's depth, blurred over the spacing of the new vertices (a mip level that wide, and five taps), so
        // a vertex never lands on detail finer than the mesh can show: fine cracks between vertices would make the ground
        // jagged and noisy.
        const float3 span = max(float3(length(b - a), length(c - b), length(a - c)), 1e-3f);
        const float2 uvPerUnit = max(abs(patch[1].uv - patch[0].uv) / span.x, max(abs(patch[2].uv - patch[1].uv) / span.y, abs(patch[0].uv - patch[2].uv) / span.z));
        const float spacing = max(max(span.x, max(span.y, span.z)) / max(p.inside, 1.0f), abs(FrParams.groundParams.z));
        const float2 radius = uvPerUnit * (spacing * 0.5f);
        const float2 ddxUV = float2(radius.x * 2.0f, 0.0f);
        const float2 ddyUV = float2(0.0f, radius.y * 2.0f);
        // (A loop, not five copies: the texture lookup is a big function.)
        float depth = 0.0f;
        [loop]
        for (uint tap = 0; tap < 5; tap++) {
            const float2 offset = (tap == 0) ? float2(0.0f, 0.0f) : ((tap == 1) ? float2(1.0f, 0.0f) : ((tap == 2) ? float2(-1.0f, 0.0f) : ((tap == 3) ? float2(0.0f, 1.0f) : float2(0.0f, -1.0f))));
            depth += ParallaxDepthAt(otherMode, rp.flags, v.uv + offset * radius, ddxUV, ddyUV, rdpTile, heightTile, range, heightMap, shape);
        }
        depthAt = depth * 0.2f * fade;

        // Down by the texture's depth in world units: the Displaced ground setting at its picked depth.
        const uint fineDepth = (bits & RASTER_PARALLAX_FINE_DEPTH) >> RASTER_PARALLAX_FINE_DEPTH_SHIFT;
        const float depthScale = (fineDepth != 0) ? (float(fineDepth) * 0.1f) : ParallaxDepthScale((bits >> 28) & 0x7u);
        float4 up = FrParams.waterClipUp * (-depthAt * FrParams.groundParams.x * depthScale);
        up.xy = up.xy * gConstants.screenScale + gConstants.screenOffset * up.w;
#ifdef __spirv__
        up.y = -up.y;
#endif
        v.position += up;
    }
    v.furAnchor.w = wall ? -1.0f : depthAt;
    return v;
}
