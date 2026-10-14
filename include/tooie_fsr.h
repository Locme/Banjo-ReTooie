#ifndef __TOOIE_FSR_H__
#define __TOOIE_FSR_H__

#include <cstdint>
#include <string>

#include "librecomp/config.hpp"

// FSR 1 upscaling (src/display/fsr.cpp): a Graphics option, Off, On or Sharp. RT64 upscales the game
// image to the window's size with AMD FidelityFX Super Resolution 1 (lib/fsr, lib-patches/rt64.patch).
namespace tooie::fsr {
    inline const std::string option = "fsr";

    enum class Mode : uint32_t {
        Off,
        On,
        Sharp,
    };

    void add_option(recomp::config::Config& graphics);

    // Sends the saved setting to RT64.
    void apply();
}

#endif
