// Extended draw distance (handoff 4.26).
//
// Each map sets a halfword at D_8012844C (1300 in Spiral Mountain, 1500 in
// Mayahem Temple), returned by func_800BDC5C. It is the size of the world grid
// cells objects are streamed in by (func_800D2F44 works out a cell's centre as
// index * size + size / 2), so it must not be changed: raising it moved every
// cell, and feathers, eggs and enemies vanished (L, 2026-10-13).
//
// func_800D2F20 returns that size times 4, and the scene draw (func_800BFAD0)
// and the actor draw (func_80101970) pass it to func_800DF428 as the model
// draw distance (D_8012C82C, checked in func_800DE498). banjotooie.us.toml
// hooks both callers just after func_800D2F20 returns, and this file raises
// the returned value in $v0 to the per-map value from retroben's Xenia "Draw
// Distance Hack": 10400 in Terrydactyland (0x112) and Hailfire Peaks' icy side
// (0x128), 12800 on the lava side (0x127), 21504 in Cloud Cuckooland (0x136),
// 25600 elsewhere. Actors with a draw distance of their own (Doubloons) are
// scaled the same way.
//
// Props (notes, eggs, feathers, honeycombs and other placed objects) are kept
// in those grid cells and only drawn for cells near the camera, a second limit
// of the same cell size x 4: func_800D3104 gathers the cells within a radius
// of 4 cells ($f20) and func_800D2F44 drops a cell whose centre is further
// than cell size x 4 (x two constant factors, in $f2). Both are hooked and
// scaled by the same ratio as the model distance, so props reach as far as
// models. Only which cells are drawn changes; the cells stay where they are.

#include <algorithm>
#include <cstring>

#include "recomp.h"
#include "recompui/config.h"
#include "tooie_game.h"
#include "tooie_gfx_budget.h"
#include "tooie_hooks.h"

namespace {
    constexpr gpr current_map_addr = (int32_t)0x80132DC2;

    bool enabled() {
        try {
            return std::get<bool>(recompui::config::get_graphics_config().get_option_value(tooie::draw_distance_option));
        } catch (...) {
            return false;
        }
    }

    int extended_distance(uint16_t map) {
        switch (map) {
            case 0x112: case 0x128: return 10400;
            case 0x127: return 12800;
            case 0x136: return 21504;
            default: return 25600;
        }
    }
}

namespace {
    constexpr gpr cell_size_addr = (int32_t)0x8012844C;

    // How much further the extended distance reaches than the game's own
    // (cell size x 4), or 1 when the option is off.
    float distance_scale(uint8_t* rdram) {
        // Not while the frame's drawing memory is nearly full (gfx_budget.cpp).
        if (!enabled() || !tooie::gfx_budget::room_for_extras(rdram)) {
            return 1.0f;
        }
        int32_t cell = MEM_H(0, cell_size_addr);
        if (cell <= 0) {
            return 1.0f;
        }
        return std::max(1.0f, (float)extended_distance(MEM_HU(0, current_map_addr)) / (cell * 4.0f));
    }
}

extern "C" void tooie_cell_draw_radius(uint8_t* rdram, recomp_context* ctx) {
    ctx->f20.fl *= distance_scale(rdram);
}

extern "C" void tooie_cell_draw_distance(uint8_t* rdram, recomp_context* ctx) {
    ctx->f2.fl *= distance_scale(rdram);
}

// Actors whose data sets their own draw distance (func_80101970 passes it instead of
// func_800D2F20's; Jolly Roger's Doubloons use 3000) reach as much further as the rest,
// up to the map's extended distance.
extern "C" void tooie_actor_draw_distance(uint8_t* rdram, recomp_context* ctx) {
    const float own = ctx->f12.fl;
    const float scale = distance_scale(rdram);
    if (own <= 0.0f || scale <= 1.0f) {
        return;
    }
    ctx->f12.fl = std::max(own, std::min(own * scale, (float)extended_distance(MEM_HU(0, current_map_addr))));
}

// Actors that draw themselves through func_80101808 without func_80101970 (Sabreman, frozen in Icy Side's ice;
// the ice is drawn as a part of his draw, so it goes with him) never set the model draw distance, so D_8012C82C
// still holds the game's default (D_80125D60, 30000). func_800DE498 treats a model drawn with exactly that
// default as unimportant: past 4000 units it cuts the distance down to its own size x 50 (about 5000 for
// Sabreman), so he and his ice popped out far nearer than everything else. Give such a draw the extended
// distance like every other actor's, which skips that size rule. Never lowers a larger own distance
// (func_80101970's) except the default itself.
extern "C" void tooie_actor_draw_reach(uint8_t* rdram, recomp_context* ctx) {
    if (!enabled() || !tooie::gfx_budget::room_for_extras(rdram)) {
        return;
    }
    constexpr gpr model_distance_addr = (int32_t)0x8012C82C;
    constexpr gpr default_distance_addr = (int32_t)0x80125D60;
    const float extended = (float)extended_distance(MEM_HU(0, current_map_addr));
    const int32_t bits = MEM_W(0, model_distance_addr);
    float current;
    std::memcpy(&current, &bits, sizeof(current));
    if (current < extended || bits == MEM_W(0, default_distance_addr)) {
        std::memcpy(&MEM_W(0, model_distance_addr), &extended, sizeof(extended));
    }
}

extern "C" void tooie_model_draw_distance(uint8_t* rdram, recomp_context* ctx) {
    if (!enabled() || !tooie::gfx_budget::room_for_extras(rdram)) {
        return;
    }
    int32_t game = (int32_t)ctx->r2;
    if (game <= 0) {
        return;
    }
    ctx->r2 = (int32_t)std::max<int32_t>(game, extended_distance(MEM_HU(0, current_map_addr)));
}
