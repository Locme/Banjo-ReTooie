//
// RT64
//

// Banjo-Tooie: puts the HUD, drawn at the output size over black (gTexture1) and over white (gTexture2), on the upscaled
// world (gTexture0). A draw that blends with what is under it gives result = f + g * under, per colour channel; over
// black that is f, over white f + g, so g = white - black and the HUD on the world is black + world * (white - black).

#include "shared/rt64_temporal_upscaler.h"

[[vk::push_constant]] ConstantBuffer<UpscalerResolveCB> gConstants : register(b0);

Texture2D<float4> gTexture0 : register(t1);
Texture2D<float4> gTexture1 : register(t2);
Texture2D<float4> gTexture2 : register(t3);
SamplerState LinearSampler : register(s4);
SamplerState PointSampler : register(s5);

float4 PSMain(in float4 pos : SV_Position, in float2 uv : TEXCOORD0) : SV_TARGET0 {
    const int3 pixel = int3(int2(pos.xy), 0);
    const float3 world = gTexture0.Load(pixel).rgb;
    const float3 overBlack = gTexture1.Load(pixel).rgb;
    const float3 overWhite = gTexture2.Load(pixel).rgb;
    float3 color = overBlack + world * (overWhite - overBlack);
    // jitter.x is 1 for a high dynamic range target, which is not limited to 0..1.
    if (gConstants.jitter.x < 0.5f) {
        color = saturate(color);
    }
    return float4(color, 1.0f);
}
