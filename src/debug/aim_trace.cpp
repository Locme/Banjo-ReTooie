// Aim trace (L, 2026-10-20): the game has no shared "chase the player" code, so which functions read the
// player's position has to be found by watching play. The recompiled code does not keep return addresses, so
// the first version, which counted the callers of the position getters by return address, only logged 0. Now
// every function that calls a getter (func_800F5A00, func_800F5A2C, func_8008FE68; generated hooks at their
// entry, player states left out) counts its own calls under its name. With DEV > Aim trace on, the counts are
// rewritten to aim_trace.txt in the Dev Files folder every 5 seconds as "caller count". Play near the enemies in question and
// send the file. It changes nothing in the game.

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <map>
#include <mutex>
#include <string>
#include <variant>

#include "recomp.h"
#include "librecomp/game.hpp"
#include "recompui/config.h"
#include "tooie_aim_trace.h"
#include "tooie_dev_files.h"
#include "tooie_game.h"

namespace {
    using clock_type = std::chrono::steady_clock;

    std::mutex trace_mutex;
    std::map<std::string, uint64_t> counts;
    clock_type::time_point last_flush = clock_type::now();
    clock_type::time_point last_option_check{};
    bool option_on = false;
    bool dirty = false;
    bool capturing = false;

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
        return option_on || capturing;
    }

    void flush() {
        std::ofstream out(tooie::dev_files::path("aim_trace.txt"), std::ios::trunc);
        if (!out.good()) {
            return;
        }
        out << "caller count\n";
        for (const auto& [name, n] : counts) {
            out << name << ' ' << n << '\n';
        }
    }
}

void tooie::aim_trace::add_option(recomp::config::Config& wip) {
    wip.add_bool_option(
        option,
        "Aim trace",
        "For testing. Writes aim_trace.txt in the Dev Files folder, listing which game code reads Banjo's position and how often, so enemy chase code can be found. Play a minute near the enemies in question, then send the file.",
        false);
    wip.add_bool_option(
        sweep_option,
        "Aim sweep",
        "For testing. Needs a save being played. Spawns each enemy next to Banjo in turn (reloading the area between them), counts which game code reads his position while it is alive, and writes aim_sweep.txt in the Dev Files folder. It turns itself off when done (about 25 minutes). Stand somewhere open, such as Spiral Mountain.",
        false);
}

// Entry of each function that calls a player-position getter; caller is its name.
extern "C" void tooie_aim_trace(uint8_t* rdram, recomp_context* ctx, const char* caller) {
    if (!check_option()) {
        return;
    }
    std::lock_guard lock{ trace_mutex };
    counts[caller]++;
    dirty = true;
    const auto now = clock_type::now();
    if (!capturing && now - last_flush > std::chrono::seconds(5)) {
        last_flush = now;
        flush();
        dirty = false;
    }
}

void tooie::aim_trace::capture_begin() {
    std::lock_guard lock{ trace_mutex };
    counts.clear();
    capturing = true;
}

std::map<std::string, uint64_t> tooie::aim_trace::capture_end() {
    std::lock_guard lock{ trace_mutex };
    capturing = false;
    std::map<std::string, uint64_t> result;
    result.swap(counts);
    return result;
}

bool tooie::aim_trace::sweep_requested() {
    try {
        return std::get<bool>(recompui::config::get_config(tooie::wip_tab_id).get_option_value(sweep_option));
    } catch (...) {
        return false;
    }
}

void tooie::aim_trace::sweep_finished() {
    try {
        recompui::config::get_config(tooie::wip_tab_id).update_option_value(sweep_option, false);
    } catch (...) {
    }
}
