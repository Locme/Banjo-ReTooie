// The barebone build's stand-in for snout_jiggle.cpp. The jiggle physics are left out, so the game's
// own model and animation are drawn as they are. The hooks still exist, so the recompiled game links.
#include <cstdint>

#include "recomp.h"
#include "tooie_hooks.h"
#include "tooie_snout_jiggle.h"

namespace tooie::snout_jiggle {
    // Nothing is rewritten here, so frame interpolation has nothing to blend.
    bool blend_vertices(uint32_t) { return false; }
}

extern "C" void tooie_snout_model([[maybe_unused]] uint8_t* rdram, [[maybe_unused]] recomp_context* ctx) {
}

extern "C" void tooie_snout_bone([[maybe_unused]] uint8_t* rdram, [[maybe_unused]] recomp_context* ctx) {
}
