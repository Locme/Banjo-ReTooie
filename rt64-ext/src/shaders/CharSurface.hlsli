// Banjo-Tooie: the character surface layer: Banjo and Kazooie get wet, snowy, dirty and sandy (WIP > Character surface).
// Pixel shading only, over the model's own colour, over the fur shells and over Kazooie's feather cards, so it needs no
// motion vectors and no extra geometry.

#ifndef CHAR_SURFACE_HLSLI
#define CHAR_SURFACE_HLSLI

// How high above Banjo's feet a vertex is at most (world units): the fraction of its fur mark runs 0 to 0.45 over it
// (rt64_framebuffer_renderer.cpp, CharHeightRange).
#define CHAR_HEIGHT_RANGE 180.0f

// 1 where the layer shows, 0 on his and her eyes and in his mouth: their dark pupils, pale whites, Kazooie's green eyes
// and his mouth's dark reds, read from the model's own texture colour (the lit colour has the light in it), and only
// above his knees, so his reddish feet keep theirs.
float CharSurfaceKeep(float3 texColor, float height, bool featherCard) {
    if (height < 40.0f) {
        return 1.0f;
    }
    const float high = max(texColor.r, max(texColor.g, texColor.b));
    const float low = min(texColor.r, min(texColor.g, texColor.b));
    const float saturation = (high - low) / max(high, 1e-4f);
    float keep = smoothstep(0.10f, 0.22f, high);
    // The whites of the eyes: pale and grey.
    keep *= 1.0f - (1.0f - smoothstep(0.12f, 0.22f, saturation)) * smoothstep(0.45f, 0.6f, high);
    // Kazooie's green eyes.
    keep *= 1.0f - smoothstep(0.02f, 0.08f, texColor.g - max(texColor.r, texColor.b)) * smoothstep(0.15f, 0.3f, saturation);
    // The inside of his mouth: red to pink (hue under 12 degrees, where his brown fur is 19 and up), not too bright.
    // (Kazooie's mouth has the same reds.)
    // (Only deep reds, and only up at the head: his chest and muzzle are pale pink, close to the mouth's hue.)
    if (!featherCard && (texColor.r >= texColor.g) && (texColor.r >= texColor.b) && (saturation > 0.45f) && (high < 0.8f)) {
        const float hue = (texColor.g - texColor.b) / max(texColor.r - min(texColor.g, texColor.b), 1e-4f);
        keep *= lerp(1.0f, smoothstep(0.15f, 0.3f, hue), smoothstep(75.0f, 95.0f, height));
    }
    return keep;
}

// Spots that sit on the parts near the ground and climb his body as the coat grows: coverage 0 to 1. amount is how much
// there is (0 to 1), reach how high up the coat gets at most.
float CharSurfaceSpots(float3 grid, float height, float amount, float reach, float seed) {
    const float low = saturate((reach - height) / reach);
    const float n = 0.55f * FurNoise(grid * 0.45f + seed) + 0.45f * FurNoise(grid * 1.4f + seed * 2.1f);
    const float threshold = 0.82f - 0.5f * amount;
    // (Near the ground it is thick, higher up it thins out, but the more there is the more of his upper body it reaches.)
    const float near = smoothstep(0.0f, 0.2f, low);
    return smoothstep(threshold, threshold + 0.09f, n + 0.4f * low) * lerp(amount * 0.8f, 1.0f, near);
}

// anchor: the vertex's place in the model (xyz; moves with the body, so the spots stick to it) and its fur mark with how
// high it is above his feet in the fraction. share: 0 on the model itself, 0 to 1 up a fur shell or a feather. texColor:
// the draw's texture colour.
float3 CharSurface(float3 color, float3 texColor, float4 anchor, float share, bool featherCard) {
    const float wet = FrParams.charSurface.x;
    const float snow = FrParams.charSurface.y;
    const float dirt = FrParams.charSurface.z;
    const float sand = FrParams.charSurface.w;
    const float height = saturate((anchor.w - floor(anchor.w + 0.05f)) / 0.45f) * CHAR_HEIGHT_RANGE;
    const float keep = CharSurfaceKeep(texColor, height, featherCard);
    if (keep <= 0.0f) {
        return color;
    }
    const float3 grid = anchor.xyz * 0.35f;
    const float tips = 0.6f + 0.4f * share;

    // Dirt: brown mud in spots on his lower body.
    if (dirt > 0.0f) {
        const float cover = CharSurfaceSpots(grid, height, dirt, 20.0f + 90.0f * dirt, 3.0f);
        const float3 mud = float3(0.30f, 0.21f, 0.12f) * (0.6f + 0.4f * FurNoise(grid * 2.3f));
        color = lerp(color, mud, saturate(cover * tips * keep * 0.85f));
    }

    // Sand: pale, grainy tan spots.
    if (sand > 0.0f) {
        const float cover = CharSurfaceSpots(grid, height, sand, 20.0f + 70.0f * sand, 19.0f);
        const float3 grains = float3(0.80f, 0.68f, 0.45f) * (0.8f + 0.3f * FurNoise(anchor.xyz * 2.1f + 40.0f));
        color = lerp(color, grains, saturate(cover * tips * keep * 0.85f));
    }

    // Snow: white clumps where he touches it.
    if (snow > 0.0f) {
        const float cover = CharSurfaceSpots(grid, height, snow, 20.0f + 90.0f * snow, 41.0f);
        color = lerp(color, float3(0.92f, 0.95f, 1.0f), saturate(cover * tips * keep * 0.95f));
    }

    // Swimming: his fur and skin go dark and heavy.
    // (Only on what is fur, cloth and feathers: his pale skin, face and chest stay as they are.)
    const float hi = max(texColor.r, max(texColor.g, texColor.b));
    const float tint = keep * smoothstep(0.38f, 0.52f, (hi - min(texColor.r, min(texColor.g, texColor.b))) / max(hi, 1e-4f));
    const float soaked = FrParams.charSurface2.z;
    color *= 1.0f - 0.3f * soaked * tint;

    // Icy water (swimming in it, or still wet from it): an ice-blue cast over everything wet.
    const float icy = FrParams.charSurface2.w;
    if (icy > 0.0f) {
        const float cold = icy * saturate(max(wet, soaked)) * tint;
        const float luma = dot(color, float3(0.3f, 0.59f, 0.11f));
        color = lerp(color, float3(0.35f, 0.7f, 1.0f) * (luma + 0.12f) * 1.5f, 0.6f * cold);
    }

    // Wet: darker and a little richer all over, with a sheen where it catches the light.
    if (wet > 0.0f) {
        const float luma = dot(color, float3(0.3f, 0.59f, 0.11f));
        // (In the water it is just the darker fur: no sheen or spots, those come once he is out.)
        const float w = wet * tint;
        const float dry = 1.0f - soaked;
        color = lerp(color, color * color * 1.3f + luma * 0.05f, 0.7f * w);
        color *= 1.0f - 0.22f * w;
        color += float3(0.55f, 0.6f, 0.65f) * w * dry * 0.14f * smoothstep(0.55f, 0.85f, FurNoise(grid * 0.8f));

        // Dripping: bright streaks of water running down him (columns round the body, the pattern moving down the height).
        const float drip = FrParams.charSurface2.y;
        if (drip > 0.0f) {
            const float streakNoise = FurNoise(float3(anchor.x * 0.8f + 3.0f, anchor.z * 0.8f, height * 0.05f + FrParams.charSurface2.x * 1.6f));
            const float streak = smoothstep(0.72f, 0.9f, streakNoise) * smoothstep(8.0f, 30.0f, height) * drip * tint;
            color = lerp(color, color * 0.8f + float3(0.5f, 0.6f, 0.7f) * 0.3f, streak);
        }
    }
    return color;
}

#endif
