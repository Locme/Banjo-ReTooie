//
// RT64
//
// Banjo-Tooie: bakes a parallax texture's height map when it loads (TextureCache::refreshHeights), from the texture that
// is drawn: the game's own, its upscale, or a texture pack's. The pixel shaders then take one lookup a step from it
// (Parallax.hlsli, GroundTess.hlsl) instead of working the height out from the texture's colour at every step.
//
// Ten passes over the same resources, picked by gConstants.pass (the PASS_ names below):
//   0  clears the histograms;
//   1  the brightness of each height map texel (the average of the source texels it covers), counted in the brightness
//      histogram for the game's own textures;
//   2  for a texture pack's texture, its brightness blurred widely across (about three of the game's texels),
//   3  and down, into gHeight for now: the light and shade painted over the texture round each place;
//   4  and its brightness over that, counted in the brightness histogram (see below);
//   5  the texture's darkest and lightest brightness: the listed range for the game's own textures, or for a texture
//      pack's, which can be brighter or darker than the game's, the 1st and 99th percentile of its own brightness;
//   6  the depth of each texel in the texture's shape (ParallaxShape.hlsli), blurred across (a Gaussian, Parallax
//      smoothness and the shape's own softness), and counted unblurred in the depth histogram;
//   7  blurs the depth down, and counts it in the blurred depth histogram;
//   8  the gain that gives thin features back the depth the blur took from them (see below);
//   9  writes the height, white high and black deep, as a texture pack's "_height" maps are.
// A texture pack's textures are painted with light and shade (an HD pack's most of all: a lit side and a shaded side
// to each rock, a shine on each leaf), and taken as height those made whole lit areas bulge and shaded ones sink, and
// each shine a hump, so rock and leaves looked like melted wax. Passes 2 to 4 take that out first, as shape from
// shading does (Glencross et al., "A Perceptually Validated Model for Surface Depth Hallucination", 2008, separate the
// painted shading from the shape before taking depth from it): each texel's brightness is divided by the brightness
// round it, so only the local shape (a pit, the gap round a leaf, a lump) is left, and what is brighter than its
// surroundings is squashed to a third, so a painted shine doesn't stand up as a spike. The game's own textures keep
// their brightness, as their shapes and ranges were picked by eye from it.
// The blur keeps a speckled texture's specks from becoming tiny steep pillars, each of which the march stretched
// along the view into a hair. It is taken after the shape, not before: blurring the brightness first averaged a thin
// dark crack with the light stone round it, so it never got dark enough for the shape to sink it, and a cracked wall
// (or a texture pack's, whose lines are crisper and thinner) came out flat. Blurring the depth keeps the crack as a
// soft groove; the gain then brings its deepest part back down to the depth it had before the blur, for the shapes
// where only a few thin parts sink (cracks, seams, gaps). A surface that is bumpy all over is left as the blur makes it.

#include "ParallaxShape.hlsli"

#define GROUP_SIZE 8
#define HISTOGRAM_BINS 256
#define HISTOGRAM_RANGE_LOW 256
#define HISTOGRAM_RANGE_HIGH 257
#define HISTOGRAM_DEPTH 260
#define HISTOGRAM_BLURRED 516
#define HISTOGRAM_GAIN 772
#define HISTOGRAM_SIZE 773
// A pack texture is baked at up to 1024 texels a side, so one of the game's texels can be a blur of 16 or more.
#define MAX_TAPS 48
// The most the gain brings a thin feature back up by, and the share of the texture that has to sink at least halfway
// for the gain to be left out (fully at DEPTH_BROAD, none at DEPTH_SPARSE), so a bumpy surface keeps its blurred depth.
#define MAX_GAIN 3.0f
// How much of what is brighter than its surroundings is kept, in a texture pack's texture (passes 2 to 4).
#define SHINE_KEPT 0.35f

#define PASS_CLEAR 0
#define PASS_LUMA 1
#define PASS_SHADING_ACROSS 2
#define PASS_SHADING_DOWN 3
#define PASS_UNSHADE 4
#define PASS_RANGE 5
#define PASS_DEPTH_ACROSS 6
#define PASS_DEPTH_DOWN 7
#define PASS_GAIN 8
#define PASS_HEIGHT 9
#define DEPTH_SPARSE 0.1f
#define DEPTH_BROAD 0.3f

struct HeightBakeCB {
    uint2 sourceSize;
    uint2 heightSize;
    uint pass;
    // The shape in bits 0 to 7, and in bits 8 to 31 the wide blur of passes 2 and 3 (its standard deviation in height
    // map texels, times 16).
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

// How deep a height map texel lies (0 the top, 1 the deepest), from its brightness, in the texture's shape.
float DepthAt(int2 at) {
    const float low = float(gHistogram[uint2(HISTOGRAM_RANGE_LOW, 0)]) / 255.0f;
    const float high = float(gHistogram[uint2(HISTOGRAM_RANGE_HIGH, 0)]) / 255.0f;
    const float darkness = saturate((high - gLuma[at]) / max(high - low, 0.05f));
    return ParallaxShapeDepth(darkness, gConstants.shape & 0xFFu);
}

uint DepthBin(float depth) {
    return min(uint(saturate(depth) * 255.0f + 0.5f), 255u);
}

// The depth at a percentile (0 to 1) of one of the depth histograms, as 0 to 1.
float DepthPercentile(uint first, uint total, float share) {
    const uint wanted = max(uint(float(total) * share), 1u);
    uint seen = 0;
    for (uint i = 0; i < HISTOGRAM_BINS; i++) {
        seen += gHistogram[uint2(first + i, 0)];
        if (seen >= wanted) {
            return float(i) / 255.0f;
        }
    }

    return 1.0f;
}

int2 WrapAt(int2 at) {
    const int2 size = int2(gConstants.heightSize);
    return int2(Wrap(at.x, size.x), Wrap(at.y, size.y));
}

bool OwnRange() {
    return (gConstants.range & 0x10000u) != 0;
}

// The wide blur of the painted light and shade (passes 2 and 3): across, of the brightness; down, of what that left in
// gBlur. At most 32 lookups each way, spaced out for a wide blur on a large height map.
float ShadingBlur(int2 at, bool across) {
    const float sigma = float(gConstants.shape >> 8) / 16.0f;
    if (sigma < 0.3f) {
        return across ? gLuma[at] : gBlur[at];
    }

    const int2 dir = across ? int2(1, 0) : int2(0, 1);
    const int stride = max(int(ceil(sigma * 2.5f / 32.0f)), 1);
    const float k = -0.5f / (sigma * sigma);
    float sum = across ? gLuma[at] : gBlur[at];
    float weights = 1.0f;
    for (int i = 1; i <= 32; i++) {
        const int d = i * stride;
        if (float(d) > sigma * 2.5f) {
            break;
        }
        const float w = exp(float(d * d) * k);
        const int2 a = WrapAt(at + dir * d);
        const int2 b = WrapAt(at - dir * d);
        sum += w * (across ? (gLuma[a] + gLuma[b]) : (gBlur[a] + gBlur[b]));
        weights += 2.0f * w;
    }

    return sum / weights;
}

// The blur along one axis: across, of the depth in the texture's shape (pass 6); down, of what that left in gBlur
// (pass 7).
float Blur(int2 at, bool across) {
    const float sigma = gConstants.sigma;
    if (sigma < 0.3f) {
        return across ? DepthAt(at) : gBlur[at];
    }

    const int2 dir = across ? int2(1, 0) : int2(0, 1);
    const int taps = min(int(ceil(sigma * 2.5f)), MAX_TAPS);
    const float k = -0.5f / (sigma * sigma);
    float sum = across ? DepthAt(at) : gBlur[at];
    float weights = 1.0f;
    for (int i = 1; i <= taps; i++) {
        const float w = exp(float(i * i) * k);
        const int2 a = WrapAt(at + dir * i);
        const int2 b = WrapAt(at - dir * i);
        sum += w * (across ? (DepthAt(a) + DepthAt(b)) : (gBlur[a] + gBlur[b]));
        weights += 2.0f * w;
    }

    return sum / weights;
}

[numthreads(GROUP_SIZE, GROUP_SIZE, 1)]
void CSMain(uint2 id : SV_DispatchThreadID) {
    const uint pass = gConstants.pass;
    if (pass == PASS_CLEAR) {
        if ((id.y == 0) && (id.x < HISTOGRAM_SIZE)) {
            gHistogram[uint2(id.x, 0)] = 0;
        }
        return;
    }

    if (pass == PASS_RANGE) {
        if (any(id != 0)) {
            return;
        }

        uint low = gConstants.range & 0xFFu;
        uint high = (gConstants.range >> 8) & 0xFFu;
        if (OwnRange()) {
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

    if (pass == PASS_GAIN) {
        if (any(id != 0)) {
            return;
        }

        // How deep the deepest parts were before the blur and after it (the 99.5th percentile, so a few stray texels
        // don't count), and how much of the texture sinks at least halfway.
        const uint total = gConstants.heightSize.x * gConstants.heightSize.y;
        const float before = DepthPercentile(HISTOGRAM_DEPTH, total, 0.995f);
        const float after = DepthPercentile(HISTOGRAM_BLURRED, total, 0.995f);
        uint deep = 0;
        for (uint i = 128; i < HISTOGRAM_BINS; i++) {
            deep += gHistogram[uint2(HISTOGRAM_DEPTH + i, 0)];
        }

        const float deepShare = float(deep) / float(max(total, 1u));
        const float restore = (before > 0.01f) ? min(before / max(after, 1.0f / 255.0f), MAX_GAIN) : 1.0f;
        const float sparse = saturate((DEPTH_BROAD - deepShare) / (DEPTH_BROAD - DEPTH_SPARSE));
        gHistogram[uint2(HISTOGRAM_GAIN, 0)] = asuint(lerp(1.0f, max(restore, 1.0f), sparse));
        return;
    }

    if (any(id >= gConstants.heightSize)) {
        return;
    }

    if (pass == PASS_LUMA) {
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
        if (!OwnRange()) {
            InterlockedAdd(gHistogram[uint2(min(uint(luma * 255.0f + 0.5f), 255u), 0)], 1u);
        }
    }
    else if ((pass == PASS_SHADING_ACROSS) && OwnRange()) {
        gBlur[id] = ShadingBlur(int2(id), true);
    }
    else if ((pass == PASS_SHADING_DOWN) && OwnRange()) {
        // (gHeight is only written at the end, so it holds the painted shading until then.)
        gHeight[id] = ShadingBlur(int2(id), false);
    }
    else if ((pass == PASS_UNSHADE) && OwnRange()) {
        float shade = gLuma[id] / max(gHeight[id], 0.02f);
        if (shade > 1.0f) {
            shade = 1.0f + (shade - 1.0f) * SHINE_KEPT;
        }

        // Half way up for the brightness round it; pass 5 then takes the 1st to 99th percentiles of this as the range.
        const float luma = saturate(shade * 0.5f);
        gLuma[id] = luma;
        InterlockedAdd(gHistogram[uint2(min(uint(luma * 255.0f + 0.5f), 255u), 0)], 1u);
    }
    else if (pass == PASS_DEPTH_ACROSS) {
        gBlur[id] = Blur(int2(id), true);
        InterlockedAdd(gHistogram[uint2(HISTOGRAM_DEPTH + DepthBin(DepthAt(int2(id))), 0)], 1u);
    }
    else if (pass == PASS_DEPTH_DOWN) {
        // (gLuma is not read again after pass 6, so it holds the blurred depth from here on.)
        const float depth = Blur(int2(id), false);
        gLuma[id] = depth;
        InterlockedAdd(gHistogram[uint2(HISTOGRAM_BLURRED + DepthBin(depth), 0)], 1u);
    }
    else if (pass == PASS_HEIGHT) {
        const float gain = asfloat(gHistogram[uint2(HISTOGRAM_GAIN, 0)]);
        gHeight[id] = 1.0f - saturate(gLuma[id] * gain);
    }
}
