#ifndef __TOOIE_CIRCLE_SHADOW_H__
#define __TOOIE_CIRCLE_SHADOW_H__

#include <cstdint>
#include <string>
#include <vector>

// Graphics > Demake > Simple Circle Shadow (src/gameplay/circle_shadow.cpp): the player's shadow is a
// soft round disc instead of the flattened model, like the blob shadows of early 3D games.
namespace tooie::circle_shadow {
    inline const std::string option = "circle_shadow";
    // A level model left in the ROM that nothing loads (its place in the asset table is only a
    // number the game never asks for). The disc takes its place while the option is on.
    constexpr uint32_t model_id = 0x1D96;

    bool enabled();

    // Called from the asset loader for every asset it loads: the disc model when id is model_id, else empty.
    std::vector<uint8_t> model_for(uint32_t id);
}

#endif
