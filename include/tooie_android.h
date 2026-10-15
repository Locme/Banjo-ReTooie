#ifndef __TOOIE_ANDROID_H__
#define __TOOIE_ANDROID_H__

#include <string>

// Android start-up (src/android/android_platform.cpp). The Java side (android/) unpacks assets/ into
// the app's internal folder and saves the ROM the player picked as picked_rom.z64 in the app folder.
namespace tooie::android {
    // Called first in main(): moves to the internal folder (assets/ is there), makes the app folder
    // (Android/data/<package>/files, reachable over USB) the one for saves, settings and mods, and
    // sends stdout and stderr to logs/console.log in it.
    void setup_paths();
    // Called once the game is registered: checks and stores picked_rom.z64 as the game's ROM, then
    // deletes it. Returns false, after saying why, when the ROM is refused; the game then closes and
    // the launcher asks for a ROM again.
    bool install_picked_rom(std::u8string game_id);
}

#endif
