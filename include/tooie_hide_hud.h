#ifndef __TOOIE_HIDE_HUD_H__
#define __TOOIE_HIDE_HUD_H__

// Hide HUD (src/game/hide_hud.cpp, handoff 4.84): F1 hides and shows the HUD, text boxes and
// the pause menu, live, with a "HUD hidden" / "HUD shown" notice.
namespace tooie::hide_hud {
    // Starts the F1 key-watching thread (safe to call more than once).
    void start();

    // Hides or shows the HUD. Safe to call from any thread.
    void set_hidden(bool hidden);
    bool is_hidden();
}

#endif
