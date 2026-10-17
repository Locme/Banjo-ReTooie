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

#include <atomic>
#include <string>
#include <variant>

#include "recomp.h"
#include "recompui/config.h"
#include "tooie_cheats.h"
#include "tooie_damage.h"

namespace {
    // Set while bssplat_entrypoint_0 hands a fall's damage to func_800A17A8.
    bool in_fall = false;

    bool double_damage_on() {
        try {
            return std::get<bool>(recompui::config::get_general_config().get_option_value(tooie::damage::double_damage_option));
        } catch (...) {
            return false;
        }
    }
}

// func_800A17A8 entry: $a1 is the health change.
extern "C" void tooie_player_health_change(uint8_t* rdram, recomp_context* ctx) {
    const int32_t delta = (int32_t)ctx->r5;
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
