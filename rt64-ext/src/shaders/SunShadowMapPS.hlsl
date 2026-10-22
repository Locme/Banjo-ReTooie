//
// RT64
//
// Banjo-Tooie: the sun shadow map's pass. Banjo's own shadow can be left out (as the screen-space shadows
// do it): what is drawn inside a capsule around him casts none.

#include "shared/rt64_scene_effects.h"

[[vk::push_constant]] ConstantBuffer<SceneEffectsCB> gConstants : register(b0);

void PSMain(in float4 pos : SV_Position, in float3 world : TEXCOORD0) {
    const float shadowFlags = gConstants.shadows.w - floor(gConstants.shadows.w / 4.0f) * 4.0f;
    if ((shadowFlags > 1.5f) && (gConstants.rippleAge.w > -1e8f)) {
        const float3 banjo = float3(gConstants.rippleX.w, gConstants.rippleAge.w, gConstants.rippleZ.w);
        const float2 across = world.xz - banjo.xz;
        if ((dot(across, across) < 80.0f * 80.0f) && (world.y > banjo.y - 5.0f) && (world.y < banjo.y + 180.0f)) {
            discard;
        }
    }
}
