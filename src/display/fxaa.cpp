// FXAA (handoff 4.34, the XBLA port's FXAA and FXAA Extreme).
//
// RT64 runs one FXAA pass on the finished game image before the VI draws it to the window, after SMAA
// when both are on (lib-patches/rt64.patch, src/render/rt64_fxaa.cpp and src/shaders/FxaaPS.hlsl).
// FXAA finds edges by brightness and blends across them; it is cheaper than SMAA and softer.
// Extreme follows edges further and catches fainter ones, for an even softer picture.
// Like SMAA, it saves and applies as it changes instead of waiting for Apply.

#include <variant>

#include "recompui/config.h"

#include "tooie_effect_views.h"
#include "tooie_fxaa.h"

namespace RT64 {
    // lib/rt64/src/render/rt64_fxaa.h (from lib-patches/rt64.patch).
    void SetFxaaMode(uint32_t mode);
}

namespace {
    // Looked up each time: the tab list moves its configs as more tabs are added.
    recomp::config::Config& graphics_config() {
        return recompui::config::get_config(recompui::config::graphics::id);
    }

    bool created = false;
}

void tooie::fxaa::apply() {
    if (!created) {
        return;
    }
    uint32_t mode = (uint32_t)Mode::Off;
    try {
        mode = std::get<uint32_t>(graphics_config().get_option_value(option));
    } catch (...) {
    }
    // Graphics > Debug > Effect debug view: on (at its setting, or Fxaa when it is off) only in its own view.
    if (tooie::effect_views::isolating()) {
        if (tooie::effect_views::solo() != tooie::effect_views::Solo::Fxaa) {
            mode = (uint32_t)Mode::Off;
        } else if (mode == (uint32_t)Mode::Off) {
            mode = (uint32_t)Mode::Fxaa;
        }
    }
    RT64::SetFxaaMode(mode);
}

void tooie::fxaa::add_option(recomp::config::Config& graphics) {
    created = true;

    graphics.add_enum_option(
        option,
        "FXAA Anti-Aliasing",
        "A quick edge smoothing on the finished picture, as on Xbox Live Arcade. Lighter than SMAA but softer; Extreme smooths more and blurs a little more. It can be used with MSAA and SMAA.",
        {
            {Mode::Off, "Off", "Off"},
            {Mode::Fxaa, "FXAA", "FXAA"},
            {Mode::Extreme, "Extreme", "FXAA Extreme"},
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
