#ifndef __TOOIE_SMAA_H__
#define __TOOIE_SMAA_H__

#include <cstdint>
#include <string>

#include "librecomp/config.hpp"

// SMAA anti-aliasing (src/display/smaa.cpp): RT64 smooths the game image with iryoku's SMAA
// (lib/smaa, lib-patches/rt64.patch) before it is drawn to the window, on top of any MSAA.
namespace tooie::smaa {
    enum class Quality : uint32_t { Off, Low, Medium, High, Ultra };
    inline const std::string option = "smaa";

    // Adds the option to the Graphics tab. It applies as soon as it changes.
    void add_option(recomp::config::Config& graphics);
    // Hands the current setting to RT64.
    void apply();
}

#endif
