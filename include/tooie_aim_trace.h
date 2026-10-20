#ifndef __TOOIE_AIM_TRACE_H__
#define __TOOIE_AIM_TRACE_H__

#include <string>

#include "recomp.h"
#include "recompui/config.h"

// DEV > Aim trace (src/debug/aim_trace.cpp): lists which game code reads the player's position, for finding
// where common enemies chase and attack from.
namespace tooie::aim_trace {
    inline const std::string option = "aim_trace";
    void add_option(recomp::config::Config& wip);
}

#endif
