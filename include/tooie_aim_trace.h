#ifndef __TOOIE_AIM_TRACE_H__
#define __TOOIE_AIM_TRACE_H__

#include <map>
#include <string>

#include "recomp.h"
#include "recompui/config.h"

// DEV > Aim trace (src/debug/aim_trace.cpp): lists which game code reads the player's position, for finding
// where common enemies chase and attack from.
namespace tooie::aim_trace {
    inline const std::string option = "aim_trace";
    void add_option(recomp::config::Config& wip);

    // DEV > Aim sweep: the enemy spawner's sweep (src/gameplay/enemy_spawner.cpp) spawns each enemy next to
    // Banjo in turn and uses these to count the player-position readers that run while it is alive.
    inline const std::string sweep_option = "aim_sweep";
    bool sweep_requested();
    void sweep_finished();
    void capture_begin();
    std::map<std::string, uint64_t> capture_end();
}

#endif
