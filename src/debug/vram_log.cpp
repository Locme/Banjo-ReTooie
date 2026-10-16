// Video memory log: [vram] lines in console.log, so a run that ends in a freeze or a driver
// crash shows whether video memory was running out first. Vulkan only (plume's
// GetVideoMemoryUse from lib-patches/plume.patch, using VK_EXT_memory_budget when the
// driver has it); on D3D12 nothing is logged.
//
// A thread of its own checks every 2 seconds, so it keeps logging when the game thread is
// stuck. It logs the first reading, a warning once use passes 90% of the budget (again
// after it falls below 80%), and a line whenever use moved by 512 MB since the last line.
// Each line also says how much of it the renderer's own allocations account for, and how
// many textures and render targets are alive, so a climb can be pinned on one of them; a second
// line counts every kind of Vulkan object alive and made since the last line. Two more say what the
// memory is holding: the biggest groups of textures and buffers by name, and which groups grew or
// shrank since the last line.

#include <algorithm>
#include <cstdlib>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <map>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

#include "tooie_vram_log.h"

namespace plume {
    // lib/rt64/src/contrib/plume/plume_vulkan.h (from lib-patches/plume.patch).
    bool GetVideoMemoryUse(uint64_t &usage, uint64_t &budget);
    bool GetVideoMemoryDetail(uint64_t &allocationBytes, uint64_t &allocationCount, uint64_t &blockBytes);
    int GetVulkanObjectKinds();
    const char *GetVulkanObjectName(int kind);
    void GetVulkanObjectCount(int kind, int64_t &live, int64_t &made);
    struct VideoMemoryGroup {
        std::string label;
        int64_t count = 0;
        int64_t bytes = 0;
    };
    std::vector<VideoMemoryGroup> GetVideoMemoryGroups();
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

    // Every kind of Vulkan object alive, with how many were made since the last line, the busiest first:
    // memory the driver keeps for objects VMA doesn't see (pipelines, descriptor pools, command lists)
    // shows up as one of these climbing.
    std::string describe_objects() {
        static int64_t last_made[64] = {};
        struct Row { const char *name; int64_t live; int64_t made; };
        std::vector<Row> rows;
        const int kinds = std::min(plume::GetVulkanObjectKinds(), 64);
        for (int i = 0; i < kinds; i++) {
            int64_t live = 0, made = 0;
            plume::GetVulkanObjectCount(i, live, made);
            rows.push_back({ plume::GetVulkanObjectName(i), live, made - last_made[i] });
            last_made[i] = made;
        }
        std::stable_sort(rows.begin(), rows.end(), [](const Row &a, const Row &b) { return a.made > b.made; });
        std::string text = "[vram] objects alive (made since the last line):";
        for (const Row &row : rows) {
            char buf[96];
            snprintf(buf, sizeof(buf), " %s %lld (+%lld),", row.name, (long long)row.live, (long long)row.made);
            text += buf;
        }
        text.pop_back();
        return text;
    }

    std::string megabytes(int64_t bytes) {
        char buf[32];
        if (bytes >= int64_t(mb) || bytes <= -int64_t(mb)) {
            snprintf(buf, sizeof(buf), "%lld MB", (long long)(bytes / int64_t(mb)));
        } else {
            snprintf(buf, sizeof(buf), "%lld KB", (long long)(bytes / 1024));
        }
        return buf;
    }

    // What the video memory is holding, by what each texture and buffer is (RT64's name for it, or its
    // kind and size when unnamed): the biggest groups, then the ones that grew since the last line.
    std::string describe_memory() {
        static std::map<std::string, int64_t> last_bytes;
        struct Row { plume::VideoMemoryGroup group; int64_t grew; };
        std::vector<Row> rows;
        std::map<std::string, int64_t> now_bytes;
        int64_t total = 0;
        for (const plume::VideoMemoryGroup &group : plume::GetVideoMemoryGroups()) {
            auto it = last_bytes.find(group.label);
            rows.push_back({ group, group.bytes - ((it != last_bytes.end()) ? it->second : 0) });
            now_bytes[group.label] = group.bytes;
            total += group.bytes;
        }
        // Groups gone since the last line count as shrinking.
        for (const auto &it : last_bytes) {
            if (now_bytes.find(it.first) == now_bytes.end()) {
                rows.push_back({ { it.first, 0, 0 }, -it.second });
            }
        }
        last_bytes = std::move(now_bytes);

        std::string text = "[vram] using it: " + megabytes(total) + " in textures and buffers; biggest:";
        std::stable_sort(rows.begin(), rows.end(), [](const Row &a, const Row &b) { return a.group.bytes > b.group.bytes; });
        for (size_t i = 0; i < rows.size() && i < 8 && rows[i].group.bytes > 0; i++) {
            const Row &row = rows[i];
            text += " " + row.group.label + " " + megabytes(row.group.bytes) + " (" + std::to_string(row.group.count) + "),";
        }
        text.pop_back();

        std::stable_sort(rows.begin(), rows.end(), [](const Row &a, const Row &b) { return std::llabs(a.grew) > std::llabs(b.grew); });
        std::string changed;
        for (size_t i = 0; i < rows.size() && i < 6 && std::llabs(rows[i].grew) >= int64_t(mb); i++) {
            const Row &row = rows[i];
            changed += " " + row.group.label + " " + (row.grew > 0 ? "+" : "") + megabytes(row.grew) + " (now " + std::to_string(row.group.count) + "),";
        }
        if (!changed.empty()) {
            changed.pop_back();
            text += "\n[vram] changed since the last line:" + changed;
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
            printf("%s\n", describe_objects().c_str());
            printf("%s\n", describe_memory().c_str());
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
