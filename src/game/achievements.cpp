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
// Achievements whose XBLA rule counts events (enemies beaten with given attacks, octopi frozen, one of
// each collectible) are listed but not tracked yet.

#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <cstring>
#include <ctime>
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
        // Unlocked when any of these flags is set; empty means not tracked yet.
        std::vector<int32_t> flags;
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
            {}},
        {"calamari_bonanza", "Calamari Bonanza", 20,
            "Don't be suckered! You'll have to freeze every single octopi.",
            {}},
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
            {}},
        {"all_over", "They think it's all over...", 15,
            "Win a Colosseum Kickball final. The worst scorers rule at this game, so you should be good at it!",
            {0x252, 0x293}},                // FLAG_252_JIGGY_MT_KICKBALL, FLAG_293_JIGGY_HFP_KICKBALL
        {"treasure_hunt", "Treasure Hunt", 20,
            "You'll probably end up with many more, but to achieve this you need just one of each.",
            {}},
    };

    const std::string tab_id = "achievements";

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

    void create_contents(recompui::ContextId context, recompui::Element* parent) {
        using namespace recompui;
        ScrollContainer* scroll = context.create_element<ScrollContainer>(parent, ScrollDirection::Vertical);
        scroll->set_width(100.0f, Unit::Percent);
        scroll->set_height(100.0f, Unit::Percent);
        scroll->set_padding(16.0f);

        Container* list = context.create_element<Container>(scroll, FlexDirection::Column, JustifyContent::FlexStart);
        list->set_gap(12.0f);

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
            Container* entry = context.create_element<Container>(list, FlexDirection::Column, JustifyContent::FlexStart);
            entry->set_gap(2.0f);
            std::string status;
            if (done.contains(a.id) && done[a.id].is_string()) {
                status = "Unlocked " + done[a.id].get<std::string>();
            } else if (a.flags.empty()) {
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

    // TOOIE_ACHIEVEMENT_TEST=flag@ms sets a game flag once, for the headless check.
    void test_flag(uint8_t* rdram, recomp_context* ctx) {
        static int flag = -1;
        static long long at = 0;
        static bool parsed = false;
        static bool done = false;
        static auto start = std::chrono::steady_clock::now();
        if (!parsed) {
            parsed = true;
            if (const char* env = std::getenv("TOOIE_ACHIEVEMENT_TEST")) {
                flag = (int)std::strtol(env, nullptr, 16);
                if (const char* a = std::strchr(env, '@')) {
                    at = std::atoll(a + 1);
                }
            }
        }
        if (done || flag < 0 || !tooie::debug::can_warp()) {
            return;
        }
        long long ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count();
        if (ms < at) {
            return;
        }
        done = true;
        recomp_context call = *ctx;
        call.r29 = ctx->r29 - 0x100;
        call.r4 = (uint64_t)(int64_t)flag;
        call.r5 = 1;
        func_800DA3B8(rdram, &call); // the game's flag setter
        std::printf("[achievements] test set flag 0x%X\n", flag);
        std::fflush(stdout);
    }

    int frame_counter = 0;
    bool cheats_seen = false;
}

void tooie::achievements::create_tab() {
    load();
    recompui::config::create_tab("Achievements", tab_id, create_contents);
}

void tooie::achievements::tick(uint8_t* rdram, recomp_context* ctx) {
    // A few checks a second are plenty.
    if (++frame_counter < 10) {
        return;
    }
    frame_counter = 0;

    if (tooie::cheats::enabled()) {
        cheats_seen = true;
    }
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
        bool earned = false;
        for (int32_t flag : a.flags) {
            if (flag_get(rdram, ctx, flag)) {
                earned = true;
                break;
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
        tooie::toast::show(std::string("Achievement unlocked: ") + a.name + " (" + std::to_string(a.points) + " G)");
        if (log_on()) {
            std::printf("[achievements] unlocked %s\n", a.id);
            std::fflush(stdout);
        }
    }
}
