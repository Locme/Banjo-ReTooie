//
// RT64
//

#include "rt64_temporal_upscaler.h"

#include <algorithm>
#include <atomic>
#include <cmath>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <mutex>

#include "shared/rt64_temporal_upscaler.h"

#include "rt64_render_target.h"

namespace RT64 {
    namespace {
        std::atomic<uint32_t> upscalerMode{ 0 };
        std::atomic<uint32_t> upscalerQuality{ 0 };

        struct Camera {
            float projection[16] = {};
            float view[16] = {};
            float prevProjection[16] = {};
            float prevView[16] = {};
            float depthScale = 0.5f;
            float depthTranslate = 0.5f;
            uint32_t width = 0;
            uint32_t height = 0;
            bool valid = false;
        };

        std::mutex cameraMutex;
        Camera currentCamera;
        std::atomic<uint32_t> jitterFrame{ 0 };
        // Frames in a row the resolve could not run for; the jitter is off from the third, so a picture the upscaler
        // cannot work on (a menu, a cut) does not wobble. A resolve that runs puts it back.
        std::atomic<uint32_t> unresolvedFrames{ 0 };
        // Whether the camera was set since the last frame took it (a frame with no 3D world leaves it stale).
        std::atomic<bool> cameraFresh{ false };
        std::atomic<uint32_t> renderWidth{ 640 };
        std::atomic<uint32_t> renderHeight{ 480 };
        constexpr uint32_t JitterPhases = 16;

        // The Halton sequence (base b) at index i, in [0, 1).
        float halton(uint32_t i, uint32_t b) {
            float f = 1.0f, r = 0.0f;
            while (i > 0) {
                f /= float(b);
                r += f * float(i % b);
                i /= b;
            }
            return r;
        }

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

        // The projection with its jitter taken out (the jitter sits in row 2, columns 0 and 1, of a perspective
        // projection with row vectors; see UpscalerJitterNdc), and the jitter itself in pixels (x right, y down).
        void removeJitter(const float m[16], bool rowVector, uint32_t width, uint32_t height, float out[16], float &jitterX, float &jitterY) {
            std::copy(m, m + 16, out);
            // Row-vector form: clip.xy gains z * m[2][0..1], and w = -z, so the picture shifts by -m[2][0..1] in clip space.
            const int a = rowVector ? (2 * 4 + 0) : (0 * 4 + 2);
            const int b = rowVector ? (2 * 4 + 1) : (1 * 4 + 2);
            const float shiftX = -out[a];
            const float shiftY = -out[b];
            jitterX = shiftX * float(width) * 0.5f;
            jitterY = -shiftY * float(height) * 0.5f;
            out[a] = 0.0f;
            out[b] = 0.0f;
        }

        // Works out, for the current camera, the matrix taking a view-space position to the previous camera's clip
        // space, the depth terms and the jitter of both frames. False when the projection is not a perspective one.
        bool reprojection(const Camera &cur, float out[16], interop::float4 &depthTerms, float &projX, float &projY, float jitter[4]) {
            if (!cur.valid || (cur.width == 0) || (cur.height == 0)) {
                return false;
            }
            const float (&cm)[16] = cur.projection;
            if ((std::abs(cm[2 * 4 + 3] + 1.0f) > 0.01f) && (std::abs(cm[3 * 4 + 2] + 1.0f) > 0.01f)) {
                return false;
            }
            const bool curRow = rowVectorProjection(cur.projection);
            const bool prevRow = rowVectorProjection(cur.prevProjection);
            float curProj[16], prevProj[16];
            removeJitter(cur.projection, curRow, cur.width, cur.height, curProj, jitter[0], jitter[1]);
            removeJitter(cur.prevProjection, prevRow, cur.width, cur.height, prevProj, jitter[2], jitter[3]);

            float curView[16], prevView[16], prevProjRow[16];
            rowVectorForm(cur.view, curRow, curView);
            rowVectorForm(cur.prevView, prevRow, prevView);
            rowVectorForm(prevProj, prevRow, prevProjRow);
            float curViewInverse[16];
            if (!invert(curView, curViewInverse)) {
                return false;
            }
            // view(cur) -> world -> view(prev) -> clip(prev).
            float step[16], full[16];
            multiply(curViewInverse, prevView, step);
            multiply(step, prevProjRow, full);
            std::copy(full, full + 16, out);

            // The projection's depth terms, folded with the viewport's depth range as the scene effects do.
            interop::float4 t = curRow ? interop::float4{ curProj[2 * 4 + 2], curProj[3 * 4 + 2], curProj[2 * 4 + 3], curProj[3 * 4 + 3] } :
                interop::float4{ curProj[2 * 4 + 2], curProj[2 * 4 + 3], curProj[3 * 4 + 2], curProj[3 * 4 + 3] };
            if (std::abs(cur.depthScale) >= 1e-6f) {
                const float a = 0.5f / cur.depthScale;
                const float b = (0.5f - cur.depthTranslate) / cur.depthScale;
                t = interop::float4{ t.x - b * t.z, t.y - b * t.w, a * t.z, a * t.w };
            }
            depthTerms = t;
            projX = curProj[0];
            projY = curProj[5];
            return true;
        }
    }

    void SetUpscalerMode(uint32_t mode) {
        upscalerMode = std::min(mode, 8U);
    }

    uint32_t GetUpscalerMode() {
        return upscalerMode.load();
    }

    void SetUpscalerQuality(uint32_t quality) {
        upscalerQuality = std::min(quality, 3U);
    }

    float UpscalerRenderFraction() {
        // Only the built-in resolve (8) enlarges so far; the other choices have no backend yet and must not render small.
        // (Off, FSR 4 native AA and DLAA will always keep the window's size.)
        if (upscalerMode.load() != 8) {
            return 1.0f;
        }
        static const float fractions[4] = { 0.667f, 0.58f, 0.5f, 0.333f };
        return fractions[upscalerQuality.load()];
    }

    bool UpscalerWanted() {
        return upscalerMode.load() == 8;
    }

    bool UpscalerJitterActive() {
        return (upscalerMode.load() == 8) && (unresolvedFrames.load() < 3);
    }

    void UpscalerNextFrame() {
        jitterFrame++;
    }

    void UpscalerJitterNdc(uint32_t framesBack, float &x, float &y) {
        x = 0.0f;
        y = 0.0f;
        if (!UpscalerJitterActive()) {
            return;
        }
        const uint32_t index = (jitterFrame.load() - framesBack) % JitterPhases + 1;
        // In pixels, -0.5 to 0.5 (x right, y down); the picture then shifts by that much, in clip space 2 / size a pixel.
        const float pixelX = halton(index, 2) - 0.5f;
        const float pixelY = halton(index, 3) - 0.5f;
        x = pixelX * 2.0f / float(renderWidth.load());
        y = -pixelY * 2.0f / float(renderHeight.load());
    }

    void SetUpscalerCamera(const float projection[16], const float view[16], const float prevProjection[16], const float prevView[16],
        float depthScale, float depthTranslate, uint32_t width, uint32_t height)
    {
        if (upscalerMode.load() == 0) {
            return;
        }
        renderWidth = std::max(width, 1U);
        renderHeight = std::max(height, 1U);
        const std::scoped_lock lock(cameraMutex);
        std::copy(projection, projection + 16, currentCamera.projection);
        std::copy(view, view + 16, currentCamera.view);
        std::copy(prevProjection, prevProjection + 16, currentCamera.prevProjection);
        std::copy(prevView, prevView + 16, currentCamera.prevView);
        currentCamera.depthScale = depthScale;
        currentCamera.depthTranslate = depthTranslate;
        currentCamera.width = width;
        currentCamera.height = height;
        currentCamera.valid = true;
        cameraFresh = true;
    }

    namespace {
        // One line to the console every few seconds while an upscaler is on, for finding what went wrong in a test.
        void logUpscaler(const char *what, uint32_t mode, uint32_t inW, uint32_t inH, uint32_t outW, uint32_t outH, bool motionKnown,
            const float jitter[4], uint32_t resets, bool debugView)
        {
            static auto lastLog = std::chrono::steady_clock::now() - std::chrono::seconds(10);
            const auto now = std::chrono::steady_clock::now();
            if (now - lastLog < std::chrono::seconds(5)) {
                return;
            }
            lastLog = now;
            fprintf(stdout, "[upscaler] %s mode %u render %ux%u output %ux%u motion %s jitter %.3f %.3f (previous %.3f %.3f) history resets %u velocity view %s\n",
                what, mode, inW, inH, outW, outH, motionKnown ? "known" : "unknown", jitter[0], jitter[1], jitter[2], jitter[3], resets, debugView ? "on" : "off");
            fflush(stdout);
        }
    }

    RenderTexture *UpscalerRenderer::velocity(RenderDevice *device, RenderCommandList *commandList, const ShaderLibrary *shaderLibrary,
        RenderTexture *input, RenderFormat format, uint32_t inputWidth, uint32_t inputHeight, RenderTexture *depth)
    {
        velocityValid = false;
        debugShown = false;
        if ((GetUpscalerMode() == 0) || (input == nullptr) || (depth == nullptr) || (inputWidth == 0) || (inputHeight == 0) ||
            (format != RenderTarget::colorBufferFormat(shaderLibrary->usesHDR)))
        {
            return input;
        }

        interop::UpscalerVelocityCB constants;
        float reproject[16];
        float jitter[4] = {};
        bool motionKnown;
        {
            const std::scoped_lock lock(cameraMutex);
            float projX = 1.0f, projY = 1.0f;
            // A camera nobody set for this frame (no 3D world in it) is stale: no motion.
            const bool fresh = cameraFresh.exchange(false);
            motionKnown = fresh && reprojection(currentCamera, reproject, constants.depthTerms, projX, projY, jitter);
            constants.flags.w = motionKnown ? 0.0f : 1.0f;
            if (!motionKnown) {
                // No motion known: no velocity.
                std::fill(reproject, reproject + 16, 0.0f);
                reproject[0] = reproject[5] = reproject[10] = reproject[15] = 1.0f;
                constants.depthTerms = { 1.0f, 0.0f, 0.0f, 1.0f };
            }
            constants.projection = { projX, projY, float(inputWidth), float(inputHeight) };
        }
        constants.reproject0 = { reproject[0], reproject[1], reproject[2], reproject[3] };
        constants.reproject1 = { reproject[4], reproject[5], reproject[6], reproject[7] };
        constants.reproject2 = { reproject[8], reproject[9], reproject[10], reproject[11] };
        constants.reproject3 = { reproject[12], reproject[13], reproject[14], reproject[15] };
        currentJitter[0] = jitter[0];
        currentJitter[1] = jitter[1];
        motionWasKnown = motionKnown;

        static const char *viewEnv = std::getenv("TOOIE_VELOCITY_VIEW");
        const bool debugView = (viewEnv != nullptr) && (viewEnv[0] != '0');
        const float debugScale = (viewEnv != nullptr) && (viewEnv[0] == '2') ? 4.0f : 16.0f;
        logUpscaler("velocity", GetUpscalerMode(), inputWidth, inputHeight, lastOutputWidth, lastOutputHeight, motionKnown, jitter, historyResets, debugView);

        if ((this->width != inputWidth) || (this->height != inputHeight) || (velocityTexture == nullptr)) {
            velocityFramebuffer.reset();
            debugFramebuffer.reset();
            velocityTexture = device->createTexture(RenderTextureDesc::ColorTarget(inputWidth, inputHeight, RenderFormat::R16G16_FLOAT));
            velocityTexture->setName("Upscaler Velocity");
            debugTexture = device->createTexture(RenderTextureDesc::ColorTarget(inputWidth, inputHeight, format));
            debugTexture->setName("Upscaler Velocity View");
            const RenderTexture *velocityTex = velocityTexture.get();
            const RenderTexture *debug = debugTexture.get();
            velocityFramebuffer = device->createFramebuffer(RenderFramebufferDesc(&velocityTex, 1));
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
        velocityValid = true;

        if (!debugView) {
            return input;
        }

        RenderTextureBarrier debugBarriers[] = {
            RenderTextureBarrier(debugTexture.get(), RenderTextureLayout::COLOR_WRITE)
        };
        commandList->barriers(RenderBarrierStage::GRAPHICS, debugBarriers, uint32_t(std::size(debugBarriers)));
        drawPass(shaderLibrary->upscalerVelocityView, debugFramebuffer.get(), true);
        debugShown = true;
        return debugTexture.get();
    }

    RenderTexture *UpscalerRenderer::resolve(RenderDevice *device, RenderCommandList *commandList, const ShaderLibrary *shaderLibrary,
        RenderTexture *input, RenderFormat format, uint32_t inputWidth, uint32_t inputHeight, uint32_t outputWidth, uint32_t outputHeight)
    {
        // Without a known camera motion the picture is not a 3D world (a menu, a cut): left as it is, with no blur.
        if (!UpscalerWanted() || !velocityValid || debugShown || !motionWasKnown || (input == nullptr) || (inputWidth != width) || (inputHeight != height) ||
            (format != RenderTarget::colorBufferFormat(shaderLibrary->usesHDR)) || (outputWidth < inputWidth) || (outputHeight < inputHeight))
        {
            historyValid = false;
            unresolvedFrames++;
            return input;
        }

        bool reset = !historyValid;
        if ((outputWidth != lastOutputWidth) || (outputHeight != lastOutputHeight) || (resolved[0] == nullptr)) {
            for (int i = 0; i < 2; i++) {
                resolvedFramebuffer[i].reset();
                resolved[i] = device->createTexture(RenderTextureDesc::ColorTarget(outputWidth, outputHeight, format));
                resolved[i]->setName(i == 0 ? "Upscaler Resolve A" : "Upscaler Resolve B");
                const RenderTexture *tex = resolved[i].get();
                resolvedFramebuffer[i] = device->createFramebuffer(RenderFramebufferDesc(&tex, 1));
            }
            lastOutputWidth = outputWidth;
            lastOutputHeight = outputHeight;
            reset = true;
        }

        if (resolveDescriptorSet == nullptr) {
            resolveDescriptorSet = std::make_unique<SmaaDescriptorSet>(shaderLibrary->samplerLibrary.linear.clampClamp.get(),
                shaderLibrary->samplerLibrary.nearest.clampClamp.get(), device);
        }

        // Written to one of the two textures; the other holds the last frame's result.
        const uint32_t target = writeIndex;
        const uint32_t source = 1 - writeIndex;
        resolveDescriptorSet->setTexture(resolveDescriptorSet->gTexture0, input, RenderTextureLayout::SHADER_READ);
        resolveDescriptorSet->setTexture(resolveDescriptorSet->gTexture1, velocityTexture.get(), RenderTextureLayout::SHADER_READ);
        resolveDescriptorSet->setTexture(resolveDescriptorSet->gTexture2, resolved[source].get(), RenderTextureLayout::SHADER_READ);

        interop::UpscalerResolveCB constants;
        constants.sizes = { float(inputWidth), float(inputHeight), float(outputWidth), float(outputHeight) };
        constants.jitter = { currentJitter[0], currentJitter[1], reset ? 0.0f : 1.0f, 0.1f };

        RenderTextureBarrier barriers[] = {
            RenderTextureBarrier(input, RenderTextureLayout::SHADER_READ),
            RenderTextureBarrier(velocityTexture.get(), RenderTextureLayout::SHADER_READ),
            RenderTextureBarrier(resolved[source].get(), RenderTextureLayout::SHADER_READ),
            RenderTextureBarrier(resolved[target].get(), RenderTextureLayout::COLOR_WRITE)
        };
        commandList->barriers(RenderBarrierStage::GRAPHICS, barriers, uint32_t(std::size(barriers)));
        commandList->setFramebuffer(resolvedFramebuffer[target].get());
        commandList->setPipeline(shaderLibrary->upscalerResolve.pipeline.get());
        commandList->setGraphicsPipelineLayout(shaderLibrary->upscalerResolve.pipelineLayout.get());
        commandList->setGraphicsDescriptorSet(resolveDescriptorSet->get(), 0);
        commandList->setGraphicsPushConstants(0, &constants);
        commandList->setVertexBuffers(0, nullptr, 0, nullptr);
        commandList->setViewports(RenderViewport(0.0f, 0.0f, float(outputWidth), float(outputHeight)));
        commandList->setScissors(RenderRect(0, 0, outputWidth, outputHeight));
        commandList->drawInstanced(3, 1, 0, 0);

        if (reset) {
            historyResets++;
        }
        historyValid = true;
        unresolvedFrames = 0;
        writeIndex = source;
        float jitterLog[4] = { currentJitter[0], currentJitter[1], 0.0f, 0.0f };
        logUpscaler("resolve", GetUpscalerMode(), inputWidth, inputHeight, outputWidth, outputHeight, motionWasKnown, jitterLog, historyResets, false);
        return resolved[target].get();
    }
}
