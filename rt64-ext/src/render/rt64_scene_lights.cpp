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
    // Lamps found by a lamp texture are kept for the whole map, so one off screen still lights what is on screen; one found
    // within this of a kept one is the same lamp. Forgotten when the map changes (SetScenePointLamps). A Light Source pick
    // (its reach has a fraction, SceneLightSourceW) can be a thing that moves, so it lights only the frame it is drawn in.
    static constexpr float TextureLampSame = 80.0f;
    static constexpr size_t TextureLampsKept = 256;

    static std::atomic<bool> pointLights = false;
    static std::mutex lampMutex;
    static float lampStrength = 1.0f;
    static std::vector<ScenePointLamp> levelLamps;
    static std::vector<ScenePointLamp> textureLamps;
    static std::vector<ScenePointLamp> frameLamps;
    static float lampCamera[3] = {};
    static uint32_t lampMap = UINT32_MAX;

    void SetScenePointLights(bool enabled, float strength) {
        const std::scoped_lock lock(lampMutex);
        lampStrength = std::clamp(strength, 0.0f, 4.0f);
        pointLights = enabled && (lampStrength > 0.0f);
    }

    bool ScenePointLights() {
        return pointLights.load();
    }

    void SetScenePointLamps(const ScenePointLamp *lamps, uint32_t count, const float camera[3], uint32_t map) {
        const std::scoped_lock lock(lampMutex);
        if (map != lampMap) {
            lampMap = map;
            textureLamps.clear();
            frameLamps.clear();
        }

        levelLamps.assign(lamps, lamps + count);
        lampCamera[0] = camera[0];
        lampCamera[1] = camera[1];
        lampCamera[2] = camera[2];
    }

    void SetScenePointTextureLamps(const float *xyzr, uint32_t count) {
        const std::scoped_lock lock(lampMutex);
        frameLamps.clear();
        for (uint32_t i = 0; i < count; i++) {
            const float *l = xyzr + i * 4;
            const ScenePointLamp lamp = { l[0], l[1], l[2], std::min(std::floor(l[3]), TextureLampRadius), TextureLampColour[0], TextureLampColour[1], TextureLampColour[2] };
            if (l[3] != std::floor(l[3])) {
                frameLamps.push_back(lamp);
                continue;
            }

            bool known = false;
            for (ScenePointLamp &kept : textureLamps) {
                const float dx = kept.x - lamp.x, dy = kept.y - lamp.y, dz = kept.z - lamp.z;
                if ((dx * dx + dy * dy + dz * dz) < (TextureLampSame * TextureLampSame)) {
                    kept = lamp;
                    known = true;
                    break;
                }
            }

            if (!known && (textureLamps.size() < TextureLampsKept)) {
                textureLamps.push_back(lamp);
            }
        }
    }

    uint32_t ScenePointLampsForFrame(ScenePointLamp *out) {
        if (!ScenePointLights()) {
            return 0;
        }

        const std::scoped_lock lock(lampMutex);
        struct Near { float dist2; const ScenePointLamp *lamp; };
        std::vector<Near> nearest;
        nearest.reserve(levelLamps.size() + textureLamps.size() + frameLamps.size());
        for (const std::vector<ScenePointLamp> *list : { &levelLamps, &textureLamps, &frameLamps }) {
            for (const ScenePointLamp &lamp : *list) {
                const float dx = lamp.x - lampCamera[0], dy = lamp.y - lampCamera[1], dz = lamp.z - lampCamera[2];
                // Every lamp counts, however far away (a cut-off by distance lit a lamp only as the camera came close, L):
                // the nearest ScenePointLightMax are used.
                const float dist2 = dx * dx + dy * dy + dz * dz;
                if (lamp.radius > 0.0f) {
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
