// Graphics > Demake > Simple Circle Shadow.
//
// The game draws the player's shadow (func_800A6250) by flattening the form's shadow model onto the
// floor into an 8-bit buffer, then pasting the buffer over the picture at half strength: a pixel of
// the buffer is how much light reaches the floor, 255 for none blocked, lower where the model is.
// With the option on, the model the game is asked for (func_800D674C, at the id func_80084F40 gave) is
// swapped for a disc built here and loaded in its place through the asset loader (asset_mods.cpp). The
// disc is flat, centred on the player's feet and dark in the middle, fading to nothing at the edge
// through its vertex shading. Everything else (flattening onto the floor's slope, the decal test
// against the floor, the paste) stays the game's own, so the disc sits on slopes and steps like the
// original shadow.
//
// The model is laid out like the shadow models (a type 0x0B model: header, texture list, display
// list, vertices, geometry list), but static: one draw node, no bones.

#include <algorithm>
#include <cmath>
#include <cstring>
#include <variant>

#include "recomp.h"
#include "recompui/config.h"
#include "tooie_circle_shadow.h"
#include "tooie_hooks.h"

namespace {
    // The disc, in model units: Banjo's own shadow model spans 148 by 108.
    constexpr int sides = 16;
    constexpr float radius = 62.0f;
    // The vertex rings: the middle, then two rings at these fractions of the radius. The shade of each
    // (0 is the darkest shadow, 255 none) sets how the shadow fades towards the edge.
    constexpr float ring_inner = 0.55f;
    constexpr uint8_t shade_middle = 0;
    constexpr uint8_t shade_inner = 70;
    constexpr uint8_t shade_edge = 255;

    void put16(std::vector<uint8_t>& out, uint32_t v) {
        out.push_back(uint8_t(v >> 8));
        out.push_back(uint8_t(v));
    }
    void put32(std::vector<uint8_t>& out, uint32_t v) {
        put16(out, v >> 16);
        put16(out, v & 0xFFFF);
    }
    void set16(std::vector<uint8_t>& out, size_t at, uint32_t v) {
        out[at] = uint8_t(v >> 8);
        out[at + 1] = uint8_t(v);
    }
    void set32(std::vector<uint8_t>& out, size_t at, uint32_t v) {
        set16(out, at, v >> 16);
        set16(out, at + 2, v & 0xFFFF);
    }
    void pad(std::vector<uint8_t>& out, size_t to) {
        while (out.size() % to != 0) {
            out.push_back(0);
        }
    }

    // G_SETCOMBINE with the same colour and alpha in both cycles, so it does not matter which one the
    // render mode uses: colour = shade, alpha = shade alpha.
    std::pair<uint32_t, uint32_t> combine_shade() {
        constexpr uint32_t zero_a = 15, zero_b = 15, zero_c = 31, shade_d = 4;   // colour (A-B)*C+D
        constexpr uint32_t alpha_zero = 7, alpha_shade = 4;                         // alpha
        const uint32_t w0 = 0xFC000000 | (zero_a << 20) | (zero_c << 15) | (alpha_zero << 12) | (alpha_zero << 9)
                          | (zero_a << 5) | zero_c;
        const uint32_t w1 = (zero_b << 28) | (zero_b << 24) | (alpha_zero << 21) | (alpha_zero << 18) | (shade_d << 15)
                          | (alpha_zero << 12) | (alpha_shade << 9) | (shade_d << 6) | (alpha_zero << 3) | alpha_shade;
        return { w0, w1 };
    }

    std::vector<uint8_t> build() {
        // Vertices: the middle (0), the inner ring (1 to 16), the outer ring (17 to 32).
        struct Vertex { int16_t x, z; uint8_t shade; };
        std::vector<Vertex> verts;
        verts.push_back({ 0, 0, shade_middle });
        for (int ring = 0; ring < 2; ring++) {
            const float r = radius * (ring == 0 ? ring_inner : 1.0f);
            for (int i = 0; i < sides; i++) {
                const float a = float(i) * 2.0f * 3.14159265f / float(sides);
                verts.push_back({ int16_t(std::lround(r * std::cos(a))), int16_t(std::lround(r * std::sin(a))),
                                  ring == 0 ? shade_inner : shade_edge });
            }
        }
        const uint32_t total_v = uint32_t(verts.size());

        auto tri = [](uint32_t a, uint32_t b, uint32_t c) { return (a * 2 << 16) | (b * 2 << 8) | (c * 2); };
        std::vector<std::pair<uint32_t, uint32_t>> cmds;
        cmds.push_back({ 0xD9C0FFFB, 0x00000000 });   // as the shadow models: shade, no lighting, no fog
        cmds.push_back({ 0xD9FFFFFF, 0x00200004 });
        cmds.push_back({ 0xD7000000, 0x80008000 });   // no texture
        cmds.push_back({ 0xE7000000, 0x00000000 });
        const auto [c0, c1] = combine_shade();
        cmds.push_back({ c0, c1 });
        cmds.push_back({ 0xDE000000, 0x03000000 });   // the render mode list the game builds for the shadow (segment 3)
        uint32_t ntri = 0;
        // The middle and the inner ring (17 vertices), as a fan. Every triangle is given both ways round,
        // so culling can't hide the disc whichever way the flattened model faces.
        cmds.push_back({ 0x01000000 | ((1 + sides) << 12) | ((1 + sides) * 2), 0x01000000 });
        for (int i = 0; i < sides; i++) {
            const uint32_t a = 1 + i, b = 1 + (i + 1) % sides;
            cmds.push_back({ 0x06000000 | tri(0, a, b), tri(0, b, a) });
            ntri += 2;
        }
        // The two rings (32 vertices), as a band.
        cmds.push_back({ 0x01000000 | ((2 * sides) << 12) | ((2 * sides) * 2), 0x01000000 + 1 * 16 });
        for (int i = 0; i < sides; i++) {
            const uint32_t j = (i + 1) % sides;
            const uint32_t in_i = i, in_j = j, out_i = sides + i, out_j = sides + j;
            cmds.push_back({ 0x06000000 | tri(in_i, out_i, out_j), tri(out_j, in_j, in_i) });
            cmds.push_back({ 0x06000000 | tri(in_i, out_j, out_i), tri(out_j, in_i, in_j) });
            ntri += 4;
        }
        cmds.push_back({ 0xDF000000, 0x00000000 });

        // Header (0x50 bytes), then an empty texture list.
        std::vector<uint8_t> out(0x50, 0);
        set32(out, 0x00, 0x0B);
        set16(out, 0x08, 0x50);
        set16(out, 0x44, ntri);
        set16(out, 0x46, total_v);
        set32(out, 0x48, 0x41200000);   // 10.0, as the shadow models
        put32(out, 0);
        put16(out, 0);
        put16(out, 0);

        // Display list: two empty commands first and the draw below them, as the shadow models.
        const uint32_t dl_off = uint32_t(out.size());
        put32(out, uint32_t(cmds.size() + 2));
        put32(out, 0);
        put32(out, 0xDF000000); put32(out, 0);
        put32(out, 0xDF000000); put32(out, 0);
        for (const auto& [w0, w1] : cmds) {
            put32(out, w0);
            put32(out, w1);
        }
        pad(out, 8);

        // Vertices under their header: bounds, middle, the two radii, then twice the count.
        const uint32_t vtx_off = uint32_t(out.size());
        const int r = int(std::ceil(radius));
        for (int v : { -r, 0, -r, r, 0, r, 0, 0, 0 }) {
            put16(out, uint16_t(int16_t(v)));
        }
        put16(out, uint16_t(r));
        put16(out, uint16_t(r));
        put16(out, uint16_t(total_v * 2));
        for (const Vertex& v : verts) {
            put16(out, uint16_t(v.x)); put16(out, 0); put16(out, uint16_t(v.z)); put16(out, 0);
            put16(out, 0); put16(out, 0);
            out.push_back(v.shade); out.push_back(v.shade); out.push_back(v.shade); out.push_back(255);
        }
        pad(out, 16);

        // Geometry list: one draw node over the commands after the two empty ones.
        const uint32_t geo_off = uint32_t(out.size());
        put32(out, 3);
        put32(out, 0);
        put16(out, 2);
        put16(out, uint16_t(cmds.size()));
        put32(out, 0);
        pad(out, 16);

        set32(out, 0x04, geo_off);
        set32(out, 0x0C, dl_off);
        set32(out, 0x10, vtx_off);
        return out;
    }
}

bool tooie::circle_shadow::enabled() {
    try {
        return std::get<bool>(recompui::config::get_config(recompui::config::graphics::id).get_option_value(option));
    } catch (...) {
        return false;
    }
}

std::vector<uint8_t> tooie::circle_shadow::model_for(uint32_t id) {
    if (id != model_id) {
        return {};
    }
    static const std::vector<uint8_t> disc = build();
    return disc;
}

// Hooked in func_800A6250 after func_80084F40 has given the form's shadow model id ($v0), before the model
// is fetched with it: the disc's id goes in its place.
extern "C" void tooie_circle_shadow_id(uint8_t* /*rdram*/, recomp_context* ctx) {
    if (tooie::circle_shadow::enabled()) {
        ctx->r2 = tooie::circle_shadow::model_id;
    }
}
