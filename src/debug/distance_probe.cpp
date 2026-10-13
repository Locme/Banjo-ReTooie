// Distance probe (debug tool for handoff 4.26): with TOOIE_DISTANCE_PROBE=1,
// counts who calls the game's distance helpers func_800EEAD4 (distance) and
// func_800EEB40 (squared distance), by host caller address (resolve with nm or addr2line; Linux only), and prints the busiest
// callers every 5 seconds. Used to find the
// draw-distance and actor-range checks.

#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <mutex>
#include <utility>
#include <vector>
#include <algorithm>

#if defined(__linux__)
#include <dlfcn.h>
#include <execinfo.h>
#endif

#include "recomp.h"
#include "tooie_hooks.h"

namespace {
    struct Entry { uint64_t calls = 0; };
    std::mutex probe_mutex;
    std::map<std::pair<int, uintptr_t>, Entry> callers;
    std::chrono::steady_clock::time_point last_print;

    bool enabled() {
        static const bool on = std::getenv("TOOIE_DISTANCE_PROBE") != nullptr;
        return on;
    }

    void note(int kind, recomp_context* ctx) {
        std::lock_guard lock{probe_mutex};
        // Recompiled calls are plain C calls ($ra is not set), so take the
        // host caller of the helper: frame 0 is note(), 1 the helper (the hook and note are inlined into it), 2 its caller.
        uintptr_t caller = 0;
#if defined(__linux__)
        void* frames[4] = {};
        int n = backtrace(frames, 4);
        caller = n >= 3 ? (uintptr_t)frames[2] : 0;
        Dl_info info{};
        if (caller != 0 && dladdr((void*)caller, &info) != 0) {
            caller -= (uintptr_t)info.dli_fbase;   // offset into the executable, for nm
        }
#endif
        callers[{kind, caller}].calls++;
        auto now = std::chrono::steady_clock::now();
        if (now - last_print < std::chrono::seconds(5)) {
            return;
        }
        last_print = now;
        std::vector<std::pair<uint64_t, std::pair<int, uintptr_t>>> rows;
        for (auto& [key, entry] : callers) {
            rows.push_back({entry.calls, key});
        }
        std::sort(rows.rbegin(), rows.rend());
        fprintf(stderr, "[distance probe]");
        for (size_t i = 0; i < rows.size() && i < 24; i++) {
            fprintf(stderr, " %s%llx:%llu", rows[i].second.first ? "sq@" : "d@", (unsigned long long)rows[i].second.second, (unsigned long long)rows[i].first);
        }
        fprintf(stderr, "\n");
        callers.clear();
    }
}

extern "C" void tooie_distance_probe(uint8_t* rdram, recomp_context* ctx, int squared) {
    if (enabled()) {
        note(squared, ctx);
    }
}
