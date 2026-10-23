//
// RT64
//

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_RENDER_RT64_DLSS_H
#define RT64_EXT_RENDER_RT64_DLSS_H

#include <cstdint>
#include <string>

#include "common/rt64_common.h"
#include "common/rt64_plume.h"

namespace RT64 {
    // Banjo-Tooie: NVIDIA DLSS (and DLAA, the same model at the output's own size) through NGX, on Windows with Direct3D 12.
    // The NGX library (third-party/nvidia-dlss, NVIDIA's licence) and nvngx_dlss.dll are NVIDIA's; neither is on other platforms.
    struct DlssBackend {
        // Records DLSS on the command list. color is the jittered game image at inputWidth by inputHeight, depth a float depth
        // (R32), motion the velocity (previous minus current, pixels) at the same size, output outputWidth by outputHeight
        // with unordered access. Returns false (and says why on the console, once) when it cannot: no Direct3D 12, no RTX
        // card, no nvngx_dlss.dll, an old driver. quality: 0 Quality, 1 Balanced, 2 Performance, 3 Ultra Performance;
        // native true for DLAA.
        bool evaluate(RenderDevice *device, RenderCommandList *commandList, RenderTexture *color, RenderTexture *depth, RenderTexture *motion,
            RenderTexture *output, uint32_t inputWidth, uint32_t inputHeight, uint32_t outputWidth, uint32_t outputHeight,
            float jitterX, float jitterY, bool reset, uint32_t quality, bool native, bool hdr);

        // True once DLSS has been found unusable; the caller then uses another resolve.
        bool unavailable() const { return failed; }

        // Why, for the log.
        std::string reason;

        ~DlssBackend();

    private:
        bool failed = false;
        bool initialized = false;
        void *params = nullptr;
        void *feature = nullptr;
        uint32_t featureInputWidth = 0;
        uint32_t featureInputHeight = 0;
        uint32_t featureOutputWidth = 0;
        uint32_t featureOutputHeight = 0;
        uint32_t featureQuality = 0;
        bool featureNative = false;
        bool featureHdr = false;
        void *deviceUsed = nullptr;

        void fail(const std::string &why);
    };
};

#endif // RT64_EXT_RENDER_RT64_DLSS_H
