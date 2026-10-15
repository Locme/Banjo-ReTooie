// Low Input Latency (handoff 4.31).
//
// The runtime used to queue each screen update before latching the frame the game had just swapped
// in, so a frame reached the screen one VI after a real N64 would start showing it (the comment in
// ultramodern's VI thread calls this "after the previous frame's scanout finished"). With this on,
// the screen update goes after the latch, so the frame shows at the next VI: about 17 ms less
// between pressing a button and seeing it, at 60 VIs a second (4 ms at Unlocked's 240).
// The frame rate overlay's "Input latency" line (Full) shows the difference live.
// Like SMAA, it saves and applies as it changes instead of waiting for Apply.

#include <variant>

#include "recompui/config.h"
#include "ultramodern/ultramodern.hpp"

#include "tooie_low_latency.h"

namespace {
    // Looked up each time: the tab list moves its configs as more tabs are added.
    recomp::config::Config& graphics_config() {
        return recompui::config::get_config(recompui::config::graphics::id);
    }

    bool created = false;
}

void tooie::low_latency::apply() {
    if (!created) {
        return;
    }
    bool on = true;
    try {
        on = std::get<bool>(graphics_config().get_option_value(option));
    } catch (...) {
    }
    ultramodern::set_low_latency(on);
}

void tooie::low_latency::add_option(recomp::config::Config& graphics) {
    created = true;

    graphics.add_bool_option(
        option,
        "Low Input Latency",
        "Shows each finished frame at the next screen refresh, as the N64 does, instead of one refresh later. Buttons and the stick feel about 17 ms quicker. Turn it off only if you see flicker or a frame out of order.",
        true);
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
