// Volumetric mist, fog and clouds (WIP tab): see include/tooie_volumetric.h.
//
// The settings are global options; Dev Files/volumetric.txt (read again whenever it changes) overrides them per level,
// one map a line, any of the keys in any order:
//   0xAF clouds=stormy cover=80 height=50 thickness=60 speed=40 mist=50 fog=30 fog_preset=murky mist_offset=0
// clouds: off, fair, scattered, overcast, stormy, wispy, sunset or thunderstorm. cover, height, thickness and speed are the
// cloud shape in 0 to 100 as the Day and Night cloud settings (50 the usual); a type's own shape is used for what is left
// out. mist and fog are 0 to 100, fog_preset one of default, bright, hell, murky, poison, sponza or pillar, mist_offset
// moves the mist's floor up or down in world units. mist_water and mist_fall (0 to 100) are the mist over water and at a
// waterfall's foot, mist_water_height and mist_fall_height how high each hangs (world units); fog_start is the fog's start
// distance (world units) and fog_colour one of preset, haze, mist, dusk or gloom. # starts a comment.

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <map>
#include <mutex>
#include <sstream>
#include <string>
#include <variant>
#include <vector>

#include "recomp.h"
#include "recompinput/recompinput.h"
#include "recompui/config.h"

#include "tooie_day_night.h"
#include "tooie_debug.h"
#include "tooie_dev_files.h"
#include "tooie_toast.h"
#include "tooie_volumetric.h"

namespace RT64 {
    // rt64-ext/src/render/rt64_scene_effects.h.
    void SetSceneVolumetric(float mist, float fog, uint32_t fogPreset, uint32_t cloudType, float mistOffset);
    void SetSceneClouds(float cover, float height, float thickness, float speed);
    void SetSceneVolumetricExtra(float fogStart, uint32_t fogColour, float waterMist, float waterHeight, float fallMist, float fallHeight);
}

namespace {
    constexpr const char* file_name = "volumetric.txt";

    // A type's own cloud shape, in the units SetSceneClouds takes: cover 0 to 1, height 0.0625 to 4, thickness 0.1 to 2, speed 0 to 8.
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
        float water = -1.0f;
        float water_height = -1.0f;
        float fall = -1.0f;
        float fall_height = -1.0f;
        float fog_start = -1.0f;
        int fog_colour = -1;
    };

    // The cloud height as the file's 0 to 1: 0.5 the usual (1), 0 a sixteenth of it and 1 four times it.
    float height_from_unit(float v) {
        return (v < 0.5f) ? std::exp2((v - 0.5f) * 8.0f) : std::pow(4.0f, (v - 0.5f) * 2.0f);
    }
    float unit_from_height(float h) {
        h = std::clamp(h, 0.0625f, 4.0f);
        return (h < 1.0f) ? std::clamp(std::log2(h) / 8.0f + 0.5f, 0.0f, 1.0f) : std::clamp(std::log(h) / std::log(4.0f) / 2.0f + 0.5f, 0.0f, 1.0f);
    }

    std::map<uint16_t, Level> levels;
    std::filesystem::file_time_type file_time{};
    bool file_seen = false;
    int frames = 0;
    // Guards levels and current: tick() runs on the game thread, the save buttons on the pick worker's.
    std::mutex data_mutex;
    // What is showing now (the options with this level's line over them), for the save buttons.
    struct Current {
        bool valid = false;
        uint16_t map = 0;
        uint32_t cloud_type = 0;
        Shape shape{};
        float mist = 0.0f;
        float fog = 0.0f;
        uint32_t preset = 0;
        float offset = 0.0f;
        float water = 0.0f, water_height = 80.0f, fall = 0.0f, fall_height = 120.0f;
        float fog_start = 0.0f;
        uint32_t fog_colour = 0;
    } current;

    const char* const cloud_names[] = { "off", "fair", "scattered", "overcast", "stormy", "wispy", "sunset", "thunderstorm" };
    const char* const preset_names[] = { "default", "bright", "hell", "murky", "poison", "sponza", "pillar" };
    const char* const colour_names[] = { "preset", "haze", "mist", "dusk", "gloom" };

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
            else if (key == "fog_colour") {
                out.fog_colour = find(colour_names, std::size(colour_names), value);
                if (out.fog_colour < 0) {
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
            else if (key == "mist_water") { out.water = std::clamp(number / 100.0f, 0.0f, 1.0f); }
            else if (key == "mist_water_height") { out.water_height = std::clamp(number, 0.0f, 500.0f); }
            else if (key == "mist_fall") { out.fall = std::clamp(number / 100.0f, 0.0f, 1.0f); }
            else if (key == "mist_fall_height") { out.fall_height = std::clamp(number, 0.0f, 500.0f); }
            else if (key == "fog_start") { out.fog_start = std::clamp(number, 0.0f, 6000.0f); }
            else {
                return false;
            }
        }
        return true;
    }

    // The shape as the file's 0 to 100 values (the inverse of what tick() makes of them).
    Level level_of(const Current& c) {
        Level l;
        l.clouds = int(c.cloud_type);
        l.cover = std::clamp(c.shape.cover, 0.0f, 1.0f);
        l.height = unit_from_height(c.shape.height);
        l.thickness = std::clamp((c.shape.thickness - 0.2f) / 0.8f, 0.0f, 1.0f);
        l.speed = std::clamp(std::sqrt(std::max(c.shape.speed, 0.0f)) / 2.0f, 0.0f, 1.0f);
        l.mist = c.mist;
        l.fog = c.fog;
        l.preset = int(c.preset);
        l.mist_offset = c.offset;
        l.water = c.water;
        l.water_height = c.water_height;
        l.fall = c.fall;
        l.fall_height = c.fall_height;
        l.fog_start = c.fog_start;
        l.fog_colour = int(c.fog_colour);
        return l;
    }

    // The line for a level: only the settings it has (a key left out is whatever the options say).
    std::string line_of(uint16_t map, const Level& l) {
        char text[96];
        std::snprintf(text, sizeof(text), "0x%X", map);
        std::string out = text;
        const auto add = [&](const char* key, float value) {
            if (value >= 0.0f) {
                std::snprintf(text, sizeof(text), " %s=%.0f", key, value);
                out += text;
            }
        };
        if (l.clouds >= 0) { out += std::string(" clouds=") + cloud_names[std::clamp(l.clouds, 0, 7)]; }
        add("cover", l.cover * 100.0f);
        add("height", l.height * 100.0f);
        add("thickness", l.thickness * 100.0f);
        add("speed", l.speed * 100.0f);
        add("mist", l.mist * 100.0f);
        add("fog", l.fog * 100.0f);
        if (l.preset >= 0) { out += std::string(" fog_preset=") + preset_names[std::clamp(l.preset, 0, 6)]; }
        if (l.mist_offset != 0.0f) {
            std::snprintf(text, sizeof(text), " mist_offset=%.0f", l.mist_offset);
            out += text;
        }
        add("mist_water", l.water * 100.0f);
        add("mist_water_height", l.water_height);
        add("mist_fall", l.fall * 100.0f);
        add("mist_fall_height", l.fall_height);
        add("fog_start", l.fog_start);
        if (l.fog_colour >= 0) { out += std::string(" fog_colour=") + colour_names[std::clamp(l.fog_colour, 0, 4)]; }
        return out;
    }

    // Writes the level's line into volumetric.txt, replacing its old line and keeping the rest of the file as it was.
    bool save(uint16_t map, const Level& l) {
        std::vector<std::string> lines;
        {
            std::ifstream in(tooie::dev_files::read_path(file_name));
            std::string line;
            while (std::getline(in, line)) {
                lines.push_back(line);
            }
        }
        if (lines.empty()) {
            lines.push_back("# Volumetric mist, fog and clouds per level, written by Save Volumetric Settings (Controls > Volumetrics). See the format at the top of src/gameplay/volumetric.cpp:");
            lines.push_back("# map (hex), then clouds= cover= height= thickness= speed= (0 to 100) mist= fog= (0 to 100) fog_preset= mist_offset= mist_water= mist_water_height= mist_fall= mist_fall_height= fog_start= fog_colour=");
        }
        const std::string text = line_of(map, l);
        bool replaced = false;
        for (std::string& line : lines) {
            uint16_t m;
            Level old;
            if (read_line(line, m, old) && m == map) {
                line = text;
                replaced = true;
            }
        }
        if (!replaced) {
            lines.push_back(text);
        }
        std::error_code ec;
        std::filesystem::create_directories(tooie::dev_files::folder(), ec);
        std::ofstream out(tooie::dev_files::path(file_name), std::ios::trunc);
        for (const std::string& line : lines) {
            out << line << "\n";
        }
        return bool(out);
    }

    void write_template() {
        std::error_code ec;
        std::filesystem::create_directories(tooie::dev_files::folder(), ec);
        std::ofstream out(tooie::dev_files::path(file_name));
        out << "# Volumetric mist, fog and clouds per level (Graphics > WIP > Volumetrics). Read again whenever this file changes.\n"
               "# One level a line: map (hex), then any of these in any order. # starts a comment.\n"
               "#   clouds=off|fair|scattered|overcast|stormy|wispy|sunset|thunderstorm   the cloud type on this level\n"
               "#   cover= height= thickness= speed=   the cloud shape, 0 to 100 (50 the usual); left out, the type's own shape\n"
               "#   mist=0..100  fog=0..100  fog_preset=default|bright|hell|murky|poison|sponza|pillar\n"
               "#   mist_offset=<world units>   moves the mist's floor up (+) or down (-)\n"
               "#   mist_water=0..100 mist_water_height=<units>   mist hanging over water, and how high\n"
               "#   mist_fall=0..100 mist_fall_height=<units>   mist at a waterfall's foot, and how high\n"
               "#   fog_start=<units>  fog_colour=preset|haze|mist|dusk|gloom   as Graphics > Fog\n"
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
        0, 100, 1, 0, false, 0);
    graphics.add_number_option(
        mist_water_option,
        "Mist Over Water",
        "WIP. Mist that settles over lakes, ponds and the sea: a denser layer hanging just over the surface wherever there is water near what you look at. It is its own mist, on without the Volumetric Mist above. 0 turns it off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        mist_water_height_option,
        "Mist Over Water Height",
        "How high the mist over water hangs above the surface, in the game's units (Banjo is about 150 tall).",
        0, 500, 10, 0, false, 80);
    graphics.add_number_option(
        mist_fall_option,
        "Mist At Waterfalls",
        "WIP. Spray and mist that gathers where a waterfall lands, billowing up from its foot. It is its own mist, on without the Volumetric Mist above. 0 turns it off.",
        0, 100, 5, 0, false, 0);
    graphics.add_number_option(
        mist_fall_height_option,
        "Mist At Waterfalls Height",
        "How high the mist rises above the foot of a waterfall, in the game's units.",
        0, 500, 10, 0, false, 120);
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
    graphics.add_number_option(
        fog_start_option,
        "Volumetric Fog Start Distance",
        "How far from Banjo the fog begins, in the game's units (Banjo is about 150 tall), as Graphics > Fog. 0 has it from right in front of you.",
        0, 6000, 250, 0, false, 0);
    graphics.add_option_hidden_dependency(fog_start_option, fog_option, 0.0);
    graphics.add_enum_option(
        fog_colour_option,
        "Volumetric Fog Colour",
        "The fog's colour, as Graphics > Fog: Preset keeps the preset's own colour and glow, the others are Haze (pale blue), Mist (white), Dusk (warm orange) and Gloom (dark blue-grey).",
        {
            {FogColour::Preset, "Preset", "Preset"},
            {FogColour::Haze, "Haze", "Haze"},
            {FogColour::Mist, "Mist", "Mist"},
            {FogColour::Dusk, "Dusk", "Dusk"},
            {FogColour::Gloom, "Gloom", "Gloom"},
        },
        FogColour::Preset);
    graphics.add_option_hidden_dependency(fog_colour_option, fog_option, 0.0);
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
    graphics.add_number_option(
        cloud_amount_option,
        "Volumetric Cloud Amount",
        "How much of the sky the forced clouds cover. 50 is the type's own; lower is clearer, higher is more.",
        0, 100, 5, 0, false, 50);
    graphics.add_number_option(
        cloud_height_option,
        "Volumetric Cloud Height",
        "How high the cloud layer sits. 50 is the type's own; lower brings it down, to the horizon and into the scenery's edge at 0, higher raises it.",
        0, 100, 5, 0, false, 50);
    graphics.add_number_option(
        cloud_size_option,
        "Volumetric Cloud Size",
        "How thick the cloud layer is, so bigger, taller clouds. 50 is the type's own.",
        0, 100, 5, 0, false, 50);
    graphics.add_number_option(
        cloud_speed_option,
        "Volumetric Cloud Speed",
        "How fast the clouds drift and churn. 50 is the type's own; 0 holds them still.",
        0, 100, 5, 0, false, 50);
    for (const std::string* id : { &cloud_amount_option, &cloud_height_option, &cloud_size_option, &cloud_speed_option }) {
        graphics.add_option_hidden_dependency(*id, clouds_option, Clouds::Off);
    }
    graphics.add_bool_option(
        file_option,
        "Volumetric Level File",
        "Reads Dev Files/volumetric.txt (made the first time any volumetric option is on, or by the Save Volumetric Settings key in Controls > Volumetrics): per level mist, fog, cloud type and cloud shape that override the settings above, for the levels listed. Changes to the file apply within a second.",
        true);
    for (const std::string* id : { &mist_option, &mist_water_option, &mist_water_height_option, &mist_fall_option, &mist_fall_height_option,
            &fog_option, &fog_preset_option, &fog_start_option, &fog_colour_option, &clouds_option, &cloud_amount_option, &cloud_height_option,
            &cloud_size_option, &cloud_speed_option, &file_option }) {
        graphics.add_option_change_callback(*id,
            [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
                if (context == recomp::config::OptionChangeContext::Temporary) {
                    recompui::config::get_graphics_config().save_config();
                }
            });
    }
}

void tooie::volumetric::tick(uint8_t* rdram) {
    std::lock_guard lock{ data_mutex };
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
    // The Day and Night cycle's Mist (its Mist and Mist Time settings) is this same mist while the cycle runs.
    mist = std::max(mist, tooie::day_night::mist_amount());
    const bool use_file = flag(file_option, true);
    refresh((mist > 0.0f) || (fog > 0.0f) || (cloud_type > 0));

    // The cloud sliders (50 the type's own shape) over the type's shape.
    const auto shaped = [](uint32_t type) {
        Shape sh = type_shapes[std::min(type, 7u)];
        const float amount = number(cloud_amount_option, 50.0f);
        const float high = number(cloud_height_option, 50.0f);
        const float size = number(cloud_size_option, 50.0f);
        const float speed = number(cloud_speed_option, 50.0f);
        sh.cover = std::clamp(sh.cover + (amount - 50.0f) / 100.0f, 0.0f, 1.0f);
        sh.height = std::clamp(sh.height * std::exp2((high - 50.0f) / 12.5f), 0.0625f, 4.0f);
        sh.thickness = std::clamp(sh.thickness * std::exp2((size - 50.0f) / 25.0f), 0.1f, 2.0f);
        sh.speed = (speed <= 0.0f) ? 0.0f : std::clamp(sh.speed * std::exp2((speed - 50.0f) / 25.0f), 0.0f, 8.0f);
        return sh;
    };
    Shape shape = shaped(cloud_type);
    float offset = 0.0f;
    float water = number(mist_water_option, 0.0f) / 100.0f;
    float water_height = number(mist_water_height_option, 80.0f);
    float fall = number(mist_fall_option, 0.0f) / 100.0f;
    float fall_height = number(mist_fall_height_option, 120.0f);
    float fog_start = number(fog_start_option, 0.0f);
    uint32_t fog_colour = choice(fog_colour_option);
    // Test aid: TOOIE_VOL_EXTRA=<water mist 0-100>,<its height>,<fall mist 0-100>,<its height>,<fog start>,<fog colour 0-4>.
    if (const char* v = std::getenv("TOOIE_VOL_EXTRA")) {
        float w = 0.0f, wh = 80.0f, f = 0.0f, fh = 120.0f, fs = 0.0f;
        unsigned int fc = 0;
        std::sscanf(v, "%f,%f,%f,%f,%f,%u", &w, &wh, &f, &fh, &fs, &fc);
        water = w / 100.0f;
        water_height = wh;
        fall = f / 100.0f;
        fall_height = fh;
        fog_start = fs;
        fog_colour = fc;
    }
    if (use_file) {
        const auto found = levels.find(tooie::debug::current_map(rdram));
        if (found != levels.end()) {
            const Level& l = found->second;
            if (l.clouds >= 0) {
                cloud_type = uint32_t(l.clouds);
                shape = shaped(cloud_type);
            }
            if (l.mist >= 0.0f) { mist = l.mist; }
            if (l.fog >= 0.0f) { fog = l.fog; }
            if (l.preset >= 0) { preset = uint32_t(l.preset); }
            if (l.water >= 0.0f) { water = l.water; }
            if (l.water_height >= 0.0f) { water_height = l.water_height; }
            if (l.fall >= 0.0f) { fall = l.fall; }
            if (l.fall_height >= 0.0f) { fall_height = l.fall_height; }
            if (l.fog_start >= 0.0f) { fog_start = l.fog_start; }
            if (l.fog_colour >= 0) { fog_colour = uint32_t(l.fog_colour); }
            offset = l.mist_offset;
            // The cloud shape in the file's units (see level_of); the height as height_from_unit.
            if (l.cover >= 0.0f) { shape.cover = l.cover; }
            if (l.height >= 0.0f) { shape.height = height_from_unit(l.height); }
            if (l.thickness >= 0.0f) { shape.thickness = 0.2f + 0.8f * l.thickness; }
            if (l.speed >= 0.0f) { shape.speed = (l.speed * 2.0f) * (l.speed * 2.0f); }
        }
    }
    current = { true, tooie::debug::current_map(rdram), cloud_type, shape, mist, fog, preset, offset, water, water_height, fall, fall_height, fog_start, fog_colour };
    // The mist over water and at waterfalls draw in the same pass as the mist: a hair of ground mist keeps it running.
    const float mist_drawn = ((water > 0.0f) || (fall > 0.0f)) ? std::max(mist, 1.0f / 63.0f) : mist;
    RT64::SetSceneVolumetric(mist_drawn, fog, preset, cloud_type, offset);
    RT64::SetSceneVolumetricExtra(fog_start, fog_colour, water, water_height, fall, fall_height);
    // Forced clouds take the shape over from the Day and Night cycle's (whose tick has already run this frame).
    if (cloud_type > 0) {
        RT64::SetSceneClouds(shape.cover, shape.height, shape.thickness, shape.speed);
    }
}

const char* tooie::volumetric::setting_name(int setting) {
    static const char* names[setting_count] = { "Cloud Type", "Cloud Shape", "Mist", "Fog", "Fog Look" };
    return (setting >= 0 && setting < setting_count) ? names[setting] : "";
}

namespace {
    // Whether this level's line already has the setting as it is showing.
    bool saved_locked(int setting) {
        const auto found = levels.find(current.map);
        if (found == levels.end()) {
            return false;
        }
        const Level& have = found->second;
        const Level now = level_of(current);
        const auto same = [](float a, float b) { return (a >= 0.0f) && (std::fabs(a - b) < 0.011f); };
        switch (setting) {
        case 0: return have.clouds == now.clouds;
        case 1: return same(have.cover, now.cover) && same(have.height, now.height) && same(have.thickness, now.thickness) && same(have.speed, now.speed);
        case 2: return same(have.mist, now.mist) && (std::fabs(have.mist_offset - now.mist_offset) < 0.5f) && same(have.water, now.water) &&
            same(have.fall, now.fall) && (std::fabs(have.water_height - now.water_height) < 0.5f) && (std::fabs(have.fall_height - now.fall_height) < 0.5f);
        case 3: return same(have.fog, now.fog) && (std::fabs(have.fog_start - now.fog_start) < 0.5f);
        case 4: return (have.preset == now.preset) && (have.fog_colour == now.fog_colour);
        }
        return false;
    }
}

bool tooie::volumetric::setting_unsaved(int setting) {
    std::lock_guard lock{ data_mutex };
    return current.valid && !saved_locked(setting);
}

bool tooie::volumetric::save_setting(int setting) {
    std::lock_guard lock{ data_mutex };
    if (!current.valid) {
        return false;
    }
    const Level now = level_of(current);
    Level l = now;
    if (setting >= 0) {
        // Only this setting: the rest of the level's line stays as it was (or unset).
        const auto found = levels.find(current.map);
        l = (found != levels.end()) ? found->second : Level();
        switch (setting) {
        case 0: l.clouds = now.clouds; break;
        case 1: l.cover = now.cover; l.height = now.height; l.thickness = now.thickness; l.speed = now.speed; break;
        case 2: l.mist = now.mist; l.mist_offset = now.mist_offset; l.water = now.water; l.water_height = now.water_height;
            l.fall = now.fall; l.fall_height = now.fall_height; break;
        case 3: l.fog = now.fog; l.fog_start = now.fog_start; break;
        case 4: l.preset = now.preset; l.fog_colour = now.fog_colour; break;
        default: return false;
        }
    }
    char text[160];
    if (save(current.map, l)) {
        levels[current.map] = l;
        std::error_code ec;
        file_time = std::filesystem::last_write_time(tooie::dev_files::read_path(file_name), ec);
        fprintf(stderr, "[volumetric] saved %s for map 0x%X: %s\n", setting < 0 ? "all" : setting_name(setting), current.map, line_of(current.map, l).c_str());
        std::snprintf(text, sizeof(text), "Saved %s for map 0x%X to volumetric.txt", setting < 0 ? "all volumetric settings" : setting_name(setting), current.map);
        tooie::toast::show(text);
        return true;
    }
    tooie::toast::show("Could not write volumetric.txt in the Dev Files folder");
    return false;
}
