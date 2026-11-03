// Point Lights (WIP tab): see include/tooie_point_lights.h and docs/point-lights.md.
//
// Banjo-Tooie lights its vertices itself on the CPU and draws nothing with the N64's hardware lighting, so the lamps
// light the finished picture per pixel in RT64's scene effects pass (rt64-ext rt64_scene_lights.h, SceneEffectsPS.hlsl
// PointLampsAt), every frame. The lamps are the lit lamps RT64 finds by their textures, and the
// level's own list here: Dev Files/point_lights.txt, one lamp a line, "<map hex> x y z r g b radius" (world units,
// colour 0 to 255; # starts a comment), placed with the console's lights command at Banjo.

#include <algorithm>
#include <atomic>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <mutex>
#include <sstream>
#include <variant>

#include "recompui/config.h"

#include "tooie_debug.h"
#include "tooie_dev_files.h"
#include "tooie_player_cheats.h"
#include "tooie_point_lights.h"
#include "tooie_rdram.h"

namespace RT64 {
    // rt64-ext/src/render/rt64_scene_lights.h.
    struct ScenePointLamp {
        float x, y, z;
        float radius;
        float r, g, b;
    };
    void SetScenePointLights(bool enabled, float strength);
    void SetScenePointLamps(const ScenePointLamp* lamps, uint32_t count, const float camera[3]);
}

namespace {
    constexpr const char* file_name = "point_lights.txt";
    // Points at the camera, its position first (src/game/widescreen.cpp).
    constexpr uint32_t camera_ptr = 0x8012D500u;

    struct Lamp {
        uint16_t map;
        float x, y, z;
        int r, g, b;
        float radius;
    };

    std::mutex lamps_mutex;
    std::vector<Lamp> lamps;
    bool loaded = false;
    std::filesystem::file_time_type loaded_time{};

    float number(const std::string& id, float fallback) {
        try {
            return float(std::get<double>(recompui::config::get_config(recompui::config::graphics::id).get_option_value(id)));
        } catch (...) {
            return fallback;
        }
    }

    bool flag(const std::string& id) {
        try {
            return std::get<bool>(recompui::config::get_config(recompui::config::graphics::id).get_option_value(id));
        } catch (...) {
            return false;
        }
    }

    // The list, read again whenever the file changes (lamps_mutex held).
    void load() {
        std::error_code ec;
        const std::filesystem::path path = tooie::dev_files::read_path(file_name);
        const auto time = std::filesystem::last_write_time(path, ec);
        if (loaded && (ec ? std::filesystem::file_time_type{} : time) == loaded_time) {
            return;
        }
        loaded = true;
        loaded_time = ec ? std::filesystem::file_time_type{} : time;
        lamps.clear();
        std::ifstream in(path);
        std::string line;
        while (std::getline(in, line)) {
            const size_t hash = line.find('#');
            if (hash != std::string::npos) {
                line.resize(hash);
            }
            std::istringstream words(line);
            std::string map;
            Lamp lamp{};
            if (words >> map >> lamp.x >> lamp.y >> lamp.z >> lamp.r >> lamp.g >> lamp.b >> lamp.radius) {
                lamp.map = uint16_t(std::strtoul(map.c_str(), nullptr, 16));
                lamp.r = std::clamp(lamp.r, 0, 255);
                lamp.g = std::clamp(lamp.g, 0, 255);
                lamp.b = std::clamp(lamp.b, 0, 255);
                lamp.radius = std::max(lamp.radius, 1.0f);
                lamps.push_back(lamp);
            }
        }
    }

    bool save() {
        std::error_code ec;
        std::filesystem::create_directories(tooie::dev_files::folder(), ec);
        std::ofstream out(tooie::dev_files::path(file_name), std::ios::trunc);
        out << "# Point Lights (Graphics > WIP): <map hex> x y z r g b radius, one lamp a line (docs/point-lights.md).\n";
        for (const Lamp& l : lamps) {
            char text[160];
            std::snprintf(text, sizeof(text), "%X %.1f %.1f %.1f %d %d %d %.0f\n", l.map, l.x, l.y, l.z, l.r, l.g, l.b, l.radius);
            out << text;
        }
        out.close();
        loaded_time = std::filesystem::last_write_time(tooie::dev_files::path(file_name), ec);
        return bool(out);
    }

    // TOOIE_POINT_LIGHTS=<strength %> turns them on whatever the settings say (headless tests).
    float forced_strength() {
        static const char* forced = std::getenv("TOOIE_POINT_LIGHTS");
        return (forced != nullptr) ? float(std::atof(forced)) : -1.0f;
    }
}

void tooie::point_lights::add_options(recomp::config::Config& graphics) {
    graphics.add_bool_option(
        option,
        "Point Lights",
        "WIP. Lamps light what is near them: the walls, floors, Banjo and the rest brighten as they get closer to a lit lamp, worked out every frame on top of the light the game gives them. The lamps are the lit lamps found by their textures and the ones placed with the console's lights command. Applies at once.",
        false);
    graphics.add_number_option(
        strength_option,
        "Point Lights Strength",
        "How bright the lamps' light is, in percent.",
        10, 200, 5, 0, false, 50);
    graphics.add_option_hidden_dependency(strength_option, option, false);
    for (const std::string* id : { &option, &strength_option }) {
        graphics.add_option_change_callback(*id,
            [](recomp::config::ConfigValueVariant, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
                if (context == recomp::config::OptionChangeContext::Temporary) {
                    recompui::config::get_graphics_config().save_config();
                }
            });
    }
}

void tooie::point_lights::tick(uint8_t* rdram) {
    const float forced = forced_strength();
    const bool on = (forced >= 0.0f) ? (forced > 0.0f) : flag(option);
    const float strength = ((forced >= 0.0f) ? forced : number(strength_option, 50.0f)) / 100.0f;
    RT64::SetScenePointLights(on, strength);
    if (!on) {
        return;
    }

    float camera[3] = {};
    const uint32_t camera_at = tooie::rdram::read_word(rdram, camera_ptr);
    if (tooie::rdram::valid_ptr(camera_at)) {
        for (uint32_t axis = 0; axis < 3; axis++) {
            camera[axis] = tooie::rdram::read_float(rdram, camera_at + 4 * axis);
        }
    }

    const uint16_t map = tooie::debug::current_map(rdram);
    std::vector<RT64::ScenePointLamp> here;
    {
        std::lock_guard lock{ lamps_mutex };
        // The file is checked about once a second, not every frame.
        static int frames = 0;
        if (!loaded || (++frames % 60) == 0) {
            load();
        }
        for (const Lamp& l : lamps) {
            if (l.map == map) {
                here.push_back({ l.x, l.y, l.z, l.radius, l.r / 255.0f, l.g / 255.0f, l.b / 255.0f });
            }
        }
    }
    RT64::SetScenePointLamps(here.data(), uint32_t(here.size()), camera);
}

std::string tooie::point_lights::console(uint8_t* rdram, const std::vector<std::string>& args) {
    std::lock_guard lock{ lamps_mutex };
    load();
    const uint16_t map = tooie::debug::current_map(rdram);
    const std::string cmd = args.empty() ? "" : args[0];
    std::ostringstream out;
    auto here = [&]() { return std::count_if(lamps.begin(), lamps.end(), [&](const Lamp& l) { return l.map == map; }); };
    if (cmd == "add") {
        float p[3];
        if (!tooie::player_cheats::position(rdram, p)) {
            return "ERR lights add: there is no player yet";
        }
        Lamp lamp{ map, p[0], p[1], p[2], 255, 190, 110, 500.0f };
        const float height = (args.size() > 5) ? float(std::atof(args[5].c_str())) : 80.0f;
        lamp.y += height;
        if (args.size() > 3) {
            lamp.r = std::clamp(std::atoi(args[1].c_str()), 0, 255);
            lamp.g = std::clamp(std::atoi(args[2].c_str()), 0, 255);
            lamp.b = std::clamp(std::atoi(args[3].c_str()), 0, 255);
        }
        if (args.size() > 4) {
            lamp.radius = std::max(float(std::atof(args[4].c_str())), 1.0f);
        }
        lamps.push_back(lamp);
        save();
        char text[160];
        std::snprintf(text, sizeof(text), "added a lamp at %.0f %.0f %.0f, colour %d %d %d, radius %.0f (saved)\n", lamp.x, lamp.y, lamp.z, lamp.r, lamp.g, lamp.b, lamp.radius);
        out << text;
    } else if (cmd == "undo") {
        for (auto it = lamps.rbegin(); it != lamps.rend(); ++it) {
            if (it->map == map) {
                lamps.erase(std::next(it).base());
                break;
            }
        }
        save();
        out << "removed this map's last lamp (saved)\n";
    } else if (cmd == "clear") {
        lamps.erase(std::remove_if(lamps.begin(), lamps.end(), [&](const Lamp& l) { return l.map == map; }), lamps.end());
        save();
        out << "removed this map's lamps (saved)\n";
    } else if (cmd == "list") {
        for (const Lamp& l : lamps) {
            if (l.map == map) {
                char text[160];
                std::snprintf(text, sizeof(text), "  %.0f %.0f %.0f  colour %d %d %d  radius %.0f\n", l.x, l.y, l.z, l.r, l.g, l.b, l.radius);
                out << text;
            }
        }
    } else if (!cmd.empty()) {
        return "ERR lights [add [r g b [radius [height]]] | undo | clear | list]";
    }
    char text[160];
    std::snprintf(text, sizeof(text), "Point Lights %s, map 0x%X: %d lamp(s) in Dev Files/%s", flag(option) ? "on" : "off", map, int(here()), file_name);
    out << text;
    return out.str();
}
