// Preemption points for the game's busy-wait loops.
//
// On the console, a thread spinning on a flag is interrupted when a
// higher-priority thread's message arrives (a timer, the audio interface, a
// DMA). The runtime only switches threads inside OS calls, so a loop that
// makes no OS call never lets the thread it waits for run. Hooks placed in
// such loops (banjotooie.us.toml) call tooie_preempt_point, which delivers the
// messages that have arrived and switches to any thread that now outranks the
// current one, as the interrupt would have.

#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <thread>

#include "recomp.h"
#include "tooie_hooks.h"
#include "ultramodern/ultramodern.hpp"

void dequeue_external_messages(uint8_t* rdram);

extern "C" void tooie_preempt_point(uint8_t* rdram, recomp_context* /*ctx*/) {
    std::this_thread::yield();
    dequeue_external_messages(rdram);
    ultramodern::check_running_queue(rdram);
}

// func_800C2AB8 (before a map change) waits until every sound slot that is
// stopping (state 3) has had its sound released by the audio side: slot i is
// 0x80 bytes at 0x80128B90 + i * 0x80, its handle is the byte at +0x79, and
// the sound is still held while the word at 0x80128B08 + handle * 8 is not 0.
// In L's hang of 2026-10-16 one slot never let go and the game spun here for
// good. After 2 s this frees such a slot the way the game does (func_800C16A4)
// and logs it, so the map change goes on.
namespace {
    constexpr uint32_t sound_slots = 0x80128B90;
    constexpr uint32_t sound_handles = 0x80128B08;
    constexpr int sound_slot_count = 0x3C;
    constexpr auto sound_wait_limit = std::chrono::seconds(2);

    gpr k0(uint32_t addr) {
        return (gpr)(int64_t)(int32_t)addr;
    }
}

extern "C" void tooie_sound_slot_wait(uint8_t* rdram, recomp_context* ctx) {
    using clock_type = std::chrono::steady_clock;
    static clock_type::time_point wait_start{};
    static clock_type::time_point last_pass{};
    auto now = clock_type::now();
    // Passes come back to back while the game waits; a gap means a new wait.
    if (now - last_pass > std::chrono::milliseconds(250)) {
        wait_start = now;
    }
    last_pass = now;

    tooie_preempt_point(rdram, ctx);

    // TOOIE_TEST_STUCK_SOUND=1 holds the first waited-on sound for good, to check the release below.
    static const bool test_stuck = std::getenv("TOOIE_TEST_STUCK_SOUND") != nullptr;
    static int test_handle = -1;
    if (test_stuck && test_handle != 0) {
        for (int i = 1; i < sound_slot_count && test_handle == -1; i++) {
            gpr slot = k0(sound_slots + i * 0x80);
            if (MEM_BU(0x78, slot) != 0 && ((MEM_W(0x78, slot) >> 10) & 7) == 3 && MEM_BU(0x79, slot) != 0) {
                test_handle = MEM_BU(0x79, slot);
                std::printf("[sound] TOOIE_TEST_STUCK_SOUND: holding handle %d\n", test_handle);
            }
        }
        if (test_handle > 0) {
            gpr entry = k0(sound_handles + test_handle * 8);
            if (MEM_W(0, entry) == 0) {
                MEM_W(0, entry) = 0x80000400;
            }
        }
    }

    if (now - wait_start < sound_wait_limit) {
        return;
    }
    for (int i = 1; i < sound_slot_count; i++) {
        gpr slot = k0(sound_slots + i * 0x80);
        if (MEM_BU(0x78, slot) == 0 || ((MEM_W(0x78, slot) >> 10) & 7) != 3) {
            continue;
        }
        uint8_t handle = MEM_BU(0x79, slot);
        if (handle == 0 || MEM_W(0, k0(sound_handles + handle * 8)) == 0) {
            continue;
        }
        std::printf("[sound] map change waited %.1f s for sound slot %d (handle %u, slot word 0x%08X, sound object 0x%08X); freeing it\n",
            std::chrono::duration<double>(now - wait_start).count(), i, (unsigned)handle,
            (uint32_t)MEM_W(0x78, slot), (uint32_t)MEM_W(0, k0(sound_handles + handle * 8)));
        std::fflush(stdout);
        // As func_800C16A4: drop the handle's second word, the handle and the slot.
        MEM_W(4, k0(sound_handles + handle * 8)) = 0;
        MEM_B(0x79, slot) = 0;
        MEM_B(0x78, slot) = 0;
        if (handle == test_handle) {
            MEM_W(0, k0(sound_handles + handle * 8)) = 0;
            test_handle = 0;
        }
    }
    wait_start = now;
}
