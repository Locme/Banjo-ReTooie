#pragma once

// Day and night cycle (src/gameplay/day_night.cpp), Graphics tab, off by default.
#include <cstddef>
#include <cstdint>
#include <string>

#include "librecomp/config.hpp"

namespace tooie::day_night {
    // Off, a running cycle, or one time of day held.
    enum class Mode : uint32_t { Off, Cycle, Morning, Sunset, Night };
    inline const std::string option = "day_night";
    // How long a whole day and night takes, in minutes of play.
    inline const std::string length_option = "day_night_length";
    // Lens flare towards the sun by day.
    inline const std::string flare_option = "day_night_flare";
    // Fireflies round Banjo at night.
    inline const std::string fireflies_option = "day_night_fireflies";
    // Crickets and owls at night, birdsong in the morning (src/gameplay/night_sounds.cpp).
    inline const std::string sounds_option = "day_night_sounds";

    void add_options(recomp::config::Config& graphics);
    // Call once per frame from the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram);
    // The light in world space, a unit vector towards the sun (the moon at night), always well above the
    // horizon. False while the cycle is off or the map is not one that cycles: keep your own light then.
    bool sun_direction(float out[3]);
    // The time of day, 0 to 1 from midnight (0.5 is noon). False as for sun_direction.
    bool time_of_day(float& out);
}

namespace tooie::night_sounds {
    // How much of each to play, 0 to 1. From day_night::tick on the game thread.
    void set(float crickets, float owls, float birds);
    // Adds them to interleaved stereo float samples at the given rate (main.cpp queue_samples, audio thread).
    void mix(float* stereo, size_t frames, uint32_t rate, float volume);
}
