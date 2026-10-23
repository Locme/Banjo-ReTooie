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
//   * Virtual pad buttons: v<0..15> holds that raw button of a virtual SDL controller, attached
//     when the script has any (a:b0 b:b1 x:b2 y:b3 back:b4 guide:b5 start:b6 leftstick:b7
//     rightstick:b8 leftshoulder:b9 rightshoulder:b10; b11-b15 are left unmapped, like back
//     buttons). Unlike the buttons above, these go through the Controls tab's bindings.
//     vlt and vrt pull the virtual pad's left and right triggers all the way.
//   * `quit` ends the program.
// TOOIE_INPUT_LOG=1 logs player 1's bound N64 buttons whenever they change.
// TOOIE_COMBO_TEST=1 binds N64 A's second slot to the combination Paddle 1 (v11) + Y, for testing
// button combinations with the virtual pad.
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

#include "ultramodern/ultramodern.hpp"
#include "tooie_mirror_mode.h"
#include "tooie_game_frame_rate.h"
#include "tooie_debug.h"
#include "tooie_control_scheme.h"
#include "tooie_photo_mode.h"
#include "tooie_game.h"
#include "tooie_player_cheats.h"
#include "tooie_tiptoe.h"
#include "tooie_talon_trot.h"
#include "tooie_dive.h"
#include "tooie_hold_to_run.h"
#include "tooie_fine_aim.h"
#include "tooie_frame_overlay.h"
#include "tooie_motion_aim.h"
#include "tooie_free_camera.h"
#include "tooie_menu_mouse.h"
#include "tooie_texture_sweep.h"
#include "tooie_totals_checklist.h"
#include "recompinput/profiles.h"
#include "recompinput/input_mapping.h"

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

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
        uint16_t vbuttons = 0;
        uint8_t vtriggers = 0;   // 1 left, 2 right
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
            else if (action == "vlt" || action == "vrt") {
                step.vtriggers |= action == "vlt" ? 1 : 2;
            }
            else if (action.size() > 1 && action[0] == 'v' && action[1] >= '0' && action[1] <= '9') {
                step.vbuttons |= (uint16_t)(1u << (std::strtoul(action.c_str() + 1, nullptr, 10) & 15));
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

// The virtual pad for v<n> steps.
static void update_virtual_pad(uint32_t now_ms) {
    static SDL_Joystick* joystick = nullptr;
    static bool tried = false;
    static int index = -1;
    static bool combo_bound = false;
    uint16_t held = 0;
    uint8_t triggers = 0;
    bool used = false;
    for (const Step& step : steps) {
        used = used || step.vbuttons != 0 || step.vtriggers != 0;
        if (now_ms >= step.start_ms && now_ms < step.start_ms + step.hold_ms) {
            held |= step.vbuttons;
            triggers |= step.vtriggers;
        }
    }
    if (!used) {
        return;
    }
    if (!tried) {
        tried = true;
        SDL_VirtualJoystickDesc desc{};
        desc.version = SDL_VIRTUAL_JOYSTICK_DESC_VERSION;
        desc.type = SDL_JOYSTICK_TYPE_GAMECONTROLLER;
        desc.naxes = 6;
        desc.nbuttons = 16;
        desc.vendor_id = 0x1234;
        desc.product_id = 0x5678;
        desc.name = "Pad script";
        index = SDL_JoystickAttachVirtualEx(&desc);
        if (index >= 0) {
            char guid[64];
            SDL_JoystickGetGUIDString(SDL_JoystickGetDeviceGUID(index), guid, sizeof(guid));
            std::string mapping = std::string(guid) + ",Pad script,a:b0,b:b1,x:b2,y:b3,back:b4,guide:b5,start:b6,"
                "leftstick:b7,rightstick:b8,leftshoulder:b9,rightshoulder:b10,leftx:a0,lefty:a1,rightx:a2,righty:a3,"
                "lefttrigger:a4,righttrigger:a5,";
            SDL_GameControllerAddMapping(mapping.c_str());
        }
        fprintf(stderr, "[pad] virtual pad %s\n", index >= 0 ? "attached" : SDL_GetError());
    }
    if (joystick == nullptr && index >= 0) {
        // Opening can fail until the main thread has seen the new device; try again on later reads.
        joystick = SDL_JoystickOpen(index);
    }
    if (joystick == nullptr) {
        return;
    }
    if (!combo_bound && std::getenv("TOOIE_COMBO_TEST") != nullptr) {
        int profile = recompinput::profiles::get_sp_controller_profile_index();
        if (profile >= 0) {
            recompinput::InputField combo = recompinput::InputField::controller_digital(recompinput::SDL_CONTROLLER_BUTTON_NORTH);
            combo.modifier_type = recompinput::InputType::ControllerDigital;
            combo.modifier_id = SDL_CONTROLLER_BUTTON_PADDLE1;
            recompinput::profiles::set_input_binding(profile, recompinput::GameInput::A, 1, combo);
            combo_bound = true;
            fprintf(stderr, "[pad] N64 A also bound to %s\n", combo.to_string().c_str());
        }
    }
    for (int b = 0; b < 16; b++) {
        SDL_JoystickSetVirtualButton(joystick, b, (held >> b) & 1);
    }
    SDL_JoystickSetVirtualAxis(joystick, 4, (triggers & 1) ? 32767 : -32768);
    SDL_JoystickSetVirtualAxis(joystick, 5, (triggers & 2) ? 32767 : -32768);
}

// Player input with any scripted input added.
static bool merged_n64_input(int player_index, uint16_t* buttons_out, float* x_out, float* y_out) {
    if (player_index == 0 && !steps.empty()) {
        update_virtual_pad(script_ms());
    }
    bool ok = recompinput::profiles::get_n64_input(player_index, buttons_out, x_out, y_out);
    if (player_index != 0) {
        return ok;
    }
    static const bool log_input = std::getenv("TOOIE_INPUT_LOG") != nullptr;
    static uint16_t last_logged = 0;
    if (log_input && *buttons_out != last_logged) {
        last_logged = *buttons_out;
        fprintf(stderr, "[input] %u ms: buttons %04X\n", steps.empty() ? 0u : script_ms(), *buttons_out);
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
        // Mirror Mode: the controls follow the flipped picture (left stick and the left/right camera buttons).
        if (tooie::mirror_mode::active()) {
            *x_out = -*x_out;
            const uint16_t c_left_right = 0x0003;
            const uint16_t swapped = uint16_t(((*buttons_out & 0x0001) << 1) | ((*buttons_out & 0x0002) >> 1));
            *buttons_out = uint16_t((*buttons_out & ~c_left_right) | swapped);
        }
        tooie::frame_overlay::note_input_read();
        static const bool vi_log = std::getenv("TOOIE_VI_LOG") != nullptr;
        if (vi_log) {
            int64_t now = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
            std::printf("[vi] pad %.2f\n", (now - ultramodern::get_last_vi_tick_ns()) / 1e6);
        }
        tooie::photo_mode::apply_input(buttons_out, x_out, y_out);
        tooie::control_scheme::apply(buttons_out, x_out, y_out);
        tooie::input::apply_tiptoe(buttons_out, x_out, y_out);
        tooie::hold_to_run::apply(x_out, y_out);
        tooie::talon_trot::apply(buttons_out);
        tooie::dive::apply(buttons_out);
        tooie::motion_aim::collect();
        tooie::free_camera::apply_input(buttons_out);
        tooie::cutscene_skip_apply(buttons_out);
        tooie::player_cheats::apply_input(buttons_out);
        tooie::texture_sweep::apply_input(buttons_out);
        tooie::totals_checklist::apply_input(buttons_out, x_out, y_out);
        tooie::menu_mouse::apply_input(buttons_out, x_out, y_out);
    }
    return ok;
}
