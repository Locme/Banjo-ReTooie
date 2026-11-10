#ifndef __TOOIE_WRITE_WATCH_H__
#define __TOOIE_WRITE_WATCH_H__

#include <cstdint>
#include <string>

// A hardware write watch on one RDRAM word (src/debug/write_watch.cpp, console `writewatch`).
namespace tooie::write_watch {
    // Watches writes to the word for the given seconds on the calling thread (the game thread when the console runs
    // it), then prints the host functions that wrote it, with their callers. Returns the line to print, or "ERR " text.
    std::string start(uint8_t* rdram, uint32_t address, double seconds);
}

#endif
