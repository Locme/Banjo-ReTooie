//
// RT64
//

#pragma once

#include <cstdint>

namespace RT64 {
    // Banjo-Tooie: the temporal upscaler chosen in Graphics (src/display/upscaler.cpp).
    // Mode: 0 off, 1 FSR 4, 2 FSR 4 native AA, 3 DLSS, 4 DLAA, 5 Arm ASR, 6 Snapdragon GSR (Android), 7 FSR 3.
    void SetUpscalerMode(uint32_t mode);
    uint32_t GetUpscalerMode();
};
