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
// While Start can't open the pause menu (a cutscene, a map change) Esc doesn't open the ESC menu either
// (open_allowed, asked by the frontend); the title screen and file select still open it.
//
// Menu Slide (QOL > Menu, 2026-11-10, on by default): the Esc menu slides in from the left and out again
// (RecompFrontend's Modal, lib-patches/RecompFrontend.patch), and plays the sounds the Start menu's rows make
// as they slide in and out. Those rows are gczoombox boxes, which play their sounds through
// gcaudiolist_entrypoint_1(sound, 0x4650). Traced in game (2026-11-12): opening, each of the five rows plays 4
// as it starts in and 2 as it lands 0.25 s later, a row about 0.1 s after the one above; closing plays 3, and 5
// about 0.28 s later; moving the highlight plays nothing. The Esc menu tells us each wave of rows starting and
// landing, and the slide out starting; 5 follows the slide out here. The menu asks for the sounds on the main
// thread; tick() plays them on the game thread, through the overlay's thunk as the game does.
//
// Headless: TOOIE_MENU_PAUSE_LOG=1 logs `[menu-pause]` when the pause starts and ends, and each slide sound.

#include <atomic>
#include <chrono>
#include <deque>
#include <mutex>
#include <cstdio>
#include <cstdlib>
#include <vector>

#include "librecomp/config.hpp"
#include "recompui/config.h"
#include "ultramodern/ultramodern.hpp"

#include "funcs.h"
#include "tooie_debug.h"
#include "tooie_game.h"
#include "tooie_menu_pause.h"
#include "tooie_rdram.h"

namespace {
    using tooie::rdram::write_float;
    using tooie::rdram::read_word;

    constexpr uint32_t delta_time_addr = 0x8012C760;
    constexpr uint32_t game_pause_addr = 0x80128AF0;
    // As photo mode's: not zero, as some code divides by it.
    constexpr float frozen_delta = 1.0e-7f;
    constexpr int32_t pause_track = 0x24;
    constexpr uint32_t fade_ms = 0x7D0;
    constexpr uint32_t slots_addr = 0x801357D0;
    constexpr uint32_t slot_size = 0x50;
    constexpr uint32_t slot_count = 6;

    // gcaudiolist's sounds for a Start menu row, at the volume the pause menu gives them: starting in, landing,
    // starting out, and the end of the slide out.
    constexpr int32_t row_in_sound = 4;
    constexpr int32_t row_land_sound = 2;
    constexpr int32_t out_sound = 3;
    constexpr int32_t out_end_sound = 5;
    constexpr uint32_t slide_sound_volume = 0x4650;
    constexpr auto out_end_delay = std::chrono::milliseconds(280);

    std::atomic<bool> menu_open{false};
    // The slide sounds to play, each from its time on (main thread in, game thread out).
    struct PendingSound {
        std::chrono::steady_clock::time_point due;
        int32_t sound;
    };
    std::mutex pending_mutex;
    std::deque<PendingSound> pending_sounds;
    std::atomic<bool> allowed{true};
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

bool tooie::menu_pause::slide_enabled() {
    try {
        return std::get<bool>(recompui::config::get_config(tooie::qol_tab_id).get_option_value(tooie::menu_pause::slide_option));
    } catch (...) {
        return true;
    }
}

void tooie::menu_pause::slide_sound(recompui::config::SlideSound sound) {
    // The menu also opens from the launcher, before the game runs: no sound then, and none left over for later.
    if (!ultramodern::is_game_started()) {
        return;
    }
    using recompui::config::SlideSound;
    const auto now = std::chrono::steady_clock::now();
    std::lock_guard lock(pending_mutex);
    switch (sound) {
    case SlideSound::RowIn:
        // Opened again during the slide out: the end of the slide out doesn't come.
        while (!pending_sounds.empty() && pending_sounds.back().sound == out_end_sound) {
            pending_sounds.pop_back();
        }
        pending_sounds.push_back({ now, row_in_sound });
        break;
    case SlideSound::RowLand:
        pending_sounds.push_back({ now, row_land_sound });
        break;
    case SlideSound::Out:
        // Shut while still coming in: the rows' sounds still to come are dropped.
        pending_sounds.clear();
        pending_sounds.push_back({ now, out_sound });
        pending_sounds.push_back({ now + out_end_delay, out_end_sound });
        break;
    }
}

void tooie::menu_pause::set_menu_open(bool open) {
    menu_open = open;
}

bool tooie::menu_pause::open_allowed() {
    return allowed.load();
}

bool tooie::menu_pause::pausing() {
    return paused;
}

void tooie::menu_pause::tick(uint8_t* rdram, recomp_context* ctx) {
    std::vector<int32_t> sounds;
    {
        const auto now = std::chrono::steady_clock::now();
        std::lock_guard lock(pending_mutex);
        while (!pending_sounds.empty() && pending_sounds.front().due <= now) {
            sounds.push_back(pending_sounds.front().sound);
            pending_sounds.pop_front();
        }
    }
    for (const int32_t sound : sounds) {
        call_game(rdram, ctx, _gcaudiolist_entrypoint_1, (uint32_t)sound, slide_sound_volume);
        if (log_on()) {
            std::fprintf(stderr, "[menu-pause] slide sound %d\n", sound);
        }
    }
    // Start can't open the pause menu in a cutscene or while a map loads, so the ESC menu stays shut too.
    const bool now_allowed = !(enabled() && tooie::debug::can_warp() &&
        (tooie::in_letterboxed_scene() || tooie::debug::map_change_busy(rdram)));
    if (allowed.exchange(now_allowed) != now_allowed && log_on()) {
        std::fprintf(stderr, "[menu-pause] Esc menu %s\n", now_allowed ? "allowed" : "blocked");
    }
    const bool game_pause = read_word(rdram, game_pause_addr) != 0;
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
