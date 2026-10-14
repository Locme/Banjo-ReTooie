// Music player (handoff 4.61).
//
// The game keeps six music slots of 0x50 bytes at 0x801357D0; the s16 at +0x28 is the slot's track
// (negative when the slot is free). func_800FC660(track) starts a track in a slot, func_800FCAE0
// (track, volume, time) fades it and func_800FCA90(track) stops it (the pause menu's game over fades
// with (track, 0, 200) and then stops). Jolly's jukebox (chmusicmenu) plays its songs the same way;
// its track list is the 48 halfwords at 0x80123DE0, and song i is unlocked by flag 0x53E + i
// (func_800FCF50). The list is read from memory when a song is picked, so no game data is kept here.
//
// Picking a track notes the tracks the level is playing, stops them and starts the track. "Level
// music" stops it and starts the noted tracks again (the game does not reliably restart its music
// after silence). Doors and cutscenes change the music as usual, and a map change ends the chosen
// track and puts the row back to "Level music".

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
#include "tooie_debug.h"
#include "tooie_music_player.h"

namespace {
    constexpr gpr slots_addr = (int32_t)0x801357D0;
    constexpr uint32_t slot_size = 0x50;
    constexpr uint32_t slot_count = 6;
    constexpr gpr jukebox_addr = (int32_t)0x80123DE0;
    constexpr uint32_t track_count = 160;
    constexpr uint32_t fade_time = 200;

    // Jolly's jukebox songs in the jukebox's order, named after the decomp's unlock flags
    // (FLAG_53E_JUKEBOX_SONG_UNLOCKED_SM_MAIN ...). The jukebox has 48 entries; the last has no flag name.
    constexpr const char* jukebox_names[] = {
        "Spiral Mountain",
        "Banjo's House",
        "Klungo",
        "Mayahem Temple",
        "Targitzan",
        "Glitter Gulch Mine",
        "Glitter Gulch Mine: Minigame",
        "Old King Coal",
        "Witchyworld",
        "Witchyworld: Minigame",
        "Witchyworld 3",
        "Mr. Patch",
        "Jolly Roger's Lagoon",
        "Atlantis",
        "Aliens",
        "Aliens (Fixed)",
        "Chris P. Bacon",
        "Targitzan 2",
        "Terrydactyland",
        "Terry",
        "Grunty Industries",
        "Weldar",
        "Hailfire Peaks",
        "Chilly Willy and Chilli Billi",
        "Cloud Cuckooland",
        "Lord Woo Fak Fak",
        "Canary Mary",
        "Cauldron Keep",
        "Tower of Tragedy",
        "Credits",
        "Isle o' Hags",
        "Jinjo Village",
        "Sad Jinjo House",
        "Happy Jinjo House",
        "King Jingaling",
        "Zombie Jingaling",
        "Bottles' House",
        "Heggy's Egg Shed",
        "Jiggywiggy's Temple",
        "Honey B's Hive",
        "Turbo Talon Trainers",
        "Wading Boots",
        "Springy Step Shoes",
        "Claw Clamber Boots",
        "Clockwork Kazooie",
        "Chompasaurus",
        "Bottles' Party",
        "Jukebox 48",
    };
    constexpr uint32_t jukebox_count = sizeof(jukebox_names) / sizeof(jukebox_names[0]);
    // Row entries: 0 Level music, then the jukebox songs, then Track 0 to 159.
    constexpr uint32_t first_number_entry = 1 + jukebox_count;
    constexpr uint32_t entry_count = first_number_entry + track_count;

    constexpr uint32_t no_request = 0xFFFFFFFF;
    std::atomic<uint32_t> pending{no_request};

    bool playing = false;
    int16_t chosen_track = -1;
    uint16_t chosen_map = 0;
    std::vector<int16_t> level_tracks;
    bool reset_row = false;

    // Headless test hook: TOOIE_MUSIC=<entry>@ms[,<entry>@ms...] picks each row entry once, ms after
    // the game loop first runs (0 is Level music).
    struct EnvRequest {
        uint32_t entry;
        uint32_t delay_ms;
    };
    std::vector<EnvRequest> env_requests;
    size_t env_next = 0;
    bool env_read = false;
    std::chrono::steady_clock::time_point started;

    int16_t slot_track(uint8_t* rdram, uint32_t i) {
        return (int16_t)MEM_H(0x28, slots_addr + (int32_t)(i * slot_size));
    }

    void call_game(uint8_t* rdram, recomp_context* ctx, void (*fn)(uint8_t*, recomp_context*), uint32_t a0, uint32_t a1 = 0, uint32_t a2 = 0) {
        recomp_context saved = *ctx;
        ctx->r29 = (int32_t)((((uint32_t)ctx->r29 - 0x100) & ~0xFu));
        ctx->r4 = (int32_t)a0;
        ctx->r5 = (int32_t)a1;
        ctx->r6 = (int32_t)a2;
        fn(rdram, ctx);
        *ctx = saved;
    }

    void stop_track(uint8_t* rdram, recomp_context* ctx, int16_t track) {
        call_game(rdram, ctx, func_800FCAE0, (uint32_t)(int32_t)track, 0, fade_time);
        call_game(rdram, ctx, func_800FCA90, (uint32_t)(int32_t)track);
    }

    int16_t entry_track(uint8_t* rdram, uint32_t entry) {
        if (entry >= first_number_entry) {
            return (int16_t)(entry - first_number_entry);
        }
        return (int16_t)MEM_H(0, jukebox_addr + (int32_t)((entry - 1) * 2));
    }

    void log_slots(uint8_t* rdram, const char* why) {
        fprintf(stderr, "[music] %s: slots", why);
        for (uint32_t i = 0; i < slot_count; i++) {
            const gpr slot = slots_addr + (int32_t)(i * slot_size);
            fprintf(stderr, " %d", slot_track(rdram, i));
            if (slot_track(rdram, i) >= 0) {
                fprintf(stderr, "(%X/%X/%X)", MEM_W(0x20, slot), MEM_BU(0x31, slot), MEM_BU(0x34, slot));
            }
        }
        fprintf(stderr, "\n");
    }
}

void tooie::music_player::add_options(recomp::config::Config& sound) {
    std::vector<recomp::config::ConfigOptionEnumOption> entries;
    entries.push_back(recomp::config::ConfigOptionEnumOption(0, "level", "Level music"));
    for (uint32_t i = 0; i < jukebox_count; i++) {
        entries.push_back(recomp::config::ConfigOptionEnumOption(1 + i, "jukebox_" + std::to_string(i), jukebox_names[i]));
    }
    for (uint32_t t = 0; t < track_count; t++) {
        entries.push_back(recomp::config::ConfigOptionEnumOption(first_number_entry + t, "track_" + std::to_string(t), "Track " + std::to_string(t)));
    }
    sound.add_enum_option(option, "Music player",
        "Plays any of the game's tracks: Jolly's jukebox songs by name, then every track by number. "
        "Level music goes back to the area's own music. Doors and cutscenes change the music as usual, "
        "and going to another area ends the chosen track.",
        entries, 0u);
    sound.add_option_change_callback(option,
        [](recomp::config::ConfigValueVariant cur, recomp::config::ConfigValueVariant prev, recomp::config::OptionChangeContext) {
            const uint32_t* idx = std::get_if<uint32_t>(&cur);
            const uint32_t* was = std::get_if<uint32_t>(&prev);
            if (idx == nullptr || *idx >= entry_count || (was != nullptr && *was == *idx)) {
                return;
            }
            pending = *idx;
        });
}

void tooie::music_player::tick(uint8_t* rdram, recomp_context* ctx) {
    if (!env_read) {
        env_read = true;
        started = std::chrono::steady_clock::now();
        // The choice is not kept between runs: the row starts on Level music.
        reset_row = true;
        pending = no_request;
        if (const char* v = std::getenv("TOOIE_MUSIC")) {
            std::string list{v};
            size_t pos = 0;
            while (pos < list.size()) {
                size_t comma = list.find(',', pos);
                unsigned entry = 0, delay = 0;
                if (std::sscanf(list.substr(pos, comma - pos).c_str(), "%u@%u", &entry, &delay) >= 1 && entry < entry_count) {
                    env_requests.push_back({ entry, delay });
                }
                pos = comma == std::string::npos ? list.size() : comma + 1;
            }
        }
    }
    static const bool dbg = std::getenv("TOOIE_MUSIC_LOG") != nullptr;
    if (dbg) {
        static auto last = std::chrono::steady_clock::now();
        auto now = std::chrono::steady_clock::now();
        if (now - last >= std::chrono::seconds(1)) {
            last = now;
            log_slots(rdram, "tick");
        }
    }
    if (env_next < env_requests.size() && tooie::debug::can_warp() && pending.load() == no_request) {
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - started).count();
        if (elapsed >= env_requests[env_next].delay_ms) {
            pending = env_requests[env_next++].entry;
        }
    }

    const uint16_t map = tooie::debug::current_map(rdram);
    if (playing && map != chosen_map) {
        // The new area started its own music.
        fprintf(stderr, "[music] map changed, track %d ended\n", chosen_track);
        playing = false;
        level_tracks.clear();
        reset_row = true;
    }
    if (reset_row) {
        reset_row = false;
        try {
            recomp::config::Config& sound = recompui::config::get_sound_config();
            if (std::get<uint32_t>(sound.get_option_value(option)) != 0) {
                sound.update_option_value(option, 0u);
            }
        } catch (...) {
        }
        pending = no_request;
    }

    uint32_t entry = pending.load();
    if (entry == no_request || !tooie::debug::can_warp()) {
        return;
    }
    pending = no_request;

    if (entry == 0) {
        if (!playing) {
            return;
        }
        stop_track(rdram, ctx, chosen_track);
        for (int16_t t : level_tracks) {
            call_game(rdram, ctx, func_800FC660, (uint32_t)(int32_t)t);
        }
        fprintf(stderr, "[music] back to the level's music (%zu tracks)\n", level_tracks.size());
        playing = false;
        level_tracks.clear();
        if (dbg) {
            log_slots(rdram, "restored");
        }
        return;
    }

    const int16_t track = entry_track(rdram, entry);
    if (track < 0 || track >= (int16_t)track_count) {
        fprintf(stderr, "[music] entry %u has no track (%d)\n", entry, track);
        return;
    }
    // Note what the level plays the first time, then stop everything that is playing.
    std::vector<int16_t> now_playing;
    for (uint32_t i = 0; i < slot_count; i++) {
        int16_t t = slot_track(rdram, i);
        if (t >= 0) {
            now_playing.push_back(t);
        }
    }
    if (!playing) {
        level_tracks = now_playing;
    }
    for (int16_t t : now_playing) {
        stop_track(rdram, ctx, t);
    }
    call_game(rdram, ctx, func_800FC660, (uint32_t)(int32_t)track);
    playing = true;
    chosen_track = track;
    chosen_map = map;
    fprintf(stderr, "[music] playing entry %u, track %d\n", entry, track);
    if (dbg) {
        log_slots(rdram, "playing");
    }
}
