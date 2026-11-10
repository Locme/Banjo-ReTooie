// A hardware write watch (console `writewatch`): a debug register on one RDRAM word for a few seconds, counting which
// host code wrote it, with two callers above it, named from BanjoReTooie.pdb (through the sampling profiler's symbol
// lookup). For "what changes this value every frame" questions that the console's watch and trace, which only show the
// value, cannot answer. Only writes from the thread that starts it (the game thread, from the console) are seen.
// Windows only.

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

#include "tooie_host_profiler.h"
#include "tooie_write_watch.h"

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif

namespace {
    std::string format(const char* f, ...) {
        char buf[512];
        va_list args;
        va_start(args, f);
        std::vsnprintf(buf, sizeof(buf), f, args);
        va_end(args);
        return buf;
    }

#ifdef _WIN32
    // ---------------------------------------------------------------------------------------------------------------
    // The write watch.

    struct WatchChain {
        uintptr_t at[4] = { 0, 0, 0, 0 };
        bool operator==(const WatchChain& o) const { return std::memcmp(at, o.at, sizeof(at)) == 0; }
    };
    struct WatchChainHash {
        size_t operator()(const WatchChain& c) const { return c.at[0] ^ (c.at[1] * 31) ^ (c.at[2] * 1009) ^ (c.at[3] * 7919); }
    };

    std::atomic<bool> watching{ false };
    std::mutex watch_mutex;
    std::unordered_map<WatchChain, uint32_t, WatchChainHash> watch_hits;
    PVOID watch_handler = nullptr;

    // The writer and the functions above it, from the x64 unwind data (a leaf function has none: its return address
    // is at the stack pointer). A bad stack ends the walk instead of crashing.
    void walk_writer(CONTEXT c, WatchChain& chain) {
        chain.at[0] = (uintptr_t)c.Rip;
        __try {
            for (int level = 1; level < 4; level++) {
                DWORD64 image = 0;
                PRUNTIME_FUNCTION fn = RtlLookupFunctionEntry(c.Rip, &image, nullptr);
                if (fn == nullptr) {
                    c.Rip = *(DWORD64*)c.Rsp;
                    c.Rsp += 8;
                } else {
                    void* data = nullptr;
                    DWORD64 frame = 0;
                    RtlVirtualUnwind(UNW_FLAG_NHANDLER, image, c.Rip, fn, &c, &data, &frame, nullptr);
                }
                if (c.Rip == 0) break;
                chain.at[level] = (uintptr_t)c.Rip;
            }
        } __except (EXCEPTION_EXECUTE_HANDLER) {
        }
    }

    LONG CALLBACK on_watch_hit(EXCEPTION_POINTERS* info) {
        if (info->ExceptionRecord->ExceptionCode != EXCEPTION_SINGLE_STEP || !watching.load() || (info->ContextRecord->Dr6 & 1) == 0) {
            return EXCEPTION_CONTINUE_SEARCH;
        }
        WatchChain chain;
        walk_writer(*info->ContextRecord, chain);
        {
            std::lock_guard lock{ watch_mutex };
            watch_hits[chain]++;
        }
        info->ContextRecord->Dr6 = 0;
        return EXCEPTION_CONTINUE_EXECUTION;
    }

    void set_debug_register(HANDLE thread, DWORD64 address, bool on) {
        SuspendThread(thread);
        CONTEXT c{};
        c.ContextFlags = CONTEXT_DEBUG_REGISTERS;
        if (GetThreadContext(thread, &c)) {
            c.Dr0 = on ? address : 0;
            // Dr0 on (local), written to, 4 bytes long.
            c.Dr7 = on ? (1ull | (1ull << 16) | (3ull << 18)) : 0;
            c.Dr6 = 0;
            SetThreadContext(thread, &c);
        }
        ResumeThread(thread);
    }

    // Function names without the parameter lists the PDB may give.
    std::string short_name(uintptr_t address) {
        std::string name = tooie::host_profiler::function_name(address);
        return name.empty() ? format("%p", (void*)address) : name;
    }
#endif
}

std::string tooie::write_watch::start(uint8_t* rdram, uint32_t address, double seconds) {
#ifdef _WIN32
    // The console has checked the address is in RAM.
    if ((address & 3) != 0) {
        return "ERR the address must be a multiple of 4 (a whole word)";
    }
    if (watching.exchange(true)) {
        return "ERR a write watch is already on";
    }
    seconds = std::clamp(seconds, 0.5, 60.0);
    {
        std::lock_guard lock{ watch_mutex };
        watch_hits.clear();
    }
    if (watch_handler == nullptr) {
        watch_handler = AddVectoredExceptionHandler(1, on_watch_hit);
    }
    HANDLE self = nullptr;
    DuplicateHandle(GetCurrentProcess(), GetCurrentThread(), GetCurrentProcess(), &self, 0, FALSE, DUPLICATE_SAME_ACCESS);
    const DWORD64 host = (DWORD64)(rdram + (address - 0x80000000u));
    std::thread([self, host, address, seconds]() {
        set_debug_register(self, host, true);
        std::this_thread::sleep_for(std::chrono::duration<double>(seconds));
        set_debug_register(self, host, false);
        CloseHandle(self);
        std::vector<std::pair<uint32_t, WatchChain>> list;
        {
            std::lock_guard lock{ watch_mutex };
            for (auto& [chain, n] : watch_hits) list.push_back({ n, chain });
            watch_hits.clear();
        }
        watching = false;
        std::sort(list.begin(), list.end(), [](const auto& a, const auto& b) { return a.first > b.first; });
        uint32_t total = 0;
        for (auto& [n, chain] : list) total += n;
        std::fprintf(stderr, "[writewatch] %08X: %u writes in %.1f s from %zu places\n", address, total, seconds, list.size());
        for (size_t i = 0; i < list.size() && i < 8; i++) {
            const WatchChain& chain = list[i].second;
            std::string text = short_name(chain.at[0]);
            for (int level = 1; level < 4 && chain.at[level] != 0; level++) {
                text += " <- " + short_name(chain.at[level]);
            }
            std::fprintf(stderr, "[writewatch]   %u  %s\n", list[i].first, text.c_str());
        }
        std::fflush(stderr);
    }).detach();
    return format("watching writes to %08X for %.1f s on the game thread", address, seconds);
#else
    (void)rdram; (void)address; (void)seconds;
    return "ERR the write watch runs on Windows only";
#endif
}
