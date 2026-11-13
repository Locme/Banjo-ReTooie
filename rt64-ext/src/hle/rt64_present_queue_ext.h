//
// RT64
//
// Banjo-Tooie: declarations for the present queue's additions (rt64_present_queue_ext.cpp), and the
// shared state rt64_present_queue.cpp (lib-patches/rt64.patch) uses from there.

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_HLE_RT64_PRESENT_QUEUE_EXT_H
#define RT64_EXT_HLE_RT64_PRESENT_QUEUE_EXT_H

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <functional>
#include <memory>
#include <mutex>
#include <vector>

#include "render/rt64_smaa.h"
#include "render/rt64_fxaa.h"
#include "render/rt64_mirror.h"
#include "render/rt64_gpu_sections.h"
#include "render/rt64_fsr.h"
#include "render/rt64_photo_grade.h"
#include "render/rt64_temporal_upscaler.h"
#include "render/rt64_vi_renderer.h"

namespace RT64 {
    // Screenshots: the next presented frame's game image (before any UI is drawn over it)
    // is read back and handed to the callback as tightly packed 8-bit RGBA rows, on the
    // present thread. Only one request is kept; a newer one replaces it.
    typedef std::function<void(uint32_t width, uint32_t height, std::vector<uint8_t> &&rgba)> ScreenshotCallback;
    void RequestScreenshot(ScreenshotCallback callback);
    // The same for a part of the game image only: x0 to x1 and y0 to y1 as parts of its width and height (0 to 1).
    // Only that part is copied back from the GPU and converted, so it is far quicker than the whole image when the
    // part is small (photo mode's pose cards take one a frame).
    void RequestScreenshotRegion(float x0, float y0, float x1, float y1, ScreenshotCallback callback);
    // The same for the whole window as it is presented: the picture with the menus, the console and notices drawn over
    // it, at the window's size (the console's screenshot ui).
    void RequestWindowScreenshot(ScreenshotCallback callback);
    // A picture the game draws off screen (photo mode's pose cards, src/gameplay/pose_puppets.cpp): while set, the
    // first time each game frame draws a colour image at this RDRAM address, its render target (the size RT64 drew it
    // at, not the N64 size) is copied back and handed to the callback as packed 8-bit RGBA rows with their alpha, on a
    // thread of its own. nativeWidth and nativeHeight are the colour image's N64 size. Address 0 stops it.
    void SetTargetCapture(uint32_t address, uint32_t nativeWidth, uint32_t nativeHeight, ScreenshotCallback callback);

    // Present counts and time since the last call (then reset): presents shown and skipped, time asleep to hold the
    // target rate, in vkQueuePresent, and waiting for the renderer to finish a frame.
    struct PaceStats {
        uint64_t shown = 0, skipped = 0;
        double sleepMs = 0.0, presentCallMs = 0.0, workloadWaitMs = 0.0;
    };
    PaceStats TakePaceStats();

    // Whether the window has a surface to present to (true until told otherwise). An Android app loses its
    // window's surface when it goes to the background: before that, call this with false, and the present
    // thread releases the swap chain and its surface (it waits up to timeoutMs for that). Presents are
    // dropped while there is none. With true, the next present makes the surface and swap chain again.
    void SetWindowSurfaceAvailable(bool available, uint32_t timeoutMs);

    // Frame statistics for the Banjo-Tooie frame rate overlay, taken from the timings RT64
    // already keeps (presentProfiler and rendererGPUProfiler). Each read returns the totals
    // since the last read and starts them again from zero.
    struct FrameStats {
        uint32_t presents = 0;
        double presentMs = 0.0;
        double worstPresentMs = 0.0;
        uint32_t gpuFrames = 0;
        double gpuMs = 0.0;
        // Each present interval in ms, oldest first (at most 4096 kept between reads).
        std::vector<float> intervals;
        // Input latency: from the controller read a game frame was made from to the
        // first present that shows it.
        uint32_t latencyFrames = 0;
        double latencyMs = 0.0;
        double worstLatencyMs = 0.0;
        // Shaders compiled for a new combination of render settings. The ubershader draws
        // while one compiles, so the game keeps going, but more slowly.
        uint32_t shaderCompiles = 0;
        // GPU time of each of the port's extra passes (GpuSection), and how many times each ran.
        double sectionMs[uint32_t(GpuSection::Count)] = {};
        uint32_t sectionCount[uint32_t(GpuSection::Count)] = {};
        // The renderer thread's own time on each game frame it drew (RendererCpuPart), and how many it drew.
        uint32_t cpuFrames = 0;
        double cpuMs[5] = {};
        // Of the renderer thread's time, the deep snow's and tessellated sand's parts (RendererSnowPart).
        double snowMs[4] = {};
        // Of the effects setup (RendererCpuPart::Effects), each part's time (RendererEffectsPart).
        double effectsMs[5] = {};
        // How many times deep snow's or tessellated sand's ground had to be worked out again (not in its cache).
        uint32_t snowRedone = 0;
    };

    FrameStats TakeFrameStats();
    // Turns the per-pass GPU timers (FrameStats::sectionMs) on or off; off by default.
    void SetGpuSectionTiming(bool wanted);
    void RecordGpuFrameTime(double ms);
    // The renderer thread's time on a game frame, by part: going through the game's draws (addFramebuffer), the port's
    // passes set up before them (endFramebuffers), recording the draws, waiting for the GPU to finish them, and after.
    enum class RendererCpuPart : uint32_t { Draws, Effects, Record, GpuWait, After, Count };
    void RecordRendererCpuTimes(const double (&ms)[uint32_t(RendererCpuPart::Count)]);
    // The deep snow's and tessellated sand's CPU work on a game frame: the camera and trail (ComputeSceneSnow), which
    // ground draws take it (snowShellCount), the models pressing it (snowTouchDraw), and its ground's edges.
    enum class RendererSnowPart : uint32_t { Trail, Ground, Touch, Edges, Count };
    void RecordRendererSnowTimes(const double (&ms)[uint32_t(RendererSnowPart::Count)]);
    void RecordRendererSnowRedone(uint32_t count);
    // The effects setup's parts (endFramebuffers): fur normals, snow and sand (whose own parts are
    // RendererSnowPart), the ray traced scene's acceleration structures, the uploads, the shader views.
    enum class RendererEffectsPart : uint32_t { Fur, MaskAndSnow, RtScene, Uploads, Views, Count };
    void RecordRendererEffectsTimes(const double (&ms)[uint32_t(RendererEffectsPart::Count)]);
    void RecordShaderCompiled();
    // The game read the controller at this steady_clock time (ns). The next game frame
    // handed to RT64 takes the latest such time with it.
    void NoteInputRead(int64_t steadyNs);
    int64_t TakeInputRead();

    struct RenderWorker;
    struct RenderTarget;
    struct ShaderLibrary;

    // State shared with rt64_present_queue.cpp, defined in rt64_present_queue_ext.cpp.
    namespace presentext {
        // SetTargetCapture's side in the workload queue (rt64_workload_queue.cpp, lib-patches/rt64.patch), all on its
        // thread: a new game frame is about to be drawn (it may be drawn several times, for frame interpolation; only
        // the first draw is taken); a framebuffer pair was just drawn into colorTarget for the colour image at
        // address (its target in the shader read layout, contentWidth x contentHeight of it drawn), so the copy
        // is recorded when it is the one asked for; the command list has run, so a recorded copy can be read.
        void targetCaptureBeginFrame();
        void targetCaptureRecord(RenderWorker *worker, RenderTarget *colorTarget, uint32_t address, uint32_t contentWidth,
            uint32_t contentHeight, const ShaderLibrary *shaderLibrary);
        void targetCaptureFinish();

        extern std::mutex backlogMutex;
        extern uint64_t presentsQueued;
        // Repainting an open menu while the game sends no frames (SetIdleRepaint).
        extern std::atomic<bool> idleRepaintWanted;
        constexpr auto idleRepaintAfter = std::chrono::milliseconds(100);
        constexpr auto idleRepaintInterval = std::chrono::milliseconds(16);
        void countPresentDone();

        // The window's surface (SetWindowSurfaceAvailable): whether there is one, and whether a swap chain
        // holds a surface made on it. Both under surfaceMutex.
        extern std::mutex surfaceMutex;
        extern std::condition_variable surfaceCondition;
        extern bool surfaceAvailable;
        extern bool surfaceInUse;
        // Called before the swap chain is first made: waits for the window to have a surface and marks it in use.
        void waitForWindowSurface();

        // The present thread's pacing totals since the last TakePaceStats (the game's [pace] log line).
        extern std::atomic<uint64_t> paceShown, paceSkipped, paceSleepNs, paceCallNs, paceWorkloadWaitNs;

        extern std::mutex screenshotMutex;
        extern ScreenshotCallback screenshotCallback;
        // The part of the image the pending screenshot wants (x0, y0, x1, y1), the whole of it unless
        // RequestScreenshotRegion asked for less. Under screenshotMutex.
        extern float screenshotRegion[4];
        struct ScreenshotReadback {
            std::unique_ptr<RenderBuffer> buffer;
            ScreenshotCallback callback;
            RenderFormat format = RenderFormat::UNKNOWN;
            uint32_t width = 0;
            uint32_t height = 0;
            uint32_t rowWidth = 0;
        };
        bool screenshotFormatSupported(RenderFormat format);
        void finishScreenshot(ScreenshotReadback &readback);
        // A pending window screenshot: its callback taken and the swap chain image (everything drawn, in the copy
        // source layout afterwards) copied into out's read-back buffer. Nothing when none is pending.
        void copyWindowScreenshot(RenderDevice *device, RenderCommandList *commandList, RenderTexture *swapChainTexture,
            uint32_t width, uint32_t height, ScreenshotReadback &out);

        extern std::mutex frameStatsMutex;
        extern FrameStats frameStats;
    }
    using namespace presentext;
}

#endif // RT64_EXT_HLE_RT64_PRESENT_QUEUE_EXT_H
