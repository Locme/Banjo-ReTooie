// HD shadows (handoff 4.51), Graphics tab, off by default.
//
// The player's shadow is the player's model flattened onto the floor and
// drawn into an offscreen 8-bit buffer (func_800A6250, called from the player
// shadow component func_800A6DAC). It does not use the model on screen:
// _bapreload_entrypoint_1 gives each form a simpler shadow model (0x853 for
// Banjo-Kazooie), which func_800D674C loads into the frame at $sp+0x1C8, next
// to the model on screen at $sp+0x1C4 (func_80092B04). When the two are the
// same, func_800A6250 already draws the on-screen model with its pose, so the
// hook just after both are known copies the on-screen model over the shadow
// model while the option is on. It is read every frame, so it applies at once.

#include <cstdio>
#include <cstdlib>
#include <variant>

#include "recomp.h"
#include "recompui/config.h"
#include "tooie_game.h"
#include "tooie_hooks.h"

namespace {
    bool hd_shadows_on() {
        try {
            return std::get<bool>(recompui::config::get_config(recompui::config::graphics::id).get_option_value(tooie::hd_shadows_option));
        } catch (...) {
            return false;
        }
    }
}

extern "C" void tooie_player_shadow_model(uint8_t* rdram, recomp_context* ctx) {
    // TOOIE_SHADOW_LOG=1: the two models each time they change.
    static const bool log = std::getenv("TOOIE_SHADOW_LOG") != nullptr;
    if (log) {
        static uint32_t last_shadow = 0, last_model = 0;
        uint32_t shadow = MEM_W(0x1C8, ctx->r29), model = MEM_W(0x1C4, ctx->r29);
        if (shadow != last_shadow || model != last_model) {
            std::printf("[shadow] player shadow model %08X, on-screen model %08X, HD shadows %d\n", shadow, model, hd_shadows_on());
            std::fflush(stdout);
            last_shadow = shadow;
            last_model = model;
        }
    }
    if (hd_shadows_on()) {
        MEM_W(0x1C8, ctx->r29) = MEM_W(0x1C4, ctx->r29);
    }
}
