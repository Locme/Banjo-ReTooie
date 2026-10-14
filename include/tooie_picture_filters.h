#ifndef __TOOIE_PICTURE_FILTERS_H__
#define __TOOIE_PICTURE_FILTERS_H__

#include <cstdint>
#include <string>

#include "librecomp/config.hpp"
#include "recomp.h"

// Picture filters drawn by RT64 as it puts the picture in the window (src/display/picture_filters.cpp,
// lib-patches/rt64.patch): brightness with a test pattern (handoff 4.25), colourblind filters (4.41)
// and the retro filters (4.40). Sharpening, contrast, saturation, vignette and film grain (4.35, 4.36)
// use photo mode's RT64 pass, which photo mode takes over while it is on. Ambient occlusion, fog (4.35)
// and toon outlines, bloom and rim light (4.36) and the underwater tint (4.45) are RT64's scene effects pass, drawn after the 3D world and before the HUD.
// Cutscene depth of field (4.36) and eye adaptation (4.37) too. Effects preset (4.42) sets them all at once.
namespace tooie::picture_filters {
    enum class Colourblind : uint32_t { Off, Deuteranopia, Protanopia, Tritanopia };
    enum class Colour16 : uint32_t { Off, Console, Raw };
    enum class FogColour : uint32_t { Haze, Mist, Dusk, Gloom };
    enum class Preset : uint32_t { Custom, Original, Enhanced, Retro };

    inline const std::string preset_option = "effects_preset";
    inline const std::string brightness_option = "brightness";
    inline const std::string brightness_pattern_option = "brightness_pattern";
    inline const std::string colourblind_option = "colourblind_filter";
    inline const std::string colourblind_strength_option = "colourblind_strength";
    inline const std::string three_point_option = "retro_three_point";
    inline const std::string dither16_option = "retro_16bit_colour";
    inline const std::string crt_option = "retro_crt";
    inline const std::string sharpen_option = "picture_sharpening";
    inline const std::string contrast_option = "picture_contrast";
    inline const std::string saturation_option = "picture_saturation";
    inline const std::string vignette_option = "picture_vignette";
    inline const std::string grain_option = "picture_grain";
    inline const std::string ambient_occlusion_option = "ambient_occlusion";
    inline const std::string fog_option = "fog";
    inline const std::string fog_start_option = "fog_start";
    inline const std::string fog_colour_option = "fog_colour";
    inline const std::string outlines_option = "toon_outlines";
    inline const std::string bloom_option = "bloom";
    inline const std::string cutscene_dof_option = "cutscene_dof";
    inline const std::string eye_adaptation_option = "eye_adaptation";
    inline const std::string rim_light_option = "rim_light";
    inline const std::string underwater_tint_option = "underwater_tint";
    inline const std::string underwater_haze_option = "underwater_haze";

    // Adds the options to the Graphics tab. They apply as soon as they change.
    void add_options(recomp::config::Config& graphics);
    // An effect setting was changed by hand: the effects preset becomes Custom (unless a preset is
    // being applied).
    void effect_changed();
    // An effect setting was changed by hand: the effects preset becomes Custom (unless a preset is
    // being applied).
    void effect_changed();
    // Whether a preset is setting the effect options now.
    bool applying_effects_preset();
    // Each game frame: gives RT64 the game's depth buffer for ambient occlusion.
    void tick(uint8_t* rdram, recomp_context* ctx);
    // Hands the current settings to RT64 (the contrast, saturation, vignette and grain only while photo
    // mode is off).
    void apply();
}

#endif
