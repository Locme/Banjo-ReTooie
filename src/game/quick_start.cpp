// Quick start (handoff 4.5): Start during the boot logos goes straight to the
// file select.
//
// The logos, the title flight and the title screen are all one map, 0x18B.
// The game only listens for Start once the title screen is up; it then asks
// for map 0x158 (file select), exit 0, transition 1, which is what we ask for
// too, so the wipe into the menu looks the same either way.
//
// A Start press is noted from the input callback. Two frames later, on the
// game thread, the map change is requested if the game is still on map 0x18B
// and has not asked for a map change of its own (the request byte at
// 0x80127642 is still clear), so on the finished title the game's own Start
// wins and nothing is doubled.

#include <atomic>

#include "recomp.h"
#include "recompui/config.h"
#include "tooie_debug.h"
#include "tooie_game.h"

namespace {
    constexpr uint16_t intro_map = 0x18B;
    constexpr uint16_t file_select_map = 0x158;
    constexpr gpr map_change_request_addr = (int32_t)0x80127642; // D_80127630.unk12
    constexpr uint16_t start_button = 0x1000;

    std::atomic<bool> start_pressed = false;
    uint16_t last_buttons = 0;
    int frames_waited = 0;

    bool enabled() {
        try {
            return std::get<bool>(recompui::config::get_config(tooie::qol_tab_id).get_option_value(tooie::quick_start_option));
        } catch (...) {
            return true;
        }
    }
}

void tooie::quick_start_note_input(uint16_t buttons) {
    if ((buttons & start_button) && !(last_buttons & start_button)) {
        start_pressed = true;
    }
    last_buttons = buttons;
}

void tooie::quick_start_tick(uint8_t* rdram) {
    if (!start_pressed) {
        frames_waited = 0;
        return;
    }
    // Give the game two frames to act on the press itself.
    if (++frames_waited < 2) {
        return;
    }
    start_pressed = false;
    frames_waited = 0;

    if (tooie::debug::current_map(rdram) != intro_map || MEM_BU(0, map_change_request_addr) != 0) {
        return;
    }
    if (!enabled()) {
        return;
    }
    tooie::debug::request_warp(file_select_map, 0);
}
