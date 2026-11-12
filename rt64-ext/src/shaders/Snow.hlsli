//
// RT64
//

// Banjo-Tooie: deep snow that Banjo wades through, in the style of Red Dead Redemption 2's. The level's snowy ground
// draws are drawn again as shells, each moved further up by its share of the snow's full height (RasterVS.hlsl); each
// shell keeps only where the snow reaches it, so a stack of them reads as a layer of snow lying on the ground, with
// soft drifts in it. Banjo presses a furrow and footprints into it as he goes, the snow he pushes aside banks up
// either side, and after a while it all fills back in. The snow is pressed wherever a model's triangles reach into it
// (Banjo, the NPCs and enemies, anything thrown): ComputeSceneSnow keeps the lowest each reached to in a grid of cells
// that wraps round over the world's x and z (snowTrail, SnowTouchCell in rt64_scene_effects.cpp).
//
// The shells are drawn from the top down, so where one keeps a pixel the ones below it are hidden by the depth
// test before they are shaded, and SnowShellShape throws away a shell's pixels above the snow before the draw's
// textures and colours are worked out: most pixels are shaded once or twice, not once for every shell.

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_SHADERS_SNOW_HLSLI
#define RT64_EXT_SHADERS_SNOW_HLSLI

#include "FbRendererCommon.hlsli"
#include "CellHash.hlsli"

// Snowy ground: light and not very colourful (white, lilac or a little warm in the sun). On Icy Side not the ice's
// cyan (its pale streaks are as light as snow, but greener and bluer than red); in Chilly Willy's arena the snow
// itself is bluish white (snowColor, from the map).
// Tessellated sand instead of deep snow (SetSceneSnow's sand): shallow, shaded as sand, rippled by the wind.
bool SnowSand() {
    return FrParams.snowLod.w > 0.5f;
}

// Smooth value noise (0 to 1).
float SnowNoise(float2 p) {
    const float2 i = floor(p);
    const float2 f = frac(p);
    const float2 u = f * f * (3.0f - 2.0f * f);
    const float a = SceneCellHash(i).x;
    const float b = SceneCellHash(i + float2(1.0f, 0.0f)).x;
    const float c = SceneCellHash(i + float2(0.0f, 1.0f)).x;
    const float d = SceneCellHash(i + float2(1.0f, 1.0f)).x;
    return lerp(lerp(a, b, u.x), lerp(c, d, u.x), u.y);
}

// One set of wind ripples' slope: ridges across wind, spacing wavelength, bent along their length by warp.
float2 SandRippleSet(float2 xz, float2 wind, float wavelength, float warp) {
    const float theta = (dot(xz, wind) + warp) / wavelength * 6.2831853f;
    // (A ridge gentle up the windward side, steeper down the lee: sin + a quarter of its second harmonic.)
    const float rise = cos(theta) + 0.5f * cos(2.0f * theta);
    return wind * (rise * 6.2831853f / wavelength);
}

// The slope (d height / dx, dz) of the ripples the wind leaves in sand at a world position: two sets of low ridges
// from winds a little apart (10 and 8.5 units apart), their strength changing from place to place, bent and with
// their crests broken off here and there, so no stretch repeats; fading out by distance before they are finer than the
// pixels. (Each set's spacing is the same everywhere: one that changed from place to place, worked out as the world
// position over a varying wavelength, changed the ridges' phase faster the further from the world's middle, and far
// out drew tight rings of moire over the sand.)
float2 SandRippleSlope(float2 xz, float cameraDistance) {
    const float fade = saturate(1.0f - cameraDistance / 900.0f);
    if (fade <= 0.0f) {
        return 0.0f;
    }
    const float warp = 14.0f * SnowNoise(xz / 60.0f) + 5.0f * SnowNoise(xz / 19.0f + 5.0f) + 1.5f * SnowNoise(xz / 6.0f + 9.0f);
    const float wavelengthA = 10.0f;
    const float wavelengthB = 8.5f;
    // Which wind shaped which stretch, and stretches the wind left nearly smooth.
    const float mix = smoothstep(0.3f, 0.7f, SnowNoise(xz / 55.0f + 23.0f));
    const float strength = smoothstep(0.2f, 0.75f, SnowNoise(xz / 40.0f + 11.0f));
    // Crests broken off along their length.
    const float broken = lerp(0.25f, 1.0f, smoothstep(0.25f, 0.75f, SnowNoise(xz / 8.0f + 41.0f)));
    const float2 slope = SandRippleSet(xz, float2(0.8f, 0.6f), wavelengthA, warp) * (1.0f - mix) +
        SandRippleSet(xz, float2(0.34f, 0.94f), wavelengthB, warp * 0.7f + 3.0f) * mix;
    const float amplitude = 0.35f;
    return slope * (amplitude * lerp(0.15f, 1.0f, strength) * broken * fade);
}

// Smooth value noise as SnowNoise (x), with its slope (d / dp.x, d / dp.y in yz).
float3 SnowNoiseSlope(float2 p) {
    const float2 i = floor(p);
    const float2 f = p - i;
    const float2 u = f * f * (3.0f - 2.0f * f);
    const float2 du = 6.0f * f * (1.0f - f);
    const float a = SceneCellHash(i).x;
    const float b = SceneCellHash(i + float2(1.0f, 0.0f)).x;
    const float c = SceneCellHash(i + float2(0.0f, 1.0f)).x;
    const float d = SceneCellHash(i + float2(1.0f, 1.0f)).x;
    const float k = a - b - c + d;
    return float3(a + (b - a) * u.x + (c - a) * u.y + k * u.x * u.y, du * float2((b - a) + k * u.y, (c - a) + k * u.x));
}

// The untouched snow and sand have a shape of their own over the ground (the N64's ground under them is flat between
// its few points): the tessellated snow is cut finely enough near the camera to follow it (SnowTess.hlsl), and the
// pixels are lit by its slope, so it shows in both outline and light. Sand's is lit only: it lies so close to the
// level's ground that the finer cut flickered against it. Whole up to the Snow LOD distance, then faded
// out by twice that so it never pops. (The game's camera usually watches Banjo from 1000 to 1500 units away, and the
// snow round him lies further off still.)
float SnowSurfaceFade(float cameraDistance) {
    const float start = max(FrParams.snowLod.x, 1.0f);
    return saturate(2.0f - cameraDistance / start);
}

// How far apart the tessellated surface's new vertices are for its own shape at a distance from the camera (world
// units): about as many pixels apart everywhere (some 10 at 1080p), as in adaptive displacement tessellation, never
// finer than a few units.
float SnowSurfaceSegment(float cameraDistance) {
    return max(SnowSand() ? 8.0f : 6.0f, cameraDistance * 0.008f);
}

// About how wide one pixel is at a distance from the camera (world units), at 1080p (snowCamera.w is the projection's
// y scale): for fading out detail finer than the pixels.
float SnowPixelSize(float cameraDistance) {
    return cameraDistance * 2.0f / (max(FrParams.snowCamera.w, 0.1f) * 1080.0f);
}

// How much of a wave of a wavelength to keep when the points that show it are segment apart: all of it from five
// points a wave, none below three, where it would only swim as the points slide over it with the camera.
float SnowWaveKept(float wavelength, float segment) {
    return saturate((wavelength / max(segment, 1e-3f) - 3.0f) * 0.5f);
}

// One layer of noise of the surface's shape, stretched along the wind (along) and across it (across, world units a
// bump), up and down by amplitude: its height (x) and slope (d / dx, dz in yz). ridge: sharpened into crests along the
// wind, as wind-carved snow is.
float3 SnowShapeLayer(float2 xz, float along, float across, float2 offset, float amplitude, bool ridge) {
    const float2 wind = float2(0.8f, 0.6f);
    const float2 side = float2(-0.6f, 0.8f);
    const float3 n = SnowNoiseSlope(float2(dot(xz, wind) / along, dot(xz, side) / across) + offset);
    const float2 slope = n.y * wind / along + n.z * side / across;
    if (ridge) {
        // (1 - (2n - 1)^2, centred: a crest where the noise passes its middle.)
        const float r = 2.0f * n.x - 1.0f;
        return amplitude * float3(0.5f - r * r, -4.0f * r * slope);
    }
    return amplitude * float3(2.0f * n.x - 1.0f, 2.0f * slope);
}

// The untouched surface's own shape (height over its even depth, then slope) at a world position, by the spacing of
// the points that show it (segment: SnowSurfaceSegment for the tessellated surface, a few pixels for its light).
// Snow: broad drifts, wind-carved ridges (sastrugi) along the wind and small lumps, up to about two thirds of its
// depth up or down. Sand: broad swells and the big ripples the wind builds (megaripples, ridges across it about 90 units apart,
// steeper on their lee side), under the small ripples SandRippleSlope lights.
float3 SnowSurfaceShape(float2 xz, float depth, float segment) {
    float3 shape = 0.0f;
    if (SnowSand()) {
        shape += SnowShapeLayer(xz, 300.0f, 300.0f, float2(31.0f, 7.0f), 0.35f * depth * SnowWaveKept(300.0f, segment), false);
        // (One spacing everywhere, as SandRippleSlope's; the warp bends the ridges.)
        const float wavelength = 90.0f;
        const float kept = SnowWaveKept(wavelength, segment);
        if (kept > 0.0f) {
            const float2 wind = float2(0.8f, 0.6f);
            const float warp = 60.0f * SnowNoise(xz / 260.0f + 7.0f);
            const float strength = smoothstep(0.25f, 0.8f, SnowNoise(xz / 180.0f + 29.0f));
            const float theta = (dot(xz, wind) + warp) / wavelength * 6.2831853f;
            const float amplitude = 0.15f * depth * strength * kept;
            // (sin + a quarter of its second harmonic, as the small ripples: gentle up the windward side, steep down the lee.)
            shape += amplitude * float3(sin(theta) + 0.25f * sin(2.0f * theta), wind * ((cos(theta) + 0.5f * cos(2.0f * theta)) * 6.2831853f / wavelength));
        }
        return shape;
    }
    shape += SnowShapeLayer(xz, 260.0f, 200.0f, float2(3.0f, 11.0f), 0.4f * depth * SnowWaveKept(200.0f, segment), false);
    shape += SnowShapeLayer(xz, 150.0f, 45.0f, float2(17.0f, 5.0f), 0.22f * depth * SnowWaveKept(45.0f, segment), true);
    shape += SnowShapeLayer(xz, 30.0f, 30.0f, float2(43.0f, 29.0f), 0.06f * depth * SnowWaveKept(30.0f, segment), false);
    return shape;
}

// One size of grains for SnowSparkle: a cell of size cell holds a grain by chance (each size its own grains, seed),
// each grain a tiny mirror tipped off the surface's normal by up to spread, flashing when it faces h.
float SnowGrains(float2 xz, float3 normal, float3 h, float cell, float seed, float chance, float spread, float power) {
    const float2 p = xz / cell;
    const float2 c = floor(p);
    const float3 g = SceneCellHash(c + seed * 1013.0f);
    if (g.x >= chance) {
        return 0.0f;
    }
    const float3 g2 = SceneCellHash(c + seed * 1013.0f + 71.0f);
    const float3 facet = normalize(normal + float3((g.y - 0.5f) * 2.0f * spread, 0.0f, (g.z - 0.5f) * 2.0f * spread));
    // (A round grain somewhere in its cell, not the whole square.)
    const float2 centre = 0.5f + (g2.yz - 0.5f) * 0.4f;
    const float grain = saturate(1.0f - length(p - c - centre) / 0.3f);
    return pow(saturate(dot(facet, h)), power) * lerp(0.5f, 1.0f, g2.x) * grain;
}

// A sparkle off grains lying at fixed places in the world (SnowGrains): each flashes when it faces halfway between the
// light and the eye, so as the camera moves each one fades in and out smoothly and none jumps. Further off, where a
// grain of cell would be smaller than a pixel, bigger and sparser grains stand in, sized by the pixels (about three
// to a cell) and blended between two sizes as mip levels are, so the sparkle neither flickers nor thins out with
// distance. (After Zirr and Kaplanyan's multiscale glints, I3D 2016, and the glitter in Edwards' Sand Rendering in
// Journey, GDC 2013, simplified.)
float SnowSparkle(float2 xz, float3 normal, float3 view, float cameraDistance, float cell, float chance, float spread, float power) {
    const float3 light = FrParams.snowLight.xyz;
    if (light.y <= 0.05f) {
        return 0.0f;
    }
    const float3 h = normalize(light + view);
    const float level = log2(max(SnowPixelSize(cameraDistance) * 3.0f / cell, 1.0f));
    const float first = floor(level);
    const float t = level - first;
    const float near = SnowGrains(xz, normal, h, cell * exp2(first), first, chance, spread, power);
    const float far = (t > 0.0f) ? SnowGrains(xz, normal, h, cell * exp2(first + 1.0f), first + 1.0f, chance, spread, power) : 0.0f;
    return lerp(near, far, t);
}

bool SnowColor(float3 baseColor) {
    const float brightest = max(baseColor.r, max(baseColor.g, baseColor.b));
    const float darkest = min(baseColor.r, min(baseColor.g, baseColor.b));
    const float luma = dot(baseColor, float3(0.3f, 0.59f, 0.11f));
    const float4 limits = FrParams.snowColor;
    return (luma > limits.w) && ((brightest - darkest) < limits.z * brightest) && (baseColor.g - baseColor.r < limits.x) && (baseColor.b - baseColor.r < limits.y);
}

// The deepest a game's own snow layer over the ground Banjo walks on is pressed through to his feet (world units).
static const float SnowLayerMost = 120.0f;

// How far a print's floor has risen once it has filled back in (SnowRefillRise in rt64_scene_effects.cpp).
static const float SnowRefillRise = 260.0f;

// How far one cell is pressed down (x, 0 to 1 of the snow's depth) and banked up (y) now, after filling back in for as
// long as it has been, and how far below this ground the print's floor lies, times x (z); 0 for a cell that holds
// another part of the world, or a print on another floor. A cell holds the lowest a model reached down to there
// (ComputeSceneSnow), so the snow is pressed as far as that reaches below its top: a light touch a little, a foot down
// to the ground, something passing over it not at all.
float3 SnowCell(int2 cell, float groundY) {
    const int n = int(FrParams.snowGrid.z);
    const int2 slot = ((cell % n) + n) % n;
    const uint2 tag = uint2((cell - slot) / n) & 0xFFu;
    const uint index = (uint(slot.y) * uint(n) + uint(slot.x)) * 2;
    const uint b = snowTrail[index + 1];
    if ((b == 0) || (((b >> 16) & 0xFFu) != tag.x) || ((b >> 24) != tag.y)) {
        return 0.0f;
    }
    const uint a = snowTrail[index];
    // Icy Side's own snow is drawn as a layer up to about 50 units over the ground Banjo walks on (his legs sink into
    // it), and the snow ground can lie a little below his feet elsewhere; a print further from the ground than that
    // belongs to another floor.
    const float touchY = float(int(a) >> 8) / 16.0f;
    const float above = groundY - touchY;
    // (Past a sloped wall's full rise above it, SnowWallRise: another floor's print or bank.)
    if ((above > 200.0f) || (above < -220.0f)) {
        return 0.0f;
    }
    const float4 spring = FrParams.snowSpring;
    const float age = float((uint(spring.w) - (b & 0xFFFFu)) & 0xFFFFu) / 20.0f;
    const float t = saturate((age - spring.x) / max(spring.y, 1.0f));
    const float back = 1.0f - t * t * (3.0f - 2.0f * t);
    const float bank = float(a & 0x7Fu) / 127.0f * back;
    // (Far above this ground: a print on a floor above, or the top of a trench's sloped wall, whose floor the renderer's
    // copy raised over the snow's top beside a bank, SnowSlopeWalls in rt64_scene_effects.cpp: only the bank counts.)
    if (((a & 0x80u) != 0u) || (above < -80.0f)) {
        return float3(0.0f, bank, 0.0f);
    }
    // The print's floor rises as it fills back in.
    const float floorY = touchY + (1.0f - back) * SnowRefillRise;
    const float depth = max(FrParams.snowParams.x, 1e-3f);
    const float pressed = saturate((groundY + depth - floorY) / depth);
    // (Down through such a layer to his feet: the tessellated snow's trail reaches them, RASTER_SNOW_TESS.)
    // (Sand lies on the ground itself: nothing to go down through.)
    return float3(pressed, bank, SnowSand() ? 0.0f : pressed * clamp(groundY - floorY, 0.0f, SnowLayerMost));
}

// The trail's press (x), bank (y) and depth below the ground (z, SnowCell) at a world position, blended between the
// four nearest cells.
float3 SnowTrailAt(float2 xz, float groundY) {
    const float2 g = xz * FrParams.snowGrid.y - 0.5f;
    const float2 first = floor(g);
    const float2 f = g - first;
    const int2 c = int2(first);
    const float3 a = lerp(SnowCell(c, groundY), SnowCell(c + int2(1, 0), groundY), f.x);
    const float3 b = lerp(SnowCell(c + int2(0, 1), groundY), SnowCell(c + int2(1, 1), groundY), f.x);
    return lerp(a, b, f.y);
}

// The snow's height over the ground (world units) where it is pressed down by trail.x and banked up by trail.y, its
// untouched height being surface; below the ground (negative) where a game's own snow layer lies over Banjo's feet
// (trail.z). The banks only rise beside the trail, not in it.
float SnowHeight(float surface, float3 trail) {
    const float bank = trail.y * saturate(1.0f - trail.x * 3.0f) * FrParams.snowSpring.z * FrParams.snowParams.x;
    return surface * (1.0f - 0.97f * trail.x) - trail.z + bank;
}

// How much of the snow's depth lies at a world position (1 near, thinning to 0 by reach, so it ends without an edge),
// and its distance from the camera. (The shells reach snowParams.z; the tessellated snow, cheap far away, much further,
// snowLod.y.)
float SnowThin(float3 world, out float cameraDistance, float reach) {
    const float3 camera = FrParams.snowCamera.xyz;
    cameraDistance = distance(world, camera);
    // (As far as the snow's reach goes, a camera zoomed in brings it nearer, SceneSnowZoom, and the snow round Banjo is
    // never far, SceneSnowNearBanjo: Chilly Willy's fight watches him from far back.)
    float reachDistance = cameraDistance * clamp(2.2f / max(FrParams.snowCamera.w, 1e-3f), 0.2f, 1.0f);
    if (FrParams.snowPlayer.w > 0.0f) {
        reachDistance = min(reachDistance, distance(world, float3(FrParams.snowPlayer.x, FrParams.snowPlayer.z, FrParams.snowPlayer.y)) + 600.0f);
    }
    return saturate(1.0f - (reachDistance - reach * 0.55f) / (reach * 0.45f));
}

// What SnowShellShape found out about a shell's pixel, for SnowShellShade.
struct SnowSample {
    float surface;
    float height;
    float shellY;
    float3 trail;
    bool nearTrail;
    float cameraDistance;
    // The trail's slope (d height / dx, dz) where SnowTessShape found it with the trail (sloped), so SnowShellShade
    // needs no more lookups for its light.
    float2 slope;
    bool sloped;
    // How the trail's slopes light it (-1 to 1, SnowTrailLight) where already known (lit): the tessellated snow's pixels
    // get it from its vertices (SnowTessPacked).
    float lit;
    bool litKnown;
};

// The snow's shape at a shell's pixel at height share (0 to 1 of the snow's full height): false when the pixel is
// above the snow, or not on ground facing up, so it can be thrown away before the draw's colours are worked out.
bool SnowShellShape(float3 world, float3 worldDx, float3 worldDy, float share, out SnowSample s) {
    s = (SnowSample)0;
    // Test aid (TOOIE_SNOW_DEBUG=3): the top shell kept everywhere, coloured in SnowShellShade by why the snow would be
    // left out there (s.trail.x: 1 no normal or a wall, 2 out of reach, 3 a steep face, 4 kept).
    const bool why = FrParams.snowGrid.w > 3.5f;

    // Ground facing up: the shell lies parallel to it, so its slopes give the ground's normal.
    const float3 normal = cross(worldDx, worldDy);
    const float normalLength = length(normal);
    if (normalLength <= 0.0f) {
        s.trail.x = 1.0f;
        return why && (share >= 0.999f);
    }
    const bool steep = abs(normal.y) < 0.6f * normalLength;
    // A steep bank of snow (the drop at a snowfield's edge) is raised with it as a solid face, so the snow's side
    // isn't a stack of thin layers with gaps between. Not a wall standing straight up, where the raised copies would
    // lie on the wall itself and fight over it.
    if (steep && (abs(normal.y) < 0.12f * normalLength)) {
        s.trail.x = 1.0f;
        return why && (share >= 0.999f);
    }

    // Thinner far away, gone by the snow's reach, so it ends without an edge.
    const float4 params = FrParams.snowParams;
    const float thin = SnowThin(world, s.cameraDistance, FrParams.snowParams.z);
    if (thin <= 0.02f) {
        s.trail.x = 2.0f;
        return why && (share >= 0.999f);
    }

    // The same depth everywhere: where it varied, each shell's edge showed as a line across the ground, cutting its
    // shading into stripes (the ground's own shape gives the drifts).
    s.surface = params.x * thin;

    s.shellY = share * params.y;
    if (steep) {
        s.height = s.surface;
        s.trail.x = why ? 3.0f : 0.0f;
        return why ? (share >= 0.999f) : (s.shellY <= s.height);
    }
    if (why) {
        s.trail.x = 4.0f;
        return share >= 0.999f;
    }

    // Banjo's trail, near him only.
    const float4 player = FrParams.snowPlayer;
    s.nearTrail = (player.w > 0.0f) && all(abs(world.xz - player.xy) < player.w);
    s.trail = s.nearTrail ? SnowTrailAt(world.xz, world.y - s.shellY) : 0.0f;
    s.height = SnowHeight(s.surface, s.trail);
    return s.shellY <= s.height;
}

// Whether a block of the trail grid holding this world position has a trail in it (FrameParams.snowBlocksLow and High).
bool SnowBlockActive(float2 xz) {
    const int n = int(FrParams.snowGrid.z);
    const int2 cell = int2(floor(xz * FrParams.snowGrid.y));
    const uint2 slot = uint2(((cell % n) + n) % n);
    const uint2 block = min(slot / uint(n / 16), 15u);
    const uint k = block.y * 16u + block.x;
    const uint4 words = (k < 128u) ? FrParams.snowBlocksLow : FrParams.snowBlocksHigh;
    const uint i = (k / 32u) & 3u;
    const uint word = (i == 0u) ? words.x : (i == 1u) ? words.y : (i == 2u) ? words.z : words.w;
    return ((word >> (k % 32u)) & 1u) != 0u;
}

// Whether any of the trail can reach within r world units of this position: near Banjo, in a block with a trail in it.
// Most of the snow has none, and skips the trail's lookups.
bool SnowTrailNear(float2 xz, float r) {
    const float4 player = FrParams.snowPlayer;
    if ((player.w <= 0.0f) || any(abs(xz - player.xy) >= player.w)) {
        return false;
    }
    return SnowBlockActive(xz) || SnowBlockActive(xz + float2(r, r)) || SnowBlockActive(xz + float2(-r, r)) ||
        SnowBlockActive(xz + float2(r, -r)) || SnowBlockActive(xz - float2(r, r));
}

// The snow's height over the trail at a world position smoothed over about blur world units (four blended lookups
// blur * 0.75 apart either way, each itself blended between four cells), with its slope from the same four, so the
// dents' walls are soft slopes in both shape and light, at a quarter of the lookups a wider filter took. The trail
// itself (s.trail) is the four's average.
void SnowTrailSmoothed(float2 xz, float groundY, float blur, float edge, inout SnowSample s) {
    // Nine lookups blur * 0.5 apart, weighted 1 2 1 each way (a tent over the whole blur), the slope from the same nine
    // as a Sobel filter takes it. (Four lookups at the corners, as before, averaged two cliffs of a print's edge into a
    // terrace of two hard steps: the snow's edges looked cut.)
    const float r = blur * 0.5f;
    // (Not below the ground near the snowy ground's edge, edge: there the trench would open a hole beside a cliff.)
    const float3 keep = float3(1.0f, 1.0f, edge);
    float3 trail = 0.0f;
    float height = 0.0f;
    float2 slope = 0.0f;
    [unroll] for (int j = -1; j <= 1; j++) {
        [unroll] for (int i = -1; i <= 1; i++) {
            const float3 t = SnowTrailAt(xz + float2(i, j) * r, groundY) * keep;
            const float h = SnowHeight(s.surface, t);
            const float w = float((2 - abs(i)) * (2 - abs(j)));
            trail += t * w;
            height += h * w;
            slope += float2(float(i) * float(2 - abs(j)), float(j) * float(2 - abs(i))) * h;
        }
    }
    s.trail = trail / 16.0f;
    s.height = height / 16.0f;
    s.slope = slope / (8.0f * r);
    s.sloped = true;
}

// How far apart the tessellated snow's new vertices over the trail are (SnowTess.hlsl) at a distance from the camera (world units).
// Two cells up to the Snow LOD distance, then coarser and coarser (smoother, and cheaper) the further away.
float SnowTrailSegment(float cameraDistance) {
    const float start = max(FrParams.snowLod.x, 1.0f);
    // (No finer than 4 units: the trail is smoothed over 6, SnowTrailBlur, so finer points cost without showing more.
    // Sand, shallow, keeps its footprints' detail: one cell. Further off, coarser with the distance as a point covers
    // fewer pixels, about as many pixels apart everywhere: finely cut prints all over the level, held until the map
    // changes, cost the most of a frame.)
    const float finest = SnowSand() ? FrParams.snowGrid.x : max(FrParams.snowGrid.x * 2.0f, 4.0f);
    const float closest = max(finest, cameraDistance * 0.008f);
    return closest * (1.0f + max(cameraDistance - start, 0.0f) / (start * 0.25f));
}

// How far the tessellated snow's trail is smoothed over at a distance from the camera (world units): by the domain
// shader where to raise the surface to, and the pixel shader alike, so the shading matches the shape. Never less than
// a few cells, so the dents' walls slope as soft snow does instead of standing as steps and spikes between the cells.
float SnowTrailBlur(float cameraDistance) {
    return SnowSand() ? max(SnowTrailSegment(cameraDistance) * 0.5f, 1.25f) : max(SnowTrailSegment(cameraDistance) * 0.75f, 6.0f);
}

// SnowTrailSegment and SnowTrailBlur at a world position: closer together round Banjo (half as far apart within 150
// units of him, easing back by 400), so his footprints, about 10 units long, show one by one where they are fresh
// and looked at instead of running together into a furrow, while the trail further off stays as cheap as before. (By
// the position only, so the patches either side of an edge, and the domain shader's points, agree.)
float SnowTrailNearBanjo(float3 world) {
    const float4 player = FrParams.snowPlayer;
    if (player.w <= 0.0f) {
        return 1.0f;
    }
    return lerp(0.5f, 1.0f, saturate((distance(world.xz, player.xy) - 150.0f) / 250.0f));
}

float SnowTrailSegmentAt(float3 world, float cameraDistance) {
    return SnowTrailSegment(cameraDistance) * SnowTrailNearBanjo(world);
}

float SnowTrailBlurAt(float3 world, float cameraDistance) {
    const float near = SnowTrailNearBanjo(world);
    // (Snow smoothed as far round Banjo as elsewhere, at least 6 units, so its soft edges stay soft: only sand's prints,
    // shallow and crisp, are smoothed less there. Banjo's prints still show one by one, by their light, SnowShellShade.)
    return SnowSand() ? max(SnowTrailSegment(cameraDistance) * near * 0.5f, 1.25f) : max(SnowTrailSegment(cameraDistance) * 0.75f, 6.0f);
}

// The tessellated snow (RASTER_SNOW_TESS, SnowTess.hlsl): its height over a point of the ground (ground, with how much
// of the snow's height lies there by its distance from the snowy ground's edge, and the ground's normal, any length) in s.height, s.shellY the same (the pixel is on the snow's surface). False where
// no snow lies on it: a wall, or past the snow's reach; s.height is then still how far that ground is raised with the
// snow round it (its untouched height there, thinning out by the reach), so the raised ground has no cracks where a
// wall or the snow's end meets it. Both the
// domain shader (where to raise the surface to) and the pixel shader (how to shade it) ask, both with the trail smoothed
// over blur world units (SnowTrailBlur).
bool SnowTessShape(float3 ground, float edge, float3 normal, float blur, out SnowSample s) {
    s = (SnowSample)0;
    const bool why = FrParams.snowGrid.w > 3.5f;
    const float4 params = FrParams.snowParams;
    const float normalLength = length(normal);
    const float thin = SnowThin(ground, s.cameraDistance, FrParams.snowLod.y);
    // (None on the snowy ground's very edge, rising inward: edge, snowGroundVertices.)
    s.surface = params.x * thin * saturate(edge);
    // The untouched snow's own shape (SnowSurfaceShape) near the camera. By the point's place only, also on a wall or
    // a steep bank, so a point two patches share is raised the same for both and no crack opens between them; never
    // below a quarter of the even depth, so the snow doesn't open down to the ground. (Not sand's: shallow, its shape
    // is only lit, as a normal map would, SnowShellShade.)
    const float surfaceFade = SnowSurfaceFade(s.cameraDistance);
    if (!why && !SnowSand() && (surfaceFade > 0.0f) && (s.surface > 0.0f)) {
        const float shape = SnowSurfaceShape(ground.xz, params.x, SnowSurfaceSegment(s.cameraDistance)).x;
        s.surface = max(s.surface + shape * thin * saturate(edge) * surfaceFade, s.surface * 0.25f);
    }
    if ((normalLength <= 0.0f) || (abs(normal.y) < 0.12f * normalLength)) {
        s.trail.x = 1.0f;
        s.height = s.shellY = why ? params.x : s.surface;
        return why;
    }
    if (thin <= 0.02f) {
        s.trail.x = 2.0f;
        s.height = s.shellY = why ? params.x : s.surface;
        return why;
    }
    const bool steep = abs(normal.y) < 0.6f * normalLength;
    if (why) {
        s.trail.x = steep ? 3.0f : 4.0f;
        s.height = s.shellY = params.x;
        return true;
    }

    // Banjo's trail, near him only, on ground facing up (a steep bank keeps its snow as it is).
    const float4 player = FrParams.snowPlayer;
    s.nearTrail = !steep && SnowTrailNear(ground.xz, blur + FrParams.snowGrid.x * 2.0f);
    s.height = s.surface;
    if (s.nearTrail) {
        SnowTrailSmoothed(ground.xz, ground.y, blur, saturate(edge), s);
    }
    s.shellY = s.height;
    return true;
}

// How the trail's slope (d height / dx, dz) lights it: -1 (in shade) to 1 (toward the light).
float SnowTrailLight(float2 slope) {
    const float3 n = normalize(float3(-slope.x, 1.0f, -slope.y));
    const float3 light = FrParams.snowLight.xyz;
    return clamp(FrParams.snowLight.w * (dot(n, light) - light.y), -1.0f, 1.0f);
}

// The tessellated snow's pixels don't look the trail up again (16 lookups a pixel, at a high resolution most of the
// snow's cost): its domain shader packs what shading needs into each vertex's anchor, blended over the pixels between
// (its vertices are no further apart than the trail is smoothed over, SnowTrailBlur). For the snow: (x, light, z, how
// far under the untouched surface 0 to 1, or -1 where no snow lies). For the ground pass: w the snow's height.
// (Not with a test aid on, TOOIE_SNOW_DEBUG: those look it up as before.)
bool SnowTessPacked() {
    return FrParams.snowGrid.w <= 1.5f;
}

float4 SnowTessPack(float3 ground, bool shaped, SnowSample s, bool groundPass) {
    if (groundPass) {
        // (Where no snow lies, far above, so RasterPS keeps the ground there: it leaves the ground pass out where the snow
        // lies within 2 units of it.)
        return float4(ground, shaped ? s.height : 1.0e4f);
    }
    const float lit = s.sloped ? SnowTrailLight(s.slope) : 0.0f;
    const float under = saturate((s.surface - s.shellY) / max(s.surface, 1.0f));
    return float4(ground.x, lit, ground.z, shaped ? under : -1.0f);
}

// A tessellated snow pixel's sample from its packed anchor (SnowTessPack); false where no snow lies. distance: the
// pixel's distance from the camera (across the ground: enough for the glints, SnowShellShade).
bool SnowTessUnpack(float4 anchor, float distance, out SnowSample s) {
    s = (SnowSample)0;
    s.cameraDistance = distance;
    if (anchor.w < -0.5f) {
        return false;
    }
    // (Only how far under the surface matters to the shading: the surface counts as 1, the pixel that far below it.)
    const float under = saturate(anchor.w);
    s.surface = 1.0f;
    s.shellY = s.height = 1.0f - under;
    s.trail.x = under;
    s.lit = anchor.y;
    s.litKnown = true;
    return true;
}

// Shades a shell's pixel inside the snow; false when the ground under it isn't snowy (baseColor, the draw's colour).
// anyColor: whatever the ground's colour (the tessellated snow, which stands in for the ground's draw: its snow in
// shade, under the ice's cliffs, is too dark for SnowColor).
bool SnowShellShade(float3 world, float3 baseColor, float share, SnowSample s, bool anyColor, inout float3 color) {
    if (FrParams.snowGrid.w > 3.5f) {
        const int reason = int(s.trail.x + 0.5f);
        color = !SnowColor(baseColor) ? float3(1.0f, 0.0f, 1.0f) : (reason == 1) ? float3(1.0f, 0.0f, 0.0f) : (reason == 2) ? float3(0.0f, 1.0f, 0.0f) :
            (reason == 3) ? float3(0.0f, 1.0f, 1.0f) : float3(1.0f, 1.0f, 1.0f);
        return true;
    }
    if (!anyColor && !SnowColor(baseColor)) {
        return false;
    }

    // The trail's slopes light up toward the light and fall into soft blue shade away from it.
    float lit = 0.0f;
    if (s.litKnown) {
        lit = s.lit;
    }
    else if (s.sloped) {
        lit = SnowTrailLight(s.slope);
    }
    else if (s.nearTrail && ((s.trail.x > 0.003f) || (s.trail.y > 0.003f))) {
        const float e = 1.25f;
        const float groundY = world.y - s.shellY;
        const float hx0 = SnowHeight(s.surface, SnowTrailAt(world.xz - float2(e, 0.0f), groundY));
        const float hx1 = SnowHeight(s.surface, SnowTrailAt(world.xz + float2(e, 0.0f), groundY));
        const float hz0 = SnowHeight(s.surface, SnowTrailAt(world.xz - float2(0.0f, e), groundY));
        const float hz1 = SnowHeight(s.surface, SnowTrailAt(world.xz + float2(0.0f, e), groundY));
        const float3 n = normalize(float3(-(hx1 - hx0) / (2.0f * e), 1.0f, -(hz1 - hz0) / (2.0f * e)));
        const float3 light = FrParams.snowLight.xyz;
        lit = clamp(FrParams.snowLight.w * (dot(n, light) - light.y), -1.0f, 1.0f);
    }

    // Deeper under the snow's untouched surface (the floor and walls of the trail) it is packed down and in shade:
    // greyer and bluer. The top is a little brighter than the ground below it.
    const float under = saturate((s.surface - s.shellY) / max(s.surface, 1.0f));

    // The untouched surface's own shape (SnowSurfaceShape) lights it as its trail does, finer than the tessellated
    // surface's points follow too (as a normal map would), down to a few pixels; flattened where a foot pressed it.
    // (The trail's slope is packed in its light only, so the grains below lie on this slope, not the trail's.)
    const float surfaceFade = SnowSurfaceFade(s.cameraDistance) * (1.0f - under);
    const float2 surfaceSlope = (surfaceFade > 0.0f) ?
        SnowSurfaceShape(world.xz, FrParams.snowParams.x, SnowPixelSize(s.cameraDistance) * 4.0f).yz * surfaceFade : 0.0f;
    lit = clamp(lit + SnowTrailLight(surfaceSlope), -1.0f, 1.0f);

    // The eye's direction, for the grains' sparkle and sand's sheen. (The tessellated snow's pixels know only the
    // ground's x and z, SnowTessUnpack: its height is taken as Banjo's, near enough for the light off grains.)
    const float3 camera = FrParams.snowCamera.xyz;
    const float groundY = s.litKnown ? ((FrParams.snowPlayer.w > 0.0f) ? FrParams.snowPlayer.z : camera.y - 150.0f) : world.y;
    const float3 view = normalize(camera - float3(world.x, groundY, world.z));
    const float brightness = saturate(dot(color, float3(0.3f, 0.59f, 0.11f)) * 1.4f);
    // (Only on the side facing the light.)
    const float sunny = saturate(lit * 2.0f + 1.0f);

    if (SnowSand()) {
        // Sand: rippled by the wind where no foot has flattened it, and its shaded slopes warm, not blue. A footprint
        // reads plainly: its floor darker the deeper it goes and browner (the sand under the dry top, packed down and a
        // little damp), its wall toward the light brighter and the one away in deep warm shade.
        // (Sand's prints are shallow, so the trail's own slopes light them half again as strongly as snow's.)
        const float2 sandSlope = surfaceSlope + SandRippleSlope(world.xz, s.cameraDistance) * (1.0f - under);
        lit = clamp(lit * 1.5f + SnowTrailLight(sandSlope - surfaceSlope), -1.0f, 1.0f);
        float3 sand = color * lerp(1.04f, 0.6f, under) * (1.0f + 0.4f * max(lit, 0.0f));
        sand = lerp(sand, sand * float3(0.68f, 0.6f, 0.52f), saturate(-lit * 1.3f) * 0.9f);
        sand = lerp(sand, sand * float3(0.88f, 0.79f, 0.68f), saturate(under * 2.0f));
        // Journey's sand (Edwards, GDC 2013): a broad sheen off the swells' and big ripples' slopes toward the sun,
        // strongest seen low across the sand ("ocean specular"), and glitter off single grains. Not on packed-down
        // sand. (Off the broad shape only: the small ripples, about as fine as the pixels, drew bands of moire in it.)
        const float3 normal = normalize(float3(-surfaceSlope.x, 1.0f, -surfaceSlope.y));
        const float3 h = normalize(FrParams.snowLight.xyz + view);
        const float grazing = 1.0f - saturate(dot(normal, view));
        const float sheen = pow(saturate(dot(normal, h)), 16.0f) * (0.25f + 0.75f * grazing * grazing);
        const float glitter = SnowSparkle(world.xz, normal, view, s.cameraDistance, 0.45f, 0.12f, 0.45f, 600.0f);
        sand += (float3(1.0f, 0.95f, 0.86f) * (0.08f * sheen) + 0.7f * glitter) * (brightness * sunny * (1.0f - under));
        color = sand;
        return true;
    }
    // A footprint reads plainly on snow near white: its floor darker and bluer the deeper it goes (packed snow in a
    // hollow, the sky's blue light all that reaches it), the wall turned from the light in clear blue shade.
    // (Eased in over the wall, not started hard at the rim, so a trench's edge reads as a soft fold in the snow.)
    float3 shade = color * lerp(1.06f, 0.76f, smoothstep(0.0f, 1.0f, under)) * (1.0f + 0.3f * max(lit, 0.0f));
    shade = lerp(shade, shade * float3(0.55f, 0.62f, 0.84f), saturate(-lit * 1.25f));
    shade = lerp(shade, shade * float3(0.74f, 0.8f, 0.95f), smoothstep(0.05f, 0.8f, under));

    // Glints in the sun off grains of snow lying on its untouched top (SnowSparkle), each fading in and out as the
    // camera moves.
    if (s.height - s.shellY < FrParams.snowParams.y * 0.12f) {
        const float3 normal = normalize(float3(-surfaceSlope.x, 1.0f, -surfaceSlope.y));
        shade += 1.1f * SnowSparkle(world.xz, normal, view, s.cameraDistance, 0.6f, 0.1f, 0.4f, 500.0f) * brightness * sunny * (1.0f - under);
    }

    // Test aids (TOOIE_SNOW_DEBUG): 1 colours the shells from blue at the ground to magenta at the snow's full
    // height; 2 shows the trail near Banjo (yellow untouched, brighter where pressed, red where banked).
    if (FrParams.snowGrid.w > 2.5f) {
        shade = s.nearTrail ? float3(saturate(0.6f + s.trail.y * 4.0f), saturate(0.6f + s.trail.x * 4.0f) * (1.0f - s.trail.y), 0.0f) : float3(0.1f, 0.2f, 1.0f);
    }
    else if (FrParams.snowGrid.w > 1.5f) {
        shade = lerp(float3(0.1f, 0.2f, 1.0f), float3(1.0f, 0.1f, 0.9f), share);
    }

    color = shade;
    return true;
}

#endif // RT64_EXT_SHADERS_SNOW_HLSLI
