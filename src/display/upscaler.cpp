// Temporal upscaler setting (FSR 4, DLSS and their native-resolution modes).
//
// Only the setting lives here. RT64 receives the mode (rt64-ext/src/render/rt64_upscaler.cpp) and leaves the picture
// alone until the motion-vector pass and the vendor libraries are in; Off is the default and changes nothing.

#include <variant>
#include <vector>

#include "recompui/config.h"

#include "tooie_upscaler.h"

namespace RT64 {
    // rt64-ext/src/render/rt64_upscaler.h.
    void SetUpscalerMode(uint32_t mode);
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
#if !defined(__ANDROID__)
    // The Android upscalers do nothing elsewhere.
    if ((mode == (uint32_t)Mode::ArmAsr) || (mode == (uint32_t)Mode::SnapdragonGsr)) {
        mode = (uint32_t)Mode::Off;
    }
#endif
    RT64::SetUpscalerMode(mode);
}

void tooie::upscaler::add_option(recomp::config::Config& graphics) {
    created = true;

    // Arm ASR and Snapdragon GSR are listed on Android only.
    std::vector<recomp::config::ConfigOptionEnumOption> choices = {
        {Mode::Off, "Off", "Off"},
        {Mode::Fsr3, "FSR 3", "FSR 3"},
        {Mode::Fsr4, "FSR 4", "FSR 4"},
        {Mode::Fsr4NativeAA, "FSR 4 Native AA", "FSR 4 Native AA"},
        {Mode::Dlss, "DLSS", "DLSS"},
        {Mode::Dlaa, "DLAA", "DLAA"},
#if defined(__ANDROID__)
        {Mode::ArmAsr, "Arm ASR", "Arm ASR"},
        {Mode::SnapdragonGsr, "Snapdragon GSR", "Snapdragon GSR"},
#endif
    };
    graphics.add_enum_option(
        option,
        "Upscaler",
        "Temporal upscaling and anti-aliasing. FSR 3 runs on any recent graphics card. FSR 4 needs a Radeon RX 9000 card and DLSS an RTX card; On Android phones, Arm ASR (Mali) and Snapdragon GSR (Adreno) are listed too. The native modes (FSR 4 Native AA, DLAA) anti-alias without upscaling. Off leaves the picture as it is.",
        choices,
        Mode::Off);
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
