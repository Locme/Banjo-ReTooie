//
// RT64
//

// Banjo-Tooie: how deep a parallax texture's surface lies (0 the top, 1 the deepest) for how dark it is there within its
// own range (0 its lightest, 1 its darkest), in the texture's shape (RASTER_PARALLAX_SHAPE_*, picked per texture in
// pick mode). Shared by the pixel shaders (Parallax.hlsli, when a texture has no height map yet) and the height map
// bake (HeightBakeCS.hlsl), so both give a texture the same surface.

#pragma once
#ifndef RT64_EXT_SHADERS_PARALLAX_SHAPE_HLSLI
#define RT64_EXT_SHADERS_PARALLAX_SHAPE_HLSLI

float ParallaxShapeDepth(float darkness, uint shape) {
    switch (shape) {
    // Bumpy: the whole surface follows its brightness (rough rock, bark).
    case 1u:
        return darkness;
    // Inverted: the light parts lie deep (carvings whose grooves are lighter).
    case 2u:
        return smoothstep(0.65f, 0.95f, 1.0f - darkness);
    // Cracks: only the darkest lines sink (cracked floors, mortar); the faces stay put.
    case 3u:
        return smoothstep(0.85f, 0.98f, darkness);
    // Terraced: a few flat steps (bricks, tiles, stacked slabs).
    case 4u: {
        const float s = darkness * 3.0f;
        const float f = min(floor(s), 2.0f);
        return (f + smoothstep(0.4f, 0.6f, s - f)) / 3.0f;
    }
    // Rounded: the faces bulge like pebbles or cobbles, steep only near the gaps.
    case 5u:
        return 1.0f - sqrt(saturate(1.0f - darkness));
    // Grass: the light blade tips stand up and the dark ground between them lies deep, steeply.
    case 6u:
        return pow(smoothstep(0.15f, 0.85f, darkness), 0.8f);
    // Wood: a shallow grain, with the dark gaps between planks sunk deep.
    case 7u:
        return 0.35f * darkness + 0.65f * smoothstep(0.8f, 0.97f, darkness);
    // Bark: deep furrows with steep sides between the ridges.
    case 8u:
        return sqrt(smoothstep(0.2f, 0.9f, darkness));
    // Brick: flat bricks with bevelled edges and a wide band of mortar sunk between them.
    case 9u:
        return smoothstep(0.5f, 0.7f, darkness);
    // Dirt: soft, shallow lumps (paths, sand, mud).
    case 10u:
        return 0.5f * smoothstep(0.0f, 1.0f, darkness);
    // Metal: flat plates; only the darkest seams sink.
    case 11u:
        return smoothstep(0.92f, 1.0f, darkness);
    // Leaves: overlapping leaves, rounded with the shade under each sunk.
    case 12u:
        return 1.0f - (1.0f - darkness) * (1.0f - darkness);
    // Tiles: flat tiles and a narrow, sharp line of grout.
    case 13u:
        return smoothstep(0.75f, 0.85f, darkness);
    // Sand: low, soft ripples from the blurred brightness.
    case 14u:
        return 0.4f * smoothstep(0.1f, 0.9f, darkness);
    // Smooth: Bumpy's full depth from the blurred brightness, with no stair steps.
    case 15u:
        return smoothstep(0.0f, 1.0f, darkness);
    // Ice: a clear top layer with the pattern seen inside it: nothing stands at the surface, the frost and bubbles
    // (the light parts) lie just under it and the dark parts deep down, softly (from the blurred brightness).
    case 16u:
        return 0.3f + 0.7f * smoothstep(0.0f, 1.0f, darkness);
    // Stone: the speckle on a stone's face isn't its shape, so most of it is one flat top and only the darkest parts
    // (the gaps, cracks and the shade under a ledge) sink, steeply at their edges.
    default:
        return smoothstep(0.65f, 0.95f, darkness);
    }
}

#endif // RT64_EXT_SHADERS_PARALLAX_SHAPE_HLSLI
