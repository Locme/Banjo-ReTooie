//
// RT64
//

#include "rt64_ffx_upscaler.h"

#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cstring>
#include <vector>

#if defined(_WIN32) && defined(TOOIE_HAS_FFX)

#include <windows.h>

#include "plume_d3d12.h"

#define _WINDOWS 1
#include "api/include/ffx_api_loader.h"
#include "api/include/dx12/ffx_api_dx12.h"
#include "upscalers/include/ffx_upscale.h"

namespace RT64 {
    namespace {
        ffxFunctions functions = {};

        bool startsWith(const char *text, const char *prefix) {
            return (text != nullptr) && (std::strncmp(text, prefix, std::strlen(prefix)) == 0);
        }

        std::string code(ffxReturnCode_t result) {
            return "FFX error " + std::to_string(result);
        }
    }

    void FfxBackend::fail(const std::string &why) {
        if (!failed) {
            fprintf(stdout, "[upscaler] FSR unavailable: %s\n", why.c_str());
            fflush(stdout);
        }
        failed = true;
        reason = why;
    }

    void FfxBackend::destroyContext() {
        if ((context != nullptr) && (functions.DestroyContext != nullptr)) {
            ffxContext ctx = context;
            functions.DestroyContext(&ctx, nullptr);
        }
        context = nullptr;
    }

    FfxBackend::~FfxBackend() {
        destroyContext();
    }

    bool FfxBackend::evaluate(RenderDevice *device, RenderCommandList *commandList, RenderTexture *color, RenderTexture *depth, RenderTexture *motion,
        RenderTexture *output, uint32_t inputWidth, uint32_t inputHeight, uint32_t outputWidth, uint32_t outputHeight,
        float jitterX, float jitterY, bool reset, bool fsr4, bool native, bool hdr, float nearPlane, float farPlane, float fovY)
    {
        if (failed) {
            return false;
        }

        D3D12Device *d3dDevice = dynamic_cast<D3D12Device *>(device);
        D3D12CommandList *d3dCommandList = dynamic_cast<D3D12CommandList *>(commandList);
        if ((d3dDevice == nullptr) || (d3dCommandList == nullptr)) {
            fail("the renderer is not using Direct3D 12 (set the graphics API to D3D12)");
            return false;
        }

        if (module == nullptr) {
            // The loader finds amd_fidelityfx_upscaler_dx12.dll beside itself.
            HMODULE loaded = LoadLibraryW(L"amd_fidelityfx_loader_dx12.dll");
            if (loaded == nullptr) {
                fail("amd_fidelityfx_loader_dx12.dll / amd_fidelityfx_upscaler_dx12.dll are not beside the game");
                return false;
            }
            module = loaded;
            ffxLoadFunctions(&functions, module);
            if ((functions.CreateContext == nullptr) || (functions.Dispatch == nullptr) || (functions.Query == nullptr)) {
                fail("the FidelityFX loader has no API");
                return false;
            }
            deviceUsed = d3dDevice->d3d;
        }

        const bool contextChanged = (context == nullptr) || (contextInputWidth != inputWidth) || (contextInputHeight != inputHeight) ||
            (contextOutputWidth != outputWidth) || (contextOutputHeight != outputHeight) || (contextFsr4 != fsr4) || (contextHdr != hdr);
        if (contextChanged) {
            destroyContext();

            // The provider: the FSR 4 one for FSR 4 modes, else an FSR 3 one.
            ffxQueryDescGetVersions versionQuery = {};
            versionQuery.header.type = FFX_API_QUERY_DESC_TYPE_GET_VERSIONS;
            versionQuery.createDescType = FFX_API_CREATE_CONTEXT_DESC_TYPE_UPSCALE;
            versionQuery.device = d3dDevice->d3d;
            uint64_t count = 0;
            versionQuery.outputCount = &count;
            ffxReturnCode_t result = functions.Query(nullptr, &versionQuery.header);
            if ((result != FFX_API_RETURN_OK) || (count == 0)) {
                fail("no FSR versions are available (" + code(result) + ")");
                return false;
            }
            std::vector<uint64_t> ids(count);
            std::vector<const char *> names(count);
            versionQuery.versionIds = ids.data();
            versionQuery.versionNames = names.data();
            result = functions.Query(nullptr, &versionQuery.header);
            if (result != FFX_API_RETURN_OK) {
                fail("could not list FSR versions (" + code(result) + ")");
                return false;
            }
            std::string available;
            int chosen = -1;
            for (uint64_t i = 0; i < count; i++) {
                available += std::string(i ? ", " : "") + (names[i] ? names[i] : "?");
                if (chosen < 0 && startsWith(names[i], fsr4 ? "4" : "3")) {
                    chosen = int(i);
                }
            }
            if (chosen < 0) {
                fail(std::string(fsr4 ? "FSR 4" : "FSR 3") + " is not offered by this card or driver (versions: " + available + ")");
                return false;
            }

            ffxOverrideVersion versionOverride = {};
            versionOverride.header.type = FFX_API_DESC_TYPE_OVERRIDE_VERSION;
            versionOverride.versionId = ids[chosen];

            ffxCreateBackendDX12Desc backend = {};
            backend.header.type = FFX_API_CREATE_CONTEXT_DESC_TYPE_BACKEND_DX12;
            backend.device = d3dDevice->d3d;

            ffxCreateContextDescUpscale create = {};
            create.header.type = FFX_API_CREATE_CONTEXT_DESC_TYPE_UPSCALE;
            create.flags = FFX_UPSCALE_ENABLE_AUTO_EXPOSURE | (hdr ? FFX_UPSCALE_ENABLE_HIGH_DYNAMIC_RANGE : FFX_UPSCALE_ENABLE_NON_LINEAR_COLORSPACE);
            create.maxRenderSize = { inputWidth, inputHeight };
            create.maxUpscaleSize = { outputWidth, outputHeight };
            create.fpMessage = [](uint32_t type, const wchar_t *message) {
                fprintf(stdout, "[upscaler] FSR %s: %ls\n", (type == FFX_API_MESSAGE_TYPE_ERROR) ? "error" : "warning", message);
                fflush(stdout);
            };
            create.header.pNext = &backend.header;
            backend.header.pNext = &versionOverride.header;

            ffxContext created = nullptr;
            result = functions.CreateContext(&created, &create.header, nullptr);
            if (result != FFX_API_RETURN_OK) {
                fail(std::string("could not start ") + (fsr4 ? "FSR 4" : "FSR 3") + " (" + code(result) + "; versions: " + available + ")");
                return false;
            }
            context = created;
            contextInputWidth = inputWidth;
            contextInputHeight = inputHeight;
            contextOutputWidth = outputWidth;
            contextOutputHeight = outputHeight;
            contextFsr4 = fsr4;
            contextHdr = hdr;
            fprintf(stdout, "[upscaler] FSR context made: %s (%s), %ux%u to %ux%u%s\n", fsr4 ? "FSR 4" : "FSR 3", names[chosen], inputWidth, inputHeight,
                outputWidth, outputHeight, native ? ", native AA" : "");
            fflush(stdout);
            reset = true;
        }

        static auto lastFrame = std::chrono::steady_clock::now();
        const auto now = std::chrono::steady_clock::now();
        const float frameMs = std::clamp(std::chrono::duration<float, std::milli>(now - lastFrame).count(), 1.0f, 100.0f);
        lastFrame = now;

        D3D12Texture *colorTexture = static_cast<D3D12Texture *>(color);
        D3D12Texture *depthTexture = static_cast<D3D12Texture *>(depth);
        D3D12Texture *motionTexture = static_cast<D3D12Texture *>(motion);
        D3D12Texture *outputTexture = static_cast<D3D12Texture *>(output);

        ffxDispatchDescUpscale dispatch = {};
        dispatch.header.type = FFX_API_DISPATCH_DESC_TYPE_UPSCALE;
        dispatch.commandList = d3dCommandList->d3d;
        dispatch.color = ffxApiGetResourceDX12(colorTexture->d3d, FFX_API_RESOURCE_STATE_COMPUTE_READ);
        dispatch.depth = ffxApiGetResourceDX12(depthTexture->d3d, FFX_API_RESOURCE_STATE_COMPUTE_READ);
        dispatch.motionVectors = ffxApiGetResourceDX12(motionTexture->d3d, FFX_API_RESOURCE_STATE_COMPUTE_READ);
        dispatch.output = ffxApiGetResourceDX12(outputTexture->d3d, FFX_API_RESOURCE_STATE_UNORDERED_ACCESS);
        dispatch.jitterOffset = { jitterX, jitterY };
        dispatch.motionVectorScale = { 1.0f, 1.0f };
        dispatch.renderSize = { inputWidth, inputHeight };
        dispatch.upscaleSize = { outputWidth, outputHeight };
        dispatch.enableSharpening = false;
        dispatch.sharpness = 0.0f;
        dispatch.frameTimeDelta = frameMs;
        dispatch.preExposure = 1.0f;
        dispatch.reset = reset;
        dispatch.cameraNear = nearPlane;
        dispatch.cameraFar = farPlane;
        dispatch.cameraFovAngleVertical = fovY;
        dispatch.viewSpaceToMetersFactor = 1.0f;
        dispatch.flags = hdr ? 0 : FFX_UPSCALE_FLAG_NON_LINEAR_COLOR_SRGB;

        ffxContext ctx = context;
        const ffxReturnCode_t result = functions.Dispatch(&ctx, &dispatch.header);
        if (result != FFX_API_RETURN_OK) {
            fail("FSR failed to run (" + code(result) + ")");
            return false;
        }

        return true;
    }
}

#else

namespace RT64 {
    FfxBackend::~FfxBackend() { }
    void FfxBackend::destroyContext() { }

    void FfxBackend::fail(const std::string &why) {
        failed = true;
        reason = why;
    }

    bool FfxBackend::evaluate(RenderDevice *, RenderCommandList *, RenderTexture *, RenderTexture *, RenderTexture *, RenderTexture *,
        uint32_t, uint32_t, uint32_t, uint32_t, float, float, bool, bool, bool, bool, float, float, float)
    {
        fail("this build has no FSR 3 / FSR 4 (Windows builds with the FidelityFX files only)");
        return false;
    }
}

#endif
