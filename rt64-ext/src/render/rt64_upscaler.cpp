//
// RT64
//

#include "rt64_upscaler.h"

#include <algorithm>
#include <atomic>

namespace RT64 {
    namespace {
        std::atomic<uint32_t> upscalerMode{ 0 };
    }

    void SetUpscalerMode(uint32_t mode) {
        upscalerMode = std::min(mode, 4U);
    }

    uint32_t GetUpscalerMode() {
        return upscalerMode.load();
    }
}
