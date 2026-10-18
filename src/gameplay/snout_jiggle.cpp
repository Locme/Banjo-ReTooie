// General > Snout jiggle (L, 2026-10-16): Banjo's snout wobbles on a spring as he moves.
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
// - The snout is one jiggle bone from the corners of the mouth to its tip (L, 2026-10-18): a point hangs on a damped spring from the tip in the world
//   (the model's position, turn and scale come from func_800DE498's arguments), and the snout turns
//   to point at it and stretches or squashes to reach it, keeping its volume. Falling, the point lags
//   above and the snout pushes up into his face; jumping, it hangs down; stops slap it forward. The
//   tip moves at most a share of the snout's length from rest: inwards (squashing into the face),
//   outwards (stretching) and up, down or to the side, each its own slider. It steps by the game's
//   own clock, so it behaves the same at any frame rate and never snaps back after a hitch.
// - Sliders (tooie_snout_jiggle.h): stiffness, damping, mass and the three limits.
// - Nose jiggle (L, 2026-10-18, its own toggle under Snout jiggle): the black nose is a second jiggle
//   bone with the same sliders, from its base to its tip, on the end of the swung snout. Its vertices
//   (the snout bone's black ones and the white highlights over them; on mods without black ones, the
//   front third of the snout bone's mesh, blended in) are rewritten each frame like the muzzle's.
// - In Photo Mode the swing stops, so the snout stays mid-wobble (L, 2026-10-16).
//
// On the game's own models only the front of the snout is bone 10; the rest of the muzzle is the
// head's (bone 9). So that the muzzle bends too (L: "the snout part in the vanilla model could go
// further back"; 2026-10-18: "all the way down to his mouth point"), the snout swings about the
// corners of the mouth, and the head's vertices in front of them minus the Reach slider take the
// snout's turn, blended in towards the front (as skinning does), written into the model's own
// vertex list each frame; the originals are put back when the option is turned off. The mouth stays
// out of it (L): the lips and the corners of the mouth don't bend, and the lips on the snout bone are
// turned back, so only the snout above the mouth swings. Not on models with many vertices (mods such as
// Smash Banjo, which have their own muzzle on bone 10). The eyes (selectors) and the other bones'
// vertices are left alone. (The first Nose jiggle, an angle spring, was taken out on
// 2026-10-17, "its not doing anything"; the jiggle bone above replaced it.)
//
// General > Kazooie jiggle (L, 2026-10-17, its own toggle): Kazooie's crest and tail feathers
// hang on springs the same way. Each feather bone gets its own spring on the end of the bone, from
// the root of the chain out, and each bone's turn carries the bones after it, so the tail whips.
// Her bones are found by index and id: 062A and 0838 (in the backpack; Smash Banjo keeps them) and
// 061C (alone after Split Up). The snout's sliders don't apply to her.
//
// The copied matrices live in extended RDRAM no one else uses (after the pause menu's strings at
// 0x80EF1200, src/gameplay/pause_settings.cpp): the snout's at 0x80EF8000, Kazooie's feathers' after
// it. Headless: TOOIE_SNOUT_LOG=1 logs the springs.

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

#include "recomp.h"
#include "tooie_size_cheats.h"
#include "recompui/config.h"
#include "tooie_game_frame_rate.h"
#include "tooie_photo_mode.h"
#include "tooie_snout_jiggle.h"
#include "tooie_rdram.h"

namespace {
    constexpr uint32_t matrix_copy = 0x80EF8000;
    constexpr uint32_t feather_copies = 0x80EF8040;   // 64 bytes per feather bone
    constexpr int head_bone = 9, snout_bone = 10, jaw_bone = 11;
    constexpr int16_t head_id = 18, snout_id = 42, jaw_id = 74;
    // Snout tip from the snout bone's root in the bind pose (vanilla 062A: root 0,100,35, nose 39-56).
    constexpr float tip_offset[3] = { 0.0f, 5.0f, 17.0f };
    // The corners of the mouth, behind the snout bone's root (vanilla 062A: z 25 against 35).
    constexpr float mouth_back = 10.0f;
    constexpr float teleport = 300.0f;    // world units in one step: a warp, not a move
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

    using tooie::rdram::read_float;
    using tooie::rdram::read_half;
    using tooie::rdram::read_word;
    using tooie::rdram::valid_ptr;
    using tooie::rdram::write_float;
    using tooie::rdram::write_word;

    void write_half(uint8_t* rdram, uint32_t addr, int16_t value) {
        *reinterpret_cast<int16_t*>(rdram + ((addr ^ 2) - 0x80000000u)) = value;
    }
    uint8_t read_byte(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<uint8_t*>(rdram + ((addr ^ 3) - 0x80000000u));
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

    // The sliders, read once per draw of the player's model (L, 2026-10-18: just the jiggle bone's own).
    // The snout and the nose share them.
    struct Settings {
        float stiffness = 150.0f;   // spring, per unit of mass
        float damping = 12.0f;      // against the tip's velocity
        float mass = 1.0f;
        // How far the tip may move from rest, as shares of the bone's length: back along it (into the
        // face), out along it, and across it (up, down, sideways).
        float inwards = 0.5f, outwards = 0.5f, across = 0.5f;
        float reach = 6.0f;         // vanilla model: how far behind the mouth's corners the head blends in
    } settings;

    void read_settings() {
        using namespace tooie::snout_jiggle;
        settings.stiffness = std::clamp((float)option_number(stiffness_option, 150.0), 1.0f, 2000.0f);
        settings.damping = std::clamp((float)option_number(damping_option, 12.0), 0.0f, 200.0f);
        settings.mass = std::clamp((float)option_number(mass_option, 1.0), 0.05f, 20.0f);
        settings.inwards = std::clamp((float)option_number(squash_in_option, 50.0), 0.0f, 95.0f) / 100.0f;
        settings.outwards = std::clamp((float)option_number(squash_out_option, 50.0), 0.0f, 300.0f) / 100.0f;
        settings.across = std::clamp((float)option_number(squash_across_option, 50.0), 0.0f, 300.0f) / 100.0f;
    }

    bool logging() {
        static const bool log = std::getenv("TOOIE_SNOUT_LOG") != nullptr;
        return log;
    }

    // The model being drawn, and where the snout's root and tip are in its bind pose.
    struct ModelInfo { bool player = false, jaw = false; Vec root{}, pivot{}, tip{}; uint32_t vtx = 0; int vertices = 0; };
    // The player's model (physical start and end of its asset) while its vertices are rewritten.
    std::atomic<uint32_t> bent_from{ 0 }, bent_to{ 0 };
    bool drawing_player = false;
    bool snout_on = false, nose_on = false;
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
            // On the game's own models the snout swings from the corners of the mouth (z 25), not from the
            // snout bone's root (z 35): L, 2026-10-18, "its too short". Mods turn their bone at its root.
            info.pivot = info.root;
            if (info.vertices > 0 && info.vertices <= vanilla_vertices) info.pivot.z -= mouth_back;
            info.jaw = count > jaw_bone && read_half(rdram, bone(jaw_bone) + 12) == jaw_id &&
                       read_half(rdram, bone(jaw_bone) + 14) == head_bone;
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

    // The head's own vertices: draw nodes on bone 9 outside selectors, the head side of the snout's
    // skin node (on bone 10, its second half) and of the jaw's (bone 11): the corners of the mouth are
    // one point in all three, so they must move alike or the mouth tears open there (L's close-up,
    // 2026-10-17). (Second of each pair: true for the snout bone's own; none now, L 2026-10-18: holding
    // its underside back with the mouth stopped the snout bending down.)
    void collect(uint8_t* rdram, uint32_t node, int bone, bool in_selector, int depth, std::vector<std::pair<int, bool>>& out) {
        const bool jaw = current.jaw;
        for (int guard = 0; guard < 4096 && depth < 32; guard++) {
            const uint32_t cmd = read_word(rdram, node), size = read_word(rdram, node + 4);
            if (cmd == 2) {
                collect(rdram, node + read_byte(rdram, node + 8), read_byte(rdram, node + 9), in_selector, depth + 1, out);
            } else if (cmd == 0x0C) {
                const int options = (uint16_t)read_half(rdram, node + 8);
                for (int i = 0; i < options && i < 64; i++)
                    collect(rdram, node + read_word(rdram, node + 12 + 4 * i), bone, true, depth + 1, out);
            } else if (cmd == 0x11 && !in_selector && bone == head_bone) {
                const int v0 = (uint16_t)read_half(rdram, node + 10), nv = (uint16_t)read_half(rdram, node + 12);
                for (int i = v0; i < v0 + nv; i++) out.push_back({ i, false });
            } else if (cmd == 0x18 && !in_selector && (bone == snout_bone || (jaw && bone == jaw_bone))) {
                const int n_parent = (uint16_t)read_half(rdram, node + 20), n_child = (uint16_t)read_half(rdram, node + 32);
                const int v0 = (uint16_t)read_half(rdram, node + 44);
                for (int i = v0 + n_child; i < v0 + n_child + n_parent; i++) out.push_back({ i, false });
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
        std::vector<std::pair<int, bool>> all;
        collect(rdram, geo, -1, false, 0, all);
        std::sort(all.begin(), all.end());
        all.erase(std::unique(all.begin(), all.end(), [](auto& a, auto& b) { return a.first == b.first; }), all.end());
        for (const auto& entry : all) {
            const int i = entry.first;
            if (i < 0 || i >= current.vertices) continue;
            muzzle.index.push_back(i);
            for (int c = 0; c < 3; c++) muzzle.original.push_back(read_half(rdram, vertex_addr(i) + 2 * c));
        }
        return !muzzle.index.empty();
    }

    float smooth(float t) {
        t = std::clamp(t, 0.0f, 1.0f);
        return t * t * (3.0f - 2.0f * t);
    }
    // The game's head (bind space, 062A and 0838): the eyes reach forward to z 27 and down to y 106;
    // the mouth (the lips on the snout and head, its corners at y 98, and the jaw) is below about y 99.
    constexpr float eye_front = 27.0f, eye_bottom = 106.0f, mouth_top = 96.0f, mouth_band = 6.0f, mouth_corner_z = 26.0f;

    // Row vectors, as the game's matrices: p' = p * M.
    Vec transform(const float m[16], Vec p) {
        return { p.x * m[0] + p.y * m[4] + p.z * m[8] + m[12],
                 p.x * m[1] + p.y * m[5] + p.z * m[9] + m[13],
                 p.x * m[2] + p.y * m[6] + p.z * m[10] + m[14] };
    }

    // An affine map p' = p * L + t (row vectors).
    struct Affine { Mat L; Vec t; };
    Affine then(const Affine& a, const Affine& b) { return { mul(a.L, b.L), apply(a.t, b.L) + b.t }; }
    void apply_affine(const float m[16], const Affine& a, float out[16]) {
        for (int row = 0; row < 3; row++) {
            const Vec r = apply({ m[row * 4], m[row * 4 + 1], m[row * 4 + 2] }, a.L);
            out[row * 4] = r.x; out[row * 4 + 1] = r.y; out[row * 4 + 2] = r.z;
            out[row * 4 + 3] = m[row * 4 + 3];
        }
        const Vec moved = apply(Vec{ m[12], m[13], m[14] }, a.L) + a.t;
        out[12] = moved.x; out[13] = moved.y; out[14] = moved.z;
        out[15] = m[15];
    }

    // How much of the mouth a bind position is: 1 at the lips and below, 0 from mouth_top + mouth_band,
    // and only back at the corners of the mouth (z 25), not under the snout in front of them. The snout
    // swings, the mouth stays put (L, 2026-10-17: "it should affect his snout not his mouth"), and the
    // underside of the snout bends down with the rest (L, 2026-10-18).
    float mouth(Vec v) {
        return (1.0f - smooth((v.y - mouth_top) / mouth_band)) * (1.0f - smooth((v.z - mouth_corner_z) / 4.0f));
    }

    // Bend the muzzle: each head vertex takes the snout's turn A (posed space, about the corners of the
    // mouth), blended in from pivot.z - reach to the pivot. Vertices are in the bind pose; head is the
    // head's matrix.
    void bend_muzzle(uint8_t* rdram, const Affine& A, const float head[16]) {
        const float front = current.pivot.z, back = current.pivot.z - settings.reach;
        Mat inv_head;
        if (!inverse(upper(head), inv_head)) return;
        std::vector<int16_t> out(muzzle.original.size());
        for (size_t k = 0; k < muzzle.index.size(); k++) {
            Vec v{ (float)muzzle.original[3 * k], (float)muzzle.original[3 * k + 1], (float)muzzle.original[3 * k + 2] };
            // Weights depend only on the bind position, so points shared by the head, the snout's skin
            // and the jaw's skin move together.
            {
                // Leave the brow round the eyes alone (the eyes are selectors and don't move), or they come
                // apart (L's photo, 2026-10-17), and the mouth.
                const float keep = (1.0f - (1.0f - smooth((v.z - eye_front) / 4.0f)) * smooth((v.y - (eye_bottom - 4.0f)) / 4.0f)) *
                                   (1.0f - mouth(v));
                const float wa = keep * (front > back ? smooth((v.z - back) / (front - back)) : (v.z >= front ? 1.0f : 0.0f));
                if (wa > 0.0f) {
                    Vec p = transform(head, v);
                    p = p + (apply(p, A.L) + A.t - p) * wa;
                    v = apply(p - Vec{ head[12], head[13], head[14] }, inv_head);
                }
            }
            out[3 * k] = (int16_t)std::lround(std::clamp(v.x, -32768.0f, 32767.0f));
            out[3 * k + 1] = (int16_t)std::lround(std::clamp(v.y, -32768.0f, 32767.0f));
            out[3 * k + 2] = (int16_t)std::lround(std::clamp(v.z, -32768.0f, 32767.0f));
        }
        for (size_t k = 0; k < muzzle.index.size(); k++)
            for (int c = 0; c < 3; c++) write_half(rdram, vertex_addr(muzzle.index[k]) + 2 * c, out[3 * k + c]);
        muzzle.written = std::move(out);
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

    // A spring: a point that follows a place in the world (the snout's tip, a feather's end).
    struct Spring {
        bool started = false;
        Vec point{}, velocity{};
        std::chrono::steady_clock::time_point last;
        Vec lag{};      // point - target after the last update, world space
        Vec target{};   // the target at the last update
        float period = 1.0f / 30.0f;   // the game's frame time, smoothed
    };

    // One step of the spring per game frame. The game moves the target by the same amount each frame
    // whatever the wall clock says, so the spring steps by the game's frame time, smoothed over about
    // half a second, not by the time since the last draw: frames that arrive unevenly (2 close
    // together, then a gap) made the wobble stutter (L, 2026-10-17).
    void update_spring(Spring& spring, Vec target, float frequency, float damping) {
        const auto now = std::chrono::steady_clock::now();
        if (tooie::photo_mode::active()) {
            // Photo Mode: it stays as it was when the photo was framed.
            spring.last = now;
            return;
        }
        const float since = std::chrono::duration<float>(now - spring.last).count();
        // Not drawn for a while (Kazooie hides in the pack between moves): start again where it is.
        if (!spring.started || since > 0.5f || length(target - spring.point) > teleport) {
            spring.started = true;
            spring.point = target;
            spring.velocity = {};
            spring.last = now;
            spring.lag = {};
            spring.target = target;
            return;
        }
        // The shadow pass draws the model again in the same frame, at the same place: one step per frame.
        if (since < 0.008f && length(target - spring.target) < 1e-4f) {
            return;
        }
        spring.last = now;
        spring.target = target;
        spring.period += (std::clamp(since, 1.0f / 240.0f, 0.1f) - spring.period) * 0.1f;
        const float dt = spring.period;
        const float w = 2.0f * pi * frequency;
        const float k = w * w, c = 2.0f * damping * w;
        for (float t = 0.0f; t < dt; t += step) {
            const float h = std::min(step, dt - t);
            Vec accel = (target - spring.point) * k - spring.velocity * c;
            spring.velocity = spring.velocity + accel * h;
            spring.point = spring.point + spring.velocity * h;
        }
        spring.lag = spring.point - target;
    }

    // Turn that points arm (from a pivot) at arm + lag, at most max_deg; the angle in radians.
    Mat aim(Vec arm, Vec lag, float max_deg, float& angle) {
        angle = 0.0f;
        const float la = length(arm);
        const Vec want = arm + lag;
        const float lw = length(want);
        if (la < 1e-3f || lw < 1e-3f) {
            return rotation({ 1, 0, 0 }, 0.0f);
        }
        const Vec a = arm * (1.0f / la), b = want * (1.0f / lw);
        const Vec axis = cross(a, b);
        const float sin_t = length(axis);
        if (sin_t < 1e-5f) {
            return rotation({ 1, 0, 0 }, 0.0f);
        }
        angle = std::min(std::atan2(sin_t, dot(a, b)), max_deg * pi / 180.0f);
        return rotation(axis * (1.0f / sin_t), angle);
    }

    // ---- the jiggle bones: the snout and the nose (see the top) ----
    // A point hangs on a damped spring from the bone's tip, in the world: F = -stiffness * (point -
    // tip) - damping * velocity, a = F / mass. The bone points from its root at where the point is, as
    // far as the limits let it, and stretches or squashes to reach it, keeping its volume. Falling, the
    // tip lags above and the snout folds up into the face; jumping, it hangs down; stopping, it slaps
    // forward.
    struct Jiggle {
        bool started = false;
        Vec point{}, velocity{};
        Vec offset{};                 // point - tip after the last step, model space
        double last = 0.0;            // game time of the last step, seconds
    };
    Jiggle snout_spring, nose_spring;

    // One step per game frame by the game's own clock (the shadow pass's second draw and any frame rate
    // give the same wobble). After a long gap or a warp the point comes back where it was on the bone,
    // still, so it never snaps to rest (L: "the snout also resets a lot").
    void update_jiggle(Jiggle& jiggle, Vec tip_world) {
        if (tooie::photo_mode::active()) {
            return;
        }
        const double now = tooie::game_frame_rate::game_seconds();
        const float dt = (float)(now - jiggle.last);
        const Vec back_on = tip_world + to_world(jiggle.offset) - to_world(Vec{ 0, 0, 0 });
        if (!jiggle.started || dt > 0.25f || length(tip_world - jiggle.point) > teleport) {
            jiggle.point = jiggle.started ? back_on : tip_world;
            jiggle.velocity = {};
            jiggle.started = true;
            jiggle.last = now;
            return;
        }
        if (dt <= 1e-5f) {
            return;
        }
        jiggle.last = now;
        const float k = settings.stiffness, c = settings.damping, inv_m = 1.0f / settings.mass;
        for (float t = 0.0f; t < dt; t += step) {
            const float h = std::min(step, dt - t);
            const Vec accel = ((jiggle.point - tip_world) * (-k) - jiggle.velocity * c) * inv_m;
            jiggle.velocity = jiggle.velocity + accel * h;
            jiggle.point = jiggle.point + jiggle.velocity * h;
        }
        jiggle.offset = to_model_dir(jiggle.point - tip_world);
    }

    struct BoneTurn { Affine A; Vec offset; float angle = 0.0f, stretch = 1.0f; };

    // The bone from pivot to tip (model space, posed), up being the head's up: steps its spring and
    // returns the turn and stretch about the pivot that takes the tip to the spring's point, within the
    // limits. force (headless, degrees up and to the side) holds it instead.
    BoneTurn jiggle_bone(Jiggle& jiggle, Vec pivot, Vec tip, Vec up, const float* force) {
        BoneTurn r;
        r.A = { rotation({ 1, 0, 0 }, 0.0f), { 0, 0, 0 } };
        const Vec arm = tip - pivot;
        const float la = length(arm);
        if (la < 1e-3f) {
            return r;
        }
        update_jiggle(jiggle, to_world(tip));
        const Vec f = arm * (1.0f / la);
        Vec offset = to_model_dir(jiggle.point - to_world(tip));
        if (force != nullptr) {
            Vec u = up - f * dot(up, f);
            u = u * (1.0f / std::max(length(u), 1e-4f));
            const Vec sd = cross(f, u);
            const float p = force[0] * pi / 180.0f, y = force[1] * pi / 180.0f;
            offset = (f * (std::cos(p) * std::cos(y)) + u * (std::sin(p) * std::cos(y)) + sd * std::sin(y)) * la - arm;
        }
        // Limits: along the bone, back in (squash) and out (stretch); across it, up, down and sideways.
        const float along = std::clamp(dot(offset, f), -settings.inwards * la, settings.outwards * la);
        Vec side = offset - f * dot(offset, f);
        const float ls = length(side), limit = settings.across * la;
        if (ls > limit) {
            side = side * (limit / ls);
        }
        offset = f * along + side;
        r.offset = offset;
        const Vec want = arm + offset;
        const float lw = std::max(length(want), 0.05f * la);
        // Turn the bone to point at it...
        Mat R = rotation({ 1, 0, 0 }, 0.0f);
        {
            const Vec b = want * (1.0f / lw);
            const Vec axis = cross(f, b);
            const float sin_t = length(axis);
            if (sin_t > 1e-5f) {
                r.angle = std::atan2(sin_t, dot(f, b));
                R = rotation(axis * (1.0f / sin_t), r.angle);
            }
        }
        // ...and stretch or squash along it to reach it, keeping its volume (thinner as it gets longer).
        const float st = lw / la;
        r.stretch = st;
        const float d[3] = { f.x, f.y, f.z };
        const float thin = 1.0f / std::sqrt(st);
        Mat S{};
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                S.m[i * 3 + j] = (i == j ? thin : 0.0f) + (st - thin) * d[i] * d[j];
        const Mat Q = mul(S, R);   // p' = pivot + (p - pivot) * S * R
        r.A = { Q, pivot - apply(pivot, Q) };
        return r;
    }

    // ---- the black nose (see the top) ----
    struct Nose {
        uint32_t model = 0;
        std::vector<int> index;
        std::vector<float> weight;
        std::vector<int16_t> original, written;
        Vec pivot{}, tip{};          // the snout bone's vertex space
    } nose;

    bool nose_intact(uint8_t* rdram) {
        const std::vector<int16_t>& expect = nose.written.empty() ? nose.original : nose.written;
        for (size_t k = 0; k < nose.index.size(); k++)
            for (int c = 0; c < 3; c++)
                if (read_half(rdram, vertex_addr(nose.index[k]) + 2 * c) != expect[3 * k + c]) return false;
        return true;
    }

    void restore_nose(uint8_t* rdram) {
        if (nose.model != 0 && !nose.written.empty() && nose.model == current_model && nose_intact(rdram)) {
            for (size_t k = 0; k < nose.index.size(); k++)
                for (int c = 0; c < 3; c++) write_half(rdram, vertex_addr(nose.index[k]) + 2 * c, nose.original[3 * k + c]);
        }
        nose = {};
    }

    // The snout bone's own vertices (draw nodes on bone 10, outside selectors).
    void collect_snout(uint8_t* rdram, uint32_t node, int bone, bool in_selector, int depth, std::vector<int>& out) {
        for (int guard = 0; guard < 4096 && depth < 32; guard++) {
            const uint32_t cmd = read_word(rdram, node), size = read_word(rdram, node + 4);
            if (cmd == 2) {
                collect_snout(rdram, node + read_byte(rdram, node + 8), read_byte(rdram, node + 9), in_selector, depth + 1, out);
            } else if (cmd == 0x0C) {
                const int options = (uint16_t)read_half(rdram, node + 8);
                for (int i = 0; i < options && i < 64; i++)
                    collect_snout(rdram, node + read_word(rdram, node + 12 + 4 * i), bone, true, depth + 1, out);
            } else if (cmd == 0x11 && bone == snout_bone && !in_selector) {
                const int v0 = (uint16_t)read_half(rdram, node + 10), nv = (uint16_t)read_half(rdram, node + 12);
                for (int i = v0; i < v0 + nv; i++) out.push_back(i);
            }
            if (size == 0 || size > 0x100000) return;
            node += size;
        }
    }

    bool prepare_nose(uint8_t* rdram) {
        if (current.vertices <= 0) {
            return false;
        }
        if (nose.model == current_model && !nose.index.empty() && nose_intact(rdram)) {
            return true;
        }
        nose = {};
        nose.model = current_model;
        std::vector<int> all;
        collect_snout(rdram, current_model + read_word(rdram, current_model + 4), -1, false, 0, all);
        std::sort(all.begin(), all.end());
        all.erase(std::unique(all.begin(), all.end()), all.end());
        struct V { int i; Vec p; bool black, white; };
        std::vector<V> verts;
        for (int i : all) {
            if (i < 0 || i >= current.vertices) continue;
            const uint32_t a = vertex_addr(i);
            const Vec p{ (float)read_half(rdram, a), (float)read_half(rdram, a + 2), (float)read_half(rdram, a + 4) };
            const bool black = read_byte(rdram, a + 12) == 0 && read_byte(rdram, a + 13) == 0 && read_byte(rdram, a + 14) == 0;
            const bool white = read_byte(rdram, a + 12) == 0xFF && read_byte(rdram, a + 13) == 0xFF && read_byte(rdram, a + 14) == 0xFF;
            verts.push_back({ i, p, black, white });
        }
        if (verts.empty()) {
            return false;
        }
        std::vector<Vec> black;
        for (const V& v : verts) if (v.black) black.push_back(v.p);
        auto add = [&](const V& v, float w) {
            nose.index.push_back(v.i);
            nose.weight.push_back(w);
            nose.original.push_back((int16_t)v.p.x); nose.original.push_back((int16_t)v.p.y); nose.original.push_back((int16_t)v.p.z);
        };
        Vec sum{ 0, 0, 0 };
        float total = 0.0f, zmin = 1e9f, zmax = -1e9f;
        if (black.size() >= 4) {
            // The game's nose: the black vertices, and the white highlight drawn over them (inside their box).
            Vec lo = black[0], hi = black[0];
            for (const Vec& b : black) {
                lo = { std::min(lo.x, b.x), std::min(lo.y, b.y), std::min(lo.z, b.z) };
                hi = { std::max(hi.x, b.x), std::max(hi.y, b.y), std::max(hi.z, b.z) };
            }
            for (const V& v : verts) {
                const float m = 3.0f;   // 062A's black vertices are not symmetric: one highlight is 2 outside
                const bool on_nose = v.black || (v.white && v.p.x >= lo.x - m && v.p.x <= hi.x + m && v.p.y >= lo.y - m &&
                                                 v.p.y <= hi.y + m && v.p.z >= lo.z - m && v.p.z <= hi.z + m);
                if (on_nose) {
                    add(v, 1.0f);
                    sum = sum + v.p; total += 1.0f;
                    zmin = std::min(zmin, v.p.z); zmax = std::max(zmax, v.p.z);
                }
            }
            const Vec c = sum * (1.0f / total);
            nose.pivot = { c.x, c.y, zmin };
            nose.tip = { c.x, c.y, zmax };
        } else {
            // No black vertices (mods): the front third of the snout's mesh, blended in.
            for (const V& v : verts) { zmin = std::min(zmin, v.p.z); zmax = std::max(zmax, v.p.z); }
            const float span = std::max(zmax - zmin, 1.0f), z0 = zmax - 0.3f * span;
            for (const V& v : verts) {
                const float w = smooth((v.p.z - z0) / (0.15f * span));
                if (w <= 0.0f) continue;
                add(v, w);
                sum = sum + v.p * w; total += w;
            }
            if (total <= 0.0f) {
                return false;
            }
            const Vec c = sum * (1.0f / total);
            nose.pivot = { c.x, c.y, z0 };
            nose.tip = { c.x, c.y, zmax };
        }
        return !nose.index.empty();
    }

    // Swing the nose: m is the snout bone's matrix as drawn (after the snout's own jiggle).
    float jiggle_nose(uint8_t* rdram, const float m[16], Vec up) {
        const BoneTurn turn = jiggle_bone(nose_spring, transform(m, nose.pivot), transform(m, nose.tip), up, nullptr);
        // In the vertex space: v' = pivot + (v - pivot) * M N M^-1.
        const Mat M = upper(m);
        Mat Mi;
        if (!inverse(M, Mi)) {
            return 0.0f;
        }
        const Mat Nb = mul(mul(M, turn.A.L), Mi);
        std::vector<int16_t> out(nose.original.size());
        for (size_t k = 0; k < nose.index.size(); k++) {
            Vec v{ (float)nose.original[3 * k], (float)nose.original[3 * k + 1], (float)nose.original[3 * k + 2] };
            const Vec moved = nose.pivot + apply(v - nose.pivot, Nb);
            v = v + (moved - v) * nose.weight[k];
            out[3 * k] = (int16_t)std::lround(std::clamp(v.x, -32768.0f, 32767.0f));
            out[3 * k + 1] = (int16_t)std::lround(std::clamp(v.y, -32768.0f, 32767.0f));
            out[3 * k + 2] = (int16_t)std::lround(std::clamp(v.z, -32768.0f, 32767.0f));
        }
        for (size_t k = 0; k < nose.index.size(); k++)
            for (int c = 0; c < 3; c++) write_half(rdram, vertex_addr(nose.index[k]) + 2 * c, out[3 * k + c]);
        nose.written = std::move(out);
        return turn.angle;
    }

    // ---- Kazooie's feathers ----
    // Chains of bones, root first: bone indices and the ids that confirm them.
    struct Chain { int count; int bone[4]; int16_t id[4]; };
    // 062A and 0838 (Banjo with Kazooie in the pack). 0838 (Dragon Kazooie) has no crest.
    constexpr Chain pack_chains[] = {
        { 2, { 21, 22 }, { 47, 48 } },                 // crest, on her head (bone 20)
        { 3, { 51, 52, 53 }, { 50, 51, 52 } },         // three tail feathers, on bone 50
        { 3, { 54, 55, 56 }, { 53, 54, 55 } },
        { 3, { 57, 58, 59 }, { 56, 57, 58 } },
    };
    // 061C (Kazooie alone after Split Up): head bone 7 (id 108), crest 8 (id 42) on it.
    constexpr Chain solo_chains[] = {
        { 3, { 8, 9, 10 }, { 42, 43, 44 } },
        { 4, { 44, 45, 46, 47 }, { 57, 58, 59, 60 } },
        { 4, { 48, 49, 50, 51 }, { 61, 62, 63, 64 } },
        { 4, { 52, 53, 54, 55 }, { 65, 66, 67, 68 } },
        { 2, { 56, 57 }, { 91, 93 } },
    };
    // Lighter than the snout: slower, longer wobbles and a wider swing per bone. The Kazooie jiggle
    // sliders scale these (defaults: 2.5 a second, damping 0.15, follow 1.2, 32 degrees per bone).
    struct FeatherSettings { float frequency = 2.5f, damping = 0.15f, follow = 1.2f, max_angle = 32.0f; } feather_settings;
    void read_feather_settings() {
        using namespace tooie::snout_jiggle;
        feather_settings.follow = 1.2f * (float)option_number(kazooie_strength_option, 100.0) / 100.0f;
        // Bounce 0..100 as the snout's: damping 0.33 .. 0.03; 60 is 0.15.
        feather_settings.damping = 0.03f + 0.30f * (1.0f - std::clamp((float)option_number(kazooie_bounce_option, 60.0), 0.0f, 100.0f) / 100.0f);
        feather_settings.frequency = std::clamp((float)option_number(kazooie_speed_option, 2.5), 0.5f, 20.0f);
        feather_settings.max_angle = std::min(32.0f * (float)option_number(kazooie_exaggeration_option, 100.0) / 100.0f, 85.0f);
    }
    constexpr float feather_arm = 12.0f;     // every bone turns as if it were this long
    constexpr int max_feather_bones = 20, max_bones = 64;

    struct Feathers {
        int kind = 0;                        // 0 none, 1 pack, 2 solo: springs start again on a change
        int chains = 0;
        int chain_start[6]{}, chain_count[6]{};
        int bone[max_feather_bones]{};
        Vec pivot[max_feather_bones]{}, tip[max_feather_bones]{};   // bind pose
        int8_t slot_of[max_bones];
        bool done = false;                   // matrices worked out for this draw
        Spring spring[max_feather_bones];
        float max_angle = 0.0f;              // for the log
    } feathers;

    // Which of Kazooie's chains this model has (per draw: the heap reuses memory).
    void pick_feathers(uint8_t* rdram, uint32_t model, bool player) {
        std::memset(feathers.slot_of, -1, sizeof(feathers.slot_of));
        feathers.chains = 0;
        feathers.done = false;
        const uint32_t bones_off = read_word(rdram, model + 0x18);
        if (bones_off == 0 || bones_off >= 0x200000) {
            return;
        }
        const uint32_t bones = model + bones_off;
        const int count = (uint16_t)read_half(rdram, bones + 4);
        auto bone = [&](int i) { return bones + 8 + 16 * i; };
        auto id = [&](int i) { return read_half(rdram, bone(i) + 12); };
        auto parent = [&](int i) { return (int)read_half(rdram, bone(i) + 14); };
        auto pos = [&](int i) { return Vec{ read_float(rdram, bone(i)), read_float(rdram, bone(i) + 4), read_float(rdram, bone(i) + 8) }; };
        const Chain* list = nullptr;
        int n = 0, kind = 0;
        if (player) {
            list = pack_chains; n = (int)std::size(pack_chains); kind = 1;
        } else if (count > 57 && count <= max_bones && id(7) == 108 && id(8) == 42 && parent(8) == 7) {
            list = solo_chains; n = (int)std::size(solo_chains); kind = 2;
        } else {
            return;
        }
        if (kind != feathers.kind) {
            for (Spring& s : feathers.spring) s = {};
            feathers.kind = kind;
        }
        int slot = 0;
        for (int c = 0; c < n; c++) {
            const Chain& chain = list[c];
            bool ok = slot + chain.count <= max_feather_bones;
            for (int j = 0; ok && j < chain.count; j++) {
                const int b = chain.bone[j];
                ok = b < count && b < max_bones && id(b) == chain.id[j] && (j == 0 || parent(b) == chain.bone[j - 1]);
            }
            // Keep each chain on the same springs whichever chains are missing.
            const int first = c * 4;
            if (!ok || first + chain.count > max_feather_bones) {
                continue;
            }
            slot = first;
            feathers.chain_start[feathers.chains] = slot;
            feathers.chain_count[feathers.chains] = chain.count;
            feathers.chains++;
            for (int j = 0; j < chain.count; j++, slot++) {
                const int b = chain.bone[j];
                feathers.bone[slot] = b;
                feathers.slot_of[b] = (int8_t)slot;
                feathers.pivot[slot] = pos(b);
                // The end of the bone: the next one's pivot, or for the last one as far again along the
                // one before it.
                if (j + 1 < chain.count) {
                    feathers.tip[slot] = pos(chain.bone[j + 1]);
                } else {
                    const Vec from = pos(parent(b) >= 0 && parent(b) < count ? parent(b) : b);
                    Vec d = feathers.pivot[slot] - from;
                    const float l = length(d);
                    d = l > 1e-3f ? d * (std::max(l, 6.0f) / l) : Vec{ 0, 6, 0 };
                    feathers.tip[slot] = feathers.pivot[slot] + d;
                }
            }
        }
    }

    // Every feather bone's turned matrix, into its copy. list = the matrix list (bone 0's matrix).
    void work_out_feathers(uint8_t* rdram, uint32_t list) {
        feathers.done = true;
        feathers.max_angle = 0.0f;
        for (int c = 0; c < feathers.chains; c++) {
            Affine C{ rotation({ 1, 0, 0 }, 0.0f), { 0, 0, 0 } };
            for (int j = 0; j < feathers.chain_count[c]; j++) {
                const int slot = feathers.chain_start[c] + j;
                float m[16], m1[16];
                for (int i = 0; i < 16; i++) m[i] = read_float(rdram, list + 64 * feathers.bone[slot] + 4 * i);
                // Where the bone is once the bones before it in the chain have turned.
                apply_affine(m, C, m1);
                const Vec pivot = transform(m1, feathers.pivot[slot]);
                const Vec end = transform(m1, feathers.tip[slot]);
                Spring& s = feathers.spring[slot];
                update_spring(s, to_world(end), feather_settings.frequency, feather_settings.damping);
                const Vec arm = end - pivot;
                const float la = length(arm);
                if (la > 1e-3f) {
                    float angle;
                    const Mat R = aim(arm * (feather_arm / la), to_model_dir(s.lag) * feather_settings.follow, feather_settings.max_angle, angle);
                    feathers.max_angle = std::max(feathers.max_angle, angle);
                    C = then(C, Affine{ R, pivot - apply(pivot, R) });
                }
                float out[16];
                apply_affine(m, C, out);
                for (int i = 0; i < 16; i++) write_float(rdram, feather_copies + 64 * slot + 4 * i, out[i]);
            }
        }
    }
}

// func_800DE498 once it has settled on the model it draws (0x10C($sp), with the shadow hook):
// position (copied to 0xE0($sp)), rotation pointer (0x100($sp), degrees) and scale (0x104($sp)).
extern "C" void tooie_snout_model(uint8_t* rdram, recomp_context* ctx) {
    drawing_player = false;
    have_head = false;
    feathers.chains = 0;
    const uint32_t sp = (uint32_t)ctx->r29;
    const uint32_t model = read_word(rdram, sp + 0x10C);
    tooie::size_cheats::model(rdram, model);
    if (!valid_ptr(model)) {
        return;
    }
    const bool on = option_bool(tooie::snout_jiggle::option);
    const bool feathers_on = option_bool(tooie::snout_jiggle::kazooie_option);
    snout_on = on;
    nose_on = on && option_bool(tooie::snout_jiggle::nose_option);
    if (!on && !feathers_on && muzzle.model == 0 && nose.model == 0) {
        return;
    }
    const ModelInfo info = info_for(rdram, model);
    if (feathers_on) {
        pick_feathers(rdram, model, info.player);
        if (feathers.chains != 0) {
            read_feather_settings();
        }
    }
    if (info.player) {
        current_model = model;
        current = info;
        if (on) {
            drawing_player = true;
            read_settings();
        } else {
            restore_muzzle(rdram);
        }
        if (!nose_on) {
            restore_nose(rdram);
        }
        const bool bending = (on && current.vertices > 0 && current.vertices <= vanilla_vertices) || nose_on;
        bent_from = bending ? (model & 0x1FFFFFFF) : 0;
        bent_to = bending ? ((current.vtx + 0x18 + 16 * current.vertices) & 0x1FFFFFFF) : 0;
    }
    if (!drawing_player && feathers.chains == 0) {
        return;
    }
    model_pos = { read_float(rdram, sp + 0xE0), read_float(rdram, sp + 0xE4), read_float(rdram, sp + 0xE8) };
    const uint32_t rot = read_word(rdram, sp + 0x100);
    model_yaw = valid_ptr(rot) ? read_float(rdram, rot + 4) : 0.0f;
    const float scale = read_float(rdram, sp + 0x104);
    model_scale = (scale > 0.01f && scale < 100.0f) ? scale : 1.0f;
}

static void snout_bone_node(uint8_t* rdram, recomp_context* ctx);

// func_800DCF48 (a bone node) after func_800ADE2C returned the bone's matrix in $v0, before
// func_80019AA0 pushes it ($a1 = $v0 in the delay slot). The size cheats scale what Snout jiggle leaves.
extern "C" void tooie_snout_bone(uint8_t* rdram, recomp_context* ctx) {
    snout_bone_node(rdram, ctx);
    const uint32_t node = read_word(rdram, (uint32_t)ctx->r29 + 0x24);
    if (valid_ptr(node)) {
        tooie::size_cheats::bone(rdram, ctx, read_byte(rdram, node + 9));
    }
}

static void snout_bone_node(uint8_t* rdram, recomp_context* ctx) {
    if (!drawing_player && feathers.chains == 0) {
        return;
    }
    const uint32_t node = read_word(rdram, (uint32_t)ctx->r29 + 0x24);
    if (!valid_ptr(node)) {
        return;
    }
    const int bone = read_byte(rdram, node + 9);
    const uint32_t src = (uint32_t)ctx->r2;
    if (!valid_ptr(src)) {
        return;
    }
    // Kazooie's feathers: the matrix list holds every bone's matrix, 64 bytes each (func_800ADE2C).
    if (feathers.chains != 0 && bone < max_bones && feathers.slot_of[bone] >= 0) {
        if (!feathers.done) {
            work_out_feathers(rdram, src - 64 * bone);
            if (logging()) {
                static int n = 0;
                if (++n % 15 == 0) {
                    printf("[kazooie] kind %d chains %d max angle %.1f%s\n", feathers.kind, feathers.chains,
                           feathers.max_angle * 180.0f / pi, tooie::photo_mode::active() ? " (photo)" : "");
                    fflush(stdout);
                }
            }
        }
        ctx->r2 = (gpr)(int32_t)(feather_copies + 64 * feathers.slot_of[bone]);
        return;
    }
    if (!drawing_player || (bone != snout_bone && bone != head_bone)) {
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
    if (!snout_on) {
        return;
    }
    const Vec pivot = transform(m, current.pivot);   // the corners of the mouth (vanilla) or the root
    const Vec tip = transform(m, current.tip);
    if (length(tip - pivot) < 1e-3f) {
        return;
    }
    const Vec head_up{ m[4], m[5], m[6] };

    // Headless: TOOIE_SNOUT_FORCE=<up>,<side> (degrees) holds the snout there, for close-ups.
    static const char* force_env = std::getenv("TOOIE_SNOUT_FORCE");
    float force[2] = { 0.0f, 0.0f };
    const bool forced = force_env != nullptr && std::sscanf(force_env, "%f,%f", &force[0], &force[1]) >= 1;
    const BoneTurn turn = jiggle_bone(snout_spring, pivot, tip, head_up, forced ? force : nullptr);
    const Affine& A = turn.A;

    float out[16];
    apply_affine(m, A, out);
    for (int i = 0; i < 16; i++) {
        write_float(rdram, matrix_copy + 4 * i, out[i]);
    }
    ctx->r2 = (gpr)(int32_t)matrix_copy;

    // The muzzle and the mouth on the game's own models.
    if (have_head && prepare_muzzle(rdram)) {
        bend_muzzle(rdram, A, head_matrix);
    }
    float nose_angle = 0.0f;
    if (nose_on && prepare_nose(rdram)) {
        nose_angle = jiggle_nose(rdram, out, Vec{ out[4], out[5], out[6] });
    }
    if (logging()) {
        static int n = 0;
        if (++n % 15 == 0) {
            printf("[snout] pos %.0f,%.0f,%.0f yaw %.0f vel %.0f,%.0f,%.0f offset %.1f,%.1f,%.1f angle %.1f stretch %.2f muzzle %zu nose %.1f/%zu%s\n",
                   model_pos.x, model_pos.y, model_pos.z, model_yaw, snout_spring.velocity.x, snout_spring.velocity.y, snout_spring.velocity.z,
                   turn.offset.x, turn.offset.y, turn.offset.z, turn.angle * 180.0f / pi, turn.stretch, muzzle.index.size(),
                   nose_angle * 180.0f / pi, nose.index.size(),
                   tooie::photo_mode::active() ? " (photo)" : "");
            fflush(stdout);
        }
    }
}

bool tooie::snout_jiggle::blend_vertices(uint32_t first_list_phys) {
    const uint32_t from = bent_from, to = bent_to;
    const bool hit = from != 0 && first_list_phys >= from && first_list_phys < to;
    if (from != 0 && logging()) {
        static int n = 0;
        if (++n % 200 == 0) {
            printf("[snout] blend check %08X in %08X-%08X: %d\n", first_list_phys, from, to, hit);
            fflush(stdout);
        }
    }
    return hit;
}
