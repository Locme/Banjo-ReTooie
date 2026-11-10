// Moving the sun by hand (L, 2026-10-22): see include/tooie_sun_control.h.
//
// The sun is kept as a compass angle (azimuth: 0 towards +z, 90 towards +x) and a height above the horizon
// (elevation), per map. day_night.cpp asks map_sun() before its own table, so a moved or saved sun is what the sun
// shadows, the traced light, the sky's sun and HD shadows use, and the Day and Night cycle leans its path towards it.
// sun.txt (Dev Files) has one map a line: "0xAF 150.0 40.0" (map in hex, azimuth, elevation, in degrees); # starts
// a comment.

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <map>
#include <mutex>
#include <sstream>
#include <string>
#include <vector>

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include "recompinput/recompinput.h"

#include "tooie_dev_files.h"
#include "tooie_game_frame_rate.h"
#include "tooie_hotkeys.h"
#include "tooie_sun_control.h"
#include "tooie_toast.h"

namespace {
    constexpr const char* file_name = "sun.txt";
    constexpr float pi = 3.14159265f;
    // Lower than this the snow's light and the sun shadows give up on the sun (it needs y above 0.15).
    constexpr float lowest_elevation = 9.0f;

    struct Sun {
        float azimuth;
        float elevation;
    };

    std::mutex mutex;
    // Moved by hand this session, and read from sun.txt. A moved sun wins.
    std::map<uint16_t, Sun> moved;
    std::map<uint16_t, Sun> saved;
    bool loaded = false;
    // Set by the console's sun commands, so the next tick sends the sun again.
    bool console_changed = false;

    void to_vector(const Sun& s, float out[3]) {
        const float az = s.azimuth * pi / 180.0f;
        const float el = s.elevation * pi / 180.0f;
        out[0] = std::cos(el) * std::sin(az);
        out[1] = std::sin(el);
        out[2] = std::cos(el) * std::cos(az);
    }

    Sun from_vector(const float v[3]) {
        const float length = std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
        if (length < 1e-6f) {
            return { 0.0f, 90.0f };
        }
        Sun s;
        s.azimuth = std::atan2(v[0], v[2]) * 180.0f / pi;
        if (s.azimuth < 0.0f) {
            s.azimuth += 360.0f;
        }
        s.elevation = std::asin(std::clamp(v[1] / length, -1.0f, 1.0f)) * 180.0f / pi;
        return s;
    }

    Sun clamped(Sun s) {
        s.azimuth = std::fmod(s.azimuth, 360.0f);
        if (s.azimuth < 0.0f) {
            s.azimuth += 360.0f;
        }
        s.elevation = std::clamp(s.elevation, lowest_elevation, 90.0f);
        return s;
    }

    // One "map azimuth elevation" line, false for a comment, a blank line or one that doesn't read.
    bool read_line(const std::string& line, uint16_t& map, Sun& s) {
        const std::string text = line.substr(0, line.find('#'));
        unsigned int m = 0;
        if (std::sscanf(text.c_str(), "%x %f %f", &m, &s.azimuth, &s.elevation) != 3 || m > 0xFFFF) {
            return false;
        }
        map = uint16_t(m);
        s = clamped(s);
        return true;
    }

    void load() {
        if (loaded) {
            return;
        }
        loaded = true;
        std::ifstream in(tooie::dev_files::read_path(file_name));
        std::string line;
        int count = 0;
        while (std::getline(in, line)) {
            uint16_t map;
            Sun s;
            if (read_line(line, map, s)) {
                saved[map] = s;
                count++;
            }
            else if (line.find_first_not_of(" \t\r") != std::string::npos && line.find_first_not_of(" \t\r") != line.find('#')) {
                fprintf(stderr, "[sun] skipped a line of sun.txt: %s\n", line.c_str());
            }
        }
        if (count > 0) {
            fprintf(stderr, "[sun] read %d map(s) from sun.txt\n", count);
        }
    }

    // Writes the map's sun into sun.txt, replacing its line if it has one and keeping the rest as it was.
    bool save(uint16_t map, const Sun& s) {
        std::vector<std::string> lines;
        {
            std::ifstream in(tooie::dev_files::read_path(file_name));
            std::string line;
            while (std::getline(in, line)) {
                lines.push_back(line);
            }
        }
        if (lines.empty()) {
            lines.push_back("# The sun per map, from Move Sun and Save Sun Location (Controls > Ray Trace Debug).");
            lines.push_back("# map (hex)  azimuth (0 = +z, 90 = +x)  elevation (degrees above the horizon)");
        }
        char text[64];
        std::snprintf(text, sizeof(text), "0x%X %.1f %.1f", map, s.azimuth, s.elevation);
        bool replaced = false;
        for (std::string& line : lines) {
            uint16_t m;
            Sun old;
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

    // Test aid: TOOIE_SUN_SCRIPT=<ms>:<what>[;...], ms of game time (as TOOIE_SCREENSHOT_GAME counts), what = az<+-degrees>, el<+-degrees> or
    // save. Moves the sun as the key and wheel would.
    struct Step {
        int64_t at;
        std::string what;
    };

    std::vector<Step> read_script() {
        std::vector<Step> steps;
        const char* v = std::getenv("TOOIE_SUN_SCRIPT");
        if (v == nullptr) {
            return steps;
        }
        std::stringstream all(v);
        std::string item;
        while (std::getline(all, item, ';')) {
            const size_t colon = item.find(':');
            if (colon != std::string::npos) {
                steps.push_back({ std::atoll(item.substr(0, colon).c_str()), item.substr(colon + 1) });
            }
        }
        return steps;
    }
}

bool tooie::sun_control::tick(uint16_t map, const float start[3]) {
    static bool move_was_down = false;
    static bool save_was_down = false;
    static int32_t wheel_was = recompinput::get_mouse_wheel_pos();
    static std::vector<Step> script = read_script();

    const bool move_down = tooie::hotkeys::down(recompinput::GameInput::SUN_MOVE);
    const bool save_down = tooie::hotkeys::down(recompinput::GameInput::SUN_SAVE);
    const bool save_pressed = save_down && !save_was_down;
    save_was_down = save_down;
    if (move_down && !move_was_down) {
        char text[128];
        std::snprintf(text, sizeof(text), "Move Sun (map 0x%X): wheel turns it round, Ctrl + wheel raises or lowers it, Shift for fine steps", map);
        tooie::toast::show(text);
        fprintf(stderr, "[sun] Move Sun held on map 0x%X\n", map);
    }
    move_was_down = move_down;

    // Wheel notches since the last frame, only used while Move Sun is held.
    const int32_t wheel = recompinput::get_mouse_wheel_pos();
    const int32_t notches = wheel - wheel_was;
    wheel_was = wheel;
    float turn = 0.0f, raise = 0.0f;
    if (move_down && notches != 0) {
        const SDL_Keymod mods = SDL_GetModState();
        const bool fine = (mods & KMOD_SHIFT) != 0;
        if ((mods & KMOD_CTRL) != 0) {
            raise = float(notches) * (fine ? 0.5f : 2.0f);
        }
        else {
            turn = float(notches) * (fine ? 1.0f : 5.0f);
        }
    }
    bool script_save = false;
    const int64_t ms = int64_t(tooie::game_frame_rate::game_ms());
    while (!script.empty() && script.front().at <= ms) {
        const std::string& what = script.front().what;
        if (what.compare(0, 2, "az") == 0) {
            turn += float(std::atof(what.c_str() + 2));
        }
        else if (what.compare(0, 2, "el") == 0) {
            raise += float(std::atof(what.c_str() + 2));
        }
        else if (what == "save") {
            script_save = true;
        }
        script.erase(script.begin());
    }

    std::lock_guard lock{ mutex };
    load();
    bool changed = console_changed;
    console_changed = false;
    if (turn != 0.0f || raise != 0.0f) {
        Sun s;
        if (auto it = moved.find(map); it != moved.end()) {
            s = it->second;
        }
        else if (auto it = saved.find(map); it != saved.end()) {
            s = it->second;
        }
        else {
            s = from_vector(start);
        }
        s.azimuth += turn;
        s.elevation += raise;
        s = clamped(s);
        moved[map] = s;
        changed = true;
        fprintf(stderr, "[sun] map 0x%X az %.1f el %.1f\n", map, s.azimuth, s.elevation);
        char text[96];
        std::snprintf(text, sizeof(text), "Sun: %.0f\xC2\xB0 round, %.0f\xC2\xB0 high (not saved)", s.azimuth, s.elevation);
        tooie::toast::show(text);
    }
    if (save_pressed || script_save) {
        Sun s;
        bool have = true;
        if (auto it = moved.find(map); it != moved.end()) {
            s = it->second;
        }
        else if (auto it = saved.find(map); it != saved.end()) {
            s = it->second;
        }
        else {
            have = false;
        }
        if (!have) {
            tooie::toast::show("Save Sun Location: move the sun first (hold Move Sun and turn the wheel)");
        }
        else if (save(map, s)) {
            saved[map] = s;
            fprintf(stderr, "[sun] saved map 0x%X az %.1f el %.1f to sun.txt\n", map, s.azimuth, s.elevation);
            char text[96];
            std::snprintf(text, sizeof(text), "Sun saved to sun.txt: map 0x%X, %.0f\xC2\xB0 round, %.0f\xC2\xB0 high", map, s.azimuth, s.elevation);
            tooie::toast::show(text);
        }
        else {
            fprintf(stderr, "[sun] could not write sun.txt\n");
            tooie::toast::show("Could not write sun.txt in the Dev Files folder");
        }
    }
    return changed;
}

bool tooie::sun_control::map_sun(uint16_t map, float out[3]) {
    std::lock_guard lock{ mutex };
    load();
    if (auto it = moved.find(map); it != moved.end()) {
        to_vector(it->second, out);
        return true;
    }
    if (auto it = saved.find(map); it != saved.end()) {
        to_vector(it->second, out);
        return true;
    }
    return false;
}

void tooie::sun_control::set(uint16_t map, float azimuth, float elevation) {
    std::lock_guard lock{ mutex };
    load();
    moved[map] = clamped({ azimuth, elevation });
    console_changed = true;
}

bool tooie::sun_control::save(uint16_t map) {
    std::lock_guard lock{ mutex };
    load();
    Sun s;
    if (auto it = moved.find(map); it != moved.end()) {
        s = it->second;
    }
    else if (auto it = saved.find(map); it != saved.end()) {
        s = it->second;
    }
    else {
        return false;
    }
    if (!::save(map, s)) {
        return false;
    }
    saved[map] = s;
    fprintf(stderr, "[sun] saved map 0x%X az %.1f el %.1f to sun.txt\n", map, s.azimuth, s.elevation);
    return true;
}

void tooie::sun_control::clear(uint16_t map) {
    std::lock_guard lock{ mutex };
    load();
    moved.erase(map);
    console_changed = true;
}

bool tooie::sun_control::get(uint16_t map, float& azimuth, float& elevation, bool& moved_by_hand) {
    std::lock_guard lock{ mutex };
    load();
    const Sun* s = nullptr;
    if (auto it = moved.find(map); it != moved.end()) {
        s = &it->second;
        moved_by_hand = true;
    }
    else if (auto it = saved.find(map); it != saved.end()) {
        s = &it->second;
        moved_by_hand = false;
    }
    if (s == nullptr) {
        return false;
    }
    azimuth = s->azimuth;
    elevation = s->elevation;
    return true;
}
