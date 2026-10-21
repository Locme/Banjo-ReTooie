//
// RT64
//

#pragma once

#include "rt64_descriptor_sets.h"
#include "rt64_shader_library.h"

namespace RT64 {
    // Banjo-Tooie: AMD FSR 1 upscaling of the game image to the window's size, just before the VI draws it.
    // Mode: 0 off, 1 FSR 1 (light sharpening), 2 FSR 1 sharp.
    void SetFsrMode(uint32_t mode);
    uint32_t GetFsrMode();

    struct FsrRenderer {
        std::unique_ptr<RenderTexture> upscaledTexture;
        std::unique_ptr<RenderTexture> outputTexture;
        std::unique_ptr<RenderFramebuffer> upscaledFramebuffer;
        std::unique_ptr<RenderFramebuffer> outputFramebuffer;
        std::unique_ptr<SmaaDescriptorSet> easuSet;
        std::unique_ptr<SmaaDescriptorSet> rcasSet;
        uint32_t width = 0;
        uint32_t height = 0;

        // Upscales by scale (above 1) and returns the sharpened image in a texture of outputWidth by
        // outputHeight, or the input itself when FSR is off or the format isn't the game's.
        RenderTexture *apply(RenderDevice *device, RenderCommandList *commandList, const ShaderLibrary *shaderLibrary,
            RenderTexture *input, RenderFormat format, uint32_t inputWidth, uint32_t inputHeight, uint32_t outputWidth, uint32_t outputHeight);
    };
};
