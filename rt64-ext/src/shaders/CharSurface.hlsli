// Banjo-Tooie: the character surface layer: Banjo and Kazooie get wet, snowy and dirty (Graphics > Character Shaders).
// Pixel shading only, over the model's own colour (and over the fur shells and feathers' base), so it needs no motion
// vectors and no extra geometry.

#ifndef CHAR_SURFACE_HLSLI
#define CHAR_SURFACE_HLSLI

// mark: the vertex's fur mark with how far up it faces in the fraction (rt64_framebuffer_renderer.cpp,
// finishFurNormals): 0 down, 1 up. anchor: the vertex's place in the model (moves with the body, so the patches stick
// to it). share: 0 on the model itself, 0 to 1 up a fur shell (snow and dirt settle on the tips).
float3 CharSurface(float3 color, float4 anchor, float share) {
    const float wet = FrParams.charSurface.x;
    const float snow = FrParams.charSurface.y;
    const float dirt = FrParams.charSurface.z;
    const float up = saturate((anchor.w - floor(anchor.w + 0.05f)) / 0.45f);
    const float3 grid = anchor.xyz * 0.35f;
    const float noise = FurNoise(grid);
    const float patches = FurNoise(grid * 0.23f + 5.0f);

    // Dirt first: a brown film that settles lower down and on the undersides, in splotches.
    if (dirt > 0.0f) {
        const float cover = saturate((1.0f - up) * 0.8f + 0.25f) * smoothstep(0.35f, 0.7f, patches * 0.7f + noise * 0.5f - 0.15f + dirt * 0.5f) * dirt;
        const float3 mud = float3(0.30f, 0.21f, 0.12f) * (0.6f + 0.4f * noise);
        color = lerp(color, mud, saturate(cover * (0.55f + 0.45f * share)));
    }

    // Snow: on the surfaces facing up, in clumps, brightest at the tips of fur.
    if (snow > 0.0f) {
        const float cover = smoothstep(0.45f - 0.35f * snow, 0.8f - 0.3f * snow, up + (patches - 0.5f) * 0.6f);
        const float3 white = float3(0.90f, 0.93f, 1.0f) * (0.82f + 0.18f * up);
        color = lerp(color, white, saturate(cover * snow * (0.6f + 0.4f * share)));
    }

    // Wet: darker and a little richer, with a sheen on the surfaces facing up (sharpest where the patches are).
    if (wet > 0.0f) {
        const float luma = dot(color, float3(0.3f, 0.59f, 0.11f));
        color = lerp(color, color * color * 1.3f + luma * 0.05f, 0.7f * wet);
        color *= 1.0f - 0.22f * wet;
        color += float3(0.55f, 0.6f, 0.65f) * wet * 0.14f * smoothstep(0.55f, 1.0f, up) * smoothstep(0.35f, 0.8f, noise);
    }
    return color;
}

#endif
