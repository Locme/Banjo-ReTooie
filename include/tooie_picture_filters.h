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
    // Retro: CRT's phosphor mask; RT64 takes it plus one (0 is the filter off).
    enum class CrtMask : uint32_t { ApertureGrille, SlotMask, ShadowMask, None };
    enum class TextureUpscale : uint32_t { Off, Double, Quadruple };
    enum class FogColour : uint32_t { Haze, Mist, Dusk, Gloom };
    enum class Preset : uint32_t { Custom, Original, Enhanced, Retro, Toon };
    // Toon Shading's style: soft bands, or hard, two flat tones with a sharp line between.
    enum class ToonStyle : uint32_t { Soft, Hard };
    enum class Water : uint32_t { Original, Modern, Stylised };
    // Graphics > Ray Tracing > Ray tracing resolution.
    enum class RayResolution : uint32_t { Half, Medium, High };
    // Graphics > Lighting: the game's own, Relighting (no ray tracing) or Ray tracing; each shows its own settings.
    enum class Lighting : uint32_t { None, Relighting, RayTracing };
    // Banjo's fur and furry NPCs' (L, 2026-11-15): none, Clump Fur or Hair (the strands), each showing its own settings.
    enum class Fur : uint32_t { None, ClumpFur, Hair };

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
    inline const std::string crt_mask_option = "retro_crt_mask";
    inline const std::string crt_curvature_option = "retro_crt_curvature";
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
    inline const std::string toon_style_option = "toon_shading_style";
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
    // Graphics > Lighting (L, 2026-11-12): sets ray_tracing_option, which the menu no longer shows, and turns Relighting on.
    inline const std::string lighting_option = "lighting";
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
    // Traced relighting: the game's own shading is taken out of each surface and the traced sun, sky and bounce light
    // light it again, 0 (the game's shading) to 100 (all traced).
    inline const std::string ray_tracing_relighting_option = "ray_tracing_relighting";
    // Ray traced denoising: the traced light, shadows and lamps kept from frame to frame and blended with each new frame's rays.
    inline const std::string ray_tracing_denoise_option = "ray_tracing_denoise";
    inline const std::string path_tracing_option = "path_tracing";
    inline const std::string path_tracing_bounces_option = "path_tracing_bounces";
    inline const std::string traced_beams_option = "traced_light_beams";
    inline const std::string texture_upscale_option = "texture_upscale";
    // Cartoon Textures (0 off to 100): the game's textures flattened into areas of even colour as they load.
    inline const std::string texture_cartoon_option = "texture_cartoon";
    inline const std::string water_waves_option = "water_waves";
    inline const std::string light_shafts_option = "light_shafts";
    inline const std::string sun_shadows_option = "sun_shadows";
    inline const std::string sun_shadow_banjo_option = "sun_shadow_banjo";
    inline const std::string sun_shadow_softness_option = "sun_shadow_softness";
    inline const std::string sun_shadow_distance_option = "sun_shadow_distance";
    // Graphics > Relighting: Traced Relighting without ray tracing, lit by the sun shadow map (0 to 100, 0 off).
    inline const std::string relighting_option = "relighting";
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
    // Graphics > 3D Grass (notes/cheap-grass-plan.md): blades on the grassy ground and tall grass along the lawns' sides,
    // with how dense (percent), how far they reach (world units) and how tall (percent).
    inline const std::string grass_option = "grass_blades";
    inline const std::string grass_density_option = "grass_blades_density";
    inline const std::string grass_distance_option = "grass_blades_distance";
    inline const std::string grass_height_option = "grass_blades_height";
    inline const std::string grass_long_option = "grass_blades_long";
    inline const std::string grass_flowers_option = "grass_blades_flowers";
    inline const std::string grass_flower_amount_option = "grass_blades_flower_amount";
    inline const std::string grass_long_height_option = "grass_blades_long_height";
    inline const std::string grass_type_option = "grass_blades_type";
    inline const std::string grass_patches_option = "grass_blades_patches";
    // Graphics > 3D Grass: how much of the grass is flower beds and how big they are (percent; rt64_grass.cpp's
    // FlowerSection).
    inline const std::string grass_flower_beds_option = "grass_blades_flower_beds";
    inline const std::string grass_bed_size_option = "grass_blades_bed_size";
    // Graphics > 3D Grass: small creatures in the grass (rt64-ext's rt64_critters.cpp): insects over the land levels'
    // grass, fish under the sea, and how many (percent).
    inline const std::string critter_insects_option = "grass_critters_insects";
    inline const std::string critter_fish_option = "grass_critters_fish";
    inline const std::string critter_amount_option = "grass_critters_amount";
    // Graphics > 3D Grass: an Amount for each kind of grass and flower the levels grow (rt64-ext's GrassBladeVS.hlsl,
    // GrassFormOf and FlowerFormOf), in percent, 100 by default and 0 none: its setting, name, description, whether it
    // is a flower, and its place among the grasses or the flowers (RT64::SetSceneGrassKinds).
    struct GrassKindOption {
        std::string id;
        const char* name;
        const char* description;
        bool flower;
        uint32_t bit;
    };
    inline const std::vector<GrassKindOption> grass_kind_options = {
        { "grass_blades_kind_fine", "Fine Blades", "Every level: fine, tall, narrow blades among its usual grass.", false, 0u },
        { "grass_blades_kind_broad", "Broad Blades", "Every level: broad, short, blunt blades among its usual grass.", false, 1u },
        { "grass_blades_kind_curling", "Curling Blades", "Every level: long blades curling over among its usual grass.", false, 2u },
        { "grass_blades_kind_timothy", "Timothy", "The meadows (the Isle o' Hags, such as Wooded Hollow and Jinjo Village's lawns, and Spiral Mountain): tall stalks with pale seed spikes.", false, 3u },
        { "grass_blades_kind_sedge", "Sedge", "The meadows: broad, blunt, dark sedge.", false, 4u },
        { "grass_blades_kind_horsetails", "Horsetails", "Terrydactyland: upright jointed stems with dark bands and a brown cone on top.", false, 5u },
        { "grass_blades_kind_tussocks", "Tussocks", "Terrydactyland: short blond tussocks flopping over.", false, 6u },
        { "grass_blades_kind_palm_fronds", "Palm Fronds", "Mayahem Temple (the lawns in front of the temple where Banjo arrives): long arching fronds cut into narrow leaflets.", false, 7u },
        { "grass_blades_kind_cattails", "Cattail Reeds", "Mayahem Temple (the lawns in front of the temple): tall reeds with a fat brown seed head near the top.", false, 8u },
        { "grass_blades_kind_yucca", "Yucca Spikes", "Glitter Gulch Mine: stiff blue-grey swords.", false, 9u },
        { "grass_blades_kind_tumbleweed", "Tumbleweed Tufts", "Glitter Gulch Mine: short, dry, brown tufts curled over.", false, 10u },
        { "grass_blades_kind_pennants", "Pennant Grass", "Witchyworld: tall blades with red, yellow or blue tips.", false, 11u },
        { "grass_blades_kind_topiary", "Topiary Tufts", "Witchyworld: short, clipped, bright tufts.", false, 12u },
        { "grass_blades_kind_ice_shards", "Ice Shards", "Hailfire Peaks' icy side: stiff, pale crystals.", false, 13u },
        { "grass_blades_kind_frozen_tufts", "Frozen Tufts", "Hailfire Peaks' icy side: short tufts white with frost.", false, 14u },
        { "grass_blades_kind_charred_stalks", "Charred Stalks", "Hailfire Peaks' lava side: black stalks whose tips glow like embers.", false, 15u },
        { "grass_blades_kind_ash_grass", "Ash Grass", "Hailfire Peaks' lava side: short, grey, curled grass.", false, 16u },
        { "grass_blades_kind_dock_leaves", "Dock Leaves", "Grunty Industries: broad rusty leaves.", false, 17u },
        { "grass_blades_kind_wire_grass", "Wire Grass", "Grunty Industries: thin, grey, kinked grass.", false, 18u },
        { "grass_blades_kind_sea_oats", "Sea Oats", "Jolly Roger's Lagoon: tall stalks nodding with golden seed heads.", false, 19u },
        { "grass_blades_kind_succulents", "Beach Succulents", "Jolly Roger's Lagoon: short, fat leaves reddening at their tips.", false, 20u },
        { "grass_blades_kind_candy_grass", "Candy Grass", "Cloud Cuckooland: blades with pastel pink, lilac or mint tips.", false, 21u },
        { "grass_blades_kind_cloud_tufts", "Cloud Tufts", "Cloud Cuckooland: short, white, round-topped tufts.", false, 22u },
        { "grass_blades_kind_ferns", "Ferns", "Terrydactyland: wide fern fronds among the dry grass.", false, 23u },
        { "grass_blades_kind_jungle_leaves", "Jungle Leaves", "Mayahem Temple: broad arching leaves.", false, 24u },
        { "grass_blades_kind_kelp", "Kelp", "Under the sea in Jolly Roger's Lagoon: wide ribbons with ruffled edges.", false, 25u },
        { "grass_blades_kind_eelgrass", "Eelgrass", "Under the sea: long, narrow blades.", false, 26u },
        { "grass_blades_kind_sea_lettuce", "Sea Lettuce", "Under the sea: short, round, crinkled sheets.", false, 27u },
        { "grass_blades_kind_bladder_wrack", "Bladder Wrack", "Under the sea: brown-olive stems of round lobes.", false, 28u },
        { "grass_blades_kind_fescue", "Blue Fescue", "The meadows (Wooded Hollow, Jinjo Village, Spiral Mountain): short, fine, blue-grey tufts.", false, 29u },
        { "grass_blades_kind_club_moss", "Club Moss", "Terrydactyland: short, upright, fuzzy dark-green spikes.", false, 30u },
        { "grass_blades_kind_bamboo", "Bamboo Shoots", "Mayahem Temple (the lawns in front of the temple): tall, straight, pale shoots ringed at their joints.", false, 31u },
        { "grass_blades_kind_sagebrush", "Sagebrush", "Glitter Gulch Mine: short, bushy, silver-grey tufts.", false, 32u },
        { "grass_blades_kind_neon", "Neon Grass", "Witchyworld: tall blades whose tips glow purple, lime or orange like the fair's lights.", false, 33u },
        { "grass_blades_kind_cotton_grass", "Cotton Grass", "Hailfire Peaks' icy side: thin stalks with a white tuft of cotton on top.", false, 34u },
        { "grass_blades_kind_obsidian", "Obsidian Spikes", "Hailfire Peaks' lava side: glassy black-purple blades with red-glowing points.", false, 35u },
        { "grass_blades_kind_toxic_weeds", "Toxic Weeds", "Grunty Industries: sickly yellow-green weeds with glowing green tips.", false, 36u },
        { "grass_blades_kind_sea_rush", "Sea Rushes", "Jolly Roger's Lagoon: stiff, straight, dark green rushes.", false, 37u },
        { "grass_blades_kind_rainbow", "Rainbow Grass", "Cloud Cuckooland: each blade's tip one colour of the rainbow.", false, 38u },
        { "grass_blades_kind_red_weed", "Red Weed", "Under the sea in Jolly Roger's Lagoon: feathery red-pink seaweed.", false, 39u },
        { "grass_blades_flower_daisies", "Daisies", "The meadows (Wooded Hollow, Jinjo Village, Spiral Mountain): thin white petals round a big yellow centre.", true, 0u },
        { "grass_blades_flower_bluebells", "Bluebells", "The meadows (Wooded Hollow, Jinjo Village, Spiral Mountain): nodding stems hung with blue bells.", true, 1u },
        { "grass_blades_flower_buttercups", "Buttercups", "The meadows (Wooded Hollow, Jinjo Village, Spiral Mountain): five glossy yellow cupped petals.", true, 2u },
        { "grass_blades_flower_orchids", "Orchids", "Mayahem Temple (the lawns in front of the temple): purple petals and a big white-pink lip.", true, 3u },
        { "grass_blades_flower_bromeliads", "Bromeliads", "Mayahem Temple: rosettes of spiky red leaves round a yellow heart.", true, 4u },
        { "grass_blades_flower_bird_of_paradise", "Birds of Paradise", "Mayahem Temple (the lawns in front of the temple): narrow orange petals rising like a crest, with a long blue tongue.", true, 5u },
        { "grass_blades_flower_cycads", "Cycads", "Terrydactyland: stiff dark fronds round an orange cone.", true, 6u },
        { "grass_blades_flower_magnolias", "Magnolias", "Terrydactyland: big cream cupped petals blushing pink.", true, 7u },
        { "grass_blades_flower_puffballs", "Giant Puffballs", "Terrydactyland: big pale fungus balls on the ground.", true, 8u },
        { "grass_blades_flower_barrel_cacti", "Barrel Cacti", "Glitter Gulch Mine: ribbed green balls with a pink flower on top.", true, 9u },
        { "grass_blades_flower_crystal_sprouts", "Crystal Sprouts", "Glitter Gulch Mine: glittering cyan and violet shards.", true, 10u },
        { "grass_blades_flower_marigolds", "Desert Marigolds", "Glitter Gulch Mine: yellow petals round an orange heart.", true, 11u },
        { "grass_blades_flower_pinwheels", "Carnival Pinwheels", "Witchyworld: six broad red and yellow petals, swirled.", true, 12u },
        { "grass_blades_flower_toadstools", "Toadstools", "Witchyworld: red domed caps with a white spot, on thick white stalks.", true, 13u },
        { "grass_blades_flower_balloons", "Balloon Flowers", "Witchyworld: round red, blue, yellow or green balloons on tall thin stalks.", true, 14u },
        { "grass_blades_flower_snowdrops", "Snowdrops", "Hailfire Peaks' icy side: white bells hanging from bowed stems.", true, 15u },
        { "grass_blades_flower_ice_crystals", "Ice Crystal Clusters", "Hailfire Peaks' icy side: tall pale shards lit from within.", true, 16u },
        { "grass_blades_flower_edelweiss", "Edelweiss", "Hailfire Peaks' icy side: woolly white star petals round a yellow heart.", true, 17u },
        { "grass_blades_flower_fire_lilies", "Fire Lilies", "Hailfire Peaks' lava side: red petals curling up like a flame.", true, 18u },
        { "grass_blades_flower_flame_poppies", "Flame Poppies", "Hailfire Peaks' lava side: four broad orange-red petals round a black heart.", true, 19u },
        { "grass_blades_flower_ember_puffs", "Ember Puffs", "Hailfire Peaks' lava side: glowing orange balls like floating embers.", true, 20u },
        { "grass_blades_flower_dandelions", "Dandelions", "Grunty Industries: yellow pompoms.", true, 21u },
        { "grass_blades_flower_dandelion_clocks", "Dandelion Clocks", "Grunty Industries: white seed puffs on taller stems.", true, 22u },
        { "grass_blades_flower_thistles", "Thistles", "Grunty Industries: purple spiky balls on tall stems.", true, 23u },
        { "grass_blades_flower_sea_pinks", "Sea Pinks", "Jolly Roger's Lagoon: round pink pompoms.", true, 24u },
        { "grass_blades_flower_sea_holly", "Sea Holly", "Jolly Roger's Lagoon: a spiky silver-blue ruff round a blue thistle head.", true, 25u },
        { "grass_blades_flower_sea_lavender", "Sea Lavender", "Jolly Roger's Lagoon: little purple bells along a stem.", true, 26u },
        { "grass_blades_flower_candy_puffs", "Candy Puffs", "Cloud Cuckooland: pastel balls.", true, 27u },
        { "grass_blades_flower_lollipops", "Lollipop Swirls", "Cloud Cuckooland: flat swirled discs of pink and white.", true, 28u },
        { "grass_blades_flower_sugar_stars", "Sugar Stars", "Cloud Cuckooland: five narrow, glowing pastel-yellow points round a pink heart.", true, 29u },
    };
    // Parallax mapping on the stone textures listed in picture_filters.cpp (rt64-ext/src/shaders/Parallax.hlsli): how
    // deep, 0 off.
    inline const std::string parallax_option = "parallax";
    inline const std::string ground_displacement_option = "ground_displacement";
    inline const std::string ground_displacement_distance_option = "ground_displacement_distance";
    inline const std::string parallax_original_option = "parallax_original";
    inline const std::string parallax_smoothness_option = "parallax_smoothness";
    // Banjo Fur: which fur Banjo has (Fur); its settings show under it.
    inline const std::string fur_option = "fur_style";
    // Banjo Hair: shells of strands over his brown fur (rt64-ext/src/shaders/Fur.hlsli). (Still named banjo_fur, so saved
    // settings keep their values.)
    inline const std::string banjo_fur_option = "banjo_fur";
    inline const std::string banjo_fur_length_option = "banjo_fur_length";
    inline const std::string banjo_fur_density_option = "banjo_fur_density";
    inline const std::string banjo_fur_noisiness_option = "banjo_fur_noisiness";
    // Clump Fur: clumps of fur over his brown fur instead of strands, after DK's in Donkey Kong Bananza (ClumpShell in
    // rt64-ext/src/shaders/Fur.hlsli).
    inline const std::string clump_fur_option = "clump_fur";
    inline const std::string clump_fur_size_option = "clump_fur_size";
    inline const std::string clump_fur_length_option = "clump_fur_length";
    // The character surface layer (rt64-ext/src/shaders/CharSurface.hlsli): how wet, snowy and dirty Banjo and Kazooie can
    // get, 0 (off) to 100.
    inline const std::string char_wet_option = "char_wet";
    inline const std::string char_snow_option = "char_snow";
    inline const std::string char_dirt_option = "char_dirt";
    // The old Character Shaders section's switch: hidden since 2026-11-15 (L), and no longer turns anything off.
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
    // NPC Fur: which fur they have (Fur), as Banjo Fur; NPC Hair's settings keep the old npc_fur ids.
    inline const std::string npc_fur_style_option = "npc_fur_style";
    inline const std::string npc_fur_option = "npc_fur";
    inline const std::string npc_fur_length_option = "npc_fur_length";
    inline const std::string npc_fur_density_option = "npc_fur_density";
    inline const std::string npc_fur_noisiness_option = "npc_fur_noisiness";
    inline const std::string npc_clump_fur_option = "npc_clump_fur";
    inline const std::string npc_clump_fur_size_option = "npc_clump_fur_size";
    inline const std::string npc_clump_fur_length_option = "npc_clump_fur_length";
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
    // The hives the 3D grass's bees live round (critter_hives.txt next to the game, a line each: map in hex, x, y, z;
    // sent to RT64 at the first frame and whenever they change): adding one at a place, taking away the nearest one on a
    // map within reach (false when there is none), and a line for each.
    void critter_hive_add(uint32_t map, const float place[3]);
    bool critter_hive_remove(uint32_t map, const float place[3], float reach);
    std::vector<std::string> critter_hive_lines();
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
