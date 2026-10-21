//
// RT64
//

#include "rt64_mirror.h"

#include <algorithm>
#include <atomic>
#include <mutex>
#include <unordered_set>

#include "shared/rt64_smaa.h"

#include "rt64_render_target.h"

namespace RT64 {
    namespace {
        std::atomic<bool> mirrorMode{ false };
    }

    namespace {
        std::mutex textTextureMutex;
        std::unordered_set<uint64_t> textTextures;
    }

    void SetMirrorTextTextures(const uint64_t *hashes, size_t count) {
        std::unordered_set<uint64_t> textures(hashes, hashes + count);
        const std::scoped_lock lock(textTextureMutex);
        textTextures.swap(textures);
    }

    bool MirrorTextTexture(uint64_t hash) {
        const std::scoped_lock lock(textTextureMutex);
        return textTextures.count(hash) != 0;
    }

    void SetMirrorMode(bool on) {
        mirrorMode = on;
    }

    bool GetMirrorMode() {
        return mirrorMode.load();
    }

    RenderTexture *MirrorRenderer::apply(RenderDevice *device, RenderCommandList *commandList, const ShaderLibrary *shaderLibrary,
        RenderTexture *input, RenderFormat format, uint32_t width, uint32_t height)
    {
        if (!mirrorMode.load() || (input == nullptr) || (width == 0) || (height == 0) || (format != RenderTarget::colorBufferFormat(shaderLibrary->usesHDR))) {
            return input;
        }

        if ((this->width != width) || (this->height != height) || (outputTexture == nullptr)) {
            outputFramebuffer.reset();
            outputTexture = device->createTexture(RenderTextureDesc::ColorTarget(width, height, format));
            outputTexture->setName("Mirror Output");
            const RenderTexture *output = outputTexture.get();
            outputFramebuffer = device->createFramebuffer(RenderFramebufferDesc(&output, 1));
            this->width = width;
            this->height = height;
        }

        if (descriptorSet == nullptr) {
            descriptorSet = std::make_unique<SmaaDescriptorSet>(shaderLibrary->samplerLibrary.linear.clampClamp.get(),
                shaderLibrary->samplerLibrary.nearest.clampClamp.get(), device);
        }

        // Every slot gets a texture, the ones the pass doesn't read included.
        descriptorSet->setTexture(descriptorSet->gTexture0, input, RenderTextureLayout::SHADER_READ);
        descriptorSet->setTexture(descriptorSet->gTexture1, input, RenderTextureLayout::SHADER_READ);
        descriptorSet->setTexture(descriptorSet->gTexture2, input, RenderTextureLayout::SHADER_READ);

        interop::SmaaCB constants;
        constants.rtMetrics = { 1.0f / float(width), 1.0f / float(height), float(width), float(height) };

        RenderTextureBarrier barriers[] = {
            RenderTextureBarrier(input, RenderTextureLayout::SHADER_READ),
            RenderTextureBarrier(outputTexture.get(), RenderTextureLayout::COLOR_WRITE)
        };

        commandList->barriers(RenderBarrierStage::GRAPHICS, barriers, uint32_t(std::size(barriers)));
        const ShaderRecord &record = shaderLibrary->mirror;
        commandList->setFramebuffer(outputFramebuffer.get());
        commandList->setPipeline(record.pipeline.get());
        commandList->setGraphicsPipelineLayout(record.pipelineLayout.get());
        commandList->setGraphicsDescriptorSet(descriptorSet->get(), 0);
        commandList->setGraphicsPushConstants(0, &constants);
        commandList->setVertexBuffers(0, nullptr, 0, nullptr);
        commandList->setViewports(RenderViewport(0.0f, 0.0f, float(width), float(height)));
        commandList->setScissors(RenderRect(0, 0, width, height));
        commandList->drawInstanced(3, 1, 0, 0);
        return outputTexture.get();
    }
};
