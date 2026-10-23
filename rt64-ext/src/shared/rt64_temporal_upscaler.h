//
// RT64
//

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_SHARED_RT64_TEMPORAL_UPSCALER_H
#define RT64_EXT_SHARED_RT64_TEMPORAL_UPSCALER_H

#include "shared/rt64_hlsl.h"

#ifdef HLSL_CPU
namespace interop {
#endif
    struct UpscalerVelocityCB {
        // The rows of the matrix that takes a view-space position of this frame to the previous frame's clip
        // space (row vectors: clip = position * M).
        float4 reproject0;
        float4 reproject1;
        float4 reproject2;
        float4 reproject3;
        // The projection's depth terms (as the scene effects use them), its x and y scale, then the target's size.
        float4 depthTerms;
        float4 projection;
        // x: 1 to draw the velocity as a picture, y: that picture's scale in pixels per full colour step, z: whether
        // the depth is the colour copy of RT64's depth target (1) or a plain float depth (0).
        float4 flags;
    };

    struct UpscalerResolveCB {
        // The game image's size, then the output's.
        float4 sizes;
        // x, y: the jitter the image was drawn with, in input pixels (x right, y down); z: 1 when there is a
        // history to blend with; w: how much of the new image goes into the result when there is.
        float4 jitter;
    };
#ifdef HLSL_CPU
};
#endif

#endif // RT64_EXT_SHARED_RT64_TEMPORAL_UPSCALER_H
