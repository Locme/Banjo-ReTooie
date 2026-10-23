//
// RT64
//

// Banjo-Tooie: see ObjectVelocityVS.hlsl. Writes the velocity in pixels (previous minus current, y down) and 1 in alpha.

#include "shared/rt64_temporal_upscaler.h"

[[vk::push_constant]] ConstantBuffer<UpscalerObjectVelocityCB> gConstants : register(b0);

float4 PSMain(in float4 pos : SV_Position, in float3 previous : TEXCOORD0) : SV_TARGET0 {
    const float2 size = gConstants.size.xy;
    float2 velocity = float2(0.0f, 0.0f);
    if (abs(previous.z) > 1e-6f) {
        const float2 ndc = float2(pos.x / size.x * 2.0f - 1.0f, 1.0f - pos.y / size.y * 2.0f);
        const float2 previousNdc = previous.xy / previous.z;
        velocity = float2((previousNdc.x - ndc.x) * 0.5f * size.x, (ndc.y - previousNdc.y) * 0.5f * size.y);
    }
    return float4(velocity, 0.0f, 1.0f);
}
