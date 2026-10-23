//
// RT64
//

// Banjo-Tooie: puts the HUD back on an upscaled picture. The upscaler was given the 3D world alone (a copy taken
// before the HUD was drawn), so the HUD does not ghost or shimmer in its history. The HUD is what the finished
// frame has that the world does not, put on the upscaled world as a darkening or a lightening (below). gTexture0 is the upscaled world, gTexture1 the world and gTexture2 the finished
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
    // Each channel the HUD made darker is scaled by the same ratio and each it made lighter is moved the same share of the
    // way to white, so a fade or a wipe to black (the jiggy warp's jigsaw) comes out black, not as the upscaled world minus the
    // world (which left its edges showing). Both give the finished frame back where the upscaled world is the world.
    // jitter.x is 1 for a high dynamic range target, which is not limited to 0..1: lighter parts are added there.
    const bool hdr = (gConstants.jitter.x > 0.5f);
    float3 color;
    [unroll] for (int i = 0; i < 3; i++) {
        const float u = upscaled[i];
        const float w = world[i];
        const float f = finished[i];
        if (f <= w) {
            color[i] = (w > 1e-3f) ? u * (f / w) : f;
        }
        else if (!hdr && (w < 0.999f)) {
            color[i] = u + (1.0f - u) * saturate((f - w) / (1.0f - w));
        }
        else {
            color[i] = u + (f - w);
        }
    }
    if (!hdr) {
        color = saturate(color);
    }
    return float4(color, 1.0f);
}
