#ifndef __TOOIE_RACE_WARP_H__
#define __TOOIE_RACE_WARP_H__

#include <cstdint>

#include "recomp.h"

// Race warps (src/gameplay/race_warp.cpp, roadmap 4.81): the Warp tab's last group starts one of Canary
// Mary's four races straight away, whatever the file's progress. A practice run: when the race map is
// left, the file's race state is put back, so nothing is won or lost.
namespace tooie::race_warp {
    constexpr int count = 4;

    // The race's name for the Warp tab.
    const char* name(int race);

    // Starts race 0-3 at the start of the next frame (any thread).
    void request(int race);

    // Call once per frame from the game thread (tooie_warp_tick), before the warp is issued.
    void tick(uint8_t* rdram, recomp_context* ctx);

    // From the game's flag getter: true, with the value to report, while a race warp stands in for
    // the file's progress (Mary freed, which race is next).
    bool override_flag(int32_t flag, bool& value);
}

#endif
