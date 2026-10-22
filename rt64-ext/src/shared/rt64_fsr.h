//
// RT64
//

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_SHARED_RT64_FSR_H
#define RT64_EXT_SHARED_RT64_FSR_H

#include "shared/rt64_hlsl.h"

#ifdef HLSL_CPU
namespace interop {
#endif
    struct FsrCB {
        // FsrEasuCon's four constants for the upscale, or FsrRcasCon's in con0 for the sharpening.
        uint4 con0;
        uint4 con1;
        uint4 con2;
        uint4 con3;
    };
#ifdef HLSL_CPU
};
#endif

#endif // RT64_EXT_SHARED_RT64_FSR_H
