// Honeycombs Stay (WIP, L 2026-10-25).
//
// The health honeycombs that enemies and breakables drop are chhoney objects (actors 0x22B and 0x22C, models 0x704
// and 0x705). func_80800244 (the object's init, decomp: chhoney) sets a 20 second timer in the float at +0x28, and
// func_80800EB0, run first thing every frame by the update (func_80800A5C), counts it down and, when it runs out,
// makes the comb vanish (func_80089CA8). Combs placed in the world have bit 5 of the word at +0x78 set and are
// skipped. With Honeycombs Stay on, the check is skipped, so a comb stays until Banjo takes it, the area is left or
// the game's own limit (10 dropped combs; the 11th removes the oldest, func_8080046C and func_80800688) pushes it out.

#include "recomp.h"
#include "recompui/config.h"
#include "tooie_honeycomb_cap.h"

namespace {
    bool enabled() {
        try {
            return std::get<bool>(recompui::config::get_general_config().get_option_value(tooie::honeycomb_cap::option));
        } catch (...) {
            return false;
        }
    }
}

// func_80800EB0 entry (chhoney's expiry check): 1 skips it, so the comb doesn't run out.
extern "C" int tooie_honeycomb_no_expire(uint8_t* rdram, recomp_context* ctx) {
    return enabled() ? 1 : 0;
}
