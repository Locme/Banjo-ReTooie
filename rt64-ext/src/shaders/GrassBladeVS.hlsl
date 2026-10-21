//
// RT64
//

// Banjo-Tooie: instanced 3D grass's blades (rt64_grass_instances.h). A ground draw's blades are drawn as one instanced
// draw right after it, with its own material, so the pixel shader colours them from the ground under them (and keeps
// only green ground, RasterPS.hlsl) as before: an instance per blade the culling pass (GrassCullCS.hlsl) kept, of
// GRASS_BLADE_VERTICES vertices (a flat, tapering blade of two segments and a tip, or one triangle when chunky).
// RasterParams.grassShell is the ground draw's slot plus one. The draw asks for as many blades as the slot could hold;
// those past the count the culling pass kept are dropped here, before anything is drawn.

#include "shared/rt64_raster_params.h"

#include "FbRendererCommon.hlsli"
#include "GrassBladeCommon.hlsli"

[[vk::push_constant]] ConstantBuffer<RasterParams> gConstants : register(b0, space0);

float GrassHalf(uint packed, bool high) {
    return f16tof32(high ? (packed >> 16) : (packed & 0xFFFFu));
}

void VSMain(
    in uint iVertexId : SV_VertexID
    , in uint iInstanceId : SV_InstanceID
    , out float4 oPosition : SV_POSITION
    , out float2 oUV : TEXCOORD
    , out float4 oSmoothColor : COLOR0
    , out nointerpolation float4 oFlatColor : COLOR1
    , out float4 oFurAnchor : TEXCOORD1
)
{
    oPosition = float4(2.0f, 2.0f, 2.0f, 1.0f);
    oUV = 0.0f;
    oSmoothColor = 0.0f;
    oFlatColor = 0.0f;
    oFurAnchor = 0.0f;

    const uint slot = gConstants.grassShell - 1;
    const GrassSlot slotInfo = grassSlots[slot];
    const uint count = min(grassSlotCounts[slot * 4 + 1], slotInfo.info.y);
    const bool chunky = FrParams.grassStyle.x > 0.5f;
    const uint bladeTriangle = iVertexId / 3;
    if ((iInstanceId >= count) || (chunky && (bladeTriangle > 0))) {
        return;
    }

    // The blade's corners: 0 and 1 at the root, 2 and 3 across the middle, 4 the tip; a chunky blade is 0, 1 and 4.
    static const uint corners[GRASS_BLADE_VERTICES] = { 0, 1, 2, 1, 3, 2, 2, 3, 4 };
    static const float2 cornerST[5] = { float2(-1.0f, 0.0f), float2(1.0f, 0.0f), float2(-0.75f, 0.55f), float2(0.75f, 0.55f), float2(0.0f, 1.0f) };
    const uint corner = (chunky && ((iVertexId % 3) == 2)) ? 4 : corners[iVertexId];
    float s = cornerST[corner].x;
    float t = cornerST[corner].y;

    const GrassBladeInstance blade = grassBlades[slotInfo.info.x + iInstanceId];
    const float3 root = blade.root.xyz;
    const float bladeHeight = blade.root.w;
    const float yaw = blade.shape.x;
    const float bladeWidth = blade.shape.y;
    const float rise = blade.shape.z;
    const float2 bend = blade.uvBend.zw;
    const float2 facing = float2(cos(yaw), sin(yaw));
    const float3 side = float3(facing.x, 0.0f, facing.y) * (bladeWidth * 0.5f);
    const float3 tipBend = float3(bend.x, 0.0f, bend.y) * bladeHeight;
    const float3 middle = float3(0.0f, rise * 0.55f, 0.0f) + tipBend * 0.3f;
    const float3 tip = float3(0.0f, rise, 0.0f) + tipBend;
    const float4 rootClip = GrassToClip(root);

    // Pixelated blades are drawn bigger, by one block (grassStyle.w N64 pixels, 2 / 240 of the screen's height before
    // its scale) each way across and along them, with their (s, t) going along, so RasterPS can keep whole blocks
    // whose centre is in the real blade.
    if (FrParams.grassStyle.y > 0.5f) {
        const float pixel = FrParams.grassStyle.w * 2.0f / 240.0f;
        const float w = max(rootClip.w, 1e-3f);
        const float across = length(GrassDirToClip(side).xy) / w;
        const float along = length(GrassDirToClip(tip).xy) / w;
        const float2 grow = float2(1.0f + min(pixel / max(across, 1e-4f), 400.0f), 1.0f + min(2.0f * pixel / max(along, 1e-4f), 400.0f));
        s *= grow.x;
        t = 0.5f + (t - 0.5f) * grow.y;
        oFurAnchor = float4(s, t, 1.0f, 0.0f);
    }

    float4 position = rootClip + GrassDirToClip(GrassBladePoint(s, t, chunky, side, middle, tip));
    position.xy = position.xy * gConstants.screenScale + gConstants.screenOffset * position.w;
    oPosition = position;
    oUV = blade.uvBend.xy;
    oSmoothColor = float4(GrassHalf(blade.colors.x, false), GrassHalf(blade.colors.x, true), GrassHalf(blade.colors.y, false), GrassHalf(blade.colors.y, true));
    // The root's height rides in the flat colour's alpha (GrassBlade in Grass.hlsli).
    oFlatColor = float4(GrassHalf(blade.colors.z, false), GrassHalf(blade.colors.z, true), GrassHalf(blade.colors.w, false), root.y);
}
