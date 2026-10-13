// Developer aid for headless runs: with TOOIE_WATCH set to a comma-separated
// list of RDRAM addresses (hex), prints those words every two seconds. An
// entry `addr+len` (both hex) prints every word in that range.
//     TOOIE_WATCH=80079138,80128B00+90 ./BanjoTooieN64Recomp --game bt

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
        std::string entry = list.substr(pos, comma - pos);
        size_t plus = entry.find('+');
        uint32_t addr = (uint32_t)std::stoul(entry.substr(0, plus), nullptr, 16);
        uint32_t len = plus == std::string::npos ? 4 : (uint32_t)std::stoul(entry.substr(plus + 1), nullptr, 16);
        for (uint32_t offset = 0; offset < len; offset += 4) {
            addrs.push_back(addr + offset);
        }
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
