#ifndef __TOOIE_PICTURE_FILTERS_H__
#define __TOOIE_PICTURE_FILTERS_H__

#include <cstdint>
#include <string>
#include <vector>

#include "librecomp/config.hpp"
#include "recomp.h"

// Picture filters drawn by RT64 as it puts the picture in the window (src/display/picture_filters.cpp,
// lib-patches/rt64.patch): brightness with a test pattern (handoff 4.25), colourblind filters (4.41)
// and the retro filters (4.40). Sharpening, contrast, saturation, vignette and film grain (4.35, 4.36)
// use photo mode's RT64 pass, which photo mode takes over while it is on. Ambient occlusion, fog (4.35)
// and toon outlines, bloom and rim light (4.36) and the underwater tint and heat haze (4.45) are RT64's scene effects pass, drawn after the 3D world and before the HUD.
// Cutscene depth of field (4.36) and eye adaptation (4.37) too. Effects preset (4.42) sets them all at once.
namespace tooie::picture_filters {
    enum class Colourblind : uint32_t { Off, Deuteranopia, Protanopia, Tritanopia };
    enum class Colour16 : uint32_t { Off, Console, Raw };
    enum class TextureUpscale : uint32_t { Off, Double, Quadruple };
    enum class FogColour : uint32_t { Haze, Mist, Dusk, Gloom };
    enum class Preset : uint32_t { Custom, Original, Enhanced, Retro };
    enum class Water : uint32_t { Original, Modern, Stylised };
    // Graphics > Ray Tracing > Ray tracing resolution.
    enum class RayResolution : uint32_t { Half, Medium, High };

    inline const std::string preset_option = "effects_preset";
    // Lighting, Water, Fog (Experimental) toggle: hides the effect options below it (they keep their values).
    inline const std::string reflections_section_option = "reflections_section";
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
    inline const std::string outline_thickness_option = "toon_outline_thickness";
    inline const std::string bloom_option = "bloom";
    inline const std::string cutscene_dof_option = "cutscene_dof";
    inline const std::string gameplay_dof_option = "gameplay_dof";
    inline const std::string eye_adaptation_option = "eye_adaptation";
    inline const std::string rim_light_option = "rim_light";
    // Toon shading apart for the level and for characters (the old single "toon_shading" is carried over to both once, see
    // split_saved_toon_shading in src/game/config.cpp).
    inline const std::string toon_world_option = "toon_shading_world";
    inline const std::string toon_section_option = "toon_shading_section";
    inline const std::string toon_characters_option = "toon_shading_characters";
    inline const std::string underwater_tint_option = "underwater_tint";
    inline const std::string underwater_haze_option = "underwater_haze";
    inline const std::string heat_haze_option = "heat_haze";
    inline const std::string underwater_distortion_option = "underwater_distortion";
    inline const std::string water_reflections_option = "water_reflections";
    inline const std::string ice_reflections_option = "ice_reflections";
    inline const std::string bounce_light_option = "bounce_light";
    inline const std::string ssgi_option = "ssgi";
    inline const std::string ssr_option = "ssr";
    inline const std::string ssr_stochastic_option = "ssr_stochastic";
    inline const std::string ray_tracing_option = "ray_tracing";
    inline const std::string ray_tracing_strength_option = "ray_tracing_strength";
    // Graphics > Ray Tracing's reflection sliders (L, 2026-10-21): how much the traced reflections show, on water, and on
    // the Parallax materials that reflect.
    inline const std::string ray_tracing_reflections_option = "ray_tracing_reflections";
    inline const std::string ray_tracing_water_reflections_option = "ray_tracing_water_reflections";
    inline const std::string ray_tracing_metal_option = "ray_tracing_metal";
    inline const std::string ray_tracing_tiles_option = "ray_tracing_tiles";
    inline const std::string ray_tracing_smooth_option = "ray_tracing_smooth";
    inline const std::string ray_tracing_hit_colours_option = "ray_tracing_hit_colours";
    inline const std::string ray_tracing_resolution_option = "ray_tracing_resolution";
    inline const std::string ray_tracing_parallax_option = "ray_tracing_parallax";
    inline const std::string ray_detail_half_option = "ray_detail_half_distance";
    inline const std::string ray_detail_quarter_option = "ray_detail_quarter_distance";
    inline const std::string ray_tracing_player_shadows_option = "ray_tracing_player_shadows";
    inline const std::string ray_tracing_smoothing_option = "ray_tracing_smoothing";
    // Ray traced BRDF (reflection roughness for every traced reflection, switching the screen-space Stochastic reflections off) and
    // traced Subsurface scattering (leaves and grass, and any texture a Ray Tracing Material pick gives subsurface) (L, 2026-10-22).
    inline const std::string ray_tracing_brdf_option = "ray_tracing_brdf";
    inline const std::string ray_tracing_subsurface_option = "ray_tracing_subsurface";
    inline const std::string path_tracing_option = "path_tracing";
    inline const std::string path_tracing_bounces_option = "path_tracing_bounces";
    inline const std::string traced_beams_option = "traced_light_beams";
    inline const std::string texture_upscale_option = "texture_upscale";
    inline const std::string water_waves_option = "water_waves";
    inline const std::string light_shafts_option = "light_shafts";
    inline const std::string sun_shadows_option = "sun_shadows";
    inline const std::string sun_shadow_banjo_option = "sun_shadow_banjo";
    inline const std::string sun_shadow_softness_option = "sun_shadow_softness";
    inline const std::string sun_shadow_distance_option = "sun_shadow_distance";
    inline const std::string wave_speed_option = "water_wave_speed";
    // Graphics > Water detail: how finely Modern and Stylised water is cut into moving geometry round the player (0 = none).
    inline const std::string water_detail_option = "water_detail";
    // Graphics > Water: Original (the game's water) or Modern (new water drawn in its place, roadmap 4.45/4.46).
    inline const std::string water_option = "water_style";
    // Graphics > Shore foam: Modern water's broken white line along the shores, on the game's own water (Original).
    inline const std::string shore_foam_option = "water_shore_foam";
    // Deep snow that Banjo leaves a trail in, on the snowy ground of the snow levels (rt64-ext/src/shaders/Snow.hlsli),
    // and how deep it is.
    // The Tessellation switch (L, 2026-10-23): its Tessellated Snow and Tessellated Sand settings sit under it.
    inline const std::string tessellation_section_option = "tessellation_section";
    inline const std::string deep_snow_option = "deep_snow";
    inline const std::string tessellated_sand_option = "tessellated_sand";
    inline const std::string snow_height_option = "deep_snow_height";
    inline const std::string snow_detail_option = "deep_snow_detail";
    inline const std::string snow_refill_option = "deep_snow_refill_seconds";
    inline const std::string snow_lod_option = "deep_snow_lod_distance";
    // Parallax mapping on the stone textures listed in picture_filters.cpp (rt64-ext/src/shaders/Parallax.hlsli): how
    // deep, 0 off.
    inline const std::string parallax_option = "parallax";
    inline const std::string ground_displacement_option = "ground_displacement";
    inline const std::string ground_displacement_distance_option = "ground_displacement_distance";
    inline const std::string parallax_original_option = "parallax_original";
    inline const std::string parallax_smoothness_option = "parallax_smoothness";
    // Banjo's fur: shells of strands over his brown fur (rt64-ext/src/shaders/Fur.hlsli).
    inline const std::string banjo_fur_option = "banjo_fur";
    inline const std::string banjo_fur_length_option = "banjo_fur_length";
    inline const std::string banjo_fur_density_option = "banjo_fur_density";
    inline const std::string banjo_fur_noisiness_option = "banjo_fur_noisiness";
    // The character surface layer (rt64-ext/src/shaders/CharSurface.hlsli): how wet, snowy and dirty Banjo and Kazooie can
    // get, 0 (off) to 100.
    inline const std::string char_wet_option = "char_wet";
    inline const std::string char_snow_option = "char_snow";
    inline const std::string char_dirt_option = "char_dirt";
    // The Character Shaders section's switch: shows Banjo's fur and Kazooie's feathers (hiding them turns none off).
    inline const std::string character_section_option = "character_shaders_section";
    // Kazooie's feathers (rt64-ext/src/shaders/FeatherGS.hlsl): how full (0 off) and how big.
    inline const std::string kazooie_feathers_option = "kazooie_feathers";
    inline const std::string kazooie_feather_size_option = "kazooie_feather_size";
    // Like Banjo's fur (L): length, density, noisiness, and how see-through.
    inline const std::string kazooie_feather_length_option = "kazooie_feather_length";
    inline const std::string kazooie_feather_density_option = "kazooie_feather_density";
    inline const std::string kazooie_feather_noisiness_option = "kazooie_feather_noisiness";
    inline const std::string kazooie_feather_transparency_option = "kazooie_feather_transparency";
    // Furry NPCs' white fur (the yetis) and feathered NPCs' feathers (Canary Mary), each with its own sliders (L).
    inline const std::string npc_fur_option = "npc_fur";
    inline const std::string npc_fur_length_option = "npc_fur_length";
    inline const std::string npc_fur_density_option = "npc_fur_density";
    inline const std::string npc_fur_noisiness_option = "npc_fur_noisiness";
    inline const std::string npc_feathers_option = "npc_feather_amount";
    inline const std::string npc_feather_size_option = "npc_feather_size";
    inline const std::string npc_feather_length_option = "npc_feather_length";
    inline const std::string npc_feather_density_option = "npc_feather_density";
    inline const std::string npc_feather_noisiness_option = "npc_feather_noisiness";
    inline const std::string npc_feather_transparency_option = "npc_feather_transparency";
    // DEV tab, on by default (L, 2026-10-17): blends the seams of clamped textures, such as the lines between the
    // pieces of the title's logo (a vanilla issue that shows at high resolutions).
    inline const std::string texture_seams_option = "blend_texture_seams";
    // Whether Toon shading: Characters is above 0, so the model tagging marks the characters' draws.
    bool toon_characters_on();
    // Whether Banjo's fur is on, for the model tagging to mark his model's draws.
    bool banjo_fur_on();
    // Any of the character surface layer's sliders is above 0: the model tagging marks Banjo's and Kazooie's draws.
    bool char_surface_on();
    // Whether a texture has a Light Source pick, so the model tagging tells RT64 which model each matrix is part of.
    bool light_source_models_on();
    // Whether sun shadows are on, so the game's culling keeps what casts them from just outside the picture.
    bool sun_shadows_on();
    // Graphics > Ray tracing is on and the device has ray queries (the traced effects run).
    bool ray_tracing_active();
    // Ray tracing on with Traced light beams above 0: they stand in for Window Light Beams' drawn ones.
    bool traced_beams_on();
    // Graphics > Sun shadow distance, in world units (0 while sun shadows are off).
    float sun_shadow_distance();
    // Whether Kazooie's feathers are on, for the model tagging to mark her draws.
    bool kazooie_feathers_on();
    // Whether furry enemies' fur is on, for the model tagging to mark them.
    bool npc_fur_on();
    bool npc_feathers_on();
    // How far under water the view is, 0 above to 1 under (easing between), for the day and night cycle's rain.
    float underwater();

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
    // The effects preset in Graphics, and setting it as the menu does (applies its values and saves);
    // Custom leaves the effects as they are. The start menu's Play row picks it (src/main/main.cpp).
    Preset preset();
    void set_preset(Preset preset);
    // Each game frame: gives RT64 the game's depth buffer for ambient occlusion.
    void tick(uint8_t* rdram, recomp_context* ctx);
    // Hands the current settings to RT64 (the contrast, saturation, vignette and grain only while photo
    // mode is off).
    void apply();

    // The Effect Cost Check key (src/game/frame_overlay.cpp): the effects that are on now, each with its
    // name in the Graphics tab and the value that turns it off. Ray tracing comes with its own effects.
    struct CostEffect {
        const std::string* id;
        std::string name;
        recomp::config::ConfigValueVariant off;
    };
    std::vector<CostEffect> cost_effects();
    // Turns one effect off for the cost check without touching the saved setting (nullptr: none), and
    // applies it.
    void set_cost_override(const CostEffect* effect);
}

#endif
