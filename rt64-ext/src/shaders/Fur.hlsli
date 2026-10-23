//
// RT64
//

// Banjo-Tooie: Banjo's fur, the shell technique of Sorumi's UnityFurShader (Apache 2.0). Banjo's model draws are
// drawn again as shells, each pushed further out along the vertex normals by its share of the fur's length
// (RasterVS.hlsl). Each shell keeps a pixel where a fine noise is above a threshold that rises with the shell's
// height (Sorumi: alpha = noise - height^2 * density), so the noise's peaks become thin strands that thin out
// towards their tips, and shades it darker towards the roots ((1 - height)^3, as there). Vanilla Banjo has no fur
// texture, so the noise is a 3D value noise over the model's own vertex positions (before the bones move them),
// and stays put on him as he moves. Only Banjo's brown fur grows strands (and only on his own bones, see
// model_tagging.cpp): not the yellow shorts, the blue backpack or the pale gloves and boots.

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_SHADERS_FUR_HLSLI
#define RT64_EXT_SHADERS_FUR_HLSLI

uint FurHash(int3 cell) {
    uint3 c = uint3(cell + 0x8000);
    uint h = c.x * 0x8DA6B343u ^ c.y * 0xD8163841u ^ c.z * 0xCB1AB31Fu;
    h ^= h >> 13;
    h *= 0x5BD1E995u;
    h ^= h >> 15;
    return h;
}

float FurValue(int3 cell) {
    return float(FurHash(cell) & 0xFFFFu) / 65535.0f;
}

// Smooth value noise, 0 to 1, a lattice point every unit of p.
float FurNoise(float3 p) {
    const int3 i = int3(floor(p));
    const float3 f = frac(p);
    const float3 u = f * f * (3.0f - 2.0f * f);
    const float x00 = lerp(FurValue(i + int3(0, 0, 0)), FurValue(i + int3(1, 0, 0)), u.x);
    const float x10 = lerp(FurValue(i + int3(0, 1, 0)), FurValue(i + int3(1, 1, 0)), u.x);
    const float x01 = lerp(FurValue(i + int3(0, 0, 1)), FurValue(i + int3(1, 0, 1)), u.x);
    const float x11 = lerp(FurValue(i + int3(0, 1, 1)), FurValue(i + int3(1, 1, 1)), u.x);
    return lerp(lerp(x00, x10, u.y), lerp(x01, x11, u.y), u.z);
}

// Banjo's fur colours: strong orange browns, from dark to light (not the shorts' yellow, the backpack's blue or
// the pale gloves and boots).
bool FurColor(float3 color) {
    const float high = max(color.r, max(color.g, color.b));
    const float low = min(color.r, min(color.g, color.b));
    if ((high < 0.06f) || (color.r < high) || (color.b > color.g)) {
        return false;
    }
    const float chroma = high - low;
    const float saturation = chroma / high;
    if ((saturation < 0.5f) || (chroma <= 0.0f)) {
        return false;
    }
    // Hue in degrees, red being the largest: 60 * (g - b) / chroma. His brightest lit fur reaches 37 (it was left bald
    // there, L); the shorts' shading starts above 38.
    const float hue = 60.0f * (color.g - color.b) / chroma;
    return (hue >= 14.0f) && (hue <= 38.0f);
}

// A furry NPC's white fur (the yeti), from its texture: white to mid grey, not its blue-grey face and hands
// (saturation 0.14 and up where lit, L: no fur there) or its dark eyes and mouth.
bool WhiteFurColor(float3 color) {
    const float high = max(color.r, max(color.g, color.b));
    const float low = min(color.r, min(color.g, color.b));
    return (high >= 0.3f) && ((high - low) <= 0.09f * high);
}

// Whether a shell's pixel at height share (0 to 1) is part of a strand; if so, shades it from root to tip.
// anchor is the place on the model (its own units), baseColor the surface's own colour there; white picks a furry
// enemy's white fur instead of Banjo's brown. mark is the vertex's fur mark (FurMarkW in rt64_framebuffer_renderer.cpp),
// blended across the triangle: 3 fur, 1 or 4 bare (his model tells them by their own colours, so the light on them
// doesn't change the coat, L); 0 (unmarked) tells it by the colour as lit here. Between fur and bare only the last
// quarter next to the fur grows it: his shorts' edge blends into his legs' brown, and stays clean (L).
bool FurShell(float3 anchor, float3 baseColor, float share, bool white, float mark, inout float3 color) {
    if (((mark >= 0.5f) && (mark < 2.5f)) || (mark >= 3.5f)) {
        return false;
    }
    else if (mark >= 2.5f) {
        // (Fur, told by his model.)
    }
    else if (white ? !WhiteFurColor(baseColor) : !FurColor(baseColor)) {
        return false;
    }

    // params.y: strands per unit (the density); params.z: how fast the strands thin out with height; params.w: the
    // noisiness, how uneven the coat is: tufts that stand taller or lower (a coarser noise moving the threshold)
    // and strands lighter or darker than their neighbours.
    const float4 params = white ? FrParams.npcFurParams : FrParams.furParams;
    // (Banjo's fur wet: the strands clump into coarser locks and the coat sits lower, FrParams.charSurface.x.)
    const float wet = white ? 0.0f : FrParams.charSurface.x;
    const float3 grid = anchor * params.y * (1.0f - 0.35f * wet);
    const float noise = FurNoise(grid);
    const float tufts = FurNoise(grid * 0.23f + 17.0f) - 0.5f;
    if (noise - share * share * (params.z + 0.45f * wet) + tufts * 0.35f * params.w < 0.55f) {
        return false;
    }

    // The strands shade each other near the roots (Sorumi's FurShading); the tips catch a little more light.
    const float rootShade = 1.0f - share;
    const float strand = FurValue(int3(floor(grid))) - 0.5f;
    color *= (1.0f - 0.55f * rootShade * rootShade * rootShade) * (1.0f + 0.12f * share) * (1.0f + 0.7f * params.w * strand);
    return true;
}

// Banjo-Tooie: one of Kazooie's feathers (GrassGS.hlsl): anchor is its place across (-1 to 1) and along it (0 root,
// 1 tip), then its own shade. Only on her feathers (reds and oranges), not her beak or legs. Cut to a feather's
// shape, narrow at the root and round at the tip, darker towards the root where the one above lies over it, with a
// faint shaft down its middle. known: her model marks it a feather by its own colour (SetFurVertexFlags), so its
// colour as lit here (dark underneath, say) is not tested.
bool FeatherCard(float3 anchor, float3 baseColor, bool npc, bool wing, bool known, inout float3 color) {
    const float high = max(baseColor.r, max(baseColor.g, baseColor.b));
    const float low = min(baseColor.r, min(baseColor.g, baseColor.b));
    if (!known && ((high < 0.22f) || (baseColor.r < high) || (((high - low) / high) < 0.5f))) {
        return false;
    }
    // Red to orange; up to a deep orange only where it is fully saturated (the top of her head, no blue at all), as
    // her beak's orange base keeps a little blue (saturation 0.91-0.95; its feathers showed as flecks, L).
    // A feathered NPC (Canary Mary) has them on her strong orange-yellow (hue 37-47, saturation 0.85 and up), not on
    // her tan skin (saturation about 0.6) or her paler lemon beak (hue 54).
    const float hue = 60.0f * (baseColor.g - baseColor.b) / max(high - low, 1e-4f);
    const float saturation = (high - low) / max(high, 1e-4f);
    if (known) {
        // (Told by her model.)
    }
    else if (npc) {
        if ((hue < 30.0f) || (hue > 50.0f) || (saturation < 0.78f)) {
            return false;
        }
    }
    // Her wings and crest have them on their yellow too (L).
    else if ((hue < -20.0f) || (hue > (wing ? 62.0f : ((saturation >= 0.98f) ? 30.0f : 18.0f)))) {
        return false;
    }

    const float t = saturate(anchor.y);
    const float across = abs(anchor.x);
    const float halfWidth = sqrt(saturate(t * 4.0f)) * sqrt(saturate((1.0f - t) * 2.2f));
    if (across > halfWidth) {
        return false;
    }
    const float edge = smoothstep(halfWidth * 0.6f, halfWidth, across);
    const float shaft = 1.0f - smoothstep(0.0f, 0.08f, across);
    color *= anchor.z * lerp(0.62f, 1.05f, smoothstep(0.0f, 0.75f, t)) * (1.0f - 0.18f * edge) * (1.0f - 0.08f * shaft);
    return true;
}

#endif // RT64_EXT_SHADERS_FUR_HLSLI
