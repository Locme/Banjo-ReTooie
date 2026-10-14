// HD shadows (handoff 4.51), Graphics tab, off by default.
//
// The player's shadow is the player's model flattened onto the floor and
// drawn into an offscreen 8-bit buffer (func_800A6250, called from the player
// shadow component func_800A6DAC). It does not use the model on screen:
// _bapreload_entrypoint_1 gives each form a simpler shadow model (0x853 for
// Banjo-Kazooie), which func_800D674C loads into the frame at $sp+0x1C8, next
// to the model on screen at $sp+0x1C4 (func_80092B04). When the two are the
// same, func_800A6250 already draws the on-screen model with its pose, so the
// hook just after both are known copies the on-screen model over the shadow
// model while the option is on. It is read every frame, so it applies at once.
//
// Enemies and NPCs have no shadow in the game. With the option on, each actor
// drawn by the generic actor draw (func_80101808) also gets one, made the
// same way as the player's: tooie_actor_shadow runs right after the actor's
// model is drawn and repeats func_800A69F0 and func_800A6250 for it, with the
// light straight down. It finds the floor under the actor (func_800C6A7C),
// builds the matrix that flattens the model onto that floor, clears the
// shadow buffer, draws the actor's model and pose into it (the pose comes
// from the same draw callback func_80101808 was given), switches back to the
// screen and pastes the buffer over the actor's projected bounding box.

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <variant>
#include <vector>

#include "recomp.h"
#include "funcs.h"
#include "recompui/config.h"
#include "tooie_game.h"
#include "tooie_hooks.h"
#include "tooie_hd_shadows.h"
#include "tooie_gfx_budget.h"

namespace {
    bool hd_shadows_on() {
        try {
            return std::get<bool>(recompui::config::get_config(recompui::config::graphics::id).get_option_value(tooie::hd_shadows_option));
        } catch (...) {
            return false;
        }
    }

    bool tilted(const std::string& option) {
        try {
            return static_cast<tooie::hd_shadows::Direction>(std::get<uint32_t>(
                recompui::config::get_config(recompui::config::graphics::id).get_option_value(option))) == tooie::hd_shadows::Direction::Tilt;
        } catch (...) {
            return false;
        }
    }

    // The Tilt light, towards the light and fixed in the world like a sun: about 35 degrees from
    // straight up, so a shadow falls beside what casts it (towards -X, -Z) instead of under it.
    constexpr float tilt_light[3] = {0.47f, 0.82f, 0.33f};
}

extern "C" void tooie_player_shadow_model(uint8_t* rdram, recomp_context* ctx) {
    // TOOIE_SHADOW_LOG=1: the two models each time they change.
    static const bool log = std::getenv("TOOIE_SHADOW_LOG") != nullptr;
    if (log) {
        static uint32_t last_shadow = 0, last_model = 0;
        uint32_t shadow = MEM_W(0x1C8, ctx->r29), model = MEM_W(0x1C4, ctx->r29);
        if (shadow != last_shadow || model != last_model) {
            std::printf("[shadow] player shadow model %08X, on-screen model %08X, HD shadows %d\n", shadow, model, hd_shadows_on());
            std::fflush(stdout);
            last_shadow = shadow;
            last_model = model;
        }
    }
    if (hd_shadows_on()) {
        MEM_W(0x1C8, ctx->r29) = MEM_W(0x1C4, ctx->r29);
        // $s0 is the light direction, a vector its callers (func_800A69F0 via func_800A6B24) build on
        // their stack for every shadow. Tilt replaces the default overhead light (0, 1, 0) only, so a
        // shadow cast by a real light in the level keeps that light's direction.
        const gpr light = ctx->r16;
        const uint32_t light_y_bits = MEM_W(4, light);
        float light_y;
        std::memcpy(&light_y, &light_y_bits, sizeof(light_y));
        if (tilted(tooie::hd_shadows::banjo_direction_option) && light_y > 0.999f) {
            for (int i = 0; i < 3; i++) {
                uint32_t bits;
                std::memcpy(&bits, &tilt_light[i], sizeof(bits));
                MEM_W(i * 4, light) = bits;
            }
        }
    }
}

namespace {
    // Actors more than this far above their floor get no shadow.
    constexpr float max_height = 1500.0f;
    // At most this many actor shadows a frame: each one switches the colour image twice.
    constexpr int max_per_frame = 12;
    int shadows_this_frame = 0;
    // TOOIE_SHADOW_LOG=1: why actors got no shadow, counted per reason and printed every 2 s.
    const bool shadow_log = std::getenv("TOOIE_SHADOW_LOG") != nullptr;
    enum Outcome { NoModel, NoFloor, Steep, Offscreen, TooSmall, NoRoom, Drawn, OutcomeCount };
    int outcomes[OutcomeCount] = {};
    void count(Outcome outcome) {
        outcomes[outcome]++;
    }
    // func_80101808's draw callback ($a1), kept from its entry for the shadow draw. A callback can
    // draw another actor through func_80101808, so each call keeps its own: a stack, one per call.
    std::vector<uint32_t> draw_callbacks;
    // The model the outermost func_80101808 draw used (tooie_shadow_note_model), 0 if none. The
    // shadow passes it to the renderer: fetching it again (func_800D674C) in the same frame marks
    // it as drawn twice, and the model cache then dropped models still in use (crash, objects gone).
    uint32_t drawn_model = 0;
    // True while an actor is drawn into the shadow buffer.
    bool in_shadow_pass = false;

    float load_float(uint8_t* rdram, gpr addr) {
        uint32_t bits = MEM_W(0, addr);
        float value;
        std::memcpy(&value, &bits, sizeof(value));
        return value;
    }

    void store_float(uint8_t* rdram, gpr addr, float value) {
        uint32_t bits;
        std::memcpy(&bits, &value, sizeof(bits));
        MEM_W(0, addr) = bits;
    }

    uint32_t float_bits(float value) {
        uint32_t bits;
        std::memcpy(&bits, &value, sizeof(bits));
        return bits;
    }

    void store_vec(uint8_t* rdram, gpr addr, float x, float y, float z) {
        store_float(rdram, addr, x);
        store_float(rdram, addr + 4, y);
        store_float(rdram, addr + 8, z);
    }

    void push_gfx(uint8_t* rdram, gpr gfx_head, uint32_t w0, uint32_t w1) {
        gpr cmd = (int32_t)MEM_W(0, gfx_head);
        MEM_W(0, cmd) = w0;
        MEM_W(4, cmd) = w1;
        MEM_W(0, gfx_head) = (uint32_t)(cmd + 8);
    }

    // The shadow for one actor. ctx is a scratch copy; frame is free RDRAM stack space.
    void draw_actor_shadow(uint8_t* rdram, recomp_context* ctx, gpr actor, gpr frame, uint32_t draw_callback, uint32_t drawn) {
        const gpr start = frame + 0x40;     // vec3
        const gpr floor = frame + 0x50;     // vec3, the end of the ray, then the floor point
        const gpr normal = frame + 0x60;    // vec3
        const gpr flatten = frame + 0x70;   // 4x4 matrix
        const gpr rotation = frame + 0xB0;  // 4x4 matrix
        const gpr corners = frame + 0xF0;   // 8 vec3
        const gpr screen = frame + 0x150;   // 8 vec2
        const gpr visible = frame + 0x190;  // s32

        const float x = load_float(rdram, actor + 0x4);
        const float y = load_float(rdram, actor + 0x8);
        const float z = load_float(rdram, actor + 0xC);
        const float scale = load_float(rdram, actor + 0x38);

        // The model the actor's own draw used; only its size is used here. Looking it up again with
        // func_801039E4 fetched it from the model cache a second time this frame, and the cache then
        // let go of models still on screen (eggs, notes and other objects vanished).
        const gpr model = (int32_t)drawn;
        if (model == 0 || scale <= 0.0f) {
            count(NoModel);
            return;
        }

        // Floor straight below (func_800A69F0's ray).
        store_vec(rdram, start, x, y + 10.0f, z);
        store_vec(rdram, floor, x, y - max_height, z);
        ctx->r4 = start;
        ctx->r5 = floor;
        ctx->r6 = normal;
        ctx->r7 = 0x20020;
        func_800C6A7C(rdram, ctx);
        if (ctx->r2 == 0) {
            count(NoFloor);
            return;
        }
        const float nx = load_float(rdram, normal);
        const float ny = load_float(rdram, normal + 4);
        const float nz = load_float(rdram, normal + 8);
        if (ny < 0.3f) {
            count(Steep);
            return;  // a wall or a steep slope
        }

        // Flatten along the light l onto the floor plane: M = I - n l / (l . n), as func_800A6250
        // (row i, column j at i * 0x10 + j * 4). Overhead is l = (0, 1, 0).
        static const float overhead_light[3] = {0.0f, 1.0f, 0.0f};
        const float* l = tilted(tooie::hd_shadows::enemy_direction_option) ? tilt_light : overhead_light;
        const float n[3] = {nx, ny, nz};
        const float inv = 1.0f / (l[0] * nx + l[1] * ny + l[2] * nz);
        ctx->r4 = flatten;
        func_800F274C(rdram, ctx);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                store_float(rdram, flatten + i * 0x10 + j * 4, (i == j ? 1.0f : 0.0f) - n[i] * l[j] * inv);
            }
        }

        // The actor's turn, folded in as func_800A6250 does for the player.
        ctx->r4 = actor;
        func_801027F4(rdram, ctx);
        const gpr angles = (int32_t)(uint32_t)ctx->r2;
        func_80019CD4(rdram, ctx);
        ctx->f12.fl = load_float(rdram, angles + 4);
        mlMtxRotYaw(rdram, ctx);
        ctx->f12.fl = load_float(rdram, angles);
        mlMtxRotPitch(rdram, ctx);
        ctx->f12.fl = load_float(rdram, angles + 8);
        mlMtxRotRoll(rdram, ctx);
        ctx->r4 = rotation;
        mlMtxGet(rdram, ctx);
        ctx->r4 = rotation;
        ctx->r5 = flatten;
        ctx->r6 = flatten;
        func_800F27D4(rdram, ctx);

        // The model's size, for the area to paste (func_800A6250 after the draw).
        ctx->r4 = model;
        func_800B2840(rdram, ctx);
        ctx->r4 = ctx->r2;
        func_800B2354(rdram, ctx);
        const float radius = ctx->f0.fl * scale;
        for (int i = 0; i < 8; i++) {
            const gpr corner = corners + i * 12;
            store_vec(rdram, corner, (i & 4) ? -radius : radius, (i & 2) ? 0.0f : radius, (i & 1) ? -radius : radius);
            ctx->r4 = flatten;
            ctx->r5 = corner;
            ctx->r6 = corner;
            func_800F23D0(rdram, ctx);
            ctx->r4 = corner;
            ctx->r5 = floor;
            func_800EF04C(rdram, ctx);
        }
        float min_x = 0, min_y = 0, max_x = 0, max_y = 0;
        for (int i = 0; i < 8; i++) {
            ctx->r4 = corners + i * 12;
            ctx->r5 = screen + i * 8;
            ctx->r6 = visible;
            func_800E4190(rdram, ctx);
            if (MEM_W(0, visible) == 0) {
                count(Offscreen);
                return;
            }
            const float sx = load_float(rdram, screen + i * 8);
            const float sy = load_float(rdram, screen + i * 8 + 4);
            if (i == 0 || sx < min_x) min_x = sx;
            if (i == 0 || sx > max_x) max_x = sx;
            if (i == 0 || sy < min_y) min_y = sy;
            if (i == 0 || sy > max_y) max_y = sy;
        }
        min_x = std::clamp(min_x, 0.0f, 304.0f);
        max_x = std::clamp(max_x, 0.0f, 304.0f);
        min_y = std::clamp(min_y, 0.0f, 228.0f);
        max_y = std::clamp(max_y, 0.0f, 228.0f);
        if (max_x - min_x < 1.0f || max_y - min_y < 1.0f) {
            count(TooSmall);
            return;
        }

        // Pose and shadow look for the next model draw.
        ctx->r4 = (int32_t)draw_callback;
        ctx->r5 = actor;
        func_800DF47C(rdram, ctx);
        ctx->r4 = flatten;
        func_800DF540(rdram, ctx);
        func_800A61D4(rdram, ctx);

        // Clear the shadow buffer and draw into it (the same commands as func_800A6250).
        func_800A7180(rdram, ctx);
        const gpr gfx_head = (int32_t)(uint32_t)ctx->r2;
        func_8001575C(rdram, ctx);
        const uint32_t buffer = (uint32_t)ctx->r2;
        push_gfx(rdram, gfx_head, 0xE7000000, 0);
        push_gfx(rdram, gfx_head, 0xFF48012F, buffer + 0x80000000);
        push_gfx(rdram, gfx_head, 0xE3000800, 0);
        push_gfx(rdram, gfx_head, 0xE3000A01, 0x300000);
        push_gfx(rdram, gfx_head, 0xF7000000, 0xFFFEFFFE);
        push_gfx(rdram, gfx_head, 0xE200001C, 0);
        push_gfx(rdram, gfx_head, 0xF64BC38C, 0);

        // func_8010347C sets the model id and draw distances (D_8012CA18, by func_800DF7F8), as in
        // func_80101808; the model itself is passed in, so the renderer does not fetch it again.
        ctx->r4 = (int32_t)MEM_W(0, actor);
        func_8010347C(rdram, ctx);
        ctx->r4 = floor;
        ctx->r5 = 0;
        ctx->r6 = float_bits(scale);
        ctx->r7 = 0;
        MEM_W(0x10, ctx->r29) = drawn;  // the model the actor's own draw used
        in_shadow_pass = true;
        func_800DE448(rdram, ctx);
        in_shadow_pass = false;

        // Back to the screen, then paste.
        push_gfx(rdram, gfx_head, 0xE7000000, 0);
        ctx->r4 = gfx_head;
        func_800E7CF4(rdram, ctx);
        func_8001575C(rdram, ctx);
        const int x0 = (int)min_x, y0 = (int)min_y;
        ctx->r4 = gfx_head;
        ctx->r5 = ctx->r2;
        ctx->r6 = x0;
        ctx->r7 = y0;
        MEM_W(0x10, ctx->r29) = (uint32_t)((int)max_x - x0);
        MEM_W(0x14, ctx->r29) = (uint32_t)((int)max_y - y0);
        MEM_W(0x18, ctx->r29) = 0xFF;
        func_800A5EC4(rdram, ctx);
        shadows_this_frame++;
        count(Drawn);
    }
}

void tooie::hd_shadows::tick() {
    shadows_this_frame = 0;
    if (shadow_log) {
        static int frames = 0;
        if (++frames >= 60) {
            std::printf("[shadow] actors in 60 frames: drawn %d, no model %d, no floor %d, steep %d, off screen %d, too small %d, no room %d\n",
                outcomes[Drawn], outcomes[NoModel], outcomes[NoFloor], outcomes[Steep], outcomes[Offscreen], outcomes[TooSmall], outcomes[NoRoom]);
            std::fflush(stdout);
            std::memset(outcomes, 0, sizeof(outcomes));
            frames = 0;
        }
    }
}

extern "C" void tooie_shadow_render_mode(uint8_t* /*rdram*/, recomp_context* ctx) {
    if (in_shadow_pass) {
        ctx->r4 = 3;  // the shadow render mode func_800A61D4 set
    }
}

extern "C" void tooie_shadow_note_model(uint8_t* rdram, recomp_context* ctx) {
    if (!in_shadow_pass && draw_callbacks.size() == 1) {
        drawn_model = MEM_W(0x10C, ctx->r29);
    }
}

extern "C" void tooie_actor_draw_begin(uint8_t* /*rdram*/, recomp_context* ctx) {
    if (draw_callbacks.empty()) {
        drawn_model = 0;
    }
    draw_callbacks.push_back((uint32_t)ctx->r5);
}

extern "C" void tooie_actor_shadow(uint8_t* rdram, recomp_context* ctx) {
    if (draw_callbacks.empty()) {
        return;
    }
    const uint32_t draw_callback = draw_callbacks.back();
    draw_callbacks.pop_back();
    // Only outermost draws: one nested in another actor's draw (or in a shadow pass) would reset
    // the outer draw's state halfway through.
    if (!draw_callbacks.empty() || in_shadow_pass || !hd_shadows_on()) {
        return;
    }
    if (shadows_this_frame >= max_per_frame || draw_callback == 0 || drawn_model == 0) {
        return;
    }
    if (!tooie::gfx_budget::room_for_extras(rdram)) {
        count(NoRoom);
        return;
    }
    // Work on a copy so func_80101808 carries on with its own registers, below its stack frame.
    recomp_context scratch = *ctx;
    const gpr frame = (ctx->r29 - 0x200) & ~(gpr)0xF;
    scratch.r29 = frame;
    // The shadow draw runs the actor's draw callback a second time this frame. Put the Actor
    // (0x9C bytes) back as the real draw left it, so per-draw counters and flags only move once.
    const gpr actor = ctx->r16;
    uint32_t saved[0x9C / 4];
    for (int i = 0; i < 0x9C / 4; i++) {
        saved[i] = MEM_W(i * 4, actor);
    }
    draw_actor_shadow(rdram, &scratch, actor, frame, draw_callback, drawn_model);
    for (int i = 0; i < 0x9C / 4; i++) {
        MEM_W(i * 4, actor) = saved[i];
    }
}
