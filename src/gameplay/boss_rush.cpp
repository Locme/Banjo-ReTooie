// Boss rush (L, 2026-10-16).
//
// General > Boss rush fights the game's 13 bosses one after another, in the order the game meets them,
// whatever the save file has reached. It is built on the game's own Boss Replay (the Replay menu on the game
// select screen): gcfrontend_entrypoint_7(replay number, 1) sets the game mode byte (0x8012B3F2) to 2,
// "replay", runs the replay's set-up list (the moves and items the fight needs; the game puts the file's own
// back afterwards) and changes map to the boss's arena. Replay numbers 0x20..0x2C are the bosses (found by
// calling it for every number headless and reading the map it asked for): 0x40.. are the multiplayer games,
// 0x60.. the minigames, 0x80.. the cutscenes (src/gameplay/replays.cpp).
//
// When a replayed fight ends the boss calls gcfrontend_entrypoint_10, which goes back to the game select
// screen (map 0x158). That is the same call after a win and after a loss (when the player answers "No" to
// "Do you want to play again?"; "Yes" restarts the fight in its arena). So when a map change from the arena
// to the game select is asked for, the rush looks at whether the player died in this try (state 0x41, seen
// headless; by the time the change is asked for the state has already moved on) - a loss, which ends the rush; alive is a win, and once the game select has loaded the next boss's replay is started
// from there, as the game's multiplayer mode chains its minigames (func_800AA1A0). Quitting from the pause
// menu during a fight ends the rush too.
//
// Turning the option on starts a rush (the open file is saved first, as Save and quit does, because the
// game select at the end of a replay drops anything unsaved); turning it off stops it after the current
// fight. The option turns itself off when the rush ends. It is not started while Bottles' Revenge is on,
// since that mode holds the same mode byte at 1.
//
// Headless test aids:
//   TOOIE_BOSS_RUSH=<ms>[:<first boss>]  starts a rush that long after the game loop first runs, optionally
//                                        from boss <first> (0-12, rush order) instead of the first
//   TOOIE_BOSS_RUSH_MENU=<ms>            turns the General switch on that long after start, as the menu does
//   TOOIE_BOSS_RUSH_LOSS_IS_WIN=1        counts a loss as a win, to test the chaining without beating bosses
//   TOOIE_REPLAY=<hex>@<ms>              starts that one replay number (TOOIE_REPLAY_SCAN=1: log every number's map)

#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <mutex>
#include <string>
#include <thread>
#include <variant>

#include "recomp.h"
#include "funcs.h"
#include "recompui/config.h"
#include "tooie_boss_rush.h"
#include "tooie_game_frame_rate.h"
#include "tooie_bottles_revenge.h"
#include "tooie_debug.h"
#include "tooie_toast.h"

namespace {
    struct Boss {
        const char* name;
        int replay;      // gcfrontend replay number
        uint16_t map;    // the arena it loads
    };

    // The order the game meets them in. The game's own replay list (and its GFLAG_BC8.. unlock flags) groups
    // the three Klungo fights first instead.
    constexpr Boss bosses[] = {
        { "Klungo", 0x20, 0x141 },
        { "Targitzan", 0x23, 0x17A },
        { "Old King Coal", 0x24, 0x0D1 },
        { "Mr. Patch", 0x25, 0x0F9 },
        { "Lord Woo Fak Fak", 0x26, 0x0FC },
        { "Klungo (second fight)", 0x21, 0x15B },
        { "Terry", 0x27, 0x113 },
        { "Weldar", 0x28, 0x110 },
        { "Chilli Billi", 0x2A, 0x12B },
        { "Chilly Willy", 0x29, 0x12C },
        { "Mingy Jongo", 0x2B, 0x13F },
        { "Klungo (third fight)", 0x22, 0x15E },
        { "Hag 1", 0x2C, 0x15D },
    };
    constexpr int boss_count = sizeof(bosses) / sizeof(bosses[0]);

    constexpr gpr game_mode_addr = (int32_t)0x8012B3F2;
    constexpr gpr game_state_addr = (int32_t)0x80127630; // +0x10 map asked for, +0x12 go byte
    constexpr gpr save_slot_addr = (int32_t)0x8012B3F1;
    constexpr gpr current_level_addr = (int32_t)0x8012762C;
    constexpr gpr pause_menu_addr = (int32_t)0x80128AF0;
    constexpr uint16_t game_select_map = 0x158;
    constexpr uint16_t title_map = 0x18B;
    // Player 0's PlayerState (src/gameplay/player_cheats.cpp): +0x120 state block, +4 the state id.
    constexpr uint32_t player_table = 0x80135490;
    constexpr uint32_t state_dead = 0x41;
    // Game select frames to wait before the next replay is started, so the screen has finished loading.
    constexpr int settle_frames = 20;
    // Real time a replay may take to reach its arena (or the game select) before the rush gives up.
    constexpr auto load_timeout = std::chrono::seconds(60);

    std::atomic<bool> start_requested{false};
    std::atomic<bool> stop_requested{false};
    std::atomic<bool> resetting_option{false};

    // Game thread only from here on.
    enum class Stage { Idle, Fight, Between };
    Stage stage = Stage::Idle;
    int current = 0;
    int frames = 0;
    bool arrived = false;
    // The player has died in this try at the fight (a retry reloads the arena and starts a new try).
    bool died = false;
    bool retrying = false;
    bool stop_after_fight = false;
    std::chrono::steady_clock::time_point stage_started;
    std::chrono::steady_clock::time_point rush_started;

    // Env test requests.
    std::once_flag env_flag;
    std::chrono::steady_clock::time_point env_start;
    int env_rush_first = -1;
    uint32_t env_rush_ms = 0;
    bool loss_is_win = false;
    int env_replay = -1;
    uint32_t env_replay_ms = 0;
    bool env_scan = false;

    bool bottles_on() {
        try {
            return std::get<bool>(recompui::config::get_general_config().get_option_value(tooie::bottles_revenge::option));
        } catch (...) {
            return false;
        }
    }

    // Puts the option back to off when the rush ends (from its own thread: the config belongs to the UI).
    void reset_option() {
        std::thread([] {
            try {
                recomp::config::Config& general = recompui::config::get_general_config();
                resetting_option = true;
                general.set_option_value(tooie::boss_rush::option, false);
                general.save_config();
            } catch (...) {
            }
            resetting_option = false;
        }).detach();
    }

    bool valid_pointer(uint32_t p) {
        return p >= 0x80000000u && p < 0x80800000u;
    }

    uint32_t player_state(uint8_t* rdram) {
        uint32_t player = (uint32_t)MEM_W(0, (int32_t)player_table);
        if (!valid_pointer(player)) {
            return 0;
        }
        uint32_t block = (uint32_t)MEM_W(0x120, (int32_t)player);
        return valid_pointer(block) ? (uint32_t)MEM_W(4, (int32_t)block) : 0;
    }

    bool changing(uint8_t* rdram) {
        return MEM_BU(0x12, game_state_addr) != 0;
    }

    uint16_t change_target(uint8_t* rdram) {
        return (uint16_t)MEM_HU(0x10, game_state_addr);
    }

    // The game's own replay start, as the game select's Replay menu and the multiplayer mode call it.
    void start_replay(uint8_t* rdram, recomp_context* ctx, int replay) {
        recomp_context saved = *ctx;
        ctx->r29 = (int32_t)((((uint32_t)ctx->r29 - 0x100) & ~0xFu));
        ctx->r4 = (uint64_t)(int64_t)replay;
        ctx->r5 = 1;
        _gcfrontend_entrypoint_7(rdram, ctx);
        *ctx = saved;
    }

    std::string clock_text(std::chrono::steady_clock::duration d) {
        long s = (long)std::chrono::duration_cast<std::chrono::seconds>(d).count();
        char text[32];
        std::snprintf(text, sizeof(text), "%ld:%02ld", s / 60, s % 60);
        return text;
    }

    void finish(const std::string& message) {
        std::fprintf(stderr, "[boss-rush] %s\n", message.c_str());
        tooie::toast::show(message);
        stage = Stage::Idle;
        stop_after_fight = false;
        reset_option();
    }

    void start_fight(uint8_t* rdram, recomp_context* ctx, int index) {
        current = index;
        arrived = false;
        died = false;
        retrying = false;
        stage = Stage::Fight;
        stage_started = std::chrono::steady_clock::now();
        const Boss& boss = bosses[index];
        std::fprintf(stderr, "[boss-rush] boss %d of %d: %s (replay 0x%X, map 0x%X)\n",
            index + 1, boss_count, boss.name, boss.replay, boss.map);
        tooie::toast::show("Boss rush " + std::to_string(index + 1) + "/" + std::to_string(boss_count) + ": " + boss.name);
        start_replay(rdram, ctx, boss.replay);
    }

    void read_env() {
        env_start = std::chrono::steady_clock::now();
        if (const char* env = std::getenv("TOOIE_BOSS_RUSH")) {
            unsigned ms = 0, first = 0;
            int fields = std::sscanf(env, "%u:%u", &ms, &first);
            if (fields >= 1) {
                env_rush_ms = ms;
                env_rush_first = (fields >= 2 && first < (unsigned)boss_count) ? (int)first : 0;
            }
        }
        loss_is_win = std::getenv("TOOIE_BOSS_RUSH_LOSS_IS_WIN") != nullptr;
        if (const char* env = std::getenv("TOOIE_REPLAY")) {
            unsigned replay = 0, ms = 0;
            if (std::sscanf(env, "%x@%u", &replay, &ms) >= 1) {
                env_replay = (int)replay;
                env_replay_ms = ms;
            }
        }
        env_scan = std::getenv("TOOIE_REPLAY_SCAN") != nullptr;
    }

    // TOOIE_REPLAY: one replay number, or with TOOIE_REPLAY_SCAN each number from it up, one a frame, logging
    // the map each asks for and cancelling the change.
    void replay_probe(uint8_t* rdram, recomp_context* ctx) {
        static const bool game_clock = std::getenv("TOOIE_SCREENSHOT_GAME") != nullptr;   // QA: times in game time
        if (env_replay < 0 || changing(rdram) ||
            (game_clock ? tooie::game_frame_rate::game_ms() < env_replay_ms
                        : std::chrono::steady_clock::now() - env_start < std::chrono::milliseconds(env_replay_ms))) {
            return;
        }
        start_replay(rdram, ctx, env_replay);
        if (env_scan && env_replay < 0x100) {
            if (changing(rdram)) {
                std::fprintf(stderr, "[boss-rush] scan 0x%X -> map 0x%X exit %u\n", env_replay,
                    change_target(rdram), MEM_BU(0x13, game_state_addr));
                MEM_B(0x12, game_state_addr) = 0;
            }
            env_replay++;
        } else {
            std::fprintf(stderr, "[boss-rush] replay 0x%X -> map 0x%X\n", env_replay, change_target(rdram));
            env_replay = -1;
        }
    }

    // Saves the open file first, as the pause menu's Save and quit does (src/game/timer_save.cpp).
    // False while that can't be done yet (paused).
    bool save_open_file(uint8_t* rdram, recomp_context* ctx) {
        const int slot = MEM_B(0, save_slot_addr);
        const int level = MEM_BU(0, current_level_addr);
        const bool in_level = level >= 0x0F && level < 0x1C && level != 0x11;
        if (slot < 0 || !in_level || MEM_BU(0, game_mode_addr) != 0) {
            return true;
        }
        if (MEM_W(0, pause_menu_addr) != 0) {
            return false;
        }
        std::fprintf(stderr, "[boss-rush] saving slot %d before the rush\n", slot);
        recomp_context saved = *ctx;
        ctx->r4 = slot;
        _glsavegame_entrypoint_7(rdram, ctx);
        *ctx = saved;
        return true;
    }
}

void tooie::boss_rush::add_option(recomp::config::Config& general) {
    general.add_bool_option(option, "Boss rush",
        "Fight all 13 bosses one after another, from Klungo to Hag 1, with the moves each fight needs, whatever "
        "your save file has reached (the game's own Boss Replay, chained). Your file is saved first and the fights "
        "don't change it. If you lose, Yes tries that boss again and No ends the rush. Turns itself off when the "
        "rush ends; pressing the button again stops after the current fight.",
        false);
    // A button (L, 2026-10-23): the value is true while a rush runs, and the button's text follows it.
    general.set_option_button(option, "Start boss rush", "Stop boss rush");
    general.add_option_change_callback(option,
        // The callback gets (new value, previous value, context).
        [](recomp::config::ConfigValueVariant value, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
            if (resetting_option || context == recomp::config::OptionChangeContext::Load) {
                return;
            }
            const bool on = std::holds_alternative<bool>(value) && std::get<bool>(value);
            if (on) {
                start_requested = true;
            } else {
                stop_requested = true;
            }
        });
}

void tooie::boss_rush::tick(uint8_t* rdram, recomp_context* ctx) {
    std::call_once(env_flag, [] {
        read_env();
        // Left on by a run that closed mid-rush: the saved value says on, but no rush is running.
        try {
            if (std::get<bool>(recompui::config::get_general_config().get_option_value(tooie::boss_rush::option))) {
                start_requested = false;
                reset_option();
            }
        } catch (...) {
        }
    });
    replay_probe(rdram, ctx);
    if (const char* env = std::getenv("TOOIE_BOSS_RUSH_MENU")) {
        static bool done = false;
        if (!done && std::chrono::steady_clock::now() - env_start >= std::chrono::milliseconds(std::atoi(env))) {
            done = true;
            std::thread([] {
                recomp::config::Config& general = recompui::config::get_general_config();
                general.set_option_value(tooie::boss_rush::option, true);
                std::fprintf(stderr, "[boss-rush] menu switch set on\n");
            }).detach();
        }
    }
    if (env_rush_first >= 0 && stage == Stage::Idle &&
        std::chrono::steady_clock::now() - env_start >= std::chrono::milliseconds(env_rush_ms)) {
        start_requested = true;
    }

    const uint16_t map = tooie::debug::current_map(rdram);

    if (stop_requested.exchange(false)) {
        start_requested = false;
        if (stage == Stage::Fight) {
            stop_after_fight = true;
            tooie::toast::show("Boss rush stops after this fight");
        } else if (stage == Stage::Between) {
            stage = Stage::Idle;
            tooie::toast::show("Boss rush stopped");
        }
    }

    switch (stage) {
    case Stage::Idle:
        if (!start_requested.load()) {
            break;
        }
        if (bottles_on()) {
            start_requested = false;
            env_rush_first = -1;
            finish("Turn off Bottles' Revenge to start a boss rush");
            break;
        }
        // Wait for the game itself (not the launcher or the boot logos) and no map change under way.
        if (map == 0 || map == title_map || changing(rdram)) {
            break;
        }
        if (!save_open_file(rdram, ctx)) {
            break;
        }
        start_requested = false;
        stop_after_fight = false;
        rush_started = std::chrono::steady_clock::now();
        std::fprintf(stderr, "[boss-rush] started from map 0x%X\n", map);
        start_fight(rdram, ctx, env_rush_first >= 0 ? env_rush_first : 0);
        env_rush_first = -1;
        break;

    case Stage::Fight: {
        const Boss& boss = bosses[current];
        if (!arrived) {
            if (map == boss.map && !changing(rdram)) {
                arrived = true;
                std::fprintf(stderr, "[boss-rush] in %s's arena\n", boss.name);
            } else if (std::chrono::steady_clock::now() - stage_started > load_timeout) {
                finish(std::string("Boss rush stopped: ") + boss.name + "'s fight did not load");
            }
            break;
        }
        // "Yes, play again" reloads the arena: a new try once it has loaded.
        if (changing(rdram) && change_target(rdram) == boss.map) {
            retrying = true;
            break;
        }
        if (retrying) {
            retrying = false;
            died = false;
            std::fprintf(stderr, "[boss-rush] trying %s again\n", boss.name);
        }
        if (!changing(rdram) && player_state(rdram) == state_dead && !died) {
            died = true;
            std::fprintf(stderr, "[boss-rush] died in %s's fight\n", boss.name);
        }
        // The replay is over when it asks for the game select (gcfrontend_entrypoint_10).
        if (!changing(rdram)) {
            break;
        }
        if (change_target(rdram) != game_select_map) {
            break;
        }
        const bool paused = MEM_W(0, pause_menu_addr) != 0;
        const bool won = (!died && !paused) || loss_is_win;
        std::fprintf(stderr, "[boss-rush] %s's fight over: %s%s -> %s (%s in)\n", boss.name, died ? "died" : "alive",
            paused ? ", paused" : "", won ? "won" : "lost", clock_text(std::chrono::steady_clock::now() - rush_started).c_str());
        if (!won) {
            finish("Boss rush over: " + std::to_string(current) + " of " + std::to_string(boss_count) +
                " bosses beaten, stopped at " + boss.name);
        } else if (current + 1 >= boss_count) {
            finish("Boss rush complete! All " + std::to_string(boss_count) + " bosses in " +
                clock_text(std::chrono::steady_clock::now() - rush_started));
        } else if (stop_after_fight) {
            finish("Boss rush stopped after " + std::string(boss.name));
        } else {
            stage = Stage::Between;
            frames = 0;
            stage_started = std::chrono::steady_clock::now();
        }
        break;
    }

    case Stage::Between:
        // Back on the game select screen: start the next replay from there once it has settled.
        if (map != game_select_map || changing(rdram)) {
            frames = 0;
            if (std::chrono::steady_clock::now() - stage_started > load_timeout) {
                finish("Boss rush stopped: the game select screen did not load");
            }
            break;
        }
        if (++frames >= settle_frames) {
            start_fight(rdram, ctx, current + 1);
        }
        break;
    }
}

bool tooie::boss_rush::cancel() {
    if (stage == Stage::Idle) {
        return false;
    }
    start_requested = false;
    finish("Boss rush stopped");
    return true;
}
