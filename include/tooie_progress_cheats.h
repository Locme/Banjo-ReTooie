#ifndef __TOOIE_PROGRESS_CHEATS_H__
#define __TOOIE_PROGRESS_CHEATS_H__

#include "recomp.h"

// Cheats that use the game's flags (src/gameplay/progress_cheats.cpp): the Cheato codes and Unlock all moves.
namespace tooie::progress_cheats {
    // Call once per frame from the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram, recomp_context* ctx);

    // Whether the file being played is 100% (every Jiggy, note, Jinjo, Empty Honeycomb, Cheato page,
    // Glowbo and Jamjars move), for Cheats > Beat Hag 1 to show. Any thread.
    bool complete_reached();

    // The game's flag getter and setter (func_800DA298 / func_800DA3B8) on the game thread, for the developer
    // console. ctx is the hook's context; it is left as it was.
    bool get_flag(uint8_t* rdram, recomp_context* ctx, int32_t flag);
    void set_flag(uint8_t* rdram, recomp_context* ctx, int32_t flag, bool value);

    // The game's item counters (eggs, feathers, Glowbos and the rest; item = 0x40 + its place in the item table at
    // 0x8011AF50): func_800D1A04 reads one (999 when it has no limit), func_800D1864 sets one, clamped to its cap
    // by the game (func_800D16CC). The counts are kept XORed with code bytes, so a RAM poke cannot set them.
    int32_t get_item(uint8_t* rdram, recomp_context* ctx, int32_t item);
    void set_item(uint8_t* rdram, recomp_context* ctx, int32_t item, int32_t value);

    // Plays a sound effect on the player with func_8009DE38(player, sound, volume), as Transform anywhere plays its
    // refusal sound. False when there is no player.
    bool play_sound(uint8_t* rdram, recomp_context* ctx, int32_t sound, float volume);
}

#endif
