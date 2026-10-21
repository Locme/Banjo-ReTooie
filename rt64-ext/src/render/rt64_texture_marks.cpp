//
// RT64
//

#include "rt64_texture_marks.h"

#include <atomic>
#include <mutex>
#include <unordered_set>

namespace RT64 {
    namespace {
        // Each list is swapped in whole; the flags skip the lock while a list is empty (most of the time).
        std::mutex glowMutex;
        std::unordered_set<uint64_t> glowTextures;
        std::atomic<bool> glowAny{ false };
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
