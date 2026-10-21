//
// RT64
//

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_RENDER_RT64_GPU_SECTIONS_H
#define RT64_EXT_RENDER_RT64_GPU_SECTIONS_H

#include <iterator>
#include <memory>
#include <utility>
#include <vector>

#include "rt64_shader_library.h"

namespace RT64 {
    // Banjo-Tooie: the GPU time of each of the port's extra passes, for the frame rate overlay
    // (lib/rt64 FrameStats::sectionMs). Each pass is bracketed by two timestamps in the command
    // list that records it; once that command list has finished, collect() adds the times up.
    enum class GpuSection : uint32_t {
        WaterMask,
        EyeAdaptation,
        Bloom,
        SceneEffects,
        Smaa,
        Fxaa,
        PhotoFilters,
        Fsr,
        Output,
        Interface,
        // Added after the first ten so the overlay's copy of the list keeps its order. All four are
        // in the workload command list, once per game frame.
        SunShadowMap,
        RayTracingBuild,
        IndirectLight,
        TracedEffects,
        Count
    };

    void RecordGpuSectionTime(GpuSection section, double ms);

    // Whether anything reads the section times (the overlay in Full, a benchmark or TOOIE_FRAME_LOG).
    // While nothing does, the timers write no timestamps and read nothing back (SetGpuSectionTiming).
    bool GpuSectionTimingWanted();

    struct GpuSectionTimer {
        static constexpr uint32_t Capacity = 32;
        std::unique_ptr<RenderQueryPool> pool;
        struct Span {
            GpuSection section;
            uint32_t first;
            bool counted;
        };
        std::vector<Span> spans;
        RenderCommandList *commandList = nullptr;

        // Call with the command list open, outside any render pass.
        void begin(RenderDevice *device, RenderCommandList *list) {
            spans.clear();
            if (!GpuSectionTimingWanted()) {
                commandList = nullptr;
                return;
            }
            if (pool == nullptr) {
                pool = device->createQueryPool(Capacity);
            }
            commandList = list;
            commandList->resetQueryPool(pool.get(), 0, Capacity);
        }

        // Returns the span to pass to end(), or -1 when the pool is full, or when the pass is being
        // recorded into some other command list than the one begin() was given.
        int start(GpuSection section, const RenderCommandList *list) {
            if ((commandList == nullptr) || (list != commandList) || ((spans.size() + 1) * 2 > Capacity)) {
                return -1;
            }
            const uint32_t first = uint32_t(spans.size()) * 2;
            commandList->writeTimestamp(pool.get(), first);
            spans.push_back({ section, first, true });
            return int(spans.size()) - 1;
        }

        void end(int span) {
            if ((commandList != nullptr) && (span >= 0)) {
                commandList->writeTimestamp(pool.get(), spans[span].first + 1);
            }
        }

        // Leaves a span out of the totals: the pass turned out to be off and drew nothing.
        void drop(int span) {
            if (span >= 0) {
                spans[span].counted = false;
            }
        }

        // Call before the command list ends. Vulkan only reads back a pool whose every query was
        // written, so the unused ones are written here too.
        void finish() {
            if (commandList == nullptr) {
                return;
            }
            for (uint32_t i = uint32_t(spans.size()) * 2; i < Capacity; i++) {
                commandList->writeTimestamp(pool.get(), i);
            }
            commandList = nullptr;
        }

        // Call once the command list has finished on the GPU.
        void collect() {
            if (spans.empty()) {
                return;
            }
            pool->queryResults();
            const uint64_t *results = pool->getResults();
            for (const Span &span : spans) {
                const uint64_t a = results[span.first];
                const uint64_t b = results[span.first + 1];
                if (span.counted && (b >= a)) {
                    RecordGpuSectionTime(span.section, double(b - a) / 1000000.0);
                }
            }
            spans.clear();
        }
    };

    // The timer for the workload command list (the game's frame and the scene effects).
    GpuSectionTimer &WorkloadGpuSections();

    // Banjo-Tooie: marks a point in a command list that the driver follows on the GPU, so a lost device
    // (the GPU stopped answering) reports the last pass the GPU started and finished (plume::DeviceLostReport).
    // Always on, timed or not. The marker must be a string literal.
    inline void GpuCheckpoint(const RenderCommandList *list, const char *marker) {
        if (list != nullptr) {
            const_cast<RenderCommandList *>(list)->setCheckpoint(marker);
        }
    }

    inline const char *GpuSectionMarker(GpuSection section, bool end) {
        static const char *starts[] = { "water mask: start", "eye adaptation: start", "bloom: start", "scene effects: start",
            "SMAA: start", "FXAA: start", "photo filters: start", "FSR: start", "output: start", "interface: start",
            "sun shadow map: start", "ray tracing: build", "indirect light: start", "traced effects: start" };
        static const char *ends[] = { "water mask: end", "eye adaptation: end", "bloom: end", "scene effects: end",
            "SMAA: end", "FXAA: end", "photo filters: end", "FSR: end", "output: end", "interface: end",
            "sun shadow map: end", "ray tracing: built", "indirect light: end", "traced effects: end" };
        static_assert(std::size(starts) == size_t(GpuSection::Count), "one marker per section");
        return end ? ends[uint32_t(section)] : starts[uint32_t(section)];
    }

    // Starts a span on construction and ends it on destruction, with a checkpoint at each end.
    struct GpuSectionScope {
        GpuSectionTimer &timer;
        int span;
        const RenderCommandList *list;
        GpuSection section;
        GpuSectionScope(GpuSectionTimer &timer, GpuSection section, const RenderCommandList *list) : timer(timer), list(list), section(section) {
            GpuCheckpoint(list, GpuSectionMarker(section, false));
            span = timer.start(section, list);
        }
        void drop() { timer.drop(span); }
        ~GpuSectionScope() {
            timer.end(span);
            GpuCheckpoint(list, GpuSectionMarker(section, true));
        }
    };
};

#endif // RT64_EXT_RENDER_RT64_GPU_SECTIONS_H
