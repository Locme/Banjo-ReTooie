#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <mutex>
#include <string>
#include <thread>

#include "librecomp/game.hpp"

#include "tooie_watchdog.h"

namespace {
    using namespace std::chrono_literals;
    using clock_type = std::chrono::steady_clock;

    constexpr auto hang_threshold = 5s;
    constexpr auto poll_interval = 250ms;

    std::atomic<uint64_t> frames_presented{0};
    std::once_flag start_once;

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

    void log_line(const std::string& line) {
        std::error_code ec;
        std::filesystem::path dir = recomp::get_config_path() / "logs";
        std::filesystem::create_directories(dir, ec);
        std::ofstream out(dir / "hangs.log", std::ios::app);
        if (out.good()) {
            out << line << "\n";
        }
    }

    void watch() {
        uint64_t last_count = 0;
        auto last_change = clock_type::now();
        bool armed = false;
        bool in_hang = false;

        for (;;) {
            std::this_thread::sleep_for(poll_interval);
            uint64_t count = frames_presented.load(std::memory_order_relaxed);
            auto now = clock_type::now();

            if (count != last_count) {
                if (in_hang) {
                    auto stalled = std::chrono::duration_cast<std::chrono::milliseconds>(now - last_change).count();
                    log_line(wall_time() + " game presenting again after " + std::to_string(stalled / 1000.0) + " s (frame " + std::to_string(count) + ")");
                    in_hang = false;
                }
                last_count = count;
                last_change = now;
                armed = true;
                continue;
            }

            if (armed && !in_hang && now - last_change >= hang_threshold) {
                in_hang = true;
                log_line(wall_time() + " no frame presented for " + std::to_string(std::chrono::duration_cast<std::chrono::seconds>(now - last_change).count())
                    + " s; last frame number " + std::to_string(last_count) + "; running game thread: not available");
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
        void send_dl(const OSTask* task) override { inner->send_dl(task); }
        void send_dummy_workload(uint32_t fb_address) override { inner->send_dummy_workload(fb_address); }
        void update_screen() override {
            inner->update_screen();
            frames_presented.fetch_add(1, std::memory_order_relaxed);
        }
        void shutdown() override { inner->shutdown(); }
        uint32_t get_display_framerate() const override { return inner->get_display_framerate(); }
        float get_resolution_scale() const override { return inner->get_resolution_scale(); }

    private:
        std::unique_ptr<ultramodern::renderer::RendererContext> inner;
    };
}

void tooie::watchdog::start() {
    std::call_once(start_once, [] {
        // Detached: it only reads a counter and appends to a log, so it can die with the process.
        std::thread(watch).detach();
    });
}

std::unique_ptr<ultramodern::renderer::RendererContext> tooie::watchdog::wrap(
    std::unique_ptr<ultramodern::renderer::RendererContext> inner) {
    if (!inner) {
        return inner;
    }
    return std::make_unique<WatchedRenderer>(std::move(inner));
}
