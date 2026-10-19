// Cheats > Replays (L, 2026-10-17): the Race Warps (Replay Race), which used to be in the Warp tab, and the
// game's own Replay menu (boss fights, minigames and cutscenes), each as a drop-down that starts the pick
// at once from wherever Banjo is, whatever the save file has reached.
//
// Races are practice runs (src/gameplay/race_warp.cpp): nothing is won and the file's races stay where
// they were. Boss, minigame and cutscene replays are the game's Replay menu entries, started with
// gcfrontend_entrypoint_7(replay number, 1) as the game select does (src/gameplay/boss_rush.cpp has the
// details). The game sets up the moves and items each needs and, when it ends, goes back to the game
// select screen, dropping anything unsaved; so the open file is saved first, as Save and quit does.
//
// A boss, minigame or cutscene picked during another replay (L, 2026-10-19) does not call entrypoint 7 from
// inside the running replay: it ends that replay the game's own way (gcfrontend_entrypoint_10, what a boss
// calls when its fight is over, going to the game select screen) and starts the new one once the game
// select has loaded, the path boss rush chains its fights on and the game's own Replay menu uses. A running
// boss rush is stopped first. Picks are taken on the game select screen too, as its Replay menu is there.
// Still refused: replays during Bottles' Revenge (it holds the same mode byte at 1), and races during a
// replay (a race runs on the save file's flags, which a replay has swapped for its own set-up).
//
// Replay numbers (headless, TOOIE_REPLAY_SCAN, 2026-10-17): bosses 0x20-0x2C, minigames 0x60-0x76,
// cutscenes 0x80-0x85 (in the order of their unlock flags GFLAG_BC8.., GFLAG_BE3.., GFLAG_BFA..);
// 0x40-0x4D are the multiplayer games.
//
// Headless: TOOIE_REPLAY_PICK=<hex replay number>@<ms> asks for that replay as the drop-down does.

#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <variant>
#include <vector>

#include "recomp.h"
#include "funcs.h"
#include "recompui/config.h"
#include "tooie_boss_rush.h"
#include "tooie_debug.h"
#include "tooie_race_warp.h"
#include "tooie_replays.h"
#include "tooie_toast.h"

namespace {
    struct Entry {
        const char* name;
        int replay;
    };

    const Entry bosses[] = {
        { "Klungo", 0x20 },
        { "Klungo (second fight)", 0x21 },
        { "Klungo (third fight)", 0x22 },
        { "Targitzan", 0x23 },
        { "Old King Coal", 0x24 },
        { "Mr. Patch", 0x25 },
        { "Lord Woo Fak Fak", 0x26 },
        { "Terry", 0x27 },
        { "Weldar", 0x28 },
        { "Chilly Willy", 0x29 },
        { "Chilli Billi", 0x2A },
        { "Mingy Jongo", 0x2B },
        { "Hag 1", 0x2C },
    };

    const Entry minigames[] = {
        { "Mayan Kickball (quarterfinal)", 0x60 },
        { "Mayan Kickball (semifinal)", 0x61 },
        { "Mayan Kickball (final)", 0x62 },
        { "Ordnance Storage", 0x63 },
        { "Dodgems (1 vs 1)", 0x64 },
        { "Dodgems (2 vs 1)", 0x65 },
        { "Dodgems (3 vs 1)", 0x66 },
        { "Hoop Hurry", 0x67 },
        { "Balloon Burst", 0x68 },
        { "Saucer of Peril", 0x69 },
        { "Mini-Sub Challenge", 0x6A },
        { "Chompa's Belly", 0x6B },
        { "Clinker's Cavern", 0x6C },
        { "Twinklies Packing", 0x6D },
        { "Colosseum Kickball (quarterfinal)", 0x6E },
        { "Colosseum Kickball (semifinal)", 0x6F },
        { "Colosseum Kickball (final)", 0x70 },
        { "Pot o' Gold", 0x71 },
        { "Trash Can Germs", 0x72 },
        { "Zubbas' Hive", 0x73 },
        { "Tower of Tragedy Quiz (round 1)", 0x74 },
        { "Tower of Tragedy Quiz (round 2)", 0x75 },
        { "Tower of Tragedy Quiz (round 3)", 0x76 },
    };

    const Entry cutscenes[] = {
        { "Opening story", 0x80 },
        { "King Jingaling gets zapped", 0x81 },
        { "Bottles and Jingaling restored", 0x82 },
        { "Grunty defeated", 0x83 },
        { "Credits", 0x84 },
        { "Character parade", 0x85 },
    };

    struct List {
        const char* option;
        const char* name;
        const char* description;
        const Entry* entries;
        size_t count;
    };

    // Race names come from race_warp.cpp; replay -1 - i means race i.
    std::vector<Entry> race_entries() {
        std::vector<Entry> out;
        for (int i = 0; i < tooie::race_warp::count; i++) {
            out.push_back({ tooie::race_warp::name(i), -1 - i });
        }
        return out;
    }
    const std::vector<Entry> races = race_entries();

    const List lists[] = {
        { "replay_race", "Race (Replay Race)",
          "Race Canary Mary now, in Glitter Gulch Mine or Cloud Cuckooland. A practice run: nothing is won or lost.",
          races.data(), races.size() },
        { "replay_boss", "Boss",
          "Fight a boss again now, with the moves the fight needs. Your file is saved first; when the fight ends the "
          "game goes back to the game select screen, as the game's own Replay menu does.",
          bosses, sizeof(bosses) / sizeof(bosses[0]) },
        { "replay_minigame", "Minigame",
          "Play a minigame again now. Your file is saved first; when it ends the game goes back to the game select "
          "screen, as the game's own Replay menu does.",
          minigames, sizeof(minigames) / sizeof(minigames[0]) },
        { "replay_cutscene", "Cutscene",
          "Watch a story cutscene now, the ending ones too. Your file is saved first; when it ends the game goes back "
          "to the game select screen, as the game's own Replay menu does.",
          cutscenes, sizeof(cutscenes) / sizeof(cutscenes[0]) },
    };

    constexpr gpr game_state_addr = (int32_t)0x80127630;   // +0x12: a map change is under way
    constexpr gpr save_slot_addr = (int32_t)0x8012B3F1;    // -1: no file open
    constexpr gpr current_level_addr = (int32_t)0x8012762C;
    constexpr gpr game_mode_addr = (int32_t)0x8012B3F2;    // 0 normal, 1 Bottles' Revenge, 2 replay
    constexpr gpr pause_menu_addr = (int32_t)0x80128AF0;   // pause menu object while paused

    constexpr uint16_t game_select_map = 0x158;
    // Game select frames to wait before a replay is started there, so the screen has finished loading.
    constexpr int settle_frames = 20;
    constexpr auto load_timeout = std::chrono::seconds(60);

    // The replay number waiting to be started (0 = none).
    std::atomic<int> pending{0};
    // Game thread only: the replay to start once the one being ended has reached the game select (0 = none).
    int after_select = 0;
    int select_frames = 0;
    std::chrono::steady_clock::time_point ending_started;
    // Set while a drop-down is put back to "Pick one", so that change is not taken as a pick.
    std::atomic<bool> resetting{false};

    bool in_level(uint8_t* rdram) {
        const int level = MEM_BU(0, current_level_addr);
        return level >= 0x0F && level < 0x1C && level != 0x11;
    }

    void start_replay(uint8_t* rdram, recomp_context* ctx, int replay) {
        recomp_context saved = *ctx;
        ctx->r29 = (int32_t)((((uint32_t)ctx->r29 - 0x100) & ~0xFu));
        ctx->r4 = (uint64_t)(int64_t)replay;
        ctx->r5 = 1;
        _gcfrontend_entrypoint_7(rdram, ctx);
        *ctx = saved;
    }

    // gcfrontend_entrypoint_10, what a boss calls when its replayed fight is over: back to the game select.
    void end_replay(uint8_t* rdram, recomp_context* ctx) {
        recomp_context saved = *ctx;
        ctx->r29 = (int32_t)((((uint32_t)ctx->r29 - 0x100) & ~0xFu));
        _gcfrontend_entrypoint_10(rdram, ctx);
        *ctx = saved;
    }

    void save_open_file(uint8_t* rdram, recomp_context* ctx) {
        const int slot = MEM_B(0, save_slot_addr);
        if (slot < 0 || !in_level(rdram) || MEM_BU(0, game_mode_addr) != 0) {
            return;
        }
        std::fprintf(stderr, "[replays] saving slot %d first\n", slot);
        recomp_context saved = *ctx;
        ctx->r4 = slot;
        _glsavegame_entrypoint_7(rdram, ctx);
        *ctx = saved;
    }

    const char* name_of(int replay) {
        for (const List& list : lists) {
            for (size_t i = 0; i < list.count; i++) {
                if (list.entries[i].replay == replay) {
                    return list.entries[i].name;
                }
            }
        }
        return "";
    }
}

void tooie::replays::add_options(recomp::config::Config& cheats, const std::string& master_option) {
    for (const List& list : lists) {
        std::vector<recomp::config::ConfigOptionEnumOption> entries;
        entries.push_back(recomp::config::ConfigOptionEnumOption(0, "pick", "Pick one"));
        for (size_t i = 0; i < list.count; i++) {
            entries.push_back(recomp::config::ConfigOptionEnumOption((uint32_t)(i + 1), "entry_" + std::to_string(i), list.entries[i].name));
        }
        cheats.add_enum_option(list.option, list.name, list.description, entries, 0u);
        cheats.add_option_hidden_dependency(list.option, master_option, false);
        const List* l = &list;
        cheats.add_option_change_callback(list.option,
            [l](recomp::config::ConfigValueVariant cur, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
                const uint32_t* idx = std::get_if<uint32_t>(&cur);
                if (resetting || idx == nullptr || *idx == 0 || *idx > l->count ||
                    context == recomp::config::OptionChangeContext::Load) {
                    return;
                }
                pending = l->entries[*idx - 1].replay;
                // Back to "Pick one", so the same entry can be picked again.
                resetting = true;
                recompui::config::get_config(tooie::replays::tab_id).update_option_value(l->option, 0u);
                resetting = false;
            });
    }
    recompui::config::set_option_group(lists[0].option, "Replays");
}

void tooie::replays::reset(recomp::config::Config& cheats) {
    pending = 0;
    resetting = true;
    for (const List& list : lists) {
        cheats.update_option_value(list.option, 0u);
    }
    resetting = false;
}

void tooie::replays::tick(uint8_t* rdram, recomp_context* ctx) {
    static bool env_read = false;
    static int env_replay = 0;
    static std::chrono::steady_clock::time_point env_at;
    if (!env_read) {
        env_read = true;
        if (const char* v = std::getenv("TOOIE_REPLAY_PICK")) {
            unsigned replay = 0, ms = 0;
            if (std::sscanf(v, "%x@%u", &replay, &ms) >= 1) {
                env_replay = (int)replay;
                env_at = std::chrono::steady_clock::now() + std::chrono::milliseconds(ms);
            }
        }
    }
    if (env_replay != 0 && std::chrono::steady_clock::now() >= env_at) {
        pending = env_replay;
        env_replay = 0;
    }

    // Ending a replay to start another: wait for the game select, then start it as its Replay menu does.
    if (after_select != 0) {
        const uint16_t map = tooie::debug::current_map(rdram);
        if (map != game_select_map || MEM_BU(0x12, game_state_addr) != 0) {
            select_frames = 0;
            if (std::chrono::steady_clock::now() - ending_started > load_timeout) {
                std::fprintf(stderr, "[replays] the game select never loaded; 0x%X dropped\n", after_select);
                tooie::toast::show("Replay not started: the game select screen did not load");
                after_select = 0;
            }
        } else if (++select_frames >= settle_frames) {
            const int next = after_select;
            after_select = 0;
            std::fprintf(stderr, "[replays] starting replay 0x%X (%s) from the game select\n", next, name_of(next));
            start_replay(rdram, ctx, next);
        }
    }

    const int replay = pending.load();
    if (replay == 0) {
        return;
    }
    // Wait for a frame where Banjo is playing: not paused, no map change under way.
    if (MEM_W(0, pause_menu_addr) != 0 || MEM_BU(0x12, game_state_addr) != 0) {
        return;
    }
    pending = 0;
    const uint8_t mode = MEM_BU(0, game_mode_addr);
    const bool at_select = tooie::debug::current_map(rdram) == game_select_map;
    if (replay < 0) {
        if (!tooie::debug::can_warp()) {
            tooie::toast::show("Start the game and load a file first");
        } else if (mode != 0) {
            tooie::toast::show("Races use your save file: quit the replay or mode first");
        } else {
            tooie::race_warp::request(-1 - replay);
            tooie::toast::show(std::string("Racing Canary Mary: ") + tooie::race_warp::name(-1 - replay));
        }
        return;
    }
    if (!tooie::debug::can_warp() && !at_select) {
        tooie::toast::show("Start the game and load a file first");
        return;
    }
    if (mode == 1) {
        tooie::toast::show("Turn off Bottles' Revenge first");
        return;
    }
    tooie::boss_rush::cancel();
    tooie::toast::show(std::string("Replay: ") + name_of(replay));
    if (mode == 2 && !at_select) {
        // In a replay: end it as the game does and start this one from the game select.
        std::fprintf(stderr, "[replays] ending the current replay for 0x%X (%s)\n", replay, name_of(replay));
        after_select = replay;
        select_frames = 0;
        ending_started = std::chrono::steady_clock::now();
        end_replay(rdram, ctx);
        return;
    }
    after_select = 0;
    save_open_file(rdram, ctx);
    std::fprintf(stderr, "[replays] starting replay 0x%X (%s)\n", replay, name_of(replay));
    start_replay(rdram, ctx, replay);
}
