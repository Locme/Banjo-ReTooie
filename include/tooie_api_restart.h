#ifndef __TOOIE_API_RESTART_H__
#define __TOOIE_API_RESTART_H__

#include "librecomp/config.hpp"

// Graphics API restart (src/game/api_restart.cpp): RT64 picks its graphics API when it starts, so a
// new choice in Graphics > Graphics API asks "Restart now?" and, if confirmed, the game closes and
// starts itself again with the new API.
namespace tooie::api_restart {
    // Hooks the Graphics API option of the Graphics tab.
    void add_prompt(recomp::config::Config& graphics);
    // Called at the end of main(): starts the game again if a restart was confirmed.
    void relaunch_if_requested(int argc, char** argv);
}

#endif
