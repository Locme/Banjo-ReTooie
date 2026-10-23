//
// RT64
//

// Banjo-Tooie: Qualcomm's Snapdragon Game Super Resolution 1 (third-party/snapdragon-gsr, BSD 3-Clause), a
// single-pass spatial upscaler for mobile. Android builds only. The game image is gTexture0; sizes.xy is its size
// in pixels, sizes.zw the output's.

#include "shared/rt64_temporal_upscaler.h"

[[vk::push_constant]] ConstantBuffer<UpscalerResolveCB> gConstants : register(b0);

Texture2D<float4> gTexture0 : register(t1);
Texture2D<float4> gTexture1 : register(t2);
Texture2D<float4> gTexture2 : register(t3);
SamplerState LinearSampler : register(s4);
SamplerState PointSampler : register(s5);

#define SGSR_MOBILE
#define SGSR_H 1

half4 SGSRRGBH(float2 p) { return gTexture0.SampleLevel(LinearSampler, p, 0); }
half4 SGSRRH(float2 p) { return gTexture0.GatherRed(LinearSampler, p); }
half4 SGSRGH(float2 p) { return gTexture0.GatherGreen(LinearSampler, p); }
half4 SGSRBH(float2 p) { return gTexture0.GatherBlue(LinearSampler, p); }
half4 SGSRAH(float2 p) { return gTexture0.GatherAlpha(LinearSampler, p); }

half4 SGSRH(float2 p, uint channel) {
    if (channel == 0) return SGSRRH(p);
    if (channel == 1) return SGSRGH(p);
    if (channel == 2) return SGSRBH(p);
    return SGSRAH(p);
}

#include "sgsr1_mobile.h"

float4 PSMain(in float4 pos : SV_Position, in float2 uv : TEXCOORD0) : SV_TARGET0 {
    const float2 inSize = gConstants.sizes.xy;
    const float2 outSize = gConstants.sizes.zw;
    const float2 coord = pos.xy / outSize;
    half4 color = half4(0, 0, 0, 1);
    SgsrYuvH(color, coord, float4(1.0f / inSize.x, 1.0f / inSize.y, inSize.x, inSize.y));
    return float4(color);
}
