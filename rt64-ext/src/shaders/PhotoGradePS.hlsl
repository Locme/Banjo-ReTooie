//
// RT64
//

// Banjo-Tooie: photo mode's filters on the finished game image, after SMAA and before the VI draws it,
// so screenshots show them. A look (a fixed colour treatment) first, then exposure, contrast,
// saturation, warmth, vignette and film grain. Then the crop frame (outside it shaded; screenshots keep
// only the frame) and the rule-of-thirds grid inside it.

#include "shared/rt64_photo_grade.h"

#include "Depth.hlsli"

[[vk::push_constant]] ConstantBuffer<PhotoGradeCB> gConstants : register(b0);

Texture2D<float4> gTexture0 : register(t1);
Texture2D<float4> gTexture1 : register(t2);
Texture2D<float4> gTexture2 : register(t3);
SamplerState LinearSampler : register(s4);
SamplerState PointSampler : register(s5);

float Luma(float3 rgb) {
    return dot(rgb, float3(0.2126f, 0.7152f, 0.0722f));
}

float3 Saturation(float3 rgb, float amount) {
    return lerp(Luma(rgb).xxx, rgb, amount);
}

float3 Contrast(float3 rgb, float amount) {
    return (rgb - 0.5f) * amount + 0.5f;
}

float3 Look(float3 rgb, uint look) {
    const float y = Luma(rgb);
    if (look == 1) {
        // Sepia.
        return float3(dot(rgb, float3(0.393f, 0.769f, 0.189f)), dot(rgb, float3(0.349f, 0.686f, 0.168f)), dot(rgb, float3(0.272f, 0.534f, 0.131f)));
    }
    else if (look == 2) {
        // Black and white.
        return y.xxx;
    }
    else if (look == 3) {
        // Noir: hard black and white.
        return saturate(Contrast(y.xxx, 1.6f));
    }
    else if (look == 4) {
        // Warm.
        return rgb * float3(1.10f, 1.0f, 0.85f);
    }
    else if (look == 5) {
        // Cool.
        return rgb * float3(0.88f, 0.98f, 1.12f);
    }
    else if (look == 6) {
        // Vivid.
        return Contrast(Saturation(rgb, 1.45f), 1.1f);
    }
    else if (look == 7) {
        // Faded film: lifted blacks, softer colour.
        return lerp(float3(0.08f, 0.07f, 0.06f), float3(0.95f, 0.93f, 0.88f), Saturation(rgb, 0.7f));
    }
    else if (look == 8) {
        // Teal and orange: shadows to teal, highlights to orange.
        return saturate(rgb + lerp(float3(-0.05f, 0.03f, 0.06f), float3(0.07f, 0.02f, -0.06f), smoothstep(0.2f, 0.8f, y)));
    }
    else if (look == 9) {
        // Dream: soft and bright, a little pink.
        return lerp(rgb, float3(1.0f, 0.92f, 0.95f), 0.18f) * 1.05f;
    }

    return rgb;
}

// The scene's depth at a pixel: gTexture1 holds RT64's depth-to-color copy, an N64 16-bit depth value
// packed as RGBA 5551. Returned as a distance (the game's near plane taken as 10 and far as 10000), so
// blur grows evenly with how far something is from the focus.
float SceneDistance(int2 pixel) {
    const float4 c = gTexture1.Load(int3(pixel, 0));
    const uint r = uint(round(saturate(c.r) * 255.0f)) >> 3;
    const uint g = uint(round(saturate(c.g) * 255.0f)) >> 3;
    const uint b = uint(round(saturate(c.b) * 255.0f)) >> 3;
    const uint a = (c.a > 0.5f) ? 1u : 0u;
    const float z = Depth16ToFloat((r << 11) | (g << 6) | (b << 1) | a);
    const float n = 10.0f;
    const float f = 10000.0f;
    return (n * f) / max(f - z * (f - n), 1e-3f);
}

// Depth of field: the nearest thing in a small box at the focus point (the middle unless photo mode moved it) is in focus, and the
// picture blurs more the further a pixel's distance is from it (in either direction), up to a radius
// set by the strength. A golden-angle spiral of taps gathers the blur.
float3 DepthOfField(float2 uv, float3 sharp, int2 pixel) {
    const float2 size = gConstants.rtMetrics.zw;
    float focus = 1e9f;
    [unroll] for (int y = -2; y <= 2; y++) {
        [unroll] for (int x = -2; x <= 2; x++) {
            const int2 probe = int2(size * gConstants.focus.xy) + int2(x, y) * int(max(1.0f, size.y / 90.0f));
            focus = min(focus, SceneDistance(clamp(probe, int2(0, 0), int2(size) - 1)));
        }
    }

    const float distance = SceneDistance(pixel);
    const float maxRadius = gConstants.dof.x * size.y / 60.0f;
    const float coc = saturate(abs(distance - focus) / max(focus, 1.0f)) * maxRadius;
    if (coc < 0.75f) {
        return sharp;
    }

    const int taps = 32;
    float3 sum = sharp;
    float weight = 1.0f;
    [loop] for (int i = 1; i <= taps; i++) {
        const float t = float(i) / float(taps);
        const float angle = float(i) * 2.39996323f;
        const float2 offset = float2(cos(angle), sin(angle)) * sqrt(t) * coc;
        const int2 tapPixel = clamp(pixel + int2(round(offset)), int2(0, 0), int2(size) - 1);
        // A sharp thing in front of the focus doesn't bleed into the blurred background behind it.
        const float tapDistance = SceneDistance(tapPixel);
        const float tapCoc = saturate(abs(tapDistance - focus) / max(focus, 1.0f)) * maxRadius;
        const float w = (tapDistance < distance) ? saturate(tapCoc / max(coc, 1e-3f)) : 1.0f;
        sum += gTexture0.Load(int3(tapPixel, 0)).rgb * w;
        weight += w;
    }

    return sum / weight;
}

// Contrast-adaptive sharpening: each pixel is pushed away from its four neighbours, less where the
// neighbourhood already has strong contrast, so edges don't ring and flat areas don't gain noise.
float3 Sharpen(int2 pixel, float3 center, float amount) {
    const int2 maxPixel = int2(gConstants.rtMetrics.zw) - 1;
    const float3 north = saturate(gTexture0.Load(int3(clamp(pixel + int2(0, -1), int2(0, 0), maxPixel), 0)).rgb);
    const float3 south = saturate(gTexture0.Load(int3(clamp(pixel + int2(0, 1), int2(0, 0), maxPixel), 0)).rgb);
    const float3 west = saturate(gTexture0.Load(int3(clamp(pixel + int2(-1, 0), int2(0, 0), maxPixel), 0)).rgb);
    const float3 east = saturate(gTexture0.Load(int3(clamp(pixel + int2(1, 0), int2(0, 0), maxPixel), 0)).rgb);
    const float3 c = saturate(center);
    const float3 lowest = min(c, min(min(north, south), min(west, east)));
    const float3 highest = max(c, max(max(north, south), max(west, east)));
    const float3 room = sqrt(saturate(min(lowest, 1.0f - highest) / max(highest, 1e-4f)));
    const float3 weight = -room * lerp(0.125f, 0.2f, amount);
    return saturate((c + (north + south + west + east) * weight) / (1.0f + 4.0f * weight));
}

float Hash(float2 p) {
    return frac(sin(dot(p, float2(12.9898f, 78.233f))) * 43758.5453f);
}

// Distance from p to the edge of its cell in a hexagon grid (cells r across, pointy side up): 0 on an edge.
float HexEdge(float2 p, float r) {
    const float2 spacing = float2(1.7320508f, 1.0f) * r;
    const float2 a = fmod(p, spacing) - spacing * 0.5f;
    const float2 b = fmod(p + spacing * 0.5f, spacing) - spacing * 0.5f;
    const float2 g = (dot(a, a) < dot(b, b)) ? a : b;
    const float2 q = abs(g);
    return r * 0.5f - max(q.x * 0.8660254f + q.y * 0.5f, q.y);
}

// Photo frames drawn over the edge of the crop frame (so screenshots keep them), in Banjo-Tooie's colours:
// 1 instant photo, 2 film strip, 3 honeycomb, 4 Jiggy (gold with puzzle knobs), 5 wooden (the menus' brown
// and gold). local is the pixel inside the frame, size the frame's size, in pixels.
float3 PhotoBorder(float3 rgb, float2 local, float2 size, uint style) {
    const float unit = min(size.x, size.y);
    const float2 fromEdge = min(local, size - local);
    const float edge = min(fromEdge.x, fromEdge.y);
    const float px = max(1.0f, unit / 540.0f);
    if (style == 1u) {
        // White card, wider at the bottom, with a faint paper texture and a soft shadow inside.
        const float side = unit * 0.045f;
        const float bottom = unit * 0.17f;
        const bool card = (local.x < side) || (local.x > size.x - side) || (local.y < side) || (local.y > size.y - bottom);
        if (card) {
            return float3(0.96f, 0.95f, 0.91f) - 0.025f * Hash(floor(local / (2.0f * px)));
        }
        const float inner = min(min(local.x - side, size.x - side - local.x), min(local.y - side, size.y - bottom - local.y));
        return rgb * lerp(0.75f, 1.0f, saturate(inner / (6.0f * px)));
    }
    if (style == 2u) {
        // Black bands top and bottom with sprocket holes.
        const float band = unit * 0.1f;
        const float fromBand = min(local.y, size.y - local.y);
        if (fromBand < band) {
            const float pitch = band * 0.75f;
            const float2 hole = float2(fmod(local.x, pitch) - pitch * 0.5f, fromBand - band * 0.5f);
            const float2 holeSize = float2(pitch * 0.28f, band * 0.22f);
            const float2 d = abs(hole) - holeSize;
            const float rounded = length(max(d, 0.0f)) + min(max(d.x, d.y), 0.0f) - band * 0.06f;
            return (rounded < 0.0f) ? float3(0.86f, 0.84f, 0.8f) : float3(0.06f, 0.05f, 0.05f);
        }
        return rgb;
    }
    if (style == 3u) {
        // A band of golden honeycomb.
        const float band = unit * 0.08f;
        if (edge < band) {
            const float h = HexEdge(local, unit * 0.045f);
            const float3 wax = lerp(float3(1.0f, 0.62f, 0.05f), float3(1.0f, 0.82f, 0.25f), saturate(h / (unit * 0.02f)));
            const float3 cell = (h < 1.5f * px) ? float3(0.55f, 0.3f, 0.02f) : wax;
            return (edge > band - 2.0f * px) ? float3(0.45f, 0.24f, 0.02f) : cell;
        }
        return rgb;
    }
    if (style == 4u) {
        // A gold band with round puzzle knobs pushing into the picture along each side.
        const float band = unit * 0.045f;
        const float knob = band * 0.85f;
        const float2 pitch = size / max(round(size / (unit * 0.25f)), 1.0f);
        float inside = edge - band;
        // The knob nearest this pixel on the nearest side.
        float2 centre = local;
        if (fromEdge.x < fromEdge.y) {
            centre.x = (local.x < size.x * 0.5f) ? band : size.x - band;
            centre.y = (floor(local.y / pitch.y) + 0.5f) * pitch.y;
        } else {
            centre.y = (local.y < size.y * 0.5f) ? band : size.y - band;
            centre.x = (floor(local.x / pitch.x) + 0.5f) * pitch.x;
        }
        inside = min(inside, length(local - centre) - knob);
        if (inside < 0.0f) {
            const float shade = saturate(-inside / band);
            const float3 gold = lerp(float3(0.85f, 0.5f, 0.02f), float3(1.0f, 0.86f, 0.3f), shade);
            return (inside > -1.5f * px) ? float3(0.45f, 0.22f, 0.0f) : gold;
        }
        return rgb * lerp(0.7f, 1.0f, saturate(inside / (5.0f * px)));
    }
    if (style == 5u) {
        // Wood with a gold line inside, as the menus.
        const float band = unit * 0.06f;
        if (edge < band) {
            const float along = (fromEdge.x < fromEdge.y) ? local.y : local.x;
            const float grain = sin(along * 0.05f / px + 6.0f * sin(edge * 0.11f / px)) * 0.5f + 0.5f;
            const float3 wood = lerp(float3(0.2f, 0.1f, 0.03f), float3(0.38f, 0.2f, 0.07f), grain);
            const float fromInside = band - edge;
            if (fromInside < 3.0f * px) {
                return float3(1.0f, 0.77f, 0.19f);
            }
            return wood * lerp(0.75f, 1.0f, saturate(edge / band));
        }
        return rgb;
    }
    return rgb;
}

float4 PSMain(in float4 pos : SV_Position, in float2 uv : TEXCOORD0) : SV_TARGET {
    float4 color = gTexture0.SampleLevel(PointSampler, uv, 0);
    // F8 compare: the right half as it was, a line down the middle.
    if (gConstants.frame.z > 0.5f) {
        const float middle = gConstants.rtMetrics.z * 0.5f;
        if (abs(pos.x - middle) < max(1.0f, gConstants.rtMetrics.w / 540.0f)) {
            return float4(1.0f, 1.0f, 1.0f, color.a);
        }
        if (pos.x >= middle) {
            return color;
        }
    }
    if (gConstants.dof.w > 0.0f) {
        color.rgb = Sharpen(int2(pos.xy), color.rgb, gConstants.dof.w);
    }
    if ((gConstants.dof.x > 0.0f) && (gConstants.dof.y > 0.5f)) {
        color.rgb = DepthOfField(uv, color.rgb, int2(pos.xy));
    }
    float3 rgb = Look(saturate(color.rgb), uint(gConstants.effects.w + 0.5f));
    rgb *= exp2(gConstants.tone.x);
    rgb = Contrast(rgb, 1.0f + gConstants.tone.y);
    rgb = Saturation(rgb, 1.0f + gConstants.tone.z);
    rgb *= float3(1.0f + 0.12f * gConstants.tone.w, 1.0f, 1.0f - 0.12f * gConstants.tone.w);

    // Vignette: darkens towards the corners.
    const float2 centered = (uv - 0.5f) * float2(gConstants.rtMetrics.z / gConstants.rtMetrics.w, 1.0f);
    rgb *= 1.0f - gConstants.effects.x * smoothstep(0.35f, 1.0f, length(centered) * 1.2f);

    // Film grain: soft clumps sized to the picture (about two pixels at 1080p), so it reads the same at
    // any resolution, strongest in the mid tones like real film.
    const float grainSize = max(gConstants.rtMetrics.w / 540.0f, 1.0f);
    const float2 grainAt = pos.xy / grainSize + frac(gConstants.effects.z) * 517.0f;
    const float2 cell = floor(grainAt);
    const float2 f = smoothstep(0.0f, 1.0f, grainAt - cell);
    const float noise = lerp(lerp(Hash(cell), Hash(cell + float2(1.0f, 0.0f)), f.x),
        lerp(Hash(cell + float2(0.0f, 1.0f)), Hash(cell + float2(1.0f, 1.0f)), f.x), f.y) - 0.5f;
    const float midTones = 0.6f + 1.6f * Luma(rgb) * (1.0f - Luma(rgb));
    rgb += noise * 0.3f * midTones * gConstants.effects.y;
    rgb = saturate(rgb);

    // The crop frame: the largest rectangle of that shape in the middle of the picture.
    float2 frameMin = float2(0.0f, 0.0f);
    float2 frameSize = gConstants.rtMetrics.zw;
    const float cropAspect = gConstants.frame.x;
    if (cropAspect > 0.0f) {
        const float aspect = gConstants.rtMetrics.z / gConstants.rtMetrics.w;
        frameSize = (cropAspect < aspect) ? float2(frameSize.y * cropAspect, frameSize.y) : float2(frameSize.x, frameSize.x / cropAspect);
        frameMin = (gConstants.rtMetrics.zw - frameSize) * 0.5f;
        if (any(pos.xy < frameMin) || any(pos.xy >= frameMin + frameSize)) {
            rgb *= 0.3f;
        }
    }

    // The photo frame's border (frame.w: 0 none), kept in screenshots.
    const uint border = uint(gConstants.frame.w + 0.5f);
    if (border != 0u) {
        const float2 local = pos.xy - frameMin;
        if (all(local >= 0.0f) && all(local < frameSize)) {
            rgb = PhotoBorder(rgb, local, frameSize, border);
        }
    }

    // Rule-of-thirds grid: thin light lines at the thirds of the frame.
    if (gConstants.frame.y > 0.5f) {
        const float2 local = pos.xy - frameMin;
        const float thickness = max(1.0f, gConstants.rtMetrics.w / 540.0f);
        bool onLine = false;
        [unroll] for (int i = 1; i <= 2; i++) {
            const float2 at = frameSize * (float(i) / 3.0f);
            onLine = onLine || (abs(local.x - at.x) < thickness * 0.5f) || (abs(local.y - at.y) < thickness * 0.5f);
        }
        if (onLine && all(local >= 0.0f) && all(local < frameSize)) {
            rgb = lerp(rgb, float3(1.0f, 1.0f, 1.0f), 0.45f);
        }
    }

    return float4(rgb, color.a);
}
