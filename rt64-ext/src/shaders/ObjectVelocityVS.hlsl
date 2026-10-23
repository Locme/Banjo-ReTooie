//
// RT64
//

// Banjo-Tooie: the temporal upscalers' velocity of things that move on their own. The 3D world's solid draws again,
// each vertex at its world position now (worldPos) and, with worldVel (now minus the frame before, from RT64's frame
// matching), where it was; both go through the camera without jitter. The pixel shader writes the difference.

#include "shared/rt64_temporal_upscaler.h"

[[vk::push_constant]] ConstantBuffer<UpscalerObjectVelocityCB> gConstants : register(b0);
StructuredBuffer<float4> worldPos : register(t1);
StructuredBuffer<float4> worldVel : register(t2);

void VSMain(in uint vertexIndex : SV_VertexID, out float4 pos : SV_Position, out float3 previous : TEXCOORD0) {
    const float3 now = worldPos[vertexIndex].xyz;
    const float3 before = now - worldVel[vertexIndex].xyz;
    const float4 cur = now.x * gConstants.cur0 + now.y * gConstants.cur1 + now.z * gConstants.cur2 + gConstants.cur3;
    const float4 prev = before.x * gConstants.prev0 + before.y * gConstants.prev1 + before.z * gConstants.prev2 + gConstants.prev3;
    // The projection's depth runs from -w to w; this target's from 0 to w.
    pos = float4(cur.xy, (cur.z + cur.w) * 0.5f, cur.w);
    previous = float3(prev.x, prev.y, prev.w);
}
