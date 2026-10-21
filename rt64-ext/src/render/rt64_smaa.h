//
// RT64
//

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_RENDER_RT64_SMAA_H
#define RT64_EXT_RENDER_RT64_SMAA_H

#include "rt64_descriptor_sets.h"
#include "rt64_shader_library.h"

namespace RT64 {
    // Banjo-Tooie: SMAA 1x (iryoku/smaa) on the finished game image, before the VI draws it, so it works
    // the same with or without MSAA. Quality: 0 off, 1 low, 2 medium, 3 high, 4 ultra.
    void SetSmaaQuality(uint32_t quality);
    uint32_t GetSmaaQuality();

    struct SmaaRenderer {
        std::unique_ptr<RenderTexture> areaTexture;
        std::unique_ptr<RenderTexture> searchTexture;
        std::unique_ptr<RenderBuffer> areaUpload;
        std::unique_ptr<RenderBuffer> searchUpload;
        std::unique_ptr<RenderTexture> edgesTexture;
        std::unique_ptr<RenderTexture> weightsTexture;
        std::unique_ptr<RenderTexture> outputTexture;
        std::unique_ptr<RenderFramebuffer> edgesFramebuffer;
        std::unique_ptr<RenderFramebuffer> weightsFramebuffer;
        std::unique_ptr<RenderFramebuffer> outputFramebuffer;
        std::unique_ptr<SmaaDescriptorSet> edgesSet;
        std::unique_ptr<SmaaDescriptorSet> weightsSet;
        std::unique_ptr<SmaaDescriptorSet> blendSet;
        uint32_t width = 0;
        uint32_t height = 0;

        // Records the three passes and returns the smoothed image, or the input itself when SMAA is off
        // or the image is in a format the passes weren't made for.
        RenderTexture *apply(RenderDevice *device, RenderCommandList *commandList, const ShaderLibrary *shaderLibrary,
            RenderTexture *input, RenderFormat format, uint32_t width, uint32_t height);
    };
};

#endif // RT64_EXT_RENDER_RT64_SMAA_H
