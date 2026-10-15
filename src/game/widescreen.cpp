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
#include <cstring>

#include "recomp.h"
#include "funcs.h"
#include "recompui/recompui.h"
#include "ultramodern/config.hpp"
#include "tooie_game.h"

namespace {
    constexpr float original_aspect = 4.0f / 3.0f;

    // Extra degrees around a widened view. In a wide window, models near the edges were dropped
    // while still partly on screen (Bottles' burnt body lost its parts at the bottom-left corner,
    // and with HD shadows only its shadow stayed): the game tests each model with a sphere that
    // can be smaller than the model (61 units for that body), and the planes sit right on the
    // picture's edge. The sides get this margin and the top and bottom half of it; it costs a few
    // more models drawn just outside the picture.
    constexpr float wide_margin_degrees = 10.0f;

    float side_angle(float aspect_times_half_fov) {
        const float scale = tooie::widescreen_scale();
        float angle = aspect_times_half_fov * scale;
        if (scale > 1.0f) {
            angle += wide_margin_degrees;
        }
        return std::min(angle, 89.0f);
    }
}

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
    ctx->r6 = float_bits(tooie::widescreen_scale() > 1.0f ? std::min(half_fov + wide_margin_degrees * 0.5f, 89.0f) : half_fov);
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
