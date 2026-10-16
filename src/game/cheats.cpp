#include <array>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <mutex>
#include <string>
#include <string_view>
#include <thread>
#include <variant>

#include "recompui/config.h"

#include "tooie_cheats.h"
#include "tooie_level_warp.h"
#include "tooie_speedup.h"
#include "tooie_transform_picker.h"

namespace {
    const std::string tab_id = "cheats";
    const std::string enabled_option = "cheats_enabled";

    // The game's item table (data at 0x8011AF50): one (item id, cap) pair of halfwords per item, in the
    // order the game uses everywhere (index 0 = blue eggs). The cap is what the game checks when it adds
    // to a counter, and 0xFFFE (-2) is the game's own "no limit" value (see the cap setter at 0x800D1960).
    constexpr uint32_t item_table = 0x8011AF50;
    constexpr uint16_t first_item_id = 209; // blue eggs, used to tell the table has been loaded
    constexpr uint16_t infinite_cap = 0xFFFE;

    struct Cheat {
        const char* option;
        const char* name;
        const char* description;
        std::array<int, 6> items; // item table indices, -1 ends the list
    };

    constexpr Cheat cheat_list[] = {
        { "infinite_eggs", "Infinite eggs",
          "Blue, fire, ice, grenade, clockwork and mine eggs have no limit.", { 0, 1, 2, 3, 4, 5 } },
        { "infinite_feathers", "Infinite feathers",
          "Red and gold feathers have no limit.", { 6, 7, -1, -1, -1, -1 } },
        { "infinite_glowbos", "Infinite Glowbos",
          "Glowbos have no limit.", { 8, -1, -1, -1, -1, -1 } },
        { "infinite_ice_keys", "Infinite ice keys",
          "Ice keys have no limit.", { 19, -1, -1, -1, -1, -1 } },
        // This one changes the player's movement (src/gameplay/player_cheats.cpp), not the item table.
        { "cheat_infinite_jumps", "Infinite Jumps (Levitate)",
          "Press A again in mid-air to jump again, and hold it to keep rising.", { -1, -1, -1, -1, -1, -1 } },
        { "cheat_split_anywhere", "Split up anywhere",
          "Press D-pad down to split Banjo and Kazooie up where you stand, and again to join them up. While split, D-pad left plays Banjo and D-pad right plays Kazooie. Off while Noclip is on.", { -1, -1, -1, -1, -1, -1 } },
        { "cheat_noclip", "Noclip",
          "Walk and float through walls, floors and ceilings. Hold R (RT) to rise and Z (LT) to sink; you stay at that height when you let go.", { -1, -1, -1, -1, -1, -1 } },
        { "cheat_fly_anywhere", "Fly anywhere",
          "Press D-pad up to take off anywhere, as Banjo-Kazooie or the bee. While flying, B stops flying instead of doing a Beak Bomb.", { -1, -1, -1, -1, -1, -1 } },
        { "cheato_feathers", "Cheato: FEATHERS", "Doubles how many red and gold feathers you can carry (the feather counters' limits are twice the normal ones).", { -1, -1, -1, -1, -1, -1 } },
        { "cheato_eggs", "Cheato: EGGS", "Doubles how many of each kind of egg you can carry (blue, fire, ice, grenade and clockwork).", { -1, -1, -1, -1, -1, -1 } },
        { "cheato_fallproof", "Cheato: FALLPROOF", "Falling never hurts, whatever the height. Long drops that would normally take health or the damage animation do nothing.", { -1, -1, -1, -1, -1, -1 } },
        { "cheato_honeyback", "Cheato: HONEYBACK", "Gives back one piece of your honeycomb health about every three seconds until it is full, so you heal without finding honey.", { -1, -1, -1, -1, -1, -1 } },
        { "cheato_jukebox", "Cheato: JUKEBOX", "Turns on the jukebox in Jolly's Social Club (Jolly Roger's Lagoon) so you can pick music with it before the game would let you.", { -1, -1, -1, -1, -1, -1 } },
        { "cheato_getjiggy", "Cheato: GETJIGGY", "Switches on the signs in Jiggywiggy's Temple, so you can start his Jiggy puzzles without finding the signs first.", { -1, -1, -1, -1, -1, -1 } },
        { "cheato_superbanjo", "Cheato: SUPERBANJO", "Banjo and Kazooie move faster: walking, running and swimming speed all go up.", { -1, -1, -1, -1, -1, -1 } },
        { "cheato_superbaddy", "Cheato: SUPERBADDY", "Enemies move and attack faster than normal. This makes the game harder.", { -1, -1, -1, -1, -1, -1 } },
        { "cheato_honeyking", "Cheato: HONEYKING", "You take no damage from enemies and hazards, so your health never drops.", { -1, -1, -1, -1, -1, -1 } },
        { "cheato_nestking", "Cheato: NESTKING", "Your eggs and feathers never run out, so you can fire eggs and fly without limit.", { -1, -1, -1, -1, -1, -1 } },
        { "cheato_homing", "Cheato: HOMING", "Eggs you fire steer towards the nearest enemy instead of flying straight.", { -1, -1, -1, -1, -1, -1 } },
        { "cheat_stop_n_swop", "Stop 'n' Swop items",
          "Marks the Stop 'n' Swop mystery eggs (blue and pink) as collected from the Banjo-Kazooie link, without a Banjo-Kazooie save.", { -1, -1, -1, -1, -1, -1 } },
        { "cheat_unlock_everything", "Unlock everything",
          "Learns every move and opens every world, warp pad, silo, train station, Isle o' Hags path and Cheato code, and the doors and shortcuts that have a switch of their own. The area reloads once. Saving keeps it, and switching this off doesn't undo it.", { -1, -1, -1, -1, -1, -1 } },
        { "cheat_complete", "100% complete",
          "Everything done except the last boss: all 90 Jiggies, 900 notes, Jinjos, honeycombs, Cheato pages, Glowbos, doubloons and moves, every world and Jiggywiggy challenge, and every boss but Hag 1 beaten. The area reloads once. Saving keeps it, and switching this off doesn't undo it.", { -1, -1, -1, -1, -1, -1 } },
        { "cheat_dragon_kazooie", "Dragon Kazooie",
          "On: Kazooie is Dragon Kazooie, as after Humba's pool on Isle o' Hags. Off: she is Kazooie again. The area reloads when you change it, and saving keeps it.", { -1, -1, -1, -1, -1, -1 } },
        { "cheat_all_moves", "Unlock all moves", "Every move counts as learned. Your save file is not changed.", { -1, -1, -1, -1, -1, -1 } },
    };
    constexpr size_t cheat_count = sizeof(cheat_list) / sizeof(cheat_list[0]);
    constexpr size_t item_count = 20;

    std::once_flag start_once;

    // Whether each cheat is on right now (master switch included), published by the apply loop so the
    // game thread can read it every frame without touching the config.
    std::array<std::atomic<bool>, cheat_count> active{};

    bool option_on(const std::string& id) {
        try {
            return std::get<bool>(recompui::config::get_config(tab_id).get_option_value(id));
        } catch (...) {
            return false;
        }
    }

    // RDRAM halfwords are stored with the address bit 1 flipped.
    volatile uint16_t* cap_ptr(uint8_t* rdram, size_t item) {
        uint32_t addr = item_table + static_cast<uint32_t>(item) * 4 + 2;
        return reinterpret_cast<volatile uint16_t*>(rdram + (((addr - 0x80000000u) ^ 2u)));
    }

    uint16_t item_id(uint8_t* rdram, size_t item) {
        uint32_t addr = item_table + static_cast<uint32_t>(item) * 4;
        return *reinterpret_cast<volatile uint16_t*>(rdram + (((addr - 0x80000000u) ^ 2u)));
    }

    void apply_loop(uint8_t* rdram) {
        // Caps as the game had them before the cheat touched them, so turning a cheat off puts them back.
        std::array<uint16_t, item_count> original{};
        std::array<bool, item_count> overridden{};

        for (;;) {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            // The table is plain data in the game's image; wait until it has been loaded.
            if (item_id(rdram, 0) != first_item_id) {
                continue;
            }
            const bool master = tooie::cheats::enabled();

            for (size_t c = 0; c < cheat_count; c++) {
                const bool on = master && option_on(cheat_list[c].option);
                active[c] = on;
                for (int idx : cheat_list[c].items) {
                    if (idx < 0) {
                        continue;
                    }
                    volatile uint16_t* cap = cap_ptr(rdram, idx);
                    if (on) {
                        if (*cap != infinite_cap) {
                            // Remember what the game has now (it also changes caps when Banjo learns upgrades).
                            original[idx] = *cap;
                            overridden[idx] = true;
                            *cap = infinite_cap;
                        }
                    } else if (overridden[idx]) {
                        if (*cap == infinite_cap) {
                            *cap = original[idx];
                        }
                        overridden[idx] = false;
                    }
                }
            }
        }
    }
}

void tooie::cheats::create_tab() {
    recomp::config::Config& config = recompui::config::create_config_tab("Cheats", tab_id, false);

    config.add_bool_option(enabled_option, "Enable cheats",
        "Turns on the cheat options below. Achievements cannot be earned while this is on.", false);
    // Speed-up first: it is the cheat people reach for most (src/game/speedup.cpp).
    tooie::speedup::add_options(config, enabled_option);
    tooie::transform_picker::add_options(config, enabled_option);
    for (const Cheat& cheat : cheat_list) {
        config.add_bool_option(cheat.option, cheat.name, cheat.description, false);
        // The rows only show while the master switch is on.
        config.add_option_hidden_dependency(cheat.option, enabled_option, false);
    }

    // Section headings (they hide with their rows while the master switch is off).
    recompui::config::set_option_group("infinite_eggs", "Infinite items");
    recompui::config::set_option_group("cheat_infinite_jumps", "Moves");
    recompui::config::set_option_group("cheato_feathers", "Cheato codes");
    recompui::config::set_option_group("cheat_stop_n_swop", "Unlocks");

    // Turning the master switch off (or loading it off) resets every cheat.
    config.add_option_change_callback(enabled_option,
        [](recomp::config::ConfigValueVariant cur, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext) {
            if (std::holds_alternative<bool>(cur) && !std::get<bool>(cur)) {
                recomp::config::Config& cfg = recompui::config::get_config(tab_id);
                for (const Cheat& cheat : cheat_list) {
                    cfg.update_option_value(cheat.option, false);
                }
                cfg.update_option_value("debug_tab", false);
                tooie::transform_picker::reset(cfg);
            }
            // The Warp tab follows the master switch too.
            tooie::level_warp::refresh();
        });
}

void tooie::cheats::start(uint8_t* rdram) {
    std::call_once(start_once, [rdram] {
        // Detached: it only pokes game memory, so it can die with the process.
        std::thread(apply_loop, rdram).detach();
    });
}

bool tooie::cheats::enabled() {
    return option_on(enabled_option);
}

bool tooie::cheats::is_on(const char* option) {
    for (size_t c = 0; c < cheat_count; c++) {
        if (std::string_view(cheat_list[c].option) == option) {
            return active[c];
        }
    }
    return false;
}
