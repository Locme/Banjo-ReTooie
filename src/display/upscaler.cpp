// Temporal upscaler setting (FSR 4, DLSS and their native-resolution modes).
//
// Only the setting lives here. RT64 receives the mode (rt64-ext/src/render/rt64_temporal_upscaler.cpp) and leaves the picture
// alone until the motion-vector pass and the vendor libraries are in; Off is the default and changes nothing.

#include <variant>
#include <vector>

#include "recompui/config.h"

#include "tooie_upscaler.h"

namespace RT64 {
    // rt64-ext/src/render/rt64_upscaler.h.
    void SetUpscalerMode(uint32_t mode);
    void SetUpscalerQuality(uint32_t quality);
}

namespace {
    // Looked up each time: the tab list moves its configs as more tabs are added.
    recomp::config::Config& graphics_config() {
        return recompui::config::get_config(recompui::config::graphics::id);
    }

    bool created = false;

}

void tooie::upscaler::apply() {
    if (!created) {
        return;
    }
    uint32_t mode = (uint32_t)Mode::Off;
    try {
        mode = std::get<uint32_t>(graphics_config().get_option_value(option));
    } catch (...) {
    }
    // A saved choice this platform doesn't list (a settings file from another device) acts as Off.
#if defined(__ANDROID__)
    const bool listed = (mode == (uint32_t)Mode::Off) || (mode == (uint32_t)Mode::Temporal) || (mode == (uint32_t)Mode::SnapdragonGsr);
#else
    const bool listed = (mode != (uint32_t)Mode::ArmAsr) && (mode != (uint32_t)Mode::SnapdragonGsr);
#endif
    if (!listed) {
        mode = (uint32_t)Mode::Off;
    }
    RT64::SetUpscalerMode(mode);
    uint32_t quality = (uint32_t)Quality::Quality;
    try {
        quality = std::get<uint32_t>(graphics_config().get_option_value(quality_option));
    } catch (...) {
    }
    RT64::SetUpscalerQuality(quality);
}

void tooie::upscaler::add_option(recomp::config::Config& graphics) {
    created = true;

    // Only the upscalers a platform can run are listed: Android has no FSR 3, FSR 4 or DLSS (their DLLs are Windows only), and Windows no Snapdragon GSR. Arm ASR is not made yet.
    std::vector<recomp::config::ConfigOptionEnumOption> choices = {
        {Mode::Off, "Off", "Off"},
        {Mode::Temporal, "Temporal (built-in)", "Temporal (built-in)"},
#if defined(__ANDROID__)
        {Mode::SnapdragonGsr, "Snapdragon GSR", "Snapdragon GSR"},
#else
        {Mode::Fsr3, "FSR 3", "FSR 3"},
        {Mode::Fsr4, "FSR 4", "FSR 4"},
        {Mode::Fsr4NativeAA, "FSR 4 Native AA", "FSR 4 Native AA"},
        {Mode::Dlss, "DLSS", "DLSS"},
        {Mode::Dlaa, "DLAA", "DLAA"},
#endif
    };
    graphics.add_enum_option(
        option,
        "Upscaler",
        "Temporal upscaling and anti-aliasing. Temporal (built-in) is the game's own temporal upscaler and works on any card. FSR 3 runs on any recent Windows graphics card. FSR 4 needs a Radeon RX 9000 card and DLSS an RTX card; On Android phones, Snapdragon GSR (a fast spatial upscaler, best on Adreno) is listed instead. The native modes (FSR 4 Native AA, DLAA) anti-alias without upscaling. Off leaves the picture as it is.",
        choices,
        Mode::Off);
    graphics.add_enum_option(
        quality_option,
        "Upscaler Quality",
        "How much of your window's height the game renders at when Resolution is Auto and an upscaler is on: Quality about 67%, Balanced 58%, Performance 50%, Ultra Performance 33%. The upscaler makes up the rest. Native modes ignore it.",
        {
            {Quality::Quality, "Quality", "Quality"},
            {Quality::Balanced, "Balanced", "Balanced"},
            {Quality::Performance, "Performance", "Performance"},
            {Quality::UltraPerformance, "Ultra Performance", "Ultra Performance"},
        },
        Quality::Quality);
    graphics.add_option_change_callback(quality_option,
        [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
            if (context == recomp::config::OptionChangeContext::Temporary) {
                graphics_config().save_config();
            } else {
                apply();
            }
        });
    graphics.add_option_change_callback(option,
        [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
            if (context == recomp::config::OptionChangeContext::Temporary) {
                // Saving applies the change, which calls back here as Permanent.
                graphics_config().save_config();
            } else {
                apply();
            }
        });
}
