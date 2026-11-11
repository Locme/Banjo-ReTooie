//
// RT64
//
// Banjo-Tooie: screen-space effects over the 3D world, drawn after its last perspective draw and before
// the HUD, with only the scene's depth as input. The output is blended as dst * a + rgb, so ambient
// occlusion and outlines darken with a, and fog and bloom add its color in rgb as a fades the scene.
// Built with INDIRECT_PASS it is the indirect pass instead: GTAO and SSGI at half size, which this pass reads.

#include "shared/rt64_scene_effects.h"
#ifdef RAY_TRACED
#include "shared/rt64_gpu_tile.h"
#include "shared/rt64_rdp_tile.h"
#endif
#include "SunShadowMap.hlsli"
#include "WaterTess.hlsli"

[[vk::push_constant]] ConstantBuffer<SceneEffectsCB> gConstants : register(b0);

#if defined(SAMPLES_8X) || defined(SAMPLES_4X) || defined(SAMPLES_2X)
#   define MULTISAMPLING
Texture2DMS<float> gInput : register(t1);
#else
Texture2D<float> gInput : register(t1);
#endif
Texture2D<float4> gBloom : register(t2);
SamplerState LinearSampler : register(s3);
Texture2D<float4> gColor : register(t4);
Texture2D<float2> gAdapted : register(t5);
#ifdef MULTISAMPLING
Texture2DMS<float4> gWater : register(t6);
Texture2DMS<float4> gWaterColor : register(t7);
#else
Texture2D<float4> gWater : register(t6);
Texture2D<float4> gWaterColor : register(t7);
#endif
// Modern water's ripple grid round the player: height and speed per cell (rippleX/Z.x hold its corner).
Texture2D<float2> gWaterRipples : register(t8);
// The sun shadow map (SunShadowMap.hlsli), when shadows.y is negative.
Texture2D<float> gSunShadowMap : register(t9);
// The fireflies' table for this frame (FireflyPlace), 162 by 3, written by the FIREFLY_TABLE pass: rows 0 and 1 the
// fireflies, row 2 the depth of field's focus distance (DepthOfFieldFocus) in its first pixel.
Texture2D<float4> gFireflies : register(t10);
// The scene at half size (BloomPS pass 8), for the bounce light's colour samples.
Texture2D<float4> gColorHalf : register(t11);
// The indirect pass (INDIRECT_PASS) at half size: SSGI's light (rgb) and GTAO's visibility (a), for IndirectAt.
Texture2D<float4> gIndirect : register(t12);
// Banjo-Tooie: the volumetric settings' extras (VolExtra): four floats in the first 16 bytes (SetSceneVolumetricExtra in
// rt64_scene_effects.cpp). Bound whether or not the device has ray queries.
ByteAddressBuffer gDust : register(t16);
// Ray traced denoising: the indirect pass's target of the pass before (its four bands, the last each texel's distance), which
// the indirect pass blends its new rays into (DenoiseBlend). Something else is bound when denoising is off; it is never read then.
Texture2D<float4> gHistory : register(t17);
#ifdef RAY_TRACED
// Banjo-Tooie: the 3D world's solid triangles in world space (Graphics > Ray tracing), rebuilt each frame; only in
// the RAY_TRACED variant of the pass, which is used while the device has ray queries and the structure is built.
RaytracingAccelerationStructure gSceneBVH : register(t13);
// The level's lights: the count (as a float) in the first 16 bytes, then x, y, z (world) and the outer range of each.
ByteAddressBuffer gLights : register(t14);
// The world radiance cache (Graphics > Ray tracing hit colours): what the screen showed at each spot of the world, in
// 16-unit cells (a hash of the cell, then the colour), so a ray that lands where the picture can't see it still finds
// the colour the surface had when it was last on screen.
RWByteAddressBuffer gRadianceCache : register(u15);
// What the rays read the textures of the triangles they meet with (SceneRayTexturesDescriptorSet, then the texture cache
// at space2): the traced scene's geometries (first index, tile, flags (1 cut-out, 2 textured), 0), the frame's index
// buffer, texture coordinates (two floats a vertex) and tiles.
ByteAddressBuffer gRayGeometries : register(t0, space1);
ByteAddressBuffer gRayIndices : register(t1, space1);
ByteAddressBuffer gRayTexcoords : register(t2, space1);
StructuredBuffer<RDPTile> gRayRDPTiles : register(t3, space1);
StructuredBuffer<GPUTile> gRayGPUTiles : register(t4, space1);
// The world positions the traced structure was built from (four floats a vertex), for the face a ray met (HitFaceNormal).
ByteAddressBuffer gRayPositions : register(t5, space1);
Texture2D<float4> gRayTextures[8192] : register(t0, space2);
#endif

// A surface's Ray Tracing Material Pick Mode material (production PBR): the albedo it is tinted by, roughness and
// metalness (0 to 1) and emissive (1 is as bright again). The index sits above Parallax's shape in a geometry's material
// word; the records follow both ranges of geometries in the same buffer (SceneMaxRayMaterials + 1 of them from entry
// SCENE_RAY_MATERIAL_BASE).
struct RayPbr {
    bool present;
    float3 albedo;
    float roughness;
    float metalness;
    float emissive;
    float subsurface;
};

RayPbr RayPbrNone() {
    RayPbr none;
    none.present = false;
    none.albedo = 1.0f;
    none.roughness = 0.5f;
    none.metalness = 0.0f;
    none.emissive = 0.0f;
    none.subsurface = 0.0f;
    return none;
}

// The colour a material tints its surface's own (diffuse) colour with: a metal's albedo is what it tints its reflection
// with, and the texture already has its colour, so the more metal the less it is tinted twice.
float3 DiffuseAlbedo(RayPbr material) {
    return lerp(material.albedo, 1.0f, material.metalness);
}

// Ray Tracing Material Pick Mode: whether the traced scene holds a surface with a material of that mode's (lights word 9,
// bit 2 (value 4); the traced scene's records follow its geometries).
// The same word carries the Ray traced BRDF roughness (percent times 8) and the subsurface scattering strength (percent times 1024).
#ifdef RAY_TRACED
uint RayHeaderWord() {
    return uint(asfloat(gLights.Load(36)) + 0.5f);
}
bool RayPbrOn() {
    return (RayHeaderWord() & 4u) != 0u;
}
float RayBrdfRoughness() {
    return float((RayHeaderWord() >> 3u) & 127u) / 100.0f;
}
float RaySssStrength() {
    return float((RayHeaderWord() >> 10u) & 127u) / 100.0f;
}
// Traced relighting (0 to 1): how much of the game's own shading the traced sun and sky light take over (Relit).
float RayRelight() {
    return float(RayHeaderWord() >> 17u) / 100.0f;
}
// Whether the traced scene has anything subsurface scattering lights without a Ray Tracing Material (lights word 10: leaves
// or grass, with the Parallax materials in use).
bool RaySubsurfaceScene() {
    return asfloat(gLights.Load(40)) > 0.5f;
}
#else
bool RayPbrOn() {
    return false;
}
float RayBrdfRoughness() {
    return 0.0f;
}
float RaySssStrength() {
    return 0.0f;
}
float RayRelight() {
    return 0.0f;
}
#endif

// Eye adaptation: brightens a dark scene and tones down a bright one around a middle key, keeping black
// black and white white (out = c * e / (1 + c * (e - 1))).
float3 Adapt(float3 color) {
    const float2 brightness = max(gAdapted.Load(int3(0, 0, 0)), 0.002f);
    const float adapted = brightness.x;
    const float measured = brightness.y;
    // Like eyes: coming out into the light the picture is too bright for a moment and settles, going into the
    // dark it is too dark for a moment and opens up. Once settled a dark place stays a little brighter and a
    // glaring one a little darker than the game draws them, so the look of a level is kept.
    const float moment = (measured < 0.03f) ? 1.0f : clamp(pow(measured / adapted, 0.7f), 0.35f, 3.0f);
    const float settled = clamp(pow(0.3f / adapted, 0.25f), 0.8f, 1.4f);
    const float exposure = lerp(1.0f, moment * settled, gConstants.bloom.z);
    const float3 c = saturate(color);
    // Half a curve that keeps black and white where they are, half a straight scale, so a bright moment can
    // glare out to white and a dark one dims the highlights too.
    return lerp(c * exposure / (1.0f + c * (exposure - 1.0f)), saturate(c * exposure), 0.5f);
}

// Underwater: the scene turns light blue and fades into a light blue haze with distance (the sky is all haze).
float3 Underwater(float3 color, float distance) {
    // Both settings rise quickly at first and keep rising up to 100, so low values show and high ones still add.
    const float tint = 1.0f - pow(1.0f - saturate(gConstants.fog.w), 3.0f);
    // Light blue: less red, a little less green, and lifted towards a light blue so dark water brightens too
    // (scaling the colour alone only darkened it).
    const float3 tinted = color * float3(0.6f, 0.8f, 0.9f) + float3(0.1f, 0.2f, 0.26f);
    // Thickens within the few hundred units of a pool, not only across a whole level.
    const float haze = (1.0f - pow(1.0f - saturate(gConstants.bloom.w), 4.0f)) * (1.0f - exp(-distance / 900.0f));
    return lerp(lerp(color, tinted, tint), float3(0.36f, 0.6f, 0.74f), haze);
}

// Day and night cycle: the 3D world's tint, packed in shadows.z as 1 + three 7-bit channels (steps of 0.01) and
// three flags (bit 0 fireflies, bit 1 clouds, bit 2 northern lights), negative for no lens flare. False (and no tint) while the cycle is off.
uint DayPacked() {
    const float packedFloat = abs(gConstants.shadows.z);
    // The float holds the whole number exactly (below 2^24), so take it as it is: adding a half to round, as this
    // did, rounded odd values up to the next even one above 2^23 (any daylight tint), which turned the clouds and
    // fireflies flags into the northern lights' one.
    return (packedFloat < 1.0f) ? 0u : (uint(packedFloat) - 1u);
}

bool DayTint(out float3 tint) {
    tint = 1.0f;
    if (abs(gConstants.shadows.z) < 1.0f) {
        return false;
    }
    const uint packed = DayPacked();
    tint = float3(float((packed >> 17) & 127u), float((packed >> 10) & 127u), float((packed >> 3) & 127u)) / 100.0f;
    return true;
}

// How much of the night has come in, from how dark the tint's brightest channel is (0 day, 1 night), so a warm
// sunset still counts as day.
float DayNight(float3 tint) {
    return saturate((0.97f - max(tint.r, max(tint.g, tint.b))) / 0.3f);
}

// The day and night cycle's weather, from the light shafts' constant (see rt64_scene_effects.h): rain (0 to 1),
// the shafts' strength and lightning (0 to 1).
float3 DayWeather() {
    const float w = gConstants.sun.w;
    if (w >= 0.0f) {
        return float3(0.0f, w, 0.0f);
    }
    const float v = -w - 1.0f;
    const float whole = floor(v);
    const uint packed = uint(whole + 0.5f);
    return float3(float((packed >> 8) & 255u) / 255.0f, float(packed & 255u) / 255.0f, v - whole);
}

// The moon's phase, 0 to 7 (0 new, 4 full).
uint DayMoonPhase() {
    const float w = gConstants.sun.w;
    return (w < 0.0f) ? ((uint(floor(-w - 1.0f) + 0.5f) >> 17) & 7u) : 4u;
}

// True when the weather's rain falls as snow.
bool DaySnow() {
    const float w = gConstants.sun.w;
    return (w < 0.0f) && (((uint(floor(-w - 1.0f) + 0.5f) >> 16) & 1u) != 0u);
}

// Rain greys and darkens what it falls on (snow a little less); lightning lights it all up for a moment.
float3 DayWeatherLight(float3 color, float rain, float flash, float amount) {
    if (DaySnow()) {
        rain *= 0.5f;
    }
    const float grey = dot(color, float3(0.3f, 0.59f, 0.11f));
    color = lerp(color, grey.xxx * float3(0.92f, 0.96f, 1.0f), rain * 0.4f) * (1.0f - rain * amount);
    return color + (color * 1.6f + float3(0.06f, 0.07f, 0.1f)) * flash;
}

// The world under the tint. The brightest parts (lamps, lava, glowing things) keep more of their light the darker
// it gets, so they stand out at night.
// Colours fade towards grey as night comes in, as moonlight does, so the tint reads as blue rather than as a
// darker version of the day's colours.
// glow: whether a bright colour may stay lit at night as a light. Not on water and waterfalls, whose pale
// colours would otherwise shine out of the dark.
float3 DayWorld(float3 color, float3 tint, bool glow) {
    const float night = DayNight(tint);
    // Golden hour: in the warm light after sunrise and before sunset, colours grow richer.
    const float warmth = saturate((tint.r - tint.b) * 2.5f) * (1.0f - night);
    color = saturate(lerp(dot(color, float3(0.3f, 0.59f, 0.11f)).xxx, color, 1.0f + 0.3f * warmth));
    const float bright = glow ? smoothstep(0.7f, 0.98f, max(color.r, max(color.g, color.b))) : 0.0f;
    const float3 faded = lerp(color, dot(color, float3(0.3f, 0.59f, 0.11f)).xxx, 0.5f * night * (1.0f - bright));
    return faded * lerp(tint, 1.0f, bright * night * 0.6f);
}

float DayHash(float3 p) {
    p = frac(p * 0.3183099f + 0.1f) * 17.0f;
    return frac(p.x * p.y * p.z * (p.x + p.y + p.z));
}

// Day and night cycle's clouds: value noise on a lattice, smooth between its points (0 to 1).
float CloudNoise(float3 p) {
    const float3 i = floor(p);
    float3 f = p - i;
    f = f * f * (3.0f - 2.0f * f);
    const int3 c = int3(i);
    float v[8];
    [unroll]
    for (int k = 0; k < 8; k++) {
        uint3 q = uint3(c + int3(k & 1, (k >> 1) & 1, (k >> 2) & 1));
        uint h = q.x * 73856093u ^ q.y * 19349663u ^ q.z * 83492791u;
        h = (h ^ (h >> 13)) * 0x5bd1e995u;
        h ^= h >> 15;
        v[k] = float(h & 0xFFFFu) / 65535.0f;
    }
    const float x00 = lerp(v[0], v[1], f.x);
    const float x10 = lerp(v[2], v[3], f.x);
    const float x01 = lerp(v[4], v[5], f.x);
    const float x11 = lerp(v[6], v[7], f.x);
    return lerp(lerp(x00, x10, f.y), lerp(x01, x11, f.y), f.z);
}

// The cloud shape packed in view.y (PackSceneClouds in rt64_scene_effects.cpp): cover (0 to 1), height (0.0625 to 4),
// thickness (0.1 to 2) and wind speed (0 to 8). The sign is F8 compare.
float4 CloudShape() {
    const float packedValue = gConstants.view.y;
    const uint packed = uint(((packedValue < 0.0f) ? (-packedValue - 1.0f) : packedValue) + 0.5f);
    const float4 f = float4(packed & 63u, (packed >> 6) & 63u, (packed >> 12) & 63u, (packed >> 18) & 63u) / 63.0f;
    const float speed = f.w * sqrt(8.0f);
    return float4(f.x, exp2(lerp(-4.0f, 2.0f, f.y)), lerp(0.1f, 2.0f, f.z), speed * speed);
}

// How thick the cloud is at a point of the layer (in layer units, 0 at its floor, 1 at its top), 0 for clear air.
float CloudDensity(float3 p, int octaves, float rain) {
    const float time = gConstants.view.z;
    // Drifts slowly with the wind, the small shapes a little faster so the clouds churn as they go.
    const float3 wind = float3(time * 0.012f, 0.0f, time * 0.005f) * CloudShape().w;
    float n = CloudNoise(p * 0.55f + wind) * 0.6f;
    n += CloudNoise(p * 1.4f + wind * 1.6f + 13.7f) * 0.27f;
    if (octaves > 2) {
        n += CloudNoise(p * 3.6f + wind * 2.5f + 41.3f) * 0.13f;
    }
    // Round bottoms that thin out towards the top.
    const float height = saturate(p.y);
    const float shape = smoothstep(0.0f, 0.18f, height) * smoothstep(1.0f, 0.45f, height);
    // How much of the sky they cover (the Cloud Amount setting: 0.5 the usual); rain spreads them over all of it.
    const float cover = CloudShape().x;
    const float threshold = (cover < 0.5f) ? lerp(0.82f, 0.52f, cover * 2.0f) : lerp(0.52f, 0.26f, (cover - 0.5f) * 2.0f);
    return saturate((n - lerp(threshold, min(threshold, 0.3f), rain)) * 3.5f) * shape;
}

// Soft clouds over the sky, marched through a layer above the camera. Returns the cloud's colour and how much it
// covers (0 to 1). Lit from the sun by day (warm at sunrise and sunset, a bright edge round it when it is behind
// them) and faintly from the moon at night, and they darken with the tint like the rest of the sky.
float4 DayClouds(float3 world, float3 sunWorld, float3 tint, float glow, int2 pixel, float3 weather) {
    const float rain = weather.x;
    if (world.y < 0.015f) {
        return 0.0f;
    }
    const float night = DayNight(tint);
    // The layer from its height to its height + thickness (1 to 1.6 usually, in its own units) above the camera;
    // walking about moves it a little.
    const float3 camera = float3(gConstants.worldX.w, 0.0f, gConstants.worldZ.w) / 9000.0f;
    // Its height and thickness from the Cloud Height and Cloud Thickness settings.
    const float base = CloudShape().y;
    const float depth = CloudShape().z;
    const float start = base / world.y;
    const float end = min((base + depth) / world.y, start + 3.0f * max(base, 1.0f));
    const int steps = 10;
    const float stride = (end - start) / steps;
    // A different start in each pixel, so the steps don't show as bands.
    float t = start + stride * DayHash(float3(pixel, 7.0f));
    const float3 sunColor = lerp(float3(1.0f, 0.96f, 0.9f), float3(1.0f, 0.6f, 0.32f), glow);
    // Rain clouds are darker and lit less by the sun.
    const float3 light = lerp(sunColor * 1.15f, float3(0.32f, 0.38f, 0.55f), night) * (1.0f - rain * 0.75f) + weather.z * 2.5f;
    const float3 ambient = lerp(float3(0.62f, 0.68f, 0.8f), float3(0.08f, 0.1f, 0.16f), night) * (1.0f - rain * 0.35f) + weather.z * 0.8f;
    // Brighter looking towards the light (light through the cloud's edges).
    const float toward = dot(world, sunWorld);
    const float phase = 0.55f + 0.9f * pow(saturate(toward), 8.0f);
    float transmittance = 1.0f;
    float3 color = 0.0f;
    [loop]
    for (int i = 0; i < steps; i++) {
        float3 p = world * t + camera;
        p.y = world.y * t - base;
        p.y /= depth;
        const float density = CloudDensity(p, 3, rain);
        if (density > 0.01f) {
            // How much cloud lies between here and the light.
            const float toLight = CloudDensity(p + sunWorld * 0.25f, 2, rain) + CloudDensity(p + sunWorld * 0.6f, 2, rain) * 0.6f;
            const float lit = exp(-toLight * 3.0f);
            // A darker underside.
            const float base = lerp(0.6f, 1.0f, saturate(p.y));
            const float3 c = (light * lit * phase + ambient * base) * pow(tint, 1.2f);
            const float alpha = 1.0f - exp(-density * stride * 6.0f);
            color += c * alpha * transmittance;
            transmittance *= 1.0f - alpha;
            if (transmittance < 0.03f) {
                break;
            }
        }
        t += stride;
    }
    // Thin out into the distance, so the layer doesn't end in a line at the horizon.
    const float fade = smoothstep(0.015f, 0.12f, world.y);
    return float4(color, 1.0f - transmittance) * fade;
}

// The sky under the tint: it darkens more than the world, glows warm round the sun near the horizon when the tint
// is warm (sunrise and sunset), and at night shows stars fixed in the world and the moon (the sun constant's
// direction, which the cycle points at the moon at night).
// The sun in the sky while the day and night cycle is off and the sun shadows are on (shadows.z = 0.5, see
// rt64_scene_effects.cpp): the same disc and glow as the cycle's by day (DaySky), added over the sky where the sun
// shadows' light comes from.
bool HeldSunShown() {
    return abs(gConstants.shadows.z - 0.5f) < 0.25f;
}

float3 HeldSun(int2 pixel) {
    const float2 ndc = float2((pixel.x + 0.5f) / gConstants.projection.z * 2.0f - 1.0f, 1.0f - (pixel.y + 0.5f) / gConstants.projection.w * 2.0f);
    const float3 look = normalize(float3(ndc.x / gConstants.projection.x, ndc.y / gConstants.projection.y, -1.0f));
    const float toward = saturate(dot(look, gConstants.sun.xyz));
    const float3 sunColor = float3(1.0f, 0.97f, 0.88f);
    const float disc = smoothstep(0.99955f, 0.99975f, toward);
    return sunColor * (disc * 1.1f + pow(toward, 600.0f) * 0.6f + pow(toward, 60.0f) * 0.15f);
}

// The cloud types' darkness (used as the rain's: greys and darkens the clouds and spreads them over the sky) and how
// warm the light on them is (0 to 1), by type: 1 Fair, 2 Scattered, 3 Overcast, 4 Stormy, 5 Wispy, 6 Sunset, 7 Thunderstorm.
float VolCloudDarkness(uint type) {
    const float table[8] = { 0.0f, 0.0f, 0.0f, 0.45f, 0.92f, 0.0f, 0.0f, 1.0f };
    return table[type & 7u];
}

float VolCloudWarmth(uint type) {
    return (type == 6u) ? 0.9f : 0.0f;
}

float3 DaySky(float3 color, int2 pixel, float3 tint) {
    const float2 ndc = float2((pixel.x + 0.5f) / gConstants.projection.z * 2.0f - 1.0f, 1.0f - (pixel.y + 0.5f) / gConstants.projection.w * 2.0f);
    const float3 look = normalize(float3(ndc.x / gConstants.projection.x, ndc.y / gConstants.projection.y, -1.0f));
    const float3 world = normalize(float3(dot(look, gConstants.worldX.xyz), dot(look, gConstants.worldY.xyz), dot(look, gConstants.worldZ.xyz)));
    const float night = DayNight(tint);
    const float3 weather = DayWeather();
    const float rain = weather.x;
    float3 sky = lerp(color, dot(color, float3(0.3f, 0.59f, 0.11f)).xxx, 0.6f * night) * pow(tint, 1.7f);
    // Overcast in the rain: a flat grey sky, no sun, moon or stars.
    const float3 overcast = DaySnow() ? float3(0.72f, 0.74f, 0.78f) : float3(0.5f, 0.53f, 0.58f);
    sky = lerp(sky, overcast * pow(tint, 1.7f), rain * 0.8f);

    const float toward = saturate(dot(look, gConstants.sun.xyz));
    const float horizon = 1.0f - saturate(abs(world.y) * 2.5f);
    const float glow = saturate((tint.r - tint.b) * 2.2f) * (1.0f - night);
    sky += float3(1.0f, 0.55f, 0.25f) * glow * (pow(toward, 3.0f) * 0.6f + 0.25f) * horizon;

    if ((night > 0.0f) && (world.y > 0.0f) && (rain < 0.99f)) {
        const float3 before = sky;
        // One star at most in each cell of a grid round the camera, at a random place in it, twinkling.
        const float3 grid = world * 160.0f;
        const float3 cell = floor(grid);
        const float pick = DayHash(cell);
        if (pick > 0.9f) {
            const float3 place = cell + 0.5f + (float3(DayHash(cell + 17.0f), DayHash(cell + 31.0f), DayHash(cell + 53.0f)) - 0.5f) * 0.6f;
            // About a pixel and a half to three pixels across at 1080p, whatever the resolution's step.
            const float size = (0.18f + 0.18f * DayHash(cell + 71.0f)) * saturate(1080.0f / gConstants.projection.w) * 1.4f;
            const float twinkle = 0.7f + 0.3f * sin(gConstants.view.z * 3.0f + pick * 400.0f);
            const float star = saturate(1.0f - length(grid - place) / size) * twinkle;
            sky += float3(0.9f, 0.93f, 1.0f) * (star * 1.6f) * night * saturate(world.y * 5.0f);
        }
        // Now and then a shooting star: in each six-second slot one time in three, a short streak down part of the
        // sky that fades as it goes.
        {
            const float time = gConstants.view.z;
            const float slot = floor(time / 6.0f);
            if (DayHash(float3(slot, 1.7f, 9.1f)) < 0.35f) {
                const float t = (time - slot * 6.0f - 2.0f * DayHash(float3(slot, 4.3f, 2.2f))) / 0.7f;
                if ((t > 0.0f) && (t < 1.4f)) {
                    const float azimuth = DayHash(float3(slot, 8.8f, 5.5f)) * 6.2831853f;
                    const float elevation = 0.35f + 0.4f * DayHash(float3(slot, 3.1f, 7.7f));
                    const float turn = (0.25f + 0.2f * DayHash(float3(slot, 6.6f, 1.1f))) * ((DayHash(float3(slot, 2.4f, 8.3f)) < 0.5f) ? -1.0f : 1.0f);
                    const float drop = elevation - 0.15f - 0.1f * DayHash(float3(slot, 9.9f, 4.4f));
                    const float3 from = float3(cos(elevation) * cos(azimuth), sin(elevation), cos(elevation) * sin(azimuth));
                    const float3 to = float3(cos(drop) * cos(azimuth + turn), sin(drop), cos(drop) * sin(azimuth + turn));
                    const float3 normal = normalize(cross(from, to));
                    const float off = abs(dot(world, normal));
                    const float3 onArc = normalize(world - normal * dot(world, normal));
                    const float span = acos(saturate(dot(from, to)));
                    const float along = acos(clamp(dot(from, onArc), -1.0f, 1.0f)) / span * ((dot(cross(from, onArc), normal) >= 0.0f) ? 1.0f : -1.0f);
                    const float head = saturate(t);
                    const float trail = smoothstep(head - 0.35f, head, along) * step(along, head);
                    const float pixelAngle = 2.0f / (gConstants.projection.y * gConstants.projection.w);
                    const float width = pixelAngle * 1.2f;
                    const float streak = saturate(1.0f - off / width);
                    const float fade = 1.0f - saturate((t - 1.0f) / 0.4f);
                    sky += float3(1.0f, 0.95f, 0.85f) * (streak * trail * fade * 1.5f) * night;
                }
            }
        }
        // The moon, with a faint halo, in its phase: the part in shadow is cut off by a second disc beside it,
        // on the right while it waxes and the left while it wanes, and only just shows.
        const float disc = smoothstep(0.99925f, 0.99945f, toward);
        const uint phase = DayMoonPhase();
        float lit = 1.0f;
        if ((phase != 4u) && (disc > 0.0f)) {
            const float3 across = look - gConstants.sun.xyz * dot(look, gConstants.sun.xyz);
            const float3 side = normalize(cross(gConstants.sun.xyz, float3(0.0f, 1.0f, 0.0f)));
            const float2 local = float2(dot(across, side), dot(across, normalize(cross(side, gConstants.sun.xyz)))) / 0.036f;
            // How far the shadow's disc sits from the moon's, in moon radii: 0 covers it all (new), 2 none.
            const float shift = float(phase < 4u ? phase : 8u - phase) * 0.5f;
            const float2 shadow = float2((phase < 4u) ? -shift : shift, 0.0f);
            lit = smoothstep(0.92f, 1.0f, length(local - shadow));
        }
        sky = lerp(sky, float3(0.92f, 0.94f, 1.0f) * lerp(0.08f, 1.0f, lit), disc * night);
        const float fullness = 1.0f - abs(float(phase) - 4.0f) / 4.0f;
        sky += float3(0.25f, 0.3f, 0.45f) * pow(toward, 40.0f) * 0.35f * night * (0.2f + 0.8f * fullness);
        sky = lerp(sky, before, saturate(rain * 1.6f));
    }

    // The sun by day: a bright disc with a glow round it, orange when low and warm.
    const float day = (1.0f - night) * (1.0f - rain);
    if (day > 0.0f) {
        const float3 sunColor = lerp(float3(1.0f, 0.97f, 0.88f), float3(1.0f, 0.62f, 0.3f), glow);
        const float disc = smoothstep(0.99955f, 0.99975f, toward);
        sky = lerp(sky, sunColor * 1.3f, disc * day);
        sky += sunColor * (pow(toward, 600.0f) * 0.6f + pow(toward, 60.0f) * 0.15f) * day;
    }

    // Northern lights: curtains of green fading to violet at their tops, waving slowly, behind the clouds.
    if (((DayPacked() & 4u) != 0u) && (night > 0.0f) && (world.y > 0.04f)) {
        const float time = gConstants.view.z;
        float3 aurora = 0.0f;
        [loop]
        for (int i = 0; i < 10; i++) {
            const float h = 1.0f + float(i) * 0.09f;
            const float2 q = world.xz / world.y * h * 0.35f;
            // Bands along a wandering line: the noise's middle values, thin and bright.
            const float n = CloudNoise(float3(q.x * 0.6f + time * 0.015f, q.y * 1.4f + sin(q.x * 0.5f + time * 0.05f), time * 0.03f));
            const float band = pow(saturate(1.0f - abs(n - 0.5f) * 3.5f), 2.0f);
            const float shimmer = 0.7f + 0.3f * CloudNoise(float3(q * 6.0f, time * 0.4f));
            const float up = float(i) / 10.0f;
            aurora += lerp(float3(0.15f, 1.0f, 0.45f), float3(0.55f, 0.25f, 0.9f), up * up) * band * shimmer * (1.0f - up) * 0.4f;
        }
        // Brightest up from the horizon, fading towards the top of the sky; hidden by the rain.
        const float place = smoothstep(0.04f, 0.2f, world.y) * (1.0f - smoothstep(0.5f, 0.9f, world.y));
        sky += aurora * place * night * (1.0f - rain);
    }

    // Clouds in front of all of it.
    // Also forced clouds (the WIP Volumetric Clouds option): their type's darkness stands in for rain, their warmth for glow.
    const uint forcedClouds = (uint(gConstants.fog.z) >> 12 >> 3) & 7u;
    if (((DayPacked() & 2u) != 0u) || (forcedClouds != 0u)) {
        const float3 sunWorld = normalize(float3(dot(gConstants.sun.xyz, gConstants.worldX.xyz), dot(gConstants.sun.xyz, gConstants.worldY.xyz), dot(gConstants.sun.xyz, gConstants.worldZ.xyz)));
        float3 cloudWeather = weather;
        cloudWeather.x = max(cloudWeather.x, VolCloudDarkness(forcedClouds));
        const float4 clouds = DayClouds(world, sunWorld, tint, max(glow, VolCloudWarmth(forcedClouds)), pixel, cloudWeather);
        sky = sky * (1.0f - clouds.a) + clouds.rgb;
    }
    return DayWeatherLight(sky, 0.0f, weather.z, 0.0f);
}

float LoadDepth(int2 pixel) {
    pixel = clamp(pixel, int2(0, 0), int2(gConstants.projection.zw) - 1);
#ifdef MULTISAMPLING
    return gInput.Load(pixel, 0);
#else
    return gInput.Load(int3(pixel, 0));
#endif
}

// The view-space position at a pixel (the camera looks along -z).
float3 ViewPosition(int2 pixel, float depth) {
    const float4 t = gConstants.depthTerms;
    // The game's projections give z / w in [-1, 1] and RT64 keeps it halved and moved into [0, 1] as the depth
    // (flat surfaces stay flat this way). Reading the depth as z / w itself put everything about twice as far.
    const float ndcZ = depth * 2.0f - 1.0f;
    const float z = (t.y - ndcZ * t.w) / (ndcZ * t.z - t.x);
    const float2 ndc = float2((pixel.x + 0.5f) / gConstants.projection.z * 2.0f - 1.0f, 1.0f - (pixel.y + 0.5f) / gConstants.projection.w * 2.0f);
    return float3(ndc.x * -z / gConstants.projection.x, ndc.y * -z / gConstants.projection.y, z);
}

float3 ViewPositionAt(int2 pixel) {
    return ViewPosition(pixel, LoadDepth(pixel));
}

// The surface's view-space normal from the neighbouring depths, facing the camera.
float3 ViewNormal(int2 pixel, float3 center) {
    const float3 left = ViewPositionAt(pixel + int2(-1, 0)), right = ViewPositionAt(pixel + int2(1, 0));
    const float3 up = ViewPositionAt(pixel + int2(0, -1)), down = ViewPositionAt(pixel + int2(0, 1));
    // The smaller step on each axis, so edges don't bend the normal.
    const float3 dx = (abs(right.z - center.z) < abs(center.z - left.z)) ? (right - center) : (center - left);
    const float3 dy = (abs(down.z - center.z) < abs(center.z - up.z)) ? (down - center) : (center - up);
    float3 normal = normalize(cross(dx, dy));
    if (dot(normal, -center) < 0.0f) {
        normal = -normal;
    }
    return normal;
}

// The normal averaged over a few pixels round about (eight taps r pixels out), only where the depth says it is the
// same surface: rounded over a furry or low-poly character, whose own normal turns pixel to pixel.
float3 SmoothedNormal(int2 pixel, float3 center, float3 normal, int r) {
    const int2 offsets[8] = { int2(-r, 0), int2(r, 0), int2(0, -r), int2(0, r), int2(-r, -r), int2(r, r), int2(r, -r), int2(-r, r) };
    const float tolerance = 8.0f - center.z * 0.02f * float(r);
    float3 sum = normal;
    [unroll] for (int k = 0; k < 8; k++) {
        const int2 at = clamp(pixel + offsets[k], int2(1, 1), int2(gConstants.projection.zw) - 2);
        const float3 there = ViewPositionAt(at);
        if (abs(there.z - center.z) < tolerance) {
            sum += ViewNormal(at, there);
        }
    }
    const float3 smoothed = normalize(sum);
    return (dot(smoothed, -center) < 0.0f) ? normal : smoothed;
}

// Ambient occlusion, screen-space global illumination and screen-space reflections share ambientOcclusion.x,
// packed as AO + 128 * SSGI + 16384 * SSR, each in hundredths (0 to 100), + 2097152 * stochastic glossiness (0 to 7).
uint3 IndirectPacked() {
    const uint packed = uint(max(gConstants.ambientOcclusion.x, 0.0f) + 0.5f);
    return uint3(packed & 127u, (packed >> 7) & 127u, (packed >> 14) & 127u);
}

float AoStrength() {
    return float(IndirectPacked().x) / 100.0f;
}

float SsgiStrength() {
    return float(IndirectPacked().y) / 100.0f;
}

float SsrStrength() {
    return float(IndirectPacked().z) / 100.0f;
}

// Stochastic reflections' glossiness (0 off: the mirror ray; 1 to 7 the roughness in tenths).
float SsrRoughness() {
    const uint packed = uint(max(gConstants.ambientOcclusion.x, 0.0f) + 0.5f);
    return float((packed >> 21) & 7u) * 0.1f;
}

// A view-space depth (negative) from a depth buffer value, as ViewPosition works it out.
float ViewZ(float depth) {
    const float4 t = gConstants.depthTerms;
    const float ndcZ = depth * 2.0f - 1.0f;
    return (t.y - ndcZ * t.w) / (ndcZ * t.z - t.x);
}

// Where a view-space position lands on the target, in pixels (a pixel's centre at + 0.5), the inverse of ViewPosition.
float2 ViewToPixel(float3 view) {
    const float2 ndc = float2(view.x * gConstants.projection.x, view.y * gConstants.projection.y) / -view.z;
    return float2((ndc.x + 1.0f) * 0.5f * gConstants.projection.z, (1.0f - ndc.y) * 0.5f * gConstants.projection.w);
}

// While a temporal upscaler (DLSS, FSR, Temporal) jitters the camera: a new turn of the noise each frame (0 to 1, in
// golden-ratio steps, the dust buffer's last float), so the upscaler averages the rays over frames instead of seeing a
// fixed pattern that the picture slides across, which flickers (L, 2026-10-24). 0 with no upscaler.
float NoiseFrameOffset() {
    return asfloat(gDust.Load(12u));
}

// Ray traced denoising: after Point Lights' lamps in the dust buffer, the camera the history was drawn from (its view's rows
// into the world, then its projection) and a word: denoising on (x) and the history to be used (y). See rt64_scene_effects.cpp.
static const uint DustDenoiseOffset = 32u + 32u * 16u;

float4 DenoiseRow(uint row) {
    return asfloat(gDust.Load4(DustDenoiseOffset + row * 16u));
}

bool DenoiseOn() {
    return DenoiseRow(4u).x > 0.5f;
}

// Interleaved gradient noise (Jimenez 2014): 0 to 1, different from each pixel to the next.
float InterleavedNoise(int2 pixel) {
    return frac(52.9829189f * frac(0.06711056f * float(pixel.x) + 0.00583715f * float(pixel.y)) + NoiseFrameOffset());
}

// A 4x4 ordered pattern (0 to 15): neighbouring pixels of the indirect pass get directions far apart, so each 4x4
// block holds all of them and the scene pass's blur (IndirectAt) brings them back together.
uint IndirectCell(int2 pixel) {
    const uint x = uint(pixel.x) & 3u, y = uint(pixel.y) & 3u;
    const uint row = (y == 0u) ? 0xA280u : (y == 1u) ? 0x6E4Cu : (y == 2u) ? 0x91B3u : 0x5D7Fu;
    // Denoising: the whole pattern turns a step each frame, so the frames a pixel blends traced different directions.
    const uint turn = DenoiseOn() ? uint(NoiseFrameOffset() * 16.0f) : 0u;
    return ((row >> (x * 4u)) + turn) & 15u;
}

static const float IndirectPi = 3.14159265f;
static const float IndirectHalfPi = 1.57079633f;

// Ground Truth Ambient Occlusion (Jimenez, Wu, Pesce and Jarabo, "Practical Real-Time Strategies for Accurate
// Indirect Occlusion", 2016), the method of MaxwellGengYF/Unity-Ground-Truth-Ambient-Occlusion, written here from
// the paper. For one slice through the pixel (a direction on the screen and the view direction) it finds the
// highest point the depth rises to on each side within the radius (the horizons), and integrates the
// cosine-weighted sky left between them over the surface's normal as projected into the slice. The indirect pass
// takes one slice a pixel, 16 directions over each 4x4 block, and the scene pass's blur averages them.
// Returns the visible share of the sky: 1 open, 0 shut in.
float GroundTruthOcclusion(int2 pixel, float3 center, float3 normal, uint slice, float jitter) {
    const float radius = gConstants.ambientOcclusion.y;
    const float distance = max(-center.z, 1.0f);
    // Up to a tenth of the picture's height: the pass runs at half size, so it can afford wider reads than the old one.
    const float radiusPixels = clamp(radius * gConstants.projection.y * gConstants.projection.w * 0.5f / distance, 3.0f, gConstants.projection.w * 0.1f);

    const float angle = (float(slice) + 0.5f) * (IndirectPi / 16.0f);
    const float2 direction = float2(cos(angle), sin(angle));
    // The same direction in view space (y up, where the screen's y goes down).
    const float3 viewDirection = normalize(-center);
    const float3 sliceDirection = float3(direction.x, -direction.y, 0.0f);
    const float3 orthoDirection = normalize(sliceDirection - dot(sliceDirection, viewDirection) * viewDirection);
    const float3 axis = cross(orthoDirection, viewDirection);
    const float3 projected = normal - axis * dot(normal, axis);
    const float projectedLength = length(projected);
    if (projectedLength < 1e-4f) {
        return 1.0f;
    }
    // The normal's angle from the view direction within the slice, towards orthoDirection.
    const float cosN = saturate(dot(projected, viewDirection) / projectedLength);
    const float n = ((dot(projected, orthoDirection) < 0.0f) ? -1.0f : 1.0f) * acos(cosN);

    // The lowest each horizon can be (the surface's own tangent): the cosines from the view direction on the
    // direction's side [0] and the other side [1].
    const float lowCos0 = cos(n + IndirectHalfPi);
    const float lowCos1 = cos(n - IndirectHalfPi);
    float horizonCos0 = lowCos0;
    float horizonCos1 = lowCos1;
    // Points further than this fade back to the low horizon by the radius, so far walls don't occlude.
    const float falloffFrom = radius * 0.6f;
    const int steps = 8;
    [loop] for (int i = 0; i < steps; i++) {
        // Closer together near the pixel, where the small creases are; at least a pixel apart.
        const float t = (float(i) + jitter) / float(steps);
        const float reach = max(t * t * radiusPixels, float(i) + 1.0f);
        const int2 offset = int2(round(direction * reach));
        [unroll] for (int side = 0; side < 2; side++) {
            const int2 at = pixel + ((side == 0) ? offset : -offset);
            const float sampleDepth = LoadDepth(at);
            if (sampleDepth >= 0.99999f) {
                continue;
            }
            const float3 delta = ViewPosition(at, sampleDepth) - center;
            const float len = length(delta);
            const float sampleCos = dot(delta, viewDirection) / max(len, 1e-3f);
            const float falloff = saturate((radius - len) / (radius - falloffFrom));
            if (side == 0) {
                horizonCos0 = max(horizonCos0, lerp(lowCos0, sampleCos, falloff));
            }
            else {
                horizonCos1 = max(horizonCos1, lerp(lowCos1, sampleCos, falloff));
            }
        }
    }

    // The horizon angles, kept within a half turn of the normal, then the paper's integral of the visible arc.
    const float h0 = n + max(-acos(horizonCos1) - n, -IndirectHalfPi);
    const float h1 = n + min(acos(horizonCos0) - n, IndirectHalfPi);
    const float sinN = sin(n);
    const float arc0 = -cos(2.0f * h0 - n) + cosN + 2.0f * h0 * sinN;
    const float arc1 = -cos(2.0f * h1 - n) + cosN + 2.0f * h1 * sinN;
    return saturate(projectedLength * 0.25f * (arc0 + arc1));
}

// GTAO's multi-bounce fit (the same paper): light bounced between the occluding surfaces gives some of the
// occlusion back, more on bright surfaces than on dark ones.
float MultiBounce(float visibility, float albedo) {
    const float a = 2.0404f * albedo - 0.3324f;
    const float b = -4.7951f * albedo + 0.6417f;
    const float c = 2.7552f * albedo + 0.6903f;
    return max(visibility, ((visibility * a + b) * visibility + c) * visibility);
}

// The ray march shared by SSGI and SSR, ported from 0beqz/realism-effects (src/ssgi/shader/ssgi.frag, RayMarch and
// BinarySearch), under its MIT licence:
//
//   MIT License
//
//   Copyright (c) 2023 0beqz
//
//   Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
//   documentation files (the "Software"), to deal in the Software without restriction, including without limitation
//   the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and
//   to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
//   The above copyright notice and this permission notice shall be included in all copies or substantial portions
//   of the Software.
//
//   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//   THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
//   CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//   IN THE SOFTWARE.
//
// The ray steps through view space from origin, small steps first (sharper contact) growing to full ones, until it
// passes just behind the depth (by less than the thickness); a binary search between the last two steps then finds
// the hit. Here it reads the game's depth directly instead of a G-buffer, gives up behind the camera and off the
// screen, and its thickness grows with the step, since the game's units are much larger than three.js scenes'.
bool MarchRay(float3 origin, float3 direction, float rayDistance, int steps, int refineSteps, float jitter, out float2 hitPixel) {
    hitPixel = 0.0f;
    const float2 size = gConstants.projection.zw;
    const float3 stepVector = direction * (rayDistance / float(steps));
    float3 hit = origin;
    [loop] for (int i = 1; i < steps; i++) {
        // realism-effects: "use slower increments for the first few steps to sharpen contact shadows".
        const float grow = 1.0f - exp(-0.25f * pow(float(i) + jitter - 0.5f, 2.0f));
        float3 increment = stepVector * grow;
        hit += increment;
        if (hit.z > -1.0f) {
            return false;
        }
        const float2 at = ViewToPixel(hit);
        if ((at.x < 0.0f) || (at.y < 0.0f) || (at.x >= size.x) || (at.y >= size.y)) {
            return false;
        }
        const float sampleDepth = LoadDepth(int2(at));
        if (sampleDepth >= 0.99999f) {
            continue;
        }
        const float difference = ViewZ(sampleDepth) - hit.z;
        const float thickness = max(length(increment) * 2.0f, 20.0f);
        if ((difference >= 0.0f) && (difference < thickness)) {
            increment *= 0.5f;
            hit -= increment;
            [loop] for (int j = 0; j < refineSteps; j++) {
                const float refineDifference = ViewZ(LoadDepth(int2(ViewToPixel(hit)))) - hit.z;
                increment *= 0.5f;
                hit += (refineDifference >= 0.0f) ? -increment : increment;
            }
            hitPixel = ViewToPixel(hit);
            return true;
        }
    }
    return false;
}

// realism-effects' fade near the picture's edges (border 0.15), where a ray's hit is less trustworthy.
float RayEdgeFade(float2 hitPixel) {
    const float2 uv = hitPixel / gConstants.projection.zw;
    const float2 fade = smoothstep(0.0f, 0.15f, uv) * smoothstep(1.0f, 0.85f, uv);
    return sqrt(fade.x * fade.y);
}

// Screen-space global illumination (after realism-effects' SSGI, diffuse rays): two cosine-weighted rays about the
// normal, the 16 pixels of each 4x4 block spreading their 32 over the hemisphere (a Vogel spiral, which is
// cosine-weighted), each taking the colour of the scene where it lands. The average light arriving at the surface;
// the scene pass multiplies it by the surface's own colour. Rays that leave the screen bring nothing (as
// realism-effects without an environment map). The spiral and the rays' first steps are the same in every block, so
// any 4x4 window of the half-size pass holds all 32 rays and IndirectAt's gather comes out smooth: per-pixel noise
// here (interleaved gradient noise) left diagonal lines the gather couldn't average away.
float3 ScreenSpaceGI(float3 center, float3 normal, uint cell) {
    const float3 side = normalize(cross(normal, (abs(normal.y) < 0.99f) ? float3(0.0f, 1.0f, 0.0f) : float3(1.0f, 0.0f, 0.0f)));
    const float3 across = cross(side, normal);
    // Off the surface a little, so the ray doesn't find the surface it starts from.
    const float3 origin = center + normal * max(-center.z * 0.002f, 1.0f);
    const float rayDistance = gConstants.ambientOcclusion.y * 3.0f;
    float3 light = 0.0f;
    [unroll] for (int r = 0; r < 2; r++) {
        const uint index = cell * 2u + uint(r);
        const float diskRadius = sqrt((float(index) + 0.5f) / 32.0f);
        const float theta = float(index) * 2.39996323f;
        // Each ray's first step, spread evenly over the block's 32 rays (the golden ratio's fractions).
        const float stepOffset = frac(float(index) * 0.61803399f + 0.5f);
        const float3 direction = normalize(side * (diskRadius * cos(theta)) + across * (diskRadius * sin(theta)) + normal * sqrt(max(1.0f - diskRadius * diskRadius, 0.0f)));
        float2 hitPixel;
        if (MarchRay(origin, direction, rayDistance, 12, 4, stepOffset, hitPixel)) {
            light += gColorHalf.SampleLevel(LinearSampler, hitPixel / gConstants.projection.zw, 0).rgb * RayEdgeFade(hitPixel);
        }
    }
    return light * 0.5f;
}

// Screen-space reflections (after realism-effects' SSR, a mirror ray: the game has no roughness to blur it by): the
// scene's colour where the reflected ray lands, and how much to trust it (a).
float4 ScreenSpaceReflection(int2 pixel, float3 center, float3 normal) {
    const float3 direction = reflect(normalize(center), normal);
    const float3 origin = center + normal * max(-center.z * 0.002f, 1.0f);
    float2 hitPixel;
    if (!MarchRay(origin, direction, 3000.0f, 24, 5, InterleavedNoise(pixel), hitPixel)) {
        return 0.0f;
    }
    return float4(gColor.SampleLevel(LinearSampler, hitPixel / gConstants.projection.zw, 0).rgb, RayEdgeFade(hitPixel));
}

// Stochastic reflections, after simeonradivoev/ComputeStochasticReflections (itself after Stachowiak and Uludag,
// "Stochastic Screen-Space Reflections", SIGGRAPH 2015), under its MIT licence:
//
//   MIT License
//
//   Copyright (c) 2018 Simeon Radivoev
//
//   Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
//   documentation files (the "Software"), to deal in the Software without restriction, including without limitation
//   the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and
//   to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
//   The above copyright notice and this permission notice shall be included in all copies or substantial portions
//   of the Software.
//
//   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//   THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
//   CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//   IN THE SOFTWARE.
//
// Ported from BRDFComputeLib.cginc (ImportanceSampleGGX after Karis, BRDF_Unity_Weight) and the resolve in
// RayTraceCompute.compute: each ray takes a GGX-distributed half vector about the normal, and what the rays find is
// averaged weighted by the BRDF over the ray's probability density. Left out: the hierarchical depth march (the
// existing MarchRay stands in), the colour mip pyramid (the half-size scene stands in for a rough hit's blur), the
// temporal pass and the median/bilateral blurs (the game has no history buffer here); more rays per pixel make up
// for them, and the 4x4 block pattern spreads the samples so the noise is fine grained.
float StochasticWeight(float3 V, float3 L, float3 N, float roughness) {
    const float3 H = normalize(L + V);
    const float NdotH = saturate(dot(N, H));
    const float NdotL = saturate(dot(N, L));
    const float NdotV = saturate(dot(N, V));
    const float lambdaV = NdotL * (NdotV * (1.0f - roughness) + roughness);
    const float lambdaL = NdotV * (NdotL * (1.0f - roughness) + roughness);
    const float visibility = 0.5f / (lambdaV + lambdaL + 1e-5f);
    const float a2 = roughness * roughness;
    const float d = (NdotH * a2 - NdotH) * NdotH + 1.0f;
    const float distribution = 0.31830988618f * a2 / (d * d + 1e-7f);
    return distribution * visibility * 0.78539816f;
}

float4 StochasticReflection(int2 pixel, float3 center, float3 normal, float roughness) {
    const float3 incoming = normalize(center);
    const float3 V = -incoming;
    const float3 up = (abs(normal.z) < 0.999f) ? float3(0.0f, 0.0f, 1.0f) : float3(1.0f, 0.0f, 0.0f);
    const float3 tangent = normalize(cross(up, normal));
    const float3 bitangent = cross(normal, tangent);
    const float3 origin = center + normal * max(-center.z * 0.002f, 1.0f);
    const uint cell = uint(pixel.x & 3) + 4u * uint(pixel.y & 3);
    const float m = roughness * roughness;
    const float m2 = m * m;
    float3 colourSum = 0.0f;
    float hitSum = 0.0f;
    float totalSum = 0.0f;
    [unroll] for (int r = 0; r < 3; r++) {
        // The 48 samples of a 4x4 block spread over the lobe (the R2 sequence), the cells scrambled so neighbours differ.
        const float n = float((cell * 7u) % 16u) * 3.0f + float(r);
        const float2 xi = frac(0.5f + n * float2(0.7548776662f, 0.5698402910f));
        const float phi = 6.28318531f * xi.x;
        const float cosTheta = sqrt((1.0f - xi.y) / (1.0f + (m2 - 1.0f) * xi.y));
        const float sinTheta = sqrt(max(1e-5f, 1.0f - cosTheta * cosTheta));
        const float3 H = normalize(tangent * (sinTheta * cos(phi)) + bitangent * (sinTheta * sin(phi)) + normal * cosTheta);
        const float d = (cosTheta * m2 - cosTheta) * cosTheta + 1.0f;
        const float pdf = max(m2 / (3.14159265f * d * d) * cosTheta, 1e-4f);
        const float3 direction = reflect(incoming, H);
        if (dot(direction, normal) <= 0.0f) {
            continue;
        }
        const float weight = StochasticWeight(V, direction, normal, roughness) / pdf;
        totalSum += weight;
        float2 hitPixel;
        if (MarchRay(origin, direction, 3000.0f, 24, 5, frac(xi.x * 7.0f + InterleavedNoise(pixel)), hitPixel)) {
            const float2 uv = hitPixel / gConstants.projection.zw;
            // A rough reflection is blurry: more of the half-size scene the rougher it is.
            const float3 colour = lerp(gColor.SampleLevel(LinearSampler, uv, 0).rgb, gColorHalf.SampleLevel(LinearSampler, uv, 0).rgb, saturate(roughness * 2.0f));
            const float fade = RayEdgeFade(hitPixel);
            colourSum += colour * (weight * fade);
            hitSum += weight * fade;
        }
    }
    if (hitSum <= 0.0f) {
        return 0.0f;
    }
    return float4(colourSum / hitSum, saturate(hitSum / max(totalSum, 1e-5f)));
}

// View space to world space and back, through the world x, y and z terms (the view matrix's inverse: world = dot(view,
// X) + X.w and so on, and, the view being a scaled rotation, view = X * (world.x - X.w) + Y * (world.y - Y.w) + Z * ...).
float3 ViewToWorldPoint(float3 view) {
    return float3(dot(view, gConstants.worldX.xyz) + gConstants.worldX.w, dot(view, gConstants.worldY.xyz) + gConstants.worldY.w,
        dot(view, gConstants.worldZ.xyz) + gConstants.worldZ.w);
}

float3 ViewToWorldDirection(float3 view) {
    return float3(dot(view, gConstants.worldX.xyz), dot(view, gConstants.worldY.xyz), dot(view, gConstants.worldZ.xyz));
}

// Banjo-Tooie: Point Lights (Graphics > WIP, rt64_scene_lights.h): the lamps nearest the camera (up to 16), in the dust buffer after
// its first 16 bytes: the count, then each lamp's world x, y, z and radius, and its colour (times the strength).
uint PointLampCount() {
    return uint(asfloat(gDust.Load(16u)) + 0.5f);
}

// The lamps' light on a surface (view-space position and normal), on top of the light the game gave it: full at a lamp,
// smoothly down to nothing at its radius, most on the side that faces it. The normals from the depth are rough, so
// the side turned away keeps some of it (the game's own vertex light reads that way too).
float3 PointLampsAt(float3 center, float3 normal) {
    const float3 world = ViewToWorldPoint(center);
    const float3 worldNormal = ViewToWorldDirection(normal);
    float3 light = 0.0f;
    const uint count = min(PointLampCount(), 16u);
    for (uint i = 0u; i < count; i++) {
        const float4 lamp = asfloat(gDust.Load4(32u + i * 32u));
        const float3 colour = asfloat(gDust.Load3(48u + i * 32u));
        const float3 toLamp = lamp.xyz - world;
        const float distance2 = dot(toLamp, toLamp);
        const float reach = saturate(1.0f - distance2 / max(lamp.w * lamp.w, 1.0f));
        if (reach > 0.0f) {
            const float facing = dot(worldNormal, toLamp * rsqrt(max(distance2, 1.0f)));
            light += colour * (reach * reach * (0.4f + 0.6f * saturate(facing)));
        }
    }
    return light;
}

// Inside a capsule round Banjo (world space): what the sun shadows leave out when they leave him out, and all
// his contact shadow counts.
bool InsideBanjo(float3 world) {
    const float3 banjo = float3(gConstants.rippleX.w, gConstants.rippleAge.w, gConstants.rippleZ.w);
    const float2 across = world.xz - banjo.xz;
    return (gConstants.rippleAge.w > -1e8f) && (dot(across, across) < 80.0f * 80.0f) && (world.y > banjo.y - 5.0f) && (world.y < banjo.y + 180.0f);
}

#ifdef RAY_TRACED
// The radiance cache (see gRadianceCache): on when lights word 1 says so (Graphics > Ray tracing hit colours).
bool HitColoursOn() {
    return asfloat(gLights.Load(4)) > 0.5f;
}

// Traced shadows of the player off: Banjo casts no traced shadows (lights word 9).
bool PlayerShadowsOff() {
    return (uint(asfloat(gLights.Load(36)) + 0.5f) & 1u) != 0u;
}

// Ray tracing resolution High (lights word 15): every pixel traces all its rays, at any distance.
bool RayResolutionHigh() {
    return asfloat(gLights.Load(60)) > 1.5f;
}

// Ray detail by distance (Graphics > Ray detail distances, the lights buffer's header): 0 all the rays, 1 half (past the
// first distance), 2 a quarter (past the second); a distance of 0 never.
uint RayDetail(float distance) {
    if (RayResolutionHigh()) {
        return 0u;
    }
    const float half = asfloat(gLights.Load(48));
    const float quarter = asfloat(gLights.Load(52));
    if ((quarter > 0.0f) && (distance > quarter)) {
        return 2u;
    }
    return ((half > 0.0f) && (distance > half)) ? 1u : 0u;
}

// Half-resolution ray tracing: the sun's traced shadows and the traced light beams come from the indirect pass's lower
// half (one ray set for each 2x2 pixels), see TracedHalfAt.
bool HalfTraced() {
    return (uint(asfloat(gLights.Load(36)) + 0.5f) & 2u) != 0u;
}

// The traced light beams from the indirect pass's second band (half size, TracedHalfBeams): below Ray tracing resolution
// High; it draws the band whenever the beams are on (rt64_scene_effects.cpp tracedBeamsHalf).
bool BeamsHalf() {
    return HalfTraced() || !RayResolutionHigh();
}

// Ray tracing noise smoothing, 0 (the raw rays) to 1.
float RtSmoothing() {
    return saturate(asfloat(gLights.Load(8)));
}

// How far round about Banjo's normal is averaged (pixels; 0 not at all).
int BanjoSmoothRadius() {
    return int(RtSmoothing() * 7.0f + 0.5f);
}

uint RadianceCell(float3 world, out uint check) {
    const int3 cell = int3(floor(world * (1.0f / 16.0f)));
    const uint h = uint(cell.x) * 73856093u ^ uint(cell.y) * 19349663u ^ uint(cell.z) * 83492791u;
    check = h | 1u;
    return ((h * 2654435761u) >> 12) * 8u;
}

void RadianceStore(float3 world, float3 colour) {
    uint check;
    const uint at = RadianceCell(world, check);
    const uint3 c = uint3(saturate(colour) * 255.0f + 0.5f);
    gRadianceCache.Store2(at, uint2(check, c.r | (c.g << 8) | (c.b << 16)));
}

// Whether the rays can read the textures of what they meet this pass (the lights buffer's header, BuildSceneBVH).
bool RayTexturesOn() {
    return asfloat(gLights.Load(32)) > 0.5f;
}

// The traced structure's instances (BuildSceneBVH): the level's own draws (mask 1, custom index 0) and the models
// (characters, enemies, objects: mask 4, custom index the first of their geometry table entries).
static const uint RayLevelMask = 0x01u;
static const uint RayModelMask = 0x04u;
static const uint RayWorldMask = RayLevelMask | RayModelMask;

uint RayGeometryOf(uint instance, uint geometry) {
    return instance + geometry;
}

// A traced geometry's flags: 1 a cut-out or see-through draw, 2 it has a texture, 4 a model.
uint RayGeometryFlags(uint geometry) {
    return gRayGeometries.Load(geometry * 16u + 8u);
}

// A geometry's material (SceneMaterialTexture: Parallax's shape + 1; 0 for none).
// The Parallax shape a geometry carries (0 none), unless Ray tracing uses Parallax materials is off (gLights 14).
uint RayGeometryMaterial(uint geometry) {
    if (asfloat(gLights.Load(56)) < 0.5f) {
        return 0u;
    }
    return gRayGeometries.Load(geometry * 16u + 12u) & 0xFFu;
}

RayPbr RayGeometryPbr(uint geometry) {
    RayPbr material = RayPbrNone();
    if (!RayPbrOn()) {
        return material;
    }
    const uint index = gRayGeometries.Load(geometry * 16u + 12u) >> 8u;
    if (index == 0u) {
        return material;
    }
    const uint2 words = gRayGeometries.Load2((SCENE_RAY_MATERIAL_BASE + index) * 16u);
    material.present = true;
    material.albedo = float3(float(words.x & 255u), float((words.x >> 8u) & 255u), float((words.x >> 16u) & 255u)) / 255.0f;
    material.roughness = float(words.x >> 24u) / 100.0f;
    material.metalness = float(words.y & 255u) / 100.0f;
    material.emissive = float((words.y >> 8u) & 0xFFFFu) / 100.0f;
    material.subsurface = float(words.y >> 24u) / 100.0f;
    return material;
}

int RayWrap(int texel, int mask, bool mirror) {
    if (mask <= 0) {
        return texel;
    }
    const int wrapped = texel - mask * int(floor(float(texel) / float(mask)));
    if (mirror) {
        const int twice = texel - 2 * mask * int(floor(float(texel) / float(2 * mask)));
        return (twice >= mask) ? (mask - 1 - wrapped) : wrapped;
    }
    return wrapped;
}

// The texel of a traced draw where a ray met it (geometry, triangle, barycentrics), as the draw samples its first tile
// (TextureSampler.hlsli's sampleTexture, one texel, no filtering); white where it can't be read (a texture decoded from
// TMEM as it is drawn).
float2 RayTileCoord(RDPTile tile, GPUTile gpuTile, float2 uv);
float4 RayTileTexel(RDPTile tile, GPUTile gpuTile, int2 texel);
bool RayCutoutSolid(uint geometry, uint primitive, float2 barycentrics);

float4 RayTexel(uint geometry, uint primitive, float2 barycentrics) {
    const uint4 entry = gRayGeometries.Load4(geometry * 16u);
    const uint base = (entry.x + primitive * 3u) * 4u;
    const uint3 v = uint3(gRayIndices.Load(base), gRayIndices.Load(base + 4u), gRayIndices.Load(base + 8u));
    const float2 uv = asfloat(gRayTexcoords.Load2(v.x * 8u)) * (1.0f - barycentrics.x - barycentrics.y) +
        asfloat(gRayTexcoords.Load2(v.y * 8u)) * barycentrics.x + asfloat(gRayTexcoords.Load2(v.z * 8u)) * barycentrics.y;
    const RDPTile tile = gRayRDPTiles[entry.y];
    const GPUTile gpuTile = gRayGPUTiles[entry.y];
    if (gpuTileFlagRawTMEM(gpuTile.flags)) {
        return 1.0f;
    }
    return RayTileTexel(tile, gpuTile, int2(floor(RayTileCoord(tile, gpuTile, uv))));
}

// Traced relighting: the texture's colour where the camera's ray meets the surface (view space), blended between its
// four nearest texels as the game's own filtering blends them, so the colour divided out of the picture (Relit) doesn't
// show the texel grid. White on an untextured draw, where the drawn colour is all shading. False where there is no
// surface to read or its texture can't be read (one decoded from TMEM as it is drawn).
bool SurfaceAlbedo(float3 center, out float3 albedo) {
    albedo = 1.0f;
    const float distance = length(center);
    if ((distance < 10.0f) || !RayTexturesOn()) {
        return false;
    }
    RayDesc ray;
    ray.Origin = ViewToWorldPoint(center * (1.0f - 6.0f / distance));
    ray.Direction = ViewToWorldDirection(center / distance);
    ray.TMin = 0.0f;
    ray.TMax = 12.0f + distance * 0.004f;
    // Through a cut-out's or see-through draw's clear texels to what is drawn behind them, as the picture shows it.
    RayQuery<RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES> query;
    query.TraceRayInline(gSceneBVH, 0, 0xFFu, ray);
    while (query.Proceed()) {
        if (query.CandidateType() != CANDIDATE_NON_OPAQUE_TRIANGLE) {
            continue;
        }
        const uint candidate = RayGeometryOf(query.CandidateInstanceID(), query.CandidateGeometryIndex());
        if (RayCutoutSolid(candidate, query.CandidatePrimitiveIndex(), query.CandidateTriangleBarycentrics())) {
            query.CommitNonOpaqueTriangleHit();
        }
    }
    if (query.CommittedStatus() != COMMITTED_TRIANGLE_HIT) {
        return false;
    }
    const uint geometry = RayGeometryOf(query.CommittedInstanceID(), query.CommittedGeometryIndex());
    if ((RayGeometryFlags(geometry) & 2u) == 0u) {
        return true;
    }
    const uint4 entry = gRayGeometries.Load4(geometry * 16u);
    const uint base = (entry.x + query.CommittedPrimitiveIndex() * 3u) * 4u;
    const uint3 v = uint3(gRayIndices.Load(base), gRayIndices.Load(base + 4u), gRayIndices.Load(base + 8u));
    const float2 barycentrics = query.CommittedTriangleBarycentrics();
    const float2 uv = asfloat(gRayTexcoords.Load2(v.x * 8u)) * (1.0f - barycentrics.x - barycentrics.y) +
        asfloat(gRayTexcoords.Load2(v.y * 8u)) * barycentrics.x + asfloat(gRayTexcoords.Load2(v.z * 8u)) * barycentrics.y;
    const RDPTile tile = gRayRDPTiles[entry.y];
    const GPUTile gpuTile = gRayGPUTiles[entry.y];
    if (gpuTileFlagRawTMEM(gpuTile.flags)) {
        return false;
    }
    const float2 coord = RayTileCoord(tile, gpuTile, uv) - 0.5f;
    const int2 corner = int2(floor(coord));
    const float2 f = coord - floor(coord);
    const float4 top = lerp(RayTileTexel(tile, gpuTile, corner), RayTileTexel(tile, gpuTile, corner + int2(1, 0)), f.x);
    const float4 bottom = lerp(RayTileTexel(tile, gpuTile, corner + int2(0, 1)), RayTileTexel(tile, gpuTile, corner + int2(1, 1)), f.x);
    albedo = lerp(top, bottom, f.y).rgb;
    return true;
}

// Where in a tile's texels a texture coordinate falls, as TextureSampler.hlsli's sampleTexture works it out.
float2 RayTileCoord(RDPTile tile, GPUTile gpuTile, float2 uv) {
    float2 coord = uv * float2(tile.shifts, tile.shiftt);
    if (gpuTileFlagShiftedByHalf(gpuTile.flags)) {
        coord += 0.5f;
    }
    coord *= gpuTile.tcScale;
    coord -= (float2(tile.uls, tile.ult) * gpuTile.ulScale) / 4.0f;
    return coord;
}

// One texel of a tile, clamped, mirrored and wrapped by the tile's masks as clampWrapMirrorSample does.
float4 RayTileTexel(RDPTile tile, GPUTile gpuTile, int2 texel) {
    const float2 tcScale = gpuTile.tcScale;
    // Clamp (2), mirror (1) and wrap by the tile's masks, as clampWrapMirrorSample does.
    if ((tile.cms & 2) != 0) {
        texel.x = clamp(texel.x, 0, int((round(tcScale.x * tile.lrs) / 4) - (round(tcScale.x * tile.uls) / 4) + round(tcScale.x - 1.0f)));
    }
    if ((tile.cmt & 2) != 0) {
        texel.y = clamp(texel.y, 0, int((round(tcScale.y * tile.lrt) / 4) - (round(tcScale.y * tile.ult) / 4) + round(tcScale.y - 1.0f)));
    }
    texel.x = RayWrap(texel.x, int(round(tile.masks * tcScale.x)), (tile.cms & 1) != 0);
    texel.y = RayWrap(texel.y, int(round(tile.maskt * tcScale.y)), (tile.cmt & 1) != 0);
    texel = int2((uint2(texel) & gpuTile.texelMask) + gpuTile.texelShift);
    return gRayTextures[NonUniformResourceIndex(gpuTile.textureIndex)].Load(int3(texel, 0));
}

// Traced relighting: the surface lit again by the traced light instead of the game's. The game's shading here is how
// much brighter or darker the picture is than the surface's own texture; divided out, what is left is the surface's own
// colour (keeping the tints the game painted on it), which the sun lights where its rays get through (sunBlocked, from
// SunShadow), by how squarely the surface faces it, and the sky lights from above (the ground's bounce from below).
float3 Relit(int2 pixel, float3 center, float3 normal, float3 scene, float sunBlocked) {
    float3 albedo;
    if (!SurfaceAlbedo(center, albedo)) {
        return scene;
    }
    const float3 luma = float3(0.299f, 0.587f, 0.114f);
    // The game's shading is only the brightness between the texture and the picture when both have the same colour.
    // Where they don't (a grey texture the draw tints, like the flight pad's blue and red), the colour comes from the
    // draw and not from the texture, so the ratio says nothing about the shading: there the shading is taken as the
    // game's usual (0.85) instead. Either way it is kept within what the game paints (dividing by a small one turned
    // the flight pad cyan and yellow).
    const float sceneLuma = max(dot(scene, luma), 1e-3f);
    const float albedoLuma = max(dot(albedo, luma), 0.03f);
    const float hueGap = length(scene / sceneLuma - albedo / albedoLuma);
    const float trust = saturate(1.0f - (hueGap - 0.15f) * 2.5f);
    const float shade = lerp(0.85f, clamp(sceneLuma / albedoLuma, 0.45f, 1.5f), trust);
    const float3 own = scene / shade;
    // Smoothed over a few pixels of the same surface (more at higher resolutions), so the low-poly level's faces don't
    // show in the sun's shading, and wrapped a little round the side turned away, so a ridge between two faces turns
    // from lit to shaded softly instead of along a line.
    const float3 smooth = SmoothedNormal(pixel, center, normal, max(3, int(gConstants.projection.w / 270.0f)));
    const float facing = saturate((dot(smooth, normalize(gConstants.sun.xyz)) + 0.25f) / 1.25f);
    const float skyward = dot(smooth, normalize(gConstants.worldY.xyz)) * 0.5f + 0.5f;
    const float3 sky = lerp(float3(0.30f, 0.27f, 0.24f), float3(0.42f, 0.47f, 0.56f), skyward);
    const float3 sun = float3(1.0f, 0.95f, 0.86f) * 0.9f;
    // The day and night cycle's light: its brightest channel dims the sun and the sky (its colour is already in the picture).
    float3 tint;
    const float daylight = DayTint(tint) ? max(tint.r, max(tint.g, tint.b)) : 1.0f;
    const float3 lit = own * (sky + sun * (facing * (1.0f - sunBlocked))) * daylight;
    // A soft shoulder on the brightness above three quarters, so sunlit snow and sand roll off towards white instead of
    // clipping flat. On the brightness and not each channel, so a bright colour keeps its hue (per channel, sunlit grass
    // went neon).
    const float brightness = dot(lit, luma);
    const float over = max(brightness - 0.75f, 0.0f);
    const float rolled = min(brightness, 0.75f) + over / (1.0f + over * 4.0f);
    return min(lit * (rolled / max(brightness, 1e-4f)), 1.0f);
}

// Whether a traced hit is Banjo (whoever is played): a model's triangle (SceneRayDrawModel) in a wide capsule round him.
// The plain capsule (InsideBanjo) missed his backpack and nose, and counted the level's own triangles near him, so leaving
// him out of the shadows left those two as his shadow, and a lit hole in shadows he stood in (L, 2026-10-21).
bool BanjoHit(uint geometry, float3 world) {
    const float3 banjo = float3(gConstants.rippleX.w, gConstants.rippleAge.w, gConstants.rippleZ.w);
    const float2 across = world.xz - banjo.xz;
    return (gConstants.rippleAge.w > -1e8f) && ((RayGeometryFlags(geometry) & 4u) != 0u) && (dot(across, across) < 140.0f * 140.0f) &&
        (world.y > banjo.y - 20.0f) && (world.y < banjo.y + 240.0f);
}

// Whether a cut-out's triangle a ray met is solid there (its texture's alpha); see-through where it can't be read.
bool RayCutoutSolid(uint geometry, uint primitive, float2 barycentrics) {
    return RayTexturesOn() && (RayTexel(geometry, primitive, barycentrics).a >= 0.5f);
}

// Whether a ray (world space) meets anything: mode 0 anything, 1 anything but Banjo (the ray goes on past him to what
// is behind, so his outline leaves no lit hole in a shadow he stands in), 2 only Banjo. A cut-out (a grate, a fence,
// leaves) counts only where its texture is solid, so light goes through its holes (L, 2026-10-21).
// Anything solid among the instances in mask: solid triangles end the search at once (the hardware's fast path); only
// cut-outs are looked at one by one.
// Set when a ray TraceAny traced met a level cut-out (instance 0), solid there or not: the sun's shadow rays that all got
// through and met none leave SunThroughCutout nothing to find.
static bool gSawLevelCutout = false;

bool TraceAny(RayDesc ray, uint mask) {
    RayQuery<RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES | RAY_FLAG_ACCEPT_FIRST_HIT_AND_END_SEARCH> query;
    query.TraceRayInline(gSceneBVH, RAY_FLAG_NONE, mask, ray);
    while (query.Proceed()) {
        if (query.CandidateType() != CANDIDATE_NON_OPAQUE_TRIANGLE) {
            continue;
        }
        const uint geometry = RayGeometryOf(query.CandidateInstanceID(), query.CandidateGeometryIndex());
        if ((query.CandidateInstanceID() == 0u) && ((RayGeometryFlags(geometry) & 5u) == 1u)) {
            gSawLevelCutout = true;
        }
        if (RayCutoutSolid(geometry, query.CandidatePrimitiveIndex(), query.CandidateTriangleBarycentrics())) {
            query.CommitNonOpaqueTriangleHit();
        }
    }
    return query.CommittedStatus() == COMMITTED_TRIANGLE_HIT;
}

// Whether a ray meets a model that is (banjo) or isn't Banjo. Only the models' instance, where each triangle is looked at.
bool TraceModels(RayDesc ray, bool banjo) {
    RayQuery<RAY_FLAG_FORCE_NON_OPAQUE | RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES> query;
    query.TraceRayInline(gSceneBVH, 0, RayModelMask, ray);
    while (query.Proceed()) {
        if (query.CandidateType() != CANDIDATE_NON_OPAQUE_TRIANGLE) {
            continue;
        }
        const uint geometry = RayGeometryOf(query.CandidateInstanceID(), query.CandidateGeometryIndex());
        if (((RayGeometryFlags(geometry) & 1u) != 0u) && !RayCutoutSolid(geometry, query.CandidatePrimitiveIndex(), query.CandidateTriangleBarycentrics())) {
            continue;
        }
        if (BanjoHit(geometry, ray.Origin + ray.Direction * query.CandidateTriangleRayT()) == banjo) {
            query.CommitNonOpaqueTriangleHit();
            query.Abort();
        }
    }
    return query.CommittedStatus() == COMMITTED_TRIANGLE_HIT;
}

// Mode 3: the level only (models, Banjo among them, let the ray by). The level and the models are separate instances, so
// only the models' triangles are looked at one by one, and only when Banjo has to be told apart.
bool TraceOccluded(RayDesc ray, uint mode) {
    if (mode == 0u) {
        return TraceAny(ray, 0xFFu);
    }
    if (mode == 2u) {
        return TraceModels(ray, true);
    }
    if (TraceAny(ray, RayLevelMask)) {
        return true;
    }
    return (mode == 1u) && TraceModels(ray, false);
}

// A Light Source pick's object size (SceneLightSourceW in rt64_texture_marks.cpp): its radius from the fraction of the
// light's w, 0 for a lamp (whole). Its light leaves from the whole object, not a point inside it, so it lights what
// is round it evenly instead of only through the gaps in its own shape (L, 2026-10-22: "make the OBJECT itself
// light source, dont add balls").
float LightSourceRadius(float w) {
    const float f = frac(w);
    return (f > 0.01f) ? (f - 0.05f) / 0.9f * 1000.0f : 0.0f;
}

// A lamp's light, traced from a surface towards it: blocked by anything solid on the way (a cut-out only where
// solid). The lamp's own fitting (within 90 units of the light, or of a Light Source's object) lets it all out, so
// the lamp lights up as normal.
float TraceLampVisible(RayDesc ray, float3 light, float radius) {
    // The ray points at the light, so what lies within reach of it is the ray's last stretch: the ray stops short of it.
    const float clear = max(90.0f, radius + 10.0f);
    const float toLight = length(light - ray.Origin) / max(length(ray.Direction), 1e-4f);
    ray.TMax = min(ray.TMax, toLight - clear);
    if (ray.TMax <= ray.TMin) {
        return 1.0f;
    }
    // With the player's traced shadows off, the light goes on through Banjo.
    return TraceOccluded(ray, PlayerShadowsOff() ? 1u : 0u) ? 0.0f : 1.0f;
}

// Traced light beams: the light's shafts through the air, where the sun (or a room's window light) reaches. Along the
// eye's ray to the surface, a dozen points (spaced on a 4x4 pattern so the gaps fill in across neighbours), each tested
// with a ray towards the light through the world's triangles: the lit ones glow, more looking towards the light. In
// a room the light only gets in at the windows, so the beams have the windows' shapes, and anything in them (Banjo
// too) cuts its shadow through them. Outdoors it is a thin haze with shafts between trees and under arches.
float3 TracedBeams(int2 pixel, float depth) {
    const float strength = asfloat(gLights.Load(16));
    if (strength <= 0.0f) {
        return 0.0f;
    }
    const float3 roomLight = asfloat(gLights.Load3(20));
    const bool room = dot(roomLight, roomLight) > 0.25f;
    float3 toLight;
    if (room) {
        toLight = normalize(roomLight);
    }
    else {
        if (dot(gConstants.sun.xyz, gConstants.sun.xyz) < 0.25f) {
            return 0.0f;
        }
        toLight = normalize(ViewToWorldDirection(gConstants.sun.xyz));
        // The sun under the horizon lights no air.
        if (toLight.y < 0.05f) {
            return 0.0f;
        }
    }
    const float3 surface = (depth >= 0.99999f) ? normalize(ViewPosition(pixel, 0.5f)) * 4000.0f : ViewPosition(pixel, depth);
    const float reach = min(length(surface), 4000.0f);
    const float3 look = surface / max(length(surface), 1e-3f);
    // Fewer steps outdoors, where the haze is thin and the shafts soft (the beams were over half the traced pass's time,
    // L 2026-10-21: performance very bad); the Bayer offsets below spread the steps between neighbouring pixels.
    // Ray detail distances take a room's eight down to no fewer than four: with one or two, the Bayer offsets turned a
    // pixel's whole beam on or off and the 4x4 pattern showed as a mesh over the scene (L, 2026-10-22).
    const int Samples = (room || RayResolutionHigh()) ? max(8 >> RayDetail(reach), 4) : 4;
    const float step = reach / float(Samples);
    const int2 cell = pixel & 3;
    const float bayer[16] = { 0.0f, 8.0f, 2.0f, 10.0f, 12.0f, 4.0f, 14.0f, 6.0f, 3.0f, 11.0f, 1.0f, 9.0f, 15.0f, 7.0f, 13.0f, 5.0f };
    const float offset = (bayer[cell.y * 4 + cell.x] + 0.5f) / 16.0f;
    float lit = 0.0f;
    [loop] for (int i = 0; i < Samples; i++) {
        const float t = (float(i) + offset) * step;
        RayDesc ray;
        ray.Origin = ViewToWorldPoint(look * t);
        ray.Direction = toLight;
        ray.TMin = 0.0f;
        ray.TMax = 20000.0f;
        lit += TraceOccluded(ray, 0u) ? 0.0f : step;
    }
    // Brighter looking towards the light (forward scattering).
    const float toward = saturate(dot(normalize(ViewToWorldDirection(look)), toLight));
    const float phase = 0.45f + 1.4f * toward * toward * toward;
    const float density = room ? 0.0006f : 0.00008f;
    return float3(1.0f, 0.93f, 0.78f) * (strength * density * phase * lit);
}

// The remembered colour at a spot, blended between the eight nearest cells (by how near their centres are, the ones
// remembered only): one cell's colour alone showed in reflections as 16-unit squares (L, 2026-10-21: blocky ice).
bool RadianceLoad(float3 world, out float3 colour) {
    const float3 cellAt = world * (1.0f / 16.0f) - 0.5f;
    const float3 base = floor(cellAt);
    const float3 f = cellAt - base;
    float3 sum = 0.0f;
    float weights = 0.0f;
    [unroll] for (int k = 0; k < 8; k++) {
        const float3 corner = float3(float(k & 1), float((k >> 1) & 1), float((k >> 2) & 1));
        const float3 w3 = lerp(1.0f - f, f, corner);
        const float w = w3.x * w3.y * w3.z;
        uint check;
        const uint at = RadianceCell((base + corner + 0.5f) * 16.0f, check);
        const uint2 entry = gRadianceCache.Load2(at);
        if ((entry.x == check) && (w > 0.0f)) {
            sum += float3(float(entry.y & 255u), float((entry.y >> 8) & 255u), float((entry.y >> 16) & 255u)) * (w / 255.0f);
            weights += w;
        }
    }
    colour = (weights > 0.0f) ? sum / weights : 0.0f;
    return weights > 0.05f;
}

// Traced reflections: the same mirror ray as ScreenSpaceReflection, but through the world's triangles (a ray query
// over gSceneBVH, in world space) instead of marching the depth, so it finds what the depth hides (the back of a
// pillar, what is behind the nearest surface) and misses nothing between steps. Where it lands: the scene's colour
// there when that spot is on the screen and in view; when it is off the screen or hidden behind something nearer, the
// colour of the nearest spot of the screen in its direction, trusted less (or, with Ray tracing hit colours, the
// colour that spot had when last seen). A ray that leaves the world brings the sky.
// How much a pixel's surface reflects by its material (Parallax's list and picks), found by a short ray from just in
// front of it: metal, glazed tiles and smooth surfaces as their sliders say (fully, 60% and 35% by default); otherwise for anything else (L, 2026-10-21:
// ray tracing took no notice of the material list).
// The geometry a pixel's surface belongs to (a short ray from just in front of it); false where the ray finds none.
// The main pass asks twice for the same spot (its material, then how much it reflects): the second time reads the first's answer.
static bool gSurfaceKnown = false;
static float3 gSurfaceCenter = 0.0f;
static bool gSurfaceFound = false;
static uint gSurfaceGeometry = 0u;

bool SurfaceGeometryTraced(float3 center, out uint geometry) {
    geometry = 0u;
    const float distance = length(center);
    if (distance < 10.0f) {
        return false;
    }
    RayDesc ray;
    ray.Origin = ViewToWorldPoint(center * (1.0f - 6.0f / distance));
    ray.Direction = ViewToWorldDirection(center / distance);
    ray.TMin = 0.0f;
    ray.TMax = 12.0f + distance * 0.004f;
    RayQuery<RAY_FLAG_FORCE_OPAQUE | RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES> query;
    query.TraceRayInline(gSceneBVH, 0, 0xFFu, ray);
    query.Proceed();
    if (query.CommittedStatus() != COMMITTED_TRIANGLE_HIT) {
        return false;
    }
    geometry = RayGeometryOf(query.CommittedInstanceID(), query.CommittedGeometryIndex());
    return true;
}

bool SurfaceGeometry(float3 center, out uint geometry) {
    if (!gSurfaceKnown || any(center != gSurfaceCenter)) {
        gSurfaceFound = SurfaceGeometryTraced(center, gSurfaceGeometry);
        gSurfaceCenter = center;
        gSurfaceKnown = true;
    }
    geometry = gSurfaceGeometry;
    return gSurfaceFound;
}

// Whether a pixel's surface (view space) is Banjo himself: inside his capsule (InsideBanjo) and a model's triangle. The capsule
// alone took in the ground round his feet, a circle where his fur's smoothing went and the model shadows were left
// out, which showed as a lighter ring round him with no shadow (L, 2026-10-22).
bool OnBanjoTraced(float3 center) {
    if (!InsideBanjo(ViewToWorldPoint(center))) {
        return false;
    }
    uint geometry;
    return SurfaceGeometry(center, geometry) && ((RayGeometryFlags(geometry) & 4u) != 0u);
}

float MaterialShine(float3 center, float otherwise) {
    // Graphics > Ray Tracing's Metal, Tiles and Smooth reflection sliders (gLights 11, packed; 0 when nothing in the
    // scene has a material that reflects, and no ray is needed).
    const uint packed = uint(asfloat(gLights.Load(44)) + 0.5f);
    if (packed == 0u) {
        return otherwise;
    }
    uint geometry;
    if (!SurfaceGeometry(center, geometry)) {
        return otherwise;
    }
    const uint material = RayGeometryMaterial(geometry);
    return (material == 12u) ? float(packed & 0xFFu) / 100.0f : (material == 14u) ? float((packed >> 8) & 0xFFu) / 100.0f :
        (material == 16u) ? float(packed >> 16) / 100.0f : otherwise;
}

// A pixel's surface's Ray Tracing Material Pick Mode material, none (present false) where it has none.
RayPbr PbrAt(float3 center) {
    uint geometry;
    if (!RayPbrOn() || !SurfaceGeometry(center, geometry)) {
        return RayPbrNone();
    }
    return RayGeometryPbr(geometry);
}

// A reflection ray from origin along direction (view space). softness (0 to 1) blurs what it finds towards the half-size scene
// (a rough surface's lobe); a surface with a Ray Tracing Material Pick Mode material tints it by its albedo and adds its
// emissive, as the ray's payload.
float3 HitNormal(float3 origin, float3 direction, float t);
float3 HitFaceNormal(float3 origin, float3 direction, float t, uint geometry, uint primitive);
float3 PathDirectLight(float3 at, float3 normal);

// The light round about, for a reflected spot the screen can't show: the picture's average brightness from five points
// spread over it (a dark cave stays dark, a sunny field bright).
float3 RoomLight() {
    const float2 points[5] = { float2(0.25f, 0.25f), float2(0.75f, 0.25f), float2(0.5f, 0.5f), float2(0.25f, 0.75f), float2(0.75f, 0.75f) };
    float3 sum = 0.0f;
    [unroll] for (int k = 0; k < 5; k++) {
        sum += gColorHalf.SampleLevel(LinearSampler, points[k], 0).rgb;
    }
    return sum * 0.2f;
}

float4 TracedReflectionRay(float3 origin, float3 direction, float softness) {
    const float rayDistance = 3000.0f;
    RayDesc ray;
    ray.Origin = ViewToWorldPoint(origin);
    ray.Direction = ViewToWorldDirection(direction);
    ray.TMin = 0.0f;
    // The direction keeps the view's scale, so t is in view units.
    ray.TMax = rayDistance;
    // Cut-outs are seen where their texture is solid (a grate's bars, Banjo's textured parts: characters are drawn as
    // cut-outs), passed by in their holes.
    RayQuery<RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES> query;
    query.TraceRayInline(gSceneBVH, 0, 0xFFu, ray);
    while (query.Proceed()) {
        if (query.CandidateType() != CANDIDATE_NON_OPAQUE_TRIANGLE) {
            continue;
        }
        const uint geometry = RayGeometryOf(query.CandidateInstanceID(), query.CandidateGeometryIndex());
        if (RayCutoutSolid(geometry, query.CandidatePrimitiveIndex(), query.CandidateTriangleBarycentrics())) {
            query.CommitNonOpaqueTriangleHit();
        }
    }
    const float2 size = gConstants.projection.zw;
    if (query.CommittedStatus() != COMMITTED_TRIANGLE_HIT) {
        // The ray left the world: it sees the sky. Where that direction lies on the screen and shows sky, that
        // pixel's colour; otherwise the haze at the horizon stands in, trusted less.
        const float3 far = origin + direction * 50000.0f;
        if (far.z < -1.0f) {
            const float2 skyAt = ViewToPixel(far);
            const float2 skyInside = clamp(skyAt, float2(0.0f, 0.0f), size - 1.0f);
            if (all(skyAt == skyInside) && (LoadDepth(int2(skyInside)) >= 0.99999f)) {
                return float4(gColor.SampleLevel(LinearSampler, (skyInside + 0.5f) / size, 0).rgb, RayEdgeFade(skyInside));
            }
        }
        return float4(gConstants.fogColor.rgb, 0.6f);
    }
    const float3 hit = origin + direction * query.CommittedRayT();
    if (hit.z > -1.0f) {
        return 0.0f;
    }
    const float2 at = ViewToPixel(hit);
    const float2 inside = clamp(at, float2(0.0f, 0.0f), size - 1.0f);
    const bool onScreen = all(at == inside);
    const float sampleDepth = LoadDepth(int2(inside));
    const float thickness = max(-hit.z * 0.03f, 20.0f);
    const bool inView = onScreen && ((sampleDepth >= 0.99999f) || (ViewZ(sampleDepth) - hit.z <= thickness));
    float3 colour = gColor.SampleLevel(LinearSampler, (inside + 0.5f) / size, 0).rgb;
    if (softness > 0.0f) {
        colour = lerp(colour, gColorHalf.SampleLevel(LinearSampler, (inside + 0.5f) / size, 0).rgb, saturate(softness * 2.0f));
    }
    if (RayPbrOn()) {
        const RayPbr hitMaterial = RayGeometryPbr(RayGeometryOf(query.CommittedInstanceID(), query.CommittedGeometryIndex()));
        colour = colour * DiffuseAlbedo(hitMaterial) * (1.0f + hitMaterial.emissive);
    }
    if (!inView && HitColoursOn()) {
        // Off the screen or hidden: the colour the surface had when it was last seen.
        float3 remembered;
        if (RadianceLoad(ViewToWorldPoint(hit), remembered)) {
            return float4(remembered, 0.85f);
        }
    }
    // Off the screen or hidden, the screen there shows something else (a mirror showed stripes of whatever was drawn
    // where the hit would be, L 2026-10-22): a textured surface's own texel, lit there: the sun and the nearest lamp
    // where they reach it (PathDirectLight), and the light round about (RoomLight), so a mirror keeps showing what is
    // behind the camera, dark where it is dark.
    if (!inView && RayTexturesOn()) {
        const uint hitGeometry = RayGeometryOf(query.CommittedInstanceID(), query.CommittedGeometryIndex());
        if ((RayGeometryFlags(hitGeometry) & 2u) != 0u) {
            const float3 texel = RayTexel(hitGeometry, query.CommittedPrimitiveIndex(), query.CommittedTriangleBarycentrics()).rgb;
            const float3 hitNormal = HitFaceNormal(origin, direction, query.CommittedRayT(), hitGeometry, query.CommittedPrimitiveIndex());
            const float3 light = RoomLight() * 1.6f + PathDirectLight(hit, hitNormal);
            return float4(texel * light, 0.85f);
        }
    }
    return float4(colour, inView ? RayEdgeFade(inside) : 0.5f);
}

float4 TracedReflection(int2 pixel, float3 center, float3 normal) {
    const float3 direction = reflect(normalize(center), normal);
    const float3 origin = center + normal * max(-center.z * 0.002f, 1.0f);
    return TracedReflectionRay(origin, direction, 0.0f);
}

// A reflection off a rough surface (Ray Tracing Material Pick Mode): rays over the GGX lobe of the roughness (0 to 1), a few
// to a pixel with the 4x4 block's pattern spreading the rest (as StochasticReflection), weighted by the BRDF over each ray's
// probability, so a tight lobe is a mirror and a wide one the brushed blur of the scene.
float4 TracedRoughReflection(int2 pixel, float3 center, float3 normal, float roughness) {
    if (roughness < 0.03f) {
        return TracedReflection(pixel, center, normal);
    }
    // One ray along the mirror direction, what it finds blurred by the roughness (TracedReflectionRay's softness): the
    // lobe's few rays, a different few each pixel of a 4x4 block with nothing to even them out, showed as a dotted mesh
    // over every surface with a material (L, 2026-10-22).
    if (true) {
        const float3 origin = center + normal * max(-center.z * 0.002f, 1.0f);
        const float4 found = TracedReflectionRay(origin, reflect(normalize(center), normal), roughness);
        // A rough surface's lobe spreads its light thin: it fades well down, so rough and worn metal shows a dull sheen
        // rather than a dimmed mirror (L, 2026-10-22: metal too shiny).
        return float4(found.rgb, found.a * lerp(1.0f, 0.15f, smoothstep(0.1f, 0.9f, roughness)));
    }
    const float3 incoming = normalize(center);
    const float3 V = -incoming;
    const float3 up = (abs(normal.z) < 0.999f) ? float3(0.0f, 0.0f, 1.0f) : float3(1.0f, 0.0f, 0.0f);
    const float3 tangent = normalize(cross(up, normal));
    const float3 bitangent = cross(normal, tangent);
    const float3 origin = center + normal * max(-center.z * 0.002f, 1.0f);
    const uint cell = uint(pixel.x & 3) + 4u * uint(pixel.y & 3);
    const float m = roughness * roughness;
    const float m2 = m * m;
    float3 colourSum = 0.0f;
    float hitSum = 0.0f;
    float totalSum = 0.0f;
    [unroll] for (int r = 0; r < 4; r++) {
        // A fourth ray only for the wider lobes.
        if ((r == 3) && (roughness < 0.35f)) {
            continue;
        }
        const float n = float((cell * 7u) % 16u) * 4.0f + float(r);
        const float2 xi = frac(0.5f + n * float2(0.7548776662f, 0.5698402910f));
        const float phi = 6.28318531f * xi.x;
        const float cosTheta = sqrt((1.0f - xi.y) / (1.0f + (m2 - 1.0f) * xi.y));
        const float sinTheta = sqrt(max(1e-5f, 1.0f - cosTheta * cosTheta));
        const float3 H = normalize(tangent * (sinTheta * cos(phi)) + bitangent * (sinTheta * sin(phi)) + normal * cosTheta);
        const float d = (cosTheta * m2 - cosTheta) * cosTheta + 1.0f;
        const float pdf = max(m2 / (3.14159265f * d * d) * cosTheta, 1e-4f);
        const float3 direction = reflect(incoming, H);
        if (dot(direction, normal) <= 0.0f) {
            continue;
        }
        const float weight = StochasticWeight(V, direction, normal, roughness) / pdf;
        totalSum += weight;
        const float4 found = TracedReflectionRay(origin, direction, roughness);
        colourSum += found.rgb * (weight * found.a);
        hitSum += weight * found.a;
    }
    if (hitSum <= 0.0f) {
        return 0.0f;
    }
    return float4(colourSum / hitSum, saturate(hitSum / max(totalSum, 1e-5f)));
}

// Shadows from the level's lights (lamps, fires): for each light that reaches the surface, rays from it to the light
// through the world's triangles; blocked, the surface is darker the closer the light and the more it faces it. A
// couple of rays over a small disc at the light, so the edge has a penumbra. The light's own fitting (a lamp's
// shade) doesn't count: the ray stops short of it.
// Whether a spot is shut in (a room, a cave): straight up and four ways up at a slant all meet something. The sun
// doesn't reach in there, and the game's own lighting is already right, so the traced sun shadows leave it alone
// (otherwise the roof shadowed the whole room, and its walls facing away from the sun darkened too).
// The rays reach as far as the sun's shadow rays (20000). At 6000 a big cave's roof was out of reach: Terrydactyland's
// Inside the Mountain pool, with its roof far overhead, counted as open, so it took the sun's shadow, and only the
// spots under a nearby ledge counted as shut in and kept the game's lighting, in hard ledge-shaped patches (L, 2026-11-10).
bool Enclosed(float3 worldStart) {
    const float3 directions[5] = { float3(0.0f, 1.0f, 0.0f), float3(0.82f, 0.57f, 0.0f), float3(-0.82f, 0.57f, 0.0f), float3(0.0f, 0.57f, 0.82f), float3(0.0f, 0.57f, -0.82f) };
    [loop] for (int k = 0; k < 5; k++) {
        RayDesc ray;
        ray.Origin = worldStart;
        ray.Direction = directions[k];
        ray.TMin = 0.0f;
        ray.TMax = 20000.0f;
        // Only the level makes a room: Banjo standing over the spot doesn't, nor a model beside it (a note pedestal
        // closed the one way out for the floor round it, so its shadow there came out lit and the rest dark: a
        // reversed shadow, L 2026-10-22).
        if (!TraceAny(ray, RayLevelMask)) {
            return false;
        }
    }
    return true;
}

// The level's lights (lamps, fires), traced: each lights what it can see and leaves the rest in the dark. Within a
// light's reach the room's own light is dimmed (keep, returned) and the light's own added back (lamp, rgb) only where
// rays to it get through and the surface faces it, falling off with distance. So a lamp throws hard-edged shadows of
// what stands between (two rays a pixel over a small disc at the light, turned from pixel to pixel, a soft edge), not just a glow over the room
// (L, 2026-10-20: "they don't emit ray traced light").
// Half-resolution ray tracing: 2 leaves the lamps' traced light out (lamp stays 0; TracedHalfLamp reads it from the
// indirect pass's third band) and only works out the shade.
static int gLampHalf = 0;

float LightShadows(int2 pixel, float3 center, float3 normal, out float3 lamp) {
    lamp = 0.0f;
    const uint count = uint(asfloat(gLights.Load(0)) + 0.5f);
    if (count == 0u) {
        return 1.0f;
    }
    const float distanceFade = saturate(1.0f - (-center.z / ShadowFadeScale(gConstants.shadows.y) - 4000.0f) / 3000.0f);
    if (distanceFade <= 0.0f) {
        return 1.0f;
    }
    const float3 start = ViewToWorldPoint(center + normal * max(-center.z * 0.003f + 2.0f, 2.0f));
    const float3 worldNormal = normalize(ViewToWorldDirection(normal));
    float influence = 0.0f;
    // A turn of the disc's points for each pixel (interleaved gradient noise), so two rays a light over neighbouring
    // pixels cover the disc as four did, at half the cost (L, 2026-10-22: Bottles' House at 20 fps).
    // Noise smoothing takes the turn towards the same for every pixel.
    const float turn = InterleavedNoise(pixel) * 6.2831853f * (1.0f - RtSmoothing() * 0.8f);
    uint traced = 0u;
    // Fewer lights and rays far off (Ray detail distances): six lights at two rays, three at one, then one at one.
    const uint detail = RayDetail(-center.z);
    const uint mostTraced = (detail == 0u) ? 6u : ((detail == 1u) ? 3u : 1u);
    const int rays = RayResolutionHigh() ? 4 : ((detail == 0u) ? 2 : 1);
    [loop] for (uint i = 0u; i < count; i++) {
        const float4 light = asfloat(gLights.Load4(16u * (i + 4u)));
        const float3 toLight = light.xyz - start;
        const float distance = length(toLight);
        const float radius = LightSourceRadius(light.w);
        const float fromSurface = max(distance - radius, 0.0f);
        if ((distance < 30.0f) || (fromSurface > light.w)) {
            continue;
        }
        const float falloff = saturate(1.0f - fromSurface / light.w);
        // A Light Source pick leaves the room's own light as it is (dimming it round the object and adding its own
        // back drew a bright patch, a "ball", round it; L 2026-10-22) and adds a gentler light that fades out
        // smoothly, so what is round the object is just lit a little more, evenly.
        const bool source = radius > 0.0f;
        const float reachHere = source ? (0.45f * falloff * falloff * falloff) : (falloff * falloff);
        if (!source) {
            influence = max(influence, reachHere);
        }
        const float3 direction = toLight / distance;
        const float facing = dot(worldNormal, direction);
        // At most six lights traced a pixel (a room full of lamps traced every one). A light that would add less than a
        // step of the picture's colour here isn't traced (nor counted, so a nearer one gets its turn).
        if ((facing <= 0.0f) || (traced >= mostTraced) || (gLampHalf == 2) || (1.3f * reachHere * facing * distanceFade < 0.002f)) {
            continue;
        }
        traced++;
        // Two points (four at Ray tracing resolution High) on a small disc round the light. The rays go right up to the flame, through its fitting
        // (TraceLampVisible); a Light Source's stop at its object.
        const float stopShort = max(3.0f, radius);
        const float discRadius = 3.0f;
        const float3 side = normalize(cross(direction, float3(0.0f, 1.0f, 0.0f)) + float3(1e-4f, 0.0f, 0.0f));
        const float3 across = cross(direction, side);
        float visible = 0.0f;
        [unroll] for (int k = 0; k < 4; k++) {
            if (k >= rays) {
                break;
            }
            const float angle = float(k) * ((rays == 4) ? 1.5707963f : 3.1415927f) + turn;
            const float3 target = light.xyz + (side * cos(angle) + across * sin(angle)) * discRadius;
            const float3 toTarget = target - start;
            const float reach = length(toTarget) - stopShort;
            if (reach <= 1.0f) {
                visible += 1.0f / float(rays);
                continue;
            }
            RayDesc ray;
            ray.Origin = start;
            ray.Direction = toTarget / (reach + stopShort);
            ray.TMin = 0.0f;
            ray.TMax = reach;
            // Banjo casts his shadow from the lamps too.
            visible += TraceLampVisible(ray, light.xyz, radius) / float(rays);
        }
        lamp += float3(1.0f, 0.8f, 0.55f) * (1.3f * reachHere * saturate(facing) * visible);
    }
    lamp *= distanceFade;
    return lerp(1.0f, 1.0f - 0.55f * influence, distanceFade);
}

// Banjo's contact shadow, traced: while the sun shadows leave him out (the HD shadows give him one), the ground and
// anything low beside him is shadowed by him straight overhead: three rays a little apart, up from the surface, a
// hit within his height darkening it, softer the further away he is. His shadow stays under him as he moves.
float BanjoContactShadow(float3 center, float3 normal) {
    const float3 banjo = float3(gConstants.rippleX.w, gConstants.rippleAge.w, gConstants.rippleZ.w);
    if (gConstants.rippleAge.w < -1e8f) {
        return 1.0f;
    }
    const float3 world = ViewToWorldPoint(center);
    const float2 across = world.xz - banjo.xz;
    const float reach = 170.0f;
    const float horizontal = length(across);
    if ((horizontal > reach) || (world.y > banjo.y + 40.0f) || (world.y < banjo.y - 260.0f)) {
        return 1.0f;
    }
    const float3 up = normalize(ViewToWorldDirection(normalize(gConstants.worldY.xyz)));
    const float3 side = normalize(cross(up, float3(0.0f, 0.0f, 1.0f)) + float3(0.0f, 1e-4f, 0.0f));
    const float3 along = cross(up, side);
    const float3 start = ViewToWorldPoint(center + normal * 3.0f);
    float blocked = 0.0f;
    [unroll] for (int k = 0; k < 3; k++) {
        const float angle = float(k) * 2.0943951f;
        const float3 direction = normalize(up + (side * cos(angle) + along * sin(angle)) * 0.12f);
        RayDesc ray;
        ray.Origin = start;
        ray.Direction = direction;
        ray.TMin = 0.0f;
        ray.TMax = 320.0f;
        // Only Banjo himself counts: a roof or branch overhead would put a dark disc round him wherever he went.
        blocked += TraceOccluded(ray, 2u) ? (1.0f / 3.0f) : 0.0f;
    }
    // The shadow fades out towards its edge.
    return 1.0f - 0.45f * blocked * saturate(1.0f - horizontal / reach);
}

// Models' shadows straight down (L, 2026-10-21: a Jinjo's or a bird's hovering over the ground cast none in a cave):
// from a surface facing up, three rays a little apart straight up; one that meets a model (not the level's own
// geometry; Banjo too, unless Traced shadows of the player is off) within 400 units shades it, more the nearer the model, so the shadow is dark
// and sharp under something low and faint and soft under something high. Where the textures can't be read (a frame
// that reuses the structure) nothing is known about the models, so there is none.
float ModelShadow(float3 center, float3 normal) {
    if (!RayTexturesOn()) {
        return 1.0f;
    }
    const float3 worldNormal = normalize(ViewToWorldDirection(normal));
    if (worldNormal.y < 0.4f) {
        return 1.0f;
    }
    // Faded out from 3000 to 4000 units away: there a model's shadow is a pixel or two, and its rays were traced for every
    // floor pixel out to the horizon.
    const float distanceFade = saturate((4000.0f + center.z / ShadowFadeScale(gConstants.shadows.y)) / 1000.0f);
    if (distanceFade <= 0.0f) {
        return 1.0f;
    }
    const float3 start = ViewToWorldPoint(center + normal * max(-center.z * 0.002f + 1.0f, 2.0f));
    const float reach = 400.0f;
    float shade = 0.0f;
    // Two rays from opposite sides, turned a different way each pixel (the noise smoothing evens them out). Where only
    // one meets a model (the shadow's edge) six more spread over the cone: two alone cast two hard copies of the model's
    // low-poly outline, a blocky edge in two shades (L, 2026-10-23).
    const int Rays = 8;
    const float turn = frac(52.9829189f * frac(dot(center.xy, float2(0.06711056f, 0.00583715f)) * 37.0f) + NoiseFrameOffset()) * 3.14159265f * (1.0f - RtSmoothing() * 0.8f);
    int traced = 0;
    int hits = 0;
    [loop] for (int k = 0; k < Rays; k++) {
        if ((k == 2) && (hits != 1)) {
            break;
        }
        // The first two across the cone, the rest spread over it (golden angle).
        const float angle = turn + ((k < 2) ? float(k) * 3.14159265f : float(k) * 2.39996323f);
        const float radius = (k < 2) ? 0.08f : sqrt((float(k - 2) + 0.5f) / float(Rays - 2)) * 0.1f;
        traced++;
        RayDesc ray;
        ray.Origin = start;
        ray.Direction = normalize(float3(cos(angle) * radius, 1.0f, sin(angle) * radius));
        ray.TMin = 0.0f;
        ray.TMax = reach;
        // The first thing above decides: a model shades, the level (a roof, a ledge) stops the ray. The nearest model
        // first (the models' instance is small, and most rays meet none); only then is the level asked whether
        // anything of it comes before. Solid triangles are taken as they come; only cut-outs are looked at one by one.
        RayQuery<RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES> query;
        query.TraceRayInline(gSceneBVH, 0, RayModelMask, ray);
        while (query.Proceed()) {
            if (query.CandidateType() != CANDIDATE_NON_OPAQUE_TRIANGLE) {
                continue;
            }
            const uint geometry = RayGeometryOf(query.CandidateInstanceID(), query.CandidateGeometryIndex());
            if (!RayCutoutSolid(geometry, query.CandidatePrimitiveIndex(), query.CandidateTriangleBarycentrics())) {
                continue;
            }
            query.CommitNonOpaqueTriangleHit();
        }
        if (query.CommittedStatus() == COMMITTED_TRIANGLE_HIT) {
            const float t = query.CommittedRayT();
            const uint geometry = RayGeometryOf(query.CommittedInstanceID(), query.CommittedGeometryIndex());
            const bool model = (RayGeometryFlags(geometry) & 4u) != 0u;
            if (model && !(PlayerShadowsOff() && BanjoHit(geometry, ray.Origin + ray.Direction * t))) {
                RayDesc below = ray;
                below.TMax = t;
                if (!TraceAny(below, RayLevelMask)) {
                    shade += 1.0f - t / reach;
                    hits++;
                }
            }
        }
    }
    return 1.0f - 0.55f * distanceFade * shade / float(max(traced, 1));
}

// The indirect pass's traced rays: a cosine-spread direction round the normal (ray index of 32 in a 4x4 block's
// spiral, the same ones SSGI's march uses, so IndirectAt's gather still sees all 32), traced through gSceneBVH.
float3 IndirectDirection(float3 normal, uint index) {
    const float3 side = normalize(cross(normal, (abs(normal.y) < 0.99f) ? float3(0.0f, 1.0f, 0.0f) : float3(1.0f, 0.0f, 0.0f)));
    const float3 across = cross(side, normal);
    const float diskRadius = sqrt((float(index) + 0.5f) / 32.0f);
    const float theta = float(index) * 2.39996323f;
    return normalize(side * (diskRadius * cos(theta)) + across * (diskRadius * sin(theta)) + normal * sqrt(max(1.0f - diskRadius * diskRadius, 0.0f)));
}

// How far a ray goes before it hits the world (view units), or a negative number when it doesn't within the reach.
float TraceDistance(float3 origin, float3 direction, float reach) {
    RayDesc ray;
    ray.Origin = ViewToWorldPoint(origin);
    ray.Direction = ViewToWorldDirection(direction);
    ray.TMin = 0.0f;
    ray.TMax = reach;
    RayQuery<RAY_FLAG_CULL_NON_OPAQUE | RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES> query;
    query.TraceRayInline(gSceneBVH, 0, RayWorldMask, ray);
    while (query.Proceed()) {
    }
    return (query.CommittedStatus() == COMMITTED_TRIANGLE_HIT) ? query.CommittedRayT() : -1.0f;
}

// Whether the sky shows anywhere on the screen: the depth at sixteen points over it (4 x 4), any at the far plane.
bool SkyOnScreen() {
    const float2 size = gConstants.projection.zw;
    [unroll] for (int k = 0; k < 16; k++) {
        const float2 at = (float2(float(k & 3), float(k >> 2)) + 0.5f) * 0.25f * size;
        if (LoadDepth(int2(at)) >= 0.99999f) {
            return true;
        }
    }
    return false;
}

// TraceDistance with the geometry it met too (any where it met none), from the same ray.
float TraceDistanceGeometry(float3 origin, float3 direction, float reach, out uint geometry, out uint primitive) {
    geometry = 0u;
    primitive = 0u;
    RayDesc ray;
    ray.Origin = ViewToWorldPoint(origin);
    ray.Direction = ViewToWorldDirection(direction);
    ray.TMin = 0.0f;
    ray.TMax = reach;
    RayQuery<RAY_FLAG_CULL_NON_OPAQUE | RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES> query;
    query.TraceRayInline(gSceneBVH, 0, RayWorldMask, ray);
    while (query.Proceed()) {
    }
    if (query.CommittedStatus() != COMMITTED_TRIANGLE_HIT) {
        return -1.0f;
    }
    geometry = RayGeometryOf(query.CommittedInstanceID(), query.CommittedGeometryIndex());
    primitive = query.CommittedPrimitiveIndex();
    return query.CommittedRayT();
}

// Whether a ray (as TraceDistance traces it) meets anything within reach: the first triangle met ends the search, where
// only the nearest's distance needed the whole search.
bool TraceBlocked(float3 origin, float3 direction, float reach) {
    RayDesc ray;
    ray.Origin = ViewToWorldPoint(origin);
    ray.Direction = ViewToWorldDirection(direction);
    ray.TMin = 0.0f;
    ray.TMax = reach;
    RayQuery<RAY_FLAG_CULL_NON_OPAQUE | RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES | RAY_FLAG_ACCEPT_FIRST_HIT_AND_END_SEARCH> query;
    query.TraceRayInline(gSceneBVH, 0, RayWorldMask, ray);
    query.Proceed();
    return query.CommittedStatus() == COMMITTED_TRIANGLE_HIT;
}

// Traced ambient occlusion: the share of the cosine-spread rays that reach the open (a ray that hits something
// within the radius counts less the further away it was). Two rays a pixel, 32 over each 4x4 block.
// How far the indirect pass's rays start off the surface: clear of a second layer the game draws just over some ground
// (Spiral Mountain's open grass came out fully occluded and black with the rays starting a unit off it).
float IndirectLift(float3 center) {
    return max(-center.z * 0.003f, 8.0f);
}

// The occlusion from its two rays' distances (negative: met nothing).
float OcclusionFrom(float2 distances) {
    const float radius = gConstants.ambientOcclusion.y * 1.5f;
    float blocked = 0.0f;
    [unroll] for (int r = 0; r < 2; r++) {
        if ((distances[r] >= 0.0f) && (distances[r] <= radius)) {
            blocked += 1.0f - distances[r] / radius * 0.6f;
        }
    }
    return 1.0f - blocked * 0.5f;
}

float TracedOcclusion(float3 center, float3 normal, uint cell) {
    const float3 origin = center + normal * IndirectLift(center);
    const float radius = gConstants.ambientOcclusion.y * 1.5f;
    float2 distances;
    [unroll] for (int r = 0; r < 2; r++) {
        distances[r] = TraceDistance(origin, IndirectDirection(normal, cell * 2u + uint(r)), radius);
    }
    return OcclusionFrom(distances);
}

// The sky's light from a direction (world space up from the view's worldY): the horizon's haze at the horizon, bluer
// overhead, dimmer than the sky itself so it only lifts what the game's own ambient light leaves.
float3 SkyLight(float3 direction) {
    const float up = saturate(dot(direction, normalize(gConstants.worldY.xyz)));
    const float3 haze = gConstants.fogColor.rgb;
    return lerp(haze, haze * float3(0.75f, 0.9f, 1.25f), up) * 0.35f;
}

// The colour a traced ray brings back from where it landed (view space): that spot's colour on the screen when it is in
// view, else the nearest on the screen in its direction (or the remembered colour, with Ray tracing hit colours),
// with how much it is trusted.
float3 HitColour(float3 hit, out float trust) {
    const float2 size = gConstants.projection.zw;
    const float2 at = ViewToPixel(hit);
    const float2 inside = clamp(at, float2(0.0f, 0.0f), size - 1.0f);
    const bool onScreen = all(at == inside);
    const float sampleDepth = LoadDepth(int2(inside));
    const float thickness = max(-hit.z * 0.03f, 20.0f);
    const bool inView = onScreen && ((sampleDepth >= 0.99999f) || (ViewZ(sampleDepth) - hit.z <= thickness));
    float3 colour = gColorHalf.SampleLevel(LinearSampler, (inside + 0.5f) / size, 0).rgb;
    trust = inView ? RayEdgeFade(inside) : 0.35f;
    if (!inView && HitColoursOn()) {
        float3 remembered;
        if (RadianceLoad(ViewToWorldPoint(hit), remembered)) {
            colour = remembered;
            trust = 0.8f;
        }
    }
    return colour;
}

// Path tracing's bounces after the first (0: path tracing off), from the lights buffer.
uint PathBounces() {
    return min(uint(asfloat(gLights.Load(12)) + 0.5f), 4u);
}

// The normal of the surface a ray (view space) landed on at t: two more rays a hair to either side find two more
// points of it, and the normal is across the three, turned back towards the ray. Facing back along the ray when
// either misses (an edge).
float3 HitNormal(float3 origin, float3 direction, float t) {
    const float3 side = normalize(cross(direction, (abs(direction.y) < 0.9f) ? float3(0.0f, 1.0f, 0.0f) : float3(1.0f, 0.0f, 0.0f)));
    const float3 up = cross(side, direction);
    const float spread = 0.01f;
    const float3 d1 = normalize(direction + side * spread);
    const float3 d2 = normalize(direction + up * spread);
    const float t1 = TraceDistance(origin, d1, t * 1.5f + 50.0f);
    const float t2 = TraceDistance(origin, d2, t * 1.5f + 50.0f);
    if ((t1 < 0.0f) || (t2 < 0.0f)) {
        return -direction;
    }
    const float3 p0 = origin + direction * t;
    float3 normal = cross(origin + d1 * t1 - p0, origin + d2 * t2 - p0);
    if (dot(normal, normal) < 1e-8f) {
        return -direction;
    }
    normal = normalize(normal);
    return (dot(normal, direction) > 0.0f) ? -normal : normal;
}

// The normal of the face a ray (view space) met at t, from the triangle's own corners (the world positions the traced
// structure was built from), turned back towards the ray: what HitNormal found with two more rays a hit, for none.
// Where this frame's buffers aren't bound to the rays (a pass that reuses an earlier structure), HitNormal.
float3 HitFaceNormal(float3 origin, float3 direction, float t, uint geometry, uint primitive) {
    if (!RayTexturesOn()) {
        return HitNormal(origin, direction, t);
    }
    const uint base = (gRayGeometries.Load(geometry * 16u) + primitive * 3u) * 4u;
    const uint3 v = uint3(gRayIndices.Load(base), gRayIndices.Load(base + 4u), gRayIndices.Load(base + 8u));
    const float3 p0 = asfloat(gRayPositions.Load3(v.x * 16u));
    const float3 p1 = asfloat(gRayPositions.Load3(v.y * 16u));
    const float3 p2 = asfloat(gRayPositions.Load3(v.z * 16u));
    const float3 worldNormal = cross(p1 - p0, p2 - p0);
    // Into view space: a normal goes by the transpose of view to world (whose scale normalizing takes out).
    float3 normal = gConstants.worldX.xyz * worldNormal.x + gConstants.worldY.xyz * worldNormal.y + gConstants.worldZ.xyz * worldNormal.z;
    const float lengthSquared = dot(normal, normal);
    if (!(lengthSquared > 1e-12f)) {
        return -direction;
    }
    normal *= rsqrt(lengthSquared);
    return (dot(normal, direction) > 0.0f) ? -normal : normal;
}
// What a view-space ray first meets, seen-through things included (ice, glass and cut-outs count as solid), within reach.
float TraceDistanceSolid(float3 origin, float3 direction, float reach) {
    RayDesc ray;
    ray.Origin = ViewToWorldPoint(origin);
    ray.Direction = ViewToWorldDirection(direction);
    ray.TMin = 0.0f;
    ray.TMax = reach;
    RayQuery<RAY_FLAG_FORCE_OPAQUE | RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES> query;
    query.TraceRayInline(gSceneBVH, 0, RayWorldMask, ray);
    query.Proceed();
    return (query.CommittedStatus() == COMMITTED_TRIANGLE_HIT) ? query.CommittedRayT() : -1.0f;
}

// The true way a pixel's surface (view space) faces, from three rays from the camera, facing the camera (false where the rays
// don't all meet it, at its edges). The ice's own depths can't tell a wall's edge from a floor's: there it fell back to
// level, and a ray reflected off level ice went on into the wall and showed what is behind it (L, 2026-10-22, Icy Side).
bool SurfaceNormalTraced(float3 surface, out float3 normal) {
    normal = 0.0f;
    const float distance = length(surface);
    if (distance < 10.0f) {
        return false;
    }
    const float3 direction = surface / distance;
    const float3 side = normalize(cross(direction, (abs(direction.y) < 0.9f) ? float3(0.0f, 1.0f, 0.0f) : float3(1.0f, 0.0f, 0.0f)));
    const float3 up = cross(side, direction);
    const float spread = 0.004f;
    const float reach = distance * 1.2f + 20.0f;
    const float start = max(distance - 20.0f - distance * 0.05f, 0.0f);
    const float3 d1 = normalize(direction + side * spread);
    const float3 d2 = normalize(direction + up * spread);
    const float t0 = TraceDistanceSolid(direction * start, direction, reach - start);
    const float t1 = TraceDistanceSolid(d1 * start, d1, reach - start);
    const float t2 = TraceDistanceSolid(d2 * start, d2, reach - start);
    if ((t0 < 0.0f) || (t1 < 0.0f) || (t2 < 0.0f)) {
        return false;
    }
    const float3 p0 = direction * (start + t0);
    // The three must land on one face: a ray that met something else (the wall's far edge, what stands on the ice) gives
    // no normal.
    if (abs(start + t0 - distance) > max(distance * 0.03f, 6.0f)) {
        return false;
    }
    float3 n = cross(d1 * (start + t1) - p0, d2 * (start + t2) - p0);
    if (dot(n, n) < 1e-8f) {
        return false;
    }
    n = normalize(n);
    normal = (dot(n, direction) > 0.0f) ? -n : n;
    return true;
}

// Path tracing's light at a spot a path landed on (view space, with its normal): the sun where a ray reaches it, and the
// nearest few of the level's lights that reach it unblocked (cut-outs let it all through: the indirect pass has no
// textures to read). The screen's colour there already holds the light the game
// gave it; this is what the traced light adds, so sunlit patches and lamps light what is round the corner from them.
float3 PathDirectLight(float3 at, float3 normal) {
    float3 light = 0.0f;
    const float3 start = at + normal * max(-at.z * 0.002f, 1.0f);
    const float3 worldStart = ViewToWorldPoint(start);
    const float3 sun = normalize(gConstants.sun.xyz);
    const float sunFacing = dot(normal, sun);
    if (sunFacing > 0.0f) {
        if (!TraceBlocked(start, sun, 20000.0f)) {
            light += float3(1.0f, 0.93f, 0.78f) * (0.4f * sunFacing);
        }
    }
    const uint count = uint(asfloat(gLights.Load(0)) + 0.5f);
    const float3 worldNormal = normalize(ViewToWorldDirection(normal));
    uint traced = 0u;
    // One lamp a hop (three made path tracing the dearest part of a room full of lamps, L 2026-10-22).
    [loop] for (uint i = 0u; (i < count) && (traced < 1u); i++) {
        const float4 lamp = asfloat(gLights.Load4(16u * (i + 4u)));
        const float3 toLight = lamp.xyz - worldStart;
        const float distance = length(toLight);
        const float radius = LightSourceRadius(lamp.w);
        const float fromSurface = max(distance - radius, 0.0f);
        if ((distance < 10.0f) || (fromSurface > lamp.w)) {
            continue;
        }
        const float facing = dot(worldNormal, toLight / distance);
        if (facing <= 0.0f) {
            continue;
        }
        traced++;
        // Stops short of the lamp's own fitting.
        RayDesc ray;
        ray.Origin = worldStart;
        ray.Direction = toLight / distance;
        ray.TMin = 0.0f;
        ray.TMax = max(distance - max(60.0f, radius), 1.0f);
        RayQuery<RAY_FLAG_CULL_NON_OPAQUE | RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES | RAY_FLAG_ACCEPT_FIRST_HIT_AND_END_SEARCH> query;
        query.TraceRayInline(gSceneBVH, 0, RayWorldMask, ray);
        query.Proceed();
        if (query.CommittedStatus() == COMMITTED_TRIANGLE_HIT) {
            continue;
        }
        const float falloff = saturate(1.0f - fromSurface / lamp.w);
        light += float3(1.0f, 0.8f, 0.55f) * ((radius > 0.0f) ? (0.45f * falloff * falloff * falloff) : (1.3f * falloff * falloff)) * facing;
    }
    return light;
}

// Traced light (path traced): from the surface, two rays a pixel (32 over a 4x4 block) over the hemisphere, far enough
// to leave the world. A ray that leaves it brings the sky's light; one that lands brings the colour of where it lands
// (HitColour), the less the further off it was. With Path tracing on, the path goes on from there for Path tracing
// bounces more hops: each turns off the surface it landed on (its normal from HitNormal) in a cosine-spread
// direction, and brings what it meets (sky or a surface's colour) tinted by the colours along the way, so light
// carries round corners and into rooms. The directions are fixed per pixel, so the light holds still from frame to frame.
// distances: its first two rays' (the ones the traced occlusion uses too, so with both on they're traced once).
float3 TracedGI(float3 center, float3 normal, uint cell, out float2 distances) {
    const float3 origin = center + normal * IndirectLift(center);
    const float nearReach = gConstants.ambientOcclusion.y * 3.0f;
    const uint bounces = PathBounces();
    float3 light = 0.0f;
    distances = -1.0f;
    [loop] for (int r = 0; r < 2; r++) {
        const float3 direction = IndirectDirection(normal, cell * 2u + uint(r));
        uint hitGeometry, hitPrimitive;
        const float t = TraceDistanceGeometry(origin, direction, 15000.0f, hitGeometry, hitPrimitive);
        distances[r] = t;
        if (t < 0.0f) {
            light += SkyLight(normalize(ViewToWorldDirection(direction)));
            continue;
        }
        const float3 hit = origin + direction * t;
        if (hit.z > -1.0f) {
            continue;
        }
        const float far = lerp(1.0f, 0.4f, saturate(t / (nearReach * 4.0f)));
        float trust;
        float3 hitColour = HitColour(hit, trust);
        // A surface with a Ray Tracing Material Pick Mode material tints the light it sends back by its albedo, and an
        // emissive one gives off its own light into the ray's payload whether or not the picture shows it lit.
        if (RayPbrOn()) {
            const RayPbr hitMaterial = RayGeometryPbr(hitGeometry);
            hitColour = hitColour * DiffuseAlbedo(hitMaterial) + hitMaterial.albedo * (hitMaterial.emissive * 0.35f);
        }
        light += hitColour * trust * far;
        // The path's further hops. Each spot the path lands on also brings the sun's and the lamps' traced light
        // (PathDirectLight) on its own colour, so path tracing carries real light round corners, not only the colours
        // the picture shows.
        float3 throughput = hitColour * (0.8f * far);
        float3 at = hit;
        float3 from = direction;
        float reach = t;
        float3 previous = origin;
        // (The face each hop landed on, for its normal from the triangle itself: HitFaceNormal.)
        uint atGeometry = hitGeometry;
        uint atPrimitive = hitPrimitive;
        [loop] for (uint b = 0u; b < bounces; b++) {
            const float3 surfaceNormal = HitFaceNormal(previous, from, reach, atGeometry, atPrimitive);
            // Direct light on the first spot the path lands on only: further hops add little of it for their rays.
            if (b == 0u) {
                light += throughput * PathDirectLight(at, surfaceNormal);
            }
            const float3 start = at + surfaceNormal * max(-at.z * 0.002f, 1.0f);
            const float3 next = IndirectDirection(surfaceNormal, (cell * 2u + uint(r) + 11u * (b + 1u)) & 31u);
            const float tn = TraceDistanceGeometry(start, next, 15000.0f, atGeometry, atPrimitive);
            if (tn < 0.0f) {
                light += throughput * SkyLight(normalize(ViewToWorldDirection(next)));
                break;
            }
            const float3 nextHit = start + next * tn;
            if (nextHit.z > -1.0f) {
                break;
            }
            float nextTrust;
            const float3 nextColour = HitColour(nextHit, nextTrust);
            light += throughput * nextColour * nextTrust;
            throughput *= nextColour * 0.8f;
            if (max(throughput.r, max(throughput.g, throughput.b)) < 0.02f) {
                break;
            }
            previous = start;
            from = next;
            reach = tn;
            at = nextHit;
        }
    }
    return light * 0.5f;
}

// Traced subsurface scattering: the light that gets into a thin or soft surface (a leaf, a petal, wax) from the side away from the
// camera and comes out where it is seen. The sun and the nearest lamp behind the surface each get a ray from just behind
// it; reaching the light, they add the light times how squarely it faces the back. The light is tinted by the surface's own
// colour where it is added (scene * light). center and normal are view space, the normal facing the camera.
float3 TracedSubsurface(float3 center, float3 normal) {
    const float lift = IndirectLift(center);
    const float3 behind = center - normal * lift;
    float3 light = 0.0f;
    if (dot(gConstants.sun.xyz, gConstants.sun.xyz) > 0.25f) {
        const float3 toSun = normalize(gConstants.sun.xyz);
        const float back = saturate(-dot(normal, toSun));
        if ((back > 0.02f) && !TraceBlocked(behind, toSun, 20000.0f)) {
            light += float3(1.0f, 0.93f, 0.78f) * (0.9f * back);
        }
    }
    const uint count = uint(asfloat(gLights.Load(0)) + 0.5f);
    const float3 worldBehind = ViewToWorldPoint(behind);
    const float3 worldNormal = normalize(ViewToWorldDirection(normal));
    uint traced = 0u;
    [loop] for (uint i = 0u; (i < count) && (traced < 1u); i++) {
        const float4 lamp = asfloat(gLights.Load4(16u * (i + 4u)));
        const float3 toLight = lamp.xyz - worldBehind;
        const float distance = length(toLight);
        const float radius = LightSourceRadius(lamp.w);
        const float fromSurface = max(distance - radius, 0.0f);
        if ((distance < 10.0f) || (fromSurface > lamp.w)) {
            continue;
        }
        const float back = -dot(worldNormal, toLight / distance);
        if (back <= 0.0f) {
            continue;
        }
        traced++;
        RayDesc ray;
        ray.Origin = worldBehind;
        ray.Direction = toLight / distance;
        ray.TMin = 0.0f;
        ray.TMax = max(distance - max(60.0f, radius), 1.0f);
        RayQuery<RAY_FLAG_CULL_NON_OPAQUE | RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES | RAY_FLAG_ACCEPT_FIRST_HIT_AND_END_SEARCH> query;
        query.TraceRayInline(gSceneBVH, 0, RayWorldMask, ray);
        query.Proceed();
        if (query.CommittedStatus() == COMMITTED_TRIANGLE_HIT) {
            continue;
        }
        const float falloff = saturate(1.0f - fromSurface / lamp.w);
        light += float3(1.0f, 0.8f, 0.55f) * (1.3f * falloff * falloff * back);
    }
    return light;
}

// Traced refraction: where the eye's ray, bent as it enters the water (a surface pointing up at the viewer, an index
// of 1.33), meets the floor under it, as a pixel of the picture (the floor drawn there is what shows through);
// the unbent place when it meets nothing near.
int2 TracedRefractedPixel(float3 surface, float3 normal, int2 fallback) {
    const float3 bent = refract(normalize(surface), normal, 0.75f);
    if (dot(bent, bent) < 0.5f) {
        return fallback;
    }
    const float3 origin = surface + bent * 0.5f;
    const float t = TraceDistance(origin, bent, 2500.0f);
    if (t < 0.0f) {
        return fallback;
    }
    const float3 hit = origin + bent * t;
    if (hit.z > -1.0f) {
        return fallback;
    }
    return clamp(int2(ViewToPixel(hit)), int2(0, 0), int2(gConstants.projection.zw) - 1);
}
#endif

// The indirect pass's result for a pixel: GTAO's visibility (a) and SSGI's light (rgb) from the 4x4 block of the
// half-size pass round it, each weighted by how near its surface lies to this pixel's plane, so the block's 16
// slices and 32 rays come together without bleeding across edges (the spatial filter of the Unity GTAO's own
// passes; there is no temporal one, as the game has no motion vectors).
float4 IndirectAt(int2 pixel, float3 center, float3 normal, int softReach = 0) {
    const int2 halfSize = max(int2(gConstants.projection.zw) / 2, int2(1, 1));
    const int2 base = pixel / 2;
    const float tolerance = max(-center.z * 0.03f, 2.0f);
    // Soft (Banjo's fur): a wider gather by distance alone, as the fur's normals turn every pixel and the plane test
    // left each pixel its own two rays, which crawled.
    const bool soft = softReach > 0;
    const int reach = soft ? softReach : 1;
    float4 sum = 0.0f;
    float weight = 0.0f;
#ifdef RAY_TRACED
    // Traced, each texel holds its own one or two rays, so the gather is what smooths them. A window fixed to the 2x2
    // pixels a texel stands for gave all four the same light and jumped a whole texel column at the next: the ground
    // showed in square blocks, like a compressed picture (L, 2026-10-24). The window now slides with the pixel itself,
    // the same width (the 4x4 ray pattern's, so all its rays still count equally), texels at its edges counting for
    // the part of them inside it.
    const float2 at = (float2(pixel) + 0.5f) * 0.5f;
    const float halfWidth = float(reach) + 1.0f;
    const int2 first = int2(floor(at - halfWidth));
    [loop] for (int y = 0; y <= 2 * reach + 2; y++) {
        [loop] for (int x = 0; x <= 2 * reach + 2; x++) {
            const int2 cell = first + int2(x, y);
            const float2 inside = saturate(min(float2(cell) + 1.0f, at + halfWidth) - max(float2(cell), at - halfWidth));
            const float share = inside.x * inside.y;
            if (share <= 0.0f) {
                continue;
            }
            const int2 q = clamp(cell, int2(0, 0), halfSize - 1);
            const float sampleDepth = LoadDepth(q * 2);
            if (sampleDepth >= 0.99999f) {
                continue;
            }
            const float3 offset = ViewPosition(q * 2, sampleDepth) - center;
            const float planeDistance = soft ? length(offset) * 0.25f : abs(dot(offset, normal));
            const float w = saturate(1.0f - planeDistance / tolerance) * share;
            sum += gIndirect.Load(int3(q, 0)) * w;
            weight += w;
        }
    }
#else
    [loop] for (int y = -reach; y <= reach + 1; y++) {
        [loop] for (int x = -reach; x <= reach + 1; x++) {
            const int2 q = clamp(base + int2(x, y), int2(0, 0), halfSize - 1);
            const float sampleDepth = LoadDepth(q * 2);
            if (sampleDepth >= 0.99999f) {
                continue;
            }
            const float3 offset = ViewPosition(q * 2, sampleDepth) - center;
            const float planeDistance = soft ? length(offset) * 0.25f : abs(dot(offset, normal));
            const float w = saturate(1.0f - planeDistance / tolerance);
            sum += gIndirect.Load(int3(q, 0)) * w;
            weight += w;
        }
    }
#endif
    if (weight < 1e-3f) {
        return gIndirect.Load(int3(clamp(base, int2(0, 0), halfSize - 1), 0));
    }
    return sum / weight;
}

// Bounce light: the colour of nearby surfaces facing this one, gathered like the ambient occlusion over
// a wider radius: their average colour, as much of it as there is around (a corner gets more than an open
// floor), so colourful walls and floors light what is next to them.
// Every pixel uses the same sample pattern, and each sample reads the colour blurred over a small square:
// a pattern turned per pixel (as the ambient occlusion does) read single texels of the grass and fur a
// different way at each pixel, which showed as a fine dotted noise all over at high resolutions.
float3 BounceLight(int2 pixel, float depth) {
    const float3 center = ViewPosition(pixel, depth);
    const float3 normal = ViewNormal(pixel, center);
    const float radius = gConstants.ambientOcclusion.y * 1.5f;
    const float distance = max(-center.z, 1.0f);
    const float radiusPixels = clamp(radius * gConstants.projection.y * gConstants.projection.w * 0.5f / distance, 3.0f, gConstants.projection.w * 0.07f);
    const float2 size = gConstants.projection.zw;

    const int samples = 12;
    float3 light = 0.0f;
    float weight = 0.0f;
    [loop] for (int i = 0; i < samples; i++) {
        const float t = (float(i) + 0.5f) / float(samples);
        const float angle = float(i) * 2.39996323f + 1.0f;
        const float2 at = clamp(float2(pixel) + float2(cos(angle), sin(angle)) * sqrt(t) * radiusPixels, float2(0.0f, 0.0f), size - 1.0f);
        const int2 samplePixel = int2(round(at));
        const float sampleDepth = LoadDepth(samplePixel);
        if (sampleDepth >= 0.99999f) {
            continue;
        }
        const float3 v = ViewPosition(samplePixel, sampleDepth) - center;
        const float lengthSquared = dot(v, v);
        const float facing = saturate(dot(normal, v) * rsqrt(max(lengthSquared, 1e-4f)));
        const float w = facing * saturate(1.0f - lengthSquared / (radius * radius));
        // The sample's colour, averaged over a few pixels so the texture's detail doesn't decide it: one bilinear
        // tap of the scene's half-size copy (four pixels' average, blended with its neighbours').
        const float2 uv = (at + 0.5f) / size;
        const float3 colour = gColorHalf.SampleLevel(LinearSampler, uv, 0).rgb;
        light += colour * w;
        weight += w;
    }
    if (weight <= 1e-3f) {
        return 0.0f;
    }
    return (light / weight) * saturate(weight * (3.0f / float(samples)));
}

// How hot a colour looks (0 to 1): bright orange to yellow, like glowing lava and fire. Dull red rock and brown
// earth are too dark, pinks and white have too much blue, and pure reds (Kazooie) too little green.
float Warmth(float3 c) {
    return saturate((c.r - 0.55f) * 4.0f) * saturate((c.r * 0.6f - c.b) * 5.0f) * saturate((c.r * 0.97f - c.g) * 5.0f) *
        saturate((c.g - c.r * 0.12f) * 8.0f);
}

// How much heat rises through a pixel (0 to 1): hot surfaces at it or below it on screen, up to a fifth of the
// picture's height down, fading the further down they are. Three columns, the middle one counting twice, so
// the shimmer's sides fade out. The sky never counts as hot.
float WarmthBelow(int2 pixel) {
    const float2 size = gConstants.projection.zw;
    const float step = size.y * (9.0f / 540.0f);
    float warmth = 0.0f;
    [unroll]
    for (int column = -1; column <= 1; column++) {
        float hottest = 0.0f;
        [loop]
        for (int i = 0; i < 12; i++) {
            const int2 at = clamp(int2(round(float2(pixel) + float2(float(column) * 2.5f * step, float(i) * step))), int2(0, 0), int2(size) - 1);
            if (LoadDepth(at) < 0.99999f) {
                hottest = max(hottest, Warmth(gColor.Load(int3(at, 0)).rgb) * (1.0f - float(i) / 12.0f));
            }
        }
        warmth += hottest * ((column == 0) ? 0.5f : 0.25f);
    }
    return saturate(warmth * 1.5f);
}

// Heat haze: the scene so far, read a little to the side and up and down in waves that rise, more with
// distance. The waves are sized to the picture, not to pixels, so they look the same at any resolution,
// and read between pixels so the shimmer is smooth. A pixel isn't read from something nearer than itself,
// so near things keep their edges. view.w is the strength, or 2 + it when the haze only rises above warm
// surfaces (by lava); then it starts nearer, as the lava is often close by.
float3 HeatHaze(int2 pixel, float distance) {
    const float2 size = gConstants.projection.zw;
    const bool warmOnly = gConstants.view.w > 1.5f;
    const float strength = warmOnly ? (gConstants.view.w - 2.0f) * WarmthBelow(pixel) : gConstants.view.w;
    if (strength <= 0.0f) {
        return gColor.Load(int3(pixel, 0)).rgb;
    }
    // In 540ths of the picture's height: up to 3 far away.
    const float amount = strength * 3.0f * (warmOnly ? saturate((distance - 60.0f) / 900.0f) : saturate((distance - 150.0f) / 1800.0f));
    const float t = gConstants.view.z;
    const float2 at = float2(pixel) / size.y * 540.0f;
    const float2 wave = float2(sin(at.y * 0.21f + t * 6.0f) + 0.5f * sin(at.y * 0.083f + at.x * 0.035f + t * 2.9f),
        0.6f * sin(at.x * 0.13f + at.y * 0.05f + t * 4.3f));
    const float2 offset = wave * amount * (size.y / 540.0f);
    const int2 from = clamp(int2(round(float2(pixel) + offset)), int2(0, 0), int2(size) - 1);
    if (-ViewPositionAt(from).z < distance * 0.95f) {
        return gColor.Load(int3(pixel, 0)).rgb;
    }
    return gColor.SampleLevel(LinearSampler, (float2(pixel) + 0.5f + offset) / size, 0).rgb;
}

// Water: the water mask holds each water pixel's own depth (24 bits over rgb, a = 1), redrawn from the
// game's translucent surfaces. False where there is no water.
bool LoadWater(int2 pixel, out float depth) {
    pixel = clamp(pixel, int2(0, 0), int2(gConstants.projection.zw) - 1);
#ifdef MULTISAMPLING
    const float4 m = gWater.Load(pixel, 0);
#else
    const float4 m = gWater.Load(int3(pixel, 0));
#endif
    const uint3 b = uint3(round(m.rgb * 255.0f));
    depth = float((b.r << 16) | (b.g << 8) | b.b) / 16777215.0f;
    return m.a > 0.5f;
}

// Modern water's colours: the game's own water colour (rgb) and how opaque it drew it (a) at a pixel.
float4 LoadWaterColor(int2 pixel) {
    pixel = clamp(pixel, int2(0, 0), int2(gConstants.projection.zw) - 1);
#ifdef MULTISAMPLING
    return gWaterColor.Load(pixel, 0);
#else
    return gWaterColor.Load(int3(pixel, 0));
#endif
}

// Ice (waterMask 4): see-through level decals lying flat on a floor (Icy Side's frozen water), kept as the game drew
// them but reflecting.
bool LoadIce(int2 pixel, out float depth) {
    pixel = clamp(pixel, int2(0, 0), int2(gConstants.projection.zw) - 1);
#ifdef MULTISAMPLING
    const float4 m = gWater.Load(pixel, 0);
#else
    const float4 m = gWater.Load(int3(pixel, 0));
#endif
    const uint3 b = uint3(round(m.rgb * 255.0f));
    depth = float((b.r << 16) | (b.g << 8) | b.b) / 16777215.0f;
    return (m.a > 0.03f) && (m.a < 0.1f);
}

// Ice that the picture shows here: a decal is drawn into the mask without the depth test it gets in the game, so it
// counts only where it lies on the 3D world's own surface at this pixel.
bool IceAt(int2 pixel, float sceneDepth, out float depth) {
    if (!LoadIce(pixel, depth)) {
        return false;
    }
    // On the surface, or in front of it: see-through ice (a block round a note) lies over what is behind it.
    const float iceDistance = -ViewPosition(pixel, depth).z;
    const float sceneDistance = -ViewPosition(pixel, sceneDepth).z;
    return (iceDistance - sceneDistance) < (2.0f + sceneDistance * 0.01f);
}

// A shiny surface in the mask (waterMask 5: metal and tiles, SetSceneShinyTextures), for screen-space reflections.
bool LoadShiny(int2 pixel) {
    pixel = clamp(pixel, int2(0, 0), int2(gConstants.projection.zw) - 1);
#ifdef MULTISAMPLING
    const float4 m = gWater.Load(pixel, 0);
#else
    const float4 m = gWater.Load(int3(pixel, 0));
#endif
    return (m.a > 0.008f) && (m.a < 0.03f);
}

// A character or other model in the mask (waterMask 6), for Toon shading's characters: the mask's kind of
// 1 / 255, below every other kind.
bool LoadCharacter(int2 pixel) {
    pixel = clamp(pixel, int2(0, 0), int2(gConstants.projection.zw) - 1);
#ifdef MULTISAMPLING
    const float4 m = gWater.Load(pixel, 0);
#else
    const float4 m = gWater.Load(int3(pixel, 0));
#endif
    return (m.a > 0.002f) && (m.a < 0.008f);
}

// Water reflections' strength (0 off, 1 strongest) and Ice reflections' (in steps of 0.01): water.x carries the
// first plus twice the second's hundredths, as the push constants have no room left.
float WaterReflectionStrength() {
    return gConstants.water.x - 2.0f * floor(gConstants.water.x * 0.5f);
}

float IceReflectionStrength() {
    return floor(gConstants.water.x * 0.5f) / 100.0f;
}

// Where screen-space reflections show: shiny surfaces (metal, gold, glass, glazed tiles), and water whose own reflections are off,
// from the water mask (water.y 1 to 2.25 when it was drawn this frame).
bool ReflectiveAt(int2 pixel, float depth) {
    if ((gConstants.water.y < 0.5f) || (gConstants.water.y > 2.9f)) {
        return false;
    }
    if (LoadShiny(pixel)) {
        return true;
    }
    // Ice has Ice reflections of its own, and SSR stays off it.
    float maskDepth;
#ifdef RAY_TRACED
    // Water has its own reflections (Water reflections, traced while ray tracing is on: WaterReflectionMarch), so
    // the screen-space ones stay off it: they started from the bed's depth and normal and came out stretched.
    return false;
#else
    return (WaterReflectionStrength() <= 0.0f) && (gConstants.water.y < 1.5f) && LoadWater(pixel, maskDepth);
#endif
}

// The ice's own facing at a pixel, from its depths in the mask next to it (ice is floors, walls and blocks): the
// neighbour on each side that is nearest in distance, so an edge doesn't bend it. Level when there is no neighbour.
float3 IceNormal(int2 pixel, float3 surface) {
    float3 along[2];
    [unroll] for (int axis = 0; axis < 2; axis++) {
        const int2 step = (axis == 0) ? int2(1, 0) : int2(0, 1);
        float dA, dB;
        const bool a = LoadIce(pixel + step, dA);
        const bool b = LoadIce(pixel - step, dB);
        const float3 pA = ViewPosition(pixel + step, dA) - surface;
        const float3 pB = surface - ViewPosition(pixel - step, dB);
        const float reach = 2.0f + -surface.z * 0.02f;
        const bool useA = a && (abs(pA.z) < reach) && (!b || (abs(pA.z) <= abs(pB.z)) || (abs(pB.z) >= reach));
        const bool useB = b && (abs(pB.z) < reach);
        along[axis] = useA ? pA : (useB ? pB : float3(0.0f, 0.0f, 0.0f));
    }
    const float3 level = normalize(gConstants.worldY.xyz);
    if ((dot(along[0], along[0]) <= 0.0f) || (dot(along[1], along[1]) <= 0.0f)) {
        return level;
    }
    float3 n = cross(along[1], along[0]);
    if (dot(n, n) < 1e-12f) {
        return level;
    }
    n = normalize(n);
    // Facing the camera.
    return (dot(n, -surface) < 0.0f) ? -n : n;
}

// Modern water's steep draws (waterfalls, and the light beams the renderer can't tell from them): their depth,
// from the water mask, where they are marked with a quarter alpha.

bool LoadFall(int2 pixel, out float depth) {
    pixel = clamp(pixel, int2(0, 0), int2(gConstants.projection.zw) - 1);
#ifdef MULTISAMPLING
    const float4 m = gWater.Load(pixel, 0);
#else
    const float4 m = gWater.Load(int3(pixel, 0));
#endif
    const uint3 b = uint3(round(m.rgb * 255.0f));
    depth = float((b.r << 16) | (b.g << 8) | b.b) / 16777215.0f;
    return (m.a > 0.1f) && (m.a < 0.5f);
}

// Anything in the water mask (flat water or a steep draw): its depth. One read of the mask: flat water has alpha 1
// and a steep draw a quarter (never exactly a half, from an 8-bit mask), so both are everything above a tenth.
bool LoadAnyWater(int2 pixel, out float depth) {
    pixel = clamp(pixel, int2(0, 0), int2(gConstants.projection.zw) - 1);
#ifdef MULTISAMPLING
    const float4 m = gWater.Load(pixel, 0);
#else
    const float4 m = gWater.Load(int3(pixel, 0));
#endif
    const uint3 b = uint3(round(m.rgb * 255.0f));
    depth = float((b.r << 16) | (b.g << 8) | b.b) / 16777215.0f;
    return m.a > 0.1f;
}

// How steep the water mask's surface is at a pixel (0 lying flat, 1 upright), in the world.
float SteepAt(int2 pixel) {
    float d, dr, dd, dl, du;
    if (!LoadAnyWater(pixel, d)) {
        return 0.0f;
    }
    const float3 c = ViewPosition(pixel, d);
    const float3 px = LoadAnyWater(pixel + int2(1, 0), dr) ? ViewPosition(pixel + int2(1, 0), dr) - c : (LoadAnyWater(pixel - int2(1, 0), dl) ? c - ViewPosition(pixel - int2(1, 0), dl) : float3(1.0f, 0.0f, 0.0f));
    const float3 py = LoadAnyWater(pixel + int2(0, 1), dd) ? ViewPosition(pixel + int2(0, 1), dd) - c : (LoadAnyWater(pixel - int2(0, 1), du) ? c - ViewPosition(pixel - int2(0, 1), du) : float3(0.0f, 0.0f, 1.0f));
    const float3 n = cross(px, py);
    if (dot(n, n) < 1e-10f) {
        return 0.0f;
    }
    return 1.0f - saturate((abs(dot(normalize(n), normalize(gConstants.worldY.xyz))) - 0.45f) * 4.0f);
}

// How watery a steep draw's colour is round a pixel, 0 to 1: water is bluer than it is red, the light beams
// are warm or white. Averaged over a few pixels so the scrolling texture doesn't decide it. Gives the colour.
float FallWatery(int2 pixel, out float3 tint) {
    const int reach = max(2, int(gConstants.projection.w / 120.0f));
    tint = 0.0f;
    float count = 0.0f;
    [unroll] for (int i = 0; i < 5; i++) {
        const int2 offset = (i == 0) ? int2(0, 0) : (i == 1) ? int2(reach, 0) : (i == 2) ? int2(-reach, 0) : (i == 3) ? int2(0, reach) : int2(0, -reach);
        float d;
        if (LoadAnyWater(pixel + offset, d)) {
            tint += LoadWaterColor(pixel + offset).rgb;
            count += 1.0f;
        }
    }
    tint = (count > 0.0f) ? tint / count : 0.0f;
    return (count > 0.0f) ? saturate((tint.b - tint.r) * 8.0f - 0.1f) : 0.0f;
}

// How much a water pixel reflects (0 to 1): only flat surfaces facing up, lying over something further
// down (so shadows and decals on the ground don't count), fading in from the shore. Gives the surface's
// view-space position and normal.
float WaterAmount(int2 pixel, float sceneDepth, out float3 surface, out float3 normal) {
    float depth;
    surface = 0.0f;
    normal = float3(0.0f, 1.0f, 0.0f);
    if (!LoadWater(pixel, depth)) {
        return 0.0f;
    }
    surface = ViewPosition(pixel, depth);
    float dRight, dDown;
    const bool right = LoadWater(pixel + int2(1, 0), dRight);
    const bool down = LoadWater(pixel + int2(0, 1), dDown);
    float dLeft, dUp;
    const float3 px = right ? ViewPosition(pixel + int2(1, 0), dRight) - surface :
        (LoadWater(pixel - int2(1, 0), dLeft) ? surface - ViewPosition(pixel - int2(1, 0), dLeft) : float3(1.0f, 0.0f, 0.0f));
    const float3 py = down ? ViewPosition(pixel + int2(0, 1), dDown) - surface :
        (LoadWater(pixel - int2(0, 1), dUp) ? surface - ViewPosition(pixel - int2(0, 1), dUp) : float3(0.0f, 0.0f, 1.0f));
    normal = normalize(cross(px, py));
    if (dot(normal, -surface) < 0.0f) {
        normal = -normal;
    }
    // Facing up in the world (not on the screen, so it holds when looking down at water). Streams
    // running downhill count too; waterfalls don't.
    const float flat = saturate((dot(normal, normalize(gConstants.worldY.xyz)) - 0.45f) * 4.0f);
    const float below = (sceneDepth >= 0.99999f) ? 1e6f : -ViewPosition(pixel, sceneDepth).z;
    const float gap = saturate((below - -surface.z - 1.0f) / 6.0f);
    return flat * gap;
}

float WaterNoise(float2 p);

// The waves vary over the water so they never line up in a grid: where a point's waves are taken from is pushed
// about by a slow, broad noise (the crests bend and wander), and each wave train's height swells and fades from
// place to place on its own (some patches calm, some choppy).
float2 WaveWarp(float2 p) {
    return float2(WaterNoise(p / 420.0f) - 0.5f, WaterNoise(p / 420.0f + float2(7.3f, 2.9f)) - 0.5f) * 170.0f +
        float2(WaterNoise(p / 150.0f + float2(3.1f, 5.7f)) - 0.5f, WaterNoise(p / 150.0f + float2(9.2f, 1.4f)) - 0.5f) * 45.0f;
}

float WaveVariation(float2 p, int i) {
    const float n = WaterNoise(p / (260.0f + 110.0f * float(i)) + float2(float(i) * 3.7f, float(i) * 1.9f));
    return 0.3f + 1.2f * n * n * (3.0f - 2.0f * n);
}

// Water waves: four travelling waves over the world's x and z (in the game's units: Banjo is about 150
// tall). Gives the slope along x and z. Waves too small to show at this distance fade out, so far water
// doesn't shimmer.
float2 WaveSlope(float2 p, float t, float footprint) {
    // Mostly one way, like waves pushed by the wind, with a little chop across.
    const float2 dirs[4] = { float2(0.8f, 0.6f), float2(0.6f, 0.8f), float2(0.97f, 0.26f), float2(-0.5f, 0.87f) };
    const float lengths[4] = { 230.0f, 140.0f, 83.0f, 51.0f };
    const float heights[4] = { 1.0f, 0.7f, 0.45f, 0.3f };
    float2 slope = 0.0f;
    const float2 q = p + WaveWarp(p);
    [unroll] for (int i = 0; i < 4; i++) {
        const float k = 6.2831853f / lengths[i];
        // Deep water: speed grows with the square root of the wavelength.
        const float omega = k * sqrt(lengths[i]) * 6.0f;
        const float visible = saturate(lengths[i] / (footprint * 6.0f) - 1.0f);
        const float steepness = 0.2f * heights[i] * visible * WaveVariation(p, i);
        slope += dirs[i] * (steepness * cos(k * dot(dirs[i], q) - omega * t));
    }
    return slope;
}

// Banjo in the water: up to three rings spreading from where he moved or splashed in, a wake trailing behind
// him as he swims, and a small ring bobbing round him, with a little foam where he cuts the water. Only on
// water near his height (rippleX/Z/Age.w are his position), so he must be standing, wading or swimming in it.
// A ring's age carries 4 more for a splash: bigger, faster and longer lasting.
float2 RippleSlope(float2 p, float waterY, float footprint, out float foam) {
    float2 slope = 0.0f;
    foam = 0.0f;
    const float banjoY = gConstants.rippleAge.w;
    if ((banjoY < -1e8f) || (waterY < banjoY - 40.0f) || (waterY > banjoY + 150.0f)) {
        return slope;
    }
    const float t = gConstants.ambientOcclusion.z;
    const float2 banjo = float2(gConstants.rippleX.w, gConstants.rippleZ.w);
    float newest = 1e9f;
    float2 newestAt = banjo;
    [unroll] for (int i = 0; i < 3; i++) {
        const float packed = gConstants.rippleAge[i];
        if (packed < 0.0f) {
            continue;
        }
        const bool splash = packed >= 4.0f;
        const float age = splash ? packed - 4.0f : packed;
        const float2 at = float2(gConstants.rippleX[i], gConstants.rippleZ[i]);
        if (age < newest) {
            newest = age;
            newestAt = at;
        }
        const float life = splash ? 3.5f : 2.5f;
        if (age > life) {
            continue;
        }
        const float wavelength = splash ? 55.0f : 38.0f;
        const float visible = saturate(wavelength / (footprint * 6.0f) - 1.0f);
        const float2 away = p - at;
        const float d = length(away);
        const float x = d - age * (splash ? 170.0f : 110.0f);
        const float fade = 1.0f - age / life;
        const float width = splash ? 70.0f : 45.0f;
        const float band = exp(-(x * x) / (2.0f * width * width));
        slope += (away / max(d, 1.0f)) * ((splash ? 3.0f : 1.5f) * fade * fade * band * visible * cos(6.2831853f * x / wavelength));
        if (splash) {
            foam = max(foam, band * fade * fade * saturate(1.0f - abs(x) / 30.0f));
        }
    }

    // The ring bobbing round him.
    const float2 q = p - banjo;
    const float d = length(q);
    {
        const float wavelength = 26.0f;
        const float visible = saturate(wavelength / (footprint * 6.0f) - 1.0f);
        const float x = d - 30.0f;
        const float band = exp(-(x * x) / (2.0f * 22.0f * 22.0f));
        slope += (q / max(d, 1.0f)) * (0.8f * band * visible * cos(6.2831853f * (d - t * 30.0f) / wavelength));
        foam = max(foam, 0.35f * exp(-(x * x) / (2.0f * 8.0f * 8.0f)));
    }

    // The wake: two arms opening behind him at the 19.5 degrees of a boat's wake, while he is moving (the
    // newest ring was dropped where he was moments ago).
    const float2 moved = banjo - newestAt;
    const float speed = (newest < 0.8f) ? length(moved) / max(newest, 0.1f) : 0.0f;
    if (speed > 20.0f) {
        const float2 ahead = moved / length(moved);
        const float along = -dot(q, ahead);
        if (along > 0.0f) {
            const float2 side = float2(-ahead.y, ahead.x);
            const float across = dot(q, side);
            const float arm = abs(across) - along * 0.354f;
            const float width = 10.0f + along * 0.08f;
            const float wavelength = 30.0f;
            const float visible = saturate(wavelength / (footprint * 6.0f) - 1.0f);
            const float strength = saturate(speed / 150.0f) * exp(-along / 350.0f) * visible;
            const float band = exp(-(arm * arm) / (2.0f * width * width));
            const float2 outward = side * sign(across) - ahead * 0.354f;
            slope += normalize(outward) * (1.6f * strength * band * cos(6.2831853f * (along - arm * 0.5f) / wavelength));
            foam = max(foam, 0.5f * strength * band * saturate(1.0f - along / 120.0f));
        }
    }
    return slope;
}

// The view-space normal of the waves on a water surface (with its flat normal), at a strength.
float3 WaveNormal(float3 surface, float3 normal, float strength, out float foam) {
    const float2 world = float2(dot(surface, gConstants.worldX.xyz) + gConstants.worldX.w, dot(surface, gConstants.worldZ.xyz) + gConstants.worldZ.w);
    const float worldY = dot(surface, gConstants.worldY.xyz) + gConstants.worldY.w;
    // World units one pixel covers here.
    const float footprint = -surface.z * 2.0f / (gConstants.projection.y * gConstants.projection.w);
    // Banjo's rings and wake keep their size whatever the waves' strength.
    const float2 slope = WaveSlope(world, gConstants.ambientOcclusion.z, footprint) * strength +
        RippleSlope(world, worldY, footprint, foam) * max(strength, 0.6f);
    const float3 alongX = normalize(gConstants.worldX.xyz);
    const float3 alongZ = normalize(gConstants.worldZ.xyz);
    return normalize(normal - alongX * slope.x - alongZ * slope.y);
}

// The reflection off a water pixel: a ray marched across the screen against the scene's depth. What it
// hits is reflected; a ray leaving through the sky reflects the sky; anything else fades out.
float4 WaterReflectionRay(float3 surface, float3 normal, bool bendBack);
float4 WaterReflectionMarch(float3 surface, float3 r, float nearest, out bool hit);

float4 WaterReflection(float3 surface, float3 normal) {
    return WaterReflectionRay(surface, normal, false);
}

// bendBack (ice): a ray heading back past the camera (any view looking down steeper than about 45 degrees, or at a
// wall face on) is bent to run into the picture instead, so ice seen from above still reflects the scenery beyond
// rather than nothing; a little fainter, as it is made up.
float4 WaterReflectionRay(float3 surface, float3 normal, bool bendBack) {
    // Ripples: the normal wobbles with the surface's position and time (the waves bring their own). Not on ice
    // (bendBack), which keeps still: moving ripples made it read as water.
    float3 n = normal;
    if ((gConstants.water.w <= 0.0f) && !bendBack) {
        const float t = gConstants.view.z;
        const float2 ripple = float2(sin(surface.x * 0.05f + t * 1.7f) + sin(surface.z * 0.08f - t * 2.3f),
            sin(surface.z * 0.06f + t * 1.3f) + sin(surface.x * 0.07f + t * 2.9f)) * 0.012f;
        n = normalize(normal + float3(ripple.x, 0.0f, ripple.y));
    }
    const float3 v = normalize(surface);
    float3 r = reflect(v, n);
    float made = 1.0f;
    bool hit;
    // A ray that leaves into the surface rather than off it (a normal facing away from the camera) meets only what is
    // behind it: the surface's own picture shows instead.
    if (dot(r, normal) <= 0.0f) {
        return 0.0f;
    }
#ifdef RAY_TRACED
    // Traced, the true ray finds what is really there (behind the camera too), so ice keeps it rather than bending it
    // into the picture: bent rays copied the scenery on the screen down the ice in smeared stripes (L, 2026-10-21,
    // Waterfall Cavern).
    const bool bend = false;
#else
    const bool bend = bendBack;
#endif
    // Bent in over a band of angles rather than at one (r.z from -0.45 to -0.3): switched at one, the reflection cut
    // off along a straight line across the ice wherever the angle passed it (L, 2026-10-21, Icy Side).
    float4 unbent = 0.0f;
    float bendIn = 1.0f;
    // Only ice that lies roughly level is bent: a ray bent off a wall of ice came back into the picture and copied what
    // stands beside or behind the wall onto it, as if seen through it (L, 2026-10-22, Icy Side). A wall reflects what is
    // really in front of it, or its own picture.
    const float level = dot(normal, normalize(gConstants.worldY.xyz));
    if (bend && (r.z > -0.45f) && (level > 0.6f)) {
        // The true ray first: one heading back towards the camera still meets what stands on the ice (Banjo's front),
        // so he keeps one real reflection under him at every camera height instead of it cutting out past 45 degrees.
        const float4 real = WaterReflectionMarch(surface, r, 0.0f, hit);
        if (hit) {
            return real;
        }
        unbent = real;
        bendIn = smoothstep(-0.45f, -0.3f, r.z) * smoothstep(0.6f, 0.8f, level);
        // Along the picture the way the ray was going (or up the picture, the way level ground runs away, when it
        // came almost straight back), and a fixed way into it.
        float2 across = r.xy;
        if (dot(across, across) < 0.01f) {
            across = gConstants.worldY.xy;
            if (dot(across, across) < 1e-4f) {
                across = float2(0.0f, 1.0f);
            }
        }
        r = normalize(float3(normalize(across), -0.3f));
        made = 0.75f;
    }
#ifndef RAY_TRACED
    if (r.z > 0.0f && surface.z + r.z * 1e4f > -1.0f) {
        // Heading back past the camera.
        return 0.0f;
    }
#endif
    // A bent ray is made up, so it only picks up what lies well beyond the ice: closer things (Banjo, the walls round
    // the ice) would be copied down the picture under themselves, a fresh copy wherever a ray met them again.
    const float nearest = (made < 1.0f) ? max(-surface.z * 2.0f, -surface.z + 800.0f) : 0.0f;
    float4 reflection = WaterReflectionMarch(surface, r, nearest, hit);
    reflection.a *= made;
    return (bendIn < 1.0f) ? lerp(unbent, reflection, bendIn) : reflection;
}

// The reflection along a ray from a surface (view space): see WaterReflection. Things nearer the camera than
// nearest are passed over.
float4 WaterReflectionMarch(float3 surface, float3 r, float nearest, out bool hit) {
    hit = false;
    const float2 size = gConstants.projection.zw;
#ifdef RAY_TRACED
    // Traced (ray queries over the world's triangles, in place of the march): the same reflection, found exactly:
    // what the ray meets, whether or not the depth buffer shows it from here. Rays that must pass over nearer
    // things (ice's bent ones, nearest above 0) still march.
    if (nearest <= 0.0f) {
        const float3 origin = surface + r * 1.0f;
        const float t = TraceDistance(origin, r, 8000.0f);
        if (t >= 0.0f) {
            const float3 hitPoint = origin + r * t;
            if (hitPoint.z < -1.0f) {
                const float2 at = ViewToPixel(hitPoint);
                const float2 inside = clamp(at, float2(0.0f, 0.0f), size - 1.0f);
                const float sampleDepth = LoadDepth(int2(inside));
                const bool inView = all(at == inside) && ((sampleDepth >= 0.99999f) || (ViewZ(sampleDepth) - hitPoint.z <= max(-hitPoint.z * 0.03f, 20.0f)));
                hit = true;
                // What is off the screen or behind something nearer shows faintly, as the march's last resort did, or as it
                // was remembered when last seen (the radiance cache).
                float3 remembered;
                if (!inView && HitColoursOn() && RadianceLoad(ViewToWorldPoint(hitPoint), remembered)) {
                    return float4(remembered, 0.85f);
                }
                if (!inView) {
                    // Off the screen or hidden, with nothing remembered: the colour at the screen's edge is not what is
                    // there (it smeared across ice and water), so the surface's own picture shows instead.
                    return 0.0f;
                }
                // Sampled between pixels: a point load gave every ice pixel that lands on the same scene pixel the same
                // colour, so a close reflection came out in squares (L, 2026-10-21).
                return float4(gColor.SampleLevel(LinearSampler, (inside + 0.5f) / size, 0).rgb, RayEdgeFade(inside));
            }
            // Behind the camera: only as remembered.
            hit = true;
            float3 behind;
            if (HitColoursOn() && RadianceLoad(ViewToWorldPoint(hitPoint), behind)) {
                return float4(behind, 0.85f);
            }
            return 0.0f;
        }
        else {
            // Left the world: the sky in that direction when it shows on the screen, else the horizon's haze.
            const float3 far = surface + r * 50000.0f;
            if (far.z < -1.0f) {
                const float2 skyAt = ViewToPixel(far);
                const float2 skyInside = clamp(skyAt, float2(0.0f, 0.0f), size - 1.0f);
                if (all(skyAt == skyInside) && (LoadDepth(int2(skyInside)) >= 0.99999f)) {
                    return float4(gColor.Load(int3(int2(skyInside), 0)).rgb, RayEdgeFade(skyInside));
                }
            }
            // With no sky anywhere on the screen (a cave), a ray that met nothing went past its reach under a high roof or
            // out through what the game didn't draw this frame (the traced scene is only what it drew), not out to the
            // sky: no reflection, the water's own picture. The haze showed in Terrydactyland's Inside the Mountain as
            // light patches on the pool, shaped by the walkways and moving with the camera (L, 2026-11-10).
            if (!SkyOnScreen()) {
                return 0.0f;
            }
            return float4(gConstants.fogColor.rgb, 0.6f);
        }
    }
#endif
    const float stepLength = max(-surface.z * 0.03f, 4.0f);
    float travelled = 0.0f;
    [loop] for (int i = 1; i <= 32; i++) {
        const float before = travelled;
        travelled += stepLength * (1.0f + float(i) * 0.15f);
        const float3 p = surface + r * travelled;
        if (p.z > -1.0f) {
            break;
        }
        const float2 ndc = float2(p.x * gConstants.projection.x / -p.z, p.y * gConstants.projection.y / -p.z);
        const float2 screen = float2(ndc.x * 0.5f + 0.5f, 0.5f - ndc.y * 0.5f) * size;
        if (any(screen < 0.0f) || any(screen >= size)) {
            break;
        }
        const int2 at = int2(screen);
        const float d = LoadDepth(at);
        const float edge = saturate(min(min(screen.x, size.x - screen.x), min(screen.y, size.y - screen.y)) / (size.y * 0.08f));
        if (d >= 0.99999f) {
            // The sky: keep going while it stays sky, but remember it.
            if (i == 32) {
                return float4(gColor.Load(int3(at, 0)).rgb, edge);
            }
            continue;
        }
        const float sceneZ = -ViewPosition(at, d).z;
        const float behind = -p.z - sceneZ;
        // Hit something, as long as the ray didn't pass far behind it: one that did went behind a thing standing
        // in front (Banjo on the ice), and goes on. Giving it that thing faintly instead put a fresh faded copy of
        // it under itself at each step the rays from further down the surface passed behind it.
        if ((behind > 0.0f) && (behind < stepLength * (2.0f + float(i) * 0.3f)) && (sceneZ >= nearest)) {
            // Narrowed down to where the ray meets it between this step and the last: picked up at the step itself,
            // rays from neighbouring pixels all landed on the same few points, a stepped copy of it for each.
            float near = before;
            float far = travelled;
            int2 found = at;
            float foundBehind = behind;
            [unroll] for (int k = 0; k < 6; k++) {
                const float mid = (near + far) * 0.5f;
                const float3 q = surface + r * mid;
                const float2 qScreen = float2(q.x * gConstants.projection.x / -q.z * 0.5f + 0.5f, 0.5f - q.y * gConstants.projection.y / -q.z * 0.5f) * size;
                const int2 qAt = clamp(int2(qScreen), int2(0, 0), int2(size) - 1);
                const float qd = LoadDepth(qAt);
                const float qBehind = -q.z + ViewPosition(qAt, qd).z;
                if ((qd < 0.99999f) && (qBehind > 0.0f)) {
                    far = mid;
                    found = qAt;
                    foundBehind = qBehind;
                }
                else {
                    near = mid;
                }
            }
            // Where it first gets behind something, the ray should be at its surface: well behind there, it slipped
            // past the edge of a thing in front (Banjo seen from above) rather than meeting it, and goes on.
            if (foundBehind > stepLength * 0.75f) {
                continue;
            }
            hit = true;
            return float4(gColor.Load(int3(found, 0)).rgb, edge);
        }
    }
    // Left the screen: reflect the sky if that's where the ray went.
    const float3 p = surface + r * travelled;
    const float2 ndc = float2(p.x * gConstants.projection.x / max(-p.z, 1.0f), p.y * gConstants.projection.y / max(-p.z, 1.0f));
    const int2 at = clamp(int2(float2(ndc.x * 0.5f + 0.5f, 0.5f - ndc.y * 0.5f) * size), int2(0, 0), int2(size) - 1);
    // Otherwise what's at the screen's edge where it left, faintly, so all of the water reflects something.
    return float4(gColor.Load(int3(at, 0)).rgb, (LoadDepth(at) >= 0.99999f) ? 0.5f : 0.3f);
}

// A world position from a view-space one.
float3 WorldPosition(float3 view) {
    return float3(dot(view, gConstants.worldX.xyz) + gConstants.worldX.w, dot(view, gConstants.worldY.xyz) + gConstants.worldY.w,
        dot(view, gConstants.worldZ.xyz) + gConstants.worldZ.w);
}

// Smooth value noise over the world's x and z, 0 to 1.
float WaterNoise(float2 p) {
    const float2 i = floor(p);
    const float2 f = frac(p);
    const float2 u = f * f * (3.0f - 2.0f * f);
    const float a = frac(sin(dot(i, float2(127.1f, 311.7f))) * 43758.5453f);
    const float b = frac(sin(dot(i + float2(1.0f, 0.0f), float2(127.1f, 311.7f))) * 43758.5453f);
    const float c = frac(sin(dot(i + float2(0.0f, 1.0f), float2(127.1f, 311.7f))) * 43758.5453f);
    const float d = frac(sin(dot(i + float2(1.0f, 1.0f), float2(127.1f, 311.7f))) * 43758.5453f);
    return lerp(lerp(a, b, u.x), lerp(c, d, u.x), u.y);
}

// The water waves' height at a world x and z (as WaveSlope), in world units.
float WaveHeight(float2 p, float t, float footprint) {
    const float2 dirs[4] = { float2(0.8f, 0.6f), float2(0.6f, 0.8f), float2(0.97f, 0.26f), float2(-0.5f, 0.87f) };
    const float lengths[4] = { 230.0f, 140.0f, 83.0f, 51.0f };
    const float heights[4] = { 1.0f, 0.7f, 0.45f, 0.3f };
    float h = 0.0f;
    const float2 q = p + WaveWarp(p);
    [unroll] for (int i = 0; i < 4; i++) {
        const float k = 6.2831853f / lengths[i];
        const float omega = k * sqrt(lengths[i]) * 6.0f;
        const float visible = saturate(lengths[i] / (footprint * 6.0f) - 1.0f);
        h += (0.2f * heights[i] * visible * WaveVariation(p, i) / k) * sin(k * dot(dirs[i], q) - omega * t);
    }
    return h;
}

// Modern water's flags in water.y's eighths over 2 (or 3 with no water drawn): a quarter for Stylised (Graphics > Water
// Stylised), an eighth when the water was drawn tessellated this frame (WaterTess.hlsl).
uint ModernWaterBits() {
    return (gConstants.water.y > 1.5f) ? (uint(round(frac(gConstants.water.y) * 8.0f)) & 3u) : 0u;
}

bool StylisedWaterOn() {
    return (ModernWaterBits() & 2u) != 0u;
}

// Tessellated water: the mask holds the moving surface itself (its swell and the player's rings), so nothing is marched.
bool TessellatedWaterOn() {
    return (ModernWaterBits() & 1u) != 0u;
}

// Modern water's ripples from the player at a world x and z: height (x), slope along x and z (yz) and how
// fast the water moves there (w, for foam). Zero away from the grid, or on water far from the player's height.
float4 Ripples(float2 p, float waterY) {
    const float playerY = gConstants.rippleAge.w;
    // (Tessellated water has its rings in its surface, and no grid.)
    if (TessellatedWaterOn() || (gConstants.rippleX.z < 0.5f) || (playerY < -1e8f) || (waterY < playerY - 60.0f) || (waterY > playerY + 160.0f)) {
        return 0.0f;
    }
    const float cell = gConstants.rippleX.y;
    const float cells = gConstants.rippleZ.y;
    const float2 at = (p - float2(gConstants.rippleX.x, gConstants.rippleZ.x)) / cell;
    if (any(at < 1.0f) || any(at > cells - 1.0f)) {
        return 0.0f;
    }
    const float2 uv = at / cells;
    const float2 texel = 1.0f / cells;
    const float2 c = gWaterRipples.SampleLevel(LinearSampler, uv, 0);
    const float hx = gWaterRipples.SampleLevel(LinearSampler, uv + float2(texel.x, 0.0f), 0).r - gWaterRipples.SampleLevel(LinearSampler, uv - float2(texel.x, 0.0f), 0).r;
    const float hz = gWaterRipples.SampleLevel(LinearSampler, uv + float2(0.0f, texel.y), 0).r - gWaterRipples.SampleLevel(LinearSampler, uv - float2(0.0f, texel.y), 0).r;
    // Kept gentle right where the player pushes (steep slopes there would mirror the sky over their body), and
    // stronger further out, where the wake and rings spread.
    float2 slope = float2(hx, hz) / (2.0f * cell);
    const float fromPlayer = length(p - float2(gConstants.rippleX.w, gConstants.rippleZ.w));
    const float steepest = lerp(0.3f, 0.75f, saturate((fromPlayer - 40.0f) / 40.0f));
    slope *= min(1.0f, steepest / max(length(slope), 1e-4f));
    return float4(clamp(c.r, -14.0f, 14.0f), slope, abs(c.g));
}

// Modern water's surface height above the flat surface at a world x and z (waves and ripples).
float ModernHeight(float2 p, float waterY, float strength, float footprint) {
    return WaveHeight(p, gConstants.ambientOcclusion.z, footprint) * strength + Ripples(p, waterY).x;
}

// Caustics: the bright, wobbling net of light the waves focus onto what is under the water (0 to about 1.5),
// over the world's x and z.
float Caustics(float2 p, float t) {
    float2 q = p / 70.0f;
    float light = 0.0f;
    [unroll] for (int i = 0; i < 3; i++) {
        q += float2(sin(q.y * 1.7f + t * 0.9f + float(i)), cos(q.x * 1.3f - t * 0.7f + float(i) * 1.9f)) * 0.55f;
        light += 1.0f / (1.0f + 14.0f * abs(sin(q.x * 2.3f) + sin(q.y * 2.1f)));
    }
    return saturate(light * 0.75f - 0.2f) * 1.5f;
}

// How strongly caustics light a point under the water: on what faces up, fading with depth below the surface.
float CausticsAt(int2 pixel, float3 view, float depthBelow) {
    if (depthBelow <= 0.0f) {
        return 0.0f;
    }
    const float facing = saturate(dot(ViewNormal(pixel, view), normalize(gConstants.worldY.xyz)) * 1.5f - 0.2f);
    return Caustics(WorldPosition(view).xz, gConstants.ambientOcclusion.z) * facing * exp(-depthBelow / 400.0f) * saturate(depthBelow / 15.0f);
}

// Modern water (Graphics > Water): the game's water isn't drawn, so the scene here is what lies under the
// surface. The water is drawn over it: the floor seen through the surface, bent by the waves and fading into
// the water's own colour with depth (from the game's water colour, so each level keeps its look), the sky
// and scenery reflected more at low angles, the sun's glint, and foam along the shore and round the player.
// Original water with Shore foam on: water.y is 1.25 instead of 1.
bool OriginalShoreFoamOn() {
    return (gConstants.water.y > 1.1f) && (gConstants.water.y < 1.5f);
}

// How level the water mask's surface is at a pixel: the up of its facing in the world (1 lying flat, 0 upright).
float WaterUpAt(int2 pixel) {
    float d, dr, dd, dl, du;
    if (!LoadAnyWater(pixel, d)) {
        return 1.0f;
    }
    const float3 c = ViewPosition(pixel, d);
    const float3 px = LoadAnyWater(pixel + int2(1, 0), dr) ? ViewPosition(pixel + int2(1, 0), dr) - c : (LoadAnyWater(pixel - int2(1, 0), dl) ? c - ViewPosition(pixel - int2(1, 0), dl) : float3(1.0f, 0.0f, 0.0f));
    const float3 py = LoadAnyWater(pixel + int2(0, 1), dd) ? ViewPosition(pixel + int2(0, 1), dd) - c : (LoadAnyWater(pixel - int2(0, 1), du) ? c - ViewPosition(pixel - int2(0, 1), du) : float3(0.0f, 0.0f, 1.0f));
    const float3 n = cross(px, py);
    if (dot(n, n) < 1e-10f) {
        return 1.0f;
    }
    return abs(dot(normalize(n), normalize(gConstants.worldY.xyz)));
}

// Whether the water round a pixel lies level and still (1) or runs down a slope or a waterfall (0): shore foam
// belongs only on level water. Looks a little round the pixel (more above it, where a fall comes down from), so
// the edges of a fall and the white water at its foot get none either.
float OriginalShoreLevel(int2 pixel) {
    const int reach = max(2, int(gConstants.projection.w / 180.0f));
    float level = 1.0f;
    [unroll] for (int i = 0; i < 8; i++) {
        const int2 offset = (i == 0) ? int2(0, 0) : (i == 1) ? int2(reach, 0) : (i == 2) ? int2(-reach, 0) : (i == 3) ? int2(0, reach) :
            int2(0, -reach * (i - 2));
        float d;
        if (LoadFall(pixel + offset, d)) {
            return 0.0f;
        }
        level = min(level, saturate((WaterUpAt(pixel + offset) - 0.88f) / 0.07f));
    }
    return level;
}

// Shore foam on the game's own water (Original): Modern water's broken white line where the floor comes up near the
// surface. The game's water doesn't write depth, so the depth under it is the floor.
float OriginalShoreFoam(int2 pixel, float waterDepth, float sceneDepth) {
    if (sceneDepth >= 0.99999f) {
        return 0.0f;
    }
    const float3 surface = ViewPosition(pixel, waterDepth);
    const float3 surfaceWorld = WorldPosition(surface);
    // From under the water there is no shore: what shows through the surface lies above it (the banks, the sky).
    if (gConstants.worldY.w < surfaceWorld.y) {
        return 0.0f;
    }
    const float below = surfaceWorld.y - WorldPosition(ViewPosition(pixel, sceneDepth)).y;
    if (below < -4.0f) {
        return 0.0f;
    }
    const float floorDepth = max(below, 0.0f);
    const float t = gConstants.ambientOcclusion.z;
    const float2 p = surfaceWorld.xz;
    const float pattern = WaterNoise(p / 18.0f + float2(t * 0.15f, 0.0f)) * 0.6f + WaterNoise(p / 7.0f - float2(0.0f, t * 0.3f)) * 0.4f;
    const float shore = saturate(1.0f - floorDepth / 16.0f);
    const float foam = saturate((shore * 1.2f - (1.0f - pattern)) * 2.5f) * saturate(1.5f - length(surface) / 4000.0f);
    return (foam > 0.0f) ? foam * OriginalShoreLevel(pixel) : 0.0f;
}

// Tessellated water's slope along the world's x and z: the same swell and player's rings as raise its surface
// (WaterTess.hlsli, with the swell's height and rings' as ComputeSceneWater sets them), by differences.
float2 TessellatedSlope(float3 world) {
    const float t = gConstants.ambientOcclusion.z;
    const float swell = 5.0f * gConstants.water.w;
    // (In tessellated water, rippleX.xy hold the player's velocity and rippleZ.x their push: no ripple grid is read.)
    const float4 player = float4(gConstants.rippleX.w, gConstants.rippleZ.w, gConstants.rippleAge.w, gConstants.rippleZ.x);
    const float2 velocity = gConstants.rippleX.xy;
    const float e = 1.5f;
    const float h = WaterTessHeight(world, t, swell, 1.0f, player, velocity, 6.0f);
    const float hx = WaterTessHeight(world + float3(e, 0.0f, 0.0f), t, swell, 1.0f, player, velocity, 6.0f);
    const float hz = WaterTessHeight(world + float3(0.0f, 0.0f, e), t, swell, 1.0f, player, velocity, 6.0f);
    return float2(hx - h, hz - h) / e;
}

// Tessellated water's fine waves: two scrolling normal maps (smooth noise drifting two ways, one turned against the
// other), their slope along the world's x and z by differences. Also gives their height, 0 to 1, for Stylised's crests.
float2 ScrollingNormals(float2 p, float t, float footprint, out float height) {
    const float sizeA = 38.0f;
    const float sizeB = 23.0f;
    const float e = 0.05f;
    const float2 a = p / sizeA + float2(t * 0.06f, t * 0.035f);
    const float2 turned = float2(p.x * 0.8f - p.y * 0.6f, p.x * 0.6f + p.y * 0.8f);
    const float2 b = turned / sizeB - float2(t * 0.05f, -t * 0.07f);
    const float ha = WaterNoise(a);
    const float hb = WaterNoise(b);
    const float2 ga = float2(WaterNoise(a + float2(e, 0.0f)) - ha, WaterNoise(a + float2(0.0f, e)) - ha) / (e * sizeA);
    const float2 gt = float2(WaterNoise(b + float2(e, 0.0f)) - hb, WaterNoise(b + float2(0.0f, e)) - hb) / (e * sizeB);
    // (Back from the turned layer's axes to the world's.)
    const float2 gb = float2(gt.x * 0.8f + gt.y * 0.6f, -gt.x * 0.6f + gt.y * 0.8f);
    // Fading out where they would be smaller than a pixel or two, so far water doesn't shimmer.
    const float visibleA = saturate(sizeA / (footprint * 3.0f) - 1.0f);
    const float visibleB = saturate(sizeB / (footprint * 3.0f) - 1.0f);
    height = ha * 0.65f + hb * 0.35f;
    return ga * (4.0f * visibleA) + gb * (2.2f * visibleB);
}

float3 ModernWater(int2 pixel, float sceneDepth, float3 surface, float3 normal, float3 scene) {
    const float3 v = normalize(surface);
    const float3 up = normalize(gConstants.worldY.xyz);
    // The game's water polygons each tilt a little as they bob, so lighting them by their own facing
    // shows every triangle as a flat block: the surface is lit as level, and only the waves bend it.
    normal = up;
    const float strength = gConstants.water.w;
    const float footprint = -surface.z * 2.0f / (gConstants.projection.y * gConstants.projection.w);
    const float waterY = dot(surface, gConstants.worldY.xyz) + gConstants.worldY.w;

    // The moving surface: the flat surface raised and lowered by the waves and ripples. Where the eye's ray first
    // meets it is found by stepping along the ray through the band they can reach.
    const float band = 9.0f * strength + 14.0f;
    const float along = dot(v, up);
    const bool tessellated = TessellatedWaterOn();
    if (!tessellated && (abs(along) > 0.02f)) {
        const float tFlat = length(surface);
        // From above the band down to below it (along is negative looking down).
        const float tStart = tFlat + band / along;
        const float tEnd = tFlat - band / along;
        float tPrev = tStart;
        float fPrev = band;
        float tHit = tFlat;
        [loop] for (int i = 1; i <= 10; i++) {
            const float t = lerp(tStart, tEnd, float(i) / 10.0f);
            const float3 q = v * t;
            const float3 w = WorldPosition(q);
            const float f = (w.y - waterY) - ModernHeight(w.xz, waterY, strength, footprint);
            if (f <= 0.0f) {
                tHit = lerp(tPrev, t, fPrev / max(fPrev - f, 1e-4f));
                break;
            }
            tPrev = t;
            fPrev = f;
        }
        surface = v * tHit;
    }
    const float distance = -surface.z;

    // The surface's slope: the waves' and the ripples', with a little foam where the ripples move fast.
    // Tessellated: the swell and the player's rings are in the surface itself, and two scrolling normal maps add the
    // fine waves.
    const float3 world = WorldPosition(surface);
    const float4 ripple = tessellated ? 0.0f : Ripples(world.xz, waterY);
    float fineHeight = 0.0f;
    // (Lit by the waves' own slope, not the surface's facing in the mask: the game's water polygons tilt as they bob.)
    const float2 slope = tessellated ? ScrollingNormals(world.xz, gConstants.ambientOcclusion.z, footprint, fineHeight) * strength + TessellatedSlope(world) :
        WaveSlope(world.xz, gConstants.ambientOcclusion.z, footprint) * strength + ripple.yz;
    const float3 n = normalize(normal - normalize(gConstants.worldX.xyz) * slope.x - normalize(gConstants.worldZ.xyz) * slope.y);
    // Not on the player's own spot: the water there is over their body, and foam would paint it white.
    const float awayFromPlayer = saturate((length(world.xz - float2(gConstants.rippleX.w, gConstants.rippleZ.w)) - 30.0f) / 25.0f);
    const float foam = (saturate((ripple.w - 0.3f) * 1.2f) + saturate((length(ripple.yz) - 0.6f) * 0.6f)) * awayFromPlayer;

    // The water's colour: the game's, averaged over a few nearby water pixels so its scrolling texture
    // doesn't show through, and kept fairly saturated so each level's water stays its own colour.
    const int reach = max(2, int(gConstants.projection.w / 90.0f));
    float3 tint = 0.0f;
    float tintWeight = 0.0f;
    [unroll] for (int i = 0; i < 5; i++) {
        const int2 offset = (i == 0) ? int2(0, 0) : (i == 1) ? int2(reach, 0) : (i == 2) ? int2(-reach, 0) : (i == 3) ? int2(0, reach) : int2(0, -reach);
        float d;
        if (LoadWater(pixel + offset, d)) {
            // The game's own white ripple rings and splashes are left out of the water's colour.
            const float3 c = LoadWaterColor(pixel + offset).rgb;
            const float w = saturate((0.7f - dot(c, float3(0.299f, 0.587f, 0.114f))) * 5.0f) + 0.001f;
            tint += c * w;
            tintWeight += w;
        }
    }
    tint = (tintWeight > 0.01f) ? tint / tintWeight : float3(0.2f, 0.4f, 0.5f);
    const float luma = dot(tint, float3(0.299f, 0.587f, 0.114f));
    const float3 hue = saturate(lerp(luma.xxx, tint, 1.35f));
    // Deep water: the game's colour, darker. Shallow water: a clear, slightly coloured lens over the floor.
    const float3 deep = hue * 0.55f + float3(0.01f, 0.03f, 0.05f);
    const float3 shallow = lerp(float3(1.0f, 1.0f, 1.0f), hue / max(max(hue.r, max(hue.g, hue.b)), 0.05f), 0.35f);

    // How much water the eye looks through to the floor, and how deep the water is above it.
    const float3 surfaceWorld = WorldPosition(surface);
    float throughLength = 2000.0f;
    float floorDepth = 2000.0f;
    if (sceneDepth < 0.99999f) {
        const float3 floorView = ViewPosition(pixel, sceneDepth);
        throughLength = max(length(floorView) - length(surface), 0.0f);
        floorDepth = max(surfaceWorld.y - WorldPosition(floorView).y, 0.0f);
    }

    // Refraction: the floor seen through the waves, shifted more where the water is deeper, but only to
    // places that are under the water too (otherwise things in front would bleed into it).
    const float3 bend = n - up;
    const float2 shift = float2(bend.x, -bend.y) * (gConstants.projection.w * 0.05f) * saturate(throughLength / 150.0f) * saturate(800.0f / distance);
    int2 bent = clamp(int2(float2(pixel) + shift), int2(0, 0), int2(gConstants.projection.zw) - 1);
#ifdef RAY_TRACED
    bent = TracedRefractedPixel(surface, n, bent);
#endif
    float3 below = scene;
    float bentWater;
    if (LoadWater(bent, bentWater)) {
        const float bentDepth = LoadDepth(bent);
        if ((bentDepth >= 0.99999f) || (-ViewPosition(bent, bentDepth).z > distance)) {
            below = gColor.Load(int3(bent, 0)).rgb;
        }
    }

    // The waves' light dancing on the floor.
    // Gentler on the player's own body just under the surface, where they whitened the shoulders.
    const float3 surfaceAt = WorldPosition(surface);
    const float clearOfPlayer = (gConstants.rippleAge.w > -1e8f) ? saturate((length(surfaceAt.xz - float2(gConstants.rippleX.w, gConstants.rippleZ.w)) - 50.0f) / 40.0f) : 1.0f;
    if (sceneDepth < 0.99999f) {
        below *= 1.0f + (0.15f + 0.4f * clearOfPlayer) * CausticsAt(pixel, ViewPosition(pixel, sceneDepth), floorDepth);
    }

    // Light fades through the water: red first, then green, so deep water turns the game's colour.
    // Stylised: clearer than real water, so the floor of a pool shows a few hundred units down.
    const float3 absorb = (1.15f - hue) * (1.0f / 450.0f) + 1.0f / 1800.0f;
    const float3 through = exp(-absorb * (throughLength * 0.6f + floorDepth * 0.4f));
    float3 color = lerp(deep, below * shallow, through);

    // Reflections: the sky and scenery, little looking straight down and a lot at a low angle.
    const float facing = saturate(dot(-v, n));
    const float fresnel = 0.04f + 0.96f * pow(1.0f - facing, 5.0f);
    const float4 reflection = WaterReflection(surface, n);
    // Where nothing on screen can be reflected, a pale sky colour stands in.
    const float3 sky = lerp(float3(0.62f, 0.75f, 0.85f), hue * 0.5f + 0.4f, 0.25f);
    const float3 reflected = lerp(sky, reflection.rgb, saturate(reflection.a * 2.0f));
    color = lerp(color, reflected, saturate(0.06f + fresnel * 0.8f));

    // The sun's glint on the wave slopes, sharp up close and broader further away.
    const float3 sun = (gConstants.sun.z < 0.98f) ? gConstants.sun.xyz : normalize(float3(0.3f, 0.8f, -0.5f));
    const float3 r = reflect(v, n);
    const float glint = pow(saturate(dot(r, sun)), 220.0f) * 2.5f + pow(saturate(dot(r, sun)), 24.0f) * 0.12f;
    color += float3(1.0f, 0.96f, 0.88f) * glint * saturate(dot(n, normalize(gConstants.worldY.xyz)) * 2.0f);

    // The shoreline: the water fades out over the last few units, where the floor comes up through it (by the depth
    // buffer), so its edge doesn't cut a hard line.
    color = lerp(scene, color, smoothstep(0.0f, 10.0f, throughLength));

    // Foam: a broken line along the shore (where the floor comes up near the surface), and the player's.
    const float t = gConstants.ambientOcclusion.z;
    const float2 p = surfaceWorld.xz;
    const float pattern = WaterNoise(p / 18.0f + float2(t * 0.15f, 0.0f)) * 0.6f + WaterNoise(p / 7.0f - float2(0.0f, t * 0.3f)) * 0.4f;
    // Not round the player: there the thing just under the surface is their body, not the shore.
    const float nearPlayer = (gConstants.rippleAge.w > -1e8f) ? saturate((length(p - float2(gConstants.rippleX.w, gConstants.rippleZ.w)) - 60.0f) / 30.0f) : 1.0f;
    const float shore = (sceneDepth < 0.99999f) ? saturate(1.0f - floorDepth / 16.0f) * nearPlayer : 0.0f;
    const float shoreFoam = saturate((shore * 1.2f - (1.0f - pattern) * 1.0f) * 2.5f) * saturate(1.5f - distance / 4000.0f);
    // White water where a waterfall comes down into it: a fall just above on screen, near in distance.
    float boil = 0.0f;
    [unroll] for (int k = 1; k <= 3; k++) {
        float fallDepth;
        const int2 above = pixel - int2(0, k * max(2, int(gConstants.projection.w / 60.0f)));
        if (LoadFall(above, fallDepth) || (LoadWater(above, fallDepth) && (SteepAt(above) > 0.5f))) {
            float3 fallTint;
            const float near = saturate(1.0f - abs(-ViewPosition(above, fallDepth).z - distance) / 150.0f);
            boil = max(boil, near * FallWatery(above, fallTint) * (1.0f - 0.25f * float(k - 1)));
        }
    }
    const float boilFoam = saturate(boil * (0.6f + 0.6f * pattern) - 0.15f);
    const float allFoam = saturate(max(max(shoreFoam, foam * (0.15f + 0.45f * pattern)), boilFoam));
    color = lerp(color, float3(0.93f, 0.96f, 0.98f), allFoam * 0.55f);
    return color;
}

// Cellular noise over a plane: the distance to the nearest of a jittered grid of points (x) and to the second
// nearest (y), the points slowly wandering round their cells with t. y - x is small along the cells' edges.
float2 StylisedCells(float2 p, float t) {
    const float2 cell = floor(p);
    const float2 f = frac(p);
    float nearest = 8.0f;
    float second = 8.0f;
    [loop] for (int j = -1; j <= 1; j++) {
        [loop] for (int i = -1; i <= 1; i++) {
            const float2 o = float2(float(i), float(j));
            const float2 h = frac(sin(float2(dot(cell + o, float2(127.1f, 311.7f)), dot(cell + o, float2(269.5f, 183.3f)))) * 43758.5453f);
            const float2 spot = o + 0.5f + 0.4f * sin(t + 6.2831853f * h);
            const float d = length(spot - f);
            second = (d < nearest) ? nearest : min(second, d);
            nearest = min(nearest, d);
        }
    }
    return float2(nearest, second);
}

// Stylised water's waves at a world x and z: height (x) and slope along x and z (yz), in world units. Two equal wave
// trains crossing at right angles make a lattice of crests (the look of the Unity asset's cross lattice), with two
// smaller trains for chop. Each crest is a sine raised to a power and stretched back to the same height, so the
// tops are sharp and the troughs broad, like Gerstner waves.
float3 StylisedWave(float2 p, float t, float footprint) {
    const float2 dirs[4] = { float2(0.83f, 0.56f), float2(-0.56f, 0.83f), float2(0.97f, -0.26f), float2(0.26f, 0.97f) };
    const float lengths[4] = { 190.0f, 175.0f, 70.0f, 47.0f };
    const float heights[4] = { 1.0f, 0.9f, 0.4f, 0.28f };
    const float sharpness = 2.2f;
    float3 wave = 0.0f;
    // (Varied over the water as Modern water's waves are, WaveWarp.)
    const float2 q = p + WaveWarp(p);
    [unroll] for (int i = 0; i < 4; i++) {
        const float k = 6.2831853f / lengths[i];
        const float omega = k * sqrt(lengths[i]) * 6.0f;
        const float visible = saturate(lengths[i] / (footprint * 6.0f) - 1.0f);
        const float amplitude = 0.2f * heights[i] * visible * WaveVariation(p, i) / k;
        const float phase = k * dot(dirs[i], q) - omega * t;
        const float s = sin(phase) * 0.5f + 0.5f;
        const float raised = pow(max(s, 1e-4f), sharpness);
        // Centred on 0 (the mean of s^2.2 is about 0.33), so the water's mean level stays the game's.
        wave.x += amplitude * (2.0f * raised - 0.66f);
        wave.yz += dirs[i] * (amplitude * 2.0f * sharpness * raised / max(s, 1e-4f) * 0.5f * cos(phase) * k);
    }
    return wave;
}

// Stylised water's surface height above the flat surface at a world x and z (waves and ripples).
float StylisedHeight(float2 p, float waterY, float strength, float footprint) {
    return StylisedWave(p, gConstants.ambientOcclusion.z, footprint).x * strength + Ripples(p, waterY).x;
}

// Stylised caustics: a bright net of light along the edges of two layers of wandering cells drifting across each
// other, 0 to about 1.6.
float StylisedCaustics(float2 p, float t) {
    const float2 a = StylisedCells(p / 46.0f + float2(t * 0.05f, t * 0.03f), t * 0.8f);
    const float2 b = StylisedCells(p / 33.0f - float2(t * 0.04f, -t * 0.05f) + 17.0f, t * 0.7f + 2.0f);
    const float lineA = 1.0f - smoothstep(0.02f, 0.16f, a.y - a.x);
    const float lineB = 1.0f - smoothstep(0.02f, 0.16f, b.y - b.x);
    return saturate(lineA * lineB * 1.6f + (lineA + lineB) * 0.3f);
}

// How strongly stylised caustics light a point under the water: everything under the surface, most on what faces up,
// fading with depth below the surface.
float StylisedCausticsAt(int2 pixel, float3 view, float depthBelow) {
    if (depthBelow <= 0.0f) {
        return 0.0f;
    }
    const float facing = 0.35f + 0.65f * saturate(dot(ViewNormal(pixel, view), normalize(gConstants.worldY.xyz)));
    return StylisedCaustics(WorldPosition(view).xz, gConstants.ambientOcclusion.z) * facing * exp(-depthBelow / 300.0f) * saturate(depthBelow / 10.0f);
}

// Stylised foam's pattern at a world x and z, 0 to about 1: three octaves of wandering cells, bright in their middles,
// so a cut through it leaves rounded white blobs and bubbles.
float StylisedFoamNoise(float2 p, float t) {
    float n = 0.0f;
    float amplitude = 0.55f;
    float2 q = p / 30.0f;
    [loop] for (int i = 0; i < 3; i++) {
        const float c = 1.0f - StylisedCells(q, t * (1.0f + 0.4f * float(i))).x;
        n += c * c * amplitude;
        amplitude *= 0.5f;
        q = float2(q.x * 0.88f - q.y * 0.48f, q.x * 0.48f + q.y * 0.88f) * 2.0f + 100.0f;
    }
    return n;
}

// Stylised water: Modern water's surface, reflections, refraction and player ripples with the stylised look of
// UnicornWay's Unity water: sharp crossing crests, a clean shallow-to-deep gradient, crisp white foam with a soft dark
// edge along shores, round anything poking through and in breakers rolling in, cell caustics, a hard sun highlight
// and light glowing through the crests.
float3 StylisedWater(int2 pixel, float sceneDepth, float3 surface, float3 normal, float3 scene) {
    const float3 v = normalize(surface);
    const float3 up = normalize(gConstants.worldY.xyz);
    normal = up;
    const float strength = gConstants.water.w;
    const float footprint = -surface.z * 2.0f / (gConstants.projection.y * gConstants.projection.w);
    const float waterY = dot(surface, gConstants.worldY.xyz) + gConstants.worldY.w;
    const float t = gConstants.ambientOcclusion.z;

    // The moving surface, found as Modern water's is.
    const float band = 12.0f * strength + 14.0f;
    const float along = dot(v, up);
    const bool tessellated = TessellatedWaterOn();
    if (!tessellated && (abs(along) > 0.02f)) {
        const float tFlat = length(surface);
        const float tStart = tFlat + band / along;
        const float tEnd = tFlat - band / along;
        float tPrev = tStart;
        float fPrev = band;
        float tHit = tFlat;
        [loop] for (int i = 1; i <= 10; i++) {
            const float s = lerp(tStart, tEnd, float(i) / 10.0f);
            const float3 w = WorldPosition(v * s);
            const float f = (w.y - waterY) - StylisedHeight(w.xz, waterY, strength, footprint);
            if (f <= 0.0f) {
                tHit = lerp(tPrev, s, fPrev / max(fPrev - f, 1e-4f));
                break;
            }
            tPrev = s;
            fPrev = f;
        }
        surface = v * tHit;
    }
    const float distance = -surface.z;
    const float3 world = WorldPosition(surface);
    const float2 p = world.xz;
    // Tessellated: the swell and the player's rings are in the surface itself, and two scrolling normal maps add the
    // fine waves (and the crests' shading).
    const float4 ripple = tessellated ? 0.0f : Ripples(p, waterY);
    float fineHeight = 0.0f;
    const float3 wave = tessellated ? 0.0f : StylisedWave(p, t, footprint);
    const float2 slope = tessellated ? ScrollingNormals(p, t, footprint, fineHeight) * strength + TessellatedSlope(world) : wave.yz * strength + ripple.yz;
    const float3 n = normalize(normal - normalize(gConstants.worldX.xyz) * slope.x - normalize(gConstants.worldZ.xyz) * slope.y);
    // How high on the waves this point is: 0 in the deepest troughs, about 0.6 on a single crest and 1 where the two
    // big trains' crests meet.
    const float crest = tessellated ? smoothstep(0.2f, 0.85f, fineHeight) : saturate((wave.x + 8.5f) / 25.0f);

    // The level's water colour, as Modern water reads it.
    const int reach = max(2, int(gConstants.projection.w / 90.0f));
    float3 tint = 0.0f;
    float tintWeight = 0.0f;
    [unroll] for (int i = 0; i < 5; i++) {
        const int2 offset = (i == 0) ? int2(0, 0) : (i == 1) ? int2(reach, 0) : (i == 2) ? int2(-reach, 0) : (i == 3) ? int2(0, reach) : int2(0, -reach);
        float d;
        if (LoadWater(pixel + offset, d)) {
            const float3 c = LoadWaterColor(pixel + offset).rgb;
            const float w = saturate((0.7f - dot(c, float3(0.299f, 0.587f, 0.114f))) * 5.0f) + 0.001f;
            tint += c * w;
            tintWeight += w;
        }
    }
    tint = (tintWeight > 0.01f) ? tint / tintWeight : float3(0.2f, 0.45f, 0.55f);
    const float luma = dot(tint, float3(0.299f, 0.587f, 0.114f));
    const float3 hue = saturate(lerp(luma.xxx, tint, 1.6f));
    const float peak = max(max(hue.r, max(hue.g, hue.b)), 0.05f);
    // Two clean colours from it: bright and clear in the shallows (nudged towards cyan), deep and saturated further
    // down (nudged towards blue).
    const float3 shallowColor = saturate(lerp(hue / peak, float3(0.4f, 0.95f, 1.0f), 0.45f));
    const float3 deepColor = saturate(lerp(hue / peak, float3(0.05f, 0.3f, 0.75f), 0.4f) * 0.55f);

    // How deep the water is under this point and how much of it the eye looks through.
    float throughLength = 2000.0f;
    float floorDepth = 2000.0f;
    if (sceneDepth < 0.99999f) {
        const float3 floorView = ViewPosition(pixel, sceneDepth);
        throughLength = max(length(floorView) - length(surface), 0.0f);
        floorDepth = max(world.y - WorldPosition(floorView).y, 0.0f);
    }

    // Refraction, guarded as Modern water's: only from places that are under the water too.
    const float3 bend = n - up;
    const float2 shift = float2(bend.x, -bend.y) * (gConstants.projection.w * 0.06f) * saturate(throughLength / 120.0f) * saturate(800.0f / distance);
    int2 bent = clamp(int2(float2(pixel) + shift), int2(0, 0), int2(gConstants.projection.zw) - 1);
#ifdef RAY_TRACED
    bent = TracedRefractedPixel(surface, n, bent);
#endif
    float3 below = scene;
    float bentWater;
    if (LoadWater(bent, bentWater)) {
        const float bentDepth = LoadDepth(bent);
        if ((bentDepth >= 0.99999f) || (-ViewPosition(bent, bentDepth).z > distance)) {
            below = gColor.Load(int3(bent, 0)).rgb;
        }
    }

    // Caustics on what lies under the water (not on the player's body just under the surface).
    const float2 playerAt = float2(gConstants.rippleX.w, gConstants.rippleZ.w);
    const bool havePlayer = gConstants.rippleAge.w > -1e8f;
    const float fromPlayer = havePlayer ? length(p - playerAt) : 1e4f;
    if (sceneDepth < 0.99999f) {
        below *= 1.0f + (0.25f + 0.55f * saturate((fromPlayer - 45.0f) / 35.0f)) * StylisedCausticsAt(pixel, ViewPosition(pixel, sceneDepth), floorDepth);
    }

    // The gradient: the floor through a clear tint in the shallows, fading into the deep colour by how deep the water
    // is and how far the eye looks through it. Red goes first, so deep water turns towards blue-green.
    const float depthRatio = smoothstep(4.0f, 260.0f, floorDepth * 0.7f + throughLength * 0.3f);
    const float3 volume = lerp(shallowColor, deepColor, depthRatio);
    const float3 absorb = float3(0.3f, 0.07f, 0.03f) / 90.0f + (1.0f - hue / peak) * (1.0f / 600.0f);
    const float3 through = exp(-absorb * (throughLength * 0.6f + floorDepth * 0.4f));
    float3 color = lerp(deepColor, below * lerp(float3(1.0f, 1.0f, 1.0f), volume, 0.6f), through);
    color = lerp(color, volume, depthRatio * 0.35f);

    // Light through the crests, from behind them: brighter, cleaner water on the tops.
    const float3 sun = (gConstants.sun.z < 0.98f) ? gConstants.sun.xyz : normalize(float3(0.3f, 0.8f, -0.5f));
    const float backlit = 0.35f + 0.65f * saturate(dot(v, sun) * 0.5f + 0.5f);
    color += shallowColor * (0.18f * crest * crest * backlit * saturate(depthRatio * 3.0f));
    // The stylised gradient over the waves too: crests a lighter shade of the water, troughs a deeper one.
    color = lerp(color, (crest > 0.5f) ? shallowColor : deepColor, abs(crest - 0.5f) * 0.4f * saturate(strength * 2.0f));

    // Reflections, as Modern water's.
    const float facing = saturate(dot(-v, n));
    const float fresnel = 0.04f + 0.96f * pow(1.0f - facing, 5.0f);
    const float4 reflection = WaterReflection(surface, n);
    const float3 sky = lerp(float3(0.62f, 0.78f, 0.9f), shallowColor, 0.2f);
    const float3 reflected = lerp(sky, reflection.rgb, saturate(reflection.a * 2.0f));
    color = lerp(color, reflected, saturate(0.05f + fresnel * 0.75f));

    // The sun: a hard-edged highlight with a soft halo.
    const float3 r = reflect(v, n);
    const float toSun = saturate(dot(r, sun));
    const float highlight = smoothstep(0.9965f, 0.9985f, toSun) * 1.4f + pow(toSun, 40.0f) * 0.15f;
    color += float3(1.0f, 0.97f, 0.9f) * highlight * saturate(dot(n, up) * 2.0f);

    // The shoreline: faded out over the last few units, as Modern water's (the foam still draws over it).
    color = lerp(scene, color, smoothstep(0.0f, 10.0f, throughLength));

    // Foam. Where it may show (level): along the shore and round anything poking through the surface, by how much
    // water lies between the surface and what is under it; on the tallest crests; in the player's wake; and in
    // breakers rolling in through the shallows towards the shore.
    const float fine = saturate(1.6f - distance / 3500.0f);
    const float shallow = (sceneDepth < 0.99999f) ? min(floorDepth, throughLength * 0.5f) : 2000.0f;
    // Not on the player: the water there is over their body, not the shore. Instead a ring of foam round them,
    // where they cut the water, while they are in it.
    // (Their arms and pack spread a good way out just under the surface, so the shore's reach is kept well off.)
    const float clearOfPlayer = saturate((fromPlayer - 70.0f) / 15.0f);
    const float playerY = gConstants.rippleAge.w;
    const bool playerIn = havePlayer && (gConstants.rippleX.z > 0.5f) && (waterY > playerY - 60.0f) && (waterY < playerY + 160.0f);
    // Only over open water: where their body lies just under the surface the ring would paint it white.
    const float ring = playerIn ? smoothstep(38.0f, 46.0f, fromPlayer) * (1.0f - smoothstep(52.0f, 72.0f, fromPlayer)) * smoothstep(25.0f, 45.0f, shallow) : 0.0f;
    const float shore = (1.0f - smoothstep(0.0f, 34.0f, shallow)) * clearOfPlayer;
    const float breakerPhase = frac(floorDepth / 26.0f + t * 0.35f);
    const float breakers = (1.0f - smoothstep(0.0f, 0.12f, breakerPhase)) * smoothstep(80.0f, 30.0f, floorDepth) * smoothstep(8.0f, 20.0f, floorDepth) * clearOfPlayer;
    const float crestFoam = smoothstep(0.75f, 0.95f, crest) * saturate(strength * 1.5f);
    const float wake = saturate((ripple.w - 0.25f) * 1.5f) + saturate((length(ripple.yz) - 0.5f) * 0.8f);
    const float level = saturate(shore * 1.15f + breakers * 0.8f + crestFoam * 0.55f + wake * clearOfPlayer * 0.7f + ring * 0.85f);
    // The pattern, cut sharply: white where pattern and level together pass the cut, and a dark edge just outside it.
    const float2 drift = float2(t * 0.9f, t * 0.6f);
    const float pattern = StylisedFoamNoise(p + drift, t * 0.6f);
    // Solid only right at the shore; further out the pattern breaks it into blobs and bubbles.
    const float cut = 1.0f;
    const float foam = smoothstep(cut, cut + 0.05f, pattern + level * 0.75f) * fine;
    const float edgePattern = StylisedFoamNoise(p + drift + float2(2.5f, 2.5f), t * 0.6f);
    const float edge = saturate(smoothstep(cut - 0.12f, cut - 0.02f, edgePattern + level * 0.75f) - foam) * fine;
    color = lerp(color, deepColor * 0.6f, edge * 0.35f);
    color = lerp(color, float3(0.96f, 0.98f, 1.0f), foam * 0.92f);
    return color;
}

// Modern water's waterfalls: the game's own fall (its texture keeps scrolling as the game moves it), drawn a little
// thicker, with soft streaks of white water pouring down over it, sparkles where the sun catches it, and mist
// gathering at its foot where it lands in flat water. Everything is laid out in the world (across the fall as the
// camera sees it, and down it by height), so it stays put on the fall as the camera moves and never shows the
// game's triangles. All of it moves on the effects' own clock, smoothly at any frame rate.
float3 ModernFall(int2 pixel, float fallDepth, float3 original, float4 game) {
    const float3 surface = ViewPosition(pixel, fallDepth);
    const float distance = length(surface);
    const float3 world = WorldPosition(surface);
    // Across the fall: the camera's right, flattened onto the ground.
    float2 across = float2(gConstants.worldX.x, gConstants.worldZ.x);
    across = (dot(across, across) > 1e-6f) ? normalize(across) : float2(1.0f, 0.0f);
    const float u = dot(world.xz, across);
    const float t = gConstants.ambientOcclusion.z;
    // Finer detail fades out with distance, where it would shimmer.
    const float fine = saturate(1.0f - distance / 1800.0f);

    // Streaks: broad bands pouring down slowly and narrow ones faster, soft-edged.
    const float broad = WaterNoise(float2(u / 7.0f, world.y / 55.0f + t * 1.6f));
    const float narrow = WaterNoise(float2(u / 2.6f, world.y / 22.0f + t * 3.2f));
    const float streak = lerp(broad, broad * 0.55f + narrow * 0.45f, fine);
    const float white = smoothstep(0.5f, 0.9f, streak);

    // The fall's body: the game's, a little thicker, shaded along the streaks.
    float3 color = lerp(original, game.rgb, 0.3f * saturate(game.a + 0.3f));
    color *= 0.86f + 0.28f * streak;
    color = lerp(color, float3(0.9f, 0.94f, 0.98f), white * 0.4f);

    // Sparkles where the sun catches the falling water.
    const float3 sun = (gConstants.sun.z < 0.98f) ? gConstants.sun.xyz : normalize(float3(0.3f, 0.8f, -0.5f));
    const float sunUp = saturate(dot(sun, normalize(gConstants.worldY.xyz)) + 0.3f);
    const float glitter = pow(WaterNoise(float2(u / 1.4f, world.y / 5.0f + t * 5.0f)), 14.0f) * fine;
    color += float3(1.0f, 0.98f, 0.92f) * glitter * 1.6f * sunUp;

    // Mist at the foot: flat water a little below on screen, close in distance.
    float foot = 0.0f;
    const int step = max(2, int(gConstants.projection.w / 70.0f));
    [unroll] for (int k = 1; k <= 4; k++) {
        float d;
        const int2 below = pixel + int2(0, k * step);
        if (LoadWater(below, d) && (SteepAt(below) < 0.5f)) {
            const float near = saturate(1.0f - abs(length(ViewPosition(below, d)) - distance) / 120.0f);
            foot = max(foot, near * (1.0f - 0.2f * float(k - 1)));
        }
    }
    const float mist = foot * (0.55f + 0.45f * WaterNoise(float2(u / 10.0f, world.y / 14.0f - t * 0.8f)));
    color = lerp(color, float3(0.88f, 0.92f, 0.95f), saturate(mist) * 0.6f);
    return saturate(color);
}

// Modern water's surface seen from under it: straight up, a bright window onto the world above, bent by the
// waves; further out the surface mirrors the water below (total internal reflection), dark in its colour.
float3 ModernWaterBelow(int2 pixel, float3 surface, float3 normal, float3 scene) {
    const float3 v = normalize(surface);
    const float footprint = -surface.z * 2.0f / (gConstants.projection.y * gConstants.projection.w);
    const float3 world = WorldPosition(surface);
    const float waterY = world.y;
    const float4 ripple = Ripples(world.xz, waterY);
    const float2 slope = WaveSlope(world.xz, gConstants.ambientOcclusion.z, footprint) * gConstants.water.w + ripple.yz;
    const float3 n = normalize(normal + normalize(gConstants.worldX.xyz) * slope.x + normalize(gConstants.worldZ.xyz) * slope.y);

    // The water's colour, as from above.
    const float3 tint = LoadWaterColor(pixel).rgb;
    const float luma = dot(tint, float3(0.299f, 0.587f, 0.114f));
    const float3 hue = saturate(lerp(luma.xxx, tint, 1.35f));
    const float3 deep = hue * 0.45f + float3(0.02f, 0.05f, 0.08f);

    // The world above, through the window, bent strongly by the waves.
    const float3 bend = n - normal;
    const int2 bent = clamp(int2(float2(pixel) + float2(bend.x, -bend.y) * gConstants.projection.w * 0.12f), int2(0, 0), int2(gConstants.projection.zw) - 1);
    float bentWater;
    const float3 above = LoadWater(bent, bentWater) ? gColor.Load(int3(bent, 0)).rgb : scene;
    const float facing = saturate(dot(-v, n));
    // Snell's window: about 49 degrees either side of straight up.
    const float window = smoothstep(0.6f, 0.72f, facing);
    // Outside it, the water below is mirrored.
    const float4 mirrored = WaterReflection(surface, n);
    const float3 inside = lerp(deep, mirrored.rgb * lerp(1.0f.xxx, hue, 0.4f), mirrored.a * 0.6f);
    return lerp(inside, above * lerp(1.0f.xxx, hue * 1.4f, 0.25f) * 1.1f, window);
}

// Lens flare by day: soft rings along the line from the sun through the middle of the screen, while the sun
// is on screen and the sky shows where it is.
float3 DayFlare(int2 pixel, float3 tint) {
    const float3 sun = gConstants.sun.xyz;
    if ((gConstants.shadows.z <= 0.0f) || (sun.z > -0.05f)) {
        return 0.0f;
    }
    const float day = 1.0f - DayNight(tint);
    if (day <= 0.0f) {
        return 0.0f;
    }
    const float2 size = gConstants.projection.zw;
    const float2 ndc = float2(sun.x * gConstants.projection.x / -sun.z, sun.y * gConstants.projection.y / -sun.z);
    const float2 sunScreen = float2(ndc.x * 0.5f + 0.5f, 0.5f - ndc.y * 0.5f) * size;
    if (any(sunScreen < 0.0f) || any(sunScreen >= size)) {
        return 0.0f;
    }
    // How much of the sun is in clear sky: five taps round it.
    const float spread = size.y * 0.006f;
    float clear = 0.0f;
    [unroll] for (int i = 0; i < 5; i++) {
        const float2 offset = (i == 0) ? float2(0.0f, 0.0f) : (i == 1) ? float2(spread, 0.0f) : (i == 2) ? float2(-spread, 0.0f) : (i == 3) ? float2(0.0f, spread) : float2(0.0f, -spread);
        clear += (LoadDepth(int2(sunScreen + offset)) >= 0.99999f) ? 0.2f : 0.0f;
    }
    // Weaker as the sun nears the edge of the screen.
    const float2 fromMiddle = (sunScreen - size * 0.5f) / (size * 0.5f);
    const float edge = saturate(1.6f - length(fromMiddle));
    const float strength = clear * edge * day;
    if (strength <= 0.0f) {
        return 0.0f;
    }
    const float glow = saturate((tint.r - tint.b) * 2.2f);
    const float2 axis = size * 0.5f - sunScreen;
    float3 flare = 0.0f;
    // Rings: where along the line (0 the sun, 1 the middle, 2 the far side) and size (screen heights), then colour.
    const float2 rings[5] = { float2(0.45f, 0.035f), float2(0.8f, 0.07f), float2(1.2f, 0.025f), float2(1.55f, 0.1f), float2(1.9f, 0.05f) };
    const float3 colours[5] = { float3(1.0f, 0.85f, 0.6f), float3(0.5f, 0.8f, 1.0f), float3(1.0f, 0.6f, 0.9f), float3(0.6f, 1.0f, 0.7f), float3(1.0f, 0.75f, 0.5f) };
    [unroll] for (int r = 0; r < 5; r++) {
        const float2 centre = sunScreen + axis * rings[r].x;
        const float radius = rings[r].y * size.y;
        const float d = length(float2(pixel) + 0.5f - centre) / radius;
        // A soft disc with a slightly brighter rim.
        const float ring = saturate(1.0f - d) * 0.6f + saturate(1.0f - abs(d - 0.9f) * 8.0f) * 0.4f;
        flare += lerp(colours[r], float3(1.0f, 0.6f, 0.3f), glow * 0.5f) * ring;
    }
    // A faint glare spread round the sun over the scenery too.
    const float glare = saturate(1.0f - length(float2(pixel) - sunScreen) / (size.y * 0.35f));
    return (flare * 0.45f + float3(1.0f, 0.9f, 0.75f) * (glare * glare * 0.4f)) * strength;
}

// Rain landing: small rings splashing up and spreading on level ground, at random spots fixed in the world, each
// spot splashing again and again at its own pace, and fewer far off. On water (from the water mask) the rings
// are wider and slower, two at a time spreading over the surface, with no splash in the middle.
float3 DayRainSplashes(int2 pixel, float depth, float3 tint, float rain) {
    if ((rain <= 0.0f) || (depth >= 0.99999f) || DaySnow()) {
        return 0.0f;
    }
    float waterDepth;
    const bool onWater = (gConstants.water.y > 0.5f) && (gConstants.fog.w <= 0.0f) && LoadWater(pixel, waterDepth);
    const float3 center = ViewPosition(pixel, onWater ? waterDepth : depth);
    // Level ground, and level water (not waterfalls).
    const float level = saturate((dot(ViewNormal(pixel, center), normalize(gConstants.worldY.xyz)) - 0.75f) * 6.0f);
    if (level <= 0.0f) {
        return 0.0f;
    }
    const float scale = length(gConstants.worldX.xyz);
    const float distance = length(center) * scale;
    // Out to about Banjo's surroundings and well past them: splashes far off shrink to small flecks, so they thin
    // out gently instead of stopping a little way in front of the camera.
    const float fade = 1.0f - (onWater ? smoothstep(1400.0f, 3000.0f, distance) : smoothstep(1000.0f, 2400.0f, distance));
    if (fade <= 0.0f) {
        return 0.0f;
    }
    const float2 world = float2(dot(center, gConstants.worldX.xyz) + gConstants.worldX.w, dot(center, gConstants.worldZ.xyz) + gConstants.worldZ.w);
    const float pixelSize = distance * 2.0f / (gConstants.projection.y * gConstants.projection.w);
    const float time = gConstants.view.z;
    const float Cell = onWater ? 24.0f : 11.0f;
    const float life = onWater ? 0.7f : 0.25f;
    float total = 0.0f;
    [unroll]
    for (int layer = 0; layer < 3; layer++) {
        const float2 p = world / Cell + float2(0.37f, 0.61f) * float(layer);
        const float2 cell = floor(p);
        const float3 seed = float3(cell, 4.0f + float(layer) * 9.0f);
        if (DayHash(seed) > rain) {
            continue;
        }
        // A splash every half second to second (a little slower on water), lasting a quarter of a second (on
        // water, the rings spread for most of a second).
        const float period = (0.5f + 0.5f * DayHash(seed + 3.0f)) * (onWater ? 1.6f : 1.0f);
        const float age = frac(time / period + DayHash(seed + 5.0f)) * period;
        if (age > life) {
            continue;
        }
        const float2 spot = (cell + 0.3f + 0.4f * float2(DayHash(seed + 7.0f), DayHash(seed + 9.0f)) - float2(0.37f, 0.61f) * float(layer)) * Cell;
        const float x = age / life;
        const float width = max(0.5f, pixelSize);
        const float across = length(world - spot);
        if (onWater) {
            const float outer = 0.8f + 7.5f * sqrt(x);
            const float inner = outer * 0.55f;
            const float soft = width * 1.6f;
            const float ring = saturate(1.0f - abs(across - outer) / soft) + 0.5f * saturate(1.0f - abs(across - inner) / soft) * step(0.15f, x);
            total += ring * min(1.0f, 0.5f / width) * 0.3f * (1.0f - x) * (1.0f - x);
        }
        else {
            const float ringRadius = 0.6f + 3.4f * sqrt(x);
            const float ring = saturate(1.0f - abs(across - ringRadius) / width) * min(1.0f, 0.5f / width);
            // A bright drop at the middle as it lands.
            const float hit = saturate(1.0f - across / max(0.8f, pixelSize)) * saturate(1.0f - x * 4.0f);
            total += (ring * 0.6f + hit * 0.8f) * (1.0f - x);
        }
    }
    // Far off a splash is a pixel or two: dimmer there, so the ground doesn't flicker.
    total *= saturate(1.5f / pixelSize);
    // Lit like what they land on: a brighter, paler copy of the surface's own colour, so splashes in shade stay
    // faint and those on bright ground or water catch the light.
    const float3 surface = gColor.Load(int3(pixel, 0)).rgb * tint;
    const float3 color = lerp(surface, dot(surface, float3(0.3f, 0.59f, 0.11f)).xxx, 0.5f) * 1.6f + float3(0.75f, 0.8f, 0.88f) * 0.2f * max(tint.r, max(tint.g, tint.b));
    return color * total * level * fade * saturate(rain * 1.5f) * (onWater ? 1.6f : 1.0f);
}

// Rain: streaks falling on four rings round the camera (fixed to the compass, so they stay put as it turns),
// each hidden behind whatever is nearer than its ring. Nearer rings have bigger, brighter, sparser drops.
float3 DayRain(int2 pixel, float depth, float3 tint, float rain) {
    if (rain <= 0.0f) {
        return 0.0f;
    }
    const float2 ndc = float2((pixel.x + 0.5f) / gConstants.projection.z * 2.0f - 1.0f, 1.0f - (pixel.y + 0.5f) / gConstants.projection.w * 2.0f);
    const float3 look = normalize(float3(ndc.x / gConstants.projection.x, ndc.y / gConstants.projection.y, -1.0f));
    const float3 world = normalize(float3(dot(look, gConstants.worldX.xyz), dot(look, gConstants.worldY.xyz), dot(look, gConstants.worldZ.xyz)));
    const float across = length(world.xz);
    if (across < 0.08f) {
        return 0.0f;
    }
    // How far the scene is along this ray, in world units (view units times the view-to-world scale).
    const float scale = length(gConstants.worldX.xyz);
    const float scene = (depth >= 0.99999f) ? 1e9f : length(ViewPosition(pixel, depth)) * scale;
    // A pixel's size at a distance of 1, for keeping thin drops from flickering.
    const float pixelSize = 2.0f / (gConstants.projection.y * gConstants.projection.w);
    const float angle = atan2(world.z, world.x);
    const float time = gConstants.view.z;
    const float3 color = float3(0.62f, 0.66f, 0.74f) * (0.3f + 0.7f * max(tint.r, max(tint.g, tint.b)));
    float total = 0.0f;
    if (DaySnow()) {
        // Snow: soft flakes drifting down slowly, swaying from side to side.
        [unroll]
        for (int i = 0; i < 4; i++) {
            const float radius = 70.0f * pow(2.0f, float(i));
            const float distance = radius / across;
            if (distance > scene) {
                continue;
            }
            const float width = 16.0f + 8.0f * float(i);
            const float height = 30.0f + 12.0f * float(i);
            const float up = world.y / across * radius;
            const float around = angle * radius / width;
            const float column = floor(around);
            const float offset = DayHash(float3(column, float(i) * 7.0f, 11.0f));
            const float fall = (up + time * (45.0f + 30.0f * offset)) / height + offset * 5.0f;
            const float row = floor(fall);
            const float pick = DayHash(float3(column, row, float(i) * 3.0f + 1.0f));
            if (pick > saturate(rain * 1.4f) * 0.9f) {
                continue;
            }
            const float x0 = 0.25f + 0.5f * DayHash(float3(column, row, float(i) + 5.0f));
            const float sway = sin(time * (0.8f + offset) + pick * 30.0f) * 0.18f;
            const float dx = (frac(around) - x0 - sway) * width;
            const float dy = (frac(fall) - 0.5f) * height;
            const float size = 0.9f + 0.5f * float(i);
            const float footprint = max(size, distance * pixelSize * 1.5f);
            const float flake = saturate(1.0f - length(float2(dx, dy)) / footprint) * min(1.0f, (size * size) / (footprint * footprint));
            total += flake * (1.1f - 0.15f * float(i));
        }
        return float3(0.9f, 0.92f, 0.96f) * (0.3f + 0.7f * max(tint.r, max(tint.g, tint.b))) * total * saturate(rain * 1.5f);
    }
    [unroll]
    for (int i = 0; i < 4; i++) {
        const float radius = 90.0f * pow(2.2f, float(i));
        const float distance = radius / across;
        if (distance > scene) {
            continue;
        }
        const float width = 9.0f + 5.0f * float(i);
        const float height = 150.0f;
        // Where on the ring (around and up), in cells, leaning a little with the wind.
        const float up = world.y / across * radius;
        const float around = angle * radius / width + up * 0.08f / width;
        const float column = floor(around);
        const float pick = DayHash(float3(column, float(i) * 7.0f, 3.0f));
        if (pick > rain * 0.85f) {
            continue;
        }
        const float offset = DayHash(float3(column, float(i) * 7.0f, 11.0f));
        const float speed = 900.0f + 300.0f * offset;
        const float fall = (up + time * speed) / height + offset * 5.0f;
        const float along = frac(fall);
        // The drop's top part of its cell, brightest at its leading (lower) end.
        const float streak = smoothstep(0.55f, 0.95f, along) * (1.0f - smoothstep(0.95f, 1.0f, along));
        const float x = abs(frac(around) - (0.2f + 0.6f * DayHash(float3(column, floor(fall), float(i)))) ) * width;
        const float drop = 0.4f + 0.2f * float(i);
        const float footprint = max(drop, distance * pixelSize);
        const float stroke = saturate(1.0f - x / footprint) * (drop / footprint);
        total += stroke * streak * (0.36f - 0.06f * float(i));
    }
    return color * total * rain;
}

// How much of the morning it is: the sun low in the east (0 to 1), not at night or in the rain.
float DayMorning(float3 tint) {
    const float3 sunWorld = normalize(float3(dot(gConstants.sun.xyz, gConstants.worldX.xyz), dot(gConstants.sun.xyz, gConstants.worldY.xyz), dot(gConstants.sun.xyz, gConstants.worldZ.xyz)));
    return saturate(sunWorld.x * 2.0f) * (1.0f - smoothstep(0.35f, 0.75f, sunWorld.y)) * smoothstep(-0.05f, 0.08f, sunWorld.y) *
        (1.0f - DayNight(tint)) * (1.0f - DayWeather().x);
}

// The rain settings, from the sun shadows' constant (shadows.w = 4 * (512 * wet (0 to 31) + 16384 for raindrops) +
// 2 to leave Banjo out + softness; the first 9 bits once held the removed mist): x and y unused (0), z how wet the ground is (0 to 1), w 1 for raindrops on the
// screen.
float4 DayMistAndRain() {
    float packed = floor(gConstants.shadows.w / 4.0f);
    const float drops = (packed >= 16384.0f) ? 1.0f : 0.0f;
    packed -= drops * 16384.0f;
    const float wet = floor(packed / 512.0f);
    packed -= wet * 512.0f;
    const float when = floor(packed / 128.0f);
    return float4((packed - when * 128.0f) / 100.0f, when, wet / 31.0f, drops);
}

// Wet ground in and after the rain: everything darkens a little, and what faces up darkens more, in patches
// fixed to the ground. Not on Banjo himself, nor on the water.
float3 DayWet(float3 scene, int2 pixel, float depth) {
    const float wet = DayMistAndRain().z;
    if ((wet <= 0.0f) || (depth >= 0.99999f) || (gConstants.fog.w > 0.0f)) {
        return scene;
    }
    float waterDepth;
    if ((gConstants.water.y > 0.5f) && LoadWater(pixel, waterDepth)) {
        return scene;
    }
    const float3 center = ViewPosition(pixel, depth);
    const float3 world = WorldPosition(center);
    if (gConstants.rippleAge.w > -1e8f) {
        const float across = length(world.xz - float2(gConstants.rippleX.w, gConstants.rippleZ.w));
        const float up = world.y - gConstants.rippleAge.w;
        if ((across < 45.0f) && (up > 3.0f) && (up < 140.0f)) {
            return scene;
        }
    }
    const float3 normal = ViewNormal(pixel, center);
    const float level = saturate((dot(normal, normalize(gConstants.worldY.xyz)) - 0.55f) * 4.0f);
    // Wet patches and drier ones, fixed to the ground.
    const float patches = 0.55f + 0.45f * smoothstep(0.25f, 0.7f, WaterNoise(world.xz / 90.0f));
    // No reflection: L wants only water and Icy Side's ice to reflect (2026-10-17), so wet grass and dirt only darken.
    return scene * (1.0f - wet * (0.12f + 0.2f * level * patches));
}

// WIP volumetric mist, fog and clouds (Graphics options in the WIP tab, all off by default; src/gameplay/volumetric.cpp).
// The settings ride in the 12 bits above the fog's start (fog.y) and length (fog.z), which hold those in steps of 4 units
// in their low 12 bits: fog.y mist (6 bits, 0 to 63) and fog (6); fog.z the fog's preset (3), the forced cloud type (3,
// 0 none) and the mist floor's height over Banjo's feet (6 bits, steps of 8 units, 32 = level).
uint VolBits() {
    return (uint(gConstants.fog.y) >> 12) | ((uint(gConstants.fog.z) >> 12) << 12);
}

float VolMistStrength() {
    return float(VolBits() & 63u) / 63.0f;
}

float VolFogStrength() {
    return float((VolBits() >> 6) & 63u) / 63.0f;
}

uint VolFogPreset() {
    return (VolBits() >> 12) & 7u;
}

uint VolCloudType() {
    return (VolBits() >> 15) & 7u;
}

float VolFloorDelta() {
    return (float((VolBits() >> 18) & 63u) - 32.0f) * 8.0f;
}

// The rest of the settings, in the buffer's header (SetSceneVolumetricExtra in rt64_scene_effects.cpp): [0] the fog's
// start distance / 25 (8 bits), its colour (3 bits: 0 the preset's own, 1 to 4 Haze, Mist, Dusk, Gloom) and how high the mist
// hangs over water / 4 (7); [1] the mist over water and at a waterfall's foot in hundredths (7 bits each) and how high the
// fall's mist rises / 4 (7).
uint VolExtra(uint index) {
    return uint(asfloat(gDust.Load(4u + index * 4u)) + 0.5f);
}

float VolFogStart() {
    return float(VolExtra(0u) & 255u) * 25.0f;
}

uint VolFogColour() {
    return (VolExtra(0u) >> 8) & 7u;
}

float VolWaterHeight() {
    return float((VolExtra(0u) >> 11) & 127u) * 4.0f;
}

float VolWaterMist() {
    return float(VolExtra(1u) & 127u) / 100.0f;
}

float VolFallMist() {
    return float((VolExtra(1u) >> 7) & 127u) / 100.0f;
}

float VolFallHeight() {
    return float((VolExtra(1u) >> 14) & 127u) * 4.0f;
}

// The normal fog's colours (Graphics > Fog colour), for the volumetric fog's own colour setting.
static const float3 kVolFogColours[4] = {
    float3(0.72f, 0.80f, 0.88f), float3(0.90f, 0.92f, 0.94f), float3(0.95f, 0.72f, 0.52f), float3(0.16f, 0.17f, 0.22f) };

// The fog presets (Graphics > Volumetric Fog Preset): the settings of the presets in Arthur Brussee's Vapor
// (https://github.com/ArthurBrussee/Vapor, VaporSettings/*.asset, Resources/DefaultVaporSetting.asset and
// Examples/SponzaScene/SponzaFog.asset, Examples/PillarTest/PillarSetting.asset), MIT licence:
//
//   MIT License
//   Copyright (c) 2017 Arthur Brussee
//   Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
//   documentation files (the "Software"), to deal in the Software without restriction, including without limitation
//   the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and
//   to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//   The above copyright notice and this permission notice shall be included in all copies or substantial portions of
//   the Software.
//   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
//   TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//   THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
//   CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//   DEALINGS IN THE SOFTWARE.
//
// Only these numbers are taken (no Vapor shader or C# code is copied): albedo (the colour it scatters), extinction (how thick it is),
// emissive (its own glow) and the ambient light it scatters. The fog itself is our own ray march (Wronski-style
// scattering along each pixel's ray), not Vapor's code. 0 Default, 1 Bright, 2 Hell, 3 Murky, 4 Poison, 5 Sponza, 6 Pillar.
// Bright's extinction is 1 here, not Vapor's 0.05: Vapor's lights are far brighter than the game's sun.
static const float3 kVolAlbedo[7] = {
    float3(0.4477f, 0.7303f, 0.8456f), float3(0.4191f, 0.4191f, 0.3820f), float3(0.1160f, 0.0f, 0.0f), float3(0.0515f, 0.0515f, 0.0515f),
    float3(0.3447f, 0.5294f, 0.0973f), float3(0.7777f, 0.8785f, 0.9118f), float3(1.0f, 1.0f, 1.0f) };
static const float kVolExtinction[7] = { 4.0f, 1.0f, 15.45f, 7.0f, 5.0f, 10.0f, 5.0f };
static const float3 kVolEmissive[7] = {
    float3(0.0f, 0.0f, 0.0f), float3(0.0f, 0.0f, 0.0f), float3(0.4044f, 0.0f, 0.0f), float3(0.0f, 0.0f, 0.0f),
    float3(0.6366f, 1.42f, 0.0f), float3(0.0f, 0.0f, 0.0f), float3(0.0f, 0.0f, 0.0f) };
static const float3 kVolAmbient[7] = {
    float3(0.1604f, 0.1604f, 0.1604f), float3(0.6871f, 1.2361f, 1.46f), float3(0.4485f, 0.4485f, 0.4485f), float3(4.378f, 4.378f, 4.378f),
    float3(1.0f, 1.0f, 1.0f), float3(0.2353f, 0.2353f, 0.2353f), float3(0.2353f, 0.2353f, 0.2353f) };

// The sun's direction in view space: towards it, or straight up when the game has none set.
float3 VolSunView() {
    const float3 sun = gConstants.sun.xyz;
    return (dot(sun, sun) > 0.25f) ? normalize(sun) : normalize(gConstants.worldY.xyz);
}

float3 VolLookView(int2 pixel) {
    const float2 ndc = float2((pixel.x + 0.5f) / gConstants.projection.z * 2.0f - 1.0f, 1.0f - (pixel.y + 0.5f) / gConstants.projection.w * 2.0f);
    return normalize(float3(ndc.x / gConstants.projection.x, ndc.y / gConstants.projection.y, -1.0f));
}

// Volumetric mist and fog along the pixel's ray from the camera to the surface (worldDistance in world units; the
// sky passes a long one): the ray is marched in steps that are short near the camera, and at each the thickness
// of a ground-hugging mist layer and of an even fog (both broken up by drifting noise) takes light from the
// picture, and the light they scatter (ambient, and the sun, more when looking towards it) is added, as in
// Wronski's and Hillaire's volumetric scattering: colour = colour * transmittance + in-scattered light.
// The mist layer stands at Banjo's ground (a slow anchor, so it does not bob as he jumps) and thins out above it.
// tint: the day and night cycle's tint of the light (1 without it).
// Where the mist settles round the point the ray ends at (the nearest thing at the pixel), found as the mist used to be: a ring
// of looks into the water mask about 260 world units round the point. x the water's height there (-1e9 for none), y how far
// across (along the ground) the nearest water look is, z the lowest point of a waterfall found (-1e9 for none), w how far
// across the nearest waterfall look is; xz of the nearest of each go in waterAt and fallAt.
float4 VolSettle(int2 pixel, float3 end, float distance, float3 look, out float2 waterAt, out float2 fallAt) {
    float4 result = float4(-1e9f, 1e9f, -1e9f, 1e9f);
    waterAt = 0.0f;
    fallAt = 0.0f;
    if (gConstants.water.y <= 0.5f) {
        return result;
    }
    const float scale = length(gConstants.worldX.xyz);
    const float height = gConstants.projection.w;
    const float viewDepth = max(distance / scale * max(-look.z, 0.05f), 1e-3f);
    const float radius = clamp((260.0f / scale) * gConstants.projection.y * 0.5f * height / viewDepth, 3.0f, height * 0.2f);
    float found = 0.0f;
    float waterY = 0.0f;
    for (int i = 0; i < 9; i++) {
        const float angle = float(i) * 0.6981317f;
        const float2 offset = (i == 8) ? float2(0.0f, 0.0f) : float2(cos(angle), sin(angle)) * radius * ((i & 1) ? 1.0f : 0.5f);
        const int2 at = pixel + int2(offset);
        float waterDepth;
        if (LoadWater(at, waterDepth) && (SteepAt(at) < 0.5f)) {
            const float3 waterWorld = WorldPosition(ViewPosition(at, waterDepth));
            found += 1.0f;
            waterY += waterWorld.y;
            const float across = length(waterWorld.xz - end.xz);
            if (across < result.y) {
                result.y = across;
                waterAt = waterWorld.xz;
            }
        }
        else if (LoadAnyWater(at, waterDepth) && (SteepAt(at) >= 0.5f)) {
            const float3 fallWorld = WorldPosition(ViewPosition(at, waterDepth));
            result.z = (result.z < -1e8f) ? fallWorld.y : min(result.z, fallWorld.y);
            const float across = length(fallWorld.xz - end.xz);
            if (across < result.w) {
                result.w = across;
                fallAt = fallWorld.xz;
            }
        }
    }
    if (found > 0.0f) {
        result.x = waterY / found;
    }
    return result;
}

float3 VolScatter(float3 color, int2 pixel, float worldDistance, float3 tint) {
    // Squared: the slider's low end is fine, and 100 is as thick as it always was.
    const float mistSlider = VolMistStrength();
    const float mist = mistSlider * mistSlider;
    // The slider's curve eases in (40 is about a quarter as thick as 100, L 2026-10-23: 40 hid the far scenery); 100 is as it was.
    const float fogAmount = pow(VolFogStrength(), 1.6f);
    const float waterMist = VolWaterMist();
    const float fallMist = VolFallMist();
    if ((mist <= 0.0f) && (fogAmount <= 0.0f) && (waterMist <= 0.0f) && (fallMist <= 0.0f)) {
        return color;
    }
    const float scale = length(gConstants.worldX.xyz);
    const float3 look = VolLookView(pixel);
    const float3 origin = float3(gConstants.worldX.w, gConstants.worldY.w, gConstants.worldZ.w);
    const float3 direction = float3(dot(look, gConstants.worldX.xyz), dot(look, gConstants.worldY.xyz), dot(look, gConstants.worldZ.xyz)) / scale;
    const float far = min(worldDistance, 6000.0f);
    const float floorY = (gConstants.rippleAge.w > -1e8f) ? (gConstants.rippleAge.w + VolFloorDelta()) : (origin.y - 100.0f);
    const float time = gConstants.view.z;

    const uint preset = min(VolFogPreset(), 6u);
    // Per world unit: Vapor's extinction is per metre; this is tuned so a level's far side is lost to the thickest.
    const float fogSigma = fogAmount * kVolExtinction[preset] * 0.00012f;
    const uint fogColour = VolFogColour();
    const float3 fogAlbedo = (fogColour > 0u) ? kVolFogColours[min(fogColour - 1u, 3u)] : kVolAlbedo[preset];
    const float fogStart = VolFogStart();
    const float3 sunView = VolSunView();
    const float cosine = dot(look, sunView);
    // Henyey-Greenstein, mostly forward: brighter looking towards the sun.
    const float g = 0.45f;
    const float phase = 0.55f * (1.0f - g * g) / pow(max(1.0f + g * g - 2.0f * g * cosine, 0.05f), 1.5f);
    const float3 sunLight = float3(1.0f, 0.95f, 0.85f) * (phase + 0.25f) * 1.4f;
    const float3 fogLight = (fogAlbedo * ((fogColour > 0u) ? (0.35f + sunLight) : (kVolAmbient[preset] + sunLight)) + ((fogColour > 0u) ? 0.0f : 0.6f) * kVolEmissive[preset]) * tint;
    const float3 mistLight = lerp(float3(0.78f, 0.82f, 0.88f), float3(1.0f, 0.9f, 0.76f), saturate(phase * 0.4f)) * tint * 0.9f;

    // Mist settling over water and at a waterfall's foot, round where the ray ends.
    float4 settle = float4(-1e9f, 1e9f, -1e9f, 1e9f);
    float2 waterAt = 0.0f;
    float2 fallAt = 0.0f;
    if (((waterMist > 0.0f) || (fallMist > 0.0f)) && (worldDistance < 5990.0f)) {
        settle = VolSettle(pixel, origin + direction * far, far, look, waterAt, fallAt);
    }
    const float waterHeight = VolWaterHeight();
    const float fallHeight = VolFallHeight();

    const int steps = 20;
    const float jitter = frac(DayHash(float3(pixel, 3.0f)) + NoiseFrameOffset());
    const float3 wind = float3(time * 6.0f, 0.0f, time * 2.5f);
    float transmittance = 1.0f;
    float3 light = 0.0f;
    [loop]
    for (int i = 0; i < steps; i++) {
        // Steps grow with distance (squared spacing): fine detail near the camera, the far reach still covered.
        const float e0 = far * float(i) * float(i) / float(steps * steps);
        const float e1 = far * float(i + 1) * float(i + 1) / float(steps * steps);
        const float ds = e1 - e0;
        const float t = e0 + ds * jitter;
        const float3 p = origin + direction * t;
        const float height = p.y - floorY;
        // The mist: thickest at and under the floor, thinning to nothing about 300 units up, in drifting banks.
        float mistSigma = 0.0f;
        if (mist > 0.0f) {
            const float banks = saturate(0.25f + 1.6f * CloudNoise(p * 0.0045f + wind * 0.004f));
            mistSigma = mist * 0.0026f * exp(-max(height, 0.0f) / 130.0f) * banks;
        }
        // A denser, shallower layer hanging just over the water, and spray rising where a waterfall lands.
        if ((waterMist > 0.0f) && (settle.x > -1e8f)) {
            const float across = length(p.xz - waterAt);
            const float over = p.y - settle.x;
            const float banks = saturate(0.35f + 1.3f * CloudNoise(p * 0.006f + wind * 0.004f));
            mistSigma += waterMist * 0.004f * banks * saturate(1.5f - across / 260.0f) * exp(-max(over, 0.0f) / max(waterHeight, 8.0f)) * saturate((over + 40.0f) / 40.0f);
        }
        if ((fallMist > 0.0f) && (settle.z > -1e8f)) {
            const float across = length(p.xz - fallAt);
            const float over = p.y - settle.z;
            const float billow = saturate(0.3f + 1.2f * CloudNoise(float3(p.x + p.z, p.y - time * 40.0f, p.x - p.z) * 0.02f));
            mistSigma += fallMist * 0.008f * billow * saturate(1.0f - across / 180.0f) * exp(-max(over, 0.0f) / max(fallHeight, 8.0f)) * saturate((over + 30.0f) / 30.0f);
        }
        float fogHere = 0.0f;
        if (fogAmount > 0.0f) {
            // An even fog with slow patches, and a little less far above the floor; it thickens past its start distance.
            const float begin = lerp(1.0f, saturate((t - fogStart) / 1500.0f), saturate(fogStart / 200.0f));
            fogHere = fogSigma * begin * (0.7f + 0.6f * CloudNoise(p * 0.0016f + wind * 0.002f + 5.0f)) * exp(-max(height, 0.0f) / 7000.0f);
        }
        const float sigma = mistSigma + fogHere;
        if (sigma > 1e-7f) {
            const float3 mistLit = mistLight * lerp(0.75f, 1.0f, saturate(height / 160.0f));
            const float3 source = (mistSigma * mistLit + fogHere * fogLight) / sigma;
            const float step = exp(-sigma * ds);
            light += transmittance * (1.0f - step) * source;
            transmittance *= step;
        }
    }
    return color * transmittance + light;
}

// Forced clouds (WIP): the cycle's clouds on any level without the cycle, over the sky. The cloud's shape comes
// from the cloud constant (view.y); the type's darkness and warmth from the tables above.
float3 VolSky(float3 color, int2 pixel) {
    const uint type = VolCloudType();
    const float3 look = VolLookView(pixel);
    const float3 world = normalize(float3(dot(look, gConstants.worldX.xyz), dot(look, gConstants.worldY.xyz), dot(look, gConstants.worldZ.xyz)));
    float3 sunWorld = float3(0.3f, 0.8f, 0.5f);
    if (dot(gConstants.sun.xyz, gConstants.sun.xyz) > 0.25f) {
        sunWorld = float3(dot(gConstants.sun.xyz, gConstants.worldX.xyz), dot(gConstants.sun.xyz, gConstants.worldY.xyz), dot(gConstants.sun.xyz, gConstants.worldZ.xyz));
    }
    sunWorld = normalize(sunWorld);
    const float dark = VolCloudDarkness(type);
    // A stormy sky greys and darkens too.
    const float grey = dot(color, float3(0.3f, 0.59f, 0.11f));
    float3 sky = lerp(color, grey.xxx * float3(0.8f, 0.84f, 0.9f), dark * 0.55f) * (1.0f - dark * 0.35f);
    const float4 clouds = DayClouds(world, sunWorld, float3(1.0f, 1.0f, 1.0f), VolCloudWarmth(type), pixel, float3(dark, 0.0f, 0.0f));
    return sky * (1.0f - clouds.a) + clouds.rgb;
}

// Raindrops on the screen in the rain, more when looking up: each lands, holds a while, then runs down leaving
// a thin wet trail. A drop bends what is behind it, as a little lens, darker at its rim with a glint.
float3 DayLensDrops(float3 scene, int2 pixel, float3 tint, float rain) {
    if ((DayMistAndRain().w < 0.5f) || (rain <= 0.0f) || (gConstants.fog.w > 0.0f) || DaySnow()) {
        return scene;
    }
    const float2 size = gConstants.projection.zw;
    const float lookUp = -gConstants.worldY.z / length(gConstants.worldY.xyz);
    const float chance = saturate(rain * 1.3f) * (0.06f + 0.34f * smoothstep(-0.45f, 0.25f, lookUp));
    const float time = gConstants.view.z;
    const float Cell = size.y / 7.0f;
    float2 bend = 0.0f;
    float inside = 0.0f, rim = 0.0f, glint = 0.0f, trail = 0.0f;
    [unroll]
    for (int layer = 0; layer < 2; layer++) {
        const float2 p = float2(pixel) / Cell + float2(0.5f, 0.29f) * float(layer);
        // This cell, and the one above for a drop running down into it.
        [unroll]
        for (int k = 0; k < 2; k++) {
            const float2 cell = floor(p) - float2(0.0f, float(k));
            const float3 seed = float3(cell, 31.0f + float(layer) * 7.0f);
            const float period = 3.0f + 3.0f * DayHash(seed + 1.0f);
            const float phase = time / period + DayHash(seed + 2.0f);
            // A new drop (or none) each time round, on its own spot.
            const float3 drop = seed + floor(phase) * 17.0f;
            if (DayHash(drop) > chance) {
                continue;
            }
            const float age = frac(phase);
            const float radius = 0.06f + 0.09f * DayHash(drop + 3.0f);
            float2 c = cell + 0.25f + 0.5f * float2(DayHash(drop + 4.0f), DayHash(drop + 5.0f));
            const float slide = smoothstep(0.45f, 1.0f, age);
            const float run = slide * slide * 1.4f;
            const float top = c.y;
            c.y += run;
            const float appear = saturate(age * 25.0f) * (1.0f - smoothstep(0.85f, 1.0f, age));
            // Running drops stretch a little.
            const float2 d = (p - c) / (radius * float2(1.0f, 1.0f + 0.3f * slide));
            const float r = length(d);
            if (r < 1.0f) {
                bend += -d * radius * Cell * 0.3f * appear;
                inside = max(inside, appear);
                rim = max(rim, smoothstep(0.65f, 1.0f, r) * appear);
                glint = max(glint, saturate(1.0f - length(d - float2(-0.35f, -0.4f)) / 0.28f) * appear);
            }
            else if ((run > 0.0f) && (p.y < c.y) && (p.y > top)) {
                const float along = (p.y - top) / max(run, 1e-3f);
                trail = max(trail, saturate(1.0f - abs(p.x - c.x) / (radius * 0.3f)) * along * appear * 0.6f);
            }
        }
    }
    if ((inside <= 0.0f) && (trail <= 0.0f)) {
        return scene;
    }
    const float bright = 0.4f + 0.6f * max(tint.r, max(tint.g, tint.b));
    if (inside > 0.0f) {
        const int2 at = clamp(int2(float2(pixel) + bend), int2(0, 0), int2(size) - 1);
        // What is bent in, as the change it makes to the picture here, so the drop keeps the finished look
        // (the tint, an overcast sky) round it.
        const float3 through = max(scene + (gColor.Load(int3(at, 0)).rgb - gColor.Load(int3(pixel, 0)).rgb) * tint, 0.0f);
        const float3 lens = through * (1.0f - 0.35f * rim) + glint * 0.5f * bright;
        return lerp(scene, lens, inside * 0.7f);
    }
    const int2 at = clamp(pixel + int2(int(Cell * 0.02f) + 1, 0), int2(0, 0), int2(size) - 1);
    return lerp(scene, max(scene + (gColor.Load(int3(at, 0)).rgb - gColor.Load(int3(pixel, 0)).rgb) * tint, 0.0f) * 1.08f, trail);
}

// Morning dew: by the low morning sun (in the east), tiny glints twinkle on level grass, fixed in the world.
float3 DayDew(int2 pixel, float depth, float3 tint, float3 color) {
    if (depth >= 0.99999f) {
        return 0.0f;
    }
    const float morning = DayMorning(tint);
    // Grass: green above red and blue.
    const float grass = saturate((color.g - max(color.r, color.b) * 1.05f) * 8.0f);
    if ((morning <= 0.0f) || (grass <= 0.0f)) {
        return 0.0f;
    }
    const float3 center = ViewPosition(pixel, depth);
    const float level = saturate((dot(ViewNormal(pixel, center), normalize(gConstants.worldY.xyz)) - 0.6f) * 4.0f);
    if (level <= 0.0f) {
        return 0.0f;
    }
    const float3 world = float3(dot(center, gConstants.worldX.xyz) + gConstants.worldX.w, dot(center, gConstants.worldY.xyz) + gConstants.worldY.w,
        dot(center, gConstants.worldZ.xyz) + gConstants.worldZ.w);
    const float scale = length(gConstants.worldX.xyz);
    const float distance = length(center) * scale;
    // A drop in some cells of a 5-unit grid on the ground, a pixel or so across.
    const float Cell = 5.0f;
    const float2 cell = floor(world.xz / Cell);
    const float pick = DayHash(float3(cell, 3.0f));
    if (pick < 0.7f) {
        return 0.0f;
    }
    const float2 place = (cell + 0.2f + 0.6f * float2(DayHash(float3(cell, 5.0f)), DayHash(float3(cell, 9.0f)))) * Cell;
    const float pixelSize = distance * 2.0f / (gConstants.projection.y * gConstants.projection.w);
    const float size = max(0.25f, pixelSize * 0.8f);
    const float drop = saturate(1.0f - length(world.xz - place) / size) * min(1.0f, 0.25f / size * 2.0f);
    // Each catches the sun only from some angles, so they twinkle as the camera moves, and slowly on their own.
    const float twinkle = pow(saturate(sin(gConstants.view.z * (0.7f + pick) + pick * 200.0f + dot(normalize(center), float3(31.0f, 17.0f, 23.0f)))), 6.0f);
    const float fade = 1.0f - smoothstep(300.0f, 900.0f, distance);
    return float3(1.0f, 0.97f, 0.88f) * (drop * twinkle * fade * grass * level * morning * 3.0f);
}

// Fireflies at night, after the forest at night in Ocarina of Time: many small warm motes of light, a bright
// white-yellow core in a wide soft glow, floating slowly in loops at all heights from the grass up into the
// trees and glowing up and fading away smoothly rather than blinking. Two to each 160-unit square of the
// ground round Banjo (a 9 by 9 block of squares, fixed in the world). Each is projected onto the screen and
// hidden behind whatever is nearer.
//
// Where each firefly is on the screen is the same for every pixel, so a one-line pass works the 162 of them out
// once a frame into a table (FIREFLY_TABLE: FireflyTablePS, a 162 by 2 texture, gFireflies), and the pixels only
// read it: row 0 holds the screen position, the core's radius in pixels and the view-space z (radius 0 for one
// that is dark or behind the camera), row 1 its brightness.
#define FIREFLY_CELLS 9
#define FIREFLY_COUNT (FIREFLY_CELLS * FIREFLY_CELLS * 2)

bool FireflyPlace(int index, out float4 place, out float weight) {
    place = 0.0f;
    weight = 0.0f;
    const int k = index & 1;
    const int cellIndex = index >> 1;
    const int cx = (cellIndex % FIREFLY_CELLS) - (FIREFLY_CELLS / 2);
    const int cz = (cellIndex / FIREFLY_CELLS) - (FIREFLY_CELLS / 2);
    const float3 banjo = float3(gConstants.rippleX.w, gConstants.rippleAge.w, gConstants.rippleZ.w);
    // View space from world space: the inverse of the view-to-world rows (a rotation and a scale).
    const float scale = 1.0f / dot(gConstants.worldX.xyz, gConstants.worldX.xyz);
    const float viewToWorld = length(gConstants.worldX.xyz);
    const float3 origin = float3(gConstants.worldX.w, gConstants.worldY.w, gConstants.worldZ.w);
    const float2 size = gConstants.projection.zw;
    const float time = gConstants.view.z;
    const float Cell = 160.0f;
    const float2 home = floor(banjo.xz / Cell);
    const float2 cell = home + float2(cx, cz);
    const float3 seed = float3(cell, 7.0f + 13.0f * float(k));
    const float a = DayHash(seed + 11.0f), b = DayHash(seed + 23.0f), c = DayHash(seed + 37.0f);
    // Glows up and fades away over several seconds, then is dark for a while: about two in three
    // are lit at a time.
    const float cycle = frac(time / (5.0f + 4.0f * a) + b);
    const float lit = smoothstep(0.0f, 0.25f, cycle) * (1.0f - smoothstep(0.55f, 0.7f, cycle));
    if (lit <= 0.0f) {
        return false;
    }
    // Slow loops round a home spot, at any height from the grass up into the trees.
    const float t = time * (0.18f + 0.12f * c) + a * 40.0f;
    const float3 world = float3((cell.x + 0.15f + 0.7f * a) * Cell + sin(t) * 40.0f + sin(t * 2.3f) * 12.0f,
        banjo.y + 15.0f + 230.0f * c * c + sin(t * 1.7f + b * 20.0f) * 22.0f,
        (cell.y + 0.15f + 0.7f * b) * Cell + cos(t * 0.9f) * 40.0f + cos(t * 2.1f) * 12.0f);
    const float3 d = world - origin;
    const float3 v = (gConstants.worldX.xyz * d.x + gConstants.worldY.xyz * d.y + gConstants.worldZ.xyz * d.z) * scale;
    if (v.z > -20.0f) {
        return false;
    }
    const float2 ndc = float2(v.x * gConstants.projection.x / -v.z, v.y * gConstants.projection.y / -v.z);
    const float2 at = float2(ndc.x * 0.5f + 0.5f, 0.5f - ndc.y * 0.5f) * size;
    // A core about 3 units across (never under 1.5 pixels at 1080 rows) in a glow eight times as wide.
    const float radius = max(3.0f * gConstants.projection.y / -v.z * size.y * 0.5f, 1.5f * size.y / 1080.0f);
    const float distance = -v.z * viewToWorld;
    const float fade = saturate(1.0f - length(world.xz - banjo.xz) / (Cell * 4.2f));
    // Fades out right by the camera, where one would fill the screen.
    const float near = smoothstep(60.0f, 160.0f, distance);
    const float flicker = 0.85f + 0.15f * sin(time * (6.0f + 4.0f * c) + a * 50.0f);
    place = float4(at, radius, v.z);
    weight = lit * flicker * fade * near;
    return true;
}

#ifndef FIREFLY_TABLE
float3 DayFireflies(int2 pixel, float depth, float3 tint) {
    const float night = DayNight(tint);
    if (((DayPacked() & 1u) == 0u) || (night <= 0.0f) || (gConstants.rippleAge.w < -1e8f)) {
        return 0.0f;
    }
    const float sceneZ = (depth >= 0.99999f) ? -1e9f : ViewPosition(pixel, depth).z;
    const float2 here = float2(pixel) + 0.5f;
    float3 glow = 0.0f;
    [loop] for (int i = 0; i < FIREFLY_COUNT; i++) {
        const float4 place = gFireflies.Load(int3(i, 0, 0));
        if (place.z <= 0.0f) {
            continue;
        }
        // Hidden behind nearer scenery.
        if (sceneZ > place.w + 10.0f) {
            continue;
        }
        const float r = length(here - place.xy) / place.z;
        if (r > 8.0f) {
            continue;
        }
        const float weight = gFireflies.Load(int3(i, 1, 0)).x;
        const float core = saturate(1.3f - r);
        const float halo = saturate(1.0f - r / 8.0f);
        glow += (float3(1.0f, 0.98f, 0.85f) * core + float3(1.0f, 0.85f, 0.4f) * (halo * halo * halo * 0.45f)) * weight;
    }
    return glow * night * 2.2f;
}
#endif

// Light shafts: from each pixel, steps towards the sun on screen, gathering the bright sky it passes
// through and fading with each step, so light streams through gaps between things against the sky.
float3 LightShafts(int2 pixel) {
    const float3 sun = gConstants.sun.xyz;
    if (sun.z > -0.05f) {
        // Behind the camera, or almost square to it.
        return 0.0f;
    }
    const float2 size = gConstants.projection.zw;
    const float2 ndc = float2(sun.x * gConstants.projection.x / -sun.z, sun.y * gConstants.projection.y / -sun.z);
    const float2 sunScreen = float2(ndc.x * 0.5f + 0.5f, 0.5f - ndc.y * 0.5f) * size;
    // Fades out as the sun leaves the screen, gone a screen's height past its edge.
    const float2 outside = max(max(-sunScreen, sunScreen - size), 0.0f);
    const float onScreen = saturate(1.0f - length(outside) / size.y);
    if (onScreen <= 0.0f) {
        return 0.0f;
    }

    const int Samples = 24;
    const float2 delta = (sunScreen - float2(pixel)) * (0.9f / float(Samples));
    // A different start for each pixel hides the steps.
    const float jitter = InterleavedNoise(pixel);
    float2 p = float2(pixel) + delta * jitter;
    float3 gathered = 0.0f;
    float weight = 1.0f;
    float total = 0.0f;
    [loop] for (int i = 0; i < Samples; i++) {
        p += delta;
        const int2 at = clamp(int2(p), int2(0, 0), int2(size) - 1);
        if (LoadDepth(at) >= 0.99999f) {
            const float3 sky = gColor.Load(int3(at, 0)).rgb;
            // Only bright sky gives light: night skies and dark backdrops don't.
            const float bright = saturate((dot(sky, float3(0.299f, 0.587f, 0.114f)) - 0.2f) * 1.6f);
            gathered += sky * (bright * weight);
        }
        total += weight;
        weight *= 0.935f;
    }
    // The share of the way to the sun that is open sky: whole near gaps in the scenery, so beams fan out
    // from them across whatever is in front, and brightest close to the sun.
    const float near = saturate(1.0f - length(sunScreen - float2(pixel)) / (size.y * 1.2f));
    return (gathered / total) * (DayWeather().y * onScreen * near * near * 1.4f);
}

// Sun shadows: from the surface, steps towards the sun and checks the depth buffer at each step; when
// something stands in front of the step (but not so far in front that the ray passed behind it), the
// surface is in its shadow. Surfaces turned away from the sun are shaded too, gently, so the dark side of
// a thing meets its shadow on the ground.
// center and surfaceNormal as AmbientOcclusion's.
// One of the sun shadow maps (the near one at x 0 in gSunShadowMap, the far one beside it at offsetX): how much of
// the sun a surface gets none of, looked up a little off the surface, a few texels around (wider the softer the
// shadows). cover fades out towards the map's edges (0 outside it).
float SunMapLookup(SunMapFrame mapFrame, int offsetX, float3 worldCenter, float3 worldNormal, float distance, float softness, float jitter, out float cover) {
    cover = 0.0f;
    const float texel = 2.0f * mapFrame.halfWidth / mapFrame.size;
    float3 across, up, towards, middle;
    SunMapBasis(mapFrame, across, up, towards, middle);
    // How steeply the sun meets the surface. A low sun (mornings and evenings) grazes the ground: across
    // the few texels looked up the ground's own depth on the map changes a lot, and a fixed bias let it
    // shadow itself in fine diagonal lines. The bias and the lift off the surface grow with the slope.
    const float sunFacing = dot(worldNormal, towards);
    const float sunCos = saturate(sunFacing);
    const float sunSin = sqrt(1.0f - sunCos * sunCos);
    const float sunTan = min(sunSin / max(sunCos, 0.05f), 8.0f);
    const float radius = 1.0f + softness * 2.5f;
    const float3 world = worldCenter + worldNormal * (texel * (1.5f + 1.5f * sunSin) + distance * 0.001f);
    const float3 m = SunMapPosition(mapFrame, world);
    if ((m.z <= 0.0f) || (m.z >= 1.0f)) {
        return 0.0f;
    }
    cover = saturate((1.0f - max(abs(m.x), abs(m.y))) / 0.1f);
    if (cover <= 0.0f) {
        return 0.0f;
    }
    const float depthBias = texel * (1.5f + sunTan * (radius + 1.0f)) / (2.0f * mapFrame.range);
    const float2 base = float2(m.x * 0.5f + 0.5f, 0.5f - m.y * 0.5f) * mapFrame.size;
    const float angle = jitter * 6.2831853f;
    const float2x2 turn = float2x2(cos(angle), -sin(angle), sin(angle), cos(angle));
    const int Taps = 12;
    const float2 disk[Taps] = {
        float2(-0.326f, -0.406f), float2(-0.840f, -0.074f), float2(-0.696f, 0.457f), float2(-0.203f, 0.621f),
        float2(0.962f, -0.195f), float2(0.473f, -0.480f), float2(0.519f, 0.767f), float2(0.185f, -0.893f),
        float2(0.507f, 0.064f), float2(0.896f, 0.412f), float2(-0.322f, -0.933f), float2(-0.792f, -0.598f)
    };
    const int last = int(mapFrame.size) - 1;
    float blocked = 0.0f;
    [unroll] for (int k = 0; k < Taps; k++) {
        const int2 at = clamp(int2(floor(base + mul(turn, disk[k]) * radius)), int2(0, 0), int2(last, last));
        blocked += ((m.z - depthBias) > gSunShadowMap.Load(int3(at.x + offsetX, at.y, 0))) ? 1.0f : 0.0f;
    }
    // A surface turned from the sun gets none of its light either: as dark as a cast shadow, with a soft
    // turn (wider the softer the shadows) so rounded characters still shade smoothly.
    const float away = saturate(-sunFacing * lerp(6.0f, 2.0f, softness));
    return max(blocked / float(Taps), away);
}

#ifdef RAY_TRACED
// Whether the sun reaches a spot under cover through a cut-out's holes (a grate in a wall or a roof, a fence): the first
// thing towards the sun, counting cut-outs as solid, is a level cut-out (the traced shadow rays went through its holes),
// and the spot is under cover (the ray straight up and three of four slanted up meet something). There the game lit it as
// shade, so the sun's light coming through is added, throwing the grate's pattern (L, 2026-10-21). A wall under eaves or
// the floor round an object's lip isn't lit through a cut-out, so it gets nothing (King Jingaling's house, the Jiggy shrine).
bool SunThroughCutout(float3 worldStart, float3 worldSun, bool unblocked) {
    // gLights 8 is 3 when the scene has a level cut-out at all.
    if (asfloat(gLights.Load(32)) < 2.5f) {
        return false;
    }
    if (unblocked) {
        // Every shadow ray got through, so nothing solid lies towards the sun: the first thing there counting cut-outs as
        // solid is a cut-out wherever there is one. Asked of the cut-outs alone, the solid triangles (most of the world)
        // are passed by, where the closest-hit ray below walked the whole structure for every sunlit pixel.
        RayDesc ray;
        ray.Origin = worldStart;
        ray.Direction = worldSun;
        ray.TMin = 0.0f;
        ray.TMax = 20000.0f;
        RayQuery<RAY_FLAG_CULL_OPAQUE | RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES> query;
        query.TraceRayInline(gSceneBVH, 0, RayLevelMask, ray);
        while (query.Proceed()) {
            if (query.CandidateType() != CANDIDATE_NON_OPAQUE_TRIANGLE) {
                continue;
            }
            if ((RayGeometryFlags(RayGeometryOf(query.CandidateInstanceID(), query.CandidateGeometryIndex())) & 5u) == 1u) {
                query.CommitNonOpaqueTriangleHit();
                query.Abort();
            }
        }
        if (query.CommittedStatus() != COMMITTED_TRIANGLE_HIT) {
            return false;
        }
    }
    else {
        RayDesc ray;
        ray.Origin = worldStart;
        ray.Direction = worldSun;
        ray.TMin = 0.0f;
        ray.TMax = 20000.0f;
        RayQuery<RAY_FLAG_FORCE_OPAQUE | RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES> query;
        query.TraceRayInline(gSceneBVH, 0, RayWorldMask, ray);
        query.Proceed();
        if ((query.CommittedStatus() != COMMITTED_TRIANGLE_HIT) || ((RayGeometryFlags(RayGeometryOf(query.CommittedInstanceID(), query.CommittedGeometryIndex())) & 5u) != 1u)) {
            return false;
        }
    }
    const float3 directions[5] = { float3(0.0f, 1.0f, 0.0f), float3(0.82f, 0.57f, 0.0f), float3(-0.82f, 0.57f, 0.0f), float3(0.0f, 0.57f, 0.82f), float3(0.0f, 0.57f, -0.82f) };
    uint hits = 0u;
    [loop] for (int k = 0; k < 5; k++) {
        RayDesc ray;
        ray.Origin = worldStart;
        ray.Direction = directions[k];
        ray.TMin = 0.0f;
        ray.TMax = 6000.0f;
        RayQuery<RAY_FLAG_FORCE_OPAQUE | RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES | RAY_FLAG_ACCEPT_FIRST_HIT_AND_END_SEARCH> query;
        query.TraceRayInline(gSceneBVH, 0, RayWorldMask, ray);
        query.Proceed();
        if (query.CommittedStatus() == COMMITTED_TRIANGLE_HIT) {
            hits++;
        }
        else if (k == 0) {
            return false;
        }
    }
    return hits >= 4u;
}
#endif

#ifdef RAY_TRACED
// Half-resolution ray tracing (HalfTraced). The indirect pass's lower half, one texel for each 2x2 pixels (for the pixel at
// twice its place): the light beams (rgb, TracedBeams) and the sun shadow's share of blocked rays (a; 2 where the spot is
// enclosed, so in shade whatever the rays say). The pass reads it back for each pixel from the texels round it on the same
// surface (as IndirectAt does), the beams smoothly as they are soft anyway.
static int gSunHalf = 0;

int2 TracedHalfSize() {
    return max(int2(gConstants.projection.zw) / 2, int2(1, 1));
}

float TracedHalfShadow(int2 pixel, float3 center, float3 normal) {
    const int2 halfSize = TracedHalfSize();
    // The 2x2 texels round the pixel (each stands for the pixel at twice its place).
    const int2 base = int2(floor((float2(pixel) - 1.0f) * 0.5f));
    const float2 f = (float2(pixel) - float2(base * 2)) * 0.5f;
    const float tolerance = max(-center.z * 0.03f, 2.0f);
    float shadow = 0.0f;
    float weight = 0.0f;
    float enclosed = 0.0f;
    float nearest = 1e9f;
    float nearestValue = 0.0f;
    [unroll] for (int k = 0; k < 4; k++) {
        const int2 corner = int2(k & 1, k >> 1);
        const int2 q = clamp(base + corner, int2(0, 0), halfSize - 1);
        const float sampleDepth = LoadDepth(q * 2);
        const float value = gIndirect.Load(int3(q.x, q.y + halfSize.y, 0)).a;
        if (sampleDepth >= 0.99999f) {
            continue;
        }
        const float planeDistance = abs(dot(ViewPosition(q * 2, sampleDepth) - center, normal));
        if (planeDistance < nearest) {
            nearest = planeDistance;
            nearestValue = value;
        }
        const float2 b = lerp(1.0f - f, f, float2(corner));
        const float w = saturate(1.0f - planeDistance / tolerance) * (b.x * b.y + 1e-3f);
        if (value > 1.5f) {
            enclosed += w;
        }
        else {
            shadow += value * w;
            weight += w;
        }
    }
    if ((weight + enclosed) < 1e-4f) {
        // Nothing on the same surface round it (a thin pole): the texel on the nearest one.
        return nearestValue;
    }
    return (enclosed > weight) ? 2.0f : shadow / max(weight, 1e-4f);
}

float3 TracedHalfBeams(int2 pixel) {
    const int2 halfSize = TracedHalfSize();
    const float2 textureSize = float2(halfSize.x, halfSize.y * 3);
    // Kept inside the lower half, so the upper half's texels never blend in.
    // Four bilinear taps half a texel apart: a 3x3 tent, which weighs the Bayer pattern's alternate texels equally so it
    // smooths out instead of showing as a mesh.
    const float2 at = clamp((float2(pixel) + 0.5f) * 0.5f, 1.0f, float2(halfSize) - 1.0f) + float2(0.0f, float(halfSize.y));
    float3 sum = 0.0f;
    [unroll] for (int k = 0; k < 4; k++) {
        const float2 offset = float2((k & 1) ? 0.5f : -0.5f, (k & 2) ? 0.5f : -0.5f);
        sum += gIndirect.SampleLevel(LinearSampler, (at + offset) / textureSize, 0).rgb;
    }
    return sum * 0.25f;
}

// The lamps' and fires' traced light (LightShadows' lamp), from the third band, on the same surface as TracedHalfShadow.
float3 TracedHalfLamp(int2 pixel, float3 center, float3 normal) {
    const int2 halfSize = TracedHalfSize();
    const int2 base = int2(floor((float2(pixel) - 1.0f) * 0.5f));
    const float2 f = (float2(pixel) - float2(base * 2)) * 0.5f;
    const float tolerance = max(-center.z * 0.03f, 2.0f);
    float3 sum = 0.0f;
    float weight = 0.0f;
    [unroll] for (int k = 0; k < 4; k++) {
        const int2 corner = int2(k & 1, k >> 1);
        const int2 q = clamp(base + corner, int2(0, 0), halfSize - 1);
        const float sampleDepth = LoadDepth(q * 2);
        if (sampleDepth >= 0.99999f) {
            continue;
        }
        const float planeDistance = abs(dot(ViewPosition(q * 2, sampleDepth) - center, normal));
        const float2 b = lerp(1.0f - f, f, float2(corner));
        const float w = saturate(1.0f - planeDistance / tolerance) * (b.x * b.y + 1e-3f);
        sum += gIndirect.Load(int3(q.x, q.y + halfSize.y * 2, 0)).rgb * w;
        weight += w;
    }
    if (weight < 1e-4f) {
        return gIndirect.Load(int3(clamp(pixel / 2, int2(0, 0), halfSize - 1) + int2(0, halfSize.y * 2), 0)).rgb;
    }
    return sum / weight;
}
#endif

#ifdef RAY_TRACED
// The models' share of the traced sun shadow (Banjo, enemies, NPCs). They are low-poly, and cast through the level's
// narrow cone every flat face of them showed as a hard straight edge: blocky shadows (L, 2026-10-23). Their rays
// spread over a wider cone, so the edge softens the further the shadow falls from the model and the faces blur into
// one rounded shape, still sharp where a foot meets the ground. Two rays from opposite sides of the cone first; only
// where they disagree (the soft edge) the rest. All in world space. Leaving Banjo out (Traced shadows of the player
// off), a ray that meets him goes on.
float SunModelShadow(float3 origin, float3 sunDirection, float3 side, float3 up, float jitter, float softness, bool onBanjo, uint detail) {
    const int Rays = 10;
    const float spread = lerp(0.05f, 0.12f, softness);
    // Turned a different way each pixel; the noise smoothing turns them all more alike (on Banjo even more).
    const float turn = jitter * 6.28318531f * (1.0f - RtSmoothing() * (onBanjo ? 1.0f : 0.8f));
    float blocked = 0.0f;
    int traced = 0;
    [loop] for (int k = 0; k < Rays; k++) {
        if ((k == 2) && ((detail > 0u) || (blocked == 0.0f) || (blocked == 2.0f))) {
            break;
        }
        // The first two across the cone at most of its width, the rest spread over it (golden angle).
        const float angle = turn + ((k < 2) ? float(k) * 3.14159265f : float(k) * 2.39996323f);
        const float radius = ((k < 2) ? 0.8f : sqrt((float(k - 2) + 0.5f) / float(Rays - 2))) * spread;
        RayDesc ray;
        ray.Origin = origin;
        ray.Direction = normalize(sunDirection + (side * cos(angle) + up * sin(angle)) * radius);
        ray.TMin = 0.0f;
        ray.TMax = 20000.0f;
        blocked += (PlayerShadowsOff() ? TraceModels(ray, false) : TraceAny(ray, RayModelMask)) ? 1.0f : 0.0f;
        traced++;
    }
    return blocked / float(max(traced, 1));
}
#endif

// sunlight: with ray tracing, the sun's light let in through a cut-out's holes (a grate) onto what is under cover behind
// it (SunThroughCutout). The game lit such spots as if in shade, so traced shadows alone could only darken them and
// the light through the grate never showed (L, 2026-10-21).
float SunShadow(int2 pixel, float3 center, float3 surfaceNormal, inout float3 sunlight) {
    const float3 sun = gConstants.sun.xyz;
    const float distance = -center.z;
    // Fades out with distance: far away the depth buffer is too coarse and the shadows too small to tell.
    const float near = saturate(1.0f - (distance / ShadowFadeScale(gConstants.shadows.y) - 4000.0f) / 3000.0f);
    if (near <= 0.0f) {
#ifdef RAY_TRACED
        if (gSunHalf == 1) {
            return 0.0f;
        }
#endif
        return 1.0f;
    }
    // Softness (shadows.w, below 1; 2 is added to leave Banjo out).
    const float shadowFlags = gConstants.shadows.w - floor(gConstants.shadows.w / 4.0f) * 4.0f;
    const bool skipBanjo = (shadowFlags > 1.5f) && (gConstants.rippleAge.w > -1e8f);
    const float softness = shadowFlags - (shadowFlags > 1.5f ? 2.0f : 0.0f);
    float3 normal = surfaceNormal;
    // Characters are low-poly, so a normal read from the depth is flat across each triangle and the side
    // turned from the sun was shaded face by face. Soft shadows average the normals a few pixels around,
    // only where the depth says it is the same surface.
    if (softness > 0.0f) {
        const int r = 1 + int(softness * 4.0f);
        const int2 offsets[4] = { int2(-r, 0), int2(r, 0), int2(0, -r), int2(0, r) };
        float3 sum = normal;
        [unroll] for (int k = 0; k < 4; k++) {
            const int2 at = clamp(pixel + offsets[k], int2(1, 1), int2(gConstants.projection.zw) - 2);
            const float3 there = ViewPositionAt(at);
            if (abs(there.z - center.z) < 6.0f + distance * 0.01f * float(r)) {
                sum += ViewNormal(at, there);
            }
        }
        normal = normalize(lerp(normal, normalize(sum), softness));
    }
    const float facing = dot(normal, sun);
    // Lifted off the surface a little (more further away, where the depth is coarser) so it doesn't shadow itself.
    const float bias = 2.0f + distance * 0.004f;
    const float3 start = center + normal * bias;
    const float2 size = gConstants.projection.zw;
    const bool mapView = SunMapView(gConstants.shadows.y);
    const float reach = SunMapReach(gConstants.shadows.y);
    // A different start for each pixel hides the steps.
    const float jitter = InterleavedNoise(pixel);
    // Banjo's own shadow can be left out: what is drawn inside a capsule around him casts none.
    const float3 banjo = float3(gConstants.rippleX.w, gConstants.rippleAge.w, gConstants.rippleZ.w);
    float shadow = 0.0f;
#ifdef RAY_TRACED
    // Traced shadows: rays from the surface towards the sun through the world's triangles (gSceneBVH), a few of them
    // spread over a narrow cone (wider the softer the shadows) so the edge has a penumbra. Nothing between a surface
    // and the sun is missed, on screen or not, and there is no depth thickness to guess.
    {
        const float3 sunDirection = normalize(sun);
        const float3 side = normalize(cross(sunDirection, (abs(sunDirection.y) < 0.9f) ? float3(0.0f, 1.0f, 0.0f) : float3(1.0f, 0.0f, 0.0f)));
        const float3 up = cross(sunDirection, side);
        const float spread = lerp(0.006f, 0.04f, softness);
        const int Rays = 4;
        const bool onBanjo = OnBanjoTraced(center);
        const uint sunDetail = RayDetail(distance);
        float blocked = 0.0f;
        // Two rays across the cone first; only where they disagree (the shadow's soft edge) the other two are traced.
        // Half-resolution ray tracing reads what the indirect pass traced instead (gSunHalf 2).
        int traced = 0;
        // A surface turned from the sun in a room is left alone whatever its rays find: asked first, they needn't be traced.
        if ((gSunHalf != 2) && (facing < 0.0f) && Enclosed(ViewToWorldPoint(start))) {
            return (gSunHalf == 1) ? 2.0f : 1.0f;
        }
        // Turned well away from the sun, a ray towards it goes back in through the surface itself: blocked whatever
        // else is there, so it needn't be traced (unless Banjo lets the rays through him).
        const bool turnedFromSun = (gSunHalf != 2) && (facing < -0.15f) && !(onBanjo && PlayerShadowsOff());
        if (turnedFromSun) {
            blocked = 1.0f;
            traced = 1;
        }
        if (gSunHalf == 2) {
            const float half = TracedHalfShadow(pixel, center, surfaceNormal);
            if (half > 1.5f) {
                return 1.0f;
            }
            blocked = half;
            traced = 1;
        }
        gSawLevelCutout = false;
        [loop] for (int k = 0; (k < Rays) && (gSunHalf != 2) && !turnedFromSun; k++) {
            if ((k == 2) && !RayResolutionHigh() && ((blocked == 0.0f) || (blocked == 2.0f))) {
                break;
            }
            // Far off (Ray detail distances) one ray.
            if ((k == 1) && (sunDetail > 0u)) {
                break;
            }
            traced++;
            // Steadier on Banjo with the noise smoothing: a different turn each pixel speckled his fur.
            // Noise smoothing turns all pixels' rays the same way (on Banjo even more): smoother, the edge in steps.
            const float angle = float(k) * 2.39996323f + jitter * 6.28318531f * (1.0f - RtSmoothing() * (onBanjo ? 1.0f : 0.8f));
            const float radius = sqrt((float(k) + 0.5f) / float(Rays)) * spread;
            const float3 direction = normalize(sunDirection + (side * cos(angle) + up * sin(angle)) * radius);
            RayDesc ray;
            ray.Origin = ViewToWorldPoint(start);
            ray.Direction = ViewToWorldDirection(direction);
            ray.TMin = 0.0f;
            ray.TMax = 20000.0f;
            // The level only: the models cast through their own wider cone below (SunModelShadow).
            blocked += TraceOccluded(ray, 3u) ? 1.0f : 0.0f;
        }
        shadow = blocked / float(max(traced, 1));
        if ((gSunHalf != 2) && !turnedFromSun && (shadow < 1.0f)) {
            shadow = max(shadow, SunModelShadow(ViewToWorldPoint(start), ViewToWorldDirection(sunDirection), ViewToWorldDirection(side),
                ViewToWorldDirection(up), jitter, softness, onBanjo, sunDetail));
        }
        if ((gSunHalf != 2) && (shadow > 0.0f) && (facing >= 0.0f) && Enclosed(ViewToWorldPoint(start))) {
            return (gSunHalf == 1) ? 2.0f : 1.0f;
        }
        if (gSunHalf == 1) {
            return shadow;
        }
        if ((shadow < 1.0f) && (facing > 0.0f) && !onBanjo &&
            ((gSunHalf == 2) || (shadow > 0.0f) || gSawLevelCutout) &&
            SunThroughCutout(ViewToWorldPoint(start), normalize(ViewToWorldDirection(sunDirection)), shadow <= 0.0f)) {
            sunlight += float3(1.0f, 0.93f, 0.78f) * (0.9f * facing * (1.0f - shadow) * near);
        }
    }
#else
    const int Steps = 24;
    [loop] for (int i = 0; i < Steps; i++) {
        // Steps grow with distance, so close shadows are sharp and long ones still reach.
        const float t = (float(i) + jitter) / float(Steps);
        const float travelled = reach * t * t + 1.0f;
        const float3 p = start + sun * travelled;
        if (p.z > -1.0f) {
            break;
        }
        const float2 ndc = float2(p.x * gConstants.projection.x / -p.z, p.y * gConstants.projection.y / -p.z);
        if (any(abs(ndc) > 1.0f)) {
            break;
        }
        const int2 at = int2(float2(ndc.x * 0.5f + 0.5f, 0.5f - ndc.y * 0.5f) * size);
        const float sceneDepth = LoadDepth(at);
        if (sceneDepth >= 0.99999f) {
            continue;
        }
        const float3 occluder = ViewPosition(at, sceneDepth);
        const float inFront = -p.z - (-occluder.z);
        // Something is in front of the step by no more than a thing's thickness. A fixed thickness: one that
        // grew along the ray let a character's outline smear into a long dark block behind them.
        const float thickness = 45.0f + distance * 0.01f;
        if ((inFront > bias) && (inFront < thickness)) {
            if (skipBanjo) {
                const float3 world = float3(dot(occluder, gConstants.worldX.xyz) + gConstants.worldX.w,
                    dot(occluder, gConstants.worldY.xyz) + gConstants.worldY.w, dot(occluder, gConstants.worldZ.xyz) + gConstants.worldZ.w);
                const float2 across = world.xz - banjo.xz;
                if ((dot(across, across) < 80.0f * 80.0f) && (world.y > banjo.y - 5.0f) && (world.y < banjo.y + 180.0f)) {
                    continue;
                }
            }
            // Softer the further the shadow falls from what casts it, and fading in over the first hits so
            // the edge is a soft gradient rather than a dotted line.
            shadow = min(1.0f, shadow + (1.0f - t * 0.6f) * lerp(0.5f, 0.2f, softness));
            if (shadow >= 0.99f) {
                break;
            }
        }
    }
    // The sun shadow map: everything solid casts, on screen or not. Looked up a little off the surface, a few
    // texels around (wider the softer the shadows), fading out towards the map's edges where the screen-space
    // shadows above carry on alone.
    if (gConstants.shadows.y < 0.0f) {
        const SunMapFrame nearFrame = SUN_MAP_FRAME(gConstants);
        const SunMapFrame farFrame = MakeSunMapFarFrame(nearFrame);
        const float3 worldNormal = normalize(SunMapWorldDirection(nearFrame, normal));
        const float3 worldCenter = WorldPosition(center);
        float nearCover = 0.0f;
        float farCover = 0.0f;
        const float nearShadow = SunMapLookup(nearFrame, 0, worldCenter, worldNormal, distance, softness, jitter, nearCover);
        // Past the near map's edge the far map, over the whole level, carries on.
        const float farShadow = (nearCover < 1.0f) ? SunMapLookup(farFrame, int(nearFrame.size), worldCenter, worldNormal, distance, softness, jitter, farCover) : 0.0f;
        const float mapShadow = nearShadow * nearCover + farShadow * farCover * (1.0f - nearCover);
        shadow = max(shadow, mapShadow);
        if (mapView) {
            return ((nearCover > 0.0f) || (farCover > 0.0f)) ? (1.0f - 0.9f * mapShadow) : 0.5f;
        }
    }
#endif
    // The side turned from the sun darkens over a wider turn the softer the shadows.
    const float turnedAway = saturate(-facing * lerp(4.0f, 1.25f, softness)) * lerp(0.6f, 0.45f, softness);
    return 1.0f - gConstants.shadows.x * 0.55f * near * max(shadow, turnedAway);
}

// Rim light and Toon shading share ambientOcclusion.w, packed as rim light (0 to 1) + 2 * (the level's toon shading
// in hundredths + 101 * the characters' toon shading in hundredths).
float ToonPacked() {
    return floor(max(gConstants.ambientOcclusion.w, 0.0f) * 0.5f + 1e-4f);
}

// Toon shading of the level.
float ToonWorldStrength() {
    const float packed = ToonPacked();
    return (packed - 101.0f * floor((packed + 0.5f) / 101.0f)) / 100.0f;
}

// Toon shading of characters and other models (the water mask marks them).
float ToonCharacterStrength() {
    return floor((ToonPacked() + 0.5f) / 101.0f) / 100.0f;
}

// Either of the two is on.
float ToonStrength() {
    return max(ToonWorldStrength(), ToonCharacterStrength());
}

float RimStrength() {
    return max(gConstants.ambientOcclusion.w, 0.0f) - 2.0f * floor(max(gConstants.ambientOcclusion.w, 0.0f) * 0.5f + 1e-4f);
}

// Toon shading (technique after nekotogd's CC0 Godot toon shader): the lit scene's brightness is split into a few flat bands with soft steps between them (the
// light/shadow split of cel-shading shaders, a smoothstep on the lighting term), the shadow side
// taking a cool tint and the lit side a warm one, with colour kept. strength blends from the game's picture.
float3 ToonShade(float3 scene, float strength) {
    const float luma = dot(scene, float3(0.299f, 0.587f, 0.114f));
    const float step1 = smoothstep(0.16f, 0.22f, luma);
    const float step2 = smoothstep(0.42f, 0.48f, luma);
    const float step3 = smoothstep(0.72f, 0.78f, luma);
    const float banded = 0.2f + 0.3f * step1 + 0.3f * step2 + 0.2f * step3;
    const float3 tint = lerp(float3(0.78f, 0.84f, 1.0f), float3(1.0f, 0.97f, 0.9f), saturate(step1 * 0.5f + step2 * 0.5f));
    const float3 chroma = scene / max(luma, 0.02f);
    // Colour is pulled halfway to its own average so bands read as flat paint, not as darker texture.
    const float3 flatChroma = lerp(chroma, float3(1.0f, 1.0f, 1.0f), 0.2f);
    return lerp(scene, min(flatChroma * banded * tint * 1.1f, 1.5f), strength);
}

// Rim light: near the edge of something in front of what's behind it, the more the surface turns away
// from the camera the more it is lit, fading out with distance so far hills and the skyline stay as
// they are.
float RimLight(int2 pixel, float depth) {
    const float3 center = ViewPosition(pixel, depth);
    const float distance = -center.z;
    const float near = saturate(1.0f - (distance - 1500.0f) / 2500.0f);
    if (near <= 0.0f) {
        return 0.0f;
    }

    // A soft band inside the silhouette, about four pixels per 540 rows wide: the share of samples
    // around the pixel that land on something further behind, nearer ones counting more.
    const float reach = max(3.0f, gConstants.projection.w / 135.0f);
    float behind = 0.0f;
    float total = 0.0f;
    [unroll] for (int r = 1; r <= 2; r++) {
        const float w = 3.0f - float(r);
        [unroll] for (int i = 0; i < 8; i++) {
            const float angle = (float(i) + 0.5f * float(r)) * 0.785398163f;
            const int2 offset = int2(round(float2(cos(angle), sin(angle)) * reach * float(r) / 2.0f));
            const float neighbour = -ViewPositionAt(pixel + offset).z;
            behind += w * saturate(((neighbour - distance) / distance - 0.04f) * 6.0f);
            total += w;
        }
    }
    const float edge = saturate(behind / total * 3.0f);
    if (edge <= 0.0f) {
        return 0.0f;
    }

    // Surfaces turned away from the camera take the most; tops that face up (the ground, ledges) don't.
    const float3 normal = ViewNormal(pixel, center);
    const float facing = saturate(dot(normal, normalize(-center)));
    const float fresnel = pow(1.0f - facing, 2.0f);
    const float notUp = 1.0f - saturate((normal.y - 0.45f) * 2.5f);
    return RimStrength() * edge * (0.25f + 0.75f * fresnel) * notUp * near;
}

// Banjo's distance in front of the camera (his middle, a little above his feet), or 0 when there is no Banjo:
// his world position taken back through the view-to-world rows.
float BanjoDistance() {
    if (gConstants.rippleAge.w < -1e8f) {
        return 0.0f;
    }
    const float3 a = gConstants.worldX.xyz, b = gConstants.worldY.xyz, c = gConstants.worldZ.xyz;
    const float3 d = float3(gConstants.rippleX.w - gConstants.worldX.w, gConstants.rippleAge.w + 50.0f - gConstants.worldY.w,
        gConstants.rippleZ.w - gConstants.worldZ.w);
    const float det = dot(a, cross(b, c));
    if (abs(det) < 1e-8f) {
        return 0.0f;
    }
    const float3 v = (d.x * cross(b, c) + d.y * cross(c, a) + d.z * cross(a, b)) / det;
    return -v.z;
}

// Depth of field: the nearest thing in a small box at the middle of the picture is in focus (or Banjo, for the
// gameplay one, unless he is too close to the camera, as in first person), and the picture blurs more the
// further a pixel's distance is from it, up to a radius set by the strength.
// The distance in focus: the same for the whole picture, so the table pass works it out once a frame (row 2 of
// the fireflies' table) and the pixels read it.
float DepthOfFieldFocus(bool onBanjo) {
    const float2 size = gConstants.projection.zw;
    float focus = onBanjo ? BanjoDistance() : 0.0f;
    if (focus < 80.0f) {
        const int spacing = int(max(1.0f, size.y / 90.0f));
        focus = 1e9f;
        [unroll] for (int y = -2; y <= 2; y++) {
            [unroll] for (int x = -2; x <= 2; x++) {
                const int2 probe = int2(size * 0.5f) + int2(x, y) * spacing;
                focus = min(focus, -ViewPositionAt(probe).z);
            }
        }
    }
    return focus;
}

#ifndef FIREFLY_TABLE
float3 DepthOfField(int2 pixel, float distance, float strength, bool onBanjo) {
    const float2 size = gConstants.projection.zw;
    const float focus = gFireflies.Load(int3(0, 2, 0)).x;

    const float3 sharp = gColor.Load(int3(pixel, 0)).rgb;
    const float maxRadius = strength * size.y / 80.0f;
    const float coc = saturate(abs(distance - focus) / max(focus, 1.0f)) * maxRadius;
    if (coc < 0.75f) {
        return sharp;
    }

    const int taps = 24;
    float3 sum = sharp;
    float weight = 1.0f;
    [loop] for (int i = 1; i <= taps; i++) {
        const float t = float(i) / float(taps);
        const float angle = float(i) * 2.39996323f;
        const int2 tapPixel = clamp(pixel + int2(round(float2(cos(angle), sin(angle)) * sqrt(t) * coc)), int2(0, 0), int2(size) - 1);
        // Something sharp in front of the focus doesn't bleed into the blurred background behind it.
        const float tapDistance = -ViewPositionAt(tapPixel).z;
        const float tapCoc = saturate(abs(tapDistance - focus) / max(focus, 1.0f)) * maxRadius;
        const float w = (tapDistance < distance) ? saturate(tapCoc / max(coc, 1e-3f)) : 1.0f;
        sum += gColor.Load(int3(tapPixel, 0)).rgb * w;
        weight += w;
    }

    return sum / weight;
}
#endif

#ifdef FIREFLY_TABLE
// The fireflies' table: one column a firefly, row 0 its place and row 1 its brightness (see FireflyPlace), and in
// row 2 the depth of field's focus distance.
float4 PSMain(in float4 pos : SV_Position, in float2 uv : TEXCOORD0) : SV_TARGET {
    const int2 pixel = int2(pos.xy);
    if (pixel.y == 2) {
        return float4((gConstants.bloom.y != 0.0f) ? DepthOfFieldFocus(gConstants.bloom.y < 0.0f) : 0.0f, 0.0f, 0.0f, 0.0f);
    }
    float3 tint;
    if (!DayTint(tint) || ((DayPacked() & 1u) == 0u) || (DayNight(tint) <= 0.0f) || (gConstants.rippleAge.w < -1e8f)) {
        return 0.0f;
    }
    float4 place;
    float weight;
    if (!FireflyPlace(pixel.x, place, weight)) {
        return 0.0f;
    }
    return (pixel.y == 0) ? place : float4(weight, 0.0f, 0.0f, 0.0f);
}
#elif defined(INDIRECT_PASS)
#ifdef RAY_TRACED
// Ray traced denoising: where a world position was in the view the history was drawn from (view space).
float3 HistoryView(float3 world) {
    const float4 x = DenoiseRow(0u), y = DenoiseRow(1u), z = DenoiseRow(2u);
    const float3 d = world - float3(x.w, y.w, z.w);
    return float3(x.x * d.x + y.x * d.y + z.x * d.z, x.y * d.x + y.y * d.y + z.y * d.z, x.z * d.x + y.z * d.y + z.z * d.z);
}

// Ray traced denoising: a band's new rays (raw) blended into what the same spot of the world held in the pass before. The spot
// is followed as the camera moves (into the history's view, then its texels), and the history is used only from texels that
// were the same surface (their distance then, the fourth band, as far as this spot is now): newly seen ground, and whatever
// moved across it, start from their new rays. Each frame keeps most of the past (bounce light and occlusion the most, lamps
// the least, as their fires flicker), less round the player, whose own shadow moves with him.
float4 DenoiseBlend(int2 halfPixel, int band, float4 raw) {
    if (DenoiseRow(4u).y < 0.5f) {
        return raw;
    }
    const int2 halfSize = TracedHalfSize();
    const int2 pixel = halfPixel * 2;
    const float depth = LoadDepth(pixel);
    if (depth >= 0.99999f) {
        return raw;
    }
    const float3 world = ViewToWorldPoint(ViewPosition(pixel, depth));
    const float3 before = HistoryView(world);
    if (before.z > -1.0f) {
        return raw;
    }
    const float4 projection = DenoiseRow(3u);
    const float2 ndc = before.xy * projection.xy / -before.z;
    const float2 beforePixel = float2((ndc.x + 1.0f) * 0.5f * projection.z, (1.0f - ndc.y) * 0.5f * projection.w);
    // A texel stands for the pixel at twice its place (that pixel's centre at 2q + 0.5).
    const float2 at = (beforePixel - 0.5f) * 0.5f;
    const int2 corner = int2(floor(at));
    const float2 f = at - float2(corner);
    const float expected = -before.z;
    const float tolerance = max(expected * 0.04f, 4.0f);
    float4 sum = 0.0f;
    float weight = 0.0f;
    [unroll] for (int k = 0; k < 4; k++) {
        const int2 step = int2(k & 1, k >> 1);
        const int2 q = corner + step;
        if (any(q < 0) || any(q >= halfSize)) {
            continue;
        }
        const float then = gHistory.Load(int3(q.x, q.y + halfSize.y * 3, 0)).r;
        if (abs(then - expected) > tolerance) {
            continue;
        }
        const float2 b = lerp(1.0f - f, f, float2(step));
        const float w = b.x * b.y;
        sum += gHistory.Load(int3(q.x, q.y + halfSize.y * band, 0)) * w;
        weight += w;
    }
    if (weight < 0.25f) {
        return raw;
    }
    const float4 history = sum / weight;
    float keepNew = (band == 0) ? 0.1f : ((band == 1) ? 0.15f : 0.25f);
    if (gConstants.rippleAge.w > -1e8f) {
        const float2 across = world.xz - float2(gConstants.rippleX.w, gConstants.rippleZ.w);
        if ((dot(across, across) < 300.0f * 300.0f) && (abs(world.y - gConstants.rippleAge.w - 60.0f) < 300.0f)) {
            keepNew = max(keepNew, 0.5f);
        }
    }
    float4 result = lerp(history, raw, keepNew);
    // The sun band's 2 (enclosed: in shade whatever the rays say) is a mark, not a share of rays: it is never blended.
    if ((band == 1) && ((raw.a > 1.5f) || (history.a > 1.0f))) {
        result.a = raw.a;
    }
    return result;
}
#endif

// The indirect pass, at half size: GTAO's visibility (a) and SSGI's light (rgb) for the scene pixel at twice its
// own, one GTAO slice and two SSGI rays a pixel, turned through each 4x4 block (IndirectCell) for IndirectAt to
// gather.
float4 IndirectRaw(float4 pos) {
#ifdef RAY_TRACED
    // The lower bands (drawn only with Half-resolution ray tracing): the light beams and the sun shadow, then the
    // lamps' traced light (TracedHalfShadow, TracedHalfBeams, TracedHalfLamp).
    const int2 halfSize = TracedHalfSize();
    if (int(pos.y) >= halfSize.y * 2) {
        const int2 lampPixel = int2(int(pos.x), int(pos.y) - halfSize.y * 2) * 2;
        const float lampDepth = LoadDepth(lampPixel);
        float3 lamps = 0.0f;
        if ((lampDepth < 0.99999f) && (gConstants.view.x < 1.5f)) {
            const float3 lampCenter = ViewPosition(lampPixel, lampDepth);
            LightShadows(lampPixel, lampCenter, ViewNormal(lampPixel, lampCenter), lamps);
        }
        return float4(lamps, 1.0f);
    }
    if (int(pos.y) >= halfSize.y) {
        const int2 lowerPixel = int2(int(pos.x), int(pos.y) - halfSize.y) * 2;
        const float lowerDepth = LoadDepth(lowerPixel);
        float4 lower = float4(TracedBeams(lowerPixel, lowerDepth), 0.0f);
        // The sun's shadows only at Half resolution (at Medium the band is the beams' alone).
        if (HalfTraced() && (lowerDepth < 0.99999f) && (gConstants.shadows.x > 0.0f)) {
            const float3 lowerCenter = ViewPosition(lowerPixel, lowerDepth);
            float3 unused = 0.0f;
            gSunHalf = 1;
            lower.a = SunShadow(lowerPixel, lowerCenter, ViewNormal(lowerPixel, lowerCenter), unused);
            gSunHalf = 0;
        }
        return lower;
    }
#endif
    const int2 halfPixel = int2(pos.xy);
    const int2 pixel = halfPixel * 2;
    const float depth = LoadDepth(pixel);
    if (depth >= 0.99999f) {
        return float4(0.0f, 0.0f, 0.0f, 1.0f);
    }
    const float3 center = ViewPosition(pixel, depth);
    float3 normal = ViewNormal(pixel, center);
    const uint cell = IndirectCell(halfPixel);
    const float jitter = InterleavedNoise(halfPixel);
    float4 result = float4(0.0f, 0.0f, 0.0f, 1.0f);
#ifdef RAY_TRACED
    // Banjo's fur: its rays round the smoothed normal (see the main pass).
    if ((BanjoSmoothRadius() > 0) && OnBanjoTraced(center)) {
        normal = SmoothedNormal(pixel, center, normal, BanjoSmoothRadius());
    }
    if (SsgiStrength() > 0.0f) {
        float2 distances;
        result.rgb = TracedGI(center, normal, cell, distances);
        if (AoStrength() > 0.0f) {
            result.a = OcclusionFrom(distances);
        }
    }
    else if (AoStrength() > 0.0f) {
        result.a = TracedOcclusion(center, normal, cell);
    }
#else
    if (AoStrength() > 0.0f) {
        result.a = GroundTruthOcclusion(pixel, center, normal, cell, jitter);
    }
    if (SsgiStrength() > 0.0f) {
        result.rgb = ScreenSpaceGI(center, normal, cell);
    }
#endif
    return result;
}

float4 PSMain(in float4 pos : SV_Position, in float2 uv : TEXCOORD0) : SV_TARGET {
#ifdef RAY_TRACED
    // Ray traced denoising: each band blended into the pass before's, and the fourth band each texel's distance for the next.
    if (DenoiseOn()) {
        const int2 halfSize = TracedHalfSize();
        const int band = min(int(pos.y) / halfSize.y, 3);
        const int2 halfPixel = int2(int(pos.x), int(pos.y) - band * halfSize.y);
        if (band == 3) {
            const float depth = LoadDepth(halfPixel * 2);
            return float4((depth < 0.99999f) ? -ViewPosition(halfPixel * 2, depth).z : -1.0f, 0.0f, 0.0f, 0.0f);
        }
        return DenoiseBlend(halfPixel, band, IndirectRaw(pos));
    }
#endif
    return IndirectRaw(pos);
}
#else
float4 PSMain(in float4 pos : SV_Position, in float2 uv : TEXCOORD0) : SV_TARGET {
    const int2 pixel = int2(pos.xy);
    const float depth = LoadDepth(pixel);

    // F8 compare: the effects only on the left half, a line down the middle.
    if (gConstants.view.y < 0.0f) {
        const float middle = gConstants.projection.z * 0.5f;
        if (abs(pos.x - middle) < max(1.0f, gConstants.projection.w / 540.0f)) {
            return float4(1.0f, 1.0f, 1.0f, 0.0f);
        }
        if (pos.x >= middle) {
            return float4(0.0f, 0.0f, 0.0f, 1.0f);
        }
    }

    // Debug views of GTAO's visibility (white open, dark occluded), SSGI's light, and screen-space reflections: the
    // reflection where they show (red where the ray found nothing on screen), the dimmed scene elsewhere.
    // Debug view of the traced scene: a ray from the eye to each pixel's surface, green where it meets that surface,
    // blue where it passes through (not in the traced scene: light goes through it), red where something traced
    // stands in front of it; over the scene, dimmed. Grey without ray tracing.
    if (gConstants.view.x > 21.5f) {
        const float3 scene = gColor.Load(int3(pixel, 0)).rgb;
        const float grey = dot(scene, float3(0.299f, 0.587f, 0.114f)) * 0.5f + 0.1f;
        if (depth >= 0.99999f) {
            return float4(grey.xxx * 0.5f, 0.0f);
        }
#ifdef RAY_TRACED
        const float3 surface = ViewPosition(pixel, depth);
        const float distance = length(surface);
        const float tolerance = max(distance * 0.02f, 8.0f);
        // The ray reads the textures as the shadow rays do: a cut-out's clear texels let it through (blue there), its
        // solid ones show yellow; solid draws green. With the textures readable, the tint is shaded by the texel's
        // brightness, so a grate's holes show as the rays see them.
        RayDesc ray;
        ray.Origin = ViewToWorldPoint(float3(0.0f, 0.0f, 0.0f));
        ray.Direction = ViewToWorldDirection(surface / distance);
        ray.TMin = 0.0f;
        ray.TMax = distance + tolerance;
        RayQuery<RAY_FLAG_FORCE_NON_OPAQUE | RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES> query;
        query.TraceRayInline(gSceneBVH, 0, 0xFFu, ray);
        while (query.Proceed()) {
            if (query.CandidateType() == CANDIDATE_NON_OPAQUE_TRIANGLE) {
                const uint geometry = RayGeometryOf(query.CandidateInstanceID(), query.CandidateGeometryIndex());
                if (((RayGeometryFlags(geometry) & 1u) != 0u) && !RayCutoutSolid(geometry, query.CandidatePrimitiveIndex(), query.CandidateTriangleBarycentrics())) {
                    continue;
                }
                query.CommitNonOpaqueTriangleHit();
            }
        }
        // The level's lights (lamps, fires): magenta round each, brighter nearer, so they can be found against their fittings.
        {
            const float3 world = ViewToWorldPoint(surface);
            const uint lightCount = uint(asfloat(gLights.Load(0)) + 0.5f);
            for (uint i = 0u; i < lightCount; i++) {
                const float4 light = asfloat(gLights.Load4(16u * (i + 4u)));
                const float near = length(world - light.xyz);
                if (near < 60.0f) {
                    return float4(float3(1.0f, 0.1f, 1.0f) * (1.0f - near / 80.0f), 0.0f);
                }
            }
        }
        float3 tint = float3(0.2f, 0.4f, 1.0f);
        if (query.CommittedStatus() == COMMITTED_TRIANGLE_HIT) {
            const float t = query.CommittedRayT();
            const uint geometry = RayGeometryOf(query.CommittedInstanceID(), query.CommittedGeometryIndex());
            const uint flags = RayGeometryFlags(geometry);
            if (t < distance - tolerance) {
                tint = float3(1.0f, 0.2f, 0.2f);
            }
            else {
                tint = ((flags & 1u) != 0u) ? float3(1.0f, 0.9f, 0.2f) : float3(0.3f, 1.0f, 0.3f);
                if (RayTexturesOn() && ((flags & 2u) != 0u)) {
                    const float3 texel = RayTexel(geometry, query.CommittedPrimitiveIndex(), query.CommittedTriangleBarycentrics()).rgb;
                    return float4(tint * (0.25f + 0.75f * dot(texel, float3(0.299f, 0.587f, 0.114f))), 0.0f);
                }
            }
        }
        return float4(tint * grey * 1.6f, 0.0f);
#else
        return float4(grey.xxx, 0.0f);
#endif
    }
    if (gConstants.view.x > 18.5f) {
        if (depth >= 0.99999f) {
            return float4(0.0f, 0.0f, 0.0f, 0.0f);
        }
        const float3 center = ViewPosition(pixel, depth);
        const float3 normal = ViewNormal(pixel, center);
        if (gConstants.view.x < 19.5f) {
            return float4(IndirectAt(pixel, center, normal).aaa, 0.0f);
        }
        if (gConstants.view.x < 20.5f) {
            return float4(IndirectAt(pixel, center, normal).rgb * (SsgiStrength() * 2.0f), 0.0f);
        }
        const float3 scene = gColor.Load(int3(pixel, 0)).rgb;
#ifdef RAY_TRACED
        if (!ReflectiveAt(pixel, depth) && (MaterialShine(center, 0.0f) <= 0.0f)) {
#else
        if (!ReflectiveAt(pixel, depth)) {
#endif
            return float4(dot(scene, float3(0.299f, 0.587f, 0.114f)).xxx * 0.25f, 0.0f);
        }
#ifdef RAY_TRACED
        const float4 reflection = (RayBrdfRoughness() > 0.0f) ? TracedRoughReflection(pixel, center, normal, RayBrdfRoughness()) : TracedReflection(pixel, center, normal);
#else
        const float4 reflection = ScreenSpaceReflection(pixel, center, normal);
#endif
        return float4(lerp(float3(0.6f, 0.0f, 0.0f), reflection.rgb, reflection.a), 0.0f);
    }

    // Debug views of the depth: distance (near white, far dark, sky blue) and the normals from it.
    if (gConstants.view.x > 3.5f) {
        float3 surface, normal;
        const float amount = (gConstants.water.y > 0.5f) ? WaterAmount(pixel, depth, surface, normal) : 0.0f;
        float waterDepth;
        const bool isWater = (gConstants.water.y > 0.5f) && LoadWater(pixel, waterDepth);
        // Falls purple, ice blue.
        const bool isFall = !isWater && (gConstants.water.y > 0.5f) && LoadFall(pixel, waterDepth);
        const bool isIce = !isWater && !isFall && (gConstants.water.y > 0.5f) && IceAt(pixel, depth, waterDepth);
        return float4(isWater ? float3(1.0f, amount, 0.2f) : (isFall ? float3(0.6f, 0.2f, 0.8f) : (isIce ? float3(0.2f, 0.5f, 1.0f) : float3(0.15f, 0.15f, 0.15f))), 0.0f);
    }
    if (gConstants.view.x > 1.5f) {
        if (depth >= 0.99999f) {
            return float4(0.3f, 0.5f, 1.0f, 0.0f);
        }
        const float3 center = ViewPosition(pixel, depth);
        if (gConstants.view.x < 2.5f) {
            return float4(exp(-length(center) / 3000.0f).xxx, 0.0f);
        }
        return float4(ViewNormal(pixel, center) * 0.5f + 0.5f, 0.0f);
    }

    // Bloom: the blurred bright parts of the scene, added on top.
    float3 bloom = 0.0f;
    if (gConstants.bloom.x > 0.0f) {
        bloom = gBloom.SampleLevel(LinearSampler, uv, 0).rgb * gConstants.bloom.x;
    }
    float3 dayTint;
    const bool daytime = DayTint(dayTint);
    // The glow of what was bright before the tint dims with it.
    bloom *= dayTint;
    if (daytime && (gConstants.view.x < 1.5f)) {
        const float3 weather = DayWeather();
        bloom += (DayFlare(pixel, dayTint) + DayFireflies(pixel, depth, dayTint)) * (1.0f - weather.x) + DayRain(pixel, depth, dayTint, weather.x) + DayRainSplashes(pixel, depth, dayTint, weather.x) +
            DayDew(pixel, depth, dayTint, gColor.Load(int3(pixel, 0)).rgb);
    }
    // Light shafts are added the same way.
    if ((DayWeather().y > 0.0f) && (gConstants.view.x < 1.5f)) {
        // Less on the sky itself, so the beams show over the scenery rather than the sky washing out.
        bloom += LightShafts(pixel) * ((depth >= 0.99999f) ? 0.4f : 1.0f);
    }
    if (!daytime && (depth >= 0.99999f) && HeldSunShown() && (gConstants.view.x < 1.5f)) {
        bloom += HeldSun(pixel);
    }

    // With depth of field the pass draws the blurred scene itself (a = 0), with the other effects on it.
    const bool blur = (gConstants.bloom.y != 0.0f) && (gConstants.view.x < 0.5f);
    // Eye adaptation also draws the scene itself.
    const bool redraw = (blur || (gConstants.bloom.z > 0.0f) || (gConstants.fog.w > 0.0f) || (gConstants.view.w > 0.0f) || (gConstants.water.x > 0.0f) || (gConstants.water.y > 1.1f) || (gConstants.water.z > 0.0f) || (gConstants.water.w > 0.0f) || daytime || (VolBits() != 0u) || (SsgiStrength() > 0.0f) || (SsrStrength() > 0.0f) || (ToonStrength() > 0.0f) || RayPbrOn() || (RaySssStrength() > 0.0f) || (RayRelight() > 0.0f) || (PointLampCount() > 0u)) && (gConstants.view.x < 0.5f);

    if (depth >= 0.99999f) {
        // The sky takes most of the fog, so it meets the fogged scenery without a hard edge.
        const float skyFog = gConstants.fog.x * 0.75f;
        if (gConstants.view.x > 0.5f) {
            return float4(1.0f, 0.0f, 1.0f, 0.0f);
        }
        if (redraw) {
            float3 scene = blur ? DepthOfField(pixel, -ViewPosition(pixel, depth).z, abs(gConstants.bloom.y), gConstants.bloom.y < 0.0f) : gColor.Load(int3(pixel, 0)).rgb;
            if (daytime) {
                scene = DaySky(scene, pixel, dayTint);
                scene = DayLensDrops(scene, pixel, dayTint, DayWeather().x);
            }
            else if (VolCloudType() > 0u) {
                scene = VolSky(scene, pixel);
            }
            if (VolBits() != 0u) {
                scene = VolScatter(scene, pixel, 6000.0f, daytime ? dayTint : float3(1.0f, 1.0f, 1.0f));
            }
            if (gConstants.bloom.z > 0.0f) {
                scene = Adapt(scene);
            }
            if (gConstants.fog.w > 0.0f) {
                scene = Underwater(scene, 1e6f);
            }
            return float4(scene * (1.0f - skyFog) + gConstants.fogColor.rgb * skyFog + bloom, 0.0f);
        }
        return float4(gConstants.fogColor.rgb * skyFog + bloom, 1.0f - skyFog);
    }

#ifdef RAY_TRACED
    // The radiance cache's writes: about one pixel in eight each frame notes the colour of the spot of the world it shows.
    if (redraw && HitColoursOn()) {
        const uint seed = uint(pixel.x) * 73856093u ^ uint(pixel.y) * 19349663u ^ uint(gConstants.view.z * 60.0f) * 83492791u;
        if (((seed * 2654435761u) >> 29) == 0u) {
            RadianceStore(ViewToWorldPoint(ViewPosition(pixel, depth)), gColor.Load(int3(pixel, 0)).rgb);
        }
    }
#endif
    float keep = 1.0f;
    // Light the level's lamps add (traced: LightShadows), on the scene's own colour.
    float3 lamp = 0.0f;
    const bool occlusion = AoStrength() > 0.0f;
    const bool globalIllumination = (SsgiStrength() > 0.0f) && redraw;
#ifdef RAY_TRACED
    // Ray Tracing Material Pick Mode: this surface's material, when it has one.
    RayPbr pbr = RayPbrNone();
    // How much light passes through this surface (traced subsurface scattering): a Ray Tracing Material pick's own, else
    // Graphics > Ray tracing's slider on the leaves and grass Parallax knows (materials 13 and 7).
    float subsurface = 0.0f;
    // (Not for every pixel when nothing in the scene could use what the surface ray finds.)
    if (redraw && (RayPbrOn() || ((RaySssStrength() > 0.0f) && RaySubsurfaceScene()))) {
        uint surfaceGeometry;
        if (SurfaceGeometry(ViewPosition(pixel, depth), surfaceGeometry)) {
            pbr = RayGeometryPbr(surfaceGeometry);
            const uint shape = RayGeometryMaterial(surfaceGeometry);
            subsurface = pbr.present ? pbr.subsurface : (((shape == 13u) || (shape == 7u)) ? RaySssStrength() : 0.0f);
        }
    }
    // Traced, the surfaces Parallax marks metal, tiles or smooth reflect too, as much as their material does.
    const bool reflectionsWanted = ((SsrStrength() > 0.0f) || pbr.present) && redraw && (depth < 0.99999f);
    // (A grate's holes are left out of the shiny mask where it is drawn: RasterPS.)
    const bool masked = reflectionsWanted && ReflectiveAt(pixel, depth);
    // A shiny-list texture with no material of its own reflects fully.
    const float shine = reflectionsWanted ? MaterialShine(ViewPosition(pixel, depth), masked ? 1.0f : 0.0f) : 1.0f;
    const bool reflections = reflectionsWanted && (masked || (shine > 0.0f) || pbr.present);
#else
    const RayPbr pbr = RayPbrNone();
    const float subsurface = 0.0f;
    const float shine = 1.0f;
    const bool reflections = (SsrStrength() > 0.0f) && redraw && ReflectiveAt(pixel, depth);
#endif
    const bool sunShadows = (gConstants.shadows.x > 0.0f) && (gConstants.view.x < 1.5f);
    // Traced relighting: how much of the game's shading the traced light takes over here (not the sky, nor water, whose
    // colour is the water's and not its surface's), and how much of the sun is blocked (SunShadow).
    float relight = 0.0f;
    float sunBlocked = 0.0f;
#ifdef RAY_TRACED
    float waterAt;
    if (redraw && (depth < 0.99999f) && !LoadAnyWater(pixel, waterAt)) {
        relight = RayRelight();
    }
#endif
    // The surface's position and normal once for all of them (the normal reads four more depths).
    float3 center = 0.0f;
    float3 normal = float3(0.0f, 0.0f, 1.0f);
    // The indirect pass's GTAO visibility (a) and SSGI light (rgb) here.
    float4 indirect = float4(0.0f, 0.0f, 0.0f, 1.0f);
#ifdef RAY_TRACED
    const bool lightShadows = (gConstants.view.x < 1.5f);
#else
    const bool lightShadows = false;
#endif
    // Point Lights: the lamps light the surface where the pass draws the scene itself.
    const bool pointLamps = redraw && (PointLampCount() > 0u);
    if (occlusion || globalIllumination || reflections || sunShadows || lightShadows || pointLamps || (relight > 0.0f)) {
        center = ViewPosition(pixel, depth);
        normal = ViewNormal(pixel, center);
#ifdef RAY_TRACED
        // Not in a room or a cave: there the game's own light is the lamps' and the sun doesn't reach.
        if ((relight > 0.0f) && Enclosed(ViewToWorldPoint(center + normal * 4.0f))) {
            relight = 0.0f;
        }
#endif
#ifdef RAY_TRACED
        // Banjo's fur: its tufts' normals turn every pixel, so the traced rays on him were a different few a pixel
        // and crawled as he moved (L, 2026-10-20). There the normal is smoothed over his surface and the traced
        // light gathered wider, so the fur keeps its traced shading without the speckle.
        const bool onBanjo = OnBanjoTraced(center);
        if (onBanjo && (BanjoSmoothRadius() > 0)) {
            normal = SmoothedNormal(pixel, center, normal, BanjoSmoothRadius());
        }
#else
        const bool onBanjo = false;
#endif
        if (occlusion || globalIllumination) {
#ifdef RAY_TRACED
            indirect = IndirectAt(pixel, center, normal, onBanjo ? 1 + int(RtSmoothing() * 3.0f + 0.5f) : 0);
#else
            indirect = IndirectAt(pixel, center, normal);
#endif
        }
        if (occlusion) {
            // GTAO's visibility with its multi-bounce, from the scene's brightness here when the pass has the scene
            // (a mid grey otherwise). 50 is GTAO as it is; above that it is deepened, below it lightened.
            const float albedo = redraw ? saturate(dot(gColor.Load(int3(pixel, 0)).rgb, float3(0.299f, 0.587f, 0.114f))) : 0.5f;
            // On Banjo himself (above his feet, so the ground round them keeps its contact shading) a quarter as
            // much: his fur and limbs crowd each other, and full GTAO blackened him (L, 2026-10-21).
            const float3 world = ViewToWorldPoint(center);
#ifdef RAY_TRACED
            // Traced, only his model's own pixels: the capsule alone took in the grass and bumps round his feet, a ring
            // with its shading gone that went round with him (L, 2026-10-22).
            const bool banjoBody = onBanjo && (world.y > gConstants.rippleAge.w + 8.0f);
#else
            const bool banjoBody = InsideBanjo(world) && (world.y > gConstants.rippleAge.w + 8.0f);
#endif
            keep *= pow(saturate(MultiBounce(indirect.a, albedo)), AoStrength() * (banjoBody ? 0.5f : 2.0f));
        }
        if (sunShadows) {
#ifdef RAY_TRACED
            gSunHalf = HalfTraced() ? 2 : 0;
#endif
            const float sunKeep = SunShadow(pixel, center, normal, lamp);
            // SunShadow returns 1 - strength * 0.55 * blocked. Relit lights the surface by what gets through, so the
            // picture keeps the shadow only as much as it is not relit.
            sunBlocked = saturate((1.0f - sunKeep) / max(gConstants.shadows.x * 0.55f, 1e-3f));
            keep *= lerp(sunKeep, 1.0f, relight);
#ifdef RAY_TRACED
            gSunHalf = 0;
#endif
        }
#ifdef RAY_TRACED
        // Not tied to the sun: lamps and fires cast their own in caves and at night.
        if (lightShadows) {
            float3 lamps;
            gLampHalf = HalfTraced() ? 2 : 0;
            keep *= LightShadows(pixel, center, normal, lamps);
            gLampHalf = 0;
            lamp += HalfTraced() ? TracedHalfLamp(pixel, center, normal) : lamps;
            if (!onBanjo) {
                keep *= ModelShadow(center, normal);
            }
        }
#endif
        if (pointLamps) {
            lamp += PointLampsAt(center, normal);
        }
    }

    // Toon outlines: dark where the distance jumps against a neighbour (silhouettes against what's behind),
    // and along creases, where the surface folds away on both sides (ridges, the top edge of a cliff).
    if (gConstants.fogColor.w > 0.0f) {
        // Packed as strength + 2 * (quarters of thickness - 1).
        const float quarters = floor((gConstants.fogColor.w - 1e-3f) * 0.5f) + 1.0f;
        const float strength = gConstants.fogColor.w - 2.0f * (quarters - 1.0f);
        const float thickness = quarters * 0.25f;
        const float distance = -ViewPosition(pixel, depth).z;
        // About one pixel per 540 rows for each step of thickness, so the lines keep their weight at higher
        // resolutions.
        const float scale = max(gConstants.projection.w / 540.0f, 1.0f);
        const int step = max(1, int(round(scale * thickness)));
        float jump = 0.0f;
        [unroll] for (int i = 0; i < 8; i++) {
            const int2 direction = (i == 0) ? int2(1, 0) : (i == 1) ? int2(-1, 0) : (i == 2) ? int2(0, 1) : (i == 3) ? int2(0, -1) :
                (i == 4) ? int2(1, 1) : (i == 5) ? int2(-1, 1) : (i == 6) ? int2(1, -1) : int2(-1, -1);
            // The diagonals a little shorter, so the line is as thick at every angle.
            const int2 offset = (i < 4) ? direction * step : direction * max(1, int(round(float(step) * 0.7f)));
            const float neighbour = -ViewPositionAt(pixel + offset).z;
            jump = max(jump, (neighbour - distance) / distance);
            // Thick lines also look half as far, so thin things (posts, leaves) don't get a detached line.
            if (step >= 4) {
                const float near = -ViewPositionAt(pixel + offset / 2).z;
                jump = max(jump, (near - distance) / distance);
            }
        }
        float edge = saturate((jump - 0.05f) * 8.0f);
        // Creases: both neighbours across the pixel further away than a straight surface would put them.
        const int crease = max(1, int(round(scale)));
        const float left = -ViewPositionAt(pixel + int2(-crease, 0)).z, right = -ViewPositionAt(pixel + int2(crease, 0)).z;
        const float up = -ViewPositionAt(pixel + int2(0, -crease)).z, down = -ViewPositionAt(pixel + int2(0, crease)).z;
        const float bend = max(left + right - 2.0f * distance, up + down - 2.0f * distance) / distance;
        edge = max(edge, saturate((bend - 0.012f) * 40.0f) * 0.8f);
        keep *= 1.0f - strength * edge;
    }

#ifdef RAY_TRACED
    // Traced subsurface scattering: the sun's and a lamp's light through the back of the surface, and a soft coloured glow where
    // its shade would go flat dark (light that scattered inside).
    if (subsurface > 0.0f) {
        const float3 sssCenter = ViewPosition(pixel, depth);
        const float3 sssNormal = ViewNormal(pixel, sssCenter);
        lamp += TracedSubsurface(sssCenter, sssNormal) * subsurface + (1.0f - saturate(keep)) * (subsurface * 0.2f);
    }
#endif
    // Rim light: a soft warm-white light added along the edges.
    float3 rim = 0.0f;
    if (RimStrength() > 0.0f) {
        rim = float3(1.0f, 0.95f, 0.85f) * (0.9f * RimLight(pixel, depth));
    }
#ifdef RAY_TRACED
    // Traced light beams, added like the rim light (the fog still covers them).
    // (Off, the indirect pass draws no band of them to read.)
    if ((gConstants.view.x < 1.5f) && (asfloat(gLights.Load(16)) > 0.0f)) {
        // (No glow round the level's lights in the air: it showed as balls round every light, L 2026-10-21.)
        rim += BeamsHalf() ? TracedHalfBeams(pixel) : TracedBeams(pixel, depth);
    }
    // Ray Tracing Material Pick Mode's emissive: the surface's own colour, tinted by its albedo, added as light that shadows
    // and the traced lighting don't dim (and the bloom picks up).
    if (pbr.present && (pbr.emissive > 0.0f)) {
        rim += gColor.Load(int3(pixel, 0)).rgb * pbr.albedo * pbr.emissive;
    }
#endif

    // Fog thickens with distance from Banjo (from the camera when there is no Banjo) past its start,
    // approaching its strength, so moving the camera doesn't change how fogged things are.
    float fog = 0.0f;
    if (gConstants.fog.x > 0.0f) {
        const float3 position = ViewPosition(pixel, depth);
        float distance = length(position);
        if (gConstants.rippleAge.w > -1e8f) {
            const float3 world = float3(dot(position, gConstants.worldX.xyz) + gConstants.worldX.w,
                dot(position, gConstants.worldY.xyz) + gConstants.worldY.w, dot(position, gConstants.worldZ.xyz) + gConstants.worldZ.w);
            distance = length(world - float3(gConstants.rippleX.w, gConstants.rippleAge.w, gConstants.rippleZ.w));
        }
        fog = gConstants.fog.x * (1.0f - exp(-max(distance - float(uint(gConstants.fog.y) & 4095u) * 4.0f, 0.0f) / max(float(uint(gConstants.fog.z) & 4095u) * 4.0f, 1.0f)));
    }

    if (gConstants.view.x > 0.5f) {
        return float4(lerp(keep.xxx * 0.6f + rim + bloom, float3(0.0f, 0.4f, 1.0f), fog), 0.0f);
    }

    if (redraw) {
        float3 scene = blur ? DepthOfField(pixel, -ViewPosition(pixel, depth).z, abs(gConstants.bloom.y), gConstants.bloom.y < 0.0f) :
            (gConstants.view.w > 0.0f) ? HeatHaze(pixel, -ViewPosition(pixel, depth).z) : gColor.Load(int3(pixel, 0)).rgb;
        // Ray Tracing Material Pick Mode: the albedo tints the surface before anything lights it. A metal has no diffuse
        // colour of its own, only what it reflects (below).
        scene *= DiffuseAlbedo(pbr);
#ifdef RAY_TRACED
        if (relight > 0.0f) {
            scene = lerp(scene, Relit(pixel, center, normal, scene, sunBlocked), relight);
        }
#endif
        if (gConstants.water.z > 0.0f) {
            // The surface's own colour lit by it, and a little of it straight on, so dark corners take on the
            // colour of what is around them.
            const float3 bounce = BounceLight(pixel, depth) * gConstants.water.z;
            scene += scene * bounce * 1.2f + bounce * 0.12f;
        }
        if (globalIllumination) {
            // SSGI: the light arriving from the surfaces round about, times the surface's own colour (the scene
            // stands in for it). 50 is one bounce as it is.
#ifdef RAY_TRACED
            // Traced, the light is real and adds up (sky, sunlit ground, path tracing's hops): capped, and less on what
            // is already bright, so lit sand and snow don't blow out to white (L, 2026-10-21) while shade still fills.
            const float bright = dot(scene, float3(0.299f, 0.587f, 0.114f));
            scene += scene * min(indirect.rgb, 0.6f) * (SsgiStrength() * 2.0f * saturate(1.15f - bright * 1.1f));
#else
            scene += scene * indirect.rgb * (SsgiStrength() * 2.0f);
#endif
        }
        if (reflections) {
            // SSR: the reflected scene, more at grazing angles (Fresnel) and less in creases (GTAO's specular
            // occlusion, Lagarde and de Rousiers 2014, as the Unity GTAO does for its reflections). At 100 a
            // surface seen straight on is three quarters mirror, and fully at grazing angles.
#ifdef RAY_TRACED
            // Ray traced BRDF: every traced reflection over a GGX lobe, a material's own roughness where it has one.
            const float lobe = pbr.present ? pbr.roughness : RayBrdfRoughness();
            const float4 reflection = (lobe > 0.0f) ? TracedRoughReflection(pixel, center, normal, lobe) : TracedReflection(pixel, center, normal);
#else
            const float roughness = SsrRoughness();
            const float4 reflection = (roughness > 0.0f) ? StochasticReflection(pixel, center, normal, roughness) : ScreenSpaceReflection(pixel, center, normal);
#endif
            const float facing = saturate(dot(-normalize(center), normal));
            const float fresnel = 0.75f + 0.75f * pow(1.0f - facing, 2.0f);
            const float specularOcclusion = occlusion ? saturate(pow(facing + indirect.a, 0.5f) - 1.0f + indirect.a) : 1.0f;
            if (pbr.present) {
                // Production PBR: the reflected share is Schlick's Fresnel from the base reflectance, 4% for a dielectric and
                // the albedo for a metal (tinting what it reflects); a metal keeps only a sliver of diffuse, as much as its
                // reflection is trusted.
                const float baseReflectance = lerp(0.04f, 1.0f, pbr.metalness);
                const float schlick = baseReflectance + (1.0f - baseReflectance) * pow(1.0f - facing, 5.0f);
                scene *= lerp(1.0f, 0.12f, pbr.metalness * reflection.a);
                const float3 tint = lerp(1.0f, pbr.albedo, pbr.metalness);
                scene = lerp(scene, reflection.rgb * tint, saturate(schlick * reflection.a * specularOcclusion));
            } else {
                scene = lerp(scene, reflection.rgb, saturate(SsrStrength() * shine * fresnel * reflection.a * specularOcclusion));
            }
        }
        if (gConstants.water.y > 1.5f) {
            // Modern water in place of the game's: flat water over something further down gets the new water;
            // anything else the game drew as water (waterfalls, and the surface seen from under it) is put back
            // as the game drew it, from its colour and blending alpha.
            float waterDepth;
            if ((gConstants.water.y < 2.5f) && LoadWater(pixel, waterDepth)) {
                float3 surface, normal;
                const float amount = WaterAmount(pixel, depth, surface, normal);
                const float4 game = LoadWaterColor(pixel);
                const float3 original = lerp(scene, game.rgb, saturate(game.a));
                // The camera's height against the surface's: from under it the surface is seen from below.
                float3 flatSurface = ViewPosition(pixel, waterDepth);
                const bool fromBelow = gConstants.worldY.w < dot(flatSurface, gConstants.worldY.xyz) + gConstants.worldY.w;
                if (fromBelow) {
                    // Facing up in the world, whichever side the camera is on.
                    float3 n = normalize(gConstants.worldY.xyz);
                    const float flat = (amount > 0.0f) ? 1.0f : saturate((abs(dot(normal, n)) - 0.45f) * 4.0f);
                    scene = (flat > 0.0f) ? lerp(original, ModernWaterBelow(pixel, flatSurface, -n, scene), flat) : original;
                }
                else {
                    // Steep parts of a water draw (a stream going over a drop) become a waterfall when watery.
                    float3 back = original;
                    const float steep = (amount < 1.0f) ? SteepAt(pixel) : 0.0f;
                    if (steep > 0.0f) {
                        float3 tint;
                        const float watery = FallWatery(pixel, tint);
                        back = (watery > 0.0f) ? lerp(original, ModernFall(pixel, waterDepth, original, game), watery * steep) : original;
                    }
                    scene = (amount > 0.0f) ? lerp(back, StylisedWaterOn() ? StylisedWater(pixel, depth, surface, normal, scene) :
                        ModernWater(pixel, depth, surface, normal, scene), amount) : back;
                }
            }
            else if ((gConstants.water.y < 2.5f) && LoadFall(pixel, waterDepth)) {
                // A steep draw: a waterfall gets Modern water's own; anything else (light beams) is put back
                // as the game drew it.
                const float4 game = LoadWaterColor(pixel);
                const float3 original = lerp(scene, game.rgb, saturate(game.a));
                float3 tint;
                const float watery = FallWatery(pixel, tint);
                scene = (watery > 0.0f) ? lerp(original, ModernFall(pixel, waterDepth, original, game), watery) : original;
            }
            else if ((gConstants.rippleZ.z > 0.0f) && (depth < 0.99999f)) {
                // Under the water: caustics on what faces up below the surface.
                const float3 view = ViewPosition(pixel, depth);
                const float below = (gConstants.rippleAge.y > 0.5f) ? 300.0f : (gConstants.rippleAge.x - WorldPosition(view).y);
                scene *= 1.0f + 0.6f * gConstants.rippleZ.z * (StylisedWaterOn() ? StylisedCausticsAt(pixel, view, below) : CausticsAt(pixel, view, below));
            }
        }
        else if ((WaterReflectionStrength() > 0.0f) || (gConstants.water.w > 0.0f) || OriginalShoreFoamOn()) {
            float3 surface, normal;
            const float amount = WaterAmount(pixel, depth, surface, normal);
            if ((amount > 0.0f) && (gConstants.water.w > 0.0f)) {
                // Waves: the water seen through bends with the slope, and the slopes facing the light
                // brighten while those facing away darken, with a glint where the light reflects.
                float foam;
                const float3 waved = WaveNormal(surface, normal, gConstants.water.w, foam);
                const float3 bend = waved - normal;
                const float2 offset = float2(bend.x, bend.z) * (gConstants.projection.w * 0.04f) * saturate(600.0f / -surface.z);
                const int2 bent = clamp(int2(float2(pixel) + offset), int2(0, 0), int2(gConstants.projection.zw) - 1);
                float bentDepth;
                if (LoadWater(bent, bentDepth)) {
                    const float3 bentScene = (gConstants.view.w > 0.0f) ? scene : gColor.Load(int3(bent, 0)).rgb;
                    scene = lerp(scene, bentScene, amount);
                }
                const float3 light = normalize(normalize(gConstants.worldX.xyz) * 0.35f + normal * 0.8f - normalize(gConstants.worldZ.xyz) * 0.45f);
                const float shade = (dot(waved, light) - dot(normal, light)) * 0.6f;
                const float glint = pow(saturate(dot(reflect(normalize(surface), waved), light)), 48.0f);
                scene = scene * (1.0f + shade * amount) + float3(1.0f, 0.97f, 0.9f) * (glint * 0.5f * amount * saturate(gConstants.water.w * 2.0f));
                scene = lerp(scene, float3(0.92f, 0.95f, 0.97f), foam * 0.45f * amount);
                normal = waved;
            }
            if ((amount > 0.0f) && (WaterReflectionStrength() > 0.0f)) {
                const float4 reflection = WaterReflection(surface, normal);
                const float fresnel = 0.25f + 0.75f * pow(1.0f - saturate(dot(-normalize(surface), normal)), 3.0f);
                scene = lerp(scene, reflection.rgb, saturate(WaterReflectionStrength() * amount * fresnel * reflection.a));
            }
            float shoreDepth;
            // Not weighted by how much water there is: the shore is exactly where that runs out.
            if (OriginalShoreFoamOn() && LoadWater(pixel, shoreDepth) && (SteepAt(pixel) < 0.5f)) {
                scene = lerp(scene, float3(0.93f, 0.96f, 0.98f), OriginalShoreFoam(pixel, shoreDepth, depth) * 0.55f);
            }
        }
        // Ice reflects (Ice reflections): floors, walls and blocks of ice, each the way it faces (from the mask's
        // depths), with a soft wobble so it doesn't read as a mirror. Seen from above, the rays are bent into the
        // picture, so it reflects at every camera height. Seen low across it, the wobble is gentler (a small tilt
        // moves a grazing reflection a long way, which looked like waves) and the ice's own picture always shows
        // through, so it stays ice rather than turning into a water mirror.
        float iceDepth;
        const float iceStrength = IceReflectionStrength();
        if ((iceStrength > 0.0f) && IceAt(pixel, depth, iceDepth)) {
            const float3 iceSurface = ViewPosition(pixel, iceDepth);
            const float3 iceWorld = WorldPosition(iceSurface);
            float3 iceFacing = IceNormal(pixel, iceSurface);
#ifdef RAY_TRACED
            // Traced, the ice's own triangles say which way it faces wherever its depths can't.
            float3 iceTraced;
            if (SurfaceNormalTraced(iceSurface, iceTraced)) {
                iceFacing = iceTraced;
            }
#endif
            const float2 wobbleAt = (iceWorld.xz + float2(iceWorld.y, -iceWorld.y)) / 40.0f;
            const float2 wobble = float2(WaterNoise(wobbleAt), WaterNoise(wobbleAt + 17.0f)) - 0.5f;
            const float3 side = normalize(cross(iceFacing, (abs(iceFacing.x) < 0.9f) ? float3(1.0f, 0.0f, 0.0f) : float3(0.0f, 1.0f, 0.0f)));
            const float iceFacingView = saturate(dot(-normalize(iceSurface), iceFacing));
            const float wobbleAmount = 0.06f * lerp(0.25f, 1.0f, saturate(iceFacingView * 2.0f));
            const float3 iceNormal = normalize(iceFacing + (side * wobble.x + cross(iceFacing, side) * wobble.y) * wobbleAmount);
            const float4 iceReflection = WaterReflectionRay(iceSurface, iceNormal, true);
            const float iceFresnel = 0.4f + 0.6f * pow(1.0f - saturate(dot(-normalize(iceSurface), iceNormal)), 3.0f);
            scene = lerp(scene, iceReflection.rgb, min(saturate(iceStrength * iceFresnel * iceReflection.a), 0.6f));
        }
        if (daytime) {
            scene = DayWet(scene, pixel, depth);
            float wetDepth;
            const bool wet = (gConstants.water.y > 0.5f) && (LoadWater(pixel, wetDepth) || LoadFall(pixel, wetDepth) || IceAt(pixel, depth, wetDepth));
            scene = DayWorld(scene, dayTint, !wet);
            const float3 weather = DayWeather();
            scene = DayWeatherLight(scene, weather.x, weather.z, 0.3f);
        }
        // WIP volumetric mist and fog along the ray to the nearest thing at the pixel (the water and falls write no depth).
        if (VolBits() != 0u) {
            float volDepth = depth;
            float volWater;
            if ((gConstants.water.y > 0.5f) && LoadAnyWater(pixel, volWater)) {
                volDepth = min(volDepth, volWater);
            }
            scene = VolScatter(scene, pixel, length(ViewPosition(pixel, volDepth)) * length(gConstants.worldX.xyz), daytime ? dayTint : float3(1.0f, 1.0f, 1.0f));
        }
        if (daytime) {
            scene = DayLensDrops(scene, pixel, dayTint, DayWeather().x);
            rim *= dayTint;
        }
        if (ToonStrength() > 0.0f) {
            // The characters' strength where the mask has a character (drawn this frame: the constants leave it out otherwise).
            const float toon = ((ToonCharacterStrength() > 0.0f) && LoadCharacter(pixel)) ? ToonCharacterStrength() : ToonWorldStrength();
            if (toon > 0.0f) {
                scene = ToonShade(scene * (keep + lamp), toon) / max(keep + lamp, 0.001f);
            }
        }
        if (gConstants.bloom.z > 0.0f) {
            scene = Adapt(scene);
        }
        if (gConstants.fog.w > 0.0f) {
            scene = Underwater(scene * (keep + lamp) + rim, length(ViewPosition(pixel, depth)));
            return float4(scene * (1.0f - fog) + gConstants.fogColor.rgb * fog + bloom, 0.0f);
        }
        return float4((scene * (keep + lamp) + rim) * (1.0f - fog) + gConstants.fogColor.rgb * fog + bloom, 0.0f);
    }

    return float4(rim * (1.0f - fog) + gConstants.fogColor.rgb * fog + bloom, keep * (1.0f - fog));
}
#endif
