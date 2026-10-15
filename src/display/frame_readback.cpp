// Frame Read-Back (handoff 4.32, performance).
//
// RT64 renders to RAM by default: at the end of every display list it draws the frame, waits for
// the GPU to finish and copies the picture back into RDRAM, as a real RDP leaves it there. Measured
// headless (Bottles' House, lavapipe), that made the renderer's thread wait on the GPU every frame
// and, since the game waits for the renderer to read each list (the vertex race fix in
// lib-patches/N64ModernRuntime.patch), the game, the renderer and the GPU took turns: 14 fps.
// With it off, RT64 hands the frame to its own workload thread and the next list can start at
// once: 28 fps, and the controller-to-screen time went from about 165 ms to 64 ms.
// RT64 still keeps framebuffers on the GPU for effects that draw with an earlier frame (the pause
// menu's background, the jigsaw wipe, both checked headless). Only something the game reads back
// with the CPU would be missing, so the option stays for that case.
// Like SMAA, it saves and applies as it changes instead of waiting for Apply.

#include <variant>

#include "recompui/config.h"

#include "tooie_frame_readback.h"

namespace RT64 {
    // lib/rt64/src/common/rt64_emulator_configuration.h (from lib-patches/rt64.patch).
    void SetRenderToRAM(bool enabled);
}

namespace {
    // Looked up each time: the tab list moves its configs as more tabs are added.
    recomp::config::Config& graphics_config() {
        return recompui::config::get_config(recompui::config::graphics::id);
    }

    bool created = false;
}

void tooie::frame_readback::apply() {
    if (!created) {
        return;
    }
    bool on = false;
    try {
        on = std::get<bool>(graphics_config().get_option_value(option));
    } catch (...) {
    }
    RT64::SetRenderToRAM(on);
}

void tooie::frame_readback::add_option(recomp::config::Config& graphics) {
    created = true;

    graphics.add_bool_option(
        option,
        "Frame Read-Back",
        "Copies every finished frame back into the game's memory, as on the N64. Off is much faster: the renderer no longer waits for the graphics card each frame, so the frame rate goes up and controls react sooner. Turn it on only if a picture effect shows black, frozen or an old image.",
        false);
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
