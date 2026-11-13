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

// level: 1 for the level's own vertices (their model transform is the identity, or a move alone: some maps place the
// level's sections so), which the Voxel Layer's cut cells leave out (SunShadowMapPS.hlsl); models keep their shadows.
void VSMain(in uint vertexIndex : SV_VertexID, out float4 pos : SV_Position, out float3 world : TEXCOORD0, out nointerpolation uint level : TEXCOORD1) {
    const uint posIndex = vertexIndex * 3;
    const float3 local = float3(srcPos[posIndex + 0], srcPos[posIndex + 1], srcPos[posIndex + 2]);
    const float4x4 m = worldMats[srcWorldIndices[vertexIndex]];
    const float4 worldPos = mul(m, float4(local, 1.0f));
    world = worldPos.xyz / worldPos.w;
    pos = float4(SunMapPosition(SUN_MAP_FRAME(gConstants), world), 1.0f);
    const float4x4 offIdentity = m - float4x4(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    // (mul(m, v): the move is column 3 of rows 0 to 2, left out; the rest must be the identity's.)
    const float3 turn = abs(offIdentity[0].xyz) + abs(offIdentity[1].xyz) + abs(offIdentity[2].xyz);
    const float4 a = float4(turn, 0.0f) + abs(offIdentity[3]);
    level = ((a.x + a.y + a.z + a.w) < 4e-3f) ? 1u : 0u;
}
