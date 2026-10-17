#ifndef __TOOIE_INTERP_CHECK_H__
#define __TOOIE_INTERP_CHECK_H__

// Interpolation check (src/debug/interp_check.cpp): F7 turns on a debug view
// that tints models red for a moment when their blend between frames looks
// wrong, and logs each one ([interp-check] lines in logs/console.log).
// model_tagging.cpp does the checking.
#include <string>

#include "librecomp/config.hpp"

namespace tooie::interp_check {
    inline const std::string check_option = "interp_check";
    inline const std::string blend_option = "interp_blend_mode";
    // Freeze, for switching blend modes on a held scene (tooie_save_state.h).
    inline const std::string freeze_option = "interp_freeze";
    // Adds the Interpolation check, Freeze and Interpolation blend mode options to the DEV tab.
    void add_options(recomp::config::Config& graphics);

    // Starts watching the key (once).
    void start();
    bool enabled();
    // The Blend Mode key (unbound unless set in the Controls tab) or the menu picks a blend mode for finding what blends wrong (5 = custom, the default; 0 = normal):
    // 1 no tags (RT64's own matching), 2 tags with vertex blending (off since
    // it tore the sky),
    // 3 camera untagged, 4 models snap (camera still blends), 5 custom (the default: models snap, characters blend with vertices, manual tags decide).
    int blend_mode();
    const char* blend_mode_name(int mode);
    // 5 custom (the default): models snap, characters (2+ matrices) blend with their vertices, the manual tags (tooie_interp_tags.h) decide for their models.
    inline constexpr int blend_custom = 5;
    void set_blend_mode(int mode);
}

#endif
