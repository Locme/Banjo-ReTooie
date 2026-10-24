// The cursor as the save select's pointing hand (L, 2026-10-24): WIP > Hand Cursor, on by default.
//
// By default a drawn white glove pointing up: a 32x32 picture built into the program and handed to SDL as
// a colour cursor. WIP > 3D Hand Cursor (off by default) uses the save select's own 3D hand instead, drawn
// from the ROM with its animations (hand_model_cursor.cpp), one cursor per animation frame. The window's event loop
// (RecompFrontend input_events.cpp update_cursor_lock) shows it whenever the cursor is visible, and keeps the
// crosshair for pick mode and the hidden cursor while the game's own menus draw the real hand.
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <variant>
#include <vector>

#include "recompui/config.h"
#include "recompinput/input_state.h"
#include "tooie_game.h"
#include "tooie_hand_cursor.h"
#include "tooie_hotkeys.h"

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

    // The 3D hand (WIP > 3D Hand Cursor): one cursor per animation frame, 64 pixels across.
    constexpr int model_size = 64;
    std::vector<SDL_Cursor*> model_idle;
    std::vector<SDL_Cursor*> model_click;
    float idle_fps = 30.0f;
    float click_fps = 30.0f;
    bool model_made = false;
    // While the ROM can't be read yet (the launcher before a ROM is picked), tried again now and then.
    std::chrono::steady_clock::time_point next_model_try{};

    bool option_value(const std::string& id, bool fallback) {
        try {
            return std::get<bool>(recompui::config::get_config(recompui::config::graphics::id).get_option_value(id));
        } catch (...) {
            return fallback;
        }
    }

    SDL_Cursor* make_cursor(const uint8_t* rgba, int w, int h, int hot_x, int hot_y) {
        SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormat(0, w, h, 32, SDL_PIXELFORMAT_RGBA32);
        if (surface == nullptr) {
            return nullptr;
        }
        for (int y = 0; y < h; y++) {
            std::memcpy(static_cast<uint8_t*>(surface->pixels) + y * surface->pitch, rgba + y * w * 4, w * 4);
        }
        SDL_Cursor* cursor = SDL_CreateColorCursor(surface, hot_x, hot_y);
        SDL_FreeSurface(surface);
        return cursor;
    }

    void make() {
        made = true;
        std::vector<uint8_t> rgba(size * size * 4);
        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++) {
                const char c = picture[y][x];
                uint8_t* p = &rgba[(y * size + x) * 4];
                const uint8_t v = (c == 'w') ? 255 : 12;
                p[0] = v;
                p[1] = v;
                p[2] = v;
                p[3] = (c == '.') ? 0 : 255;
            }
        }
        hand = make_cursor(rgba.data(), size, size, 7, 1);
    }

    void make_model() {
        const auto now = std::chrono::steady_clock::now();
        if (now < next_model_try) {
            return;
        }
        next_model_try = now + std::chrono::seconds(2);
        tooie::hand_cursor::ModelFrames frames;
        if (!tooie::hand_cursor::make_model_frames(model_size, frames)) {
            return;
        }
        for (const auto& f : frames.idle) {
            model_idle.push_back(make_cursor(f.data(), frames.size, frames.size, frames.hot_x, frames.hot_y));
        }
        for (const auto& f : frames.click) {
            model_click.push_back(make_cursor(f.data(), frames.size, frames.size, frames.hot_x, frames.hot_y));
        }
        idle_fps = frames.idle_fps;
        click_fps = frames.click_fps;
        model_made = true;
        std::printf("[hand-cursor] 3D hand made: %zu idle and %zu click frames, hot spot %d,%d\n",
            model_idle.size(), model_click.size(), frames.hot_x, frames.hot_y);
        std::fflush(stdout);
    }

    // The 3D hand's cursor for now: the idle loops, a left click plays the grab animation once.
    SDL_Cursor* model_cursor() {
        using clock = std::chrono::steady_clock;
        static const clock::time_point began = clock::now();
        static clock::time_point click_began{};
        static bool clicking = false;
        static bool was_down = false;
        const clock::time_point now = clock::now();
        const bool down = (SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON_LMASK) != 0;
        if (down && !was_down && !model_click.empty()) {
            clicking = true;
            click_began = now;
        }
        was_down = down;
        if (clicking) {
            const size_t frame = (size_t)(std::chrono::duration<float>(now - click_began).count() * click_fps);
            if (frame < model_click.size()) {
                return model_click[frame];
            }
            clicking = false;
        }
        if (model_idle.empty()) {
            return nullptr;
        }
        const size_t frame = (size_t)(std::chrono::duration<float>(now - began).count() * idle_fps);
        return model_idle[frame % model_idle.size()];
    }
}

void tooie::hand_cursor::add_option(recomp::config::Config& graphics) {
    graphics.add_bool_option(option, "Hand Cursor",
        "Shows the cursor as the save select screen's pointing hand wherever it appears over the game: the Start menu, the ESC menu and the other menus. Off uses the system's arrow. Pick mode keeps its crosshair.",
        true);
    graphics.add_bool_option(model_option, "3D Hand Cursor",
        "With Hand Cursor on, the cursor is the save select screen's own 3D hand, drawn from the game's model with its idle animation, and a left click plays its grab animation (the hand closes into a fist and opens again). Off shows the flat glove.",
        false);
}

void tooie::hand_cursor::update() {
    if (!made) {
        make();
    }
    // Show/Hide Cursor (Tab, L 2026-10-24): each press over the game flips it.
    static bool toggle_was_down = false;
    const bool toggle_down = tooie::hotkeys::down(recompinput::GameInput::TOGGLE_CURSOR);
    if (toggle_down && !toggle_was_down && !recompinput::game_input_disabled()) {
        recompinput::set_cursor_shown_by_key(!recompinput::cursor_shown_by_key());
    }
    toggle_was_down = toggle_down;
    // The options are read every 50 ms (they take the config's lock); the 3D hand's frame every pass.
    static bool on = true;
    static bool model_on = false;
    static auto next_read = std::chrono::steady_clock::time_point{};
    const auto now = std::chrono::steady_clock::now();
    if (now >= next_read) {
        next_read = now + std::chrono::milliseconds(50);
        on = option_value(option, true);
        model_on = option_value(model_option, false);
    }
    SDL_Cursor* cursor = nullptr;
    if (on && model_on) {
        if (!model_made) {
            make_model();
        }
        cursor = model_cursor();
    }
    if (on && cursor == nullptr) {
        cursor = hand;
    }
    recompinput::set_custom_cursor(cursor);
}
