#pragma once

// HD shadows (src/gameplay/hd_shadows.cpp).
#include <cstdint>
#include <string>

namespace tooie::hd_shadows {
    // Where the light comes from, one option for enemies and NPCs and one for Banjo (Graphics tab).
    enum class Direction : uint32_t { Overhead, Tilt };
    inline const std::string enemy_direction_option = "hd_shadows_enemy_direction";
    inline const std::string banjo_direction_option = "hd_shadows_banjo_direction";

    // Call once per frame from the game thread (tooie_warp_tick): resets the per-frame shadow count.
    void tick();
}
