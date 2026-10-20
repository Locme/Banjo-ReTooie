// Effect developer views (handoff 4.43).
//
// Graphics > Debug > Effect debug view, or F6 (Shift+F6 back), steps through the debug views of RT64's
// scene effects pass (lib-patches/rt64.patch, SceneEffectsPS.hlsl): the effects alone (ambient occlusion
// and outlines as grey, rim light lighter, fog blue, sky magenta), the depth (near white, far dark, sky
// blue), the normals worked out from the depth, the water mask (red where the game draws water, yellow
// where it reflects). F8 draws the picture effects (the scene effects pass and the photo grade pass:
// sharpening, contrast, saturation, vignette, grain) only on the left half, with the original on the
// right and a line between. SMAA and the Retro filters aren't split.
//
// Then one view for each effect and filter on its own ("Only: bloom" and so on), at its setting or at a
// default strength when it is off, with every other effect and filter off; with F8 it is compared with
// the original. "All effects off" is the picture with none of them, to compare against. The scene effects
// are kept or dropped by RT64 (RT64::GetSceneEffects; view 18 keeps none); the other filters are left out
// by picture_filters, smaa, fxaa and fsr apply(), which ask isolating() and solo().
//
// The view starts off at each launch. Headless test hooks: TOOIE_SCENE_FX_VIEW=<1-33> starts in that
// view; TOOIE_FX_COMPARE=1 starts with the compare on.

#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <iterator>
#include <mutex>
#include <thread>
#include <variant>

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include "recompui/config.h"

#include "tooie_effect_views.h"
#include "tooie_fsr.h"
#include "tooie_fxaa.h"
#include "tooie_game.h"
#include "tooie_hotkeys.h"
#include "tooie_picture_filters.h"
#include "tooie_smaa.h"
#include "tooie_toast.h"

namespace RT64 {
    // lib/rt64/src/render/rt64_scene_effects.h and rt64_photo_grade.h (from lib-patches/rt64.patch).
    void SetSceneEffectsView(uint32_t view, bool compare);
    void SetPhotoGradeCompare(bool compare);
}

namespace {
    using namespace std::chrono_literals;
    using Solo = tooie::effect_views::Solo;

    constexpr auto poll_interval = 10ms;
    // RT64's solo views run from 5 (RT64::SceneEffectsSoloFirst) to 17; 18 keeps no scene effect; 19 to 21 show
    // GTAO, SSGI and SSR on their own (RT64::SceneEffectsViewGtao on).
    constexpr uint32_t scene_solo_first = 5;
    constexpr uint32_t scene_none = 18;

    struct View {
        const char* name;
        uint32_t scene_view;
        Solo solo;
    };
    const View views[] = {
        { "Off", 0, Solo::None },
        { "Effects alone", 1, Solo::None },
        { "Depth", 2, Solo::None },
        { "Normals", 3, Solo::None },
        { "Water (red, yellow where it reflects)", 4, Solo::None },
        { "Only: ambient occlusion", 5, Solo::None },
        { "Only: bounce light", 6, Solo::None },
        { "Only: toon outlines", 7, Solo::None },
        { "Only: rim light", 8, Solo::None },
        { "Only: fog", 9, Solo::None },
        { "Only: bloom", 10, Solo::None },
        { "Only: light shafts", 11, Solo::None },
        { "Only: eye adaptation", 12, Solo::None },
        { "Only: water reflections", 13, Solo::None },
        { "Only: water waves", 14, Solo::None },
        { "Only: underwater tint and haze", 15, Solo::None },
        { "Only: heat haze and underwater distortion", 16, Solo::None },
        { "Only: depth of field", 17, Solo::None },
        { "GTAO occlusion (white open, dark shaded)", 19, Solo::None },
        { "SSGI bounced light", 20, Solo::None },
        { "Screen-space reflections (red: nothing to reflect)", 21, Solo::None },
        { "All effects off", scene_none, Solo::None },
        { "Only: sharpening", scene_none, Solo::Sharpening },
        { "Only: contrast", scene_none, Solo::Contrast },
        { "Only: colour saturation", scene_none, Solo::Saturation },
        { "Only: vignette", scene_none, Solo::Vignette },
        { "Only: film grain", scene_none, Solo::Grain },
        { "Only: SMAA", scene_none, Solo::Smaa },
        { "Only: FXAA", scene_none, Solo::Fxaa },
        { "Only: FSR", scene_none, Solo::Fsr },
        { "Only: CRT", scene_none, Solo::Crt },
        { "Only: N64 16-bit colour", scene_none, Solo::Colour16 },
        { "Only: colourblind filter", scene_none, Solo::Colourblind },
        { "Only: texture upscaling", scene_none, Solo::TextureUpscale },
    };
    constexpr uint32_t view_count = (uint32_t)std::size(views);

    std::once_flag started;
    std::atomic<uint32_t> view{0};
    std::atomic<bool> compare{false};
    bool created = false;

    // Looked up each time: the tab list moves its configs as more tabs are added. The options live in the DEV tab.
    recomp::config::Config& graphics_config() {
        return recompui::config::get_config(tooie::wip_tab_id);
    }

    void send() {
        const uint32_t v = view.load();
        RT64::SetSceneEffectsView(views[v].scene_view, compare);
        RT64::SetPhotoGradeCompare(compare);
        // The filters outside the scene effects pass read isolating() and solo() as they apply.
        tooie::picture_filters::apply();
        tooie::smaa::apply();
        tooie::fxaa::apply();
        tooie::fsr::apply();
    }

    void set_view(uint32_t v) {
        v %= view_count;
        if (created) {
            // The option's callback saves it, and then sets the view.
            try {
                graphics_config().update_option_value(tooie::effect_views::option, v);
                return;
            } catch (...) {
            }
        }
        view = v;
        send();
    }

    void set_compare(bool on) {
        if (created) {
            // The option's callback saves it, and then sets the compare.
            try {
                graphics_config().update_option_value(tooie::effect_views::compare_option, on);
                return;
            } catch (...) {
            }
        }
        compare = on;
        send();
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
            const bool view_down = tooie::hotkeys::down(recompinput::GameInput::EFFECT_VIEW);
            const bool compare_down = tooie::hotkeys::down(recompinput::GameInput::EFFECT_COMPARE);
            if (view_down && !view_was_down) {
                // Shift+F6 steps back.
                const bool back = key_down(SDL_SCANCODE_LSHIFT) || key_down(SDL_SCANCODE_RSHIFT);
                const uint32_t next = (view + (back ? view_count - 1 : 1)) % view_count;
                set_view(next);
                tooie::toast::show(next == 0 ? "Effect view off" : views[next].name);
            }
            if (compare_down && !compare_was_down) {
                set_compare(!compare);
                tooie::toast::show(compare ? "Compare: effects on the left, original on the right" : "Compare off");
            }
            view_was_down = view_down;
            compare_was_down = compare_down;
        }
    }
}

bool tooie::effect_views::isolating() {
    return view.load() >= scene_solo_first;
}

tooie::effect_views::Solo tooie::effect_views::solo() {
    return views[view.load()].solo;
}

void tooie::effect_views::add_option(recomp::config::Config& graphics) {
    created = true;

    std::vector<recomp::config::ConfigOptionEnumOption> options;
    for (uint32_t i = 0; i < view_count; i++) {
        options.emplace_back(i, views[i].name, views[i].name);
    }
    graphics.add_enum_option(
        option,
        "Effect debug view",
        "For testing. Shows one picture effect or filter on its own, with every other one off: at its setting, or at a default strength when it is off. "
        "<recomp-color primary>All effects off</recomp-color> shows the picture with none of them, to compare against. The first views show the scene effects' depth, normals and water mask. "
        "The Effect Debug View key steps to the next view (with Shift back) and the Effect Compare key splits the picture: the effect on the left, the original on the right (both bound in the Debug section of the Controls tab). Starts Off each launch.",
        options,
        0u);
    graphics.add_bool_option(
        compare_option,
        "Effect compare",
        "Splits the picture for testing: the effect or filter on the left, the original on the right. F8 switches it on and off while you play. Starts Off each launch.",
        false);
    graphics.add_option_change_callback(compare_option,
        [](recomp::config::ConfigValueVariant value, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
            if (context == recomp::config::OptionChangeContext::Temporary) {
                graphics_config().save_config();
                return;
            }
            const auto* v = std::get_if<bool>(&value);
            compare = (v != nullptr) && *v;
            send();
        });
    graphics.add_option_change_callback(option,
        [](recomp::config::ConfigValueVariant value, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
            if (context == recomp::config::OptionChangeContext::Temporary) {
                // Saving applies the change, which calls back here as Permanent.
                graphics_config().save_config();
                return;
            }
            const auto* v = std::get_if<uint32_t>(&value);
            view = ((v != nullptr) && (*v < view_count)) ? *v : 0;
            send();
        });
}

void tooie::effect_views::start() {
    std::call_once(started, [] {
        uint32_t first = 0;
        if (const char* v = std::getenv("TOOIE_SCENE_FX_VIEW")) {
            first = (uint32_t)std::atoi(v) % view_count;
        }
        if (const char* v = std::getenv("TOOIE_FX_COMPARE"); v != nullptr && v[0] == '1') {
            compare = true;
        }
        // A debug view left on last time starts off again.
        set_view(first);
        set_compare(compare);
        send();
        std::thread(worker).detach();
    });
}
