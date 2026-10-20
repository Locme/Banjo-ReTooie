#ifndef __TOOIE_MEMORY_GUARD_H__
#define __TOOIE_MEMORY_GUARD_H__

#include <cstdint>
#include <string>

#include "librecomp/config.hpp"

// Pass over crashes (src/game/memory_guard.cpp), DEV tab, on by default: game code that reads or
// writes an address with no memory behind it (a null pointer, mostly) carries on, reading 0,
// instead of closing the game, and each place it happens is logged as a MAJOR line.
namespace tooie::memory_guard {
    inline const std::string option = "pass_over_crashes";
    void add_option(recomp::config::Config& config);
    // From the game thread each frame (tooie_warp_tick): installs the guard the first time, and
    // follows the option.
    void tick(uint8_t* rdram);
    // True when the option is on (the texture sweep's restart after a crash or hang follows it too).
    bool enabled();
    // Adds a line to logs/PassedOver.txt (with the time in front) and console.log, and shows a
    // notice. Safe from the crash handler and the watchdog once the game has run a frame.
    void log_passed_over(const char* line);
    // Forgets the places seen so far, so the next hit at each is logged in full again (headless
    // sweeps that try one thing after another, such as the enemy spawner's TOOIE_ENEMY_SWEEP).
    void forget_sites();
}

#endif
