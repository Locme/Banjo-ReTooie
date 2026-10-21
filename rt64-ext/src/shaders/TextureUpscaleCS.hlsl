//
// RT64
//
// Banjo-Tooie: live texture upscaling. Doubles a decoded texture with an edge-directed rule written from
// the published description of Hyllian's xBR (level 1): for each corner of a source pixel, the edge
// across that corner is compared with the one along it, using the pixels around them, and where the
// corner sits on an edge it takes the colour of the nearer side, half blended. Run twice for 4x.
// Textures wrap, as most of the game's tile, unless the far side is nothing like the edge (see Fetch).

#define GROUP_SIZE 8

struct TextureUpscaleCB {
    uint2 inputSize;
    uint2 padding;
};

[[vk::push_constant]] ConstantBuffer<TextureUpscaleCB> gConstants : register(b0);
Texture2D<float4> gInput : register(t1);
RWTexture2D<float4> gOutput : register(u2);

// A perceptual distance between two colours (luma counts most), with alpha.
float Distance(float4 a, float4 b) {
    const float3 d = a.rgb - b.rgb;
    const float y = dot(d, float3(0.299f, 0.587f, 0.114f));
    const float u = dot(d, float3(-0.169f, -0.331f, 0.5f));
    const float v = dot(d, float3(0.5f, -0.419f, -0.081f));
    return 48.0f * abs(y) + 7.0f * abs(u) + 6.0f * abs(v) + 32.0f * abs(a.a - b.a);
}

// Past the texture's edge the pixel wraps round to the other side, as most of the game's tiles do, unless that
// pixel is nothing like the edge pixel it follows (a fence cut out by its alpha, a clamped sign: the other side is
// not its continuation), when the edge pixel is repeated instead. Else the far side bled into the edge as a line.
float4 Fetch(int2 base, int2 offset, int2 mirror) {
    const int2 size = int2(gConstants.inputSize);
    const int2 at = base + offset * mirror;
    const int2 wrapped = (at % size + size) % size;
    const float4 value = gInput.Load(int3(wrapped, 0));
    if (all(at == wrapped)) {
        return value;
    }
    const float4 edge = gInput.Load(int3(clamp(at, int2(0, 0), size - 1), 0));
    return (Distance(value, edge) > 10.0f) ? edge : value;
}

[numthreads(GROUP_SIZE, GROUP_SIZE, 1)]
void CSMain(uint2 coord : SV_DispatchThreadID) {
    if ((coord.x >= gConstants.inputSize.x * 2) || (coord.y >= gConstants.inputSize.y * 2)) {
        return;
    }

    // The source pixel and the corner this output pixel is in, as a mirror so the rule is written once
    // for the bottom-right corner.
    const int2 base = int2(coord / 2);
    const int2 mirror = int2((coord.x & 1) ? 1 : -1, (coord.y & 1) ? 1 : -1);
    const float4 E = Fetch(base, int2(0, 0), mirror);
    const float4 B = Fetch(base, int2(0, -1), mirror);
    const float4 C = Fetch(base, int2(1, -1), mirror);
    const float4 D = Fetch(base, int2(-1, 0), mirror);
    const float4 F = Fetch(base, int2(1, 0), mirror);
    const float4 G = Fetch(base, int2(-1, 1), mirror);
    const float4 H = Fetch(base, int2(0, 1), mirror);
    const float4 I = Fetch(base, int2(1, 1), mirror);
    const float4 F4 = Fetch(base, int2(2, 0), mirror);
    const float4 I4 = Fetch(base, int2(2, 1), mirror);
    const float4 H5 = Fetch(base, int2(0, 2), mirror);
    const float4 I5 = Fetch(base, int2(1, 2), mirror);

    // An edge running between F and H (across the corner) against one through E and I (along it).
    const float across = Distance(E, C) + Distance(E, G) + Distance(I, F4) + Distance(I, H5) + 4.0f * Distance(H, F);
    const float along = Distance(H, D) + Distance(H, I5) + Distance(F, I4) + Distance(F, B) + 4.0f * Distance(E, I);
    float4 result = E;
    if (across < along) {
        const float4 nearer = (Distance(E, F) <= Distance(E, H)) ? F : H;
        result = lerp(E, nearer, 0.5f);
    }
    gOutput[coord] = result;
}
