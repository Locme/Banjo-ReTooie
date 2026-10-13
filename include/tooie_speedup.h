#ifndef __TOOIE_SPEEDUP_H__
#define __TOOIE_SPEEDUP_H__

#include <string>

// Speed-up key (src/game/speedup.cpp): hold F2 to run the game at 2x/3x/4x. It scales the
// N64ModernRuntime game clock (ultramodern::set_speed_multiplier), so the VI, timers and audio
// all stay in step. With the toggle option on, F2 switches it on and off instead.
namespace tooie::speedup {
    inline const std::string factor_option = "speed_up_factor";
    inline const std::string toggle_option = "speed_up_toggle";

    // Starts the key-watching thread (safe to call more than once).
    void start();
}

#endif
