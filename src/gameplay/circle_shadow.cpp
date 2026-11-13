// Graphics > Demake > Simple Circle Shadow.
//
// The game draws the player's shadow in func_800A6DAC: the flattened shadow model (func_800A6B24), or,
// when player+0x64 bit 20 is set, its own round blob (func_800A5DB0: model 0x637 laid on the floor under
// the player, the blob it gives most other characters). With the option on, the blob is drawn for the
// player every time and the flattened model is skipped. Nothing is built here: it is the game's own
// shadow, so it behaves as it does for those characters.
//
// Photo mode's Hide Banjo takes his shadow away with him: while it is on, neither is drawn here.

#include <variant>

#include "recomp.h"
#include "funcs.h"
#include "recompui/config.h"
#include "tooie_circle_shadow.h"
#include "tooie_hooks.h"
#include "tooie_photo_mode.h"

bool tooie::circle_shadow::enabled() {
    try {
        return std::get<bool>(recompui::config::get_config(recompui::config::graphics::id).get_option_value(option));
    } catch (...) {
        return false;
    }
}

// Hooked in func_800A6DAC where it would draw the flattened model: $s0 is the player.
extern "C" int tooie_circle_shadow_draw(uint8_t* rdram, recomp_context* ctx) {
    if (tooie::photo_mode::banjo_hidden()) {
        return 1;
    }
    if (!tooie::circle_shadow::enabled()) {
        return 0;
    }
    ctx->r4 = ctx->r16;
    func_800A5DB0(rdram, ctx);
    return 1;
}
