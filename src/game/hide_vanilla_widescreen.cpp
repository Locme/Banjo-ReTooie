// DEV > Hide Vanilla Widescreen Entry in the Game Menu (L, 2026-10-17; Screen Alignment too, 2026-10-19).
//
// The save select's global settings menu (the TV, chgameselect state 17) has three rows: 0 Screen
// Alignment, 1 Wide-screen Mode, 2 Speaker Mode. The game's own widescreen mode squashes the picture
// for a stretched TV and fights this port's widescreen, and Screen Alignment shifts the picture for
// a TV's overscan, so with the switch on the menu is built with one row, Speaker Mode: every place
// that turns a row number into a setting (the current value, its text, the setting stored, what A
// opens) reads row 0 as row 2. The switch is read when the menu is built, so a change shows the
// next time it opens.
// While it is on, the game's widescreen mode is also kept off (L, 2026-10-17: Aspect Ratio does
// that job), the anamorphic flag the game draws with and the saved setting both, and the screen
// alignment is kept centred.

#include <cstdio>
#include <cstdlib>
#include <vector>

#include "recomp.h"
#include "recompui/config.h"
#include "funcs.h"
#include "tooie_game.h"
#include "tooie_hooks.h"

namespace {
    constexpr int speaker_row = 2;
    constexpr int rows_shown = 1;
    // Value texts are 5 * row + value + 10; the title list has one halfword per row.
    constexpr int texts_per_row = 5;
    // set_widescreen stores the game's anamorphic flag here; glglobalsettings keeps it saved as flag 0xBB9.
    constexpr gpr widescreen_enabled_addr = (int32_t)0x800799B8;
    constexpr int32_t widescreen_flag = 0xBB9;
    // Screen Alignment is saved as two 6-bit numbers, x + 0x20 from flag 0xBBA and y + 0x28 from 0xBC0
    // (glglobalsettings_entrypoint_5/6); func_80015670(x, y) moves the picture.
    constexpr int32_t align_x_flag = 0xBBA;
    constexpr int32_t align_y_flag = 0xBC0;
    constexpr int32_t align_bits = 6;
    constexpr int32_t align_x_centre = 0x20;
    constexpr int32_t align_y_centre = 0x28;
    // How often the saved settings are checked, in game frames.
    constexpr int flag_check_frames = 30;

    // Whether the menu that is open was built with only Speaker Mode.
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

    // The game's row for a row on screen.
    int game_row(int row) {
        return hidden && row == 0 ? speaker_row : row;
    }

    // Calls a game function from the frame tick, on a stack below the tick's.
    recomp_context call_context(recomp_context* ctx) {
        recomp_context call = *ctx;
        call.r29 = ctx->r29 - 0x100;
        return call;
    }

    int32_t flag_value(uint8_t* rdram, recomp_context* ctx, int32_t first, int32_t bits) {
        recomp_context call = call_context(ctx);
        call.r4 = (uint64_t)(int64_t)first;
        call.r5 = (uint64_t)(int64_t)bits;
        func_800DA564(rdram, &call); // the game's getter for a number kept in flags
        return (int32_t)call.r2;
    }

    void set_flag_value(uint8_t* rdram, recomp_context* ctx, int32_t first, int32_t value, int32_t bits) {
        recomp_context call = call_context(ctx);
        call.r4 = (uint64_t)(int64_t)first;
        call.r5 = (uint64_t)(int64_t)value;
        call.r6 = (uint64_t)(int64_t)bits;
        func_800DA7A8(rdram, &call); // and its setter
    }
}

// Building the menu, $a2 = its row count (3).
extern "C" void tooie_vanilla_widescreen_rows(uint8_t* rdram, recomp_context* ctx) {
    hidden = ctx->r6 == 3 && enabled();
    if (hidden) {
        ctx->r6 = rows_shown;
    }
    if (log_enabled()) {
        std::printf("[global-settings] menu built, %d rows%s\n", (int)ctx->r6, hidden ? " (only Speaker Mode)" : "");
    }
}

// The rows' setup loop: $s3 = the row count.
extern "C" void tooie_vanilla_widescreen_loop(uint8_t* rdram, recomp_context* ctx) {
    if (hidden) {
        ctx->r19 = rows_shown;
    }
}

// Before row $s0's title is set from the title list at $s1 (one row, so $s1 is moved once).
extern "C" void tooie_vanilla_widescreen_title(uint8_t* rdram, recomp_context* ctx) {
    int row = (int)ctx->r16;
    if (game_row(row) != row) {
        ctx->r17 = ADD32(ctx->r17, (game_row(row) - row) * 2);
    }
}

// A row's current setting, $a0 = the row.
extern "C" void tooie_vanilla_widescreen_row_a0(uint8_t* rdram, recomp_context* ctx) {
    ctx->r4 = game_row((int)ctx->r4);
}

// A row's value text, $a1 = the row.
extern "C" void tooie_vanilla_widescreen_text(uint8_t* rdram, recomp_context* ctx) {
    int row = (int)ctx->r5;
    ctx->r6 = ADD32(ctx->r6, (game_row(row) - row) * texts_per_row);
}

// The menu's update keeps the row at 0x30($sp).
extern "C" void tooie_vanilla_widescreen_row_stack(uint8_t* rdram, recomp_context* ctx) {
    MEM_W(0x30, ctx->r29) = game_row((int)MEM_W(0x30, ctx->r29));
}

// A row's refresh after its value was edited, $a0 = the row: row 0 would reset Screen Alignment
// instead of showing Speaker Mode's new value.
extern "C" void tooie_vanilla_widescreen_refresh(uint8_t* rdram, recomp_context* ctx) {
    ctx->r4 = game_row((int)ctx->r4);
}

// Once a frame (tooie_warp_tick): with the switch on, the game's widescreen mode stays off and the
// screen alignment centred.
void tooie::vanilla_widescreen_tick(uint8_t* rdram, recomp_context* ctx) {
    static int frames = 0;
    if (!enabled()) {
        return;
    }
    if (MEM_H(0, widescreen_enabled_addr) != 0) {
        MEM_H(0, widescreen_enabled_addr) = 0;
        if (log_enabled()) {
            std::printf("[global-settings] game widescreen turned off\n");
        }
    }
    if (++frames < flag_check_frames) {
        return;
    }
    frames = 0;
    recomp_context call = call_context(ctx);
    call.r4 = (uint64_t)(int64_t)widescreen_flag;
    func_800DA298(rdram, &call); // the game's flag getter
    if (call.r2 != 0) {
        call = call_context(ctx);
        call.r4 = (uint64_t)(int64_t)widescreen_flag;
        call.r5 = 0;
        func_800DA3B8(rdram, &call); // the game's flag setter
        if (log_enabled()) {
            std::printf("[global-settings] saved game widescreen setting cleared\n");
        }
    }
    int32_t x = flag_value(rdram, ctx, align_x_flag, align_bits);
    int32_t y = flag_value(rdram, ctx, align_y_flag, align_bits);
    if (x != align_x_centre || y != align_y_centre) {
        set_flag_value(rdram, ctx, align_x_flag, align_x_centre, align_bits);
        set_flag_value(rdram, ctx, align_y_flag, align_y_centre, align_bits);
        call = call_context(ctx);
        call.r4 = 0;
        call.r5 = 0;
        func_80015670(rdram, &call); // moves the picture back to the centre
        if (log_enabled()) {
            std::printf("[global-settings] screen alignment %d,%d centred\n", x - align_x_centre, y - align_y_centre);
        }
    }
}

// ---- The pause menu's Settings page (L, 2026-10-20): the TV's settings in the Start menu, the rows the
// TV shows (Speaker Mode; Wide-screen Mode too while the switch above is off). Screen Alignment, a
// picture you move with the stick, is left to the TV. Values are read and set with the TV's own
// glglobalsettings calls, so the game saves them the way it saves the TV's.
namespace {
    // Speaker Mode's values, as the TV names them (flag 0xBC6, 2 bits; checked headless).
    const char* const speaker_names[] = { "MONO", "STEREO", "HEADPHONE", "DOLBY SURROUND" };
    constexpr int32_t speaker_flag = 0xBC6;
    constexpr int32_t speaker_bits = 2;
    constexpr int speaker_values = 4;

    enum Setting { setting_speaker, setting_widescreen };

    std::vector<Setting> settings_shown() {
        std::vector<Setting> shown;
        if (!enabled()) {
            shown.push_back(setting_widescreen);
        }
        shown.push_back(setting_speaker);
        return shown;
    }

    void call_entrypoint(uint8_t* rdram, recomp_context* ctx, void (*func)(uint8_t*, recomp_context*), int32_t a0) {
        recomp_context call = call_context(ctx);
        call.r4 = (uint64_t)(int64_t)a0;
        func(rdram, &call); // loads glglobalsettings if it is not
    }
}

std::vector<tooie::game_settings::Row> tooie::game_settings::rows(uint8_t* rdram, recomp_context* ctx) {
    std::vector<Row> out;
    for (Setting s : settings_shown()) {
        if (s == setting_speaker) {
            const int32_t value = flag_value(rdram, ctx, speaker_flag, speaker_bits);
            out.push_back({ "SPEAKER MODE", speaker_names[value & (speaker_values - 1)] });
        } else {
            recomp_context call = call_context(ctx);
            call.r4 = (uint64_t)(int64_t)widescreen_flag;
            func_800DA298(rdram, &call); // the game's flag getter
            out.push_back({ "WIDE-SCREEN MODE", call.r2 != 0 ? "ON" : "OFF" });
        }
    }
    return out;
}

void tooie::game_settings::change(uint8_t* rdram, recomp_context* ctx, size_t row, int step) {
    const std::vector<Setting> shown = settings_shown();
    if (row >= shown.size() || step == 0) {
        return;
    }
    if (shown[row] == setting_speaker) {
        const int32_t value = flag_value(rdram, ctx, speaker_flag, speaker_bits);
        const int32_t next = ((value + step) % speaker_values + speaker_values) % speaker_values;
        call_entrypoint(rdram, ctx, _glglobalsettings_entrypoint_8, next); // sets the sound output and saves the flag
        if (log_enabled()) {
            std::printf("[global-settings] pause menu: speaker mode %d -> %d\n", value, next);
        }
    } else {
        recomp_context call = call_context(ctx);
        call.r4 = (uint64_t)(int64_t)widescreen_flag;
        func_800DA298(rdram, &call);
        const int32_t next = call.r2 != 0 ? 0 : 1;
        call_entrypoint(rdram, ctx, _glglobalsettings_entrypoint_4, next); // set_widescreen and the flag
        if (log_enabled()) {
            std::printf("[global-settings] pause menu: wide-screen mode %d\n", next);
        }
    }
}
