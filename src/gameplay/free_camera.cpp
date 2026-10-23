// Twin-stick (free) camera (handoff 4.55).
//
// The game turns the right stick into C buttons: a stepped 45-degree swing left
// or right and a stepped zoom. With QOL > Free camera on, the right stick
// instead orbits the camera smoothly around Banjo (left and right) and tilts it
// (up and down). Once the stick has been used the camera's yaw is held in world
// space until the game takes the camera over (a cutscene, first person, a fixed
// camera) or the map changes. Walking follows the turned camera, because the
// game reads the viewport camera's yaw for the stick direction.
//
// How it hooks in: func_8010FC38 is the per-frame step of a viewport's camera
// controller (+0x00 the viewport camera, +0x04 the dynamic camera, +0x16 the
// controller mode, 2 = dynamic camera). The mode's update writes the camera's
// position (+0x00) and pitch/yaw/roll in degrees (+0x18) and then the function
// copies them back with any shake added (func_800E1A58) and builds the
// matrices. banjotooie.us.toml hooks the point after the mode's update (0x8010FCB8),
// where this file turns the camera's offset from Banjo about Banjo. The
// dynamic camera keeps its own position (+0x74) and rotation (+0x80), so the
// game's camera logic is left as it was and only the picture moves.
//
// Ease back (QOL > Free camera: ease back, off by default): a second after the stick is let go while
// Banjo flies (Flying only) or flies or moves (Always), the held yaw, elevation, aim and zoom ease
// towards the game's own camera, which keeps chasing the spot behind Banjo underneath; once they
// meet, the game's camera takes over again.
//
// Smooth walls (QOL > Free camera: smooth walls, off by default): the wall pull-in eases instead of
// snapping. The camera's distance is held as a fraction of the wanted one; it falls quickly when a
// wall comes between, but never further behind the hit point than most of the line test's radius,
// so the camera stays in front of the surface, and it rises slowly once the way is clear. Banjo
// fades out as the camera comes close to him (func_80092258 gives a player's draw alpha; its hook
// scales the result, and the players' draw puts a faded player in its see-through pass).

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "recomp.h"
#include "funcs.h"
#include "recompui/config.h"
#include "recompinput/input_state.h"
#include "tooie_debug.h"
#include "tooie_free_camera.h"
#include "tooie_photo_mode.h"
#include "tooie_game.h"
#include "tooie_hotkeys.h"
#include "tooie_motion_aim.h"
#include "tooie_hooks.h"
#include "tooie_mirror_mode.h"
#include "tooie_rdram.h"

namespace {
    // PlayerState pointers by player at 0x80135490; PlayerState +0xE4 points at Banjo's position
    // (func_8009C128 copies it out).
    constexpr uint32_t player_table = 0x80135490;
    constexpr uint32_t player_transform = 0xE4;
    // PlayerState +0x120 points at the state block, whose +0x04 is the current state id.
    constexpr uint32_t player_state_block = 0x120;
    constexpr uint32_t state_current = 0x04;
    // Flying states: Banjo-Kazooie's take-off and flight, the bee's flight pad launch and flight
    // (as src/gameplay/player_cheats.cpp).
    constexpr uint32_t flying_states[] = { 35, 36, 0x8B, 0x8C };
    // The game's delta time for this frame in seconds (func_800D8FF8 returns it; see photo_mode.cpp).
    constexpr uint32_t game_delta_time = 0x8012C760;

    // Camera controller (func_8010FC38's argument).
    constexpr uint32_t ctl_camera = 0x00;
    constexpr uint32_t ctl_dynamic = 0x04;
    constexpr uint32_t ctl_mode = 0x16;
    constexpr uint32_t ctl_active = 0x18;
    constexpr uint32_t ctl_forced = 0x19;
    constexpr int16_t mode_dynamic = 2;

    // Dynamic camera: +0x6C is its sub-mode (index into the table at 0x801247A4). While +0x71 is set
    // another camera (first person) supplies the position and rotation (func_800893E0); while +0x72
    // is set the dynamic camera is not updated.
    constexpr uint32_t dynamic_submode = 0x6C;
    constexpr uint32_t dynamic_override = 0x71;
    constexpr uint32_t dynamic_frozen = 0x72;

    // Viewport camera.
    constexpr uint32_t cam_pos = 0x00;
    constexpr uint32_t cam_rot = 0x18;

    // The point the camera orbits: Banjo's feet plus this much.
    constexpr float pivot_height = 60.0f;
    // Degrees per second at full tilt, per speed setting.
    constexpr float yaw_speeds[] = { 90.0f, 150.0f, 220.0f };
    constexpr float pitch_ratio = 0.5f;
    // Elevation of the camera above the pivot, in degrees.
    constexpr float min_elevation = -20.0f;
    constexpr float max_elevation = 70.0f;
    // How far above the pivot the camera aims (view pitch plus elevation), taken from the game's
    // camera when the stick is first used.
    constexpr float min_aim = -5.0f;
    constexpr float max_aim = 20.0f;
    // Look-up tilt (WIP): the eye may swing this low, and the view aims up to this many degrees.
    constexpr float look_min_elevation = -30.0f;
    constexpr float look_max_pitch = 80.0f;
    // Floor clearance (WIP): the downward line test runs from this far above the camera to this far below it.
    constexpr float floor_probe_up = 40.0f;
    constexpr float floor_probe_down = 60.0f;
    // Smooth stairs: rate (per second) the orbit height follows Banjo, and the jump (teleport) that snaps it.
    constexpr float pivot_rate = 8.0f;
    constexpr float pivot_snap = 300.0f;
    constexpr float stick_deadzone = 0.2f;
    // Distance, as a multiple of the game's, reached by pushing on past the tilt limits.
    constexpr float min_zoom = 0.25f;
    constexpr float max_zoom = 1.6f;
    // Zoom change per degree of stick tilt beyond a limit.
    constexpr float zoom_rate = 1.0f / 40.0f;

    // Camera line test flags and radius, as the game's camera uses them (func_80113640).
    constexpr uint32_t sweep_flags = 0x820020;
    constexpr float sweep_radius = 45.0f;
    // Hover over small objects: the thin line test that decides whether Banjo can still be seen.
    constexpr float hover_radius = 12.0f;

    // Ease back: seconds after the stick is let go, the rate (per second) of the ease, the speed
    // (units per second) Banjo counts as moving at, and how close counts as caught up.
    constexpr float ease_delay = 1.0f;
    constexpr float ease_rate = 2.0f;
    constexpr float moving_speed = 100.0f;
    constexpr float ease_done_degrees = 1.0f;
    // Smooth walls: rates (per second) of the pull-in and of the move back out, and how much of the
    // line test's radius the camera may lag behind the hit point while pulling in.
    constexpr float wall_in_rate = 18.0f;
    constexpr float wall_out_rate = 3.0f;
    constexpr float wall_lag = 0.75f * sweep_radius;
    // Banjo's alpha: whole with the camera this far from the pivot or further, gone this close.
    constexpr float fade_far = 110.0f;
    constexpr float fade_near = 45.0f;

    constexpr float deg = 3.14159265358979f / 180.0f;

    struct State {
        bool active = false;   // the stick has been used and the yaw is held
        float yaw = 0.0f;      // held camera yaw (degrees)
        float elevation = 0.0f; // held height of the camera above the pivot, in degrees
        float aim = 0.0f;       // view pitch plus elevation: how far above the pivot the camera looks
        float zoom = 1.0f;     // times the game's distance
        bool snap = false;      // Camera Snap Behind pressed: ease back now, whatever Banjo is doing
        bool snap_was_down = false;
        int32_t wheel = 0;      // mouse wheel total last step
        uint32_t middle = 0;    // middle button presses last step
        bool has_wheel = false;
        float pivot_y = 0.0f;   // smooth stairs: the height the camera orbits, eased towards Banjo's
        bool has_pivot = false;
        float look = 0.0f;      // look-up tilt: degrees the view is raised past the lowest eye height
        float idle = 0.0f;      // seconds since the stick was last used
        float wall = 1.0f;      // smooth walls: the camera's distance as a fraction of the wanted one
        float banjo[3] = { 0, 0, 0 }; // Banjo's position last step, for his speed
        bool has_banjo = false;
        uint16_t map = 0xFFFF;
        std::chrono::steady_clock::time_point last;
        bool has_last = false;
    } state;

    using tooie::rdram::read_float;
    using tooie::rdram::read_half;
    using tooie::rdram::read_word;
    using tooie::rdram::valid_ptr;
    using tooie::rdram::write_float;

    uint8_t read_byte(uint8_t* rdram, uint32_t addr) {
        return *(rdram + ((addr ^ 3) - 0x80000000u));
    }

    template <typename T>
    T option(const std::string& id, T fallback) {
        try {
            return std::get<T>(recompui::config::get_config(tooie::qol_tab_id).get_option_value(id));
        } catch (...) {
            return fallback;
        }
    }

    // The WIP tab's options live in the Graphics config (graphics.json).
    template <typename T>
    T wip_option(const std::string& id, T fallback) {
        try {
            return std::get<T>(recompui::config::get_config(recompui::config::graphics::id).get_option_value(id));
        } catch (...) {
            return fallback;
        }
    }

    float deadzone(float v) {
        if (v > stick_deadzone) return (v - stick_deadzone) / (1.0f - stick_deadzone);
        if (v < -stick_deadzone) return (v + stick_deadzone) / (1.0f - stick_deadzone);
        return 0.0f;
    }

    // func_800FAB50(from, to, normal_out, flags, radius on the stack): a swept line test that moves
    // `to` back to where it first hits. Runs it on scratch space below the hook's stack frame.
    bool sweep(uint8_t* rdram, recomp_context* ctx, const float from[3], float to[3], float* normal = nullptr,
               float radius = sweep_radius) {
        recomp_context saved = *ctx;
        const uint32_t sp = ((uint32_t)ctx->r29 - 0x80) & ~0xFu;
        const uint32_t from_addr = sp + 0x20;
        const uint32_t to_addr = sp + 0x30;
        const uint32_t normal_addr = sp + 0x40;
        for (int i = 0; i < 3; i++) {
            write_float(rdram, from_addr + 4 * i, from[i]);
            write_float(rdram, to_addr + 4 * i, to[i]);
            write_float(rdram, normal_addr + 4 * i, 0.0f);
        }
        write_float(rdram, sp + 0x10, radius);
        ctx->r29 = (int32_t)sp; // addresses are sign-extended in the registers
        ctx->r4 = (int32_t)from_addr;
        ctx->r5 = (int32_t)to_addr;
        ctx->r6 = (int32_t)normal_addr;
        ctx->r7 = sweep_flags;
        func_800FAB50(rdram, ctx);
        const bool hit = ctx->r2 != 0;
        if (hit) {
            for (int i = 0; i < 3; i++) {
                to[i] = read_float(rdram, to_addr + 4 * i);
                if (normal != nullptr) {
                    normal[i] = read_float(rdram, normal_addr + 4 * i);
                }
            }
        }
        *ctx = saved;
        return hit;
    }

    // Height of the camera above the pivot as seen from the pivot, in degrees.
    float game_elevation(const float pos[3], const float banjo[3]) {
        const float dx = pos[0] - banjo[0];
        const float dy = pos[1] - (banjo[1] + pivot_height);
        const float dz = pos[2] - banjo[2];
        return std::atan2(dy, std::sqrt(dx * dx + dz * dz)) / deg;
    }

    // 0..360 to -180..180.
    float signed_degrees(float a) {
        return a > 180.0f ? a - 360.0f : a;
    }

    float wrap_degrees(float a) {
        a = std::fmod(a, 360.0f);
        return a < 0.0f ? a + 360.0f : a;
    }

    // -180..180
    float angle_delta(float to, float from) {
        float d = wrap_degrees(to - from);
        return d > 180.0f ? d - 360.0f : d;
    }

    // 1 - e^(-rate * dt): the share of the way an ease at `rate` per second covers in dt.
    float ease(float rate, float dt) {
        return 1.0f - std::exp(-rate * dt);
    }

    // C Down tap or hold (see free_camera::apply_input): held past the threshold, the fine-tune is on.
    std::atomic<bool> fine_held{false};
    // Whether the free camera is running the game's camera now (not first person, a cutscene or a menu).
    std::atomic<bool> gameplay_camera{false};
    constexpr std::chrono::milliseconds tap_limit{250};
    constexpr int tap_pulse_reads = 4;
    // RB fine-tune: the distance range as a multiple of the game's, and the rate (per second, at a full
    // push) of the change.
    constexpr float rb_min_zoom = 0.5f;
    constexpr float rb_max_zoom = 2.0f;
    constexpr float rb_zoom_rate = 0.8f;
    // The game's camera distance button: C Down, which a controller's RB is bound to (L, 2026-10-23).
    constexpr uint16_t n64_r_button = 0x0004;

    // Scales the players' draw alpha (tooie_free_camera_player_alpha), 1 for whole.
    std::atomic<float> player_fade{1.0f};
}

bool tooie::free_camera::enabled() {
    // TOOIE_FREE_CAMERA=1 turns it on for headless tests without touching the settings.
    static const bool forced = std::getenv("TOOIE_FREE_CAMERA") != nullptr;
    return forced || option<bool>(tooie::free_camera_option, true);
}

namespace {
    std::atomic<uint32_t> last_ctl{0};
}

uint32_t tooie::free_camera::last_controller() {
    return last_ctl.load();
}

extern "C" void tooie_free_camera(uint8_t* rdram, recomp_context* ctx) {
    static const bool log = std::getenv("TOOIE_FREECAM_LOG") != nullptr;
    static auto last_log = std::chrono::steady_clock::now();

    auto now = std::chrono::steady_clock::now();
    float dt = state.has_last ? std::chrono::duration<float>(now - state.last).count() : 0.0f;
    state.last = now;
    state.has_last = true;
    dt = std::clamp(dt, 0.0f, 0.1f);

    const uint32_t ctl = (uint32_t)ctx->r16;
    if (!valid_ptr(ctl)) {
        return;
    }
    last_ctl = ctl;
    const uint32_t camera = read_word(rdram, ctl + ctl_camera);
    if (valid_ptr(camera) && tooie::photo_mode::place_camera(rdram, ctx, camera)) {
        state.active = false;
        player_fade = 1.0f;
        return;
    }
    const uint32_t dynamic = read_word(rdram, ctl + ctl_dynamic);
    const int16_t mode = read_half(rdram, ctl + ctl_mode);
    const bool updating = read_byte(rdram, ctl + ctl_active) != 0 || read_byte(rdram, ctl + ctl_forced) != 0;
    const uint32_t player = read_word(rdram, player_table);
    const uint32_t transform = valid_ptr(player) ? read_word(rdram, player + player_transform) : 0;
    const uint16_t map = tooie::debug::current_map(rdram);

    float pos[3] = { 0, 0, 0 };
    float rot[3] = { 0, 0, 0 };
    float banjo[3] = { 0, 0, 0 };
    if (valid_ptr(camera)) {
        for (int i = 0; i < 3; i++) {
            pos[i] = read_float(rdram, camera + cam_pos + 4 * i);
            rot[i] = read_float(rdram, camera + cam_rot + 4 * i);
        }
    }
    if (valid_ptr(transform)) {
        for (int i = 0; i < 3; i++) {
            banjo[i] = read_float(rdram, transform + 4 * i);
        }
    }
    const uint32_t submode = valid_ptr(dynamic) ? read_word(rdram, dynamic + dynamic_submode) : 0xFFFFFFFFu;
    const uint32_t state_block = valid_ptr(player) ? read_word(rdram, player + player_state_block) : 0;
    const uint32_t player_state = valid_ptr(state_block) ? read_word(rdram, state_block + state_current) : 0;

    // Banjo's speed along the ground since the last step, in game time so a slow frame doesn't lower it.
    float speed = 0.0f;
    if (valid_ptr(transform)) {
        const float game_dt = read_float(rdram, game_delta_time);
        if (state.has_banjo && game_dt > 0.0f) {
            const float dx = banjo[0] - state.banjo[0];
            const float dz = banjo[2] - state.banjo[2];
            speed = std::sqrt(dx * dx + dz * dz) / game_dt;
        }
        std::memcpy(state.banjo, banjo, sizeof(banjo));
    }
    state.has_banjo = valid_ptr(transform);

    // Right stick, up and right positive (SDL's y grows downwards).
    float stick_x = 0.0f;
    float stick_y = 0.0f;
    recompinput::get_right_analog(0, &stick_x, &stick_y);
    stick_y = -stick_y;
    tooie::debug::get_scripted_right_stick(&stick_x, &stick_y);
    stick_x = deadzone(stick_x);
    stick_y = deadzone(stick_y);

    // Mouse and gyro motion since the last step (drained even when unused, so it cannot pile up).
    float mouse_x = 0.0f, mouse_y = 0.0f, gyro_x = 0.0f, gyro_y = 0.0f;
    tooie::motion_aim::take_orbit(&mouse_x, &mouse_y, &gyro_x, &gyro_y);
    const auto mouse_mode = option<uint32_t>(tooie::free_camera_mouse_option, (uint32_t)tooie::FreeCameraMouse::Always);
    const auto gyro_mode = option<uint32_t>(tooie::free_camera_gyro_option, (uint32_t)tooie::FreeCameraMouse::Hold);
    const bool look_key = tooie::hotkeys::down(recompinput::GameInput::CAMERA_MOUSE_LOOK);
    auto allowed = [&](uint32_t mode) {
        return mode == (uint32_t)tooie::FreeCameraMouse::Always ||
            (mode == (uint32_t)tooie::FreeCameraMouse::Hold && look_key);
    };
    if (!allowed(mouse_mode)) {
        mouse_x = mouse_y = 0.0f;
    }
    if (!allowed(gyro_mode)) {
        gyro_x = gyro_y = 0.0f;
    }
    const float orbit_x = mouse_x + gyro_x;
    const float orbit_y = mouse_y + gyro_y;
    // Mouse wheel zoom and the middle button (snap behind) while the mouse is on; counts since last step.
    const int32_t wheel_now = recompinput::get_game_mouse_wheel();
    const uint32_t middle_now = recompinput::get_game_mouse_clicks(2);
    const bool mouse_on = mouse_mode != (uint32_t)tooie::FreeCameraMouse::Off;
    const int32_t wheel_notches = mouse_on && state.has_wheel ? wheel_now - state.wheel : 0;
    const bool middle_clicked = mouse_on && state.has_wheel && middle_now != state.middle;
    state.wheel = wheel_now;
    state.middle = middle_now;
    state.has_wheel = true;
    const bool snap_down = tooie::hotkeys::down(recompinput::GameInput::CAMERA_SNAP_BEHIND);
    const bool snap_pressed = (snap_down && !state.snap_was_down) || middle_clicked;
    state.snap_was_down = snap_down;

    const bool on = tooie::free_camera::enabled();
    const bool gameplay = updating && mode == mode_dynamic && valid_ptr(camera) && valid_ptr(transform) && valid_ptr(dynamic);
    // First person and the like: leave the camera alone but keep the held yaw for afterwards.
    const bool paused = gameplay &&
        (read_byte(rdram, dynamic + dynamic_override) != 0 || read_byte(rdram, dynamic + dynamic_frozen) != 0);
    // While the free camera is on and the game's own camera is running, the right stick
    // is the free camera's, not C buttons.
    recompinput::set_right_analog_suppressed(on && gameplay && !paused);

    // Holding C Down (RB) with the option on: the stick's up and down change the distance instead of tilting.
    float rb_zoom_input = 0.0f;
    gameplay_camera = on && gameplay && !paused;
    if (fine_held && wip_option<bool>(tooie::free_camera_rb_distance_option, false)) {
        rb_zoom_input = stick_y;
        stick_y = 0.0f;
    }

    if (!on || !gameplay || map != state.map) {
        state.active = false;
        state.map = map;
    }

    bool blocked = false;
    bool easing = false;
    float fade = 1.0f;
    if (on && gameplay && !paused) {
        const bool stick = stick_x != 0.0f || stick_y != 0.0f || orbit_x != 0.0f || orbit_y != 0.0f ||
            wheel_notches != 0 || rb_zoom_input != 0.0f;
        if (!state.active && stick) {
            state.active = true;
            state.yaw = rot[1];
            state.elevation = std::clamp(game_elevation(pos, banjo), min_elevation, max_elevation);
            state.aim = std::clamp(signed_degrees(rot[0]) + game_elevation(pos, banjo), min_aim, max_aim);
            state.zoom = 1.0f;
            state.has_pivot = false;
            state.look = 0.0f;
            state.wall = 1.0f;
        }
        state.idle = stick ? 0.0f : state.idle + dt;
        if (snap_pressed) {
            state.snap = true;
        }
        if (stick) {
            state.snap = false;
        }

        // Ease back towards the game's camera, which is behind Banjo while he moves.
        const auto ease_back = option<uint32_t>(tooie::free_camera_ease_back_option, (uint32_t)tooie::FreeCameraEaseBack::Off);
        const bool flying = std::find(std::begin(flying_states), std::end(flying_states), player_state) != std::end(flying_states);
        easing = state.active && (state.snap || state.idle >= ease_delay &&
            ((ease_back == (uint32_t)tooie::FreeCameraEaseBack::Flying && flying) ||
             (ease_back == (uint32_t)tooie::FreeCameraEaseBack::Always && (flying || speed >= moving_speed))));
        if (easing) {
            const float k = ease(ease_rate, dt);
            const float elevation = std::clamp(game_elevation(pos, banjo), min_elevation, max_elevation);
            const float aim = std::clamp(signed_degrees(rot[0]) + game_elevation(pos, banjo), min_aim, max_aim);
            state.yaw = wrap_degrees(state.yaw + angle_delta(rot[1], state.yaw) * k);
            state.elevation += (elevation - state.elevation) * k;
            state.aim += (aim - state.aim) * k;
            state.zoom += (1.0f - state.zoom) * k;
            state.look -= state.look * k;
            state.wall += (1.0f - state.wall) * k;
            if (std::fabs(angle_delta(rot[1], state.yaw)) < ease_done_degrees &&
                std::fabs(elevation - state.elevation) < ease_done_degrees &&
                std::fabs(aim - state.aim) < ease_done_degrees &&
                std::fabs(1.0f - state.zoom) < 0.01f && state.look < ease_done_degrees && state.wall > 0.99f) {
                // Caught up: the game's camera is back in charge.
                state.active = false;
            }
        }
        if (!state.active) {
            state.snap = false;
        }
        if (state.active) {
            const auto speed = std::min<uint32_t>(option<uint32_t>(tooie::free_camera_speed_option, 1), 2);
            const float sx = (option<bool>(tooie::free_camera_invert_x_option, false) != tooie::mirror_mode::active()) ? -stick_x : stick_x;
            const float sy = option<bool>(tooie::free_camera_invert_y_option, false) ? -stick_y : stick_y;
            // Right turns the view right (yaw grows to the left). Up looks up, so the camera drops.
            // C Down held, stick up: closer; down: further. Steps toward the range's limits only.
            if (rb_zoom_input != 0.0f) {
                const float wanted_zoom = state.zoom * std::exp(-rb_zoom_input * rb_zoom_rate * dt);
                state.zoom = std::clamp(wanted_zoom, rb_min_zoom, rb_max_zoom);
            }
            // Mouse wheel: each notch changes the distance by 10%, up zooms in.
            if (wheel_notches != 0) {
                state.zoom = std::clamp(state.zoom * std::pow(0.9f, (float)wheel_notches), min_zoom, max_zoom);
            }
            const bool flip_x = option<bool>(tooie::free_camera_invert_x_option, false) != tooie::mirror_mode::active();
            const float orbit_yaw = flip_x ? -orbit_x : orbit_x;
            const float orbit_pitch = option<bool>(tooie::free_camera_invert_y_option, false) ? -orbit_y : orbit_y;
            state.yaw = wrap_degrees(state.yaw - sx * yaw_speeds[speed] * dt + orbit_yaw);
            const float tilt_input = -sy * yaw_speeds[speed] * pitch_ratio * dt - orbit_pitch;

            // The camera's offset from the pivot, turned about the vertical by the yaw change.
            // Smooth stairs: the orbit height follows Banjo's with an ease, so steps don't bob the camera.
            const float pivot_target = banjo[1] + pivot_height;
            if (!state.has_pivot || !option<bool>(tooie::free_camera_smooth_height_option, true) ||
                std::fabs(pivot_target - state.pivot_y) > pivot_snap) {
                state.pivot_y = pivot_target;
            }
            else {
                state.pivot_y += (pivot_target - state.pivot_y) * ease(pivot_rate, dt);
            }
            state.has_pivot = true;
            const float pivot[3] = { banjo[0], state.pivot_y, banjo[2] };
            const float ox = pos[0] - pivot[0];
            const float oy = pos[1] - pivot[1];
            const float oz = pos[2] - pivot[2];
            const float turn = angle_delta(state.yaw, rot[1]) * deg;
            const float c = std::cos(turn);
            const float s = std::sin(turn);
            const float rx = ox * c + oz * s;
            const float rz = -ox * s + oz * c;

            // Tilted about the horizontal to the held elevation. The game's own camera keeps
            // changing its height and pitch as it chases the spot behind Banjo it wants, so the
            // free camera holds its own elevation and aim instead of following the game's, which
            // tipped the view towards the floor while walking. Pushing on past the lowest tilt
            // slides the camera in towards Banjo, past the highest it pulls out; tilting back
            // reverses that first.
            const float horizontal = std::sqrt(rx * rx + rz * rz);
            const float distance = std::sqrt(horizontal * horizontal + oy * oy);
            const bool look_up = option<bool>(tooie::free_camera_look_up_option, true);
            const float low_limit = look_up ? look_min_elevation : min_elevation;
            float tilt_left = tilt_input;
            // Look-up tilt: a push past the lowest eye height raises the view instead of closing in; tilting
            // back lowers the view first.
            if (look_up && tilt_left > 0.0f && state.look > 0.0f) {
                const float used = std::min(tilt_left, state.look);
                state.look -= used;
                tilt_left -= used;
            }
            if (!look_up) {
                state.look = 0.0f;
            }
            if (tilt_left < 0.0f && state.zoom > 1.0f) {
                const float used = std::max(tilt_left, (1.0f - state.zoom) / zoom_rate);
                state.zoom += used * zoom_rate;
                tilt_left -= used;
            }
            else if (tilt_left > 0.0f && state.zoom < 1.0f) {
                const float used = std::min(tilt_left, (1.0f - state.zoom) / zoom_rate);
                state.zoom += used * zoom_rate;
                tilt_left -= used;
            }
            float wanted = state.elevation + tilt_left;
            if (wanted < low_limit) {
                if (look_up) {
                    state.look += low_limit - wanted;
                }
                else {
                    state.zoom = std::max(min_zoom, state.zoom - (low_limit - wanted) * zoom_rate);
                }
                wanted = low_limit;
            }
            else if (wanted > max_elevation) {
                state.zoom = std::min(max_zoom, state.zoom + (wanted - max_elevation) * zoom_rate);
                wanted = max_elevation;
            }
            state.elevation = wanted;

            float want[3] = { pivot[0] + rx, pivot[1] + oy, pivot[2] + rz };
            if (horizontal > 1.0f && distance > 1.0f) {
                const float d = distance * state.zoom;
                const float h = d * std::cos(wanted * deg);
                want[0] = pivot[0] + rx / horizontal * h;
                want[1] = pivot[1] + d * std::sin(wanted * deg);
                want[2] = pivot[2] + rz / horizontal * h;
            }

            // Pull the camera in front of any wall between Banjo and it, with the game's own camera
            // line test (func_800FAB50(from, to_inout, normal_out, flags, radius), as func_80113640 uses it).
            float hit[3] = { want[0], want[1], want[2] };
            blocked = sweep(rdram, ctx, pivot, hit);
            // A small object near the line stops the wide test but not the view of Banjo: if a thin line
            // from Banjo to the wanted spot is clear, the camera stays there and hovers over it. Banjo is
            // never hidden, because anything between him and the camera stops the thin line too.
            if (blocked && option<bool>(tooie::free_camera_hover_option, true)) {
                float thin[3] = { want[0], want[1], want[2] };
                if (!sweep(rdram, ctx, pivot, thin, nullptr, hover_radius)) {
                    std::memcpy(hit, want, sizeof(hit));
                    blocked = false;
                }
            }
            const float full = std::sqrt((want[0] - pivot[0]) * (want[0] - pivot[0]) +
                (want[1] - pivot[1]) * (want[1] - pivot[1]) + (want[2] - pivot[2]) * (want[2] - pivot[2]));
            if (option<bool>(tooie::free_camera_smooth_walls_option, false) && full > 1.0f) {
                const float reach = std::sqrt((hit[0] - pivot[0]) * (hit[0] - pivot[0]) +
                    (hit[1] - pivot[1]) * (hit[1] - pivot[1]) + (hit[2] - pivot[2]) * (hit[2] - pivot[2]));
                const float target = blocked ? std::clamp(reach / full, 0.0f, 1.0f) : 1.0f;
                if (target < state.wall) {
                    state.wall += (target - state.wall) * ease(wall_in_rate, dt);
                    state.wall = std::min(state.wall, target + wall_lag / full);
                }
                else {
                    state.wall += (target - state.wall) * ease(wall_out_rate, dt);
                }
                for (int i = 0; i < 3; i++) {
                    want[i] = pivot[i] + (want[i] - pivot[i]) * state.wall;
                }
                const float close = full * state.wall;
                fade = std::clamp((close - fade_near) / (fade_far - fade_near), 0.0f, 1.0f);
            }
            else {
                std::memcpy(want, hit, sizeof(want));
                state.wall = 1.0f;
            }

            // Floor clearance (WIP): a low tilt can swing the eye into the floor, so lift it onto the floor
            // under it (the camera line test's resting point is its radius above the surface).
            if (option<bool>(tooie::free_camera_floor_clearance_option, true)) {
                const float from[3] = { want[0], want[1] + floor_probe_up, want[2] };
                float down[3] = { want[0], want[1] - floor_probe_down, want[2] };
                if (sweep(rdram, ctx, from, down) && down[1] > want[1]) {
                    want[1] = down[1];
                }
            }

            // Look-up tilt: the view aims further up, to look_max_pitch, without moving the eye.
            float view_pitch = state.aim - wanted;
            if (state.look > 0.0f) {
                state.look = std::min(state.look, std::max(0.0f, look_max_pitch - view_pitch));
                view_pitch += state.look;
            }

            write_float(rdram, camera + cam_pos + 0, want[0]);
            write_float(rdram, camera + cam_pos + 4, want[1]);
            write_float(rdram, camera + cam_pos + 8, want[2]);
            write_float(rdram, camera + cam_rot + 0, wrap_degrees(view_pitch));
            write_float(rdram, camera + cam_rot + 4, state.yaw);
        }
    }
    // TOOIE_FREECAM_FADE=<0..1> caps Banjo's fade while the free camera is held, to check the faded look headless.
    static const float forced_fade = std::getenv("TOOIE_FREECAM_FADE") ? std::strtof(std::getenv("TOOIE_FREECAM_FADE"), nullptr) : 1.0f;
    if (state.active) {
        fade = std::min(fade, forced_fade);
    }
    player_fade = fade;

    if (log && now - last_log >= std::chrono::milliseconds(250)) {
        last_log = now;
        std::printf("[freecam] map %03X mode %d upd %d paused %d sub %u cam %.0f %.0f %.0f rot %.1f %.1f %.1f banjo %.0f %.0f %.0f stick %.2f %.2f active %d yaw %.1f elev %.1f view %.1f zoom %.2f wall %d state %u speed %.0f easing %d fraction %.2f fade %.2f\n",
            map, mode, updating, paused, submode, pos[0], pos[1], pos[2], rot[0], rot[1], rot[2],
            banjo[0], banjo[1], banjo[2], stick_x, stick_y, state.active, state.yaw, state.elevation, state.aim - state.elevation, state.zoom, blocked,
            player_state, speed, easing, state.wall, fade);
        std::fflush(stdout);
    }
}

bool tooie::free_camera::sweep_line(uint8_t* rdram, recomp_context* ctx, const float from[3], float to[3], float normal[3]) {
    return sweep(rdram, ctx, from, to, normal);
}

extern "C" int tooie_free_camera_player_alpha(int alpha) {
    const float fade = player_fade.load();
    return fade >= 1.0f ? alpha : (int)((float)alpha * fade);
}

void tooie::free_camera::apply_input(uint16_t* buttons) {
    static bool down = false;
    static bool holding = false;
    static int pulse = 0;
    static std::chrono::steady_clock::time_point since;
    const bool tune = wip_option<bool>(tooie::free_camera_rb_distance_option, false);
    const bool physical = (*buttons & n64_r_button) != 0;
    if (!tune || !gameplay_camera.load()) {
        // Passed through as it is; nothing pending.
        down = false;
        holding = false;
        pulse = 0;
        fine_held = false;
        return;
    }
    const auto now = std::chrono::steady_clock::now();
    if (physical && !down) {
        down = true;
        holding = false;
        since = now;
    }
    if (physical) {
        if (!holding && now - since >= tap_limit) {
            holding = true;
        }
        // Kept from the game while it may still be a hold, and for the whole hold.
        *buttons = (uint16_t)(*buttons & ~n64_r_button);
    }
    else if (down) {
        down = false;
        if (!holding) {
            pulse = tap_pulse_reads; // a tap: the game sees a short press now
        }
        holding = false;
    }
    if (!physical && pulse > 0) {
        *buttons = (uint16_t)(*buttons | n64_r_button);
        pulse--;
    }
    fine_held = holding;
}
