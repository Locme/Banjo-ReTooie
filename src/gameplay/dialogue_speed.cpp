// Dialogue text speed (handoff 4.52): 1x, 2x, 4x or instant.
//
// Dialogue boxes are the zoombox overlay. gczoombox_entrypoint_4 is a box's
// per-frame update; in state 2 (printing, +0x171) it adds the frame time to the
// print timer at +0x1D4, then prints one letter for every interval (+0x1D8) the
// timer holds, taking an extra 0.1 (or 0.05) off it after punctuation.
// banjotooie.us.toml hooks the instruction after the timer is advanced. Adding
// (speed - 1) more frame times there divides both the letter interval and the
// punctuation pauses by the speed. Instant fills the timer so the whole page
// prints on the frame it appears; the next page resets the timer to 0.
// Menus do not use the zoombox, so they are unchanged.

#include <cstring>
#include <string>

#include "recomp.h"
#include "recompui/config.h"
#include "tooie_game.h"
#include "tooie_hooks.h"

namespace {
    constexpr gpr timer_offset = 0x1D4;
    constexpr float instant_timer = 1.0e6f;

    // -1 when the command line did not set a speed.
    int cli_speed = -1;

    tooie::TextSpeed current_speed() {
        if (cli_speed >= 0) {
            return static_cast<tooie::TextSpeed>(cli_speed);
        }
        try {
            return static_cast<tooie::TextSpeed>(std::get<uint32_t>(
                recompui::config::get_config(tooie::qol_tab_id).get_option_value(tooie::text_speed_option)));
        } catch (...) {
            return tooie::TextSpeed::Normal;
        }
    }
}

bool tooie::parse_text_speed_arg(const char* value) {
    if (strcmp(value, "1") == 0 || strcmp(value, "1x") == 0) cli_speed = (int)TextSpeed::Normal;
    else if (strcmp(value, "2") == 0 || strcmp(value, "2x") == 0) cli_speed = (int)TextSpeed::Double;
    else if (strcmp(value, "4") == 0 || strcmp(value, "4x") == 0) cli_speed = (int)TextSpeed::Quadruple;
    else if (strcmp(value, "instant") == 0) cli_speed = (int)TextSpeed::Instant;
    else return false;
    return true;
}

extern "C" void tooie_dialogue_timer_advanced(uint8_t* rdram, recomp_context* ctx) {
    gpr box = ctx->r16;
    float dt = ctx->f0.fl;
    float extra;
    switch (current_speed()) {
        case tooie::TextSpeed::Double:    extra = dt;     break;
        case tooie::TextSpeed::Quadruple: extra = 3 * dt; break;
        case tooie::TextSpeed::Instant:   extra = instant_timer; break;
        default: return;
    }
    float timer;
    uint32_t bits = MEM_W(timer_offset, box);
    memcpy(&timer, &bits, sizeof(timer));
    timer += extra;
    memcpy(&bits, &timer, sizeof(bits));
    MEM_W(timer_offset, box) = bits;
}
