//
// RT64
//

// Banjo-Tooie: AMD FidelityFX Super Resolution 1 on the finished game image, just before the VI draws it.
// ffx_a.h and ffx_fsr1.h are AMD's (MIT), kept in the game's repository under lib/fsr. FSR_PASS_EASU
// upscales to the window's size, FSR_PASS_RCAS sharpens the upscaled image.

#include "shared/rt64_fsr.h"

[[vk::push_constant]] ConstantBuffer<FsrCB> gConstants : register(b0);

Texture2D<float4> gTexture0 : register(t1);
Texture2D<float4> gTexture1 : register(t2);
Texture2D<float4> gTexture2 : register(t3);
SamplerState LinearSampler : register(s4);
SamplerState PointSampler : register(s5);

#define A_GPU 1
#define A_HLSL 1
#include "ffx_a.h"

#if defined(FSR_PASS_EASU)
#   define FSR_EASU_F 1
// The 2x2 texels around p in Gather's order (x: bottom-left, y: bottom-right, z: top-right, w: top-left),
// read one by one: Gather isn't reliable on every driver here.
float4x4 gatherTexels(float2 p) {
    const float2 texel = asfloat(gConstants.con1.xy);
    const float2 topLeft = p - 0.5 * texel;
    return float4x4(
        gTexture0.SampleLevel(PointSampler, topLeft + float2(0.0, texel.y), 0),
        gTexture0.SampleLevel(PointSampler, topLeft + texel, 0),
        gTexture0.SampleLevel(PointSampler, topLeft + float2(texel.x, 0.0), 0),
        gTexture0.SampleLevel(PointSampler, topLeft, 0));
}

AF4 FsrEasuRF(AF2 p) { const float4x4 t = gatherTexels(p); return AF4(t[0].r, t[1].r, t[2].r, t[3].r); }
AF4 FsrEasuGF(AF2 p) { const float4x4 t = gatherTexels(p); return AF4(t[0].g, t[1].g, t[2].g, t[3].g); }
AF4 FsrEasuBF(AF2 p) { const float4x4 t = gatherTexels(p); return AF4(t[0].b, t[1].b, t[2].b, t[3].b); }
#else
#   define FSR_RCAS_F 1
AF4 FsrRcasLoadF(ASU2 p) { return gTexture0.Load(int3(p, 0)); }
void FsrRcasInputF(inout AF1 r, inout AF1 g, inout AF1 b) { }
#endif

#include "ffx_fsr1.h"

float4 PSMain(in float4 pos : SV_Position, in float2 uv : TEXCOORD0) : SV_TARGET {
    const AU2 ip = AU2(pos.xy);
#if defined(FSR_PASS_EASU)
    AF3 color;
    FsrEasuF(color, ip, gConstants.con0, gConstants.con1, gConstants.con2, gConstants.con3);
    return float4(color, 1.0f);
#else
    AF1 r, g, b;
    FsrRcasF(r, g, b, ip, gConstants.con0);
    return float4(r, g, b, 1.0f);
#endif
}
