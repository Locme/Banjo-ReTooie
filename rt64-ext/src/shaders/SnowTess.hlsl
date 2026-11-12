//
// RT64
//

// Banjo-Tooie: deep snow as one tessellated surface, where the device has hull and domain shaders (D3D12, and Vulkan
// with tessellationShader). The level's snowy ground draws are drawn again through these: the hull shader cuts each
// triangle finer near Banjo's trail (coarser past the Snow LOD distance) and near the camera, where the snow's own drifts
// have a shape (SnowSurfaceShape), and the domain shader raises every new vertex
// straight up to the snow's height over the ground there, pressed down where Banjo walked and banked up beside
// it (SnowTessShape in Snow.hlsli), so the trail is a real dent in the snow's surface rather than a stack of shells.
// The vertex shader leaves the ground where it is (RASTER_SNOW_TESS, RasterVS.hlsl); the pixel shader asks the same
// height again to shade the snow, and shades the ground as it is where no snow lies (RasterPS.hlsl). The ground's own
// draw is left out (FramebufferRenderer): this one stands in for it, so the trail can go down through a game's own
// snow layer (Icy Side's) to Banjo's feet.
//
// Built twice from this file: HSMain (hull) and DSMain (domain). Both use the ubershader's vertex and pixel shaders,
// whose outputs and inputs SnowVertex matches.

#include "shared/rt64_raster_params.h"

#include "FbRendererCommon.hlsli"
#include "Snow.hlsli"

[[vk::push_constant]] ConstantBuffer<RasterParams> gConstants : register(b0, space0);

struct SnowVertex {
    float4 position : SV_POSITION;
    float2 uv : TEXCOORD;
    float4 smoothColor : COLOR0;
    nointerpolation float4 flatColor : COLOR1;
    // The ground's place in the world, then how much of the snow's height lies there (RasterVS.hlsl).
    float4 furAnchor : TEXCOORD1;
};

struct SnowPatch {
    float edges[3] : SV_TessFactor;
    float inside : SV_InsideTessFactor;
    // The ground's normal, for SnowTessShape (any length).
    float3 normal : NORMAL;
};

// Over the trail the surface is cut about two of its cells fine (SnowTrailSegment: coarser past the Snow LOD distance);
// elsewhere near the camera finely enough to follow the untouched surface's own shape (SnowSurfaceSegment, about as many
// pixels apart everywhere) out to twice the Snow LOD distance (SnowSurfaceFade), and past that not at all.
static const float SnowTessMaxFactor = 64.0f;
// Whether any block of the trail grid with a trail in it overlaps a box of the world (lowest and highest x and z): every
// block the box covers is looked at, so a big triangle can't miss one between points it looked at.
bool SnowTrailInBox(float2 low, float2 high) {
    const float4 player = FrParams.snowPlayer;
    if ((player.w <= 0.0f) || any(high < player.xy - player.w) || any(low > player.xy + player.w)) {
        return false;
    }
    const int n = int(FrParams.snowGrid.z);
    const int blockCells = n / 16;
    // (Widened by how far the trail is smoothed over, SnowTrailBlur, so a dent's soft edge in the next block is cut too.)
    const float pad = 10.0f;
    const int2 first = int2(floor((low - pad) * FrParams.snowGrid.y / float(blockCells)));
    const int2 last = int2(floor((high + pad) * FrParams.snowGrid.y / float(blockCells)));
    // (A box wider than the grid covers every block.)
    const int2 count = min(last - first + 1, 16);
    const float blockSize = float(blockCells) / FrParams.snowGrid.y;
    for (int z = 0; z < count.y; z++) {
        for (int x = 0; x < count.x; x++) {
            if (SnowBlockActive((float2(first + int2(x, z)) + 0.5f) * blockSize)) {
                return true;
            }
        }
    }
    return false;
}

// Sand's footprints are shallow: past this far from the camera they are smaller than a pixel, so the sand there isn't cut
// for them (by each edge's middle, so the triangles either side of an edge agree). Never round Banjo, though: a camera
// high over him (looking straight down) is further than this from all of the sand, and flattened it (L 2026-10-22).
static const float SandTessReach = 900.0f;

bool SandTooFar(float3 world, float cameraDistance) {
    if (!SnowSand() || (cameraDistance <= SandTessReach)) {
        return false;
    }
    const float4 player = FrParams.snowPlayer;
    return (player.w <= 0.0f) || (distance(world, float3(player.x, player.z, player.y)) > SandTessReach);
}

float SnowSegmentFactor(float edgeLength, float3 middle, float cameraDistance, bool trail) {
    // (Untouched snow lies flat over the ground, raised by the same height all over a triangle: nothing to cut.)
    if (!trail) {
        return 1.0f;
    }
    return clamp(edgeLength / SnowTrailSegmentAt(middle, cameraDistance), 1.0f, SnowTessMaxFactor);
}

// For the untouched surface's own shape (SnowSurfaceShape): 1 past its reach, for the ground pass
// (RASTER_SNOW_GROUND), which lies flat on the ground under the snow, for sand (shallow, its shape is only lit,
// SnowShellShade), and where any corner it runs between lies at the snowy ground's edge (raised, 0 to 1 of the snow's
// height: furAnchor.w). Snow there lies on the ground itself, flat with the level's other ground beside or under
// it, and cut finer it would round its depth a hair differently from that ground's and flicker against it in rings
// (as tessellated sand did all over).
float SnowSurfaceFactor(float edgeLength, float cameraDistance, float raised) {
    if ((SnowSurfaceFade(cameraDistance) <= 0.0f) || ((gConstants.grassShells & RASTER_SNOW_GROUND) != 0) || SnowSand() || (raised < 0.5f)) {
        return 1.0f;
    }
    return clamp(edgeLength / SnowSurfaceSegment(cameraDistance), 1.0f, SnowTessMaxFactor);
}

float SnowEdgeFactor(float4 anchorA, float4 anchorB) {
    const float3 a = anchorA.xyz;
    const float3 b = anchorB.xyz;
    const float edgeLength = distance(a, b);
    const float3 camera = FrParams.snowCamera.xyz;
    const float cameraDistance = distance((a + b) * 0.5f, camera);
    const bool trail = !SandTooFar((a + b) * 0.5f, cameraDistance) && SnowTrailInBox(min(a.xz, b.xz), max(a.xz, b.xz));
    return max(SnowSegmentFactor(edgeLength, (a + b) * 0.5f, cameraDistance, trail), SnowSurfaceFactor(edgeLength, cameraDistance, min(anchorA.w, anchorB.w)));
}

// The inside's factor: as fine as the trail anywhere over the triangle needs, and at least as fine as its edges.
float SnowInsideFactor(float3 a, float3 b, float3 c, float raised, float edgeFactor) {
    const float longest = max(distance(a, b), max(distance(b, c), distance(c, a)));
    const float3 camera = FrParams.snowCamera.xyz;
    const float cameraDistance = distance((a + b + c) / 3.0f, camera);
    const bool trail = !SandTooFar((a + b + c) / 3.0f, cameraDistance) && SnowTrailInBox(min(a.xz, min(b.xz, c.xz)), max(a.xz, max(b.xz, c.xz)));
    return max(edgeFactor, max(SnowSegmentFactor(longest, (a + b + c) / 3.0f, cameraDistance, trail), SnowSurfaceFactor(longest, cameraDistance, raised)));
}

// Whether a patch is out of view: all of it, from the snow's full height above the ground to as far below it, past the
// same side of the screen (a little widened) or behind the camera. It is then not drawn at all (factor 0), so the
// level's snow or sand out of view costs nothing past this.
bool SnowPatchOutOfView(InputPatch<SnowVertex, 3> patch) {
    float4 up = FrParams.snowClipUp;
    up.xy = up.xy * gConstants.screenScale + gConstants.screenOffset * up.w;
#ifdef __spirv__
    up.y = -up.y;
#endif
    const float slack = 1.1f;
    bool left = true, right = true, bottom = true, top = true, behind = true;
    for (uint i = 0; i < 3; i++) {
        for (int k = -1; k <= 1; k++) {
            const float4 q = patch[i].position + up * float(k);
            left = left && (q.x < -slack * q.w);
            right = right && (q.x > slack * q.w);
            bottom = bottom && (q.y < -slack * q.w);
            top = top && (q.y > slack * q.w);
            behind = behind && (q.w <= 0.0f);
        }
    }
    return left || right || bottom || top || behind;
}

SnowPatch SnowPatchConstants(InputPatch<SnowVertex, 3> patch) {
    SnowPatch p;
    const float3 a = patch[0].furAnchor.xyz;
    const float3 b = patch[1].furAnchor.xyz;
    const float3 c = patch[2].furAnchor.xyz;
    p.normal = cross(b - a, c - a);
    if (SnowPatchOutOfView(patch)) {
        p.edges[0] = p.edges[1] = p.edges[2] = 0.0f;
        p.inside = 0.0f;
        return p;
    }

    // Not cut inside on a wall, or where all of the triangle is past the snow's reach (drawn as it is: the ground's own
    // draw is left out). Its edges are still cut as the patch beside them cuts them (an edge's factor depends on the
    // edge only), or a crack would open along the foot of every wall where the floor's edge follows the surface's
    // shape and the wall's runs straight.
    const float normalLength = length(p.normal);
    float distanceA, distanceB, distanceC;
    const bool wall = (normalLength <= 0.0f) || (abs(p.normal.y) < 0.12f * normalLength);
    const float reach = FrParams.snowLod.y;
    const bool beyond = (SnowThin(a, distanceA, reach) <= 0.02f) && (SnowThin(b, distanceB, reach) <= 0.02f) && (SnowThin(c, distanceC, reach) <= 0.02f);
    if ((wall || beyond) && (FrParams.snowGrid.w <= 3.5f)) {
        p.edges[0] = SnowEdgeFactor(patch[1].furAnchor, patch[2].furAnchor);
        p.edges[1] = SnowEdgeFactor(patch[2].furAnchor, patch[0].furAnchor);
        p.edges[2] = SnowEdgeFactor(patch[0].furAnchor, patch[1].furAnchor);
        p.inside = 1.0f;
        return p;
    }

    // (Edge 0 is the one across from vertex 0. An edge's factor depends on the edge only, so the triangles either side
    // of it cut it the same way and no cracks open between them.)
    p.edges[0] = SnowEdgeFactor(patch[1].furAnchor, patch[2].furAnchor);
    p.edges[1] = SnowEdgeFactor(patch[2].furAnchor, patch[0].furAnchor);
    p.edges[2] = SnowEdgeFactor(patch[0].furAnchor, patch[1].furAnchor);
    const float raised = min(patch[0].furAnchor.w, min(patch[1].furAnchor.w, patch[2].furAnchor.w));
    p.inside = SnowInsideFactor(a, b, c, raised, max(p.edges[0], max(p.edges[1], p.edges[2])));
    return p;
}

[domain("tri")]
[partitioning("fractional_odd")]
[outputtopology("triangle_cw")]
[outputcontrolpoints(3)]
[patchconstantfunc("SnowPatchConstants")]
[maxtessfactor(64.0f)]
SnowVertex HSMain(InputPatch<SnowVertex, 3> patch, uint i : SV_OutputControlPointID) {
    return patch[i];
}

[domain("tri")]
SnowVertex DSMain(SnowPatch p, float3 w : SV_DomainLocation, const OutputPatch<SnowVertex, 3> patch) {
    SnowVertex v;
    v.position = patch[0].position * w.x + patch[1].position * w.y + patch[2].position * w.z;
    v.uv = patch[0].uv * w.x + patch[1].uv * w.y + patch[2].uv * w.z;
    v.smoothColor = patch[0].smoothColor * w.x + patch[1].smoothColor * w.y + patch[2].smoothColor * w.z;
    v.flatColor = patch[0].flatColor;
    v.furAnchor = patch[0].furAnchor * w.x + patch[1].furAnchor * w.y + patch[2].furAnchor * w.z;

    // Up to the snow's height there, as RasterVS raises a shell (snowClipUp is the snow's full height straight up),
    // then through the draw's screen scale and offset as the position already went.
    // (The trail smoothed over at least as far as the vertices over it are apart, SnowTrailBlur, so its trench has no spikes; by
    // the distance from the camera only, so a vertex shared by two patches lands in the same place for both.)
    // (Below the ground where the trail goes down through a game's own snow layer to Banjo's feet. The ground pass,
    // RASTER_SNOW_GROUND, stays where it is.)
    SnowSample s;
    const float3 camera = FrParams.snowCamera.xyz;
    // (Smoothed over at least as far as this patch's new vertices really are apart: a big triangle can't be cut finer
    // than SnowTessMaxFactor allows, and a trail followed by points further apart than it is smoothed over is spiky. A
    // vertex on an edge takes that edge's spacing only, so the patches either side of it put it in the same place;
    // the triangle's own corners none.)
    const float3 a = patch[0].furAnchor.xyz, b = patch[1].furAnchor.xyz, c = patch[2].furAnchor.xyz;
    float spacing = 0.0f;
    const float onEdge = 1e-4f;
    const uint zeros = uint(w.x < onEdge) + uint(w.y < onEdge) + uint(w.z < onEdge);
    if (zeros == 1u) {
        spacing = (w.x < onEdge) ? distance(b, c) / p.edges[0] : (w.y < onEdge) ? distance(c, a) / p.edges[1] : distance(a, b) / p.edges[2];
    }
    else if (zeros == 0u) {
        spacing = max(distance(a, b), max(distance(b, c), distance(c, a))) / p.inside;
    }
    const float blur = max(SnowTrailBlurAt(v.furAnchor.xyz, distance(v.furAnchor.xyz, camera)), spacing * 0.75f);
    const bool shaped = SnowTessShape(v.furAnchor.xyz, v.furAnchor.w, p.normal, blur, s);
    const bool groundPass = (gConstants.grassShells & RASTER_SNOW_GROUND) != 0;
    const float height = groundPass ? 0.0f : s.height;
    // The snow's texture lies on it by the ground's x and z under it, so down a trench's steep wall every point of a
    // column had the same place in it, and the texture was drawn as streaks straight down the wall (in every lighting).
    // A point pressed down is moved in the texture as far again as it dropped, downhill, by how steep the snow is there,
    // so the texture runs on down the wall instead. (The ground's texture across the patch, from its corners.)
    if (!groundPass && shaped && s.sloped) {
        const float drop = max(s.surface - s.height, 0.0f);
        const float slopeLength = length(s.slope);
        const float2 e1 = b.xz - a.xz, e2 = c.xz - a.xz;
        const float det = e1.x * e2.y - e1.y * e2.x;
        if ((drop > 0.25f) && (slopeLength > 0.05f) && (abs(det) > 1e-3f)) {
            const float2 move = (-s.slope / slopeLength) * (drop * saturate(slopeLength * 0.5f));
            const float u = (move.x * e2.y - move.y * e2.x) / det;
            const float t = (e1.x * move.y - e1.y * move.x) / det;
            v.uv += (patch[1].uv - patch[0].uv) * u + (patch[2].uv - patch[0].uv) * t;
        }
    }
    if (SnowTessPacked()) {
        v.furAnchor = SnowTessPack(v.furAnchor.xyz, shaped, s, groundPass);
    }
    float4 up = FrParams.snowClipUp * (height / max(FrParams.snowParams.y, 1e-3f));
    up.xy = up.xy * gConstants.screenScale + gConstants.screenOffset * up.w;
#ifdef __spirv__
    up.y = -up.y;
#endif
    v.position += up;
    return v;
}
