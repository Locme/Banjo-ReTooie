// Photo mode (handoff 4.82).
//
// Freeze: func_800D8FA0 turns the VIs the last frame took into the frame's delta time, kept as a
// float at 0x8012C760 (func_800D8FF8 returns it). tooie_warp_tick runs at the start of the game's
// frame update (func_800A7D84), after that, so photo mode scales the value there: almost nothing
// while frozen, 1/8 or 1/4 of it in slow time. Everything the game moves by delta time stands
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
//   A               screenshot (as F12)
//   D-pad up/down   pick a row of the photo panel (src/ui/photo_panel.cpp)
//   D-pad left/right change it (held repeats): zoom (the field of view, through tooie_set_fov), camera
//                   (free, or orbit Banjo: the sticks circle him, Z / R move closer and further), time,
//                   HUD, Banjo shown or hidden, the filter rows below, depth of field, tilt, crop, grid
//   L               show / hide the photo panel
//   Start           frozen, 1/8 speed, 1/4 speed
//   B / Photo Mode  back to the game, with the camera and HUD as they were
//
// Hide Banjo: func_800F5008 draws the players each frame (opaque ones at once, faded ones listed for
// func_800F50D0 to draw later); banjotooie.us.toml hooks both to skip them while tooie_players_hidden().
//
// Filters (QOL > Photo filter rows): a look, exposure, contrast, saturation, warmth, vignette and grain,
// drawn by RT64's photo grade pass (lib-patches/rt64.patch) only while photo mode is on, so screenshots
// show them. They can be changed from the photo panel or the menu while photo mode is on, as can
// QOL > Photo tilt (the camera's roll); the panel writes the same options, so both stay in step.
//
// Collision (QOL > Photo mode camera collision, on by default): each move is swept with the game's
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
#include "tooie_picture_filters.h"
#include "tooie_screenshot.h"
#include "tooie_toast.h"

namespace RT64 {
    // lib/rt64/src/render/rt64_photo_grade.h (from lib-patches/rt64.patch).
    void SetPhotoGrade(bool enabled, uint32_t look, float exposure, float contrast, float saturation, float warmth, float vignette, float grain);
    void SetPhotoFrame(float cropAspect, bool grid);
    void SetPhotoDepthOfField(float strength, uint32_t depthAddress);
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
    // The game's delta time while frozen: small but not zero, as some code divides by it.
    constexpr float frozen_delta = 0.0001f;
    constexpr float speed_scales[] = { 0.0f, 0.125f, 0.25f };
    constexpr const char* speed_names[] = { "Time frozen", "Time 1/8", "Time 1/4" };
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
    std::atomic<float> fov_scale{1.0f};

    // The photo panel: its rows, the one picked, whether it is shown, and a change waiting for the game
    // thread (-1 or +1 on the picked row).
    enum class Row { Zoom, Camera, Time, Hud, Banjo, Filter, Exposure, Contrast, Saturation, Warmth, Vignette, Grain,
        Focus, Tilt, Crop, Grid, Count };
    constexpr int row_count = (int)Row::Count;
    std::atomic<int> picked{0};
    std::atomic<bool> panel_shown{true};
    std::atomic<int> pending_step{0};
    std::atomic<bool> orbit_on{false};
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
        if (recompinput::binding::is_binding()) {
            return false;
        }
        bool down = false;
        for (int profile : { recompinput::profiles::get_sp_keyboard_profile_index(), recompinput::profiles::get_sp_controller_profile_index() }) {
            if (profile < 0) {
                continue;
            }
            for (size_t b = 0; b < recompinput::num_bindings_per_input; b++) {
                down = down || recompinput::get_input_digital(0, recompinput::profiles::get_input_binding(profile, photo_input, b));
            }
        }
        return down;
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
            RT64::SetPhotoDepthOfField(0.0f, 0);
            return;
        }
        RT64::SetPhotoDepthOfField((float)qol_value<double>(tooie::photo_mode::dof_option, 0.0) / 100.0f, depth_address);
        RT64::SetPhotoFrame(crop_value(), qol_value<bool>(tooie::photo_mode::grid_option, false));
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
    constexpr const char* crop_names[] = { "None", "16:9", "2.39:1", "4:3", "1:1", "4:5", "9:16" };
    constexpr const char* row_names[] = { "Zoom", "Camera", "Time", "HUD", "Banjo", "Filter", "Exposure", "Contrast",
        "Saturation", "Warmth", "Vignette", "Film grain", "Depth of field", "Tilt", "Crop", "Grid" };
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
            case Row::Time:
                speed = (speed + 3 + step) % 3;
                break;
            case Row::Hud:
                tooie::hide_hud::set_hidden(!tooie::hide_hud::is_hidden());
                break;
            case Row::Banjo:
                players_toggle = true;
                break;
            case Row::Filter: {
                const uint32_t n = (uint32_t)std::size(look_names);
                qol.update_option_value(tooie::photo_mode::look_option, (qol_value<uint32_t>(tooie::photo_mode::look_option, 0) + n + step) % n);
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
        case Row::Time:
            return speed == 0 ? "Frozen" : speed == 1 ? "1/8 speed" : "1/4 speed";
        case Row::Hud:
            return tooie::hide_hud::is_hidden() ? "Hidden" : "Shown";
        case Row::Banjo:
            return players_hidden ? "Hidden" : "Shown";
        case Row::Filter: {
            const uint32_t v = qol_value<uint32_t>(tooie::photo_mode::look_option, 0);
            return v < std::size(look_names) ? look_names[v] : "None";
        }
        case Row::Crop: {
            const uint32_t v = qol_value<uint32_t>(tooie::photo_mode::crop_option, 0);
            return v < std::size(crop_names) ? crop_names[v] : "None";
        }
        case Row::Grid:
            return qol_value<bool>(tooie::photo_mode::grid_option, false) ? "On" : "Off";
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
        players_hidden = false;
        if (!hud_was_hidden && tooie::hide_hud::is_hidden()) {
            tooie::hide_hud::set_hidden(false);
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
        "A list on screen holds zoom, camera, time, HUD, Banjo, the filters, depth of field, tilt, crop and grid: "
        "D-pad up and down pick a row, left and right change it, L hides the list. "
        "Start runs time at 1/8 or 1/4 speed, B goes back to the game.");
    recompinput::set_default_mapping_for_keyboard(photo_input, { recompinput::InputField::keyboard(SDL_SCANCODE_F10) });
    recompinput::set_default_mapping_for_controller(photo_input, { recompinput::InputField::controller_digital(SDL_CONTROLLER_BUTTON_GUIDE) });
}

void tooie::photo_mode::start() {
    std::call_once(started, [] {
        if (const char* v = std::getenv("TOOIE_PHOTO")) {
            test.active = std::sscanf(v, "%ld:%ld", &test.on, &test.off) == 2;
        }
        std::thread(worker).detach();
    });
}

void tooie::photo_mode::add_options(recomp::config::Config& qol) {
    qol.add_bool_option(hide_settings_option, "Hide Settings",
        "Hides photo mode's filter, exposure, crop and the other photo settings below. Turn it off to change them.", true);
    qol.add_enum_option(look_option, "Photo filter",
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
        0u);
    qol.add_number_option(exposure_option, "Photo exposure", "Brightens or darkens photo mode's picture, in tenths of a stop.", -20, 20, 1, 0, false, 0);
    qol.add_number_option(contrast_option, "Photo contrast", "Photo mode's contrast, in percent.", -50, 50, 5, 0, false, 0);
    qol.add_number_option(saturation_option, "Photo saturation", "Photo mode's colour strength, in percent. -100 is black and white.", -100, 100, 5, 0, false, 0);
    qol.add_number_option(warmth_option, "Photo warmth", "Tints photo mode's picture warmer (up) or cooler (down).", -100, 100, 5, 0, false, 0);
    qol.add_number_option(vignette_option, "Photo vignette", "Darkens the corners of photo mode's picture.", 0, 100, 5, 0, false, 0);
    qol.add_number_option(grain_option, "Photo film grain", "Adds film grain to photo mode's picture.", 0, 100, 5, 0, false, 0);
    qol.add_enum_option(crop_option, "Photo crop",
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
        0u);
    qol.add_number_option(tilt_option, "Photo tilt",
        "Tilts photo mode's camera, in degrees. 0 is level.",
        -45, 45, 1, 0, false, 0);
    qol.add_number_option(dof_option, "Photo depth of field",
        "Blurs what is nearer or further than the middle of photo mode's picture, which stays sharp. 0 is off.",
        0, 100, 5, 0, false, 0);
    qol.add_bool_option(grid_option, "Photo grid",
        "Draws a rule-of-thirds grid in photo mode, inside the crop frame. It is never in screenshots.", false);
    for (const std::string* id : { &look_option, &exposure_option, &contrast_option, &saturation_option, &warmth_option,
            &vignette_option, &grain_option, &crop_option, &tilt_option, &dof_option, &grid_option }) {
        qol.add_option_hidden_dependency(*id, hide_settings_option, true);
    }
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

bool tooie::photo_mode::active() {
    return is_active;
}

float tooie::photo_mode::crop_aspect() {
    return is_active ? crop_value() : 0.0f;
}

float tooie::photo_mode::adjust_fov(float fov) {
    return is_active ? fov * fov_scale.load() : fov;
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
        tooie::screenshot::take();
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
        int s = (speed + 1) % 3;
        speed = s;
        if (!panel_shown) {
            tooie::toast::show(speed_names[s]);
        }
    }
    *buttons = 0;
    *x = 0.0f;
    *y = 0.0f;
}

void tooie::photo_mode::tick(uint8_t* rdram, recomp_context* /*ctx*/) {
    if (test.active) {
        if (test.begin == Clock::time_point{}) {
            test.begin = Clock::now();
        }
        long ms = (long)std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - test.begin).count();
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
        leave();
    }
    leave_requested = false;
    if (!is_active) {
        return;
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
    write_float(rdram, (uint32_t)delta_time_addr, scale > 0.0f ? dt * scale : frozen_delta);
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

    static const bool log = std::getenv("TOOIE_PHOTO_LOG") != nullptr;
    static Clock::time_point last_log;
    if (log && now - last_log >= 500ms) {
        last_log = now;
        fprintf(stderr, "[photo] cam %.0f %.0f %.0f yaw %.1f pitch %.1f speed %d dt %.5f orbit %d dist %.0f fov x%.2f\n",
            cam.pos[0], cam.pos[1], cam.pos[2], cam.yaw, cam.pitch, speed.load(), read_float(rdram, (uint32_t)delta_time_addr),
            cam.orbit, cam.distance, fov_scale.load());
    }
    return true;
}

extern "C" int tooie_players_hidden(void) {
    return is_active && players_hidden ? 1 : 0;
}
