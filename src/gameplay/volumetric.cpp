// Volumetric mist, fog and clouds (WIP tab): see include/tooie_volumetric.h.
//
// The settings are global options; Dev Files/volumetric.txt (read again whenever it changes) overrides them per level,
// one map a line, any of the keys in any order:
//   0xAF clouds=stormy cover=80 height=50 thickness=60 speed=40 mist=50 fog=30 fog_preset=murky mist_offset=0
// clouds: off, fair, scattered, overcast, stormy, wispy, sunset or thunderstorm. cover, height, thickness and speed are the
// cloud shape in 0 to 100 as the Day and Night cloud settings (50 the usual); a type's own shape is used for what is left
// out. mist and fog are 0 to 100, fog_preset one of default, bright, hell, murky, poison, sponza or pillar, mist_offset
// moves the mist's floor up or down in world units. # starts a comment.

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <variant>

#include "recomp.h"
#include "recompui/config.h"

#include "tooie_debug.h"
#include "tooie_dev_files.h"
#include "tooie_volumetric.h"

namespace RT64 {
    // rt64-ext/src/render/rt64_scene_effects.h.
    void SetSceneVolumetric(float mist, float fog, uint32_t fogPreset, uint32_t cloudType, float mistOffset);
    void SetSceneClouds(float cover, float height, float thickness, float speed);
}

namespace {
    constexpr const char* file_name = "volumetric.txt";

    // A type's own cloud shape, in the units SetSceneClouds takes: cover 0 to 1, height 0.25 to 4, thickness 0.1 to 2, speed 0 to 8.
    struct Shape {
        float cover;
        float height;
        float thickness;
        float speed;
    };
    // Index: the type (1 Fair to 7 Thunderstorm).
    constexpr Shape type_shapes[8] = {
        { 0.5f, 1.0f, 0.6f, 1.0f },
        { 0.45f, 1.0f, 0.6f, 1.0f },
        { 0.3f, 0.8f, 1.0f, 1.5f },
        { 0.85f, 0.9f, 0.5f, 0.8f },
        { 0.95f, 0.7f, 1.3f, 2.5f },
        { 0.35f, 2.0f, 0.25f, 1.5f },
        { 0.5f, 1.0f, 0.7f, 0.8f },
        { 1.0f, 0.6f, 1.6f, 3.5f },
    };

    // What one line of the file sets; a negative number or -1 is left alone.
    struct Level {
        int clouds = -1;
        float cover = -1.0f;
        float height = -1.0f;
        float thickness = -1.0f;
        float speed = -1.0f;
        float mist = -1.0f;
        float fog = -1.0f;
        int preset = -1;
        float mist_offset = 0.0f;
    };

    std::map<uint16_t, Level> levels;
    std::filesystem::file_time_type file_time{};
    bool file_seen = false;
    int frames = 0;

    const char* const cloud_names[] = { "off", "fair", "scattered", "overcast", "stormy", "wispy", "sunset", "thunderstorm" };
    const char* const preset_names[] = { "default", "bright", "hell", "murky", "poison", "sponza", "pillar" };

    int find(const char* const* names, size_t count, const std::string& word) {
        for (size_t i = 0; i < count; i++) {
            if (word == names[i]) {
                return int(i);
            }
        }
        return -1;
    }

    bool read_line(const std::string& raw, uint16_t& map, Level& out) {
        const std::string text = raw.substr(0, raw.find('#'));
        std::istringstream in(text);
        std::string first;
        if (!(in >> first)) {
            return false;
        }
        char* end = nullptr;
        const unsigned long m = std::strtoul(first.c_str(), &end, 16);
        if (end == first.c_str() || *end != '\0' || m > 0xFFFF) {
            return false;
        }
        map = uint16_t(m);
        out = Level();
        std::string pair;
        while (in >> pair) {
            const size_t equals = pair.find('=');
            if (equals == std::string::npos) {
                return false;
            }
            std::string key = pair.substr(0, equals);
            std::string value = pair.substr(equals + 1);
            std::transform(value.begin(), value.end(), value.begin(), [](unsigned char c) { return char(std::tolower(c)); });
            const float number = float(std::atof(value.c_str()));
            if (key == "clouds") {
                out.clouds = find(cloud_names, std::size(cloud_names), value);
                if (out.clouds < 0) {
                    return false;
                }
            }
            else if (key == "fog_preset") {
                out.preset = find(preset_names, std::size(preset_names), value);
                if (out.preset < 0) {
                    return false;
                }
            }
            else if (key == "cover") { out.cover = std::clamp(number / 100.0f, 0.0f, 1.0f); }
            else if (key == "height") { out.height = std::clamp(number / 100.0f, 0.0f, 1.0f); }
            else if (key == "thickness") { out.thickness = std::clamp(number / 100.0f, 0.0f, 1.0f); }
            else if (key == "speed") { out.speed = std::clamp(number / 100.0f, 0.0f, 1.0f); }
            else if (key == "mist") { out.mist = std::clamp(number / 100.0f, 0.0f, 1.0f); }
            else if (key == "fog") { out.fog = std::clamp(number / 100.0f, 0.0f, 1.0f); }
            else if (key == "mist_offset") { out.mist_offset = number; }
            else {
                return false;
            }
        }
        return true;
    }

    void write_template() {
        std::error_code ec;
        std::filesystem::create_directories(tooie::dev_files::folder(), ec);
        std::ofstream out(tooie::dev_files::path(file_name));
        out << "# Volumetric mist, fog and clouds per level (Graphics > WIP > Volumetric). Read again whenever this file changes.\n"
               "# One level a line: map (hex), then any of these in any order. # starts a comment.\n"
               "#   clouds=off|fair|scattered|overcast|stormy|wispy|sunset|thunderstorm   the cloud type on this level\n"
               "#   cover= height= thickness= speed=   the cloud shape, 0 to 100 (50 the usual); left out, the type's own shape\n"
               "#   mist=0..100  fog=0..100  fog_preset=default|bright|hell|murky|poison|sponza|pillar\n"
               "#   mist_offset=<world units>   moves the mist's floor up (+) or down (-)\n"
               "# Examples (remove the # to use one):\n"
               "# 0xAF clouds=stormy cover=80 mist=40\n"
               "# 0x142 clouds=off fog=30 fog_preset=murky\n";
    }

    void load() {
        std::error_code ec;
        const std::filesystem::path path = tooie::dev_files::read_path(file_name);
        std::ifstream in(path);
        levels.clear();
        std::string line;
        int count = 0;
        while (std::getline(in, line)) {
            uint16_t map;
            Level level;
            if (read_line(line, map, level)) {
                levels[map] = level;
                count++;
            }
            else if (line.find_first_not_of(" \t\r") != std::string::npos && line.find_first_not_of(" \t\r") != line.find('#')) {
                fprintf(stderr, "[volumetric] skipped a line of volumetric.txt: %s\n", line.c_str());
            }
        }
        fprintf(stderr, "[volumetric] read %d level(s) from volumetric.txt\n", count);
    }

    // Reads the file at the start and again after it changes (checked about once a second).
    void refresh(bool anything_on) {
        if (frames++ % 60 != 0) {
            return;
        }
        std::error_code ec;
        const std::filesystem::path path = tooie::dev_files::read_path(file_name);
        const bool exists = std::filesystem::exists(path, ec);
        if (!exists && anything_on && !file_seen) {
            write_template();
        }
        file_seen = true;
        const auto time = exists ? std::filesystem::last_write_time(path, ec) : std::filesystem::file_time_type{};
        static bool first = true;
        if (first || time != file_time) {
            first = false;
            file_time = time;
            load();
        }
    }

    float number(const std::string& id, float fallback) {
        try {
            return float(std::get<double>(recompui::config::get_config(recompui::config::graphics::id).get_option_value(id)));
        } catch (...) {
            return fallback;
        }
    }

    uint32_t choice(const std::string& id) {
        try {
            return std::get<uint32_t>(recompui::config::get_config(recompui::config::graphics::id).get_option_value(id));
        } catch (...) {
            return 0;
        }
    }

    bool flag(const std::string& id, bool fallback) {
        try {
            return std::get<bool>(recompui::config::get_config(recompui::config::graphics::id).get_option_value(id));
        } catch (...) {
            return fallback;
        }
    }
}

void tooie::volumetric::add_options(recomp::config::Config& graphics) {
    graphics.add_number_option(
        mist_option,
        "Volumetric Mist",
        "WIP. Mist as a real volume: pale banks drift along the ground, thickest low down and thinning out about 300 units up, lit by the sun and thicker the further you look through it. It stays put in the level as you walk, and meets the scenery rather than lying over it. 0 turns it off. A level's line in Dev Files/volumetric.txt (mist=) overrides this.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        fog_option,
        "Volumetric Fog",
        "WIP. Fog through the whole scene, as a real volume lit by the sun, with slow patches drifting through it: the preset below sets its colour, thickness and glow. 100 is the preset as designed, lower is thinner. 0 turns it off. Separate from the Fog setting. A level's line in Dev Files/volumetric.txt (fog=) overrides this.",
        0, 100, 5, 0, false, 0);
    graphics.add_enum_option(
        fog_preset_option,
        "Volumetric Fog Preset",
        "The fog's look, from Vapor's presets. Default: pale blue-grey. Bright: soft, light haze. Hell: thick, red and glowing. Murky: thick, dark grey. Poison: green and glowing. Sponza: thick, pale blue-white. Pillar: thick white.",
        {
            {FogPreset::Default, "Default", "Default"},
            {FogPreset::Bright, "Bright", "Bright"},
            {FogPreset::Hell, "Hell", "Hell"},
            {FogPreset::Murky, "Murky", "Murky"},
            {FogPreset::Poison, "Poison", "Poison"},
            {FogPreset::Sponza, "Sponza", "Sponza"},
            {FogPreset::Pillar, "Pillar", "Pillar"},
        },
        FogPreset::Default);
    graphics.add_option_hidden_dependency(fog_preset_option, fog_option, 0.0);
    graphics.add_enum_option(
        clouds_option,
        "Volumetric Clouds",
        "WIP. Soft 3D clouds across the sky of every level, whatever the time of day and without the Day and Night cycle (with it, they replace its clouds). The types: Fair, Scattered puffs, Overcast grey, Stormy dark grey, Wispy high streaks, Sunset glow, Thunderstorm. Only where the sky shows. Per level choices and shapes go in Dev Files/volumetric.txt.",
        {
            {Clouds::Off, "Off", "Off"},
            {Clouds::Fair, "Fair", "Fair"},
            {Clouds::Scattered, "Scattered", "Scattered"},
            {Clouds::Overcast, "Overcast", "Overcast"},
            {Clouds::Stormy, "Stormy", "Stormy"},
            {Clouds::Wispy, "Wispy", "Wispy"},
            {Clouds::Sunset, "Sunset", "Sunset"},
            {Clouds::Thunderstorm, "Thunderstorm", "Thunderstorm"},
        },
        Clouds::Off);
    graphics.add_bool_option(
        file_option,
        "Volumetric Level File",
        "Reads Dev Files/volumetric.txt (made the first time any volumetric option is on): per level mist, fog, cloud type and cloud shape that override the settings above, for the levels listed. Changes to the file apply within a second.",
        true);
    for (const std::string* id : { &mist_option, &fog_option, &fog_preset_option, &clouds_option, &file_option }) {
        graphics.add_option_change_callback(*id,
            [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
                if (context == recomp::config::OptionChangeContext::Temporary) {
                    recompui::config::get_graphics_config().save_config();
                }
            });
    }
}

void tooie::volumetric::tick(uint8_t* rdram) {
    float mist = number(mist_option, 0.0f) / 100.0f;
    float fog = number(fog_option, 0.0f) / 100.0f;
    uint32_t preset = choice(fog_preset_option);
    uint32_t cloud_type = choice(clouds_option);
    // Test aid: TOOIE_VOL=<mist 0-100>,<fog 0-100>,<fog preset 0-6>,<cloud type 0-7> whatever the settings say.
    if (const char* v = std::getenv("TOOIE_VOL")) {
        float m = 0.0f, f = 0.0f;
        unsigned int p = 0, c = 0;
        std::sscanf(v, "%f,%f,%u,%u", &m, &f, &p, &c);
        mist = m / 100.0f;
        fog = f / 100.0f;
        preset = p;
        cloud_type = c;
    }
    const bool use_file = flag(file_option, true);
    refresh((mist > 0.0f) || (fog > 0.0f) || (cloud_type > 0));

    Shape shape = type_shapes[std::min(cloud_type, 7u)];
    float offset = 0.0f;
    if (use_file) {
        const auto found = levels.find(tooie::debug::current_map(rdram));
        if (found != levels.end()) {
            const Level& l = found->second;
            if (l.clouds >= 0) {
                cloud_type = uint32_t(l.clouds);
                shape = type_shapes[std::min(cloud_type, 7u)];
            }
            if (l.mist >= 0.0f) { mist = l.mist; }
            if (l.fog >= 0.0f) { fog = l.fog; }
            if (l.preset >= 0) { preset = uint32_t(l.preset); }
            offset = l.mist_offset;
            // The same units the Day and Night cloud settings use (see day_night.cpp).
            if (l.cover >= 0.0f) { shape.cover = l.cover; }
            if (l.height >= 0.0f) { shape.height = std::pow(4.0f, l.height - 0.5f); }
            if (l.thickness >= 0.0f) { shape.thickness = 0.2f + 0.8f * l.thickness; }
            if (l.speed >= 0.0f) { shape.speed = (l.speed * 2.0f) * (l.speed * 2.0f); }
        }
    }
    RT64::SetSceneVolumetric(mist, fog, preset, cloud_type, offset);
    // Forced clouds take the shape over from the Day and Night cycle's (whose tick has already run this frame).
    if (cloud_type > 0) {
        RT64::SetSceneClouds(shape.cover, shape.height, shape.thickness, shape.speed);
    }
}
