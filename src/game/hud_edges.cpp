// HUD at the screen edges (handoff 4.22, "Edge HUD").
//
// With Aspect Ratio set to Expand or Letterbox 16:9, RT64 keeps the game's 2D
// in the middle 4:3 of a wide picture. This moves the in-game HUD groups out to the window edges:
// honeycombs and air on the left, notes, feathers and eggs on the right, the
// middle (jiggies) where it is.
//
// The HUD is drawn by the infobar overlay, one element per call to
// scinfobar_entrypoint_24(gfx_ctx, element, ...). banjotooie.us.toml hooks its
// entry and its return. At the return, the display list the element just
// wrote is scanned: every model matrix load (G_MTX) carries the sprite's x
// translation in the game's 2D space (4 units per screen pixel, -608..608),
// and every texture rectangle (G_TEXRECT, the digits) its x in screen pixels.
// If the element sits in the left or right quarter of the screen, its matrices
// are moved out by the extra width RT64 adds on that side (edited in place,
// once each), and its rectangles are redrawn anchored to that window edge.
// HUD Ratio limits the spread: Original keeps the HUD in the 4:3 middle,
// Clamp16x9 stops at 16:9. Both options are read every frame.

#include <algorithm>
#include <cmath>
#include <vector>

#include "recomp.h"
#include "ultramodern/config.hpp"
#include "tooie_game.h"
#include "tooie_hooks.h"

namespace {
    constexpr float units_per_pixel = 4.0f;
    constexpr float screen_width = 304.0f;
    constexpr float half_width_units = screen_width * units_per_pixel / 2.0f;
    // Elements whose sprites average further out than this are edge elements.
    constexpr float edge_zone_units = half_width_units / 2.0f;

    constexpr uint32_t op_mtx = 0xDA;
    constexpr uint32_t op_texrect = 0xE4;
    constexpr uint32_t op_rdphalf_1 = 0xE1;
    constexpr uint32_t op_rdphalf_2 = 0xF1;
    constexpr uint32_t op_dl = 0xDE;
    constexpr uint32_t op_enddl = 0xDF;
    constexpr uint32_t dl_branch = 0x01;
    // F3DEX2 stores G_MTX params with G_MTX_PUSH inverted.
    constexpr uint32_t mtx_push = 0x01;
    constexpr uint32_t mtx_load = 0x02;
    constexpr uint32_t mtx_projection = 0x04;

    // RT64 extended GBI (lib/rt64/include/rt64_extended_gbi.h).
    constexpr uint32_t rt64_hook_word0 = 0xE0000000 | 0x525464;
    constexpr uint32_t rt64_extended_opcode = 0x64;
    constexpr uint32_t rt64_hook_op_enable = 0x1;
    constexpr uint32_t g_ex_texrect_v1 = 0x000002;
    constexpr uint32_t g_ex_setscissor_v1 = 0x000005;
    constexpr uint32_t g_ex_pushscissor_v1 = 0x000017;
    constexpr uint32_t g_ex_popscissor_v1 = 0x000018;
    constexpr uint32_t g_sc_non_interlace = 0;
    constexpr uint32_t screen_height = 228;
    constexpr uint32_t g_ex_origin_left = 0x0;
    constexpr uint32_t g_ex_origin_right = 0x400;

    gpr span_gfx_ctx = 0;
    uint32_t span_gfx_start = 0;

    gpr to_kseg0(uint32_t addr) {
        return (int32_t)((addr & 0x1FFFFFFF) | 0x80000000);
    }

    // N64 fixed-point matrix: 16 integer halfwords, then 16 fraction
    // halfwords. The x translation is element [3][0].
    float read_translation_x(uint8_t* rdram, gpr mtx) {
        int16_t whole = (int16_t)MEM_HU(24, mtx);
        uint16_t frac = MEM_HU(56, mtx);
        return (float)((int32_t)((uint32_t)(uint16_t)whole << 16 | frac)) / 65536.0f;
    }

    // Appends one command at the graphics context's display list pointer.
    void append_command(uint8_t* rdram, gpr gfx_ctx, uint32_t w0, uint32_t w1) {
        uint32_t gfx = (uint32_t)MEM_W(0, gfx_ctx);
        gpr cmd = to_kseg0(gfx);
        MEM_W(0, cmd) = (int32_t)w0;
        MEM_W(4, cmd) = (int32_t)w1;
        MEM_W(0, gfx_ctx) = (int32_t)(gfx + 8);
    }

    uint32_t ex_word0(uint32_t command) {
        return (rt64_extended_opcode << 24) | command;
    }

    // How much wider than 4:3 the HUD spreads: the window's extra width, up to
    // the limit the HUD Ratio option sets (RT64 applies the same limit to the
    // edge-anchored rectangles).
    float hud_scale() {
        float scale = tooie::widescreen_scale();
        switch (ultramodern::renderer::get_graphics_config().hr_option) {
            case ultramodern::renderer::HUDRatioMode::Original:
                return 1.0f;
            case ultramodern::renderer::HUDRatioMode::Clamp16x9:
                return std::min(scale, (16.0f / 9.0f) / (4.0f / 3.0f));
            default:
                return scale;
        }
    }

    void write_translation_x(uint8_t* rdram, gpr mtx, float x) {
        int32_t fixed = (int32_t)std::lround(x * 65536.0f);
        MEM_H(24, mtx) = (int16_t)((uint32_t)fixed >> 16);
        MEM_H(56, mtx) = (int16_t)((uint32_t)fixed & 0xFFFF);
    }
}

// Entry of scinfobar_entrypoint_24: $a0 is the graphics context, whose first
// word is the display list pointer.
extern "C" void tooie_hud_element_begin(uint8_t* rdram, recomp_context* ctx) {
    gpr gfx_ctx = ctx->r4;
    span_gfx_ctx = gfx_ctx;
    if (hud_scale() > 1.0f) {
        // gEXEnable, harmless when repeated.
        append_command(rdram, gfx_ctx, rt64_hook_word0, (rt64_hook_op_enable << 28) | rt64_extended_opcode);
    }
    span_gfx_start = (uint32_t)MEM_W(0, gfx_ctx);
}

// Return of scinfobar_entrypoint_24.
extern "C" void tooie_hud_element_end(uint8_t* rdram, recomp_context* ctx) {
    if (span_gfx_ctx == 0) {
        return;
    }
    gpr gfx_ctx = span_gfx_ctx;
    span_gfx_ctx = 0;
    uint32_t start = span_gfx_start;
    uint32_t end = (uint32_t)MEM_W(0, gfx_ctx);
    float scale = hud_scale();
    if (scale <= 1.0f) {
        return;
    }
    if (end <= start || end - start > 0x10000) {
        return;
    }

    std::vector<gpr> matrices;
    std::vector<uint32_t> texrects;
    float sum = 0.0f;
    int count = 0;
    for (uint32_t cmd = start; cmd < end; cmd += 8) {
        uint32_t w0 = (uint32_t)MEM_W(0, to_kseg0(cmd));
        uint32_t w1 = (uint32_t)MEM_W(4, to_kseg0(cmd));
        uint32_t op = w0 >> 24;
        uint32_t params = (w0 & 0xFF) ^ mtx_push;
        // Model matrices, and matrices multiplied onto the projection (some
        // sprites carry their position there). Not the ortho projection
        // itself, which every element shares.
        bool positions = (params & mtx_projection) == 0 || (params & mtx_load) == 0;
        if (op == op_mtx && positions && ((w1 >> 24) == 0x00 || (w1 >> 24) == 0x80)) {
            gpr mtx = to_kseg0(w1);
            if (std::find(matrices.begin(), matrices.end(), mtx) != matrices.end()) {
                continue;
            }
            matrices.push_back(mtx);
            float x = read_translation_x(rdram, mtx);
            if (x != 0.0f) {
                sum += x;
                count++;
            }
        }
        else if (op == op_texrect && cmd + 24 <= end) {
            texrects.push_back(cmd);
        }
    }
    if (count == 0) {
        return;
    }
    float average = sum / count;
    bool right;
    if (average < -edge_zone_units) {
        right = false;
    }
    else if (average > edge_zone_units) {
        right = true;
    }
    else {
        return;
    }

    float shift_units = half_width_units * (scale - 1.0f) * (right ? 1.0f : -1.0f);
    for (gpr mtx : matrices) {
        float x = read_translation_x(rdram, mtx);
        if (x != 0.0f) {
            write_translation_x(rdram, mtx, x + shift_units);
        }
    }

    // G_TEXRECT (the counter digits) is followed by RDPHALF_1 (s, t) and
    // RDPHALF_2 (dsdx, dtdy). Each one becomes a call to a short display list
    // that draws it as RT64's gEXTextureRectangle anchored to the window edge,
    // inside a scissor as wide as the window (the game's scissor is the middle
    // 4:3). Only the rectangles get the wide scissor: RT64 stops widening the
    // element's ortho sprites when their scissor differs from the frame's.
    // The display lists are written after the element's commands, behind a
    // branch that skips them.
    std::vector<uint32_t> rewrite;
    for (uint32_t cmd : texrects) {
        gpr addr = to_kseg0(cmd);
        if (((uint32_t)MEM_W(8, addr) >> 24) == op_rdphalf_1 && ((uint32_t)MEM_W(16, addr) >> 24) == op_rdphalf_2) {
            rewrite.push_back(cmd);
        }
    }
    if (rewrite.empty()) {
        return;
    }

    constexpr uint32_t sub_list_bytes = 8 * 8;
    uint32_t branch = end;
    uint32_t after = branch + 8 + (uint32_t)rewrite.size() * sub_list_bytes;
    gpr out = to_kseg0(branch);
    MEM_W(0, out) = (int32_t)(op_dl << 24 | dl_branch << 16);
    MEM_W(4, out) = (int32_t)(after & 0x1FFFFFFF);

    uint32_t origin = right ? g_ex_origin_right : g_ex_origin_left;
    // Right-anchored coordinates count from the right edge of the screen.
    int32_t origin_offset = right ? -(int32_t)(screen_width * units_per_pixel) : 0;
    uint32_t sub = branch + 8;
    for (uint32_t cmd : rewrite) {
        gpr addr = to_kseg0(cmd);
        uint32_t w0 = (uint32_t)MEM_W(0, addr);
        uint32_t w1 = (uint32_t)MEM_W(4, addr);
        uint32_t st = (uint32_t)MEM_W(12, addr);
        uint32_t steps = (uint32_t)MEM_W(20, addr);
        int32_t lrx = (int32_t)((w0 >> 12) & 0xFFF) + origin_offset;
        int32_t lry = (int32_t)(w0 & 0xFFF);
        uint32_t tile = (w1 >> 24) & 0x7;
        int32_t ulx = (int32_t)((w1 >> 12) & 0xFFF) + origin_offset;
        int32_t uly = (int32_t)(w1 & 0xFFF);

        const uint32_t words[16] = {
            ex_word0(g_ex_pushscissor_v1), 0,
            // gEXSetScissor(G_SC_NON_INTERLACE, LEFT, RIGHT, 1, 0, 0, height).
            // The left edge is 1 pixel in: at 0, RT64's misalignment
            // correction makes the scissor start at -1 and the draw is lost.
            ex_word0(g_ex_setscissor_v1), g_sc_non_interlace | g_ex_origin_left << 2 | g_ex_origin_right << 14,
            (uint32_t)(1 * units_per_pixel) << 16, screen_height * (uint32_t)units_per_pixel,
            ex_word0(g_ex_texrect_v1), tile | origin << 3 | origin << 15,
            ((uint32_t)ulx & 0xFFFF) << 16 | ((uint32_t)uly & 0xFFFF), ((uint32_t)lrx & 0xFFFF) << 16 | ((uint32_t)lry & 0xFFFF),
            st, steps,
            ex_word0(g_ex_popscissor_v1), 0,
            op_enddl << 24, 0,
        };
        gpr list = to_kseg0(sub);
        for (int i = 0; i < 16; i++) {
            MEM_W(i * 4, list) = (int32_t)words[i];
        }

        // The texrect's three commands: call the list, then two no-ops.
        MEM_W(0, addr) = (int32_t)(op_dl << 24);
        MEM_W(4, addr) = (int32_t)(sub & 0x1FFFFFFF);
        for (int i = 8; i < 24; i += 4) {
            MEM_W(i, addr) = 0;
        }
        sub += sub_list_bytes;
    }
    MEM_W(0, gfx_ctx) = (int32_t)after;
}
