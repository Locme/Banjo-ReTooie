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
//
// Free blocks are also on a free list, smallest first, through prev_free and next_free at +0x10 and
// +0x14: the first 8 bytes of what the block held while in use, so a write to an object after it was
// freed lands there. In L's sweep of 2026-11-07, arriving in GI Floor 3 (0x109), a link held
// 0xC4961900 (the float -1200.8); heap_alloc_sided and heap_merge_free_block followed it and the game
// hung. The free list is now checked at the start of every heap_alloc_sided and after the block list
// above; a link outside the heap, to a block that isn't free, or that doesn't link back gets the
// whole free list rebuilt from the block list, logged as [heap] with the map.

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>

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

    // A block's state: bits 7-6 of its header's fourth word (0 free, 1 used, 2 fixed).
    uint32_t block_state(uint8_t* rdram, uint32_t block) {
        return (read_word(rdram, block + 0xC) >> 6) & 3;
    }

    bool heap_bounds(uint8_t* rdram, uint32_t& start, uint32_t& end) {
        start = read_word(rdram, heap_start_address);
        const uint32_t size = read_word(rdram, heap_size_address);
        end = start + size;
        return start >= 0x80000000u && size != 0 && end <= 0x81000000u && end > start;
    }

    // Walks the free list from the first block's next_free to the last block. Returns 0 when every link
    // is a free block in the heap that links back, else the address of the link that is not.
    uint32_t free_list_damage(uint8_t* rdram, uint32_t start, uint32_t end, uint32_t& bad_value) {
        const uint32_t last = end - 0x20;
        uint32_t prev = start;
        uint32_t cur = read_word(rdram, start + 0x14);
        for (int steps = 0; steps < 200000; steps++) {
            if (cur == last) {
                return (read_word(rdram, last + 0x10) == prev) ? 0 : last + 0x10;
            }
            if ((cur & 0xF) != (start & 0xF) || cur <= start || cur >= last || block_state(rdram, cur) != 0 ||
                read_word(rdram, cur + 0x10) != prev) {
                bad_value = cur;
                return prev + 0x14;
            }
            prev = cur;
            cur = read_word(rdram, cur + 0x14);
        }
        bad_value = cur;
        return prev + 0x14;
    }

    // Links every free block of the block list into a new free list, smallest first (the order
    // heap_merge_free_block keeps it in), between the fixed first and last blocks. Needs a good block list.
    bool rebuild_free_list(uint8_t* rdram, uint32_t start, uint32_t end) {
        const uint32_t last = end - 0x20;
        static std::vector<std::pair<uint32_t, uint32_t>> blocks; // (size, address)
        blocks.clear();
        uint32_t cur = read_word(rdram, start + 4);
        for (int steps = 0; steps < 200000 && cur != last; steps++) {
            const uint32_t next = read_word(rdram, cur + 4);
            if (!good_link(rdram, cur, next, start, end)) {
                return false;
            }
            if (block_state(rdram, cur) == 0) {
                blocks.emplace_back(next - cur, cur);
            }
            cur = next;
        }
        if (cur != last) {
            return false;
        }
        std::stable_sort(blocks.begin(), blocks.end(),
            [](const auto& a, const auto& b) { return a.first < b.first; });
        uint32_t prev = start;
        for (const auto& b : blocks) {
            MEM_W(0, (int32_t)(prev + 0x14)) = (int32_t)b.second;
            MEM_W(0, (int32_t)(b.second + 0x10)) = (int32_t)prev;
            prev = b.second;
        }
        MEM_W(0, (int32_t)(prev + 0x14)) = (int32_t)last;
        MEM_W(0, (int32_t)(last + 0x10)) = (int32_t)prev;
        return true;
    }

    // Checks the free list and rebuilds it when a link is bad (L's sweep hang of 2026-11-07: a free
    // block's link held 0xC4961900, the float -1200.8, written into the block after it was freed).
    void guard_free_list(uint8_t* rdram, uint32_t start, uint32_t end) {
        uint32_t bad_value = 0;
        const uint32_t at = free_list_damage(rdram, start, end, bad_value);
        if (at == 0) {
            return;
        }
        const unsigned map = (unsigned)(uint16_t)MEM_HU(0, (int32_t)0x80132DC2);
        if (!rebuild_free_list(rdram, start, end)) {
            std::printf("[heap] free list link at %08X holds %08X (map %03X); the block list is broken too, left as it was\n",
                at, bad_value, map);
            std::fflush(stdout);
            tooie::toast::show("HEAP error: could not repair it, the game may crash");
            return;
        }
        std::printf("[heap] free list link at %08X held %08X (map %03X); free list rebuilt from the block list\n",
            at, bad_value, map);
        std::fflush(stdout);
        tooie::toast::show("HEAP error repaired (details in console.log)");
    }
}

// At the start of heap_alloc_sided: the free list only, which is short, so it costs little on every allocation.
extern "C" void tooie_heap_free_list_guard(uint8_t* rdram, recomp_context* ctx) {
    (void)ctx;
    uint32_t start = 0, end = 0;
    if (!heap_bounds(rdram, start, end)) {
        return;
    }
    // Headless test: TOOIE_HEAP_BREAK_FREE=<n> writes the float -1200.8 (0xC4961900) over the first free
    // block's next_free at the nth allocation, as in L's sweep hang. TOOIE_HEAP_FREE_GUARD=0 leaves the
    // free list unrepaired, to see the hang again.
    static const long break_at = std::getenv("TOOIE_HEAP_BREAK_FREE") ? std::atol(std::getenv("TOOIE_HEAP_BREAK_FREE")) : 0;
    static const bool repair = !(std::getenv("TOOIE_HEAP_FREE_GUARD") && std::atol(std::getenv("TOOIE_HEAP_FREE_GUARD")) == 0);
    static long calls = 0;
    if (++calls == break_at) {
        const uint32_t first_free = read_word(rdram, start + 0x14);
        if (first_free != end - 0x20) {
            MEM_W(0, (int32_t)(first_free + 0x14)) = (int32_t)0xC4961900u;
            std::printf("[heap] test: wrote C4961900 over free block %08X's next_free\n", first_free);
            std::fflush(stdout);
        }
    }
    if (repair) {
        guard_free_list(rdram, start, end);
    }
}

extern "C" void tooie_heap_guard(uint8_t* rdram, recomp_context* ctx) {
    (void)ctx;
    uint32_t start = 0, end = 0;
    if (!heap_bounds(rdram, start, end)) {
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
            break;
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
    guard_free_list(rdram, start, end);
}
