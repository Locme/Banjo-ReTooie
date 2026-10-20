#pragma once

#include <string>

struct SDL_Window;

namespace tooie::boot_screen {
    // A plain text screen drawn straight onto the game window (src/main/boot_screen.cpp), for work done
    // at startup before the renderer and the menus exist, such as unpacking mod zips. Windows and Linux
    // only; elsewhere these do nothing.
    void set_window(SDL_Window* window);
    // Shows (or updates) the screen and keeps the window responding. Cheap to call often: it redraws
    // at most every 30 ms.
    void show(const std::string& title, const std::string& detail);
    // Gives the window back so the renderer can take it over.
    void close();
}
