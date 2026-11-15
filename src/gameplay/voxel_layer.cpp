// WIP > Voxel Layer: a destructible voxel layer (notes/voxel-layer-plan.md).
//
// The layer is behind the level's own geometry (L, 2026-11-13: the level's design must not change). Untouched, it is
// not there to see or to bump into: the level looks and plays as it always did. Banjo's blows and eggs dig into the
// ground and the walls.
//
// Cells. The world is cut into cells of 18 units, square to its axes, kept in sparse chunks of 8 x 8 x 8. A cell is
// filled only when a blow comes near it: one line test with the map's own func_800BEF00 (solid surfaces only) along
// the axis nearest the struck surface's normal finds the surface of its column, and the column's cells behind the
// surface, down to the layer's depth (1-2 m; 2-4 m where the world is sand or dirt), are solid. The deepest is
// bedrock and never breaks. Columns are kept, so each costs one test.
//
// Breaking (L, 2026-11-13: "two hits minimum"; then "one hit
// rule for sand and dirt"). A blow hurts the solid cells in its sphere whose material its power can hurt. Sand and
// dirt break at once; anything else by no more than half its health a blow, so it takes two at least: the first
// cracks the spot (the cracked cells are shown in place of the level's surface there, a dent, with a cracked
// texture), the next breaks them out as debris. Nothing breaks near water (L: no water physics to deal with) or near
// metal (L: metal is unbreakable, and what is close to it). Leaving the map puts everything back.
//
// Showing. A cell is shown when it is cracked or next to a broken one; only shown cells are drawn, and the level's
// own surface is cut away over shown and broken cells (RT64::SetSceneVoxelCuts: the picture, the sun shadow maps and
// the ray tracing leave out the level inside them). Where a shown cell's face lies behind the old surface, a skirt
// face fills the step up to the surface of the column beside it, so the dent never shows the empty inside of the level.
//
// Collision. The game's floor test (func_800C6A7C), its sphere push (func_800C6C94) and its swept sphere
// (func_800C6B78) each ask up to 8 collision providers in turn. Hooks drop a provider's contact when the contact is in
// a cut cell, so the level's surface stops where it is dug: Banjo falls into a hole in the floor and walks into one in
// a wall. The floor test is answered again past the dropped contact; a shown cell's top is a floor where the cell
// above it is dug, its bottom a ceiling where the cell below it is. In the draw hook his body is pushed out of shown
// cells higher than a step.
//
// Drawing. Each shown chunk's mesh (cubes' faces toward air or broken cells, skirts, per-vertex ambient occlusion, a
// colour jitter per cell, cracks, and a grain texture made here; no game art) is built into an arena taken from the
// game heap and rebuilt when the chunk changes. Each frame one G_DL goes into the game's list, to a list of ours in
// one of eight rotating slots: render state, then each chunk's matrix (its place in the world: the camera is all in
// the projection) and mesh, then the debris cubes. A rebuilt mesh's old block is freed only eight frames later.
//
// Console: voxel (docs/console.md).

#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <map>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "recomp.h"
#include "funcs.h"
#include "librecomp/config.hpp"
#include "recompui/config.h"
#include "tooie_debug.h"
#include "tooie_effect_views.h"
#include "tooie_game.h"
#include "tooie_game_frame_rate.h"
#include "tooie_gfx_budget.h"
#include "tooie_rdram.h"
#include "tooie_voxel_layer.h"

// RT64 (rt64-ext/src/render/rt64_scene_effects.cpp): the cells whose level geometry is left out, as a hash table of
// 4 words a slot (x, y, z, 1 when used), after a header of 4 words (slot count, cells, 0, 0). Copied at once.
namespace RT64 {
    void SetSceneVoxelCuts(const uint32_t* table, uint32_t words);
    // The colour of the level's surface at a place (its texture's average times its vertex colours), asked for by
    // ticket and found in the next frame's draws (rt64_scene_effects.h).
    void RequestSceneSurfaceColour(const float point[3], const float facing[3], uint32_t ticket);
    bool SceneSurfaceColour(uint32_t ticket, float rgb[3], uint64_t* textureHash, float* repeat);
    // That texture as 32 x 32 RGBA16 (5551) values.
    bool SceneTextureRGBA16(uint64_t hash, uint16_t texels[1024]);
}

namespace {
    using namespace tooie::rdram;

    constexpr float pi = 3.14159265f;
    constexpr float deg = pi / 180.0f;

    // ---------------------------------------------------------------------------------------------------------------
    // The game

    constexpr uint32_t player_table = 0x80135490;
    constexpr uint32_t physics_offset = 0xC8;      // PlayerState -> physics block: position +4, velocity +0x10
    constexpr uint32_t pos_ptr_offset = 0xE4;      // PlayerState -> three copies of the position, 0xC apart
    constexpr uint32_t yaw_ptr_offset = 0xF8;      // PlayerState -> facing, degrees, 0 faces +z
    constexpr uint32_t state_offset = 0x120;       // PlayerState -> state block, current state +4
    constexpr uint32_t last_pos_offset = 0x29C;    // where the game's collision restarts from next frame
    constexpr uint32_t camera_ptr = 0x8012D500;    // the camera being drawn: position +0

    constexpr uint32_t object_array_pointer = 0x80136EE0;
    constexpr uint32_t object_size = 0x9C;
    constexpr int max_objects = 2048;
    constexpr uint32_t object_pos = 0x04;
    constexpr uint32_t marker_model = 0x14;

    // Eggs in flight, by model (torch_enemy.cpp, damage_mods.cpp): blue, fire, ice, grenade, clockwork, golden,
    // proximity. They are in the object array (spawned by func_80108474 as actors 0x15A-0x160).
    constexpr uint16_t egg_blue = 0x09D7, egg_fire = 0x09C1, egg_ice = 0x09C0, egg_grenade = 0x09C2,
        egg_clockwork = 0x09C4, egg_golden = 0x09C3, egg_proximity = 0x09C5;

    // The game's line test against the map (func_800BEF00(from, to, normal, kind)): kinds for water surfaces only,
    // and for solid surfaces (no water), as enemy_spawner.cpp.
    constexpr uint32_t kind_water_surface = 0x1F00;
    constexpr uint32_t kind_solid = 0x20020;
    // A collision triangle's flags (+8): its surface type in 0x1F00, which the game turns into footstep sounds
    // (func_800C84B0, a table at 0x8011A930); 0x20000 water, 0x2000 a hazard liquid, 0x20 left out of Banjo's floor
    // test. Those are never dug.
    constexpr uint32_t surface_type_mask = 0x1F00;
    constexpr uint32_t no_dig_flags = 0x22020;

    // The collision providers' table (func_800C6A7C and its two siblings): 16 bytes an entry, its end at +0x80, the
    // object a hit belongs to at +0x84.
    constexpr uint32_t providers = 0x8012AA40;

    // States that keep the player still or out of play: dead, and the locked ones (player_cheats.cpp).
    bool locked_state(uint32_t s) {
        return s == 0x41 || s == 0x97 || s == 0x93 || s == 0x92 || s == 0x5D || s == 0x75 || s == 0x9A || s == 0;
    }

    // ---------------------------------------------------------------------------------------------------------------
    // Materials

    enum Mat : uint8_t {
        Empty = 0, Dirt, GrassDirt, Clay, Sand, Snow, Cheese, Ice, Stone, Sandstone, Brick, Rock, DarkStone, AshRock,
        Gold,
        Marker,   // voxel voidscan's markers (never a cell's material)
        MatCount
    };

    struct MatInfo {
        const char* name;
        uint8_t r, g, b;
        uint8_t hardness;   // the least power that hurts it
        uint8_t health;     // damage that breaks it
        float jitter;       // how much one cell's shade differs from the next
        uint16_t sound;     // the game's sound for a break (0: none yet)
        float pitch;
    };

    // Sound ids are the game's; 0 until picked by ear (voxel sound <id>).
    MatInfo mats[MatCount] = {
        { "empty",      0,   0,   0,   0, 0,  0.00f, 0, 1.0f },
        { "dirt",       122, 84,  52,  1, 20, 0.10f, 0, 1.0f },
        { "grass",      128, 90,  54,  1, 20, 0.10f, 0, 1.1f },   // inside grass is dirt (L, 2026-11-13)
        { "clay",       170, 96,  62,  1, 20, 0.08f, 0, 0.95f },
        { "sand",       222, 196, 132, 1, 10, 0.06f, 0, 1.2f },
        { "snow",       236, 242, 250, 1, 10, 0.03f, 0, 1.25f },
        { "cheese",     246, 204, 70,  1, 10, 0.06f, 0, 1.15f },
        { "ice",        150, 206, 240, 2, 20, 0.06f, 0, 1.3f },
        { "stone",      132, 132, 138, 2, 30, 0.10f, 0, 1.0f },
        { "sandstone",  206, 160, 104, 2, 30, 0.08f, 0, 1.05f },
        { "brick",      160, 70,  56,  2, 30, 0.08f, 0, 0.95f },
        { "rock",       98,  90,  86,  3, 40, 0.10f, 0, 0.85f },
        { "darkstone",  70,  64,  82,  3, 40, 0.08f, 0, 0.8f },
        { "ashrock",    64,  48,  44,  3, 40, 0.10f, 0, 0.8f },
        { "gold",       236, 186, 40,  3, 60, 0.12f, 0, 1.4f },
        { "marker",     255, 0,   255, 255, 255, 0.0f, 0, 1.0f },
    };

    Mat mat_by_name(const std::string& name) {
        for (int m = 1; m < MatCount; m++) {
            if (name == mats[m].name) {
                return (Mat)m;
            }
        }
        return Empty;
    }

    // A world's layers: the outer layer, the one under it, and a seam of a third with this chance.
    struct Palette {
        Mat top, base, vein;
        float vein_chance;
    };

    struct MapName {
        uint16_t id;
        const char* name;
    };
    constexpr MapName map_names[] = {
#include "../game/map_names.inc"
    };

    const char* map_name(uint16_t map) {
        for (const MapName& m : map_names) {
            if (m.id == map) {
                return m.name;
            }
        }
        return "";
    }

    bool starts_with(const char* s, const char* prefix) {
        return std::strncmp(s, prefix, std::strlen(prefix)) == 0;
    }

    // Everywhere can be dug but the cutscene maps.
    bool map_allowed(uint16_t map) {
        const char* name = map_name(map);
        return name[0] != 0 && !starts_with(name, "Cutscene");
    }

    Palette palette_for(uint16_t map) {
        const char* name = map_name(map);
        if (starts_with(name, "MT")) return { Sandstone, Stone, Rock, 0.05f };
        if (starts_with(name, "GGM")) return { Rock, Stone, Gold, 0.06f };
        if (starts_with(name, "WW")) return { GrassDirt, Dirt, Brick, 0.04f };
        if (starts_with(name, "JRL")) return { Sand, Stone, Rock, 0.05f };
        if (starts_with(name, "TDL")) return { GrassDirt, Clay, Rock, 0.08f };
        if (starts_with(name, "GI")) return { Brick, Stone, Rock, 0.05f };
        if (starts_with(name, "HFP")) {
            if (std::strstr(name, "Lava") != nullptr || std::strstr(name, "Volcano") != nullptr || std::strstr(name, "Chilli Billi") != nullptr) {
                return { AshRock, Rock, Gold, 0.02f };
            }
            return { Snow, Ice, Stone, 0.05f };
        }
        if (starts_with(name, "CCL")) return { Cheese, Cheese, Sand, 0.04f };
        if (starts_with(name, "CK")) return { DarkStone, Rock, Stone, 0.06f };
        return { GrassDirt, Dirt, Stone, 0.06f };   // Spiral Mountain, Isle o' Hags, Jinjo Village
    }

    bool soil(Mat m) {
        return m == Dirt || m == GrassDirt || m == Clay || m == Sand;
    }

    // ---------------------------------------------------------------------------------------------------------------
    // Small helpers

    uint32_t hash32(uint32_t x) {
        x ^= x >> 16; x *= 0x7FEB352Du; x ^= x >> 15; x *= 0x846CA68Bu; x ^= x >> 16;
        return x;
    }
    uint32_t hash3(uint32_t a, uint32_t b, uint32_t c) {
        return hash32(a * 0x9E3779B1u ^ hash32(b * 0x85EBCA77u ^ hash32(c + 0x27D4EB2Fu)));
    }
    // 0 to 1.
    float unit(uint32_t h) {
        return (float)(h & 0xFFFFFF) / (float)0x1000000;
    }

    // Smooth noise in 0..1 over a grid of cells `cell` wide, the same for the same seed.
    float smooth_noise(uint32_t seed, int i, int j, int cell) {
        const int ci = (int)std::floor(i / (float)cell), cj = (int)std::floor(j / (float)cell);
        const float fx = i / (float)cell - ci, fy = j / (float)cell - cj;
        const float sx = fx * fx * (3 - 2 * fx), sy = fy * fy * (3 - 2 * fy);
        auto at = [&](int a, int b) { return unit(hash3(seed, (uint32_t)a, (uint32_t)b)); };
        const float top = at(ci, cj) + (at(ci + 1, cj) - at(ci, cj)) * sx;
        const float bottom = at(ci, cj + 1) + (at(ci + 1, cj + 1) - at(ci, cj + 1)) * sx;
        return top + (bottom - top) * sy;
    }

    struct Rng {
        uint32_t s;
        explicit Rng(uint32_t seed) : s(seed ? seed : 1) {}
        uint32_t next() { s ^= s << 13; s ^= s >> 17; s ^= s << 5; return s; }
        float f() { return unit(next()); }
        float range(float a, float b) { return a + (b - a) * f(); }
    };

    // A number setting (the sliders below the Voxel Layer switch), or its default when it can't be read.
    double number_option(const std::string& id, double fallback) {
        try {
            return std::get<double>(recompui::config::get_graphics_config().get_option_value(id));
        } catch (...) {
            return fallback;
        }
    }

    // The sliders, read once a tick (they apply at once, to the next blow and the next ground filled in).
    struct Sliders {
        float strength = 1.0f;          // 1 = 100%
        float depth_soft = 2.0f;        // metres
        float depth_stone = 1.0f;
        float depth_rock = 1.0f;
    } sliders;

    void read_sliders() {
        sliders.strength = (float)std::clamp(number_option(tooie::voxel_layer::strength_option, 100.0) / 100.0, 0.1, 10.0);
        sliders.depth_soft = (float)std::clamp(number_option(tooie::voxel_layer::depth_soft_option, 2.0), 0.25, 20.0);
        sliders.depth_stone = (float)std::clamp(number_option(tooie::voxel_layer::depth_stone_option, 1.0), 0.25, 20.0);
        sliders.depth_rock = (float)std::clamp(number_option(tooie::voxel_layer::depth_rock_option, 1.0), 0.25, 20.0);
    }

    bool option_on() {
        static const bool forced = std::getenv("TOOIE_VOXELS") != nullptr;
        if (forced) {
            return true;
        }
        try {
            return std::get<bool>(recompui::config::get_graphics_config().get_option_value(tooie::voxel_layer::option));
        } catch (...) {
            return false;
        }
    }

    bool log_on() {
        static const bool on = std::getenv("TOOIE_VOXEL_LOG") != nullptr;
        return on;
    }

    float length3(const float v[3]) {
        return std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    }

    // ---------------------------------------------------------------------------------------------------------------
    // Calling the game

    struct GameCall {
        uint8_t* rdram;
        recomp_context* ctx;
        recomp_context saved;
        uint32_t scratch;

        GameCall(uint8_t* rdram_, recomp_context* ctx_) : rdram(rdram_), ctx(ctx_), saved(*ctx_) {
            scratch = (((uint32_t)ctx->r29) - 0x200u) & ~0xFu;
            ctx->r29 = (int32_t)(scratch - 0x80u);
        }
        ~GameCall() {
            *ctx = saved;
        }
        gpr operator()(void (*fn)(uint8_t*, recomp_context*), uint32_t a0 = 0, uint32_t a1 = 0, uint32_t a2 = 0, uint32_t a3 = 0) {
            ctx->r29 = (int32_t)(scratch - 0x80u);
            ctx->r4 = (int32_t)a0;
            ctx->r5 = (int32_t)a1;
            ctx->r6 = (int32_t)a2;
            ctx->r7 = (int32_t)a3;
            fn(rdram, ctx);
            return ctx->r2;
        }
        void vec(uint32_t offset, const float v[3]) {
            for (int i = 0; i < 3; i++) {
                write_float(rdram, scratch + offset + 4 * i, v[i]);
            }
        }
    };

    // The game's sound at a place (func_800C401C(sound, pitch, volume, position, near, far, 2)), as torch_enemy.cpp.
    void play_sound(uint8_t* rdram, recomp_context* ctx, uint32_t sound, const float pos[3], float pitch, float volume) {
        if (sound == 0) {
            return;
        }
        GameCall call(rdram, ctx);
        call.vec(0, pos);
        const uint32_t sp = call.scratch - 0x80u;
        write_float(rdram, sp + 0x10, 200.0f);
        write_float(rdram, sp + 0x14, 2500.0f);
        write_word(rdram, sp + 0x18, 2);
        uint32_t pitch_bits;
        std::memcpy(&pitch_bits, &pitch, 4);
        call(func_800C401C, sound, pitch_bits, (uint32_t)(0x7FFF * std::clamp(volume, 0.0f, 1.0f)), call.scratch);
    }

    // The map's line test from `from` to `to` for this kind: the point where it meets a surface, the surface's normal
    // and its triangle's flags (+8).
    bool line_test(uint8_t* rdram, recomp_context* ctx, const float from[3], const float to[3], uint32_t kind,
                   float hit[3], float normal[3], uint32_t* tri_flags) {
        GameCall call(rdram, ctx);
        const uint32_t v = call.scratch;
        call.vec(0x00, from);
        call.vec(0x10, to);
        for (int c = 0; c < 3; c++) write_float(rdram, v + 0x20 + 4 * c, 0.0f);
        const uint32_t tri = (uint32_t)call(func_800BEF00, v, v + 0x10, v + 0x20, kind);
        if (tri == 0) {
            return false;
        }
        for (int c = 0; c < 3; c++) {
            hit[c] = read_float(rdram, v + 0x10 + 4 * c);
            normal[c] = read_float(rdram, v + 0x20 + 4 * c);
        }
        if (tri_flags != nullptr) {
            *tri_flags = valid_ptr(tri) ? read_word(rdram, tri + 8) : 0;
        }
        for (int c = 0; c < 3; c++) {
            if (!std::isfinite(hit[c]) || !std::isfinite(normal[c])) return false;
        }
        return true;
    }

    // The highest water surface between from_y and to_y at (x, z), if any.
    bool water_at(uint8_t* rdram, recomp_context* ctx, float x, float z, float from_y, float to_y, float* hit_y) {
        const float from[3] = { x, from_y, z }, to[3] = { x, to_y, z };
        float hit[3], n[3];
        if (!line_test(rdram, ctx, from, to, kind_water_surface, hit, n, nullptr)) return false;
        *hit_y = hit[1];
        return true;
    }

    // ---------------------------------------------------------------------------------------------------------------
    // Cells

    constexpr float vs = 18.0f;                 // a cell's size
    constexpr int chunk_n = 8;                  // cells a chunk side
    constexpr int chunk_cells = chunk_n * chunk_n * chunk_n;
    constexpr float metre = 100.0f;             // Banjo stands about 105
    constexpr float column_start = 4 * 18.0f;   // a column's line test starts this far out from the struck surface
    constexpr float column_reach = 600.0f;      // and runs this far in past it

    enum CellState : uint8_t { Unknown = 0, Air, Solid, Dug, Bedrock };
    constexpr uint8_t cell_wet = 1;
    constexpr uint8_t cell_piled = 2;   // soil thrown up round a hole dug down (above the level's surface)

    // Which way a column runs: its axis (0 x, 1 y, 2 z) times 2, plus 1 when the surface faces the axis's minus side.
    int dir_code(int axis, int sign) { return axis * 2 + (sign < 0 ? 1 : 0); }
    int dir_axis(int code) { return code >> 1; }
    int dir_sign(int code) { return (code & 1) ? -1 : 1; }

    uint64_t pack3(int x, int y, int z) {
        return ((uint64_t)(uint32_t)(x & 0x1FFFFF) << 42) | ((uint64_t)(uint32_t)(y & 0x1FFFFF) << 21) | (uint64_t)(uint32_t)(z & 0x1FFFFF);
    }

    int cell_of(float w) {
        return (int)std::floor(w / vs);
    }
    int chunk_of(int c) {
        return c >= 0 ? c / chunk_n : -((-c + chunk_n - 1) / chunk_n);
    }

    struct Block {
        uint32_t addr = 0;      // in the arena (0: none)
        uint32_t bytes = 0;
    };

    struct Chunk {
        int cx = 0, cy = 0, cz = 0;   // chunk coordinates
        uint8_t state[chunk_cells] = {};
        uint8_t mat[chunk_cells] = {};
        uint8_t dmg[chunk_cells] = {};
        uint8_t flags[chunk_cells] = {};
        uint8_t dir[chunk_cells] = {};       // the column direction it was filled from
        float surface[chunk_cells] = {};     // that column's surface, along its axis
        uint32_t ground_flags = 0;           // a floor triangle's flags seen while filling (footstep sounds)
        bool dirty = false;
        Block mesh;
        uint32_t mesh_dl = 0;       // the faces of shown cells not cracked (grain texture)
        uint32_t crack_dl = 0;      // the faces of cracked cells (cracked texture)
        uint32_t retry_after = 0;
        int shown = 0;
        static int index(int lx, int ly, int lz) { return (lz * chunk_n + ly) * chunk_n + lx; }
    };

    struct Column {
        bool hit = false;
        float surface = 0.0f;
        int layers = 0;          // cells deep, the last of them bedrock
        uint32_t tri_flags = 0;
        bool wet = false;
        // The colour of the level's surface over it (0 to 1 each), once RT64 has found it (L, 2026-11-13: the inside of
        // a green mountain is green).
        bool tinted = false;
        float tint[3] = { 0.0f, 0.0f, 0.0f };
        // The level's own texture there, by arena slot (1 on; 0: the grain, in the cells' colour): the inside of what
        // Banjo breaks is drawn with the texture of the surface he broke (L, 2026-11-13: the plain colour didn't fit the
        // game's texture style).
        int tex = 0;
    };

    uint64_t column_key(int code, int x, int y, int z) {
        const int a = dir_axis(code);
        const int cell[3] = { x, y, z };
        const int u = cell[(a + 1) % 3], v = cell[(a + 2) % 3];
        return ((uint64_t)code << 58) | ((uint64_t)(uint32_t)(u & 0x1FFFFFFF) << 29) | (uint64_t)(uint32_t)(v & 0x1FFFFFFF);
    }

    // The columns made since the last strike began (strike asks RT64 for their colour).
    std::vector<uint64_t> fresh_columns;

    // One map's cells, from the first blow until the map is left (L, 2026-11-13: reset on level exit).
    struct World {
        std::unordered_map<uint64_t, std::unique_ptr<Chunk>> chunks;
        std::unordered_map<uint64_t, Column> columns;
        std::unordered_set<uint64_t> cut;    // dug and shown cells: the level's geometry is left out in them
        bool cut_changed = false;
        int dug = 0;
        int cut_lo_y = 1 << 30, cut_hi_y = -(1 << 30);   // the cut cells' lowest and highest rows (publish_cuts)
    } world;

    Chunk* chunk_at(int x, int y, int z, bool make) {
        const int cx = chunk_of(x), cy = chunk_of(y), cz = chunk_of(z);
        const uint64_t key = pack3(cx, cy, cz);
        auto it = world.chunks.find(key);
        if (it != world.chunks.end()) return it->second.get();
        if (!make) return nullptr;
        auto c = std::make_unique<Chunk>();
        c->cx = cx; c->cy = cy; c->cz = cz;
        Chunk* p = c.get();
        world.chunks.emplace(key, std::move(c));
        return p;
    }

    int local_index(const Chunk& c, int x, int y, int z) {
        return Chunk::index(x - c.cx * chunk_n, y - c.cy * chunk_n, z - c.cz * chunk_n);
    }

    uint8_t state_at(int x, int y, int z) {
        const Chunk* c = chunk_at(x, y, z, false);
        return c == nullptr ? Unknown : c->state[local_index(*c, x, y, z)];
    }

    bool solid_state(uint8_t s) {
        return s == Solid || s == Bedrock;
    }

    bool is_cut(int x, int y, int z) {
        return world.cut.count(pack3(x, y, z)) != 0;
    }

    bool is_cut_at(const float w[3]) {
        return !world.cut.empty() && is_cut(cell_of(w[0]), cell_of(w[1]), cell_of(w[2]));
    }

    // Shown: solid, and cracked or beside a broken cell.
    bool shown(int x, int y, int z) {
        const Chunk* c = chunk_at(x, y, z, false);
        if (c == nullptr) return false;
        const int i = local_index(*c, x, y, z);
        if (!solid_state(c->state[i])) return false;
        if (c->dmg[i] > 0 || (c->flags[i] & cell_piled)) return true;
        static constexpr int n6[6][3] = { { 1, 0, 0 }, { -1, 0, 0 }, { 0, 1, 0 }, { 0, -1, 0 }, { 0, 0, 1 }, { 0, 0, -1 } };
        for (const auto& d : n6) {
            if (state_at(x + d[0], y + d[1], z + d[2]) == Dug) return true;
        }
        return false;
    }

    // A dug cell among the 26 round (x, y, z): a solid cell there draws at least its face to the surface (build_mesh).
    bool near_dug(int x, int y, int z) {
        for (int dz = -1; dz <= 1; dz++) for (int dy = -1; dy <= 1; dy++) for (int dx = -1; dx <= 1; dx++) {
            if (state_at(x + dx, y + dy, z + dz) == Dug) return true;
        }
        return false;
    }

    // The column through cell (x, y, z) running along `code`'s axis, its surface found from `ref` (a coordinate
    // along the axis near the surface).
    // The depth slider for a level's ground: soft ground (sand on top, or soft ground under it), stone, or rock, by the
    // ground's hardness.
    float depth_for(const Palette& pal) {
        if (soil(pal.base) || pal.top == Sand || mats[pal.base].hardness <= 1) return sliders.depth_soft;
        return mats[pal.base].hardness >= 3 ? sliders.depth_rock : sliders.depth_stone;
    }

    const Column& column(uint8_t* rdram, recomp_context* ctx, int code, int x, int y, int z, float ref) {
        const int a = dir_axis(code), s = dir_sign(code);
        const int cell[3] = { x, y, z };
        const int u = cell[(a + 1) % 3], v = cell[(a + 2) % 3];
        const uint64_t key = column_key(code, x, y, z);
        auto it = world.columns.find(key);
        if (it != world.columns.end()) return it->second;
        fresh_columns.push_back(key);
        Column col;
        float from[3], to[3];
        for (int c = 0; c < 3; c++) from[c] = to[c] = (cell[c] + 0.5f) * vs;
        from[a] = ref + s * column_start;
        to[a] = ref - s * column_reach;
        float hit[3], n[3];
        uint32_t flags = 0;
        // Only a surface facing out along the column (a wall's back or an overhang's underside is not the face), and
        // not water (0x20000), a hazard liquid (0x2000) or the other kind Banjo's own floor test leaves out (0x20).
        if (line_test(rdram, ctx, from, to, kind_solid, hit, n, &flags) && n[a] * s > 0.3f && (flags & no_dig_flags) == 0) {
            col.hit = true;
            col.surface = hit[a];
            col.tri_flags = flags;
            const Palette pal = palette_for(tooie::debug::current_map(rdram));
            // Depth (L, 2026-11-13): by the level's ground, from the depth sliders (1-2 m by default, 2-4 m in sand
            // or dirt): the slider's metres to twice that, swelling smoothly from column to column.
            const float depth = depth_for(pal) * metre * (1.0f + smooth_noise(0xD16 + code, u, v, 5));
            col.layers = std::max(2, (int)std::lround(depth / vs));
            if (a == 1 && s > 0) {
                float wy;
                if (water_at(rdram, ctx, hit[0], hit[2], hit[1] + 600.0f, hit[1] - 10.0f, &wy) && wy > hit[1] + 5.0f) col.wet = true;
            }
        }
        return world.columns.emplace(key, col).first->second;
    }

    // Fills cell (x, y, z) from its column, if it is not known yet. The blow's own column direction first; when that
    // finds it in open air, the floor's column and then the four sideways ones too (from a little way out): a cell
    // under the ground beside a dug wall is in front of the wall's surface, yet under the floor's. Without them it
    // counted as open air, nothing was drawn there, and a cut in the level showed the empty inside of the world (L's
    // picture, 2026-11-13).
    void ensure(uint8_t* rdram, recomp_context* ctx, int x, int y, int z, int code, float ref) {
        Chunk* c = chunk_at(x, y, z, true);
        const int i = local_index(*c, x, y, z);
        if (c->state[i] != Unknown) return;
        const int cell[3] = { x, y, z };
        const int tries[6] = { code, dir_code(1, 1), dir_code(0, 1), dir_code(0, -1), dir_code(2, 1), dir_code(2, -1) };
        const Column* found = nullptr;
        int found_code = code;
        float found_behind = 0.0f;
        for (int k = 0; k < 6; k++) {
            const int cd = tries[k];
            if (k > 0 && cd == code) continue;
            const int a = dir_axis(cd), sgn = dir_sign(cd);
            const float middle = (cell[a] + 0.5f) * vs;
            // The blow's own column starts from its struck surface; the others from 240 out of the cell.
            const float r = k == 0 ? ref : middle + sgn * (240.0f - column_start);
            const Column& col = column(rdram, ctx, cd, x, y, z, r);
            if (k == 0) {
                c->dir[i] = (uint8_t)cd;
                c->surface[i] = col.surface;
            }
            if (!col.hit) continue;
            // A cell is solid only when all of it is behind the surface, so a cracked or dug cell is always at or
            // below the old surface (a dent, never a ledge: seen 2026-11-13 on Grunty Industries' floor).
            const float behind = sgn > 0 ? col.surface - middle : middle - col.surface;
            if (behind < vs * 0.5f) continue;
            found = &col;
            found_code = cd;
            found_behind = behind;
            break;
        }
        if (found == nullptr) {
            c->state[i] = Air;
            return;
        }
        const Column& col = *found;
        c->dir[i] = (uint8_t)found_code;
        c->surface[i] = col.surface;
        const int t = (int)((found_behind - vs * 0.5f) / vs);
        const Palette pal = palette_for(tooie::debug::current_map(rdram));
        if (t >= col.layers - 1) {
            c->state[i] = Bedrock;
            c->mat[i] = pal.base;
        }
        else {
            c->state[i] = Solid;
            // Deep sand is sand half way in; elsewhere one cell of the outer layer.
            const int top_layers = pal.top == Sand ? std::max(1, col.layers / 2) : 1;
            Mat m = t < top_layers ? pal.top : pal.base;
            if (unit(hash3(x * 7 + 1, y * 13 + 5, z * 3 + 9)) < pal.vein_chance * (t == 0 ? 1.0f : 3.0f)) m = pal.vein;
            c->mat[i] = m;
        }
        if (col.wet) c->flags[i] |= cell_wet;
        if (dir_axis(found_code) == 1 && dir_sign(found_code) > 0 && c->ground_flags == 0) c->ground_flags = col.tri_flags;
    }

    void mark_dirty(int x, int y, int z) {
        // The chunk and, at its edges, the ones beside it (their faces and occlusion look across).
        for (int dz = -1; dz <= 1; dz++) for (int dy = -1; dy <= 1; dy++) for (int dx = -1; dx <= 1; dx++) {
            Chunk* c = chunk_at(x + dx, y + dy, z + dz, false);
            if (c != nullptr) c->dirty = true;
        }
    }

    // Works out the cut cells again round a changed cell.
    void recut_around(int x, int y, int z) {
        for (int dz = -1; dz <= 1; dz++) for (int dy = -1; dy <= 1; dy++) for (int dx = -1; dx <= 1; dx++) {
            const int a = x + dx, b = y + dy, c = z + dz;
            const uint64_t key = pack3(a, b, c);
            // Cut out of the level: the dug cells and the cracked ones. A whole cell beside a hole is drawn (shown) but
            // keeps the level's surface over it: the smooth surface's rim starts under it.
            const uint8_t st = state_at(a, b, c);
            bool want = st == Dug;
            if (!want && solid_state(st)) {
                const Chunk* ck = chunk_at(a, b, c, false);
                want = ck != nullptr && ck->dmg[local_index(*ck, a, b, c)] > 0;
                // A whole cell with dug cells on both sides of it across its column (left and right, or above and
                // below) is inside the hole's opening: cut too, with its face to the surface drawn. Kept, the level's
                // surface over it showed as a thin sliver across the hole (2026-11-15).
                if (!want && ck != nullptr) {
                    const int axis = dir_axis(ck->dir[local_index(*ck, a, b, c)]);
                    for (int t = 1; t < 3 && !want; t++) {
                        int lo[3] = { a, b, c }, hi[3] = { a, b, c };
                        const int k = (axis + t) % 3;
                        lo[k]--; hi[k]++;
                        want = state_at(lo[0], lo[1], lo[2]) == Dug && state_at(hi[0], hi[1], hi[2]) == Dug;
                    }
                }
            }
            const bool has = world.cut.count(key) != 0;
            if (want != has) {
                if (want) world.cut.insert(key); else world.cut.erase(key);
                world.cut_changed = true;
                if (want) {
                    world.cut_lo_y = std::min(world.cut_lo_y, b);
                    world.cut_hi_y = std::max(world.cut_hi_y, b);
                }
            }
        }
    }

    // The dug and shown cells to RT64, as a hash table (see SetSceneVoxelCuts at the top), when they changed.
    uint32_t cut_hash(int x, int y, int z, uint32_t mask) {
        return (((uint32_t)x * 73856093u) ^ ((uint32_t)y * 19349663u) ^ ((uint32_t)z * 83492791u)) & mask;
    }

    void publish_cuts() {
        world.cut_changed = false;
        const uint32_t count = (uint32_t)world.cut.size();
        uint32_t slots = 0;
        if (count > 0) {
            slots = 64;
            while (slots < count * 2) slots <<= 1;
        }
        // The shaders look at most 32 slots on from a cell's own (VoxelCuts.hlsli): a table with a longer run is made
        // again twice the size.
        std::vector<uint32_t> table;
        for (;;) {
            // Header (12 words): slot count, cells, 0, 0, the lowest cell x y z, 0, the highest x y z, 0. The shaders
            // skip every point outside the bounds without looking in the table (most of a level draw's pixels).
            table.assign(12 + (size_t)slots * 4, 0);
            table[0] = slots;
            table[1] = count;
            uint32_t longest = 0;
            for (uint64_t key : world.cut) {
                // Back from pack3: 21-bit fields, sign-extended.
                auto field = [](uint64_t v) { int32_t f = (int32_t)(v & 0x1FFFFF); return (f & 0x100000) ? f - 0x200000 : f; };
                const int x = field(key >> 42), y = field(key >> 21), z = field(key);
                uint32_t h = cut_hash(x, y, z, slots - 1);
                uint32_t run = 0;
                while (table[12 + h * 4 + 3] != 0) { h = (h + 1) & (slots - 1); run++; }
                longest = std::max(longest, run);
                table[12 + h * 4 + 0] = (uint32_t)x;
                table[12 + h * 4 + 1] = (uint32_t)y;
                table[12 + h * 4 + 2] = (uint32_t)z;
                table[12 + h * 4 + 3] = 1;
            }
            if (count > 0) {
                int lo[3] = { INT32_MAX, INT32_MAX, INT32_MAX }, hi[3] = { INT32_MIN, INT32_MIN, INT32_MIN };
                for (uint64_t key : world.cut) {
                    auto field = [](uint64_t v) { int32_t f = (int32_t)(v & 0x1FFFFF); return (f & 0x100000) ? f - 0x200000 : f; };
                    const int c3[3] = { field(key >> 42), field(key >> 21), field(key) };
                    for (int c = 0; c < 3; c++) { lo[c] = std::min(lo[c], c3[c]); hi[c] = std::max(hi[c], c3[c]); }
                }
                for (int c = 0; c < 3; c++) { table[4 + c] = (uint32_t)lo[c]; table[8 + c] = (uint32_t)hi[c]; }
            }
            if (slots == 0 || longest < 32 || slots >= (1u << 20)) break;
            slots <<= 1;
        }
        // The cut cells' bounds, for the floor answer's search (cell_face_on_line).
        world.cut_lo_y = 1 << 30;
        world.cut_hi_y = -(1 << 30);
        for (uint64_t key : world.cut) {
            int32_t y = (int32_t)((key >> 21) & 0x1FFFFF);
            if (y & 0x100000) y -= 0x200000;
            world.cut_lo_y = std::min(world.cut_lo_y, (int)y);
            world.cut_hi_y = std::max(world.cut_hi_y, (int)y);
        }
        RT64::SetSceneVoxelCuts(table.data(), (uint32_t)table.size());
    }

    // ---------------------------------------------------------------------------------------------------------------
    // The arena: game heap memory for the per-frame lists, the grain texture, the debris cubes, the fake floor
    // triangles and the meshes.

    constexpr uint32_t frame_slots = 8;
    constexpr uint32_t frame_slot_bytes = 48 * 1024;
    constexpr uint32_t texture_bytes = 32 * 32;   // each of the two textures: the grain, then the cracks
    constexpr uint32_t cube_block_bytes = 24 * 16 + 8 * 8;
    constexpr uint32_t floor_tri_slots = 64;    // fake floor triangles, used in turn (see floor_exit)
    constexpr uint32_t floor_tri_bytes = 16;
    // Level textures: up to 15 a map in slots 1..15, and each one's cracked copy (for a cell hit once) 16 slots on.
    // Slot 0 is unused (the grain texture is its own).
    constexpr uint32_t level_tex_kinds = 16;
    constexpr uint32_t level_tex_cracked = 16;    // added to a slot for its cracked copy
    constexpr uint32_t level_tex_slots = 32;
    constexpr uint32_t level_tex_bytes = 32 * 32 * 2;
    // Wooded Hollow has about 1.8 MB free in one piece (2026-11-13), so the layer makes do with less where it must.
    constexpr uint32_t arena_want = 1536 * 1024;
    constexpr uint32_t arena_least = 640 * 1024;
    constexpr uint32_t heap_margin = 768 * 1024;   // left free in the game's heap
    constexpr float arena_retry_seconds = 5.0f;    // a map short of heap is asked again after this

    float game_time = 0.0f;   // seconds of game time since the game started (tick)
    float game_time_now() { return game_time; }
    uint16_t current_map = 0xFFFF;   // the map the cells belong to (tick)

    // A map change lays the game's heap out again (pose_puppets.cpp), so the arena belongs to the map it was taken
    // in: on a change it is forgotten, not freed, and a new one is taken in the new map.
    struct Arena {
        uint16_t map = 0xFFFF;
        uint32_t block = 0;         // from heap_alloc
        uint32_t base = 0;          // 64-aligned start
        uint32_t size = 0;
        uint32_t frames = 0;        // the frame slots
        uint32_t texture = 0;
        uint32_t cubes = 0;         // MatCount debris cubes: a list then its vertices
        uint32_t floor_tris = 0;    // floor_tri_slots fake floor triangles
        uint32_t level_tex = 0;     // level_tex_slots textures copied from the level's (32 x 32 RGBA16)
        std::unordered_map<uint64_t, int> tex_slot_of;   // texture hash -> slot
        // Texels per world unit for each slot's faces, so the inside of a break has the texture at the size the level
        // has it (L, 2026-11-13: it looked far too busy at the grain's size).
        float tex_scale[level_tex_kinds] = {};
        // The last colour and texture the level's surface gave a break, for cells whose own column never got one
        // (they showed the map's plain stone, flat grey squares in a green mountain's hole).
        bool has_look = false;
        float look_tint[3] = {};
        int look_slot = 0;
        uint32_t pool = 0, pool_size = 0;
        std::map<uint32_t, uint32_t> free_list;            // offset in pool -> bytes
        std::deque<std::pair<uint32_t, Block>> retiring;   // frame it was retired, block
        bool failed = false;
        float failed_at = 0.0f;     // game_time of the failure
    } arena;

    uint32_t frame_counter = 0;

    void pool_release(uint32_t off, uint32_t bytes) {
        auto it = arena.free_list.emplace(off, bytes).first;
        auto next = std::next(it);
        if (next != arena.free_list.end() && it->first + it->second == next->first) {
            it->second += next->second;
            arena.free_list.erase(next);
        }
        if (it != arena.free_list.begin()) {
            auto prev = std::prev(it);
            if (prev->first + prev->second == it->first) {
                prev->second += it->second;
                arena.free_list.erase(it);
            }
        }
    }

    Block pool_alloc(uint32_t bytes) {
        bytes = (bytes + 15) & ~15u;
        for (auto it = arena.free_list.begin(); it != arena.free_list.end(); ++it) {
            if (it->second >= bytes) {
                const uint32_t off = it->first;
                const uint32_t left = it->second - bytes;
                arena.free_list.erase(it);
                if (left > 0) {
                    arena.free_list.emplace(off + bytes, left);
                }
                return { arena.pool + off, bytes };
            }
        }
        return {};
    }

    // Frees a block once RT64 can no longer be reading a frame that used it.
    void retire(Block& b) {
        if (b.addr != 0) {
            arena.retiring.emplace_back(frame_counter, b);
        }
        b = {};
    }

    void release_retired() {
        while (!arena.retiring.empty() && frame_counter - arena.retiring.front().first > frame_slots) {
            const Block b = arena.retiring.front().second;
            arena.retiring.pop_front();
            pool_release(b.addr - arena.pool, b.bytes);
        }
    }

    void make_texture_and_cubes(uint8_t* rdram);

    bool arena_ready(uint8_t* rdram, recomp_context* ctx) {
        if (arena.block != 0) {
            return true;
        }
        if (arena.failed) {
            // The heap changes as the map's objects come and go: ask again now and then.
            if (game_time - arena.failed_at < arena_retry_seconds) return false;
            arena.failed = false;
        }
        uint32_t largest = 0;
        {
            GameCall call(rdram, ctx);
            write_word(rdram, call.scratch, 0);
            call(heap_largest_free, call.scratch);
            largest = read_word(rdram, call.scratch);
        }
        uint32_t want = arena_want;
        if (largest < want + heap_margin) {
            want = largest > heap_margin ? largest - heap_margin : 0;
        }
        if (want < arena_least) {
            fprintf(stderr, "[voxels] not enough game heap for the voxel layer: %u bytes free in one piece\n", largest);
            arena.failed = true;
            arena.failed_at = game_time;
            return false;
        }
        uint32_t block = 0;
        {
            GameCall call(rdram, ctx);
            block = (uint32_t)call(heap_alloc, want);
        }
        if (!valid_ptr(block)) {
            arena.failed = true;
            arena.failed_at = game_time;
            return false;
        }
        arena.block = block;
        arena.map = tooie::debug::current_map(rdram);
        arena.base = (block + 63) & ~63u;
        arena.size = want - (arena.base - block);
        arena.frames = arena.base;
        arena.texture = arena.frames + frame_slots * frame_slot_bytes;
        arena.cubes = arena.texture + 2 * texture_bytes;
        arena.floor_tris = arena.cubes + MatCount * cube_block_bytes;
        arena.level_tex = (arena.floor_tris + floor_tri_slots * floor_tri_bytes + 63) & ~63u;
        arena.pool = (arena.level_tex + level_tex_slots * level_tex_bytes + 63) & ~63u;
        arena.pool_size = arena.base + arena.size - arena.pool;
        arena.free_list.clear();
        arena.free_list.emplace(0, arena.pool_size);
        arena.retiring.clear();
        make_texture_and_cubes(rdram);
        fprintf(stderr, "[voxels] arena %08X, %u KB (%u KB for meshes)\n", arena.base, arena.size / 1024, arena.pool_size / 1024);
        return true;
    }

    // ---------------------------------------------------------------------------------------------------------------
    // Display list writing

    constexpr uint32_t op_vtx = 0x01000000;
    constexpr uint32_t op_tri2 = 0x06000000;
    constexpr uint32_t op_dl = 0xDE000000;
    constexpr uint32_t op_enddl = 0xDF000000;
    constexpr uint32_t op_mtx_modelview_load = 0xDA380003;
    constexpr uint32_t op_pipesync = 0xE7000000;
    // RT64's extended GBI (lib/rt64/include/rt64_extended_gbi.h), as model_tagging.cpp writes it.
    constexpr uint32_t rt64_hook_word0 = 0xE0000000 | 0x525464;
    constexpr uint32_t rt64_enable_word1 = (1u << 28) | 0x64;
    constexpr uint32_t ex_matrix_group = (0x64u << 24) | 0x0C;
    constexpr uint32_t component_interpolate = 1, component_auto = 2, component_skip = 0;
    uint32_t group_params(uint32_t mode, uint32_t c) {
        return (mode << 2) | (c << 3) | (c << 5) | (c << 7) | (c << 9) | (c << 11) | (component_skip << 13) |
            (component_auto << 15) | (0u << 17) | (component_skip << 22) | (component_auto << 24);
    }

    uint32_t phys(uint32_t addr) {
        return addr & 0x1FFFFFFF;
    }

    struct Writer {
        uint8_t* rdram;
        uint32_t at;
        uint32_t end;
        bool full = false;
        bool put(uint32_t w0, uint32_t w1) {
            if (at + 8 > end) {
                full = true;
                return false;
            }
            write_word(rdram, at, w0);
            write_word(rdram, at + 4, w1);
            at += 8;
            return true;
        }
    };

    // One vertex: x, y, z, flag, s, t (S10.5), r, g, b, a.
    void put_vertex(uint8_t* rdram, uint32_t at, int x, int y, int z, int s, int t, uint8_t r, uint8_t g, uint8_t b) {
        write_word(rdram, at + 0, ((uint32_t)(uint16_t)(int16_t)x << 16) | (uint16_t)(int16_t)y);
        write_word(rdram, at + 4, (uint32_t)(uint16_t)(int16_t)z << 16);
        write_word(rdram, at + 8, ((uint32_t)(uint16_t)(int16_t)s << 16) | (uint16_t)(int16_t)t);
        write_word(rdram, at + 12, ((uint32_t)r << 24) | ((uint32_t)g << 16) | ((uint32_t)b << 8) | 0xFF);
    }

    uint32_t tri(int a, int b, int c) {
        return ((uint32_t)(a * 2) << 16) | ((uint32_t)(b * 2) << 8) | (uint32_t)(c * 2);
    }

    // An N64 matrix (s15.16, integer halves then fraction halves) from a row-vector 4x4.
    void write_matrix(uint8_t* rdram, uint32_t at, const float m[4][4]) {
        uint32_t ints[16], fracs[16];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                const float v = std::clamp(m[i][j], -32767.0f, 32767.0f);
                const int32_t fx = (int32_t)std::lround((double)v * 65536.0);
                ints[i * 4 + j] = ((uint32_t)fx >> 16) & 0xFFFF;
                fracs[i * 4 + j] = (uint32_t)fx & 0xFFFF;
            }
        }
        for (int w = 0; w < 8; w++) {
            write_word(rdram, at + 4 * w, (ints[2 * w] << 16) | ints[2 * w + 1]);
            write_word(rdram, at + 32 + 4 * w, (fracs[2 * w] << 16) | fracs[2 * w + 1]);
        }
    }

    bool flip_winding = false;

    uint8_t shade_byte(float v) {
        return (uint8_t)std::clamp((int)std::lround(v), 0, 255);
    }

    // The cell's colour on a face before ambient occlusion: its material mixed with the colour of the level's surface
    // over its column (most of it near the surface and in a pile, about half deeper, a little in a seam, so the inside
    // of a green mountain is green with some dirt in it), a jitter of its own, cracks, wetness.
    // The colour and texture slot of the level's surface over a cell's column, or the last one found (Arena::has_look).
    bool column_look(int code, int x, int y, int z, float tint[3], int* slot) {
        auto col = world.columns.find(column_key(code, x, y, z));
        if (col != world.columns.end() && col->second.tinted) {
            for (int c = 0; c < 3; c++) tint[c] = col->second.tint[c];
            *slot = col->second.tex;
            return true;
        }
        // A column no ask covered (a wall cell filled in from beside the blow) takes the look of the nearest column the
        // same way round that has one. The last look found was often the floor's, and a wall hole's bottom edge showed
        // a bright tan strip of floor colour (2026-11-15).
        {
            const int a = dir_axis(code);
            for (int r = 1; r <= 4; r++) {
                for (int du = -r; du <= r; du++) for (int dv = -r; dv <= r; dv++) {
                    if (std::max(std::abs(du), std::abs(dv)) != r) continue;
                    int cell[3] = { x, y, z };
                    cell[(a + 1) % 3] += du;
                    cell[(a + 2) % 3] += dv;
                    auto near = world.columns.find(column_key(code, cell[0], cell[1], cell[2]));
                    if (near == world.columns.end() || !near->second.tinted) continue;
                    for (int c = 0; c < 3; c++) tint[c] = near->second.tint[c];
                    *slot = near->second.tex;
                    return true;
                }
            }
        }
        if (!arena.has_look) return false;
        for (int c = 0; c < 3; c++) tint[c] = arena.look_tint[c];
        *slot = arena.look_slot;
        return true;
    }

    void cell_colour(const Chunk& c, int i, int x, int y, int z, float out[3]) {
        const MatInfo& m = mats[c.mat[i]];
        float base[3] = { (float)m.r, (float)m.g, (float)m.b };
        auto col = world.columns.find(column_key(c.dir[i], x, y, z));
        float tint[3];
        int tint_slot = 0;
        if (column_look(c.dir[i], x, y, z, tint, &tint_slot)) {
            const int a = dir_axis(c.dir[i]), sgn = dir_sign(c.dir[i]);
            const int cell[3] = { x, y, z };
            const float middle = (cell[a] + 0.5f) * vs;
            const float surface = col != world.columns.end() ? col->second.surface : middle;
            const float behind = sgn > 0 ? surface - middle : middle - surface;
            const bool vein = c.mat[i] == palette_for(current_map).vein && c.mat[i] != palette_for(current_map).top &&
                c.mat[i] != palette_for(current_map).base;
            const bool wall = dir_axis(c.dir[i]) != 1;
            float share = (behind < vs * 2.0f || (c.flags[i] & cell_piled)) ? (wall ? 1.0f : 0.85f) : (wall ? 0.85f : 0.55f);
            if (vein) share = 0.2f;
            for (int k = 0; k < 3; k++) base[k] = base[k] * (1.0f - share) + tint[k] * 255.0f * share;
        }
        float k = 1.0f + m.jitter * (2.0f * unit(hash3((uint32_t)x * 131u, (uint32_t)y, (uint32_t)z)) - 1.0f);
        if (m.health > 0 && c.dmg[i] > 0) {
            // Cracks: a damaged cell darkens, unevenly.
            const float d = std::min(1.0f, c.dmg[i] / (float)m.health);
            k *= 1.0f - d * (0.3f + 0.3f * unit(hash3((uint32_t)x, (uint32_t)y * 7u + (uint32_t)z, 99u)));
        }
        if (c.state[i] == Bedrock) k *= 0.8f;
        if (c.flags[i] & cell_wet) k *= 0.68f;
        out[0] = base[0] * k;
        out[1] = base[1] * k;
        out[2] = base[2] * k;
    }

    struct Quad {
        int16_t v[4][3];
        int16_t st[4][2];
        uint8_t col[4][3];
        bool flip;
        bool cracked;
        uint8_t slot = 0;   // the level texture (0: the grain)
    };

    // The colour a cell shows (cell_colour), or none for a cell not loaded.
    bool colour_at(int x, int y, int z, float out[3]) {
        const Chunk* c = chunk_at(x, y, z, false);
        if (c == nullptr) return false;
        const int i = local_index(*c, x, y, z);
        if (!solid_state(c->state[i])) return false;
        cell_colour(*c, i, x, y, z, out);
        return true;
    }

    // Builds the chunk's mesh into a new arena block (the old one retires). False when the arena is full.
    //
    // Smooth, not cubes (L, 2026-11-13: "smooth, not Minecraft squares"): Surface Nets over the
    // cells' centres. Each 2x2x2 group of cells has one vertex, the mean of the points where its edges cross from solid
    // to open; each face between a shown solid cell and an open one is a quad through the four vertices round it. An
    // edge from a solid cell to open air along its column crosses at the level's own surface there (the column's
    // surface), so a dent's rim lies on the old ground and meets the level's surface, and the untouched ground beside a
    // hole keeps its height; other crossings are half way. The normal is the solid cells' slope, the ambient occlusion
    // how many of the eight are solid, and the grain is laid along the face's main direction.
    // A texture coordinate (s10.5) for a world position: texels from the chunk's corner, plus where that corner falls in
    // the 32-texel texture, so neighbouring chunks meet without a seam and the numbers stay far inside their range.
    static int16_t tex_coord(float p, float corner, float scale, int offset) {
        const float at = corner * scale;
        const float wrap = at - 32.0f * std::floor(at / 32.0f);
        return (int16_t)std::lround(((p - corner) * scale + wrap + (float)offset) * 32.0f);
    }

    bool build_mesh(uint8_t* rdram, Chunk& ch) {
        std::vector<Quad> quads;
        const int ox = ch.cx * chunk_n, oy = ch.cy * chunk_n, oz = ch.cz * chunk_n;
        // The chunk's vertices are a cell in from its matrix's corner (draw_frame), so positions are local + 1 cell.
        const float base[3] = { (ox - 1) * vs, (oy - 1) * vs, (oz - 1) * vs };
        auto solid = [&](int x, int y, int z) { return solid_state(state_at(x, y, z)); };

        // The point where the edge from cell a (solid) to cell b (open) crosses, in world units.
        auto crossing = [&](const int a[3], const int b[3], float out[3]) {
            for (int c = 0; c < 3; c++) out[c] = (a[c] + b[c] + 1) * 0.5f * vs;
            int k = 0;
            for (int c = 0; c < 3; c++) if (a[c] != b[c]) k = c;
            const Chunk* ca = chunk_at(a[0], a[1], a[2], false);
            if (ca == nullptr || state_at(b[0], b[1], b[2]) != Air) return;
            const int ia = local_index(*ca, a[0], a[1], a[2]);
            if (dir_axis(ca->dir[ia]) != k || (ca->flags[ia] & cell_piled)) return;
            const float lo = std::min(a[k], b[k]) * vs + vs * 0.5f, hi = lo + vs;
            out[k] = std::clamp(ca->surface[ia], lo, hi);
        };

        // One vertex a 2x2x2 group (by its lowest cell), with its normal, occlusion and colour, kept as they are met.
        struct DualVertex { float p[3]; float n[3]; float ao; float col[3]; bool ok; };
        std::unordered_map<uint64_t, DualVertex> duals;
        auto dual = [&](int mx, int my, int mz) -> const DualVertex& {
            const uint64_t key = pack3(mx, my, mz);
            auto it = duals.find(key);
            if (it != duals.end()) return it->second;
            DualVertex d{};
            bool s[2][2][2];
            int solids = 0;
            for (int dz = 0; dz < 2; dz++) for (int dy = 0; dy < 2; dy++) for (int dx = 0; dx < 2; dx++) {
                s[dx][dy][dz] = solid(mx + dx, my + dy, mz + dz);
                solids += s[dx][dy][dz];
            }
            float sum[3] = { 0, 0, 0 };
            int crossings = 0;
            // The twelve edges: along x, y and z, at the four places across each.
            for (int axis = 0; axis < 3; axis++) {
                for (int u = 0; u < 2; u++) for (int v = 0; v < 2; v++) {
                    int a[3], b[3];
                    a[axis] = 0; b[axis] = 1;
                    a[(axis + 1) % 3] = b[(axis + 1) % 3] = u;
                    a[(axis + 2) % 3] = b[(axis + 2) % 3] = v;
                    const bool sa = s[a[0]][a[1]][a[2]], sb = s[b[0]][b[1]][b[2]];
                    if (sa == sb) continue;
                    int ca[3] = { mx + a[0], my + a[1], mz + a[2] }, cb[3] = { mx + b[0], my + b[1], mz + b[2] };
                    float pt[3];
                    if (sa) crossing(ca, cb, pt); else crossing(cb, ca, pt);
                    for (int c = 0; c < 3; c++) sum[c] += pt[c];
                    crossings++;
                }
            }
            if (crossings == 0) {
                for (int c = 0; c < 3; c++) d.p[c] = (c == 0 ? mx : c == 1 ? my : mz) * vs + vs;
            }
            else {
                for (int c = 0; c < 3; c++) d.p[c] = sum[c] / crossings;
            }
            // The outer top edge of a pile (one or two piled cells, all in the lower layer of the group) comes down most
            // of a cell, so the lip slopes away to the ground instead of standing up with a straight side.
            {
                int piled = 0, upper = 0;
                for (int dz = 0; dz < 2; dz++) for (int dy = 0; dy < 2; dy++) for (int dx = 0; dx < 2; dx++) {
                    if (!s[dx][dy][dz]) continue;
                    if (dy == 1) upper++;
                    const Chunk* pc = chunk_at(mx + dx, my + dy, mz + dz, false);
                    if (pc != nullptr && (pc->flags[local_index(*pc, mx + dx, my + dy, mz + dz)] & cell_piled)) piled++;
                }
                if (solids > 0 && solids <= 2 && piled == solids && upper == 0) d.p[1] -= vs * 0.45f;
            }
            // The slope of the solid cells: the normal points to the open side.
            float g[3] = { 0, 0, 0 };
            for (int dz = 0; dz < 2; dz++) for (int dy = 0; dy < 2; dy++) for (int dx = 0; dx < 2; dx++) {
                const float w = s[dx][dy][dz] ? 1.0f : 0.0f;
                g[0] += dx ? w : -w;
                g[1] += dy ? w : -w;
                g[2] += dz ? w : -w;
            }
            const float gl = length3(g);
            for (int c = 0; c < 3; c++) d.n[c] = gl > 1e-4f ? -g[c] / gl : (c == 1 ? 1.0f : 0.0f);
            d.ao = std::clamp(1.0f - 0.09f * (float)(solids - 4), 0.6f, 1.0f);
            // Its colour: the solid cells' own, mixed.
            int coloured = 0;
            for (int dz = 0; dz < 2; dz++) for (int dy = 0; dy < 2; dy++) for (int dx = 0; dx < 2; dx++) {
                float cc[3];
                if (s[dx][dy][dz] && colour_at(mx + dx, my + dy, mz + dz, cc)) {
                    for (int c = 0; c < 3; c++) d.col[c] += cc[c];
                    coloured++;
                }
            }
            for (int c = 0; c < 3; c++) d.col[c] = coloured > 0 ? d.col[c] / coloured : 128.0f;
            d.ok = true;
            return duals.emplace(key, d).first->second;
        };

        // The sun's direction for the shading (from above, a little to the side).
        const float light[3] = { 0.36f, 0.83f, 0.42f };
        ch.shown = 0;
        for (int lz = 0; lz < chunk_n; lz++) for (int ly = 0; ly < chunk_n; ly++) for (int lx = 0; lx < chunk_n; lx++) {
            const int i = Chunk::index(lx, ly, lz);
            if (!solid_state(ch.state[i])) continue;
            const int x = ox + lx, y = oy + ly, z = oz + lz;
            // A whole cell touching a dug cell only at an edge or a corner isn't shown, but the level's cut blends across
            // the cells round a point and can take its surface away: it draws its face to the surface alone. Without
            // it the level showed through under a wall hole's floor, a tan strip of the sand behind Jinjo Village's
            // cliff (2026-11-15).
            bool rim_only = false;
            if (!shown(x, y, z)) {
                if (!near_dug(x, y, z)) continue;
                rim_only = true;
            }
            else ch.shown++;
            const bool cracked_cell = ch.dmg[i] > 0;
            const bool piled_cell = (ch.flags[i] & cell_piled) != 0;
            int cell_slot = 0;
            float seam_dark = 1.0f;
            {
                const Palette pal_here = palette_for(current_map);
                const bool seam = ch.mat[i] == pal_here.vein && ch.mat[i] != pal_here.top && ch.mat[i] != pal_here.base;
                float tint[3];
                int slot_here = 0;
                // A seam stays stone (the map's stone colour on the grain): L likes the bits of stone in a mountain's hole
                // (2026-11-13).
                if (!seam && column_look(ch.dir[i], x, y, z, tint, &slot_here)) cell_slot = slot_here;
                // A rim-only cell shows through the cut of the dug cell beside it, so it takes that cell's look: a floor
                // cell under a wall hole showed in the floor's dirt colour, a tan bit under the hole (2026-11-15).
                if (rim_only) {
                    for (int dz = -1; dz <= 1; dz++) for (int dy = -1; dy <= 1; dy++) for (int dx = -1; dx <= 1; dx++) {
                        const Chunk* dc = chunk_at(x + dx, y + dy, z + dz, false);
                        if (dc == nullptr) continue;
                        const int di = local_index(*dc, x + dx, y + dy, z + dz);
                        if (dc->state[di] != Dug || dc->dir[di] == ch.dir[i]) continue;
                        if (column_look(dc->dir[di], x + dx, y + dy, z + dz, tint, &slot_here)) cell_slot = slot_here;
                        dz = dy = dx = 2;   // the first one found
                    }
                }
            }
            const uint32_t uv_off = hash3(ch.mat[i], 3, 5) & 15;
            static constexpr int n6[6][3] = { { 1, 0, 0 }, { -1, 0, 0 }, { 0, 1, 0 }, { 0, -1, 0 }, { 0, 0, 1 }, { 0, 0, -1 } };
            for (const auto& d : n6) {
                // Toward a dug cell always; toward open air for a piled cell, and otherwise only on the face to the
                // level's surface (its column's way out): where that surface is cut away this face stands in for it. The
                // other faces to open air stuck out through the level's surface as thin slivers.
                const uint8_t nb = state_at(x + d[0], y + d[1], z + d[2]);
                const bool surface_face = d[dir_axis(ch.dir[i])] == dir_sign(ch.dir[i]);
                if (rim_only && !surface_face) continue;
                // Every shown cell draws its face to the surface too, a little behind the level's surface (below): where
                // the level's wall stays it hides the face; where the wall's cut reaches past the hole's own faces (a
                // sloped wall, under a hole's floor) the face fills the gap, which showed the ground behind the wall as
                // a tan strip along a hole's bottom edge (2026-11-15).
                // (The cell in front of the surface is often never filled in, Unknown, rather than Air.)
                if (nb != Dug && !((nb == Air && piled_cell) || ((nb == Air || nb == Unknown) && surface_face))) continue;
                int k = 0;
                for (int c = 0; c < 3; c++) if (d[c] != 0) k = c;
                const int i1 = (k + 1) % 3, i2 = (k + 2) % 3;
                // The four groups round the edge from this cell to the open one, in a loop.
                const int cell[3] = { x, y, z };
                const int lowk = std::min(cell[k], cell[k] + d[k]);
                constexpr int loop[4][2] = { { -1, -1 }, { 0, -1 }, { 0, 0 }, { -1, 0 } };
                const DualVertex* v[4];
                for (int q = 0; q < 4; q++) {
                    int m[3];
                    m[k] = lowk;
                    m[i1] = cell[i1] + loop[q][0];
                    m[i2] = cell[i2] + loop[q][1];
                    v[q] = &dual(m[0], m[1], m[2]);
                }
                // Facing the open cell: the loop's turn checked against the edge's direction.
                const float e1[3] = { v[1]->p[0] - v[0]->p[0], v[1]->p[1] - v[0]->p[1], v[1]->p[2] - v[0]->p[2] };
                const float e2[3] = { v[3]->p[0] - v[0]->p[0], v[3]->p[1] - v[0]->p[1], v[3]->p[2] - v[0]->p[2] };
                const float cr[3] = { e1[1] * e2[2] - e1[2] * e2[1], e1[2] * e2[0] - e1[0] * e2[2], e1[0] * e2[1] - e1[1] * e2[0] };
                const bool reverse = cr[0] * d[0] + cr[1] * d[1] + cr[2] * d[2] < 0.0f;
                // The grain along the face's main direction.
                const int ua = (k + 1) % 3, ub = (k + 2) % 3;
                Quad qd{};
                for (int q = 0; q < 4; q++) {
                    const DualVertex& dv = *v[reverse ? (4 - q) % 4 : q];
                    // Never in front of the level's surface over the cell's column (a piled cell is on top of it):
                    // a corner mixed from the crossings round a curved wall stuck out of it as a spike (2026-11-15).
                    float at[3] = { dv.p[0], dv.p[1], dv.p[2] };
                    if (!piled_cell) {
                        // (Four units behind it, so the level's own surface wins where it is kept: at one unit, faces
                        // showed through a curved wall between the columns as thin lines. Not much more: Jinjo
                        // Village's cliff has a tan layer a few units behind its surface, and at eight it showed in front.)
                        const int sa = dir_axis(ch.dir[i]);
                        const float back = 4.0f;
                        if (dir_sign(ch.dir[i]) > 0) at[sa] = std::min(at[sa], ch.surface[i] - back);
                        else at[sa] = std::max(at[sa], ch.surface[i] + back);
                    }
                    for (int c = 0; c < 3; c++) qd.v[q][c] = (int16_t)std::lround(at[c] - base[c]);
                    const float lit = 0.5f + 0.5f * std::max(0.0f, dv.n[0] * light[0] + dv.n[1] * light[1] + dv.n[2] * light[2]);
                    // Darker the deeper the corner is behind the level's surface over the cell's column, to 40% three
                    // cells in. Lit like the level round it, a hole in a wall read as a flat patch stuck on the wall (L,
                    // 2026-11-15). A piled cell sits on the surface and keeps the full light.
                    const int col_a = dir_axis(ch.dir[i]);
                    const float depth = piled_cell ? 0.0f
                        : (dir_sign(ch.dir[i]) > 0 ? ch.surface[i] - dv.p[col_a] : dv.p[col_a] - ch.surface[i]);
                    const float deep = std::clamp(1.0f - 0.2f * std::max(0.0f, depth) / vs, 0.4f, 1.0f);
                    const float level = lit * dv.ao * deep;
                    // A face with the level's texture takes only the light (the texture has the colour).
                    if (cell_slot > 0) for (int c = 0; c < 3; c++) qd.col[q][c] = shade_byte(235.0f * level * seam_dark);
                    else for (int c = 0; c < 3; c++) qd.col[q][c] = shade_byte(dv.col[c] * level);
                    const float scale = cell_slot > 0 ? arena.tex_scale[cell_slot] : 16.0f / vs;
                    qd.st[q][0] = tex_coord(dv.p[ua], base[ua], scale, cell_slot > 0 ? 0 : (int)uv_off);
                    qd.st[q][1] = tex_coord(dv.p[ub], base[ub], scale, cell_slot > 0 ? 0 : (int)uv_off * 3);
                }
                qd.flip = false;
                // A cracked cell with a level texture shows that texture's cracked copy, among the textured faces.
                qd.cracked = cracked_cell && cell_slot == 0;
                qd.slot = (uint8_t)(cell_slot > 0 ? cell_slot + (cracked_cell ? (int)level_tex_cracked : 0) : 0);
                quads.push_back(qd);
            }
        }
        // A backstop against seeing into the empty inside of the world (L, 2026-11-13): where a dug cell meets a cell
        // counted as open air, a dark face on their shared side, turned toward the dug cell. Seen through the hole's
        // mouth it faces away and is culled, so the hole stays open; where the open-air cell is behind the level's
        // surface (a sloped wall the column tests missed), it faces the viewer and fills what would be empty.
        const Palette pal = palette_for(current_map);
        for (int lz = 0; lz < chunk_n; lz++) for (int ly = 0; ly < chunk_n; ly++) for (int lx = 0; lx < chunk_n; lx++) {
            const int i = Chunk::index(lx, ly, lz);
            if (ch.state[i] != Dug) continue;
            const int x = ox + lx, y = oy + ly, z = oz + lz;
            static constexpr int n6b[6][3] = { { 1, 0, 0 }, { -1, 0, 0 }, { 0, 1, 0 }, { 0, -1, 0 }, { 0, 0, 1 }, { 0, 0, -1 } };
            const int col_axis = dir_axis(ch.dir[i]), col_sign = dir_sign(ch.dir[i]);
            for (const auto& d : n6b) {
                // Open air, or a cell never filled in (Unknown): nothing is drawn there either, and where the wall's cut
                // reached over one the level behind the wall showed through, a tan sliver of Jinjo Village's sand at a
                // wall hole's corner (2026-11-15).
                const uint8_t nb_state = state_at(x + d[0], y + d[1], z + d[2]);
                if (nb_state != Air && nb_state != Unknown) continue;
                int k = 0;
                for (int c = 0; c < 3; c++) if (d[c] != 0) k = c;
                // Not across the hole's mouth (the way out of the column): from inside the hole it would wall him in.
                if (k == col_axis && d[k] == col_sign) continue;
                const int i1 = (k + 1) % 3, i2 = (k + 2) % 3;
                // The shared side's corners, in a loop, then turned to face the dug cell (against d).
                const float side = (d[k] > 0 ? (float)((k == 0 ? x : k == 1 ? y : z) + 1) : (float)(k == 0 ? x : k == 1 ? y : z)) * vs;
                const float lo1 = (float)(i1 == 0 ? x : i1 == 1 ? y : z) * vs, lo2 = (float)(i2 == 0 ? x : i2 == 1 ? y : z) * vs;
                constexpr int loop[4][2] = { { 0, 0 }, { 1, 0 }, { 1, 1 }, { 0, 1 } };
                float pts[4][3];
                for (int q = 0; q < 4; q++) {
                    pts[q][k] = side;
                    pts[q][i1] = lo1 + loop[q][0] * vs;
                    pts[q][i2] = lo2 + loop[q][1] * vs;
                }
                // Only the part behind the level's surface: a whole cell's side reached out in front of a wall, a thin
                // plate seen edge on as a line across it (L, 2026-11-13).
                if (k != col_axis) {
                    const float surf = ch.surface[i];
                    bool any = false;
                    for (int q = 0; q < 4; q++) {
                        pts[q][col_axis] = col_sign > 0 ? std::min(pts[q][col_axis], surf) : std::max(pts[q][col_axis], surf);
                    }
                    for (int q = 1; q < 4; q++) any = any || std::fabs(pts[q][col_axis] - pts[0][col_axis]) > 0.5f;
                    if (!any) continue;
                }
                const float e1[3] = { pts[1][0] - pts[0][0], pts[1][1] - pts[0][1], pts[1][2] - pts[0][2] };
                const float e2[3] = { pts[3][0] - pts[0][0], pts[3][1] - pts[0][1], pts[3][2] - pts[0][2] };
                const float cr[3] = { e1[1] * e2[2] - e1[2] * e2[1], e1[2] * e2[0] - e1[0] * e2[2], e1[0] * e2[1] - e1[1] * e2[0] };
                const bool reverse = cr[0] * d[0] + cr[1] * d[1] + cr[2] * d[2] > 0.0f;
                // In the dug cell's own texture and colour, a little in shadow (it was a dark grey patch, which read as
                // a hole in the picture).
                const MatInfo& m = mats[pal.base];
                int back_slot = 0;
                float back_col[3] = { (float)m.r, (float)m.g, (float)m.b };
                {
                    float tint[3];
                    if (column_look(ch.dir[i], x, y, z, tint, &back_slot)) for (int c = 0; c < 3; c++) back_col[c] = tint[c] * 255.0f;
                }
                const uint32_t uv_off = hash3(pal.base, 3, 5) & 15;
                const int ua = (k + 1) % 3, ub = (k + 2) % 3;
                const float scale = back_slot > 0 ? arena.tex_scale[back_slot] : 16.0f / vs;
                Quad qd{};
                for (int q = 0; q < 4; q++) {
                    const float* pt = pts[reverse ? (4 - q) % 4 : q];
                    for (int c = 0; c < 3; c++) qd.v[q][c] = (int16_t)std::lround(pt[c] - base[c]);
                    for (int c = 0; c < 3; c++) qd.col[q][c] = shade_byte((back_slot > 0 ? 235.0f : back_col[c]) * 0.6f);
                    qd.st[q][0] = tex_coord(pt[ua], base[ua], scale, back_slot > 0 ? 0 : (int)uv_off);
                    qd.st[q][1] = tex_coord(pt[ub], base[ub], scale, back_slot > 0 ? 0 : (int)uv_off * 3);
                }
                qd.flip = false;
                qd.cracked = false;
                qd.slot = (uint8_t)back_slot;
                quads.push_back(qd);
            }
        }
        // (Test aid, TOOIE_VOXEL_RED=1: every face plain red, untextured, to tell the layer's faces from the level's.)
        static const bool red = std::getenv("TOOIE_VOXEL_RED") != nullptr;
        if (red) for (Quad& q : quads) {
            q.slot = 0;
            q.cracked = false;
            for (auto& c : q.col) { c[0] = 255; c[1] = 0; c[2] = 0; }
        }
        if (quads.empty()) {
            retire(ch.mesh);
            ch.mesh_dl = 0;
            ch.crack_dl = 0;
            ch.dirty = false;
            return true;
        }
        // The plain faces first, then the cracked ones: two lists, each ending in its own G_ENDDL.
        std::stable_partition(quads.begin(), quads.end(), [](const Quad& q) { return !q.cracked; });
        const size_t plain = (size_t)(std::find_if(quads.begin(), quads.end(), [](const Quad& q) { return q.cracked; }) - quads.begin());
        std::stable_sort(quads.begin(), quads.begin() + plain, [](const Quad& a, const Quad& b) { return a.slot < b.slot; });
        size_t groups = 0;
        for (size_t q = 0; q < plain; q++) if (q == 0 || quads[q].slot != quads[q - 1].slot) groups++;
        // A batch can end at each group's end; each group has its texture's load (8 commands).
        const uint32_t batches = (uint32_t)((plain + 7) / 8 + groups + (quads.size() - plain + 7) / 8);
        const uint32_t cmd_bytes = (batches + (uint32_t)quads.size() + 2 + 8 * (uint32_t)groups) * 8;
        const uint32_t vtx_bytes = (uint32_t)quads.size() * 4 * 16;
        Block b = pool_alloc(cmd_bytes + vtx_bytes);
        if (b.addr == 0) {
            // The old mesh stays until there is room (better than the level cut away with nothing in the hole).
            if (log_on()) fprintf(stderr, "[voxels] arena full: a chunk keeps its old mesh\n");
            ch.dirty = true;
            return false;
        }
        retire(ch.mesh);
        ch.mesh_dl = 0;
        ch.crack_dl = 0;
        ch.dirty = false;
        uint32_t cmd = b.addr;
        const uint32_t verts = b.addr + cmd_bytes;
        // The texture for a group of faces into tile 0: the grain (32 x 32 I8) or a level texture (32 x 32 RGBA16).
        auto load_texture = [&](int slot) {
            auto put = [&](uint32_t w0, uint32_t w1) { write_word(rdram, cmd, w0); write_word(rdram, cmd + 4, w1); cmd += 8; };
            put(op_pipesync, 0);
            if (slot == 0) {
                put(0xFD900000, phys(arena.texture));
                put(0xF5900000, 0x07000000);
                put(0xE6000000, 0);
                put(0xF3000000, 0x071FF200);
                put(op_pipesync, 0);
                put(0xF5880800, (5u << 14) | (5u << 4));
                put(0xF2000000, 0x0007C07C);
            }
            else {
                put(0xFD100000, phys(arena.level_tex + (uint32_t)slot * level_tex_bytes));
                put(0xF5100000, 0x07000000);
                put(0xE6000000, 0);
                put(0xF3000000, 0x073FF100);
                put(op_pipesync, 0);
                put(0xF5101000, (5u << 14) | (5u << 4));
                put(0xF2000000, 0x0007C07C);
            }
        };
        auto write_list = [&](size_t from, size_t to, bool textured) {
        for (size_t q0 = from; q0 < to;) {
            if (textured && (q0 == from || quads[q0].slot != quads[q0 - 1].slot)) load_texture(quads[q0].slot);
            size_t group_end = to;
            if (textured) { group_end = q0; while (group_end < to && quads[group_end].slot == quads[q0].slot) group_end++; }
            const uint32_t count = (uint32_t)std::min<size_t>(8, group_end - q0);
            const uint32_t nv = count * 4;
            const uint32_t first = verts + (uint32_t)q0 * 64;
            for (uint32_t q = 0; q < count; q++) {
                const Quad& qd = quads[q0 + q];
                for (int c = 0; c < 4; c++) {
                    put_vertex(rdram, first + (q * 4 + c) * 16, qd.v[c][0], qd.v[c][1], qd.v[c][2], qd.st[c][0], qd.st[c][1],
                        qd.col[c][0], qd.col[c][1], qd.col[c][2]);
                }
            }
            write_word(rdram, cmd, op_vtx | (nv << 12) | (nv * 2));
            write_word(rdram, cmd + 4, phys(first));
            cmd += 8;
            for (uint32_t q = 0; q < count; q++) {
                const int v = (int)q * 4;
                int a0, a1, a2, b0, b1, b2;
                if (!quads[q0 + q].flip) { a0 = v; a1 = v + 1; a2 = v + 2; b0 = v; b1 = v + 2; b2 = v + 3; }
                else { a0 = v + 1; a1 = v + 2; a2 = v + 3; b0 = v + 1; b1 = v + 3; b2 = v; }
                if (flip_winding) { std::swap(a1, a2); std::swap(b1, b2); }
                write_word(rdram, cmd, op_tri2 | tri(a0, a1, a2));
                write_word(rdram, cmd + 4, tri(b0, b1, b2));
                cmd += 8;
            }
            q0 += count;
        }
        write_word(rdram, cmd, op_enddl);
        write_word(rdram, cmd + 4, 0);
        cmd += 8;
        };
        ch.mesh = b;
        if (plain > 0) {
            ch.mesh_dl = cmd;
            write_list(0, plain, true);
        }
        if (plain < quads.size()) {
            ch.crack_dl = cmd;
            write_list(plain, quads.size(), false);
        }
        return true;
    }

    // Each texel's share of light in the cracked texture (255 whole), for the level textures' cracked copies.
    uint8_t crack_shade[1024];

    // The grain texture (32 x 32 I8, soft value noise, ours) and one debris cube a material.
    void make_texture_and_cubes(uint8_t* rdram) {
        float cells[9][9];
        Rng rng(0xB10C5);
        for (auto& row : cells) for (float& c : row) c = rng.f();
        for (int y = 0; y < 32; y++) {
            for (int x = 0; x < 32; x++) {
                // Two octaves of value noise, wrapping at 32, plus speckle.
                auto sample = [&](int period, float fx, float fy) {
                    const int cells_n = 32 / period;
                    const int x0 = (int)fx % cells_n, y0 = (int)fy % cells_n;
                    const int x1 = (x0 + 1) % cells_n, y1 = (y0 + 1) % cells_n;
                    const float tx = fx - std::floor(fx), ty = fy - std::floor(fy);
                    const float sx = tx * tx * (3 - 2 * tx), sy = ty * ty * (3 - 2 * ty);
                    const float a = cells[y0][x0] + (cells[y0][x1] - cells[y0][x0]) * sx;
                    const float b = cells[y1][x0] + (cells[y1][x1] - cells[y1][x0]) * sx;
                    return a + (b - a) * sy;
                };
                float v = 0.6f * sample(8, x / 8.0f, y / 8.0f) + 0.4f * sample(4, x / 4.0f + 0.5f, y / 4.0f + 0.5f);
                v += 0.18f * (unit(hash3(x, y, 77)) - 0.5f);
                const int value = std::clamp((int)std::lround(196.0f + 59.0f * (v - 0.5f) * 2.0f), 120, 255);
                rdram[((arena.texture + y * 32 + x) ^ 3) - 0x80000000u] = (uint8_t)value;
            }
        }
        // The cracked texture (a cell hit once but not yet broken): the grain with cracks across it (random walks from a
        // few seeds, branching), so a dent reads as struck and about to give. The cracks darken the grain by a third
        // and their edge a little: near-black cracks on a white ground looked like they didn't belong on the stone
        // (L, 2026-11-15). crack_shade keeps each texel's share, for the level textures' cracked copies too.
        {
            uint8_t crack[32][32];
            for (int y = 0; y < 32; y++) for (int x = 0; x < 32; x++) crack[y][x] = 255;
            Rng cr(0xC4AC5);
            for (int line = 0; line < 5; line++) {
                float px = cr.range(0.0f, 32.0f), py = cr.range(0.0f, 32.0f);
                float ang = cr.range(0.0f, 2.0f * pi);
                const int steps = 18 + (int)(cr.f() * 16);
                for (int k = 0; k < steps; k++) {
                    const int ix = ((int)std::floor(px) % 32 + 32) % 32, iy = ((int)std::floor(py) % 32 + 32) % 32;
                    crack[iy][ix] = (uint8_t)(160 + cr.f() * 20);
                    // The crack's soft edge.
                    const int jx = (ix + 1) % 32;
                    crack[iy][jx] = (uint8_t)std::min<int>(crack[iy][jx], 215);
                    ang += cr.range(-0.6f, 0.6f);
                    px += std::cos(ang);
                    py += std::sin(ang);
                    if (cr.f() < 0.08f) ang += cr.f() < 0.5f ? 1.1f : -1.1f;   // a branch's turn
                }
            }
            for (int y = 0; y < 32; y++) for (int x = 0; x < 32; x++) {
                crack_shade[y * 32 + x] = crack[y][x];
                const uint8_t grain = rdram[((arena.texture + y * 32 + x) ^ 3) - 0x80000000u];
                rdram[((arena.texture + texture_bytes + y * 32 + x) ^ 3) - 0x80000000u] = (uint8_t)(grain * crack[y][x] / 255);
            }
        }
        // Stones (L, 2026-11-13: square debris ruined the illusion): an icosahedron of radius 50 round its middle, each
        // corner pushed in or out a little, shaded by its slope (light from above), in the material's colour; the
        // matrix scales and stretches each piece differently.
        static const float ico[12][3] = {
            { -1, 1.618f, 0 }, { 1, 1.618f, 0 }, { -1, -1.618f, 0 }, { 1, -1.618f, 0 },
            { 0, -1, 1.618f }, { 0, 1, 1.618f }, { 0, -1, -1.618f }, { 0, 1, -1.618f },
            { 1.618f, 0, -1 }, { 1.618f, 0, 1 }, { -1.618f, 0, -1 }, { -1.618f, 0, 1 },
        };
        static const int ico_tris[20][3] = {
            { 0, 11, 5 }, { 0, 5, 1 }, { 0, 1, 7 }, { 0, 7, 10 }, { 0, 10, 11 },
            { 1, 5, 9 }, { 5, 11, 4 }, { 11, 10, 2 }, { 10, 7, 6 }, { 7, 1, 8 },
            { 3, 9, 4 }, { 3, 4, 2 }, { 3, 2, 6 }, { 3, 6, 8 }, { 3, 8, 9 },
            { 4, 9, 5 }, { 2, 4, 11 }, { 6, 2, 10 }, { 8, 6, 7 }, { 9, 8, 1 },
        };
        for (int m = 1; m < MatCount; m++) {
            const uint32_t list = arena.cubes + m * cube_block_bytes;
            const uint32_t verts = list + 16 * 8;
            Writer w{ rdram, list, list + 16 * 8 };
            w.put(op_vtx | (12u << 12) | 24u, phys(verts));
            for (int v = 0; v < 12; v++) {
                const float len = std::sqrt(ico[v][0] * ico[v][0] + ico[v][1] * ico[v][1] + ico[v][2] * ico[v][2]);
                const float bump = 0.8f + 0.35f * unit(hash3((uint32_t)m, (uint32_t)v, 11u));
                const float n[3] = { ico[v][0] / len, ico[v][1] / len, ico[v][2] / len };
                const float shade = 0.6f + 0.4f * std::max(0.0f, n[1] * 0.8f + n[0] * 0.36f + n[2] * 0.42f);
                put_vertex(rdram, verts + v * 16, (int)std::lround(n[0] * 50 * bump), (int)std::lround(n[1] * 50 * bump),
                    (int)std::lround(n[2] * 50 * bump), 0, 0,
                    shade_byte(mats[m].r * shade), shade_byte(mats[m].g * shade), shade_byte(mats[m].b * shade));
            }
            for (int t = 0; t < 20; t += 2) {
                int a0 = ico_tris[t][0], a1 = ico_tris[t][1], a2 = ico_tris[t][2];
                int b0 = ico_tris[t + 1][0], b1 = ico_tris[t + 1][1], b2 = ico_tris[t + 1][2];
                if (flip_winding) { std::swap(a1, a2); std::swap(b1, b2); }
                w.put(op_tri2 | tri(a0, a1, a2), tri(b0, b1, b2));
            }
            w.put(op_enddl, 0);
        }
    }

    // ---------------------------------------------------------------------------------------------------------------
    // State

    bool was_on = false;
    uint32_t last_game_ms = 0;
    bool matrix_relative = false;  // modelview = place minus camera; the game's is the world place (see the top)
    // voxel void on (L, 2026-11-13: make the void easy to find): a bright magenta box round the camera, behind
    // everything drawn, so the sky and any gap a hole lets through show magenta, in the picture and in screenshots
    // (where its pixels can be counted).


    void drop_meshes() {
        for (auto& [key, c] : world.chunks) {
            retire(c->mesh);
            c->mesh_dl = 0;
            c->crack_dl = 0;
            c->dirty = true;
        }
    }

    // ---------------------------------------------------------------------------------------------------------------
    // Debris

    struct Debris {
        float pos[3], vel[3];
        float ang[2], spin[2];
        float size, life, age;
        float ground;
        uint8_t mat;
        uint32_t id;
    };
    std::vector<Debris> debris;
    constexpr size_t max_debris = 300;
    uint32_t debris_serial = 0;

    // A broken cell flies out of the surface (out_n) and away from the blow.
    void spawn_debris(const float at[3], const float blow[3], const float out_n[3], uint8_t mat, float ground, Rng& rng) {
        if (debris.size() >= max_debris) {
            debris.erase(debris.begin());
        }
        Debris d{};
        for (int c = 0; c < 3; c++) d.pos[c] = at[c];
        float away[3] = { at[0] - blow[0], 0.0f, at[2] - blow[2] };
        const float len = std::sqrt(away[0] * away[0] + away[2] * away[2]);
        if (len > 0.01f) { away[0] /= len; away[2] /= len; }
        const float speed = rng.range(120.0f, 320.0f);
        for (int c = 0; c < 3; c++) d.vel[c] = out_n[c] * speed * 0.8f + away[c] * speed * 0.5f + rng.range(-60.0f, 60.0f);
        d.vel[1] += rng.range(220.0f, 420.0f);
        d.ang[0] = rng.range(0, 360); d.ang[1] = rng.range(0, 360);
        d.spin[0] = rng.range(-540, 540); d.spin[1] = rng.range(-540, 540);
        d.size = vs * rng.range(0.45f, 0.75f);
        d.life = rng.range(1.1f, 1.8f);
        d.ground = ground;
        d.mat = mat;
        d.id = ++debris_serial;
        debris.push_back(d);
    }

    void step_debris(float dt) {
        for (Debris& d : debris) {
            d.age += dt;
            if (d.mat == Marker) continue;
            d.vel[1] -= 1300.0f * dt;
            for (int c = 0; c < 3; c++) d.pos[c] += d.vel[c] * dt;
            if (d.pos[1] - d.size * 0.5f < d.ground && d.vel[1] < 0.0f) {
                d.pos[1] = d.ground + d.size * 0.5f;
                d.vel[1] = -d.vel[1] * 0.3f;
                d.vel[0] *= 0.55f; d.vel[2] *= 0.55f;
                d.spin[0] *= 0.5f; d.spin[1] *= 0.5f;
            }
            d.ang[0] += d.spin[0] * dt;
            d.ang[1] += d.spin[1] * dt;
        }
        debris.erase(std::remove_if(debris.begin(), debris.end(), [](const Debris& d) { return d.age >= d.life; }), debris.end());
    }

    // ---------------------------------------------------------------------------------------------------------------
    // Breaking

    // Metal floors, by surface type (a collision triangle's flags & 0x1F00, >> 8): the game names none of them, so the
    // types are found by standing on metal (voxel surface) and set with voxel metal <type>. Walls carry no type of
    // their own (type 1, as plain ground: seen 2026-11-13 in Grunty Industries and Jinjo Village), so in Grunty
    // Industries, the metal factory, every wall counts as metal (metal_walls).
    uint32_t metal_types = 0;

    bool metal_walls() {
        return starts_with(map_name(current_map), "GI");
    }
    constexpr float water_keep_off = 300.0f;   // nothing breaks within this of water (L, 2026-11-13)
    constexpr float metal_keep_off = 100.0f;   // nor within this of metal

    bool is_metal(uint32_t flags) {
        return ((metal_types >> ((flags & surface_type_mask) >> 8)) & 1u) != 0;
    }

    // Whether a blow at `at` (on a surface facing `n`) is near water or metal, where nothing breaks: water surfaces
    // above or below it and round it within water_keep_off, and metal under it or round it within metal_keep_off
    // (short line tests into the surface beside it).
    bool protected_place(uint8_t* rdram, recomp_context* ctx, const float at[3], const float n[3], uint32_t flags) {
        if (is_metal(flags)) return true;
        if (metal_walls()) {
            // A wall here is metal; a floor is kept within metal_keep_off of one (four level rays across it).
            if (std::fabs(n[1]) < 0.7f) return true;
            constexpr float across[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
            for (const auto& d : across) {
                const float from[3] = { at[0], at[1] + 40.0f, at[2] };
                const float to[3] = { at[0] + d[0] * metal_keep_off, at[1] + 40.0f, at[2] + d[1] * metal_keep_off };
                float hit[3], hn[3];
                if (line_test(rdram, ctx, from, to, kind_solid, hit, hn, nullptr) && std::fabs(hn[1]) < 0.7f) return true;
            }
        }
        constexpr float ring[5][2] = { { 0, 0 }, { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        for (const auto& r : ring) {
            float wy;
            const float x = at[0] + r[0] * water_keep_off, z = at[2] + r[1] * water_keep_off;
            if (water_at(rdram, ctx, x, z, at[1] + water_keep_off, at[1] - water_keep_off, &wy)) return true;
        }
        if (metal_types == 0) return false;
        // Two directions along the surface (across its normal), and the probes beside the blow, into the surface.
        int a = 0;
        for (int c = 1; c < 3; c++) if (std::fabs(n[c]) > std::fabs(n[a])) a = c;
        const int t1 = (a + 1) % 3, t2 = (a + 2) % 3;
        for (int k = 1; k < 5; k++) {
            float from[3] = { at[0], at[1], at[2] }, to[3];
            from[t1] += ring[k][0] * metal_keep_off;
            from[t2] += ring[k][1] * metal_keep_off;
            for (int c = 0; c < 3; c++) {
                to[c] = from[c] - n[c] * 60.0f;
                from[c] += n[c] * 60.0f;
            }
            float hit[3], hn[3];
            uint32_t f = 0;
            if (line_test(rdram, ctx, from, to, kind_solid, hit, hn, &f) && is_metal(f)) return true;
        }
        return false;
    }

    struct Breaks {
        bool kept = false;  // near water or metal: nothing breaks
        int count = 0;      // cells broken
        int cracked = 0;    // cells hurt but not broken
        int clinks = 0;     // cells too hard for the blow
        float where[3] = {};
        Mat mat = Empty;
        bool reached = false;   // the blow met the level's surface or a shown cell
    };

    // The colour asked of RT64 for the columns blows have made: one ask at a time (RT64 keeps the last), so columns
    // made while one waits join it. It is answered within a frame or two; one not answered in 2 s is dropped.
    struct ColourAsk {
        uint32_t ticket = 0;
        std::vector<uint64_t> columns;
        float asked_at = 0.0f;
        int code = 0;   // the facing asked for
        std::vector<std::array<int, 3>> near;   // the cells struck (the chunks round them are rebuilt with the answer)
    } colour_ask;
    uint32_t colour_ticket = 0;
    float game_time_now();

    // code: the struck surface's facing (its columns' direction).
    void ask_colour(const float at[3], int code, const std::vector<uint64_t>& columns) {
        if (colour_ask.ticket == 0) colour_ask.ticket = ++colour_ticket;
        colour_ask.columns.insert(colour_ask.columns.end(), columns.begin(), columns.end());
        colour_ask.asked_at = game_time_now();
        colour_ask.code = code;
        colour_ask.near.push_back({ cell_of(at[0]), cell_of(at[1]), cell_of(at[2]) });
        float facing[3] = { 0.0f, 0.0f, 0.0f };
        facing[dir_axis(code)] = 1.0f;
        RT64::RequestSceneSurfaceColour(at, facing, colour_ask.ticket);
    }

    uint8_t* rdram_now = nullptr;   // the tick's rdram, for take_colour

    void take_colour() {
        if (colour_ask.ticket == 0) return;
        float rgb[3];
        uint64_t tex_hash = 0;
        float repeat = 0.0f;
        if (RT64::SceneSurfaceColour(colour_ask.ticket, rgb, &tex_hash, &repeat)) {
            // The texture into a slot of the arena (once a map), as the game's RGBA16 texels.
            int slot = 0;
            if (tex_hash != 0 && arena.level_tex != 0) {
                auto known = arena.tex_slot_of.find(tex_hash);
                if (known != arena.tex_slot_of.end()) slot = known->second;
                else if (arena.tex_slot_of.size() + 1 < level_tex_kinds) {
                    static uint16_t texels[1024];
                    if (RT64::SceneTextureRGBA16(tex_hash, texels)) {
                        slot = (int)arena.tex_slot_of.size() + 1;
                        const uint32_t at = arena.level_tex + (uint32_t)slot * level_tex_bytes;
                        for (int t = 0; t < 1024; t += 2) write_word(rdram_now, at + t * 2, ((uint32_t)texels[t] << 16) | texels[t + 1]);
                        // Its cracked copy: darkened along the cracks of the crack texture (I8 in the arena).
                        static uint16_t cracked[1024];
                        for (int t = 0; t < 1024; t++) {
                            const uint8_t crack = crack_shade[t];
                            const float f = crack / 255.0f;
                            const uint16_t c = texels[t];
                            auto dim = [&](int v) { return (uint16_t)std::clamp((int)std::lround(v * f), 0, 31); };
                            cracked[t] = (uint16_t)((dim((c >> 11) & 31) << 11) | (dim((c >> 6) & 31) << 6) | (dim((c >> 1) & 31) << 1) | (c & 1));
                        }
                        const uint32_t at_cracked = arena.level_tex + (uint32_t)(slot + level_tex_cracked) * level_tex_bytes;
                        for (int t = 0; t < 1024; t += 2) write_word(rdram_now, at_cracked + t * 2, ((uint32_t)cracked[t] << 16) | cracked[t + 1]);
                        arena.tex_slot_of.emplace(tex_hash, slot);
                        // 32 texels across the width it covers; a size out of reason falls back to a repeat every 8 cells.
                        const float width = (repeat > vs && repeat < 4000.0f) ? repeat : vs * 8.0f;
                        // (Drawn at the grain's density, 16 texels a cell, not the level's own size: L liked the denser look
                        // better, 2026-11-13. The size found is kept in the log.)
                        arena.tex_scale[slot] = 16.0f / vs;
                        if (log_on()) fprintf(stderr, "[voxels] level texture %016llX in slot %d, %.0f units across\n", (unsigned long long)tex_hash, slot, width);
                    }
                }
            }
            // A green floor is grass, and inside grass is dirt (L, 2026-11-13: "grass should always display dirt"): its
            // columns take the world's dirt instead. A green wall (a mountain) keeps its green, the floor and roof of a
            // hole in it too ("the mountain is green so the insides should reflect on that").
            const bool asked_floor = colour_ask.code == dir_code(1, 1);
            const bool green = rgb[1] > rgb[0] * 1.12f && rgb[1] > rgb[2] * 1.12f;
            const MatInfo& dirt = mats[soil(palette_for(current_map).base) ? palette_for(current_map).base : Dirt];
            for (uint64_t key : colour_ask.columns) {
                auto it = world.columns.find(key);
                if (it == world.columns.end()) continue;
                const bool floor = asked_floor && (key >> 58) == (uint64_t)dir_code(1, 1);
                it->second.tinted = true;
                // A floor's texture is never used, on the floor's columns or the wall columns its ask covered: they
                // take the grain in the floor's colour. At the grain's density one texel of a dirt path's beige zigzag
                // filled whole faces with flat beige (L's pictures, 2026-11-15).
                it->second.tex = asked_floor ? 0 : slot;
                for (int c = 0; c < 3; c++) {
                    const float own = (c == 0 ? dirt.r : c == 1 ? dirt.g : dirt.b) / 255.0f;
                    it->second.tint[c] = (green && floor) ? own : std::clamp(rgb[c], 0.0f, 1.0f);
                }
            }
            const bool first_look = !arena.has_look;
            arena.has_look = true;
            arena.look_slot = asked_floor ? 0 : slot;
            for (int c = 0; c < 3; c++) {
                const float own = (c == 0 ? dirt.r : c == 1 ? dirt.g : dirt.b) / 255.0f;
                arena.look_tint[c] = (green && asked_floor) ? own : std::clamp(rgb[c], 0.0f, 1.0f);
            }
            // The meshes to make again: those within reach of the blows (a blow's columns reach about a dozen cells
            // round it), or all of them the first time on the map (cells with no answer of their own take this one).
            constexpr int reach = 14;
            for (auto& [key, c] : world.chunks) {
                bool near = first_look;
                for (const auto& p : colour_ask.near) {
                    if (near) break;
                    const int base[3] = { c->cx * chunk_n, c->cy * chunk_n, c->cz * chunk_n };
                    near = true;
                    for (int k = 0; k < 3; k++) near = near && p[k] >= base[k] - reach && p[k] < base[k] + chunk_n + reach;
                }
                if (near) c->dirty = true;
            }
            if (log_on()) fprintf(stderr, "[voxels] surface colour %.2f %.2f %.2f for %zu columns\n", rgb[0], rgb[1], rgb[2], colour_ask.columns.size());
            colour_ask = ColourAsk{};
        }
        else if (game_time_now() - colour_ask.asked_at > 2.0f) {
            if (log_on()) fprintf(stderr, "[voxels] no surface colour found for %zu columns\n", colour_ask.columns.size());
            colour_ask = ColourAsk{};
        }
    }

    // Digging down into sand or dirt throws it up round the hole (L, 2026-11-13: "a trench before going down", only
    // when going down): the columns beside a dug one get two cells of the dug soil on top of the ground, the ones beyond
    // those one, so the smooth surface rounds it into a lip that falls away outward. Never in walls or above. The pile
    // is soil like the rest (one blow), stood on and pushed against as a shown cell; it is not cut out of the level
    // (there is none under it to cut).
    void pile_round(uint8_t* rdram, recomp_context* ctx, const std::vector<std::array<int, 3>>& changed, int code, float ref) {
        // The dug soil columns, by x and z, with the soil.
        std::unordered_map<uint64_t, Mat> dug_cols;
        for (const auto& p : changed) {
            const Chunk* c = chunk_at(p[0], p[1], p[2], false);
            if (c == nullptr) continue;
            const int i = local_index(*c, p[0], p[1], p[2]);
            if (c->state[i] != Dug || !soil((Mat)c->mat[i]) || dir_axis(c->dir[i]) != 1) continue;
            dug_cols.emplace(pack3(p[0], 0, p[2]), (Mat)c->mat[i]);
        }
        if (dug_cols.empty()) return;
        auto field = [](uint64_t v) { int32_t f = (int32_t)(v & 0x1FFFFF); return (f & 0x100000) ? f - 0x200000 : f; };
        // The rings round the dug columns, round rather than square (square rings stood up as a box round the hole,
        // 2026-11-15): height 2 within 1.5 cells, 1 within 2.5, the outer ring broken up so its edge is ragged
        // (the higher wins).
        std::unordered_map<uint64_t, std::pair<int, Mat>> heights;
        for (const auto& [key, mat] : dug_cols) {
            const int x = field(key >> 42), z = field(key);
            for (int dz = -2; dz <= 2; dz++) for (int dx = -2; dx <= 2; dx++) {
                const uint64_t col = pack3(x + dx, 0, z + dz);
                if (dug_cols.count(col)) continue;
                const float r = std::sqrt((float)(dx * dx + dz * dz));
                int h = r <= 1.5f ? 2 : r <= 2.5f ? 1 : 0;
                if (h == 1 && unit(hash3((uint32_t)(x + dx) * 977u, 41u, (uint32_t)(z + dz) * 613u)) < 0.4f) h = 0;
                if (h == 0) continue;
                auto& e = heights[col];
                if (h > e.first) e = { h, mat };
            }
        }
        for (const auto& [key, hm] : heights) {
            const int x = field(key >> 42), z = field(key);
            // The ground's surface in that column (its first cell in open air is the one it lies in).
            const Column& col = column(rdram, ctx, code, x, cell_of(ref), z, ref);
            if (!col.hit) continue;
            const int first = cell_of(col.surface);
            for (int j = 0; j < hm.first; j++) {
                const int y = first + j;
                ensure(rdram, ctx, x, y, z, code, ref);
                Chunk* c = chunk_at(x, y, z, true);
                const int i = local_index(*c, x, y, z);
                if (c->state[i] != Air) continue;
                c->state[i] = Solid;
                c->mat[i] = hm.second;
                c->dmg[i] = 0;
                c->flags[i] |= cell_piled;
                mark_dirty(x, y, z);
            }
        }
    }

    // A blow from `origin` (where it comes from: Banjo's chest, an egg's last place) to a sphere round `centre`.
    // The level's surface it meets fills the cells round it; then every solid cell in the sphere that the power can
    // hurt takes damage, at most half its health (two blows at least). fire: melts ice and
    // snow. ground: where the debris bounces.
    // only: when not Empty, the blow hurts that material alone (a blue egg: sand).
    Breaks strike(uint8_t* rdram, recomp_context* ctx, const float origin[3], const float centre[3], float radius, int power,
                  bool fire, float ground, Mat only = Empty) {
        // The Strength slider: the blow's power (what it can break, how fast) times it, its reach times its square root.
        if (sliders.strength != 1.0f) {
            power = std::max(1, (int)std::lround(power * sliders.strength));
            radius *= std::sqrt(sliders.strength);
        }
        Breaks out;
        for (int c = 0; c < 3; c++) out.where[c] = centre[c];
        float dir[3] = { centre[0] - origin[0], centre[1] - origin[1], centre[2] - origin[2] };
        float len = length3(dir);
        if (len < 1.0f) { dir[0] = 0.0f; dir[1] = -1.0f; dir[2] = 0.0f; len = 1.0f; }
        else for (float& v : dir) v /= len;
        const float to[3] = { centre[0] + dir[0] * radius, centre[1] + dir[1] * radius, centre[2] + dir[2] * radius };
        float hit[3], n[3] = { 0.0f, 1.0f, 0.0f };
        uint32_t flags = 0;
        int code = -1;
        float ref = 0.0f;
        if (line_test(rdram, ctx, origin, to, kind_solid, hit, n, &flags) && (flags & no_dig_flags) == 0) {
            const float d[3] = { hit[0] - centre[0], hit[1] - centre[1], hit[2] - centre[2] };
            if (length3(d) <= radius + vs) {
                out.reached = true;
                if (protected_place(rdram, ctx, hit, n, flags)) {
                    out.kept = true;
                    return out;
                }
                int a = 0;
                for (int c = 1; c < 3; c++) if (std::fabs(n[c]) > std::fabs(n[a])) a = c;
                code = dir_code(a, n[a] >= 0.0f ? 1 : -1);
                ref = hit[a];
            }
        }
        else if (line_test(rdram, ctx, origin, to, kind_solid, hit, n, &flags) && (flags & no_dig_flags) != 0) {
            // Water, a hazard liquid or the like: never dug.
            out.reached = true;
            out.kept = true;
            return out;
        }
        if (code < 0 && !world.cut.empty()) {
            float wy;
            if (water_at(rdram, ctx, centre[0], centre[2], centre[1] + water_keep_off, centre[1] - water_keep_off, &wy)) {
                out.kept = true;
                return out;
            }
        }
        const float reach = radius + vs;
        const int x0 = cell_of(centre[0] - reach), x1 = cell_of(centre[0] + reach);
        const int y0 = cell_of(centre[1] - reach), y1 = cell_of(centre[1] + reach);
        const int z0 = cell_of(centre[2] - reach), z1 = cell_of(centre[2] + reach);
        fresh_columns.clear();
        if (code >= 0) {
            for (int z = z0; z <= z1; z++) for (int y = y0; y <= y1; y++) for (int x = x0; x <= x1; x++) {
                ensure(rdram, ctx, x, y, z, code, ref);
            }
        }
        Rng rng(hash3((uint32_t)(int32_t)(centre[0] * 7), (uint32_t)(int32_t)(centre[2] * 13), frame_counter));
        std::vector<std::array<int, 3>> changed;
        for (int z = z0; z <= z1; z++) for (int y = y0; y <= y1; y++) for (int x = x0; x <= x1; x++) {
            Chunk* c = chunk_at(x, y, z, false);
            if (c == nullptr) continue;
            const int i = local_index(*c, x, y, z);
            const uint8_t st = c->state[i];
            if (!solid_state(st)) continue;
            const float mid[3] = { (x + 0.5f) * vs, (y + 0.5f) * vs, (z + 0.5f) * vs };
            const float d3[3] = { mid[0] - centre[0], mid[1] - centre[1], mid[2] - centre[2] };
            const float d = length3(d3);
            if (d > radius + vs * 0.5f) continue;
            if (code < 0 && !shown(x, y, z)) continue;   // nothing struck but shown cells
            out.reached = true;
            const Mat m = (Mat)c->mat[i];
            const MatInfo& info = mats[m];
            if (st == Bedrock || (only != Empty && m != only)) { out.clinks++; continue; }
            int pw = power;
            if (fire && (m == Ice || m == Snow)) pw = std::max(pw, 3);
            const bool wet = (c->flags[i] & cell_wet) != 0;
            if (wet && pw + 1 >= info.hardness) pw = std::max(pw, (int)info.hardness);
            if (pw < info.hardness) {
                out.clinks++;
                continue;
            }
            float amount = pw * 10.0f * (1.0f - 0.5f * std::clamp(d / (radius + vs * 0.5f), 0.0f, 1.0f));
            if (fire && m == Ice) amount *= 3.0f;
            if (wet) amount *= 1.3f;
            // Sand and dirt break at one blow; anything else takes two at least (L, 2026-11-13).
            if (soil(m)) amount = (float)info.health;
            else amount = std::min(amount, (float)((info.health + 1) / 2));
            const int total = c->dmg[i] + std::max(1, (int)std::lround(amount));
            if (total >= info.health) {
                c->state[i] = Dug;
                c->dmg[i] = 0;
                const int a = dir_axis(c->dir[i]), s = dir_sign(c->dir[i]);
                float out_n[3] = { 0.0f, 0.0f, 0.0f };
                out_n[a] = (float)s;
                if (rng.f() < 0.8f) spawn_debris(mid, centre, out_n, m, ground, rng);
                if (out.mat == Empty) out.mat = m;
                out.count++;
                world.dug++;
            }
            else {
                c->dmg[i] = (uint8_t)std::min(total, 255);
                out.cracked++;
            }
            changed.push_back({ x, y, z });
        }
        // Cells cut loose fall (as Teardown's): a flood fill through solid cells from the edges of a box round the blow,
        // from bedrock and from cells beside ground not filled yet (still joined to the world), and whatever it does not
        // reach breaks out as debris.
        if (out.count > 0) {
            const int pad = 3;
            const int bx0 = x0 - pad, bx1 = x1 + pad, by0 = y0 - pad, by1 = y1 + pad, bz0 = z0 - pad, bz1 = z1 + pad;
            const int nx = bx1 - bx0 + 1, ny = by1 - by0 + 1, nz = bz1 - bz0 + 1;
            std::vector<uint8_t> reach((size_t)nx * ny * nz, 0);
            auto at = [&](int x, int y, int z) { return ((size_t)(z - bz0) * ny + (y - by0)) * nx + (x - bx0); };
            std::vector<std::array<int, 3>> queue;
            static constexpr int n6[6][3] = { { 1, 0, 0 }, { -1, 0, 0 }, { 0, 1, 0 }, { 0, -1, 0 }, { 0, 0, 1 }, { 0, 0, -1 } };
            for (int z = bz0; z <= bz1; z++) for (int y = by0; y <= by1; y++) for (int x = bx0; x <= bx1; x++) {
                const uint8_t st = state_at(x, y, z);
                if (!solid_state(st)) continue;
                bool anchor = st == Bedrock || x == bx0 || x == bx1 || y == by0 || y == by1 || z == bz0 || z == bz1;
                for (int k = 0; k < 6 && !anchor; k++) anchor = state_at(x + n6[k][0], y + n6[k][1], z + n6[k][2]) == Unknown;
                if (anchor) { reach[at(x, y, z)] = 1; queue.push_back({ x, y, z }); }
            }
            for (size_t q = 0; q < queue.size(); q++) {
                for (const auto& d : n6) {
                    const int x = queue[q][0] + d[0], y = queue[q][1] + d[1], z = queue[q][2] + d[2];
                    if (x < bx0 || x > bx1 || y < by0 || y > by1 || z < bz0 || z > bz1) continue;
                    if (reach[at(x, y, z)] || !solid_state(state_at(x, y, z))) continue;
                    reach[at(x, y, z)] = 1;
                    queue.push_back({ x, y, z });
                }
            }
            for (int z = bz0; z <= bz1; z++) for (int y = by0; y <= by1; y++) for (int x = bx0; x <= bx1; x++) {
                if (reach[at(x, y, z)] || !solid_state(state_at(x, y, z))) continue;
                Chunk* c = chunk_at(x, y, z, false);
                const int i = local_index(*c, x, y, z);
                const float mid[3] = { (x + 0.5f) * vs, (y + 0.5f) * vs, (z + 0.5f) * vs };
                const float down[3] = { 0.0f, -0.3f, 0.0f };
                if (rng.f() < 0.8f) spawn_debris(mid, centre, down, c->mat[i], ground, rng);
                c->state[i] = Dug;
                c->dmg[i] = 0;
                out.count++;
                world.dug++;
                changed.push_back({ x, y, z });
            }
        }
        // The cells two round each changed one are filled (from the changed cell's own column direction), so a hole's
        // sides and floor are known, and the smooth surface's rim (build_mesh looks one further than a shown cell);
        // then what is shown and cut is worked out again there.
        for (const auto& p : changed) {
            const Chunk* c = chunk_at(p[0], p[1], p[2], false);
            const int i = local_index(*c, p[0], p[1], p[2]);
            const int cc = c->dir[i];
            const float cref = c->surface[i];
            for (int dz = -2; dz <= 2; dz++) for (int dy = -2; dy <= 2; dy++) for (int dx = -2; dx <= 2; dx++) {
                ensure(rdram, ctx, p[0] + dx, p[1] + dy, p[2] + dz, cc, cref);
            }
        }
        for (const auto& p : changed) {
            mark_dirty(p[0], p[1], p[2]);
            recut_around(p[0], p[1], p[2]);
        }
        if (code == dir_code(1, 1) && out.count > 0) pile_round(rdram, ctx, changed, code, ref);
        if (code >= 0 && !fresh_columns.empty()) ask_colour(hit, code, fresh_columns);
        return out;
    }

    void sound_for(uint8_t* rdram, recomp_context* ctx, const Breaks& b) {
        if (b.count > 0 && b.mat != Empty) {
            const MatInfo& m = mats[b.mat];
            const float pitch = m.pitch * (0.9f + 0.2f * unit(hash32(frame_counter * 31u + b.count)));
            play_sound(rdram, ctx, m.sound, b.where, pitch, std::min(1.0f, 0.55f + 0.05f * b.count));
        }
    }

    // ---------------------------------------------------------------------------------------------------------------
    // Banjo

    struct Player {
        uint32_t ps = 0, physics = 0, posp = 0;
        float pos[3] = {};
        float yaw = 0.0f;
        uint32_t state = 0;
    };

    bool read_player(uint8_t* rdram, Player& pl) {
        pl.ps = read_word(rdram, player_table);
        if (!valid_ptr(pl.ps)) return false;
        pl.physics = read_word(rdram, pl.ps + physics_offset);
        pl.posp = read_word(rdram, pl.ps + pos_ptr_offset);
        if (!valid_ptr(pl.physics) || !valid_ptr(pl.posp)) return false;
        for (int c = 0; c < 3; c++) pl.pos[c] = read_float(rdram, pl.physics + 4 + 4 * c);
        const uint32_t yp = read_word(rdram, pl.ps + yaw_ptr_offset);
        pl.yaw = valid_ptr(yp) ? read_float(rdram, yp) : 0.0f;
        const uint32_t block = read_word(rdram, pl.ps + state_offset);
        pl.state = valid_ptr(block) ? read_word(rdram, block + 4) : 0;
        for (float v : pl.pos) if (!std::isfinite(v)) return false;
        return true;
    }

    void write_player_xz(uint8_t* rdram, const Player& pl, float x, float z) {
        write_float(rdram, pl.physics + 4, x);
        write_float(rdram, pl.physics + 0xC, z);
        for (uint32_t copy = 0; copy < 3; copy++) {
            write_float(rdram, pl.posp + copy * 0xC, x);
            write_float(rdram, pl.posp + copy * 0xC + 8, z);
        }
        write_float(rdram, pl.ps + last_pos_offset, x);
        write_float(rdram, pl.ps + last_pos_offset + 8, z);
    }

    // Out of bounds (L, 2026-11-13: "if I fall out of bounds, make it reset too"): Banjo more than three cells under the
    // lowest cut cell has fallen through the dug ground into the empty inside of the world. Everything is put back, as on
    // leaving the map, and he goes back to the last place he stood away from any hole, standing still.
    struct SafePlace { bool have = false; float pos[3] = {}; } safe_place;

    void write_player_pos(uint8_t* rdram, const Player& pl, const float p[3]) {
        for (int c = 0; c < 3; c++) {
            write_float(rdram, pl.physics + 4 + 4 * c, p[c]);
            write_float(rdram, pl.physics + 0x10 + 4 * c, 0.0f);
            for (uint32_t copy = 0; copy < 3; copy++) write_float(rdram, pl.posp + copy * 0xC + 4 * c, p[c]);
            write_float(rdram, pl.ps + last_pos_offset + 4 * c, p[c]);
        }
    }

    void reset_world();

    // From the tick: keeps the safe place, and catches a fall out of bounds.
    float inside_time = 0.0f;   // how long Banjo has been inside the ground (watch_bounds)
    float last_dt = 0.0f;       // the tick's game time step

    void watch_bounds(uint8_t* rdram, recomp_context* ctx) {
        Player pl;
        if (!read_player(rdram, pl) || locked_state(pl.state)) return;
        const int bx = cell_of(pl.pos[0]), by = cell_of(pl.pos[1]), bz = cell_of(pl.pos[2]);
        if (world.cut.empty()) {
            safe_place.have = true;
            for (int c = 0; c < 3; c++) safe_place.pos[c] = pl.pos[c];
            return;
        }
        // Out of bounds: below the cut cells, under them (within a few cells of one sideways), and with no ground of the
        // level under him. Below the cut cells alone isn't enough: a hole high in a wall leaves the ground under it
        // lower than every cut cell, and walking or falling there is fine (it put everything back by mistake).
        bool out = false;
        if (by < world.cut_lo_y - 3) {
            bool under = false;
            for (int dz = -4; dz <= 4 && !under; dz++) for (int dx = -4; dx <= 4 && !under; dx++) {
                for (int y = world.cut_lo_y; y <= world.cut_hi_y && !under; y++) under = is_cut(bx + dx, y, bz + dz);
            }
            if (under) {
                const float from[3] = { pl.pos[0], pl.pos[1] + 20.0f, pl.pos[2] };
                const float to[3] = { pl.pos[0], pl.pos[1] - 2000.0f, pl.pos[2] };
                float hit[3], hn[3];
                out = !line_test(rdram, ctx, from, to, kind_solid, hit, hn, nullptr);
            }
        }
        // Or inside the ground (L, 2026-11-13: he did fall out of bounds, and it should put everything back): his feet
        // and middle both behind the level's surface by more than a cell, by any column the blows have line-tested
        // there, and neither in a dug cell, for a sixth of a second running (a moment slipping past a corner is not it).
        {
            bool inside = true;
            const float body[2] = { pl.pos[1] + 8.0f, pl.pos[1] + 50.0f };
            for (int k = 0; k < 2 && inside; k++) {
                const float p[3] = { pl.pos[0], body[k], pl.pos[2] };
                const int cx = cell_of(p[0]), cy = cell_of(p[1]), cz = cell_of(p[2]);
                if (state_at(cx, cy, cz) == Dug) { inside = false; break; }
                bool behind = false;
                for (int code = 0; code < 6 && !behind; code++) {
                    auto col = world.columns.find(column_key(code, cx, cy, cz));
                    if (col == world.columns.end() || !col->second.hit) continue;
                    const int a = dir_axis(code), sg = dir_sign(code);
                    behind = (sg > 0 ? col->second.surface - p[a] : p[a] - col->second.surface) > vs * 1.5f;
                }
                inside = behind;
            }
            inside_time = inside ? inside_time + last_dt : 0.0f;
            if (inside_time > 0.17f) out = true;
        }
        if (out) {
            inside_time = 0.0f;
            if (log_on()) fprintf(stderr, "[voxels] Banjo fell out of bounds at y %.0f: everything put back\n", pl.pos[1]);
            reset_world();
            if (safe_place.have) write_player_pos(rdram, pl, safe_place.pos);
            return;
        }
        // A safe place: no cut or dug cell in the cells round his feet and below them.
        for (int dz = -2; dz <= 2; dz++) for (int dy = -4; dy <= 1; dy++) for (int dx = -2; dx <= 2; dx++) {
            if (is_cut(bx + dx, by + dy, bz + dz) || state_at(bx + dx, by + dy, bz + dz) == Dug) return;
        }
        safe_place.have = true;
        for (int c = 0; c < 3; c++) safe_place.pos[c] = pl.pos[c];
    }

    constexpr float body_radius = 34.0f;
    constexpr float body_height = 105.0f;
    // A cell whose top is no more than this above his feet is a step: the push leaves it alone, and the floor test
    // lifts him onto it, so he walks up one cell but not two.
    constexpr float step_up = vs + 2.0f;

    // Pushes Banjo sideways out of shown cells (a hole's sides) higher than a step, and stops his speed into them.
    // Cells still under the level's surface are left to the level's own collision.
    void collide(uint8_t* rdram) {
        if (world.cut.empty()) return;
        Player pl;
        if (!read_player(rdram, pl) || locked_state(pl.state)) return;
        float x = pl.pos[0], z = pl.pos[2];
        const float y = pl.pos[1];
        bool moved = false;
        for (int pass = 0; pass < 2; pass++) {
            float push_x = 0.0f, push_z = 0.0f;
            const int i0 = cell_of(x - body_radius), i1 = cell_of(x + body_radius);
            const int k0 = cell_of(z - body_radius), k1 = cell_of(z + body_radius);
            const int j0 = cell_of(y + step_up), j1 = cell_of(y + body_height);
            for (int k = k0; k <= k1; k++) for (int i = i0; i <= i1; i++) {
                bool any = false;
                for (int j = j0; j <= j1 && !any; j++) any = shown(i, j, k);
                if (!any) continue;
                // The nearest point of the column's square to his middle.
                const float qx = std::clamp(x, i * vs, (i + 1) * vs), qz = std::clamp(z, k * vs, (k + 1) * vs);
                float ex = x - qx, ez = z - qz;
                float d = std::sqrt(ex * ex + ez * ez);
                if (d >= body_radius) continue;
                if (d < 0.01f) {
                    // His middle is inside the cell: out through the nearest side of its square.
                    const float to_lo = z - k * vs, to_hi = (k + 1) * vs - z;
                    const float to_left = x - i * vs, to_right = (i + 1) * vs - x;
                    const float m = std::min({ to_lo, to_hi, to_left, to_right });
                    if (m == to_hi) { ex = 0; ez = 1; d = -to_hi; }
                    else if (m == to_lo) { ex = 0; ez = -1; d = -to_lo; }
                    else if (m == to_right) { ex = 1; ez = 0; d = -to_right; }
                    else { ex = -1; ez = 0; d = -to_left; }
                    const float depth = body_radius - d;
                    if (std::fabs(ex * depth) > std::fabs(push_x)) push_x = ex * depth;
                    if (std::fabs(ez * depth) > std::fabs(push_z)) push_z = ez * depth;
                    continue;
                }
                const float depth = body_radius - d;
                const float px = ex / d * depth, pz = ez / d * depth;
                if (std::fabs(px) > std::fabs(push_x)) push_x = px;
                if (std::fabs(pz) > std::fabs(push_z)) push_z = pz;
            }
            if (push_x == 0.0f && push_z == 0.0f) break;
            x += push_x;
            z += push_z;
            moved = true;
            const float wl = std::sqrt(push_x * push_x + push_z * push_z);
            const float nx = push_x / wl, nz = push_z / wl;
            float vx = read_float(rdram, pl.physics + 0x10), vz = read_float(rdram, pl.physics + 0x18);
            const float into = vx * nx + vz * nz;
            if (into < 0.0f) {
                vx -= into * nx; vz -= into * nz;
                write_float(rdram, pl.physics + 0x10, vx);
                write_float(rdram, pl.physics + 0x18, vz);
            }
        }
        if (moved && std::isfinite(x) && std::isfinite(z)) {
            write_player_xz(rdram, pl, x, z);
        }
    }

    // ---------------------------------------------------------------------------------------------------------------
    // The game's collision tests (see the top): hooks at the entry, after each provider and at the exit.

    constexpr int hook_depth = 12;
    uint32_t floor_hits = 0, contacts_dropped = 0;

    // func_800C6A7C(from, to, normal, kind): the line's own end, kept at the entry (the providers move `to`).
    struct LineCall { float end[3]; };
    LineCall line_calls[hook_depth];
    int line_depth = 0;
    int rerun_depth = 0;   // reruns of the floor test inside reruns (floor_exit)

    // A cut cell at a contact: the point moved a cell into the surface (against its normal), into the outermost solid
    // cell under it (a solid cell is all behind the surface, at most a cell under it).
    bool contact_in_cut(const float p[3], const float n[3]) {
        const float probe[3] = { p[0] - n[0] * vs, p[1] - n[1] * vs, p[2] - n[2] * vs };
        return is_cut_at(probe);
    }

    void floor_enter(uint8_t* rdram, recomp_context* ctx) {
        if (line_depth < hook_depth) {
            const uint32_t to = (uint32_t)ctx->r5;
            for (int c = 0; c < 3; c++) line_calls[line_depth].end[c] = valid_ptr(to) ? read_float(rdram, to + 4 * c) : 0.0f;
        }
        line_depth++;
    }

    // The tops and bottoms of shown cells along a steep line: a top is a floor where the cell above is open, a bottom
    // a ceiling where the cell below is. A line that starts a little inside a cell still finds its top (a step).
    constexpr float floor_start_allow = 12.0f;
    constexpr float floor_edge_reach = 12.0f;

    bool cell_face_on_line(const float f[3], const float t[3], float best[3]) {
        const float dy = t[1] - f[1];
        const float hx = t[0] - f[0], hz = t[2] - f[2];
        if (std::fabs(dy) < 0.5f || hx * hx + hz * hz > 0.36f * dy * dy) return false;
        for (int c = 0; c < 3; c++) if (std::fabs(f[c]) > 1e6f || std::fabs(t[c]) > 1e6f) return false;
        // Only the rows the cut cells are in (a face is a shown cell's top or bottom), at most 256 of them.
        const float row_lo = (float)(world.cut_lo_y - 1) * vs, row_hi = (float)(world.cut_hi_y + 2) * vs;
        if (std::max(f[1], t[1]) < row_lo || std::min(f[1], t[1]) > row_hi) return false;
        constexpr float around[5][2] = { { 0, 0 }, { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        auto point_at = [&](float y, float* x, float* z) {
            const float s = std::clamp((f[1] - y) / (f[1] - t[1]), 0.0f, 1.0f);
            *x = f[0] + s * hx; *z = f[2] + s * hz;
        };
        if (dy < 0.0f) {
            const int k_end = std::max(cell_of(std::max(t[1], row_lo)), cell_of(f[1] + floor_start_allow) - 256);
            for (int k = std::min(cell_of(f[1] + floor_start_allow), cell_of(row_hi)); k >= k_end && (float)k * vs > t[1]; k--) {
                const float y = k * vs;
                if (y > f[1] + floor_start_allow) continue;
                float px, pz;
                point_at(y, &px, &pz);
                for (const auto& a : around) {
                    const int i = cell_of(px + a[0] * floor_edge_reach), kz = cell_of(pz + a[1] * floor_edge_reach);
                    if (shown(i, k - 1, kz) && !solid_state(state_at(i, k, kz))) {
                        best[0] = px; best[1] = y; best[2] = pz;
                        return true;
                    }
                }
            }
        }
        else {
            const int k_end = std::min(cell_of(std::min(t[1], row_hi)) + 1, cell_of(f[1]) + 257);
            for (int k = std::max(cell_of(f[1]) + 1, cell_of(row_lo)); k <= k_end && (float)k * vs < t[1]; k++) {
                const float y = k * vs;
                float px, pz;
                point_at(y, &px, &pz);
                const int i = cell_of(px), kz = cell_of(pz);
                if (shown(i, k, kz) && !solid_state(state_at(i, k - 1, kz))) {
                    best[0] = px; best[1] = y; best[2] = pz;
                    return true;
                }
            }
        }
        return false;
    }

    void floor_exit(uint8_t* rdram, recomp_context* ctx) {
        line_depth--;
        if (line_depth < 0) { line_depth = 0; return; }
        if (!was_on || world.cut.empty() || line_depth >= hook_depth) return;
        if (tooie::debug::map_change_busy(rdram) || tooie::debug::current_map(rdram) != current_map) return;
        const uint32_t from_addr = (uint32_t)ctx->r19, to_addr = (uint32_t)ctx->r20, normal_addr = (uint32_t)ctx->r21;
        if (!valid_ptr(from_addr) || !valid_ptr(to_addr)) return;
        const float* end = line_calls[line_depth].end;
        float f[3], t[3], n[3] = { 0.0f, 1.0f, 0.0f };
        for (int c = 0; c < 3; c++) {
            f[c] = read_float(rdram, from_addr + 4 * c);
            t[c] = read_float(rdram, to_addr + 4 * c);
            if (valid_ptr(normal_addr)) n[c] = read_float(rdram, normal_addr + 4 * c);
            if (!std::isfinite(f[c]) || !std::isfinite(t[c]) || !std::isfinite(end[c])) return;
        }
        uint32_t tri = (uint32_t)ctx->r23;
        // 1. A provider's hit in a cut cell is dropped, and the test runs again from just past it to the line's end.
        if (tri != 0 && contact_in_cut(t, n)) {
            contacts_dropped++;
            const float span[3] = { end[0] - f[0], end[1] - f[1], end[2] - f[2] };
            const float total = length3(span);
            const float dir[3] = { span[0] / std::max(total, 0.001f), span[1] / std::max(total, 0.001f), span[2] / std::max(total, 0.001f) };
            const float past[3] = { t[0] + dir[0], t[1] + dir[1], t[2] + dir[2] };
            const float left = (end[0] - past[0]) * dir[0] + (end[1] - past[1]) * dir[1] + (end[2] - past[2]) * dir[2];
            uint32_t again = 0;
            float hit[3] = { end[0], end[1], end[2] }, hn[3] = { n[0], n[1], n[2] };
            uint32_t owner = 0;
            if (left > 0.5f && rerun_depth < 4 && line_depth + 1 < hook_depth) {
                rerun_depth++;
                GameCall call(rdram, ctx);
                call.vec(0x00, past);
                call.vec(0x10, end);
                call.vec(0x20, n);
                again = (uint32_t)call(func_800C6A7C, call.scratch, call.scratch + 0x10, call.scratch + 0x20, (uint32_t)ctx->r22);
                if (again != 0) {
                    for (int c = 0; c < 3; c++) {
                        hit[c] = read_float(rdram, call.scratch + 0x10 + 4 * c);
                        hn[c] = read_float(rdram, call.scratch + 0x20 + 4 * c);
                    }
                    owner = read_word(rdram, providers + 0x84);
                }
                rerun_depth--;
            }
            for (int c = 0; c < 3; c++) {
                t[c] = hit[c];
                write_float(rdram, to_addr + 4 * c, hit[c]);
                if (valid_ptr(normal_addr)) write_float(rdram, normal_addr + 4 * c, hn[c]);
            }
            write_word(rdram, providers + 0x84, again != 0 ? owner : 0);
            tri = again;
            ctx->r23 = (gpr)(int32_t)again;
        }
        // 2. A shown cell's top or bottom nearer than what is left.
        float face[3];
        if (cell_face_on_line(f, t, face)) {
            const bool down = t[1] < f[1];
            uint32_t flags = 0;
            if (const Chunk* c = chunk_at(cell_of(face[0]), cell_of(face[1]) - (down ? 1 : 0), cell_of(face[2]), false)) flags = c->ground_flags;
            if (valid_ptr(tri)) flags = read_word(rdram, tri + 8);
            for (int c = 0; c < 3; c++) write_float(rdram, to_addr + 4 * c, face[c]);
            if (valid_ptr(normal_addr)) {
                write_float(rdram, normal_addr, 0.0f);
                write_float(rdram, normal_addr + 4, down ? 1.0f : -1.0f);
                write_float(rdram, normal_addr + 8, 0.0f);
            }
            // The ground's own triangle under it where the providers found one; otherwise a fake one (no vertices of
            // its own: the floor code reads only its flags) with the ground's flags.
            if (valid_ptr(tri)) {
                ctx->r23 = (gpr)(int32_t)tri;
            }
            else if (arena.floor_tris != 0) {
                const uint32_t fake = arena.floor_tris + (floor_hits % floor_tri_slots) * floor_tri_bytes;
                write_word(rdram, fake + 0, 0);
                write_word(rdram, fake + 4, 0);
                write_word(rdram, fake + 8, flags & ~no_dig_flags);
                write_word(rdram, fake + 12, 0);
                ctx->r23 = (gpr)(int32_t)fake;
            }
            write_word(rdram, providers + 0x84, 0);
            floor_hits++;
        }
    }

    // func_800C6C94(centre, radius, push_out, kind): each provider writes push_out; a dropped contact puts back what
    // the last kept one wrote.
    struct PushCall { float kept[3]; bool have; };
    PushCall push_calls[hook_depth];
    int push_depth = 0;

    void push_enter(uint8_t* rdram, recomp_context* ctx) {
        if (push_depth < hook_depth) {
            // push_out as it was before any provider wrote it, put back if the first one is dropped.
            const uint32_t push = (uint32_t)ctx->r6;
            push_calls[push_depth].have = valid_ptr(push);
            for (int c = 0; c < 3; c++) push_calls[push_depth].kept[c] = valid_ptr(push) ? read_float(rdram, push + 4 * c) : 0.0f;
        }
        push_depth++;
    }

    // The cut cells belong to this map and it is not changing (the tick keeps them until the new map settles).
    bool cuts_live(uint8_t* rdram) {
        return was_on && !world.cut.empty() && !tooie::debug::map_change_busy(rdram) && tooie::debug::current_map(rdram) == current_map;
    }

    void push_after_provider(uint8_t* rdram, recomp_context* ctx) {
        const int d = push_depth - 1;
        if (d < 0 || d >= hook_depth || (uint32_t)ctx->r2 == 0) return;
        const uint32_t centre_addr = (uint32_t)ctx->r19, push_addr = (uint32_t)ctx->r20;
        if (!valid_ptr(centre_addr) || !valid_ptr(push_addr)) return;
        float p[3], centre[3];
        for (int c = 0; c < 3; c++) {
            p[c] = read_float(rdram, push_addr + 4 * c);
            centre[c] = read_float(rdram, centre_addr + 4 * c);
        }
        const float len = length3(p);
        if (cuts_live(rdram) && std::isfinite(len) && len > 1e-4f) {
            const float out_n[3] = { p[0] / len, p[1] / len, p[2] / len };
            const float radius = ctx->f20.fl;
            const float contact[3] = { centre[0] - out_n[0] * radius, centre[1] - out_n[1] * radius, centre[2] - out_n[2] * radius };
            if (contact_in_cut(contact, out_n)) {
                contacts_dropped++;
                ctx->r2 = 0;
                if (push_calls[d].have) {
                    for (int c = 0; c < 3; c++) write_float(rdram, push_addr + 4 * c, push_calls[d].kept[c]);
                }
                return;
            }
        }
        for (int c = 0; c < 3; c++) push_calls[d].kept[c] = p[c];
        push_calls[d].have = true;
    }

    void push_exit() {
        if (push_depth > 0) push_depth--;
    }

    // func_800C6B78(a, b, radius, normal, kind, flags), the swept sphere: a provider moves one end to the contact.
    // A dropped contact puts both ends back as the last kept provider left them.
    struct SweepCall { float a[3], b[3]; };
    SweepCall sweep_calls[hook_depth];
    int sweep_depth = 0;

    void sweep_enter(uint8_t* rdram, recomp_context* ctx) {
        if (sweep_depth < hook_depth) {
            const uint32_t a = (uint32_t)ctx->r4, b = (uint32_t)ctx->r5;
            for (int c = 0; c < 3; c++) {
                sweep_calls[sweep_depth].a[c] = valid_ptr(a) ? read_float(rdram, a + 4 * c) : 0.0f;
                sweep_calls[sweep_depth].b[c] = valid_ptr(b) ? read_float(rdram, b + 4 * c) : 0.0f;
            }
        }
        sweep_depth++;
    }

    void sweep_after_provider(uint8_t* rdram, recomp_context* ctx) {
        const int d = sweep_depth - 1;
        if (d < 0 || d >= hook_depth || (uint32_t)ctx->r2 == 0) return;
        const uint32_t a_addr = (uint32_t)ctx->r19, b_addr = (uint32_t)ctx->r20, n_addr = (uint32_t)ctx->r21;
        if (!valid_ptr(a_addr) || !valid_ptr(b_addr)) return;
        float a[3], b[3], n[3] = { 0.0f, 0.0f, 0.0f };
        for (int c = 0; c < 3; c++) {
            a[c] = read_float(rdram, a_addr + 4 * c);
            b[c] = read_float(rdram, b_addr + 4 * c);
            if (valid_ptr(n_addr)) n[c] = read_float(rdram, n_addr + 4 * c);
        }
        SweepCall& kept = sweep_calls[d];
        if (cuts_live(rdram)) {
            // The end that moved is the sphere's middle at the contact.
            const float da[3] = { a[0] - kept.a[0], a[1] - kept.a[1], a[2] - kept.a[2] };
            const float db[3] = { b[0] - kept.b[0], b[1] - kept.b[1], b[2] - kept.b[2] };
            const float* moved = length3(da) > length3(db) ? a : b;
            const float nl = length3(n);
            if (std::isfinite(nl) && nl > 0.5f) {
                const float out_n[3] = { n[0] / nl, n[1] / nl, n[2] / nl };
                const float radius = ctx->f20.fl;
                const float contact[3] = { moved[0] - out_n[0] * radius, moved[1] - out_n[1] * radius, moved[2] - out_n[2] * radius };
                if (contact_in_cut(contact, out_n)) {
                    contacts_dropped++;
                    ctx->r2 = 0;
                    for (int c = 0; c < 3; c++) {
                        write_float(rdram, a_addr + 4 * c, kept.a[c]);
                        write_float(rdram, b_addr + 4 * c, kept.b[c]);
                    }
                    return;
                }
            }
        }
        for (int c = 0; c < 3; c++) { kept.a[c] = a[c]; kept.b[c] = b[c]; }
    }

    void sweep_exit() {
        if (sweep_depth > 0) sweep_depth--;
    }

    // ---------------------------------------------------------------------------------------------------------------
    // Attacks

    // The state, its power, where its sphere is (forward, up from his feet), its size, how often it hits while the
    // state lasts, and whether it strikes down (from his chest to under his feet).
    struct Attack {
        uint32_t state;
        int power;
        float forward, up, radius;
        float every;
        bool down;
        const char* name;
    };
    constexpr Attack attacks[] = {
        { 0x06, 1, 45.0f, 55.0f, 42.0f, 0.20f, false, "claw swipe" },
        { 0xE4, 1, 50.0f, 55.0f, 46.0f, 0.20f, false, "pack whack" },
        { 0xC2, 1, 50.0f, 45.0f, 46.0f, 0.20f, false, "wing whack" },
        { 0xC4, 1, 50.0f, 45.0f, 46.0f, 0.20f, false, "wing whack" },
        { 0x31, 1, 42.0f, 30.0f, 46.0f, 0.12f, false, "roll" },
        { 0x11, 2, 50.0f, 60.0f, 46.0f, 0.12f, false, "rat-a-tat rap" },
        { 0x13, 3, 55.0f, 50.0f, 56.0f, 0.10f, false, "beak barge" },
        { 237, 3, 60.0f, 20.0f, 52.0f, 0.10f, false, "talon torpedo" },
        { 0x0F, 3, 0.0f, -10.0f, 56.0f, 0.10f, true, "beak buster" },
        { 0xB6, 3, 0.0f, -10.0f, 56.0f, 0.10f, true, "bill drill" },
    };

    uint32_t last_state = 0;
    float next_hit_time = 0.0f;

    // Lowers Banjo through dug cells under his feet at the drill's pace, down to the top of the first cell that is not
    // dug. Only dug cells: under the level's own ground (never filled in) he stays where the game holds him.
    constexpr float drill_speed = 150.0f;   // units a second, about 8 cells
    void drill_sink(uint8_t* rdram, const Player& pl) {
        if (world.cut.empty()) return;
        const int bx = cell_of(pl.pos[0]), bz = cell_of(pl.pos[2]);
        int y = cell_of(pl.pos[1] - 1.0f);
        if (state_at(bx, y, bz) != Dug) return;
        while (state_at(bx, y - 1, bz) == Dug && y > world.cut_lo_y - 2) y--;
        const float floor_y = y * vs;   // the bottom of the lowest dug cell in the run
        const float to = std::max(floor_y, pl.pos[1] - drill_speed * last_dt);
        if (to >= pl.pos[1] - 0.01f) return;
        const float p[3] = { pl.pos[0], to, pl.pos[2] };
        write_player_pos(rdram, pl, p);
    }

    void attack(uint8_t* rdram, recomp_context* ctx) {
        Player pl;
        if (!read_player(rdram, pl)) return;
        const uint32_t s = pl.state;
        const bool entered = s != last_state;
        const uint32_t left = entered ? last_state : 0;
        last_state = s;
        const float fwd[3] = { std::sin(pl.yaw * deg), 0.0f, std::cos(pl.yaw * deg) };
        // Landing from a Beak Buster: a wider blow at his feet.
        if (left == 0x0F) {
            const float origin[3] = { pl.pos[0], pl.pos[1] + 60.0f, pl.pos[2] };
            const float at[3] = { pl.pos[0], pl.pos[1] - 10.0f, pl.pos[2] };
            sound_for(rdram, ctx, strike(rdram, ctx, origin, at, 80.0f, 3, false, pl.pos[1]));
        }
        // The Bill Drill bores down (L, 2026-11-15: "the drill move doesn't remove voxels until it's done"). The game
        // holds Banjo at the height he landed at for the whole drill, so each blow only reached the cells just under
        // his feet and the hole showed only when the drill ended and he dropped. While he drills, he sinks into the
        // dug cells under him, so the next blow breaks deeper ground.
        if (s == 0xB6) drill_sink(rdram, pl);
        for (const Attack& a : attacks) {
            if (a.state != s) continue;
            if (!entered && game_time < next_hit_time) return;
            next_hit_time = game_time + a.every;
            const float origin[3] = { pl.pos[0], pl.pos[1] + (a.down ? 60.0f : a.up), pl.pos[2] };
            const float at[3] = { pl.pos[0] + fwd[0] * a.forward, pl.pos[1] + a.up, pl.pos[2] + fwd[2] * a.forward };
            const Breaks b = strike(rdram, ctx, origin, at, a.radius, a.power, false, pl.pos[1]);
            if (log_on() && (b.count > 0 || b.cracked > 0 || b.clinks > 0)) {
                fprintf(stderr, "[voxels] %s: %d broke, %d cracked, %d too hard\n", a.name, b.count, b.cracked, b.clinks);
            }
            sound_for(rdram, ctx, b);
            return;
        }
    }

    // ---------------------------------------------------------------------------------------------------------------
    // Eggs

    template <typename F>
    void for_each_object(uint8_t* rdram, F fn) {
        const uint32_t array = read_word(rdram, object_array_pointer);
        if (!valid_ptr(array)) return;
        const uint32_t first = read_word(rdram, array + 0x04);
        const uint32_t last = read_word(rdram, array + 0x08);
        if (!valid_ptr(first) || !valid_ptr(last) || last < first) return;
        const int count = (int)((last - first) / object_size) + 1;
        if (count > max_objects) return;
        for (int i = 0; i < count; i++) {
            fn(array + 0x10 + (uint32_t)i * object_size);
        }
    }

    // A shown cell within `radius` of a point.
    bool shown_near(const float w[3], float radius) {
        const int x0 = cell_of(w[0] - radius), x1 = cell_of(w[0] + radius);
        const int y0 = cell_of(w[1] - radius), y1 = cell_of(w[1] + radius);
        const int z0 = cell_of(w[2] - radius), z1 = cell_of(w[2] + radius);
        for (int z = z0; z <= z1; z++) for (int y = y0; y <= y1; y++) for (int x = x0; x <= x1; x++) {
            if (shown(x, y, z)) return true;
        }
        return false;
    }

    struct EggSeen {
        float pos[3];
        float vel[3];
        uint16_t model;
    };
    // Each egg in flight by its marker (as damage_mods.cpp keys them): where it was last tick and how fast it went.
    std::unordered_map<uint32_t, EggSeen> eggs_seen;
    constexpr float egg_step = 9.0f;   // half a cell

    // Only the special eggs dig (L, 2026-11-13: "normal eggs shouldn't destruct, need special eggs"): grenade,
    // clockwork and proximity eggs blow wide holes, fire eggs melt ice and snow, golden and ice eggs chip. A blue egg
    // stops at a shown cell as at a wall and breaks nothing but sand (L, 2026-11-13: "blue egg can destroy sand").
    void egg_blow(uint8_t* rdram, recomp_context* ctx, uint16_t model, const float at[3], const float from[3]) {
        Breaks b;
        if (model == egg_blue) b = strike(rdram, ctx, from, at, 26.0f, 1, false, at[1] - 60.0f, Sand);
        else if (model == egg_grenade || model == egg_clockwork || model == egg_proximity) b = strike(rdram, ctx, from, at, 85.0f, 4, false, at[1] - 60.0f);
        else if (model == egg_fire) b = strike(rdram, ctx, from, at, 34.0f, 2, true, at[1] - 60.0f);
        else if (model == egg_golden) b = strike(rdram, ctx, from, at, 34.0f, 3, false, at[1] - 60.0f);
        else b = strike(rdram, ctx, from, at, 26.0f, 2, false, at[1] - 60.0f);   // ice
        sound_for(rdram, ctx, b);
        if (log_on() && b.reached) fprintf(stderr, "[voxels] egg %04X: %d broke, %d cracked\n", model, b.count, b.cracked);
    }

    // An egg that reaches a shown cell is removed there and strikes it. An egg that is gone since last tick met the
    // level (or blew up): it strikes where it was going.
    void eggs(uint8_t* rdram, recomp_context* ctx, float dt) {
        std::unordered_map<uint32_t, EggSeen> now;
        std::vector<std::pair<uint32_t, uint16_t>> removed;
        std::vector<std::array<float, 6>> removed_at;   // where, then where from
        std::unordered_set<uint32_t> removed_markers;
        for_each_object(rdram, [&](uint32_t object) {
            const uint32_t marker = read_word(rdram, object);
            if (!valid_ptr(marker)) return;
            const uint16_t model = (uint16_t)read_half(rdram, marker + marker_model);
            if (model != egg_blue && model != egg_fire && model != egg_ice && model != egg_grenade && model != egg_clockwork &&
                model != egg_golden && model != egg_proximity) {
                return;
            }
            // Bit 2 of +0x65: removed, waiting for the game to pack the array.
            if ((read_byte(rdram, object + 0x65) & 0x04) != 0) return;
            EggSeen e{};
            e.model = model;
            for (int c = 0; c < 3; c++) e.pos[c] = read_float(rdram, object + object_pos + 4 * c);
            for (float v : e.pos) if (!std::isfinite(v)) return;
            float from[3] = { e.pos[0], e.pos[1], e.pos[2] };
            const auto last = eggs_seen.find(marker);
            if (last != eggs_seen.end()) {
                const float d3[3] = { e.pos[0] - last->second.pos[0], e.pos[1] - last->second.pos[1], e.pos[2] - last->second.pos[2] };
                // (A jump of more than 600 is a new egg in an old marker's place, not one egg's flight.)
                if (length3(d3) < 600.0f) {
                    for (int c = 0; c < 3; c++) {
                        from[c] = last->second.pos[c];
                        e.vel[c] = dt > 0.0f ? d3[c] / dt : 0.0f;
                    }
                }
            }
            const float span[3] = { e.pos[0] - from[0], e.pos[1] - from[1], e.pos[2] - from[2] };
            const int steps = std::max(1, (int)std::ceil(length3(span) / egg_step));
            for (int k = 1; k <= steps && !world.cut.empty(); k++) {
                const float t = (float)k / steps;
                const float q[3] = { from[0] + span[0] * t, from[1] + span[1] * t, from[2] + span[2] * t };
                if (shown_near(q, 12.0f)) {
                    removed_markers.insert(marker);
                    removed.emplace_back(object, model);
                    removed_at.push_back({ q[0], q[1], q[2], from[0], from[1], from[2] });
                    return;
                }
            }
            now[marker] = e;
        });
        // Eggs gone since last tick: they met the level's surface where they were heading.
        for (const auto& [marker, e] : eggs_seen) {
            if (now.count(marker) || removed_markers.count(marker)) continue;
            const float speed = length3(e.vel);
            if (speed < 50.0f) continue;
            const float dir[3] = { e.vel[0] / speed, e.vel[1] / speed, e.vel[2] / speed };
            const float ahead = std::clamp(speed * dt * 1.5f, 30.0f, 200.0f);
            const float at[3] = { e.pos[0] + dir[0] * ahead, e.pos[1] + dir[1] * ahead, e.pos[2] + dir[2] * ahead };
            egg_blow(rdram, ctx, e.model, at, e.pos);
        }
        eggs_seen.swap(now);
        for (size_t k = 0; k < removed.size(); k++) {
            const float at[3] = { removed_at[k][0], removed_at[k][1], removed_at[k][2] };
            const float from[3] = { removed_at[k][3], removed_at[k][4], removed_at[k][5] };
            egg_blow(rdram, ctx, removed[k].second, at, from);
            GameCall call(rdram, ctx);
            call(func_800FFAB0, removed[k].first);
        }
    }

    // ---------------------------------------------------------------------------------------------------------------
    // Drawing

    void draw_frame(uint8_t* rdram, recomp_context* ctx) {
        if (arena.block == 0) return;
        const uint32_t camera = read_word(rdram, camera_ptr);
        if (!valid_ptr(camera) || !tooie::gfx_budget::room_for_extras(rdram)) return;
        const float cam[3] = { read_float(rdram, camera + 0), read_float(rdram, camera + 4), read_float(rdram, camera + 8) };
        for (float v : cam) if (!std::isfinite(v)) return;
        if (world.cut_changed) publish_cuts();
        if (world.chunks.empty() && debris.empty()) return;

        // Chunks that changed, at most a few a frame. One that found the arena full waits a second before it tries again.
        int rebuilt = 0;
        for (auto& [key, cp] : world.chunks) {
            Chunk& c = *cp;
            if (!c.dirty || frame_counter < c.retry_after) continue;
            if (rebuilt >= 8) break;
            if (!build_mesh(rdram, c)) c.retry_after = frame_counter + 60;
            rebuilt++;
        }

        const uint32_t slot = arena.frames + (frame_counter % frame_slots) * frame_slot_bytes;
        // Matrices from the end of the slot down, commands from the start up.
        // The last 24 bytes below the matrices are kept for the closing commands.
        constexpr uint32_t tail_bytes = 24;
        uint32_t mtx_at = slot + frame_slot_bytes;
        Writer w{ rdram, slot, slot + frame_slot_bytes - tail_bytes };
        w.put(op_pipesync, 0);
        w.put(rt64_hook_word0, rt64_enable_word1);
        w.put(0xD9000000, 0x00000001 | 0x00000004 | 0x00000400 | 0x00200000);   // z-buffer, shade, cull back, smooth
        w.put(0xE3000A01, 0x00000000);   // one cycle
        w.put(0xE3000C00, 0x00080000);   // perspective texture correction
        w.put(0xE3001001, 0x00000000);   // no palette
        w.put(0xE3001201, 0x00002000);   // bilinear
        w.put(0xE2001E01, 0x00000000);   // no alpha compare
        w.put(0xE200001C, 0x00552078);   // opaque, z-buffered surface
        // The colour combiner, (a - b) x c + d for colour and alpha, both cycles.
        auto cc = [](uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t aa, uint32_t ab, uint32_t ac, uint32_t ad, uint32_t* w0, uint32_t* w1) {
            *w0 = 0xFC000000 | ((a & 0xF) << 20) | ((c & 0x1F) << 15) | ((aa & 7) << 12) | ((ac & 7) << 9) | ((a & 0xF) << 5) | (c & 0x1F);
            *w1 = ((b & 0xF) << 28) | ((b & 0xF) << 24) | ((aa & 7) << 21) | ((ac & 7) << 18) | ((d & 7) << 15) |
                ((ab & 7) << 12) | ((ad & 7) << 9) | ((d & 7) << 6) | ((ab & 7) << 3) | (ad & 7);
        };
        // The faces carry the level's own textures (each chunk's list loads them): TEXEL0 x SHADE, texture on.
        {
            uint32_t w0, w1;
            cc(1, 15, 4, 7, 7, 7, 7, 4, &w0, &w1);
            w.put(w0, w1);
            w.put(0xD7000002, 0xFFFFFFFF);
        }

        // Each draw is a matrix (64 bytes) and four commands (32), so a matrix is only taken while both fit.
        auto put_matrix = [&](const float m[4][4]) -> uint32_t {
            if (mtx_at - 64 < w.at + 32 + tail_bytes) return 0;
            mtx_at -= 64;
            w.end = mtx_at - tail_bytes;
            write_matrix(rdram, mtx_at, m);
            return mtx_at;
        };

        int drawn = 0;
        // Each chunk's matrix, kept for the cracked pass.
        std::vector<std::pair<const Chunk*, uint32_t>> placed;
        for (auto& [key, cp] : world.chunks) {
            const Chunk& c = *cp;
            if (c.mesh_dl == 0 && c.crack_dl == 0) continue;
            // (One cell before the chunk's corner: its vertices are a cell in, so no chunk's matrix is the identity,
            // which RT64 would take for the level's own geometry and cut away.)
            const float o[3] = { (c.cx * chunk_n - 1) * vs, (c.cy * chunk_n - 1) * vs, (c.cz * chunk_n - 1) * vs };
            const float dx = o[0] - cam[0], dy = o[1] - cam[1], dz = o[2] - cam[2];
            if (dx * dx + dy * dy + dz * dz > 9000.0f * 9000.0f) continue;
            float m[4][4] = {
                { 1.0f, 0.0f, 0.0f, 0.0f },
                { 0.0f, 1.0f, 0.0f, 0.0f },
                { 0.0f, 0.0f, 1.0f, 0.0f },
                { o[0], o[1], o[2], 1.0f },
            };
            if (matrix_relative) {
                for (int k = 0; k < 3; k++) m[3][k] -= cam[k];
            }
            const uint32_t mtx = put_matrix(m);
            if (mtx == 0) break;
            if (!w.put(ex_matrix_group, 0x56000000u | (uint32_t)(hash32((uint32_t)key ^ (uint32_t)(key >> 32)) & 0xFFFFFF))) break;
            if (!w.put(group_params(0, component_interpolate), 0)) break;
            if (!w.put(op_mtx_modelview_load, phys(mtx))) break;
            if (c.mesh_dl != 0 && !w.put(op_dl, phys(c.mesh_dl))) break;
            if (c.crack_dl != 0) placed.emplace_back(&c, mtx);
            drawn++;
        }
        // The debris stones (plain shade, no texture), then the cracked texture and the cracked faces.
        {
            uint32_t w0, w1;
            cc(15, 15, 31, 4, 7, 7, 7, 4, &w0, &w1);
            w.put(op_pipesync, 0);
            w.put(w0, w1);
            w.put(0xD7000000, 0);
        }
        uint32_t crack_w0, crack_w1;
        cc(1, 15, 4, 7, 7, 7, 7, 4, &crack_w0, &crack_w1);   // (TEXEL0 - 0) x SHADE + 0
        if (!placed.empty() && w.put(op_pipesync, 0) && w.put(crack_w0, crack_w1) && w.put(0xD7000002, 0xFFFFFFFF) &&
            w.put(0xFD900000, phys(arena.texture + texture_bytes)) &&
            w.put(0xF5900000, 0x07000000) && w.put(0xE6000000, 0) && w.put(0xF3000000, 0x071FF200) && w.put(op_pipesync, 0) &&
            w.put(0xF5880800, (5u << 14) | (5u << 4)) && w.put(0xF2000000, 0x0007C07C)) {
            for (const auto& [c, mtx] : placed) {
                const uint64_t id = pack3(c->cx, c->cy, c->cz);
                if (!w.put(ex_matrix_group, 0x58000000u | (uint32_t)(hash32((uint32_t)id ^ (uint32_t)(id >> 32)) & 0xFFFFFF))) break;
                if (!w.put(group_params(0, component_interpolate), 0)) break;
                if (!w.put(op_mtx_modelview_load, phys(mtx))) break;
                if (!w.put(op_dl, phys(c->crack_dl))) break;
            }
        }
        // Texturing off again; the game's models set the rest themselves.
        write_word(rdram, w.at, op_pipesync); write_word(rdram, w.at + 4, 0); w.at += 8;
        write_word(rdram, w.at, 0xD7000000); write_word(rdram, w.at + 4, 0); w.at += 8;
        write_word(rdram, w.at, op_enddl); write_word(rdram, w.at + 4, 0); w.at += 8;

        // One call into the game's list.
        GameCall call(rdram, ctx);
        const uint32_t gfx = (uint32_t)call(func_800A7180);
        if (!valid_ptr(gfx) || !valid_ptr(read_word(rdram, gfx))) return;
        const uint32_t head = read_word(rdram, gfx);
        write_word(rdram, head, op_dl);
        write_word(rdram, head + 4, phys(slot));
        write_word(rdram, gfx, head + 8);
        frame_counter++;
        release_retired();
        static float last_frame_log = -10.0f;
        if (log_on() && game_time - last_frame_log >= 2.0f) {
            last_frame_log = game_time;
            fprintf(stderr, "[voxels] frame: %d chunks drawn, %zu cut cells, %zu debris, list %u bytes\n", drawn, world.cut.size(),
                debris.size(), w.at - slot);
        }
    }

    // ---------------------------------------------------------------------------------------------------------------
    // Map changes and switching off

    // Leaving the map, or switching off: every cell goes (L, 2026-11-13: reset on level exit), and RT64 is told.
    void reset_world() {
        drop_meshes();
        const bool had_cuts = !world.cut.empty();
        world = World{};
        colour_ask = ColourAsk{};
        debris.clear();
        eggs_seen.clear();
        if (had_cuts) publish_cuts();
    }

    // Switched off: nothing more is drawn at once, and the arena goes back to the heap some frames later, once RT64
    // has drawn the last frames that used it.
    uint32_t free_block = 0;
    uint16_t free_map = 0xFFFF;
    int free_countdown = 0;

    void turn_off(uint8_t* rdram) {
        reset_world();
        if (arena.block != 0 && arena.map == tooie::debug::current_map(rdram)) {
            free_block = arena.block;
            free_map = arena.map;
            free_countdown = 20;
        }
        arena = Arena{};
    }

    void free_later(uint8_t* rdram, recomp_context* ctx) {
        // A map change in the meantime took the block with the old heap.
        if (free_block != 0 && (tooie::debug::map_change_busy(rdram) || tooie::debug::current_map(rdram) != free_map)) {
            free_block = 0;
            return;
        }
        if (free_block != 0 && --free_countdown <= 0) {
            GameCall call(rdram, ctx);
            call(heap_free, free_block);
            free_block = 0;
        }
    }

    int count_state(uint8_t s) {
        int n = 0;
        for (auto& [key, c] : world.chunks) for (uint8_t v : c->state) n += v == s;
        return n;
    }
}

void tooie::voxel_layer::add_options(recomp::config::Config& graphics) {
    graphics.add_bool_option(option, "Voxel Layer",
        "Lets Banjo dig into the levels' ground and walls. The level looks and plays as it "
        "always did until he strikes it; then the ground behind the surface (1 to 2 m deep, 2 to 4 m in sand and dirt) "
        "gives way: sand and dirt at one blow, anything else cracks on the first and breaks out on the next. Claw "
        "swipes and rolls dig soft ground; stone needs the Rat-a-tat Rap or stronger, rock the Beak Barge, Beak "
        "Buster or Bill Drill. Of the eggs only the special ones dig: grenade, clockwork and proximity eggs blow "
        "holes, fire eggs melt ice, blue eggs dig only sand. Nothing near water or metal breaks. Holes fill back in when he leaves the level.",
        false);
    graphics.add_number_option(strength_option, "Voxel Strength",
        "How much Banjo breaks with each blow, egg and fall: 100 as made. Higher makes his blows reach further and break "
        "harder ground sooner (at 200 a claw swipe breaks stone); lower takes more blows.",
        25, 400, 25, 0, true, 100);
    graphics.add_number_option(depth_soft_option, "Voxel Depth: Sand and Dirt",
        "How deep the ground behind the level's surface goes, in metres, where the level's ground is soft: sand, dirt, "
        "grass, clay and snow. The depth varies from this to twice it. New ground takes it at once; holes already dug "
        "keep theirs until he leaves the level.",
        0.5, 8, 0.5, 1, false, 2);
    graphics.add_number_option(depth_stone_option, "Voxel Depth: Stone",
        "As above, where the level's ground is stone, sandstone, brick or ice.",
        0.5, 8, 0.5, 1, false, 1);
    graphics.add_number_option(depth_rock_option, "Voxel Depth: Rock",
        "As above, where the level's ground is rock, dark stone, ash rock or gold ore.",
        0.5, 8, 0.5, 1, false, 1);
    for (const std::string* id : { &strength_option, &depth_soft_option, &depth_stone_option, &depth_rock_option }) {
        graphics.add_option_hidden_dependency(*id, option, false);
    }
    // In the WIP tab under its own heading (L, 2026-11-15). The tab is a page of Graphics options, so these save to
    // graphics.json; config.cpp carries the values saved in general.json over once.
    for (const std::string* id : { &option, &strength_option, &depth_soft_option, &depth_stone_option, &depth_rock_option }) {
        recompui::config::set_option_page(*id, tooie::work_in_progress_tab_id);
    }
    recompui::config::set_option_group(option, "Voxel Layer");
    // The Graphics settings keep a change aside until they are saved; saving at once makes it apply the moment it
    // changes, as the other WIP options do.
    for (const std::string* id : { &option, &strength_option, &depth_soft_option, &depth_stone_option, &depth_rock_option }) {
        graphics.add_option_change_callback(*id,
            [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
                if (context == recomp::config::OptionChangeContext::Temporary) {
                    recompui::config::get_graphics_config().save_config();
                }
            });
    }
}

void tooie::voxel_layer::tick(uint8_t* rdram, recomp_context* ctx) {
    const uint32_t now = tooie::game_frame_rate::game_ms();
    const float dt = std::clamp((float)(now - last_game_ms) / 1000.0f, 0.0f, 0.1f);
    last_game_ms = now;
    game_time += dt;

    free_later(rdram, ctx);
    const bool on = option_on();
    if (!on) {
        if (was_on) {
            turn_off(rdram);
            was_on = false;
        }
        return;
    }
    // Switched back on before the old arena went back: it is freed now, and a new one taken below.
    if (free_block != 0) {
        free_countdown = 0;
        free_later(rdram, ctx);
    }
    was_on = true;

    if (tooie::debug::map_change_busy(rdram)) {
        return;
    }
    const uint16_t map = tooie::debug::current_map(rdram);
    if (map != current_map || (arena.block != 0 && arena.map != map)) {
        // Leaving a map: its cells go, and its meshes with the old heap.
        reset_world();
        arena = Arena{};
        current_map = map;
        last_state = 0;
    }
    if (!map_allowed(map) || !arena_ready(rdram, ctx)) return;
    rdram_now = rdram;
    last_dt = dt;
    read_sliders();
    take_colour();
    watch_bounds(rdram, ctx);
    attack(rdram, ctx);
    eggs(rdram, ctx, dt);
    step_debris(dt);
}

void tooie::voxel_layer::draw(uint8_t* rdram, recomp_context* ctx) {
    if (!was_on || arena.block == 0 || tooie::debug::map_change_busy(rdram)) return;
    if (tooie::debug::current_map(rdram) != current_map) return;
    collide(rdram);
    draw_frame(rdram, ctx);
}

std::string tooie::voxel_layer::console(uint8_t* rdram, recomp_context* ctx, const std::vector<std::string>& args) {
    const std::string what = args.empty() ? "info" : args[0];
    char text[320];
    if (what == "on" || what == "off") {
        recomp::config::Config& graphics = recompui::config::get_graphics_config();
        graphics.update_option_value(option, what == "on");
        graphics.save_config();
        return std::string("Voxel Layer ") + what;
    }
    if (what == "info") {
        size_t free_bytes = 0;
        for (auto& [o, s] : arena.free_list) free_bytes += s;
        snprintf(text, sizeof(text), "Voxel Layer %s, map %03X%s: %zu chunks, %zu columns, %d solid, %d bedrock, %d dug, %zu cut, "
            "%zu debris; arena %u KB, %zu KB free%s; %u floor answers, %u contacts dropped",
            option_on() ? "on" : "off", current_map, map_allowed(current_map) ? "" : " (not dug: a cutscene)",
            world.chunks.size(), world.columns.size(), count_state(Solid), count_state(Bedrock), count_state(Dug), world.cut.size(),
            debris.size(), arena.size / 1024, free_bytes / 1024, arena.failed ? " (no heap room)" : "", floor_hits, contacts_dropped);
        return text;
    }
    if (!option_on()) return "ERR the Voxel Layer is off: voxel on";
    if (what == "hit" || what == "dig") {
        // hit: a blow 60 ahead of Banjo at his chest; dig: one down at his feet.
        Player pl;
        if (!read_player(rdram, pl)) return "ERR there is no player yet";
        if (!arena_ready(rdram, ctx)) return "ERR no room in the game heap";
        const int power = args.size() >= 2 ? std::atoi(args[1].c_str()) : 3;
        const float radius = args.size() >= 3 ? (float)std::atof(args[2].c_str()) : 40.0f;
        const float fwd[3] = { std::sin(pl.yaw * deg), 0.0f, std::cos(pl.yaw * deg) };
        const bool down = what == "dig";
        const float origin[3] = { pl.pos[0], pl.pos[1] + 60.0f, pl.pos[2] };
        float at[3] = { pl.pos[0] + (down ? 0.0f : fwd[0] * 60.0f), pl.pos[1] + (down ? -10.0f : 55.0f),
            pl.pos[2] + (down ? 0.0f : fwd[2] * 60.0f) };
        // hit ... wall: the blow lands on the first wall straight ahead within 1000 (for testing from afar).
        if (!down && args.size() >= 4 && args[3] == "wall") {
            const float far[3] = { origin[0] + fwd[0] * 1000.0f, origin[1], origin[2] + fwd[2] * 1000.0f };
            float hit[3], n[3];
            if (!line_test(rdram, ctx, origin, far, kind_solid, hit, n, nullptr)) return "ERR no wall within 1000 ahead of Banjo";
            for (int c = 0; c < 3; c++) at[c] = hit[c];
        }
        const auto started = std::chrono::steady_clock::now();
        const Breaks b = strike(rdram, ctx, origin, at, radius, power, false, pl.pos[1]);
        const double ms = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - started).count();
        sound_for(rdram, ctx, b);
        snprintf(text, sizeof(text), "%s with power %d, radius %.0f: %s; %d broke, %d cracked, %d too hard (%.1f ms)", what.c_str(), power, radius,
            b.kept ? "met the level near water or metal (kept)" : b.reached ? "met the level" : "met nothing", b.count, b.cracked, b.clinks, ms);
        return text;
    }
    if (what == "surface") {
        // The surface type of the ground under Banjo (flags & 0x1F00), for matching surface types to materials.
        Player pl;
        if (!read_player(rdram, pl)) return "ERR there is no player yet";
        // surface ahead: the wall straight in front of him (within 1000) instead.
        const bool ahead = args.size() >= 2 && args[1] == "ahead";
        const float fwd[3] = { std::sin(pl.yaw * deg), 0.0f, std::cos(pl.yaw * deg) };
        const float from[3] = { pl.pos[0], pl.pos[1] + (ahead ? 60.0f : 50.0f), pl.pos[2] };
        const float to[3] = { pl.pos[0] + (ahead ? fwd[0] * 1000.0f : 0.0f), pl.pos[1] + (ahead ? 60.0f : -300.0f),
            pl.pos[2] + (ahead ? fwd[2] * 1000.0f : 0.0f) };
        float hit[3], n[3];
        uint32_t flags = 0;
        if (!line_test(rdram, ctx, from, to, kind_solid, hit, n, &flags)) return ahead ? "ERR no wall within 1000 ahead" : "ERR no ground under Banjo";
        snprintf(text, sizeof(text), "%s at %.0f %.0f %.0f, flags %08X, surface type %u (%s)", ahead ? "wall" : "ground", hit[0], hit[1], hit[2],
            flags, (flags & surface_type_mask) >> 8,
            (flags & no_dig_flags) ? "never dug: water or the like" : is_metal(flags) ? "metal: never dug" : "dug");
        return text;
    }
    if (what == "metal") {
        // voxel metal <type> [off]: a surface type that is metal (unbreakable, and what is near it); no type: the list.
        if (args.size() >= 2) {
            const unsigned type = (unsigned)std::strtoul(args[1].c_str(), nullptr, 0);
            if (type > 31) return "ERR a surface type is 0 to 31 (voxel surface shows the one under Banjo)";
            if (args.size() >= 3 && args[2] == "off") metal_types &= ~(1u << type); else metal_types |= 1u << type;
        }
        std::string list;
        for (unsigned t = 0; t < 32; t++) if ((metal_types >> t) & 1u) list += " " + std::to_string(t);
        return "metal surface types:" + (list.empty() ? std::string(" none") : list);
    }
    if (what == "debris") {
        // One still stone cube 120 ahead of Banjo at his chest, for 8 s: for checking that debris is drawn.
        Player pl;
        if (!read_player(rdram, pl)) return "ERR there is no player yet";
        const float size = args.size() >= 2 ? (float)std::atof(args[1].c_str()) : 30.0f;
        Debris d{};
        d.pos[0] = pl.pos[0] + std::sin(pl.yaw * deg) * 120.0f;
        d.pos[1] = pl.pos[1] + 60.0f;
        d.pos[2] = pl.pos[2] + std::cos(pl.yaw * deg) * 120.0f;
        d.ang[0] = 30.0f; d.ang[1] = 20.0f;
        d.size = size;
        d.life = 8.0f;
        d.ground = d.pos[1] - 1.0f;
        d.mat = Stone;
        d.id = ++debris_serial;
        debris.push_back(d);
        snprintf(text, sizeof(text), "a still cube of size %.0f at %.0f %.0f %.0f for 8 s", size, d.pos[0], d.pos[1], d.pos[2]);
        return text;
    }
    if (what == "restore") {
        reset_world();
        return "this map's ground and walls are put back as they were";
    }
    if (what == "sound") {
        if (args.size() < 2) return "ERR voxel sound <id> [material]";
        const uint32_t id = (uint32_t)std::strtoul(args[1].c_str(), nullptr, 16);
        Player pl;
        if (!read_player(rdram, pl)) return "ERR there is no player yet";
        if (args.size() >= 3) {
            const Mat m = mat_by_name(args[2]);
            if (m == Empty) return "ERR no such material";
            mats[m].sound = (uint16_t)id;
        }
        play_sound(rdram, ctx, id, pl.pos, 1.0f, 0.8f);
        snprintf(text, sizeof(text), "played sound %04X%s", id, args.size() >= 3 ? (" and set it for " + args[2]).c_str() : "");
        return text;
    }
    if (what == "voidscan") {
        // Every visible point of the level's surface the cut takes away, by the same rule as the shader
        // (rt64-ext/src/shaders/VoxelCuts.hlsli), over the cut cells and the cells round them: the line of sight from
        // the camera, followed on through the hole cell by cell. It is covered when it meets a solid cell from open
        // space (a shown cell's face) or passes from a dug cell into open air (the backstop face there). It is a void
        // when it starts inside a solid cell (the level's surface is gone over a cell nothing faces the camera in),
        // runs into cells nothing is drawn for (not filled yet) or out past six cells. Each void gets a magenta
        // marker for 10 s.
        const uint32_t camera = read_word(rdram, camera_ptr);
        if (!valid_ptr(camera)) return "ERR no camera";
        const float cam[3] = { read_float(rdram, camera + 0), read_float(rdram, camera + 4), read_float(rdram, camera + 8) };
        auto field = [](uint64_t v) { int32_t f = (int32_t)(v & 0x1FFFFF); return (f & 0x100000) ? f - 0x200000 : f; };
        // The shader's rule: the cell a cell's size behind the point (either side) is cut, and so much of the four
        // cells round it that the blend reaches 0.65.
        auto row_cut = [&](const float w[3], int axis, float side) {
            float q[3] = { w[0], w[1], w[2] };
            q[axis] += side * vs;
            const int t1 = (axis + 1) % 3, t2 = (axis + 2) % 3;
            int cell[3];
            for (int c = 0; c < 3; c++) cell[c] = (int)std::floor(q[c] / vs);
            if (!is_cut(cell[0], cell[1], cell[2])) return 0.0f;
            const float g1 = q[t1] / vs - 0.5f, g2 = q[t2] / vs - 0.5f;
            const float f1 = std::floor(g1), f2 = std::floor(g2);
            const float w1 = g1 - f1, w2 = g2 - f2;
            float sum = 0.0f;
            for (int k = 0; k < 4; k++) {
                const int o1 = k & 1, o2 = k >> 1;
                cell[t1] = (int)f1 + o1;
                cell[t2] = (int)f2 + o2;
                const float weight = (o1 ? w1 : 1.0f - w1) * (o2 ? w2 : 1.0f - w2);
                if (is_cut(cell[0], cell[1], cell[2])) sum += weight;
            }
            return sum;
        };
        auto surface_cut = [&](const float w[3], int axis) { return std::max(row_cut(w, axis, -1.0f), row_cut(w, axis, 1.0f)) >= 0.75f; };
        int visible = 0, voids = 0, markers = 0;
        int why[3] = { 0, 0, 0 };   // what a void ran into: cells not filled, too far, inside a solid cell
        std::unordered_set<uint64_t> seen;
        for (uint64_t key : world.cut) {
            const int cx = field(key >> 42), cy = field(key >> 21), cz = field(key);
            const Chunk* ck = chunk_at(cx, cy, cz, false);
            if (ck == nullptr) continue;
            const int ci = local_index(*ck, cx, cy, cz);
            const int a = dir_axis(ck->dir[ci]), sgn = dir_sign(ck->dir[ci]);
            const float surface = ck->surface[ci];
            const int t1 = (a + 1) % 3, t2 = (a + 2) % 3;
            const int c3[3] = { cx, cy, cz };
            // A 4 x 4 grid of points on the level's surface over this cell and the eight round it.
            for (int u = 0; u < 12; u++) for (int v = 0; v < 12; v++) {
                float pt[3];
                pt[a] = surface;
                pt[t1] = (c3[t1] - 1) * vs + (u + 0.5f) * vs / 4.0f;
                pt[t2] = (c3[t2] - 1) * vs + (v + 0.5f) * vs / 4.0f;
                const uint64_t place = pack3((int)std::floor(pt[0] * 4.0f / vs), (int)std::floor(pt[1] * 4.0f / vs), (int)std::floor(pt[2] * 4.0f / vs));
                if (!seen.insert(place).second) continue;
                if (!surface_cut(pt, a)) continue;
                // In front of the camera and in its sight (the level's own test, up to just short of the point).
                const float d[3] = { pt[0] - cam[0], pt[1] - cam[1], pt[2] - cam[2] };
                const float len = length3(d);
                if (len < 30.0f || len > 4000.0f) continue;
                const float dir[3] = { d[0] / len, d[1] / len, d[2] / len };
                if (dir[a] * sgn > -0.05f) continue;   // the surface seen from behind or edge on
                const float near_pt[3] = { pt[0] - dir[0] * 6.0f, pt[1] - dir[1] * 6.0f, pt[2] - dir[2] * 6.0f };
                float hit[3], hn[3];
                if (line_test(rdram, ctx, cam, near_pt, kind_solid, hit, hn, nullptr)) {
                    // Something of the level before it: is that something cut too? (then it doesn't hide the point)
                    if (!contact_in_cut(hit, hn)) continue;
                }
                visible++;
                int kind = 1;   // too far, unless something else is met
                bool covered = false;
                int last = -1;
                for (float t = 1.0f; t < vs * 6.0f; t += 3.0f) {
                    const float q[3] = { pt[0] + dir[0] * t, pt[1] + dir[1] * t, pt[2] + dir[2] * t };
                    const uint8_t st = state_at(cell_of(q[0]), cell_of(q[1]), cell_of(q[2]));
                    if (solid_state(st)) {
                        // Under the surface at once: a whole cell lost its surface, unless the cell is the pile thrown up
                        // round a dig (on top of the ground, drawn all round, so it covers the point).
                        const int qx = cell_of(q[0]), qy = cell_of(q[1]), qz = cell_of(q[2]);
                        const Chunk* qc = chunk_at(qx, qy, qz, false);
                        const bool piled = qc != nullptr && (qc->flags[local_index(*qc, qx, qy, qz)] & cell_piled);
                        if (last == -1 && !piled && !near_dug(qx, qy, qz)) { kind = 2; break; }
                        covered = true;
                        break;
                    }
                    if (st == Air && last == Dug) { covered = true; break; }
                    if (st == Unknown) { kind = 0; break; }
                    last = st;
                }
                if (covered) continue;
                voids++;
                why[kind]++;
                if (markers < 160) {
                    Debris m{};
                    for (int c = 0; c < 3; c++) m.pos[c] = pt[c] + dir[c] * 4.0f;
                    m.size = 5.0f;
                    m.life = 10.0f;
                    m.ground = -1e9f;
                    m.mat = Marker;
                    m.id = ++debris_serial;
                    debris.push_back(m);
                    markers++;
                }
            }
        }
        snprintf(text, sizeof(text), "voidscan: %d cut points in sight, %d see into a void (%d into cells not filled, %d past six cells, "
            "%d where a whole cell lost its surface); magenta markers at %d of them for 10 s", visible, voids, why[0], why[1], why[2], markers);
        return text;
    }
    if (what == "void") {
        // L, 2026-11-13: "easier to make the whole sky magenta". The scene effects pass paints every pixel nothing was
        // drawn on, so a gap a hole opens shows magenta like the sky round it.
        const bool on = args.size() >= 2 ? args[1] != "off" : !tooie::effect_views::void_view_on();
        tooie::effect_views::void_view(on);
        return std::string("void view ") + (on ? "on: the sky, and any gap a hole lets the camera see through, is magenta" : "off");
    }
    if (what == "mtx") {
        if (args.size() >= 2) matrix_relative = args[1] != "abs";
        return std::string("voxel matrices: ") + (matrix_relative ? "rel (place minus camera)" : "abs (world place)");
    }
    if (what == "flip") {
        flip_winding = !flip_winding;
        drop_meshes();
        if (arena.block != 0) make_texture_and_cubes(rdram);
        return std::string("triangle winding ") + (flip_winding ? "flipped" : "normal");
    }
    return "ERR voxel [on|off|info|hit [power] [radius] [wall]|dig [power] [radius]|surface [ahead]|metal [type [off]]|restore|sound <id> [material]|debris [size]]";
}

// banjotooie.us.toml: the entry of func_800F5008, which draws the players, in the 3D scene of each frame.
extern "C" void tooie_voxel_draw(uint8_t* rdram, recomp_context* ctx) {
    tooie::voxel_layer::draw(rdram, ctx);
}

// The game's floor test, func_800C6A7C: its entry and its exit.
extern "C" void tooie_voxel_floor_enter(uint8_t* rdram, recomp_context* ctx) {
    floor_enter(rdram, ctx);
}
extern "C" void tooie_voxel_floor(uint8_t* rdram, recomp_context* ctx) {
    floor_exit(rdram, ctx);
}

// The sphere push, func_800C6C94: its entry, after each provider, its exit.
extern "C" void tooie_voxel_push_enter(uint8_t* rdram, recomp_context* ctx) {
    push_enter(rdram, ctx);
}
extern "C" void tooie_voxel_push_provider(uint8_t* rdram, recomp_context* ctx) {
    push_after_provider(rdram, ctx);
}
extern "C" void tooie_voxel_push_exit(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram; (void)ctx;
    push_exit();
}

// The swept sphere, func_800C6B78: its entry, after each provider, its exit.
extern "C" void tooie_voxel_sweep_enter(uint8_t* rdram, recomp_context* ctx) {
    sweep_enter(rdram, ctx);
}
extern "C" void tooie_voxel_sweep_provider(uint8_t* rdram, recomp_context* ctx) {
    sweep_after_provider(rdram, ctx);
}
extern "C" void tooie_voxel_sweep_exit(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram; (void)ctx;
    sweep_exit();
}
