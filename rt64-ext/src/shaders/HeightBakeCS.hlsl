//
// RT64
//
// Banjo-Tooie: bakes a parallax texture's height map when it loads (TextureCache::refreshHeights), from the texture that
// is drawn: the game's own, its upscale, or a texture pack's. The pixel shaders then take one lookup a step from it
// (Parallax.hlsli, GroundTess.hlsl) instead of working the height out from the texture's colour at every step.
//
// Five passes over the same resources, picked by gConstants.pass:
//   0  clears the brightness histogram;
//   1  the brightness of each height map texel (the average of the source texels it covers), counted in the histogram;
//   2  the texture's darkest and lightest brightness: the listed range for the game's own textures, or for a texture
//      pack's, which can be brighter or darker than the game's, the 1st and 99th percentile of its own brightness;
//   3  blurs the brightness across (a Gaussian, Parallax smoothness and the shape's own softness);
//   4  blurs it down, and writes the height in the texture's shape (ParallaxShape.hlsli), white high and black deep,
//      as a texture pack's "_height" maps are.
// The blur keeps a speckled texture's specks from becoming tiny steep pillars, each of which the march stretched
// along the view into a hair.

#include "ParallaxShape.hlsli"

#define GROUP_SIZE 8
#define HISTOGRAM_BINS 256
#define HISTOGRAM_RANGE_LOW 256
#define HISTOGRAM_RANGE_HIGH 257
#define MAX_TAPS 16

struct HeightBakeCB {
    uint2 sourceSize;
    uint2 heightSize;
    uint pass;
    uint shape;
    // The listed darkest brightness in bits 0 to 7 and lightest in 8 to 15 (0 to 255), and in bit 16, take the
    // texture's own range instead.
    uint range;
    // The blur's standard deviation in height map texels.
    float sigma;
};

[[vk::push_constant]] ConstantBuffer<HeightBakeCB> gConstants : register(b0);
Texture2D<float4> gSource : register(t1);
[[vk::image_format("r32f")]] RWTexture2D<float> gLuma : register(u2);
[[vk::image_format("r32f")]] RWTexture2D<float> gBlur : register(u3);
[[vk::image_format("r8")]] RWTexture2D<float> gHeight : register(u4);
[[vk::image_format("r32ui")]] RWTexture2D<uint> gHistogram : register(u5);

static const float3 LumaWeights = float3(0.299f, 0.587f, 0.114f);

// Textures wrap, as most of the game's tile, so the blur reads round to the other side.
int Wrap(int i, int size) {
    return ((i % size) + size) % size;
}

// The blur along one axis (dir (1, 0) across, (0, 1) down) of a texture of the height map's size.
float Blur(RWTexture2D<float> input, int2 at, int2 dir) {
    const float sigma = gConstants.sigma;
    if (sigma < 0.3f) {
        return input[at];
    }

    const int2 size = int2(gConstants.heightSize);
    const int taps = min(int(ceil(sigma * 2.5f)), MAX_TAPS);
    const float k = -0.5f / (sigma * sigma);
    float sum = input[at];
    float weights = 1.0f;
    for (int i = 1; i <= taps; i++) {
        const float w = exp(float(i * i) * k);
        const int2 a = at + dir * i;
        const int2 b = at - dir * i;
        sum += w * (input[int2(Wrap(a.x, size.x), Wrap(a.y, size.y))] + input[int2(Wrap(b.x, size.x), Wrap(b.y, size.y))]);
        weights += 2.0f * w;
    }

    return sum / weights;
}

[numthreads(GROUP_SIZE, GROUP_SIZE, 1)]
void CSMain(uint2 id : SV_DispatchThreadID) {
    const uint pass = gConstants.pass;
    if (pass == 0) {
        if ((id.y == 0) && (id.x <= HISTOGRAM_RANGE_HIGH)) {
            gHistogram[uint2(id.x, 0)] = 0;
        }
        return;
    }

    if (pass == 2) {
        if (any(id != 0)) {
            return;
        }

        uint low = gConstants.range & 0xFFu;
        uint high = (gConstants.range >> 8) & 0xFFu;
        if ((gConstants.range & 0x10000u) != 0) {
            uint total = 0;
            for (uint i = 0; i < HISTOGRAM_BINS; i++) {
                total += gHistogram[uint2(i, 0)];
            }

            const uint lowCount = max(total / 100u, 1u);
            const uint highCount = total - total / 100u;
            uint seen = 0;
            low = 0;
            high = 255;
            bool lowFound = false;
            for (uint j = 0; j < HISTOGRAM_BINS; j++) {
                seen += gHistogram[uint2(j, 0)];
                if (!lowFound && (seen >= lowCount)) {
                    low = j;
                    lowFound = true;
                }
                if (seen >= highCount) {
                    high = j;
                    break;
                }
            }
        }

        gHistogram[uint2(HISTOGRAM_RANGE_LOW, 0)] = low;
        gHistogram[uint2(HISTOGRAM_RANGE_HIGH, 0)] = max(high, low + 1u);
        return;
    }

    if (any(id >= gConstants.heightSize)) {
        return;
    }

    if (pass == 1) {
        // The source texels this height map texel covers (a texture pack's can be larger than the height map).
        const uint2 step = max(gConstants.sourceSize / gConstants.heightSize, uint2(1, 1));
        const uint2 base = id * step;
        float luma = 0.0f;
        for (uint y = 0; y < step.y; y++) {
            for (uint x = 0; x < step.x; x++) {
                const uint2 at = min(base + uint2(x, y), gConstants.sourceSize - 1u);
                luma += dot(gSource.Load(int3(at, 0)).rgb, LumaWeights);
            }
        }

        luma /= float(step.x * step.y);
        gLuma[id] = luma;
        if ((gConstants.range & 0x10000u) != 0) {
            InterlockedAdd(gHistogram[uint2(min(uint(luma * 255.0f + 0.5f), 255u), 0)], 1u);
        }
    }
    else if (pass == 3) {
        gBlur[id] = Blur(gLuma, int2(id), int2(1, 0));
    }
    else if (pass == 4) {
        const float luma = Blur(gBlur, int2(id), int2(0, 1));
        const float low = float(gHistogram[uint2(HISTOGRAM_RANGE_LOW, 0)]) / 255.0f;
        const float high = float(gHistogram[uint2(HISTOGRAM_RANGE_HIGH, 0)]) / 255.0f;
        const float darkness = saturate((high - luma) / max(high - low, 0.05f));
        gHeight[id] = 1.0f - ParallaxShapeDepth(darkness, gConstants.shape);
    }
}
