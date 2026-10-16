// Back-Port: Original honeycomb.
//
// Tooie's assets still hold Banjo-Kazooie's health honeycomb (asset 0x0614: 62 vertices, 48
// triangles, the BK mesh with its honey and shine textures), unused. Loaded in place of Tooie's comb
// (asset 0x0704) as it is, the game crashes: the BK model has a BK-style geometry list and no bones,
// while the comb's code reads bone 1 (its middle, which the glitter back-port also uses). So when
// General > Back-Port: Original honeycomb is on, the asset loader (asset_mods.cpp) builds a model
// with Tooie's comb's header, bones and geometry list and BK's display list, textures and
// vertices, and loads that for 0x0704:
// - the vertices are scaled 2.4 times, so the comb is as big as Tooie's (66 -> 160 units wide);
// - BK's comb lights its frame with texture generation (the shine), and BK keeps those vertices'
//   normals in their colours; Tooie reads normals from the model's normals block and colours as
//   colours, so from the second vertex load on the colours move to the normals block and become
//   white. The honey faces (first load, unlit) get normals worked out from the triangles;
// - the geometry list is bone 0 > bone 1 > one draw node for the whole display list, plus Tooie's
//   four sparkle points (0x0A nodes) as they are.
// A model mod that replaces 0x0704 wins over this. Switching it in a level reloads the area.

#include <algorithm>
#include <cmath>
#include <cstring>

#include "recompui/config.h"
#include "tooie_original_honeycomb.h"

namespace {
    constexpr float scale = 2.4f;

    uint32_t rd32(const std::vector<uint8_t>& b, size_t o) {
        return o + 4 <= b.size() ? (uint32_t(b[o]) << 24) | (uint32_t(b[o + 1]) << 16) | (uint32_t(b[o + 2]) << 8) | b[o + 3] : 0;
    }
    uint16_t rd16(const std::vector<uint8_t>& b, size_t o) {
        return o + 2 <= b.size() ? uint16_t((b[o] << 8) | b[o + 1]) : 0;
    }
    void put32(std::vector<uint8_t>& b, size_t o, uint32_t v) {
        b[o] = uint8_t(v >> 24); b[o + 1] = uint8_t(v >> 16); b[o + 2] = uint8_t(v >> 8); b[o + 3] = uint8_t(v);
    }
    void put16(std::vector<uint8_t>& b, size_t o, uint16_t v) {
        b[o] = uint8_t(v >> 8); b[o + 1] = uint8_t(v);
    }
    void push32(std::vector<uint8_t>& b, uint32_t v) {
        b.resize(b.size() + 4); put32(b, b.size() - 4, v);
    }
    void push16(std::vector<uint8_t>& b, uint16_t v) {
        b.resize(b.size() + 2); put16(b, b.size() - 2, v);
    }
    void pad(std::vector<uint8_t>& b, size_t a) {
        b.resize((b.size() + a - 1) / a * a, 0);
    }
    void append(std::vector<uint8_t>& out, const std::vector<uint8_t>& b, size_t from, size_t len) {
        out.insert(out.end(), b.begin() + from, b.begin() + from + len);
    }
}

bool tooie::original_honeycomb::enabled() {
    try {
        return std::get<bool>(recompui::config::get_general_config().get_option_value(option));
    } catch (...) {
        return false;
    }
}

std::vector<uint8_t> tooie::original_honeycomb::build(const std::vector<uint8_t>& bk, const std::vector<uint8_t>& tz) {
    if (bk.size() < 0x50 || tz.size() < 0x50 || rd32(bk, 0) != 0x0B || rd32(tz, 0) != 0x0B) {
        return {};
    }
    // BK's comb: texture block at 0x50, display list, vertices (a 0x18 header, then 16 bytes each).
    const uint32_t tex_size = rd32(bk, 0x50);
    const uint32_t dl_at = rd32(bk, 0xC), vtx_at = rd32(bk, 0x10);
    const uint32_t ncmd = rd32(bk, dl_at);
    const uint32_t nv = rd16(bk, vtx_at + 0x16) / 2;
    if (0x50 + tex_size > bk.size() || dl_at + 8 + 8 * ncmd > bk.size() || vtx_at + 0x18 + 16 * nv > bk.size() || nv == 0) {
        return {};
    }
    struct Vtx { int16_t p[3]; uint8_t rest[10]; float n[3]; };
    std::vector<Vtx> v(nv);
    for (uint32_t i = 0; i < nv; i++) {
        const size_t o = vtx_at + 0x18 + 16 * i;
        for (int k = 0; k < 3; k++) {
            v[i].p[k] = (int16_t)std::lround((int16_t)rd16(bk, o + 2 * k) * scale);
            v[i].n[k] = 0.0f;
        }
        std::memcpy(v[i].rest, &bk[o + 6], 10);   // flag, s, t, colour
    }
    // Normals from the triangles (area weighted); the frame's from its colours (see the top).
    uint32_t slots[64] = {};
    int loads = 0;
    uint32_t lit_from = nv;
    uint32_t ntris = 0;
    auto tri = [&](uint32_t word) {
        uint32_t t[3];
        for (int k = 0; k < 3; k++) {
            t[k] = slots[((word >> (16 - 8 * k)) & 0xFF) / 2 & 63];
            if (t[k] >= nv) {
                return;
            }
        }
        float a[3], b[3];
        for (int k = 0; k < 3; k++) {
            a[k] = float(v[t[1]].p[k] - v[t[0]].p[k]);
            b[k] = float(v[t[2]].p[k] - v[t[0]].p[k]);
        }
        const float f[3] = { a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0] };
        for (uint32_t i : t) {
            for (int k = 0; k < 3; k++) v[i].n[k] += f[k];
        }
        ntris++;
    };
    for (uint32_t c = 0; c < ncmd; c++) {
        const uint32_t w0 = rd32(bk, dl_at + 8 + 8 * c), w1 = rd32(bk, dl_at + 12 + 8 * c);
        const uint32_t op = w0 >> 24;
        if (op == 0x01) {
            const uint32_t n = (w0 >> 12) & 0xFF, end = (w0 & 0xFF) >> 1, base = (w1 & 0xFFFFFF) / 16;
            if (++loads == 2) {
                lit_from = base;
            }
            for (uint32_t k = 0; k < n; k++) slots[(end - n + k) & 63] = base + k;
        } else if (op == 0x05) {
            tri(w0);
        } else if (op == 0x06) {
            tri(w0);
            tri(w1);
        }
    }
    for (uint32_t i = 0; i < nv; i++) {
        uint8_t* rgba = v[i].rest + 6;
        if (i >= lit_from) {
            for (int k = 0; k < 3; k++) {
                v[i].n[k] = (int8_t)rgba[k];
                rgba[k] = 255;
            }
        }
        const float len = std::sqrt(v[i].n[0] * v[i].n[0] + v[i].n[1] * v[i].n[1] + v[i].n[2] * v[i].n[2]);
        for (int k = 0; k < 3; k++) v[i].n[k] = len > 0 ? v[i].n[k] / len : 0.0f;
    }

    // Tooie's comb: bones, and the sparkle points under bone 1.
    const uint32_t bones_at = rd32(tz, 0x18);
    const uint32_t bones_len = 8 + 16 * rd16(tz, bones_at + 4);
    if (bones_at == 0 || bones_at + bones_len > tz.size()) {
        return {};
    }
    std::vector<std::vector<uint8_t>> kids;
    {
        std::vector<uint8_t> draw;
        push32(draw, 0x11); push32(draw, 0); push16(draw, 0); push16(draw, 0); push16(draw, uint16_t(nv)); push16(draw, 0);
        kids.push_back(draw);
        const uint32_t geo = rd32(tz, 4);
        const uint32_t bone1 = geo + tz[geo + 8];          // bone 0's child
        if (rd32(tz, geo) == 2 && rd32(tz, bone1) == 2) {
            uint32_t o = bone1 + tz[bone1 + 8];
            for (int guard = 0; guard < 64 && o + 8 <= tz.size(); guard++) {
                const uint32_t cmd = rd32(tz, o), size = rd32(tz, o + 4);
                if (cmd == 0x0A && o + 0x18 <= tz.size()) {
                    kids.emplace_back(tz.begin() + o, tz.begin() + o + 0x18);
                }
                if (size == 0) break;
                o += size;
            }
        }
    }
    std::vector<uint8_t> geo;
    for (uint32_t id : { 0u, 1u }) {      // bone 0 (id 3) > bone 1 (id 1)
        push32(geo, 2); push32(geo, 0);
        geo.push_back(0x10); geo.push_back(uint8_t(id)); push16(geo, id == 0 ? 3 : 1); push32(geo, 0);
    }
    for (size_t i = 0; i < kids.size(); i++) {
        put32(kids[i], 4, i + 1 < kids.size() ? uint32_t(kids[i].size()) : 0);
        geo.insert(geo.end(), kids[i].begin(), kids[i].end());
    }

    std::vector<uint8_t> out(tz.begin(), tz.begin() + 0x50);
    const uint32_t tex_off = (uint32_t)out.size(); append(out, bk, 0x50, tex_size); pad(out, 8);
    const uint32_t dl_off = (uint32_t)out.size(); append(out, bk, dl_at, 8 + 8 * ncmd); pad(out, 8);
    const uint32_t bones_off = (uint32_t)out.size(); append(out, tz, bones_at, bones_len); pad(out, 8);
    const uint32_t vtx_off = (uint32_t)out.size();
    int lo[3] = { 32767, 32767, 32767 }, hi[3] = { -32768, -32768, -32768 };
    for (const Vtx& x : v) {
        for (int k = 0; k < 3; k++) { lo[k] = std::min<int>(lo[k], x.p[k]); hi[k] = std::max<int>(hi[k], x.p[k]); }
    }
    int ctr[3];
    for (int k = 0; k < 3; k++) ctr[k] = (lo[k] + hi[k]) / 2;
    float local = 0, glob = 0;
    for (const Vtx& x : v) {
        float dl = 0, dg = 0;
        for (int k = 0; k < 3; k++) { dl += float((x.p[k] - ctr[k]) * (x.p[k] - ctr[k])); dg += float(x.p[k] * x.p[k]); }
        local = std::max(local, std::sqrt(dl)); glob = std::max(glob, std::sqrt(dg));
    }
    for (int k = 0; k < 3; k++) push16(out, uint16_t(lo[k]));
    for (int k = 0; k < 3; k++) push16(out, uint16_t(hi[k]));
    for (int k = 0; k < 3; k++) push16(out, uint16_t(ctr[k]));
    push16(out, uint16_t(std::ceil(local))); push16(out, uint16_t(std::ceil(glob))); push16(out, uint16_t(nv * 2));
    for (const Vtx& x : v) {
        for (int k = 0; k < 3; k++) push16(out, uint16_t(x.p[k]));
        out.insert(out.end(), x.rest, x.rest + 10);
    }
    pad(out, 8);
    const uint32_t nrm_off = (uint32_t)out.size();
    for (const Vtx& x : v) {
        for (int k = 0; k < 3; k++) out.push_back(uint8_t((int8_t)std::lround(std::clamp(x.n[k] * 127.0f, -127.0f, 127.0f))));
        out.push_back(0);
    }
    pad(out, 8);
    const uint32_t geo_off = (uint32_t)out.size();
    out.insert(out.end(), geo.begin(), geo.end());
    pad(out, 16);
    put32(out, 4, geo_off);
    put16(out, 8, uint16_t(tex_off));
    put32(out, 0xC, dl_off);
    put32(out, 0x10, vtx_off);
    put32(out, 0x18, bones_off);
    put32(out, 0x38, nrm_off);
    put16(out, 0x44, uint16_t(ntris));
    put16(out, 0x46, uint16_t(nv));
    return out;
}
