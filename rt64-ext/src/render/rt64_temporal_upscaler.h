//
// RT64
//

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_RENDER_RT64_TEMPORAL_UPSCALER_H
#define RT64_EXT_RENDER_RT64_TEMPORAL_UPSCALER_H

#include <functional>

#include "rt64_descriptor_sets.h"
#include "rt64_shader_library.h"
#include "rt64_dlss.h"
#include "rt64_ffx_upscaler.h"

namespace RT64 {
    struct RenderWorker;
    struct RenderTarget;
    struct RenderFramebufferStorage;

    // Banjo-Tooie: the temporal upscaler chosen in Graphics (src/display/upscaler.cpp).
    // Mode: 0 off, 1 FSR 4, 2 FSR 4 native AA, 3 DLSS, 4 DLAA, 5 Arm ASR, 6 Snapdragon GSR (Android), 7 FSR 3, 8 the built-in temporal resolve.
    // 1 to 4 and 7 run in AMD's and NVIDIA's DLLs (Windows) and fall back to 8 when the DLL or card cannot do it.
    void SetUpscalerMode(uint32_t mode);
    uint32_t GetUpscalerMode();

    // How much of the window's height the game renders at, when the Resolution setting is Auto and an upscaler that
    // enlarges is chosen: 0 Quality (about 67%), 1 Balanced (58%), 2 Performance (50%), 3 Ultra Performance (33%).
    void SetUpscalerQuality(uint32_t quality);

    // 1 when nothing is to be enlarged (no upscaler, or a native-resolution mode), else the fraction of the window's height.
    float UpscalerRenderFraction();

    // Whether the built-in temporal upscaler is the chosen one.
    bool UpscalerWanted();

    // Whether the 3D world is to be drawn with camera jitter now: it is wanted and the resolve has not been failing.
    bool UpscalerJitterActive();

    // Called once for each frame the projections are worked out for (ProjectionProcessor::process).
    void UpscalerNextFrame();

    // 0 to 1, a new value each frame while the camera is jittered (else 0): the scene effects' ray noise is turned by it
    // (SceneEffectsPS.hlsl NoiseFrameOffset), so the upscaler averages the noise over frames instead of flickering.
    float UpscalerNoiseOffset();

    // The jitter, in clip space, of the frame this many frames back (0 is the one being worked out). Zero when jitter is off.
    void UpscalerJitterNdc(uint32_t framesBack, float &x, float &y);

    // The 3D world's camera for the frame being drawn, from the framebuffer renderer: the projection and view as
    // drawn (jitter in them) and the ones of the frame before (ProjectionProcessor's prev matrices, which are equal to
    // the current ones when the camera cut), the viewport's depth range and the target's size.
    void SetUpscalerCamera(const float projection[16], const float view[16], const float prevProjection[16], const float prevView[16],
        float depthScale, float depthTranslate, uint32_t width, uint32_t height);

    // The camera's near and far planes and vertical field of view (radians), from the last projection seen.
    void UpscalerCameraRange(float &nearPlane, float &farPlane, float &fovY);

    // The velocity of things that move on their own (characters, enemies): the framebuffer renderer, once the 3D world is
    // drawn, draws the solid triangles again with the world positions and the world velocities RT64 worked out. draw
    // sets the vertex and index buffers and issues the draws.
    bool UpscalerObjectVelocityWanted();
    void UpscalerRecordObjectVelocity(RenderWorker *worker, uint32_t width, uint32_t height, const ShaderLibrary *shaderLibrary,
        const RenderBuffer *worldPos, const RenderBuffer *worldVel, const std::function<void(RenderCommandList *)> &draw,
        const std::function<void(RenderCommandList *)> &drawReactive);

    // Graphics > Upscaler > Reactive mask: the see-through draws (particles, fire, spray) marked so the upscaler trusts
    // its history less there (drawReactive, in the call above, draws them). And Sharpness (0 to 1).
    void SetUpscalerReactive(bool enabled);
    // Graphics > Upscaler > Object Motion: the moving things' own velocity (the solid draws again; costs GPU time).
    void SetUpscalerObjectMotion(bool enabled);
    void SetUpscalerSharpness(float sharpness);
    float UpscalerSharpness();

    // The present queue: the reactive mask (R8) of the frame being shown, or null. Taken once.
    RenderTexture *UpscalerObjectReactive(uint32_t width, uint32_t height);

    // The present queue: the objects' velocity of the frame being shown (alpha 1 where an object was drawn), or null.
    RenderTexture *UpscalerObjectVelocity(uint32_t width, uint32_t height);

    // Graphics > Upscaler > Keep the HUD out of the upscale: the 3D world is copied before the HUD is drawn, the
    // upscaler works on the copy, and the HUD is put back after (UpscalerRenderer::composeHud).
    void SetUpscalerHudSplit(bool enabled);
    bool UpscalerHudSplitWanted();

    // The framebuffer renderer, once the 3D world is drawn and before the HUD: copies the color target.
    void UpscalerTakeWorldSnapshot(RenderWorker *worker, RenderTarget *colorTarget, const ShaderLibrary *shaderLibrary);

    // The present queue: the copy of colorTarget (the framebuffer being shown), or null if there is none or it is not
    // width by height. Each framebuffer has its own copy, so the game drawing the next frame into its other framebuffer
    // while this one is shown does not swap the copy under it. A copy can be taken once.
    RenderTexture *UpscalerWorldSnapshot(const RenderTarget *colorTarget, uint32_t width, uint32_t height);

    // Graphics > Upscaler > HUD at full resolution (experimental): after the 3D world the framebuffer renderer draws the HUD
    // again at the upscaler's output size, once over black and once over white, and the present queue puts it on the upscaled
    // picture (UpscalerRenderer::composeHudLayers). The present queue says the output size it is using for the frame.
    void SetUpscalerHudFullResolution(bool enabled);
    void SetUpscalerOutputSize(uint32_t width, uint32_t height);
    bool UpscalerHudLayersWanted(uint32_t colorWidth, uint32_t colorHeight, uint32_t sampleCount);
    RenderFramebufferStorage *UpscalerBeginHudLayer(RenderWorker *worker, RenderTarget *colorTarget, uint32_t layer, float &scaleX, float &scaleY);
    void UpscalerEndHudLayer(RenderWorker *worker, uint32_t layer);
    bool UpscalerHudLayers(uint32_t width, uint32_t height, RenderTexture *&black, RenderTexture *&white);

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

        // DLSS and DLAA (Windows): a float copy of the depth, an output it can write, and the backend.
        std::unique_ptr<RenderTexture> depthFloatTexture;
        std::unique_ptr<RenderFramebuffer> depthFloatFramebuffer;
        std::unique_ptr<RenderTexture> dlssOutput;
        DlssBackend dlss;
        FfxBackend ffx;
        bool depthFloatValid = false;
        std::unique_ptr<RenderTexture> hudTexture;
        std::unique_ptr<RenderFramebuffer> hudFramebuffer;
        std::unique_ptr<SmaaDescriptorSet> hudDescriptorSet;
        uint32_t hudWidth = 0;
        uint32_t hudHeight = 0;
        uint32_t depthFloatWidth = 0;
        uint32_t depthFloatHeight = 0;
        uint32_t dlssOutputWidth = 0;
        uint32_t dlssOutputHeight = 0;

        // Draws the camera's motion into velocityTexture (R16G16 float, pixels, previous minus current, y down) from the
        // depth (the copy of the game's depth RT64 makes for the color target of the same size). With the velocity
        // view on (TOOIE_VELOCITY_VIEW=1 or 2 for a bigger scale) it returns a picture of it instead of the input.
        RenderTexture *velocity(RenderDevice *device, RenderCommandList *commandList, const ShaderLibrary *shaderLibrary,
            RenderTexture *input, RenderFormat format, uint32_t inputWidth, uint32_t inputHeight, RenderTexture *depth);

        // The built-in temporal resolve: the jittered game image and its velocity, with the last result, make an image of
        // outputWidth by outputHeight (the same size or larger). Returns the input itself when it does not apply.
        // Puts the HUD layers (drawn at the output size over black and over white) on the upscaled world.
        RenderTexture *composeHudLayers(RenderDevice *device, RenderCommandList *commandList, const ShaderLibrary *shaderLibrary,
            RenderTexture *upscaled, RenderTexture *black, RenderTexture *white, RenderFormat format, uint32_t outputWidth, uint32_t outputHeight);

        // Adds the HUD (the finished frame minus the world copy) to the upscaled world. Returns the upscaled world if it cannot.
        RenderTexture *composeHud(RenderDevice *device, RenderCommandList *commandList, const ShaderLibrary *shaderLibrary,
            RenderTexture *upscaled, RenderTexture *world, RenderTexture *finished, RenderFormat format,
            uint32_t inputWidth, uint32_t inputHeight, uint32_t outputWidth, uint32_t outputHeight);

        RenderTexture *resolve(RenderDevice *device, RenderCommandList *commandList, const ShaderLibrary *shaderLibrary,
            RenderTexture *input, RenderFormat format, uint32_t inputWidth, uint32_t inputHeight, uint32_t outputWidth, uint32_t outputHeight);
    };
};

#endif // RT64_EXT_RENDER_RT64_TEMPORAL_UPSCALER_H
