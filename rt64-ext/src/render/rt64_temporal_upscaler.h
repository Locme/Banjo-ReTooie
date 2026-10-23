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
    // Mode: 0 off, 1 FSR 4, 2 FSR 4 native AA, 3 DLSS, 4 DLAA, 5 Arm ASR, 6 Snapdragon GSR (Android), 7 FSR 3, 8 the built-in temporal resolve.
    void SetUpscalerMode(uint32_t mode);
    uint32_t GetUpscalerMode();

    // Whether the chosen upscaler needs the 3D world drawn with camera jitter (the built-in temporal one does).
    bool UpscalerJitterActive();

    // Called once for each frame the projections are worked out for (ProjectionProcessor::process).
    void UpscalerNextFrame();

    // The jitter, in clip space, of the frame this many frames back (0 is the one being worked out). Zero when jitter is off.
    void UpscalerJitterNdc(uint32_t framesBack, float &x, float &y);

    // The 3D world's camera for the frame being drawn, from the framebuffer renderer: the projection and view as
    // drawn (jitter in them) and the ones of the frame before (ProjectionProcessor's prev matrices, which are equal to
    // the current ones when the camera cut), the viewport's depth range and the target's size.
    void SetUpscalerCamera(const float projection[16], const float view[16], const float prevProjection[16], const float prevView[16],
        float depthScale, float depthTranslate, uint32_t width, uint32_t height);

    struct UpscalerRenderer {
        std::unique_ptr<RenderTexture> velocityTexture;
        std::unique_ptr<RenderFramebuffer> velocityFramebuffer;
        std::unique_ptr<RenderTexture> debugTexture;
        std::unique_ptr<RenderFramebuffer> debugFramebuffer;
        std::unique_ptr<SmaaDescriptorSet> descriptorSet;
        std::unique_ptr<SmaaDescriptorSet> resolveDescriptorSet;
        std::unique_ptr<RenderTexture> resolved[2];
        std::unique_ptr<RenderFramebuffer> resolvedFramebuffer[2];
        uint32_t writeIndex = 0;
        uint32_t width = 0;
        uint32_t height = 0;
        uint32_t lastOutputWidth = 0;
        uint32_t lastOutputHeight = 0;
        uint32_t historyResets = 0;
        float currentJitter[2] = {};
        bool velocityValid = false;
        bool debugShown = false;
        bool historyValid = false;
        bool motionWasKnown = false;

        // Draws the camera's motion into velocityTexture (R16G16 float, pixels, previous minus current, y down) from the
        // depth (the copy of the game's depth RT64 makes for the color target of the same size). With the velocity
        // view on (TOOIE_VELOCITY_VIEW=1 or 2 for a bigger scale) it returns a picture of it instead of the input.
        RenderTexture *velocity(RenderDevice *device, RenderCommandList *commandList, const ShaderLibrary *shaderLibrary,
            RenderTexture *input, RenderFormat format, uint32_t inputWidth, uint32_t inputHeight, RenderTexture *depth);

        // The built-in temporal resolve: the jittered game image and its velocity, with the last result, make an image of
        // outputWidth by outputHeight (the same size or larger). Returns the input itself when it does not apply.
        RenderTexture *resolve(RenderDevice *device, RenderCommandList *commandList, const ShaderLibrary *shaderLibrary,
            RenderTexture *input, RenderFormat format, uint32_t inputWidth, uint32_t inputHeight, uint32_t outputWidth, uint32_t outputHeight);
    };
};

#endif // RT64_EXT_RENDER_RT64_TEMPORAL_UPSCALER_H
