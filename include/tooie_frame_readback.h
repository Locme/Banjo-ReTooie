#ifndef __TOOIE_FRAME_READBACK_H__
#define __TOOIE_FRAME_READBACK_H__

#include <string>

#include "librecomp/config.hpp"

// Frame Read-Back (src/display/frame_readback.cpp, handoff 4.32): a Graphics option, off by default,
// that copies every finished frame back into the game's memory as a real N64 has it (RT64's render
// to RAM). Off, RT64 keeps frames on the GPU and draws on its own thread (RT64::SetRenderToRAM).
namespace tooie::frame_readback {
    inline const std::string option = "frame_readback";

    void add_option(recomp::config::Config& graphics);

    // Sends the saved setting to RT64.
    void apply();
}

#endif
