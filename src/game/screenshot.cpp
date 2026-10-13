// Screenshots (handoff 4.83).
//
// F12 asks RT64 for the next frame's game image (lib-patches/rt64.patch adds
// RT64::RequestScreenshot to its present queue). RT64 copies the image before
// it draws the menus and notices over it, so neither is ever in a screenshot.
// The image has the picture's shape: wide in Fill, 4:3 in 4:3. It is saved as
// screenshots/<date>_<time>.png in the app-data folder, on a thread of its own
// so the present thread is not held up by the PNG encoder.
//
// Headless test hook: TOOIE_SCREENSHOT_AT=<ms>[,<ms>...] takes a screenshot
// at those times after the game started.

#include <chrono>
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

#include "SDL2/SDL.h"

#include "librecomp/game.hpp"

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
        for (;;) {
            std::this_thread::sleep_for(poll_interval);
            bool down = key_down();
            if (down && !was_down) {
                tooie::screenshot::take();
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
    RT64::RequestScreenshot([](uint32_t width, uint32_t height, std::vector<uint8_t>&& rgba) {
        std::thread(save, width, height, std::move(rgba)).detach();
    });
}

void tooie::screenshot::start() {
    std::call_once(started, [] {
        std::thread(worker).detach();
    });
}
