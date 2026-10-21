//
// RT64
//

#pragma once

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
