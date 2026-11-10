#ifndef __TOOIE_TEXTURE_SWEEP_H__
#define __TOOIE_TEXTURE_SWEEP_H__

#include <cstdint>
#include <string>

#include "recomp.h"
#include "librecomp/config.hpp"

// Texture dump and texture sweep (src/game/texture_sweep.cpp), DEV tab:
// saves every texture the game draws to texture_dump/ in the app-data folder, for
// making texture packs. The sweep warps through every known map so nobody has to play.
namespace tooie {
    inline const std::string texture_dump_option = "texture_dump";
    enum class TextureDump : uint32_t { Off, WhilePlaying, SweepAllMaps };
}

namespace tooie::texture_sweep {
    // Full: every entrance of every map, turning the camera. Fast: entrance 0 of every map, no turn, shorter
    // waits. More: the other entrances of the maps that gave textures in a fast pass.
    enum class Mode { Full, Fast, More };
    // Call once per frame from the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram);
    // Asks "Start the texture sweep?" when Sweep all maps is picked in the menu.
    void add_prompt(recomp::config::Config& config);
    // Adds the camera turn to the player's buttons while a sweep looks around a map.
    void apply_input(uint16_t* buttons);
    // True while a sweep is warping around, so nothing saves the game meanwhile.
    bool sweeping();
    // Starts the sweep as the menu prompt's Start sweep button does, once Texture dump is set to Sweep all maps
    // (developer console).
    void confirm_start(Mode mode = Mode::Full);
    // True while a sweep is in a map with DEV > Pass over crashes on: a crash or hang should call pass_over.
    bool pass_over_active();
    // From the crash handler or the watchdog: writes the MAJOR line for the entrance the sweep is in,
    // with why, and starts a new copy of the game, which resumes after it. False if not active or
    // the copy couldn't start. The caller then ends this process.
    bool pass_over(const char* why);
    // From the memory guard: a crash it passed over while the sweep was in a map, for sweep.txt.
    void note_major(const char* why);
}

#endif
