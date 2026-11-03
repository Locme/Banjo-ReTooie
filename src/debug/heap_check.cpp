// Heap check: walks the game's heap once per game frame and logs the first damage it finds (a
// block list or free list link that does not match, a bad block state), with the blocks around
// it and the map. A PC crash in the allocator (heap_alloc_sided, 120 FPS, 7e04c77) found model
// display-list data where a free block's header should be; this says when and where that starts.
// It is cheap (the heap has tens to hundreds of blocks) and on by default; DEV > Heap check or
// TOOIE_HEAP_CHECK=0 turns it off. Headless, a 10-level tour at 120 FPS with and without HD Shadows found no damage.
// Heap layout (decomp include/memory.h): blocks from the address held at 0x8007E990 to that plus
// the size at 0x8007BF00, each with a 16-byte header (prev, next, unk8, bits: overhead 24, state 2, ...) and,
// when free, prev_free/next_free at +0x10/+0x14. The first and last blocks are fixed dummies.

#include <atomic>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <variant>

#include "recomp.h"
#include "recompui/config.h"
#include "tooie_game.h"
#include "tooie_debug.h"
#include "tooie_toast.h"

namespace {
    uint32_t heap_start = 0;
    uint32_t word(uint8_t* rdram, uint32_t addr) { return (uint32_t)MEM_W(0, (gpr)(int32_t)addr); }
    uint32_t state(uint8_t* rdram, uint32_t block) { return (word(rdram, block + 0xC) >> 6) & 3; }

    void dump(uint8_t* rdram, const char* what, uint32_t block) {
        if (block < 0x80000000u || block >= 0x81000000u) {
            fprintf(stderr, "[heap]   %s %08X (outside RDRAM)\n", what, block);
            return;
        }
        fprintf(stderr, "[heap]   %s %08X:", what, block);
        for (int i = 0; i < 8; i++) fprintf(stderr, " %08X", word(rdram, block + 4 * i));
        fprintf(stderr, "\n");
    }
}

namespace {
    std::atomic<bool> option_on{true};

    bool env_off() {
        const char* v = std::getenv("TOOIE_HEAP_CHECK");
        return v != nullptr && std::strcmp(v, "0") == 0;
    }
}

void tooie::debug::add_heap_check_option(recomp::config::Config& wip) {
    wip.add_bool_option(
        heap_check_option,
        "Heap Check",
        "For testing. Checks the game's memory once per frame and writes the first damage it finds to the log, "
        "to help track down crashes. It costs almost nothing; turn it off only to rule it out.",
        true);
    wip.add_option_change_callback(heap_check_option,
        [](recomp::config::ConfigValueVariant value, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
            if (context == recomp::config::OptionChangeContext::Temporary) {
                recompui::config::get_config(tooie::wip_tab_id).save_config();
                return;
            }
            const auto* v = std::get_if<bool>(&value);
            option_on = (v == nullptr) || *v;
        });
}

void tooie::debug::apply_heap_check() {
    try {
        option_on = std::get<bool>(recompui::config::get_config(tooie::wip_tab_id).get_option_value(heap_check_option));
    } catch (...) {
    }
}

void tooie::debug::heap_check(uint8_t* rdram, const char* where) {
    static const bool off_for_run = env_off();
    static const bool log_ok = std::getenv("TOOIE_HEAP_CHECK") != nullptr;
    static bool reported = false;
    static unsigned checks = 0;
    if (off_for_run || !option_on.load(std::memory_order_relaxed) || reported) {
        return;
    }
    checks++;
    heap_start = word(rdram, 0x8007E990);
    uint32_t size = word(rdram, 0x8007BF00);
    uint32_t end = heap_start + size;
    if (heap_start < 0x80000000u || size == 0 || end > 0x81000000u) {
        return;
    }
    uint32_t last = end - 0x20;
    // The free blocks, in address order (the walk goes up through the heap), kept between checks so a check
    // makes no allocations.
    static std::vector<uint32_t> free_blocks;
    free_blocks.clear();
    uint32_t block = heap_start;
    unsigned n = 0;
    const char* problem = nullptr;
    uint32_t bad = 0, before = 0;
    while (block != end) {
        uint32_t next = word(rdram, block + 4);
        if (next <= block || next > end || (next & 0xF) != (heap_start & 0xF)) { problem = "block's next link is bad"; bad = block; break; }
        if (next != end && word(rdram, next) != block) { problem = "next block's prev link does not point back"; bad = next; before = block; break; }
        uint32_t s = state(rdram, block);
        if (s == 3) { problem = "block state is 3"; bad = block; break; }
        if (s == 0) free_blocks.push_back(block);
        before = block;
        block = next;
        if (++n > 2000000) { problem = "block list does not end"; break; }
    }
    if (!problem) {
        uint32_t f = word(rdram, heap_start + 0x14);
        uint32_t prev = heap_start;
        n = 0;
        while (f != last) {
            if (!std::binary_search(free_blocks.begin(), free_blocks.end(), f)) { problem = "free list entry is not a free block"; bad = f; before = prev; break; }
            if (word(rdram, f + 0x10) != prev) { problem = "free list prev link does not point back"; bad = f; before = prev; break; }
            prev = f;
            f = word(rdram, f + 0x14);
            if (++n > 2000000) { problem = "free list does not end"; break; }
        }
    }
    if (problem) {
        reported = true;
        fprintf(stderr, "[heap] damage found at %s (check %u, map %03X): %s\n", where, checks,
            (unsigned)(uint16_t)MEM_HU(0, (gpr)(int32_t)0x80132DC2), problem);
        tooie::toast::show("HEAP error: damage found (details in console.log)");
        dump(rdram, "bad", bad);
        if (before) dump(rdram, "before", before);
        std::fflush(stderr);
    } else if (log_ok && (checks % 600) == 0) {
        fprintf(stderr, "[heap] ok after %u checks (%zu free blocks)\n", checks, free_blocks.size());
        std::fflush(stderr);
    }
}
