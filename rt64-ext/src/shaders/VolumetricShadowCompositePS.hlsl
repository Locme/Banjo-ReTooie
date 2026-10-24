//
// RT64
//
// Banjo-Tooie: volumetric shadows' composite pass (VolumetricShadows.hlsli), over the 3D world before the HUD. The haze
// dims what is behind it (the alpha, blended as dst * a + rgb) and adds its light: the sun's from the lit stretches of
// each ray (the volume pass inside the sun's map, worked out here past its edges, where nothing is known to shade it),
// the sky's dim light everywhere, and the lamps' glow.

#include "VolumetricShadows.hlsli"

Texture2D<float> gSunMap : register(t2);
Texture2D<float2> gGathered : register(t4);

// The sun's light gathered along the ray outside its map's box, where it all counts as lit.
float SunOutsideMap(float3 camera, float3 ray, float distance) {
    const float3 q = camera - gConstants.lightD.xyz;
    const float3 extent = float3(gConstants.lightA.w, gConstants.lightA.w, gConstants.lightB.w);
    const float3 o = float3(dot(q, gConstants.lightA.xyz), dot(q, gConstants.lightB.xyz), dot(q, gConstants.lightC.xyz)) / extent;
    const float3 d = float3(dot(ray, gConstants.lightA.xyz), dot(ray, gConstants.lightB.xyz), dot(ray, gConstants.lightC.xyz)) / extent;
    const float3 tiny = float3(abs(d) <= 1e-8f);
    const float3 inv = 1.0f / (d * (1.0f - tiny) + 1e-8f * tiny);
    const float3 ta = (-1.0f - o) * inv;
    const float3 tb = (1.0f - o) * inv;
    const float3 lo = min(ta, tb);
    const float3 hi = max(ta, tb);
    const float enter = max(max(lo.x, lo.y), lo.z);
    const float leave = min(min(hi.x, hi.y), hi.z);
    if ((leave <= enter) || (leave <= 0.0f)) {
        return SunGathered(distance);
    }
    const float a = clamp(enter, 0.0f, distance);
    const float b = clamp(leave, 0.0f, distance);
    return SunGathered(a) + (SunGathered(distance) - SunGathered(b));
}

// Henyey-Greenstein, half and half with even scattering, so the haze is brightest looking towards the sun but still
// lit looking away.
float SunPhase(float cosine) {
    const float g = gConstants.sunColor.w;
    const float hg = (1.0f - g * g) / pow(max(1.0f + g * g - 2.0f * g * cosine, 1e-4f), 1.5f);
    return 0.5f + 0.5f * hg;
}

float4 PSMain(in float4 pos : SV_Position) : SV_Target {
    const int2 pixel = int2(pos.xy);
    const float distance = SceneDistance(pixel);
    const float3 camera = CameraWorld();
    const float3 ray = normalize(PixelRay(float2(pixel) + 0.5f));

    // The gathered light, at half size picked from the four nearest by how close their distance is to this pixel's,
    // so it doesn't bleed over the edges of things.
    float2 gathered;
    const int scale = int(gConstants.medium.w);
    if (scale <= 1) {
        gathered = gGathered.Load(int3(pixel, 0));
    }
    else {
        const float2 at = (float2(pixel) + 0.5f) / float(scale) - 0.5f;
        const int2 base = int2(floor(at));
        const float2 f = at - float2(base);
        uint width, height;
        gGathered.GetDimensions(width, height);
        const int2 size = int2(width, height);
        float2 sum = 0.0f;
        float weights = 0.0f;
        [unroll] for (int i = 0; i < 4; i++) {
            const int2 offset = int2(i & 1, i >> 1);
            const int2 q = clamp(base + offset, int2(0, 0), size - 1);
            const float bilinear = ((offset.x == 1) ? f.x : (1.0f - f.x)) * ((offset.y == 1) ? f.y : (1.0f - f.y));
            const float there = SceneDistance(GatheredToPicture(q));
            const float w = (bilinear + 1e-3f) / (0.02f + abs(there - distance) / max(distance, 1.0f));
            sum += gGathered.Load(int3(q, 0)) * w;
            weights += w;
        }
        gathered = sum / max(weights, 1e-6f);
    }

    float3 light = 0.0f;
    if (any(gConstants.sunColor.rgb > 0.0f)) {
        const float lit = max(gathered.x + SunOutsideMap(camera, ray, distance), 0.0f);
        light += gConstants.sunColor.rgb * (SunPhase(dot(ray, gConstants.lightC.xyz)) * lit);
    }
    light += gConstants.ambient.rgb * SunGathered(distance);
    // The lamps' glow: warm, as the game's torches and lanterns are.
    light += float3(1.0f, 0.72f, 0.42f) * max(gathered.y, 0.0f);
    // The views for testing: only the light (over black), and with the sun's map (near the sun white, far dark).
    if (gConstants.medium.z > 0.5f) {
        if ((gConstants.medium.z > 1.5f) && all(pixel < int2(384, 384))) {
            const int size = int(gConstants.lightC.w);
            const float depth = gSunMap.Load(int3(pixel * size / 384, 0));
            return float4((1.0f - depth).xxx, 0.0f);
        }
        return float4(light, 0.0f);
    }
    return float4(light, exp(-gConstants.ambient.w * distance));
}
