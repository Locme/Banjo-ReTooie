// Video memory log: [vram] lines in console.log, so a run that ends in a freeze or a driver
// crash shows whether video memory was running out first. Vulkan only (plume's
// GetVideoMemoryUse from lib-patches/plume.patch, using VK_EXT_memory_budget when the
// driver has it); on D3D12 nothing is logged.
//
// A thread of its own checks every 2 seconds, so it keeps logging when the game thread is
// stuck. It logs the first reading, a warning once use passes 90% of the budget (again
// after it falls below 80%), and a line whenever use moved by 512 MB since the last line.

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
}

namespace RT64 {
    // lib/rt64/src/render/rt64_texture_cache.h (from lib-patches/rt64.patch).
    uint64_t GetReplacementPoolSize();
}

namespace {
    using namespace std::chrono_literals;

    constexpr uint64_t mb = 1024 * 1024;
    constexpr uint64_t change_step = 512 * mb;

    std::once_flag start_once;

    std::string describe(uint64_t usage, uint64_t budget) {
        char buf[128];
        snprintf(buf, sizeof(buf), "VRAM %llu of %llu MB, pack %llu MB",
            (unsigned long long)(usage / mb), (unsigned long long)(budget / mb), (unsigned long long)(RT64::GetReplacementPoolSize() / mb));
        return buf;
    }

    void watch() {
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
            } else if (first || (usage > last_logged + change_step) || (usage + change_step < last_logged)) {
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
