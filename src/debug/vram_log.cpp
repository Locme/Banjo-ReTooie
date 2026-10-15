// Video memory log: [vram] lines in console.log, so a run that ends in a freeze or a driver
// crash shows whether video memory was running out first. Vulkan only (plume's
// GetVideoMemoryUse from lib-patches/plume.patch, using VK_EXT_memory_budget when the
// driver has it); on D3D12 nothing is logged.
//
// A thread of its own checks every 2 seconds, so it keeps logging when the game thread is
// stuck. It logs the first reading, a warning once use passes 90% of the budget (again
// after it falls below 80%), and a line whenever use moved by 512 MB since the last line.
// Each line also says how much of it the renderer's own allocations account for, and how
// many textures and render targets are alive, so a climb can be pinned on one of them.

#include <algorithm>
#include <cstdlib>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <mutex>
#include <string>
#include <thread>

#include "tooie_vram_log.h"

namespace plume {
    // lib/rt64/src/contrib/plume/plume_vulkan.h (from lib-patches/plume.patch).
    bool GetVideoMemoryUse(uint64_t &usage, uint64_t &budget);
    bool GetVideoMemoryDetail(uint64_t &allocationBytes, uint64_t &allocationCount, uint64_t &blockBytes);
}

namespace RT64 {
    // lib/rt64/src/render/rt64_texture_cache.h (from lib-patches/rt64.patch).
    uint64_t GetReplacementPoolSize();
    // lib/rt64/src/render/rt64_texture.h (from lib-patches/rt64.patch).
    extern std::atomic<int64_t> LiveTextureCount;
    extern std::atomic<int64_t> LiveRenderTargetCount;
}

namespace {
    using namespace std::chrono_literals;

    constexpr uint64_t mb = 1024 * 1024;
    constexpr uint64_t change_step = 512 * mb;

    std::once_flag start_once;

    std::string describe(uint64_t usage, uint64_t budget) {
        char buf[192];
        snprintf(buf, sizeof(buf), "VRAM %llu of %llu MB, pack %llu MB",
            (unsigned long long)(usage / mb), (unsigned long long)(budget / mb), (unsigned long long)(RT64::GetReplacementPoolSize() / mb));
        std::string text = buf;
        // Ours: what the renderer itself has allocated. When VRAM climbs and this does not, the
        // driver is holding the memory, not a leak in the game's renderer.
        uint64_t allocation_bytes = 0, allocation_count = 0, block_bytes = 0;
        if (plume::GetVideoMemoryDetail(allocation_bytes, allocation_count, block_bytes)) {
            snprintf(buf, sizeof(buf), ", ours %llu MB in %llu allocations (%llu MB blocks), %lld textures, %lld render targets",
                (unsigned long long)(allocation_bytes / mb), (unsigned long long)allocation_count, (unsigned long long)(block_bytes / mb),
                (long long)RT64::LiveTextureCount.load(), (long long)RT64::LiveRenderTargetCount.load());
            text += buf;
        }
        return text;
    }

    void watch() {
        // TOOIE_VRAM_STEP_MB=<n>: log every n MB of change instead of 512 (finding slow leaks headless).
        static const uint64_t step = std::getenv("TOOIE_VRAM_STEP_MB") ? std::max<uint64_t>(1, std::strtoull(std::getenv("TOOIE_VRAM_STEP_MB"), nullptr, 10)) * mb : change_step;
        bool first = true;
        bool warned = false;
        uint64_t last_logged = 0;
        for (;;) {
            std::this_thread::sleep_for(2s);
            uint64_t usage = 0, budget = 0;
            if (!plume::GetVideoMemoryUse(usage, budget) || budget == 0) {
                continue;
            }
            const uint64_t percent = usage * 100 / budget;
            const char* note = nullptr;
            if (percent >= 90 && !warned) {
                warned = true;
                note = "nearly full";
            } else if (percent < 80 && warned) {
                warned = false;
                note = "back under 80%";
            } else if (first || (usage > last_logged + step) || (usage + step < last_logged)) {
                note = "";
            }
            if (note == nullptr) {
                continue;
            }
            first = false;
            last_logged = usage;
            printf("[vram] %s (%llu%%)%s%s\n", describe(usage, budget).c_str(), (unsigned long long)percent, note[0] ? ", " : "", note);
            fflush(stdout);
        }
    }
}

void tooie::vram_log::start() {
    std::call_once(start_once, [] { std::thread(watch).detach(); });
}

std::string tooie::vram_log::summary() {
    uint64_t usage = 0, budget = 0;
    if (!plume::GetVideoMemoryUse(usage, budget) || budget == 0) {
        return {};
    }
    return describe(usage, budget);
}
