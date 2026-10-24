//
// RT64
//
// Banjo-Tooie: volumetric shadows' volume pass (VolumetricShadows.hlsli). Each face of the lit air's mesh, wherever it
// covers a pixel of the gathered light, adds the light gathered from the camera out to the face if the eye's ray leaves
// the lit air there, or takes it away if the ray goes in. Faces behind what the pixel shows count as at its distance,
// so they cancel out in pairs. Blended by adding: the sun in r, the lamps in g. Depth isn't tested.

#include "VolumetricShadows.hlsli"

float2 PSMain(in float4 pos : SV_Position, in float3 world : TEXCOORD0, nointerpolation in float3 normal : TEXCOORD1) : SV_Target {
    const int2 picture = GatheredToPicture(int2(pos.xy));
    const float3 camera = CameraWorld();
    // The pixel's own ray, the same for every face over it.
    const float3 ray = normalize(PixelRay(float2(picture) + 0.5f));
    const float distance = min(dot(world - camera, ray), SceneDistance(picture));
    const float side = (dot(normal, ray) < 0.0f) ? -1.0f : 1.0f;
    if (gConstants.medium.z < 0.5f) {
        return float2(side * SunGathered(max(distance, 0.0f)), 0.0f);
    }
    const float3 toLamp = gConstants.lightA.xyz - camera;
    const float along = dot(toLamp, ray);
    // A core round the lamp, so it glows instead of blazing to a point.
    const float Core = 24.0f;
    const float closest = sqrt(max(dot(toLamp, toLamp) - along * along, 0.0f) + Core * Core);
    return float2(0.0f, side * LampGathered(max(distance, 0.0f), along, closest) * gConstants.lightB.w);
}
