#pragma once

// HD shadows (src/gameplay/hd_shadows.cpp).
#include <cstdint>
#include <string>

namespace tooie::hd_shadows {
    // Where the light comes from, one option for enemies and NPCs and one for Banjo (Graphics tab).
    // Off is offered for Banjo only: he keeps the game's own shadow while the rest stay HD.
    enum class Direction : uint32_t { Overhead, Tilt, Off };
    inline const std::string enemy_direction_option = "hd_shadows_enemy_direction";
    inline const std::string banjo_direction_option = "hd_shadows_banjo_direction";

    // Call once per frame from the game thread (tooie_warp_tick): resets the per-frame shadow count.
    void tick();
    // Call with the 3D scene's display list once it is complete (physical start and end): moves
    // the player's shadow paste to where a wide window shows the shadow.
    void fix_pastes(uint8_t* rdram, uint32_t start, uint32_t end);
    // The same list: poses the player's shadow with this frame's bones instead of last frame's.
    void fix_shadow_pose(uint8_t* rdram, uint32_t start, uint32_t end);
}
