#ifndef __TOOIE_UPSCALER_H__
#define __TOOIE_UPSCALER_H__

#include <cstdint>
#include <string>

#include "librecomp/config.hpp"

// Arm ASR and Snapdragon GSR are for Android; on other platforms they are listed as such and act as Off.
// Temporal upscaler choice (src/display/upscaler.cpp): a Graphics option, Off by default. FSR 4, DLSS and
// their native-resolution modes need motion vectors, depth and camera jitter from RT64 (rt64-ext/src/render/rt64_upscaler.*).
namespace tooie::upscaler {
    inline const std::string option = "upscaler";

    enum class Mode : uint32_t {
        Off,
        Fsr4,
        Fsr4NativeAA,
        Dlss,
        Dlaa,
        ArmAsr,
        SnapdragonGsr,
        Fsr3,
    };

    void add_option(recomp::config::Config& graphics);

    // Sends the saved setting to RT64.
    void apply();
}

#endif
