#ifndef __TOOIE_SOUND_DUMP_H__
#define __TOOIE_SOUND_DUMP_H__

#include <cstdint>
#include <string>

// DEV > Dump sounds (src/game/sound_dump.cpp): writes the game's sound samples as WAV files to
// sound_dump/ in the app-data folder, organised by sound bank and instrument.
namespace tooie {
    inline const std::string sound_dump_option = "sound_dump";
}

namespace tooie::sound_dump {
    // Call once per frame from the game thread (tooie_warp_tick).
    void tick(uint8_t* rdram);
}

#endif
