// The save select's hand as the cursor, drawn from the game's own model and animations (L, 2026-10-24):
// WIP > 3D Hand Cursor. The pictures are made here on the CPU, once, from the ROM; hand_cursor.cpp turns
// them into SDL cursors and steps through them.
//
// The hand is actor 0x4AB in overlay chgameselect (its actor info at 0x80808038: model 0x0862, animation
// list at 0x80808020). The list has two animations: 1 is 0x03D0, 1.0 s, the idle the hand plays while it
// waits; 2 is 0x03D4, 2.6 s, which func_80801714 starts when a file is picked (a thumbs up). The ROM has more
// animations for this hand (0x03CF to 0x03D6, 0x0423, 0x04B4); the click uses 0x03D5.
//
// The model (asset kind 0) is skinned in its display list: G_MTX loads (and pushes) the matrix of bone k
// from segment 5 + 0x40 * k before the vertices that follow it, and G_POPMTX goes back to the parent's. Its
// vertices are in model space in the bind pose. The bone list (header +0x18) has each bone's pivot in model
// space, its animation id and its parent. The animation files are the ones hold_to_run.cpp reads; a track is
// evaluated as the game's func_800E04C0 does it, and a bone's three rotations become a quaternion as in
// func_800E084C. A bone's matrix is its parent's times a turn (and scale and move) about its pivot.
//
// The picture is drawn as the game draws it: vertex colour times the CI4 texture (combiner TEXEL0 * SHADE
// with PRIM black and ENV white), or vertex colour alone, no lighting. The sleeve's end is drawn blended by
// its vertex alpha (the game switches to a blended render mode through segment 3 + 0x20), so it fades out. Each frame is drawn 3x larger and
// averaged down for smooth edges.
#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <iterator>
#include <span>
#include <vector>

#include "librecomp/game.hpp"

#include "tooie_asset_mods.h"
#include "tooie_hand_cursor.h"

namespace {
    constexpr uint32_t model_asset = 0x0862;
    constexpr uint32_t idle_asset = 0x03D0;
    constexpr float idle_seconds = 1.0f;
    // The click: 0x03D5, made for the same hand (not in the save select's list), a grab that closes into a
    // fist and opens again (L, 2026-10-24: the pick's thumbs up did not read as a click). Played whole, at the
    // idle's frame rate.
    constexpr uint32_t click_asset = 0x03D5;
    constexpr float click_frames_per_second = 36.0f;
    constexpr int supersample = 3;
    // The ROM as librecomp stores it in the config folder (the game id in main.cpp plus .z64).
    constexpr const char* stored_rom_name = "bt.n64.us.1.0.z64";

    struct Bytes {
        const std::vector<uint8_t>& b;
        bool has(size_t at, size_t n) const { return at + n <= b.size(); }
        uint32_t u32(size_t at) const { return has(at, 4) ? (uint32_t(b[at]) << 24) | (uint32_t(b[at + 1]) << 16) | (uint32_t(b[at + 2]) << 8) | b[at + 3] : 0; }
        uint16_t u16(size_t at) const { return has(at, 2) ? uint16_t((b[at] << 8) | b[at + 1]) : 0; }
        int16_t s16(size_t at) const { return (int16_t)u16(at); }
        float f32(size_t at) const {
            uint32_t w = u32(at);
            float f;
            std::memcpy(&f, &w, sizeof(f));
            return f;
        }
    };

    struct Vec3 {
        float x = 0, y = 0, z = 0;
    };

    // Row-major 3x4: rows of a 3x3 and the move in the last column.
    struct Mat {
        float m[3][4] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0} };
        Vec3 apply(const Vec3& v) const {
            return { m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3],
                     m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3],
                     m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3] };
        }
        Mat operator*(const Mat& o) const {
            Mat r;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 4; j++) {
                    r.m[i][j] = m[i][0] * o.m[0][j] + m[i][1] * o.m[1][j] + m[i][2] * o.m[2][j] + (j == 3 ? m[i][3] : 0.0f);
                }
            }
            return r;
        }
    };

    struct Bone {
        Vec3 pivot;
        int id;
        int parent;
    };

    struct Vertex {
        Vec3 pos;
        int16_t s, t;
        uint8_t rgba[4];
    };

    struct Corner {
        Vec3 pos;
        float s, t;
        float rgba[4];
    };

    struct Tri {
        Corner c[3];
        bool textured;
        // Drawn blended by its vertex alpha: the end of the sleeve, which fades out as on the save select.
        bool translucent;
    };

    struct Texture {
        int w = 0, h = 0;
        std::vector<std::array<uint8_t, 4>> texels;
    };

    struct Model {
        std::vector<uint8_t> bytes;
        uint32_t dl = 0;
        uint32_t seg2 = 0;
        std::vector<Bone> bones;
        std::vector<Vertex> verts;
        Texture tex;
    };

    // --- Animation ---------------------------------------------------------------------------------

    struct Key {
        uint16_t frame;  // frame in the low 14 bits; 0x4000 and 0x8000 ask for the neighbouring keys (a curve)
        int16_t value;
    };

    struct Track {
        int bone_id;
        int type;  // 0-2 rotation x/y/z (degrees), 3-5 scale, 6-8 move; 9-17 the same with angle wrapping
        std::vector<Key> keys;
    };

    struct Anim {
        int start = 0, end = 0;
        std::vector<Track> tracks;
    };

    bool parse_anim(const std::vector<uint8_t>& b, Anim& a) {
        Bytes r{b};
        a.start = r.u16(0);
        a.end = r.u16(2);
        const int count = r.u16(4);
        if (count == 0 || count > 512) {
            return false;
        }
        size_t at = 8;
        for (int i = 0; i < count; i++) {
            if (!r.has(at, 4)) {
                return false;
            }
            const uint16_t head = r.u16(at);
            const int keys = r.u16(at + 2);
            at += 4;
            if (keys == 0 || !r.has(at, keys * 4)) {
                return false;
            }
            Track t{ head >> 4, head & 0xF, {} };
            for (int k = 0; k < keys; k++, at += 4) {
                t.keys.push_back({ r.u16(at), r.s16(at + 2) });
            }
            a.tracks.push_back(std::move(t));
        }
        return true;
    }

    // func_800E04C0: the track's value at frame f; loop is the animation's length when it loops (else 0).
    float evaluate(const Track& tr, float f, int loop) {
        const std::vector<Key>& k = tr.keys;
        const int n = (int)k.size();
        if (n == 1) {
            return k[0].value / 64.0f;
        }
        auto frame = [&](int i) { return (int)(k[i].frame & 0x3FFF); };
        const int t0 = (int)f;
        const int last = n - 1;
        int i1, i2, t1, t2;
        if (t0 < frame(0)) {
            if (loop) {
                i1 = last; i2 = 0; t1 = frame(last) - loop; t2 = frame(0);
            } else {
                i1 = i2 = 0; t1 = t2 = frame(0);
            }
        } else if (t0 >= frame(last)) {
            if (loop) {
                i1 = last; i2 = 0; t1 = frame(last); t2 = frame(0) + loop;
            } else {
                i1 = i2 = last; t1 = t2 = frame(last);
            }
        } else {
            i1 = 0;
            while (i1 + 1 < last && frame(i1 + 1) <= t0) {
                i1++;
            }
            i2 = i1 + 1;
            t1 = frame(i1);
            t2 = frame(i2);
        }
        float a = 1.0f;
        if (!(t2 < t0) && t2 != t1) {
            a = (f - (float)t1) / (float)(t2 - t1);
        }
        int v4, v5 = k[i1].value, v6 = k[i2].value, v7;
        bool curve = (k[i1].frame & 0x4000) != 0;
        if (curve) {
            int j = i1 - 1;
            if (j < 0) {
                j = loop ? last : 0;
            }
            v4 = k[j].value;
        } else {
            v4 = v5;
        }
        if (k[i2].frame & 0x8000) {
            curve = true;
            int j = i2 + 1;
            if (j > last) {
                j = loop ? 0 : last;
            }
            v7 = k[j].value;
        } else {
            v7 = v6;
        }
        const bool wrap = tr.type >= 9;
        if (wrap) {
            // Steps of more than a turn either way are taken the short way round (0xB400 units).
            auto unwrap = [](int d) {
                if ((unsigned)(d + 0x5A00) > 0xB400u) {
                    d += d < 0 ? 0xB400 : -0xB400;
                }
                return d;
            };
            const int d0 = unwrap(v5 - v4), d1 = unwrap(v6 - v5), d2 = unwrap(v7 - v6);
            v5 = v4 + d0;
            v6 = v5 + d1;
            v7 = v6 + d2;
        }
        float value;
        if (curve) {
            const int d = v6 - v5;
            const float A = (float)((v7 - v4) + d - 4 * d);
            const float B = (float)(2 * v4 + 4 * d - v5 - v7);
            const float C = (float)(v6 - v4);
            value = (((A * a + B) * a + C) * a + (float)(2 * v5)) / 128.0f;
        } else {
            value = v5 / 64.0f + (v6 / 64.0f - v5 / 64.0f) * a;
        }
        if (wrap) {
            value -= 360.0f * std::trunc(value / 360.0f);
            if (value < 0) {
                value += 360.0f;
            }
        }
        return value;
    }

    // func_800E084C: the three rotations (degrees) as a quaternion (x, y, z, w). Its sine helper
    // (func_800137AC) returns the cosine in f0 and the sine in f2, so this is the turn Rz * Ry * Rx.
    std::array<float, 4> euler_quat(float rx, float ry, float rz) {
        constexpr float half_rad = 3.14159265f / 360.0f;
        const float sx = std::sin(rx * half_rad), cx = std::cos(rx * half_rad);
        const float sy = std::sin(ry * half_rad), cy = std::cos(ry * half_rad);
        const float sz = std::sin(rz * half_rad), cz = std::cos(rz * half_rad);
        return { sx * cy * cz - cx * sy * sz, cx * sy * cz + sx * cy * sz, cx * cy * sz - sx * sy * cz, cx * cy * cz + sx * sy * sz };
    }

    std::vector<Mat> pose(const Model& model, const Anim& anim, float frame, bool loop) {
        // Per bone id: rotation x/y/z, scale x/y/z, move x/y/z.
        std::vector<std::array<float, 9>> parts(256, { 0, 0, 0, 1, 1, 1, 0, 0, 0 });
        const int length = loop ? anim.end - anim.start : 0;
        // The root bone's turn and move place the whole hand in the save select scene (most of these animations
        // turn it 53 degrees to point at a file), so they are left out: the cursor keeps one upright hand.
        const int root_id = model.bones.empty() ? -1 : model.bones[0].id;
        for (const Track& t : anim.tracks) {
            if (t.bone_id < 256 && t.bone_id != root_id) {
                parts[t.bone_id][t.type >= 9 ? t.type - 9 : t.type] = evaluate(t, frame, length);
            }
        }
        std::vector<Mat> mats;
        for (const Bone& b : model.bones) {
            const std::array<float, 9>& p = parts[std::clamp(b.id, 0, 255)];
            const auto q = euler_quat(p[0], p[1], p[2]);
            const float x = q[0], y = q[1], z = q[2], w = q[3];
            // func_800D965C writes the transpose of this, as the game's matrices take row vectors (v * M).
            const float R[3][3] = {
                { 1 - 2 * (y * y + z * z), 2 * (x * y - z * w), 2 * (x * z + y * w) },
                { 2 * (x * y + z * w), 1 - 2 * (x * x + z * z), 2 * (y * z - x * w) },
                { 2 * (x * z - y * w), 2 * (y * z + x * w), 1 - 2 * (x * x + y * y) },
            };
            Mat local;
            const float piv[3] = { b.pivot.x, b.pivot.y, b.pivot.z };
            for (int i = 0; i < 3; i++) {
                float turned = 0;
                for (int j = 0; j < 3; j++) {
                    local.m[i][j] = R[i][j] * p[3 + j];
                    turned += local.m[i][j] * piv[j];
                }
                local.m[i][3] = piv[i] + p[6 + i] - turned;
            }
            const bool has_parent = b.parent >= 0 && b.parent < (int)mats.size();
            mats.push_back(has_parent ? mats[b.parent] * local : local);
        }
        return mats;
    }

    // --- Model ---------------------------------------------------------------------------------------

    std::array<uint8_t, 4> rgba16(uint16_t c) {
        return { uint8_t((c >> 11 & 31) * 255 / 31), uint8_t((c >> 6 & 31) * 255 / 31), uint8_t((c >> 1 & 31) * 255 / 31), uint8_t((c & 1) * 255) };
    }

    bool parse_model(std::vector<uint8_t> bytes, Model& m) {
        m.bytes = std::move(bytes);
        Bytes r{m.bytes};
        if (r.u32(0) != 0x0B) {
            return false;
        }
        m.dl = r.u32(0xC);
        const uint32_t vtx = r.u32(0x10);
        const uint32_t bones = r.u32(0x18);
        m.seg2 = 0x58 + r.u16(0x54) * 8;
        const int nbones = r.u16(bones + 4);
        for (int i = 0; i < nbones; i++) {
            const uint32_t o = bones + 8 + i * 16;
            m.bones.push_back({ { r.f32(o), r.f32(o + 4), r.f32(o + 8) }, r.s16(o + 12), r.s16(o + 14) });
        }
        const int nverts = r.u16(vtx + 0x16) / 2;
        for (int i = 0; i < nverts; i++) {
            const uint32_t o = vtx + 0x18 + i * 16;
            if (!r.has(o, 16)) {
                return false;
            }
            Vertex v{ { (float)r.s16(o), (float)r.s16(o + 2), (float)r.s16(o + 4) }, r.s16(o + 8), r.s16(o + 10), {} };
            std::memcpy(v.rgba, &m.bytes[o + 12], 4);
            m.verts.push_back(v);
        }
        return !m.bones.empty() && !m.verts.empty() && r.has(m.dl + 8, r.u32(m.dl) * 8);
    }

    // Reads the display list once for its texture: the palette loaded with G_LOADTLUT and the CI texels with
    // G_LOADBLOCK, sized by tile 0's G_SETTILESIZE. Formats other than CI4, CI8 and RGBA16 draw white.
    void decode_texture(Model& m) {
        Bytes r{m.bytes};
        uint32_t image = 0, palette = 0, texels = 0;
        int fmt = 0, siz = 0, w = 0, h = 0;
        const uint32_t count = r.u32(m.dl);
        for (uint32_t i = 0; i < count; i++) {
            const uint32_t w0 = r.u32(m.dl + 8 + i * 8), w1 = r.u32(m.dl + 12 + i * 8);
            switch (w0 >> 24) {
                case 0xFD: image = w1 & 0xFFFFFF; break;
                case 0xF0: palette = image; break;
                case 0xF3: texels = image; break;
                case 0xF5:
                    if (((w1 >> 24) & 7) == 0) {
                        fmt = (w0 >> 21) & 7;
                        siz = (w0 >> 19) & 3;
                    }
                    break;
                case 0xF2:
                    if (((w1 >> 24) & 7) == 0) {
                        w = (int)(((w1 >> 12) & 0xFFF) >> 2) + 1;
                        h = (int)((w1 & 0xFFF) >> 2) + 1;
                    }
                    break;
            }
        }
        if (w <= 0 || h <= 0 || w > 256 || h > 256) {
            return;
        }
        m.tex.w = w;
        m.tex.h = h;
        m.tex.texels.assign(w * h, { 255, 255, 255, 255 });
        const uint32_t pal = m.seg2 + palette, tx = m.seg2 + texels;
        for (int i = 0; i < w * h; i++) {
            if (fmt == 2 && siz == 0) {  // CI4
                const uint8_t b = m.bytes.size() > tx + i / 2 ? m.bytes[tx + i / 2] : 0;
                m.tex.texels[i] = rgba16(r.u16(pal + 2 * ((i & 1) ? (b & 15) : (b >> 4))));
            } else if (fmt == 2 && siz == 1) {  // CI8
                const uint8_t b = m.bytes.size() > tx + i ? m.bytes[tx + i] : 0;
                m.tex.texels[i] = rgba16(r.u16(pal + 2 * b));
            } else if (fmt == 0 && siz == 2) {  // RGBA16
                m.tex.texels[i] = rgba16(r.u16(tx + 2 * i));
            }
        }
    }

    // Walks the display list with the bones' matrices: the posed triangles.
    std::vector<Tri> skin(const Model& m, const std::vector<Mat>& mats) {
        Bytes r{m.bytes};
        std::vector<Tri> tris;
        std::vector<Mat> stack;
        Mat cur;
        std::array<Corner, 64> slots{};
        bool textured = true;
        bool translucent = false;
        const uint32_t count = r.u32(m.dl);
        for (uint32_t i = 0; i < count; i++) {
            const uint32_t w0 = r.u32(m.dl + 8 + i * 8), w1 = r.u32(m.dl + 12 + i * 8);
            switch (w0 >> 24) {
                case 0xDA: {  // G_MTX: the stored flags are G_MTX_PUSH flipped
                    if (((w0 & 0xFF) ^ 1) & 1) {
                        stack.push_back(cur);
                    }
                    const uint32_t k = (w1 & 0xFFFFFF) / 0x40;
                    if ((w1 >> 24) == 5 && k < mats.size()) {
                        cur = mats[k];
                    }
                    break;
                }
                case 0xD8:  // G_POPMTX
                    for (uint32_t n = 0; n < w1 / 0x40 && !stack.empty(); n++) {
                        cur = stack.back();
                        stack.pop_back();
                    }
                    break;
                case 0xFC:  // G_SETCOMBINE: textured when the first cycle starts from TEXEL0
                    textured = ((w0 >> 20) & 0xF) == 1;
                    break;
                case 0xDE:  // G_DL into segment 3, the game's render modes: +0 opaque, +0x20 blended (the sleeve's end)
                    if ((w1 >> 24) == 3) {
                        translucent = (w1 & 0xFFFFFF) != 0;
                    }
                    break;
                case 0x01: {  // G_VTX
                    const uint32_t n = (w0 >> 12) & 0xFF, end = (w0 & 0xFF) >> 1, base = (w1 & 0xFFFFFF) / 16;
                    for (uint32_t v = 0; v < n; v++) {
                        const uint32_t slot = end - n + v;
                        if (slot >= slots.size() || base + v >= m.verts.size()) {
                            continue;
                        }
                        const Vertex& src = m.verts[base + v];
                        slots[slot] = { cur.apply(src.pos), (float)src.s, (float)src.t,
                                        { src.rgba[0] / 255.0f, src.rgba[1] / 255.0f, src.rgba[2] / 255.0f, src.rgba[3] / 255.0f } };
                    }
                    break;
                }
                case 0x05:
                case 0x06: {  // G_TRI1, G_TRI2
                    const uint32_t words[2] = { w0, w1 };
                    for (int t = 0; t < ((w0 >> 24) == 6 ? 2 : 1); t++) {
                        Tri tri{};
                        tri.textured = textured;
                        tri.translucent = translucent;
                        for (int c = 0; c < 3; c++) {
                            tri.c[c] = slots[((words[t] >> (16 - 8 * c)) & 0xFF) / 2 % slots.size()];
                        }
                        tris.push_back(tri);
                    }
                    break;
                }
            }
        }
        return tris;
    }

    // --- Drawing -------------------------------------------------------------------------------------

    // The view: the back of the hand towards the viewer, as on the save select (the fingers curl away), fingers
    // up and leaning left like an arrow cursor.
    Vec3 view(const Vec3& p) {
        constexpr float lean = 25.0f * 3.14159265f / 180.0f;
        // Model +y (the back of the hand) towards the viewer, model -z (the fingers) up the screen.
        const float sx = p.x, y = -p.z, z = p.y;
        // Seen from above the fingertips (tipped 20 degrees; L wanted it flatter than 50), so the nails stay in sight while the fingers curl.
        constexpr float tip = -20.0f * 3.14159265f / 180.0f;
        const float sy = y * std::cos(tip) + z * std::sin(tip), sz = z * std::cos(tip) - y * std::sin(tip);
        return { sx * std::cos(lean) - sy * std::sin(lean), sx * std::sin(lean) + sy * std::cos(lean), sz };
    }

    struct Framing {
        float min_x, max_y, scale;
    };

    void draw(const Model& m, const std::vector<Tri>& tris, const Framing& fr, int size, std::vector<uint8_t>& out) {
        const int n = size * supersample;
        std::vector<float> color(n * n * 4, 0.0f);
        std::vector<float> depth(n * n, -1e30f);
        const float s_scale = m.tex.w > 0 ? 1.0f / 64.0f : 0.0f;  // S10.5 coordinates at a G_TEXTURE scale of 0.5
        // Opaque triangles write depth; blended ones (drawn after, far to near) test it and mix by their alpha.
        auto raster = [&](const Tri& t) {
            float x[3], y[3], z[3];
            for (int c = 0; c < 3; c++) {
                const Vec3 v = view(t.c[c].pos);
                x[c] = (v.x - fr.min_x) * fr.scale * supersample;
                y[c] = (fr.max_y - v.y) * fr.scale * supersample;
                z[c] = v.z;
            }
            const float den = (y[1] - y[2]) * (x[0] - x[2]) + (x[2] - x[1]) * (y[0] - y[2]);
            if (std::fabs(den) < 1e-6f) {
                return;
            }
            const int x0 = std::max(0, (int)std::floor(std::min({ x[0], x[1], x[2] })));
            const int x1 = std::min(n - 1, (int)std::ceil(std::max({ x[0], x[1], x[2] })));
            const int y0 = std::max(0, (int)std::floor(std::min({ y[0], y[1], y[2] })));
            const int y1 = std::min(n - 1, (int)std::ceil(std::max({ y[0], y[1], y[2] })));
            for (int py = y0; py <= y1; py++) {
                for (int px = x0; px <= x1; px++) {
                    const float cx = px + 0.5f, cy = py + 0.5f;
                    const float l0 = ((y[1] - y[2]) * (cx - x[2]) + (x[2] - x[1]) * (cy - y[2])) / den;
                    const float l1 = ((y[2] - y[0]) * (cx - x[2]) + (x[0] - x[2]) * (cy - y[2])) / den;
                    const float l2 = 1.0f - l0 - l1;
                    if (l0 < 0 || l1 < 0 || l2 < 0) {
                        continue;
                    }
                    float pz = l0 * z[0] + l1 * z[1] + l2 * z[2];
                    float rgba[4];
                    for (int k = 0; k < 4; k++) {
                        rgba[k] = l0 * t.c[0].rgba[k] + l1 * t.c[1].rgba[k] + l2 * t.c[2].rgba[k];
                    }
                    if (t.textured && m.tex.w > 0) {
                        const float s = (l0 * t.c[0].s + l1 * t.c[1].s + l2 * t.c[2].s) * s_scale;
                        const float tt = (l0 * t.c[0].t + l1 * t.c[1].t + l2 * t.c[2].t) * s_scale;
                        const int tx = std::clamp((int)std::floor(s), 0, m.tex.w - 1);
                        const int ty = std::clamp((int)std::floor(tt), 0, m.tex.h - 1);
                        const auto& texel = m.tex.texels[ty * m.tex.w + tx];
                        for (int k = 0; k < 4; k++) {
                            rgba[k] *= texel[k] / 255.0f;
                        }
                        // The nail (the texture's dark stripe) is brought a little forward so it shows over its own
                        // fingertip when the finger curls away.
                        if (texel[0] + texel[1] + texel[2] < 3 * 128) {
                            pz += 30.0f;
                        }
                    }
                    float& d = depth[py * n + px];
                    if (pz <= d) {
                        continue;
                    }
                    // Kept premultiplied by alpha.
                    float* c = &color[(py * n + px) * 4];
                    if (t.translucent) {
                        const float a = std::clamp(rgba[3], 0.0f, 1.0f);
                        for (int k = 0; k < 3; k++) {
                            c[k] = rgba[k] * a + c[k] * (1.0f - a);
                        }
                        c[3] = a + c[3] * (1.0f - a);
                    } else {
                        d = pz;
                        c[0] = rgba[0];
                        c[1] = rgba[1];
                        c[2] = rgba[2];
                        c[3] = 1.0f;
                    }
                }
            }
        };
        std::vector<const Tri*> blended;
        for (const Tri& t : tris) {
            if (t.translucent) {
                blended.push_back(&t);
            } else {
                raster(t);
            }
        }
        auto depth_of = [](const Tri* t) { return view(t->c[0].pos).z + view(t->c[1].pos).z + view(t->c[2].pos).z; };
        std::sort(blended.begin(), blended.end(), [&](const Tri* a, const Tri* b) { return depth_of(a) < depth_of(b); });
        for (const Tri* t : blended) {
            raster(*t);
        }
        out.assign(size * size * 4, 0);
        const float area = (float)(supersample * supersample);
        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++) {
                float sum[4] = { 0, 0, 0, 0 };
                for (int sy = 0; sy < supersample; sy++) {
                    for (int sx = 0; sx < supersample; sx++) {
                        const float* c = &color[((y * supersample + sy) * n + x * supersample + sx) * 4];
                        for (int k = 0; k < 4; k++) {
                            sum[k] += c[k];
                        }
                    }
                }
                uint8_t* o = &out[(y * size + x) * 4];
                const float a = sum[3] / area;
                for (int k = 0; k < 3; k++) {
                    o[k] = (uint8_t)std::lround(std::clamp(a > 0 ? sum[k] / sum[3] : 0.0f, 0.0f, 1.0f) * 255.0f);
                }
                o[3] = (uint8_t)std::lround(a * 255.0f);
            }
        }
    }
}

bool tooie::hand_cursor::make_model_frames(int size, ModelFrames& frames) {
    // Before the game starts (the start menu) the ROM isn't loaded yet: the stored copy is read instead.
    std::vector<uint8_t> stored;
    std::span<const uint8_t> rom = recomp::get_rom();
    if (rom.empty()) {
        std::ifstream in(recomp::get_config_path() / stored_rom_name, std::ios::binary);
        stored.assign(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>());
        rom = stored;
    }
    Model model;
    Anim idle, click;
    if (!parse_model(tooie::asset_mods::rom_asset_bytes(rom, model_asset), model) ||
        !parse_anim(tooie::asset_mods::rom_asset_bytes(rom, idle_asset), idle) ||
        !parse_anim(tooie::asset_mods::rom_asset_bytes(rom, click_asset), click)) {
        return false;
    }
    decode_texture(model);
    // The nail is a black stripe three texels wide on the fingertip caps, well under a pixel at cursor size,
    // so it is widened (each texel takes the darkest of its row within one texel) to stay in sight.
    if (model.tex.w > 0) {
        const auto src = model.tex.texels;
        for (int y = 0; y < model.tex.h; y++) {
            for (int x = 0; x < model.tex.w; x++) {
                auto& out = model.tex.texels[y * model.tex.w + x];
                for (int dx = -1; dx <= 1; dx++) {
                    const auto& in = src[y * model.tex.w + std::clamp(x + dx, 0, model.tex.w - 1)];
                    if (in[0] + in[1] + in[2] < out[0] + out[1] + out[2]) {
                        out = in;
                    }
                }
            }
        }
    }

    // One frame per animation frame: the idle loops over its whole length, the click plays once.
    std::vector<std::vector<Tri>> idle_tris, click_tris;
    for (int f = idle.start; f < idle.end; f++) {
        idle_tris.push_back(skin(model, pose(model, idle, (float)f, true)));
    }
    for (int f = click.start; f <= click.end; f++) {
        click_tris.push_back(skin(model, pose(model, click, (float)f, false)));
    }
    if (idle_tris.empty() || click_tris.empty()) {
        return false;
    }

    // One framing for every frame, so the hand moves within the cursor as it does in the game. The idle's
    // bounds set the scale (the idle hand fills the asked size); the picture grows to take in the click too,
    // so the click is never cut at the edge.
    struct Bounds {
        float min_x = 1e30f, max_x = -1e30f, min_y = 1e30f, max_y = -1e30f;
        void add(const std::vector<std::vector<Tri>>& frames_tris) {
            for (const auto& tris : frames_tris) {
                for (const Tri& t : tris) {
                    for (const Corner& c : t.c) {
                        const Vec3 v = view(c.pos);
                        min_x = std::min(min_x, v.x);
                        max_x = std::max(max_x, v.x);
                        min_y = std::min(min_y, v.y);
                        max_y = std::max(max_y, v.y);
                    }
                }
            }
        }
    };
    Bounds idle_bounds, all;
    idle_bounds.add(idle_tris);
    all.add(idle_tris);
    all.add(click_tris);
    const float span = std::max(idle_bounds.max_x - idle_bounds.min_x, idle_bounds.max_y - idle_bounds.min_y);
    if (span <= 0) {
        return false;
    }
    const float scale = (float)(size - 1) / span;
    const float all_span = std::max(all.max_x - all.min_x, all.max_y - all.min_y);
    size = std::min((int)std::ceil(all_span * scale) + 1, size * 2);
    const Framing fr{ all.min_x, all.max_y, scale };

    // The hot spot: the middle of the hand in the idle's first frame (L: the click lands where the hand is,
    // not at a fingertip), 70% of the way from the palm bone's pivot (the wrist) to the mean of its
    // children's pivots (the knuckles).
    {
        const std::vector<Mat> mats = pose(model, idle, (float)idle.start, true);
        Vec3 centre{ 0, 0, 0 };
        if (model.bones.size() > 1) {
            const Vec3 wrist = mats[1].apply(model.bones[1].pivot);
            Vec3 knuckles{ 0, 0, 0 };
            int count = 0;
            for (size_t i = 2; i < model.bones.size(); i++) {
                if (model.bones[i].parent == 1) {
                    const Vec3 k = mats[i].apply(model.bones[i].pivot);
                    knuckles = { knuckles.x + k.x, knuckles.y + k.y, knuckles.z + k.z };
                    count++;
                }
            }
            if (count > 0) {
                constexpr float to_knuckles = 0.7f;
                centre = { wrist.x + (knuckles.x / count - wrist.x) * to_knuckles, wrist.y + (knuckles.y / count - wrist.y) * to_knuckles,
                           wrist.z + (knuckles.z / count - wrist.z) * to_knuckles };
            } else {
                centre = wrist;
            }
        }
        const Vec3 v = view(centre);
        frames.hot_x = std::clamp((int)std::lround((v.x - fr.min_x) * fr.scale), 0, size - 1);
        frames.hot_y = std::clamp((int)std::lround((fr.max_y - v.y) * fr.scale), 0, size - 1);
    }

    frames.size = size;
    frames.idle.clear();
    frames.click.clear();
    for (const auto& tris : idle_tris) {
        frames.idle.emplace_back();
        draw(model, tris, fr, size, frames.idle.back());
    }
    for (const auto& tris : click_tris) {
        frames.click.emplace_back();
        draw(model, tris, fr, size, frames.click.back());
    }
    frames.idle_fps = (float)(idle.end - idle.start) / idle_seconds;
    frames.click_fps = click_frames_per_second;
    return true;
}
