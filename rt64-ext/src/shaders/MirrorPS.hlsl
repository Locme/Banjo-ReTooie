//
// RT64
//

// Banjo-Tooie: Mirror Mode. Copies the finished game image flipped left to right.

#include "shared/rt64_smaa.h"

[[vk::push_constant]] ConstantBuffer<SmaaCB> gConstants : register(b0);

Texture2D<float4> gTexture0 : register(t1);
Texture2D<float4> gTexture1 : register(t2);
Texture2D<float4> gTexture2 : register(t3);
SamplerState LinearSampler : register(s4);
SamplerState PointSampler : register(s5);

float4 PSMain(in float4 pos : SV_Position, in float2 uv : TEXCOORD0) : SV_TARGET {
    return gTexture0.SampleLevel(PointSampler, float2(1.0f - uv.x, uv.y), 0);
}
