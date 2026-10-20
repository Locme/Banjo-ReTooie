// Damage changes (L, 2026-10-17): Cheats > One-hit enemies, and General > Gameplay > Enemies do double damage.
//
// Player damage: func_800A17A8(player state, delta) adds delta to the current form's health (negative is
// damage; -999 is an instant death, as in a bottomless pit). Every hit from an enemy or hazard goes through
// it, and so do falls: bssplat_entrypoint_0 passes the fall damage from func_800954E8 at 0x80800020. Double
// damage doubles a delta between -998 and -1, leaving falls and instant deaths as they are.
//
// Enemy damage: an enemy's health is a byte at +0x5C + kind in its 0x9C-byte object (99 when full). The
// game's enemy hit handlers take 100 / (hits the attack needs) from it, worked out from the hit table
// (glhittableDll entry 9, which the player's hits read too, so the table is left alone). One-hit enemies
// makes that amount 255 in the three handlers that subtract it: func_80108F08, func_80800294_sucoasterhit
// (watched on an Ugger) and func_80801108_sucoasterfly. Bosses have their own code and are not touched.
//
// Enemy aim (L, 2026-10-20): the game aims in one place: func_8010D12C(player, out, lead, point) returns the
// player's point plus his movement over "lead" seconds. Only Klungo's potion, the lava gargoyle and the
// fantasy eyeball call it (the lead is an actor's +0x58; Klungo's comes from a per-fight table). Every other
// enemy aims at where the player is now. Better and Sharp multiply the lead by 1.5 and 2, so a straight run
// no longer dodges a shot but a change of direction still does.
//
// Take No Damage (Cheato: HONEYKING, game flag 0x53C, L 2026-10-19): the game's own cheat keeps the health
// from dropping, but Banjo still got hurt: knocked back and flung up in the air. func_80099B94 handles the
// player's hit events; each hurt case calls func_800A17A8 with the damage and then picks the hurt state
// (func_80099840 and friends), which it hands to bs_setState in $s2 at its end. State 0 there means "stay as
// you are", so while HONEYKING is on, a hit event that tried to take health and left the player alive sets
// no state. Instant deaths (health 0 after the hit) keep their state, and so does a hit that puts the player
// back in the state he is already in (Dragunda holding him, state 152, re-enters it with each bite).
// Headless test aid: TOOIE_DAMAGE_LOG=1 logs each damaging hit event, its state and whether it was dropped.

#include <algorithm>
#include <atomic>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <random>
#include <unordered_map>
#include <string>
#include <variant>

#include "recomp.h"
#include "funcs.h"
#include "recompui/config.h"
#include "tooie_cheats.h"
#include "tooie_damage.h"
#include "tooie_rdram.h"

namespace {
    // Set while bssplat_entrypoint_0 hands a fall's damage to func_800A17A8.
    bool in_fall = false;

    // Set from func_80099B94's entry until its bs_setState; hit_damaged once it has called func_800A17A8
    // with a negative change.
    bool in_hit = false;
    bool hit_damaged = false;
    int32_t hit_event = 0;

    constexpr int32_t honeyking_flag = 0x53C;

    // Calls a game function on a copy of the hook's context, below the caller's stack frame.
    int32_t call_game(uint8_t* rdram, recomp_context* ctx, void (*func)(uint8_t*, recomp_context*), uint32_t a0) {
        recomp_context saved = *ctx;
        ctx->r29 = (int32_t)((((uint32_t)ctx->r29 - 0x100) & ~0xFu));
        ctx->r4 = (uint64_t)(int64_t)(int32_t)a0;
        func(rdram, ctx);
        const int32_t value = (int32_t)ctx->r2;
        *ctx = saved;
        return value;
    }

    bool double_damage_on() {
        try {
            return std::get<bool>(recompui::config::get_general_config().get_option_value(tooie::damage::double_damage_option));
        } catch (...) {
            return false;
        }
    }
}

bool tooie::damage::no_damage_on(uint8_t* rdram, recomp_context* ctx) {
    return call_game(rdram, ctx, func_800DA298, honeyking_flag) != 0;
}

// func_800A17A8 entry: $a1 is the health change.
extern "C" void tooie_player_health_change(uint8_t* rdram, recomp_context* ctx) {
    const int32_t delta = (int32_t)ctx->r5;
    if (in_hit && delta < 0) {
        hit_damaged = true;
    }
    if (in_fall || delta >= 0 || delta <= -999 || !double_damage_on()) {
        return;
    }
    ctx->r5 = (gpr)(int64_t)(delta * 2);
}

// bssplat_entrypoint_0 around its func_800A17A8 call.
extern "C" void tooie_fall_damage_begin(uint8_t* rdram, recomp_context* ctx) {
    in_fall = true;
}
extern "C" void tooie_fall_damage_end(uint8_t* rdram, recomp_context* ctx) {
    in_fall = false;
}

// An enemy hit handler just before it takes the damage (in register reg) from the enemy's health.
extern "C" void tooie_enemy_hit_damage(uint8_t* rdram, recomp_context* ctx, int reg) {
    if (!tooie::cheats::is_on("cheat_one_hit")) {
        return;
    }
    if (reg == 2) {
        ctx->r2 = 0xFF;
    } else if (reg == 24) {
        ctx->r24 = 0xFF;
    }
}

// func_80099B94 entry: a player hit event is being handled.
extern "C" void tooie_player_hit_begin(uint8_t* rdram, recomp_context* ctx) {
    in_hit = true;
    hit_damaged = false;
    hit_event = call_game(rdram, ctx, func_8009E6EC, (uint32_t)ctx->r4);
}

// func_80099B94 just before bs_setState($s0, $s2).
extern "C" void tooie_player_hit_state(uint8_t* rdram, recomp_context* ctx) {
    static const bool log = std::getenv("TOOIE_DAMAGE_LOG") != nullptr;
    const bool damaged = in_hit && hit_damaged;
    in_hit = false;
    hit_damaged = false;
    if (!damaged || ctx->r18 == 0) {
        return;
    }
    const bool cheat = tooie::damage::no_damage_on(rdram, ctx);
    // func_800A1718(player) is the current form's health; the player's state block (+0x120) holds the current
    // state at +4. A hit that puts the player back in the state he is in (Dragunda's hold, 152) is left alone.
    const int32_t health = call_game(rdram, ctx, func_800A1718, (uint32_t)ctx->r16);
    const int32_t block = MEM_W(ctx->r16, 0x120);
    const uint32_t state = (uint32_t)MEM_W(block, 4);
    const bool drop = cheat && health > 0 && (uint32_t)ctx->r18 != state;
    if (log) {
        std::printf("[damage] hit: event %d in state %u, next state %u, health %d, Take No Damage %s -> %s\n", hit_event,
            state, (uint32_t)ctx->r18, health, cheat ? "on" : "off", drop ? "no reaction" : "state kept");
        std::fflush(stdout);
    }
    if (drop) {
        ctx->r18 = 0;
    }
}

// Enemy aim (second try, L's test of Sharp on Klungo showed no change): scaling the game's own lead did nothing,
// so the aim measures the player's movement itself. aim_tick (once per frame) samples his position and keeps
// a smoothed horizontal velocity. func_8010D12C / func_8010D09C (the two aim-ahead functions) save their out
// pointer ($a1) at entry; at their return the out point is moved on by that velocity times 0.5 s (Better) or
// 1.0 s (Sharp), at most 600 units. Klungo's potion flies 1.2 s, so Sharp puts it just in front of a runner.
namespace {
    float aim_prev[3] = {};
    float aim_vel[2] = {};
    bool aim_have_prev = false;
    uint32_t aim_out = 0;
    bool aim_out_hunt = true;

    // Dynamic (L, 2026-10-20): not every shot is aimed. Each shot rolls on its own: about 3 in 4 are aimed
    // ahead and steered, the others fly as in the game, so the boss cannot be read as always-ahead or never-ahead.
    int aim_hunt_percent() {
        try {
            return (int)std::get<double>(recompui::config::get_general_config().get_option_value(tooie::damage::aim_chance_option));
        } catch (...) {
            return 75;
        }
    }
    bool roll_hunt() {
        static std::mt19937 rng{ std::random_device{}() };
        return std::uniform_int_distribution<int>(0, 99)(rng) < aim_hunt_percent();
    }
    std::unordered_map<uint32_t, bool> potion_hunt;

    float aim_seconds() {
        try {
            switch (static_cast<tooie::damage::Aim>(std::get<uint32_t>(recompui::config::get_general_config().get_option_value(tooie::damage::aim_option)))) {
            case tooie::damage::Aim::Better: return 0.5f;
            case tooie::damage::Aim::Sharp: return 1.0f;
            default: break;
            }
        } catch (...) {
        }
        return 0.0f;
    }
}

// Once per frame (tooie_warp_tick).
void tooie::damage::aim_tick(uint8_t* rdram) {
    const uint32_t player = tooie::rdram::read_word(rdram, 0x80135490u);
    const uint32_t pos_ptr = tooie::rdram::valid_ptr(player) ? tooie::rdram::read_word(rdram, player + 0xE4) : 0;
    const float dt = tooie::rdram::read_float(rdram, 0x8012C760u);
    if (!tooie::rdram::valid_ptr(pos_ptr) || !(dt > 0.0f) || dt > 0.5f) {
        aim_have_prev = false;
        aim_vel[0] = aim_vel[1] = 0.0f;
        return;
    }
    float pos[3];
    for (int k = 0; k < 3; k++) {
        pos[k] = tooie::rdram::read_float(rdram, pos_ptr + 4 * k);
    }
    if (aim_have_prev) {
        const float vx = (pos[0] - aim_prev[0]) / dt;
        const float vz = (pos[2] - aim_prev[2]) / dt;
        // A jump of position (warp, loading) is not movement.
        if (std::fabs(vx) < 3000.0f && std::fabs(vz) < 3000.0f) {
            aim_vel[0] += (vx - aim_vel[0]) * 0.3f;
            aim_vel[1] += (vz - aim_vel[1]) * 0.3f;
        } else {
            aim_vel[0] = aim_vel[1] = 0.0f;
        }
    }
    std::memcpy(aim_prev, pos, sizeof(pos));
    aim_have_prev = true;
}

// func_8010D12C / func_8010D09C entry: $a1 is the out point.
extern "C" void tooie_enemy_aim(uint8_t* rdram, recomp_context* ctx) {
    aim_out = (uint32_t)ctx->r5;
    aim_out_hunt = roll_hunt();
}

// func_8010D12C / func_8010D09C return.
extern "C" void tooie_enemy_aim_end(uint8_t* rdram, recomp_context* ctx) {
    const float seconds = aim_seconds();
    const uint32_t out = aim_out;
    aim_out = 0;
    if (seconds <= 0.0f || !aim_out_hunt || !tooie::rdram::valid_ptr(out)) {
        return;
    }
    float dx = aim_vel[0] * seconds;
    float dz = aim_vel[1] * seconds;
    const float length = std::sqrt(dx * dx + dz * dz);
    if (length > 600.0f) {
        dx *= 600.0f / length;
        dz *= 600.0f / length;
    }
    tooie::rdram::write_float(rdram, out, tooie::rdram::read_float(rdram, out) + dx);
    tooie::rdram::write_float(rdram, out + 8, tooie::rdram::read_float(rdram, out + 8) + dz);
}

// Steering in flight (Enemy aim Better / Sharp). Klungo's potion (func_80800204_chklungophial is its per-frame
// update; $a0 is the potion) flies on a fixed arc: position at +4, velocity at +0x28 (x), +0x2C (y), +0x30 (z),
// gravity pulling +0x2C down, and a state in the top six bits of the halfword at +0x72 (1 = in flight). While in
// flight the horizontal velocity is nudged toward the speed that would reach where the player is heading
// (his position plus his measured movement over the time the potion has left) by then, so a potion only
// misses when he really changes direction. The time left is the horizontal distance over the horizontal speed.
extern "C" void tooie_klungo_potion_steer(uint8_t* rdram, recomp_context* ctx) {
    bool homing = true;
    try {
        homing = std::get<bool>(recompui::config::get_general_config().get_option_value(tooie::damage::homing_option));
    } catch (...) {
    }
    const float seconds = homing ? aim_seconds() : 0.0f;
    const uint32_t potion = (uint32_t)ctx->r4;
    if (seconds <= 0.0f || !aim_have_prev || !tooie::rdram::valid_ptr(potion)) {
        return;
    }
    if ((((uint16_t)tooie::rdram::read_half(rdram, potion + 0x72)) >> 10) != 1) {
        potion_hunt.erase(potion);
        return;
    }
    auto found = potion_hunt.find(potion);
    if (found == potion_hunt.end()) {
        if (potion_hunt.size() > 32) {
            potion_hunt.clear();
        }
        found = potion_hunt.emplace(potion, roll_hunt()).first;
    }
    if (!found->second) {
        return;
    }
    const float dt = tooie::rdram::read_float(rdram, 0x8012C760u);
    if (!(dt > 0.0f) || dt > 0.5f) {
        return;
    }
    const float px = tooie::rdram::read_float(rdram, potion + 4);
    const float pz = tooie::rdram::read_float(rdram, potion + 0xC);
    float vx = tooie::rdram::read_float(rdram, potion + 0x28);
    float vz = tooie::rdram::read_float(rdram, potion + 0x30);
    const float speed = std::sqrt(vx * vx + vz * vz);
    if (speed < 1.0f) {
        return;
    }
    // Time left in flight, from where the potion is now to where the player is now.
    float dx = aim_prev[0] - px;
    float dz = aim_prev[2] - pz;
    const float left = std::max(0.15f, std::sqrt(dx * dx + dz * dz) / speed);
    dx += aim_vel[0] * left;
    dz += aim_vel[1] * left;
    const float want_x = dx / left;
    const float want_z = dz / left;
    // How quickly it corrects: Better about a second to settle, Sharp about a third.
    const float rate = seconds >= 1.0f ? 3.0f : 1.0f;
    const float k = std::min(1.0f, rate * dt);
    vx += (want_x - vx) * k;
    vz += (want_z - vz) * k;
    tooie::rdram::write_float(rdram, potion + 0x28, vx);
    tooie::rdram::write_float(rdram, potion + 0x30, vz);
}
