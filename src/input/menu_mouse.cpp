// The mouse in the game's own menus (L, 2026-10-19): QOL > "Mouse in the game's menus", on by default.
//
// In the pause menu (the Start menu) the row under the cursor is picked as the cursor moves over it, and a
// left click on a row picks it and presses A. A right click is B anywhere in the menu (back, or no to "are
// you sure?"). The game moves its own highlight: this only steers the stick and presses the buttons, one
// step a frame, so the game's sounds and animations play as with a controller.
//
// The pause menu (overlay gcnewpause) draws its main page with gcnewoption: an OptionState at
// PauseState + 0x30 (layout below, from gcnewoption_entrypoint_8/9/40/41 and its draw func_80800D28),
// whose rows are zoomboxes stacked from (x, y) one spacing apart. gcnewoption moves the highlight with
// the stick (func_80016068) and picks with A (func_80015E80).
//
// The save select (map 0x158, overlay chgameselect) has a hand that moves between eight spots on a
// camera that pans to each: 0-2 the files, 3 the copier, 4 the bin (erase), 5 the console (multiplayer),
// 6 the TV (settings), 7 the green box (not available). The spot is the high nibble of the byte at 0x79
// of the menu that func_80800E24 (the hand's update, hooked) runs on; it is moved with the stick (row
// above row: spot + 4) and A plays it. As the camera differs at every spot, each spot has the screen
// places the eight things are at from there (measured headless at 16:9, in the window's height units
// from its middle). The cursor moving onto a thing steers the hand there, a left click also presses A.
// In the screens inside it (copy, erase, settings, are you sure?) a left click is A and a right click B.
//
// While one of these menus is up the cursor is freed from mouse aiming (recompinput::set_game_menu_mouse)
// and shows once the mouse is used, as in this program's own menus. The window's picture is the game's
// 320x240 frame scaled to fit (the menus stay 4:3 in the middle with widescreen).
//
// TOOIE_MENU_MOUSE_LOG=1 logs what is under the cursor and each step.

#include <algorithm>
#include <atomic>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <variant>

#include "recomp.h"
#include "recompui/config.h"
#include "recompinput/input_state.h"
#include "tooie_debug.h"
#include "tooie_game.h"
#include "tooie_hooks.h"
#include "tooie_menu_mouse.h"
#include "tooie_rdram.h"

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

namespace {
    // The open pause menu's PauseState, 0 when it is closed (as src/gameplay/pause_settings.cpp reads it).
    constexpr uint32_t pause_menu_addr = 0x80128AF0;
    // PauseState (decomp include/gc/newpause.h).
    constexpr uint32_t pause_page = 0x00;
    constexpr uint32_t pause_exit_type = 0x02;
    constexpr uint32_t pause_confirm = 0x0E;        // unkE: an "are you sure?" is up
    constexpr uint32_t pause_options = 0x30;        // OptionState
    constexpr uint8_t page_main = 2;

    // OptionState (gcnewoption).
    constexpr uint32_t option_visible = 0x02;       // rows shown (s16)
    constexpr uint32_t option_count = 0x04;         // rows in all (s16)
    constexpr uint32_t option_picked = 0x06;        // the highlighted row (s16)
    constexpr uint32_t option_top = 0x08;           // the first row shown (s16)
    constexpr uint32_t option_spacing = 0x14;       // rows apart (f32)
    constexpr uint32_t option_x = 0x254;            // where the rows start (s16)
    constexpr uint32_t option_y = 0x256;

    constexpr uint16_t button_a = 0x8000;
    constexpr uint16_t button_b = 0x4000;

    // The save select's hand update ran: the menu it ran on (set by tooie_select_menu on the game thread).
    std::atomic<uint32_t> select_menu = 0;
    std::atomic<uint32_t> select_calls = 0;
    // The hand's spot: 0 to 7, the high nibble of the byte at 0x79 (4 a row; decomp-less, from func_80800E24).
    constexpr uint32_t select_spot = 0x79;

    constexpr uint16_t save_select_map = 0x158;
    constexpr int spots = 8;
    // Where each spot's thing is on screen when the hand is at spot `from`: centre (x, y) and radius, in
    // 800 x 450 pixels (a window shrunk to that, its middle at 400, 225).
    struct Place { float x, y, r; };
    constexpr Place places[spots][spots] = {
        // from 0: files 1-3, copier, bin, console, TV, green box
        { {215, 150, 85}, {385, 210, 80}, {555, 145, 85}, {715, 170, 45}, {225, 430, 40}, {440, 425, 50}, {590, 330, 95}, {780, 350, 40} },
        // from 1
        { {145, 140, 85}, {320, 200, 80}, {485, 130, 85}, {660, 160, 45}, {180, 415, 40}, {375, 440, 50}, {520, 320, 95}, {685, 310, 50} },
        // from 2
        { {105, 155, 85}, {275, 225, 80}, {440, 150, 85}, {590, 160, 45}, {160, 425, 40}, {320, 435, 50}, {450, 335, 95}, {630, 375, 50} },
        // from 3
        { {40, 160, 85}, {210, 215, 80}, {370, 155, 85}, {510, 170, 45}, {85, 425, 40}, {255, 425, 50}, {385, 335, 95}, {555, 390, 55} },
        // from 4
        { {240, 35, 60}, {395, 90, 70}, {570, 40, 60}, {745, 30, 45}, {245, 320, 55}, {440, 310, 60}, {600, 200, 100}, {750, 300, 55} },
        // from 5
        { {145, 50, 70}, {305, 110, 70}, {455, 50, 60}, {640, 50, 45}, {170, 335, 55}, {345, 320, 60}, {485, 210, 100}, {635, 305, 55} },
        // from 6
        { {140, 115, 80}, {295, 155, 75}, {450, 100, 75}, {600, 115, 45}, {155, 375, 55}, {315, 355, 60}, {460, 285, 95}, {630, 375, 55} },
        // from 7
        { {75, 85, 75}, {225, 135, 75}, {380, 65, 70}, {525, 80, 45}, {85, 375, 55}, {235, 345, 60}, {390, 215, 95}, {525, 285, 65} },
    };

    bool logging() {
        static const bool log = std::getenv("TOOIE_MENU_MOUSE_LOG") != nullptr;
        return log;
    }

    bool enabled() {
        try {
            return std::get<bool>(recompui::config::get_config(tooie::qol_tab_id).get_option_value(tooie::menu_mouse::enabled_option));
        } catch (...) {
            return true;
        }
    }

    uint8_t read_byte(uint8_t* rdram, uint32_t addr) {
        return rdram[(addr ^ 3) - 0x80000000u];
    }

    // What the pad reads get this frame (set by tick, read by apply_input on the pad thread).
    std::atomic<int> stick_step = 0;            // -1 down, 1 up
    std::atomic<int> stick_x = 0;               // -1 left, 1 right
    std::atomic<bool> pad_used = false;         // a controller or key was used since the last tick
    int select_target = -1;                     // the spot being steered to
    bool select_press_a = false;                // press A there
    std::atomic<uint16_t> press = 0;

    // The cursor in the game's 320x240 frame; false when the mouse has not been seen.
    bool cursor_in_frame(float* x, float* y) {
        int mx, my, w, h;
        if (!recompinput::get_game_mouse_position(&mx, &my, &w, &h) || mx < 0) {
            return false;
        }
        const float scale = std::min(w / 320.0f, h / 240.0f);
        *x = (mx - w * 0.5f) / scale + 160.0f;
        *y = (my - h * 0.5f) / scale + 120.0f;
        return true;
    }

    // The cursor as pixels of the window shrunk to 800 x 450 (the 3D picture fills the window's height).
    bool cursor_in_800(float* x, float* y) {
        int mx, my, w, h;
        if (!recompinput::get_game_mouse_position(&mx, &my, &w, &h) || mx < 0) {
            return false;
        }
        // 4:3 or narrower windows fit the picture to the width instead.
        const float height = std::min((float)h, w * 0.75f);
        const float scale = 450.0f / height;
        *x = 400.0f + (mx - w * 0.5f) * scale;
        *y = 225.0f + (my - h * 0.5f) * scale;
        return true;
    }

    // The mouse since the last frame.
    struct MouseUse {
        bool moved = false;
        bool left = false;
        bool right = false;
    };

    MouseUse take_mouse_use(bool reset) {
        static uint32_t moves_seen = 0, left_seen = 0, right_seen = 0;
        const uint32_t moves = recompinput::get_game_mouse_moves();
        const uint32_t left = recompinput::get_game_mouse_clicks(SDL_BUTTON_LEFT);
        const uint32_t right = recompinput::get_game_mouse_clicks(SDL_BUTTON_RIGHT);
        MouseUse use;
        if (!reset) {
            use.moved = moves != moves_seen;
            use.left = left != left_seen;
            use.right = right != right_seen;
        }
        moves_seen = moves;
        left_seen = left;
        right_seen = right;
        return use;
    }

    // A row of a gcnewoption menu under the cursor, or -1. Each row's zoombox is drawn spacing * (slot + 1)
    // below y (func_80800D28); a row counts from half a spacing above that to half below.
    int option_row_at(uint8_t* rdram, uint32_t options, float x, float y) {
        const int visible = tooie::rdram::read_half(rdram, options + option_visible);
        const int count = tooie::rdram::read_half(rdram, options + option_count);
        const int top = tooie::rdram::read_half(rdram, options + option_top);
        const float spacing = tooie::rdram::read_float(rdram, options + option_spacing);
        const float left = tooie::rdram::read_half(rdram, options + option_x);
        const float first = tooie::rdram::read_half(rdram, options + option_y);
        if (visible <= 0 || count <= 0 || !(spacing > 1.0f && spacing < 100.0f)) {
            return -1;
        }
        if (x < left - 8.0f || x > left + 200.0f) {
            return -1;
        }
        const int slot = (int)std::floor((y - first) / spacing - 0.5f);
        if (slot < 0 || slot >= visible || top + slot >= count) {
            return -1;
        }
        return top + slot;
    }

    // Steering a gcnewoption menu to a row.
    struct Steer {
        int target = -1;
        bool press_a = false;           // once the target is reached
        bool released = true;           // the stick went back to the middle since the last step
    };
    Steer steer;

    void steer_options(uint8_t* rdram, uint32_t options, bool hover, const MouseUse& use, float x, float y, bool have_cursor) {
        const int row = have_cursor ? option_row_at(rdram, options, x, y) : -1;
        if (hover && use.moved && row >= 0) {
            steer.target = row;
        }
        if (use.left && row >= 0) {
            steer.target = row;
            steer.press_a = true;
        }

        const int picked = tooie::rdram::read_half(rdram, options + option_picked);
        if (steer.target < 0) {
            return;
        }
        if (steer.target == picked) {
            if (steer.press_a) {
                press.fetch_or(button_a);
                if (logging()) {
                    fprintf(stderr, "[menu-mouse] A on row %d\n", picked);
                }
            }
            steer.target = -1;
            steer.press_a = false;
            return;
        }
        // One stick push a frame, back to the middle between them: the menu steps once per push.
        if (!steer.released) {
            steer.released = true;
            return;
        }
        stick_step.store(steer.target > picked ? -1 : 1);
        steer.released = false;
        if (logging()) {
            fprintf(stderr, "[menu-mouse] row %d -> %d\n", picked, steer.target);
        }
    }

    void clear_steer() {
        steer = Steer{};
        select_target = -1;
        select_press_a = false;
    }

    // The thing under the cursor with the hand at `spot`, or -1: the nearest centre within its radius.
    int spot_at(int spot, float x, float y) {
        int best = -1;
        float best_d = 1.0f;
        for (int i = 0; i < spots; i++) {
            const Place& p = places[spot][i];
            const float d = std::hypot(x - p.x, y - p.y) / p.r;
            if (d < best_d) {
                best_d = d;
                best = i;
            }
        }
        return best;
    }

    // Steering the save select's hand.
    void steer_select(uint8_t* rdram, uint32_t menu, const MouseUse& use, float x, float y, bool have_cursor) {
        const int spot = read_byte(rdram, menu + select_spot) >> 4;
        if (spot < 0 || spot >= spots) {
            return;
        }
        const int hit = have_cursor ? spot_at(spot, x, y) : -1;
        if (logging() && (use.moved || use.left)) {
            fprintf(stderr, "[menu-mouse] hand at spot %d, cursor on %d, target %d\n", spot, hit, select_target);
        }
        if (use.moved && hit >= 0) {
            select_target = hit;
            select_press_a = false;
        }
        if (use.left && hit >= 0) {
            select_target = hit;
            select_press_a = true;
        }
        if (select_target < 0) {
            return;
        }
        if (select_target == spot) {
            if (select_press_a) {
                press.fetch_or(button_a);
                if (logging()) {
                    fprintf(stderr, "[menu-mouse] A on spot %d\n", spot);
                }
            }
            select_target = -1;
            select_press_a = false;
            return;
        }
        // Along the row first, then up or down; the game takes one step each time its timer is up.
        const int column = spot & 3, target_column = select_target & 3;
        if (column != target_column) {
            stick_x.store(target_column > column ? 1 : -1);
        } else {
            stick_step.store((select_target >> 2) > (spot >> 2) ? -1 : 1);
        }
    }
}

void tooie::menu_mouse::add_options(recomp::config::Config& qol) {
    qol.add_bool_option(enabled_option, "Mouse in the game's menus",
        "The pause menu follows the mouse: the row under the cursor is picked as the cursor moves over it and "
        "a left click presses A on it. A right click is B (back). The cursor shows once the mouse is used.", true);
}

void tooie::menu_mouse::tick(uint8_t* rdram, recomp_context* /*ctx*/) {
    stick_step.store(0);
    stick_x.store(0);
    press.store(0);

    // The save select's hand updated since the last tick.
    static uint32_t calls_seen = 0;
    const uint32_t calls = select_calls.load();
    const uint32_t menu = select_menu.load();
    const bool hand_active = calls != calls_seen && tooie::rdram::valid_ptr(menu);
    calls_seen = calls;
    const bool in_save_select = tooie::debug::current_map(rdram) == save_select_map;
    const uint32_t pause = tooie::rdram::read_word(rdram, pause_menu_addr);
    const bool pause_open = tooie::rdram::valid_ptr(pause) && read_byte(rdram, pause + pause_exit_type) == 0;
    const bool on = enabled() && (pause_open || in_save_select);
    recompinput::set_game_menu_mouse(on);
    // The save select's hand is the cursor while it follows the mouse; elsewhere (copy, erase, yes/no) the system one shows.
    static int hand_idle = 100;
    hand_idle = hand_active ? 0 : hand_idle + 1;
    const bool hand_hides_cursor = on && !pause_open && hand_idle < 30;
    if (!on) {
        pad_used.store(false);
        take_mouse_use(true);
        clear_steer();
        return;
    }

    const MouseUse use = take_mouse_use(false);
    // The mouse is in use from its first move or click until the pad is used; until then the menus are vanilla
    // (no cursor, the mouse does nothing).
    static bool mouse_in_use = false;
    if (pad_used.exchange(false)) {
        mouse_in_use = false;
    }
    if (use.moved || use.left || use.right) {
        mouse_in_use = true;
    }
    recompinput::set_game_menu_cursor_hidden(!mouse_in_use || hand_hides_cursor);
    if (!mouse_in_use) {
        clear_steer();
        return;
    }
    float x = 0.0f, y = 0.0f;
    const bool have_cursor = cursor_in_frame(&x, &y);
    if (logging() && (use.moved || use.left || use.right)) {
        fprintf(stderr, "[menu-mouse] cursor %.1f,%.1f%s%s page %u\n", x, y, use.left ? " left" : "", use.right ? " right" : "",
            read_byte(rdram, pause + pause_page));
    }

    if (use.right) {
        press.fetch_or(button_b);
        clear_steer();
        return;
    }
    if (!pause_open) {
        // The save select: the hand steers to what the cursor is over; elsewhere in it A and B.
        if (use.left && !hand_active) {
            press.fetch_or(button_a);
        }
        if (hand_active) {
            float sx = 0.0f, sy = 0.0f;
            const bool have = cursor_in_800(&sx, &sy);
            steer_select(rdram, menu, use, sx, sy, have);
        } else {
            clear_steer();
        }
        return;
    }
    if (read_byte(rdram, pause + pause_page) == page_main) {
        // While "are you sure?" is up the rows don't move; a left click answers with A.
        const bool confirming = read_byte(rdram, pause + pause_confirm) != 0;
        if (confirming) {
            clear_steer();
            if (use.left) {
                press.fetch_or(button_a);
            }
            return;
        }
        steer_options(rdram, pause + pause_options, true, use, x, y, have_cursor);
    } else {
        clear_steer();
    }
}

void tooie::menu_mouse::apply_input(uint16_t* buttons, float* x, float* y) {
    // What the player's own controller or keys do (before the mouse's presses are added): a press or a pushed
    // stick hands the menus back to the pad, as in the vanilla game.
    if (*buttons != 0 || std::fabs(*x) > 0.4f || std::fabs(*y) > 0.4f) {
        pad_used.store(true);
    }
    const int step_x = stick_x.load();
    if (step_x != 0) {
        *x = (float)step_x;
    }
    const int step = stick_step.load();
    if (step != 0) {
        *y = (float)step;
    }
    *buttons |= press.load();
}

extern "C" void tooie_select_menu(uint8_t* /*rdram*/, recomp_context* ctx) {
    select_menu.store((uint32_t)ctx->r16);
    select_calls.fetch_add(1);
}
