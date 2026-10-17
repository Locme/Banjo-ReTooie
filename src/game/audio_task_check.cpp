// Sound task check, for the "Unhandled jump target ... in n_aspMain" crash (seen with Game
// Frame Rate Unlocked on a PC, never headless).
//
// The game builds each sound frame's command list into one of two buffers and queues it in the
// scheduler's ring (func_80013D94, $a0 = an entry: list start at +8, end at +0xC); the scheduler
// later copies it into its one sound OSTask and starts it. If a list were rewritten after it was
// queued and before the RSP read it, the microcode would read a broken list. A checksum taken when
// the list is queued is compared just before the task runs (on the SP task thread), and any
// difference is logged with how many lists were already waiting when it was queued.
//
// A sound task that still fails no longer ends the game: the runtime skips that sound frame
// (lib-patches/N64ModernRuntime.patch, events.cpp).
//
// The cause seen on PCs: the ring holds pointers to requests, and the game takes requests round
// robin from one pool of 20 (0x8007BCF8, 0x18 bytes each, next index at 0x8007BED8) for sound
// (type 0), graphics (type 1) and others, without checking whether one is still waiting. At 30 FPS
// that never matters. At high or uncapped frame rates (and in sped-up cutscene skips) 20 graphics
// frames can be sent while a sound request waits for the RSP, so its slot becomes a graphics
// request and the sound microcode is given a display list (first command DE000000, "Unhandled jump
// target 0x0E5F"). Each queued sound request is now copied into a slot of our own, which stays
// unchanged until well after it has played, and the ring gets the copy.

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <mutex>
#include <unordered_map>

#include "recomp.h"
#include "tooie_hooks.h"
#include "ultramodern/ultramodern.hpp"

namespace {
    constexpr gpr ring_write_addr = (int32_t)0x80078F00;
    constexpr gpr ring_read_addr = (int32_t)0x80078F04;
    constexpr int ring_slots = 20;
    constexpr uint32_t request_size = 0x18;
    // More than the ring can hold plus the one playing, so a copy is never reused while in use.
    constexpr uint32_t copy_slots = 32;
    // Extended RDRAM no one else uses: between the sample DMA list (src/gameplay/mix_rate.cpp, ends at
    // 0x80EE0E10) and the Totals checklist's strings (0x80EF0000). Save states keep it
    // (save_state.cpp's request_copies_start and request_copies_size: keep them in step).
    constexpr gpr copies = (int32_t)0x80EE8000;
    static_assert(0x80EE8000u + copy_slots * request_size <= 0x80EF0000u, "sound request copies run into the Totals strings");

    struct Queued {
        uint32_t sum;
        uint32_t size;
        int waiting;
        uint32_t request; // the game's own request; the ring got a copy
    };

    std::mutex mutex;
    std::unordered_map<uint32_t, Queued> lists;
    unsigned changed = 0;
    unsigned reused = 0;
    uint32_t next_copy = 0;

    bool in_rdram(uint32_t addr, uint32_t size) {
        return addr >= 0x80000000u && size <= 0x10000 && addr + size <= 0x81000000u; // More game memory's lists are at 0x80E80000
    }

    uint32_t checksum(uint8_t* rdram, uint32_t addr, uint32_t size) {
        uint32_t sum = 0x811C9DC5u;
        for (uint32_t i = 0; i + 4 <= size; i += 4) {
            sum = (sum ^ (uint32_t)MEM_W(i, (gpr)(int32_t)addr)) * 0x01000193u;
        }
        return sum;
    }

    void check_audio_task(uint8_t* rdram, const OSTask* task) {
        uint32_t addr = (uint32_t)task->t.data_ptr;
        uint32_t size = task->t.data_size;
        if (!in_rdram(addr, size)) {
            return;
        }
        std::lock_guard lock{ mutex };
        auto found = lists.find(addr);
        if (found == lists.end()) {
            return;
        }
        Queued queued = found->second;
        lists.erase(found);
        if ((uint32_t)MEM_W(8, (gpr)(int32_t)queued.request) != addr) {
            reused++;
            if (reused <= 20) {
                fprintf(stderr, "[audio] A sound request's slot was reused before it played (%u so far); played the kept copy.\n", reused);
            }
        }
        uint32_t sum = checksum(rdram, addr, std::min(size, queued.size));
        if (sum != queued.sum) {
            changed++;
            if (changed <= 20) {
                fprintf(stderr, "[audio] A sound list changed between being queued and playing (%u so far; list %08X, %u lists were waiting).\n",
                    changed, addr, (unsigned)queued.waiting);
            }
        }
    }
}

// func_80013D94, at its start: $a0 is the ring entry about to be queued.
extern "C" void tooie_audio_list_queued(uint8_t* rdram, recomp_context* ctx) {
    static bool registered = false;
    if (!registered) {
        registered = true;
        ultramodern::set_audio_task_check(check_audio_task);
    }
    uint32_t entry = (uint32_t)ctx->r4;
    if (!in_rdram(entry, 0x10)) {
        return;
    }
    uint32_t start = (uint32_t)MEM_W(8, ctx->r4);
    uint32_t end = (uint32_t)MEM_W(0xC, ctx->r4);
    uint32_t size = (end - start) & ~7u;
    std::lock_guard lock{ mutex };
    gpr copy = copies + (gpr)(next_copy * request_size);
    next_copy = (next_copy + 1) % copy_slots;
    for (uint32_t i = 0; i < request_size; i += 4) {
        MEM_W(i, copy) = MEM_W(i, ctx->r4);
    }
    // func_80013D94 puts $a0 in the ring.
    ctx->r4 = copy;
    if (!in_rdram(start, size)) {
        return;
    }
    int waiting = (((int32_t)MEM_W(0, ring_write_addr) - (int32_t)MEM_W(0, ring_read_addr)) % ring_slots + ring_slots) % ring_slots;
    lists[start] = Queued{ checksum(rdram, start, size), size, waiting, entry };
}
