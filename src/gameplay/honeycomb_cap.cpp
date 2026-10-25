// Honeycombs Stay (WIP, L 2026-10-25).
//
// The health honeycombs that enemies and breakables drop are chhoney objects (actors 0x22B and 0x22C, models 0x704
// and 0x705). Two things in the overlay (decomp: chhoney) decide how long they last:
// - func_80800244 (the object's init) sets a 20 second timer in the float at +0x28, and func_80800EB0, run first
//   thing every frame by the update (func_80800A5C), counts it down and, when it runs out, makes the comb vanish
//   (func_80089CA8). Combs placed in the world have bit 5 of the word at +0x78 set and are skipped.
// - func_8080046C, on message 0x95 (a comb has appeared), counts the dropped combs in the word at 0x80127194
//   (zeroed with the area, func_80800634 takes one off when a comb goes). From the 11th on it calls func_80800688,
//   which removes the oldest comb (smallest creation stamp at +0x54, found through a list of up to 14).
// With Honeycombs Stay on, the expiry check is skipped, so a comb stays until Banjo takes it, the area is left
// or a newer comb pushes it out, and the limit of 10 (the slti with 0xB at 0x808005FC) becomes Banjo's full health
// for the form he is in (the byte at +2 of his slot in the health table, 0x8011B640, 3 bytes each) plus one.

#include <algorithm>

#include "recomp.h"
#include "funcs.h"
#include "recompui/config.h"
#include "tooie_honeycomb_cap.h"
#include "tooie_rdram.h"

namespace {
    constexpr uint32_t player_pointer = 0x80135490;
    constexpr uint32_t health_table = 0x8011B640;
    constexpr int32_t original_limit = 0xB;

    bool enabled() {
        try {
            return std::get<bool>(recompui::config::get_graphics_config().get_option_value(tooie::honeycomb_cap::option));
        } catch (...) {
            return false;
        }
    }

    // Calls a game function on a copy of the hook's context, below the caller's stack frame.
    int32_t call_game(uint8_t* rdram, recomp_context* ctx, void (*func)(uint8_t*, recomp_context*), uint32_t a0) {
        recomp_context saved = *ctx;
        ctx->r29 = (int32_t)((((uint32_t)ctx->r29 - 0x100) & ~0xFu));
        ctx->r4 = (uint64_t)(int64_t)(int32_t)a0;
        func(rdram, ctx);
        const int32_t value = (int32_t)ctx->r2;
        *ctx = saved;
        return value;
    }
}

// func_80800EB0 entry (chhoney's expiry check): 1 skips it, so the comb doesn't run out.
extern "C" int tooie_honeycomb_no_expire(uint8_t* rdram, recomp_context* ctx) {
    return enabled() ? 1 : 0;
}

// func_8080046C, just before the test of the new comb's number against the limit: the first number that removes
// the oldest comb.
extern "C" int tooie_honeycomb_limit(uint8_t* rdram, recomp_context* ctx) {
    if (!enabled()) {
        return original_limit;
    }
    const uint32_t player = tooie::rdram::read_word(rdram, player_pointer);
    if (!tooie::rdram::valid_ptr(player)) {
        return original_limit;
    }
    const int32_t form = call_game(rdram, ctx, func_800A3274, player);
    const int32_t slot = call_game(rdram, ctx, func_800D4DD0, (uint32_t)form);
    if (slot < 0 || slot > 32) {
        return original_limit;
    }
    const int32_t full = rdram[(health_table + 3 * (uint32_t)slot + 2 - 0x80000000u) ^ 3];
    return std::clamp(full, 1, 13) + 1;
}
