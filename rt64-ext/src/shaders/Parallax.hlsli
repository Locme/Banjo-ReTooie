//
// RT64
//

// Banjo-Tooie: parallax mapping on stone. The N64's textures carry no height, so a texture's own brightness stands in
// for it: the dark parts (the gaps between stones, cracks, the shade under a ledge) lie deeper than the light faces.
// Each pixel follows the view ray from its place on the flat triangle down into that height field, a step at a time,
// and the textures are then looked up where the ray meets it, so the faces of the stones stand out of the wall and
// hide the gaps behind them as the camera moves. The triangle's own place and slope come from the camera's terms
// (ComputeSceneGrass) and the pixel's depth, as for deep snow, so the game's models need nothing new.

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_SHADERS_PARALLAX_HLSLI
#define RT64_EXT_SHADERS_PARALLAX_HLSLI

#include "FbRendererCommon.hlsli"
#include "TextureSampler.hlsli"

// The view space position at a pixel (the camera at the origin, looking down -z), from its depth, as
// ScenePixelWorldPosition finds it before it goes to world space.
// With the camera of the draw's own framebuffer (RASTER_PARALLAX_CAMERA, FrameParams.parallaxCameras).
float3 ParallaxViewPosition(float4 pixelPosition, uint bits) {
    // (Eight cameras: bits 0 and 1 in RASTER_PARALLAX_CAMERA, bit 2 in RASTER_PARALLAX_CAMERA_HIGH.)
    const uint camera = ((bits & RASTER_PARALLAX_CAMERA) >> RASTER_PARALLAX_CAMERA_SHIFT) | (((bits & RASTER_PARALLAX_CAMERA_HIGH) != 0u) ? 4u : 0u);
    const float4 t = FrParams.parallaxCameras[camera * 2];
    const float ndcZ = pixelPosition.z * 2.0f - 1.0f;
    const float z = (t.y - ndcZ * t.w) / (ndcZ * t.z - t.x);
    const float4 p = FrParams.parallaxCameras[camera * 2 + 1];
    const float2 ndc = float2(pixelPosition.x / p.z * 2.0f - 1.0f, 1.0f - pixelPosition.y / p.w * 2.0f);
    return float3(ndc.x * -z / p.x, ndc.y * -z / p.y, z);
}

// The tile to look up a texture pack's height map with: as the texture's own tile, scaled to the height map's size.
GPUTile ParallaxHeightTile(GPUTile gpuTile) {
    GPUTile heightTile = gpuTile;
    const float2 scale = gpuTile.heightDimensions / max(gpuTile.textureDimensions.xy, float2(1.0f, 1.0f));
    heightTile.tcScale = gpuTile.tcScale * scale;
    heightTile.ulScale = gpuTile.ulScale * scale;
    heightTile.textureIndex = gpuTile.heightIndex;
    heightTile.textureDimensions = float3(gpuTile.heightDimensions, 1.0f);
    heightTile.flags = gpuTile.flags & ~(0x8u | 0x10u);
    return heightTile;
}

// How deep the texture's surface lies at a place on it, 0 (the top) to 1 (the deepest): from a texture pack's height map
// (white high, black deep), or else from the texture's brightness within its own range (x its darkest, y its lightest),
// in the texture's shape (RASTER_PARALLAX_SHAPE_*, picked per texture in pick mode).
float ParallaxDepthAt(OtherMode otherMode, RenderFlags renderFlags, float2 uv, float2 ddxUV, float2 ddyUV, RDPTile rdpTile, GPUTile gpuTile, float2 range, bool heightMap, uint shape) {
    const float4 c = sampleTexture(otherMode, renderFlags, uv, ddxUV, ddyUV, rdpTile, gpuTile, false);
    if (heightMap) {
        return saturate(1.0f - c.r);
    }

    float luma = dot(c.rgb, float3(0.299f, 0.587f, 0.114f));
    // Sand and Smooth: the brightness blurred over about a texel and a half, so the surface has no stair steps where a
    // small texture's texels meet (jaggies), at four more lookups a step.
    if (shape >= 14u) {
        const float2 o = float2(0.75f, -0.75f);
        luma *= 0.2f;
        luma += 0.2f * dot(sampleTexture(otherMode, renderFlags, uv + o.xx, ddxUV, ddyUV, rdpTile, gpuTile, false).rgb, float3(0.299f, 0.587f, 0.114f));
        luma += 0.2f * dot(sampleTexture(otherMode, renderFlags, uv + o.xy, ddxUV, ddyUV, rdpTile, gpuTile, false).rgb, float3(0.299f, 0.587f, 0.114f));
        luma += 0.2f * dot(sampleTexture(otherMode, renderFlags, uv + o.yx, ddxUV, ddyUV, rdpTile, gpuTile, false).rgb, float3(0.299f, 0.587f, 0.114f));
        luma += 0.2f * dot(sampleTexture(otherMode, renderFlags, uv + o.yy, ddxUV, ddyUV, rdpTile, gpuTile, false).rgb, float3(0.299f, 0.587f, 0.114f));
    }
    const float darkness = saturate((range.y - luma) / max(range.y - range.x, 0.05f));
    switch (shape) {
    // Bumpy: the whole surface follows its brightness (rough rock, bark).
    case 1u:
        return darkness;
    // Inverted: the light parts lie deep (carvings whose grooves are lighter).
    case 2u:
        return smoothstep(0.65f, 0.95f, 1.0f - darkness);
    // Cracks: only the darkest lines sink (cracked floors, mortar); the faces stay put.
    case 3u:
        return smoothstep(0.85f, 0.98f, darkness);
    // Terraced: a few flat steps (bricks, tiles, stacked slabs).
    case 4u: {
        const float s = darkness * 3.0f;
        const float f = min(floor(s), 2.0f);
        return (f + smoothstep(0.4f, 0.6f, s - f)) / 3.0f;
    }
    // Rounded: the faces bulge like pebbles or cobbles, steep only near the gaps.
    case 5u:
        return 1.0f - sqrt(saturate(1.0f - darkness));
    // Grass: the light blade tips stand up and the dark ground between them lies deep, steeply.
    case 6u:
        return pow(smoothstep(0.15f, 0.85f, darkness), 0.8f);
    // Wood: a shallow grain, with the dark gaps between planks sunk deep.
    case 7u:
        return 0.35f * darkness + 0.65f * smoothstep(0.8f, 0.97f, darkness);
    // Bark: deep furrows with steep sides between the ridges.
    case 8u:
        return sqrt(smoothstep(0.2f, 0.9f, darkness));
    // Brick: flat bricks with bevelled edges and a wide band of mortar sunk between them.
    case 9u:
        return smoothstep(0.5f, 0.7f, darkness);
    // Dirt: soft, shallow lumps (paths, sand, mud).
    case 10u:
        return 0.5f * smoothstep(0.0f, 1.0f, darkness);
    // Metal: flat plates; only the darkest seams sink.
    case 11u:
        return smoothstep(0.92f, 1.0f, darkness);
    // Leaves: overlapping leaves, rounded with the shade under each sunk.
    case 12u:
        return 1.0f - (1.0f - darkness) * (1.0f - darkness);
    // Tiles: flat tiles and a narrow, sharp line of grout.
    case 13u:
        return smoothstep(0.75f, 0.85f, darkness);
    // Sand: low, soft ripples from the blurred brightness.
    case 14u:
        return 0.4f * smoothstep(0.1f, 0.9f, darkness);
    // Smooth: Bumpy's full depth from the blurred brightness, with no stair steps.
    case 15u:
        return smoothstep(0.0f, 1.0f, darkness);
    // Ice: a clear top layer with the pattern seen inside it: nothing stands at the surface, the frost and bubbles
    // (the light parts) lie just under it and the dark parts deep down, softly (from the blurred brightness).
    case 16u:
        return 0.3f + 0.7f * smoothstep(0.0f, 1.0f, darkness);
    // Stone: the speckle on a stone's face isn't its shape, so most of it is one flat top and only the darkest parts
    // (the gaps, cracks and the shade under a ledge) sink, steeply at their edges.
    default:
        return smoothstep(0.65f, 0.95f, darkness);
    }
}

// How far to move the texture coordinates at this pixel so the textures show the place the view ray meets the height
// field (xy), and how lit that place is (z): darker deep down and in the shadow the stones above it cast, with the
// light from straight up in the world. No change where it is flat: seen edge on, or far away.
float3 ParallaxOffset(OtherMode otherMode, RenderFlags renderFlags, float4 pixelPosition, float2 uv, float2 ddxUV, float2 ddyUV, RDPTile rdpTile, GPUTile gpuTile, float2 range, uint bits) {
    // The texture's own shape, depth and shadows (RasterParams.nightLight, rt64_raster_params.h).
    const uint shape = ((bits >> 25) & 0x7u) | (((bits & RASTER_PARALLAX_SHAPE_HIGH) != 0) ? 8u : 0u) | (((bits & RASTER_PARALLAX_SHAPE_TOP) != 0) ? 16u : 0u);
    float4 params = FrParams.parallaxParams;
    const uint fineDepth = (bits & RASTER_PARALLAX_FINE_DEPTH) >> RASTER_PARALLAX_FINE_DEPTH_SHIFT;
    params.x *= (fineDepth != 0) ? (float(fineDepth) * 0.1f) : 1.0f;
    const float4 shading = ((bits & RASTER_PARALLAX_NO_SHADOWS) != 0) ? float4(0.0f, 0.0f, 0.0f, 0.0f) : FrParams.parallaxShading;
    const float3 p = ParallaxViewPosition(pixelPosition, bits);
    const float3 dp1 = ddx(p);
    const float3 dp2 = ddy(p);
    const float distance = length(p);
    float3 n = cross(dp1, dp2);
    const float nLength = length(n);
    // Written as "go on only if it is a real value", so a NaN or infinite place (the camera's terms giving none) stops
    // here too instead of marching on into a black surface. Plain compares, no isfinite on the march's result: that
    // made every pipeline several times bigger to compile.
    if (!(nLength > 1e-12f) || !(distance > 1e-4f) || !(distance < 1e30f) || (params.x <= 0.0f)) {
        return float3(0.0f, 0.0f, 1.0f);
    }

    // The triangle's normal, turned toward the camera, and the way to the camera.
    n /= nLength;
    const float3 v = -p / distance;
    if (dot(n, v) < 0.0f) {
        n = -n;
    }
    const float vn = dot(n, v);
    const float fade = saturate((vn - 0.2f) / 0.35f) * (1.0f - smoothstep(params.y, params.z, distance));
    if (!(fade > 0.0f)) {
        return float3(0.0f, 0.0f, 1.0f);
    }

    // How the texture coordinates change along the triangle: their slopes in view space (a frame worked out from the
    // screen-space derivatives, as in Schüler's "Normal Mapping Without Precomputed Tangents").
    const float3 dp2perp = cross(dp2, n);
    const float3 dp1perp = cross(n, dp1);
    const float det = dot(dp1, dp2perp);
    if (abs(det) <= 1e-12f) {
        return float3(0.0f, 0.0f, 1.0f);
    }
    const float3 gu = (dp2perp * ddxUV.x + dp1perp * ddyUV.x) / det;
    const float3 gv = (dp2perp * ddxUV.y + dp1perp * ddyUV.y) / det;

    const bool heightMap = gpuTileFlagHasHeight(gpuTile.flags);
    GPUTile heightTile = gpuTile;
    if (heightMap) {
        heightTile = ParallaxHeightTile(gpuTile);
    }
    const float depthScale = params.x * fade;

    // Going down the view ray to the deepest part, the place on the surface it passes under moves this far.
    const float3 lateral = (n - v / max(vn, 0.3f)) * depthScale;
    float2 uvFull = float2(dot(gu, lateral), dot(gv, lateral));

    // No more than a few texels across, however slanted the view: further, a wall seen at a slant smears the stones
    // sideways into streaks (L: walls looked worse than without it).
    const float maxTexels = params.x * 0.3f;
    const float uvLength = length(uvFull);
    if (uvLength > maxTexels) {
        uvFull *= maxTexels / uvLength;
    }

    // Down the ray in even steps (more of them seen at a slant) until it goes under the surface, then halving the
    // last step to find where the two cross.
    const float steps = lerp(params.w, 8.0f, vn);
    const float stepSize = 1.0f / steps;
    float layer = 0.0f;
    float surface = ParallaxDepthAt(otherMode, renderFlags, uv, ddxUV, ddyUV, rdpTile, heightTile, range, heightMap, shape);
    float previousLayer = 0.0f;
    float previousSurface = surface;
    [loop]
    for (uint i = 0; (i < 48) && (layer < surface); i++) {
        previousLayer = layer;
        previousSurface = surface;
        layer = min(layer + stepSize, 1.0f);
        surface = ParallaxDepthAt(otherMode, renderFlags, uv + uvFull * layer, ddxUV, ddyUV, rdpTile, heightTile, range, heightMap, shape);
    }

    [loop]
    for (uint j = 0; (j < 4) && (layer > previousLayer); j++) {
        const float middle = (previousLayer + layer) * 0.5f;
        const float middleSurface = ParallaxDepthAt(otherMode, renderFlags, uv + uvFull * middle, ddxUV, ddyUV, rdpTile, heightTile, range, heightMap, shape);
        if (middle < middleSurface) {
            previousLayer = middle;
            previousSurface = middleSurface;
        }
        else {
            layer = middle;
            surface = middleSurface;
        }
    }

    const float after = surface - layer;
    const float before = previousSurface - previousLayer;
    const float share = (before - after > 1e-5f) ? saturate(before / (before - after)) : 1.0f;
    const float hit = lerp(previousLayer, layer, share);
    const float2 hitUV = uv + uvFull * hit;

    // Shade: darker the deeper it is, and in shadow where the surface rises between it and the light (straight up in
    // the world, tipped a little toward the camera so the shadows fall where they can be seen).
    float lit = 1.0f - shading.x * hit;
    const float3 up = normalize(FrParams.grassWorldY.xyz);
    const float3 l = normalize(up + v * 0.35f);
    const float nl = dot(n, l);
    if ((shading.y > 0.0f) && (nl > 0.05f) && (hit > 0.02f)) {
        const float3 lateralLight = (l - n * nl) / max(nl, 0.25f) * depthScale;
        float2 uvLight = float2(dot(gu, lateralLight), dot(gv, lateralLight));
        const float uvLightLength = length(uvLight);
        if (uvLightLength > maxTexels) {
            uvLight *= maxTexels / uvLightLength;
        }
        float shadow = 0.0f;
        [loop]
        for (uint k = 1; k <= 6; k++) {
            const float rise = hit * (float(k) / 6.0f);
            const float rayLayer = hit - rise;
            const float s = ParallaxDepthAt(otherMode, renderFlags, hitUV + uvLight * rise, ddxUV, ddyUV, rdpTile, heightTile, range, heightMap, shape);
            shadow = max(shadow, saturate((rayLayer - s) * 3.0f) * (1.0f - float(k - 1) / 6.0f));
        }
        lit *= 1.0f - shading.y * shadow;
    }

    return float3(uvFull * hit, lerp(1.0f, lit, fade));
}

#endif // RT64_EXT_SHADERS_PARALLAX_HLSLI
