#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include "recomp.h"
#include "funcs.h"

#include "tooie_cheats.h"
#include "tooie_debug.h"
#include "tooie_player_cheats.h"

namespace {
    // Player 0's PlayerState pointer lives in a table of words at 0x80135490 (func_800F53D0 reads it).
    constexpr uint32_t player_table = 0x80135490;
    constexpr uint32_t physics_offset = 0xC8;  // PlayerState -> physics block
    constexpr uint32_t vel_y_offset = 0x14;    // physics block -> vertical velocity (f32)
    constexpr uint32_t state_offset = 0x120;   // PlayerState -> state block
    constexpr uint32_t state_current = 0x4;    // state block -> current state id

    constexpr uint16_t button_a = 0x8000;
    constexpr uint16_t button_dd = 0x0400;

    // Player states (the same ids as the XBLA report; checked against the N64 state ids in a headless run).
    constexpr uint32_t state_jump = 5;
    constexpr uint32_t state_flutter = 16;
    constexpr uint32_t state_fall = 47;
    // Moving upwards at this speed (units per second) while D-pad down (Levitate) or A in mid-air
    // (Infinite jumps) is held. A normal jump takes off at about 665.
    constexpr float levitate_speed = 300.0f;
    constexpr float takeoff_speed = 665.0f;
    constexpr float falling_speed = -150.0f;

    uint32_t rd_word(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<uint32_t*>(rdram + (addr - 0x80000000u));
    }

    void write_float(uint8_t* rdram, uint32_t addr, float value) {
        std::memcpy(rdram + (addr - 0x80000000u), &value, sizeof(value));
    }

    bool valid_ptr(uint32_t p) {
        return p >= 0x80000000u && p < 0x80800000u;
    }
}

void tooie::player_cheats::tick(uint8_t* rdram, recomp_context* ctx) {
    static const bool log = std::getenv("TOOIE_PLAYER_LOG") != nullptr;
    static auto last_log = std::chrono::steady_clock::now();

    uint32_t player = rd_word(rdram, player_table);
    if (!valid_ptr(player)) {
        return;
    }
    uint32_t physics = rd_word(rdram, player + physics_offset);
    uint32_t state = rd_word(rdram, player + state_offset);
    if (!valid_ptr(physics) || !valid_ptr(state)) {
        return;
    }
    uint32_t vy_bits = rd_word(rdram, physics + vel_y_offset);
    float vy;
    std::memcpy(&vy, &vy_bits, sizeof(vy));
    uint32_t cur = rd_word(rdram, state + state_current);

    uint16_t buttons = 0;
    float sx = 0, sy = 0;
    tooie::debug::get_n64_input(0, &buttons, &sx, &sy);

    const bool levitate = tooie::cheats::is_on("cheat_levitate");
    const bool infinite_jumps = tooie::cheats::is_on("cheat_infinite_jumps");
    static bool was_a = false;
    const bool a_down = (buttons & button_a) != 0;
    const bool a_pressed = a_down && !was_a;
    was_a = a_down;

    if (levitate && (buttons & button_dd) && vy < levitate_speed) {
        write_float(rdram, physics + vel_y_offset, levitate_speed);
    }

    if (infinite_jumps) {
        // Transformations and swimming/climbing-like states keep their own A button.
        const bool excluded = cur == 35 || cur == 36 || cur == 45 || cur == 46 || cur >= 184 || cur == 0;
        const bool in_air = cur == state_jump || cur == state_flutter || cur == state_fall || vy < falling_speed;
        if (!excluded && in_air) {
            if (a_pressed) {
                // A fresh press jumps again. Entering the jump state sets the take-off speed; from the jump
                // state itself (which cannot be re-entered) set the speed directly.
                if (cur != state_jump) {
                    recomp_context saved = *ctx;
                    ctx->r4 = (int32_t)player; // addresses are sign-extended in the registers
                    ctx->r5 = state_jump;
                    bs_setState(rdram, ctx);
                    *ctx = saved;
                }
                write_float(rdram, physics + vel_y_offset, takeoff_speed);
            } else if (a_down && vy < levitate_speed) {
                write_float(rdram, physics + vel_y_offset, levitate_speed);
            }
        }
    }

    if (log && std::chrono::steady_clock::now() - last_log >= std::chrono::milliseconds(100)) {
        last_log = std::chrono::steady_clock::now();
        uint32_t hv_bits = rd_word(rdram, physics + 0x3C); // target horizontal velocity
        float hv;
        std::memcpy(&hv, &hv_bits, sizeof(hv));
        uint32_t av_bits = rd_word(rdram, physics + 0x38); // horizontal velocity
        float av;
        std::memcpy(&av, &av_bits, sizeof(av));
        uint32_t tr = rd_word(rdram, player + 0x140);
        float pos[3] = {0, 0, 0};
        if (valid_ptr(tr)) {
            for (int k = 0; k < 3; k++) {
                uint32_t b = rd_word(rdram, tr + 4 * k);
                std::memcpy(&pos[k], &b, 4);
            }
        }
        std::printf("[player] state %u vy %.1f buttons %04x hvel %.1f av %.1f pos %.1f %.1f %.1f stick %.2f %.2f\n", cur, vy, buttons, hv, av, pos[0], pos[1], pos[2], sx, sy);
        std::fflush(stdout);
    }
}
