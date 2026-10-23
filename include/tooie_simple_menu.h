#ifndef __TOOIE_SIMPLE_MENU_H__
#define __TOOIE_SIMPLE_MENU_H__

#include <string>

namespace recomp::config {
    class Config;
}

// Simple / Advanced settings menu (General > Menu). Simple, the default, shows an effect that has
// settings of its own as an on/off switch (a plain slider stays a slider) and hides the tuning sliders, photo mode and free camera extras, and debug options;
// Advanced shows everything. Display only: hidden settings keep their values and keep
// working, and Search still finds them.
namespace tooie::simple_menu {
    inline const std::string option = "simple_menu";

    // Adds the switch to General, before the other game options.
    void add_option(recomp::config::Config& general);

    // True while the Simple menu is on.
    bool on();

    // Marks the advanced options and switches on the effect on/off toggles. Call once, after every
    // tab has been created (before recompui::config::finalize()).
    void classify();

    // Applies the switch to every tab, and refreshes the "N advanced settings changed" note.
    void apply();
}

#endif
