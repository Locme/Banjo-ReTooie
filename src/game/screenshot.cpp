// Screenshots (handoff 4.83).
//
// F12 asks RT64 for the next frame's game image (lib-patches/rt64.patch adds
// RT64::RequestScreenshot to its present queue). RT64 copies the image before
// it draws the menus and notices over it, so neither is ever in a screenshot.
// The image has the picture's shape: wide in Fill, 4:3 in 4:3. It is saved as
// screenshots/<date>_<time>.png in the app-data folder, on a thread of its own
// so the present thread is not held up by the PNG encoder.
//
// Holding F12 for half a second starts a burst: every presented frame is kept,
// shrunk to a quarter of its size, in a ring of the last 150 frames, and when
// the key is let go they are written to screenshots/burst-<date>_<time>/
// 000.png, 001.png, ... (oldest first). For glitches that last a frame or two:
// hold F12, play until one shows, let go.
//
// Headless test hooks: TOOIE_SCREENSHOT_AT=<ms>[,<ms>...] takes a screenshot
// at those times after the game started; TOOIE_BURST=<from ms>:<to ms> acts as
// F12 held over that window.

#include <algorithm>
#include <atomic>
#include <deque>
#include <chrono>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <functional>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include "librecomp/game.hpp"

#include "tooie_photo_mode.h"
#include "tooie_screenshot.h"
#include "tooie_toast.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_WRITE_STATIC
#include "../../lib/rt64/src/contrib/stb/stb_image_write.h"

namespace RT64 {
    // lib/rt64/src/hle/rt64_present_queue.h (from lib-patches/rt64.patch).
    typedef std::function<void(uint32_t width, uint32_t height, std::vector<uint8_t> &&rgba)> ScreenshotCallback;
    void RequestScreenshot(ScreenshotCallback callback);
}

namespace {
    namespace fs = std::filesystem;
    using namespace std::chrono_literals;

    constexpr auto poll_interval = 10ms;

    std::once_flag started;

    bool key_down() {
        const Uint8* keys = SDL_GetKeyboardState(nullptr);
        return keys != nullptr && keys[SDL_SCANCODE_F12] != 0;
    }

    // A file name from the local time, with a counter if two land in one second.
    fs::path next_path(const fs::path& folder) {
        std::time_t now = std::time(nullptr);
        std::tm local{};
#ifdef _WIN32
        localtime_s(&local, &now);
#else
        localtime_r(&now, &local);
#endif
        char stamp[32];
        std::strftime(stamp, sizeof(stamp), "%Y-%m-%d_%H-%M-%S", &local);
        fs::path path = folder / (std::string(stamp) + ".png");
        for (int i = 2; fs::exists(path); i++) {
            path = folder / (std::string(stamp) + "_" + std::to_string(i) + ".png");
        }
        return path;
    }

    void save(uint32_t width, uint32_t height, std::vector<uint8_t> rgba) {
        fs::path folder = recomp::get_config_path() / "screenshots";
        std::error_code ec;
        fs::create_directories(folder, ec);
        fs::path path = next_path(folder);

        // stbi_write_png takes a narrow path; write to memory and save it ourselves so
        // non-ASCII folder names work on Windows too.
        std::vector<uint8_t> png;
        auto append = [](void* context, void* data, int size) {
            auto* out = static_cast<std::vector<uint8_t>*>(context);
            out->insert(out->end(), static_cast<uint8_t*>(data), static_cast<uint8_t*>(data) + size);
        };
        bool encoded = stbi_write_png_to_func(append, &png, (int)width, (int)height, 4, rgba.data(), (int)width * 4) != 0;

        bool written = false;
        if (encoded) {
#ifdef _WIN32
            FILE* file = _wfopen(path.c_str(), L"wb");
#else
            FILE* file = std::fopen(path.c_str(), "wb");
#endif
            if (file != nullptr) {
                written = std::fwrite(png.data(), 1, png.size(), file) == png.size();
                written = (std::fclose(file) == 0) && written;
            }
        }

        if (written) {
            std::fprintf(stderr, "[screenshot] saved %s (%ux%u)\n", path.string().c_str(), width, height);
            tooie::toast::show("Screenshot saved");
        }
        else {
            std::fprintf(stderr, "[screenshot] could not save %s\n", path.string().c_str());
            tooie::toast::show("Screenshot not saved");
        }
    }

    // Burst (F12 held): the last frames, shrunk, oldest first.
    constexpr auto burst_hold = 500ms;
    constexpr size_t burst_frames = 150;
    constexpr uint32_t burst_shrink = 4;
    struct Small {
        uint32_t width;
        uint32_t height;
        std::vector<uint8_t> rgba;
    };
    std::atomic<bool> burst_on{false};
    std::mutex burst_mutex;
    std::deque<Small> burst_ring;

    // Shrinks an image by burst_shrink in each direction, averaging the pixels.
    Small shrink(uint32_t width, uint32_t height, const std::vector<uint8_t>& rgba) {
        Small out;
        out.width = std::max(1u, width / burst_shrink);
        out.height = std::max(1u, height / burst_shrink);
        out.rgba.resize((size_t)out.width * out.height * 4);
        const uint32_t n = burst_shrink * burst_shrink;
        for (uint32_t y = 0; y < out.height; y++) {
            for (uint32_t x = 0; x < out.width; x++) {
                uint32_t sum[4] = {0, 0, 0, 0};
                for (uint32_t dy = 0; dy < burst_shrink; dy++) {
                    const uint8_t* row = &rgba[((size_t)(y * burst_shrink + dy) * width + (size_t)x * burst_shrink) * 4];
                    for (uint32_t dx = 0; dx < burst_shrink; dx++) {
                        for (int c = 0; c < 4; c++) {
                            sum[c] += row[dx * 4 + c];
                        }
                    }
                }
                uint8_t* dst = &out.rgba[((size_t)y * out.width + x) * 4];
                for (int c = 0; c < 4; c++) {
                    dst[c] = (uint8_t)(sum[c] / n);
                }
            }
        }
        return out;
    }

    void burst_request();

    void burst_frame(uint32_t width, uint32_t height, std::vector<uint8_t>&& rgba) {
        if (!burst_on.load()) {
            return;
        }
        Small small = shrink(width, height, rgba);
        {
            std::lock_guard<std::mutex> lock(burst_mutex);
            burst_ring.push_back(std::move(small));
            while (burst_ring.size() > burst_frames) {
                burst_ring.pop_front();
            }
        }
        burst_request();
    }

    void burst_request() {
        RT64::RequestScreenshot([](uint32_t width, uint32_t height, std::vector<uint8_t>&& rgba) {
            burst_frame(width, height, std::move(rgba));
        });
    }

    void burst_save(std::deque<Small> frames) {
        fs::path folder = recomp::get_config_path() / "screenshots";
        std::error_code ec;
        fs::create_directories(folder, ec);
        fs::path stamped = next_path(folder);
        fs::path dir = folder / ("burst-" + stamped.stem().string());
        fs::create_directories(dir, ec);
        size_t written = 0;
        for (size_t i = 0; i < frames.size(); i++) {
            const Small& f = frames[i];
            char name[16];
            std::snprintf(name, sizeof(name), "%03zu.png", i);
            std::vector<uint8_t> png;
            auto append = [](void* context, void* data, int size) {
                auto* out = static_cast<std::vector<uint8_t>*>(context);
                out->insert(out->end(), static_cast<uint8_t*>(data), static_cast<uint8_t*>(data) + size);
            };
            if (stbi_write_png_to_func(append, &png, (int)f.width, (int)f.height, 4, f.rgba.data(), (int)f.width * 4) == 0) {
                continue;
            }
            fs::path path = dir / name;
#ifdef _WIN32
            FILE* file = _wfopen(path.c_str(), L"wb");
#else
            FILE* file = std::fopen(path.c_str(), "wb");
#endif
            if (file != nullptr) {
                if (std::fwrite(png.data(), 1, png.size(), file) == png.size()) {
                    written++;
                }
                std::fclose(file);
            }
        }
        std::fprintf(stderr, "[screenshot] burst: %zu of %zu frames saved in %s\n", written, frames.size(), dir.string().c_str());
        tooie::toast::show("Burst saved: " + std::to_string(written) + " frames");
    }

    void burst_begin() {
        {
            std::lock_guard<std::mutex> lock(burst_mutex);
            burst_ring.clear();
        }
        burst_on = true;
        tooie::toast::show("Burst: let go of F12 after the glitch");
        burst_request();
    }

    void burst_end() {
        burst_on = false;
        std::deque<Small> frames;
        {
            std::lock_guard<std::mutex> lock(burst_mutex);
            frames.swap(burst_ring);
        }
        std::thread(burst_save, std::move(frames)).detach();
    }

    // TOOIE_BURST=<from ms>:<to ms>
    bool parse_burst_window(long& from, long& to) {
        const char* v = std::getenv("TOOIE_BURST");
        if (v == nullptr) {
            return false;
        }
        return std::sscanf(v, "%ld:%ld", &from, &to) == 2;
    }

    std::vector<long> parse_test_times() {
        std::vector<long> times;
        if (const char* v = std::getenv("TOOIE_SCREENSHOT_AT")) {
            std::stringstream list(v);
            std::string item;
            while (std::getline(list, item, ',')) {
                times.push_back(std::strtol(item.c_str(), nullptr, 10));
            }
        }
        return times;
    }

    void worker() {
        std::vector<long> test_times = parse_test_times();
        size_t next_test = 0;
        auto begin = std::chrono::steady_clock::now();
        bool was_down = false;
        bool bursting = false;
        std::chrono::steady_clock::time_point down_since;
        long burst_from = 0, burst_to = 0;
        const bool burst_test = parse_burst_window(burst_from, burst_to);
        for (;;) {
            std::this_thread::sleep_for(poll_interval);
            auto now = std::chrono::steady_clock::now();
            bool down = key_down();
            if (burst_test) {
                long ms = (long)std::chrono::duration_cast<std::chrono::milliseconds>(now - begin).count();
                down = down || (ms >= burst_from && ms < burst_to);
            }
            if (down && !was_down) {
                tooie::screenshot::take();
                down_since = now;
            }
            if (down && !bursting && now - down_since >= burst_hold) {
                bursting = true;
                burst_begin();
            }
            if (!down && bursting) {
                bursting = false;
                burst_end();
            }
            was_down = down;

            if (next_test < test_times.size()) {
                long ms = (long)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - begin).count();
                if (ms >= test_times[next_test]) {
                    next_test++;
                    tooie::screenshot::take();
                }
            }
        }
    }
}

void tooie::screenshot::take() {
    // Photo mode's crop: keep only the frame, the largest rectangle of that shape in the middle.
    const float crop = tooie::photo_mode::crop_aspect();
    RT64::RequestScreenshot([crop](uint32_t width, uint32_t height, std::vector<uint8_t>&& rgba) {
        if (crop > 0.0f && width > 0 && height > 0) {
            uint32_t w = width, h = height;
            if (crop < (float)width / (float)height) {
                w = std::max(1u, (uint32_t)((float)height * crop + 0.5f));
            }
            else {
                h = std::max(1u, (uint32_t)((float)width / crop + 0.5f));
            }
            const uint32_t x0 = (width - w) / 2, y0 = (height - h) / 2;
            std::vector<uint8_t> cropped((size_t)w * h * 4);
            for (uint32_t y = 0; y < h; y++) {
                std::memcpy(&cropped[(size_t)y * w * 4], &rgba[((size_t)(y0 + y) * width + x0) * 4], (size_t)w * 4);
            }
            std::thread(save, w, h, std::move(cropped)).detach();
            return;
        }
        std::thread(save, width, height, std::move(rgba)).detach();
    });
}

void tooie::screenshot::start() {
    std::call_once(started, [] {
        std::thread(worker).detach();
    });
}
