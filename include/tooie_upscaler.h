#ifndef __TOOIE_UPSCALER_H__
#define __TOOIE_UPSCALER_H__

#include <cstdint>
#include <string>

#include "librecomp/config.hpp"

// Arm ASR and Snapdragon GSR are for Android; on other platforms they are listed as such and act as Off.
// Temporal upscaler choice (src/display/upscaler.cpp): a Graphics option, Off by default. FSR 4, DLSS and
// their native-resolution modes need motion vectors, depth and camera jitter from RT64 (rt64-ext/src/render/rt64_temporal_upscaler.*).
namespace tooie::upscaler {
    inline const std::string option = "upscaler";
    inline const std::string quality_option = "upscaler_quality";
    inline const std::string hud_option = "upscaler_hud_outside";
    inline const std::string hud_full_option = "upscaler_hud_full";
    inline const std::string reactive_option = "upscaler_reactive";
    inline const std::string sharpness_option = "upscaler_sharpness";

    enum class Quality : uint32_t {
        Quality,
        Balanced,
        Performance,
        UltraPerformance,
    };

    enum class Sharpness : uint32_t {
        Off,
        Low,
        Medium,
        High,
    };

    enum class Mode : uint32_t {
        Off,
        Fsr4,
        Fsr4NativeAA,
        Dlss,
        Dlaa,
        ArmAsr,
        SnapdragonGsr,
        Fsr3,
        Temporal,
    };

    void add_option(recomp::config::Config& graphics);

    // Called when the Graphics API choice is loaded or changed: on Vulkan the Direct3D 12 only upscalers (FSR, DLSS) are greyed out.
    void api_changed(uint32_t api);

    // Sends the saved setting to RT64.
    void apply();
}

#endif
