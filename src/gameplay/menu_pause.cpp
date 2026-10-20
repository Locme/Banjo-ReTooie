// Pause Special Menu (L, 2026-10-19): QOL > Pause Special Menu, on by default.
//
// While the ESC menu is open during play, the game thread waits at the start of its frame update
// (tooie_warp_tick, at the entry of func_800A7D84) until the menu closes. Nothing moves, as with the
// game's own pause, but no pause menu is drawn: the screen keeps the last picture (RT64 repaints it
// under the menu, main.cpp update_gfx), the HUD as it was. The game threads run one at a time, so the
// wait is an N64 one (osRecvMesg on our own queue) and the other threads, the sound among them, go
// on: the music keeps playing. A host thread posts to the queue every 20 ms while the game waits, so
// it checks again.
//
// Not during the title, the file select, letterboxed scenes (the music would run ahead of the
// picture) or a map change, where Start doesn't pause either.
//
// The first frame after the wait would step by the whole wait (up to the game's cap of 15/60 s), so
// its delta time (0x8012C760) and frame count (0x8012C764) are set back to those of the frame before.
//
// Headless: TOOIE_MENU_PAUSE_LOG=1 logs `[menu-pause]` when the wait starts and ends.

#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <mutex>
#include <thread>

#include "librecomp/config.hpp"
#include "recompui/config.h"
#include "ultramodern/ultra64.h"
#include "ultramodern/ultramodern.hpp"

#include "tooie_debug.h"
#include "tooie_game.h"
#include "tooie_menu_pause.h"
#include "tooie_rdram.h"

namespace {
    using namespace std::chrono_literals;
    using tooie::rdram::read_float;
    using tooie::rdram::read_word;
    using tooie::rdram::write_float;
    using tooie::rdram::write_word;

    constexpr uint32_t delta_time_addr = 0x8012C760;
    constexpr uint32_t frame_count_addr = 0x8012C764;
    // Our queue (0x18 bytes) and its one message slot, above the pause option copies (pause_settings.cpp)
    // and below Snout jiggle's matrices (0x80EF8000).
    constexpr uint32_t queue_addr = 0x80EF7F00;
    constexpr uint32_t message_addr = 0x80EF7F20;
    constexpr auto wake_interval = 20ms;

    std::atomic<bool> menu_open{false};
    std::atomic<bool> waiting{false};
    std::once_flag started;

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

    bool should_wait(uint8_t* rdram) {
        return menu_open.load() && enabled() && tooie::debug::can_warp() && !tooie::in_letterboxed_scene() &&
            !tooie::debug::map_change_busy(rdram);
    }

    void waker() {
        for (;;) {
            std::this_thread::sleep_for(wake_interval);
            if (waiting.load()) {
                ultramodern::enqueue_external_message((PTR(OSMesgQueue))queue_addr, 0, false, false);
            }
        }
    }
}

void tooie::menu_pause::set_menu_open(bool open) {
    menu_open = open;
}

bool tooie::menu_pause::active() {
    return waiting.load();
}

void tooie::menu_pause::tick(uint8_t* rdram, recomp_context* ctx) {
    (void)ctx;
    static bool resumed = false;
    static float last_delta = 1.0f / 30.0f;
    static uint32_t last_count = 2;

    if (resumed) {
        // This frame's step covers the wait: give it the one before.
        resumed = false;
        write_float(rdram, delta_time_addr, last_delta);
        write_word(rdram, frame_count_addr, last_count);
    }
    if (!should_wait(rdram)) {
        return;
    }

    std::call_once(started, [rdram] {
        osCreateMesgQueue(rdram, (PTR(OSMesgQueue))queue_addr, (PTR(OSMesg))message_addr, 1);
        std::thread(waker).detach();
    });
    last_delta = read_float(rdram, delta_time_addr);
    last_count = read_word(rdram, frame_count_addr);
    if (log_on()) {
        std::fprintf(stderr, "[menu-pause] paused (map 0x%X)\n", tooie::debug::current_map(rdram));
    }
    const auto start = std::chrono::steady_clock::now();
    waiting = true;
    while (should_wait(rdram)) {
        osRecvMesg(rdram, (PTR(OSMesgQueue))queue_addr, NULLPTR, OS_MESG_BLOCK);
    }
    waiting = false;
    resumed = true;
    if (log_on()) {
        std::fprintf(stderr, "[menu-pause] resumed after %.1f s\n",
            std::chrono::duration<double>(std::chrono::steady_clock::now() - start).count());
    }
}
