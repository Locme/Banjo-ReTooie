#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <system_error>

#include "SDL.h"
#include "SDL_system.h"

#include "librecomp/game.hpp"
#include "tooie_android.h"

namespace fs = std::filesystem;

namespace {
    fs::path app_folder;

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
