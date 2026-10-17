// Transform anywhere (L, 2026-10-15): QOL > Transform anywhere, off by default.
//
// The Transform key (Controls tab, Movement; keyboard T and controller LT + Y by default) changes Banjo-Kazooie into the
// form Humba Wumba gives in the world he is in, where he stands, and changes him back. A world's
// form works only once Banjo has jumped in that world's Humba pool and changed at least once (the
// game's own "first time transformed" flags, 0x345-0x34D, kept in the save file), and only in that
// world. Golden Goliath (Mumbo's) and Dragon Kazooie are not part of it (L).
//
// How the game changes form: Humba's pool calls func_800907EC(form), which is
// func_800F8730(player index, form): it stores the wanted form in the player (+0xA0 block, +0x28)
// and asks the player's current state to hand over to the transformation state (command 0xA,
// func_8009E7C8; bsdronexform). That state lifts Banjo up spinning, swaps the form in place
// (func_800A3410) and puts him down. The answer is 2 when the state took the command, so a state
// that can't be left (a cutscene, a talk) refuses on its own. The same call is made here.
//
// Terrydactyland has two forms: the Daddy T-Rex when Mumbo has enlarged the wigwam (flag 0x18A, so
// the pool there gives the big one), the baby T-Rex otherwise (L: go with the tent's size). The big
// one needs room: a line test up and around Banjo, and it is refused when something is in the way.
//
// Refused, with a sound: in the air, swimming (the submarine is the other way round: it changes in
// water only), in a cutscene or a talk, a world with no form, a form not unlocked yet, or a T-Rex
// with no room. Paused or during a map change the key does nothing.
//
// Humba's line for the form ("WUMBA CALL THIS STONY...", the one she says the first time) shows
// after the 1st, 3rd, 5th... change into a form this session (L), with func_800C05B8 and no actor
// behind it (as Bottles' moles do); when its text ends her portrait is put away with func_800C0850,
// as Humba's own code does.
//
// Headless: TOOIE_TRANSFORM_ANYWHERE=1 turns it on whatever the setting says,
// TOOIE_TRANSFORM_PRESS=<ms>[,<ms>...] presses the key that long after the game loop first runs,
// TOOIE_TRANSFORM_LOG=1 logs [transform-anywhere] lines, TOOIE_TRANSFORM_SFX=<hex> tries another
// refusal sound.

#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <string>
#include <variant>
#include <vector>

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include "recomp.h"
#include "funcs.h"
#include "librecomp/game.hpp"
#include "recompinput/recompinput.h"
#include "recompinput/input_binding.h"
#include "recompinput/profiles.h"
#include "recompui/config.h"
#include "tooie_debug.h"
#include "tooie_free_camera.h"
#include "tooie_game.h"
#include "tooie_transform_anywhere.h"

namespace {
    using Clock = std::chrono::steady_clock;

    constexpr auto transform_input = recompinput::GameInput::TRANSFORM;

    constexpr gpr player_table = (int32_t)0x80135490;    // player pointers, player 0 first
    constexpr gpr player_index_addr = (int32_t)0x801354DC; // the player being controlled (func_800F54E4)
    constexpr gpr current_level_addr = (int32_t)0x8012762C;
    constexpr gpr pause_menu_addr = (int32_t)0x80128AF0;  // pause menu object while paused
    constexpr gpr game_state_addr = (int32_t)0x80127630;  // +0x12: a map change is under way
    constexpr gpr dialog_id_addr = (int32_t)0x80128A12;   // the text being shown, -1 for none (func_800C064C)
    constexpr gpr dialog_addr = (int32_t)0x801288B0;      // the conversation (func_800C0850's argument)

    constexpr uint8_t form_bk = 0x1;
    constexpr uint8_t form_trex_small = 0x12;
    constexpr uint8_t form_trex_big = 0x13;
    constexpr uint8_t form_sub = 0xC;

    constexpr int32_t flag_tdl_wigwam_enlarged = 0x18A;

    // A world's form: the level id (0x8012762C), the form, its first-time-transformed flag and
    // Humba's line for it.
    struct WorldForm {
        uint8_t level;
        uint8_t form;
        int32_t unlock_flag;
        uint16_t text;
        const char* name;
    };
    constexpr WorldForm world_forms[] = {
        { 0x10, 0x08, 0x346, 0x11A5, "Stony" },            // Mayahem Temple
        { 0x0F, 0x0F, 0x347, 0x11A6, "Detonator" },        // Glitter Gulch Mine
        { 0x12, 0x10, 0x348, 0x11A8, "Van" },              // Witchyworld
        { 0x14, 0x0C, 0x349, 0x11A7, "Submarine" },        // Jolly Roger's Lagoon
        { 0x15, 0x12, 0x34A, 0x11A9, "Baby T-Rex" },       // Terrydactyland
        { 0x15, 0x13, 0x345, 0x11AA, "Daddy T-Rex" },      // Terrydactyland, enlarged wigwam
        { 0x16, 0x07, 0x34B, 0x11AB, "Washing machine" },  // Grunty Industries
        { 0x17, 0x02, 0x34C, 0x11AC, "Snowball" },         // Hailfire Peaks
        { 0x18, 0x06, 0x34D, 0x11AD, "Bee" },              // Cloud Cuckooland
    };

    // Room the Daddy T-Rex needs around Banjo: clear this far up, and this far out at half height.
    // Its model (0x060D) spans 701 units up and 246 either side, with the tail 700 behind.
    constexpr float trex_height = 720.0f;
    constexpr float trex_radius = 260.0f;

    // The refusal sound, played on the player as the transformation state plays its own.
    constexpr uint32_t default_refuse_sfx = 0x3EB;

    // Frames to wait after the form changes before Humba speaks (the spin finishes, Banjo lands).
    constexpr int line_delay_frames = 25;
    // Give up waiting for the form to change after this many frames.
    constexpr int change_timeout_frames = 1200;

    struct State {
        bool was_held = false;
        // A change asked for and not seen yet.
        uint8_t waiting_form = 0;
        int waiting_frames = 0;
        // Humba's line to show once the change is done (0 = none), and frames until then.
        uint16_t line = 0;
        int line_frames = 0;
        // Humba's line is up: once its text is done, her portrait is put away.
        bool line_up = false;
        bool line_seen = false;
        uint16_t line_text = 0;
        int line_up_frames = 0;
        // Changes into a form this session, for "every other time".
        uint32_t changes = 0;
    } state;

    struct EnvPresses {
        bool read = false;
        std::vector<uint32_t> at_ms;
        size_t next = 0;
        Clock::time_point started;
    } env;

    bool log_on() {
        static const bool on = std::getenv("TOOIE_TRANSFORM_LOG") != nullptr;
        return on;
    }

    bool enabled() {
        static const bool forced = std::getenv("TOOIE_TRANSFORM_ANYWHERE") != nullptr;
        if (forced) {
            return true;
        }
        try {
            return std::get<bool>(recompui::config::get_config(tooie::qol_tab_id).get_option_value(tooie::transform_anywhere::option));
        } catch (...) {
            return false;
        }
    }

    uint32_t refuse_sfx() {
        static const uint32_t sfx = [] {
            if (const char* v = std::getenv("TOOIE_TRANSFORM_SFX")) {
                return (uint32_t)std::strtoul(v, nullptr, 16);
            }
            return default_refuse_sfx;
        }();
        return sfx;
    }

    // Whether the Transform control is held (keyboard or controller).
    bool key_held() {
        if (recompinput::binding::is_binding()) {
            return false;
        }
        bool held = false;
        for (int profile : { recompinput::profiles::get_sp_keyboard_profile_index(), recompinput::profiles::get_sp_controller_profile_index() }) {
            if (profile < 0) {
                continue;
            }
            for (size_t b = 0; b < recompinput::num_bindings_per_input; b++) {
                const recompinput::InputField& field = recompinput::profiles::get_input_binding(profile, transform_input, b);
                if (field.input_type == recompinput::InputType::None) {
                    continue;
                }
                held = held || recompinput::get_input_digital(0, field);
            }
        }
        return held;
    }

    // The controller default, LT + Y (L, 2026-10-17): Y counts only while LT is held. While LT is
    // held, Y alone (C-left by default) does not reach the game; the right stick still gives C-left.
    recompinput::InputField lt_y() {
        recompinput::InputField field = recompinput::InputField::controller_digital(recompinput::SDL_CONTROLLER_BUTTON_NORTH);
        const recompinput::InputField lt = recompinput::InputField::controller_analog(SDL_CONTROLLER_AXIS_TRIGGERLEFT, true);
        field.modifier_type = lt.input_type;
        field.modifier_id = lt.input_id;
        return field;
    }

    // Saved controls from before LT + Y was the default get it once, if Transform has nothing on
    // the controller. Returns false until the controller profile is loaded.
    bool give_transform_lt_y() {
        const std::filesystem::path marker = recomp::get_config_path() / "transform_default_lt_y.done";
        std::error_code ec;
        if (std::filesystem::exists(marker, ec)) {
            return true;
        }
        const int profile = recompinput::profiles::get_sp_controller_profile_index();
        if (profile < 0) {
            return false;
        }
        bool bound = false;
        for (size_t b = 0; b < recompinput::num_bindings_per_input; b++) {
            if (recompinput::profiles::get_input_binding(profile, transform_input, b).input_type != recompinput::InputType::None) {
                bound = true;
            }
        }
        if (!bound) {
            recompinput::profiles::set_input_binding(profile, transform_input, 0, lt_y());
            recompinput::profiles::save_controls_config(recomp::get_config_path() / "controls.json");
            std::printf("[transform-anywhere] Transform bound to LT + Y on the controller\n");
        } else {
            std::printf("[transform-anywhere] Transform kept as saved on the controller\n");
        }
        std::fflush(stdout);
        std::ofstream(marker) << "Transform was given LT + Y on the controller once (transform_anywhere.cpp).\n";
        return true;
    }

    // Headless presses (TOOIE_TRANSFORM_PRESS).
    bool env_press() {
        if (!env.read) {
            env.read = true;
            env.started = Clock::now();
            if (const char* v = std::getenv("TOOIE_TRANSFORM_PRESS")) {
                std::string list{v};
                size_t pos = 0;
                while (pos < list.size()) {
                    size_t comma = list.find(',', pos);
                    env.at_ms.push_back((uint32_t)std::strtoul(list.substr(pos, comma - pos).c_str(), nullptr, 10));
                    pos = comma == std::string::npos ? list.size() : comma + 1;
                }
            }
        }
        if (env.next >= env.at_ms.size()) {
            return false;
        }
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - env.started).count();
        if (ms >= (long long)env.at_ms[env.next]) {
            env.next++;
            return true;
        }
        return false;
    }

    // A context for calling a game function from the hook: the caller's registers are kept, and the
    // stack is moved down so the callee and its stack arguments use scratch space.
    recomp_context call_context(recomp_context* ctx) {
        recomp_context call = *ctx;
        call.r29 = (int32_t)(((uint32_t)ctx->r29 - 0x200) & ~0xFu);
        return call;
    }

    bool flag_get(uint8_t* rdram, recomp_context* ctx, int32_t flag) {
        recomp_context call = call_context(ctx);
        call.r4 = (uint64_t)(int64_t)flag;
        func_800DA298(rdram, &call); // the game's flag getter
        return (int32_t)call.r2 != 0;
    }

    bool player_call_bool(uint8_t* rdram, recomp_context* ctx, uint32_t player, void (*fn)(uint8_t*, recomp_context*)) {
        recomp_context call = call_context(ctx);
        call.r4 = (int32_t)player;
        fn(rdram, &call);
        return (int32_t)call.r2 != 0;
    }

    uint8_t player_form(uint8_t* rdram, uint32_t player) {
        return MEM_BU(0x29, MEM_W(0xA0, (gpr)(int32_t)player));
    }

    // func_8009DE38(player, sound, volume): a sound on the player.
    void play_refuse(uint8_t* rdram, recomp_context* ctx, uint32_t player) {
        recomp_context call = call_context(ctx);
        call.r4 = (int32_t)player;
        call.r5 = refuse_sfx();
        call.r6 = 0x3F800000; // 1.0f
        func_8009DE38(rdram, &call);
    }

    // func_800C05B8(text, flags, position, marker, 0, 0, 0): a dialogue box with no actor behind it,
    // as Bottles' moles use it.
    void show_line(uint8_t* rdram, recomp_context* ctx, uint32_t player, uint16_t text) {
        recomp_context call = call_context(ctx);
        const uint32_t sp = (uint32_t)call.r29;
        MEM_W(0x10, (gpr)(int32_t)sp) = 0;
        MEM_W(0x14, (gpr)(int32_t)sp) = 0;
        MEM_W(0x18, (gpr)(int32_t)sp) = 0;
        call.r4 = text;
        call.r5 = 7;
        call.r6 = (int32_t)MEM_W(0xE4, (gpr)(int32_t)player); // the player's position
        call.r7 = 0;
        func_800C05B8(rdram, &call);
    }

    // Asks the player's state to hand over to the transformation (func_800F8730). True if it did.
    bool request_form(uint8_t* rdram, recomp_context* ctx, uint8_t form) {
        recomp_context call = call_context(ctx);
        call.r4 = (int32_t)MEM_W(0, player_index_addr);
        call.r5 = form;
        func_800F8730(rdram, &call);
        return (int32_t)call.r2 != 0;
    }

    // Whether the Daddy T-Rex fits where Banjo stands: nothing above him up to its height, and nothing
    // around him at half its height.
    bool trex_fits(uint8_t* rdram, recomp_context* ctx, uint32_t player) {
        const uint32_t pos_addr = MEM_W(0xE4, (gpr)(int32_t)player);
        float pos[3];
        for (int i = 0; i < 3; i++) {
            uint32_t bits = MEM_W(4 * i, (gpr)(int32_t)pos_addr);
            std::memcpy(&pos[i], &bits, sizeof(float));
        }
        float normal[3];
        const float base[3] = { pos[0], pos[1] + 40.0f, pos[2] };
        float up[3] = { pos[0], pos[1] + trex_height, pos[2] };
        if (tooie::free_camera::sweep_line(rdram, ctx, base, up, normal)) {
            if (log_on()) {
                fprintf(stderr, "[transform-anywhere] no room above (hit at %.0f)\n", up[1] - pos[1]);
            }
            return false;
        }
        const float mid[3] = { pos[0], pos[1] + trex_height * 0.5f, pos[2] };
        for (int i = 0; i < 8; i++) {
            const float a = (float)i * 3.14159265f / 4.0f;
            float out[3] = { mid[0] + std::cos(a) * trex_radius, mid[1], mid[2] + std::sin(a) * trex_radius };
            if (tooie::free_camera::sweep_line(rdram, ctx, mid, out, normal)) {
                if (log_on()) {
                    fprintf(stderr, "[transform-anywhere] no room at %d degrees\n", i * 45);
                }
                return false;
            }
        }
        return true;
    }

    const WorldForm* form_info(uint8_t form) {
        for (const WorldForm& w : world_forms) {
            if (w.form == form) {
                return &w;
            }
        }
        return nullptr;
    }

    // The form this world gives now, or nullptr: none here, or not unlocked.
    const WorldForm* world_form(uint8_t* rdram, recomp_context* ctx, uint8_t level) {
        if (level == 0x15) {
            const bool big = flag_get(rdram, ctx, flag_tdl_wigwam_enlarged);
            const WorldForm* f = form_info(big ? form_trex_big : form_trex_small);
            return flag_get(rdram, ctx, f->unlock_flag) ? f : nullptr;
        }
        for (const WorldForm& w : world_forms) {
            if (w.level == level) {
                return flag_get(rdram, ctx, w.unlock_flag) ? &w : nullptr;
            }
        }
        return nullptr;
    }

    void refuse(uint8_t* rdram, recomp_context* ctx, uint32_t player, const char* why) {
        if (log_on()) {
            fprintf(stderr, "[transform-anywhere] refused: %s\n", why);
        }
        play_refuse(rdram, ctx, player);
    }

    void press(uint8_t* rdram, recomp_context* ctx, uint32_t player) {
        const uint8_t form = player_form(rdram, player);
        const uint8_t level = MEM_BU(0, current_level_addr);
        const bool on_ground = player_call_bool(rdram, ctx, player, func_800A0FCC);
        const bool in_water = player_call_bool(rdram, ctx, player, func_800A0FD8);
        if (log_on()) {
            fprintf(stderr, "[transform-anywhere] pressed: form 0x%X, level 0x%X, ground %d, water %d\n", form, level, on_ground, in_water);
        }
        if (tooie::in_letterboxed_scene()) {
            refuse(rdram, ctx, player, "cutscene");
            return;
        }

        uint8_t target = 0;
        const WorldForm* into = nullptr;
        if (form_info(form) != nullptr) {
            // In a Humba form: back to Banjo-Kazooie.
            target = form_bk;
        } else if (form == form_bk) {
            into = world_form(rdram, ctx, level);
            if (into == nullptr) {
                refuse(rdram, ctx, player, "no unlocked form in this world");
                return;
            }
            target = into->form;
        } else {
            refuse(rdram, ctx, player, "not Banjo-Kazooie");
            return;
        }

        // The submarine lives in water; everything else changes on the ground, out of the water.
        const bool water_change = form == form_sub || target == form_sub;
        if (water_change ? !in_water : (in_water || !on_ground)) {
            refuse(rdram, ctx, player, water_change ? "the submarine needs water" : (in_water ? "swimming" : "in the air"));
            return;
        }
        if (target == form_trex_big && !trex_fits(rdram, ctx, player)) {
            refuse(rdram, ctx, player, "no room for the Daddy T-Rex");
            return;
        }
        if (!request_form(rdram, ctx, target)) {
            refuse(rdram, ctx, player, "the player's state did not hand over");
            return;
        }
        if (log_on()) {
            fprintf(stderr, "[transform-anywhere] changing 0x%X -> 0x%X\n", form, target);
        }
        state.waiting_form = target;
        state.waiting_frames = 0;
        state.line = 0;
        if (into != nullptr) {
            state.changes++;
            if (state.changes % 2 == 1) {
                state.line = into->text;
            }
        }
    }
}

void tooie::transform_anywhere::register_input() {
    recompinput::set_game_input_name(transform_input, "Transform");
    recompinput::set_game_input_description(transform_input,
        "With QOL > Transform anywhere on: changes Banjo into the world's Humba Wumba form where he stands, and back. "
        "A world's form works once you have changed in its Humba pool.");
    recompinput::set_game_input_section(transform_input, "Movement");
    recompinput::set_default_mapping_for_keyboard(transform_input, { recompinput::InputField::keyboard(SDL_SCANCODE_T) });
    recompinput::set_default_mapping_for_controller(transform_input, { lt_y() });
}

void tooie::transform_anywhere::tick(uint8_t* rdram, recomp_context* ctx) {
    static bool migrated = false;
    if (!migrated) {
        migrated = give_transform_lt_y();
    }
    const bool env_pressed = env_press();
    const bool held = key_held();
    const bool pressed = (held && !state.was_held) || env_pressed;
    state.was_held = held;

    const uint32_t player = MEM_W(0, player_table);
    if (!enabled() || !tooie::debug::can_warp() || player == 0) {
        state.waiting_form = 0;
        state.line = 0;
        state.line_up = false;
        return;
    }

    // A change under way: wait for the form, then for Banjo to land, then Humba speaks.
    if (state.waiting_form != 0) {
        if (log_on() && state.waiting_frames % 30 == 0) {
            fprintf(stderr, "[transform-anywhere] waiting: frame %d, form 0x%X, state %d\n", state.waiting_frames,
                player_form(rdram, player), (int)MEM_W(4, MEM_W(0x120, (gpr)(int32_t)player)));
        }
        if (player_form(rdram, player) == state.waiting_form) {
            if (log_on()) {
                fprintf(stderr, "[transform-anywhere] now form 0x%X after %d frames\n", state.waiting_form, state.waiting_frames);
            }
            state.waiting_form = 0;
            state.line_frames = 0;
        } else if (++state.waiting_frames > change_timeout_frames) {
            if (log_on()) {
                fprintf(stderr, "[transform-anywhere] the form did not change\n");
            }
            state.waiting_form = 0;
            state.line = 0;
        }
        return;
    }
    if (state.line != 0) {
        if (++state.line_frames >= line_delay_frames && !tooie::in_letterboxed_scene()) {
            if (log_on()) {
                fprintf(stderr, "[transform-anywhere] Humba's line 0x%X\n", state.line);
            }
            show_line(rdram, ctx, player, state.line);
            state.line_text = state.line;
            state.line = 0;
            state.line_up = true;
            state.line_seen = false;
            state.line_up_frames = 0;
        }
        return;
    }
    // The text keeps the speaker's portrait up when it ends; the game's callers put it away
    // (func_800C0850, as Humba does) once the text has been read and the box waits for its caller.
    // It must be called while the text is still the current one: before it starts, or after it has
    // gone, it crashes in gcdialogexec.
    if (state.line_up) {
        const int16_t shown = (int16_t)MEM_H(0, dialog_id_addr);
        if (shown == (int16_t)state.line_text) {
            state.line_seen = true;
        }
        if (!state.line_seen && ++state.line_up_frames > 300) {
            state.line_up = false; // it never showed
        } else if (state.line_seen && (shown != (int16_t)state.line_text ||
                                       (MEM_BU(0x11C, dialog_addr) & 0xC0) != 0)) {
            // The text has ended and the box waits for its caller (the 0x11C bits), or another
            // text took over: let it go on.
            if (shown == (int16_t)state.line_text) {
                recomp_context call = call_context(ctx);
                func_800C0850(rdram, &call);
            }
            state.line_up = false;
            if (log_on()) {
                fprintf(stderr, "[transform-anywhere] Humba's portrait put away\n");
            }
        }
    }

    if (!pressed) {
        return;
    }
    // Paused or a map change under way: the key does nothing.
    if (MEM_W(0, pause_menu_addr) != 0 || MEM_BU(0x12, game_state_addr) != 0) {
        return;
    }
    press(rdram, ctx, player);
}
