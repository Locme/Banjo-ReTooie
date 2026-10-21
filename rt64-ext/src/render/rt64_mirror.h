//
// RT64
//

#pragma once

#include "rt64_descriptor_sets.h"
#include "rt64_shader_library.h"

namespace RT64 {
    // Banjo-Tooie: Mirror Mode flips the finished game image left to right, before the VI draws it. The draws after
    // the 3D world (HUD and text) are drawn flipped first (FramebufferRenderer::submitRasterScene), so they come
    // out where they were and readable.
    void SetMirrorMode(bool on);
    bool GetMirrorMode();

    // Mirror Mode: textures with writing on them (signs), which are flipped back so they read normally on the
    // mirrored world (RasterPS.hlsl). Read on the render thread.
    void SetMirrorTextTextures(const uint64_t *hashes, size_t count);
    bool MirrorTextTexture(uint64_t hash);

    struct MirrorRenderer {
        std::unique_ptr<RenderTexture> outputTexture;
        std::unique_ptr<RenderFramebuffer> outputFramebuffer;
        std::unique_ptr<SmaaDescriptorSet> descriptorSet;
        uint32_t width = 0;
        uint32_t height = 0;

        // Records the pass and returns the smoothed image, or the input itself when Mirror Mode is off or the
        // image is in a format the pass wasn't made for.
        RenderTexture *apply(RenderDevice *device, RenderCommandList *commandList, const ShaderLibrary *shaderLibrary,
            RenderTexture *input, RenderFormat format, uint32_t width, uint32_t height);
    };
};
