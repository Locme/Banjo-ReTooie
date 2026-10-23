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
        std::mutex shineModelMutex;
        std::unordered_set<uint64_t> shineModelTextures;
        std::atomic<bool> shineModelAny{ false };
        std::mutex matrixObjectMutex;
        std::unordered_map<uint32_t, uint32_t> matrixObjects;
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
        std::atomic<uint64_t> glowVersion{ 0 }, lightSourceVersion{ 0 }, rayOffVersion{ 0 }, markedVersion{ 0 }, shineModelVersion{ 0 }, matrixObjectVersion{ 0 };

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

    void SetSceneShineModelTextures(const uint64_t *hashes, size_t count) {
        std::unordered_set<uint64_t> textures(hashes, hashes + count);
        const std::scoped_lock lock(shineModelMutex);
        shineModelTextures.swap(textures);
        shineModelAny.store(!shineModelTextures.empty());
        shineModelVersion.fetch_add(1, std::memory_order_release);
    }

    bool SceneShineModelAny() {
        return shineModelAny.load();
    }

    bool SceneShineModelTexture(uint64_t hash) {
        if (!shineModelAny.load()) {
            return false;
        }
        thread_local std::unordered_set<uint64_t> cache;
        thread_local uint64_t cacheVersion = UINT64_MAX;
        return cachedCopy(shineModelMutex, shineModelTextures, shineModelVersion, cache, cacheVersion).count(hash) != 0;
    }

    void SetSceneMatrixObjects(const uint32_t *ids, const uint32_t *objects, size_t count) {
        // (Nothing to send while no Light Source is picked: the list stays as it was, unread.)
        if (!shineModelAny.load() && (count == 0)) {
            return;
        }
        std::unordered_map<uint32_t, uint32_t> map;
        map.reserve(count);
        for (size_t i = 0; i < count; i++) {
            map[ids[i]] = objects[i];
        }
        const std::scoped_lock lock(matrixObjectMutex);
        matrixObjects.swap(map);
        matrixObjectVersion.fetch_add(1, std::memory_order_release);
    }

    uint32_t SceneMatrixObject(uint32_t matrixId) {
        if ((matrixId == 0) || !shineModelAny.load()) {
            return 0;
        }
        thread_local std::unordered_map<uint32_t, uint32_t> cache;
        thread_local uint64_t cacheVersion = UINT64_MAX;
        const auto &objects = cachedCopy(matrixObjectMutex, matrixObjects, matrixObjectVersion, cache, cacheVersion);
        const auto it = objects.find(matrixId);
        return (it != objects.end()) ? it->second : 0;
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
