//
// RT64
//

// Include guard: SceneEffectsPS and SunShadowMapVS include this, and DXC on Windows can reach a file
// here by two spellings of its path (from a file beside it, and through -I).
#ifndef RT64_EXT_SHADERS_SUNSHADOWMAP_HLSLI
#define RT64_EXT_SHADERS_SUNSHADOWMAP_HLSLI

// Banjo-Tooie: the sun shadow map. The 3D world's own triangles are drawn again as seen from the sun into a
// depth map, so things outside the picture cast shadows too. Both that pass (SunShadowMapVS.hlsl) and the
// scene effects work out where the map lies from the same scene effects constants with this same code, so
// they always agree: a square of the world round the camera, a little ahead of it, square to the sun.

#include "shared/rt64_scene_effects.h"

// How far the map reaches is the Sun shadow distance setting: half the width of the square it covers, in world
// units, packed into shadows.y (SunMapHalfWidth). The square's middle sits ahead of the camera by 0.6 of that (of
// at most 6000), and the map reaches towards and away from the sun at least SunMapMinRange from its middle. The far
// map (SUN_SHADOW_MAP_FAR_HALF) is the same with its own half width: its pass is given that in shadows.y.
static const float SunMapMinRange = 8000.0f;

// The constants the map needs, copied out member by member. Passing the push constant buffer itself to a
// function makes the Windows build's DXC (1.7) load the whole buffer and emit invalid SPIR-V.
struct SunMapFrame {
    float4 worldX;
    float4 worldY;
    float4 worldZ;
    float4 sun;
    // Half the square's width, how far towards and away from the sun it reaches, its size in texels.
    float halfWidth;
    float range;
    float size;
    // The far map's middle stays put (SUN_SHADOW_MAP_FAR_CELL) instead of following the camera.
    bool fixedMiddle;
};

// shadows.y: |y| = the screen-space reach (under 1000) + 1000 * the map's half width in steps of
// SUN_SHADOW_MAP_HALF_STEP, + SUN_SHADOW_MAP_VIEW_FLAG for the headless map view; negative when the map was drawn.
float SunMapPacked(float y) {
    const float a = abs(y);
    return (a >= SUN_SHADOW_MAP_VIEW_FLAG - 0.5f) ? (a - SUN_SHADOW_MAP_VIEW_FLAG) : a;
}

bool SunMapView(float y) {
    return abs(y) >= SUN_SHADOW_MAP_VIEW_FLAG - 0.5f;
}

float SunMapReach(float y) {
    const float a = SunMapPacked(y);
    return a - 1000.0f * floor(a / 1000.0f);
}

float SunMapHalfWidth(float y) {
    const float steps = floor(SunMapPacked(y) / 1000.0f);
    return (steps > 0.5f) ? steps * SUN_SHADOW_MAP_HALF_STEP : SUN_SHADOW_MAP_DEFAULT_HALF;
}

SunMapFrame MakeSunMapFrame(float4 worldX, float4 worldY, float4 worldZ, float4 sun, float4 shadows) {
    SunMapFrame f;
    f.worldX = worldX;
    f.worldY = worldY;
    f.worldZ = worldZ;
    f.sun = sun;
    f.halfWidth = SunMapHalfWidth(shadows.y);
    f.range = max(SunMapMinRange, 1.5f * f.halfWidth);
    f.size = float(SunShadowMapSize(f.halfWidth));
    f.fixedMiddle = (f.halfWidth > SUN_SHADOW_MAP_FAR_HALF - 1.0f);
    return f;
}

#define SUN_MAP_FRAME(cb) MakeSunMapFrame((cb).worldX, (cb).worldY, (cb).worldZ, (cb).sun, (cb).shadows)

// The far map's frame, for the effects (its pass gets it from SUN_MAP_FRAME).
SunMapFrame MakeSunMapFarFrame(SunMapFrame nearFrame) {
    SunMapFrame f = nearFrame;
    f.halfWidth = SUN_SHADOW_MAP_FAR_HALF;
    f.range = max(SunMapMinRange, 1.5f * f.halfWidth);
    f.size = float(SUN_SHADOW_MAP_FAR_SIZE);
    f.fixedMiddle = true;
    return f;
}

float3 SunMapWorldDirection(SunMapFrame c, float3 d) {
    return float3(dot(d, c.worldX.xyz), dot(d, c.worldY.xyz), dot(d, c.worldZ.xyz));
}

// The map's axes in the world (across, up the map, towards the sun) and its middle.
void SunMapBasis(SunMapFrame c, out float3 across, out float3 up, out float3 towards, out float3 middle) {
    towards = normalize(SunMapWorldDirection(c, c.sun.xyz));
    across = (abs(towards.y) > 0.999f) ? float3(1.0f, 0.0f, 0.0f) : normalize(float3(towards.z, 0.0f, -towards.x));
    up = cross(towards, across);
    const float3 camera = float3(c.worldX.w, c.worldY.w, c.worldZ.w);
    if (c.fixedMiddle) {
        const float cell = SUN_SHADOW_MAP_FAR_CELL;
        middle = float3(floor(camera.x * (1.0f / cell) + 0.5f) * cell, 0.0f, floor(camera.z * (1.0f / cell) + 0.5f) * cell);
        return;
    }
    const float2 forward = -float2(c.worldX.z, c.worldZ.z);
    const float forwardLength = length(forward);
    const float2 ahead = (forwardLength > 1e-6f) ? forward / forwardLength * (0.6f * min(c.halfWidth, 6000.0f)) : float2(0.0f, 0.0f);
    middle = camera + float3(ahead.x, 0.0f, ahead.y);
    // Moved in whole texels across the map, so the shadows' edges don't crawl as the camera moves.
    const float texel = 2.0f * c.halfWidth / c.size;
    const float a = dot(middle, across), u = dot(middle, up);
    middle += across * (floor(a / texel) * texel - a) + up * (floor(u / texel) * texel - u);
}

// A world position on the map: x and y in [-1, 1] across it, z the depth in [0, 1] (0 nearest the sun).
float3 SunMapPosition(SunMapFrame c, float3 world) {
    float3 across, up, towards, middle;
    SunMapBasis(c, across, up, towards, middle);
    const float3 q = world - middle;
    return float3(dot(q, across) / c.halfWidth, dot(q, up) / c.halfWidth, 0.5f - dot(q, towards) / (2.0f * c.range));
}

#endif // RT64_EXT_SHADERS_SUNSHADOWMAP_HLSLI
