#ifndef __TOOIE_SCREENSHOT_H__
#define __TOOIE_SCREENSHOT_H__

// Screenshots (src/game/screenshot.cpp, handoff 4.83): F12 saves the game's picture, without
// any menu or notice drawn over it, as a PNG in the screenshots folder of the app-data folder,
// then shows "Screenshot saved".
namespace tooie::screenshot {
    // Starts the key-watching thread (safe to call more than once).
    void start();

    // Takes a screenshot of the next frame. Safe to call from any thread.
    void take();
}

#endif
