#ifndef __TOOIE_EFFECT_VIEWS_H__
#define __TOOIE_EFFECT_VIEWS_H__

#include <cstdint>
#include <string>

#include "librecomp/config.hpp"

// Effect developer views (src/display/effect_views.cpp, handoff 4.43): Graphics > Debug > Effect debug
// view, or F6, steps through the scene effects' debug views and one view for each effect and picture
// filter on its own; F8 shows the picture effects on the left half only, to compare.
namespace tooie::effect_views {
    inline const std::string option = "effect_debug_view";
    inline const std::string compare_option = "effect_debug_compare";

    // The filter outside RT64's scene effects pass that a debug view shows on its own.
    enum class Solo : uint32_t {
        None,
        Sharpening,
        Contrast,
        Saturation,
        Vignette,
        Grain,
        Smaa,
        Fxaa,
        Fsr,
        Crt,
        Colour16,
        Colourblind,
        TextureUpscale,
    };

    // Adds the Effect debug view and Effect compare options to the Graphics tab (Debug heading).
    void add_option(recomp::config::Config& graphics);
    // Starts the F6 / F8 key-watching thread (safe to call more than once).
    void start();
    // True while a debug view shows one effect or filter alone (or all of them off): the picture filters
    // set outside the scene effects pass leave out every one but solo().
    bool isolating();
    // Which of those filters is shown alone (None for a scene effect, all off, or no debug view).
    Solo solo();
    // The Voxel Layer's void view (console: voxel void on): the picture with everything nothing was drawn on (the sky,
    // and any gap a hole lets the camera see through) magenta. It overrides the debug view while on; not saved.
    void void_view(bool on);
    bool void_view_on();
}

#endif
