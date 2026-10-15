#pragma once

// Day and night cycle (src/gameplay/day_night.cpp), Graphics tab, off by default.
#include <cstdint>
#include <string>

#include "librecomp/config.hpp"

namespace tooie::day_night {
    // Off, a running cycle, or one time of day held.
    enum class Mode : uint32_t { Off, Cycle, Morning, Sunset, Night };
    inline const std::string option = "day_night";
    // How long a whole day and night takes, in minutes of play.
    inline const std::string length_option = "day_night_length";

    void add_options(recomp::config::Config& graphics);
    // Call once per frame from the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram);
    // The light in world space, a unit vector towards the sun (the moon at night), always well above the
    // horizon. False while the cycle is off or the map is not one that cycles: keep your own light then.
    bool sun_direction(float out[3]);
    // The time of day, 0 to 1 from midnight (0.5 is noon). False as for sun_direction.
    bool time_of_day(float& out);
}
