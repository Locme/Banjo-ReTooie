// Transform Anywhere Menu (L, 2026-11-03): WIP tab > Transform Anywhere Menu, off by default. A separate toggle from
// Transform Anywhere (transform_anywhere.cpp), which keeps working as before while this one is off.
//
// While it is on, the Transform key (Controls tab, Movement; T, and LT + Y on a controller) opens a menu instead of
// changing into the world's Humba form. The game stands still (the frame's delta time is set to almost nothing,
// as the Pause Special Menu does) and the forms Banjo has been stand round him as their real 3D models, small, in a
// ring in the middle of the screen, after the picture L sent (2026-11-04): they stand a short way in front of the
// camera, square to the view, and the camera is kept where it was (free_camera.cpp's hook after the camera's update
// calls place_camera, as for photo mode), so the ring does not depend on where Banjo is. The scene darkens towards the edges of the
// screen in a soft round fade, and a bar along the bottom reads [d-pad] SELECT, [A] TRANSFORM, [B] BACK with plain
// grey buttons. The stick or the d-pad points at a form to pick it (up is the one ahead of Banjo); the picked one is
// larger and spins slowly. Each model stands in its form's idle pose (the animation moved on by the clock, as the
// game stands still), facing the camera and leaning back as far as the camera looks down.
//
// The models: each is a Golden Goliath statue (actor 0x163, a still model) spawned with the game's own
// func_80108474 and given the form's model (its id struct +0x14). They are removed with func_800FFAB0 when the
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
// prints). The fade and the buttons are small textures this file makes in spare RDRAM, drawn as texture rectangles
// straight into the display list (as hd_shadows.cpp writes its commands).
//
// Headless: TOOIE_TRANSFORM_MENU=1 turns it on whatever the setting says, TOOIE_TRANSFORM_MENU_OPEN=<ms> opens it
// that long after the game loop first runs, TOOIE_TRANSFORM_MENU_ALL=1 shows every form whether unlocked or not,
// TOOIE_TRANSFORM_MENU_ALPHA=<0-255> sets the other models' alpha (255, not faded, by default),
// TOOIE_TRANSFORM_MENU_DRAW=fade|icons|probe draws only the fade, only the bar, or three dots at the screen's
// corner and middle (to measure where rectangles land), TOOIE_TRANSFORM_MENU_LOG=1 logs
// [transform-menu] lines. It does not open while a wipe is still drawing (tooie::wipe_showing), which the frozen game
// would hold over the screen.

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
#include "tooie_free_camera.h"
#include "tooie_hotkeys.h"
#include "tooie_mirror_mode.h"
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

    // Strings and sprite coordinates go in extended RDRAM no one else uses: the pause menu's SETTINGS rows end
    // before 0x80EF1400 and Snout jiggle's copies start at 0x80EF8000.
    constexpr uint32_t string_area = 0x80EF4000;
    constexpr uint32_t string_area_size = 0x800;
    constexpr uint32_t coords_addr = string_area + string_area_size - 8;   // Coords2D, in quarter pixels

    // The textures this file draws (I8, the intensity also its alpha): the fade (64 x 64, stretched over the screen),
    // then a filled circle and a d-pad cross (16 x 16 each), after the strings.
    constexpr uint32_t fade_texture = 0x80EF5000;
    constexpr int fade_size = 64;
    constexpr uint32_t circle_texture = fade_texture + fade_size * fade_size;
    constexpr uint32_t dpad_texture = circle_texture + 16 * 16;
    constexpr int icon_size = 16;
    // The fade: clear within this many pixels of the middle of the 320 x 240 screen, darkest from this far out.
    constexpr float fade_clear = 60.0f;
    constexpr float fade_full = 175.0f;
    constexpr uint8_t fade_alpha = 215;
    constexpr uint32_t button_grey = 0xB4B4B4FFu;
    // Texture rectangles come out this much lower than the 320 x 240 screen the text is placed on, measured from its top
    // (dots drawn at y 0 and 112 landed at 0 and 119.6, 2026-11-04, and the buttons sat 11 below their labels at the
    // bar), so their y is divided by it. Across they land where the text does.
    constexpr float rect_scale = 1.0475f;

    // Where things go on the game's 320 x 240 2D screen.
    constexpr int centre_x = 160;

    // The 3D line-up: a ring this far in front of the camera, square to the view so it sits in the middle of the
    // screen, of this radius, the models at this share of their size (L, 2026-11-04: in the middle of the screen
    // always, not round Banjo, and using the screen's height).
    constexpr float ring_depth = 320.0f;
    constexpr float ring_radius = 78.0f;
    constexpr float model_scale = 0.17f;
    // The ring's middle sits this far up the screen from its middle, to leave room for the bar along the bottom.
    constexpr float ring_raise = 8.0f;
    constexpr float picked_grow = 1.4f;
    constexpr float spin_degrees_per_second = 40.0f;
    constexpr uint8_t default_faded_alpha = 255;
    // The viewport camera (camera controller +0x00, src/gameplay/free_camera.cpp): its position at +0x00 and pitch, yaw
    // and roll in degrees at +0x18. The menu keeps it where it was when the menu opened (written back after the
    // camera's own update each frame), whatever kind of camera the map runs.
    constexpr uint32_t cam_pos = 0x00;
    constexpr uint32_t cam_rot = 0x18;

    constexpr uint16_t statue_actor = 0x163;          // the Golden Goliath statue: a still model
    constexpr uint32_t object_array_pointer = 0x80136EE0;
    constexpr uint32_t object_first = 0x04;
    constexpr uint32_t object_last = 0x08;
    constexpr uint32_t object_base = 0x10;
    constexpr uint32_t object_size = 0x9C;
    constexpr uint32_t object_pos = 0x04;
    constexpr uint32_t object_scale = 0x38;
    constexpr uint32_t object_pitch = 0x44;
    constexpr uint32_t object_yaw = 0x48;
    constexpr uint32_t object_alpha = 0x9B;
    constexpr uint32_t marker_model = 0x14;
    constexpr int max_objects = 2048;
    constexpr uint32_t player_pos_ptr = 0xE4;
    constexpr uint32_t player_yaw_ptr = 0xF8;
    constexpr int bar_y = 214;
    constexpr float text_scale = 0.5f;

    // A form: the game's id for it (as the player's +0xA0 block +0x29 holds it), its model, its size in the menu, the
    // flags any of which unlocks it (none: always), and its idle animation and that animation's length (what the
    // console's anim command reads with Banjo standing still in the form, 2026-11-04).
    struct Form {
        uint8_t id;
        const char* name;
        uint16_t model;
        float scale;
        int32_t flags[3];
        uint16_t idle;
        float idle_seconds;
    };
    // Left to right along the arc.
    const Form forms[] = {
        { 0x01, "BANJO-KAZOOIE", 0x61F, 1.0f, { -1, -1, -1 }, 0x6F, 5.5f },
        { 0x0A, "BANJO", 0x62A, 1.0f, { 0x4F5, -1, -1 }, 0x6F, 5.5f },
        { 0x0B, "KAZOOIE", 0x61C, 1.0f, { 0x4F5, -1, -1 }, 0xA4, 6.5f },
        { 0x08, "STONY", 0x61D, 1.0f, { 0x346, -1, -1 }, 0x63, 6.1f },
        { 0x0F, "DETONATOR", 0x623, 1.0f, { 0x347, -1, -1 }, 0xE5, 6.5f },
        { 0x10, "VAN", 0x624, 0.8f, { 0x348, -1, -1 }, 0xEE, 1.0f },
        { 0x0C, "SUBMARINE", 0x626, 0.8f, { 0x349, -1, -1 }, 0x12E, 6.0f },
        { 0x12, "BABY T-REX", 0x609, 1.0f, { 0x34A, -1, -1 }, 0x1D2, 8.5f },
        { 0x13, "DADDY T-REX", 0x60D, 0.3f, { 0x345, -1, -1 }, 0x1D2, 8.5f },
        { 0x07, "WASHING MACHINE", 0x60C, 1.0f, { 0x34B, -1, -1 }, 0x356, 3.9f },
        { 0x02, "SNOWBALL", 0x60B, 0.6f, { 0x34C, -1, -1 }, 0x5E, 1.2f },
        { 0x06, "BEE", 0x613, 1.0f, { 0x34D, -1, -1 }, 0x1DE, 3.0f },
    };
    constexpr size_t form_count = sizeof(forms) / sizeof(forms[0]);

    struct Entry {
        size_t form;          // index into forms
        float pos[3];         // where its statue stands
        float yaw;            // facing the camera
        float screen_angle;   // where it is round Banjo on screen, degrees clockwise from straight up
        uint32_t marker = 0;  // the statue's id struct (object +0), 0 if it did not spawn
    };

    struct Menu {
        bool open = false;
        std::vector<Entry> entries;
        size_t picked = 0;
        uint8_t current = 0;      // the player's form when it opened
        bool key_was_held = false;
        Clock::time_point opened_at{};
        // The camera held over Banjo.
        bool has_view = false;
        float camera_pos[3] = {};
        float camera_rot[3] = {};
        // How far the models lean back to face the camera (its pitch down).
        float lean = 0.0f;
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

    // Whether it may open now: as can_open, and no wipe still drawing (the frozen game would hold a map change's
    // jigsaw wipe half over the screen, 2026-11-04).
    bool can_open_now(uint8_t* rdram) {
        return can_open(rdram) && !tooie::wipe_showing();
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
    void pose_statues(uint8_t* rdram, recomp_context* ctx) {
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
            write_float(rdram, object + object_pitch, menu.lean);
            write_float(rdram, object + object_scale, forms[e.form].scale * model_scale * (picked ? picked_grow : 1.0f));
            MEM_B(object_alpha, (gpr)(int32_t)object) = (int8_t)(picked ? 255 : faded_alpha());
            // The game stands still behind the menu, so its animations do not move on: the idle animation's place
            // (anctrl +0x1C +0x10, 0 to 1, as anctrl_getAnimTimer reads it) is set from the clock instead.
            const uint32_t ctrl = call(rdram, ctx, func_80104248, object);
            if (tooie::rdram::valid_ptr(ctrl) && forms[e.form].idle_seconds > 0.0f) {
                write_float(rdram, ctrl + 0x2C, std::fmod(t / forms[e.form].idle_seconds, 1.0f));
            }
        }
    }

    // Puts a statue in its form's idle pose, straight on its animation controller, as func_80101BE0 does when an
    // actor changes state: the controller (func_80104248, made by func_801042B8 if it has none), the animation
    // (anctrl_setIndex), its length (anctrl_setDuration), func_8008B188 and anctrl_start. The statue's own state is left alone:
    // setting it through func_80101FDC made the statue run Mumbo's transformation effects, which crashed (2026-11-04).
    void pose_idle(uint8_t* rdram, recomp_context* ctx, uint32_t object, const Form& f) {
        uint32_t ctrl = call(rdram, ctx, func_80104248, object);
        if (!tooie::rdram::valid_ptr(ctrl)) {
            ctrl = call(rdram, ctx, func_801042B8, object);
            if (!tooie::rdram::valid_ptr(ctrl)) {
                return;
            }
            call(rdram, ctx, anctrl_reset, ctrl);
        }
        if (call(rdram, ctx, anctrl_getPlaybackType, ctrl) == 3) {
            call(rdram, ctx, anctrl_setPlaybackType, ctrl, 2);
        }
        uint32_t seconds;
        std::memcpy(&seconds, &f.idle_seconds, sizeof(seconds));
        call(rdram, ctx, anctrl_setIndex, ctrl, f.idle);
        call(rdram, ctx, anctrl_setDuration, ctrl, seconds);
        call(rdram, ctx, func_8008B188, ctrl, 1);
        // And starts it, as func_80101FDC does after the state change.
        call(rdram, ctx, anctrl_start, ctrl);
    }

    // The fade (dark towards the screen's edges, as a round vignette) and the two button shapes, as I8 textures.
    void make_textures(uint8_t* rdram) {
        static bool made = false;
        if (made) {
            return;
        }
        made = true;
        for (int v = 0; v < fade_size; v++) {
            for (int u = 0; u < fade_size; u++) {
                // In screen pixels from the middle: the texture is stretched over 320 x 240.
                const float dx = ((float)u + 0.5f - fade_size / 2.0f) * (320.0f / fade_size);
                const float dy = ((float)v + 0.5f - fade_size / 2.0f) * (240.0f / fade_size);
                const float t = std::clamp((std::sqrt(dx * dx + dy * dy) - fade_clear) / (fade_full - fade_clear), 0.0f, 1.0f);
                const float smooth = t * t * (3.0f - 2.0f * t);
                MEM_B(v * fade_size + u, (gpr)(int32_t)fade_texture) = (int8_t)(uint8_t)std::lround(smooth * 255.0f);
            }
        }
        for (int v = 0; v < icon_size; v++) {
            for (int u = 0; u < icon_size; u++) {
                const float dx = (float)u + 0.5f - icon_size / 2.0f;
                const float dy = (float)v + 0.5f - icon_size / 2.0f;
                // A filled circle, its edge softened over a pixel.
                const float edge = std::clamp(7.5f - std::sqrt(dx * dx + dy * dy), 0.0f, 1.0f);
                MEM_B(v * icon_size + u, (gpr)(int32_t)circle_texture) = (int8_t)(uint8_t)std::lround(edge * 255.0f);
                // A plus with arms five pixels wide.
                const bool arm = (std::fabs(dx) < 2.6f && std::fabs(dy) < 7.6f) || (std::fabs(dy) < 2.6f && std::fabs(dx) < 7.6f);
                MEM_B(v * icon_size + u, (gpr)(int32_t)dpad_texture) = (int8_t)(arm ? 255 : 0);
            }
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
        // The camera as it is now, kept there while the menu is up.
        const uint32_t ctl = tooie::free_camera::last_controller();
        const uint32_t camera = tooie::rdram::valid_ptr(ctl) ? read_word(rdram, ctl) : 0;
        if (!tooie::rdram::valid_ptr(camera)) {
            return;
        }
        for (int k = 0; k < 3; k++) {
            menu.camera_pos[k] = tooie::rdram::read_float(rdram, camera + cam_pos + 4 * k);
            menu.camera_rot[k] = tooie::rdram::read_float(rdram, camera + cam_rot + 4 * k);
        }
        menu.has_view = true;
        // The view's axes: yaw 0 looks along -z and grows turning left, a positive pitch looks up.
        const float pitch = (menu.camera_rot[0] > 180.0f ? menu.camera_rot[0] - 360.0f : menu.camera_rot[0]) * 3.14159265f / 180.0f;
        const float yaw = menu.camera_rot[1] * 3.14159265f / 180.0f;
        const float forward[3] = { -std::sin(yaw) * std::cos(pitch), std::sin(pitch), -std::cos(yaw) * std::cos(pitch) };
        const bool mirrored = tooie::mirror_mode::active();
        // Right on screen (left in the world with Mirror Mode, which flips the picture) and up on screen.
        const float side = mirrored ? -1.0f : 1.0f;
        const float right[3] = { std::cos(yaw) * side, 0.0f, -std::sin(yaw) * side };
        const float up[3] = { std::sin(yaw) * std::sin(pitch), std::cos(pitch), std::cos(yaw) * std::sin(pitch) };
        float centre[3];
        for (int k = 0; k < 3; k++) {
            centre[k] = menu.camera_pos[k] + forward[k] * ring_depth;
        }
        for (int k = 0; k < 3; k++) {
            centre[k] += up[k] * ring_raise;
        }
        // The object's pitch tips a model forward when positive (a camera looking down saw more of their tops with
        // it), so they lean back with a negative one.
        menu.lean = -std::clamp(-pitch * 180.0f / 3.14159265f, 0.0f, 80.0f);

        // Evenly round the ring, the first at the top of the screen and on clockwise.
        const size_t n = shown.size();
        for (size_t i = 0; i < n; i++) {
            const float screen_angle = 360.0f * (float)i / (float)std::max<size_t>(n, 1);
            const float a = screen_angle * 3.14159265f / 180.0f;
            Entry e;
            e.form = shown[i];
            e.screen_angle = screen_angle;
            for (int k = 0; k < 3; k++) {
                e.pos[k] = centre[k] + (up[k] * std::cos(a) + right[k] * std::sin(a)) * ring_radius;
            }
            // Facing the camera (a model's yaw faces the way the camera's yaw comes from).
            e.yaw = menu.camera_rot[1];
            const uint32_t object = spawn(rdram, ctx, statue_actor, e.pos, e.yaw);
            if (tooie::rdram::valid_ptr(object)) {
                e.marker = read_word(rdram, object);
                if (forms[e.form].model != 0 && tooie::rdram::valid_ptr(e.marker)) {
                    tooie::rdram::write_half(rdram, e.marker + marker_model, forms[e.form].model);
                }
                pose_idle(rdram, ctx, object, forms[e.form]);
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
        make_textures(rdram);
        menu.open = true;
        menu.opened_at = Clock::now();
        open_flag = true;
        pose_statues(rdram, ctx);
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
        menu.has_view = false;
        menu.open = false;
        open_flag = false;
        if (log_on()) {
            std::fprintf(stderr, "[transform-menu] closed: %s\n", why);
        }
    }

    // Picks the form round the ring nearest the way the stick or the d-pad points (dy -1 is up the screen).
    void move_pick(int dx, int dy) {
        const float want = std::atan2((float)dx, (float)-dy) * 180.0f / 3.14159265f;
        float best = 1000.0f;
        for (size_t i = 0; i < menu.entries.size(); i++) {
            const float d = std::fabs(std::fmod(menu.entries[i].screen_angle - want + 540.0f, 360.0f) - 180.0f);
            if (d < best) {
                best = d;
                menu.picked = i;
            }
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

    void push(uint8_t* rdram, uint32_t gfx, uint32_t w0, uint32_t w1) {
        const uint32_t cmd = read_word(rdram, gfx);
        write_word(rdram, cmd, w0);
        write_word(rdram, cmd + 4, w1);
        write_word(rdram, gfx, cmd + 8);
    }

    // Draws one of this file's I8 textures (size x size texels) over x, y, w, h on the 320 x 240 screen, in the colour
    // rgba (its alpha times the texel's intensity), blended over what is there.
    void draw_shape(uint8_t* rdram, uint32_t gfx, uint32_t texture, int size, int x, int y, int w, int h, uint32_t alpha,
                    uint32_t rgba = 0x000000FFu) {
        const uint32_t texels = (uint32_t)(size * size);
        const uint32_t line = (uint32_t)(size + 7) / 8;
        const uint32_t dxt = (2048u + line - 1) / line;
        push(rdram, gfx, 0xE7000000, 0);                               // pipe sync
        push(rdram, gfx, 0xE3000A01, 0x00000000);                      // one cycle
        push(rdram, gfx, 0xE3000C00, 0x00000000);                      // no perspective
        push(rdram, gfx, 0xE3001201, 0x00002000);                      // bilinear filter
        push(rdram, gfx, 0xE3001001, 0x00000000);                      // no palette
        push(rdram, gfx, 0xE3001402, 0x00000C00);                      // texture convert: filter
        push(rdram, gfx, 0xE2001E01, 0x00000000);                      // no alpha compare
        push(rdram, gfx, 0xE200001C, 0x00504240);                      // G_RM_XLU_SURF, G_RM_XLU_SURF2
        // Colour: the primitive colour; alpha: the texel times the primitive alpha (both cycles).
        push(rdram, gfx, 0xFCFF97FF, 0xFF2DFEFF);
        push(rdram, gfx, 0xFA000000, (rgba & 0xFFFFFF00u) | (alpha & 0xFF));
        // Load the texture as 16-bit words (a block load), then set it up as I8 in tile 0, clamped.
        push(rdram, gfx, 0xFD900000, texture - 0x80000000u);
        push(rdram, gfx, 0xF5900000, 0x07000000);
        push(rdram, gfx, 0xE6000000, 0);
        push(rdram, gfx, 0xF3000000, 0x07000000 | (((texels + 1) / 2 - 1) << 12) | dxt);
        push(rdram, gfx, 0xE7000000, 0);
        push(rdram, gfx, 0xF5880000 | (line << 9), 0x00080200);
        push(rdram, gfx, 0xF2000000, (uint32_t)(((size - 1) << 2) << 12) | (uint32_t)((size - 1) << 2));
        // The rectangle, in quarter pixels, with the texture stepped to fill it (s and t steps in 5.10), scaled to land
        // where the text's coordinates put it.
        const uint32_t x0 = (uint32_t)(x * 4), y0 = (uint32_t)std::lround(y * 4 / rect_scale);
        const uint32_t x1 = (uint32_t)((x + w) * 4), y1 = (uint32_t)std::lround((y + h) * 4 / rect_scale);
        const uint32_t dsdx = (uint32_t)std::lround((double)size * 4.0 / (double)(x1 - x0) * 1024.0);
        const uint32_t dtdy = (uint32_t)std::lround((double)size * 4.0 / (double)(y1 - y0) * 1024.0);
        push(rdram, gfx, 0xE4000000 | (x1 << 12) | y1, (x0 << 12) | y0);
        push(rdram, gfx, 0xE1000000, 0);
        push(rdram, gfx, 0xF1000000, (dsdx << 16) | dtdy);
        push(rdram, gfx, 0xE7000000, 0);
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

bool tooie::transform_menu::place_camera(uint8_t* rdram, uint32_t camera) {
    if (!open_flag.load() || !menu.has_view || !tooie::rdram::valid_ptr(camera)) {
        return false;
    }
    for (int k = 0; k < 3; k++) {
        write_float(rdram, camera + cam_pos + 4 * k, menu.camera_pos[k]);
    }
    for (int k = 0; k < 3; k++) {
        write_float(rdram, camera + cam_rot + 4 * k, menu.camera_rot[k]);
    }
    return true;
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
        if ((key_pressed || env_pressed) && can_open_now(rdram)) {
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
    pose_statues(rdram, ctx);

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
            pose_statues(rdram, ctx);
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
    uint32_t offset = 0;

    // TOOIE_TRANSFORM_MENU_DRAW=fade or icons draws only that part, to test them apart.
    static const std::string only = [] { const char* v = std::getenv("TOOIE_TRANSFORM_MENU_DRAW"); return std::string(v != nullptr ? v : ""); }();
    // The fade over the whole 320 x 240 screen, black with the texture's darkness as its alpha.
    if (only != "icons") {
        draw_shape(rdram, gfx, fade_texture, fade_size, 0, 0, 320, 240, fade_alpha);
    }
    if (only == "fade") {
        return;
    }
    if (only == "probe") {
        // Two dots at the corners of the 320 x 240 screen, to see where rectangles land.
        draw_shape(rdram, gfx, circle_texture, icon_size, 0, 0, icon_size, icon_size, 0xFF, 0xFF0000FFu);
        draw_shape(rdram, gfx, circle_texture, icon_size, 320 - icon_size, 240 - icon_size, icon_size, icon_size, 0xFF, 0x00FF00FFu);
        draw_shape(rdram, gfx, circle_texture, icon_size, 160 - icon_size / 2, 120 - icon_size / 2, icon_size, icon_size, 0xFF, 0x0000FFFFu);
        return;
    }

    // The bar along the bottom: [d-pad] SELECT  [A] TRANSFORM  [B] BACK, centred as a whole, as in L's picture.
    constexpr int gap = 4;
    constexpr int spacing = 18;
    const char* labels[3] = { "SELECT", "TRANSFORM", "BACK" };
    int widths[3];
    int total = 0;
    for (int i = 0; i < 3; i++) {
        widths[i] = text_width(rdram, ctx, offset, text_scale, labels[i]);
        total += icon_size + gap + widths[i];
    }
    total += spacing * 2;
    int x = centre_x - total / 2;
    const int icon_y = bar_y - 1 - icon_size / 2;
    for (int i = 0; i < 3; i++) {
        draw_shape(rdram, gfx, i == 0 ? dpad_texture : circle_texture, icon_size, x, icon_y, icon_size, icon_size,
                   button_grey & 0xFF, button_grey);
        if (i != 0) {
            print(rdram, ctx, gfx, offset, colour_white, 0.42f, x + icon_size / 2, bar_y - 4, i == 1 ? "A" : "B", 1);
        }
        print(rdram, ctx, gfx, offset, colour_white, text_scale, x + icon_size + gap, bar_y - 5, labels[i]);
        x += icon_size + gap + widths[i] + spacing;
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
