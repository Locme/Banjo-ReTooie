//
// RT64
//

#pragma once

#include "shared/rt64_hlsl.h"

#ifdef HLSL_CPU
namespace interop {
#endif
    struct PhotoGradeCB {
        // 1 / width, 1 / height, width, height of the game image.
        float4 rtMetrics;
        // Exposure (stops), contrast, saturation, warmth (-1 to 1, 0 leaves the picture alone).
        float4 tone;
        // Vignette (0 to 1), film grain (0 to 1), a time in seconds for the grain, the look (0 none).
        float4 effects;
        // The crop's width / height (0 for none: the outside is shaded), 1 to draw the rule-of-thirds grid, 1 to
        // keep the right half of the picture as it was (F8 compare), then the photo frame's border (0 none, 1 instant
        // photo, 2 film strip, 3 honeycomb, 4 Jiggy, 5 wooden).
        float4 frame;
        // Depth of field strength (0 off, 1 strongest), 1 when the depth texture holds this frame's depth, 1 for
        // an HDR colour buffer, then the sharpening (0 off, 1 strongest).
        float4 dof;
        // Depth of field's focus point as a fraction of the picture (0.5, 0.5 is the middle), then unused.
        float4 focus;
    };
#ifdef HLSL_CPU
};
#endif
