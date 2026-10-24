//
// RT64
//

#include "rt64_volumetric_shadows.h"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <memory>
#include <mutex>
#include <unordered_map>
#include <vector>

#include "shared/rt64_volumetric_shadows.h"

#include "rt64_descriptor_sets.h"

#include "shaders/FullScreenVS.hlsl.spirv.h"
#include "shaders/VolumetricShadowMapVS.hlsl.spirv.h"
#include "shaders/VolumetricShadowMapPS.hlsl.spirv.h"
#include "shaders/VolumetricShadowVolumeVS.hlsl.spirv.h"
#include "shaders/VolumetricShadowVolumePS.hlsl.spirv.h"
#include "shaders/VolumetricShadowVolume2XPS.hlsl.spirv.h"
#include "shaders/VolumetricShadowVolume4XPS.hlsl.spirv.h"
#include "shaders/VolumetricShadowVolume8XPS.hlsl.spirv.h"
#include "shaders/VolumetricShadowCompositePS.hlsl.spirv.h"
#include "shaders/VolumetricShadowComposite2XPS.hlsl.spirv.h"
#include "shaders/VolumetricShadowComposite4XPS.hlsl.spirv.h"
#include "shaders/VolumetricShadowComposite8XPS.hlsl.spirv.h"
#ifdef _WIN32
#   include "shaders/FullScreenVS.hlsl.dxil.h"
#   include "shaders/VolumetricShadowMapVS.hlsl.dxil.h"
#   include "shaders/VolumetricShadowMapPS.hlsl.dxil.h"
#   include "shaders/VolumetricShadowVolumeVS.hlsl.dxil.h"
#   include "shaders/VolumetricShadowVolumePS.hlsl.dxil.h"
#   include "shaders/VolumetricShadowVolume2XPS.hlsl.dxil.h"
#   include "shaders/VolumetricShadowVolume4XPS.hlsl.dxil.h"
#   include "shaders/VolumetricShadowVolume8XPS.hlsl.dxil.h"
#   include "shaders/VolumetricShadowCompositePS.hlsl.dxil.h"
#   include "shaders/VolumetricShadowComposite2XPS.hlsl.dxil.h"
#   include "shaders/VolumetricShadowComposite4XPS.hlsl.dxil.h"
#   include "shaders/VolumetricShadowComposite8XPS.hlsl.dxil.h"
#endif
#ifdef __APPLE__
#   include "shaders/FullScreenVS.hlsl.metal.h"
#   include "shaders/VolumetricShadowMapVS.hlsl.metal.h"
#   include "shaders/VolumetricShadowMapPS.hlsl.metal.h"
#   include "shaders/VolumetricShadowVolumeVS.hlsl.metal.h"
#   include "shaders/VolumetricShadowVolumePS.hlsl.metal.h"
#   include "shaders/VolumetricShadowVolume2XPS.hlsl.metal.h"
#   include "shaders/VolumetricShadowVolume4XPS.hlsl.metal.h"
#   include "shaders/VolumetricShadowVolume8XPS.hlsl.metal.h"
#   include "shaders/VolumetricShadowCompositePS.hlsl.metal.h"
#   include "shaders/VolumetricShadowComposite2XPS.hlsl.metal.h"
#   include "shaders/VolumetricShadowComposite4XPS.hlsl.metal.h"
#   include "shaders/VolumetricShadowComposite8XPS.hlsl.metal.h"
#endif

#ifdef _WIN32
#   define VOL_SHADER_INPUTS(NAME, ENTRY_NAME, SHADER_FORMAT)\
        (SHADER_FORMAT == RenderShaderFormat::DXIL) ? NAME##BlobDXIL : (SHADER_FORMAT == RenderShaderFormat::SPIRV) ? NAME##BlobSPIRV : nullptr,\
        (SHADER_FORMAT == RenderShaderFormat::DXIL) ? sizeof(NAME##BlobDXIL) : (SHADER_FORMAT == RenderShaderFormat::SPIRV) ? sizeof(NAME##BlobSPIRV) : 0,\
        ENTRY_NAME,\
        SHADER_FORMAT
#elif defined(__APPLE__)
#   define VOL_SHADER_INPUTS(NAME, ENTRY_NAME, SHADER_FORMAT)\
        (SHADER_FORMAT == RenderShaderFormat::METAL) ? NAME##BlobMSL : (SHADER_FORMAT == RenderShaderFormat::SPIRV) ? NAME##BlobSPIRV : nullptr,\
        (SHADER_FORMAT == RenderShaderFormat::METAL) ? sizeof(NAME##BlobMSL) : (SHADER_FORMAT == RenderShaderFormat::SPIRV) ? sizeof(NAME##BlobSPIRV) : 0,\
        ENTRY_NAME,\
        SHADER_FORMAT
#else
#   define VOL_SHADER_INPUTS(NAME, ENTRY_NAME, SHADER_FORMAT)\
        (SHADER_FORMAT == RenderShaderFormat::SPIRV) ? NAME##BlobSPIRV : nullptr,\
        (SHADER_FORMAT == RenderShaderFormat::SPIRV) ? sizeof(NAME##BlobSPIRV) : 0,\
        ENTRY_NAME,\
        SHADER_FORMAT
#endif

namespace RT64 {
    namespace {
        // The volume pass's inputs: the picture's depth, the sun's map and the lamps' maps.
        struct VolShadowVolumeDescriptorSet : RenderDescriptorSetBase {
            uint32_t gDepth;
            uint32_t gSunMap;
            uint32_t gLampMap;

            VolShadowVolumeDescriptorSet(RenderDevice *device = nullptr) {
                builder.begin();
                gDepth = builder.addTexture(1);
                gSunMap = builder.addTexture(2);
                gLampMap = builder.addTexture(3);
                builder.end();
                if (device != nullptr) {
                    create(device);
                }
            }
        };

        // The composite pass's: the picture's depth and the gathered light.
        struct VolShadowCompositeDescriptorSet : RenderDescriptorSetBase {
            uint32_t gDepth;
            uint32_t gGathered;

            VolShadowCompositeDescriptorSet(RenderDevice *device = nullptr) {
                builder.begin();
                gDepth = builder.addTexture(1);
                gGathered = builder.addTexture(4);
                builder.end();
                if (device != nullptr) {
                    create(device);
                }
            }
        };

        std::mutex settingsMutex;
        VolumetricShadowSettings currentSettings;

        // The passes' pipelines, made with the shader library's (for its sample count).
        struct Pipelines {
            RenderDevice *device = nullptr;
            RenderSampleCounts sampleCount = RenderSampleCount::COUNT_1;
            RenderFormat colorFormat = RenderFormat::UNKNOWN;
            std::unique_ptr<RenderPipelineLayout> mapLayout;
            std::unique_ptr<RenderPipeline> mapSun;
            std::unique_ptr<RenderPipeline> mapLamp;
            std::unique_ptr<RenderPipelineLayout> volumeLayout;
            std::unique_ptr<RenderPipeline> volume;
            std::unique_ptr<RenderPipelineLayout> compositeLayout;
            std::unique_ptr<RenderPipeline> composite;
        };
        std::mutex pipelinesMutex;
        std::unique_ptr<Pipelines> pipelines;

        constexpr RenderFormat GatheredFormat = RenderFormat::R32G32_FLOAT;

        // Quality: the sun's map size, how many picture pixels a side each gathered pixel covers, a lamp's face size.
        struct Quality {
            uint32_t sunMap;
            uint32_t scale;
            uint32_t lampFace;
        };
        constexpr Quality Qualities[3] = { { 512, 2, 256 }, { 1024, 2, 256 }, { 2048, 1, 512 } };

        // Each worker that records the passes gets its own targets (as the scene effects' resources).
        struct Resources {
            RenderDevice *device = nullptr;
            std::unique_ptr<RenderTexture> sunMap;
            std::unique_ptr<RenderTextureView> sunMapView;
            std::unique_ptr<RenderFramebuffer> sunMapFramebuffer;
            uint32_t sunMapSize = 0;
            std::unique_ptr<RenderTexture> lampMap;
            std::unique_ptr<RenderTextureView> lampMapView;
            std::unique_ptr<RenderFramebuffer> lampMapFramebuffer;
            uint32_t lampFaceSize = 0;
            std::unique_ptr<RenderTexture> gathered;
            std::unique_ptr<RenderFramebuffer> gatheredFramebuffer;
            uint32_t gatheredWidth = 0;
            uint32_t gatheredHeight = 0;
            std::unique_ptr<VolShadowVolumeDescriptorSet> volumeSet;
            std::unique_ptr<VolShadowCompositeDescriptorSet> compositeSet;
            const RenderTexture *setDepth = nullptr;
            const RenderTexture *setSunMap = nullptr;
            const RenderTexture *setLampMap = nullptr;
            const RenderTexture *setGathered = nullptr;

            // Replaced objects, kept until the GPU can no longer be using them.
            struct Retired {
                uint64_t pass;
                std::chrono::steady_clock::time_point time;
                std::shared_ptr<void> object;
            };
            std::deque<Retired> retired;
            uint64_t passes = 0;

            template <typename T>
            void retireLater(std::unique_ptr<T> &&object) {
                if (object != nullptr) {
                    retired.push_back({ passes, std::chrono::steady_clock::now(), std::shared_ptr<void>(std::move(object)) });
                }
            }

            void freeRetired() {
                passes++;
                const auto now = std::chrono::steady_clock::now();
                while (!retired.empty() && (retired.front().pass + 8 <= passes) && ((now - retired.front().time) >= std::chrono::milliseconds(500))) {
                    retired.pop_front();
                }
            }
        };
        std::mutex resourcesMutex;
        std::unordered_map<RenderWorker *, std::unique_ptr<Resources>> workerResources;

        Resources &resourcesFor(RenderWorker *worker) {
            const std::scoped_lock lock(resourcesMutex);
            std::unique_ptr<Resources> &resources = workerResources[worker];
            if ((resources == nullptr) || (resources->device != worker->device)) {
                resources = std::make_unique<Resources>();
                resources->device = worker->device;
            }
            return *resources;
        }

        void normalize3(float v[3]) {
            const float length = std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
            if (length > 1e-12f) {
                v[0] /= length;
                v[1] /= length;
                v[2] /= length;
            }
        }

        float dot3(const float a[3], const float b[3]) {
            return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
        }

        void depthTexture(RenderDevice *device, uint32_t width, uint32_t height, const char *name, std::unique_ptr<RenderTexture> &texture,
            std::unique_ptr<RenderTextureView> &view, std::unique_ptr<RenderFramebuffer> &framebuffer)
        {
            RenderClearValue clearValue = RenderClearValue::Depth(RenderDepth(), RenderFormat::D32_FLOAT);
            texture = device->createTexture(RenderTextureDesc::DepthTarget(width, height, RenderFormat::D32_FLOAT, RenderMultisampling(), &clearValue));
            texture->setName(name);
            view = texture->createTextureView(RenderTextureViewDesc::Texture2D(RenderFormat::D32_FLOAT));
            const RenderTexture *noColor = nullptr;
            framebuffer = device->createFramebuffer(RenderFramebufferDesc(&noColor, 0, texture.get()));
        }
    }

    void SetVolumetricShadows(float sun, float haze, uint32_t quality, float distance, float lamps, uint32_t lampCount) {
        const std::scoped_lock lock(settingsMutex);
        currentSettings.sun = std::clamp(sun, 0.0f, 1.0f);
        currentSettings.haze = std::clamp(haze, 0.0f, 1.0f);
        currentSettings.quality = std::min(quality, 2U);
        currentSettings.distance = distance;
        currentSettings.lamps = std::clamp(lamps, 0.0f, 1.0f);
        currentSettings.lampCount = std::clamp(lampCount, 1U, uint32_t(VOL_SHADOW_MAX_LAMPS));
    }

    VolumetricShadowSettings GetVolumetricShadows() {
        const std::scoped_lock lock(settingsMutex);
        return currentSettings;
    }

    bool VolumetricShadowsOn() {
        const std::scoped_lock lock(settingsMutex);
        return (currentSettings.sun > 0.0f) || (currentSettings.lamps > 0.0f);
    }

    void SetupVolumetricShadowShaders(RenderDevice *device, RenderShaderFormat shaderFormat, const RenderMultisampling &multisampling, bool usesHDR) {
        std::unique_ptr<Pipelines> made = std::make_unique<Pipelines>();
        made->device = device;
        made->sampleCount = multisampling.sampleCount;
        made->colorFormat = RenderTarget::colorBufferFormat(usesHDR);
        RenderPipelineLayoutBuilder layoutBuilder;

        // The map pass: the casters' own set (the game's vertices and model transforms), depth only.
        {
            SunShadowMapDescriptorSet descriptorSet;
            layoutBuilder.begin();
            layoutBuilder.addDescriptorSet(descriptorSet);
            layoutBuilder.addPushConstant(0, 0, sizeof(interop::VolShadowCB), RenderShaderStageFlag::VERTEX | RenderShaderStageFlag::PIXEL);
            layoutBuilder.end();
            made->mapLayout = layoutBuilder.create(device);
            std::unique_ptr<RenderShader> vertexShader = device->createShader(VOL_SHADER_INPUTS(VolumetricShadowMapVS, "VSMain", shaderFormat));
            std::unique_ptr<RenderShader> pixelShader = device->createShader(VOL_SHADER_INPUTS(VolumetricShadowMapPS, "PSMain", shaderFormat));
            RenderGraphicsPipelineDesc pipelineDesc;
            pipelineDesc.pipelineLayout = made->mapLayout.get();
            pipelineDesc.vertexShader = vertexShader.get();
            pipelineDesc.pixelShader = pixelShader.get();
            pipelineDesc.renderTargetCount = 0;
            pipelineDesc.depthEnabled = true;
            pipelineDesc.depthWriteEnabled = true;
            pipelineDesc.depthFunction = RenderComparisonFunction::LESS;
            pipelineDesc.depthTargetFormat = RenderFormat::D32_FLOAT;
            // The sun: what is beyond the map's depth range is held at its ends (it still blocks the sun).
            made->mapSun = device->createGraphicsPipeline(pipelineDesc);
            // A lamp: what is nearer than the near plane (the lamp's own frame and glass) is left out.
            pipelineDesc.depthClipEnabled = true;
            made->mapLamp = device->createGraphicsPipeline(pipelineDesc);
        }

        // The volume pass: the lit air's mesh, added up into the gathered light. Reads the picture's depth.
        {
            VolShadowVolumeDescriptorSet descriptorSet;
            layoutBuilder.begin();
            layoutBuilder.addDescriptorSet(descriptorSet);
            layoutBuilder.addPushConstant(0, 0, sizeof(interop::VolShadowCB), RenderShaderStageFlag::VERTEX | RenderShaderStageFlag::PIXEL);
            layoutBuilder.end();
            made->volumeLayout = layoutBuilder.create(device);
            std::unique_ptr<RenderShader> vertexShader = device->createShader(VOL_SHADER_INPUTS(VolumetricShadowVolumeVS, "VSMain", shaderFormat));
            std::unique_ptr<RenderShader> pixelShader;
            switch (multisampling.sampleCount) {
            case RenderSampleCount::COUNT_2:
                pixelShader = device->createShader(VOL_SHADER_INPUTS(VolumetricShadowVolume2XPS, "PSMain", shaderFormat));
                break;
            case RenderSampleCount::COUNT_4:
                pixelShader = device->createShader(VOL_SHADER_INPUTS(VolumetricShadowVolume4XPS, "PSMain", shaderFormat));
                break;
            case RenderSampleCount::COUNT_8:
                pixelShader = device->createShader(VOL_SHADER_INPUTS(VolumetricShadowVolume8XPS, "PSMain", shaderFormat));
                break;
            default:
                pixelShader = device->createShader(VOL_SHADER_INPUTS(VolumetricShadowVolumePS, "PSMain", shaderFormat));
                break;
            }
            RenderBlendDesc blendDesc;
            blendDesc.blendEnabled = true;
            blendDesc.srcBlend = RenderBlend::ONE;
            blendDesc.dstBlend = RenderBlend::ONE;
            blendDesc.blendOp = RenderBlendOperation::ADD;
            blendDesc.srcBlendAlpha = RenderBlend::ONE;
            blendDesc.dstBlendAlpha = RenderBlend::ONE;
            blendDesc.blendOpAlpha = RenderBlendOperation::ADD;
            RenderGraphicsPipelineDesc pipelineDesc;
            pipelineDesc.pipelineLayout = made->volumeLayout.get();
            pipelineDesc.vertexShader = vertexShader.get();
            pipelineDesc.pixelShader = pixelShader.get();
            pipelineDesc.renderTargetBlend[0] = blendDesc;
            pipelineDesc.renderTargetFormat[0] = GatheredFormat;
            pipelineDesc.renderTargetCount = 1;
            pipelineDesc.cullMode = RenderCullMode::NONE;
            made->volume = device->createGraphicsPipeline(pipelineDesc);
        }

        // The composite pass: over the picture, at its sample count, blended as dst * a + rgb.
        {
            VolShadowCompositeDescriptorSet descriptorSet;
            layoutBuilder.begin();
            layoutBuilder.addDescriptorSet(descriptorSet);
            layoutBuilder.addPushConstant(0, 0, sizeof(interop::VolShadowCB), RenderShaderStageFlag::VERTEX | RenderShaderStageFlag::PIXEL);
            layoutBuilder.end();
            made->compositeLayout = layoutBuilder.create(device);
            std::unique_ptr<RenderShader> vertexShader = device->createShader(VOL_SHADER_INPUTS(FullScreenVS, "VSMain", shaderFormat));
            std::unique_ptr<RenderShader> pixelShader;
            switch (multisampling.sampleCount) {
            case RenderSampleCount::COUNT_2:
                pixelShader = device->createShader(VOL_SHADER_INPUTS(VolumetricShadowComposite2XPS, "PSMain", shaderFormat));
                break;
            case RenderSampleCount::COUNT_4:
                pixelShader = device->createShader(VOL_SHADER_INPUTS(VolumetricShadowComposite4XPS, "PSMain", shaderFormat));
                break;
            case RenderSampleCount::COUNT_8:
                pixelShader = device->createShader(VOL_SHADER_INPUTS(VolumetricShadowComposite8XPS, "PSMain", shaderFormat));
                break;
            default:
                pixelShader = device->createShader(VOL_SHADER_INPUTS(VolumetricShadowCompositePS, "PSMain", shaderFormat));
                break;
            }
            RenderBlendDesc blendDesc;
            blendDesc.blendEnabled = true;
            blendDesc.srcBlend = RenderBlend::ONE;
            blendDesc.dstBlend = RenderBlend::SRC_ALPHA;
            blendDesc.blendOp = RenderBlendOperation::ADD;
            blendDesc.srcBlendAlpha = RenderBlend::ZERO;
            blendDesc.dstBlendAlpha = RenderBlend::ONE;
            blendDesc.blendOpAlpha = RenderBlendOperation::ADD;
            RenderGraphicsPipelineDesc pipelineDesc;
            pipelineDesc.pipelineLayout = made->compositeLayout.get();
            pipelineDesc.vertexShader = vertexShader.get();
            pipelineDesc.pixelShader = pixelShader.get();
            pipelineDesc.renderTargetBlend[0] = blendDesc;
            pipelineDesc.renderTargetFormat[0] = made->colorFormat;
            pipelineDesc.renderTargetCount = 1;
            pipelineDesc.multisampling = multisampling;
            made->composite = device->createGraphicsPipeline(pipelineDesc);
        }

        const std::scoped_lock lock(pipelinesMutex);
        pipelines = std::move(made);
    }

    void RecordVolumetricShadows(RenderWorker *worker, RenderTarget *colorTarget, RenderTarget *depthTarget, const VolumetricShadowFrame &frame,
        const std::function<void(RenderCommandList *)> &drawCasters)
    {
        const VolumetricShadowSettings settings = GetVolumetricShadows();
        if (((settings.sun <= 0.0f) && (settings.lamps <= 0.0f)) || !drawCasters || (colorTarget == nullptr) || (depthTarget == nullptr) ||
            (colorTarget->width == 0) || (colorTarget->height == 0))
        {
            return;
        }

        const std::scoped_lock pipelinesLock(pipelinesMutex);
        if ((pipelines == nullptr) || (pipelines->device != worker->device) || (pipelines->sampleCount != colorTarget->multisampling.sampleCount) ||
            (pipelines->colorFormat != colorTarget->format) || (pipelines->composite == nullptr))
        {
            static bool warned = false;
            if (!warned) {
                warned = true;
                fprintf(stderr, "[volshadow] no pipelines for this target (sample count %u), not drawn\n", uint32_t(colorTarget->multisampling.sampleCount));
            }
            return;
        }

        RenderDevice *device = worker->device;
        RenderCommandList *commandList = worker->commandList.get();
        Resources &res = resourcesFor(worker);
        res.freeRetired();

        const Quality &quality = Qualities[settings.quality];
        const float camera[3] = { frame.worldX[3], frame.worldY[3], frame.worldZ[3] };

        // The sun's map: a square round the camera, a little ahead of it, square to the sun. It fades out as the sun
        // nears the horizon and is gone below it.
        float towards[3] = { frame.sun[0], frame.sun[1], frame.sun[2] };
        normalize3(towards);
        const float sunUp = std::clamp((towards[1] - 0.02f) / 0.13f, 0.0f, 1.0f);
        const float sunStrength = settings.sun * sunUp * sunUp * (3.0f - 2.0f * sunUp);
        const bool sunOn = sunStrength > 0.0f;
        const float halfWidth = std::clamp(settings.distance, 1000.0f, 12000.0f);
        const float range = std::max(8000.0f, 1.5f * halfWidth);
        float across[3] = { 1.0f, 0.0f, 0.0f };
        if (std::abs(towards[1]) <= 0.999f) {
            across[0] = towards[2];
            across[1] = 0.0f;
            across[2] = -towards[0];
            normalize3(across);
        }
        const float up[3] = { towards[1] * across[2] - towards[2] * across[1], towards[2] * across[0] - towards[0] * across[2], towards[0] * across[1] - towards[1] * across[0] };
        float middle[3] = { camera[0], camera[1], camera[2] };
        {
            float forward[2] = { -frame.worldX[2], -frame.worldZ[2] };
            const float forwardLength = std::sqrt(forward[0] * forward[0] + forward[1] * forward[1]);
            if (forwardLength > 1e-6f) {
                middle[0] += forward[0] / forwardLength * 0.5f * halfWidth;
                middle[2] += forward[1] / forwardLength * 0.5f * halfWidth;
            }
            // Moved in whole texels across the map, so the shadows' edges don't crawl as the camera moves.
            const float texel = 2.0f * halfWidth / float(quality.sunMap);
            const float a = dot3(middle, across), u = dot3(middle, up);
            const float da = std::floor(a / texel) * texel - a, du = std::floor(u / texel) * texel - u;
            for (int c = 0; c < 3; c++) {
                middle[c] += across[c] * da + up[c] * du;
            }
        }

        // The nearest lamps (the level's lights, with what reaches past the camera first), at most lampCount.
        struct Lamp {
            float position[3];
            float radius;
            float score;
        };
        Lamp lamps[VOL_SHADOW_MAX_LAMPS];
        uint32_t lampCount = 0;
        if (settings.lamps > 0.0f) {
            std::vector<Lamp> found;
            for (uint32_t i = 0; i < frame.lightCount; i++) {
                const float *l = frame.lights + i * 4;
                const float radius = std::clamp(l[3], 300.0f, 2500.0f);
                const float d[3] = { l[0] - camera[0], l[1] - camera[1], l[2] - camera[2] };
                const float distance = std::sqrt(dot3(d, d));
                // Too far for its glow to reach what the camera sees nearby.
                if (distance < radius + 3000.0f) {
                    found.push_back({ { l[0], l[1], l[2] }, radius, distance - radius });
                }
            }
            std::sort(found.begin(), found.end(), [](const Lamp &a, const Lamp &b) { return a.score < b.score; });
            lampCount = std::min(uint32_t(found.size()), settings.lampCount);
            std::copy(found.begin(), found.begin() + lampCount, lamps);
        }
        if (!sunOn && (lampCount == 0) && (settings.haze <= 0.0f)) {
            return;
        }

        // The targets: made again when the quality or the picture's size asks for others.
        if ((res.sunMap != nullptr) && (res.sunMapSize != quality.sunMap)) {
            res.retireLater(std::move(res.sunMapFramebuffer));
            res.retireLater(std::move(res.sunMapView));
            res.retireLater(std::move(res.sunMap));
        }
        if (res.sunMap == nullptr) {
            depthTexture(device, quality.sunMap, quality.sunMap, "Volumetric Shadows Sun Map", res.sunMap, res.sunMapView, res.sunMapFramebuffer);
            res.sunMapSize = quality.sunMap;
            commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderTextureBarrier(res.sunMap.get(), RenderTextureLayout::DEPTH_WRITE) });
            commandList->setFramebuffer(res.sunMapFramebuffer.get());
            commandList->clearDepth(true, 1.0f);
            commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderTextureBarrier(res.sunMap.get(), RenderTextureLayout::SHADER_READ) });
        }
        if ((res.lampMap != nullptr) && (res.lampFaceSize != quality.lampFace)) {
            res.retireLater(std::move(res.lampMapFramebuffer));
            res.retireLater(std::move(res.lampMapView));
            res.retireLater(std::move(res.lampMap));
        }
        if (res.lampMap == nullptr) {
            depthTexture(device, quality.lampFace * 3 * VOL_SHADOW_MAX_LAMPS, quality.lampFace * 2, "Volumetric Shadows Lamp Maps", res.lampMap, res.lampMapView, res.lampMapFramebuffer);
            res.lampFaceSize = quality.lampFace;
            commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderTextureBarrier(res.lampMap.get(), RenderTextureLayout::DEPTH_WRITE) });
            commandList->setFramebuffer(res.lampMapFramebuffer.get());
            commandList->clearDepth(true, 1.0f);
            commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderTextureBarrier(res.lampMap.get(), RenderTextureLayout::SHADER_READ) });
        }
        const uint32_t gatheredWidth = std::max((colorTarget->width + quality.scale - 1) / quality.scale, 1U);
        const uint32_t gatheredHeight = std::max((colorTarget->height + quality.scale - 1) / quality.scale, 1U);
        if ((res.gathered != nullptr) && ((res.gatheredWidth != gatheredWidth) || (res.gatheredHeight != gatheredHeight))) {
            res.retireLater(std::move(res.gatheredFramebuffer));
            res.retireLater(std::move(res.gathered));
        }
        if (res.gathered == nullptr) {
            res.gathered = device->createTexture(RenderTextureDesc::ColorTarget(gatheredWidth, gatheredHeight, GatheredFormat));
            res.gathered->setName("Volumetric Shadows Gathered Light");
            const RenderTexture *texture = res.gathered.get();
            res.gatheredFramebuffer = device->createFramebuffer(RenderFramebufferDesc(&texture, 1));
            res.gatheredWidth = gatheredWidth;
            res.gatheredHeight = gatheredHeight;
        }
        if ((res.volumeSet == nullptr) || (res.setDepth != depthTarget->texture.get()) || (res.setSunMap != res.sunMap.get()) ||
            (res.setLampMap != res.lampMap.get()) || (res.setGathered != res.gathered.get()))
        {
            res.retireLater(std::move(res.volumeSet));
            res.retireLater(std::move(res.compositeSet));
            res.volumeSet = std::make_unique<VolShadowVolumeDescriptorSet>(device);
            res.volumeSet->setTexture(res.volumeSet->gDepth, depthTarget->texture.get(), RenderTextureLayout::SHADER_READ, depthTarget->textureView.get());
            res.volumeSet->setTexture(res.volumeSet->gSunMap, res.sunMap.get(), RenderTextureLayout::SHADER_READ, res.sunMapView.get());
            res.volumeSet->setTexture(res.volumeSet->gLampMap, res.lampMap.get(), RenderTextureLayout::SHADER_READ, res.lampMapView.get());
            res.compositeSet = std::make_unique<VolShadowCompositeDescriptorSet>(device);
            res.compositeSet->setTexture(res.compositeSet->gDepth, depthTarget->texture.get(), RenderTextureLayout::SHADER_READ, depthTarget->textureView.get());
            res.compositeSet->setTexture(res.compositeSet->gGathered, res.gathered.get(), RenderTextureLayout::SHADER_READ);
            res.setDepth = depthTarget->texture.get();
            res.setSunMap = res.sunMap.get();
            res.setLampMap = res.lampMap.get();
            res.setGathered = res.gathered.get();
        }

        // The constants every pass shares.
        interop::VolShadowCB constants;
        constants.worldX = { frame.worldX[0], frame.worldX[1], frame.worldX[2], frame.worldX[3] };
        constants.worldY = { frame.worldY[0], frame.worldY[1], frame.worldY[2], frame.worldY[3] };
        constants.worldZ = { frame.worldZ[0], frame.worldZ[1], frame.worldZ[2], frame.worldZ[3] };
        constants.depthTerms = { frame.depthTerms[0], frame.depthTerms[1], frame.depthTerms[2], frame.depthTerms[3] };
        constants.projection = { frame.projectionScale[0], frame.projectionScale[1], float(colorTarget->width), float(colorTarget->height) };
        constants.clipX = { frame.clip[0][0], frame.clip[0][1], frame.clip[0][2], frame.clip[0][3] };
        constants.clipY = { frame.clip[1][0], frame.clip[1][1], frame.clip[1][2], frame.clip[1][3] };
        constants.clipZ = { frame.clip[2][0], frame.clip[2][1], frame.clip[2][2], frame.clip[2][3] };
        constants.clipW = { frame.clip[3][0], frame.clip[3][1], frame.clip[3][2], frame.clip[3][3] };
        const uint32_t sunCells = quality.sunMap / 2;
        constants.lightA = { across[0], across[1], across[2], halfWidth };
        constants.lightB = { up[0], up[1], up[2], range };
        constants.lightC = { towards[0], towards[1], towards[2], float(quality.sunMap) };
        constants.lightD = { middle[0], middle[1], middle[2], float(sunCells) };
        // The haze: at 100, half the light is lost over about 3500 units (at the default 40, about 8700); the sky counts
        // as one and a half times the map's reach away.
        const float thickness = std::max(settings.haze, 0.01f) * (1.0f / 5000.0f);
        constants.medium = { thickness, 1.5f * halfWidth, float(VOL_SHADOW_PASS_SUN), float(quality.scale) };
        const float sunLight = sunOn ? sunStrength * 1.2f : 0.0f;
        constants.sunColor = { frame.sunTint[0] * 1.0f * sunLight, frame.sunTint[1] * 0.92f * sunLight, frame.sunTint[2] * 0.80f * sunLight, 0.45f };
        // The shaded haze keeps a little of the sky's light, so the shafts stand out against it without it going black.
        const float skyLight = 0.25f * std::max(settings.sun, settings.lamps * 0.5f);
        constants.ambient = { frame.sunTint[0] * 0.55f * skyLight, frame.sunTint[1] * 0.62f * skyLight, frame.sunTint[2] * 0.75f * skyLight, settings.lamps };

        RenderRect area(0, 0, int32_t(colorTarget->width), int32_t(colorTarget->height));
        if (!frame.area.isEmpty()) {
            area.left = std::max(area.left, frame.area.left);
            area.top = std::max(area.top, frame.area.top);
            area.right = std::min(area.right, frame.area.right);
            area.bottom = std::min(area.bottom, frame.area.bottom);
        }

        // The maps: the world's solid triangles from the sun, and from each lamp six times over (a cube's faces).
        commandList->setGraphicsPipelineLayout(pipelines->mapLayout.get());
        if (sunOn) {
            commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderTextureBarrier(res.sunMap.get(), RenderTextureLayout::DEPTH_WRITE) });
            commandList->setFramebuffer(res.sunMapFramebuffer.get());
            commandList->clearDepth(true, 1.0f);
            commandList->setViewports(RenderViewport(0.0f, 0.0f, float(quality.sunMap), float(quality.sunMap)));
            commandList->setScissors(RenderRect(0, 0, quality.sunMap, quality.sunMap));
            commandList->setPipeline(pipelines->mapSun.get());
            commandList->setGraphicsPipelineLayout(pipelines->mapLayout.get());
            commandList->setGraphicsPushConstants(0, &constants);
            drawCasters(commandList);
            commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderTextureBarrier(res.sunMap.get(), RenderTextureLayout::SHADER_READ) });
        }
        interop::VolShadowCB lampConstants[VOL_SHADOW_MAX_LAMPS];
        const float lampNear = 30.0f;
        if (lampCount > 0) {
            commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderTextureBarrier(res.lampMap.get(), RenderTextureLayout::DEPTH_WRITE) });
            commandList->setFramebuffer(res.lampMapFramebuffer.get());
            commandList->clearDepth(true, 1.0f);
            commandList->setPipeline(pipelines->mapLamp.get());
            commandList->setGraphicsPipelineLayout(pipelines->mapLayout.get());
            const uint32_t face = quality.lampFace;
            for (uint32_t l = 0; l < lampCount; l++) {
                interop::VolShadowCB &c = lampConstants[l];
                c = constants;
                c.lightA = { lamps[l].position[0], lamps[l].position[1], lamps[l].position[2], lamps[l].radius };
                // The far plane reaches the cube's corners at the lamp's radius.
                c.lightB = { lampNear, lamps[l].radius * 1.75f, float(face), 0.0f };
                c.lightC = { float(face * 3 * l), 0.0f, float(face / 2), 0.0f };
                c.medium.z = float(VOL_SHADOW_PASS_LAMP);
                for (uint32_t f = 0; f < 6; f++) {
                    const uint32_t x = face * 3 * l + (f % 3) * face;
                    const uint32_t y = (f / 3) * face;
                    commandList->setViewports(RenderViewport(float(x), float(y), float(face), float(face)));
                    commandList->setScissors(RenderRect(int32_t(x), int32_t(y), int32_t(x + face), int32_t(y + face)));
                    c.lightB.w = float(f);
                    commandList->setGraphicsPushConstants(0, &c);
                    drawCasters(commandList);
                }
                // The volume pass reads the lamp's brightness in its place.
                c.lightB.w = settings.lamps * 30.0f * (0.25f + settings.haze);
            }
            commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderTextureBarrier(res.lampMap.get(), RenderTextureLayout::SHADER_READ) });
        }

        // The volume pass: each lit air's mesh, added up.
        commandList->barriers(RenderBarrierStage::GRAPHICS, {
            RenderTextureBarrier(res.gathered.get(), RenderTextureLayout::COLOR_WRITE),
            RenderTextureBarrier(depthTarget->texture.get(), RenderTextureLayout::SHADER_READ)
        });
        commandList->setFramebuffer(res.gatheredFramebuffer.get());
        commandList->clearColor(0, RenderColor(0.0f, 0.0f, 0.0f, 0.0f));
        if (sunOn || (lampCount > 0)) {
            commandList->setViewports(RenderViewport(0.0f, 0.0f, float(gatheredWidth), float(gatheredHeight)));
            commandList->setScissors(RenderRect(area.left / int32_t(quality.scale), area.top / int32_t(quality.scale),
                std::min((area.right + int32_t(quality.scale) - 1) / int32_t(quality.scale), int32_t(gatheredWidth)),
                std::min((area.bottom + int32_t(quality.scale) - 1) / int32_t(quality.scale), int32_t(gatheredHeight))));
            commandList->setPipeline(pipelines->volume.get());
            commandList->setGraphicsPipelineLayout(pipelines->volumeLayout.get());
            commandList->setGraphicsDescriptorSet(res.volumeSet->get(), 0);
            commandList->setVertexBuffers(0, nullptr, 0, nullptr);
            if (sunOn) {
                commandList->setGraphicsPushConstants(0, &constants);
                commandList->drawInstanced(6 * sunCells * sunCells + 36 * sunCells, 1, 0, 0);
            }
            const uint32_t lampCells = quality.lampFace / 2;
            for (uint32_t l = 0; l < lampCount; l++) {
                commandList->setGraphicsPushConstants(0, &lampConstants[l]);
                commandList->drawInstanced(36 * lampCells * lampCells, 1, 0, 0);
            }
        }
        commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderTextureBarrier(res.gathered.get(), RenderTextureLayout::SHADER_READ) });

        // The composite pass over the picture.
        colorTarget->setupColorFramebuffer(worker);
        commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderTextureBarrier(colorTarget->texture.get(), RenderTextureLayout::COLOR_WRITE) });
        commandList->setFramebuffer(colorTarget->textureFramebuffer.get());
        commandList->setViewports(RenderViewport(0.0f, 0.0f, float(colorTarget->width), float(colorTarget->height)));
        commandList->setScissors(area);
        commandList->setPipeline(pipelines->composite.get());
        commandList->setGraphicsPipelineLayout(pipelines->compositeLayout.get());
        commandList->setGraphicsDescriptorSet(res.compositeSet->get(), 0);
        commandList->setGraphicsPushConstants(0, &constants);
        commandList->setVertexBuffers(0, nullptr, 0, nullptr);
        commandList->drawInstanced(3, 1, 0, 0);

        commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderTextureBarrier(depthTarget->texture.get(), RenderTextureLayout::DEPTH_WRITE) });
        colorTarget->markForResolve();

        // TOOIE_VOLSHADOW_LOG=1: what was drawn, every 2 s.
        static const bool log = (getenv("TOOIE_VOLSHADOW_LOG") != nullptr);
        static auto lastLog = std::chrono::steady_clock::now();
        if (log && (std::chrono::steady_clock::now() - lastLog > std::chrono::seconds(2))) {
            lastLog = std::chrono::steady_clock::now();
            fprintf(stderr, "[volshadow] sun %.2f (towards %.2f %.2f %.2f) lamps %u of %u lights, map %u, gathered %ux%u\n", sunStrength,
                towards[0], towards[1], towards[2], lampCount, frame.lightCount, quality.sunMap, gatheredWidth, gatheredHeight);
        }
    }
};
