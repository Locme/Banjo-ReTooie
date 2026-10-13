#ifndef __TOOIE_SPEEDUP_H__
#define __TOOIE_SPEEDUP_H__

#include <string>

namespace recomp::config {
    class Config;
}

// Speed-up key (src/game/speedup.cpp): hold the Speed-Up key (default F2, rebindable in the
// Controls tab, Cheats section) to run the game at 2x/3x/4x. It scales the N64ModernRuntime game
// clock (ultramodern::set_speed_multiplier), so the VI, timers and audio all stay in step. With
// the toggle option on, the key switches it on and off instead. The options live in the Cheats tab
// and the key only works while "Enable cheats" and "Speed-up" are both on.
namespace tooie::speedup {
    inline const std::string enabled_option = "speed_up_enabled";
    inline const std::string factor_option = "speed_up_factor";
    inline const std::string toggle_option = "speed_up_toggle";

    // Names the Speed-Up hotkey and gives it its default bindings. Call before
    // recompui::config::finalize(), which loads the controls config.
    void register_input();

    // Adds the speed-up rows to the Cheats tab, hidden while source_option (the master switch) is off.
    void add_options(recomp::config::Config& cheats, const std::string& master_option);

    // Starts the key-watching thread (safe to call more than once).
    void start();
}

#endif
