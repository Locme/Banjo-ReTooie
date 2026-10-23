// Mouse and gyro aiming (handoff 4.58 and 4.59).
//
// In first person (C-up) the game keeps the view's angles in degrees in the dynamic camera (camera
// controller +0x04, see src/gameplay/free_camera.cpp): +0xBC pitch (0 to 360, positive looks up,
// 297 is 63 down) and +0xC0 yaw (positive turns left), and turns them with the stick each frame.
// Banjo's own yaw and the picture follow them. Found by diffing RDRAM while turning (TOOIE_RAMDUMP)
// and checked by writing them headless; 0x8012CEA8 / 0x8012CEAC and the viewport camera are copies
// the game rewrites each frame. Mouse and gyro motion is added to them straight, so the view moves
// with the hand instead of at a stick's speed. The stick still works as before.
//
// Strength comes from the General tab's Mouse Sensitivity and Gyro Sensitivity, which RecompFrontend
// already has (0 turns each off; any other mouse value also locks the cursor to the window while the
// game runs). QOL > "Mouse and gyro aim: invert up/down" flips the vertical.
//
// TOOIE_AIM_TEST=<dx>,<dy>,<from ms>,<to ms> adds that mouse motion (pixels) to every pad read in that
// window, for headless runs. TOOIE_AIM_LOG=1 logs the angles.

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <mutex>
#include <variant>

#include "recomp.h"
#include "recompui/config.h"
#include "recompinput/input_state.h"
#include "tooie_fine_aim.h"
#include "tooie_free_camera.h"
#include "tooie_game.h"
#include "tooie_motion_aim.h"

namespace {
    // Camera controller +0x04: the dynamic camera, whose first-person view angles are at +0xBC (pitch)
    // and +0xC0 (yaw).
    constexpr uint32_t dynamic_offset = 0x04;
    constexpr uint32_t fp_pitch = 0xBC;
    constexpr uint32_t fp_yaw = 0xC0;
    // The steepest the game's own stick aim goes (measured headless).
    constexpr float pitch_down_limit = -68.0f;
    constexpr float pitch_up_limit = 70.0f;
    // Degrees per pixel of mouse motion at 100% sensitivity.
    constexpr float mouse_degrees_per_pixel = 0.4f;
    // Gyro deltas are degrees the controller turned (RecompFrontend patch), scaled 4x so the
    // default 25% turns the view as far as the controller turns.
    constexpr float gyro_scale = 4.0f;

    std::mutex pending_mutex;
    float pending_yaw = 0.0f;
    // The same motion, kept for the free camera's orbit (drained by take_orbit).
    float orbit_mouse_yaw = 0.0f;
    float orbit_mouse_pitch = 0.0f;
    float orbit_gyro_yaw = 0.0f;
    float orbit_gyro_pitch = 0.0f;
    float pending_pitch = 0.0f;

    struct Test {
        bool on = false;
        float dx = 0, dy = 0;
        long from = 0, to = 0;
        std::chrono::steady_clock::time_point begin;
    } test;

    std::once_flag test_flag;

    // The angles this tick left the view at, so the next tick can see how far the game turned it.
    bool have_last = false;
    float last_yaw = 0.0f;
    float last_pitch = 0.0f;

    // Wraps an angle difference into -180..180.
    float wrap_delta(float d) {
        d = std::fmod(d + 180.0f, 360.0f);
        return (d < 0.0f ? d + 360.0f : d) - 180.0f;
    }

    bool valid_ptr(gpr p) {
        return (uint32_t)p >= 0x80000000u && (uint32_t)p < 0x81000000u;
    }

    float read_float(uint8_t* rdram, gpr addr) {
        uint32_t u = (uint32_t)MEM_W(0, addr);
        float f;
        std::memcpy(&f, &u, 4);
        return f;
    }

    void write_float(uint8_t* rdram, gpr addr, float f) {
        uint32_t u;
        std::memcpy(&u, &f, 4);
        MEM_W(0, addr) = (int32_t)u;
    }

    bool invert_y() {
        try {
            return std::get<bool>(recompui::config::get_config(tooie::qol_tab_id).get_option_value(tooie::motion_aim::invert_y_option));
        } catch (...) {
            return false;
        }
    }
}

void tooie::motion_aim::add_options(recomp::config::Config& qol) {
    qol.add_bool_option(invert_y_option, "Mouse And Gyro Aim: Invert Up/Down",
        "In first person, moving the mouse or tilting the controller up looks down instead. "
        "The strength of each is General > Mouse Sensitivity and Gyro Sensitivity.", false);
}

void tooie::motion_aim::collect() {
    std::call_once(test_flag, [] {
        if (const char* v = std::getenv("TOOIE_AIM_TEST")) {
            test.on = std::sscanf(v, "%f,%f,%ld,%ld", &test.dx, &test.dy, &test.from, &test.to) == 4;
            test.begin = std::chrono::steady_clock::now();
        }
    });

    float mx = 0.0f, my = 0.0f, gx = 0.0f, gy = 0.0f;
    if (recompui::config::general::has_mouse_sensitivity_option()) {
        recompinput::get_mouse_deltas(&mx, &my);
    }
    if (recompui::config::general::has_gyro_sensitivity_option()) {
        recompinput::get_gyro_deltas(0, &gx, &gy);
    }
    if (test.on) {
        long ms = (long)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - test.begin).count();
        if (ms >= test.from && ms < test.to) {
            mx += test.dx;
            my += test.dy;
        }
    }

    // get_mouse_deltas has applied the sensitivity already (pixels * percent / 100); so has get_gyro_deltas.
    // Gyro x is the pitch (front of the controller up is positive) and y the yaw (left is positive),
    // the same senses as the view's angles.
    std::lock_guard lock{ pending_mutex };
    const float yaw = -mx * mouse_degrees_per_pixel + gy * gyro_scale;
    const float pitch = -my * mouse_degrees_per_pixel + gx * gyro_scale;
    pending_yaw += yaw;
    pending_pitch += pitch;
    auto add = [](float& total, float delta) { total = std::clamp(total + delta, -360.0f, 360.0f); };
    add(orbit_mouse_yaw, -mx * mouse_degrees_per_pixel);
    add(orbit_mouse_pitch, -my * mouse_degrees_per_pixel);
    add(orbit_gyro_yaw, gy * gyro_scale);
    add(orbit_gyro_pitch, gx * gyro_scale);
}

void tooie::motion_aim::take_orbit(float* mouse_yaw, float* mouse_pitch, float* gyro_yaw, float* gyro_pitch) {
    std::lock_guard lock{ pending_mutex };
    *mouse_yaw = orbit_mouse_yaw;
    *mouse_pitch = orbit_mouse_pitch;
    *gyro_yaw = orbit_gyro_yaw;
    *gyro_pitch = orbit_gyro_pitch;
    orbit_mouse_yaw = orbit_mouse_pitch = orbit_gyro_yaw = orbit_gyro_pitch = 0.0f;
}

void tooie::motion_aim::tick(uint8_t* rdram, recomp_context* ctx) {
    (void)ctx;
    float yaw_delta, pitch_delta;
    {
        std::lock_guard lock{ pending_mutex };
        yaw_delta = pending_yaw;
        pitch_delta = pending_pitch;
        pending_yaw = 0.0f;
        pending_pitch = 0.0f;
    }
    if (!tooie::fine_aim::in_first_person()) {
        have_last = false;
        return;
    }
    if (invert_y()) {
        pitch_delta = -pitch_delta;
    }

    const gpr ctl = (gpr)(int32_t)tooie::free_camera::last_controller();
    if (!valid_ptr(ctl)) {
        have_last = false;
        return;
    }
    const gpr dynamic = (gpr)(int32_t)MEM_W(dynamic_offset, ctl);
    if (!valid_ptr(dynamic)) {
        have_last = false;
        return;
    }

    static const bool log = std::getenv("TOOIE_AIM_LOG") != nullptr;
    // Pitch is kept from 0 to 360 (297 is 63 degrees down).
    float pitch = read_float(rdram, dynamic + fp_pitch);
    float yaw = read_float(rdram, dynamic + fp_yaw);
    // Fine aim: the game turned the view by (angle - last) with the stick since the last tick. Take
    // back the unwanted part of that turn. Scaling the stick instead barely slows the game's turning.
    const float fine = tooie::fine_aim::view_scale();
    if (have_last && fine < 1.0f) {
        yaw_delta += wrap_delta(yaw - last_yaw) * (fine - 1.0f);
        pitch_delta += wrap_delta(pitch - last_pitch) * (fine - 1.0f);
    }
    if (yaw_delta != 0.0f || pitch_delta != 0.0f) {
        yaw = std::fmod(yaw + yaw_delta, 360.0f);
        if (yaw < 0.0f) {
            yaw += 360.0f;
        }
        float signed_pitch = pitch > 180.0f ? pitch - 360.0f : pitch;
        signed_pitch = std::clamp(signed_pitch + pitch_delta, pitch_down_limit, pitch_up_limit);
        pitch = signed_pitch < 0.0f ? signed_pitch + 360.0f : signed_pitch;
        write_float(rdram, dynamic + fp_yaw, yaw);
        write_float(rdram, dynamic + fp_pitch, pitch);
    }
    have_last = true;
    last_yaw = yaw;
    last_pitch = pitch;
    if (log) {
        fprintf(stderr, "[aim] pitch %.1f yaw %.1f (+%.2f, +%.2f)\n", pitch, yaw, pitch_delta, yaw_delta);
    }
}
