// Graphics > Window Light Beams.
//
// Mumbo's Skull (every world's: maps B7, D9, EF, 134, 13E, 156, 171, 172, 176 share the models 0x1D01
// and 0x1D02) lights its two window eyes with beams the game draws in the room's see-through model
// 0x1D02: an eight-sided tube from each window down to the floor, white, faded from alpha 153 at the
// window to 0 at the floor, textured with the streaky light texture 0xF2 (64x64 IA8). Other rooms
// with bright windows have no beams. When the option is on, they get the same tubes:
// - Bottles' house (maps 0x143, 0x169, 0x191, 0x192; models 0x1DD0 and 0x1DD3): its two round
//   windows either side of the doorway to the stairs. Its see-through model 0x1DD3 (the lamps'
//   glows) is loaded with the beams added.
// - Banjo's house (map 0x173, model 0x1D08): its three hexagonal windows.
// - King Jingaling's throne room (maps 0x144, 0x199, model 0x1DD1): its two lit windows (the two on
//   the other wall are dim glass, no sun comes through them).
// The last two have no see-through model. The game finds a map's models in the map table of
// gcmapDll (14 bytes a map: map, solid model, see-through model, ...), with func_80800000_gcmapDll;
// a hook there (banjotooie.us.toml) gives these rooms a see-through model id that no map uses
// (0x1D49 and 0x1D97, level models left in the ROM), and the asset loader (asset_mods.cpp) loads a
// model holding only the beams in its place, while that room is the one being loaded.
// A model's texture list holds texture ids (asset 0x1EF6 + id), laid out one after the other in
// segment 2, so 0xF2 goes after any texture the model has. The beams are one draw with Mumbo's
// commands (texture, combiner, the see-through render mode call into segment 3) after the model's
// own, with a draw node for it after the last top-level node of the geometry list.
// The windows' places and the way each faces were read off the solid models (their glass and
// frames). Switching the option in one of these rooms reloads it.

#include <algorithm>
#include <array>
#include <atomic>
#include <cmath>
#include <mutex>

#include "recomp.h"
#include "recompui/config.h"
#include "tooie_window_beams.h"

namespace {
    struct Window {
        float x, y, z;              // the middle of the window, on the room side
        float nx, nz;               // the way it faces into the room (level)
        float half_w, half_h;       // the tube's size there, across and up
        float floor_y;              // the floor where its beam lands
    };
    struct Room {
        std::array<uint16_t, 4> maps;
        uint32_t model;             // its see-through model, or the stand-in id when it has none
        bool stand_in;
        std::vector<Window> windows;
    };
    const std::array<Room, 3> rooms = {{
        { { 0x143, 0x169, 0x191, 0x192 }, 0x1DD3, false, {
            { 529.0f, 443.0f, -2137.0f, -0.162f, 0.987f, 110.0f, 110.0f, 262.0f },   // right of the doorway (from inside)
            { -553.0f, 422.0f, -2155.0f, 0.215f, 0.977f, 110.0f, 110.0f, 282.0f },   // left of the doorway
        } },
        { { 0x173, 0x173, 0x173, 0x173 }, 0x1D49, true, {
            { 250.0f, 116.0f, 304.0f, 0.0f, -1.0f, 66.0f, 54.0f, 0.0f },             // either side of the door
            { -250.0f, 116.0f, 304.0f, 0.0f, -1.0f, 66.0f, 54.0f, 0.0f },
            { -456.0f, 116.0f, -131.0f, 1.0f, 0.0f, 66.0f, 54.0f, 0.0f },            // by the fireplace
        } },
        { { 0x144, 0x199, 0x199, 0x199 }, 0x1D97, true, {
            { 1496.0f, -100.0f, -2350.0f, -1.0f, 0.0f, 140.0f, 390.0f, -650.0f },
            { 1496.0f, -100.0f, -1650.0f, -1.0f, 0.0f, 140.0f, 390.0f, -650.0f },
        } },
    }};
    constexpr float drop_degrees = 35.0f;     // how steeply the light falls into the room
    constexpr int sides = 8;                  // as Mumbo's
    constexpr uint8_t top_alpha = 153;        // Mumbo's, at the window; 0 at the floor
    constexpr uint32_t light_texture = 0xF2;  // Mumbo's beams' streaks
    constexpr uint32_t ia8_type = 0x10, ia8_size = 64 * 64;

    std::atomic<uint16_t> looked_up_map{ 0 };

    bool has_map(const Room& room, uint16_t map) {
        return std::find(room.maps.begin(), room.maps.end(), map) != room.maps.end();
    }

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

    struct Vertex {
        int16_t x, y, z, s, t;
        uint8_t a;
    };

    // One window's tube: a ring of corners round the window, the same ring where the light meets
    // the floor, each with the first corner again at the end so the texture wraps round once.
    void add_tube(std::vector<Vertex>& out, const Window& w) {
        const float drop = drop_degrees * 3.14159265f / 180.0f;
        const float dx = w.nx * std::cos(drop), dy = -std::sin(drop), dz = w.nz * std::cos(drop);
        // Across the window (level) and up it.
        const float ax = -w.nz, az = w.nx;
        for (int ring = 0; ring < 2; ring++) {
            for (int i = 0; i <= sides; i++) {
                const float a = (i + 0.5f) * 2.0f * 3.14159265f / sides;
                float x = w.x + w.half_w * std::cos(a) * ax;
                float y = w.y + w.half_h * std::sin(a);
                float z = w.z + w.half_w * std::cos(a) * az;
                if (ring == 1) {
                    const float along = (y - w.floor_y) / -dy;
                    x += dx * along; y = w.floor_y; z += dz * along;
                }
                // s goes twice round the 64-texel texture, t runs down the streaks (10.5 fixed point).
                out.push_back({ int16_t(std::lround(x)), int16_t(std::lround(y)), int16_t(std::lround(z)),
                    int16_t(i * 4096 / sides), int16_t(ring == 0 ? 4096 : 0), uint8_t(ring == 0 ? top_alpha : 0) });
            }
        }
    }

    // The room's see-through model with the beams: base is its own (decompressed), or empty for a
    // model holding only the beams. Empty when base is not what is expected.
    std::vector<uint8_t> build(const std::vector<uint8_t>& base, const Room& room) {
        std::vector<uint8_t> out;
        uint32_t geo_at = 0, ncmd = 0, nv = 0, dl_at = 0, vtx_at = 0, ntex = 0;
        if (!base.empty()) {
            if (base.size() < 0x68 || rd32(base, 0) != 0x0B || rd16(base, 0x08) != 0x50 || rd32(base, 0x1C) != 0) {
                return out;
            }
            geo_at = rd32(base, 0x04);
            dl_at = rd32(base, 0x0C);
            vtx_at = rd32(base, 0x10);
            ntex = rd16(base, 0x54);
            ncmd = rd32(base, dl_at);
            nv = rd16(base, vtx_at + 0x16) / 2;
            if (geo_at == 0 || geo_at >= base.size() || 0x58 + 8 * ntex > dl_at || dl_at + 8 + 8 * ncmd > base.size() ||
                vtx_at + 0x18 + 16 * nv > base.size()) {
                return out;
            }
        }
        // Where the light texture goes in segment 2: after the model's own textures.
        const uint32_t light_at = base.empty() ? 0 : rd32(base, 0x50);

        std::vector<Vertex> tubes;
        for (const Window& w : room.windows) {
            add_tube(tubes, w);
        }

        // The beams' draw, with Mumbo's commands (0x1D02's draws).
        std::vector<std::pair<uint32_t, uint32_t>> beams = {
            { 0xD9C0FFFB, 0x00000000 }, { 0xD9FFFFFF, 0x00200004 }, { 0xD7000002, 0x80008000 },
            { 0xFD700000, 0x02000000 + light_at }, { 0xF5700000, 0x07018060 }, { 0xE6000000, 0x00000000 },
            { 0xF3000000, 0x077FF100 }, { 0xE7000000, 0x00000000 }, { 0xF5681000, 0x00018060 },
            { 0xF2000000, 0x000FC0FC }, { 0xE7000000, 0x00000000 }, { 0xFC129804, 0x3F15FFFF },
            { 0xDE000000, 0x03000020 },
        };
        const uint32_t per_tube = 2 * (sides + 1);
        uint32_t ntri = 0;
        for (uint32_t t = 0; t < room.windows.size(); t++) {
            beams.push_back({ 0x01000000 | (per_tube << 12) | (per_tube * 2), 0x01000000 + (nv + t * per_tube) * 16 });
            auto tri = [](uint32_t a, uint32_t b, uint32_t c) { return (a * 2 << 16) | (b * 2 << 8) | (c * 2); };
            for (uint32_t i = 0; i < sides; i++) {
                const uint32_t t0 = i, t1 = i + 1, b0 = sides + 1 + i, b1 = sides + 2 + i;
                // Both faces, as Mumbo's: the tube is seen from inside and out.
                beams.push_back({ 0x06000000 | tri(t0, t1, b1), tri(b1, b0, t0) });
                beams.push_back({ 0x06000000 | tri(t0, b0, b1), tri(b1, t1, t0) });
                ntri += 4;
            }
        }
        beams.push_back({ 0xDF000000, 0x00000000 });

        std::vector<uint8_t> dl;
        push32(dl, ncmd + uint32_t(beams.size()));
        push32(dl, 0);
        if (ncmd != 0) {
            append(dl, base, dl_at + 8, 8 * ncmd);
        }
        for (const auto& [w0, w1] : beams) {
            push32(dl, w0);
            push32(dl, w1);
        }

        // Vertices: the model's own, then the tubes', under a header with the bounds of both.
        std::vector<std::array<int, 3>> points;
        for (uint32_t i = 0; i < nv; i++) {
            const size_t o = vtx_at + 0x18 + 16 * i;
            points.push_back({ int16_t(rd16(base, o)), int16_t(rd16(base, o + 2)), int16_t(rd16(base, o + 4)) });
        }
        for (const Vertex& v : tubes) {
            points.push_back({ v.x, v.y, v.z });
        }
        int lo[3] = { 32767, 32767, 32767 }, hi[3] = { -32768, -32768, -32768 };
        for (const auto& p : points) {
            for (int k = 0; k < 3; k++) {
                lo[k] = std::min(lo[k], p[k]);
                hi[k] = std::max(hi[k], p[k]);
            }
        }
        int mid[3];
        for (int k = 0; k < 3; k++) {
            mid[k] = (lo[k] + hi[k]) / 2;
        }
        float local = 0.0f, global = 0.0f;
        for (const auto& p : points) {
            const float lx = float(p[0] - mid[0]), ly = float(p[1] - mid[1]), lz = float(p[2] - mid[2]);
            local = std::max(local, std::sqrt(lx * lx + ly * ly + lz * lz));
            global = std::max(global, std::sqrt(float(p[0]) * p[0] + float(p[1]) * p[1] + float(p[2]) * p[2]));
        }
        const uint32_t total_v = uint32_t(points.size());
        std::vector<uint8_t> vtx;
        for (int k = 0; k < 3; k++) push16(vtx, uint16_t(lo[k]));
        for (int k = 0; k < 3; k++) push16(vtx, uint16_t(hi[k]));
        for (int k = 0; k < 3; k++) push16(vtx, uint16_t(mid[k]));
        push16(vtx, uint16_t(std::ceil(local)));
        push16(vtx, uint16_t(std::ceil(global)));
        push16(vtx, uint16_t(total_v * 2));
        if (nv != 0) {
            append(vtx, base, vtx_at + 0x18, 16 * nv);
        }
        for (const Vertex& v : tubes) {
            push16(vtx, uint16_t(v.x)); push16(vtx, uint16_t(v.y)); push16(vtx, uint16_t(v.z)); push16(vtx, 0);
            push16(vtx, uint16_t(v.s)); push16(vtx, uint16_t(v.t));
            vtx.push_back(255); vtx.push_back(255); vtx.push_back(255); vtx.push_back(v.a);
        }

        // Geometry list: the model's own, with a draw node for the beams after its last top-level node.
        std::vector<uint8_t> geo;
        if (!base.empty()) {
            geo.assign(base.begin() + geo_at, base.end());
            uint32_t last = 0;
            for (int guard = 0;; guard++) {
                const uint32_t next = rd32(geo, last + 4);
                if (next == 0) {
                    break;
                }
                if (guard == 256 || last + next + 8 > geo.size()) {
                    return out;
                }
                last += next;
            }
            pad(geo, 8);
            put32(geo, last + 4, uint32_t(geo.size()) - last);
        }
        push32(geo, 3);           // draw
        push32(geo, 0);           // no next node
        push16(geo, uint16_t(ncmd));
        push16(geo, uint16_t(beams.size()));
        push32(geo, 0);

        // Header, texture list (the model's own, then the light), display list, vertices, geometry list.
        if (base.empty()) {
            out.assign(0x50, 0);
            put32(out, 0x00, 0x0B);
            put16(out, 0x08, 0x50);
            put16(out, 0x44, uint16_t(ntri));
            put32(out, 0x48, 0x42C80000);   // 100.0, as every level model
        } else {
            out.assign(base.begin(), base.begin() + 0x50);
        }
        push32(out, light_at + ia8_size);
        push16(out, uint16_t(ntex + 1));
        push16(out, base.empty() ? 0x0100 : rd16(base, 0x56));
        if (ntex != 0) {
            append(out, base, 0x58, 8 * ntex);
        }
        push32(out, light_texture);
        push16(out, uint16_t(ia8_type));
        out.push_back(64);
        out.push_back(64);
        pad(out, 8);
        const uint32_t dl_off = uint32_t(out.size());
        out.insert(out.end(), dl.begin(), dl.end());
        pad(out, 8);
        const uint32_t vtx_off = uint32_t(out.size());
        out.insert(out.end(), vtx.begin(), vtx.end());
        pad(out, 16);
        const uint32_t geo_off = uint32_t(out.size());
        out.insert(out.end(), geo.begin(), geo.end());
        pad(out, 16);
        put32(out, 0x04, geo_off);
        put32(out, 0x0C, dl_off);
        put32(out, 0x10, vtx_off);
        put16(out, 0x46, uint16_t(total_v));
        return out;
    }
}

bool tooie::window_beams::enabled() {
    try {
        return std::get<bool>(recompui::config::get_graphics_config().get_option_value(option));
    } catch (...) {
        return false;
    }
}

bool tooie::window_beams::has_beams(uint16_t map) {
    return std::any_of(rooms.begin(), rooms.end(), [map](const Room& room) { return has_map(room, map); });
}

void tooie::window_beams::note_map(uint16_t map) {
    looked_up_map = map;
}

std::vector<uint8_t> tooie::window_beams::model_for(uint32_t id, std::vector<uint8_t> (*rom_asset)(uint32_t id)) {
    for (size_t r = 0; r < rooms.size(); r++) {
        const Room& room = rooms[r];
        if (room.model != id) {
            continue;
        }
        // A stand-in id only while its room is the one being loaded (the id's own model, if anything
        // ever loads it, stays as it is).
        if (!enabled() || (room.stand_in && !has_map(room, looked_up_map))) {
            return {};
        }
        static std::mutex built_mutex;
        static std::array<std::vector<uint8_t>, rooms.size()> built;
        std::lock_guard lock{ built_mutex };
        if (built[r].empty()) {
            built[r] = build(room.stand_in ? std::vector<uint8_t>() : rom_asset(room.model), room);
            if (built[r].empty()) {
                fprintf(stderr, "[assets] Window light beams: model 0x%04X is not as expected, no beams\n", room.model);
            }
        }
        return built[r];
    }
    return {};
}

// Hooked in func_80800000_gcmapDll (find a map's entry in the map table) where it returns the entry
// it found: $a0 the map, $v1 the entry. Rooms with no see-through model get the stand-in id there
// while the option is on, and lose it again when it is off.
extern "C" void tooie_window_beams_map_entry(uint8_t* rdram, recomp_context* ctx) {
    const uint16_t map = uint16_t(ctx->r4);
    tooie::window_beams::note_map(map);
    for (const Room& room : rooms) {
        if (!room.stand_in || !has_map(room, map)) {
            continue;
        }
        const uint16_t now = uint16_t(MEM_H(4, ctx->r3));
        const uint16_t want = tooie::window_beams::enabled() ? uint16_t(room.model) : 0;
        if (now == 0 || now == room.model) {
            MEM_H(4, ctx->r3) = int16_t(want);
        }
    }
}
