#ifndef __TOOIE_LAUNCHER_TITLE_H__
#define __TOOIE_LAUNCHER_TITLE_H__

namespace recompui {
    class LauncherMenu;
}

// The start menu's BANJO RE-TOOIE title (L, 2026-10-24), src/ui/launcher_title.cpp: its letters bounce
// in one at a time, on their own layer above the background.
namespace tooie::launcher_title {
    // Adds the title's layer to the launcher. Call from the launcher init callback, after the menu is built.
    void init(recompui::LauncherMenu* menu);
    // Moves the letters. Call from the launcher update callback (every frame while the launcher shows).
    void update(recompui::LauncherMenu* menu);
}

#endif
