// Widescreen culling (handoff 4.22).
//
// With the graphics option Aspect Ratio set to Expand, RT64 widens the game's
// viewports to the window shape and scales every perspective projection to
// match, so the 3D view already fills the window undistorted. The game itself
// still culls against a 4:3 view, though, so objects near the left and right
// edges of a wide window would vanish before they leave the picture.
//
// func_800CA2A8(camera, half_fov) builds a camera's culling planes from its
// field of view and its aspect ratio (camera + 0xE8). banjotooie.us.toml marks
// it as ignored and this host version builds the same planes with the aspect
// widened by as much as RT64 widens the picture. The aspect stored in the
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
