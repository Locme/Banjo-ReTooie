//
// RT64 extension: Point Lights. See rt64_scene_lights.h.
//

#include "rt64_scene_lights.h"

#include <algorithm>
#include <atomic>
#include <cmath>
#include <mutex>
#include <vector>

namespace RT64 {
    // A lamp found by its texture: warm lamplight, out to this far (its reach for the traced lights is much longer).
    static constexpr float TextureLampColour[3] = { 1.0f, 0.72f, 0.42f };
    static constexpr float TextureLampRadius = 600.0f;
    // Lamps further than their radius plus this from the camera light nothing on screen worth the work.
    static constexpr float LampViewReach = 4000.0f;

    static std::atomic<bool> pointLights = false;
    static std::mutex lampMutex;
    static float lampStrength = 1.0f;
    static std::vector<ScenePointLamp> levelLamps;
    static std::vector<ScenePointLamp> textureLamps;
    static float lampCamera[3] = {};

    void SetScenePointLights(bool enabled, float strength) {
        const std::scoped_lock lock(lampMutex);
        lampStrength = std::clamp(strength, 0.0f, 4.0f);
        pointLights = enabled && (lampStrength > 0.0f);
    }

    bool ScenePointLights() {
        return pointLights.load();
    }

    void SetScenePointLamps(const ScenePointLamp *lamps, uint32_t count, const float camera[3]) {
        const std::scoped_lock lock(lampMutex);
        levelLamps.assign(lamps, lamps + count);
        lampCamera[0] = camera[0];
        lampCamera[1] = camera[1];
        lampCamera[2] = camera[2];
    }

    void SetScenePointTextureLamps(const float *xyzr, uint32_t count) {
        const std::scoped_lock lock(lampMutex);
        textureLamps.clear();
        for (uint32_t i = 0; i < count; i++) {
            const float *l = xyzr + i * 4;
            textureLamps.push_back({ l[0], l[1], l[2], std::min(std::floor(l[3]), TextureLampRadius), TextureLampColour[0], TextureLampColour[1], TextureLampColour[2] });
        }
    }

    uint32_t ScenePointLampsForFrame(ScenePointLamp *out) {
        if (!ScenePointLights()) {
            return 0;
        }

        const std::scoped_lock lock(lampMutex);
        struct Near { float dist2; const ScenePointLamp *lamp; };
        std::vector<Near> nearest;
        nearest.reserve(levelLamps.size() + textureLamps.size());
        for (const std::vector<ScenePointLamp> *list : { &levelLamps, &textureLamps }) {
            for (const ScenePointLamp &lamp : *list) {
                const float dx = lamp.x - lampCamera[0], dy = lamp.y - lampCamera[1], dz = lamp.z - lampCamera[2];
                const float dist2 = dx * dx + dy * dy + dz * dz;
                const float reach = lamp.radius + LampViewReach;
                if ((lamp.radius > 0.0f) && (dist2 < reach * reach)) {
                    nearest.push_back({ dist2, &lamp });
                }
            }
        }

        std::sort(nearest.begin(), nearest.end(), [](const Near &a, const Near &b) { return a.dist2 < b.dist2; });
        const uint32_t count = std::min<uint32_t>(uint32_t(nearest.size()), ScenePointLightMax);
        for (uint32_t i = 0; i < count; i++) {
            out[i] = *nearest[i].lamp;
            out[i].r *= lampStrength;
            out[i].g *= lampStrength;
            out[i].b *= lampStrength;
        }

        return count;
    }
};
