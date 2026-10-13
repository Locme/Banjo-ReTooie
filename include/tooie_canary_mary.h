#ifndef __TOOIE_CANARY_MARY_H__
#define __TOOIE_CANARY_MARY_H__

#include <cstdint>
#include <string>

// Canary Mary rubber banding (src/gameplay/canary_mary.cpp, handoff 4.53).
namespace tooie::canary_mary {
    enum class Mode : uint32_t { Original, Fair, Easy };
    inline const std::string mode_option = "canary_mary";
}

#endif
