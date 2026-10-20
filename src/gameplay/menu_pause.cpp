// Pause Special Menu (L, 2026-10-19): QOL > Pause Special Menu, on by default.
//
// While the ESC menu is open during play, gameplay stands still as if Start were pressed, without the
// pause menu drawn over it. The game keeps running and drawing every frame, so the picture's shader
// effects (water, grass, sky, fog) stay live behind the menu (L, 2026-10-20): like photo mode's freeze,
// the frame's delta time (0x8012C760) is set to almost nothing in tooie_warp_tick, after func_800D8FA0
// wrote it, and everything the game moves by delta time stands still.
//
// Music: the game's own pause fades its music slots to silence and plays the pause track (0x24) on its
// background channel (func_800FC124). func_800FC348, which it fades the slots with, leaves the level's own
// track alone while the game runs on (L, 2026-10-20: both played), so each playing slot (the six at
// 0x801357D0, track at +0x28) is faded to 0 with func_800FCAE0 here, and back to its own volume (-1) on
// closing, when the background channel is cleared (func_800FC1A8) as the pause menu does.
//
// Not during the title, the file select, letterboxed scenes or a map change, where Start doesn't pause
// either, nor while the game's own pause menu is open (its pointer at 0x80128AF0).
//
// Headless: TOOIE_MENU_PAUSE_LOG=1 logs `[menu-pause]` when the pause starts and ends.

#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <vector>

#include "librecomp/config.hpp"
#include "recompui/config.h"

#include "funcs.h"
#include "tooie_debug.h"
#include "tooie_game.h"
#include "tooie_menu_pause.h"
#include "tooie_rdram.h"

namespace {
    using tooie::rdram::write_float;

    constexpr uint32_t delta_time_addr = 0x8012C760;
    constexpr uint32_t game_pause_addr = 0x80128AF0;
    // As photo mode's: not zero, as some code divides by it.
    constexpr float frozen_delta = 1.0e-7f;
    constexpr int32_t pause_track = 0x24;
    constexpr uint32_t fade_ms = 0x7D0;
    constexpr uint32_t slots_addr = 0x801357D0;
    constexpr uint32_t slot_size = 0x50;
    constexpr uint32_t slot_count = 6;

    std::atomic<bool> menu_open{false};
    bool paused = false;
    // The tracks the pause faded out, to fade back in.
    std::vector<int16_t> faded;

    bool log_on() {
        static const bool on = std::getenv("TOOIE_MENU_PAUSE_LOG") != nullptr;
        return on;
    }

    bool enabled() {
        try {
            return std::get<bool>(recompui::config::get_config(tooie::qol_tab_id).get_option_value(tooie::menu_pause::option));
        } catch (...) {
            return true;
        }
    }

    void call_game(uint8_t* rdram, recomp_context* ctx, void (*fn)(uint8_t*, recomp_context*), uint32_t a0 = 0, uint32_t a1 = 0, uint32_t a2 = 0) {
        recomp_context saved = *ctx;
        ctx->r29 = (int32_t)((((uint32_t)ctx->r29 - 0x100) & ~0xFu));
        ctx->r4 = (int32_t)a0;
        ctx->r5 = (int32_t)a1;
        ctx->r6 = (int32_t)a2;
        fn(rdram, ctx);
        *ctx = saved;
    }

    bool should_pause(uint8_t* rdram) {
        return menu_open.load() && enabled() && tooie::debug::can_warp() && !tooie::in_letterboxed_scene() &&
            !tooie::debug::map_change_busy(rdram);
    }
}

void tooie::menu_pause::set_menu_open(bool open) {
    menu_open = open;
}

void tooie::menu_pause::tick(uint8_t* rdram, recomp_context* ctx) {
    const bool game_pause = MEM_W(0, game_pause_addr) != 0;
    if (game_pause) {
        // The game's own pause menu plays its music and puts it back itself.
        paused = false;
        return;
    }
    const bool want = should_pause(rdram);
    if (want && !paused) {
        paused = true;
        faded.clear();
        for (uint32_t i = 0; i < slot_count; i++) {
            const int16_t track = (int16_t)MEM_H(0x28, (int32_t)(slots_addr + i * slot_size));
            if (track >= 0 && track != pause_track) {
                faded.push_back(track);
                call_game(rdram, ctx, func_800FCAE0, (uint32_t)(int32_t)track, 0, fade_ms);
            }
        }
        call_game(rdram, ctx, func_800FC124, (uint32_t)pause_track);
        if (log_on()) {
            std::fprintf(stderr, "[menu-pause] paused (map 0x%X), %zu tracks faded\n", tooie::debug::current_map(rdram), faded.size());
        }
    } else if (!want && paused) {
        paused = false;
        for (const int16_t track : faded) {
            call_game(rdram, ctx, func_800FCAE0, (uint32_t)(int32_t)track, (uint32_t)-1, fade_ms);
        }
        faded.clear();
        call_game(rdram, ctx, func_800FC1A8);
        if (log_on()) {
            std::fprintf(stderr, "[menu-pause] resumed\n");
        }
    }
    if (paused) {
        write_float(rdram, delta_time_addr, frozen_delta);
    }
}
