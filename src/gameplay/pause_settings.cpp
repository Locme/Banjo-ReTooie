// Achievements entry in the pause menu (the Start menu; L named it Settings first, then Achievements on
// 2026-10-16). The entry shows in the main pause page and opens a page of its own titled ACHIEVEMENTS,
// which lists the XBLA achievements (src/game/achievements.cpp) and is drawn by the Totals draw hook
// (src/gameplay/totals_checklist.cpp). B goes back to the main page, Start closes the menu, as on the
// Totals pages.
//
// The pause menu (overlay gcnewpause, decomp src/overlays/gc/newpause.c) builds its main page from
// the table D_80802070: one PauseOption per menu variant (8 bytes: text bank, first option, size,
// options pointer), each option 6 bytes (icon, text index, function, sub option, are-you-sure). The
// options are drawn by gcnewoption, which looks each text index up in a text bank with
// gldbstring_entrypoint_1(bank, index).
//
// The entry is added by pointing the table at copies of the options with one more row, kept in
// extended RDRAM. Its text index (settings_text) is one no bank uses; the gldbstring hook returns
// our own string for it. Picking it opens the Totals page (PageIndex 3) with a sub page of its own
// (settings_sub_page): that page brings the title, the B button, B to go back and Start to close
// with it. The counts the Totals pages draw are skipped on that sub page.

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "recomp.h"
#include "funcs.h"

#include "tooie_achievements.h"
#include "tooie_game.h"
#include "tooie_hooks.h"

namespace {
    // PauseState (decomp include/gc/newpause.h).
    constexpr uint32_t pause_page = 0x00;
    constexpr uint32_t pause_sub_page = 0x01;
    constexpr uint32_t pause_last_option = 0x05;
    constexpr uint32_t pause_variant = 0x0D;
    constexpr uint32_t pause_title_bank = 0x14;     // textPointer: the page titles
    constexpr uint32_t pause_can_move_left = 0x1E;
    constexpr uint32_t pause_can_move_right = 0x1F;
    constexpr uint32_t pause_option_bank = 0x30 + 0x23C;   // OptionState + 0x23C: the options' text bank
    constexpr uint8_t page_totals = 3;

    // PauseOption and Option.
    constexpr uint32_t variant_size = 8;
    constexpr uint32_t variant_count_offset = 3;
    constexpr uint32_t variant_options_offset = 4;
    constexpr uint32_t option_size = 6;
    constexpr uint32_t option_icon = 0;
    constexpr uint32_t option_text = 2;
    constexpr uint32_t option_function = 3;

    // Option functions 0..4 are the game's (return, totals, game over, restart, file select).
    constexpr uint8_t function_totals = 1;
    constexpr uint8_t function_settings = 5;

    // Text index and Totals sub page no bank or page uses (bank entries hold index + 0x80 in a byte,
    // so 0x7E is never one of the game's; Totals sub pages go up to 0xD).
    constexpr uint8_t settings_text = 0x7E;
    constexpr uint8_t settings_sub_page = tooie::achievements::pause_sub_page;

    // The variants that get the entry: 0..3, the normal pause menu (+1 with items, +2 with Jinjos).
    // 4..6 are the menus of special modes (decomp func_80800534 case 1), left as they are.
    constexpr int normal_variants = 4;
    constexpr uint32_t max_options = 16;
    // Option boxes gcnewoption has room for (OptionState 0x3C: five zoombox pointers).
    constexpr gpr visible_rows = 5;

    // Extended RDRAM no one else uses: the Totals checklist's strings end at 0x80EF1000 and the model
    // tagging lists start at 0x80F00000 (src/gameplay/totals_checklist.cpp).
    constexpr gpr option_area = (int32_t)0x80EF1000;
    constexpr uint32_t option_area_variant = 0x80;  // room for max_options rows per variant
    constexpr gpr string_addr = (int32_t)0x80EF1200;
    const char* const settings_string = "ACHIEVEMENTS";

    // The open pause menu's PauseState, 0 when it is closed. The game's heap moves it while it is
    // open, so it is read here each time rather than kept.
    constexpr gpr pause_menu_addr = (int32_t)0x80128AF0;

    bool logging() {
        static const bool log = std::getenv("TOOIE_PAUSE_LOG") != nullptr;
        return log;
    }

    void write_string(uint8_t* rdram) {
        size_t i = 0;
        for (; settings_string[i] != '\0'; i++) {
            MEM_B(i, string_addr) = settings_string[i];
        }
        MEM_B(i, string_addr) = 0;
    }

    void log_string(uint8_t* rdram, gpr addr) {
        char text[64];
        size_t i = 0;
        for (; i + 1 < sizeof(text); i++) {
            uint8_t c = MEM_BU(i, addr);
            if (c == 0) {
                break;
            }
            text[i] = (c >= 0x20 && c < 0x7F) ? (char)c : '?';
        }
        text[i] = '\0';
        fprintf(stderr, "\"%s\"", text);
    }

    // Where in a variant's options the entry goes: after the last Totals page option, else after the first.
    uint32_t insert_index(uint8_t* rdram, gpr options, uint32_t count) {
        uint32_t index = count > 0 ? 1 : 0;
        for (uint32_t i = 0; i < count; i++) {
            if (MEM_BU(i * option_size + option_function, options) == function_totals) {
                index = i + 1;
            }
        }
        return index;
    }

    // The pause overlay (overlay index, 0 when unknown) and where the table sits in it.
    uint32_t overlay_index = 0;
    uint32_t table_offset = 0;

    bool in_overlay(gpr addr) {
        const auto overlays = tooie::mapped_overlays();
        const auto it = overlays.find(overlay_index);
        uint32_t rom_addr, size;
        if (it == overlays.end() || !tooie::overlay_section(overlay_index, rom_addr, size)) {
            return false;
        }
        return addr >= (gpr)it->second && addr < (gpr)it->second + (gpr)size;
    }

    // Points each normal variant at its copy with the Achievements row. A pointer outside the overlay is
    // one of ours: the game moves the overlay with its heap and shifts every pointer in its data by
    // as much, ours included, so it is set back.
    void patch_table(uint8_t* rdram, gpr table) {
        for (int variant = 0; variant < normal_variants; variant++) {
            const gpr entry = table + variant * variant_size;
            const gpr options = (gpr)(int32_t)MEM_W(variant_options_offset, entry);
            const uint32_t count = MEM_BU(variant_count_offset, entry);
            const gpr copy = option_area + variant * option_area_variant;
            if (options == copy) {
                continue;
            }
            if (!in_overlay(options)) {
                MEM_W(variant_options_offset, entry) = (int32_t)copy;
                if (logging()) {
                    fprintf(stderr, "[pause-settings] variant %d pointer 0x%08X set back\n", variant, (uint32_t)options);
                }
                continue;
            }
            if (count + 1 > max_options) {
                continue;
            }

            if (logging()) {
                fprintf(stderr, "[pause-settings] variant %d: %u options at 0x%08X\n", variant, count, (uint32_t)options);
                for (uint32_t i = 0; i < count; i++) {
                    const gpr row = options + i * option_size;
                    fprintf(stderr, "[pause-settings]   %u: icon 0x%04X text %u function %u sub %u sure %u\n", i,
                        MEM_HU(option_icon, row), MEM_BU(option_text, row), MEM_BU(option_function, row),
                        MEM_BU(4, row), MEM_BU(5, row));
                }
            }

            const uint32_t at = insert_index(rdram, options, count);

            uint32_t out = 0;
            for (uint32_t i = 0; i <= count; i++) {
                if (i == at) {
                    // Same icon as the row above it; the text and function are ours. The icon is a talking
                    // head (gczoomboxdata's portrait list); Cheato has none there (swept 0x00..0xD1
                    // headless, 2026-10-16).
                    const gpr dst = copy + out * option_size;
                    const gpr like = options + (at > 0 ? at - 1 : 0) * option_size;
                    MEM_H(option_icon, dst) = MEM_HU(option_icon, like);
                    MEM_B(option_text, dst) = settings_text;
                    MEM_B(option_function, dst) = function_settings;
                    MEM_B(4, dst) = 0;
                    MEM_B(5, dst) = 0;
                    out++;
                }
                if (i == count) {
                    break;
                }
                const gpr src = options + i * option_size;
                const gpr row = copy + out * option_size;
                for (uint32_t b = 0; b < option_size; b++) {
                    MEM_B(b, row) = MEM_BU(b, src);
                }
                out++;
            }
            MEM_W(variant_options_offset, entry) = (int32_t)copy;
            MEM_B(variant_count_offset, entry) = (int8_t)(count + 1);
        }
    }
}

// func_80800A08 (the main page's setup), with $s0 = the table D_80802070.
extern "C" void tooie_pause_settings_setup(uint8_t* rdram, recomp_context* ctx) {
    const gpr table = ctx->r16;
    write_string(rdram);

    // TOOIE_PAUSE_VARIANT=<0-3>: headless test of a menu variant ($t6 holds the variant read from $s4).
    static const char* force = std::getenv("TOOIE_PAUSE_VARIANT");
    if (force != nullptr) {
        const int variant = std::atoi(force) & 3;
        MEM_B(pause_variant, ctx->r20) = (int8_t)variant;
        ctx->r14 = variant;
    }

    // The overlay the table is in, to find it again after the game moves the overlay.
    overlay_index = 0;
    for (const auto& [index, code] : tooie::mapped_overlays()) {
        uint32_t rom_addr, size;
        if (tooie::overlay_section(index, rom_addr, size) && table >= code && table < code + (gpr)size) {
            overlay_index = index;
            table_offset = (uint32_t)(table - code);
            break;
        }
    }
    if (overlay_index == 0) {
        return;
    }
    patch_table(rdram, table);
}

// Start of gcnewpause_entrypoint_2 (the pause menu's update, which picks options): the table's
// pointers to the copies are put right if the game moved the overlay since.
extern "C" void tooie_pause_settings_update(uint8_t* rdram, recomp_context* /*ctx*/) {
    if (overlay_index == 0) {
        return;
    }
    const auto overlays = tooie::mapped_overlays();
    const auto it = overlays.find(overlay_index);
    if (it == overlays.end()) {
        overlay_index = 0;
        return;
    }
    patch_table(rdram, (gpr)it->second + table_offset);
}

// func_80800A08 before it sets how many option boxes are shown ($a1): gcnewoption has room for
// visible_rows, more rows scroll.
extern "C" void tooie_pause_settings_visible(uint8_t* /*rdram*/, recomp_context* ctx) {
    if (ctx->r5 > visible_rows) {
        ctx->r5 = visible_rows;
    }
}

// Start of func_80800CE4 (an option was picked): $a0 the PauseState, $a2 the option. Returns true
// when it was the Achievements entry (handled here).
extern "C" int tooie_pause_settings_select(uint8_t* rdram, recomp_context* ctx) {
    const gpr pause = ctx->r4;
    const uint32_t picked = (uint32_t)ctx->r6;
    const int variant = MEM_B(pause_variant, pause);
    if (variant < 0 || variant >= normal_variants) {
        return 0;
    }
    // The table is reached the way func_80800A08 reached it: the copy lives at a fixed address.
    const gpr options = option_area + variant * option_area_variant;
    if (picked >= max_options || MEM_BU(picked * option_size + option_function, options) != function_settings ||
        MEM_BU(picked * option_size + option_text, options) != settings_text) {
        return 0;
    }
    if (logging()) {
        fprintf(stderr, "[pause-settings] Achievements picked (option %u)\n", picked);
    }

    // As function 1 (open a Totals page), with our sub page and no left/right pages.
    MEM_B(pause_sub_page, pause) = settings_sub_page;
    MEM_B(pause_can_move_left, pause) = 0;
    MEM_B(pause_can_move_right, pause) = 0;
    recomp_context saved = *ctx;
    ctx->r4 = pause;
    ctx->r5 = page_totals;
    func_80800534_gcnewpause(rdram, ctx);
    *ctx = saved;
    MEM_B(pause_last_option, pause) = (int8_t)picked;
    return 1;
}

// Start of func_80800F2C (a Totals page's counts): $a1 the sub page. Nothing to count on ours; the
// achievements are drawn by the Totals draw hook.
extern "C" int tooie_pause_settings_page_counts(uint8_t* /*rdram*/, recomp_context* ctx) {
    if ((uint32_t)ctx->r5 != settings_sub_page) {
        return 0;
    }
    ctx->r2 = 0;
    return 1;
}

// Start of gldbstring_entrypoint_1(bank $a0, index $a1): our string for our index in the pause menu's banks.
extern "C" int tooie_pause_settings_text(uint8_t* rdram, recomp_context* ctx) {
    if ((uint32_t)(ctx->r5 & 0xFFFF) != settings_text) {
        return 0;
    }
    const gpr pause_menu = (gpr)(int32_t)MEM_W(0, pause_menu_addr);
    if (pause_menu == 0) {
        return 0;
    }
    const int32_t bank = (int32_t)ctx->r4;
    if (bank != MEM_W(pause_option_bank, pause_menu) && bank != MEM_W(pause_title_bank, pause_menu)) {
        return 0;
    }
    ctx->r2 = string_addr;
    return 1;
}

// For the log: what gldbstring returned for a pause option (end of the options' text lookup).
extern "C" void tooie_pause_settings_log_text(uint8_t* rdram, recomp_context* ctx) {
    if (!logging() || ctx->r2 == 0) {
        return;
    }
    fprintf(stderr, "[pause-settings] option text ");
    log_string(rdram, ctx->r2);
    fprintf(stderr, "\n");
}
