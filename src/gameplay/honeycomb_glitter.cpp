// Back-Port: Glittering honeycombs (handoff 4.63).
//
// In Banjo-Kazooie the health honeycombs sparkle; in Tooie only the empty
// honeycombs do. The empty honeycomb's update (func_80800754_chhoney) makes 4
// tries a frame at a few percent each to spawn the twinkle sprite
// (_fxtwinkle_entrypoint_0, sprite 0x9E2) at a random point up to 50 units
// from it. With General > Back-Port: Glittering honeycombs on, this file does
// the same for health honeycombs, once per game frame from tooie_warp_tick.
//
// Objects: the pointer at 0x80136EE0 is the object array; +4 and +8 point at
// its first and last object, each 0x9C bytes from +0x10. An object's +0 points
// at its id struct (model at +0x14, u16) and +4 is its position. Health
// honeycomb models: 0x614, 0x704 and 0x705 (ScriptHawk's model list).
// The sparkle rate is per second of real time, so it does not depend on the
// frame rate: 4 tries x 3% at 30 frames a second, about 3.6 a second.

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

    constexpr double sparkles_per_second = 3.6;
    constexpr float sparkle_radius = 50.0f;
    constexpr int max_objects = 2048;

    std::mt19937 rng{1234};
    std::chrono::steady_clock::time_point last_tick;
    bool have_last = false;

    bool valid_ptr(uint32_t p) {
        return p >= 0x80000000u && p < 0x80800000u;
    }

    uint32_t read_word(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<uint32_t*>(rdram + (addr - 0x80000000u));
    }

    void write_word(uint8_t* rdram, uint32_t addr, uint32_t value) {
        *reinterpret_cast<uint32_t*>(rdram + (addr - 0x80000000u)) = value;
    }

    uint16_t read_half(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<uint16_t*>(rdram + ((addr ^ 2) - 0x80000000u));
    }

    float read_float(uint8_t* rdram, uint32_t addr) {
        uint32_t bits = read_word(rdram, addr);
        float value;
        std::memcpy(&value, &bits, sizeof(value));
        return value;
    }

    void write_float(uint8_t* rdram, uint32_t addr, float value) {
        uint32_t bits;
        std::memcpy(&bits, &value, sizeof(bits));
        write_word(rdram, addr, bits);
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
    const double chance = sparkles_per_second * dt;

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
    int found = 0;
    for (int i = 0; i < count; i++) {
        const uint32_t obj = array + object_base + (uint32_t)i * object_size;
        const uint32_t id = read_word(rdram, obj + object_id);
        if (!valid_ptr(id) || !is_health_honeycomb(read_half(rdram, id + id_model))) {
            continue;
        }
        found++;
        if (!enabled() || unit(rng) >= chance) {
            continue;
        }
        // A random point within sparkle_radius of the honeycomb.
        float yaw = unit(rng) * 6.2831853f, pitch = unit(rng) * 6.2831853f, r = unit(rng) * sparkle_radius;
        float pos[3] = {
            read_float(rdram, obj + object_pos + 0) + r * std::cos(pitch) * std::sin(yaw),
            read_float(rdram, obj + object_pos + 4) + r * std::sin(pitch),
            read_float(rdram, obj + object_pos + 8) + r * std::cos(pitch) * std::cos(yaw),
        };
        spawn_twinkle(rdram, ctx, pos);
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
