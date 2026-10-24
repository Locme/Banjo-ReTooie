//
// RT64
//

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_SHARED_RT64_VOLUMETRIC_SHADOWS_H
#define RT64_EXT_SHARED_RT64_VOLUMETRIC_SHADOWS_H

#include "shared/rt64_hlsl.h"

// Banjo-Tooie: volumetric shadows (rt64_volumetric_shadows.cpp, WIP tab). Light in the air with the shadows of the
// scenery cut out of it, by Billeter, Sintorn and Assarsson's polygonal light volumes ("Real Time Volumetric Shadows
// using Polygonal Light Volumes", HPG 2010): a depth map is drawn from the light, a closed mesh is raised from it that
// holds exactly the air the light reaches, and that mesh is drawn over the picture with each of its faces adding (where
// the eye's ray leaves the lit air) or taking away (where it enters) the light gathered from the camera up to the face.
// What is left at each pixel is the light from the lit stretches of its ray only. Its own maps, mesh and passes: it uses
// nothing of the sun shadows or of ray tracing.

// Passes (VolShadowCB.medium.z).
#define VOL_SHADOW_PASS_SUN 0
#define VOL_SHADOW_PASS_LAMP 1

// The lamps' maps: six faces each (a cube round the lamp), laid out three across and two down, one lamp after the other.
#define VOL_SHADOW_MAX_LAMPS 2

#ifdef HLSL_CPU
namespace interop {
#endif
    struct VolShadowCB {
        // A view-space position's world position: dot(position, xyz) + w (as SceneEffectsCB).
        float4 worldX;
        float4 worldY;
        float4 worldZ;
        // The projection's depth terms (as SceneEffectsCB, corrected for the viewport), then its x and y scales and the
        // full picture's width and height.
        float4 depthTerms;
        float4 projection;
        // World to clip space: clip.x = dot(float4(world, 1), clipX) and so on.
        float4 clipX;
        float4 clipY;
        float4 clipZ;
        float4 clipW;
        // The light. The sun: its map's axes in the world (across, up the map, towards the sun) with the map's half width,
        // its reach towards and away from the sun, its size in texels, then the map's middle and the mesh's cells a side.
        // A lamp: lightA its position and radius; lightB the map's near and far distances, a face's size in texels and the
        // face being drawn (map pass) or the lamp's brightness (volume pass); lightC the lamp's first texel across in the
        // map, unused, the mesh's cells a face side, unused.
        float4 lightA;
        float4 lightB;
        float4 lightC;
        float4 lightD;
        // How fast the haze gathers light (per world unit), how far the sky counts as, the pass (VOL_SHADOW_PASS_*; the
        // composite's view instead), then how many picture pixels a side each pixel of the gathered light covers (1 or 2).
        float4 medium;
        // The sun's light in the haze (rgb, strength folded in), then the haze's forward scattering (0 to 0.9).
        float4 sunColor;
        // The light the shaded haze still gets from the sky (rgb), then how much of the picture behind it the haze hides
        // (extinction per world unit).
        float4 ambient;
    };
#ifdef HLSL_CPU
    // Push constants: Vulkan guarantees only 256 bytes (NVIDIA allows no more), and going over can lose the device.
    static_assert(sizeof(VolShadowCB) <= 256, "VolShadowCB is bigger than the 256 bytes of push constants");
};
#endif

#endif // RT64_EXT_SHARED_RT64_VOLUMETRIC_SHADOWS_H
