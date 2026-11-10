// Water camera (QOL tab): seven touches to the camera in and around water, each with its own toggle under one
// switch. They work on whichever camera placed the view this step, the game's or the free camera, and leave
// first person, cutscenes and Photo Mode alone (the free camera's hook only calls apply() in play).
//
// - Off the waterline: the camera never rests right on the water's surface, where the picture is half above and
//   half below and the underwater look flickers; it is kept a little above or below and glides across quickly.
// - Smooth splash: for half a second after Banjo lands in the water the camera eases after him, so the plunge
//   doesn't jerk it.
// - Surface bob: while Banjo floats on the surface the camera rises and falls gently.
// - Underwater drag: under water the camera follows a little more slowly and softly, as if through water.
// - Follow the torpedo: while Kazooie is a Talon Torpedo the camera follows her instead of staying back by Banjo.
// - Torpedo pull-back: as the Talon Torpedo speeds up the camera drops back a little and the view widens.
// - Look up under water: the free camera can go further below Banjo under water, to look up at the surface.
//
// Banjo's water states and the surface height come the same way as the underwater look in
// src/display/picture_filters.cpp: the surface is where he floats, or where he went in.

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <variant>

#include "recomp.h"
#include "recompui/config.h"
#include "librecomp/config.hpp"

#include "tooie_debug.h"
#include "tooie_free_camera.h"
#include "tooie_game.h"
#include "tooie_rdram.h"
#include "tooie_water_camera.h"

namespace RT64 {
    // The height of the camera the 3D world was last drawn from (rt64-ext), for the log.
    bool GetSceneCameraHeight(float* height);
}

namespace {
    using tooie::rdram::read_float;
    using tooie::rdram::read_word;
    using tooie::rdram::valid_ptr;
    using tooie::rdram::write_float;

    constexpr uint32_t game_delta_time = 0x8012C760;
    constexpr uint32_t player_table = 0x80135490;
    // While Kazooie torpedoes, Banjo stays in slot 0 and does not move; she gets the next slot (0x80135494), in a
    // PlayerState made anew for each torpedo (measured 2026-11-10).
    constexpr uint32_t kazooie_slot = player_table + 4;
    constexpr uint32_t player_transform = 0xE4;  // PlayerState -> position (x, y, z)
    constexpr uint32_t player_physics = 0xC8;    // PlayerState -> physics block; its +0x10 is the velocity
    constexpr uint32_t physics_velocity = 0x10;
    // Added to the camera's field of view for one frame and then cleared by the camera update (func_800C54F0:
    // field of view = its base + this); the underwater wobble adds to it the same way (func_800C4B90).
    constexpr uint32_t fov_add = 0x8012AA1C;
    constexpr uint32_t current_camera = 0x8012D500;   // points at the camera the picture is drawn from
    constexpr uint32_t player_yaw_ptr = 0xF8;         // PlayerState +0xF8 points at the yaw (degrees, 0 faces +z)
    constexpr float deg = 3.14159265f / 180.0f;
    constexpr uint32_t cam_pos = 0x00;
    constexpr uint32_t cam_rot = 0x18;           // pitch, yaw, roll in degrees

    // Banjo's states in the water (src/display/picture_filters.cpp): 45 floating on the surface, 46 swimming on
    // it, 48 starting a dive, 57 swimming under water, 43 still under water, 76 plunging in from a fall, 61 coming
    // out of the plunge. The Talon Torpedo: 343 winding up, 237 shooting along (measured 2026-11-10).
    bool on_surface(uint32_t s) { return s == 45 || s == 46; }
    bool torpedo(uint32_t s) { return s == 237 || s == 343; }
    bool in_water(uint32_t s) {
        return on_surface(s) || s == 48 || s == 57 || s == 43 || s == 76 || s == 61 || torpedo(s);
    }
    bool submerged(uint32_t s) { return in_water(s) && !on_surface(s); }
    // Atlantis and the Sea Bottom in Jolly Roger's Lagoon are under water from end to end: no surface.
    bool whole_level_under_water(uint16_t map) { return map == 0x1A8 || map == 0x1A9; }

    // How far the camera is kept from the surface, and how fast it glides across it.
    constexpr float waterline_gap = 30.0f;
    constexpr float waterline_glide_rate = 15.0f;
    // How fast the surface height eases after Banjo as he floats (per second).
    constexpr float surface_rate = 2.0f;
    // The splash ease: how long, and how fast the camera catches up meanwhile (per second).
    constexpr float splash_time = 0.5f;
    constexpr float splash_rate = 14.0f;
    // Under water the camera catches up at this rate (per second).
    constexpr float drag_rate = 9.0f;
    // A camera jump bigger than this in one step is a cut or a teleport, taken at once.
    constexpr float cut_distance = 400.0f;
    // The surface bob: height (units) and the time of one rise and fall (seconds); it fades in and out at
    // bob_fade_rate per second.
    constexpr float bob_height = 5.0f;
    constexpr float bob_period = 2.6f;
    constexpr float bob_fade_rate = 2.0f;
    // The torpedo: no pull-back at its cruising speed (150), all of it at its kick (about 417). At most it drops
    // back this far and widens the view by this many degrees, easing in and out at these rates per second.
    constexpr float torpedo_cruise = 150.0f;
    constexpr float torpedo_kick = 417.0f;
    constexpr float torpedo_back = 160.0f;
    constexpr float torpedo_fov = 8.0f;
    constexpr float torpedo_in_rate = 4.0f;
    constexpr float torpedo_out_rate = 2.0f;
    // Follow the torpedo: how far behind Kazooie and above her the camera sits, how far ahead of her it looks, how
    // fast it eases after her place and her way (per second), and how fast it hands over to and from the game's camera.
    constexpr float follow_distance = 260.0f;
    constexpr float follow_height = 60.0f;
    constexpr float follow_look_ahead = 120.0f;
    constexpr float follow_rate = 8.0f;
    constexpr float follow_turn_rate = 6.0f;
    // The view turns to look at her faster than the eye moves, since the eye already eases after her way; with
    // both at 8 the two lags added up and she slid to the edge of the picture in a hard turn.
    constexpr float follow_look_rate = 16.0f;
    constexpr float follow_blend_rate = 3.0f;
    // How steeply the follow camera tips with her climb or dive, at most (the sine of the angle, about 50 degrees).
    constexpr float follow_max_climb = 0.75f;
    // Banjo's middle above his feet, and how far from it the follow camera is kept.
    constexpr float banjo_middle = 50.0f;
    constexpr float banjo_clearance = 110.0f;
    // The wall test starts this far above Kazooie, and a hit puts the eye this far short of the wall.
    constexpr float follow_wall_lift = 10.0f;
    constexpr float follow_wall_gap = 15.0f;

    struct State {
        uint16_t map = 0xFFFF;
        uint32_t camera = 0;
        float surface = 0.0f;
        bool has_surface = false;
        float out_of_water = 0.0f;    // seconds since Banjo was last in a water state
        bool was_in_water = false;
        float splash = 0.0f;          // seconds of splash ease left
        bool has_smooth = false;
        float smooth[3] = { 0, 0, 0 };
        float smooth_rot[2] = { 0, 0 };
        int side = 0;                 // waterline: +1 above, -1 below, 0 unknown
        float glide = 0.0f;           // waterline: the jump left to glide out of the crossing
        float bob_fade = 0.0f;
        float clock = 0.0f;
        float pull = 0.0f;
        float way[3] = { 0, 0, 0 };   // the torpedo's eased direction of travel
        float target[3] = { 0, 0, 0 };   // where Kazooie was last step
        bool has_target = false;
        float follow_blend = 0.0f;    // 0 the game's camera, 1 the follow camera
        float follow_eye[3] = { 0, 0, 0 };
        float follow_rot[2] = { 0, 0 };
        bool has_follow = false;
        float face = 0.0f;            // the way Kazooie faces (degrees), for the log
        bool walled = false;          // the follow camera was brought in front of a wall this step, for the log
        int wall_hits = 0;            // steps the wall test moved the eye, for the log
        float log_clock = 0.0f;
    };
    // One state per camera: some moves step two cameras each frame (the Talon Torpedo steps Banjo's, which stays
    // put, and the one that chases Kazooie), and each eases on its own.
    constexpr int max_cameras = 4;
    State states[max_cameras];
    int next_slot = 0;

    State& state_for(uint32_t camera, uint16_t map) {
        for (State& s : states) {
            if (s.camera == camera && s.map == map) {
                return s;
            }
        }
        State& s = states[next_slot];
        next_slot = (next_slot + 1) % max_cameras;
        s = State{};
        s.camera = camera;
        s.map = map;
        return s;
    }

    bool option(const std::string& id, bool fallback) {
        try {
            return std::get<bool>(recompui::config::get_config(tooie::qol_tab_id).get_option_value(id));
        } catch (...) {
            return fallback;
        }
    }

    // A player's yaw in degrees, 0 when it can't be read.
    float player_yaw(uint8_t* rdram, uint32_t player) {
        const uint32_t yaw = valid_ptr(player) ? read_word(rdram, player + player_yaw_ptr) : 0;
        return valid_ptr(yaw) ? read_float(rdram, yaw) : 0.0f;
    }

    // Kazooie's position while she torpedoes; false when her slot is empty.
    bool kazooie_position(uint8_t* rdram, uint32_t kazooie, float out[3]) {
        const uint32_t transform = valid_ptr(kazooie) ? read_word(rdram, kazooie + player_transform) : 0;
        if (!valid_ptr(transform)) {
            return false;
        }
        for (int i = 0; i < 3; i++) {
            out[i] = read_float(rdram, transform + 4 * i);
        }
        return true;
    }

    float ease(float rate, float dt) {
        return 1.0f - std::exp(-rate * dt);
    }

    float angle_delta(float to, float from) {
        float d = std::fmod(to - from, 360.0f);
        if (d > 180.0f) d -= 360.0f;
        if (d < -180.0f) d += 360.0f;
        return d;
    }

    float wrap(float a) {
        a = std::fmod(a, 360.0f);
        return a < 0.0f ? a + 360.0f : a;
    }

    float distance(const float a[3], const float b[3]) {
        const float dx = a[0] - b[0], dy = a[1] - b[1], dz = a[2] - b[2];
        return std::sqrt(dx * dx + dy * dy + dz * dz);
    }
}

void tooie::water_camera::add_options(recomp::config::Config& qol) {
    qol.add_bool_option(
        tooie::water_camera_option,
        "Water Camera",
        "Touches to the camera in and around water. Each one can be switched off below.",
        true);
    qol.add_bool_option(
        tooie::water_camera_waterline_option,
        "Off the Waterline",
        "The camera never rests right on the water's surface, where the picture is half above and half below the water. It stays a little above or below and glides across quickly.",
        true);
    qol.add_bool_option(
        tooie::water_camera_splash_option,
        "Smooth Splash",
        "For half a second after Banjo lands in the water, the camera eases after him instead of jerking with the plunge.",
        true);
    qol.add_bool_option(
        tooie::water_camera_bob_option,
        "Surface Bob",
        "While Banjo floats on the surface, the camera rises and falls gently with him.",
        true);
    qol.add_bool_option(
        tooie::water_camera_drag_option,
        "Underwater Drag",
        "Under water, the camera follows Banjo a little more slowly and softly, as if moving through water.",
        true);
    qol.add_bool_option(
        tooie::water_camera_follow_option,
        "Follow the Torpedo",
        "While Kazooie is a Talon Torpedo, the camera follows her from behind, turning as she turns, instead of staying back by Banjo.",
        true);
    qol.add_bool_option(
        tooie::water_camera_torpedo_option,
        "Torpedo Pull-Back",
        "As the Talon Torpedo speeds up, the camera drops back a little and the view widens, then settles as it slows.",
        true);
    qol.add_bool_option(
        tooie::water_camera_look_up_option,
        "Look Up Under Water",
        "Under water, the free camera can go further below Banjo, so you can look up at the surface.",
        true);
}

bool tooie::water_camera::under_water(uint32_t player_state) {
    return submerged(player_state);
}

bool tooie::water_camera::look_up_under_water(uint32_t player_state) {
    return option(tooie::water_camera_option, true) && option(tooie::water_camera_look_up_option, true) &&
        submerged(player_state);
}

void tooie::water_camera::apply(uint8_t* rdram, recomp_context* ctx, uint32_t camera, uint32_t player_state,
    const float banjo[3]) {
    if (!valid_ptr(camera)) {
        return;
    }
    const uint16_t map = tooie::debug::current_map(rdram);
    State& state = state_for(camera, map);
    const bool on = option(tooie::water_camera_option, true);
    const float dt = std::clamp(read_float(rdram, game_delta_time), 0.0f, 0.1f);
    state.clock = std::fmod(state.clock + dt, bob_period * 1000.0f);

    float p[3], rot[2];
    for (int i = 0; i < 3; i++) {
        p[i] = read_float(rdram, camera + cam_pos + 4 * i);
    }
    rot[0] = read_float(rdram, camera + cam_rot + 0);
    rot[1] = read_float(rdram, camera + cam_rot + 4);

    // The water: the surface is where Banjo floats, or where he went in; kept for a second after he leaves it.
    const bool water = in_water(player_state);
    if (water) {
        // He bobs a few units as he floats; the surface eases after him so the camera held off it doesn't bob too.
        if (!state.was_in_water && !state.has_surface) {
            state.surface = banjo[1];
            state.has_surface = !whole_level_under_water(map);
        }
        else if (on_surface(player_state)) {
            state.surface += (banjo[1] - state.surface) * ease(surface_rate, dt);
            state.has_surface = !whole_level_under_water(map);
        }
        if (!state.was_in_water) {
            state.splash = splash_time;
        }
        state.out_of_water = 0.0f;
    }
    else {
        state.out_of_water += dt;
        if (state.out_of_water > 1.0f) {
            state.has_surface = false;
            state.side = 0;
        }
    }
    state.was_in_water = water;
    state.splash = std::max(0.0f, state.splash - dt);

    // Smooth splash and underwater drag: the camera eases after where the game put it. A cut or teleport is
    // taken at once. The angles are written back only while they are eased.
    bool eased = false;
    if (!state.has_smooth || distance(p, state.smooth) > cut_distance) {
        std::copy(p, p + 3, state.smooth);
        state.smooth_rot[0] = rot[0];
        state.smooth_rot[1] = rot[1];
        state.has_smooth = true;
    }
    else {
        float k = 1.0f;
        if (on && option(tooie::water_camera_splash_option, true) && state.splash > 0.0f) {
            // Fades out over the half second, so the camera hands back to the game smoothly.
            const float weight = state.splash / splash_time;
            k = std::min(k, 1.0f - weight * (1.0f - ease(splash_rate, dt)));
        }
        if (on && option(tooie::water_camera_drag_option, true) && (submerged(player_state) || whole_level_under_water(map))) {
            k = std::min(k, ease(drag_rate, dt));
        }
        eased = k < 1.0f;
        for (int i = 0; i < 3; i++) {
            state.smooth[i] += (p[i] - state.smooth[i]) * k;
        }
        state.smooth_rot[0] = wrap(state.smooth_rot[0] + angle_delta(rot[0], state.smooth_rot[0]) * k);
        state.smooth_rot[1] = wrap(state.smooth_rot[1] + angle_delta(rot[1], state.smooth_rot[1]) * k);
    }
    std::copy(state.smooth, state.smooth + 3, p);
    rot[0] = state.smooth_rot[0];
    rot[1] = state.smooth_rot[1];

    // Follow the torpedo: while Kazooie torpedoes (Banjo waits in slot 0, she is in the next) the game's camera
    // stays back by Banjo and she soon swims out of sight. The camera shown (0x8012D500) is put behind her
    // instead, along the way she is going, looking a little ahead of her, and eases in and out of it. Torpedo
    // pull-back drops it further back and widens the view as she speeds up.
    const uint32_t kazooie = read_word(rdram, kazooie_slot);
    float kaz[3] = { banjo[0], banjo[1], banjo[2] };
    const bool torpedoing = on && player_state == 237 && camera == read_word(rdram, current_camera) &&
        kazooie_position(rdram, kazooie, kaz);
    const bool follow = torpedoing && option(tooie::water_camera_follow_option, true);
    float vel[3] = { 0, 0, 0 };
    float speed = 0.0f;
    if (torpedoing) {
        const uint32_t physics = read_word(rdram, kazooie + player_physics);
        if (valid_ptr(physics)) {
            for (int i = 0; i < 3; i++) vel[i] = read_float(rdram, physics + physics_velocity + 4 * i);
            speed = std::sqrt(vel[0] * vel[0] + vel[1] * vel[1] + vel[2] * vel[2]);
        }
        // Her way: across, the way she faces, which is what the stick steers and stays steady as she shoots off
        // (her path curls round on the launch, and following it swung the camera half round in a quarter
        // second); up and down, how steeply she climbs or dives.
        const float face = player_yaw(rdram, kazooie) * deg;
        const float climb = speed > 30.0f ? std::clamp(vel[1] / speed, -follow_max_climb, follow_max_climb) : 0.0f;
        const float level = std::sqrt(1.0f - climb * climb);
        const float want_way[3] = { std::sin(face) * level, climb, std::cos(face) * level };
        const float k = state.has_target ? ease(follow_turn_rate, dt) : 1.0f;
        for (int i = 0; i < 3; i++) state.way[i] += (want_way[i] - state.way[i]) * k;
        std::copy(kaz, kaz + 3, state.target);
        state.has_target = true;
        state.face = face / deg;
    }
    else {
        state.has_target = false;
    }

    // Pull-back: by her speed past cruising.
    float want = 0.0f;
    if (torpedoing && option(tooie::water_camera_torpedo_option, true)) {
        want = std::clamp((speed - torpedo_cruise) / (torpedo_kick - torpedo_cruise), 0.0f, 1.0f);
    }
    state.pull += (want - state.pull) * ease(want > state.pull ? torpedo_in_rate : torpedo_out_rate, dt);

    state.follow_blend = std::clamp(state.follow_blend + (follow ? dt : -dt) * follow_blend_rate, 0.0f, 1.0f);
    if (state.follow_blend > 0.0f && state.has_target) {
        float way[3] = { state.way[0], state.way[1], state.way[2] };
        float len = std::sqrt(way[0] * way[0] + way[1] * way[1] + way[2] * way[2]);
        if (len < 0.01f) {
            way[0] = 0.0f; way[1] = 0.0f; way[2] = 1.0f; len = 1.0f;
        }
        for (float& w : way) w /= len;
        // TOOIE_WATERCAM_FOLLOW_DISTANCE=<units> sets the distance behind her, to test the wall test headless.
        static const float distance_setting = std::getenv("TOOIE_WATERCAM_FOLLOW_DISTANCE") ?
            std::strtof(std::getenv("TOOIE_WATERCAM_FOLLOW_DISTANCE"), nullptr) : follow_distance;
        const float back = distance_setting + state.pull * torpedo_back;
        const float eye[3] = { state.target[0] - way[0] * back, state.target[1] - way[1] * back + follow_height,
            state.target[2] - way[2] * back };
        if (!state.has_follow) {
            std::copy(p, p + 3, state.follow_eye);
            state.follow_rot[0] = rot[0];
            state.follow_rot[1] = rot[1];
            state.has_follow = true;
        }
        const float k = ease(follow_rate, dt);
        for (int i = 0; i < 3; i++) state.follow_eye[i] += (eye[i] - state.follow_eye[i]) * k;

        // Banjo waits where she set off, right behind her for the first moment: the eye is kept outside a ball
        // round him, so it goes over him instead of through him.
        float shown[3] = { state.follow_eye[0], state.follow_eye[1], state.follow_eye[2] };
        const float body[3] = { banjo[0], banjo[1] + banjo_middle, banjo[2] };
        float off[3] = { shown[0] - body[0], shown[1] - body[1], shown[2] - body[2] };
        float off_len = std::sqrt(off[0] * off[0] + off[1] * off[1] + off[2] * off[2]);
        if (off_len < banjo_clearance) {
            if (off_len < 1.0f) {
                off[0] = 0.0f; off[1] = 1.0f; off[2] = 0.0f; off_len = 1.0f;
            }
            for (int i = 0; i < 3; i++) shown[i] = body[i] + off[i] / off_len * banjo_clearance;
        }
        // Walls: the game's camera line test from Kazooie out to the eye (the free camera's, func_800FAB50) brings
        // the eye in front of any rock between them, a little short of it.
        const float from[3] = { state.target[0], state.target[1] + follow_wall_lift, state.target[2] };
        float hit[3] = { shown[0], shown[1], shown[2] };
        if (ctx != nullptr && tooie::free_camera::sweep_line(rdram, ctx, from, hit, nullptr)) {
            float in[3] = { from[0] - hit[0], from[1] - hit[1], from[2] - hit[2] };
            const float in_len = std::sqrt(in[0] * in[0] + in[1] * in[1] + in[2] * in[2]);
            const float step = std::min(follow_wall_gap, in_len * 0.5f);
            for (int i = 0; i < 3; i++) shown[i] = hit[i] + (in_len > 0.01f ? in[i] / in_len * step : 0.0f);
            state.walled = true;
            state.wall_hits++;
        }
        else {
            state.walled = false;
        }

        // It looks a little ahead of her, from where the eye ends up. The camera's yaw points back the way it
        // looks (a camera behind Banjo facing 95 degrees has yaw 275), and looking down is a pitch just under 360.
        const float look[3] = { state.target[0] + way[0] * follow_look_ahead - shown[0],
            state.target[1] + way[1] * follow_look_ahead - shown[1], state.target[2] + way[2] * follow_look_ahead - shown[2] };
        const float look_yaw = wrap(std::atan2(look[0], look[2]) / deg + 180.0f);
        const float look_pitch = wrap(std::atan2(look[1], std::sqrt(look[0] * look[0] + look[2] * look[2])) / deg);
        const float look_k = ease(follow_look_rate, dt);
        state.follow_rot[0] = wrap(state.follow_rot[0] + angle_delta(look_pitch, state.follow_rot[0]) * look_k);
        state.follow_rot[1] = wrap(state.follow_rot[1] + angle_delta(look_yaw, state.follow_rot[1]) * look_k);
        const float b = state.follow_blend * state.follow_blend * (3.0f - 2.0f * state.follow_blend);
        for (int i = 0; i < 3; i++) p[i] += (shown[i] - p[i]) * b;
        rot[0] = wrap(rot[0] + angle_delta(state.follow_rot[0], rot[0]) * b);
        rot[1] = wrap(rot[1] + angle_delta(state.follow_rot[1], rot[1]) * b);
        eased = true;
        if (state.pull > 0.001f) {
            write_float(rdram, fov_add, read_float(rdram, fov_add) + state.pull * torpedo_fov * b);
        }
    }
    else {
        state.has_follow = false;
        if (torpedoing && state.pull > 0.001f) {
            write_float(rdram, fov_add, read_float(rdram, fov_add) + state.pull * torpedo_fov);
        }
    }

    // Surface bob, faded in while he floats.
    const bool bob = on && option(tooie::water_camera_bob_option, true) && on_surface(player_state) && state.has_surface;
    state.bob_fade = std::clamp(state.bob_fade + (bob ? dt : -dt) * bob_fade_rate, 0.0f, 1.0f);
    p[1] += bob_height * std::sin(state.clock * 6.2831853f / bob_period) * state.bob_fade;

    // Off the waterline: inside the gap round the surface the camera is held at its edge on the side it was on,
    // and a crossing to the other side glides over instead of jumping.
    if (on && option(tooie::water_camera_waterline_option, true) && state.has_surface) {
        const float s = state.surface;
        int side = state.side;
        if (p[1] > s + waterline_gap) side = 1;
        else if (p[1] < s - waterline_gap) side = -1;
        else if (side == 0) side = p[1] >= s ? 1 : -1;
        float target = p[1];
        if (std::fabs(p[1] - s) < waterline_gap) {
            target = s + side * waterline_gap;
        }
        if (state.side != 0 && side != state.side) {
            // Crossed: start from the edge it left and glide the rest.
            state.glide = (s + state.side * waterline_gap) - target;
        }
        state.side = side;
        state.glide -= state.glide * ease(waterline_glide_rate, dt);
        p[1] = target + state.glide;
    }
    else {
        state.glide = 0.0f;
    }

    // TOOIE_WATERCAM_LOG=1: four times a second, Banjo's state, the surface, the waterline side and the
    // camera's height as the game placed it and as written.
    static const bool log = std::getenv("TOOIE_WATERCAM_LOG") != nullptr;
    state.log_clock += dt;
    if (log && state.log_clock >= 0.25f) {
        state.log_clock = 0.0f;
        float drawn = 0.0f;
        RT64::GetSceneCameraHeight(&drawn);
        std::printf("[watercam] drawn y %.1f current %08X cam %08X x %.1f z %.1f pitch %.1f yaw %.1f state %u surface %.1f (%d) side %d glide %.1f cam y %.1f -> %.1f splash %.2f bob %.2f pull %.2f kaz %.0f %.0f %.0f face %.1f wall %d hits %d blend %.2f\n",
            drawn, read_word(rdram, 0x8012D500), camera, p[0], p[2], rot[0], rot[1], player_state, state.surface, state.has_surface ? 1 : 0, state.side, state.glide,
            read_float(rdram, camera + cam_pos + 4), p[1], state.splash, state.bob_fade, state.pull, kaz[0], kaz[1], kaz[2], state.face, state.walled ? 1 : 0, state.wall_hits, state.follow_blend);
        std::fflush(stdout);
    }
    for (int i = 0; i < 3; i++) {
        write_float(rdram, camera + cam_pos + 4 * i, p[i]);
    }
    if (eased) {
        write_float(rdram, camera + cam_rot + 0, rot[0]);
        write_float(rdram, camera + cam_rot + 4, rot[1]);
    }
}
