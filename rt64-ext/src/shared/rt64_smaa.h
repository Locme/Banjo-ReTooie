//
// RT64
//

#pragma once

#include "shared/rt64_hlsl.h"

#ifdef HLSL_CPU
namespace interop {
#endif
    struct SmaaCB {
        // 1 / width, 1 / height, width, height of the game image.
        float4 rtMetrics;
    };
#ifdef HLSL_CPU
};
#endif
