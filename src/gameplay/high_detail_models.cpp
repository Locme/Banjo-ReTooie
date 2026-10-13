// High-detail models always (handoff 4.28).
//
// Models that swap to a simpler version far away do it with a geo LOD command
// (command 8): func_800DD214 (draw pass), func_800DD2E8 (matrix pass) and
// func_800DD37C (a third pass, same layout) take the squared distance from the camera in $f0 (func_800EEB40) and run the
// command's child only when near² < d² <= far² (near at +0xC, far at +0x8,
// child offset at +0x1C). banjotooie.us.toml hooks both just after the
// distance is computed; with the option on, the distance is replaced by 1, so
// every LOD command runs as if the camera were right next to it: the detailed
// child (near 0) is drawn and the simpler ones (near further out) are not.
// The option is read on every call, so switching it applies at once.
//
// Banjo and Kazooie are not swapped by a LOD command. Their model (0x607) has
// two versions: a close-up one (Banjo's necklace, belt buckle, Kazooie's
// detail) and a simpler far one. func_80094070 measures the camera distance
// each frame and asks func_80093F30 for the model of detail level 0 (close) or
// 1 (far); func_80093FD4 picks the starting level from the map. With the option
// on, the hook at func_80093F30's entry always asks for level 0. With it off,
// the next distance check goes back to the game's choice.

#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <utility>
#include <variant>

#include "recomp.h"
#include "recompui/config.h"
#include "tooie_game.h"
#include "tooie_hooks.h"

namespace {
    bool high_detail_on() {
        try {
            return std::get<bool>(recompui::config::get_config(recompui::config::graphics::id).get_option_value(tooie::high_detail_models_option));
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
        static std::set<std::pair<uint32_t, uint32_t>> seen;
        if (seen.emplace(near_bits, far_bits).second) {
            std::printf("[lod] new pair near %.0f far %.0f at distance %.0f map %04X\n", near_range, far_range, std::sqrt(d2),
                (uint32_t)MEM_HU(0, (gpr)(int32_t)0x80132DC2));
        }
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

extern "C" void tooie_banjo_detail(uint8_t* rdram, recomp_context* ctx) {
    if (high_detail_on()) {
        ctx->r4 = 0;
    }
}
