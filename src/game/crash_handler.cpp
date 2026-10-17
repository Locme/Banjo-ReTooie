#include <atomic>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <cstring>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

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

#include "tooie_texture_sweep.h"
#include "tooie_game.h"

namespace fs = std::filesystem;

namespace {
    // Kept as plain buffers so the handlers do as little allocation as possible.
    char logs_dir[1024];
    char marker_path[1100];
    char crash_log_path[1100];
    std::atomic_flag crashing;

    // Build and settings for the crash log (set_crash_context). Two buffers so a crash never reads
    // one that is half written: the writer fills the idle one, then flips the index.
    char context[2][16384];
    std::atomic<int> context_index{0};

    // Minidumps are tens of MB each; older ones are deleted at start so these many are kept.
    constexpr size_t dumps_kept = 5;
    // Hang dumps (write_hang_dump) are kept apart from crash dumps, fewer of them.
    constexpr size_t hang_dumps_kept = 3;
    // Minidump stream type that holds the game's memory in a hang dump ("BTRD").
    constexpr uint32_t hang_rdram_stream = 0x44525442;

    // Deletes all but the newest `keep` logs/<prefix>*.dmp (names sort by date).
    void prune_dumps(const char* prefix, size_t keep) {
        std::error_code ec;
        std::vector<fs::path> dumps;
        for (const auto& entry : fs::directory_iterator(fs::path(logs_dir), ec)) {
            const std::string name = entry.path().filename().string();
            if (name.rfind(prefix, 0) == 0 && entry.path().extension() == ".dmp") {
                dumps.push_back(entry.path());
            }
        }
        std::sort(dumps.begin(), dumps.end());
        for (size_t i = 0; i + keep < dumps.size(); i++) {
            fs::remove(dumps[i], ec);
        }
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

    // Everything written for this crash, also stored inside the minidump so the .dmp alone is enough.
    char report[65536];
    size_t report_len = 0;

    void add_to_report(const char* text) {
        size_t n = std::strlen(text);
        if (report_len + n < sizeof(report)) {
            std::memcpy(report + report_len, text, n);
            report_len += n;
            report[report_len] = '\0';
        }
    }

    void append_log_line(const char* line) {
        add_to_report(line);
        add_to_report("\n");
        FILE* f = std::fopen(crash_log_path, "a");
        if (f) {
            std::fprintf(f, "%s\n", line);
            std::fclose(f);
        }
    }

    // The build and settings, each line indented under the crash line.
    void append_context() {
        const char* text = context[context_index.load()];
        FILE* f = std::fopen(crash_log_path, "a");
        if (!f) {
            return;
        }
        bool line_start = true;
        for (const char* c = text; *c != '\0'; c++) {
            if (line_start) {
                std::fputs("    ", f);
                add_to_report("    ");
            }
            std::fputc(*c, f);
            char one[2] = { *c, '\0' };
            add_to_report(one);
            line_start = *c == '\n';
        }
        if (!line_start) {
            std::fputc('\n', f);
            add_to_report("\n");
        }
        std::fclose(f);
    }

    void remove_marker() {
        std::remove(marker_path);
    }

    void clean_exit() {
        remove_marker();
    }

#ifdef _WIN32
    // DbgHelp is single threaded and the hang watchdog uses it too (describe_code_address, write_hang_dump).
    // A crash waits a little for the watchdog to finish, then goes ahead anyway.
    std::atomic_flag dbghelp_busy;

    struct DbgHelpLock {
        bool held = false;
        explicit DbgHelpLock(int wait_ms) {
            for (int waited = 0; ; waited++) {
                if (!dbghelp_busy.test_and_set()) {
                    held = true;
                    return;
                }
                if (waited >= wait_ms) {
                    return;
                }
                Sleep(1);
            }
        }
        ~DbgHelpLock() {
            if (held) {
                dbghelp_busy.clear();
            }
        }
    };

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
        // Module and offset always, so a dump can be matched to the build's PDB later.
        HMODULE module = nullptr;
        char module_name[MAX_PATH] = "?";
        if (GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                reinterpret_cast<LPCSTR>(addr), &module) && module != nullptr) {
            char path[MAX_PATH];
            if (GetModuleFileNameA(module, path, sizeof(path)) > 0) {
                const char* slash = std::strrchr(path, '\\');
                std::snprintf(module_name, sizeof(module_name), "%s", slash ? slash + 1 : path);
            }
        }
        unsigned long long offset = reinterpret_cast<uintptr_t>(addr) - reinterpret_cast<uintptr_t>(module);
        DWORD64 displacement = 0;
        if (SymFromAddr(process, reinterpret_cast<DWORD64>(addr), &displacement, sym)) {
            std::snprintf(out, size, "%s+0x%llx (%s+0x%llx)", sym->Name, static_cast<unsigned long long>(displacement),
                module_name, offset);
        } else {
            std::snprintf(out, size, "%s+0x%llx (no symbol)", module_name, offset);
        }
    }

    // The last C++ exception thrown, kept so a crash from an uncaught one (std::terminate, which MSVC turns
    // into abort() on threads other than main) can say what it was.
    char last_cpp_exception[600];

    // MSVC throws C++ exceptions as SEH exception 0xE06D7363. Its parameters point at the thrown object
    // and its ThrowInfo, whose catchable-type list names every type the object can be caught as.
    LONG WINAPI note_cpp_exception(EXCEPTION_POINTERS* ep) {
        const EXCEPTION_RECORD* rec = ep->ExceptionRecord;
        if (rec->ExceptionCode != 0xE06D7363 || rec->NumberParameters < 4) {
            return EXCEPTION_CONTINUE_SEARCH;
        }
        __try {
            const void* object = reinterpret_cast<const void*>(rec->ExceptionInformation[1]);
            const uint8_t* throw_info = reinterpret_cast<const uint8_t*>(rec->ExceptionInformation[2]);
            const uint8_t* image = reinterpret_cast<const uint8_t*>(rec->ExceptionInformation[3]);
            // ThrowInfo: attributes, pmfnUnwind, pForwardCompat, pCatchableTypeArray (32-bit image offsets).
            const int32_t* types = reinterpret_cast<const int32_t*>(image + reinterpret_cast<const int32_t*>(throw_info)[3]);
            int count = types[0];
            const char* first_name = "?";
            bool is_std_exception = false;
            for (int i = 0; i < count; i++) {
                // CatchableType: properties, pType (TypeDescriptor offset), ...; the name is at TypeDescriptor + 16.
                const int32_t* catchable = reinterpret_cast<const int32_t*>(image + types[1 + i]);
                const char* name = reinterpret_cast<const char*>(image + catchable[1] + 16);
                if (i == 0) {
                    first_name = name;
                }
                if (std::strcmp(name, ".?AVexception@std@@") == 0) {
                    is_std_exception = true;
                }
            }
            std::snprintf(last_cpp_exception, sizeof(last_cpp_exception), "%s: %s", first_name,
                is_std_exception ? static_cast<const std::exception*>(object)->what() : "(not a std::exception)");
        } __except (EXCEPTION_EXECUTE_HANDLER) {
        }
        return EXCEPTION_CONTINUE_SEARCH;
    }

    // The crashing thread's stack, one function per line, for the crash log. Unwound from the
    // exception's own context when there is one, so it starts at the faulting instruction.
    USHORT walk_stack(EXCEPTION_POINTERS* ep, void** frames, USHORT max) {
        if (ep == nullptr || ep->ContextRecord == nullptr) {
            return CaptureStackBackTrace(0, max, frames, nullptr);
        }
        CONTEXT ctx = *ep->ContextRecord;
        USHORT n = 0;
        __try {
            while (n < max && ctx.Rip != 0) {
                frames[n++] = reinterpret_cast<void*>(ctx.Rip);
                DWORD64 image_base = 0;
                PRUNTIME_FUNCTION entry = RtlLookupFunctionEntry(ctx.Rip, &image_base, nullptr);
                if (entry == nullptr) {
                    // Leaf function: the return address is on top of the stack.
                    ctx.Rip = *reinterpret_cast<DWORD64*>(ctx.Rsp);
                    ctx.Rsp += 8;
                } else {
                    void* handler_data = nullptr;
                    DWORD64 establisher = 0;
                    RtlVirtualUnwind(UNW_FLAG_NHANDLER, image_base, ctx.Rip, entry, &ctx, &handler_data, &establisher, nullptr);
                }
            }
        } __except (EXCEPTION_EXECUTE_HANDLER) {
        }
        return n;
    }

    void append_backtrace(EXCEPTION_POINTERS* ep) {
        void* frames[48];
        USHORT n = walk_stack(ep, frames, 48);
        for (USHORT i = 0; i < n; i++) {
            char name[400];
            describe_address(frames[i], name, sizeof(name));
            char line[460];
            std::snprintf(line, sizeof(line), "    %2u %s", i, name);
            append_log_line(line);
        }
    }

    void write_crash(const char* reason, EXCEPTION_POINTERS* ep) {
        if (crashing.test_and_set()) {
            return;
        }
        DbgHelpLock dbghelp(2000);
        char ts[32];
        timestamp(ts, sizeof(ts));

        char where[400] = "unknown";
        if (ep && ep->ExceptionRecord) {
            describe_address(ep->ExceptionRecord->ExceptionAddress, where, sizeof(where));
        }

        char dump_name[1200];
        std::snprintf(dump_name, sizeof(dump_name), "%s\\crash_%s.dmp", logs_dir, ts);

        // The log first, so the same text can go inside the dump.
        char line[1900];
        std::snprintf(line, sizeof(line), "%s crash: %s at %s (code 0x%08lx), dump: %s", ts, reason, where,
            ep && ep->ExceptionRecord ? static_cast<unsigned long>(ep->ExceptionRecord->ExceptionCode) : 0ul,
            dump_name);
        append_log_line(line);
        append_context();
        if (last_cpp_exception[0] != '\0') {
            std::snprintf(line, sizeof(line), "    last C++ exception thrown: %s", last_cpp_exception);
            append_log_line(line);
        }
        append_backtrace(ep);

        bool dumped = false;
        HANDLE file = CreateFileA(dump_name, GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
        if (file != INVALID_HANDLE_VALUE) {
            MINIDUMP_EXCEPTION_INFORMATION info{};
            info.ThreadId = GetCurrentThreadId();
            info.ExceptionPointers = ep;
            info.ClientPointers = FALSE;
            // The crash log rides along as the dump's comment, readable with any minidump tool.
            MINIDUMP_USER_STREAM comment{};
            comment.Type = CommentStreamA;
            comment.BufferSize = static_cast<ULONG>(report_len + 1);
            comment.Buffer = report;
            MINIDUMP_USER_STREAM_INFORMATION streams{};
            streams.UserStreamCount = 1;
            streams.UserStreamArray = &comment;
            dumped = MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), file,
                static_cast<MINIDUMP_TYPE>(MiniDumpWithDataSegs | MiniDumpWithIndirectlyReferencedMemory),
                ep ? &info : nullptr, &streams, nullptr) != FALSE;
            CloseHandle(file);
        }
        if (!dumped) {
            append_log_line("    (the dump could not be written)");
        }
        // The crash is recorded, so the marker no longer means "died silently".
        remove_marker();
        // A texture sweep with "pass over crashes" on starts the game again and carries on.
        if (tooie::texture_sweep::pass_over_active()) {
            const char* dump_file = std::strrchr(dump_name, '\\');
            char why[1400];
            std::snprintf(why, sizeof(why), "crash at %s (%s), dump %s", where, reason, dumped ? (dump_file ? dump_file + 1 : dump_name) : "not written");
            if (tooie::texture_sweep::pass_over(why)) {
                append_log_line("    texture sweep: passed over, the game was started again");
            }
        }
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
        AddVectoredExceptionHandler(1, note_cpp_exception);
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
            append_context();
            if (tooie::texture_sweep::pass_over_active()) {
                char why[160];
                std::snprintf(why, sizeof(why), "crash: signal %d (%s)", sig, strsignal(sig));
                tooie::texture_sweep::pass_over(why);
            }
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

#ifdef _WIN32
void tooie::describe_code_address(void* addr, char* out, size_t size) {
    DbgHelpLock dbghelp(5000);
    describe_address(addr, out, size);
}

std::string tooie::write_hang_dump(const std::string& report_text, const uint8_t* rdram, size_t rdram_size) {
    prune_dumps("hang_", hang_dumps_kept - 1);
    char ts[32];
    timestamp(ts, sizeof(ts));
    char dump_name[1200];
    std::snprintf(dump_name, sizeof(dump_name), "%s\\hang_%s.dmp", logs_dir, ts);
    HANDLE file = CreateFileA(dump_name, GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (file == INVALID_HANDLE_VALUE) {
        return {};
    }
    // The hang report rides along as the dump's comment, like a crash log (tools/read_dump.py prints it).
    std::string comment = report_text;
    MINIDUMP_USER_STREAM stream[2]{};
    stream[0].Type = CommentStreamA;
    stream[0].BufferSize = static_cast<ULONG>(comment.size() + 1);
    stream[0].Buffer = comment.data();
    // The game's memory as the recompiled code holds it (32-bit words in host order), so the game's
    // state at the hang can be read back. The type is any number above the reserved ones.
    stream[1].Type = hang_rdram_stream;
    stream[1].BufferSize = static_cast<ULONG>(rdram != nullptr ? rdram_size : 0);
    stream[1].Buffer = const_cast<uint8_t*>(rdram);
    MINIDUMP_USER_STREAM_INFORMATION streams{};
    streams.UserStreamCount = rdram != nullptr ? 2 : 1;
    streams.UserStreamArray = stream;
    bool dumped;
    {
        DbgHelpLock dbghelp(5000);
        // No exception: every other thread is suspended and saved with its own registers and stack.
        dumped = MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), file,
            static_cast<MINIDUMP_TYPE>(MiniDumpWithDataSegs | MiniDumpWithIndirectlyReferencedMemory | MiniDumpWithThreadInfo),
            nullptr, &streams, nullptr) != FALSE;
    }
    CloseHandle(file);
    if (!dumped) {
        std::remove(dump_name);
        return {};
    }
    return dump_name;
}
#else
void tooie::describe_code_address(void* addr, char* out, size_t size) {
    std::snprintf(out, size, "%p", addr);
}

std::string tooie::write_hang_dump(const std::string&, const uint8_t*, size_t) {
    return {};
}
#endif

void tooie::crash_log_line(const char* line) {
    if (crash_log_path[0] == '\0') {
        return;
    }
    FILE* f = std::fopen(crash_log_path, "a");
    if (f) {
        std::fprintf(f, "%s\n", line);
        std::fclose(f);
    }
}

void tooie::set_crash_context(const std::string& text) {
    int next = 1 - context_index.load();
    std::snprintf(context[next], sizeof(context[next]), "%s", text.c_str());
    context_index.store(next);
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
    // Keep room for this run's dump: delete all but the newest dumps_kept - 1 (names sort by date).
    prune_dumps("crash_", dumps_kept - 1);
    std::atexit(clean_exit);
    install_handlers();
}
