// Achievements (handoff 4.85; L, 2026-10-14: "backport achievements from XBLA version").
//
// The N64 game has none, so the Xbox Live Arcade version's twelve are rebuilt here. The XBLA port
// awarded them inside 4J's code, which the N64 doesn't have, so each one is unlocked from the game's
// own progress flags (lib/bt-decomp/include/gameflags.h), checked a few times a second while a save is
// being played. Unlocks are kept for the whole install in achievements.json in the config folder, as
// XBLA kept them per profile, and show a pop-up with the gamerscore.
//
// Rules, as on XBLA: nothing is awarded while cheats are on, and once cheats have been switched on
// nothing is awarded until the game is restarted (flags a cheat set would otherwise count later).
// A save that already has the progress unlocks the achievement when it is loaded.
//
// Achievements whose XBLA rule counts events are counted here: targets in the shooting games (from
// their HUD counters), enemies beaten with given attacks and Inky octopi frozen (from hooks in
// banjotooie.us.toml). Counts are kept with the unlocks and shown in the tab.

#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <cstring>
#include <ctime>
#include <atomic>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <mutex>
#include <string>
#include <vector>

#include <json/json.hpp>

#include "recomp.h"
#include "funcs.h"
#include "librecomp/game.hpp"
#include "recompui/recompui.h"
#include "recompui/config.h"
#include "elements/ui_container.h"
#include "elements/ui_label.h"
#include "elements/ui_pseudo_border.h"
#include "elements/ui_scroll_container.h"

#include "tooie_achievements.h"
#include "tooie_cheats.h"
#include "tooie_debug.h"
#include "tooie_toast.h"

namespace {
    struct Achievement {
        const char* id;
        const char* name;
        int points;
        const char* description;
        // Unlocked when any of these flags is set.
        std::vector<int32_t> flags;
        // Or when all of these flags are set and the game total of each of these item types is above 0.
        std::vector<int32_t> all_flags = {};
        std::vector<int16_t> all_totals = {};
        // Counted outside these rules (Shoot Em Up!).
        bool counted = false;

        bool tracked() const { return counted || !flags.empty() || !all_flags.empty() || !all_totals.empty(); }
    };

    // Names, points and descriptions as the XBLA game lists them.
    const std::vector<Achievement> achievement_list = {
        {"merry_old_soul", "A Merry Old Soul", 20,
            "You'll find Old King Coal in Chuffy's boiler and he's a bit on the grubby side. Scrub him out!",
            {0x086}},                       // FLAG_086_PROGRESS_DEFEATED_OLD_KING_COAL
        {"after_the_storm", "After The Storm", 10,
            "Ahhhh, a pretty rainbow. You did that, you old softy!",
            {0x1E1}},                       // FLAG_1E1_PHYSICAL_CCL_RainbowSpawned
        {"all_beaten_up", "All Beaten Up", 20,
            "Kill any 20 bad guys with any of these attacks: Mumbo's wand, your Pants Attack or the Daddy T-Rex.",
            {}, {}, {}, true},             // counted by tooie_ach_enemy_hit
        {"calamari_bonanza", "Calamari Bonanza", 20,
            "Don't be suckered! You'll have to freeze every single octopi.",
            {}, {}, {}, true},             // counted by tooie_ach_octopus_frozen
        {"hatch_the_future", "Hatch the Future", 20,
            "Separate our heroes for the first time, or hatch a Banjo-Kazooie Stop 'N' Swop Egg with Heggy.",
            {0x4F5, 0x3E4, 0x3E6, 0x3E7}},  // FLAG_4F5_FTT_SPLIT_UP, Stop 'n' Swop eggs hatched (blue, pink, yellow)
        {"it_lives", "It Lives!", 15,
            "Miracles do happen! Bring Sabreman back to life.",
            {0x28E}},                       // FLAG_28E_JIGGY_HFP_SABREMAN (his reward for it)
        {"knocked_out_klungo", "Knocked Out Klungo", 20,
            "He's out for revenge; not once, not twice, but three times. You need to beat him once.",
            {0x318, 0x319, 0x31A}},         // FLAG_318..31A_PROGRESS_DEFEATED_KLUNGO_1..3
        {"my_nemesis", "My Nemesis", 10,
            "Do it properly this time! Get rid of Grunty and save us from her rhymes. Off with her head!",
            {0x043}},                       // FLAG_043_PROGRESS_DEFEATED_HAG_1
        {"points_make_prizes", "Points Make Prizes", 15,
            "Balloons of any color will do, get 60 points worth or more and you're a winner... sort of.",
            {0x268}},                       // FLAG_268_JIGGY_WW_BALLOON_BURST (its Jiggy)
        {"shoot_em_up", "Shoot Em Up!", 15,
            "It's great fun exploding these little lovelies! Any 20 Ulcers, Clinkers or Mines will earn this.",
            {}, {}, {}, true},             // counted by shooting_tick, 20 over any number of games
        {"all_over", "They think it's all over...", 15,
            "Win a Colosseum Kickball final. The worst scorers rule at this game, so you should be good at it!",
            {0x252, 0x293}},                // FLAG_252_JIGGY_MT_KICKBALL, FLAG_293_JIGGY_HFP_KICKBALL
        {"treasure_hunt", "Treasure Hunt", 20,
            "You'll probably end up with many more, but to achieve this you need just one of each.",
            // The game's "first time" flags for each pickup (FLAG_02A..02F, 032, 035, 067: glowbo, egg,
            // red and gold feather, treble clef, health and empty honeycomb, jinjo, cheato page), and the
            // Jiggy (type 1) and note (type 6) totals, which have no such flag. Stop 'n' Swop items and
            // Jolly Roger's doubloons are left out as not collectibles of every level.
            {}, {0x02A, 0x02B, 0x02C, 0x02D, 0x02E, 0x02F, 0x032, 0x035, 0x067}, {1, 6}},
    };

    const std::string tab_id = "achievements";

    // Counted achievements: the running count is kept with the unlocks under "<id>_count".
    struct Counted {
        const char* id;
        int goal;
    };
    const Counted counted_list[] = {
        {"shoot_em_up", 20},       // targets in the shooting games, over any number of games
        {"all_beaten_up", 20},     // enemies beaten with Mumbo's wand, the washing machine or Daddy T-Rex
        {"calamari_bonanza", 4},   // the four Inky octopi in Atlantis, each frozen once
    };

    const Counted* counted_of(const char* id) {
        for (const Counted& c : counted_list) {
            if (std::string(c.id) == id) {
                return &c;
            }
        }
        return nullptr;
    }

    std::mutex unlocked_mutex;
    // Achievement id -> when it was unlocked (local time, "YYYY-MM-DD HH:MM").
    nlohmann::json unlocked = nlohmann::json::object();
    bool loaded = false;

    std::filesystem::path file_path() {
        return recomp::get_config_path() / "achievements.json";
    }

    void load() {
        std::lock_guard lock{unlocked_mutex};
        loaded = true;
        std::ifstream file(file_path());
        if (!file) {
            return;
        }
        nlohmann::json json = nlohmann::json::parse(file, nullptr, false);
        if (json.is_object() && json.contains("unlocked") && json["unlocked"].is_object()) {
            unlocked = json["unlocked"];
        }
    }

    // Called with unlocked_mutex held.
    void save() {
        nlohmann::json json = nlohmann::json::object();
        json["unlocked"] = unlocked;
        const std::filesystem::path path = file_path();
        const std::filesystem::path temp = path.string() + ".tmp";
        {
            std::ofstream file(temp, std::ios::trunc);
            if (!file) {
                return;
            }
            file << json.dump(4);
        }
        std::error_code ec;
        std::filesystem::rename(temp, path, ec);
    }

    // func_800D035C: the game-wide total of an item type collected, as the pause menu's totals show.
    int32_t item_total(uint8_t* rdram, recomp_context* ctx, int16_t type) {
        recomp_context call = *ctx;
        call.r29 = ctx->r29 - 0x100;
        call.r4 = (uint64_t)(int64_t)type;
        func_800D035C(rdram, &call);
        return (int32_t)call.r2;
    }

    std::string now_text() {
        const std::time_t t = std::time(nullptr);
        std::tm tm{};
#ifdef _WIN32
        localtime_s(&tm, &t);
#else
        localtime_r(&t, &tm);
#endif
        char text[32];
        std::strftime(text, sizeof(text), "%Y-%m-%d %H:%M", &tm);
        return text;
    }

    bool flag_get(uint8_t* rdram, recomp_context* ctx, int32_t flag) {
        recomp_context call = *ctx;
        call.r29 = ctx->r29 - 0x100;
        call.r4 = (uint64_t)(int64_t)flag;
        func_800DA298(rdram, &call); // the game's flag getter
        return (int32_t)call.r2 != 0;
    }

    bool log_on() {
        static const bool on = std::getenv("TOOIE_ACHIEVEMENT_LOG") != nullptr;
        return on;
    }

    // One achievement in the list. It can take focus, so a controller or the arrow keys move
    // through the list, and the list scrolls to keep the focused entry in view.
    class Entry : public recompui::Container {
    public:
        Entry(recompui::ResourceId rid, recompui::Element* parent)
            : Container(rid, parent, recompui::FlexDirection::Column, recompui::JustifyContent::FlexStart,
                        recompui::Events(recompui::EventType::Focus)) {
            enable_focus();
            set_position(recompui::Position::Relative);
            set_padding(6.0f);
            recompui::get_current_context().create_element<recompui::FocusBorder>(this, false);
        }
    protected:
        std::string_view get_type_name() override { return "AchievementEntry"; }
        void process_event(const recompui::Event& e) override {
            if (e.type == recompui::EventType::Focus) {
                const bool active = std::get<recompui::EventFocus>(e.variant).active;
                set_style_enabled(recompui::focus_state, active);
                if (active) {
                    scroll_into_view();
                }
            }
        }
    };

    void create_contents(recompui::ContextId context, recompui::Element* parent) {
        using namespace recompui;
        ScrollContainer* scroll = context.create_element<ScrollContainer>(parent, ScrollDirection::Vertical);
        scroll->set_width(100.0f, Unit::Percent);
        scroll->set_height(100.0f, Unit::Percent);
        scroll->set_padding(16.0f);

        Container* list = context.create_element<Container>(scroll, FlexDirection::Column, JustifyContent::FlexStart);
        list->set_gap(6.0f);
        list->set_as_navigation_container(NavigationType::Vertical);

        nlohmann::json done;
        {
            std::lock_guard lock{unlocked_mutex};
            done = unlocked;
        }
        int count = 0;
        int points = 0;
        int total = 0;
        for (const Achievement& a : achievement_list) {
            total += a.points;
            if (done.contains(a.id)) {
                count++;
                points += a.points;
            }
        }
        context.create_element<Label>(list,
            std::to_string(count) + " of " + std::to_string(achievement_list.size()) + " unlocked, " +
            std::to_string(points) + " of " + std::to_string(total) + " G", LabelStyle::Large);

        for (const Achievement& a : achievement_list) {
            Entry* entry = context.create_element<Entry>(list);
            entry->set_gap(2.0f);
            std::string status;
            if (done.contains(a.id) && done[a.id].is_string()) {
                status = "Unlocked " + done[a.id].get<std::string>();
            } else if (const Counted* c = a.counted ? counted_of(a.id) : nullptr) {
                const std::string key = std::string(a.id) + "_count";
                const int count = done.contains(key) && done[key].is_number_integer() ? done[key].get<int>() : 0;
                status = "Locked (" + std::to_string(count) + " of " + std::to_string(c->goal) + ")";
            } else if (!a.tracked()) {
                status = "Locked (not tracked yet)";
            } else {
                status = "Locked";
            }
            Label* title = context.create_element<Label>(entry, std::string(a.name) + "  (" + std::to_string(a.points) + " G)", LabelStyle::Normal);
            if (!done.contains(a.id)) {
                title->set_opacity(0.6f);
            }
            context.create_element<Label>(entry, a.description, LabelStyle::Small);
            Label* state = context.create_element<Label>(entry, status, LabelStyle::Small);
            state->set_opacity(0.7f);
        }
    }

    // TOOIE_ACHIEVEMENT_TEST=flag[,flag...]@ms sets game flags once, for the headless check. With
    // TOOIE_ACHIEVEMENT_LOG the Jiggy and note totals are printed then too.
    void test_flag(uint8_t* rdram, recomp_context* ctx) {
        static std::vector<int32_t> flags;
        static long long at = 0;
        static bool parsed = false;
        static bool done = false;
        static auto start = std::chrono::steady_clock::now();
        if (!parsed) {
            parsed = true;
            if (const char* env = std::getenv("TOOIE_ACHIEVEMENT_TEST")) {
                const char* p = env;
                while (*p != '\0' && *p != '@') {
                    char* end = nullptr;
                    flags.push_back((int32_t)std::strtol(p, &end, 16));
                    p = (*end == ',') ? end + 1 : end;
                }
                if (*p == '@') {
                    at = std::atoll(p + 1);
                }
            }
        }
        if (done || flags.empty() || !tooie::debug::can_warp()) {
            return;
        }
        long long ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count();
        if (ms < at) {
            return;
        }
        done = true;
        for (int32_t flag : flags) {
            recomp_context call = *ctx;
            call.r29 = ctx->r29 - 0x100;
            call.r4 = (uint64_t)(int64_t)flag;
            call.r5 = 1;
            func_800DA3B8(rdram, &call); // the game's flag setter
            std::printf("[achievements] test set flag 0x%X\n", flag);
        }
        if (log_on()) {
            std::printf("[achievements] jiggies %d, notes %d\n", item_total(rdram, ctx, 1), item_total(rdram, ctx, 6));
        }
        std::fflush(stdout);
    }

    // Shoot Em Up!: targets shot in the three shooting games, read each frame from the game's HUD
    // counters (func_800D21D0: display id -> 0x8011AFB0 + (id - 0xC0) * 12, the value set at +4).
    // Clinker's Cavern (map 0x162) and Ordnance Storage (map 0xDC) count down the targets left on
    // displays 0x103 and 0x102, one per target. Chompa's Belly (map 0x123) shows points on display 0xF7,
    // weighted by Ulcer type, so each rise counts as one Ulcer (two in the same frame count as one).
    int16_t shoot_last = -1;
    uint16_t shoot_last_map = 0;

    int16_t hud_value(uint8_t* rdram, uint32_t display) {
        const uint32_t addr = 0x8011AFB0u + (display - 0xC0u) * 12u + 4u;
        return *(int16_t*)(rdram + ((addr - 0x80000000u) ^ 2u));
    }

    // Returns how many targets were shot since the last frame.
    int shooting_tick(uint8_t* rdram) {
        const uint16_t map = tooie::debug::current_map(rdram);
        uint32_t display;
        bool counts_down;
        switch (map) {
            case 0x162: display = 0x103; counts_down = true; break;  // Clinker's Cavern
            case 0xDC:  display = 0x102; counts_down = true; break;  // Ordnance Storage
            case 0x123: display = 0xF7;  counts_down = false; break; // Chompa's Belly
            default:
                shoot_last = -1;
                shoot_last_map = map;
                return 0;
        }
        const int16_t value = hud_value(rdram, display);
        int shot = 0;
        if (map == shoot_last_map && shoot_last >= 0 && value >= 0) {
            if (counts_down && value == shoot_last - 1) {
                shot = 1;
            } else if (!counts_down && value > shoot_last) {
                shot = 1;
            }
        }
        shoot_last = value;
        shoot_last_map = map;
        return shot;
    }

    int frame_counter = 0;
    std::atomic<bool> cheats_seen = false;

    bool counting_allowed() {
        if (tooie::cheats::enabled()) {
            cheats_seen = true;
        }
        return !cheats_seen && loaded && tooie::debug::can_warp();
    }

    void unlock_message(const Achievement& a) {
        tooie::toast::show(std::string("Achievement unlocked: ") + a.name + " (" + std::to_string(a.points) + " G)");
    }

    // Adds one to a counted achievement, unlocking it at its goal. Pass a key to count each thing once
    // (kept under "<id>_seen").
    void add_count(const char* id, const std::string& once_key = "") {
        const Counted* c = counted_of(id);
        if (c == nullptr) {
            return;
        }
        const std::string count_key = std::string(id) + "_count";
        bool earned = false;
        int count = 0;
        {
            std::lock_guard lock{unlocked_mutex};
            if (!once_key.empty()) {
                nlohmann::json& seen = unlocked[std::string(id) + "_seen"];
                if (!seen.is_array()) {
                    seen = nlohmann::json::array();
                }
                for (const auto& k : seen) {
                    if (k == once_key) {
                        return;
                    }
                }
                seen.push_back(once_key);
            }
            count = unlocked.value(count_key, 0) + 1;
            unlocked[count_key] = count;
            if (count >= c->goal && !unlocked.contains(id)) {
                unlocked[id] = now_text();
                earned = true;
            }
            save();
        }
        if (log_on()) {
            std::printf("[achievements] %s %d of %d%s%s\n", id, count, c->goal, once_key.empty() ? "" : " ", once_key.c_str());
            std::fflush(stdout);
        }
        if (earned) {
            for (const Achievement& a : achievement_list) {
                if (std::string(a.id) == id) {
                    unlock_message(a);
                }
            }
        }
    }
}

void tooie::achievements::create_tab() {
    load();
    recompui::config::create_tab("Achievements", tab_id, create_contents);
}

void tooie::achievements::tick(uint8_t* rdram, recomp_context* ctx) {
    if (counting_allowed()) {
        if (shooting_tick(rdram) > 0) {
            add_count("shoot_em_up");
        }
    }

    // A few checks a second are plenty for the rest.
    if (++frame_counter < 10) {
        return;
    }
    frame_counter = 0;

    test_flag(rdram, ctx);
    if (cheats_seen || !loaded || !tooie::debug::can_warp()) {
        return;
    }

    for (const Achievement& a : achievement_list) {
        {
            std::lock_guard lock{unlocked_mutex};
            if (unlocked.contains(a.id)) {
                continue;
            }
        }
        if (!a.tracked() || a.counted) {
            continue;
        }
        bool earned = false;
        for (int32_t flag : a.flags) {
            if (flag_get(rdram, ctx, flag)) {
                earned = true;
                break;
            }
        }
        if (!earned && a.flags.empty()) {
            earned = true;
            for (int32_t flag : a.all_flags) {
                earned = earned && flag_get(rdram, ctx, flag);
            }
            for (int16_t type : a.all_totals) {
                earned = earned && item_total(rdram, ctx, type) > 0;
            }
        }
        if (!earned) {
            continue;
        }
        {
            std::lock_guard lock{unlocked_mutex};
            unlocked[a.id] = now_text();
            save();
        }
        unlock_message(a);
        if (log_on()) {
            std::printf("[achievements] unlocked %s\n", a.id);
            std::fflush(stdout);
        }
    }
}

namespace {
    uint32_t read_word(uint8_t* rdram, uint32_t addr) {
        return *(uint32_t*)(rdram + (addr - 0x80000000u));
    }
    uint16_t read_half(uint8_t* rdram, uint32_t addr) {
        return *(uint16_t*)(rdram + ((addr - 0x80000000u) ^ 2u));
    }
    uint8_t read_byte(uint8_t* rdram, uint32_t addr) {
        return rdram[(addr - 0x80000000u) ^ 3u];
    }
    bool is_ram(uint32_t addr) {
        return addr >= 0x80000000u && addr < 0x81000000u;
    }

    // The PlayerState behind an attacker collision object, or 0 when the attacker is not a player.
    // Marker 0 is the player; its index is the halfword at +0x1A shifted right by 5, and the
    // PlayerState pointers start at 0x80135490.
    uint32_t attacking_player(uint8_t* rdram, uint32_t attacker) {
        if (!is_ram(attacker) || (read_word(rdram, attacker + 0x24) >> 22) != 0) {
            return 0;
        }
        const uint32_t index = read_half(rdram, attacker + 0x1A) >> 5;
        if (index > 3) {
            return 0;
        }
        const uint32_t player = read_word(rdram, 0x80135490u + 4 * index);
        return is_ram(player) ? player : 0;
    }

    // Transformation (+0xA0 -> +0x29) and current state (+0x120 -> +4) of a PlayerState.
    uint8_t transformation(uint8_t* rdram, uint32_t player) {
        const uint32_t block = read_word(rdram, player + 0xA0);
        return is_ram(block) ? read_byte(rdram, block + 0x29) : 0;
    }
    uint32_t player_state(uint8_t* rdram, uint32_t player) {
        const uint32_t block = read_word(rdram, player + 0x120);
        return is_ram(block) ? read_word(rdram, block + 4) : 0;
    }
}

// All Beaten Up: hook in func_80108F08, the hit handler of most enemies, just before it reports the
// hit (func_800EB210). Kind 2 is a defeat. The hit code's low half is the hit table column: 30 is the
// washing machine's laundry (the "Pants Attack"), 14 Daddy T-Rex's attack. Mumbo's wand has no
// column of its own, so a defeat by the player as Mumbo (transformation 0xD) in his attack state
// (0xF7) counts, and so does any defeat by the player as Daddy T-Rex (transformation 0x13).
extern "C" void tooie_ach_enemy_hit(uint8_t* rdram, recomp_context* ctx) {
    if (!counting_allowed()) {
        return;
    }
    const uint32_t sp = (uint32_t)ctx->r29;
    if (read_word(rdram, sp + 0x8C) != 2) {
        return;
    }
    const uint32_t column = read_word(rdram, sp + 0xA8) & 0xFFFF;
    bool counts = column == 30 || column == 14;
    if (!counts) {
        const uint32_t player = attacking_player(rdram, read_word(rdram, sp + 0xA4));
        if (player != 0) {
            const uint8_t form = transformation(rdram, player);
            counts = form == 0x13 || (form == 0xD && player_state(rdram, player) == 0xF7);
        }
    }
    if (counts) {
        add_count("all_beaten_up");
    }
}

// Calamari Bonanza: hook in func_80800428_choctopus where an Inky octopus that wasn't frozen starts
// to freeze (an Ice Egg or Submarine Banjo's ping). Each one counts once, known by its map and spot
// (Inkies don't move).
extern "C" void tooie_ach_octopus_frozen(uint8_t* rdram, recomp_context* ctx) {
    if (!counting_allowed()) {
        return;
    }
    const uint32_t actor = (uint32_t)ctx->r16;
    if (!is_ram(actor)) {
        return;
    }
    char key[64];
    float pos[3];
    for (int i = 0; i < 3; i++) {
        const uint32_t bits = read_word(rdram, actor + 4 + 4 * i);
        std::memcpy(&pos[i], &bits, sizeof(float));
    }
    // Rounded to 50 units, so the same Inky always gives the same key.
    std::snprintf(key, sizeof(key), "%X:%d,%d,%d", tooie::debug::current_map(rdram),
        (int)std::lround(pos[0] / 50.0f), (int)std::lround(pos[1] / 50.0f), (int)std::lround(pos[2] / 50.0f));
    add_count("calamari_bonanza", key);
}
