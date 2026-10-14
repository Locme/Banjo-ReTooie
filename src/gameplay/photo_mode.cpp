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
// pitch / yaw (+0x18, +0x1C, degrees) after the game's camera has updated. Facing: yaw 0 looks
// along -z, the yaw grows turning left, and a positive pitch looks up.
//
// Input: while photo mode is on, player 1's pad goes to the camera and the game reads an idle pad.
//   left stick      move (forward, back, sideways)
//   right stick     look (C-buttons on the keyboard)
//   Z / R           down / up
//   L               faster (holding a move for a second speeds it up too)
//   A               screenshot (as F12)
//   D-pad up        HUD on / off
//   D-pad down      orbit Banjo (the sticks circle him, Z / R move closer and further) / fly freely
//   D-pad left/right zoom out / in (the field of view, through tooie_set_fov)
//   Start           frozen, 1/8 speed, 1/4 speed
//   B / Photo Mode  back to the game, with the camera and HUD as they were
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
#include "tooie_screenshot.h"
#include "tooie_toast.h"

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
    std::atomic<float> fov_scale{1.0f};

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

    void enter(uint8_t* rdram) {
        is_active = true;
        speed = 0;
        fov_scale = 1.0f;
        orbit_toggle = false;
        cam.placed = false;
        cam.orbit = false;
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
        tooie::toast::show("Photo mode: A photo, B back, Start time");
        fprintf(stderr, "[photo] on\n");
    }

    void leave() {
        is_active = false;
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
        "Left stick moves, right stick looks, Z and R go down and up, L goes faster, A takes a screenshot, "
        "D-pad up shows the HUD, D-pad down circles Banjo, D-pad left and right zoom, "
        "Start runs time at 1/8 or 1/4 speed, B goes back to the game.");
    recompinput::set_default_mapping_for_keyboard(photo_input, { recompinput::InputField::keyboard(SDL_SCANCODE_F10) });
    recompinput::set_default_mapping_for_controller(photo_input, { recompinput::InputField::controller_digital(SDL_CONTROLLER_BUTTON_MISC1) });
}

void tooie::photo_mode::start() {
    std::call_once(started, [] {
        if (const char* v = std::getenv("TOOIE_PHOTO")) {
            test.active = std::sscanf(v, "%ld:%ld", &test.on, &test.off) == 2;
        }
        std::thread(worker).detach();
    });
}

bool tooie::photo_mode::active() {
    return is_active;
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
        tooie::hide_hud::set_hidden(!tooie::hide_hud::is_hidden());
    }
    if (pressed & d_down) {
        orbit_toggle = true;
    }
    if (pressed & button_start) {
        int s = (speed + 1) % 3;
        speed = s;
        tooie::toast::show(speed_names[s]);
    }
    *buttons = 0;
    *x = 0.0f;
    *y = 0.0f;
}

void tooie::photo_mode::tick(uint8_t* rdram, recomp_context* ctx) {
    (void)ctx;
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
    const float zoom = (p.buttons & d_left ? 1.0f : 0.0f) - (p.buttons & d_right ? 1.0f : 0.0f);
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
        tooie::toast::show(cam.orbit ? "Orbit Banjo" : "Free camera");
    }
    const float move_x = deadzone(p.x);
    const float move_y = deadzone(p.y);
    const float rise = (p.buttons & button_r ? 1.0f : 0.0f) - (p.buttons & button_z ? 1.0f : 0.0f);

    const bool moving = move_x != 0.0f || move_y != 0.0f || rise != 0.0f;
    if (moving && !cam.moving) {
        cam.moving_since = now;
    }
    cam.moving = moving;
    const bool fast = (p.buttons & button_l) || (moving && now - cam.moving_since >= 1s);
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
    write_float(rdram, camera + cam_rot + 8, 0.0f);

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
