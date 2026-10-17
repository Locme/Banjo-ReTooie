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
#include <unordered_map>
#include <variant>
#include <vector>

#include "recomp.h"
#include "funcs.h"
#include "recompui/config.h"

#include "tooie_achievements.h"
#include "tooie_game.h"
#include "tooie_hooks.h"
#include "tooie_totals_checklist.h"

namespace {
    using namespace std::chrono_literals;
    using Clock = std::chrono::steady_clock;

    // PauseState (decomp include/gc/newpause.h).
    constexpr uint32_t pause_page = 0x0;
    constexpr uint32_t pause_sub_page = 0x1;
    constexpr uint32_t pause_title_step = 0x1A;     // MovePageHeaderTrigger: 0..10 as the title comes in
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
    // category: the checklist's own kind (totals_rules.inc, Category), for the NOW column.
    struct Row {
        int32_t type;
        int category;
        const char* name;
    };
    constexpr Row rows[] = {
        { 1, 0, "JIGGIES" },
        { 2, 1, "HONEYCOMBS" },
        { 4, 2, "PAGES" },
        { 3, 3, "GLOWBOS" },
        { 6, 4, "NOTES" },
        { 0, 5, "JINJOS" },
    };
    constexpr int category_moves = 6;

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
        static bool cached = false;
        static Clock::time_point cached_at{};
        if (cached_at == Clock::time_point{} || now - cached_at > 250ms) {
            cached_at = now;
            try {
                cached = std::get<bool>(recompui::config::get_config(tooie::qol_tab_id).get_option_value(tooie::totals_checklist::option));
            } catch (...) {
                cached = false;
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
        if (start + length + 1 > string_area_size - 8) {   // the last 8 bytes hold sprite coordinates
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
    // How far the page title has come in (0..1, gcnewpause's MovePageHeaderTrigger / 10): the extra
    // lines fade and rise in with it, and go out with it when the page turns or Totals closes.
    float page_in = 1.0f;
    int rise = 0;

    void print(uint8_t* rdram, recomp_context* ctx, uint32_t gfx, uint32_t& offset,
               int colour, float size, int x, int y, const std::string& text, bool right_align = false,
               bool dim = false) {
        y += rise;
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
            // Rows not picked are faded back, as the pause menu does with the options not picked.
            const float alpha = (shadow ? 160.0f : 255.0f) * page_in * (dim ? 0.55f : 1.0f);
            MEM_B(text_alpha, text_settings) = (int8_t)(uint8_t)alpha;
            if (shadow) {
                MEM_B(0, text_settings) = 0;
                MEM_B(1, text_settings) = 0;
                MEM_B(2, text_settings) = 0;
            }
            call(rdram, ctx, func_800B7F14, gfx);
            call(rdram, ctx, func_800B8E28, gfx, (uint32_t)(x + (shadow ? 1 : 0)), (uint32_t)(y + (shadow ? 1 : 0)), addr);
            call(rdram, ctx, func_800B811C, gfx);
        }
    }

    // The pause menu's own button art (the same set as its B button, asset 0xB59): 0xB58 is the blue
    // A button, four frames of it turning. Drawn at half size beside the picked row, it says "press A
    // here" the way the B button at the bottom says "press B to go back".
    constexpr uint32_t sprite_a_button = 0xB58;

    void draw_a_button(uint8_t* rdram, recomp_context* ctx, uint32_t gfx, int x, int y, int64_t ms) {
        if (page_in < 1.0f) {
            return;
        }
        const uint32_t image = call(rdram, ctx, func_800D674C, sprite_a_button);
        if (image == 0) {
            return;
        }
        const gpr image_addr = (gpr)(int32_t)image;
        const gpr coords = string_area + (string_area_size - 8);   // Coords2D, in quarter pixels
        MEM_W(0, coords) = x * 4;
        MEM_W(4, coords) = (y + rise) * 4;
        call(rdram, ctx, func_800E2568, (uint32_t)(MEM_H(8, image_addr) * 2), (uint32_t)(MEM_H(0xA, image_addr) * 2));
        const uint32_t frames = std::max<uint32_t>(1, (uint16_t)MEM_H(0, image_addr));
        call(rdram, ctx, func_800E30E0, gfx, image, (uint32_t)((ms / 150) % frames), (uint32_t)coords);
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
    // number left ends at left_x and the number that can be got now at now_x.
    constexpr int block_x = 92;
    constexpr int left_x = 172;
    constexpr int now_x = 204;
    constexpr int block_y = 72;
    constexpr int line_height = 12;
    constexpr float text_scale = 0.4f;
    constexpr int colour_green = 0xC2A;

    void print_row(uint8_t* rdram, recomp_context* ctx, uint32_t gfx, uint32_t& offset, int line,
                   const char* name, Count c, uint32_t now) {
        const int y = block_y + line_height * line;
        print(rdram, ctx, gfx, offset, colour_white, text_scale, block_x, y, name);
        if (c.got >= c.total) {
            print(rdram, ctx, gfx, offset, colour_yellow, text_scale, now_x, y, "DONE", true);
            return;
        }
        const uint32_t left = c.total - c.got;
        print(rdram, ctx, gfx, offset, colour_white, text_scale, left_x, y, std::to_string(left), true);
        if (now > 0) {
            print(rdram, ctx, gfx, offset, colour_green, text_scale, now_x, y, std::to_string(std::min(now, left)), true);
        } else {
            print(rdram, ctx, gfx, offset, colour_white, text_scale, now_x, y, "-", true);
        }
    }

    int last_page = -1;
    int last_sub_page = -1;
    bool last_achievements_open = false;
}

// What can be got now: the rules of the Archipelago randomizer's Banjo-Tooie world, translated by
// tools/gen_totals_rules.py into totals_rules.inc, evaluated against this save's flags.
namespace totals_rules {
    constexpr int max_items = 160;
    constexpr int max_regions = 96;

    struct State {
        int counts[max_items] = {};
        bool reached[max_regions] = {};
        bool world_open[9] = {};
        uint32_t notes = 0;

        bool has(int item, int n = 1) const { return counts[item] >= n; }
        int count(int item) const { return counts[item]; }
        bool reach(int region) const { return reached[region]; }
    };

    // Hand-written in place of the randomizer methods that read its own world data.
    static bool o_mt_jiggy(const State& s) { return s.world_open[0]; }
    static bool o_gm_jiggy(const State& s) { return s.world_open[1]; }
    static bool o_ww_jiggy(const State& s) { return s.world_open[2]; }
    static bool o_jrl_jiggy(const State& s) { return s.world_open[3]; }
    static bool o_tdl_jiggy(const State& s) { return s.world_open[4]; }
    static bool o_gi_jiggy(const State& s) { return s.world_open[5]; }
    static bool o_hfp_jiggy(const State& s) { return s.world_open[6]; }
    static bool o_ccl_jiggy(const State& s) { return s.world_open[7]; }
    static bool o_ck_jiggy(const State& s) { return s.world_open[8]; }
    // Banjo-Kazooie's moves are all known from the start.
    static bool o_has_BK_move(const State&, int) { return true; }
    static bool o_check_notes(const State& s, int location);
    static bool o_check_solo_moves(const State& s, int item);

#include "totals_rules.inc"

    static_assert(I_COUNT <= max_items && R_COUNT <= max_regions, "raise max_items / max_regions");

    // Jamjars teaches a move once the notes collected reach its price.
    static bool o_check_notes(const State& s, int location) {
        const int cost = silo_cost[location];
        return cost >= 0 && s.notes >= (uint32_t)cost;
    }

    static bool o_check_solo_moves(const State& s, int item) { return s.has(item) && r_split_up(s); }

    static bool reach_location(const State& s, int location) {
        const int index = location_index[location];
        if (index < 0) {
            return false;
        }
        const Location& l = locations[index];
        return s.reach(l.region) && (l.rule == nullptr || l.rule(s));
    }
}

namespace {
    // The game's flag getter (func_800DA298) on a copy of the hook's registers.
    bool flag(uint8_t* rdram, recomp_context* ctx, int32_t f) {
        return call(rdram, ctx, func_800DA298, (uint32_t)f) != 0;
    }

    using totals_rules::State;

    // Warp pads (Archipelago item order MT1..5, GM1..5, WW1..5, JR1..5, TL1..5, GI1..5, HP1..5, CC1..2,
    // CK1..2) as N64 flags: touching a pad sets its flag (decomp include/gameflags.h).
    struct ItemFlag {
        int item;
        int32_t flag;
    };

    // Per-world Humba (Wumba) and Mumbo: the flag set when their Glowbo is paid. A Glowbo that is
    // collected but not yet paid counts too: it can be taken to them now.
    struct MagicFlag {
        int humba_item;
        int mumbo_item;
        int32_t humba_paid;
        int32_t mumbo_paid;
    };

    // The areas that can be reached: from those already reached, through every entrance that is open,
    // until nothing changes.
    void spread(State& s) {
        using namespace totals_rules;
        for (bool changed = true; changed;) {
            changed = false;
            for (const Entrance& e : entrances) {
                if (s.reached[e.from] && !s.reached[e.to] && (e.open == nullptr || e.open(s))) {
                    s.reached[e.to] = true;
                    changed = true;
                }
            }
        }
    }

    bool gettable(const State& s, size_t location) {
        const totals_rules::Location& l = totals_rules::locations[location];
        return s.reach(l.region) && (l.rule == nullptr || l.rule(s));
    }

    void fill_state(uint8_t* rdram, recomp_context* ctx, State& s, bool* collected) {
        using namespace totals_rules;
        for (int i = 0; i < I_COUNT; i++) {
            const int f = item_location_flag[i];
            if (f >= 0 && flag(rdram, ctx, f)) {
                s.counts[i] = 1;
            }
        }
        static const ItemFlag pads[] = {
            { I_WARPMT1, 0x3AC }, { I_WARPMT2, 0x3AD }, { I_WARPMT3, 0x3AE }, { I_WARPMT4, 0x3AF }, { I_WARPMT5, 0x3B0 },
            { I_WARPGM1, 0x3B1 }, { I_WARPGM2, 0x3B2 }, { I_WARPGM3, 0x3B3 }, { I_WARPGM4, 0x3B4 }, { I_WARPGM5, 0x3B5 },
            { I_WARPWW1, 0x3B6 }, { I_WARPWW2, 0x3B7 }, { I_WARPWW3, 0x3B8 }, { I_WARPWW4, 0x3B9 }, { I_WARPWW5, 0x3BA },
            { I_WARPJR1, 0x3BB }, { I_WARPJR2, 0x3BC }, { I_WARPJR3, 0x3BD }, { I_WARPJR4, 0x3BE }, { I_WARPJR5, 0x3BF },
            { I_WARPTL1, 0x3C0 }, { I_WARPTL2, 0x3C1 }, { I_WARPTL3, 0x3C2 }, { I_WARPTL4, 0x3C3 }, { I_WARPTL5, 0x3C4 },
            { I_WARPGI1, 0x3C5 }, { I_WARPGI2, 0x3C6 }, { I_WARPGI3, 0x3C7 }, { I_WARPGI4, 0x3C8 }, { I_WARPGI5, 0x3C9 },
            { I_WARPHP1, 0x3CA }, { I_WARPHP2, 0x3CB }, { I_WARPHP3, 0x3CC }, { I_WARPHP4, 0x3CD }, { I_WARPHP5, 0x3CE },
            { I_WARPCC1, 0x3CF }, { I_WARPCC2, 0x3D0 }, { I_WARPCK1, 0x3D4 }, { I_WARPCK2, 0x3D5 },
            // Jamjars' silos on the Isle o' Hags open when first visited.
            { I_SILOIOHJV, 0x32D }, { I_SILOIOHWH, 0x32E }, { I_SILOIOHPL, 0x32F }, { I_SILOIOHPG, 0x330 },
            { I_SILOIOHCT, 0x331 }, { I_SILOIOHWL, 0x332 }, { I_SILOIOHQM, 0x333 },
        };
        for (const ItemFlag& p : pads) {
            s.counts[p.item] = flag(rdram, ctx, p.flag) ? 1 : 0;
        }

        // Collectibles: which are collected, and the totals some rules ask for.
        for (size_t i = 0; i < sizeof(locations) / sizeof(locations[0]); i++) {
            collected[i] = flag(rdram, ctx, locations[i].flag);
        }
        int jiggies = 0;
        int glowbos = 0;
        for (size_t i = 0; i < sizeof(locations) / sizeof(locations[0]); i++) {
            if (!collected[i]) {
                continue;
            }
            if (locations[i].category == C_JIGGY) {
                jiggies++;
            } else if (locations[i].category == C_GLOWBO) {
                glowbos++;
            }
        }
        s.counts[I_JIGGY] = jiggies;
        int doubloons = 0;
        for (int32_t f = 0x13F; f <= 0x15C; f++) {
            doubloons += flag(rdram, ctx, f) ? 1 : 0;
        }
        s.counts[I_DOUBLOON] = doubloons;
        s.notes = call(rdram, ctx, func_800D035C, 6);

        // Jinjo families: func_800D1338(family) is how many of a family are collected (white, orange,
        // yellow, brown, green, red, blue, purple, black, as the Totals Jinjo page lists them).
        const int families[] = { I_WJINJO, I_OJINJO, I_YJINJO, I_BRJINJO, I_GJINJO, I_RJINJO, I_BLJINJO, I_PJINJO, I_BKJINJO };
        for (int i = 0; i < 9; i++) {
            s.counts[families[i]] = (int)call(rdram, ctx, func_800D1338, (uint32_t)i);
        }

        static const MagicFlag magic[] = {
            { I_HUMBAMT, I_MUMBOMT, 0x0D6, 0x37F }, { I_HUMBAGM, I_MUMBOGM, 0x0D7, 0x380 },
            { I_HUMBAWW, I_MUMBOWW, 0x0D8, 0x381 }, { I_HUMBAJR, I_MUMBOJR, 0x0D9, 0x382 },
            { I_HUMBATD, I_MUMBOTD, 0x0DA, 0x383 }, { I_HUMBAGI, I_MUMBOGI, 0x0DB, 0x387 },
            { I_HUMBAHP, I_MUMBOHP, 0x0DC, 0x384 }, { I_HUMBACC, I_MUMBOCC, 0x0DD, 0x385 },
            { I_HUMBAIH, I_MUMBOIH, 0x0DE, 0x386 },
        };
        int paid = 0;
        for (const MagicFlag& m : magic) {
            paid += flag(rdram, ctx, m.humba_paid) ? 1 : 0;
            paid += flag(rdram, ctx, m.mumbo_paid) ? 1 : 0;
        }
        const bool spare_glowbo = glowbos > paid;
        for (const MagicFlag& m : magic) {
            s.counts[m.humba_item] = (flag(rdram, ctx, m.humba_paid) || spare_glowbo) ? 1 : 0;
            s.counts[m.mumbo_item] = (flag(rdram, ctx, m.mumbo_paid) || spare_glowbo) ? 1 : 0;
        }

        for (int i = 0; i < 9; i++) {
            s.world_open[i] = flag(rdram, ctx, 0x392 + i);
        }

        s.reached[R_MENU] = true;
        spread(s);
    }

    // Per level and category: how many are left, and how many of those can be got now. Notes count in
    // notes (5 a nest, 20 a Treble Clef).
    struct Checklist {
        uint32_t now[16][7] = {};       // by level - 0x0F, category
        bool valid = false;
        bool world_can_open = false;    // Jiggywiggy would open the next world
        bool level_shown[16] = {};      // by level - 0x0F: the level has a Totals page (visited)
    };
    Checklist checklist;

    // The save as last evaluated, for the item lists and their hints.
    State base_state;
    bool collected[sizeof(totals_rules::locations) / sizeof(totals_rules::locations[0])];
    constexpr size_t location_count = sizeof(totals_rules::locations) / sizeof(totals_rules::locations[0]);

    // Jiggies Jiggywiggy asks for each world, in order (MT .. CK).
    constexpr int world_cost[9] = { 1, 4, 8, 14, 20, 28, 36, 45, 55 };

    void evaluate(uint8_t* rdram, recomp_context* ctx) {
        using namespace totals_rules;
        State& s = base_state;
        s = State{};
        fill_state(rdram, ctx, s, collected);
        checklist = Checklist{};
        const bool log = std::getenv("TOOIE_TOTALS_LOG") != nullptr;
        for (size_t i = 0; i < sizeof(locations) / sizeof(locations[0]); i++) {
            const Location& l = locations[i];
            if (collected[i] || !gettable(s, i)) {
                continue;
            }
            const int level = l.level - 0x0F;
            if (level >= 0 && level < 16) {
                checklist.now[level][l.category] += (uint32_t)l.amount;
            }
            if (log) {
                fprintf(stderr, "[totals] now: %s\n", l.name);
            }
        }
        // The pause menu shows a level's page once it is visited (decomp include/gameflags.h,
        // FLAG_1E3_PROGRESS_VIEW_TOTALS_MENU_MT ..); Spiral Mountain always.
        static const int32_t shown_flags[][2] = {
            { 0x10, 0x1E3 }, { 0x0F, 0x1E4 }, { 0x12, 0x1E5 }, { 0x14, 0x1E6 }, { 0x15, 0x1E7 },
            { 0x16, 0x1E8 }, { 0x17, 0x1E9 }, { 0x18, 0x1EA }, { 0x19, 0x1EB }, { 0x1A, 0x1EC },
        };
        checklist.level_shown[0x13 - 0x0F] = true;
        for (const auto& f : shown_flags) {
            checklist.level_shown[f[0] - 0x0F] = flag(rdram, ctx, f[1]);
        }
        for (int w = 0; w < 9; w++) {
            if (!s.world_open[w]) {
                checklist.world_can_open = s.count(I_JIGGY) >= world_cost[w];
                break;
            }
        }
        if (log) {
            int reached = 0;
            for (int r = 0; r < R_COUNT; r++) {
                reached += s.reached[r] ? 1 : 0;
            }
            fprintf(stderr, "[totals] %d of %d areas reachable, %d jiggies, %u notes, next world %s\n", reached,
                    (int)R_COUNT, s.count(I_JIGGY), s.notes, checklist.world_can_open ? "can open" : "not yet");
        }
        checklist.valid = true;
    }

    uint32_t now_for(int32_t level, int category) {
        uint32_t n = 0;
        for (int l = 0; l < 16; l++) {
            if (level < 0 || l == level - 0x0F) {
                n += checklist.now[l][category];
            }
        }
        return n;
    }

    // ---- Item lists: A on a row of the table lists that row's collectibles as GET NOW, LATER or DONE,
    // with what a LATER one still needs when it is picked.

    enum Status : uint8_t { status_now, status_later, status_done };

    struct Entry {
        std::string name;               // as the pause font can print it
        Status status = status_done;
        int left = 0;                   // notes left in a group of notes
        std::vector<uint16_t> locations;
        std::string fitted[2];          // name cut to fit: [0] first row (beside the notes counter), [1] others
        bool hint_done = false;
        std::string hint;               // what a LATER entry needs, worked out when it is picked
    };

    // Shared with the pad filter (apply_input), which runs before the game reads the pad.
    enum Mode : int { mode_none, mode_table, mode_list };
    std::atomic<int> input_mode{ mode_none };
    std::atomic<int64_t> drawn_at_ms{ 0 };
    std::atomic<int> moves_down{ 0 };   // cursor steps, down positive
    std::atomic<int> presses_a{ 0 };
    std::atomic<int> presses_b{ 0 };

    int64_t now_ms() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now().time_since_epoch()).count();
    }

    struct ListView {
        bool open = false;
        int32_t level = -1;
        int category = 0;
        std::string title;
        std::vector<Entry> entries;
        int cursor = 0;
        int top = 0;
    };
    ListView list;
    int table_cursor = 0;

    // Only what the pause font has: capitals, digits, spaces and '-'.
    std::string printable(const std::string& text) {
        std::string out;
        for (char c : text) {
            if (c >= 'a' && c <= 'z') {
                out += (char)(c - 'a' + 'A');
            } else if ((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '-') {
                out += c;
            } else if (c == ' ' && !out.empty() && out.back() != ' ') {
                out += c;
            }
        }
        while (!out.empty() && out.back() == ' ') {
            out.pop_back();
        }
        return out;
    }

    bool ends_with(const std::string& text, const char* suffix) {
        const size_t n = std::strlen(suffix);
        return text.size() >= n && text.compare(text.size() - n, n, suffix) == 0;
    }

    // "MT: Jade Snake Grove Jinjo" -> "Jade Snake Grove" on a level's own list (the world and the kind
    // are known), "MT Jade Snake Grove" on the whole game's. GI keeps its floor. Notes lose their number,
    // so a group of notes shares one name.
    std::string short_name(const char* full, bool keep_world) {
        std::string name = full;
        const size_t colon = name.find(": ");
        if (colon != std::string::npos) {
            std::string world = name.substr(0, colon);
            std::string rest = name.substr(colon + 2);
            std::string floor;
            if (world.rfind("GI ", 0) == 0) {
                floor = world.substr(3) + " ";
                world = "GI";
            }
            name = (keep_world ? world + " " : std::string()) + floor + rest;
        }
        // Notes: "First Stairs Note 3" -> "First Stairs Notes".
        const size_t note = name.rfind(" Note");
        if (note != std::string::npos && (note + 5 == name.size() || name[note + 5] == ' ')) {
            name = name.substr(0, note) + " Notes";
        }
        for (const char* suffix : { " Jinjo", " Silo", " Jiggy", " Honeycomb", " Cheato Page", " Page", " Glowbo" }) {
            if (ends_with(name, suffix) && name.size() > std::strlen(suffix) + 3) {
                name.resize(name.size() - std::strlen(suffix));
                break;
            }
        }
        return printable(name);
    }

    const char* category_title(int category) {
        switch (category) {
        case 0: return "JIGGIES";
        case 1: return "HONEYCOMBS";
        case 2: return "PAGES";
        case 3: return "GLOWBOS";
        case 4: return "NOTES";
        case 5: return "JINJOS";
        default: return "MOVES";
        }
    }

    void open_list(int32_t level, int category) {
        using namespace totals_rules;
        list = ListView{};
        list.open = true;
        list.level = level;
        list.category = category;
        list.title = category_title(category);
        for (size_t i = 0; i < location_count; i++) {
            const Location& l = locations[i];
            if (l.category != category || (level >= 0 && l.level != level)) {
                continue;
            }
            // The whole game's list names only what is in levels already visited, so it gives
            // nothing away about places not yet seen.
            if (level < 0 && (l.level < 0x0F || l.level - 0x0F >= 16 || !checklist.level_shown[l.level - 0x0F])) {
                continue;
            }
            const std::string name = short_name(l.name, level < 0);
            Entry* e = nullptr;
            if (category == C_NOTES) {
                for (Entry& other : list.entries) {
                    if (other.name == name) {
                        e = &other;
                        break;
                    }
                }
            }
            if (e == nullptr) {
                list.entries.push_back(Entry{});
                e = &list.entries.back();
                e->name = name;
            }
            e->locations.push_back((uint16_t)i);
        }
        for (Entry& e : list.entries) {
            if (e.locations.size() == 1 && ends_with(e.name, " NOTES")) {
                e.name.pop_back();  // one note on its own
            }
            bool any_left = false;
            bool any_now = false;
            for (uint16_t i : e.locations) {
                if (!collected[i]) {
                    any_left = true;
                    e.left += locations[i].amount;
                    any_now = any_now || gettable(base_state, i);
                }
            }
            e.status = !any_left ? status_done : any_now ? status_now : status_later;
        }
        // GET NOW first, then LATER, then DONE, each in the game's order.
        std::stable_sort(list.entries.begin(), list.entries.end(),
                         [](const Entry& a, const Entry& b) { return a.status < b.status; });
    }

    // What a LATER entry still needs: the one thing that, given on top of this save, makes it gettable.
    std::string work_out_hint(const Entry& e) {
        using namespace totals_rules;
        auto works = [&](const State& t) {
            for (uint16_t i : e.locations) {
                if (!collected[i] && gettable(t, i)) {
                    return true;
                }
            }
            return false;
        };
        std::vector<std::string> found;
        auto add = [&](const std::string& text) {
            if (std::find(found.begin(), found.end(), text) == found.end()) {
                found.push_back(text);
            }
        };

        // Notes for Jamjars.
        {
            State t = base_state;
            t.notes = 100000;
            spread(t);
            if (works(t)) {
                int cost = -1;
                for (uint16_t i : e.locations) {
                    for (int l = 0; l < (int)(sizeof(location_index) / sizeof(location_index[0])); l++) {
                        if (location_index[l] == (int)i && silo_cost[l] > cost) {
                            cost = silo_cost[l];
                        }
                    }
                }
                if (cost > (int)base_state.notes) {
                    add(std::to_string(cost - (int)base_state.notes) + " MORE NOTES");
                } else {
                    add("MORE NOTES");
                }
            }
        }
        // A world opened by Jiggywiggy.
        static const char* const worlds[9] = { "MAYAHEM TEMPLE", "GLITTER GULCH MINE", "WITCHYWORLD", "JOLLY ROGERS LAGOON",
                                               "TERRYDACTYLAND", "GRUNTY INDUSTRIES", "HAILFIRE PEAKS", "CLOUD CUCKOOLAND",
                                               "CAULDRON KEEP" };
        for (int w = 0; w < 9; w++) {
            if (base_state.world_open[w]) {
                continue;
            }
            State t = base_state;
            t.world_open[w] = true;
            spread(t);
            if (works(t)) {
                add(std::string(worlds[w]) + " OPEN");
            }
        }
        // One item: a move, a transformation, a spell, a station, a silo or a warp pad, or more of
        // something counted (Jiggies, a Jinjo family, doubloons).
        for (int item = 0; item < I_COUNT; item++) {
            switch (item) {
            case I_PAEGGAIM: case I_PASWIM: case I_PBASH: case I_PBBUST: case I_PEGGAIM: case I_PFLIGHT:
            case I_PSHOES: case I_PSWIM:
                continue;   // the randomizer's progressive items; the game has none
            default:
                break;
            }
            const bool counted = item == I_JIGGY || item == I_DOUBLOON || item == I_WJINJO || item == I_OJINJO ||
                                 item == I_YJINJO || item == I_BRJINJO || item == I_GJINJO || item == I_RJINJO ||
                                 item == I_BLJINJO || item == I_PJINJO || item == I_BKJINJO;
            if (!counted && base_state.counts[item] > 0) {
                continue;
            }
            State t = base_state;
            t.counts[item] = counted ? 1000 : 1;
            spread(t);
            if (!works(t)) {
                continue;
            }
            std::string name = item_display[item];
            if (item == I_JIGGY) {
                add("MORE JIGGIES");
            } else if (item == I_DOUBLOON) {
                add("MORE DOUBLOONS");
            } else if (counted) {
                add("ALL " + printable(name) + "S");
            } else if (name.rfind("Humba: ", 0) == 0) {
                add(printable(name.substr(7)) + " FORM");
            } else if (name.rfind("Mumbo: ", 0) == 0) {
                add("MUMBO " + printable(name.substr(7)));
            } else if (ends_with(name, " Train Station")) {
                add("TRAIN AT " + printable(name.substr(0, name.size() - 14)));
            } else if (ends_with(name, " Warp Pad")) {
                add("WARP PAD " + printable(name.substr(0, name.size() - 9)));
            } else {
                add(printable(name));
            }
        }
        if (found.empty()) {
            return "NEEDS MORE THAN ONE THING";
        }
        std::string hint = "NEEDS " + found[0];
        if (found.size() > 1) {
            hint += " OR " + found[1];
        }
        return hint;
    }

    // Sets up the text settings print() uses, so func_800B8CFC measures in the same font and size.
    uint32_t measure(uint8_t* rdram, recomp_context* ctx, uint32_t& offset, float size, const std::string& text) {
        uint32_t scratch = offset;
        const uint32_t addr = put_string(rdram, scratch, text);
        if (addr == 0) {
            return 0;
        }
        uint32_t size_bits;
        std::memcpy(&size_bits, &size, sizeof(size_bits));
        call(rdram, ctx, func_800B8C50);
        MEM_B(text_font, text_settings) = (int8_t)menu_font;
        MEM_W(text_size, text_settings) = (int32_t)size_bits;
        return call(rdram, ctx, func_800B8CFC, addr);
    }

    std::string fit(uint8_t* rdram, recomp_context* ctx, uint32_t& offset, float size, std::string text, int width) {
        if ((int)measure(rdram, ctx, offset, size, text) <= width) {
            return text;
        }
        // Whole words while they fit, else as many letters as fit.
        for (size_t space = text.rfind(' '); space != std::string::npos && space > 0; space = text.rfind(' ', space - 1)) {
            const std::string shorter = text.substr(0, space);
            if ((int)measure(rdram, ctx, offset, size, shorter) <= width) {
                return shorter;
            }
        }
        while (text.size() > 1 && (int)measure(rdram, ctx, offset, size, text) > width) {
            text.pop_back();
        }
        return text;
    }

    // Splits text into lines no wider than width.
    std::vector<std::string> wrap(uint8_t* rdram, recomp_context* ctx, uint32_t& offset, float size,
                                  const std::string& text, int width) {
        std::vector<std::string> lines;
        std::string line;
        size_t start = 0;
        while (start < text.size()) {
            size_t end = text.find(' ', start);
            if (end == std::string::npos) {
                end = text.size();
            }
            const std::string word = text.substr(start, end - start);
            const std::string longer = line.empty() ? word : line + " " + word;
            if (!line.empty() && (int)measure(rdram, ctx, offset, size, longer) > width) {
                lines.push_back(line);
                line = word;
            } else {
                line = longer;
            }
            start = end + 1;
        }
        if (!line.empty()) {
            lines.push_back(line);
        }
        return lines;
    }

    // List layout: up to list_rows names under the title; the picked one's status and hint below.
    // The first row sits beside the game's notes counter, so it is kept narrower.
    constexpr int list_rows = 8;
    // The A button beside the picked row of the table (its sprite is placed by its middle).
    constexpr int button_x = block_x - 13;
    constexpr int button_dy = -8;
    constexpr int narrow_width = 205 - block_x;
    constexpr int wide_width = 242 - block_x;

    void draw_list(uint8_t* rdram, recomp_context* ctx, uint32_t gfx, uint32_t& offset) {
        const int header_y = block_y - line_height;
        print(rdram, ctx, gfx, offset, colour_blue, text_scale, block_x, header_y, list.title);
        if (list.entries.empty()) {
            print(rdram, ctx, gfx, offset, colour_white, text_scale, block_x, block_y, "NONE HERE");
            return;
        }
        const int count = (int)list.entries.size();
        if (list.cursor < list.top) {
            list.top = list.cursor;
        } else if (list.cursor >= list.top + list_rows) {
            list.top = list.cursor - list_rows + 1;
        }
        for (int row = 0; row < list_rows && list.top + row < count; row++) {
            Entry& e = list.entries[list.top + row];
            const int which = row == 0 ? 0 : 1;
            if (e.fitted[which].empty()) {
                e.fitted[which] = fit(rdram, ctx, offset, text_scale, e.name, which == 0 ? narrow_width : wide_width);
            }
            const int colour = e.status == status_now ? colour_green : e.status == status_done ? colour_yellow : colour_white;
            const int y = block_y + line_height * row;
            const bool picked = list.top + row == list.cursor;
            print(rdram, ctx, gfx, offset, colour, text_scale, block_x, y, e.fitted[which], false, !picked);
        }

        // The picked entry.
        Entry& e = list.entries[list.cursor];
        int y = block_y + line_height * list_rows + 4;
        std::string status = e.status == status_now ? "GET NOW" : e.status == status_done ? "DONE" : "LATER";
        if (list.category == totals_rules::C_NOTES && e.status != status_done) {
            status += " - " + std::to_string(e.left) + " NOTES LEFT";
        }
        const int colour = e.status == status_now ? colour_green : e.status == status_done ? colour_yellow : colour_white;
        print(rdram, ctx, gfx, offset, colour, text_scale, block_x, y, status);
        if (e.status == status_later) {
            if (!e.hint_done) {
                e.hint = work_out_hint(e);
                e.hint_done = true;
                if (std::getenv("TOOIE_TOTALS_LOG") != nullptr) {
                    fprintf(stderr, "[totals] hint: %s: %s\n", e.name.c_str(), e.hint.c_str());
                }
            }
            for (const std::string& line : wrap(rdram, ctx, offset, text_scale, e.hint, wide_width)) {
                y += line_height;
                print(rdram, ctx, gfx, offset, colour_white, text_scale, block_x, y, line);
            }
        }
    }
}

namespace {
    // ---- The pause menu's Achievements page (pause_settings.cpp opens it as a Totals sub page): the
    // XBLA achievements as a list, unlocked ones in yellow, up/down picks one and its description and
    // state show under the list. Drawn whatever the Totals checklist option says.
    constexpr int ach_left = 64;
    constexpr int ach_right = 256;
    constexpr int ach_rows = 6;
    constexpr int ach_description_lines = 4;
    int ach_cursor = 0;
    int ach_top = 0;
    // Each row's icon sits before its name; the picked one is shown larger beside its description.
    constexpr int ach_icon_size = 11;
    constexpr int ach_icon_gap = 14;
    constexpr int ach_big_icon_size = 40;

    // Draws a talking-head portrait (an id in gczoomboxdata's table) as the game's dialogue boxes do:
    // gczoomboxdata_entrypoint_1 gives the portrait's sprite asset and func_800D674C loads it (gczoombox
    // func_80802B94). The game draws the sprite itself, cut out as in a dialogue box, so a texture pack
    // that replaces the portrait replaces the icon too. x, y are its middle; size its height in pixels.
    void draw_portrait(uint8_t* rdram, recomp_context* ctx, uint32_t gfx, int portrait, int x, int y, int size) {
        if (portrait < 0) {
            return;
        }
        // The table is fixed, so each portrait's asset is looked up once (the call may load the overlay).
        static std::unordered_map<int, uint32_t> assets;
        auto found = assets.find(portrait);
        if (found == assets.end()) {
            found = assets.emplace(portrait, call(rdram, ctx, _gczoomboxdata_entrypoint_1, (uint32_t)portrait) & 0xFFFF).first;
        }
        const uint32_t asset = found->second;
        if (asset == 0) {
            return;
        }
        const uint32_t image = call(rdram, ctx, func_800D674C, asset);
        if (image == 0) {
            return;
        }
        const gpr image_addr = (gpr)(int32_t)image;
        const int width = MEM_H(8, image_addr);
        const int height = MEM_H(0xA, image_addr);
        if (width <= 0 || height <= 0) {
            return;
        }
        if (std::getenv("TOOIE_ACH_ICON_LOG") != nullptr) {
            static int logged = 0;
            if (logged < 64) {
                logged++;
                fprintf(stderr, "[ach-icon] portrait 0x%X asset 0x%X %dx%d frames %u\n", portrait, asset,
                        width, height, (uint16_t)MEM_H(0, image_addr));
            }
        }
        const gpr coords = string_area + (string_area_size - 8);   // Coords2D, in quarter pixels
        MEM_W(0, coords) = x * 4;
        // Portraits come out 12 pixels lower than asked at any size (measured headless), so ask higher.
        MEM_W(4, coords) = (y - 12 + rise) * 4;
        // func_800E2568 sets the drawn size in quarter pixels.
        call(rdram, ctx, func_800E2568, (uint32_t)(width * size * 4 / height), (uint32_t)(size * 4));
        call(rdram, ctx, func_800E30E0, gfx, image, 0, (uint32_t)coords);
    }

    void draw_achievements(uint8_t* rdram, recomp_context* ctx, uint32_t gfx, uint32_t& offset, int steps) {
        const std::vector<tooie::achievements::PauseEntry> entries = tooie::achievements::pause_entries();
        if (entries.empty()) {
            return;
        }
        const int count = (int)entries.size();
        ach_cursor = std::clamp(ach_cursor + steps, 0, count - 1);
        if (ach_cursor < ach_top) {
            ach_top = ach_cursor;
        } else if (ach_cursor >= ach_top + ach_rows) {
            ach_top = ach_cursor - ach_rows + 1;
        }

        int unlocked = 0;
        int points = 0;
        int total = 0;
        for (const auto& e : entries) {
            total += e.points;
            if (e.unlocked) {
                unlocked++;
                points += e.points;
            }
        }
        const int header_y = block_y - line_height;
        print(rdram, ctx, gfx, offset, colour_blue, text_scale, ach_left, header_y,
              std::to_string(unlocked) + " OF " + std::to_string(count) + " UNLOCKED");
        print(rdram, ctx, gfx, offset, colour_blue, text_scale, ach_right, header_y,
              std::to_string(points) + " OF " + std::to_string(total) + "G", true);

        // The list; more above or below is shown by a "-" at the end of the first or last row.
        constexpr int points_width = 26;
        for (int row = 0; row < ach_rows && ach_top + row < count; row++) {
            const auto& e = entries[ach_top + row];
            const int y = block_y + line_height * row;
            const bool picked = ach_top + row == ach_cursor;
            const int colour = e.unlocked ? colour_yellow : colour_white;
            const int name_x = e.portrait >= 0 ? ach_left + ach_icon_gap : ach_left;
            const std::string name = fit(rdram, ctx, offset, text_scale, printable(e.name), ach_right - name_x - points_width);
            if (page_in >= 1.0f) {
                draw_portrait(rdram, ctx, gfx, e.portrait, ach_left + ach_icon_size / 2, y + ach_icon_size / 2, ach_icon_size);
            }
            print(rdram, ctx, gfx, offset, colour, text_scale, name_x, y, name, false, !picked);
            print(rdram, ctx, gfx, offset, colour, text_scale, ach_right, y, std::to_string(e.points) + "G", true, !picked);
        }
        if (ach_top > 0) {
            print(rdram, ctx, gfx, offset, colour_white, text_scale, ach_left - 10, block_y, "-");
        }
        if (ach_top + ach_rows < count) {
            print(rdram, ctx, gfx, offset, colour_white, text_scale, ach_left - 10, block_y + line_height * (ach_rows - 1), "-");
        }

        // The picked one: its state, then its description.
        const auto& e = entries[ach_cursor];
        int y = block_y + line_height * ach_rows + 4;
        std::string state;
        int colour = colour_white;
        if (e.unlocked) {
            state = "UNLOCKED";
            if (e.unlocked_at.size() >= 10) {
                state += " " + e.unlocked_at.substr(0, 10);
            }
            colour = colour_yellow;
        } else if (e.count >= 0) {
            state = "LOCKED - " + std::to_string(std::min(e.count, e.goal)) + " OF " + std::to_string(e.goal);
        } else {
            state = "LOCKED";
        }
        print(rdram, ctx, gfx, offset, colour, text_scale, ach_left, y, state);
        if (page_in >= 1.0f) {
            draw_portrait(rdram, ctx, gfx, e.portrait, ach_right + 4 + ach_big_icon_size / 2, y + ach_big_icon_size / 2, ach_big_icon_size);
        }
        const std::vector<std::string> lines = wrap(rdram, ctx, offset, text_scale, printable(e.description), ach_right - ach_left);
        for (int i = 0; i < (int)lines.size() && i < ach_description_lines; i++) {
            y += line_height;
            std::string line = lines[i];
            if (i == ach_description_lines - 1 && (int)lines.size() > ach_description_lines) {
                line = fit(rdram, ctx, offset, text_scale, line + " " + lines[i + 1], ach_right - ach_left);
            }
            print(rdram, ctx, gfx, offset, colour_white, text_scale, ach_left, y, line);
        }
    }
}

namespace {
    // ---- The unlock pop-up: the portrait with "ACHIEVEMENT UNLOCKED" and the name and score beside
    // it, at the top of the screen, sliding down and fading in, then out. Its strings go after the
    // pause page's in the string area.
    constexpr uint32_t popup_string_offset = 0x800;
    constexpr int64_t popup_in_ms = 300;
    constexpr int64_t popup_show_ms = 4000;
    constexpr int64_t popup_out_ms = 500;
    constexpr int popup_icon_size = 30;
    constexpr int popup_x = 104;
    constexpr int popup_y = 18;

    tooie::achievements::Popup popup;
    int64_t popup_start = -1;
}

void tooie::achievements::draw_popup(uint8_t* rdram, recomp_context* ctx, uint32_t gfx) {
    const int64_t ms = now_ms();
    if (popup_start >= 0 && ms - popup_start > popup_in_ms + popup_show_ms + popup_out_ms) {
        popup_start = -1;
    }
    if (popup_start < 0) {
        if (!take_popup(popup)) {
            return;
        }
        popup_start = ms;
    }
    const int64_t t = ms - popup_start;
    float in = 1.0f;
    if (t < popup_in_ms) {
        in = (float)t / popup_in_ms;
    } else if (t > popup_in_ms + popup_show_ms) {
        in = 1.0f - (float)(t - popup_in_ms - popup_show_ms) / popup_out_ms;
    }
    in = std::clamp(in, 0.0f, 1.0f);
    const float saved_in = page_in;
    const int saved_rise = rise;
    page_in = in;
    rise = -(int)((1.0f - in) * 12.0f + 0.5f);
    uint32_t offset = popup_string_offset;
    // The game's sprites draw at full strength, so the icon shows only while the text is fully in.
    if (in >= 1.0f) {
        draw_portrait(rdram, ctx, gfx, popup.portrait, popup_x + popup_icon_size / 2, popup_y + popup_icon_size / 2, popup_icon_size);
    }
    const int text_x = popup_x + popup_icon_size + 6;
    print(rdram, ctx, gfx, offset, colour_blue, text_scale, text_x, popup_y + 2, "ACHIEVEMENT UNLOCKED");
    print(rdram, ctx, gfx, offset, colour_yellow, text_scale, text_x, popup_y + 2 + line_height,
          printable(popup.name) + "  " + std::to_string(popup.points) + "G");
    page_in = saved_in;
    rise = saved_rise;
}

extern "C" void tooie_totals_checklist_draw(uint8_t* rdram, recomp_context* ctx) {
    const gpr pause = ctx->r16;
    const uint8_t page = MEM_BU(pause_page, pause);
    const uint8_t sub_page = MEM_BU(pause_sub_page, pause);
    const uint32_t gfx = MEM_W(0x20, ctx->r29);

    if (page != last_page || sub_page != last_sub_page) {
        // Worked out again each time a Totals page opens; nothing changes while paused.
        if (page == page_totals && last_page != page_totals) {
            checklist.valid = false;
            table_cursor = 0;
        }
        list.open = false;
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

    // Every pause page passes here, so the pad filter learns at once when no table is on screen.
    input_mode.store(mode_none);
    if (page == page_totals && sub_page == tooie::achievements::pause_sub_page) {
        if (!last_achievements_open) {
            ach_cursor = 0;
            ach_top = 0;
        }
        last_achievements_open = true;
        if (MEM_BU(pause_draw_header, pause) == 0) {
            return;
        }
        page_in = std::min(1.0f, MEM_BU(pause_title_step, pause) / 10.0f);
        rise = (int)((1.0f - page_in) * 12.0f + 0.5f);
        presses_a.exchange(0);
        presses_b.exchange(0);
        uint32_t offset = 0;
        drawn_at_ms.store(now_ms());
        input_mode.store(mode_table);
        draw_achievements(rdram, ctx, gfx, offset, moves_down.exchange(0));
        return;
    }
    last_achievements_open = false;
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
    if (!checklist.valid) {
        evaluate(rdram, ctx);
    }
    page_in = std::min(1.0f, MEM_BU(pause_title_step, pause) / 10.0f);
    rise = (int)((1.0f - page_in) * 12.0f + 0.5f);

    // The pad filter's presses since the last frame.
    const int steps = moves_down.exchange(0);
    const int a = presses_a.exchange(0);
    const int b = presses_b.exchange(0);
    uint32_t offset = 0;

    if (list.open) {
        if (b > 0) {
            list.open = false;
        } else if (!list.entries.empty()) {
            list.cursor = std::clamp(list.cursor + steps, 0, (int)list.entries.size() - 1);
        }
    }
    if (list.open) {
        drawn_at_ms.store(now_ms());
        input_mode.store(mode_list);
        draw_list(rdram, ctx, gfx, offset);
        return;
    }

    // The table: one row per kind of collectible the page counts.
    struct Shown {
        const char* name;
        int category;
        Count c;
        uint32_t now;
    };
    Shown shown[8];
    int line_count = 0;
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
            shown[line_count++] = { row.name, row.category, c, now_for(level, row.category) };
        }
    }
    const Count moves = count_moves(rdram, ctx, level);
    if (moves.total != 0) {
        shown[line_count++] = { "MOVES", category_moves, moves, now_for(level, category_moves) };
    }
    if (line_count > 0) {
        table_cursor = std::clamp(table_cursor + steps, 0, line_count - 1);
        if (a > 0) {
            open_list(level, shown[table_cursor].category);
            if (std::getenv("TOOIE_TOTALS_LOG") != nullptr) {
                fprintf(stderr, "[totals] list %s: %zu entries\n", list.title.c_str(), list.entries.size());
                for (const Entry& e : list.entries) {
                    fprintf(stderr, "[totals]   %s %s\n", e.status == status_now ? "now  " : e.status == status_done ? "done " : "later",
                            e.name.c_str());
                }
            }
            drawn_at_ms.store(now_ms());
            input_mode.store(mode_list);
            draw_list(rdram, ctx, gfx, offset);
            return;
        }
    }
    drawn_at_ms.store(now_ms());
    input_mode.store(line_count > 0 ? mode_table : mode_none);

    const int header_y = block_y - line_height;
    print(rdram, ctx, gfx, offset, colour_blue, text_scale, block_x, header_y, level < 0 ? "LEFT IN GAME" : "LEFT HERE");
    print(rdram, ctx, gfx, offset, colour_green, text_scale, now_x, header_y, "NOW", true);
    uint32_t things_left = 0;
    uint32_t things_now = 0;
    for (int line = 0; line < line_count; line++) {
        const Shown& r = shown[line];
        if (line == table_cursor) {
            draw_a_button(rdram, ctx, gfx, button_x, block_y + line_height * line + button_dy, now_ms());
        }
        print_row(rdram, ctx, gfx, offset, line, r.name, r.c, r.now);
        if (r.c.got < r.c.total) {
            things_left += 1;
            things_now += r.now > 0 ? 1 : 0;
        }
    }

    // The verdict under the table, and how to open a list.
    int y = block_y + line_height * line_count + 3;
    if (level < 0) {
        if (checklist.world_can_open) {
            print(rdram, ctx, gfx, offset, colour_green, text_scale, block_x, y, "NEW WORLD READY");
            y += line_height;
        }
    } else {
        if (things_left == 0) {
            print(rdram, ctx, gfx, offset, colour_yellow, text_scale, block_x, y, "ALL DONE HERE");
        } else if (things_now > 0) {
            print(rdram, ctx, gfx, offset, colour_green, text_scale, block_x, y, "MORE TO GET HERE");
        } else {
            print(rdram, ctx, gfx, offset, colour_yellow, text_scale, block_x, y, "MOVE ON FOR NOW");
        }
        y += line_height;
    }
}

// Runs on every read of player 1's pad. While a Totals table or list is on screen it turns up/down
// (D-pad, C buttons or the stick) into cursor steps and A / B into presses for the draw hook, and keeps
// those from the game: the page would otherwise act on them (the stick turns pages, B leaves Totals).
void tooie::totals_checklist::apply_input(uint16_t* buttons, float* x, float* y) {
    constexpr uint16_t button_a = 0x8000;
    constexpr uint16_t button_b = 0x4000;
    constexpr uint16_t dpad_up = 0x0800;
    constexpr uint16_t dpad_down = 0x0400;
    constexpr uint16_t c_up = 0x0008;
    constexpr uint16_t c_down = 0x0004;

    static bool held_a = false;
    static bool held_b = false;
    static bool swallow_b = false;
    static int held_dir = 0;
    static int64_t next_repeat = 0;

    constexpr uint16_t button_start = 0x1000;
    static int64_t start_at = -100000;
    const int64_t now = now_ms();
    // The draw hook says what is on screen on every pause frame. Start closes the pause menu, after
    // which the hook stops running, so nothing is kept from the game for a while after it.
    if ((*buttons & button_start) != 0) {
        start_at = now;
    }
    int mode = input_mode.load();
    if (now - drawn_at_ms.load() > 1000 || now - start_at < 2500) {
        mode = mode_none;
    }
    const bool a = (*buttons & button_a) != 0;
    const bool b = (*buttons & button_b) != 0;
    int dir = 0;
    if ((*buttons & (dpad_up | c_up)) != 0 || *y > 0.5f) {
        dir = -1;
    } else if ((*buttons & (dpad_down | c_down)) != 0 || *y < -0.5f) {
        dir = 1;
    }

    if (mode == mode_none) {
        held_a = a;
        held_b = b;
        held_dir = dir;
        swallow_b = swallow_b && b;
        if (swallow_b) {
            *buttons &= ~button_b;
        }
        return;
    }

    if (dir != 0 && dir != held_dir) {
        moves_down.fetch_add(dir);
        next_repeat = now + 350;
    } else if (dir != 0 && now >= next_repeat) {
        moves_down.fetch_add(dir);
        next_repeat = now + 100;
    }
    held_dir = dir;
    if (a && !held_a) {
        presses_a.fetch_add(1);
    }
    held_a = a;
    if (mode == mode_list && b && !held_b) {
        presses_b.fetch_add(1);
        swallow_b = true;   // until B is let go, after the list has closed too
    }
    held_b = b;

    *buttons &= ~(button_a | dpad_up | dpad_down | c_up | c_down);
    *y = 0.0f;
    if (mode == mode_list) {
        *buttons &= ~button_b;
        *x = 0.0f;
    }
    swallow_b = swallow_b && b;
    if (swallow_b) {
        *buttons &= ~button_b;
    }
}
