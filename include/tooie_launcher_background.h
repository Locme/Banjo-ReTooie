#ifndef __TOOIE_LAUNCHER_BACKGROUND_H__
#define __TOOIE_LAUNCHER_BACKGROUND_H__

namespace recompui {
    class LauncherMenu;
}

// The start menu's animated background (L, 2026-10-24), src/ui/launcher_background.cpp: L's BANJO.svg
// split into assets/launcher/ layers. The sky and hill stay still, one part slides in from the left and
// the other from the right, then both drift a little for as long as the menu is up.
namespace tooie::launcher_background {
    // Adds the layers to the launcher's background. Call from the launcher init callback.
    void init(recompui::LauncherMenu* menu);
    // Moves the layers. Call from the launcher update callback (every frame while the launcher shows).
    void update(recompui::LauncherMenu* menu);
}

#endif
