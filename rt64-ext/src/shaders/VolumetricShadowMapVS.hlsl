//
// RT64
//
// Banjo-Tooie: volumetric shadows' map pass (VolumetricShadows.hlsli). Each of the 3D world's solid draws again, depth
// only, from the sun (straight on) or from a lamp (one face of the cube round it). The index buffer holds the global
// vertex indices, so the vertex's world position is worked out here the way RSPWorldCS does it, from the game's own
// vertices and model transforms (the same set of buffers as the casters' other passes).

#define VOL_SHADOW_MAP_PASS
#include "VolumetricShadows.hlsli"

Buffer<float> srcPos : register(t1);
Buffer<uint> srcWorldIndices : register(t2);
StructuredBuffer<float4x4> worldMats : register(t3);

void VSMain(in uint vertexIndex : SV_VertexID, out float4 pos : SV_Position) {
    const uint posIndex = vertexIndex * 3;
    const float3 local = float3(srcPos[posIndex + 0], srcPos[posIndex + 1], srcPos[posIndex + 2]);
    const float4 worldPos = mul(worldMats[srcWorldIndices[vertexIndex]], float4(local, 1.0f));
    const float3 world = worldPos.xyz / worldPos.w;
    if (gConstants.medium.z < 0.5f) {
        pos = float4(WorldToSunMap(world), 1.0f);
    }
    else {
        float3 axis, u, v;
        LampFace(uint(gConstants.lightB.w), axis, u, v);
        const float3 rel = world - gConstants.lightA.xyz;
        const float n = gConstants.lightB.x;
        const float f = gConstants.lightB.y;
        const float z = dot(rel, axis);
        pos = float4(dot(rel, u), dot(rel, v), z * (f / (f - n)) - f * n / (f - n), z);
    }
}
