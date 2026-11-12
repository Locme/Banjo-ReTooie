//
// RT64
//
// Banjo-Tooie: live texture upscaling. Doubles a decoded texture with an edge-directed rule written from
// the published description of Hyllian's xBR (level 1): for each corner of a source pixel, the edge
// across that corner is compared with the one along it, using the pixels around them, and where the
// corner sits on an edge it takes the colour of the nearer side, half blended. Run twice for 4x.
// Textures wrap, as most of the game's tile, unless the far side is nothing like the edge (see Fetch).
//
// Mode 1 is the cartoon textures pass instead, at the same size (after the upscale when that is on): see Cartoon.

#define GROUP_SIZE 8

struct TextureUpscaleCB {
    uint2 inputSize;
    uint mode;          // 0: double the size (xBR); 1: cartoon, same size
    uint strength;      // cartoon: 0 to 100
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

float Luma(float3 c) {
    return dot(c, float3(0.299f, 0.587f, 0.114f));
}

// Cartoon textures: the texture flattened into areas of even colour, as painted cartoon textures are, with the edges
// between them kept sharp.
// - A Kuwahara filter: the four squares that have the pixel in a corner are each averaged, and the pixel takes the
//   average of the evenest of them (the least spread of brightness), so it joins the area on its own side of an edge
//   and noise and dither inside an area wash out. The squares are blended by how even they are, not just the evenest
//   picked, which keeps the blocky look of the plain filter away. Pixels are weighted by alpha, so a cut-out's empty
//   part doesn't darken its edge.
// - Brightness is then pulled towards a few even steps (softly, so a gradient becomes bands without hard stairs)
//   and colour made a little stronger.
// strength blends it from the texture.
float4 Cartoon(int2 pixel) {
    const int2 one = int2(1, 1);
    const float4 centre = Fetch(pixel, int2(0, 0), one);
    if (centre.a <= 0.0f) {
        return centre;
    }

    // About a 24th of the texture's size across, 1 to 4 pixels.
    const int radius = clamp(int(min(gConstants.inputSize.x, gConstants.inputSize.y)) / 24, 1, 4);
    float3 blended = float3(0.0f, 0.0f, 0.0f);
    float blendWeight = 0.0f;
    [unroll] for (int q = 0; q < 4; q++) {
        const int2 direction = int2(((q & 1) != 0) ? 1 : -1, ((q & 2) != 0) ? 1 : -1);
        float3 sum = float3(0.0f, 0.0f, 0.0f);
        float lumaSum = 0.0f;
        float lumaSquares = 0.0f;
        float weight = 0.0f;
        for (int y = 0; y <= radius; y++) {
            for (int x = 0; x <= radius; x++) {
                const float4 s = Fetch(pixel, int2(x, y) * direction, one);
                const float l = Luma(s.rgb);
                sum += s.rgb * s.a;
                lumaSum += l * s.a;
                lumaSquares += l * l * s.a;
                weight += s.a;
            }
        }
        if (weight < 0.5f) {
            continue;
        }
        const float mean = lumaSum / weight;
        const float spread = max(lumaSquares / weight - mean * mean, 0.0f);
        // Evener squares count far more (by the square of the spread, the fourth power of its standard deviation), so
        // the pixel follows its own side of an edge.
        const float w = 1.0f / (1.0f + pow(spread * 400.0f, 2.0f));
        blended += (sum / weight) * w;
        blendWeight += w;
    }
    float3 flat = (blendWeight > 0.0f) ? (blended / blendWeight) : centre.rgb;

    // A few soft steps of brightness: 6 at a low strength, 4 at full.
    const float strength = saturate(float(gConstants.strength) / 100.0f);
    const float steps = lerp(6.0f, 4.0f, strength);
    const float luma = Luma(flat);
    const float level = luma * steps;
    const float stepped = (floor(level) + smoothstep(0.3f, 0.7f, frac(level))) / steps;
    flat *= lerp(1.0f, stepped / max(luma, 0.004f), 0.75f);
    flat = lerp(Luma(flat).xxx, flat, 1.0f + 0.3f * strength);

    return float4(lerp(centre.rgb, saturate(flat), strength), centre.a);
}

[numthreads(GROUP_SIZE, GROUP_SIZE, 1)]
void CSMain(uint2 coord : SV_DispatchThreadID) {
    if (gConstants.mode == 1) {
        if ((coord.x < gConstants.inputSize.x) && (coord.y < gConstants.inputSize.y)) {
            gOutput[coord] = Cartoon(int2(coord));
        }
        return;
    }

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
