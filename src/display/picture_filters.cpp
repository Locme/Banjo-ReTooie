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
#include <mutex>
#include <unordered_map>
#include <variant>
#include <vector>

#include "tooie_game_frame_rate.h"
#include "recompui/config.h"

#include "tooie_effect_views.h"
#include "tooie_free_camera.h"
#include "tooie_game.h"
#include "tooie_photo_mode.h"
#include "tooie_fsr.h"
#include "tooie_fxaa.h"
#include "tooie_smaa.h"
#include "tooie_picture_filters.h"
#include "tooie_debug.h"
#include "tooie_window_beams.h"
#include "tooie_toast.h"
#include "tooie_effect_pick.h"
#include "tooie_material_pick.h"
#include "tooie_parallax_pick.h"

namespace RT64 {
    // lib/rt64/src/render/rt64_vi_renderer.h (from lib-patches/rt64.patch).
    void SetPictureFilters(int brightness, bool brightnessPattern, uint32_t colourblindMode, float colourblindStrength, bool crt, uint32_t dither16, bool threePointFiltering);
    // rt64-ext/src/render/rt64_photo_grade.h.
    void SetPhotoGrade(bool enabled, uint32_t look, float exposure, float contrast, float saturation, float warmth, float vignette, float grain);
    void SetSharpening(float strength);
    // rt64-ext/src/render/rt64_scene_effects.h.
    void SetSceneEffects(float ambientOcclusion, float radius, uint32_t depthAddress);
    void SetSceneFog(float fog, float start, float length, float red, float green, float blue);
    void SetSceneOutlines(float outlines, float thickness);
    void SetSceneBloom(float bloom, float threshold);
    void SetSceneDepthOfField(float strength, bool onBanjo);
    void SetSceneEyeAdaptation(float strength);
    void SetSceneRimLight(float strength);
    void SetSceneToonShading(float world, float characters);
    void SetSceneUnderwater(float tint, float haze);
    void SetSceneHeatHaze(float strength, bool warmOnly);
    void SetSceneWaterReflections(float strength);
    void SetSceneIceReflections(float strength);
    void SetSceneIceTextures(const uint64_t *hashes, size_t count);
    void SetSceneIceAnywhereTextures(const uint64_t *hashes, size_t count);
    void SetSceneShinyTextures(const uint64_t *hashes, size_t count);
    // rt64-ext/src/render/rt64_mirror.h.
    void SetMirrorTextTextures(const uint64_t *hashes, size_t count);
    void SetSceneSnowOffTextures(const uint64_t *hashes, size_t count);
    void SetSceneGlowTextures(const uint64_t *hashes, size_t count);
    void SetSceneLightSourceTextures(const uint64_t *hashes, const float *reaches, size_t count);
    void SetSceneRayOffTextures(const uint64_t *hashes, size_t count);
    void SetSceneRayTracingBrdfSubsurface(float brdfRoughness, float subsurface);
    void SetSceneRayMaterials(const uint64_t *hashes, const uint32_t *albedoRoughness, const uint32_t *metalnessEmissive, size_t count);
    void SetSceneBounceLight(float strength);
    void SetSceneScreenSpaceGI(float strength);
    void SetSceneScreenSpaceReflections(float strength, float glossiness);
    void SetSceneRayTracing(bool enabled);
    void SetSceneRayTracingStrength(float strength);
    void SetSceneRayTracingReflections(float reflections, float water, float metal, float tiles, float smooth);
    void SetSceneRayTracingHitColours(bool enabled);
    void SetSceneRayTracingPlayerShadows(bool enabled);
    void SetSceneRayTracingSmoothing(float smoothing);
    void SetScenePathTracing(uint32_t bounces);
    void SetSceneTracedBeams(float strength, const float *direction);
    int GetRayTracingSupport();
    void SetSceneWaterWaves(float strength, float speed);
    void SetSceneShoreFoam(bool enabled);
    void SetSceneOwnMist(float strength);
    void SetSceneModernWater(bool enabled, bool stylised);
    void SetSceneWaterDetail(float detail);
    void SetSceneGroundDisplacement(float amount, float reach);
    void SetSceneIcyLevel(bool enabled);
    void SetSceneModernUnderwater(float amount, float surfaceY, bool wholeLevel);
    void SetSceneLightShafts(float strength);
    void SetSceneSunShadows(float strength, bool onBanjo, float softness);
    void SetSceneSunShadowDistance(float distance);
    void SetSceneGrass(float amount, float height, float distance, float density, float patches);
    void SetSceneGrassBlades(float thickness, float randomLength, bool chunky, float chunkSize, bool pixelated, float pixelSize, float blend);
    void SetSceneGrassCulling(bool frustum, bool occlusion, bool chunking);
    void SetSceneGrassLod(float lod, bool halfRate);
    void SetSceneGrassRayTracing(bool enabled);
    void SetSceneGrassTextures(const uint64_t *hashes, size_t count);
    void SetSceneGrassEdgeTextures(const uint64_t *hashes, size_t count);
    void SetSceneFur(float amount, float length, float density, float noisiness);
    void SetSceneKazooieFeathers(float amount, float size, float length, float density, float noisiness, float transparency);
    void SetSceneNpcFur(float amount, float length, float density, float noisiness);
    void SetSceneNpcFeathers(float amount, float size, float length, float density, float noisiness, float transparency);
    void SetSceneSnow(bool on, float height, bool strictColor, float detail, float refillAfter, float lodDistance, uint32_t map, bool sand);
    void SetSceneSandTextures(const uint64_t *hashes, size_t count);
    void SetSceneLampTextures(const uint64_t *hashes, size_t count);
    void SetSceneParallax(float depth, bool original, bool all);
    void SetSceneTextureSeams(bool blend);
    void SetSceneParallaxTextures(const uint64_t *hashes, const uint8_t *ranges, size_t count, const uint8_t *styles, const uint8_t *fineDepths);
    void SetSceneWaterRipples(const float x[3], const float z[3], const float age[3]);
    void SetScenePlayer(bool valid, float x, float y, float z, bool grounded);
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
    // Graphics > Water is Modern or Stylised (test aid: TOOIE_MODERN_WATER=1, 2 for Stylised, or 0 overrides it).
    std::atomic<bool> modern_water{false};
    // Graphics > Water is Stylised: Modern water with the stylised look.
    std::atomic<bool> stylised_water{false};
    // The Water reflections setting (0 to 1), and set when the water settings change, for Icy Side's override.
    std::atomic<float> water_reflections_set{0.0f};
    std::atomic<bool> water_settings_changed{true};
    std::atomic<bool> banjo_fur{false};
    std::atomic<bool> sun_shadows{false};
    std::atomic<float> sun_shadow_distance_set{3000.0f};
    std::atomic<float> sun_shadow_reach{0.0f};
    std::atomic<bool> kazooie_feathers{false};
    std::atomic<bool> npc_fur{false};
    std::atomic<bool> npc_feathers{false};
    // Graphics > Deep snow and its height (1 normal); sent to RT64 only on a map with snow.
    std::atomic<bool> deep_snow{false};
    // Graphics > Tessellated sand: deep snow's footprints, shallow, on sand textures (parallax shape Sand) on any map
    // without deep snow.
    std::atomic<bool> tessellated_sand{false};
    std::atomic<float> snow_height{1.0f};
    std::atomic<float> snow_detail{1.0f};
    std::atomic<float> snow_refill{0.0f};
    std::atomic<float> snow_lod_distance{2000.0f};
    // What was last sent (-1 to send again).
    std::atomic<float> snow_sent{-1.0f};

    // The maps with deep snow on their snowy ground: Hailfire Peaks' Icy Side and Chilly Willy's
    // arena (the shader keeps it to snow-coloured ground facing up). Test aid:
    // TOOIE_SNOW_MAPS=<hex>,<hex>... replaces the list.
    bool snowy_map(uint16_t map) {
        static const std::vector<uint16_t> maps = [] {
            std::vector<uint16_t> list;
            if (const char* forced = std::getenv("TOOIE_SNOW_MAPS")) {
                for (const char* p = forced; *p != '\0';) {
                    char* end = nullptr;
                    const unsigned long value = std::strtoul(p, &end, 16);
                    if (end == p) {
                        break;
                    }
                    list.push_back((uint16_t)value);
                    p = (*end == ',') ? end + 1 : end;
                }
            }
            else {
                list = { 0x128, 0x12C };
            }
            return list;
        }();
        return std::find(maps.begin(), maps.end(), map) != maps.end();
    }
    float heat_haze_sent = -1.0f;
    bool heat_haze_warm_sent = false;

    // Heat haze only by lava: Hailfire Peaks' lava side, its train station, Chilli Billi's fight and
    // inside the volcano.
    bool by_lava(uint8_t* rdram) {
        const uint16_t map = (uint16_t)MEM_HU(0, (int32_t)0x80132DC2);
        return (map == 0x127) || (map == 0x129) || (map == 0x12B) || (map == 0x133);
    }
    // How far into the underwater look (0 above water, 1 under), eased over a fifth of a second.
    float underwater_amount = 0.0f;
    // underwater_amount for other threads (tooie::picture_filters::underwater).
    std::atomic<float> underwater_shared{0.0f};
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

    // Banjo stands on the ground, not in the air (the game's own test, func_800A0FCC: player->0x150->0x2); true when
    // it can't be read.
    bool banjo_grounded(uint8_t* rdram) {
        const uint32_t player = (uint32_t)MEM_W(0, (int32_t)0x80135490);
        if (!valid_pointer(player)) {
            return true;
        }
        const uint32_t state = (uint32_t)MEM_W(0x150, (int32_t)player);
        if (!valid_pointer(state)) {
            return true;
        }
        return MEM_BU(0x2, (int32_t)state) != 0;
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

    // Ice textures (RT64 hashes, picked by eye from a texture dump of Hailfire Peaks' icy maps on 2026-10-17): floors,
    // walls, frozen water and blocks drawn with them reflect with Ice reflections (TOOIE_ICE_TEXTURES=<hex>,... adds more).
    constexpr uint64_t ice_textures[] = {
        // Floors: the cobbled and cracked ice.
        0xae436b1f52b9b6e6, 0xcea4f61a7e7130be, 0xbfc40d7b3dece6b7, 0xe9613c7dbc78b866,
        // Icy Side's frozen lake.
        0xd3e61b579c35618c, 0xedd50d1a56daa493,
        // Glassy ice walls and pillars.
        0x1d045b70e33827c3, 0x34f050082c5115e6, 0x35454ef2c5d88795, 0x5506dfde3b791931,
        0x7f3d8973e3b1ccad, 0x94db90a8d01cd37c, 0xc720731faa60507b, 0xcd3125fb97b26599,
        0xeef03afb17bf6360,
        // Icicle Grotto's floor.
        0xa9f95d7e99c45ea7,
        // The mottled ice of walls, platform sides and the see-through blocks round notes (drawn solid and see-through).
        0x23fb73341a90acee, 0x27a85a283bfcca1b, 0x6714212997654fa0, 0x78d3311792ce28ef,
        0xb5185cb35b5559d8, 0xc03abd6a4d9d4295, 0xd5787e1378d43620, 0xfc57075b40c809cb,
        // The see-through blocks round notes themselves (a pale blue texture, 60 triangles, seen in Icy Side 2026-10-17).
        0xe3890f274d878db4,
    };

    // Ice outside the icy maps that reflects wherever it is (Ice reflections), picked by L on 2026-10-21 in Glitter Gulch
    // Mine's Waterfall Cavern (shader_effect_tags.txt). The Ice picks join it.
    constexpr uint64_t ice_anywhere_textures[] = {
        0x31d98da7f8ab6e40, 0x37488137fb10db24, 0x5030ec15ded34bc9, 0x604279c748dde428, 0x68dbdb32fd236996, 0x7757c212c3543909,
        0x7c7d6480aa2a36a2, 0x7e3dde1e37601f1d, 0x8328161013507ecd, 0x9e1db7eb4ed945a5, 0xa05ce779f63ba5ba, 0xa0754fa808c1eec1,
        0xa0c74c8970f42515, 0xb9ba390865aa6d04, 0xc3ef62edd84ea687, 0xe0d5ce6913a1288b,
        // Ice sweep (L, 2026-10-21): crystal ice, ice blocks and icicle walls picked by eye from the 7,259-texture dump
        // (textures/ice-sweep/ice-sweep.png; water, snowy backdrops and fog left out).
        0xa111f6281c4c0ff7, 0x3ad422f50614deef, 0x7c6a08e45d7b0dcf, 0xfd9b9d2facc15775, 0x664b0c6644060bed, 0x61651a70e726dbdb,
        0xce591e8142597cca, 0x343369c2081485f9, 0xca3ac18fa0ee884d, 0x5a223ae5487e2ed2, 0x3c2fe461b635534e, 0x8736bfc30bbe4140,
        0x79a8b89ae797effa, 0x10907a3d02067a62,
    };

    // Lit lamps' textures (RT64 hashes): with Graphics > Ray tracing on, each draw with one lights the traced scene from
    // where it hangs, its frame and bars casting shadows (L, 2026-10-21). Lamp picks add more.
    constexpr uint64_t lamp_textures[] = {
        // Bottles' house: the lantern's lit pane (the game gives it no light of its own).
        0x861bfb5c8890c6e0,
        // Picked by eye on 2026-10-21 from the 7,259-texture dump (textures/banjo-tooie-textures.zip), warm and bright
        // ones first (L: a sweep to add light sources). The glow round Jinjo Village's lanterns.
        0xe18f96f57e5f4241,
        // Torch and candle flames.
        0xcec58574a22efd1f, 0x6c297cad1c8edbbf, 0x2ccf00e0c31ed884, 0x910453acfb90f339, 0x2a0bcff2df52fe7e,
        // Strip and ceiling lamps.
        0xfe7ebd28c377b54f, 0x6f59260c143a2e31, 0xfbbb2214e197d33e,
        // The second sweep, 2026-10-21 (L: everything relevant to ray tracing). Small flames.
        0xdac402b2c6689462, 0x398b65ffa9ca4c95,
        // Fires and a furnace's glowing door. (Lava and Hailfire Peaks' burning walls and edges are left out: they
        // cover the lava side, and a light per piece used up all 32 lights there, headless.)
        0xcde1f307e74ccd61, 0xacdd8a64c72db73b, 0xe330c9e79570e5d6, 0xc4b1866b2ad526fa,
        // (Not lit windows, 0xdf5bda9c967f0cf8, 0x4ace91a7ca4d04f7, 0x7982df0b74a1b2f5, 0xa8c70f9559367755,
        // 0x45b7432c37b52e79: a light's glow showed as a ball in each pane, and Window Light Beams light them.)
        // Panel and round ceiling lamps, and a small warm glow.
        0x0850e871a6ef8d8b, 0x89a3b176a1fec7d3, 0xd6288b4fa0525df4, 0x082b687364b25694, 0xd7aa28a361f6a24d,
    };

    // Shader Effects picks that ship with the port, as if picked (a player's own pick of the texture replaces it): L's
    // shader_effect_tags.txt of 2026-10-22, then the explosion and fire sweep.
    struct ShippedPick {
        uint64_t hash;
        tooie::effect_pick::Effects effects;
    };
    constexpr tooie::effect_pick::Effects fx(tooie::effect_pick::Effect a) {
        return tooie::effect_pick::Effects(1) << a;
    }
    constexpr tooie::effect_pick::Effects fx(tooie::effect_pick::Effect a, tooie::effect_pick::Effect b) {
        return fx(a) | fx(b);
    }
    using namespace tooie::effect_pick;
    constexpr ShippedPick shipped_effect_picks[] = {
        // L's picks. Explosions (Light Source), some glowing too.
        { 0x147dea7cee6cdebe, fx(effect_light) },
        { 0x60ca3428768dd6a0, fx(effect_light) },
        { 0x8fe93bef0359f4e9, fx(effect_light) },
        { 0x9cf1200adfd04a03, fx(effect_glow, effect_light) },
        { 0xa905125b3c0e82f8, fx(effect_glow, effect_light) },
        { 0xc129d9786a8369af, fx(effect_light) },
        { 0xd56f986c82dbb0b6, fx(effect_light) },
        { 0x7b06f0b824a155d5, fx(effect_glow) },
        // Lamps.
        { 0x1dd9cc6fd0e4e782, fx(effect_lamp) },
        { 0x303ca05590e1a6c8, fx(effect_lamp) },
        { 0x4ace91a7ca4d04f7, fx(effect_disable) },
        { 0x68f33cb17b917dfc, fx(effect_lamp) },
        { 0xead9da3505577c00, fx(effect_lamp) },
        { 0xeea8b5ed41ab6218, fx(effect_lamp) },
        // No texture effects.
        { 0x2c3c98c477419020, fx(effect_disable) },
        { 0xf47cb4e25f06a8f8, fx(effect_disable) },
        // The lanterns' glass (L picked Disable): Disable RT instead, so it no longer blocks the lamp's traced light
        // into black squares round each lantern (L's screenshot, 2026-10-22).
        { 0xc330b27b1c24cb3d, fx(effect_rt_off) },
        // Fire (L, 2026-10-22: light source and glow on fire), picked by eye from the texture dump: flames, torch and
        // candle flames, fire walls. (Most were Lamps, whose glow in the air drew a ball; these light with none.)
        { 0xff7cbfcbb9802b27, fx(effect_glow, effect_light) },
        { 0xdac402b2c6689462, fx(effect_glow, effect_light) },
        { 0xa995bc282a7d4f6c, fx(effect_glow, effect_light) },
        { 0x6c297cad1c8edbbf, fx(effect_glow, effect_light) },
        { 0xd65734810b0d40e3, fx(effect_glow, effect_light) },
        { 0x92aa7b146c40b48e, fx(effect_glow, effect_light) },
        { 0xcec58574a22efd1f, fx(effect_glow, effect_light) },
        { 0x927ef8d07ab0a7ac, fx(effect_glow, effect_light) },
        { 0x398b65ffa9ca4c95, fx(effect_glow, effect_light) },
        { 0x2ccf00e0c31ed884, fx(effect_glow, effect_light) },
        { 0xcde1f307e74ccd61, fx(effect_glow, effect_light) },
        { 0xacdd8a64c72db73b, fx(effect_glow, effect_light) },
        { 0xe330c9e79570e5d6, fx(effect_glow, effect_light) },
        // Embers: glow only (many small ones would use up the lights).
        { 0xd8d30fc16d3c2078, fx(effect_glow) },
        // Likely explosion frames from the dump (a fiery burst, a flash, a burst disc); the explosions L picked are not
        // in the dump, as they are drawn only when something blows up.
        { 0xfa680103e7ce6cbc, fx(effect_glow, effect_light) },
        { 0x28f275d076d8817d, fx(effect_glow, effect_light) },
        { 0x52ad0ec437488cbd, fx(effect_glow) },
        // L's shader_effect_tags.txt of 2026-10-22 (the Disable and Glow picks above are from it too).
        { 0x4f86a813903a7df4, fx(effect_disable) },
        { 0x5462e6d9c55692d5, fx(effect_disable) },
        { 0x65149dd8580c268f, fx(effect_shiny) },
        { 0x6a4311930945f097, fx(effect_shiny, effect_glow) },
        { 0x861bfb5c8890c6e0, fx(effect_glow, effect_light) },
        { 0xa0754fa808c1eec1, fx(effect_ice, effect_shiny) | fx(effect_light) },
        { 0xa95b7ee485b02d15, fx(effect_rt_off) },
        { 0xaa4fb767534de6b1, fx(effect_rt_off) },
        // The grenade egg's blast fireball (8x8 fire), found with a headless blow-up run (TOOIE_EXPLODE=a15D@<ms>).
        { 0x0f99c88fb5007ceb, fx(effect_glow, effect_light) },
    };

    // Shiny textures for Screen-space reflections besides the parallax list's metal (RT64 hashes, picked by
    // eye on 2026-10-20 from the dump's 2,618 textures the parallax sweep left out): shiny metal, gold and machine
    // parts, crystals and gems, glass and windows. No ice: Ice reflections cover it (ice_textures are left out
    // below).
    constexpr uint64_t shiny_textures[] = {
        // Metal: steel, gold, brass and copper parts, trims and machinery (140)
        0x00efe89a05c37cfc, 0x0348aba32abccf8f, 0x052e5e214b074e46, 0x05bed606aa7cf58f,
        0x06635b868db9a1eb, 0x0aaca422457e0dc8, 0x0dda4130179da841, 0x0edfaf02879af5de,
        0x1085071aeccbaaec, 0x11127cba84729a83, 0x11d730637623c0e6, 0x12b63e73a3210e1e,
        0x13a6a0d0720fceaf, 0x17ca8e1154577597, 0x190680dc86de6714, 0x196a3c1d3f89ad46,
        0x1aec3ae12f288fd4, 0x1b28f93ed91299c5, 0x1c6ea26155d5cbc7, 0x1e3c6f5b7d4fd8ec,
        0x1e46213c9605d459, 0x1fbad3057ea2a9a0, 0x1fe48ebc9374f00b, 0x2156ef1b48312f53,
        0x229d1da147c5a73f, 0x2a3b2d8357bf1f98, 0x2ad10735da950566, 0x2ae5cc6ca498ba39,
        0x2c4c96536b8b7b5a, 0x2f01c0962a3f1119, 0x35a6fa45844784aa, 0x36de1f108f8ec82e,
        0x3c6c72cebdcfda95, 0x3db08e40e41544f5, 0x3e3f11605465bf14, 0x4113c5eabdb06f71,
        0x41eb542175e8902f, 0x466039678d7e4844, 0x479848345ac366f7, 0x47f3ff36ed0edd7a,
        0x4a5e67eca512ec24, 0x4b2dabab65151e30, 0x4befcb59717f5977, 0x4cdd4b08c4cf7f6d,
        0x4edcfe29eab9f9d7, 0x52b8de47adefccf0, 0x53114bfda1182881, 0x53fd8e1dbdebb8f1,
        0x556df73cad052835, 0x55974effa10b50b2, 0x560a41300280ed02, 0x562b34c1218fd1b8,
        0x57d04f8f0c1f03c8, 0x58c70baa02f4a191, 0x594356a84a74082d, 0x5a7d42b55f050f24,
        0x5ccd85dbd5b0d3ee, 0x614bd692513046a3, 0x62a7a8ccbab246b5, 0x63332c4d31561ed1,
        0x643a5679edb3426f, 0x64a1ab6348e2c47c, 0x6579b8c1852b6fbc, 0x66fc6d958d629254,
        0x66fd10caf2d867d0, 0x67d4ebbdd56e392f, 0x6881f316689a6e95, 0x688a2f33e305417b,
        0x6bd7eef5b4b544ad, 0x6c1f6b4894437fd7, 0x6ec1169c8ac54fc5, 0x708aa6ba9de2e747,
        0x776adb5f84d53d24, 0x7ac35f509b00c0ce, 0x7cfca85b81a487c7, 0x7d6cb4d798d31abe,
        0x81a0f9248b66ce01, 0x81e1103fe17d95b5, 0x833b5594f071abb9, 0x8d2f78cc91e85f3d,
        0x9045f10c4be8e099, 0x913fa97bc6457120, 0x96e4a5b0cbd49d23, 0x9b3389ef372081ec,
        0x9ded73062322e234, 0x9f401d180568b47e, 0x9fc0b0edcf634542, 0xa07b26167b652a03,
        0xa1fbfb4b7e566e8f, 0xa26805cf6fefbda3, 0xa5faaee70e252666, 0xa7668c59352abe8a,
        0xa970e5517350bb3e, 0xacf387a35a424846, 0xb131649ad7333cef, 0xb13f0c7b6669fee6,
        0xb30eaf3c65672655, 0xb5abbfe203e51617, 0xbbafc817fb64fdb0, 0xbdbf81d7b2621f6b,
        0xbe041cdc9df375ef, 0xc0ca4ff2a78b2629, 0xc124d01e79e8fa32, 0xc1e65a8a924884d2,
        0xc21668249131f412, 0xc3a41edc2676640b, 0xc49d8d291cd81997, 0xc5b57e68f931ea8c,
        0xc5bc6261dfece826, 0xc769b5fe90c68a17, 0xc898524aba681c86, 0xc97249c30ee7b913,
        0xc9ac05812888d25f, 0xcefe98bd0b65af4a, 0xd88f0ffa83b47a39, 0xd932ef70cd7da419,
        0xdc74d77466dca12d, 0xde7a8b196a15ea8a, 0xe2cd4c17d94c0cb8, 0xe585a469e3cedbac,
        0xe6f6ea1ae92f4512, 0xeabc08f85602d542, 0xec029110fb80cb68, 0xee57aab90797e593,
        0xef37e7804f15cd3a, 0xefdc76eb8a87b8b8, 0xf05ff4fe9a8b4057, 0xf103a851e363b2ac,
        0xf25b7fe8cca57f21, 0xf3063a55e8237324, 0xf32c33cf2ddf523b, 0xf54d58565c421075,
        0xfa6da10599d876de, 0xfb20d484347e507a, 0xfb7bd58e16034e15, 0xfb822a2a95b52ab3,
        0xfcd67fa7c1ee3a97, 0xfd997b006c0d2279, 0xfeec46c1e07f6ec6, 0xff1789e72c4c5b05,
        // Crystals and gems (19)
        0x0f71ebd913354f04, 0x22402ed8424e798b, 0x2fe8e3ecae2a3740, 0x37488137fb10db24,
        0x3d6d0e08f30e0dcd, 0x5882c0aed5e94dfa, 0x5a5872a0c544c177, 0x778b12f89aaeb246,
        0x78d67b5d46fd6de4, 0x9873ab2ea6afc92b, 0x9cd99a44f36bbab5, 0xa0754fa808c1eec1,
        0xbda54fd31b527f0e, 0xc99adb3fb7f0bc02, 0xca03179894a7570f, 0xd3db47b98a571e16,
        0xe0c45d0afc26cf02, 0xe75507b6b900f558, 0xfbbc50554bf66f9b,
        // Glass and windows (6)
        0x1a1949e1f923e12d, 0x34bf2cae5467cb0e, 0x968d8376fb42d7db, 0xc9eac79984101fc0,
        0xd61b89ced680452d, 0xf7f170249a3bbefa,
        // Glazed and gold tiles (the parallax list's other tiles are stone paving).
        0x1cf577bcf120b2b6, 0x31cce062f51590d7, 0x51780acfdf66aedb, 0x563e4f62f46a44d7,
        0x5841e6ebe2f92c7a, 0x7239dd5a1ac6abf6, 0x7fd51000b2716945, 0xc9d07c3b79818c1f,
        // Notes: the gold 30-triangle model drawn only where notes are (Mayahem Temple 2026-10-20; not yet seen
        // reflecting headless).
        0x8962042db2fc940b,
        // Glossy paint (1)
        0x12c31c68cdc11203,
        // The second sweep, 2026-10-21 (for ray tracing): chrome, steel plates and slots, hammered metal, brass
        // plates, gold bars and a gold statue, and a glass tube with copper ends.
        0x1a5b229900cf51dc, 0x5df2bd92df810920, 0x65d7f51774d6f517, 0x38d2eb489e460671, 0x37ea7fb53d8476bf,
        0x864c46576cf6d66f, 0x6496a585b38c359e, 0x5fc7747fd3682881, 0x051417523e95e419, 0x0094046121ae7630,
        0x85919b047554690d, 0x2134e632976c842b, 0xdeb45d22885ce6ae, 0xeb54025ce2d6dfff, 0xd3a3c48b65567f1c,
    };

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

    // Textures with parallax mapping: stone walls, paving, brick, rock, cliff and rocky ground, and (from a second sweep)
    // plank walls and crates, roof tiles, scales and carved or embossed panels, and (a third) riveted and grated metal
    // panels, pipes, machinery and rough ground, whose brightness reads as their shape (dark gaps, grooves and cracks
    // between lighter faces), picked by eye from a texture dump of every level. A fourth sweep (2026-10-20, with the
    // shapes pick mode has) gave each its shape and depth, and added foliage, grassy and sandy ground, bark and more rock
    // and metal: 3,517 of the dump's 7,259 textures. Water, ice, glowing parts and painted or lettered textures are left
    // out: their dark parts aren't deeper. With each, its darkest and lightest brightness (0 to 255,
    // leaving out the darkest and lightest twentieth of its texels) from the same dump: its deepest and highest parts.
    // Its shape (tooie::parallax_pick::Shape, Stone unless given) and its depth in 10% steps of the Parallax setting
    // (0: 100%; the sweep's shallow is 70% and deep 150%). The ice textures (ice_textures[] and ice_anywhere_textures[])
    // are Ice, with no shadows: clear ice casts none (L, 2026-10-21).
    constexpr uint8_t Stone = tooie::parallax_pick::shape_stone, Bumpy = tooie::parallax_pick::shape_bumpy, Cracks = tooie::parallax_pick::shape_cracks,
        Terraced = tooie::parallax_pick::shape_terraced, Rounded = tooie::parallax_pick::shape_rounded,
        Grass = tooie::parallax_pick::shape_grass, Wood = tooie::parallax_pick::shape_wood, Bark = tooie::parallax_pick::shape_bark,
        Brick = tooie::parallax_pick::shape_brick, Dirt = tooie::parallax_pick::shape_dirt, Metal = tooie::parallax_pick::shape_metal,
        Leaves = tooie::parallax_pick::shape_leaves, Tiles = tooie::parallax_pick::shape_tiles, Sand = tooie::parallax_pick::shape_sand,
        Smooth = tooie::parallax_pick::shape_smooth, Ice = tooie::parallax_pick::shape_ice;
    struct ParallaxTexture {
        uint64_t hash;
        uint8_t darkest;
        uint8_t lightest;
        uint8_t shape = tooie::parallax_pick::shape_stone;
        uint8_t fine = 0;
        bool shadows = true;
    };
    constexpr ParallaxTexture parallax_textures[] = {
        { 0x0001617090b5bc7c, 50, 192, Dirt },
        { 0x00207baf52ab5405, 7, 67, Wood },
        { 0x0020873608f64060, 113, 182, Sand, 7 },
        { 0x00482294d4775195, 0, 103 },
        { 0x0051ce560cbce4b7, 27, 174, Bumpy },
        { 0x00530d3954d48881, 47, 166, Wood },
        { 0x006a53f12a6dd20c, 18, 108, Metal, 7 },
        { 0x008aa0b716f08f43, 15, 124, Bark, 15 },
        { 0x008c827b2cf0fbee, 42, 170 },
        { 0x009e8657a28070fc, 7, 110, Brick },
        { 0x00af8c0af482afca, 47, 176, Stone, 7 },
        { 0x00aff12ed28a389e, 0, 214, Rounded, 15 },
        { 0x00b9e69db35b807a, 19, 235, Smooth },
        { 0x00d476f29da6b904, 17, 168, Metal },
        { 0x00d67b34f15c4b66, 49, 158 },
        { 0x00e468c683180b2c, 58, 186, Tiles, 7 },
        { 0x00e9ec811e1b3217, 26, 92, Metal, 7 },
        { 0x00f26da1eca0d558, 75, 137, Rounded },
        { 0x00f36138f0eb86ef, 0, 114 },
        { 0x010f63904c0d8e53, 17, 170, Bumpy },
        { 0x0111c6b86ede0ade, 7, 151, Smooth },
        { 0x012341b1b0d75b56, 41, 188, Metal, 7 },
        { 0x015ef1653b33b38e, 32, 188, Smooth },
        { 0x016c50f3b51f9523, 0, 250, Brick },
        { 0x0173a13e153c861a, 0, 91 },
        { 0x017b097bae58e41e, 22, 153, Wood, 7 },
        { 0x017e2039cfd7296e, 26, 178, Metal, 7 },
        { 0x01a19f3502e26679, 28, 203, Wood, 7 },
        { 0x01a20bd62ff8cac0, 42, 151, Bumpy },
        { 0x01c5286172432ffe, 21, 72, Wood, 7 },
        { 0x01d1f490aca268a0, 63, 129, Bumpy, 7 },
        { 0x01f7b859a329e173, 11, 178, Bumpy },
        { 0x01f83d5409a3d61a, 134, 205, Cracks },
        { 0x023abf7c9623e683, 32, 180, Dirt },
        { 0x0242ac7fbca6be7c, 21, 73 },
        { 0x02526c288cb279b5, 0, 118, Metal },
        { 0x027cfdcd168638fc, 5, 110, Rounded },
        { 0x029446ed12503659, 7, 130, Bark, 15 },
        { 0x02b5cd0f24705794, 44, 201, Bumpy },
        { 0x02bd3a5b1f23e0ca, 0, 99, Metal, 7 },
        { 0x02d54ba70a8c070f, 0, 247, Metal, 7 },
        { 0x02d8c6bdefef3e0e, 31, 232, Bumpy, 15 },
        { 0x02e0da37956bb42f, 49, 170, Smooth },
        { 0x02f4c308663b9cdd, 27, 178, Cracks },
        { 0x03025b2ebbdefdbc, 52, 132, Brick, 7 },
        { 0x03127f47ae8ac2a9, 0, 84, Metal },
        { 0x032d5042d010c49d, 8, 110 },
        { 0x034df8c6d276295f, 90, 155, Bumpy, 7 },
        { 0x035442f9a6cd7efc, 5, 103, Metal },
        { 0x039014c5f7f7ea13, 17, 236, Bumpy, 7 },
        { 0x03b6793b42af3238, 52, 168, Smooth },
        { 0x03bbdd21c6a714b9, 0, 89, Wood },
        { 0x03c351eb636639d2, 10, 114, Metal, 7 },
        { 0x03cd49073d86df54, 24, 152, Tiles, 7 },
        { 0x03db71e4568f5748, 36, 154, Rounded },
        { 0x042024796e55fdbc, 18, 91, Brick },
        { 0x042df1f4b226ffea, 0, 126, Tiles, 7 },
        { 0x0454cbf0014c5593, 25, 139, Metal, 7 },
        { 0x045f7108a45e37f6, 29, 112, Brick },
        { 0x046240417ced039e, 30, 118, Brick },
        { 0x047c7b0902b966c7, 47, 184, Metal, 7 },
        { 0x04803456a4c0e866, 11, 247, Smooth },
        { 0x048101b42dee7dfa, 94, 208, Cracks },
        { 0x0486246f261fb5e4, 7, 112 },
        { 0x04abc18241190ed6, 51, 133, Grass, 7 },
        { 0x04b38d61e33f692d, 36, 125 },
        { 0x04bb9d529d73fc93, 28, 146, Wood, 7 },
        { 0x04da11e18c826c75, 28, 120, Brick },
        { 0x04e71251efe9bf4f, 28, 100, Brick },
        { 0x04ee57596d4b28a5, 10, 125, Cracks },
        { 0x04fb302be3d894ca, 21, 160, Brick },
        { 0x04fd9bf3f7fb634c, 0, 160 },
        { 0x05285cc2ae45a6c4, 101, 208, Sand },
        { 0x05451f8697959b6a, 36, 119, Wood, 7 },
        { 0x054aecc1a0dd274e, 36, 247 },
        { 0x0557af15df95d704, 9, 152, Metal, 7 },
        { 0x056644ebac6fbddc, 8, 110 },
        { 0x05749d611ab935e0, 7, 143, Stone, 7 },
        { 0x0581557796590067, 17, 169, Wood },
        { 0x0583a8b5a27a0f2f, 34, 107, Bumpy },
        { 0x058502e264bc98d7, 7, 163, Metal, 7 },
        { 0x0587796c4d31d722, 24, 156, Bumpy },
        { 0x05a3f78aff8b369c, 0, 98, Wood },
        { 0x05c383a22d00ea22, 0, 86, Wood },
        { 0x05cb187f0218b983, 55, 247, Metal, 7 },
        { 0x05de1c38a1a9bc71, 7, 134, Metal, 7 },
        { 0x05ebd26c957efd51, 50, 127 },
        { 0x0619db7ff8a981f1, 82, 177 },
        { 0x06487c3084b00b90, 0, 91 },
        { 0x065d15861a5d3e98, 0, 185, Metal, 7 },
        { 0x0677963d42f960b5, 24, 179, Bark, 15 },
        { 0x06943fa4078b534b, 0, 122, Smooth },
        { 0x06a469b76bb4c087, 0, 214 },
        { 0x06d946095e1e8a74, 21, 113, Wood, 7 },
        { 0x06fd1f7c823ffd4d, 34, 168, Metal, 7 },
        { 0x070549b9291bc325, 11, 157, Bumpy },
        { 0x073071e9ef0574b7, 24, 182, Bumpy },
        { 0x0758af959cf26fa1, 17, 141 },
        { 0x076a73c9792e9159, 11, 113, Bark, 15 },
        { 0x076b5bc2322742b8, 27, 102, Bumpy },
        { 0x077d3ca17c2aab93, 21, 72, Bumpy },
        { 0x07898912ac01ba63, 25, 170, Brick },
        { 0x078c87ad49f47581, 51, 156, Bumpy },
        { 0x07adb0a1d6c3a236, 7, 141, Metal, 7 },
        { 0x07c34be47cfc2d46, 32, 141, Leaves },
        { 0x07e2b487404b45ff, 35, 131, Wood, 7 },
        { 0x07e3114757f361f7, 10, 158, Wood, 7 },
        { 0x07fadb9ed6ad471f, 9, 115, Tiles, 7 },
        { 0x086f93e69a7af3e7, 42, 200, Metal, 7 },
        { 0x08901692870d9985, 33, 155, Metal, 7 },
        { 0x08b03b3917a0e53d, 0, 118 },
        { 0x08b8b691fe6624ca, 12, 117 },
        { 0x08cf5859441e0d11, 18, 152 },
        { 0x08ecbac398e8acc8, 7, 98, Metal, 7 },
        { 0x08efc1acd4d7873b, 28, 96, Wood, 7 },
        { 0x08f4425ab40876af, 10, 107, Metal, 7 },
        { 0x0907b72f10e10130, 42, 149, Dirt },
        { 0x0909c16e0270ec5b, 30, 105, Metal, 7 },
        { 0x090c7bb53421a5d8, 17, 85, Brick },
        { 0x090f275a00912965, 16, 169, Leaves },
        { 0x092351194c1d7fde, 74, 166, Bumpy, 7 },
        { 0x093cc9ccdbd7fbc6, 31, 60, Cracks },
        { 0x0948d26fcc074602, 31, 109, Brick },
        { 0x0963a8b4980537c9, 15, 113, Wood, 7 },
        { 0x0985b20cc572c72a, 10, 68, Metal, 7 },
        { 0x09914b8f8d763849, 15, 152, Bumpy },
        { 0x099a9f9db0686f97, 29, 216, Metal, 7 },
        { 0x09a95b195ca80f47, 34, 133, Bumpy },
        { 0x09c8d97492215a1c, 5, 100, Stone, 7 },
        { 0x09d001eee961a505, 56, 172 },
        { 0x09d4460093cd1b06, 46, 113, Wood, 7 },
        { 0x0a177dafc9884d69, 7, 133, Bumpy },
        { 0x0a71cef9d3bd7ba5, 39, 137, Leaves },
        { 0x0a898c8110877f60, 71, 132, Wood, 7 },
        { 0x0a8ab18ab03849e9, 0, 162, Brick },
        { 0x0aa9a582b5232a32, 10, 123, Metal, 7 },
        { 0x0aadc698877ce9c1, 17, 173, Rounded },
        { 0x0acdfffb9d510a4f, 7, 202, Leaves },
        { 0x0ae31e046f941ba9, 23, 67, Metal, 7 },
        { 0x0ae61fb14f1e99b2, 25, 151, Wood },
        { 0x0af1112ec4df3eb2, 25, 171, Rounded },
        { 0x0b241fb227091fcf, 27, 129, Bark },
        { 0x0b48179bcf40c42a, 0, 204, Tiles, 7 },
        { 0x0b4f0f983b650d34, 12, 133, Brick },
        { 0x0b89bb5e00b0a9a9, 45, 133 },
        { 0x0b9074258b557836, 24, 173 },
        { 0x0ba04cec6e510120, 56, 140, Dirt },
        { 0x0bbfca0a807b10fe, 0, 56, Stone, 7 },
        { 0x0bdbfde92d8b6af8, 10, 148, Metal, 7 },
        { 0x0bee1300e82d7fe9, 16, 107, Bumpy },
        { 0x0c07e769b88ae3b9, 57, 159, Cracks },
        { 0x0c122afe3131d183, 0, 151, Bumpy },
        { 0x0c26fe447120fe5c, 0, 126, Metal, 7 },
        { 0x0c2ce5c89c75ba28, 58, 131 },
        { 0x0c3d8e6c04be8c76, 41, 232, Rounded },
        { 0x0c7f62cbb821e620, 36, 160, Bumpy },
        { 0x0c92eb1cfd58574c, 7, 114, Metal, 7 },
        { 0x0cb8f7b5fa258c0b, 27, 128, Bumpy },
        { 0x0d13300aafa10c10, 50, 114, Metal, 7 },
        { 0x0d37af26aaeb15b6, 97, 243, Metal, 7 },
        { 0x0d63ce2a735f9856, 15, 76, Bumpy },
        { 0x0d6cc6ae8e0b6ada, 49, 173, Bumpy },
        { 0x0d720fd875569e0e, 35, 118, Metal, 7 },
        { 0x0d85f1ae3d64d3e3, 30, 194 },
        { 0x0d8a636077ffb178, 0, 112 },
        { 0x0d95d1914a9eff7a, 0, 121 },
        { 0x0db43da5f245d34e, 17, 178 },
        { 0x0e3a4bc9be058c2e, 18, 214, Wood },
        { 0x0e4e50c6a794a89a, 27, 151, Wood },
        { 0x0e61666be36c8681, 22, 94, Wood, 7 },
        { 0x0e6d75d401b81308, 33, 140, Tiles, 7 },
        { 0x0e73ebfab5c0d509, 4, 166, Leaves },
        { 0x0e974c21aabbaae7, 24, 128, Cracks },
        { 0x0ea6b2ac63243fdf, 14, 165, Rounded },
        { 0x0ebbdf02942c77e7, 48, 233, Metal, 7 },
        { 0x0ec1efbf5ae74d98, 11, 156, Bumpy },
        { 0x0ecbb92b29b4d25b, 15, 163, Tiles, 7 },
        { 0x0ecfd1de4e3661e5, 17, 125, Metal, 7 },
        { 0x0ed9da708f327983, 23, 130 },
        { 0x0edfaf02879af5de, 39, 226 },
        { 0x0ee8ea44c59721e0, 28, 225, Metal, 7 },
        { 0x0f346c3e5d70fcdd, 0, 103, Leaves },
        { 0x0f35dad372d3c950, 33, 161 },
        { 0x0f47265a11157ba4, 21, 164 },
        { 0x0f634207ad561508, 20, 175, Brick },
        { 0x0fa7b53b50030580, 35, 197, Metal, 7 },
        { 0x0fac4e76d9d0740f, 29, 87, Metal, 7 },
        { 0x0fbaf3fc6be0c0bf, 29, 89, Bumpy },
        { 0x101b67e86f3893fa, 4, 121 },
        { 0x101e9cc1b3fcd36e, 25, 165, Metal, 7 },
        { 0x101f4b499fe3d3f5, 0, 67, Metal, 7 },
        { 0x102d22c51813bc65, 53, 189, Metal, 7 },
        { 0x1037b3163eac3233, 10, 159, Metal, 7 },
        { 0x105556f416b5e4d5, 59, 155, Metal, 7 },
        { 0x1064da053ed6ce3c, 11, 120, Bumpy },
        { 0x10893c3bd73b6416, 25, 84, Brick },
        { 0x10907a3d02067a62, 42, 230, Ice, 0, false },
        { 0x10941e5603ffe40c, 0, 116, Metal, 7 },
        { 0x109aa92135290686, 0, 159, Metal, 7 },
        { 0x10b2ea1809b77d5a, 7, 148 },
        { 0x10b94d91f8f5fc4a, 22, 119, Bumpy },
        { 0x10dcb2c0ab82681a, 14, 102, Bark },
        { 0x10eef767501d0eb1, 24, 132, Metal, 7 },
        { 0x110a128d8494c1d5, 19, 213, Bumpy },
        { 0x11127cba84729a83, 5, 83 },
        { 0x111ab27c1868db39, 42, 159 },
        { 0x112b6b8287194ac4, 51, 121 },
        { 0x1140c796753bd399, 7, 113, Smooth },
        { 0x114175582bfa83cc, 0, 111 },
        { 0x11449cf3a53749b9, 11, 157 },
        { 0x114782302a4b4161, 31, 149 },
        { 0x11484d16216dd776, 61, 217 },
        { 0x116af19cd2c300dc, 63, 215, Bumpy },
        { 0x11772d49e968bed8, 28, 134, Bumpy },
        { 0x118c257109a1f09b, 15, 122 },
        { 0x11a67bfad0df309f, 29, 147, Wood },
        { 0x11b62abb87909103, 19, 182, Smooth },
        { 0x11c90c285da5ba84, 17, 209, Metal, 7 },
        { 0x11d730637623c0e6, 33, 228 },
        { 0x11d844c946fd5bd9, 35, 109 },
        { 0x11fa704293b8565e, 0, 149 },
        { 0x121cacd1869f6d0e, 26, 78 },
        { 0x122aedafd43e2a9e, 0, 134 },
        { 0x122afdf6f57475b5, 14, 107, Bumpy },
        { 0x12341e9f3dc350f0, 7, 100 },
        { 0x1254af638b17791b, 24, 143, Wood, 7 },
        { 0x127747e7605a42c9, 0, 152, Metal, 7 },
        { 0x127daf28296ab861, 10, 137, Bumpy },
        { 0x128837f2944a3283, 15, 144 },
        { 0x12a01dce86076f8b, 0, 66, Brick },
        { 0x12a1df75fed0b12a, 33, 164, Wood, 7 },
        { 0x12b1b32194c9de3a, 15, 115, Wood },
        { 0x12b8a356001fb299, 25, 84 },
        { 0x12dff97cff65d958, 0, 168, Metal },
        { 0x12f50c86fe16cfac, 95, 172, Cracks },
        { 0x130beaeab5a263d2, 51, 237, Smooth },
        { 0x1316c252f25ead06, 101, 195, Bumpy, 7 },
        { 0x132a903d7672de70, 0, 135 },
        { 0x133010d9f09ec074, 44, 150, Rounded },
        { 0x136db0f01dc11442, 17, 80, Brick },
        { 0x1374ddbadc030f0c, 33, 74, Bumpy, 7 },
        { 0x13764347db5fb09e, 49, 174, Bumpy },
        { 0x13ab04610ebf4632, 7, 159, Wood },
        { 0x13b2750824b2202e, 30, 132 },
        { 0x13b47e670150a364, 55, 157, Smooth },
        { 0x13c036e7abd0c772, 32, 161, Cracks },
        { 0x13cc5c48c05a3c1e, 13, 100, Smooth },
        { 0x13d329ee4fc7ece5, 33, 105, Bumpy, 7 },
        { 0x13e2a684ff459045, 88, 150, Bumpy, 7 },
        { 0x13f3e647168b2d8c, 7, 152, Bumpy },
        { 0x13f5fef8083ed33d, 18, 181 },
        { 0x14018832fcf55524, 36, 207, Rounded },
        { 0x144868d838262664, 23, 181, Metal, 7 },
        { 0x1455119a6e290587, 41, 215, Stone, 7 },
        { 0x14583ac053876808, 2, 132, Metal },
        { 0x14716a97ec6ef4fa, 15, 151, Metal },
        { 0x1489b248dd0d4d3c, 57, 182 },
        { 0x14a1a79ae73a5498, 7, 213 },
        { 0x14b1c0dd7464f1a7, 22, 234, Stone, 7 },
        { 0x14d0dd9bde7bdb6a, 18, 188, Cracks },
        { 0x14e5ef57e21fae5b, 35, 183 },
        { 0x14f99c90e77ed2e0, 18, 135 },
        { 0x150938e5610de722, 7, 154 },
        { 0x150ccf1882ca812a, 0, 113, Metal, 7 },
        { 0x1511b198f2b565f2, 10, 75, Metal },
        { 0x151e5f17937c2e4f, 32, 161, Cracks },
        { 0x157f74fb68f76204, 36, 91 },
        { 0x159957192eaf3818, 21, 119, Bumpy },
        { 0x15999601cee2ba0f, 58, 166, Bumpy },
        { 0x15cd2bca81a90156, 57, 119, Wood, 7 },
        { 0x15d93fc6bf173fbc, 25, 208, Metal },
        { 0x15fab549689b8a4a, 56, 247, Bumpy, 7 },
        { 0x161ab8b4f1bf2946, 18, 222 },
        { 0x1622786fa68af183, 36, 139 },
        { 0x164b389e046c6924, 7, 113 },
        { 0x164d4747ed428a76, 15, 148, Metal },
        { 0x16591883f1bb0837, 7, 154, Bumpy },
        { 0x16c01eccb1be46b0, 0, 109, Metal },
        { 0x16d20762d85bed44, 34, 108 },
        { 0x16d32fb024e3f64f, 7, 115, Metal },
        { 0x16d813ec4c6886e0, 52, 164, Rounded },
        { 0x16da0a13905c997b, 35, 201, Metal },
        { 0x16fa295c3bc277f2, 34, 135, Cracks },
        { 0x16fdc5a3c17ce480, 7, 107, Bumpy },
        { 0x1702281d1e11147a, 0, 116, Metal, 7 },
        { 0x17233311b0615ad2, 31, 132, Metal, 7 },
        { 0x1740f25e08d7a4f0, 11, 152 },
        { 0x1775baf0ac5b3e0e, 28, 97, Cracks },
        { 0x177627a656018689, 41, 156, Bumpy },
        { 0x1795215954789e3b, 132, 238 },
        { 0x179b56c5de8563a8, 21, 87, Tiles },
        { 0x17d816065d5438f6, 10, 146, Leaves },
        { 0x17e89485732ff080, 22, 179, Rounded },
        { 0x17ee8f70d3dfadac, 18, 163 },
        { 0x18014201a9e8aeb8, 11, 146, Bumpy },
        { 0x1802883858572e53, 0, 91, Wood },
        { 0x1825705c2e0926e1, 9, 156, Metal, 7 },
        { 0x18425abb87034a2d, 9, 123 },
        { 0x1846b340aed3e00b, 17, 104, Rounded },
        { 0x184ed47ff30463fb, 25, 129 },
        { 0x186e8be285231006, 41, 189, Metal, 7 },
        { 0x18767254f0e3ee1a, 10, 225, Rounded, 15 },
        { 0x1876a6e9ec585c9d, 44, 140, Bumpy, 7 },
        { 0x18802e314f707546, 11, 140, Bumpy },
        { 0x1897b801adce374a, 28, 139 },
        { 0x18a54811e1066b76, 25, 171 },
        { 0x18c6fe4a9ae54c94, 4, 148, Leaves },
        { 0x18facd90790db747, 29, 73, Tiles, 7 },
        { 0x1908c1102ecf9ead, 24, 178 },
        { 0x190911b98a55dc15, 29, 138, Smooth },
        { 0x190f4978edb951a8, 23, 220, Bumpy, 7 },
        { 0x1912b4a0b0ffd817, 40, 130, Metal, 7 },
        { 0x191a787d7555e8ec, 2, 238, Rounded },
        { 0x191b3515c6cc7bbc, 0, 108, Bumpy },
        { 0x192d157685ef8d65, 46, 136, Metal, 7 },
        { 0x19323aba8123c7ed, 0, 107, Bumpy },
        { 0x1954f93573c7319d, 68, 147, Bumpy },
        { 0x1962acc70568fb09, 36, 155, Metal },
        { 0x1982ec7379b81ba0, 45, 183, Metal },
        { 0x198e1fb4cd483963, 58, 233, Metal, 7 },
        { 0x19ca60a2f6755840, 10, 107, Brick },
        { 0x1a0d7971ab2275d8, 7, 168, Metal },
        { 0x1a1092ee16031d22, 126, 210, Metal, 7 },
        { 0x1a27d1c1a36b1d4c, 0, 163, Stone, 7 },
        { 0x1a38b16d514dad93, 24, 140, Bumpy },
        { 0x1a72ccadffbe44cf, 14, 127 },
        { 0x1a7773fc099b83b4, 0, 234, Metal, 7 },
        { 0x1a8f1ef8d446cd4e, 17, 195 },
        { 0x1a97b5d2b1c8fc7c, 17, 66, Bumpy, 7 },
        { 0x1aa016c6c3535ee7, 25, 181, Rounded },
        { 0x1aba331288298a61, 0, 148, Metal, 7 },
        { 0x1abfa29ff62afd58, 9, 159, Bumpy },
        { 0x1ac9283ecbec37cf, 17, 106, Metal, 7 },
        { 0x1ad1d807e0b0e3aa, 36, 244, Leaves },
        { 0x1aec3ae12f288fd4, 0, 70 },
        { 0x1b25f68a48a672cd, 35, 117, Wood },
        { 0x1b67637c8907dfab, 7, 49, Wood },
        { 0x1bac890c8e1f35b6, 59, 124, Bumpy },
        { 0x1bb3ebe4bcb6e072, 7, 116 },
        { 0x1bc411ce2285f1f2, 10, 111, Wood },
        { 0x1bd9baa5f2f17fac, 13, 137, Brick },
        { 0x1bf911b09a06c668, 56, 147, Bumpy },
        { 0x1c0de8001f4b462c, 0, 69, Brick },
        { 0x1c103fd522c14708, 13, 141 },
        { 0x1c2127b15f26ab87, 64, 176 },
        { 0x1c2a9ea9ff441502, 0, 105 },
        { 0x1c31c9737da2106f, 15, 154, Leaves },
        { 0x1c3a1a23a7b9c948, 50, 126, Wood },
        { 0x1c4601767b60e7af, 47, 207 },
        { 0x1c477d99e3583bd8, 46, 190 },
        { 0x1c5a4be8a548485b, 15, 247, Wood },
        { 0x1c61d35ec26c686b, 22, 142 },
        { 0x1c77f41e6611307f, 68, 201 },
        { 0x1c801aa2ffd39655, 0, 126, Brick },
        { 0x1ca19caa4fbe37f7, 128, 210, Bumpy, 7 },
        { 0x1ca76f03df594354, 24, 181 },
        { 0x1ca8e1c62aab2958, 40, 151, Rounded },
        { 0x1cb455e939406b6e, 0, 152, Brick },
        { 0x1cbce9fbfc67f8f1, 33, 206, Bumpy },
        { 0x1cd41d958b58ae0b, 29, 120 },
        { 0x1cd8068e6bcc894d, 7, 144, Wood },
        { 0x1cd82040c8e5ddd8, 7, 192 },
        { 0x1ce159cf573ed433, 0, 105 },
        { 0x1cf577bcf120b2b6, 9, 219, Tiles, 7 },
        { 0x1d02d26d18562bdc, 39, 233, Brick },
        { 0x1d045b70e33827c3, 13, 214, Ice, 0, false },
        { 0x1d1be3fa4faed238, 63, 167, Bumpy },
        { 0x1d57571bbe0ec873, 18, 58, Bumpy, 7 },
        { 0x1d65da6219880aab, 0, 134 },
        { 0x1d814fb7964f7ca0, 45, 132, Smooth, 7 },
        { 0x1d8a3ade736c08b0, 7, 70, Wood },
        { 0x1d95a6340195d0fd, 20, 188, Rounded },
        { 0x1d9864f780fbbde3, 15, 114, Metal, 7 },
        { 0x1dbadfa9c36b09cc, 0, 115, Metal },
        { 0x1dd17a9ddda66c12, 30, 183, Smooth },
        { 0x1dfd70ab704b021a, 0, 151, Bumpy },
        { 0x1e0f01ca6d40970c, 90, 206 },
        { 0x1e1202f2aac0edc8, 68, 181, Metal, 7 },
        { 0x1e1ee3ff71f15d16, 63, 203, Bumpy, 7 },
        { 0x1e20284f29c8928c, 31, 70 },
        { 0x1e2364ae05c62c38, 37, 162 },
        { 0x1e2790b1f6169b5f, 21, 128 },
        { 0x1e37817816ef83d4, 37, 210 },
        { 0x1e399afb007292d1, 33, 235, Smooth },
        { 0x1e43fa7dfa7d915b, 52, 175, Bumpy, 7 },
        { 0x1e4a2512c902a8c7, 7, 148, Bumpy },
        { 0x1e60e2ac8d71306f, 0, 64 },
        { 0x1e6dd94ed8a990c8, 10, 133, Wood },
        { 0x1e79ef1a846df074, 34, 126, Wood, 7 },
        { 0x1e8a5cab889e2064, 21, 105, Wood },
        { 0x1ea82d16871f2d25, 10, 143, Leaves },
        { 0x1eb2eca5bca66ef1, 17, 199, Brick },
        { 0x1ebcf8526dcfa985, 7, 124, Brick },
        { 0x1ecd9da1cd71b9c1, 14, 108, Rounded },
        { 0x1ed83f658c7847ca, 38, 96 },
        { 0x1eebf29d375d666e, 22, 167, Bumpy },
        { 0x1eefa00761536012, 18, 111 },
        { 0x1f086963dbb8f6be, 56, 187, Smooth },
        { 0x1f23e732ad1c087e, 29, 83, Metal },
        { 0x1f23fd001952a893, 21, 67, Dirt },
        { 0x1f4ee418a010ea90, 90, 198 },
        { 0x1f50c760a645f00c, 56, 173, Tiles, 7 },
        { 0x1f642febef0807d9, 34, 204, Bumpy },
        { 0x1f6df3999f824572, 16, 118, Rounded },
        { 0x1f7329662a94ec5a, 24, 134 },
        { 0x1f98ebb7b5b0d5fc, 25, 141, Bumpy, 7 },
        { 0x1f9a464e981dbb75, 11, 111, Metal, 7 },
        { 0x1fb25ff677dc08a4, 23, 242, Smooth },
        { 0x1fbc8134671de73e, 15, 155, Bumpy },
        { 0x1fdc19958c228c7f, 105, 191, Rounded },
        { 0x1fdcfcc6bb86af21, 31, 196 },
        { 0x1ff9596be308271f, 18, 180, Metal },
        { 0x200d1bdd07959c4c, 15, 163, Bumpy },
        { 0x20207ef77ec6bbcb, 52, 223, Bumpy, 7 },
        { 0x2047ab093f604e00, 36, 247, Brick },
        { 0x205f61a8748197a3, 32, 128 },
        { 0x206ae5d42840ca3c, 115, 232, Rounded },
        { 0x20a4d4611b9c53db, 56, 130, Bumpy, 7 },
        { 0x20a516cb84fd4fac, 4, 43, Bumpy, 7 },
        { 0x20a785b60e758faa, 7, 167, Metal, 7 },
        { 0x20a7e9c989f3dcfc, 30, 116, Brick },
        { 0x20de52f743e5a323, 10, 100 },
        { 0x20dfc8619cdc4cd0, 0, 132, Metal, 7 },
        { 0x20e6bd7ef8f9cc54, 0, 187, Bumpy, 7 },
        { 0x2105bf707addd155, 7, 124, Metal, 7 },
        { 0x210ec922b8fd22ff, 29, 125, Bumpy },
        { 0x212e1e97a48d8b0f, 0, 136, Stone, 7 },
        { 0x2147a623c7f969c5, 64, 117, Bumpy },
        { 0x215f9a11c949d672, 15, 137 },
        { 0x2175d986e68cb690, 15, 74, Metal, 7 },
        { 0x217bcdd8b080800f, 20, 98, Brick },
        { 0x21b015a85b4feaea, 21, 99, Bumpy },
        { 0x21b3744ca6fe7c02, 33, 159, Bumpy },
        { 0x21ceab0812e99c55, 2, 111, Wood, 7 },
        { 0x2204434e37303bf8, 17, 152, Bumpy },
        { 0x22192b154844f2be, 0, 153 },
        { 0x223413d0d5676218, 21, 114, Leaves },
        { 0x22351bd331a5b5ab, 7, 156, Metal, 7 },
        { 0x225765292d5b73c3, 67, 217, Stone, 7 },
        { 0x225ada1141303cf8, 14, 167, Bumpy },
        { 0x226edf6d94fe0a41, 2, 188, Wood, 7 },
        { 0x22760748d9723119, 17, 156, Metal, 7 },
        { 0x22a9b309f8b4fc87, 15, 170, Wood, 7 },
        { 0x22b51966ddcfd3fc, 7, 192, Wood, 7 },
        { 0x230c9131758d4ba7, 20, 171 },
        { 0x23224d671fc665d8, 53, 197, Wood, 7 },
        { 0x235dc89e116701d8, 32, 92, Stone, 7 },
        { 0x237048ef667d8a70, 32, 149, Bumpy },
        { 0x2372f8a9903c3e85, 30, 126, Bumpy },
        { 0x238051715167af46, 43, 135, Rounded },
        { 0x238b97fae060c8f8, 27, 140, Wood, 7 },
        { 0x23a025da09940ab1, 25, 198, Rounded },
        { 0x23a3d09bbf529e17, 21, 122, Bumpy },
        { 0x23d06fbd7a635eab, 21, 195 },
        { 0x23d41c45d9e4d86b, 19, 92, Leaves },
        { 0x23da8d9c0c994fad, 0, 247, Bumpy },
        { 0x23e3d7909b58a62e, 10, 200, Rounded, 15 },
        { 0x23e40866e4cbcb67, 33, 155, Metal, 7 },
        { 0x23f3f4080f184ce4, 30, 208, Wood, 7 },
        { 0x23f567fdfd7fe9f5, 2, 147, Metal, 7 },
        { 0x23f7a96f9be65361, 64, 170, Smooth },
        { 0x23fb73341a90acee, 30, 107, Ice, 0, false },
        { 0x2428c6d4951a83db, 0, 48, Bumpy },
        { 0x2449ee8a63579727, 43, 111, Wood, 7 },
        { 0x2489804c2d11d428, 40, 126, Wood, 7 },
        { 0x248aa036fc69695f, 0, 139, Brick },
        { 0x249b9cd5c2ba5d94, 52, 150, Cracks },
        { 0x24a866cbfbe77c8f, 0, 148, Bumpy },
        { 0x24b2ff54def3f3bb, 76, 153 },
        { 0x24cc6d97bc0497e8, 40, 161 },
        { 0x25009b25e09ef610, 0, 119 },
        { 0x251409fef3a6d871, 15, 173, Metal, 7 },
        { 0x251bb9c42f8dddca, 16, 96, Bumpy },
        { 0x252edfa734e82676, 43, 154 },
        { 0x253de8cef41fce79, 193, 229, Sand, 7 },
        { 0x254400c02ffd8896, 48, 116, Bumpy },
        { 0x25457d3bb185de55, 15, 175, Rounded },
        { 0x25486c84ff34fafc, 0, 221, Metal, 7 },
        { 0x257c9da8f87fafd7, 16, 155, Terraced },
        { 0x259a18f4fdd53846, 54, 173, Smooth },
        { 0x25ff3da7a7aca4ab, 28, 216, Metal, 7 },
        { 0x2622425a5d2c5594, 33, 200, Bumpy },
        { 0x266cbcb83a2c4e46, 15, 155, Metal, 7 },
        { 0x267df4b5979bc3a2, 2, 148, Wood, 7 },
        { 0x2681a4500e6a8994, 78, 207 },
        { 0x26864fb216a36c99, 9, 144 },
        { 0x268e0793d0460c67, 47, 162, Rounded },
        { 0x26a08f5b58a1d0c6, 28, 185 },
        { 0x26a490d4fbdd412c, 17, 108, Brick },
        { 0x26b93de16d8ade89, 17, 106, Wood, 7 },
        { 0x26d9275494bd9623, 58, 239 },
        { 0x2706642fc029ed45, 10, 184, Brick },
        { 0x270fdf707f2afda5, 7, 148, Bumpy },
        { 0x2714c4351dddd476, 15, 118, Metal, 7 },
        { 0x271c67a54d422fde, 17, 171, Bumpy },
        { 0x27248e8f62bb7cce, 56, 181, Bumpy, 7 },
        { 0x272edb1ad6fdf4b2, 3, 157, Metal, 7 },
        { 0x273e78009b937fde, 15, 140, Smooth },
        { 0x275a6695c97c94e8, 14, 108 },
        { 0x27703be820f9c016, 15, 148, Metal, 7 },
        { 0x27773327f32d3637, 9, 90, Cracks },
        { 0x27a85a283bfcca1b, 22, 181, Ice, 0, false },
        { 0x27ab6c27c9b08a64, 40, 130, Metal, 7 },
        { 0x27e39ebd724fa6fa, 7, 140, Bumpy, 15 },
        { 0x27f004c07ab108c9, 7, 158, Bumpy },
        { 0x2800998e3e6e128a, 33, 179, Bumpy },
        { 0x280a02e4f7c5a0c0, 15, 114, Metal, 7 },
        { 0x282ea347b50e0bac, 34, 100, Smooth },
        { 0x282fbeb862a85c9d, 7, 130, Bark, 15 },
        { 0x28361c09062cae44, 62, 118, Dirt },
        { 0x2847ad566a599458, 99, 186, Dirt },
        { 0x28621a62c2f98de6, 15, 161, Bumpy },
        { 0x2874016ef8106c8b, 27, 171, Bumpy },
        { 0x287b88a191185278, 20, 94, Cracks },
        { 0x28816a52cffaffd2, 42, 126, Wood, 7 },
        { 0x28862d457543e7f7, 53, 134, Bumpy },
        { 0x289a0fd56604a5de, 16, 139, Smooth },
        { 0x28a0635092959f3c, 17, 88, Cracks },
        { 0x28c9aaebee1ba5c1, 17, 136, Bumpy },
        { 0x28d761c3889d819d, 55, 189, Wood, 7 },
        { 0x28e8588b6991b215, 15, 180, Bumpy },
        { 0x28ee377b5789d255, 68, 157, Metal, 7 },
        { 0x28f2a101e74f0482, 7, 138, Bumpy },
        { 0x28f2a5f86eac2153, 40, 187, Bumpy },
        { 0x29213aa45f5482b7, 24, 180, Smooth },
        { 0x2929d26c14e07ef9, 16, 104, Bumpy },
        { 0x29301132791f05a4, 37, 184 },
        { 0x293394aeaf0bf7f7, 21, 128, Bumpy },
        { 0x299492d7f011d979, 62, 144, Tiles, 7 },
        { 0x299643e72e19a2fd, 25, 181, Bumpy },
        { 0x29afa93f32d446fa, 7, 189 },
        { 0x29bd187bd97fb9af, 44, 104, Metal, 7 },
        { 0x29db1455d2225b58, 53, 183, Cracks },
        { 0x29e022a606c437d5, 75, 165, Dirt },
        { 0x29ff2dbbec000348, 23, 101, Metal, 7 },
        { 0x2a1db0c6b37dcd37, 9, 87, Leaves },
        { 0x2a1e382c0af72af8, 48, 114, Tiles, 7 },
        { 0x2a3b2d8357bf1f98, 30, 161 },
        { 0x2a40634ae7333cbc, 36, 204, Wood, 7 },
        { 0x2a45ba63f86c03ed, 0, 94, Bark, 15 },
        { 0x2a46e6b4b2c5a030, 0, 118, Leaves },
        { 0x2a48c72207ef5f8b, 34, 137, Rounded },
        { 0x2a4c770f525bb349, 20, 200, Bumpy },
        { 0x2a5cc30b0ca6b260, 23, 226, Bumpy },
        { 0x2a6d84162fe5ca56, 24, 151, Metal, 7 },
        { 0x2a81b88577db0aa0, 38, 140, Wood, 7 },
        { 0x2a8d6a30da13090b, 15, 247, Metal, 7 },
        { 0x2a9cf0a6c42633b3, 77, 200, Bumpy },
        { 0x2aa195e2eace52f9, 0, 84, Bumpy },
        { 0x2aaf3716f3e0cb89, 29, 122, Bumpy },
        { 0x2ab2aa4811471a25, 12, 103, Bumpy },
        { 0x2abef6447d8bb67f, 16, 98, Cracks },
        { 0x2ad4289996a301a5, 27, 207, Bumpy },
        { 0x2ad64370d222517d, 2, 133, Smooth },
        { 0x2ae48b484bb37dcc, 7, 175, Bark, 15 },
        { 0x2ae5cc6ca498ba39, 9, 232 },
        { 0x2aee29e9d696ffff, 61, 197 },
        { 0x2af032dcdc6a22c6, 0, 190, Smooth },
        { 0x2af5f3ba1f30be9f, 0, 167, Metal, 7 },
        { 0x2b11673964a8f29e, 41, 135, Bumpy, 7 },
        { 0x2b1839e0b24169cb, 24, 143, Stone, 7 },
        { 0x2b494c596f26c1d6, 53, 194 },
        { 0x2b53fa967c6701cf, 40, 189, Wood, 7 },
        { 0x2b952321557a1eb2, 50, 226, Tiles, 7 },
        { 0x2ba22618e11267ab, 7, 199, Brick },
        { 0x2bb372b8886710e0, 23, 166, Bumpy },
        { 0x2bef665340a0a4ee, 53, 154, Leaves },
        { 0x2c054b48e1d45e6f, 27, 141, Leaves },
        { 0x2c221ae5873ce190, 15, 140, Wood },
        { 0x2c411f4cbdc79aef, 58, 247, Bumpy },
        { 0x2c4c210d292064b1, 35, 95, Metal, 7 },
        { 0x2c50fd0f3632ea7a, 28, 118, Metal, 7 },
        { 0x2c5a288c98a88850, 35, 220, Wood, 7 },
        { 0x2c5ee157edecc832, 56, 247, Smooth, 7 },
        { 0x2c717280b37a0c07, 24, 138, Bumpy },
        { 0x2c8b524bbb6d71b9, 0, 63, Cracks },
        { 0x2c9a20de7fefae7e, 15, 170, Rounded },
        { 0x2cd0abf9ab268afa, 14, 64, Dirt },
        { 0x2cd73e1f0ef5548c, 4, 170, Wood, 7 },
        { 0x2cefe335c40dace1, 24, 151, Bumpy },
        { 0x2d0ca1a473f2dcf7, 97, 183, Sand, 7 },
        { 0x2d26a49f244b938f, 34, 170, Leaves },
        { 0x2d2e21e3471bd739, 0, 90 },
        { 0x2d3a127caca18bb2, 0, 122, Metal, 7 },
        { 0x2d640c671fdcd117, 50, 140, Tiles, 7 },
        { 0x2d7d2ec2c7c74ced, 58, 108, Dirt, 7 },
        { 0x2d8f695884ce28cc, 0, 173, Metal, 7 },
        { 0x2d9fe2af34c82213, 0, 88, Wood, 7 },
        { 0x2dc30f0bf1ba0e86, 7, 173 },
        { 0x2dcd4f0bbb758593, 27, 136, Bumpy },
        { 0x2ddf6a64b03476e3, 13, 125, Metal, 7 },
        { 0x2e0f7ad7b661ef0f, 7, 109, Stone, 7 },
        { 0x2e1744031baa92ac, 26, 150, Metal, 7 },
        { 0x2e2bbcdb71ccf658, 38, 247, Metal, 7 },
        { 0x2e330ae57edadb13, 50, 86, Dirt, 7 },
        { 0x2e3b3e10123050d9, 14, 165 },
        { 0x2e3bdde1aac971fd, 36, 114, Tiles, 7 },
        { 0x2e406ee24c1c05ae, 15, 162, Bumpy },
        { 0x2e4c957b3a9fada4, 49, 171, Metal, 7 },
        { 0x2e5f973666a32a60, 5, 105, Rounded, 7 },
        { 0x2e8089498692e2b7, 10, 114, Metal, 7 },
        { 0x2e939d2b5bc3ded2, 10, 182, Bumpy },
        { 0x2e94c2898e1204e0, 10, 137, Metal, 7 },
        { 0x2ebdaf343f78e7cb, 15, 199 },
        { 0x2ec7da4af9e4495f, 34, 74, Metal, 7 },
        { 0x2ede23f667c073fd, 0, 142 },
        { 0x2ee0e978870db1e8, 0, 57, Bumpy, 7 },
        { 0x2ee86a3a07b8ea74, 0, 139 },
        { 0x2f06a8993ea35595, 3, 91, Stone, 7 },
        { 0x2f180d19c9fec40b, 0, 92, Metal, 7 },
        { 0x2f2c8684cbe3f0a5, 74, 147, Smooth, 7 },
        { 0x2f322f6ecaf14b27, 25, 192, Metal, 7 },
        { 0x2f3f0b21ea3e7371, 15, 92, Metal, 7 },
        { 0x2f40da9927154dd2, 11, 106, Cracks },
        { 0x2f4fa3f6d0d6c5f4, 0, 220, Bumpy },
        { 0x2f546478c2c69b4a, 119, 173, Sand, 7 },
        { 0x2f56aaed7d0fc642, 60, 238 },
        { 0x2f83a236402bd08c, 0, 142, Metal, 7 },
        { 0x2f905985cdc251ed, 7, 126, Bumpy },
        { 0x2f984e91e609d43a, 7, 140, Wood, 7 },
        { 0x2fa67ad2ede0a586, 18, 92, Cracks },
        { 0x2fb174c878ce4aaa, 2, 172 },
        { 0x2fb5cbe472166043, 40, 117 },
        { 0x2fd04cbc57722e00, 13, 204, Metal, 7 },
        { 0x2fe9898de2748a4c, 21, 160, Metal, 7 },
        { 0x2fefe095ed7062da, 63, 242, Smooth },
        { 0x2ff286595702c8a0, 42, 174, Metal, 7 },
        { 0x2ffd7b1612896028, 13, 132 },
        { 0x300e90f3992f4242, 21, 116, Brick },
        { 0x3023946ea96c18f8, 17, 149, Bumpy },
        { 0x3027a77c06a1ffad, 0, 78, Tiles, 7 },
        { 0x303e0ba577e48a3a, 29, 127, Metal, 7 },
        { 0x306982b56ce85113, 9, 129, Rounded },
        { 0x3072d8a193d49b72, 15, 158, Metal, 7 },
        { 0x30842c9d39297202, 0, 187, Metal, 7 },
        { 0x308771e0497a4d04, 21, 115, Leaves },
        { 0x308d295e500726dd, 0, 179, Metal, 7 },
        { 0x308f51f4c8ca3acb, 5, 119, Leaves },
        { 0x309c635b9b618110, 7, 104, Wood, 7 },
        { 0x30a7af387fd55fa0, 24, 84, Wood, 7 },
        { 0x30ad4033ba60846d, 26, 193 },
        { 0x30b215b148fd3bdd, 23, 134, Metal, 7 },
        { 0x30c59dab2863d2f3, 19, 154, Wood, 7 },
        { 0x30cf71bf213e52fd, 48, 198, Metal, 7 },
        { 0x30f9507a5d0d7676, 17, 172, Metal, 7 },
        { 0x310855e6d3f6134f, 31, 150, Metal, 7 },
        { 0x3111bc5e27293f56, 42, 125, Metal, 7 },
        { 0x3121980d95b82826, 71, 159, Bumpy },
        { 0x3139fd6628faecaa, 28, 158, Leaves },
        { 0x314225c56d3b37df, 39, 240, Brick },
        { 0x31485a1152be9a3d, 95, 125, Wood, 7 },
        { 0x3166b27215dd246f, 11, 94, Bumpy },
        { 0x3168a854a7cbbdef, 34, 100, Bumpy },
        { 0x316ca6ad13e5d129, 26, 148, Bark },
        { 0x3172875ca3b7f76a, 0, 141 },
        { 0x3175bc9dbf49aeb8, 0, 154, Bark, 15 },
        { 0x318a6b311eb20447, 26, 118, Leaves },
        { 0x31a04372df3b5ccd, 18, 146, Metal, 7 },
        { 0x31b599a1fc54cefd, 33, 82, Metal, 7 },
        { 0x31c0726339721acf, 115, 212, Smooth, 7 },
        { 0x31c0936b2d6ac753, 9, 88, Leaves },
        { 0x31cce062f51590d7, 51, 173, Tiles, 7 },
        { 0x31d8fc33a7d41dd2, 51, 165, Smooth },
        { 0x31d98da7f8ab6e40, 36, 247, Ice, 0, false },
        { 0x31ece8d332602440, 15, 50, Dirt, 7 },
        { 0x320323c422800ec7, 0, 73 },
        { 0x320f3db556e3c57e, 21, 85, Brick },
        { 0x321cbd193e1932c5, 25, 135, Metal, 7 },
        { 0x3260b67995695e9f, 9, 108, Wood, 7 },
        { 0x32731c19971218d3, 10, 173, Wood, 7 },
        { 0x32755e1496264b74, 14, 99, Leaves },
        { 0x32ec70463ba7f667, 24, 196, Metal, 7 },
        { 0x3318e7eaa784833a, 28, 185, Wood, 7 },
        { 0x33193721e62639bb, 7, 73, Grass },
        { 0x33209eec18c815a9, 11, 106, Wood, 7 },
        { 0x332e525a36873e3f, 0, 146, Metal, 7 },
        { 0x332feefdc547a632, 11, 150, Bumpy },
        { 0x3331a035c2fb002f, 9, 155 },
        { 0x333a5cad2b45909e, 70, 108 },
        { 0x3361921e7386e1c3, 0, 136, Stone, 7 },
        { 0x33708cee2307f45e, 109, 169, Dirt, 7 },
        { 0x3377d72034874ef2, 28, 173, Bumpy },
        { 0x3385553ea566cf13, 31, 154, Bumpy },
        { 0x3387e8dfc7b38aeb, 0, 149 },
        { 0x338c253d9be9e5c9, 58, 191, Leaves },
        { 0x339f1346ef81d56b, 10, 114, Metal, 7 },
        { 0x33acc97ce8879a9a, 7, 204, Stone, 7 },
        { 0x33af9af34d377033, 7, 158, Bumpy },
        { 0x33b3d5553886f9ed, 14, 185, Wood, 7 },
        { 0x33b74e8f65e3ed68, 11, 161, Bumpy },
        { 0x33c414509ab39a14, 9, 104, Rounded },
        { 0x33d2d889ebb678c4, 0, 148, Rounded },
        { 0x33e34f1e08f13a46, 16, 198, Bumpy },
        { 0x33f44855f63171b8, 15, 123, Metal, 7 },
        { 0x340779d04050291c, 85, 186, Cracks },
        { 0x341f9795584d17f2, 57, 209 },
        { 0x343369c2081485f9, 33, 247, Ice, 0, false },
        { 0x343a9584f6c5be74, 5, 67, Cracks },
        { 0x344f600fde2365fc, 2, 137, Bumpy, 15 },
        { 0x346d3bbe7c3f2dc6, 36, 116, Grass },
        { 0x3475bd9442c75baf, 26, 190, Metal, 7 },
        { 0x3479c8ccc1843172, 0, 171 },
        { 0x347ae1ea980f41f7, 35, 155, Rounded },
        { 0x349ef602fab82566, 9, 138, Leaves },
        { 0x34a70712552a8df7, 19, 228 },
        { 0x34a7a420677f5297, 7, 124, Wood, 7 },
        { 0x34b7d075683be8e1, 0, 122, Wood, 7 },
        { 0x34bc0df8bc599c11, 64, 150, Metal, 7 },
        { 0x34e036b8d3a5ccbb, 46, 113, Leaves },
        { 0x34edb75eecfadfe4, 7, 109, Metal, 7 },
        { 0x34f050082c5115e6, 22, 160, Ice, 0, false },
        { 0x35158ae452767f97, 33, 175, Leaves },
        { 0x351976c604fadf0d, 28, 112, Metal, 7 },
        { 0x3532348b25f70133, 23, 82, Metal, 7 },
        { 0x35454ef2c5d88795, 21, 168, Ice, 0, false },
        { 0x354e3dc78c79296c, 52, 156, Bumpy },
        { 0x3556f1557d8289c6, 44, 90, Bumpy, 7 },
        { 0x3558cb0a913e66ba, 21, 134, Stone, 7 },
        { 0x359be5eefca1eaaa, 11, 168, Bumpy },
        { 0x35a06e91ca131dfc, 100, 156, Rounded },
        { 0x35a236bc6a897ec3, 75, 140, Dirt, 7 },
        { 0x35b59f6a3ace5c4a, 76, 148, Bumpy, 7 },
        { 0x35b5a6394634d334, 22, 106, Cracks },
        { 0x35c235cf3a024cfc, 79, 127, Bumpy, 7 },
        { 0x35cc6b8a85826f45, 15, 134, Brick },
        { 0x35d13774bab570cf, 29, 114, Wood, 7 },
        { 0x35d70bff264c12ed, 0, 142, Metal, 7 },
        { 0x35dfdb1ef04d3d66, 12, 157, Metal, 7 },
        { 0x35e91f2f8821467c, 48, 132, Dirt },
        { 0x35fdb637e2921a6d, 18, 106, Brick },
        { 0x35ff3014da72385d, 34, 128, Dirt, 7 },
        { 0x3610cd8c8aac75d5, 13, 121, Metal, 7 },
        { 0x3613d0580a4ab9cb, 39, 247, Metal, 7 },
        { 0x361d4bc0cb99f851, 43, 145, Grass, 7 },
        { 0x364d703d10b7a60b, 0, 126 },
        { 0x365d4549de37a8bb, 7, 119 },
        { 0x365fa1b3649a6920, 21, 175, Brick },
        { 0x36acd7f21792e910, 29, 239 },
        { 0x36ddc05347d855eb, 48, 116, Bumpy, 7 },
        { 0x37215dca32e492f3, 119, 203 },
        { 0x372a05be9442cb26, 67, 170, Tiles, 7 },
        { 0x372bf031e71abc9f, 14, 124, Leaves },
        { 0x37302eb1b7793f17, 13, 129, Wood, 7 },
        { 0x37408a39190428cd, 43, 144, Bark },
        { 0x37488137fb10db24, 7, 203, Ice, 0, false },
        { 0x3750a73192f3ddda, 11, 129, Wood, 7 },
        { 0x375f5a32d4750f05, 74, 148, Dirt },
        { 0x377e82608fb7bfbc, 34, 109, Dirt },
        { 0x37bd8b12171468ac, 25, 165, Cracks, 7 },
        { 0x37c67901e7c1d828, 0, 49, Rounded },
        { 0x37cf9756bf11bfcc, 48, 102, Grass, 7 },
        { 0x37d2bdb9fd204824, 17, 160, Metal, 7 },
        { 0x37ee24ce6aa68b60, 7, 175, Bark, 15 },
        { 0x3811b4ce606c94ef, 7, 214, Stone, 7 },
        { 0x383158a31ec96959, 24, 101, Leaves },
        { 0x3840aa695cf2012a, 10, 133, Bumpy },
        { 0x384b864ae3d7229d, 24, 148, Metal, 7 },
        { 0x386cf3f06762c9c6, 14, 179 },
        { 0x387c7d1ba21557e2, 16, 144, Bumpy },
        { 0x387de22ccd948b04, 45, 172, Metal, 7 },
        { 0x388133ad5e89cd52, 33, 129, Brick },
        { 0x3891013168297692, 9, 57, Smooth },
        { 0x389a89f7622fd9ae, 22, 145, Brick },
        { 0x38ad2d2878cf7f1a, 66, 174, Bumpy, 7 },
        { 0x38adc327779f9390, 41, 126, Rounded },
        { 0x38b54dbba8427ab3, 48, 148, Bumpy, 7 },
        { 0x38bbfc1505a78876, 9, 93, Wood, 7 },
        { 0x38bd89e4da3e771f, 25, 113, Leaves },
        { 0x38e5627a23c668f2, 0, 136, Smooth },
        { 0x38e7906f3564cbe2, 10, 143, Rounded },
        { 0x38eb650dc851809e, 31, 103, Metal, 7 },
        { 0x3917011f437aa3c6, 24, 89, Bumpy },
        { 0x391f2b30389ff160, 7, 192, Metal, 7 },
        { 0x3934e39e019014c6, 24, 192, Bumpy },
        { 0x39388b09dd0bbba1, 37, 144, Dirt },
        { 0x3960627ba4adc155, 0, 174, Metal, 7 },
        { 0x396df713ebfd8a60, 26, 112, Metal, 7 },
        { 0x39850f33e32dfb53, 26, 145 },
        { 0x398f17a909273a68, 42, 79, Dirt, 7 },
        { 0x39c15cc601b20ca9, 24, 108, Smooth, 7 },
        { 0x39c3be5b13478a11, 48, 202, Metal, 7 },
        { 0x39c759083802105b, 21, 97, Grass },
        { 0x39c9df8b98454e4c, 23, 142, Metal, 7 },
        { 0x39e87db621c4e023, 35, 154, Bumpy },
        { 0x39eaab258e71fa13, 15, 167, Bumpy },
        { 0x39f30e08edf37651, 0, 126, Stone, 7 },
        { 0x3a036966b6a994bb, 21, 105, Metal, 7 },
        { 0x3a19d2af1b9013b0, 17, 89, Brick },
        { 0x3a39c56b931ff827, 44, 108, Brick },
        { 0x3a39edf4d3cce92d, 49, 130, Cracks },
        { 0x3a4378a6b2fbc1d5, 62, 133, Dirt, 7 },
        { 0x3a6c154ebc700fb0, 47, 104, Brick },
        { 0x3a7948c749824309, 17, 115, Bumpy },
        { 0x3a83bd8d568e5360, 39, 99, Bumpy, 7 },
        { 0x3ad29cd1224072fd, 21, 139, Wood, 7 },
        { 0x3ad422f50614deef, 73, 247, Ice, 0, false },
        { 0x3af04c7cc4fce273, 7, 164 },
        { 0x3af6f165bc6fe3e6, 13, 163, Bumpy },
        { 0x3b0915b3ead335c7, 40, 107, Bumpy, 7 },
        { 0x3b0df0f0dc38c65b, 7, 206, Rounded },
        { 0x3b121df9e7ddc849, 33, 125, Cracks },
        { 0x3b25f6bba8b73025, 2, 247, Wood, 7 },
        { 0x3b54555a7d4e07ec, 86, 161 },
        { 0x3b55235d08c8527b, 34, 193, Bumpy },
        { 0x3b5cdf01db92f0f4, 0, 113, Wood, 7 },
        { 0x3b5ceddf7e529830, 0, 143 },
        { 0x3b61efdb5d3a10f8, 0, 143, Metal, 7 },
        { 0x3b75640b8e53c288, 64, 113, Dirt, 7 },
        { 0x3b787bdb4e410902, 0, 67 },
        { 0x3b8643c5d0f5afe8, 27, 117 },
        { 0x3b945bd6c6a8e901, 11, 213, Bumpy },
        { 0x3ba0e53ceaae7888, 0, 103, Metal, 7 },
        { 0x3ba997dc1b490bb4, 32, 137, Bumpy },
        { 0x3bac5844ea2566c7, 42, 142, Bumpy, 7 },
        { 0x3bb205c240c1c1af, 23, 129, Metal, 7 },
        { 0x3bcdd062f712b6ee, 14, 85, Rounded },
        { 0x3bd13b7ed23d2a25, 16, 133, Metal, 7 },
        { 0x3bd7bb2c370d7c60, 15, 117, Metal, 7 },
        { 0x3bd7e264fe2c8d1d, 24, 103, Bumpy },
        { 0x3be8a6d4b15a8402, 70, 113, Metal, 7 },
        { 0x3c084cd1e95a1ab5, 4, 167, Bumpy },
        { 0x3c08bbe7fb485a32, 37, 102, Dirt },
        { 0x3c17219a8253c2be, 11, 101, Wood, 7 },
        { 0x3c2fe461b635534e, 60, 185, Ice, 0, false },
        { 0x3c4815e4b1bb8e98, 0, 91, Smooth },
        { 0x3c723669b32a24ec, 106, 176, Smooth, 7 },
        { 0x3c76ae27b3e43cc2, 0, 151, Metal, 7 },
        { 0x3ca3b7f582b639e3, 4, 140 },
        { 0x3ca79b02b38f248b, 69, 185, Metal, 7 },
        { 0x3ccf31bc81cc0429, 18, 246, Metal, 7 },
        { 0x3cd988a0887dc5da, 0, 158, Stone, 7 },
        { 0x3cddb85fa2abc4df, 16, 147, Metal, 7 },
        { 0x3ce6183f0d0ab5de, 0, 142 },
        { 0x3ceb70f3d433e802, 12, 134, Brick },
        { 0x3d0b68b77a39f579, 2, 205, Wood, 7 },
        { 0x3d1d63d5cc7cc121, 0, 120, Brick, 7 },
        { 0x3d23faf9064c9432, 61, 185, Metal, 7 },
        { 0x3d25ab643413ff15, 32, 146, Dirt },
        { 0x3d2d672a0d5ea18e, 45, 183, Terraced, 7 },
        { 0x3d32bf6dd451b710, 28, 128, Bumpy },
        { 0x3d356ee15a1b63be, 62, 171, Smooth, 7 },
        { 0x3d3c93a63002e692, 24, 170, Bumpy, 7 },
        { 0x3d62274fae2feff4, 14, 175, Bumpy },
        { 0x3d9dc4c184a4d527, 18, 149, Metal, 7 },
        { 0x3dafd58477a2b999, 0, 230, Stone, 7 },
        { 0x3db08e40e41544f5, 24, 198 },
        { 0x3db137bf59b5a361, 14, 69, Leaves },
        { 0x3db995dac045c106, 7, 83, Metal, 7 },
        { 0x3dc671d1385e5d3f, 29, 116 },
        { 0x3dc787c9627d2ce4, 19, 114 },
        { 0x3dda3db9dbc4e87e, 0, 74, Metal, 7 },
        { 0x3de6e4b924c861d0, 24, 124, Stone, 7 },
        { 0x3df91cac0528deb1, 18, 110, Rounded },
        { 0x3e240e99dc421f59, 0, 197, Metal, 7 },
        { 0x3e2eb575a82c06e7, 87, 200 },
        { 0x3e37092a6f548abc, 129, 154, Smooth, 7 },
        { 0x3e3f11605465bf14, 0, 188 },
        { 0x3e491f4cb5abaf97, 34, 185, Metal, 7 },
        { 0x3e527f5f69c591c4, 32, 106, Brick },
        { 0x3e5caf8667a1371a, 46, 105, Wood, 7 },
        { 0x3e6ae419d07b45b9, 11, 148, Bumpy },
        { 0x3e6e77d3665edcbc, 29, 156, Brick },
        { 0x3e8083164f450e63, 23, 247, Metal, 7 },
        { 0x3e86927fadf68c73, 10, 130, Wood, 7 },
        { 0x3e9099c947e493b2, 49, 129, Metal, 7 },
        { 0x3e96c032f508f5da, 0, 108, Stone, 7 },
        { 0x3ea8ed134c685def, 0, 202 },
        { 0x3eb50724384e79a9, 66, 188, Smooth },
        { 0x3eb7653bb8ef6d4d, 32, 162, Rounded },
        { 0x3ebf1bdbcf377578, 12, 109, Leaves },
        { 0x3ec756cf0d63e0cc, 11, 119, Grass },
        { 0x3ec791909a5c2dd8, 17, 65, Bumpy },
        { 0x3ecf4dc800e023c1, 55, 140, Brick },
        { 0x3ed94e7e3498d623, 68, 157, Dirt },
        { 0x3f0909f319aa119a, 84, 203 },
        { 0x3f256797bf901055, 21, 115, Wood, 7 },
        { 0x3f30456ca9f8eb4f, 24, 111, Bumpy },
        { 0x3f44179a5a7f10f2, 15, 189, Rounded },
        { 0x3f4883f132c567e7, 34, 77, Dirt },
        { 0x3f577f3e6a900c71, 102, 183, Sand, 7 },
        { 0x3f62326b5bab62d9, 22, 132, Bumpy },
        { 0x3f827bede427e44c, 24, 119 },
        { 0x3f83182166a9f321, 36, 116, Wood, 7 },
        { 0x3fb4dedcdbdf2b4a, 45, 174, Dirt },
        { 0x3fca0ef99a811647, 4, 101, Wood, 7 },
        { 0x3fcb0a8204293fc2, 12, 133, Metal, 7 },
        { 0x3fde6c56d26a5cbc, 11, 138, Bumpy },
        { 0x3fe8b6c9ef0e3034, 40, 166, Bumpy },
        { 0x3ffed25216e5587f, 22, 176, Brick },
        { 0x4020317bb8b15f15, 114, 159, Sand, 7 },
        { 0x40760813a656c0c2, 25, 164, Terraced, 7 },
        { 0x409119592e5cbdb3, 7, 144, Wood, 7 },
        { 0x409799c8a8f1b9fc, 24, 126, Leaves },
        { 0x40b14eae15503474, 10, 178, Wood, 7 },
        { 0x40dc29e76b14f909, 5, 49 },
        { 0x4113c5eabdb06f71, 0, 232 },
        { 0x411ad65c16dd8582, 17, 157, Dirt },
        { 0x4138fd2332f8b37f, 70, 144, Rounded },
        { 0x414fd5f0df9ba1ff, 20, 106, Bumpy },
        { 0x419786222253ef3d, 60, 132, Grass, 7 },
        { 0x41c1af93ef19fcf4, 34, 143, Metal, 7 },
        { 0x41c4bb8adb05c85b, 9, 106, Bumpy },
        { 0x41d86d98f9a3cc8d, 16, 184, Bumpy },
        { 0x41dd7a41e84011a3, 9, 65 },
        { 0x41eb542175e8902f, 0, 137 },
        { 0x41ef668a0019dc43, 33, 119, Metal, 7 },
        { 0x42124bb78091726e, 16, 104, Cracks },
        { 0x426e9940e1dde9f6, 26, 167, Metal, 7 },
        { 0x429647da13a8bac2, 42, 154, Cracks },
        { 0x429e1b342a4dcf25, 43, 200, Metal, 7 },
        { 0x429f1f8998afd986, 2, 79, Bumpy },
        { 0x42a0eb838e8b8448, 4, 95, Brick },
        { 0x42a3b3aad545633a, 7, 131 },
        { 0x42b649299429b4ed, 29, 152, Dirt },
        { 0x42bd4ae4b0ca5fab, 15, 106 },
        { 0x42c7e52e00be2ce7, 7, 185 },
        { 0x431354d219d6775d, 49, 101, Smooth },
        { 0x433035dadf876f64, 57, 133, Metal, 7 },
        { 0x4333ba5434c2adb9, 40, 247, Bumpy },
        { 0x4347767e23bc9e5d, 0, 167, Metal, 7 },
        { 0x4353c43bbca25d97, 22, 139, Bumpy },
        { 0x435ca96ccc7c44d5, 59, 135, Dirt, 7 },
        { 0x4368095c1f6114db, 3, 108 },
        { 0x436c13d3fe918324, 26, 247 },
        { 0x4370611c217277ca, 52, 126, Wood, 7 },
        { 0x4377b4130cb160e0, 66, 126 },
        { 0x43c2cdf7b01e2d1d, 56, 157, Bumpy },
        { 0x4440573cf98e653c, 69, 209, Wood, 7 },
        { 0x445e4d72d5665061, 40, 109, Dirt },
        { 0x44827aac7f609b39, 7, 135 },
        { 0x449c6376102b79d1, 24, 167, Bumpy },
        { 0x44ac11d21d561dec, 24, 179, Bumpy },
        { 0x44b9843f1a53d5e6, 50, 141, Metal, 7 },
        { 0x44c0422599eb4eba, 12, 91, Brick },
        { 0x44d1e69a245d63f2, 10, 152 },
        { 0x4510e51116cab6ef, 2, 114 },
        { 0x451ceadc54fbacfd, 16, 163 },
        { 0x45402f8a100aa866, 0, 214, Brick },
        { 0x454964434d348e3d, 27, 93 },
        { 0x455828a4578c2478, 0, 172, Metal, 7 },
        { 0x456dddbe7a6e5165, 24, 92 },
        { 0x456eb563cca743c3, 15, 158, Bumpy },
        { 0x45859a57ddd5a52f, 24, 152, Bumpy },
        { 0x459b6bece1f6cc26, 25, 118, Wood, 7 },
        { 0x459bdb1169d071ff, 7, 168, Bumpy },
        { 0x459f5955ef02c8bd, 10, 189, Metal, 7 },
        { 0x45b2b9c646280f84, 74, 148, Metal, 7 },
        { 0x45cc3ed5b60cdd33, 48, 197, Bumpy },
        { 0x45e8928f1627aa87, 59, 117, Bumpy },
        { 0x45fe0b2f27e02a99, 35, 187, Wood, 7 },
        { 0x463a319558e6fc3a, 8, 201, Rounded },
        { 0x46413d07679afeb1, 38, 247, Bark },
        { 0x4647ed3ad558fec1, 57, 221, Bumpy },
        { 0x465476366af0148d, 25, 119, Metal, 7 },
        { 0x4658c3c01898f3e6, 20, 139, Metal, 7 },
        { 0x465f935675aff108, 21, 121, Bumpy },
        { 0x4666688c2b422b92, 13, 75 },
        { 0x46778db98a15fcc9, 41, 200 },
        { 0x468264b74f8b2dec, 10, 141, Metal, 7 },
        { 0x4698d1e1dfc3781e, 0, 138, Bumpy },
        { 0x46aa267b7dc88e1d, 0, 145, Metal, 7 },
        { 0x470d45c29b3728bd, 107, 247, Metal, 7 },
        { 0x470e624fbda8c9c2, 15, 182, Bumpy },
        { 0x47188646ca94b46b, 24, 86, Cracks },
        { 0x471d5ed1a7003994, 25, 145, Wood, 7 },
        { 0x471f6d17cdd61f9b, 15, 135, Metal, 7 },
        { 0x472d7f529cb423e0, 33, 170, Bumpy },
        { 0x474f9d462a945b39, 0, 112 },
        { 0x476e0c0f9df4cbd6, 0, 160, Brick },
        { 0x47b5cb51dc54ccc1, 20, 118, Bumpy },
        { 0x47bd3d64a467211a, 47, 196, Bumpy },
        { 0x47d68b358ef7434b, 25, 177, Bumpy },
        { 0x484a25a8b8959a74, 49, 132, Metal, 7 },
        { 0x4889c0b4a7749d2d, 15, 183, Bumpy },
        { 0x488e2266d3f6adc1, 60, 151, Metal, 7 },
        { 0x4892f5c57e34a617, 7, 136, Bumpy },
        { 0x489ef60dc361717d, 60, 146 },
        { 0x48bc8d1b919f576d, 74, 157, Bumpy },
        { 0x48bdc58e140c54bf, 22, 97, Wood, 7 },
        { 0x48c6cbe2f925e03f, 6, 143, Bumpy },
        { 0x48efa3236ca2d3d4, 7, 129 },
        { 0x48f20e44bfdf6a3b, 15, 216, Wood, 7 },
        { 0x4918299448b17621, 34, 144, Dirt },
        { 0x492ac296787e1d90, 10, 130, Bumpy },
        { 0x492e569afa61de83, 31, 224 },
        { 0x494d3b319a9ad48b, 17, 134, Bumpy },
        { 0x49527db287e45fe0, 25, 130, Bumpy },
        { 0x499abb77bc31ab6c, 28, 199, Dirt },
        { 0x49a8852fec684293, 26, 151, Bumpy },
        { 0x49c7461d9770cfd7, 11, 182, Wood, 7 },
        { 0x49f70f67e0bc25bc, 9, 169, Wood, 7 },
        { 0x4a024d7e99be8ef8, 24, 90, Metal, 7 },
        { 0x4a13a6ce05005957, 15, 158, Bumpy },
        { 0x4a2079f50290cad7, 16, 104, Rounded },
        { 0x4a7b1a2672b73a09, 49, 162, Dirt },
        { 0x4a91c83686d998e1, 7, 181, Bark },
        { 0x4ad95e5cb1087bd7, 42, 122, Brick },
        { 0x4adac0e46c0901e4, 7, 113, Metal, 7 },
        { 0x4ae015f8efa8523b, 0, 126, Wood, 7 },
        { 0x4ae3a3c82929142c, 28, 116 },
        { 0x4ae4986acc207870, 11, 130, Bumpy },
        { 0x4aea5e10022f76be, 45, 165 },
        { 0x4afb1baed26d936c, 0, 168, Metal, 7 },
        { 0x4afbe7db845bd36e, 84, 150, Dirt, 7 },
        { 0x4afcdad2f3b2aa57, 0, 133, Bumpy },
        { 0x4b134c5e1c1b4937, 13, 112, Metal, 7 },
        { 0x4b1c4ef1230df1d8, 9, 158 },
        { 0x4b4e53b7d00f1c9c, 16, 160 },
        { 0x4b5076dd6ebdc1c4, 15, 137, Wood, 7 },
        { 0x4b64325faca53943, 68, 120, Metal, 7 },
        { 0x4b69a00eadfcf5a5, 19, 154 },
        { 0x4ba2436cd4a1cdc2, 24, 119, Tiles, 7 },
        { 0x4bac24b97b3ccabb, 16, 97 },
        { 0x4bba2af7a0d18c9d, 32, 123, Brick },
        { 0x4bca7bb298b2eb5e, 83, 211, Bumpy },
        { 0x4bd04d5cd4168bed, 11, 138, Bumpy },
        { 0x4bdca8d8671deab0, 57, 203, Bumpy },
        { 0x4bf5d4df8b48da77, 45, 88, Dirt, 7 },
        { 0x4c1673b775a2dc01, 51, 205, Bumpy },
        { 0x4c16e454a9a28aea, 0, 157, Metal, 7 },
        { 0x4c17dfad677f5e95, 42, 119, Wood, 7 },
        { 0x4c1d84d3a84e1f5e, 12, 128, Metal, 7 },
        { 0x4c202898712a2e46, 15, 127 },
        { 0x4c6d134a6f26ffa4, 16, 205 },
        { 0x4c6ea40f6d5265d5, 17, 165 },
        { 0x4c7fa5b97866d78c, 17, 163, Wood, 7 },
        { 0x4cd109b5110e860b, 7, 66, Bumpy },
        { 0x4cd2c4b5dfe1ec2a, 25, 230, Rounded },
        { 0x4d05259792e449ed, 21, 115, Bumpy },
        { 0x4d2d6f78c97fdad4, 7, 149 },
        { 0x4d7c019e1409f8be, 24, 123, Bumpy },
        { 0x4d9e8d6b630bf268, 27, 150, Bumpy },
        { 0x4da7be96b8e07a31, 172, 238 },
        { 0x4db56846c6e525b7, 15, 145 },
        { 0x4dbab2ad7c3c20bc, 7, 126 },
        { 0x4dbe7e6322992b14, 9, 173 },
        { 0x4dd2f69d2d0ebdbb, 38, 247, Metal, 7 },
        { 0x4de6ecc5ad0f1bc5, 15, 103 },
        { 0x4de8e78965df63f4, 31, 120, Bumpy },
        { 0x4df3a71b42f154b7, 29, 121, Metal, 7 },
        { 0x4e034fe0740cb8ca, 7, 58, Bumpy, 15 },
        { 0x4e1d234c5b6a945c, 10, 147 },
        { 0x4e1f169bcc5f20b7, 40, 190, Bumpy },
        { 0x4e2f502bf0aad5ce, 31, 124, Metal, 7 },
        { 0x4e423e67c81f936c, 53, 202 },
        { 0x4e4887659c0b0dd5, 15, 155 },
        { 0x4e4a14ab435ca64a, 35, 138, Metal, 7 },
        { 0x4e53d3c2953f6953, 25, 110, Metal, 7 },
        { 0x4e7a7ab0cff39b36, 51, 165, Bumpy },
        { 0x4e8583b9bb44ef7d, 34, 65, Dirt },
        { 0x4e8a0a6c999776a7, 49, 150, Metal, 7 },
        { 0x4e8c799e5f5df3b7, 17, 149, Bumpy },
        { 0x4e94fa46d521721c, 0, 99, Bumpy },
        { 0x4eacce6dd57cab4a, 68, 145, Bumpy },
        { 0x4ebf7f7b622dbdab, 15, 139, Metal, 7 },
        { 0x4ed873b7e516e91c, 13, 127, Metal, 7 },
        { 0x4edc8c79b78d4ade, 31, 113 },
        { 0x4edf6531675e5834, 17, 190 },
        { 0x4ee9300a3307deb0, 61, 150, Metal, 7 },
        { 0x4ef8774a9738a182, 36, 89 },
        { 0x4efcb48b8a87d0f2, 41, 132 },
        { 0x4efdb8e91d50394d, 15, 170 },
        { 0x4eff00978db86573, 40, 119, Brick },
        { 0x4f0ba9a3a0b57456, 15, 142, Bark },
        { 0x4f0baf7f20c7c1aa, 24, 191, Bumpy },
        { 0x4f1a17bc0b089acd, 31, 144 },
        { 0x4f200881c67db3ee, 80, 126 },
        { 0x4f20d3d31ac4c2a0, 35, 153, Wood, 7 },
        { 0x4f3e24ce9bdc0ed8, 15, 144, Wood, 7 },
        { 0x4f4cb6e07a52378a, 64, 130, Wood, 7 },
        { 0x4f5531c078d1d8c6, 60, 150, Wood, 7 },
        { 0x4f7ef743963aba3d, 2, 150, Wood },
        { 0x4f8495c523df6a7c, 37, 247, Bumpy },
        { 0x4f8c32c7e4c64f00, 48, 233 },
        { 0x4fc1a51479e79a58, 24, 180, Tiles, 7 },
        { 0x4fc6584b8f1e7670, 23, 105, Brick },
        { 0x4fc67ab2b7940f66, 12, 165, Brick },
        { 0x4fe9bd68c071ac96, 7, 68, Wood },
        { 0x4fea7705e7a749ba, 27, 176, Bumpy },
        { 0x501a72fe21324180, 7, 140, Metal, 7 },
        { 0x50230021e8e528ee, 31, 158, Metal, 7 },
        { 0x5026445d030afd6d, 16, 107, Bumpy },
        { 0x5030ec15ded34bc9, 0, 177, Ice, 0, false },
        { 0x5036251517514a3f, 17, 182, Bumpy },
        { 0x504066852db82e74, 38, 167, Metal, 7 },
        { 0x50464136b4087ab1, 11, 117, Metal, 7 },
        { 0x505799bc4edffd9f, 77, 181 },
        { 0x50595a51a39b0eb3, 32, 172, Bumpy },
        { 0x505fb4c4fdca9135, 0, 143 },
        { 0x5079c5e2acb90c07, 32, 147, Bumpy },
        { 0x5082bd21d03a5ec4, 22, 162, Brick },
        { 0x5086e256e6d31891, 27, 162, Bumpy },
        { 0x50fb7c5594541cc9, 48, 159, Bumpy },
        { 0x50fc3d804e356e27, 33, 118, Metal, 7 },
        { 0x5119ff2ce5c2718f, 23, 72 },
        { 0x512ba19af0aa3415, 0, 130, Metal, 7 },
        { 0x513c4c204c6e5a40, 17, 135, Brick },
        { 0x514858ce27fde6cb, 125, 194, Bumpy },
        { 0x5168a881c0fd9082, 22, 153, Brick },
        { 0x51762ea4d41ea043, 13, 64 },
        { 0x51780acfdf66aedb, 49, 172, Tiles, 7 },
        { 0x5191ce6906c8841c, 38, 239, Smooth },
        { 0x51923084f13f54ee, 7, 111 },
        { 0x51a584013d865eb7, 20, 92 },
        { 0x51a7bde1748e3168, 16, 89, Metal, 7 },
        { 0x51d854377749c534, 100, 184, Sand },
        { 0x51e3b779e6a0d10b, 15, 133, Leaves },
        { 0x51eab6df84dd7e70, 9, 85, Metal, 7 },
        { 0x51fbf1ff6d23d880, 8, 120, Metal, 7 },
        { 0x51fc9428e961d64b, 0, 152 },
        { 0x5201c69a906ff852, 0, 143, Metal, 7 },
        { 0x520da5015f653d7f, 0, 139 },
        { 0x521a73f5a1dab97d, 0, 133, Wood, 7 },
        { 0x521eb2f311a0d50c, 24, 130, Bumpy },
        { 0x5222592b5d96814d, 74, 173, Metal, 7 },
        { 0x52346deca6fad60f, 37, 136, Bumpy },
        { 0x52363c7f7714a1f2, 52, 123, Wood, 7 },
        { 0x523c161db74ef5cf, 0, 111, Metal, 7 },
        { 0x523d67d18e1d92c5, 4, 97, Metal, 7 },
        { 0x524ac7da983655cb, 31, 142, Brick },
        { 0x525708d5af93918d, 76, 165, Sand },
        { 0x52582b44a00d5e83, 2, 86 },
        { 0x525a2183a0717930, 91, 126 },
        { 0x5274d2ced3198549, 0, 162 },
        { 0x528c90b27aa94716, 43, 172, Wood, 7 },
        { 0x5295e71f98a0c1bc, 63, 247, Tiles, 7 },
        { 0x529ba621c60ce6d2, 49, 141, Dirt },
        { 0x52ab0411f10c5a9f, 7, 144, Bumpy },
        { 0x52e1b54465e2825b, 44, 160, Dirt },
        { 0x52e538f5b4623d3e, 17, 118, Metal, 7 },
        { 0x52f0ccc4dc4bdff2, 42, 127, Bumpy },
        { 0x53003f56de7edd45, 34, 132, Metal, 7 },
        { 0x5304f13c3c058301, 38, 118 },
        { 0x535e6aa2e9a8d0f1, 0, 144, Bumpy },
        { 0x536a83c6895f120d, 42, 110, Dirt, 7 },
        { 0x5370052245387808, 0, 165 },
        { 0x538dbf33fc8108c4, 25, 111, Metal, 7 },
        { 0x53ad7026e0eb92a8, 25, 158, Bumpy },
        { 0x53c0a6afe70bdf26, 21, 214, Metal, 7 },
        { 0x53cd7419a47704f1, 0, 99, Metal, 7 },
        { 0x53faf488bde45df7, 10, 147, Wood, 7 },
        { 0x53ffd545e1247e6b, 10, 154 },
        { 0x5403cfd038deb924, 0, 102 },
        { 0x54138f7890a91f25, 18, 207, Metal, 7 },
        { 0x543f9c296fe749e4, 52, 157, Wood, 7 },
        { 0x544a1133bc09bbd3, 25, 140 },
        { 0x54510ac258a690c5, 46, 133 },
        { 0x546c6714520106c4, 28, 183, Wood, 7 },
        { 0x546caf97828d6167, 44, 106, Dirt },
        { 0x54788e2104404b19, 41, 149, Bumpy },
        { 0x548852184068cf1c, 12, 155, Metal, 7 },
        { 0x54938f10dad17a60, 27, 202 },
        { 0x549fb742f9b2bdff, 40, 174, Bark },
        { 0x54ea6ee2a2025ced, 36, 170, Metal, 7 },
        { 0x54f8745a17ed6b00, 19, 123, Bumpy },
        { 0x5506dfde3b791931, 15, 162, Ice, 0, false },
        { 0x552ac2c29d54fc5a, 2, 122, Wood, 7 },
        { 0x5550d49ac5bd2d37, 0, 230, Bumpy },
        { 0x557b3919500d51d8, 30, 173, Bumpy },
        { 0x557e17c8fb6790ab, 7, 247, Rounded },
        { 0x5591e7ec2104140b, 23, 117, Metal, 7 },
        { 0x55974effa10b50b2, 18, 150 },
        { 0x55b4cb40fc3c04bf, 25, 123, Bumpy },
        { 0x55c690fabf520218, 11, 125 },
        { 0x55c9938a0d1cf094, 28, 109 },
        { 0x55f263b5201acf57, 57, 112, Dirt },
        { 0x5626beaeaa74d356, 0, 99, Metal, 7 },
        { 0x563e4f62f46a44d7, 51, 151, Tiles, 7 },
        { 0x5644f928f27e1626, 0, 161 },
        { 0x565a73c12daab3b8, 0, 227, Metal, 7 },
        { 0x565d41f359f6ec9c, 21, 164 },
        { 0x56999a939e83fb09, 7, 147 },
        { 0x56af8ef649835179, 0, 135, Wood, 7 },
        { 0x56afe943876a9fea, 0, 104, Bumpy },
        { 0x56b463c9691b7f67, 17, 106, Brick },
        { 0x56b94ab18dee63bb, 56, 166 },
        { 0x56beec8d30a74dfe, 31, 149 },
        { 0x56d31e495daf8c0f, 0, 124 },
        { 0x56d3b33340c76dca, 0, 199, Bumpy },
        { 0x56fd6ad911711ea9, 7, 126 },
        { 0x571ddae99c2926a8, 7, 157 },
        { 0x573d8cb73388edf8, 43, 164 },
        { 0x578dbb74ba606159, 4, 112, Wood, 7 },
        { 0x578fbef0e500e924, 23, 142, Bumpy },
        { 0x57a31abd3c108ca9, 27, 174, Grass, 7 },
        { 0x57beea655a737a17, 58, 255 },
        { 0x57c0f0b0dcd2879a, 61, 226, Metal, 7 },
        { 0x57dfecc37599bb21, 33, 114 },
        { 0x57f63d6359e74436, 92, 134, Wood, 7 },
        { 0x57f6bdfa90046cf7, 148, 203 },
        { 0x5841e6ebe2f92c7a, 12, 117, Tiles, 7 },
        { 0x585ab23e5b44edf3, 25, 181, Wood, 7 },
        { 0x587a76a5cdc6f314, 48, 140, Bumpy },
        { 0x5882c0aed5e94dfa, 15, 222 },
        { 0x588aeee0e8771613, 38, 247, Metal, 7 },
        { 0x5898d9c0faa8c34f, 0, 126 },
        { 0x58a104f474626b8f, 0, 125, Bumpy },
        { 0x58aac87dc121084c, 18, 162, Bumpy },
        { 0x58ae8a070f32fd3e, 49, 187, Bumpy },
        { 0x58c70baa02f4a191, 15, 182 },
        { 0x58cdc31441a193bb, 9, 120, Bumpy },
        { 0x58d52d89183d8867, 0, 158 },
        { 0x58fd413f2f327952, 21, 78, Brick },
        { 0x5902dec10eea92fe, 15, 157, Rounded },
        { 0x590da0b9920d7207, 0, 163 },
        { 0x591dd6094b07d3e3, 54, 158, Bumpy },
        { 0x5937b40f7ad7a441, 33, 208, Metal, 7 },
        { 0x593891bd81eb4a88, 26, 175, Bumpy },
        { 0x593e0d1824038d0a, 0, 54 },
        { 0x5942c0f010806cf6, 15, 169, Tiles, 7 },
        { 0x5947282ba5809902, 7, 168, Bumpy },
        { 0x596a3fe376fb7cf7, 15, 102, Smooth },
        { 0x596b196bca54ea31, 26, 127 },
        { 0x5983317e1b1d3411, 19, 145, Metal, 7 },
        { 0x59935280bb9e5859, 190, 247, Bumpy },
        { 0x59946d438d02a025, 56, 188, Bumpy },
        { 0x599aea4c3931c866, 0, 143 },
        { 0x59bc30c60d5c3417, 9, 177 },
        { 0x59d84e6ccfd0d7f1, 0, 75 },
        { 0x5a021d0579321113, 17, 157 },
        { 0x5a14c1c874f488f0, 7, 75 },
        { 0x5a1c120d5e0fb46a, 7, 124, Metal, 7 },
        { 0x5a223ae5487e2ed2, 69, 222, Ice, 0, false },
        { 0x5a23394829fdbaba, 41, 133, Wood, 7 },
        { 0x5a2c1493b3396e7d, 24, 218 },
        { 0x5a307c438d58f54d, 15, 154, Metal, 7 },
        { 0x5a357885d055dd7b, 33, 165, Cracks },
        { 0x5a6c88f1d0681623, 98, 203, Sand },
        { 0x5a6d35dcdd798e6f, 22, 165, Rounded },
        { 0x5a7e6e5d10e621d1, 53, 126, Bumpy },
        { 0x5af674025c29ac3f, 0, 91, Wood, 7 },
        { 0x5b046a99b520de70, 24, 153, Cracks },
        { 0x5b080d7331473990, 12, 135, Metal, 7 },
        { 0x5b0874124b795244, 0, 70 },
        { 0x5b2593598e6ebdd3, 29, 154, Metal, 7 },
        { 0x5b5cb8b380d4acb7, 3, 82 },
        { 0x5b74f7ffd01e0570, 0, 129, Bark },
        { 0x5b83974b5f81f0ad, 7, 200, Rounded },
        { 0x5b8466278bb1da3a, 7, 132 },
        { 0x5b9b5458df77e559, 11, 174, Dirt },
        { 0x5baec60367c2f4f7, 29, 96 },
        { 0x5bc03acbc3f3b9e9, 47, 247, Metal, 7 },
        { 0x5bcf1e0dd3fa5e3c, 36, 162, Bumpy },
        { 0x5be75667404a2d54, 53, 156, Tiles, 7 },
        { 0x5bf21126f5c810a2, 18, 144 },
        { 0x5bffa44edb6fcbc3, 73, 177, Tiles, 7 },
        { 0x5c122aec9780fcef, 120, 159 },
        { 0x5c1f1a15accb521c, 7, 157 },
        { 0x5c480c7d2e021e9d, 24, 220, Rounded },
        { 0x5c663ca9ac2c26df, 16, 195 },
        { 0x5c6d352aa6356837, 55, 247, Metal, 7 },
        { 0x5c7fb4aabd532d5b, 10, 108, Wood, 7 },
        { 0x5c87bd362d351f4a, 50, 183 },
        { 0x5c9983d07c846cd5, 32, 138, Bumpy },
        { 0x5c9f11e79a73d8fa, 7, 150 },
        { 0x5ca4e8d2953ba6d9, 67, 213 },
        { 0x5cc669c83a7d9e83, 89, 144 },
        { 0x5cc6d7ea523f92d5, 11, 142, Bumpy },
        { 0x5cd5094fea6bb085, 14, 138, Bumpy },
        { 0x5ce76c38b3943e12, 11, 197, Bumpy },
        { 0x5d3b59b45acea5fb, 25, 236, Metal, 7 },
        { 0x5d4e036bf0b4a509, 31, 202, Bumpy },
        { 0x5d668679c8c927ea, 2, 159 },
        { 0x5d68959b4123d077, 25, 104, Metal, 7 },
        { 0x5d7924700a15daa6, 25, 145, Metal, 7 },
        { 0x5d7e13e289af341c, 12, 144, Bumpy },
        { 0x5dc59a4bd776c80d, 11, 143, Bumpy },
        { 0x5de1361623be1176, 42, 101, Brick },
        { 0x5df20fe1233f7904, 107, 144 },
        { 0x5e0c251a746c396c, 25, 156 },
        { 0x5e0cec64f07852c5, 0, 141, Metal, 7 },
        { 0x5e0f452d958398f6, 15, 150, Bumpy },
        { 0x5e18070c1b4f9d20, 26, 222, Metal, 7 },
        { 0x5e28433451c01f89, 25, 92, Wood, 7 },
        { 0x5e435e1da77885e8, 7, 109 },
        { 0x5e4810723d1be71e, 17, 152, Metal, 7 },
        { 0x5e5d0525a05ec848, 33, 162, Bumpy },
        { 0x5e6121e90b5f068e, 11, 114, Wood, 7 },
        { 0x5e6e7021dd5095c5, 15, 114, Metal, 7 },
        { 0x5e79ac0cbb62a287, 0, 91, Brick },
        { 0x5e7de46a3513db4b, 6, 169, Metal, 7 },
        { 0x5e91b79f9e6047dc, 10, 117, Metal, 7 },
        { 0x5e956a8ce8b6197f, 35, 111, Wood, 7 },
        { 0x5eae8371e0571df1, 34, 159, Dirt },
        { 0x5ec2cb7e8607db54, 7, 100, Metal, 7 },
        { 0x5efc0675f7f47ef2, 24, 139, Dirt },
        { 0x5f1a6ab2addeaefb, 38, 147, Wood, 7 },
        { 0x5f2b51b65fce65e0, 7, 247, Metal, 7 },
        { 0x5f3566337f598bd3, 42, 144, Wood, 7 },
        { 0x5f3afa325e871398, 23, 117, Metal, 7 },
        { 0x5f4065a63e017dfa, 10, 94, Wood, 7 },
        { 0x5f523e3ad4058fb6, 20, 159 },
        { 0x5f77e7888e023fc6, 16, 154, Dirt },
        { 0x5f93e4d1e3125b56, 118, 208 },
        { 0x5faba789b5614fbc, 47, 96 },
        { 0x5fb12b725995853d, 83, 202 },
        { 0x5fd39748ddbfdf00, 0, 146, Bumpy },
        { 0x60016dedbd1c7418, 53, 172, Metal, 7 },
        { 0x60226ef635220c47, 103, 187, Sand },
        { 0x603a85a1e20cfabb, 23, 67, Metal, 7 },
        { 0x604279c748dde428, 7, 157, Ice, 0, false },
        { 0x6047bb0918006f16, 20, 133, Rounded },
        { 0x605204a6927feea0, 26, 196, Metal, 7 },
        { 0x6080ad261c12a620, 11, 69, Bumpy },
        { 0x60814cc7d1f951e7, 32, 193, Dirt },
        { 0x60869c580b3745e1, 7, 93, Wood, 7 },
        { 0x60df7ef7d321614f, 116, 228 },
        { 0x60fc3ec7867acf7c, 7, 95, Rounded },
        { 0x60ff7a8f2dab244c, 7, 185, Metal, 7 },
        { 0x610d76c0db1d62d4, 24, 84, Bumpy },
        { 0x6117061bdf68345a, 31, 186, Dirt },
        { 0x61342c458f748353, 25, 134, Metal, 7 },
        { 0x61361286afbbfbe3, 12, 112, Metal, 7 },
        { 0x6143eea1ee517a13, 20, 131, Wood, 7 },
        { 0x614bd692513046a3, 33, 148 },
        { 0x6157bd790da827c4, 39, 127, Metal, 7 },
        { 0x61609c3b3f69eb41, 64, 141, Bumpy },
        { 0x6161fd604987fced, 20, 217, Wood, 7 },
        { 0x61651a70e726dbdb, 68, 247, Ice, 0, false },
        { 0x619da87b9bca19cd, 38, 150, Metal, 7 },
        { 0x61a27e3d19a60cad, 20, 87, Wood, 7 },
        { 0x61b0e35322cd50f9, 25, 130, Metal, 7 },
        { 0x61e2c5aa73ad8352, 12, 84, Bumpy },
        { 0x61f001d90e741830, 16, 123, Bumpy },
        { 0x61fb8d354589791c, 17, 78, Bumpy },
        { 0x6211013c1fe16075, 41, 171, Wood },
        { 0x621339cdeca329ef, 0, 163, Brick },
        { 0x62175001933cbafc, 42, 168, Metal, 7 },
        { 0x621b91feb14faa89, 14, 235, Bumpy },
        { 0x6230dd0b8df2e747, 7, 163, Dirt },
        { 0x623299cb715cc503, 35, 117, Metal, 7 },
        { 0x62366b8585173a2a, 0, 102 },
        { 0x624aba45ab5e4757, 12, 189, Metal, 7 },
        { 0x6252a7a69a679e80, 12, 160, Bumpy, 15 },
        { 0x62631ca5b098ecd1, 0, 102, Bumpy },
        { 0x628a055bbd3873b9, 24, 174, Bumpy },
        { 0x628f759a73079cff, 25, 114, Metal, 7 },
        { 0x6292de4e19a6dff6, 62, 189, Sand, 7 },
        { 0x62acb465cc7d0b44, 38, 158 },
        { 0x62e7739f075bd8d5, 30, 131, Cracks },
        { 0x62e8a4f03729cde4, 21, 118, Cracks },
        { 0x62fb5b401c990b8c, 0, 206, Bumpy },
        { 0x62fb6f4da1c30a8c, 17, 157, Bumpy },
        { 0x6304e2fa04e07fbe, 21, 87, Brick },
        { 0x6320f56631ce28c0, 111, 193 },
        { 0x633579e55621c059, 4, 100, Grass, 7 },
        { 0x6337435ab40edddf, 7, 166, Leaves },
        { 0x6340e9408e63fe0f, 0, 76 },
        { 0x63436e936af9acc0, 14, 209, Rounded },
        { 0x635240385dc466c7, 56, 170, Bumpy },
        { 0x6352b05801975cc5, 25, 161, Wood },
        { 0x635bdf5f8d1be6b7, 15, 103, Brick },
        { 0x6360fd6e0ee35b9d, 0, 208, Bumpy },
        { 0x638b5c7bee0748b5, 28, 108, Wood, 7 },
        { 0x639481543009a883, 0, 185, Wood },
        { 0x63b5dfbbc3199326, 45, 131, Bumpy },
        { 0x63c8c0806df5ae64, 10, 108, Rounded },
        { 0x63d7f742fcb7b17b, 7, 54, Wood, 7 },
        { 0x63d87cd06523523f, 0, 143 },
        { 0x63dc5676de860beb, 16, 150, Metal, 7 },
        { 0x6411fca39761537f, 0, 214, Metal, 7 },
        { 0x641a3f5bd09d49a9, 7, 124, Leaves },
        { 0x64460bb865e9ac48, 13, 124, Bumpy },
        { 0x646d9b3e801a5087, 60, 170, Bumpy, 7 },
        { 0x64907c6cbc0c0478, 21, 125, Cracks },
        { 0x64b0f7daac85ce13, 18, 192 },
        { 0x64b4a80da04abf91, 31, 118, Bumpy },
        { 0x64b9636d64f643cd, 12, 117, Leaves },
        { 0x64be724a850d5113, 7, 133, Rounded },
        { 0x64c948d225f75cd4, 0, 158, Metal, 7 },
        { 0x64d1921a162d0c0f, 15, 159 },
        { 0x64dfbca7ae6069ce, 2, 79, Bumpy },
        { 0x64f56f4911e6eeb9, 25, 129, Bumpy },
        { 0x64f74a561b876efc, 24, 92, Cracks },
        { 0x64fa34406d493da1, 15, 159, Bumpy, 15 },
        { 0x650e95b37effafae, 11, 175, Bumpy, 15 },
        { 0x6520e3e76974babb, 9, 163, Bumpy },
        { 0x652501a3b0ac377e, 18, 132, Metal, 7 },
        { 0x6570644005f912eb, 41, 119 },
        { 0x658bac500d305e75, 22, 176, Bumpy },
        { 0x65920db6a4366297, 31, 74, Bumpy, 7 },
        { 0x659eee7c2d964d0e, 18, 123, Metal, 7 },
        { 0x65a09c3c51796115, 15, 227, Metal, 7 },
        { 0x65a2f53427c16016, 0, 146, Wood },
        { 0x65a4894be14b319b, 34, 127, Bumpy },
        { 0x65bd0590e8b3e254, 37, 206, Bumpy },
        { 0x65cd1543f9823102, 22, 162 },
        { 0x65dffeab9c2f4ae4, 89, 177, Sand, 7 },
        { 0x65f74ffea0da59a1, 15, 145 },
        { 0x6603155343b911f1, 44, 154, Bumpy },
        { 0x660a0fafa429e5e6, 0, 143, Metal, 7 },
        { 0x664b0c6644060bed, 58, 247, Ice, 0, false },
        { 0x667956fd034ca4c7, 11, 151, Bumpy, 15 },
        { 0x6698ced22fac2011, 36, 161, Stone, 7 },
        { 0x66a3343d6189ffd4, 21, 157 },
        { 0x66b69e795098bc95, 0, 100, Bumpy },
        { 0x66bc0fb0d27db22f, 11, 206, Wood },
        { 0x66bd5ad13cd6c360, 53, 158, Metal, 7 },
        { 0x66dff166a80de94c, 26, 142, Metal, 7 },
        { 0x66f829f7e9a6ffd3, 39, 112, Metal, 7 },
        { 0x6714212997654fa0, 16, 219, Ice, 0, false },
        { 0x6716c8bac2d0dee0, 15, 189, Rounded },
        { 0x6747c5c931e53c98, 44, 81, Brick },
        { 0x675ec03cbd102f4f, 0, 79, Brick },
        { 0x67676312e98e9ffb, 18, 124, Bumpy },
        { 0x6770da5d72bc3f51, 10, 178, Bumpy },
        { 0x677756f14b31a92c, 7, 171, Bumpy },
        { 0x678a63f16e8b41c6, 16, 97, Stone, 7 },
        { 0x679bd52f0098815f, 36, 124, Bumpy },
        { 0x67a497b0808dbd05, 58, 160, Bumpy, 7 },
        { 0x67ba38a57c55e9df, 11, 175 },
        { 0x67bf4aa4455c5925, 46, 165 },
        { 0x67c95936ecdb8be5, 30, 107, Bumpy, 7 },
        { 0x67e01f02b1d31700, 0, 119, Bumpy },
        { 0x680089bdeb1079be, 7, 114, Metal, 7 },
        { 0x685af9765395eb25, 7, 127, Wood },
        { 0x6894ef4a77692f63, 26, 110, Bumpy, 7 },
        { 0x689effeeacf7ba99, 23, 123, Bumpy },
        { 0x68dbdb32fd236996, 7, 129, Ice, 0, false },
        { 0x68dcd1a23fd88e74, 2, 128, Bumpy, 7 },
        { 0x690254c6bebbc8e8, 26, 200, Rounded },
        { 0x6906d8eee5e3245a, 23, 75 },
        { 0x690893cd6514f356, 41, 163, Metal, 7 },
        { 0x692bc3cb21409c55, 24, 99, Bumpy },
        { 0x69467e72f258f360, 133, 231, Bumpy, 7 },
        { 0x6967c2e519072e86, 70, 242, Bumpy },
        { 0x696936fe891b324e, 28, 105, Bumpy },
        { 0x696ae1fee3176ccd, 51, 115, Bumpy, 7 },
        { 0x696f5c61b0ccb58a, 0, 135, Bumpy },
        { 0x697064f166831769, 25, 121, Bumpy, 7 },
        { 0x69902f09b00ff0b0, 4, 115, Brick, 7 },
        { 0x699ee2ef06d19491, 16, 128, Metal, 7 },
        { 0x69a19da23c9e3873, 46, 108, Dirt, 7 },
        { 0x69a5881f88e8ff5c, 24, 127, Bumpy },
        { 0x69b0d0a2d79c0dec, 70, 131, Metal, 7 },
        { 0x69b9cec55ca2c86d, 39, 132, Bumpy },
        { 0x69bdd096f337c074, 48, 158 },
        { 0x69bfd3d4962dfc98, 34, 98, Bumpy },
        { 0x69d114fa7f112011, 11, 109, Wood },
        { 0x69fcea74913ea215, 20, 100, Bumpy },
        { 0x6a05717d27480cbc, 18, 112, Metal, 7 },
        { 0x6a0e63b6d41cfd2a, 39, 203, Bumpy },
        { 0x6a264d1d3e60e53b, 91, 237, Bumpy, 7 },
        { 0x6a323fe0717f9018, 7, 200, Rounded },
        { 0x6a3864b6023938dd, 10, 149, Metal, 7 },
        { 0x6a3c662bc17b998f, 59, 183, Bumpy, 7 },
        { 0x6a47fdde568437ac, 33, 85, Dirt },
        { 0x6a720643cb702803, 35, 215, Metal, 7 },
        { 0x6a75e4b59b50d580, 2, 108, Bark },
        { 0x6a84c37159fee846, 17, 103, Bumpy },
        { 0x6a8cd20acdb76950, 67, 95, Dirt, 7 },
        { 0x6a93d7e2076ac219, 9, 120 },
        { 0x6a987c35a1ab60dd, 10, 122, Metal, 7 },
        { 0x6ab4b8ba550b70ef, 25, 153, Wood },
        { 0x6ae6895e0018f49f, 33, 162, Bumpy, 7 },
        { 0x6af8811078eeeac0, 23, 118, Bumpy },
        { 0x6b131144cad192f9, 15, 189, Bumpy, 15 },
        { 0x6b2203d1740e24b8, 48, 184, Metal, 7 },
        { 0x6b53ba7d121a87b0, 96, 148, Bumpy, 7 },
        { 0x6b735120da629b50, 54, 134, Brick, 7 },
        { 0x6b7d120589f845a9, 54, 165, Bumpy, 7 },
        { 0x6bcd8f508a56e50b, 27, 85, Dirt },
        { 0x6bdb707a1843168f, 68, 157, Rounded },
        { 0x6bdb8b8ce73aa0b1, 54, 123, Wood, 7 },
        { 0x6be3c56f644aa962, 15, 186, Bumpy },
        { 0x6bed5a47c9216fa5, 35, 199 },
        { 0x6bf63716b9e1d260, 27, 152, Bumpy },
        { 0x6c156de94a94a26e, 18, 105, Brick },
        { 0x6c20d50edf2fe6bc, 19, 51, Wood, 7 },
        { 0x6c30a4368d488471, 32, 156, Cracks },
        { 0x6c3dbea350dc773e, 15, 153, Brick, 7 },
        { 0x6c7e131856a863af, 26, 71, Wood, 7 },
        { 0x6c82371ee7255f22, 0, 61 },
        { 0x6c9813f82d5b1c78, 44, 154, Cracks },
        { 0x6c9a9cd4096b8dce, 27, 90, Bumpy },
        { 0x6cad62a3d6d85354, 48, 167 },
        { 0x6cb44e8fb8b19b8c, 15, 214 },
        { 0x6cce9ae15d63aa84, 24, 112, Bumpy },
        { 0x6cdee03beb8ddec0, 21, 146, Rounded },
        { 0x6ce59928daacd0b8, 15, 173, Metal, 7 },
        { 0x6cee20852ead7625, 31, 114, Metal, 7 },
        { 0x6d0d80a90d1520d7, 15, 101, Bumpy },
        { 0x6d1a501355215448, 84, 155, Sand, 7 },
        { 0x6d1a5c7d054c426e, 47, 158, Bumpy, 7 },
        { 0x6d1ad0d6f8f6e709, 40, 183, Brick },
        { 0x6d20a0c3eef43450, 26, 117 },
        { 0x6d286b1adbbc6c4e, 7, 155, Metal, 7 },
        { 0x6d2e592bea2b1e66, 35, 162, Cracks },
        { 0x6d2f27726fb61c8f, 45, 131, Brick },
        { 0x6d55fd8c68026604, 31, 124, Bumpy, 7 },
        { 0x6d8a5ce2d790e33d, 2, 155, Wood, 7 },
        { 0x6d9fc0af2aeb6111, 33, 74, Bumpy, 7 },
        { 0x6da55463c724d76a, 114, 247 },
        { 0x6de009975e3d0b67, 17, 108, Brick },
        { 0x6def271eeb7af6d0, 34, 182, Metal, 7 },
        { 0x6df53371c976219d, 15, 116, Bumpy },
        { 0x6dfcc8c7b3ba9c6c, 33, 203, Bumpy },
        { 0x6e2661c87844f27f, 38, 150 },
        { 0x6e4477de3238700a, 30, 168, Brick },
        { 0x6e7127d21f79fe23, 0, 155, Stone, 7 },
        { 0x6e79f3cacea44cd0, 17, 141, Metal, 7 },
        { 0x6e897017baf2c39a, 30, 147 },
        { 0x6e99b1a57eff9a58, 41, 225, Bumpy },
        { 0x6e9df551d329a340, 41, 149, Bumpy, 7 },
        { 0x6ebbe8ef8f026bf7, 25, 93 },
        { 0x6ed48bcd3ceae2ed, 46, 164 },
        { 0x6edf87e2df0975ff, 89, 134, Sand, 7 },
        { 0x6f04502ef762b0c7, 106, 177, Bumpy, 7 },
        { 0x6f2cff9705351ae3, 87, 190, Metal, 7 },
        { 0x6f31bf9bf91845f8, 23, 86, Bumpy, 7 },
        { 0x6f33bc189c1901f3, 20, 184, Bumpy, 15 },
        { 0x6f3ae2649ebbc5d9, 40, 161, Dirt },
        { 0x6f3df414363c9ffa, 119, 231, Leaves, 7 },
        { 0x6f4fe859a7a23ee2, 0, 118, Metal, 7 },
        { 0x6f5b3bae8c40fc0a, 74, 157, Bumpy },
        { 0x6f7c66122a9e73d4, 9, 94, Leaves, 7 },
        { 0x6f80356623ee05f1, 3, 66, Brick, 7 },
        { 0x6fa9254f12982b2d, 29, 180, Metal, 7 },
        { 0x6fc549f8d6650613, 9, 131 },
        { 0x6fc668a228e8ae76, 24, 154, Stone, 7 },
        { 0x6fd872234747021b, 15, 184, Metal, 7 },
        { 0x6fdc747db107258f, 31, 76, Bumpy, 7 },
        { 0x6fe46fb4a52b6b2d, 32, 147, Wood },
        { 0x6ffb18e3e92c7eeb, 25, 101, Bumpy, 7 },
        { 0x6ffb589b2203462a, 30, 139, Metal, 7 },
        { 0x6ffd01d52c14081e, 31, 83, Metal, 7 },
        { 0x6ffd2936379fb8be, 0, 142 },
        { 0x700568bc6d26c2fe, 19, 77, Tiles, 7 },
        { 0x701668455089d89e, 7, 111, Bumpy },
        { 0x7031d5c8d07ef7a7, 2, 113, Wood },
        { 0x704bafee2fa58d87, 29, 162, Brick },
        { 0x706b0bd5b391d27d, 25, 176, Rounded },
        { 0x708b18471d8ca926, 4, 154 },
        { 0x709ac7b49c48649a, 15, 177, Rounded },
        { 0x709f8c3a81f42f8e, 16, 148, Bumpy, 15 },
        { 0x70afdc29039ea698, 28, 247, Metal, 7 },
        { 0x70d7dc6e7e96531a, 24, 131, Bumpy },
        { 0x70e64ec1b946f20a, 47, 170, Bumpy },
        { 0x70f9b2c03770f393, 31, 133, Rounded },
        { 0x71169bc0c0d05237, 31, 127, Metal, 7 },
        { 0x71213fe6061596e3, 51, 126, Dirt, 7 },
        { 0x71232d660c0a0546, 9, 122, Metal, 7 },
        { 0x713fb8135fe614ab, 25, 119, Bumpy },
        { 0x716555697d784126, 9, 173, Wood, 7 },
        { 0x71720cad036412e8, 7, 180, Metal, 7 },
        { 0x7179031051659818, 58, 128, Dirt, 7 },
        { 0x71a2a1c63925976b, 10, 104, Bark },
        { 0x71a4019c2da79f19, 25, 171, Bumpy },
        { 0x71a4adc936c38120, 60, 229 },
        { 0x71b30bddb0dbacdb, 0, 113, Smooth },
        { 0x71e54e70b5da42f8, 15, 140, Stone, 7 },
        { 0x71ea2cc04072232a, 0, 105, Dirt, 7 },
        { 0x720b4aed5c9bb942, 55, 105, Dirt, 7 },
        { 0x7239dd5a1ac6abf6, 58, 202, Tiles, 7 },
        { 0x724e4d1ab0b38061, 18, 140, Stone, 7 },
        { 0x724f85c5da11a5c0, 16, 148, Bumpy, 15 },
        { 0x725eb3f33a3d2f0a, 9, 143, Rounded },
        { 0x7272cd0e77e2daf8, 26, 102, Brick },
        { 0x728d6eee4dff334f, 9, 110, Cracks },
        { 0x728f80c1d1f05dcc, 40, 161, Cracks },
        { 0x7291d4eaa66782df, 7, 134, Leaves },
        { 0x72a35b1e14cefff7, 17, 108, Metal, 7 },
        { 0x72a663523d4efa91, 7, 173, Metal, 7 },
        { 0x72ab33a541780505, 33, 173, Bumpy },
        { 0x72d5eb5633c15d42, 19, 118, Metal, 7 },
        { 0x72f66b94d8756e05, 24, 99, Leaves, 7 },
        { 0x730317da2236f486, 17, 111 },
        { 0x73147809328441ed, 0, 151, Metal, 7 },
        { 0x732aff91d2b4e05a, 47, 206, Bumpy },
        { 0x732d80cb08865532, 95, 166, Sand, 7 },
        { 0x7351b718adec93fc, 28, 204, Metal, 7 },
        { 0x7352862927dfe84e, 73, 159, Bumpy, 7 },
        { 0x735b0cdfdf915181, 17, 182, Bark, 15 },
        { 0x735d179bd8ac04ca, 46, 223, Cracks },
        { 0x7386e2c4986e95da, 2, 155, Bumpy, 15 },
        { 0x7391d2cf03710f7e, 0, 178, Brick },
        { 0x73a1d68f67c41201, 25, 165, Metal, 7 },
        { 0x73a53667ba076135, 7, 69, Stone, 7 },
        { 0x73ac0308fabef6ce, 29, 90, Bumpy },
        { 0x73af8b58f6ba6762, 17, 114, Metal, 7 },
        { 0x73d585f86b82dfd8, 27, 111, Wood },
        { 0x73d743bb5be7d2bc, 0, 184, Metal, 7 },
        { 0x74080a55dd3b9f54, 4, 75, Metal, 7 },
        { 0x74167d728a996d20, 25, 149, Bumpy, 7 },
        { 0x742b91dbb8ae10fa, 51, 154, Bumpy },
        { 0x7434ad7c28e48d43, 0, 120, Wood },
        { 0x744b4d52af7c733c, 14, 150, Bumpy },
        { 0x747f93d5552d7d66, 12, 113, Bumpy },
        { 0x74b718e0b17d2ff8, 42, 148, Tiles, 7 },
        { 0x74ce5a04d0ee022a, 0, 203, Bumpy },
        { 0x74ce782e12042c68, 41, 134, Bumpy, 7 },
        { 0x74d5fa19b14cdae2, 47, 193 },
        { 0x74f03d5df2613187, 26, 191, Metal, 7 },
        { 0x74fc64f63403acb6, 14, 82, Bumpy },
        { 0x7501de36382aafd3, 0, 237 },
        { 0x7503f66067d03708, 0, 82, Stone, 7 },
        { 0x7504e20d0bf15cea, 0, 108, Leaves },
        { 0x751bfbe5af716627, 24, 173, Metal, 7 },
        { 0x751c0f4afa17b201, 0, 99 },
        { 0x7525ff78bdc6be6d, 7, 117, Bumpy },
        { 0x752ecc99d648d38b, 17, 128, Rounded },
        { 0x754216ac897d1286, 2, 235, Rounded },
        { 0x75516ee894419b59, 16, 203, Bumpy, 7 },
        { 0x7551e76ad7a219ad, 49, 101 },
        { 0x756444be175f649c, 9, 137 },
        { 0x757bc39fd7da2fe0, 7, 80 },
        { 0x7593f78bac05572a, 7, 70, Bumpy },
        { 0x7597a9050b2e8bdd, 31, 207, Metal, 7 },
        { 0x75b0ea9e841562d3, 38, 117, Bumpy, 7 },
        { 0x75b609669099bce5, 76, 141, Metal, 7 },
        { 0x75b68bfab20e5d6c, 27, 94, Bumpy },
        { 0x75e440066192feb7, 69, 189, Rounded, 7 },
        { 0x75eab2aa0940cdeb, 62, 112, Metal, 7 },
        { 0x75f31130364c4b7e, 21, 226, Bumpy },
        { 0x760fa714e7c8e569, 20, 94, Metal, 7 },
        { 0x761773c84e663cd1, 21, 107, Bumpy },
        { 0x76310cadc41fe660, 26, 125, Metal, 7 },
        { 0x76342d73bfb82684, 22, 108 },
        { 0x764b54ca036d31c1, 13, 77, Bumpy, 7 },
        { 0x765137823a46151c, 41, 140, Metal, 7 },
        { 0x76693826c96a8a3a, 15, 162 },
        { 0x76c5d96815f2b5b2, 41, 225, Bumpy },
        { 0x76d43bae9e80e32b, 40, 167, Metal, 7 },
        { 0x76f26c53b69b6bd8, 10, 76, Leaves, 7 },
        { 0x7708b1d589135556, 30, 126, Bumpy },
        { 0x771ab127e0c99596, 38, 247, Metal, 7 },
        { 0x771b6b6c53a84b59, 31, 77, Metal, 7 },
        { 0x772abb4beca34886, 34, 200, Metal, 7 },
        { 0x77398bd409ba04f5, 43, 95, Bumpy, 7 },
        { 0x7747cb19e1dc6333, 21, 95, Leaves },
        { 0x7757c212c3543909, 29, 243, Ice, 0, false },
        { 0x7775b63e815f9d25, 7, 130, Wood },
        { 0x7778c4c1cccb7045, 24, 118, Bumpy },
        { 0x778a32a6cbe6cc18, 0, 66, Rounded },
        { 0x77aff944bd018922, 51, 155, Bumpy },
        { 0x77d6f564e68bc78e, 55, 167, Bark },
        { 0x77dac6d297377ede, 24, 82, Leaves, 7 },
        { 0x77dc3a5681abd437, 25, 149, Metal, 7 },
        { 0x77dd4ad2a8ae43d1, 44, 214, Smooth },
        { 0x77e3b5d5347bc448, 68, 141, Metal, 7 },
        { 0x77e7f714210ee6a3, 49, 108, Metal, 7 },
        { 0x77f3a13095b40d8e, 29, 114 },
        { 0x77fb02f872b6b6b8, 9, 121 },
        { 0x780957b505b8a9d9, 28, 123, Bumpy, 7 },
        { 0x780b3e21a7f5326b, 12, 83, Tiles, 7 },
        { 0x781770f4e521cd1f, 37, 222 },
        { 0x7855e1eb595c5d2c, 34, 120, Metal, 7 },
        { 0x786178834c039f38, 10, 97, Bumpy },
        { 0x786394a0fee23325, 24, 171, Bark },
        { 0x787cfad12ec9c131, 0, 114 },
        { 0x788738be67f2c2e3, 17, 113, Bumpy, 15 },
        { 0x788bcf44bb9e68a0, 18, 185, Metal, 7 },
        { 0x78a885de4b380162, 0, 98, Bumpy },
        { 0x78d00d310976a919, 17, 177, Bark },
        { 0x78d3311792ce28ef, 22, 124, Ice, 0, false },
        { 0x78db74ee8d0e3f3d, 59, 123, Wood, 7 },
        { 0x7905224bdc01abf6, 0, 155 },
        { 0x790d6cf1ffa5b79a, 21, 200 },
        { 0x791aeb79a75dc449, 19, 220, Bumpy },
        { 0x791d0d561c46c5e2, 36, 159, Bumpy },
        { 0x792c46f637d5af06, 31, 91, Metal, 7 },
        { 0x7935bdebaef2840d, 31, 221, Metal, 7 },
        { 0x793dca385bc0a4d9, 54, 247, Rounded },
        { 0x7945a97e05e2fe47, 63, 224, Sand, 7 },
        { 0x7949e8a57259df3f, 0, 124, Bumpy },
        { 0x794a7e521666ce0c, 187, 234, Sand, 7 },
        { 0x79636f07655e908e, 14, 75, Bumpy },
        { 0x7965d626638078a2, 25, 114, Metal, 7 },
        { 0x797ba82182603d55, 67, 185, Metal, 7 },
        { 0x7982859f91bf9080, 47, 128, Metal, 7 },
        { 0x7986ef655492a785, 0, 129, Bumpy },
        { 0x7994f3ddbaf27ac8, 23, 140, Bumpy },
        { 0x7997a9ce1f771171, 23, 208, Bumpy, 7 },
        { 0x79a8b89ae797effa, 29, 247, Ice, 0, false },
        { 0x79f2f2d1b02fbb3f, 24, 225, Rounded },
        { 0x79f35ed6f23861b7, 15, 82, Cracks, 7 },
        { 0x79f8fd0432a49806, 55, 140, Brick },
        { 0x7a024e598a3c879d, 77, 174, Bumpy, 7 },
        { 0x7a052d5fa080637a, 36, 161, Wood, 7 },
        { 0x7a1e87ff2b1b686f, 17, 113, Wood },
        { 0x7a4d12b7c5ecefd8, 140, 231, Bumpy, 7 },
        { 0x7a755240ec306220, 17, 178, Rounded },
        { 0x7a8b9e06c8114b0e, 44, 92, Bumpy, 7 },
        { 0x7a8e1e56ff5d0fe3, 34, 182 },
        { 0x7aa05d0faacbc01f, 7, 150, Bumpy },
        { 0x7aa327af69958d74, 17, 175, Bumpy },
        { 0x7aafd11a0ae4d49e, 33, 76, Bumpy, 7 },
        { 0x7ab53fdba345e8e7, 41, 167, Metal, 7 },
        { 0x7acde6f0c1a0efa2, 14, 77, Leaves, 7 },
        { 0x7ad091419192ebc3, 24, 109, Leaves, 7 },
        { 0x7af90558bdbfa183, 0, 101 },
        { 0x7b030cf890da3fb4, 37, 187, Bumpy },
        { 0x7b31d535b644f17e, 21, 143, Bumpy, 15 },
        { 0x7b49d55d9dfdcee9, 16, 161, Bumpy },
        { 0x7b705a08e8ff12c1, 60, 157, Leaves, 7 },
        { 0x7bcaebd9ab47a8c6, 7, 158 },
        { 0x7bd66b082b57f02e, 38, 180, Bumpy },
        { 0x7bd8a64ac791df0f, 56, 90, Bumpy, 7 },
        { 0x7bdfd065a6d4f18c, 21, 111, Leaves },
        { 0x7be6af50e6bbe865, 26, 133, Brick },
        { 0x7c25b9ee46295942, 34, 127, Cracks },
        { 0x7c4935943ff45c04, 38, 110 },
        { 0x7c6a08e45d7b0dcf, 71, 230, Ice, 0, false },
        { 0x7c7d6480aa2a36a2, 0, 146, Ice, 0, false },
        { 0x7c9237d1787e4903, 14, 193, Leaves, 7 },
        { 0x7cbbc714e3b3a416, 17, 82, Wood },
        { 0x7cc5f18b9650741a, 14, 84, Bumpy },
        { 0x7ccbda70c948e860, 31, 181, Bumpy, 7 },
        { 0x7d18043625318a26, 58, 140, Metal, 7 },
        { 0x7d182435ca389b30, 15, 147 },
        { 0x7d22c72e5659d669, 20, 150, Wood, 7 },
        { 0x7d56d4ff068e122a, 47, 110, Metal, 7 },
        { 0x7d7040a04f26397c, 26, 178, Smooth, 7 },
        { 0x7d9bc6137ccfee5c, 0, 163, Brick },
        { 0x7da4c2960ea50f7a, 84, 173, Sand, 7 },
        { 0x7da4e6f65810c2ed, 28, 172, Brick },
        { 0x7da9c8630d4dc1d2, 16, 144, Bumpy },
        { 0x7db567da51fc6184, 0, 100, Rounded },
        { 0x7dc160b3516317d5, 64, 113, Bumpy, 7 },
        { 0x7dc4e39122b31d51, 33, 200, Metal, 7 },
        { 0x7dca6af036d3faf7, 20, 156, Rounded },
        { 0x7df4c8e94f209e2c, 17, 122, Metal, 7 },
        { 0x7e0adb87f1f66715, 48, 198, Metal, 7 },
        { 0x7e190f2730965ad0, 0, 123, Bumpy },
        { 0x7e1b9bc8ac386491, 21, 167, Brick },
        { 0x7e24996ca7a0fb90, 41, 199, Metal, 7 },
        { 0x7e2c280082c1b549, 7, 160, Metal, 7 },
        { 0x7e35542713feeee3, 0, 134, Metal, 7 },
        { 0x7e3c53a0394c6149, 17, 200, Bumpy, 7 },
        { 0x7e3dde1e37601f1d, 15, 217, Ice, 0, false },
        { 0x7e674458ffb53a23, 40, 185, Rounded },
        { 0x7ea0035710bb7477, 80, 126, Dirt, 7 },
        { 0x7ea36a1331aaec40, 11, 123, Bumpy },
        { 0x7ed57244a03703ae, 34, 180 },
        { 0x7ee1c59b6c6e8474, 0, 110, Metal, 7 },
        { 0x7ef03df5f7b3f361, 12, 79, Bumpy },
        { 0x7ef04c7a5fa86802, 24, 223 },
        { 0x7efb98644332b472, 48, 151, Bumpy, 7 },
        { 0x7f22cad39c1d7387, 28, 111, Stone, 7 },
        { 0x7f290c1d485d0efb, 12, 106, Brick },
        { 0x7f291a8011fd480e, 0, 113, Bumpy },
        { 0x7f2a27e193fc0c0b, 78, 166, Bumpy, 7 },
        { 0x7f3d8973e3b1ccad, 21, 168, Ice, 0, false },
        { 0x7f43e664bc405717, 172, 237, Sand, 7 },
        { 0x7f43fde8c3cde238, 34, 100, Bumpy, 7 },
        { 0x7f4612fbdfd0fba1, 16, 95, Bumpy, 15 },
        { 0x7f5e246a0d74688a, 33, 105, Bumpy, 7 },
        { 0x7f607d88a1567afc, 7, 57, Bumpy, 7 },
        { 0x7fc20db554afd4bf, 24, 90, Leaves, 7 },
        { 0x7fcd8b63900a63b3, 15, 140, Brick },
        { 0x7fd51000b2716945, 51, 189, Tiles, 7 },
        { 0x7feca3c3b24912e1, 0, 122, Bumpy },
        { 0x7feeda9e5af362f6, 0, 110, Metal, 7 },
        { 0x7ffe5155c26da7e2, 0, 149 },
        { 0x8007639607ab8950, 34, 174, Metal, 7 },
        { 0x800e83aa67a6e616, 18, 67, Stone, 7 },
        { 0x801ac148b2d5800f, 9, 80, Dirt, 7 },
        { 0x801d879cd89cb691, 68, 227, Bumpy, 7 },
        { 0x802e753014ce2538, 0, 114, Bumpy },
        { 0x8030b3e07c4d6684, 40, 163, Metal, 7 },
        { 0x803deb358181cae6, 24, 194, Bumpy, 15 },
        { 0x803e9a0d45712dd5, 35, 106, Metal, 7 },
        { 0x804a279acf063763, 11, 191, Bumpy },
        { 0x8050b510e14ef1fc, 18, 145, Leaves },
        { 0x805d01eae813bb68, 0, 129, Metal, 7 },
        { 0x806551c75e3a5a12, 125, 195, Bumpy, 7 },
        { 0x8067b3ecc29f0e62, 42, 87, Dirt, 7 },
        { 0x80711c0de6da88da, 20, 142, Bumpy },
        { 0x8075ed192b89f968, 0, 96, Bumpy, 7 },
        { 0x807633d5a0444700, 45, 154, Bumpy },
        { 0x807a9340055630a2, 83, 215, Sand, 7 },
        { 0x808ebd998bafba3a, 55, 131, Dirt, 7 },
        { 0x80b159705558b1b3, 17, 113, Bumpy },
        { 0x80b9ab1f1c75ddfb, 19, 99, Leaves, 7 },
        { 0x80bb6523e7c54f08, 90, 229, Bumpy, 7 },
        { 0x80c4bc312f199f5d, 9, 97, Leaves },
        { 0x80c4e4b432d14a7a, 12, 171, Metal, 7 },
        { 0x80d299d1b5869b11, 26, 231 },
        { 0x80e6be46dbf243a3, 0, 150, Metal, 7 },
        { 0x80ff3baad3485760, 19, 138, Bumpy },
        { 0x810fe44f144ee25f, 52, 118, Wood, 7 },
        { 0x811f9aa8023fe105, 48, 174, Wood, 7 },
        { 0x813b56b979649119, 12, 129, Brick },
        { 0x813ef23f28e5937d, 4, 140, Brick },
        { 0x814b64fc724de5cb, 10, 147, Leaves },
        { 0x8157774a31892bad, 35, 89, Wood, 7 },
        { 0x81724e18c99b9531, 39, 150, Brick },
        { 0x8172744a20b57db2, 15, 140, Cracks },
        { 0x8172b5d2149e95a9, 25, 111, Bumpy, 7 },
        { 0x817e86a83afd00f5, 11, 146, Rounded },
        { 0x817f8b59ca87b5d8, 34, 165, Rounded },
        { 0x819076cead8db4a4, 0, 138 },
        { 0x81a9edc887cb8617, 28, 154, Bumpy },
        { 0x81bf0b5885410251, 17, 157 },
        { 0x81d37bcb59f00098, 17, 189, Bumpy, 15 },
        { 0x81d78ed9b348f3c4, 22, 102 },
        { 0x81ec5fb38e476e90, 30, 190, Bumpy },
        { 0x81fc081670d051be, 35, 126, Wood, 7 },
        { 0x82007ef354c0e21c, 41, 118 },
        { 0x820b58cdfdb2a985, 0, 178 },
        { 0x820bf39d2df9d9db, 42, 186, Bumpy, 7 },
        { 0x8242a9a39153312d, 12, 87, Dirt },
        { 0x824620357d04a5b6, 4, 178, Dirt },
        { 0x8249755c8c108c1d, 15, 168, Rounded },
        { 0x824feb6912e7526e, 27, 148, Wood, 7 },
        { 0x825b5914c3a521c2, 9, 167, Bumpy, 15 },
        { 0x825c9756076ffb60, 36, 103, Brick },
        { 0x8267548d96107016, 7, 218, Metal, 7 },
        { 0x82709b260097a475, 0, 88, Wood },
        { 0x82909a96676a4245, 10, 138, Metal, 7 },
        { 0x8297ae891236db5f, 14, 136 },
        { 0x82b9c2031fef595f, 15, 171, Wood, 7 },
        { 0x82d30d733ebcccf9, 24, 214, Wood },
        { 0x82ed3dc01c93de5a, 18, 112, Metal, 7 },
        { 0x82f2cb4afc89381d, 2, 149, Wood, 7 },
        { 0x8305e8221d0a958e, 7, 148, Smooth },
        { 0x83134ad6a1e270bc, 37, 115, Cracks },
        { 0x83224706a3b80c1b, 7, 141, Stone, 7 },
        { 0x8328161013507ecd, 15, 164, Ice, 0, false },
        { 0x836d440704f29d5d, 17, 114, Bumpy, 15 },
        { 0x8372f332a9fb59ae, 25, 143, Metal, 7 },
        { 0x837446c54f42960d, 0, 139 },
        { 0x8380f92bf6fc0e21, 7, 107, Metal, 7 },
        { 0x83968bf54cb3de15, 25, 149, Metal, 7 },
        { 0x83a28c1b37481767, 42, 123, Metal, 7 },
        { 0x83ae970f6e1c12cf, 21, 171, Bumpy },
        { 0x83c57603a204c40b, 16, 142, Leaves },
        { 0x83d693d9e9707210, 14, 109, Leaves },
        { 0x83da8cbcca3ecc99, 27, 175, Bumpy },
        { 0x83e78a95b6da7ec4, 0, 100 },
        { 0x83ed003c24879da4, 7, 146, Metal, 7 },
        { 0x83f90e658554a5b9, 0, 101, Smooth },
        { 0x84173a5558eaa4c5, 36, 109, Bumpy, 7 },
        { 0x841c6243556ccc57, 2, 140, Wood, 7 },
        { 0x84507c3a580c377f, 58, 197, Stone, 7 },
        { 0x848b3104cf070678, 40, 111 },
        { 0x84b1036154def46a, 0, 186, Bumpy },
        { 0x84bf735b55ad9076, 24, 185, Bumpy, 15 },
        { 0x84d581ca94be4101, 49, 122, Rounded },
        { 0x8506072cac2c9d5a, 9, 88, Bark, 15 },
        { 0x8538f7a371cc8c11, 9, 174, Bumpy, 15 },
        { 0x854a2eb2537006bd, 69, 193, Metal, 7 },
        { 0x857f6698241b3335, 25, 97, Metal, 7 },
        { 0x8581058025593288, 14, 134 },
        { 0x8585324eb4681986, 65, 227 },
        { 0x85a8a576ea0053e8, 18, 137, Wood, 7 },
        { 0x85bc1f2151f3dc2e, 0, 70 },
        { 0x85bf6b72fc193d35, 25, 109, Metal, 7 },
        { 0x85c1fe614be9eaed, 53, 87, Wood, 7 },
        { 0x85fa4242b75b54b6, 26, 124, Metal, 7 },
        { 0x86069cac7d676ad0, 55, 130, Grass, 7 },
        { 0x863deae4a0ff7e54, 26, 109, Metal, 7 },
        { 0x8641976cca674560, 0, 161, Metal, 7 },
        { 0x86465c633e884575, 22, 50, Metal, 7 },
        { 0x864690c0beca1d0b, 24, 132 },
        { 0x86612047ca84670e, 35, 191, Metal, 7 },
        { 0x868e690c21eb01bb, 11, 120, Bumpy },
        { 0x869f57bf19a61340, 43, 123, Metal, 7 },
        { 0x869f9ca80defadce, 54, 173, Rounded },
        { 0x86a95eb9341e66a9, 33, 185, Metal, 7 },
        { 0x86acdb6b0bc1e981, 33, 119 },
        { 0x86d72ffd80ad2c07, 0, 162, Metal, 7 },
        { 0x86e1ea8fe3cb6d62, 38, 115, Rounded },
        { 0x86eeeba15f421833, 21, 162, Bumpy, 15 },
        { 0x8703d07480128c57, 17, 121, Wood },
        { 0x87170d94e2ac4056, 12, 178, Bumpy },
        { 0x87191a5c34c16ade, 7, 112, Bumpy },
        { 0x871f5794e21afc76, 15, 142, Wood },
        { 0x8736bfc30bbe4140, 52, 247, Ice, 0, false },
        { 0x874e74587189a983, 36, 247, Bumpy, 15 },
        { 0x875fd71f83af4b7a, 0, 102, Bumpy },
        { 0x87c19a9f691b6298, 0, 111, Rounded },
        { 0x87d3e0f8741c0c9d, 32, 123, Cracks },
        { 0x87d7107db5ca21bb, 12, 157, Brick },
        { 0x87ddf73f49582cd9, 48, 91, Bumpy, 7 },
        { 0x87f8cb282b32b064, 47, 204 },
        { 0x880e41a8e39680c9, 58, 187, Dirt },
        { 0x8815cc73a8bd88a1, 17, 189, Stone, 15 },
        { 0x882437d58120c8d7, 26, 202, Metal, 7 },
        { 0x884515fe28dd53e5, 126, 232 },
        { 0x88488331c4127c77, 9, 126 },
        { 0x886bda2772cd5bfa, 0, 208 },
        { 0x88753089e8a1fe6b, 67, 233 },
        { 0x8895197ea5ba3945, 26, 76, Metal, 7 },
        { 0x8899878a3c896403, 31, 211 },
        { 0x88a6c9a7f3d17bf6, 0, 128 },
        { 0x88c8630ddc818ba2, 14, 80, Bumpy, 7 },
        { 0x8902ec2815ec861a, 15, 75, Metal, 7 },
        { 0x8910fae67f0392f3, 18, 185, Metal, 7 },
        { 0x891255c75f6407b9, 45, 183, Stone, 7 },
        { 0x892f388c370872d9, 19, 77 },
        { 0x8930d3e71de5b4a3, 15, 140, Bumpy },
        { 0x898c2f8e981a06bf, 7, 138, Bumpy },
        { 0x89941f1e716adc30, 15, 79, Brick, 7 },
        { 0x899f2bd667becc02, 27, 186, Tiles, 7 },
        { 0x89a5c017c9642821, 21, 68 },
        { 0x89b6cf757e8d79b6, 0, 197, Bumpy, 7 },
        { 0x89fc67a171b36ef8, 45, 183 },
        { 0x8a13fcf914709030, 15, 80, Metal, 7 },
        { 0x8a16add34c374e4c, 35, 116, Metal, 7 },
        { 0x8a27c363eb2935d7, 0, 132, Bumpy },
        { 0x8a65f3f0a75426e9, 15, 206, Metal, 7 },
        { 0x8a69d08d297c5b79, 21, 72, Bumpy },
        { 0x8a6dba6448b8edc7, 61, 141, Metal, 7 },
        { 0x8abfa35d79fcf0b2, 19, 117, Metal, 7 },
        { 0x8ac65d7979cbed0f, 41, 168, Cracks },
        { 0x8ac8233b6a252763, 15, 133, Rounded },
        { 0x8aedde30cf580577, 30, 97, Grass, 7 },
        { 0x8afb2bc2d08566bf, 9, 144, Bumpy },
        { 0x8afb588dd3f04a29, 7, 159, Bumpy, 15 },
        { 0x8b001f5533e75be3, 7, 61, Metal, 7 },
        { 0x8b038cc54d2cc7cc, 14, 132, Bumpy, 7 },
        { 0x8b14cd9b9500cbdf, 9, 165 },
        { 0x8b1712b52c844067, 7, 154, Bark, 15 },
        { 0x8b1c329f4667f6b5, 17, 183, Rounded },
        { 0x8b31ea5880ba5ec9, 9, 188, Leaves },
        { 0x8b3465298adb5dc2, 56, 188, Bumpy, 7 },
        { 0x8b461e71b5cb3d98, 51, 190, Bumpy },
        { 0x8b59806860709424, 31, 247, Bumpy, 7 },
        { 0x8b862b0e833f76e7, 0, 120, Wood },
        { 0x8b889035cb218939, 21, 104, Metal, 7 },
        { 0x8b88eebb4b17c6a1, 98, 179, Sand, 7 },
        { 0x8b9936019263a563, 12, 76, Bumpy },
        { 0x8bb7617d610874c0, 8, 184, Wood, 7 },
        { 0x8bc4a2f1c1551a25, 23, 225, Metal, 7 },
        { 0x8bc62aea19ba6750, 0, 151, Tiles, 7 },
        { 0x8bd88ef2305f6b03, 0, 104 },
        { 0x8bf0fd846a8b1563, 2, 140, Metal, 7 },
        { 0x8c266133f114b6ab, 20, 182 },
        { 0x8c2ae54ec327838c, 0, 92, Bumpy },
        { 0x8c4912b6ac5cc56d, 23, 165, Bumpy, 7 },
        { 0x8c4cf942e3566102, 0, 160 },
        { 0x8c5dcee84cd10158, 30, 78, Metal, 7 },
        { 0x8c6b1a8afdd53b9e, 25, 214, Metal, 7 },
        { 0x8c8da158ca5dfd2a, 0, 171, Terraced, 7 },
        { 0x8ccfd7c0ce0149f9, 0, 105, Wood },
        { 0x8cd5657d41db60e4, 40, 130, Metal, 7 },
        { 0x8cd999fc53fa6ac9, 11, 208, Bumpy, 15 },
        { 0x8cebbb55d7c58374, 32, 128, Bumpy },
        { 0x8d3167c23a5cc793, 22, 127, Wood, 7 },
        { 0x8d388d96d45f9fe6, 64, 155, Metal, 7 },
        { 0x8d4b8d526eb0708b, 67, 177, Terraced, 7 },
        { 0x8d5b4afde78e335f, 17, 209, Wood },
        { 0x8d7ebfee691aeb45, 51, 123, Metal, 7 },
        { 0x8da8cf894aaadbf9, 60, 95 },
        { 0x8dab975e552fa864, 70, 205, Wood, 7 },
        { 0x8dabd3fa797e94e2, 49, 174, Bumpy },
        { 0x8dd355e7b4fdb4ee, 15, 179, Bumpy, 15 },
        { 0x8ddc110b6d0d81c6, 60, 151, Tiles, 7 },
        { 0x8dfac77c74559caa, 104, 206, Rounded },
        { 0x8e0227ad205bef7a, 33, 120, Bumpy, 7 },
        { 0x8e1dd066f2daa7b0, 52, 126, Wood, 7 },
        { 0x8e41b04b99a602ef, 7, 130, Brick },
        { 0x8e6a8bc02e6dc442, 0, 100, Bumpy, 15 },
        { 0x8e70731d51b8b4be, 0, 158, Metal, 7 },
        { 0x8e7ddf9dae646b45, 30, 91, Brick },
        { 0x8e7f1216ce897f67, 0, 108, Brick, 7 },
        { 0x8e9ad53113a7e2e1, 47, 247, Bark },
        { 0x8eb058f94ebf3ade, 54, 102 },
        { 0x8eb2a8aa932dd87e, 22, 233, Smooth },
        { 0x8eb95bf239003594, 17, 104, Wood },
        { 0x8ed0596ec81616ff, 18, 74, Metal, 7 },
        { 0x8eecdcc0138348c2, 26, 186, Bumpy },
        { 0x8efb0a598b63e522, 42, 161, Metal, 7 },
        { 0x8efb567a05413918, 38, 244, Bumpy },
        { 0x8efc74474ebccf82, 30, 183, Smooth },
        { 0x8efe1d4ed28a3af8, 49, 149 },
        { 0x8f45ba32270fafc2, 11, 158, Bumpy, 15 },
        { 0x8f5c2b4231d5b6c2, 31, 136 },
        { 0x8f7155d44310a68a, 11, 192, Bumpy, 15 },
        { 0x8f7e0a9250e52463, 10, 121 },
        { 0x8fa54a167220c133, 49, 155, Bumpy, 7 },
        { 0x8fa99ce7dd7c7b71, 18, 138, Metal, 7 },
        { 0x8fb60c8ba9ece354, 22, 164, Bumpy },
        { 0x8fc35b86286ef823, 10, 100, Brick },
        { 0x8fc76b3f44e518e8, 25, 106, Metal, 7 },
        { 0x8fd799d60e29b069, 0, 160 },
        { 0x8fdd3ea722903409, 61, 187, Rounded },
        { 0x8ff864862e3a1a60, 0, 198, Metal, 7 },
        { 0x902b145651b89259, 17, 122, Metal, 7 },
        { 0x904150caa7ee62b0, 0, 224 },
        { 0x9047f4a7278186d1, 17, 73, Brick },
        { 0x9079e72148e51fc6, 0, 145 },
        { 0x908c66fd7e0ce10b, 32, 169, Bumpy, 7 },
        { 0x909297b7b0fb3c8f, 57, 154, Bumpy },
        { 0x90b7b6a00011f2fa, 0, 124, Leaves },
        { 0x90b920492cad82a4, 83, 180, Bumpy },
        { 0x90bc94c28452eb95, 67, 156 },
        { 0x90cae82d8f85eb6b, 0, 192 },
        { 0x90d7118a8ab2b8c9, 9, 117, Bumpy },
        { 0x90e80f95f8f77bd8, 0, 114, Stone, 7 },
        { 0x91087093a281529c, 20, 140, Wood, 7 },
        { 0x910bedbe64faf3b9, 0, 141, Metal, 7 },
        { 0x91103f0fdc3a7027, 7, 167, Stone, 15 },
        { 0x911e0bd018a90cee, 24, 175, Metal, 7 },
        { 0x913af37ab62ac18c, 38, 187, Dirt, 7 },
        { 0x916720448b58e0bf, 2, 95, Bumpy, 15 },
        { 0x917b03c44a8f4913, 15, 134, Wood },
        { 0x91b20b54b85edcde, 16, 138, Bumpy, 15 },
        { 0x91b794e774d96ac3, 9, 82, Wood, 7 },
        { 0x91c0cbe58581d7b6, 54, 114, Metal, 7 },
        { 0x91d69b3654b91ac3, 53, 133, Metal, 7 },
        { 0x91dc63433e7132c8, 97, 168, Bumpy, 7 },
        { 0x91e24b5ac9fe1611, 40, 190, Stone },
        { 0x92281f3d22a435ab, 18, 123, Metal, 7 },
        { 0x9233817d7fb6b383, 25, 177, Bumpy, 7 },
        { 0x923dcb8f364ecb2b, 25, 170, Rounded },
        { 0x924be837cee6836b, 7, 156, Metal, 7 },
        { 0x929c8afda23a17ac, 22, 123, Smooth },
        { 0x92b2ff68069fbe74, 18, 164, Bumpy, 15 },
        { 0x92b49a114a754437, 7, 104, Wood },
        { 0x9310362f28b39ab1, 25, 175, Metal, 7 },
        { 0x933463bd04326f81, 18, 110, Brick },
        { 0x9340e6610e77a148, 31, 190, Bumpy, 15 },
        { 0x93413b9d06a5b726, 71, 141, Metal, 7 },
        { 0x9351c4ba5887ad1b, 0, 106, Bumpy, 7 },
        { 0x93738b7897e3c32a, 27, 137 },
        { 0x938274204a5b6dfd, 0, 165, Metal, 7 },
        { 0x93a1957667906742, 27, 146, Bumpy, 15 },
        { 0x93c513b27b0bc1cc, 66, 173, Bumpy, 7 },
        { 0x93cb51b73b3a1305, 19, 138, Cracks },
        { 0x93d239feeebdcfb9, 128, 210, Bumpy, 7 },
        { 0x93d275628f97b992, 24, 123, Dirt },
        { 0x93e0ed1da4c23ba2, 112, 222, Metal, 7 },
        { 0x9409c9b31ea68a7b, 12, 134, Brick },
        { 0x940e71052be60bc0, 16, 154, Metal, 7 },
        { 0x941c4fe6949e0607, 7, 156, Metal, 7 },
        { 0x9429eac1e5d310a8, 25, 73, Metal, 7 },
        { 0x948de7a57002f906, 0, 80, Wood },
        { 0x9492ed986d87ca58, 0, 161, Bumpy, 7 },
        { 0x94b93bb46b0ab937, 0, 142, Stone, 7 },
        { 0x94bd29b74e9a3736, 10, 193, Rounded },
        { 0x94c6681123effb47, 27, 88, Metal, 7 },
        { 0x94cbff261d18ba58, 0, 179, Bumpy, 15 },
        { 0x94ce9f3c48c498aa, 35, 140, Brick, 7 },
        { 0x94db90a8d01cd37c, 21, 136, Ice, 0, false },
        { 0x94e63a3b4b78fc54, 14, 94, Leaves, 7 },
        { 0x94e717979b0d8bec, 22, 134 },
        { 0x950461349ccac6b8, 7, 130, Bumpy, 15 },
        { 0x95090856b247f169, 7, 111, Wood, 7 },
        { 0x9540642b06531ae6, 29, 173, Rounded },
        { 0x954ef9f8a319784b, 2, 155 },
        { 0x955b7661b59bc795, 7, 113, Wood, 7 },
        { 0x95658c9dcb4783c7, 82, 247, Metal, 7 },
        { 0x956d81aee25fd129, 40, 188, Metal, 7 },
        { 0x957999740383b323, 21, 176 },
        { 0x958318165d86fdf6, 75, 182, Metal, 7 },
        { 0x9595318a739833ec, 11, 154, Dirt, 7 },
        { 0x95a198f9fa47c784, 10, 140, Metal, 7 },
        { 0x95c9016de9d51f9a, 25, 109, Metal, 7 },
        { 0x95cd35ce4b6567d1, 40, 110, Brick },
        { 0x95d70f9123941e94, 17, 96, Bumpy, 15 },
        { 0x9604441f9f941d68, 25, 113, Metal, 7 },
        { 0x96094327a0463bc4, 15, 107, Metal, 7 },
        { 0x960e624f68ea52e3, 58, 141, Metal, 7 },
        { 0x9624b030ab15d4a3, 15, 142, Bumpy, 7 },
        { 0x962c6920654d2677, 26, 137, Metal, 7 },
        { 0x964f6a9c338b66fc, 42, 153, Cracks },
        { 0x965b08644b4d217e, 79, 218, Metal, 7 },
        { 0x96684ebf786bf7ac, 19, 144 },
        { 0x967a35dd5bd987c8, 9, 69, Metal, 7 },
        { 0x9693718ef3da2734, 26, 205 },
        { 0x96d1d3d57b4fc88d, 34, 146, Metal, 7 },
        { 0x96e16660653cbbcd, 0, 179 },
        { 0x96f6e820251a87e2, 39, 96, Brick },
        { 0x96ff68f594e53ca1, 15, 111 },
        { 0x97189ee6be615272, 0, 168 },
        { 0x971a9e7b42204478, 81, 210 },
        { 0x9720383198742bd3, 16, 148, Stone, 7 },
        { 0x97250339c78cd191, 29, 179, Metal, 7 },
        { 0x97417481aeafad57, 24, 130 },
        { 0x975cf852a49e45a0, 39, 249, Wood },
        { 0x976a01be774a1632, 25, 170, Stone, 7 },
        { 0x9770184e022cc464, 7, 160, Bumpy },
        { 0x9776b3f5dafda331, 15, 151, Metal, 7 },
        { 0x979c3cf62ddb8a71, 18, 195, Bumpy, 15 },
        { 0x97cc55f299a21c10, 0, 140, Metal, 7 },
        { 0x97f7b53ed01f00bd, 25, 205 },
        { 0x97ff2e2f169d1730, 57, 150, Metal, 7 },
        { 0x9822431fff596e5d, 0, 194 },
        { 0x9825428a498ff6dd, 2, 164, Brick },
        { 0x98487ac51cd8946f, 9, 158, Bumpy },
        { 0x984c4e7ea9848642, 26, 133, Metal, 7 },
        { 0x9857bbf60edc979c, 16, 95, Rounded },
        { 0x986890d52d95f936, 18, 155, Metal, 7 },
        { 0x98be367d532c6b11, 7, 130, Bumpy },
        { 0x98cd9fff48e72dd5, 47, 140, Brick },
        { 0x98dcef22757b659f, 7, 60, Metal, 7 },
        { 0x98df406551469f0a, 3, 66, Metal, 7 },
        { 0x98e12a8ff62ba173, 24, 74 },
        { 0x98ee5e9ba1a698e3, 32, 228, Bumpy },
        { 0x9962017efebfabc7, 43, 155, Wood, 7 },
        { 0x998278df51ad0d68, 0, 132, Metal, 7 },
        { 0x99a52f04d4688333, 9, 61, Cracks },
        { 0x99a77f779f130652, 0, 133, Bumpy, 15 },
        { 0x99a8168efe4ab39e, 18, 85, Rounded },
        { 0x99ab738edd4c9686, 8, 149, Metal, 7 },
        { 0x99b9fb9707542646, 9, 128, Bumpy },
        { 0x99c3af3fdc6d2975, 29, 149, Bumpy },
        { 0x99c74403eaa03e91, 18, 78 },
        { 0x99d6577a8147e3f6, 15, 140, Rounded },
        { 0x99e6df7fb5e60395, 84, 196, Metal, 7 },
        { 0x9a0c6b5514751e80, 0, 86, Wood },
        { 0x9a0d74daa0c53cea, 7, 99, Metal, 7 },
        { 0x9a31309f5831e399, 16, 164, Bumpy },
        { 0x9a63118c6d838d79, 54, 143, Smooth },
        { 0x9a67f2f6e4d7513a, 39, 170, Stone, 7 },
        { 0x9a6c820ed1eff795, 0, 133, Metal, 7 },
        { 0x9a8a2771abe34822, 16, 99 },
        { 0x9aa748ef8616a37c, 31, 221, Metal, 7 },
        { 0x9aa7e53d7f3a75cf, 34, 165, Rounded },
        { 0x9ab08733874bc545, 24, 221, Bumpy, 7 },
        { 0x9abf7873bffea7a3, 12, 137 },
        { 0x9ac1569f44d8ca8e, 18, 138, Smooth },
        { 0x9adb59faf6497a02, 42, 143, Dirt },
        { 0x9aee981af640bccb, 0, 167, Bumpy, 7 },
        { 0x9b0dbe6f1cc6a337, 15, 134, Wood },
        { 0x9b3389ef372081ec, 23, 183 },
        { 0x9b3468a302b5a297, 33, 92 },
        { 0x9b3d8816f4dcde85, 33, 247, Metal, 7 },
        { 0x9b5972f0fafc698a, 7, 101, Metal, 7 },
        { 0x9b6a3475689e17e3, 25, 155, Dirt },
        { 0x9b816f70cdd04699, 0, 147 },
        { 0x9b95ab071aff4c3b, 59, 152, Tiles, 7 },
        { 0x9bb4c42ecd384cef, 2, 121, Bumpy },
        { 0x9beac0023a407f40, 40, 141 },
        { 0x9c3fc52726ae4750, 14, 129, Wood, 7 },
        { 0x9c647fa63c310397, 19, 91, Cracks },
        { 0x9c9af8fb8a03a09d, 10, 134, Metal, 7 },
        { 0x9c9bf5e63641ac40, 42, 156, Wood, 7 },
        { 0x9ca12bfed2af3249, 11, 80, Wood },
        { 0x9caa8d076b098d97, 17, 104, Brick },
        { 0x9cb80a598ed3e0c6, 22, 60, Wood, 7 },
        { 0x9cd04455aef1b874, 30, 77, Metal, 7 },
        { 0x9cd6a08c1c787ab6, 3, 137 },
        { 0x9d0986172debbd81, 30, 111, Wood, 7 },
        { 0x9d1221e805a2ed58, 37, 130 },
        { 0x9d237364c786161b, 23, 162, Wood },
        { 0x9d43e04fc88fb513, 15, 92, Bumpy },
        { 0x9d448fef5f4c23a4, 34, 147, Metal, 7 },
        { 0x9d4d5d5bc8169f7a, 19, 128, Wood, 7 },
        { 0x9d509697d771dd69, 7, 159, Bumpy, 15 },
        { 0x9d5277e27ce2cc77, 7, 138 },
        { 0x9d6dd1d940d7351e, 0, 145 },
        { 0x9d7e6546531aa6fc, 10, 167, Metal, 7 },
        { 0x9d83b6d6c3c41ca6, 0, 161, Metal, 7 },
        { 0x9d938c1c99d1f644, 36, 181, Rounded },
        { 0x9da87daa0a25d9ef, 7, 185, Metal, 7 },
        { 0x9dbb93d9b85edfd6, 15, 122, Metal, 7 },
        { 0x9de405397fd7d5c3, 12, 166 },
        { 0x9de8db63910e9e65, 11, 135, Bumpy },
        { 0x9df43c81570b1776, 21, 127, Bumpy },
        { 0x9dfd9d7f943b778e, 33, 132 },
        { 0x9e03cdcf7b72b801, 7, 160, Wood, 7 },
        { 0x9e1238d95e5ddd31, 0, 90 },
        { 0x9e1db7eb4ed945a5, 7, 189, Ice, 0, false },
        { 0x9e54aaa6a4580c06, 27, 216, Bumpy },
        { 0x9e5511d1b9cf600b, 0, 223, Metal, 7 },
        { 0x9e6fcbeb7ca4a79b, 20, 109, Bumpy },
        { 0x9ea267ba8e1b23b2, 69, 192, Grass, 7 },
        { 0x9ecdd16b47696c54, 9, 77, Grass, 7 },
        { 0x9ee71580efd905a1, 19, 107 },
        { 0x9eee263630b724a9, 10, 91, Wood, 7 },
        { 0x9f06fb5f6adb8d56, 38, 139 },
        { 0x9f07d09a0d58baeb, 51, 81, Bumpy, 7 },
        { 0x9f1986bf06a9fde4, 24, 90, Grass, 7 },
        { 0x9f20f7bf1d3bf1f5, 51, 108, Metal, 7 },
        { 0x9f352c25edf6a19a, 43, 130, Rounded },
        { 0x9f60f5f101610f3d, 42, 124, Brick },
        { 0x9f762167a284f9df, 33, 120, Bumpy },
        { 0x9f7742d1d6795685, 12, 102, Bumpy, 15 },
        { 0x9fa67f767a2d583d, 7, 147, Stone, 7 },
        { 0x9fac986b6ed87a53, 68, 109, Bumpy, 7 },
        { 0x9fb9a23dea2871ee, 0, 101 },
        { 0x9fbf807c7aeab607, 36, 119, Wood, 7 },
        { 0x9fce8d7e0390ed15, 0, 170 },
        { 0x9ff47835f3cfef24, 74, 166, Bumpy, 7 },
        { 0xa005cf2925f112f2, 42, 179, Metal, 7 },
        { 0xa0393d4bafb9a1a3, 0, 171 },
        { 0xa0503c76848a3e24, 31, 83, Metal, 7 },
        { 0xa05ce779f63ba5ba, 47, 247, Ice, 0, false },
        { 0xa0754fa808c1eec1, 12, 236, Ice, 0, false },
        { 0xa08c0479242935a7, 7, 158, Rounded },
        { 0xa09c0a9a2c12c725, 7, 148, Bumpy },
        { 0xa0a5fc0eab54ee58, 17, 195, Wood },
        { 0xa0b0365bcc5cba16, 54, 254 },
        { 0xa0c74c8970f42515, 4, 153, Ice, 0, false },
        { 0xa0c9f5d87a2719f3, 11, 222, Bumpy },
        { 0xa0d9d9703f991f7d, 10, 151, Bumpy },
        { 0xa0de3fc13405c501, 46, 146, Rounded },
        { 0xa0ec8f703e868df8, 52, 180, Wood, 7 },
        { 0xa111f6281c4c0ff7, 184, 251, Ice, 0, false },
        { 0xa143bc99822bbca3, 0, 144 },
        { 0xa146cbb1e54c321f, 41, 119 },
        { 0xa158cf9c8d9cd419, 66, 116, Dirt },
        { 0xa1759593f3db6f28, 28, 107, Brick },
        { 0xa17794f0fdc55516, 34, 149, Brick, 7 },
        { 0xa17f35ee08150d7c, 9, 155 },
        { 0xa18f15a150602735, 49, 221, Smooth },
        { 0xa1aa41d9516f0cf3, 13, 110, Metal, 7 },
        { 0xa1c7296ecda0c10b, 36, 126, Dirt },
        { 0xa1ff4089894a423a, 74, 203, Bumpy },
        { 0xa209087f413c21d1, 0, 181, Bumpy, 7 },
        { 0xa20df58ddccd9776, 17, 154, Rounded },
        { 0xa2509d490d45ba1d, 10, 73, Metal, 7 },
        { 0xa25f2ff33f0d985a, 4, 129, Leaves },
        { 0xa27d6a9eda020221, 100, 208, Dirt },
        { 0xa27db8e6051ac017, 23, 137, Bumpy },
        { 0xa29317375edfad5d, 24, 162, Dirt },
        { 0xa294b8bc0d16b647, 21, 110, Metal, 7 },
        { 0xa2bf29619ffa0d64, 34, 180, Metal, 7 },
        { 0xa2c006363284479d, 63, 197, Rounded },
        { 0xa2cede0facc04fa3, 25, 164, Metal, 7 },
        { 0xa2cf26b457afa04c, 24, 129, Metal, 7 },
        { 0xa2eda786883d0a13, 17, 247, Wood, 7 },
        { 0xa2f4f8571f9f4329, 37, 80, Wood, 7 },
        { 0xa2f53285183c5c33, 25, 199, Metal, 7 },
        { 0xa2fbd406fcc82afa, 0, 160 },
        { 0xa30a9795bfed5faa, 31, 95, Brick },
        { 0xa30b630e08fe9067, 36, 221 },
        { 0xa3296e0b31f67aa5, 15, 64, Bumpy },
        { 0xa32b519f2aaec955, 101, 219, Bumpy },
        { 0xa32c99c8fcb308ef, 27, 153, Bumpy },
        { 0xa336eb3decdfafb2, 89, 125, Wood, 7 },
        { 0xa3482879d3235bd1, 15, 112 },
        { 0xa34dee09ea021e7f, 23, 74, Bumpy },
        { 0xa35c79f04f53aa86, 120, 203, Metal, 7 },
        { 0xa39760d993820f23, 16, 155, Dirt },
        { 0xa3c4d099db9c7b85, 12, 145, Metal, 7 },
        { 0xa3c7d84a264ff0aa, 7, 114, Metal, 7 },
        { 0xa3e18cc5b2092a70, 20, 167, Brick },
        { 0xa3e5f72c07000df2, 27, 179, Bumpy },
        { 0xa3f601ea82d7f49a, 40, 186, Metal, 7 },
        { 0xa3fc446d1590570c, 7, 82 },
        { 0xa409be2c72be3570, 15, 178 },
        { 0xa40ed4f606a6bcce, 25, 174, Bumpy },
        { 0xa415017d816e8c8a, 21, 178, Smooth },
        { 0xa4290e283edf9a08, 41, 152 },
        { 0xa42f9db7100b1df3, 17, 187 },
        { 0xa43c7255397ee939, 25, 170, Dirt },
        { 0xa452d5ab4722ca21, 0, 88, Metal, 7 },
        { 0xa455894091918abc, 15, 157, Rounded },
        { 0xa45c682a45b6901e, 91, 218 },
        { 0xa45e6eb6df215fff, 61, 143, Grass },
        { 0xa46698ccae52c778, 28, 83, Wood, 7 },
        { 0xa46cd8fa45fa7bb3, 17, 148, Bumpy },
        { 0xa47b7057aa363cb6, 0, 149, Bumpy, 15 },
        { 0xa47e7bd6e9ed4cc1, 28, 122, Cracks },
        { 0xa48abe6b02572a6b, 15, 67, Bumpy },
        { 0xa49c90e0e00672c8, 17, 133, Wood },
        { 0xa49fb4fdb2e4025a, 36, 204, Wood, 7 },
        { 0xa4aee8d715ca78c9, 66, 169, Bumpy, 7 },
        { 0xa4b3a3e8da5423aa, 18, 142 },
        { 0xa4bec532754a7fef, 74, 166, Bumpy, 7 },
        { 0xa4c6c3fcaddb91da, 66, 166, Bumpy, 7 },
        { 0xa4cf0c8bc180dfa9, 0, 149, Metal, 7 },
        { 0xa4d7892f3c86d7f6, 0, 119, Metal, 7 },
        { 0xa4e5851d80f51828, 16, 166, Wood, 7 },
        { 0xa4e70087129de191, 0, 124, Bumpy },
        { 0xa50430d2d2af6fdd, 25, 170, Dirt },
        { 0xa5053c8eb9f6fa90, 7, 108, Stone, 7 },
        { 0xa506bdb5c689e702, 21, 196, Bumpy },
        { 0xa509255f2664aef8, 41, 99, Tiles, 7 },
        { 0xa51744f263a8df99, 16, 139 },
        { 0xa525d66c7a6c6133, 0, 82, Metal, 7 },
        { 0xa5364dc6d8eecfc0, 7, 179, Metal, 7 },
        { 0xa53c582ab77804c1, 37, 115, Cracks },
        { 0xa53e8319a245d052, 0, 224, Stone, 7 },
        { 0xa54ab3b37f6399d2, 2, 105, Wood, 7 },
        { 0xa5607cec5e10f98e, 47, 96, Bumpy, 7 },
        { 0xa577e32c6d12cd1a, 32, 135, Leaves },
        { 0xa57f67f36ca2f5e4, 9, 86, Metal, 7 },
        { 0xa58d445252dd94a3, 0, 238, Rounded },
        { 0xa5b866b8b4eef420, 0, 115 },
        { 0xa5d67522e054a3ec, 33, 175, Metal, 7 },
        { 0xa5e2cef314e46512, 23, 175, Metal, 7 },
        { 0xa6045147e0e7a456, 41, 165, Bumpy },
        { 0xa60e85dcf6f85f92, 40, 186, Stone },
        { 0xa61b06c88562fbad, 0, 151, Bumpy, 7 },
        { 0xa62a7a4045e244ed, 138, 195, Sand, 7 },
        { 0xa6305666423e78eb, 34, 68, Wood, 7 },
        { 0xa64628a50f2106d0, 18, 82, Stone, 7 },
        { 0xa64a1b2eac9f207c, 0, 125, Bumpy, 15 },
        { 0xa661bcde8daa3e24, 0, 146 },
        { 0xa674cd827a907caf, 12, 181 },
        { 0xa685dfe6cea99f5f, 10, 117, Stone, 7 },
        { 0xa6990b5f9ef08045, 15, 168, Metal, 7 },
        { 0xa69e0dc6c2638fc0, 4, 86, Grass },
        { 0xa69e383b25b27208, 68, 110 },
        { 0xa6aa8fd8983de63e, 70, 162, Bumpy },
        { 0xa6b1fd02d5614f7d, 7, 127, Brick },
        { 0xa6c43a742a5431ee, 10, 140, Brick },
        { 0xa6c8788d0c50de4a, 0, 139, Brick },
        { 0xa6d65800a9f28f7b, 7, 229, Metal, 7 },
        { 0xa70e1c9a0236b70a, 4, 150 },
        { 0xa72c861887019e20, 49, 247, Wood, 7 },
        { 0xa72d0b035e4439fa, 46, 173 },
        { 0xa73014eae44c2740, 81, 115 },
        { 0xa73562b346690e0e, 23, 118, Metal, 7 },
        { 0xa739e806f0516a5b, 16, 106, Cracks },
        { 0xa75a2e5e12a66fd2, 10, 82 },
        { 0xa775528ca2349220, 30, 99 },
        { 0xa77bf63a4bb16ce7, 7, 133, Wood, 7 },
        { 0xa7abe97054676acf, 28, 137, Wood, 7 },
        { 0xa7ae0e57ecff4eee, 16, 109, Cracks },
        { 0xa7bbdf5e3affd347, 16, 82 },
        { 0xa7c65237e5e725c9, 11, 189 },
        { 0xa7c75f38cce318f6, 21, 120, Metal, 7 },
        { 0xa7cf5818019da319, 10, 203 },
        { 0xa7f793a1f2f5421d, 40, 123, Brick },
        { 0xa82640b2845e7d98, 21, 112, Wood, 7 },
        { 0xa82c6bae60c736bf, 7, 90, Stone, 7 },
        { 0xa8332887c610f0f1, 0, 91, Metal, 7 },
        { 0xa83329f40b73a78b, 32, 136, Dirt },
        { 0xa84cf5c92451c9d6, 10, 131, Wood, 7 },
        { 0xa851d683f7b836f8, 37, 231, Bumpy, 7 },
        { 0xa86dce38d516fa09, 42, 156, Metal, 7 },
        { 0xa879c49006451054, 18, 152, Metal, 7 },
        { 0xa881ab84a0390719, 15, 183, Metal, 7 },
        { 0xa884c1ca41ec1127, 58, 163, Metal, 7 },
        { 0xa8999091d4a1f092, 19, 89, Rounded },
        { 0xa89b99ae8897ec88, 15, 164, Rounded },
        { 0xa89ff7be11dd7a4f, 7, 118, Metal, 7 },
        { 0xa8b4c42e366deb1f, 11, 75, Wood, 7 },
        { 0xa8ba99b89b8ce05e, 49, 156 },
        { 0xa8e8caccbf4180fb, 24, 158, Metal, 7 },
        { 0xa8f190b0f3cbcd59, 0, 95, Wood, 7 },
        { 0xa923df64a2fa96b7, 0, 121, Metal, 7 },
        { 0xa925a107f4c9edc6, 36, 153, Bumpy, 7 },
        { 0xa92f48b5288c6e5b, 10, 141, Metal, 7 },
        { 0xa932bf6b88e6fc6f, 15, 122, Bumpy },
        { 0xa940fd6b4a60e3a3, 26, 254 },
        { 0xa9623177beee5f46, 15, 152, Bumpy, 7 },
        { 0xa9690b65ed36091c, 63, 172, Rounded },
        { 0xa96d959e636af4bf, 2, 129, Bumpy },
        { 0xa98cd44b3c853507, 9, 137, Metal, 7 },
        { 0xa9a30e2c2dd1d4c9, 17, 126, Wood, 7 },
        { 0xa9c2a14aa3d16803, 24, 152, Bumpy, 7 },
        { 0xa9c6c08511d44618, 61, 185, Brick },
        { 0xa9c9585285fc0684, 14, 165, Rounded },
        { 0xa9d2b9a3ee29624a, 23, 168, Metal, 7 },
        { 0xa9d6e248b5f02181, 18, 188, Dirt },
        { 0xa9dcd8fd124b828a, 24, 94, Bumpy },
        { 0xa9eff74087fe8df3, 21, 139, Wood, 7 },
        { 0xa9f20b0c4ac98505, 33, 130, Wood, 7 },
        { 0xa9f56ccc9425035d, 46, 169, Rounded },
        { 0xa9f95d7e99c45ea7, 74, 173, Ice, 0, false },
        { 0xaa1283507401823a, 0, 140, Bumpy },
        { 0xaa14bdbf49a24366, 10, 141, Wood, 7 },
        { 0xaa4030800363aab8, 2, 137, Wood, 7 },
        { 0xaa4fb767534de6b1, 0, 160, Rounded },
        { 0xaa618c2d88ca4077, 16, 172, Bumpy, 15 },
        { 0xaa6a980f4cd57392, 46, 155, Bark },
        { 0xaa6e13b8066e0811, 24, 110, Dirt },
        { 0xaa82e69cadb0e937, 14, 146, Leaves },
        { 0xaa962abd25d9510d, 20, 172 },
        { 0xaac84b3284715d31, 16, 163, Bumpy, 15 },
        { 0xaae87d0c8c851ec6, 10, 141, Bark, 15 },
        { 0xaaee5201dd8f2759, 4, 59 },
        { 0xab1be3153dce6e0f, 0, 81, Brick },
        { 0xab221bcfb1ff608f, 15, 184 },
        { 0xab261f00fcc2c4a1, 52, 126, Wood, 7 },
        { 0xab57eb88d914d923, 14, 142, Metal, 7 },
        { 0xab5d051a0cd96804, 22, 132, Leaves },
        { 0xab6be82fea216784, 35, 140, Wood, 7 },
        { 0xab77c8d42d1736a4, 53, 95, Wood, 7 },
        { 0xab8e5c4f1a5abb67, 41, 132, Stone, 7 },
        { 0xab8f9c1cb8b507ab, 23, 126, Bumpy },
        { 0xaba49f2bd348c7d5, 31, 219, Smooth },
        { 0xabc507d3fc53778b, 0, 152, Rounded },
        { 0xabca800b2dec72e0, 12, 146, Leaves },
        { 0xabd20886f7786a44, 7, 157, Wood, 7 },
        { 0xabd2c87baba20e5f, 0, 141 },
        { 0xabd94ab9611a9a01, 56, 184, Metal, 7 },
        { 0xabda8bbba4cddc60, 11, 99 },
        { 0xabf6f8e3fe0eeab5, 17, 117, Bark, 15 },
        { 0xac10bb8e872631a3, 15, 175 },
        { 0xac1cc49c584ac0eb, 10, 85, Metal, 7 },
        { 0xac218b43a6d21568, 15, 111, Stone, 7 },
        { 0xac3caa207ef665f3, 12, 76, Metal, 7 },
        { 0xac535dd5a290b70b, 32, 188, Rounded },
        { 0xac53c39d18b1002d, 41, 176, Metal, 7 },
        { 0xac5f9951be1d6790, 15, 158 },
        { 0xac6e506103371664, 0, 212, Bumpy },
        { 0xacb4d25d3b2afa49, 18, 178, Metal, 7 },
        { 0xacdfca0076008f4a, 7, 124, Metal, 7 },
        { 0xacec28b81f63a44b, 75, 181, Rounded },
        { 0xaceee5e898f23f85, 130, 225 },
        { 0xad0c2d276f949ed2, 15, 172, Stone, 7 },
        { 0xad140731b3754d68, 5, 180 },
        { 0xad1a6f82078e0f25, 9, 137, Metal, 7 },
        { 0xad1a8d1b824db315, 0, 77, Metal, 7 },
        { 0xad2b8d0f88245995, 17, 140, Metal, 7 },
        { 0xad39f488b6cde9bf, 7, 149, Metal, 7 },
        { 0xad415a75840c37f0, 37, 94, Metal, 7 },
        { 0xad44eff085c0b866, 0, 209, Metal, 7 },
        { 0xad7902c7084c8d22, 25, 121, Wood, 7 },
        { 0xad894856bef14f41, 17, 102, Wood, 7 },
        { 0xadae48789688a435, 17, 178, Rounded },
        { 0xadae65bf96c42d8f, 18, 119, Metal, 7 },
        { 0xadccd83290101198, 49, 157 },
        { 0xade00442025589ca, 19, 190, Bumpy },
        { 0xadf80a4579c90177, 15, 88, Metal, 7 },
        { 0xae0b4d543b16a9ac, 21, 95, Brick },
        { 0xae0fb196b4b721f2, 24, 164, Bumpy },
        { 0xae143d3065fa42e6, 67, 143, Metal, 7 },
        { 0xae1c01f3a5f4259e, 0, 169, Stone, 7 },
        { 0xae2dd14baf47086c, 41, 247, Wood, 7 },
        { 0xae436b1f52b9b6e6, 69, 184, Ice, 0, false },
        { 0xae5b3131b684cffb, 0, 108, Wood, 7 },
        { 0xae67e8e96592a1fa, 18, 152, Metal, 7 },
        { 0xaea5124156ccb293, 12, 174, Bumpy },
        { 0xaeace8a315463d62, 57, 183, Bumpy, 7 },
        { 0xaec49560e8bd1c06, 0, 189, Wood, 7 },
        { 0xaed9eea3aa92213f, 0, 62, Metal, 7 },
        { 0xaee03f44fed81570, 2, 125, Wood, 7 },
        { 0xaee7537f2f606214, 43, 171, Metal, 7 },
        { 0xaef9b50089cd8e31, 33, 157 },
        { 0xaf0d12b079cf82fc, 9, 105, Rounded },
        { 0xaf29198cc320c313, 10, 102, Wood, 7 },
        { 0xaf4525b8b4c04e40, 2, 113, Metal, 7 },
        { 0xaf4d0117184ab07d, 42, 170, Metal, 7 },
        { 0xaf571c466134b7ea, 21, 64 },
        { 0xaf8cae0d28892445, 28, 230, Bumpy },
        { 0xafa298cdd876caee, 2, 172 },
        { 0xafb352c79c8fb406, 0, 158 },
        { 0xafcd48cdef16366b, 0, 101, Wood, 7 },
        { 0xafd46d1550545c8d, 2, 113, Bark },
        { 0xaffc186424cd8ef1, 34, 131 },
        { 0xb012f2948d350e9a, 7, 148 },
        { 0xb029e06361834389, 7, 153, Wood, 7 },
        { 0xb037df448223153e, 56, 114 },
        { 0xb05de8a77af32577, 0, 160, Metal, 7 },
        { 0xb0616ec66aae6c81, 17, 132, Tiles, 7 },
        { 0xb07a5d8812aa38bb, 30, 140, Metal, 7 },
        { 0xb09981dcf815abc1, 50, 155, Metal, 7 },
        { 0xb0aaf35ff7a9537f, 24, 217, Bumpy },
        { 0xb0d2f1680acf2cd6, 54, 247, Rounded },
        { 0xb0f0d788922a8c74, 0, 128, Metal, 7 },
        { 0xb0f31814ca84c8a8, 49, 156, Bumpy },
        { 0xb1047c503517dd5b, 9, 135, Metal, 7 },
        { 0xb138d43125fc5775, 54, 130, Metal, 7 },
        { 0xb1690e5cf0e55e6f, 41, 198 },
        { 0xb16e71a5324b1cab, 45, 98 },
        { 0xb18466e59af8a35c, 21, 92 },
        { 0xb19bfaa29191d3d1, 0, 162 },
        { 0xb1e6c8b0697d1274, 0, 207 },
        { 0xb1e9d035a5dc3d72, 43, 154, Bumpy },
        { 0xb1ec271147f0ed82, 10, 121, Wood, 7 },
        { 0xb2071ad8aa6fed79, 18, 99, Cracks },
        { 0xb2319b35370a50f8, 34, 225, Rounded },
        { 0xb274adf310bd4283, 33, 166, Bumpy },
        { 0xb27a8b6573bd1d3f, 67, 129, Wood, 7 },
        { 0xb28100d5df745365, 0, 104, Stone, 7 },
        { 0xb288830472f9b295, 19, 137, Leaves },
        { 0xb2923ccf7df89c29, 61, 174, Dirt, 7 },
        { 0xb294cd9746100f7d, 27, 127, Wood, 7 },
        { 0xb29ed8b4a87ffad7, 16, 120, Metal, 7 },
        { 0xb2a807efb4ab65bb, 28, 147, Metal, 7 },
        { 0xb333e4077bbc4226, 71, 194, Rounded },
        { 0xb36c715cff99f080, 14, 147, Leaves },
        { 0xb37abb87aa3231a2, 10, 189, Bumpy },
        { 0xb3904d875784e0a5, 66, 165, Bumpy, 7 },
        { 0xb39341dfc580c244, 35, 103, Wood, 7 },
        { 0xb3998371b5018263, 17, 119, Metal, 7 },
        { 0xb3aac0a9f6b88d5e, 48, 162, Tiles, 7 },
        { 0xb3b06d5b88831d93, 0, 143, Metal, 7 },
        { 0xb3dbb68c77ed34b2, 9, 169, Bumpy },
        { 0xb3f7875ac1fc7ed8, 53, 248, Metal, 7 },
        { 0xb3fd7240bdd3646a, 40, 141 },
        { 0xb41b217e154f61fb, 44, 94 },
        { 0xb43314e16bf0b4e3, 33, 128, Bumpy, 7 },
        { 0xb46104a301d5c7c8, 0, 86 },
        { 0xb47f50da39d5c0f3, 10, 148, Metal, 7 },
        { 0xb486624422010a14, 40, 104, Wood, 7 },
        { 0xb4960fb8f7799f0d, 10, 147, Leaves },
        { 0xb4b6357372826639, 7, 168, Metal, 7 },
        { 0xb4baa6487c8ca8b9, 48, 168, Bumpy },
        { 0xb4cd454ea469d4f2, 33, 110 },
        { 0xb50440325f38ea78, 0, 103, Metal, 7 },
        { 0xb5185cb35b5559d8, 31, 106, Ice, 0, false },
        { 0xb524593b446b465c, 32, 78, Metal, 7 },
        { 0xb52788f10a0d0957, 15, 81, Wood, 7 },
        { 0xb570b1775626ec40, 24, 155, Metal, 7 },
        { 0xb58e68e8e6c4d273, 28, 229, Rounded },
        { 0xb5a17119d8286cc3, 41, 68 },
        { 0xb5a248bb60754677, 24, 148, Wood, 7 },
        { 0xb5ad94ac4cb852f6, 18, 179, Bumpy },
        { 0xb5bb6294be859050, 43, 162, Metal, 7 },
        { 0xb5c3e1503154df36, 33, 213, Bumpy, 15 },
        { 0xb5cec4e320632b6b, 8, 91, Bumpy },
        { 0xb5d33b69d87b0a9b, 25, 137 },
        { 0xb5d37bb832c46ab6, 157, 201, Sand, 7 },
        { 0xb602e5e84f1c0632, 0, 167, Bumpy, 7 },
        { 0xb6044a8ccdb834d6, 25, 119, Bark },
        { 0xb608ba3cf174cd12, 27, 87, Leaves },
        { 0xb61057728ec94d45, 8, 96, Brick },
        { 0xb617d006e46cacb2, 23, 92, Metal, 7 },
        { 0xb627be613ae265f1, 26, 107, Metal, 7 },
        { 0xb63015dade4ccf05, 56, 169, Stone, 7 },
        { 0xb630fa75808a126a, 67, 161, Stone, 7 },
        { 0xb6353b0dcdc0da8c, 5, 91, Metal, 7 },
        { 0xb63c1d988baf97fc, 2, 129 },
        { 0xb65133698af75fa0, 12, 159, Bumpy },
        { 0xb656ed8cad322400, 11, 139, Wood, 7 },
        { 0xb6640fc75e630756, 0, 121, Bumpy },
        { 0xb691799a8d569813, 48, 163, Bumpy },
        { 0xb692a4ebeefd4dd3, 4, 150, Stone, 7 },
        { 0xb69be0001d12b8a9, 0, 159, Metal, 7 },
        { 0xb69c55ec5d5b1b8b, 7, 123 },
        { 0xb6c3d4fbf6aca2c6, 9, 86, Leaves },
        { 0xb6cf9480ccb27ccf, 69, 171, Wood, 7 },
        { 0xb6f8bbbed7d5ee0e, 48, 203, Bumpy },
        { 0xb6fcd67489647e96, 18, 108, Rounded },
        { 0xb706dbf96475cc5f, 10, 221, Bumpy },
        { 0xb70c260c734f62fe, 28, 201, Metal, 7 },
        { 0xb7154e176cab9b89, 58, 134, Bumpy, 7 },
        { 0xb717793fa34a1632, 0, 151, Stone, 7 },
        { 0xb733740449c82d29, 17, 161, Bumpy },
        { 0xb764ecaea4991bac, 21, 104, Brick },
        { 0xb76a18e61958cae5, 15, 121, Metal, 7 },
        { 0xb76afe336c7c29b8, 25, 113, Metal, 7 },
        { 0xb76c4a89c5b7fdcf, 10, 152, Metal, 7 },
        { 0xb786399b0071826a, 10, 133, Metal, 7 },
        { 0xb7a3c9e0e8a7e50d, 49, 201, Metal, 7 },
        { 0xb7ab00dd19df192b, 42, 151, Metal, 7 },
        { 0xb7b1698056c3cc29, 0, 150 },
        { 0xb7ba16c30dc30db3, 26, 121 },
        { 0xb7c1754d6ddd9956, 25, 198 },
        { 0xb7d6e7ed9276a3ab, 56, 150, Metal, 7 },
        { 0xb7d85a0b64f8887b, 59, 150, Bumpy, 7 },
        { 0xb7d90e01e340d2c0, 17, 120, Metal, 7 },
        { 0xb7e8e326c474cb60, 40, 114, Rounded },
        { 0xb812256cd76cd695, 9, 149, Bumpy },
        { 0xb831fcffaa4b86d9, 36, 110, Wood, 7 },
        { 0xb84afa9cd9f0188f, 49, 118, Metal, 7 },
        { 0xb84f027e7b95a96b, 19, 155, Wood, 7 },
        { 0xb865f87c32feeb67, 41, 214, Bumpy, 7 },
        { 0xb86decadbbb5b6d5, 41, 162 },
        { 0xb8836166e6779162, 7, 141, Leaves },
        { 0xb8b0eb9d3c853dba, 15, 128, Dirt, 7 },
        { 0xb8bdd1f40b699a85, 16, 139, Rounded },
        { 0xb8db8dd17dc644ec, 7, 142, Stone, 7 },
        { 0xb8f45a0b0594cd67, 7, 126, Bumpy },
        { 0xb92dfae412e94d0c, 31, 95, Metal, 7 },
        { 0xb92fb1645f39ed49, 33, 247, Metal, 7 },
        { 0xb93ddfdacda3144c, 29, 153, Rounded },
        { 0xb94b7a12fad63902, 24, 66, Bumpy, 7 },
        { 0xb96cf8a78a6f0a5e, 10, 102, Metal, 7 },
        { 0xb97617bcad095426, 54, 134, Brick },
        { 0xb9845ade19e54572, 0, 185, Metal, 7 },
        { 0xb9862f775a0ad8c7, 10, 101 },
        { 0xb99861018e26672a, 41, 149, Bumpy },
        { 0xb9ba390865aa6d04, 29, 247, Ice, 0, false },
        { 0xb9d310cb7a7c7933, 30, 223, Metal, 7 },
        { 0xb9d792e14a181a6e, 55, 156 },
        { 0xb9f5123bf1caad50, 23, 136, Metal, 7 },
        { 0xba28e99c898a0601, 44, 118, Dirt, 7 },
        { 0xba2d2454033dea66, 33, 129, Wood, 7 },
        { 0xba2dc3d7540c679c, 32, 169, Rounded },
        { 0xba36a0629f3d7917, 7, 110, Brick },
        { 0xba43b8ff32939879, 0, 217, Metal, 7 },
        { 0xba4451260120cc20, 7, 210, Bumpy, 7 },
        { 0xba47f7fec7557515, 31, 137, Tiles, 7 },
        { 0xba4e3d80104bed92, 18, 67, Wood, 7 },
        { 0xba81046702fb1ed0, 2, 123, Wood, 7 },
        { 0xbab90b28259e10b1, 43, 143, Bumpy },
        { 0xbadfc8c99a7ba54a, 44, 162, Cracks },
        { 0xbae56b64e06ca623, 15, 74, Metal, 7 },
        { 0xbae840fc18bac10c, 18, 159 },
        { 0xbaf0e9ae06c533c4, 56, 156 },
        { 0xbafe075e027175c8, 0, 116 },
        { 0xbb1c16e40221df80, 10, 157, Wood, 7 },
        { 0xbb35ab13578a2f58, 26, 97, Metal, 7 },
        { 0xbb3c113dedc23ac6, 7, 214, Terraced },
        { 0xbb75836daa4d7ce5, 54, 165, Bumpy, 7 },
        { 0xbb8192ef95c7ce14, 25, 91, Wood, 7 },
        { 0xbb9603e4159d5dcd, 4, 114 },
        { 0xbb9d8f48528dc33f, 0, 152, Metal, 7 },
        { 0xbba4fefc4b7d49eb, 10, 247, Bumpy },
        { 0xbbab69ccc7816278, 40, 107 },
        { 0xbbc18c841f359a8f, 47, 186, Cracks },
        { 0xbbf770fe909b287b, 51, 138, Bumpy },
        { 0xbc37be3ebae490a4, 7, 160, Bark, 15 },
        { 0xbc43a6a96887eb5a, 46, 172, Leaves },
        { 0xbc6fd2476db96aa7, 0, 119, Stone, 7 },
        { 0xbc915a4ca0e49b40, 16, 114, Bumpy },
        { 0xbca9e7e8230595d4, 10, 121, Wood, 7 },
        { 0xbcae94b32238dd3d, 7, 177, Wood, 7 },
        { 0xbcd60fc302af1189, 11, 138, Bumpy },
        { 0xbcdb64c6debfc1ae, 42, 197, Metal, 7 },
        { 0xbcf4cc8679b482d7, 26, 142, Metal, 7 },
        { 0xbd302941764573ef, 12, 175, Wood, 7 },
        { 0xbd622869984ea4d1, 34, 214, Metal, 7 },
        { 0xbd7017c0dd86ab83, 33, 204 },
        { 0xbd783fa3c4e6a51d, 0, 144, Bumpy },
        { 0xbd83470dc2be0320, 31, 139 },
        { 0xbd8be19e821ed184, 7, 132, Wood, 7 },
        { 0xbd907053c0a27a0f, 34, 110, Metal, 7 },
        { 0xbda171752f546440, 17, 109, Metal, 7 },
        { 0xbdb6a01c0aef186a, 9, 132, Wood, 7 },
        { 0xbdb943cddf7a8aaf, 0, 191, Metal, 7 },
        { 0xbde6f89ff645d256, 23, 149, Cracks },
        { 0xbe13b4ff8d8e0bf6, 7, 113, Bumpy },
        { 0xbe15459056e9d1b4, 16, 147, Bumpy, 7 },
        { 0xbe366f310281b20f, 0, 94, Metal, 7 },
        { 0xbe5110de4476c4fc, 0, 68 },
        { 0xbe60c6ba7dd3b6ed, 7, 149, Leaves },
        { 0xbe73da425ef132d5, 33, 206, Metal, 7 },
        { 0xbe7ca36598f4cac3, 9, 136, Bumpy },
        { 0xbe8f839ceefe38d4, 11, 129, Wood, 7 },
        { 0xbea4752505c12c45, 16, 112 },
        { 0xbeb28bae8e949cb8, 54, 203, Dirt },
        { 0xbeb754d38f257f98, 38, 166, Bumpy, 7 },
        { 0xbeb8f8d1c675a7cd, 0, 125, Metal, 7 },
        { 0xbecfbf4731ccb363, 17, 131 },
        { 0xbed31b2dc11a0ef2, 28, 107, Metal, 7 },
        { 0xbedffc84449a8404, 18, 166 },
        { 0xbeeb95e53912706e, 38, 161 },
        { 0xbef11d6185195803, 0, 181, Bumpy, 7 },
        { 0xbf142cd45521c2a9, 74, 205, Sand, 7 },
        { 0xbf248c19aabe947b, 16, 111 },
        { 0xbf27855f92dba7b6, 2, 163, Stone, 7 },
        { 0xbf374b8eabd63568, 20, 154, Rounded },
        { 0xbf6f171e83660761, 33, 102, Wood, 7 },
        { 0xbfc40d7b3dece6b7, 95, 217, Ice, 0, false },
        { 0xbfc628d6a6a0bb45, 27, 105 },
        { 0xbfcfb7888129f279, 8, 176, Rounded },
        { 0xbfdb7d5617ff07d6, 18, 125, Bumpy },
        { 0xbffb74b475a8f845, 7, 167, Bumpy },
        { 0xc00955eab5cf1064, 20, 166, Metal, 7 },
        { 0xc00e4949336c6fc9, 0, 124, Metal, 7 },
        { 0xc013d2f1614f8c75, 28, 185, Wood, 7 },
        { 0xc01636bd34f40333, 74, 169, Stone, 7 },
        { 0xc018e6c0bf3d253f, 27, 108, Brick },
        { 0xc02ac78ae12a6577, 7, 148, Wood, 7 },
        { 0xc03abd6a4d9d4295, 30, 107, Ice, 0, false },
        { 0xc04f4656f4aad135, 15, 148, Bumpy },
        { 0xc07d602ddfdbb77b, 85, 181, Dirt },
        { 0xc07f9031797fa8cb, 27, 187, Grass, 7 },
        { 0xc0ad6f3ae735fb3f, 20, 114 },
        { 0xc0e29cf73101030e, 0, 228, Bumpy },
        { 0xc0e61eb0010dadc0, 11, 94, Wood, 7 },
        { 0xc0ed078689a5622e, 47, 187, Metal, 7 },
        { 0xc0edabc93af6bd50, 2, 102, Metal, 7 },
        { 0xc104bfc6cb7e6bf8, 5, 110, Rounded },
        { 0xc1072849fdccb4b2, 0, 172 },
        { 0xc10dba28023b0684, 44, 240, Bumpy, 7 },
        { 0xc133a77850bf892e, 0, 65, Bark },
        { 0xc1468657a9ffc9ce, 37, 165 },
        { 0xc1575dd48f3a72df, 33, 157, Rounded },
        { 0xc16c6f9500335f08, 2, 149 },
        { 0xc18e4c7d3c19913c, 7, 174, Bumpy },
        { 0xc1a7332320ebbc3a, 7, 84, Bumpy },
        { 0xc1bd310142106cb1, 24, 158, Smooth },
        { 0xc1e65a8a924884d2, 29, 215 },
        { 0xc1fcda6be5418dd9, 132, 211, Tiles, 7 },
        { 0xc207f7789a5f0f11, 21, 73, Rounded },
        { 0xc2123d9f415c5b0a, 7, 133, Bark },
        { 0xc232f2ff08279dce, 7, 164, Wood, 7 },
        { 0xc2415572a9927224, 0, 152, Tiles, 7 },
        { 0xc24d06e0cecb4276, 29, 167, Dirt },
        { 0xc25e1c0e8bb1acac, 42, 90, Brick },
        { 0xc263009fe90abc95, 30, 111 },
        { 0xc276b0253b0d6e40, 11, 171 },
        { 0xc297078a7f0c92ad, 15, 137, Brick },
        { 0xc2bcbd4e70a02eb1, 0, 118 },
        { 0xc2bcbf9cc24db01c, 100, 186, Cracks, 7 },
        { 0xc2c1c401b52c8e2e, 21, 113, Cracks },
        { 0xc2d9ede4bd1654f6, 86, 247, Tiles, 7 },
        { 0xc2dac938089e0303, 25, 169, Smooth },
        { 0xc2eb688aafe50cf1, 8, 163, Metal, 7 },
        { 0xc2f61620b20cc301, 15, 155 },
        { 0xc2f8dffd41d1d262, 32, 206, Wood, 7 },
        { 0xc2fe0aa22dd4fe83, 50, 100, Dirt, 7 },
        { 0xc305e6be7805bb88, 0, 68, Rounded },
        { 0xc3236d0574086eac, 21, 94, Smooth },
        { 0xc3284b0014d45930, 26, 241, Bumpy },
        { 0xc32cbecef47fc667, 17, 130, Wood, 7 },
        { 0xc32ea6c90ab112c4, 37, 108, Smooth },
        { 0xc340bdd88a499268, 0, 148, Metal, 7 },
        { 0xc36ce138643bae23, 14, 93, Leaves },
        { 0xc3891248090bf04e, 7, 186, Bumpy },
        { 0xc38ca61e3e26eb46, 10, 193, Brick },
        { 0xc3a7b61605549a39, 34, 108, Metal, 7 },
        { 0xc3bced8b6b276c60, 0, 162, Terraced },
        { 0xc3c8d31c4cc2523f, 44, 154, Bumpy },
        { 0xc3ce45257edceaa6, 35, 115, Brick },
        { 0xc3d7604e02cd7d74, 0, 56 },
        { 0xc3ef62edd84ea687, 27, 252, Ice, 0, false },
        { 0xc3fcd00459ec477b, 17, 74, Brick },
        { 0xc3ffc54eb680c953, 18, 91, Cracks },
        { 0xc4025a99e510cf93, 33, 176, Metal, 7 },
        { 0xc4038f13370a94d0, 9, 224, Bumpy },
        { 0xc406be7794d0d2df, 27, 136, Bumpy },
        { 0xc414cc1265ff5206, 2, 149, Wood, 7 },
        { 0xc42ffaff478d9471, 12, 110, Brick },
        { 0xc445e7c031f07440, 2, 133, Wood, 7 },
        { 0xc45505ae1ba6a9d1, 33, 90, Brick },
        { 0xc464d44979a98f0b, 42, 80, Dirt, 7 },
        { 0xc469eff2c4e92b9c, 13, 124, Metal, 7 },
        { 0xc47086b521f75673, 21, 76, Dirt, 7 },
        { 0xc487e32d8285b942, 0, 126 },
        { 0xc48b302249ea7176, 17, 78, Bumpy, 7 },
        { 0xc49eb2e5c74522c0, 17, 126, Leaves },
        { 0xc4ab4868610138e5, 0, 99 },
        { 0xc4c373ced87fa85c, 24, 219, Metal, 7 },
        { 0xc4d4246482cea4e1, 66, 214, Metal, 7 },
        { 0xc4e95cf0d996ab6b, 2, 64, Metal, 7 },
        { 0xc4ee0af5713d8fba, 68, 126, Dirt, 7 },
        { 0xc4f45c0707948a59, 54, 198, Smooth },
        { 0xc5039a780fe1e69c, 24, 173 },
        { 0xc51008299112dab0, 18, 120, Brick },
        { 0xc53c161765d0eb9e, 58, 190, Metal, 7 },
        { 0xc53f9e8924c78ad6, 16, 98, Metal, 7 },
        { 0xc541dc4a70885b0f, 0, 124, Metal, 7 },
        { 0xc5451ca8e1a60068, 0, 219 },
        { 0xc5458ae4debfa138, 0, 162, Wood, 7 },
        { 0xc555d06973dd6d54, 20, 173, Rounded },
        { 0xc56bf3324630a5a0, 7, 109, Grass },
        { 0xc57080f48c24691d, 24, 126, Bumpy },
        { 0xc59f29d0f7ee6a98, 27, 109, Dirt, 7 },
        { 0xc5aa81b3d8d80c66, 36, 100, Metal, 7 },
        { 0xc5afc7268306326f, 82, 156, Sand, 7 },
        { 0xc5f9e13762b9d0b8, 42, 223, Rounded },
        { 0xc61c94cd9ee32784, 50, 211, Metal, 7 },
        { 0xc62c86c01a142396, 51, 146, Wood, 7 },
        { 0xc6302aa54eadf48d, 32, 132, Leaves },
        { 0xc64c6cb16d6453e1, 2, 154, Wood, 7 },
        { 0xc6517a9afaa92d24, 9, 177, Wood, 7 },
        { 0xc65f216815fcf942, 15, 158, Metal, 7 },
        { 0xc68dbbc4a544e2ca, 47, 140, Dirt },
        { 0xc6a06d6be6064e93, 29, 145, Dirt },
        { 0xc6a6d9af6350452c, 0, 75, Metal },
        { 0xc6a8bafaf2e247d3, 24, 109, Metal, 7 },
        { 0xc6c83c8d0f1f6b8a, 141, 226, Cracks, 7 },
        { 0xc6ca7e815c15250b, 59, 123, Tiles, 7 },
        { 0xc6d46defeefe3d62, 10, 90, Metal, 7 },
        { 0xc6e5d539fbad23ec, 48, 166, Metal, 7 },
        { 0xc6f04e27131f8420, 0, 107, Rounded },
        { 0xc6fa6791fead6038, 22, 172, Bumpy },
        { 0xc6fb33c6dbebacad, 17, 90 },
        { 0xc6fd346ff864d089, 36, 162, Metal, 7 },
        { 0xc720731faa60507b, 27, 95, Ice, 0, false },
        { 0xc727761fce953f65, 63, 171, Bumpy },
        { 0xc73ea6f8dcaede92, 9, 101, Metal, 7 },
        { 0xc742d778d4c95fb1, 42, 162, Rounded },
        { 0xc743777e651e64d6, 10, 116, Bumpy, 7 },
        { 0xc74a5d1cdb6ff209, 17, 132, Metal, 7 },
        { 0xc759efaff5344409, 15, 148, Metal, 7 },
        { 0xc760da60fcc2c692, 24, 140, Metal, 7 },
        { 0xc76366f7f49725fa, 0, 74 },
        { 0xc76d77e9d247d5ac, 0, 99 },
        { 0xc7ae39cb3c85ebfb, 11, 156, Metal, 7 },
        { 0xc7c4a14fbe697e13, 55, 170, Rounded },
        { 0xc7c610827d5b8dc4, 51, 203, Smooth },
        { 0xc7cc912f49160416, 119, 207 },
        { 0xc7dab4b4ee4047ab, 9, 139, Wood, 7 },
        { 0xc7e70835bb90709f, 0, 94 },
        { 0xc7e93934f0d653a0, 33, 152, Bumpy, 7 },
        { 0xc7eeca9edbdcbcdb, 0, 159 },
        { 0xc800d2e225ab3de5, 43, 138 },
        { 0xc819d32430d04474, 23, 125, Tiles, 7 },
        { 0xc8366236a2ceb63a, 0, 102, Metal, 7 },
        { 0xc84774c4aec58a24, 11, 153, Brick },
        { 0xc862c8496e50d3ae, 37, 100, Bumpy, 7 },
        { 0xc87d3ac47c07a33d, 0, 99, Dirt, 7 },
        { 0xc87df6931b1a146f, 9, 178, Bumpy },
        { 0xc891c24372c18de2, 9, 107, Dirt },
        { 0xc8945525d458b1fd, 0, 112, Metal, 7 },
        { 0xc89ab5657206b883, 34, 150, Wood, 7 },
        { 0xc8b5febb798c3829, 11, 54, Smooth },
        { 0xc8f57e8d3428e974, 13, 82 },
        { 0xc910cbda075e2e88, 0, 149 },
        { 0xc936b73b4ef95aa5, 4, 99, Leaves },
        { 0xc95e5fa9fd513384, 40, 109, Dirt, 7 },
        { 0xc987efbbbbb271bd, 0, 166 },
        { 0xc9893f88da45f4b1, 33, 172, Terraced },
        { 0xc98b3e17fe122760, 36, 185, Bumpy },
        { 0xc99502e46df5d5ae, 9, 90, Wood, 7 },
        { 0xc9d07c3b79818c1f, 51, 164, Tiles, 7 },
        { 0xca0fbf643d425952, 49, 166, Bumpy },
        { 0xca13f12e2276e786, 43, 126, Dirt, 7 },
        { 0xca2dda4914227f0e, 0, 92, Bumpy },
        { 0xca3ac18fa0ee884d, 32, 244, Ice, 0, false },
        { 0xca5cbf59b46e892b, 41, 153, Rounded },
        { 0xca6c07caeead8e52, 0, 181, Metal, 7 },
        { 0xca7ce0a0d8b68144, 24, 84, Wood, 7 },
        { 0xca81ecc5b3694ce1, 24, 143, Sand, 7 },
        { 0xca9b69f1a907e13e, 73, 182, Wood, 7 },
        { 0xcaa8e7967450a381, 49, 109, Bumpy, 7 },
        { 0xcaab85e3af47d3ca, 48, 130, Cracks },
        { 0xcac6e9d96c39cb27, 4, 158 },
        { 0xcad7f1fe05318307, 49, 114, Bumpy, 7 },
        { 0xcad910f996402e64, 28, 151, Rounded },
        { 0xcadc48b0b699c2ee, 33, 183, Metal, 7 },
        { 0xcaef5f37b110377b, 9, 119, Bumpy },
        { 0xcaf51b9f35c17fb4, 9, 131 },
        { 0xcb0b278ccffcacfd, 46, 183 },
        { 0xcb10c9b18d25c1a1, 42, 127, Metal, 7 },
        { 0xcb1cd298280e4491, 92, 165, Sand, 7 },
        { 0xcb2add03bfc71951, 29, 132, Cracks },
        { 0xcb32c6a552a1c7be, 14, 113, Cracks },
        { 0xcb3d8d6a5a2b1ba0, 0, 159, Metal, 7 },
        { 0xcb4a5fd1a6a2e661, 36, 185, Metal, 7 },
        { 0xcb6d2394425a6c75, 37, 194, Bumpy },
        { 0xcb738fa74eaaa007, 0, 144 },
        { 0xcbaa9fa3bc466415, 7, 158, Rounded },
        { 0xcbb37a01a88b8dd6, 88, 211 },
        { 0xcbbb580295bd83a2, 50, 182, Tiles, 7 },
        { 0xcbbe6cd0cf49a35a, 61, 190, Brick },
        { 0xcbd2a8ab03d36a29, 16, 129 },
        { 0xcbe1191638d658c5, 27, 157, Metal, 7 },
        { 0xcc2af20ed8927f50, 63, 222, Rounded },
        { 0xcc2b60a136d2c850, 94, 155, Metal, 7 },
        { 0xcc47393386eb5bfc, 14, 199 },
        { 0xcc4c16500bf1a307, 71, 195 },
        { 0xcc4f2b784240d236, 23, 121, Dirt },
        { 0xcc60f61883cea649, 31, 166 },
        { 0xcc837d40b0a45053, 15, 199, Bumpy },
        { 0xccaefbc13a266aba, 24, 214, Metal, 7 },
        { 0xccddecbfd3908187, 31, 91, Leaves, 7 },
        { 0xccdfc014b6782112, 7, 165, Metal, 7 },
        { 0xcce47b6a6c42ab7b, 57, 228 },
        { 0xccf9d177385d4ea6, 79, 186 },
        { 0xcd07a7dd6e04ede7, 18, 172 },
        { 0xcd0d975d6a1a3107, 45, 246, Metal, 7 },
        { 0xcd3125fb97b26599, 29, 159, Ice, 0, false },
        { 0xcd3900c65823069d, 79, 170, Bumpy, 7 },
        { 0xcd55092bd5dfc4e4, 25, 105, Wood, 7 },
        { 0xcd72bc01685b7ce4, 7, 148, Metal, 7 },
        { 0xcd9caad61f9b2b77, 33, 157, Bumpy },
        { 0xcdb613622d5c5991, 0, 91, Metal, 7 },
        { 0xcdb773e87aa53f86, 166, 234, Sand, 7 },
        { 0xcdbacf30b8830043, 30, 96, Brick },
        { 0xcdbe0c5100aaab94, 0, 117, Bumpy },
        { 0xcdcb858c01d2720c, 57, 178, Dirt, 7 },
        { 0xcdd960c27b4778c7, 17, 138 },
        { 0xcde58f70f69d6312, 30, 106, Wood, 7 },
        { 0xcdf02e20f69e61f0, 24, 100, Metal, 7 },
        { 0xcdf88e0215f530e7, 42, 165, Metal, 7 },
        { 0xce16beb16ec9bb97, 25, 120, Metal, 7 },
        { 0xce1841ffdfac064d, 31, 154, Bumpy },
        { 0xce322197859812b3, 9, 35 },
        { 0xce3952edce0e23b1, 10, 157, Metal, 7 },
        { 0xce4ac150af1251fd, 27, 91, Metal, 7 },
        { 0xce591e8142597cca, 54, 247, Ice, 0, false },
        { 0xce6c77f714b5c093, 17, 119, Metal, 7 },
        { 0xce7195375ad16a07, 11, 194, Bumpy },
        { 0xce75b46395137551, 20, 146, Brick },
        { 0xcea091859edffb7a, 70, 148, Smooth },
        { 0xcea4f61a7e7130be, 49, 149, Ice, 0, false },
        { 0xcea8be5df90d2df4, 14, 155, Dirt, 7 },
        { 0xcebb441714f8c0f6, 27, 136, Bumpy },
        { 0xcebd03adf337b45e, 19, 105, Wood, 7 },
        { 0xcebe2682675a72fd, 10, 207, Metal, 7 },
        { 0xcec7d64fa9ce9556, 14, 103, Leaves },
        { 0xcf0403e08e2de283, 9, 169 },
        { 0xcf062a797b3f036a, 103, 163, Wood, 7 },
        { 0xcf06a535ade0ec8e, 17, 118, Brick },
        { 0xcf0a851d09a57df2, 56, 124, Metal, 7 },
        { 0xcf1fc1abef094340, 41, 99, Metal, 7 },
        { 0xcf26476397c300e3, 16, 99, Bumpy },
        { 0xcf399fe7f8321759, 39, 151, Metal, 7 },
        { 0xcf3cba69a25477e0, 60, 168, Cracks, 7 },
        { 0xcf44715486561836, 38, 247, Metal, 7 },
        { 0xcf6ef877cce4b28f, 0, 142 },
        { 0xcf8605db3e2066ac, 65, 169, Bumpy, 7 },
        { 0xcf8aefe2740a4e39, 10, 54, Metal, 7 },
        { 0xcfbc306c2368f7d9, 12, 125, Leaves },
        { 0xcfe9a1a43d4a739c, 16, 149, Dirt },
        { 0xcff5c8dfca3a46be, 41, 189, Cracks },
        { 0xcffd264d69b2c6b6, 12, 110, Metal, 7 },
        { 0xd0101a96cf0727a4, 43, 133, Bumpy, 7 },
        { 0xd010e5225964a8b6, 19, 127, Cracks },
        { 0xd0435f7f70422238, 49, 171, Metal, 7 },
        { 0xd069164a0e0edcc1, 9, 162, Metal, 7 },
        { 0xd090145f0f9faa9d, 24, 137, Dirt },
        { 0xd0a8efa897ce0482, 17, 157, Bumpy },
        { 0xd0cfada8f2ab3fcc, 12, 173, Bumpy },
        { 0xd0d1f872c65fa725, 45, 141, Tiles, 7 },
        { 0xd0df960785750436, 45, 124, Metal, 7 },
        { 0xd0e59fb0d2ab265a, 2, 166, Metal, 7 },
        { 0xd0f23a12f4a3c3c3, 21, 96, Wood, 7 },
        { 0xd101231317f80b0d, 7, 159 },
        { 0xd10c9d936bf311b7, 28, 139, Brick },
        { 0xd1102748c0f26955, 22, 57, Wood, 7 },
        { 0xd12712f04dcefd8f, 18, 85, Metal, 7 },
        { 0xd169a4e2a6dd713c, 21, 131, Leaves },
        { 0xd16d388540a6e872, 7, 139 },
        { 0xd18e4b32d49f3eb5, 84, 188, Metal, 7 },
        { 0xd199140436f5c422, 0, 135, Metal, 7 },
        { 0xd1d3e51b1a3194ae, 34, 218, Rounded },
        { 0xd1de29852140d206, 2, 238, Rounded },
        { 0xd1eb874b9d3ba7fb, 67, 206, Metal, 7 },
        { 0xd1ecdca19a7ff57f, 58, 174, Bumpy, 7 },
        { 0xd1f2100ed480a670, 14, 141, Bumpy },
        { 0xd2035b82ae4aa060, 0, 93, Metal, 7 },
        { 0xd20f10985adda329, 23, 158, Bumpy },
        { 0xd2122268fdcd8272, 33, 133, Brick },
        { 0xd21e587709d11a86, 0, 149 },
        { 0xd22937df68ab12c3, 35, 159, Metal, 7 },
        { 0xd2311c223921b695, 35, 125, Wood, 7 },
        { 0xd261c5dd6bc7ee9f, 24, 70, Dirt },
        { 0xd26b61541cca8f68, 7, 122 },
        { 0xd27c1e27812bfcd8, 17, 187, Bumpy },
        { 0xd27ce5a8c6a95df4, 19, 114, Dirt, 7 },
        { 0xd2844b760d347fa5, 107, 214, Rounded },
        { 0xd28c4a3bda75d471, 18, 119 },
        { 0xd2b52042f69a7949, 11, 104, Bark },
        { 0xd2e4769a23ed2ff7, 16, 211 },
        { 0xd30e716caf57fc0f, 51, 204, Dirt, 7 },
        { 0xd30ea3c4a64a252a, 9, 179, Cracks },
        { 0xd3259e3090c2d98c, 15, 148, Bumpy },
        { 0xd343efe79ef2103b, 31, 160, Bumpy },
        { 0xd36884bd1f2fb61a, 0, 173, Metal, 7 },
        { 0xd369f7a38d1e5251, 14, 150, Bark },
        { 0xd3721bafc0c2acd3, 18, 168 },
        { 0xd3e61b579c35618c, 40, 190, Ice, 0, false },
        { 0xd3f92553376a7758, 10, 83, Metal, 7 },
        { 0xd3fb04e8290eb89f, 46, 191, Bumpy, 7 },
        { 0xd4152d4dcb82a6d2, 18, 110, Metal, 7 },
        { 0xd43233920209a202, 20, 132 },
        { 0xd43a0e33a033d883, 0, 133, Metal },
        { 0xd47957fc32b8e1f6, 45, 201, Smooth },
        { 0xd47c56aae92d3f79, 15, 164, Tiles, 7 },
        { 0xd48dbc4653da6b34, 34, 154, Dirt },
        { 0xd4b675a352fed91e, 48, 194, Smooth },
        { 0xd4c5767aaf3208a4, 10, 204, Rounded },
        { 0xd4e0174ac0c39170, 10, 168, Wood },
        { 0xd4ffbadfdbce6b8a, 7, 48, Metal, 7 },
        { 0xd50f0236d1239f41, 21, 89, Bumpy, 7 },
        { 0xd5345be8fe2911bf, 31, 96, Brick },
        { 0xd539467535f6522b, 5, 102 },
        { 0xd5787e1378d43620, 22, 176, Ice, 0, false },
        { 0xd587003a561ef253, 15, 74, Metal, 7 },
        { 0xd589ca1322c51835, 0, 72, Bumpy },
        { 0xd589d0c97824902b, 56, 123, Bumpy, 7 },
        { 0xd5baa2dd6019f1c8, 10, 102, Rounded },
        { 0xd5d14096f1355ae1, 4, 110, Bumpy },
        { 0xd5d9a05f55923a54, 9, 148, Bumpy },
        { 0xd5e7a27e7b183bf6, 19, 118 },
        { 0xd5ebeb3bb12e1fa5, 28, 120, Metal, 7 },
        { 0xd600ac9fadf6f6c4, 7, 139, Bumpy },
        { 0xd626396239f5c508, 4, 169, Bumpy },
        { 0xd63268e6de5b178f, 26, 175, Metal, 7 },
        { 0xd650b1e47b18de22, 25, 170, Bumpy },
        { 0xd6647486b527f6fc, 13, 137, Tiles, 7 },
        { 0xd672d2cef93fae59, 21, 131, Bumpy },
        { 0xd68449933c1326bf, 11, 96, Wood, 7 },
        { 0xd689ae83c00efab4, 28, 99 },
        { 0xd68a65807e53e155, 24, 207, Metal, 7 },
        { 0xd68bbfb7ecd137d9, 15, 136, Bumpy, 7 },
        { 0xd68d4ca230647b99, 91, 127 },
        { 0xd69450c4c807c5a8, 24, 82 },
        { 0xd6956e00dc9f9731, 21, 143, Metal, 7 },
        { 0xd69de71b5d2d5f61, 20, 154, Bumpy },
        { 0xd6bc167d46933f49, 24, 169 },
        { 0xd6bfdf713028dad0, 17, 112, Bumpy },
        { 0xd6ec1368a75cff68, 69, 188, Bumpy },
        { 0xd7089f35f5f911c5, 0, 108 },
        { 0xd719b033ae602af7, 18, 201, Bumpy },
        { 0xd72663224125b11f, 54, 148, Bumpy, 7 },
        { 0xd72b8a7fd9b15e10, 122, 224 },
        { 0xd7333c0bce4b478a, 14, 181 },
        { 0xd7355ee81e98cd51, 7, 169, Metal, 7 },
        { 0xd73f1e47a889a996, 15, 156 },
        { 0xd746c3304d93396c, 18, 117, Metal, 7 },
        { 0xd75664135743fbb1, 7, 185, Bumpy },
        { 0xd75ae769b09ee13c, 15, 76, Brick },
        { 0xd770e79f0bcccc38, 35, 208, Bumpy },
        { 0xd7732a09cec280ea, 40, 126, Wood, 7 },
        { 0xd78d1ae2a28b7073, 54, 248, Smooth, 7 },
        { 0xd795d833deb26049, 23, 110, Brick },
        { 0xd7b3e24f50d0c169, 23, 109, Metal, 7 },
        { 0xd7d40a50f26eba58, 48, 178, Smooth },
        { 0xd7d77d76767aa545, 21, 105, Wood, 7 },
        { 0xd7df9f1ec940fe04, 29, 152, Smooth },
        { 0xd7e9dc24efca7fac, 27, 169, Dirt },
        { 0xd7fe8981528bcefe, 0, 220 },
        { 0xd8072f4b99c3a8ec, 53, 120, Bumpy, 7 },
        { 0xd8091973a4a28991, 74, 151, Dirt, 7 },
        { 0xd80ce2b92cf3ea66, 14, 149, Bumpy },
        { 0xd80f8578387ca2db, 7, 112, Bumpy },
        { 0xd81b1a432c4074ff, 14, 82, Cracks },
        { 0xd82509783b9bf001, 0, 152 },
        { 0xd827fdb3c6c588d1, 2, 113, Metal, 7 },
        { 0xd876b4c640f0218b, 15, 113, Leaves, 7 },
        { 0xd883e53f8ace8151, 45, 219, Metal, 7 },
        { 0xd88901e0ba47e0c9, 0, 143 },
        { 0xd8894b67af3cec4a, 0, 126, Metal, 7 },
        { 0xd8cea96805426bfd, 7, 189, Metal, 7 },
        { 0xd8d14d10608e2315, 114, 191, Bumpy, 7 },
        { 0xd8ddee7e0a0a0946, 12, 137, Tiles, 7 },
        { 0xd8e738e328c6efb3, 11, 148, Bumpy },
        { 0xd900c1e527f1271e, 5, 127 },
        { 0xd9180579b92032ce, 46, 140, Dirt, 7 },
        { 0xd927cc42396eb634, 25, 176, Smooth },
        { 0xd948c5c6713b551d, 74, 155, Bumpy, 7 },
        { 0xd968ef825b01ed2d, 35, 218, Wood, 7 },
        { 0xd973a4f18333c919, 31, 133, Brick },
        { 0xd97f457ae08a743a, 2, 145, Bumpy },
        { 0xd980d57325197745, 10, 158, Metal, 7 },
        { 0xd99c46088da26244, 40, 104, Brick },
        { 0xd9b4b5b15c5dcddf, 11, 88, Cracks },
        { 0xd9c7150b3ed211af, 15, 148, Metal, 7 },
        { 0xd9e5488644d7ec85, 42, 84, Dirt, 7 },
        { 0xda07a0e149ce44f6, 22, 94, Wood, 7 },
        { 0xda08af375a7c32c6, 17, 124, Bumpy },
        { 0xda109ac5dc3ae34b, 26, 151, Leaves },
        { 0xda542943b939f23f, 7, 152, Wood, 7 },
        { 0xda74192b4680e0c0, 10, 162, Bumpy },
        { 0xda7a0526f4013677, 51, 139, Metal, 7 },
        { 0xda7adf867f3c87c4, 21, 173, Dirt },
        { 0xda7f0fff7527d3e7, 40, 197, Metal, 7 },
        { 0xda86e8db9b2cb5b9, 15, 113 },
        { 0xda8b6db8d2294e25, 60, 165 },
        { 0xdaa8b13d87e13ff9, 26, 138, Leaves, 7 },
        { 0xdaaa97ff63a91b7b, 8, 120, Metal, 7 },
        { 0xdad5291953013077, 59, 218, Metal, 7 },
        { 0xdae03e7c34349a14, 24, 181, Bumpy },
        { 0xdb03b9355cd64974, 7, 141 },
        { 0xdb053495566a2d30, 0, 215 },
        { 0xdb0781a24e28da86, 63, 230, Leaves, 7 },
        { 0xdb14615e0fb4e281, 24, 178, Rounded },
        { 0xdb42cd9a31b66cfc, 7, 169, Metal, 7 },
        { 0xdb6bd24e8b0107e1, 0, 154 },
        { 0xdb9b430bf926ac1c, 9, 101, Leaves },
        { 0xdbbd7cb28a4886ba, 35, 215, Metal, 7 },
        { 0xdbdd9fa66b1af141, 15, 173, Metal, 7 },
        { 0xdbe3f20c0639f287, 0, 155 },
        { 0xdbf262379b26d3d0, 24, 124, Wood, 7 },
        { 0xdc11ff84b45f462f, 28, 140, Wood, 7 },
        { 0xdc5646085d68aeeb, 49, 173, Rounded },
        { 0xdcaca515c664f6a5, 70, 151, Rounded },
        { 0xdcc0f0a5ecbeb211, 10, 111 },
        { 0xdcc398f5affaadef, 31, 110, Metal, 7 },
        { 0xdcc723d599326bfb, 68, 209 },
        { 0xdcce3f81567a177d, 24, 132, Metal, 7 },
        { 0xdcdb624c545fefac, 15, 101, Leaves },
        { 0xdce1acf45276b786, 9, 166, Rounded },
        { 0xdce42ff103ee07a9, 0, 82 },
        { 0xdcef16bdf2fc10ff, 0, 233, Metal, 7 },
        { 0xdcf74c5d11b70f73, 119, 185, Smooth },
        { 0xdd0be660111ff675, 2, 148 },
        { 0xdd10cebe35f92d10, 104, 188, Sand, 7 },
        { 0xdd15a87eec783ade, 34, 115, Metal, 7 },
        { 0xdd2e07f2dff569f3, 21, 100, Bumpy },
        { 0xdd2f61f8691ff947, 34, 226, Metal, 7 },
        { 0xdd41040e70ed5c8e, 35, 116, Cracks },
        { 0xdd422eb1ce557535, 9, 129, Bumpy },
        { 0xdd73116daf40b90e, 26, 95, Brick },
        { 0xdd7ecdf83db839a0, 7, 113, Wood, 7 },
        { 0xdd899e3652968723, 44, 232, Cracks },
        { 0xdd94be70f8e7fe2a, 37, 159, Stone, 15 },
        { 0xdd96acc525117fe8, 0, 107 },
        { 0xdd9d4d9ad015b48e, 19, 185, Bumpy },
        { 0xddbe30be48fc0e0f, 66, 251, Metal, 7 },
        { 0xddcd958879777c51, 17, 145 },
        { 0xdde5e19b8c0b9ece, 25, 159, Metal, 7 },
        { 0xdde879987590af41, 21, 151, Smooth },
        { 0xddf434e3d92f546c, 58, 174, Bumpy, 7 },
        { 0xddfea90f41225b4e, 8, 102, Metal, 7 },
        { 0xde063c5c561595e4, 19, 136, Dirt },
        { 0xde0c320c67568e6b, 16, 123, Wood, 7 },
        { 0xde17c14b9e699979, 5, 167 },
        { 0xde2e2dbc083d9bae, 15, 217, Rounded },
        { 0xde316b635f35cf1f, 34, 128, Dirt },
        { 0xde42b3c409007b12, 15, 109, Wood, 7 },
        { 0xde57c09d4d6ca1c7, 0, 111 },
        { 0xde5b4c6b93cd5a74, 33, 144, Leaves, 7 },
        { 0xde65b3edf70fafbb, 0, 82 },
        { 0xde7dd744beec8a79, 0, 79 },
        { 0xde82ed1138f2ae02, 40, 180, Smooth },
        { 0xde85516120d88e47, 21, 115, Cracks },
        { 0xde8b74e35bdb8874, 0, 188 },
        { 0xde9d01ace39be760, 15, 127, Metal, 7 },
        { 0xdea93024c15621de, 0, 133, Rounded },
        { 0xdec03116d8f116d9, 0, 106 },
        { 0xdec9ba6767d599f3, 17, 77, Bumpy },
        { 0xdef206192a2db4be, 9, 65, Cracks },
        { 0xdef787cd79beb323, 23, 172, Metal, 7 },
        { 0xdefaaa0f5db4c2dd, 7, 187 },
        { 0xdeff667fb9330cee, 58, 229, Rounded },
        { 0xdf218df9aeb4fd03, 47, 222, Dirt, 7 },
        { 0xdf42b09b1a9664cd, 32, 207, Bumpy },
        { 0xdf49369b8f4087b9, 22, 105, Bumpy },
        { 0xdf4c02b3c17903c9, 35, 189, Grass, 7 },
        { 0xdf4c08bdaedf698b, 40, 163, Bark },
        { 0xdf4d5b5567352b3e, 44, 133, Metal, 7 },
        { 0xdf5c2c0101502a0f, 26, 114, Metal, 7 },
        { 0xdf6aca1216447036, 7, 148, Metal, 7 },
        { 0xdf6bda79e3b0bfdd, 25, 120, Metal, 7 },
        { 0xdf6cd828b4433d38, 88, 146 },
        { 0xdf84098d6176b343, 40, 167 },
        { 0xdfb2569b7d94830f, 34, 163, Metal, 7 },
        { 0xdfc86f88dec8b152, 40, 198, Metal, 7 },
        { 0xdfecf3a160724dd4, 7, 126 },
        { 0xe011d2cc374d5e37, 24, 142, Metal, 7 },
        { 0xe014c3012581bef5, 28, 182, Bumpy },
        { 0xe035f3e25d5be463, 0, 130 },
        { 0xe06888b2909a38c7, 31, 247, Brick },
        { 0xe07eed37e2e5a5e8, 20, 188, Rounded },
        { 0xe0b07525b3575e79, 121, 213 },
        { 0xe0bb5bfc116fa1c1, 9, 96, Bumpy },
        { 0xe0d5ce6913a1288b, 29, 247, Ice, 0, false },
        { 0xe0dc4c270cce29d1, 15, 156 },
        { 0xe0e598c1a7f6d99a, 75, 169, Cracks, 7 },
        { 0xe0ec464e3b78b4da, 20, 175, Brick },
        { 0xe0f90bbd9e937f63, 12, 171, Brick },
        { 0xe113238425323c08, 67, 185, Metal, 7 },
        { 0xe115a05ac2d10403, 7, 210, Bumpy },
        { 0xe11c75383d80e7b0, 7, 163, Wood, 7 },
        { 0xe140f211206bb23b, 18, 136 },
        { 0xe146a70f81a82614, 4, 154 },
        { 0xe149ee99d7a23135, 7, 144, Metal, 7 },
        { 0xe15ed130c91a440c, 15, 176, Rounded },
        { 0xe17928f79b9227df, 0, 208 },
        { 0xe17ff38daf7fe3e8, 43, 220, Dirt },
        { 0xe190fbc55f734001, 20, 111, Smooth },
        { 0xe19ee99a7eb8bda3, 10, 159, Rounded },
        { 0xe1a77418ed910c5a, 0, 147 },
        { 0xe1b83c897f6884ae, 7, 218, Terraced, 7 },
        { 0xe1c7488b178efec4, 35, 95, Dirt },
        { 0xe1c80ed78dc0d43d, 46, 99, Metal, 7 },
        { 0xe1dd9e0622cb3ecb, 61, 203, Bark },
        { 0xe1f2affa45506117, 35, 177, Bumpy },
        { 0xe200d6da3d44b9aa, 30, 161, Leaves },
        { 0xe21124b722ff6639, 15, 114, Metal, 7 },
        { 0xe25eb0a6c52fc5dc, 23, 197, Bumpy },
        { 0xe2835487053cec45, 15, 108, Stone, 7 },
        { 0xe290dfdb33e0f39c, 7, 133, Wood },
        { 0xe2de16f8cd83ad38, 4, 99, Bumpy },
        { 0xe2e6167bdf517013, 19, 171, Bumpy },
        { 0xe2e7a2cb8926f935, 42, 170, Metal, 7 },
        { 0xe2e9777b33c978f7, 21, 137, Metal, 7 },
        { 0xe31cd4bc8ee80871, 2, 87, Bumpy },
        { 0xe331cb64bac99206, 0, 217, Metal, 7 },
        { 0xe33bfcf426b3e6b5, 32, 172, Grass },
        { 0xe350d6b5bf35ca92, 24, 151, Dirt },
        { 0xe35adcc021d648c8, 18, 89, Metal, 7 },
        { 0xe376d62d8359a6e0, 56, 144, Metal, 7 },
        { 0xe377597033cac2ff, 18, 218 },
        { 0xe3890f274d878db4, 178, 229, Ice, 0, false },
        { 0xe3aa2d22e709a3ba, 0, 118, Rounded },
        { 0xe3aa7127fe0a8308, 32, 87 },
        { 0xe3bfd0c95386cb18, 18, 226, Metal, 7 },
        { 0xe3e6288922a471ff, 7, 146, Leaves },
        { 0xe3e8acb5a4edcb07, 37, 97, Dirt },
        { 0xe3fe605fff2a96c7, 0, 174, Stone, 7 },
        { 0xe41cbd0d51b39956, 0, 100, Rounded },
        { 0xe46fc93d707fa9a4, 68, 206, Metal, 7 },
        { 0xe47ba6c6dbf7eb6b, 7, 132, Wood },
        { 0xe480b92979efbb9c, 10, 140, Metal, 7 },
        { 0xe482d339f035a8cc, 27, 153, Wood, 7 },
        { 0xe48ee8c429ec649f, 34, 142, Tiles, 7 },
        { 0xe4b88123b10cc727, 33, 101 },
        { 0xe4d268df501d8181, 42, 160 },
        { 0xe4ded17b17fb4804, 5, 141, Metal, 7 },
        { 0xe4e83c396d6fd5c7, 0, 100, Bumpy },
        { 0xe4f39b114dd96059, 16, 82, Rounded },
        { 0xe50b58406bbd2bd3, 45, 203, Bumpy },
        { 0xe50bad609fb79f31, 16, 151 },
        { 0xe50e3d6fab056885, 60, 156, Rounded },
        { 0xe519545d74e46677, 52, 226, Brick },
        { 0xe5406c7b92c47689, 34, 125, Cracks, 7 },
        { 0xe56baa9bac52c5ce, 15, 129, Rounded },
        { 0xe57edef746fedb16, 56, 165, Metal, 7 },
        { 0xe5b111801b5d5677, 7, 143, Rounded },
        { 0xe5b2fee0871b45ed, 0, 151, Metal, 7 },
        { 0xe5c6213d56c82d81, 25, 88, Metal, 7 },
        { 0xe5ca8e7d1d5a5933, 7, 148, Metal, 7 },
        { 0xe5f489ce584fcce3, 37, 96, Bark, 15 },
        { 0xe5f6a767e81cbf2a, 42, 90, Brick },
        { 0xe5fa50c406c62f28, 18, 78 },
        { 0xe5fd84050af1238c, 24, 207, Bumpy },
        { 0xe60558d9ec64aefd, 10, 139, Bumpy },
        { 0xe610678d115ab976, 43, 97, Brick },
        { 0xe6144dde451feb08, 0, 129 },
        { 0xe6167ead08fe8b89, 5, 151 },
        { 0xe644d2a7b101f429, 25, 133, Bumpy },
        { 0xe657ee3e7f493161, 7, 145, Bumpy, 15 },
        { 0xe66829648048c429, 64, 123 },
        { 0xe670130008be48cf, 4, 123 },
        { 0xe68b7a59ccc098e7, 43, 119, Metal, 7 },
        { 0xe68fcbdbf2ed0001, 36, 114, Metal, 7 },
        { 0xe698da1553c3a1e1, 40, 192, Metal, 7 },
        { 0xe699d5387e8e4d7e, 63, 115, Metal, 7 },
        { 0xe6ad23687eda3749, 0, 124, Bumpy },
        { 0xe6bc242d2f0c3173, 20, 67, Wood, 7 },
        { 0xe6e0932b639252eb, 54, 155, Bumpy },
        { 0xe6ed503f3cf268ba, 12, 117, Leaves },
        { 0xe6fb1891235035ed, 23, 202, Bumpy },
        { 0xe71978d0d94fd284, 41, 143, Wood, 7 },
        { 0xe72cad5807901897, 7, 137 },
        { 0xe761cff8a6ec3581, 0, 192, Metal, 7 },
        { 0xe790492f77f78970, 12, 137, Brick },
        { 0xe791aaa556960f75, 14, 81, Bumpy },
        { 0xe7b1bb76d5424583, 31, 103, Metal, 7 },
        { 0xe7cd31b6e076703e, 14, 89, Cracks },
        { 0xe7cf20cc6b19a345, 35, 206, Cracks },
        { 0xe7e51d822ee1076a, 17, 193, Bumpy },
        { 0xe7eb91e57331e1c3, 18, 76 },
        { 0xe7f7a6ba11d5ef40, 10, 72, Wood, 7 },
        { 0xe802d6473c35a9b4, 49, 84 },
        { 0xe81290e10e3c5de1, 28, 160, Rounded },
        { 0xe816db6504966bb2, 21, 64, Metal, 7 },
        { 0xe819972428b545c4, 28, 127, Metal, 7 },
        { 0xe81fc6ac9b60facd, 15, 247, Metal, 7 },
        { 0xe86f8e0160a65eba, 18, 213, Brick },
        { 0xe87b874c22ef9692, 11, 63, Rounded },
        { 0xe87b89b83317a064, 0, 173, Wood },
        { 0xe883b149b244f122, 31, 192, Bumpy },
        { 0xe894ced83e18d4a3, 7, 162 },
        { 0xe899474037b0f4ef, 35, 139, Metal, 7 },
        { 0xe8c6dd994d51c6a7, 21, 141, Stone, 7 },
        { 0xe8e4680050c73d23, 113, 205, Sand, 7 },
        { 0xe91bafb112ee5234, 0, 125, Metal, 7 },
        { 0xe925783ee9330af2, 40, 157, Metal, 7 },
        { 0xe9338ce76bafa0d8, 50, 117, Metal, 7 },
        { 0xe94bf2c6e32f2cdf, 48, 137, Cracks, 7 },
        { 0xe94e47c49eecbad5, 0, 152 },
        { 0xe9613c7dbc78b866, 109, 212, Ice, 0, false },
        { 0xe962d8953cd027d4, 32, 114 },
        { 0xe96b52b23d8fbe09, 33, 117, Metal, 7 },
        { 0xe97be88a8664f198, 31, 118, Metal, 7 },
        { 0xe9cd1a60bbe53581, 14, 121, Bumpy },
        { 0xe9e4e937cb4c51db, 10, 118, Rounded },
        { 0xe9fd8817eaaca22e, 12, 160, Metal, 7 },
        { 0xea185efc9754e929, 34, 197, Rounded },
        { 0xea5ac88c59f20696, 0, 158, Bumpy },
        { 0xea775aebff1c03e7, 39, 171 },
        { 0xea93b9dbd71cf21f, 37, 164 },
        { 0xeab23a531bfaa6c0, 25, 105 },
        { 0xeae1817da4af7272, 12, 110, Brick },
        { 0xeaee8860c58e3a0a, 20, 84, Bumpy },
        { 0xeaf1c83513867ac9, 3, 49, Metal, 7 },
        { 0xeaf42fa6af063d6d, 31, 141, Metal, 7 },
        { 0xeb121aa89adf8395, 7, 181, Metal, 7 },
        { 0xeb20a24c56f33911, 17, 82, Metal, 7 },
        { 0xeb2725213831120e, 66, 178, Bumpy },
        { 0xeb2be3814c92704a, 81, 206, Metal, 7 },
        { 0xeb4ace8d4dbed42f, 0, 79, Wood, 7 },
        { 0xeb516956ee2749e3, 27, 147, Wood, 7 },
        { 0xeb52df347aeb8c5e, 27, 126, Wood, 7 },
        { 0xeb58a89a233350c5, 16, 46, Dirt },
        { 0xeb62585450498ef7, 2, 51, Metal, 7 },
        { 0xeb94cd4fa7a09a3a, 12, 55, Dirt },
        { 0xeb9505e7595b86bf, 39, 136 },
        { 0xeb9eb3d47f0f2414, 13, 73, Rounded },
        { 0xeb9f8645e293e8dc, 9, 109, Bark, 15 },
        { 0xeba809fec834f467, 81, 165, Sand, 7 },
        { 0xebaddf51de23af05, 25, 120, Metal, 7 },
        { 0xebbaa5e8e45e6365, 0, 78, Bumpy },
        { 0xebd157ada2510cb8, 25, 76, Bumpy },
        { 0xebe8a204537bcecf, 16, 141, Tiles, 7 },
        { 0xebeb96e662deb443, 26, 118, Wood, 7 },
        { 0xebee14f7ba40e49f, 26, 145 },
        { 0xec029110fb80cb68, 31, 197 },
        { 0xec444cbe95e90e41, 0, 176 },
        { 0xec4c9697bb762087, 47, 247 },
        { 0xec72c6c6dadee3f3, 29, 154, Bumpy },
        { 0xec882d9da3a405f9, 0, 145, Metal, 7 },
        { 0xec990b3ed1a64771, 0, 201 },
        { 0xeca4591a3dbd2fcc, 44, 162, Cracks },
        { 0xed007ae11f0b6d8e, 15, 158, Metal, 7 },
        { 0xed0510dff7682d8a, 0, 238 },
        { 0xed1a91c69ec8e309, 7, 148 },
        { 0xed427afe1d3dfa45, 25, 58, Bumpy, 7 },
        { 0xed57f0329b33fff0, 45, 90 },
        { 0xed990b453fb935b0, 29, 125 },
        { 0xed9f5126d8d2e24f, 0, 114, Metal, 7 },
        { 0xeda3c7618ead95c5, 9, 168, Rounded },
        { 0xedd50d1a56daa493, 67, 183, Ice, 0, false },
        { 0xede339dfda98f27d, 18, 123, Brick },
        { 0xee17ea138c267ee2, 23, 129 },
        { 0xee57aab90797e593, 0, 186 },
        { 0xee5e4357aba76c79, 43, 156 },
        { 0xee65b4360bc86c10, 23, 122 },
        { 0xee7d78f83b9734a7, 36, 151, Metal, 7 },
        { 0xee9a8c1667b6f0b1, 0, 51, Bumpy },
        { 0xeea25599713a49ac, 11, 74, Cracks },
        { 0xeea385c9af603ab5, 41, 84, Stone, 7 },
        { 0xeea8b5ed41ab6218, 14, 105 },
        { 0xeed8093f625587b2, 25, 131, Brick },
        { 0xeef03afb17bf6360, 19, 197, Ice, 0, false },
        { 0xeefb8cee5e0e7c5a, 9, 105 },
        { 0xef1637c6d57aa9c6, 0, 125, Smooth },
        { 0xef23a62c6a70f5f0, 18, 118, Stone, 7 },
        { 0xef29e8474b2ccf37, 17, 135, Wood, 7 },
        { 0xef2b9c7f53317a2f, 59, 140, Wood, 7 },
        { 0xef37e7804f15cd3a, 0, 234 },
        { 0xef48fb8743bfe621, 24, 79, Metal, 7 },
        { 0xefa2c7d3c016758f, 67, 202 },
        { 0xefb01141c8141afd, 28, 184, Rounded },
        { 0xefd03e2cb8e0266e, 17, 114, Metal, 7 },
        { 0xefdc76eb8a87b8b8, 50, 201 },
        { 0xefeb69fba0f2379f, 0, 151, Stone, 7 },
        { 0xf00cf99dd2cba95d, 21, 164, Stone, 7 },
        { 0xf013a89d0d9174c0, 58, 159, Metal, 7 },
        { 0xf024851e0c275f78, 10, 89, Bark, 15 },
        { 0xf0545865e49b668c, 33, 165 },
        { 0xf05c9f468f794ef3, 7, 121, Wood, 7 },
        { 0xf069e36e669d23b8, 26, 203, Metal, 7 },
        { 0xf08b03de3c48fc13, 19, 183 },
        { 0xf09461599ded885c, 97, 134, Sand, 7 },
        { 0xf0a682df64091853, 0, 114, Rounded },
        { 0xf0ae7217246e5a6d, 52, 177 },
        { 0xf0b4d73a56d5257a, 51, 95, Wood, 7 },
        { 0xf0df15db5fb33bb6, 0, 178, Bumpy },
        { 0xf0e443258eec2017, 10, 144, Wood, 7 },
        { 0xf10e30d97ceabd4f, 0, 171 },
        { 0xf11d28826deadd8a, 21, 136 },
        { 0xf11fed1def3950dc, 0, 102, Bumpy },
        { 0xf13b3cfd0e5fc100, 40, 190, Grass, 5 },
        { 0xf1434f38b2bc7204, 15, 140, Metal, 7 },
        { 0xf1483220619bb2b7, 7, 163 },
        { 0xf173be7d0b4b5078, 43, 131 },
        { 0xf1ccdb941fd27853, 7, 152, Wood, 7 },
        { 0xf1e3b34e936603b3, 48, 114, Metal, 7 },
        { 0xf1e81762c5a661c3, 48, 180, Bumpy },
        { 0xf1ee4b4fcedeb8de, 34, 198, Metal, 7 },
        { 0xf2069e31d6ef8c40, 0, 114, Metal, 7 },
        { 0xf24068eed1637a59, 2, 137, Wood, 7 },
        { 0xf253ef21aa4c9da1, 20, 198, Metal, 7 },
        { 0xf2a4c454ee9d8cba, 16, 180, Rounded },
        { 0xf2b985d6790d2a85, 15, 186 },
        { 0xf2bc48d9d4bf1f5d, 17, 146, Metal, 7 },
        { 0xf2cafac38e1bb95e, 7, 171 },
        { 0xf2e2dfc6a356b577, 89, 241, Bumpy },
        { 0xf2e46679811bc9d6, 0, 123, Wood, 7 },
        { 0xf2e65755511675be, 36, 179 },
        { 0xf2f2254b48fa73d5, 21, 119, Wood, 7 },
        { 0xf303f051f6394997, 21, 156, Metal, 7 },
        { 0xf3052c02362a7c6e, 75, 229, Rounded },
        { 0xf30ad0ecf1aa1d2d, 14, 175, Bumpy },
        { 0xf3519ebedb7c7a5e, 26, 160, Bumpy },
        { 0xf37ae6382c226d5c, 9, 131, Metal, 7 },
        { 0xf396d41209e60919, 7, 149, Bumpy },
        { 0xf3afb5c423775dcc, 2, 156, Wood, 7 },
        { 0xf3bf912c516f68d6, 26, 114, Metal, 7 },
        { 0xf3c965ae714ffaeb, 31, 246, Rounded },
        { 0xf3d5dbbcf85d0e81, 7, 164 },
        { 0xf3da48ebda0be0cd, 27, 130 },
        { 0xf3dd67ba9488a6d9, 35, 126, Wood, 7 },
        { 0xf432933f4b935817, 0, 122, Wood, 7 },
        { 0xf4495bdcfb773a98, 25, 168, Bumpy },
        { 0xf464357dd4151820, 7, 134, Bumpy },
        { 0xf46eb824b2404553, 20, 82, Brick },
        { 0xf479b1db6cc02089, 15, 186 },
        { 0xf48540e93369e579, 2, 114, Wood, 7 },
        { 0xf4b1cd3fdf14469b, 36, 96, Wood, 7 },
        { 0xf4b45b8e849b2d95, 14, 121, Bumpy },
        { 0xf4b9df9d9935eaaf, 57, 125, Brick },
        { 0xf4bdaf2b2b85ad2c, 22, 68 },
        { 0xf4c00ebd4a2ef0ef, 7, 123, Metal, 7 },
        { 0xf4d843370d3b3496, 17, 154, Cracks },
        { 0xf4e95249da120903, 23, 107, Bumpy },
        { 0xf4f04be02044bd0c, 40, 176 },
        { 0xf504473d89863409, 51, 123, Bumpy, 7 },
        { 0xf517a9c3c6e33483, 0, 150, Bark, 15 },
        { 0xf5230ed106df3514, 12, 86, Dirt },
        { 0xf554e4803655ad5f, 11, 90, Dirt },
        { 0xf55ee57f396ff7b5, 7, 81, Bumpy },
        { 0xf572bd5f393b6c00, 34, 97, Wood, 7 },
        { 0xf598a16d67ae77cb, 35, 141, Wood, 7 },
        { 0xf5b1d7f437524fa8, 54, 119, Metal, 7 },
        { 0xf5c1924488c6e990, 12, 159 },
        { 0xf5c5752547b2ba79, 9, 152 },
        { 0xf5cad94ad3066f90, 24, 173, Dirt },
        { 0xf5f41410c0c1086f, 25, 116, Stone, 7 },
        { 0xf5f80810264f62ff, 51, 123, Wood, 7 },
        { 0xf61b800146839354, 18, 125, Brick },
        { 0xf61f5951776b90de, 169, 217, Sand, 7 },
        { 0xf65b830b42495bf9, 7, 231, Rounded },
        { 0xf6654fce88c8f7ce, 15, 148, Bumpy },
        { 0xf6ae503aae3e8c47, 81, 206 },
        { 0xf6af282bc263cb32, 11, 101, Bumpy },
        { 0xf6f29651029a0846, 15, 143, Brick },
        { 0xf7132370f3524d75, 25, 93, Metal, 7 },
        { 0xf72c14f88e4786f8, 24, 186 },
        { 0xf72d73608b5a452f, 17, 102, Bumpy },
        { 0xf72e117e7f4b84f7, 84, 165 },
        { 0xf749b3a1269adf75, 0, 169, Metal, 7 },
        { 0xf753f5fde1334391, 12, 77, Bumpy },
        { 0xf75c17ce8afa4956, 24, 182, Bumpy },
        { 0xf768e0003567ae5c, 41, 140, Metal, 7 },
        { 0xf77e160e2a5b3a60, 129, 207, Sand, 7 },
        { 0xf780e70328751036, 31, 151, Smooth },
        { 0xf7842ba08ee5dedc, 43, 149, Bumpy },
        { 0xf7adb13364ecc872, 48, 188, Metal, 7 },
        { 0xf7b0b1a468e5a05b, 37, 135 },
        { 0xf7c44663cb23b942, 15, 198, Rounded },
        { 0xf7c7f3a480f5e3f2, 7, 105 },
        { 0xf80085d9ebad470c, 19, 170, Metal, 7 },
        { 0xf805d356c9a6c2d0, 7, 120, Wood, 7 },
        { 0xf80f17aa9d7a4418, 0, 153, Bumpy },
        { 0xf82a9abb52fbe514, 36, 142, Metal, 7 },
        { 0xf82dbef53593098f, 2, 216, Rounded },
        { 0xf82e16ea60825659, 95, 206, Smooth },
        { 0xf83ab0af7276468d, 76, 235, Rounded },
        { 0xf869d396a3093ef0, 41, 189, Metal, 7 },
        { 0xf870a28019a1d618, 0, 99, Metal, 7 },
        { 0xf88fd02ef6bd4f15, 32, 125, Bumpy },
        { 0xf8b428cc94d11bad, 35, 184, Wood, 7 },
        { 0xf8c1aa1fa125a8ca, 10, 247, Rounded },
        { 0xf8cdb968b4027b9e, 35, 201, Rounded },
        { 0xf8e9db46a8e40ed5, 27, 142, Smooth },
        { 0xf8f117fa679b322b, 0, 173 },
        { 0xf8f9bc2833c53a5e, 31, 217, Metal, 7 },
        { 0xf9092aee4b5a144d, 45, 176, Smooth },
        { 0xf90df084850b22b7, 30, 77 },
        { 0xf90f2f832e292206, 47, 168, Smooth },
        { 0xf9140cd61642a49e, 0, 116, Rounded },
        { 0xf915003e0a22d033, 15, 175, Rounded },
        { 0xf918aaa71f53d965, 42, 156 },
        { 0xf930837c8fe2a7b3, 33, 87, Dirt },
        { 0xf930bc0624eab7b8, 15, 169, Bumpy },
        { 0xf93bc060ba0d762f, 58, 141, Metal, 7 },
        { 0xf940a34f148c43e9, 7, 132 },
        { 0xf9451942ba08cae9, 0, 125 },
        { 0xf96e3a4f018c9d3f, 16, 132 },
        { 0xf9712c53810329f1, 0, 76, Metal, 7 },
        { 0xf9775f79edc13f8b, 10, 141, Bumpy },
        { 0xf97b2b9993f6d07c, 8, 110 },
        { 0xf9834c8706c7f1f9, 15, 89, Wood, 7 },
        { 0xf985d8d09e1d0d3c, 29, 158, Bumpy },
        { 0xf992138142cecdad, 56, 177, Terraced },
        { 0xf9939193e295e767, 32, 206, Cracks },
        { 0xf9a310069f98add4, 29, 211, Smooth },
        { 0xf9c4e0657cce4249, 37, 131, Metal, 7 },
        { 0xf9d3f21d9381a0dd, 18, 82 },
        { 0xfa049c2be42034c4, 7, 118, Metal, 7 },
        { 0xfa1e8dc772db8e02, 35, 176, Metal, 7 },
        { 0xfa2aacd51251f6d6, 15, 176, Rounded },
        { 0xfa32efc1403b509b, 18, 48, Metal, 7 },
        { 0xfa4a2f7269d43d25, 18, 73, Metal, 7 },
        { 0xfa5411db919a9ab7, 23, 175, Wood, 7 },
        { 0xfa7001eb61afa815, 16, 98, Wood, 7 },
        { 0xfa738c6d7a2905c7, 20, 97, Wood, 7 },
        { 0xfa792372324a6eb8, 9, 122 },
        { 0xfa7998071a44c498, 30, 187 },
        { 0xfa7a6375c54eb362, 73, 209, Metal, 7 },
        { 0xfa8c586577f8875c, 7, 95, Stone, 7 },
        { 0xfa8e693da813405a, 0, 134, Stone, 7 },
        { 0xfaa0b3db9b4c630d, 24, 157 },
        { 0xfaab8609d135bfb1, 8, 108, Bumpy },
        { 0xfabf88cefb81a333, 35, 140, Wood, 7 },
        { 0xfac04f9c7ee13e16, 26, 207, Metal, 7 },
        { 0xfaed81783d54ecae, 7, 90, Cracks },
        { 0xfaf8783f6fdee2cb, 20, 113, Brick },
        { 0xfb0e05c7a4be6675, 16, 70, Bumpy, 7 },
        { 0xfb206d40ffc09586, 7, 155 },
        { 0xfb215318e212987e, 31, 140, Brick },
        { 0xfb6b21227ba29a7c, 92, 177 },
        { 0xfb7bd58e16034e15, 0, 178 },
        { 0xfb822a2a95b52ab3, 10, 156 },
        { 0xfb9713b28e3feb2a, 7, 159, Wood, 7 },
        { 0xfba118097bf3e13f, 34, 115, Metal, 7 },
        { 0xfbb3aa8beb7e4199, 15, 124, Metal, 7 },
        { 0xfbc2dfb4ac5488e3, 37, 150, Metal, 7 },
        { 0xfbc2eb5013fbb2bb, 0, 109, Metal, 7 },
        { 0xfbdf0c3fc9562611, 42, 126, Brick },
        { 0xfbf419640b398822, 0, 161, Metal, 7 },
        { 0xfc113562142a1e77, 0, 84 },
        { 0xfc2a94befcacd6d7, 13, 74, Bumpy },
        { 0xfc3307662a1fe23b, 7, 70, Wood, 7 },
        { 0xfc4dc4c800ae0c7a, 77, 150, Wood, 3 },
        { 0xfc57075b40c809cb, 22, 160, Ice, 0, false },
        { 0xfc66a03814c8a735, 52, 158, Bumpy },
        { 0xfc6747679066341a, 7, 118, Bumpy },
        { 0xfc6be9330a92cb2c, 7, 208, Metal, 7 },
        { 0xfc9098f4eca876e1, 36, 113, Wood, 7 },
        { 0xfc9d729fc614152b, 18, 178, Cracks },
        { 0xfca13e55cc6b0d12, 61, 168, Bumpy },
        { 0xfca2c1f5f87b7874, 99, 247, Metal, 7 },
        { 0xfce81175251cf3cd, 10, 122, Metal, 7 },
        { 0xfcfeb83a6f9fb73c, 43, 109, Bumpy },
        { 0xfcff397e5890b8a3, 51, 135, Metal, 7 },
        { 0xfd07083c7e4d6cad, 26, 144, Bark, 15 },
        { 0xfd1a7ff24377ea2e, 0, 149, Metal, 7 },
        { 0xfd4a1a28c5c31509, 7, 100, Metal, 7 },
        { 0xfd56ae8dc8c57a6b, 40, 176, Metal, 7 },
        { 0xfd9b9d2facc15775, 75, 247, Ice, 0, false },
        { 0xfd9c7ac571d17add, 5, 75 },
        { 0xfdc5ecae4f2dcb6a, 7, 109, Wood, 7 },
        { 0xfdcd0591736854c2, 36, 159, Metal, 7 },
        { 0xfdd393e588c8d112, 15, 200, Metal, 7 },
        { 0xfdd495c179e17300, 33, 89 },
        { 0xfddceeadbeda595a, 7, 134, Rounded },
        { 0xfde40244f0a7c13c, 41, 173, Bumpy, 7 },
        { 0xfde5104a8166eb04, 20, 140, Wood, 7 },
        { 0xfe19291f3c9a767d, 21, 103, Dirt },
        { 0xfe3e2f09fc2ba6dc, 70, 181, Dirt },
        { 0xfeb22c418b8eefe5, 108, 148, Sand, 7 },
        { 0xfebc742ba565f08a, 10, 142 },
        { 0xfec69c47e50c6f70, 18, 156, Bumpy },
        { 0xfee9563680a176bd, 11, 214, Smooth },
        { 0xfef5c06c42fcce74, 56, 132 },
        { 0xfefb4ff3bf481b76, 27, 161, Bumpy },
        { 0xff044bbcc8c1703a, 9, 95, Bumpy },
        { 0xff0c10896d38c41a, 44, 144, Wood, 7 },
        { 0xff2080a5111218ea, 45, 165, Bumpy },
        { 0xff2cbfe2bcff836e, 0, 94 },
        { 0xff307a9be38271c5, 19, 113, Bumpy },
        { 0xff63e13746309d15, 0, 95, Rounded },
        { 0xff80e90f855fc529, 21, 108, Brick },
        { 0xff82f245f7716316, 65, 163, Bumpy },
        { 0xff8d6ab61e61bbc1, 111, 169 },
        { 0xff90c462ed8f4e70, 20, 189, Bumpy },
        { 0xff9e1b9c172db321, 18, 200, Bumpy },
        { 0xffa181ae3dd430a0, 31, 147, Metal, 7 },
        { 0xffae0c4bc924ee8c, 18, 111, Metal, 7 },
        { 0xffb4aad3f5340097, 16, 127, Bumpy },
        { 0xffb679b10a9311b5, 23, 102, Metal, 7 },
        { 0xffd6a13883063ef1, 28, 137, Brick },
        { 0xffd9d3b61eaec92d, 105, 155, Smooth },
        { 0xfff36d5a5023683c, 7, 144, Bumpy },
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
    // Graphics > Ray tracing is on / the no-hardware notice was shown for it (tick shows it once the renderer has
    // looked at the device, which is after the first apply).
    std::atomic<bool> ray_tracing_on{ false };
    std::atomic<bool> ray_tracing_notified{ false };

    // Every effect a preset sets, with its value for Original (everything off).
    struct PresetValue {
        const std::string* id;
        recomp::config::ConfigValueVariant off;
    };
    const PresetValue preset_values[] = {
        { &tooie::smaa::option, (uint32_t)tooie::smaa::Quality::Off },
        { &tooie::fxaa::option, (uint32_t)tooie::fxaa::Mode::Off },
        { &tooie::fsr::option, (uint32_t)tooie::fsr::Mode::Off },
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
        { &tooie::picture_filters::toon_world_option, 0.0 },
        { &tooie::picture_filters::toon_characters_option, 0.0 },
        { &tooie::picture_filters::underwater_tint_option, 0.0 },
        { &tooie::picture_filters::underwater_haze_option, 0.0 },
        { &tooie::picture_filters::heat_haze_option, 0.0 },
        { &tooie::picture_filters::underwater_distortion_option, 0.0 },
        { &tooie::picture_filters::water_reflections_option, 0.0 },
        { &tooie::picture_filters::ice_reflections_option, 0.0 },
        { &tooie::picture_filters::bounce_light_option, 0.0 },
        { &tooie::picture_filters::ssgi_option, 0.0 },
        { &tooie::picture_filters::ssr_option, 0.0 },
        { &tooie::picture_filters::ssr_stochastic_option, 0.0 },
        { &tooie::picture_filters::water_waves_option, 0.0 },
        { &tooie::picture_filters::light_shafts_option, 0.0 },
        { &tooie::picture_filters::sun_shadows_option, 0.0 },
        { &tooie::picture_filters::grass_option, 0.0 },
        { &tooie::picture_filters::deep_snow_option, false },
        { &tooie::picture_filters::tessellated_sand_option, false },
        { &tooie::picture_filters::parallax_option, 0.0 },
        { &tooie::picture_filters::ground_displacement_option, 0.0 },
        { &tooie::picture_filters::ground_displacement_distance_option, 8000.0 },
        { &tooie::picture_filters::parallax_original_option, true },
        { &tooie::picture_filters::banjo_fur_option, 0.0 },
        { &tooie::picture_filters::kazooie_feathers_option, 0.0 },
        { &tooie::picture_filters::npc_fur_option, 0.0 },
        { &tooie::picture_filters::npc_feathers_option, 0.0 },
        { &tooie::picture_filters::water_option, (uint32_t)tooie::picture_filters::Water::Original },
        { &tooie::picture_filters::shore_foam_option, false },
        { &tooie::picture_filters::mist_option, 0.0 },
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
            graphics.update_option_value(ice_reflections_option, 60.0);
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

    // The Effect Cost Check key's effect turned off for now (set_cost_override), read in place of its setting.
    std::mutex cost_mutex;
    std::atomic<bool> cost_override_on{ false };
    const std::string* cost_override_id = nullptr;
    recomp::config::ConfigValueVariant cost_override_value;

    template <typename T>
    T value(const std::string& id, T fallback) {
        try {
            if (cost_override_on.load(std::memory_order_relaxed)) {
                std::lock_guard lock{ cost_mutex };
                if ((cost_override_id != nullptr) && (*cost_override_id == id)) {
                    return std::get<T>(cost_override_value);
                }
            }
            return std::get<T>(graphics_config().get_option_value(id));
        } catch (...) {
            return fallback;
        }
    }

    // The grass, grass edge, ice and snow-off lists sent to RT64: the built-in ones (grass_textures[],
    // grass_edge_textures[], ice_textures[]) with Shader Effects pick mode's picks over them. A pick without
    // Deep Snow among its effects also keeps deep snow off that texture; Deep Snow picks are only kept in the file for now, as deep
    // snow goes by map and colour, not texture.
    std::atomic<uint32_t> effects_sent_version{0};
    // Parallax picks count too: a texture picked as Metal there is shiny (L, 2026-10-21).
    uint32_t effect_textures_version() {
        return tooie::effect_pick::version() + tooie::parallax_pick::version() * 65599u + tooie::material_pick::version() * 4099u;
    }
    void send_effect_textures() {
        static const std::vector<uint64_t> ice_extra = [] {
            std::vector<uint64_t> list;
            if (const char* extra = std::getenv("TOOIE_ICE_TEXTURES")) {
                for (const char* p = extra; *p != '\0';) {
                    char* end = nullptr;
                    const unsigned long long h = std::strtoull(p, &end, 16);
                    if (end == p) {
                        break;
                    }
                    list.push_back((uint64_t)h);
                    p = (*end == ',') ? end + 1 : end;
                }
            }
            return list;
        }();
        const uint32_t version = effect_textures_version();
        std::unordered_map<uint64_t, tooie::effect_pick::Effects> picks;
        tooie::effect_pick::for_each([&](uint64_t hash, tooie::effect_pick::Effects effects) {
            picks[hash] = effects;
        });
        // The shipped picks, where the player has none of their own.
        for (const ShippedPick& shipped : shipped_effect_picks) {
            picks.emplace(shipped.hash, shipped.effects);
        }
        // Built-in entries a pick does not take that effect off, then the picks with that effect (a pick can have several).
        auto build = [&](const uint64_t* begin, const uint64_t* end, tooie::effect_pick::Effect effect, bool add_picks) {
            std::vector<uint64_t> list;
            for (const uint64_t* h = begin; h != end; h++) {
                const auto pick = picks.find(*h);
                if ((pick == picks.end()) || tooie::effect_pick::has(pick->second, effect)) {
                    list.push_back(*h);
                }
            }
            if (add_picks) {
                for (const auto& [hash, picked] : picks) {
                    if (tooie::effect_pick::has(picked, effect) && (std::find(list.begin(), list.end(), hash) == list.end())) {
                        list.push_back(hash);
                    }
                }
            }
            return list;
        };
        std::vector<uint64_t> grass = build(std::begin(grass_textures), std::end(grass_textures), tooie::effect_pick::effect_grass, true);
        std::vector<uint64_t> edges = build(std::begin(grass_edge_textures), std::end(grass_edge_textures), tooie::effect_pick::effect_grass, false);
        std::vector<uint64_t> ice_all(std::begin(ice_textures), std::end(ice_textures));
        ice_all.insert(ice_all.end(), ice_extra.begin(), ice_extra.end());
        std::vector<uint64_t> ice = build(ice_all.data(), ice_all.data() + ice_all.size(), tooie::effect_pick::effect_ice, true);
        // Shiny surfaces for Screen-space reflections: shiny_textures and the textures the parallax sweep
        // (textures/sweep4) found to be metal, with Shiny Reflection picks over them.
        std::vector<uint64_t> shiny_all(std::begin(shiny_textures), std::end(shiny_textures));
        for (const ParallaxTexture& texture : parallax_textures) {
            if (texture.shape == Metal) {
                shiny_all.push_back(texture.hash);
            }
        }
        tooie::parallax_pick::for_each([&](uint64_t hash, const tooie::parallax_pick::Pick& pick) {
            if (!pick.off && (pick.shape == tooie::parallax_pick::shape_metal)) {
                shiny_all.push_back(hash);
            }
        });
        shiny_all.erase(std::remove_if(shiny_all.begin(), shiny_all.end(), [&](uint64_t h) { return std::find(ice_all.begin(), ice_all.end(), h) != ice_all.end(); }), shiny_all.end());
        std::vector<uint64_t> shiny = build(shiny_all.data(), shiny_all.data() + shiny_all.size(), tooie::effect_pick::effect_shiny, true);
        std::vector<uint64_t> snow_off;
        for (const auto& [hash, picked] : picks) {
            if (!tooie::effect_pick::has(picked, tooie::effect_pick::effect_deep_snow)) {
                snow_off.push_back(hash);
            }
        }
        // An edge entry picked as Grass is grass all over: the grass list wins.
        edges.erase(std::remove_if(edges.begin(), edges.end(), [&](uint64_t h) { return picks.count(h) != 0; }), edges.end());
        // RT64 reads an empty grass list as every texture, so a list emptied by Disable picks keeps one entry no draw has.
        if (grass.empty()) {
            grass.push_back(0);
        }
        RT64::SetSceneGrassTextures(grass.data(), grass.size());
        RT64::SetSceneIceTextures(ice.data(), ice.size());
        // Ice that reflects in any map: ice_anywhere_textures and the Ice picks.
        std::vector<uint64_t> ice_anywhere = build(std::begin(ice_anywhere_textures), std::end(ice_anywhere_textures), tooie::effect_pick::effect_ice, true);
        RT64::SetSceneIceAnywhereTextures(ice_anywhere.data(), ice_anywhere.size());
        RT64::SetSceneShinyTextures(shiny.data(), shiny.size());
        // Mirror Mode: textures picked as Text are flipped back on the mirrored world.
        std::vector<uint64_t> mirror_text = build(nullptr, nullptr, tooie::effect_pick::effect_text, true);
        RT64::SetMirrorTextTextures(mirror_text.data(), mirror_text.size());
        std::vector<uint64_t> lamps = build(std::begin(lamp_textures), std::end(lamp_textures), tooie::effect_pick::effect_lamp, true);
        RT64::SetSceneLampTextures(lamps.data(), lamps.size());
        RT64::SetSceneGrassEdgeTextures(edges.data(), value<bool>(tooie::picture_filters::grass_edges_option, true) ? edges.size() : 0);
        RT64::SetSceneSnowOffTextures(snow_off.data(), snow_off.size());
        std::vector<uint64_t> glow = build(nullptr, nullptr, tooie::effect_pick::effect_glow, true);
        RT64::SetSceneGlowTextures(glow.data(), glow.size());
        // Light Source picks: lamps with no glow in the air, reaching 900 units at 100% (as a lamp), more or less with
        // the texture's strength.
        std::vector<uint64_t> light_sources;
        std::vector<float> light_reaches;
        for (const auto& [hash, picked] : picks) {
            if (tooie::effect_pick::has(picked, tooie::effect_pick::effect_light)) {
                light_sources.push_back(hash);
                light_reaches.push_back(9.0f * float(tooie::effect_pick::light_strength(picked)));
            }
        }
        // Ray Tracing Material Pick Mode: the materials (the built-in ones from the texture sweep, a pick over each) go to the traced pass, and an emissive pick also lights the scene as a Light
        // Source would (half the emissive's percent as its strength), unless Shader Effects pick mode has given the texture
        // a Light Source of its own.
        {
            std::vector<uint64_t> material_hashes;
            std::vector<uint32_t> albedo_roughness;
            std::vector<uint32_t> metalness_emissive;
            tooie::material_pick::for_each_effective([&](uint64_t hash, const tooie::material_pick::Material& material, bool own) {
                material_hashes.push_back(hash);
                albedo_roughness.push_back(uint32_t(material.red) | (uint32_t(material.green) << 8) | (uint32_t(material.blue) << 16) | (uint32_t(material.roughness) << 24));
                metalness_emissive.push_back(uint32_t(material.metalness) | (uint32_t(material.emissive) << 8) | (uint32_t(material.subsurface) << 24));
                const auto own_light = picks.find(hash);
                // (Only a player's own pick lights the scene: the built-in glowing textures would use up the lights.)
                if (own && (material.emissive > 0) && ((own_light == picks.end()) || !tooie::effect_pick::has(own_light->second, tooie::effect_pick::effect_light))) {
                    light_sources.push_back(hash);
                    light_reaches.push_back(9.0f * std::max(10.0f, float(material.emissive) * 0.5f));
                }
            });
            RT64::SetSceneRayMaterials(material_hashes.data(), albedo_roughness.data(), metalness_emissive.data(), material_hashes.size());
        }
        RT64::SetSceneLightSourceTextures(light_sources.data(), light_reaches.data(), light_sources.size());
        std::vector<uint64_t> ray_off = build(nullptr, nullptr, tooie::effect_pick::effect_rt_off, true);
        RT64::SetSceneRayOffTextures(ray_off.data(), ray_off.size());
        // The same lists for the pick mode's Show All (edges count as grass; ice in the icy maps or anywhere).
        {
            using tooie::effect_pick::set_list;
            std::vector<uint64_t> grass_all = grass;
            grass_all.insert(grass_all.end(), edges.begin(), edges.end());
            set_list(tooie::effect_pick::effect_grass, grass_all);
            std::vector<uint64_t> ice_any = ice;
            ice_any.insert(ice_any.end(), ice_anywhere.begin(), ice_anywhere.end());
            set_list(tooie::effect_pick::effect_ice, ice_any);
            set_list(tooie::effect_pick::effect_shiny, shiny);
            set_list(tooie::effect_pick::effect_text, mirror_text);
            set_list(tooie::effect_pick::effect_lamp, lamps);
            set_list(tooie::effect_pick::effect_glow, glow);
            set_list(tooie::effect_pick::effect_light, light_sources);
            set_list(tooie::effect_pick::effect_rt_off, ray_off);
            set_list(tooie::effect_pick::effect_disable, build(nullptr, nullptr, tooie::effect_pick::effect_disable, true));
            set_list(tooie::effect_pick::effect_deep_snow, build(nullptr, nullptr, tooie::effect_pick::effect_deep_snow, true));
        }
        effects_sent_version.store(version);
    }

    // The parallax list sent to RT64: the built-in one (parallax_textures[]), with pick mode's picks over it.
    std::atomic<uint32_t> parallax_sent_version{0};
    void send_parallax_textures() {
        // TOOIE_PARALLAX_SKIP=<hex hash>,... leaves those out (headless, to tell which listed texture is which).
        static const std::vector<uint64_t> skip = [] {
            std::vector<uint64_t> hashes;
            if (const char* text = std::getenv("TOOIE_PARALLAX_SKIP")) {
                for (const char* p = text; *p != '\0';) {
                    char* end = nullptr;
                    hashes.push_back(std::strtoull(p, &end, 16));
                    p = (*end == ',') ? end + 1 : end;
                    if (end == p) {
                        break;
                    }
                }
            }
            return hashes;
        }();
        const uint32_t version = tooie::parallax_pick::version();
        std::unordered_map<uint64_t, tooie::parallax_pick::Pick> picks;
        tooie::parallax_pick::for_each([&](uint64_t hash, const tooie::parallax_pick::Pick& pick) {
            picks[hash] = pick;
        });
        std::vector<uint64_t> hashes;
        std::vector<uint8_t> ranges;
        std::vector<uint8_t> styles;
        hashes.reserve(std::size(parallax_textures) + picks.size());
        std::vector<uint8_t> fines;
        // (The sand ones are where Tessellated sand lies.)
        std::vector<uint64_t> sand;
        auto add = [&](uint64_t hash, uint8_t darkest, uint8_t lightest, uint8_t shape, uint8_t fine, bool shadows) {
            const auto pick = picks.find(hash);
            uint8_t final_shape = shape;
            if (pick != picks.end()) {
                const bool off = pick->second.off;
                const uint8_t style = pick->second.style();
                const uint8_t fine = pick->second.fine_depth();
                final_shape = pick->second.shape;
                picks.erase(pick);
                if (off) {
                    return;
                }
                styles.push_back(style);
                fines.push_back(fine);
            } else {
                tooie::parallax_pick::Pick built_in;
                built_in.shape = shape;
                built_in.shadows = shadows;
                styles.push_back(built_in.style());
                fines.push_back(fine);
            }
            hashes.push_back(hash);
            ranges.push_back(darkest);
            ranges.push_back(lightest);
            if (final_shape == tooie::parallax_pick::shape_sand) {
                sand.push_back(hash);
            }
        };
        for (const ParallaxTexture& texture : parallax_textures) {
            if (std::find(skip.begin(), skip.end(), texture.hash) == skip.end()) {
                add(texture.hash, texture.darkest, texture.lightest, texture.shape, texture.fine, texture.shadows);
            }
        }
        // Textures picked that the built-in list leaves out, with a middling range.
        for (const auto& [hash, pick] : std::unordered_map<uint64_t, tooie::parallax_pick::Pick>(picks)) {
            add(hash, 40, 190, tooie::parallax_pick::shape_stone, 0, true);
        }
        RT64::SetSceneParallaxTextures(hashes.data(), ranges.data(), hashes.size(), styles.data(), fines.data());
        RT64::SetSceneSandTextures(sand.data(), sand.size());
        parallax_sent_version = version;
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

    // Graphics > Shaders off (L, 2026-10-16): the effects of its section are off, their settings kept.
    const bool shaders = value<bool>(lighting_section_option, true);
    auto shader = [shaders](double v) { return shaders ? v : 0.0; };

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
    underwater_tint = (float)(shader(value<double>(underwater_tint_option, 25.0)) / 100.0);
    underwater_haze = (float)(shader(value<double>(underwater_haze_option, 15.0)) / 100.0);
    underwater_sent = -1.0f;
    heat_haze = (float)(value<double>(heat_haze_option, 0.0) / 100.0);
    heat_haze_sent = -1.0f;
    underwater_distortion = (float)(shader(value<double>(underwater_distortion_option, 30.0)) / 100.0);
    // The next frame sets it again for the scene playing then.
    dof_sent = -1;
    RT64::SetSharpening(debug_value(Solo::Sharpening, (float)(value<double>(sharpen_option, 0.0) / 100.0), 0.0f, 0.5f));
    ambient_occlusion = (float)(shader(value<double>(ambient_occlusion_option, 0.0)) / 100.0);
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
    RT64::SetSceneOutlines((float)(shader(value<double>(outlines_option, 0.0)) / 100.0), (float)(thickness / 25.0));
    const uint32_t upscale = debug_value(Solo::TextureUpscale, value<uint32_t>(texture_upscale_option, (uint32_t)TextureUpscale::Off), (uint32_t)TextureUpscale::Off, (uint32_t)TextureUpscale::Double);
    RT64::SetTextureUpscale(upscale == (uint32_t)TextureUpscale::Quadruple ? 4 : (upscale == (uint32_t)TextureUpscale::Double ? 2 : 1));
    RT64::SetSceneBounceLight((float)(shader(value<double>(bounce_light_option, 0.0)) / 100.0));
    RT64::SetSceneScreenSpaceGI((float)(shader(value<double>(ssgi_option, 0.0)) / 100.0));
    // Graphics > Ray tracing (L, 2026-10-20): its own switch, not one of the shader effects. Reflections are the
    // first effect it drives. On a device without ray tracing (RT64::GetRayTracingSupport 1) the option does
    // nothing but tell you once; the screen-space and water reflections carry on as set.
    const bool ray_tracing = value<bool>(ray_tracing_option, false);
    RT64::SetSceneRayTracing(ray_tracing);
    RT64::SetSceneRayTracingStrength((float)(value<double>(ray_tracing_strength_option, 60.0) / 100.0));
    RT64::SetSceneRayTracingReflections((float)(value<double>(ray_tracing_reflections_option, 60.0) / 100.0),
        (float)(value<double>(ray_tracing_water_reflections_option, 60.0) / 100.0), (float)(value<double>(ray_tracing_metal_option, 100.0) / 100.0),
        (float)(value<double>(ray_tracing_tiles_option, 60.0) / 100.0), (float)(value<double>(ray_tracing_smooth_option, 35.0) / 100.0));
    RT64::SetSceneRayTracingHitColours(value<bool>(ray_tracing_hit_colours_option, false));
    RT64::SetSceneRayTracingPlayerShadows(value<bool>(ray_tracing_player_shadows_option, true));
    RT64::SetSceneRayTracingSmoothing((float)(value<double>(ray_tracing_smoothing_option, 50.0) / 100.0));
    // Ray traced BRDF takes over the glossy reflections: with it on, the screen-space Stochastic reflections are off.
    const float traced_brdf = ray_tracing ? (float)(value<double>(ray_tracing_brdf_option, 0.0) / 100.0) : 0.0f;
    RT64::SetSceneRayTracingBrdfSubsurface(traced_brdf, ray_tracing ? (float)(value<double>(ray_tracing_subsurface_option, 0.0) / 100.0) : 0.0f);
    RT64::SetScenePathTracing(value<bool>(path_tracing_option, false) ? (uint32_t)value<double>(path_tracing_bounces_option, 2.0) : 0u);
    ray_tracing_on.store(ray_tracing);
    if (!ray_tracing) {
        ray_tracing_notified.store(false);
    }
    RT64::SetSceneScreenSpaceReflections((float)(shader(value<double>(ssr_option, 0.0)) / 100.0), (traced_brdf > 0.0f) ? 0.0f : (float)(shader(value<double>(ssr_stochastic_option, 0.0)) / 100.0));
    RT64::SetSceneLightShafts((float)(value<double>(light_shafts_option, 0.0) / 100.0));
    sun_shadows = value<double>(sun_shadows_option, 0.0) > 0.0;
    RT64::SetSceneSunShadows((float)(value<double>(sun_shadows_option, 0.0) / 100.0), value<bool>(sun_shadow_banjo_option, true),
        (float)(value<double>(sun_shadow_softness_option, 60.0) / 100.0));
    const float shadow_distance = (float)value<double>(sun_shadow_distance_option, 3000.0);
    sun_shadow_reach = sun_shadows ? shadow_distance : 0.0f;
    sun_shadow_distance_set.store(shadow_distance);
    RT64::SetSceneSunShadowDistance(shadow_distance);
    RT64::SetSceneGrass((float)(value<double>(grass_option, 0.0) / 100.0), (float)(value<double>(grass_height_option, 100.0) / 100.0),
        (float)value<double>(grass_distance_option, 1800.0), (float)(value<double>(grass_density_option, 100.0) / 100.0),
        (float)(value<double>(grass_patches_option, 50.0) / 100.0));
    RT64::SetSceneGrassBlades((float)(value<double>(grass_thickness_option, 100.0) / 100.0),
        (float)(value<double>(grass_random_length_option, 40.0) / 100.0), value<bool>(grass_chunky_option, false),
        (float)(value<double>(grass_chunk_size_option, 200.0) / 100.0), value<bool>(grass_pixelated_option, false),
        (float)value<double>(grass_pixel_size_option, 1.0), (float)(value<double>(grass_blend_option, 50.0) / 100.0));
    RT64::SetSceneGrassCulling(value<bool>(grass_frustum_cull_option, true), value<bool>(grass_occlusion_cull_option, true),
        value<bool>(grass_chunking_option, true));
    RT64::SetSceneGrassLod((float)(value<double>(grass_lod_option, 0.0) / 100.0), value<bool>(grass_half_rate_option, true));
    RT64::SetSceneGrassRayTracing(value<bool>(grass_ray_tracing_option, true));
    send_effect_textures();
    double fur = value<double>(banjo_fur_option, 0.0);
    if (const char* forced = std::getenv("TOOIE_BANJO_FUR")) {
        fur = std::atof(forced);
    }
    banjo_fur = fur > 0.0;
    RT64::SetSceneFur((float)(fur / 100.0), (float)(value<double>(banjo_fur_length_option, 100.0) / 100.0),
        (float)(value<double>(banjo_fur_density_option, 100.0) / 100.0), (float)(value<double>(banjo_fur_noisiness_option, 50.0) / 100.0));
    // NPCs' fur (the yetis' white fur), with its own sliders; TOOIE_NPC_FUR=<0-100> sets it instead (headless).
    double npc_fur_amount = value<double>(npc_fur_option, 0.0);
    if (const char* forced = std::getenv("TOOIE_NPC_FUR")) {
        npc_fur_amount = std::atof(forced);
    }
    npc_fur = npc_fur_amount > 0.0;
    RT64::SetSceneNpcFur((float)(npc_fur_amount / 100.0), (float)(value<double>(npc_fur_length_option, 100.0) / 100.0),
        (float)(value<double>(npc_fur_density_option, 100.0) / 100.0), (float)(value<double>(npc_fur_noisiness_option, 50.0) / 100.0));
    // Kazooie's feathers; TOOIE_KAZOOIE_FEATHERS=<0-100> sets them instead (headless).
    double feathers = value<double>(kazooie_feathers_option, 0.0);
    if (const char* forced = std::getenv("TOOIE_KAZOOIE_FEATHERS")) {
        feathers = std::atof(forced);
    }
    kazooie_feathers = feathers > 0.0;
    // TOOIE_FEATHER_TRANSPARENCY=<0-100> sets their transparency instead (headless).
    double feather_transparency = value<double>(kazooie_feather_transparency_option, 0.0);
    if (const char* forced = std::getenv("TOOIE_FEATHER_TRANSPARENCY")) {
        feather_transparency = std::atof(forced);
    }
    RT64::SetSceneKazooieFeathers((float)(feathers / 100.0), (float)(value<double>(kazooie_feather_size_option, 100.0) / 100.0),
        (float)(value<double>(kazooie_feather_length_option, 100.0) / 100.0), (float)(value<double>(kazooie_feather_density_option, 100.0) / 100.0),
        (float)(value<double>(kazooie_feather_noisiness_option, 50.0) / 100.0), (float)(feather_transparency / 100.0));
    // NPCs' feathers (Canary Mary), with their own sliders; TOOIE_NPC_FEATHERS=<0-100> sets them instead (headless).
    double npc_feather_amount = value<double>(npc_feathers_option, 0.0);
    if (const char* forced = std::getenv("TOOIE_NPC_FEATHERS")) {
        npc_feather_amount = std::atof(forced);
    }
    npc_feathers = npc_feather_amount > 0.0;
    RT64::SetSceneNpcFeathers((float)(npc_feather_amount / 100.0), (float)(value<double>(npc_feather_size_option, 100.0) / 100.0),
        (float)(value<double>(npc_feather_length_option, 100.0) / 100.0), (float)(value<double>(npc_feather_density_option, 100.0) / 100.0),
        (float)(value<double>(npc_feather_noisiness_option, 50.0) / 100.0), (float)(value<double>(npc_feather_transparency_option, 0.0) / 100.0));
    bool snow = shaders && value<bool>(deep_snow_option, false);
    if (const char* forced = std::getenv("TOOIE_DEEP_SNOW")) {
        snow = std::atoi(forced) != 0;
    }
    deep_snow = snow;
    bool sand = shaders && value<bool>(tessellated_sand_option, false);
    if (const char* forced = std::getenv("TOOIE_SAND")) {
        sand = std::atoi(forced) != 0;
    }
    tessellated_sand = sand;
    snow_height = (float)(value<double>(snow_height_option, 100.0) / 100.0);
    if (const char* forced = std::getenv("TOOIE_SNOW_HEIGHT")) {
        snow_height = (float)(std::atof(forced) / 100.0);
    }
    snow_detail = (float)(value<double>(snow_detail_option, 100.0) / 100.0);
    if (const char* forced = std::getenv("TOOIE_SNOW_DETAIL")) {
        snow_detail = (float)(std::atof(forced) / 100.0);
    }
    snow_refill = (float)value<double>(snow_refill_option, 0.0);
    snow_lod_distance = (float)value<double>(snow_lod_option, 2000.0);
    if (const char* forced = std::getenv("TOOIE_SNOW_LOD")) {
        snow_lod_distance = (float)std::atof(forced);
    }
    snow_sent = -1.0f;
    // Parallax mapping; TOOIE_PARALLAX=<0-100> sets it instead, TOOIE_PARALLAX_ALL=1 puts it on every texture of the
    // 3D world (headless, to find textures that suit it).
    double parallax = shader(value<double>(parallax_option, 0.0));
    if (const char* forced = std::getenv("TOOIE_PARALLAX")) {
        parallax = std::atof(forced);
    }
    // Parallax on the original textures (by their brightness) as well as on texture packs' height maps;
    // TOOIE_PARALLAX_ORIGINAL=0 or 1 sets it instead.
    bool parallax_original = value<bool>(parallax_original_option, true);
    if (const char* forced = std::getenv("TOOIE_PARALLAX_ORIGINAL")) {
        parallax_original = std::atoi(forced) != 0;
    }
    const char* parallax_all = std::getenv("TOOIE_PARALLAX_ALL");
    RT64::SetSceneParallax((float)(parallax / 100.0), parallax_original, (parallax_all != nullptr) && (std::atoi(parallax_all) != 0));
    send_parallax_textures();
    // Displaced ground (0-100); TOOIE_GROUND_DISPLACE=<0-100> sets it instead.
    double ground_displacement = shader(value<double>(ground_displacement_option, 0.0));
    if (const char* forced = std::getenv("TOOIE_GROUND_DISPLACE")) {
        ground_displacement = std::atof(forced);
    }
    // How far off it reaches, in world units; TOOIE_GROUND_DISTANCE=<units> sets it instead.
    double ground_distance = value<double>(ground_displacement_distance_option, 8000.0);
    if (const char* forced = std::getenv("TOOIE_GROUND_DISTANCE")) {
        ground_distance = std::atof(forced);
    }
    RT64::SetSceneGroundDisplacement((float)(ground_displacement / 100.0), (float)ground_distance);
    const uint32_t water = shaders ? value<uint32_t>(water_option, (uint32_t)Water::Original) : (uint32_t)Water::Original;
    modern_water = (water == (uint32_t)Water::Modern) || (water == (uint32_t)Water::Stylised);
    stylised_water = water == (uint32_t)Water::Stylised;
    if (const char* forced = std::getenv("TOOIE_MODERN_WATER")) {
        modern_water = std::atoi(forced) != 0;
        stylised_water = std::atoi(forced) == 2;
    }
    RT64::SetSceneModernWater(modern_water, stylised_water);
    double water_detail = value<double>(water_detail_option, 50.0);
    if (const char* forced = std::getenv("TOOIE_WATER_DETAIL")) {
        water_detail = std::atof(forced);
    }
    RT64::SetSceneWaterDetail((float)(water_detail / 100.0));
    bool shore_foam = shaders && value<bool>(shore_foam_option, false);
    if (const char* forced = std::getenv("TOOIE_SHORE_FOAM")) {
        shore_foam = std::atoi(forced) != 0;
    }
    RT64::SetSceneShoreFoam(shore_foam);
    // Test aid: TOOIE_OWN_MIST=<0 to 100> whatever the setting says.
    float own_mist = shaders ? (float)(value<double>(mist_option, 0.0) / 100.0) : 0.0f;
    if (const char* forced = std::getenv("TOOIE_OWN_MIST")) {
        own_mist = (float)(std::atof(forced) / 100.0);
    }
    RT64::SetSceneOwnMist(own_mist);
    water_waves_on = (shader(value<double>(water_waves_option, 0.0)) > 0.0) || modern_water;
    RT64::SetSceneWaterWaves((float)(shader(value<double>(water_waves_option, 0.0)) / 100.0), (float)(value<double>(wave_speed_option, 100.0) / 100.0));
    water_reflections_set = (float)(shader(value<double>(water_reflections_option, 0.0)) / 100.0);
    RT64::SetSceneWaterReflections(water_reflections_set.load());
    RT64::SetSceneIceReflections((float)(shader(value<double>(ice_reflections_option, 0.0)) / 100.0));
    water_settings_changed = true;
    RT64::SetSceneRimLight((float)(shader(value<double>(rim_light_option, 0.0)) / 100.0));
    RT64::SetSceneToonShading((float)(shader(value<double>(toon_world_option, 0.0)) / 100.0), (float)(shader(value<double>(toon_characters_option, 0.0)) / 100.0));
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

tooie::picture_filters::Preset tooie::picture_filters::preset() {
    if (!created) {
        return Preset::Custom;
    }
    return (Preset)value<uint32_t>(preset_option, (uint32_t)Preset::Custom);
}

void tooie::picture_filters::set_preset(Preset preset) {
    if (!created) {
        return;
    }
    graphics_config().update_option_value(preset_option, (uint32_t)preset);
    apply_preset(preset);
    graphics_config().save_config();
}

bool tooie::picture_filters::toon_characters_on() {
    return value<double>(toon_characters_option, 0.0) > 0.0;
}

bool tooie::picture_filters::banjo_fur_on() {
    return banjo_fur;
}

// Ray tracing shows sun shadows (traced ones) at 60 at least whatever the slider says, so the game keeps the whole
// level and the off-screen casters drawn then too.
static bool traced_shadows_on() {
    return ray_tracing_on.load() && (RT64::GetRayTracingSupport() == 2);
}

bool tooie::picture_filters::ray_tracing_active() {
    return traced_shadows_on();
}

bool tooie::picture_filters::traced_beams_on() {
    return ray_tracing_active() && (value<double>(traced_beams_option, 60.0) > 0.0);
}

bool tooie::picture_filters::sun_shadows_on() {
    return sun_shadows || traced_shadows_on();
}

float tooie::picture_filters::sun_shadow_distance() {
    return traced_shadows_on() ? sun_shadow_distance_set.load() : sun_shadow_reach.load();
}

bool tooie::picture_filters::kazooie_feathers_on() {
    return kazooie_feathers;
}

bool tooie::picture_filters::npc_fur_on() {
    return npc_fur;
}

bool tooie::picture_filters::npc_feathers_on() {
    return npc_feathers;
}

float tooie::picture_filters::underwater() {
    return underwater_shared;
}

bool tooie::picture_filters::applying_effects_preset() {
    return applying_preset;
}

void tooie::picture_filters::tick(uint8_t* rdram, recomp_context* ctx) {
    (void)ctx;
    {
        static bool logged = false;
        const int support = RT64::GetRayTracingSupport();
        if (!logged && support != 0) {
            logged = true;
            std::fprintf(stderr, "[ray-tracing] hardware ray tracing: %s (Graphics > Ray tracing is %s)\n", support == 2 ? "yes" : "no", ray_tracing_on.load() ? "on" : "off");
        }
    }
    if (ray_tracing_on.load() && !ray_tracing_notified.load() && RT64::GetRayTracingSupport() == 1) {
        ray_tracing_notified.store(true);
        std::fprintf(stderr, "[ray-tracing] no ray queries on this device or renderer; using the current effects\n");
        tooie::toast::show("Ray tracing needs the Vulkan renderer and a graphics card with ray tracing. Using the current effects.");
    }
    // Traced light beams: their strength, and in a room Window Light Beams knows, the way its windows' light comes in.
    {
        static float beams_sent = -1.0f;
        static uint16_t beams_map_sent = 0xFFFF;
        const uint16_t map = tooie::debug::current_map(rdram);
        // Not where beams are drawn (Mumbo's Skulls, and the rooms Window Light Beams covers): they would double.
        const bool drawn = tooie::window_beams::drawn_beams(map);
        const float beams = (traced_beams_on() && !drawn) ? (float)(value<double>(traced_beams_option, 60.0) / 100.0) : 0.0f;
        if ((beams != beams_sent) || (map != beams_map_sent)) {
            beams_sent = beams;
            beams_map_sent = map;
            float direction[3];
            RT64::SetSceneTracedBeams(beams, tooie::window_beams::room_light(map, direction) ? direction : nullptr);
        }
    }
    // A pick made in parallax pick mode shows at once.
    if (tooie::parallax_pick::version() != parallax_sent_version.load()) {
        send_parallax_textures();
    }
    // Likewise for Shader Effects pick mode.
    if (effect_textures_version() != effects_sent_version.load()) {
        send_effect_textures();
    }
    // DEV > Blend texture seams; TOOIE_TEXTURE_SEAMS=0 or 1 sets it instead (headless A/B).
    {
        bool seams = true;
        try {
            seams = std::get<bool>(recompui::config::get_config(tooie::wip_tab_id).get_option_value(texture_seams_option));
        } catch (...) {
        }
        static const char* forced_seams = std::getenv("TOOIE_TEXTURE_SEAMS");
        if (forced_seams != nullptr) {
            seams = std::atoi(forced_seams) != 0;
        }
        RT64::SetSceneTextureSeams(seams);
    }
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
    underwater_shared = underwater_amount;
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

    // Icy Side keeps the game's icy water with Modern water on (L's pick, 2026-10-17): the game's own water there. Its
    // frozen lake is drawn with an ice texture, so it reflects with Ice reflections.
    {
        const uint16_t map = (uint16_t)MEM_HU(0, (int32_t)0x80132DC2);
        const bool icy = modern_water && (map == 0x128);
        // Only the icy maps' flat see-through decals are ice (Icy Side, the Ice Train Station, Chilly Willy, Boggy's Igloo,
        // Icicle Grotto, the parade); elsewhere they are dirt and grass blended onto the ground.
        const bool icy_level = (map == 0x128) || (map == 0x12A) || (map == 0x12C) || (map == 0x131) || (map == 0x132) || (map == 0x168);
        static int ice_sent = -1;
        if (int(icy_level) != ice_sent) {
            ice_sent = int(icy_level);
            RT64::SetSceneIcyLevel(icy_level);
        }
        static bool icy_sent = false;
        if ((icy != icy_sent) || water_settings_changed.exchange(false)) {
            icy_sent = icy;
            RT64::SetSceneModernWater(modern_water && !icy, stylised_water);
            RT64::SetSceneWaterReflections(water_reflections_set.load());
        }
    }

    // Deep snow on the maps with snow only.
    {
        const uint16_t map = (uint16_t)MEM_HU(0, (int32_t)0x80132DC2);
        // (Elsewhere tessellated sand, through the same: most of the snow's ankle depth (a third was too shallow to
        // see a footprint), on sand only.)
        const bool sand = tessellated_sand && !(deep_snow && snowy_map(map));
        const float snow = (deep_snow && snowy_map(map)) ? snow_height.load() : (sand ? 1.0f : 0.0f);
        // Icy Side has pale ice beside its snow; elsewhere the snow is bluer.
        const bool strict = (map == 0x128);
        static bool strict_sent = true;
        static float detail_sent = -1.0f;
        static float refill_sent = -1.0f;
        static float lod_sent = -1.0f;
        static uint16_t map_sent = 0xFFFF;
        const float detail = snow_detail.load();
        const float refill = snow_refill.load();
        const float lod = snow_lod_distance.load();
        static bool sand_sent = false;
        if ((snow != snow_sent.load()) || (strict != strict_sent) || (detail != detail_sent) || (refill != refill_sent) || (lod != lod_sent) || (map != map_sent) ||
            (sand != sand_sent)) {
            sand_sent = sand;
            snow_sent = snow;
            strict_sent = strict;
            detail_sent = detail;
            refill_sent = refill;
            lod_sent = lod;
            map_sent = map;
            RT64::SetSceneSnow(snow > 0.0f, snow, strict, detail, refill, lod, map, sand);
        }
    }
    // The fog is measured from Banjo.
    {
        float pos[3];
        const bool valid = banjo_position(rdram, pos);
        RT64::SetScenePlayer(valid, valid ? pos[0] : 0.0f, valid ? pos[1] : 0.0f, valid ? pos[2] : 0.0f, banjo_grounded(rdram));
    }

    // The same shimmer, gentler, under water. By lava it only rises above hot things (lava, fire); under water it
    // covers the whole picture.
    const bool warm = by_lava(rdram);
    const float heat = warm ? heat_haze.load() : underwater_distortion.load() * underwater_amount * 0.5f;
    if ((heat != heat_haze_sent) || (warm != heat_haze_warm_sent)) {
        heat_haze_sent = heat;
        heat_haze_warm_sent = warm;
        RT64::SetSceneHeatHaze(heat, warm);
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
        "Sets all the picture effects below at once. <recomp-color primary>Vanilla</recomp-color> turns them all off, so none of the effect shaders run. <recomp-color primary>Enhanced</recomp-color> adds SMAA, ambient occlusion and sharpening. <recomp-color primary>Retro</recomp-color> gives N64 16-bit colour and a CRT look. Changing any of them yourself makes it <recomp-color primary>Custom</recomp-color>.",
        {
            {Preset::Custom, "Custom", "Custom"},
            {Preset::Original, "Original", "Vanilla"},
            {Preset::Enhanced, "Enhanced", "Enhanced"},
            {Preset::Retro, "Retro", "Retro"},
        },
        // A first launch or a fresh graphics.json starts on Vanilla (L, 2026-10-17).
        Preset::Original);
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
        "Turns on the lighting, water and other effects below and shows their settings. Off plays the game without them (their settings are kept for when you turn it back on).",
        true);

    graphics.add_number_option(
        ambient_occlusion_option,
        "Ambient occlusion",
        "Soft shading where surfaces meet: in corners, under ledges and around things standing on the ground (Ground Truth Ambient Occlusion). 50 is GTAO as it is; higher deepens it. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        ssgi_option,
        "SSGI",
        "Screen-space global illumination: light bounced off the surfaces on screen lights what faces them, so a sunny floor brightens the wall beside it and colours rub off on each other. Heavier than Bounce light. 50 is one bounce as it is. 0 is off.",
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
        toon_characters_option,
        "Toon shading: Characters",
        "Cel shading for Banjo, Kazooie and the game's other characters and enemies (not rocks or other objects, which follow World): the lit picture is split into a few flat bands of light and shadow with soft steps between them, shadows cool and lit parts warm. Works well with the toon outlines and Rim light. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        toon_world_option,
        "Toon shading: World",
        "The same cel shading for everything that isn't a character: the ground, walls, buildings, rocks, other objects and the sky. Set it apart from the characters' to have one without the other. 0 is off.",
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
        water_waves_option,
        "Water waves",
        "Waves roll across the game's water: the water seen through bends with them, and their slopes catch the light. Drawn on the picture, so Banjo still floats at the same height. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        wave_speed_option,
        "Water wave speed",
        "How fast the water waves move, in percent. 100 is normal.",
        25, 200, 5, 0, false, 100);
    graphics.add_number_option(
        water_detail_option,
        "Water detail",
        "With Water on <recomp-color primary>Modern</recomp-color> or <recomp-color primary>Stylised</recomp-color>: the water round the player is cut into fine moving geometry, so the swell and the rings the player pushes out are real bumps in the surface. Higher cuts it finer and further out, which costs more. 0 keeps the flat surface with drawn-on waves. Needs a graphics card with tessellation; without it the drawn-on waves are used.",
        0, 100, 5, 0, false, 50);
    graphics.add_enum_option(
        water_option,
        "Water",
        "<recomp-color primary>Original</recomp-color> is the game's own water. <recomp-color primary>Modern</recomp-color> replaces it with new water: clear in the shallows and darker with depth in each level's own colour, bent by rolling waves, reflecting the sky and scenery more at low angles, with the sun's glint, foam along the shores and rings, a wake and splashes round the player. <recomp-color primary>Stylised</recomp-color> is Modern with a cartoon look: sharp crossing wave crests, a clean shallow-to-deep gradient, crisp white foam along the shores, round anything poking out of the water and in breakers rolling in, and bright rippling light on everything under the surface. Modern and Stylised make their own reflections, so Water reflections is not used; their waves follow Water waves (50 when that is 0) and Water wave speed. Under water, the game's water surface is kept for now. Drawn on the picture, so the player still floats at the same height.",
        {
            {Water::Original, "Original", "Original"},
            {Water::Modern, "Modern", "Modern"},
            {Water::Stylised, "Stylised", "Stylised"},
        },
        Water::Original);
    graphics.add_bool_option(
        shore_foam_option,
        "Shore foam",
        "With Water on <recomp-color primary>Original</recomp-color>: a broken white line of foam drifts along the edges of the game's water, where it gets shallow, as in Modern water. Modern water always has it.",
        false);
    graphics.add_number_option(
        mist_option,
        "Mist",
        "Pale mist drifts in banks over low ground, hangs thickest on and round water, and rises as spray where waterfalls land. Always showing, at any time of day. While Day and Night runs in a level, its own Mist and Mist Time settings are used instead. 0 turns it off.",
        0, 100, 5, 0, false, 0);
    graphics.add_bool_option(
        deep_snow_option,
        "Deep snow",
        "The snow on the ground lies deep, as a real layer of snow (Hailfire Peaks' Icy Side): Banjo, the NPCs and the enemies press it down wherever they touch it, with the snow banked up round the dents, and the dents stay (or fill back in, with Snow fills back in). Drawn on the picture, so nothing in the game changes.",
        false);
    graphics.add_bool_option(
        tessellated_sand_option,
        "Tessellated sand",
        "Sandy ground takes footprints: Banjo, the NPCs and the enemies press shallow, detailed prints into it wherever they touch it, and the wind has left low ripples over it. As Deep snow, with its detail, fills back in and distance settings. Needs a graphics card with tessellation.",
        false);
    graphics.add_number_option(
        snow_height_option,
        "Snow height",
        "How deep the deep snow is, in percent. 100 is about ankle deep on Banjo, 300 up to his knees. Deeper snow costs a little more.",
        25, 300, 5, 0, false, 100);
    graphics.add_number_option(
        snow_detail_option,
        "Snow detail",
        "How fine the dents in the deep snow are, in percent. 100 is the finest; 50 is as coarse as it first was, and lower still is coarser. Lower is lighter on weaker graphics cards.",
        25, 100, 5, 0, false, 100);
    graphics.add_number_option(
        snow_refill_option,
        "Snow fills back in",
        "How many seconds prints in the deep snow stay before they fill back in (then sooner while it snows). 0 is off: they stay until you leave the area (going into a hut counts). On is a little lighter on the graphics card, as the snow is only cut finely where prints still show.",
        0, 600, 5, 0, false, 0);
    graphics.add_number_option(
        snow_lod_option,
        "Snow LOD distance",
        "How far from the camera the deep snow keeps its full detail. Further away it is drawn smoother and smoother, which is cheaper. Higher shows the dents in full from further off.",
        250, 10000, 250, 0, false, 2000);
    graphics.add_number_option(
        parallax_option,
        "Parallax",
        "Stone walls, paving and rock get depth: the stones stand out of the surface and the gaps and cracks between them sink in and fall into shadow, shifting as the camera moves, instead of looking painted on. Texture packs can give their textures depth with height maps (see Parallax on original textures). Higher numbers are deeper. Drawn on the picture, so nothing in the game changes. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_bool_option(
        parallax_original_option,
        "Parallax on original textures",
        "Parallax on the game's own stone, brick and rock textures, whose depth is worked out from how dark each part is. Off, only a texture pack's textures that come with a height map get parallax (a pack's \"wall.png\" with \"wall_height.png\" beside it, white high and black deep).",
        true);
    graphics.add_number_option(
        ground_displacement_option,
        "Displaced ground",
        "The ground's cracks, gaps and grooves become real dips: floors with a Parallax texture (cracked flagstones, cobbles, paving, dirt) are cut into fine triangles near the camera and the dark parts of the texture pushed down, so the surface has a real outline and depth, not only a painted-on look. Higher numbers are deeper. Walls are left alone, and so is the ground near the edge of each piece. Uses Parallax's list of textures and their shapes and depths (Parallax on original textures must be on). Needs a graphics card with tessellation. Drawn on the picture, so nothing in the game changes. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        ground_displacement_distance_option,
        "Displaced ground distance",
        "How far from the camera the ground is displaced, in the game's units. The dips fade out over the last quarter. Further costs more: every displaced floor in reach is cut into fine triangles.",
        2000, 20000, 500, 0, false, 8000);
    graphics.add_bool_option(
        ray_tracing_option,
        "Ray tracing",
        "Ray traced effects: reflections on shiny surfaces and water, sun shadows and shadows from lamps and fires, ambient occlusion, and bounce and sky light, all found by tracing rays through the level's triangles instead of marching the picture. It is a switch of its own, apart from the shader effects: while it is on each of those shows at least as strongly as Ray tracing strength says, even with its own setting at 0 (a higher setting wins). Needs the Vulkan renderer and a graphics card with hardware ray tracing (ray queries): without them this shows a notice and the effects carry on as you have set them. Heavy on the graphics card.",
        false);
    graphics.add_number_option(
        ray_tracing_strength_option,
        "Ray tracing strength",
        "How strongly the ray traced effects show while Ray tracing is on: the least each of them is drawn at (sun shadows at this, ambient occlusion and bounce light a little under it; the reflections have sliders of their own below). An effect's own slider still wins when it is higher. 60 is the default; 100 makes them plain.",
        0, 100, 5, 0, false, 60);
    graphics.add_number_option(
        ray_tracing_reflections_option,
        "Traced reflections",
        "How much shiny surfaces reflect while Ray tracing is on: metal, tiles and the other shiny textures, and whatever Parallax pick mode marks Metal, Tiles or Smooth. The Screen-space reflections slider still wins when it is higher. 0 turns the traced reflections off. 60 is the default.",
        0, 100, 5, 0, false, 60);
    graphics.add_number_option(
        ray_tracing_water_reflections_option,
        "Traced water reflections",
        "How much water reflects while Ray tracing is on (traced, so what is off screen shows too). The Water reflections slider still wins when it is higher. 60 is the default.",
        0, 100, 5, 0, false, 60);
    graphics.add_number_option(
        ray_tracing_metal_option,
        "Metal reflection",
        "How mirror-like the surfaces Parallax calls Metal are, in percent of Traced reflections. 100 is the default.",
        0, 100, 5, 0, false, 100);
    graphics.add_number_option(
        ray_tracing_tiles_option,
        "Tiles reflection",
        "How much the surfaces Parallax calls Tiles reflect, in percent of Traced reflections. 60 is the default.",
        0, 100, 5, 0, false, 60);
    graphics.add_number_option(
        ray_tracing_smooth_option,
        "Smooth surface reflection",
        "How much the surfaces Parallax calls Smooth reflect, in percent of Traced reflections. 35 is the default; stone, wood, dirt and the rest never reflect.",
        0, 100, 5, 0, false, 35);
    graphics.add_number_option(
        ray_tracing_smoothing_option,
        "Ray tracing noise smoothing",
        "How much the ray traced light and shadows are smoothed out where they get grainy, mostly on Banjo's fur (whose surface turns every pixel, so each pixel caught different rays and the fur crawled as he moved). Higher is calmer but softer; 0 is the raw rays. 50 is the default. Needs Ray tracing on.",
        0, 100, 5, 0, false, 50);
    graphics.add_number_option(
        ray_tracing_brdf_option,
        "Ray traced BRDF",
        "Every traced reflection becomes a physically based one: rays are scattered over a GGX lobe (Smith visibility, weighted by the BRDF over each ray's probability), as wide as this setting, so reflections go from a sharp mirror to a soft brushed blur on shiny surfaces and on materials from Ray Tracing Material Pick Mode (which set their own roughness). Turns the screen-space Stochastic reflections off while it is above 0. Grainier the higher it goes. Needs Ray tracing on. 0 is off: mirror reflections.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        ray_tracing_subsurface_option,
        "Ray traced subsurface scattering",
        "Light that gets into a thin or soft surface and comes out the other side: leaves and grass glow with the sun or a lamp behind them (traced rays check the light reaches the back of the surface and how much solid there is to pass through), and shadowed parts keep a soft coloured glow instead of going flat dark. Textures given Subsurface in Ray Tracing Material Pick Mode use it at their own strength whatever this is set to. Needs Ray tracing on. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_bool_option(
        path_tracing_option,
        "Path tracing",
        "The traced bounce light goes on bouncing: a ray that lands on a surface turns off it and carries on, picking up the colours along the way, so light reaches round corners and deeper into rooms and caves. Needs Ray tracing on and the bounce light showing (Ray tracing strength above 0 or Screen-space GI on). Heavy on the graphics card: each bounce traces three more rays a pixel.",
        false);
    graphics.add_number_option(
        path_tracing_bounces_option,
        "Path tracing bounces",
        "How many more times light bounces with Path tracing on, after the first. More reaches further into shadowed places but costs more. 2 is the default.",
        1, 4, 1, 0, false, 2);
    graphics.add_number_option(
        traced_beams_option,
        "Traced light beams",
        "Shafts of light through the air, found by tracing rays towards the light: in a room the light only gets in at the windows, so the beams take the windows' shapes and anything standing in them (Banjo too) cuts its shadow through them; outdoors it is a thin haze with shafts between trees and under arches. Where beams are drawn (Mumbo's Skulls, and the rooms Window Light Beams covers while it is on), those are kept instead. Needs Ray tracing on. 0 is off. Costs a dozen rays a pixel.",
        0, 100, 5, 0, false, 60);
    graphics.add_bool_option(
        ray_tracing_player_shadows_option,
        "Traced shadows of the player",
        "Whether Banjo and Kazooie (or whoever you are playing) cast traced shadows: from the sun, the lamps and fires, and straight down on the ground. Off, the player casts none of them, and light and shadows go on through as if they weren't there; everything else keeps its traced shadows. Use it with HD shadows for the game's own shadow under the player. Needs Ray tracing on.",
        true);
    graphics.add_bool_option(
        ray_tracing_hit_colours_option,
        "Ray tracing hit colours",
        "Experimental. A traced reflection or bounce that lands on something the picture can't see (off the screen, or hidden behind something) uses the colour that spot had when it was last on screen, remembered in the world as you look around, instead of smearing the nearest colour from the picture. Adds a small cost every frame. Needs Ray tracing on. Starts off: if you see flicker, wrong colours or a crash, leave it off and tell me.",
        false);
    graphics.add_bool_option(
        reflections_section_option,
        "Reflections",
        "Shows the reflection settings below. Hiding them does not turn the reflections off.",
        true);
    graphics.add_number_option(
        ssr_option,
        "Screen-space reflections",
        "Shiny surfaces (metal and tiles, and water and ice when their own reflections are off) reflect what is on screen, most at grazing angles. Only what is on screen can be reflected, so reflections fade out near the edges of the picture. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        ssr_stochastic_option,
        "Stochastic reflections",
        "Makes Screen-space reflections glossy instead of mirror-sharp (a port of simeonradivoev's Compute Stochastic Reflections, MIT): each pixel sends a few rays spread over a lobe that widens with this setting, and blends what they find. The result is slightly grainy and blurrier the higher it goes. Needs Screen-space reflections above 0. Starts at 0, which keeps the mirror reflections.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        water_reflections_option,
        "Water reflections",
        "The game's water mirrors what is around it, with gentle ripples. Only what is on screen can be reflected, so reflections fade near the edges. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        ice_reflections_option,
        "Ice reflections",
        "Ice mirrors what is around it: frozen water, ice floors and walls, and the blocks of ice round notes, from any camera height. Only what is on screen can be reflected. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_bool_option(
        character_section_option,
        "Character Shaders",
        "Shows Banjo's fur and Kazooie's feather shaders below. Hiding them does not turn any of them off.",
        true);
    graphics.add_number_option(
        banjo_fur_option,
        "Banjo fur",
        "Banjo's brown fur grows real strands: layers of short hairs stand out of his model and move with him, darker at the roots, in play and in cutscenes. Kazooie, his shorts, feet and backpack are left as they are, and so is everyone else. Higher numbers give a thicker coat. Drawn on the picture, so nothing in the game changes. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        banjo_fur_length_option,
        "Banjo fur length",
        "How long Banjo's fur is, in percent. 100 is short and fluffy; 1500 is very long, for fun.",
        25, 1500, 5, 0, false, 100);
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
        kazooie_feathers_option,
        "Kazooie feathers",
        "Kazooie's red feathers grow real feathers: lots of little flat ones lying over each other down her body, each in her own colour there, so she looks feathered instead of smooth. Her beak and legs stay as they are. Higher numbers pack them more thickly. Needs a graphics card with geometry shaders (not on Mac). 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        kazooie_feather_size_option,
        "Kazooie feather size",
        "How big Kazooie's feathers are, in percent.",
        50, 200, 5, 0, false, 100);
    graphics.add_number_option(
        kazooie_feather_length_option,
        "Kazooie feather length",
        "How long Kazooie's feathers are, in percent, keeping their width.",
        25, 300, 5, 0, false, 100);
    graphics.add_number_option(
        kazooie_feather_density_option,
        "Kazooie feather density",
        "How many feathers Kazooie has, in percent: higher packs them more thickly.",
        25, 300, 5, 0, false, 100);
    graphics.add_number_option(
        kazooie_feather_noisiness_option,
        "Kazooie feather noisiness",
        "How uneven Kazooie's feathers are: higher turns them more different ways and makes them more different in size and shade, 0 an even coat.",
        0, 100, 5, 0, false, 50);
    graphics.add_number_option(
        kazooie_feather_transparency_option,
        "Kazooie feather transparency",
        "How see-through Kazooie's feathers are, so more of her own colours show through them. 0 is solid.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        npc_fur_option,
        "NPC fur",
        "Furry characters grow white fur like Banjo's: the yetis on Hailfire Peaks' Icy Side, not on their faces or hands. Higher numbers give a thicker coat. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        npc_fur_length_option,
        "NPC fur length",
        "How long the NPCs' fur is, in percent. 100 is short and fluffy.",
        25, 300, 5, 0, false, 100);
    graphics.add_number_option(
        npc_fur_density_option,
        "NPC fur density",
        "How many hairs the NPCs' fur has, in percent: higher is more, finer hairs, lower is fewer, thicker ones.",
        25, 300, 5, 0, false, 100);
    graphics.add_number_option(
        npc_fur_noisiness_option,
        "NPC fur noisiness",
        "How uneven the NPCs' fur is: higher gives tufts that stand taller or lower, 0 an even coat.",
        0, 100, 5, 0, false, 50);
    graphics.add_number_option(
        npc_feathers_option,
        "NPC feathers",
        "Feathered characters grow feathers like Kazooie's in their own colours: Canary Mary, not on her face, hair or beak. Higher numbers pack them more thickly. Needs a graphics card with geometry shaders (not on Mac). 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        npc_feather_size_option,
        "NPC feather size",
        "How big the NPCs' feathers are, in percent.",
        50, 200, 5, 0, false, 100);
    graphics.add_number_option(
        npc_feather_length_option,
        "NPC feather length",
        "How long the NPCs' feathers are, in percent, keeping their width.",
        25, 300, 5, 0, false, 100);
    graphics.add_number_option(
        npc_feather_density_option,
        "NPC feather density",
        "How many feathers the NPCs have, in percent: higher packs them more thickly.",
        25, 300, 5, 0, false, 100);
    graphics.add_number_option(
        npc_feather_noisiness_option,
        "NPC feather noisiness",
        "How uneven the NPCs' feathers are: higher turns them more different ways and makes them more different in size and shade, 0 an even coat.",
        0, 100, 5, 0, false, 50);
    graphics.add_number_option(
        npc_feather_transparency_option,
        "NPC feather transparency",
        "How see-through the NPCs' feathers are, so more of their own colours show through them. 0 is solid.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        heat_haze_option,
        "Heat haze",
        "Near lava (Hailfire Peaks' lava side, Chilli Billi, inside the volcano), the air shimmers above hot things such as lava and fire, more in the distance. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        sun_shadows_option,
        "Sun shadows",
        "Real-time shadows from the sun: every character, enemy, object and piece of scenery casts a shadow onto what is behind it, moving as they move. The whole level casts one, on screen or not. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_bool_option(
        sun_shadow_banjo_option,
        "Sun shadow on Banjo",
        "Whether Banjo casts a sun shadow too. Off leaves his to HD shadows or the game's own. With Ray tracing on, Traced shadows of the player decides instead.",
        true);
    graphics.add_number_option(
        sun_shadow_softness_option,
        "Sun shadow softness",
        "How smooth the sun shadows are. Higher blends the light across a character's body instead of shading it face by face, and gives shadow edges a softer fade. 0 is the sharpest.",
        0, 100, 5, 0, false, 60);
    graphics.add_number_option(
        sun_shadow_distance_option,
        "Sun shadow distance",
        "How far from the camera sun shadows are sharp, in game units; past it the level's shadows carry on, softer. The whole level casts, and characters and objects within this distance, on screen or not, so shadows stay put as the camera turns. Past 6000 each shadow is a little blurrier, and higher costs more.",
        1500, 20000, 500, 0, false, 3000);
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
        500, 6000, 250, 0, false, 1800);
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
    graphics.add_number_option(
        grass_blend_option,
        "3D grass blending",
        "How much the 3D grass takes on the colour of the ground it grows from, so it blends in instead of standing out: most at the roots (no dark line where the blades meet the ground) and further away. 0 is off.",
        0, 100, 5, 0, false, 50);
    graphics.add_bool_option(
        grass_chunky_option,
        "Chunky 3D grass",
        "Low-poly 3D grass to suit the N64 look: fewer, wider blades, each a single flat-coloured triangle. Also cheaper to draw.",
        false);
    graphics.add_number_option(
        grass_chunk_size_option,
        "Chunk size",
        "With Chunky 3D grass: how big the chunky blades are, in percent of a normal blade. They also grow further apart, so the grass gets coarser. Higher is chunkier and cheaper.",
        100, 400, 25, 0, false, 200);
    graphics.add_bool_option(
        grass_pixelated_option,
        "Pixelated 3D grass",
        "Draws the 3D grass blades in blocks the size of the N64's own pixels, so they look blocky and pixel-sharp at any resolution. Works with or without Chunky 3D grass.",
        false);
    graphics.add_number_option(
        grass_pixel_size_option,
        "Pixel size",
        "With Pixelated 3D grass: how big the blocks are, in N64 pixels. 1 matches the game's own pixels; lower is finer (0.5 is half an N64 pixel), higher is blockier. A block is never smaller than one pixel of your screen.",
        0.25, 8, 0.25, 2, false, 1);
    graphics.add_bool_option(
        grass_edges_option,
        "3D grass on edges",
        "Also grow 3D grass on the grassy parts of textures that are only partly grass: the grass fringe along cliff tops and banks, and grass at the foot of rocks and walls. The blades lean out from slopes and walls.",
        true);
    graphics.add_bool_option(
        grass_frustum_cull_option,
        "Frustum culling",
        "Skips 3D grass blades that are off the edges of the screen before they are drawn. Looks the same; faster.",
        true);
    graphics.add_bool_option(
        grass_occlusion_cull_option,
        "Occlusion culling",
        "With Chunking: skips whole chunks of 3D grass hidden behind walls, hills and other nearer things, using the depth of the frame before. Single blades are never hidden this way, so grass doesn't vanish behind Banjo as he moves. Turns itself off for a frame when the camera cuts or turns fast.",
        true);
    graphics.add_bool_option(
        grass_chunking_option,
        "Chunking",
        "With Frustum culling: sorts the grassy ground into chunks and skips whole chunks that are off screen (or, with Occlusion culling, hidden) at once, before looking at single blades. Not the same as Chunky 3D grass. Looks the same; faster.",
        true);
    graphics.add_number_option(
        grass_lod_option,
        "3D grass LOD",
        "How much the 3D grass thins out with distance, in percent: fewer, wider blades further away. 0 is off: every blade is placed once, stays where it is and is drawn all the way out to 3D grass distance (slowest). Higher thins it out sooner and is faster; each blade still keeps its place.",
        0, 100, 5, 0, false, 0);
    graphics.add_bool_option(
        grass_half_rate_option,
        "30 FPS 3D grass",
        "Works out which 3D grass blades to draw, and their sway in the wind, 30 times a second instead of every frame, and draws them again in between. Faster above 30 FPS; the wind and the grass parting round Banjo update at 30 FPS.",
        true);
    graphics.add_bool_option(
        grass_ray_tracing_option,
        "3D grass in ray tracing",
        "With Ray tracing on: the 3D grass near Banjo casts traced shadows (sun, lamps, light beams) and shows in traced reflections. Off leaves the grass out of the rays (faster).",
        true);

    for (const std::string* id : { &brightness_option, &brightness_pattern_option, &colourblind_option, &colourblind_strength_option,
                                   &three_point_option, &dither16_option, &crt_option, &sharpen_option, &contrast_option,
                                   &saturation_option, &vignette_option, &grain_option, &ambient_occlusion_option,
                                   &fog_option, &fog_start_option, &fog_colour_option, &outlines_option, &outline_thickness_option, &bloom_option, &cutscene_dof_option, &gameplay_dof_option,
                                   &eye_adaptation_option, &rim_light_option, &toon_world_option, &toon_characters_option, &underwater_tint_option, &underwater_haze_option, &heat_haze_option, &underwater_distortion_option, &water_reflections_option, &ice_reflections_option, &bounce_light_option, &ssgi_option, &ssr_option, &ssr_stochastic_option, &ray_tracing_option, &ray_tracing_strength_option, &ray_tracing_reflections_option, &ray_tracing_water_reflections_option, &ray_tracing_metal_option, &ray_tracing_tiles_option, &ray_tracing_smooth_option, &ray_tracing_smoothing_option, &ray_tracing_brdf_option, &ray_tracing_subsurface_option, &path_tracing_option, &path_tracing_bounces_option, &traced_beams_option, &ray_tracing_player_shadows_option, &ray_tracing_hit_colours_option, &texture_upscale_option, &water_waves_option, &wave_speed_option, &water_detail_option, &light_shafts_option, &sun_shadows_option, &sun_shadow_banjo_option, &sun_shadow_softness_option, &sun_shadow_distance_option, &grass_option, &grass_height_option, &grass_distance_option, &grass_density_option, &grass_patches_option, &grass_thickness_option, &grass_random_length_option, &grass_blend_option, &grass_chunky_option, &grass_chunk_size_option, &grass_pixelated_option, &grass_pixel_size_option, &grass_edges_option, &grass_frustum_cull_option, &grass_occlusion_cull_option, &grass_chunking_option, &grass_lod_option, &grass_half_rate_option, &grass_ray_tracing_option, &deep_snow_option, &tessellated_sand_option, &snow_height_option, &snow_detail_option, &snow_refill_option, &snow_lod_option, &parallax_option, &parallax_original_option, &ground_displacement_option, &ground_displacement_distance_option, &banjo_fur_option, &banjo_fur_length_option, &banjo_fur_density_option, &banjo_fur_noisiness_option, &kazooie_feathers_option, &kazooie_feather_size_option, &kazooie_feather_length_option, &kazooie_feather_density_option, &kazooie_feather_noisiness_option, &kazooie_feather_transparency_option, &npc_fur_option, &npc_fur_length_option, &npc_fur_density_option, &npc_fur_noisiness_option, &npc_feathers_option, &npc_feather_size_option, &npc_feather_length_option, &npc_feather_density_option, &npc_feather_noisiness_option, &npc_feather_transparency_option, &water_option, &shore_foam_option, &mist_option, &lighting_section_option }) {
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
    graphics.add_option_hidden_dependency(ssgi_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(outlines_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(outline_thickness_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(rim_light_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(toon_characters_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(toon_world_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(underwater_tint_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(underwater_haze_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(underwater_distortion_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(reflections_section_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(water_reflections_option, reflections_section_option, false);
    graphics.add_option_hidden_dependency(ice_reflections_option, reflections_section_option, false);
    graphics.add_option_hidden_dependency(ssr_option, reflections_section_option, false);
    graphics.add_option_hidden_dependency(ssr_stochastic_option, reflections_section_option, false);
    graphics.add_option_hidden_dependency(water_waves_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(wave_speed_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(water_detail_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(water_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(shore_foam_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(mist_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(grass_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_height_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_distance_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_density_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_patches_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_thickness_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_random_length_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_blend_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_chunky_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_pixelated_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_chunk_size_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_pixel_size_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_edges_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_frustum_cull_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_occlusion_cull_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_chunking_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_lod_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_half_rate_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_ray_tracing_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(deep_snow_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(tessellated_sand_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(snow_height_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(snow_detail_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(snow_refill_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(snow_lod_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(parallax_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(parallax_original_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(ground_displacement_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(ground_displacement_distance_option, lighting_section_option, false);
    // Banjo's fur and Kazooie's feathers sit in their own Character Shaders section (L, 2026-10-16).
    for (const std::string* option : { &banjo_fur_option, &banjo_fur_length_option, &banjo_fur_density_option, &banjo_fur_noisiness_option, &kazooie_feathers_option, &kazooie_feather_size_option, &kazooie_feather_length_option, &kazooie_feather_density_option, &kazooie_feather_noisiness_option, &kazooie_feather_transparency_option, &npc_fur_option, &npc_fur_length_option, &npc_fur_density_option, &npc_fur_noisiness_option, &npc_feathers_option, &npc_feather_size_option, &npc_feather_length_option, &npc_feather_density_option, &npc_feather_noisiness_option, &npc_feather_transparency_option }) {
        graphics.add_option_hidden_dependency(*option, character_section_option, false);
    }
    graphics.add_option_hidden_dependency(heat_haze_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(sun_shadows_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(sun_shadow_banjo_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(sun_shadow_softness_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(sun_shadow_distance_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(light_shafts_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(bloom_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(eye_adaptation_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(cutscene_dof_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(gameplay_dof_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(fog_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(fog_start_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(fog_colour_option, lighting_section_option, false);
}

std::vector<tooie::picture_filters::CostEffect> tooie::picture_filters::cost_effects() {
    std::vector<CostEffect> effects;
    if (!created) {
        return effects;
    }
    auto add = [&](const std::string* id, recomp::config::ConfigValueVariant off) {
        try {
            if (graphics_config().get_option_value(*id) != off) {
                effects.push_back({ id, graphics_config().get_option(*id).name, off });
            }
        } catch (...) {
        }
    };
    for (const PresetValue& preset : preset_values) {
        // SMAA, FXAA and FSR read their own settings (and have their own lines in the overlay); the
        // sub-settings that only change how an effect looks are left as they are.
        if ((preset.id == &tooie::smaa::option) || (preset.id == &tooie::fxaa::option) || (preset.id == &tooie::fsr::option) ||
            (preset.id == &three_point_option) || (preset.id == &parallax_original_option) || (preset.id == &ssr_stochastic_option)) {
            continue;
        }
        // The underwater ones only draw under water.
        if (((preset.id == &underwater_tint_option) || (preset.id == &underwater_haze_option) || (preset.id == &underwater_distortion_option)) &&
            (underwater() <= 0.0f)) {
            continue;
        }
        add(preset.id, preset.off);
    }
    // Ray tracing as a whole (its effects fall back to their screen-space forms), then its own extras.
    add(&ray_tracing_option, false);
    if (ray_tracing_active()) {
        add(&path_tracing_option, false);
        add(&traced_beams_option, 0.0);
        add(&ray_tracing_brdf_option, 0.0);
        add(&ray_tracing_subsurface_option, 0.0);
        add(&ray_tracing_hit_colours_option, false);
    }
    return effects;
}

void tooie::picture_filters::set_cost_override(const CostEffect* effect) {
    {
        std::lock_guard lock{ cost_mutex };
        cost_override_id = (effect != nullptr) ? effect->id : nullptr;
        if (effect != nullptr) {
            cost_override_value = effect->off;
        }
        cost_override_on.store(effect != nullptr, std::memory_order_relaxed);
    }
    apply();
}
