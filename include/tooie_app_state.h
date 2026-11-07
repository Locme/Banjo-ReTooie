#ifndef __TOOIE_APP_STATE_H__
#define __TOOIE_APP_STATE_H__

#include <cstdint>

// Leaving the app while the game runs (src/main/app_state.cpp). On Android the app goes to the background on
// Home, a switch to another app, the screen turning off or a call (src/android/android_platform.cpp), and its
// window loses its surface. The console's `background <seconds>` does the same on any system.
namespace tooie::app_state {
    // The game stops where it is (no VIs, the game clock held), the hang watchdog stops watching, and the save
    // file and the logs are written out, as the system may close an app in the background. Safe to call again.
    void enter_background();
    // The game carries on from where it stopped.
    void enter_foreground();
    bool in_background();

    // The window lost its surface (false): RT64's present thread releases its swap chain and the surface it was
    // made on, and this waits for it (up to 2 s). With true, the next frame shown makes them again.
    void set_window_surface(bool available);
}

#endif
