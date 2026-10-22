//
// RT64
//

// Banjo-Tooie: SMAA 1x on the finished game image, before the VI draws it. SMAA.hlsl, AreaTex.h and
// SearchTex.h are iryoku/smaa (MIT), kept in the game's repository under lib/smaa. One of SMAA_PASS_EDGES,
// SMAA_PASS_WEIGHTS or SMAA_PASS_BLEND picks the pass, and SMAA_PRESET_* the quality.

#include "shared/rt64_smaa.h"

[[vk::push_constant]] ConstantBuffer<SmaaCB> gConstants : register(b0);

// Edges: colour. Weights: edges, area, search. Blend: colour, weights.
Texture2D<float4> gTexture0 : register(t1);
Texture2D<float4> gTexture1 : register(t2);
Texture2D<float4> gTexture2 : register(t3);
SamplerState LinearSampler : register(s4);
SamplerState PointSampler : register(s5);

#define SMAA_RT_METRICS gConstants.rtMetrics
#define SMAA_CUSTOM_SL
#define SMAATexture2D(tex) Texture2D tex
#define SMAATexturePass2D(tex) tex
#define SMAASampleLevelZero(tex, coord) tex.SampleLevel(LinearSampler, coord, 0)
#define SMAASampleLevelZeroPoint(tex, coord) tex.SampleLevel(PointSampler, coord, 0)
#define SMAASampleLevelZeroOffset(tex, coord, offset) tex.SampleLevel(LinearSampler, coord, 0, offset)
#define SMAASample(tex, coord) tex.Sample(LinearSampler, coord)
#define SMAASamplePoint(tex, coord) tex.Sample(PointSampler, coord)
#define SMAASampleOffset(tex, coord, offset) tex.Sample(LinearSampler, coord, offset)
#define SMAA_FLATTEN [flatten]
#define SMAA_BRANCH [branch]

#include "SMAA.hlsl"

float4 PSMain(in float4 pos : SV_Position, in float2 uv : TEXCOORD0) : SV_TARGET {
    // SMAA's vertex shader parts only offset the coordinates, so they run here.
#if defined(SMAA_PASS_EDGES)
    float4 offset[3];
    SMAAEdgeDetectionVS(uv, offset);
    return float4(SMAALumaEdgeDetectionPS(uv, offset, gTexture0), 0.0f, 0.0f);
#elif defined(SMAA_PASS_WEIGHTS)
    float2 pixcoord;
    float4 offset[3];
    SMAABlendingWeightCalculationVS(uv, pixcoord, offset);
    return SMAABlendingWeightCalculationPS(uv, pixcoord, offset, gTexture0, gTexture1, gTexture2, float4(0.0f, 0.0f, 0.0f, 0.0f));
#else
    float4 offset;
    SMAANeighborhoodBlendingVS(uv, offset);
    return SMAANeighborhoodBlendingPS(uv, offset, gTexture0, gTexture1);
#endif
}
