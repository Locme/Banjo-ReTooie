//
// RT64
//
// Banjo-Tooie: the texture cache's additions that are whole functions of their own: parallax height maps in
// the texture map (setHeight, useHeight) and live texture upscaling (recordUpscale, refreshUpscaled).
// rt64_texture_cache.cpp (lib-patches/rt64.patch) calls them.

#include "rt64_texture_cache.h"

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
        if (!replacementMapEnabled || (heightBases.find(hash) == heightBases.end())) {
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
}
