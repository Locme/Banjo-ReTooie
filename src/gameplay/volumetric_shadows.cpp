// Volumetric shadows (WIP tab): see include/tooie_volumetric_shadows.h.

#include <algorithm>
#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <variant>

#include "recompui/config.h"

#include "tooie_volumetric_shadows.h"

namespace RT64 {
    // rt64-ext/src/render/rt64_volumetric_shadows.h.
    void SetVolumetricShadows(float sun, float haze, uint32_t quality, float distance, float lamps, uint32_t lampCount, uint32_t view, float surfaces);
}

namespace {
    std::atomic<float> sun_reach{ 0.0f };
    std::atomic<bool> lamps{ false };

    float number(const std::string& id, float fallback) {
        try {
            return float(std::get<double>(recompui::config::get_config(recompui::config::graphics::id).get_option_value(id)));
        } catch (...) {
            return fallback;
        }
    }

    uint32_t choice(const std::string& id, uint32_t fallback) {
        try {
            return std::get<uint32_t>(recompui::config::get_config(recompui::config::graphics::id).get_option_value(id));
        } catch (...) {
            return fallback;
        }
    }
}

void tooie::volumetric_shadows::add_options(recomp::config::Config& graphics) {
    graphics.add_number_option(
        sun_option,
        "Volumetric Shadows (Sun)",
        "WIP. Shafts of sunlight through the air: a thin haze lit by the sun, with the shadows of trees, arches, cliffs and Banjo cut out of it, so the light streams through the gaps. Brightest looking towards the sun. It works on its own, whatever Sun Shadows or Ray Tracing are set to. 0 turns it off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        lamps_option,
        "Volumetric Shadows (Lamps)",
        "WIP. A warm glow in the air round the nearest lamps, torches and fires, with the shadows of what stands in their light cut through it. It works on its own, whatever Sun Shadows or Ray Tracing are set to. 0 turns it off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        lamp_count_option,
        "Volumetric Shadows Lamps At Once",
        "How many of the nearest lamps glow at once. Each one costs about six times as much as the sun.",
        1, 2, 1, 0, false, 2);
    graphics.add_option_hidden_dependency(lamp_count_option, lamps_option, 0.0);
    graphics.add_number_option(
        surfaces_option,
        "Volumetric Shadows On Surfaces",
        "How much the sun's shafts also shade the ground and walls: what stands in the sun's way darkens what is behind it, from the shafts' own map, so the shade on the ground lines up with the shadows in the air. Separate from Sun Shadows. 0 leaves the surfaces as they are.",
        0, 100, 5, 0, false, 60);
    graphics.add_option_hidden_dependency(surfaces_option, sun_option, 0.0);
    graphics.add_number_option(
        haze_option,
        "Volumetric Shadows Haze",
        "How thick the haze the light shows in is. Thicker makes the shafts and glows stronger, and also dims what is far away.",
        1, 100, 1, 0, false, 40);
    graphics.add_enum_option(
        quality_option,
        "Volumetric Shadows Quality",
        "The detail of the shadows in the light. Low and Medium work the light out at half the picture's size; High at full size, with a finer map. Higher costs more.",
        {
            {Quality::Low, "Low", "Low"},
            {Quality::Medium, "Medium", "Medium"},
            {Quality::High, "High", "High"},
        },
        Quality::Medium);
    graphics.add_number_option(
        distance_option,
        "Volumetric Shadows Distance",
        "How far round the camera the sun's shafts have shadows in them, in the game's units (Banjo is about 150 tall). Past it the haze is lit all through. Further spreads the same detail wider.",
        1500, 8000, 250, 0, false, 4000);
    graphics.add_enum_option(
        view_option,
        "Volumetric Shadows View",
        "For testing. Light Only shows just the light in the haze over black, so the shafts and the shadows through them are easy to see. Light And Map adds the sun's map in the top left corner: what is nearest the sun white, the ground grey, nothing black.",
        {
            {View::Normal, "Normal", "Normal"},
            {View::LightOnly, "LightOnly", "Light Only"},
            {View::LightAndMap, "LightAndMap", "Light And Map"},
        },
        View::Normal);
    for (const std::string* id : { &sun_option, &lamps_option, &lamp_count_option, &surfaces_option, &haze_option, &quality_option, &distance_option, &view_option }) {
        graphics.add_option_change_callback(*id,
            [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
                if (context == recomp::config::OptionChangeContext::Temporary) {
                    recompui::config::get_graphics_config().save_config();
                }
            });
    }
}

void tooie::volumetric_shadows::tick() {
    float sun = number(sun_option, 0.0f) / 100.0f;
    float lamp = number(lamps_option, 0.0f) / 100.0f;
    float haze = number(haze_option, 40.0f) / 100.0f;
    uint32_t quality = choice(quality_option, uint32_t(Quality::Medium));
    // Test aid: TOOIE_VOLSHADOW=<sun 0-100>,<lamps 0-100>,<haze 1-100>,<quality 0-2> whatever the settings say.
    if (const char* v = std::getenv("TOOIE_VOLSHADOW")) {
        float s = 0.0f, l = 0.0f, h = 40.0f;
        unsigned int q = 1;
        std::sscanf(v, "%f,%f,%f,%u", &s, &l, &h, &q);
        sun = s / 100.0f;
        lamp = l / 100.0f;
        haze = h / 100.0f;
        quality = q;
    }
    const float distance = number(distance_option, 4000.0f);
    const uint32_t count = uint32_t(std::clamp(number(lamp_count_option, 2.0f), 1.0f, 2.0f));
    sun_reach = (sun > 0.0f) ? distance : 0.0f;
    lamps = lamp > 0.0f;
    RT64::SetVolumetricShadows(sun, haze, quality, distance, lamp, count, choice(view_option, 0), number(surfaces_option, 60.0f) / 100.0f);
}

float tooie::volumetric_shadows::sun_distance() {
    return sun_reach.load();
}

bool tooie::volumetric_shadows::lamps_on() {
    return lamps.load();
}
