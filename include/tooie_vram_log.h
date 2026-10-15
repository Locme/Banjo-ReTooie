#ifndef __TOOIE_VRAM_LOG_H__
#define __TOOIE_VRAM_LOG_H__

#include <string>

// Video memory log (src/debug/vram_log.cpp): [vram] lines in console.log with the video
// memory in use, the driver's budget for the game and the texture pack's share.
namespace tooie::vram_log {
    // Starts the logging thread the first time; call from the game thread each frame.
    void start();
    // "VRAM 5120 of 14336 MB, pack 900 MB", or empty when the renderer can't tell.
    std::string summary();
}

#endif
