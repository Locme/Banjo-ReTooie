// Headless explosion test (TOOIE_EXPLODE): sets off the game's own explosions in front of Banjo, so the texture dump
// records their textures (they are drawn only when something blows up; L, 2026-10-22). Each entry is
// <type>@<ms after start>, the type as the game passes to the exploder (_chexploder_entrypoint_3(actor, pos, type);
// Glitter Gulch Mine's entrance grille and Terrydactyland's teeth use 8). The actor is the player's, as those do.
// That exploder only breaks things into pieces (debris and smoke). e<kind>@<ms> spawns the eggs' blast instead
// (actor 0x2B2, cheggsplode; grenade eggs and the other eggs spawn it with their kind, as cheggsplode_entrypoint_1
// does: kind at its data +4, and kinds 4 and 6 a flag at object +0x72 and a radius at data +0xC). a<actor id in
// hex>@<ms> spawns that actor there instead, 150 units up (0x15D is a grenade egg, which falls and blows up).
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

#include "recomp.h"
#include "funcs.h"
#include "tooie_debug.h"
#include "tooie_rdram.h"

namespace tooie::debug {
    void explode_tick(uint8_t* rdram, recomp_context* ctx);
}

namespace {
    struct Request {
        char kind;
        uint32_t type;
        uint32_t at_ms;
    };
    bool read = false;
    std::vector<Request> requests;
    size_t next = 0;
    std::chrono::steady_clock::time_point started;

    constexpr uint32_t player_table = 0x80135490;
    constexpr uint32_t player_pos_ptr = 0xE4;
    constexpr uint32_t player_yaw_ptr = 0xF8;
    constexpr gpr game_state_addr = (int32_t)0x80127630;

    void read_env() {
        read = true;
        started = std::chrono::steady_clock::now();
        const char* v = std::getenv("TOOIE_EXPLODE");
        if (v == nullptr) {
            return;
        }
        std::string list{v};
        size_t pos = 0;
        while (pos < list.size()) {
            const size_t comma = list.find(',', pos);
            unsigned type = 0, at = 0;
            const std::string entry = list.substr(pos, comma - pos);
            const char kind = (!entry.empty() && ((entry[0] == 'e') || (entry[0] == 'a'))) ? entry[0] : 'x';
            if (std::sscanf(entry.c_str() + ((kind == 'x') ? 0 : 1), (kind == 'a') ? "%x@%u" : "%u@%u", &type, &at) == 2) {
                requests.push_back({ kind, type, at });
            }
            pos = (comma == std::string::npos) ? list.size() : comma + 1;
        }
    }

    void explode(uint8_t* rdram, recomp_context* ctx, char kind, uint32_t type) {
        using namespace tooie::rdram;
        const uint32_t player = read_word(rdram, player_table);
        if (!valid_ptr(player)) {
            return;
        }
        const uint32_t pos_ptr = read_word(rdram, player + player_pos_ptr);
        const uint32_t yaw_ptr = read_word(rdram, player + player_yaw_ptr);
        if (!valid_ptr(pos_ptr) || !valid_ptr(yaw_ptr)) {
            return;
        }
        const float rad = read_float(rdram, yaw_ptr) * 3.14159265f / 180.0f;
        recomp_context saved = *ctx;
        const uint32_t vec = ((uint32_t)ctx->r29 - 0x100) & ~0xFu;
        write_float(rdram, vec + 0, read_float(rdram, pos_ptr) + std::sin(rad) * 300.0f);
        write_float(rdram, vec + 4, read_float(rdram, pos_ptr + 4) + 60.0f);
        write_float(rdram, vec + 8, read_float(rdram, pos_ptr + 8) + std::cos(rad) * 300.0f);
        ctx->r29 = (int32_t)(vec - 0x40);
        if (kind == 'a') {
            write_float(rdram, vec + 4, read_float(rdram, pos_ptr + 4) + 150.0f);
            ctx->r4 = (int32_t)type;
            ctx->r5 = (int32_t)vec;
            ctx->r6 = 0;
            func_80108474(rdram, ctx);
            const uint32_t object = (uint32_t)ctx->r2;
            *ctx = saved;
            printf("[explode] actor %X (object %08X)\n", type, object);
            fflush(stdout);
            return;
        }
        if (kind == 'e') {
            constexpr uint32_t egg_blast_actor = 0x2B2;
            ctx->r4 = egg_blast_actor;
            ctx->r5 = (int32_t)vec;
            ctx->r6 = 0;
            func_80108474(rdram, ctx);
            const uint32_t object = (uint32_t)ctx->r2;
            if (valid_ptr(object)) {
                ctx->r4 = (int32_t)object;
                ctx->r5 = 0;
                func_80100094(rdram, ctx);
                const uint32_t data = (uint32_t)ctx->r2;
                if (valid_ptr(data)) {
                    write_word(rdram, data + 0, 0);
                    write_word(rdram, data + 4, type << 16);
                    if ((type == 4) || (type == 6)) {
                        const uint8_t flags = MEM_BU(0x72, (gpr)(int32_t)object);
                        MEM_B(0x72, (gpr)(int32_t)object) = (int8_t)((flags & 0x03) | ((type == 4) ? 0x8 : 0xC));
                        write_float(rdram, data + 0xC, (type == 4) ? 250.0f : 350.0f);
                    }
                }
            }
            *ctx = saved;
            printf("[explode] egg blast kind %u (object %08X)\n", type, object);
            fflush(stdout);
            return;
        }
        // The player's actor, as the grille and the teeth pass (func_80106790(func_80101080())).
        func_80101080(rdram, ctx);
        ctx->r4 = ctx->r2;
        func_80106790(rdram, ctx);
        const uint32_t actor = (uint32_t)ctx->r2;
        if (valid_ptr(actor)) {
            ctx->r4 = (int32_t)actor;
            ctx->r5 = (int32_t)vec;
            ctx->r6 = (int32_t)type;
            _chexploder_entrypoint_3(rdram, ctx);
        }
        *ctx = saved;
        printf("[explode] type %u (actor %08X)\n", type, actor);
        fflush(stdout);
    }
}

void tooie::debug::explode_tick(uint8_t* rdram, recomp_context* ctx) {
    if (!read) {
        read_env();
    }
    if ((next >= requests.size()) || !tooie::debug::can_warp() || (MEM_B(0x12, game_state_addr) != 0)) {
        return;
    }
    const auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - started).count();
    if (elapsed >= requests[next].at_ms) {
        explode(rdram, ctx, requests[next].kind, requests[next].type);
        next++;
    }
}
