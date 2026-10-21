//
// RT64
//

#pragma once
#ifndef RT64_EXT_RENDER_RT64_TEXTURE_MARKS_H
#define RT64_EXT_RENDER_RT64_TEXTURE_MARKS_H

#include <cstddef>
#include <cstdint>

namespace RT64 {
    // Banjo-Tooie: Shader Effects pick mode's Slight Glow: textures drawn a little brighter, as if lit from inside
    // (RasterPS.hlsl, RASTER_SLIGHT_GLOW). Read on the render thread.
    void SetSceneGlowTextures(const uint64_t *hashes, size_t count);
    bool SceneGlowTexture(uint64_t hash);

    // Banjo-Tooie: Shader Effects pick mode's Light Source: textures that light the traced scene like a lamp, each
    // with its own reach (strength), and no glow in the air round the light. SceneLightSourceReach is 0 for others.
    void SetSceneLightSourceTextures(const uint64_t *hashes, const float *reaches, size_t count);
    float SceneLightSourceReach(uint64_t hash);

    // Banjo-Tooie: Shader Effects pick mode's Show All: while a pick mode is on, the draws with one of these textures
    // pulse in their own colour, between the picked texture's pulses.
    void SetScenePickMarkedTextures(const uint64_t *hashes, size_t count);
    bool ScenePickMarkedTexture(uint64_t hash);
}

#endif
