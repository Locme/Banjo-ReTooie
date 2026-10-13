// Skip cutscenes with B (handoff 4.62, "Skip boss intros").
//
// Boss intros and other scenes the game will not skip run for a minute or more
// and wait on dialogue. With QOL > Skip cutscenes with B on, pressing B while a
// letterboxed scene is on screen (tooie::in_letterboxed_scene, from the FOV
// setter) fast-forwards it: the game clock runs at 16x (as the speed-up key
// does) and A is tapped for the player every few frames so the dialogue pages
// along. Both stop as soon as the gameplay camera is back, after a map change
// that lands in gameplay, or after a safety limit. During the skip the
// player's own A and B are kept from the game.
//
// Headless: Chilly Willy's intro (warp 12C:0) with one B press reaches the
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
    constexpr uint32_t skip_speed = 16;
    // Real time a skip may last at most.
    constexpr auto skip_limit = std::chrono::seconds(45);

    std::atomic<bool> scene_on{false};      // game thread -> input thread
    std::atomic<bool> skip_requested{false}; // input thread -> game thread
    std::atomic<bool> skipping{false};
    uint16_t last_buttons = 0;
    uint32_t polls = 0;
    uint32_t speed_before = 1;
    std::chrono::steady_clock::time_point skip_started;

    bool enabled() {
        try {
            return std::get<bool>(recompui::config::get_config(tooie::qol_tab_id).get_option_value(tooie::cutscene_skip_option));
        } catch (...) {
            return true;
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
    (void)rdram;
    const bool scene = tooie::in_letterboxed_scene();
    static const bool log = std::getenv("TOOIE_CUTSCENE_LOG") != nullptr;
    if (log && scene != scene_on.load()) {
        printf("[cutscene] %s\n", scene ? "scene" : "gameplay");
        fflush(stdout);
    }
    scene_on = scene && enabled();

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
    const bool b_pressed = (now & button_b) && !(last_buttons & button_b);
    last_buttons = now;

    if (skipping) {
        // Tap A: held for two reads, released for two.
        *buttons &= (uint16_t)~(button_a | button_b);
        if ((polls++ / 2) % 2 == 0) {
            *buttons |= button_a;
        }
        return;
    }
    if (scene_on && b_pressed) {
        skip_requested = true;
    }
}
