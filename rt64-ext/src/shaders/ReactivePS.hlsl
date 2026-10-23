//
// RT64
//

// Banjo-Tooie: the see-through draws (particles, fire, water spray, glass) of the 3D world, drawn again over the objects'
// velocity pass with the same vertex shader (ObjectVelocityVS.hlsl). They have no velocity of their own to give, so the
// velocity target is not written; the reactive mask gets the value in the push constants' size.z, which tells the
// temporal upscalers to trust the history less there.

#include "shared/rt64_temporal_upscaler.h"

[[vk::push_constant]] ConstantBuffer<UpscalerObjectVelocityCB> gConstants : register(b0);

void PSMain(in float4 pos : SV_Position, in float3 previous : TEXCOORD0, out float4 outVelocity : SV_TARGET0, out float outReactive : SV_TARGET1) {
    // Only the blue channel of the velocity target is written (the pipeline's write mask): the built-in resolve reads it from there.
    outVelocity = float4(0.0f, 0.0f, gConstants.size.z, 0.0f);
    outReactive = gConstants.size.z;
}
