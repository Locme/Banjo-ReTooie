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

#include "rt64_vi.h"

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

        void countPresentDone() {
            {
                std::scoped_lock lock(backlogMutex);
                presentsDone = std::min(presentsDone + 1, presentsQueued);
            }
            backlogCondition.notify_all();
        }
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

        bool screenshotFormatSupported(RenderFormat format) {
            return (format == RenderFormat::R8G8B8A8_UNORM) || (format == RenderFormat::B8G8R8A8_UNORM) || (format == RenderFormat::R16G16B16A16_UNORM);
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
