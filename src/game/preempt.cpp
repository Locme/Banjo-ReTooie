// Preemption points for the game's busy-wait loops.
//
// On the console, a thread spinning on a flag is interrupted when a
// higher-priority thread's message arrives (a timer, the audio interface, a
// DMA). The runtime only switches threads inside OS calls, so a loop that
// makes no OS call never lets the thread it waits for run. Hooks placed in
// such loops (banjotooie.us.toml) call tooie_preempt_point, which delivers the
// messages that have arrived and switches to any thread that now outranks the
// current one, as the interrupt would have.

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
