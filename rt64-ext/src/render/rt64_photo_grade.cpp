//
// RT64
//

#include "rt64_photo_grade.h"

#include <chrono>
#include <mutex>

#include "shared/rt64_photo_grade.h"

#include "rt64_render_target.h"

namespace RT64 {
    namespace {
        std::mutex gradeMutex;
        PhotoGradeSettings gradeSettings;
        const auto startTime = std::chrono::steady_clock::now();
    }

    void SetPhotoGrade(bool enabled, uint32_t look, float exposure, float contrast, float saturation, float warmth, float vignette, float grain) {
        const std::scoped_lock lock(gradeMutex);
        const float cropAspect = gradeSettings.cropAspect;
        const bool grid = gradeSettings.grid;
        const uint32_t border = gradeSettings.border;
        const float dofStrength = gradeSettings.dofStrength;
        const uint32_t depthAddress = gradeSettings.depthAddress;
        const float focusX = gradeSettings.focusX;
        const float focusY = gradeSettings.focusY;
        const float sharpen = gradeSettings.sharpen;
        gradeSettings = { enabled, look, exposure, contrast, saturation, warmth, vignette, grain, cropAspect, grid, border, dofStrength, depthAddress, focusX, focusY, sharpen };
    }

    void SetSharpening(float strength) {
        const std::scoped_lock lock(gradeMutex);
        gradeSettings.sharpen = strength;
    }

    void SetPhotoDepthOfField(float strength, uint32_t depthAddress) {
        const std::scoped_lock lock(gradeMutex);
        gradeSettings.dofStrength = strength;
        gradeSettings.depthAddress = depthAddress;
    }

    void SetPhotoFocus(float x, float y) {
        const std::scoped_lock lock(gradeMutex);
        gradeSettings.focusX = x;
        gradeSettings.focusY = y;
    }

    PhotoGradeSettings GetPhotoGrade() {
        const std::scoped_lock lock(gradeMutex);
        return gradeSettings;
    }

    void SetPhotoGradeCompare(bool compare) {
        const std::scoped_lock lock(gradeMutex);
        gradeSettings.compare = compare;
    }

    void SetPhotoFrame(float cropAspect, bool grid) {
        const std::scoped_lock lock(gradeMutex);
        gradeSettings.cropAspect = cropAspect;
        gradeSettings.grid = grid;
    }

    void SetPhotoBorder(uint32_t border) {
        const std::scoped_lock lock(gradeMutex);
        gradeSettings.border = border;
    }

    RenderTexture *PhotoGradeRenderer::apply(RenderDevice *device, RenderCommandList *commandList, const ShaderLibrary *shaderLibrary,
        RenderTexture *input, RenderFormat format, uint32_t width, uint32_t height, bool forScreenshot, RenderTexture *depth)
    {
        PhotoGradeSettings settings;
        {
            const std::scoped_lock lock(gradeMutex);
            settings = gradeSettings;
        }

        if (!settings.enabled) {
            // Only the sharpening, if that.
            const float sharpen = settings.sharpen;
            const bool compare = settings.compare;
            settings = PhotoGradeSettings();
            settings.sharpen = sharpen;
            settings.compare = compare;
            if (sharpen <= 0.0f) {
                return input;
            }
        }

        if ((input == nullptr) || (width == 0) || (height == 0) || (format != RenderTarget::colorBufferFormat(shaderLibrary->usesHDR))) {
            return input;
        }

        if ((this->width != width) || (this->height != height) || (outputTexture == nullptr)) {
            outputFramebuffer.reset();
            outputTexture = device->createTexture(RenderTextureDesc::ColorTarget(width, height, format));
            outputTexture->setName("Photo Grade Output");
            const RenderTexture *output = outputTexture.get();
            outputFramebuffer = device->createFramebuffer(RenderFramebufferDesc(&output, 1));
            this->width = width;
            this->height = height;
        }

        if (descriptorSet == nullptr) {
            descriptorSet = std::make_unique<SmaaDescriptorSet>(shaderLibrary->samplerLibrary.linear.clampClamp.get(),
                shaderLibrary->samplerLibrary.nearest.clampClamp.get(), device);
        }

        // Every slot gets a texture; the pass reads the first, and the second for depth of field.
        descriptorSet->setTexture(descriptorSet->gTexture0, input, RenderTextureLayout::SHADER_READ);
        descriptorSet->setTexture(descriptorSet->gTexture1, (depth != nullptr) ? depth : input, RenderTextureLayout::SHADER_READ);
        descriptorSet->setTexture(descriptorSet->gTexture2, input, RenderTextureLayout::SHADER_READ);

        interop::PhotoGradeCB constants;
        constants.rtMetrics = { 1.0f / float(width), 1.0f / float(height), float(width), float(height) };
        constants.tone = { settings.exposure, settings.contrast, settings.saturation, settings.warmth };
        const float seconds = std::chrono::duration<float>(std::chrono::steady_clock::now() - startTime).count();
        constants.effects = { settings.vignette, settings.grain, seconds, float(settings.look) };
        constants.frame = { settings.cropAspect, (settings.grid && !forScreenshot) ? 1.0f : 0.0f, settings.compare ? 1.0f : 0.0f, float(settings.border) };
        constants.dof = { settings.dofStrength, (depth != nullptr) ? 1.0f : 0.0f, shaderLibrary->usesHDR ? 1.0f : 0.0f, settings.sharpen };
        constants.focus = { settings.focusX, settings.focusY, 0.0f, 0.0f };

        RenderTextureBarrier barriers[] = {
            RenderTextureBarrier(input, RenderTextureLayout::SHADER_READ),
            RenderTextureBarrier(outputTexture.get(), RenderTextureLayout::COLOR_WRITE),
            RenderTextureBarrier((depth != nullptr) ? depth : input, RenderTextureLayout::SHADER_READ)
        };

        commandList->barriers(RenderBarrierStage::GRAPHICS, barriers, uint32_t(std::size(barriers)));
        commandList->setFramebuffer(outputFramebuffer.get());
        commandList->setPipeline(shaderLibrary->photoGrade.pipeline.get());
        commandList->setGraphicsPipelineLayout(shaderLibrary->photoGrade.pipelineLayout.get());
        commandList->setGraphicsDescriptorSet(descriptorSet->get(), 0);
        commandList->setGraphicsPushConstants(0, &constants);
        commandList->setVertexBuffers(0, nullptr, 0, nullptr);
        commandList->setViewports(RenderViewport(0.0f, 0.0f, float(width), float(height)));
        commandList->setScissors(RenderRect(0, 0, width, height));
        commandList->drawInstanced(3, 1, 0, 0);
        return outputTexture.get();
    }
};
