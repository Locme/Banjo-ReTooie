// Pass over crashes (DEV tab, on by default; L, 2026-10-17): a general guard against the crash the
// game hits most, game code reading or writing through a bad pointer.
//
// The game's memory is a 4 GB block (librecomp: the first 512 MB usable, the rest kept with no
// access), and a recompiled load of N64 address A reads base + (A - 0x80000000). A null pointer
// (A = 0 plus a small offset) lands at base + 0x80000000, in the no-access part, and Windows stops
// the game with an access violation (L's chanim_entrypoint_6 and chquiz crashes in the sweep).
//
// With the guard on, such a fault in that part of the block is caught first: the page is made
// readable and zeroed, the one instruction is run again single-stepped (so the read gives 0 and a
// write goes nowhere), and the page is closed again. The game carries on as if the memory held 0.
// Each place it happens is logged once in detail as a MAJOR line in logs/PassedOver.txt and
// console.log, with a notice on screen, then counted, so it can be fixed properly afterwards.
// PassedOver.txt also gets the texture sweep's pass-overs (texture_sweep.cpp). Faults anywhere else still crash and are reported as before.
//
// x86-64 Windows and Linux; elsewhere the option does nothing. Headless check:
// TOOIE_PASS_OVER_TEST=<frame> reads and writes through a null pointer on that frame.

#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <filesystem>
#include <mutex>
#include <string>

#ifdef _WIN32
#include <Windows.h>
#else
#include <csignal>
#include <sys/mman.h>
#include <ucontext.h>
#include <unistd.h>
#endif

#include "recomp.h"
#include "librecomp/addresses.hpp"
#include "recompui/config.h"
#include "librecomp/game.hpp"

#include "tooie_debug.h"
#include "tooie_game.h"
#include "tooie_memory_guard.h"
#include "tooie_texture_sweep.h"
#include "tooie_toast.h"

namespace {
    constexpr uint64_t block_size = recomp::allocation_size;
    constexpr uint64_t usable_size = recomp::mem_size;

    std::atomic<uint8_t*> base{nullptr};
    std::atomic<bool> on{true};
    std::once_flag install_once;

    // Places (host instruction addresses) seen so far, with how often.
    struct Site {
        std::atomic<uintptr_t> pc{0};
        std::atomic<uint32_t> hits{0};
    };
    constexpr int max_sites = 128;
    Site sites[max_sites];
    std::atomic<uint32_t> total_hits{0};

    thread_local uint8_t* open_page = nullptr;
    // Wide on Windows, so a folder named outside the ANSI code page (バンジョー on a Western PC) still opens.
#ifdef _WIN32
    wchar_t passed_over_path[1024] = {};
#else
    char passed_over_path[1024] = {};
#endif

    FILE* open_passed_over() {
#ifdef _WIN32
        return _wfopen(passed_over_path, L"a");
#else
        return std::fopen(passed_over_path, "a");
#endif
    }

    constexpr size_t page_size = 4096;

    uint8_t* page_of(uintptr_t addr) {
        return reinterpret_cast<uint8_t*>(addr & ~uintptr_t(page_size - 1));
    }

    // The N64 address a host address in the block stands for.
    uint32_t n64_address(uintptr_t host) {
        return uint32_t(host - reinterpret_cast<uintptr_t>(base.load())) + 0x80000000u;
    }

    bool in_guarded_part(uintptr_t addr) {
        const uintptr_t b = reinterpret_cast<uintptr_t>(base.load());
        return b != 0 && addr >= b + usable_size && addr < b + block_size;
    }

    void timestamp(char* out, size_t size) {
        std::time_t t = std::time(nullptr);
        std::tm tm_buf{};
#ifdef _WIN32
        localtime_s(&tm_buf, &t);
#else
        localtime_r(&t, &tm_buf);
#endif
        std::strftime(out, size, "%Y-%m-%d_%H-%M-%S", &tm_buf);
    }

    // Counts the hit; logs the first one at each place in full, then again at 10, 100 and 1000.
    void note(uintptr_t pc, uintptr_t fault, bool write) {
        total_hits++;
        uint32_t hits = 0;
        bool new_site = false;
        for (Site& s : sites) {
            uintptr_t expected = 0;
            if (s.pc.load() == pc) {
                hits = ++s.hits;
                break;
            }
            if (s.pc.compare_exchange_strong(expected, pc)) {
                hits = ++s.hits;
                new_site = true;
                break;
            }
        }
        if (!new_site && hits != 10 && hits != 100 && hits != 1000) {
            return;
        }

        char where[400];
        tooie::describe_code_address(reinterpret_cast<void*>(pc), where, sizeof(where));
        const uint32_t address = n64_address(fault);
        uint16_t map = 0;
        if (uint8_t* rdram = base.load()) {
            map = tooie::debug::current_map(rdram);
        }
        char line[900];
        if (new_site) {
            std::snprintf(line, sizeof(line),
                "MAJOR crash passed over: bad %s of N64 address 0x%08X (%s) in %s, map 0x%03X; the game carried on as if it held 0",
                write ? "write" : "read", address, address < 0x10000 ? "a null pointer" : "no memory there", where, map);
            tooie::memory_guard::log_passed_over(line);
            char why[700];
            std::snprintf(why, sizeof(why), "bad %s of N64 address 0x%08X in %s (carried on)", write ? "write" : "read", address, where);
            tooie::texture_sweep::note_major(why);
        } else {
            std::snprintf(line, sizeof(line), "MAJOR crash passed over again: %s, %u times so far (last at map 0x%03X)", where, hits, map);
            char ts[32];
            timestamp(ts, sizeof(ts));
            std::printf("[pass-over] %s %s\n", ts, line);
            std::fflush(stdout);
            if (FILE* f = open_passed_over()) {
                std::fprintf(f, "%s %s\n", ts, line);
                std::fclose(f);
            }
        }
    }

#ifdef _WIN32
    LONG WINAPI on_exception(EXCEPTION_POINTERS* ep) {
        const DWORD code = ep->ExceptionRecord->ExceptionCode;
        if (code == EXCEPTION_SINGLE_STEP && open_page != nullptr) {
            DWORD old = 0;
            VirtualProtect(open_page, page_size, PAGE_NOACCESS, &old);
            open_page = nullptr;
            ep->ContextRecord->EFlags &= ~0x100;
            return EXCEPTION_CONTINUE_EXECUTION;
        }
        if (code != EXCEPTION_ACCESS_VIOLATION || !on.load() || ep->ExceptionRecord->NumberParameters < 2) {
            return EXCEPTION_CONTINUE_SEARCH;
        }
        const uintptr_t fault = static_cast<uintptr_t>(ep->ExceptionRecord->ExceptionInformation[1]);
        const ULONG_PTR kind = ep->ExceptionRecord->ExceptionInformation[0];
        // 8 is an attempt to run code there: nothing to pass over.
        if (kind == 8 || !in_guarded_part(fault) || open_page != nullptr) {
            return EXCEPTION_CONTINUE_SEARCH;
        }
        uint8_t* page = page_of(fault);
        DWORD old = 0;
        if (!VirtualProtect(page, page_size, PAGE_READWRITE, &old)) {
            return EXCEPTION_CONTINUE_SEARCH;
        }
        std::memset(page, 0, page_size);
        open_page = page;
        ep->ContextRecord->EFlags |= 0x100;
        note(static_cast<uintptr_t>(ep->ContextRecord->Rip), fault, kind == 1);
        return EXCEPTION_CONTINUE_EXECUTION;
    }

    void install() {
        AddVectoredExceptionHandler(1, on_exception);
    }
#elif defined(__x86_64__) && !defined(__ANDROID__)
    struct sigaction previous_segv{};
    struct sigaction previous_trap{};

    void pass_on(const struct sigaction& prev, int sig, siginfo_t* info, void* uc) {
        if (prev.sa_flags & SA_SIGINFO) {
            if (prev.sa_sigaction) {
                prev.sa_sigaction(sig, info, uc);
                return;
            }
        } else if (prev.sa_handler != SIG_DFL && prev.sa_handler != SIG_IGN) {
            prev.sa_handler(sig);
            return;
        }
        signal(sig, SIG_DFL);
        raise(sig);
    }

    void on_segv(int sig, siginfo_t* info, void* uc_void) {
        const uintptr_t fault = reinterpret_cast<uintptr_t>(info->si_addr);
        if (on.load() && open_page == nullptr && in_guarded_part(fault)) {
            uint8_t* page = page_of(fault);
            if (mprotect(page, page_size, PROT_READ | PROT_WRITE) == 0) {
                std::memset(page, 0, page_size);
                open_page = page;
                ucontext_t* uc = static_cast<ucontext_t*>(uc_void);
                uc->uc_mcontext.gregs[REG_EFL] |= 0x100;
                const bool write = (uc->uc_mcontext.gregs[REG_ERR] & 2) != 0;
                note(static_cast<uintptr_t>(uc->uc_mcontext.gregs[REG_RIP]), fault, write);
                return;
            }
        }
        pass_on(previous_segv, sig, info, uc_void);
    }

    void on_trap(int sig, siginfo_t* info, void* uc_void) {
        if (open_page != nullptr) {
            mprotect(open_page, page_size, PROT_NONE);
            open_page = nullptr;
            // The saved flags still have the trap flag set: clear it, or every next instruction traps.
            static_cast<ucontext_t*>(uc_void)->uc_mcontext.gregs[REG_EFL] &= ~0x100;
            return;
        }
        pass_on(previous_trap, sig, info, uc_void);
    }

    void install() {
        struct sigaction sa{};
        sa.sa_sigaction = on_segv;
        sa.sa_flags = SA_SIGINFO | SA_ONSTACK;
        sigemptyset(&sa.sa_mask);
        sigaction(SIGSEGV, &sa, &previous_segv);
        struct sigaction st{};
        st.sa_sigaction = on_trap;
        st.sa_flags = SA_SIGINFO;
        sigemptyset(&st.sa_mask);
        sigaction(SIGTRAP, &st, &previous_trap);
    }
#else
    void install() {}
#endif
}

void tooie::memory_guard::add_option(recomp::config::Config& config) {
    config.add_bool_option(
        option,
        "Pass Over Crashes",
        "When game code reads or writes memory that isn't there (a missing pointer, the most common crash), the game carries on as if it read 0 instead of closing. "
        "Each place this happens is written to logs/PassedOver.txt and console.log as a MAJOR line saying where, with a notice on screen, so it can be fixed properly. "
        "During a texture sweep, any other crash or a hang of 60 seconds starts the game again and the sweep carries on from the next entrance.",
        true);
}

void tooie::memory_guard::log_passed_over(const char* line) {
    char ts[32];
    timestamp(ts, sizeof(ts));
    std::printf("[pass-over] %s %s\n", ts, line);
    std::fflush(stdout);
    if (passed_over_path[0] == '\0') {
        return;
    }
    if (FILE* f = open_passed_over()) {
        std::fprintf(f, "%s %s\n", ts, line);
        std::fclose(f);
    }
    tooie::toast::show("Passed over a crash: logs/PassedOver.txt has the details");
}

void tooie::memory_guard::tick(uint8_t* rdram) {
    if (passed_over_path[0] == '\0') {
        std::error_code ec;
        std::filesystem::path logs = recomp::get_config_path() / "logs";
        std::filesystem::create_directories(logs, ec);
        // native(): wide on Windows (path::string() throws for a name outside the ANSI code page), UTF-8 elsewhere.
        const auto path = (logs / "PassedOver.txt").native();
        const size_t room = sizeof(passed_over_path) / sizeof(passed_over_path[0]) - 1;
        const size_t length = path.size() < room ? path.size() : room;
        for (size_t i = 0; i < length; i++) {
            passed_over_path[i] = path[i];
        }
        passed_over_path[length] = 0;
    }
    if (base.load() == nullptr) {
        base = rdram;
        std::call_once(install_once, install);
    }
    // Headless check: TOOIE_PASS_OVER_TEST=<n> makes the game thread read and write through a null
    // pointer on its nth frame, as the game's crashing code does.
    static const long test_frame = [] {
        const char* env = std::getenv("TOOIE_PASS_OVER_TEST");
        return env ? std::strtol(env, nullptr, 10) : 0L;
    }();
    static long frames = 0;
    if (test_frame > 0 && ++frames == test_frame) {
        const gpr null_pointer = 0;
        const int32_t value = MEM_W(0x4, null_pointer);
        MEM_W(0x8, null_pointer) = 0x1234;
        std::printf("[pass-over] test: read %d through a null pointer and wrote to one, still running\n", value);
        std::fflush(stdout);
    }
    try {
        on = std::get<bool>(recompui::config::get_config(tooie::wip_tab_id).get_option_value(option));
    } catch (...) {
    }
}

void tooie::memory_guard::forget_sites() {
    for (Site& s : sites) {
        s.hits = 0;
        s.pc = 0;
    }
}

bool tooie::memory_guard::enabled() {
    return on.load();
}
