#ifndef __TOOIE_CONSOLE_H__
#define __TOOIE_CONSOLE_H__

#include <cstdint>
#include <string>

#include "recomp.h"

// Developer console (src/game/console.cpp, ported from the Mario Party 3 port's): a prompt on the ` key, commands on
// stdin, --exec <file> and TOOIE_CONSOLE="cmd; cmd". Results go to stdout as "[command] text".
namespace tooie::console {
    // Program start, before recomp::start: loads console.txt (binds and aliases), queues --exec and TOOIE_CONSOLE, and
    // starts the stdin and before-the-game threads.
    void start(int argc, char** argv);

    // The exit code for main to return: 1 if any command failed, or the one `quit` was given.
    int exit_code();

    // Queues a line of commands as if typed at the prompt. Safe to call from any thread.
    void run(const std::string& line);

    // Once per game update, on the game thread (tooie_warp_tick), before that update's own work.
    void frame(uint8_t* rdram, recomp_context* ctx);

    // On every read of player 1's pad: a `press` holds buttons and the stick. Returns whether the pad has input.
    // The texture sweep's quick passes ask for a faster game (1 for normal); it multiplies the `timescale` command's.
    void set_sweep_timescale(double scale);

    bool apply_input(int controller, uint16_t* buttons, float* x, float* y, bool got);
}

// Game code that wants a log the console's `log` command can switch calls this with its environment variable name.
// 1 when it is on (from the environment at first, then the console).
extern "C" int tooie_debug_log_on(const char* env_name);

#endif
