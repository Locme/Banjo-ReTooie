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
#include "tooie_game_frame_rate.h"
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
        // Game Frame Rate (the port's own Graphics option), by its saved key.
        std::string game_rate = "?";
        try {
            static const char* names[] = { "Original", "Fps30", "Fps60", "Fps120", "Uncapped", "Fps40", "Fps175", "Fps240" };
            uint32_t v = std::get<uint32_t>(recompui::config::get_graphics_config().get_option_value(tooie::game_frame_rate::option));
            game_rate = v < 8 ? names[v] : std::to_string(v);
        } catch (...) {
        }
        return "game frame rate " + game_rate +
            ", interpolation " + frame_rate +
            ", aspect ratio " + widescreen +
            ", HUD " + enum_name(config.hr_option) +
            ", renderer " + enum_name(config.api_option) +
            ", resolution " + enum_name(config.res_option) +
            ", downsampling " + std::to_string(config.ds_option) +
            ", MSAA " + enum_name(config.msaa_option) +
            ", window " + enum_name(config.wm_option) +
            ", high-precision framebuffer " + enum_name(config.hpfb_option);
    }

    // Kept to plain option values: passing nlohmann::json across from librecomp fails to link on Windows.
    std::string tab_line(const recomp::config::Config& config) {
        std::string out;
        for (const auto& option : config.get_config_schema().options) {
            const recomp::config::ConfigValueVariant value = config.get_option_value(option.id);
            std::string text;
            if (const uint32_t* v = std::get_if<uint32_t>(&value)) {
                text = std::to_string(*v);
                if (const auto* e = std::get_if<recomp::config::ConfigOptionEnum>(&option.variant)) {
                    auto it = e->find_option_from_value(*v);
                    if (it != e->options.end()) {
                        text = it->key;
                    }
                }
            } else if (const double* v = std::get_if<double>(&value)) {
                char buf[32];
                std::snprintf(buf, sizeof(buf), "%g", *v);
                text = buf;
            } else if (const bool* v = std::get_if<bool>(&value)) {
                text = *v ? "on" : "off";
            } else if (const std::string* v = std::get_if<std::string>(&value)) {
                text = "\"" + *v + "\"";
            }
            out += (out.empty() ? "" : ", ") + option.id + "=" + text;
        }
        return out;
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
                out += std::string(id) + ": " + tab_line(recompui::config::get_config(id)) + "\n";
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
#ifdef TOOIE_CPU_NAME
        ", for " TOOIE_CPU_NAME
#endif
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
