// FSR 1 upscaling (handoff 4.34, the XBLA port's AMD FSR 1 upscaling).
//
// When the game renders below the window's resolution (Resolution set to Original, 2x and so on), RT64
// upscales the finished image to the window's size with AMD FidelityFX Super Resolution 1 (lib/fsr, MIT):
// EASU upscales with edge-aware filtering, then RCAS sharpens. Without it the VI's bilinear filter
// stretches the image. It runs after screenshots and photo effects, which stay at the game's own
// resolution, and does nothing when the game already renders at the window's size.
// Like SMAA, it saves and applies as it changes instead of waiting for Apply.

#include <variant>

#include "recompui/config.h"

#include "tooie_fsr.h"

namespace RT64 {
    // lib/rt64/src/render/rt64_fsr.h (from lib-patches/rt64.patch).
    void SetFsrMode(uint32_t mode);
}

namespace {
    // Looked up each time: the tab list moves its configs as more tabs are added.
    recomp::config::Config& graphics_config() {
        return recompui::config::get_config(recompui::config::graphics::id);
    }

    bool created = false;
}

void tooie::fsr::apply() {
    if (!created) {
        return;
    }
    uint32_t mode = (uint32_t)Mode::Off;
    try {
        mode = std::get<uint32_t>(graphics_config().get_option_value(option));
    } catch (...) {
    }
    RT64::SetFsrMode(mode);
}

void tooie::fsr::add_option(recomp::config::Config& graphics) {
    created = true;

    graphics.add_enum_option(
        option,
        "FSR 1 Upscaling",
        "When Resolution is below your window's (Original, 2x and so on), AMD FSR 1 upscales the picture to the window with sharper edges than plain stretching. Sharp sharpens more. It does nothing at Auto resolution, which already matches the window.",
        {
            {Mode::Off, "Off", "Off"},
            {Mode::On, "On", "On"},
            {Mode::Sharp, "Sharp", "Sharp"},
        },
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
