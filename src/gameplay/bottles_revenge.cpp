// Cut Content: Bottles' Revenge (handoff 4.77).
//
// The game still has the two-player mode that was cut before release: the game mode byte at
// 0x8012B3F2 (D_8012B3F2) set to 1, the value of the old GameShark code, makes every area spawn Devil
// Bottles, who follows Banjo and is played with controller 2 (R and the stick to possess an enemy).
// The byte is set every frame while the option is on, so each area loads with him, and turning the
// option on or off reloads the current area at the entrance the player came in by.
//
// Controllers: single player mode normally sends every pad to every N64 controller, so player 2 would
// copy player 1. While the mode is on, recompinput's split controllers (lib-patches/RecompFrontend.patch)
// give N64 controller 2 the second pad only, and the keyboard stays with player 1.
//
// The mode's intro (Bottles' ghost turning into Devil Bottles) only plays in Spiral Mountain, the first time
// the mode is on there: the actor's spawn handler checks game flag 0xCA (decomp gameflags.h
// FLAG_0CA_SEEN_BOTTLES_REVENGE_INTRO) and the scene sets it when its dialogue ends. So while the mode is
// on and the loaded file has not seen it, the player is warped to Spiral Mountain to watch it (L,
// 2026-10-15), then taken back to the area and entrance they came from once the scene is over. That is
// tried once per save file per run, so leaving early or skipping does not loop, and the flag (saved with
// the file) stops it for good.
//
// TOOIE_BOTTLES=1 turns it on for headless runs.

#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <variant>

#include "recomp.h"
#include "funcs.h"
#include "recompui/config.h"
#include "recompinput/input_state.h"
#include "tooie_bottles_revenge.h"
#include "tooie_debug.h"
#include "tooie_game.h"

namespace {
    constexpr gpr game_mode_addr = (int32_t)0x8012B3F2;
    constexpr uint8_t mode_bottles_revenge = 1;
    // The game-state block holding map change requests: +0x12 go byte, +0x13 exit.
    constexpr gpr game_state_addr = (int32_t)0x80127630;

    // The open save file (-1 = none).
    constexpr gpr save_slot_addr = (int32_t)0x8012B3F1;
    constexpr uint16_t spiral_mountain_map = 0xAF;
    constexpr int32_t seen_intro_flag = 0xCA;
    // Gameplay frames to wait after the intro's scene ends before warping back.
    constexpr int return_delay_frames = 30;

    std::atomic<bool> reload_requested{false};
    bool was_on = false;

    // The intro warp: save files it was tried for in this run (by slot + 1; 0 is a debug warp with no
    // file open), and the way back.
    bool intro_tried[9] = {};
    enum class IntroWarp { none, going, watching };
    IntroWarp intro_warp = IntroWarp::none;
    uint16_t return_map = 0;
    uint8_t return_exit = 0;
    int return_wait = 0;

    bool option_on() {
        static const bool forced = std::getenv("TOOIE_BOTTLES") != nullptr;
        if (forced) {
            return true;
        }
        try {
            return std::get<bool>(recompui::config::get_general_config().get_option_value(tooie::bottles_revenge::option));
        } catch (...) {
            return false;
        }
    }
}

namespace {
    // The game's map change, func_800A7990(map, exit, transition), called as if from the hook.
    void change_map(uint8_t* rdram, recomp_context* ctx, uint16_t map, uint8_t exit) {
        recomp_context saved = *ctx;
        ctx->r29 = (int32_t)((((uint32_t)ctx->r29 - 0x100) & ~0xFu));
        ctx->r4 = map;
        ctx->r5 = exit;
        ctx->r6 = 1;
        func_800A7990(rdram, ctx);
        *ctx = saved;
    }

    // The game's flag getter (func_800DA298).
    bool flag_get(uint8_t* rdram, recomp_context* ctx, int32_t flag) {
        recomp_context saved = *ctx;
        ctx->r29 = (int32_t)((((uint32_t)ctx->r29 - 0x100) & ~0xFu));
        ctx->r4 = (uint64_t)(int64_t)flag;
        func_800DA298(rdram, ctx);
        const bool value = (int32_t)ctx->r2 != 0;
        *ctx = saved;
        return value;
    }

    // Warps to the intro if the open file has not seen it, and back once it has. True if a map change was
    // issued this frame.
    bool intro_tick(uint8_t* rdram, recomp_context* ctx, bool on) {
        if (!tooie::debug::can_warp()) {
            intro_warp = IntroWarp::none;
            return false;
        }
        const uint16_t map = tooie::debug::current_map(rdram);
        const bool changing = MEM_B(0x12, game_state_addr) != 0;

        if (intro_warp == IntroWarp::going) {
            if (!changing && map == spiral_mountain_map) {
                intro_warp = IntroWarp::watching;
                return_wait = 0;
            }
            return false;
        }
        if (intro_warp == IntroWarp::watching) {
            // Left Spiral Mountain (or turned the mode off) before the scene was over: stay where they are.
            if (map != spiral_mountain_map || !on) {
                fprintf(stderr, "[bottles] left the intro early, not warping back\n");
                intro_warp = IntroWarp::none;
                return false;
            }
            if (changing || tooie::in_letterboxed_scene() || !flag_get(rdram, ctx, seen_intro_flag)) {
                return_wait = 0;
                return false;
            }
            if (++return_wait < return_delay_frames) {
                return false;
            }
            intro_warp = IntroWarp::none;
            fprintf(stderr, "[bottles] intro seen, back to map 0x%X exit %u\n", return_map, return_exit);
            change_map(rdram, ctx, return_map, return_exit);
            return true;
        }

        if (!on || changing || map == spiral_mountain_map || tooie::in_letterboxed_scene()) {
            return false;
        }
        const int index = (int8_t)MEM_B(0, save_slot_addr) + 1;
        if (index < 0 || index >= (int)(sizeof(intro_tried) / sizeof(intro_tried[0])) || intro_tried[index]) {
            return false;
        }
        intro_tried[index] = true;
        if (flag_get(rdram, ctx, seen_intro_flag)) {
            return false;
        }
        return_map = map;
        return_exit = MEM_B(0x13, game_state_addr);
        intro_warp = IntroWarp::going;
        fprintf(stderr, "[bottles] intro not seen: warping to Spiral Mountain from map 0x%X exit %u\n", map, return_exit);
        change_map(rdram, ctx, spiral_mountain_map, 0);
        return true;
    }
}

void tooie::bottles_revenge::add_option(recomp::config::Config& general) {
    general.add_bool_option(option, "Cut Content: Bottles' Revenge",
        "The two-player mode cut from the game: Devil Bottles follows Banjo, and player 2 (a second controller) "
        "possesses enemies to attack him. The area reloads when you turn it on or off. If this save file has not seen "
        "the mode's intro, you are taken to Spiral Mountain to watch it once, then brought back.",
        false);
    general.add_option_change_callback(option,
        [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext) {
            reload_requested = true;
        });
}

void tooie::bottles_revenge::tick(uint8_t* rdram, recomp_context* ctx) {
    const bool on = option_on();
    if (on != was_on) {
        was_on = on;
        recompinput::set_split_controllers(on);
        fprintf(stderr, "[bottles] %s\n", on ? "on" : "off");
    }
    if (on) {
        MEM_B(0, game_mode_addr) = mode_bottles_revenge;
    }
    else if (MEM_BU(0, game_mode_addr) == mode_bottles_revenge) {
        MEM_B(0, game_mode_addr) = 0;
    }

    if (intro_tick(rdram, ctx, on)) {
        // The warp to or from the intro loads an area with the mode as it is now.
        reload_requested = false;
        return;
    }

    if (!reload_requested.load()) {
        return;
    }
    if (!tooie::debug::can_warp()) {
        reload_requested = false;
        return;
    }
    // A map change is already under way: try again next frame.
    if (MEM_B(0x12, game_state_addr) != 0) {
        return;
    }
    reload_requested = false;

    const uint16_t map = tooie::debug::current_map(rdram);
    const uint8_t exit = MEM_B(0x13, game_state_addr);
    fprintf(stderr, "[bottles] reloading map 0x%X exit %u\n", map, exit);
    change_map(rdram, ctx, map, exit);
}
