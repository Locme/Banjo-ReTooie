//
// RT64
//

#include "rt64_fsr.h"

#include <algorithm>
#include <atomic>
#include <cstring>

#include "shared/rt64_fsr.h"

#include "rt64_render_target.h"

#define A_CPU 1
#if defined(__GNUC__) || defined(__clang__)
#   define A_GCC 1
#endif
#include "ffx_a.h"
#include "ffx_fsr1.h"

namespace RT64 {
    namespace {
        std::atomic<uint32_t> fsrMode{ 0 };

        void toCB(const AU1 *con, interop::uint4 &out) {
            out = interop::uint4(con[0], con[1], con[2], con[3]);
        }
    }

    void SetFsrMode(uint32_t mode) {
        fsrMode = std::min(mode, 2U);
    }

    uint32_t GetFsrMode() {
        return fsrMode.load();
    }

    RenderTexture *FsrRenderer::apply(RenderDevice *device, RenderCommandList *commandList, const ShaderLibrary *shaderLibrary,
        RenderTexture *input, RenderFormat format, uint32_t inputWidth, uint32_t inputHeight, uint32_t outputWidth, uint32_t outputHeight)
    {
        const uint32_t mode = fsrMode.load();
        if ((mode == 0) || (input == nullptr) || (inputWidth == 0) || (inputHeight == 0) || (outputWidth <= inputWidth) || (outputHeight <= inputHeight) ||
            (format != RenderTarget::colorBufferFormat(shaderLibrary->usesHDR)))
        {
            return input;
        }

        if ((width != outputWidth) || (height != outputHeight) || (outputTexture == nullptr)) {
            upscaledFramebuffer.reset();
            outputFramebuffer.reset();
            upscaledTexture = device->createTexture(RenderTextureDesc::ColorTarget(outputWidth, outputHeight, format));
            outputTexture = device->createTexture(RenderTextureDesc::ColorTarget(outputWidth, outputHeight, format));
            upscaledTexture->setName("FSR Upscaled");
            outputTexture->setName("FSR Output");
            const RenderTexture *upscaled = upscaledTexture.get();
            const RenderTexture *output = outputTexture.get();
            upscaledFramebuffer = device->createFramebuffer(RenderFramebufferDesc(&upscaled, 1));
            outputFramebuffer = device->createFramebuffer(RenderFramebufferDesc(&output, 1));
            width = outputWidth;
            height = outputHeight;
        }

        if (easuSet == nullptr) {
            const RenderSampler *linearSampler = shaderLibrary->samplerLibrary.linear.clampClamp.get();
            const RenderSampler *pointSampler = shaderLibrary->samplerLibrary.nearest.clampClamp.get();
            easuSet = std::make_unique<SmaaDescriptorSet>(linearSampler, pointSampler, device);
            rcasSet = std::make_unique<SmaaDescriptorSet>(linearSampler, pointSampler, device);
        }

        // Every slot gets a texture, the ones a pass doesn't read included.
        easuSet->setTexture(easuSet->gTexture0, input, RenderTextureLayout::SHADER_READ);
        easuSet->setTexture(easuSet->gTexture1, input, RenderTextureLayout::SHADER_READ);
        easuSet->setTexture(easuSet->gTexture2, input, RenderTextureLayout::SHADER_READ);
        rcasSet->setTexture(rcasSet->gTexture0, upscaledTexture.get(), RenderTextureLayout::SHADER_READ);
        rcasSet->setTexture(rcasSet->gTexture1, upscaledTexture.get(), RenderTextureLayout::SHADER_READ);
        rcasSet->setTexture(rcasSet->gTexture2, upscaledTexture.get(), RenderTextureLayout::SHADER_READ);

        varAU4(con0);
        varAU4(con1);
        varAU4(con2);
        varAU4(con3);
        FsrEasuCon(con0, con1, con2, con3, AF1(inputWidth), AF1(inputHeight), AF1(inputWidth), AF1(inputHeight), AF1(outputWidth), AF1(outputHeight));
        interop::FsrCB easuConstants;
        toCB(con0, easuConstants.con0);
        toCB(con1, easuConstants.con1);
        toCB(con2, easuConstants.con2);
        toCB(con3, easuConstants.con3);

        // Sharpness in stops below the maximum: 0.25 for Sharp, 1 for the default.
        varAU4(rcasCon);
        FsrRcasCon(rcasCon, (mode == 2) ? 0.25f : 1.0f);
        interop::FsrCB rcasConstants;
        std::memset(&rcasConstants, 0, sizeof(rcasConstants));
        toCB(rcasCon, rcasConstants.con0);

        auto drawPass = [&](const ShaderRecord &record, const RenderFramebuffer *framebuffer, const SmaaDescriptorSet *set, const interop::FsrCB &constants) {
            commandList->setFramebuffer(framebuffer);
            commandList->setPipeline(record.pipeline.get());
            commandList->setGraphicsPipelineLayout(record.pipelineLayout.get());
            commandList->setGraphicsDescriptorSet(set->get(), 0);
            commandList->setGraphicsPushConstants(0, &constants);
            commandList->setVertexBuffers(0, nullptr, 0, nullptr);
            commandList->setViewports(RenderViewport(0.0f, 0.0f, float(outputWidth), float(outputHeight)));
            commandList->setScissors(RenderRect(0, 0, outputWidth, outputHeight));
            commandList->drawInstanced(3, 1, 0, 0);
        };

        RenderTextureBarrier easuBarriers[] = {
            RenderTextureBarrier(input, RenderTextureLayout::SHADER_READ),
            RenderTextureBarrier(upscaledTexture.get(), RenderTextureLayout::COLOR_WRITE)
        };

        commandList->barriers(RenderBarrierStage::GRAPHICS, easuBarriers, uint32_t(std::size(easuBarriers)));
        drawPass(shaderLibrary->fsrEasu, upscaledFramebuffer.get(), easuSet.get(), easuConstants);

        RenderTextureBarrier rcasBarriers[] = {
            RenderTextureBarrier(upscaledTexture.get(), RenderTextureLayout::SHADER_READ),
            RenderTextureBarrier(outputTexture.get(), RenderTextureLayout::COLOR_WRITE)
        };

        commandList->barriers(RenderBarrierStage::GRAPHICS, rcasBarriers, uint32_t(std::size(rcasBarriers)));
        drawPass(shaderLibrary->fsrRcas, outputFramebuffer.get(), rcasSet.get(), rcasConstants);
        return outputTexture.get();
    }
};
