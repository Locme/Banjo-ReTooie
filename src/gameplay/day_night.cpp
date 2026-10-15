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
#include <variant>

#include "recomp.h"
#include "recompui/config.h"
#include "tooie_day_night.h"
#include "tooie_debug.h"
#include "tooie_game_frame_rate.h"

namespace RT64 {
    // lib/rt64/src/render/rt64_scene_effects.h.
    void SetSceneTimeOfDay(bool enabled, const float tint[3], float shafts, bool flare, bool fireflies);
    void SetSceneSun(bool custom, float x, float y, float z);
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
        { 0.30f, { 1.00f, 0.92f, 0.84f } },
        { 0.36f, { 1.00f, 1.00f, 1.00f } },
        { 0.66f, { 1.00f, 1.00f, 1.00f } },
        { 0.72f, { 1.00f, 0.74f, 0.52f } },
        { 0.77f, { 0.56f, 0.46f, 0.66f } },
        { 0.82f, { 0.38f, 0.44f, 0.68f } },
        { 1.00f, { 0.38f, 0.44f, 0.68f } },
    };

    // Held times for the fixed modes.
    constexpr float morning_time = 0.31f;
    constexpr float sunset_time = 0.72f;
    constexpr float night_time = 0.0f;

    std::mutex mutex;
    bool active = false;
    float sun[3] = { 0.0f, 1.0f, 0.0f };
    float current_time = 0.0f;

    // The running clock, from morning when the game starts. Test aid: TOOIE_TIME_OF_DAY=<0 to 1> starts there.
    double day_clock = std::getenv("TOOIE_TIME_OF_DAY") ? std::atof(std::getenv("TOOIE_TIME_OF_DAY")) : morning_time;
    uint32_t last_ms = 0;
    bool had_ms = false;
    // How far the look has come in, 0 to 1, so it eases in and out when the option changes.
    float amount = 0.0f;
    bool sent_off = false;

    tooie::day_night::Mode mode() {
        // Test aid: TOOIE_DAY_NIGHT=<0 Off, 1 Cycle, 2 Morning, 3 Sunset, 4 Night> whatever the setting says.
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
        day_clock -= std::floor(day_clock);
    }
    const float t = (m == Mode::Morning) ? morning_time : (m == Mode::Sunset) ? sunset_time : (m == Mode::Night) ? night_time : (float)day_clock;

    // Eases over half a second when switched on or off in a level; a map change (behind its wipe) snaps.
    static uint16_t last_map = 0xFFFF;
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
        tooie::night_sounds::set(0.0f, 0.0f, 0.0f);
        if (!sent_off) {
            sent_off = true;
            const float none[3] = { 1.0f, 1.0f, 1.0f };
            RT64::SetSceneTimeOfDay(false, none, 1.0f, false, false);
            RT64::SetSceneSun(false, 0.0f, 0.0f, 0.0f);
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
    const float angle = 2.0f * 3.14159265f * (t - 0.25f);
    const float height = std::sin(angle);
    // The sky (sun disc, lens flare) and the sun shadows follow where it really is, so it sets below the
    // horizon; the moon takes over a little after.
    float sky[3] = { std::cos(angle) * 0.85f, height, 0.45f };
    if (height < -0.1f) {
        // The moon keeps lower, so it is often in view.
        sky[0] = -sky[0];
        sky[1] = -sky[1] * 0.55f;
    }
    normalize(sky);
    // For sun_direction (HD shadows): something to cast shadows with, never lower than about 10 degrees.
    float direction[3] = { sky[0], std::max(sky[1], 0.18f), sky[2] };
    normalize(direction);
    // Light shafts from the sun only, fading out as it nears the horizon.
    const float shafts = smooth(height / 0.2f);

    // No fireflies on Hailfire Peaks (lava and ice).
    const bool fireflies = option_on(tooie::day_night::fireflies_option) && (map != 0x127) && (map != 0x128);
    RT64::SetSceneTimeOfDay(true, look.tint, shafts, option_on(tooie::day_night::flare_option), fireflies);
    RT64::SetSceneSun(true, sky[0], sky[1], sky[2]);

    // Night sounds: crickets and owls through the night, birds from dawn into the morning and a few through
    // the day. Quiet while the game stands still (the pause menu). No crickets on Hailfire Peaks or in Cloud
    // Cuckooland, and nothing living on the Icy Side.
    float sounds[3] = { 0.0f, 0.0f, 0.0f };
    if (option_on(tooie::day_night::sounds_option) && dt > 0.0f) {
        const float night = 1.0f - smooth((t - 0.20f) / 0.06f) + smooth((t - 0.76f) / 0.06f);
        const float morning = smooth((t - 0.22f) / 0.05f) * (1.0f - 0.75f * smooth((t - 0.36f) / 0.09f)) *
            (1.0f - smooth((t - 0.68f) / 0.06f));
        const bool hailfire = (map == 0x127) || (map == 0x128);
        const float crickets = (hailfire || map == 0x136) ? 0.0f : night;
        const float owls = (map == 0x128) ? 0.0f : night;
        const float birds = (map == 0x128) ? 0.0f : morning;
        sounds[0] = crickets * amount;
        sounds[1] = owls * amount;
        sounds[2] = birds * amount;
    }
    tooie::night_sounds::set(sounds[0], sounds[1], sounds[2]);
    {
        std::lock_guard lock{mutex};
        active = (amount >= 1.0f);
        std::copy(std::begin(direction), std::end(direction), sun);
        current_time = t;
    }

    if (std::getenv("TOOIE_DAY_NIGHT_LOG")) {
        static uint32_t logged_ms = 0;
        if (ms - logged_ms >= 1000) {
            logged_ms = ms;
            fprintf(stderr, "[day-night] map %X time %.3f tint %.2f %.2f %.2f sun %.2f %.2f %.2f shafts %.2f sounds %.2f %.2f %.2f\n",
                map, t, look.tint[0], look.tint[1], look.tint[2], direction[0], direction[1], direction[2], shafts,
                sounds[0], sounds[1], sounds[2]);
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

bool tooie::day_night::time_of_day(float& out) {
    std::lock_guard lock{mutex};
    if (!active) {
        return false;
    }
    out = current_time;
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
            {Mode::Morning, "Morning", "Morning"},
            {Mode::Sunset, "Sunset", "Sunset"},
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
    graphics.add_bool_option(
        sounds_option,
        "Night Sounds",
        "With Day and Night on, crickets and the odd owl at night and birdsong in the morning, quietly under the music.",
        true);
    graphics.add_option_hidden_dependency(sounds_option, option, Mode::Off);
}
