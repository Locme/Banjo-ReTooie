//
// RT64
//

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_RENDER_RT64_TEMPORAL_UPSCALER_H
#define RT64_EXT_RENDER_RT64_TEMPORAL_UPSCALER_H

#include "rt64_descriptor_sets.h"
#include "rt64_shader_library.h"

namespace RT64 {
    // Banjo-Tooie: the temporal upscaler chosen in Graphics (src/display/upscaler.cpp).
    // Mode: 0 off, 1 FSR 4, 2 FSR 4 native AA, 3 DLSS, 4 DLAA, 5 Arm ASR, 6 Snapdragon GSR (Android), 7 FSR 3.
    void SetUpscalerMode(uint32_t mode);
    uint32_t GetUpscalerMode();

    // The 3D world's camera for the frame being drawn, from the framebuffer renderer: the projection, the view (both as
    // the scene effects get them), the viewport's depth range and the target's size. The renderer keeps the last one to
    // work out how the camera moved.
    void SetUpscalerCamera(const float projection[16], const float view[16], float depthScale, float depthTranslate, uint32_t width, uint32_t height);

    // The camera's motion between the last two frames is only known when the camera has been set in both and the
    // picture did not cut in between.
    struct UpscalerRenderer {
        std::unique_ptr<RenderTexture> velocityTexture;
        std::unique_ptr<RenderFramebuffer> velocityFramebuffer;
        std::unique_ptr<RenderTexture> debugTexture;
        std::unique_ptr<RenderFramebuffer> debugFramebuffer;
        std::unique_ptr<SmaaDescriptorSet> descriptorSet;
        uint32_t width = 0;
        uint32_t height = 0;

        // Draws the camera's motion into velocityTexture (R16G16 float, pixels, previous minus current, y down) from the
        // depth (the copy of the game's depth RT64 makes for the color target of the same size). With the velocity
        // view on (TOOIE_VELOCITY_VIEW=1 or 2 for a bigger scale) it returns a picture of it instead of the input.
        RenderTexture *apply(RenderDevice *device, RenderCommandList *commandList, const ShaderLibrary *shaderLibrary,
            RenderTexture *input, RenderFormat format, uint32_t inputWidth, uint32_t inputHeight, RenderTexture *depth);
    };
};

#endif // RT64_EXT_RENDER_RT64_TEMPORAL_UPSCALER_H
