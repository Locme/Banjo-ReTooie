#ifndef __TOOIE_FXAA_H__
#define __TOOIE_FXAA_H__

#include <cstdint>
#include <string>

#include "librecomp/config.hpp"

// FXAA (src/display/fxaa.cpp): a Graphics option, Off, FXAA or FXAA Extreme, run by RT64 on the
// finished game image (rt64-ext/src/render/rt64_fxaa.cpp, called from lib-patches/rt64.patch).
namespace tooie::fxaa {
    inline const std::string option = "fxaa";

    enum class Mode : uint32_t {
        Off,
        Fxaa,
        Extreme,
    };

    void add_option(recomp::config::Config& graphics);

    // Sends the saved setting to RT64.
    void apply();
}

#endif
