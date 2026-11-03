#ifndef __TOOIE_EFFECT_PICK_H__
#define __TOOIE_EFFECT_PICK_H__

// Shader Effects pick mode (src/debug/parallax_pick.cpp, beside parallax pick mode): the Shader Effects Pick Mode key
// frees the mouse as a crosshair and the texture under it is highlighted. A texture can hold several effects at once:
// right click chooses an effect (Disable, Deep Snow, Ice Reflection, Shiny Reflection, Text (Mirror Mode flips it
// back so it reads normally), Lamp (a lit lamp: Graphics > Ray tracing lights the scene from it), Slight Glow, Light Source (lights the
// scene like a lamp, with no glow in the air round it; Shift + wheel sets its strength), Disable RT (left out of
// the traced scene)) and left
// click turns it on or off for that texture (or keys 1 to 9 choose and turn on or off in one; hold left click and sweep
// to paint it over more textures; middle click shows every texture with it); Disable turns the others off, and Shift + left click goes back to the built-in
// choice. The picks
// are kept in shader_effect_tags.txt in the Dev Files folder and override the built-in lists (ice_textures[], and the shiny list from parallax_textures[] in picture_filters.cpp), which they can be folded into.
#include <cstdint>
#include <functional>
#include <vector>

namespace tooie::effect_pick {
    enum Effect : uint8_t {
        effect_disable = 0,
        effect_deep_snow = 1,
        effect_ice = 2,
        effect_shiny = 3,
        effect_text = 4,
        effect_lamp = 5,
        // Drawn a little brighter, as if lit from inside (RT64 SetSceneGlowTextures).
        effect_glow = 6,
        // Lights the traced scene like a lamp (Graphics > Ray tracing), with no glow in the air round the light, at
        // the texture's own strength (light_strength).
        effect_light = 7,
        // Left out of the traced scene (Graphics > Ray tracing): casts no traced shadow and blocks no traced light.
        effect_rt_off = 8,
        effect_count = 9
    };

    // A texture's effects, one bit each (1 << Effect). A picked texture gets exactly these, none of its built-in ones.
    using Effects = uint32_t;
    constexpr bool has(Effects effects, Effect effect) {
        return (effects & (Effects(1) << effect)) != 0;
    }
    // The effect bits; bits 16 to 21 hold Light Source's strength in 10% steps (0: 100%).
    constexpr Effects effect_bits = 0xFFFFu;
    constexpr Effects strength_shift = 16;
    constexpr Effects strength_bits = Effects(0x3F) << strength_shift;
    constexpr int light_strength(Effects effects) {
        const int steps = int((effects & strength_bits) >> strength_shift);
        return (steps == 0) ? 100 : steps * 10;
    }
    constexpr Effects with_light_strength(Effects effects, int percent) {
        const int steps = (percent < 10) ? 1 : ((percent > 500) ? 50 : (percent / 10));
        return (effects & ~strength_bits) | ((steps == 10) ? 0 : (Effects(steps) << strength_shift));
    }

    // Bumped each time a pick changes, so the texture lists are rebuilt.
    uint32_t version();
    // Each texture picked, with its effects.
    void for_each(const std::function<void(uint64_t hash, Effects effects)>& visit);
    // The textures an effect is on as last sent to RT64, built-in ones included (picture_filters.cpp tells the pick
    // mode, for Show All).
    void set_list(Effect effect, const std::vector<uint64_t>& hashes);
}

#endif
