#ifndef __TOOIE_DEBUG_H__
#define __TOOIE_DEBUG_H__

#include <cstdint>

namespace tooie::debug {
    // Parses a --pad-script argument (see src/debug/pad_script.cpp).
    bool parse_pad_script(const char* script);
    // Player input with any scripted input added, for the runtime's callbacks.
    bool get_n64_input(int player_index, uint16_t* buttons_out, float* x_out, float* y_out);
    // Map warps (see src/debug/warp.cpp). The request is issued on the game
    // thread at the start of the next frame.
    void request_warp(uint16_t map, uint8_t exit);
    uint16_t current_map(uint8_t* rdram);
    // True while a save file is being played, so a warp can be issued.
    bool can_warp();
}

namespace tooie::dl_dump {
    // Display list dumps (see src/debug/dl_dump.cpp), called after the 3D scene.
    void scene_end(uint8_t* rdram, uint32_t gfx_end);
}

#endif
