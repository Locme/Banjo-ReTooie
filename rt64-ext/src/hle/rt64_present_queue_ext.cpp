//
// RT64
//
// Banjo-Tooie: the present queue's additions that need none of its internals: the present backlog
// (WaitForPresentBacklog), repainting an open menu, screenshots, frame statistics and input latency,
// and PresentQueue::threadRepaint. rt64_present_queue.cpp (lib-patches/rt64.patch) uses the shared
// state through rt64_present_queue_ext.h.

#include "rt64_present_queue.h"

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <thread>

#include "rt64_vi.h"
#include "render/rt64_render_target.h"
#include "render/rt64_render_worker.h"

namespace RT64 {
    namespace presentext {
        // Banjo-Tooie: presents queued and presents shown or skipped, for WaitForPresentBacklog.
        std::mutex backlogMutex;
        std::condition_variable backlogCondition;
        uint64_t presentsQueued = 0;
        uint64_t presentsDone = 0;

        // Banjo-Tooie: the frontend's UI (the Esc menu) is drawn, and reads its input, only when a frame is
        // presented, and frames are only presented when the game sends one. While the game sends none (a
        // map change, a load, a long stall) an open menu froze and ignored every button. While a menu is
        // open (SetIdleRepaint), the last frame is drawn again with the menu over it whenever the game has
        // sent nothing for idleRepaintAfter, every idleRepaintInterval.
        std::atomic<bool> idleRepaintWanted = false;

        std::atomic<uint64_t> paceShown{ 0 }, paceSkipped{ 0 }, paceSleepNs{ 0 }, paceCallNs{ 0 }, paceWorkloadWaitNs{ 0 };

        void countPresentDone() {
            {
                std::scoped_lock lock(backlogMutex);
                presentsDone = std::min(presentsDone + 1, presentsQueued);
            }
            backlogCondition.notify_all();
        }
    }

    PaceStats TakePaceStats() {
        PaceStats stats;
        stats.shown = presentext::paceShown.exchange(0);
        stats.skipped = presentext::paceSkipped.exchange(0);
        stats.sleepMs = double(presentext::paceSleepNs.exchange(0)) / 1e6;
        stats.presentCallMs = double(presentext::paceCallNs.exchange(0)) / 1e6;
        stats.workloadWaitMs = double(presentext::paceWorkloadWaitNs.exchange(0)) / 1e6;
        return stats;
    }

    void SetIdleRepaint(bool enabled) {
        idleRepaintWanted = enabled;
    }

    bool WaitForPresentBacklog(uint32_t maxBacklog, uint32_t timeoutMs) {
        std::unique_lock lock(backlogMutex);
        return backlogCondition.wait_for(lock, std::chrono::milliseconds(timeoutMs), [&]() {
            return (presentsQueued - presentsDone) <= maxBacklog;
        });
    }

    namespace presentext {
        std::mutex screenshotMutex;
        ScreenshotCallback screenshotCallback;
        float screenshotRegion[4] = { 0.0f, 0.0f, 1.0f, 1.0f };

        bool screenshotFormatSupported(RenderFormat format) {
            return (format == RenderFormat::R8G8B8A8_UNORM) || (format == RenderFormat::B8G8R8A8_UNORM) || (format == RenderFormat::R16G16B16A16_UNORM);
        }

        std::mutex windowShotMutex;
        ScreenshotCallback windowShotCallback;

        void copyWindowScreenshot(RenderDevice *device, RenderCommandList *commandList, RenderTexture *swapChainTexture,
            uint32_t width, uint32_t height, ScreenshotReadback &out) {
            {
                const std::scoped_lock lock(windowShotMutex);
                if (!windowShotCallback || (swapChainTexture == nullptr) || (width == 0) || (height == 0)) {
                    return;
                }
                out.callback = std::move(windowShotCallback);
                windowShotCallback = nullptr;
            }
            // The swap chain is B8G8R8A8 (rt64_application.cpp). Rows padded to 256 bytes, as D3D12 requires.
            out.format = RenderFormat::B8G8R8A8_UNORM;
            out.width = width;
            out.height = height;
            const uint32_t rowBytes = ((width * 4) + 255) & ~255U;
            out.rowWidth = rowBytes / 4;
            out.buffer = device->createBuffer(RenderBufferDesc::ReadbackBuffer(uint64_t(rowBytes) * height));
            commandList->barriers(RenderBarrierStage::COPY, RenderTextureBarrier(swapChainTexture, RenderTextureLayout::COPY_SOURCE));
            commandList->copyTextureRegion(
                RenderTextureCopyLocation::PlacedFootprint(out.buffer.get(), out.format, width, height, 1, out.rowWidth),
                RenderTextureCopyLocation::Subresource(swapChainTexture));
        }

        // Converts the read-back rows to packed RGBA8 and calls the callback.
        void finishScreenshot(ScreenshotReadback &readback) {
            const uint32_t texelSize = RenderFormatSize(readback.format);
            const uint8_t *src = reinterpret_cast<const uint8_t *>(readback.buffer->map());
            std::vector<uint8_t> rgba(size_t(readback.width) * readback.height * 4);
            for (uint32_t y = 0; y < readback.height; y++) {
                const uint8_t *row = src + size_t(y) * readback.rowWidth * texelSize;
                uint8_t *out = rgba.data() + size_t(y) * readback.width * 4;
                for (uint32_t x = 0; x < readback.width; x++) {
                    const uint8_t *texel = row + size_t(x) * texelSize;
                    if (readback.format == RenderFormat::R16G16B16A16_UNORM) {
                        const uint16_t *wide = reinterpret_cast<const uint16_t *>(texel);
                        out[x * 4 + 0] = uint8_t(wide[0] >> 8);
                        out[x * 4 + 1] = uint8_t(wide[1] >> 8);
                        out[x * 4 + 2] = uint8_t(wide[2] >> 8);
                    }
                    else if (readback.format == RenderFormat::B8G8R8A8_UNORM) {
                        out[x * 4 + 0] = texel[2];
                        out[x * 4 + 1] = texel[1];
                        out[x * 4 + 2] = texel[0];
                    }
                    else {
                        out[x * 4 + 0] = texel[0];
                        out[x * 4 + 1] = texel[1];
                        out[x * 4 + 2] = texel[2];
                    }

                    out[x * 4 + 3] = 0xFF;
                }
            }

            readback.buffer->unmap();
            readback.callback(readback.width, readback.height, std::move(rgba));
        }
    }

    namespace presentext {
        std::mutex frameStatsMutex;
        FrameStats frameStats;
    }

    FrameStats TakeFrameStats() {
        const std::scoped_lock lock(frameStatsMutex);
        FrameStats taken = std::move(frameStats);
        frameStats = FrameStats();
        return taken;
    }

    namespace {
        std::atomic<int64_t> pendingInputNs{0};
    }

    void NoteInputRead(int64_t steadyNs) {
        pendingInputNs.store(steadyNs, std::memory_order_relaxed);
    }

    int64_t TakeInputRead() {
        return pendingInputNs.exchange(0, std::memory_order_relaxed);
    }

    void RecordGpuFrameTime(double ms) {
        const std::scoped_lock lock(frameStatsMutex);
        frameStats.gpuFrames++;
        frameStats.gpuMs += ms;
    }

    void RecordRendererCpuTimes(const double (&ms)[uint32_t(RendererCpuPart::Count)]) {
        const std::scoped_lock lock(frameStatsMutex);
        frameStats.cpuFrames++;
        for (uint32_t i = 0; i < uint32_t(RendererCpuPart::Count); i++) {
            frameStats.cpuMs[i] += ms[i];
        }
    }

    void RecordRendererSnowTimes(const double (&ms)[uint32_t(RendererSnowPart::Count)]) {
        const std::scoped_lock lock(frameStatsMutex);
        for (uint32_t i = 0; i < uint32_t(RendererSnowPart::Count); i++) {
            frameStats.snowMs[i] += ms[i];
        }
    }

    void RecordRendererSnowRedone(uint32_t count) {
        const std::scoped_lock lock(frameStatsMutex);
        frameStats.snowRedone += count;
    }

    void RecordRendererEffectsTimes(const double (&ms)[uint32_t(RendererEffectsPart::Count)]) {
        const std::scoped_lock lock(frameStatsMutex);
        for (uint32_t i = 0; i < uint32_t(RendererEffectsPart::Count); i++) {
            frameStats.effectsMs[i] += ms[i];
        }
    }

    void RecordGpuSectionTime(GpuSection section, double ms) {
        const std::scoped_lock lock(frameStatsMutex);
        frameStats.sectionMs[uint32_t(section)] += ms;
        frameStats.sectionCount[uint32_t(section)]++;
    }

    namespace {
        std::atomic<bool> gpuSectionTiming{false};
    }

    void SetGpuSectionTiming(bool wanted) {
        gpuSectionTiming.store(wanted, std::memory_order_relaxed);
    }

    bool GpuSectionTimingWanted() {
        return gpuSectionTiming.load(std::memory_order_relaxed);
    }

    GpuSectionTimer &WorkloadGpuSections() {
        static GpuSectionTimer timer;
        return timer;
    }

    void RecordShaderCompiled() {
        const std::scoped_lock lock(frameStatsMutex);
        frameStats.shaderCompiles++;
    }

    void RequestScreenshot(ScreenshotCallback callback) {
        const std::scoped_lock lock(screenshotMutex);
        screenshotCallback = std::move(callback);
        screenshotRegion[0] = 0.0f;
        screenshotRegion[1] = 0.0f;
        screenshotRegion[2] = 1.0f;
        screenshotRegion[3] = 1.0f;
    }

    void RequestScreenshotRegion(float x0, float y0, float x1, float y1, ScreenshotCallback callback) {
        const std::scoped_lock lock(screenshotMutex);
        screenshotCallback = std::move(callback);
        screenshotRegion[0] = std::clamp(std::min(x0, x1), 0.0f, 1.0f);
        screenshotRegion[1] = std::clamp(std::min(y0, y1), 0.0f, 1.0f);
        screenshotRegion[2] = std::clamp(std::max(x0, x1), 0.0f, 1.0f);
        screenshotRegion[3] = std::clamp(std::max(y0, y1), 0.0f, 1.0f);
    }

    void RequestWindowScreenshot(ScreenshotCallback callback) {
        const std::scoped_lock lock(windowShotMutex);
        windowShotCallback = std::move(callback);
    }

    namespace presentext {
        std::mutex surfaceMutex;
        std::condition_variable surfaceCondition;
        bool surfaceAvailable = true;
        bool surfaceInUse = false;

        void waitForWindowSurface() {
            std::unique_lock lock(surfaceMutex);
            surfaceCondition.wait(lock, []() { return surfaceAvailable; });
            surfaceInUse = true;
        }
    }

    void SetWindowSurfaceAvailable(bool available, uint32_t timeoutMs) {
        std::unique_lock lock(surfaceMutex);
        surfaceAvailable = available;
        surfaceCondition.notify_all();
        if (!available) {
            // The present thread looks at this at least every idleRepaintInterval, between presents.
            if (!surfaceCondition.wait_for(lock, std::chrono::milliseconds(timeoutMs), []() { return !surfaceInUse; })) {
                fprintf(stderr, "[present] The swap chain was not released within %u ms of the window losing its surface.\n", timeoutMs);
            }
        }
    }

    // Banjo-Tooie: called by the present thread between presents. Releases the swap chain and its surface when
    // the window has lost its surface (SetWindowSurfaceAvailable), and lets the next present make them again once
    // it has one. Returns whether the swap chain can be used.
    bool PresentQueue::threadSyncSurface(bool &swapChainValid) {
        std::unique_lock lock(surfaceMutex);
        if (!surfaceAvailable && surfaceInUse) {
            lock.unlock();
            {
                std::unique_lock<std::mutex> threadLock(threadMutex);
                // Everything already sent to the queue (the last presents' draws) finishes first, as before a resize.
                ext.presentGraphicsWorker->commandList->begin();
                ext.presentGraphicsWorker->commandList->end();
                ext.presentGraphicsWorker->execute();
                ext.presentGraphicsWorker->wait();
                swapChainFramebuffers.clear();
                ext.swapChain->releaseSurface();
                swapChainValid = false;
            }
            fprintf(stdout, "[present] The window lost its surface; the swap chain is released.\n");
            lock.lock();
            surfaceInUse = false;
            surfaceCondition.notify_all();
        }
        else if (surfaceAvailable && !surfaceInUse) {
            // The next present resizes the swap chain, which makes the surface again.
            surfaceInUse = true;
            swapChainValid = false;
            fprintf(stdout, "[present] The window has a surface again; the swap chain is made on it.\n");
        }

        return surfaceInUse;
    }

    void PresentQueue::threadRepaint(bool &swapChainValid) {
        if (!swapChainValid || ext.swapChain->isEmpty() || ext.swapChain->needsResize()) {
            return;
        }

        repainting = true;
        threadPresent(lastPresent, swapChainValid);
        repainting = false;
    }
}

// Banjo-Tooie: SetTargetCapture, a picture the game draws off screen copied back from its render target (photo mode's
// pose cards). The copy is recorded in the workload queue's own command list right after the framebuffer pair that
// drew it, and read once that list has run, all on the workload queue's thread, so it never meets the GPU drawing
// into the same target. Turning the rows into RGBA8 and the callback run on a thread of their own.
namespace RT64 {
    namespace presentext {
        std::mutex captureMutex;
        uint32_t captureAddress = 0;
        uint32_t captureNativeWidth = 0;
        uint32_t captureNativeHeight = 0;
        ScreenshotCallback captureCallback;

        // The workload queue's thread only.
        bool captureArmed = false;
        std::unique_ptr<RenderBuffer> captureBuffer;
        uint64_t captureBufferSize = 0;
        struct CaptureRecorded {
            bool recorded = false;
            RenderFormat format = RenderFormat::UNKNOWN;
            uint32_t width = 0;
            uint32_t height = 0;
            uint32_t rowWidth = 0;
            ScreenshotCallback callback;
        } captureRecorded;

        void targetCaptureBeginFrame() {
            captureArmed = true;
        }

        void targetCaptureRecord(RenderWorker *worker, RenderTarget *colorTarget, uint32_t address, uint32_t contentWidth,
            uint32_t contentHeight, const ShaderLibrary *shaderLibrary)
        {
            // A picture can take several framebuffer pairs (its clear, then the draws once the depth image is set): each
            // one at the address copies it again, over the last, so what is read is the picture as the frame left it.
            if (!captureArmed || (colorTarget == nullptr)) {
                return;
            }

            ScreenshotCallback callback;
            {
                const std::scoped_lock lock(captureMutex);
                // TOOIE_PUPPET_LOG=1: the colour images drawn while a capture is wanted.
                static const bool log = std::getenv("TOOIE_PUPPET_LOG") != nullptr;
                if (log && (captureAddress != 0)) {
                    fprintf(stderr, "[capture] colour image %06X (%ux%u drawn), want %06X\n", address, contentWidth, contentHeight, captureAddress);
                }
                if ((captureAddress == 0) || (address != captureAddress) || !captureCallback) {
                    return;
                }

                callback = captureCallback;
            }

            RenderTexture *texture = colorTarget->texture.get();
            if (colorTarget->usesResolve()) {
                colorTarget->resolveTarget(worker, shaderLibrary);
                texture = colorTarget->getResolvedTexture();
            }

            const uint32_t width = std::min(contentWidth, colorTarget->width);
            const uint32_t height = std::min(contentHeight, colorTarget->height);
            if ((texture == nullptr) || (width == 0) || (height == 0) || !screenshotFormatSupported(colorTarget->format)) {
                return;
            }

            // Rows padded to 256 bytes, as D3D12 requires.
            const uint32_t texelSize = RenderFormatSize(colorTarget->format);
            const uint32_t rowBytes = ((width * texelSize) + 255) & ~255U;
            const uint64_t bufferSize = uint64_t(rowBytes) * height;
            if (!captureBuffer || (captureBufferSize < bufferSize)) {
                captureBuffer = worker->device->createBuffer(RenderBufferDesc::ReadbackBuffer(bufferSize));
                captureBufferSize = bufferSize;
            }

            RenderCommandList *commandList = worker->commandList.get();
            commandList->barriers(RenderBarrierStage::COPY, RenderTextureBarrier(texture, RenderTextureLayout::COPY_SOURCE));
            const RenderBox box(0, 0, int32_t(width), int32_t(height));
            commandList->copyTextureRegion(
                RenderTextureCopyLocation::PlacedFootprint(captureBuffer.get(), colorTarget->format, width, height, 1, rowBytes / texelSize),
                RenderTextureCopyLocation::Subresource(texture), 0, 0, 0, &box);
            commandList->barriers(RenderBarrierStage::GRAPHICS, RenderTextureBarrier(texture, RenderTextureLayout::SHADER_READ));
            captureRecorded.recorded = true;
            captureRecorded.format = colorTarget->format;
            captureRecorded.width = width;
            captureRecorded.height = height;
            captureRecorded.rowWidth = rowBytes / texelSize;
            captureRecorded.callback = std::move(callback);
        }

        void targetCaptureFinish() {
            if (!captureRecorded.recorded) {
                return;
            }

            // Only the first draw of a game frame is taken (the others are its frame interpolation).
            captureArmed = false;

            CaptureRecorded taken = std::move(captureRecorded);
            captureRecorded = CaptureRecorded();
            const uint32_t texelSize = RenderFormatSize(taken.format);
            const size_t rowBytes = size_t(taken.rowWidth) * texelSize;
            std::vector<uint8_t> raw(rowBytes * taken.height);
            const uint8_t *mapped = reinterpret_cast<const uint8_t *>(captureBuffer->map());
            if (mapped != nullptr) {
                std::memcpy(raw.data(), mapped, raw.size());
            }

            captureBuffer->unmap();
            if (mapped == nullptr) {
                return;
            }

            std::thread([taken = std::move(taken), raw = std::move(raw), texelSize]() mutable {
                std::vector<uint8_t> rgba(size_t(taken.width) * taken.height * 4);
                for (uint32_t y = 0; y < taken.height; y++) {
                    const uint8_t *row = raw.data() + size_t(y) * taken.rowWidth * texelSize;
                    uint8_t *out = rgba.data() + size_t(y) * taken.width * 4;
                    for (uint32_t x = 0; x < taken.width; x++) {
                        const uint8_t *texel = row + size_t(x) * texelSize;
                        if (taken.format == RenderFormat::R16G16B16A16_UNORM) {
                            const uint16_t *wide = reinterpret_cast<const uint16_t *>(texel);
                            for (int c = 0; c < 4; c++) {
                                out[x * 4 + c] = uint8_t(wide[c] >> 8);
                            }
                        }
                        else if (taken.format == RenderFormat::B8G8R8A8_UNORM) {
                            out[x * 4 + 0] = texel[2];
                            out[x * 4 + 1] = texel[1];
                            out[x * 4 + 2] = texel[0];
                            out[x * 4 + 3] = texel[3];
                        }
                        else {
                            std::memcpy(&out[x * 4], texel, 4);
                        }
                    }
                }

                taken.callback(taken.width, taken.height, std::move(rgba));
            }).detach();
        }
    }

    void SetTargetCapture(uint32_t address, uint32_t nativeWidth, uint32_t nativeHeight, ScreenshotCallback callback) {
        const std::scoped_lock lock(presentext::captureMutex);
        // RT64 keeps framebuffers by their address in the N64's 16 MB (RDP_ADDRESS_MASK).
        presentext::captureAddress = address & 0xFFFFFF;
        presentext::captureNativeWidth = nativeWidth;
        presentext::captureNativeHeight = nativeHeight;
        presentext::captureCallback = (address != 0) ? std::move(callback) : ScreenshotCallback();
    }
}
