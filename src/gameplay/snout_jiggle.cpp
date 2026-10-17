// General > Snout jiggle (L, 2026-10-16): Banjo's snout wobbles on a spring as he moves, the way
// Mario's nose does in Super Mario Odyssey.
//
// The game draws a model by walking its geometry (func_800DE498); each bone node (func_800DCF48)
// takes the bone's model-space matrix from the animation's matrix list (func_800ADE2C) and pushes
// it (func_80019AA0). For the player's model this file swaps the snout bone's matrix for a copy
// turned (and sized, and stretched) about the snout's root, just before the push:
//
// - The player's model is the one whose skeleton has bone 9 (id 18, the head) with child bone 10
//   (id 42, the snout): asset 062A (Banjo, also alone after Split Up) and 0838 (Banjo with Dragon
//   Kazooie). A model mod that keeps the skeleton (Smash Banjo) gets the jiggle on whatever it
//   puts on bone 10.
// - A point on the snout's tip hangs on a damped spring from where the animation puts it, in
//   world space (the model's position, turn and scale come from func_800DE498's arguments), so
//   running, turning, jumping, landing and the animation's own head moves all set it swinging.
//   The spring runs on real time in small steps, so it behaves the same at any frame rate.
// - The snout turns about its root to point at the spring's point, at most the Exaggeration
//   slider's angle; the sliders under the option set the rest (tooie_snout_jiggle.h).
// - In Photo Mode the spring stops, so the snout stays mid-wobble (L, 2026-10-16).
//
// On the game's own models only the front of the snout is bone 10; the rest of the muzzle is the
// head's (bone 9). So that the muzzle bends too (L: "the snout part in the vanilla model could go
// further back"), the head's vertices in front of the snout's root minus the Reach slider take the
// snout's turn, blended in towards the front (as skinning does), written into the model's own
// vertex list each frame; the originals are put back when the option is turned off. Not on models
// with many vertices (mods such as Smash Banjo, which have their own muzzle on bone 10). The
// eyes (selectors) and the other bones' vertices are left alone.
//
// The snout's copied matrix lives in extended RDRAM no one else uses (after the pause menu's
// strings at 0x80EF1200, src/gameplay/pause_settings.cpp). Headless: TOOIE_SNOUT_LOG=1 logs the
// spring.

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

#include "recomp.h"
#include "recompui/config.h"
#include "tooie_photo_mode.h"
#include "tooie_snout_jiggle.h"

namespace {
    constexpr uint32_t matrix_copy = 0x80EF8000;
    constexpr int head_bone = 9, snout_bone = 10;
    constexpr int16_t head_id = 18, snout_id = 42;
    // Snout tip from the snout bone's root in the bind pose (vanilla 062A: root 0,100,35, nose 39-56).
    constexpr float tip_offset[3] = { 0.0f, 5.0f, 17.0f };
    // What the sliders scale: at their defaults about 3.5 wobbles a second that die out over about
    // half a second, turning at most 28 degrees.
    constexpr float base_follow = 1.3f;   // how much of the spring point's lag the snout turns towards
    constexpr float base_angle = 28.0f;   // degrees
    constexpr float teleport = 300.0f;    // world units in one step: start the spring again
    constexpr float step = 1.0f / 240.0f;
    // Models with more vertices than this are mods with their own snout: no muzzle bending.
    constexpr int vanilla_vertices = 4000;
    constexpr float pi = 3.14159265f;

    struct Vec { float x, y, z; };
    Vec operator+(Vec a, Vec b) { return { a.x + b.x, a.y + b.y, a.z + b.z }; }
    Vec operator-(Vec a, Vec b) { return { a.x - b.x, a.y - b.y, a.z - b.z }; }
    Vec operator*(Vec a, float s) { return { a.x * s, a.y * s, a.z * s }; }
    float dot(Vec a, Vec b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
    Vec cross(Vec a, Vec b) { return { a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x }; }
    float length(Vec a) { return std::sqrt(dot(a, a)); }

    // 3x3 matrices, row vectors (p' = p * M), as the game's.
    struct Mat { float m[9]; };
    Mat mul(const Mat& a, const Mat& b) {
        Mat r{};
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                r.m[i * 3 + j] = a.m[i * 3] * b.m[j] + a.m[i * 3 + 1] * b.m[3 + j] + a.m[i * 3 + 2] * b.m[6 + j];
        return r;
    }
    Vec apply(Vec p, const Mat& a) {
        return { p.x * a.m[0] + p.y * a.m[3] + p.z * a.m[6], p.x * a.m[1] + p.y * a.m[4] + p.z * a.m[7],
                 p.x * a.m[2] + p.y * a.m[5] + p.z * a.m[8] };
    }
    bool inverse(const Mat& a, Mat& out) {
        const float* m = a.m;
        const float det = m[0] * (m[4] * m[8] - m[5] * m[7]) - m[1] * (m[3] * m[8] - m[5] * m[6]) + m[2] * (m[3] * m[7] - m[4] * m[6]);
        if (std::fabs(det) < 1e-12f) return false;
        const float d = 1.0f / det;
        out.m[0] = (m[4] * m[8] - m[5] * m[7]) * d; out.m[1] = (m[2] * m[7] - m[1] * m[8]) * d; out.m[2] = (m[1] * m[5] - m[2] * m[4]) * d;
        out.m[3] = (m[5] * m[6] - m[3] * m[8]) * d; out.m[4] = (m[0] * m[8] - m[2] * m[6]) * d; out.m[5] = (m[2] * m[3] - m[0] * m[5]) * d;
        out.m[6] = (m[3] * m[7] - m[4] * m[6]) * d; out.m[7] = (m[1] * m[6] - m[0] * m[7]) * d; out.m[8] = (m[0] * m[4] - m[1] * m[3]) * d;
        return true;
    }
    Mat upper(const float m[16]) { return { { m[0], m[1], m[2], m[4], m[5], m[6], m[8], m[9], m[10] } }; }
    Mat rotation(Vec axis, float angle) {
        const float c = std::cos(angle), s = std::sin(angle), t = 1.0f - c;
        return { {
            t * axis.x * axis.x + c,          t * axis.x * axis.y + s * axis.z, t * axis.x * axis.z - s * axis.y,
            t * axis.x * axis.y - s * axis.z, t * axis.y * axis.y + c,          t * axis.y * axis.z + s * axis.x,
            t * axis.x * axis.z + s * axis.y, t * axis.y * axis.z - s * axis.x, t * axis.z * axis.z + c,
        } };
    }

    uint32_t read_word(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<uint32_t*>(rdram + (addr - 0x80000000u));
    }
    void write_word(uint8_t* rdram, uint32_t addr, uint32_t value) {
        *reinterpret_cast<uint32_t*>(rdram + (addr - 0x80000000u)) = value;
    }
    int16_t read_half(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<int16_t*>(rdram + ((addr ^ 2) - 0x80000000u));
    }
    void write_half(uint8_t* rdram, uint32_t addr, int16_t value) {
        *reinterpret_cast<int16_t*>(rdram + ((addr ^ 2) - 0x80000000u)) = value;
    }
    uint8_t read_byte(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<uint8_t*>(rdram + ((addr ^ 3) - 0x80000000u));
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

    bool option_bool(const std::string& id) {
        try {
            return std::get<bool>(recompui::config::get_general_config().get_option_value(id));
        } catch (...) {
            return false;
        }
    }
    double option_number(const std::string& id, double fallback) {
        try {
            return std::get<double>(recompui::config::get_general_config().get_option_value(id));
        } catch (...) {
            return fallback;
        }
    }

    // The sliders, read once per draw of the player's model.
    struct Settings {
        float follow = base_follow, damping = 0.18f, frequency = 3.5f, max_angle = base_angle;
        float stretch = 0.0f, size = 1.0f, reach = 20.0f;
    } settings;

    void read_settings() {
        using namespace tooie::snout_jiggle;
        settings.follow = base_follow * (float)option_number(strength_option, 100.0) / 100.0f;
        // Bounce 0..100: damping from 0.33 (settles at once) to 0.03 (wobbles for seconds); 50 is 0.18.
        settings.damping = 0.03f + 0.30f * (1.0f - std::clamp((float)option_number(bounce_option, 50.0), 0.0f, 100.0f) / 100.0f);
        settings.frequency = std::clamp((float)option_number(speed_option, 3.5), 0.5f, 20.0f);
        settings.max_angle = std::min(base_angle * (float)option_number(exaggeration_option, 100.0) / 100.0f, 85.0f);
        settings.stretch = (float)option_number(stretch_option, 0.0) / 100.0f;
        settings.size = std::clamp((float)option_number(size_option, 100.0) / 100.0f, 0.25f, 4.0f);
        settings.reach = std::max((float)option_number(reach_option, 20.0), 0.0f);
    }

    bool logging() {
        static const bool log = std::getenv("TOOIE_SNOUT_LOG") != nullptr;
        return log;
    }

    // The model being drawn, and where the snout's root and tip are in its bind pose.
    struct ModelInfo { bool player = false; Vec root{}, tip{}; uint32_t vtx = 0; int vertices = 0; };
    bool drawing_player = false;
    uint32_t current_model = 0;
    ModelInfo current;
    Vec model_pos{};
    float model_yaw = 0.0f, model_scale = 1.0f;
    float head_matrix[16];
    bool have_head = false;

    // Read each draw: the heap reuses a model's memory for other assets after an area loads.
    ModelInfo info_for(uint8_t* rdram, uint32_t model) {
        ModelInfo info;
        const uint32_t bones_off = read_word(rdram, model + 0x18);
        const uint32_t vtx_off = read_word(rdram, model + 0x10);
        if (bones_off == 0 || bones_off >= 0x200000 || vtx_off == 0 || vtx_off >= 0x200000) {
            return info;
        }
        const uint32_t bones = model + bones_off;
        const int count = (uint16_t)read_half(rdram, bones + 4);
        auto bone = [&](int i) { return bones + 8 + 16 * i; };
        if (count > snout_bone && read_half(rdram, bone(head_bone) + 12) == head_id &&
            read_half(rdram, bone(snout_bone) + 12) == snout_id && read_half(rdram, bone(snout_bone) + 14) == head_bone) {
            info.player = true;
            info.root = { read_float(rdram, bone(snout_bone)), read_float(rdram, bone(snout_bone) + 4),
                          read_float(rdram, bone(snout_bone) + 8) };
            info.tip = info.root + Vec{ tip_offset[0], tip_offset[1], tip_offset[2] };
            info.vtx = model + vtx_off;
            info.vertices = (uint16_t)read_half(rdram, info.vtx + 0x16) / 2;
        }
        return info;
    }

    // ---- the muzzle on the game's own models (see the top) ----
    struct Muzzle {
        uint32_t model = 0;
        std::vector<int> index;            // the head's vertices that can bend
        std::vector<int16_t> original;     // their bind positions, 3 per vertex
        std::vector<int16_t> written;      // what was last written, 3 per vertex (empty: nothing yet)
    } muzzle;

    uint32_t vertex_addr(int i) { return current.vtx + 0x18 + 16 * i; }

    // Is the vertex list still the one the muzzle was read from (or last bent)?
    bool muzzle_intact(uint8_t* rdram) {
        const std::vector<int16_t>& expect = muzzle.written.empty() ? muzzle.original : muzzle.written;
        const size_t stride = std::max<size_t>(1, muzzle.index.size() / 16);
        for (size_t k = 0; k < muzzle.index.size(); k += stride) {
            for (int c = 0; c < 3; c++) {
                if (read_half(rdram, vertex_addr(muzzle.index[k]) + 2 * c) != expect[3 * k + c]) return false;
            }
        }
        return true;
    }

    void restore_muzzle(uint8_t* rdram) {
        if (muzzle.model != 0 && !muzzle.written.empty() && muzzle.model == current_model && muzzle_intact(rdram)) {
            for (size_t k = 0; k < muzzle.index.size(); k++)
                for (int c = 0; c < 3; c++) write_half(rdram, vertex_addr(muzzle.index[k]) + 2 * c, muzzle.original[3 * k + c]);
        }
        muzzle = {};
    }

    // The head's own vertices: draw nodes on bone 9 outside selectors, and the head side of the snout's
    // skin node (on bone 10, its second half).
    void collect(uint8_t* rdram, uint32_t node, int bone, bool in_selector, int depth, std::vector<int>& out) {
        for (int guard = 0; guard < 4096 && depth < 32; guard++) {
            const uint32_t cmd = read_word(rdram, node), size = read_word(rdram, node + 4);
            if (cmd == 2) {
                collect(rdram, node + read_byte(rdram, node + 8), read_byte(rdram, node + 9), in_selector, depth + 1, out);
            } else if (cmd == 0x0C) {
                const int options = (uint16_t)read_half(rdram, node + 8);
                for (int i = 0; i < options && i < 64; i++)
                    collect(rdram, node + read_word(rdram, node + 12 + 4 * i), bone, true, depth + 1, out);
            } else if (cmd == 0x11 && bone == head_bone && !in_selector) {
                const int v0 = (uint16_t)read_half(rdram, node + 10), nv = (uint16_t)read_half(rdram, node + 12);
                for (int i = v0; i < v0 + nv; i++) out.push_back(i);
            } else if (cmd == 0x18 && bone == snout_bone && !in_selector) {
                const int n_parent = (uint16_t)read_half(rdram, node + 20), n_child = (uint16_t)read_half(rdram, node + 32);
                const int v0 = (uint16_t)read_half(rdram, node + 44);
                for (int i = v0 + n_child; i < v0 + n_child + n_parent; i++) out.push_back(i);
            }
            if (size == 0 || size > 0x100000) return;
            node += size;
        }
    }

    bool prepare_muzzle(uint8_t* rdram) {
        if (current.vertices <= 0 || current.vertices > vanilla_vertices) {
            return false;
        }
        if (muzzle.model == current_model && muzzle_intact(rdram)) {
            return !muzzle.index.empty();
        }
        muzzle = {};
        muzzle.model = current_model;
        const uint32_t geo = current_model + read_word(rdram, current_model + 4);
        std::vector<int> all;
        collect(rdram, geo, -1, false, 0, all);
        std::sort(all.begin(), all.end());
        all.erase(std::unique(all.begin(), all.end()), all.end());
        for (int i : all) {
            if (i < 0 || i >= current.vertices) continue;
            muzzle.index.push_back(i);
            for (int c = 0; c < 3; c++) muzzle.original.push_back(read_half(rdram, vertex_addr(i) + 2 * c));
        }
        return !muzzle.index.empty();
    }

    // Bend the muzzle: each head vertex in front of root.z - reach takes the snout's transform Qb (the
    // head's bind space, about the root), blended in by how far forward it is.
    void bend_muzzle(uint8_t* rdram, const Mat& Qb) {
        const float front = current.root.z, back = current.root.z - settings.reach;
        std::vector<int16_t> out(muzzle.original.size());
        for (size_t k = 0; k < muzzle.index.size(); k++) {
            Vec v{ (float)muzzle.original[3 * k], (float)muzzle.original[3 * k + 1], (float)muzzle.original[3 * k + 2] };
            float w = 0.0f;
            if (settings.reach > 0.01f) {
                const float t = std::clamp((v.z - back) / (front - back), 0.0f, 1.0f);
                w = t * t * (3.0f - 2.0f * t);
            }
            if (w > 0.0f) {
                const Vec moved = current.root + apply(v - current.root, Qb);
                v = v + (moved - v) * w;
            }
            out[3 * k] = (int16_t)std::lround(std::clamp(v.x, -32768.0f, 32767.0f));
            out[3 * k + 1] = (int16_t)std::lround(std::clamp(v.y, -32768.0f, 32767.0f));
            out[3 * k + 2] = (int16_t)std::lround(std::clamp(v.z, -32768.0f, 32767.0f));
        }
        for (size_t k = 0; k < muzzle.index.size(); k++)
            for (int c = 0; c < 3; c++) write_half(rdram, vertex_addr(muzzle.index[k]) + 2 * c, out[3 * k + c]);
        muzzle.written = std::move(out);
    }

    // Row vectors, as the game's matrices: p' = p * M.
    Vec transform(const float m[16], Vec p) {
        return { p.x * m[0] + p.y * m[4] + p.z * m[8] + m[12],
                 p.x * m[1] + p.y * m[5] + p.z * m[9] + m[13],
                 p.x * m[2] + p.y * m[6] + p.z * m[10] + m[14] };
    }

    // Model space <-> world space: turned by the model's yaw (degrees, about y) and scaled.
    Vec to_world(Vec p) {
        const float r = model_yaw * pi / 180.0f, c = std::cos(r), s = std::sin(r);
        p = p * model_scale;
        return model_pos + Vec{ c * p.x + s * p.z, p.y, -s * p.x + c * p.z };
    }
    Vec to_model_dir(Vec d) {
        const float r = model_yaw * pi / 180.0f, c = std::cos(r), s = std::sin(r);
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
        if (tooie::photo_mode::active()) {
            // Photo Mode: the snout stays as it was when the photo was framed.
            spring.last = now;
            return;
        }
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
        const float w = 2.0f * pi * settings.frequency;
        const float k = w * w, c = 2.0f * settings.damping * w;
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
    have_head = false;
    const uint32_t sp = (uint32_t)ctx->r29;
    const uint32_t model = read_word(rdram, sp + 0x10C);
    if (!valid_ptr(model)) {
        return;
    }
    const bool on = option_bool(tooie::snout_jiggle::option);
    if (!on && muzzle.model == 0) {
        return;
    }
    const ModelInfo info = info_for(rdram, model);
    if (!info.player) {
        return;
    }
    current_model = model;
    current = info;
    if (!on) {
        restore_muzzle(rdram);
        return;
    }
    drawing_player = true;
    read_settings();
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
    if (!valid_ptr(node)) {
        return;
    }
    const int bone = read_byte(rdram, node + 9);
    const uint32_t src = (uint32_t)ctx->r2;
    if ((bone != snout_bone && bone != head_bone) || !valid_ptr(src)) {
        return;
    }
    float m[16];
    for (int i = 0; i < 16; i++) {
        m[i] = read_float(rdram, src + 4 * i);
    }
    if (bone == head_bone) {
        std::memcpy(head_matrix, m, sizeof(m));
        have_head = true;
        return;
    }
    const Vec root = transform(m, current.root);
    const Vec tip = transform(m, current.tip);
    update_spring(to_world(tip));

    // Turn the snout about its root so its tip points at the spring's point.
    const Vec arm = tip - root;
    const float la = length(arm);
    if (la < 1e-3f) {
        return;
    }
    const Vec lag = to_model_dir(spring.lag) * settings.follow;
    const Vec want = arm + lag;
    const float lw = length(want);
    Mat R = rotation({ 1, 0, 0 }, 0.0f);
    float angle = 0.0f;
    if (lw > 1e-3f) {
        const Vec a = arm * (1.0f / la), b = want * (1.0f / lw);
        Vec axis = cross(a, b);
        const float sin_t = length(axis);
        if (sin_t > 1e-5f) {
            angle = std::min(std::atan2(sin_t, dot(a, b)), settings.max_angle * pi / 180.0f);
            R = rotation(axis * (1.0f / sin_t), angle);
        }
    }
    // Size, and squash and stretch along the snout as it swings (thinner as it stretches).
    const float d[3] = { arm.x / la, arm.y / la, arm.z / la };
    const float f = 1.0f + settings.stretch * std::min(length(lag) / la, 1.0f);
    const float across = 1.0f / std::sqrt(std::max(f, 0.05f));
    Mat S{};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            S.m[i * 3 + j] = settings.size * ((i == j ? across : 0.0f) + (f - across) * d[i] * d[j]);
    const Mat Q = mul(S, R);   // p' = root + (p - root) * S * R

    // M' = M * T(-root) * Q * T(root).
    float out[16];
    for (int row = 0; row < 3; row++) {
        const Vec r = apply({ m[row * 4], m[row * 4 + 1], m[row * 4 + 2] }, Q);
        out[row * 4] = r.x; out[row * 4 + 1] = r.y; out[row * 4 + 2] = r.z;
        out[row * 4 + 3] = m[row * 4 + 3];
    }
    const Vec moved = apply(Vec{ m[12], m[13], m[14] } - root, Q) + root;
    out[12] = moved.x; out[13] = moved.y; out[14] = moved.z;
    out[15] = m[15];
    for (int i = 0; i < 16; i++) {
        write_float(rdram, matrix_copy + 4 * i, out[i]);
    }
    ctx->r2 = (gpr)(int32_t)matrix_copy;

    // The muzzle on the game's own models: Q in the head's bind space (Qb = A9 Q A9^-1).
    if (have_head && prepare_muzzle(rdram)) {
        Mat A = upper(head_matrix), Ai;
        if (inverse(A, Ai)) {
            bend_muzzle(rdram, mul(mul(A, Q), Ai));
        }
    }
    if (logging()) {
        static int n = 0;
        if (++n % 15 == 0) {
            printf("[snout] pos %.0f,%.0f,%.0f yaw %.0f scale %.2f lag %.1f,%.1f,%.1f angle %.1f stretch %.2f muzzle %zu%s\n",
                   model_pos.x, model_pos.y, model_pos.z, model_yaw, model_scale, spring.lag.x, spring.lag.y, spring.lag.z,
                   angle * 180.0f / pi, f, muzzle.index.size(), tooie::photo_mode::active() ? " (photo)" : "");
            fflush(stdout);
        }
    }
}
