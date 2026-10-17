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
    void SetSceneParallax(float depth, bool original, bool all);
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

    // Textures with parallax mapping: stone walls, paving, brick, rock, cliff and rocky ground, and (from a second sweep)
    // plank walls and crates, roof tiles, scales and carved or embossed panels, whose brightness reads as their shape
    // (dark gaps, grooves and cracks between lighter faces), picked by eye from a texture dump of every level (1,690 of
    // its 7,259 textures). Grass, smooth metal and painted or lettered textures are left out: their dark parts aren't
    // deeper. With each, its darkest and lightest brightness (0 to 255,
    // leaving out the darkest and lightest twentieth of its texels) from the same dump: its deepest and highest parts.
    struct ParallaxTexture {
        uint64_t hash;
        uint8_t darkest;
        uint8_t lightest;
    };
    constexpr ParallaxTexture parallax_textures[] = {
        { 0x00207baf52ab5405, 7, 67 },
        { 0x006a53f12a6dd20c, 18, 108 },
        { 0x008c827b2cf0fbee, 42, 170 },
        { 0x009e8657a28070fc, 7, 110 },
        { 0x00aff12ed28a389e, 0, 214 },
        { 0x00b9e69db35b807a, 19, 235 },
        { 0x00f26da1eca0d558, 75, 137 },
        { 0x010f63904c0d8e53, 17, 170 },
        { 0x0111c6b86ede0ade, 7, 151 },
        { 0x016c50f3b51f9523, 0, 250 },
        { 0x0173a13e153c861a, 0, 91 },
        { 0x01a19f3502e26679, 28, 203 },
        { 0x01a20bd62ff8cac0, 42, 151 },
        { 0x01c5286172432ffe, 21, 72 },
        { 0x023abf7c9623e683, 32, 180 },
        { 0x0242ac7fbca6be7c, 21, 73 },
        { 0x027cfdcd168638fc, 5, 110 },
        { 0x029446ed12503659, 7, 130 },
        { 0x02b5cd0f24705794, 44, 201 },
        { 0x02d8c6bdefef3e0e, 31, 232 },
        { 0x02e0da37956bb42f, 49, 170 },
        { 0x02f4c308663b9cdd, 27, 178 },
        { 0x032d5042d010c49d, 8, 110 },
        { 0x039014c5f7f7ea13, 17, 236 },
        { 0x03bbdd21c6a714b9, 0, 89 },
        { 0x03db71e4568f5748, 36, 154 },
        { 0x042024796e55fdbc, 18, 91 },
        { 0x042df1f4b226ffea, 0, 126 },
        { 0x045f7108a45e37f6, 29, 112 },
        { 0x04b38d61e33f692d, 36, 125 },
        { 0x04bb9d529d73fc93, 28, 146 },
        { 0x04da11e18c826c75, 28, 120 },
        { 0x04e71251efe9bf4f, 28, 100 },
        { 0x04ee57596d4b28a5, 10, 125 },
        { 0x04fd9bf3f7fb634c, 0, 160 },
        { 0x05285cc2ae45a6c4, 101, 208 },
        { 0x056644ebac6fbddc, 8, 110 },
        { 0x05749d611ab935e0, 7, 143 },
        { 0x0581557796590067, 17, 169 },
        { 0x0583a8b5a27a0f2f, 34, 107 },
        { 0x0587796c4d31d722, 24, 156 },
        { 0x0619db7ff8a981f1, 82, 177 },
        { 0x06943fa4078b534b, 0, 122 },
        { 0x06a469b76bb4c087, 0, 214 },
        { 0x070549b9291bc325, 11, 157 },
        { 0x073071e9ef0574b7, 24, 182 },
        { 0x076a73c9792e9159, 11, 113 },
        { 0x076b5bc2322742b8, 27, 102 },
        { 0x077d3ca17c2aab93, 21, 72 },
        { 0x07898912ac01ba63, 25, 170 },
        { 0x078c87ad49f47581, 51, 156 },
        { 0x07e2b487404b45ff, 35, 131 },
        { 0x07e3114757f361f7, 10, 158 },
        { 0x07fadb9ed6ad471f, 9, 115 },
        { 0x08b03b3917a0e53d, 0, 118 },
        { 0x08b8b691fe6624ca, 12, 117 },
        { 0x0907b72f10e10130, 42, 149 },
        { 0x090c7bb53421a5d8, 17, 85 },
        { 0x092351194c1d7fde, 74, 166 },
        { 0x0948d26fcc074602, 31, 109 },
        { 0x0963a8b4980537c9, 15, 113 },
        { 0x09d001eee961a505, 56, 172 },
        { 0x0a8ab18ab03849e9, 0, 162 },
        { 0x0aadc698877ce9c1, 17, 173 },
        { 0x0b48179bcf40c42a, 0, 204 },
        { 0x0b4f0f983b650d34, 12, 133 },
        { 0x0b89bb5e00b0a9a9, 45, 133 },
        { 0x0ba04cec6e510120, 56, 140 },
        { 0x0bbfca0a807b10fe, 0, 56 },
        { 0x0bee1300e82d7fe9, 16, 107 },
        { 0x0c07e769b88ae3b9, 57, 159 },
        { 0x0c122afe3131d183, 0, 151 },
        { 0x0c3d8e6c04be8c76, 41, 232 },
        { 0x0cb8f7b5fa258c0b, 27, 128 },
        { 0x0d13300aafa10c10, 50, 114 },
        { 0x0d37af26aaeb15b6, 97, 243 },
        { 0x0d63ce2a735f9856, 15, 76 },
        { 0x0d6cc6ae8e0b6ada, 49, 173 },
        { 0x0db43da5f245d34e, 17, 178 },
        { 0x0e61666be36c8681, 22, 94 },
        { 0x0e6d75d401b81308, 33, 140 },
        { 0x0e974c21aabbaae7, 24, 128 },
        { 0x0ea6b2ac63243fdf, 14, 165 },
        { 0x0ebbdf02942c77e7, 48, 233 },
        { 0x0ec1efbf5ae74d98, 11, 156 },
        { 0x0edfaf02879af5de, 39, 226 },
        { 0x0f47265a11157ba4, 21, 164 },
        { 0x0f634207ad561508, 20, 175 },
        { 0x101b67e86f3893fa, 4, 121 },
        { 0x101f4b499fe3d3f5, 0, 67 },
        { 0x10893c3bd73b6416, 25, 84 },
        { 0x10b2ea1809b77d5a, 7, 148 },
        { 0x10b94d91f8f5fc4a, 22, 119 },
        { 0x10dcb2c0ab82681a, 14, 102 },
        { 0x11127cba84729a83, 5, 83 },
        { 0x111ab27c1868db39, 42, 159 },
        { 0x112b6b8287194ac4, 51, 121 },
        { 0x1140c796753bd399, 7, 113 },
        { 0x114175582bfa83cc, 0, 111 },
        { 0x11449cf3a53749b9, 11, 157 },
        { 0x114782302a4b4161, 31, 149 },
        { 0x116af19cd2c300dc, 63, 215 },
        { 0x11a67bfad0df309f, 29, 147 },
        { 0x11b62abb87909103, 19, 182 },
        { 0x11c90c285da5ba84, 17, 209 },
        { 0x11d844c946fd5bd9, 35, 109 },
        { 0x11fa704293b8565e, 0, 149 },
        { 0x121cacd1869f6d0e, 26, 78 },
        { 0x122aedafd43e2a9e, 0, 134 },
        { 0x12341e9f3dc350f0, 7, 100 },
        { 0x1254af638b17791b, 24, 143 },
        { 0x127daf28296ab861, 10, 137 },
        { 0x128837f2944a3283, 15, 144 },
        { 0x12a01dce86076f8b, 0, 66 },
        { 0x132a903d7672de70, 0, 135 },
        { 0x133010d9f09ec074, 44, 150 },
        { 0x136db0f01dc11442, 17, 80 },
        { 0x1374ddbadc030f0c, 33, 74 },
        { 0x13764347db5fb09e, 49, 174 },
        { 0x13ab04610ebf4632, 7, 159 },
        { 0x13b2750824b2202e, 30, 132 },
        { 0x13b47e670150a364, 55, 157 },
        { 0x13c036e7abd0c772, 32, 161 },
        { 0x13e2a684ff459045, 88, 150 },
        { 0x14018832fcf55524, 36, 207 },
        { 0x14d0dd9bde7bdb6a, 18, 188 },
        { 0x14e5ef57e21fae5b, 35, 183 },
        { 0x151e5f17937c2e4f, 32, 161 },
        { 0x15999601cee2ba0f, 58, 166 },
        { 0x161ab8b4f1bf2946, 18, 222 },
        { 0x16d20762d85bed44, 34, 108 },
        { 0x16fa295c3bc277f2, 34, 135 },
        { 0x17233311b0615ad2, 31, 132 },
        { 0x1740f25e08d7a4f0, 11, 152 },
        { 0x177627a656018689, 41, 156 },
        { 0x17e89485732ff080, 22, 179 },
        { 0x18014201a9e8aeb8, 11, 146 },
        { 0x1802883858572e53, 0, 91 },
        { 0x18425abb87034a2d, 9, 123 },
        { 0x184ed47ff30463fb, 25, 129 },
        { 0x18767254f0e3ee1a, 10, 225 },
        { 0x1876a6e9ec585c9d, 44, 140 },
        { 0x18802e314f707546, 11, 140 },
        { 0x1897b801adce374a, 28, 139 },
        { 0x18a54811e1066b76, 25, 171 },
        { 0x18facd90790db747, 29, 73 },
        { 0x1908c1102ecf9ead, 24, 178 },
        { 0x191a787d7555e8ec, 2, 238 },
        { 0x1954f93573c7319d, 68, 147 },
        { 0x1982ec7379b81ba0, 45, 183 },
        { 0x19ca60a2f6755840, 10, 107 },
        { 0x1a0d7971ab2275d8, 7, 168 },
        { 0x1a1092ee16031d22, 126, 210 },
        { 0x1a72ccadffbe44cf, 14, 127 },
        { 0x1a7773fc099b83b4, 0, 234 },
        { 0x1a97b5d2b1c8fc7c, 17, 66 },
        { 0x1aa016c6c3535ee7, 25, 181 },
        { 0x1aba331288298a61, 0, 148 },
        { 0x1abfa29ff62afd58, 9, 159 },
        { 0x1ac9283ecbec37cf, 17, 106 },
        { 0x1b25f68a48a672cd, 35, 117 },
        { 0x1bb3ebe4bcb6e072, 7, 116 },
        { 0x1bc411ce2285f1f2, 10, 111 },
        { 0x1bd9baa5f2f17fac, 13, 137 },
        { 0x1c0de8001f4b462c, 0, 69 },
        { 0x1c2a9ea9ff441502, 0, 105 },
        { 0x1c77f41e6611307f, 68, 201 },
        { 0x1c801aa2ffd39655, 0, 126 },
        { 0x1ca8e1c62aab2958, 40, 151 },
        { 0x1cb455e939406b6e, 0, 152 },
        { 0x1cbce9fbfc67f8f1, 33, 206 },
        { 0x1cd8068e6bcc894d, 7, 144 },
        { 0x1ce159cf573ed433, 0, 105 },
        { 0x1cf577bcf120b2b6, 9, 219 },
        { 0x1d1be3fa4faed238, 63, 167 },
        { 0x1d65da6219880aab, 0, 134 },
        { 0x1d95a6340195d0fd, 20, 188 },
        { 0x1dfd70ab704b021a, 0, 151 },
        { 0x1e0f01ca6d40970c, 90, 206 },
        { 0x1e1ee3ff71f15d16, 63, 203 },
        { 0x1e2364ae05c62c38, 37, 162 },
        { 0x1e2790b1f6169b5f, 21, 128 },
        { 0x1e37817816ef83d4, 37, 210 },
        { 0x1e43fa7dfa7d915b, 52, 175 },
        { 0x1e6dd94ed8a990c8, 10, 133 },
        { 0x1e8a5cab889e2064, 21, 105 },
        { 0x1ebcf8526dcfa985, 7, 124 },
        { 0x1ecd9da1cd71b9c1, 14, 108 },
        { 0x1ed83f658c7847ca, 38, 96 },
        { 0x1eebf29d375d666e, 22, 167 },
        { 0x1eefa00761536012, 18, 111 },
        { 0x1f23e732ad1c087e, 29, 83 },
        { 0x1f23fd001952a893, 21, 67 },
        { 0x1f642febef0807d9, 34, 204 },
        { 0x1f7329662a94ec5a, 24, 134 },
        { 0x1fbc8134671de73e, 15, 155 },
        { 0x1fdc19958c228c7f, 105, 191 },
        { 0x2047ab093f604e00, 36, 247 },
        { 0x20a7e9c989f3dcfc, 30, 116 },
        { 0x20de52f743e5a323, 10, 100 },
        { 0x20e6bd7ef8f9cc54, 0, 187 },
        { 0x210ec922b8fd22ff, 29, 125 },
        { 0x2147a623c7f969c5, 64, 117 },
        { 0x217bcdd8b080800f, 20, 98 },
        { 0x21b3744ca6fe7c02, 33, 159 },
        { 0x21ceab0812e99c55, 2, 111 },
        { 0x2204434e37303bf8, 17, 152 },
        { 0x22192b154844f2be, 0, 153 },
        { 0x22351bd331a5b5ab, 7, 156 },
        { 0x226edf6d94fe0a41, 2, 188 },
        { 0x22760748d9723119, 17, 156 },
        { 0x22a9b309f8b4fc87, 15, 170 },
        { 0x230c9131758d4ba7, 20, 171 },
        { 0x235dc89e116701d8, 32, 92 },
        { 0x237048ef667d8a70, 32, 149 },
        { 0x238b97fae060c8f8, 27, 140 },
        { 0x23a025da09940ab1, 25, 198 },
        { 0x23e3d7909b58a62e, 10, 200 },
        { 0x23f3f4080f184ce4, 30, 208 },
        { 0x2449ee8a63579727, 43, 111 },
        { 0x248aa036fc69695f, 0, 139 },
        { 0x249b9cd5c2ba5d94, 52, 150 },
        { 0x251bb9c42f8dddca, 16, 96 },
        { 0x254400c02ffd8896, 48, 116 },
        { 0x25457d3bb185de55, 15, 175 },
        { 0x257c9da8f87fafd7, 16, 155 },
        { 0x267df4b5979bc3a2, 2, 148 },
        { 0x268e0793d0460c67, 47, 162 },
        { 0x26a490d4fbdd412c, 17, 108 },
        { 0x271c67a54d422fde, 17, 171 },
        { 0x27773327f32d3637, 9, 90 },
        { 0x27e39ebd724fa6fa, 7, 140 },
        { 0x27f004c07ab108c9, 7, 158 },
        { 0x282ea347b50e0bac, 34, 100 },
        { 0x282fbeb862a85c9d, 7, 130 },
        { 0x28361c09062cae44, 62, 118 },
        { 0x2847ad566a599458, 99, 186 },
        { 0x28621a62c2f98de6, 15, 161 },
        { 0x2874016ef8106c8b, 27, 171 },
        { 0x28862d457543e7f7, 53, 134 },
        { 0x289a0fd56604a5de, 16, 139 },
        { 0x28c9aaebee1ba5c1, 17, 136 },
        { 0x28f2a101e74f0482, 7, 138 },
        { 0x29301132791f05a4, 37, 184 },
        { 0x293394aeaf0bf7f7, 21, 128 },
        { 0x299643e72e19a2fd, 25, 181 },
        { 0x29afa93f32d446fa, 7, 189 },
        { 0x29e022a606c437d5, 75, 165 },
        { 0x2a45ba63f86c03ed, 0, 94 },
        { 0x2a48c72207ef5f8b, 34, 137 },
        { 0x2a5cc30b0ca6b260, 23, 226 },
        { 0x2a81b88577db0aa0, 38, 140 },
        { 0x2a9cf0a6c42633b3, 77, 200 },
        { 0x2aaf3716f3e0cb89, 29, 122 },
        { 0x2ab2aa4811471a25, 12, 103 },
        { 0x2abef6447d8bb67f, 16, 98 },
        { 0x2ad4289996a301a5, 27, 207 },
        { 0x2ad64370d222517d, 2, 133 },
        { 0x2ae48b484bb37dcc, 7, 175 },
        { 0x2ae5cc6ca498ba39, 9, 232 },
        { 0x2af032dcdc6a22c6, 0, 190 },
        { 0x2b11673964a8f29e, 41, 135 },
        { 0x2b1839e0b24169cb, 24, 143 },
        { 0x2ba22618e11267ab, 7, 199 },
        { 0x2bb372b8886710e0, 23, 166 },
        { 0x2c221ae5873ce190, 15, 140 },
        { 0x2c50fd0f3632ea7a, 28, 118 },
        { 0x2c5a288c98a88850, 35, 220 },
        { 0x2c717280b37a0c07, 24, 138 },
        { 0x2c8b524bbb6d71b9, 0, 63 },
        { 0x2cd0abf9ab268afa, 14, 64 },
        { 0x2cd73e1f0ef5548c, 4, 170 },
        { 0x2cefe335c40dace1, 24, 151 },
        { 0x2d2e21e3471bd739, 0, 90 },
        { 0x2d7d2ec2c7c74ced, 58, 108 },
        { 0x2dc30f0bf1ba0e86, 7, 173 },
        { 0x2dcd4f0bbb758593, 27, 136 },
        { 0x2e3bdde1aac971fd, 36, 114 },
        { 0x2e5f973666a32a60, 5, 105 },
        { 0x2e939d2b5bc3ded2, 10, 182 },
        { 0x2e94c2898e1204e0, 10, 137 },
        { 0x2ebdaf343f78e7cb, 15, 199 },
        { 0x2ede23f667c073fd, 0, 142 },
        { 0x2ee86a3a07b8ea74, 0, 139 },
        { 0x2f56aaed7d0fc642, 60, 238 },
        { 0x2fb174c878ce4aaa, 2, 172 },
        { 0x2fd04cbc57722e00, 13, 204 },
        { 0x2fe9898de2748a4c, 21, 160 },
        { 0x2ffd7b1612896028, 13, 132 },
        { 0x300e90f3992f4242, 21, 116 },
        { 0x3027a77c06a1ffad, 0, 78 },
        { 0x303e0ba577e48a3a, 29, 127 },
        { 0x306982b56ce85113, 9, 129 },
        { 0x3072d8a193d49b72, 15, 158 },
        { 0x309c635b9b618110, 7, 104 },
        { 0x30a7af387fd55fa0, 24, 84 },
        { 0x30c59dab2863d2f3, 19, 154 },
        { 0x3166b27215dd246f, 11, 94 },
        { 0x3168a854a7cbbdef, 34, 100 },
        { 0x3172875ca3b7f76a, 0, 141 },
        { 0x3175bc9dbf49aeb8, 0, 154 },
        { 0x318a6b311eb20447, 26, 118 },
        { 0x31cce062f51590d7, 51, 173 },
        { 0x320323c422800ec7, 0, 73 },
        { 0x3260b67995695e9f, 9, 108 },
        { 0x32731c19971218d3, 10, 173 },
        { 0x332feefdc547a632, 11, 150 },
        { 0x3331a035c2fb002f, 9, 155 },
        { 0x3361921e7386e1c3, 0, 136 },
        { 0x3377d72034874ef2, 28, 173 },
        { 0x3385553ea566cf13, 31, 154 },
        { 0x3387e8dfc7b38aeb, 0, 149 },
        { 0x33b3d5553886f9ed, 14, 185 },
        { 0x33b74e8f65e3ed68, 11, 161 },
        { 0x33c414509ab39a14, 9, 104 },
        { 0x340779d04050291c, 85, 186 },
        { 0x344f600fde2365fc, 2, 137 },
        { 0x346d3bbe7c3f2dc6, 36, 116 },
        { 0x3479c8ccc1843172, 0, 171 },
        { 0x347ae1ea980f41f7, 35, 155 },
        { 0x349ef602fab82566, 9, 138 },
        { 0x34a70712552a8df7, 19, 228 },
        { 0x34a7a420677f5297, 7, 124 },
        { 0x34b7d075683be8e1, 0, 122 },
        { 0x34edb75eecfadfe4, 7, 109 },
        { 0x3532348b25f70133, 23, 82 },
        { 0x354e3dc78c79296c, 52, 156 },
        { 0x3556f1557d8289c6, 44, 90 },
        { 0x359be5eefca1eaaa, 11, 168 },
        { 0x35a06e91ca131dfc, 100, 156 },
        { 0x35cc6b8a85826f45, 15, 134 },
        { 0x35e91f2f8821467c, 48, 132 },
        { 0x35fdb637e2921a6d, 18, 106 },
        { 0x364d703d10b7a60b, 0, 126 },
        { 0x365d4549de37a8bb, 7, 119 },
        { 0x365fa1b3649a6920, 21, 175 },
        { 0x3750a73192f3ddda, 11, 129 },
        { 0x37bd8b12171468ac, 25, 165 },
        { 0x37c67901e7c1d828, 0, 49 },
        { 0x37ee24ce6aa68b60, 7, 175 },
        { 0x3840aa695cf2012a, 10, 133 },
        { 0x386cf3f06762c9c6, 14, 179 },
        { 0x387c7d1ba21557e2, 16, 144 },
        { 0x388133ad5e89cd52, 33, 129 },
        { 0x38ad2d2878cf7f1a, 66, 174 },
        { 0x38adc327779f9390, 41, 126 },
        { 0x38bbfc1505a78876, 9, 93 },
        { 0x38bd89e4da3e771f, 25, 113 },
        { 0x38e7906f3564cbe2, 10, 143 },
        { 0x3917011f437aa3c6, 24, 89 },
        { 0x39388b09dd0bbba1, 37, 144 },
        { 0x396df713ebfd8a60, 26, 112 },
        { 0x39c15cc601b20ca9, 24, 108 },
        { 0x39c759083802105b, 21, 97 },
        { 0x39f30e08edf37651, 0, 126 },
        { 0x3a036966b6a994bb, 21, 105 },
        { 0x3a19d2af1b9013b0, 17, 89 },
        { 0x3a39c56b931ff827, 44, 108 },
        { 0x3a39edf4d3cce92d, 49, 130 },
        { 0x3a6c154ebc700fb0, 47, 104 },
        { 0x3a7948c749824309, 17, 115 },
        { 0x3ad29cd1224072fd, 21, 139 },
        { 0x3af04c7cc4fce273, 7, 164 },
        { 0x3b0915b3ead335c7, 40, 107 },
        { 0x3b0df0f0dc38c65b, 7, 206 },
        { 0x3b55235d08c8527b, 34, 193 },
        { 0x3b5cdf01db92f0f4, 0, 113 },
        { 0x3b5ceddf7e529830, 0, 143 },
        { 0x3b787bdb4e410902, 0, 67 },
        { 0x3b8643c5d0f5afe8, 27, 117 },
        { 0x3ba997dc1b490bb4, 32, 137 },
        { 0x3bac5844ea2566c7, 42, 142 },
        { 0x3bb205c240c1c1af, 23, 129 },
        { 0x3bcdd062f712b6ee, 14, 85 },
        { 0x3bd13b7ed23d2a25, 16, 133 },
        { 0x3bd7e264fe2c8d1d, 24, 103 },
        { 0x3be8a6d4b15a8402, 70, 113 },
        { 0x3c084cd1e95a1ab5, 4, 167 },
        { 0x3c08bbe7fb485a32, 37, 102 },
        { 0x3c17219a8253c2be, 11, 101 },
        { 0x3c4815e4b1bb8e98, 0, 91 },
        { 0x3c723669b32a24ec, 106, 176 },
        { 0x3ca3b7f582b639e3, 4, 140 },
        { 0x3ce6183f0d0ab5de, 0, 142 },
        { 0x3ceb70f3d433e802, 12, 134 },
        { 0x3d0b68b77a39f579, 2, 205 },
        { 0x3d25ab643413ff15, 32, 146 },
        { 0x3d32bf6dd451b710, 28, 128 },
        { 0x3d356ee15a1b63be, 62, 171 },
        { 0x3d3c93a63002e692, 24, 170 },
        { 0x3dafd58477a2b999, 0, 230 },
        { 0x3dc671d1385e5d3f, 29, 116 },
        { 0x3dc787c9627d2ce4, 19, 114 },
        { 0x3df91cac0528deb1, 18, 110 },
        { 0x3e3f11605465bf14, 0, 188 },
        { 0x3e527f5f69c591c4, 32, 106 },
        { 0x3e5caf8667a1371a, 46, 105 },
        { 0x3e6ae419d07b45b9, 11, 148 },
        { 0x3e6e77d3665edcbc, 29, 156 },
        { 0x3e86927fadf68c73, 10, 130 },
        { 0x3e9099c947e493b2, 49, 129 },
        { 0x3ea8ed134c685def, 0, 202 },
        { 0x3eb50724384e79a9, 66, 188 },
        { 0x3eb7653bb8ef6d4d, 32, 162 },
        { 0x3ec791909a5c2dd8, 17, 65 },
        { 0x3ecf4dc800e023c1, 55, 140 },
        { 0x3ed94e7e3498d623, 68, 157 },
        { 0x3f256797bf901055, 21, 115 },
        { 0x3f4883f132c567e7, 34, 77 },
        { 0x3f827bede427e44c, 24, 119 },
        { 0x3fb4dedcdbdf2b4a, 45, 174 },
        { 0x3fcb0a8204293fc2, 12, 133 },
        { 0x3fde6c56d26a5cbc, 11, 138 },
        { 0x3ffed25216e5587f, 22, 176 },
        { 0x409799c8a8f1b9fc, 24, 126 },
        { 0x40b14eae15503474, 10, 178 },
        { 0x4113c5eabdb06f71, 0, 232 },
        { 0x4138fd2332f8b37f, 70, 144 },
        { 0x414fd5f0df9ba1ff, 20, 106 },
        { 0x42124bb78091726e, 16, 104 },
        { 0x426e9940e1dde9f6, 26, 167 },
        { 0x429647da13a8bac2, 42, 154 },
        { 0x429f1f8998afd986, 2, 79 },
        { 0x42a0eb838e8b8448, 4, 95 },
        { 0x42a3b3aad545633a, 7, 131 },
        { 0x42b649299429b4ed, 29, 152 },
        { 0x42bd4ae4b0ca5fab, 15, 106 },
        { 0x433035dadf876f64, 57, 133 },
        { 0x436c13d3fe918324, 26, 247 },
        { 0x43c2cdf7b01e2d1d, 56, 157 },
        { 0x4440573cf98e653c, 69, 209 },
        { 0x445e4d72d5665061, 40, 109 },
        { 0x44ac11d21d561dec, 24, 179 },
        { 0x44c0422599eb4eba, 12, 91 },
        { 0x4510e51116cab6ef, 2, 114 },
        { 0x451ceadc54fbacfd, 16, 163 },
        { 0x454964434d348e3d, 27, 93 },
        { 0x456dddbe7a6e5165, 24, 92 },
        { 0x456eb563cca743c3, 15, 158 },
        { 0x459bdb1169d071ff, 7, 168 },
        { 0x45cc3ed5b60cdd33, 48, 197 },
        { 0x45e8928f1627aa87, 59, 117 },
        { 0x45fe0b2f27e02a99, 35, 187 },
        { 0x4647ed3ad558fec1, 57, 221 },
        { 0x4658c3c01898f3e6, 20, 139 },
        { 0x46778db98a15fcc9, 41, 200 },
        { 0x47188646ca94b46b, 24, 86 },
        { 0x472d7f529cb423e0, 33, 170 },
        { 0x476e0c0f9df4cbd6, 0, 160 },
        { 0x47b5cb51dc54ccc1, 20, 118 },
        { 0x47bd3d64a467211a, 47, 196 },
        { 0x4889c0b4a7749d2d, 15, 183 },
        { 0x4892f5c57e34a617, 7, 136 },
        { 0x489ef60dc361717d, 60, 146 },
        { 0x48bc8d1b919f576d, 74, 157 },
        { 0x48efa3236ca2d3d4, 7, 129 },
        { 0x4918299448b17621, 34, 144 },
        { 0x492e569afa61de83, 31, 224 },
        { 0x499abb77bc31ab6c, 28, 199 },
        { 0x49c7461d9770cfd7, 11, 182 },
        { 0x49f70f67e0bc25bc, 9, 169 },
        { 0x4a2079f50290cad7, 16, 104 },
        { 0x4a7b1a2672b73a09, 49, 162 },
        { 0x4a91c83686d998e1, 7, 181 },
        { 0x4ad95e5cb1087bd7, 42, 122 },
        { 0x4ae015f8efa8523b, 0, 126 },
        { 0x4ae3a3c82929142c, 28, 116 },
        { 0x4ae4986acc207870, 11, 130 },
        { 0x4aea5e10022f76be, 45, 165 },
        { 0x4b5076dd6ebdc1c4, 15, 137 },
        { 0x4b64325faca53943, 68, 120 },
        { 0x4b69a00eadfcf5a5, 19, 154 },
        { 0x4ba2436cd4a1cdc2, 24, 119 },
        { 0x4bac24b97b3ccabb, 16, 97 },
        { 0x4bba2af7a0d18c9d, 32, 123 },
        { 0x4bd04d5cd4168bed, 11, 138 },
        { 0x4bf5d4df8b48da77, 45, 88 },
        { 0x4c6ea40f6d5265d5, 17, 165 },
        { 0x4cd109b5110e860b, 7, 66 },
        { 0x4cd2c4b5dfe1ec2a, 25, 230 },
        { 0x4d05259792e449ed, 21, 115 },
        { 0x4d2d6f78c97fdad4, 7, 149 },
        { 0x4da7be96b8e07a31, 172, 238 },
        { 0x4dbab2ad7c3c20bc, 7, 126 },
        { 0x4dbe7e6322992b14, 9, 173 },
        { 0x4de6ecc5ad0f1bc5, 15, 103 },
        { 0x4de8e78965df63f4, 31, 120 },
        { 0x4e034fe0740cb8ca, 7, 58 },
        { 0x4e4a14ab435ca64a, 35, 138 },
        { 0x4e7a7ab0cff39b36, 51, 165 },
        { 0x4e8583b9bb44ef7d, 34, 65 },
        { 0x4eacce6dd57cab4a, 68, 145 },
        { 0x4ef8774a9738a182, 36, 89 },
        { 0x4efcb48b8a87d0f2, 41, 132 },
        { 0x4eff00978db86573, 40, 119 },
        { 0x4f0baf7f20c7c1aa, 24, 191 },
        { 0x4f20d3d31ac4c2a0, 35, 153 },
        { 0x4f7ef743963aba3d, 2, 150 },
        { 0x4fc1a51479e79a58, 24, 180 },
        { 0x4fc6584b8f1e7670, 23, 105 },
        { 0x4fc67ab2b7940f66, 12, 165 },
        { 0x4fe9bd68c071ac96, 7, 68 },
        { 0x50230021e8e528ee, 31, 158 },
        { 0x5036251517514a3f, 17, 182 },
        { 0x504066852db82e74, 38, 167 },
        { 0x505799bc4edffd9f, 77, 181 },
        { 0x505fb4c4fdca9135, 0, 143 },
        { 0x5086e256e6d31891, 27, 162 },
        { 0x50fb7c5594541cc9, 48, 159 },
        { 0x512ba19af0aa3415, 0, 130 },
        { 0x513c4c204c6e5a40, 17, 135 },
        { 0x5168a881c0fd9082, 22, 153 },
        { 0x51780acfdf66aedb, 49, 172 },
        { 0x51923084f13f54ee, 7, 111 },
        { 0x51a584013d865eb7, 20, 92 },
        { 0x51fc9428e961d64b, 0, 152 },
        { 0x520da5015f653d7f, 0, 139 },
        { 0x521a73f5a1dab97d, 0, 133 },
        { 0x521eb2f311a0d50c, 24, 130 },
        { 0x52363c7f7714a1f2, 52, 123 },
        { 0x524ac7da983655cb, 31, 142 },
        { 0x525708d5af93918d, 76, 165 },
        { 0x529ba621c60ce6d2, 49, 141 },
        { 0x52ab0411f10c5a9f, 7, 144 },
        { 0x52e1b54465e2825b, 44, 160 },
        { 0x52f0ccc4dc4bdff2, 42, 127 },
        { 0x53ad7026e0eb92a8, 25, 158 },
        { 0x53ffd545e1247e6b, 10, 154 },
        { 0x544a1133bc09bbd3, 25, 140 },
        { 0x546c6714520106c4, 28, 183 },
        { 0x546caf97828d6167, 44, 106 },
        { 0x54788e2104404b19, 41, 149 },
        { 0x54938f10dad17a60, 27, 202 },
        { 0x549fb742f9b2bdff, 40, 174 },
        { 0x54f8745a17ed6b00, 19, 123 },
        { 0x552ac2c29d54fc5a, 2, 122 },
        { 0x5550d49ac5bd2d37, 0, 230 },
        { 0x557b3919500d51d8, 30, 173 },
        { 0x557e17c8fb6790ab, 7, 247 },
        { 0x55c690fabf520218, 11, 125 },
        { 0x55c9938a0d1cf094, 28, 109 },
        { 0x5644f928f27e1626, 0, 161 },
        { 0x565a73c12daab3b8, 0, 227 },
        { 0x565d41f359f6ec9c, 21, 164 },
        { 0x56999a939e83fb09, 7, 147 },
        { 0x56b463c9691b7f67, 17, 106 },
        { 0x56d3b33340c76dca, 0, 199 },
        { 0x578fbef0e500e924, 23, 142 },
        { 0x57a31abd3c108ca9, 27, 174 },
        { 0x57c0f0b0dcd2879a, 61, 226 },
        { 0x5841e6ebe2f92c7a, 12, 117 },
        { 0x587a76a5cdc6f314, 48, 140 },
        { 0x5898d9c0faa8c34f, 0, 126 },
        { 0x58aac87dc121084c, 18, 162 },
        { 0x58cdc31441a193bb, 9, 120 },
        { 0x58d52d89183d8867, 0, 158 },
        { 0x5902dec10eea92fe, 15, 157 },
        { 0x593891bd81eb4a88, 26, 175 },
        { 0x593e0d1824038d0a, 0, 54 },
        { 0x5942c0f010806cf6, 15, 169 },
        { 0x5947282ba5809902, 7, 168 },
        { 0x59935280bb9e5859, 190, 247 },
        { 0x59946d438d02a025, 56, 188 },
        { 0x599aea4c3931c866, 0, 143 },
        { 0x59bc30c60d5c3417, 9, 177 },
        { 0x5a021d0579321113, 17, 157 },
        { 0x5a357885d055dd7b, 33, 165 },
        { 0x5a6c88f1d0681623, 98, 203 },
        { 0x5a6d35dcdd798e6f, 22, 165 },
        { 0x5a7e6e5d10e621d1, 53, 126 },
        { 0x5af674025c29ac3f, 0, 91 },
        { 0x5b046a99b520de70, 24, 153 },
        { 0x5b83974b5f81f0ad, 7, 200 },
        { 0x5b8466278bb1da3a, 7, 132 },
        { 0x5b9b5458df77e559, 11, 174 },
        { 0x5bcf1e0dd3fa5e3c, 36, 162 },
        { 0x5c480c7d2e021e9d, 24, 220 },
        { 0x5c9f11e79a73d8fa, 7, 150 },
        { 0x5cc6d7ea523f92d5, 11, 142 },
        { 0x5cd5094fea6bb085, 14, 138 },
        { 0x5ce76c38b3943e12, 11, 197 },
        { 0x5d4e036bf0b4a509, 31, 202 },
        { 0x5d668679c8c927ea, 2, 159 },
        { 0x5dc59a4bd776c80d, 11, 143 },
        { 0x5de1361623be1176, 42, 101 },
        { 0x5e0c251a746c396c, 25, 156 },
        { 0x5e0cec64f07852c5, 0, 141 },
        { 0x5e5d0525a05ec848, 33, 162 },
        { 0x5e6121e90b5f068e, 11, 114 },
        { 0x5e79ac0cbb62a287, 0, 91 },
        { 0x5e956a8ce8b6197f, 35, 111 },
        { 0x5eae8371e0571df1, 34, 159 },
        { 0x5efc0675f7f47ef2, 24, 139 },
        { 0x5f523e3ad4058fb6, 20, 159 },
        { 0x5f77e7888e023fc6, 16, 154 },
        { 0x5faba789b5614fbc, 47, 96 },
        { 0x6047bb0918006f16, 20, 133 },
        { 0x6080ad261c12a620, 11, 69 },
        { 0x60814cc7d1f951e7, 32, 193 },
        { 0x60869c580b3745e1, 7, 93 },
        { 0x60fc3ec7867acf7c, 7, 95 },
        { 0x610d76c0db1d62d4, 24, 84 },
        { 0x6117061bdf68345a, 31, 186 },
        { 0x61361286afbbfbe3, 12, 112 },
        { 0x619da87b9bca19cd, 38, 150 },
        { 0x61a27e3d19a60cad, 20, 87 },
        { 0x61f001d90e741830, 16, 123 },
        { 0x61fb8d354589791c, 17, 78 },
        { 0x6211013c1fe16075, 41, 171 },
        { 0x621339cdeca329ef, 0, 163 },
        { 0x621b91feb14faa89, 14, 235 },
        { 0x6230dd0b8df2e747, 7, 163 },
        { 0x624aba45ab5e4757, 12, 189 },
        { 0x6252a7a69a679e80, 12, 160 },
        { 0x62631ca5b098ecd1, 0, 102 },
        { 0x62acb465cc7d0b44, 38, 158 },
        { 0x62fb6f4da1c30a8c, 17, 157 },
        { 0x6304e2fa04e07fbe, 21, 87 },
        { 0x6320f56631ce28c0, 111, 193 },
        { 0x63436e936af9acc0, 14, 209 },
        { 0x635240385dc466c7, 56, 170 },
        { 0x635bdf5f8d1be6b7, 15, 103 },
        { 0x63b5dfbbc3199326, 45, 131 },
        { 0x63c8c0806df5ae64, 10, 108 },
        { 0x63d87cd06523523f, 0, 143 },
        { 0x646d9b3e801a5087, 60, 170 },
        { 0x64907c6cbc0c0478, 21, 125 },
        { 0x64b0f7daac85ce13, 18, 192 },
        { 0x64b9636d64f643cd, 12, 117 },
        { 0x64be724a850d5113, 7, 133 },
        { 0x64c948d225f75cd4, 0, 158 },
        { 0x64dfbca7ae6069ce, 2, 79 },
        { 0x64f56f4911e6eeb9, 25, 129 },
        { 0x64f74a561b876efc, 24, 92 },
        { 0x64fa34406d493da1, 15, 159 },
        { 0x650e95b37effafae, 11, 175 },
        { 0x6520e3e76974babb, 9, 163 },
        { 0x658bac500d305e75, 22, 176 },
        { 0x65a4894be14b319b, 34, 127 },
        { 0x65bd0590e8b3e254, 37, 206 },
        { 0x65f74ffea0da59a1, 15, 145 },
        { 0x6603155343b911f1, 44, 154 },
        { 0x667956fd034ca4c7, 11, 151 },
        { 0x66a3343d6189ffd4, 21, 157 },
        { 0x66bc0fb0d27db22f, 11, 206 },
        { 0x66f829f7e9a6ffd3, 39, 112 },
        { 0x6716c8bac2d0dee0, 15, 189 },
        { 0x675ec03cbd102f4f, 0, 79 },
        { 0x6770da5d72bc3f51, 10, 178 },
        { 0x677756f14b31a92c, 7, 171 },
        { 0x679bd52f0098815f, 36, 124 },
        { 0x67a497b0808dbd05, 58, 160 },
        { 0x67ba38a57c55e9df, 11, 175 },
        { 0x67c95936ecdb8be5, 30, 107 },
        { 0x67e01f02b1d31700, 0, 119 },
        { 0x685af9765395eb25, 7, 127 },
        { 0x68dbdb32fd236996, 7, 129 },
        { 0x690254c6bebbc8e8, 26, 200 },
        { 0x692bc3cb21409c55, 24, 99 },
        { 0x69467e72f258f360, 133, 231 },
        { 0x696936fe891b324e, 28, 105 },
        { 0x696ae1fee3176ccd, 51, 115 },
        { 0x69a19da23c9e3873, 46, 108 },
        { 0x69a5881f88e8ff5c, 24, 127 },
        { 0x69b0d0a2d79c0dec, 70, 131 },
        { 0x69b9cec55ca2c86d, 39, 132 },
        { 0x69bdd096f337c074, 48, 158 },
        { 0x69d114fa7f112011, 11, 109 },
        { 0x69fcea74913ea215, 20, 100 },
        { 0x6a05717d27480cbc, 18, 112 },
        { 0x6a0e63b6d41cfd2a, 39, 203 },
        { 0x6a323fe0717f9018, 7, 200 },
        { 0x6a3c662bc17b998f, 59, 183 },
        { 0x6a47fdde568437ac, 33, 85 },
        { 0x6a75e4b59b50d580, 2, 108 },
        { 0x6a84c37159fee846, 17, 103 },
        { 0x6a93d7e2076ac219, 9, 120 },
        { 0x6af8811078eeeac0, 23, 118 },
        { 0x6bcd8f508a56e50b, 27, 85 },
        { 0x6bdb707a1843168f, 68, 157 },
        { 0x6bf63716b9e1d260, 27, 152 },
        { 0x6c156de94a94a26e, 18, 105 },
        { 0x6c30a4368d488471, 32, 156 },
        { 0x6c3dbea350dc773e, 15, 153 },
        { 0x6c7e131856a863af, 26, 71 },
        { 0x6c9813f82d5b1c78, 44, 154 },
        { 0x6c9a9cd4096b8dce, 27, 90 },
        { 0x6cad62a3d6d85354, 48, 167 },
        { 0x6cce9ae15d63aa84, 24, 112 },
        { 0x6cdee03beb8ddec0, 21, 146 },
        { 0x6d0d80a90d1520d7, 15, 101 },
        { 0x6d1a501355215448, 84, 155 },
        { 0x6d1a5c7d054c426e, 47, 158 },
        { 0x6d1ad0d6f8f6e709, 40, 183 },
        { 0x6d2e592bea2b1e66, 35, 162 },
        { 0x6d2f27726fb61c8f, 45, 131 },
        { 0x6d9fc0af2aeb6111, 33, 74 },
        { 0x6de009975e3d0b67, 17, 108 },
        { 0x6df53371c976219d, 15, 116 },
        { 0x6dfcc8c7b3ba9c6c, 33, 203 },
        { 0x6e2661c87844f27f, 38, 150 },
        { 0x6e7127d21f79fe23, 0, 155 },
        { 0x6e897017baf2c39a, 30, 147 },
        { 0x6ed48bcd3ceae2ed, 46, 164 },
        { 0x6f04502ef762b0c7, 106, 177 },
        { 0x6f33bc189c1901f3, 20, 184 },
        { 0x6f3ae2649ebbc5d9, 40, 161 },
        { 0x6f5b3bae8c40fc0a, 74, 157 },
        { 0x6fc549f8d6650613, 9, 131 },
        { 0x6fc668a228e8ae76, 24, 154 },
        { 0x6fdc747db107258f, 31, 76 },
        { 0x6fe46fb4a52b6b2d, 32, 147 },
        { 0x6ffd2936379fb8be, 0, 142 },
        { 0x700568bc6d26c2fe, 19, 77 },
        { 0x701668455089d89e, 7, 111 },
        { 0x7031d5c8d07ef7a7, 2, 113 },
        { 0x704bafee2fa58d87, 29, 162 },
        { 0x706b0bd5b391d27d, 25, 176 },
        { 0x708b18471d8ca926, 4, 154 },
        { 0x709ac7b49c48649a, 15, 177 },
        { 0x709f8c3a81f42f8e, 16, 148 },
        { 0x70f9b2c03770f393, 31, 133 },
        { 0x71213fe6061596e3, 51, 126 },
        { 0x7179031051659818, 58, 128 },
        { 0x71a2a1c63925976b, 10, 104 },
        { 0x71a4adc936c38120, 60, 229 },
        { 0x71b30bddb0dbacdb, 0, 113 },
        { 0x71e54e70b5da42f8, 15, 140 },
        { 0x7239dd5a1ac6abf6, 58, 202 },
        { 0x724f85c5da11a5c0, 16, 148 },
        { 0x725eb3f33a3d2f0a, 9, 143 },
        { 0x7272cd0e77e2daf8, 26, 102 },
        { 0x728d6eee4dff334f, 9, 110 },
        { 0x728f80c1d1f05dcc, 40, 161 },
        { 0x72ab33a541780505, 33, 173 },
        { 0x72f66b94d8756e05, 24, 99 },
        { 0x730317da2236f486, 17, 111 },
        { 0x732aff91d2b4e05a, 47, 206 },
        { 0x735b0cdfdf915181, 17, 182 },
        { 0x735d179bd8ac04ca, 46, 223 },
        { 0x7386e2c4986e95da, 2, 155 },
        { 0x7391d2cf03710f7e, 0, 178 },
        { 0x73ac0308fabef6ce, 29, 90 },
        { 0x73d585f86b82dfd8, 27, 111 },
        { 0x742b91dbb8ae10fa, 51, 154 },
        { 0x7434ad7c28e48d43, 0, 120 },
        { 0x74ce5a04d0ee022a, 0, 203 },
        { 0x74ce782e12042c68, 41, 134 },
        { 0x7501de36382aafd3, 0, 237 },
        { 0x751c0f4afa17b201, 0, 99 },
        { 0x752ecc99d648d38b, 17, 128 },
        { 0x754216ac897d1286, 2, 235 },
        { 0x75516ee894419b59, 16, 203 },
        { 0x756444be175f649c, 9, 137 },
        { 0x757bc39fd7da2fe0, 7, 80 },
        { 0x75e440066192feb7, 69, 189 },
        { 0x75eab2aa0940cdeb, 62, 112 },
        { 0x76342d73bfb82684, 22, 108 },
        { 0x76693826c96a8a3a, 15, 162 },
        { 0x7708b1d589135556, 30, 126 },
        { 0x77398bd409ba04f5, 43, 95 },
        { 0x7775b63e815f9d25, 7, 130 },
        { 0x7778c4c1cccb7045, 24, 118 },
        { 0x778a32a6cbe6cc18, 0, 66 },
        { 0x77d6f564e68bc78e, 55, 167 },
        { 0x77dac6d297377ede, 24, 82 },
        { 0x77e7f714210ee6a3, 49, 108 },
        { 0x77f3a13095b40d8e, 29, 114 },
        { 0x77fb02f872b6b6b8, 9, 121 },
        { 0x780957b505b8a9d9, 28, 123 },
        { 0x786178834c039f38, 10, 97 },
        { 0x786394a0fee23325, 24, 171 },
        { 0x788738be67f2c2e3, 17, 113 },
        { 0x78a885de4b380162, 0, 98 },
        { 0x78d00d310976a919, 17, 177 },
        { 0x78d3311792ce28ef, 22, 124 },
        { 0x7905224bdc01abf6, 0, 155 },
        { 0x791aeb79a75dc449, 19, 220 },
        { 0x791d0d561c46c5e2, 36, 159 },
        { 0x792c46f637d5af06, 31, 91 },
        { 0x7945a97e05e2fe47, 63, 224 },
        { 0x79636f07655e908e, 14, 75 },
        { 0x7982859f91bf9080, 47, 128 },
        { 0x79f2f2d1b02fbb3f, 24, 225 },
        { 0x79f8fd0432a49806, 55, 140 },
        { 0x7a755240ec306220, 17, 178 },
        { 0x7a8e1e56ff5d0fe3, 34, 182 },
        { 0x7aa05d0faacbc01f, 7, 150 },
        { 0x7af90558bdbfa183, 0, 101 },
        { 0x7b030cf890da3fb4, 37, 187 },
        { 0x7b31d535b644f17e, 21, 143 },
        { 0x7b49d55d9dfdcee9, 16, 161 },
        { 0x7b705a08e8ff12c1, 60, 157 },
        { 0x7bcaebd9ab47a8c6, 7, 158 },
        { 0x7bd66b082b57f02e, 38, 180 },
        { 0x7bd8a64ac791df0f, 56, 90 },
        { 0x7be6af50e6bbe865, 26, 133 },
        { 0x7c25b9ee46295942, 34, 127 },
        { 0x7c9237d1787e4903, 14, 193 },
        { 0x7cbbc714e3b3a416, 17, 82 },
        { 0x7d182435ca389b30, 15, 147 },
        { 0x7d9bc6137ccfee5c, 0, 163 },
        { 0x7da4c2960ea50f7a, 84, 173 },
        { 0x7da4e6f65810c2ed, 28, 172 },
        { 0x7da9c8630d4dc1d2, 16, 144 },
        { 0x7db567da51fc6184, 0, 100 },
        { 0x7dc160b3516317d5, 64, 113 },
        { 0x7dca6af036d3faf7, 20, 156 },
        { 0x7e190f2730965ad0, 0, 123 },
        { 0x7e1b9bc8ac386491, 21, 167 },
        { 0x7e674458ffb53a23, 40, 185 },
        { 0x7ed57244a03703ae, 34, 180 },
        { 0x7ef03df5f7b3f361, 12, 79 },
        { 0x7f290c1d485d0efb, 12, 106 },
        { 0x7f291a8011fd480e, 0, 113 },
        { 0x7f2a27e193fc0c0b, 78, 166 },
        { 0x7f43fde8c3cde238, 34, 100 },
        { 0x7f4612fbdfd0fba1, 16, 95 },
        { 0x7f5e246a0d74688a, 33, 105 },
        { 0x7ffe5155c26da7e2, 0, 149 },
        { 0x801ac148b2d5800f, 9, 80 },
        { 0x802e753014ce2538, 0, 114 },
        { 0x8030b3e07c4d6684, 40, 163 },
        { 0x803deb358181cae6, 24, 194 },
        { 0x807633d5a0444700, 45, 154 },
        { 0x807a9340055630a2, 83, 215 },
        { 0x80b159705558b1b3, 17, 113 },
        { 0x80b9ab1f1c75ddfb, 19, 99 },
        { 0x80c4e4b432d14a7a, 12, 171 },
        { 0x80ff3baad3485760, 19, 138 },
        { 0x811f9aa8023fe105, 48, 174 },
        { 0x813b56b979649119, 12, 129 },
        { 0x813ef23f28e5937d, 4, 140 },
        { 0x81724e18c99b9531, 39, 150 },
        { 0x817e86a83afd00f5, 11, 146 },
        { 0x817f8b59ca87b5d8, 34, 165 },
        { 0x81a9edc887cb8617, 28, 154 },
        { 0x81d37bcb59f00098, 17, 189 },
        { 0x81ec5fb38e476e90, 30, 190 },
        { 0x820b58cdfdb2a985, 0, 178 },
        { 0x8242a9a39153312d, 12, 87 },
        { 0x8249755c8c108c1d, 15, 168 },
        { 0x824feb6912e7526e, 27, 148 },
        { 0x825b5914c3a521c2, 9, 167 },
        { 0x825c9756076ffb60, 36, 103 },
        { 0x82709b260097a475, 0, 88 },
        { 0x8297ae891236db5f, 14, 136 },
        { 0x82d30d733ebcccf9, 24, 214 },
        { 0x82f2cb4afc89381d, 2, 149 },
        { 0x83134ad6a1e270bc, 37, 115 },
        { 0x83224706a3b80c1b, 7, 141 },
        { 0x836d440704f29d5d, 17, 114 },
        { 0x837446c54f42960d, 0, 139 },
        { 0x83ae970f6e1c12cf, 21, 171 },
        { 0x83da8cbcca3ecc99, 27, 175 },
        { 0x848b3104cf070678, 40, 111 },
        { 0x84b1036154def46a, 0, 186 },
        { 0x84bf735b55ad9076, 24, 185 },
        { 0x84d581ca94be4101, 49, 122 },
        { 0x8506072cac2c9d5a, 9, 88 },
        { 0x8538f7a371cc8c11, 9, 174 },
        { 0x8581058025593288, 14, 134 },
        { 0x8585324eb4681986, 65, 227 },
        { 0x85a8a576ea0053e8, 18, 137 },
        { 0x868e690c21eb01bb, 11, 120 },
        { 0x869f9ca80defadce, 54, 173 },
        { 0x86acdb6b0bc1e981, 33, 119 },
        { 0x86e1ea8fe3cb6d62, 38, 115 },
        { 0x86eeeba15f421833, 21, 162 },
        { 0x875fd71f83af4b7a, 0, 102 },
        { 0x87c19a9f691b6298, 0, 111 },
        { 0x87d3e0f8741c0c9d, 32, 123 },
        { 0x87d7107db5ca21bb, 12, 157 },
        { 0x87ddf73f49582cd9, 48, 91 },
        { 0x87f8cb282b32b064, 47, 204 },
        { 0x880e41a8e39680c9, 58, 187 },
        { 0x8815cc73a8bd88a1, 17, 189 },
        { 0x882437d58120c8d7, 26, 202 },
        { 0x88488331c4127c77, 9, 126 },
        { 0x886bda2772cd5bfa, 0, 208 },
        { 0x88753089e8a1fe6b, 67, 233 },
        { 0x8895197ea5ba3945, 26, 76 },
        { 0x8899878a3c896403, 31, 211 },
        { 0x88a6c9a7f3d17bf6, 0, 128 },
        { 0x892f388c370872d9, 19, 77 },
        { 0x89941f1e716adc30, 15, 79 },
        { 0x899f2bd667becc02, 27, 186 },
        { 0x89a5c017c9642821, 21, 68 },
        { 0x89b6cf757e8d79b6, 0, 197 },
        { 0x89fc67a171b36ef8, 45, 183 },
        { 0x8a69d08d297c5b79, 21, 72 },
        { 0x8ac65d7979cbed0f, 41, 168 },
        { 0x8ac8233b6a252763, 15, 133 },
        { 0x8afb2bc2d08566bf, 9, 144 },
        { 0x8afb588dd3f04a29, 7, 159 },
        { 0x8b038cc54d2cc7cc, 14, 132 },
        { 0x8b1712b52c844067, 7, 154 },
        { 0x8b1c329f4667f6b5, 17, 183 },
        { 0x8b3465298adb5dc2, 56, 188 },
        { 0x8b59806860709424, 31, 247 },
        { 0x8b862b0e833f76e7, 0, 120 },
        { 0x8b88eebb4b17c6a1, 98, 179 },
        { 0x8b9936019263a563, 12, 76 },
        { 0x8bc62aea19ba6750, 0, 151 },
        { 0x8bd88ef2305f6b03, 0, 104 },
        { 0x8c2ae54ec327838c, 0, 92 },
        { 0x8ccfd7c0ce0149f9, 0, 105 },
        { 0x8dab975e552fa864, 70, 205 },
        { 0x8dabd3fa797e94e2, 49, 174 },
        { 0x8e41b04b99a602ef, 7, 130 },
        { 0x8e6a8bc02e6dc442, 0, 100 },
        { 0x8e7ddf9dae646b45, 30, 91 },
        { 0x8e7f1216ce897f67, 0, 108 },
        { 0x8eb058f94ebf3ade, 54, 102 },
        { 0x8eb95bf239003594, 17, 104 },
        { 0x8ed0596ec81616ff, 18, 74 },
        { 0x8efb0a598b63e522, 42, 161 },
        { 0x8efe1d4ed28a3af8, 49, 149 },
        { 0x8f45ba32270fafc2, 11, 158 },
        { 0x8f5c2b4231d5b6c2, 31, 136 },
        { 0x8f7155d44310a68a, 11, 192 },
        { 0x8fc35b86286ef823, 10, 100 },
        { 0x8fc76b3f44e518e8, 25, 106 },
        { 0x8fdd3ea722903409, 61, 187 },
        { 0x904150caa7ee62b0, 0, 224 },
        { 0x9047f4a7278186d1, 17, 73 },
        { 0x9079e72148e51fc6, 0, 145 },
        { 0x909297b7b0fb3c8f, 57, 154 },
        { 0x90b920492cad82a4, 83, 180 },
        { 0x90d7118a8ab2b8c9, 9, 117 },
        { 0x91087093a281529c, 20, 140 },
        { 0x910bedbe64faf3b9, 0, 141 },
        { 0x913af37ab62ac18c, 38, 187 },
        { 0x917b03c44a8f4913, 15, 134 },
        { 0x91b20b54b85edcde, 16, 138 },
        { 0x91d69b3654b91ac3, 53, 133 },
        { 0x91dc63433e7132c8, 97, 168 },
        { 0x92281f3d22a435ab, 18, 123 },
        { 0x9233817d7fb6b383, 25, 177 },
        { 0x923dcb8f364ecb2b, 25, 170 },
        { 0x924be837cee6836b, 7, 156 },
        { 0x92b49a114a754437, 7, 104 },
        { 0x933463bd04326f81, 18, 110 },
        { 0x9340e6610e77a148, 31, 190 },
        { 0x93a1957667906742, 27, 146 },
        { 0x93c513b27b0bc1cc, 66, 173 },
        { 0x93cb51b73b3a1305, 19, 138 },
        { 0x93d275628f97b992, 24, 123 },
        { 0x93e0ed1da4c23ba2, 112, 222 },
        { 0x9409c9b31ea68a7b, 12, 134 },
        { 0x948de7a57002f906, 0, 80 },
        { 0x94bd29b74e9a3736, 10, 193 },
        { 0x94cbff261d18ba58, 0, 179 },
        { 0x94e63a3b4b78fc54, 14, 94 },
        { 0x94e717979b0d8bec, 22, 134 },
        { 0x950461349ccac6b8, 7, 130 },
        { 0x9540642b06531ae6, 29, 173 },
        { 0x954ef9f8a319784b, 2, 155 },
        { 0x955b7661b59bc795, 7, 113 },
        { 0x958318165d86fdf6, 75, 182 },
        { 0x95c9016de9d51f9a, 25, 109 },
        { 0x95cd35ce4b6567d1, 40, 110 },
        { 0x95d70f9123941e94, 17, 96 },
        { 0x964f6a9c338b66fc, 42, 153 },
        { 0x965b08644b4d217e, 79, 218 },
        { 0x96684ebf786bf7ac, 19, 144 },
        { 0x96e16660653cbbcd, 0, 179 },
        { 0x96f6e820251a87e2, 39, 96 },
        { 0x97189ee6be615272, 0, 168 },
        { 0x9720383198742bd3, 16, 148 },
        { 0x97417481aeafad57, 24, 130 },
        { 0x979c3cf62ddb8a71, 18, 195 },
        { 0x9822431fff596e5d, 0, 194 },
        { 0x9825428a498ff6dd, 2, 164 },
        { 0x98487ac51cd8946f, 9, 158 },
        { 0x984c4e7ea9848642, 26, 133 },
        { 0x9857bbf60edc979c, 16, 95 },
        { 0x98cd9fff48e72dd5, 47, 140 },
        { 0x9962017efebfabc7, 43, 155 },
        { 0x99a77f779f130652, 0, 133 },
        { 0x99a8168efe4ab39e, 18, 85 },
        { 0x99b9fb9707542646, 9, 128 },
        { 0x99c3af3fdc6d2975, 29, 149 },
        { 0x99c74403eaa03e91, 18, 78 },
        { 0x9a0c6b5514751e80, 0, 86 },
        { 0x9a8a2771abe34822, 16, 99 },
        { 0x9aa7e53d7f3a75cf, 34, 165 },
        { 0x9abf7873bffea7a3, 12, 137 },
        { 0x9adb59faf6497a02, 42, 143 },
        { 0x9b0dbe6f1cc6a337, 15, 134 },
        { 0x9b3389ef372081ec, 23, 183 },
        { 0x9b3468a302b5a297, 33, 92 },
        { 0x9b6a3475689e17e3, 25, 155 },
        { 0x9bb4c42ecd384cef, 2, 121 },
        { 0x9beac0023a407f40, 40, 141 },
        { 0x9c647fa63c310397, 19, 91 },
        { 0x9ca12bfed2af3249, 11, 80 },
        { 0x9caa8d076b098d97, 17, 104 },
        { 0x9cd6a08c1c787ab6, 3, 137 },
        { 0x9d0986172debbd81, 30, 111 },
        { 0x9d1221e805a2ed58, 37, 130 },
        { 0x9d43e04fc88fb513, 15, 92 },
        { 0x9d4d5d5bc8169f7a, 19, 128 },
        { 0x9d509697d771dd69, 7, 159 },
        { 0x9d938c1c99d1f644, 36, 181 },
        { 0x9de405397fd7d5c3, 12, 166 },
        { 0x9de8db63910e9e65, 11, 135 },
        { 0x9df43c81570b1776, 21, 127 },
        { 0x9dfd9d7f943b778e, 33, 132 },
        { 0x9e54aaa6a4580c06, 27, 216 },
        { 0x9f06fb5f6adb8d56, 38, 139 },
        { 0x9f20f7bf1d3bf1f5, 51, 108 },
        { 0x9f352c25edf6a19a, 43, 130 },
        { 0x9f60f5f101610f3d, 42, 124 },
        { 0x9f762167a284f9df, 33, 120 },
        { 0x9f7742d1d6795685, 12, 102 },
        { 0x9fa67f767a2d583d, 7, 147 },
        { 0x9fac986b6ed87a53, 68, 109 },
        { 0x9fb9a23dea2871ee, 0, 101 },
        { 0x9fbf807c7aeab607, 36, 119 },
        { 0x9fce8d7e0390ed15, 0, 170 },
        { 0x9ff47835f3cfef24, 74, 166 },
        { 0xa0393d4bafb9a1a3, 0, 171 },
        { 0xa08c0479242935a7, 7, 158 },
        { 0xa0a5fc0eab54ee58, 17, 195 },
        { 0xa143bc99822bbca3, 0, 144 },
        { 0xa1759593f3db6f28, 28, 107 },
        { 0xa17f35ee08150d7c, 9, 155 },
        { 0xa1c7296ecda0c10b, 36, 126 },
        { 0xa209087f413c21d1, 0, 181 },
        { 0xa20df58ddccd9776, 17, 154 },
        { 0xa25f2ff33f0d985a, 4, 129 },
        { 0xa27d6a9eda020221, 100, 208 },
        { 0xa27db8e6051ac017, 23, 137 },
        { 0xa29317375edfad5d, 24, 162 },
        { 0xa294b8bc0d16b647, 21, 110 },
        { 0xa2c006363284479d, 63, 197 },
        { 0xa2f4f8571f9f4329, 37, 80 },
        { 0xa2fbd406fcc82afa, 0, 160 },
        { 0xa30a9795bfed5faa, 31, 95 },
        { 0xa30b630e08fe9067, 36, 221 },
        { 0xa32b519f2aaec955, 101, 219 },
        { 0xa3482879d3235bd1, 15, 112 },
        { 0xa39760d993820f23, 16, 155 },
        { 0xa3c4d099db9c7b85, 12, 145 },
        { 0xa3e5f72c07000df2, 27, 179 },
        { 0xa3fc446d1590570c, 7, 82 },
        { 0xa40ed4f606a6bcce, 25, 174 },
        { 0xa415017d816e8c8a, 21, 178 },
        { 0xa43c7255397ee939, 25, 170 },
        { 0xa455894091918abc, 15, 157 },
        { 0xa46cd8fa45fa7bb3, 17, 148 },
        { 0xa47b7057aa363cb6, 0, 149 },
        { 0xa47e7bd6e9ed4cc1, 28, 122 },
        { 0xa48abe6b02572a6b, 15, 67 },
        { 0xa49c90e0e00672c8, 17, 133 },
        { 0xa4aee8d715ca78c9, 66, 169 },
        { 0xa4bec532754a7fef, 74, 166 },
        { 0xa4e5851d80f51828, 16, 166 },
        { 0xa4e70087129de191, 0, 124 },
        { 0xa50430d2d2af6fdd, 25, 170 },
        { 0xa506bdb5c689e702, 21, 196 },
        { 0xa509255f2664aef8, 41, 99 },
        { 0xa51744f263a8df99, 16, 139 },
        { 0xa53c582ab77804c1, 37, 115 },
        { 0xa53e8319a245d052, 0, 224 },
        { 0xa5607cec5e10f98e, 47, 96 },
        { 0xa58d445252dd94a3, 0, 238 },
        { 0xa5b866b8b4eef420, 0, 115 },
        { 0xa60e85dcf6f85f92, 40, 186 },
        { 0xa61b06c88562fbad, 0, 151 },
        { 0xa6305666423e78eb, 34, 68 },
        { 0xa661bcde8daa3e24, 0, 146 },
        { 0xa674cd827a907caf, 12, 181 },
        { 0xa6aa8fd8983de63e, 70, 162 },
        { 0xa6b1fd02d5614f7d, 7, 127 },
        { 0xa6c43a742a5431ee, 10, 140 },
        { 0xa6c8788d0c50de4a, 0, 139 },
        { 0xa70e1c9a0236b70a, 4, 150 },
        { 0xa72d0b035e4439fa, 46, 173 },
        { 0xa73014eae44c2740, 81, 115 },
        { 0xa75a2e5e12a66fd2, 10, 82 },
        { 0xa7ae0e57ecff4eee, 16, 109 },
        { 0xa7bbdf5e3affd347, 16, 82 },
        { 0xa7c65237e5e725c9, 11, 189 },
        { 0xa7f793a1f2f5421d, 40, 123 },
        { 0xa82640b2845e7d98, 21, 112 },
        { 0xa83329f40b73a78b, 32, 136 },
        { 0xa84cf5c92451c9d6, 10, 131 },
        { 0xa851d683f7b836f8, 37, 231 },
        { 0xa86dce38d516fa09, 42, 156 },
        { 0xa8999091d4a1f092, 19, 89 },
        { 0xa89b99ae8897ec88, 15, 164 },
        { 0xa8b4c42e366deb1f, 11, 75 },
        { 0xa925a107f4c9edc6, 36, 153 },
        { 0xa932bf6b88e6fc6f, 15, 122 },
        { 0xa940fd6b4a60e3a3, 26, 254 },
        { 0xa9690b65ed36091c, 63, 172 },
        { 0xa96d959e636af4bf, 2, 129 },
        { 0xa98cd44b3c853507, 9, 137 },
        { 0xa9c6c08511d44618, 61, 185 },
        { 0xa9c9585285fc0684, 14, 165 },
        { 0xa9d6e248b5f02181, 18, 188 },
        { 0xa9dcd8fd124b828a, 24, 94 },
        { 0xa9f56ccc9425035d, 46, 169 },
        { 0xaa4030800363aab8, 2, 137 },
        { 0xaa4fb767534de6b1, 0, 160 },
        { 0xaa6e13b8066e0811, 24, 110 },
        { 0xaa82e69cadb0e937, 14, 146 },
        { 0xaa962abd25d9510d, 20, 172 },
        { 0xaac84b3284715d31, 16, 163 },
        { 0xaae87d0c8c851ec6, 10, 141 },
        { 0xaaee5201dd8f2759, 4, 59 },
        { 0xab1be3153dce6e0f, 0, 81 },
        { 0xab57eb88d914d923, 14, 142 },
        { 0xab5d051a0cd96804, 22, 132 },
        { 0xab8e5c4f1a5abb67, 41, 132 },
        { 0xabc507d3fc53778b, 0, 152 },
        { 0xac10bb8e872631a3, 15, 175 },
        { 0xac218b43a6d21568, 15, 111 },
        { 0xac3caa207ef665f3, 12, 76 },
        { 0xac535dd5a290b70b, 32, 188 },
        { 0xac53c39d18b1002d, 41, 176 },
        { 0xacdfca0076008f4a, 7, 124 },
        { 0xacec28b81f63a44b, 75, 181 },
        { 0xaceee5e898f23f85, 130, 225 },
        { 0xad0c2d276f949ed2, 15, 172 },
        { 0xad140731b3754d68, 5, 180 },
        { 0xad415a75840c37f0, 37, 94 },
        { 0xadae48789688a435, 17, 178 },
        { 0xadccd83290101198, 49, 157 },
        { 0xae0b4d543b16a9ac, 21, 95 },
        { 0xae0fb196b4b721f2, 24, 164 },
        { 0xae1c01f3a5f4259e, 0, 169 },
        { 0xae5b3131b684cffb, 0, 108 },
        { 0xaee03f44fed81570, 2, 125 },
        { 0xaef9b50089cd8e31, 33, 157 },
        { 0xaf0d12b079cf82fc, 9, 105 },
        { 0xaf29198cc320c313, 10, 102 },
        { 0xaf4d0117184ab07d, 42, 170 },
        { 0xaf571c466134b7ea, 21, 64 },
        { 0xaf8cae0d28892445, 28, 230 },
        { 0xafd46d1550545c8d, 2, 113 },
        { 0xaffc186424cd8ef1, 34, 131 },
        { 0xb029e06361834389, 7, 153 },
        { 0xb0616ec66aae6c81, 17, 132 },
        { 0xb07a5d8812aa38bb, 30, 140 },
        { 0xb09981dcf815abc1, 50, 155 },
        { 0xb0aaf35ff7a9537f, 24, 217 },
        { 0xb0f31814ca84c8a8, 49, 156 },
        { 0xb16e71a5324b1cab, 45, 98 },
        { 0xb1e6c8b0697d1274, 0, 207 },
        { 0xb1ec271147f0ed82, 10, 121 },
        { 0xb2319b35370a50f8, 34, 225 },
        { 0xb274adf310bd4283, 33, 166 },
        { 0xb28100d5df745365, 0, 104 },
        { 0xb288830472f9b295, 19, 137 },
        { 0xb333e4077bbc4226, 71, 194 },
        { 0xb36c715cff99f080, 14, 147 },
        { 0xb37abb87aa3231a2, 10, 189 },
        { 0xb3904d875784e0a5, 66, 165 },
        { 0xb39341dfc580c244, 35, 103 },
        { 0xb3998371b5018263, 17, 119 },
        { 0xb3b06d5b88831d93, 0, 143 },
        { 0xb3dbb68c77ed34b2, 9, 169 },
        { 0xb46104a301d5c7c8, 0, 86 },
        { 0xb47f50da39d5c0f3, 10, 148 },
        { 0xb486624422010a14, 40, 104 },
        { 0xb4960fb8f7799f0d, 10, 147 },
        { 0xb4baa6487c8ca8b9, 48, 168 },
        { 0xb5185cb35b5559d8, 31, 106 },
        { 0xb52788f10a0d0957, 15, 81 },
        { 0xb58e68e8e6c4d273, 28, 229 },
        { 0xb5a248bb60754677, 24, 148 },
        { 0xb5ad94ac4cb852f6, 18, 179 },
        { 0xb5bb6294be859050, 43, 162 },
        { 0xb5cec4e320632b6b, 8, 91 },
        { 0xb608ba3cf174cd12, 27, 87 },
        { 0xb61057728ec94d45, 8, 96 },
        { 0xb63015dade4ccf05, 56, 169 },
        { 0xb6353b0dcdc0da8c, 5, 91 },
        { 0xb63c1d988baf97fc, 2, 129 },
        { 0xb65133698af75fa0, 12, 159 },
        { 0xb6640fc75e630756, 0, 121 },
        { 0xb691799a8d569813, 48, 163 },
        { 0xb692a4ebeefd4dd3, 4, 150 },
        { 0xb69be0001d12b8a9, 0, 159 },
        { 0xb69c55ec5d5b1b8b, 7, 123 },
        { 0xb6fcd67489647e96, 18, 108 },
        { 0xb7154e176cab9b89, 58, 134 },
        { 0xb717793fa34a1632, 0, 151 },
        { 0xb733740449c82d29, 17, 161 },
        { 0xb764ecaea4991bac, 21, 104 },
        { 0xb7b1698056c3cc29, 0, 150 },
        { 0xb7c1754d6ddd9956, 25, 198 },
        { 0xb7d6e7ed9276a3ab, 56, 150 },
        { 0xb7d85a0b64f8887b, 59, 150 },
        { 0xb7e8e326c474cb60, 40, 114 },
        { 0xb812256cd76cd695, 9, 149 },
        { 0xb831fcffaa4b86d9, 36, 110 },
        { 0xb84f027e7b95a96b, 19, 155 },
        { 0xb8836166e6779162, 7, 141 },
        { 0xb8bdd1f40b699a85, 16, 139 },
        { 0xb8f45a0b0594cd67, 7, 126 },
        { 0xb93ddfdacda3144c, 29, 153 },
        { 0xb94b7a12fad63902, 24, 66 },
        { 0xb97617bcad095426, 54, 134 },
        { 0xb99861018e26672a, 41, 149 },
        { 0xb9d792e14a181a6e, 55, 156 },
        { 0xba28e99c898a0601, 44, 118 },
        { 0xba2dc3d7540c679c, 32, 169 },
        { 0xba4451260120cc20, 7, 210 },
        { 0xbadfc8c99a7ba54a, 44, 162 },
        { 0xbaf0e9ae06c533c4, 56, 156 },
        { 0xbafe075e027175c8, 0, 116 },
        { 0xbb3c113dedc23ac6, 7, 214 },
        { 0xbb8192ef95c7ce14, 25, 91 },
        { 0xbb9603e4159d5dcd, 4, 114 },
        { 0xbba4fefc4b7d49eb, 10, 247 },
        { 0xbbc18c841f359a8f, 47, 186 },
        { 0xbbf770fe909b287b, 51, 138 },
        { 0xbc37be3ebae490a4, 7, 160 },
        { 0xbc6fd2476db96aa7, 0, 119 },
        { 0xbc915a4ca0e49b40, 16, 114 },
        { 0xbcd60fc302af1189, 11, 138 },
        { 0xbd302941764573ef, 12, 175 },
        { 0xbd7017c0dd86ab83, 33, 204 },
        { 0xbd83470dc2be0320, 31, 139 },
        { 0xbdb6a01c0aef186a, 9, 132 },
        { 0xbdb943cddf7a8aaf, 0, 191 },
        { 0xbe13b4ff8d8e0bf6, 7, 113 },
        { 0xbe7ca36598f4cac3, 9, 136 },
        { 0xbe8f839ceefe38d4, 11, 129 },
        { 0xbea4752505c12c45, 16, 112 },
        { 0xbeb28bae8e949cb8, 54, 203 },
        { 0xbeb754d38f257f98, 38, 166 },
        { 0xbecfbf4731ccb363, 17, 131 },
        { 0xbf142cd45521c2a9, 74, 205 },
        { 0xbf248c19aabe947b, 16, 111 },
        { 0xbf27855f92dba7b6, 2, 163 },
        { 0xbf374b8eabd63568, 20, 154 },
        { 0xbf6f171e83660761, 33, 102 },
        { 0xbfc628d6a6a0bb45, 27, 105 },
        { 0xbfdb7d5617ff07d6, 18, 125 },
        { 0xc018e6c0bf3d253f, 27, 108 },
        { 0xc02ac78ae12a6577, 7, 148 },
        { 0xc07d602ddfdbb77b, 85, 181 },
        { 0xc07f9031797fa8cb, 27, 187 },
        { 0xc0ad6f3ae735fb3f, 20, 114 },
        { 0xc0e29cf73101030e, 0, 228 },
        { 0xc0edabc93af6bd50, 2, 102 },
        { 0xc104bfc6cb7e6bf8, 5, 110 },
        { 0xc1072849fdccb4b2, 0, 172 },
        { 0xc10dba28023b0684, 44, 240 },
        { 0xc1575dd48f3a72df, 33, 157 },
        { 0xc1a7332320ebbc3a, 7, 84 },
        { 0xc1bd310142106cb1, 24, 158 },
        { 0xc1e65a8a924884d2, 29, 215 },
        { 0xc207f7789a5f0f11, 21, 73 },
        { 0xc2123d9f415c5b0a, 7, 133 },
        { 0xc232f2ff08279dce, 7, 164 },
        { 0xc2415572a9927224, 0, 152 },
        { 0xc24d06e0cecb4276, 29, 167 },
        { 0xc25e1c0e8bb1acac, 42, 90 },
        { 0xc297078a7f0c92ad, 15, 137 },
        { 0xc2bcbd4e70a02eb1, 0, 118 },
        { 0xc2bcbf9cc24db01c, 100, 186 },
        { 0xc2c1c401b52c8e2e, 21, 113 },
        { 0xc2fe0aa22dd4fe83, 50, 100 },
        { 0xc305e6be7805bb88, 0, 68 },
        { 0xc32cbecef47fc667, 17, 130 },
        { 0xc3bced8b6b276c60, 0, 162 },
        { 0xc3c8d31c4cc2523f, 44, 154 },
        { 0xc3ce45257edceaa6, 35, 115 },
        { 0xc3d7604e02cd7d74, 0, 56 },
        { 0xc3fcd00459ec477b, 17, 74 },
        { 0xc4038f13370a94d0, 9, 224 },
        { 0xc406be7794d0d2df, 27, 136 },
        { 0xc414cc1265ff5206, 2, 149 },
        { 0xc42ffaff478d9471, 12, 110 },
        { 0xc445e7c031f07440, 2, 133 },
        { 0xc45505ae1ba6a9d1, 33, 90 },
        { 0xc464d44979a98f0b, 42, 80 },
        { 0xc47086b521f75673, 21, 76 },
        { 0xc487e32d8285b942, 0, 126 },
        { 0xc49eb2e5c74522c0, 17, 126 },
        { 0xc4e95cf0d996ab6b, 2, 64 },
        { 0xc4f45c0707948a59, 54, 198 },
        { 0xc51008299112dab0, 18, 120 },
        { 0xc555d06973dd6d54, 20, 173 },
        { 0xc56bf3324630a5a0, 7, 109 },
        { 0xc59f29d0f7ee6a98, 27, 109 },
        { 0xc5afc7268306326f, 82, 156 },
        { 0xc5f9e13762b9d0b8, 42, 223 },
        { 0xc6302aa54eadf48d, 32, 132 },
        { 0xc64c6cb16d6453e1, 2, 154 },
        { 0xc6517a9afaa92d24, 9, 177 },
        { 0xc68dbbc4a544e2ca, 47, 140 },
        { 0xc6a06d6be6064e93, 29, 145 },
        { 0xc6a6d9af6350452c, 0, 75 },
        { 0xc6a8bafaf2e247d3, 24, 109 },
        { 0xc6f04e27131f8420, 0, 107 },
        { 0xc6fd346ff864d089, 36, 162 },
        { 0xc727761fce953f65, 63, 171 },
        { 0xc742d778d4c95fb1, 42, 162 },
        { 0xc743777e651e64d6, 10, 116 },
        { 0xc74a5d1cdb6ff209, 17, 132 },
        { 0xc760da60fcc2c692, 24, 140 },
        { 0xc76366f7f49725fa, 0, 74 },
        { 0xc76d77e9d247d5ac, 0, 99 },
        { 0xc7c4a14fbe697e13, 55, 170 },
        { 0xc800d2e225ab3de5, 43, 138 },
        { 0xc819d32430d04474, 23, 125 },
        { 0xc84774c4aec58a24, 11, 153 },
        { 0xc862c8496e50d3ae, 37, 100 },
        { 0xc87df6931b1a146f, 9, 178 },
        { 0xc891c24372c18de2, 9, 107 },
        { 0xc89ab5657206b883, 34, 150 },
        { 0xc910cbda075e2e88, 0, 149 },
        { 0xc95e5fa9fd513384, 40, 109 },
        { 0xc9893f88da45f4b1, 33, 172 },
        { 0xc98b3e17fe122760, 36, 185 },
        { 0xc99502e46df5d5ae, 9, 90 },
        { 0xca0fbf643d425952, 49, 166 },
        { 0xca5cbf59b46e892b, 41, 153 },
        { 0xca7ce0a0d8b68144, 24, 84 },
        { 0xca81ecc5b3694ce1, 24, 143 },
        { 0xcaa8e7967450a381, 49, 109 },
        { 0xcaab85e3af47d3ca, 48, 130 },
        { 0xcac6e9d96c39cb27, 4, 158 },
        { 0xcad7f1fe05318307, 49, 114 },
        { 0xcad910f996402e64, 28, 151 },
        { 0xcaef5f37b110377b, 9, 119 },
        { 0xcaf51b9f35c17fb4, 9, 131 },
        { 0xcb0b278ccffcacfd, 46, 183 },
        { 0xcb2add03bfc71951, 29, 132 },
        { 0xcb32c6a552a1c7be, 14, 113 },
        { 0xcb6d2394425a6c75, 37, 194 },
        { 0xcb738fa74eaaa007, 0, 144 },
        { 0xcbaa9fa3bc466415, 7, 158 },
        { 0xcbb37a01a88b8dd6, 88, 211 },
        { 0xcbbe6cd0cf49a35a, 61, 190 },
        { 0xcbd2a8ab03d36a29, 16, 129 },
        { 0xcbe1191638d658c5, 27, 157 },
        { 0xcc2af20ed8927f50, 63, 222 },
        { 0xcc47393386eb5bfc, 14, 199 },
        { 0xcc837d40b0a45053, 15, 199 },
        { 0xccddecbfd3908187, 31, 91 },
        { 0xcd07a7dd6e04ede7, 18, 172 },
        { 0xcd3900c65823069d, 79, 170 },
        { 0xcd55092bd5dfc4e4, 25, 105 },
        { 0xcdb773e87aa53f86, 166, 234 },
        { 0xcdbacf30b8830043, 30, 96 },
        { 0xcdbe0c5100aaab94, 0, 117 },
        { 0xcdcb858c01d2720c, 57, 178 },
        { 0xce1841ffdfac064d, 31, 154 },
        { 0xce4ac150af1251fd, 27, 91 },
        { 0xce7195375ad16a07, 11, 194 },
        { 0xce75b46395137551, 20, 146 },
        { 0xcea091859edffb7a, 70, 148 },
        { 0xcea4f61a7e7130be, 49, 149 },
        { 0xcea8be5df90d2df4, 14, 155 },
        { 0xcebb441714f8c0f6, 27, 136 },
        { 0xcec7d64fa9ce9556, 14, 103 },
        { 0xcf26476397c300e3, 16, 99 },
        { 0xcf3cba69a25477e0, 60, 168 },
        { 0xcf6ef877cce4b28f, 0, 142 },
        { 0xcf8605db3e2066ac, 65, 169 },
        { 0xcfbc306c2368f7d9, 12, 125 },
        { 0xcfe9a1a43d4a739c, 16, 149 },
        { 0xcff5c8dfca3a46be, 41, 189 },
        { 0xd010e5225964a8b6, 19, 127 },
        { 0xd090145f0f9faa9d, 24, 137 },
        { 0xd0cfada8f2ab3fcc, 12, 173 },
        { 0xd101231317f80b0d, 7, 159 },
        { 0xd10c9d936bf311b7, 28, 139 },
        { 0xd16d388540a6e872, 7, 139 },
        { 0xd1de29852140d206, 2, 238 },
        { 0xd1ecdca19a7ff57f, 58, 174 },
        { 0xd1f2100ed480a670, 14, 141 },
        { 0xd20f10985adda329, 23, 158 },
        { 0xd2122268fdcd8272, 33, 133 },
        { 0xd21e587709d11a86, 0, 149 },
        { 0xd2311c223921b695, 35, 125 },
        { 0xd261c5dd6bc7ee9f, 24, 70 },
        { 0xd26b61541cca8f68, 7, 122 },
        { 0xd27c1e27812bfcd8, 17, 187 },
        { 0xd28c4a3bda75d471, 18, 119 },
        { 0xd2b52042f69a7949, 11, 104 },
        { 0xd2e4769a23ed2ff7, 16, 211 },
        { 0xd30ea3c4a64a252a, 9, 179 },
        { 0xd343efe79ef2103b, 31, 160 },
        { 0xd3fb04e8290eb89f, 46, 191 },
        { 0xd43233920209a202, 20, 132 },
        { 0xd47c56aae92d3f79, 15, 164 },
        { 0xd48dbc4653da6b34, 34, 154 },
        { 0xd4c5767aaf3208a4, 10, 204 },
        { 0xd5345be8fe2911bf, 31, 96 },
        { 0xd539467535f6522b, 5, 102 },
        { 0xd589ca1322c51835, 0, 72 },
        { 0xd5d14096f1355ae1, 4, 110 },
        { 0xd5d9a05f55923a54, 9, 148 },
        { 0xd5ebeb3bb12e1fa5, 28, 120 },
        { 0xd600ac9fadf6f6c4, 7, 139 },
        { 0xd650b1e47b18de22, 25, 170 },
        { 0xd68449933c1326bf, 11, 96 },
        { 0xd69de71b5d2d5f61, 20, 154 },
        { 0xd6bc167d46933f49, 24, 169 },
        { 0xd6bfdf713028dad0, 17, 112 },
        { 0xd719b033ae602af7, 18, 201 },
        { 0xd7333c0bce4b478a, 14, 181 },
        { 0xd73f1e47a889a996, 15, 156 },
        { 0xd746c3304d93396c, 18, 117 },
        { 0xd75ae769b09ee13c, 15, 76 },
        { 0xd795d833deb26049, 23, 110 },
        { 0xd7e9dc24efca7fac, 27, 169 },
        { 0xd7fe8981528bcefe, 0, 220 },
        { 0xd80ce2b92cf3ea66, 14, 149 },
        { 0xd81b1a432c4074ff, 14, 82 },
        { 0xd827fdb3c6c588d1, 2, 113 },
        { 0xd88901e0ba47e0c9, 0, 143 },
        { 0xd8e738e328c6efb3, 11, 148 },
        { 0xd900c1e527f1271e, 5, 127 },
        { 0xd9180579b92032ce, 46, 140 },
        { 0xd968ef825b01ed2d, 35, 218 },
        { 0xd973a4f18333c919, 31, 133 },
        { 0xd97f457ae08a743a, 2, 145 },
        { 0xd99c46088da26244, 40, 104 },
        { 0xd9b4b5b15c5dcddf, 11, 88 },
        { 0xd9e5488644d7ec85, 42, 84 },
        { 0xda08af375a7c32c6, 17, 124 },
        { 0xda109ac5dc3ae34b, 26, 151 },
        { 0xda542943b939f23f, 7, 152 },
        { 0xda74192b4680e0c0, 10, 162 },
        { 0xda7adf867f3c87c4, 21, 173 },
        { 0xda86e8db9b2cb5b9, 15, 113 },
        { 0xda8b6db8d2294e25, 60, 165 },
        { 0xdae03e7c34349a14, 24, 181 },
        { 0xdb053495566a2d30, 0, 215 },
        { 0xdb0781a24e28da86, 63, 230 },
        { 0xdb14615e0fb4e281, 24, 178 },
        { 0xdc5646085d68aeeb, 49, 173 },
        { 0xdcaca515c664f6a5, 70, 151 },
        { 0xdcc0f0a5ecbeb211, 10, 111 },
        { 0xdcc398f5affaadef, 31, 110 },
        { 0xdce1acf45276b786, 9, 166 },
        { 0xdce42ff103ee07a9, 0, 82 },
        { 0xdd0be660111ff675, 2, 148 },
        { 0xdd10cebe35f92d10, 104, 188 },
        { 0xdd41040e70ed5c8e, 35, 116 },
        { 0xdd422eb1ce557535, 9, 129 },
        { 0xdd73116daf40b90e, 26, 95 },
        { 0xdd7ecdf83db839a0, 7, 113 },
        { 0xdd899e3652968723, 44, 232 },
        { 0xdd94be70f8e7fe2a, 37, 159 },
        { 0xdd96acc525117fe8, 0, 107 },
        { 0xdd9d4d9ad015b48e, 19, 185 },
        { 0xddcd958879777c51, 17, 145 },
        { 0xdde879987590af41, 21, 151 },
        { 0xddf434e3d92f546c, 58, 174 },
        { 0xde063c5c561595e4, 19, 136 },
        { 0xde0c320c67568e6b, 16, 123 },
        { 0xde2e2dbc083d9bae, 15, 217 },
        { 0xde316b635f35cf1f, 34, 128 },
        { 0xde57c09d4d6ca1c7, 0, 111 },
        { 0xde7dd744beec8a79, 0, 79 },
        { 0xde85516120d88e47, 21, 115 },
        { 0xdea93024c15621de, 0, 133 },
        { 0xdec9ba6767d599f3, 17, 77 },
        { 0xdef206192a2db4be, 9, 65 },
        { 0xdefaaa0f5db4c2dd, 7, 187 },
        { 0xdeff667fb9330cee, 58, 229 },
        { 0xdf218df9aeb4fd03, 47, 222 },
        { 0xdf42b09b1a9664cd, 32, 207 },
        { 0xdf49369b8f4087b9, 22, 105 },
        { 0xdf4c02b3c17903c9, 35, 189 },
        { 0xdf4c08bdaedf698b, 40, 163 },
        { 0xdf5c2c0101502a0f, 26, 114 },
        { 0xdf6cd828b4433d38, 88, 146 },
        { 0xdf84098d6176b343, 40, 167 },
        { 0xdfecf3a160724dd4, 7, 126 },
        { 0xe014c3012581bef5, 28, 182 },
        { 0xe035f3e25d5be463, 0, 130 },
        { 0xe06888b2909a38c7, 31, 247 },
        { 0xe07eed37e2e5a5e8, 20, 188 },
        { 0xe0bb5bfc116fa1c1, 9, 96 },
        { 0xe0e598c1a7f6d99a, 75, 169 },
        { 0xe0f90bbd9e937f63, 12, 171 },
        { 0xe113238425323c08, 67, 185 },
        { 0xe115a05ac2d10403, 7, 210 },
        { 0xe140f211206bb23b, 18, 136 },
        { 0xe146a70f81a82614, 4, 154 },
        { 0xe15ed130c91a440c, 15, 176 },
        { 0xe17928f79b9227df, 0, 208 },
        { 0xe190fbc55f734001, 20, 111 },
        { 0xe19ee99a7eb8bda3, 10, 159 },
        { 0xe1a77418ed910c5a, 0, 147 },
        { 0xe1c7488b178efec4, 35, 95 },
        { 0xe1c80ed78dc0d43d, 46, 99 },
        { 0xe1f2affa45506117, 35, 177 },
        { 0xe200d6da3d44b9aa, 30, 161 },
        { 0xe290dfdb33e0f39c, 7, 133 },
        { 0xe2de16f8cd83ad38, 4, 99 },
        { 0xe2e6167bdf517013, 19, 171 },
        { 0xe31cd4bc8ee80871, 2, 87 },
        { 0xe33bfcf426b3e6b5, 32, 172 },
        { 0xe350d6b5bf35ca92, 24, 151 },
        { 0xe3aa2d22e709a3ba, 0, 118 },
        { 0xe3aa7127fe0a8308, 32, 87 },
        { 0xe3e6288922a471ff, 7, 146 },
        { 0xe3e8acb5a4edcb07, 37, 97 },
        { 0xe3fe605fff2a96c7, 0, 174 },
        { 0xe4b88123b10cc727, 33, 101 },
        { 0xe4d268df501d8181, 42, 160 },
        { 0xe4e83c396d6fd5c7, 0, 100 },
        { 0xe4f39b114dd96059, 16, 82 },
        { 0xe50e3d6fab056885, 60, 156 },
        { 0xe519545d74e46677, 52, 226 },
        { 0xe5406c7b92c47689, 34, 125 },
        { 0xe56baa9bac52c5ce, 15, 129 },
        { 0xe5b111801b5d5677, 7, 143 },
        { 0xe5f489ce584fcce3, 37, 96 },
        { 0xe5f6a767e81cbf2a, 42, 90 },
        { 0xe5fa50c406c62f28, 18, 78 },
        { 0xe5fd84050af1238c, 24, 207 },
        { 0xe60558d9ec64aefd, 10, 139 },
        { 0xe610678d115ab976, 43, 97 },
        { 0xe6144dde451feb08, 0, 129 },
        { 0xe6167ead08fe8b89, 5, 151 },
        { 0xe670130008be48cf, 4, 123 },
        { 0xe699d5387e8e4d7e, 63, 115 },
        { 0xe6fb1891235035ed, 23, 202 },
        { 0xe790492f77f78970, 12, 137 },
        { 0xe791aaa556960f75, 14, 81 },
        { 0xe7cf20cc6b19a345, 35, 206 },
        { 0xe7e51d822ee1076a, 17, 193 },
        { 0xe7f7a6ba11d5ef40, 10, 72 },
        { 0xe802d6473c35a9b4, 49, 84 },
        { 0xe81290e10e3c5de1, 28, 160 },
        { 0xe87b874c22ef9692, 11, 63 },
        { 0xe87b89b83317a064, 0, 173 },
        { 0xe94bf2c6e32f2cdf, 48, 137 },
        { 0xe94e47c49eecbad5, 0, 152 },
        { 0xe962d8953cd027d4, 32, 114 },
        { 0xe9cd1a60bbe53581, 14, 121 },
        { 0xe9e4e937cb4c51db, 10, 118 },
        { 0xea185efc9754e929, 34, 197 },
        { 0xea5ac88c59f20696, 0, 158 },
        { 0xea775aebff1c03e7, 39, 171 },
        { 0xea93b9dbd71cf21f, 37, 164 },
        { 0xeab23a531bfaa6c0, 25, 105 },
        { 0xeae1817da4af7272, 12, 110 },
        { 0xeaf1c83513867ac9, 3, 49 },
        { 0xeb20a24c56f33911, 17, 82 },
        { 0xeb4ace8d4dbed42f, 0, 79 },
        { 0xeb516956ee2749e3, 27, 147 },
        { 0xeb94cd4fa7a09a3a, 12, 55 },
        { 0xeb9505e7595b86bf, 39, 136 },
        { 0xeb9f8645e293e8dc, 9, 109 },
        { 0xeba809fec834f467, 81, 165 },
        { 0xebd157ada2510cb8, 25, 76 },
        { 0xebe8a204537bcecf, 16, 141 },
        { 0xebee14f7ba40e49f, 26, 145 },
        { 0xec444cbe95e90e41, 0, 176 },
        { 0xec990b3ed1a64771, 0, 201 },
        { 0xeca4591a3dbd2fcc, 44, 162 },
        { 0xed007ae11f0b6d8e, 15, 158 },
        { 0xed0510dff7682d8a, 0, 238 },
        { 0xed57f0329b33fff0, 45, 90 },
        { 0xeda3c7618ead95c5, 9, 168 },
        { 0xee17ea138c267ee2, 23, 129 },
        { 0xee5e4357aba76c79, 43, 156 },
        { 0xee65b4360bc86c10, 23, 122 },
        { 0xee9a8c1667b6f0b1, 0, 51 },
        { 0xeea8b5ed41ab6218, 14, 105 },
        { 0xeed8093f625587b2, 25, 131 },
        { 0xeefb8cee5e0e7c5a, 9, 105 },
        { 0xef2b9c7f53317a2f, 59, 140 },
        { 0xef37e7804f15cd3a, 0, 234 },
        { 0xefa2c7d3c016758f, 67, 202 },
        { 0xefb01141c8141afd, 28, 184 },
        { 0xefeb69fba0f2379f, 0, 151 },
        { 0xf00cf99dd2cba95d, 21, 164 },
        { 0xf024851e0c275f78, 10, 89 },
        { 0xf0545865e49b668c, 33, 165 },
        { 0xf09461599ded885c, 97, 134 },
        { 0xf0b4d73a56d5257a, 51, 95 },
        { 0xf10e30d97ceabd4f, 0, 171 },
        { 0xf11fed1def3950dc, 0, 102 },
        { 0xf173be7d0b4b5078, 43, 131 },
        { 0xf24068eed1637a59, 2, 137 },
        { 0xf2a4c454ee9d8cba, 16, 180 },
        { 0xf2cafac38e1bb95e, 7, 171 },
        { 0xf2e2dfc6a356b577, 89, 241 },
        { 0xf2e46679811bc9d6, 0, 123 },
        { 0xf2e65755511675be, 36, 179 },
        { 0xf2f2254b48fa73d5, 21, 119 },
        { 0xf3052c02362a7c6e, 75, 229 },
        { 0xf30ad0ecf1aa1d2d, 14, 175 },
        { 0xf3519ebedb7c7a5e, 26, 160 },
        { 0xf396d41209e60919, 7, 149 },
        { 0xf3afb5c423775dcc, 2, 156 },
        { 0xf3d5dbbcf85d0e81, 7, 164 },
        { 0xf432933f4b935817, 0, 122 },
        { 0xf4495bdcfb773a98, 25, 168 },
        { 0xf46eb824b2404553, 20, 82 },
        { 0xf48540e93369e579, 2, 114 },
        { 0xf4b1cd3fdf14469b, 36, 96 },
        { 0xf4b45b8e849b2d95, 14, 121 },
        { 0xf4b9df9d9935eaaf, 57, 125 },
        { 0xf4d843370d3b3496, 17, 154 },
        { 0xf4e95249da120903, 23, 107 },
        { 0xf4f04be02044bd0c, 40, 176 },
        { 0xf5230ed106df3514, 12, 86 },
        { 0xf554e4803655ad5f, 11, 90 },
        { 0xf55ee57f396ff7b5, 7, 81 },
        { 0xf572bd5f393b6c00, 34, 97 },
        { 0xf5c1924488c6e990, 12, 159 },
        { 0xf5c5752547b2ba79, 9, 152 },
        { 0xf5cad94ad3066f90, 24, 173 },
        { 0xf5f41410c0c1086f, 25, 116 },
        { 0xf5f80810264f62ff, 51, 123 },
        { 0xf61b800146839354, 18, 125 },
        { 0xf65b830b42495bf9, 7, 231 },
        { 0xf6af282bc263cb32, 11, 101 },
        { 0xf7132370f3524d75, 25, 93 },
        { 0xf72c14f88e4786f8, 24, 186 },
        { 0xf72d73608b5a452f, 17, 102 },
        { 0xf72e117e7f4b84f7, 84, 165 },
        { 0xf753f5fde1334391, 12, 77 },
        { 0xf768e0003567ae5c, 41, 140 },
        { 0xf77e160e2a5b3a60, 129, 207 },
        { 0xf780e70328751036, 31, 151 },
        { 0xf7b0b1a468e5a05b, 37, 135 },
        { 0xf805d356c9a6c2d0, 7, 120 },
        { 0xf80f17aa9d7a4418, 0, 153 },
        { 0xf82dbef53593098f, 2, 216 },
        { 0xf83ab0af7276468d, 76, 235 },
        { 0xf870a28019a1d618, 0, 99 },
        { 0xf8c1aa1fa125a8ca, 10, 247 },
        { 0xf8cdb968b4027b9e, 35, 201 },
        { 0xf8e9db46a8e40ed5, 27, 142 },
        { 0xf8f9bc2833c53a5e, 31, 217 },
        { 0xf9140cd61642a49e, 0, 116 },
        { 0xf915003e0a22d033, 15, 175 },
        { 0xf930837c8fe2a7b3, 33, 87 },
        { 0xf940a34f148c43e9, 7, 132 },
        { 0xf9451942ba08cae9, 0, 125 },
        { 0xf97b2b9993f6d07c, 8, 110 },
        { 0xf9834c8706c7f1f9, 15, 89 },
        { 0xf985d8d09e1d0d3c, 29, 158 },
        { 0xf9939193e295e767, 32, 206 },
        { 0xf9d3f21d9381a0dd, 18, 82 },
        { 0xfa2aacd51251f6d6, 15, 176 },
        { 0xfa5411db919a9ab7, 23, 175 },
        { 0xfa7001eb61afa815, 16, 98 },
        { 0xfa738c6d7a2905c7, 20, 97 },
        { 0xfa792372324a6eb8, 9, 122 },
        { 0xfa8e693da813405a, 0, 134 },
        { 0xfaa0b3db9b4c630d, 24, 157 },
        { 0xfabf88cefb81a333, 35, 140 },
        { 0xfaf8783f6fdee2cb, 20, 113 },
        { 0xfb6b21227ba29a7c, 92, 177 },
        { 0xfbdf0c3fc9562611, 42, 126 },
        { 0xfc113562142a1e77, 0, 84 },
        { 0xfc3307662a1fe23b, 7, 70 },
        { 0xfc4dc4c800ae0c7a, 77, 150 },
        { 0xfc66a03814c8a735, 52, 158 },
        { 0xfc9098f4eca876e1, 36, 113 },
        { 0xfc9d729fc614152b, 18, 178 },
        { 0xfca13e55cc6b0d12, 61, 168 },
        { 0xfcfeb83a6f9fb73c, 43, 109 },
        { 0xfcff397e5890b8a3, 51, 135 },
        { 0xfdd495c179e17300, 33, 89 },
        { 0xfde5104a8166eb04, 20, 140 },
        { 0xfe19291f3c9a767d, 21, 103 },
        { 0xfebc742ba565f08a, 10, 142 },
        { 0xfef5c06c42fcce74, 56, 132 },
        { 0xfefb4ff3bf481b76, 27, 161 },
        { 0xff044bbcc8c1703a, 9, 95 },
        { 0xff0c10896d38c41a, 44, 144 },
        { 0xff2080a5111218ea, 45, 165 },
        { 0xff307a9be38271c5, 19, 113 },
        { 0xff63e13746309d15, 0, 95 },
        { 0xff8d6ab61e61bbc1, 111, 169 },
        { 0xff90c462ed8f4e70, 20, 189 },
        { 0xffa181ae3dd430a0, 31, 147 },
        { 0xffb4aad3f5340097, 16, 127 },
        { 0xffd9d3b61eaec92d, 105, 155 },
        { 0xfff36d5a5023683c, 7, 144 },
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
        { &tooie::picture_filters::parallax_original_option, true },
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
    // Parallax on the original textures (by their brightness) as well as on texture packs' height maps;
    // TOOIE_PARALLAX_ORIGINAL=0 or 1 sets it instead.
    bool parallax_original = value<bool>(parallax_original_option, true);
    if (const char* forced = std::getenv("TOOIE_PARALLAX_ORIGINAL")) {
        parallax_original = std::atoi(forced) != 0;
    }
    const char* parallax_all = std::getenv("TOOIE_PARALLAX_ALL");
    RT64::SetSceneParallax((float)(parallax / 100.0), parallax_original, (parallax_all != nullptr) && (std::atoi(parallax_all) != 0));
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
        "Stone walls, paving and rock get depth: the stones stand out of the surface and the gaps and cracks between them sink in and fall into shadow, shifting as the camera moves, instead of looking painted on. Texture packs can give their textures depth with height maps (see Parallax on original textures). Higher numbers are deeper. Drawn on the picture, so nothing in the game changes. 0 is off.",
        0, 100, 5, 0, false, 0);
    graphics.add_bool_option(
        parallax_original_option,
        "Parallax on original textures",
        "Parallax on the game's own stone, brick and rock textures, whose depth is worked out from how dark each part is. Off, only a texture pack's textures that come with a height map get parallax (a pack's \"wall.png\" with \"wall_height.png\" beside it, white high and black deep).",
        true);
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
                                   &eye_adaptation_option, &rim_light_option, &underwater_tint_option, &underwater_haze_option, &heat_haze_option, &underwater_distortion_option, &water_reflections_option, &bounce_light_option, &texture_upscale_option, &water_waves_option, &wave_speed_option, &light_shafts_option, &sun_shadows_option, &sun_shadow_banjo_option, &sun_shadow_softness_option, &grass_option, &grass_height_option, &grass_distance_option, &grass_density_option, &grass_patches_option, &grass_thickness_option, &grass_random_length_option, &grass_blend_option, &grass_chunky_option, &grass_chunk_size_option, &grass_pixelated_option, &grass_pixel_size_option, &grass_edges_option, &deep_snow_option, &snow_height_option, &parallax_option, &parallax_original_option, &banjo_fur_option, &banjo_fur_length_option, &banjo_fur_density_option, &banjo_fur_noisiness_option, &kazooie_feathers_option, &kazooie_feather_size_option, &kazooie_feather_length_option, &kazooie_feather_density_option, &kazooie_feather_noisiness_option, &kazooie_feather_transparency_option, &enemy_fur_option, &water_option, &shore_foam_option, &lighting_section_option }) {
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
    graphics.add_option_hidden_dependency(parallax_original_option, lighting_section_option, false);
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
