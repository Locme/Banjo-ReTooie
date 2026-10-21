//
// RT64
//
// Banjo-Tooie: the sun shadow map's pass. Each of the 3D world's draws again, from the sun, depth only. The
// index buffer holds the global vertex indices, so the vertex's world position is worked out here the way
// RSPWorldCS does it, from the game's own vertices and model transforms.

#include "SunShadowMap.hlsli"

[[vk::push_constant]] ConstantBuffer<SceneEffectsCB> gConstants : register(b0);
Buffer<float> srcPos : register(t1);
Buffer<uint> srcWorldIndices : register(t2);
StructuredBuffer<float4x4> worldMats : register(t3);

void VSMain(in uint vertexIndex : SV_VertexID, out float4 pos : SV_Position, out float3 world : TEXCOORD0) {
    const uint posIndex = vertexIndex * 3;
    const float3 local = float3(srcPos[posIndex + 0], srcPos[posIndex + 1], srcPos[posIndex + 2]);
    const float4 worldPos = mul(worldMats[srcWorldIndices[vertexIndex]], float4(local, 1.0f));
    world = worldPos.xyz / worldPos.w;
    pos = float4(SunMapPosition(SUN_MAP_FRAME(gConstants), world), 1.0f);
}
