#ifndef __TOOIE_EFFECT_PICK_H__
#define __TOOIE_EFFECT_PICK_H__

// Shader Effects pick mode (src/debug/parallax_pick.cpp, beside parallax pick mode): the Shader Effects Pick Mode key
// frees the mouse as a crosshair and the texture under it is highlighted. A texture can hold several effects at once:
// right click chooses an effect (Disable, Grass, Deep Snow, Ice Reflection, Shiny Reflection, Text (Mirror Mode flips it
// back so it reads normally), Fence, Lamp (a lit lamp: Graphics > Ray tracing lights the scene from it)) and left click
// turns it on or off for that texture; Disable turns the others off, and Shift + left click goes back to the built-in
// choice. The picks
// are kept in shader_effect_tags.txt in the Dev Files folder and override the built-in lists (grass_textures[],
// ice_textures[], and the shiny list from parallax_textures[] in picture_filters.cpp), which they can be folded into.
#include <cstdint>
#include <functional>

namespace tooie::effect_pick {
    enum Effect : uint8_t {
        effect_disable = 0,
        effect_grass = 1,
        effect_deep_snow = 2,
        effect_ice = 3,
        effect_shiny = 4,
        effect_text = 5,
        // A flat texture cut out by its alpha that stands for something solid (a fence): drawn as a few layers
        // pushed out along its normal, so it has thickness (the Fence thickness setting; off at 0).
        effect_fence = 6,
        effect_lamp = 7,
        effect_count = 8
    };

    // A texture's effects, one bit each (1 << Effect). A picked texture gets exactly these, none of its built-in ones.
    using Effects = uint32_t;
    constexpr bool has(Effects effects, Effect effect) {
        return (effects & (Effects(1) << effect)) != 0;
    }

    // Bumped each time a pick changes, so the texture lists are rebuilt.
    uint32_t version();
    // Each texture picked, with its effects.
    void for_each(const std::function<void(uint64_t hash, Effects effects)>& visit);
}

#endif
