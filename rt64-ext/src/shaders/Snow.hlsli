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
#include "Grass.hlsli"

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
    const float a = GrassHash(i).x;
    const float b = GrassHash(i + float2(1.0f, 0.0f)).x;
    const float c = GrassHash(i + float2(0.0f, 1.0f)).x;
    const float d = GrassHash(i + float2(1.0f, 1.0f)).x;
    return lerp(lerp(a, b, u.x), lerp(c, d, u.x), u.y);
}

// One set of wind ripples' slope: ridges across wind, spacing wavelength (varying from place to place), bent along
// their length by warp.
float2 SandRippleSet(float2 xz, float2 wind, float wavelength, float warp) {
    const float theta = (dot(xz, wind) + warp) / wavelength * 6.2831853f;
    // (A ridge gentle up the windward side, steeper down the lee: sin + a quarter of its second harmonic.)
    const float rise = cos(theta) + 0.5f * cos(2.0f * theta);
    return wind * (rise * 6.2831853f / wavelength);
}

// The slope (d height / dx, dz) of the ripples the wind leaves in sand at a world position: two sets of low ridges
// from winds a little apart, their spacing (7 to 13 units) and strength changing from place to place, bent and with
// their crests broken off here and there, so no stretch repeats; fading out by distance before they are finer than the
// pixels.
float2 SandRippleSlope(float2 xz, float cameraDistance) {
    const float fade = saturate(1.0f - cameraDistance / 900.0f);
    if (fade <= 0.0f) {
        return 0.0f;
    }
    const float warp = 14.0f * SnowNoise(xz / 60.0f) + 5.0f * SnowNoise(xz / 19.0f + 5.0f) + 1.5f * SnowNoise(xz / 6.0f + 9.0f);
    const float wavelengthA = lerp(7.0f, 13.0f, SnowNoise(xz / 90.0f + 3.0f));
    const float wavelengthB = lerp(6.0f, 11.0f, SnowNoise(xz / 75.0f + 17.0f));
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
    if ((above < -80.0f) || (above > 200.0f)) {
        return 0.0f;
    }
    const float4 spring = FrParams.snowSpring;
    const float age = float((uint(spring.w) - (b & 0xFFFFu)) & 0xFFFFu) / 20.0f;
    const float t = saturate((age - spring.x) / max(spring.y, 1.0f));
    const float back = 1.0f - t * t * (3.0f - 2.0f * t);
    const float bank = float(a & 0x7Fu) / 127.0f * back;
    if ((a & 0x80u) != 0u) {
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
    const float r = blur * 0.75f;
    // (Not below the ground near the snowy ground's edge, edge: there the trench would open a hole beside a cliff.)
    const float3 keep = float3(1.0f, 1.0f, edge);
    const float3 t00 = SnowTrailAt(xz + float2(-r, -r), groundY) * keep;
    const float3 t10 = SnowTrailAt(xz + float2(r, -r), groundY) * keep;
    const float3 t01 = SnowTrailAt(xz + float2(-r, r), groundY) * keep;
    const float3 t11 = SnowTrailAt(xz + float2(r, r), groundY) * keep;
    const float h00 = SnowHeight(s.surface, t00);
    const float h10 = SnowHeight(s.surface, t10);
    const float h01 = SnowHeight(s.surface, t01);
    const float h11 = SnowHeight(s.surface, t11);
    s.trail = (t00 + t10 + t01 + t11) * 0.25f;
    s.height = (h00 + h10 + h01 + h11) * 0.25f;
    s.slope = float2((h10 + h11) - (h00 + h01), (h01 + h11) - (h00 + h10)) / (4.0f * r);
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
        return float4(ground, shaped ? s.height : 0.0f);
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
    if (SnowSand()) {
        // Sand: rippled by the wind where no foot has flattened it, a footprint a little darker (packed down), and its
        // shaded slopes warm, not blue. No glints.
        lit = clamp(lit + SnowTrailLight(SandRippleSlope(world.xz, s.cameraDistance) * (1.0f - under)), -1.0f, 1.0f);
        float3 sand = color * lerp(1.03f, 0.76f, under) * (1.0f + 0.25f * max(lit, 0.0f));
        sand = lerp(sand, sand * float3(0.8f, 0.75f, 0.68f), saturate(-lit) * 0.85f);
        color = sand;
        return true;
    }
    float3 shade = color * lerp(1.06f, 0.84f, under) * (1.0f + 0.3f * max(lit, 0.0f));
    shade = lerp(shade, shade * float3(0.62f, 0.68f, 0.86f), saturate(-lit));
    shade = lerp(shade, shade * float3(0.8f, 0.84f, 0.94f), saturate(under * s.trail.x * 1.5f));

    // A few glints in the sun close by, each catching the light from some places and not others.
    if (s.cameraDistance < 700.0f) {
        const float3 camera = FrParams.snowCamera.xyz;
        const float3 glint = GrassHash(floor(world.xz * 1.6f) + floor(camera.xz * 0.04f) * 17.0f);
        if ((glint.x > 0.992f) && (s.height - s.shellY < FrParams.snowParams.y * 0.12f)) {
            shade += 0.35f * (1.0f - s.cameraDistance / 700.0f) * glint.y;
        }
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
