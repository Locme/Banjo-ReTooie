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

    tooie::hd_shadows::Direction direction(const std::string& option) {
        try {
            return static_cast<tooie::hd_shadows::Direction>(std::get<uint32_t>(
                recompui::config::get_config(recompui::config::graphics::id).get_option_value(option)));
        } catch (...) {
            return tooie::hd_shadows::Direction::Overhead;
        }
    }

    bool tilted(const std::string& option) {
        return direction(option) == tooie::hd_shadows::Direction::Tilt;
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
    // "HD Shadows: Banjo" Off leaves the game's shadow model and light for the player.
    if (hd_shadows_on() && direction(tooie::hd_shadows::banjo_direction_option) != tooie::hd_shadows::Direction::Off) {
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
    enum Outcome { NoModel, NoFloor, Steep, Offscreen, TooSmall, NoRoom, Drawn, Lit, OutcomeCount };
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
    // The display list spans of this frame's actor shadow pastes, already placed for the window
    // shape (paste_x), so fix_pastes leaves them alone.
    std::vector<std::pair<uint32_t, uint32_t>> actor_pastes;
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

    // Where a screen x (the game's 4:3 view, 0 to 304) has to go in the shadow paste. With a wide
    // window RT64 draws the 3D view, and so the shadow in its buffer, squeezed towards the middle,
    // but it stretches the paste's rectangles (they read a framebuffer) across the whole width. So
    // the rectangle is squeezed the same way here, or it covers the wrong place and cuts the shadow.
    // The actor shadows below use it directly; the player's paste (func_800A6250) is moved
    // afterwards by tooie::hd_shadows::fix_pastes.
    float paste_x(float x) {
        return 152.0f + (x - 152.0f) / tooie::widescreen_scale();
    }

    // The nearest of the level's lights (lamps, fires) that reaches the point, found as
    // func_800A6B24 does for the player's shadow: l is the direction from the light to the point.
    // Returns false when no light reaches it.
    bool level_light(uint8_t* rdram, recomp_context* ctx, gpr frame, const float point[3], float reach, float l[3]) {
        const gpr light_pos = frame + 0x1A0;  // vec3
        const gpr light_range = frame + 0x1B0;  // inner, outer range, intensity
        float best = 0.0f;
        bool found = false;
        ctx->r4 = 0;
        ctx->r5 = 1;
        func_800C8760(rdram, ctx);
        for (int guard = 0; ctx->r2 != 0 && guard < 64; guard++) {
            const gpr light = (int32_t)(uint32_t)ctx->r2;
            ctx->r4 = light;
            func_800C89A8(rdram, ctx);
            if ((ctx->r2 & 0x8) == 0) {
                ctx->r4 = light;
                ctx->r5 = light_pos;
                func_800C8800(rdram, ctx);
                ctx->r4 = light;
                ctx->r5 = light_range;
                func_800C8898(rdram, ctx);
                const float d[3] = {
                    point[0] - load_float(rdram, light_pos),
                    point[1] - load_float(rdram, light_pos + 4),
                    point[2] - load_float(rdram, light_pos + 8),
                };
                const float dist = std::sqrt(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
                if (dist > 0.0f && dist < load_float(rdram, light_range + 4) + reach && (!found || dist < best)) {
                    best = dist;
                    found = true;
                    for (int i = 0; i < 3; i++) {
                        l[i] = d[i] / dist;
                    }
                }
            }
            ctx->r4 = light;
            ctx->r5 = 0;
            ctx->r6 = 1;
            func_800C878C(rdram, ctx);
        }
        return found;
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

        // The model's size, for the light's reach and the area to paste (func_800A6250 after the draw).
        ctx->r4 = model;
        func_800B2840(rdram, ctx);
        ctx->r4 = ctx->r2;
        func_800B2354(rdram, ctx);
        const float radius = ctx->f0.fl * scale;

        // Flatten along the light l onto the floor plane: M = I - n l / (l . n), as func_800A6250
        // (row i, column j at i * 0x10 + j * 4). A level light in reach wins, as for the player;
        // otherwise overhead, l = (0, 1, 0), or Tilt. A light too close to the floor's plane
        // would stretch the shadow out of sight, so it is lifted towards overhead.
        float l[3] = {0.0f, 1.0f, 0.0f};
        const float center[3] = {x, y + radius * 0.5f, z};
        if (level_light(rdram, ctx, frame, center, radius, l)) {
            count(Lit);
            if (l[1] < 0.0f) {
                for (float& c : l) c = -c;  // a light below: the same line through the point
            }
            if (l[1] < 0.5f) {
                l[1] = 0.5f;
                const float len = std::sqrt(l[0] * l[0] + l[1] * l[1] + l[2] * l[2]);
                for (float& c : l) c /= len;
            }
        } else if (tilted(tooie::hd_shadows::enemy_direction_option)) {
            std::memcpy(l, tilt_light, sizeof(l));
        }
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
        min_x = std::clamp(paste_x(min_x), 0.0f, 304.0f);
        max_x = std::clamp(paste_x(max_x), 0.0f, 304.0f);
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
        const uint32_t paste_start = MEM_W(0, gfx_head) & 0x1FFFFFFF;
        func_800A5EC4(rdram, ctx);
        actor_pastes.push_back({paste_start, (uint32_t)MEM_W(0, gfx_head) & 0x1FFFFFFF});
        shadows_this_frame++;
        count(Drawn);
    }
}

void tooie::hd_shadows::tick() {
    shadows_this_frame = 0;
    if (shadow_log) {
        static int frames = 0;
        if (++frames >= 60) {
            std::printf("[shadow] actors in 60 frames: drawn %d, no model %d, no floor %d, steep %d, off screen %d, too small %d, no room %d, lit by a level light %d\n",
                outcomes[Drawn], outcomes[NoModel], outcomes[NoFloor], outcomes[Steep], outcomes[Offscreen], outcomes[TooSmall], outcomes[NoRoom], outcomes[Lit]);
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

// The shadow pastes left in the 3D scene's display list (start to end, physical addresses): each
// reads the 8-bit shadow buffer (TIMG 0xFD48012F) with LOADTILE, SETTILESIZE and TEXRECT strips.
// The player's, from func_800A6250, are placed for a 4:3 view, so with a wide window they are
// moved sideways by as much as paste_x moves their middle; the strips keep their width, which is
// wider than the squeezed shadow needs. The actor pastes were placed already and are skipped.
void tooie::hd_shadows::fix_pastes(uint8_t* rdram, uint32_t start, uint32_t end) {
    const auto skip = std::move(actor_pastes);
    actor_pastes.clear();
    if (tooie::widescreen_scale() <= 1.0f || start >= end || end > 0x800000) {
        return;
    }
    auto word = [&](uint32_t phys) { return (uint32_t)MEM_W(0, (gpr)(int32_t)(phys | 0x80000000)); };
    auto set_word = [&](uint32_t phys, uint32_t value) { MEM_W(0, (gpr)(int32_t)(phys | 0x80000000)) = value; };
    for (uint32_t cmd = start; cmd + 8 <= end; cmd += 8) {
        if (word(cmd) != 0xFD48012F) {
            continue;
        }
        bool ours = false;
        for (const auto& span : skip) {
            ours |= cmd >= span.first && cmd < span.second;
        }
        // The paste's commands, up to the first that is none of them.
        uint32_t last = cmd + 8;
        int dx = 0;
        bool have_dx = false;
        for (; last + 8 <= end; last += 8) {
            const uint32_t op = word(last) >> 24;
            if (op == 0xE4 && !have_dx) {
                const int lrx = (word(last) >> 12) & 0xFFF, ulx = (word(last + 4) >> 12) & 0xFFF;
                const float middle = (ulx + lrx) / 8.0f;
                dx = (int)std::lround((paste_x(middle) - middle) * 4.0f);
                dx = std::clamp(dx, -ulx, std::max(-ulx, 304 * 4 - lrx));
                have_dx = true;
            }
            if (op != 0xF5 && op != 0xE6 && op != 0xE7 && op != 0xE8 && op != 0xF4 && op != 0xF2 && op != 0xE4 && op != 0xE1 && op != 0xF1) {
                break;
            }
        }
        if (!ours && dx != 0) {
            for (uint32_t c = cmd + 8; c < last; c += 8) {
                const uint32_t w0 = word(c), w1 = word(c + 4), op = w0 >> 24;
                auto move12 = [&](uint32_t w) { return (w & ~(0xFFFu << 12)) | ((((w >> 12) & 0xFFF) + dx) & 0xFFF) << 12; };
                if (op == 0xF4 || op == 0xF2) {
                    set_word(c, move12(w0));
                    set_word(c + 4, move12(w1));
                } else if (op == 0xE4) {
                    set_word(c, move12(w0));
                    set_word(c + 4, move12(w1));
                } else if (op == 0xE1) {
                    // s in 10.5: the texture moves with the rectangle.
                    set_word(c + 4, (w1 & 0xFFFF) | ((((w1 >> 16) + dx * 8) & 0xFFFF) << 16));
                }
            }
        }
        cmd = last - 8;
    }
}

