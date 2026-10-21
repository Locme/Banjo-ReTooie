//
// RT64
//

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_RENDER_RT64_FXAA_H
#define RT64_EXT_RENDER_RT64_FXAA_H

#include "rt64_descriptor_sets.h"
#include "rt64_shader_library.h"

namespace RT64 {
    // Banjo-Tooie: FXAA on the finished game image, before the VI draws it (after SMAA when both are on).
    // Mode: 0 off, 1 FXAA, 2 FXAA Extreme.
    void SetFxaaMode(uint32_t mode);
    uint32_t GetFxaaMode();

    struct FxaaRenderer {
        std::unique_ptr<RenderTexture> outputTexture;
        std::unique_ptr<RenderFramebuffer> outputFramebuffer;
        std::unique_ptr<SmaaDescriptorSet> descriptorSet;
        uint32_t width = 0;
        uint32_t height = 0;

        // Records the pass and returns the smoothed image, or the input itself when FXAA is off or the
        // image is in a format the pass wasn't made for.
        RenderTexture *apply(RenderDevice *device, RenderCommandList *commandList, const ShaderLibrary *shaderLibrary,
            RenderTexture *input, RenderFormat format, uint32_t width, uint32_t height);
    };
};

#endif // RT64_EXT_RENDER_RT64_FXAA_H
