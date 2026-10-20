// Headless settings script: TOOIE_SET="<ms>:<option>=<value>[,<option>=<value>...];<ms>:..."
// changes Graphics (or Sound, or Cheats) options at those times after the game started, the same way
// the menu does (set_option_value, which saves and applies them at once), so a
// run can switch settings live without anyone at the keyboard. Enum options take
// the index of their choice (game_frame_rate: 0 Original, 1 30 FPS, 2 60 FPS, 3 120 FPS, 4 Unlocked;
// rr_option, Interpolation: 0 Off, 1 Display, 2 Manual), number options a number.
// Each change is logged as "[set] ...".

#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <variant>
#include <vector>

#include "recompui/config.h"

#include "tooie_cheats.h"
#include "tooie_game.h"

namespace {
    struct Change {
        long ms = 0;
        std::string option;
        double value = 0.0;
    };

    std::vector<Change> parse(const char* text) {
        std::vector<Change> changes;
        std::stringstream steps{ text };
        std::string step;
        while (std::getline(steps, step, ';')) {
            size_t colon = step.find(':');
            if (colon == std::string::npos) {
                continue;
            }
            long ms = std::strtol(step.substr(0, colon).c_str(), nullptr, 10);
            std::stringstream sets{ step.substr(colon + 1) };
            std::string set;
            while (std::getline(sets, set, ',')) {
                size_t eq = set.find('=');
                if (eq != std::string::npos) {
                    changes.push_back({ ms, set.substr(0, eq), std::strtod(set.substr(eq + 1).c_str(), nullptr) });
                }
            }
        }
        return changes;
    }

    void apply(const Change& c) {
        try {
            // Graphics options, or Sound ones (mix_rate) or Cheats ones when Graphics has no such option.
            recomp::config::Config* config = &recompui::config::get_graphics_config();
            if (!config->has_option(c.option) && recompui::config::get_sound_config().has_option(c.option)) {
                config = &recompui::config::get_sound_config();
            } else if (!config->has_option(c.option) && tooie::cheats::config().has_option(c.option)) {
                config = &tooie::cheats::config();
            }
            recomp::config::Config& graphics = *config;
            recomp::config::ConfigValueVariant current = graphics.get_option_value(c.option);
            if (std::holds_alternative<uint32_t>(current)) {
                graphics.set_option_value(c.option, (uint32_t)c.value);
            } else if (std::holds_alternative<bool>(current)) {
                graphics.set_option_value(c.option, c.value != 0.0);
            } else {
                graphics.set_option_value(c.option, c.value);
            }
            // The Graphics tab saves on every change in the menu (no Apply button); do the same here.
            graphics.save_config();
            std::printf("[set] %ld ms: %s = %g\n", c.ms, c.option.c_str(), c.value);
        } catch (...) {
            std::printf("[set] %ld ms: %s not found\n", c.ms, c.option.c_str());
        }
        std::fflush(stdout);
    }
}

void tooie::start_settings_script() {
    static std::once_flag once;
    std::call_once(once, [] {
        const char* text = std::getenv("TOOIE_SET");
        if (text == nullptr) {
            return;
        }
        std::thread([changes = parse(text)] {
            auto begin = std::chrono::steady_clock::now();
            for (const Change& c : changes) {
                std::this_thread::sleep_until(begin + std::chrono::milliseconds(c.ms));
                apply(c);
            }
        }).detach();
    });
}
