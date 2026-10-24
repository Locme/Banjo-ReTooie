//
// RT64
//

// Include guard: DXC on Windows can reach a file here by two spellings of its path (from a file beside it, and
// through -I).
#ifndef RT64_EXT_SHADERS_VOLUMETRICSHADOWS_HLSLI
#define RT64_EXT_SHADERS_VOLUMETRICSHADOWS_HLSLI

// Banjo-Tooie: volumetric shadows (shared/rt64_volumetric_shadows.h). What the map, volume and composite passes share:
// where the light's map lies, how a node of the mesh raised from it is placed, and what each of the mesh's faces adds.

#include "shared/rt64_volumetric_shadows.h"

[[vk::push_constant]] ConstantBuffer<VolShadowCB> gConstants : register(b0);

float3 CameraWorld() {
    return float3(gConstants.worldX.w, gConstants.worldY.w, gConstants.worldZ.w);
}

float4 WorldToClip(float3 world) {
    const float4 p = float4(world, 1.0f);
    return float4(dot(p, gConstants.clipX), dot(p, gConstants.clipY), dot(p, gConstants.clipZ), dot(p, gConstants.clipW));
}

// The haze's light gathered from the camera out to a distance along the eye's ray, for a light that reaches every bit
// of it alike (the sun), as a share of the most it can gather: 1 - e^(-thickness * distance).
float SunGathered(float distance) {
    return 1.0f - exp(-gConstants.medium.x * distance);
}

// --- The sun ---------------------------------------------------------------------------------------------------------

// A spot on the sun's map, x and y in [-1, 1] across it, and its depth (0 nearest the sun), in the world.
float3 SunMapToWorld(float x, float y, float z) {
    return gConstants.lightD.xyz + gConstants.lightA.xyz * (x * gConstants.lightA.w) + gConstants.lightB.xyz * (y * gConstants.lightA.w) +
        gConstants.lightC.xyz * ((0.5f - z) * 2.0f * gConstants.lightB.w);
}

// A world position on the sun's map: x and y in [-1, 1], z the depth in [0, 1].
float3 WorldToSunMap(float3 world) {
    const float3 q = world - gConstants.lightD.xyz;
    return float3(dot(q, gConstants.lightA.xyz) / gConstants.lightA.w, dot(q, gConstants.lightB.xyz) / gConstants.lightA.w,
        0.5f - dot(q, gConstants.lightC.xyz) / (2.0f * gConstants.lightB.w));
}

// --- The lamps -------------------------------------------------------------------------------------------------------

// A cube face's axis and its across and up directions.
void LampFace(uint face, out float3 axis, out float3 u, out float3 v) {
    switch (face) {
    case 0: axis = float3(1.0f, 0.0f, 0.0f); u = float3(0.0f, 0.0f, -1.0f); v = float3(0.0f, 1.0f, 0.0f); break;
    case 1: axis = float3(-1.0f, 0.0f, 0.0f); u = float3(0.0f, 0.0f, 1.0f); v = float3(0.0f, 1.0f, 0.0f); break;
    case 2: axis = float3(0.0f, 1.0f, 0.0f); u = float3(1.0f, 0.0f, 0.0f); v = float3(0.0f, 0.0f, -1.0f); break;
    case 3: axis = float3(0.0f, -1.0f, 0.0f); u = float3(1.0f, 0.0f, 0.0f); v = float3(0.0f, 0.0f, 1.0f); break;
    case 4: axis = float3(0.0f, 0.0f, 1.0f); u = float3(1.0f, 0.0f, 0.0f); v = float3(0.0f, 1.0f, 0.0f); break;
    default: axis = float3(0.0f, 0.0f, -1.0f); u = float3(-1.0f, 0.0f, 0.0f); v = float3(0.0f, 1.0f, 0.0f); break;
    }
}

// The face a direction from the lamp falls on. On an edge or corner between faces the same face is picked whichever
// face the direction was worked out from (x before y before z), so the faces' meshes meet without gaps.
uint LampFaceOf(float3 d) {
    const float3 m = abs(d);
    if ((m.x >= m.y) && (m.x >= m.z)) {
        return (d.x >= 0.0f) ? 0u : 1u;
    }
    if (m.y >= m.z) {
        return (d.y >= 0.0f) ? 2u : 3u;
    }
    return (d.z >= 0.0f) ? 4u : 5u;
}

// A face's depth (as the map pass writes it) back to the distance along the face's axis.
float LampLinearDepth(float depth) {
    const float n = gConstants.lightB.x;
    const float f = gConstants.lightB.y;
    return f * n / (f - depth * (f - n));
}

// The haze's light gathered from the camera out to a distance along the eye's ray (direction r from the camera), from a
// lamp: the integral of 1 / (distance to the lamp squared + core squared) less 1 / radius squared, so it fades to nothing at the
// lamp's radius. ray: the lamp as seen from the camera (how far along the ray it is closest, and how close).
float LampGathered(float distance, float along, float closest) {
    const float radius = gConstants.lightA.w;
    return (atan((distance - along) / closest) + atan(along / closest)) / closest - distance / (radius * radius);
}


// --- The picture (not in the map pass, whose t1 is the game's vertices) -----------------------------------------------

#ifndef VOL_SHADOW_MAP_PASS

#if defined(SAMPLES_8X) || defined(SAMPLES_4X) || defined(SAMPLES_2X)
#   define VOL_SHADOW_MULTISAMPLING
Texture2DMS<float> gDepth : register(t1);
#else
Texture2D<float> gDepth : register(t1);
#endif

float LoadDepth(int2 pixel) {
    pixel = clamp(pixel, int2(0, 0), int2(gConstants.projection.zw) - 1);
#ifdef VOL_SHADOW_MULTISAMPLING
    return gDepth.Load(pixel, 0);
#else
    return gDepth.Load(int3(pixel, 0));
#endif
}

// The eye's ray through a spot of the picture (in pixels of the full picture), in the world, not normalized.
float3 PixelRay(float2 at) {
    const float2 ndc = float2(at.x / gConstants.projection.z * 2.0f - 1.0f, 1.0f - at.y / gConstants.projection.w * 2.0f);
    const float3 view = float3(ndc.x / gConstants.projection.x, ndc.y / gConstants.projection.y, -1.0f);
    return float3(dot(view, gConstants.worldX.xyz), dot(view, gConstants.worldY.xyz), dot(view, gConstants.worldZ.xyz));
}

// How far the camera is from what a pixel of the full picture shows, in world units (the sky as far as medium.y).
float SceneDistance(int2 pixel) {
    const float depth = LoadDepth(pixel);
    if (depth >= 0.99999f) {
        return gConstants.medium.y;
    }
    // As SceneEffectsPS's ViewPosition: RT64 keeps the projected z / w halved and moved into [0, 1].
    const float4 t = gConstants.depthTerms;
    const float ndcZ = depth * 2.0f - 1.0f;
    const float z = (t.y - ndcZ * t.w) / (ndcZ * t.z - t.x);
    const float2 ndc = float2((pixel.x + 0.5f) / gConstants.projection.z * 2.0f - 1.0f, 1.0f - (pixel.y + 0.5f) / gConstants.projection.w * 2.0f);
    const float3 view = float3(ndc.x * -z / gConstants.projection.x, ndc.y * -z / gConstants.projection.y, z);
    const float3 world = float3(dot(view, gConstants.worldX.xyz), dot(view, gConstants.worldY.xyz), dot(view, gConstants.worldZ.xyz));
    return min(length(world), gConstants.medium.y);
}

// The pixel of the full picture a pixel of the gathered light stands for (its depth is read there by both passes).
int2 GatheredToPicture(int2 gathered) {
    const int scale = int(gConstants.medium.w);
    return gathered * scale + (scale >> 1);
}
#endif // VOL_SHADOW_MAP_PASS

#endif // RT64_EXT_SHADERS_VOLUMETRICSHADOWS_HLSLI
