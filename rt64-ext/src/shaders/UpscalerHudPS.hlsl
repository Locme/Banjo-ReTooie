//
// RT64
//

// Banjo-Tooie: puts the HUD back on an upscaled picture. The upscaler was given the 3D world alone (a copy taken
// before the HUD was drawn), so the HUD does not ghost or shimmer in its history. The HUD is what the finished
// frame has that the world does not: with = world blended with the HUD, so with - world is the HUD's part, and it
// is added to the upscaled world. gTexture0 is the upscaled world, gTexture1 the world and gTexture2 the finished
// frame, both at the game's size and sampled bilinearly up to the output.

#include "shared/rt64_temporal_upscaler.h"

[[vk::push_constant]] ConstantBuffer<UpscalerResolveCB> gConstants : register(b0);

Texture2D<float4> gTexture0 : register(t1);
Texture2D<float4> gTexture1 : register(t2);
Texture2D<float4> gTexture2 : register(t3);
SamplerState LinearSampler : register(s4);
SamplerState PointSampler : register(s5);

float4 PSMain(in float4 pos : SV_Position, in float2 uv : TEXCOORD0) : SV_TARGET0 {
    const float2 outSize = gConstants.sizes.zw;
    const float2 coord = pos.xy / outSize;
    const float4 upscaled = gTexture0.Load(int3(int2(pos.xy), 0));
    const float3 world = gTexture1.SampleLevel(LinearSampler, coord, 0).rgb;
    const float3 finished = gTexture2.SampleLevel(LinearSampler, coord, 0).rgb;
    float3 color = upscaled.rgb + (finished - world);
    // jitter.x is 1 for a high dynamic range target, which is not limited to 0..1.
    if (gConstants.jitter.x < 0.5f) {
        color = saturate(color);
    }
    return float4(color, 1.0f);
}
