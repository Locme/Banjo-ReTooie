// Developer aid for headless runs: with TOOIE_WATCH set to a comma-separated
// list of RDRAM addresses (hex), prints those words every two seconds.
//     TOOIE_WATCH=80079138,8007913C ./BanjoTooieN64Recomp --game bt

#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <thread>
#include <vector>

#include "tooie_game.h"

void tooie::start_debug_watch(uint8_t* rdram) {
    const char* env = std::getenv("TOOIE_WATCH");
    if (env == nullptr || *env == '\0') {
        return;
    }
    std::vector<uint32_t> addrs;
    std::string list{env};
    size_t pos = 0;
    while (pos < list.size()) {
        size_t comma = list.find(',', pos);
        addrs.push_back((uint32_t)std::stoul(list.substr(pos, comma - pos), nullptr, 16));
        pos = (comma == std::string::npos) ? list.size() : comma + 1;
    }
    std::thread([rdram, addrs]() {
        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(2));
            fprintf(stderr, "[watch]");
            for (uint32_t addr : addrs) {
                int32_t value = *(int32_t*)(rdram + ((addr & ~3u) - 0x80000000u));
                fprintf(stderr, " %08X=%08X", addr, (uint32_t)value);
            }
            fprintf(stderr, "\n");
        }
    }).detach();
}
