#ifndef __TOOIE_EFFECT_VIEWS_H__
#define __TOOIE_EFFECT_VIEWS_H__

// Effect developer views (src/display/effect_views.cpp, handoff 4.43): F6 steps through the scene
// effects' debug views and F8 shows the picture effects on the left half only, to compare.
namespace tooie::effect_views {
    // Starts the F6 / F8 key-watching thread (safe to call more than once).
    void start();
}

#endif
