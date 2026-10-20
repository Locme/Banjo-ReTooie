// Aim trace (L, 2026-10-20): the game has no shared "chase the player" code, so which function an enemy reads
// the player's position from has to be found by watching it. With DEV > Aim trace on, the three getters the
// game uses (func_800F5A00 and func_800F5A2C by player index, func_8008FE68 as a wrapper) count their callers by
// return address; every 5 seconds the table is rewritten to logs/aim_trace.txt as "getter caller count"
// (caller is the address the getter returns to, to be matched to a function in RecompiledFuncs). Play a minute
// near the enemies in question and send the file. It changes nothing in the game.

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <map>
#include <mutex>
#include <utility>
#include <variant>

#include "recomp.h"
#include "librecomp/game.hpp"
#include "recompui/config.h"
#include "tooie_aim_trace.h"
#include "tooie_game.h"

namespace {
    using clock_type = std::chrono::steady_clock;

    std::mutex trace_mutex;
    std::map<std::pair<int, uint32_t>, uint64_t> counts;
    clock_type::time_point last_flush = clock_type::now();
    clock_type::time_point last_option_check{};
    bool option_on = false;
    bool dirty = false;

    bool check_option() {
        const auto now = clock_type::now();
        if (now - last_option_check > std::chrono::seconds(1)) {
            last_option_check = now;
            try {
                option_on = std::get<bool>(recompui::config::get_config(tooie::wip_tab_id).get_option_value(tooie::aim_trace::option));
            } catch (...) {
                option_on = false;
            }
        }
        return option_on;
    }

    void flush() {
        std::error_code ec;
        const std::filesystem::path dir = recomp::get_config_path() / "logs";
        std::filesystem::create_directories(dir, ec);
        std::ofstream out(dir / "aim_trace.txt", std::ios::trunc);
        if (!out.good()) {
            return;
        }
        static const char* names[] = { "func_800F5A00", "func_800F5A2C", "func_8008FE68" };
        out << "getter caller count\n";
        for (const auto& [key, n] : counts) {
            char line[96];
            std::snprintf(line, sizeof(line), "%s 0x%08X %llu\n", names[key.first], key.second, (unsigned long long)n);
            out << line;
        }
    }
}

void tooie::aim_trace::add_option(recomp::config::Config& wip) {
    wip.add_bool_option(
        option,
        "Aim trace",
        "For testing. Writes logs/aim_trace.txt, listing which game code reads Banjo's position and how often, so enemy chase code can be found. Play a minute near the enemies in question, then send the file.",
        false);
}

// Entry of func_800F5A00 (getter 0), func_800F5A2C (1) and func_8008FE68 (2): $ra is the caller.
extern "C" void tooie_aim_trace(uint8_t* rdram, recomp_context* ctx, int getter) {
    if (!check_option()) {
        return;
    }
    std::lock_guard lock{ trace_mutex };
    counts[{ getter, (uint32_t)ctx->r31 }]++;
    dirty = true;
    const auto now = clock_type::now();
    if (now - last_flush > std::chrono::seconds(5)) {
        last_flush = now;
        flush();
        dirty = false;
    }
}
