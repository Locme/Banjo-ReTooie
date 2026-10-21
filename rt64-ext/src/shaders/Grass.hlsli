//
// RT64
//

// Banjo-Tooie: 3D grass, in the style of stylised open-field grass. The level's ground draws are drawn
// again as shells, each moved further up by its share of the blade height (RasterVS.hlsl); each shell keeps
// only where a blade crosses it, so a stack of them reads as a field of blades. The blades grow in tufts,
// one tuft per cell of a grid over the world's x and z: five thin, flat blades that arc out from the middle and
// taper to a point. Wind waves roll across the field and bend them, and they are pushed down and away round
// Banjo and along the trail he leaves, springing back up behind him. Dark at the roots, lighter and yellower
// at the tips, and shorter with distance.

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_SHADERS_GRASS_HLSLI
#define RT64_EXT_SHADERS_GRASS_HLSLI

#include "FbRendererCommon.hlsli"

static const uint GrassTrailPoints = 12;
static const uint GrassTuftBlades = 5;

// The world position at a pixel of a shell, from its depth, as SceneEffectsPS.hlsl works out view positions.
float3 GrassWorldPosition(float4 pixelPosition) {
    const float4 t = FrParams.grassDepthTerms;
    const float ndcZ = pixelPosition.z * 2.0f - 1.0f;
    const float z = (t.y - ndcZ * t.w) / (ndcZ * t.z - t.x);
    const float4 p = FrParams.grassProjection;
    const float2 ndc = float2(pixelPosition.x / p.z * 2.0f - 1.0f, 1.0f - pixelPosition.y / p.w * 2.0f);
    const float3 view = float3(ndc.x * -z / p.x, ndc.y * -z / p.y, z);
    return float3(
        dot(view, FrParams.grassWorldX.xyz) + FrParams.grassWorldX.w,
        dot(view, FrParams.grassWorldY.xyz) + FrParams.grassWorldY.w,
        dot(view, FrParams.grassWorldZ.xyz) + FrParams.grassWorldZ.w);
}

float3 GrassHash(float2 cell) {
    uint2 c = uint2(int2(cell) + 0x8000);
    uint h = c.x * 0x8DA6B343u ^ c.y * 0xD8163841u;
    h ^= h >> 13;
    h *= 0x5BD1E995u;
    h ^= h >> 15;
    const uint h2 = h * 0x27D4EB2Du;
    const uint h3 = h2 * 0x165667B1u;
    return float3(h & 0xFFFF, h2 & 0xFFFF, h3 & 0xFFFF) / 65535.0f;
}

// Smooth value noise over the world's x and z.
float GrassPatchNoise(float2 p) {
    const float2 i = floor(p);
    const float2 f = frac(p);
    const float2 u = f * f * (3.0f - 2.0f * f);
    return lerp(lerp(GrassHash(i).x, GrassHash(i + float2(1.0f, 0.0f)).x, u.x), lerp(GrassHash(i + float2(0.0f, 1.0f)).x, GrassHash(i + 1.0f).x, u.x), u.y);
}

// Whether a shell's pixel at height share (0 to 1) is part of a blade; if so, shades it from root to tip.
bool GrassShell(float3 world, float3 worldDx, float3 worldDy, float3 baseColor, float share, inout float3 color) {
    // Green ground only (grass, not dirt, rock or paths).
    if (!((baseColor.g - max(baseColor.r, baseColor.b) > 0.03f) && (baseColor.g > baseColor.b * 1.25f))) {
        return false;
    }

    // Ground facing up: the shell lies parallel to it, so its slopes give the ground's normal.
    const float3 normal = cross(worldDx, worldDy);
    const float normalLength = length(normal);
    if ((normalLength <= 0.0f) || (abs(normal.y) < 0.6f * normalLength)) {
        return false;
    }

    // Shorter blades further away, gone by the fade distance.
    const float4 params = FrParams.grassParams;
    const float height = params.x;
    const float3 camera = float3(FrParams.grassWorldX.w, FrParams.grassWorldY.w, FrParams.grassWorldZ.w);
    const float cameraDistance = distance(world, camera);
    const float fade = saturate(1.0f - cameraDistance / params.z);
    // Further away the blades widen, so they don't thin to flickering lines.
    const float widen = 1.0f + cameraDistance / 700.0f;
    if (fade < 0.05f) {
        return false;
    }

    // Only in patches (as GrassGS.hlsl), shorter toward their edges.
    float patchAmount = 1.0f;
    if (FrParams.grassPatches.x < 0.999f) {
        const float2 p = world.xz / FrParams.grassPatches.y;
        const float n = GrassPatchNoise(p + 41.0f) * 0.7f + GrassPatchNoise(p * 2.6f + 97.0f) * 0.3f;
        const float threshold = lerp(0.8f, 0.2f, FrParams.grassPatches.x);
        patchAmount = smoothstep(threshold, threshold + 0.1f, n);
        if (patchAmount <= 0.0f) {
            return false;
        }
    }

    // Wind: a slow wave rolling across the field along the wind, a faster cross wave, and a little flutter.
    const float4 wind = FrParams.grassWind;
    const float2 windDir = normalize(wind.xy);
    const float2 windSide = float2(-windDir.y, windDir.x);
    const float time = wind.z;
    const float along = dot(world.xz, windDir);
    const float across = dot(world.xz, windSide);
    const float wave = 0.5f + 0.5f * sin(along * (6.2832f / 320.0f) - time * 1.9f + 0.8f * sin(across * (6.2832f / 900.0f)));
    const float ripple = 0.5f + 0.5f * sin(dot(world.xz, float2(0.043f, -0.061f)) - time * 3.1f);
    const float push = wave * wave * 0.75f + ripple * 0.25f;
    float2 lean = windDir * height * wind.w * (0.08f + 0.42f * push);
    lean += windSide * height * 0.05f * sin(time * 4.3f + along * 0.11f + across * 0.07f);

    // Pressed down and away round Banjo and along his trail; older trail points spring back (and overshoot a little).
    const float groundY = world.y - share * height;
    const float radius = FrParams.grassPlayer.w;
    float flatten = 0.0f;
    float2 pushed = 0.0f;
    const float4 bounds = FrParams.grassTrailBounds;
    const bool nearTrail = all(world.xz >= bounds.xy) && all(world.xz <= bounds.zw);
    for (uint i = 0; nearTrail && (i <= GrassTrailPoints); i++) {
        const float4 trail = (i == GrassTrailPoints) ? float4(FrParams.grassPlayer.xyz, 1.0f) : FrParams.grassTrail[i];
        if ((trail.w == 0.0f) || (trail.z < -1e8f) || (abs(groundY - trail.z) > 80.0f)) {
            continue;
        }

        const float2 away = world.xz - trail.xy;
        const float awayLength = length(away);
        if (awayLength >= radius) {
            continue;
        }

        const float k = 1.0f - awayLength / radius;
        const float strength = trail.w * k * k * (3.0f - 2.0f * k);
        pushed += (awayLength > 0.001f ? away / awayLength : windDir) * strength;
        flatten = max(flatten, strength);
    }

    // Under Banjo the blades lie nearly flat; the wind matters less there.
    lean = lerp(lean, 0.0f, saturate(flatten)) + pushed * height * 0.95f;
    const float leanLength = length(lean);
    if (leanLength > height * 0.95f) {
        lean *= height * 0.95f / leanLength;
    }

    // A leaning blade's tip is lower, so the shells it reaches are fewer.
    const float leanShare = min(leanLength / height, 0.95f);
    const float tallness = fade * lerp(0.3f, 1.0f, patchAmount) * (1.0f - 0.55f * leanShare * leanShare) * (1.0f - 0.45f * saturate(flatten));

    // The blades curve: the higher up, the further the shell's point is from the blade's root. Blades arc out
    // of their tuft by up to half a cell. Tufts sit 0.2 to 0.8 of the way across their cell, so the four
    // cells nearest the point hold every tuft that can reach it.
    const float2 root = (world.xz - lean * pow(share, 1.5f)) * params.y;
    const float2 first = floor(root - 0.5f);
    const float reach = 0.5f * saturate(share * share / max(0.1f * tallness * tallness, 1e-4f)) + 0.15f * widen;
    for (int c = 0; c < 4; c++) {
        const float2 cell = first + float2(c & 1, c >> 1);
        const float3 tuft = GrassHash(cell);
        const float2 local = root - cell;
        const float2 center = 0.2f + 0.6f * tuft.yz;
        const float3 tuft2 = GrassHash(cell + 7919.0f);
        const float tuftHeight = lerp(0.7f, 1.0f, tuft2.x) * tallness;
        const float2 toCenter = local - center;
        if ((tuft.x > params.w) || (share > tuftHeight) || (dot(toCenter, toCenter) > reach * reach)) {
            continue;
        }

        // The blades fan out evenly round the tuft (a turn of a fifth each), each nudged a little.
        float2 dir = float2(cos(tuft2.y * 6.2832f), sin(tuft2.y * 6.2832f));
        for (uint b = 0; b < GrassTuftBlades; b++) {
            dir = float2(dir.x * 0.309f - dir.y * 0.951f, dir.x * 0.951f + dir.y * 0.309f);
            const float3 r = GrassHash(cell + float(b + 1) * 131.0f);
            const float bladeHeight = tuftHeight * lerp(0.45f, 1.0f, r.z);
            if (share > bladeHeight) {
                continue;
            }

            // h runs from 0 at the root to 1 at the tip. The blade arcs out from the tuft's middle.
            const float h = share / bladeHeight;
            const float2 bladeDir = normalize(dir + (r.xy - 0.5f) * 0.6f);
            const float2 d = toCenter - bladeDir * (0.05f * r.y + (0.12f + 0.33f * r.y) * h * h);

            // Flat and wide across, thin through, tapering to a point.
            const float halfWidth = (0.06f * pow(1.0f - h, 0.8f) + 0.01f) * widen;
            const float halfThickness = 0.035f * widen;
            if ((abs(dot(d, float2(-bladeDir.y, bladeDir.x))) > halfWidth) || (abs(dot(d, bladeDir)) > halfThickness)) {
                continue;
            }

            // Dark at the roots, lighter and yellower at the tips; each blade a little different, and
            // brighter where the wind lays the blades over.
            float3 shade = color * lerp(0.4f, 1.05f, h) * lerp(0.85f, 1.12f, r.z);
            shade = lerp(shade, shade * float3(1.3f, 1.22f, 0.65f) + float3(0.04f, 0.045f, 0.0f), h * h * 0.75f);
            shade *= 1.0f + 0.16f * push * h * (1.0f - saturate(flatten));
            color = shade;
            return true;
        }
    }

    return false;
}

// A real blade (GrassGS.hlsl): kept only when the ground at its root (baseColor, from the root's texture
// coordinates) is green, then shaded dark at the root to bright and warm at the tip by its height over the root,
// with broad patches of lighter, yellower grass across the field.
// Whether a point (s across, t up, as GrassBladePoint in GrassGS.hlsl) is in the blade: a chunky blade is one
// triangle, the others narrow to 0.75 of their width at t 0.55, then to the tip.
bool GrassBladeCovers(float2 st) {
    if ((st.y < 0.0f) || (st.y > 1.0f)) {
        return false;
    }

    const float width = (FrParams.grassStyle.x > 0.5f) ? (1.0f - st.y) : ((st.y < 0.55f) ? lerp(1.0f, 0.75f, st.y / 0.55f) : 0.75f * (1.0f - st.y) / 0.45f);
    return abs(st.x) <= width;
}

bool GrassBlade(float3 world, float3 baseColor, float rootY, inout float3 color) {
    if (!((baseColor.g - max(baseColor.r, baseColor.b) > 0.03f) && (baseColor.g > baseColor.b * 1.25f))) {
        return false;
    }

    // Retro blades are one colour all the way up, as at 60% of the way to the tip.
    const float t = (FrParams.grassStyle.x > 0.5f) ? 0.6f : saturate((world.y - rootY) / max(FrParams.grassParams.x, 1.0f));
    const float patch = smoothstep(0.5f, 0.85f, GrassPatchNoise(world.xz / 240.0f + 17.0f));
    const float variation = GrassPatchNoise(world.xz / 37.0f);
    float3 shade = color * lerp(0.42f, 1.08f, t) * lerp(0.9f, 1.08f, variation);
    shade = lerp(shade, shade * float3(1.3f, 1.24f, 0.62f) + float3(0.045f, 0.05f, 0.0f), t * t * 0.8f);
    shade = lerp(shade, shade * float3(1.18f, 1.15f, 0.7f) + float3(0.03f, 0.03f, 0.0f), patch * 0.6f * t);

    // Blending (grassLook.x, 0 to 1): the blades take on the ground's own colour, most at the root (no dark line
    // where they meet the ground) and further away, so they melt into the ground instead of standing out.
    const float blend = FrParams.grassLook.x;
    if (blend > 0.0f) {
        const float3 camera = float3(FrParams.grassWorldX.w, FrParams.grassWorldY.w, FrParams.grassWorldZ.w);
        const float far = smoothstep(0.2f, 0.8f, distance(world, camera) / max(FrParams.grassParams.z, 1.0f));
        shade = lerp(shade, color, saturate(blend * max(lerp(1.0f, 0.35f, t), far)));
    }

    color = shade;
    return true;
}

#endif // RT64_EXT_SHADERS_GRASS_HLSLI
