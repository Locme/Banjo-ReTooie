// Call profiler for builds made with tools/trace_build.sh.
//
// Trace-mode code calls tooie_trace_slot() once per function to get a counter
// and bumps it on every call. With TOOIE_TRACE=<file> set, a thread writes the
// calls made in each 2 s window to <file>, one block per window:
//
//     == window 12 (24 s)
//     1830 func_800A7D84
//     ...
//
// tools/trace_diff.py compares windows, e.g. HUD shown against HUD hidden, to
// find the functions behind something on screen. Normal builds never call
// tooie_trace_slot(), so this file costs nothing there.

#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
#include <algorithm>

#include "trace.h"

namespace {
    struct Slot {
        std::string name;
        uint32_t count = 0;
        uint32_t last = 0;
    };

    std::mutex slots_mutex;
    std::deque<Slot> slots; // deque: pointers to elements stay valid
    std::once_flag writer_flag;

    void writer(std::string path) {
        FILE* out = std::fopen(path.c_str(), "w");
        if (out == nullptr) {
            std::fprintf(stderr, "[trace] cannot write %s\n", path.c_str());
            return;
        }
        std::fprintf(stderr, "[trace] writing call counts to %s\n", path.c_str());
        for (int window = 1;; window++) {
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::vector<std::pair<uint32_t, const std::string*>> rows;
            {
                std::lock_guard lock{slots_mutex};
                for (Slot& slot : slots) {
                    uint32_t now = __atomic_load_n(&slot.count, __ATOMIC_RELAXED);
                    if (now != slot.last) {
                        rows.emplace_back(now - slot.last, &slot.name);
                        slot.last = now;
                    }
                }
            }
            std::sort(rows.begin(), rows.end(), [](auto& a, auto& b) { return a.first > b.first; });
            std::fprintf(out, "== window %d (%d s)\n", window, window * 2);
            for (auto& [calls, name] : rows) {
                std::fprintf(out, "%u %s\n", calls, name->c_str());
            }
            std::fflush(out);
        }
    }
}

extern "C" uint32_t* tooie_trace_slot(const char* func_name) {
    std::call_once(writer_flag, [] {
        const char* path = std::getenv("TOOIE_TRACE");
        if (path != nullptr && *path != '\0') {
            std::thread(writer, std::string(path)).detach();
        }
    });
    std::lock_guard lock{slots_mutex};
    slots.push_back(Slot{func_name});
    return &slots.back().count;
}
