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
// 25600 elsewhere. Objects still load by grid cell as before; only models
// that are already loaded stay drawn further away.

#include <algorithm>

#include "recomp.h"
#include "recompui/config.h"
#include "tooie_game.h"
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

extern "C" void tooie_model_draw_distance(uint8_t* rdram, recomp_context* ctx) {
    if (!enabled()) {
        return;
    }
    int32_t game = (int32_t)ctx->r2;
    if (game <= 0) {
        return;
    }
    ctx->r2 = (int32_t)std::max<int32_t>(game, extended_distance(MEM_HU(0, current_map_addr)));
}
