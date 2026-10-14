// SMAA anti-aliasing (asked for by L, 2026-10-13).
//
// RT64 runs SMAA 1x (iryoku/smaa, MIT, lib/smaa) on the finished game image before the
// VI draws it to the window: edge detection on luma, blend weights from SMAA's area and
// search textures, then neighbourhood blending. lib-patches/rt64.patch adds the passes
// (src/render/rt64_smaa.cpp); the quality picks SMAA's preset (Low, Medium, High, Ultra).
// It works on whatever the game rendered, so it adds to MSAA rather than replacing it,
// and it also smooths edges MSAA can't reach, such as alpha-tested leaves and fences.
// The Graphics tab normally waits for Apply; this saves and applies as it changes.

#include <variant>

#include "recompui/config.h"

#include "tooie_effect_views.h"
#include "tooie_picture_filters.h"
#include "tooie_smaa.h"

namespace RT64 {
    // lib/rt64/src/render/rt64_smaa.h (from lib-patches/rt64.patch).
    void SetSmaaQuality(uint32_t quality);
}

namespace {
    // Looked up each time: the tab list moves its configs as more tabs are added.
    recomp::config::Config& graphics_config() {
        return recompui::config::get_config(recompui::config::graphics::id);
    }

    bool created = false;
}

void tooie::smaa::apply() {
    if (!created) {
        return;
    }
    uint32_t quality = (uint32_t)Quality::Off;
    try {
        quality = std::get<uint32_t>(graphics_config().get_option_value(option));
    } catch (...) {
    }
    // Graphics > Debug > Effect debug view: on (at its setting, or High when it is off) only in its own view.
    if (tooie::effect_views::isolating()) {
        if (tooie::effect_views::solo() != tooie::effect_views::Solo::Smaa) {
            quality = (uint32_t)Quality::Off;
        } else if (quality == (uint32_t)Quality::Off) {
            quality = (uint32_t)Quality::High;
        }
    }
    RT64::SetSmaaQuality(quality);
}

void tooie::smaa::add_option(recomp::config::Config& graphics) {
    created = true;

    graphics.add_enum_option(
        option,
        "SMAA Anti-Aliasing",
        "Smooths jagged edges by finding them in the finished picture. It works together with MS Anti-Aliasing and also smooths edges that can't, like leaves and fences. Higher settings catch more edges for a little more GPU time.",
        {
            {Quality::Off, "Off", "Off"},
            {Quality::Low, "Low", "Low"},
            {Quality::Medium, "Medium", "Medium"},
            {Quality::High, "High", "High"},
            {Quality::Ultra, "Ultra", "Ultra"},
        },
        Quality::Off);
    graphics.add_option_change_callback(option,
        [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
            if (context == recomp::config::OptionChangeContext::Temporary) {
                // An effects preset saves once it has set everything; a change by hand makes it Custom.
                if (tooie::picture_filters::applying_effects_preset()) {
                    return;
                }
                tooie::picture_filters::effect_changed();
                // Saving applies the change, which calls back here as Permanent.
                graphics_config().save_config();
            } else {
                apply();
            }
        });
}
