#ifndef __TOOIE_MIX_RATE_H__
#define __TOOIE_MIX_RATE_H__

#include <cstdint>

namespace recomp::config {
    class Config;
}

namespace tooie::mix_rate {
    // Sound > Mix rate: Original (22 kHz) or High (44 kHz). Switches at the start of the next sound frame.
    void add_option(recomp::config::Config& sound);

    // RDRAM holding the game's sound memory while High is in use (above the 8 MB a save state copies),
    // as a physical address and size. The size is 0 if the sound memory didn't move.
    uint32_t extra_region_start();
    uint32_t extra_region_size();

    // The rate factor the sound in RDRAM is set up for (1 at 22 kHz, 2 at 44 kHz). A save state keeps it
    // with its RDRAM and puts it back on a load, so the next sound frame switches the reverb, the synthesizer's
    // rate and the AI back to what the menu asks for (a load otherwise left the music at double or half speed).
    uint32_t factor();
    void restore_factor(uint32_t factor);
}

#endif
