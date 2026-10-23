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
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <random>
#include <unordered_map>
#include <string>
#include <variant>
#include <vector>

#include "recomp.h"
#include "funcs.h"
#include "recompui/config.h"
#include "tooie_cheats.h"
#include "tooie_damage.h"
#include "tooie_rdram.h"
#include "tooie_game_frame_rate.h"

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
    // Noclip takes no damage either (L, 2026-10-21).
    return tooie::cheats::is_on("cheat_noclip") || call_game(rdram, ctx, func_800DA298, honeyking_flag) != 0;
}

// func_800A17A8 entry: $a1 is the health change.
extern "C" void tooie_player_health_change(uint8_t* rdram, recomp_context* ctx) {
    const int32_t delta = (int32_t)ctx->r5;
    if (in_hit && delta < 0) {
        hit_damaged = true;
    }
    if (delta < 0 && tooie::cheats::is_on("cheat_noclip")) {
        ctx->r5 = 0;
        return;
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

namespace {
    // Hit timing log (L, 2026-10-20: enemies sometimes take damage 1-2 s after the hit, at 175 FPS running
    // at 30-77). Always on and small: each player state change and each enemy hit, with game and real time,
    // so a console.log from a PC where it happens shows whether the hit itself came late. Not reproduced
    // headless (claw swipes on Uggers landed as soon as they were in reach at every frame rate tried).
    const auto hit_log_start = std::chrono::steady_clock::now();
    void hit_log_line(const char* what, int value) {
        const double real = std::chrono::duration<double>(std::chrono::steady_clock::now() - hit_log_start).count();
        std::printf("[hits] game %.3f s, real %.3f s: %s %d\n", tooie::game_frame_rate::game_seconds(), real, what, value);
        std::fflush(stdout);
    }
}

// An enemy hit handler just before it takes the damage (in register reg) from the enemy's health.
extern "C" void tooie_enemy_hit_damage(uint8_t* rdram, recomp_context* ctx, int reg) {
    hit_log_line("enemy hit, damage", (int)(reg == 2 ? ctx->r2 : ctx->r24));
    {
        // Which enemy: func_80800294_sucoasterhit keeps the actor (its $a0) at $sp + 0xA0; the other two handlers
        // keep it elsewhere, so a word there is only taken for an actor when it points at a game object whose
        // entry (+0x10) lies in the syscall stub area.
        const uint32_t actor = tooie::rdram::read_word(rdram, (uint32_t)ctx->r29 + 0xA0);
        const uint32_t entry = tooie::rdram::valid_ptr(actor) ? tooie::rdram::read_word(rdram, actor + 0x10) : 0;
        const uint32_t marker = tooie::rdram::valid_ptr(actor) ? tooie::rdram::read_word(rdram, actor) : 0;
        if (entry >= 0x80080000u && entry < 0x80090000u && tooie::rdram::valid_ptr(marker)) {
            std::printf("[hits] hit actor entry 0x%08X model 0x%04X\n", entry, (unsigned)(uint16_t)tooie::rdram::read_half(rdram, marker + 0x14));
            std::fflush(stdout);
        }
    }
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
    uint32_t aim_frame = 0; // counts aim_tick calls (game frames)
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
    aim_frame++;
    const uint32_t player = tooie::rdram::read_word(rdram, 0x80135490u);
    {
        // The player's state (state block +0x120, current state at +4) for the hit timing log.
        static uint32_t last_state = 0;
        const uint32_t block = tooie::rdram::valid_ptr(player) ? tooie::rdram::read_word(rdram, player + 0x120) : 0;
        const uint32_t state = tooie::rdram::valid_ptr(block) ? tooie::rdram::read_word(rdram, block + 4) : 0;
        if (state != last_state && state != 0) {
            hit_log_line("player state", (int)state);
        }
        last_state = state;
    }
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
// Curated enemies (L, 2026-10-23): the two enemy toggles only touch the enemies on L's list, not every actor
// built on the shared sucoaster helper (many of those are objects that cannot be killed). An object is on the
// list when its actor entry (+0x10, the pointer _gemarkersDll_entrypoint_0 returns for the actor id, as the
// enemy spawner's guard uses) matches one of these ids. Diggit, Flatso and Globble are matched by model instead
// (their actor ids are not known); Bargasaurus is missing.
namespace {
    constexpr uint16_t curated_ids[] = {
        0x440, // Boltoid
        0x150, // Billy Bob
        0x327, // Jippo Jim
        0x3C3, // Guvnor
        0x133, 0x134, // Gruntydactyl
        0x462, // Hothead
        0x3C9, // Keelhaul
        0x19C, // Minjo
        0x112, // Moggy warrior
        0x43E, // Nutta
        0x46B, // Pansie
        0x426, // S'Hard
        0x39A, // Soarasaur
        0x131, // Ugger
        0x43F, // Washup
        0x213, // Zubba
    };

    bool curated_actor(uint8_t* rdram, recomp_context* ctx, uint32_t actor) {
        static std::unordered_map<uint32_t, bool> cache; // entry pointer -> on the list
        static std::vector<uint32_t> entries;
        if (entries.empty()) {
            const recomp_context saved = *ctx;
            for (const uint16_t id : curated_ids) {
                ctx->r29 = saved.r29 - 0x200;
                ctx->r4 = id;
                _gemarkersDll_entrypoint_0(rdram, ctx);
                entries.push_back((uint32_t)ctx->r2);
            }
            *ctx = saved;
        }
        const uint32_t entry = tooie::rdram::read_word(rdram, actor + 0x10);
        if (entry != 0 && std::find(entries.begin(), entries.end(), entry) != entries.end()) {
            return true;
        }
        // Enemies whose actor id is not known: matched by model (the object's marker +0x14, ScriptHawk's
        // model list): Diggit, Flatso (green, blue, pink) and Globble. 0x662 is listed there as "Globble (Fly,
        // Bovina)", so Bovina may match too.
        const uint32_t marker = tooie::rdram::read_word(rdram, actor);
        if (!tooie::rdram::valid_ptr(marker)) {
            return false;
        }
        const uint16_t model = (uint16_t)tooie::rdram::read_half(rdram, marker + 0x14);
        return model == 0x66F || model == 0x818 || model == 0x819 || model == 0x81A || model == 0x662;
    }
}

// Eggs in flight (L, 2026-10-23): the marker +0x14 model ids of the egg actors (blue 0x9D7, fire 0x9C1, ice 0x9C0,
// grenade 0x9C2, clockwork 0x9C4, golden 0x9C3, proximity 0x9C5), found by walking the object array once a frame and
// measuring each egg's velocity from its last position (eggs are keyed by their marker pointer).
namespace {
    struct Egg {
        float pos[2];
        float vel[2];
    };
    std::vector<Egg> eggs;
    uint32_t eggs_frame = ~0u;

    void scan_eggs(uint8_t* rdram, float dt) {
        using namespace tooie::rdram;
        eggs.clear();
        static std::unordered_map<uint32_t, std::pair<float, float>> last; // marker -> position last frame
        std::unordered_map<uint32_t, std::pair<float, float>> now;
        const uint32_t array = read_word(rdram, 0x80136EE0u);
        if (!valid_ptr(array)) {
            last.clear();
            return;
        }
        const uint32_t first = read_word(rdram, array + 4);
        const uint32_t last_obj = read_word(rdram, array + 8);
        if (!valid_ptr(first) || !valid_ptr(last_obj) || last_obj < first || (last_obj - first) / 0x9C >= 2048) {
            return;
        }
        const int count = (int)((last_obj - first) / 0x9C) + 1;
        for (int i = 0; i < count; i++) {
            const uint32_t object = array + 0x10 + (uint32_t)i * 0x9C;
            const uint32_t marker = read_word(rdram, object);
            if (!valid_ptr(marker)) {
                continue;
            }
            const uint16_t model = (uint16_t)read_half(rdram, marker + 0x14);
            if (model != 0x9D7 && model != 0x9C1 && model != 0x9C0 && model != 0x9C2 && model != 0x9C4
                && model != 0x9C3 && model != 0x9C5) {
                continue;
            }
            const float x = read_float(rdram, object + 4);
            const float z = read_float(rdram, object + 0xC);
            now[marker] = {x, z};
            const auto it = last.find(marker);
            if (it != last.end() && dt > 0.0f) {
                const float vx = (x - it->second.first) / dt;
                const float vz = (z - it->second.second) / dt;
                if (std::hypot(vx, vz) < 5000.0f) {
                    eggs.push_back({{x, z}, {vx, vz}});
                }
            }
        }
        last.swap(now);
    }
}

// Dynamic positioning (L, 2026-10-23): hooked at the entry of sucoaster_entrypoint_2, the per-frame update of
// the shared-helper enemies ($a0 is the actor; position floats at +4, +8, +0xC), for the curated enemies only. That
// helper has no movement code of its own, so this adds a sideways step on top of whatever the enemy's own
// movement does: an enemy that is moving (it displaced itself since the last frame) and is between 150 and
// 800 units from Banjo slides perpendicular to the line between them at 55 units a second, the side picked
// per enemy and swapped every 2 to 4 seconds. While Banjo is rolling, jumping, pecking or whacking and the enemy is within 350 to 500
// units, the step is 350 units a second, to the side of his roll line it is already on, so it tries not to be
// rolled on. Walls and floors are not checked; the step is a few units a frame.
extern "C" void tooie_enemy_strafe(uint8_t* rdram, recomp_context* ctx) {
    static bool on = false;
    static auto last_check = std::chrono::steady_clock::now() - std::chrono::seconds(2);
    const auto now = std::chrono::steady_clock::now();
    if (now - last_check > std::chrono::seconds(1)) {
        last_check = now;
        try {
            on = std::get<bool>(recompui::config::get_general_config().get_option_value(tooie::damage::strafe_option));
        } catch (...) {
            on = false;
        }
    }
    const uint32_t actor = (uint32_t)ctx->r4;
    if (!on || !aim_have_prev || !tooie::rdram::valid_ptr(actor) || !curated_actor(rdram, ctx, actor)) {
        return;
    }
    const float dt = tooie::rdram::read_float(rdram, 0x8012C760u);
    if (!(dt > 0.0f) || dt > 0.1f) {
        return;
    }
    struct Track {
        float pos[2] = {};
        bool have = false;
        float side = 1.0f;
        float swap_in = 0.0f;
        float moving_for = 0.0f; // seconds since it last moved by itself, counted down from 0.4
        float vel = 0.0f;        // the sideways speed now, eased toward its target
        float roll_side = 0.0f;  // the side picked for the roll in progress, 0 when none
        float heading[2] = {};   // its own measured velocity, eased
        float evel[2] = {};      // the dodge velocity away from an egg coming at it, eased
    };
    static std::unordered_map<uint32_t, Track> tracks;
    if (tracks.size() > 512) {
        tracks.clear();
    }
    Track& t = tracks[actor];
    const float x = tooie::rdram::read_float(rdram, actor + 4);
    const float z = tooie::rdram::read_float(rdram, actor + 0xC);
    const float moved = t.have ? std::hypot(x - t.pos[0], z - t.pos[1]) : 0.0f;
    if (t.have && moved > 400.0f) {
        t.vel = 0.0f; // teleported or respawned
    }
    // It counts as moving for 0.4 s after its last step of its own, so a pause between hops does not stop the slide.
    if (t.have && moved > 0.4f && moved < 400.0f) {
        t.moving_for = 0.4f;
    } else {
        t.moving_for = std::max(0.0f, t.moving_for - dt);
    }
    if (t.have && moved < 400.0f) {
        const float k = std::min(1.0f, dt * 8.0f);
        t.heading[0] += ((x - t.pos[0]) / dt - t.heading[0]) * k;
        t.heading[1] += ((z - t.pos[1]) / dt - t.heading[1]) * k;
    } else {
        t.heading[0] = t.heading[1] = 0.0f;
    }
    t.pos[0] = x;
    t.pos[1] = z;
    t.have = true;
    t.swap_in -= dt;
    if (t.swap_in <= 0.0f) {
        t.swap_in = 2.0f + (float)((actor >> 4) % 21) / 10.0f;
        t.side = t.side < 0.0f ? 1.0f : -1.0f;
    }
    const float dx = aim_prev[0] - x;
    const float dz = aim_prev[2] - z;
    const float dist = std::hypot(dx, dz);
    const uint32_t player = tooie::rdram::read_word(rdram, 0x80135490u);
    const uint32_t block = tooie::rdram::valid_ptr(player) ? tooie::rdram::read_word(rdram, player + 0x120) : 0;
    const uint32_t state = tooie::rdram::valid_ptr(block) ? tooie::rdram::read_word(rdram, block + 4) : 0;
    // Banjo's attacks that an enemy should step out of (ScriptHawk's movement state names): the roll (49) from up
    // to 500 units, the jump (5, Kazooie alone 0xBD), the peck / claw swipe (6) and Kazooie's wing whack
    // (0xC2, 0xC4) from up to 350.
    const bool rolling = (state == 49 && dist < 500.0f)
        || ((state == 5 || state == 6 || state == 0xBD || state == 0xC2 || state == 0xC4) && dist < 350.0f);
    if (!rolling) {
        t.roll_side = 0.0f;
    }
    // The target sideways speed: 0 outside 150 to 800 units (fading in over 100 units at each end) or when it is
    // not moving, 55 units a second, or 350 while Banjo rolls, on the side picked when the roll began.
    float target = 0.0f;
    if (t.moving_for > 0.0f && dist > 1.0f) {
        const float fade = std::clamp(std::min(dist - 150.0f, 800.0f - dist) / 100.0f, 0.0f, 1.0f);
        float side = t.side;
        // A run, not a shuffle: the slide is 0.6 of the enemy's own measured speed (at least 55, at most 220
        // units a second), so the animation it already plays for its own speed fits the way it is going.
        float speed = std::clamp(0.6f * std::hypot(t.heading[0], t.heading[1]), 55.0f, 220.0f);
        if (rolling) {
            speed = 350.0f;
            if (t.roll_side == 0.0f) {
                const float vlen = std::hypot(aim_vel[0], aim_vel[1]);
                if (vlen > 1.0f) {
                    // The side of his roll line the enemy is already on.
                    const float cross = aim_vel[0] * (z - aim_prev[2]) - aim_vel[1] * (x - aim_prev[0]);
                    t.roll_side = cross >= 0.0f ? 1.0f : -1.0f;
                }
            }
            if (t.roll_side != 0.0f) {
                side = t.roll_side;
            }
        }
        target = side * speed * fade;
    }
    // Ease toward the target in about a sixth of a second instead of jumping, so starts, stops and swaps are smooth.
    t.vel += (target - t.vel) * std::min(1.0f, dt * 6.0f);
    // An egg coming at it: step out of the egg's line, to the side the enemy is already on, at 380 units a second.
    if (eggs_frame != aim_frame) {
        eggs_frame = aim_frame;
        scan_eggs(rdram, dt);
    }
    float edx = 0.0f, edz = 0.0f;
    for (const Egg& egg : eggs) {
        const float speed2 = egg.vel[0] * egg.vel[0] + egg.vel[1] * egg.vel[1];
        if (speed2 < 100.0f * 100.0f) {
            continue;
        }
        const float rx = x - egg.pos[0], rz = z - egg.pos[1];
        const float along = (rx * egg.vel[0] + rz * egg.vel[1]) / speed2; // seconds until it is level with the enemy
        if (along < 0.0f || along > 1.5f) {
            continue;
        }
        const float miss_x = rx - egg.vel[0] * along, miss_z = rz - egg.vel[1] * along; // enemy from the egg's closest point
        if (std::hypot(miss_x, miss_z) > 150.0f) {
            continue;
        }
        const float speed = std::sqrt(speed2);
        const float nx = egg.vel[1] / speed, nz = -egg.vel[0] / speed; // perpendicular to the egg's path
        const float sign = (miss_x * nx + miss_z * nz) >= 0.0f ? 1.0f : -1.0f;
        edx = nx * sign * 380.0f;
        edz = nz * sign * 380.0f;
        break;
    }
    const float ek = std::min(1.0f, dt * 10.0f);
    t.evel[0] += (edx - t.evel[0]) * ek;
    t.evel[1] += (edz - t.evel[1]) * ek;
    const bool sliding = std::fabs(t.vel) >= 0.5f && dist >= 1.0f;
    const bool dodging = std::hypot(t.evel[0], t.evel[1]) >= 0.5f;
    if (!sliding && !dodging) {
        return;
    }
    // The slide is perpendicular to the enemy-to-Banjo line: (dz, -dx) / dist.
    const float sx = sliding ? dz * t.vel / dist : 0.0f;
    const float sz = sliding ? -dx * t.vel / dist : 0.0f;
    tooie::rdram::write_float(rdram, actor + 4, x + (sx + t.evel[0]) * dt);
    tooie::rdram::write_float(rdram, actor + 0xC, z + (sz + t.evel[1]) * dt);
    // Face the way it is actually going (its own movement plus the slide and dodge): the game's yaw is
    // rotation[1] at +0x48, in degrees, turned toward atan2(dx, dz) as func_800F1DF4 measures it. Turn toward it
    // over about an eighth of a second, the short way round; below 20 units a second it has no heading and keeps
    // its facing.
    const float hx = t.heading[0] + sx + t.evel[0];
    const float hz = t.heading[1] + sz + t.evel[1];
    if (std::hypot(hx, hz) > 20.0f) {
        float yaw = tooie::rdram::read_float(rdram, actor + 0x48);
        const float want = std::atan2(hx, hz) * 57.29578f;
        float diff = std::fmod(want - yaw, 360.0f);
        if (diff > 180.0f) {
            diff -= 360.0f;
        } else if (diff < -180.0f) {
            diff += 360.0f;
        }
        yaw += diff * std::min(1.0f, dt * 12.0f);
        tooie::rdram::write_float(rdram, actor + 0x48, std::fmod(yaw + 360.0f, 360.0f));
    }
}

// Faster enemy attacks (L, 2026-10-23): the shared enemy helper sucoaster_entrypoint_14 (used by every enemy
// the Aim sweep saw reading the player through func_8080202C_sucoaster) rolls a random 5 to 8 second wait
// (func_800DC178(5.0, 8.0), func_800D9058 turns the seconds into the byte) and stores it at data +0x12, which
// sucoaster_entrypoint_2 counts down. With the option on the stored wait is halved (hooked before both stores,
// $v0 holds the byte).
extern "C" void tooie_enemy_attack_timer(uint8_t* rdram, recomp_context* ctx) {
    bool on = false;
    try {
        on = std::get<bool>(recompui::config::get_general_config().get_option_value(tooie::damage::faster_attacks_option));
    } catch (...) {
    }
    if (on && curated_actor(rdram, ctx, (uint32_t)ctx->r16)) { // $s0 is the actor
        ctx->r2 = (int32_t)(((uint32_t)ctx->r2 & 0xFFu) / 2u);
    }
}

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
