// DEV > Hide Vanilla Widescreen Entry in the Game Menu (L, 2026-10-17).
//
// The save select's global settings menu (the TV, chgameselect state 17) has three rows: 0 Screen
// Alignment, 1 Wide-screen Mode, 2 Speaker Mode. The game's own widescreen mode squashes the picture
// for a stretched TV and fights this port's widescreen, so with the switch on the menu is built with
// two rows and row 1 is Speaker Mode: every place that turns a row number into a setting
// (the current value, its text, the setting stored, what A opens) reads row 1 as row 2.
// The switch is read when the menu is built, so a change shows the next time it opens.

#include <cstdio>
#include <cstdlib>

#include "recomp.h"
#include "recompui/config.h"
#include "tooie_game.h"
#include "tooie_hooks.h"

namespace {
    constexpr int widescreen_row = 1;
    constexpr int speaker_row = 2;
    // Value texts are 5 * row + value + 10.
    constexpr int texts_per_row = 5;

    // Whether the menu that is open was built without the row.
    bool hidden = false;

    bool enabled() {
        try {
            return std::get<bool>(recompui::config::get_config(tooie::wip_tab_id).get_option_value(tooie::hide_vanilla_widescreen_option));
        } catch (...) {
            return true;
        }
    }

    bool log_enabled() {
        static const bool on = std::getenv("TOOIE_GLOBAL_SETTINGS_LOG") != nullptr;
        return on;
    }
}

// Building the menu, $a2 = its row count (3).
extern "C" void tooie_vanilla_widescreen_rows(uint8_t* rdram, recomp_context* ctx) {
    hidden = ctx->r6 == 3 && enabled();
    if (hidden) {
        ctx->r6 = 2;
    }
    if (log_enabled()) {
        std::printf("[global-settings] menu built, %d rows%s\n", (int)ctx->r6, hidden ? " (Wide-screen Mode hidden)" : "");
    }
}

// The rows' setup loop: $s3 = the row count.
extern "C" void tooie_vanilla_widescreen_loop(uint8_t* rdram, recomp_context* ctx) {
    if (hidden) {
        ctx->r19 = 2;
    }
}

// Before row $s0's title is set from the title list at $s1: row 1 takes the next title.
extern "C" void tooie_vanilla_widescreen_title(uint8_t* rdram, recomp_context* ctx) {
    if (hidden && ctx->r16 == widescreen_row) {
        ctx->r17 = ADD32(ctx->r17, 2);
    }
}

// A row's current setting, $a0 = the row.
extern "C" void tooie_vanilla_widescreen_row_a0(uint8_t* rdram, recomp_context* ctx) {
    if (hidden && ctx->r4 == widescreen_row) {
        ctx->r4 = speaker_row;
    }
}

// A row's value text, $a1 = the row.
extern "C" void tooie_vanilla_widescreen_text(uint8_t* rdram, recomp_context* ctx) {
    if (hidden && ctx->r5 == widescreen_row) {
        ctx->r6 = ADD32(ctx->r6, (speaker_row - widescreen_row) * texts_per_row);
    }
}

// The menu's update keeps the row at 0x30($sp).
extern "C" void tooie_vanilla_widescreen_row_stack(uint8_t* rdram, recomp_context* ctx) {
    if (hidden && MEM_W(0x30, ctx->r29) == widescreen_row) {
        MEM_W(0x30, ctx->r29) = speaker_row;
    }
}
