// The cursor as the save select's pointing hand (L, 2026-10-24): WIP > Hand Cursor, on by default.
//
// The save select draws its hand as a 3D model, so this is a drawn copy of a white glove pointing up:
// a 32x32 picture built into the program and handed to SDL as a colour cursor. The window's event loop
// (RecompFrontend input_events.cpp update_cursor_lock) shows it whenever the cursor is visible, and keeps the
// crosshair for pick mode and the hidden cursor while the game's own menus draw the real hand.
#include <cstdint>
#include <variant>

#include "recompui/config.h"
#include "recompinput/input_state.h"
#include "tooie_game.h"
#include "tooie_hand_cursor.h"

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

namespace {
    constexpr int size = 32;
    // 'k' outline, 'w' glove, '.' clear. The fingertip is the hot spot.
    constexpr const char* picture[size] = {
        "......kkk.......................",
        ".....kwwwk......................",
        "....kwwwwwk.....................",
        "....kwwwwwk.....................",
        "....kwwwwwk.....................",
        "....kwwwwwk.....................",
        "....kwwwwwk.....................",
        "....kwwwwwk.....................",
        "....kwwwwwk.....................",
        "....kwwwwwk.....................",
        "....kwwwwwkkkk.kkk..kkk.........",
        "....kwwwwwkwwwkwwwkkwwwk........",
        "....kwwwwwwwwwwwwwwwwwwwk.......",
        "....kwwwwwwwwwwwwwwwwwwwwk......",
        "....kwwwwwwwwwwwwwwwwwwwwwk.....",
        "....kwwwwwwwwwwwwwwwwwwwwwwk....",
        "....kwwwwwwwwwwwwwwwwwwwwwwk....",
        "...kwwwwwwwwwwwwwwwwwwwwwwwk....",
        "..kwwwwwwwwwwwwwwwwwwwwwwwwk....",
        ".kwwwwwwwwwwwwwwwwwwwwwwwwwk....",
        ".kwwwwwwwwwwwwwwwwwwwwwwwwwk....",
        ".kwwwwwwwwwwwwwwwwwwwwwwwwwk....",
        ".kwwwwwwwwwwwwwwwwwwwwwwwwwk....",
        ".kwwwwwwwwwwwwwwwwwwwwwwwwwk....",
        "..kwwwwwwwwwwwwwwwwwwwwwwwwk....",
        "...kwwwwwwwwwwwwwwwwwwwwwwk.....",
        "....kkkwwwwwwwwwwwwwwwwwwk......",
        ".......kwwwwwwwwwwwwwwwwk.......",
        "........kkkkkkkkkkkkkkkk........",
        "................................",
        "................................",
        "................................",
    };

    SDL_Cursor* hand = nullptr;
    bool made = false;

    bool enabled() {
        try {
            return std::get<bool>(recompui::config::get_config(recompui::config::graphics::id).get_option_value(tooie::hand_cursor::option));
        } catch (...) {
            return true;
        }
    }

    void make() {
        made = true;
        SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormat(0, size, size, 32, SDL_PIXELFORMAT_RGBA32);
        if (surface == nullptr) {
            return;
        }
        uint8_t* pixels = static_cast<uint8_t*>(surface->pixels);
        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++) {
                const char c = picture[y][x];
                uint8_t* p = pixels + y * surface->pitch + x * 4;
                const uint8_t v = (c == 'w') ? 255 : 12;
                p[0] = v;
                p[1] = v;
                p[2] = v;
                p[3] = (c == '.') ? 0 : 255;
            }
        }
        hand = SDL_CreateColorCursor(surface, 7, 1);
        SDL_FreeSurface(surface);
    }
}

void tooie::hand_cursor::add_option(recomp::config::Config& graphics) {
    graphics.add_bool_option(option, "Hand Cursor",
        "Shows the cursor as the save select screen's pointing hand wherever it appears over the game: the Start menu, the ESC menu and the other menus. Off uses the system's arrow. Pick mode keeps its crosshair.",
        true);
}

void tooie::hand_cursor::update() {
    if (!made) {
        make();
    }
    recompinput::set_custom_cursor(enabled() ? hand : nullptr);
}
