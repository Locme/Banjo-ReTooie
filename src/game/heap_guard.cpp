// Heap guard: repairs a broken link in the game's heap block list before the game walks it.
//
// The heap (lib/bt-decomp/src/core1/heap.c) is a list of blocks in address order, each starting with a
// 16-byte header: +0x0 the previous block, +0x4 the next one. L's crash of 2026-10-15
// (crash_2026-10-15_14-09-59.dmp) was func_8001C0A0, the walk for heap_alloc_sided's third kind of
// allocation, following a next link of 0x0025EBB8: a block address that had lost its top bit, so the
// walk read outside RDRAM. Something wrote over that header; what wrote it isn't known yet.
//
// banjotooie.us.toml hooks the start of func_8001C0A0 to walk the list first. A link that points
// outside the heap, backwards, or at a block that doesn't point back is repaired from the block that
// does point back (the link with its top bit restored, or else the first header found after this block
// whose previous link is this block). Each repair is logged as [heap], with the bad value, to help find
// the writer, and shown in game as a "HEAP error" notice. A list that can't be repaired is left as it was.

#include <cstdint>
#include <cstdio>
#include <cstdlib>

#include "recomp.h"
#include "tooie_hooks.h"
#include "tooie_toast.h"

namespace {
    constexpr uint32_t heap_start_address = 0x8007E990; // D_8007E990, the heap's start
    constexpr uint32_t heap_size_address = 0x8007BF00;  // D_8007BF00, its size (heap_setup)
    // Far enough to step over any one allocation the game makes when looking for the block that points back.
    constexpr uint32_t search_limit = 0x100000;

    uint32_t read_word(uint8_t* rdram, uint32_t address) {
        return (uint32_t)MEM_W(0, (int32_t)address);
    }

    // True when next is a block after cur in the heap that links back to cur (or the heap's end).
    bool good_link(uint8_t* rdram, uint32_t cur, uint32_t next, uint32_t start, uint32_t end) {
        if ((next & 3) != 0 || next <= cur || next > end || next < start) {
            return false;
        }
        return (next == end) || (read_word(rdram, next) == cur);
    }
}

extern "C" void tooie_heap_guard(uint8_t* rdram, recomp_context* ctx) {
    (void)ctx;
    const uint32_t start = read_word(rdram, heap_start_address);
    const uint32_t size = read_word(rdram, heap_size_address);
    const uint32_t end = start + size;
    if (start < 0x80000000u || size == 0 || end > 0x81000000u || end <= start) {
        return;
    }
    // Headless test: TOOIE_HEAP_BREAK=<n> clears the top bit of a link on the nth call, as in L's crash.
    static const long break_at = std::getenv("TOOIE_HEAP_BREAK") ? std::atol(std::getenv("TOOIE_HEAP_BREAK")) : 0;
    static long calls = 0;
    if (++calls == break_at) {
        uint32_t block = start;
        for (int i = 0; i < 40 && read_word(rdram, block + 4) != end; i++) {
            block = read_word(rdram, block + 4);
        }
        const uint32_t next = read_word(rdram, block + 4);
        // TOOIE_HEAP_BREAK_VALUE writes that value instead.
        const char* value = std::getenv("TOOIE_HEAP_BREAK_VALUE");
        MEM_W(0, (int32_t)(block + 4)) = (int32_t)(value ? (uint32_t)std::strtoul(value, nullptr, 16) : (next & 0x7FFFFFFFu));
        std::printf("[heap] test: broke block %08X's next link %08X\n", block, next);
    }
    uint32_t cur = start;
    for (int steps = 0; steps < 200000 && cur < end; steps++) {
        const uint32_t next = read_word(rdram, cur + 4);
        if (next == end) {
            return;
        }
        if (good_link(rdram, cur, next, start, end)) {
            cur = next;
            continue;
        }
        uint32_t fixed = 0;
        if (good_link(rdram, cur, next | 0x80000000u, start, end)) {
            fixed = next | 0x80000000u;
        }
        else {
            const uint32_t limit = (end - cur > search_limit) ? cur + search_limit : end;
            for (uint32_t at = cur + 0x10; at + 8 <= limit; at += 4) {
                if (read_word(rdram, at) == cur && good_link(rdram, cur, at, start, end) && (read_word(rdram, at + 4) > at)) {
                    fixed = at;
                    break;
                }
            }
        }
        if (fixed == 0) {
            std::printf("[heap] block %08X has a broken next link %08X; no block links back, left as it was\n", cur, next);
            std::fflush(stdout);
            tooie::toast::show("HEAP error: could not repair it, the game may crash");
            return;
        }
        std::printf("[heap] block %08X had a broken next link %08X; repaired to %08X\n", cur, next, fixed);
        std::fflush(stdout);
        MEM_W(0, (int32_t)(cur + 4)) = (int32_t)fixed;
        tooie::toast::show("HEAP error repaired (details in console.log)");
        cur = fixed;
    }
}
