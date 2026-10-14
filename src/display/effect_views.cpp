// Effect developer views (handoff 4.43).
//
// F6 steps through the debug views of RT64's scene effects pass (lib-patches/rt64.patch,
// SceneEffectsPS.hlsl): the effects alone (ambient occlusion and outlines as grey, rim light lighter,
// fog blue, sky magenta), the depth (near white, far dark, sky blue), the normals worked out from the
// depth, the water mask (red where the game draws water, yellow where it reflects). F8 draws the picture effects (the scene effects pass and the photo grade pass:
// sharpening, contrast, saturation, vignette, grain) only on the left half, with the original on the
// right and a line between. SMAA and the Retro filters aren't split.
//
// Then one view for each effect on its own ("Only: bloom" and so on), at its setting or at half strength
// when it is off, to see what each one does; with F8 it is compared with the original.
//
// Headless test hooks: TOOIE_SCENE_FX_VIEW=<1-17> starts in that view; TOOIE_FX_COMPARE=1 starts with
// the compare on.

#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <mutex>
#include <thread>

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include "tooie_effect_views.h"
#include "tooie_toast.h"

namespace RT64 {
    // lib/rt64/src/render/rt64_scene_effects.h and rt64_photo_grade.h (from lib-patches/rt64.patch).
    void SetSceneEffectsView(uint32_t view, bool compare);
    void SetPhotoGradeCompare(bool compare);
}

namespace {
    using namespace std::chrono_literals;

    constexpr auto poll_interval = 10ms;
    // From 5 on, the picture with one effect only (RT64::SceneEffectsSoloFirst), at its setting or at half
    // strength when it is off; F8 compares it with the original.
    constexpr uint32_t view_count = 18;
    const char* const view_names[view_count] = {
        "Effect view off",
        "Effect view: effects alone",
        "Effect view: depth",
        "Effect view: normals",
        "Effect view: water (red, yellow where it reflects)",
        "Only: ambient occlusion",
        "Only: bounce light",
        "Only: toon outlines",
        "Only: rim light",
        "Only: fog",
        "Only: bloom",
        "Only: light shafts",
        "Only: eye adaptation",
        "Only: water reflections",
        "Only: water waves",
        "Only: underwater tint and haze",
        "Only: heat haze",
        "Only: depth of field",
    };

    std::once_flag started;
    uint32_t view = 0;
    bool compare = false;

    void send() {
        RT64::SetSceneEffectsView(view, compare);
        RT64::SetPhotoGradeCompare(compare);
    }

    bool key_down(SDL_Scancode key) {
        const Uint8* keys = SDL_GetKeyboardState(nullptr);
        return keys != nullptr && keys[key] != 0;
    }

    void worker() {
        bool view_was_down = false;
        bool compare_was_down = false;
        for (;;) {
            std::this_thread::sleep_for(poll_interval);
            const bool view_down = key_down(SDL_SCANCODE_F6);
            const bool compare_down = key_down(SDL_SCANCODE_F8);
            if (view_down && !view_was_down) {
                // Shift+F6 steps back.
                const bool back = key_down(SDL_SCANCODE_LSHIFT) || key_down(SDL_SCANCODE_RSHIFT);
                view = (view + (back ? view_count - 1 : 1)) % view_count;
                send();
                tooie::toast::show(view_names[view]);
            }
            if (compare_down && !compare_was_down) {
                compare = !compare;
                send();
                tooie::toast::show(compare ? "Compare: effects on the left, original on the right" : "Compare off");
            }
            view_was_down = view_down;
            compare_was_down = compare_down;
        }
    }
}

void tooie::effect_views::start() {
    std::call_once(started, [] {
        if (const char* v = std::getenv("TOOIE_SCENE_FX_VIEW")) {
            view = (uint32_t)std::atoi(v) % view_count;
        }
        if (const char* v = std::getenv("TOOIE_FX_COMPARE"); v != nullptr && v[0] == '1') {
            compare = true;
        }
        if ((view != 0) || compare) {
            send();
        }
        std::thread(worker).detach();
    });
}
