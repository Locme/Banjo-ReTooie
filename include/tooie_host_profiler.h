#ifndef __TOOIE_HOST_PROFILER_H__
#define __TOOIE_HOST_PROFILER_H__

#include <cstdint>
#include <string>

// Sampling profiler of the whole process (src/debug/host_profiler.cpp), for the console's hostprof command. Windows
// only; elsewhere start returns false.
namespace tooie::host_profiler {
    // Starts sampling (or starts over, forgetting what was counted) into the file, written every 5 s and on stop.
    bool start(const std::string& path);
    // Writes the file and stops; returns the samples taken.
    uint64_t stop();
    // Samples from now on are counted under this label (a map, a scene); "-" until one is set.
    void label(const std::string& text);
    bool running();
    std::string path();
}

#endif
