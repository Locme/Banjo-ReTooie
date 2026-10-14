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

namespace {
    constexpr gpr game_mode_addr = (int32_t)0x8012B3F2;
    constexpr uint8_t mode_bottles_revenge = 1;
    // The game-state block holding map change requests: +0x12 go byte, +0x13 exit.
    constexpr gpr game_state_addr = (int32_t)0x80127630;

    std::atomic<bool> reload_requested{false};
    bool was_on = false;

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

void tooie::bottles_revenge::add_option(recomp::config::Config& general) {
    general.add_bool_option(option, "Cut Content: Bottles' Revenge",
        "The two-player mode cut from the game: Devil Bottles follows Banjo, and player 2 (a second controller) "
        "possesses enemies to attack him. The area reloads when you turn it on or off.",
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
    recomp_context saved = *ctx;
    ctx->r29 = (int32_t)((((uint32_t)ctx->r29 - 0x100) & ~0xFu));
    ctx->r4 = map;
    ctx->r5 = exit;
    ctx->r6 = 1;
    func_800A7990(rdram, ctx);
    *ctx = saved;
}
