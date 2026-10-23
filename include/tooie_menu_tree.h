#ifndef __TOOIE_MENU_TREE_H__
#define __TOOIE_MENU_TREE_H__

namespace tooie::menu_tree {
    // Puts options under the options they belong to, so a row gets an arrow that opens them: an effect
    // (Fog, 3D grass, Banjo fur ...) over its sliders, and the Jiggle switch over the jiggle parts and
    // their sliders. A number option with options under it shows as an on/off switch. Display only: the
    // values are untouched, and Search still finds the options. Call once, after every tab has been
    // created (before recompui::config::finalize()).
    void classify();
}

#endif
