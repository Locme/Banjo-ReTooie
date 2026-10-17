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
// tooie_list_end_guard() runs twice as the game closes the frame's list: before
// func_800C940C, which draws the transition (fades, the warp's fade-in) and the
// viewport, and before func_800E7EF4, which adds the full sync and the end. L's
// crash of 2026-10-17 12:22:25 was one frame right after a warp into Icy Side
// that filled the whole 256 KB list buffer (normally about 10 KB there); the
// commands after it landed on the heap block that follows the buffer and broke
// the heap. What filled it is not known (it did not happen headless). The guard
// keeps the end of the list inside the buffer by moving the head back over the
// frame's last commands when it is within reach of the end: that frame loses a
// little of its drawing instead of the heap. Logged once per map as [gfx] list
// full, with the map and how full the buffer was, to find the cause next time.
// A head already past the end has damaged the heap; that is logged every time.
//
// TOOIE_GFX_LOG=1: every 2 s, the most of each buffer a frame used.
// TOOIE_GFX_FILL=<bytes>: test aid, on one frame in Icy Side (0x128) moves the
// list head that far on before the guard runs, as a frame that drew that much
// more would.

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

extern "C" void tooie_list_end_guard(uint8_t* rdram, recomp_context* ctx, int step) {
    (void)ctx;
    const uint32_t b0 = (uint32_t)MEM_W(0, buffers_addr);
    const uint32_t b1 = (uint32_t)MEM_W(4, buffers_addr);
    const int index = MEM_H(0, index_addr);
    if (b1 <= b0 || (index != 0 && index != 1)) {
        return;
    }
    const uint32_t start = index == 0 ? b0 : b1;
    // The buffers are heap blocks: b1 - b0 is one buffer and the 16-byte heap header after it.
    const uint32_t end = start + (b1 - b0) - 0x10;
    // Step 0, before the transition: room for it, the viewport and the closing
    // commands (the transition normally adds under 0x100 bytes).
    // Step 1, after it: room for the full sync and end (0x10 bytes).
    const uint32_t tail = step == 0 ? 0x800 : 0x10;
    static const uint32_t test_fill = [] {
        const char* env = std::getenv("TOOIE_GFX_FILL");
        return env ? (uint32_t)std::strtoul(env, nullptr, 0) : 0u;
    }();
    uint32_t head = (uint32_t)MEM_W(0, heads_addr);
    static bool test_filled = false;
    if (step == 0 && test_fill != 0 && !test_filled && head >= start && head < end
        && MEM_HU(0, (int32_t)0x80132DC2) == 0x128) {
        test_filled = true;
        // Fill with no-ops (G_NOOP), as real drawing would, then move the head on.
        const uint32_t target = std::min(head + (test_fill & ~7u), end);
        for (uint32_t a = head; a < target; a += 8) {
            MEM_W(0, (int32_t)a) = 0;
            MEM_W(4, (int32_t)a) = 0;
        }
        head = target;
        MEM_W(0, heads_addr) = (int32_t)head;
    }
    if (head < start || head >= start + 2 * (b1 - b0) || head + tail <= end) {
        return;
    }
    static uint16_t logged_map = 0xFFFF;
    const uint16_t map = (uint16_t)MEM_HU(0, (int32_t)0x80132DC2);
    if (head > end) {
        // Already past the end: the heap after the buffer is damaged. Pulling the
        // head back still keeps the closing commands off it.
        std::fprintf(stderr, "[gfx] list ran %X bytes past its buffer in map 0x%X (%s the transition); the heap after it is damaged\n",
            head - end, map, step == 0 ? "before" : "in");
    } else if (map != logged_map) {
        logged_map = map;
        std::fprintf(stderr, "[gfx] list full in map 0x%X: %X of %X used; the frame's last commands were dropped so the heap stays intact\n",
            map, head - start, end - start);
    }
    MEM_W(0, heads_addr) = (int32_t)(end - tail);
}

bool tooie::gfx_budget::room_for_extras(uint8_t* rdram) {
    for (int pool = 0; pool < 2; pool++) {
        uint32_t used, size;
        // Not in a known buffer (a few rooms draw into their own table at
        // D_8007BCE8, which this does not measure): no extras rather than
        // unguarded ones.
        if (!usage(rdram, pool, &used, &size) || used + margin[pool] > size) {
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
