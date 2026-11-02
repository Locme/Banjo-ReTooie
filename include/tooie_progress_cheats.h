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
}

#endif
