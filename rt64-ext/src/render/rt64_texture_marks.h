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

    // Banjo-Tooie: Shader Effects pick mode's Light Source picks: a model drawn with one of these textures shines whole
    // (every draw of the model gets Slight Glow), not only where the texture is. The model tagging sends which model each
    // bone matrix id belongs to (0 for none: the level, particles).
    void SetSceneShineModelTextures(const uint64_t *hashes, size_t count);
    bool SceneShineModelAny();
    bool SceneShineModelTexture(uint64_t hash);
    void SetSceneMatrixObjects(const uint32_t *ids, const uint32_t *objects, size_t count);
    uint32_t SceneMatrixObject(uint32_t matrixId);

    // Banjo-Tooie: Shader Effects pick mode's Light Source: textures that light the traced scene like a lamp, each
    // with its own reach (strength), and no glow in the air round the light. SceneLightSourceReach is 0 for others.
    void SetSceneLightSourceTextures(const uint64_t *hashes, const float *reaches, size_t count);
    float SceneLightSourceReach(uint64_t hash);
    // The light's w for a Light Source: its reach as a whole number, and the object's radius (up to 1000) in the
    // fraction, 0.05 to 0.95 (LightSourceRadius in SceneEffectsPS.hlsl). A lamp's w is whole (fraction 0).
    float SceneLightSourceW(float reach, float radius);

    // Banjo-Tooie: Shader Effects pick mode's Disable RT: textures whose draws stay out of the traced scene (they
    // cast no traced shadows and block no traced light; a lamp's glass, L 2026-10-22).
    void SetSceneRayOffTextures(const uint64_t *hashes, size_t count);
    bool SceneRayOffTexture(uint64_t hash);

    // Banjo-Tooie: Shader Effects pick mode's Show All: while a pick mode is on, the draws with one of these textures
    // pulse in their own colour, between the picked texture's pulses.
    void SetScenePickMarkedTextures(const uint64_t *hashes, size_t count);
    bool ScenePickMarkedTexture(uint64_t hash);
}

#endif
