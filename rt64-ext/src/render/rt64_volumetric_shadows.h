//
// RT64
//

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_RENDER_RT64_VOLUMETRIC_SHADOWS_H
#define RT64_EXT_RENDER_RT64_VOLUMETRIC_SHADOWS_H

#include <functional>

#include "rt64_render_target.h"
#include "rt64_render_worker.h"

namespace RT64 {
    // Banjo-Tooie: volumetric shadows (shared/rt64_volumetric_shadows.h, src/gameplay/volumetric_shadows.cpp). Light in a
    // thin haze with the scenery's shadows cut out of it: shafts of sunlight between trees and under arches, and the glow
    // round the nearest lamps with the shadows of what stands in it. Its own maps, mesh and passes, whatever the sun
    // shadows or ray tracing do.
    struct VolumetricShadowSettings {
        // The sun's shafts (0 off, 1 strongest).
        float sun = 0.0f;
        // How thick the haze is (0 to 1).
        float haze = 0.4f;
        // 0 low (512 map, half-size light), 1 medium (1024, half size), 2 high (2048, full size).
        uint32_t quality = 1;
        // Half the width of the square of the world round the camera that the sun's map covers.
        float distance = 4000.0f;
        // The lamps' glow (0 off, 1 strongest), and how many of the nearest lamps have it (1 or 2).
        float lamps = 0.0f;
        uint32_t lampCount = 2;
        // 0 the picture, 1 only the light in the haze (over black), 2 that with the sun's map in the top left corner.
        uint32_t view = 0;
    };
    // Set by the game each frame (src/gameplay/volumetric_shadows.cpp declares this itself, so it takes plain values).
    void SetVolumetricShadows(float sun, float haze, uint32_t quality, float distance, float lamps, uint32_t lampCount, uint32_t view);
    VolumetricShadowSettings GetVolumetricShadows();
    bool VolumetricShadowsOn();

    // Called by the shader library with its other passes' pipelines (and again when the sample count changes).
    void SetupVolumetricShadowShaders(RenderDevice *device, RenderShaderFormat shaderFormat, const RenderMultisampling &multisampling, bool usesHDR);

    // What the scene effects know of the frame that the passes need too.
    struct VolumetricShadowFrame {
        // View-space position to world (SceneEffectsCB.worldX/Y/Z), the corrected depth terms, the projection's x and y
        // scales, and world to clip space (row-vector columns: clip.x = dot(float4(world, 1), clip[0])).
        float worldX[4];
        float worldY[4];
        float worldZ[4];
        float depthTerms[4];
        float projectionScale[2];
        float clip[4][4];
        // The direction towards the sun in the world (not normalized), and the light it gives now (the day and night
        // cycle's tint of the world, white without it).
        float sun[3];
        float sunTint[3];
        // The level's lights as SetSceneLights got them: x, y, z and outer range each.
        const float *lights = nullptr;
        uint32_t lightCount = 0;
        // The 3D world's area of the picture (empty for all of it).
        RenderRect area;
    };

    // Draws the volumetric shadows over the color target, after the scene effects. drawCasters draws the 3D world's solid
    // triangles (it binds its own descriptor set at 0 and index buffer) with the map's framebuffer, pipeline and constants
    // set. Leaves the color target ready for color writes and the depth target ready for depth writes.
    void RecordVolumetricShadows(RenderWorker *worker, RenderTarget *colorTarget, RenderTarget *depthTarget, const VolumetricShadowFrame &frame,
        const std::function<void(RenderCommandList *)> &drawCasters);
};

#endif // RT64_EXT_RENDER_RT64_VOLUMETRIC_SHADOWS_H
