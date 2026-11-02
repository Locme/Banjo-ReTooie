// Photo mode (handoff 4.82).
//
// Freeze: func_800D8FA0 turns the VIs the last frame took into the frame's delta time, kept as a
// float at 0x8012C760 (func_800D8FF8 returns it). tooie_warp_tick runs at the start of the game's
// frame update (func_800A7D84), after that, so photo mode scales the value there: almost nothing
// while frozen, 1/167, 1/8 or 1/4 of it in slow time. Everything the game moves by delta time stands
// still, and the world is still drawn every frame, so the camera can move. (Things the game moves
// by a fixed step per frame can keep moving.)
//
// Camera: func_8010FC38 steps each viewport's camera controller; the free camera's hook in it
// (tooie_free_camera) calls place_camera, which writes the viewport camera's position (+0x00) and
// pitch / yaw / roll (+0x18, +0x1C, +0x20, degrees) after the game's camera has updated. Facing: yaw 0 looks
// along -z, the yaw grows turning left, and a positive pitch looks up.
//
// Input: while photo mode is on, player 1's pad goes to the camera and the game reads an idle pad.
//   left stick      move (forward, back, sideways)
//   right stick     look (C-buttons on the keyboard)
//   Z / R           down / up
//   (holding a move for a second speeds it up)
//   A               screenshot (as F12), after the self-timer if one is set
//   D-pad up/down   pick a row of the photo panel (src/ui/photo_panel.cpp)
//   D-pad left/right change it (held repeats): zoom (the field of view, through tooie_set_fov), camera
//                   (free, or orbit Banjo: the sticks circle him, Z / R move closer and further), collision on or off, time,
//                   HUD, Banjo shown or hidden, his pose and the point in it, the others shown or hidden, the filter rows below, depth of field, tilt, crop, grid
//   L               show / hide the photo panel
//   Start           frozen, 1/167 speed, 1/8 speed, 1/4 speed
//   B / Photo Mode  back to the game, with the camera and HUD as they were
//
// Shutter (QOL > Photo shutter, on by default): each photo plays a camera click (synthesised, mixed into
// the game's sound by mix_shutter from main.cpp) and the photo panel flashes the screen white; the flash
// is a UI layer, so the photo itself never shows it. The Timer row (Off, 3 s, 10 s) counts down with
// toasts before the photo; A again cancels it.
//
// Others (hidden: enemies, NPCs, items, doors and other moving parts): banjotooie.us.toml hooks func_800EC7D4, the draw of
// each actor in an object pass's list, to skip it while tooie_others_hidden().
//
// Poses: the Pose row swaps Banjo's animation (his anim controller from baanim_getAnimCtrlPtr, set up as the
// game's own state inits do) and the Pose frame row holds it at a point (the animation's timer, anctrl +0x2C)
// while time is frozen. His own animation is put back on leaving or on picking "Game".
//
// Hide Banjo: func_800F5008 draws the players each frame (opaque ones at once, faded ones listed for
// func_800F50D0 to draw later); banjotooie.us.toml hooks both to skip them while tooie_players_hidden().
//
// Border (QOL > Photo border): a frame drawn by the same pass over the edge of the crop frame and kept in
// screenshots: instant photo, film strip, honeycomb, Jiggy (gold puzzle knobs) or wooden (the menus' look).
//
// Filters (QOL > Photo filter rows): a look, exposure, contrast, saturation, warmth, vignette and grain,
// drawn by RT64's photo grade pass (lib-patches/rt64.patch) only while photo mode is on, so screenshots
// show them. They can be changed from the photo panel or the menu while photo mode is on, as can
// QOL > Photo tilt (the camera's roll); the panel writes the same options, so both stay in step.
//
// Collision (the photo panel's Collision row, on by default): each move is swept with the game's
// camera line test (tooie::free_camera::sweep_line); a hit stops the camera at the surface and the
// rest of the move slides along it. In orbit the line from Banjo to the camera pulls it in instead.
//
// Headless test hook: TOOIE_PHOTO=<on ms>:<off ms> enters and leaves photo mode at those times after
// the game loop first runs. TOOIE_PHOTO_LOG=1 logs the photo camera.

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
#include <variant>

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include "recomp.h"
#include "funcs.h"
#include "recompui/config.h"
#include "recompinput/recompinput.h"
#include "recompinput/input_binding.h"
#include "recompinput/input_state.h"
#include "recompinput/profiles.h"
#include "tooie_debug.h"
#include "tooie_free_camera.h"
#include "tooie_game.h"
#include "tooie_hide_hud.h"
#include "tooie_photo_mode.h"
#include "tooie_game_frame_rate.h"
#include "tooie_picture_filters.h"
#include "tooie_screenshot.h"
#include "tooie_toast.h"
#include "tooie_hotkeys.h"

namespace RT64 {
    // rt64-ext/src/render/rt64_photo_grade.h.
    void SetPhotoGrade(bool enabled, uint32_t look, float exposure, float contrast, float saturation, float warmth, float vignette, float grain);
    void SetPhotoFrame(float cropAspect, bool grid);
    void SetPhotoDepthOfField(float strength, uint32_t depthAddress);
    void SetPhotoFocus(float x, float y);
    void SetPhotoBorder(uint32_t border);
}

namespace {
    using namespace std::chrono_literals;
    using Clock = std::chrono::steady_clock;

    constexpr auto photo_input = recompinput::GameInput::PHOTO_MODE;
    constexpr auto poll_interval = 10ms;

    constexpr gpr game_state_addr = (int32_t)0x80127630;
    constexpr uint32_t game_state_playing = 3;
    constexpr gpr delta_time_addr = (int32_t)0x8012C760;

    constexpr uint32_t cam_pos = 0x00;
    constexpr uint32_t cam_rot = 0x18;

    constexpr uint16_t button_a = 0x8000, button_b = 0x4000, button_z = 0x2000, button_start = 0x1000;
    constexpr uint16_t d_up = 0x0800, d_down = 0x0400, d_left = 0x0200, d_right = 0x0100;
    constexpr uint16_t button_l = 0x0020, button_r = 0x0010;
    constexpr uint16_t c_up = 0x0008, c_down = 0x0004, c_left = 0x0002, c_right = 0x0001;

    // Units and degrees per second.
    constexpr float move_speed = 600.0f;
    constexpr float look_speed = 90.0f;
    constexpr float fast_factor = 3.0f;
    constexpr float stick_deadzone = 0.15f;
    constexpr float max_pitch = 89.0f;
    constexpr float deg = 3.14159265f / 180.0f;
    // The game's delta time while frozen: not zero, as some code divides by it, but small enough that
    // adding it to a timer changes nothing. (It was 0.0001 s, which at 60 FPS ran time at 0.0001 / (1/60)
    // = 0.006 of normal speed, about 1/167: still moving. That speed is kept as its own step, L, 2026-10-16.)
    constexpr float frozen_delta = 1.0e-7f;
    constexpr float speed_scales[] = { 0.0f, 0.006f, 0.125f, 0.25f };
    constexpr const char* speed_names[] = { "Time frozen", "Time 1/167", "Time 1/8", "Time 1/4" };
    constexpr const char* speed_values[] = { "Frozen", "1/167 speed", "1/8 speed", "1/4 speed" };
    constexpr int speed_count = (int)std::size(speed_scales);
    // Orbit: the point circled is Banjo's position plus this much, at these distances.
    constexpr uint32_t player_table = 0x80135490;
    constexpr uint32_t player_transform = 0xE4;
    constexpr float orbit_height = 60.0f;
    constexpr float min_orbit = 100.0f, max_orbit = 6000.0f;
    // Zoom: the field of view is multiplied by this, changed by this much per second.
    // How far the camera keeps off a surface it hit.
    constexpr float surface_gap = 2.0f;
    constexpr float min_fov_scale = 0.2f, max_fov_scale = 2.0f, fov_rate = 0.8f;

    std::once_flag started;

    // Requests from the key thread and the input path, carried out on the game thread.
    std::atomic<bool> toggle_requested{false};
    std::atomic<bool> leave_requested{false};
    std::atomic<bool> is_active{false};
    std::atomic<int> speed{0};
    std::atomic<bool> orbit_toggle{false};
    std::atomic<bool> players_toggle{false};
    std::atomic<bool> players_hidden{false};
    // Others row: every other actor (enemies, NPCs, items, doors and other moving parts) hidden.
    std::atomic<bool> others_hidden{false};
    std::atomic<float> fov_scale{1.0f};
    // The game's own delta time this frame, before photo mode scaled it (for the log).
    std::atomic<float> game_delta{0.0f};

    // The photo panel: its rows, the one picked, whether it is shown, and a change waiting for the game
    // thread (-1 or +1 on the picked row).
    enum class Row { Zoom, Camera, Collision, Time, Hud, Banjo, Pose, PoseFrame, Others, Timer, Shutter, Filter, Exposure, Contrast, Saturation, Warmth,
        Vignette, Grain, Focus, FocusPoint, Tilt, Crop, Border, Grid, Album, Count };
    constexpr int row_count = (int)Row::Count;
    std::atomic<int> picked{0};
    std::atomic<bool> panel_shown{true};
    std::atomic<int> pending_step{0};
    std::atomic<bool> orbit_on{false};
    // Depth of field's focus point: the middle, Banjo, or one of the rule-of-thirds points.
    enum class Focus { Middle, Banjo, TopLeft, TopRight, BottomLeft, BottomRight, Count };
    constexpr const char* focus_names[] = { "Middle", "Banjo", "Top left", "Top right", "Bottom left", "Bottom right" };
    std::atomic<int> focus_choice{0};
    // The field of view the game last set while photo mode was on (degrees, vertical), to find Banjo on screen.
    std::atomic<float> last_fov{45.0f};
    // Banjo's middle, above his feet.
    constexpr float banjo_middle = 45.0f;

    // Poses: Banjo's animation swapped for one of these and held at a point in it (Pose frame, 0 to 1).
    // "Game" leaves him as he was. Leaving photo mode puts his own animation back.
    struct PoseChoice {
        const char* name;
        uint32_t anim;
    };
    constexpr PoseChoice poses[] = {
        { "Game", 0 },
        // Picked from a headless sweep of animations 0x1-0x17E on Banjo (names describe the look).
        { "Walk", 0x3 },
        { "Run", 0xC },
        { "Jump", 0x17 },
        { "Big stride", 0x14A },
        { "Kick", 0xAB },
        { "Crouch", 0x2A },
        { "Lie down", 0x5A },
        { "Jiggy jig", 0x2E },
        { "Wings out", 0x14 },
        { "Wings spread", 0x9F },
        { "Fly", 0xFB },
        { "Kazooie up", 0x1B },
        { "Kazooie dash", 0x47 },
        { "Kazooie lunge", 0x166 },
        { "Talon trot", 0x3C },
    };
    constexpr int pose_count = (int)std::size(poses);
    std::atomic<int> pose_choice{0};
    std::atomic<int> pose_frame{0};          // in 5% steps, 0 to 20
    std::atomic<bool> pose_dirty{false};
    // Banjo's own animation, kept to put back.
    struct SavedAnim {
        bool saved = false;
        uint32_t ctrl = 0;
        uint32_t index = 0;
        uint32_t duration = 0;
        uint32_t playback = 0;
        uint32_t timer = 0;
    } saved_anim;
    constexpr uint32_t anctrl_duration = 0x0C;
    constexpr uint32_t anctrl_playback = 0x1A;     // byte
    constexpr uint32_t anctrl_timer = 0x1C + 0x10;  // the animation's place, 0 to 1
    constexpr uint32_t anctrl_index = 0x1C + 0x18;  // halfword
    // Headless: TOOIE_POSE_SWEEP=<hex>[-<hex>][,...] poses those animation ids in turn 12 s after photo mode
    // comes on, with a screenshot of each, logging "[pose] sweep 0x..". TOOIE_POSE_FRAME=<0-20> sets the pose
    // frame (default 10, the middle).
    struct PoseSweep {
        bool active = false;
        std::vector<uint32_t> ids;
        size_t next = 0;
        Clock::time_point at{};
        bool shot = false;
    } pose_sweep;
    uint32_t sweep_anim = 0;

    // Self-timer: the Timer row's choice, and the countdown (on the game thread) once A started it.
    constexpr int timer_seconds[] = { 0, 3, 10 };
    std::atomic<int> timer_choice{0};
    std::atomic<bool> timer_requested{false};
    // A on the Album row: the photo panel opens the menu's Album tab (on its own thread, which may touch the menus).
    std::atomic<bool> album_requested{false};
    bool timer_running = false;
    Clock::time_point timer_end{};
    int timer_shown = -1;
    // Shutter: photos taken (the sound mixer plays a click for each new one) and when the last one was.
    std::atomic<uint32_t> shots{0};
    std::atomic<int64_t> last_shot_ns{0};
    constexpr float flash_seconds = 0.35f;

    // Held left / right: the first change at once, then repeats.
    Clock::time_point step_held_since{};
    Clock::time_point step_last{};
    constexpr auto repeat_delay = 400ms;
    constexpr auto repeat_every = 70ms;

    // The pad as photo mode reads it (written by apply_input, read by place_camera).
    std::mutex pad_mutex;
    struct Pad {
        uint16_t buttons = 0;
        float x = 0.0f, y = 0.0f;
    } pad;
    uint16_t last_buttons = 0;

    // Game-thread state.
    struct Camera {
        bool placed = false;
        float pos[3] = { 0, 0, 0 };
        float yaw = 0.0f;
        float pitch = 0.0f;
        Clock::time_point last;
        Clock::time_point moving_since;
        bool moving = false;
        bool orbit = false;
        float pivot[3] = { 0, 0, 0 };
        float distance = 0.0f;
    } cam;
    bool hud_was_hidden = false;
    uint16_t entered_map = 0;

    struct TestHold {
        bool active = false;
        long on = 0, off = 0;
        bool did_on = false, did_off = false;
        Clock::time_point begin;
    } test;

    bool key_down() {
        return tooie::hotkeys::down(photo_input);
    }

    void worker() {
        bool was_down = false;
        for (;;) {
            std::this_thread::sleep_for(poll_interval);
            bool down = key_down();
            if (down && !was_down) {
                toggle_requested = true;
            }
            was_down = down;
        }
    }

    float read_float(uint8_t* rdram, uint32_t addr) {
        uint32_t u = (uint32_t)MEM_W(0, (gpr)(int32_t)addr);
        float f;
        std::memcpy(&f, &u, 4);
        return f;
    }

    void write_float(uint8_t* rdram, uint32_t addr, float f) {
        uint32_t u;
        std::memcpy(&u, &f, 4);
        MEM_W(0, (gpr)(int32_t)addr) = (int32_t)u;
    }

    float signed_degrees(float d) {
        d = std::fmod(d, 360.0f);
        if (d > 180.0f) d -= 360.0f;
        if (d < -180.0f) d += 360.0f;
        return d;
    }

    template <typename T>
    T qol_value(const std::string& id, T fallback) {
        try {
            return std::get<T>(recompui::config::get_config(tooie::qol_tab_id).get_option_value(id));
        } catch (...) {
            return fallback;
        }
    }

    // Photo crop entries' width / height, by enum value (0 none).
    constexpr float crop_aspects[] = { 0.0f, 16.0f / 9.0f, 2.39f, 4.0f / 3.0f, 1.0f, 4.0f / 5.0f, 9.0f / 16.0f };

    float crop_value() {
        const uint32_t crop = qol_value<uint32_t>(tooie::photo_mode::crop_option, 0);
        return crop < std::size(crop_aspects) ? crop_aspects[crop] : 0.0f;
    }

    // The game's depth buffer pointer (decomp func_8001A0A8), for depth of field.
    constexpr gpr depth_buffer_ptr = (int32_t)0x8007BCC4;

    void apply_filters(bool on, uint32_t depth_address = 0) {
        if (!on) {
            // The game's own picture settings (Graphics tab) come back.
            tooie::picture_filters::apply();
            RT64::SetPhotoFrame(0.0f, false);
            RT64::SetPhotoBorder(0);
            RT64::SetPhotoDepthOfField(0.0f, 0);
            return;
        }
        RT64::SetPhotoDepthOfField((float)qol_value<double>(tooie::photo_mode::dof_option, 0.0) / 100.0f, depth_address);
        RT64::SetPhotoFrame(crop_value(), qol_value<bool>(tooie::photo_mode::grid_option, false));
        RT64::SetPhotoBorder(qol_value<uint32_t>(tooie::photo_mode::border_option, 0));
        RT64::SetPhotoGrade(true,
            qol_value<uint32_t>(tooie::photo_mode::look_option, 0),
            (float)qol_value<double>(tooie::photo_mode::exposure_option, 0.0) / 10.0f,
            (float)qol_value<double>(tooie::photo_mode::contrast_option, 0.0) / 100.0f,
            (float)qol_value<double>(tooie::photo_mode::saturation_option, 0.0) / 100.0f,
            (float)qol_value<double>(tooie::photo_mode::warmth_option, 0.0) / 100.0f,
            (float)qol_value<double>(tooie::photo_mode::vignette_option, 0.0) / 100.0f,
            (float)qol_value<double>(tooie::photo_mode::grain_option, 0.0) / 100.0f);
    }

    bool collision_on() {
        try {
            return std::get<bool>(recompui::config::get_config(tooie::qol_tab_id).get_option_value(tooie::photo_mode_collision_option));
        } catch (...) {
            return true;
        }
    }

    // Moves the camera from `pos` by `delta`, stopping at what it hits and sliding along it.
    void move_with_collision(uint8_t* rdram, recomp_context* ctx, float pos[3], const float delta[3]) {
        float to[3] = { pos[0] + delta[0], pos[1] + delta[1], pos[2] + delta[2] };
        if (delta[0] == 0.0f && delta[1] == 0.0f && delta[2] == 0.0f) {
            return;
        }
        float normal[3] = { 0, 0, 0 };
        float want[3] = { to[0], to[1], to[2] };
        if (!tooie::free_camera::sweep_line(rdram, ctx, pos, to, normal)) {
            std::memcpy(pos, want, sizeof(want));
            return;
        }
        // Lift off the surface a little, so the next test does not start touching it.
        for (int i = 0; i < 3; i++) {
            to[i] += normal[i] * surface_gap;
        }
        // Slide: what is left of the move, without the part going into the surface.
        float rest[3] = { want[0] - to[0], want[1] - to[1], want[2] - to[2] };
        const float into = rest[0] * normal[0] + rest[1] * normal[1] + rest[2] * normal[2];
        if (into < 0.0f) {
            for (int i = 0; i < 3; i++) {
                rest[i] -= into * normal[i];
            }
        }
        float slide[3] = { to[0] + rest[0], to[1] + rest[1], to[2] + rest[2] };
        if (tooie::free_camera::sweep_line(rdram, ctx, to, slide, normal)) {
            for (int i = 0; i < 3; i++) {
                slide[i] += normal[i] * surface_gap;
            }
        }
        std::memcpy(pos, slide, sizeof(slide));
    }

    float deadzone(float v) {
        return std::fabs(v) < stick_deadzone ? 0.0f : v;
    }

    recomp::config::Config& qol_config() {
        return recompui::config::get_config(tooie::qol_tab_id);
    }

    struct NumberRow {
        Row row;
        const std::string* id;
        double min, max, step;
    };
    const NumberRow number_rows[] = {
        { Row::Exposure, &tooie::photo_mode::exposure_option, -20, 20, 1 },
        { Row::Contrast, &tooie::photo_mode::contrast_option, -50, 50, 5 },
        { Row::Saturation, &tooie::photo_mode::saturation_option, -100, 100, 5 },
        { Row::Warmth, &tooie::photo_mode::warmth_option, -100, 100, 5 },
        { Row::Vignette, &tooie::photo_mode::vignette_option, 0, 100, 5 },
        { Row::Grain, &tooie::photo_mode::grain_option, 0, 100, 5 },
        { Row::Focus, &tooie::photo_mode::dof_option, 0, 100, 5 },
        { Row::Tilt, &tooie::photo_mode::tilt_option, -45, 45, 1 },
    };
    constexpr const char* look_names[] = { "None", "Sepia", "Black and white", "Noir", "Warm", "Cool", "Vivid", "Faded film",
        "Teal and orange", "Dream" };
    constexpr const char* border_names[] = { "None", "Instant photo", "Film strip", "Honeycomb", "Jiggy", "Wooden" };
    constexpr const char* crop_names[] = { "None", "16:9", "2.39:1", "4:3", "1:1", "4:5", "9:16" };
    constexpr const char* row_names[] = { "Zoom", "Camera", "Collision", "Time", "HUD", "Banjo", "Pose", "Pose frame", "Others", "Timer", "Shutter", "Filter", "Exposure",
        "Contrast", "Saturation", "Warmth", "Vignette", "Film grain", "Depth of field", "Focus point", "Tilt", "Crop", "Border", "Grid", "Album" };
    static_assert(std::size(row_names) == row_count);

    // On the game thread: one step of the picked row, -1 or +1.
    void change_row(Row row, int step) {
        try {
            recomp::config::Config& qol = qol_config();
            switch (row) {
            case Row::Zoom:
                break;
            case Row::Camera:
                orbit_toggle = true;
                break;
            case Row::Collision:
                qol.update_option_value(tooie::photo_mode_collision_option, !collision_on());
                break;
            case Row::Time:
                speed = (speed + speed_count + step) % speed_count;
                break;
            case Row::Hud:
                tooie::hide_hud::set_hidden(!tooie::hide_hud::is_hidden());
                break;
            case Row::Banjo:
                players_toggle = true;
                break;
            case Row::Others:
                others_hidden = !others_hidden;
                break;
            case Row::Pose:
                pose_choice = (pose_choice + pose_count + step) % pose_count;
                pose_dirty = true;
                break;
            case Row::PoseFrame:
                pose_frame = std::clamp(pose_frame + step, 0, 20);
                pose_dirty = true;
                break;
            case Row::Filter: {
                const uint32_t n = (uint32_t)std::size(look_names);
                qol.update_option_value(tooie::photo_mode::look_option, (qol_value<uint32_t>(tooie::photo_mode::look_option, 0) + n + step) % n);
                break;
            }
            case Row::Border: {
                const uint32_t n = (uint32_t)std::size(border_names);
                qol.update_option_value(tooie::photo_mode::border_option, (qol_value<uint32_t>(tooie::photo_mode::border_option, 0) + n + step) % n);
                break;
            }
            case Row::Crop: {
                const uint32_t n = (uint32_t)std::size(crop_names);
                qol.update_option_value(tooie::photo_mode::crop_option, (qol_value<uint32_t>(tooie::photo_mode::crop_option, 0) + n + step) % n);
                break;
            }
            case Row::Grid:
                qol.update_option_value(tooie::photo_mode::grid_option, !qol_value<bool>(tooie::photo_mode::grid_option, false));
                break;
            case Row::Timer: {
                const int n = (int)std::size(timer_seconds);
                timer_choice = (timer_choice + n + step) % n;
                break;
            }
            case Row::FocusPoint: {
                const int n = (int)Focus::Count;
                focus_choice = (focus_choice + n + step) % n;
                break;
            }
            case Row::Album:
                if (step > 0) {
                    album_requested = true;
                }
                break;
            case Row::Shutter:
                qol.update_option_value(tooie::photo_mode::shutter_option, !qol_value<bool>(tooie::photo_mode::shutter_option, true));
                break;
            default:
                for (const NumberRow& n : number_rows) {
                    if (n.row == row) {
                        const double v = std::clamp(qol_value<double>(*n.id, 0.0) + step * n.step, n.min, n.max);
                        qol.update_option_value(*n.id, v);
                    }
                }
                break;
            }
        } catch (...) {
        }
    }

    std::string row_value(Row row) {
        char text[32];
        switch (row) {
        case Row::Zoom:
            std::snprintf(text, sizeof(text), "x%.2f", 1.0f / fov_scale.load());
            return text;
        case Row::Camera:
            return orbit_on ? "Orbit Banjo" : "Free";
        case Row::Collision:
            return collision_on() ? "On" : "Off";
        case Row::Time:
            return speed_values[speed.load()];
        case Row::Hud:
            return tooie::hide_hud::is_hidden() ? "Hidden" : "Shown";
        case Row::Banjo:
            return players_hidden ? "Hidden" : "Shown";
        case Row::Others:
            return others_hidden ? "Hidden" : "Shown";
        case Row::Pose:
            return poses[pose_choice.load()].name;
        case Row::PoseFrame:
            std::snprintf(text, sizeof(text), "%d%%", pose_frame.load() * 5);
            return text;
        case Row::Filter: {
            const uint32_t v = qol_value<uint32_t>(tooie::photo_mode::look_option, 0);
            return v < std::size(look_names) ? look_names[v] : "None";
        }
        case Row::Border: {
            const uint32_t v = qol_value<uint32_t>(tooie::photo_mode::border_option, 0);
            return v < std::size(border_names) ? border_names[v] : "None";
        }
        case Row::Crop: {
            const uint32_t v = qol_value<uint32_t>(tooie::photo_mode::crop_option, 0);
            return v < std::size(crop_names) ? crop_names[v] : "None";
        }
        case Row::Grid:
            return qol_value<bool>(tooie::photo_mode::grid_option, false) ? "On" : "Off";
        case Row::Timer:
            if (timer_choice == 0) {
                return "Off";
            }
            std::snprintf(text, sizeof(text), "%d s", timer_seconds[timer_choice.load()]);
            return text;
        case Row::FocusPoint:
            return focus_names[focus_choice.load()];
        case Row::Album:
            return "A to open";
        case Row::Shutter:
            return qol_value<bool>(tooie::photo_mode::shutter_option, true) ? "Click and flash" : "Off";
        case Row::Exposure:
            std::snprintf(text, sizeof(text), "%+.1f stops", qol_value<double>(tooie::photo_mode::exposure_option, 0.0) / 10.0);
            return text;
        default:
            for (const NumberRow& n : number_rows) {
                if (n.row == row) {
                    std::snprintf(text, sizeof(text), "%.0f", qol_value<double>(*n.id, 0.0));
                    return text;
                }
            }
            return "";
        }
    }

    uint32_t player_anim_ctrl(uint8_t* rdram, recomp_context* ctx) {
        const uint32_t player = (uint32_t)MEM_W(0, (gpr)(int32_t)player_table);
        if (player < 0x80000000u || player >= 0x81000000u) {
            return 0;
        }
        recomp_context call = *ctx;
        call.r29 = ctx->r29 - 0x100;
        call.r4 = (int32_t)player;
        baanim_getAnimCtrlPtr(rdram, &call);
        const uint32_t ctrl = (uint32_t)call.r2;
        return ctrl >= 0x80000000u && ctrl < 0x81000000u ? ctrl : 0;
    }

    // As the game's own state inits do: reset, no blend, the animation, a duration, looped, started.
    void play_anim(uint8_t* rdram, recomp_context* ctx, uint32_t ctrl, uint32_t anim, uint32_t duration_bits, uint32_t playback) {
        recomp_context call = *ctx;
        call.r29 = ctx->r29 - 0x100;
        call.r4 = (int32_t)ctrl;
        anctrl_reset(rdram, &call);
        call.r4 = (int32_t)ctrl;
        call.r5 = 0;
        anctrl_setSmoothTransition(rdram, &call);
        call.r4 = (int32_t)ctrl;
        call.r5 = (int32_t)anim;
        anctrl_setIndex(rdram, &call);
        call.r4 = (int32_t)ctrl;
        call.r5 = (int32_t)duration_bits;
        anctrl_setDuration(rdram, &call);
        call.r4 = (int32_t)ctrl;
        call.r5 = (int32_t)playback;
        anctrl_setPlaybackType(rdram, &call);
        call.r4 = (int32_t)ctrl;
        anctrl_start(rdram, &call);
    }

    void hold_pose_frame(uint8_t* rdram, recomp_context* ctx);

    // Puts Banjo in the picked pose (or back in his own animation for "Game"), held at the pose frame.
    void apply_pose(uint8_t* rdram, recomp_context* ctx, uint32_t anim) {
        const uint32_t ctrl = player_anim_ctrl(rdram, ctx);
        if (ctrl == 0) {
            return;
        }
        if (anim == 0) {
            if (saved_anim.saved && saved_anim.ctrl == ctrl) {
                play_anim(rdram, ctx, ctrl, saved_anim.index, saved_anim.duration, saved_anim.playback);
                MEM_W(anctrl_timer, (gpr)(int32_t)ctrl) = (int32_t)saved_anim.timer;
            }
            saved_anim.saved = false;
            return;
        }
        if (!saved_anim.saved) {
            saved_anim.saved = true;
            saved_anim.ctrl = ctrl;
            saved_anim.index = (uint32_t)(uint16_t)MEM_H(anctrl_index, (gpr)(int32_t)ctrl);
            saved_anim.duration = (uint32_t)MEM_W(anctrl_duration, (gpr)(int32_t)ctrl);
            saved_anim.playback = (uint32_t)MEM_BU(anctrl_playback, (gpr)(int32_t)ctrl);
            saved_anim.timer = (uint32_t)MEM_W(anctrl_timer, (gpr)(int32_t)ctrl);
        }
        constexpr uint32_t two_seconds = 0x40000000;   // 2.0f: how long a loop takes in slow time
        play_anim(rdram, ctx, ctrl, anim, two_seconds, 2);
        hold_pose_frame(rdram, ctx);
    }

    // Keeps the animation at the pose frame while time is frozen (in slow time it plays on from there).
    void hold_pose_frame(uint8_t* rdram, recomp_context* ctx) {
        const uint32_t ctrl = player_anim_ctrl(rdram, ctx);
        if (ctrl == 0) {
            return;
        }
        const float t = std::min((float)pose_frame.load() / 20.0f, 0.999f);
        write_float(rdram, ctrl + anctrl_timer, t);
    }

    void shoot() {
        tooie::screenshot::take();
        bool shutter = true;
        try {
            shutter = qol_value<bool>(tooie::photo_mode::shutter_option, true);
        } catch (...) {
        }
        if (shutter) {
            last_shot_ns = Clock::now().time_since_epoch().count();
            shots.fetch_add(1);
        }
    }

    void stop_timer() {
        timer_requested = false;
        timer_running = false;
        timer_shown = -1;
    }

    void enter(uint8_t* rdram) {
        is_active = true;
        speed = 0;
        fov_scale = 1.0f;
        orbit_toggle = false;
        cam.placed = false;
        cam.orbit = false;
        orbit_on = false;
        players_toggle = false;
        pending_step = 0;
        cam.moving = false;
        entered_map = tooie::debug::current_map(rdram);
        hud_was_hidden = tooie::hide_hud::is_hidden();
        if (!hud_was_hidden) {
            tooie::hide_hud::set_hidden(true);
        }
        {
            std::lock_guard lock{ pad_mutex };
            last_buttons = 0xFFFF;   // buttons already held don't count as presses
        }
        if (!panel_shown) {
            tooie::toast::show("Photo mode: A photo, B back, L shows the list");
        }
        fprintf(stderr, "[photo] on\n");
    }

    void leave() {
        is_active = false;
        apply_filters(false);
        RT64::SetPhotoFocus(0.5f, 0.5f);
        players_hidden = false;
        others_hidden = false;
        if (!hud_was_hidden && tooie::hide_hud::is_hidden()) {
            tooie::hide_hud::set_hidden(false);
        }
        if (timer_running) {
            stop_timer();
        }
        tooie::toast::show("Photo mode off");
        fprintf(stderr, "[photo] off\n");
    }
}

void tooie::photo_mode::register_input() {
    recompinput::set_game_input_name(photo_input, "Photo Mode");
    recompinput::set_game_input_description(photo_input,
        "Freezes the game and hides the HUD so you can fly the camera around and take screenshots. "
        "Left stick moves, right stick looks, Z and R go down and up, A takes a screenshot. "
        "A list on screen holds zoom, camera, collision, time, HUD, Banjo, the filters, depth of field, tilt, crop and grid: "
        "D-pad up and down pick a row, left and right change it, L hides the list. "
        "Start runs time at 1/167, 1/8 or 1/4 speed, B goes back to the game.");
    recompinput::set_default_mapping_for_keyboard(photo_input, { recompinput::InputField::keyboard(SDL_SCANCODE_F10) });
    recompinput::set_default_mapping_for_controller(photo_input, { recompinput::InputField::controller_digital(SDL_CONTROLLER_BUTTON_GUIDE) });
}

void tooie::photo_mode::start() {
    std::call_once(started, [] {
        if (const char* v = std::getenv("TOOIE_POSE_SWEEP")) {
            for (const char* p = v; *p != '\0';) {
                unsigned first = 0, last = 0;
                int used = 0;
                if (std::sscanf(p, "%x%n", &first, &used) != 1) {
                    break;
                }
                p += used;
                last = first;
                if (*p == '-' && std::sscanf(p + 1, "%x%n", &last, &used) == 1) {
                    p += 1 + used;
                }
                for (unsigned id = first; id <= last; id++) {
                    pose_sweep.ids.push_back(id);
                }
                if (*p == ',') {
                    p++;
                }
            }
            pose_sweep.active = !pose_sweep.ids.empty();
            const char* frame = std::getenv("TOOIE_POSE_FRAME");
            pose_frame = frame != nullptr ? std::clamp(std::atoi(frame), 0, 20) : 10;
        }
        if (const char* v = std::getenv("TOOIE_PHOTO")) {
            test.active = std::sscanf(v, "%ld:%ld", &test.on, &test.off) == 2;
        }
        std::thread(worker).detach();
    });
}

void tooie::photo_mode::add_options(recomp::config::Config& qol) {
    qol.add_enum_option(look_option, "Photo Filter",
        "A colour look for photo mode (F10). Only shown while photo mode is on, and in its screenshots.",
        {
            {0, "none", "None"},
            {1, "sepia", "Sepia"},
            {2, "bw", "Black and white"},
            {3, "noir", "Noir"},
            {4, "warm", "Warm"},
            {5, "cool", "Cool"},
            {6, "vivid", "Vivid"},
            {7, "faded", "Faded film"},
            {8, "teal_orange", "Teal and orange"},
            {9, "dream", "Dream"},
        },
        0u, true);
    qol.add_number_option(exposure_option, "Photo Exposure", "Brightens or darkens photo mode's picture, in tenths of a stop.", -20, 20, 1, 0, false, 0, true);
    qol.add_number_option(contrast_option, "Photo Contrast", "Photo mode's contrast, in percent.", -50, 50, 5, 0, false, 0, true);
    qol.add_number_option(saturation_option, "Photo Saturation", "Photo mode's colour strength, in percent. -100 is black and white.", -100, 100, 5, 0, false, 0, true);
    qol.add_number_option(warmth_option, "Photo Warmth", "Tints photo mode's picture warmer (up) or cooler (down).", -100, 100, 5, 0, false, 0, true);
    qol.add_number_option(vignette_option, "Photo Vignette", "Darkens the corners of photo mode's picture.", 0, 100, 5, 0, false, 0, true);
    qol.add_number_option(grain_option, "Photo Film Grain", "Adds film grain to photo mode's picture.", 0, 100, 5, 0, false, 0, true);
    qol.add_enum_option(crop_option, "Photo Crop",
        "Frames photo mode's picture to a shape: outside the frame is shaded, and screenshots keep only the frame.",
        {
            {0, "none", "None"},
            {1, "16_9", "16:9"},
            {2, "239_1", "2.39:1"},
            {3, "4_3", "4:3"},
            {4, "1_1", "1:1"},
            {5, "4_5", "4:5"},
            {6, "9_16", "9:16"},
        },
        0u, true);
    qol.add_enum_option(border_option, "Photo Border",
        "A frame round photo mode's picture (inside the crop), kept in its screenshots.",
        {
            {0, "none", "None"},
            {1, "instant", "Instant photo"},
            {2, "film", "Film strip"},
            {3, "honeycomb", "Honeycomb"},
            {4, "jiggy", "Jiggy"},
            {5, "wooden", "Wooden"},
        },
        0u, true);
    qol.add_number_option(tilt_option, "Photo Tilt",
        "Tilts photo mode's camera, in degrees. 0 is level.",
        -45, 45, 1, 0, false, 0, true);
    qol.add_number_option(dof_option, "Photo Depth Of Field",
        "Blurs what is nearer or further than the focus point (the middle of photo mode's picture, unless the photo panel's Focus point row moves it), which stays sharp. 0 is off.",
        0, 100, 5, 0, false, 0, true);
    qol.add_bool_option(shutter_option, "Photo Shutter",
        "Plays a camera click and flashes the screen when photo mode takes a photo. The flash is never in the photo.", true, true);
    qol.add_bool_option(grid_option, "Photo Grid",
        "Draws a rule-of-thirds grid in photo mode, inside the crop frame. It is never in screenshots.", false, true);
    // Was QOL > Photo mode camera collision until L moved it to the photo panel (2026-10-21); same key.
    qol.add_bool_option(tooie::photo_mode_collision_option, "Photo Mode Camera Collision",
        "In photo mode the camera stops at the ground and slides along walls. Off lets it fly through everything.", true, true);
}

bool tooie::photo_mode::panel_state(std::vector<std::string>& rows, int& picked_row) {
    if (!is_active || !panel_shown) {
        return false;
    }
    rows.clear();
    for (int i = 0; i < row_count; i++) {
        rows.push_back(std::string(row_names[i]) + ": " + row_value((Row)i));
    }
    picked_row = picked;
    return true;
}

bool tooie::photo_mode::take_album_request() {
    return album_requested.exchange(false) && is_active;
}

bool tooie::photo_mode::active() {
    return is_active;
}

float tooie::photo_mode::crop_aspect() {
    return is_active ? crop_value() : 0.0f;
}

float tooie::photo_mode::adjust_fov(float fov) {
    if (!is_active) {
        return fov;
    }
    last_fov = fov * fov_scale.load();
    return last_fov;
}

void tooie::photo_mode::apply_input(uint16_t* buttons, float* x, float* y) {
    if (!is_active) {
        return;
    }
    uint16_t pressed;
    {
        std::lock_guard lock{ pad_mutex };
        pad.buttons = *buttons;
        pad.x = *x;
        pad.y = *y;
        pressed = *buttons & ~last_buttons;
        last_buttons = *buttons;
    }
    if (pressed & button_b) {
        leave_requested = true;
    }
    if (pressed & button_a) {
        if ((Row)picked.load() == Row::Album) {
            album_requested = true;
        }
        else if (timer_choice == 0) {
            shoot();
        }
        else {
            // Started (or, while counting, cancelled) on the game thread.
            timer_requested = true;
        }
    }
    if (pressed & d_up) {
        picked = (picked + row_count - 1) % row_count;
    }
    if (pressed & d_down) {
        picked = (picked + 1) % row_count;
    }
    if (pressed & button_l) {
        panel_shown = !panel_shown;
    }
    // Left / right change the picked row (zoom is held, in place_camera).
    const int dir = (*buttons & d_right ? 1 : 0) - (*buttons & d_left ? 1 : 0);
    const Clock::time_point now = Clock::now();
    if (dir == 0 || (Row)picked.load() == Row::Zoom) {
        step_held_since = {};
    }
    else if (pressed & (d_left | d_right)) {
        step_held_since = now;
        step_last = now;
        pending_step = dir;
    }
    else if (step_held_since != Clock::time_point{} && now - step_held_since >= repeat_delay && now - step_last >= repeat_every) {
        step_last = now;
        pending_step = dir;
    }
    if (pressed & button_start) {
        int s = (speed + 1) % speed_count;
        speed = s;
        if (!panel_shown) {
            tooie::toast::show(speed_names[s]);
        }
    }
    *buttons = 0;
    *x = 0.0f;
    *y = 0.0f;
}

void tooie::photo_mode::tick(uint8_t* rdram, recomp_context* ctx) {
    if (test.active) {
        if (test.begin == Clock::time_point{}) {
            test.begin = Clock::now();
        }
        static const bool game_clock = std::getenv("TOOIE_SCREENSHOT_GAME") != nullptr;   // QA: times in game time
        long ms = game_clock ? (long)tooie::game_frame_rate::game_ms()
                             : (long)std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - test.begin).count();
        if (!test.did_on && ms >= test.on && tooie::debug::can_warp()) {
            test.did_on = true;
            toggle_requested = true;
        }
        if (test.did_on && !test.did_off && ms >= test.off) {
            test.did_off = true;
            if (is_active) {
                leave_requested = true;
            }
        }
    }

    const bool playing = tooie::debug::can_warp() && (uint32_t)MEM_W(0, game_state_addr) == game_state_playing;
    if (toggle_requested.exchange(false)) {
        if (is_active) {
            leave_requested = true;
        }
        else if (playing) {
            enter(rdram);
        }
    }
    if (is_active && (leave_requested.exchange(false) || !playing || tooie::debug::current_map(rdram) != entered_map)) {
        if (saved_anim.saved && playing && tooie::debug::current_map(rdram) == entered_map) {
            apply_pose(rdram, ctx, 0);
        }
        saved_anim.saved = false;
        pose_choice = 0;
        leave();
    }
    leave_requested = false;
    if (!is_active) {
        return;
    }

    if (pose_sweep.active) {
        const Clock::time_point now = Clock::now();
        if (pose_sweep.at == Clock::time_point{}) {
            pose_sweep.at = now + 12s;
        }
        if (now >= pose_sweep.at) {
            if (!pose_sweep.shot) {
                if (pose_sweep.next >= pose_sweep.ids.size()) {
                    pose_sweep.active = false;
                    fprintf(stderr, "[pose] sweep done\n");
                }
                else {
                    sweep_anim = pose_sweep.ids[pose_sweep.next++];
                    fprintf(stderr, "[pose] sweep 0x%X\n", sweep_anim);
                    apply_pose(rdram, ctx, sweep_anim);
                    pose_sweep.shot = true;
                    pose_sweep.at = now + 300ms;
                }
            }
            else {
                tooie::screenshot::take();
                pose_sweep.shot = false;
                pose_sweep.at = now + 300ms;
            }
        }
    }
    if (pose_dirty.exchange(false)) {
        apply_pose(rdram, ctx, poses[pose_choice.load()].anim);
    }
    if (pose_choice != 0 || pose_sweep.active) {
        if (speed == 0) {
            hold_pose_frame(rdram, ctx);
        }
    }

    if (timer_requested.exchange(false)) {
        if (timer_running) {
            stop_timer();
            tooie::toast::show("Timer cancelled");
        }
        else if (timer_choice > 0) {
            timer_running = true;
            timer_end = Clock::now() + std::chrono::seconds(timer_seconds[timer_choice.load()]);
            timer_shown = -1;
        }
    }
    if (timer_running) {
        const auto left = timer_end - Clock::now();
        if (left <= 0ms) {
            stop_timer();
            shoot();
        }
        else {
            const int secs = (int)std::chrono::duration_cast<std::chrono::seconds>(left + 999ms).count();
            if (secs != timer_shown) {
                timer_shown = secs;
                tooie::toast::show("Photo in " + std::to_string(secs));
            }
        }
    }

    if (const int step = pending_step.exchange(0); step != 0) {
        change_row((Row)picked.load(), step);
    }
    if (players_toggle.exchange(false)) {
        players_hidden = !players_hidden;
        if (!panel_shown) {
            tooie::toast::show(players_hidden ? "Banjo hidden" : "Banjo shown");
        }
    }

    // RT64 keys framebuffers by physical address.
    apply_filters(true, (uint32_t)MEM_W(0, depth_buffer_ptr) & 0x1FFFFFFFu);

    const float scale = speed_scales[speed.load()];
    const float dt = read_float(rdram, (uint32_t)delta_time_addr);
    game_delta = dt;
    write_float(rdram, (uint32_t)delta_time_addr, scale > 0.0f ? dt * scale : frozen_delta);
}

namespace {
    // Tells RT64 where depth of field focuses, as a fraction of the picture. For Banjo, his middle is
    // projected with the photo camera (yaw 0 looks along -z, turning left as it grows; positive pitch
    // looks up), the game's vertical field of view and the window's shape, then turned with the tilt.
    void place_focus(uint8_t* rdram, float tilt) {
        float fx = 0.5f, fy = 0.5f;
        switch ((Focus)focus_choice.load()) {
        case Focus::TopLeft: fx = 1.0f / 3.0f; fy = 1.0f / 3.0f; break;
        case Focus::TopRight: fx = 2.0f / 3.0f; fy = 1.0f / 3.0f; break;
        case Focus::BottomLeft: fx = 1.0f / 3.0f; fy = 2.0f / 3.0f; break;
        case Focus::BottomRight: fx = 2.0f / 3.0f; fy = 2.0f / 3.0f; break;
        case Focus::Banjo: {
            const uint32_t player = (uint32_t)MEM_W(0, (gpr)(int32_t)player_table);
            const uint32_t transform = player != 0 ? (uint32_t)MEM_W(player_transform, (gpr)(int32_t)player) : 0;
            if (transform == 0) {
                break;
            }
            float v[3];
            for (int i = 0; i < 3; i++) {
                v[i] = read_float(rdram, transform + 4 * i) - cam.pos[i];
            }
            v[1] += banjo_middle;
            const float sy = std::sin(cam.yaw * deg), cy = std::cos(cam.yaw * deg);
            const float sp = std::sin(cam.pitch * deg), cp = std::cos(cam.pitch * deg);
            const float forward[3] = { -sy * cp, sp, -cy * cp };
            const float right[3] = { cy, 0.0f, -sy };
            const float up[3] = { right[1] * forward[2] - right[2] * forward[1], right[2] * forward[0] - right[0] * forward[2],
                right[0] * forward[1] - right[1] * forward[0] };
            const float z = v[0] * forward[0] + v[1] * forward[1] + v[2] * forward[2];
            if (z < 1.0f) {
                break;
            }
            int width = 0, height = 0;
            recompui::get_window_size(width, height);
            const float aspect = width > 0 && height > 0 ? (float)width / (float)height : 16.0f / 9.0f;
            const float t = std::tan(std::clamp(last_fov.load(), 8.0f, 150.0f) * 0.5f * deg);
            // In units of half the picture's height, so the tilt turns them without stretching.
            const float x = (v[0] * right[0] + v[1] * right[1] + v[2] * right[2]) / (z * t);
            const float y = (v[0] * up[0] + v[1] * up[1] + v[2] * up[2]) / (z * t);
            const float st = std::sin(tilt * deg), ct = std::cos(tilt * deg);
            const float tx = x * ct + y * st, ty = -x * st + y * ct;
            fx = std::clamp(0.5f + 0.5f * tx / aspect, 0.02f, 0.98f);
            fy = std::clamp(0.5f - 0.5f * ty, 0.02f, 0.98f);
            break;
        }
        default:
            break;
        }
        RT64::SetPhotoFocus(fx, fy);
        static const bool log = std::getenv("TOOIE_PHOTO_LOG") != nullptr;
        static Clock::time_point last_log;
        if (log && Clock::now() - last_log >= 500ms) {
            last_log = Clock::now();
            fprintf(stderr, "[photo] focus %.3f %.3f\n", fx, fy);
        }
    }
}

bool tooie::photo_mode::place_camera(uint8_t* rdram, recomp_context* ctx, uint32_t camera) {
    if (!is_active) {
        return false;
    }
    const Clock::time_point now = Clock::now();
    if (!cam.placed) {
        // Start where the game's camera is.
        cam.placed = true;
        cam.last = now;
        for (int i = 0; i < 3; i++) {
            cam.pos[i] = read_float(rdram, camera + cam_pos + 4 * i);
        }
        cam.pitch = signed_degrees(read_float(rdram, camera + cam_rot + 0));
        cam.yaw = read_float(rdram, camera + cam_rot + 4);
    }
    const float dt = std::clamp(std::chrono::duration<float>(now - cam.last).count(), 0.0f, 0.1f);
    cam.last = now;

    Pad p;
    {
        std::lock_guard lock{ pad_mutex };
        p = pad;
    }
    // Look: the right stick, or the C-buttons when the stick is still (keyboard).
    float look_x = 0.0f, look_y = 0.0f;
    recompinput::get_right_analog(0, &look_x, &look_y);
    look_y = -look_y;
    tooie::debug::get_scripted_right_stick(&look_x, &look_y);
    look_x = deadzone(look_x);
    look_y = deadzone(look_y);
    if (look_x == 0.0f && look_y == 0.0f) {
        look_x = (p.buttons & c_right ? 1.0f : 0.0f) - (p.buttons & c_left ? 1.0f : 0.0f);
        look_y = (p.buttons & c_up ? 1.0f : 0.0f) - (p.buttons & c_down ? 1.0f : 0.0f);
    }
    // Zoom, held.
    const float zoom = (Row)picked.load() != Row::Zoom ? 0.0f : (p.buttons & d_left ? 1.0f : 0.0f) - (p.buttons & d_right ? 1.0f : 0.0f);
    if (zoom != 0.0f) {
        fov_scale = std::clamp(fov_scale.load() * std::exp(zoom * fov_rate * dt), min_fov_scale, max_fov_scale);
    }
    if (orbit_toggle.exchange(false)) {
        cam.orbit = !cam.orbit;
        if (cam.orbit) {
            const uint32_t player = (uint32_t)MEM_W(0, (gpr)(int32_t)player_table);
            const uint32_t transform = player != 0 ? (uint32_t)MEM_W(player_transform, (gpr)(int32_t)player) : 0;
            if (transform == 0) {
                cam.orbit = false;
            }
            else {
                for (int i = 0; i < 3; i++) {
                    cam.pivot[i] = read_float(rdram, transform + 4 * i);
                }
                cam.pivot[1] += orbit_height;
                float d[3] = { cam.pivot[0] - cam.pos[0], cam.pivot[1] - cam.pos[1], cam.pivot[2] - cam.pos[2] };
                cam.distance = std::clamp(std::sqrt(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]), min_orbit, max_orbit);
                const float len = std::max(1.0f, std::sqrt(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]));
                cam.pitch = std::clamp(std::asin(std::clamp(d[1] / len, -1.0f, 1.0f)) / deg, -max_pitch, max_pitch);
                cam.yaw = std::fmod(std::atan2(-d[0], -d[2]) / deg + 360.0f, 360.0f);
                // Headless: TOOIE_PHOTO_ORBIT=<yaw>,<pitch>,<distance>[,<height>] puts the orbit camera
                // there at once (degrees as the camera's; height above Banjo's feet, default 60), so
                // close-ups frame the same whatever the frame rate.
                static const char* fixed = std::getenv("TOOIE_PHOTO_ORBIT");
                float fy, fp, fd, fh = orbit_height;
                if (fixed != nullptr && std::sscanf(fixed, "%f,%f,%f,%f", &fy, &fp, &fd, &fh) >= 3) {
                    cam.pivot[1] += fh - orbit_height;
                    cam.yaw = std::fmod(fy + 360.0f, 360.0f);
                    cam.pitch = std::clamp(fp, -max_pitch, max_pitch);
                    cam.distance = std::clamp(fd, min_orbit, max_orbit);
                }
            }
        }
        orbit_on = cam.orbit;
        if (!panel_shown) {
            tooie::toast::show(cam.orbit ? "Orbit Banjo" : "Free camera");
        }
    }
    const float move_x = deadzone(p.x);
    const float move_y = deadzone(p.y);
    const float rise = (p.buttons & button_r ? 1.0f : 0.0f) - (p.buttons & button_z ? 1.0f : 0.0f);

    const bool moving = move_x != 0.0f || move_y != 0.0f || rise != 0.0f;
    if (moving && !cam.moving) {
        cam.moving_since = now;
    }
    cam.moving = moving;
    const bool fast = moving && now - cam.moving_since >= 1s;
    const float speed_now = move_speed * (fast ? fast_factor : 1.0f);

    if (cam.orbit) {
        // Both sticks circle the pivot; Z / R move closer and further.
        look_x += move_x;
        look_y += move_y;
    }
    cam.yaw = std::fmod(cam.yaw - look_x * look_speed * dt + 360.0f, 360.0f);
    cam.pitch = std::clamp(cam.pitch + look_y * look_speed * dt, -max_pitch, max_pitch);

    const float sy = std::sin(cam.yaw * deg), cy = std::cos(cam.yaw * deg);
    const float sp = std::sin(cam.pitch * deg), cp = std::cos(cam.pitch * deg);
    const float forward[3] = { -sy * cp, sp, -cy * cp };
    const float right[3] = { cy, 0.0f, -sy };
    const bool collide = collision_on();
    if (cam.orbit) {
        cam.distance = std::clamp(cam.distance + rise * speed_now * dt, min_orbit, max_orbit);
        for (int i = 0; i < 3; i++) {
            cam.pos[i] = cam.pivot[i] - forward[i] * cam.distance;
        }
        if (collide) {
            float normal[3];
            tooie::free_camera::sweep_line(rdram, ctx, cam.pivot, cam.pos, normal);
        }
    }
    else {
        float delta[3];
        for (int i = 0; i < 3; i++) {
            delta[i] = (forward[i] * move_y + right[i] * move_x) * speed_now * dt;
        }
        delta[1] += rise * speed_now * dt;
        if (collide) {
            move_with_collision(rdram, ctx, cam.pos, delta);
        }
        else {
            for (int i = 0; i < 3; i++) {
                cam.pos[i] += delta[i];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        write_float(rdram, camera + cam_pos + 4 * i, cam.pos[i]);
    }
    write_float(rdram, camera + cam_rot + 0, cam.pitch < 0.0f ? cam.pitch + 360.0f : cam.pitch);
    write_float(rdram, camera + cam_rot + 4, cam.yaw);
    // Tilt: the camera's roll, positive turning the picture clockwise.
    const float tilt = (float)qol_value<double>(tooie::photo_mode::tilt_option, 0.0);
    write_float(rdram, camera + cam_rot + 8, tilt < 0.0f ? tilt + 360.0f : tilt);

    place_focus(rdram, tilt);

    static const bool log = std::getenv("TOOIE_PHOTO_LOG") != nullptr;
    static Clock::time_point last_log;
    if (log && now - last_log >= 500ms) {
        last_log = now;
        fprintf(stderr, "[photo] cam %.0f %.0f %.0f yaw %.1f pitch %.1f speed %d dt %.7f (game %.5f) orbit %d dist %.0f fov x%.2f\n",
            cam.pos[0], cam.pos[1], cam.pos[2], cam.yaw, cam.pitch, speed.load(), read_float(rdram, (uint32_t)delta_time_addr),
            game_delta.load(), cam.orbit, cam.distance, fov_scale.load());
    }
    return true;
}

extern "C" int tooie_others_hidden(void) {
    return is_active && others_hidden ? 1 : 0;
}

extern "C" int tooie_players_hidden(void) {
    return is_active && players_hidden ? 1 : 0;
}

float tooie::photo_mode::flash_level() {
    const int64_t at = last_shot_ns.load();
    if (at == 0) {
        return 0.0f;
    }
    const float t = std::chrono::duration<float>(Clock::now().time_since_epoch() - Clock::duration(at)).count();
    return t >= 0.0f && t < flash_seconds ? 1.0f - t / flash_seconds : 0.0f;
}

// A camera shutter, made up: two short clicks (the shutter opening and closing, 70 ms apart), each a
// burst of noise and a high ring dying away within a few milliseconds.
void tooie::photo_mode::mix_shutter(float* stereo, size_t frames, uint32_t rate, float volume) {
    static uint32_t seen = 0;
    static float time = -1.0f;
    static uint32_t noise = 22222;
    const uint32_t now_shots = shots.load(std::memory_order_relaxed);
    if (now_shots != seen) {
        seen = now_shots;
        time = 0.0f;
    }
    if (time < 0.0f || rate == 0) {
        return;
    }
    constexpr float level = 0.22f;
    constexpr float second_click = 0.07f;
    constexpr float length = 0.12f;
    const float dt = 1.0f / (float)rate;
    for (size_t i = 0; i < frames && time < length; i++, time += dt) {
        float v = 0.0f;
        for (const float start : { 0.0f, second_click }) {
            const float t = time - start;
            if (t < 0.0f) {
                continue;
            }
            noise = noise * 1664525u + 1013904223u;
            const float white = (float)(noise >> 8) / (float)(1u << 24) * 2.0f - 1.0f;
            const float loud = start == 0.0f ? 1.0f : 0.7f;
            v += loud * (white * std::exp(-t / 0.004f) + 0.6f * std::sin(t * 2.0f * 3.14159265f * 2400.0f) * std::exp(-t / 0.012f));
        }
        stereo[i * 2 + 0] += v * level * volume;
        stereo[i * 2 + 1] += v * level * volume;
    }
    if (time >= length) {
        time = -1.0f;
    }
}

void tooie::photo_mode::request_toggle() {
    toggle_requested = true;
}
