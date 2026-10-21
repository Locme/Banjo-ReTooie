// Skip cutscenes with Start (handoff 4.62, "Skip boss intros").
//
// Boss intros run for a minute or more and wait on dialogue, and the game will
// not skip them. Two QOL toggles (L): "Skip boss intros" (on) for letterboxed
// scenes in a boss's map, and "Skip other cutscenes" (off) for every other
// letterboxed scene, NPC conversations included. With the matching toggle on,
// pressing Start while such a scene is on screen (tooie::in_letterboxed_scene, from the FOV
// setter) fast-forwards it: the game clock runs at 16x (as the speed-up key
// does) and A is tapped for the player every few frames so the dialogue pages
// along. Both stop as soon as the gameplay camera is back, after a map change
// that lands in gameplay, or after a safety limit. During the skip the
// player's own A, B and Start are kept from the game, and the Start press
// that begins a skip is not passed on, so it does not open the pause menu.
// (Was B until L asked for Start, 2026-10-14.) Start again during a skip
// stops it, and the sound is muted while it runs (main.cpp queue_samples)
// rather than played sped up (L).
//
// The boot logos, title (0x18B) and file select (0x158) are never skipped:
// Start there is the game's own (and quick start's), and the A taps would
// pick the first save file.
//
// Headless: Chilly Willy's intro (warp 12C:0) with one Start press reaches the
// fight in about 18 s of real time; with A held it took about 60 s. The boss
// fight camera is not letterboxed, so the skip ends there.
// TOOIE_CUTSCENE_LOG=1 logs scene and gameplay changes.
//
// Holding the Speed-Up key for 3 s in such a scene starts the same skip
// (speedup.cpp, needs Enable cheats and Speed-up on); toasts "Skipping cutscene"
// and "Cutscene skipped" at the end. Shorter holds are plain speed-up.
//
// The game has no skip prompt for these scenes on N64, so nothing is drawn; a
// toast says "Fast Forward Scene" ("Fast Forward stopped" when Start stops it).

#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>

#include "recomp.h"
#include "recompui/config.h"
#include "ultramodern/ultramodern.hpp"
#include "tooie_game.h"
#include "tooie_toast.h"

namespace {
    constexpr uint16_t button_a = 0x8000;
    constexpr uint16_t button_b = 0x4000;
    constexpr uint16_t button_start = 0x1000;
    constexpr uint32_t skip_speed = 16;
    // Real time a skip may last at most.
    constexpr auto skip_limit = std::chrono::seconds(45);

    constexpr gpr current_map_addr = (int32_t)0x80132DC2;
    constexpr uint16_t title_map = 0x18B;
    constexpr uint16_t file_select_map = 0x158;

    std::atomic<bool> scene_on{false};      // game thread -> input thread
    std::atomic<bool> skip_requested{false}; // input thread -> game thread
    std::atomic<bool> stop_requested{false}; // input thread -> game thread
    std::atomic<bool> skipping{false};
    std::atomic<bool> hold_started{false};   // the running skip came from holding Speed-Up
    uint16_t last_buttons = 0;
    uint32_t polls = 0;
    uint32_t speed_before = 1;
    std::chrono::steady_clock::time_point skip_started;

    bool option(const std::string& id, bool fallback) {
        try {
            return std::get<bool>(recompui::config::get_config(tooie::qol_tab_id).get_option_value(id));
        } catch (...) {
            return fallback;
        }
    }

    void stop(const char* why) {
        skipping = false;
        ultramodern::set_speed_multiplier(speed_before);
        printf("[cutscene] skip ended (%s)\n", why);
        fflush(stdout);
    }
}

void tooie::cutscene_skip_tick(uint8_t* rdram) {
    const bool scene = tooie::in_letterboxed_scene();
    const uint16_t map = (uint16_t)MEM_HU(0, current_map_addr);
    const bool menu = map == title_map || map == file_select_map;
    static const bool log = std::getenv("TOOIE_CUTSCENE_LOG") != nullptr;
    if (log && scene != scene_on.load()) {
        printf("[cutscene] %s\n", scene ? "scene" : "gameplay");
        fflush(stdout);
    }
    scene_on = scene && !menu && option(tooie::cutscene_skip_option, true);

    if (skipping) {
        if (stop_requested.exchange(false)) {
            hold_started = false;
            stop("Start pressed");
            tooie::toast::show("Fast Forward stopped");
        } else if (!scene || menu) {
            stop(menu ? "menu" : "scene over");
            if (hold_started.exchange(false) && !menu) {
                tooie::toast::show("Cutscene skipped");
            }
        } else if (std::chrono::steady_clock::now() - skip_started > skip_limit) {
            hold_started = false;
            stop("time limit");
        }
        return;
    }
    stop_requested = false;
    if (skip_requested.exchange(false) && scene_on) {
        speed_before = ultramodern::get_speed_multiplier();
        ultramodern::set_speed_multiplier(skip_speed);
        skip_started = std::chrono::steady_clock::now();
        skipping = true;
        tooie::toast::show(hold_started ? "Skipping cutscene" : "Fast Forward Scene");
        printf("[cutscene] skip started\n");
        fflush(stdout);
    }
}

void tooie::cutscene_skip_apply(uint16_t* buttons) {
    const uint16_t now = *buttons;
    const bool start_pressed = (now & button_start) && !(last_buttons & button_start);
    last_buttons = now;

    if (skipping) {
        if (start_pressed) {
            stop_requested = true;
        }
        // Tap A: held for two reads, released for two.
        *buttons &= (uint16_t)~(button_a | button_b | button_start);
        if ((polls++ / 2) % 2 == 0) {
            *buttons |= button_a;
        }
        return;
    }
    if (scene_on && (now & button_start)) {
        // Start skips here instead of reaching the game (no pause menu).
        *buttons &= (uint16_t)~button_start;
        if (start_pressed) {
            skip_requested = true;
        }
    }
}

bool tooie::cutscene_skip_hold_request() {
    if (!scene_on || skipping) {
        return false;
    }
    hold_started = true;
    skip_requested = true;
    return true;
}

bool tooie::cutscene_skip_active() {
    return skipping;
}
