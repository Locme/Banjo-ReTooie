//
// RT64
//

#include "rt64_temporal_upscaler.h"

#include <algorithm>
#include <atomic>
#include <cmath>
#include <cstdlib>
#include <mutex>

#include "shared/rt64_temporal_upscaler.h"

#include "rt64_render_target.h"

namespace RT64 {
    namespace {
        std::atomic<uint32_t> upscalerMode{ 0 };

        struct Camera {
            float projection[16] = {};
            float view[16] = {};
            float depthScale = 0.5f;
            float depthTranslate = 0.5f;
            uint32_t width = 0;
            uint32_t height = 0;
            bool valid = false;
        };

        std::mutex cameraMutex;
        Camera currentCamera;
        Camera previousCamera;
        // Whether a frame has drawn with the current camera: the next camera set then moves it to previousCamera.
        bool currentUsed = false;

        // Row-major 4x4 inverse by cofactors; false if singular.
        bool invert(const float m[16], float out[16]) {
            float inv[16];
            inv[0] = m[5] * m[10] * m[15] - m[5] * m[11] * m[14] - m[9] * m[6] * m[15] + m[9] * m[7] * m[14] + m[13] * m[6] * m[11] - m[13] * m[7] * m[10];
            inv[4] = -m[4] * m[10] * m[15] + m[4] * m[11] * m[14] + m[8] * m[6] * m[15] - m[8] * m[7] * m[14] - m[12] * m[6] * m[11] + m[12] * m[7] * m[10];
            inv[8] = m[4] * m[9] * m[15] - m[4] * m[11] * m[13] - m[8] * m[5] * m[15] + m[8] * m[7] * m[13] + m[12] * m[5] * m[11] - m[12] * m[7] * m[9];
            inv[12] = -m[4] * m[9] * m[14] + m[4] * m[10] * m[13] + m[8] * m[5] * m[14] - m[8] * m[6] * m[13] - m[12] * m[5] * m[10] + m[12] * m[6] * m[9];
            inv[1] = -m[1] * m[10] * m[15] + m[1] * m[11] * m[14] + m[9] * m[2] * m[15] - m[9] * m[3] * m[14] - m[13] * m[2] * m[11] + m[13] * m[3] * m[10];
            inv[5] = m[0] * m[10] * m[15] - m[0] * m[11] * m[14] - m[8] * m[2] * m[15] + m[8] * m[3] * m[14] + m[12] * m[2] * m[11] - m[12] * m[3] * m[10];
            inv[9] = -m[0] * m[9] * m[15] + m[0] * m[11] * m[13] + m[8] * m[1] * m[15] - m[8] * m[3] * m[13] - m[12] * m[1] * m[11] + m[12] * m[3] * m[9];
            inv[13] = m[0] * m[9] * m[14] - m[0] * m[10] * m[13] - m[8] * m[1] * m[14] + m[8] * m[2] * m[13] + m[12] * m[1] * m[10] - m[12] * m[2] * m[9];
            inv[2] = m[1] * m[6] * m[15] - m[1] * m[7] * m[14] - m[5] * m[2] * m[15] + m[5] * m[3] * m[14] + m[13] * m[2] * m[7] - m[13] * m[3] * m[6];
            inv[6] = -m[0] * m[6] * m[15] + m[0] * m[7] * m[14] + m[4] * m[2] * m[15] - m[4] * m[3] * m[14] - m[12] * m[2] * m[7] + m[12] * m[3] * m[6];
            inv[10] = m[0] * m[5] * m[15] - m[0] * m[7] * m[13] - m[4] * m[1] * m[15] + m[4] * m[3] * m[13] + m[12] * m[1] * m[7] - m[12] * m[3] * m[5];
            inv[14] = -m[0] * m[5] * m[14] + m[0] * m[6] * m[13] + m[4] * m[1] * m[14] - m[4] * m[2] * m[13] - m[12] * m[1] * m[6] + m[12] * m[2] * m[5];
            inv[3] = -m[1] * m[6] * m[11] + m[1] * m[7] * m[10] + m[5] * m[2] * m[11] - m[5] * m[3] * m[10] - m[9] * m[2] * m[7] + m[9] * m[3] * m[6];
            inv[7] = m[0] * m[6] * m[11] - m[0] * m[7] * m[10] - m[4] * m[2] * m[11] + m[4] * m[3] * m[10] + m[8] * m[2] * m[7] - m[8] * m[3] * m[6];
            inv[11] = -m[0] * m[5] * m[11] + m[0] * m[7] * m[9] + m[4] * m[1] * m[11] - m[4] * m[3] * m[9] - m[8] * m[1] * m[7] + m[8] * m[3] * m[5];
            inv[15] = m[0] * m[5] * m[10] - m[0] * m[6] * m[9] - m[4] * m[1] * m[10] + m[4] * m[2] * m[9] + m[8] * m[1] * m[6] - m[8] * m[2] * m[5];
            const float det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];
            if (std::abs(det) < 1e-20f) {
                return false;
            }
            for (int i = 0; i < 16; i++) {
                out[i] = inv[i] / det;
            }
            return true;
        }

        void multiply(const float a[16], const float b[16], float out[16]) {
            float result[16];
            for (int r = 0; r < 4; r++) {
                for (int c = 0; c < 4; c++) {
                    float sum = 0.0f;
                    for (int k = 0; k < 4; k++) {
                        sum += a[r * 4 + k] * b[k * 4 + c];
                    }
                    result[r * 4 + c] = sum;
                }
            }
            std::copy(result, result + 16, out);
        }

        // The game's matrices are row-vector (clip = v * M), told apart by the projection (as the scene effects do).
        bool rowVectorProjection(const float m[16]) {
            return std::abs(m[2 * 4 + 3] + 1.0f) <= std::abs(m[3 * 4 + 2] + 1.0f);
        }

        void rowVectorForm(const float m[16], bool rowVector, float out[16]) {
            for (int r = 0; r < 4; r++) {
                for (int c = 0; c < 4; c++) {
                    out[r * 4 + c] = rowVector ? m[r * 4 + c] : m[c * 4 + r];
                }
            }
        }

        // Works out, for the current camera, the matrix taking a view-space position to the previous camera's clip
        // space. False when there is no previous camera of the same size to compare to.
        bool reprojection(const Camera &cur, const Camera &prev, float out[16], interop::float4 &depthTerms) {
            if (!cur.valid || !prev.valid || (cur.width != prev.width) || (cur.height != prev.height)) {
                return false;
            }
            const float (&cm)[16] = cur.projection;
            if ((std::abs(cm[2 * 4 + 3] + 1.0f) > 0.01f) && (std::abs(cm[3 * 4 + 2] + 1.0f) > 0.01f)) {
                return false;
            }
            const bool curRow = rowVectorProjection(cur.projection);
            const bool prevRow = rowVectorProjection(prev.projection);
            float curView[16], prevView[16], prevProj[16];
            rowVectorForm(cur.view, curRow, curView);
            rowVectorForm(prev.view, prevRow, prevView);
            rowVectorForm(prev.projection, prevRow, prevProj);
            float curViewInverse[16];
            if (!invert(curView, curViewInverse)) {
                return false;
            }
            // view(cur) -> world -> view(prev) -> clip(prev).
            float step[16], full[16];
            multiply(curViewInverse, prevView, step);
            multiply(step, prevProj, full);
            std::copy(full, full + 16, out);

            // The projection's depth terms, folded with the viewport's depth range as the scene effects do.
            interop::float4 t = curRow ? interop::float4{ cm[2 * 4 + 2], cm[3 * 4 + 2], cm[2 * 4 + 3], cm[3 * 4 + 3] } :
                interop::float4{ cm[2 * 4 + 2], cm[2 * 4 + 3], cm[3 * 4 + 2], cm[3 * 4 + 3] };
            if (std::abs(cur.depthScale) >= 1e-6f) {
                const float a = 0.5f / cur.depthScale;
                const float b = (0.5f - cur.depthTranslate) / cur.depthScale;
                t = interop::float4{ t.x - b * t.z, t.y - b * t.w, a * t.z, a * t.w };
            }
            depthTerms = t;
            return true;
        }
    }

    void SetUpscalerMode(uint32_t mode) {
        upscalerMode = std::min(mode, 7U);
    }

    uint32_t GetUpscalerMode() {
        return upscalerMode.load();
    }

    void SetUpscalerCamera(const float projection[16], const float view[16], float depthScale, float depthTranslate, uint32_t width, uint32_t height) {
        if (upscalerMode.load() == 0) {
            return;
        }
        const std::scoped_lock lock(cameraMutex);
        // A camera set again before a frame used the last one replaces it (a frame can have the world drawn in parts).
        if (currentUsed) {
            previousCamera = currentCamera;
            currentUsed = false;
        }
        std::copy(projection, projection + 16, currentCamera.projection);
        std::copy(view, view + 16, currentCamera.view);
        currentCamera.depthScale = depthScale;
        currentCamera.depthTranslate = depthTranslate;
        currentCamera.width = width;
        currentCamera.height = height;
        currentCamera.valid = true;
    }

    RenderTexture *UpscalerRenderer::apply(RenderDevice *device, RenderCommandList *commandList, const ShaderLibrary *shaderLibrary,
        RenderTexture *input, RenderFormat format, uint32_t inputWidth, uint32_t inputHeight, RenderTexture *depth)
    {
        if ((GetUpscalerMode() == 0) || (input == nullptr) || (depth == nullptr) || (inputWidth == 0) || (inputHeight == 0) ||
            (format != RenderTarget::colorBufferFormat(shaderLibrary->usesHDR)))
        {
            return input;
        }

        interop::UpscalerVelocityCB constants;
        float reproject[16];
        {
            const std::scoped_lock lock(cameraMutex);
            // The camera of this frame is the one set last; the one before it is what it moved from.
            currentUsed = true;
            constants.flags.w = 0.0f;
            if (!reprojection(currentCamera, previousCamera, reproject, constants.depthTerms)) {
                // No motion known: no velocity.
                constants.flags.w = 1.0f;
                std::fill(reproject, reproject + 16, 0.0f);
                reproject[0] = reproject[5] = reproject[10] = reproject[15] = 1.0f;
                constants.depthTerms = { 1.0f, 0.0f, 0.0f, 1.0f };
            }
            constants.projection = { currentCamera.projection[0], currentCamera.projection[5], float(inputWidth), float(inputHeight) };
        }
        // Row-vector form of the current projection's scale is its own [0][0] and [1][1] either way round.
        constants.reproject0 = { reproject[0], reproject[1], reproject[2], reproject[3] };
        constants.reproject1 = { reproject[4], reproject[5], reproject[6], reproject[7] };
        constants.reproject2 = { reproject[8], reproject[9], reproject[10], reproject[11] };
        constants.reproject3 = { reproject[12], reproject[13], reproject[14], reproject[15] };

        static const char *viewEnv = std::getenv("TOOIE_VELOCITY_VIEW");
        const bool debugView = (viewEnv != nullptr) && (viewEnv[0] != '0');
        const float debugScale = (viewEnv != nullptr) && (viewEnv[0] == '2') ? 4.0f : 16.0f;

        if ((this->width != inputWidth) || (this->height != inputHeight) || (velocityTexture == nullptr)) {
            velocityFramebuffer.reset();
            debugFramebuffer.reset();
            velocityTexture = device->createTexture(RenderTextureDesc::ColorTarget(inputWidth, inputHeight, RenderFormat::R16G16_FLOAT));
            velocityTexture->setName("Upscaler Velocity");
            debugTexture = device->createTexture(RenderTextureDesc::ColorTarget(inputWidth, inputHeight, format));
            debugTexture->setName("Upscaler Velocity View");
            const RenderTexture *velocity = velocityTexture.get();
            const RenderTexture *debug = debugTexture.get();
            velocityFramebuffer = device->createFramebuffer(RenderFramebufferDesc(&velocity, 1));
            debugFramebuffer = device->createFramebuffer(RenderFramebufferDesc(&debug, 1));
            this->width = inputWidth;
            this->height = inputHeight;
        }

        if (descriptorSet == nullptr) {
            descriptorSet = std::make_unique<SmaaDescriptorSet>(shaderLibrary->samplerLibrary.linear.clampClamp.get(),
                shaderLibrary->samplerLibrary.nearest.clampClamp.get(), device);
        }

        // Every slot gets a texture; the pass reads the second (the depth).
        descriptorSet->setTexture(descriptorSet->gTexture0, input, RenderTextureLayout::SHADER_READ);
        descriptorSet->setTexture(descriptorSet->gTexture1, depth, RenderTextureLayout::SHADER_READ);
        descriptorSet->setTexture(descriptorSet->gTexture2, input, RenderTextureLayout::SHADER_READ);

        auto drawPass = [&](const ShaderRecord &record, const RenderFramebuffer *framebuffer, bool asPicture) {
            constants.flags = { asPicture ? 1.0f : 0.0f, debugScale, 1.0f, constants.flags.w };
            commandList->setFramebuffer(framebuffer);
            commandList->setPipeline(record.pipeline.get());
            commandList->setGraphicsPipelineLayout(record.pipelineLayout.get());
            commandList->setGraphicsDescriptorSet(descriptorSet->get(), 0);
            commandList->setGraphicsPushConstants(0, &constants);
            commandList->setVertexBuffers(0, nullptr, 0, nullptr);
            commandList->setViewports(RenderViewport(0.0f, 0.0f, float(inputWidth), float(inputHeight)));
            commandList->setScissors(RenderRect(0, 0, inputWidth, inputHeight));
            commandList->drawInstanced(3, 1, 0, 0);
        };

        RenderTextureBarrier velocityBarriers[] = {
            RenderTextureBarrier(input, RenderTextureLayout::SHADER_READ),
            RenderTextureBarrier(depth, RenderTextureLayout::SHADER_READ),
            RenderTextureBarrier(velocityTexture.get(), RenderTextureLayout::COLOR_WRITE)
        };
        commandList->barriers(RenderBarrierStage::GRAPHICS, velocityBarriers, uint32_t(std::size(velocityBarriers)));
        drawPass(shaderLibrary->upscalerVelocity, velocityFramebuffer.get(), false);

        if (!debugView) {
            return input;
        }

        RenderTextureBarrier debugBarriers[] = {
            RenderTextureBarrier(debugTexture.get(), RenderTextureLayout::COLOR_WRITE)
        };
        commandList->barriers(RenderBarrierStage::GRAPHICS, debugBarriers, uint32_t(std::size(debugBarriers)));
        drawPass(shaderLibrary->upscalerVelocityView, debugFramebuffer.get(), true);
        return debugTexture.get();
    }
}
