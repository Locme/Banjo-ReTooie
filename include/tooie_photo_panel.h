#ifndef __TOOIE_PHOTO_PANEL_H__
#define __TOOIE_PHOTO_PANEL_H__

// The photo panel (src/ui/photo_panel.cpp, handoff 4.82): photo mode's on-screen list of settings and
// controls. It is UI, so screenshots never include it.
namespace tooie::photo_panel {
    // Starts the thread that shows the panel while photo mode is on (safe to call more than once).
    void start();
}

#endif
