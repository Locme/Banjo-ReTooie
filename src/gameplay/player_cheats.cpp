#include <algorithm>
#include <atomic>
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
    constexpr uint16_t button_b = 0x4000;
    constexpr uint16_t button_d_up = 0x0800;
    constexpr uint16_t button_z = 0x2000;
    constexpr uint16_t button_r = 0x0010;

    // The player's form byte (ScriptHawk's character_state, US address): 1 Banjo-Kazooie, 6 the bee.
    constexpr uint32_t form_addr = 0x80136F63;
    constexpr uint8_t form_banjo_kazooie = 1;
    constexpr uint8_t form_bee = 6;

    // Player states (the same ids as the XBLA report; checked against the N64 state ids in a headless run).
    constexpr uint32_t state_jump = 5;
    constexpr uint32_t state_flutter = 16;
    constexpr uint32_t state_fall = 47;
    // Fly anywhere (handoff 4.74). Banjo-Kazooie: take-off 35 leads to flying 36. The bee: the flight pad
    // launch 0x8B leads to flying 0x8C, and 0x88 is the bee falling.
    constexpr uint32_t state_takeoff = 35;
    constexpr uint32_t state_flying = 36;
    constexpr uint32_t state_bee_launch = 0x8B;
    constexpr uint32_t state_bee_flying = 0x8C;
    constexpr uint32_t state_bee_fall = 0x88;
    // Moving upwards at this speed (units per second) while A is held in mid-air (Infinite Jumps
    // (Levitate)). A normal jump takes off at about 665.
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

    uint8_t rd_byte(uint8_t* rdram, uint32_t addr) {
        return rdram[(addr - 0x80000000u) ^ 3u];
    }

    void set_state(uint8_t* rdram, recomp_context* ctx, uint32_t player, uint32_t id) {
        recomp_context saved = *ctx;
        ctx->r4 = (int32_t)player; // addresses are sign-extended in the registers
        ctx->r5 = id;
        bs_setState(rdram, ctx);
        *ctx = saved;
    }

    // States Banjo-Kazooie may take off from: standing, walking, jumping, crouching, the Feathery Flap,
    // the Flap Flip, landing and falling. Swimming, climbing, talking and the moves with their own
    // animations are left alone.
    bool can_take_off(uint32_t s) {
        return (s >= 1 && s <= 5) || s == 7 || s == 0x10 || s == 0x12 || s == 0x20 || s == state_fall;
    }

    // The bee on the ground or in the air (idle, walking, jumping, falling).
    bool bee_can_take_off(uint32_t s) {
        return s >= 0x85 && s <= 0x88;
    }

    // Set by the game thread every frame: whether the player is flying with Fly anywhere on, so the input
    // hook can keep B (Beak Bomb) from the game and stop the flight instead.
    std::atomic<bool> flying_with_cheat{false};

    // Noclip (handoff 4.75). The physics block holds the position (+4) and velocity (+0x10); player+0xE4
    // points at a second copy of the position. Each frame the player is moved from the cheat's own
    // position by the velocity the game wants (from the stick), and both copies are written, so the game's
    // collision pushes are undone next frame and walls, floors and ceilings are passed through. Z (LT on
    // a pad) sinks and R (RT) rises; both are kept from the game while noclip is on.
    constexpr uint32_t pos_ptr_offset = 0xE4;
    constexpr uint32_t pos_offset = 0x4;
    constexpr uint32_t vel_x_offset = 0x10;
    constexpr uint32_t vel_z_offset = 0x18;
    constexpr float noclip_vertical_speed = 600.0f;
    // States where the game moves the player itself: door walk-ins and loading zones (0x98), and the
    // locked states for signposts, talking and cutscenes.
    bool noclip_paused_state(uint32_t s) {
        return s == 0 || s == 0x98 || s == 0x97 || s == 0x93 || s == 0x92 || s == 0x5D || s == 0x75 || s == 0x9A;
    }
    std::atomic<bool> noclip_on{false};
    // Player 1's buttons before Z and R were hidden, for noclip's up and down.
    std::atomic<uint16_t> unhidden_buttons{0};
    std::atomic<bool> stop_requested{false};
    uint16_t last_input_buttons = 0;
    // B stays hidden from the game until it is let go after stopping, or the fall would turn it into a Rat-a-tat Rap.
    bool hide_b = false;
}

void tooie::player_cheats::apply_input(uint16_t* buttons) {
    const uint16_t now = *buttons;
    const bool b_pressed = (now & button_b) && !(last_input_buttons & button_b);
    last_input_buttons = now;
    if (!(now & button_b)) {
        hide_b = false;
    }
    if (flying_with_cheat) {
        if (b_pressed) {
            stop_requested = true;
        }
        hide_b = hide_b || (now & button_b);
    }
    if (hide_b) {
        *buttons &= (uint16_t)~button_b;
    }
    unhidden_buttons = *buttons;
    if (noclip_on) {
        *buttons &= (uint16_t)~(button_z | button_r);
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

    const bool infinite_jumps = tooie::cheats::is_on("cheat_infinite_jumps");
    static bool was_a = false;
    const bool a_down = (buttons & button_a) != 0;
    const bool a_pressed = a_down && !was_a;
    was_a = a_down;

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

    const bool fly_anywhere = tooie::cheats::is_on("cheat_fly_anywhere");
    static bool was_d_up = false;
    const bool d_up_pressed = (buttons & button_d_up) && !was_d_up;
    was_d_up = (buttons & button_d_up) != 0;
    const uint8_t form = rd_byte(rdram, form_addr);
    const bool flying = cur == state_flying || cur == state_bee_flying;
    flying_with_cheat = fly_anywhere && flying;
    if (fly_anywhere) {
        if (stop_requested.exchange(false) && flying) {
            set_state(rdram, ctx, player, cur == state_flying ? state_fall : state_bee_fall);
        } else if (d_up_pressed) {
            if (form == form_banjo_kazooie && can_take_off(cur)) {
                set_state(rdram, ctx, player, state_takeoff);
            } else if (form == form_bee && bee_can_take_off(cur)) {
                set_state(rdram, ctx, player, state_bee_launch);
            }
        }
    } else {
        stop_requested = false;
    }

    // Noclip.
    {
        static bool anchored = false;
        static float anchor[3];
        static uint16_t anchor_map = 0;
        static uint8_t anchor_form = 0;
        static int settle = 0;
        static auto last = std::chrono::steady_clock::now();
        const auto now = std::chrono::steady_clock::now();
        const float dt = std::min(std::chrono::duration<float>(now - last).count(), 0.1f);
        last = now;

        const bool on = tooie::cheats::is_on("cheat_noclip");
        noclip_on = on;
        const uint16_t map = *reinterpret_cast<uint16_t*>(rdram + ((0x80132DC2u ^ 2u) - 0x80000000u));
        const uint32_t pos2 = rd_word(rdram, player + pos_ptr_offset);
        if (!on || !valid_ptr(pos2) || map != anchor_map || form != anchor_form || noclip_paused_state(cur)) {
            // The first updates of an area put the player back where they were before it loaded, so wait.
            anchored = false;
            anchor_map = map;
            anchor_form = form;
            settle = 10;
        } else if (settle > 0) {
            settle--;
        } else {
            const uint16_t raw = unhidden_buttons;
            if (!anchored) {
                for (int k = 0; k < 3; k++) {
                    uint32_t b = rd_word(rdram, physics + pos_offset + 4 * k);
                    std::memcpy(&anchor[k], &b, 4);
                }
                anchored = true;
            }
            uint32_t vx_bits = rd_word(rdram, physics + vel_x_offset), vz_bits = rd_word(rdram, physics + vel_z_offset);
            float vx, vz;
            std::memcpy(&vx, &vx_bits, 4);
            std::memcpy(&vz, &vz_bits, 4);
            anchor[0] += vx * dt;
            anchor[2] += vz * dt;
            const float rise = ((raw & button_r) ? 1.0f : 0.0f) - ((raw & button_z) ? 1.0f : 0.0f);
            anchor[1] += rise * noclip_vertical_speed * dt;
            for (int k = 0; k < 3; k++) {
                write_float(rdram, physics + pos_offset + 4 * k, anchor[k]);
                write_float(rdram, pos2 + 4 * k, anchor[k]);
            }
            write_float(rdram, physics + vel_y_offset, 0.0f);
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
        float pos[3] = {0, 0, 0};
        for (int k = 0; k < 3; k++) {
            uint32_t b = rd_word(rdram, physics + 4 + 4 * k);
            std::memcpy(&pos[k], &b, 4);
        }
        std::printf("[player] form %u state %u vy %.1f buttons %04x hvel %.1f av %.1f pos %.1f %.1f %.1f stick %.2f %.2f\n", form, cur, vy, buttons, hv, av, pos[0], pos[1], pos[2], sx, sy);
        std::fflush(stdout);
    }
}
