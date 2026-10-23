//
// RT64
//

// Banjo-Tooie: the built-in temporal resolve. The game image was drawn with a small camera jitter that changes
// every frame, so each frame has samples at slightly different places. Here they are gathered round each output
// pixel (the jitter taken into account), mixed with last frame's result moved along the camera's motion, and the
// old part is clamped to what the new neighbourhood allows so it cannot ghost. At an output larger than the game
// image this is an upscale; at the same size it is an anti-aliasing.

#include "shared/rt64_temporal_upscaler.h"

[[vk::push_constant]] ConstantBuffer<UpscalerResolveCB> gConstants : register(b0);

Texture2D<float4> gTexture0 : register(t1); // The game image.
Texture2D<float4> gTexture1 : register(t2); // The velocity, in input pixels.
Texture2D<float4> gTexture2 : register(t3); // Last frame's result.
SamplerState LinearSampler : register(s4);
SamplerState PointSampler : register(s5);

float4 PSMain(in float4 pos : SV_Position, in float2 uv : TEXCOORD0) : SV_TARGET0 {
    const float2 inSize = gConstants.sizes.xy;
    const float2 outSize = gConstants.sizes.zw;
    const float2 jitter = gConstants.jitter.xy;

    // The output pixel's place in input pixels, where the middle of input pixel i is i + 0.5.
    const float2 q = (pos.xy / outSize) * inSize;
    const int2 base = int2(floor(q));
    const int2 maxPixel = int2(inSize) - 1;

    float3 sum = 0.0f;
    float3 sum3 = 0.0f;
    float weights = 0.0f;
    float3 lowest = 1e9f;
    float3 highest = -1e9f;
    [unroll] for (int y = -1; y <= 1; y++) {
        [unroll] for (int x = -1; x <= 1; x++) {
            const int2 p = clamp(base + int2(x, y), int2(0, 0), maxPixel);
            const float3 c = gTexture0.Load(int3(p, 0)).rgb;
            // Where this sample sits in the image drawn without jitter: the jitter moved the picture by jitter pixels.
            const float2 at = float2(p) + 0.5f - jitter;
            const float2 d = at - q;
            // A sharper kernel when upscaling, so the output keeps the detail.
            const float w = exp(-2.3f * dot(d, d));
            sum += c * w;
            sum3 += c;
            weights += w;
            lowest = min(lowest, c);
            highest = max(highest, c);
        }
    }
    float3 current = sum / max(weights, 1e-4f);
    // Sharpening (Graphics > Upscaler > Sharpness): the new samples' weighted mean pushed away from their plain mean,
    // within what the neighbourhood holds so it cannot ring.
    if (gConstants.extra.x > 0.0f) {
        const float3 plain = (sum3 / 9.0f);
        current = clamp(current + (current - plain) * gConstants.extra.x * 2.0f, lowest, highest);
    }

    float3 result = current;
    if (gConstants.jitter.z > 0.5f) {
        const int2 center = clamp(base, int2(0, 0), maxPixel);
        const float4 motion = gTexture1.Load(int3(center, 0));
        const float2 velocity = motion.xy;
        const float2 historyUV = (q + velocity) / inSize;
        if (all(historyUV > 0.0f) && all(historyUV < 1.0f)) {
            const float3 history = gTexture2.SampleLevel(LinearSampler, historyUV, 0).rgb;
            const float3 clamped = clamp(history, lowest, highest);
            // Less of the old part when it had to be clamped hard (a thing moved or came uncovered).
            const float rejected = saturate(length(history - clamped) * 4.0f);
            // See-through things (particles, fire, spray) take more of the new picture.
            const float blend = lerp(lerp(gConstants.jitter.w, 1.0f, rejected), 1.0f, saturate(motion.z));
            result = lerp(clamped, current, blend);
        }
    }
    return float4(result, 1.0f);
}
