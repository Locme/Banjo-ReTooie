//
// RT64
//
// Banjo-Tooie: the texture cache's additions that are whole functions of their own: parallax height maps in
// the texture map (setHeight, useHeight), live texture upscaling (recordUpscale, refreshUpscaled) and the parallax
// height maps baked as textures load (refreshHeights). rt64_texture_cache.cpp (lib-patches/rt64.patch) calls them.

#include <cstring>

#include "rt64_texture_cache.h"
#include "rt64_scene_effects.h"

namespace RT64 {
    // Same as rt64_texture_cache.cpp's.
    static const interop::float2 IdentityScale = { 1.0f, 1.0f };
    static const uint32_t TextureUpscaleMaxSize = 4096;

    void TextureMap::setHeight(uint64_t hash, uint64_t creationFrame, Texture *texture) {
        const uint64_t heightHash = hash ^ HeightHashSalt;
        const auto it = hashMap.find(heightHash);
        if (it == hashMap.end()) {
            add(heightHash, creationFrame, texture);
        }
        else {
            // One from a texture pack used before: freed as an evicted texture is.
            evictedTextures.emplace_back(textures[it->second]);
            textures[it->second] = texture;
            cachedTextureDimensions[it->second] = interop::float3(float(texture->width), float(texture->height), 1.0f);
            versions[it->second]++;
            globalVersion++;
        }

        heightBases.insert(hash);
    }

    bool TextureMap::useHeight(uint64_t hash, uint64_t submissionFrame, uint32_t &textureIndex, interop::float2 &textureDimensions) {
        if (heightBases.find(hash) == heightBases.end()) {
            return false;
        }

        // A texture pack's height map goes with its textures; a baked one (refreshHeights) stays with the game's own.
        if (!replacementMapEnabled && (bakedHeights.find(hash) == bakedHeights.end())) {
            return false;
        }

        interop::float2 textureScale;
        interop::float3 dimensions;
        bool textureReplaced = false;
        bool hasMipmaps = false;
        bool shiftedByHalf = false;
        if (!use(hash ^ HeightHashSalt, submissionFrame, textureIndex, textureScale, dimensions, textureReplaced, hasMipmaps, shiftedByHalf)) {
            return false;
        }

        textureDimensions = interop::float2(dimensions.x, dimensions.y);
        return true;
    }

    bool TextureCache::recordUpscale(RenderCommandList *commandList, Texture *texture, uint32_t factor) {
        if ((texture->texture == nullptr) || (texture->width == 0) || (texture->height == 0) || ((texture->width * factor) > TextureUpscaleMaxSize) || ((texture->height * factor) > TextureUpscaleMaxSize)) {
            return false;
        }

        const ShaderRecord &textureUpscale = shaderLibrary->textureUpscale;
        commandList->setPipeline(textureUpscale.pipeline.get());
        commandList->setComputePipelineLayout(textureUpscale.pipelineLayout.get());

        // Each pass doubles the size: once for 2x, twice for 4x (through a half-way texture).
        RenderTexture *input = texture->texture.get();
        uint32_t width = texture->width;
        uint32_t height = texture->height;
        std::unique_ptr<Texture> upscaled = std::make_unique<Texture>();
        for (uint32_t scale = 2; scale <= factor; scale *= 2) {
            const bool lastPass = (scale * 2) > factor;
            std::unique_ptr<RenderTexture> output = directWorker->device->createTexture(RenderTextureDesc::Texture2D(width * 2, height * 2, 1, RenderFormat::R8G8B8A8_UNORM, RenderTextureFlag::STORAGE | RenderTextureFlag::UNORDERED_ACCESS));
            output->setName("Texture Cache Upscaled");
            if (upscaleDescriptorsUsed >= upscaleDescriptorSets.size()) {
                upscaleDescriptorSets.emplace_back(std::make_unique<TextureUpscaleDescriptorSet>(directWorker->device));
            }

            TextureUpscaleDescriptorSet *descSet = upscaleDescriptorSets[upscaleDescriptorsUsed++].get();
            descSet->setTexture(descSet->gInput, input, RenderTextureLayout::SHADER_READ);
            descSet->setTexture(descSet->gOutput, output.get(), RenderTextureLayout::GENERAL);
            commandList->barriers(RenderBarrierStage::COMPUTE, RenderTextureBarrier(output.get(), RenderTextureLayout::GENERAL));

            const uint32_t upscaleCB[4] = { width, height, 0, 0 };
            const uint32_t ThreadGroupSize = 8;
            commandList->setComputePushConstants(0, upscaleCB);
            commandList->setComputeDescriptorSet(descSet->get(), 0);
            commandList->dispatch((width * 2 + ThreadGroupSize - 1) / ThreadGroupSize, (height * 2 + ThreadGroupSize - 1) / ThreadGroupSize, 1);
            commandList->barriers(RenderBarrierStage::GRAPHICS_AND_COMPUTE, RenderTextureBarrier(output.get(), RenderTextureLayout::SHADER_READ));

            width *= 2;
            height *= 2;
            input = output.get();
            if (lastPass) {
                upscaled->texture = std::move(output);
            }
            else {
                upscaleSteps.emplace_back(std::move(output));
            }
        }

        upscaled->creationFrame = texture->creationFrame;
        upscaled->format = RenderFormat::R8G8B8A8_UNORM;
        upscaled->width = width;
        upscaled->height = height;
        upscaled->mipmaps = 1;
        upscaled->memorySize = uint64_t(width) * height * 4;
        texture->upscaled = std::move(upscaled);
        return true;
    }

    void TextureCache::refreshUpscaled(uint32_t factor) {
        std::unique_lock lock(textureMapMutex);

        // Take off the upscales made with the old setting. Frames in flight may still use them, so they're
        // freed with the evicted textures.
        for (size_t i = 0; i < textureMap.textures.size(); i++) {
            Texture *texture = textureMap.textures[i];
            if ((texture == nullptr) || (texture->upscaled == nullptr)) {
                continue;
            }

            if (textureMap.textureReplacements[i] == texture->upscaled.get()) {
                textureMap.textureReplacements[i] = nullptr;
                textureMap.textureReplacementShiftedByHalf[i] = false;
                textureMap.textureReplacementReferenceCounted[i] = false;
                textureMap.textureScales[i] = IdentityScale;
                textureMap.versions[i]++;
            }

            textureMap.evictedTextures.emplace_back(texture->upscaled.release());
        }

        textureMap.globalVersion++;
        if (factor <= 1) {
            return;
        }

        // Upscale every decoded texture that nothing else replaces.
        std::vector<uint32_t> upscaledIndices;
        directWorker->commandList->begin();
        upscaleDescriptorsUsed = 0;
        for (size_t i = 0; i < textureMap.textures.size(); i++) {
            Texture *texture = textureMap.textures[i];
            if ((texture != nullptr) && texture->decodeTMEM && (textureMap.textureReplacements[i] == nullptr) && recordUpscale(directWorker->commandList.get(), texture, factor)) {
                upscaledIndices.emplace_back(uint32_t(i));
            }
        }

        directWorker->commandList->end();
        const RenderCommandList *directCommandList = directWorker->commandList.get();
        directWorker->commandQueue->executeCommandLists(&directCommandList, 1, nullptr, 0, nullptr, 0, directWorker->commandFence.get());
        directWorker->wait();
        upscaleSteps.clear();

        for (uint32_t i : upscaledIndices) {
            textureMap.replace(textureMap.hashes[i], textureMap.textures[i]->upscaled.get(), false, false);
        }
    }

    // Height maps no bigger than this across (a texture pack's 4K texture gives one a quarter of its size), and no more
    // than this many baked a call, so a changed setting doesn't hold the texture map for long.
    static const uint32_t HeightBakeMaxSize = 1024;
    static const size_t HeightBakeBatch = 32;

    bool TextureCache::refreshHeights() {
        if (!SceneHeightBakeWanted()) {
            return false;
        }

        const uint32_t generation = SceneHeightBakeGeneration();
        std::unique_lock lock(textureMapMutex);
        if ((generation == heightBakeGeneration) && (textureMap.globalVersion == heightBakeMapVersion)) {
            return false;
        }

        // A baked height map that is gone (evicted, or the texture packs changed) is baked again; the record of a texture
        // that is gone is dropped.
        for (auto it = textureMap.bakedHeights.begin(); it != textureMap.bakedHeights.end();) {
            if (textureMap.heightBases.find(*it) == textureMap.heightBases.end()) {
                it = textureMap.bakedHeights.erase(it);
            }
            else {
                it++;
            }
        }

        for (auto it = textureMap.heightBakes.begin(); it != textureMap.heightBakes.end();) {
            if (textureMap.hashMap.find(it->first) == textureMap.hashMap.end()) {
                textureMap.bakedHeights.erase(it->first);
                it = textureMap.heightBakes.erase(it);
            }
            else {
                it++;
            }
        }

        struct Job {
            uint64_t hash;
            Texture *source;
            Texture *base;
            uint32_t bits;
            bool ownRange;
        };

        std::vector<Job> jobs;
        bool more = false;
        for (size_t i = 0; i < textureMap.textures.size(); i++) {
            Texture *base = textureMap.textures[i];
            if (base == nullptr) {
                continue;
            }

            // Not a height map itself, in the parallax list, and with no height map from a texture pack.
            const uint64_t hash = textureMap.hashes[i];
            if (textureMap.heightBases.find(hash ^ TextureMap::HeightHashSalt) != textureMap.heightBases.end()) {
                continue;
            }

            const uint32_t bits = SceneParallaxTexture(hash);
            if (bits == 0) {
                continue;
            }

            const bool baked = textureMap.bakedHeights.find(hash) != textureMap.bakedHeights.end();
            if (!baked && (textureMap.heightBases.find(hash) != textureMap.heightBases.end())) {
                continue;
            }

            // From the texture that is drawn: a texture pack's or the upscale (the replacement), or the game's own. One the
            // shaders read from TMEM has no decoded texture to bake from, and keeps working its height out as it draws.
            Texture *source = (textureMap.replacementMapEnabled && (textureMap.textureReplacements[i] != nullptr)) ? textureMap.textureReplacements[i] : base;
            if ((source->texture == nullptr) || (source->width == 0) || (source->height == 0) || (base->width == 0)) {
                continue;
            }

            const auto state = textureMap.heightBakes.find(hash);
            if (baked && (state != textureMap.heightBakes.end()) && (state->second.source == source) && (state->second.generation == generation)) {
                continue;
            }

            if (jobs.size() >= HeightBakeBatch) {
                more = true;
                break;
            }

            // A texture pack's own range: it can be brighter or darker than the game's texture the list's range is for.
            const bool ownRange = (source != base) && (source != base->upscaled.get());
            jobs.push_back({ hash, source, base, bits, ownRange });
        }

        if (!jobs.empty()) {
            const ShaderRecord &heightBake = shaderLibrary->heightBake;
            RenderDevice *device = directWorker->device;
            RenderCommandList *commandList = directWorker->commandList.get();
            const RenderTextureFlags storage = RenderTextureFlag::STORAGE | RenderTextureFlag::UNORDERED_ACCESS;
            const float smoothness = SceneParallaxSmoothness();
            std::vector<std::unique_ptr<Texture>> heights;
            commandList->begin();
            commandList->setPipeline(heightBake.pipeline.get());
            commandList->setComputePipelineLayout(heightBake.pipelineLayout.get());
            for (size_t j = 0; j < jobs.size(); j++) {
                const Job &job = jobs[j];
                const uint32_t step = std::max((std::max(job.source->width, job.source->height) + HeightBakeMaxSize - 1) / HeightBakeMaxSize, 1U);
                const uint32_t width = std::max(job.source->width / step, 1U);
                const uint32_t height = std::max(job.source->height / step, 1U);
                std::unique_ptr<RenderTexture> luma = device->createTexture(RenderTextureDesc::Texture2D(width, height, 1, RenderFormat::R32_FLOAT, storage));
                std::unique_ptr<RenderTexture> blur = device->createTexture(RenderTextureDesc::Texture2D(width, height, 1, RenderFormat::R32_FLOAT, storage));
                std::unique_ptr<RenderTexture> histogram = device->createTexture(RenderTextureDesc::Texture2D(260, 1, 1, RenderFormat::R32_UINT, storage));
                std::unique_ptr<Texture> heightMap = std::make_unique<Texture>();
                heightMap->texture = device->createTexture(RenderTextureDesc::Texture2D(width, height, 1, RenderFormat::R8_UNORM, storage));
                heightMap->texture->setName("Texture Cache Baked Height");
                heightMap->creationFrame = job.base->creationFrame;
                heightMap->format = RenderFormat::R8_UNORM;
                heightMap->width = width;
                heightMap->height = height;
                heightMap->mipmaps = 1;
                heightMap->memorySize = uint64_t(width) * height;

                if (j >= heightBakeDescriptorSets.size()) {
                    heightBakeDescriptorSets.emplace_back(std::make_unique<HeightBakeDescriptorSet>(device));
                }

                HeightBakeDescriptorSet *descSet = heightBakeDescriptorSets[j].get();
                descSet->setTexture(descSet->gSource, job.source->texture.get(), RenderTextureLayout::SHADER_READ);
                descSet->setTexture(descSet->gLuma, luma.get(), RenderTextureLayout::GENERAL);
                descSet->setTexture(descSet->gBlur, blur.get(), RenderTextureLayout::GENERAL);
                descSet->setTexture(descSet->gHeight, heightMap->texture.get(), RenderTextureLayout::GENERAL);
                descSet->setTexture(descSet->gHistogram, histogram.get(), RenderTextureLayout::GENERAL);
                const RenderTextureBarrier general[] = {
                    RenderTextureBarrier(luma.get(), RenderTextureLayout::GENERAL),
                    RenderTextureBarrier(blur.get(), RenderTextureLayout::GENERAL),
                    RenderTextureBarrier(histogram.get(), RenderTextureLayout::GENERAL),
                    RenderTextureBarrier(heightMap->texture.get(), RenderTextureLayout::GENERAL),
                };
                commandList->barriers(RenderBarrierStage::COMPUTE, general, uint32_t(std::size(general)));
                commandList->setComputeDescriptorSet(descSet->get(), 0);

                // The shape (as RASTER_PARALLAX_SHAPE_* from the list's bits, SetSceneParallaxTextures) and the blur: up to two
                // of the game's texels with Parallax smoothness, and at least a little for Sand, Smooth and Ice, whose shapes
                // were always worked out from a blurred brightness.
                const uint32_t shape = ((job.bits >> 17) & 0x7u) | (((job.bits >> 24) & 0x1u) << 3) | (((job.bits >> 20) & 0x1u) << 4);
                float sigma = smoothness * 2.0f;
                if (shape >= 14u) {
                    sigma = std::max(sigma, 0.6f);
                }

                sigma *= float(width) / float(job.base->width);
                uint32_t sigmaBits;
                memcpy(&sigmaBits, &sigma, sizeof(sigmaBits));
                const uint32_t range = (job.bits & 0xFFFFu) | (job.ownRange ? 0x10000u : 0u);
                const uint32_t groupsX = (width + 7) / 8;
                const uint32_t groupsY = (height + 7) / 8;
                for (uint32_t pass = 0; pass <= 4; pass++) {
                    const uint32_t constants[8] = { job.source->width, job.source->height, width, height, pass, shape, range, sigmaBits };
                    commandList->setComputePushConstants(0, constants);
                    if (pass == 0) {
                        commandList->dispatch(33, 1, 1);
                    }
                    else if (pass == 2) {
                        commandList->dispatch(1, 1, 1);
                    }
                    else {
                        commandList->dispatch(groupsX, groupsY, 1);
                    }

                    // Each pass reads what the one before it wrote.
                    commandList->barriers(RenderBarrierStage::COMPUTE, general, uint32_t(std::size(general)));
                }

                commandList->barriers(RenderBarrierStage::GRAPHICS_AND_COMPUTE, RenderTextureBarrier(heightMap->texture.get(), RenderTextureLayout::SHADER_READ));
                heightBakeScratch.emplace_back(std::move(luma));
                heightBakeScratch.emplace_back(std::move(blur));
                heightBakeScratch.emplace_back(std::move(histogram));
                heights.emplace_back(std::move(heightMap));
            }

            commandList->end();
            const RenderCommandList *directCommandList = commandList;
            directWorker->commandQueue->executeCommandLists(&directCommandList, 1, nullptr, 0, nullptr, 0, directWorker->commandFence.get());
            directWorker->wait();
            heightBakeScratch.clear();

            for (size_t j = 0; j < jobs.size(); j++) {
                const Job &job = jobs[j];
                textureMap.setHeight(job.hash, job.base->creationFrame, heights[j].release());
                textureMap.bakedHeights.insert(job.hash);
                textureMap.heightBakes[job.hash] = { job.source, generation };
            }

            fprintf(stdout, "[parallax] baked %zu height maps%s\n", jobs.size(), more ? ", more to come" : "");
        }

        // Done until the settings or the textures change (a texture loaded, replaced or evicted).
        if (!more) {
            heightBakeGeneration = generation;
            heightBakeMapVersion = textureMap.globalVersion;
        }

        return more;
    }
}
