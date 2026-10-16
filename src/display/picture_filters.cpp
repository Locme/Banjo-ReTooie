// Picture filters (handoff 4.25 Brightness, 4.41 Colourblind filters, 4.40 Retro).
//
// RT64's VI pass draws the finished picture into the window; lib-patches/rt64.patch
// gives its shader (VideoInterfacePS.hlsl) a few more constants, set here through
// RT64::SetPictureFilters:
// - Brightness, -5 to +5: out = in^(1 / (1 + 0.08 * step)). Black and white stay put.
//   The test pattern is ten boxes from 2% to 20% grey on black, drawn over the
//   picture: box 1 should just vanish and box 2 just show.
// - Colourblind filters: daltonization for deuteranopia, protanopia or tritanopia,
//   with a strength. The colours the eye can't tell apart are moved into the
//   channels it still sees; this corrects, it does not simulate.
// - Retro: N64 3-point filtering is RT64's own texture filter and is on by default;
//   off gives plain bilinear. N64 16-bit colour cuts each channel to 5 bits with the
//   RDP's magic square dither, at the game's own resolution; Console then runs the
//   VI's dither filter as the N64 does on its way to the TV, Raw dither leaves the
//   dither pattern as it is in the framebuffer. CRT draws 240
//   scanlines and an aperture grille.
// The Graphics tab normally waits for Apply; these save and apply as they change.

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <variant>

#include "tooie_game_frame_rate.h"
#include "recompui/config.h"

#include "tooie_effect_views.h"
#include "tooie_free_camera.h"
#include "tooie_game.h"
#include "tooie_photo_mode.h"
#include "tooie_smaa.h"
#include "tooie_picture_filters.h"

namespace RT64 {
    // lib/rt64/src/render/rt64_vi_renderer.h (from lib-patches/rt64.patch).
    void SetPictureFilters(int brightness, bool brightnessPattern, uint32_t colourblindMode, float colourblindStrength, bool crt, uint32_t dither16, bool threePointFiltering);
    // lib/rt64/src/render/rt64_photo_grade.h.
    void SetPhotoGrade(bool enabled, uint32_t look, float exposure, float contrast, float saturation, float warmth, float vignette, float grain);
    void SetSharpening(float strength);
    // lib/rt64/src/render/rt64_scene_effects.h.
    void SetSceneEffects(float ambientOcclusion, float radius, uint32_t depthAddress);
    void SetSceneFog(float fog, float start, float length, float red, float green, float blue);
    void SetSceneOutlines(float outlines, float thickness);
    void SetSceneBloom(float bloom, float threshold);
    void SetSceneDepthOfField(float strength, bool onBanjo);
    void SetSceneEyeAdaptation(float strength);
    void SetSceneRimLight(float strength);
    void SetSceneUnderwater(float tint, float haze);
    void SetSceneHeatHaze(float strength);
    void SetSceneWaterReflections(float strength);
    void SetSceneBounceLight(float strength);
    void SetSceneWaterWaves(float strength, float speed);
    void SetSceneShoreFoam(bool enabled);
    void SetSceneModernWater(bool enabled);
    void SetSceneModernUnderwater(float amount, float surfaceY, bool wholeLevel);
    void SetSceneLightShafts(float strength);
    void SetSceneSunShadows(float strength, bool onBanjo, float softness);
    void SetSceneGrass(float amount, float height, float distance, float density, float patches);
    void SetSceneGrassBlades(float thickness, float randomLength, bool chunky, bool pixelated);
    void SetSceneGrassTextures(const uint64_t *hashes, size_t count);
    void SetSceneGrassEdgeTextures(const uint64_t *hashes, size_t count);
    void SetSceneFur(float amount, float length, float density, float noisiness);
    void SetSceneSnow(bool on, float height);
    void SetSceneWaterRipples(const float x[3], const float z[3], const float age[3]);
    void SetScenePlayer(bool valid, float x, float y, float z);
    bool GetSceneCameraHeight(float *height);
    // lib/rt64/src/render/rt64_texture_cache.h.
    void SetTextureUpscale(uint32_t factor);
}

namespace {
    // Looked up each time: the tab list moves its configs as more tabs are added.
    recomp::config::Config& graphics_config() {
        return recompui::config::get_config(recompui::config::graphics::id);
    }

    bool created = false;

    // The game's depth buffer pointer (decomp func_8001A0A8).
    constexpr gpr depth_buffer_ptr = (int32_t)0x8007BCC4;
    // Ambient occlusion's reach in world units (Banjo is about 150 tall).
    // Test aid: TOOIE_AO_RADIUS overrides it.
    const float ambient_occlusion_radius = std::getenv("TOOIE_AO_RADIUS") ? (float)std::atof(std::getenv("TOOIE_AO_RADIUS")) : 200.0f;
    std::atomic<float> ambient_occlusion{0.0f};
    std::atomic<uint32_t> depth_address{0};
    std::atomic<float> cutscene_dof{0.0f};
    std::atomic<float> gameplay_dof{0.0f};
    // What was last sent: 0 none, 1 the cutscene one, 2 the gameplay one (-1 to send again).
    std::atomic<int> dof_sent{-1};
    std::atomic<float> underwater_tint{0.25f};
    std::atomic<float> underwater_haze{0.15f};
    std::atomic<float> heat_haze{0.0f};
    std::atomic<float> underwater_distortion{0.3f};
    std::atomic<bool> water_waves_on{false};
    // Graphics > Water is Modern (test aid: TOOIE_MODERN_WATER=1 or 0 overrides it).
    std::atomic<bool> modern_water{false};
    std::atomic<bool> banjo_fur{false};
    // Graphics > Deep snow and its height (1 normal); sent to RT64 only on a map with snow.
    std::atomic<bool> deep_snow{false};
    std::atomic<float> snow_height{1.0f};
    // What was last sent (-1 to send again).
    std::atomic<float> snow_sent{-1.0f};

    // The maps with deep snow on their snowy ground: Hailfire Peaks' Icy Side.
    bool snowy_map(uint16_t map) {
        return map == 0x128;
    }
    float heat_haze_sent = -1.0f;

    // Heat haze only by lava: Hailfire Peaks' lava side, its train station, Chilli Billi's fight and
    // inside the volcano.
    bool by_lava(uint8_t* rdram) {
        const uint16_t map = (uint16_t)MEM_HU(0, (int32_t)0x80132DC2);
        return (map == 0x127) || (map == 0x129) || (map == 0x12B) || (map == 0x133);
    }
    // How far into the underwater look (0 above water, 1 under), eased over a fifth of a second.
    float underwater_amount = 0.0f;
    float underwater_sent = -1.0f;
    std::chrono::steady_clock::time_point underwater_at{};
    // How far above Banjo's position the surface is while he floats. His position is about at the
    // surface then (630 in the Spiral Mountain pool, where a plunge starts at 604).
    constexpr float water_surface_offset = 0.0f;
    // How far below the surface Banjo's position is once all of him is under water.
    constexpr float submerged_depth = 100.0f;

    // Player 0's current state (see src/gameplay/fine_aim.cpp), 0 when there is no player.
    uint32_t player_state(uint8_t* rdram) {
        const uint32_t player = (uint32_t)MEM_W(0, (int32_t)0x80135490);
        if (player < 0x80000000u || player >= 0x81000000u) {
            return 0;
        }
        const uint32_t block = (uint32_t)MEM_W(0x120, (int32_t)player);
        if (block < 0x80000000u || block >= 0x81000000u) {
            return 0;
        }
        return (uint32_t)MEM_W(4, (int32_t)block);
    }

    float read_f32(uint8_t* rdram, uint32_t address) {
        const uint32_t bits = (uint32_t)MEM_W(0, (int32_t)address);
        float value;
        std::memcpy(&value, &bits, sizeof(value));
        return value;
    }

    bool valid_pointer(uint32_t address) {
        return (address >= 0x80000000u) && (address < 0x81000000u);
    }

    // Banjo's position (PlayerState +0xE4 points at it), false when there is no player.
    bool banjo_position(uint8_t* rdram, float pos[3]) {
        const uint32_t player = (uint32_t)MEM_W(0, (int32_t)0x80135490);
        if (!valid_pointer(player)) {
            return false;
        }
        const uint32_t transform = (uint32_t)MEM_W(0xE4, (int32_t)player);
        if (!valid_pointer(transform)) {
            return false;
        }
        for (int i = 0; i < 3; i++) {
            pos[i] = read_f32(rdram, transform + 4 * i);
        }
        return true;
    }

    // Banjo's height, false when there is no player.
    bool banjo_height(uint8_t* rdram, float& y) {
        const uint32_t player = (uint32_t)MEM_W(0, (int32_t)0x80135490);
        if (!valid_pointer(player)) {
            return false;
        }
        const uint32_t transform = (uint32_t)MEM_W(0xE4, (int32_t)player);
        if (!valid_pointer(transform)) {
            return false;
        }
        y = read_f32(rdram, transform + 4);
        return true;
    }

    // The height of the camera the 3D world is drawn from, from RT64's view matrix. The camera controller's
    // own position isn't it: under water the game moves the real camera down to Banjo while that stays
    // above the surface.
    bool camera_height(uint8_t*, float& y) {
        return RT64::GetSceneCameraHeight(&y);
    }

    // Banjo's states in the water, measured headless in the Spiral Mountain pool (TOOIE_WATER_TRACE=1):
    // 45 floating on the surface, 46 swimming on it, 48 starting a dive, 57 swimming under water, 43 still under water,
    // 76 plunging in from a fall, 61 coming out of the plunge.
    bool on_surface(uint32_t state) {
        return (state == 45) || (state == 46);
    }
    bool in_water_state(uint32_t state) {
        return on_surface(state) || (state == 48) || (state == 57) || (state == 43) || (state == 76) || (state == 61);
    }

    // The water's surface while Banjo is in it: his height as he floats on it, or where he went in.
    float water_surface = 0.0f;
    bool was_in_water = false;

    // Under water: the camera below the surface of the water Banjo is in, Banjo dived well under it, or
    // anywhere in Atlantis and the Sea Bottom (whole levels under water).
    bool under_water(uint8_t* rdram, uint32_t state) {
        const uint16_t map = (uint16_t)MEM_HU(0, (int32_t)0x80132DC2);
        if ((map == 0x1A8) || (map == 0x1A9)) {
            return true;
        }
        float banjo = 0.0f;
        const bool have_banjo = banjo_height(rdram, banjo);
        // A water state, or still below the surface he went in at: swimming fast, turning and other moves
        // under water have states of their own, which mustn't end it.
        const bool in_water = have_banjo && (in_water_state(state) || (was_in_water && (banjo < water_surface + 20.0f)));
        if (in_water && (!was_in_water || on_surface(state))) {
            water_surface = banjo + water_surface_offset;
        }
        was_in_water = in_water;
        // Banjo dived well below the surface: the game draws its own underwater look then even where it keeps
        // the camera above the water (the Spiral Mountain moat), so the tint and haze come on with it.
        if (in_water && !on_surface(state) && (banjo < water_surface - submerged_depth)) {
            return true;
        }
        float camera = 0.0f;
        return in_water && camera_height(rdram, camera) && (camera < water_surface);
    }

    // Fog colours by FogColour value, and how far fog takes to thicken (world units).
    // The grass textures of the levels' ground (their RT64 texture hashes, picked by eye from a texture dump of 22
    // outdoor maps on 2026-10-16): 3D grass grows only on these, not on other green textures (moss, leaves, walls).
    constexpr uint64_t grass_textures[] = {
        0x04b8e6560d7f0373, 0x07e2adeaace237bf, 0x0ba0f140a35638fc, 0x0e4d9a802c7dc7ea,
        0x131bc9d029e49793, 0x177db5c49582b48d, 0x1acbb6681f918b72, 0x1dd2ae664d368548,
        0x1fcb6c5e87f783fb, 0x27eae30b3613e31d, 0x37cf9756bf11bfcc, 0x4550fe11ee0e4d34,
        0x48b2654886cd15c6, 0x4a0cddf9edc01dab, 0x4b0e8cd3ac96bba8, 0x543f46bc9510c161,
        0x55950894b7abc374, 0x583f4a61dea0c60c, 0x5d56d430aeacb7cf, 0x6f7c66122a9e73d4,
        0x7557553c55ab1a8a, 0x7727582b32eebc5f, 0x7b5eec9bafbe1838, 0x887e31b8771d7b91,
        0x9069a11fede45381, 0x92912c9af8ac974f, 0x94e63a3b4b78fc54, 0x9ec2455f025b64df,
        0x9f1986bf06a9fde4, 0x9fa547ff3c838199, 0xa0b40729970090fe, 0xa181e8f7c27c9e43,
        0xa4235f087bde04cd, 0xa45e6eb6df215fff, 0xb092ded1029decac, 0xb4e2f23be6235ed4,
        0xb586ef9810cd32d7, 0xbea28b5e576eeebc, 0xbfcb26d86de25a81, 0xc0555349975fe317,
        0xc65609b0a5b03fe4, 0xdfe83dc2f43dcf40, 0xe333ef8b4a0b2512, 0xe6a78e76ed50374a,
        0xe6e8cc803fb5cc26, 0xe6fb1ff1fd886251, 0xe83affdc5057bd6d, 0xea8789c9031a539d,
        0xf13b3cfd0e5fc100, 0xfbcd4c5990eee6c0,
    };

    // Textures with grass only along an edge or in part (cliff tops with a grass fringe, banks of grass over dirt),
    // picked by eye from the same dump: with 3D grass on edges, blades grow on their green parts, whichever way they
    // face. The yellow road and the stone and brick walls with moss are left out: blades grew from their green
    // flecks (L, 2026-10-16).
    constexpr uint64_t grass_edge_textures[] = {
        0x05ea4829b0f5ae21, 0x0c5260f7fed5e062, 0x0e44aed08f6b69e4, 0x252c178af5221184,
        0x2df0d9aa6d361419, 0x383158a31ec96959, 0x3db137bf59b5a361, 0x42cdc86e999ec748,
        0x46d68be1a6b1fa62, 0x747f93d5552d7d66, 0x7acde6f0c1a0efa2, 0x7ad091419192ebc3,
        0x83d693d9e9707210, 0xa63f304a43ef6d4d, 0xb55e8fd582d86eb2, 0xe8394ac6c551ad41,
        0xf083a8663d02850e,
    };

    constexpr float fog_colours[][3] = {
        { 0.72f, 0.80f, 0.88f },   // Haze: pale blue
        { 0.90f, 0.92f, 0.94f },   // Mist: white
        { 0.95f, 0.72f, 0.52f },   // Dusk: warm orange
        { 0.16f, 0.17f, 0.22f },   // Gloom: dark blue-grey
    };
    constexpr float fog_length = 3000.0f;
    // Bloom glows from the parts of the picture brighter than this (0 to 1).
    constexpr float bloom_threshold = 0.55f;

    // True while a preset sets the effect options, so their callbacks neither save one by one nor
    // switch the preset back to Custom.
    bool applying_preset = false;

    // Every effect a preset sets, with its value for Original (everything off).
    struct PresetValue {
        const std::string* id;
        recomp::config::ConfigValueVariant off;
    };
    const PresetValue preset_values[] = {
        { &tooie::smaa::option, (uint32_t)tooie::smaa::Quality::Off },
        { &tooie::picture_filters::three_point_option, true },
        { &tooie::picture_filters::dither16_option, (uint32_t)tooie::picture_filters::Colour16::Off },
        { &tooie::picture_filters::crt_option, false },
        { &tooie::picture_filters::sharpen_option, 0.0 },
        { &tooie::picture_filters::ambient_occlusion_option, 0.0 },
        { &tooie::picture_filters::outlines_option, 0.0 },
        { &tooie::picture_filters::bloom_option, 0.0 },
        { &tooie::picture_filters::cutscene_dof_option, 0.0 },
        { &tooie::picture_filters::gameplay_dof_option, 0.0 },
        { &tooie::picture_filters::eye_adaptation_option, 0.0 },
        { &tooie::picture_filters::rim_light_option, 0.0 },
        { &tooie::picture_filters::underwater_tint_option, 0.0 },
        { &tooie::picture_filters::underwater_haze_option, 0.0 },
        { &tooie::picture_filters::heat_haze_option, 0.0 },
        { &tooie::picture_filters::underwater_distortion_option, 0.0 },
        { &tooie::picture_filters::water_reflections_option, 0.0 },
        { &tooie::picture_filters::bounce_light_option, 0.0 },
        { &tooie::picture_filters::water_waves_option, 0.0 },
        { &tooie::picture_filters::light_shafts_option, 0.0 },
        { &tooie::picture_filters::sun_shadows_option, 0.0 },
        { &tooie::picture_filters::grass_option, 0.0 },
        { &tooie::picture_filters::deep_snow_option, false },
        { &tooie::picture_filters::banjo_fur_option, 0.0 },
        { &tooie::picture_filters::water_option, (uint32_t)tooie::picture_filters::Water::Original },
        { &tooie::picture_filters::shore_foam_option, false },
        { &tooie::picture_filters::texture_upscale_option, (uint32_t)tooie::picture_filters::TextureUpscale::Off },
        { &tooie::picture_filters::fog_option, 0.0 },
        { &tooie::picture_filters::contrast_option, 0.0 },
        { &tooie::picture_filters::saturation_option, 0.0 },
        { &tooie::picture_filters::vignette_option, 0.0 },
        { &tooie::picture_filters::grain_option, 0.0 },
    };

    void apply_preset(tooie::picture_filters::Preset preset) {
        using namespace tooie::picture_filters;
        if (preset == Preset::Custom) {
            return;
        }
        recomp::config::Config& graphics = graphics_config();
        applying_preset = true;
        for (const PresetValue& entry : preset_values) {
            graphics.update_option_value(*entry.id, entry.off);
        }
        if (preset == Preset::Enhanced) {
            graphics.update_option_value(tooie::smaa::option, (uint32_t)tooie::smaa::Quality::High);
            graphics.update_option_value(ambient_occlusion_option, 50.0);
            graphics.update_option_value(sharpen_option, 30.0);
            graphics.update_option_value(underwater_tint_option, 25.0);
            graphics.update_option_value(underwater_haze_option, 15.0);
            graphics.update_option_value(heat_haze_option, 50.0);
            graphics.update_option_value(underwater_distortion_option, 30.0);
            graphics.update_option_value(water_reflections_option, 60.0);
            graphics.update_option_value(texture_upscale_option, (uint32_t)TextureUpscale::Double);
            graphics.update_option_value(water_waves_option, 50.0);
            graphics.update_option_value(light_shafts_option, 40.0);
            graphics.update_option_value(sun_shadows_option, 60.0);
        } else if (preset == Preset::Retro) {
            graphics.update_option_value(dither16_option, (uint32_t)Colour16::Console);
            graphics.update_option_value(crt_option, true);
        }
        applying_preset = false;
    }

    template <typename T>
    T value(const std::string& id, T fallback) {
        try {
            return std::get<T>(graphics_config().get_option_value(id));
        } catch (...) {
            return fallback;
        }
    }
}

void tooie::picture_filters::apply() {
    if (!created) {
        return;
    }
    // Graphics > Debug > Effect debug view: one filter on its own (at its setting, or a default when it is
    // off), every other one off.
    using tooie::effect_views::Solo;
    const bool isolating = tooie::effect_views::isolating();
    const Solo solo = tooie::effect_views::solo();
    // A setting as it is, or for a debug view: the setting (or `fallback` when it is off) if this filter
    // is the one shown, otherwise off.
    auto debug_value = [&](Solo filter, auto setting, auto off, auto fallback) -> decltype(setting) {
        if (!isolating) {
            return setting;
        }
        if (solo != filter) {
            return (decltype(setting))off;
        }
        return (setting != (decltype(setting))off) ? setting : (decltype(setting))fallback;
    };

    RT64::SetPictureFilters(
        (int)value<double>(brightness_option, 0.0),
        value<bool>(brightness_pattern_option, false),
        debug_value(Solo::Colourblind, value<uint32_t>(colourblind_option, (uint32_t)Colourblind::Off), (uint32_t)Colourblind::Off, (uint32_t)Colourblind::Deuteranopia),
        debug_value(Solo::Colourblind, (float)(value<double>(colourblind_strength_option, 100.0) / 100.0), 0.0f, 1.0f),
        debug_value(Solo::Crt, value<bool>(crt_option, false), false, true),
        debug_value(Solo::Colour16, value<uint32_t>(dither16_option, (uint32_t)Colour16::Off), (uint32_t)Colour16::Off, (uint32_t)Colour16::Console),
        value<bool>(three_point_option, true));

    cutscene_dof = (float)(value<double>(cutscene_dof_option, 0.0) / 100.0);
    gameplay_dof = (float)(value<double>(gameplay_dof_option, 0.0) / 100.0);
    underwater_tint = (float)(value<double>(underwater_tint_option, 25.0) / 100.0);
    underwater_haze = (float)(value<double>(underwater_haze_option, 15.0) / 100.0);
    underwater_sent = -1.0f;
    heat_haze = (float)(value<double>(heat_haze_option, 0.0) / 100.0);
    heat_haze_sent = -1.0f;
    underwater_distortion = (float)(value<double>(underwater_distortion_option, 30.0) / 100.0);
    // The next frame sets it again for the scene playing then.
    dof_sent = -1;
    RT64::SetSharpening(debug_value(Solo::Sharpening, (float)(value<double>(sharpen_option, 0.0) / 100.0), 0.0f, 0.5f));
    ambient_occlusion = (float)(value<double>(ambient_occlusion_option, 0.0) / 100.0);
    RT64::SetSceneEffects(ambient_occlusion, ambient_occlusion_radius, depth_address);

    uint32_t colour = value<uint32_t>(fog_colour_option, (uint32_t)FogColour::Haze);
    if (colour >= std::size(fog_colours)) {
        colour = 0;
    }
    RT64::SetSceneFog((float)(value<double>(fog_option, 0.0) / 100.0), (float)value<double>(fog_start_option, 1500.0), fog_length,
        fog_colours[colour][0], fog_colours[colour][1], fog_colours[colour][2]);
    // Thickness was 1 to 4 before the slider went to 200 (25 is the old 1).
    double thickness = value<double>(outline_thickness_option, 25.0);
    if (thickness < 10.0) {
        thickness *= 25.0;
    }
    RT64::SetSceneOutlines((float)(value<double>(outlines_option, 0.0) / 100.0), (float)(thickness / 25.0));
    const uint32_t upscale = debug_value(Solo::TextureUpscale, value<uint32_t>(texture_upscale_option, (uint32_t)TextureUpscale::Off), (uint32_t)TextureUpscale::Off, (uint32_t)TextureUpscale::Double);
    RT64::SetTextureUpscale(upscale == (uint32_t)TextureUpscale::Quadruple ? 4 : (upscale == (uint32_t)TextureUpscale::Double ? 2 : 1));
    RT64::SetSceneBounceLight((float)(value<double>(bounce_light_option, 0.0) / 100.0));
    RT64::SetSceneLightShafts((float)(value<double>(light_shafts_option, 0.0) / 100.0));
    RT64::SetSceneSunShadows((float)(value<double>(sun_shadows_option, 0.0) / 100.0), value<bool>(sun_shadow_banjo_option, true),
        (float)(value<double>(sun_shadow_softness_option, 60.0) / 100.0));
    RT64::SetSceneGrass((float)(value<double>(grass_option, 0.0) / 100.0), (float)(value<double>(grass_height_option, 100.0) / 100.0),
        (float)value<double>(grass_distance_option, 2500.0), (float)(value<double>(grass_density_option, 100.0) / 100.0),
        (float)(value<double>(grass_patches_option, 50.0) / 100.0));
    RT64::SetSceneGrassBlades((float)(value<double>(grass_thickness_option, 100.0) / 100.0),
        (float)(value<double>(grass_random_length_option, 40.0) / 100.0), value<bool>(grass_chunky_option, false),
        value<bool>(grass_pixelated_option, false));
    RT64::SetSceneGrassTextures(grass_textures, std::size(grass_textures));
    RT64::SetSceneGrassEdgeTextures(grass_edge_textures, value<bool>(grass_edges_option, true) ? std::size(grass_edge_textures) : 0);
    double fur = value<double>(banjo_fur_option, 0.0);
    if (const char* forced = std::getenv("TOOIE_BANJO_FUR")) {
        fur = std::atof(forced);
    }
    banjo_fur = fur > 0.0;
    RT64::SetSceneFur((float)(fur / 100.0), (float)(value<double>(banjo_fur_length_option, 100.0) / 100.0),
        (float)(value<double>(banjo_fur_density_option, 100.0) / 100.0), (float)(value<double>(banjo_fur_noisiness_option, 50.0) / 100.0));
    bool snow = value<bool>(deep_snow_option, false);
    if (const char* forced = std::getenv("TOOIE_DEEP_SNOW")) {
        snow = std::atoi(forced) != 0;
    }
    deep_snow = snow;
    snow_height = (float)(value<double>(snow_height_option, 100.0) / 100.0);
    if (const char* forced = std::getenv("TOOIE_SNOW_HEIGHT")) {
        snow_height = (float)(std::atof(forced) / 100.0);
    }
    snow_sent = -1.0f;
    modern_water = value<uint32_t>(water_option, (uint32_t)Water::Original) == (uint32_t)Water::Modern;
    if (const char* forced = std::getenv("TOOIE_MODERN_WATER")) {
        modern_water = std::atoi(forced) != 0;
    }
    RT64::SetSceneModernWater(modern_water);
    bool shore_foam = value<bool>(shore_foam_option, false);
    if (const char* forced = std::getenv("TOOIE_SHORE_FOAM")) {
        shore_foam = std::atoi(forced) != 0;
    }
    RT64::SetSceneShoreFoam(shore_foam);
    water_waves_on = (value<double>(water_waves_option, 0.0) > 0.0) || modern_water;
    RT64::SetSceneWaterWaves((float)(value<double>(water_waves_option, 0.0) / 100.0), (float)(value<double>(wave_speed_option, 100.0) / 100.0));
    RT64::SetSceneWaterReflections((float)(value<double>(water_reflections_option, 0.0) / 100.0));
    RT64::SetSceneRimLight((float)(value<double>(rim_light_option, 0.0) / 100.0));
    RT64::SetSceneEyeAdaptation((float)(value<double>(eye_adaptation_option, 0.0) / 100.0));
    RT64::SetSceneBloom((float)(value<double>(bloom_option, 0.0) / 100.0), bloom_threshold);

    if (!tooie::photo_mode::active()) {
        const float contrast = debug_value(Solo::Contrast, (float)(value<double>(contrast_option, 0.0) / 100.0), 0.0f, 0.3f);
        const float saturation = debug_value(Solo::Saturation, (float)(value<double>(saturation_option, 0.0) / 100.0), 0.0f, 0.5f);
        const float vignette = debug_value(Solo::Vignette, (float)(value<double>(vignette_option, 0.0) / 100.0), 0.0f, 0.5f);
        const float grain = debug_value(Solo::Grain, (float)(value<double>(grain_option, 0.0) / 100.0), 0.0f, 0.5f);
        const bool any = (contrast != 0.0f) || (saturation != 0.0f) || (vignette != 0.0f) || (grain != 0.0f);
        RT64::SetPhotoGrade(any, 0, 0.0f, contrast, saturation, 0.0f, vignette, grain);
    }
}

void tooie::picture_filters::effect_changed() {
    if (!created || applying_preset) {
        return;
    }
    try {
        if (std::get<uint32_t>(graphics_config().get_option_value(preset_option)) != (uint32_t)Preset::Custom) {
            graphics_config().update_option_value(preset_option, (uint32_t)Preset::Custom);
        }
    } catch (...) {
    }
}

bool tooie::picture_filters::banjo_fur_on() {
    return banjo_fur;
}

bool tooie::picture_filters::applying_effects_preset() {
    return applying_preset;
}

void tooie::picture_filters::tick(uint8_t* rdram, recomp_context* ctx) {
    (void)ctx;
    // Test aid: TOOIE_PRESET_TEST=<preset number> picks that effects preset on the first frame and logs
    // the effect settings it gave, then changes Sharpening by hand and logs the preset again.
    static bool preset_tested = false;
    if (!preset_tested) {
        preset_tested = true;
        if (const char* v = std::getenv("TOOIE_PRESET_TEST")) {
            recomp::config::Config& graphics = graphics_config();
            graphics.update_option_value(preset_option, (uint32_t)std::atoi(v));
            fprintf(stderr, "[preset] %u: smaa %u ao %.0f sharpen %.0f 16bit %u crt %d fog %.0f\n",
                value<uint32_t>(preset_option, 99), value<uint32_t>(tooie::smaa::option, 99), value<double>(ambient_occlusion_option, -1),
                value<double>(sharpen_option, -1), value<uint32_t>(dither16_option, 99), (int)value<bool>(crt_option, false), value<double>(fog_option, -1));
            graphics.update_option_value(sharpen_option, 55.0);
            fprintf(stderr, "[preset] after a change by hand: %u, sharpen %.0f\n", value<uint32_t>(preset_option, 99), value<double>(sharpen_option, -1));
        }
    }
    // RT64 keys framebuffers by physical address.
    const uint32_t address = (uint32_t)MEM_W(0, depth_buffer_ptr) & 0x1FFFFFFFu;
    if (depth_address.exchange(address) != address) {
        RT64::SetSceneEffects(ambient_occlusion, ambient_occlusion_radius, address);
    }

    // The underwater look eases in and out over a fifth of a second.
    const uint32_t state = player_state(rdram);
    const auto now = std::chrono::steady_clock::now();
    const float dt = (underwater_at == std::chrono::steady_clock::time_point{}) ? 0.0f :
        std::min(std::chrono::duration<float>(now - underwater_at).count(), 0.25f);
    underwater_at = now;
    const float target = under_water(rdram, state) ? 1.0f : 0.0f;
    // Headless test aid: TOOIE_TELEPORT=<x>,<y>,<z>@<ms>[;<x>,<y>,<z>@<ms>...] puts Banjo at that place (held for 30
    // frames), that long after the program started, to reach a spot without steering him there; several go in turn.
    if (const char* teleport = std::getenv("TOOIE_TELEPORT")) {
        static const auto started = now;
        static size_t entry = 0;
        static int holds = 0;
        // The entry in use: the list's entry-th, separated by ';'.
        const char* text = teleport;
        for (size_t i = 0; (i < entry) && (text != nullptr); i++) {
            text = std::strchr(text, ';');
            text = (text != nullptr) ? text + 1 : nullptr;
        }
        float x = 0.0f, y = 0.0f, z = 0.0f;
        long ms = 0;
        const uint32_t player = (uint32_t)MEM_W(0, (int32_t)0x80135490);
        if ((text != nullptr) && (std::sscanf(text, "%f,%f,%f@%ld", &x, &y, &z, &ms) == 4) && valid_pointer(player) &&
            (tooie::game_frame_rate::pad_on_game_time() ? (long)tooie::game_frame_rate::game_ms() > ms
                                                        : now - started > std::chrono::milliseconds(ms)))
        {
            if (holds++ == 0) {
                fprintf(stderr, "[teleport] Banjo to %.0f %.0f %.0f\n", x, y, z);
            }
            const uint32_t physics = (uint32_t)MEM_W(0xC8, (int32_t)player);
            const uint32_t position = (uint32_t)MEM_W(0xE4, (int32_t)player);
            for (uint32_t base : { physics + 4, position }) {
                if (valid_pointer(base) && (base != 4)) {
                    const float values[3] = { x, y, z };
                    for (int i = 0; i < 3; i++) {
                        uint32_t bits;
                        std::memcpy(&bits, &values[i], sizeof(bits));
                        MEM_W(4 * i, (int32_t)base) = (int32_t)bits;
                    }
                }
            }
            if (holds >= 30) {
                holds = 0;
                entry++;
            }
        }
    }
    // TOOIE_WATER_TRACE=1 logs the player's state when it changes, and every quarter second.
    if (std::getenv("TOOIE_WATER_TRACE")) {
        static uint32_t last = 0xFFFFFFFFu;
        static auto last_log = std::chrono::steady_clock::now();
        const auto log_now = std::chrono::steady_clock::now();
        if ((state != last) || (log_now - last_log > std::chrono::milliseconds(250))) {
            last = state;
            last_log = log_now;
            float banjo = 0.0f, camera = 0.0f;
            banjo_height(rdram, banjo);
            camera_height(rdram, camera);
            fprintf(stderr, "[water] player state %u, Banjo y %.1f, camera y %.1f, surface %.1f, under water %d\n", state, banjo, camera, water_surface, (int)(target > 0.5f));
        }
    }
    underwater_amount = (target > underwater_amount) ? std::min(target, underwater_amount + dt * 5.0f) : std::max(target, underwater_amount - dt * 5.0f);
    if (underwater_amount != underwater_sent) {
        underwater_sent = underwater_amount;
        RT64::SetSceneUnderwater(underwater_tint * underwater_amount, underwater_haze * underwater_amount);
    }
    // Modern water's caustics under the water: how far under, the surface's height and whether the whole level is.
    if (modern_water) {
        const uint16_t map = (uint16_t)MEM_HU(0, (int32_t)0x80132DC2);
        RT64::SetSceneModernUnderwater(underwater_amount, water_surface, (map == 0x1A8) || (map == 0x1A9));
    }

    // Ripples: a ring spreads from Banjo as he moves (one every 0.25 s and 20 units), or now and then while he
    // stays still, and a big splash when he goes into the water. The shader draws them, his wake and the ring
    // round him only on water near his height, so wading counts and walking on land doesn't. The newest three
    // are drawn.
    {
        struct Ripple { float x = 0.0f, z = 0.0f; std::chrono::steady_clock::time_point at{}; bool used = false, splash = false; };
        static Ripple ripples[3];
        static int next = 0;
        static float last_x = 0.0f, last_z = 0.0f;
        static std::chrono::steady_clock::time_point last_at{};
        static bool was_swimming = false;
        float pos[3];
        const bool swimming = in_water_state(state);
        if (water_waves_on && banjo_position(rdram, pos)) {
            const float moved = std::hypot(pos[0] - last_x, pos[2] - last_z);
            const float since = std::chrono::duration<float>(now - last_at).count();
            const bool splash = swimming && !was_swimming;
            if (splash || (since > 0.25f && moved > 20.0f) || (since > 1.2f)) {
                ripples[next] = { pos[0], pos[2], now, true, splash };
                next = (next + 1) % 3;
                last_x = pos[0];
                last_z = pos[2];
                last_at = now;
            }
        }
        was_swimming = swimming;
        float x[3], z[3], age[3];
        for (int i = 0; i < 3; i++) {
            x[i] = ripples[i].x;
            z[i] = ripples[i].z;
            const float seconds = std::chrono::duration<float>(now - ripples[i].at).count();
            // A splash's age carries 4 more (see RippleSlope); old rings are left at their end.
            age[i] = !ripples[i].used ? -1.0f : ripples[i].splash ? 4.0f + std::min(seconds, 3.9f) : std::min(seconds, 3.9f);
        }
        RT64::SetSceneWaterRipples(x, z, age);
    }

    // Deep snow on the maps with snow only.
    {
        const uint16_t map = (uint16_t)MEM_HU(0, (int32_t)0x80132DC2);
        const float snow = (deep_snow && snowy_map(map)) ? snow_height.load() : 0.0f;
        if (snow != snow_sent.load()) {
            snow_sent = snow;
            RT64::SetSceneSnow(snow > 0.0f, snow);
        }
    }
    // The fog is measured from Banjo.
    {
        float pos[3];
        const bool valid = banjo_position(rdram, pos);
        RT64::SetScenePlayer(valid, valid ? pos[0] : 0.0f, valid ? pos[1] : 0.0f, valid ? pos[2] : 0.0f);
    }

    // The same shimmer, gentler, under water.
    const float heat = by_lava(rdram) ? heat_haze.load() : underwater_distortion.load() * underwater_amount * 0.5f;
    if (heat != heat_haze_sent) {
        heat_haze_sent = heat;
        RT64::SetSceneHeatHaze(heat);
    }

    // The cutscene depth of field in letterboxed scenes, focused on the middle of the picture; the gameplay one
    // otherwise, focused on Banjo and gentler.
    const bool letterboxed = tooie::in_letterboxed_scene();
    const int dof = (letterboxed && (cutscene_dof > 0.0f)) ? 1 : ((!letterboxed && (gameplay_dof > 0.0f)) ? 2 : 0);
    if (dof != dof_sent) {
        dof_sent = dof;
        RT64::SetSceneDepthOfField((dof == 1) ? cutscene_dof.load() : ((dof == 2) ? gameplay_dof.load() * 0.6f : 0.0f), dof == 2);
    }
}

void tooie::picture_filters::add_options(recomp::config::Config& graphics) {
    created = true;

    graphics.add_enum_option(
        preset_option,
        "Effects preset",
        "Sets all the picture effects below at once. <recomp-color primary>Original</recomp-color> turns them all off. <recomp-color primary>Enhanced</recomp-color> adds SMAA, ambient occlusion and sharpening. <recomp-color primary>Retro</recomp-color> gives N64 16-bit colour and a CRT look. Changing any of them yourself makes it <recomp-color primary>Custom</recomp-color>.",
        {
            {Preset::Custom, "Custom", "Custom"},
            {Preset::Original, "Original", "Original"},
            {Preset::Enhanced, "Enhanced", "Enhanced"},
            {Preset::Retro, "Retro", "Retro"},
        },
        Preset::Custom);
    graphics.add_option_change_callback(preset_option,
        [](recomp::config::ConfigValueVariant value, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
            if (context != recomp::config::OptionChangeContext::Temporary) {
                return;
            }
            const auto* preset = std::get_if<uint32_t>(&value);
            if ((preset != nullptr) && (*preset != (uint32_t)Preset::Custom)) {
                apply_preset((Preset)*preset);
                graphics_config().save_config();
            }
        });

    graphics.add_number_option(
        brightness_option,
        "Brightness",
        "Brightens or darkens the dark and middle tones. Black and white stay as they are. Turn on the test pattern below to set it.",
        -5, 5, 1, 0, false, 0);
    graphics.add_bool_option(
        brightness_pattern_option,
        "Brightness test pattern",
        "Shows ten grey boxes over the game. Close the menu, then set Brightness so the first box just disappears into the black and the second one is just visible. Turn it off when done.",
        false);
    graphics.add_enum_option(
        colourblind_option,
        "Colourblind filter",
        "Moves the colours you can't tell apart into ones you can. <recomp-color primary>Deuteranopia</recomp-color> and <recomp-color primary>Protanopia</recomp-color> are red-green, <recomp-color primary>Tritanopia</recomp-color> is blue-yellow.",
        {
            {Colourblind::Off, "Off", "Off"},
            {Colourblind::Deuteranopia, "Deuteranopia", "Deuteranopia"},
            {Colourblind::Protanopia, "Protanopia", "Protanopia"},
            {Colourblind::Tritanopia, "Tritanopia", "Tritanopia"},
        },
        Colourblind::Off);
    graphics.add_number_option(
        colourblind_strength_option,
        "Colourblind filter strength",
        "How strongly the colourblind filter shifts the colours.",
        0, 100, 10, 0, true, 100);
    graphics.add_option_hidden_dependency(colourblind_strength_option, colourblind_option, Colourblind::Off);

    graphics.add_bool_option(
        three_point_option,
        "Retro: N64 3-point filtering",
        "The N64's own texture smoothing, as on the console. Off uses plain bilinear smoothing instead.",
        true);
    graphics.add_enum_option(
        dither16_option,
        "Retro: N64 16-bit colour",
        "Cuts the colours down to the N64's 16-bit colour, with its dither pattern at the game's original resolution. <recomp-color primary>Console</recomp-color> smooths the dither as the N64 does on its way to the TV, leaving its colour banding. <recomp-color primary>Raw dither</recomp-color> shows the dither pattern itself.",
        {
            {Colour16::Off, "Off", "Off"},
            {Colour16::Console, "Console", "Console"},
            {Colour16::Raw, "Raw dither", "Raw dither"},
        },
        Colour16::Off);
    graphics.add_bool_option(
        crt_option,
        "Retro: CRT",
        "Draws 240 scanlines and the stripes of a CRT TV's aperture grille over the picture.",
        false);

    graphics.add_enum_option(
        texture_upscale_option,
        "Texture upscaling",
        "Draws the game's textures at 2 or 4 times their size, smoothing the stair steps on their edges and lines while keeping them sharp. Texture packs take priority."
        "<br /><br />"
        "<recomp-color primary>2x</recomp-color> runs one pass of an xBR-style edge-directed filter (a compute shader on the GPU). <recomp-color primary>4x</recomp-color> runs the same filter twice, so it is sharper on lines but uses more video memory and loading time. Neither uses AI; both only smooth edges.",
        {
            {TextureUpscale::Off, "Off", "Off"},
            {TextureUpscale::Double, "2x", "2x"},
            {TextureUpscale::Quadruple, "4x", "4x"},
        },
        TextureUpscale::Off);
    graphics.add_number_option(
        sharpen_option,
        "Sharpening",
        "Sharpens the picture's fine detail, most where it is soft. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_bool_option(
        lighting_section_option,
        "Shaders",
        "Shows the lighting, water, fog and the other effects below. Hiding them does not turn any effect off.",
        true);

    graphics.add_number_option(
        ambient_occlusion_option,
        "Ambient occlusion",
        "Soft shading where surfaces meet: in corners, under ledges and around things standing on the ground. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        bounce_light_option,
        "Bounce light",
        "Light bounced off nearby surfaces: colourful walls and floors tint and brighten what is next to them a little. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        outlines_option,
        "Toon outlines",
        "Draws dark outlines around characters and objects, on the edge in front of whatever is behind them, and lighter ones along ridges and the top edges of cliffs. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        outline_thickness_option,
        "Toon outline thickness",
        "How thick the toon outlines are: 25 is a thin line, 100 a heavy one and 200 a very bold cartoon line. They keep the same thickness at any resolution.",
        10, 200, 5, 0, false, 25);
    graphics.add_number_option(
        rim_light_option,
        "Rim light",
        "A soft light along the edges of nearby characters and objects, so they stand out from what is behind them. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        underwater_tint_option,
        "Underwater tint",
        "While under water, the 3D world turns light blue. The HUD isn't changed. 0 is off, 100 strongest.",
        0, 100, 5, 0, false, 25);
    graphics.add_number_option(
        underwater_haze_option,
        "Underwater haze",
        "While under water, things further away fade into a light blue haze. Works with Underwater tint at 0 too. 0 is off.",
        0, 100, 5, 0, false, 15);
    graphics.add_number_option(
        underwater_distortion_option,
        "Underwater distortion",
        "While under water, the 3D world wobbles gently, more in the distance. 0 is off.",
        0, 100, 5, 0, false, 30);
    graphics.add_number_option(
        water_reflections_option,
        "Water reflections",
        "The game's water mirrors what is around it, with gentle ripples. Only what is on screen can be reflected, so reflections fade near the edges. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        water_waves_option,
        "Water waves",
        "Waves roll across the game's water: the water seen through bends with them, and their slopes catch the light. Drawn on the picture, so Banjo still floats at the same height. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        wave_speed_option,
        "Water wave speed",
        "How fast the water waves move, in percent. 100 is normal.",
        25, 200, 5, 0, false, 100);
    graphics.add_enum_option(
        water_option,
        "Water",
        "<recomp-color primary>Original</recomp-color> is the game's own water. <recomp-color primary>Modern</recomp-color> replaces it with new water: clear in the shallows and darker with depth in each level's own colour, bent by rolling waves, reflecting the sky and scenery more at low angles, with the sun's glint, foam along the shores and rings, a wake and splashes round the player. Modern makes its own reflections, so Water reflections is not used; its waves follow Water waves (50 when that is 0) and Water wave speed. Under water, the game's water surface is kept for now. Drawn on the picture, so the player still floats at the same height.",
        {
            {Water::Original, "Original", "Original"},
            {Water::Modern, "Modern", "Modern"},
        },
        Water::Original);
    graphics.add_bool_option(
        shore_foam_option,
        "Shore foam",
        "With Water on <recomp-color primary>Original</recomp-color>: a broken white line of foam drifts along the edges of the game's water, where it gets shallow, as in Modern water. Modern water always has it.",
        false);
    graphics.add_bool_option(
        deep_snow_option,
        "Deep snow",
        "The snow on the ground lies deep, as a real layer of snow (Hailfire Peaks' Icy Side): Banjo wades through it, leaving a furrow and footprints with the snow banked up either side, and after a while the snow fills back in, sooner while it snows. Drawn on the picture, so nothing in the game changes.",
        false);
    graphics.add_number_option(
        snow_height_option,
        "Snow height",
        "How deep the deep snow is, in percent. 100 is about ankle deep on Banjo, 300 up to his knees. Deeper snow costs a little more.",
        25, 300, 5, 0, false, 100);
    graphics.add_number_option(
        banjo_fur_option,
        "Banjo fur",
        "Banjo's brown fur grows real strands: layers of short hairs stand out of his model and move with him, darker at the roots, in play and in cutscenes. Kazooie, his shorts, feet and backpack are left as they are, and so is everyone else. Higher numbers give a thicker coat. Drawn on the picture, so nothing in the game changes. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        banjo_fur_length_option,
        "Banjo fur length",
        "How long Banjo's fur is, in percent. 100 is short and fluffy.",
        25, 300, 5, 0, false, 100);
    graphics.add_number_option(
        banjo_fur_density_option,
        "Banjo fur density",
        "How many hairs Banjo's fur has, in percent: higher is more, finer hairs, lower is fewer, thicker ones.",
        25, 300, 5, 0, false, 100);
    graphics.add_number_option(
        banjo_fur_noisiness_option,
        "Banjo fur noisiness",
        "How uneven Banjo's fur is: higher gives tufts that stand taller or lower and hairs lighter or darker than their neighbours, 0 an even coat.",
        0, 100, 5, 0, false, 50);
    graphics.add_number_option(
        heat_haze_option,
        "Heat haze",
        "Near lava (Hailfire Peaks' lava side, Chilli Billi, inside the volcano), the air shimmers, more in the distance. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        sun_shadows_option,
        "Sun shadows",
        "Real-time shadows from the sun: every character, enemy, object and piece of scenery casts a shadow onto what is behind it, moving as they move. Drawn from what is on screen, so a shadow fades out when its caster leaves the picture. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_bool_option(
        sun_shadow_banjo_option,
        "Sun shadow on Banjo",
        "Whether Banjo casts a sun shadow too. Off leaves his to HD shadows or the game's own.",
        true);
    graphics.add_number_option(
        sun_shadow_softness_option,
        "Sun shadow softness",
        "How smooth the sun shadows are. Higher blends the light across a character's body instead of shading it face by face, and gives shadow edges a softer fade. 0 is the sharpest.",
        0, 100, 5, 0, false, 60);
    graphics.add_number_option(
        light_shafts_option,
        "Light shafts",
        "Sunlight streams through gaps between trees, cliffs and buildings where they stand against a bright sky. Indoors and under night skies there is none. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        bloom_option,
        "Bloom",
        "A glow around the brightest parts of the 3D world: a tight one close to them and a wide soft one around it, easing in rather than switching on. The HUD doesn't glow. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        eye_adaptation_option,
        "Eye adaptation",
        "Like your eyes adjusting: coming out into daylight glares for a moment, going into a cave is dark for a few seconds and then opens up. Once settled, dark places stay a little brighter and very bright ones a little darker. Fades between areas don't set it off. The HUD isn't changed. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        cutscene_dof_option,
        "Cutscene depth of field",
        "In letterboxed cutscenes, blurs what is nearer or further than the middle of the picture, like a film camera. Text and the HUD stay sharp. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        gameplay_dof_option,
        "Depth of field",
        "While you play, Banjo stays in focus and what is well in front of or behind him blurs, more the further it is. In first person the middle of the picture is in focus. Gentler than the cutscene one at the same number. The HUD stays sharp. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        fog_option,
        "Fog",
        "Distance fog over the 3D world, measured from Banjo, so moving the camera doesn't change it. It thickens past its start distance. The game's own fog stays as it is. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        fog_start_option,
        "Fog start distance",
        "How far from Banjo the fog begins, in the game's units (Banjo is about 150 tall).",
        0, 6000, 250, 0, false, 1500);
    graphics.add_enum_option(
        fog_colour_option,
        "Fog colour",
        "The fog's colour.",
        {
            {FogColour::Haze, "Haze", "Haze"},
            {FogColour::Mist, "Mist", "Mist"},
            {FogColour::Dusk, "Dusk", "Dusk"},
            {FogColour::Gloom, "Gloom", "Gloom"},
        },
        FogColour::Haze);
    graphics.add_number_option(
        contrast_option,
        "Contrast",
        "More or less difference between the dark and light parts of the picture. 0 leaves it as it is.",
        -50, 50, 5, 0, false, 0);
    graphics.add_number_option(
        saturation_option,
        "Colour saturation",
        "Stronger or paler colours. 0 leaves them as they are.",
        -100, 100, 5, 0, false, 0);
    graphics.add_number_option(
        vignette_option,
        "Vignette",
        "Darkens the corners of the picture. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        grain_option,
        "Film grain",
        "Adds moving film grain over the picture. 0 is off.",
        0, 100, 5, 0, false, 0);

    graphics.add_bool_option(
        grass_section_option,
        "Grass",
        "Shows the 3D grass settings below. Hiding them does not turn the grass off.",
        true);

    graphics.add_number_option(
        grass_option,
        "3D grass",
        "Real blades of grass grow out of the green ground of the levels (Spiral Mountain, Isle o' Hags, Mayahem Temple and others): wind rolls across them in waves, and they bend away from Banjo and spring back up behind him. Higher numbers grow more of them. Drawn on the picture, so nothing in the game changes. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        grass_height_option,
        "3D grass height",
        "How tall the 3D grass grows, in percent. 100 is about knee high on Banjo.",
        25, 200, 5, 0, false, 100);
    graphics.add_number_option(
        grass_distance_option,
        "3D grass distance",
        "How far from the camera the 3D grass reaches before it shrinks away, in the game's units (Banjo is about 150 tall). Further costs more.",
        500, 6000, 250, 0, false, 2500);
    graphics.add_number_option(
        grass_density_option,
        "3D grass density",
        "How closely the 3D grass blades grow, in percent. Lower is sparser and cheaper, higher is thicker and costs more.",
        10, 200, 5, 0, false, 100);
    graphics.add_number_option(
        grass_patches_option,
        "3D grass patches",
        "How much of the green ground the 3D grass grows on: it grows in patches here and there, with short grass at their edges. Lower is fewer, smaller patches, 100 is grass everywhere.",
        5, 100, 5, 0, false, 50);
    graphics.add_number_option(
        grass_thickness_option,
        "3D grass thickness",
        "How wide each 3D grass blade is, in percent of the normal width. Higher gives thicker, chunkier strands.",
        50, 400, 10, 0, false, 100);
    graphics.add_number_option(
        grass_random_length_option,
        "3D grass random length",
        "How much the 3D grass blades' lengths differ from each other, in percent. 0 makes every blade as long as 3D grass height; 100 makes them anything from very short to full length.",
        0, 100, 5, 0, false, 40);
    graphics.add_bool_option(
        grass_chunky_option,
        "Chunky 3D grass",
        "Low-poly 3D grass to suit the N64 look: fewer, wider blades, each a single flat-coloured triangle. Also cheaper to draw.",
        false);
    graphics.add_bool_option(
        grass_pixelated_option,
        "Pixelated 3D grass",
        "Draws the 3D grass blades in blocks the size of the N64's own pixels, so they look blocky and pixel-sharp at any resolution. Works with or without Chunky 3D grass.",
        false);
    graphics.add_bool_option(
        grass_edges_option,
        "3D grass on edges",
        "Also grow 3D grass on the grassy parts of textures that are only partly grass: the grass fringe along cliff tops and banks, and grass at the foot of rocks and walls. The blades lean out from slopes and walls.",
        true);

    for (const std::string* id : { &brightness_option, &brightness_pattern_option, &colourblind_option, &colourblind_strength_option,
                                   &three_point_option, &dither16_option, &crt_option, &sharpen_option, &contrast_option,
                                   &saturation_option, &vignette_option, &grain_option, &ambient_occlusion_option,
                                   &fog_option, &fog_start_option, &fog_colour_option, &outlines_option, &outline_thickness_option, &bloom_option, &cutscene_dof_option, &gameplay_dof_option,
                                   &eye_adaptation_option, &rim_light_option, &underwater_tint_option, &underwater_haze_option, &heat_haze_option, &underwater_distortion_option, &water_reflections_option, &bounce_light_option, &texture_upscale_option, &water_waves_option, &wave_speed_option, &light_shafts_option, &sun_shadows_option, &sun_shadow_banjo_option, &sun_shadow_softness_option, &grass_option, &grass_height_option, &grass_distance_option, &grass_density_option, &grass_patches_option, &grass_thickness_option, &grass_random_length_option, &grass_chunky_option, &grass_pixelated_option, &grass_edges_option, &deep_snow_option, &snow_height_option, &banjo_fur_option, &banjo_fur_length_option, &banjo_fur_density_option, &banjo_fur_noisiness_option, &water_option, &shore_foam_option }) {
        const bool in_presets = std::any_of(std::begin(preset_values), std::end(preset_values),
            [id](const PresetValue& entry) { return *entry.id == *id; });
        graphics.add_option_change_callback(*id,
            [in_presets](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
                if (context == recomp::config::OptionChangeContext::Temporary) {
                    if (applying_preset) {
                        // The preset saves once it has set everything.
                        return;
                    }
                    if (in_presets) {
                        effect_changed();
                    }
                    // Saving applies the change, which calls back here as Permanent.
                    graphics_config().save_config();
                } else {
                    apply();
                }
            });
    }


    // Hidden when the Shaders toggle is off; the effects keep their values either way.
    graphics.add_option_hidden_dependency(ambient_occlusion_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(bounce_light_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(outlines_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(outline_thickness_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(rim_light_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(underwater_tint_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(underwater_haze_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(underwater_distortion_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(water_reflections_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(water_waves_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(wave_speed_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(water_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(shore_foam_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(grass_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_height_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_distance_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_density_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_patches_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_thickness_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_random_length_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_chunky_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_pixelated_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_edges_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(deep_snow_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(snow_height_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(banjo_fur_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(banjo_fur_length_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(banjo_fur_density_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(banjo_fur_noisiness_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(heat_haze_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(sun_shadows_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(sun_shadow_banjo_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(sun_shadow_softness_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(light_shafts_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(bloom_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(eye_adaptation_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(cutscene_dof_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(gameplay_dof_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(fog_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(fog_start_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(fog_colour_option, lighting_section_option, false);
}
