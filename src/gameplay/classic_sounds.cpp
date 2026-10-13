#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <variant>

#include "recomp.h"
#include "recompui/config.h"

#include "tooie_classic_sounds.h"

namespace {
    // The jump sound table in main data: three halfwords, found by scanning RDRAM for the ids.
    constexpr uint32_t table_addr = 0x80119208;
    constexpr uint16_t tooie_ids[3] = {0x057C, 0x057D, 0x057E};
    constexpr uint16_t classic_ids[3] = {0x043B, 0x043C, 0x043D};

    uint16_t* slot(uint8_t* rdram, int i) {
        // Halfwords sit at address ^ 2 in the byte-swapped RDRAM.
        return reinterpret_cast<uint16_t*>(rdram + (((table_addr + 2 * i) ^ 2) & 0x7FFFFF));
    }

    bool want_classic() {
        static const bool forced = std::getenv("TOOIE_CLASSIC_SOUNDS") != nullptr;
        if (forced) {
            return true;
        }
        try {
            return std::get<bool>(recompui::config::get_general_config().get_option_value(tooie::classic_sounds::option));
        } catch (...) {
            return false;
        }
    }
}

namespace tooie::classic_sounds {
    void tick(uint8_t* rdram) {
        const bool classic = want_classic();
        const uint16_t* from = classic ? tooie_ids : classic_ids;
        const uint16_t* to = classic ? classic_ids : tooie_ids;
        // Only touch the table while it holds one of the two sets, so a different overlay or area in the
        // same memory is never overwritten.
        bool match = true;
        for (int i = 0; i < 3; i++) {
            match = match && *slot(rdram, i) == from[i];
        }
        if (!match) {
            return;
        }
        for (int i = 0; i < 3; i++) {
            *slot(rdram, i) = to[i];
        }
        if (std::getenv("TOOIE_SOUND_LOG")) {
            std::fprintf(stderr, "[classic-sounds] jump table now %X %X %X\n", to[0], to[1], to[2]);
        }
    }
}
