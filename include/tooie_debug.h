#ifndef __TOOIE_DEBUG_H__
#define __TOOIE_DEBUG_H__

#include <cstdint>

namespace tooie::debug {
    // Parses a --pad-script argument (see src/debug/pad_script.cpp).
    bool parse_pad_script(const char* script);
    // Player input with any scripted input added, for the runtime's callbacks.
    bool get_n64_input(int player_index, uint16_t* buttons_out, float* x_out, float* y_out);
}

#endif
