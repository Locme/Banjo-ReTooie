// Texture slide blending (a debug aid for frame interpolation). It sets RT64::SetTileInterpolation.
//
// L saw smoke and water droplets break into stripes with smoothing on (2026-10-15). Those effects
// animate by moving the texture across a sheet of frames, and RT64 slides that move over the
// in-between frames like a scroll, showing the parts of the sheet between two frames. RT64 now skips
// a move of half the drawn size or more (lib-patches/rt64.patch, rt64_game_frame.cpp); this option
// turns all texture sliding off, to tell whether what is left still comes from it.
// Headless: TOOIE_TEXTURE_SLIDE=0 starts with it off.

#include <atomic>
#include <cstdlib>
#include <variant>

#include "recompui/config.h"

#include "tooie_game.h"
#include "tooie_texture_slide.h"

namespace RT64 {
    // lib/rt64/src/common/rt64_emulator_configuration.h (from lib-patches/rt64.patch).
    void SetTileInterpolation(bool enabled);
}

namespace {
    std::atomic<bool> on{true};

    recomp::config::Config& wip_config() {
        return recompui::config::get_config(tooie::wip_tab_id);
    }
}

void tooie::texture_slide::add_option(recomp::config::Config& wip) {
    if (const char* v = std::getenv("TOOIE_TEXTURE_SLIDE"); v != nullptr && v[0] == '0') {
        on = false;
    }
    wip.add_bool_option(
        option,
        "Texture Slide Blending",
        "For testing. With frame smoothing, slides textures the game moves (scrolling water, animated smoke) between game frames. "
        "Off, they step at the game's own rate. Turn it off if smoke, splashes or droplets show stripes or the wrong picture while moving.",
        on.load());
    wip.add_option_change_callback(option,
        [](recomp::config::ConfigValueVariant value, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
            if (context == recomp::config::OptionChangeContext::Temporary) {
                wip_config().save_config();
                return;
            }
            const auto* v = std::get_if<bool>(&value);
            on = (v == nullptr) || *v;
            RT64::SetTileInterpolation(on.load());
        });
}

void tooie::texture_slide::apply() {
    if (std::getenv("TOOIE_TEXTURE_SLIDE") == nullptr) {
        try {
            on = std::get<bool>(wip_config().get_option_value(option));
        } catch (...) {
        }
    }
    RT64::SetTileInterpolation(on.load());
}

bool tooie::texture_slide::enabled() {
    return on.load(std::memory_order_relaxed);
}
