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

// The world position a pixel of the full picture shows (the sky as far as medium.y).
float3 PixelWorld(int2 pixel) {
    return CameraWorld() + normalize(PixelRay(float2(pixel) + 0.5f)) * SceneDistance(pixel);
}

// How much of the sun a surface gets from the feature's own map (0 shaded, 1 lit), 3 x 3 texels round it, and fading out
// over the map's last tenth so its edge doesn't show. The surface's normal comes from its neighbours' depths (the nearer
// of each pair, so an edge doesn't bend it), and the spot is moved out along it by a texel and a half, so a surface
// doesn't shade itself. Facing away from the sun counts as shaded.
float SurfaceSun(int2 pixel, float3 camera, float distance) {
    const float3 world = PixelWorld(pixel);
    const float3 right = PixelWorld(pixel + int2(1, 0)) - world;
    const float3 left = world - PixelWorld(pixel - int2(1, 0));
    const float3 down = PixelWorld(pixel + int2(0, 1)) - world;
    const float3 up = world - PixelWorld(pixel - int2(0, 1));
    const float3 dx = (dot(right, right) < dot(left, left)) ? right : left;
    const float3 dy = (dot(down, down) < dot(up, up)) ? down : up;
    float3 normal = cross(dy, dx);
    if (dot(normal, normal) < 1e-12f) {
        return 1.0f;
    }
    normal = normalize(normal);
    // Facing the camera.
    if (dot(normal, camera - world) < 0.0f) {
        normal = -normal;
    }
    const float facing = dot(normal, gConstants.lightC.xyz);
    const int size = int(gConstants.lightC.w);
    const float texel = 2.0f * gConstants.lightA.w / float(size);
    const float3 m = WorldToSunMap(world + normal * (1.5f * texel));
    const float edge = max(abs(m.x), abs(m.y));
    if ((edge >= 1.0f) || (m.z <= 0.0f) || (m.z >= 1.0f)) {
        return 1.0f;
    }
    const float2 at = float2(m.x * 0.5f + 0.5f, 0.5f - m.y * 0.5f) * float(size) - 0.5f;
    const int2 base = int2(floor(at));
    // A texel and a half in depth, so a surface at a slant to the sun doesn't shade itself between texels.
    const float bias = texel / (2.0f * gConstants.lightB.w) * 1.5f;
    float lit = 0.0f;
    [unroll] for (int y = -1; y <= 1; y++) {
        [unroll] for (int x = -1; x <= 1; x++) {
            const int2 q = clamp(base + int2(x, y), int2(0, 0), int2(size - 1, size - 1));
            lit += (m.z - bias <= gSunMap.Load(int3(q, 0))) ? 1.0f : 0.0f;
        }
    }
    lit *= 1.0f / 9.0f;
    lit *= saturate(facing * 6.0f);
    return lerp(lit, 1.0f, saturate((edge - 0.9f) * 10.0f));
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
        // The map's corner is a third of the picture's height.
        const int corner = max(int(gConstants.projection.w) / 3, 1);
        if ((gConstants.medium.z > 1.5f) && all(pixel < int2(corner, corner))) {
            const int size = int(gConstants.lightC.w);
            const float depth = gSunMap.Load(int3(pixel * size / corner, 0));
            return float4((1.0f - depth).xxx, 0.0f);
        }
        return float4(light, 0.0f);
    }
    // The surfaces in the sun's shade (lightD.w: how dark, 0 to 1), not the sky or what is past the sky's distance.
    float behind = exp(-gConstants.ambient.w * distance);
    if ((gConstants.lightD.w > 0.0f) && any(gConstants.sunColor.rgb > 0.0f) && (distance < gConstants.medium.y)) {
        behind *= 1.0f - gConstants.lightD.w * (1.0f - SurfaceSun(pixel, camera, distance));
    }
    return float4(light, behind);
}
