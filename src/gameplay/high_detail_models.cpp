// High-detail models always (handoff 4.28).
//
// Models that swap to a simpler version far away do it with a geo LOD command
// (command 8): func_800DD214 (draw pass) and func_800DD2E8 (matrix pass) take
// the squared distance from the camera in $f0 (func_800EEB40) and run the
// command's child only when near² < d² <= far² (near at +0xC, far at +0x8,
// child offset at +0x1C). banjotooie.us.toml hooks both just after the
// distance is computed; with the option on, the distance is replaced by 1, so
// every LOD command runs as if the camera were right next to it: the detailed
// child (near 0) is drawn and the simpler ones (near further out) are not.
// The option is read on every call, so switching it applies at once.

#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <variant>

#include "recomp.h"
#include "recompui/config.h"
#include "tooie_game.h"
#include "tooie_hooks.h"

namespace {
    bool high_detail_on() {
        try {
            return std::get<bool>(recompui::config::get_config(tooie::qol_tab_id).get_option_value(tooie::high_detail_models_option));
        } catch (...) {
            return true;
        }
    }
}

extern "C" void tooie_lod_distance(uint8_t* rdram, recomp_context* ctx) {
    // TOOIE_LOD_LOG=1: every 2 s, how many LOD commands ran and how many of them the option changes.
    static const bool log = std::getenv("TOOIE_LOD_LOG") != nullptr;
    if (log) {
        static uint32_t calls = 0;
        static uint32_t far_calls = 0;
        static auto last = std::chrono::steady_clock::now();
        const gpr node = MEM_W(0x1C, ctx->r29);
        uint32_t near_bits = MEM_W(0xC, node);
        uint32_t far_bits = MEM_W(0x8, node);
        float near_range, far_range;
        std::memcpy(&near_range, &near_bits, sizeof(near_range));
        std::memcpy(&far_range, &far_bits, sizeof(far_range));
        const float d2 = ctx->f0.fl;
        const bool drawn = near_range * near_range < d2 && d2 <= far_range * far_range;
        const bool drawn_close = near_range * near_range < 1.0f && 1.0f <= far_range * far_range;
        calls++;
        if (drawn != drawn_close) {
            far_calls++;
        }
        auto now = std::chrono::steady_clock::now();
        if (now - last >= std::chrono::seconds(2)) {
            std::printf("[lod] %u LOD commands, %u would pick another child at this distance, high detail %d\n", calls, far_calls, high_detail_on());
            std::fflush(stdout);
            calls = 0;
            far_calls = 0;
            last = now;
        }
    }
    if (high_detail_on()) {
        ctx->f0.fl = 1.0f;
    }
}
