//
// RT64
//

#include "rt64_dlss.h"

#include <cstdio>

#if defined(_WIN32) && defined(TOOIE_HAS_NGX)

#include <windows.h>

#include "plume_d3d12.h"
#include "plume_vulkan.h"
#include "render/plume_dlss.h"

#include "nvsdk_ngx.h"
#include "nvsdk_ngx_helpers.h"
#include "nvsdk_ngx_vk.h"
#include "nvsdk_ngx_helpers_vk.h"

namespace RT64 {
    std::wstring exeFolderForDlss();
    const char *DlssProjectIdString();

    namespace {
        // A project id for NGX's engine-less setup (any GUID; NVIDIA asks for a registered one for a shipped product).
        const char *DlssProjectId = "9a3f5c0e-7b1d-4e6a-8f24-5d2b6c1e0a47";

        std::wstring exeFolder();
    }

    std::wstring exeFolderForDlss() { return exeFolder(); }
    const char *DlssProjectIdString() { return DlssProjectId; }

    // After a third-party dispatch (NGX here, FFX in rt64_ffx_upscaler.cpp) on a Direct3D 12 command list: it bound its own
    // descriptor heaps, root signature and pipeline, so plume's record of what is bound is dropped and set again on next use.
    static void ResetD3D12StateAfterExternalDispatch(D3D12CommandList *commandList) {
        commandList->notifyDescriptorHeapWasChangedExternally();
        commandList->activeComputePipelineLayout = nullptr;
        commandList->activeGraphicsPipelineLayout = nullptr;
        commandList->activeGraphicsPipeline = nullptr;
        commandList->activeTopology = D3D_PRIMITIVE_TOPOLOGY_UNDEFINED;
    }

    namespace {
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
            if (vulkan) {
                NVSDK_NGX_VULKAN_ReleaseFeature(static_cast<NVSDK_NGX_Handle *>(feature));
            }
            else {
                NVSDK_NGX_D3D12_ReleaseFeature(static_cast<NVSDK_NGX_Handle *>(feature));
            }
            feature = nullptr;
        }
        if (params != nullptr) {
            // Capability parameters are the caller's to free (nvsdk_ngx.h, NVSDK_NGX_GetCapabilityParameters).
            if (vulkan) {
                NVSDK_NGX_VULKAN_DestroyParameters(static_cast<NVSDK_NGX_Parameter *>(params));
            }
            else {
                NVSDK_NGX_D3D12_DestroyParameters(static_cast<NVSDK_NGX_Parameter *>(params));
            }
            params = nullptr;
        }
        if (initialized && (deviceUsed != nullptr)) {
            if (vulkan) {
                NVSDK_NGX_VULKAN_Shutdown1(static_cast<VkDevice>(deviceUsed));
            }
            else {
                NVSDK_NGX_D3D12_Shutdown1(static_cast<ID3D12Device *>(deviceUsed));
            }
        }
    }

    bool DlssBackend::evaluate(RenderDevice *device, RenderCommandList *commandList, RenderTexture *color, RenderTexture *depth, RenderTexture *motion,
        RenderTexture *output, uint32_t inputWidth, uint32_t inputHeight, uint32_t outputWidth, uint32_t outputHeight,
        float jitterX, float jitterY, bool reset, uint32_t quality, bool native, bool hdr, RenderTexture *reactive)
    {
        if (failed) {
            return false;
        }

        D3D12Device *d3dDevice = dynamic_cast<D3D12Device *>(device);
        D3D12CommandList *d3dCommandList = dynamic_cast<D3D12CommandList *>(commandList);
        VulkanDevice *vkDevice = dynamic_cast<VulkanDevice *>(device);
        VulkanCommandList *vkCommandList = dynamic_cast<VulkanCommandList *>(commandList);
        const bool useVulkan = (vkDevice != nullptr) && (vkCommandList != nullptr);
        if (!useVulkan && ((d3dDevice == nullptr) || (d3dCommandList == nullptr))) {
            fail("the renderer is using neither Direct3D 12 nor Vulkan");
            return false;
        }

        if (!initialized) {
            const std::wstring folder = exeFolder();
            const wchar_t *paths[] = { folder.c_str() };
            NVSDK_NGX_FeatureCommonInfo info = {};
            info.PathListInfo.Path = paths;
            info.PathListInfo.Length = 1;
            NVSDK_NGX_Result result;
            if (useVulkan) {
                result = NVSDK_NGX_VULKAN_Init_with_ProjectID(DlssProjectId, NVSDK_NGX_ENGINE_TYPE_CUSTOM, "1.0", folder.c_str(), vkDevice->renderInterface->instance,
                    vkDevice->physicalDevice, vkDevice->vk, vkGetInstanceProcAddr, vkGetDeviceProcAddr, &info);
            }
            else {
                result = NVSDK_NGX_D3D12_Init_with_ProjectID(DlssProjectId, NVSDK_NGX_ENGINE_TYPE_CUSTOM, "1.0", folder.c_str(), d3dDevice->d3d, &info);
            }
            if (NVSDK_NGX_FAILED(result)) {
                fail("NGX would not start: " + narrow(GetNGXResultAsString(result)) + " (needs an RTX card, a current driver and nvngx_dlss.dll beside the game)");
                return false;
            }
            initialized = true;
            vulkan = useVulkan;
            deviceUsed = useVulkan ? static_cast<void *>(vkDevice->vk) : static_cast<void *>(d3dDevice->d3d);

            NVSDK_NGX_Parameter *capability = nullptr;
            result = useVulkan ? NVSDK_NGX_VULKAN_GetCapabilityParameters(&capability) : NVSDK_NGX_D3D12_GetCapabilityParameters(&capability);
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
                if (vulkan) {
                    NVSDK_NGX_VULKAN_ReleaseFeature(static_cast<NVSDK_NGX_Handle *>(feature));
                }
                else {
                    NVSDK_NGX_D3D12_ReleaseFeature(static_cast<NVSDK_NGX_Handle *>(feature));
                }
                feature = nullptr;
            }
            if (useVulkan) {
                vkCommandList->endActiveRenderPass();
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
            const NVSDK_NGX_Result result = useVulkan ? NGX_VULKAN_CREATE_DLSS_EXT(vkCommandList->vk, 1, 1, &handle, ngxParams, &create) :
                NGX_D3D12_CREATE_DLSS_EXT(d3dCommandList->d3d, 1, 1, &handle, ngxParams, &create);
            // Making the feature records into the command list too.
            if (!useVulkan) {
                ResetD3D12StateAfterExternalDispatch(d3dCommandList);
            }
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

        if (useVulkan) {
            vkCommandList->endActiveRenderPass();
            auto resource = [](RenderTexture *texture, bool readWrite) {
                VulkanTexture *vkTexture = static_cast<VulkanTexture *>(texture);
                return NVSDK_NGX_Create_ImageView_Resource_VK(vkTexture->imageView, vkTexture->vk, vkTexture->imageSubresourceRange, vkTexture->imageFormat,
                    vkTexture->desc.width, vkTexture->desc.height, readWrite);
            };
            NVSDK_NGX_Resource_VK colorResource = resource(color, false);
            NVSDK_NGX_Resource_VK depthResource = resource(depth, false);
            NVSDK_NGX_Resource_VK motionResource = resource(motion, false);
            NVSDK_NGX_Resource_VK outputResource = resource(output, true);
            NVSDK_NGX_Resource_VK reactiveResource = {};
            NVSDK_NGX_VK_DLSS_Eval_Params eval = {};
            eval.Feature.pInColor = &colorResource;
            eval.Feature.pInOutput = &outputResource;
            eval.Feature.InSharpness = 0.0f;
            eval.pInDepth = &depthResource;
            eval.pInMotionVectors = &motionResource;
            if (reactive != nullptr) {
                reactiveResource = resource(reactive, false);
                eval.pInBiasCurrentColorMask = &reactiveResource;
            }
            eval.InJitterOffsetX = jitterX;
            eval.InJitterOffsetY = jitterY;
            eval.InRenderSubrectDimensions.Width = inputWidth;
            eval.InRenderSubrectDimensions.Height = inputHeight;
            eval.InReset = reset ? 1 : 0;
            eval.InMVScaleX = 1.0f;
            eval.InMVScaleY = 1.0f;
            const NVSDK_NGX_Result result = NGX_VULKAN_EVALUATE_DLSS_EXT(vkCommandList->vk, static_cast<NVSDK_NGX_Handle *>(feature), ngxParams, &eval);
            if (NVSDK_NGX_FAILED(result)) {
                fail("DLSS failed to run: " + narrow(GetNGXResultAsString(result)));
                return false;
            }
            return true;
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
        if (reactive != nullptr) {
            eval.pInBiasCurrentColorMask = static_cast<D3D12Texture *>(reactive)->d3d;
        }
        eval.InMVScaleX = 1.0f;
        eval.InMVScaleY = 1.0f;
        const NVSDK_NGX_Result result = NGX_D3D12_EVALUATE_DLSS_EXT(d3dCommandList->d3d, static_cast<NVSDK_NGX_Handle *>(feature), ngxParams, &eval);
        // Without this plume would go on binding its descriptor tables into NGX's heaps (garbage textures or a removed device).
        ResetD3D12StateAfterExternalDispatch(d3dCommandList);
        if (NVSDK_NGX_FAILED(result)) {
            fail("DLSS failed to run: " + narrow(GetNGXResultAsString(result)));
            return false;
        }

        return true;
    }
}

namespace plume {
    // The Vulkan extensions NGX needs for DLSS, asked for when the instance and the device are made (plume_vulkan.cpp, DLSS_ENABLED).
    namespace {
        std::unordered_set<std::string> ngxExtensions(bool device, VkInstance instance, VkPhysicalDevice physicalDevice) {
            std::unordered_set<std::string> names;
            const std::wstring folder = RT64::exeFolderForDlss();
            const wchar_t *paths[] = { folder.c_str() };
            NVSDK_NGX_FeatureCommonInfo info = {};
            info.PathListInfo.Path = paths;
            info.PathListInfo.Length = 1;
            NVSDK_NGX_FeatureDiscoveryInfo discovery = {};
            discovery.SDKVersion = NVSDK_NGX_Version_API;
            discovery.FeatureID = NVSDK_NGX_Feature_SuperSampling;
            discovery.Identifier.IdentifierType = NVSDK_NGX_Application_Identifier_Type_Project_Id;
            discovery.Identifier.v.ProjectDesc.ProjectId = RT64::DlssProjectIdString();
            discovery.Identifier.v.ProjectDesc.EngineType = NVSDK_NGX_ENGINE_TYPE_CUSTOM;
            discovery.Identifier.v.ProjectDesc.EngineVersion = "1.0";
            discovery.ApplicationDataPath = folder.c_str();
            discovery.FeatureInfo = &info;
            uint32_t count = 0;
            VkExtensionProperties *properties = nullptr;
            const NVSDK_NGX_Result result = device ?
                NVSDK_NGX_VULKAN_GetFeatureDeviceExtensionRequirements(instance, physicalDevice, &discovery, &count, &properties) :
                NVSDK_NGX_VULKAN_GetFeatureInstanceExtensionRequirements(&discovery, &count, &properties);
            if (NVSDK_NGX_SUCCEED(result) && (properties != nullptr)) {
                for (uint32_t i = 0; i < count; i++) {
                    names.insert(properties[i].extensionName);
                }
            }
            return names;
        }
    }

    std::unordered_set<std::string> DLSS::getRequiredInstanceExtensionsVulkan() {
        return ngxExtensions(false, VK_NULL_HANDLE, VK_NULL_HANDLE);
    }

    std::unordered_set<std::string> DLSS::getRequiredDeviceExtensionsVulkan(VulkanDevice *device) {
        return ngxExtensions(true, device->renderInterface->instance, device->physicalDevice);
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
        uint32_t, uint32_t, uint32_t, uint32_t, float, float, bool, uint32_t, bool, bool, RenderTexture *)
    {
        fail("this build has no DLSS (Windows builds with the NGX library only)");
        return false;
    }
}

#endif
