#ifndef __TOOIE_TEXTURE_SLIDE_H__
#define __TOOIE_TEXTURE_SLIDE_H__

#include <string>

#include "librecomp/config.hpp"

// Texture slide blending (src/debug/texture_slide.cpp): a Debug option, on by default, that lets RT64
// slide a texture between game frames when the game moves it (scrolling water, smoke animations).
// Off, textures step at the game's own rate (RT64::SetTileInterpolation, lib-patches/rt64.patch).
namespace tooie::texture_slide {
    inline const std::string option = "texture_slide_blending";

    void add_option(recomp::config::Config& wip);
    // Sends the saved setting to RT64 (after the config loads).
    void apply();
    bool enabled();
}

#endif
