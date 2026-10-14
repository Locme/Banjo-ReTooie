// Per-frame drawing memory guard.
//
// The game builds each frame's display list, matrices and vertices in fixed
// double buffers (pointers at D_80127658: list head, matrix head, vertex
// head; buffers listed at D_8007BCD0, two of each, back to back, the one in use
// chosen by D_8007BEDA: lists
// 0x76D0 bytes each, matrices 0x12C10, vertices 0x1AF0). It never checks the
// ends, as the original game's own drawing always fits (at most about a
// third of each, measured headless). Extended draw distance and HD shadows
// draw more models into the same buffers: in Mayahem Temple both together
// filled 92% of the list buffer, and a busier scene can run past the end.
// Writing past the list buffer lands in the other frame's list or in the
// matrices, which shows as torn geometry, exploded models or a crash on a
// garbage display list command.
//
// room_for_extras() says whether the extras may still draw: they stop while
// enough is left for all of the game's own drawing (the margins below, about
// 1.3x the most the game used on its own). The game's own models are always
// drawn; only the extra far ones and extra shadows are skipped that frame.
//
// TOOIE_GFX_LOG=1: every 2 s, the most of each buffer a frame used.

#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cstdlib>

#include "recomp.h"
#include "tooie_gfx_budget.h"

namespace {
    constexpr gpr heads_addr = (int32_t)0x80127658;
    constexpr gpr buffers_addr = (int32_t)0x8007BCD0;
    // Bytes kept free for the game's own drawing: lists, matrices.
    constexpr uint32_t margin[2] = { 0x3000, 0x6000 };

    // The buffer this frame draws into (0 or 1), set by func_8001A4B8.
    constexpr gpr index_addr = (int32_t)0x8007BEDA;

    // Bytes used so far in this frame's buffer, and its size. False if the
    // head is not in it (not drawing yet).
    bool usage(uint8_t* rdram, int pool, uint32_t* used, uint32_t* size) {
        const uint32_t b0 = (uint32_t)MEM_W(8 * pool, buffers_addr);
        const uint32_t b1 = (uint32_t)MEM_W(8 * pool + 4, buffers_addr);
        const int index = MEM_H(0, index_addr);
        if (b1 <= b0 || (index != 0 && index != 1)) {
            return false;
        }
        *size = b1 - b0;
        const uint32_t start = index == 0 ? b0 : b1;
        const uint32_t head = (uint32_t)MEM_W(4 * pool, heads_addr);
        if (head < start || head >= start + *size * 2) {
            return false;
        }
        *used = head - start;
        return true;
    }

    const bool log_on = std::getenv("TOOIE_GFX_LOG") != nullptr;
    uint32_t peak[2] = {};
    uint32_t skipped = 0;
}

bool tooie::gfx_budget::room_for_extras(uint8_t* rdram) {
    for (int pool = 0; pool < 2; pool++) {
        uint32_t used, size;
        if (usage(rdram, pool, &used, &size) && used + margin[pool] > size) {
            skipped++;
            return false;
        }
    }
    return true;
}

void tooie::gfx_budget::frame_end(uint8_t* rdram) {
    static uint32_t sizes[2] = {};
    bool over = false;
    for (int pool = 0; pool < 2; pool++) {
        uint32_t used, size;
        if (usage(rdram, pool, &used, &size)) {
            peak[pool] = std::max(peak[pool], used);
            sizes[pool] = size;
            over = over || used > size;
        }
    }
    static auto last = std::chrono::steady_clock::now();
    static bool reported = false;
    if (over && !reported) {
        std::fprintf(stderr, "[gfx] The game's drawing memory overflowed (lists %X of %X, matrices %X of %X).\n",
            peak[0], sizes[0], peak[1], sizes[1]);
        reported = true;
    }
    if (log_on && std::chrono::steady_clock::now() - last > std::chrono::seconds(2)) {
        last = std::chrono::steady_clock::now();
        std::printf("[gfx] most used: lists %X of %X, matrices %X of %X; extras skipped %u times\n",
            peak[0], sizes[0], peak[1], sizes[1], skipped);
        std::fflush(stdout);
        peak[0] = peak[1] = 0;
        skipped = 0;
    }
}
