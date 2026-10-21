//
// RT64
//

#include "rt64_smaa.h"

#include <algorithm>
#include <atomic>
#include <cstring>

#include "AreaTex.h"
#include "SearchTex.h"

#include "shared/rt64_smaa.h"

#include "rt64_render_target.h"

namespace RT64 {
    namespace {
        std::atomic<uint32_t> smaaQuality{ 0 };

        // Uploads a lookup texture; the copy runs with the command list, so the upload buffer is kept.
        void uploadLookup(RenderDevice *device, RenderCommandList *commandList, std::unique_ptr<RenderTexture> &texture,
            std::unique_ptr<RenderBuffer> &upload, const unsigned char *bytes, uint32_t width, uint32_t height, RenderFormat format)
        {
            const uint32_t texelSize = RenderFormatSize(format);
            const uint32_t rowBytes = width * texelSize;
            // Rows are padded to 256 bytes, as D3D12 requires.
            const uint32_t alignedRowBytes = (rowBytes + 255) & ~255U;
            texture = device->createTexture(RenderTextureDesc::Texture2D(width, height, 1, format));
            upload = device->createBuffer(RenderBufferDesc::UploadBuffer(uint64_t(alignedRowBytes) * height));
            uint8_t *dst = reinterpret_cast<uint8_t *>(upload->map());
            for (uint32_t y = 0; y < height; y++) {
                std::memcpy(dst + uint64_t(y) * alignedRowBytes, bytes + uint64_t(y) * rowBytes, rowBytes);
            }

            upload->unmap();
            commandList->barriers(RenderBarrierStage::COPY, RenderTextureBarrier(texture.get(), RenderTextureLayout::COPY_DEST));
            commandList->copyTextureRegion(RenderTextureCopyLocation::Subresource(texture.get()),
                RenderTextureCopyLocation::PlacedFootprint(upload.get(), format, width, height, 1, alignedRowBytes / texelSize));
        }
    }

    void SetSmaaQuality(uint32_t quality) {
        smaaQuality = std::min(quality, 4U);
    }

    uint32_t GetSmaaQuality() {
        return smaaQuality.load();
    }

    RenderTexture *SmaaRenderer::apply(RenderDevice *device, RenderCommandList *commandList, const ShaderLibrary *shaderLibrary,
        RenderTexture *input, RenderFormat format, uint32_t width, uint32_t height)
    {
        const uint32_t quality = smaaQuality.load();
        if ((quality == 0) || (input == nullptr) || (width == 0) || (height == 0) || (format != RenderTarget::colorBufferFormat(shaderLibrary->usesHDR))) {
            return input;
        }

        if (areaTexture == nullptr) {
            uploadLookup(device, commandList, areaTexture, areaUpload, areaTexBytes, AREATEX_WIDTH, AREATEX_HEIGHT, RenderFormat::R8G8_UNORM);
            uploadLookup(device, commandList, searchTexture, searchUpload, searchTexBytes, SEARCHTEX_WIDTH, SEARCHTEX_HEIGHT, RenderFormat::R8_UNORM);
            RenderTextureBarrier lookupBarriers[] = {
                RenderTextureBarrier(areaTexture.get(), RenderTextureLayout::SHADER_READ),
                RenderTextureBarrier(searchTexture.get(), RenderTextureLayout::SHADER_READ)
            };

            commandList->barriers(RenderBarrierStage::GRAPHICS, lookupBarriers, uint32_t(std::size(lookupBarriers)));
        }

        if ((this->width != width) || (this->height != height) || (outputTexture == nullptr)) {
            const RenderTexture *edges;
            const RenderTexture *weights;
            const RenderTexture *output;
            edgesFramebuffer.reset();
            weightsFramebuffer.reset();
            outputFramebuffer.reset();
            edgesTexture = device->createTexture(RenderTextureDesc::ColorTarget(width, height, RenderFormat::R8G8_UNORM));
            weightsTexture = device->createTexture(RenderTextureDesc::ColorTarget(width, height, RenderFormat::R8G8B8A8_UNORM));
            outputTexture = device->createTexture(RenderTextureDesc::ColorTarget(width, height, format));
            edgesTexture->setName("SMAA Edges");
            weightsTexture->setName("SMAA Weights");
            outputTexture->setName("SMAA Output");
            edges = edgesTexture.get();
            weights = weightsTexture.get();
            output = outputTexture.get();
            edgesFramebuffer = device->createFramebuffer(RenderFramebufferDesc(&edges, 1));
            weightsFramebuffer = device->createFramebuffer(RenderFramebufferDesc(&weights, 1));
            outputFramebuffer = device->createFramebuffer(RenderFramebufferDesc(&output, 1));
            this->width = width;
            this->height = height;
        }

        if (edgesSet == nullptr) {
            const RenderSampler *linearSampler = shaderLibrary->samplerLibrary.linear.clampClamp.get();
            const RenderSampler *pointSampler = shaderLibrary->samplerLibrary.nearest.clampClamp.get();
            edgesSet = std::make_unique<SmaaDescriptorSet>(linearSampler, pointSampler, device);
            weightsSet = std::make_unique<SmaaDescriptorSet>(linearSampler, pointSampler, device);
            blendSet = std::make_unique<SmaaDescriptorSet>(linearSampler, pointSampler, device);
        }

        // Every slot gets a texture, the ones a pass doesn't read included.
        edgesSet->setTexture(edgesSet->gTexture0, input, RenderTextureLayout::SHADER_READ);
        edgesSet->setTexture(edgesSet->gTexture1, areaTexture.get(), RenderTextureLayout::SHADER_READ);
        edgesSet->setTexture(edgesSet->gTexture2, searchTexture.get(), RenderTextureLayout::SHADER_READ);
        weightsSet->setTexture(weightsSet->gTexture0, edgesTexture.get(), RenderTextureLayout::SHADER_READ);
        weightsSet->setTexture(weightsSet->gTexture1, areaTexture.get(), RenderTextureLayout::SHADER_READ);
        weightsSet->setTexture(weightsSet->gTexture2, searchTexture.get(), RenderTextureLayout::SHADER_READ);
        blendSet->setTexture(blendSet->gTexture0, input, RenderTextureLayout::SHADER_READ);
        blendSet->setTexture(blendSet->gTexture1, weightsTexture.get(), RenderTextureLayout::SHADER_READ);
        blendSet->setTexture(blendSet->gTexture2, searchTexture.get(), RenderTextureLayout::SHADER_READ);

        interop::SmaaCB constants;
        constants.rtMetrics = { 1.0f / float(width), 1.0f / float(height), float(width), float(height) };

        auto drawPass = [&](const ShaderRecord &record, const RenderFramebuffer *framebuffer, const SmaaDescriptorSet *set) {
            commandList->setFramebuffer(framebuffer);
            commandList->clearColor(0, RenderColor(0.0f, 0.0f, 0.0f, 0.0f));
            commandList->setPipeline(record.pipeline.get());
            commandList->setGraphicsPipelineLayout(record.pipelineLayout.get());
            commandList->setGraphicsDescriptorSet(set->get(), 0);
            commandList->setGraphicsPushConstants(0, &constants);
            commandList->setVertexBuffers(0, nullptr, 0, nullptr);
            commandList->setViewports(RenderViewport(0.0f, 0.0f, float(width), float(height)));
            commandList->setScissors(RenderRect(0, 0, width, height));
            commandList->drawInstanced(3, 1, 0, 0);
        };

        const uint32_t preset = quality - 1;
        RenderTextureBarrier edgesBarriers[] = {
            RenderTextureBarrier(input, RenderTextureLayout::SHADER_READ),
            RenderTextureBarrier(edgesTexture.get(), RenderTextureLayout::COLOR_WRITE)
        };

        commandList->barriers(RenderBarrierStage::GRAPHICS, edgesBarriers, uint32_t(std::size(edgesBarriers)));
        drawPass(shaderLibrary->smaaEdges[preset], edgesFramebuffer.get(), edgesSet.get());

        RenderTextureBarrier weightsBarriers[] = {
            RenderTextureBarrier(edgesTexture.get(), RenderTextureLayout::SHADER_READ),
            RenderTextureBarrier(weightsTexture.get(), RenderTextureLayout::COLOR_WRITE)
        };

        commandList->barriers(RenderBarrierStage::GRAPHICS, weightsBarriers, uint32_t(std::size(weightsBarriers)));
        drawPass(shaderLibrary->smaaWeights[preset], weightsFramebuffer.get(), weightsSet.get());

        RenderTextureBarrier blendBarriers[] = {
            RenderTextureBarrier(weightsTexture.get(), RenderTextureLayout::SHADER_READ),
            RenderTextureBarrier(outputTexture.get(), RenderTextureLayout::COLOR_WRITE)
        };

        commandList->barriers(RenderBarrierStage::GRAPHICS, blendBarriers, uint32_t(std::size(blendBarriers)));
        drawPass(shaderLibrary->smaaBlend, outputFramebuffer.get(), blendSet.get());
        return outputTexture.get();
    }
};
