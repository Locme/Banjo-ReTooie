//
// RT64
//
// Include guard: DXC on Windows reaches a file here by two spellings of its path (from a file beside it,
// and through -I), so it must not rely on #pragma once.
#ifndef RT64_EXT_SHADERS_WATERTESS_HLSLI
#define RT64_EXT_SHADERS_WATERTESS_HLSLI

// Banjo-Tooie: tessellated Modern and Stylised water's height above its flat surface (WaterTess.hlsl raises the surface
// by it; SceneEffectsPS.hlsl shades the surface by its slope, so the light follows the same waves). In world units.
//   world: the point (x, z; y the flat surface's height).
//   t: the waves' clock in seconds. swell: the swell's height (Water waves). speed: the swell's speed.
//   player: x, z, y (y below -1e8 when there is none), how hard they push the water (0 to 1).
//   velocity: theirs over the water (x, z). rings: the rings' full height.
float WaterTessHeight(float3 world, float t, float swell, float speed, float4 player, float2 velocity, float rings) {
    // The swell: two slow sines crossing, one longer and taller.
    float h = swell * (sin(dot(world.xz, float2(0.0219f, 0.0137f)) + t * 0.9f * speed) + 0.55f * sin(dot(world.xz, float2(-0.0153f, 0.0311f)) + t * 1.3f * speed));
    // The player's rings: a sine spreading out from them, fading with distance, and stretched behind them as they move
    // (a wake). Only on the water they are in (near their height).
    if ((player.z > -1e8f) && (player.w > 0.001f) && (world.y > player.z - 60.0f) && (world.y < player.z + 160.0f)) {
        const float speedNow = length(velocity);
        const float2 along = (speedNow > 1.0f) ? velocity / speedNow : float2(0.0f, 0.0f);
        float2 d = world.xz - player.xy;
        // Behind them the rings are drawn out (up to twice as far apart): a wake.
        const float behind = max(-dot(d, along), 0.0f);
        const float stretch = 1.0f + saturate(speedNow / 300.0f);
        d -= along * (behind * (1.0f - 1.0f / stretch));
        const float r = length(d);
        const float k = 6.2831853f / 45.0f;
        const float ring = sin(k * r - t * 7.0f);
        // Faint right on the player (their body is there), strongest a little way out, gone by about 300 units.
        const float fade = smoothstep(10.0f, 40.0f, r) * exp(-r / 110.0f);
        h += rings * player.w * ring * fade;
    }
    return h;
}

#endif // RT64_EXT_SHADERS_WATERTESS_HLSLI
