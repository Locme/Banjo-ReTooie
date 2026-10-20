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
//   outwards (stretching) and up, down or to the side, each its own slider; while he walks or runs
//   on the ground the inwards limit eases to its own Walking slider, so walking forward doesn't
//   squash his face (L, 2026-10-18). It steps by the game's
//   own clock, so it behaves the same at any frame rate and never snaps back after a hitch.
// - Sliders (tooie_snout_jiggle.h): stiffness, damping, mass and the three limits.
// - Nose jiggle (L, 2026-10-18, its own toggle under Snout jiggle): the black nose is a second jiggle
//   bone with the same spring, from its base to its tip, on the end of the swung snout; its limits
//   are capped so it always stays a whole nose (L, 2026-10-18). Its vertices
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
// General > Backpack jiggle (L, 2026-10-19, its own toggle and sliders; first tried on every bone,
// L: "just add it to the backpack instead", "like the snout, just one bone/point"): one jiggle bone,
// the backpack (062A bone 13, id 60, under bone 12 id 59 on the chest), found by id so 0838 and Smash
// Banjo work too. It swings about its root towards a point on a spring at its tip and carries the lid
// and Kazooie riding in it (her feathers, when Kazooie jiggle is on, start from there). Re-added
// (L, 2026-10-19) after being taken out for fighting Kazooie's animations: while she is out of the
// pack (a double jump, say) it holds still mid-swing and picks up again when she is back in.
//
// General > Kazooie jiggle (L, 2026-10-17, its own toggle): Kazooie's crest and tail feathers
// are jiggle bones like the snout (L, 2026-10-19), with her own sliders of the same kinds. Each
// feather bone has its own spring point at its end, from the root of the chain out, and each bone's
// swing carries the bones after it, so the tail whips. Her bones are found by index and id: 062A and
// 0838 (in the backpack; Smash Banjo keeps them) and 061C (alone after Split Up).
//
// Belly jiggle (L, 2026-10-19, its own toggle and sliders of the snout's kinds): the front of Banjo's
// belly (the chest bone's vertices and its skin down to his belt, round 0,66,17 on the game's own
// models) is a jiggle bone from inside his middle, written into the vertex list like the muzzle; it
// fades out at the belt, the fur and the chest so nothing comes apart. (L, 2026-10-20: it sat up at
// the necklace and read as a chest jiggle; it now sits just above his belt.) Not on mods with many vertices.
//
// Mumbo jiggle (L, 2026-10-19, its own toggle, Kazooie's sliders): the three feathers on Mumbo's
// head (asset 0665, playable and in his skulls: bones 4-6, 7-9 and 10-12 on head bone 2) are jiggle
// bones the same way.
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
        float walk_inwards = 0.15f;   // the inwards limit while he walks or runs on the ground (L, 2026-10-18)
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
        settings.walk_inwards = std::clamp((float)option_number(squash_walk_option, 15.0), 0.0f, 95.0f) / 100.0f;
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
    // The nose's vertices are rewritten: Nose jiggle, or Snout jiggle on the game's own models (the nose
    // keeps its size when the snout squashes).
    bool nose_kept = false;
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

    // ---- the jiggle bones: the snout, the nose, the belly, the backpack and the feathers (see the top) ----
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
    // The spring: stiffness, damping and mass.
    struct Feel { float stiffness, damping, mass; };

    void update_jiggle(Jiggle& jiggle, Vec tip_world, const Feel& feel) {
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
        const float k = feel.stiffness, c = feel.damping, inv_m = 1.0f / feel.mass;
        for (float t = 0.0f; t < dt; t += step) {
            const float h = std::min(step, dt - t);
            const Vec accel = ((jiggle.point - tip_world) * (-k) - jiggle.velocity * c) * inv_m;
            jiggle.velocity = jiggle.velocity + accel * h;
            jiggle.point = jiggle.point + jiggle.velocity * h;
        }
        jiggle.offset = to_model_dir(jiggle.point - tip_world);
    }

    // Walking (L, 2026-10-18: walking forward smushed his face in): 1 while he moves along the ground,
    // 0 in the air or standing, eased so the limit never jumps. From the model's own movement, once per
    // game frame.
    struct Walk {
        bool started = false;
        Vec last_pos{};
        double last = 0.0;
        float amount = 0.0f;
        float moving = 0.0f;   // 1 while the model moves at all (walking, jumping, falling), 0 standing
    } walk;

    void update_walk() {
        if (tooie::photo_mode::active()) {
            return;
        }
        const double now = tooie::game_frame_rate::game_seconds();
        const float dt = (float)(now - walk.last);
        if (!walk.started || dt > 0.25f) {
            walk.started = true;
            walk.last = now;
            walk.last_pos = model_pos;
            return;
        }
        if (dt <= 1e-5f) {
            return;
        }
        const Vec d = model_pos - walk.last_pos;
        walk.last = now;
        walk.last_pos = model_pos;
        const float ground = std::sqrt(d.x * d.x + d.z * d.z) / dt, up = std::fabs(d.y) / dt;
        // Moving along (world units a second) and not much up or down: slopes and steps, not jumps or falls.
        const float target = (ground > 40.0f && ground < 2000.0f && up < std::max(150.0f, 0.6f * ground)) ? 1.0f : 0.0f;
        walk.amount += (target - walk.amount) * std::min(1.0f, dt * 6.0f);
        const float moves = (ground > 20.0f || up > 20.0f) ? 1.0f : 0.0f;
        walk.moving += (moves - walk.moving) * std::min(1.0f, dt * (moves > walk.moving ? 8.0f : 3.0f));
    }

    // Shares of the bone's length its tip may move, and the most it may stretch or squash (the nose
    // keeps its shape: L, 2026-10-18, "make sure it is always whole").
    struct Limits { float inwards, outwards, across; };
    Limits snout_limits() {
        const float in = settings.inwards + (std::min(settings.walk_inwards, settings.inwards) - settings.inwards) * walk.amount;
        return { in, settings.outwards, settings.across };
    }
    Limits nose_limits() {
        return { std::min(settings.inwards, 0.15f), std::min(settings.outwards, 0.2f), std::min(settings.across, 0.35f) };
    }

    struct BoneTurn { Affine A; Mat R; Vec offset; float angle = 0.0f, stretch = 1.0f; };   // A = squash and stretch, then R

    // The bone from pivot to tip (model space, posed), up being the head's up: steps its spring and
    // returns the turn and stretch about the pivot that takes the tip to the spring's point, within the
    // limits. force (headless, degrees up and to the side) holds it instead.
    Feel snout_feel() { return { settings.stiffness, settings.damping, settings.mass }; }

    // hold: stay as it is in the bone's own frame, the spring paused (the backpack while Kazooie is out).
    BoneTurn jiggle_bone(Jiggle& jiggle, Vec pivot, Vec tip, Vec up, const Feel& feel, const Limits& lim, const float* force,
                         bool hold = false) {
        BoneTurn r;
        r.A = { rotation({ 1, 0, 0 }, 0.0f), { 0, 0, 0 } };
        r.R = r.A.L;
        const Vec arm = tip - pivot;
        const float la = length(arm);
        if (la < 1e-3f) {
            return r;
        }
        if (hold && jiggle.started) {
            // Carried along as it is: the point follows the tip, still, and picks up from there after.
            jiggle.point = to_world(tip) + to_world(jiggle.offset) - to_world(Vec{ 0, 0, 0 });
            jiggle.velocity = {};
            jiggle.last = tooie::game_frame_rate::game_seconds();
        } else {
            update_jiggle(jiggle, to_world(tip), feel);
        }
        const Vec f = arm * (1.0f / la);
        Vec offset = hold && jiggle.started ? jiggle.offset : to_model_dir(jiggle.point - to_world(tip));
        if (force != nullptr) {
            Vec u = up - f * dot(up, f);
            u = u * (1.0f / std::max(length(u), 1e-4f));
            const Vec sd = cross(f, u);
            const float p = force[0] * pi / 180.0f, y = force[1] * pi / 180.0f;
            offset = (f * (std::cos(p) * std::cos(y)) + u * (std::sin(p) * std::cos(y)) + sd * std::sin(y)) * (la * force[2]) - arm;
        }
        // Limits: along the bone, back in (squash) and out (stretch); across it, up, down and sideways.
        const float along = std::clamp(dot(offset, f), -lim.inwards * la, lim.outwards * la);
        Vec side = offset - f * dot(offset, f);
        const float ls = length(side), limit = lim.across * la;
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
        // Keeping the volume, but never more than 1.4 times as thick or less than 0.7 (L, 2026-10-20:
        // at 95% inwards the snout grew 4.5 times as wide and its nose with it).
        const float thin = std::clamp(1.0f / std::sqrt(st), 0.7f, 1.4f);
        Mat S{};
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                S.m[i * 3 + j] = (i == j ? thin : 0.0f) + (st - thin) * d[i] * d[j];
        const Mat Q = mul(S, R);   // p' = pivot + (p - pivot) * S * R
        r.A = { Q, pivot - apply(pivot, Q) };
        r.R = R;
        return r;
    }

    // ---- the black nose (see the top) ----
    struct Nose {
        uint32_t model = 0, vtx = 0;
        std::vector<int> index;
        std::vector<float> weight;
        std::vector<int16_t> original, written;
        Vec pivot{}, tip{};          // the snout bone's vertex space
    } nose;

    uint32_t nose_vertex(int i) { return nose.vtx + 0x18 + 16 * i; }

    bool nose_intact(uint8_t* rdram) {
        const std::vector<int16_t>& expect = nose.written.empty() ? nose.original : nose.written;
        for (size_t k = 0; k < nose.index.size(); k++)
            for (int c = 0; c < 3; c++)
                if (read_half(rdram, nose_vertex(nose.index[k]) + 2 * c) != expect[3 * k + c]) return false;
        return true;
    }

    // Puts the nose back on whichever model it was last written into (another player model drawn in
    // between must not keep a swung nose, or its swung vertices would be read as the rest next time).
    void restore_nose(uint8_t* rdram) {
        if (nose.model != 0 && !nose.written.empty() && valid_ptr(nose.vtx) && nose_intact(rdram)) {
            for (size_t k = 0; k < nose.index.size(); k++)
                for (int c = 0; c < 3; c++) write_half(rdram, nose_vertex(nose.index[k]) + 2 * c, nose.original[3 * k + c]);
        }
        nose = {};
    }

    // A bone's own vertices (draw nodes on that bone, outside selectors).
    void collect_bone(uint8_t* rdram, uint32_t node, int bone, bool in_selector, int depth, int target, std::vector<int>& out) {
        for (int guard = 0; guard < 4096 && depth < 32; guard++) {
            const uint32_t cmd = read_word(rdram, node), size = read_word(rdram, node + 4);
            if (cmd == 2) {
                collect_bone(rdram, node + read_byte(rdram, node + 8), read_byte(rdram, node + 9), in_selector, depth + 1, target, out);
            } else if (cmd == 0x0C) {
                const int options = (uint16_t)read_half(rdram, node + 8);
                for (int i = 0; i < options && i < 64; i++)
                    collect_bone(rdram, node + read_word(rdram, node + 12 + 4 * i), bone, true, depth + 1, target, out);
            } else if (cmd == 0x11 && bone == target && !in_selector) {
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
        if (nose.model == current_model && nose.vtx == current.vtx && !nose.index.empty() && nose_intact(rdram)) {
            return true;
        }
        restore_nose(rdram);
        nose.model = current_model;
        nose.vtx = current.vtx;
        std::vector<int> all;
        collect_bone(rdram, current_model + read_word(rdram, current_model + 4), -1, false, 0, snout_bone, all);
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
            // 062A's black vertices are only the nose's right half (and the middle); the left half is drawn
            // from its own vertices (146-151), mirror images of black ones. Their colours are relit every
            // frame, so they are found by position: a vertex on a black one or on its mirror image. Picking
            // them by colour missed them under some lights, and the halves split down the middle as the
            // nose swung (L, 2026-10-20, a missing triangle at the tip).
            auto on_black = [&](const Vec& p) {
                for (const Vec& b : black)
                    if (std::fabs(std::fabs(p.x) - std::fabs(b.x)) < 0.5f && std::fabs(p.y - b.y) < 0.5f && std::fabs(p.z - b.z) < 0.5f) return true;
                return false;
            };
            for (const V& v : verts) {
                const float m = 3.0f;
                const bool inside = v.p.x >= -std::max(std::fabs(lo.x), std::fabs(hi.x)) - m && v.p.x <= std::max(std::fabs(lo.x), std::fabs(hi.x)) + m &&
                                    v.p.y >= lo.y - m && v.p.y <= hi.y + m && v.p.z >= lo.z - m && v.p.z <= hi.z + m;
                const bool on_nose = v.black || (inside && (v.white || on_black(v.p)));
                if (on_nose) {
                    add(v, 1.0f);
                    sum = sum + v.p; total += 1.0f;
                    zmin = std::min(zmin, v.p.z); zmax = std::max(zmax, v.p.z);
                }
            }
            // The nose stays joined to the snout (L, 2026-10-18, "still not connected"): its back ring,
            // where it meets the snout's skin (062A: z 45-48 of 45-56), stays put and the swing blends in
            // towards the tip. Weights follow the bind position, so the black and white vertices at the
            // same place move together.
            const float ring = zmin + 0.35f * (zmax - zmin);
            Vec ring_sum{ 0, 0, 0 };
            float ring_n = 0.0f;
            for (size_t k = 0; k < nose.index.size(); k++) {
                const Vec p{ (float)nose.original[3 * k], (float)nose.original[3 * k + 1], (float)nose.original[3 * k + 2] };
                nose.weight[k] = smooth((p.z - ring) / std::max(zmax - ring, 1.0f));
                if (p.z <= ring) { ring_sum = ring_sum + p; ring_n += 1.0f; }
            }
            const Vec c = sum * (1.0f / total);
            const Vec base = ring_n > 0.0f ? ring_sum * (1.0f / ring_n) : Vec{ c.x, c.y, zmin };
            nose.pivot = base;
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

    // The nose on the end of the snout: raw is the snout bone's matrix from the animation, drawn its
    // matrix after the snout's jiggle, snout_turn the snout's own turn (no squash). The nose keeps its
    // own size whatever the snout's squash and stretch do (L, 2026-10-20: a squashed snout grew a huge
    // black nose, 4.5 times as wide at 95% inwards): its back ring stays on the snout's skin and the rest
    // is turned with the snout but not squashed. swing: Nose jiggle's own spring on top.
    float jiggle_nose(uint8_t* rdram, const float raw[16], const float drawn[16], const Mat& snout_turn, bool swing) {
        BoneTurn turn;
        turn.A = { rotation({ 1, 0, 0 }, 0.0f), { 0, 0, 0 } };
        if (swing) {
            // Headless: TOOIE_NOSE_FORCE=<up>,<side>[,<length>] holds the nose there, as TOOIE_SNOUT_FORCE.
            static const char* force_env = std::getenv("TOOIE_NOSE_FORCE");
            float force[3] = { 0.0f, 0.0f, 1.0f };
            const bool forced = force_env != nullptr && std::sscanf(force_env, "%f,%f,%f", &force[0], &force[1], &force[2]) >= 1;
            turn = jiggle_bone(nose_spring, transform(drawn, nose.pivot), transform(drawn, nose.tip), Vec{ drawn[4], drawn[5], drawn[6] },
                               snout_feel(), forced ? Limits{ 1.0f, 3.0f, 3.0f } : nose_limits(), forced ? force : nullptr);
        }
        // In the vertex space: drawn = v * D + t, and the nose should be base + (v - base) * Mr * R * N, so
        // v' = base + (v - base) * Mr * R * N * D^-1.
        const Mat D = upper(drawn);
        Mat Di;
        if (!inverse(D, Di)) {
            return 0.0f;
        }
        const Mat Nb = mul(mul(mul(upper(raw), snout_turn), turn.A.L), Di);
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
            for (int c = 0; c < 3; c++) write_half(rdram, nose_vertex(nose.index[k]) + 2 * c, out[3 * k + c]);
        nose.written = std::move(out);
        return turn.angle;
    }

    // ---- the belly (see the top) ----
    // The front of Banjo's belly (the game's own models: the chest bone 2's vertices and the bone-2
    // half of its skin down to the belt) is a jiggle bone from inside his middle to the front, its own
    // sliders of the snout's kinds. Weights follow the bind position: full just above the belt, none
    // at the belt itself (the skin's half on the hips), the fur and the chest, so nothing comes apart.
    constexpr int belly_bone = 2;
    constexpr float belly_pivot[3] = { 0.0f, 66.0f, 2.0f }, belly_tip[3] = { 0.0f, 66.0f, 17.0f };

    struct BellySettings { Feel feel{ 150.0f, 12.0f, 1.0f }; Limits lim{ 0.25f, 0.25f, 0.25f }; } belly_settings;
    void read_belly_settings() {
        using namespace tooie::snout_jiggle;
        belly_settings.feel.stiffness = std::clamp((float)option_number(belly_stiffness_option, 150.0), 1.0f, 2000.0f);
        belly_settings.feel.damping = std::clamp((float)option_number(belly_damping_option, 12.0), 0.0f, 200.0f);
        belly_settings.feel.mass = std::clamp((float)option_number(belly_mass_option, 1.0), 0.05f, 20.0f);
        belly_settings.lim.inwards = std::clamp((float)option_number(belly_squash_in_option, 25.0), 0.0f, 95.0f) / 100.0f;
        belly_settings.lim.outwards = std::clamp((float)option_number(belly_squash_out_option, 25.0), 0.0f, 300.0f) / 100.0f;
        belly_settings.lim.across = std::clamp((float)option_number(belly_squash_across_option, 25.0), 0.0f, 300.0f) / 100.0f;
    }

    bool belly_on = false;
    Jiggle belly_spring;

    struct Belly {
        uint32_t model = 0, vtx = 0;
        std::vector<int> index;
        std::vector<float> weight;
        std::vector<int16_t> original, written;
    } belly;

    uint32_t belly_vertex(int i) { return belly.vtx + 0x18 + 16 * i; }

    bool belly_intact(uint8_t* rdram) {
        const std::vector<int16_t>& expect = belly.written.empty() ? belly.original : belly.written;
        for (size_t k = 0; k < belly.index.size(); k++)
            for (int c = 0; c < 3; c++)
                if (read_half(rdram, belly_vertex(belly.index[k]) + 2 * c) != expect[3 * k + c]) return false;
        return true;
    }

    void restore_belly(uint8_t* rdram) {
        if (belly.model != 0 && !belly.written.empty() && valid_ptr(belly.vtx) && belly_intact(rdram)) {
            for (size_t k = 0; k < belly.index.size(); k++)
                for (int c = 0; c < 3; c++) write_half(rdram, belly_vertex(belly.index[k]) + 2 * c, belly.original[3 * k + c]);
        }
        belly = {};
    }

    // How much of the belly a bind position is (vanilla 062A: the belt at y 56, where the skin's hip
    // half sits; the belly's lower edge at y 63; the necklace at y 68-76, the chest at y 80-82; the
    // fur's skins at |x| 17 and over). Points shared with other skins (the fur's, the shoulders' and
    // the neck's) all get weight 0, so they move alike.
    float belly_weight(Vec p) {
        return smooth((p.z - 6.0f) / 10.0f) * smooth((p.y - 57.0f) / 6.0f) * (1.0f - smooth((p.y - 72.0f) / 7.0f)) *
               (1.0f - smooth((std::fabs(p.x) - 6.0f) / 11.0f));
    }

    // The bone's own half of the skin nodes on it (the first n_child vertices; the rest are on the parent).
    void collect_skin_child(uint8_t* rdram, uint32_t node, int bone, bool in_selector, int depth, int target, std::vector<int>& out) {
        for (int guard = 0; guard < 4096 && depth < 32; guard++) {
            const uint32_t cmd = read_word(rdram, node), size = read_word(rdram, node + 4);
            if (cmd == 2) {
                collect_skin_child(rdram, node + read_byte(rdram, node + 8), read_byte(rdram, node + 9), in_selector, depth + 1, target, out);
            } else if (cmd == 0x0C) {
                const int options = (uint16_t)read_half(rdram, node + 8);
                for (int i = 0; i < options && i < 64; i++)
                    collect_skin_child(rdram, node + read_word(rdram, node + 12 + 4 * i), bone, true, depth + 1, target, out);
            } else if (cmd == 0x18 && bone == target && !in_selector) {
                const int n_child = (uint16_t)read_half(rdram, node + 32), v0 = (uint16_t)read_half(rdram, node + 44);
                for (int i = v0; i < v0 + n_child; i++) out.push_back(i);
            }
            if (size == 0 || size > 0x100000) return;
            node += size;
        }
    }

    bool prepare_belly(uint8_t* rdram) {
        if (current.vertices <= 0 || current.vertices > vanilla_vertices) {
            return false;
        }
        if (belly.model == current_model && belly.vtx == current.vtx && !belly.index.empty() && belly_intact(rdram)) {
            return true;
        }
        restore_belly(rdram);
        belly.model = current_model;
        belly.vtx = current.vtx;
        std::vector<int> all;
        const uint32_t geo = current_model + read_word(rdram, current_model + 4);
        collect_bone(rdram, geo, -1, false, 0, belly_bone, all);
        collect_skin_child(rdram, geo, -1, false, 0, belly_bone, all);
        std::sort(all.begin(), all.end());
        all.erase(std::unique(all.begin(), all.end()), all.end());
        for (int i : all) {
            if (i < 0 || i >= current.vertices) continue;
            const uint32_t a = belly_vertex(i);
            const Vec p{ (float)read_half(rdram, a), (float)read_half(rdram, a + 2), (float)read_half(rdram, a + 4) };
            const float w = belly_weight(p);
            if (w <= 0.001f) continue;
            belly.index.push_back(i);
            belly.weight.push_back(w);
            belly.original.push_back((int16_t)p.x); belly.original.push_back((int16_t)p.y); belly.original.push_back((int16_t)p.z);
        }
        return !belly.index.empty();
    }

    // Swing the belly: m is the chest bone's matrix as drawn.
    float jiggle_belly(uint8_t* rdram, const float m[16]) {
        const Vec pivot{ belly_pivot[0], belly_pivot[1], belly_pivot[2] };
        const Vec tip{ belly_tip[0], belly_tip[1], belly_tip[2] };
        // Headless: TOOIE_BELLY_FORCE=<up>,<side>[,<length>] holds the belly there, as TOOIE_SNOUT_FORCE.
        static const char* force_env = std::getenv("TOOIE_BELLY_FORCE");
        float force[3] = { 0.0f, 0.0f, 1.0f };
        const bool forced = force_env != nullptr && std::sscanf(force_env, "%f,%f,%f", &force[0], &force[1], &force[2]) >= 1;
        const BoneTurn turn = jiggle_bone(belly_spring, transform(m, pivot), transform(m, tip), Vec{ m[4], m[5], m[6] },
                                          belly_settings.feel, belly_settings.lim, forced ? force : nullptr);
        // In the vertex space: v' = pivot + (v - pivot) * M N M^-1.
        const Mat M = upper(m);
        Mat Mi;
        if (!inverse(M, Mi)) {
            return 0.0f;
        }
        const Mat Nb = mul(mul(M, turn.A.L), Mi);
        std::vector<int16_t> out(belly.original.size());
        for (size_t k = 0; k < belly.index.size(); k++) {
            Vec v{ (float)belly.original[3 * k], (float)belly.original[3 * k + 1], (float)belly.original[3 * k + 2] };
            const Vec moved = pivot + apply(v - pivot, Nb);
            v = v + (moved - v) * belly.weight[k];
            out[3 * k] = (int16_t)std::lround(std::clamp(v.x, -32768.0f, 32767.0f));
            out[3 * k + 1] = (int16_t)std::lround(std::clamp(v.y, -32768.0f, 32767.0f));
            out[3 * k + 2] = (int16_t)std::lround(std::clamp(v.z, -32768.0f, 32767.0f));
        }
        for (size_t k = 0; k < belly.index.size(); k++)
            for (int c = 0; c < 3; c++) write_half(rdram, belly_vertex(belly.index[k]) + 2 * c, out[3 * k + c]);
        belly.written = std::move(out);
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
    // 0665 (Mumbo, playable and in his skulls): three feathers on his head (bone 2, id 18).
    constexpr Chain mumbo_chains[] = {
        { 3, { 4, 5, 6 }, { 42, 43, 44 } },
        { 3, { 7, 8, 9 }, { 45, 46, 47 } },
        { 3, { 10, 11, 12 }, { 48, 49, 50 } },
    };
    // Her own sliders, the snout's kinds (L, 2026-10-19): the jiggle bone's spring and its limits.
    struct FeatherSettings { Feel feel{ 150.0f, 12.0f, 1.0f }; Limits lim{ 0.5f, 0.5f, 0.5f }; } feather_settings;
    void read_feather_settings() {
        using namespace tooie::snout_jiggle;
        feather_settings.feel.stiffness = std::clamp((float)option_number(kazooie_stiffness_option, 150.0), 1.0f, 2000.0f);
        feather_settings.feel.damping = std::clamp((float)option_number(kazooie_damping_option, 12.0), 0.0f, 200.0f);
        feather_settings.feel.mass = std::clamp((float)option_number(kazooie_mass_option, 1.0), 0.05f, 20.0f);
        feather_settings.lim.inwards = std::clamp((float)option_number(kazooie_squash_in_option, 50.0), 0.0f, 95.0f) / 100.0f;
        feather_settings.lim.outwards = std::clamp((float)option_number(kazooie_squash_out_option, 50.0), 0.0f, 300.0f) / 100.0f;
        feather_settings.lim.across = std::clamp((float)option_number(kazooie_squash_across_option, 50.0), 0.0f, 300.0f) / 100.0f;
    }
    constexpr int max_feather_bones = 20, max_bones = 64;

    struct Feathers {
        int kind = 0;                        // 0 none, 1 pack, 2 solo, 3 Mumbo: springs start again on a change
        int chains = 0;
        int chain_start[6]{}, chain_count[6]{};
        int bone[max_feather_bones]{};
        Vec pivot[max_feather_bones]{}, tip[max_feather_bones]{};   // bind pose
        int8_t slot_of[max_bones];
        bool done = false;                   // matrices worked out for this draw
        Jiggle spring[max_feather_bones];
        float max_angle = 0.0f;              // for the log
    } feathers;

    // Which of Kazooie's chains this model has (per draw: the heap reuses memory).
    void pick_feathers(uint8_t* rdram, uint32_t model, bool player, bool kazooie, bool mumbo) {
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
        if (kazooie && player) {
            list = pack_chains; n = (int)std::size(pack_chains); kind = 1;
        } else if (kazooie && count > 57 && count <= max_bones && id(7) == 108 && id(8) == 42 && parent(8) == 7) {
            list = solo_chains; n = (int)std::size(solo_chains); kind = 2;
        } else if (mumbo && count > 12 && count <= max_bones && id(2) == 18 && id(4) == 42 && parent(4) == 2 &&
                   id(7) == 45 && parent(7) == 2 && id(10) == 48 && parent(10) == 2) {
            list = mumbo_chains; n = (int)std::size(mumbo_chains); kind = 3;
        } else {
            return;
        }
        if (kind != feathers.kind) {
            for (Jiggle& j : feathers.spring) j = {};
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
                const BoneTurn turn = jiggle_bone(feathers.spring[slot], pivot, end, Vec{ m1[4], m1[5], m1[6] },
                                                  feather_settings.feel, feather_settings.lim, nullptr);
                feathers.max_angle = std::max(feathers.max_angle, turn.angle);
                C = then(C, turn.A);
                float out[16];
                apply_affine(m, C, out);
                for (int i = 0; i < 16; i++) write_float(rdram, feather_copies + 64 * slot + 4 * i, out[i]);
            }
        }
    }
    // ---- Backpack jiggle (see the top) ----
    // The backpack's bone is a jiggle bone from its root to its tip (the middle of its children's
    // roots: the lid and Kazooie), with its own sliders; its swing carries the bones under it. Every
    // bone's matrix is copied (the rest unchanged) so whatever reads the list after starts from the
    // swung pack.
    constexpr uint32_t body_copies = 0x80EFB000;   // 64 bytes per bone, after the size cheats' (0x80EF9000)
    // The backpack (062A bone 13), by bone id.
    constexpr int16_t backpack_ids[] = { 60 };
    constexpr int max_body_bones = 128;

    struct BodySettings { Feel feel{ 200.0f, 10.0f, 1.5f }; Limits lim{ 0.25f, 0.25f, 0.25f }; float tilt = 0.0f; } body_settings;

    void read_body_settings() {
        using namespace tooie::snout_jiggle;
        body_settings.feel.stiffness = std::clamp((float)option_number(body_stiffness_option, 200.0), 1.0f, 2000.0f);
        body_settings.feel.damping = std::clamp((float)option_number(body_damping_option, 10.0), 0.0f, 200.0f);
        body_settings.feel.mass = std::clamp((float)option_number(body_mass_option, 1.5), 0.05f, 20.0f);
        // One squash & stretch for every direction (L, 2026-10-19).
        const float squash = std::clamp((float)option_number(body_squash_option, 25.0), 0.0f, 300.0f) / 100.0f;
        body_settings.lim = { std::min(squash, 0.95f), squash, squash };
        body_settings.tilt = std::clamp((float)option_number(body_tilt_option, 0.0), -90.0f, 90.0f) * pi / 180.0f;
    }

    struct Body {
        bool active = false;                 // the player's model is being drawn with Backpack jiggle on
        bool done = false;                   // matrices worked out for this draw
        int count = 0;
        int16_t parent[max_body_bones]{};
        bool jiggles[max_body_bones]{};
        Vec pivot[max_body_bones]{}, tip[max_body_bones]{};   // bind pose
        Jiggle spring[max_body_bones];
        float max_angle = 0.0f;              // for the log
        int kazooie_head = -1;               // her head bone (id 108), drawn only while she is out of the pack
        double kazooie_seen = -1.0;          // game time it was last drawn
    } body;

    // Kazooie is out of the pack (a double jump, a Beak Barge...): the pack holds still mid-swing so
    // it doesn't fight her animation (L, 2026-10-19). Her bones come after the pack's in a draw, so
    // this is from the draws just before.
    bool kazooie_out() {
        return body.kazooie_seen >= 0.0 && tooie::game_frame_rate::game_seconds() - body.kazooie_seen < 0.15;
    }

    // The skeleton, read each draw (the heap reuses memory).
    void read_body(uint8_t* rdram, uint32_t model) {
        body.active = false;
        body.done = false;
        const uint32_t bones = model + read_word(rdram, model + 0x18);
        const int count = (uint16_t)read_half(rdram, bones + 4);
        if (count <= snout_bone || count > max_body_bones) {
            return;
        }
        if (count != body.count) {
            for (Jiggle& j : body.spring) j = {};
        }
        body.kazooie_head = -1;
        body.count = count;
        auto entry = [&](int i) { return bones + 8 + 16 * i; };
        int children[max_body_bones]{};
        Vec child_sum[max_body_bones]{};
        for (int i = 0; i < count; i++) {
            body.pivot[i] = { read_float(rdram, entry(i)), read_float(rdram, entry(i) + 4), read_float(rdram, entry(i) + 8) };
            body.parent[i] = read_half(rdram, entry(i) + 14);
        }
        bool any = false;
        for (int i = 0; i < count; i++) {
            const int p = body.parent[i];
            if (p >= 0 && p < count && p != i) {
                children[p]++;
                child_sum[p] = child_sum[p] + body.pivot[i];
            }
        }
        for (int i = 0; i < count; i++) {
            const int p = body.parent[i];
            const int16_t id = read_half(rdram, entry(i) + 12);
            if (id == 108) body.kazooie_head = i;
            body.jiggles[i] = p >= 0 && p < count && p != i &&
                              std::find(std::begin(backpack_ids), std::end(backpack_ids), id) != std::end(backpack_ids);
            if (children[i] > 0) {
                body.tip[i] = child_sum[i] * (1.0f / (float)children[i]);
            } else if (body.jiggles[i]) {
                body.tip[i] = body.pivot[i] + (body.pivot[i] - body.pivot[p]) * 0.5f;
            }
            if (length(body.tip[i] - body.pivot[i]) < 1.0f) body.jiggles[i] = false;
            any = any || body.jiggles[i];
        }
        body.active = any;
    }

    // All the bones' matrices for this draw, from the game's matrix list (list + 64 * bone) into
    // body_copies + 64 * bone.
    void work_out_body(uint8_t* rdram, uint32_t list) {
        body.done = true;
        body.max_angle = 0.0f;
        update_walk();
        Affine acc[max_body_bones];
        int state[max_body_bones]{};   // 0 not yet, 1 working, 2 done
        const Affine none{ rotation({ 1, 0, 0 }, 0.0f), { 0, 0, 0 } };
        // Parents first, whatever order the list is in.
        auto work = [&](auto& self, int b) -> const Affine& {
            if (state[b] == 2) return acc[b];
            if (state[b] == 1) return none;   // a loop in a broken skeleton
            state[b] = 1;
            const int p = body.parent[b];
            Affine carried = (p >= 0 && p < body.count && p != b) ? self(self, p) : none;
            Affine mine = carried;
            if (body.jiggles[b]) {
                float m[16], m1[16];
                for (int i = 0; i < 16; i++) m[i] = read_float(rdram, list + 64 * b + 4 * i);
                apply_affine(m, carried, m1);
                // Tilt: the pack's rest angle while he walks or runs (L, 2026-10-19: "only affect
                // walking"), eased in and out with the walk, turned about its own side axis at its root
                // (+ leans its top forward, towards his head).
                const float tilt = body_settings.tilt * walk.amount;
                if (tilt != 0.0f) {
                    const Vec side{ m1[0], m1[1], m1[2] };
                    const float ls = length(side);
                    if (ls > 1e-4f) {
                        const Vec root = transform(m1, body.pivot[b]);
                        const Mat R = rotation(side * (1.0f / ls), tilt);
                        carried = then(carried, Affine{ R, root - apply(root, R) });
                        apply_affine(m, carried, m1);
                    }
                }
                const Vec up{ m1[4], m1[5], m1[6] };
                // Not in idle animations (L, 2026-10-19): the swing fades out while he stands still
                // and back in as he moves, so only his own movement swings the pack.
                const Limits lim{ body_settings.lim.inwards * walk.moving, body_settings.lim.outwards * walk.moving,
                                  body_settings.lim.across * walk.moving };
                const BoneTurn turn = jiggle_bone(body.spring[b], transform(m1, body.pivot[b]), transform(m1, body.tip[b]), up,
                                                  body_settings.feel, lim, nullptr, kazooie_out());
                body.max_angle = std::max(body.max_angle, turn.angle);
                mine = then(carried, turn.A);
            }
            acc[b] = mine;
            state[b] = 2;
            return acc[b];
        };
        for (int b = 0; b < body.count; b++) {
            const Affine& a = work(work, b);
            float m[16], out[16];
            for (int i = 0; i < 16; i++) m[i] = read_float(rdram, list + 64 * b + 4 * i);
            apply_affine(m, a, out);
            for (int i = 0; i < 16; i++) write_float(rdram, body_copies + 64 * b + 4 * i, out[i]);
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
    const bool body_on = option_bool(tooie::snout_jiggle::body_option);
    const bool mumbo_on = option_bool(tooie::snout_jiggle::mumbo_option);
    const bool belly_option = option_bool(tooie::snout_jiggle::belly_option);
    body.active = false;
    belly_on = false;
    if (!on && !feathers_on && !body_on && !mumbo_on && !belly_option && muzzle.model == 0 && nose.model == 0 && belly.model == 0) {
        return;
    }
    const ModelInfo info = info_for(rdram, model);
    if (feathers_on || mumbo_on) {
        pick_feathers(rdram, model, info.player, feathers_on, mumbo_on);
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
        nose_kept = on && (nose_on || (current.vertices > 0 && current.vertices <= vanilla_vertices));
        if (!nose_kept) {
            restore_nose(rdram);
        }
        if (body_on) {
            read_body(rdram, model);
            if (body.active) {
                read_body_settings();
            }
        }
        belly_on = belly_option && current.vertices > 0 && current.vertices <= vanilla_vertices;
        if (belly_on) {
            read_belly_settings();
        } else {
            restore_belly(rdram);
        }
        const bool bending = (on && current.vertices > 0 && current.vertices <= vanilla_vertices) || nose_kept || belly_on;
        bent_from = bending ? (model & 0x1FFFFFFF) : 0;
        bent_to = bending ? ((current.vtx + 0x18 + 16 * current.vertices) & 0x1FFFFFFF) : 0;
    }
    if (!drawing_player && feathers.chains == 0 && !body.active && !belly_on) {
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
    if (!drawing_player && feathers.chains == 0 && !body.active && !belly_on) {
        return;
    }
    const uint32_t node = read_word(rdram, (uint32_t)ctx->r29 + 0x24);
    if (!valid_ptr(node)) {
        return;
    }
    const int bone = read_byte(rdram, node + 9);
    uint32_t src = (uint32_t)ctx->r2;
    if (!valid_ptr(src)) {
        return;
    }
    // Backpack jiggle first: everything after (Kazooie's feathers, the snout, the size cheats) starts from
    // the swung bones, read from body_copies laid out like the game's list.
    if (body.active && bone < body.count) {
        if (!body.done) {
            work_out_body(rdram, src - 64 * bone);
            if (logging()) {
                static int n = 0;
                if (++n % 15 == 0) {
                    printf("[backpack] bones %d max angle %.1f%s%s\n", body.count, body.max_angle * 180.0f / pi,
                           kazooie_out() ? " (held: Kazooie out)" : "", tooie::photo_mode::active() ? " (photo)" : "");
                    fflush(stdout);
                }
            }
        }
        src = body_copies + 64 * bone;
        ctx->r2 = (gpr)(int32_t)src;
        if (bone == body.kazooie_head) {
            body.kazooie_seen = tooie::game_frame_rate::game_seconds();
        }
    }
    // The belly, on the chest bone's own vertices.
    if (belly_on && bone == belly_bone && prepare_belly(rdram)) {
        float mb[16];
        for (int i = 0; i < 16; i++) mb[i] = read_float(rdram, src + 4 * i);
        const float a = jiggle_belly(rdram, mb);
        if (logging()) {
            static int n = 0;
            if (++n % 15 == 0) {
                printf("[belly] angle %.1f verts %zu\n", a * 180.0f / pi, belly.index.size());
                fflush(stdout);
            }
        }
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

    // Headless: TOOIE_SNOUT_FORCE=<up>,<side>[,<length>] (degrees; length as a share of the snout's) holds the snout there, for close-ups.
    static const char* force_env = std::getenv("TOOIE_SNOUT_FORCE");
    float force[3] = { 0.0f, 0.0f, 1.0f };
    const bool forced = force_env != nullptr && std::sscanf(force_env, "%f,%f,%f", &force[0], &force[1], &force[2]) >= 1;
    update_walk();
    const BoneTurn turn = jiggle_bone(snout_spring, pivot, tip, head_up, snout_feel(), snout_limits(), forced ? force : nullptr);
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
    if (nose_kept && prepare_nose(rdram)) {
        nose_angle = jiggle_nose(rdram, m, out, turn.R, nose_on);
    }
    if (logging()) {
        static int n = 0;
        if (++n % 15 == 0) {
            printf("[snout] pos %.0f,%.0f,%.0f yaw %.0f vel %.0f,%.0f,%.0f offset %.1f,%.1f,%.1f angle %.1f stretch %.2f walk %.2f muzzle %zu nose %.1f/%zu%s\n",
                   model_pos.x, model_pos.y, model_pos.z, model_yaw, snout_spring.velocity.x, snout_spring.velocity.y, snout_spring.velocity.z,
                   turn.offset.x, turn.offset.y, turn.offset.z, turn.angle * 180.0f / pi, turn.stretch, walk.amount, muzzle.index.size(),
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
