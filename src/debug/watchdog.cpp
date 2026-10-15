#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

#ifdef _WIN32
#include <Windows.h>
#include <TlHelp32.h>
#endif

#include "librecomp/game.hpp"

#include "tooie_frame_overlay.h"
#include "tooie_game.h"
#include "tooie_watchdog.h"

// Three parts of the program are watched, each by a counter that moves while that part is working:
//  - the game: a display list sent by the game threads. The screen keeps being refreshed every VI
//    even when the game is stuck (the VI thread repeats the last image), so only this shows a game
//    that loops or waits forever.
//  - the screen: a frame handed to RT64 by the graphics thread (also stops when RT64 or the driver blocks).
//  - the window: the main thread's event loop (input, menus, the window itself).
// When one stops moving, hangs.log gets a line saying which, the stacks of the program's threads
// (Windows), and, if it lasts, a minidump.
namespace {
    using namespace std::chrono_literals;
    using clock_type = std::chrono::steady_clock;

    constexpr auto poll_interval = 250ms;
    // A hang is written to the log after this long, and a minidump after dump_after.
    constexpr auto game_threshold = 3s;
    constexpr auto screen_threshold = 3s;
    // Longer: Windows holds the main thread while the window is dragged or a system dialog is open.
    constexpr auto window_threshold = 8s;
    constexpr auto dump_after = 15s;
    // Stack reports and dumps per run, so a game that keeps stalling cannot fill the disk.
    constexpr int max_reports = 10;
    constexpr int max_dumps = 2;

    struct Part {
        const char* name;
        const char* stopped;
        std::chrono::seconds threshold;
        std::atomic<uint64_t> count{0};
        // Watch-thread state.
        uint64_t last_count = 0;
        clock_type::time_point last_change{};
        bool armed = false;
        bool in_hang = false;
    };

    Part game_part{ "game", "the game sent no new frame (the game threads are stuck or waiting)", game_threshold };
    Part screen_part{ "screen", "no frame was presented (the graphics thread, RT64 or the driver is stuck)", screen_threshold };
    Part window_part{ "window", "the window stopped handling events (the main thread is stuck)", window_threshold };
    Part* const parts[] = { &game_part, &screen_part, &window_part };

    // What the renderer reports, for the frame rate overlay.
    std::atomic<int> reported_api{(int)ultramodern::renderer::GraphicsApi::Auto};
    std::atomic<float> reported_scale{0.0f};
    std::atomic<uint32_t> reported_rate{0};
    std::once_flag start_once;
    clock_type::time_point process_start = clock_type::now();

#ifdef _WIN32
    std::atomic<DWORD> window_thread_id{0};
#endif

    std::string wall_time() {
        std::time_t t = std::time(nullptr);
        std::tm tm_buf{};
#ifdef _WIN32
        localtime_s(&tm_buf, &t);
#else
        localtime_r(&t, &tm_buf);
#endif
        char buf[32];
        std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tm_buf);
        return buf;
    }

    void log_text(const std::string& text) {
        std::error_code ec;
        std::filesystem::path dir = recomp::get_config_path() / "logs";
        std::filesystem::create_directories(dir, ec);
        std::ofstream out(dir / "hangs.log", std::ios::app);
        if (out.good()) {
            out << text;
        }
    }

    double seconds_since(clock_type::time_point t, clock_type::time_point now) {
        return std::chrono::duration_cast<std::chrono::milliseconds>(now - t).count() / 1000.0;
    }

    std::string seconds_text(double s) {
        char buf[32];
        std::snprintf(buf, sizeof(buf), "%.1f s", s);
        return buf;
    }

#ifdef _WIN32
    // Walks a suspended thread's stack from its saved registers. Kept free of C++ objects for __try.
    int walk_thread(HANDLE thread, void** frames, int max) {
#if defined(_M_X64) || defined(__x86_64__)
        CONTEXT ctx{};
        ctx.ContextFlags = CONTEXT_FULL;
        if (!GetThreadContext(thread, &ctx)) {
            return 0;
        }
        int n = 0;
        __try {
            while (n < max && ctx.Rip != 0) {
                frames[n++] = reinterpret_cast<void*>(ctx.Rip);
                DWORD64 old_rsp = ctx.Rsp;
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
                if (ctx.Rsp <= old_rsp && n > 1) {
                    break;
                }
            }
        } __except (EXCEPTION_EXECUTE_HANDLER) {
        }
        return n;
#else
        (void)thread; (void)frames; (void)max;
        return 0;
#endif
    }

    struct ThreadStack {
        DWORD id;
        std::string name;
        std::vector<void*> frames;
    };

    std::string thread_name(HANDLE thread, DWORD id) {
        std::string name;
        PWSTR wide = nullptr;
        if (SUCCEEDED(GetThreadDescription(thread, &wide)) && wide != nullptr) {
            int len = WideCharToMultiByte(CP_UTF8, 0, wide, -1, nullptr, 0, nullptr, nullptr);
            if (len > 1) {
                name.resize(len - 1);
                WideCharToMultiByte(CP_UTF8, 0, wide, -1, name.data(), len, nullptr, nullptr);
            }
            LocalFree(wide);
        }
        if (id == window_thread_id.load()) {
            name = name.empty() ? "Main (window) Thread" : name + " (window)";
        }
        return name;
    }

    // The stacks of the program's named threads (the game, VI, graphics, audio, RT64 threads and the main
    // thread). Unnamed ones are mostly driver and system pool threads. Each thread is paused only while
    // its registers and stack are read; names are looked up after it runs again.
    std::vector<ThreadStack> capture_stacks() {
        std::vector<ThreadStack> stacks;
        HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
        if (snapshot == INVALID_HANDLE_VALUE) {
            return stacks;
        }
        const DWORD self_process = GetCurrentProcessId();
        const DWORD self_thread = GetCurrentThreadId();
        THREADENTRY32 entry{};
        entry.dwSize = sizeof(entry);
        for (BOOL ok = Thread32First(snapshot, &entry); ok; ok = Thread32Next(snapshot, &entry)) {
            if (entry.th32OwnerProcessID != self_process || entry.th32ThreadID == self_thread) {
                continue;
            }
            HANDLE thread = OpenThread(THREAD_SUSPEND_RESUME | THREAD_GET_CONTEXT | THREAD_QUERY_LIMITED_INFORMATION, FALSE, entry.th32ThreadID);
            if (thread == nullptr) {
                continue;
            }
            ThreadStack stack;
            stack.id = entry.th32ThreadID;
            stack.name = thread_name(thread, stack.id);
            if (!stack.name.empty()) {
                void* frames[32];
                int n = 0;
                if (SuspendThread(thread) != (DWORD)-1) {
                    n = walk_thread(thread, frames, 32);
                    ResumeThread(thread);
                }
                stack.frames.assign(frames, frames + n);
                stacks.push_back(std::move(stack));
            }
            CloseHandle(thread);
        }
        CloseHandle(snapshot);
        return stacks;
    }

    std::string stacks_text() {
        std::string text;
        for (const ThreadStack& stack : capture_stacks()) {
            text += "    thread \"" + stack.name + "\" (id " + std::to_string(stack.id) + ")\n";
            for (size_t i = 0; i < stack.frames.size(); i++) {
                char name[400];
                tooie::describe_code_address(stack.frames[i], name, sizeof(name));
                char line[460];
                std::snprintf(line, sizeof(line), "        %2zu %s\n", i, name);
                text += line;
            }
        }
        return text;
    }
#else
    std::string stacks_text() {
        return "    (thread stacks are written on Windows only)\n";
    }
#endif

    // TOOIE_TEST_HANG=<part>:<at>:<for> stalls that part (game, screen or window) for <for> seconds once,
    // <at> seconds after the program started, so the watchdog can be checked without a real hang.
    struct TestHang {
        Part* part = nullptr;
        double at = 0.0;
        double length = 0.0;
        std::atomic_flag done;
    };
    TestHang test_hang;

    void parse_test_hang() {
        const char* env = std::getenv("TOOIE_TEST_HANG");
        if (env == nullptr) {
            return;
        }
        char name[16] = {};
        double at = 0.0, length = 0.0;
        if (std::sscanf(env, "%15[a-z]:%lf:%lf", name, &at, &length) != 3) {
            return;
        }
        for (Part* part : parts) {
            if (std::string(name) == part->name) {
                test_hang.part = part;
                test_hang.at = at;
                test_hang.length = length;
            }
        }
    }

    void test_hang_point(Part& part) {
        static std::once_flag parsed;
        std::call_once(parsed, parse_test_hang);
        if (test_hang.part != &part || seconds_since(process_start, clock_type::now()) < test_hang.at) {
            return;
        }
        if (!test_hang.done.test_and_set()) {
            std::printf("[watchdog] TOOIE_TEST_HANG: stalling the %s for %.1f s\n", part.name, test_hang.length);
            std::fflush(stdout);
            std::this_thread::sleep_for(std::chrono::milliseconds((long long)(test_hang.length * 1000.0)));
        }
    }

    void watch() {
        int reports = 0;
        int dumps = 0;
        // Set while any part is hung: the stacks are written once per episode, and the dump once.
        bool episode = false;
        bool episode_dumped = false;
        std::string episode_text;

        for (;;) {
            std::this_thread::sleep_for(poll_interval);
            auto now = clock_type::now();

            std::string started;
            for (Part* part : parts) {
                uint64_t count = part->count.load(std::memory_order_relaxed);
                if (count != part->last_count) {
                    if (part->in_hang) {
                        std::string line = wall_time() + " " + part->name + " running again after " + seconds_text(seconds_since(part->last_change, now)) + "\n";
                        log_text(line);
                        std::printf("[watchdog] %s", line.c_str());
                        part->in_hang = false;
                    }
                    part->last_count = count;
                    part->last_change = now;
                    // Armed by the first sign of life, so nothing is reported before a part has started.
                    part->armed = true;
                    continue;
                }
                if (part->armed && !part->in_hang && now - part->last_change >= part->threshold) {
                    part->in_hang = true;
                    started += wall_time() + " hang: " + part->stopped + " for " + seconds_text(seconds_since(part->last_change, now)) + "\n";
                }
            }

            bool any_hung = false;
            for (Part* part : parts) {
                any_hung |= part->in_hang;
            }
            if (!started.empty()) {
                std::string text = started;
                text += "    counters: game frames " + std::to_string(game_part.count.load()) + ", screen frames " + std::to_string(screen_part.count.load())
                    + ", window updates " + std::to_string(window_part.count.load()) + "\n";
                if (!episode && reports < max_reports) {
                    reports++;
                    text += stacks_text();
                }
                log_text(text);
                std::printf("[watchdog] %s", started.c_str());
                std::fflush(stdout);
                episode_text += text;
                episode = true;
            }

            // Still stuck well after it was reported: save a minidump of the whole program as it is.
            if (episode && any_hung && !episode_dumped && dumps < max_dumps) {
                bool long_enough = false;
                for (Part* part : parts) {
                    long_enough |= part->in_hang && now - part->last_change >= dump_after;
                }
                if (long_enough) {
                    episode_dumped = true;
                    std::string path = tooie::write_hang_dump(episode_text);
                    if (!path.empty()) {
                        dumps++;
                        log_text(wall_time() + " still hung; dump: " + path + "\n");
                    }
                }
            }

            if (!any_hung && episode) {
                episode = false;
                episode_dumped = false;
                episode_text.clear();
            }
        }
    }

    class WatchedRenderer final : public ultramodern::renderer::RendererContext {
    public:
        explicit WatchedRenderer(std::unique_ptr<ultramodern::renderer::RendererContext> inner) : inner(std::move(inner)) {}

        bool valid() override { return inner->valid(); }
        ultramodern::renderer::SetupResult get_setup_result() const override { return inner->get_setup_result(); }
        ultramodern::renderer::GraphicsApi get_chosen_api() const override { return inner->get_chosen_api(); }
        bool update_config(const ultramodern::renderer::GraphicsConfig& old_config, const ultramodern::renderer::GraphicsConfig& new_config) override {
            return inner->update_config(old_config, new_config);
        }
        void enable_instant_present() override { inner->enable_instant_present(); }
        void send_dl(const OSTask* task) override {
            inner->send_dl(task);
            game_part.count.fetch_add(1, std::memory_order_relaxed);
        }
        void send_dummy_workload(uint32_t fb_address) override { inner->send_dummy_workload(fb_address); }
        void update_screen() override {
            test_hang_point(screen_part);
            // Hands RT64 the controller read the new frame was made from (input latency).
            tooie::frame_overlay::note_screen_update();
            inner->update_screen();
            screen_part.count.fetch_add(1, std::memory_order_relaxed);
            reported_api.store((int)inner->get_chosen_api(), std::memory_order_relaxed);
            reported_scale.store(inner->get_resolution_scale(), std::memory_order_relaxed);
            reported_rate.store(inner->get_display_framerate(), std::memory_order_relaxed);
        }
        void shutdown() override { inner->shutdown(); }
        uint32_t get_display_framerate() const override { return inner->get_display_framerate(); }
        float get_resolution_scale() const override { return inner->get_resolution_scale(); }

    private:
        std::unique_ptr<ultramodern::renderer::RendererContext> inner;
    };
}

tooie::watchdog::RendererInfo tooie::watchdog::renderer_info() {
    RendererInfo info;
    info.api = (ultramodern::renderer::GraphicsApi)reported_api.load(std::memory_order_relaxed);
    info.resolution_scale = reported_scale.load(std::memory_order_relaxed);
    info.display_rate = reported_rate.load(std::memory_order_relaxed);
    return info;
}

void tooie::watchdog::start() {
    std::call_once(start_once, [] {
        // Detached: it only reads counters and appends to a log, so it can die with the process.
        std::thread(watch).detach();
    });
}

void tooie::watchdog::note_window_update() {
#ifdef _WIN32
    window_thread_id.store(GetCurrentThreadId(), std::memory_order_relaxed);
#endif
    test_hang_point(window_part);
    window_part.count.fetch_add(1, std::memory_order_relaxed);
}

void tooie::watchdog::note_game_input() {
    test_hang_point(game_part);
}

std::unique_ptr<ultramodern::renderer::RendererContext> tooie::watchdog::wrap(
    std::unique_ptr<ultramodern::renderer::RendererContext> inner) {
    if (!inner) {
        return inner;
    }
    return std::make_unique<WatchedRenderer>(std::move(inner));
}
