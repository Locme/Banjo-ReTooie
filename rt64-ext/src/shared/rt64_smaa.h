//
// RT64
//

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_SHARED_RT64_SMAA_H
#define RT64_EXT_SHARED_RT64_SMAA_H

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

#endif // RT64_EXT_SHARED_RT64_SMAA_H
