//
// RT64
//

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_RENDER_RT64_PHOTO_GRADE_H
#define RT64_EXT_RENDER_RT64_PHOTO_GRADE_H

#include "rt64_descriptor_sets.h"
#include "rt64_shader_library.h"

namespace RT64 {
    // Banjo-Tooie: photo mode's filters, drawn over the game image after SMAA and before the VI (so
    // screenshots show them). Everything at 0 and enabled false leaves the picture alone.
    struct PhotoGradeSettings {
        bool enabled = false;
        uint32_t look = 0;
        float exposure = 0.0f;
        float contrast = 0.0f;
        float saturation = 0.0f;
        float warmth = 0.0f;
        float vignette = 0.0f;
        float grain = 0.0f;
        float cropAspect = 0.0f;
        bool grid = false;
        uint32_t border = 0;
        float dofStrength = 0.0f;
        uint32_t depthAddress = 0;
        float focusX = 0.5f;
        float focusY = 0.5f;
        float sharpen = 0.0f;
        bool compare = false;
    };

    void SetPhotoGrade(bool enabled, uint32_t look, float exposure, float contrast, float saturation, float warmth, float vignette, float grain);

    // The crop frame (width / height, 0 for none; outside it is shaded) and the rule-of-thirds grid.
    // The grid is left out of the frame a screenshot is taken from.
    void SetPhotoFrame(float cropAspect, bool grid);
    // A border drawn over the edge of the crop frame and kept in screenshots: 0 none, 1 instant photo, 2 film
    // strip, 3 honeycomb, 4 Jiggy, 5 wooden.
    void SetPhotoBorder(uint32_t border);

    // Depth of field (0 off, 1 strongest), focused on the nearest thing at the middle of the picture.
    // depthAddress is the game's depth buffer in RDRAM, whose render target gives the scene's depth.
    void SetPhotoDepthOfField(float strength, uint32_t depthAddress);
    // Where depth of field focuses, as a fraction of the picture (0.5, 0.5 is the middle, the default).
    void SetPhotoFocus(float x, float y);
    // Sharpening (0 off, 1 strongest), a contrast-adaptive sharpen drawn in the same pass. It is kept
    // apart from the filters above, which photo mode and the game's picture settings take turns to set.
    void SetSharpening(float strength);
    // Banjo-Tooie F8: the filters only on the left half of the picture, with a line down the middle.
    void SetPhotoGradeCompare(bool compare);

    // The depth of field strength and depth buffer address last set (strength 0 while photo mode is off).
    PhotoGradeSettings GetPhotoGrade();

    struct PhotoGradeRenderer {
        std::unique_ptr<RenderTexture> outputTexture;
        std::unique_ptr<RenderFramebuffer> outputFramebuffer;
        std::unique_ptr<SmaaDescriptorSet> descriptorSet;
        uint32_t width = 0;
        uint32_t height = 0;

        // Records the pass and returns the graded image, or the input itself when the filters are off.
        // forScreenshot leaves the grid out.
        // depth, when not null, holds the scene's depth as RT64's depth-to-color copy writes it (an RGBA16
        // depth value per pixel) at the input's size.
        RenderTexture *apply(RenderDevice *device, RenderCommandList *commandList, const ShaderLibrary *shaderLibrary,
            RenderTexture *input, RenderFormat format, uint32_t width, uint32_t height, bool forScreenshot, RenderTexture *depth);
    };
};

#endif // RT64_EXT_RENDER_RT64_PHOTO_GRADE_H
