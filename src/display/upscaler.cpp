// Temporal upscaler setting (FSR 4, DLSS and their native-resolution modes).
//
// Only the setting lives here. RT64 receives the mode (rt64-ext/src/render/rt64_temporal_upscaler.cpp) and leaves the picture
// alone until the motion-vector pass and the vendor libraries are in; Off is the default and changes nothing.

#include <variant>
#include <vector>

#include "recompui/config.h"
#include "ultramodern/config.hpp"

#include "tooie_upscaler.h"

namespace RT64 {
    // rt64-ext/src/render/rt64_upscaler.h.
    void SetUpscalerMode(uint32_t mode);
    void SetUpscalerQuality(uint32_t quality);
    void SetUpscalerHudSplit(bool enabled);
    void SetUpscalerHudFullResolution(bool enabled);
    void SetUpscalerReactive(bool enabled);
    void SetUpscalerObjectMotion(bool enabled);
    void SetUpscalerSharpness(float sharpness);
}

namespace {
    // Looked up each time: the tab list moves its configs as more tabs are added.
    recomp::config::Config& graphics_config() {
        return recompui::config::get_config(recompui::config::graphics::id);
    }

    bool created = false;

}

namespace {
    // List order: Off, Temporal, FSR 3, FSR 4, FSR 4 Native AA, DLSS, DLAA (Windows).
    bool vulkan_selected = false;
}

void tooie::upscaler::api_changed(uint32_t api) {
    vulkan_selected = (api == (uint32_t)ultramodern::renderer::GraphicsApi::Vulkan);
    if (!created) {
        return;
    }
#if !defined(__ANDROID__)
    // FSR 3, FSR 4, FSR 4 Native AA (DLSS and DLAA have a Vulkan path).
    for (uint32_t index = 2; index <= 4; index++) {
        graphics_config().update_enum_option_disabled(option, index, vulkan_selected);
    }
    apply();
#endif
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
#if !defined(__ANDROID__)
    // FSR needs Direct3D 12; on Vulkan the built-in upscaler stands in.
    if (vulkan_selected && ((mode == (uint32_t)Mode::Fsr3) || (mode == (uint32_t)Mode::Fsr4) || (mode == (uint32_t)Mode::Fsr4NativeAA))) {
        mode = (uint32_t)Mode::Temporal;
    }
#endif
    RT64::SetUpscalerMode(mode);
    uint32_t quality = (uint32_t)Quality::Quality;
    try {
        quality = std::get<uint32_t>(graphics_config().get_option_value(quality_option));
    } catch (...) {
    }
    RT64::SetUpscalerQuality(quality);
    bool hud_outside = true;
    try {
        hud_outside = std::get<bool>(graphics_config().get_option_value(hud_option));
    } catch (...) {
    }
    RT64::SetUpscalerHudSplit(hud_outside);
    bool hud_full = false;
    try {
        hud_full = std::get<bool>(graphics_config().get_option_value(hud_full_option));
    } catch (...) {
    }
    RT64::SetUpscalerHudFullResolution(hud_full);
    bool reactive = true;
    try {
        reactive = std::get<bool>(graphics_config().get_option_value(reactive_option));
    } catch (...) {
    }
    RT64::SetUpscalerReactive(reactive);
    bool object_motion = true;
    try {
        object_motion = std::get<bool>(graphics_config().get_option_value(object_motion_option));
    } catch (...) {
    }
    RT64::SetUpscalerObjectMotion(object_motion);
    uint32_t sharpness = (uint32_t)Sharpness::Off;
    try {
        sharpness = std::get<uint32_t>(graphics_config().get_option_value(sharpness_option));
    } catch (...) {
    }
    static const float sharpness_amounts[] = { 0.0f, 0.3f, 0.6f, 0.9f };
    RT64::SetUpscalerSharpness(sharpness_amounts[sharpness < 4 ? sharpness : 0]);
}

void tooie::upscaler::add_option(recomp::config::Config& graphics) {
    created = true;
    // The API may have been loaded before this option existed.
    {
        uint32_t api = 0;
        try {
            api = std::get<uint32_t>(graphics.get_option_value(recompui::config::graphics::options::api_option));
        } catch (...) {
        }
        vulkan_selected = (api == (uint32_t)ultramodern::renderer::GraphicsApi::Vulkan);
    }

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
        "Temporal upscaling and anti-aliasing. Temporal (built-in) is the game's own temporal upscaler and works on any card. FSR 3 runs on any recent Windows graphics card (FSR needs the Direct3D 12 graphics API and is greyed out on Vulkan; DLSS runs on either). FSR 4 needs a Radeon RX 9000 card and DLSS an RTX card; On Android phones, Snapdragon GSR (a fast spatial upscaler, best on Adreno) is listed instead. The native modes (FSR 4 Native AA, DLAA) anti-alias without upscaling. Off leaves the picture as it is.",
        choices,
        Mode::Off);
    graphics.add_enum_option(
        quality_option,
        "Upscaler Quality",
        "How much of your window's height the game renders at when Resolution is Auto and an upscaler is on: Quality about 67%, Balanced 58%, Performance 50%, Ultra Performance 33%, rounded to a whole multiple of the game's own height (so at small windows two choices can render at the same size). The upscaler makes up the rest. Native modes ignore it.",
        {
            {Quality::Quality, "Quality", "Quality"},
            {Quality::Balanced, "Balanced", "Balanced"},
            {Quality::Performance, "Performance", "Performance"},
            {Quality::UltraPerformance, "Ultra Performance", "Ultra Performance"},
        },
        Quality::Quality);
    graphics.add_bool_option(
        hud_option,
        "HUD Outside",
        "Keeps the HUD out of the upscaler: the upscaler works on the 3D world alone and the HUD is added afterwards, so it cannot ghost or shimmer. The HUD is drawn at the game's lowered resolution. Off sends the whole picture through the upscaler.",
        true);
    graphics.add_bool_option(
        hud_full_option,
        "HUD Full Resolution (Experimental)",
        "Draws the HUD again at your window's resolution and puts it on the upscaled picture, so it stays sharp. Needs HUD Outside and no MSAA. Screens that show the 3D world inside the HUD (some menus) may look wrong; turn it off if so.",
        false);
    graphics.add_bool_option(
        reactive_option,
        "Reactive Mask",
        "Marks particles, fire, spray and other see-through effects so the upscaler trusts its history less there, which cuts the trails they leave behind. Works with FSR and DLSS. Turn it off if effects look wrong.",
        true);
    graphics.add_enum_option(
        sharpness_option,
        "Sharpness",
        "Sharpens the upscaled picture. Works with Temporal (built-in) and FSR; DLSS has its own and ignores this.",
        {
            {Sharpness::Off, "Off", "Off"},
            {Sharpness::Low, "Low", "Low"},
            {Sharpness::Medium, "Medium", "Medium"},
            {Sharpness::High, "High", "High"},
        },
        Sharpness::Off);
    graphics.add_bool_option(
        object_motion_option,
        "Object Motion",
        "Draws the 3D world's solid things a second time to tell the upscaler how characters and enemies move, which cuts smearing behind them. It costs frame rate; turn it off if the upscaler runs slower than no upscaler. The Reactive Mask needs it.",
        true);
    for (const std::string* id : { &reactive_option, &sharpness_option, &object_motion_option }) {
        graphics.add_option_change_callback(*id,
            [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
                if (context == recomp::config::OptionChangeContext::Temporary) {
                    graphics_config().save_config();
                } else {
                    apply();
                }
            });
    }
    graphics.add_option_change_callback(hud_full_option,
        [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
            if (context == recomp::config::OptionChangeContext::Temporary) {
                graphics_config().save_config();
            } else {
                apply();
            }
        });
    graphics.add_option_change_callback(hud_option,
        [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
            if (context == recomp::config::OptionChangeContext::Temporary) {
                graphics_config().save_config();
            } else {
                apply();
            }
        });
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
