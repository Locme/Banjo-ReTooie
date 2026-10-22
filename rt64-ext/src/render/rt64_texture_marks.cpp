//
// RT64
//

#include "rt64_texture_marks.h"

#include <atomic>
#include <mutex>
#include <unordered_map>
#include <unordered_set>

namespace RT64 {
    namespace {
        // Each list is swapped in whole; the flags skip the lock while a list is empty (most of the time).
        std::mutex glowMutex;
        std::unordered_set<uint64_t> glowTextures;
        std::atomic<bool> glowAny{ false };
        std::mutex lightSourceMutex;
        std::unordered_map<uint64_t, float> lightSourceReaches;
        std::atomic<bool> lightSourceAny{ false };
        std::mutex rayOffMutex;
        std::unordered_set<uint64_t> rayOffTextures;
        std::atomic<bool> rayOffAny{ false };
        std::mutex markedMutex;
        std::unordered_set<uint64_t> markedTextures;
        std::atomic<bool> markedAny{ false };
    }

    void SetSceneGlowTextures(const uint64_t *hashes, size_t count) {
        std::unordered_set<uint64_t> textures(hashes, hashes + count);
        const std::scoped_lock lock(glowMutex);
        glowTextures.swap(textures);
        glowAny.store(!glowTextures.empty());
    }

    bool SceneGlowTexture(uint64_t hash) {
        if (!glowAny.load()) {
            return false;
        }
        const std::scoped_lock lock(glowMutex);
        return glowTextures.count(hash) != 0;
    }

    void SetSceneLightSourceTextures(const uint64_t *hashes, const float *reaches, size_t count) {
        std::unordered_map<uint64_t, float> sources;
        for (size_t i = 0; i < count; i++) {
            sources[hashes[i]] = reaches[i];
        }
        const std::scoped_lock lock(lightSourceMutex);
        lightSourceReaches.swap(sources);
        lightSourceAny.store(!lightSourceReaches.empty());
    }

    float SceneLightSourceReach(uint64_t hash) {
        if (!lightSourceAny.load()) {
            return 0.0f;
        }
        const std::scoped_lock lock(lightSourceMutex);
        const auto it = lightSourceReaches.find(hash);
        return (it != lightSourceReaches.end()) ? it->second : 0.0f;
    }

    void SetSceneRayOffTextures(const uint64_t *hashes, size_t count) {
        std::unordered_set<uint64_t> textures(hashes, hashes + count);
        const std::scoped_lock lock(rayOffMutex);
        rayOffTextures.swap(textures);
        rayOffAny.store(!rayOffTextures.empty());
    }

    bool SceneRayOffTexture(uint64_t hash) {
        if (!rayOffAny.load()) {
            return false;
        }
        const std::scoped_lock lock(rayOffMutex);
        return rayOffTextures.count(hash) != 0;
    }

    void SetScenePickMarkedTextures(const uint64_t *hashes, size_t count) {
        std::unordered_set<uint64_t> textures(hashes, hashes + count);
        const std::scoped_lock lock(markedMutex);
        markedTextures.swap(textures);
        markedAny.store(!markedTextures.empty());
    }

    bool ScenePickMarkedTexture(uint64_t hash) {
        if (!markedAny.load()) {
            return false;
        }
        const std::scoped_lock lock(markedMutex);
        return markedTextures.count(hash) != 0;
    }
}
