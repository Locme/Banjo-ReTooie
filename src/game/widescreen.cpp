// Widescreen culling (handoff 4.22).
//
// With the graphics option Aspect Ratio set to Expand, RT64 widens the game's
// viewports to the window shape and scales every perspective projection to
// match, so the 3D view already fills the window undistorted. The game itself
// still culls against a 4:3 view, though, so objects near the left and right
// edges of a wide window would vanish before they leave the picture.
//
// func_800CA2A8(camera, half_fov) and func_800CA218(camera, half_fov) build a
// camera's culling planes from its field of view and its aspect ratio
// (camera + 0xE8); func_800CA218, and func_800CA1B0 when the field of view
// changes, make the left and right ones, which the map geometry is culled
// against. banjotooie.us.toml marks all three as ignored and these host
// versions build the same planes with the aspect widened by as much as RT64
// widens the picture. The aspect stored in the
// camera, which the projection uses, is left alone. The option is read every
// time the planes are rebuilt, so switching it applies without a restart.

#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "recomp.h"
#include "funcs.h"
#include "recompui/recompui.h"
#include "ultramodern/config.hpp"
#include "tooie_debug.h"
#include "tooie_game.h"
#include "tooie_gfx_budget.h"
#include "tooie_hooks.h"
#include "tooie_picture_filters.h"
#include "tooie_volumetric_shadows.h"
#include "tooie_rdram.h"

namespace {
    constexpr float original_aspect = 4.0f / 3.0f;

    // Extra degrees around a widened view. In a wide window, models near the edges were dropped
    // while still partly on screen (Bottles' burnt body lost its parts at the bottom-left corner,
    // and with HD shadows only its shadow stayed): the game tests each model with a sphere that
    // can be smaller than the model (61 units for that body), and the planes sit right on the
    // picture's edge. The sides get this margin and the top and bottom half of it; it costs a few
    // more models drawn just outside the picture.
    constexpr float wide_margin_degrees = 10.0f;

    // Sun shadows come from the sun shadow map, which draws what the game drew: a cliff or ledge just past
    // the picture's edge, culled by the game, cast no shadow into it (the left and top of the title screen
    // stayed lit). With sun shadows on, every side keeps this much more.
    constexpr float sun_shadow_margin_degrees = 25.0f;

    float sun_margin() {
        return (tooie::picture_filters::sun_shadows_on() || (tooie::volumetric_shadows::sun_distance() > 0.0f)) ? sun_shadow_margin_degrees : 0.0f;
    }

    float side_angle(float aspect_times_half_fov) {
        const float scale = tooie::widescreen_scale();
        float angle = aspect_times_half_fov * scale;
        if (scale > 1.0f) {
            angle += wide_margin_degrees;
        }
        return std::min(angle + sun_margin(), 89.0f);
    }
}

// The intro ("Two years have passed..", map 0xA1) is widened like everything else. Its opening shot
// was zoomed to hide the ends of its 4:3 cloud backdrop (T403) until L chose the normal wide view
// (2026-10-21): the zoom cut a lot of the picture in a wide window and looked unlike the game after it.

// How much wider than 4:3 RT64 draws the picture.
float tooie::widescreen_scale() {
    const auto& config = ultramodern::renderer::get_graphics_config();
    // Manual is the Letterbox 16:9 choice: RT64 draws a 16:9 view
    // (its default manual target) and adds bars around it.
    if (config.ar_option == ultramodern::renderer::AspectRatio::Manual) {
        return (16.0f / 9.0f) / original_aspect;
    }
    if (config.ar_option != ultramodern::renderer::AspectRatio::Expand) {
        return 1.0f;
    }
    int width = 0;
    int height = 0;
    recompui::get_window_size(width, height);
    if (width <= 0 || height <= 0) {
        return 1.0f;
    }
    return std::max((float)width / (float)height, original_aspect) / original_aspect;
}

namespace {
    float load_float(uint8_t* rdram, gpr base, int32_t offset) {
        uint32_t bits = MEM_W(offset, base);
        float value;
        std::memcpy(&value, &bits, sizeof(value));
        return value;
    }

    void store_float(uint8_t* rdram, gpr base, int32_t offset, float value) {
        uint32_t bits;
        std::memcpy(&bits, &value, sizeof(bits));
        MEM_W(offset, base) = bits;
    }
}

// void func_800CA2A8(Camera* camera, f32 half_fov)
// The same steps as the game's version, in the same order.
extern "C" void func_800CA2A8(uint8_t* rdram, recomp_context* ctx) {
    gpr camera = ctx->r4;

    MEM_W(0x110, camera) = 0;
    ctx->f12.u32l = (uint32_t)ctx->r5;

    func_800137F4(rdram, ctx);
    float sine = ctx->f0.fl;
    store_float(rdram, camera, 0x120, sine);
    store_float(rdram, camera, 0x114, -sine);

    func_80013788(rdram, ctx);
    float cosine = ctx->f0.fl;
    store_float(rdram, camera, 0x124, -cosine);
    store_float(rdram, camera, 0x118, -cosine);

    float aspect = load_float(rdram, camera, 0xE8) * tooie::widescreen_scale();
    store_float(rdram, camera, 0x11C, load_float(rdram, camera, 0x120) * aspect);

    ctx->r4 = camera + 0x11C;
    func_800EF2A0(rdram, ctx);
}

// void func_800CA218(Camera* camera, f32 half_fov)
// Builds the directions the left and right culling planes come from: (-1, 0, 0)
// turned by aspect * half_fov degrees (an angle, not a tangent). The same
// steps as the game's version, with the aspect widened as above. The angle is
// kept under 90 degrees, past which the planes would flip.
extern "C" void func_800CA218(uint8_t* rdram, recomp_context* ctx) {
    gpr camera = ctx->r4;
    uint32_t half_fov_bits = (uint32_t)ctx->r5;
    float half_fov;
    std::memcpy(&half_fov, &half_fov_bits, sizeof(half_fov));

    auto float_bits = [](float value) {
        uint32_t bits;
        std::memcpy(&bits, &value, sizeof(bits));
        return (gpr)(int32_t)bits;
    };

    // camera + 0x104 = (0, 1, 0) turned by half_fov (and half the margin in a wide view).
    ctx->r4 = camera + 0x104;
    ctx->r5 = float_bits(0.0f);
    ctx->r6 = float_bits(1.0f);
    ctx->r7 = float_bits(0.0f);
    func_800EFA4C(rdram, ctx);
    ctx->r4 = camera + 0x104;
    ctx->r5 = camera + 0x104;
    ctx->r6 = float_bits(std::min(half_fov + (tooie::widescreen_scale() > 1.0f ? wide_margin_degrees * 0.5f : 0.0f) + sun_margin(), 89.0f));
    func_800EF8BC(rdram, ctx);

    // camera + 0xF8 = (-1, 0, 0) turned by aspect * half_fov.
    ctx->r4 = camera + 0xF8;
    ctx->r5 = float_bits(-1.0f);
    ctx->r6 = float_bits(0.0f);
    ctx->r7 = float_bits(0.0f);
    func_800EFA4C(rdram, ctx);
    float angle = side_angle(load_float(rdram, camera, 0xE8) * half_fov);
    ctx->r4 = camera + 0xF8;
    ctx->r5 = camera + 0xF8;
    ctx->r6 = float_bits(angle);
    func_800EF934(rdram, ctx);
}

// void func_800CA1B0(Camera* camera)
// Rebuilds the left and right plane direction from the camera's field of view
// (camera + 0xE4): (-1, 0, 0) turned by 0.5 * fov * aspect. Widened as above.
extern "C" void func_800CA1B0(uint8_t* rdram, recomp_context* ctx) {
    gpr camera = ctx->r4;
    auto float_bits = [](float value) {
        uint32_t bits;
        std::memcpy(&bits, &value, sizeof(bits));
        return (gpr)(int32_t)bits;
    };

    ctx->r4 = camera + 0xF8;
    ctx->r5 = float_bits(-1.0f);
    ctx->r6 = float_bits(0.0f);
    ctx->r7 = float_bits(0.0f);
    func_800EFA4C(rdram, ctx);
    float angle = side_angle(load_float(rdram, camera, 0xE4) * 0.5f * load_float(rdram, camera, 0xE8));
    ctx->r4 = camera + 0xF8;
    ctx->r5 = camera + 0xF8;
    ctx->r6 = float_bits(angle);
    func_800EF934(rdram, ctx);
}

// Sun shadows: the game culls what is out of view with two tests, func_800E3E8C(position, radius) for spheres
// (models, effects) and func_800E3D0C(min, max) for boxes (the level's own geometry, in pieces). The sun shadow maps
// only hold what the game drew, so a cliff just off screen cast its shadow while the camera faced one way and lost
// it as the camera turned (L's burst of 2026-10-17: a cliff's shadow across Spiral Mountain's path came and went).
// With sun shadows on, the whole level counts as in view (the far map covers it all) and models within the Sun
// shadow distance do, so the maps hold the same casters whichever way the camera faces. What lands off screen costs
// the main picture little: the graphics card drops those triangles before drawing any of their pixels. Both hooks run at the test's
// end, its answer in $v1 and its arguments still on its stack. Only while the frame's drawing buffers have room
// (gfx_budget), as for the other extras.
namespace {
    float sun_cull_distance(uint8_t* rdram) {
        // Test aid: TOOIE_SUN_CULL=0 leaves the game's culling alone, to compare. TOOIE_SUN_CULL=<from>-<to>[,...]
        // does so only between those times (ms after the first call), to compare one camera in one run.
        static const char* cull_env = std::getenv("TOOIE_SUN_CULL");
        if (cull_env != nullptr) {
            static const auto first_call = std::chrono::steady_clock::now();
            const long long ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - first_call).count();
            bool in_window = std::strcmp(cull_env, "0") == 0;
            for (const char* p = cull_env; !in_window && *p != '\0';) {
                char* end = nullptr;
                const long long from = std::strtoll(p, &end, 10);
                const long long to = (*end == '-') ? std::strtoll(end + 1, &end, 10) : from;
                in_window = ms >= from && ms < to;
                if (*end != ',') {
                    break;
                }
                p = end + 1;
            }
            static bool was_in_window = false;
            if (in_window != was_in_window) {
                was_in_window = in_window;
                printf("[sun-cull] %s at %lld ms\n", in_window ? "off" : "on", ms);
                fflush(stdout);
            }
            if (in_window) {
                return 0.0f;
            }
        }
        // Volumetric shadows' sun shafts need the same (their own map holds only what the game drew too).
        return std::max(tooie::picture_filters::sun_shadow_distance(), tooie::volumetric_shadows::sun_distance());
    }

    // The camera's position (the culling planes are relative to it), false if there is no camera.
    bool camera_position(uint8_t* rdram, float out[3]) {
        const uint32_t camera = tooie::rdram::read_word(rdram, 0x8012D500u);
        if (!tooie::rdram::valid_ptr(camera)) {
            return false;
        }
        for (uint32_t axis = 0; axis < 3; axis++) {
            out[axis] = tooie::rdram::read_float(rdram, camera + 4 * axis);
        }
        return true;
    }

    void keep(uint8_t* rdram, recomp_context* ctx, float distance) {
        if (!tooie::gfx_budget::room_for_extras(rdram)) {
            return;
        }
        ctx->r3 = 1;
        // Test aid: TOOIE_SUN_CULL_LOG=1 prints how many culled spheres and boxes were kept, every 2 s.
        static const bool log = std::getenv("TOOIE_SUN_CULL_LOG") != nullptr;
        if (log) {
            static uint32_t kept = 0;
            static auto last = std::chrono::steady_clock::now();
            kept++;
            const auto now = std::chrono::steady_clock::now();
            if (now - last >= std::chrono::seconds(2)) {
                printf("[sun-cull] kept %u culled spheres and boxes in 2 s (models within %.0f)\n", kept, distance);
                fflush(stdout);
                kept = 0;
                last = now;
            }
        }
    }
}

extern "C" void tooie_sun_shadow_cull(uint8_t* rdram, recomp_context* ctx) {
    if (ctx->r3 != 0) {
        return;
    }
    const float distance = sun_cull_distance(rdram);
    float camera[3];
    const uint32_t position = (uint32_t)MEM_W(0x28, ctx->r29);
    if (distance <= 0.0f || !tooie::rdram::valid_ptr(position) || !camera_position(rdram, camera)) {
        return;
    }
    const uint32_t radius_bits = (uint32_t)MEM_W(0x2C, ctx->r29);
    float radius;
    std::memcpy(&radius, &radius_bits, sizeof(radius));
    float dist2 = 0.0f;
    for (uint32_t axis = 0; axis < 3; axis++) {
        const float d = tooie::rdram::read_float(rdram, position + 4 * axis) - camera[axis];
        dist2 += d * d;
    }
    const float reach = distance + std::max(radius, 0.0f);
    if (dist2 < reach * reach) {
        keep(rdram, ctx, distance);
    }
}

extern "C" void tooie_sun_shadow_cull_box(uint8_t* rdram, recomp_context* ctx) {
    // Test aid: with TOOIE_SUN_CULL_LOG=1, also the extent of every box tested (the level's size) every 2 s.
    static const bool log = std::getenv("TOOIE_SUN_CULL_LOG") != nullptr;
    if (log) {
        static float lo[3] = { 1e9f, 1e9f, 1e9f }, hi[3] = { -1e9f, -1e9f, -1e9f };
        static auto last = std::chrono::steady_clock::now();
        const uint32_t box_min = (uint32_t)MEM_W(0x50, ctx->r29);
        const uint32_t box_max = (uint32_t)MEM_W(0x54, ctx->r29);
        if (tooie::rdram::valid_ptr(box_min) && tooie::rdram::valid_ptr(box_max)) {
            for (uint32_t axis = 0; axis < 3; axis++) {
                lo[axis] = std::min(lo[axis], tooie::rdram::read_float(rdram, box_min + 4 * axis));
                hi[axis] = std::max(hi[axis], tooie::rdram::read_float(rdram, box_max + 4 * axis));
            }
        }
        const auto now = std::chrono::steady_clock::now();
        if (now - last >= std::chrono::seconds(2)) {
            printf("[sun-cull] map 0x%X boxes span x %.0f..%.0f y %.0f..%.0f z %.0f..%.0f\n", tooie::debug::current_map(rdram), lo[0], hi[0], lo[1], hi[1], lo[2], hi[2]);
            fflush(stdout);
            for (uint32_t axis = 0; axis < 3; axis++) {
                lo[axis] = 1e9f;
                hi[axis] = -1e9f;
            }
            last = now;
        }
    }
    if (ctx->r3 != 0) {
        return;
    }
    // The level's own pieces are all kept, wherever they are: the far sun shadow map covers the whole level.
    const float distance = sun_cull_distance(rdram);
    if (distance > 0.0f) {
        keep(rdram, ctx, distance);
    }
}
