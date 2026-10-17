// Interpolation check (a debug aid for frame interpolation, handoff 4.15).
//
// Graphics > Debug switches it on and off, or F7 (rebindable in the Controls tab); a toast says which. While it is on,
// model_tagging.cpp tints a model red for about a third of a second when its
// blend between game frames looks wrong, and prints a line for it to the
// console (logs/console.log on Windows):
//   * jumped: it moved much further in one game frame than the frame before,
//     so the in-between frames smear it across the gap;
//   * bones not blended: some of its matrices could not be paired with last
//     frame's, so those parts move at the game's own rate.
// Only frame rates above Original blend, so it shows nothing at Original.
//
// Freeze (the Freeze key, or Freeze under the blend mode option) holds the game on two game frames
// (src/gameplay/save_state.cpp) so the blend mode can be switched while the same in-between frames
// are drawn again and again.
//
// Headless test hooks: TOOIE_INTERP_CHECK=1 starts with it on; TOOIE_BLEND_MODE=<0-5> picks the blend mode;
// TOOIE_FREEZE=<on ms>[:<off ms>] freezes and unfreezes at those times after the game started.

#include <atomic>
#include <chrono>
#include <cstdlib>
#include <mutex>
#include <string>
#include <thread>
#include <variant>
#include <vector>

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include "recompui/config.h"

#include "tooie_game.h"
#include "tooie_hotkeys.h"
#include "tooie_interp_check.h"
#include "tooie_save_state.h"
#include "tooie_toast.h"

namespace {
    using namespace std::chrono_literals;

    std::once_flag started;
    std::atomic<bool> on{false};
    // Starts in the custom mode (L, 2026-10-15).
    std::atomic<int> mode{5};
    constexpr int mode_count = 6;
    bool created = false;

    // Looked up each time: the tab list moves its configs as more tabs are added. The options live in the DEV tab.
    recomp::config::Config& graphics_config() {
        return recompui::config::get_config(tooie::wip_tab_id);
    }

    // Through the option when it exists, so the menu follows the key; its callback sets the atomic.
    void set_on(bool v) {
        if (created) {
            try {
                graphics_config().update_option_value(tooie::interp_check::check_option, v);
                return;
            } catch (...) {
            }
        }
        on = v;
    }

    void set_mode(int m) {
        m %= mode_count;
        if (created) {
            try {
                graphics_config().update_option_value(tooie::interp_check::blend_option, (uint32_t)m);
                return;
            } catch (...) {
            }
        }
        mode = m;
    }

    // Through the option when it exists, so the menu follows the key and the freeze ending by itself.
    void show_freeze(bool v) {
        if (created) {
            try {
                graphics_config().update_option_value(tooie::interp_check::freeze_option, v);
                return;
            } catch (...) {
            }
        }
        tooie::save_state::set_freeze(v);
    }

    void worker() {
        bool was_down = false;
        bool mode_was_down = false;
        bool freeze_was_down = false;
        bool freeze_shown = false;
        long freeze_on_ms = -1, freeze_off_ms = -1;
        if (const char* v = std::getenv("TOOIE_FREEZE"); v != nullptr) {
            char* end;
            freeze_on_ms = std::strtol(v, &end, 10);
            if (*end == ':') {
                freeze_off_ms = std::strtol(end + 1, nullptr, 10);
            }
        }
        const auto begin = std::chrono::steady_clock::now();
        for (;;) {
            std::this_thread::sleep_for(10ms);
            const long ms = (long)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - begin).count();
            bool freeze_down = tooie::hotkeys::down(recompinput::GameInput::FREEZE);
            if (freeze_down && !freeze_was_down) {
                show_freeze(!tooie::save_state::freeze_on());
            }
            freeze_was_down = freeze_down;
            if (freeze_on_ms >= 0 && ms >= freeze_on_ms) {
                freeze_on_ms = -1;
                show_freeze(true);
            }
            else if (freeze_on_ms < 0 && freeze_off_ms >= 0 && ms >= freeze_off_ms) {
                freeze_off_ms = -1;
                show_freeze(false);
            }
            // The freeze ends by itself on a map change: untick it in the menu.
            const bool freeze_now = tooie::save_state::freeze_on();
            if (freeze_shown && !freeze_now) {
                show_freeze(false);
            }
            freeze_shown = freeze_now;
            bool down = tooie::hotkeys::down(recompinput::GameInput::INTERP_CHECK);
            if (down && !was_down) {
                bool now = !on.load();
                set_on(now);
                tooie::toast::show(now ? "Interpolation check on" : "Interpolation check off");
            }
            was_down = down;
            bool mode_down = tooie::hotkeys::down(recompinput::GameInput::BLEND_MODE);
            if (mode_down && !mode_was_down) {
                int now = (mode.load() + 1) % mode_count;
                set_mode(now);
                tooie::toast::show(std::string("Blend mode: ") + tooie::interp_check::blend_mode_name(now));
            }
            mode_was_down = mode_down;
        }
    }
}

void tooie::interp_check::add_options(recomp::config::Config& graphics) {
    created = true;

    graphics.add_bool_option(
        check_option,
        "Interpolation check",
        "For testing. Tints a model red for a moment when its blend between game frames looks wrong, and logs it to the console. Shows nothing at the Original frame rate. "
        "The Interpolation Check key (bind one in the Debug section of the Controls tab) switches it on and off while you play. Starts Off each launch.",
        false);
    graphics.add_option_change_callback(check_option,
        [](recomp::config::ConfigValueVariant value, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
            if (context == recomp::config::OptionChangeContext::Temporary) {
                graphics_config().save_config();
                return;
            }
            const auto* v = std::get_if<bool>(&value);
            on = (v != nullptr) && *v;
        });

    graphics.add_bool_option(
        freeze_option,
        "Freeze",
        "For testing the blend modes. Holds the game on two of its frames, put back again and again, so the frames blended between them "
        "are drawn over and over while you change the blend mode below (the picture rocks a little between the two frames). Sound is muted meanwhile. "
        "In a level only; a map change or Load State ends it. The Freeze key (bind one in the Interpolation Debug section of the Controls tab) does the same. Starts Off each launch.",
        false);
    graphics.add_option_change_callback(freeze_option,
        [](recomp::config::ConfigValueVariant value, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
            if (context == recomp::config::OptionChangeContext::Temporary) {
                graphics_config().save_config();
                return;
            }
            const auto* v = std::get_if<bool>(&value);
            tooie::save_state::set_freeze((v != nullptr) && *v);
        });

    std::vector<recomp::config::ConfigOptionEnumOption> options;
    for (uint32_t i = 0; i < (uint32_t)mode_count; i++) {
        options.emplace_back(i, blend_mode_name((int)i), blend_mode_name((int)i));
    }
    graphics.add_enum_option(
        blend_option,
        "Interpolation blend mode",
        "For testing. How frames between two game frames are blended, to find what blends wrong. "
        "<recomp-color primary>custom</recomp-color> is the setting the game ships with: models snap to the game's own frames and the camera blends, but characters (models with bones) blend with their vertices too, and a model you tagged with the Pick Model and Tag Model keys (interp_tags.txt) does as its tag says. <recomp-color primary>normal</recomp-color> blends every model without vertex blending. The Blend Mode key (bind one in the Debug section of the Controls tab) steps through them. Starts on custom each launch.",
        options,
        5u);
    graphics.add_option_change_callback(blend_option,
        [](recomp::config::ConfigValueVariant value, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
            if (context == recomp::config::OptionChangeContext::Temporary) {
                graphics_config().save_config();
                return;
            }
            const auto* v = std::get_if<uint32_t>(&value);
            mode = ((v != nullptr) && (*v < (uint32_t)mode_count)) ? (int)*v : 5;
        });
}

void tooie::interp_check::start() {
    std::call_once(started, [] {
        if (const char* v = std::getenv("TOOIE_INTERP_CHECK"); v != nullptr && v[0] == '1') {
            on = true;
        }
        // Headless: TOOIE_BLEND_MODE=<0-5> starts in that blend mode.
        if (const char* v = std::getenv("TOOIE_BLEND_MODE"); v != nullptr) {
            mode = std::atoi(v) % mode_count;
        }
        // Left on last time, they start on their defaults again.
        set_on(on.load());
        set_mode(mode.load());
        show_freeze(false);
        std::thread(worker).detach();
    });
}

int tooie::interp_check::blend_mode() {
    return mode.load(std::memory_order_relaxed);
}

const char* tooie::interp_check::blend_mode_name(int m) {
    switch (m) {
        case 1: return "no tags (RT64 matches on its own)";
        case 2: return "tags, with vertex blending";
        case 3: return "camera untagged";
        case 4: return "models snap, camera blends";
        case 5: return "custom (models snap, characters blend, your tags)";
        default: return "normal";
    }
}

void tooie::interp_check::set_blend_mode(int m) {
    set_mode(m);
}

bool tooie::interp_check::enabled() {
    return on.load(std::memory_order_relaxed);
}
