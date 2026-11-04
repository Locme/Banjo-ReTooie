// Transform Anywhere Menu (L, 2026-11-03): WIP tab > Transform Anywhere Menu, off by default. A separate toggle from
// Transform Anywhere (transform_anywhere.cpp), which keeps working as before while this one is off.
//
// While it is on, the Transform key (Controls tab, Movement; T, and LT + Y on a controller) opens a menu instead of
// changing into the world's Humba form. The game stands still (the frame's delta time is set to almost nothing,
// as the Pause Special Menu does) and the forms Banjo has been stand round him as their real 3D models, in an arc
// in front of him, after the picture L sent. The picked one is larger and spins; the others are faded back
// (the actor's alpha, +0x9B), and a bar along the bottom reads SELECT, TRANSFORM, BACK.
//
// The models: each is a Golden Goliath statue (actor 0x163, a still model) spawned with the game's own
// func_80108474 and given the form's model (its id struct +0x14), as the test room shows the transformations
// (test_room_actors.inc). They are removed with func_800FFAB0 when the
// menu closes (a map change removes them too). Banjo alone has no model of his own: the game draws him with the
// pair's 0x062A, so his statue shows Banjo-Kazooie (L to judge).
//
// Only forms Banjo has been at least once are shown (L); locked ones are left out. The game's own flags, kept in
// the save file:
//   - Humba Wumba's forms: her "first time transformed" flags 0x345-0x34D (decomp gameflags.h
//     FLAG_345_FTT_WUMBA_TRANSFORMED_T_REX_BIG .. FLAG_34D_FTT_WUMBA_TRANSFORMED_BEE), set the first time Banjo
//     changes in each pool.
//   - Banjo and Kazooie alone: FLAG_4F5_FTT_SPLIT_UP (split up once; learning the move is not enough).
//   - Banjo-Kazooie: always.
// Clockwork Kazooie, Mumbo and Golden Goliath are not offered (L).
//
// The change itself is the Cheats tab's Transformation row's (transform_picker.cpp): the form is stored where
// the game reads it when an area loads, and the area reloads at the entrance Banjo came in by. That works for
// every form in every world. Some forms can break in areas the game never expects them in, as with the cheat.
//
// Text is printed with the pause menu's font through the game's own text routines (as the Totals checklist
// prints), with the pause menu's own A and B button sprites.
//
// Headless: TOOIE_TRANSFORM_MENU=1 turns it on whatever the setting says, TOOIE_TRANSFORM_MENU_OPEN=<ms> opens it
// that long after the game loop first runs, TOOIE_TRANSFORM_MENU_ALL=1 shows every form whether unlocked or not,
// TOOIE_TRANSFORM_MENU_DPAD=<hex> tries a sprite for the d-pad, TOOIE_TRANSFORM_MENU_ALPHA=<0-255> sets the
// faded models' alpha, TOOIE_TRANSFORM_MENU_LOG=1 logs [transform-menu] lines.

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

    // The 3D line-up: an arc in front of Banjo, this far from him, spanning this many degrees either side of
    // where he faces, with at least this much room between models.
    constexpr float arc_radius = 260.0f;
    constexpr float arc_half_degrees = 100.0f;
    constexpr float min_gap = 110.0f;
    constexpr float picked_grow = 1.3f;
    constexpr float spin_degrees_per_second = 120.0f;
    constexpr uint8_t default_faded_alpha = 150;

    constexpr uint16_t statue_actor = 0x163;          // the Golden Goliath statue: a still model
    constexpr uint32_t object_array_pointer = 0x80136EE0;
    constexpr uint32_t object_first = 0x04;
    constexpr uint32_t object_last = 0x08;
    constexpr uint32_t object_base = 0x10;
    constexpr uint32_t object_size = 0x9C;
    constexpr uint32_t object_pos = 0x04;
    constexpr uint32_t object_scale = 0x38;
    constexpr uint32_t object_yaw = 0x48;
    constexpr uint32_t object_alpha = 0x9B;
    constexpr uint32_t marker_model = 0x14;
    constexpr int max_objects = 2048;
    constexpr uint32_t player_pos_ptr = 0xE4;
    constexpr uint32_t player_yaw_ptr = 0xF8;
    constexpr int name_y = 188;
    constexpr int bar_y = 212;
    constexpr float text_scale = 0.5f;
    constexpr float small_scale = 0.38f;

    // A form: the game's id for it (as the player's +0xA0 block +0x29 holds it), its model, its size in the menu and the flags any of which unlocks it (none: always).
    struct Form {
        uint8_t id;
        const char* name;
        uint16_t model;
        float scale;
        int32_t flags[3];
    };
    // Left to right along the arc.
    const Form forms[] = {
        { 0x01, "BANJO-KAZOOIE", 0x61F, 1.0f, { -1, -1, -1 } },
        { 0x0A, "BANJO", 0x62A, 1.0f, { 0x4F5, -1, -1 } },
        { 0x0B, "KAZOOIE", 0x61C, 1.0f, { 0x4F5, -1, -1 } },
        { 0x08, "STONY", 0x61D, 1.0f, { 0x346, -1, -1 } },
        { 0x0F, "DETONATOR", 0x623, 1.0f, { 0x347, -1, -1 } },
        { 0x10, "VAN", 0x624, 0.8f, { 0x348, -1, -1 } },
        { 0x0C, "SUBMARINE", 0x626, 0.8f, { 0x349, -1, -1 } },
        { 0x12, "BABY T-REX", 0x609, 1.0f, { 0x34A, -1, -1 } },
        { 0x13, "DADDY T-REX", 0x60D, 0.3f, { 0x345, -1, -1 } },
        { 0x07, "WASHING MACHINE", 0x60C, 1.0f, { 0x34B, -1, -1 } },
        { 0x02, "SNOWBALL", 0x60B, 0.6f, { 0x34C, -1, -1 } },
        { 0x06, "BEE", 0x613, 1.0f, { 0x34D, -1, -1 } },
    };
    constexpr size_t form_count = sizeof(forms) / sizeof(forms[0]);

    struct Entry {
        size_t form;          // index into forms
        float pos[3];         // where its statue stands
        float yaw;            // facing Banjo
        uint32_t marker = 0;  // the statue's id struct (object +0), 0 if it did not spawn
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

    uint8_t faded_alpha() {
        static const uint8_t alpha = [] {
            const char* v = std::getenv("TOOIE_TRANSFORM_MENU_ALPHA");
            return v != nullptr ? (uint8_t)std::clamp(std::atoi(v), 0, 255) : default_faded_alpha;
        }();
        return alpha;
    }

    // Calls fn(object) for every live object (the array moves when objects come and go, so statues are found
    // again each frame by their id struct).
    template <typename F>
    void for_each_object(uint8_t* rdram, F fn) {
        const uint32_t array = read_word(rdram, object_array_pointer);
        if (!tooie::rdram::valid_ptr(array)) {
            return;
        }
        const uint32_t first = read_word(rdram, array + object_first);
        const uint32_t last = read_word(rdram, array + object_last);
        if (!tooie::rdram::valid_ptr(first) || !tooie::rdram::valid_ptr(last) || last < first) {
            return;
        }
        const int count = (int)((last - first) / object_size) + 1;
        if (count > max_objects) {
            return;
        }
        for (int i = 0; i < count; i++) {
            fn(array + object_base + (uint32_t)i * object_size);
        }
    }

    uint32_t find_object(uint8_t* rdram, uint32_t marker) {
        uint32_t found = 0;
        if (marker == 0) {
            return 0;
        }
        for_each_object(rdram, [&](uint32_t object) {
            if (found == 0 && read_word(rdram, object) == marker) {
                found = object;
            }
        });
        return found;
    }

    // The game's spawn-by-id, func_80108474(id, f32 pos[3], yaw), on a copy of the registers with the position
    // in scratch space below the stack.
    uint32_t spawn(uint8_t* rdram, recomp_context* ctx, uint16_t id, const float pos[3], float yaw) {
        recomp_context saved = *ctx;
        const uint32_t vec = ((uint32_t)ctx->r29 - 0x100) & ~0xFu;
        for (int k = 0; k < 3; k++) {
            write_float(rdram, vec + 4 * k, pos[k]);
        }
        ctx->r29 = (int32_t)(vec - 0x40);
        ctx->r4 = id;
        ctx->r5 = (int32_t)vec;
        ctx->r6 = (int32_t)yaw;
        func_80108474(rdram, ctx);
        const uint32_t object = (uint32_t)ctx->r2;
        *ctx = saved;
        return object;
    }

    void remove_statues(uint8_t* rdram, recomp_context* ctx) {
        for (Entry& e : menu.entries) {
            if (const uint32_t object = find_object(rdram, e.marker); object != 0) {
                call(rdram, ctx, func_800FFAB0, object);
            }
            e.marker = 0;
        }
    }

    // Each frame: the statues stay on their spots, the picked one larger and turning, the others faded back.
    void pose_statues(uint8_t* rdram) {
        const float t = (float)ms_since_start() / 1000.0f;
        for (size_t i = 0; i < menu.entries.size(); i++) {
            Entry& e = menu.entries[i];
            const uint32_t object = find_object(rdram, e.marker);
            if (object == 0) {
                continue;
            }
            const bool picked = i == menu.picked;
            for (int k = 0; k < 3; k++) {
                write_float(rdram, object + object_pos + 4 * k, e.pos[k]);
            }
            const float yaw = picked ? std::fmod(e.yaw + t * spin_degrees_per_second, 360.0f) : e.yaw;
            write_float(rdram, object + object_yaw, yaw);
            write_float(rdram, object + object_scale, forms[e.form].scale * (picked ? picked_grow : 1.0f));
            MEM_B(object_alpha, (gpr)(int32_t)object) = (int8_t)(picked ? 255 : faded_alpha());
        }
    }

    void open(uint8_t* rdram, recomp_context* ctx) {
        menu.entries.clear();
        menu.current = player_form(rdram);
        const uint32_t player = read_word(rdram, player_table);
        const uint32_t pos_ptr = read_word(rdram, player + player_pos_ptr);
        const uint32_t yaw_ptr = read_word(rdram, player + player_yaw_ptr);
        if (!tooie::rdram::valid_ptr(pos_ptr) || !tooie::rdram::valid_ptr(yaw_ptr)) {
            return;
        }
        float banjo[3];
        for (int k = 0; k < 3; k++) {
            banjo[k] = tooie::rdram::read_float(rdram, pos_ptr + 4 * k);
        }
        const float facing = tooie::rdram::read_float(rdram, yaw_ptr);

        std::vector<size_t> shown;
        for (size_t i = 0; i < form_count; i++) {
            if (unlocked(rdram, ctx, forms[i])) {
                shown.push_back(i);
            }
        }
        // Spread along the arc, wider (further out) when there are many, so they keep min_gap apart.
        const size_t n = shown.size();
        const float span = 2.0f * arc_half_degrees * 3.14159265f / 180.0f;
        const float radius = n > 1 ? std::max(arc_radius, min_gap * (float)(n - 1) / span) : arc_radius;
        for (size_t i = 0; i < n; i++) {
            const float offset = n > 1 ? arc_half_degrees * (2.0f * (float)i / (float)(n - 1) - 1.0f) : 0.0f;
            // Left to right as seen from behind Banjo: the game's yaw turns anticlockwise seen from above.
            const float a = (facing - offset) * 3.14159265f / 180.0f;
            Entry e;
            e.form = shown[i];
            e.pos[0] = banjo[0] + std::sin(a) * radius;
            e.pos[1] = banjo[1];
            e.pos[2] = banjo[2] + std::cos(a) * radius;
            // Facing back at Banjo (and the camera behind him).
            e.yaw = std::fmod(std::atan2(banjo[0] - e.pos[0], banjo[2] - e.pos[2]) * 180.0f / 3.14159265f + 360.0f, 360.0f);
            const uint32_t object = spawn(rdram, ctx, statue_actor, e.pos, e.yaw);
            if (tooie::rdram::valid_ptr(object)) {
                e.marker = read_word(rdram, object);
                if (forms[e.form].model != 0 && tooie::rdram::valid_ptr(e.marker)) {
                    tooie::rdram::write_half(rdram, e.marker + marker_model, forms[e.form].model);
                }
            }
            menu.entries.push_back(e);
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
        pose_statues(rdram);
        if (log_on()) {
            std::fprintf(stderr, "[transform-menu] opened at %.0f %.0f %.0f facing %.0f: form 0x%X, %zu forms:", banjo[0],
                banjo[1], banjo[2], facing, menu.current, menu.entries.size());
            for (const Entry& e : menu.entries) {
                std::fprintf(stderr, " %s(%s)", forms[e.form].name, e.marker != 0 ? "spawned" : "FAILED");
            }
            std::fprintf(stderr, "\n");
        }
    }

    void close(uint8_t* rdram, recomp_context* ctx, const char* why) {
        if (!menu.open) {
            return;
        }
        remove_statues(rdram, ctx);
        menu.open = false;
        open_flag = false;
        if (log_on()) {
            std::fprintf(stderr, "[transform-menu] closed: %s\n", why);
        }
    }

    // Moves the pick along the arc: right or down is the next form, left or up the one before. Stops at the ends.
    void move_pick(int dx, int dy) {
        const int step = dx != 0 ? dx : dy;
        const int to = (int)menu.picked + step;
        if (to >= 0 && to < (int)menu.entries.size()) {
            menu.picked = (size_t)to;
        }
    }

    std::atomic<int> env_state{0};   // 0 not read, 1 waiting, 2 done or none
    // The console's transformmenu: 1 open, 2 close, taken on the next tick.
    std::atomic<int> console_request{0};

    bool env_open() {
        static int64_t at = -1;
        if (env_state.load() == 0) {
            env_state = 2;
            if (const char* v = std::getenv("TOOIE_TRANSFORM_MENU_OPEN")) {
                at = std::strtoll(v, nullptr, 10);
                env_state = 1;
            }
        }
        // Waits until the menu can open (headless the area can take minutes to load).
        return env_state.load() == 1 && ms_since_start() >= at;
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

}

bool tooie::transform_menu::enabled() {
    static const bool forced = std::getenv("TOOIE_TRANSFORM_MENU") != nullptr;
    if (forced) {
        return true;
    }
    try {
        return std::get<bool>(recompui::config::get_graphics_config().get_option_value(option));
    } catch (...) {
        return false;
    }
}

bool tooie::transform_menu::is_open() {
    return open_flag.load();
}

void tooie::transform_menu::request(bool open_it) {
    console_request = open_it ? 1 : 2;
}

void tooie::transform_menu::tick(uint8_t* rdram, recomp_context* ctx) {
    const bool held = tooie::hotkeys::down(recompinput::GameInput::TRANSFORM);
    const bool key_pressed = held && !menu.key_was_held;
    menu.key_was_held = held;
    // A console open waits until the menu can open; a close, or an open while it is up, is done at once.
    const int asked = console_request.load();
    const bool env_pressed = env_open() || asked == 1;

    if (!enabled()) {
        close(rdram, ctx, "option off");
        return;
    }
    if (!menu.open) {
        if (asked == 2) {
            console_request = 0;
        }
        if ((key_pressed || env_pressed) && can_open(rdram)) {
            env_state = 2;
            console_request = 0;
            open(rdram, ctx);
        }
        return;
    }
    if (!can_open(rdram)) {
        if (tooie::debug::map_change_busy(rdram)) {
            for (Entry& e : menu.entries) {
                e.marker = 0;   // the map change removes them
            }
        }
        close(rdram, ctx, "the game moved on (pause, map change, cutscene or talk)");
        return;
    }
    if (asked != 0) {
        console_request = 0;
        if (asked == 2) {
            close(rdram, ctx, "console");
            return;
        }
    }
    // The game stands still behind the menu.
    write_float(rdram, delta_time_addr, frozen_delta);
    pose_statues(rdram);

    // The Transform key shuts it again, once it has been up a moment.
    if (key_pressed && Clock::now() - menu.opened_at > std::chrono::milliseconds(200)) {
        close(rdram, ctx, "Transform key");
        return;
    }
    std::deque<int> list;
    {
        std::lock_guard lock{ events.mutex };
        list.swap(events.list);
    }
    for (int e : list) {
        if (e == 'B' || e == 'S') {
            close(rdram, ctx, e == 'B' ? "B" : "Start");
            return;
        }
        if (e == 'A') {
            const Form& f = forms[menu.entries[menu.picked].form];
            if (f.id == player_form(rdram)) {
                close(rdram, ctx, "A on the form Banjo already has");
                return;
            }
            const bool asked = tooie::transform_picker::request_form(f.id);
            if (log_on()) {
                std::fprintf(stderr, "[transform-menu] A: %s (0x%X) %s\n", f.name, f.id, asked ? "asked for" : "not taken");
            }
            close(rdram, ctx, "A");
            return;
        }
        if (e >= 0 && e <= 8 && e != 4) {
            move_pick(e % 3 - 1, e / 3 - 1);
            pose_statues(rdram);
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
