//
// RT64
//

#include "rt64_dlss.h"

#include <cstdio>

#if defined(_WIN32)

#include <windows.h>

#include "plume_d3d12.h"

#include "nvsdk_ngx.h"
#include "nvsdk_ngx_helpers.h"

namespace RT64 {
    namespace {
        // A project id for NGX's engine-less setup (any GUID; NVIDIA asks for a registered one for a shipped product).
        const char *DlssProjectId = "9a3f5c0e-7b1d-4e6a-8f24-5d2b6c1e0a47";

        std::wstring exeFolder() {
            wchar_t path[MAX_PATH] = {};
            const DWORD length = GetModuleFileNameW(nullptr, path, MAX_PATH);
            std::wstring folder(path, length);
            const size_t slash = folder.find_last_of(L"\\/");
            return (slash == std::wstring::npos) ? std::wstring(L".") : folder.substr(0, slash);
        }

        std::string narrow(const wchar_t *text) {
            std::string out;
            for (; text && *text; text++) {
                out.push_back((*text < 128) ? char(*text) : '?');
            }
            return out;
        }

        NVSDK_NGX_PerfQuality_Value perfQuality(uint32_t quality, bool native) {
            if (native) {
                return NVSDK_NGX_PerfQuality_Value_DLAA;
            }
            switch (quality) {
            case 1: return NVSDK_NGX_PerfQuality_Value_Balanced;
            case 2: return NVSDK_NGX_PerfQuality_Value_MaxPerf;
            case 3: return NVSDK_NGX_PerfQuality_Value_UltraPerformance;
            default: return NVSDK_NGX_PerfQuality_Value_MaxQuality;
            }
        }
    }

    void DlssBackend::fail(const std::string &why) {
        if (!failed) {
            fprintf(stdout, "[upscaler] DLSS unavailable: %s\n", why.c_str());
            fflush(stdout);
        }
        failed = true;
        reason = why;
    }

    DlssBackend::~DlssBackend() {
        if (feature != nullptr) {
            NVSDK_NGX_D3D12_ReleaseFeature(static_cast<NVSDK_NGX_Handle *>(feature));
            feature = nullptr;
        }
        if (initialized && (deviceUsed != nullptr)) {
            NVSDK_NGX_D3D12_Shutdown1(static_cast<ID3D12Device *>(deviceUsed));
        }
    }

    bool DlssBackend::evaluate(RenderDevice *device, RenderCommandList *commandList, RenderTexture *color, RenderTexture *depth, RenderTexture *motion,
        RenderTexture *output, uint32_t inputWidth, uint32_t inputHeight, uint32_t outputWidth, uint32_t outputHeight,
        float jitterX, float jitterY, bool reset, uint32_t quality, bool native, bool hdr)
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

        if (!initialized) {
            const std::wstring folder = exeFolder();
            const wchar_t *paths[] = { folder.c_str() };
            NVSDK_NGX_FeatureCommonInfo info = {};
            info.PathListInfo.Path = paths;
            info.PathListInfo.Length = 1;
            NVSDK_NGX_Result result = NVSDK_NGX_D3D12_Init_with_ProjectID(DlssProjectId, NVSDK_NGX_ENGINE_TYPE_CUSTOM, "1.0", folder.c_str(), d3dDevice->d3d, &info);
            if (NVSDK_NGX_FAILED(result)) {
                fail("NGX would not start: " + narrow(GetNGXResultAsString(result)) + " (needs an RTX card, a current driver and nvngx_dlss.dll beside the game)");
                return false;
            }
            initialized = true;
            deviceUsed = d3dDevice->d3d;

            NVSDK_NGX_Parameter *capability = nullptr;
            result = NVSDK_NGX_D3D12_GetCapabilityParameters(&capability);
            if (NVSDK_NGX_FAILED(result) || (capability == nullptr)) {
                fail("NGX gave no capability parameters: " + narrow(GetNGXResultAsString(result)));
                return false;
            }
            params = capability;

            int available = 0;
            capability->Get(NVSDK_NGX_Parameter_SuperSampling_Available, &available);
            if (!available) {
                int needsDriver = 0;
                int initResult = 0;
                capability->Get(NVSDK_NGX_Parameter_SuperSampling_NeedsUpdatedDriver, &needsDriver);
                capability->Get(NVSDK_NGX_Parameter_SuperSampling_FeatureInitResult, &initResult);
                fail(needsDriver ? "the graphics driver is too old for DLSS" : "this graphics card cannot run DLSS (init result " + std::to_string(initResult) + ")");
                return false;
            }
            fprintf(stdout, "[upscaler] DLSS started\n");
            fflush(stdout);
        }

        NVSDK_NGX_Parameter *ngxParams = static_cast<NVSDK_NGX_Parameter *>(params);
        const bool featureChanged = (feature == nullptr) || (featureInputWidth != inputWidth) || (featureInputHeight != inputHeight) ||
            (featureOutputWidth != outputWidth) || (featureOutputHeight != outputHeight) || (featureQuality != quality) ||
            (featureNative != native) || (featureHdr != hdr);
        if (featureChanged) {
            if (feature != nullptr) {
                NVSDK_NGX_D3D12_ReleaseFeature(static_cast<NVSDK_NGX_Handle *>(feature));
                feature = nullptr;
            }

            NVSDK_NGX_DLSS_Create_Params create = {};
            create.Feature.InWidth = inputWidth;
            create.Feature.InHeight = inputHeight;
            create.Feature.InTargetWidth = outputWidth;
            create.Feature.InTargetHeight = outputHeight;
            create.Feature.InPerfQualityValue = perfQuality(quality, native);
            // The velocity is at the render size and without the jitter in it; the exposure is left to DLSS.
            create.InFeatureCreateFlags = NVSDK_NGX_DLSS_Feature_Flags_MVLowRes | NVSDK_NGX_DLSS_Feature_Flags_AutoExposure |
                (hdr ? NVSDK_NGX_DLSS_Feature_Flags_IsHDR : 0);
            NVSDK_NGX_Handle *handle = nullptr;
            const NVSDK_NGX_Result result = NGX_D3D12_CREATE_DLSS_EXT(d3dCommandList->d3d, 1, 1, &handle, ngxParams, &create);
            if (NVSDK_NGX_FAILED(result)) {
                fail("could not create the DLSS feature: " + narrow(GetNGXResultAsString(result)));
                return false;
            }
            feature = handle;
            featureInputWidth = inputWidth;
            featureInputHeight = inputHeight;
            featureOutputWidth = outputWidth;
            featureOutputHeight = outputHeight;
            featureQuality = quality;
            featureNative = native;
            featureHdr = hdr;
            fprintf(stdout, "[upscaler] DLSS feature made: %ux%u to %ux%u, %s\n", inputWidth, inputHeight, outputWidth, outputHeight, native ? "DLAA" : "upscale");
            fflush(stdout);
            reset = true;
        }

        D3D12Texture *colorTexture = static_cast<D3D12Texture *>(color);
        D3D12Texture *depthTexture = static_cast<D3D12Texture *>(depth);
        D3D12Texture *motionTexture = static_cast<D3D12Texture *>(motion);
        D3D12Texture *outputTexture = static_cast<D3D12Texture *>(output);

        NVSDK_NGX_D3D12_DLSS_Eval_Params eval = {};
        eval.Feature.pInColor = colorTexture->d3d;
        eval.Feature.pInOutput = outputTexture->d3d;
        eval.Feature.InSharpness = 0.0f;
        eval.pInDepth = depthTexture->d3d;
        eval.pInMotionVectors = motionTexture->d3d;
        eval.InJitterOffsetX = jitterX;
        eval.InJitterOffsetY = jitterY;
        eval.InRenderSubrectDimensions.Width = inputWidth;
        eval.InRenderSubrectDimensions.Height = inputHeight;
        eval.InReset = reset ? 1 : 0;
        eval.InMVScaleX = 1.0f;
        eval.InMVScaleY = 1.0f;
        const NVSDK_NGX_Result result = NGX_D3D12_EVALUATE_DLSS_EXT(d3dCommandList->d3d, static_cast<NVSDK_NGX_Handle *>(feature), ngxParams, &eval);
        if (NVSDK_NGX_FAILED(result)) {
            fail("DLSS failed to run: " + narrow(GetNGXResultAsString(result)));
            return false;
        }

        return true;
    }
}

#else

namespace RT64 {
    DlssBackend::~DlssBackend() { }

    void DlssBackend::fail(const std::string &why) {
        failed = true;
        reason = why;
    }

    bool DlssBackend::evaluate(RenderDevice *, RenderCommandList *, RenderTexture *, RenderTexture *, RenderTexture *, RenderTexture *,
        uint32_t, uint32_t, uint32_t, uint32_t, float, float, bool, uint32_t, bool, bool)
    {
        fail("DLSS is for Windows");
        return false;
    }
}

#endif
