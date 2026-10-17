// Back-Port: Glittering honeycombs (handoff 4.63).
//
// In Banjo-Kazooie the health honeycombs sparkle; in Tooie only the empty
// honeycombs do. Banjo-Kazooie's honeycomb update (chHoneycomb_update in the
// BK decomp) tries 4 points on the comb's model every frame at 3% each and
// flashes a small yellow sparkle that stays where it appears, so the glints
// sit on the comb itself. With General > Back-Port: Glittering honeycombs on,
// this file does the same for Tooie's health honeycombs, once per game frame
// from tooie_warp_tick: 4 points around the comb's middle (bone 1 of its model,
// read the way Tooie's own empty honeycomb reads it), to the left and right of
// it as seen from Banjo, above and below, each flashing about 0.9 times a
// second (3% a frame at 30 frames a second), with Tooie's twinkle sprite
// (_fxtwinkle_entrypoint_0, sprite 0x9E2). The rate is per second of real time,
// so it does not depend on the frame rate.
//
// Objects: the pointer at 0x80136EE0 is the object array; +4 and +8 point at
// its first and last object, each 0x9C bytes from +0x10. An object's +0 points
// at its id struct (model at +0x14, u16) and +4 is its position. Health
// honeycomb models: 0x614, 0x704 and 0x705 (ScriptHawk's model list).

#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <random>

#include "recomp.h"
#include "funcs.h"
#include "recompui/config.h"
#include "tooie_honeycomb_glitter.h"
#include "tooie_rdram.h"

namespace {
    constexpr uint32_t object_array_pointer = 0x80136EE0;
    constexpr uint32_t object_first = 0x04;
    constexpr uint32_t object_last = 0x08;
    constexpr uint32_t object_base = 0x10;
    constexpr uint32_t object_size = 0x9C;
    constexpr uint32_t object_id = 0x00;
    constexpr uint32_t object_pos = 0x04;
    constexpr uint32_t id_model = 0x14;
    constexpr uint16_t health_models[] = { 0x614, 0x704, 0x705 };

    // Banjo-Kazooie's honeycomb (chHoneycomb_update) tries each of 4 points on the comb every frame at 3%,
    // so each point flashes about 0.9 times a second at 30 frames a second.
    constexpr int sparkle_points = 4;
    constexpr double sparkles_per_point_per_second = 0.9;
    // The points sit this far to each side of the comb's middle, above and below it, and a little towards
    // the player so the comb doesn't hide them.
    constexpr float point_side = 12.0f;
    constexpr float point_up = 10.0f;
    constexpr float point_front = 8.0f;
    constexpr int max_objects = 2048;

    std::mt19937 rng{1234};
    std::chrono::steady_clock::time_point last_tick;
    bool have_last = false;

    using tooie::rdram::read_float;
    using tooie::rdram::read_word;
    using tooie::rdram::valid_ptr;
    using tooie::rdram::write_float;
    using tooie::rdram::write_word;

    uint16_t read_half(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<uint16_t*>(rdram + ((addr ^ 2) - 0x80000000u));
    }

    bool enabled() {
        try {
            return std::get<bool>(recompui::config::get_general_config().get_option_value(tooie::honeycomb_glitter::option));
        } catch (...) {
            return false;
        }
    }

    bool is_health_honeycomb(uint16_t model) {
        // Headless test aid: TOOIE_HONEYCOMB_MODEL=<hex model> sparkles that model too.
        static const long extra = std::getenv("TOOIE_HONEYCOMB_MODEL") ? std::strtol(std::getenv("TOOIE_HONEYCOMB_MODEL"), nullptr, 16) : -1;
        if (model == extra) {
            return true;
        }
        for (uint16_t m : health_models) {
            if (m == model) {
                return true;
            }
        }
        return false;
    }

    // The comb's middle: bone 1 of its model, found the way the empty honeycomb's update finds it
    // (_subaddieskeleton_entrypoint_0(object, 1, out)), about 33 units above the object's position.
    void comb_centre(uint8_t* rdram, recomp_context* ctx, uint32_t obj, float out[3]) {
        recomp_context saved = *ctx;
        const uint32_t vec = ((uint32_t)ctx->r29 - 0x100) & ~0xFu;
        ctx->r29 = (int32_t)(vec - 0x40);
        ctx->r4 = (int32_t)obj;
        ctx->r5 = 1;
        ctx->r6 = (int32_t)vec;
        _subaddieskeleton_entrypoint_0(rdram, ctx);
        const bool ok = ctx->r2 != 0;
        *ctx = saved;
        for (int k = 0; k < 3; k++) {
            out[k] = ok ? read_float(rdram, vec + 4 * k) : read_float(rdram, obj + object_pos + 4 * k);
        }
        if (!ok) {
            out[1] += 33.0f;
        }
    }

    // Spawns one twinkle at pos, through the game's own spawner, with a copy of the hook's context
    // so the caller's registers stay untouched. The position goes in a scratch area below the stack.
    void spawn_twinkle(uint8_t* rdram, recomp_context* ctx, const float pos[3]) {
        recomp_context saved = *ctx;
        const uint32_t sp = (uint32_t)ctx->r29;
        const uint32_t vec = (sp - 0x100) & ~0xFu;
        write_float(rdram, vec + 0, pos[0]);
        write_float(rdram, vec + 4, pos[1]);
        write_float(rdram, vec + 8, pos[2]);
        ctx->r29 = (int32_t)(vec - 0x40);
        ctx->r4 = (int32_t)vec;
        _fxtwinkle_entrypoint_0(rdram, ctx);
        *ctx = saved;
    }
}

void tooie::honeycomb_glitter::tick(uint8_t* rdram, recomp_context* ctx) {
    static const bool log = std::getenv("TOOIE_HONEYCOMB_LOG") != nullptr;
    auto now = std::chrono::steady_clock::now();
    double dt = have_last ? std::chrono::duration<double>(now - last_tick).count() : 0.0;
    last_tick = now;
    have_last = true;
    if (dt <= 0.0 || dt > 0.25 || (!enabled() && !log)) {
        return;
    }

    const uint32_t array = read_word(rdram, object_array_pointer);
    if (!valid_ptr(array)) {
        return;
    }
    const uint32_t first = read_word(rdram, array + object_first);
    const uint32_t last = read_word(rdram, array + object_last);
    if (!valid_ptr(first) || !valid_ptr(last) || last < first) {
        return;
    }
    int count = (int)((last - first) / object_size) + 1;
    if (count > max_objects) {
        return;
    }

    std::uniform_real_distribution<float> unit(0.0f, 1.0f);
    // Headless test aid: TOOIE_HONEYCOMB_RATE=<x> sparkles x times as often.
    static const double rate_scale = std::getenv("TOOIE_HONEYCOMB_RATE") ? std::atof(std::getenv("TOOIE_HONEYCOMB_RATE")) : 1.0;
    const double chance = sparkles_per_point_per_second * rate_scale * dt;

    // Headless test aid: TOOIE_HONEYCOMB_AT_PLAYER=1 sparkles around Banjo, to see the spawner work.
    static const bool at_player = std::getenv("TOOIE_HONEYCOMB_AT_PLAYER") != nullptr;
    if (at_player) {
        const uint32_t player = read_word(rdram, 0x80135490);
        const uint32_t pos_ptr = valid_ptr(player) ? read_word(rdram, player + 0xE4) : 0;
        if (valid_ptr(pos_ptr) && unit(rng) < chance * 4) {
            float pos[3] = { read_float(rdram, pos_ptr) + (unit(rng) - 0.5f) * 80.0f,
                             read_float(rdram, pos_ptr + 4) + unit(rng) * 80.0f,
                             read_float(rdram, pos_ptr + 8) + (unit(rng) - 0.5f) * 80.0f };
            spawn_twinkle(rdram, ctx, pos);
        }
    }
    bool have_player = false;
    float player_x = 0.0f, player_z = 0.0f;
    {
        const uint32_t player = read_word(rdram, 0x80135490);
        const uint32_t pos_ptr = valid_ptr(player) ? read_word(rdram, player + 0xE4) : 0;
        if (valid_ptr(pos_ptr)) {
            player_x = read_float(rdram, pos_ptr);
            player_z = read_float(rdram, pos_ptr + 8);
            have_player = true;
        }
    }
    int found = 0;
    for (int i = 0; i < count; i++) {
        const uint32_t obj = array + object_base + (uint32_t)i * object_size;
        const uint32_t id = read_word(rdram, obj + object_id);
        if (!valid_ptr(id) || !is_health_honeycomb(read_half(rdram, id + id_model))) {
            continue;
        }
        found++;
        // Headless test aid: TOOIE_HONEYCOMB_GO=<ms> moves Banjo next to the first health honeycomb (held for 30
        // frames), that long after a health honeycomb is first seen.
        static const char* go = std::getenv("TOOIE_HONEYCOMB_GO");
        static std::chrono::steady_clock::time_point first_seen = now;
        static int holds = 0;
        if (go && found == 1 && holds < 30 && now - first_seen > std::chrono::milliseconds(std::atoi(go))) {
            holds++;
            if (holds == 1) {
                printf("[honeycomb] moving Banjo to the honeycomb at %.0f %.0f %.0f\n", read_float(rdram, obj + 4), read_float(rdram, obj + 8), read_float(rdram, obj + 12));
                fflush(stdout);
            }
            const uint32_t player = read_word(rdram, 0x80135490);
            const uint32_t physics = valid_ptr(player) ? read_word(rdram, player + 0xC8) : 0;
            const uint32_t pos_ptr = valid_ptr(player) ? read_word(rdram, player + 0xE4) : 0;
            for (uint32_t base : { physics + 4, pos_ptr }) {
                if (valid_ptr(base)) {
                    write_float(rdram, base + 0, read_float(rdram, obj + object_pos + 0) + 150.0f);
                    write_float(rdram, base + 4, read_float(rdram, obj + object_pos + 4));
                    write_float(rdram, base + 8, read_float(rdram, obj + object_pos + 8));
                }
            }
        }
        if (!enabled()) {
            continue;
        }
        float centre[3];
        comb_centre(rdram, ctx, obj, centre);
        const float cx = centre[0], cy = centre[1], cz = centre[2];
        // Towards the player, flat; the comb's points are laid out across that direction.
        float fx = player_x - cx, fz = player_z - cz;
        float len = std::sqrt(fx * fx + fz * fz);
        if (!have_player || len < 1.0f) {
            fx = 0.0f; fz = 1.0f;
        } else {
            fx /= len; fz /= len;
        }
        for (int p = 0; p < sparkle_points; p++) {
            if (unit(rng) >= chance) {
                continue;
            }
            const float side = (p & 1) ? point_side : -point_side;
            const float up = (p & 2) ? point_up : -point_up;
            float pos[3] = { cx + fz * side + fx * point_front, cy + up, cz - fx * side + fz * point_front };
            spawn_twinkle(rdram, ctx, pos);
        }
    }
    if (log) {
        static int last_found = -1;
        if (found != last_found) {
            printf("[honeycomb] %d health honeycombs among %d objects\n", found, count);
            fflush(stdout);
            last_found = found;
        }
    }
}


