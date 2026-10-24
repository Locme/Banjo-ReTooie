//
// RT64
//
// Banjo-Tooie: volumetric shadows' volume pass (VolumetricShadows.hlsli): the closed mesh round the air the light
// reaches, raised from the light's map, with no vertex buffer (each vertex works out its place from its index).
//
// The sun (lightD.w = G cells a side): the map's surface, a grid of G x G cells, each node at the nearest depth of the
// four texels round it (so a post one texel thin still casts); four walls down the map's edges, from the surface up to
// the map's side nearest the sun; and that side itself, a fan from its middle. 6 G^2 + 24 G + 12 G vertices.
// A lamp (lightC.z = G cells a face side): the six faces of a cube round it, each a grid of G x G cells pushed out from the
// lamp to the nearest thing in its way (no further than the lamp's radius). 36 G^2 vertices.
//
// Every vertex is placed by one line of code from its node, so a node shared by two triangles (or two faces) lands on
// exactly the same spot in both and the mesh has no cracks. Each triangle's normal points out of the lit air, which is all
// the pixel pass needs to know whether the eye's ray goes in or out through it.

#include "VolumetricShadows.hlsli"

Texture2D<float> gSunMap : register(t2);
Texture2D<float> gLampMap : register(t3);

struct VolumeVertex {
    float4 pos : SV_Position;
    float3 world : TEXCOORD0;
    nointerpolation float3 normal : TEXCOORD1;
};

// --- The sun ---------------------------------------------------------------------------------------------------------

float2 SunNodeXY(int2 node, float cells) {
    return float2(float(node.x) / cells * 2.0f - 1.0f, 1.0f - float(node.y) / cells * 2.0f);
}

// The nearest depth of the four texels round a node.
float SunNodeDepth(int2 node, float cells) {
    const int size = int(gConstants.lightC.w);
    const int step = size / int(cells);
    const int2 corner = node * step;
    const int2 a = clamp(corner - int2(1, 1), int2(0, 0), int2(size - 1, size - 1));
    const int2 b = clamp(corner, int2(0, 0), int2(size - 1, size - 1));
    const float d0 = gSunMap.Load(int3(a.x, a.y, 0));
    const float d1 = gSunMap.Load(int3(b.x, a.y, 0));
    const float d2 = gSunMap.Load(int3(a.x, b.y, 0));
    const float d3 = gSunMap.Load(int3(b.x, b.y, 0));
    return min(min(d0, d1), min(d2, d3));
}

float3 SunSurfaceNode(int2 node, float cells) {
    const float2 xy = SunNodeXY(node, cells);
    return SunMapToWorld(xy.x, xy.y, SunNodeDepth(node, cells));
}

// The node along one of the map's edges: side 0 the left (x = -1), 1 the right, 2 the top (y = 1), 3 the bottom.
int2 SunEdgeNode(uint side, uint k, uint cells) {
    switch (side) {
    case 0: return int2(0, k);
    case 1: return int2(cells, cells - k);
    case 2: return int2(cells - k, 0);
    default: return int2(k, cells);
    }
}

// The node's x, y and depth on the map, and the normal of its triangle.
void SunVertex(uint index, out float3 mapSpot, out float3 normal) {
    const uint cells = uint(gConstants.lightD.w);
    const float fcells = float(cells);
    const uint surfaceCount = cells * cells * 6;
    const uint wallCount = cells * 24;
    if (index < surfaceCount) {
        const uint cell = index / 6;
        const uint k = index % 6;
        const int2 c = int2(cell % cells, cell / cells);
        // Two triangles a cell: (0, 0) (1, 0) (0, 1) and (1, 0) (1, 1) (0, 1).
        int2 n0, n1, n2;
        if (k < 3) {
            n0 = c; n1 = c + int2(1, 0); n2 = c + int2(0, 1);
        }
        else {
            n0 = c + int2(1, 0); n1 = c + int2(1, 1); n2 = c + int2(0, 1);
        }
        const uint corner = k % 3;
        const int2 node = (corner == 0) ? n0 : ((corner == 1) ? n1 : n2);
        mapSpot = float3(SunNodeXY(node, fcells), SunNodeDepth(node, fcells));
        const float3 p0 = SunSurfaceNode(n0, fcells), p1 = SunSurfaceNode(n1, fcells), p2 = SunSurfaceNode(n2, fcells);
        normal = cross(p1 - p0, p2 - p0);
        // Out of the lit air is away from the sun.
        if (dot(normal, gConstants.lightC.xyz) > 0.0f) {
            normal = -normal;
        }
        return;
    }
    index -= surfaceCount;
    const float3 sideNormals[4] = { -gConstants.lightA.xyz, gConstants.lightA.xyz, gConstants.lightB.xyz, -gConstants.lightB.xyz };
    if (index < wallCount) {
        // A strip of quads down each edge: the surface's node and the one after, and above them the map's side
        // nearest the sun.
        const uint side = index / (cells * 6);
        const uint q = (index % (cells * 6)) / 6;
        const uint k = index % 6;
        // (top q, surface q, surface q + 1), (top q, surface q + 1, top q + 1).
        const uint along = ((k == 2) || (k == 4) || (k == 5)) ? (q + 1) : q;
        const bool top = (k == 0) || (k == 3) || (k == 5);
        const int2 node = SunEdgeNode(side, along, cells);
        mapSpot = float3(SunNodeXY(node, fcells), top ? 0.0f : SunNodeDepth(node, fcells));
        normal = sideNormals[side];
        return;
    }
    index -= wallCount;
    // The side nearest the sun: a fan from its middle to each edge's nodes.
    const uint side = index / (cells * 3);
    const uint q = (index % (cells * 3)) / 3;
    const uint k = index % 3;
    if (k == 0) {
        mapSpot = float3(0.0f, 0.0f, 0.0f);
    }
    else {
        const int2 node = SunEdgeNode(side, (k == 1) ? q : (q + 1), cells);
        mapSpot = float3(SunNodeXY(node, fcells), 0.0f);
    }
    normal = gConstants.lightC.xyz;
}

// --- The lamps -------------------------------------------------------------------------------------------------------

// A node's direction from the lamp (not normalized) and how far the lit air reaches along it.
void LampNode(uint face, int2 node, float cells, out float3 dir, out float reach) {
    float3 axis, u, v;
    LampFace(face, axis, u, v);
    const float x = float(node.x) / cells * 2.0f - 1.0f;
    const float y = 1.0f - float(node.y) / cells * 2.0f;
    dir = axis + u * x + v * y;
    // Read from the face the direction falls on, which is the same for every face sharing the node.
    const uint home = LampFaceOf(dir);
    float3 homeAxis, homeU, homeV;
    LampFace(home, homeAxis, homeU, homeV);
    const float major = dot(dir, homeAxis);
    const float fx = dot(dir, homeU) / major;
    const float fy = dot(dir, homeV) / major;
    const int size = int(gConstants.lightB.z);
    const int2 at = int2(round((fx * 0.5f + 0.5f) * float(size)), round((0.5f - fy * 0.5f) * float(size)));
    const int2 origin = int2(int(gConstants.lightC.x) + int(home % 3) * size, int(home / 3) * size);
    const int2 a = origin + clamp(at - int2(1, 1), int2(0, 0), int2(size - 1, size - 1));
    const int2 b = origin + clamp(at, int2(0, 0), int2(size - 1, size - 1));
    const float d0 = gLampMap.Load(int3(a.x, a.y, 0));
    const float d1 = gLampMap.Load(int3(b.x, a.y, 0));
    const float d2 = gLampMap.Load(int3(a.x, b.y, 0));
    const float d3 = gLampMap.Load(int3(b.x, b.y, 0));
    const float depth = min(min(d0, d1), min(d2, d3));
    reach = min(LampLinearDepth(depth) * length(dir) / major, gConstants.lightA.w);
}

float3 LampNodeWorld(uint face, int2 node, float cells) {
    float3 dir;
    float reach;
    LampNode(face, node, cells, dir, reach);
    return gConstants.lightA.xyz + normalize(dir) * reach;
}

void LampVertex(uint index, out float3 dir, out float reach, out float3 normal) {
    const uint cells = uint(gConstants.lightC.z);
    const float fcells = float(cells);
    const uint perFace = cells * cells * 6;
    const uint face = index / perFace;
    index %= perFace;
    const uint cell = index / 6;
    const uint k = index % 6;
    const int2 c = int2(cell % cells, cell / cells);
    int2 n0, n1, n2;
    if (k < 3) {
        n0 = c; n1 = c + int2(1, 0); n2 = c + int2(0, 1);
    }
    else {
        n0 = c + int2(1, 0); n1 = c + int2(1, 1); n2 = c + int2(0, 1);
    }
    const uint corner = k % 3;
    LampNode(face, (corner == 0) ? n0 : ((corner == 1) ? n1 : n2), fcells, dir, reach);
    const float3 p0 = LampNodeWorld(face, n0, fcells), p1 = LampNodeWorld(face, n1, fcells), p2 = LampNodeWorld(face, n2, fcells);
    normal = cross(p1 - p0, p2 - p0);
    // Out of the lit air is away from the lamp.
    if (dot(normal, (p0 + p1 + p2) * (1.0f / 3.0f) - gConstants.lightA.xyz) < 0.0f) {
        normal = -normal;
    }
}

VolumeVertex VSMain(in uint vertexIndex : SV_VertexID) {
    VolumeVertex o;
    float3 world;
    if (gConstants.medium.z < 0.5f) {
        float3 mapSpot;
        SunVertex(vertexIndex, mapSpot, o.normal);
        world = SunMapToWorld(mapSpot.x, mapSpot.y, mapSpot.z);
    }
    else {
        float3 dir;
        float reach;
        LampVertex(vertexIndex, dir, reach, o.normal);
        world = gConstants.lightA.xyz + normalize(dir) * reach;
    }
    o.world = world;
    o.pos = WorldToClip(world);
    // No near or far plane for the mesh: a face past the far plane still counts (the depth isn't tested). Kept just
    // inside; only what is behind the camera is clipped.
    if (o.pos.w > 0.0f) {
        o.pos.z = clamp(o.pos.z, 0.0f, o.pos.w * 0.999999f);
    }
    return o;
}
