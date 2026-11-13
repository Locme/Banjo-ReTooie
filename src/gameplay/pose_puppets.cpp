// Pose puppets: extra copies of Banjo's model, each posed by an animation controller of its own, drawn without
// moving the player's Banjo or the camera. Photo mode films its pose cards with them, off screen (film_*), and the
// console's `puppet` command draws some beside Banjo to look at (add, clear, list).
//
// How the game draws a posed model (read from the recompiled code; the decomp leaves these as assembly):
//   - An animation controller (func_8008AD80(1), from the game's heap; freed with func_8008ADBC) is set up as the
//     player's states do: anctrl_reset, anctrl_setSmoothTransition 0, anctrl_setIndex (the animation id),
//     anctrl_setDuration, anctrl_setPlaybackType, anctrl_start. Its place in the animation, 0 to 1, is the float
//     at +0x2C. func_8008B304(ctrl) works out the bone transforms for that place; func_8008B4D4(ctrl) returns them.
//   - func_800DF41C(list) hands them to the next model draw, func_800DE498, which turns them into bone matrices
//     with the model's skeleton. func_800DE448(position, rotation (degrees), scale, 0, model) draws (the model on
//     the stack at 0x10). Every model draw ends by resetting its per-draw state (func_800DE318), so a draw slipped in
//     between two of the game's leaves both alone.
//   - Banjo's model: func_80092B04(player, 0), which fetches it from the model cache and lets go of it again, as the
//     game itself does in a frame (translate.c); with 1 the player's own draw keeps it. Kazooie in the backpack is
//     a second model drawn with the same bones (babackpack_entrypoint_3): the backpack (PlayerState +0x14) holds
//     its model id at +0, its scale at +0x10; the player's model state (+0x50) says at +0x11 whether it is drawn.
//     The eyes (texture sets) as the player's draw sets them: func_800DF818 and func_800DF720 from the state's
//     +0x12 (the backpack's own +8 and +9).
//   - The camera the picture is drawn from (0x8012D500): its position at +0, its turn at +0x18 (pitch, yaw, roll),
//     its field of view at +0xE4 (with 1/tan(fov/2) at +0xF4) and aspect at +0xE8. func_800CAF34(camera) works out
//     its view matrix (+0xA4) and culling planes from those; func_800E44FC(gfx) puts the perspective
//     normalisation, the projection (camera turn and position folded in) and an identity model view in the list.
//     The model draw places each model from the camera's position (func_800E39A8).
//
// Filming: each frame the players are drawn (the hook at func_800F5008's entry, banjotooie.us.toml) the shots asked
// for are drawn into a picture of our own: a 32-bit colour image and a depth image in the game's heap, cleared to
// transparent and far, cut into cells. The camera is put in front of the copies the way photo mode's card camera
// was put in front of Banjo, each copy is drawn into its cell (the viewport and scissor set to it), then the camera,
// colour and depth images, viewport and scissor are put back. A stripe along the bottom is filled with a number
// for the frame, so a picture that comes back says which shots it holds. RT64 copies the picture back from its
// render target (RT64::SetTargetCapture, rt64-ext's rt64_present_queue_ext.cpp) at the size it drew it, with alpha.
//
// RT64 blends each model's matrices between the game's frames above the original frame rate, by matching them to
// last frame's (src/game/model_tagging.cpp). The copies change pose every frame, so they would be blended from the
// last frame's poses: they are drawn at one of two places far apart, by turns, so no copy has one last frame within
// the matching distance, and the card camera's projection is marked not to be blended.

#include "tooie_pose_puppets.h"

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <mutex>
#include <thread>

#include "funcs.h"
#include "tooie_debug.h"
#include "tooie_gfx_budget.h"
#include "tooie_hooks.h"
#include "tooie_player_cheats.h"
#include "tooie_rdram.h"

namespace RT64 {
    // rt64-ext/src/hle/rt64_present_queue_ext.h.
    typedef std::function<void(uint32_t width, uint32_t height, std::vector<uint8_t>&& rgba)> ScreenshotCallback;
    void SetTargetCapture(uint32_t address, uint32_t nativeWidth, uint32_t nativeHeight, ScreenshotCallback callback);
}

namespace {
    using namespace tooie::rdram;
    using Clock = std::chrono::steady_clock;

    constexpr uint32_t player_table = 0x80135490;
    constexpr uint32_t camera_ptr = 0x8012D500;
    constexpr uint32_t projection_ptr = 0x8012D558;  // the projection func_800E44FC last put in the list
    constexpr uint32_t anctrl_timer = 0x1C + 0x10;
    constexpr uint32_t camera_bytes = 0x180;
    constexpr float deg = 3.14159265f / 180.0f;

    // The card camera, as photo mode's card_camera: this far from the copy's middle (this high above its feet),
    // looking down a little, turned off its face so it is seen three-quarters, with this vertical field of view.
    constexpr float card_distance = 290.0f;
    constexpr float card_height = 62.0f;
    constexpr float card_pitch = -6.0f;
    constexpr float card_turn = 28.0f;
    constexpr float card_fov = 40.0f;

    // The picture: cells of cell x cell N64 pixels, columns x rows of them, and a stripe below for the frame number.
    // One column: with a window wider than 4:3, RT64 draws a picture wider than its N64 size and squeezes what is
    // drawn in it towards its middle (as it does the game's own view), so cells beside the middle would move off
    // their scissor. Down the middle they only get room either side.
    constexpr uint32_t cell = 64;
    constexpr uint32_t columns = 1;
    constexpr uint32_t rows = 15;
    constexpr uint32_t stripe = 4;
    constexpr uint32_t pic_w = cell * columns;
    constexpr uint32_t pic_h = cell * rows + stripe;
    constexpr uint32_t color_bytes = pic_w * pic_h * 4;
    constexpr uint32_t depth_bytes = pic_w * pic_h * 2;
    constexpr uint32_t viewport_bytes = 16 * columns * rows;
    constexpr uint32_t identity_bytes = 64;
    constexpr uint32_t block_bytes = color_bytes + depth_bytes + viewport_bytes + identity_bytes + 64;
    // Left free in the game's heap after taking the block.
    constexpr uint32_t heap_margin = 0x80000;

    // Where the copies stand while filmed: far above the level, two places 3000 apart taken by turns.
    constexpr float rig_height = 30000.0f;
    constexpr float rig_step = 3000.0f;

    // F3DEX2 and RDP commands.
    constexpr uint32_t op_pipesync = 0xE7000000;
    constexpr uint32_t op_fillcolor = 0xF7000000;
    constexpr uint32_t op_zimg = 0xFE000000;
    constexpr uint32_t op_movemem_viewport = 0xDC080008;
    constexpr uint32_t op_moveword_perspnorm = 0xDB0E0000;
    constexpr uint32_t op_mtx_modelview_load = 0xDA380003;
    // RT64's extended commands (lib/rt64/include/rt64_extended_gbi.h).
    constexpr uint32_t rt64_hook_word0 = 0xE0000000 | 0x525464;
    constexpr uint32_t rt64_enable_word1 = (1u << 28) | 0x64;
    constexpr uint32_t ex = 0x64u << 24;
    constexpr uint32_t ex_matrix_group = 0x0C;
    constexpr uint32_t ex_push_viewport = 0x15, ex_pop_viewport = 0x16;
    constexpr uint32_t ex_push_scissor = 0x17, ex_pop_scissor = 0x18;
    constexpr uint32_t ex_push_projection = 0x1D, ex_pop_projection = 0x1E;

    float to_float(uint32_t bits) {
        float f;
        std::memcpy(&f, &bits, sizeof(f));
        return f;
    }

    uint32_t float_bits(float f) {
        uint32_t bits;
        std::memcpy(&bits, &f, sizeof(bits));
        return bits;
    }

    // A copy of ctx working below its stack, for calling the game's functions.
    recomp_context call_ctx(recomp_context* ctx) {
        recomp_context call = *ctx;
        call.r29 = (ctx->r29 - 0x400) & ~(gpr)0xF;
        return call;
    }

    void push_gfx(uint8_t* rdram, uint32_t gfx, uint32_t w0, uint32_t w1) {
        const uint32_t head = read_word(rdram, gfx);
        write_word(rdram, head, w0);
        write_word(rdram, head + 4, w1);
        write_word(rdram, gfx, head + 8);
    }

    void scissor(uint8_t* rdram, uint32_t gfx, uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1) {
        push_gfx(rdram, gfx, 0xED000000 | ((x0 * 4) << 12) | (y0 * 4), ((x1 * 4) << 12) | (y1 * 4));
    }

    // Fills x0..x1, y0..y1 (inclusive) of the colour image set now with a fill colour.
    void fill(uint8_t* rdram, uint32_t gfx, uint32_t color, uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1) {
        push_gfx(rdram, gfx, op_pipesync, 0);
        push_gfx(rdram, gfx, 0xE3000800, 0);              // one primitive at a time
        push_gfx(rdram, gfx, 0xE3000A01, 0x300000);       // fill mode
        push_gfx(rdram, gfx, 0xE200001C, 0);              // no render mode
        push_gfx(rdram, gfx, op_fillcolor, color);
        push_gfx(rdram, gfx, 0xF6000000 | (x1 << 14) | (y1 << 2), (x0 << 14) | (y0 << 2));
    }

    struct PlayerLook {
        uint32_t player = 0;
        uint32_t model = 0;
        float scale = 1.0f;
        uint32_t eyes = 0;           // the model state's +0x12
        uint32_t backpack_model = 0;
        float backpack_scale = 1.0f;
        uint32_t backpack_eyes = 0;  // the backpack's +8 and +9
        uint32_t backpack_frame = 0;
    };

    // Banjo's model and his backpack's, as his own draw would draw them now. False without a player or model.
    bool look_now(uint8_t* rdram, recomp_context* ctx, PlayerLook& look) {
        look = PlayerLook{};
        look.player = read_word(rdram, player_table);
        if (!valid_ptr(look.player)) {
            return false;
        }
        const uint32_t state = read_word(rdram, look.player + 0x50);
        if (!valid_ptr(state) || read_half(rdram, state + 0xC) == 0) {
            return false;
        }
        recomp_context call = call_ctx(ctx);
        call.r4 = (int32_t)look.player;
        call.r5 = 0;
        func_80092B04(rdram, &call);
        look.model = (uint32_t)call.r2;
        if (!valid_ptr(look.model)) {
            return false;
        }
        const float s = read_float(rdram, state + 0x1C);
        look.scale = std::isfinite(s) && s > 0.0f ? s : 1.0f;
        look.eyes = read_byte(rdram, state + 0x12);
        const uint32_t backpack = read_word(rdram, look.player + 0x14);
        if (valid_ptr(backpack) && read_byte(rdram, state + 0x11) != 0) {
            const uint32_t id = read_word(rdram, backpack);
            if (id != 0 && id < 0x10000) {
                call = call_ctx(ctx);
                call.r4 = (int32_t)id;
                func_800D674C(rdram, &call);
                const uint32_t model = (uint32_t)call.r2;
                call = call_ctx(ctx);
                call.r4 = (int32_t)id;
                func_800D62E4(rdram, &call);
                if (valid_ptr(model)) {
                    look.backpack_model = model;
                    const float bs = read_float(rdram, backpack + 0x10);
                    look.backpack_scale = std::isfinite(bs) && bs > 0.0f ? bs : look.scale;
                    look.backpack_eyes = read_byte(rdram, backpack + 8);
                    look.backpack_frame = read_byte(rdram, backpack + 9);
                }
            }
        }
        return true;
    }

    // Another form's model (photo mode's Character row): fetched from the model cache once and held, so it stays
    // loaded while it is drawn (the game lets go of a model it fetched for a moment the same frame, which only works
    // for models something else holds, as the player holds his). Let go of when another is wanted or nothing is; a
    // map change rebuilds the cache, so it is fetched again then.
    struct Held {
        uint16_t id = 0;
        uint32_t ptr = 0;
        uint16_t map = 0;
    } held;

    void release_held(uint8_t* rdram, recomp_context* ctx) {
        if (held.id != 0 && tooie::debug::current_map(rdram) == held.map) {
            recomp_context call = call_ctx(ctx);
            call.r4 = (int32_t)held.id;
            func_800D62E4(rdram, &call);
        }
        held = Held{};
    }

    uint32_t hold_model(uint8_t* rdram, recomp_context* ctx, uint16_t id) {
        const uint16_t map = tooie::debug::current_map(rdram);
        if (held.id == id && held.map == map && valid_ptr(held.ptr)) {
            return held.ptr;
        }
        if (held.map == map) {
            release_held(rdram, ctx);
        }
        held = Held{};
        recomp_context call = call_ctx(ctx);
        call.r4 = (int32_t)id;
        func_800D674C(rdram, &call);
        const uint32_t model = (uint32_t)call.r2;
        if (!valid_ptr(model)) {
            return 0;
        }
        held = Held{ id, model, map };
        return model;
    }

    // The look to draw: the player's own (model 0), or another form's model, alone, at its own size.
    bool look_for(uint8_t* rdram, recomp_context* ctx, uint16_t model_id, PlayerLook& look) {
        if (model_id == 0) {
            return look_now(rdram, ctx, look);
        }
        look = PlayerLook{};
        look.player = read_word(rdram, player_table);
        look.model = hold_model(rdram, ctx, model_id);
        return valid_ptr(look.player) && look.model != 0;
    }

    // The eye textures for the next model draw, as the player's draw (and the backpack's) set them.
    void set_eyes(uint8_t* rdram, recomp_context* call, uint32_t eyes, uint32_t frame) {
        if (eyes == 0) {
            return;
        }
        call->r4 = (int32_t)(int16_t)eyes;
        call->r5 = (int32_t)frame;
        func_80100A74(rdram, call);
        call->r4 = call->r2;
        func_800DF818(rdram, call);
        call->r4 = (int32_t)eyes;
        func_80100AC4(rdram, call);
        call->r4 = call->r2;
        func_800DF720(rdram, call);
    }

    // As the game's own state inits do (and photo mode's play_anim): reset, no blend, the animation, 2 s, looped, started.
    void play_anim(uint8_t* rdram, recomp_context* ctx, uint32_t ctrl, uint32_t anim) {
        recomp_context call = call_ctx(ctx);
        call.r4 = (int32_t)ctrl;
        anctrl_reset(rdram, &call);
        call.r4 = (int32_t)ctrl;
        call.r5 = 0;
        anctrl_setSmoothTransition(rdram, &call);
        call.r4 = (int32_t)ctrl;
        call.r5 = (int32_t)anim;
        anctrl_setIndex(rdram, &call);
        call.r4 = (int32_t)ctrl;
        call.r5 = 0x40000000;  // 2.0f
        anctrl_setDuration(rdram, &call);
        call.r4 = (int32_t)ctrl;
        call.r5 = 2;
        anctrl_setPlaybackType(rdram, &call);
        call.r4 = (int32_t)ctrl;
        anctrl_start(rdram, &call);
    }

    uint32_t new_ctrl(uint8_t* rdram, recomp_context* ctx) {
        recomp_context call = call_ctx(ctx);
        call.r4 = 1;
        func_8008AD80(rdram, &call);
        const uint32_t ctrl = (uint32_t)call.r2;
        return valid_ptr(ctrl) ? ctrl : 0;
    }

    void free_ctrl(uint8_t* rdram, recomp_context* ctx, uint32_t ctrl) {
        recomp_context call = call_ctx(ctx);
        call.r4 = (int32_t)ctrl;
        func_8008ADBC(rdram, &call);
    }

    // gEXSetCullFlip (rt64_extended_gbi.h): RT64 winds the tris that follow the other way round for culling.
    constexpr uint32_t ex_cull_flip = 0x36;

    // The projection for a mirrored copy: the scene's (the projection has the camera's turn and position in it, and the
    // model view is the model's place in the world) after a reflection about the upright plane through `pos` that the
    // copy faces along (its normal the copy's right, (cos yaw, 0, -sin yaw)), so the copy is flipped left to right
    // where it stands. Written as an N64 matrix (s15.16, row vectors) into the frame's matrix room (the gfx block's
    // +4, as the model draw takes its own) and multiplied onto the projection (G_MTX, projection, multiply, no push)
    // between RT64's push and pop of the projection. The game's own size test multiplies by the scale, so a negative
    // scale (the obvious way) has the copy left out as too far away.
    bool push_mirror(uint8_t* rdram, uint32_t gfx, const float pos[3], float yaw) {
        const uint32_t mtx = read_word(rdram, gfx + 4);
        if (!valid_ptr(mtx)) {
            return false;
        }
        const float* c = pos;
        const float rad = yaw * 3.14159265f / 180.0f;
        const float n[3] = { std::cos(rad), 0.0f, -std::sin(rad) };
        const float d = 2.0f * (c[0] * n[0] + c[1] * n[1] + c[2] * n[2]);
        float m[4][4] = {};
        for (int r = 0; r < 3; r++) {
            for (int k = 0; k < 3; k++) {
                m[r][k] = (r == k ? 1.0f : 0.0f) - 2.0f * n[r] * n[k];
            }
            m[3][r] = d * n[r];
        }
        m[3][3] = 1.0f;
        for (int r = 0; r < 4; r++) {
            for (int k = 0; k < 4; k += 2) {
                const int32_t a = (int32_t)std::lround(m[r][k] * 65536.0f);
                const int32_t b = (int32_t)std::lround(m[r][k + 1] * 65536.0f);
                write_word(rdram, mtx + r * 8 + k * 2, ((uint32_t)a & 0xFFFF0000u) | ((uint32_t)b >> 16));
                write_word(rdram, mtx + 32 + r * 8 + k * 2, ((uint32_t)a << 16) | ((uint32_t)b & 0xFFFFu));
            }
        }
        write_word(rdram, gfx + 4, mtx + 64);
        push_gfx(rdram, gfx, rt64_hook_word0, rt64_enable_word1);
        push_gfx(rdram, gfx, ex | ex_push_projection, 0);
        push_gfx(rdram, gfx, ex | ex_cull_flip, 1);
        push_gfx(rdram, gfx, 0xDA380005, mtx);
        return true;
    }

    // Draws one copy, posed by ctrl held at t, standing at pos turned yaw degrees. Mirrored, it is drawn through a
    // mirrored projection (push_mirror); its faces then turn round on screen, so RT64 is told to cull the other side
    // for it (gEXSetCullFlip), and both are put back after.
    void draw_copy(uint8_t* rdram, recomp_context* ctx, const PlayerLook& look, uint32_t ctrl, float t, const float pos[3], float yaw,
                   bool mirror = false) {
        recomp_context call = call_ctx(ctx);
        uint32_t gfx = 0;
        if (mirror) {
            func_800A7180(rdram, &call);
            gfx = (uint32_t)call.r2;
            if (!valid_ptr(gfx) || !valid_ptr(read_word(rdram, gfx))) {
                gfx = 0;
                mirror = false;
            }
            call = call_ctx(ctx);
        }
        if (mirror && !push_mirror(rdram, gfx, pos, yaw)) {
            mirror = false;
        }
        const gpr base = call.r29;
        const uint32_t position = (uint32_t)base + 0x40;  // vec3
        const uint32_t rotation = (uint32_t)base + 0x50;  // vec3, degrees
        write_float(rdram, ctrl + anctrl_timer, std::clamp(t, 0.0f, 0.999f));
        call.r4 = (int32_t)ctrl;
        func_8008B304(rdram, &call);
        call.r4 = (int32_t)ctrl;
        func_8008B4D4(rdram, &call);
        const gpr bones = call.r2;
        for (int part = 0; part < 2; part++) {
            const uint32_t model = part == 0 ? look.model : look.backpack_model;
            if (model == 0) {
                continue;
            }
            call.r29 = base;
            call.r4 = bones;
            func_800DF41C(rdram, &call);
            call.r4 = 1;  // the render mode the player's draw picks (func_800923A8)
            func_800DF830(rdram, &call);
            if (part == 0) {
                set_eyes(rdram, &call, look.eyes, 0);
            }
            else {
                set_eyes(rdram, &call, look.backpack_eyes, look.backpack_frame);
            }
            write_float(rdram, position, pos[0]);
            write_float(rdram, position + 4, pos[1]);
            write_float(rdram, position + 8, pos[2]);
            write_float(rdram, rotation, 0.0f);
            write_float(rdram, rotation + 4, yaw);
            write_float(rdram, rotation + 8, 0.0f);
            const float scale = part == 0 ? look.scale : look.backpack_scale;
            call.r29 = base;
            call.r4 = (int32_t)position;
            call.r5 = (int32_t)rotation;
            call.r6 = (int32_t)float_bits(scale);
            call.r7 = 0;
            MEM_W(0x10, call.r29) = (int32_t)model;
            func_800DE448(rdram, &call);
        }
        if (mirror) {
            push_gfx(rdram, gfx, ex | ex_cull_flip, 0);
            push_gfx(rdram, gfx, ex | ex_pop_projection, 0);
        }
    }

    // ---- Looking ----
    struct Puppet {
        uint32_t ctrl = 0;
        uint32_t anim = 0;
        float t = 0.0f;
        float dx = 0.0f, dz = 0.0f;
    };
    std::vector<Puppet> puppets;
    // The map the controllers were made on: a map change rebuilds the game's heap, so they are dropped then.
    uint16_t puppets_map = 0;

    // ---- Filming ----
    struct Film {
        bool on = false;
        uint32_t block = 0;          // from heap_alloc
        uint32_t color = 0, depth = 0, viewports = 0, identity = 0;
        uint16_t map = 0;
        std::vector<uint32_t> ctrls;
        std::vector<uint32_t> ctrl_anims;
        std::vector<tooie::pose_puppets::Shot> next;
        uint32_t frame = 0;          // the number in the stripe of the last frame drawn
        uint16_t model = 0;          // 0: the player's own look
        float size = 1.0f;           // the card camera's distance and height, times this
    } film;

    // ---- The stand-in (photo mode's Character row): another form drawn where the player stands ----
    struct StandIn {
        uint32_t ctrl = 0;
        uint32_t anim = 0;
        uint16_t model = 0;
        uint16_t map = 0;
        float t = 0.0f;
    } stand;
    std::atomic<bool> stand_mirror{false};

    // Shared with the capture callback's thread.
    struct Pending {
        std::vector<tooie::pose_puppets::Shot> shots;
        Clock::time_point drawn;
    };
    std::mutex pending_mutex;
    std::map<uint32_t, Pending> pending;  // by frame number
    tooie::pose_puppets::ShotCallback shot_callback;

    // The frame number as a fill colour (32-bit RGBA, opaque) and back.
    uint32_t stripe_color(uint32_t number) {
        return ((number & 0xFFFFFF) << 8) | 0xFF;
    }

    // TOOIE_PUPPET_LOG=1: frames drawn and pictures back.
    const bool puppet_log = std::getenv("TOOIE_PUPPET_LOG") != nullptr;

    void picture_back(uint32_t width, uint32_t height, std::vector<uint8_t>&& rgba) {
        if (width == 0 || height == 0 || rgba.size() < (size_t)width * height * 4) {
            return;
        }
        const float sx = (float)width / (float)pic_w;
        const float sy = (float)height / (float)pic_h;
        // The stripe's middle.
        const uint32_t px = width / 2;
        const uint32_t py = std::min(height - 1, (uint32_t)(((float)pic_h - stripe * 0.5f) * sy));
        const uint8_t* p = &rgba[((size_t)py * width + px) * 4];
        const uint32_t number = ((uint32_t)p[0] << 16) | ((uint32_t)p[1] << 8) | p[2];
        if (puppet_log) {
            fprintf(stderr, "[puppets] picture %ux%u back, frame %u (stripe %02X %02X %02X %02X)\n", width, height, number, p[0], p[1], p[2], p[3]);
        }
        Pending got;
        tooie::pose_puppets::ShotCallback callback;
        {
            std::lock_guard lock{ pending_mutex };
            auto it = pending.find(number);
            if (it == pending.end()) {
                return;
            }
            got = std::move(it->second);
            pending.erase(it);
            callback = shot_callback;
        }
        if (!callback) {
            return;
        }
        (void)sx;
        for (size_t i = 0; i < got.shots.size(); i++) {
            // A cell is drawn cell * sy pixels square (RT64's scale for the height), down the picture's middle.
            const uint32_t row = (uint32_t)i / columns;
            const int y0 = (int)std::lround(row * cell * sy), y1 = (int)std::lround((row + 1) * cell * sy);
            const int side = std::max(1, std::min((int)width, y1 - y0));
            const int left = std::clamp((int)width / 2 - side / 2, 0, (int)width - side);
            const int top = y0;
            std::vector<uint8_t> square((size_t)side * side * 4);
            for (int y = 0; y < side; y++) {
                std::memcpy(&square[(size_t)y * side * 4], &rgba[((size_t)(top + y) * width + left) * 4], (size_t)side * 4);
            }
            // A 32-bit N64 picture keeps the pixel's coverage (0 to 7) where the alpha would be. The picture was cleared
            // to 0, so whatever was drawn has some: that is the alpha.
            for (size_t k = 0; k + 3 < square.size(); k += 4) {
                square[k + 3] = (uint8_t)std::min<uint32_t>(255, square[k + 3] * 255u / 7u);
            }
            callback(got.shots[i].id, (uint32_t)side, std::move(square));
        }
    }

    // Puts the camera in front of the copies: the card camera for a copy standing at rig turned 0, its distance and
    // height times size (a big form is filmed from further away).
    void card_camera(uint8_t* rdram, uint32_t camera, const float rig[3], float size) {
        const float yaw = card_turn;
        const float pitch = card_pitch;
        const float sy = std::sin(yaw * deg), cy = std::cos(yaw * deg);
        const float sp = std::sin(pitch * deg), cp = std::cos(pitch * deg);
        const float forward[3] = { -sy * cp, sp, -cy * cp };
        const float pivot[3] = { rig[0], rig[1] + card_height * size, rig[2] };
        for (int i = 0; i < 3; i++) {
            write_float(rdram, camera + 4 * i, pivot[i] - forward[i] * card_distance * size);
        }
        write_float(rdram, camera + 0x18, pitch < 0.0f ? pitch + 360.0f : pitch);
        write_float(rdram, camera + 0x1C, yaw);
        write_float(rdram, camera + 0x20, 0.0f);
        write_float(rdram, camera + 0xE4, card_fov);
        write_float(rdram, camera + 0xE8, 1.0f);
        write_float(rdram, camera + 0xF4, 1.0f / std::tan(card_fov * 0.5f * deg));
    }

    // Draws this frame's shots into the picture.
    void draw_film(uint8_t* rdram, recomp_context* ctx) {
        if (film.next.empty()) {
            return;
        }
        std::vector<tooie::pose_puppets::Shot> shots = std::move(film.next);
        film.next.clear();
        const uint32_t camera = read_word(rdram, camera_ptr);
        PlayerLook look;
        if (!valid_ptr(camera) || !tooie::gfx_budget::room_for_extras(rdram) || !look_for(rdram, ctx, film.model, look)) {
            return;
        }
        recomp_context call = call_ctx(ctx);
        func_800A7180(rdram, &call);
        const uint32_t gfx = (uint32_t)call.r2;
        if (!valid_ptr(gfx) || !valid_ptr(read_word(rdram, gfx))) {
            return;
        }
        const uint32_t number = (++film.frame & 0xFFFFFF) == 0 ? ++film.frame & 0xFFFFFF : film.frame & 0xFFFFFF;

        // The scene's perspective normalisation, to put back afterwards (func_800CB124 also builds the projection,
        // into scratch room here).
        call = call_ctx(ctx);
        call.r4 = (int32_t)camera;
        call.r5 = (int32_t)(call.r29 + 0x100);
        func_800CB124(rdram, &call);
        const uint32_t scene_perspnorm = (uint32_t)call.r2 & 0xFFFF;

        uint32_t saved_camera[camera_bytes / 4];
        for (uint32_t i = 0; i < camera_bytes / 4; i++) {
            saved_camera[i] = read_word(rdram, camera + i * 4);
        }
        const uint32_t saved_projection = read_word(rdram, projection_ptr);

        push_gfx(rdram, gfx, rt64_hook_word0, rt64_enable_word1);
        push_gfx(rdram, gfx, ex | ex_push_viewport, 0);
        push_gfx(rdram, gfx, ex | ex_push_scissor, 0);
        push_gfx(rdram, gfx, ex | ex_push_projection, 0);

        // Clear the depth image (drawn to as a colour image) and then the picture, then draw into the picture.
        push_gfx(rdram, gfx, op_pipesync, 0);
        scissor(rdram, gfx, 0, 0, pic_w, pic_h);
        push_gfx(rdram, gfx, 0xFF100000 | (pic_w - 1), film.depth);
        fill(rdram, gfx, 0xFFFCFFFC, 0, 0, pic_w - 1, pic_h - 1);
        push_gfx(rdram, gfx, op_pipesync, 0);
        push_gfx(rdram, gfx, op_zimg, film.depth);
        push_gfx(rdram, gfx, 0xFF180000 | (pic_w - 1), film.color);
        fill(rdram, gfx, 0, 0, 0, pic_w - 1, pic_h - 1);
        push_gfx(rdram, gfx, op_pipesync, 0);
        push_gfx(rdram, gfx, 0xE3000A01, 0);  // one-cycle mode

        // The card camera, its projection not blended between frames.
        const float rig[3] = { 0.0f, rig_height, (number & 1) ? rig_step : 0.0f };
        card_camera(rdram, camera, rig, film.size);
        call = call_ctx(ctx);
        call.r4 = (int32_t)camera;
        func_800CAF34(rdram, &call);
        push_gfx(rdram, gfx, ex | ex_matrix_group, 0xFFFFFFFF);
        push_gfx(rdram, gfx, 0x2, 0);  // the projection, no push, nothing blended
        call = call_ctx(ctx);
        call.r4 = (int32_t)gfx;
        func_800E44FC(rdram, &call);

        for (size_t i = 0; i < shots.size() && i < film.ctrls.size(); i++) {
            const uint32_t col = (uint32_t)i % columns, row = (uint32_t)i / columns;
            const uint32_t vp = film.viewports + (uint32_t)i * 16;
            const uint32_t cx = col * cell + cell / 2, cy = row * cell + cell / 2;
            write_half(rdram, vp + 0, (uint16_t)(cell * 2));
            write_half(rdram, vp + 2, (uint16_t)(cell * 2));
            write_half(rdram, vp + 4, 0x1FF);
            write_half(rdram, vp + 6, 0);
            write_half(rdram, vp + 8, (uint16_t)(cx * 4));
            write_half(rdram, vp + 10, (uint16_t)(cy * 4));
            write_half(rdram, vp + 12, 0x1FF);
            write_half(rdram, vp + 14, 0);
            push_gfx(rdram, gfx, op_movemem_viewport, vp);
            scissor(rdram, gfx, col * cell, row * cell, (col + 1) * cell, (row + 1) * cell);
            if (film.ctrl_anims[i] != shots[i].anim) {
                play_anim(rdram, ctx, film.ctrls[i], shots[i].anim);
                film.ctrl_anims[i] = shots[i].anim;
            }
            draw_copy(rdram, ctx, look, film.ctrls[i], shots[i].t, rig, 0.0f);
        }

        // The frame's number along the bottom.
        push_gfx(rdram, gfx, op_pipesync, 0);
        scissor(rdram, gfx, 0, 0, pic_w, pic_h);
        fill(rdram, gfx, stripe_color(number), 0, pic_h - stripe, pic_w - 1, pic_h - 1);

        // Everything back as the scene had it.
        for (uint32_t i = 0; i < camera_bytes / 4; i++) {
            write_word(rdram, camera + i * 4, saved_camera[i]);
        }
        write_word(rdram, projection_ptr, saved_projection);
        push_gfx(rdram, gfx, op_pipesync, 0);
        call = call_ctx(ctx);
        call.r4 = (int32_t)gfx;
        func_800E7CF4(rdram, &call);
        call = call_ctx(ctx);
        call.r4 = (int32_t)gfx;
        func_800E7BC8(rdram, &call);
        push_gfx(rdram, gfx, rt64_hook_word0, rt64_enable_word1);
        push_gfx(rdram, gfx, ex | ex_pop_projection, 0);
        push_gfx(rdram, gfx, ex | ex_pop_scissor, 0);
        push_gfx(rdram, gfx, ex | ex_pop_viewport, 0);
        push_gfx(rdram, gfx, op_moveword_perspnorm, scene_perspnorm);
        push_gfx(rdram, gfx, op_mtx_modelview_load, film.identity);

        if (puppet_log) {
            fprintf(stderr, "[puppets] frame %u drawn: %zu shots\n", number, shots.size());
        }
        {
            std::lock_guard lock{ pending_mutex };
            pending[number] = Pending{ std::move(shots), Clock::now() };
            // Frames whose picture never came (RT64 dropped the frame): forgotten, so the caller asks again.
            for (auto it = pending.begin(); it != pending.end();) {
                it = Clock::now() - it->second.drawn > std::chrono::seconds(2) ? pending.erase(it) : std::next(it);
            }
        }
    }

    void draw_stand_in(uint8_t* rdram, recomp_context* ctx) {
        if (stand.model == 0) {
            return;
        }
        if (tooie::debug::current_map(rdram) != stand.map) {
            stand = StandIn{};
            held = Held{};
            return;
        }
        PlayerLook look;
        float at[3];
        const bool own = stand.model == tooie::pose_puppets::own_look;
        if (!tooie::gfx_budget::room_for_extras(rdram) || !look_for(rdram, ctx, own ? 0 : stand.model, look) ||
            !tooie::player_cheats::position(rdram, at)) {
            return;
        }
        uint32_t ctrl = stand.ctrl;
        float t = stand.t;
        if (own) {
            // The player's own animation controller, at the place it has got to (its bones are worked out again for
            // that same place, which changes nothing).
            recomp_context call = call_ctx(ctx);
            call.r4 = (int32_t)look.player;
            baanim_getAnimCtrlPtr(rdram, &call);
            ctrl = (uint32_t)call.r2;
            if (!valid_ptr(ctrl)) {
                return;
            }
            t = read_float(rdram, ctrl + anctrl_timer);
            // His face slots (eyes and the rest), as his own draw sets them before drawing (func_800A0714 with his
            // model id): his draw is skipped while the stand-in takes his place.
            call = call_ctx(ctx);
            call.r4 = (int32_t)look.player;
            func_80092B80(rdram, &call);
            const uint32_t model_id = (uint32_t)call.r2 & 0xFFFF;
            call = call_ctx(ctx);
            call.r4 = (int32_t)look.player;
            call.r5 = (int32_t)model_id;
            func_800A0714(rdram, &call);
        }
        const uint32_t yaw_ptr = read_word(rdram, look.player + 0xF8);
        const float yaw = valid_ptr(yaw_ptr) ? read_float(rdram, yaw_ptr) : 0.0f;
        draw_copy(rdram, ctx, look, ctrl, t, at, yaw, stand_mirror.load());
    }

    void draw_puppets(uint8_t* rdram, recomp_context* ctx) {
        if (puppets.empty()) {
            return;
        }
        if (tooie::debug::current_map(rdram) != puppets_map) {
            puppets.clear();
            return;
        }
        PlayerLook look;
        float at[3];
        if (!tooie::gfx_budget::room_for_extras(rdram) || !look_now(rdram, ctx, look) || !tooie::player_cheats::position(rdram, at)) {
            return;
        }
        const uint32_t yaw_ptr = read_word(rdram, look.player + 0xF8);
        const float yaw = valid_ptr(yaw_ptr) ? read_float(rdram, yaw_ptr) : 0.0f;
        for (const Puppet& p : puppets) {
            const float pos[3] = { at[0] + p.dx, at[1], at[2] + p.dz };
            draw_copy(rdram, ctx, look, p.ctrl, p.t, pos, yaw);
        }
    }
}

// banjotooie.us.toml: the entry of func_800F5008, which draws the players, in the 3D scene of each frame.
extern "C" void tooie_players_draw(uint8_t* rdram, recomp_context* ctx) {
    if (film.on) {
        if (tooie::debug::current_map(rdram) == film.map) {
            draw_film(rdram, ctx);
        }
        else {
            film.next.clear();
        }
    }
    draw_stand_in(rdram, ctx);
    draw_puppets(rdram, ctx);
}

bool tooie::pose_puppets::film_start(uint8_t* rdram, recomp_context* ctx, ShotCallback callback, uint16_t model, float size) {
    if (film.on) {
        film_stop(rdram, ctx);
    }
    PlayerLook look;
    if (!look_for(rdram, ctx, model, look)) {
        return false;
    }
    // heap_largest_free(u32* largest) stores the largest free block's size and returns how many free blocks there are.
    recomp_context call = call_ctx(ctx);
    const uint32_t largest_at = (uint32_t)call.r29 + 0x100;
    write_word(rdram, largest_at, 0);
    call.r4 = (int32_t)largest_at;
    heap_largest_free(rdram, &call);
    const uint32_t largest = read_word(rdram, largest_at);
    if (largest < block_bytes + heap_margin) {
        fprintf(stderr, "[puppets] no room to film: %u bytes free in one piece\n", largest);
        return false;
    }
    call = call_ctx(ctx);
    call.r4 = (int32_t)block_bytes;
    heap_alloc(rdram, &call);
    const uint32_t block = (uint32_t)call.r2;
    if (!valid_ptr(block)) {
        return false;
    }
    film = Film{};
    film.block = block;
    film.color = (block + 63) & ~63u;
    film.depth = film.color + color_bytes;
    film.viewports = film.depth + depth_bytes;
    film.identity = film.viewports + viewport_bytes;
    for (uint32_t i = 0; i < 16; i++) {
        write_half(rdram, film.identity + i * 2, (i % 5) == 0 ? 1 : 0);
        write_half(rdram, film.identity + 32 + i * 2, 0);
    }
    for (uint32_t i = 0; i < columns * rows; i++) {
        const uint32_t ctrl = new_ctrl(rdram, ctx);
        if (ctrl == 0) {
            break;
        }
        film.ctrls.push_back(ctrl);
        film.ctrl_anims.push_back(0);
    }
    if (film.ctrls.empty()) {
        call = call_ctx(ctx);
        call.r4 = (int32_t)block;
        heap_free(rdram, &call);
        film = Film{};
        return false;
    }
    film.map = tooie::debug::current_map(rdram);
    film.model = model;
    film.size = std::isfinite(size) && size > 0.0f ? size : 1.0f;
    film.on = true;
    {
        std::lock_guard lock{ pending_mutex };
        pending.clear();
        shot_callback = std::move(callback);
    }
    RT64::SetTargetCapture(film.color, pic_w, pic_h, picture_back);
    fprintf(stderr, "[puppets] filming: %zu cells of %ux%u, picture at %08X\n", film.ctrls.size(), cell, cell, film.color);
    return true;
}

void tooie::pose_puppets::film_stop(uint8_t* rdram, recomp_context* ctx) {
    if (!film.on) {
        return;
    }
    RT64::SetTargetCapture(0, 0, 0, nullptr);
    {
        std::lock_guard lock{ pending_mutex };
        pending.clear();
        shot_callback = nullptr;
    }
    // After a map change the heap was laid out again, and the block and controllers went with it.
    if (tooie::debug::current_map(rdram) == film.map) {
        for (uint32_t ctrl : film.ctrls) {
            free_ctrl(rdram, ctx, ctrl);
        }
        recomp_context call = call_ctx(ctx);
        call.r4 = (int32_t)film.block;
        heap_free(rdram, &call);
    }
    // Another form's model, held for this round: let go of it unless the stand-in still draws it.
    if (film.model != 0 && stand.model != film.model) {
        release_held(rdram, ctx);
    }
    film = Film{};
}

bool tooie::pose_puppets::filming() {
    return film.on;
}

int tooie::pose_puppets::film_cells() {
    return film.on ? (int)film.ctrls.size() : 0;
}

void tooie::pose_puppets::film_next(std::vector<Shot> shots) {
    if (film.on) {
        film.next = std::move(shots);
    }
}

int tooie::pose_puppets::film_in_flight() {
    std::lock_guard lock{ pending_mutex };
    return (int)pending.size();
}

std::string tooie::pose_puppets::add(uint8_t* rdram, recomp_context* ctx, uint32_t anim, float t, float dx, float dz) {
    if (!puppets.empty() && tooie::debug::current_map(rdram) != puppets_map) {
        puppets.clear();
    }
    if (!valid_ptr(read_word(rdram, player_table))) {
        return "there is no player yet";
    }
    if (puppets.size() >= 16) {
        return "at most 16 puppets";
    }
    const uint32_t ctrl = new_ctrl(rdram, ctx);
    if (ctrl == 0) {
        return "no room in the game's heap for an animation controller";
    }
    play_anim(rdram, ctx, ctrl, anim);
    if (puppets.empty()) {
        puppets_map = tooie::debug::current_map(rdram);
    }
    puppets.push_back({ ctrl, anim, std::clamp(t, 0.0f, 0.999f), dx, dz });
    return "";
}

void tooie::pose_puppets::clear(uint8_t* rdram, recomp_context* ctx) {
    if (tooie::debug::current_map(rdram) == puppets_map) {
        for (const Puppet& p : puppets) {
            free_ctrl(rdram, ctx, p.ctrl);
        }
    }
    puppets.clear();
}

std::string tooie::pose_puppets::list() {
    std::string out;
    char line[160];
    for (size_t i = 0; i < puppets.size(); i++) {
        const Puppet& p = puppets[i];
        std::snprintf(line, sizeof(line), "%s%zu: animation 0x%X at %.3f, %.0f %.0f from Banjo, controller %08X",
            out.empty() ? "" : "\n", i, p.anim, p.t, p.dx, p.dz, p.ctrl);
        out += line;
    }
    return out.empty() ? "no puppets" : out;
}

void tooie::pose_puppets::stand_in(uint8_t* rdram, recomp_context* ctx, uint16_t model, uint32_t anim, float t) {
    const uint16_t map = tooie::debug::current_map(rdram);
    if (stand.model != 0 && stand.map != map) {
        stand = StandIn{};
        held = Held{};
    }
    if (model == 0) {
        if (stand.model != 0) {
            if (stand.ctrl != 0) {
                free_ctrl(rdram, ctx, stand.ctrl);
            }
            stand = StandIn{};
            // The model is held for filming too: let go of it only when no round of cards is filming with it.
            if (!film.on || film.model != held.id) {
                release_held(rdram, ctx);
            }
        }
        return;
    }
    if (model == own_look) {
        // The player's own look and animation: no controller of its own, and no other model held.
        if (stand.model != 0 && stand.model != own_look) {
            if (stand.ctrl != 0) {
                free_ctrl(rdram, ctx, stand.ctrl);
            }
            if (!film.on || film.model != held.id) {
                release_held(rdram, ctx);
            }
            stand = StandIn{};
        }
        stand.model = own_look;
        stand.map = map;
        return;
    }
    if (stand.model == own_look) {
        stand = StandIn{};
    }
    if (stand.model == 0) {
        const uint32_t ctrl = new_ctrl(rdram, ctx);
        if (ctrl == 0) {
            return;
        }
        stand.ctrl = ctrl;
        stand.anim = 0;
        stand.map = map;
    }
    stand.model = model;
    if (stand.anim != anim) {
        play_anim(rdram, ctx, stand.ctrl, anim);
        stand.anim = anim;
    }
    stand.t = std::clamp(t, 0.0f, 0.999f);
}

bool tooie::pose_puppets::stand_in_on() {
    return stand.model != 0;
}

void tooie::pose_puppets::set_mirror(bool on) {
    stand_mirror = on;
}
