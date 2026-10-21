//
// RT64
//
// Banjo-Tooie: what rt64_raster_shader_cache.cpp (lib-patches/rt64.patch) uses of the shader list in
// rt64_raster_shader_cache_ext.cpp.

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_RENDER_RT64_RASTER_SHADER_CACHE_EXT_H
#define RT64_EXT_RENDER_RT64_RASTER_SHADER_CACHE_EXT_H

#include <atomic>
#include <cstdint>

namespace RT64 {
    namespace shaderlistext {
        // Far more than a full playthrough meets; past it, nothing more is added.
        constexpr uint32_t ShaderListLimit = 50000;
        // Shaders from the list compiled so far, and how many it queued (GetShaderListProgress).
        extern std::atomic<uint32_t> listProgressDone;
        extern std::atomic<uint32_t> listProgressTotal;
    }
    using namespace shaderlistext;
}

#endif // RT64_EXT_RENDER_RT64_RASTER_SHADER_CACHE_EXT_H
