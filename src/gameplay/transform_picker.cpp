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
#include "tooie_cheats.h"
#include "tooie_debug.h"
#include "tooie_transform_picker.h"

namespace {
    // The form the game gives the player when an area loads (read by basetup_entrypoint_2).
    constexpr gpr form_addr = (int32_t)0x8012704C;
    // The game-state block holding map change requests: +0x12 go byte, +0x13 exit.
    // Banjo-Kazooie together, the form the game starts in.
    constexpr uint8_t normal_form = 0x1;
    // The word table of player pointers (player 0 first).
    constexpr gpr player_table = (int32_t)0x80135490;
    constexpr gpr game_state_addr = (int32_t)0x80127630;

    // Clockwork Kazooie (0x11) needs the missing-partner-entry hook on func_800F8A5C (banjotooie.us.toml).
    // The row's entries; the index is the saved value, 0 is Off.
    struct Form {
        const char* name;
        uint8_t id;
    };
    constexpr Form forms[] = {
        { "Off", 0 },
        { "Banjo", 0xA },
        { "Kazooie", 0xB },
        { "Mumbo", 0xD },
        { "Bee", 0x6 },
        { "Stony", 0x8 },
        { "Washing machine", 0x7 },
        { "Snowball", 0x2 },
        { "Submarine", 0xC },
        { "Golden Goliath", 0xE },
        { "Detonator", 0xF },
        { "Van", 0x10 },
        { "T-Rex (small)", 0x12 },
        { "T-Rex (large)", 0x13 },
        { "Banjo-Kazooie (BK)", 0x1 },
        { "Clockwork Kazooie", 0x11 },   // last, so saved choices keep their index
    };
    constexpr uint32_t form_count = sizeof(forms) / sizeof(forms[0]);

    // The form waiting to be applied (0 = none), set by the row's change callback.
    std::atomic<uint8_t> pending_form{0};
    // Banjo's form as of the last frame, and whether the waiting request came from the test room
    // (which works without the Cheats switch, since the Warp tab already needs it).
    std::atomic<uint8_t> current_form{0};
    std::atomic<bool> pending_from_room{false};
    // Set while the row is put back to Off after a reload, so its callback does not ask for the normal form.
    std::atomic<bool> clearing_row{false};

    // Headless test hook: TOOIE_TRANSFORM=<hex form>[@ms][,<hex form>@ms...] applies each form once, ms after
    // the game loop first runs (the Off row is form 1, the normal form).
    struct EnvRequest {
        uint8_t form = 0;
        uint32_t delay_ms = 0;
    };
    struct EnvState {
        bool read = false;
        std::vector<EnvRequest> requests;
        size_t next = 0;
        std::chrono::steady_clock::time_point started;
    };
    EnvState env;

    // The row goes back to Off once the reload is under way (L, 2026-10-19), so the menu never shows a form
    // waiting to be applied.
    void row_to_off() {
        try {
            recomp::config::Config& cheats = tooie::cheats::config();
            const recomp::config::ConfigValueVariant value = cheats.get_option_value(tooie::transform_picker::option);
            const uint32_t* idx = std::get_if<uint32_t>(&value);
            if (idx == nullptr || *idx == 0) {
                return;
            }
            clearing_row = true;
            cheats.update_option_value(tooie::transform_picker::option, 0u);
            // Saved too, so the next start does not load the form and reload the area again.
            cheats.save_config();
        } catch (...) {
            clearing_row = false;
        }
    }
}

void tooie::transform_picker::add_options(recomp::config::Config& cheats, const std::string& master_option) {
    std::vector<recomp::config::ConfigOptionEnumOption> entries;
    for (uint32_t i = 0; i < form_count; i++) {
        entries.push_back(recomp::config::ConfigOptionEnumOption(i, std::string("form_") + std::to_string(forms[i].id), forms[i].name));
    }
    cheats.add_enum_option(option, "Transformation",
        "Play as any of Mumbo's or Humba's forms. The area reloads to apply it, and the row goes back to Off. Some forms break in areas the game never expects them in.",
        entries, 0u);
    cheats.add_option_hidden_dependency(option, master_option, false);
    cheats.add_option_change_callback(option,
        [](recomp::config::ConfigValueVariant cur, recomp::config::ConfigValueVariant prev, recomp::config::OptionChangeContext) {
            const uint32_t* idx = std::get_if<uint32_t>(&cur);
            const uint32_t* was = std::get_if<uint32_t>(&prev);
            if (idx == nullptr || *idx >= form_count || (was != nullptr && *was == *idx)) {
                return;
            }
            fprintf(stderr, "[transform] picker changed to entry %u\n", *idx);
            // Off goes back to the normal form, but only when something was picked before (and not when
            // the row is put back to Off after a reload).
            if (*idx == 0) {
                if (clearing_row.exchange(false)) {
                    return;
                }
                if (was != nullptr && *was > 0) {
                    pending_form = normal_form;
                }
                return;
            }
            pending_form = forms[*idx].id;
        });
}

bool tooie::transform_picker::request_form(uint8_t form) {
    if (pending_form.load() != 0 || current_form == form) {
        return false;
    }
    pending_from_room = true;
    pending_form = form;
    return true;
}

void tooie::transform_picker::reset(recomp::config::Config& cheats) {
    pending_form = 0;
    cheats.update_option_value(option, 0u);
}

void tooie::transform_picker::tick(uint8_t* rdram, recomp_context* ctx) {
    if (!env.read) {
        env.read = true;
        env.started = std::chrono::steady_clock::now();
        if (const char* v = std::getenv("TOOIE_TRANSFORM")) {
            std::string list{v};
            size_t pos = 0;
            while (pos < list.size()) {
                size_t comma = list.find(',', pos);
                unsigned form = 0, delay = 0;
                if (std::sscanf(list.substr(pos, comma - pos).c_str(), "%x@%u", &form, &delay) >= 1 && form != 0) {
                    env.requests.push_back({ (uint8_t)form, delay });
                }
                pos = comma == std::string::npos ? list.size() : comma + 1;
            }
        }
    }
    if (env.next < env.requests.size() && tooie::debug::can_warp() && pending_form.load() == 0) {
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - env.started).count();
        if (elapsed >= env.requests[env.next].delay_ms) {
            pending_form = env.requests[env.next++].form;
        }
    }

    static const bool dbg = std::getenv("TOOIE_PLAYER_LOG") != nullptr;
    if (dbg) {
        static auto last = std::chrono::steady_clock::now();
        auto now = std::chrono::steady_clock::now();
        if (now - last >= std::chrono::seconds(1)) {
            last = now;
            uint32_t player = MEM_W(0, (gpr)(int32_t)0x80135490);
            uint8_t cur = player != 0 ? MEM_B(0x29, MEM_W(0xA0, (gpr)(int32_t)player)) : 0xFF;
            fprintf(stderr, "[transform] stored form 0x%X, player form 0x%X\n", MEM_B(0, form_addr), cur);
        }
    }
    {
        const uint32_t player = MEM_W(0, player_table);
        current_form = player != 0 ? MEM_B(0x29, MEM_W(0xA0, (gpr)(int32_t)player)) : 0;
    }
    uint8_t form = pending_form.load();
    if (form == 0) {
        return;
    }
    // The cheats were switched off, or no save file is being played: drop the request.
    if (!tooie::cheats::enabled() && !std::getenv("TOOIE_TRANSFORM") && !pending_from_room.load()) {
        pending_form = 0;
        pending_from_room = false;
        return;
    }
    if (!tooie::debug::can_warp()) {
        pending_form = 0;
        pending_from_room = false;
        // Dropped (no save file is being played), so the row does not keep showing it.
        row_to_off();
        return;
    }
    // A map change is already under way: try again next frame.
    if (MEM_B(0x12, game_state_addr) != 0) {
        return;
    }
    pending_form = 0;
    pending_from_room = false;

    {
        const uint32_t cur_player = MEM_W(0, player_table);
        if (cur_player != 0 && MEM_B(0x29, MEM_W(0xA0, (gpr)(int32_t)cur_player)) == form) {
            // Already in that form: nothing to reload, but the row still goes back to Off.
            row_to_off();
            return;
        }
    }

    const uint16_t map = tooie::debug::current_map(rdram);
    const uint8_t exit = MEM_B(0x13, game_state_addr);
    fprintf(stderr, "[transform] form 0x%X, reloading map 0x%X exit %u\n", form, map, exit);
    MEM_B(0, form_addr) = form;

    recomp_context saved = *ctx;
    // The game stores the player's current form in that byte when it leaves an area (func_80098E64),
    // so give the player the form too, or the old one is stored back over the choice.
    const uint32_t player = MEM_W(0, player_table);
    if (player != 0) {
        ctx->r4 = (int32_t)player;
        ctx->r5 = form;
        func_800A3410(rdram, ctx);
    }
    // The map change as the warp makes it (src/debug/warp.cpp), with the registers put back for func_800A7D84.
    ctx->r4 = map;
    ctx->r5 = exit;
    ctx->r6 = 1;
    func_800A7990(rdram, ctx);
    *ctx = saved;
    row_to_off();
}
