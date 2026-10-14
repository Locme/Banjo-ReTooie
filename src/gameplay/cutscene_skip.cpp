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
// (Was B until L asked for Start, 2026-10-14.)
//
// Headless: Chilly Willy's intro (warp 12C:0) with one Start press reaches the
// fight in about 18 s of real time; with A held it took about 60 s. The boss
// fight camera is not letterboxed, so the skip ends there.
// TOOIE_CUTSCENE_LOG=1 logs scene and gameplay changes.
//
// The game has no skip prompt for these scenes on N64, so nothing is drawn; a
// toast says "Skipping cutscene".

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

    // Maps with a boss whose intro the game will not skip (names from src/game/map_names.inc).
    // Weldar's map is inferred from the decomp's map names, not seen headless.
    constexpr uint16_t boss_maps[] = {
        0x17A, // Targitzan's Really Sacred Chamber
        0x0D1, // Inside Chuffy's Boiler (Old King Coal)
        0x0F9, // Mr. Patch
        0x0FC, // Lord Woo Fak Fak
        0x113, // Terry's Nest
        0x110, // GI Repair Depot (Weldar)
        0x12B, // Chilli Billi
        0x12C, // Chilly Willy
        0x13F, // Mingy Jongo's Skull
        0x15F, // Tower of Tragedy
        0x19A, // HAG 1
    };

    bool boss_map(uint16_t map) {
        for (uint16_t m : boss_maps) {
            if (m == map) {
                return true;
            }
        }
        return false;
    }

    std::atomic<bool> scene_on{false};      // game thread -> input thread
    std::atomic<bool> skip_requested{false}; // input thread -> game thread
    std::atomic<bool> skipping{false};
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
    const bool boss = boss_map((uint16_t)MEM_HU(0, current_map_addr));
    static const bool log = std::getenv("TOOIE_CUTSCENE_LOG") != nullptr;
    if (log && scene != scene_on.load()) {
        printf("[cutscene] %s\n", scene ? "scene" : "gameplay");
        fflush(stdout);
    }
    scene_on = scene && (boss ? option(tooie::cutscene_skip_option, true) : option(tooie::cutscene_skip_other_option, false));

    if (skipping) {
        if (!scene) {
            stop("scene over");
        } else if (std::chrono::steady_clock::now() - skip_started > skip_limit) {
            stop("time limit");
        }
        return;
    }
    if (skip_requested.exchange(false) && scene_on) {
        speed_before = ultramodern::get_speed_multiplier();
        ultramodern::set_speed_multiplier(skip_speed);
        skip_started = std::chrono::steady_clock::now();
        skipping = true;
        tooie::toast::show("Skipping cutscene");
        printf("[cutscene] skip started\n");
        fflush(stdout);
    }
}

void tooie::cutscene_skip_apply(uint16_t* buttons) {
    const uint16_t now = *buttons;
    const bool start_pressed = (now & button_start) && !(last_buttons & button_start);
    last_buttons = now;

    if (skipping) {
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
