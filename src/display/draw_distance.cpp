// Extended draw distance (handoff 4.26).
//
// Each map sets a base distance, the halfword D_8012844C (1300 in Spiral
// Mountain, 1500 in Mayahem Temple). func_800BDC5C returns it, func_800D2F20
// returns it times 4, and that is what the game hands to the renderer's range
// setters (func_800DF428, func_800E249C) and to a few characters. Its only
// reader is func_800BDC5C, so the value itself is raised: every frame, from
// tooie_warp_tick, the game's own value is remembered (a value we did not
// write is the game's) and replaced with the larger of it and the per-map
// value from retroben's Xenia "Draw Distance Hack", divided by 4:
// 10400 in Terrydactyland (0x112) and Hailfire Peaks' icy side (0x128),
// 12800 on the lava side (0x127), 21504 in Cloud Cuckooland (0x136), 25600
// elsewhere. With the option off, the game's value is put back.

#include <algorithm>

#include "recomp.h"
#include "recompui/config.h"
#include "tooie_game.h"

namespace {
    constexpr gpr base_distance_addr = (int32_t)0x8012844C;   // s16
    constexpr gpr current_map_addr = (int32_t)0x80132DC2;

    int16_t game_value = 0;
    int16_t written_value = 0;
    bool have_game_value = false;

    bool enabled() {
        try {
            return std::get<bool>(recompui::config::get_config(tooie::qol_tab_id).get_option_value(tooie::draw_distance_option));
        } catch (...) {
            return true;
        }
    }

    int extended_distance(uint16_t map) {
        switch (map) {
            case 0x112: case 0x128: return 10400;
            case 0x127: return 12800;
            case 0x136: return 21504;
            default: return 25600;
        }
    }
}

void tooie::draw_distance_tick(uint8_t* rdram) {
    int16_t now = (int16_t)MEM_H(0, base_distance_addr);
    if (!have_game_value || now != written_value) {
        // The game set a new value (a map load), or this is the first frame.
        game_value = now;
        have_game_value = true;
    }
    int16_t want = game_value;
    if (enabled() && game_value > 0) {
        int extended = extended_distance(MEM_HU(0, current_map_addr)) / 4;
        want = (int16_t)std::max<int>(game_value, extended);
    }
    written_value = want;
    if (now != want) {
        MEM_H(0, base_distance_addr) = want;
    }
}
