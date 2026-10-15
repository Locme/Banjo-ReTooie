#pragma once

#include <cstdint>
#include <string>

namespace tooie::totals_checklist {
    // QOL option id (bool, on by default).
    inline const std::string option = "totals_checklist";

    // Pad filter (src/debug/pad_script.cpp): on a Totals world page, up/down picks a row of the table
    // and A opens its list; in the list up/down scroll and B goes back. Those presses are kept from
    // the game while they are used here.
    void apply_input(uint16_t* buttons, float* x, float* y);
}
