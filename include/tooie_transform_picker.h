#ifndef __TOOIE_TRANSFORM_PICKER_H__
#define __TOOIE_TRANSFORM_PICKER_H__

#include <cstdint>
#include <string>

#include "recomp.h"

namespace recomp::config {
    class Config;
}

// Transformation picker (handoff 4.78, src/gameplay/transform_picker.cpp): the Cheats tab's
// "Transformation" row plays as any of Banjo-Tooie's forms. The game picks the player's form
// when an area loads (basetup_entrypoint_2 reads the byte at 0x8012704C), so choosing a form
// stores it there and reloads the current area at the entrance the player came in by. A live
// swap would leave the old model on top.
namespace tooie::transform_picker {
    inline const std::string option = "cheat_transform";

    // Adds the row to the Cheats tab, hidden while master_option is off.
    void add_options(recomp::config::Config& cheats, const std::string& master_option);

    // Resets the row to Off (the master switch went off).
    void reset(recomp::config::Config& cheats);

    // Asks for a form the way the row does (applied by tick). False if a request is already waiting
    // or Banjo is already in that form.
    bool request_form(uint8_t form);

    // Call once per frame from the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram, recomp_context* ctx);
}

#endif
