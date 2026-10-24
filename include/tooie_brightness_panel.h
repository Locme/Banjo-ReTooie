#ifndef __TOOIE_BRIGHTNESS_PANEL_H__
#define __TOOIE_BRIGHTNESS_PANEL_H__

// The brightness test panel (src/ui/brightness_panel.cpp): while the Brightness Test Pattern is on, the
// ESC menu is shut and a small panel with the Brightness slider and a Quit button stands in for it.
namespace tooie::brightness_panel {
    // Starts the thread that shows the panel while the test pattern is on (safe to call more than once).
    void start();
    // True while the panel is up; the ESC menu stays shut then.
    bool active();
}

#endif
