#ifndef __TOOIE_SCREENSHOT_H__
#define __TOOIE_SCREENSHOT_H__

// Screenshots (src/game/screenshot.cpp, handoff 4.83): F12 saves the game's picture, without
// any menu or notice drawn over it, as a PNG in the screenshots folder of the app-data folder,
// then shows "Screenshot saved". Held for half a second, F12 keeps the last 150 frames
// (shrunk 4x) and writes them to screenshots/burst-<stamp>/ when let go.
namespace tooie::screenshot {
    // Starts the key-watching thread (safe to call more than once).
    void start();

    // Takes a screenshot of the next frame. Safe to call from any thread.
    void take();
    // The whole window as it is shown, the Esc menu, the console and notices included, at the window's size, saved as
    // <stamp>-ui.png (the console's screenshot ui). Safe to call from any thread.
    void take_window();

    // A burst as F12 held: start keeps every presented frame (the last 150, shrunk 4x), stop writes them to
    // screenshots/burst-<stamp>/. For the console; stop does nothing while no burst is on.
    void burst_start();
    void burst_stop();
}

#endif
