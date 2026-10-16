// General > Snout jiggle (L, 2026-10-16): Banjo's snout wobbles on a spring as he moves, the way
// Mario's nose does in Super Mario Odyssey.
//
// The game draws a model by walking its geometry (func_800DE498); each bone node (func_800DCF48)
// takes the bone's model-space matrix from the animation's matrix list (func_800ADE2C) and pushes
// it (func_80019AA0). For the player's model this file swaps the snout bone's matrix for a copy
// turned about the snout's root, just before the push:
//
// - The player's model is the one whose skeleton has bone 9 (id 18, the head) with child bone 10
//   (id 42, the snout): asset 062A (Banjo, also alone after Split Up) and 0838 (Banjo with Dragon
//   Kazooie). A model mod that keeps the skeleton (Smash Banjo) gets the jiggle on whatever it
//   puts on bone 10.
// - A point on the snout's tip hangs on a damped spring from where the animation puts it, in
//   world space (the model's position, turn and scale come from func_800DE498's arguments), so
//   running, turning, jumping, landing and the animation's own head moves all set it swinging.
//   The spring runs on real time in small steps, so it behaves the same at any frame rate.
// - The snout turns about its root to point at the spring's point, at most max_angle degrees.
//
// The copy lives in extended RDRAM no one else uses (after the pause menu's strings at
// 0x80EF1200, src/gameplay/pause_settings.cpp). Headless: TOOIE_SNOUT_LOG=1 logs the spring.

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "recomp.h"
#include "recompui/config.h"
#include "tooie_snout_jiggle.h"

namespace {
    constexpr uint32_t matrix_copy = 0x80EF8000;
    constexpr int head_bone = 9, snout_bone = 10;
    constexpr int16_t head_id = 18, snout_id = 42;
    // Snout tip from the snout bone's root in the bind pose (vanilla 062A: root 0,100,35, nose 39-56).
    constexpr float tip_offset[3] = { 0.0f, 5.0f, 17.0f };
    // Spring: about 3.5 wobbles a second that die out over about half a second.
    constexpr float frequency = 3.5f;
    constexpr float damping = 0.18f;   // fraction of critical
    constexpr float follow = 1.3f;     // how much of the spring point's lag the snout turns towards
    constexpr float max_angle = 28.0f; // degrees
    constexpr float teleport = 300.0f; // world units in one step: start the spring again
    constexpr float step = 1.0f / 240.0f;

    struct Vec { float x, y, z; };
    Vec operator+(Vec a, Vec b) { return { a.x + b.x, a.y + b.y, a.z + b.z }; }
    Vec operator-(Vec a, Vec b) { return { a.x - b.x, a.y - b.y, a.z - b.z }; }
    Vec operator*(Vec a, float s) { return { a.x * s, a.y * s, a.z * s }; }
    float dot(Vec a, Vec b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
    Vec cross(Vec a, Vec b) { return { a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x }; }
    float length(Vec a) { return std::sqrt(dot(a, a)); }

    uint32_t read_word(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<uint32_t*>(rdram + (addr - 0x80000000u));
    }
    void write_word(uint8_t* rdram, uint32_t addr, uint32_t value) {
        *reinterpret_cast<uint32_t*>(rdram + (addr - 0x80000000u)) = value;
    }
    int16_t read_half(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<int16_t*>(rdram + ((addr ^ 2) - 0x80000000u));
    }
    int8_t read_byte(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<int8_t*>(rdram + ((addr ^ 3) - 0x80000000u));
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
        write_word(rdram, addr, bits);
    }
    bool valid_ptr(uint32_t p) {
        return p >= 0x80000000u && p < 0x81000000u;
    }

    bool enabled() {
        try {
            return std::get<bool>(recompui::config::get_general_config().get_option_value(tooie::snout_jiggle::option));
        } catch (...) {
            return false;
        }
    }

    bool logging() {
        static const bool log = std::getenv("TOOIE_SNOUT_LOG") != nullptr;
        return log;
    }

    // The model being drawn, and where the snout's root and tip are in its bind pose.
    struct ModelInfo { bool player = false; Vec root{}, tip{}; };
    bool drawing_player = false;
    ModelInfo current;
    Vec model_pos{};
    float model_yaw = 0.0f, model_scale = 1.0f;

    // Read each draw: the heap reuses a model's memory for other assets after an area loads.
    ModelInfo info_for(uint8_t* rdram, uint32_t model) {
        ModelInfo info;
        const uint32_t bones_off = read_word(rdram, model + 0x18);
        if (bones_off != 0 && bones_off < 0x200000) {
            const uint32_t bones = model + bones_off;
            const int count = (uint16_t)read_half(rdram, bones + 4);
            auto bone = [&](int i) { return bones + 8 + 16 * i; };
            if (count > snout_bone && read_half(rdram, bone(head_bone) + 12) == head_id &&
                read_half(rdram, bone(snout_bone) + 12) == snout_id && read_half(rdram, bone(snout_bone) + 14) == head_bone) {
                info.player = true;
                info.root = { read_float(rdram, bone(snout_bone)), read_float(rdram, bone(snout_bone) + 4),
                              read_float(rdram, bone(snout_bone) + 8) };
                info.tip = info.root + Vec{ tip_offset[0], tip_offset[1], tip_offset[2] };
            }
        }
        return info;
    }

    // Row vectors, as the game's matrices: p' = p * M.
    Vec transform(const float m[16], Vec p) {
        return { p.x * m[0] + p.y * m[4] + p.z * m[8] + m[12],
                 p.x * m[1] + p.y * m[5] + p.z * m[9] + m[13],
                 p.x * m[2] + p.y * m[6] + p.z * m[10] + m[14] };
    }
    Vec rotate_dir(const float m[16], Vec d) {
        return { d.x * m[0] + d.y * m[4] + d.z * m[8], d.x * m[1] + d.y * m[5] + d.z * m[9], d.x * m[2] + d.y * m[6] + d.z * m[10] };
    }

    // Model space <-> world space: turned by the model's yaw (degrees, about y) and scaled.
    Vec to_world(Vec p) {
        const float r = model_yaw * 3.14159265f / 180.0f, c = std::cos(r), s = std::sin(r);
        p = p * model_scale;
        return model_pos + Vec{ c * p.x + s * p.z, p.y, -s * p.x + c * p.z };
    }
    Vec to_model_dir(Vec d) {
        const float r = model_yaw * 3.14159265f / 180.0f, c = std::cos(r), s = std::sin(r);
        d = d * (1.0f / (model_scale != 0.0f ? model_scale : 1.0f));
        return { c * d.x - s * d.z, d.y, s * d.x + c * d.z };
    }

    // The spring: a point that follows the snout tip's place in the world.
    struct Spring {
        bool started = false;
        Vec point{}, velocity{};
        std::chrono::steady_clock::time_point last;
        Vec lag{};   // point - target after the last update, world space
    } spring;

    void update_spring(Vec target) {
        const auto now = std::chrono::steady_clock::now();
        if (!spring.started || length(target - spring.point) > teleport) {
            spring.started = true;
            spring.point = target;
            spring.velocity = {};
            spring.last = now;
            spring.lag = {};
            return;
        }
        float dt = std::chrono::duration<float>(now - spring.last).count();
        // The shadow pass draws the model again in the same frame: one update per frame.
        if (dt < 0.008f) {
            return;
        }
        spring.last = now;
        dt = std::min(dt, 0.1f);
        const float w = 2.0f * 3.14159265f * frequency;
        const float k = w * w, c = 2.0f * damping * w;
        for (float t = 0.0f; t < dt; t += step) {
            const float h = std::min(step, dt - t);
            Vec accel = (target - spring.point) * k - spring.velocity * c;
            spring.velocity = spring.velocity + accel * h;
            spring.point = spring.point + spring.velocity * h;
        }
        spring.lag = spring.point - target;
    }
}

// func_800DE498 once it has settled on the model it draws (0x10C($sp), with the shadow hook):
// position (copied to 0xE0($sp)), rotation pointer (0x100($sp), degrees) and scale (0x104($sp)).
extern "C" void tooie_snout_model(uint8_t* rdram, recomp_context* ctx) {
    drawing_player = false;
    if (!enabled()) {
        return;
    }
    const uint32_t sp = (uint32_t)ctx->r29;
    const uint32_t model = read_word(rdram, sp + 0x10C);
    if (!valid_ptr(model)) {
        return;
    }
    current = info_for(rdram, model);
    if (!current.player) {
        return;
    }
    drawing_player = true;
    model_pos = { read_float(rdram, sp + 0xE0), read_float(rdram, sp + 0xE4), read_float(rdram, sp + 0xE8) };
    const uint32_t rot = read_word(rdram, sp + 0x100);
    model_yaw = valid_ptr(rot) ? read_float(rdram, rot + 4) : 0.0f;
    const float scale = read_float(rdram, sp + 0x104);
    model_scale = (scale > 0.01f && scale < 100.0f) ? scale : 1.0f;
}

// func_800DCF48 (a bone node) after func_800ADE2C returned the bone's matrix in $v0, before
// func_80019AA0 pushes it ($a1 = $v0 in the delay slot).
extern "C" void tooie_snout_bone(uint8_t* rdram, recomp_context* ctx) {
    if (!drawing_player) {
        return;
    }
    const uint32_t node = read_word(rdram, (uint32_t)ctx->r29 + 0x24);
    if (!valid_ptr(node) || read_byte(rdram, node + 9) != snout_bone) {
        return;
    }
    const uint32_t src = (uint32_t)ctx->r2;
    if (!valid_ptr(src)) {
        return;
    }
    float m[16];
    for (int i = 0; i < 16; i++) {
        m[i] = read_float(rdram, src + 4 * i);
    }
    const Vec root = transform(m, current.root);
    const Vec tip = transform(m, current.tip);
    update_spring(to_world(tip));

    // Turn the snout about its root so its tip points at the spring's point.
    const Vec arm = tip - root;
    const Vec want = arm + to_model_dir(spring.lag) * follow;
    const float la = length(arm), lw = length(want);
    if (la < 1e-3f || lw < 1e-3f) {
        return;
    }
    const Vec a = arm * (1.0f / la), b = want * (1.0f / lw);
    Vec axis = cross(a, b);
    const float sin_t = length(axis);
    if (sin_t < 1e-5f) {
        return;
    }
    axis = axis * (1.0f / sin_t);
    const float angle = std::min(std::atan2(sin_t, dot(a, b)), max_angle * 3.14159265f / 180.0f);
    const float c = std::cos(angle), s = std::sin(angle), t = 1.0f - c;
    // Rotation about axis, row-vector form (p' = p * R).
    const float R[9] = {
        t * axis.x * axis.x + c,          t * axis.x * axis.y + s * axis.z, t * axis.x * axis.z - s * axis.y,
        t * axis.x * axis.y - s * axis.z, t * axis.y * axis.y + c,          t * axis.y * axis.z + s * axis.x,
        t * axis.x * axis.z + s * axis.y, t * axis.y * axis.z - s * axis.x, t * axis.z * axis.z + c,
    };
    // M' = M * T(-root) * R * T(root): the rows' directions turn, the translation turns about the root.
    float out[16];
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            out[row * 4 + col] = m[row * 4] * R[col] + m[row * 4 + 1] * R[3 + col] + m[row * 4 + 2] * R[6 + col];
        }
        out[row * 4 + 3] = m[row * 4 + 3];
    }
    const Vec moved = Vec{ m[12], m[13], m[14] } - root;
    out[12] = moved.x * R[0] + moved.y * R[3] + moved.z * R[6] + root.x;
    out[13] = moved.x * R[1] + moved.y * R[4] + moved.z * R[7] + root.y;
    out[14] = moved.x * R[2] + moved.y * R[5] + moved.z * R[8] + root.z;
    out[15] = m[15];
    for (int i = 0; i < 16; i++) {
        write_float(rdram, matrix_copy + 4 * i, out[i]);
    }
    ctx->r2 = (gpr)(int32_t)matrix_copy;
    if (logging()) {
        static int n = 0;
        if (++n % 15 == 0) {
            printf("[snout] pos %.0f,%.0f,%.0f yaw %.0f scale %.2f lag %.1f,%.1f,%.1f angle %.1f\n", model_pos.x, model_pos.y,
                   model_pos.z, model_yaw, model_scale, spring.lag.x, spring.lag.y, spring.lag.z, angle * 180.0f / 3.14159265f);
            fflush(stdout);
        }
    }
}
