// Mirror Mode: the whole picture flipped left to right, as a mirror would show it.
//
// RT64 flips the finished game image just before the VI draws it (lib-patches/rt64.patch, src/render/rt64_mirror.cpp),
// so every effect, the water and the shadows stay consistent with the world. The draws after the 3D world (the HUD,
// counters, dialogue and menu text) go in flipped across the middle first, so the flip puts them back in place and
// readable (FramebufferRenderer::submitRasterScene). Textures with text on the 3D world's own surfaces (signs) are
// part of the world and are mirrored with it.
// It applies as it changes, with no restart.

#include <atomic>
#include <variant>

#include "recompui/config.h"

#include "tooie_mirror_mode.h"

namespace RT64 {
    // lib/rt64/src/render/rt64_mirror.h (from lib-patches/rt64.patch).
    void SetMirrorMode(bool on);
}

namespace {
    std::atomic<bool> mirrored{ false };
}

bool tooie::mirror_mode::active() {
    return mirrored.load();
}

void tooie::mirror_mode::apply() {
    bool on = false;
    try {
        on = std::get<bool>(recompui::config::get_general_config().get_option_value(option));
    } catch (...) {
    }
    mirrored.store(on);
    RT64::SetMirrorMode(on);
}

void tooie::mirror_mode::add_option(recomp::config::Config& general) {
    general.add_bool_option(
        option,
        "Mirror Mode",
        "Flips the whole picture left to right, as a mirror would show it. The HUD, counters, dialogue and menu text stay readable. Writing on the world's own surfaces, such as signs, is mirrored with the world.",
        false);
    general.add_option_change_callback(option,
        [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant value, recomp::config::OptionChangeContext) {
            // Live: the new value goes straight to RT64 (the config may not hold it yet).
            if (const bool* on = std::get_if<bool>(&value)) {
                mirrored.store(*on);
                RT64::SetMirrorMode(*on);
            }
        });
}
