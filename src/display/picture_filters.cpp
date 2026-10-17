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
    void SetSceneGrassBlades(float thickness, float randomLength, bool chunky, float chunkSize, bool pixelated, float pixelSize, float blend);
    void SetSceneGrassTextures(const uint64_t *hashes, size_t count);
    void SetSceneGrassEdgeTextures(const uint64_t *hashes, size_t count);
    void SetSceneFur(float amount, float length, float density, float noisiness);
    void SetSceneKazooieFeathers(float amount, float size, float length, float density, float noisiness, float transparency);
    void SetSceneSnow(bool on, float height, bool strictColor);
    void SetSceneSnowStamps(const float *stamps, uint32_t count);
    void SetSceneParallax(float depth, bool all);
    void SetSceneParallaxTextures(const uint64_t *hashes, const uint8_t *ranges, size_t count);
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
    std::atomic<bool> sun_shadows{false};
    std::atomic<bool> kazooie_feathers{false};
    std::atomic<bool> enemy_fur{false};
    // Graphics > Deep snow and its height (1 normal); sent to RT64 only on a map with snow.
    std::atomic<bool> deep_snow{false};
    std::atomic<float> snow_height{1.0f};
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

    // Deep snow's other actors (note_snow_actor): where each was last frame, and whether it was falling.
    struct SnowActor { float x = 0.0f, y = 0.0f, z = 0.0f, scale = 1.0f; bool falling = false; };
    std::unordered_map<uint32_t, SnowActor> snow_actors_last;
    std::unordered_map<uint32_t, SnowActor> snow_actors_now;
    // Craters from attacks that landed, kept for a few frames so RT64 surely draws a frame with them.
    struct SnowCrater { float x, y, z, radius; int frames; };
    std::vector<SnowCrater> snow_craters;
    bool snow_actors_wanted = false;

    // This frame's stamps for RT64 from the actors drawn last frame: one walking along the ground presses a furrow,
    // one that was falling and stopped or went away (an attack landing) a crater.
    void send_snow_stamps(const float player[3], bool have_player) {
        std::vector<float> stamps;
        auto add = [&](float x, float y, float z, float radius, float depth) {
            if (stamps.size() / 5 >= 48) {
                return;
            }
            stamps.insert(stamps.end(), { x, y, z, radius, depth });
        };
        for (auto& [actor, now] : snow_actors_now) {
            const float radius = 12.0f * std::clamp(now.scale, 0.4f, 3.0f);
            // Banjo has his own trail.
            if (have_player && std::hypot(now.x - player[0], now.z - player[2]) < 8.0f && std::abs(now.y - player[1]) < 30.0f) {
                continue;
            }
            const auto last = snow_actors_last.find(actor);
            if (last == snow_actors_last.end()) {
                continue;
            }
            const float moved = std::hypot(now.x - last->second.x, now.z - last->second.z);
            const float dy = now.y - last->second.y;
            now.falling = (dy < -1.5f) || (last->second.falling && (dy < -0.2f));
            if (last->second.falling && !now.falling) {
                snow_craters.push_back({ now.x, now.y, now.z, radius * 1.4f, 3 });
            }
            else if ((moved > 0.3f) && (moved < 60.0f) && (std::abs(dy) < 4.0f)) {
                add(now.x, now.y, now.z, radius, 0.6f);
            }
        }
        for (const auto& [actor, last] : snow_actors_last) {
            if (last.falling && (snow_actors_now.find(actor) == snow_actors_now.end())) {
                snow_craters.push_back({ last.x, last.y, last.z, 12.0f * std::clamp(last.scale, 0.4f, 3.0f) * 1.4f, 3 });
            }
        }
        for (auto& crater : snow_craters) {
            add(crater.x, crater.y, crater.z, crater.radius, 0.9f);
            crater.frames--;
        }
        snow_craters.erase(std::remove_if(snow_craters.begin(), snow_craters.end(), [](const SnowCrater& c) { return c.frames <= 0; }), snow_craters.end());
        snow_actors_last = std::move(snow_actors_now);
        snow_actors_now.clear();
        RT64::SetSceneSnowStamps(stamps.data(), (uint32_t)(stamps.size() / 5));
    }

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

    // Stone with parallax mapping: walls, paving, brick and rock whose brightness reads as their shape (dark gaps and
    // cracks between lighter faces), picked by eye from a texture dump of every level. Moss, grass, wood, metal and
    // painted or lettered textures are left out: their dark parts aren't deeper. With each, its darkest and lightest brightness (0 to 255,
    // leaving out the darkest and lightest twentieth of its texels) from the same dump: its deepest and highest parts.
    struct ParallaxTexture {
        uint64_t hash;
        uint8_t darkest;
        uint8_t lightest;
    };
    constexpr ParallaxTexture parallax_textures[] = {
        { 0x006a53f12a6dd20c, 18, 108 },
        { 0x009e8657a28070fc, 7, 110 },
        { 0x016c50f3b51f9523, 0, 250 },
        { 0x0173a13e153c861a, 0, 91 },
        { 0x01a20bd62ff8cac0, 42, 151 },
        { 0x02b5cd0f24705794, 44, 201 },
        { 0x02e0da37956bb42f, 49, 170 },
        { 0x032d5042d010c49d, 8, 110 },
        { 0x039014c5f7f7ea13, 17, 236 },
        { 0x03db71e4568f5748, 36, 154 },
        { 0x042024796e55fdbc, 18, 91 },
        { 0x04da11e18c826c75, 28, 120 },
        { 0x056644ebac6fbddc, 8, 110 },
        { 0x05749d611ab935e0, 7, 143 },
        { 0x06a469b76bb4c087, 0, 214 },
        { 0x073071e9ef0574b7, 24, 182 },
        { 0x07898912ac01ba63, 25, 170 },
        { 0x092351194c1d7fde, 74, 166 },
        { 0x0a8ab18ab03849e9, 0, 162 },
        { 0x0c07e769b88ae3b9, 57, 159 },
        { 0x0d63ce2a735f9856, 15, 76 },
        { 0x0d6cc6ae8e0b6ada, 49, 173 },
        { 0x0e6d75d401b81308, 33, 140 },
        { 0x111ab27c1868db39, 42, 159 },
        { 0x1140c796753bd399, 7, 113 },
        { 0x114175582bfa83cc, 0, 111 },
        { 0x114782302a4b4161, 31, 149 },
        { 0x11fa704293b8565e, 0, 149 },
        { 0x122aedafd43e2a9e, 0, 134 },
        { 0x127daf28296ab861, 10, 137 },
        { 0x128837f2944a3283, 15, 144 },
        { 0x133010d9f09ec074, 44, 150 },
        { 0x13764347db5fb09e, 49, 174 },
        { 0x13b47e670150a364, 55, 157 },
        { 0x15999601cee2ba0f, 58, 166 },
        { 0x1740f25e08d7a4f0, 11, 152 },
        { 0x184ed47ff30463fb, 25, 129 },
        { 0x18767254f0e3ee1a, 10, 225 },
        { 0x1876a6e9ec585c9d, 44, 140 },
        { 0x1908c1102ecf9ead, 24, 178 },
        { 0x1954f93573c7319d, 68, 147 },
        { 0x19ca60a2f6755840, 10, 107 },
        { 0x1a0d7971ab2275d8, 7, 168 },
        { 0x1a7773fc099b83b4, 0, 234 },
        { 0x1bd9baa5f2f17fac, 13, 137 },
        { 0x1c0de8001f4b462c, 0, 69 },
        { 0x1cf577bcf120b2b6, 9, 219 },
        { 0x1d65da6219880aab, 0, 134 },
        { 0x1e1ee3ff71f15d16, 63, 203 },
        { 0x1e2790b1f6169b5f, 21, 128 },
        { 0x1ebcf8526dcfa985, 7, 124 },
        { 0x1eefa00761536012, 18, 111 },
        { 0x2047ab093f604e00, 36, 247 },
        { 0x20de52f743e5a323, 10, 100 },
        { 0x23a025da09940ab1, 25, 198 },
        { 0x23e3d7909b58a62e, 10, 200 },
        { 0x249b9cd5c2ba5d94, 52, 150 },
        { 0x254400c02ffd8896, 48, 116 },
        { 0x25457d3bb185de55, 15, 175 },
        { 0x268e0793d0460c67, 47, 162 },
        { 0x26a490d4fbdd412c, 17, 108 },
        { 0x27e39ebd724fa6fa, 7, 140 },
        { 0x28621a62c2f98de6, 15, 161 },
        { 0x28f2a101e74f0482, 7, 138 },
        { 0x29afa93f32d446fa, 7, 189 },
        { 0x29e022a606c437d5, 75, 165 },
        { 0x2a5cc30b0ca6b260, 23, 226 },
        { 0x2a9cf0a6c42633b3, 77, 200 },
        { 0x2ad4289996a301a5, 27, 207 },
        { 0x2ad64370d222517d, 2, 133 },
        { 0x2ae48b484bb37dcc, 7, 175 },
        { 0x2bb372b8886710e0, 23, 166 },
        { 0x2c717280b37a0c07, 24, 138 },
        { 0x2cefe335c40dace1, 24, 151 },
        { 0x2ede23f667c073fd, 0, 142 },
        { 0x2ee86a3a07b8ea74, 0, 139 },
        { 0x2fd04cbc57722e00, 13, 204 },
        { 0x2ffd7b1612896028, 13, 132 },
        { 0x3027a77c06a1ffad, 0, 78 },
        { 0x303e0ba577e48a3a, 29, 127 },
        { 0x3072d8a193d49b72, 15, 158 },
        { 0x3175bc9dbf49aeb8, 0, 154 },
        { 0x320323c422800ec7, 0, 73 },
        { 0x3361921e7386e1c3, 0, 136 },
        { 0x3387e8dfc7b38aeb, 0, 149 },
        { 0x354e3dc78c79296c, 52, 156 },
        { 0x35a06e91ca131dfc, 100, 156 },
        { 0x35cc6b8a85826f45, 15, 134 },
        { 0x35e91f2f8821467c, 48, 132 },
        { 0x35fdb637e2921a6d, 18, 106 },
        { 0x365d4549de37a8bb, 7, 119 },
        { 0x37bd8b12171468ac, 25, 165 },
        { 0x3840aa695cf2012a, 10, 133 },
        { 0x38ad2d2878cf7f1a, 66, 174 },
        { 0x38adc327779f9390, 41, 126 },
        { 0x3a39edf4d3cce92d, 49, 130 },
        { 0x3b0df0f0dc38c65b, 7, 206 },
        { 0x3b5ceddf7e529830, 0, 143 },
        { 0x3bb205c240c1c1af, 23, 129 },
        { 0x3ce6183f0d0ab5de, 0, 142 },
        { 0x3ceb70f3d433e802, 12, 134 },
        { 0x3d32bf6dd451b710, 28, 128 },
        { 0x3d356ee15a1b63be, 62, 171 },
        { 0x3dafd58477a2b999, 0, 230 },
        { 0x3df91cac0528deb1, 18, 110 },
        { 0x3e6e77d3665edcbc, 29, 156 },
        { 0x3ea8ed134c685def, 0, 202 },
        { 0x3ecf4dc800e023c1, 55, 140 },
        { 0x3ed94e7e3498d623, 68, 157 },
        { 0x3f827bede427e44c, 24, 119 },
        { 0x42a3b3aad545633a, 7, 131 },
        { 0x42bd4ae4b0ca5fab, 15, 106 },
        { 0x436c13d3fe918324, 26, 247 },
        { 0x43c2cdf7b01e2d1d, 56, 157 },
        { 0x4510e51116cab6ef, 2, 114 },
        { 0x454964434d348e3d, 27, 93 },
        { 0x456eb563cca743c3, 15, 158 },
        { 0x45cc3ed5b60cdd33, 48, 197 },
        { 0x48efa3236ca2d3d4, 7, 129 },
        { 0x492e569afa61de83, 31, 224 },
        { 0x4a7b1a2672b73a09, 49, 162 },
        { 0x4ad95e5cb1087bd7, 42, 122 },
        { 0x4aea5e10022f76be, 45, 165 },
        { 0x4c6ea40f6d5265d5, 17, 165 },
        { 0x4d2d6f78c97fdad4, 7, 149 },
        { 0x4da7be96b8e07a31, 172, 238 },
        { 0x4dbab2ad7c3c20bc, 7, 126 },
        { 0x4e4a14ab435ca64a, 35, 138 },
        { 0x4efcb48b8a87d0f2, 41, 132 },
        { 0x4f0baf7f20c7c1aa, 24, 191 },
        { 0x4fc1a51479e79a58, 24, 180 },
        { 0x4fc67ab2b7940f66, 12, 165 },
        { 0x505799bc4edffd9f, 77, 181 },
        { 0x505fb4c4fdca9135, 0, 143 },
        { 0x513c4c204c6e5a40, 17, 135 },
        { 0x5168a881c0fd9082, 22, 153 },
        { 0x520da5015f653d7f, 0, 139 },
        { 0x525708d5af93918d, 76, 165 },
        { 0x529ba621c60ce6d2, 49, 141 },
        { 0x52e1b54465e2825b, 44, 160 },
        { 0x54788e2104404b19, 41, 149 },
        { 0x557e17c8fb6790ab, 7, 247 },
        { 0x5644f928f27e1626, 0, 161 },
        { 0x565d41f359f6ec9c, 21, 164 },
        { 0x56999a939e83fb09, 7, 147 },
        { 0x56b463c9691b7f67, 17, 106 },
        { 0x578fbef0e500e924, 23, 142 },
        { 0x58d52d89183d8867, 0, 158 },
        { 0x5902dec10eea92fe, 15, 157 },
        { 0x5942c0f010806cf6, 15, 169 },
        { 0x5947282ba5809902, 7, 168 },
        { 0x599aea4c3931c866, 0, 143 },
        { 0x5b83974b5f81f0ad, 7, 200 },
        { 0x5b8466278bb1da3a, 7, 132 },
        { 0x5c480c7d2e021e9d, 24, 220 },
        { 0x5c9f11e79a73d8fa, 7, 150 },
        { 0x5d4e036bf0b4a509, 31, 202 },
        { 0x5e0c251a746c396c, 25, 156 },
        { 0x5e0cec64f07852c5, 0, 141 },
        { 0x624aba45ab5e4757, 12, 189 },
        { 0x635240385dc466c7, 56, 170 },
        { 0x635bdf5f8d1be6b7, 15, 103 },
        { 0x63c8c0806df5ae64, 10, 108 },
        { 0x63d87cd06523523f, 0, 143 },
        { 0x646d9b3e801a5087, 60, 170 },
        { 0x64b0f7daac85ce13, 18, 192 },
        { 0x64be724a850d5113, 7, 133 },
        { 0x64c948d225f75cd4, 0, 158 },
        { 0x64fa34406d493da1, 15, 159 },
        { 0x65f74ffea0da59a1, 15, 145 },
        { 0x66a3343d6189ffd4, 21, 157 },
        { 0x6716c8bac2d0dee0, 15, 189 },
        { 0x675ec03cbd102f4f, 0, 79 },
        { 0x67a497b0808dbd05, 58, 160 },
        { 0x68dbdb32fd236996, 7, 129 },
        { 0x690254c6bebbc8e8, 26, 200 },
        { 0x69a19da23c9e3873, 46, 108 },
        { 0x69a5881f88e8ff5c, 24, 127 },
        { 0x6a323fe0717f9018, 7, 200 },
        { 0x6c3dbea350dc773e, 15, 153 },
        { 0x6c9813f82d5b1c78, 44, 154 },
        { 0x6d1a501355215448, 84, 155 },
        { 0x6d2e592bea2b1e66, 35, 162 },
        { 0x6de009975e3d0b67, 17, 108 },
        { 0x6f04502ef762b0c7, 106, 177 },
        { 0x6ffd2936379fb8be, 0, 142 },
        { 0x704bafee2fa58d87, 29, 162 },
        { 0x7179031051659818, 58, 128 },
        { 0x71b30bddb0dbacdb, 0, 113 },
        { 0x71e54e70b5da42f8, 15, 140 },
        { 0x7272cd0e77e2daf8, 26, 102 },
        { 0x730317da2236f486, 17, 111 },
        { 0x7391d2cf03710f7e, 0, 178 },
        { 0x742b91dbb8ae10fa, 51, 154 },
        { 0x74ce782e12042c68, 41, 134 },
        { 0x7501de36382aafd3, 0, 237 },
        { 0x751c0f4afa17b201, 0, 99 },
        { 0x757bc39fd7da2fe0, 7, 80 },
        { 0x76693826c96a8a3a, 15, 162 },
        { 0x7905224bdc01abf6, 0, 155 },
        { 0x7982859f91bf9080, 47, 128 },
        { 0x79f2f2d1b02fbb3f, 24, 225 },
        { 0x79f8fd0432a49806, 55, 140 },
        { 0x7a8e1e56ff5d0fe3, 34, 182 },
        { 0x7aa05d0faacbc01f, 7, 150 },
        { 0x7af90558bdbfa183, 0, 101 },
        { 0x7b31d535b644f17e, 21, 143 },
        { 0x7bcaebd9ab47a8c6, 7, 158 },
        { 0x7be6af50e6bbe865, 26, 133 },
        { 0x7d9bc6137ccfee5c, 0, 163 },
        { 0x7db567da51fc6184, 0, 100 },
        { 0x7e190f2730965ad0, 0, 123 },
        { 0x7e1b9bc8ac386491, 21, 167 },
        { 0x7f290c1d485d0efb, 12, 106 },
        { 0x7ffe5155c26da7e2, 0, 149 },
        { 0x803deb358181cae6, 24, 194 },
        { 0x807633d5a0444700, 45, 154 },
        { 0x80c4e4b432d14a7a, 12, 171 },
        { 0x81724e18c99b9531, 39, 150 },
        { 0x8249755c8c108c1d, 15, 168 },
        { 0x83224706a3b80c1b, 7, 141 },
        { 0x837446c54f42960d, 0, 139 },
        { 0x848b3104cf070678, 40, 111 },
        { 0x84b1036154def46a, 0, 186 },
        { 0x84bf735b55ad9076, 24, 185 },
        { 0x869f9ca80defadce, 54, 173 },
        { 0x86acdb6b0bc1e981, 33, 119 },
        { 0x86eeeba15f421833, 21, 162 },
        { 0x87c19a9f691b6298, 0, 111 },
        { 0x87f8cb282b32b064, 47, 204 },
        { 0x88a6c9a7f3d17bf6, 0, 128 },
        { 0x8ac8233b6a252763, 15, 133 },
        { 0x8b1712b52c844067, 7, 154 },
        { 0x8b3465298adb5dc2, 56, 188 },
        { 0x8b59806860709424, 31, 247 },
        { 0x8dabd3fa797e94e2, 49, 174 },
        { 0x8e41b04b99a602ef, 7, 130 },
        { 0x8e6a8bc02e6dc442, 0, 100 },
        { 0x8f5c2b4231d5b6c2, 31, 136 },
        { 0x8fc35b86286ef823, 10, 100 },
        { 0x91dc63433e7132c8, 97, 168 },
        { 0x933463bd04326f81, 18, 110 },
        { 0x9340e6610e77a148, 31, 190 },
        { 0x93a1957667906742, 27, 146 },
        { 0x93c513b27b0bc1cc, 66, 173 },
        { 0x9409c9b31ea68a7b, 12, 134 },
        { 0x94bd29b74e9a3736, 10, 193 },
        { 0x94cbff261d18ba58, 0, 179 },
        { 0x958318165d86fdf6, 75, 182 },
        { 0x9857bbf60edc979c, 16, 95 },
        { 0x98cd9fff48e72dd5, 47, 140 },
        { 0x99a77f779f130652, 0, 133 },
        { 0x99a8168efe4ab39e, 18, 85 },
        { 0x99c74403eaa03e91, 18, 78 },
        { 0x9abf7873bffea7a3, 12, 137 },
        { 0x9b6a3475689e17e3, 25, 155 },
        { 0x9caa8d076b098d97, 17, 104 },
        { 0x9cd6a08c1c787ab6, 3, 137 },
        { 0x9d509697d771dd69, 7, 159 },
        { 0x9d938c1c99d1f644, 36, 181 },
        { 0x9dfd9d7f943b778e, 33, 132 },
        { 0x9e54aaa6a4580c06, 27, 216 },
        { 0x9f06fb5f6adb8d56, 38, 139 },
        { 0x9f60f5f101610f3d, 42, 124 },
        { 0x9fa67f767a2d583d, 7, 147 },
        { 0x9fb9a23dea2871ee, 0, 101 },
        { 0x9ff47835f3cfef24, 74, 166 },
        { 0xa0393d4bafb9a1a3, 0, 171 },
        { 0xa08c0479242935a7, 7, 158 },
        { 0xa143bc99822bbca3, 0, 144 },
        { 0xa1c7296ecda0c10b, 36, 126 },
        { 0xa2c006363284479d, 63, 197 },
        { 0xa2fbd406fcc82afa, 0, 160 },
        { 0xa32b519f2aaec955, 101, 219 },
        { 0xa3c4d099db9c7b85, 12, 145 },
        { 0xa3fc446d1590570c, 7, 82 },
        { 0xa415017d816e8c8a, 21, 178 },
        { 0xa455894091918abc, 15, 157 },
        { 0xa47b7057aa363cb6, 0, 149 },
        { 0xa4aee8d715ca78c9, 66, 169 },
        { 0xa4bec532754a7fef, 74, 166 },
        { 0xa4e70087129de191, 0, 124 },
        { 0xa509255f2664aef8, 41, 99 },
        { 0xa6aa8fd8983de63e, 70, 162 },
        { 0xa6c8788d0c50de4a, 0, 139 },
        { 0xa70e1c9a0236b70a, 4, 150 },
        { 0xa940fd6b4a60e3a3, 26, 254 },
        { 0xa9690b65ed36091c, 63, 172 },
        { 0xa9dcd8fd124b828a, 24, 94 },
        { 0xaa4fb767534de6b1, 0, 160 },
        { 0xabc507d3fc53778b, 0, 152 },
        { 0xac10bb8e872631a3, 15, 175 },
        { 0xac218b43a6d21568, 15, 111 },
        { 0xac53c39d18b1002d, 41, 176 },
        { 0xacdfca0076008f4a, 7, 124 },
        { 0xaceee5e898f23f85, 130, 225 },
        { 0xad0c2d276f949ed2, 15, 172 },
        { 0xae1c01f3a5f4259e, 0, 169 },
        { 0xaef9b50089cd8e31, 33, 157 },
        { 0xb0aaf35ff7a9537f, 24, 217 },
        { 0xb274adf310bd4283, 33, 166 },
        { 0xb28100d5df745365, 0, 104 },
        { 0xb3904d875784e0a5, 66, 165 },
        { 0xb3b06d5b88831d93, 0, 143 },
        { 0xb47f50da39d5c0f3, 10, 148 },
        { 0xb61057728ec94d45, 8, 96 },
        { 0xb63015dade4ccf05, 56, 169 },
        { 0xb6640fc75e630756, 0, 121 },
        { 0xb6fcd67489647e96, 18, 108 },
        { 0xb717793fa34a1632, 0, 151 },
        { 0xb7b1698056c3cc29, 0, 150 },
        { 0xb7e8e326c474cb60, 40, 114 },
        { 0xb8f45a0b0594cd67, 7, 126 },
        { 0xb97617bcad095426, 54, 134 },
        { 0xb99861018e26672a, 41, 149 },
        { 0xba28e99c898a0601, 44, 118 },
        { 0xbadfc8c99a7ba54a, 44, 162 },
        { 0xbaf0e9ae06c533c4, 56, 156 },
        { 0xbba4fefc4b7d49eb, 10, 247 },
        { 0xbbc18c841f359a8f, 47, 186 },
        { 0xbdb943cddf7a8aaf, 0, 191 },
        { 0xbf27855f92dba7b6, 2, 163 },
        { 0xbfdb7d5617ff07d6, 18, 125 },
        { 0xc1575dd48f3a72df, 33, 157 },
        { 0xc2415572a9927224, 0, 152 },
        { 0xc2bcbf9cc24db01c, 100, 186 },
        { 0xc3ce45257edceaa6, 35, 115 },
        { 0xc42ffaff478d9471, 12, 110 },
        { 0xc4f45c0707948a59, 54, 198 },
        { 0xc6fd346ff864d089, 36, 162 },
        { 0xc727761fce953f65, 63, 171 },
        { 0xc743777e651e64d6, 10, 116 },
        { 0xc76366f7f49725fa, 0, 74 },
        { 0xc76d77e9d247d5ac, 0, 99 },
        { 0xc7c4a14fbe697e13, 55, 170 },
        { 0xc84774c4aec58a24, 11, 153 },
        { 0xc910cbda075e2e88, 0, 149 },
        { 0xc95e5fa9fd513384, 40, 109 },
        { 0xca0fbf643d425952, 49, 166 },
        { 0xcaa8e7967450a381, 49, 109 },
        { 0xcaab85e3af47d3ca, 48, 130 },
        { 0xcad7f1fe05318307, 49, 114 },
        { 0xcb738fa74eaaa007, 0, 144 },
        { 0xcbaa9fa3bc466415, 7, 158 },
        { 0xcbb37a01a88b8dd6, 88, 211 },
        { 0xcbe1191638d658c5, 27, 157 },
        { 0xcc837d40b0a45053, 15, 199 },
        { 0xcd07a7dd6e04ede7, 18, 172 },
        { 0xcdbe0c5100aaab94, 0, 117 },
        { 0xcdcb858c01d2720c, 57, 178 },
        { 0xce7195375ad16a07, 11, 194 },
        { 0xcebb441714f8c0f6, 27, 136 },
        { 0xcf26476397c300e3, 16, 99 },
        { 0xcf3cba69a25477e0, 60, 168 },
        { 0xcf6ef877cce4b28f, 0, 142 },
        { 0xd16d388540a6e872, 7, 139 },
        { 0xd1ecdca19a7ff57f, 58, 174 },
        { 0xd20f10985adda329, 23, 158 },
        { 0xd27c1e27812bfcd8, 17, 187 },
        { 0xd28c4a3bda75d471, 18, 119 },
        { 0xd343efe79ef2103b, 31, 160 },
        { 0xd3fb04e8290eb89f, 46, 191 },
        { 0xd43233920209a202, 20, 132 },
        { 0xd47c56aae92d3f79, 15, 164 },
        { 0xd48dbc4653da6b34, 34, 154 },
        { 0xd4c5767aaf3208a4, 10, 204 },
        { 0xd69de71b5d2d5f61, 20, 154 },
        { 0xd719b033ae602af7, 18, 201 },
        { 0xd73f1e47a889a996, 15, 156 },
        { 0xd746c3304d93396c, 18, 117 },
        { 0xd7fe8981528bcefe, 0, 220 },
        { 0xd88901e0ba47e0c9, 0, 143 },
        { 0xd973a4f18333c919, 31, 133 },
        { 0xda7adf867f3c87c4, 21, 173 },
        { 0xda8b6db8d2294e25, 60, 165 },
        { 0xdb053495566a2d30, 0, 215 },
        { 0xdcc0f0a5ecbeb211, 10, 111 },
        { 0xdce42ff103ee07a9, 0, 82 },
        { 0xdd73116daf40b90e, 26, 95 },
        { 0xdd96acc525117fe8, 0, 107 },
        { 0xdde879987590af41, 21, 151 },
        { 0xddf434e3d92f546c, 58, 174 },
        { 0xde2e2dbc083d9bae, 15, 217 },
        { 0xde7dd744beec8a79, 0, 79 },
        { 0xdea93024c15621de, 0, 133 },
        { 0xdf5c2c0101502a0f, 26, 114 },
        { 0xe035f3e25d5be463, 0, 130 },
        { 0xe06888b2909a38c7, 31, 247 },
        { 0xe113238425323c08, 67, 185 },
        { 0xe140f211206bb23b, 18, 136 },
        { 0xe15ed130c91a440c, 15, 176 },
        { 0xe19ee99a7eb8bda3, 10, 159 },
        { 0xe1a77418ed910c5a, 0, 147 },
        { 0xe3fe605fff2a96c7, 0, 174 },
        { 0xe4d268df501d8181, 42, 160 },
        { 0xe4e83c396d6fd5c7, 0, 100 },
        { 0xe50e3d6fab056885, 60, 156 },
        { 0xe56baa9bac52c5ce, 15, 129 },
        { 0xe5fa50c406c62f28, 18, 78 },
        { 0xe5fd84050af1238c, 24, 207 },
        { 0xe6144dde451feb08, 0, 129 },
        { 0xe7e51d822ee1076a, 17, 193 },
        { 0xe94bf2c6e32f2cdf, 48, 137 },
        { 0xe94e47c49eecbad5, 0, 152 },
        { 0xe9e4e937cb4c51db, 10, 118 },
        { 0xea5ac88c59f20696, 0, 158 },
        { 0xeae1817da4af7272, 12, 110 },
        { 0xeba809fec834f467, 81, 165 },
        { 0xebee14f7ba40e49f, 26, 145 },
        { 0xeca4591a3dbd2fcc, 44, 162 },
        { 0xed007ae11f0b6d8e, 15, 158 },
        { 0xeed8093f625587b2, 25, 131 },
        { 0xefa2c7d3c016758f, 67, 202 },
        { 0xefeb69fba0f2379f, 0, 151 },
        { 0xf00cf99dd2cba95d, 21, 164 },
        { 0xf0545865e49b668c, 33, 165 },
        { 0xf11fed1def3950dc, 0, 102 },
        { 0xf173be7d0b4b5078, 43, 131 },
        { 0xf2e2dfc6a356b577, 89, 241 },
        { 0xf3d5dbbcf85d0e81, 7, 164 },
        { 0xf4b9df9d9935eaaf, 57, 125 },
        { 0xf4f04be02044bd0c, 40, 176 },
        { 0xf5f41410c0c1086f, 25, 116 },
        { 0xf61b800146839354, 18, 125 },
        { 0xf768e0003567ae5c, 41, 140 },
        { 0xf780e70328751036, 31, 151 },
        { 0xf8c1aa1fa125a8ca, 10, 247 },
        { 0xf8cdb968b4027b9e, 35, 201 },
        { 0xf9140cd61642a49e, 0, 116 },
        { 0xf915003e0a22d033, 15, 175 },
        { 0xf940a34f148c43e9, 7, 132 },
        { 0xf9451942ba08cae9, 0, 125 },
        { 0xf97b2b9993f6d07c, 8, 110 },
        { 0xf9d3f21d9381a0dd, 18, 82 },
        { 0xfa2aacd51251f6d6, 15, 176 },
        { 0xfbdf0c3fc9562611, 42, 126 },
        { 0xfef5c06c42fcce74, 56, 132 },
        { 0xffa181ae3dd430a0, 31, 147 },
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
        { &tooie::picture_filters::parallax_option, 0.0 },
        { &tooie::picture_filters::banjo_fur_option, 0.0 },
        { &tooie::picture_filters::kazooie_feathers_option, 0.0 },
        { &tooie::picture_filters::enemy_fur_option, false },
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
    RT64::SetSceneLightShafts((float)(value<double>(light_shafts_option, 0.0) / 100.0));
    sun_shadows = value<double>(sun_shadows_option, 0.0) > 0.0;
    RT64::SetSceneSunShadows((float)(value<double>(sun_shadows_option, 0.0) / 100.0), value<bool>(sun_shadow_banjo_option, true),
        (float)(value<double>(sun_shadow_softness_option, 60.0) / 100.0));
    RT64::SetSceneGrass((float)(value<double>(grass_option, 0.0) / 100.0), (float)(value<double>(grass_height_option, 100.0) / 100.0),
        (float)value<double>(grass_distance_option, 2500.0), (float)(value<double>(grass_density_option, 100.0) / 100.0),
        (float)(value<double>(grass_patches_option, 50.0) / 100.0));
    RT64::SetSceneGrassBlades((float)(value<double>(grass_thickness_option, 100.0) / 100.0),
        (float)(value<double>(grass_random_length_option, 40.0) / 100.0), value<bool>(grass_chunky_option, false),
        (float)(value<double>(grass_chunk_size_option, 200.0) / 100.0), value<bool>(grass_pixelated_option, false),
        (float)value<double>(grass_pixel_size_option, 1.0), (float)(value<double>(grass_blend_option, 50.0) / 100.0));
    RT64::SetSceneGrassTextures(grass_textures, std::size(grass_textures));
    RT64::SetSceneGrassEdgeTextures(grass_edge_textures, value<bool>(grass_edges_option, true) ? std::size(grass_edge_textures) : 0);
    double fur = value<double>(banjo_fur_option, 0.0);
    if (const char* forced = std::getenv("TOOIE_BANJO_FUR")) {
        fur = std::atof(forced);
    }
    banjo_fur = fur > 0.0;
    // Furry enemies (the yetis); TOOIE_ENEMY_FUR=1 turns it on instead (headless). Their fur is Banjo's at full
    // thickness when his is off.
    bool enemies = value<bool>(enemy_fur_option, false);
    if (const char* forced = std::getenv("TOOIE_ENEMY_FUR")) {
        enemies = std::atoi(forced) != 0;
    }
    enemy_fur = enemies;
    if (!banjo_fur && enemies) {
        fur = 100.0;
    }
    RT64::SetSceneFur((float)(fur / 100.0), (float)(value<double>(banjo_fur_length_option, 100.0) / 100.0),
        (float)(value<double>(banjo_fur_density_option, 100.0) / 100.0), (float)(value<double>(banjo_fur_noisiness_option, 50.0) / 100.0));
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
    bool snow = shaders && value<bool>(deep_snow_option, false);
    if (const char* forced = std::getenv("TOOIE_DEEP_SNOW")) {
        snow = std::atoi(forced) != 0;
    }
    deep_snow = snow;
    snow_height = (float)(value<double>(snow_height_option, 100.0) / 100.0);
    if (const char* forced = std::getenv("TOOIE_SNOW_HEIGHT")) {
        snow_height = (float)(std::atof(forced) / 100.0);
    }
    snow_sent = -1.0f;
    // Parallax mapping; TOOIE_PARALLAX=<0-100> sets it instead, TOOIE_PARALLAX_ALL=1 puts it on every texture of the
    // 3D world (headless, to find textures that suit it).
    double parallax = shader(value<double>(parallax_option, 0.0));
    if (const char* forced = std::getenv("TOOIE_PARALLAX")) {
        parallax = std::atof(forced);
    }
    const char* parallax_all = std::getenv("TOOIE_PARALLAX_ALL");
    RT64::SetSceneParallax((float)(parallax / 100.0), (parallax_all != nullptr) && (std::atoi(parallax_all) != 0));
    static const auto parallax_lists = [] {
        std::pair<std::vector<uint64_t>, std::vector<uint8_t>> lists;
        for (const ParallaxTexture& texture : parallax_textures) {
            lists.first.push_back(texture.hash);
            lists.second.push_back(texture.darkest);
            lists.second.push_back(texture.lightest);
        }
        return lists;
    }();
    RT64::SetSceneParallaxTextures(parallax_lists.first.data(), parallax_lists.second.data(), parallax_lists.first.size());
    modern_water = shaders && value<uint32_t>(water_option, (uint32_t)Water::Original) == (uint32_t)Water::Modern;
    if (const char* forced = std::getenv("TOOIE_MODERN_WATER")) {
        modern_water = std::atoi(forced) != 0;
    }
    RT64::SetSceneModernWater(modern_water);
    bool shore_foam = shaders && value<bool>(shore_foam_option, false);
    if (const char* forced = std::getenv("TOOIE_SHORE_FOAM")) {
        shore_foam = std::atoi(forced) != 0;
    }
    RT64::SetSceneShoreFoam(shore_foam);
    water_waves_on = (shader(value<double>(water_waves_option, 0.0)) > 0.0) || modern_water;
    RT64::SetSceneWaterWaves((float)(shader(value<double>(water_waves_option, 0.0)) / 100.0), (float)(value<double>(wave_speed_option, 100.0) / 100.0));
    RT64::SetSceneWaterReflections((float)(shader(value<double>(water_reflections_option, 0.0)) / 100.0));
    RT64::SetSceneRimLight((float)(shader(value<double>(rim_light_option, 0.0)) / 100.0));
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

bool tooie::picture_filters::banjo_fur_on() {
    return banjo_fur;
}

bool tooie::picture_filters::sun_shadows_on() {
    return sun_shadows;
}

bool tooie::picture_filters::kazooie_feathers_on() {
    return kazooie_feathers;
}

bool tooie::picture_filters::enemy_fur_on() {
    return enemy_fur;
}

float tooie::picture_filters::underwater() {
    return underwater_shared;
}

bool tooie::picture_filters::applying_effects_preset() {
    return applying_preset;
}

void tooie::picture_filters::note_snow_actor(uint32_t actor, float x, float y, float z, float scale) {
    if (!snow_actors_wanted || !std::isfinite(x) || !std::isfinite(y) || !std::isfinite(z)) {
        return;
    }
    snow_actors_now[actor] = { x, y, z, std::isfinite(scale) ? scale : 1.0f, false };
    // Test aid: TOOIE_SNOW_LOG=1 also counts the actors seen, every 2 s.
    static const bool log = std::getenv("TOOIE_SNOW_LOG") != nullptr;
    if (log) {
        static auto logged = std::chrono::steady_clock::now();
        static uint32_t seen = 0;
        seen++;
        if (std::chrono::steady_clock::now() - logged > std::chrono::seconds(2)) {
            logged = std::chrono::steady_clock::now();
            std::fprintf(stderr, "[snow] %u actor draws seen (last 2 s), e.g. %08X at %.0f %.0f %.0f scale %.2f\n", seen, actor, x, y, z, scale);
            seen = 0;
        }
    }
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

    // Deep snow on the maps with snow only.
    {
        const uint16_t map = (uint16_t)MEM_HU(0, (int32_t)0x80132DC2);
        const float snow = (deep_snow && snowy_map(map)) ? snow_height.load() : 0.0f;
        // Icy Side has pale ice beside its snow; elsewhere the snow is bluer.
        const bool strict = (map == 0x128);
        static bool strict_sent = true;
        if ((snow != snow_sent.load()) || (strict != strict_sent)) {
            snow_sent = snow;
            strict_sent = strict;
            RT64::SetSceneSnow(snow > 0.0f, snow, strict);
        }
        snow_actors_wanted = snow > 0.0f;
        if (snow_actors_wanted) {
            float pos[3];
            const bool valid = banjo_position(rdram, pos);
            send_snow_stamps(pos, valid);
        }
        else if (!snow_actors_last.empty() || !snow_actors_now.empty() || !snow_craters.empty()) {
            snow_actors_last.clear();
            snow_actors_now.clear();
            snow_craters.clear();
            RT64::SetSceneSnowStamps(nullptr, 0);
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
        "Sets all the picture effects below at once. <recomp-color primary>Vanilla</recomp-color> turns them all off, so none of the effect shaders run. <recomp-color primary>Enhanced</recomp-color> adds SMAA, ambient occlusion and sharpening. <recomp-color primary>Retro</recomp-color> gives N64 16-bit colour and a CRT look. Changing any of them yourself makes it <recomp-color primary>Custom</recomp-color>.",
        {
            {Preset::Custom, "Custom", "Custom"},
            {Preset::Original, "Original", "Vanilla"},
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
        "Turns on the lighting, water and other effects below and shows their settings. Off plays the game without them (their settings are kept for when you turn it back on).",
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
        parallax_option,
        "Parallax",
        "Stone walls, paving and rock get depth: the stones stand out of the surface and the gaps and cracks between them sink in, shifting as the camera moves, instead of looking painted on. The textures have no depth of their own, so it is worked out from how dark each part is. Higher numbers are deeper. Drawn on the picture, so nothing in the game changes. 0 is off.",
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
    graphics.add_bool_option(
        enemy_fur_option,
        "Enemy fur",
        "Furry enemies grow white fur like Banjo's: the yetis on Hailfire Peaks' Icy Side. It is as long and thick as Banjo's fur is set to.",
        false);
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

    for (const std::string* id : { &brightness_option, &brightness_pattern_option, &colourblind_option, &colourblind_strength_option,
                                   &three_point_option, &dither16_option, &crt_option, &sharpen_option, &contrast_option,
                                   &saturation_option, &vignette_option, &grain_option, &ambient_occlusion_option,
                                   &fog_option, &fog_start_option, &fog_colour_option, &outlines_option, &outline_thickness_option, &bloom_option, &cutscene_dof_option, &gameplay_dof_option,
                                   &eye_adaptation_option, &rim_light_option, &underwater_tint_option, &underwater_haze_option, &heat_haze_option, &underwater_distortion_option, &water_reflections_option, &bounce_light_option, &texture_upscale_option, &water_waves_option, &wave_speed_option, &light_shafts_option, &sun_shadows_option, &sun_shadow_banjo_option, &sun_shadow_softness_option, &grass_option, &grass_height_option, &grass_distance_option, &grass_density_option, &grass_patches_option, &grass_thickness_option, &grass_random_length_option, &grass_blend_option, &grass_chunky_option, &grass_chunk_size_option, &grass_pixelated_option, &grass_pixel_size_option, &grass_edges_option, &deep_snow_option, &snow_height_option, &parallax_option, &banjo_fur_option, &banjo_fur_length_option, &banjo_fur_density_option, &banjo_fur_noisiness_option, &kazooie_feathers_option, &kazooie_feather_size_option, &kazooie_feather_length_option, &kazooie_feather_density_option, &kazooie_feather_noisiness_option, &kazooie_feather_transparency_option, &enemy_fur_option, &water_option, &shore_foam_option, &lighting_section_option }) {
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
    graphics.add_option_hidden_dependency(grass_blend_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_chunky_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_pixelated_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_chunk_size_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_pixel_size_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(grass_edges_option, grass_section_option, false);
    graphics.add_option_hidden_dependency(deep_snow_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(snow_height_option, lighting_section_option, false);
    graphics.add_option_hidden_dependency(parallax_option, lighting_section_option, false);
    // Banjo's fur and Kazooie's feathers sit in their own Character Shaders section (L, 2026-10-16).
    for (const std::string* option : { &banjo_fur_option, &banjo_fur_length_option, &banjo_fur_density_option, &banjo_fur_noisiness_option, &kazooie_feathers_option, &kazooie_feather_size_option, &kazooie_feather_length_option, &kazooie_feather_density_option, &kazooie_feather_noisiness_option, &kazooie_feather_transparency_option, &enemy_fur_option }) {
        graphics.add_option_hidden_dependency(*option, character_section_option, false);
    }
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
