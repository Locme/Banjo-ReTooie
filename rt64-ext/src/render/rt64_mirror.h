//
// RT64
//

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_RENDER_RT64_MIRROR_H
#define RT64_EXT_RENDER_RT64_MIRROR_H

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

    // Mirror Mode: framebuffers the 3D world was drawn to lately. A copy of one (the Start menu's background, a transition's
    // pieces) holds the picture as the present's flip wants it, so it is never drawn flipped. Render threads.
    void NoteMirrorPictureAddress(uint32_t address);
    bool MirrorPictureAddress(uint32_t address);

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

#endif // RT64_EXT_RENDER_RT64_MIRROR_H
