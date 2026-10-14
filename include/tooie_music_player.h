#ifndef __TOOIE_MUSIC_PLAYER_H__
#define __TOOIE_MUSIC_PLAYER_H__

#include <cstdint>
#include <string>

#include "recomp.h"

namespace recomp::config {
    class Config;
}

// Music player (handoff 4.61, src/gameplay/music_player.cpp): the Sound tab's "Music player" row
// plays any of the game's 160 tracks. Jolly's jukebox songs are listed by name, the rest by number.
// "Level music" stops the chosen track and restarts the tracks the level was playing, and a map
// change ends the chosen track (the new area starts its own music).
namespace tooie::music_player {
    inline const std::string option = "music_player";

    // Adds the row to the Sound tab.
    void add_options(recomp::config::Config& sound);

    // Call once per frame from the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram, recomp_context* ctx);
}

#endif
