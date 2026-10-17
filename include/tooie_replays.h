#ifndef __TOOIE_REPLAYS_H__
#define __TOOIE_REPLAYS_H__

#include <string>

#include "recomp.h"

namespace recomp::config {
    class Config;
}

// Cheats > Replays (src/gameplay/replays.cpp): Canary Mary's races and the game's boss, minigame and
// cutscene replays, each a drop-down that starts the pick at once.
namespace tooie::replays {
    inline const std::string tab_id = "cheats";

    // Adds the drop-downs to the Cheats tab, shown while master_option is on.
    void add_options(recomp::config::Config& cheats, const std::string& master_option);

    // Puts every drop-down back to "Pick one" and drops a waiting pick.
    void reset(recomp::config::Config& cheats);

    // Call once per frame from the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram, recomp_context* ctx);
}

#endif
