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

    struct Queued {
        uint32_t sum;
        uint32_t size;
        int waiting;
    };

    std::mutex mutex;
    std::unordered_map<uint32_t, Queued> lists;
    unsigned changed = 0;

    bool in_rdram(uint32_t addr, uint32_t size) {
        return addr >= 0x80000000u && size <= 0x10000 && addr + size <= 0x80800000u;
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
    if (!in_rdram(start, size)) {
        return;
    }
    int waiting = (((int32_t)MEM_W(0, ring_write_addr) - (int32_t)MEM_W(0, ring_read_addr)) % ring_slots + ring_slots) % ring_slots;
    std::lock_guard lock{ mutex };
    lists[start] = Queued{ checksum(rdram, start, size), size, waiting };
}
