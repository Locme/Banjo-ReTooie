#ifndef __TOOIE_MIRROR_MODE_H__
#define __TOOIE_MIRROR_MODE_H__

#include <string>

#include "librecomp/config.hpp"

// Mirror Mode (src/display/mirror_mode.cpp): a General option that flips the picture left to right. RT64
// flips the finished game image, after drawing the HUD and text flipped so they come out readable
// (lib-patches/rt64.patch, src/render/rt64_mirror.cpp).
namespace tooie::mirror_mode {
    inline const std::string option = "mirror_mode";

    void add_option(recomp::config::Config& general);

    // Sends the saved setting to RT64.
    void apply();
}

#endif
