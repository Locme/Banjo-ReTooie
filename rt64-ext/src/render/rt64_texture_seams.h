//
// RT64
//

#pragma once
#ifndef RT64_EXT_RENDER_RT64_TEXTURE_SEAMS_H
#define RT64_EXT_RENDER_RT64_TEXTURE_SEAMS_H

#include <cstddef>
#include <cstdint>
#include <vector>

#include "shared/rt64_hlsl.h"

namespace RT64 {
    // Banjo-Tooie: Blend texture seams, the pieces of a picture drawn in clamped tiles (the title's logo, the flight
    // pads, cliff faces): the points on each texel edge of the piece (x and y on the screen and w, in clip space, with
    // the texel along the edge), to find the pieces sharing an edge with it after this framebuffer's draws.
    struct SeamPoint {
        interop::float3 position;
        // Which edges of the piece's texels it is on (bits: 1 s low, 2 s high, 4 t low, 8 t high), and its texel.
        uint32_t edges;
        float u, t;
    };
    struct SeamPiece {
        uint32_t instance;
        uint32_t tile;
        uint32_t width, height;
        uint32_t pointStart, pointCount;
        // The texture's format and size, the same for the pieces of one picture.
        uint32_t format;
        // In the 3D world (the top bit of its neighbours' tile indices).
        bool world;
        // The material's shader: a picture drawn twice in layers (a Split-Up pad's) pairs within each layer.
        uint64_t shader;
    };

    // Fills instanceSeamVector (one entry per draw instance, RASTER_SEAM_NONE where a piece has no neighbour) with the tile
    // of each piece's neighbour along its right, lower, left and upper edges. FramebufferRenderer::addFramebuffer collects
    // the pieces and points of a framebuffer's draws, then calls this. TOOIE_SEAM_LOG=1 prints the joins now and then.
    void FindTextureSeams(const std::vector<SeamPiece> &seamPieces, const std::vector<SeamPoint> &seamPoints, size_t instanceCount,
        std::vector<interop::uint4> &instanceSeamVector);
}

#endif
