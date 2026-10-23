// Dust exposure for the dirty characters (picture_filters.cpp): counts the game's own dust puffs made at Banjo's feet.
// (The volumetric dust that once replaced the puffs was removed, L, 2026-10-23; the hooks stay, and never take a puff's place.)
//
// badust_entrypoint_2 and badust_entrypoint_4 make the puffs (banjotooie.us.toml hooks).

#include <atomic>

#include "recomp.h"

#include "tooie_dust.h"
#include "tooie_game_frame_rate.h"
#include "tooie_hooks.h"
#include "tooie_rdram.h"

namespace {
    // Dust Banjo has been in since take_exposure (see tooie_dust.h).
    std::atomic<float> exposure{ 0.0f };

    // A roll or a landing makes several puffs at once, so the puffs within 0.75 s of one count are one trigger.
    void puff(uint8_t* rdram, uint32_t at) {
        if (!tooie::rdram::valid_ptr(at)) {
            return;
        }
        static double last_trigger = -10.0;
        const double now = tooie::game_frame_rate::game_seconds();
        if (now - last_trigger >= 0.75 || now < last_trigger) {
            last_trigger = now;
            exposure.store(exposure.load() + 1.0f);
        }
    }
}

// Hooked at the entry of badust_entrypoint_2 ($a1 the puff's position). Never takes the puff's place.
extern "C" int tooie_dust_spawn(uint8_t* rdram, recomp_context* ctx) {
    puff(rdram, uint32_t(ctx->r5));
    return 0;
}

// Hooked in badust_entrypoint_4 just before it makes its smoke object ($s0 the puff's position).
extern "C" int tooie_dust_spawn_foot(uint8_t* rdram, recomp_context* ctx) {
    puff(rdram, uint32_t(ctx->r16));
    return 0;
}

float tooie::dust::take_exposure() {
    return exposure.exchange(0.0f);
}
