// Volumetric dust (WIP tab, Volumetrics): see include/tooie_dust.h.
//
// The game's dust is a textured puff (an fxdlsmoke object) made by badust_entrypoint_2, which every dust move calls (the
// foot dust of walking, running and the Talon Trot, the quick turn's skid, landings). With the option on, a hook at that
// function's entry (banjotooie.us.toml) takes the puff's place and returns, so no sprite is made: this file keeps its own
// small cloud there instead. A cloud inherits some of Banjo's velocity, rises, slows in the air and is pushed aside by Banjo
// walking through it; the renderer draws the clouds (RT64::SetSceneDust) as volumes lit by the sun and tinted by the ground
// they are in front of.
//
// Debug: TOOIE_DUST_LOG=1 logs each puff's raw numbers (the units of the game's scale are not known, so the world size
// below is a guess to tune), TOOIE_DUST=1 turns the option on.

#include <algorithm>
#include <atomic>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <mutex>
#include <variant>

#include "recomp.h"
#include "recompui/config.h"

#include "tooie_dust.h"
#include "tooie_game_frame_rate.h"
#include "tooie_hooks.h"
#include "tooie_rdram.h"

namespace RT64 {
    // rt64-ext/src/render/rt64_scene_effects.h: up to 24 clouds, eight floats each (x, y, z, radius, strength, seed, 0, 0).
    void SetSceneDust(const float* clouds, uint32_t count);
}

namespace {
    using tooie::rdram::read_float;
    using tooie::rdram::read_word;
    using tooie::rdram::valid_ptr;

    constexpr int max_clouds = 24;
    constexpr uint32_t player_table = 0x80135490;
    // World units of radius for one unit of the game's puff scale, and the cloud's life: tuned by eye (L's test).
    constexpr float radius_per_scale = 22.0f;
    constexpr float life_seconds = 0.9f;

    struct Cloud {
        float pos[3];
        float vel[3];
        float radius_start;
        float radius_end;
        float age;
        float life;
        float seed;
    };

    std::mutex cloud_mutex;
    Cloud clouds[max_clouds];
    int cloud_count = 0;
    uint32_t spawned = 0;
    std::atomic<bool> enabled{ false };
    bool log_puffs = false;

    uint32_t player_pointer(uint8_t* rdram) {
        const uint32_t player = read_word(rdram, player_table);
        return valid_ptr(player) ? player : 0;
    }

    // Banjo's position and velocity (units a second), false when there is no player.
    bool banjo(uint8_t* rdram, float position[3], float velocity[3]) {
        const uint32_t player = player_pointer(rdram);
        if (player == 0) {
            return false;
        }
        const uint32_t pos = read_word(rdram, player + 0xE4);
        if (!valid_ptr(pos)) {
            return false;
        }
        for (int i = 0; i < 3; i++) {
            position[i] = read_float(rdram, pos + 4 * i);
        }
        velocity[0] = velocity[1] = velocity[2] = 0.0f;
        const uint32_t physics = read_word(rdram, player + 0xC8);
        if (valid_ptr(physics)) {
            velocity[0] = read_float(rdram, physics + 0x10);
            velocity[2] = read_float(rdram, physics + 0x18);
        }
        return true;
    }

    float hash(uint32_t n) {
        n ^= n >> 16;
        n *= 0x7feb352dU;
        n ^= n >> 15;
        n *= 0x846ca68bU;
        n ^= n >> 16;
        return float(n & 0xFFFFFF) / float(0x1000000);
    }

    float as_float(uint32_t bits) {
        float value;
        std::memcpy(&value, &bits, sizeof(value));
        return value;
    }

    bool option_value() {
        if (const char* forced = std::getenv("TOOIE_DUST")) {
            return std::atoi(forced) != 0;
        }
        try {
            return std::get<bool>(recompui::config::get_config(recompui::config::graphics::id).get_option_value(tooie::dust::option));
        } catch (...) {
            return false;
        }
    }
}

void tooie::dust::add_options(recomp::config::Config& graphics) {
    graphics.add_bool_option(
        option,
        "Volumetric Dust",
        "WIP. The dust Banjo kicks up when he runs, sprints, Talon Trots, turns quickly and lands is a real volume instead of a flat textured puff: soft clouds that take some of his speed, rise and thin out, are pushed aside as he moves through them, are lit by the sun and take the colour of the ground. The grass, dirt, sand and snow under his feet change the colour and the kind of dust. Replaces the game's puffs while on.",
        true);
    graphics.add_option_change_callback(option,
        [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
            if (context == recomp::config::OptionChangeContext::Temporary) {
                recompui::config::get_graphics_config().save_config();
            }
        });
}

void tooie::dust::tick(uint8_t* rdram) {
    static double last = -1.0;
    static bool first = true;
    if (first) {
        first = false;
        log_puffs = std::getenv("TOOIE_DUST_LOG") != nullptr;
    }
    const double now = tooie::game_frame_rate::game_seconds();
    const float dt = (last < 0.0) ? 0.0f : float(std::clamp(now - last, 0.0, 0.1));
    last = now;
    const bool on = option_value();
    enabled = on;

    float position[3], velocity[3];
    const bool have_banjo = banjo(rdram, position, velocity);
    float speed = std::sqrt(velocity[0] * velocity[0] + velocity[2] * velocity[2]);

    std::lock_guard lock{ cloud_mutex };
    if (!on) {
        cloud_count = 0;
    }
    int kept = 0;
    for (int i = 0; i < cloud_count; i++) {
        Cloud c = clouds[i];
        c.age += dt;
        if (c.age >= c.life) {
            continue;
        }
        // Slows down in the air, and eases from the rise.
        const float drag = std::exp(-2.4f * dt);
        c.vel[0] *= drag;
        c.vel[2] *= drag;
        c.vel[1] *= std::exp(-1.6f * dt);
        // Banjo walking through the cloud pushes it aside, more the faster he goes.
        if (have_banjo && (c.age > 0.08f)) {
            const float dx = c.pos[0] - position[0];
            const float dy = (c.pos[1] - (position[1] + 20.0f)) * 0.6f;
            const float dz = c.pos[2] - position[2];
            const float reach = 70.0f;
            const float distance = std::sqrt(dx * dx + dy * dy + dz * dz);
            if (distance < reach && distance > 1.0f) {
                const float push = (1.0f - distance / reach) * (60.0f + 0.5f * speed) * dt;
                c.vel[0] += dx / distance * push * 4.0f;
                c.vel[1] += dy / distance * push * 2.0f;
                c.vel[2] += dz / distance * push * 4.0f;
            }
        }
        for (int k = 0; k < 3; k++) {
            c.pos[k] += c.vel[k] * dt;
        }
        clouds[kept++] = c;
    }
    cloud_count = kept;

    float packed[max_clouds * 8] = {};
    for (int i = 0; i < cloud_count; i++) {
        const Cloud& c = clouds[i];
        const float t = c.age / c.life;
        // Swells quickly, then keeps growing slowly; thickest early, gone by the end.
        const float grow = 1.0f - (1.0f - t) * (1.0f - t);
        const float strength = std::min(1.0f, t * 8.0f) * (1.0f - t) * (1.0f - t * 0.3f);
        float* out = packed + i * 8;
        out[0] = c.pos[0];
        out[1] = c.pos[1];
        out[2] = c.pos[2];
        out[3] = c.radius_start + (c.radius_end - c.radius_start) * grow;
        out[4] = strength;
        out[5] = c.seed;
    }
    RT64::SetSceneDust(packed, uint32_t(cloud_count));
}

namespace {
    // Takes the puff's place: a cloud at the position (3 floats at `at`) growing from one scale of the game's puff to the other.
    bool spawn(uint8_t* rdram, uint32_t at, float scale_start, float scale_end) {
        if (!enabled.load() || !valid_ptr(at)) {
            return false;
        }
        if (log_puffs) {
            std::fprintf(stderr, "[dust] puff at %.1f %.1f %.1f scale %.3f -> %.3f\n",
                read_float(rdram, at), read_float(rdram, at + 4), read_float(rdram, at + 8), scale_start, scale_end);
        }
        float position[3], velocity[3];
        const bool have_banjo = banjo(rdram, position, velocity);
        std::lock_guard lock{ cloud_mutex };
        if (cloud_count >= max_clouds) {
            // Full: the oldest makes way.
            std::memmove(clouds, clouds + 1, sizeof(Cloud) * (max_clouds - 1));
            cloud_count = max_clouds - 1;
        }
        Cloud& c = clouds[cloud_count++];
        const uint32_t n = ++spawned;
        for (int i = 0; i < 3; i++) {
            c.pos[i] = read_float(rdram, at + 4 * i);
        }
        // Part of Banjo's speed, a sideways scatter and a lift.
        const float scatter = 14.0f;
        c.vel[0] = (have_banjo ? velocity[0] * 0.3f : 0.0f) + (hash(n * 3 + 1) - 0.5f) * 2.0f * scatter;
        c.vel[1] = 18.0f + hash(n * 3 + 2) * 14.0f;
        c.vel[2] = (have_banjo ? velocity[2] * 0.3f : 0.0f) + (hash(n * 3 + 3) - 0.5f) * 2.0f * scatter;
        const float start = std::clamp(scale_start, 0.05f, 4.0f);
        const float end = std::clamp(std::max(scale_end, scale_start), 0.1f, 6.0f);
        c.radius_start = std::max(8.0f, start * radius_per_scale);
        c.radius_end = std::max(c.radius_start * 1.5f, end * radius_per_scale);
        c.age = 0.0f;
        c.life = life_seconds * (0.8f + 0.4f * hash(n * 7 + 5));
        c.seed = hash(n * 11 + 9) * 64.0f;
        return true;
    }
}

// Hooked at the entry of badust_entrypoint_2 ($a0 object, $a1 the puff's position (3 floats, handed on to the smoke
// object's creation), $a2 its velocity, $a3 the start scale; the caller's stack holds the end scale at 0x10 and a rate at
// 0x14): used by the quick turn and a few other moves. 1 takes the puff's place: the function is skipped.
extern "C" int tooie_dust_spawn(uint8_t* rdram, recomp_context* ctx) {
    const uint32_t sp = uint32_t(ctx->r29);
    return spawn(rdram, uint32_t(ctx->r5), as_float(uint32_t(ctx->r7)), read_float(rdram, sp + 0x10)) ? 1 : 0;
}

// Hooked in badust_entrypoint_4 (the foot dust of walking, running and the Talon Trot, and others) just before it creates
// its smoke object: $s0 points at the puff's position, the scales are fixed in the function (about 0.35 growing to 0.7).
extern "C" int tooie_dust_spawn_foot(uint8_t* rdram, recomp_context* ctx) {
    return spawn(rdram, uint32_t(ctx->r16), 0.35f, 0.7f) ? 1 : 0;
}
