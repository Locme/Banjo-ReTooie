#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <cstring>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <string>

#ifdef _WIN32
#include <Windows.h>
#include <DbgHelp.h>
#include <csignal>
#include <crtdbg.h>
#include <process.h>
#else
#include <csignal>
#include <fcntl.h>
#include <unistd.h>
#if defined(__GLIBC__)
#include <execinfo.h>
#endif
#endif

#include "tooie_game.h"

namespace fs = std::filesystem;

namespace {
    // Kept as plain buffers so the handlers do as little allocation as possible.
    char logs_dir[1024];
    char marker_path[1100];
    char crash_log_path[1100];
    std::atomic_flag crashing;

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

    void append_log_line(const char* line) {
        FILE* f = std::fopen(crash_log_path, "a");
        if (f) {
            std::fprintf(f, "%s\n", line);
            std::fclose(f);
        }
    }

    void remove_marker() {
        std::remove(marker_path);
    }

    void clean_exit() {
        remove_marker();
    }

#ifdef _WIN32
    // Best effort name of the function containing an address: the recompiled code is linked into the exe,
    // so func_80XXXXXX names come out of the PDB when it sits next to the exe.
    void describe_address(void* addr, char* out, size_t size) {
        HANDLE process = GetCurrentProcess();
        static bool initialized = false;
        if (!initialized) {
            SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS | SYMOPT_LOAD_LINES);
            SymInitialize(process, nullptr, TRUE);
            initialized = true;
        }
        alignas(SYMBOL_INFO) char buffer[sizeof(SYMBOL_INFO) + 256];
        SYMBOL_INFO* sym = reinterpret_cast<SYMBOL_INFO*>(buffer);
        std::memset(sym, 0, sizeof(buffer));
        sym->SizeOfStruct = sizeof(SYMBOL_INFO);
        sym->MaxNameLen = 255;
        DWORD64 displacement = 0;
        if (SymFromAddr(process, reinterpret_cast<DWORD64>(addr), &displacement, sym)) {
            std::snprintf(out, size, "%s+0x%llx", sym->Name, static_cast<unsigned long long>(displacement));
        } else {
            HMODULE module = nullptr;
            GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                reinterpret_cast<LPCSTR>(addr), &module);
            std::snprintf(out, size, "exe+0x%llx (no symbol)",
                static_cast<unsigned long long>(reinterpret_cast<uintptr_t>(addr) - reinterpret_cast<uintptr_t>(module)));
        }
    }

    void write_crash(const char* reason, EXCEPTION_POINTERS* ep) {
        if (crashing.test_and_set()) {
            return;
        }
        char ts[32];
        timestamp(ts, sizeof(ts));

        char where[400] = "unknown";
        if (ep && ep->ExceptionRecord) {
            describe_address(ep->ExceptionRecord->ExceptionAddress, where, sizeof(where));
        }

        char dump_name[1200];
        std::snprintf(dump_name, sizeof(dump_name), "%s\\crash_%s.dmp", logs_dir, ts);
        bool dumped = false;
        HANDLE file = CreateFileA(dump_name, GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
        if (file != INVALID_HANDLE_VALUE) {
            MINIDUMP_EXCEPTION_INFORMATION info{};
            info.ThreadId = GetCurrentThreadId();
            info.ExceptionPointers = ep;
            info.ClientPointers = FALSE;
            dumped = MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), file, MiniDumpWithDataSegs,
                ep ? &info : nullptr, nullptr, nullptr) != FALSE;
            CloseHandle(file);
        }

        char line[1900];
        std::snprintf(line, sizeof(line), "%s crash: %s at %s (code 0x%08lx), dump: %s", ts, reason, where,
            ep && ep->ExceptionRecord ? static_cast<unsigned long>(ep->ExceptionRecord->ExceptionCode) : 0ul,
            dumped ? dump_name : "not written");
        append_log_line(line);
        // The crash is recorded, so the marker no longer means "died silently".
        remove_marker();
    }

    LONG WINAPI unhandled_exception_filter(EXCEPTION_POINTERS* ep) {
        write_crash("unhandled exception", ep);
        return EXCEPTION_EXECUTE_HANDLER;
    }

    // abort(), terminate, purecall and invalid-parameter have no exception record, so raise one to get a stack in the dump.
    void crash_via_exception(const char* reason, DWORD code) {
        __try {
            RaiseException(code, EXCEPTION_NONCONTINUABLE, 0, nullptr);
        } __except (write_crash(reason, GetExceptionInformation()), EXCEPTION_EXECUTE_HANDLER) {
        }
        TerminateProcess(GetCurrentProcess(), 3);
    }

    void on_abort(int) { crash_via_exception("abort()", 0xE0000001); }
    void on_terminate() { crash_via_exception("std::terminate", 0xE0000002); }
    void on_purecall() { crash_via_exception("pure virtual call", 0xE0000003); }
    void on_invalid_parameter(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, uintptr_t) {
        crash_via_exception("invalid CRT parameter", 0xE0000004);
    }

    void install_handlers() {
        SetUnhandledExceptionFilter(unhandled_exception_filter);
        std::signal(SIGABRT, on_abort);
        _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
        std::set_terminate(on_terminate);
        _set_purecall_handler(on_purecall);
        _set_invalid_parameter_handler(on_invalid_parameter);
    }
#else
    void on_signal(int sig) {
        if (!crashing.test_and_set()) {
            char ts[32];
            timestamp(ts, sizeof(ts));
            char line[256];
            std::snprintf(line, sizeof(line), "%s crash: signal %d (%s)", ts, sig, strsignal(sig));
            append_log_line(line);
#if defined(__GLIBC__)
            // Raw addresses and any exported symbols; recompiled functions appear as func_80XXXXXX when the symbols are available.
            int fd = open(crash_log_path, O_WRONLY | O_APPEND | O_CREAT, 0644);
            if (fd >= 0) {
                void* frames[64];
                int n = backtrace(frames, 64);
                backtrace_symbols_fd(frames, n, fd);
                close(fd);
            }
#endif
            remove_marker();
        }
        // Re-raise with the default action so the OS still produces its usual core/exit status.
        std::signal(sig, SIG_DFL);
        std::raise(sig);
    }

    void install_handlers() {
        // Run the handler on its own stack so stack overflows are reported too.
        static char alt_stack[64 * 1024];
        stack_t ss{};
        ss.ss_sp = alt_stack;
        ss.ss_size = sizeof(alt_stack);
        sigaltstack(&ss, nullptr);
        struct sigaction sa{};
        sa.sa_handler = on_signal;
        sa.sa_flags = SA_ONSTACK;
        sigemptyset(&sa.sa_mask);
        for (int sig : { SIGSEGV, SIGABRT, SIGBUS, SIGFPE, SIGILL }) {
            sigaction(sig, &sa, nullptr);
        }
    }
#endif
}

void tooie::install_crash_handler(const fs::path& app_folder) {
    std::error_code ec;
    fs::path logs = app_folder / "logs";
    fs::create_directories(logs, ec);
    std::snprintf(logs_dir, sizeof(logs_dir), "%s", logs.string().c_str());
    std::snprintf(marker_path, sizeof(marker_path), "%s/running.marker", logs_dir);
    std::snprintf(crash_log_path, sizeof(crash_log_path), "%s/crashes.log", logs_dir);

    // A marker left over from the last run, with no crash logged since, means the process died silently.
    if (fs::exists(marker_path, ec)) {
        char ts[32];
        timestamp(ts, sizeof(ts));
        char line[256];
        std::snprintf(line, sizeof(line), "%s previous run ended without a clean exit and without a crash report (killed, power loss or a hang)", ts);
        append_log_line(line);
    }
    {
        std::ofstream marker(marker_path);
        char ts[32];
        timestamp(ts, sizeof(ts));
        marker << "started " << ts << "\n";
    }
    std::atexit(clean_exit);
    install_handlers();
}
