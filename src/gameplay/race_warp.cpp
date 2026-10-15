// Race warps (roadmap 4.81).
//
// Warp > Race Warps starts one of Canary Mary's races. Her races are run by her
// hand cart (chhandcart, Glitter Gulch Mine) and her cloud cart (the overlay the
// decomp calls chclockworkmouse, Cloud Cuckooland). In the game, talking to her
// sets the 3-bit race state (flag 0xA4C in GGM, 0xA37 in CCL) to 1, "racing",
// and calls _gcgoto_entrypoint_1(race map, exit 1). In the race map the cart's
// init reads that state; with 1 it puts itself on the race spline. Any other
// state takes the path for her home map, which looks for her parking spot
// (cube-search props 0x313/0x314, only in GGM itself). That crashed the
// 2026-10-14 try: it set the state from another level, and entering GGM
// cleared it (see below).
//
// Which of the two races a level runs is "has this file got the first race's
// Jiggy" (GGM Jiggy 0xC, CCL Jiggy 0x4A): without it the first race (GGM map
// 0x16F, CCL's first spline), with it the second (GGM map 0x170, CCL's second
// spline). The cart also hides itself unless Mary is freed and still racing in
// that level: GGM needs flags 0x066 and 0x507 and not Cheato page 4 (her GGM
// prize); CCL needs that page, flag 0x504, and not Cheato page 0x16. The game
// keeps those collectibles in flags 0x2AE, 0x2D8, 0x2F7 and 0x2FB (read back
// from func_800D0908 headless, not the decomp's names for those numbers).
//
// The race state is in the level's own flag bank (D_8012C770[2]), which
// gclevel_entrypoint_0 clears whenever another level is entered, so a race
// warp first warps to Mary's map in that level (GGM 0xC7, CCL 0x136) unless
// Banjo is already there. A few frames after arriving it sets the race state
// with the game's own setter, makes the flag getter (hooked in
// banjotooie.us.toml, src/gameplay/progress_cheats.cpp) report those progress
// flags as the race needs them (the collectibles' flag numbers come from the
// game's own func_800D0908), and warps to the race map at exit 1. Nothing else
// in the file is written. When the race map is left
// (won, lost, or quit: the first frame a map change away from it is under way,
// before the next map loads) the race state and result flags are put back and
// the getter reports the file again, so the run is practice: no Jiggy or Cheato
// page is given and the file's own races are where they were.
//
// Headless test aids:
//   TOOIE_RACE_WARP=<race 0-3>@<ms>   asks for the race warp that long after the game loop first runs
//   TOOIE_RACE_LOG=1                  logs [race-warp] lines: each overridden flag read once, the race
//                                     state every 2 s in the race, and the restore; =2 also logs every
//                                     other flag read once during the race

#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <mutex>
#include <set>
#include <vector>

#include "recomp.h"
#include "funcs.h"
#include "tooie_debug.h"
#include "tooie_race_warp.h"

namespace {
    struct FlagValue {
        int32_t flag;
        bool value;
    };

    // A collectible as func_800D0A9C takes it: id and type (1 Jiggy, 4 Cheato page).
    struct Item {
        int32_t id;
        int32_t type;
        bool collected;
    };

    struct Race {
        const char* name;
        uint16_t home_map;   // Mary's map in the level; entering it starts the level's flags afresh
        uint16_t race_map;
        int32_t state_flag;  // 3 bits: 0 waiting, 1 racing, 2 won
        int32_t result_flag; // 2 bits: 1 lost, 2 won
        FlagValue progress[2];
        Item items[3];
    };

    constexpr uint8_t race_exit = 1;
    constexpr int32_t racing = 1;
    constexpr int32_t jiggy = 1;
    constexpr int32_t cheato_page = 4;

    // GGM: Mary freed (0x066) and ready to race (0x507), her Cheato page (4) not got yet, and her Jiggy
    // (0xC) picks the race. CCL: she is there once GGM's page is got, 0x504, CCL's page (0x16) not got
    // yet, and her Jiggy (0x4A) picks the race. { 0, false } pads the shorter lists.
    constexpr Race races[tooie::race_warp::count] = {
        { "Glitter Gulch Mine: first race", 0xC7, 0x16F, 0xA4C, 0x9DC,
            { { 0x066, true }, { 0x507, true } },
            { { 0xC, jiggy, false }, { 4, cheato_page, false }, { 0, 0, false } } },
        { "Glitter Gulch Mine: second race", 0xC7, 0x170, 0xA4C, 0x9DC,
            { { 0x066, true }, { 0x507, true } },
            { { 0xC, jiggy, true }, { 4, cheato_page, false }, { 0, 0, false } } },
        { "Cloud Cuckooland: first race", 0x136, 0x161, 0xA37, 0x9DA,
            { { 0x504, true }, { 0, false } },
            { { 0x4A, jiggy, false }, { 4, cheato_page, true }, { 0x16, cheato_page, false } } },
        { "Cloud Cuckooland: second race", 0x136, 0x161, 0xA37, 0x9DA,
            { { 0x504, true }, { 0, false } },
            { { 0x4A, jiggy, true }, { 4, cheato_page, true }, { 0x16, cheato_page, false } } },
    };

    constexpr uint32_t game_state_addr = 0x80127630;
    constexpr auto stage_timeout = std::chrono::seconds(30);
    // Frames to wait in Mary's map after arriving, before the race map is asked for.
    constexpr int settle_frames = 10;

    std::atomic<int> requested{-1};

    // Game thread only from here on.
    enum class Stage { Idle, Hop, Settle, Race };
    Stage stage = Stage::Idle;
    int active = -1;
    bool arrived = false;
    int frames = 0;
    std::chrono::steady_clock::time_point started;
    int32_t saved_state = 0;
    int32_t saved_result = 0;
    std::vector<FlagValue> overrides;
    int log_level = 0;
    std::set<int32_t> logged_flags;
    int log_frames = 0;

    // Env test request.
    int env_race = -1;
    uint32_t env_delay_ms = 0;
    std::once_flag env_flag;
    std::chrono::steady_clock::time_point env_start;

    int32_t read_bits(uint8_t* rdram, recomp_context* ctx, int32_t flag, int32_t bits) {
        recomp_context saved = *ctx;
        ctx->r4 = (uint64_t)(int64_t)flag;
        ctx->r5 = (uint64_t)(int64_t)bits;
        func_800DA564(rdram, ctx);
        int32_t value = (int32_t)ctx->r2;
        *ctx = saved;
        return value;
    }

    void write_bits(uint8_t* rdram, recomp_context* ctx, int32_t flag, int32_t value, int32_t bits) {
        recomp_context saved = *ctx;
        ctx->r4 = (uint64_t)(int64_t)flag;
        ctx->r5 = (uint64_t)(int64_t)value;
        ctx->r6 = (uint64_t)(int64_t)bits;
        func_800DA7A8(rdram, ctx);
        *ctx = saved;
    }

    // The game flag that holds whether a collectible is got (func_800D0908, 0 if it has none).
    int32_t item_flag(uint8_t* rdram, recomp_context* ctx, const Item& item) {
        recomp_context saved = *ctx;
        ctx->r4 = (uint64_t)(int64_t)item.id;
        ctx->r5 = (uint64_t)(int64_t)item.type;
        func_800D0908(rdram, ctx);
        int32_t flag = (int32_t)ctx->r2;
        *ctx = saved;
        return flag;
    }

    bool changing(uint8_t* rdram) {
        return MEM_B(0x12, (int32_t)game_state_addr) != 0;
    }

    void stop(uint8_t* rdram, recomp_context* ctx, const char* why) {
        if (stage == Stage::Race) {
            const Race& race = races[active];
            int32_t state = read_bits(rdram, ctx, race.state_flag, 3);
            int32_t result = read_bits(rdram, ctx, race.result_flag, 2);
            write_bits(rdram, ctx, race.state_flag, saved_state, 3);
            write_bits(rdram, ctx, race.result_flag, saved_result, 2);
            std::fprintf(stderr, "[race-warp] %s: race state %d result %d put back to %d %d\n",
                why, state, result, saved_state, saved_result);
        } else {
            std::fprintf(stderr, "[race-warp] %s: stopped before the race\n", why);
        }
        overrides.clear();
        stage = Stage::Idle;
        active = -1;
    }

    // In Mary's map (so the level's flags are set up): stand in for the progress, set "racing" and go.
    void start_race(uint8_t* rdram, recomp_context* ctx) {
        const Race& race = races[active];
        overrides.clear();
        for (const FlagValue& f : race.progress) {
            if (f.flag != 0) {
                overrides.push_back(f);
            }
        }
        for (const Item& item : race.items) {
            if (item.id == 0) {
                continue;
            }
            int32_t flag = item_flag(rdram, ctx, item);
            if (flag != 0) {
                overrides.push_back({ flag, item.collected });
            }
            std::fprintf(stderr, "[race-warp] item %X type %d is flag 0x%X, reported as %s\n",
                item.id, item.type, flag, item.collected ? "got" : "not got");
        }
        saved_state = read_bits(rdram, ctx, race.state_flag, 3);
        saved_result = read_bits(rdram, ctx, race.result_flag, 2);
        write_bits(rdram, ctx, race.state_flag, racing, 3);
        std::fprintf(stderr, "[race-warp] %s: race state %d -> %d (result %d), map 0x%X exit %u\n",
            race.name, saved_state, read_bits(rdram, ctx, race.state_flag, 3), saved_result, race.race_map, race_exit);
        stage = Stage::Race;
        arrived = false;
        started = std::chrono::steady_clock::now();
        logged_flags.clear();
        tooie::debug::request_warp(race.race_map, race_exit);
    }
}

const char* tooie::race_warp::name(int race) {
    return (race >= 0 && race < count) ? races[race].name : "";
}

void tooie::race_warp::request(int race) {
    if (race >= 0 && race < count) {
        requested = race;
    }
}

void tooie::race_warp::tick(uint8_t* rdram, recomp_context* ctx) {
    std::call_once(env_flag, [] {
        env_start = std::chrono::steady_clock::now();
        if (const char* log = std::getenv("TOOIE_RACE_LOG")) {
            log_level = std::atoi(log);
        }
        if (const char* env = std::getenv("TOOIE_RACE_WARP")) {
            unsigned race = 0, delay = 0;
            if (std::sscanf(env, "%u@%u", &race, &delay) >= 1 && race < (unsigned)count) {
                env_race = (int)race;
                env_delay_ms = delay;
            }
        }
    });
    if (env_race >= 0 && std::chrono::steady_clock::now() - env_start >= std::chrono::milliseconds(env_delay_ms)) {
        requested = env_race;
        env_race = -1;
    }

    const uint16_t map = tooie::debug::current_map(rdram);

    if (stage != Stage::Idle) {
        const Race& race = races[active];
        const bool timed_out = std::chrono::steady_clock::now() - started > stage_timeout;
        switch (stage) {
        case Stage::Hop:
            if (map == race.home_map && !changing(rdram)) {
                stage = Stage::Settle;
                frames = 0;
            } else if (timed_out) {
                stop(rdram, ctx, "Mary's map never loaded");
            }
            break;
        case Stage::Settle:
            if (map != race.home_map || changing(rdram)) {
                stop(rdram, ctx, "left Mary's map");
            } else if (++frames >= settle_frames) {
                start_race(rdram, ctx);
            }
            break;
        case Stage::Race: {
            const uint16_t target = (uint16_t)MEM_H(0x10, (int32_t)game_state_addr);
            if (!arrived && map == race.race_map && !changing(rdram)) {
                arrived = true;
                std::fprintf(stderr, "[race-warp] in the race map 0x%X, race state %d\n",
                    map, read_bits(rdram, ctx, race.state_flag, 3));
            }
            if (arrived && (map != race.race_map || (changing(rdram) && target != race.race_map))) {
                stop(rdram, ctx, "left the race");
            } else if (!arrived && timed_out) {
                stop(rdram, ctx, "the race map never loaded");
            } else if (log_level > 0 && ++log_frames >= 60) {
                log_frames = 0;
                std::fprintf(stderr, "[race-warp] map 0x%X race state %d result %d\n", map,
                    read_bits(rdram, ctx, race.state_flag, 3), read_bits(rdram, ctx, race.result_flag, 2));
            }
            break;
        }
        case Stage::Idle:
            break;
        }
    }

    const int want = requested.exchange(-1);
    if (want < 0 || !tooie::debug::can_warp()) {
        return;
    }
    if (stage != Stage::Idle) {
        stop(rdram, ctx, "another race picked");
    }
    active = want;
    started = std::chrono::steady_clock::now();
    const Race& race = races[want];
    std::fprintf(stderr, "[race-warp] %s picked in map 0x%X\n", race.name, map);
    if (map == race.home_map && !changing(rdram)) {
        start_race(rdram, ctx);
    } else {
        // The race state is one of the level's own flags, which start afresh when the level is entered,
        // so go to Mary's map first as the game does (also from the race map, to load it again).
        stage = Stage::Hop;
        tooie::debug::request_warp(race.home_map, 0);
    }
}

bool tooie::race_warp::override_flag(int32_t flag, bool& value) {
    if (stage != Stage::Race) {
        return false;
    }
    for (const FlagValue& f : overrides) {
        if (f.flag == flag) {
            value = f.value;
            if (log_level > 0 && logged_flags.insert(flag).second) {
                std::fprintf(stderr, "[race-warp] flag 0x%X read as %d\n", flag, value ? 1 : 0);
            }
            return true;
        }
    }
    if (log_level > 1 && logged_flags.insert(flag).second) {
        std::fprintf(stderr, "[race-warp] flag 0x%X read (file's own)\n", flag);
    }
    return false;
}
