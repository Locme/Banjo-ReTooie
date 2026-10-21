#ifndef __TOOIE_EFFECT_PICK_H__
#define __TOOIE_EFFECT_PICK_H__

// Shader Effects pick mode (src/debug/parallax_pick.cpp, beside parallax pick mode): the Shader Effects Pick Mode key
// frees the mouse as a crosshair, the texture under it is highlighted, and left clicks step the shader effect that
// texture gets: Disable, Grass, Deep Snow, Ice Reflection, Shiny Reflection, Text (Mirror Mode flips it back so it reads normally), Fence, then back to the built-in choice. The picks
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
        effect_count = 7
    };

    // Bumped each time a pick changes, so the texture lists are rebuilt.
    uint32_t version();
    // Each texture picked, with its effect.
    void for_each(const std::function<void(uint64_t hash, Effect effect)>& visit);
}

#endif
