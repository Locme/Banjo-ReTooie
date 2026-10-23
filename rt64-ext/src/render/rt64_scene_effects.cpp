//
// RT64
//

#include "rt64_scene_effects.h"
#include "shared/rt64_grass_instances.h"
#include "shared/rt64_gpu_tile.h"
#include "shared/rt64_rdp_tile.h"
#include "rt64_gpu_sections.h"

#include <algorithm>
#include <cfloat>
#include <unordered_set>
#include <atomic>
#include <cmath>
#include <cstdio>
#include <cstring>
#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdlib>
#include <deque>
#include <iterator>
#include <memory>
#include <chrono>
#include <mutex>
#include <unordered_map>
#include <vector>

#include "shared/rt64_scene_effects.h"

#include "rt64_render_target.h"

namespace RT64 {
    namespace {
        // Modern water's ripple grid round the player: cells across, and world units per cell.
        constexpr uint32_t RippleCells = 256;
        constexpr float RippleCellSize = 3.0f;
        // The fireflies' table width: two fireflies to each of a 9 by 9 block of cells (SceneEffectsPS.hlsl FIREFLY_COUNT).
        constexpr uint32_t FireflyCount = 9 * 9 * 2;
        // Its rows: the fireflies' places, their brightness, then the depth of field's focus distance.
        constexpr uint32_t FireflyTableRows = 3;
        // When the program started (near enough), for the sun shadow map's headless test hook.
        const auto sunMapProcessStart = std::chrono::steady_clock::now();
        std::mutex effectsMutex;
        SceneEffectsSettings effectsSettings;
        // The sun's direction (towards it, in the world) when the game gives none: fairly low, to one side (the game has
        // no sun of its own to follow), so it is often in view.
        constexpr float FixedSun[3] = { 0.47f, 0.42f, -0.78f };
        // The far sun shadow map is drawn again after this many maps at most (it picks up what moved or was loaded
        // since), and at once when the camera crosses into another of its cells or the sun moves more than about a
        // tenth of a degree. In between only the near map is drawn.
        constexpr uint32_t SunFarRefresh = 12;
        constexpr double SunFarMoveCosine = 0.9999985;

        // The pass's own textures and descriptor sets. Ones replaced after a resize are kept (not freed)
        // since frames still in flight may use them; resizes are rare.
        struct Resources {
            // Bloom: the bright parts at a quarter of the size [0] (blurred through [1]), again at an eighth [2]
            // (blurred through [3]) for a wider glow, and both together [4], which the pass reads.
            static constexpr int BloomTextures = 5;
            std::unique_ptr<RenderTexture> bloomTexture[BloomTextures];
            std::unique_ptr<RenderFramebuffer> bloomFramebuffer[BloomTextures];
            std::unique_ptr<SmaaDescriptorSet> bloomSet[BloomTextures];
            std::unique_ptr<SmaaDescriptorSet> bloomCombineSet;
            uint32_t bloomWidth = 0;
            uint32_t bloomHeight = 0;
            std::unique_ptr<RenderTexture> copyTexture;
            uint32_t copyWidth = 0;
            uint32_t copyHeight = 0;
            std::unique_ptr<SmaaDescriptorSet> sourceSet;
            const RenderTexture *sourceSetTexture = nullptr;
            std::unique_ptr<SceneEffectsDescriptorSet> sceneSet;
            const RenderTexture *sceneSetDepth = nullptr;
            const RenderTexture *sceneSetBloom = nullptr;
            const RenderTexture *sceneSetColor = nullptr;
            const RenderTexture *sceneSetAdapted = nullptr;
            const RenderTexture *sceneSetWater = nullptr;
            // The sun shadow map: the 3D world's solid triangles as seen from the sun, depth only.
            std::unique_ptr<RenderTexture> sunMapTexture;
            std::unique_ptr<RenderTextureView> sunMapTextureView;
            std::unique_ptr<RenderFramebuffer> sunMapFramebuffer;
            const RenderTexture *sceneSetSunMap = nullptr;
            uint32_t sunMapSize = 0;
            // The far map is drawn again only now and then (SunFarRefresh): where its middle was (SUN_SHADOW_MAP_FAR_CELL),
            // the sun's world direction it was drawn with, and how many maps have been drawn since.
            bool sunFarValid = false;
            float sunFarMiddle[2] = {};
            float sunFarSun[3] = {};
            uint32_t sunFarAge = 0;
            // The fireflies' table: where each of the night's fireflies is on the screen this frame, worked out
            // once (FireflyTablePS) rather than in every pixel.
            std::unique_ptr<RenderTexture> fireflyTexture;
            std::unique_ptr<RenderFramebuffer> fireflyFramebuffer;
            const RenderTexture *sceneSetFireflies = nullptr;
            // The scene at half size (BloomPS pass 8), the bounce light's colour source: one read a sample there
            // instead of four of the scene.
            std::unique_ptr<RenderTexture> halfTexture;
            std::unique_ptr<RenderFramebuffer> halfFramebuffer;
            const RenderTexture *sceneSetHalf = nullptr;
            // The indirect pass's target (SceneEffectsPS.hlsl INDIRECT_PASS): GTAO's visibility and SSGI's light at
            // half size, which the pass gathers (IndirectAt).
            std::unique_ptr<RenderTexture> indirectTexture;
            std::unique_ptr<RenderFramebuffer> indirectFramebuffer;
            uint32_t indirectWidth = 0;
            uint32_t indirectHeight = 0;
            const RenderTexture *sceneSetIndirect = nullptr;
            // Traced reflections (ray queries, Graphics > Ray tracing): the world's solid triangles as one bottom level
            // structure (a geometry for each run of the index buffer) under a top level one, rebuilt each frame by
            // BuildSceneBVH; bvhReady says this frame's is built. The buffers only grow.
            std::unique_ptr<RenderBuffer> bvhBlasBuffer;
            std::unique_ptr<RenderBuffer> bvhTlasBuffer;
            std::unique_ptr<RenderBuffer> bvhScratchBuffer;
            std::unique_ptr<RenderBuffer> bvhInstancesBuffer;
            std::unique_ptr<RenderAccelerationStructure> bvhBlas;
            std::unique_ptr<RenderAccelerationStructure> bvhTlas;
            uint64_t bvhBlasSize = 0;
            uint64_t bvhTlasSize = 0;
            uint64_t bvhScratchSize = 0;
            // The 3D grass's blades near the camera: their own bottom level structure (rebuilt when the grass's culling
            // pass writes them again), a second instance in the top level one (instance 1, mask 2; the world is mask 1).
            std::unique_ptr<RenderBuffer> grassBlasBuffer;
            std::unique_ptr<RenderAccelerationStructure> grassBlas;
            uint64_t grassBlasSize = 0;
            uint64_t grassBuiltGeneration = UINT64_MAX;
            const RenderBuffer *grassBuiltVertices = nullptr;
            uint32_t bvhInstanceCount = 0;
            const RenderBuffer *bvhInstanceBuffers[3] = {};
            // The level's own draws (bvhBlas holds the models'): kept while their fingerprint (levelKey) is the same.
            std::unique_ptr<RenderBuffer> levelBlasBuffer;
            std::unique_ptr<RenderAccelerationStructure> levelBlas;
            uint64_t levelBlasSize = 0;
            uint64_t levelBuiltKey = 0;
            size_t levelBuiltCount = 0;
            bool bvhReady = false;
            // A structure has been built at least once: a pass with no casters of its own reuses it (it holds the world
            // in world space, so it stays right as the camera moves).
            bool bvhBuiltOnce = false;
            // The level's lights for the traced shadows: the count, then each one's x, y, z, range (16 bytes each).
            std::unique_ptr<RenderBuffer> lightsBuffer;
            // The dust clouds (SceneEffectsPS.hlsl gDust): the count in the first 16 bytes, then two float4s a cloud.
            std::unique_ptr<RenderBuffer> dustBuffer;
            // The world radiance cache: a hash table of 16-unit cells (check word, colour), 1 M entries.
            std::unique_ptr<RenderBuffer> radianceBuffer;
            // The traced scene's geometries (first index, tile, flags, 0: 16 bytes each, in the structure's order) and the
            // set the rays read the textures of what they meet through (SceneRayTexturesDescriptorSet), with the frame's
            // buffers it holds; a set of empty stand-ins until there are some. rayTexturesValid: the structure was built
            // this pass, so its geometries match this frame's buffers (a reused one's don't: its textures aren't read).
            std::unique_ptr<RenderBuffer> rayGeometryBuffer;
            std::unique_ptr<RenderBuffer> rayDummyBuffer;
            // A few of the sets are kept, one for each group of buffers a workload hands over, so switching between workloads
            // doesn't make a new descriptor pool and layout every pass (thousands a minute; the NVIDIA driver crashed in
            // the update of one after ten minutes, 2026-10-21). rayTexturesSet is the one for this pass.
            struct RayTexturesEntry {
                std::unique_ptr<SceneRayTexturesDescriptorSet> set;
                const RenderBuffer *buffers[4] = {};
                uint64_t usedPass = 0;
            };
            std::vector<RayTexturesEntry> rayTexturesCache;
            SceneRayTexturesDescriptorSet *rayTexturesSet = nullptr;
            RenderDescriptorSet *rayTextureCacheSet = nullptr;
            bool rayTexturesValid = false;
            const RenderAccelerationStructure *sceneSetBvh = nullptr;
            // Water reflections: the water's own depth (24 bits over rgb, a = 1 on water), redrawn by the
            // framebuffer renderer into this target, at the scene's size and sample count.
            std::unique_ptr<RenderTexture> waterTexture;
            std::unique_ptr<RenderTextureView> waterTextureView;
            std::unique_ptr<RenderFramebuffer> waterFramebuffer;
            const RenderTexture *waterFramebufferDepth = nullptr;
            uint32_t waterWidth = 0;
            uint32_t waterHeight = 0;
            uint32_t waterSamples = 0;
            RenderFormat waterFormat = RenderFormat::UNKNOWN;
            bool waterDrawn = false;
            // Modern water: the same draws' own colours (rgb) and blending alpha (a), the same size.
            std::unique_ptr<RenderTexture> waterColorTexture;
            std::unique_ptr<RenderTextureView> waterColorTextureView;
            std::unique_ptr<RenderFramebuffer> waterColorFramebuffer;
            const RenderTexture *sceneSetWaterColor = nullptr;
            bool waterColorDrawn = false;
            // Banjo-Tooie: the flat water went into the mask tessellated this frame (WaterTess.hlsl).
            bool waterTessDrawn = false;
            // Modern water's ripple simulation: two grids (height, speed) stepped back and forth, ending each frame
            // in [0], which the pass reads; where the grid's corner is, in cells; steps owed at 120 a second.
            std::unique_ptr<RenderTexture> rippleTexture[2];
            std::unique_ptr<RenderFramebuffer> rippleFramebuffer[2];
            std::unique_ptr<SmaaDescriptorSet> rippleSet[2];
            const RenderTexture *sceneSetRipples = nullptr;
            int32_t rippleCornerX = 0;
            int32_t rippleCornerZ = 0;
            bool rippleCornerKnown = false;
            float rippleSteps = 0.0f;
            std::chrono::steady_clock::time_point rippleLast;
            float ripplePlayerX = 0.0f;
            float ripplePlayerZ = 0.0f;
            float rippleSplashX = 1e9f;
            float rippleSplashZ = 1e9f;
            // Eye adaptation: the measured brightness [0], the adapted one [1] (with this frame's measured one
            // beside it) and a copy of last frame's [2].
            std::unique_ptr<RenderTexture> luminanceTexture[3];
            std::unique_ptr<RenderFramebuffer> luminanceFramebuffer[3];
            std::unique_ptr<SmaaDescriptorSet> measureSet;
            const RenderTexture *measureSetTexture = nullptr;
            std::unique_ptr<SmaaDescriptorSet> adaptSet;
            std::chrono::steady_clock::time_point lastAdapt;
            // Replaced textures, framebuffers, views and descriptor sets, kept until the GPU can no longer be using
            // them: at least RetireAfterPasses passes and RetireAfterTime later. The source and measure sets are
            // replaced whenever the pass reads a different target, which can be every frame, so these must be freed
            // (they were kept forever, and the driver's memory for them filled the GPU after a few minutes).
            static constexpr uint64_t RetireAfterPasses = 8;
            static constexpr std::chrono::milliseconds RetireAfterTime{ 500 };
            struct RetiredObject {
                uint64_t pass;
                std::chrono::steady_clock::time_point time;
                std::shared_ptr<void> object;
            };
            std::deque<RetiredObject> retiredObjects;
            uint64_t passes = 0;
            uint64_t retiredSinceLog = 0;
            std::chrono::steady_clock::time_point retiredLogTime = std::chrono::steady_clock::now();

            template <typename T>
            void retireLater(std::unique_ptr<T> &&object) {
                if (object != nullptr) {
                    retiredSinceLog++;
                    retiredObjects.push_back({ passes, std::chrono::steady_clock::now(), std::shared_ptr<void>(std::move(object)) });
                }
            }

            void freeRetired() {
                passes++;
                const auto now = std::chrono::steady_clock::now();
                // Log how often things are replaced, so a log shows when the pass keeps switching targets.
                if ((now - retiredLogTime) >= std::chrono::seconds(10)) {
                    if (retiredSinceLog >= 100) {
                        fprintf(stderr, "[effects] replaced %llu textures, framebuffers and descriptor sets in %.0f s; %zu waiting to be freed\n",
                            (unsigned long long)(retiredSinceLog), std::chrono::duration<double>(now - retiredLogTime).count(), retiredObjects.size());
                    }
                    retiredSinceLog = 0;
                    retiredLogTime = now;
                }
                while (!retiredObjects.empty() && ((retiredObjects.front().pass + RetireAfterPasses) <= passes) &&
                    ((now - retiredObjects.front().time) >= RetireAfterTime))
                {
                    retiredObjects.pop_front();
                }
            }

            void retire() {
                if (bloomCombineSet != nullptr) {
                    retireLater(std::move(bloomCombineSet));
                }
                for (int i = 0; i < BloomTextures; i++) {
                    if (bloomTexture[i] != nullptr) {
                        // Users first: the set and framebuffer go before the texture they point at.
                        retireLater(std::move(bloomSet[i]));
                        retireLater(std::move(bloomFramebuffer[i]));
                        retireLater(std::move(bloomTexture[i]));
                    }
                }
            }
        };

        // Each worker that records the pass (the workload thread, and the game's thread when it syncs a
        // framebuffer) gets its own, since they record at the same time.
        std::mutex resourcesMutex;
        std::unordered_map<RenderWorker *, std::unique_ptr<Resources>> workerResources;

        Resources &resourcesFor(RenderWorker *worker) {
            const std::scoped_lock lock(resourcesMutex);
            std::unique_ptr<Resources> &resources = workerResources[worker];
            if (resources == nullptr) {
                resources = std::make_unique<Resources>();
            }
            return *resources;
        }

        // The water mask target, matching the scene's color target (so the game's own pipelines can draw
        // into it) with the scene's depth target attached.
        void ensureWaterTarget(RenderWorker *worker, Resources &res, RenderTarget *colorTarget, RenderTarget *depthTarget) {
            const uint32_t samples = colorTarget->multisampling.sampleCount;
            if ((res.waterTexture != nullptr) && (res.waterWidth == colorTarget->width) && (res.waterHeight == colorTarget->height) &&
                (res.waterSamples == samples) && (res.waterFormat == colorTarget->format) && (res.waterFramebufferDepth == depthTarget->texture.get()))
            {
                return;
            }
            if (res.waterTexture != nullptr) {
                res.retireLater(std::move(res.waterFramebuffer));
                res.retireLater(std::move(res.waterTextureView));
                res.retireLater(std::move(res.waterTexture));
                res.retireLater(std::move(res.waterColorFramebuffer));
                res.retireLater(std::move(res.waterColorTextureView));
                res.retireLater(std::move(res.waterColorTexture));
            }
            RenderClearValue clearValue = RenderClearValue::Color(RenderColor(0.0f, 0.0f, 0.0f, 0.0f), colorTarget->format);
            res.waterTexture = worker->device->createTexture(RenderTextureDesc::ColorTarget(colorTarget->width, colorTarget->height, colorTarget->format, colorTarget->multisampling, &clearValue));
            res.waterTexture->setName("Scene Effects Water Mask");
            res.waterTextureView = res.waterTexture->createTextureView(RenderTextureViewDesc::Texture2D(colorTarget->format));
            const RenderTexture *attachment = res.waterTexture.get();
            res.waterFramebuffer = worker->device->createFramebuffer(RenderFramebufferDesc(&attachment, 1, depthTarget->texture.get()));
            res.waterColorTexture = worker->device->createTexture(RenderTextureDesc::ColorTarget(colorTarget->width, colorTarget->height, colorTarget->format, colorTarget->multisampling, &clearValue));
            res.waterColorTexture->setName("Scene Effects Water Colours");
            res.waterColorTextureView = res.waterColorTexture->createTextureView(RenderTextureViewDesc::Texture2D(colorTarget->format));
            const RenderTexture *colorAttachment = res.waterColorTexture.get();
            res.waterColorFramebuffer = worker->device->createFramebuffer(RenderFramebufferDesc(&colorAttachment, 1, depthTarget->texture.get()));
            res.waterColorDrawn = false;
            res.waterWidth = colorTarget->width;
            res.waterHeight = colorTarget->height;
            res.waterSamples = samples;
            res.waterFormat = colorTarget->format;
            res.waterFramebufferDepth = depthTarget->texture.get();
            res.waterDrawn = false;
        }
    }

    // The settings as the player has them; ray tracing lifts some (RefreshReflections).
    static float userAmbientOcclusion = 0.0f;
    static float userSsgi = 0.0f;
    static float userWaterReflections = 0.0f;
    static float rayTracingStrength = 0.6f;
    static float rayTracingReflections = 0.6f;
    static float rayTracingWaterReflections = 0.6f;
    static std::atomic<float> rayTracingMaterials[3] = { 1.0f, 0.6f, 0.35f };
    // What the last traced scene held, so the traced pass skips rays that can find nothing: any draw whose Parallax
    // material reflects (MaterialShine), and any level cut-out (SunThroughCutout).
    static std::atomic<bool> rayScenesShine{ true };
    static std::atomic<bool> rayScenesLevelCutouts{ true };
    // Whether the last traced scene held a draw with a ray tracing material (SetSceneRayMaterials), so the traced pass looks
    // for them.
    static std::atomic<bool> rayScenesPbr{ false };
    // Ray traced BRDF's roughness and traced subsurface scattering's strength, in percent.
    static std::atomic<uint32_t> rayTracingBrdfPercent{ 0 };
    static std::atomic<uint32_t> rayTracingSubsurfacePercent{ 0 };
    static std::atomic<bool> rayTracingHitColours{ false };
    static std::atomic<bool> rayTracingPlayerShadows{ true };
    // Ray tracing resolution: 0 half, 1 medium, 2 high.
    static std::atomic<uint32_t> rayTracingResolution{ 1u };
    static std::atomic<bool> rayTracingHalf{ false };
    // Graphics > Ray Tracing uses Parallax materials: off, the traced pass ignores the Parallax shapes (metal, tiles, smooth,
    // leaves and grass) its geometries carry.
    static std::atomic<bool> rayTracingParallax{ false };
    static std::atomic<float> rayDetailDistances[2] = { 2000.0f, 4000.0f };
    static std::atomic<float> rayTracingSmoothing{ 0.5f };
    static std::atomic<uint32_t> pathTracingBounces{ 0 };
    // Traced light beams: strength, then the room's light direction (world, towards it), or 0 for the sun.
    static float tracedBeams[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
    static void RefreshReflections();

    void SetSceneEffects(float ambientOcclusion, float radius, uint32_t depthAddress) {
        const std::scoped_lock lock(effectsMutex);
        userAmbientOcclusion = ambientOcclusion;
        RefreshReflections();
        effectsSettings.ambientOcclusionRadius = radius;
        effectsSettings.depthAddress = depthAddress;
    }

    void SetSceneFog(float fog, float start, float length, float red, float green, float blue) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.fog = fog;
        effectsSettings.fogStart = start;
        effectsSettings.fogLength = length;
        effectsSettings.fogColor[0] = red;
        effectsSettings.fogColor[1] = green;
        effectsSettings.fogColor[2] = blue;
    }

    void SetSceneBloom(float bloom, float threshold) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.bloom = bloom;
        effectsSettings.bloomThreshold = threshold;
    }

    void SetSceneDepthOfField(float strength, bool onBanjo) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.depthOfField = strength;
        effectsSettings.depthOfFieldOnBanjo = onBanjo;
    }

    void SetSceneEyeAdaptation(float strength) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.eyeAdaptation = strength;
    }

    void SetSceneHeatHaze(float strength, bool warmOnly) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.heatHaze = strength;
        effectsSettings.heatHazeWarmOnly = warmOnly;
    }

    // Screen-space reflections on, or their debug view: the shiny list is looked up (SceneShinyWanted).
    static std::atomic<bool> shinyWanted{ false };

    void SetSceneEffectsView(uint32_t view, bool compare) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.view = view;
        effectsSettings.compare = compare;
        shinyWanted.store((effectsSettings.screenSpaceReflections > 0.0f) || (view == SceneEffectsViewSsr));
    }

    void SetSceneUnderwater(float tint, float haze) {
        const std::scoped_lock lock(effectsMutex);
        // The haze works without the tint too: a tiny tint keeps the underwater path on.
        effectsSettings.underwaterTint = ((tint <= 0.0f) && (haze > 0.0f)) ? 1e-4f : tint;
        effectsSettings.underwaterHaze = haze;
    }

    void SetSceneRimLight(float strength) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.rimLight = strength;
    }

    void SetSceneToonShading(float world, float characters) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.toonShading = world;
        effectsSettings.toonCharacters = characters;
    }

    bool SceneCharacterToonWanted() {
        const std::scoped_lock lock(effectsMutex);
        return effectsSettings.toonCharacters > 0.0f;
    }

    void SetSceneOutlines(float outlines, float thickness) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.outlines = outlines;
        effectsSettings.outlineThickness = std::clamp(thickness, 0.25f, 8.0f);
    }

    void SetSceneWaterReflections(float strength) {
        const std::scoped_lock lock(effectsMutex);
        userWaterReflections = strength;
        RefreshReflections();
    }

    static std::atomic<bool> sceneIcyLevel{ false };

    void SetSceneIcyLevel(bool enabled) {
        sceneIcyLevel = enabled;
    }

    bool SceneIcyLevel() {
        return sceneIcyLevel.load(std::memory_order_relaxed);
    }

    void SetSceneIceReflections(float strength) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.iceReflections = strength;
    }

    void SetSceneShoreFoam(bool enabled) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.shoreFoam = enabled;
    }

    void SetSceneModernWater(bool enabled, bool stylised) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.modernWater = enabled;
        effectsSettings.stylisedWater = stylised;
    }

    void SetSceneModernUnderwater(float amount, float surfaceY, bool wholeLevel) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.modernUnderwater = amount;
        effectsSettings.modernSurfaceY = surfaceY;
        effectsSettings.modernWholeLevel = wholeLevel;
    }

    bool SceneModernWater() {
        const std::scoped_lock lock(effectsMutex);
        return effectsSettings.modernWater;
    }

    void SetSceneBounceLight(float strength) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.bounceLight = strength;
    }

    void SetSceneScreenSpaceGI(float strength) {
        const std::scoped_lock lock(effectsMutex);
        userSsgi = strength;
        RefreshReflections();
    }

    // Banjo-Tooie: hardware ray tracing (Graphics > Ray tracing). While it is on and the device has ray queries, the
    // reflections are traced, and drawn at 60 at least even with Screen-space reflections at 0 (the switch alone must
    // show something); the setting is kept apart from the strength the pass uses.
    static std::atomic<bool> rayTracingWanted{ false };
    static std::atomic<int> rayTracingSupport{ 0 };
    static float userReflections = 0.0f;
    static float userGlossy = 0.0f;

    // effectsMutex held.
    static float userSunShadows = 0.0f;

    // The settings the traced effects take over: reflections and sun shadows show at 60 at least, ambient occlusion at 50
    // bounce light at 50 and water reflections at 60, while ray tracing is active (the settings themselves are kept apart, and come back when it is off).
    static void RefreshReflections() {
        float strength = userReflections;
        effectsSettings.sunShadows = userSunShadows;
        effectsSettings.ambientOcclusion = userAmbientOcclusion;
        effectsSettings.screenSpaceGI = userSsgi;
        effectsSettings.waterReflections = userWaterReflections;
        if (rayTracingWanted.load() && (rayTracingSupport.load() == 2)) {
            // The least each shows at: the strength (0.6 by default) for reflections, sun shadows and water, a little under it
            // for ambient occlusion and bounce light (the game's own lighting already has some of both).
            const float least = rayTracingStrength;
            strength = std::max(strength, rayTracingReflections);
            effectsSettings.sunShadows = std::max(userSunShadows, least);
            effectsSettings.ambientOcclusion = std::max(userAmbientOcclusion, least * 0.83f);
            effectsSettings.screenSpaceGI = std::max(userSsgi, least * 0.83f);
            effectsSettings.waterReflections = std::max(userWaterReflections, rayTracingWaterReflections);
        }
        effectsSettings.screenSpaceReflections = strength;
        effectsSettings.reflectionGlossiness = userGlossy;
        shinyWanted.store((strength > 0.0f) || (effectsSettings.view == SceneEffectsViewSsr));
    }

    void SetSceneScreenSpaceReflections(float strength, float glossiness) {
        const std::scoped_lock lock(effectsMutex);
        userReflections = strength;
        userGlossy = glossiness;
        RefreshReflections();
    }

    void SetSceneLights(const float *xyzr, uint32_t count) {
        const std::scoped_lock lock(effectsMutex);
        count = std::min(count, SceneMaxLights);
        memcpy(effectsSettings.lights, xyzr, size_t(count) * 4 * sizeof(float));
        effectsSettings.lightCount = count;
    }

    static std::mutex dustMutex;
    static float dustClouds[SceneMaxDust * 8] = {};
    static uint32_t dustCount = 0;

    void SetSceneDust(const float *clouds, uint32_t count) {
        const std::scoped_lock lock(dustMutex);
        dustCount = std::min(count, SceneMaxDust);
        memcpy(dustClouds, clouds, size_t(dustCount) * 8 * sizeof(float));
    }

    static std::mutex lampMutex;
    static std::unordered_set<uint64_t> lampTextures;
    static float lampLights[SceneMaxLights * 4] = {};
    static uint32_t lampLightCount = 0;

    void SetSceneLampLights(const float *xyzr, uint32_t count) {
        const std::scoped_lock lock(lampMutex);
        lampLightCount = std::min(count, SceneMaxLights);
        memcpy(lampLights, xyzr, size_t(lampLightCount) * 4 * sizeof(float));
    }

    void SetSceneLampTextures(const uint64_t *hashes, size_t count) {
        std::unordered_set<uint64_t> textures(hashes, hashes + count);
        const std::scoped_lock lock(lampMutex);
        lampTextures.swap(textures);
    }

    bool SceneLampTexture(uint64_t hash) {
        const std::scoped_lock lock(lampMutex);
        return lampTextures.count(hash) != 0;
    }

    void SetSceneRayTracingHitColours(bool enabled) {
        rayTracingHitColours.store(enabled);
    }

    void SetSceneRayTracingParallax(bool enabled) {
        rayTracingParallax.store(enabled);
    }

    void SetSceneRayTracingResolution(uint32_t resolution) {
        rayTracingResolution.store(std::min(resolution, 2u));
        rayTracingHalf.store(resolution == 0u);
    }

    void SetSceneRayDetailDistances(float half, float quarter) {
        rayDetailDistances[0].store(std::max(half, 0.0f));
        rayDetailDistances[1].store(std::max(quarter, 0.0f));
    }

    void SetSceneRayTracingPlayerShadows(bool enabled) {
        rayTracingPlayerShadows.store(enabled);
    }

    void SetSceneRayTracingSmoothing(float smoothing) {
        rayTracingSmoothing.store(std::clamp(smoothing, 0.0f, 1.0f));
    }

    void SetSceneTracedBeams(float strength, const float *direction) {
        const std::scoped_lock lock(effectsMutex);
        tracedBeams[0] = std::clamp(strength, 0.0f, 1.0f);
        for (int i = 0; i < 3; i++) {
            tracedBeams[i + 1] = (direction != nullptr) ? direction[i] : 0.0f;
        }
    }

    void SetScenePathTracing(uint32_t bounces) {
        pathTracingBounces.store(std::min(bounces, 4u));
    }

    void SetSceneRayTracingStrength(float strength) {
        const std::scoped_lock lock(effectsMutex);
        rayTracingStrength = std::clamp(strength, 0.0f, 1.0f);
        RefreshReflections();
    }

    void SetSceneRayTracingReflections(float reflections, float water, float metal, float tiles, float smooth) {
        rayTracingMaterials[0].store(std::clamp(metal, 0.0f, 1.0f));
        rayTracingMaterials[1].store(std::clamp(tiles, 0.0f, 1.0f));
        rayTracingMaterials[2].store(std::clamp(smooth, 0.0f, 1.0f));
        const std::scoped_lock lock(effectsMutex);
        rayTracingReflections = std::clamp(reflections, 0.0f, 1.0f);
        rayTracingWaterReflections = std::clamp(water, 0.0f, 1.0f);
        RefreshReflections();
    }

    void SetSceneFurSway(float x, float y, float z) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.furSway[0] = x;
        effectsSettings.furSway[1] = y;
        effectsSettings.furSway[2] = z;
    }

    void SetSceneRayTracing(bool enabled) {
        const std::scoped_lock lock(effectsMutex);
        rayTracingWanted.store(enabled);
        RefreshReflections();
    }

    void NoteRayTracingSupport(bool supported) {
        // TOOIE_RAY_TRACING_SUPPORT=0 pretends the device has none (headless test of the fallback).
        const char *forced = std::getenv("TOOIE_RAY_TRACING_SUPPORT");
        if ((forced != nullptr) && (forced[0] == '0')) {
            supported = false;
        }
        const std::scoped_lock lock(effectsMutex);
        rayTracingSupport.store(supported ? 2 : 1);
        RefreshReflections();
    }

    int GetRayTracingSupport() {
        return rayTracingSupport.load();
    }

    bool RayTracingActive() {
        return rayTracingWanted.load() && (rayTracingSupport.load() == 2);
    }

    void SetSceneWaterWaves(float strength, float speed) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.waterWaves = strength;
        effectsSettings.waveSpeed = speed;
    }

    void SetSceneWaterRipples(const float x[3], const float z[3], const float age[3]) {
        const std::scoped_lock lock(effectsMutex);
        for (int i = 0; i < 3; i++) {
            effectsSettings.rippleX[i] = x[i];
            effectsSettings.rippleZ[i] = z[i];
            effectsSettings.rippleAge[i] = age[i];
        }
    }

    namespace {
        std::atomic<float> sceneCameraHeight{ 0.0f };
        std::atomic<bool> sceneCameraKnown{ false };
    }

    void NoteSceneCamera(const interop::float4x4 &projection, const interop::float4x4 &view) {
        // As in RecordSceneEffects: the matrices may be either way round, told apart by the projection.
        const float (&m)[4][4] = projection.m;
        const bool rowVector = std::abs(m[2][3] + 1.0f) <= std::abs(m[3][2] + 1.0f);
        float v[4][4];
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                v[r][c] = rowVector ? view.m[r][c] : view.m[c][r];
            }
        }
        const float det = v[0][0] * (v[1][1] * v[2][2] - v[1][2] * v[2][1]) - v[0][1] * (v[1][0] * v[2][2] - v[1][2] * v[2][0]) + v[0][2] * (v[1][0] * v[2][1] - v[1][1] * v[2][0]);
        if (std::abs(det) <= 1e-12f) {
            return;
        }
        // The camera's world height: the view origin taken back through column 1 of the inverse.
        const float y0 = -(v[0][1] * v[2][2] - v[0][2] * v[2][1]) / det;
        const float y1 = (v[0][0] * v[2][2] - v[0][2] * v[2][0]) / det;
        const float y2 = -(v[0][0] * v[2][1] - v[0][1] * v[2][0]) / det;
        sceneCameraHeight = -(v[3][0] * y0 + v[3][1] * y1 + v[3][2] * y2);
        sceneCameraKnown = true;
    }

    bool GetSceneCameraHeight(float *height) {
        if (!sceneCameraKnown) {
            return false;
        }
        *height = sceneCameraHeight;
        return true;
    }

    namespace {
        // Banjo and his ripples as of each handed-over frame (the game sets them once a frame, before its
        // update, so they are what its last handed-over frame drew).
        struct PlayerFrame {
            uint64_t workload = 0;
            bool used = false;
            float player[3] = {};
            bool grounded = true;
            float rippleX[3] = {}, rippleZ[3] = {}, rippleAge[3] = {};
        };
        PlayerFrame playerFrames[16];
        uint32_t playerFrameNext = 0;
        std::atomic<uint64_t> lastSubmittedWorkload{ 0 };
        std::atomic<bool> anySubmittedWorkload{ false };
        thread_local uint64_t effectsWorkload = 0;
        thread_local bool effectsWorkloadKnown = false;
    }

    void SetScenePlayer(bool valid, float x, float y, float z, bool grounded) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.player[0] = x;
        effectsSettings.player[1] = valid ? y : -1e9f;
        effectsSettings.player[2] = z;
        effectsSettings.playerGrounded = grounded;
        // The volumetric mist's floor: eases towards the ground Banjo stands on (jumps and falls don't move it), and
        // snaps when he is somewhere else altogether (another floor, a warp).
        if (valid) {
            static auto last = std::chrono::steady_clock::now();
            const auto now = std::chrono::steady_clock::now();
            const float dt = std::min(std::chrono::duration<float>(now - last).count(), 0.25f);
            last = now;
            if (!effectsSettings.volAnchorValid || (std::fabs(y - effectsSettings.volAnchor) > 500.0f)) {
                effectsSettings.volAnchor = y;
                effectsSettings.volAnchorValid = true;
            }
            else if (grounded) {
                effectsSettings.volAnchor += (y - effectsSettings.volAnchor) * std::min(1.0f, dt * 0.6f);
            }
        }
        if (anySubmittedWorkload) {
            PlayerFrame &frame = playerFrames[playerFrameNext];
            playerFrameNext = (playerFrameNext + 1) % std::size(playerFrames);
            frame.workload = lastSubmittedWorkload;
            frame.used = true;
            frame.grounded = grounded;
            for (int i = 0; i < 3; i++) {
                frame.player[i] = effectsSettings.player[i];
                frame.rippleX[i] = effectsSettings.rippleX[i];
                frame.rippleZ[i] = effectsSettings.rippleZ[i];
                frame.rippleAge[i] = effectsSettings.rippleAge[i];
            }
        }
    }

    void NoteSceneWorkloadSubmitted(uint64_t workloadId) {
        lastSubmittedWorkload = workloadId;
        anySubmittedWorkload = true;
    }

    void SetSceneEffectsWorkload(uint64_t workloadId) {
        effectsWorkload = workloadId;
        effectsWorkloadKnown = true;
    }

    // Banjo and his ripples as the given workload drew them: the newest kept for it or an earlier one.
    static void UsePlayerFrame(SceneEffectsSettings &settings, uint64_t workloadId) {
        const std::scoped_lock lock(effectsMutex);
        const PlayerFrame *best = nullptr;
        for (const PlayerFrame &frame : playerFrames) {
            if (frame.used && (frame.workload <= workloadId) && ((best == nullptr) || (frame.workload >= best->workload))) {
                best = &frame;
            }
        }
        if (best == nullptr) {
            return;
        }
        settings.playerGrounded = best->grounded;
        for (int i = 0; i < 3; i++) {
            settings.player[i] = best->player[i];
            settings.rippleX[i] = best->rippleX[i];
            settings.rippleZ[i] = best->rippleZ[i];
            settings.rippleAge[i] = best->rippleAge[i];
        }
    }

    void SetSceneLightShafts(float strength) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.lightShafts = strength;
    }

    void SetSceneSunShadowDistance(float distance) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.sunShadowDistance = std::clamp(distance, 500.0f, 40000.0f);
    }

    void SetSceneSunShadows(float strength, bool onBanjo, float softness) {
        const std::scoped_lock lock(effectsMutex);
        userSunShadows = strength;
        RefreshReflections();
        effectsSettings.sunShadowOnBanjo = onBanjo;
        effectsSettings.sunShadowSoftness = std::clamp(softness, 0.0f, 1.0f);
    }

    void SetSceneSun(bool custom, float x, float y, float z) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.customSun = custom;
        if (custom) {
            effectsSettings.sunDirection[0] = x;
            effectsSettings.sunDirection[1] = y;
            effectsSettings.sunDirection[2] = z;
        }
    }

    // The night light textures: read on the render thread while it builds a frame's draws, so they are kept apart
    // from the effects settings and swapped in whole.
    static std::mutex grassTextureMutex;
    static std::unordered_set<uint64_t> grassTextures;
    static std::unordered_set<uint64_t> grassEdgeTextures;

    void SetSceneGrassTextures(const uint64_t *hashes, size_t count) {
        std::unordered_set<uint64_t> textures(hashes, hashes + count);
        const std::scoped_lock lock(grassTextureMutex);
        grassTextures.swap(textures);
    }

    void SetSceneGrassEdgeTextures(const uint64_t *hashes, size_t count) {
        std::unordered_set<uint64_t> textures(hashes, hashes + count);
        const std::scoped_lock lock(grassTextureMutex);
        grassEdgeTextures.swap(textures);
    }

    uint32_t SceneGrassTexture(uint64_t hash) {
        const std::scoped_lock lock(grassTextureMutex);
        if (grassTextures.empty() || (grassTextures.count(hash) != 0)) {
            return 1;
        }
        return (grassEdgeTextures.count(hash) != 0) ? 2 : 0;
    }

    // Shiny textures (metal, tiles) for screen-space reflections: read on the render thread like the ice ones,
    // and only looked up while the reflections are on.
    static std::mutex shinyTextureMutex;
    static std::unordered_set<uint64_t> shinyTextures;

    void SetSceneShinyTextures(const uint64_t *hashes, size_t count) {
        std::unordered_set<uint64_t> textures(hashes, hashes + count);
        const std::scoped_lock lock(shinyTextureMutex);
        shinyTextures.swap(textures);
    }

    bool SceneShinyTexture(uint64_t hash) {
        const std::scoped_lock lock(shinyTextureMutex);
        return shinyTextures.count(hash) != 0;
    }

    bool SceneShinyWanted() {
        return shinyWanted.load();
    }

    // Ice textures: read on the render thread like the grass ones.
    static std::mutex iceTextureMutex;
    static std::unordered_set<uint64_t> iceTextures;

    void SetSceneIceTextures(const uint64_t *hashes, size_t count) {
        std::unordered_set<uint64_t> textures(hashes, hashes + count);
        const std::scoped_lock lock(iceTextureMutex);
        iceTextures.swap(textures);
    }

    static std::unordered_set<uint64_t> iceAnywhereTextures;

    void SetSceneIceAnywhereTextures(const uint64_t *hashes, size_t count) {
        std::unordered_set<uint64_t> textures(hashes, hashes + count);
        const std::scoped_lock lock(iceTextureMutex);
        iceAnywhereTextures.swap(textures);
    }

    uint32_t SceneIceTexture(uint64_t hash) {
        const std::scoped_lock lock(iceTextureMutex);
        return (iceAnywhereTextures.count(hash) != 0) ? 2u : ((iceTextures.count(hash) != 0) ? 1u : 0u);
    }

    static std::mutex snowOffTextureMutex;
    static std::unordered_set<uint64_t> snowOffTextures;

    void SetSceneSnowOffTextures(const uint64_t *hashes, size_t count) {
        std::unordered_set<uint64_t> textures(hashes, hashes + count);
        const std::scoped_lock lock(snowOffTextureMutex);
        snowOffTextures.swap(textures);
    }

    bool SceneSnowOffTexture(uint64_t hash) {
        const std::scoped_lock lock(snowOffTextureMutex);
        return snowOffTextures.count(hash) != 0;
    }

    static std::unordered_set<uint64_t> sandTextures;

    void SetSceneSandTextures(const uint64_t *hashes, size_t count) {
        std::unordered_set<uint64_t> textures(hashes, hashes + count);
        const std::scoped_lock lock(snowOffTextureMutex);
        sandTextures.swap(textures);
    }

    bool SceneSandTexture(uint64_t hash) {
        const std::scoped_lock lock(snowOffTextureMutex);
        return sandTextures.count(hash) != 0;
    }

    static std::mutex nightLightMutex;
    static std::unordered_set<uint64_t> nightLightTextures;

    void SetSceneNightLights(const uint64_t *hashes, size_t count) {
        std::unordered_set<uint64_t> textures(hashes, hashes + count);
        const std::scoped_lock lock(nightLightMutex);
        nightLightTextures.swap(textures);
    }

    bool ComputeSceneNightLights(interop::FrameParams &frameParams) {
        float night = 0.0f;
        {
            const std::scoped_lock lock(effectsMutex);
            if (effectsSettings.timeOfDay) {
                // As DayNight in SceneEffectsPS: from how dark the tint's brightest channel is.
                const float brightest = std::max(effectsSettings.dayTint[0], std::max(effectsSettings.dayTint[1], effectsSettings.dayTint[2]));
                night = std::clamp((0.97f - brightest) / 0.3f, 0.0f, 1.0f);
                // Dusky rain counts a little too.
                night = std::max(night, effectsSettings.dayRain * 0.5f);
            }
        }
        frameParams.nightLights = { night, 1.0f, 0.88f, 0.55f };
        if (night <= 0.0f) {
            return false;
        }
        const std::scoped_lock lock(nightLightMutex);
        return !nightLightTextures.empty();
    }

    bool SceneNightLightTexture(uint64_t hash) {
        const std::scoped_lock lock(nightLightMutex);
        return nightLightTextures.count(hash) != 0;
    }

    static std::mutex parallaxMutex;
    static std::unordered_map<uint64_t, uint32_t> parallaxTextures;

    void SetSceneParallax(float depth, bool original, bool all) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.parallax = std::clamp(depth, 0.0f, 1.0f);
        effectsSettings.parallaxOriginal = original;
        effectsSettings.parallaxAll = all;
    }

    static std::atomic<bool> textureSeamsBlend = true;

    void SetSceneTextureSeams(bool blend) {
        textureSeamsBlend = blend;
    }

    bool SceneTextureSeams() {
        return textureSeamsBlend;
    }

    void SetSceneParallaxTextures(const uint64_t *hashes, const uint8_t *ranges, size_t count, const uint8_t *styles, const uint8_t *fineDepths) {
        std::unordered_map<uint64_t, uint32_t> textures;
        for (size_t i = 0; i < count; i++) {
            // The style goes in bits 17 to 23, which the renderer moves up by 8 into RasterParams.nightLight, and the shape's
            // bit 3 (style bit 7) in bit 24, which the renderer moves to RASTER_PARALLAX_SHAPE_HIGH, and a fine depth in bits
            // 25 to 29, which it moves to RASTER_PARALLAX_FINE_DEPTH.
            const uint32_t style = (styles != nullptr) ? uint32_t(styles[i]) : 0u;
            const uint32_t fine = (fineDepths != nullptr) ? (uint32_t(fineDepths[i]) & 0x1Fu) : 0u;
            textures[hashes[i]] = uint32_t(ranges[i * 2]) | (uint32_t(std::max(ranges[i * 2 + 1], uint8_t(ranges[i * 2] + 1))) << 8) |
                ((style & 0x7Fu) << 17) | ((style & 0x80u) << 17) | (fine << 25);
        }
        const std::scoped_lock lock(parallaxMutex);
        parallaxTextures.swap(textures);
    }

    static std::mutex pickMutex;
    static bool pickOn = false;
    static float pickX = 0.5f, pickY = 0.5f;
    static uint32_t pickLayer = 0;
    static float outputRect[4] = { 0.0f, 0.0f, 1.0f, 1.0f };
    struct PickHit {
        float w;
        uint64_t hash;
        uint32_t matrixId;
        bool operator<(const PickHit &other) const { return w < other.w; }
    };
    static std::vector<PickHit> pickHits;
    static uint64_t pickHash = 0;
    static uint32_t pickLayers = 0;
    static uint32_t pickMatrixId = 0;
    static bool pickHighlight = true;

    void SetScenePick(bool on, float x, float y, uint32_t layer) {
        const std::scoped_lock lock(pickMutex);
        pickOn = on;
        pickX = x;
        pickY = y;
        pickLayer = layer;
        if (!on) {
            pickHash = 0;
            pickLayers = 0;
            pickMatrixId = 0;
        }
    }

    void ScenePickResult(uint64_t &hash, uint32_t &layers) {
        const std::scoped_lock lock(pickMutex);
        hash = pickHash;
        layers = pickLayers;
    }

    void SetSceneOutputRect(float x, float y, float width, float height) {
        const std::scoped_lock lock(pickMutex);
        outputRect[0] = x;
        outputRect[1] = y;
        outputRect[2] = std::max(width, 1e-4f);
        outputRect[3] = std::max(height, 1e-4f);
    }

    bool ScenePickCursor(float &ndcX, float &ndcY, uint64_t &highlight) {
        const std::scoped_lock lock(pickMutex);
        ndcX = ((pickX - outputRect[0]) / outputRect[2]) * 2.0f - 1.0f;
        ndcY = 1.0f - ((pickY - outputRect[1]) / outputRect[3]) * 2.0f;
        highlight = pickHighlight ? pickHash : 0;
        return pickOn;
    }

    void AddScenePickHit(float w, uint64_t hash, uint32_t matrixId) {
        const std::scoped_lock lock(pickMutex);
        if (pickHits.size() < 4096) {
            pickHits.push_back({ w, hash, matrixId });
        }
    }

    uint32_t ScenePickMatrixId() {
        const std::scoped_lock lock(pickMutex);
        return pickMatrixId;
    }

    void SetScenePickHighlight(bool on) {
        const std::scoped_lock lock(pickMutex);
        pickHighlight = on;
    }

    void FinishScenePick() {
        const std::scoped_lock lock(pickMutex);
        if (!pickOn) {
            pickHits.clear();
            return;
        }
        // Nearest first, each texture once (a wall drawn in several pieces is one layer).
        std::stable_sort(pickHits.begin(), pickHits.end());
        std::vector<uint64_t> layers;
        std::vector<uint32_t> layerMatrixIds;
        for (const auto &hit : pickHits) {
            if (std::find(layers.begin(), layers.end(), hit.hash) == layers.end()) {
                layers.push_back(hit.hash);
                layerMatrixIds.push_back(hit.matrixId);
            }
        }
        pickLayers = uint32_t(layers.size());
        pickHash = layers.empty() ? 0 : layers[pickLayer % layers.size()];
        pickMatrixId = layers.empty() ? 0 : layerMatrixIds[pickLayer % layers.size()];
        pickHits.clear();
    }

    static bool parallaxAllTextures = false;
    static bool parallaxOriginalTextures = true;

    bool ComputeSceneParallax(interop::FrameParams &frameParams) {
        float depth = 0.0f;
        float ground = 0.0f;
        {
            const std::scoped_lock lock(effectsMutex);
            depth = effectsSettings.parallax;
            ground = effectsSettings.groundDisplacement;
            parallaxAllTextures = effectsSettings.parallaxAll;
            parallaxOriginalTextures = effectsSettings.parallaxOriginal;
        }
        // At the full setting, 16 world units deep (Banjo is about 150 tall, a stone block about 60 to 120 across);
        // flat by 2800 units away, where a few texels cover a pixel and it can't be seen. Up to 24 steps down the ray.
        frameParams.parallaxParams = { 16.0f * depth, 1300.0f, 2800.0f, 24.0f };
        // The deepest parts and the shadows the stones cast about a third darker, less at a lower setting.
        const float shade = std::min(1.0f, 0.4f + depth * 0.6f);
        frameParams.parallaxShading = { 0.3f * shade, 0.3f * shade, 0.0f, 0.0f };
        // On whenever it is set, as a texture pack's height maps need nothing else. (And with displaced ground, which takes
        // the list's textures and shapes.)
        return (depth > 0.0f) || (ground > 0.0f);
    }

    uint32_t SceneParallaxTexture(uint64_t hash) {
        if (!parallaxOriginalTextures) {
            return 0u;
        }
        const std::scoped_lock lock(parallaxMutex);
        const auto it = parallaxTextures.find(hash);
        if (it != parallaxTextures.end()) {
            return it->second;
        }
        // Any other texture, with every texture on: from dark grey to light grey.
        return parallaxAllTextures ? (40u | (190u << 8)) : 0u;
    }

    // Ray Tracing Material Pick Mode's materials: each picked texture's index (from 1) in the table the traced pass reads
    // (SceneMaxRayMaterials records, written beside the ray geometries), and the two words of its record.
    static std::mutex rayMaterialMutex;
    static std::unordered_map<uint64_t, uint32_t> rayMaterialIndices;
    static std::vector<uint32_t> rayMaterialWords;
    static std::atomic<bool> rayMaterialsAny{ false };

    void SetSceneRayTracingBrdfSubsurface(float brdfRoughness, float subsurface) {
        rayTracingBrdfPercent.store(uint32_t(std::round(std::clamp(brdfRoughness, 0.0f, 1.0f) * 100.0f)));
        rayTracingSubsurfacePercent.store(uint32_t(std::round(std::clamp(subsurface, 0.0f, 1.0f) * 100.0f)));
    }

    void SetSceneRayMaterials(const uint64_t *hashes, const uint32_t *albedoRoughness, const uint32_t *metalnessEmissive, size_t count) {
        count = std::min<size_t>(count, SceneMaxRayMaterials);
        std::unordered_map<uint64_t, uint32_t> indices;
        std::vector<uint32_t> words;
        for (size_t i = 0; i < count; i++) {
            indices[hashes[i]] = uint32_t(i + 1);
            words.push_back(albedoRoughness[i]);
            words.push_back(metalnessEmissive[i]);
        }
        const std::scoped_lock lock(rayMaterialMutex);
        rayMaterialIndices.swap(indices);
        rayMaterialWords.swap(words);
        rayMaterialsAny.store(count != 0);
    }

    uint32_t SceneMaterialTexture(uint64_t hash) {
        uint32_t material = 0u;
        {
            const std::scoped_lock lock(parallaxMutex);
            const auto it = parallaxTextures.find(hash);
            if (it != parallaxTextures.end()) {
                material = (((it->second >> 17) & 0x7u) | (((it->second >> 24) & 0x1u) << 3)) + 1u;
            }
        }
        if (rayMaterialsAny.load()) {
            const std::scoped_lock lock(rayMaterialMutex);
            const auto it = rayMaterialIndices.find(hash);
            if (it != rayMaterialIndices.end()) {
                material |= it->second << SceneRayMaterialIndexShift;
            }
        }
        return material;
    }

    void SetSceneAurora(bool enabled) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.dayAurora = enabled;
    }

    void SetSceneMoonPhase(uint32_t phase) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.dayMoonPhase = phase & 7u;
    }

    void SetSceneVolumetric(float mist, float fog, uint32_t fogPreset, uint32_t cloudType, float mistOffset) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.volMist = std::clamp(mist, 0.0f, 1.0f);
        effectsSettings.volFog = std::clamp(fog, 0.0f, 1.0f);
        effectsSettings.volFogPreset = std::min(fogPreset, 6u);
        effectsSettings.volCloudType = std::min(cloudType, 7u);
        effectsSettings.volMistOffset = std::clamp(mistOffset, -240.0f, 240.0f);
    }

    // The cloud shape (cover 0 to 1, height 0.25 to 4, thickness 0.1 to 2, speed 0 to 8) in 6 bits each, with
    // F8 compare as the sign, so it fits in one float of the effects' push constants (CloudShape in
    // SceneEffectsPS.hlsl). Height steps in log2 and speed in its square root, as the settings do.
    static float PackSceneClouds(const float shape[4], bool compare) {
        auto bits = [](float v, float low, float high) {
            return uint32_t(std::lround(std::clamp((v - low) / (high - low), 0.0f, 1.0f) * 63.0f));
        };
        const uint32_t packed = bits(shape[0], 0.0f, 1.0f) | (bits(std::log2(std::max(shape[1], 0.25f)), -2.0f, 2.0f) << 6) |
            (bits(shape[2], 0.1f, 2.0f) << 12) | (bits(std::sqrt(std::max(shape[3], 0.0f)), 0.0f, std::sqrt(8.0f)) << 18);
        return compare ? -(float(packed) + 1.0f) : float(packed);
    }

    void SetSceneClouds(float cover, float height, float thickness, float speed) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.dayCloudShape[0] = std::clamp(cover, 0.0f, 1.0f);
        effectsSettings.dayCloudShape[1] = std::clamp(height, 0.25f, 4.0f);
        effectsSettings.dayCloudShape[2] = std::clamp(thickness, 0.1f, 2.0f);
        effectsSettings.dayCloudShape[3] = std::clamp(speed, 0.0f, 8.0f);
    }

    void SetSceneRainDetail(float wet, bool drops) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.dayWet = std::clamp(wet, 0.0f, 1.0f);
        effectsSettings.dayDrops = drops;
    }

    void SetSceneWeather(float rain, float flash, bool snow) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.dayRain = std::clamp(rain, 0.0f, 1.0f);
        effectsSettings.dayFlash = std::clamp(flash, 0.0f, 1.0f);
        effectsSettings.daySnow = snow;
    }

    void SetSceneTimeOfDay(bool enabled, const float tint[3], float shafts, bool flare, bool fireflies, bool clouds) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.dayFlare = flare;
        effectsSettings.dayFireflies = fireflies;
        effectsSettings.dayClouds = clouds;
        effectsSettings.timeOfDay = enabled;
        for (int i = 0; i < 3; i++) {
            effectsSettings.dayTint[i] = enabled ? std::clamp(tint[i], 0.0f, 1.27f) : 1.0f;
        }
        effectsSettings.dayShafts = enabled ? std::clamp(shafts, 0.0f, 1.0f) : 1.0f;
    }

    void SetSceneGrass(float amount, float height, float distance, float density, float patches) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.grass = amount;
        effectsSettings.grassHeight = height;
        effectsSettings.grassDistance = distance;
        effectsSettings.grassDensity = std::clamp(density, 0.1f, 2.0f);
        effectsSettings.grassPatches = std::clamp(patches, 0.0f, 1.0f);
    }

    void SetSceneSnow(bool on, float height, bool strictColor, float detail, float refillAfter, float lodDistance, uint32_t map, bool sand) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.snowRefillAfter = std::max(refillAfter, 0.0f);
        effectsSettings.snowLodDistance = std::clamp(lodDistance, 100.0f, 20000.0f);
        if (map != effectsSettings.snowMap) {
            // Another map (a hut and back counts twice): the trail starts afresh.
            effectsSettings.snowMap = map;
            effectsSettings.snowMapVisit++;
        }
        effectsSettings.snowDetail = std::clamp(detail, 0.25f, 1.0f);
        effectsSettings.snowStrictColor = strictColor;
        effectsSettings.snowSand = sand;
        effectsSettings.snow = on && (height > 0.0f);
        effectsSettings.snowHeight = std::clamp(height, 0.0f, 3.0f);
    }

    void SetSceneGrassBlades(float thickness, float randomLength, bool chunky, float chunkSize, bool pixelated, float pixelSize, float blend) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.grassThickness = std::clamp(thickness, 0.25f, 4.0f);
        effectsSettings.grassRandomLength = std::clamp(randomLength, 0.0f, 1.0f);
        effectsSettings.grassChunky = chunky;
        effectsSettings.grassChunkSize = std::clamp(chunkSize, 1.0f, 4.0f);
        effectsSettings.grassPixelated = pixelated;
        effectsSettings.grassPixelSize = std::clamp(pixelSize, 0.25f, 8.0f);
        effectsSettings.grassBlend = std::clamp(blend, 0.0f, 1.0f);
    }

    void SetSceneGrassCulling(bool frustum, bool occlusion, bool chunking) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.grassCulling = (frustum ? GRASS_CULL_FRUSTUM : 0u) | (occlusion ? GRASS_CULL_OCCLUSION : 0u) | (chunking ? GRASS_CULL_CHUNKS : 0u);
    }

    uint32_t SceneGrassCulling() {
        const std::scoped_lock lock(effectsMutex);
        // Test aid: TOOIE_GRASS_CULL=<0-7> sets the flags instead (1 frustum, 2 occlusion, 4 chunking).
        static const char *forced = getenv("TOOIE_GRASS_CULL");
        return (forced != nullptr) ? (uint32_t(atoi(forced)) & 0x7u) : effectsSettings.grassCulling;
    }

    void SetSceneGrassLod(float lod, bool halfRate) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.grassLod = std::clamp(lod, 0.0f, 1.0f);
        effectsSettings.grassHalfRate = halfRate;
    }

    bool SceneGrassHalfRate() {
        const std::scoped_lock lock(effectsMutex);
        // Test aid: TOOIE_GRASS_HALF=0 or 1 instead of the setting.
        static const char *forced = getenv("TOOIE_GRASS_HALF");
        return (forced != nullptr) ? (forced[0] == '1') : effectsSettings.grassHalfRate;
    }

    void SetSceneGrassRayTracing(bool enabled) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.grassRayTracing = enabled;
    }

    float SceneGrassRayReach() {
        if (!RayTracingActive()) {
            return 0.0f;
        }
        const std::scoped_lock lock(effectsMutex);
        // Test aid: TOOIE_GRASS_RT=0 or 1 instead of the setting.
        static const char *forced = getenv("TOOIE_GRASS_RT");
        const bool wanted = (forced != nullptr) ? (forced[0] == '1') : effectsSettings.grassRayTracing;
        // Out to 1500 units: further off a blade's shadow is too small to see, and the blades too many.
        return wanted ? std::min(effectsSettings.grassDistance, 1500.0f) : 0.0f;
    }

    void SetSceneFur(float amount, float length, float density, float noisiness) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.fur = amount;
        effectsSettings.furLength = length;
        effectsSettings.furDensity = std::clamp(density, 0.1f, 4.0f);
        effectsSettings.furNoisiness = std::clamp(noisiness, 0.0f, 1.0f);
    }

    namespace {
        struct FurVertexBlock {
            uint32_t address;
            std::vector<uint8_t> flags;
            float anchorScale;
        };
        std::mutex furVertexMutex;
        std::vector<FurVertexBlock> furVertexBlocks;
    }

    void SetFurVertexFlags(uint32_t address, const std::vector<uint8_t> &flags, float anchorScale) {
        const std::scoped_lock lock(furVertexMutex);
        auto found = std::find_if(furVertexBlocks.begin(), furVertexBlocks.end(), [&](const FurVertexBlock &b) { return b.address == address; });
        if (flags.empty()) {
            if (found != furVertexBlocks.end()) {
                furVertexBlocks.erase(found);
            }
        }
        else if (found != furVertexBlocks.end()) {
            found->flags = flags;
            found->anchorScale = anchorScale;
        }
        else {
            // (A few models at most; the oldest goes when another is loaded in its place.)
            if (furVertexBlocks.size() >= 8) {
                furVertexBlocks.erase(furVertexBlocks.begin());
            }
            furVertexBlocks.push_back({ address, flags, anchorScale });
        }
    }

    void FurVertexFlags(uint32_t address, uint32_t stride, uint32_t count, uint8_t *out) {
        std::fill(out, out + count, uint8_t(FUR_VERTEX_UNKNOWN));
        const std::scoped_lock lock(furVertexMutex);
        for (const FurVertexBlock &b : furVertexBlocks) {
            const uint64_t end = uint64_t(b.address) + uint64_t(b.flags.size()) * 16;
            if ((address < b.address) || (address >= end)) {
                continue;
            }
            for (uint32_t i = 0; i < count; i++) {
                const uint64_t at = uint64_t(address) + uint64_t(i) * stride;
                if ((at < end) && (((at - b.address) % 16) == 0)) {
                    out[i] = b.flags[(at - b.address) / 16] | FUR_VERTEX_IN_BLOCK;
                }
            }
            return;
        }
    }

    float FurVertexAnchorScale() {
        const std::scoped_lock lock(furVertexMutex);
        return furVertexBlocks.empty() ? 1.0f : furVertexBlocks.back().anchorScale;
    }

    void SetSceneKazooieFeathers(float amount, float size, float length, float density, float noisiness, float transparency) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.feathers = std::clamp(amount, 0.0f, 1.0f);
        effectsSettings.featherSize = std::clamp(size, 0.25f, 4.0f);
        effectsSettings.featherLength = std::clamp(length, 0.25f, 4.0f);
        effectsSettings.featherDensity = std::clamp(density, 0.25f, 4.0f);
        effectsSettings.featherNoisiness = std::clamp(noisiness, 0.0f, 1.0f);
        effectsSettings.featherTransparency = std::clamp(transparency, 0.0f, 1.0f);
    }

    void SetSceneNpcFur(float amount, float length, float density, float noisiness) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.npcFur = amount;
        effectsSettings.npcFurLength = length;
        effectsSettings.npcFurDensity = std::clamp(density, 0.1f, 4.0f);
        effectsSettings.npcFurNoisiness = std::clamp(noisiness, 0.0f, 1.0f);
    }

    void SetSceneNpcFeathers(float amount, float size, float length, float density, float noisiness, float transparency) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.npcFeathers = std::clamp(amount, 0.0f, 1.0f);
        effectsSettings.npcFeatherSize = std::clamp(size, 0.25f, 4.0f);
        effectsSettings.npcFeatherLength = std::clamp(length, 0.25f, 4.0f);
        effectsSettings.npcFeatherDensity = std::clamp(density, 0.25f, 4.0f);
        effectsSettings.npcFeatherNoisiness = std::clamp(noisiness, 0.0f, 1.0f);
        effectsSettings.npcFeatherTransparency = std::clamp(transparency, 0.0f, 1.0f);
    }

    bool SceneKazooieFeathers() {
        const std::scoped_lock lock(effectsMutex);
        return (effectsSettings.feathers > 0.0f) || (effectsSettings.npcFeathers > 0.0f);
    }

    // Enough shells that the strands read as strands at the fur's full length.
    static constexpr uint32_t FurShells = 12;

    uint32_t SceneFurShells() {
        const std::scoped_lock lock(effectsMutex);
        return ((effectsSettings.fur > 0.0f) || (effectsSettings.npcFur > 0.0f)) ? FurShells : 0;
    }

    // The shaders read a depth as (z / w + 1) / 2, but RT64 writes z / w * scale + translate with the game's own viewport
    // depth (511/1024 in Banjo-Tooie, not 1/2). Folding the difference into the depth terms keeps the shaders' formula
    // right. Small with the usual near plane, it made the 3D world read as far nearer than it is when the game shortens
    // the near plane (the camera close to the ground or a wall): no fog, and effects measured wrongly.
    static interop::float4 DepthTermsForViewport(const interop::float4 &t, float depthScale, float depthTranslate) {
        if (std::abs(depthScale) < 1e-6f) {
            return t;
        }
        const float a = 0.5f / depthScale;
        const float b = (0.5f - depthTranslate) / depthScale;
        return interop::float4{ t.x - b * t.z, t.y - b * t.w, a * t.z, a * t.w };
    }

    bool SceneParallaxCamera(const interop::float4x4 &projection, const interop::float3 &viewportScale, const interop::float3 &viewportTranslate,
        float viewportWidth, float viewportHeight, interop::float4 &depthTerms, interop::float4 &projectionTerms)
    {
        // As ComputeSceneGrass works out grassDepthTerms and grassProjection.
        const float (&m)[4][4] = projection.m;
        if ((std::abs(m[2][3] + 1.0f) > 0.01f) && (std::abs(m[3][2] + 1.0f) > 0.01f)) {
            return false;
        }
        const bool rowVector = std::abs(m[2][3] + 1.0f) <= std::abs(m[3][2] + 1.0f);
        depthTerms = DepthTermsForViewport(rowVector ? interop::float4{ m[2][2], m[3][2], m[2][3], m[3][3] } : interop::float4{ m[2][2], m[2][3], m[3][2], m[3][3] }, viewportScale.z, viewportTranslate.z);
        projectionTerms = { m[0][0], m[1][1], viewportWidth, viewportHeight };
        return true;
    }

    bool ComputeSceneFur(const interop::float4x4 &projection, const interop::float4x4 &viewProj, const interop::float3 &viewportScale,
        const interop::float3 &viewportTranslate, const interop::float2 &resolution, interop::FrameParams &frameParams)
    {
        SceneEffectsSettings settings = GetSceneEffects();
        if (((settings.fur <= 0.0f) && (settings.npcFur <= 0.0f)) || (resolution.x <= 0.0f) || (resolution.y <= 0.0f)) {
            return false;
        }

        // As ComputeSceneGrass: row-vector matrices are told apart by the projection.
        const float (&m)[4][4] = projection.m;
        const bool rowVector = std::abs(m[2][3] + 1.0f) <= std::abs(m[3][2] + 1.0f);
        if ((std::abs(m[2][3] + 1.0f) > 0.01f) && (std::abs(m[3][2] + 1.0f) > 0.01f)) {
            return false;
        }

        // One world unit along each axis in the game's clip space, then as RasterVS has its positions.
        const float halfWidth = resolution.x / 2.0f;
        const float halfHeight = resolution.y / 2.0f;
        interop::float4 *axes[3] = { &frameParams.furClipX, &frameParams.furClipY, &frameParams.furClipZ };
        for (int a = 0; a < 3; a++) {
            float clip[4];
            for (int c = 0; c < 4; c++) {
                clip[c] = rowVector ? viewProj.m[a][c] : viewProj.m[c][a];
            }
            *axes[a] = {
                clip[0] * (viewportScale.x / halfWidth) + clip[3] * ((viewportTranslate.x - halfWidth) / halfWidth),
                clip[1] * (viewportScale.y / halfHeight) - clip[3] * ((viewportTranslate.y - halfHeight) / halfHeight),
                clip[2] * viewportScale.z + clip[3] * viewportTranslate.z,
                clip[3]
            };
        }

        // About 2.5 units long (Banjo is about 150 tall), fine strands (the noise's lattice every 0.4 units at density
        // 100), the amount making them thin out more slowly (a thicker coat).
        const float amount = std::min(settings.fur, 1.0f);
        frameParams.furParams = { 2.5f * std::max(settings.furLength, 0.1f), 2.4f * settings.furDensity, 0.6f - 0.3f * amount, settings.furNoisiness };
        frameParams.furSway = { settings.furSway[0], settings.furSway[1], settings.furSway[2], 0.0f };
        const float npcAmount = std::min(settings.npcFur, 1.0f);
        frameParams.npcFurParams = { 2.5f * std::max(settings.npcFurLength, 0.1f), 2.4f * settings.npcFurDensity, 0.6f - 0.3f * npcAmount, settings.npcFurNoisiness };
        return true;
    }

    // Enough shells that the knee-high blades look solid from the side.
    static constexpr uint32_t GrassShells = 24;

    // Real blades (GrassGS.hlsl): the finest grid's cell size at density 1, and how many blades a pass can grow on a triangle.
    static constexpr float GrassBladeCell = 3.0f;
    static constexpr uint32_t GrassBladeInvocations = 32;
    static constexpr uint32_t GrassBladesPerInvocation = 11;
    static constexpr uint32_t GrassBladeMaxPasses = 31;

    uint32_t SceneGrassBladePasses(const float (&low)[2], const float (&high)[2], float distanceToCamera, float lodNear, float baseCell) {
        // As GrassCellSize in GrassGS.hlsl: the passes the triangle's grid needs at its distance, at most GrassBladeMaxPasses.
        const float cell = baseCell * std::exp2(std::max(std::floor(std::log2(std::max(distanceToCamera, 1.0f) / lodNear)), 0.0f));
        const float cells = (std::floor((high[0] - low[0]) / cell) + 2.0f) * (std::floor((high[1] - low[1]) / cell) + 2.0f);
        const float perPass = float(GrassBladeInvocations * GrassBladesPerInvocation);
        return std::clamp(uint32_t(std::ceil(cells / perPass)), 1u, GrassBladeMaxPasses);
    }

    uint32_t SceneGrassShells() {
        const std::scoped_lock lock(effectsMutex);
        return (effectsSettings.grass > 0.0f) ? GrassShells : 0;
    }

    // Gauss-Jordan elimination with partial pivoting; false when the matrix can't be inverted.
    static bool InvertMatrix4(const double (&m)[4][4], double (&out)[4][4]) {
        double a[4][8];
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                a[r][c] = m[r][c];
                a[r][c + 4] = (r == c) ? 1.0 : 0.0;
            }
        }
        for (int c = 0; c < 4; c++) {
            int pivot = c;
            for (int r = c + 1; r < 4; r++) {
                if (std::abs(a[r][c]) > std::abs(a[pivot][c])) {
                    pivot = r;
                }
            }
            if (std::abs(a[pivot][c]) < 1e-12) {
                return false;
            }
            if (pivot != c) {
                for (int k = 0; k < 8; k++) {
                    std::swap(a[c][k], a[pivot][k]);
                }
            }
            const double d = a[c][c];
            for (int k = 0; k < 8; k++) {
                a[c][k] /= d;
            }
            for (int r = 0; r < 4; r++) {
                if ((r != c) && (a[r][c] != 0.0)) {
                    const double f = a[r][c];
                    for (int k = 0; k < 8; k++) {
                        a[r][k] -= f * a[c][k];
                    }
                }
            }
        }
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                out[r][c] = a[r][c + 4];
            }
        }
        return true;
    }

    bool ComputeSceneGrass(const interop::float4x4 &projection, const interop::float4x4 &view, const interop::float4x4 &viewProj,
        const interop::float3 &viewportScale, const interop::float3 &viewportTranslate, const interop::float2 &resolution,
        float viewportWidth, float viewportHeight, uint64_t workloadId, interop::FrameParams &frameParams)
    {
        SceneEffectsSettings settings = GetSceneEffects();
        // (Deep snow, Kazooie's and NPCs' feathers and parallax mapping need the camera's terms worked out here too.)
        if (((settings.grass <= 0.0f) && !settings.snow && (settings.feathers <= 0.0f) && (settings.npcFeathers <= 0.0f) && (settings.parallax <= 0.0f) && (settings.groundDisplacement <= 0.0f)) || (resolution.x <= 0.0f) || (resolution.y <= 0.0f)) {
            return false;
        }
        UsePlayerFrame(settings, workloadId);

        // As in RecordSceneEffects: the game's matrices are row-vector (clip = v * M), told apart by the projection.
        const float (&m)[4][4] = projection.m;
        const bool rowVector = std::abs(m[2][3] + 1.0f) <= std::abs(m[3][2] + 1.0f);
        if ((std::abs(m[2][3] + 1.0f) > 0.01f) && (std::abs(m[3][2] + 1.0f) > 0.01f)) {
            return false;
        }

        // The full blade height straight up in world space, in the game's clip space, then as RasterVS has its
        // positions: the RSP's screen position (ndc * viewport scale + translate) back over the resolution, times w.
        const float height = 36.0f * settings.grassHeight;
        float clip[4];
        for (int c = 0; c < 4; c++) {
            clip[c] = height * (rowVector ? viewProj.m[1][c] : viewProj.m[c][1]);
        }
        const float halfWidth = resolution.x / 2.0f;
        const float halfHeight = resolution.y / 2.0f;
        frameParams.grassClipUp = {
            clip[0] * (viewportScale.x / halfWidth) + clip[3] * ((viewportTranslate.x - halfWidth) / halfWidth),
            clip[1] * (viewportScale.y / halfHeight) - clip[3] * ((viewportTranslate.y - halfHeight) / halfHeight),
            clip[2] * viewportScale.z + clip[3] * viewportTranslate.z,
            clip[3]
        };

        // Real blades (GrassGS.hlsl): the whole map from world space to those positions, and back.
        double toClip[4][4];
        for (int j = 0; j < 4; j++) {
            float c[4];
            for (int k = 0; k < 4; k++) {
                c[k] = rowVector ? viewProj.m[j][k] : viewProj.m[k][j];
            }
            toClip[0][j] = c[0] * (viewportScale.x / halfWidth) + c[3] * ((viewportTranslate.x - halfWidth) / halfWidth);
            toClip[1][j] = c[1] * (viewportScale.y / halfHeight) - c[3] * ((viewportTranslate.y - halfHeight) / halfHeight);
            toClip[2][j] = c[2] * viewportScale.z + c[3] * viewportTranslate.z;
            toClip[3][j] = c[3];
        }
        double inverse[4][4];
        if (!InvertMatrix4(toClip, inverse)) {
            return false;
        }
        for (int r = 0; r < 4; r++) {
            frameParams.grassWorldToClip[r] = { float(toClip[r][0]), float(toClip[r][1]), float(toClip[r][2]), float(toClip[r][3]) };
            frameParams.grassClipToWorld[r] = { float(inverse[r][0]), float(inverse[r][1]), float(inverse[r][2]), float(inverse[r][3]) };
        }

        frameParams.grassDepthTerms = DepthTermsForViewport(rowVector ? interop::float4{ m[2][2], m[3][2], m[2][3], m[3][3] } : interop::float4{ m[2][2], m[2][3], m[3][2], m[3][3] }, viewportScale.z, viewportTranslate.z);
        frameParams.grassProjection = { m[0][0], m[1][1], viewportWidth, viewportHeight };

        // View space back to world space, as RecordSceneEffects does it.
        float v[4][4];
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                v[r][c] = rowVector ? view.m[r][c] : view.m[c][r];
            }
        }
        const float det = v[0][0] * (v[1][1] * v[2][2] - v[1][2] * v[2][1]) - v[0][1] * (v[1][0] * v[2][2] - v[1][2] * v[2][0]) + v[0][2] * (v[1][0] * v[2][1] - v[1][1] * v[2][0]);
        if (std::abs(det) <= 1e-12f) {
            return false;
        }
        const float x0 = (v[1][1] * v[2][2] - v[1][2] * v[2][1]) / det;
        const float x1 = -(v[1][0] * v[2][2] - v[1][2] * v[2][0]) / det;
        const float x2 = (v[1][0] * v[2][1] - v[1][1] * v[2][0]) / det;
        const float y0 = -(v[0][1] * v[2][2] - v[0][2] * v[2][1]) / det;
        const float y1 = (v[0][0] * v[2][2] - v[0][2] * v[2][0]) / det;
        const float y2 = -(v[0][0] * v[2][1] - v[0][1] * v[2][0]) / det;
        const float z0 = (v[0][1] * v[1][2] - v[0][2] * v[1][1]) / det;
        const float z1 = -(v[0][0] * v[1][2] - v[0][2] * v[1][0]) / det;
        const float z2 = (v[0][0] * v[1][1] - v[0][1] * v[1][0]) / det;
        frameParams.grassWorldX = { x0, x1, x2, -(v[3][0] * x0 + v[3][1] * x1 + v[3][2] * x2) };
        frameParams.grassWorldY = { y0, y1, y2, -(v[3][0] * y0 + v[3][1] * y1 + v[3][2] * y2) };
        frameParams.grassWorldZ = { z0, z1, z2, -(v[3][0] * z0 + v[3][1] * z1 + v[3][2] * z2) };

        // A tuft of five blades every 6 units (Banjo is about 150 tall); fewer cells hold one at lower amounts.
        frameParams.grassParams = { height, std::sqrt(settings.grassDensity) / 6.0f, std::max(settings.grassDistance, 100.0f), 0.35f + 0.65f * std::min(settings.grass, 1.0f) };
        frameParams.grassPlayer = { settings.player[0], settings.player[2], settings.player[1], 45.0f };

        // A breeze from one side; Grass.hlsli rolls waves across the field along it.
        static const auto startTime = std::chrono::steady_clock::now();
        const float now = std::chrono::duration<float>(std::chrono::steady_clock::now() - startTime).count();
        frameParams.grassWind = { 0.85f, 0.5f, std::fmod(now, 3600.0f), 1.0f };
        // Real blades: the grid coarsens from the LOD distance (none with LOD off: every blade out to the grass
        // distance; from 150 units away at full LOD, between them evenly in doublings), wind noise 260 units across
        // drifting 0.12 of that a second, and the finest grid's cells 3 units wide at density 1 (twice the density,
        // twice the blades).
        const float grassReach = std::max(settings.grassDistance, 100.0f);
        const float grassLodNear = (settings.grassLod <= 0.0f) ? 1.0e6f : grassReach * std::pow(std::min(150.0f / grassReach, 1.0f), settings.grassLod);
        frameParams.grassBlades = { grassLodNear, 260.0f, 0.12f, (settings.grassChunky ? settings.grassChunkSize : 1.0f) * GrassBladeCell / std::sqrt(settings.grassDensity) };
        // Kazooie's feathers: about 5.5 units long and 2.4 wide at size 1 (her head is about 25 units across), packed
        // so each spot of her is under about two of them.
        const float featherLength = 5.5f * settings.featherSize * settings.featherLength;
        const float featherWidth = 2.4f * settings.featherSize;
        frameParams.featherParams = { featherLength, featherWidth,
            (0.8f + 1.6f * settings.feathers) * settings.featherDensity / (featherLength * featherWidth * 0.55f), 0.35f };
        frameParams.featherStyle = { settings.featherNoisiness, settings.featherTransparency, 0.0f, 0.0f };
        const float npcFeatherLength = 5.5f * settings.npcFeatherSize * settings.npcFeatherLength;
        const float npcFeatherWidth = 2.4f * settings.npcFeatherSize;
        frameParams.npcFeatherParams = { npcFeatherLength, npcFeatherWidth,
            (0.8f + 1.6f * settings.npcFeathers) * settings.npcFeatherDensity / (npcFeatherLength * npcFeatherWidth * 0.55f), 0.35f };
        frameParams.npcFeatherStyle = { settings.npcFeatherNoisiness, settings.npcFeatherTransparency, 0.0f, 0.0f };
        // Patches of grass about 220 units across (Banjo is about 150 tall), from a few to all the green ground.
        frameParams.grassPatches = { settings.grassPatches, 220.0f, settings.grassThickness, settings.grassRandomLength };
        frameParams.grassStyle = { settings.grassChunky ? 1.0f : 0.0f, settings.grassPixelated ? 1.0f : 0.0f, settings.grassChunkSize, settings.grassPixelSize };
        frameParams.grassLook = { settings.grassBlend, 0.0f, 0.0f, 0.0f };

        // Banjo's trail: a point every tenth of a second he moves, each springing back up over about a second.
        struct TrailPoint { float x, y, z, time; };
        static TrailPoint trail[12] = {};
        static uint32_t trailNext = 0;
        static float trailLast = -1.0f;
        const bool havePlayer = settings.player[1] > -1e8f;
        if (havePlayer && (now - trailLast >= 0.1f)) {
            const TrailPoint &last = trail[(trailNext + 11) % 12];
            const float dx = settings.player[0] - last.x, dy = settings.player[1] - last.y, dz = settings.player[2] - last.z;
            const float moved = std::sqrt(dx * dx + dy * dy + dz * dz);
            if (moved > 400.0f) {
                // A warp or a new map: the old trail is somewhere else.
                for (TrailPoint &point : trail) {
                    point.time = 0.0f;
                }
            }
            if ((last.time == 0.0f) || (moved > 3.0f)) {
                trail[trailNext] = { settings.player[0], settings.player[1], settings.player[2], std::max(now, 1e-3f) };
                trailNext = (trailNext + 1) % 12;
            }
            trailLast = now;
        }
        float low[2] = { 1e30f, 1e30f }, high[2] = { -1e30f, -1e30f };
        if (havePlayer) {
            low[0] = high[0] = settings.player[0];
            low[1] = high[1] = settings.player[2];
        }
        for (uint32_t i = 0; i < 12; i++) {
            const TrailPoint &point = trail[i];
            const float age = now - point.time;
            float pressed = 0.0f;
            if (havePlayer && (point.time > 0.0f) && (age < 2.0f)) {
                // Held down briefly, then a damped spring back up that just overshoots.
                const float t = std::max(age - 0.15f, 0.0f);
                pressed = std::exp(-2.6f * t) * std::cos(3.4f * t);
                if (std::abs(pressed) < 1e-3f) {
                    pressed = 0.0f;
                }
            }
            frameParams.grassTrail[i] = { point.x, point.z, point.y, pressed };
            if (pressed != 0.0f) {
                low[0] = std::min(low[0], point.x); low[1] = std::min(low[1], point.z);
                high[0] = std::max(high[0], point.x); high[1] = std::max(high[1], point.z);
            }
        }
        const float trailRadius = frameParams.grassPlayer.w;
        frameParams.grassTrailBounds = { low[0] - trailRadius, low[1] - trailRadius, high[0] + trailRadius, high[1] + trailRadius };
        return true;
    }

    // Banjo-Tooie: deep snow (Snow.hlsli). The snow is pushed down wherever the triangles of a model drawn this frame
    // reach into it (SceneSnowTouch: Banjo's feet and legs, the NPCs and enemies, anything thrown or falling), the way
    // the Batman: Arkham Origins snow is, so nothing is scripted: a jump leaves nothing, a light touch a shallow dent.
    // It is kept in a grid of cells over the world's x and z that wraps round (a cell's place is its world cell modulo
    // the grid's size, the rest kept as a tag), so nothing has to move as Banjo goes. Each cell holds the lowest a model
    // reached down to there, or how far the snow was pushed up into a bank beside where one did, when, and its tag.
    // Snow.hlsli works out from that how deep the snow is pressed over its ground, and springs it back from then on:
    // held a few seconds, then filling back in.
    static constexpr uint32_t SnowGridSize = 1024;
    // A cell's size at full detail (Snow detail 100); less detail, bigger cells (2.5 at 50, the size they once were).
    static constexpr float SnowFinestCell = 1.25f;
    static constexpr float SnowTicksPerSecond = 20.0f;
    // About ankle deep at height 1 (he wades in it at 3); the banks rise a third above it.
    static constexpr float SnowDepth = 12.0f;
    static constexpr float SnowBank = 0.45f;
    static constexpr uint32_t SnowMinShells = 6;
    static constexpr uint32_t SnowMaxShells = 24;
    // How long a print takes to fill back in (less while it snows), once it has stayed as it was for as long as Snow
    // fills back in says; at 0, prints stay until Banjo leaves the map (held longer than the cells' time can count).
    static constexpr float SnowHoldForever = 1e6f;
    static constexpr float SnowRecoverSeconds = 45.0f;
    // How far a print's floor has risen once it has filled back in (SnowRefillRise in Snow.hlsli).
    static constexpr float SnowRefillRise = 260.0f;
    // The blocks of the grid FrameParams.snowBlocksLow and High mark (SnowTess.hlsl): SnowBlocks x SnowBlocks of them.
    static constexpr uint32_t SnowBlocks = 16;
    static constexpr uint32_t SnowBlockCells = SnowGridSize / SnowBlocks;
    // The shells thin out to nothing by this far from the camera; the tessellated snow, cheap far away (SnowTess.hlsl),
    // by much further.
    static constexpr float SnowReach = 2600.0f;
    static constexpr float SnowTessReach = 20000.0f;
    // A camera zoomed in further than the game's usual one (Chilly Willy's fight watches from far back) brings the snow's
    // reach out with it: distances count for less by its zoom (SceneSnowZoom, SnowZoom in Snow.hlsli).
    static constexpr float SnowUsualFov = 2.2f;
    // The most model triangles that press the snow in a frame (SceneSnowTouch).
    static constexpr size_t SnowTouchMost = 60000;

    namespace {
        struct SnowTrail {
            std::vector<uint32_t> cells = std::vector<uint32_t>(SnowGridSize * SnowGridSize * 2, 0);
            bool started = false;
            float last[3] = {};
            // The cells' size (world units), by the Snow detail setting.
            float cell = SnowFinestCell;
            // How long a print is held as it was (Snow fills back in, or SnowHoldForever), and the visit to a map it was
            // made on (SceneEffectsSettings::snowMapVisit).
            float hold = SnowHoldForever;
            uint32_t mapVisit = 0;
            // Banjo's height the last time he stood on the ground.
            float groundY = 0.0f;
            uint32_t sweepRow = 0;
            // The frame each row was last pressed on (the sweep below doesn't count: renderers copy its rows in full now
            // and then, as the times it clears only matter once they wrap round, after 54 minutes).
            std::vector<uint64_t> rowPressed = std::vector<uint64_t>(SnowGridSize, 0);
            // When something was last pressed into each block of the grid (seconds, as `seconds`).
            std::vector<double> blockPressed = std::vector<double>(SnowBlocks * SnowBlocks, -1e9);
            // This frame's touches round Banjo (a window of the grid's size centred on him): the lowest a model
            // reached down to in each cell, and which cells that is so they can be cleared again.
            std::vector<float> touchLowest = std::vector<float>(SnowGridSize * SnowGridSize, FLT_MAX);
            std::vector<uint32_t> touched;
            std::vector<float> bankMost = std::vector<float>(SnowGridSize * SnowGridSize, 0.0f);
            std::vector<float> bankY = std::vector<float>(SnowGridSize * SnowGridSize, FLT_MAX);
            std::vector<uint32_t> banked;
            std::vector<uint32_t> edges;
            // How many model triangles the last frame had (TOOIE_SNOW_LOG).
            uint32_t lastTouches = 0;
            uint32_t lastDraws = 0;
            uint32_t lastStillDraws = 0;
            float lastTouchMs = 0.0f;
            uint64_t frame = 0;
            std::chrono::steady_clock::time_point lastTime{};
            double seconds = 0.0;
        };

        SnowTrail snowTrail;
        // The model triangles drawn since the trail last took them (SceneSnowTouch): nine floats each, x y z three times.
        std::mutex snowTouchMutex;
        std::vector<float> snowTouches;
        // By draw (SceneSnowTouchDraw), each with where it is (its triangle count and the middle of its points): this
        // frame's so far, and the last frame's, held back a frame. A draw found in about the same place in the frames
        // either side of it is standing still (the level's props drawn as models: rocks, plants turned to face the
        // camera, a nest in the sand), and its triangles press nothing, or every one of them keeps the trail's blocks
        // under it cut finely forever (Terrydactyland, L: unusable).
        struct SnowTouchPlace {
            uint32_t count;
            float x, y, z;
        };
        struct SnowTouchDraws {
            std::vector<float> triangles;
            std::vector<std::pair<SnowTouchPlace, std::pair<size_t, size_t>>> draws;
            void clear() { triangles.clear(); draws.clear(); }
        };
        SnowTouchDraws snowTouchNow, snowTouchHeld;
        std::vector<SnowTouchPlace> snowTouchBefore;
        // (Within this of where it was: a prop's matrix is worked out again each frame, a sprite turns to the camera.)
        constexpr float SnowStillReach = 1.0f;
        bool SnowTouchFound(const std::vector<std::pair<SnowTouchPlace, std::pair<size_t, size_t>>> &draws, const SnowTouchPlace &p) {
            for (const auto &[q, range] : draws) {
                if ((q.count == p.count) && (std::abs(q.x - p.x) < SnowStillReach) && (std::abs(q.y - p.y) < SnowStillReach) && (std::abs(q.z - p.z) < SnowStillReach)) {
                    return true;
                }
            }
            return false;
        }
        bool SnowTouchFound(const std::vector<SnowTouchPlace> &places, const SnowTouchPlace &p) {
            for (const SnowTouchPlace &q : places) {
                if ((q.count == p.count) && (std::abs(q.x - p.x) < SnowStillReach) && (std::abs(q.y - p.y) < SnowStillReach) && (std::abs(q.z - p.z) < SnowStillReach)) {
                    return true;
                }
            }
            return false;
        }
    }

    static float SnowSpringBack(float age, float hold, float recover) {
        if (age <= hold) {
            return 1.0f;
        }
        const float t = std::min((age - hold) / std::max(recover, 1.0f), 1.0f);
        return 1.0f - t * t * (3.0f - 2.0f * t);
    }

    // Marks one cell as reached down to y (world units) by a model now, or (with bank over 0) as snow pushed up by bank
    // (0 to 1) beside where a model reached down to y. The cell's first uint holds the bank (bits 0 to 6), whether the
    // cell only holds a bank (bit 7) and y in sixteenths (8 to 31, signed); the second when (0 to 15, in twentieths of
    // a second) and which world cell it is (the tag: x in 16 to 23, z in 24 to 31).
    static void SnowTouchCell(SnowTrail &trail, int32_t worldX, int32_t worldZ, float y, float bank, uint32_t now, float recover) {
        const int32_t n = int32_t(SnowGridSize);
        const int32_t slotX = ((worldX % n) + n) % n;
        const int32_t slotZ = ((worldZ % n) + n) % n;
        const uint32_t tagX = uint32_t((worldX - slotX) / n) & 0xFFu;
        const uint32_t tagZ = uint32_t((worldZ - slotZ) / n) & 0xFFu;
        uint32_t &a = trail.cells[(uint32_t(slotZ) * SnowGridSize + uint32_t(slotX)) * 2];
        uint32_t &b = trail.cells[(uint32_t(slotZ) * SnowGridSize + uint32_t(slotX)) * 2 + 1];
        const bool bankOnly = (bank > 0.0f);
        bool again = false;
        if ((b != 0) && (((b >> 16) & 0xFFu) == tagX) && ((b >> 24) == tagZ)) {
            const float age = float((now - (b & 0xFFFFu)) & 0xFFFFu) / SnowTicksPerSecond;
            const float spring = SnowSpringBack(age, trail.hold, recover);
            const float oldY = float(int32_t(a) >> 8) / 16.0f;
            const bool oldBankOnly = (a & 0x80u) != 0;
            // Far over a print (in the air, or a floor above it): the print stays. Far below one, as on a floor below,
            // it is replaced.
            if ((y > oldY + 150.0f) && (oldBankOnly ? (float(a & 0x7Fu) / 127.0f * spring > 0.01f) : (spring > 0.05f))) {
                return;
            }
            if (std::abs(oldY - y) < 150.0f) {
                if (bankOnly) {
                    // No bank in a print, nor one lower than the bank already there.
                    if ((!oldBankOnly && (spring > 0.05f)) || (oldBankOnly && (float(a & 0x7Fu) / 127.0f * spring >= bank))) {
                        return;
                    }
                }
                else if (!oldBankOnly) {
                    // A print that already goes deeper, as far as it has filled back in (as SnowCell): it stays.
                    const float floorY = oldY + (1.0f - spring) * SnowRefillRise;
                    if (floorY < y - 0.05f) {
                        return;
                    }
                    // The same print again: kept held, but only marked anew now and then so its rows aren't sent again
                    // every frame.
                    if ((std::abs(oldY - y) < 0.1f) && (age < 1.0f)) {
                        return;
                    }
                    again = std::abs(oldY - y) < 0.1f;
                }
            }
        }
        const int32_t fixedY = std::clamp(int32_t(std::lround(y * 16.0f)), -(1 << 23), (1 << 23) - 1);
        a = (bankOnly ? (uint32_t(std::lround(std::min(bank, 1.0f) * 127.0f)) | 0x80u) : 0u) | (uint32_t(fixedY) << 8);
        // A time of 0 with tag 0 would read as an empty cell.
        b = (now & 0xFFFFu) | (tagX << 16) | (tagZ << 24);
        if (b == 0) {
            b = 1;
        }
        trail.rowPressed[slotZ] = trail.frame;
        // (The same print held again doesn't keep its block cut finely: something standing in it the whole time would
        // keep it so forever, and covers it anyway.)
        if (!again) {
            trail.blockPressed[(uint32_t(slotZ) / SnowBlockCells) * SnowBlocks + uint32_t(slotX) / SnowBlockCells] = trail.seconds;
        }
    }

    void SceneSnowTouchDraw(const float *triangles, size_t count) {
        if (count == 0) {
            return;
        }
        SnowTouchPlace place = { uint32_t(count), 0.0f, 0.0f, 0.0f };
        for (size_t i = 0; i < count * 3; i++) {
            place.x += triangles[i * 3 + 0];
            place.y += triangles[i * 3 + 1];
            place.z += triangles[i * 3 + 2];
        }
        place.x /= float(count * 3);
        place.y /= float(count * 3);
        place.z /= float(count * 3);
        const std::scoped_lock lock(snowTouchMutex);
        if (snowTouchNow.triangles.size() + count * 9 > SnowTouchMost * 9) {
            return;
        }
        snowTouchNow.draws.push_back({ place, { snowTouchNow.triangles.size(), count * 9 } });
        snowTouchNow.triangles.insert(snowTouchNow.triangles.end(), triangles, triangles + count * 9);
    }

    void SceneSnowTouch(const float *triangle) {
        const std::scoped_lock lock(snowTouchMutex);
        if (snowTouches.size() < SnowTouchMost * 9) {
            snowTouches.insert(snowTouches.end(), triangle, triangle + 9);
        }
    }

    // Presses the snow wherever this frame's model triangles reach down into it, round Banjo at x and z (y: the ground he
    // last stood on, so nothing he does in the air reaches down past it), and banks the snow they push aside up round
    // them. full is the snow's full height.
    static void SnowTakeTouches(SnowTrail &trail, float x, float y, float z, float full, uint32_t now, float recover) {
        const auto started = std::chrono::steady_clock::now();
        std::vector<float> touches;
        {
            const std::scoped_lock lock(snowTouchMutex);
            touches.swap(snowTouches);
            // Last frame's draws, less those standing still (in the same place this frame or the frame before).
            uint32_t still = 0;
            for (const auto &[place, range] : snowTouchHeld.draws) {
                if (!SnowTouchFound(snowTouchNow.draws, place) && !SnowTouchFound(snowTouchBefore, place)) {
                    touches.insert(touches.end(), snowTouchHeld.triangles.begin() + range.first, snowTouchHeld.triangles.begin() + range.first + range.second);
                    // TOOIE_SNOW_LOG=2: the moving draws now and then (how many triangles, where, and the nearest draw
                    // of as many triangles the frame after).
                    static const bool movingLog = (std::getenv("TOOIE_SNOW_LOG") != nullptr) && (std::getenv("TOOIE_SNOW_LOG")[0] == '2');
                    static uint32_t movingLogged = 0;
                    if (movingLog && ((movingLogged++ % 997) < 12)) {
                        float nearest = 1e30f;
                        for (const auto &[q, r] : snowTouchNow.draws) {
                            if (q.count == place.count) {
                                nearest = std::min(nearest, std::max({ std::abs(q.x - place.x), std::abs(q.y - place.y), std::abs(q.z - place.z) }));
                            }
                        }
                        fprintf(stderr, "[snow] moving draw: %u triangles at %.1f %.1f %.1f, nearest the frame after %.2f\n", place.count, place.x, place.y, place.z, nearest);
                    }
                }
                else {
                    still++;
                }
            }
            trail.lastStillDraws = still;
            trail.lastDraws = uint32_t(snowTouchHeld.draws.size());
            snowTouchBefore.clear();
            for (const auto &[place, range] : snowTouchHeld.draws) {
                snowTouchBefore.push_back(place);
            }
            std::swap(snowTouchHeld, snowTouchNow);
            snowTouchNow.clear();
        }
        trail.lastTouches = uint32_t(touches.size() / 9);
        // The window: the grid's size, centred on Banjo, in world cells.
        const int32_t n = int32_t(SnowGridSize);
        const int32_t originX = int32_t(std::floor(x / trail.cell)) - n / 2;
        const int32_t originZ = int32_t(std::floor(z / trail.cell)) - n / 2;
        // Higher up than this, nothing reaches the snow Banjo stands in (a game's own snow layer can lie 50 above
        // his feet, and the snow on top of it). Sand has no layer of its own: only a little over its height (for the
        // slopes round him), or every creature walking or flying about near him marks the trail (Terrydactyland).
        const float ceiling = effectsSettings.snowSand ? (y + full + 20.0f) : (y + 50.0f + full + 10.0f);
        const float spacing = trail.cell;
        auto touch = [&](float px, float py, float pz) {
            const int32_t cx = int32_t(std::floor(px / trail.cell)) - originX;
            const int32_t cz = int32_t(std::floor(pz / trail.cell)) - originZ;
            if ((cx < 0) || (cz < 0) || (cx >= n) || (cz >= n)) {
                return;
            }
            const uint32_t k = uint32_t(cz) * SnowGridSize + uint32_t(cx);
            float &lowest = trail.touchLowest[k];
            if (lowest == FLT_MAX) {
                trail.touched.push_back(k);
            }
            lowest = std::min(lowest, py);
        };
        const float reach = float(n / 2) * trail.cell;
        for (size_t i = 0; i + 9 <= touches.size(); i += 9) {
            const float *p = &touches[i];
            if ((std::min(p[1], std::min(p[4], p[7])) > ceiling) || (std::max(p[1], std::max(p[4], p[7])) < y - 400.0f) ||
                (std::abs(p[0] - x) > reach) || (std::abs(p[2] - z) > reach))
            {
                continue;
            }
            // Points over the triangle at most spacing apart (fewer on a big one), each marking the cell under it.
            const float e1[3] = { p[3] - p[0], p[4] - p[1], p[5] - p[2] };
            const float e2[3] = { p[6] - p[0], p[7] - p[1], p[8] - p[2] };
            const float longest = std::sqrt(std::max({ e1[0] * e1[0] + e1[2] * e1[2], e2[0] * e2[0] + e2[2] * e2[2],
                (p[6] - p[3]) * (p[6] - p[3]) + (p[8] - p[5]) * (p[8] - p[5]) }));
            const uint32_t steps = std::clamp(uint32_t(std::ceil(longest / spacing)), 1u, 96u);
            for (uint32_t u = 0; u <= steps; u++) {
                for (uint32_t v = 0; v <= steps - u; v++) {
                    const float fu = float(u) / float(steps), fv = float(v) / float(steps);
                    touch(p[0] + e1[0] * fu + e2[0] * fv, p[1] + e1[1] * fu + e2[1] * fv, p[2] + e1[2] * fu + e2[2] * fv);
                }
            }
        }

        // Snow doesn't keep the sharp outline of what pressed it: round each cell reached into, the print's walls
        // slope up over a few cells, rounding it off.
        const int32_t wallReach = std::max(int32_t(std::lround(6.25f / trail.cell)), 1);
        const float wallRise = 30.0f;
        // (Only from the print's edge: inside it, the walls would only land on more of the print.)
        auto edge = [&](uint32_t k) {
            const int32_t cx = int32_t(k % SnowGridSize), cz = int32_t(k / SnowGridSize);
            if ((cx == 0) || (cz == 0) || (cx == n - 1) || (cz == n - 1)) {
                return true;
            }
            return (trail.touchLowest[k - 1] > ceiling) || (trail.touchLowest[k + 1] > ceiling) ||
                (trail.touchLowest[k - SnowGridSize] > ceiling) || (trail.touchLowest[k + SnowGridSize] > ceiling);
        };
        std::vector<uint32_t> &edges = trail.edges;
        edges.clear();
        for (uint32_t k : trail.touched) {
            if ((trail.touchLowest[k] <= ceiling) && edge(k)) {
                edges.push_back(k);
            }
        }
        for (uint32_t k : edges) {
            const float lowest = trail.touchLowest[k];
            const int32_t cx = int32_t(k % SnowGridSize), cz = int32_t(k / SnowGridSize);
            for (int32_t dz = -wallReach; dz <= wallReach; dz++) {
                for (int32_t dx = -wallReach; dx <= wallReach; dx++) {
                    const int32_t wx = cx + dx, wz = cz + dz;
                    const float d2 = float(dx * dx + dz * dz) / float(wallReach * wallReach);
                    if (((dx == 0) && (dz == 0)) || (d2 > 1.0f) || (wx < 0) || (wz < 0) || (wx >= n) || (wz >= n)) {
                        continue;
                    }
                    const uint32_t j = uint32_t(wz) * SnowGridSize + uint32_t(wx);
                    const float wallY = lowest + d2 * wallRise;
                    if (trail.touchLowest[j] == FLT_MAX) {
                        trail.touched.push_back(j);
                    }
                    trail.touchLowest[j] = std::min(trail.touchLowest[j], wallY);
                }
            }
        }

        // The prints, and round each one reaching well down into the snow a bank, highest a little way out from it.
        const int32_t bankReach = std::max(int32_t(std::ceil(6.25f / trail.cell)), 1);
        const float bankPeak = 2.75f;
        const float bankWidth = 3.0f;
        for (uint32_t k : trail.touched) {
            const int32_t cx = int32_t(k % SnowGridSize), cz = int32_t(k / SnowGridSize);
            const float lowest = trail.touchLowest[k];
            if (lowest > ceiling) {
                continue;
            }
            SnowTouchCell(trail, originX + cx, originZ + cz, lowest, 0.0f, now, recover);
            const float deep = std::clamp((y + full - lowest) / std::max(full, 1e-3f), 0.0f, 1.0f);
            if ((deep <= 0.05f) || !edge(k)) {
                continue;
            }
            for (int32_t dz = -bankReach; dz <= bankReach; dz++) {
                for (int32_t dx = -bankReach; dx <= bankReach; dx++) {
                    const int32_t bx = cx + dx, bz = cz + dz;
                    if ((bx < 0) || (bz < 0) || (bx >= n) || (bz >= n)) {
                        continue;
                    }
                    const uint32_t j = uint32_t(bz) * SnowGridSize + uint32_t(bx);
                    const float distance = std::sqrt(float(dx * dx + dz * dz)) * trail.cell;
                    const float bank = deep * std::clamp(1.0f - std::abs(distance - bankPeak) / bankWidth, 0.0f, 1.0f);
                    if ((bank <= 0.01f) || (trail.touchLowest[j] <= ceiling)) {
                        continue;
                    }
                    if (trail.bankMost[j] == 0.0f) {
                        trail.banked.push_back(j);
                    }
                    trail.bankMost[j] = std::max(trail.bankMost[j], bank);
                    // (Its height: that of what pushed it up, for SnowCell's test of which floor it lies on.)
                    trail.bankY[j] = std::min(trail.bankY[j], lowest);
                }
            }
        }
        for (uint32_t j : trail.banked) {
            const int32_t bx = int32_t(j % SnowGridSize), bz = int32_t(j / SnowGridSize);
            SnowTouchCell(trail, originX + bx, originZ + bz, trail.bankY[j], trail.bankMost[j], now, recover);
            trail.bankMost[j] = 0.0f;
            trail.bankY[j] = FLT_MAX;
        }
        trail.banked.clear();
        for (uint32_t k : trail.touched) {
            trail.touchLowest[k] = FLT_MAX;
        }
        trail.touched.clear();
        trail.lastTouchMs = std::chrono::duration<float, std::milli>(std::chrono::steady_clock::now() - started).count();
    }

    uint32_t SceneSnowShells() {
        const std::scoped_lock lock(effectsMutex);
        if (!effectsSettings.snow) {
            return 0;
        }
        const float full = SnowDepth * effectsSettings.snowHeight * (1.0f + SnowBank);
        // A shell every 1.25 units: closer than that and the steps no longer show in a trench's walls.
        return std::clamp(uint32_t(std::lround(full / 1.25f)), SnowMinShells, SnowMaxShells);
    }

    float SceneSnowZoom(const interop::FrameParams &frameParams) {
        // snowCamera.w is the projection's 1 / tan(half the field of view): about 2 for the game's usual camera.
        return std::clamp(SnowUsualFov / std::max(frameParams.snowCamera.w, 1e-3f), 0.2f, 1.0f);
    }

    uint32_t SceneSnowShellsAt(float distanceToCamera, const interop::FrameParams &frameParams) {
        const float reach = frameParams.snowParams.z;
        const uint32_t most = uint32_t(frameParams.snowGrid.w > 0.0f ? frameParams.snowParams.w : 0.0f);
        if ((most == 0) || (distanceToCamera >= reach)) {
            return 0;
        }
        // All of them near the camera, down to two fifths of them far away, where the steps between them don't show.
        const float t = std::clamp((distanceToCamera - reach * 0.25f) / (reach * 0.75f), 0.0f, 1.0f);
        return std::max(uint32_t(std::lround(float(most) * (1.0f - 0.6f * t))), std::min(most, 4u));
    }

    uint32_t SceneSnowTrailRowSize() {
        return SnowGridSize * 2;
    }

    void SetSceneWaterDetail(float detail) {
        const std::scoped_lock lock(effectsMutex);
        effectsSettings.waterDetail = std::clamp(detail, 0.0f, 1.0f);
    }

    // Tessellated water's waves and player this frame (ComputeSceneWater), for the effects pass to light the same waves.
    struct WaterTessShared {
        float clock = 0.0f;
        float push = 0.0f;
        float velocity[2] = {};
    };
    static std::mutex waterTessMutex;
    static WaterTessShared waterTessShared;

    void QueueGroundShaders();

    void SetSceneGroundDisplacement(float amount, float reach) {
        {
            const std::scoped_lock lock(effectsMutex);
            effectsSettings.groundDisplacement = std::clamp(amount, 0.0f, 1.0f);
            effectsSettings.groundReach = std::clamp(reach, 500.0f, 50000.0f);
        }

        // The floors' displaced shaders compile with the shader list from now on, not on a first visit.
        if (amount > 0.0f) {
            QueueGroundShaders();
        }
    }

    float SceneGroundDisplacement() {
        const std::scoped_lock lock(effectsMutex);
        return effectsSettings.groundDisplacement;
    }

    // A world camera's map from world space to clip space as RasterVS places the vertices (row r of toClip gives clip
    // component r), and the camera's world position. False for a projection that isn't a perspective one.
    static bool SceneCameraToClip(const interop::float4x4 &projection, const interop::float4x4 &view, const interop::float4x4 &viewProj,
        const interop::float3 &viewportScale, const interop::float3 &viewportTranslate, const interop::float2 &resolution,
        double (&toClip)[4][4], double (&camera)[3])
    {
        if ((resolution.x <= 0.0f) || (resolution.y <= 0.0f)) {
            return false;
        }

        // As ComputeSceneGrass: row-vector matrices told apart by the projection, and RasterVS's positions.
        const float (&m)[4][4] = projection.m;
        const bool rowVector = std::abs(m[2][3] + 1.0f) <= std::abs(m[3][2] + 1.0f);
        if ((std::abs(m[2][3] + 1.0f) > 0.01f) && (std::abs(m[3][2] + 1.0f) > 0.01f)) {
            return false;
        }
        const float halfWidth = resolution.x / 2.0f;
        const float halfHeight = resolution.y / 2.0f;
        for (int j = 0; j < 4; j++) {
            float c[4];
            for (int k = 0; k < 4; k++) {
                c[k] = rowVector ? viewProj.m[j][k] : viewProj.m[k][j];
            }
            toClip[0][j] = c[0] * (viewportScale.x / halfWidth) + c[3] * ((viewportTranslate.x - halfWidth) / halfWidth);
            toClip[1][j] = c[1] * (viewportScale.y / halfHeight) - c[3] * ((viewportTranslate.y - halfHeight) / halfHeight);
            toClip[2][j] = c[2] * viewportScale.z + c[3] * viewportTranslate.z;
            toClip[3][j] = c[3];
        }

        // The camera: view space's origin in the world.
        double viewD[4][4], viewInverse[4][4];
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                viewD[r][c] = rowVector ? view.m[r][c] : view.m[c][r];
            }
        }
        if (!InvertMatrix4(viewD, viewInverse)) {
            return false;
        }
        // (Row vectors: a point is p * M, so the origin's place is the inverse's last row.)
        camera[0] = viewInverse[3][0];
        camera[1] = viewInverse[3][1];
        camera[2] = viewInverse[3][2];
        return true;
    }

    bool SceneGroundCamera(const interop::float4x4 &projection, const interop::float4x4 &view, const interop::float4x4 &viewProj,
        const interop::float3 &viewportScale, const interop::float3 &viewportTranslate, const interop::float2 &resolution, interop::float4 *terms)
    {
        double toClip[4][4], camera[3];
        if (!SceneCameraToClip(projection, view, viewProj, viewportScale, viewportTranslate, resolution, toClip, camera)) {
            return false;
        }
        for (int r = 0; r < 4; r++) {
            terms[r] = { float(toClip[r][0]), float(toClip[r][1]), float(toClip[r][2]), float(toClip[r][3]) };
        }
        terms[4] = { float(camera[0]), float(camera[1]), float(camera[2]), 0.0f };
        return true;
    }

    // (Displaced ground takes each framebuffer's own camera terms, FrameParams.groundCameras.)
    uint32_t ComputeSceneWater(const interop::float4x4 &projection, const interop::float4x4 &view, const interop::float4x4 &viewProj,
        const interop::float3 &viewportScale, const interop::float3 &viewportTranslate, const interop::float2 &resolution, uint64_t workloadId,
        interop::FrameParams &frameParams)
    {
        SceneEffectsSettings settings = GetSceneEffects();
        frameParams.waterCamera.w = 0.0f;
        frameParams.groundParams = { 0.0f, 0.0f, 0.0f, 0.0f };
        const bool water = settings.modernWater && (settings.waterDetail > 0.0f);
        const bool ground = settings.groundDisplacement > 0.0f;
        if (!water && !ground) {
            return 0;
        }
        UsePlayerFrame(settings, workloadId);

        double toClip[4][4], camera[3];
        if (!SceneCameraToClip(projection, view, viewProj, viewportScale, viewportTranslate, resolution, toClip, camera)) {
            return 0;
        }
        double inverse[4][4];
        if (!InvertMatrix4(toClip, inverse)) {
            return 0;
        }
        // One world unit straight up: the map's y column.
        frameParams.waterClipUp = { float(toClip[0][1]), float(toClip[1][1]), float(toClip[2][1]), float(toClip[3][1]) };
        for (int r = 0; r < 4; r++) {
            frameParams.waterClipToWorld[r] = { float(inverse[r][0]), float(inverse[r][1]), float(inverse[r][2]), float(inverse[r][3]) };
            frameParams.waterWorldToClip[r] = { float(toClip[r][0]), float(toClip[r][1]), float(toClip[r][2]), float(toClip[r][3]) };
        }

        const float detail = settings.waterDetail;
        frameParams.waterCamera = { float(camera[0]), float(camera[1]), float(camera[2]), water ? detail : 0.0f };

        // Displaced ground: the deepest part of a texture is pushed down by up to 16 units at the full setting, cut into at
        // most 16 pieces an edge no shorter than 12 units, fading out over 1400 to 2800 units from the camera.
        if (ground) {
            frameParams.groundParams = { 16.0f * settings.groundDisplacement, 16.0f, 12.0f, settings.groundReach };
        }
        if (!water) {
            return 2;
        }

        // Water detail: up to 4 to 16 pieces an edge, pieces no shorter than 24 down to 8 units, cut finely within 500 to
        // 1500 units of the player, coarsening over 600 to 2000 units from the camera.
        frameParams.waterTess = { 4.0f + 12.0f * detail, 24.0f - 16.0f * detail, 500.0f + 1000.0f * detail, 600.0f + 1400.0f * detail };

        // The player's push: from how fast they move over the water this frame, dying away over about a second and a
        // half once they stop, with a little always left (bobbing in place). Their velocity from the last frame's place.
        static auto lastTime = std::chrono::steady_clock::now();
        static float last[3] = { 0.0f, -1e9f, 0.0f };
        static float velocity[2] = { 0.0f, 0.0f };
        static float push = 0.0f;
        static double clock = 0.0;
        const auto now = std::chrono::steady_clock::now();
        const float dt = std::min(std::chrono::duration<float>(now - lastTime).count(), 0.25f);
        lastTime = now;
        clock = std::fmod(clock + double(dt) * settings.waveSpeed, 3600.0);
        const bool havePlayer = settings.player[1] > -1e8f;
        if (havePlayer && (last[1] > -1e8f) && (dt > 1e-4f)) {
            const float vx = (settings.player[0] - last[0]) / dt;
            const float vz = (settings.player[2] - last[2]) / dt;
            // (A warp or teleport is no movement.)
            if ((vx * vx + vz * vz) < 3000.0f * 3000.0f) {
                const float smooth = 1.0f - std::exp(-dt / 0.15f);
                velocity[0] += (vx - velocity[0]) * smooth;
                velocity[1] += (vz - velocity[1]) * smooth;
            }
        }
        for (int i = 0; i < 3; i++) {
            last[i] = settings.player[i];
        }
        const float speed = std::sqrt(velocity[0] * velocity[0] + velocity[1] * velocity[1]);
        push = std::max(std::clamp(speed / 250.0f, 0.0f, 1.0f), push * std::exp(-dt / 1.5f));
        frameParams.waterPlayer = { settings.player[0], settings.player[2], havePlayer ? settings.player[1] : -1e9f, havePlayer ? std::max(push, 0.35f) : 0.0f };
        frameParams.waterMotion = { velocity[0], velocity[1], float(clock), 6.0f };
        // The swell follows Water waves (half when that is 0), as the shading's waves do.
        const float waves = (settings.waterWaves > 0.0f) ? settings.waterWaves : 0.5f;
        // (5 and 6: as SceneEffectsPS's TessellatedSlope.)
        frameParams.waterSwell = { 5.0f * waves, 1.0f, settings.stylisedWater ? 1.0f : 0.0f, 0.0f };
        {
            const std::scoped_lock lock(waterTessMutex);
            waterTessShared.clock = float(clock);
            waterTessShared.push = frameParams.waterPlayer.w;
            waterTessShared.velocity[0] = velocity[0];
            waterTessShared.velocity[1] = velocity[1];
        }
        return 1 | (ground ? 2 : 0);
    }

    bool ComputeSceneSnow(const interop::float4x4 &projection, const interop::float4x4 &viewProj, const interop::float3 &viewportScale,
        const interop::float3 &viewportTranslate, const interop::float2 &resolution, uint64_t workloadId, interop::FrameParams &frameParams,
        SceneSnowTrailCopy &trailCopy)
    {
        SceneEffectsSettings settings = GetSceneEffects();
        frameParams.snowGrid.w = 0.0f;
        if (!settings.snow || (resolution.x <= 0.0f) || (resolution.y <= 0.0f)) {
            return false;
        }
        UsePlayerFrame(settings, workloadId);

        const float (&m)[4][4] = projection.m;
        const bool rowVector = std::abs(m[2][3] + 1.0f) <= std::abs(m[3][2] + 1.0f);
        if ((std::abs(m[2][3] + 1.0f) > 0.01f) && (std::abs(m[3][2] + 1.0f) > 0.01f)) {
            return false;
        }

        // The snow's full height straight up, as RasterVS has its positions (as ComputeSceneGrass's grassClipUp).
        const float depth = SnowDepth * settings.snowHeight;
        const float full = depth * (1.0f + SnowBank);
        float clip[4];
        for (int c = 0; c < 4; c++) {
            clip[c] = full * (rowVector ? viewProj.m[1][c] : viewProj.m[c][1]);
        }
        const float halfWidth = resolution.x / 2.0f;
        const float halfHeight = resolution.y / 2.0f;
        frameParams.snowClipUp = {
            clip[0] * (viewportScale.x / halfWidth) + clip[3] * ((viewportTranslate.x - halfWidth) / halfWidth),
            clip[1] * (viewportScale.y / halfHeight) - clip[3] * ((viewportTranslate.y - halfHeight) / halfHeight),
            clip[2] * viewportScale.z + clip[3] * viewportTranslate.z,
            clip[3]
        };

        // Falling snow fills the trail back in sooner.
        const float snowfall = settings.daySnow ? std::clamp(settings.dayRain, 0.0f, 1.0f) : 0.0f;
        const float recover = SnowRecoverSeconds / (1.0f + 1.5f * snowfall);
        snowTrail.hold = (settings.snowRefillAfter > 0.0f) ? settings.snowRefillAfter : SnowHoldForever;

        SnowTrail &trail = snowTrail;
        trail.frame++;
        const auto nowTime = std::chrono::steady_clock::now();
        const float dt = trail.started ? std::clamp(std::chrono::duration<float>(nowTime - trail.lastTime).count(), 0.0f, 0.25f) : 0.0f;
        trail.lastTime = nowTime;
        trail.seconds += dt;
        const uint32_t now = uint32_t(trail.seconds * SnowTicksPerSecond) & 0xFFFFu;

        const bool havePlayer = settings.player[1] > -1e8f;
        if (havePlayer) {
            const float x = settings.player[0], y = settings.player[1], z = settings.player[2];
            const float cell = SnowFinestCell / std::clamp(settings.snowDetail, 0.25f, 1.0f);
            if (cell != trail.cell) {
                // Another size of cell: the old trail doesn't fit the grid any more.
                trail.cell = cell;
                trail.started = false;
            }
            if (settings.snowMapVisit != trail.mapVisit) {
                trail.mapVisit = settings.snowMapVisit;
                trail.started = false;
            }
            if (!trail.started) {
                // A new map (going in and out of a hut, too): the old trail is gone.
                std::fill(trail.cells.begin(), trail.cells.end(), 0u);
                std::fill(trail.rowPressed.begin(), trail.rowPressed.end(), trail.frame);
                std::fill(trail.blockPressed.begin(), trail.blockPressed.end(), -1e9);
                trail.started = true;
                trail.groundY = y;
            }
            if (settings.playerGrounded) {
                trail.groundY = y;
            }
            trail.last[0] = x;
            trail.last[1] = y;
            trail.last[2] = z;
            SnowTakeTouches(trail, x, trail.groundY, z, full, now, recover);
        }
        else {
            const std::scoped_lock lock(snowTouchMutex);
            snowTouches.clear();
        }

        // Cells long since filled back in are emptied a few rows at a time, so their times can't wrap round to new.
        const uint32_t sweepRows = 4;
        for (uint32_t r = 0; r < sweepRows; r++) {
            const uint32_t row = (trail.sweepRow + r) % SnowGridSize;
            for (uint32_t c = 0; c < SnowGridSize; c++) {
                uint32_t *cell = &trail.cells[(row * SnowGridSize + c) * 2];
                if ((cell[1] != 0) && (float((now - (cell[1] & 0xFFFFu)) & 0xFFFFu) / SnowTicksPerSecond > trail.hold + SnowRecoverSeconds + 10.0f)) {
                    cell[0] = 0;
                    cell[1] = 0;
                }
            }
        }
        trail.sweepRow = (trail.sweepRow + sweepRows) % SnowGridSize;
        // The renderer's copy: the whole grid the first time and every few minutes (for the sweep's rows), otherwise
        // only the rows pressed since it last looked (a few, where Banjo and the others walk).
        const uint32_t rowSize = SnowGridSize * 2;
        const uint64_t refreshFrames = 60 * 60 * 5;
        if ((trailCopy.cells.size() != trail.cells.size()) || (trailCopy.seen == 0) || (trail.frame - trailCopy.fullAt > refreshFrames)) {
            trailCopy.cells = trail.cells;
            trailCopy.fullAt = trail.frame;
            trailCopy.rowFirst = 0;
            trailCopy.rowEnd = SnowGridSize;
        }
        else {
            for (uint32_t r = 0; r < SnowGridSize; r++) {
                if (trail.rowPressed[r] > trailCopy.seen) {
                    std::copy_n(&trail.cells[r * rowSize], rowSize, &trailCopy.cells[r * rowSize]);
                    trailCopy.rowFirst = (trailCopy.rowEnd > trailCopy.rowFirst) ? std::min(trailCopy.rowFirst, r) : r;
                    trailCopy.rowEnd = std::max(trailCopy.rowEnd, r + 1);
                }
            }
        }
        trailCopy.seen = trail.frame;

        // The light on the snow: the day and night cycle's sun when it is up, otherwise one from high to one side.
        float light[3] = { 0.42f, 0.8f, 0.43f };
        if (settings.customSun && (settings.sunDirection[1] > 0.15f)) {
            for (int c = 0; c < 3; c++) {
                light[c] = settings.sunDirection[c];
            }
        }
        const float lightLength = std::sqrt(light[0] * light[0] + light[1] * light[1] + light[2] * light[2]);
        frameParams.snowParams = { depth, full, SnowReach, float(SceneSnowShells()) };
        // Test aid: TOOIE_SNOW_DEBUG=1 tints the shells from blue at the ground to magenta at the top, =2 shows the trail,
        // =3 why the snow is left out where it is (Snow.hlsli).
        static const bool snowDebug = (std::getenv("TOOIE_SNOW_DEBUG") != nullptr);
        frameParams.snowGrid = { trail.cell, 1.0f / trail.cell, float(SnowGridSize), snowDebug ? 1.0f + float(std::max(std::atoi(std::getenv("TOOIE_SNOW_DEBUG")), 1)) : 1.0f };
        // Test aid: TOOIE_SNOW_LOG=1 logs Banjo's place and how much of the trail is pressed, every 2 seconds.
        static const bool snowLog = (std::getenv("TOOIE_SNOW_LOG") != nullptr);
        static double snowLogged = 0.0;
        if (snowLog && (trail.seconds - snowLogged >= 2.0)) {
            snowLogged = trail.seconds;
            uint32_t pressed = 0;
            for (size_t i = 0; i < trail.cells.size(); i += 2) {
                pressed += (trail.cells[i + 1] != 0) ? 1 : 0;
            }
            uint32_t activeBlocks = 0;
            for (uint32_t k = 0; k < SnowBlocks * SnowBlocks; k++) {
                activeBlocks += (trail.seconds - trail.blockPressed[k] < double(trail.hold) + SnowRecoverSeconds + 2.0) ? 1 : 0;
            }
            fprintf(stderr, "[snow] Banjo %.0f %.0f %.0f%s, %u cells pressed, %u of %u blocks cut finely, depth %.1f, recover %.0f s, %u model triangles from %u of %u draws (the rest standing still) (%.1f ms)\n", settings.player[0], settings.player[1], settings.player[2], settings.playerGrounded ? "" : " (in the air)",
                pressed, activeBlocks, SnowBlocks * SnowBlocks, depth, recover, trail.lastTouches, trail.lastDraws - trail.lastStillDraws, trail.lastDraws, trail.lastTouchMs);
        }
        // (Sand banks up less round a print than snow.)
        frameParams.snowSpring = { trail.hold, recover, settings.snowSand ? SnowBank * 0.6f : SnowBank, float(now) };
        frameParams.snowLight = { light[0] / lightLength, light[1] / lightLength, light[2] / lightLength, 3.2f };
        // (w: how light it must be. The arena's bluer snow is very light, its ice's pale glints not quite.)
        frameParams.snowColor = settings.snowStrictColor ? interop::float4{ 0.06f, 0.25f, 0.3f, 0.45f } : interop::float4{ 0.2f, 0.45f, 0.45f, 0.72f };
        frameParams.snowPlayer = { settings.player[0], settings.player[2], settings.player[1], havePlayer ? SnowTessReach : 0.0f };
        // (The trail's cells tell one world cell from another, so it can be looked up as far off as the snow goes; it is
        // only pressed in round Banjo, snowLod.z.)
        // (w: 1 for tessellated sand, Snow.hlsli SnowSand.)
        frameParams.snowLod = { settings.snowLodDistance, SnowTessReach, SnowGridSize * trail.cell * 0.45f, settings.snowSand ? 1.0f : 0.0f };
        // The blocks with a trail still filling back in (for as long as a print can take to).
        uint32_t blocks[8] = {};
        const double lasts = double(trail.hold) + SnowRecoverSeconds + 2.0;
        for (uint32_t k = 0; k < SnowBlocks * SnowBlocks; k++) {
            if (trail.seconds - trail.blockPressed[k] < lasts) {
                blocks[k / 32] |= 1u << (k % 32);
            }
        }
        frameParams.snowBlocksLow = { blocks[0], blocks[1], blocks[2], blocks[3] };
        frameParams.snowBlocksHigh = { blocks[4], blocks[5], blocks[6], blocks[7] };
        return true;
    }

    bool SceneWaterWanted() {
        const std::scoped_lock lock(effectsMutex);
        return (effectsSettings.waterReflections > 0.0f) || (effectsSettings.iceReflections > 0.0f) || (effectsSettings.screenSpaceReflections > 0.0f) || (effectsSettings.waterWaves > 0.0f) || effectsSettings.shoreFoam || effectsSettings.modernWater || (effectsSettings.view == 4) || (effectsSettings.view == SceneEffectsViewSsr) ||
            // The rain rings on water need it too.
            (effectsSettings.timeOfDay && (effectsSettings.dayRain > 0.0f)) ||
            (effectsSettings.view == SceneEffectsSoloFirst + 8) || (effectsSettings.view == SceneEffectsSoloFirst + 9);
    }

    void MarkSceneWaterTessellated(RenderWorker *worker) {
        resourcesFor(worker).waterTessDrawn = true;
    }

    RenderFramebuffer *BeginSceneWaterMask(RenderWorker *worker, RenderTarget *colorTarget, RenderTarget *depthTarget, bool colors) {
        Resources &res = resourcesFor(worker);
        RenderCommandList *commandList = worker->commandList.get();
        ensureWaterTarget(worker, res, colorTarget, depthTarget);
        RenderTexture *texture = colors ? res.waterColorTexture.get() : res.waterTexture.get();
        RenderFramebuffer *framebuffer = colors ? res.waterColorFramebuffer.get() : res.waterFramebuffer.get();
        commandList->barriers(RenderBarrierStage::GRAPHICS, {
            RenderTextureBarrier(texture, RenderTextureLayout::COLOR_WRITE),
            RenderTextureBarrier(depthTarget->texture.get(), RenderTextureLayout::DEPTH_WRITE)
        });
        commandList->setFramebuffer(framebuffer);
        commandList->clearColor(0, RenderColor(0.0f, 0.0f, 0.0f, 0.0f));
        (colors ? res.waterColorDrawn : res.waterDrawn) = true;
        return framebuffer;
    }

    SceneEffectsSettings GetSceneEffects() {
        SceneEffectsSettings settings;
        {
            const std::scoped_lock lock(effectsMutex);
            settings = effectsSettings;
        }
        if ((settings.view < SceneEffectsSoloFirst) || (settings.view == SceneEffectsViewRayScene)) {
            return settings;
        }
        if ((settings.view >= SceneEffectsViewGtao) && (settings.view <= SceneEffectsViewSsr)) {
            // The effect the view shows at half strength when it is off.
            float &strength = (settings.view == SceneEffectsViewGtao) ? settings.ambientOcclusion :
                (settings.view == SceneEffectsViewSsgi) ? settings.screenSpaceGI : settings.screenSpaceReflections;
            if (strength <= 0.0f) {
                strength = 0.5f;
            }
            return settings;
        }

        // A solo view: the picture with only one effect, at its setting or at half strength when it is off.
        SceneEffectsSettings solo = settings;
        solo.view = 0;
        float *const strengths[] = {
            &solo.ambientOcclusion, &solo.bounceLight, &solo.outlines, &solo.rimLight, &solo.fog, &solo.bloom,
            &solo.lightShafts, &solo.eyeAdaptation, &solo.waterReflections, &solo.waterWaves, &solo.underwaterTint,
            &solo.heatHaze, &solo.depthOfField
        };
        static_assert(std::size(strengths) == SceneEffectsSoloCount);
        const uint32_t kept = settings.view - SceneEffectsSoloFirst;
        for (uint32_t i = 0; i < SceneEffectsSoloCount; i++) {
            if (i == kept) {
                if (*strengths[i] <= 0.0f) {
                    *strengths[i] = 0.5f;
                }
            }
            else {
                *strengths[i] = 0.0f;
            }
        }
        if (kept != 10) {
            solo.underwaterHaze = 0.0f;
        }
        else if (solo.underwaterHaze <= 0.0f) {
            solo.underwaterHaze = 0.3f;
        }
        return solo;
    }

    bool SceneEffectsAnyOn() {
        const SceneEffectsSettings settings = GetSceneEffects();
        return ((settings.ambientOcclusion > 0.0f) || (settings.fog > 0.0f) || (settings.outlines > 0.0f) ||
            (settings.bloom > 0.0f) || (settings.depthOfField > 0.0f) ||
            (settings.eyeAdaptation > 0.0f) || (settings.rimLight > 0.0f) || (settings.toonShading > 0.0f) || (settings.toonCharacters > 0.0f) || (settings.underwaterTint > 0.0f) || (settings.heatHaze > 0.0f) || (settings.waterReflections > 0.0f) || (settings.iceReflections > 0.0f) || (settings.waterWaves > 0.0f) || settings.shoreFoam || settings.modernWater || (settings.lightShafts > 0.0f) || (settings.sunShadows > 0.0f) || (settings.bounceLight > 0.0f) || (settings.screenSpaceGI > 0.0f) || (settings.screenSpaceReflections > 0.0f) || settings.timeOfDay || (settings.volMist > 0.0f) || (settings.volFog > 0.0f) || (settings.volCloudType > 0) || (settings.view != 0)) && (settings.depthAddress != 0);
    }

    bool SceneEffectsWanted(const RenderTarget *depthTarget) {
        const SceneEffectsSettings settings = GetSceneEffects();
        return SceneEffectsAnyOn() && (depthTarget != nullptr) && (depthTarget->addressForName == settings.depthAddress);
    }

    std::atomic<uint32_t> sceneEffectsRecorded{ 0 };

    // Writes one buffer into a ray texture set, false if the driver faulted (an access violation inside NVIDIA's
    // vkUpdateDescriptorSets crashed the game from here on 2026-10-21 and 22 with no way to tell which buffer it was).
    static bool RaySetBufferSafe(SceneRayTexturesDescriptorSet *set, uint32_t index, const RenderBuffer *buffer, const RenderBufferStructuredView *view) {
#   ifdef _WIN32
        __try {
            set->setBuffer(index, buffer, 0, view);
            return true;
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {
            return false;
        }
#   else
        set->setBuffer(index, buffer, 0, view);
        return true;
#   endif
    }

    // Banjo-Tooie: Graphics > Ray tracing. Builds the structures the traced reflections trace through, from the world's
    // solid triangles: one geometry for each run of the index buffer (the sun shadow casters' runs), over the world
    // positions the vertex processor worked out, under one instance of the identity transform. Does nothing unless
    // RayTracingActive(); on a failure the pass falls back to the depth march (bvhReady stays false).
    void BuildSceneBVH(RenderWorker *worker, const RenderBuffer *worldPos, uint32_t worldPosVertexCount, const RenderBuffer *indices,
        const SceneRayDraw *draws, size_t drawCount, const SceneRayTextures &textures, const SceneRayGrass &grass, uint64_t levelKey)
    {
        Resources &res = resourcesFor(worker);
        res.bvhReady = false;
        res.rayTexturesValid = false;
        if (!RayTracingActive() || !worker->device->getCapabilities().rayQuery) {
            return;
        }
        constexpr size_t MaxGeometries = 8192;
        // The set the rays read textures through: this frame's buffers when it has them all, else empty stand-ins.
        res.rayTextureCacheSet = textures.textureSet;
        if (res.rayGeometryBuffer == nullptr) {
            res.rayGeometryBuffer = worker->device->createBuffer(RenderBufferDesc::UploadBuffer(16 * (MaxGeometries + SceneMaxRayMaterials + 1)));
            res.rayGeometryBuffer->setName("Scene Effects ray geometries");
        }
        if (res.rayDummyBuffer == nullptr) {
            res.rayDummyBuffer = worker->device->createBuffer(RenderBufferDesc::UploadBuffer(256));
            res.rayDummyBuffer->setName("Scene Effects ray stand-in");
            memset(res.rayDummyBuffer->map(), 0, 256);
            res.rayDummyBuffer->unmap();
        }
        const bool building = (worldPos != nullptr) && (indices != nullptr) && (worldPosVertexCount != 0) && (drawCount != 0);
        // Only a pass that builds binds its texture buffers: a pass with nothing drawn (warping from Photo mode) can hand
        // over buffers not yet made for this frame, and binding one crashed the driver in setBuffer (L, 2026-10-21).
        const bool haveTextureBuffers = building && (textures.indices != nullptr) && (textures.texcoords != nullptr) && (textures.rdpTiles != nullptr) && (textures.gpuTiles != nullptr);
        const RenderBuffer *wanted[4] = {
            haveTextureBuffers ? textures.indices : res.rayDummyBuffer.get(),
            haveTextureBuffers ? textures.texcoords : res.rayDummyBuffer.get(),
            haveTextureBuffers ? textures.rdpTiles : res.rayDummyBuffer.get(),
            haveTextureBuffers ? textures.gpuTiles : res.rayDummyBuffer.get()
        };
        // Sets not used for a while are dropped: the buffers they name may have been replaced since (a new buffer at an old one's
        // address would match).
        constexpr uint64_t RayCacheKeepPasses = 240;
        constexpr size_t RayCacheMax = 8;
        for (size_t i = 0; i < res.rayTexturesCache.size();) {
            if (res.rayTexturesCache[i].usedPass + RayCacheKeepPasses < res.passes) {
                res.retireLater(std::move(res.rayTexturesCache[i].set));
                res.rayTexturesCache.erase(res.rayTexturesCache.begin() + i);
            }
            else {
                i++;
            }
        }
        res.rayTexturesSet = nullptr;
        for (Resources::RayTexturesEntry &entry : res.rayTexturesCache) {
            if (std::equal(wanted, wanted + 4, entry.buffers)) {
                entry.usedPass = res.passes;
                res.rayTexturesSet = entry.set.get();
                break;
            }
        }
        if (res.rayTexturesSet == nullptr) {
            if (res.rayTexturesCache.size() >= RayCacheMax) {
                auto oldest = std::min_element(res.rayTexturesCache.begin(), res.rayTexturesCache.end(),
                    [](const Resources::RayTexturesEntry &a, const Resources::RayTexturesEntry &b) { return a.usedPass < b.usedPass; });
                res.retireLater(std::move(oldest->set));
                res.rayTexturesCache.erase(oldest);
            }
            Resources::RayTexturesEntry entry;
            entry.set = std::make_unique<SceneRayTexturesDescriptorSet>(worker->device);
            SceneRayTexturesDescriptorSet *set = entry.set.get();
            const RenderBufferStructuredView tilesView(haveTextureBuffers ? sizeof(interop::RDPTile) : 16);
            const RenderBufferStructuredView gpuTilesView(haveTextureBuffers ? sizeof(interop::GPUTile) : 16);
            const int faulted =
                RaySetBufferSafe(set, set->gRayGeometries, res.rayGeometryBuffer.get(), nullptr) ? (RaySetBufferSafe(set, set->gRayIndices, wanted[0], nullptr) ?
                (RaySetBufferSafe(set, set->gRayTexcoords, wanted[1], nullptr) ? (RaySetBufferSafe(set, set->gRayRDPTiles, wanted[2], &tilesView) ?
                (RaySetBufferSafe(set, set->gRayGPUTiles, wanted[3], &gpuTilesView) ? 0 : 5) : 4) : 3) : 2) : 1;
            if (faulted != 0) {
                // The driver faulted on writing that buffer (the crashes of 2026-10-21/22): the traced pass falls back this frame.
                fprintf(stderr, "[rt] the driver faulted writing ray texture buffer %d (%p), no traced pass this frame\n", faulted, (const void *)wanted[faulted - 1]);
                res.retireLater(std::move(entry.set));
                res.rayTexturesSet = nullptr;
                return;
            }
            std::copy(wanted, wanted + 4, entry.buffers);
            entry.usedPass = res.passes;
            res.rayTexturesSet = set;
            res.rayTexturesCache.push_back(std::move(entry));
        }
        const bool withGrass = building && (grass.vertices != nullptr) && (grass.vertexCount >= 3);
        // A pass with no casters (some in-between frames have none) traces through the last structure built, rather than
        // dropping to the depth march and its shadow map, which made the shadows come and go.
        // The lights are written every pass, whatever the casters.
        if (res.lightsBuffer == nullptr) {
            res.lightsBuffer = worker->device->createBuffer(RenderBufferDesc::UploadBuffer(16 * (SceneMaxLights + 4)));
            res.lightsBuffer->setName("Scene Effects lights");
        }
        if (res.radianceBuffer == nullptr) {
            res.radianceBuffer = worker->device->createBuffer(RenderBufferDesc::DefaultBuffer(8ull << 20, RenderBufferFlag::STORAGE | RenderBufferFlag::UNORDERED_ACCESS));
            res.radianceBuffer->setName("Scene Effects radiance cache");
        }
        if (res.lightsBuffer != nullptr) {
            const SceneEffectsSettings lightSettings = GetSceneEffects();
            float *mapped = reinterpret_cast<float *>(res.lightsBuffer->map());
            memset(mapped, 0, 16 * (SceneMaxLights + 4));
            mapped[0] = float(lightSettings.lightCount);
            mapped[1] = rayTracingHitColours.load() ? 1.0f : 0.0f;
            mapped[2] = rayTracingSmoothing.load();
            mapped[3] = float(pathTracingBounces.load());
            // Traced light beams: strength, then the room's light direction (world, towards the light; 0 for the sun).
            {
                const std::scoped_lock beamLock(effectsMutex);
                mapped[4] = tracedBeams[0];
                mapped[5] = tracedBeams[1];
                mapped[6] = tracedBeams[2];
                mapped[7] = tracedBeams[3];
            }
            // Whether the rays can read the textures of what they meet this pass (the structure is built from this frame's
            // draws and its buffers are all there).
            // 3 when the scene also has a level cut-out (SunThroughCutout has something to find).
            mapped[8] = (building && haveTextureBuffers && (res.rayTextureCacheSet != nullptr)) ? (rayScenesLevelCutouts.load() ? 3.0f : 1.0f) : 0.0f;
            // Whether the player casts traced shadows (Traced shadows of the player).
            // Player shadows off (1), plus 2 for the half-size traced shadows and beams (the indirect pass draws them), plus 4 when the
            // scene has a draw with a ray tracing material (Ray Tracing Material Pick Mode), plus the Ray traced BRDF roughness in
            // percent times 8 and the subsurface scattering strength in percent times 1024.
            mapped[9] = (rayTracingPlayerShadows.load() ? 0.0f : 1.0f) + (rayTracingHalf.load() ? 2.0f : 0.0f) + (rayScenesPbr.load() ? 4.0f : 0.0f) +
                float(rayTracingBrdfPercent.load() * 8u + rayTracingSubsurfacePercent.load() * 1024u);
            // The 3D grass (when it is in the structure): how far along a ray its blades are passed by, so a ray from a
            // blade or the ground among them (whose surfaces the picture only roughly has) isn't stopped by its own
            // blade and its neighbours: one and a half blade heights.
            mapped[10] = withGrass ? 54.0f * lightSettings.grassHeight : 0.0f;
            // How much the Parallax materials reflect (Graphics > Ray Tracing's sliders), in hundredths packed together: Metal,
            // then Tiles times 256, then Smooth times 65536.
            mapped[11] = !rayScenesShine.load() ? 0.0f : std::round(rayTracingMaterials[0].load() * 100.0f) + std::round(rayTracingMaterials[1].load() * 100.0f) * 256.0f +
                std::round(rayTracingMaterials[2].load() * 100.0f) * 65536.0f;
            // Ray detail by distance: past the first the rays a pixel are halved, past the second quartered (0 for never).
            mapped[12] = rayDetailDistances[0].load();
            mapped[13] = rayDetailDistances[1].load();
            mapped[14] = rayTracingParallax.load() ? 1.0f : 0.0f;
            // Ray tracing resolution High (2): all the rays at every distance.
            mapped[15] = float(rayTracingResolution.load());
            memcpy(mapped + 16, lightSettings.lights, size_t(lightSettings.lightCount) * 4 * sizeof(float));
            // The level's reaches as whole numbers: a fraction marks a Light Source pick and holds its object's size
            // (SceneLightSourceW).
            for (uint32_t i = 0; i < std::min(lightSettings.lightCount, SceneMaxLights); i++) {
                mapped[16 + i * 4 + 3] = std::floor(mapped[16 + i * 4 + 3]);
            }
            // The lit lamps after the level's lights.
            {
                const std::scoped_lock lampLock(lampMutex);
                const uint32_t lamps = std::min(lampLightCount, SceneMaxLights - std::min(lightSettings.lightCount, SceneMaxLights));
                memcpy(mapped + 16 + lightSettings.lightCount * 4, lampLights, size_t(lamps) * 4 * sizeof(float));
                mapped[0] = float(lightSettings.lightCount + lamps);
            }
            res.lightsBuffer->unmap();
        }
        res.bvhReady = res.bvhBuiltOnce;
        if (!building) {
            return;
        }
        static const bool bvhLog = (getenv("TOOIE_RT_LOG") != nullptr);
        // One geometry a draw (so a ray's geometry index finds the draw, its tile and its texture coordinates): solid
        // draws opaque, cut-outs not (the rays that read textures test them; the rest pass them by).
        // The level's own draws and the models' (characters, enemies, objects) go in separate bottom level structures:
        // the level's is kept while it is unchanged (levelKey), built for fast tracing, and the models' is built again
        // each frame. Rays that only care about models (Banjo's shadow) or only the level (Enclosed) pick theirs by mask
        // (SceneEffectsPS.hlsl RayLevelMask, RayModelMask). The geometry table has the level's from 0 and the models'
        // from MaxGeometries (the models' instance's custom index), so a ray's geometry finds its draw either way.
        thread_local std::vector<RenderBottomLevelASMesh> levelMeshes;
        thread_local std::vector<RenderBottomLevelASMesh> modelMeshes;
        levelMeshes.clear();
        modelMeshes.clear();
        bool sceneShine = false;
        bool sceneLevelCutouts = false;
        bool scenePbr = false;
        uint32_t *geometryTable = reinterpret_cast<uint32_t *>(res.rayGeometryBuffer->map());
        for (size_t i = 0; i < drawCount; i++) {
            const SceneRayDraw &draw = draws[i];
            if (draw.indexCount < 3) {
                continue;
            }
            const bool model = (draw.flags & SceneRayDrawModel) != 0;
            std::vector<RenderBottomLevelASMesh> &meshes = model ? modelMeshes : levelMeshes;
            if (meshes.size() >= MaxGeometries) {
                continue;
            }
            const bool cutout = (draw.flags & SceneRayDrawCutout) != 0;
            // The low byte of the material is Parallax's shape + 1, the next byte the ray tracing material's index.
            const uint32_t material = (draw.flags >> SceneRayDrawMaterialShift) & 0xFFu;
            scenePbr = scenePbr || ((draw.flags >> (SceneRayDrawMaterialShift + SceneRayMaterialIndexShift)) != 0u);
            sceneShine = sceneShine || (material == 12) || (material == 14) || (material == 16);
            sceneLevelCutouts = sceneLevelCutouts || ((draw.flags & (SceneRayDrawCutout | SceneRayDrawModel)) == SceneRayDrawCutout);
            uint32_t *entry = geometryTable + ((model ? MaxGeometries : 0) + meshes.size()) * 4;
            entry[0] = draw.indexStart;
            entry[1] = draw.tileIndex;
            entry[2] = draw.flags & ((1u << SceneRayDrawMaterialShift) - 1u);
            entry[3] = draw.flags >> SceneRayDrawMaterialShift;
            meshes.emplace_back(RenderBufferReference(indices, uint64_t(draw.indexStart) * sizeof(uint32_t)), RenderBufferReference(worldPos, 0),
                RenderFormat::R32_UINT, RenderFormat::R32G32B32_FLOAT, draw.indexCount - (draw.indexCount % 3), worldPosVertexCount, uint32_t(sizeof(float) * 4), !cutout);
        }
        // The ray tracing materials' records after the geometries' (record 0 is none).
        {
            uint32_t *table = geometryTable + MaxGeometries * 4;
            memset(table, 0, size_t(SceneMaxRayMaterials + 1) * 16);
            const std::scoped_lock lock(rayMaterialMutex);
            for (size_t i = 0; (i * 2 + 1) < rayMaterialWords.size(); i++) {
                table[(i + 1) * 4] = rayMaterialWords[i * 2];
                table[(i + 1) * 4 + 1] = rayMaterialWords[i * 2 + 1];
            }
        }
        res.rayGeometryBuffer->unmap();
        rayScenesPbr.store(scenePbr);
        rayScenesShine.store(sceneShine);
        rayScenesLevelCutouts.store(sceneLevelCutouts);
        if (levelMeshes.empty() && modelMeshes.empty()) {
            return;
        }
        res.bvhReady = false;
        RenderDevice *device = worker->device;
        RenderCommandList *commandList = worker->commandList.get();
        // The level's: built again only when its draws changed (or with no fingerprint to tell).
        const bool withLevel = !levelMeshes.empty();
        const bool levelKept = withLevel && (levelKey != 0) && (res.levelBuiltKey == levelKey) && (res.levelBuiltCount == levelMeshes.size()) && (res.levelBlas != nullptr);
        RenderBottomLevelASBuildInfo levelInfo;
        if (withLevel && !levelKept) {
            device->setBottomLevelASBuildInfo(levelInfo, levelMeshes.data(), uint32_t(levelMeshes.size()), false, true);
        }
        const bool withModels = !modelMeshes.empty();
        RenderBottomLevelASBuildInfo modelInfo;
        if (withModels) {
            device->setBottomLevelASBuildInfo(modelInfo, modelMeshes.data(), uint32_t(modelMeshes.size()), true, false);
        }
        RenderBottomLevelASBuildInfo grassInfo;
        if (withGrass) {
            const RenderBottomLevelASMesh grassMesh(RenderBufferReference(), RenderBufferReference(grass.vertices, 0), RenderFormat::UNKNOWN, RenderFormat::R32G32B32_FLOAT,
                0, grass.vertexCount - (grass.vertexCount % 3), uint32_t(sizeof(float) * 4), false);
            device->setBottomLevelASBuildInfo(grassInfo, &grassMesh, 1, true, false);
        }

        // Buffers that are too small are replaced (the old ones kept until the GPU is done with them).
        auto grow = [&](std::unique_ptr<RenderBuffer> &buffer, std::unique_ptr<RenderAccelerationStructure> &structure, uint64_t &capacity, uint64_t needed, const char *name) {
            if ((structure != nullptr) && (capacity >= needed)) {
                return false;
            }
            const uint64_t size = std::max<uint64_t>(needed + needed / 2, 1u << 20);
            res.retireLater(std::move(structure));
            res.retireLater(std::move(buffer));
            buffer = device->createBuffer(RenderBufferDesc::AccelerationStructureBuffer(size));
            buffer->setName(name);
            structure = device->createAccelerationStructure(RenderAccelerationStructureDesc(RenderAccelerationStructureType::BOTTOM_LEVEL, RenderBufferReference(buffer.get()), size));
            capacity = size;
            return true;
        };
        if (withLevel && !levelKept) {
            grow(res.levelBlasBuffer, res.levelBlas, res.levelBlasSize, levelInfo.accelerationStructureSize, "Scene Effects level BLAS");
        }
        if (withModels) {
            grow(res.bvhBlasBuffer, res.bvhBlas, res.bvhBlasSize, modelInfo.accelerationStructureSize, "Scene Effects models BLAS");
        }
        if (withGrass && grow(res.grassBlasBuffer, res.grassBlas, res.grassBlasSize, grassInfo.accelerationStructureSize, "Scene Effects grass BLAS")) {
            res.grassBuiltGeneration = UINT64_MAX;
        }
        bool grassBuild = false;
        if (withGrass) {
            grassBuild = (res.grassBuiltGeneration != grass.generation) || (res.grassBuiltVertices != grass.vertices);
        }
        // Instance 0 the level (mask 1), the models (mask 4, custom index MaxGeometries), the grass (mask 2, RayGrassInstance).
        RenderTopLevelASInstance instances[3];
        const RenderBuffer *instanceBuffers[3] = {};
        uint32_t instanceCount = 0;
        if (withLevel) {
            instanceBuffers[instanceCount] = res.levelBlasBuffer.get();
            instances[instanceCount++] = RenderTopLevelASInstance(RenderBufferReference(res.levelBlasBuffer.get()), 0, 0x01, 0, true, RenderAffineTransform());
        }
        if (withModels) {
            instanceBuffers[instanceCount] = res.bvhBlasBuffer.get();
            instances[instanceCount++] = RenderTopLevelASInstance(RenderBufferReference(res.bvhBlasBuffer.get()), uint32_t(MaxGeometries), 0x04, 0, true, RenderAffineTransform());
        }
        if (withGrass) {
            instanceBuffers[instanceCount] = res.grassBlasBuffer.get();
            instances[instanceCount++] = RenderTopLevelASInstance(RenderBufferReference(res.grassBlasBuffer.get()), 0xFFFFFFu, 0x02, 0, true, RenderAffineTransform());
        }
        const bool instancesChanged = (instanceCount != res.bvhInstanceCount) || !std::equal(instanceBuffers, instanceBuffers + 3, res.bvhInstanceBuffers);
        res.bvhInstanceCount = instanceCount;
        std::copy(instanceBuffers, instanceBuffers + 3, res.bvhInstanceBuffers);
        RenderTopLevelASBuildInfo tlasInfo;
        device->setTopLevelASBuildInfo(tlasInfo, instances, instanceCount, true, false);
        if ((res.bvhTlas == nullptr) || (res.bvhTlasSize < tlasInfo.accelerationStructureSize)) {
            const uint64_t size = std::max<uint64_t>(tlasInfo.accelerationStructureSize, 4096);
            res.retireLater(std::move(res.bvhTlas));
            res.retireLater(std::move(res.bvhTlasBuffer));
            res.bvhTlasBuffer = device->createBuffer(RenderBufferDesc::AccelerationStructureBuffer(size));
            res.bvhTlasBuffer->setName("Scene Effects TLAS");
            res.bvhTlas = device->createAccelerationStructure(RenderAccelerationStructureDesc(RenderAccelerationStructureType::TOP_LEVEL, RenderBufferReference(res.bvhTlasBuffer.get()), size));
            res.bvhTlasSize = size;
        }
        const uint64_t scratchNeeded = std::max({ (withLevel && !levelKept) ? levelInfo.scratchSize : 0, withModels ? modelInfo.scratchSize : 0, tlasInfo.scratchSize,
            withGrass ? grassInfo.scratchSize : 0 });
        if ((res.bvhScratchBuffer == nullptr) || (res.bvhScratchSize < scratchNeeded)) {
            const uint64_t size = std::max<uint64_t>(scratchNeeded + scratchNeeded / 2, 1u << 20);
            res.retireLater(std::move(res.bvhScratchBuffer));
            res.bvhScratchBuffer = device->createBuffer(RenderBufferDesc::DefaultBuffer(size, RenderBufferFlag::ACCELERATION_STRUCTURE_SCRATCH));
            res.bvhScratchBuffer->setName("Scene Effects BVH scratch");
            res.bvhScratchSize = size;
        }
        if ((res.bvhInstancesBuffer == nullptr) || instancesChanged) {
            res.retireLater(std::move(res.bvhInstancesBuffer));
            res.bvhInstancesBuffer = device->createBuffer(RenderBufferDesc::UploadBuffer(std::max<uint64_t>(tlasInfo.instancesBufferData.size(), 256), RenderBufferFlag::ACCELERATION_STRUCTURE_INPUT));
            res.bvhInstancesBuffer->setName("Scene Effects BVH instances");
            void *mapped = res.bvhInstancesBuffer->map();
            memcpy(mapped, tlasInfo.instancesBufferData.data(), tlasInfo.instancesBufferData.size());
            res.bvhInstancesBuffer->unmap();
        }
        if ((withLevel && (res.levelBlas == nullptr)) || (withModels && (res.bvhBlas == nullptr)) || (res.bvhTlas == nullptr) || (res.bvhScratchBuffer == nullptr) || (res.bvhInstancesBuffer == nullptr)) {
            return;
        }

        GpuCheckpoint(commandList, GpuSectionMarker(GpuSection::RayTracingBuild, false));
        const int buildSpan = WorkloadGpuSections().start(GpuSection::RayTracingBuild, commandList);
        // Each build in turn through the one scratch buffer.
        auto buildBottom = [&](RenderAccelerationStructure *structure, RenderBuffer *buffer, const RenderBottomLevelASBuildInfo &info, const RenderBuffer *vertices) {
            commandList->barriers(RenderBarrierStage::COMPUTE, {
                RenderBufferBarrier(const_cast<RenderBuffer *>(vertices), RenderBufferAccess::READ),
                RenderBufferBarrier(const_cast<RenderBuffer *>(indices), RenderBufferAccess::READ),
                RenderBufferBarrier(buffer, RenderBufferAccess::WRITE),
                RenderBufferBarrier(res.bvhScratchBuffer.get(), RenderBufferAccess::WRITE)
            });
            commandList->buildBottomLevelAS(structure, RenderBufferReference(res.bvhScratchBuffer.get()), info);
        };
        if (withLevel && !levelKept) {
            buildBottom(res.levelBlas.get(), res.levelBlasBuffer.get(), levelInfo, worldPos);
            res.levelBuiltKey = levelKey;
            res.levelBuiltCount = levelMeshes.size();
        }
        if (withModels) {
            buildBottom(res.bvhBlas.get(), res.bvhBlasBuffer.get(), modelInfo, worldPos);
        }
        if (grassBuild) {
            buildBottom(res.grassBlas.get(), res.grassBlasBuffer.get(), grassInfo, grass.vertices);
            res.grassBuiltGeneration = grass.generation;
            res.grassBuiltVertices = grass.vertices;
        }
        commandList->barriers(RenderBarrierStage::COMPUTE, {
            RenderBufferBarrier(res.bvhScratchBuffer.get(), RenderBufferAccess::WRITE),
            RenderBufferBarrier(res.bvhTlasBuffer.get(), RenderBufferAccess::WRITE)
        });
        for (uint32_t i = 0; i < instanceCount; i++) {
            commandList->barriers(RenderBarrierStage::COMPUTE, { RenderBufferBarrier(const_cast<RenderBuffer *>(instanceBuffers[i]), RenderBufferAccess::READ) });
        }
        commandList->buildTopLevelAS(res.bvhTlas.get(), RenderBufferReference(res.bvhScratchBuffer.get()), RenderBufferReference(res.bvhInstancesBuffer.get()), tlasInfo);
        commandList->barriers(RenderBarrierStage::GRAPHICS | RenderBarrierStage::COMPUTE, {
            RenderBufferBarrier(res.bvhTlasBuffer.get(), RenderBufferAccess::READ)
        });
        WorkloadGpuSections().end(buildSpan);
        GpuCheckpoint(commandList, GpuSectionMarker(GpuSection::RayTracingBuild, true));
        res.bvhReady = true;
        res.bvhBuiltOnce = true;
        res.rayTexturesValid = haveTextureBuffers && (res.rayTextureCacheSet != nullptr);
        if (bvhLog) {
            static auto lastLog = std::chrono::steady_clock::now();
            if (std::chrono::steady_clock::now() - lastLog > std::chrono::milliseconds(1000)) {
                lastLog = std::chrono::steady_clock::now();
                fprintf(stderr, "[rt] BVH built: level %zu geometries (%s, BLAS %llu KB), models %zu geometries (BLAS %llu KB), TLAS %llu KB, scratch %llu KB, grass %s (BLAS %llu KB, reach %.0f)\n",
                    levelMeshes.size(), levelKept ? "kept" : "rebuilt", (unsigned long long)(res.levelBlasSize / 1024), modelMeshes.size(), (unsigned long long)(res.bvhBlasSize / 1024), (unsigned long long)(res.bvhTlasSize / 1024), (unsigned long long)(res.bvhScratchSize / 1024),
                    withGrass ? (grassBuild ? "rebuilt" : "kept") : "none", (unsigned long long)(res.grassBlasSize / 1024), grass.reach);
                uint32_t modelDraws = 0, modelTris = 0, cutDraws = 0, shineDraws = 0, materialDraws = 0;
                for (size_t i = 0; i < drawCount; i++) {
                    const uint32_t material = (draws[i].flags >> SceneRayDrawMaterialShift) & 0xFFu;
                    if (material != 0) { materialDraws++; }
                    if ((material == 12) || (material == 14) || (material == 16)) { shineDraws++; }
                    if ((draws[i].flags & SceneRayDrawModel) != 0) { modelDraws++; modelTris += draws[i].indexCount / 3; }
                    if ((draws[i].flags & SceneRayDrawCutout) != 0) { cutDraws++; }
                }
                fprintf(stderr, "[rt] models %u (%u tris), cut-outs %u, with a material %u (shiny %u)\n", modelDraws, modelTris, cutDraws, materialDraws, shineDraws);
            }
        }
    }

    void RecordSceneEffects(RenderWorker *worker, RenderTarget *colorTarget, RenderTarget *depthTarget,
        const interop::float4x4 &projection, const interop::float4x4 &view, const ShaderLibrary *shaderLibrary, const RenderRect &area,
        float depthScale, float depthTranslate, const std::function<void(RenderCommandList *)> &drawSunCasters)
    {

        sceneEffectsRecorded++;
        SceneEffectsSettings settings = GetSceneEffects();
        if (effectsWorkloadKnown) {
            UsePlayerFrame(settings, effectsWorkload);
        }

        // The game's matrices are row-vector (clip = v * M), so w = -z comes from m[2][3]; take the
        // transposed terms if the matrix is the other way round.
        const float (&m)[4][4] = projection.m;
        const bool rowVector = std::abs(m[2][3] + 1.0f) <= std::abs(m[3][2] + 1.0f);
        if ((std::abs(m[2][3] + 1.0f) > 0.01f) && (std::abs(m[3][2] + 1.0f) > 0.01f)) {
            // Not a perspective projection after all (the game can briefly set others).
            return;
        }
        interop::SceneEffectsCB constants;
        constants.depthTerms = DepthTermsForViewport(rowVector ? interop::float4{ m[2][2], m[3][2], m[2][3], m[3][3] } : interop::float4{ m[2][2], m[2][3], m[3][2], m[3][3] }, depthScale, depthTranslate);
        constants.projection = { m[0][0], m[1][1], float(colorTarget->width), float(colorTarget->height) };
        // Ambient occlusion, SSGI and SSR in hundredths, packed as AO + 128 * SSGI + 16384 * SSR + 2097152 * stochastic glossiness 0 to 7 (IndirectPacked).
        const auto hundredths = [](float strength) { return std::round(std::clamp(strength, 0.0f, 1.0f) * 100.0f); };
        const float indirectPacked = hundredths(settings.ambientOcclusion) + 128.0f * hundredths(settings.screenSpaceGI) + 16384.0f * hundredths(settings.screenSpaceReflections) +
            2097152.0f * std::round(std::clamp(settings.reflectionGlossiness, 0.0f, 1.0f) * 7.0f);
        constants.ambientOcclusion = { indirectPacked, settings.ambientOcclusionRadius, 0.0f, std::min(settings.rimLight, 1.0f) + 2.0f * (std::round(std::clamp(settings.toonShading, 0.0f, 1.0f) * 100.0f) + 101.0f * std::round(std::clamp(settings.toonCharacters, 0.0f, 1.0f) * 100.0f)) };
        static const auto startTime = std::chrono::steady_clock::now();
        const float seconds = std::fmod(std::chrono::duration<float>(std::chrono::steady_clock::now() - startTime).count(), 3600.0f);
        // Heat haze only above warm surfaces is sent as 2 + its strength (see HeatHaze in SceneEffectsPS).
        const float heatPacked = (settings.heatHazeWarmOnly && (settings.heatHaze > 0.0f)) ? 2.0f + std::min(settings.heatHaze, 1.0f) : settings.heatHaze;
        constants.view = { float(settings.view), PackSceneClouds(settings.dayCloudShape, settings.compare), seconds, heatPacked };
        // The fog's start and length ride in the low 12 bits of fog.y and fog.z (steps of 4 units: an integer below 2^24 is exact
        // in a float), the WIP volumetric effects in the 12 bits above each (VolSettings in the shader): fog.y mist (6 bits, 0 to
        // 63) and fog (6); fog.z the fog's preset (3), the forced cloud type (3), then the mist floor's height over Banjo's feet in
        // steps of 8 units (6 bits, 32 = level).
        uint32_t volA = 0;
        uint32_t volB = 0;
        if ((settings.volMist > 0.0f) || (settings.volFog > 0.0f) || (settings.volCloudType > 0)) {
            const float floorDelta = (settings.volAnchorValid && (settings.player[1] > -1e8f)) ? (settings.volAnchor - settings.player[1] + settings.volMistOffset) : settings.volMistOffset;
            volA = uint32_t(std::lround(settings.volMist * 63.0f)) | (uint32_t(std::lround(settings.volFog * 63.0f)) << 6);
            volB = settings.volFogPreset | (settings.volCloudType << 3) | (uint32_t(std::lround(std::clamp(floorDelta / 8.0f + 32.0f, 0.0f, 63.0f))) << 6);
        }
        const auto packFog = [](float distance, uint32_t vol, float least) {
            return float(uint32_t(std::lround(std::clamp(distance, least, 16380.0f) / 4.0f)) | (vol << 12));
        };
        constants.fog = { settings.fog, packFog(settings.fogStart, volA, 0.0f), packFog(settings.fogLength, volB, 4.0f), settings.underwaterTint };
        // The fog darkens with the time of day as the sky does.
        const float fogTint[3] = { settings.dayTint[0] * settings.dayTint[0], settings.dayTint[1] * settings.dayTint[1], settings.dayTint[2] * settings.dayTint[2] };
        constants.fogColor = { settings.fogColor[0] * fogTint[0], settings.fogColor[1] * fogTint[1], settings.fogColor[2] * fogTint[2],
            (settings.outlines > 0.0f) ? (settings.outlines + 2.0f * (std::round(settings.outlineThickness * 4.0f) - 1.0f)) : 0.0f };

        constants.bloom = { settings.bloom, settings.depthOfFieldOnBanjo ? -settings.depthOfField : settings.depthOfField, settings.eyeAdaptation, settings.underwaterHaze };

        // The waves' own clock, so changing their speed doesn't make them jump.
        static auto waveClock = std::chrono::steady_clock::now();
        static double waveTime = 0.0;
        const auto now = std::chrono::steady_clock::now();
        waveTime = std::fmod(waveTime + std::min(std::chrono::duration<double>(now - waveClock).count(), 0.25) * settings.waveSpeed, 3600.0);
        waveClock = now;
        constants.ambientOcclusion.z = float(waveTime);
        constants.rippleX = { settings.rippleX[0], settings.rippleX[1], settings.rippleX[2], settings.player[0] };
        constants.rippleZ = { settings.rippleZ[0], settings.rippleZ[1], settings.rippleZ[2], settings.player[2] };
        constants.rippleAge = { settings.rippleAge[0], settings.rippleAge[1], settings.rippleAge[2], settings.player[1] };

        // World x and z from a view-space position: the view matrix (row vectors: view = world * V) is a
        // scaled rotation A and a translation t, so world = (view - t) * inverse(A).
        {
            float v[4][4];
            for (int r = 0; r < 4; r++) {
                for (int c = 0; c < 4; c++) {
                    v[r][c] = rowVector ? view.m[r][c] : view.m[c][r];
                }
            }
            const float det = v[0][0] * (v[1][1] * v[2][2] - v[1][2] * v[2][1]) - v[0][1] * (v[1][0] * v[2][2] - v[1][2] * v[2][0]) + v[0][2] * (v[1][0] * v[2][1] - v[1][1] * v[2][0]);
            if (std::abs(det) > 1e-12f) {
                // Columns 0 and 2 of inverse(A).
                const float x0 = (v[1][1] * v[2][2] - v[1][2] * v[2][1]) / det;
                const float x1 = -(v[1][0] * v[2][2] - v[1][2] * v[2][0]) / det;
                const float x2 = (v[1][0] * v[2][1] - v[1][1] * v[2][0]) / det;
                const float z0 = (v[0][1] * v[1][2] - v[0][2] * v[1][1]) / det;
                const float z1 = -(v[0][0] * v[1][2] - v[0][2] * v[1][0]) / det;
                const float z2 = (v[0][0] * v[1][1] - v[0][1] * v[1][0]) / det;
                // Column 1 of inverse(A).
                const float y0 = -(v[0][1] * v[2][2] - v[0][2] * v[2][1]) / det;
                const float y1 = (v[0][0] * v[2][2] - v[0][2] * v[2][0]) / det;
                const float y2 = -(v[0][0] * v[2][1] - v[0][1] * v[2][0]) / det;
                constants.worldY = { y0, y1, y2, -(v[3][0] * y0 + v[3][1] * y1 + v[3][2] * y2) };
                constants.worldX = { x0, x1, x2, -(v[3][0] * x0 + v[3][1] * x1 + v[3][2] * x2) };
                constants.worldZ = { z0, z1, z2, -(v[3][0] * z0 + v[3][1] * z1 + v[3][2] * z2) };
            }
            else {
                constants.worldX = { 1.0f, 0.0f, 0.0f, 0.0f };
                constants.worldZ = { 0.0f, 0.0f, 1.0f, 0.0f };
                constants.worldY = { 0.0f, 1.0f, 0.0f, 0.0f };
            }

            // The sun's direction in view space, through the view matrix (directions skip the translation).
            const float *sunWorld = settings.customSun ? settings.sunDirection : FixedSun;
            float sunView[3];
            for (int c = 0; c < 3; c++) {
                sunView[c] = sunWorld[0] * v[0][c] + sunWorld[1] * v[1][c] + sunWorld[2] * v[2][c];
            }
            // Headless test hook: TOOIE_SUN_FRONT puts the sun just right of and above the middle of the screen,
            // or at TOOIE_SUN_FRONT=<x>,<y> (view space, the camera looking down -z).
            static const char *sunFrontValue = getenv("TOOIE_SUN_FRONT");
            if (sunFrontValue != nullptr) {
                float x = 0.2f, y = 0.25f;
                sscanf(sunFrontValue, "%f,%f", &x, &y);
                sunView[0] = x;
                sunView[1] = y;
                sunView[2] = -1.0f;
            }
            const float sunLength = std::sqrt(sunView[0] * sunView[0] + sunView[1] * sunView[1] + sunView[2] * sunView[2]);
            // Shadows fade out as the sun sets, gone once it is below the horizon.
            const float worldLength = std::sqrt(sunWorld[0] * sunWorld[0] + sunWorld[1] * sunWorld[1] + sunWorld[2] * sunWorld[2]);
            const float height = (worldLength > 1e-6f) ? sunWorld[1] / worldLength : 0.0f;
            const float daylight = std::clamp(height / 0.15f, 0.0f, 1.0f);
            // Without the cycle, 0.5 shows the sun in the sky while the sun shadows are on (HeldSun in SceneEffectsPS).
            float dayPacked = ((settings.sunShadows > 0.0f) && (daylight > 0.0f)) ? 0.5f : 0.0f;
            if (settings.timeOfDay) {
                uint32_t packed = 0;
                for (int c = 0; c < 3; c++) {
                    packed = (packed << 7) | uint32_t(std::clamp(std::lround(settings.dayTint[c] * 100.0f), 0L, 127L));
                }
                // Then three flags: fireflies, clouds and the northern lights.
                packed = (packed << 3) | (settings.dayAurora ? 4u : 0u) | (settings.dayClouds ? 2u : 0u) | (settings.dayFireflies ? 1u : 0u);
                // Negative: no lens flare.
                dayPacked = (1.0f + float(packed)) * (settings.dayFlare ? 1.0f : -1.0f);
            }
            // Moonlight casts fainter shadows: as the tint darkens towards night (as DayNight in the shader).
            const float dayBrightest = std::max(settings.dayTint[0], std::max(settings.dayTint[1], settings.dayTint[2]));
            const float moonlight = 1.0f - 0.6f * std::clamp((0.97f - dayBrightest) / 0.3f, 0.0f, 1.0f);
            // Rain hides the sun: no sun shadows under it.
            const float rain = settings.timeOfDay ? settings.dayRain : 0.0f;
            // The rain's details ride above the softness and Banjo's flag: 4 * (512 * how wet the ground is (0 to 31) +
            // 16384 when raindrops land on the screen).
            const float mistPacked = settings.timeOfDay ? 4.0f * (512.0f * std::round(settings.dayWet * 31.0f) + (settings.dayDrops ? 16384.0f : 0.0f)) : 0.0f;
            constants.shadows = { settings.sunShadows * daylight * moonlight * (1.0f - rain),
                std::min(settings.sunShadowReach, 999.0f) + 1000.0f * std::round(settings.sunShadowDistance / SUN_SHADOW_MAP_HALF_STEP), dayPacked, (settings.sunShadowOnBanjo ? 0.0f : 2.0f) + settings.sunShadowSoftness * 0.99f + mistPacked };
            if (sunLength > 1e-6f) {
                float shafts = settings.lightShafts * settings.dayShafts;
                if (settings.timeOfDay) {
                    // Weather and the moon: -(1 + the moon's phase (0 to 7) in bits 17 to 19, snow in bit 16, rain * 255
                    // in bits 8 to 15, the shafts' strength * 255 below, then the lightning as the fraction), so it all
                    // fits the one constant. The shafts fade with the rain.
                    const float rain8 = std::round(rain * 255.0f);
                    const float shafts8 = std::round(std::clamp(shafts * (1.0f - rain), 0.0f, 1.0f) * 255.0f);
                    const float snow = settings.daySnow ? 65536.0f : 0.0f;
                    const float moon = float(settings.dayMoonPhase & 7u) * 131072.0f;
                    shafts = -(1.0f + moon + snow + rain8 * 256.0f + shafts8 + std::min(settings.dayFlash, 0.99f));
                }
                constants.sun = { sunView[0] / sunLength, sunView[1] / sunLength, sunView[2] / sunLength, shafts };
            }
            else {
                constants.sun = { 0.0f, 0.0f, 1.0f, 0.0f };
            }
        }

        {
            static const bool fxLog = (getenv("TOOIE_FX_LOG") != nullptr);
            static auto lastLog = std::chrono::steady_clock::now();
            if (fxLog && (std::chrono::steady_clock::now() - lastLog > std::chrono::milliseconds(500))) {
                lastLog = std::chrono::steady_clock::now();
                fprintf(stderr, "[fx] fog %.2f start %.0f player %.0f %.0f %.0f cam %.0f %.0f %.0f proj %.3f %.3f depth %.4f %.4f %.4f %.4f\n", constants.fog.x, constants.fog.y,
                    settings.player[0], settings.player[1], settings.player[2], constants.worldX.w, constants.worldY.w, constants.worldZ.w,
                    constants.projection.x, constants.projection.y, constants.depthTerms.x, constants.depthTerms.y, constants.depthTerms.z, constants.depthTerms.w);
            }
        }

        RenderCommandList *commandList = worker->commandList.get();
        Resources &res = resourcesFor(worker);
        res.freeRetired();
        const RenderFormat format = RenderTarget::colorBufferFormat(shaderLibrary->usesHDR);
        const uint32_t bloomWidth = std::max(colorTarget->width / 4, 1U);
        const uint32_t bloomHeight = std::max(colorTarget->height / 4, 1U);
        if ((res.bloomTexture[0] == nullptr) || (res.bloomWidth != bloomWidth) || (res.bloomHeight != bloomHeight)) {
            res.retire();
            for (int i = 0; i < Resources::BloomTextures; i++) {
                const bool eighth = (i == 2) || (i == 3);
                res.bloomTexture[i] = worker->device->createTexture(RenderTextureDesc::ColorTarget(eighth ? std::max(bloomWidth / 2, 1U) : bloomWidth,
                    eighth ? std::max(bloomHeight / 2, 1U) : bloomHeight, format));
                res.bloomTexture[i]->setName("Scene Effects Bloom");
                const RenderTexture *texture = res.bloomTexture[i].get();
                res.bloomFramebuffer[i] = worker->device->createFramebuffer(RenderFramebufferDesc(&texture, 1));
                res.bloomSet[i] = std::make_unique<SmaaDescriptorSet>(shaderLibrary->samplerLibrary.linear.clampClamp.get(),
                    shaderLibrary->samplerLibrary.nearest.clampClamp.get(), worker->device);
                res.bloomSet[i]->setTexture(res.bloomSet[i]->gTexture0, texture, RenderTextureLayout::SHADER_READ);
                res.bloomSet[i]->setTexture(res.bloomSet[i]->gTexture1, texture, RenderTextureLayout::SHADER_READ);
                res.bloomSet[i]->setTexture(res.bloomSet[i]->gTexture2, texture, RenderTextureLayout::SHADER_READ);
            }
            res.bloomCombineSet = std::make_unique<SmaaDescriptorSet>(shaderLibrary->samplerLibrary.linear.clampClamp.get(),
                shaderLibrary->samplerLibrary.nearest.clampClamp.get(), worker->device);
            res.bloomCombineSet->setTexture(res.bloomCombineSet->gTexture0, res.bloomTexture[0].get(), RenderTextureLayout::SHADER_READ);
            res.bloomCombineSet->setTexture(res.bloomCombineSet->gTexture1, res.bloomTexture[2].get(), RenderTextureLayout::SHADER_READ);
            res.bloomCombineSet->setTexture(res.bloomCombineSet->gTexture2, res.bloomTexture[2].get(), RenderTextureLayout::SHADER_READ);
            res.bloomWidth = bloomWidth;
            res.bloomHeight = bloomHeight;
            res.halfTexture = worker->device->createTexture(RenderTextureDesc::ColorTarget(std::max(colorTarget->width / 2, 1U), std::max(colorTarget->height / 2, 1U), format));
            res.halfTexture->setName("Scene Effects Half Scene");
            const RenderTexture *halfTexturePtr = res.halfTexture.get();
            res.halfFramebuffer = worker->device->createFramebuffer(RenderFramebufferDesc(&halfTexturePtr, 1));
            commandList->barriers(RenderBarrierStage::GRAPHICS, RenderTextureBarrier(res.halfTexture.get(), RenderTextureLayout::COLOR_WRITE));
            commandList->setFramebuffer(res.halfFramebuffer.get());
            commandList->clearColor(0, RenderColor(0.0f, 0.0f, 0.0f, 0.0f));
            commandList->barriers(RenderBarrierStage::GRAPHICS, RenderTextureBarrier(res.halfTexture.get(), RenderTextureLayout::SHADER_READ));
            std::vector<RenderTextureBarrier> barriers;
            for (int i = 0; i < Resources::BloomTextures; i++) {
                barriers.emplace_back(res.bloomTexture[i].get(), RenderTextureLayout::COLOR_WRITE);
            }
            commandList->barriers(RenderBarrierStage::GRAPHICS, barriers);
            // Start black, so a frame that skips the bloom reads nothing from them.
            for (int i = 0; i < Resources::BloomTextures; i++) {
                commandList->setFramebuffer(res.bloomFramebuffer[i].get());
                commandList->clearColor(0, RenderColor(0.0f, 0.0f, 0.0f, 0.0f));
            }
            barriers.clear();
            for (int i = 0; i < Resources::BloomTextures; i++) {
                barriers.emplace_back(res.bloomTexture[i].get(), RenderTextureLayout::SHADER_READ);
            }
            commandList->barriers(RenderBarrierStage::GRAPHICS, barriers);
        }

        RenderTexture *source = nullptr;
        if ((settings.bloom > 0.0f) || (settings.depthOfField > 0.0f) || (settings.eyeAdaptation > 0.0f) || (settings.toonShading > 0.0f) || (settings.toonCharacters > 0.0f) || (settings.underwaterTint > 0.0f) || (settings.heatHaze > 0.0f) || (settings.waterReflections > 0.0f) || (settings.iceReflections > 0.0f) || (settings.waterWaves > 0.0f) || settings.shoreFoam || settings.modernWater || (settings.lightShafts > 0.0f) || (settings.bounceLight > 0.0f) || (settings.screenSpaceGI > 0.0f) || (settings.screenSpaceReflections > 0.0f) || settings.timeOfDay || (settings.volMist > 0.0f) || (settings.volFog > 0.0f) || (settings.volCloudType > 0)) {
            // The scene so far, without multisampling: the target's resolve, or a copy of the target.
            const RenderTextureView *sourceView = nullptr;
            if (colorTarget->usesResolve()) {
                colorTarget->markForResolve();
                colorTarget->resolveTarget(worker, shaderLibrary);
                source = colorTarget->getResolvedTexture();
                sourceView = colorTarget->getResolvedTextureView();
            }
            else {
                if ((res.copyTexture == nullptr) || (res.copyWidth != colorTarget->width) || (res.copyHeight != colorTarget->height)) {
                    if (res.copyTexture != nullptr) {
                        res.retireLater(std::move(res.copyTexture));
                    }
                    res.copyTexture = worker->device->createTexture(RenderTextureDesc::ColorTarget(colorTarget->width, colorTarget->height, format));
                    res.copyTexture->setName("Scene Effects Copy");
                    res.copyWidth = colorTarget->width;
                    res.copyHeight = colorTarget->height;
                }

                commandList->barriers(RenderBarrierStage::COPY, {
                    RenderTextureBarrier(colorTarget->texture.get(), RenderTextureLayout::COPY_SOURCE),
                    RenderTextureBarrier(res.copyTexture.get(), RenderTextureLayout::COPY_DEST)
                });
                commandList->copyTexture(res.copyTexture.get(), colorTarget->texture.get());
                source = res.copyTexture.get();
            }

            if ((res.sourceSet == nullptr) || (res.sourceSetTexture != source)) {
                if (res.sourceSet != nullptr) {
                    res.retireLater(std::move(res.sourceSet));
                }
                res.sourceSet = std::make_unique<SmaaDescriptorSet>(shaderLibrary->samplerLibrary.linear.clampClamp.get(),
                    shaderLibrary->samplerLibrary.nearest.clampClamp.get(), worker->device);
                res.sourceSet->setTexture(res.sourceSet->gTexture0, source, RenderTextureLayout::SHADER_READ, sourceView);
                res.sourceSet->setTexture(res.sourceSet->gTexture1, source, RenderTextureLayout::SHADER_READ, sourceView);
                res.sourceSet->setTexture(res.sourceSet->gTexture2, source, RenderTextureLayout::SHADER_READ, sourceView);
                res.sourceSetTexture = source;
            }

            commandList->barriers(RenderBarrierStage::GRAPHICS, {
                RenderTextureBarrier(source, RenderTextureLayout::SHADER_READ)
            });
        }

        if (res.luminanceTexture[0] == nullptr) {
            for (int i = 0; i < 3; i++) {
                res.luminanceTexture[i] = worker->device->createTexture(RenderTextureDesc::ColorTarget(1, 1, RenderFormat::R32G32_FLOAT));
                res.luminanceTexture[i]->setName("Scene Effects Luminance");
                const RenderTexture *texture = res.luminanceTexture[i].get();
                res.luminanceFramebuffer[i] = worker->device->createFramebuffer(RenderFramebufferDesc(&texture, 1));
            }

            // Adapting into [1] reads the measured brightness [0] and last frame's [2].
            res.adaptSet = std::make_unique<SmaaDescriptorSet>(shaderLibrary->samplerLibrary.linear.clampClamp.get(),
                shaderLibrary->samplerLibrary.nearest.clampClamp.get(), worker->device);
            res.adaptSet->setTexture(res.adaptSet->gTexture0, res.luminanceTexture[0].get(), RenderTextureLayout::SHADER_READ);
            res.adaptSet->setTexture(res.adaptSet->gTexture1, res.luminanceTexture[2].get(), RenderTextureLayout::SHADER_READ);
            res.adaptSet->setTexture(res.adaptSet->gTexture2, res.luminanceTexture[0].get(), RenderTextureLayout::SHADER_READ);

            // Start with nothing adapted yet (0), so the first measurement is taken as it is.
            for (int i = 0; i < 3; i++) {
                commandList->barriers(RenderBarrierStage::GRAPHICS, RenderTextureBarrier(res.luminanceTexture[i].get(), RenderTextureLayout::COLOR_WRITE));
                commandList->setFramebuffer(res.luminanceFramebuffer[i].get());
                commandList->clearColor(0, RenderColor(0.0f, 0.0f, 0.0f, 0.0f));
                commandList->barriers(RenderBarrierStage::GRAPHICS, RenderTextureBarrier(res.luminanceTexture[i].get(), RenderTextureLayout::SHADER_READ));
            }
        }

        if ((settings.eyeAdaptation > 0.0f) && (source != nullptr)) {
            if ((res.measureSet == nullptr) || (res.measureSetTexture != source)) {
                if (res.measureSet != nullptr) {
                    res.retireLater(std::move(res.measureSet));
                }
                res.measureSet = std::make_unique<SmaaDescriptorSet>(shaderLibrary->samplerLibrary.linear.clampClamp.get(),
                    shaderLibrary->samplerLibrary.nearest.clampClamp.get(), worker->device);
                const RenderTextureView *view = colorTarget->usesResolve() ? colorTarget->getResolvedTextureView() : nullptr;
                res.measureSet->setTexture(res.measureSet->gTexture0, source, RenderTextureLayout::SHADER_READ, view);
                res.measureSet->setTexture(res.measureSet->gTexture1, source, RenderTextureLayout::SHADER_READ, view);
                res.measureSet->setTexture(res.measureSet->gTexture2, source, RenderTextureLayout::SHADER_READ, view);
                res.measureSetTexture = source;
            }

            // The time step as a rate (63% of the way each second); BloomPS.hlsl makes it quicker or slower.
            const auto now = std::chrono::steady_clock::now();
            const float seconds = std::min(std::chrono::duration<float>(now - res.lastAdapt).count(), 0.25f);
            res.lastAdapt = now;
            const float rate = 1.0f - std::exp(-seconds / 1.0f);

            auto luminancePass = [&](const SmaaDescriptorSet *input, int output, float pass, float amount) {
                commandList->barriers(RenderBarrierStage::GRAPHICS, RenderTextureBarrier(res.luminanceTexture[output].get(), RenderTextureLayout::COLOR_WRITE));
                interop::BloomCB luminanceConstants;
                luminanceConstants.params = { 0.0f, 0.0f, pass, amount };
                commandList->setFramebuffer(res.luminanceFramebuffer[output].get());
                commandList->setViewports(RenderViewport(0.0f, 0.0f, 1.0f, 1.0f));
                commandList->setScissors(RenderRect(0, 0, 1, 1));
                commandList->setPipeline(shaderLibrary->luminance.pipeline.get());
                commandList->setGraphicsPipelineLayout(shaderLibrary->luminance.pipelineLayout.get());
                commandList->setGraphicsDescriptorSet(input->get(), 0);
                commandList->setGraphicsPushConstants(0, &luminanceConstants);
                commandList->setVertexBuffers(0, nullptr, 0, nullptr);
                commandList->drawInstanced(3, 1, 0, 0);
                commandList->barriers(RenderBarrierStage::GRAPHICS, RenderTextureBarrier(res.luminanceTexture[output].get(), RenderTextureLayout::SHADER_READ));
            };

            GpuSectionScope timed(WorkloadGpuSections(), GpuSection::EyeAdaptation, commandList);
            luminancePass(res.measureSet.get(), 0, 3.0f, 0.0f);
            luminancePass(res.adaptSet.get(), 1, 4.0f, rate);
            commandList->barriers(RenderBarrierStage::COPY, {
                RenderTextureBarrier(res.luminanceTexture[1].get(), RenderTextureLayout::COPY_SOURCE),
                RenderTextureBarrier(res.luminanceTexture[2].get(), RenderTextureLayout::COPY_DEST)
            });
            commandList->copyTexture(res.luminanceTexture[2].get(), res.luminanceTexture[1].get());
            commandList->barriers(RenderBarrierStage::GRAPHICS, {
                RenderTextureBarrier(res.luminanceTexture[1].get(), RenderTextureLayout::SHADER_READ),
                RenderTextureBarrier(res.luminanceTexture[2].get(), RenderTextureLayout::SHADER_READ)
            });
        }

        if (settings.bloom > 0.0f) {
            // Bright parts at a quarter of the size into [0], blurred across into [1] and down into [0]; the same
            // at an eighth from [0] into [2] (through [3]) for a wider glow; then both together into [4].
            auto bloomPass = [&](const SmaaDescriptorSet *input, RenderTexture *inputTexture, int output, uint32_t inputWidth, uint32_t inputHeight, float pass) {
                commandList->barriers(RenderBarrierStage::GRAPHICS, {
                    RenderTextureBarrier(inputTexture, RenderTextureLayout::SHADER_READ),
                    RenderTextureBarrier(res.bloomTexture[output].get(), RenderTextureLayout::COLOR_WRITE)
                });

                const bool eighth = (output == 2) || (output == 3);
                const uint32_t outputWidth = eighth ? std::max(bloomWidth / 2, 1U) : bloomWidth;
                const uint32_t outputHeight = eighth ? std::max(bloomHeight / 2, 1U) : bloomHeight;
                interop::BloomCB bloomConstants;
                bloomConstants.params = { 1.0f / float(inputWidth), 1.0f / float(inputHeight), pass, settings.bloomThreshold };
                commandList->setFramebuffer(res.bloomFramebuffer[output].get());
                commandList->setViewports(RenderViewport(0.0f, 0.0f, float(outputWidth), float(outputHeight)));
                commandList->setScissors(RenderRect(0, 0, outputWidth, outputHeight));
                commandList->setPipeline(shaderLibrary->bloom.pipeline.get());
                commandList->setGraphicsPipelineLayout(shaderLibrary->bloom.pipelineLayout.get());
                commandList->setGraphicsDescriptorSet(input->get(), 0);
                commandList->setGraphicsPushConstants(0, &bloomConstants);
                commandList->setVertexBuffers(0, nullptr, 0, nullptr);
                commandList->drawInstanced(3, 1, 0, 0);
            };

            const uint32_t eighthWidth = std::max(bloomWidth / 2, 1U);
            const uint32_t eighthHeight = std::max(bloomHeight / 2, 1U);
            GpuSectionScope timed(WorkloadGpuSections(), GpuSection::Bloom, commandList);
            bloomPass(res.sourceSet.get(), source, 0, colorTarget->width, colorTarget->height, 0.0f);
            bloomPass(res.bloomSet[0].get(), res.bloomTexture[0].get(), 1, bloomWidth, bloomHeight, 1.0f);
            bloomPass(res.bloomSet[1].get(), res.bloomTexture[1].get(), 0, bloomWidth, bloomHeight, 2.0f);
            bloomPass(res.bloomSet[0].get(), res.bloomTexture[0].get(), 2, bloomWidth, bloomHeight, 5.0f);
            bloomPass(res.bloomSet[2].get(), res.bloomTexture[2].get(), 3, eighthWidth, eighthHeight, 1.0f);
            bloomPass(res.bloomSet[3].get(), res.bloomTexture[3].get(), 2, eighthWidth, eighthHeight, 2.0f);
            commandList->barriers(RenderBarrierStage::GRAPHICS, RenderTextureBarrier(res.bloomTexture[0].get(), RenderTextureLayout::SHADER_READ));
            bloomPass(res.bloomCombineSet.get(), res.bloomTexture[2].get(), 4, bloomWidth, bloomHeight, 6.0f);
        }

        // The scene at half size for the bounce light and SSGI (BloomPS pass 8).
        if (((settings.bounceLight > 0.0f) || (settings.screenSpaceGI > 0.0f)) && (source != nullptr)) {
            GpuSectionScope timed(WorkloadGpuSections(), GpuSection::Bloom, commandList);
            const uint32_t halfWidth = std::max(colorTarget->width / 2, 1U);
            const uint32_t halfHeight = std::max(colorTarget->height / 2, 1U);
            commandList->barriers(RenderBarrierStage::GRAPHICS, RenderTextureBarrier(res.halfTexture.get(), RenderTextureLayout::COLOR_WRITE));
            interop::BloomCB halfConstants;
            halfConstants.params = { 1.0f / float(colorTarget->width), 1.0f / float(colorTarget->height), 8.0f, 0.0f };
            commandList->setFramebuffer(res.halfFramebuffer.get());
            commandList->setViewports(RenderViewport(0.0f, 0.0f, float(halfWidth), float(halfHeight)));
            commandList->setScissors(RenderRect(0, 0, halfWidth, halfHeight));
            commandList->setPipeline(shaderLibrary->bloom.pipeline.get());
            commandList->setGraphicsPipelineLayout(shaderLibrary->bloom.pipelineLayout.get());
            commandList->setGraphicsDescriptorSet(res.sourceSet->get(), 0);
            commandList->setGraphicsPushConstants(0, &halfConstants);
            commandList->setVertexBuffers(0, nullptr, 0, nullptr);
            commandList->drawInstanced(3, 1, 0, 0);
            commandList->barriers(RenderBarrierStage::GRAPHICS, RenderTextureBarrier(res.halfTexture.get(), RenderTextureLayout::SHADER_READ));
        }

        // Modern water's ripples: the player pushes the water of a grid that follows them (RippleCells cells of
        // RippleCellSize world units), stepped at 120 a second in pairs so it always ends in [0].
        if (res.rippleTexture[0] == nullptr) {
            for (int i = 0; i < 2; i++) {
                res.rippleTexture[i] = worker->device->createTexture(RenderTextureDesc::ColorTarget(RippleCells, RippleCells, RenderFormat::R32G32_FLOAT));
                res.rippleTexture[i]->setName("Scene Effects Water Ripples");
                const RenderTexture *texture = res.rippleTexture[i].get();
                res.rippleFramebuffer[i] = worker->device->createFramebuffer(RenderFramebufferDesc(&texture, 1));
            }
            for (int i = 0; i < 2; i++) {
                res.rippleSet[i] = std::make_unique<SmaaDescriptorSet>(shaderLibrary->samplerLibrary.linear.clampClamp.get(),
                    shaderLibrary->samplerLibrary.nearest.clampClamp.get(), worker->device);
                for (uint32_t slot : { res.rippleSet[i]->gTexture0, res.rippleSet[i]->gTexture1, res.rippleSet[i]->gTexture2 }) {
                    res.rippleSet[i]->setTexture(slot, res.rippleTexture[i].get(), RenderTextureLayout::SHADER_READ);
                }
            }
            for (int i = 0; i < 2; i++) {
                commandList->barriers(RenderBarrierStage::GRAPHICS, RenderTextureBarrier(res.rippleTexture[i].get(), RenderTextureLayout::COLOR_WRITE));
                commandList->setFramebuffer(res.rippleFramebuffer[i].get());
                commandList->clearColor(0, RenderColor(0.0f, 0.0f, 0.0f, 0.0f));
                commandList->barriers(RenderBarrierStage::GRAPHICS, RenderTextureBarrier(res.rippleTexture[i].get(), RenderTextureLayout::SHADER_READ));
            }
            res.rippleLast = std::chrono::steady_clock::now();
        }
        const bool havePlayer = settings.player[1] > -1e8f;
        if (settings.modernWater && havePlayer) {
            const auto now = std::chrono::steady_clock::now();
            const float seconds = std::min(std::chrono::duration<float>(now - res.rippleLast).count(), 0.1f);
            res.rippleLast = now;
            // The grid's corner, whole cells, so the player stays near its middle.
            const int32_t cornerX = int32_t(std::floor(settings.player[0] / RippleCellSize)) - int32_t(RippleCells / 2);
            const int32_t cornerZ = int32_t(std::floor(settings.player[2] / RippleCellSize)) - int32_t(RippleCells / 2);
            int32_t shiftX = res.rippleCornerKnown ? (cornerX - res.rippleCornerX) : 0;
            int32_t shiftZ = res.rippleCornerKnown ? (cornerZ - res.rippleCornerZ) : 0;
            // A jump across the level (a warp) starts calm.
            if ((std::abs(shiftX) > int32_t(RippleCells / 4)) || (std::abs(shiftZ) > int32_t(RippleCells / 4))) {
                shiftX = int32_t(RippleCells);
                shiftZ = int32_t(RippleCells);
            }
            res.rippleCornerX = cornerX;
            res.rippleCornerZ = cornerZ;
            res.rippleCornerKnown = true;

            // How fast the player moves, and whether they just splashed in (the newest ring marked as a splash).
            const float dx = settings.player[0] - res.ripplePlayerX;
            const float dz = settings.player[2] - res.ripplePlayerZ;
            res.ripplePlayerX = settings.player[0];
            res.ripplePlayerZ = settings.player[2];
            const float speed = (seconds > 0.0f) ? std::min(std::sqrt(dx * dx + dz * dz) / seconds, 2000.0f) : 0.0f;
            bool splash = false;
            for (int i = 0; i < 3; i++) {
                const float packed = settings.rippleAge[i];
                if ((packed >= 4.0f) && (packed - 4.0f < 0.3f) &&
                    ((std::abs(settings.rippleX[i] - res.rippleSplashX) > 1.0f) || (std::abs(settings.rippleZ[i] - res.rippleSplashZ) > 1.0f))) {
                    splash = true;
                    res.rippleSplashX = settings.rippleX[i];
                    res.rippleSplashZ = settings.rippleZ[i];
                }
            }

            res.rippleSteps += seconds * 120.0f;
            int steps = int(res.rippleSteps / 2.0f) * 2;
            res.rippleSteps -= float(steps);
            steps = std::min(steps, 12);
            if (steps > 0) {
                GpuSectionScope timed(WorkloadGpuSections(), GpuSection::WaterMask, commandList);
                commandList->setViewports(RenderViewport(0.0f, 0.0f, float(RippleCells), float(RippleCells)));
                commandList->setScissors(RenderRect(0, 0, RippleCells, RippleCells));
                commandList->setPipeline(shaderLibrary->luminance.pipeline.get());
                commandList->setGraphicsPipelineLayout(shaderLibrary->luminance.pipelineLayout.get());
                commandList->setVertexBuffers(0, nullptr, 0, nullptr);
                // A moving player keeps pushing (a wake); one standing still bobs a little.
                const float bob = 0.03f * std::sin(float(std::fmod(std::chrono::duration<double>(now.time_since_epoch()).count(), 1000.0)) * 5.0f);
                const float push = std::min(speed / 250.0f, 1.5f) * 0.3f + bob;
                for (int step = 0; step < steps; step++) {
                    const int from = step & 1;
                    const int to = from ^ 1;
                    commandList->barriers(RenderBarrierStage::GRAPHICS, {
                        RenderTextureBarrier(res.rippleTexture[from].get(), RenderTextureLayout::SHADER_READ),
                        RenderTextureBarrier(res.rippleTexture[to].get(), RenderTextureLayout::COLOR_WRITE)
                    });
                    interop::BloomCB simConstants;
                    simConstants.params = { 1.0f / float(RippleCells), RippleCellSize, 7.0f, 0.0f };
                    simConstants.waterSim = { (step == 0) ? float(shiftX) : 0.0f, (step == 0) ? float(shiftZ) : 0.0f,
                        settings.player[0] / RippleCellSize - float(cornerX), settings.player[2] / RippleCellSize - float(cornerZ) };
                    simConstants.waterPush = { push, 6.0f, (splash && (step == 0)) ? 6.0f : 0.0f, 0.995f };
                    commandList->setFramebuffer(res.rippleFramebuffer[to].get());
                    commandList->setGraphicsDescriptorSet(res.rippleSet[from]->get(), 0);
                    commandList->setGraphicsPushConstants(0, &simConstants);
                    commandList->drawInstanced(3, 1, 0, 0);
                }
                commandList->barriers(RenderBarrierStage::GRAPHICS, {
                    RenderTextureBarrier(res.rippleTexture[0].get(), RenderTextureLayout::SHADER_READ),
                    RenderTextureBarrier(res.rippleTexture[1].get(), RenderTextureLayout::SHADER_READ)
                });
            }
        }

        // The pass's inputs: the depth target, the bloom and the scene so far (the bloom stands in when unused).
        const RenderTexture *color = (source != nullptr) ? source : res.bloomTexture[0].get();
        const RenderTexture *adapted = res.luminanceTexture[1].get();
        // The water mask is always bound; the shader reads it only when it was drawn this frame.
        ensureWaterTarget(worker, res, colorTarget, depthTarget);
        const bool waterDrawn = res.waterDrawn;
        res.waterDrawn = false;
        // Toon shading's character part reads the characters in the water mask, so it is left out when none was drawn.
        if (!waterDrawn && (settings.toonCharacters > 0.0f)) {
            constants.ambientOcclusion.w = std::min(settings.rimLight, 1.0f) + 2.0f * std::round(std::clamp(settings.toonShading, 0.0f, 1.0f) * 100.0f);
        }
        // Modern water draws in place of the game's (water.y 2): its waves are always on, at the Water waves
        // setting or a moderate default, and the old reflections are left out (it reflects by itself).
        const bool modern = waterDrawn && res.waterColorDrawn && settings.modernWater;
        res.waterColorDrawn = false;
        const bool waterTessellated = modern && res.waterTessDrawn;
        res.waterTessDrawn = false;
        RenderTexture *water = res.waterTexture.get();
        RenderTexture *waterColor = res.waterColorTexture.get();
        // water.y 3: Modern water with no water drawn this frame (its caustics under the water still show).
        const bool modernOn = settings.modernWater;
        // water.x: Water reflections plus twice Ice reflections' hundredths (see WaterReflectionStrength in SceneEffectsPS).
        const float waterReflect = (waterDrawn && !modernOn && (settings.waterReflections > 0.0f)) ? std::min(settings.waterReflections, 1.0f) : 0.0f;
        const float iceReflect = waterDrawn ? std::round(std::clamp(settings.iceReflections, 0.0f, 1.0f) * 100.0f) : 0.0f;
        // water.y: a quarter more for Stylised water (2.25 drawn, 3.25 with no water this frame).
        // An eighth more when its surface was tessellated this frame (the mask holds the moving surface itself).
        const float stylised = (settings.stylisedWater ? 0.25f : 0.0f) + (waterTessellated ? 0.125f : 0.0f);
        constants.water = { waterReflect + 2.0f * iceReflect, modern ? 2.0f + stylised : (modernOn ? 3.0f + stylised : (waterDrawn ? (settings.shoreFoam ? 1.25f : 1.0f) : 0.0f)), settings.bounceLight,
            modernOn ? ((settings.waterWaves > 0.0f) ? settings.waterWaves : 0.5f) : (waterDrawn ? settings.waterWaves : 0.0f) };
        if (modernOn) {
            // Modern water reads the ripple grid instead of the rings: its corner in world x and z, its cell size,
            // and 1 when it holds this player's ripples; then how far under water (z), the surface's height (x)
            // and 1 for a whole level under water (y) in rippleAge.
            constants.rippleZ.z = settings.modernUnderwater;
            constants.rippleAge.x = settings.modernSurfaceY;
            constants.rippleAge.y = settings.modernWholeLevel ? 1.0f : 0.0f;
            constants.rippleAge.z = 0.0f;
            constants.rippleX.x = float(res.rippleCornerX) * RippleCellSize;
            constants.rippleZ.x = float(res.rippleCornerZ) * RippleCellSize;
            constants.rippleX.y = RippleCellSize;
            constants.rippleZ.y = float(RippleCells);
            constants.rippleX.z = (res.rippleCornerKnown && havePlayer) ? 1.0f : 0.0f;
            // Tessellated: no grid; the waves' clock, the player's velocity (rippleX.xy) and push (rippleZ.x) as the
            // surface was raised with, so the light follows the same waves (TessellatedSlope).
            if (waterTessellated) {
                const std::scoped_lock lock(waterTessMutex);
                constants.ambientOcclusion.z = waterTessShared.clock;
                constants.rippleX.x = waterTessShared.velocity[0];
                constants.rippleX.y = waterTessShared.velocity[1];
                constants.rippleZ.x = waterTessShared.push;
                constants.rippleX.z = havePlayer ? 1.0f : 0.0f;
            }
        }
        // The fireflies' table, made once and cleared, so the pass can always read it (it does only at night).
        if (res.fireflyTexture == nullptr) {
            res.fireflyTexture = worker->device->createTexture(RenderTextureDesc::ColorTarget(FireflyCount, FireflyTableRows, RenderFormat::R32G32B32A32_FLOAT));
            res.fireflyTexture->setName("Scene Effects Fireflies");
            const RenderTexture *texture = res.fireflyTexture.get();
            res.fireflyFramebuffer = worker->device->createFramebuffer(RenderFramebufferDesc(&texture, 1));
            commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderTextureBarrier(res.fireflyTexture.get(), RenderTextureLayout::COLOR_WRITE) });
            commandList->setFramebuffer(res.fireflyFramebuffer.get());
            commandList->clearColor(0, RenderColor(0.0f, 0.0f, 0.0f, 0.0f));
            commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderTextureBarrier(res.fireflyTexture.get(), RenderTextureLayout::SHADER_READ) });
        }
        // The sun shadow maps, made (again when the Sun shadow distance needs another size) and cleared to nothing in
        // the way of the sun, so the pass can always read them: the near map at x 0, the far map over the whole level
        // beside it. The near map's size follows from shadows.y the way the shaders work it out (SunShadowMap.hlsli).
        const uint32_t sunMapSize = SunShadowMapSize(std::round(settings.sunShadowDistance / SUN_SHADOW_MAP_HALF_STEP) * SUN_SHADOW_MAP_HALF_STEP);
        const uint32_t sunMapWidth = sunMapSize + SUN_SHADOW_MAP_FAR_SIZE;
        const uint32_t sunMapHeight = std::max(sunMapSize, uint32_t(SUN_SHADOW_MAP_FAR_SIZE));
        if ((res.sunMapTexture != nullptr) && (res.sunMapSize != sunMapSize)) {
            res.retireLater(std::move(res.sunMapFramebuffer));
            res.retireLater(std::move(res.sunMapTextureView));
            res.retireLater(std::move(res.sunMapTexture));
        }
        if (res.sunMapTexture == nullptr) {
            RenderClearValue clearValue = RenderClearValue::Depth(RenderDepth(), RenderFormat::D32_FLOAT);
            res.sunMapSize = sunMapSize;
            res.sunFarValid = false;
            res.sunMapTexture = worker->device->createTexture(RenderTextureDesc::DepthTarget(sunMapWidth, sunMapHeight, RenderFormat::D32_FLOAT, RenderMultisampling(), &clearValue));
            res.sunMapTexture->setName("Scene Effects Sun Shadow Map");
            res.sunMapTextureView = res.sunMapTexture->createTextureView(RenderTextureViewDesc::Texture2D(RenderFormat::D32_FLOAT));
            const RenderTexture *noColor = nullptr;
            res.sunMapFramebuffer = worker->device->createFramebuffer(RenderFramebufferDesc(&noColor, 0, res.sunMapTexture.get()));
            commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderTextureBarrier(res.sunMapTexture.get(), RenderTextureLayout::DEPTH_WRITE) });
            commandList->setFramebuffer(res.sunMapFramebuffer.get());
            commandList->clearDepth(true, 1.0f);
            commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderTextureBarrier(res.sunMapTexture.get(), RenderTextureLayout::SHADER_READ) });
        }

        // The 3D world's solid triangles drawn from the sun. The pass works out where the map lies from the same
        // constants as the effects (SunShadowMap.hlsli); a negative reach tells the effects the map is there.
        // Headless test hooks: TOOIE_SUN_MAP_OFF leaves the map out, TOOIE_SUN_MAP_OFF_AFTER=<seconds> from then on.
        static const bool sunMapOff = (getenv("TOOIE_SUN_MAP_OFF") != nullptr);
        static const char *sunMapOffAfter = getenv("TOOIE_SUN_MAP_OFF_AFTER");
        const bool sunMapOffNow = sunMapOff || ((sunMapOffAfter != nullptr) && (std::chrono::duration<float>(std::chrono::steady_clock::now() - sunMapProcessStart).count() > float(atof(sunMapOffAfter))));
        // The traced pass (the structures are built) traces its shadows, so the map isn't drawn for it.
        const bool tracedShadows = res.bvhReady && (shaderLibrary->sceneEffectsTraced.pipeline != nullptr);
        if (drawSunCasters && !sunMapOffNow && !tracedShadows && (constants.shadows.x > 0.0f)) {
            GpuCheckpoint(commandList, GpuSectionMarker(GpuSection::SunShadowMap, false));
            const int sunMapSpan = WorkloadGpuSections().start(GpuSection::SunShadowMap, commandList);
            commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderTextureBarrier(res.sunMapTexture.get(), RenderTextureLayout::DEPTH_WRITE) });
            commandList->setFramebuffer(res.sunMapFramebuffer.get());
            // Whether the far map is drawn again this time (see SunFarRefresh). Headless test hook: TOOIE_SUN_FAR_OFF
            // leaves it out (cleared: nothing casts past the near map); TOOIE_SUN_FAR_EVERY=1 draws it every time, as before.
            static const bool sunFarOff = (getenv("TOOIE_SUN_FAR_OFF") != nullptr);
            static const bool sunFarEvery = (getenv("TOOIE_SUN_FAR_EVERY") != nullptr);
            const float *farSunWorld = settings.customSun ? settings.sunDirection : FixedSun;
            const float cell = SUN_SHADOW_MAP_FAR_CELL;
            const float farMiddle[2] = { std::floor(constants.worldX.w * (1.0f / cell) + 0.5f) * cell, std::floor(constants.worldZ.w * (1.0f / cell) + 0.5f) * cell };
            // For the log: maps drawn, and far maps among them, since the last line.
            static uint32_t mapsDrawn = 0, farMapsDrawn = 0;
            mapsDrawn++;
            bool drawFar = !sunFarOff;
            if (drawFar && !sunFarEvery && res.sunFarValid && (res.sunFarAge + 1 < SunFarRefresh) &&
                (farMiddle[0] == res.sunFarMiddle[0]) && (farMiddle[1] == res.sunFarMiddle[1]))
            {
                double dot = 0.0, a = 0.0, b = 0.0;
                for (int c = 0; c < 3; c++) {
                    dot += double(farSunWorld[c]) * res.sunFarSun[c];
                    a += double(farSunWorld[c]) * farSunWorld[c];
                    b += double(res.sunFarSun[c]) * res.sunFarSun[c];
                }
                drawFar = (dot < SunFarMoveCosine * std::sqrt(a * b));
            }
            if (drawFar || sunFarOff) {
                commandList->clearDepth(true, 1.0f);
            }
            else {
                // The far map is kept: only the near one is cleared.
                const RenderRect nearRect(0, 0, sunMapSize, sunMapSize);
                commandList->clearDepth(true, 1.0f, &nearRect, 1);
            }
            commandList->setViewports(RenderViewport(0.0f, 0.0f, float(sunMapSize), float(sunMapSize)));
            commandList->setScissors(RenderRect(0, 0, sunMapSize, sunMapSize));
            commandList->setPipeline(shaderLibrary->sunShadowMap.pipeline.get());
            commandList->setGraphicsPipelineLayout(shaderLibrary->sunShadowMap.pipelineLayout.get());
            commandList->setGraphicsPushConstants(0, &constants);
            drawSunCasters(commandList);
            // The far map: the same casters, given the far map's half width in shadows.y, beside the near map.
            res.sunFarValid = res.sunFarValid && !sunFarOff;
            res.sunFarAge++;
            if (drawFar) {
                res.sunFarValid = true;
                res.sunFarAge = 0;
                res.sunFarMiddle[0] = farMiddle[0];
                res.sunFarMiddle[1] = farMiddle[1];
                std::copy(farSunWorld, farSunWorld + 3, res.sunFarSun);
                farMapsDrawn++;
                interop::SceneEffectsCB farConstants = constants;
                farConstants.shadows.y = std::min(settings.sunShadowReach, 999.0f) + 1000.0f * std::round(SUN_SHADOW_MAP_FAR_HALF / SUN_SHADOW_MAP_HALF_STEP);
                commandList->setViewports(RenderViewport(float(sunMapSize), 0.0f, float(SUN_SHADOW_MAP_FAR_SIZE), float(SUN_SHADOW_MAP_FAR_SIZE)));
                commandList->setScissors(RenderRect(sunMapSize, 0, sunMapSize + SUN_SHADOW_MAP_FAR_SIZE, SUN_SHADOW_MAP_FAR_SIZE));
                commandList->setGraphicsPushConstants(0, &farConstants);
                drawSunCasters(commandList);
            }
            static const bool mapLog = (getenv("TOOIE_FX_LOG") != nullptr);
            static auto lastMapLog = std::chrono::steady_clock::now();
            if (mapLog && (std::chrono::steady_clock::now() - lastMapLog > std::chrono::milliseconds(1000))) {
                lastMapLog = std::chrono::steady_clock::now();
                fprintf(stderr, "[sunmap] drawn at %.1f s sun %.3f %.3f %.3f distance %.0f size %u, far map drawn %u of %u times\n", std::chrono::duration<float>(std::chrono::steady_clock::now() - sunMapProcessStart).count(), constants.sun.x, constants.sun.y, constants.sun.z, settings.sunShadowDistance, sunMapSize,
                    farMapsDrawn, mapsDrawn);
                farMapsDrawn = 0;
                mapsDrawn = 0;
            }
            commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderTextureBarrier(res.sunMapTexture.get(), RenderTextureLayout::SHADER_READ) });
            WorkloadGpuSections().end(sunMapSpan);
            GpuCheckpoint(commandList, GpuSectionMarker(GpuSection::SunShadowMap, true));
            // Headless test hook: TOOIE_SUN_MAP_VIEW shows only what the map shades (grey outside it).
            static const bool sunMapView = (getenv("TOOIE_SUN_MAP_VIEW") != nullptr);
            constants.shadows.y = -std::abs(constants.shadows.y) - (sunMapView ? SUN_SHADOW_MAP_VIEW_FLAG : 0.0f);
        }
        else {
            // Not drawn this time: the far map may be out of date by the next.
            res.sunFarValid = false;
        }

        // The indirect pass's target, at half size (made again after a resize) and cleared to no occlusion and no
        // light, so the pass can always read it. Three times as tall: the bands below hold the half-size traced sun
        // shadows and light beams, then the lamps' light (Half-resolution ray tracing), which the same pass draws when
        // that is on.
        const uint32_t indirectWidth = std::max(colorTarget->width / 2, 1U);
        const uint32_t indirectHeight = std::max(colorTarget->height / 2, 1U);
        if ((res.indirectTexture != nullptr) && ((res.indirectWidth != indirectWidth) || (res.indirectHeight != indirectHeight))) {
            res.retireLater(std::move(res.indirectFramebuffer));
            res.retireLater(std::move(res.indirectTexture));
        }
        if (res.indirectTexture == nullptr) {
            res.indirectTexture = worker->device->createTexture(RenderTextureDesc::ColorTarget(indirectWidth, indirectHeight * 3, RenderFormat::R16G16B16A16_FLOAT));
            res.indirectTexture->setName("Scene Effects Indirect");
            const RenderTexture *texture = res.indirectTexture.get();
            res.indirectFramebuffer = worker->device->createFramebuffer(RenderFramebufferDesc(&texture, 1));
            res.indirectWidth = indirectWidth;
            res.indirectHeight = indirectHeight;
            commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderTextureBarrier(res.indirectTexture.get(), RenderTextureLayout::COLOR_WRITE) });
            commandList->setFramebuffer(res.indirectFramebuffer.get());
            commandList->clearColor(0, RenderColor(0.0f, 0.0f, 0.0f, 1.0f));
            commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderTextureBarrier(res.indirectTexture.get(), RenderTextureLayout::SHADER_READ) });
        }

        if (res.dustBuffer == nullptr) {
            res.dustBuffer = worker->device->createBuffer(RenderBufferDesc::UploadBuffer(16 * (1 + 2 * SceneMaxDust)));
            res.dustBuffer->setName("Scene Effects dust");
        }
        {
            float *dust = reinterpret_cast<float *>(res.dustBuffer->map());
            memset(dust, 0, 16 * (1 + 2 * SceneMaxDust));
            const std::scoped_lock lock(dustMutex);
            dust[0] = float(dustCount);
            memcpy(dust + 4, dustClouds, size_t(dustCount) * 8 * sizeof(float));
            res.dustBuffer->unmap();
        }

        if ((res.sceneSet == nullptr) || (res.sceneSetIndirect != res.indirectTexture.get()) || (res.sceneSetDepth != depthTarget->texture.get()) || (res.sceneSetBloom != res.bloomTexture[4].get()) ||
            (res.sceneSetColor != color) || (res.sceneSetAdapted != adapted) || (res.sceneSetWater != water) || (res.sceneSetWaterColor != waterColor) ||
            (res.sceneSetRipples != res.rippleTexture[0].get()) || (res.sceneSetBvh != (res.bvhReady ? res.bvhTlas.get() : nullptr)) || (res.sceneSetSunMap != res.sunMapTexture.get()) || (res.sceneSetFireflies != res.fireflyTexture.get()) || (res.sceneSetHalf != res.halfTexture.get())) {
            if (res.sceneSet != nullptr) {
                res.retireLater(std::move(res.sceneSet));
            }
            res.sceneSet = std::make_unique<SceneEffectsDescriptorSet>(shaderLibrary->samplerLibrary.linear.clampClamp.get(), worker->device->getCapabilities().rayQuery, worker->device);
            res.sceneSet->setBuffer(res.sceneSet->gDust, res.dustBuffer.get(), 16 * (1 + 2 * SceneMaxDust));
            res.sceneSet->setTexture(res.sceneSet->gInput, depthTarget->texture.get(), RenderTextureLayout::SHADER_READ, depthTarget->textureView.get());
            res.sceneSet->setTexture(res.sceneSet->gBloom, res.bloomTexture[4].get(), RenderTextureLayout::SHADER_READ);
            res.sceneSetDepth = depthTarget->texture.get();
            res.sceneSet->setTexture(res.sceneSet->gColor, color, RenderTextureLayout::SHADER_READ,
                ((source != nullptr) && colorTarget->usesResolve()) ? colorTarget->getResolvedTextureView() : nullptr);
            res.sceneSetBloom = res.bloomTexture[4].get();
            res.sceneSet->setTexture(res.sceneSet->gAdapted, adapted, RenderTextureLayout::SHADER_READ);
            res.sceneSetColor = color;
            res.sceneSetAdapted = adapted;
            res.sceneSet->setTexture(res.sceneSet->gWater, water, RenderTextureLayout::SHADER_READ, res.waterTextureView.get());
            res.sceneSetWater = water;
            res.sceneSet->setTexture(res.sceneSet->gWaterColor, waterColor, RenderTextureLayout::SHADER_READ, res.waterColorTextureView.get());
            res.sceneSetWaterColor = waterColor;
            res.sceneSet->setTexture(res.sceneSet->gWaterRipples, res.rippleTexture[0].get(), RenderTextureLayout::SHADER_READ);
            res.sceneSetRipples = res.rippleTexture[0].get();
            res.sceneSet->setTexture(res.sceneSet->gSunShadowMap, res.sunMapTexture.get(), RenderTextureLayout::SHADER_READ, res.sunMapTextureView.get());
            res.sceneSetSunMap = res.sunMapTexture.get();
            res.sceneSet->setTexture(res.sceneSet->gFireflies, res.fireflyTexture.get(), RenderTextureLayout::SHADER_READ);
            res.sceneSetFireflies = res.fireflyTexture.get();
            res.sceneSet->setTexture(res.sceneSet->gColorHalf, res.halfTexture.get(), RenderTextureLayout::SHADER_READ);
            res.sceneSetHalf = res.halfTexture.get();
            res.sceneSet->setTexture(res.sceneSet->gIndirect, res.indirectTexture.get(), RenderTextureLayout::SHADER_READ);
            res.sceneSetIndirect = res.indirectTexture.get();
            res.sceneSetBvh = nullptr;
            if (worker->device->getCapabilities().rayQuery && res.bvhReady) {
                res.sceneSet->setAccelerationStructure(res.sceneSet->gSceneBVH, res.bvhTlas.get());
                res.sceneSet->setBuffer(res.sceneSet->gLights, res.lightsBuffer.get(), 16 * (SceneMaxLights + 4));
                res.sceneSet->setBuffer(res.sceneSet->gRadianceCache, res.radianceBuffer.get(), 8ull << 20);
                res.sceneSetBvh = res.bvhTlas.get();
            }
        }

        GpuCheckpoint(commandList, GpuSectionMarker(GpuSection::SceneEffects, false));
        const int effectsSpan = WorkloadGpuSections().start(GpuSection::SceneEffects, commandList);

        colorTarget->setupColorFramebuffer(worker);
        commandList->barriers(RenderBarrierStage::GRAPHICS, {
            RenderTextureBarrier(colorTarget->texture.get(), RenderTextureLayout::COLOR_WRITE),
            RenderTextureBarrier(depthTarget->texture.get(), RenderTextureLayout::SHADER_READ),
            RenderTextureBarrier(res.bloomTexture[4].get(), RenderTextureLayout::SHADER_READ),
            RenderTextureBarrier(water, RenderTextureLayout::SHADER_READ),
            RenderTextureBarrier(waterColor, RenderTextureLayout::SHADER_READ)
        });

        // The frame's table: the same constants and inputs as the pass itself. One pixel a firefly (and a second
        // row for their brightness), then the depth of field's focus distance, each the same for every pixel of the
        // pass, so worked out once here. Only when something in it is on; the pass otherwise never reads it.
        if ((settings.timeOfDay && settings.dayFireflies) || (settings.depthOfField > 0.0f)) {
            commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderTextureBarrier(res.fireflyTexture.get(), RenderTextureLayout::COLOR_WRITE) });
            commandList->setFramebuffer(res.fireflyFramebuffer.get());
            commandList->setViewports(RenderViewport(0.0f, 0.0f, float(FireflyCount), float(FireflyTableRows)));
            commandList->setScissors(RenderRect(0, 0, FireflyCount, FireflyTableRows));
            commandList->setPipeline(shaderLibrary->fireflyTable.pipeline.get());
            commandList->setGraphicsPipelineLayout(shaderLibrary->sceneEffects.pipelineLayout.get());
            commandList->setGraphicsDescriptorSet(res.sceneSet->get(), 0);
            commandList->setGraphicsPushConstants(0, &constants);
            commandList->setVertexBuffers(0, nullptr, 0, nullptr);
            commandList->drawInstanced(3, 1, 0, 0);
            commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderTextureBarrier(res.fireflyTexture.get(), RenderTextureLayout::SHADER_READ) });
        }

        // The radiance cache is written by the passes below (the effects) and read by them (the indirect pass and the next
        // frame's): its writes from the last pass are made visible first.
        if ((res.sceneSetBvh != nullptr) && (res.radianceBuffer != nullptr) && rayTracingHitColours.load()) {
            commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderBufferBarrier(res.radianceBuffer.get(), RenderBufferAccess::READ | RenderBufferAccess::WRITE) });
        }

        // The firefly table is timed with the effects (left out when not drawn); the indirect pass and the main
        // pass each on their own.
        if (!((settings.timeOfDay && settings.dayFireflies) || (settings.depthOfField > 0.0f))) {
            WorkloadGpuSections().drop(effectsSpan);
        }
        WorkloadGpuSections().end(effectsSpan);

        // The indirect pass: GTAO and SSGI at half size, with the same constants and inputs as the pass, which
        // gathers them. Only when one of them is on (SSGI only while the pass draws the scene, as it reads it), or
        // for Half-resolution ray tracing: its lower half, the traced sun shadows and light beams for the pass to read.
        const bool tracedIndirect = res.bvhReady && (shaderLibrary->sceneIndirectTraced.pipeline != nullptr) && (res.sceneSetBvh != nullptr) &&
            (res.rayTexturesSet != nullptr) && (res.rayTextureCacheSet != nullptr);
        const bool tracedHalf = tracedIndirect && rayTracingHalf.load();
        // The traced light beams are a soft haze: below Ray tracing resolution High they come from the indirect pass's
        // second band at half size too (a quarter of their rays), whatever the shadows do (SceneEffectsPS BeamsHalf).
        const bool tracedBeamsHalf = tracedIndirect && (tracedBeams[0] > 0.0f) && (rayTracingResolution.load() < 2u);
        if ((((settings.ambientOcclusion > 0.0f) || ((settings.screenSpaceGI > 0.0f) && (source != nullptr))) && ((settings.view < 2) || (settings.view == SceneEffectsViewGtao) || (settings.view == SceneEffectsViewSsgi))) || tracedHalf || tracedBeamsHalf) {
            commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderTextureBarrier(res.indirectTexture.get(), RenderTextureLayout::COLOR_WRITE) });
            commandList->setFramebuffer(res.indirectFramebuffer.get());
            GpuSectionScope timedIndirect(WorkloadGpuSections(), GpuSection::IndirectLight, commandList);
            const uint32_t drawnHeight = tracedHalf ? indirectHeight * 3 : (tracedBeamsHalf ? indirectHeight * 2 : indirectHeight);
            commandList->setViewports(RenderViewport(0.0f, 0.0f, float(indirectWidth), float(drawnHeight)));
            commandList->setScissors(RenderRect(0, 0, indirectWidth, drawnHeight));
            // The traced form reads the rays' textures too (cut-outs let the sun through their holes), so it takes the
            // traced pass's layout and sets.
            commandList->setPipeline(tracedIndirect ? shaderLibrary->sceneIndirectTraced.pipeline.get() : shaderLibrary->sceneIndirect.pipeline.get());
            commandList->setGraphicsPipelineLayout(tracedIndirect ? shaderLibrary->sceneEffectsTraced.pipelineLayout.get() : shaderLibrary->sceneEffects.pipelineLayout.get());
            commandList->setGraphicsDescriptorSet(res.sceneSet->get(), 0);
            if (tracedIndirect) {
                commandList->setGraphicsDescriptorSet(res.rayTexturesSet->get(), 1);
                commandList->setGraphicsDescriptorSet(res.rayTextureCacheSet, 2);
            }
            commandList->setGraphicsPushConstants(0, &constants);
            commandList->setVertexBuffers(0, nullptr, 0, nullptr);
            commandList->drawInstanced(3, 1, 0, 0);
            commandList->barriers(RenderBarrierStage::GRAPHICS, { RenderTextureBarrier(res.indirectTexture.get(), RenderTextureLayout::SHADER_READ) });
        }

        commandList->setFramebuffer(colorTarget->textureFramebuffer.get());
        commandList->setViewports(RenderViewport(0.0f, 0.0f, float(colorTarget->width), float(colorTarget->height)));
        // Only over the 3D world's area: outside it (a cutscene's letterbox bars) there is no depth, so the
        // sky's share of the fog would turn the black bars grey.
        RenderRect effectsArea(0, 0, int32_t(colorTarget->width), int32_t(colorTarget->height));
        if (!area.isEmpty()) {
            effectsArea.left = std::max(effectsArea.left, area.left);
            effectsArea.top = std::max(effectsArea.top, area.top);
            effectsArea.right = std::min(effectsArea.right, area.right);
            effectsArea.bottom = std::min(effectsArea.bottom, area.bottom);
        }
        commandList->setScissors(effectsArea);
        // Traced reflections while this frame's structure is built (BuildSceneBVH), else the depth march.
        const bool traced = res.bvhReady && (shaderLibrary->sceneEffectsTraced.pipeline != nullptr) && (res.sceneSetBvh != nullptr) &&
            (res.rayTexturesSet != nullptr) && (res.rayTextureCacheSet != nullptr);
        {
            static const bool tracedLog = (getenv("TOOIE_RT_LOG") != nullptr);
            static int lastTraced = -1;
            if (tracedLog && (lastTraced != int(traced))) {
                lastTraced = int(traced);
                fprintf(stderr, "[rt] scene effects pass %s\n", traced ? "traced (ray queries)" : "depth march");
            }
        }
        // Timed as the traced effects while the pass traces (reflections, shadows, light beams, path tracing).
        const int mainSpan = WorkloadGpuSections().start(traced ? GpuSection::TracedEffects : GpuSection::SceneEffects, commandList);
        commandList->setPipeline(traced ? shaderLibrary->sceneEffectsTraced.pipeline.get() : shaderLibrary->sceneEffects.pipeline.get());
        commandList->setGraphicsPipelineLayout(traced ? shaderLibrary->sceneEffectsTraced.pipelineLayout.get() : shaderLibrary->sceneEffects.pipelineLayout.get());
        commandList->setGraphicsDescriptorSet(res.sceneSet->get(), 0);
        if (traced) {
            commandList->setGraphicsDescriptorSet(res.rayTexturesSet->get(), 1);
            commandList->setGraphicsDescriptorSet(res.rayTextureCacheSet, 2);
        }
        commandList->setGraphicsPushConstants(0, &constants);
        commandList->setVertexBuffers(0, nullptr, 0, nullptr);
        commandList->drawInstanced(3, 1, 0, 0);
        WorkloadGpuSections().end(mainSpan);
        GpuCheckpoint(commandList, GpuSectionMarker(GpuSection::SceneEffects, true));

        commandList->barriers(RenderBarrierStage::GRAPHICS, {
            RenderTextureBarrier(depthTarget->texture.get(), RenderTextureLayout::DEPTH_WRITE)
        });

        // The HUD drawn next changes the picture again, so the target needs resolving again for display.
        colorTarget->markForResolve();
    }
};
