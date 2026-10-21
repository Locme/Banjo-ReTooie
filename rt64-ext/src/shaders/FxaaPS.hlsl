//
// RT64
//

// Banjo-Tooie: FXAA on the finished game image, before the VI draws it. A fast approximate anti-aliasing
// pass written for this port after Timothy Lottes' FXAA idea: find a luma edge, its direction and its two
// ends, then blend each pixel across the edge by how far it is from the nearer end. FXAA_EXTREME searches
// further along edges and catches fainter ones, for a softer picture.

#include "shared/rt64_smaa.h"

[[vk::push_constant]] ConstantBuffer<SmaaCB> gConstants : register(b0);

Texture2D<float4> gTexture0 : register(t1);
Texture2D<float4> gTexture1 : register(t2);
Texture2D<float4> gTexture2 : register(t3);
SamplerState LinearSampler : register(s4);
SamplerState PointSampler : register(s5);

#if defined(FXAA_EXTREME)
#   define EDGE_THRESHOLD 0.063
#   define EDGE_THRESHOLD_MIN 0.0312
#   define SEARCH_STEPS 24
#   define SUBPIXEL 1.0
#else
#   define EDGE_THRESHOLD 0.125
#   define EDGE_THRESHOLD_MIN 0.0625
#   define SEARCH_STEPS 10
#   define SUBPIXEL 0.75
#endif

float luma(float3 color) {
    return dot(saturate(color), float3(0.299, 0.587, 0.114));
}

float lumaAt(float2 uv) {
    return luma(gTexture0.SampleLevel(LinearSampler, uv, 0).rgb);
}

float lumaOffset(float2 uv, int2 offset) {
    return luma(gTexture0.SampleLevel(PointSampler, uv, 0, offset).rgb);
}

// How far each search step moves, growing after the first few.
float stepScale(int i) {
    if (i < 4) {
        return 1.0;
    }
    if (i < 8) {
        return 1.5;
    }
    if (i < 12) {
        return 2.0;
    }
    return 4.0;
}

float4 PSMain(in float4 pos : SV_Position, in float2 uv : TEXCOORD0) : SV_TARGET {
    const float2 texel = gConstants.rtMetrics.xy;
    const float4 center = gTexture0.SampleLevel(PointSampler, uv, 0);
    const float lumaM = luma(center.rgb);
    const float lumaN = lumaOffset(uv, int2(0, -1));
    const float lumaS = lumaOffset(uv, int2(0, 1));
    const float lumaW = lumaOffset(uv, int2(-1, 0));
    const float lumaE = lumaOffset(uv, int2(1, 0));

    const float lumaMax = max(lumaM, max(max(lumaN, lumaS), max(lumaW, lumaE)));
    const float lumaMin = min(lumaM, min(min(lumaN, lumaS), min(lumaW, lumaE)));
    const float range = lumaMax - lumaMin;
    if (range < max(EDGE_THRESHOLD_MIN, lumaMax * EDGE_THRESHOLD)) {
        return center;
    }

    const float lumaNW = lumaOffset(uv, int2(-1, -1));
    const float lumaNE = lumaOffset(uv, int2(1, -1));
    const float lumaSW = lumaOffset(uv, int2(-1, 1));
    const float lumaSE = lumaOffset(uv, int2(1, 1));

    // Horizontal or vertical edge, from the second differences across each axis.
    const float edgeH = abs(lumaNW - 2.0 * lumaW + lumaSW) + 2.0 * abs(lumaN - 2.0 * lumaM + lumaS) + abs(lumaNE - 2.0 * lumaE + lumaSE);
    const float edgeV = abs(lumaNW - 2.0 * lumaN + lumaNE) + 2.0 * abs(lumaW - 2.0 * lumaM + lumaE) + abs(lumaSW - 2.0 * lumaS + lumaSE);
    const bool horizontal = edgeH >= edgeV;

    // Which side of the pixel the edge lies on.
    const float luma1 = horizontal ? lumaN : lumaW;
    const float luma2 = horizontal ? lumaS : lumaE;
    const float gradient1 = abs(luma1 - lumaM);
    const float gradient2 = abs(luma2 - lumaM);
    const bool side1 = gradient1 >= gradient2;
    const float gradientScaled = 0.25 * max(gradient1, gradient2);
    float stepLength = horizontal ? texel.y : texel.x;
    float lumaLocal;
    if (side1) {
        stepLength = -stepLength;
        lumaLocal = 0.5 * (luma1 + lumaM);
    }
    else {
        lumaLocal = 0.5 * (luma2 + lumaM);
    }

    // Walk along the edge both ways until the luma along it changes.
    float2 edgeUV = uv;
    if (horizontal) {
        edgeUV.y += stepLength * 0.5;
    }
    else {
        edgeUV.x += stepLength * 0.5;
    }

    const float2 along = horizontal ? float2(texel.x, 0.0) : float2(0.0, texel.y);
    float2 uv1 = edgeUV - along;
    float2 uv2 = edgeUV + along;
    float end1 = lumaAt(uv1) - lumaLocal;
    float end2 = lumaAt(uv2) - lumaLocal;
    bool reached1 = abs(end1) >= gradientScaled;
    bool reached2 = abs(end2) >= gradientScaled;
    [loop]
    for (int i = 1; (i < SEARCH_STEPS) && !(reached1 && reached2); i++) {
        if (!reached1) {
            uv1 -= along * stepScale(i);
            end1 = lumaAt(uv1) - lumaLocal;
            reached1 = abs(end1) >= gradientScaled;
        }

        if (!reached2) {
            uv2 += along * stepScale(i);
            end2 = lumaAt(uv2) - lumaLocal;
            reached2 = abs(end2) >= gradientScaled;
        }
    }

    const float distance1 = horizontal ? (uv.x - uv1.x) : (uv.y - uv1.y);
    const float distance2 = horizontal ? (uv2.x - uv.x) : (uv2.y - uv.y);
    const bool nearer1 = distance1 < distance2;
    const float distanceNear = min(distance1, distance2);
    const float edgeLength = distance1 + distance2;
    float offset = -distanceNear / edgeLength + 0.5;

    // Only blend when the nearer end's luma moves the other way from the centre's.
    const bool centerSmaller = (lumaM - lumaLocal) < 0.0;
    const bool correct = ((nearer1 ? end1 : end2) < 0.0) != centerSmaller;
    offset = correct ? offset : 0.0;

    // Sub-pixel smoothing, for features smaller than a pixel.
    const float lumaAverage = (2.0 * (lumaN + lumaS + lumaW + lumaE) + lumaNW + lumaNE + lumaSW + lumaSE) / 12.0;
    const float subPixel1 = saturate(abs(lumaAverage - lumaM) / range);
    const float subPixel2 = (-2.0 * subPixel1 + 3.0) * subPixel1 * subPixel1;
    const float subPixelOffset = subPixel2 * subPixel2 * SUBPIXEL;
    offset = max(offset, subPixelOffset);

    float2 finalUV = uv;
    if (horizontal) {
        finalUV.y += offset * stepLength;
    }
    else {
        finalUV.x += offset * stepLength;
    }

    return float4(gTexture0.SampleLevel(LinearSampler, finalUV, 0).rgb, center.a);
}
