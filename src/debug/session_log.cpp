#include <chrono>
#include <cstdio>
#include <exception>
#include <string>
#include <thread>

#include "build_info.h"
#include "recompui/config.h"
#include "recompui/recompui.h"
#include "ultramodern/config.hpp"
#include "ultramodern/ultramodern.hpp"

#include "tooie_game.h"
#include "tooie_session_log.h"

namespace {
    std::string build_line;

    template <typename T>
    std::string enum_name(T value) {
        nlohmann::json j = value;
        return j.is_string() ? j.get<std::string>() : j.dump();
    }

    // with_fps adds the measured frame-rate target, which can move by a few fps, so it is left
    // out when deciding whether the settings changed.
    std::string graphics_line(bool with_fps) {
        const auto& config = ultramodern::renderer::get_graphics_config();
        int width = 0;
        int height = 0;
        recompui::get_window_size(width, height);
        char widescreen[96];
        std::snprintf(widescreen, sizeof(widescreen), "%s (3D %.2fx as wide as 4:3, window %dx%d)",
            enum_name(config.ar_option).c_str(), tooie::widescreen_scale(), width, height);
        std::string frame_rate = enum_name(config.rr_option);
        if (config.rr_option == ultramodern::renderer::RefreshRate::Manual) {
            frame_rate += " " + std::to_string(config.rr_manual_value);
        }
        if (with_fps) {
            frame_rate += " (target " + std::to_string(ultramodern::get_target_framerate(30)) + " fps)";
        }
        return "frame rate " + frame_rate +
            ", aspect ratio " + widescreen +
            ", HUD " + enum_name(config.hr_option) +
            ", renderer " + enum_name(config.api_option) +
            ", resolution " + enum_name(config.res_option) +
            ", downsampling " + std::to_string(config.ds_option) +
            ", MSAA " + enum_name(config.msaa_option) +
            ", window " + enum_name(config.wm_option) +
            ", high-precision framebuffer " + enum_name(config.hpfb_option);
    }

    std::string describe(bool with_fps) {
        std::string out = "build: " + build_line + "\n";
        try {
            out += "graphics: " + graphics_line(with_fps) + "\n";
        } catch (const std::exception& e) {
            out += std::string("graphics: not available (") + e.what() + ")\n";
        }
        // The other tabs as stored, option id = value.
        for (const char* id : { "general", "qol", "cheats", "sound" }) {
            try {
                out += std::string(id) + ": " + recompui::config::get_config(id).get_json_config().dump() + "\n";
            } catch (const std::exception&) {
                // Tab not created in this build.
            }
        }
        return out;
    }

    // Prints the lines of now that are not in last.
    void print_changes(const std::string& last, const std::string& now) {
        size_t pos = 0;
        while (pos < now.size()) {
            size_t end = now.find('\n', pos);
            std::string line = now.substr(pos, end - pos + 1);
            if (last.find(line) == std::string::npos) {
                std::printf("Setting changed: %s", line.c_str());
            }
            pos = end + 1;
        }
    }

    void watch() {
        std::string last;
        for (;;) {
            std::string now = describe(false);
            if (last.empty()) {
                std::printf("Settings in effect:\n%s", now.c_str());
            } else if (now != last) {
                print_changes(last, now);
            }
            std::fflush(stdout);
            last = std::move(now);
            tooie::set_crash_context(describe(true));
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
}

void tooie::session_log::start(const std::string& version) {
    build_line = version + ", commit " TOOIE_GIT_COMMIT ", built " __DATE__ " " __TIME__
#ifdef NDEBUG
        ", release";
#else
        ", debug";
#endif
    std::printf("Banjo-Tooie N64 Recomp %s\n", build_line.c_str());
    tooie::set_crash_context("build: " + build_line + "\n");
    // Detached: it only reads settings and prints, so it can die with the process.
    std::thread(watch).detach();
}
