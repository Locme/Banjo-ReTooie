//
// RT64
//
// Banjo-Tooie: the scene effects' bloom. Pass 0 keeps the bright parts of the scene at a quarter of its
// size (four bilinear taps cover each 4x4 block), passes 1 and 2 blur them across and down, pass 5 takes
// them down to an eighth for a wider glow and pass 6 adds the two. Passes 3
// and 4 measure the scene's brightness and adapt to it over time for eye adaptation, and pass 9 works out Keep Game
// Look's gain from two such measurements. Pass 8 copies the scene at
// half size for the bounce light.

#include "shared/rt64_scene_effects.h"

[[vk::push_constant]] ConstantBuffer<BloomCB> gConstants : register(b0);

Texture2D<float4> gTexture0 : register(t1);
Texture2D<float4> gTexture1 : register(t2);
Texture2D<float4> gTexture2 : register(t3);
SamplerState LinearSampler : register(s4);
SamplerState PointSampler : register(s5);

float4 PSMain(in float4 pos : SV_Position, in float2 uv : TEXCOORD0) : SV_TARGET {
    const float2 texel = gConstants.params.xy;
    const uint pass = uint(gConstants.params.z + 0.5f);
    if (pass == 3) {
        // The scene's average brightness (geometric mean over a 16x16 grid), into one pixel.
        float sum = 0.0f;
        [loop] for (int y = 0; y < 16; y++) {
            [loop] for (int x = 0; x < 16; x++) {
                const float2 at = (float2(x, y) + 0.5f) / 16.0f;
                const float3 c = saturate(gTexture0.SampleLevel(LinearSampler, at, 0).rgb);
                sum += log(max(dot(c, float3(0.2126f, 0.7152f, 0.0722f)), 0.002f));
            }
        }
        return float4(exp(sum / 256.0f), 0.0f, 0.0f, 1.0f);
    }
    else if (pass == 4) {
        // The adapted brightness moves towards the measured one (gTexture0) from where it was (gTexture1);
        // the measured one is kept beside it.
        const float measured = gTexture0.Load(int3(0, 0, 0)).r;
        const float previous = gTexture1.Load(int3(0, 0, 0)).r;
        // Like eyes, getting used to the light is quick (half a second) and to the dark slow (four seconds), so
        // the fades between areas barely move it; a black screen (a fade, a cut) doesn't move it at all.
        const float seconds = -log(max(1.0f - gConstants.params.w, 1e-4f));
        const float rate = (measured < 0.03f) ? 0.0f : (1.0f - exp(-seconds * ((measured > previous) ? 2.0f : 0.25f)));
        const float adapted = (previous > 0.0f) ? lerp(previous, measured, rate) : measured;
        return float4(adapted, measured, 0.0f, 1.0f);
    }
    else if (pass == 10) {
        // Keep Game Look: the picture's plain average brightness over a 64x64 grid, into one pixel. Not the geometric mean
        // of pass 3: deep shadows pull that down so far that matching it brightened the rest of a dark room too much. A
        // 16x16 grid was too few points to compare a shadowed picture with the game's fairly (Jolly's came out a third
        // brighter than the game).
        float sum = 0.0f;
        [loop] for (int y = 0; y < 64; y++) {
            [loop] for (int x = 0; x < 64; x++) {
                const float2 at = (float2(x, y) + 0.5f) / 64.0f;
                sum += dot(saturate(gTexture0.SampleLevel(LinearSampler, at, 0).rgb), float3(0.2126f, 0.7152f, 0.0722f));
            }
        }
        return float4(sum / 4096.0f, 0.0f, 0.0f, 1.0f);
    }
    else if (pass == 9) {
        // Keep Game Look: the gain that brings the brightness of the picture the effects drew (gTexture0, measured with
        // last frame's gain in it) to the game's own (gTexture1), moved towards from last frame's (gTexture2) over about
        // half a second. A black screen (a fade, a cut) leaves it where it is. g = 1: on.
        const float drawn = gTexture0.Load(int3(0, 0, 0)).r;
        const float game = gTexture1.Load(int3(0, 0, 0)).r;
        const float2 last = gTexture2.Load(int3(0, 0, 0)).rg;
        const float previous = (last.g > 0.5f) ? last.r : 1.0f;
        if ((drawn < 0.01f) || (game < 0.01f)) {
            return float4(previous, 1.0f, 0.0f, 1.0f);
        }
        const float wanted = clamp(previous * game / drawn, 0.4f, 2.5f);
        const float seconds = -log(max(1.0f - gConstants.params.w, 1e-4f));
        const float rate = 1.0f - exp(-seconds * 2.0f);
        return float4(lerp(previous, wanted, rate), 1.0f, 0.0f, 1.0f);
    }
    if (pass == 7) {
        // Modern water's ripples: one step of the wave equation on the grid (r height, g speed), read from where
        // the grid was before it moved with the player, pushed down where the player is.
        const int2 size = int2(round(1.0f / texel));
        const int2 cell = int2(pos.xy);
        const int2 from = cell + int2(gConstants.waterSim.xy);
        float2 state = 0.0f;
        float neighbours = 0.0f;
        if (all(from >= 0) && all(from < size)) {
            state = gTexture0.Load(int3(from, 0)).rg;
            [unroll] for (int i = 0; i < 4; i++) {
                const int2 n = from + ((i == 0) ? int2(1, 0) : (i == 1) ? int2(-1, 0) : (i == 2) ? int2(0, 1) : int2(0, -1));
                neighbours += (all(n >= 0) && all(n < size)) ? gTexture0.Load(int3(n, 0)).r : 0.0f;
            }
        }
        float h = state.r;
        float v = state.g;
        v += (neighbours - 4.0f * h) * 0.45f;
        // The player: pushed down at their spot, softly round its edge.
        const float d = length(float2(cell) + 0.5f - gConstants.waterSim.zw);
        const float r = max(gConstants.waterPush.y, 1.0f);
        v -= gConstants.waterPush.x * exp(-(d * d) / (r * r));
        // A splash pushes a wider patch much harder for one step.
        v -= gConstants.waterPush.z * exp(-(d * d) / (4.0f * r * r));
        v *= gConstants.waterPush.w;
        h = (h + v) * 0.9995f;
        // Calm towards the grid's edges, so nothing reflects off them.
        const float2 edge = min(float2(cell), float2(size - 1 - cell)) / (float2(size) * 0.12f);
        const float calm = saturate(min(edge.x, edge.y));
        return float4(h * calm, v * calm, 0.0f, 1.0f);
    }
    if (pass == 8) {
        // A plain copy at half the size, for the bounce light: the one bilinear tap at the half pixel's centre
        // averages its four pixels.
        return float4(gTexture0.SampleLevel(LinearSampler, uv, 0).rgb, 1.0f);
    }
    if (pass == 0) {
        float3 color = 0.0f;
        color += gTexture0.SampleLevel(LinearSampler, uv + texel * float2(-1.0f, -1.0f), 0).rgb;
        color += gTexture0.SampleLevel(LinearSampler, uv + texel * float2(1.0f, -1.0f), 0).rgb;
        color += gTexture0.SampleLevel(LinearSampler, uv + texel * float2(-1.0f, 1.0f), 0).rgb;
        color += gTexture0.SampleLevel(LinearSampler, uv + texel * float2(1.0f, 1.0f), 0).rgb;
        color = saturate(color * 0.25f);
        // What is brighter than the threshold, easing in over a soft knee instead of switching on, so the
        // glow doesn't flicker on textures right at the threshold. Measured on the brightness, so a fully
        // saturated red or blue doesn't count as bright as white.
        const float threshold = gConstants.params.w;
        const float knee = 0.12f;
        const float brightness = max(dot(color, float3(0.2126f, 0.7152f, 0.0722f)), max(color.r, max(color.g, color.b)) * 0.6f);
        float soft = clamp(brightness - threshold + knee, 0.0f, 2.0f * knee);
        soft = soft * soft / (4.0f * knee);
        const float keep = max(soft, brightness - threshold) / max(brightness, 1e-4f);
        return float4(color * keep, 1.0f);
    }
    else if (pass == 5) {
        // Down to an eighth: four bilinear taps cover each 4x4 block of the quarter.
        float3 color = 0.0f;
        color += gTexture0.SampleLevel(LinearSampler, uv + texel * float2(-1.0f, -1.0f), 0).rgb;
        color += gTexture0.SampleLevel(LinearSampler, uv + texel * float2(1.0f, -1.0f), 0).rgb;
        color += gTexture0.SampleLevel(LinearSampler, uv + texel * float2(-1.0f, 1.0f), 0).rgb;
        color += gTexture0.SampleLevel(LinearSampler, uv + texel * float2(1.0f, 1.0f), 0).rgb;
        return float4(color * 0.25f, 1.0f);
    }
    else if (pass == 6) {
        // The tight glow and the wide one together.
        const float3 tight = gTexture0.SampleLevel(LinearSampler, uv, 0).rgb;
        const float3 wide = gTexture1.SampleLevel(LinearSampler, uv, 0).rgb;
        return float4(tight * 0.6f + wide * 0.9f, 1.0f);
    }

    // A 9-tap Gaussian, its taps spread 1.5 texels apart for a wider glow.
    const float2 step = (pass == 1) ? float2(texel.x, 0.0f) : float2(0.0f, texel.y);
    const float weights[5] = { 0.227027f, 0.1945946f, 0.1216216f, 0.054054f, 0.016216f };
    float3 color = gTexture0.SampleLevel(LinearSampler, uv, 0).rgb * weights[0];
    [unroll] for (int i = 1; i < 5; i++) {
        const float2 offset = step * (1.5f * float(i));
        color += gTexture0.SampleLevel(LinearSampler, uv + offset, 0).rgb * weights[i];
        color += gTexture0.SampleLevel(LinearSampler, uv - offset, 0).rgb * weights[i];
    }

    return float4(color, 1.0f);
}
