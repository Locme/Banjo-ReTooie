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
        // These two change the player's movement (src/gameplay/player_cheats.cpp), not the item table.
        { "cheat_levitate", "Levitate",
          "Hold D-pad down to float upwards.", { -1, -1, -1, -1, -1, -1 } },
        { "cheat_infinite_jumps", "Infinite jumps",
          "Press A again in mid-air to jump again, and hold it to keep rising.", { -1, -1, -1, -1, -1, -1 } },
        { "cheato_feathers", "Cheato: FEATHERS", "The game's FEATHERS code, switched on directly. No Code Chamber needed.", { -1, -1, -1, -1, -1, -1 } },
        { "cheato_eggs", "Cheato: EGGS", "The game's EGGS code, switched on directly. No Code Chamber needed.", { -1, -1, -1, -1, -1, -1 } },
        { "cheato_fallproof", "Cheato: FALLPROOF", "The game's FALLPROOF code, switched on directly. No Code Chamber needed.", { -1, -1, -1, -1, -1, -1 } },
        { "cheato_honeyback", "Cheato: HONEYBACK", "The game's HONEYBACK code, switched on directly. No Code Chamber needed.", { -1, -1, -1, -1, -1, -1 } },
        { "cheato_jukebox", "Cheato: JUKEBOX", "The game's JUKEBOX code, switched on directly. No Code Chamber needed.", { -1, -1, -1, -1, -1, -1 } },
        { "cheato_getjiggy", "Cheato: GETJIGGY", "The game's GETJIGGY code, switched on directly. No Code Chamber needed.", { -1, -1, -1, -1, -1, -1 } },
        { "cheato_superbanjo", "Cheato: SUPERBANJO", "The game's SUPERBANJO code, switched on directly. No Code Chamber needed.", { -1, -1, -1, -1, -1, -1 } },
        { "cheato_superbaddy", "Cheato: SUPERBADDY", "The game's SUPERBADDY code, switched on directly. No Code Chamber needed.", { -1, -1, -1, -1, -1, -1 } },
        { "cheato_honeyking", "Cheato: HONEYKING", "The game's HONEYKING code, switched on directly. No Code Chamber needed.", { -1, -1, -1, -1, -1, -1 } },
        { "cheato_nestking", "Cheato: NESTKING", "The game's NESTKING code, switched on directly. No Code Chamber needed.", { -1, -1, -1, -1, -1, -1 } },
        { "cheato_homing", "Cheato: HOMING", "The game's HOMING code, switched on directly. No Code Chamber needed.", { -1, -1, -1, -1, -1, -1 } },
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
    for (const Cheat& cheat : cheat_list) {
        config.add_bool_option(cheat.option, cheat.name, cheat.description, false);
        // The rows only show while the master switch is on.
        config.add_option_hidden_dependency(cheat.option, enabled_option, false);
    }

    // Turning the master switch off (or loading it off) resets every cheat.
    config.add_option_change_callback(enabled_option,
        [](recomp::config::ConfigValueVariant cur, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext) {
            if (std::holds_alternative<bool>(cur) && !std::get<bool>(cur)) {
                recomp::config::Config& cfg = recompui::config::get_config(tab_id);
                for (const Cheat& cheat : cheat_list) {
                    cfg.update_option_value(cheat.option, false);
                }
            }
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
