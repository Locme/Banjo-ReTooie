//
// RT64
//

// Banjo-Tooie: the motion of the camera, as a temporal upscaler (FSR, DLSS) wants it: for each pixel, how far
// its surface was from where it is now one frame ago, in pixels (previous minus current, y down). It is worked
// out from the depth: the pixel's view-space position goes through the previous camera. Things that move on
// their own are not in it.

#include "shared/rt64_temporal_upscaler.h"

#include "Depth.hlsli"

[[vk::push_constant]] ConstantBuffer<UpscalerVelocityCB> gConstants : register(b0);

Texture2D<float4> gTexture0 : register(t1);
Texture2D<float4> gTexture1 : register(t2);
Texture2D<float4> gTexture2 : register(t3); // The objects' velocity, when extra.x is 1.
SamplerState LinearSampler : register(s4);
SamplerState PointSampler : register(s5);

// The scene's depth in [0, 1] as RT64 keeps it: gTexture1 holds the depth-to-color copy, an N64 16-bit depth value
// packed as RGBA 5551 (as PhotoGradePS.hlsl reads it).
float SceneDepth(int2 pixel) {
    const float4 c = gTexture1.Load(int3(pixel, 0));
    if (gConstants.flags.z < 0.5f) {
        return c.r;
    }
    const uint r = uint(round(saturate(c.r) * 255.0f)) >> 3;
    const uint g = uint(round(saturate(c.g) * 255.0f)) >> 3;
    const uint b = uint(round(saturate(c.b) * 255.0f)) >> 3;
    const uint a = (c.a > 0.5f) ? 1u : 0u;
    return Depth16ToFloat((r << 11) | (g << 6) | (b << 1) | a);
}

float4 PSMain(in float4 pos : SV_Position, in float2 uv : TEXCOORD0) : SV_TARGET0 {
    const int2 pixel = int2(pos.xy);
    // flags.x above 1.5: just the depth as a float, for DLSS.
    if (gConstants.flags.x > 1.5f) {
        return float4(SceneDepth(pixel), 0.0f, 0.0f, 0.0f);
    }
    const float2 size = gConstants.projection.zw;
    const float4 t = gConstants.depthTerms;

    // The view-space position (the camera looks along -z), as ViewPosition in SceneEffectsPS.hlsl.
    const float ndcZ = SceneDepth(pixel) * 2.0f - 1.0f;
    const float z = (t.y - ndcZ * t.w) / (ndcZ * t.z - t.x);
    const float2 ndc = float2((pixel.x + 0.5f) / size.x * 2.0f - 1.0f, 1.0f - (pixel.y + 0.5f) / size.y * 2.0f);
    const float3 view = float3(ndc.x * -z / gConstants.projection.x, ndc.y * -z / gConstants.projection.y, z);

    const float4 previous = view.x * gConstants.reproject0 + view.y * gConstants.reproject1 + view.z * gConstants.reproject2 + gConstants.reproject3;
    float2 velocity = float2(0.0f, 0.0f);
    // The see-through draws' reactive value, for the built-in resolve (it has no slot for the mask itself).
    float reactive = 0.0f;
    if ((gConstants.flags.w < 0.5f) && (abs(previous.w) > 1e-6f)) {
        const float2 previousNdc = previous.xy / previous.w;
        velocity = float2((previousNdc.x - ndc.x) * 0.5f * size.x, (ndc.y - previousNdc.y) * 0.5f * size.y);
    }

    // Things that move on their own: the objects' pass wrote their velocity (alpha 1), complete with the camera's part.
    if (gConstants.extra.x > 0.5f) {
        const float4 object = gTexture2.Load(int3(pixel, 0));
        if (object.a > 0.5f) {
            velocity = object.xy;
        }
        reactive = object.z;
    }

    if (gConstants.flags.x > 0.5f) {
        const float scale = max(gConstants.flags.y, 1e-3f);
        return float4(0.5f + velocity.x / (2.0f * scale), 0.5f + velocity.y / (2.0f * scale), 0.5f, 1.0f);
    }
    return float4(velocity, reactive, 0.0f);
}
