#pragma once

// HD shadows (src/gameplay/hd_shadows.cpp).
namespace tooie::hd_shadows {
    // Call once per frame from the game thread (tooie_warp_tick): resets the per-frame shadow count.
    void tick();
}
