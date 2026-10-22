//
// RT64
//

#include "rt64_texture_marks.h"

#include <algorithm>
#include <atomic>
#include <cmath>
#include <cstdint>
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

        // Bumped (under the list's lock) whenever a list is swapped. The render thread keeps its own copy of each list
        // and only takes the lock to copy it again after a change: a lock for every draw's lookup showed in the
        // renderer's CPU time.
        std::atomic<uint64_t> glowVersion{ 0 }, lightSourceVersion{ 0 }, rayOffVersion{ 0 }, markedVersion{ 0 };

        template<typename T>
        const T &cachedCopy(std::mutex &mutex, const T &shared, const std::atomic<uint64_t> &version, T &cache, uint64_t &cacheVersion) {
            if (version.load(std::memory_order_acquire) != cacheVersion) {
                const std::scoped_lock lock(mutex);
                cache = shared;
                cacheVersion = version.load(std::memory_order_relaxed);
            }
            return cache;
        }
    }

    void SetSceneGlowTextures(const uint64_t *hashes, size_t count) {
        std::unordered_set<uint64_t> textures(hashes, hashes + count);
        const std::scoped_lock lock(glowMutex);
        glowTextures.swap(textures);
        glowAny.store(!glowTextures.empty());
        glowVersion.fetch_add(1, std::memory_order_release);
    }

    bool SceneGlowTexture(uint64_t hash) {
        if (!glowAny.load()) {
            return false;
        }
        thread_local std::unordered_set<uint64_t> cache;
        thread_local uint64_t cacheVersion = UINT64_MAX;
        return cachedCopy(glowMutex, glowTextures, glowVersion, cache, cacheVersion).count(hash) != 0;
    }

    void SetSceneLightSourceTextures(const uint64_t *hashes, const float *reaches, size_t count) {
        std::unordered_map<uint64_t, float> sources;
        for (size_t i = 0; i < count; i++) {
            sources[hashes[i]] = reaches[i];
        }
        const std::scoped_lock lock(lightSourceMutex);
        lightSourceReaches.swap(sources);
        lightSourceAny.store(!lightSourceReaches.empty());
        lightSourceVersion.fetch_add(1, std::memory_order_release);
    }

    float SceneLightSourceReach(uint64_t hash) {
        if (!lightSourceAny.load()) {
            return 0.0f;
        }
        thread_local std::unordered_map<uint64_t, float> cache;
        thread_local uint64_t cacheVersion = UINT64_MAX;
        const auto &reaches = cachedCopy(lightSourceMutex, lightSourceReaches, lightSourceVersion, cache, cacheVersion);
        const auto it = reaches.find(hash);
        return (it != reaches.end()) ? it->second : 0.0f;
    }

    float SceneLightSourceW(float reach, float radius) {
        return std::floor(reach) + 0.05f + 0.9f * (std::clamp(radius, 0.0f, 1000.0f) / 1000.0f);
    }

    void SetSceneRayOffTextures(const uint64_t *hashes, size_t count) {
        std::unordered_set<uint64_t> textures(hashes, hashes + count);
        const std::scoped_lock lock(rayOffMutex);
        rayOffTextures.swap(textures);
        rayOffAny.store(!rayOffTextures.empty());
        rayOffVersion.fetch_add(1, std::memory_order_release);
    }

    bool SceneRayOffTexture(uint64_t hash) {
        if (!rayOffAny.load()) {
            return false;
        }
        thread_local std::unordered_set<uint64_t> cache;
        thread_local uint64_t cacheVersion = UINT64_MAX;
        return cachedCopy(rayOffMutex, rayOffTextures, rayOffVersion, cache, cacheVersion).count(hash) != 0;
    }

    void SetScenePickMarkedTextures(const uint64_t *hashes, size_t count) {
        std::unordered_set<uint64_t> textures(hashes, hashes + count);
        const std::scoped_lock lock(markedMutex);
        markedTextures.swap(textures);
        markedAny.store(!markedTextures.empty());
        markedVersion.fetch_add(1, std::memory_order_release);
    }

    bool ScenePickMarkedTexture(uint64_t hash) {
        if (!markedAny.load()) {
            return false;
        }
        thread_local std::unordered_set<uint64_t> cache;
        thread_local uint64_t cacheVersion = UINT64_MAX;
        return cachedCopy(markedMutex, markedTextures, markedVersion, cache, cacheVersion).count(hash) != 0;
    }
}
