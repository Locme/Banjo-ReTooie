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

#include <algorithm>
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
#include "tooie_game.h"
#include "tooie_hooks.h"

namespace {
    // PlayerState pointers by player at 0x80135490; PlayerState +0xE4 points at Banjo's position
    // (func_8009C128 copies it out).
    constexpr uint32_t player_table = 0x80135490;
    constexpr uint32_t player_transform = 0xE4;

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
    constexpr float stick_deadzone = 0.2f;
    // Distance, as a multiple of the game's, reached by pushing on past the tilt limits.
    constexpr float min_zoom = 0.25f;
    constexpr float max_zoom = 1.6f;
    // Zoom change per degree of stick tilt beyond a limit.
    constexpr float zoom_rate = 1.0f / 40.0f;

    // Camera line test flags and radius, as the game's camera uses them (func_80113640).
    constexpr uint32_t sweep_flags = 0x820020;
    constexpr float sweep_radius = 45.0f;

    constexpr float deg = 3.14159265358979f / 180.0f;

    struct State {
        bool active = false;   // the stick has been used and the yaw is held
        float yaw = 0.0f;      // held camera yaw (degrees)
        float pitch_offset = 0.0f; // degrees added to the game's elevation
        float zoom = 1.0f;     // times the game's distance
        uint16_t map = 0xFFFF;
        std::chrono::steady_clock::time_point last;
        bool has_last = false;
    } state;

    bool valid_ptr(uint32_t p) {
        return p >= 0x80000000u && p < 0x80800000u;
    }

    uint32_t read_word(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<uint32_t*>(rdram + (addr - 0x80000000u));
    }

    float read_float(uint8_t* rdram, uint32_t addr) {
        uint32_t bits = read_word(rdram, addr);
        float value;
        std::memcpy(&value, &bits, sizeof(value));
        return value;
    }

    void write_float(uint8_t* rdram, uint32_t addr, float value) {
        uint32_t bits;
        std::memcpy(&bits, &value, sizeof(bits));
        *reinterpret_cast<uint32_t*>(rdram + (addr - 0x80000000u)) = bits;
    }

    int16_t read_half(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<int16_t*>(rdram + ((addr ^ 2) - 0x80000000u));
    }

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

    float deadzone(float v) {
        if (v > stick_deadzone) return (v - stick_deadzone) / (1.0f - stick_deadzone);
        if (v < -stick_deadzone) return (v + stick_deadzone) / (1.0f - stick_deadzone);
        return 0.0f;
    }

    // func_800FAB50(from, to, normal_out, flags, radius on the stack): a swept line test that moves
    // `to` back to where it first hits. Runs it on scratch space below the hook's stack frame.
    bool sweep(uint8_t* rdram, recomp_context* ctx, const float from[3], float to[3]) {
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
        write_float(rdram, sp + 0x10, sweep_radius);
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
            }
        }
        *ctx = saved;
        return hit;
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
}

bool tooie::free_camera::enabled() {
    // TOOIE_FREE_CAMERA=1 turns it on for headless tests without touching the settings.
    static const bool forced = std::getenv("TOOIE_FREE_CAMERA") != nullptr;
    return forced || option<bool>(tooie::free_camera_option, false);
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
    const uint32_t camera = read_word(rdram, ctl + ctl_camera);
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

    // Right stick, up and right positive (SDL's y grows downwards).
    float stick_x = 0.0f;
    float stick_y = 0.0f;
    recompinput::get_right_analog(0, &stick_x, &stick_y);
    stick_y = -stick_y;
    tooie::debug::get_scripted_right_stick(&stick_x, &stick_y);
    stick_x = deadzone(stick_x);
    stick_y = deadzone(stick_y);

    const bool on = tooie::free_camera::enabled();
    const bool gameplay = updating && mode == mode_dynamic && valid_ptr(camera) && valid_ptr(transform) && valid_ptr(dynamic);
    // First person and the like: leave the camera alone but keep the held yaw for afterwards.
    const bool paused = gameplay &&
        (read_byte(rdram, dynamic + dynamic_override) != 0 || read_byte(rdram, dynamic + dynamic_frozen) != 0);
    // While the free camera is on and the game's own camera is running, the right stick
    // is the free camera's, not C buttons.
    recompinput::set_right_analog_suppressed(on && gameplay && !paused);

    if (!on || !gameplay || map != state.map) {
        state.active = false;
        state.map = map;
    }

    bool blocked = false;
    if (on && gameplay && !paused) {
        if (!state.active && (stick_x != 0.0f || stick_y != 0.0f)) {
            state.active = true;
            state.yaw = rot[1];
            state.pitch_offset = 0.0f;
            state.zoom = 1.0f;
        }
        if (state.active) {
            const auto speed = std::min<uint32_t>(option<uint32_t>(tooie::free_camera_speed_option, 1), 2);
            const float sx = option<bool>(tooie::free_camera_invert_x_option, false) ? -stick_x : stick_x;
            const float sy = option<bool>(tooie::free_camera_invert_y_option, false) ? -stick_y : stick_y;
            // Right turns the view right (yaw grows to the left). Up looks up, so the camera drops.
            state.yaw = wrap_degrees(state.yaw - sx * yaw_speeds[speed] * dt);
            const float tilt_input = -sy * yaw_speeds[speed] * pitch_ratio * dt;

            // The camera's offset from the pivot, turned about the vertical by the yaw change.
            const float pivot[3] = { banjo[0], banjo[1] + pivot_height, banjo[2] };
            const float ox = pos[0] - pivot[0];
            const float oy = pos[1] - pivot[1];
            const float oz = pos[2] - pivot[2];
            const float turn = angle_delta(state.yaw, rot[1]) * deg;
            const float c = std::cos(turn);
            const float s = std::sin(turn);
            const float rx = ox * c + oz * s;
            const float rz = -ox * s + oz * c;

            // Tilted about the horizontal. Pushing on past the lowest tilt slides the camera in
            // towards Banjo, past the highest it pulls out; tilting back reverses that first.
            const float horizontal = std::sqrt(rx * rx + rz * rz);
            const float distance = std::sqrt(horizontal * horizontal + oy * oy);
            const float elevation = std::atan2(oy, horizontal) / deg;
            float wanted = elevation + state.pitch_offset;
            float tilt_left = tilt_input;
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
            wanted += tilt_left;
            const float low = std::min(min_elevation, elevation);
            const float high = std::max(max_elevation, elevation);
            if (wanted < low) {
                state.zoom = std::max(min_zoom, state.zoom - (low - wanted) * zoom_rate);
                wanted = low;
            }
            else if (wanted > high) {
                state.zoom = std::min(max_zoom, state.zoom + (wanted - high) * zoom_rate);
                wanted = high;
            }
            state.pitch_offset = wanted - elevation;
            const float tilt = wanted - elevation;

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
            blocked = sweep(rdram, ctx, pivot, want);

            write_float(rdram, camera + cam_pos + 0, want[0]);
            write_float(rdram, camera + cam_pos + 4, want[1]);
            write_float(rdram, camera + cam_pos + 8, want[2]);
            write_float(rdram, camera + cam_rot + 0, wrap_degrees(rot[0] - tilt));
            write_float(rdram, camera + cam_rot + 4, state.yaw);
        }
    }

    if (log && now - last_log >= std::chrono::milliseconds(250)) {
        last_log = now;
        std::printf("[freecam] map %03X mode %d upd %d paused %d sub %u cam %.0f %.0f %.0f rot %.1f %.1f %.1f banjo %.0f %.0f %.0f stick %.2f %.2f active %d yaw %.1f pitch+ %.1f zoom %.2f wall %d\n",
            map, mode, updating, paused, submode, pos[0], pos[1], pos[2], rot[0], rot[1], rot[2],
            banjo[0], banjo[1], banjo[2], stick_x, stick_y, state.active, state.yaw, state.pitch_offset, state.zoom, blocked);
        std::fflush(stdout);
    }
}
