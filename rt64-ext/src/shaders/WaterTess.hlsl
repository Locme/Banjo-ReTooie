//
// RT64
//

// Banjo-Tooie: Modern and Stylised water as a real moving surface, where the device has hull and domain shaders (D3D12,
// and Vulkan with tessellationShader). The game's flat water draws are drawn into the scene effects' water mask (and its
// colours) through these: the hull shader cuts each triangle finer near the camera and round the player (capped low, and
// not at all past Water detail's reach), and leaves out triangles wholly off screen; the domain shader raises and lowers
// every new vertex by a slow swell over all the water and the rings the player pushes out as they move through it. The
// effects pass then shades the surface the mask holds (SceneEffectsPS.hlsl): its waves are real bumps in it, with two
// scrolling normal maps for the fine ripples. Nothing is simulated: the rings are a sine spreading from where the player
// is, from their position and velocity this frame (FrameParams.waterPlayer and waterMotion).
//
// Built twice from this file: HSMain (hull) and DSMain (domain). Both use the ubershader's vertex and pixel shaders,
// whose outputs and inputs WaterVertex matches (as SnowTess.hlsl's SnowVertex).

#include "shared/rt64_raster_params.h"

#include "FbRendererCommon.hlsli"
#include "WaterTess.hlsli"

[[vk::push_constant]] ConstantBuffer<RasterParams> gConstants : register(b0, space0);

struct WaterVertex {
    float4 position : SV_POSITION;
    float2 uv : TEXCOORD;
    float4 smoothColor : COLOR0;
    nointerpolation float4 flatColor : COLOR1;
    float4 furAnchor : TEXCOORD1;
};

struct WaterPatch {
    float edges[3] : SV_TessFactor;
    float inside : SV_InsideTessFactor;
};

// Where a world point lands before the draw's screen scale and offset (as RasterVS's position before them).
float4 WaterClip(float3 world) {
    const float4 p = float4(world, 1.0f);
    return float4(dot(FrParams.waterWorldToClip[0], p), dot(FrParams.waterWorldToClip[1], p), dot(FrParams.waterWorldToClip[2], p), dot(FrParams.waterWorldToClip[3], p));
}

// How finely an edge between two world points is cut: finer near the camera, only round the player, never more than
// the cap. By the edge alone, so the triangles either side of it cut it the same way and no cracks open.
float WaterEdgeFactor(float3 a, float3 b) {
    const float3 middle = (a + b) * 0.5f;
    const float2 player = FrParams.waterPlayer.xy;
    const float reach = FrParams.waterTess.z;
    const float round = (FrParams.waterPlayer.z > -1e8f) ? (1.0f - smoothstep(reach * 0.6f, reach, distance(middle.xz, player))) : 0.0f;
    const float near = 1.0f - smoothstep(0.0f, FrParams.waterTess.w, distance(middle, FrParams.waterCamera.xyz));
    const float wanted = 1.0f + (FrParams.waterTess.x - 1.0f) * round * near;
    // (No finer than the shortest piece: a short edge needs no cutting.)
    return clamp(min(wanted, distance(a, b) / FrParams.waterTess.y), 1.0f, FrParams.waterTess.x);
}

// Whether all three corners lie past one side of the screen (with room for the waves to reach back in).
bool WaterOffScreen(float4 a, float4 b, float4 c) {
    const float m = 1.15f;
    if ((a.w <= 0.0f) && (b.w <= 0.0f) && (c.w <= 0.0f)) {
        return true;
    }
    // A corner behind the camera has its x and y flipped, so the side tests below could leave out water that runs
    // under the camera (as GroundOffScreen did with the floor). Such a triangle is kept.
    if ((a.w <= 0.0f) || (b.w <= 0.0f) || (c.w <= 0.0f)) {
        return false;
    }
    return ((a.x > a.w * m) && (b.x > b.w * m) && (c.x > c.w * m)) || ((a.x < -a.w * m) && (b.x < -b.w * m) && (c.x < -c.w * m)) ||
        ((a.y > a.w * m) && (b.y > b.w * m) && (c.y > c.w * m)) || ((a.y < -a.w * m) && (b.y < -b.w * m) && (c.y < -c.w * m));
}

WaterPatch WaterPatchConstants(InputPatch<WaterVertex, 3> patch) {
    WaterPatch p;
    // The corners' places in the world, from RasterVS (furAnchor).
    const float3 a = patch[0].furAnchor.xyz;
    const float3 b = patch[1].furAnchor.xyz;
    const float3 c = patch[2].furAnchor.xyz;
    // Off screen: left out (a factor of 0 draws nothing).
    if (WaterOffScreen(WaterClip(a), WaterClip(b), WaterClip(c))) {
        p.edges[0] = p.edges[1] = p.edges[2] = 0.0f;
        p.inside = 0.0f;
        return p;
    }
    // (Edge 0 is the one across from vertex 0.)
    p.edges[0] = WaterEdgeFactor(b, c);
    p.edges[1] = WaterEdgeFactor(c, a);
    p.edges[2] = WaterEdgeFactor(a, b);
    p.inside = max(p.edges[0], max(p.edges[1], p.edges[2]));
    return p;
}

[domain("tri")]
[partitioning("fractional_odd")]
[outputtopology("triangle_cw")]
[outputcontrolpoints(3)]
[patchconstantfunc("WaterPatchConstants")]
[maxtessfactor(16.0f)]
WaterVertex HSMain(InputPatch<WaterVertex, 3> patch, uint i : SV_OutputControlPointID) {
    return patch[i];
}

// The water's height above its flat surface at a world point (WaterTess.hlsli), with this frame's waves and player.
float WaterHeight(float3 world) {
    return WaterTessHeight(world, FrParams.waterMotion.z, FrParams.waterSwell.x, FrParams.waterSwell.y, FrParams.waterPlayer,
        FrParams.waterMotion.xy, FrParams.waterMotion.w);
}

[domain("tri")]
WaterVertex DSMain(WaterPatch p, float3 w : SV_DomainLocation, const OutputPatch<WaterVertex, 3> patch) {
    WaterVertex v;
    v.position = patch[0].position * w.x + patch[1].position * w.y + patch[2].position * w.z;
    v.uv = patch[0].uv * w.x + patch[1].uv * w.y + patch[2].uv * w.z;
    v.smoothColor = patch[0].smoothColor * w.x + patch[1].smoothColor * w.y + patch[2].smoothColor * w.z;
    v.flatColor = patch[0].flatColor;
    v.furAnchor = patch[0].furAnchor * w.x + patch[1].furAnchor * w.y + patch[2].furAnchor * w.z;

    // Raised or lowered straight up in the world, then through the draw's screen scale and offset as the position was.
    const float height = WaterHeight(v.furAnchor.xyz);
    float4 up = FrParams.waterClipUp * height;
    up.xy = up.xy * gConstants.screenScale + gConstants.screenOffset * up.w;
#ifdef __spirv__
    up.y = -up.y;
#endif
    v.position += up;
    return v;
}
