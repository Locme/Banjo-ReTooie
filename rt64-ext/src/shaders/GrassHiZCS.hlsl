//
// RT64
//

// Banjo-Tooie: instanced 3D grass's depth pyramid (rt64_grass_instances.h), built once the frame's 3D world is drawn
// and read by the next frame's culling pass (GrassCullCS.hlsl): each texel keeps the farthest depth under it. Built
// from the depth target into the fine level (GRASS_HIZ_FINE pixels across a texel; MULTISAMPLING reads each pixel's
// samples), or with COARSE_PASS from the fine level into the coarse one (GRASS_HIZ_COARSE fine texels across).

#include "shared/rt64_grass_instances.h"

[[vk::push_constant]] ConstantBuffer<GrassHiZCB> gConstants : register(b0);

#ifdef MULTISAMPLING
Texture2DMS<float> gSource : register(t1);
#else
Texture2D<float> gSource : register(t1);
#endif
RWTexture2D<float> gTarget : register(u2);

#ifdef COARSE_PASS
#define GRASS_HIZ_SPAN GRASS_HIZ_COARSE
#else
#define GRASS_HIZ_SPAN GRASS_HIZ_FINE
#endif

[numthreads(8, 8, 1)]
void CSMain(uint2 texel : SV_DispatchThreadID) {
    if (any(texel >= gConstants.targetSize)) {
        return;
    }

    const uint2 first = texel * GRASS_HIZ_SPAN;
    const uint2 last = min(first + GRASS_HIZ_SPAN, gConstants.sourceSize);
    float farthest = 0.0f;
    for (uint y = first.y; y < last.y; y++) {
        for (uint x = first.x; x < last.x; x++) {
#if defined(COARSE_PASS)
            farthest = max(farthest, gSource.Load(int3(x, y, 0)));
#elif defined(MULTISAMPLING)
            uint width, height, samples;
            gSource.GetDimensions(width, height, samples);
            for (uint s = 0; s < samples; s++) {
                farthest = max(farthest, gSource.Load(int2(x, y), s));
            }
#else
            farthest = max(farthest, gSource.Load(int3(x, y, 0)));
#endif
        }
    }

    gTarget[texel] = farthest;
}
