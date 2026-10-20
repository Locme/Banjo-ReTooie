// Day and night cycle, Graphics tab, off by default.
//
// Banjo-Tooie has no time of day: each level is lit once, in its vertex colours. In the levels
// that are plainly daytime under an open sky, the cycle tints the 3D world (not the HUD) in RT64's
// scene effects pass: warm at sunrise and sunset, dark blue at night with the brightest parts (lamps,
// lava, glowing things) kept bright, and the sky darkens to a night sky with stars and a moon. The
// sun moves across the sky with the time of day; the light shafts follow it, and other features can
// read it with tooie::day_night::sun_direction (HD shadows). Indoor rooms, underwater areas and the
// levels that are already night (Witchyworld, Cauldron Keep) keep their own look. The clock runs on
// game time, so it stops while the game does.

#include <algorithm>
#include <atomic>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iterator>
#include <mutex>
#include <utility>
#include <variant>

#include "recomp.h"
#include "recompui/config.h"
#include "tooie_day_night.h"
#include "tooie_debug.h"
#include "tooie_game_frame_rate.h"
#include "tooie_picture_filters.h"

namespace RT64 {
    // lib/rt64/src/render/rt64_scene_effects.h.
    void SetSceneTimeOfDay(bool enabled, const float tint[3], float shafts, bool flare, bool fireflies, bool clouds);
    void SetSceneSun(bool custom, float x, float y, float z);
    void SetSceneWeather(float rain, float flash, bool snow);
    void SetSceneMist(float strength, uint32_t when);
    void SetSceneRainDetail(float wet, bool drops);
    void SetSceneClouds(float cover, float height, float thickness, float speed);
    void SetSceneMoonPhase(uint32_t phase);
    void SetSceneAurora(bool enabled);
    void SetSceneNightLights(const uint64_t* hashes, size_t count);
}

namespace {
    // The maps that cycle: daytime under an open sky in the original.
    constexpr uint16_t cycling_maps[] = {
        0xAF,   // Spiral Mountain
        0x142,  // Jinjo Village
        0x14F,  // Isle o' Hags: Wooded Hollow
        0x152,  // Plateau
        0x154,  // Pine Grove
        0x155,  // Cliff Top
        0x15A,  // Wasteland
        0x15C,  // Quagmire
        0xB8,   // Mayahem Temple
        0xC4,   // Mayahem Temple: Jade Snake Grove
        0x1A7,  // Jolly Roger's Lagoon (the town)
        0x112,  // Terrydactyland
        0x11A,  // Terrydactyland: Stomping Plains
        0x127,  // Hailfire Peaks: Lava Side
        0x128,  // Hailfire Peaks: Icy Side
        0x136,  // Cloud Cuckooland
    };

    // Windows and lamps that light up warm at night (their RT64 texture hashes, from a texture dump of the cycling
    // levels). Only the lighter parts of each light up (the glass, not the wooden frame).
    constexpr uint64_t night_light_textures[] = {
        0x0f160fc97318b755, 0xfe7ebd28c377b54f, 0x6f59260c143a2e31, // a pair of rounded windows, with its smaller copies
        0xc232f2ff08279dce, // a window of four panes in a wooden frame
        0x861bfb5c8890c6e0, // a lit window of four panes, on a stone sill
        0x49d8dc4266c7a1c2, // a latticed window
        0xf2b985d6790d2a85, 0x82b9c2031fef595f, 0xe11c75383d80e7b0, 0xbcae94b32238dd3d, // pale glass behind wooden crosses
    };

    // A time of day: the colour the 3D world is multiplied by. RT64 works out the rest from it: the sky darkens
    // more (to stars and the moon when it is dark blue) and glows round the sun when it is warm.
    struct Look {
        float t;
        float tint[3];
    };
    // From midnight (0) round to the next midnight (1); noon is 0.5. Days are longer than nights.
    constexpr Look looks[] = {
        { 0.00f, { 0.38f, 0.44f, 0.68f } },
        { 0.20f, { 0.38f, 0.44f, 0.68f } },
        { 0.25f, { 0.82f, 0.62f, 0.64f } },
        // Golden hour: warm light for a while after sunrise and before sunset.
        { 0.30f, { 1.00f, 0.88f, 0.72f } },
        { 0.34f, { 1.00f, 0.94f, 0.84f } },
        { 0.40f, { 1.00f, 1.00f, 1.00f } },
        { 0.60f, { 1.00f, 1.00f, 1.00f } },
        { 0.65f, { 1.00f, 0.92f, 0.78f } },
        { 0.69f, { 1.00f, 0.84f, 0.64f } },
        { 0.72f, { 1.00f, 0.74f, 0.52f } },
        { 0.77f, { 0.56f, 0.46f, 0.66f } },
        { 0.82f, { 0.38f, 0.44f, 0.68f } },
        { 1.00f, { 0.38f, 0.44f, 0.68f } },
    };

    // Where the sun stands in a level while the cycle is off: a unit vector towards it. The cycle's path is turned
    // so its noon sun stands the same way, as high. Maps not listed keep RT64's own sun (fairly low, to one side)
    // and the cycle's usual path (rising in the east, leaning a little to the south).
    struct MapSun {
        uint16_t map;
        float towards[3];
    };
    constexpr MapSun map_suns[] = {
        // Spiral Mountain: high over the mountain seen from Banjo's house, so the sunlight falls on the house (L).
        { 0xAF, { -0.56f, 0.66f, -0.50f } },
    };

    // The map's own sun, false if it has none. Test aid: TOOIE_MAP_SUN=<x>,<y>,<z> gives every map that one.
    bool map_sun(uint16_t map, float out[3]) {
        if (const char* v = std::getenv("TOOIE_MAP_SUN")) {
            if (sscanf(v, "%f,%f,%f", &out[0], &out[1], &out[2]) == 3) {
                return true;
            }
        }
        for (const MapSun& s : map_suns) {
            if (s.map == map) {
                std::copy(std::begin(s.towards), std::end(s.towards), out);
                return true;
            }
        }
        return false;
    }

    // Held times for the fixed modes.
    constexpr float morning_time = 0.31f;

    float held_time(tooie::day_night::Mode m) {
        using tooie::day_night::Mode;
        switch (m) {
            case Mode::Dawn: return 0.25f;
            case Mode::Morning: return morning_time;
            case Mode::Noon: return 0.5f;
            case Mode::Afternoon: return 0.63f;
            case Mode::GoldenHour: return 0.68f;
            case Mode::Sunset: return 0.72f;
            case Mode::Dusk: return 0.75f;
            case Mode::Night: return 0.0f;
            default: return morning_time;
        }
    }

    std::mutex mutex;
    bool active = false;
    float sun[3] = { 0.0f, 1.0f, 0.0f };

    // The running clock, from morning when the game starts. Test aid: TOOIE_TIME_OF_DAY=<0 to 1> starts there.
    double day_clock = std::getenv("TOOIE_TIME_OF_DAY") ? std::atof(std::getenv("TOOIE_TIME_OF_DAY")) : morning_time;
    uint32_t last_ms = 0;
    bool had_ms = false;
    // Whole days gone by with Cycle, for the moon's phase.
    uint32_t days = 0;
    // How far the look has come in, 0 to 1, so it eases in and out when the option changes.
    float amount = 0.0f;
    bool sent_off = false;

    tooie::day_night::Mode mode() {
        // Test aid: TOOIE_DAY_NIGHT=<0 Off, 1 Cycle, 2 Morning, 3 Sunset, 4 Night, 5 Dawn, 6 Noon, 7 Afternoon,
        // 8 Golden Hour, 9 Dusk> whatever the setting says.
        if (const char* v = std::getenv("TOOIE_DAY_NIGHT")) {
            return static_cast<tooie::day_night::Mode>(std::atoi(v));
        }
        try {
            return static_cast<tooie::day_night::Mode>(std::get<uint32_t>(
                recompui::config::get_config(recompui::config::graphics::id).get_option_value(tooie::day_night::option)));
        } catch (...) {
            return tooie::day_night::Mode::Off;
        }
    }

    double day_minutes() {
        // Test aid: TOOIE_DAY_LENGTH=<minutes>, below the menu's lowest, to run a whole day quickly.
        if (const char* v = std::getenv("TOOIE_DAY_LENGTH")) {
            return std::max(std::atof(v), 0.05);
        }
        try {
            return std::max(std::get<double>(
                recompui::config::get_config(recompui::config::graphics::id).get_option_value(tooie::day_night::length_option)), 1.0);
        } catch (...) {
            return 24.0;
        }
    }

    bool option_on(const std::string& id) {
        try {
            return std::get<bool>(recompui::config::get_config(recompui::config::graphics::id).get_option_value(id));
        } catch (...) {
            return true;
        }
    }

    // A 0 to 100 setting as 0 to 1 (50 when it can't be read).
    float option_fraction(const std::string& id) {
        try {
            return (float)std::clamp(std::get<double>(recompui::config::get_config(recompui::config::graphics::id).get_option_value(id)) / 100.0, 0.0, 1.0);
        } catch (...) {
            return 0.5f;
        }
    }

    // The mist's strength (0 to 1) and when it shows. Test aid: TOOIE_MIST=<0 to 100>,<0 mornings, 1 and nights, 2 always>.
    std::pair<float, uint32_t> mist_setting() {
        if (const char* v = std::getenv("TOOIE_MIST")) {
            float strength = 50.0f;
            uint32_t when = 0;
            sscanf(v, "%f,%u", &strength, &when);
            return { strength / 100.0f, when };
        }
        try {
            auto& config = recompui::config::get_config(recompui::config::graphics::id);
            return { (float)(std::get<double>(config.get_option_value(tooie::day_night::mist_option)) / 100.0),
                std::get<uint32_t>(config.get_option_value(tooie::day_night::mist_time_option)) };
        } catch (...) {
            return { 0.5f, 0 };
        }
    }

    tooie::day_night::Weather weather_setting() {
        // Test aid: TOOIE_WEATHER=<0 Clear, 1 Changing, 2 Rain, 3 Storm> whatever the setting says.
        if (const char* v = std::getenv("TOOIE_WEATHER")) {
            return static_cast<tooie::day_night::Weather>(std::atoi(v));
        }
        try {
            return static_cast<tooie::day_night::Weather>(std::get<uint32_t>(
                recompui::config::get_config(recompui::config::graphics::id).get_option_value(tooie::day_night::weather_option)));
        } catch (...) {
            return tooie::day_night::Weather::Changing;
        }
    }

    // The weather, on game time. Changing: clear, rain or a storm for a few minutes of play at a time.
    struct WeatherState {
        uint32_t seed = 0x2545F491u;
        uint32_t next_change_ms = 0;
        bool started = false;
        float target = 0.0f; // the rain it is heading to
        bool storm = false;
        float rain = 0.0f;   // the rain now, 0 to 1
        uint32_t flash_ms = 0;
        bool flashing = false;
        uint32_t next_flash_ms = 0;

        float random01() {
            seed ^= seed << 13;
            seed ^= seed >> 17;
            seed ^= seed << 5;
            return (seed >> 8) * (1.0f / 16777216.0f);
        }
    };
    WeatherState weather;

    // The lightning's brightness ms after it struck: a flash, a flicker, a second flash that fades.
    float flash_at(uint32_t ms) {
        if (ms < 70) {
            return 1.0f;
        }
        if (ms < 140) {
            return 0.25f;
        }
        if (ms < 220) {
            return 0.85f;
        }
        return 0.85f * std::exp(-(float)(ms - 220) / 180.0f);
    }

    // Moves the weather on (ms of game time, dt seconds of it) and gives the rain (0 to 1) and lightning (0 to 1).
    void weather_tick(tooie::day_night::Weather setting, uint32_t ms, float dt, bool snap, float& rain, float& flash) {
        using tooie::day_night::Weather;
        WeatherState& w = weather;
        if (setting == Weather::Changing) {
            if (!w.started || (int32_t)(ms - w.next_change_ms) >= 0) {
                const float roll = w.random01();
                // Starts clear; after that mostly clear, sometimes rain, now and then a storm.
                w.target = !w.started ? 0.0f : (roll < 0.6f) ? 0.0f : (roll < 0.85f) ? 0.6f : 1.0f;
                w.storm = w.started && (roll >= 0.85f);
                w.next_change_ms = ms + (uint32_t)((2.0f + 4.0f * w.random01()) * 60000.0f);
                w.started = true;
            }
        }
        else {
            w.started = false;
            w.target = (setting == Weather::Rain) ? 0.6f : (setting == Weather::Storm) ? 1.0f : 0.0f;
            w.storm = (setting == Weather::Storm);
        }
        // Comes and goes over about twenty seconds; already there on entering a level.
        const float step = snap ? 1.0f : dt / 20.0f;
        w.rain = (w.rain < w.target) ? std::min(w.target, w.rain + step) : std::max(w.target, w.rain - step);

        flash = 0.0f;
        if (w.storm && (w.rain > 0.6f)) {
            if (!w.flashing && (int32_t)(ms - w.next_flash_ms) >= 0) {
                w.flashing = true;
                w.flash_ms = ms;
                w.next_flash_ms = ms + (uint32_t)(6000.0f + 12000.0f * w.random01());
                // Further off the longer the wait for the thunder, and quieter.
                const float delay = 0.4f + 3.0f * w.random01();
                tooie::night_sounds::thunder(delay, 1.0f - delay / 4.5f);
            }
        }
        else if ((int32_t)(ms - w.next_flash_ms) >= 0) {
            w.next_flash_ms = ms + 3000;
        }
        if (w.flashing) {
            flash = flash_at(ms - w.flash_ms);
            if ((ms - w.flash_ms) > 1200) {
                w.flashing = false;
            }
        }
        rain = w.rain;
    }

    bool cycles(uint16_t map) {
        return std::find(std::begin(cycling_maps), std::end(cycling_maps), map) != std::end(cycling_maps);
    }

    float smooth(float x) {
        x = std::clamp(x, 0.0f, 1.0f);
        return x * x * (3.0f - 2.0f * x);
    }

    Look look_at(float t) {
        for (size_t i = 0; i + 1 < std::size(looks); i++) {
            const Look& a = looks[i];
            const Look& b = looks[i + 1];
            if (t >= a.t && t <= b.t) {
                const float f = smooth((t - a.t) / std::max(b.t - a.t, 1e-6f));
                Look out{ t };
                for (int c = 0; c < 3; c++) {
                    out.tint[c] = a.tint[c] + (b.tint[c] - a.tint[c]) * f;
                }
                return out;
            }
        }
        return looks[0];
    }

    void normalize(float v[3]) {
        const float length = std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
        if (length > 1e-6f) {
            for (int i = 0; i < 3; i++) {
                v[i] /= length;
            }
        }
    }
}

void tooie::day_night::tick(uint8_t* rdram) {
    static bool sent_lights = false;
    if (!sent_lights) {
        sent_lights = true;
        // Test aid: TOOIE_NIGHT_LIGHTS=0 leaves them unlit, to compare.
        const char* lights = std::getenv("TOOIE_NIGHT_LIGHTS");
        if ((lights == nullptr) || (std::atoi(lights) != 0)) {
            RT64::SetSceneNightLights(night_light_textures, std::size(night_light_textures));
        }
    }
    const Mode m = mode();
    const uint16_t map = tooie::debug::current_map(rdram);
    const bool on = (m != Mode::Off) && cycles(map);

    // The clock moves on game time, also in levels that don't cycle, so leaving one keeps the day going.
    const uint32_t ms = tooie::game_frame_rate::game_ms();
    const float dt = had_ms ? std::min((float)(ms - last_ms) / 1000.0f, 0.25f) : 0.0f;
    last_ms = ms;
    had_ms = true;
    if (m == Mode::Cycle) {
        day_clock += dt / (day_minutes() * 60.0);
        if (day_clock >= 1.0) {
            days++;
        }
        day_clock -= std::floor(day_clock);
    }
    const float t = (m == Mode::Cycle) ? (float)day_clock : held_time(m);

    // Eases over half a second when switched on or off in a level; a map change (behind its wipe) snaps.
    static uint16_t last_map = 0xFFFF;
    const bool new_map = (map != last_map);
    if (map != last_map) {
        last_map = map;
        amount = on ? 1.0f : 0.0f;
    }
    amount = on ? std::min(1.0f, amount + dt * 2.0f) : std::max(0.0f, amount - dt * 2.0f);

    if (amount <= 0.0f) {
        {
            std::lock_guard lock{mutex};
            active = false;
        }
        tooie::night_sounds::set(0.0f, 0.0f, 0.0f, 0.0f);
        if (!sent_off || new_map) {
            // The level's own sun, if it has one (for the sun shadows and the sun in the sky).
            float held[3] = { 0.0f, 1.0f, 0.0f };
            const bool own = map_sun(map, held);
            normalize(held);
            RT64::SetSceneSun(own, held[0], held[1], held[2]);
        }
        if (!sent_off) {
            sent_off = true;
            const float none[3] = { 1.0f, 1.0f, 1.0f };
            RT64::SetSceneTimeOfDay(false, none, 1.0f, false, false, false);
            RT64::SetSceneWeather(0.0f, 0.0f, false);
        }
        return;
    }
    sent_off = false;

    Look look = look_at(t);
    for (int c = 0; c < 3; c++) {
        look.tint[c] = 1.0f + (look.tint[c] - 1.0f) * amount;
    }

    // The sun rises in the east (+x) at 0.25, stands highest at noon, sets in the west at 0.75; it leans
    // a little to the south (+z) so it is never straight overhead. At night the moon takes the opposite path.
    // A level with its own sun (map_sun) turns the path to lean towards it instead, so noon's sun stands there.
    float lean_dir[2] = { 0.0f, 1.0f };
    float lean = 0.45f;
    {
        float own[3];
        if (map_sun(map, own)) {
            const float across = std::sqrt(own[0] * own[0] + own[2] * own[2]);
            if ((across > 1e-4f) && (own[1] > 0.05f)) {
                lean_dir[0] = own[0] / across;
                lean_dir[1] = own[2] / across;
                lean = across / own[1];
            }
        }
    }
    const float angle = 2.0f * 3.14159265f * (t - 0.25f);
    const float height = std::sin(angle);
    // The sky (sun disc, lens flare) and the sun shadows follow where it really is, so it sets below the
    // horizon; the moon takes over a little after. Along: from sunrise to sunset; up; the lean.
    float along = std::cos(angle) * 0.85f;
    float up = height;
    if (height < -0.1f) {
        // The moon keeps lower, so it is often in view.
        along = -along;
        up = -up * 0.55f;
    }
    // Sunrise is to the lean's left looking along it: (+x) for the usual lean to +z.
    float sky[3] = { along * lean_dir[1] + lean * lean_dir[0], up, -along * lean_dir[0] + lean * lean_dir[1] };
    normalize(sky);
    // For sun_direction (HD shadows): something to cast shadows with, never lower than about 10 degrees.
    float direction[3] = { sky[0], std::max(sky[1], 0.18f), sky[2] };
    normalize(direction);
    // Light shafts from the sun only, fading out as it nears the horizon.
    const float shafts = smooth(height / 0.2f);

    // The weather. On Hailfire Peaks' Icy Side it snows instead: a little always (unless the weather is set to
    // Clear), more when it would rain, with no lightning. No rain in Cloud Cuckooland (above the clouds).
    float rain = 0.0f;
    float flash = 0.0f;
    const tooie::day_night::Weather setting = weather_setting();
    weather_tick(setting, ms, dt, new_map, rain, flash);
    const bool snow = (map == 0x128);
    if (snow) {
        rain = (setting == tooie::day_night::Weather::Clear) ? 0.0f : std::max(rain, 0.5f);
        flash = 0.0f;
    }
    if (map == 0x136) {
        rain = 0.0f;
        flash = 0.0f;
    }
    // Test aid: TOOIE_LIGHTNING=<0 to 1> holds the lightning's brightness there.
    if (const char* v = std::getenv("TOOIE_LIGHTNING")) {
        flash = (float)std::atof(v);
    }
    // No rain falling (streaks, splashes, drops on the screen) while the view is under water, and it is only
    // heard faintly there. Lightning still flashes through.
    const float above_water = 1.0f - std::clamp(tooie::picture_filters::underwater(), 0.0f, 1.0f);
    RT64::SetSceneWeather(rain * amount * above_water, flash * amount, snow);
    const auto [mist, mist_when] = mist_setting();
    RT64::SetSceneMist(mist, mist_when);
    // The ground gets wet in the rain, in about 15 s of a storm, and dries over a minute and a half after.
    // A map change (behind its wipe) snaps it to the weather. No wet ground in snow.
    // Test aid: TOOIE_WET=<0 to 1> holds it there.
    static float wet = 0.0f;
    if (new_map) {
        wet = std::min(rain * 1.5f, 1.0f);
    }
    else {
        wet = (rain > 0.0f) ? std::min(1.0f, wet + rain * dt / 15.0f) : std::max(0.0f, wet - dt / 90.0f);
    }
    float wet_shown = (snow || !option_on(tooie::day_night::wet_ground_option)) ? 0.0f : wet;
    if (const char* v = std::getenv("TOOIE_WET")) {
        wet_shown = (float)std::atof(v);
    }
    RT64::SetSceneRainDetail(wet_shown * amount, option_on(tooie::day_night::drops_option) && !snow);

    // No fireflies on Hailfire Peaks (lava and ice).
    const bool fireflies = option_on(tooie::day_night::fireflies_option) && (map != 0x127) && (map != 0x128);
    // No clouds in Cloud Cuckooland, which is up in them.
    const bool clouds = option_on(tooie::day_night::clouds_option) && (map != 0x136);
    // The clouds' shape. Test aid: TOOIE_CLOUDS=<amount>,<height>,<thickness>,<speed>, each 0 to 100.
    float cloud[4] = { option_fraction(tooie::day_night::cloud_amount_option), option_fraction(tooie::day_night::cloud_height_option),
        option_fraction(tooie::day_night::cloud_thickness_option), option_fraction(tooie::day_night::cloud_speed_option) };
    if (const char* v = std::getenv("TOOIE_CLOUDS")) {
        float c[4] = { 50.0f, 50.0f, 50.0f, 50.0f };
        sscanf(v, "%f,%f,%f,%f", &c[0], &c[1], &c[2], &c[3]);
        for (int i = 0; i < 4; i++) {
            cloud[i] = std::clamp(c[i] / 100.0f, 0.0f, 1.0f);
        }
    }
    // Height: half to twice the usual; thickness: a third to five thirds; speed: still to four times.
    RT64::SetSceneClouds(cloud[0], std::pow(4.0f, cloud[1] - 0.5f), 0.2f + 0.8f * cloud[2], (cloud[3] * 2.0f) * (cloud[3] * 2.0f));
    RT64::SetSceneTimeOfDay(true, look.tint, shafts, option_on(tooie::day_night::flare_option), fireflies, clouds);
    RT64::SetSceneSun(true, sky[0], sky[1], sky[2]);
    // The moon goes round its phases in eight days: full on the first night, waning, new on the fifth, waxing.
    // Held at full when a time of day is held. Test aid: TOOIE_MOON_PHASE=<0 new to 7>.
    uint32_t phase = 4;
    if (m == Mode::Cycle) {
        // The night after day n belongs to day n (it starts before midnight).
        phase = (4u + days - ((t < 0.5f) && (days > 0) ? 1u : 0u)) % 8u;
    }
    if (const char* v = std::getenv("TOOIE_MOON_PHASE")) {
        phase = (uint32_t)std::atoi(v) & 7u;
    }
    RT64::SetSceneMoonPhase(phase);
    // Northern lights over Hailfire Peaks' Icy Side at night.
    // Test aid: TOOIE_AURORA=1 shows them on any cycling map.
    static const bool aurora_anywhere = (std::getenv("TOOIE_AURORA") != nullptr);
    RT64::SetSceneAurora(((map == 0x128) || aurora_anywhere) && option_on(tooie::day_night::aurora_option));

    // Night sounds: crickets and owls through the night, birds from dawn into the morning and a few through
    // the day. Quiet while the game stands still (the pause menu). No crickets on Hailfire Peaks or in Cloud
    // Cuckooland, and nothing living on the Icy Side.
    float sounds[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
    if (option_on(tooie::day_night::sounds_option) && dt > 0.0f) {
        const float night = 1.0f - smooth((t - 0.20f) / 0.06f) + smooth((t - 0.76f) / 0.06f);
        const float morning = smooth((t - 0.22f) / 0.05f) * (1.0f - 0.75f * smooth((t - 0.36f) / 0.09f)) *
            (1.0f - smooth((t - 0.68f) / 0.06f));
        const bool hailfire = (map == 0x127) || (map == 0x128);
        const float crickets = (hailfire || map == 0x136) ? 0.0f : night;
        const float owls = (map == 0x128) ? 0.0f : night;
        const float birds = (map == 0x128) ? 0.0f : morning;
        // Rain quietens the crickets and birds.
        const float dry = 1.0f - rain;
        sounds[0] = crickets * amount * dry;
        sounds[1] = owls * amount * dry;
        sounds[2] = birds * amount * dry;
    }
    // The rain is heard whether or not Night Sounds is on (not in the pause menu).
    if ((dt > 0.0f) && !snow) {
        sounds[3] = rain * amount * (0.25f + 0.75f * above_water);
    }
    tooie::night_sounds::set(sounds[0], sounds[1], sounds[2], sounds[3]);
    {
        std::lock_guard lock{mutex};
        active = (amount >= 1.0f);
        std::copy(std::begin(direction), std::end(direction), sun);
    }

    if (std::getenv("TOOIE_DAY_NIGHT_LOG")) {
        static uint32_t logged_ms = 0;
        if (ms - logged_ms >= 1000) {
            logged_ms = ms;
            fprintf(stderr, "[day-night] map %X time %.3f tint %.2f %.2f %.2f sun %.2f %.2f %.2f shafts %.2f sounds %.2f %.2f %.2f rain %.2f flash %.2f\n",
                map, t, look.tint[0], look.tint[1], look.tint[2], direction[0], direction[1], direction[2], shafts,
                sounds[0], sounds[1], sounds[2], rain, flash);
        }
    }
}

bool tooie::day_night::sun_direction(float out[3]) {
    std::lock_guard lock{mutex};
    if (!active) {
        return false;
    }
    std::copy(std::begin(sun), std::end(sun), out);
    return true;
}

void tooie::day_night::add_options(recomp::config::Config& graphics) {
    graphics.add_enum_option(
        option,
        "Day and Night",
        "A day and night cycle in the levels that are daytime under an open sky: Spiral Mountain, the Isle o' Hags outside, Mayahem Temple, Jolly Roger's Lagoon, Terrydactyland, Hailfire Peaks and Cloud Cuckooland. Sunrise and sunset turn the light warm, and at night the world goes dark blue under a starry sky. <recomp-color primary>Cycle</recomp-color> runs the clock while you play; the others hold one time of day. Rooms, underwater areas and the levels that are already night keep their own look.",
        {
            {Mode::Off, "Off", "Off"},
            {Mode::Cycle, "Cycle", "Cycle"},
            {Mode::Dawn, "Dawn", "Dawn"},
            {Mode::Morning, "Morning", "Morning"},
            {Mode::Noon, "Noon", "Noon"},
            {Mode::Afternoon, "Afternoon", "Afternoon"},
            {Mode::GoldenHour, "GoldenHour", "Golden Hour"},
            {Mode::Sunset, "Sunset", "Sunset"},
            {Mode::Dusk, "Dusk", "Dusk"},
            {Mode::Night, "Night", "Night"},
        },
        Mode::Off);
    graphics.add_number_option(
        length_option,
        "Day Length",
        "Minutes of play for a whole day and night with <recomp-color primary>Cycle</recomp-color>. About a third of it is night.",
        4, 60, 1, 0, false, 24);
    graphics.add_option_hidden_dependency(length_option, option, Mode::Off);
    graphics.add_bool_option(
        flare_option,
        "Lens Flare",
        "With Day and Night on, soft rings of light cross the screen when you look towards the sun and nothing hides it.",
        true);
    graphics.add_option_hidden_dependency(flare_option, option, Mode::Off);
    graphics.add_bool_option(
        fireflies_option,
        "Fireflies",
        "With Day and Night on, small glowing fireflies drift round Banjo at night (not on Hailfire Peaks).",
        true);
    graphics.add_option_hidden_dependency(fireflies_option, option, Mode::Off);
    graphics.add_enum_option(
        weather_option,
        "Weather",
        "With Day and Night on, rain and thunderstorms. <recomp-color primary>Changing</recomp-color> is mostly clear, with rain or a storm now and then for a few minutes; the others hold one. On Hailfire Peaks' Icy Side it snows instead (a little unless Clear), and Cloud Cuckooland stays dry.",
        {
            {Weather::Clear, "Clear", "Clear"},
            {Weather::Changing, "Changing", "Changing"},
            {Weather::Rain, "Rain", "Rain"},
            {Weather::Storm, "Storm", "Storm"},
        },
        Weather::Changing);
    graphics.add_option_hidden_dependency(weather_option, option, Mode::Off);
    graphics.add_bool_option(
        aurora_option,
        "Northern Lights",
        "With Day and Night on, green and violet northern lights wave across the night sky over Hailfire Peaks' Icy Side.",
        true);
    graphics.add_option_hidden_dependency(aurora_option, option, Mode::Off);
    graphics.add_bool_option(
        clouds_option,
        "Clouds",
        "With Day and Night on, soft 3D clouds drift across the sky, lit by the sun and the moon (not in Cloud Cuckooland).",
        true);
    graphics.add_option_hidden_dependency(clouds_option, option, Mode::Off);
    graphics.add_number_option(
        cloud_amount_option,
        "Cloud Amount",
        "With Day and Night and Clouds on, how much of the sky the clouds cover: 0 a few wisps, 50 the usual, 100 nearly overcast (rain covers it all anyway).",
        0, 100, 5, 0, false, 50);
    graphics.add_option_hidden_dependency(cloud_amount_option, option, Mode::Off);
    graphics.add_number_option(
        cloud_height_option,
        "Cloud Height",
        "With Day and Night and Clouds on, how high the clouds float: low clouds look big and close, high ones small and far off.",
        0, 100, 5, 0, false, 50);
    graphics.add_option_hidden_dependency(cloud_height_option, option, Mode::Off);
    graphics.add_number_option(
        cloud_thickness_option,
        "Cloud Thickness",
        "With Day and Night and Clouds on, how deep the cloud layer is: thin, flat clouds or tall, puffy ones that block more of the sky.",
        0, 100, 5, 0, false, 50);
    graphics.add_option_hidden_dependency(cloud_thickness_option, option, Mode::Off);
    graphics.add_number_option(
        cloud_speed_option,
        "Cloud Speed",
        "With Day and Night and Clouds on, how fast the wind blows the clouds across the sky: 0 holds them still.",
        0, 100, 5, 0, false, 50);
    graphics.add_option_hidden_dependency(cloud_speed_option, option, Mode::Off);
    graphics.add_bool_option(
        wet_ground_option,
        "Wet Ground",
        "With Day and Night on, the ground darkens and turns shiny in the rain, reflecting what is round it, then dries slowly after.",
        true);
    graphics.add_option_hidden_dependency(wet_ground_option, option, Mode::Off);
    graphics.add_bool_option(
        drops_option,
        "Raindrops on Screen",
        "With Day and Night on, raindrops land on the screen in the rain, more when you look up, and run down it.",
        true);
    graphics.add_option_hidden_dependency(drops_option, option, Mode::Off);
    graphics.add_number_option(
        mist_option,
        "Mist",
        "With Day and Night on, pale mist drifts in banks over low ground and gathers thickest on and round water. 0 turns it off.",
        0, 100, 5, 0, false, 50);
    graphics.add_option_hidden_dependency(mist_option, option, Mode::Off);
    graphics.add_enum_option(
        mist_time_option,
        "Mist Time",
        "When the mist shows: in the early morning, also at night, or all day.",
        {
            {MistTime::Mornings, "Mornings", "Mornings"},
            {MistTime::MorningsAndNights, "MorningsAndNights", "Mornings and Nights"},
            {MistTime::Always, "Always", "Always"},
        },
        MistTime::Mornings);
    graphics.add_option_hidden_dependency(mist_time_option, option, Mode::Off);
    graphics.add_bool_option(
        sounds_option,
        "Night Sounds",
        "With Day and Night on, crickets and the odd owl at night and birdsong in the morning, quietly under the music.",
        true);
    graphics.add_option_hidden_dependency(sounds_option, option, Mode::Off);
}
