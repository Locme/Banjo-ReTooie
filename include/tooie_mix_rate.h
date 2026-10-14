#ifndef __TOOIE_MIX_RATE_H__
#define __TOOIE_MIX_RATE_H__

#include <cstdint>

namespace recomp::config {
    class Config;
}

namespace tooie::mix_rate {
    // Sound > Mix rate: Original (22 kHz) or High (44 kHz). Read once, when the game sets up its sound.
    void add_option(recomp::config::Config& sound);

    // RDRAM holding the game's sound memory while High is in use (above the 8 MB a save state copies),
    // as a physical address and size. The size is 0 at the original rate.
    uint32_t extra_region_start();
    uint32_t extra_region_size();
}

#endif
