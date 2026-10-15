// Totals checklist (QOL, on by default): the pause menu's Totals pages say how many of each collectible
// are left in a world, which of them can be got with the moves and transformations the player has now,
// and when there is nothing left to get there yet.
//
// The pause menu (overlay gcnewpause, decomp src/overlays/gc/newpause.c) draws Totals as PageIndex 3;
// SubPage 2 is the game totals and 3..0xD the level pages. The extra lines are printed with the game's
// own text routines in core2 (decomp src/core2/1E91790.c): func_800B8C50 resets the text settings,
// func_800B7F14 / func_800B811C open and close text drawing on the display list, and
// func_800B8E28(gfx, x, y, string) prints a string with the current font, colour and size.

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <variant>

#include "recomp.h"
#include "funcs.h"
#include "recompui/config.h"

#include "tooie_game.h"
#include "tooie_hooks.h"
#include "tooie_totals_checklist.h"

namespace {
    using namespace std::chrono_literals;
    using Clock = std::chrono::steady_clock;

    // PauseState (decomp include/gc/newpause.h).
    constexpr uint32_t pause_page = 0x0;
    constexpr uint32_t pause_sub_page = 0x1;
    constexpr uint32_t pause_draw_header = 0x1B;
    constexpr uint8_t page_totals = 3;

    // Text settings block D_801282C0 (decomp include/core2/1E91790.h): RGB tint, alpha, font,
    // colour (func_800B8CE0 stores colour - 0xC24) and size.
    constexpr gpr text_settings = (int32_t)0x801282C0;
    constexpr uint32_t text_alpha = 0x3;
    constexpr uint32_t text_font = 0x6;
    constexpr uint32_t text_colour = 0x9;
    constexpr uint32_t text_size = 0x14;

    // The pause menu's font, as the page titles use it (capitals only).
    constexpr int menu_font = 1;

    // Strings are built in a small block of extended RDRAM no one else uses: the audio memory of
    // src/gameplay/mix_rate.cpp ends below 0x80EF0000 and the model tagging lists start at 0x80F00000.
    constexpr gpr string_area = (int32_t)0x80EF0000;
    constexpr uint32_t string_area_size = 0x1000;

    // The Totals level pages by SubPage (gcnewpause's D_808020A8 table), as the game's level ids.
    int32_t level_for_sub_page(uint8_t sub_page) {
        switch (sub_page) {
        case 3: return 0x13;   // Spiral Mountain
        case 4: return 0x1A;   // Isle o' Hags
        case 5: return 0x10;   // Mayahem Temple
        case 6: return 0x0F;   // Glitter Gulch Mine
        case 7: return 0x12;   // Witchyworld
        case 8: return 0x14;   // Jolly Roger's Lagoon
        case 9: return 0x15;   // Terrydactyland
        case 0xA: return 0x16; // Grunty Industries
        case 0xB: return 0x17; // Hailfire Peaks
        case 0xC: return 0x18; // Cloud Cuckooland
        case 0xD: return 0x19; // Cauldron Keep
        default: return -1;
        }
    }

    // Every level with a Totals page.
    constexpr int32_t all_levels[] = { 0x13, 0x1A, 0x10, 0x0F, 0x12, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19 };

    // The rows a level page counts, top to bottom (gcnewpause's D_80802130 table), with the item types
    // func_800D0018(type, level) / func_800CFC8C(type, level) count (collected / in the level).
    struct Row {
        int32_t type;
        const char* name;
    };
    constexpr Row rows[] = {
        { 1, "JIGGIES" },
        { 2, "HONEYCOMBS" },
        { 4, "PAGES" },
        { 3, "GLOWBOS" },
        { 6, "NOTES" },
        { 0, "JINJOS" },
    };

    // Jamjars' moves by level (gcnewpause's D_8080215C table): level id, ability id. func_800C6E38
    // says whether an ability is learned.
    constexpr uint8_t level_moves[][2] = {
        { 0x10, 0x14 }, { 0x10, 0x15 }, { 0x10, 0x16 }, { 0x0F, 0x19 }, { 0x0F, 0x1A },
        { 0x12, 0x1B }, { 0x12, 0x1C }, { 0x12, 0x29 }, { 0x14, 0x1E }, { 0x14, 0x1F },
        { 0x14, 0x1D }, { 0x15, 0x26 }, { 0x15, 0x27 }, { 0x15, 0x28 }, { 0x16, 0x25 },
        { 0x16, 0x23 }, { 0x16, 0x24 }, { 0x17, 0x21 }, { 0x17, 0x22 }, { 0x18, 0x2A },
        { 0x1A, 0x2C }, { 0x1A, 0x2D }, { 0x1A, 0x2E }, { 0x1A, 0x2F },
    };

    // Text colours (func_800B8CE0 takes 0xC24 + n): 0 white, 2 yellow, 4 the page title's blue, 6 green.
    constexpr int colour_white = 0xC24;
    constexpr int colour_yellow = 0xC26;
    constexpr int colour_blue = 0xC28;

    bool enabled(Clock::time_point now) {
        static bool cached = true;
        static Clock::time_point cached_at{};
        if (cached_at == Clock::time_point{} || now - cached_at > 250ms) {
            cached_at = now;
            try {
                cached = std::get<bool>(recompui::config::get_config(tooie::qol_tab_id).get_option_value(tooie::totals_checklist::option));
            } catch (...) {
                cached = true;
            }
        }
        return cached;
    }

    // Calls a game function with up to four integer arguments on a copy of the hook's registers.
    uint32_t call(uint8_t* rdram, recomp_context* ctx, void (*func)(uint8_t*, recomp_context*),
                  uint32_t a0 = 0, uint32_t a1 = 0, uint32_t a2 = 0, uint32_t a3 = 0) {
        recomp_context saved = *ctx;
        ctx->r4 = (gpr)(int32_t)a0;
        ctx->r5 = (gpr)(int32_t)a1;
        ctx->r6 = (gpr)(int32_t)a2;
        ctx->r7 = (gpr)(int32_t)a3;
        func(rdram, ctx);
        uint32_t result = (uint32_t)ctx->r2;
        *ctx = saved;
        return result;
    }

    // Writes a string into the string area at offset (bytes) and returns its address, 0 when full.
    uint32_t put_string(uint8_t* rdram, uint32_t& offset, const std::string& text) {
        const uint32_t start = offset;
        const size_t length = std::min<size_t>(text.size(), 63);
        if (start + length + 1 > string_area_size) {
            return 0;
        }
        for (size_t i = 0; i < length; i++) {
            MEM_B(start + i, string_area) = (int8_t)text[i];
        }
        MEM_B(start + length, string_area) = 0;
        offset = (start + (uint32_t)length + 4) & ~3u;
        return (uint32_t)string_area + start;
    }

    // Prints a string with a dark copy one pixel down and right behind it, so it reads over the
    // world behind the pause menu. The copy turns the tint (the RGB bytes func_800B8CBC sets, white
    // after func_800B8C50) to black.
    // right_align: x is where the text ends (func_800B8CFC measures a string in the current font
    // and size).
    void print(uint8_t* rdram, recomp_context* ctx, uint32_t gfx, uint32_t& offset,
               int colour, float size, int x, int y, const std::string& text, bool right_align = false) {
        const uint32_t addr = put_string(rdram, offset, text);
        if (addr == 0) {
            return;
        }
        uint32_t size_bits;
        std::memcpy(&size_bits, &size, sizeof(size_bits));
        for (int pass = 0; pass < 2; pass++) {
            const bool shadow = pass == 0;
            call(rdram, ctx, func_800B8C50);
            MEM_B(text_font, text_settings) = (int8_t)menu_font;
            MEM_B(text_colour, text_settings) = (int8_t)(colour - 0xC24);
            MEM_W(text_size, text_settings) = (int32_t)size_bits;
            if (right_align && pass == 0) {
                x -= (int32_t)call(rdram, ctx, func_800B8CFC, addr);
            }
            if (shadow) {
                MEM_B(0, text_settings) = 0;
                MEM_B(1, text_settings) = 0;
                MEM_B(2, text_settings) = 0;
                MEM_B(text_alpha, text_settings) = (int8_t)0xA0;
            }
            call(rdram, ctx, func_800B7F14, gfx);
            call(rdram, ctx, func_800B8E28, gfx, (uint32_t)(x + (shadow ? 1 : 0)), (uint32_t)(y + (shadow ? 1 : 0)), addr);
            call(rdram, ctx, func_800B811C, gfx);
        }
    }

    struct Count {
        uint32_t got = 0;
        uint32_t total = 0;
    };

    Count count_items(uint8_t* rdram, recomp_context* ctx, int32_t type, int32_t level) {
        Count c;
        c.got = call(rdram, ctx, func_800D0018, (uint32_t)type, (uint32_t)level);
        c.total = call(rdram, ctx, func_800CFC8C, (uint32_t)type, (uint32_t)level);
        return c;
    }

    // level -1 counts the moves of every level.
    Count count_moves(uint8_t* rdram, recomp_context* ctx, int32_t level) {
        Count c;
        for (const auto& move : level_moves) {
            if (level >= 0 && move[0] != level) {
                continue;
            }
            c.total++;
            if (call(rdram, ctx, func_800C6E38, move[1]) != 0) {
                c.got++;
            }
        }
        return c;
    }

    // Layout, in the game's 320x240 screen space: a narrow table between the counters on the left
    // and those on the right (notes and Jinjos), under the page title. Names start at block_x, the
    // number of items left ends at left_x.
    constexpr int block_x = 96;
    constexpr int left_x = 186;
    constexpr int block_y = 72;
    constexpr int line_height = 12;
    constexpr float text_scale = 0.4f;

    void print_row(uint8_t* rdram, recomp_context* ctx, uint32_t gfx, uint32_t& offset, int line,
                   const char* name, Count c) {
        const int y = block_y + line_height * line;
        print(rdram, ctx, gfx, offset, colour_white, text_scale, block_x, y, name);
        if (c.got >= c.total) {
            print(rdram, ctx, gfx, offset, colour_yellow, text_scale, left_x, y, "DONE", true);
        } else {
            print(rdram, ctx, gfx, offset, colour_white, text_scale, left_x, y, std::to_string(c.total - c.got), true);
        }
    }

    int last_page = -1;
    int last_sub_page = -1;
}

extern "C" void tooie_totals_checklist_draw(uint8_t* rdram, recomp_context* ctx) {
    const gpr pause = ctx->r16;
    const uint8_t page = MEM_BU(pause_page, pause);
    const uint8_t sub_page = MEM_BU(pause_sub_page, pause);
    const uint32_t gfx = MEM_W(0x20, ctx->r29);

    if (page != last_page || sub_page != last_sub_page) {
        last_page = page;
        last_sub_page = sub_page;
        if (std::getenv("TOOIE_TOTALS_LOG") != nullptr) {
            fprintf(stderr, "[totals] page %u sub page %u\n", page, sub_page);
            const int32_t level = level_for_sub_page(sub_page);
            if (page == page_totals && level >= 0) {
                for (const Row& row : rows) {
                    const Count c = count_items(rdram, ctx, row.type, level);
                    fprintf(stderr, "[totals] level 0x%X %s: %u of %u\n", level, row.name, c.got, c.total);
                }
                const Count m = count_moves(rdram, ctx, level);
                fprintf(stderr, "[totals] level 0x%X MOVES: %u of %u\n", level, m.got, m.total);
            }
        }
    }

    if (page != page_totals || !enabled(Clock::now())) {
        return;
    }
    if (MEM_BU(pause_draw_header, pause) == 0) {
        return;
    }

    // SubPage 2 is the game totals; 3..0xD the levels. 0 and 1 (moves and Jinjo families) are left alone.
    const int32_t level = level_for_sub_page(sub_page);
    if (sub_page != 2 && level < 0) {
        return;
    }

    uint32_t offset = 0;
    print(rdram, ctx, gfx, offset, colour_blue, text_scale, block_x, block_y - line_height,
          level < 0 ? "LEFT IN THE GAME" : "LEFT HERE");
    int line = 0;
    for (const Row& row : rows) {
        Count c;
        if (level < 0) {
            for (int32_t l : all_levels) {
                const Count lc = count_items(rdram, ctx, row.type, l);
                c.got += std::min(lc.got, lc.total);
                c.total += lc.total;
            }
        } else {
            c = count_items(rdram, ctx, row.type, level);
        }
        if (c.total != 0) {
            print_row(rdram, ctx, gfx, offset, line++, row.name, c);
        }
    }
    const Count moves = count_moves(rdram, ctx, level);
    if (moves.total != 0) {
        print_row(rdram, ctx, gfx, offset, line++, "MOVES", moves);
    }
}
