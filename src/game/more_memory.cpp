// More game memory (General > More game memory).
//
// The game keeps its heap in 0x80137800-0x80400000 (2.8 MB) and builds each frame in fixed buffers,
// with fixed caches for the animations in use. A crowded scene (many characters at once) overflows
// the display list buffer into the heap and fills the animation caches, and the game crashes. With
// this setting on, the generated code uses the values in banjotooie.us.toml's "Bigger game heap",
// "Bigger frame buffers", "More sound voices" and "Bigger animation caches" sections instead of the
// game's own: a 12.8 MB heap up to 0x80E00000, about 8x the frame buffers, 48 sound voices instead
// of 24 with 180 sample DMA buffers (the audio heap moves with them, src/gameplay/mix_rate.cpp), and
// room for 240 animation files and 1023 animations in the 16 KB below the heap.
//
// The heap is laid out when the game boots, so the setting is read once, the first time the
// generated code asks (the heap setup at boot), and holds until the game is started again.

#include <atomic>
#include <cstdio>

#include "recompui/config.h"

#include "tooie_hooks.h"
#include "tooie_more_memory.h"

namespace {
    std::atomic<int> latched{-1};

    bool setting() {
        try {
            return std::get<bool>(recompui::config::get_general_config().get_option_value(tooie::more_memory::option));
        } catch (...) {
            return true;
        }
    }
}

extern "C" int tooie_more_memory(void) {
    int value = latched.load(std::memory_order_relaxed);
    if (value < 0) {
        int expected = -1;
        latched.compare_exchange_strong(expected, setting() ? 1 : 0);
        value = latched.load();
        std::printf("[more-memory] %s\n", value ? "on" : "off");
        std::fflush(stdout);
    }
    return value;
}
