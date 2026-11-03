// Transform Anywhere Menu (L, 2026-11-03): QOL > Transform Anywhere Menu, off by default. A separate toggle from
// Transform Anywhere (transform_anywhere.cpp), which keeps working as before while this one is off.
//
// While it is on, the Transform key (Controls tab, Movement; T, and LT + Y on a controller) opens a menu over the
// game instead of changing into the world's Humba form. The game stands still behind it (the frame's delta time
// is set to almost nothing, as the Pause Special Menu does), and the forms are laid out round the middle of the
// screen with Banjo-Kazooie in the centre, after the picture L sent: the character pictures spread over the
// scene and a bar along the bottom reading SELECT, TRANSFORM, BACK with the buttons beside each.
//
// Only forms the save file has already unlocked are shown (L): locked ones are left out rather than shown greyed,
// since the pictures are the game's own sprites, which the game always draws at full strength. What counts as
// unlocked is the game's own flags, kept in the save file:
//   - Humba Wumba's forms: her "first time transformed" flags 0x345-0x34D (decomp gameflags.h
//     FLAG_345_FTT_WUMBA_TRANSFORMED_T_REX_BIG .. FLAG_34D_FTT_WUMBA_TRANSFORMED_BEE), set the first time Banjo
//     changes in each pool.
//   - Mumbo: FLAG_429_FTT_MUMBO_USED, or FLAG_09A_FTT_MUMBO_PAD (first Mumbo pad).
//   - Golden Goliath: FLAG_050_FTT_MT_GoldenGoliath, or its Jiggy FLAG_255.
//   - Banjo and Kazooie alone: FLAG_109_ABILITY_SPLIT_UP, or FLAG_4F5_FTT_SPLIT_UP.
//   - Clockwork Kazooie: FLAG_11B_ABILITY_EGGS_CLOCKWORK.
//   - Banjo-Kazooie: always.
//
// The change itself is the Cheats tab's Transformation row's (transform_picker.cpp): the form is stored where
// the game reads it when an area loads, and the area reloads at the entrance Banjo came in by. That works for
// every form in every world, where the in-place change Transform Anywhere uses only works for the world's own
// Humba form. Some forms can break in areas the game never expects them in, as with the cheat.
//
// Drawing: text with the pause menu's font through the game's own text routines (as the Totals checklist
// prints), the pictures as the game's talking-head portraits (gczoomboxdata's table, as the achievement icons),
// and the pause menu's own A and B button sprites. A form with no fitting portrait shows its name instead.
//
// Headless: TOOIE_TRANSFORM_MENU=1 turns it on whatever the setting says, TOOIE_TRANSFORM_MENU_OPEN=<ms> opens it
// that long after the game loop first runs, TOOIE_TRANSFORM_MENU_ALL=1 shows every form whether unlocked or not,
// TOOIE_TRANSFORM_MENU_PORTRAITS=<hex form>=<hex portrait>,... tries other pictures, TOOIE_TRANSFORM_MENU_DPAD=<hex>
// tries a sprite for the d-pad, TOOIE_TRANSFORM_MENU_LOG=1 logs [transform-menu] lines.

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <mutex>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

#include "recomp.h"
#include "funcs.h"
#include "recompinput/recompinput.h"
#include "recompui/config.h"
#include "tooie_debug.h"
#include "tooie_game.h"
#include "tooie_hotkeys.h"
#include "tooie_rdram.h"
#include "tooie_transform_menu.h"
#include "tooie_transform_picker.h"

namespace {
    using Clock = std::chrono::steady_clock;
    using tooie::rdram::read_word;
    using tooie::rdram::write_word;
    using tooie::rdram::read_half;
    using tooie::rdram::write_float;

    constexpr uint32_t player_table = 0x80135490;      // player pointers, player 0 first
    constexpr uint32_t pause_menu_addr = 0x80128AF0;   // the game's pause menu while it is open
    constexpr uint32_t dialog_id_addr = 0x80128A12;    // the text being shown, -1 for none
    constexpr uint32_t delta_time_addr = 0x8012C760;   // the frame's delta time (func_800D8FA0)
    constexpr float frozen_delta = 1.0e-7f;            // as photo mode's: not zero, as some code divides by it

    // Text settings block D_801282C0 (decomp include/core2/1E91790.h), as the Totals checklist uses it.
    constexpr uint32_t text_settings = 0x801282C0;
    constexpr uint32_t text_alpha = 0x3;
    constexpr uint32_t text_font = 0x6;
    constexpr uint32_t text_colour = 0x9;
    constexpr uint32_t text_size = 0x14;
    constexpr int menu_font = 1;                       // the pause menu's font (capitals)
    constexpr int colour_white = 0;
    constexpr int colour_yellow = 2;
    constexpr int colour_blue = 4;

    // Strings and sprite coordinates go in extended RDRAM no one else uses: the pause menu's SETTINGS rows end
    // before 0x80EF1400 and Snout jiggle's copies start at 0x80EF8000.
    constexpr uint32_t string_area = 0x80EF4000;
    constexpr uint32_t string_area_size = 0x800;
    constexpr uint32_t coords_addr = string_area + string_area_size - 8;   // Coords2D, in quarter pixels

    // The pause menu's own button sprites: 0xB58 the A button (four frames of it turning), 0xB59 the B button.
    constexpr uint32_t sprite_a_button = 0xB58;
    constexpr uint32_t sprite_b_button = 0xB59;

    // Where things go on the game's 320 x 240 2D screen.
    constexpr int centre_x = 160;
    constexpr int centre_y = 102;
    constexpr float ring_x = 112.0f;
    constexpr float ring_y = 64.0f;
    constexpr int portrait_size = 24;
    constexpr int picked_portrait_size = 36;
    constexpr int name_y = 188;
    constexpr int bar_y = 212;
    constexpr float text_scale = 0.5f;
    constexpr float small_scale = 0.38f;

    // A form, the game's id for it (as the player's +0xA0 block +0x29 holds it), its portrait (-1 for none) and
    // the flags any of which unlocks it (none: always).
    struct Form {
        uint8_t id;
        const char* name;
        int portrait;
        int32_t flags[3];
    };
    // Banjo-Kazooie first (the middle), then round the ring clockwise from the top.
    const Form forms[] = {
        { 0x01, "BANJO-KAZOOIE", 0x0C, { -1, -1, -1 } },
        { 0x0A, "BANJO", 0x7A, { 0x109, 0x4F5, -1 } },
        { 0x0B, "KAZOOIE", 0x0D, { 0x109, 0x4F5, -1 } },
        { 0x0D, "MUMBO", 0x10, { 0x429, 0x09A, -1 } },
        { 0x0E, "GOLDEN GOLIATH", -1, { 0x050, 0x255, -1 } },
        { 0x08, "STONY", -1, { 0x346, -1, -1 } },
        { 0x0F, "DETONATOR", -1, { 0x347, -1, -1 } },
        { 0x10, "VAN", 0x3A, { 0x348, -1, -1 } },
        { 0x0C, "SUBMARINE", -1, { 0x349, -1, -1 } },
        { 0x12, "BABY T-REX", -1, { 0x34A, -1, -1 } },
        { 0x13, "DADDY T-REX", -1, { 0x345, -1, -1 } },
        { 0x07, "WASHING MACHINE", 0x04, { 0x34B, -1, -1 } },
        { 0x02, "SNOWBALL", -1, { 0x34C, -1, -1 } },
        { 0x06, "BEE", 0x9B, { 0x34D, -1, -1 } },
        { 0x11, "CLOCKWORK KAZOOIE", -1, { 0x11B, -1, -1 } },
    };
    constexpr size_t form_count = sizeof(forms) / sizeof(forms[0]);

    struct Entry {
        size_t form;     // index into forms
        int x, y;        // middle of its picture
    };

    struct Menu {
        bool open = false;
        std::vector<Entry> entries;
        size_t picked = 0;
        uint8_t current = 0;      // the player's form when it opened
        bool key_was_held = false;
        Clock::time_point opened_at{};
    } menu;

    // Shared with the input thread.
    std::atomic<bool> open_flag{false};
    std::atomic<uint16_t> exit_mask{0};
    struct Events {
        std::mutex mutex;
        std::deque<int> list;   // 'A', 'B', 'S' (start), or a direction 1..8 (x + 1 + 3 * (y + 1), not 4)
    } events;

    bool log_on() {
        static const bool on = std::getenv("TOOIE_TRANSFORM_MENU_LOG") != nullptr;
        return on;
    }

    int64_t ms_since_start() {
        static const Clock::time_point start = Clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - start).count();
    }

    int portrait_of(size_t form) {
        static const std::unordered_map<int, int> overrides = [] {
            std::unordered_map<int, int> map;
            if (const char* v = std::getenv("TOOIE_TRANSFORM_MENU_PORTRAITS")) {
                std::string list{v};
                size_t pos = 0;
                while (pos < list.size()) {
                    size_t comma = list.find(',', pos);
                    unsigned f = 0, p = 0;
                    if (std::sscanf(list.substr(pos, comma - pos).c_str(), "%x=%x", &f, &p) == 2) {
                        map[(int)f] = (int)p;
                    }
                    pos = comma == std::string::npos ? list.size() : comma + 1;
                }
            }
            return map;
        }();
        auto found = overrides.find(forms[form].id);
        return found != overrides.end() ? found->second : forms[form].portrait;
    }

    // Calls a game function with up to four integer arguments on a copy of the hook's registers, with the stack
    // moved down so the callee uses scratch space.
    uint32_t call(uint8_t* rdram, recomp_context* ctx, void (*func)(uint8_t*, recomp_context*),
                  uint32_t a0 = 0, uint32_t a1 = 0, uint32_t a2 = 0, uint32_t a3 = 0) {
        recomp_context saved = *ctx;
        ctx->r29 = (int32_t)(((uint32_t)ctx->r29 - 0x200) & ~0xFu);
        ctx->r4 = (gpr)(int32_t)a0;
        ctx->r5 = (gpr)(int32_t)a1;
        ctx->r6 = (gpr)(int32_t)a2;
        ctx->r7 = (gpr)(int32_t)a3;
        func(rdram, ctx);
        const uint32_t result = (uint32_t)ctx->r2;
        *ctx = saved;
        return result;
    }

    bool flag_get(uint8_t* rdram, recomp_context* ctx, int32_t flag) {
        return call(rdram, ctx, func_800DA298, (uint32_t)flag) != 0;   // the game's flag getter
    }

    bool unlocked(uint8_t* rdram, recomp_context* ctx, const Form& f) {
        static const bool all = std::getenv("TOOIE_TRANSFORM_MENU_ALL") != nullptr;
        if (all || f.flags[0] < 0) {
            return true;
        }
        for (int32_t flag : f.flags) {
            if (flag >= 0 && flag_get(rdram, ctx, flag)) {
                return true;
            }
        }
        return false;
    }

    uint8_t player_form(uint8_t* rdram) {
        const uint32_t player = read_word(rdram, player_table);
        if (!tooie::rdram::valid_ptr(player)) {
            return 0;
        }
        const uint32_t block = read_word(rdram, player + 0xA0);
        if (!tooie::rdram::valid_ptr(block)) {
            return 0;
        }
        return MEM_BU(0x29, (gpr)(int32_t)block);
    }

    // Whether the menu may be up: a save file is being played, not paused, no map change, cutscene or talk.
    bool can_open(uint8_t* rdram) {
        return tooie::debug::can_warp() && tooie::rdram::valid_ptr(read_word(rdram, player_table)) &&
            read_word(rdram, pause_menu_addr) == 0 && !tooie::debug::map_change_busy(rdram) &&
            !tooie::in_letterboxed_scene() && read_half(rdram, dialog_id_addr) == -1;
    }

    void open(uint8_t* rdram, recomp_context* ctx) {
        menu.entries.clear();
        menu.current = player_form(rdram);
        std::vector<size_t> ring;
        for (size_t i = 1; i < form_count; i++) {
            if (unlocked(rdram, ctx, forms[i])) {
                ring.push_back(i);
            }
        }
        menu.entries.push_back({ 0, centre_x, centre_y });
        for (size_t i = 0; i < ring.size(); i++) {
            // Clockwise from the top, spread evenly.
            const float a = -1.5707963f + 6.2831853f * (float)i / (float)ring.size();
            menu.entries.push_back({ ring[i], centre_x + (int)std::lround(std::cos(a) * ring_x),
                                     centre_y + (int)std::lround(std::sin(a) * ring_y) });
        }
        menu.picked = 0;
        for (size_t i = 0; i < menu.entries.size(); i++) {
            if (forms[menu.entries[i].form].id == menu.current) {
                menu.picked = i;
            }
        }
        {
            std::lock_guard lock{ events.mutex };
            events.list.clear();
        }
        menu.open = true;
        menu.opened_at = Clock::now();
        open_flag = true;
        if (log_on()) {
            std::fprintf(stderr, "[transform-menu] opened: form 0x%X, %zu forms unlocked:", menu.current, menu.entries.size());
            for (const Entry& e : menu.entries) {
                std::fprintf(stderr, " %s", forms[e.form].name);
            }
            std::fprintf(stderr, "\n");
        }
    }

    void close(const char* why) {
        if (!menu.open) {
            return;
        }
        menu.open = false;
        open_flag = false;
        if (log_on()) {
            std::fprintf(stderr, "[transform-menu] closed: %s\n", why);
        }
    }

    // Moves the pick to the nearest entry in the direction (dx, dy; y down), favouring ones straight that way.
    void move_pick(int dx, int dy) {
        const Entry& from = menu.entries[menu.picked];
        const float len = std::sqrt((float)(dx * dx + dy * dy));
        const float ux = (float)dx / len;
        const float uy = (float)dy / len;
        float best = 1e9f;
        size_t best_index = menu.picked;
        for (size_t i = 0; i < menu.entries.size(); i++) {
            if (i == menu.picked) {
                continue;
            }
            const float vx = (float)(menu.entries[i].x - from.x);
            const float vy = (float)(menu.entries[i].y - from.y);
            const float dist = std::sqrt(vx * vx + vy * vy);
            if (dist < 1.0f) {
                continue;
            }
            const float along = (vx * ux + vy * uy) / dist;   // cos of the angle off the direction
            if (along < 0.35f) {
                continue;
            }
            const float score = dist / along / along;
            if (score < best) {
                best = score;
                best_index = i;
            }
        }
        menu.picked = best_index;
    }

    std::atomic<int> env_state{0};   // 0 not read, 1 waiting, 2 done or none

    bool env_open() {
        static int64_t at = -1;
        if (env_state.load() == 0) {
            env_state = 2;
            if (const char* v = std::getenv("TOOIE_TRANSFORM_MENU_OPEN")) {
                at = std::strtoll(v, nullptr, 10);
                env_state = 1;
            }
        }
        if (env_state.load() == 1 && ms_since_start() >= at) {
            env_state = 2;
            return true;
        }
        return false;
    }

    // --- drawing ---

    uint32_t put_string(uint8_t* rdram, uint32_t& offset, const std::string& text) {
        const size_t length = std::min<size_t>(text.size(), 63);
        if (offset + length + 1 > string_area_size - 8) {
            return 0;
        }
        for (size_t i = 0; i < length; i++) {
            MEM_B(offset + i, (gpr)(int32_t)string_area) = (int8_t)text[i];
        }
        MEM_B(offset + length, (gpr)(int32_t)string_area) = 0;
        const uint32_t addr = string_area + offset;
        offset = (offset + (uint32_t)length + 4) & ~3u;
        return addr;
    }

    void text_setup(uint8_t* rdram, recomp_context* ctx, int colour, float size) {
        uint32_t size_bits;
        std::memcpy(&size_bits, &size, sizeof(size_bits));
        call(rdram, ctx, func_800B8C50);
        MEM_B(text_font, (gpr)(int32_t)text_settings) = (int8_t)menu_font;
        MEM_B(text_colour, (gpr)(int32_t)text_settings) = (int8_t)colour;
        write_word(rdram, text_settings + text_size, size_bits);
    }

    // Prints a string with a dark copy one pixel down and right behind it, so it reads over the world.
    // align: 0 x is the left edge, 1 the middle, 2 the right edge.
    void print(uint8_t* rdram, recomp_context* ctx, uint32_t gfx, uint32_t& offset, int colour, float size,
               int x, int y, const std::string& text, int align = 0) {
        const uint32_t addr = put_string(rdram, offset, text);
        if (addr == 0) {
            return;
        }
        if (align != 0) {
            text_setup(rdram, ctx, colour, size);
            const int width = (int)call(rdram, ctx, func_800B8CFC, addr);
            x -= align == 1 ? width / 2 : width;
        }
        for (int pass = 0; pass < 2; pass++) {
            const bool shadow = pass == 0;
            text_setup(rdram, ctx, colour, size);
            MEM_B(text_alpha, (gpr)(int32_t)text_settings) = (int8_t)(uint8_t)(shadow ? 170 : 255);
            if (shadow) {
                MEM_B(0, (gpr)(int32_t)text_settings) = 0;
                MEM_B(1, (gpr)(int32_t)text_settings) = 0;
                MEM_B(2, (gpr)(int32_t)text_settings) = 0;
            }
            call(rdram, ctx, func_800B7F14, gfx);
            call(rdram, ctx, func_800B8E28, gfx, (uint32_t)(x + (shadow ? 1 : 0)), (uint32_t)(y + (shadow ? 1 : 0)), addr);
            call(rdram, ctx, func_800B811C, gfx);
        }
    }

    int text_width(uint8_t* rdram, recomp_context* ctx, uint32_t& offset, float size, const std::string& text) {
        const uint32_t addr = put_string(rdram, offset, text);
        if (addr == 0) {
            return 0;
        }
        text_setup(rdram, ctx, colour_white, size);
        return (int)call(rdram, ctx, func_800B8CFC, addr);
    }

    // Draws a sprite asset (func_800D674C loads it) with its middle at x, y, height pixels tall.
    void draw_sprite(uint8_t* rdram, recomp_context* ctx, uint32_t gfx, uint32_t asset, int x, int y, int height,
                     uint32_t frame = 0, int y_fix = 0) {
        const uint32_t image = call(rdram, ctx, func_800D674C, asset);
        if (!tooie::rdram::valid_ptr(image)) {
            return;
        }
        const gpr image_addr = (gpr)(int32_t)image;
        const int width = MEM_H(8, image_addr);
        const int tall = MEM_H(0xA, image_addr);
        if (width <= 0 || tall <= 0) {
            return;
        }
        const uint32_t frames = std::max<uint32_t>(1, (uint16_t)MEM_H(0, image_addr));
        write_word(rdram, coords_addr, (uint32_t)(x * 4));
        write_word(rdram, coords_addr + 4, (uint32_t)((y + y_fix) * 4));
        call(rdram, ctx, func_800E2568, (uint32_t)(width * height * 4 / tall), (uint32_t)(height * 4));
        call(rdram, ctx, func_800E30E0, gfx, image, frame % frames, coords_addr);
    }

    // A talking-head portrait (gczoomboxdata's table), as the achievement icons draw them.
    bool draw_portrait(uint8_t* rdram, recomp_context* ctx, uint32_t gfx, int portrait, int x, int y, int size) {
        if (portrait < 0) {
            return false;
        }
        static std::unordered_map<int, uint32_t> assets;
        auto found = assets.find(portrait);
        if (found == assets.end()) {
            found = assets.emplace(portrait, call(rdram, ctx, _gczoomboxdata_entrypoint_1, (uint32_t)portrait) & 0xFFFF).first;
        }
        if (found->second == 0) {
            return false;
        }
        // Portraits come out 12 pixels lower than asked at any size (measured for the achievement icons).
        draw_sprite(rdram, ctx, gfx, found->second, x, y, size, 0, -12);
        return true;
    }
}

bool tooie::transform_menu::enabled() {
    static const bool forced = std::getenv("TOOIE_TRANSFORM_MENU") != nullptr;
    if (forced) {
        return true;
    }
    try {
        return std::get<bool>(recompui::config::get_config(tooie::qol_tab_id).get_option_value(option));
    } catch (...) {
        return false;
    }
}

bool tooie::transform_menu::is_open() {
    return open_flag.load();
}

void tooie::transform_menu::tick(uint8_t* rdram, recomp_context* ctx) {
    const bool held = tooie::hotkeys::down(recompinput::GameInput::TRANSFORM);
    const bool key_pressed = held && !menu.key_was_held;
    menu.key_was_held = held;
    const bool env_pressed = env_open();

    if (!enabled()) {
        close("option off");
        return;
    }
    if (!menu.open) {
        if ((key_pressed || env_pressed) && can_open(rdram)) {
            open(rdram, ctx);
        }
        return;
    }
    if (!can_open(rdram)) {
        close("the game moved on (pause, map change, cutscene or talk)");
        return;
    }
    // The game stands still behind the menu.
    write_float(rdram, delta_time_addr, frozen_delta);

    // The Transform key shuts it again, once it has been up a moment.
    if (key_pressed && Clock::now() - menu.opened_at > std::chrono::milliseconds(200)) {
        close("Transform key");
        return;
    }
    std::deque<int> list;
    {
        std::lock_guard lock{ events.mutex };
        list.swap(events.list);
    }
    for (int e : list) {
        if (e == 'B' || e == 'S') {
            close(e == 'B' ? "B" : "Start");
            return;
        }
        if (e == 'A') {
            const Form& f = forms[menu.entries[menu.picked].form];
            if (f.id == player_form(rdram)) {
                close("A on the form Banjo already has");
                return;
            }
            const bool asked = tooie::transform_picker::request_form(f.id);
            if (log_on()) {
                std::fprintf(stderr, "[transform-menu] A: %s (0x%X) %s\n", f.name, f.id, asked ? "asked for" : "not taken");
            }
            close("A");
            return;
        }
        if (e >= 0 && e <= 8 && e != 4) {
            move_pick(e % 3 - 1, e / 3 - 1);
            if (log_on()) {
                std::fprintf(stderr, "[transform-menu] picked %s\n", forms[menu.entries[menu.picked].form].name);
            }
        }
    }
}

void tooie::transform_menu::draw(uint8_t* rdram, recomp_context* ctx, uint32_t gfx) {
    if (!menu.open || menu.entries.empty()) {
        return;
    }
    const int64_t ms = ms_since_start();
    uint32_t offset = 0;

    // The forms: the picked one larger, its name below the ring. A form with no portrait shows its name.
    for (size_t i = 0; i < menu.entries.size(); i++) {
        const Entry& e = menu.entries[i];
        const bool picked = i == menu.picked;
        const int size = picked ? picked_portrait_size : portrait_size;
        if (!draw_portrait(rdram, ctx, gfx, portrait_of(e.form), e.x, e.y, size)) {
            print(rdram, ctx, gfx, offset, picked ? colour_yellow : colour_white, picked ? text_scale : small_scale,
                  e.x, e.y - 4, forms[e.form].name, 1);
        }
    }
    // The pick marker: the A button turning just above the picked form.
    {
        const Entry& e = menu.entries[menu.picked];
        draw_sprite(rdram, ctx, gfx, sprite_a_button, e.x, e.y - picked_portrait_size / 2 - 6, 10, (uint32_t)(ms / 150));
    }
    const Form& f = forms[menu.entries[menu.picked].form];
    std::string name = f.name;
    if (f.id == menu.current) {
        name += " (NOW)";
    }
    print(rdram, ctx, gfx, offset, colour_blue, text_scale, centre_x, name_y, name, 1);

    // The bar along the bottom: [d-pad] SELECT  [A] TRANSFORM  [B] BACK, centred as a whole.
    static const int dpad_sprite = [] {
        const char* v = std::getenv("TOOIE_TRANSFORM_MENU_DPAD");
        return v != nullptr ? (int)std::strtol(v, nullptr, 16) : -1;
    }();
    constexpr int icon = 14;
    constexpr int gap = 4;
    constexpr int spacing = 16;
    const char* labels[3] = { "SELECT", "TRANSFORM", "BACK" };
    int widths[3];
    int total = 0;
    for (int i = 0; i < 3; i++) {
        widths[i] = text_width(rdram, ctx, offset, text_scale, labels[i]);
        total += icon + gap + widths[i];
    }
    total += spacing * 2;
    int x = centre_x - total / 2;
    for (int i = 0; i < 3; i++) {
        const int icon_x = x + icon / 2;
        if (i == 0) {
            if (dpad_sprite >= 0) {
                draw_sprite(rdram, ctx, gfx, (uint32_t)dpad_sprite, icon_x, bar_y, icon);
            } else {
                // No d-pad picture in the pause menu's set: a plus in the menu font stands for it.
                print(rdram, ctx, gfx, offset, colour_white, 0.7f, icon_x, bar_y - 7, "+", 1);
            }
        } else {
            draw_sprite(rdram, ctx, gfx, i == 1 ? sprite_a_button : sprite_b_button, icon_x, bar_y, icon);
        }
        print(rdram, ctx, gfx, offset, colour_white, text_scale, x + icon + gap, bar_y - 5, labels[i]);
        x += icon + gap + widths[i] + spacing;
    }
}

void tooie::transform_menu::apply_input(uint16_t* buttons, float* x, float* y) {
    constexpr uint16_t button_a = 0x8000;
    constexpr uint16_t button_b = 0x4000;
    constexpr uint16_t button_start = 0x1000;
    constexpr uint16_t dpad_up = 0x0800;
    constexpr uint16_t dpad_down = 0x0400;
    constexpr uint16_t dpad_left = 0x0200;
    constexpr uint16_t dpad_right = 0x0100;

    static uint16_t last = 0;
    static int held_dir = 4;
    static int64_t next_repeat = 0;

    if (!open_flag.load()) {
        // Held since the menu closed: kept from the game until let go (B would jump, A would attack).
        if (const uint16_t mask = exit_mask.load(); mask != 0) {
            const uint16_t still = mask & *buttons;
            exit_mask = still;
            *buttons = (uint16_t)(*buttons & ~still);
        }
        last = *buttons;
        held_dir = 4;
        return;
    }
    const uint16_t now_buttons = *buttons;
    const uint16_t pressed = now_buttons & ~last;
    last = now_buttons;

    int dx = 0, dy = 0;
    if ((now_buttons & dpad_left) != 0 || *x < -0.5f) {
        dx = -1;
    } else if ((now_buttons & dpad_right) != 0 || *x > 0.5f) {
        dx = 1;
    }
    if ((now_buttons & dpad_up) != 0 || *y > 0.5f) {
        dy = -1;
    } else if ((now_buttons & dpad_down) != 0 || *y < -0.5f) {
        dy = 1;
    }
    const int dir = dx + 1 + 3 * (dy + 1);
    const int64_t ms = ms_since_start();
    {
        std::lock_guard lock{ events.mutex };
        if (dir != 4 && dir != held_dir) {
            events.list.push_back(dir);
            next_repeat = ms + 350;
        } else if (dir != 4 && ms >= next_repeat) {
            events.list.push_back(dir);
            next_repeat = ms + 180;
        }
        if (pressed & button_a) {
            events.list.push_back('A');
        }
        if (pressed & button_b) {
            events.list.push_back('B');
        }
        if (pressed & button_start) {
            events.list.push_back('S');
        }
    }
    held_dir = dir;
    // The game sees nothing while the menu is up, and nothing held now until it is let go after.
    exit_mask = now_buttons;
    *buttons = 0;
    *x = 0.0f;
    *y = 0.0f;
}
