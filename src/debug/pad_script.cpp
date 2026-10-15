// Scripted controller input for headless tests (handoff 4.95).
//
//     --pad-script "3000:start;6000:a;9000:x=1,y=0:2000;12000:quit"
//
// Steps are separated by ';'. Each step is `time_ms:action[:hold_ms]`, with
// times counted from the game's first controller read.
//   * Buttons, joined with ',': a b z start l r du dd dl dr cu cd cl cr.
//     Held for hold_ms (default 150).
//   * Stick: x=<-1..1>, y=<-1..1>, mixed freely with buttons.
//   * Right stick: rx=<-1..1>, ry=<-1..1> (read by the free camera, which
//     sees the right stick itself rather than as C buttons).
//   * `quit` ends the program.
// Scripted input is added to player 1's real input, so a script and a person
// can share the controller.

#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <mutex>
#include <optional>
#include <string>
#include <vector>

#include "tooie_game_frame_rate.h"
#include "tooie_debug.h"
#include "tooie_control_scheme.h"
#include "tooie_photo_mode.h"
#include "tooie_game.h"
#include "tooie_player_cheats.h"
#include "tooie_tiptoe.h"
#include "tooie_talon_trot.h"
#include "tooie_hold_to_run.h"
#include "tooie_fine_aim.h"
#include "tooie_frame_overlay.h"
#include "tooie_motion_aim.h"
#include "tooie_texture_sweep.h"
#include "recompinput/profiles.h"

namespace {
    struct Step {
        uint32_t start_ms;
        uint32_t hold_ms;
        uint16_t buttons;
        std::optional<float> x;
        std::optional<float> y;
        std::optional<float> rx;
        std::optional<float> ry;
        bool quit;
    };

    std::vector<Step> steps;
    std::once_flag started_flag;
    std::chrono::steady_clock::time_point started;

    uint16_t button_bit(const std::string& name) {
        static const struct { const char* name; uint16_t bit; } buttons[] = {
            { "a", 0x8000 }, { "b", 0x4000 }, { "z", 0x2000 }, { "start", 0x1000 },
            { "du", 0x0800 }, { "dd", 0x0400 }, { "dl", 0x0200 }, { "dr", 0x0100 },
            { "l", 0x0020 }, { "r", 0x0010 },
            { "cu", 0x0008 }, { "cd", 0x0004 }, { "cl", 0x0002 }, { "cr", 0x0001 },
        };
        for (const auto& b : buttons) {
            if (name == b.name) {
                return b.bit;
            }
        }
        fprintf(stderr, "[pad] unknown button '%s'\n", name.c_str());
        return 0;
    }

    std::vector<std::string> split(const std::string& text, char sep) {
        std::vector<std::string> parts;
        size_t pos = 0;
        while (pos <= text.size()) {
            size_t next = text.find(sep, pos);
            if (next == std::string::npos) {
                next = text.size();
            }
            parts.push_back(text.substr(pos, next - pos));
            pos = next + 1;
        }
        return parts;
    }
}

bool tooie::debug::parse_pad_script(const char* script) {
    steps.clear();
    for (const std::string& text : split(script, ';')) {
        if (text.empty()) {
            continue;
        }
        std::vector<std::string> fields = split(text, ':');
        if (fields.size() < 2 || fields.size() > 3) {
            fprintf(stderr, "[pad] bad step '%s'\n", text.c_str());
            return false;
        }
        Step step{ (uint32_t)std::strtoul(fields[0].c_str(), nullptr, 10), 150, 0, {}, {}, {}, {}, false };
        if (fields.size() == 3) {
            step.hold_ms = (uint32_t)std::strtoul(fields[2].c_str(), nullptr, 10);
        }
        for (const std::string& action : split(fields[1], ',')) {
            if (action == "quit") {
                step.quit = true;
            }
            else if (action.rfind("rx=", 0) == 0) {
                step.rx = std::strtof(action.c_str() + 3, nullptr);
            }
            else if (action.rfind("ry=", 0) == 0) {
                step.ry = std::strtof(action.c_str() + 3, nullptr);
            }
            else if (action.rfind("x=", 0) == 0) {
                step.x = std::strtof(action.c_str() + 2, nullptr);
            }
            else if (action.rfind("y=", 0) == 0) {
                step.y = std::strtof(action.c_str() + 2, nullptr);
            }
            else {
                step.buttons |= button_bit(action);
            }
        }
        steps.push_back(step);
    }
    fprintf(stderr, "[pad] %zu scripted steps\n", steps.size());
    return true;
}

// Time since the first pad read: real time, or game time with TOOIE_PAD_GAME_TIME=1.
static uint32_t script_ms() {
    static uint32_t started_game_ms = 0;
    std::call_once(started_flag, []() {
        started = std::chrono::steady_clock::now();
        started_game_ms = tooie::game_frame_rate::game_ms();
    });
    if (tooie::game_frame_rate::pad_on_game_time()) {
        return tooie::game_frame_rate::game_ms() - started_game_ms;
    }
    return (uint32_t)std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::steady_clock::now() - started).count();
}

// Player input with any scripted input added.
static bool merged_n64_input(int player_index, uint16_t* buttons_out, float* x_out, float* y_out) {
    bool ok = recompinput::profiles::get_n64_input(player_index, buttons_out, x_out, y_out);
    if (player_index != 0) {
        return ok;
    }
    if (steps.empty()) {
        tooie::quick_start_note_input(*buttons_out);
        return ok;
    }
    uint32_t now_ms = script_ms();
    for (const Step& step : steps) {
        if (now_ms < step.start_ms || now_ms >= step.start_ms + step.hold_ms) {
            continue;
        }
        if (step.quit) {
            fprintf(stderr, "[pad] quit at %u ms\n", now_ms);
            fflush(stderr);
            std::_Exit(0);
        }
        *buttons_out |= step.buttons;
        if (step.x) {
            *x_out = *step.x;
        }
        if (step.y) {
            *y_out = *step.y;
        }
    }
    tooie::quick_start_note_input(*buttons_out);
    return true;
}

bool tooie::debug::get_scripted_right_stick(float* x_out, float* y_out) {
    if (steps.empty()) {
        return false;
    }
    uint32_t now_ms = script_ms();
    bool found = false;
    for (const Step& step : steps) {
        if (now_ms < step.start_ms || now_ms >= step.start_ms + step.hold_ms) {
            continue;
        }
        if (step.rx) {
            *x_out = *step.rx;
            found = true;
        }
        if (step.ry) {
            *y_out = *step.ry;
            found = true;
        }
    }
    return found;
}

bool tooie::debug::get_n64_input(int player_index, uint16_t* buttons_out, float* x_out, float* y_out) {
    bool ok = merged_n64_input(player_index, buttons_out, x_out, y_out);
    if (player_index == 0) {
        tooie::frame_overlay::note_input_read();
        tooie::photo_mode::apply_input(buttons_out, x_out, y_out);
        tooie::control_scheme::apply(buttons_out, x_out, y_out);
        tooie::input::apply_tiptoe(buttons_out, x_out, y_out);
        tooie::hold_to_run::apply(x_out, y_out);
        tooie::talon_trot::apply(buttons_out);
        tooie::motion_aim::collect();
        tooie::cutscene_skip_apply(buttons_out);
        tooie::player_cheats::apply_input(buttons_out);
        tooie::texture_sweep::apply_input(buttons_out);
    }
    return ok;
}
