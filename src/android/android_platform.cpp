#include <atomic>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <system_error>

#include <jni.h>

#include "SDL.h"
#include "SDL_system.h"

#include "librecomp/game.hpp"
#include "tooie_android.h"

namespace fs = std::filesystem;

namespace {
    fs::path app_folder;

    // Touch state written by TouchOverlay.java (the UI thread) and read by the game's graphics thread.
    // Buttons are the TouchOverlay.BTN_* bits; sticks are -32768..32767 with up and left negative.
    std::atomic<uint32_t> touch_buttons{0};
    std::atomic<int32_t> touch_left_x{0};
    std::atomic<int32_t> touch_left_y{0};
    std::atomic<int32_t> touch_right_x{0};
    std::atomic<int32_t> touch_right_y{0};

    // A virtual game controller, which the game reads like a real pad: the touch controls then use
    // recompinput's default controller mapping with no changes to it.
    SDL_Joystick* touch_pad = nullptr;
    bool touch_pad_tried = false;

    void attach_touch_pad() {
        touch_pad_tried = true;
        SDL_VirtualJoystickDesc desc{};
        desc.version = SDL_VIRTUAL_JOYSTICK_DESC_VERSION;
        desc.type = SDL_JOYSTICK_TYPE_GAMECONTROLLER;
        desc.naxes = SDL_CONTROLLER_AXIS_MAX;
        desc.nbuttons = SDL_CONTROLLER_BUTTON_MAX;
        desc.name = "Banjo-Tooie touch controls";
        int index = SDL_JoystickAttachVirtualEx(&desc);
        if (index < 0) {
            fprintf(stderr, "[android] touch controls: %s\n", SDL_GetError());
            return;
        }
        touch_pad = SDL_JoystickOpen(index);
    }

    const char* rom_error_text(recomp::RomValidationError error) {
        switch (error) {
            case recomp::RomValidationError::FailedToOpen:
                return "The file you picked could not be read.";
            case recomp::RomValidationError::NotARom:
                return "The file you picked is not an N64 ROM.";
            case recomp::RomValidationError::IncorrectRom:
                return "The file you picked is not Banjo-Tooie.";
            case recomp::RomValidationError::IncorrectVersion:
            case recomp::RomValidationError::NotYet:
                return "This is a different version of Banjo-Tooie. Only the US (NTSC-U 1.0) release is supported.";
            default:
                return "The ROM could not be set up.";
        }
    }
}

void tooie::android::setup_paths() {
    std::error_code ec;
    const char* internal = SDL_AndroidGetInternalStoragePath();
    const char* external = SDL_AndroidGetExternalStoragePath();
    if (internal != nullptr) {
        fs::current_path(internal, ec);
    }
    app_folder = fs::path{ external != nullptr ? external : (internal != nullptr ? internal : ".") };
    // Read by the runtime's app folder lookup (recompui::file::get_app_folder_path).
    setenv("APP_FOLDER_PATH", app_folder.c_str(), 1);

    // Android throws stdout and stderr away; keep them where the player can copy them from.
    fs::create_directories(app_folder / "logs", ec);
    const fs::path console_log = app_folder / "logs" / "console.log";
    if (std::freopen(console_log.c_str(), "w", stdout) != nullptr) {
        std::setvbuf(stdout, nullptr, _IONBF, 0);
    }
    if (std::freopen(console_log.c_str(), "a", stderr) != nullptr) {
        std::setvbuf(stderr, nullptr, _IONBF, 0);
    }
    std::printf("[android] internal folder: %s\n", internal != nullptr ? internal : "(none)");
    std::printf("[android] app folder: %s\n", app_folder.c_str());
}

bool tooie::android::install_picked_rom(std::u8string game_id) {
    std::error_code ec;
    const fs::path picked = app_folder / "picked_rom.z64";
    if (!fs::exists(picked, ec)) {
        return true;
    }
    recomp::RomValidationError result = recomp::select_rom(picked, game_id);
    fs::remove(picked, ec);
    if (result == recomp::RomValidationError::Good) {
        std::printf("[android] ROM installed\n");
        return true;
    }
    std::printf("[android] ROM refused: %s\n", rom_error_text(result));
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Banjo-Tooie", rom_error_text(result), nullptr);
    return false;
}

void tooie::android::update_touch() {
    if (!touch_pad_tried) {
        attach_touch_pad();
    }
    if (touch_pad == nullptr) {
        return;
    }
    const uint32_t buttons = touch_buttons.load();
    // Button bits as TouchOverlay.java sets them.
    constexpr uint32_t BTN_A = 1 << 0, BTN_B = 1 << 1, BTN_START = 1 << 2, BTN_L = 1 << 3, BTN_R = 1 << 4, BTN_Z = 1 << 5;
    SDL_JoystickSetVirtualButton(touch_pad, SDL_CONTROLLER_BUTTON_A, (buttons & BTN_A) ? 1 : 0);
    SDL_JoystickSetVirtualButton(touch_pad, SDL_CONTROLLER_BUTTON_B, (buttons & BTN_B) ? 1 : 0);
    SDL_JoystickSetVirtualButton(touch_pad, SDL_CONTROLLER_BUTTON_START, (buttons & BTN_START) ? 1 : 0);
    SDL_JoystickSetVirtualButton(touch_pad, SDL_CONTROLLER_BUTTON_LEFTSHOULDER, (buttons & BTN_L) ? 1 : 0);
    SDL_JoystickSetVirtualAxis(touch_pad, SDL_CONTROLLER_AXIS_TRIGGERRIGHT, (buttons & BTN_R) ? 32767 : 0);
    SDL_JoystickSetVirtualAxis(touch_pad, SDL_CONTROLLER_AXIS_TRIGGERLEFT, (buttons & BTN_Z) ? 32767 : 0);
    SDL_JoystickSetVirtualAxis(touch_pad, SDL_CONTROLLER_AXIS_LEFTX, touch_left_x.load());
    SDL_JoystickSetVirtualAxis(touch_pad, SDL_CONTROLLER_AXIS_LEFTY, touch_left_y.load());
    SDL_JoystickSetVirtualAxis(touch_pad, SDL_CONTROLLER_AXIS_RIGHTX, touch_right_x.load());
    SDL_JoystickSetVirtualAxis(touch_pad, SDL_CONTROLLER_AXIS_RIGHTY, touch_right_y.load());
}

// Called by TouchOverlay.java on every change. The names must match that class, in package io.github.locme.banjotooie.
extern "C" JNIEXPORT void JNICALL
Java_io_github_locme_banjotooie_TouchOverlay_nativeSetState(JNIEnv*, jclass, jint buttons, jint left_x, jint left_y, jint right_x, jint right_y) {
    touch_buttons.store(static_cast<uint32_t>(buttons));
    touch_left_x.store(left_x);
    touch_left_y.store(left_y);
    touch_right_x.store(right_x);
    touch_right_y.store(right_y);
}
