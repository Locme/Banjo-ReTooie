//
// RT64
//

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_RENDER_RT64_FFX_UPSCALER_H
#define RT64_EXT_RENDER_RT64_FFX_UPSCALER_H

#include <cstdint>
#include <string>

#include "common/rt64_common.h"
#include "common/rt64_plume.h"

namespace RT64 {
    // Banjo-Tooie: AMD FSR 3 and FSR 4 through the FidelityFX upscaler DLLs (Windows, Direct3D 12). The DLLs
    // (amd_fidelityfx_loader_dx12.dll and amd_fidelityfx_upscaler_dx12.dll, third-party/amd-fsr) are AMD's and are
    // loaded when first needed; with them missing, or FSR 4 on a card that cannot run it, evaluate() returns false.
    struct FfxBackend {
        // Same inputs as DlssBackend::evaluate. fsr4 picks the FSR 4 provider (machine learning), else FSR 3.
        // nearPlane, farPlane and fovY (radians) are the camera's, for the upscaler's depth tests.
        bool evaluate(RenderDevice *device, RenderCommandList *commandList, RenderTexture *color, RenderTexture *depth, RenderTexture *motion,
            RenderTexture *output, uint32_t inputWidth, uint32_t inputHeight, uint32_t outputWidth, uint32_t outputHeight,
            float jitterX, float jitterY, bool reset, bool fsr4, bool native, bool hdr, float nearPlane, float farPlane, float fovY);

        bool unavailable() const { return failed; }
        std::string reason;

        ~FfxBackend();

    private:
        bool failed = false;
        void *module = nullptr;
        void *context = nullptr;
        uint32_t contextInputWidth = 0;
        uint32_t contextInputHeight = 0;
        uint32_t contextOutputWidth = 0;
        uint32_t contextOutputHeight = 0;
        bool contextFsr4 = false;
        bool contextHdr = false;
        void *deviceUsed = nullptr;

        void fail(const std::string &why);
        void destroyContext();
    };
};

#endif // RT64_EXT_RENDER_RT64_FFX_UPSCALER_H
