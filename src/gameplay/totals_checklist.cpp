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

        // The areas that can be reached: from the start, through every entrance that is open, until
        // nothing changes.
        s.reached[R_MENU] = true;
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

    // Per level and category: how many are left, and how many of those can be got now. Notes count in
    // notes (5 a nest, 20 a Treble Clef).
    struct Checklist {
        uint32_t now[16][7] = {};       // by level - 0x0F, category
        bool valid = false;
        bool world_can_open = false;    // Jiggywiggy would open the next world
    };
    Checklist checklist;

    // Jiggies Jiggywiggy asks for each world, in order (MT .. CK).
    constexpr int world_cost[9] = { 1, 4, 8, 14, 20, 28, 36, 45, 55 };

    void evaluate(uint8_t* rdram, recomp_context* ctx) {
        using namespace totals_rules;
        static State s;
        static bool collected[sizeof(locations) / sizeof(locations[0])];
        s = State{};
        fill_state(rdram, ctx, s, collected);
        checklist = Checklist{};
        const bool log = std::getenv("TOOIE_TOTALS_LOG") != nullptr;
        for (size_t i = 0; i < sizeof(locations) / sizeof(locations[0]); i++) {
            const Location& l = locations[i];
            if (collected[i] || !s.reach(l.region) || (l.rule != nullptr && !l.rule(s))) {
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
        }
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
    if (!checklist.valid) {
        evaluate(rdram, ctx);
    }

    uint32_t offset = 0;
    const int header_y = block_y - line_height;
    print(rdram, ctx, gfx, offset, colour_blue, text_scale, block_x, header_y, level < 0 ? "LEFT IN GAME" : "LEFT HERE");
    print(rdram, ctx, gfx, offset, colour_green, text_scale, now_x, header_y, "NOW", true);
    int line = 0;
    uint32_t things_left = 0;
    uint32_t things_now = 0;
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
        if (c.total == 0) {
            continue;
        }
        const uint32_t now = now_for(level, row.category);
        print_row(rdram, ctx, gfx, offset, line++, row.name, c, now);
        if (c.got < c.total) {
            things_left += 1;
            things_now += now > 0 ? 1 : 0;
        }
    }
    const Count moves = count_moves(rdram, ctx, level);
    if (moves.total != 0) {
        const uint32_t now = now_for(level, category_moves);
        print_row(rdram, ctx, gfx, offset, line++, "MOVES", moves, now);
        if (moves.got < moves.total) {
            things_left += 1;
            things_now += now > 0 ? 1 : 0;
        }
    }

    // The verdict under the table.
    const int y = block_y + line_height * line + 3;
    if (level < 0) {
        if (checklist.world_can_open) {
            print(rdram, ctx, gfx, offset, colour_green, text_scale, block_x, y, "NEW WORLD READY");
        }
    } else if (things_left == 0) {
        print(rdram, ctx, gfx, offset, colour_yellow, text_scale, block_x, y, "ALL DONE HERE");
    } else if (things_now > 0) {
        print(rdram, ctx, gfx, offset, colour_green, text_scale, block_x, y, "MORE TO GET HERE");
    } else {
        print(rdram, ctx, gfx, offset, colour_yellow, text_scale, block_x, y, "MOVE ON FOR NOW");
    }
}
