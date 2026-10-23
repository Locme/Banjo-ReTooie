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

    // Present counts and time since the last call (then reset): presents shown and skipped, time asleep to hold the
    // target rate, in vkQueuePresent, and waiting for the renderer to finish a frame.
    struct PaceStats {
        uint64_t shown = 0, skipped = 0;
        double sleepMs = 0.0, presentCallMs = 0.0, workloadWaitMs = 0.0;
    };
    PaceStats TakePaceStats();

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
        double effectsMs[6] = {};
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
    // The effects setup's parts (endFramebuffers): fur normals, the grass mask with snow and sand (whose own parts are
    // RendererSnowPart), instanced grass, the ray traced scene's acceleration structures, the uploads, the shader views.
    enum class RendererEffectsPart : uint32_t { Fur, MaskAndSnow, Grass, RtScene, Uploads, Views, Count };
    void RecordRendererEffectsTimes(const double (&ms)[uint32_t(RendererEffectsPart::Count)]);
    void RecordShaderCompiled();
    // The game read the controller at this steady_clock time (ns). The next game frame
    // handed to RT64 takes the latest such time with it.
    void NoteInputRead(int64_t steadyNs);
    int64_t TakeInputRead();

    // State shared with rt64_present_queue.cpp, defined in rt64_present_queue_ext.cpp.
    namespace presentext {
        extern std::mutex backlogMutex;
        extern uint64_t presentsQueued;
        // Repainting an open menu while the game sends no frames (SetIdleRepaint).
        extern std::atomic<bool> idleRepaintWanted;
        constexpr auto idleRepaintAfter = std::chrono::milliseconds(100);
        constexpr auto idleRepaintInterval = std::chrono::milliseconds(16);
        void countPresentDone();

        // The present thread's pacing totals since the last TakePaceStats (the game's [pace] log line).
        extern std::atomic<uint64_t> paceShown, paceSkipped, paceSleepNs, paceCallNs, paceWorkloadWaitNs;

        extern std::mutex screenshotMutex;
        extern ScreenshotCallback screenshotCallback;
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

        extern std::mutex frameStatsMutex;
        extern FrameStats frameStats;
    }
    using namespace presentext;
}

#endif // RT64_EXT_HLE_RT64_PRESENT_QUEUE_EXT_H
