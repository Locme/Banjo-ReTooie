#pragma once

#include <cstdint>
#include <string>

namespace tooie::totals_checklist {
    // QOL option id (bool, on by default).
    // Renamed from "totals_checklist" when the default became Off, so a saved On from before starts Off too.
    inline const std::string option = "totals_checklist_v2";

    // Pad filter (src/debug/pad_script.cpp): on a Totals world page, up/down picks a row of the table
    // (on the Achievements page, an achievement)
    // and A opens its list; in the list up/down scroll and B goes back. Those presses are kept from
    // the game while they are used here.
    void apply_input(uint16_t* buttons, float* x, float* y);
}
