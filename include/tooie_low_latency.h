#ifndef __TOOIE_LOW_LATENCY_H__
#define __TOOIE_LOW_LATENCY_H__

#include <string>

#include "librecomp/config.hpp"

// Low Input Latency (src/input/low_latency.cpp, handoff 4.31): a Graphics option that shows each
// frame the game finishes at the very next VI, as a real N64 does, instead of one VI later
// (lib-patches/N64ModernRuntime.patch, ultramodern::set_low_latency).
namespace tooie::low_latency {
    inline const std::string option = "low_input_latency";

    void add_option(recomp::config::Config& graphics);

    // Sends the saved setting to the runtime.
    void apply();
}

#endif
