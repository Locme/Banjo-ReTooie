//
// RT64
//

// Banjo-Tooie: the small creatures in the 3D grass and the sea (shared/rt64_critters.h, rt64_critters.cpp), drawn one
// instanced draw a kind with no vertex buffers. Each kind's mesh was modelled in Blender (tools/critters/
// critter_models.py) and is kept on the GPU (critterMesh, from shared/rt64_critter_meshes.h): for each vertex its
// place, normal, colour, paint slot, the part it belongs to and whether it is flat. This shader places a creature's
// vertices in the world by its frame, moves its parts (wings beating round their roots, a frog's back legs kicking out,
// a crab's claws and legs, a turtle's flippers, a fish's tail swinging, a ray's wings rippling), paints the slots with
// the kind's colour variant (CritterMeshes.hlsli's CritterPalette), and lights it smoothly, corner by corner, as the
// N64 shades its creatures. The uber pixel shader draws the vertex colour as it is (RasterPS.hlsl, RASTER_GRASS_BLADES).

#include "shared/rt64_hlsl.h"
#include "shared/rt64_raster_params.h"
#include "shared/rt64_critters.h"
#include "shared/rt64_critter_meshes.h"

#include "FbRendererCommon.hlsli"
#include "CritterMeshes.hlsli"

[[vk::push_constant]] ConstantBuffer<RasterParams> gConstants : register(b0, space0);

StructuredBuffer<Critter> critters : register(t79, space0);
// Every kind's vertices, four words each (rt64_critter_meshes.h).
StructuredBuffer<uint4> critterMesh : register(t80, space0);

float4 CritterToClip(float3 world) {
    const float4 w = float4(world, 1.0f);
    return float4(dot(FrParams.grassWorldToClip[0], w), dot(FrParams.grassWorldToClip[1], w), dot(FrParams.grassWorldToClip[2], w), dot(FrParams.grassWorldToClip[3], w));
}

float CritterSigned16(uint bits) {
    return float(int(bits << 16) >> 16) / 8192.0f;
}

float CritterSigned8(uint bits, uint shift) {
    return float(int(bits << (24u - shift)) >> 24) / 127.0f;
}

// A part beating round its root (a wing, flipper or leg, on the creature's right when its pivot is, else its left):
// turned about the forward axis through pivot by angle, its tip going up for an angle over 0.
void CritterFlap(inout float3 p, inout float3 n, float3 pivot, float angle) {
    const float side = (pivot.y >= 0.0f) ? 1.0f : -1.0f;
    const float c = cos(angle), s = sin(angle) * side;
    const float3 d = p - pivot;
    p = pivot + float3(d.x, d.y * c - d.z * s, d.y * s + d.z * c);
    n = float3(n.x, n.y * c - n.z * s, n.y * s + n.z * c);
}

// A part swung about the creature's across axis through pivot (a frog's leg kicking back: below 0 it goes down and back).
void CritterSwing(inout float3 p, inout float3 n, float3 pivot, float angle) {
    const float c = cos(angle), s = sin(angle);
    const float3 d = p - pivot;
    p = pivot + float3(d.x * c - d.z * s, d.y, d.x * s + d.z * c);
    n = float3(n.x * c - n.z * s, n.y, n.x * s + n.z * c);
}

// A part turned about the creature's up axis through pivot (a crab's claw opening out).
void CritterTurn(inout float3 p, inout float3 n, float3 pivot, float angle) {
    const float side = (pivot.y >= 0.0f) ? 1.0f : -1.0f;
    const float c = cos(angle), s = sin(angle) * side;
    const float3 d = p - pivot;
    p = pivot + float3(d.x * c - d.y * s, d.x * s + d.y * c, d.z);
    n = float3(n.x * c - n.y * s, n.x * s + n.y * c, n.z);
}

// Moves a vertex of a creature's part by its pose (Critter.pose.z: a wing's angle, a frog's legs stretched 0 to 1, a
// stroke's phase), and bends a fish's or ray's body.
void CritterPose(uint kind, uint part, bool folded, float pose, inout float3 p, inout float3 n) {
    const float3 pivot = CritterPivots[kind * 8u + part];
    if (part != 0u) {
        switch (kind) {
        case CRITTER_BEE:
        case CRITTER_FLY:
        case CRITTER_FIREFLY:
        case CRITTER_MOTH:
            CritterFlap(p, n, pivot, pose);
            break;
        case CRITTER_BUTTERFLY:
            // (The back wings droop a little more than the front ones.)
            CritterFlap(p, n, pivot, pose - ((part >= 3u) ? 0.25f : 0.0f));
            break;
        case CRITTER_DRAGONFLY:
            CritterFlap(p, n, pivot, pose * ((part >= 3u) ? 0.8f : 1.0f));
            break;
        case CRITTER_BEETLE:
            // (Its wings fold away under its shell while it rests.)
            if (folded) {
                p = pivot;
            }
            else {
                CritterFlap(p, n, pivot, pose);
            }
            break;
        case CRITTER_BIRD:
            // (Resting, its wings hang folded down its sides; its tail, part 5, holds still.)
            if (part <= 2u) {
                CritterFlap(p, n, pivot, folded ? -1.25f : pose);
            }
            break;
        case CRITTER_FROG:
            // Its back legs kick out behind it as it hops.
            CritterSwing(p, n, pivot, -2.4f * pose);
            break;
        case CRITTER_CRAB:
            if (part <= 2u) {
                CritterTurn(p, n, pivot, 0.15f * sin(pose * 0.5f));
            }
            else {
                CritterFlap(p, n, pivot, 0.18f * sin(pose + ((pivot.y >= 0.0f) ? 0.0f : 3.14159265f)));
            }
            break;
        case CRITTER_TURTLE:
            CritterFlap(p, n, pivot, (part <= 2u) ? (0.45f * sin(pose)) : (0.25f * sin(pose + 1.5f)));
            break;
        default:
            break;
        }
    }
    if (kind == CRITTER_FISH) {
        // A fish swims by swinging its back half from side to side, more the further back.
        const float back = saturate(0.3f - p.x);
        p.y += 0.32f * back * back * sin(pose - 2.5f * p.x);
    }
    else if (kind == CRITTER_RAY) {
        // A wave rolling out along a ray's wings.
        p.z += 0.32f * sin(pose - abs(p.y) * 1.6f) * max(abs(p.y) - 0.2f, 0.0f);
    }
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
    // (Anything not drawn is left outside the screen.)
    oPosition = float4(2.0f, 2.0f, 2.0f, 1.0f);
    oUV = 0.0f;
    oSmoothColor = 0.0f;
    oFlatColor = 0.0f;
    oFurAnchor = 0.0f;

    // (This kind's draw starts at its first creature: grassShell carries it, as a draw's first instance doesn't reach
    // SV_InstanceID the same way on every graphics API.)
    const Critter c = critters[gConstants.grassShell + iInstanceId];
    const uint kind = min(c.look.x, uint(CRITTER_KINDS - 1));
    const uint2 range = CritterMeshRange[kind];
    if ((c.position.w <= 0.0f) || (iVertexId >= range.y)) {
        return;
    }
    // A creature wholly behind the camera or well off the side of the screen is left out at once.
    {
        const float4 centre = CritterToClip(c.position.xyz);
        const float reach = 3.0f * c.position.w;
        if ((centre.w < -reach) || (abs(centre.x) > centre.w + reach) || (abs(centre.y) > centre.w + reach)) {
            return;
        }
    }

    // The vertex (rt64_critter_meshes.h): place, part, slot and flatness; normal; colour.
    const uint4 w = critterMesh[range.x + iVertexId];
    float3 local = float3(CritterSigned16(w.x & 0xFFFFu), CritterSigned16(w.x >> 16), CritterSigned16(w.y & 0xFFFFu));
    const uint part = (w.y >> 16) & 0xFu;
    const uint slot = (w.y >> 20) & 0xFu;
    const bool flat = ((w.y >> 24) & 1u) != 0u;
    float3 localNormal = float3(CritterSigned8(w.z, 0u), CritterSigned8(w.z, 8u), CritterSigned8(w.z, 16u));
    const float3 paint = float3(float(w.w & 0xFFu), float((w.w >> 8) & 0xFFu), float((w.w >> 16) & 0xFFu)) / 255.0f;

    const bool folded = ((c.look.w >> 8) & 1u) != 0u;
    CritterPose(kind, part, folded, c.pose.z, local, localNormal);

    // The creature's frame in the world: its yaw round the world's up, its nose up or down, then its bank.
    const float cy = cos(c.pose.x), sy = sin(c.pose.x);
    const float cp = cos(c.pose.y), sp = sin(c.pose.y);
    const float cb = cos(c.pose.w), sb = sin(c.pose.w);
    const float3 forward0 = float3(cy, 0.0f, sy);
    const float3 right0 = float3(-sy, 0.0f, cy);
    const float3 forward = forward0 * cp + float3(0.0f, sp, 0.0f);
    const float3 up0 = float3(0.0f, cp, 0.0f) - forward0 * sp;
    const float3 right = right0 * cb + up0 * sb;
    const float3 up = up0 * cb - right0 * sb;
    const float half = 0.5f * c.position.w;
    const float3 world = c.position.xyz + (local.x * forward + local.y * right + local.z * up) * half;

    float4 position = CritterToClip(world);
    position.xy = position.xy * gConstants.screenScale + gConstants.screenOffset * position.w;
    oPosition = position;

    // Shaded smoothly, corner by corner (Gouraud shading), by the mesh's own normals; a flat wing or fin from whichever
    // side the camera sees. Soft light: wrapped round from the scene's sun (or from above), a generous share
    // everywhere, a little more from the sky on top.
    const float3 camera = float3(FrParams.grassWorldX.w, FrParams.grassWorldY.w, FrParams.grassWorldZ.w);
    float3 normal = localNormal.x * forward + localNormal.y * right + localNormal.z * up;
    normal = (dot(normal, normal) > 1e-6f) ? normalize(normal) : up;
    if (flat && (dot(normal, camera - world) < 0.0f)) {
        normal = -normal;
    }
    float3 sun = FrParams.grassSun.xyz;
    sun = (dot(sun, sun) > 1e-4f) ? normalize(sun) : normalize(float3(0.3f, 1.0f, 0.2f));
    const float wrap = saturate(dot(normal, sun) * 0.5f + 0.5f);
    const float light = 0.5f + 0.55f * wrap * wrap + 0.1f * saturate(normal.y);

    // The paint: as it is, or the kind's variant colour for its slot times the grey it holds (halved, so up to 2).
    const uint variant = c.look.y % CRITTER_PALETTE_VARIANTS;
    float3 colour = paint;
    if (slot != 0u) {
        const float3 tint = CritterPalette[(kind * CRITTER_PALETTE_SLOTS + min(slot, uint(CRITTER_PALETTE_SLOTS - 1))) * CRITTER_PALETTE_VARIANTS + variant];
        colour = tint * (paint.r * 2.0f);
    }
    colour *= light * (float(c.look.z) / 255.0f);
    // A firefly's tail (slot 4) glows by itself (look.w's low byte), lit or not, the faces towards the camera the
    // brightest; it may go past 1, so on a high-precision picture Bloom catches it.
    const bool glowing = (slot == 4u);
    if (glowing) {
        const float glow = float(c.look.w & 0xFFu) / 255.0f;
        const float3 glowColour = CritterPalette[(kind * CRITTER_PALETTE_SLOTS + 4u) * CRITTER_PALETTE_VARIANTS + variant];
        const float facing = saturate(dot(normal, normalize(camera - world)));
        colour = lerp(glowColour * 0.35f, glowColour * (1.3f + 0.6f * facing), glow);
    }
    oSmoothColor = float4(glowing ? max(colour, 0.0f) : saturate(colour), 1.0f);
    oFlatColor = oSmoothColor;
}
