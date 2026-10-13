// Timer save (handoff 4.13): saves the game every 5, 10, 30, 60 or 120 minutes of play.
//
// The game keeps play time per level in 14 floats at 0x8012C7A0
// (func_800DAE9C). It only adds to them while a level is being played: not
// paused, not in a cutscene, and with the current level (0x8012762C) a real
// level (0x0F..0x1B, not 0x11). So "minutes of play" is read straight from the
// game: when the total has grown by the interval since the last save, the next
// frame on which it is still growing saves.
//
// The save itself is what the pause menu's "Save and quit" does first:
// func_800D389C checks func_800D3770 (a level, and a file open: slot byte
// 0x8012B3F1 != -1) and then calls _glsavegame_entrypoint_7(slot), which
// writes the file to the EEPROM. Only that call is made here; the quit part
// is left out. It runs from tooie_warp_tick at the start of func_800A7D84, the
// game thread's per-frame state update, between frames. A "Game saved" notice
// shows.
//
// TOOIE_TIMER_SAVE_SECONDS=<n> sets the interval in seconds for tests.

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "recomp.h"
#include "funcs.h"
#include "recompui/config.h"
#include "tooie_game.h"
#include "tooie_toast.h"

namespace {
    constexpr gpr play_time_addr = (int32_t)0x8012C7A0;  // float[14], seconds per level
    constexpr int play_time_count = 14;
    constexpr gpr current_level_addr = (int32_t)0x8012762C;
    constexpr gpr save_slot_addr = (int32_t)0x8012B3F1;
    constexpr gpr map_change_request_addr = (int32_t)0x80127642;
    constexpr gpr pause_menu_addr = (int32_t)0x80128AF0;   // pause menu object while paused

    // The total the last save (or the file being opened) happened at, and the
    // slot it belongs to. -1: no file seen yet.
    double last_save_time = 0.0;
    double last_seen_time = 0.0;
    int tracked_slot = -1;

    double play_time(uint8_t* rdram) {
        double total = 0.0;
        for (int i = 0; i < play_time_count; i++) {
            uint32_t bits = MEM_W(i * 4, play_time_addr);
            float f;
            memcpy(&f, &bits, sizeof(f));
            total += f;
        }
        return total;
    }

    double interval_seconds() {
        static const char* env = std::getenv("TOOIE_TIMER_SAVE_SECONDS");
        if (env != nullptr) {
            return std::atof(env);
        }
        uint32_t value = 0;
        try {
            value = std::get<uint32_t>(recompui::config::get_general_config().get_option_value(tooie::timer_save_option));
        } catch (...) {
        }
        switch (static_cast<tooie::TimerSave>(value)) {
            case tooie::TimerSave::Minutes5:   return 5 * 60.0;
            case tooie::TimerSave::Minutes10:  return 10 * 60.0;
            case tooie::TimerSave::Minutes30:  return 30 * 60.0;
            case tooie::TimerSave::Minutes60:  return 60 * 60.0;
            case tooie::TimerSave::Minutes120: return 120 * 60.0;
            default: return 0.0;
        }
    }

    bool in_saveable_level(uint8_t* rdram) {
        int level = MEM_BU(0, current_level_addr);
        return level >= 0x0F && level < 0x1C && level != 0x11;
    }
}

void tooie::timer_save_tick(uint8_t* rdram, recomp_context* ctx) {
    int slot = MEM_B(0, save_slot_addr);
    double now = play_time(rdram);
    if (slot != tracked_slot) {
        // A file was opened, closed or swapped: start counting from here.
        tracked_slot = slot;
        last_save_time = now;
        last_seen_time = now;
        return;
    }
    bool playing = now > last_seen_time;
    last_seen_time = now;

    double interval = interval_seconds();
    if (slot < 0 || interval <= 0.0) {
        last_save_time = now;
        return;
    }
    if (now - last_save_time < interval) {
        return;
    }
    // Due. Wait for a frame of actual play: no pause, no cutscene, no map change.
    if (!playing || !in_saveable_level(rdram) || MEM_W(0, pause_menu_addr) != 0 || MEM_BU(0, map_change_request_addr) != 0) {
        return;
    }

    fprintf(stderr, "[timer save] saving slot %d at %.0f s of play\n", slot, now);
    recomp_context saved = *ctx;
    ctx->r4 = slot;
    _glsavegame_entrypoint_7(rdram, ctx);
    *ctx = saved;
    last_save_time = now;
    tooie::toast::show("Game saved");
}
