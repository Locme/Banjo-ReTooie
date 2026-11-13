//
// RT64
//
// Banjo-Tooie: the sun shadow map's pass. Banjo's own shadow can be left out (as the screen-space shadows
// do it): what is drawn inside a capsule around him casts none. The level casts none from where the Voxel Layer
// has cut it away (VoxelCuts.hlsli), so light falls into a dug hole as the picture shows it.

#include "shared/rt64_scene_effects.h"
#include "VoxelCuts.hlsli"

[[vk::push_constant]] ConstantBuffer<SceneEffectsCB> gConstants : register(b0);
StructuredBuffer<uint> voxelCuts : register(t4);

void PSMain(in float4 pos : SV_Position, in float3 world : TEXCOORD0, in nointerpolation uint level : TEXCOORD1) {
    if (level != 0u) {
        const float3 slopeNormal = cross(ddx(world), ddy(world));
        const float slopeLength = length(slopeNormal);
        if ((slopeLength > 1e-12f) && VoxelSurfaceCut(voxelCuts, world, slopeNormal / slopeLength)) {
            discard;
        }
    }
    const float shadowFlags = gConstants.shadows.w - floor(gConstants.shadows.w / 4.0f) * 4.0f;
    if ((shadowFlags > 1.5f) && (gConstants.rippleAge.w > -1e8f)) {
        const float3 banjo = float3(gConstants.rippleX.w, gConstants.rippleAge.w, gConstants.rippleZ.w);
        const float2 across = world.xz - banjo.xz;
        if ((dot(across, across) < 80.0f * 80.0f) && (world.y > banjo.y - 5.0f) && (world.y < banjo.y + 180.0f)) {
            discard;
        }
    }
}
