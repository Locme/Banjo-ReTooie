// A sampling profiler for the whole process (console `hostprof`, or TOOIE_PROFILE=<file> from the start): where the
// PC's CPU time goes while the game runs, by host function, so the heavy ones can be found: the recompiled game's own
// functions (func_...), the recomp runtime (librecomp, ultramodern), RT64's renderer and the graphics driver.
// Ported from the Mario Party 3 recomp's host_profiler.cpp (same author, GPLv3, docs/THIRD_PARTY.md), with labels
// added so one run through many maps splits by map.
//
// A thread of its own wakes about every 2 ms, and for each other thread of the process that used CPU time since the
// last look (QueryThreadCycleTime: a thread that waited is not sampled, so waiting is not counted as work) suspends
// it, reads its instruction pointer and lets it go on. Counts are kept per label, thread and address; every 5 s and
// on stop the file is written again with the addresses named through the PDB (DbgHelp), so a run that is killed or
// crashes still leaves its profile. Each line: samples, label, thread name, module, function (tab separated), most
// samples first. With 2 ms a sample, 500 samples are a second of one core's time. Self time only, no call stacks.
#ifdef _WIN32
#include <windows.h>
#include <intrin.h>
#include <tlhelp32.h>
#include <dbghelp.h>
#include <algorithm>
#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

#include "tooie_host_profiler.h"

#pragma comment(lib, "dbghelp.lib")
#pragma comment(lib, "winmm.lib")

namespace {

struct ThreadInfo {
    HANDLE handle = nullptr;
    ULONG64 cycles = 0;
    std::string name;
};

std::string thread_name(HANDLE h, DWORD tid) {
    using GetDesc = HRESULT(WINAPI*)(HANDLE, PWSTR*);
    static GetDesc get = (GetDesc)GetProcAddress(GetModuleHandleA("kernel32.dll"), "GetThreadDescription");
    std::string name;
    PWSTR w = nullptr;
    if (get && SUCCEEDED(get(h, &w)) && w) {
        char buf[128];
        int n = WideCharToMultiByte(CP_UTF8, 0, w, -1, buf, sizeof buf, nullptr, nullptr);
        if (n > 1) name = buf;
        LocalFree(w);
    }
    if (name.empty()) name = "thread " + std::to_string(tid);
    return name;
}

class Profiler {
public:
    void start(const std::string& path) {
        std::lock_guard lock{ mutex_ };
        path_ = path;
        counts_.clear();
        chains_.clear();
        total_ = 0;
        if (!sym_proc_) {
            HANDLE dup = nullptr;
            DuplicateHandle(GetCurrentProcess(), GetCurrentProcess(), GetCurrentProcess(), &dup, 0, FALSE, DUPLICATE_SAME_ACCESS);
            sym_proc_ = dup;
            SymSetOptions(SYMOPT_DEFERRED_LOADS | SYMOPT_UNDNAME | SYMOPT_FAIL_CRITICAL_ERRORS | SYMOPT_NO_PROMPTS);
            sym_ready_ = SymInitialize(sym_proc_, nullptr, TRUE) != FALSE;
        }
        if (cycles_per_look_ == 0) {
            // Thread cycle counts run at the time stamp counter's rate; measure it against the clock once.
            LARGE_INTEGER f0, c0, c1;
            QueryPerformanceFrequency(&f0);
            QueryPerformanceCounter(&c0);
            const unsigned long long t0 = __rdtsc();
            Sleep(50);
            QueryPerformanceCounter(&c1);
            const unsigned long long t1 = __rdtsc();
            const double seconds = double(c1.QuadPart - c0.QuadPart) / double(f0.QuadPart);
            cycles_per_look_ = (ULONG64)((t1 - t0) / seconds * 0.002);
        }
        if (!running_.exchange(true)) {
            // A thread from an earlier start that has not seen the stop yet ends at its next look.
            const int gen = ++generation_;
            std::thread([this, gen] { run(gen); }).detach();
        }
    }

    // Writes the file a last time and stops sampling. Returns the samples taken (2 ms of one core each).
    uint64_t stop() {
        if (!running_.exchange(false)) return 0;
        std::lock_guard lock{ mutex_ };
        write();
        return cycles_per_look_ ? total_ / cycles_per_look_ : 0;
    }

    void set_label(const std::string& label) {
        std::lock_guard lock{ mutex_ };
        label_ = label;
    }

    bool running() const { return running_.load(); }
    std::string path() {
        std::lock_guard lock{ mutex_ };
        return path_;
    }

private:
    void refresh_threads() {
        const DWORD pid = GetCurrentProcessId(), self = GetCurrentThreadId();
        HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
        if (snap == INVALID_HANDLE_VALUE) return;
        THREADENTRY32 te{};
        te.dwSize = sizeof te;
        for (BOOL ok = Thread32First(snap, &te); ok; ok = Thread32Next(snap, &te)) {
            if (te.th32OwnerProcessID != pid || te.th32ThreadID == self || threads_.count(te.th32ThreadID)) continue;
            HANDLE h = OpenThread(THREAD_SUSPEND_RESUME | THREAD_GET_CONTEXT | THREAD_QUERY_INFORMATION, FALSE, te.th32ThreadID);
            if (!h) continue;
            ThreadInfo info;
            info.handle = h;
            QueryThreadCycleTime(h, &info.cycles);
            info.name = thread_name(h, te.th32ThreadID);
            threads_[te.th32ThreadID] = info;
        }
        CloseHandle(snap);
        // Threads that ended: their handles are closed; their samples stay (kept by name).
        for (auto it = threads_.begin(); it != threads_.end();) {
            DWORD code = 0;
            if (GetExitCodeThread(it->second.handle, &code) && code != STILL_ACTIVE) {
                CloseHandle(it->second.handle);
                it = threads_.erase(it);
            } else {
                ++it;
            }
        }
    }

    void sample() {
        std::lock_guard lock{ mutex_ };
        auto& by_thread = counts_[label_];
        for (auto& [tid, t] : threads_) {
            ULONG64 cycles = 0;
            if (!QueryThreadCycleTime(t.handle, &cycles)) continue;
            const ULONG64 used = cycles - t.cycles;
            t.cycles = cycles;
            // A thread that only woke for a moment (under 2% of a look) is left out: it was waiting.
            if (used < cycles_per_look_ / 50) continue;
            if (SuspendThread(t.handle) == (DWORD)-1) continue;
            CONTEXT ctx{};
            // Weighted by the cycles the thread used since the last look, so a thread that was busy a tenth of the
            // time counts a tenth as much as one that ran the whole time.
            ctx.ContextFlags = CONTEXT_CONTROL | CONTEXT_INTEGER;
            if (GetThreadContext(t.handle, &ctx)) {
                by_thread[t.name][(uintptr_t)ctx.Rip] += used;
                // The two functions above it, while the thread is still held, for the .callers.tsv file.
                Chain chain{ (uintptr_t)ctx.Rip, 0, 0 };
                unwind_callers(ctx, chain);
                chains_[label_][t.name][chain] += used;
            }
            ResumeThread(t.handle);
            total_ += used;
        }
    }

    struct Chain {
        uintptr_t leaf, caller, caller2;
        bool operator==(const Chain& o) const { return leaf == o.leaf && caller == o.caller && caller2 == o.caller2; }
    };
    struct ChainHash {
        size_t operator()(const Chain& c) const { return std::hash<uintptr_t>()(c.leaf) ^ (std::hash<uintptr_t>()(c.caller) * 31) ^ (std::hash<uintptr_t>()(c.caller2) * 1009); }
    };

    // Two steps up the held thread's stack with the x64 unwind data (a leaf function with none: its return address is
    // at the stack pointer). A bad stack ends the walk instead of crashing the program.
    static void unwind_callers(CONTEXT ctx, Chain& chain) {
        __try {
            for (int level = 0; level < 2; level++) {
                DWORD64 image_base = 0;
                PRUNTIME_FUNCTION entry = RtlLookupFunctionEntry(ctx.Rip, &image_base, nullptr);
                if (entry == nullptr) {
                    ctx.Rip = *(DWORD64*)ctx.Rsp;
                    ctx.Rsp += 8;
                } else {
                    PVOID handler_data = nullptr;
                    DWORD64 establisher = 0;
                    RtlVirtualUnwind(UNW_FLAG_NHANDLER, image_base, ctx.Rip, entry, &ctx, &handler_data, &establisher, nullptr);
                }
                if (ctx.Rip == 0) break;
                (level == 0 ? chain.caller : chain.caller2) = (uintptr_t)ctx.Rip;
            }
        } __except (EXCEPTION_EXECUTE_HANDLER) {
        }
    }

    std::string name_of(uintptr_t addr, std::string& module) {
        HMODULE mod = nullptr;
        char modname[MAX_PATH] = "";
        if (GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCSTR)addr, &mod)) {
            GetModuleFileNameA(mod, modname, sizeof modname);
        }
        const char* base = modname;
        for (const char* p = modname; *p; p++) if (*p == '\\' || *p == '/') base = p + 1;
        module = *base ? base : "?";
        if (sym_ready_) {
            alignas(SYMBOL_INFO) char buf[sizeof(SYMBOL_INFO) + 512];
            SYMBOL_INFO* sym = (SYMBOL_INFO*)buf;
            sym->SizeOfStruct = sizeof(SYMBOL_INFO);
            sym->MaxNameLen = 511;
            DWORD64 disp = 0;
            if (SymFromAddr(sym_proc_, (DWORD64)addr, &disp, sym)) return sym->Name;
        }
        char hex[32];
        std::snprintf(hex, sizeof hex, "+0x%llx", (unsigned long long)(addr - (uintptr_t)mod));
        return module + hex;
    }

    const std::pair<std::string, std::string>& named(uintptr_t addr) {
        auto it = names_.find(addr);
        if (it == names_.end()) {
            std::string module;
            std::string func = name_of(addr, module);
            it = names_.emplace(addr, std::make_pair(module, func)).first;
        }
        return it->second;
    }

    // <file>.callers.tsv: samples, label, thread, function, its caller, the caller's caller; heaviest first.
    void write_callers(double per) {
        struct Row { double n; std::string key; };
        std::unordered_map<std::string, double> rows;
        for (auto& [label, threads] : chains_) {
            for (auto& [tname, chains] : threads) {
                for (auto& [chain, n] : chains) {
                    std::string key = label + '\t' + tname + '\t' + named(chain.leaf).second + '\t' +
                        (chain.caller ? named(chain.caller).second : "-") + '\t' + (chain.caller2 ? named(chain.caller2).second : "-");
                    rows[key] += n / per;
                }
            }
        }
        std::vector<Row> sorted;
        for (auto& [k, n] : rows) if (n >= 0.5) sorted.push_back({ n, k });
        std::sort(sorted.begin(), sorted.end(), [](const Row& a, const Row& b) { return a.n > b.n; });
        std::string path = path_;
        const size_t dot = path.rfind('.');
        path = (dot == std::string::npos ? path : path.substr(0, dot)) + ".callers.tsv";
        std::string tmp = path + ".tmp";
        FILE* f = std::fopen(tmp.c_str(), "w");
        if (!f) return;
        std::fprintf(f, "# samples\tlabel\tthread\tfunction\tcaller\tcaller's caller\n");
        for (const Row& r : sorted) std::fprintf(f, "%.0f\t%s\n", r.n, r.key.c_str());
        std::fclose(f);
        MoveFileExA(tmp.c_str(), path.c_str(), MOVEFILE_REPLACE_EXISTING);
    }

    // Called with mutex_ held.
    void write() {
        struct Row { uint64_t n; std::string label, thread, module, func; };
        std::unordered_map<std::string, Row> rows; // per label, thread and function
        for (auto& [label, threads] : counts_) {
            for (auto& [tname, addrs] : threads) {
                for (auto& [addr, n] : addrs) {
                    auto it = names_.find(addr);
                    if (it == names_.end()) {
                        std::string module;
                        std::string func = name_of(addr, module);
                        it = names_.emplace(addr, std::make_pair(module, func)).first;
                    }
                    Row& r = rows[label + '\t' + tname + '\t' + it->second.second];
                    r.n += n;
                    r.label = label;
                    r.thread = tname;
                    r.module = it->second.first;
                    r.func = it->second.second;
                }
            }
        }
        std::vector<Row> sorted;
        sorted.reserve(rows.size());
        for (auto& [k, r] : rows) sorted.push_back(r);
        std::sort(sorted.begin(), sorted.end(), [](const Row& a, const Row& b) { return a.n > b.n; });
        // Cycles to 2 ms samples of one core.
        const double per = (double)cycles_per_look_;
        std::string tmp = path_ + ".tmp";
        FILE* f = std::fopen(tmp.c_str(), "w");
        if (!f) return;
        std::fprintf(f, "# TOOIE_PROFILE: %.0f samples (2 ms of one core each, weighted by the CPU time each thread used)\n", total_ / per);
        for (const Row& r : sorted) {
            if (r.n / per < 0.5) break;
            std::fprintf(f, "%.0f\t%s\t%s\t%s\t%s\n", r.n / per, r.label.c_str(), r.thread.c_str(), r.module.c_str(), r.func.c_str());
        }
        std::fclose(f);
        MoveFileExA(tmp.c_str(), path_.c_str(), MOVEFILE_REPLACE_EXISTING);
        write_callers(per);
    }

    void run(int gen) {
        timeBeginPeriod(1);
        DWORD last_refresh = 0, last_write = GetTickCount();
        while (running_.load() && generation_.load() == gen) {
            const DWORD now = GetTickCount();
            if (now - last_refresh > 500) { refresh_threads(); last_refresh = now; }
            sample();
            if (now - last_write > 5000) {
                std::lock_guard lock{ mutex_ };
                write();
                last_write = now;
            }
            Sleep(2);
        }
        timeEndPeriod(1);
    }

    std::mutex mutex_;
    std::atomic<bool> running_{ false };
    std::atomic<int> generation_{ 0 };
    std::string path_;
    std::string label_ = "-";
    HANDLE sym_proc_ = nullptr;
    bool sym_ready_ = false;
    std::unordered_map<DWORD, ThreadInfo> threads_;
    std::unordered_map<std::string, std::unordered_map<std::string, std::unordered_map<uintptr_t, uint64_t>>> counts_;
    std::unordered_map<uintptr_t, std::pair<std::string, std::string>> names_;
    std::unordered_map<std::string, std::unordered_map<std::string, std::unordered_map<Chain, uint64_t, ChainHash>>> chains_;
    uint64_t total_ = 0; // cycles
    ULONG64 cycles_per_look_ = 0;
};

Profiler& profiler() {
    static Profiler* p = new Profiler();
    return *p;
}

struct Start {
    Start() {
        if (const char* path = std::getenv("TOOIE_PROFILE")) profiler().start(path);
    }
} g_start;

} // namespace

bool tooie::host_profiler::start(const std::string& path) { profiler().start(path); return true; }
uint64_t tooie::host_profiler::stop() { return profiler().stop(); }
void tooie::host_profiler::label(const std::string& text) { profiler().set_label(text); }
bool tooie::host_profiler::running() { return profiler().running(); }
std::string tooie::host_profiler::path() { return profiler().path(); }
#else
#include "tooie_host_profiler.h"
bool tooie::host_profiler::start(const std::string&) { return false; }
uint64_t tooie::host_profiler::stop() { return 0; }
void tooie::host_profiler::label(const std::string&) {}
bool tooie::host_profiler::running() { return false; }
std::string tooie::host_profiler::path() { return {}; }
#endif
