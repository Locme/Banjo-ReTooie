// Hold to run (L, 2026-10-14): "press B and hold to run", rebindable in the controller options,
// with an animation that fits Banjo running. Only for Banjo-Kazooie, Banjo alone and Kazooie alone.
//
// The Run control is a game input in the Controls tab, on the same buttons as the N64 B button by
// default. While it is held in that form's run state, the target speed the run state asks for
// (baphysics_set_target_horizontal_velocity, hooked in banjotooie.us.toml) is raised by sprint_scale.
// The game ties its run animation's pace to the speed only up to the normal run speed, so at the
// higher speed the feet would slide (the steps get longer); the top of that speed map is stretched by
// the same factor, so Banjo's run (Banjo-Kazooie, and Banjo alone, who shares it) and Kazooie's run
// keep the same step length and simply step faster.
//
// B while moving is the forward roll (Kazooie alone: her wing attack). When Run shares a button with
// B, B is held back while moving; letting go within tap_time passes a B press on, so a tap still rolls.
// Standing still, B goes through at once (the claw swipe).
//
// Debug: TOOIE_RUN_HOLD=<from ms>:<to ms>[,...] acts as Run held between those times after the first pad
// read (headless); TOOIE_RUN_LOG=1 logs form, state, animation, speed and animation duration 4 times
// a second; TOOIE_RUN_REBIND=<SDL scancode> rebinds Run on the keyboard as the Controls tab does.

#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <mutex>
#include <utility>
#include <vector>

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include "recomp.h"
#include "funcs.h"
#include "recompinput/recompinput.h"
#include "recompinput/input_binding.h"
#include "recompinput/profiles.h"

#include "tooie_hooks.h"
#include "tooie_hold_to_run.h"

namespace {
    using namespace std::chrono_literals;
    using Clock = std::chrono::steady_clock;

    constexpr auto run_input = recompinput::GameInput::RUN;
    constexpr uint16_t button_b = 0x4000;

    // Player 0's PlayerState pointer (see src/gameplay/player_cheats.cpp).
    constexpr uint32_t player_table = 0x80135490;
    constexpr uint32_t state_offset = 0x120;   // PlayerState -> state block
    constexpr uint32_t state_current = 0x4;    // state block -> current state id
    // The player's current form (src/gameplay/transform_picker.cpp).
    constexpr uint32_t form_addr = 0x8012704C;

    // A form that can run, with the state id and animation of its run (measured headless).
    struct RunForm {
        uint8_t form;
        uint32_t run_state;
        uint32_t run_anim;
    };
    constexpr RunForm run_forms[] = {
        { 0x1, 4,   0x0C },  // Banjo-Kazooie
        { 0xA, 4,   0x0C },  // Banjo alone: the same run as Banjo-Kazooie
        { 0xB, 199, 0xA6 },  // Kazooie alone
    };

    // PlayerState +0x4 -> animation block. In the speed-scaled animation mode (the run) the duration is
    // mapped linearly from the speed at +0x24 to the duration at +0x2C, and from +0x28 to +0x30
    // (__baanim_update_scaleToHorizontalVelocity; Banjo's run: 225 to 500 units/s, 0.54 to 0.44 s).
    constexpr uint32_t map_top_speed = 0x28;
    constexpr uint32_t map_top_duration = 0x30;

    // How much faster than the normal run.
    constexpr float sprint_scale = 1.5f;
    // Letting go of a shared Run/B button sooner than this is a tap: B is passed on.
    constexpr auto tap_time = 200ms;
    // How long a passed-on tap holds B down, so the game sees the press.
    constexpr auto tap_press = 100ms;
    // A left stick tilted past this counts as moving.
    constexpr float move_tilt = 0.2f;

    uint32_t rd_word(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<uint32_t*>(rdram + (addr - 0x80000000u));
    }

    uint8_t rd_byte(uint8_t* rdram, uint32_t addr) {
        return MEM_BU(0, (gpr)(int32_t)addr);
    }

    void wr_word(uint8_t* rdram, uint32_t addr, uint32_t value) {
        *reinterpret_cast<uint32_t*>(rdram + (addr - 0x80000000u)) = value;
    }

    float as_float(uint32_t bits) {
        float f;
        std::memcpy(&f, &bits, sizeof(f));
        return f;
    }

    uint32_t as_bits(float f) {
        uint32_t bits;
        std::memcpy(&bits, &f, sizeof(bits));
        return bits;
    }

    bool valid_ptr(uint32_t p) {
        return p >= 0x80000000u && p < 0x80800000u;
    }

    const RunForm* find_form(uint8_t form) {
        for (const RunForm& f : run_forms) {
            if (f.form == form) {
                return &f;
            }
        }
        return nullptr;
    }

    // Test hook for headless runs: TOOIE_RUN_HOLD=<from ms>:<to ms>[,<from ms>:<to ms>...].
    struct TestHold {
        std::vector<std::pair<long, long>> windows;
        Clock::time_point begin = Clock::now();
    };

    TestHold& test_hold() {
        static TestHold t = [] {
            TestHold h;
            if (const char* v = std::getenv("TOOIE_RUN_HOLD")) {
                long from = 0, to = 0;
                int used = 0;
                while (std::sscanf(v, "%ld:%ld%n", &from, &to, &used) == 2) {
                    h.windows.emplace_back(from, to);
                    v += used;
                    if (*v != ',') {
                        break;
                    }
                    v++;
                }
            }
            return h;
        }();
        return t;
    }

    bool log_on() {
        static const bool on = std::getenv("TOOIE_RUN_LOG") != nullptr;
        return on;
    }

    // Whether the Run control is held, and whether any of its bindings is also one of B's.
    void read_run(bool* held, bool* shares_b) {
        *held = false;
        *shares_b = false;
        // Pressing the button to bind it in the Controls tab should not run.
        if (recompinput::binding::is_binding()) {
            return;
        }
        for (int profile : { recompinput::profiles::get_sp_keyboard_profile_index(), recompinput::profiles::get_sp_controller_profile_index() }) {
            if (profile < 0) {
                continue;
            }
            for (size_t b = 0; b < recompinput::num_bindings_per_input; b++) {
                const recompinput::InputField& field = recompinput::profiles::get_input_binding(profile, run_input, b);
                if (field.input_type == recompinput::InputType::None) {
                    continue;
                }
                *held = *held || recompinput::get_input_digital(0, field);
                for (size_t c = 0; c < recompinput::num_bindings_per_input; c++) {
                    if (recompinput::profiles::get_input_binding(profile, recompinput::GameInput::B, c) == field) {
                        *shares_b = true;
                    }
                }
            }
        }
    }

    std::mutex input_mutex;
    // Input side, under input_mutex.
    struct InputState {
        bool was_held = false;
        bool hold_started_moving = false; // B was held back from the start of this hold
        Clock::time_point held_since{};
        Clock::time_point tap_until{};    // a passed-on tap holds B until then
    } input;

    // Shared between the input and game threads.
    std::atomic<bool> run_held{false};
    std::atomic<bool> form_can_run{false};

    // Game thread only: the run animation's speed map while it is stretched, and what it was.
    bool cadence_set = false;
    uint32_t saved_speed = 0;
    uint32_t saved_duration = 0;
    uint32_t sprint_speed_bits = 0;
    uint32_t sprint_duration_bits = 0;

    recomp_context call_context(recomp_context* ctx, uint32_t a0) {
        recomp_context call = *ctx;
        call.r29 = ctx->r29 - 0x100;
        call.r4 = (int32_t)a0;
        return call;
    }

    // The player's animation controller, or 0.
    uint32_t anim_ctrl(uint8_t* rdram, recomp_context* ctx, uint32_t player) {
        recomp_context call = call_context(ctx, player);
        baanim_getAnimCtrlPtr(rdram, &call);
        const uint32_t ctrl = (uint32_t)call.r2;
        return valid_ptr(ctrl) ? ctrl : 0;
    }

    uint32_t anim_index(uint8_t* rdram, recomp_context* ctx, uint32_t ctrl) {
        recomp_context call = call_context(ctx, ctrl);
        anctrl_getIndex(rdram, &call);
        return (uint32_t)call.r2 & 0xFFFF;
    }

    uint32_t player_state(uint8_t* rdram, uint32_t player) {
        const uint32_t block = rd_word(rdram, player + state_offset);
        return valid_ptr(block) ? rd_word(rdram, block + state_current) : 0;
    }
}

void tooie::hold_to_run::register_input() {
    recompinput::set_game_input_name(run_input, "Run");
    recompinput::set_game_input_description(run_input,
        "Hold to run faster as Banjo-Kazooie, Banjo or Kazooie. On the B button, a quick tap still rolls.");
    recompinput::set_game_input_section(run_input, "Movement");
    recompinput::set_default_mapping_for_keyboard(run_input, { recompinput::InputField::keyboard(SDL_SCANCODE_LSHIFT) });
    recompinput::set_default_mapping_for_controller(run_input, { recompinput::InputField::controller_digital(recompinput::SDL_CONTROLLER_BUTTON_WEST) });
}

void tooie::hold_to_run::apply(uint16_t* buttons, float x, float y) {
    const auto now = Clock::now();
    // TOOIE_RUN_REBIND=<SDL scancode> rebinds Run on the keyboard to that key, as the Controls tab does.
    static const bool rebound = [] {
        if (const char* v = std::getenv("TOOIE_RUN_REBIND")) {
            const int profile = recompinput::profiles::get_sp_keyboard_profile_index();
            if (profile >= 0) {
                recompinput::profiles::clear_input_binding(profile, run_input);
                recompinput::profiles::set_input_binding(profile, run_input, 0,
                    recompinput::InputField::keyboard((SDL_Scancode)std::atoi(v)));
                std::printf("[run] Run rebound to keyboard scancode %d\n", std::atoi(v));
                std::fflush(stdout);
            }
        }
        return true;
    }();
    (void)rebound;
    bool held = false;
    bool shares_b = false;
    read_run(&held, &shares_b);
    TestHold& test = test_hold();
    if (!test.windows.empty()) {
        const long ms = (long)std::chrono::duration_cast<std::chrono::milliseconds>(now - test.begin).count();
        for (const auto& [from, to] : test.windows) {
            held = held || (ms >= from && ms < to);
        }
    }

    std::lock_guard lock(input_mutex);
    const bool moving = std::sqrt(x * x + y * y) > move_tilt;
    const bool can_run = form_can_run.load();

    if (held && !input.was_held) {
        input.held_since = now;
        input.hold_started_moving = shares_b && moving && can_run;
    }
    if (!held && input.was_held && input.hold_started_moving && now - input.held_since < tap_time) {
        input.tap_until = now + tap_press;
    }
    // Moving after a standing B press (the claw swipe) holds B back from then on.
    if (held && shares_b && moving && can_run) {
        input.hold_started_moving = true;
    }
    input.was_held = held;

    if (shares_b && held && input.hold_started_moving) {
        *buttons &= (uint16_t)~button_b;
    }
    if (now < input.tap_until) {
        *buttons |= button_b;
    }
    run_held = held && moving;
}

void tooie::hold_to_run::tick(uint8_t* rdram, recomp_context* ctx) {
    const uint32_t player = rd_word(rdram, player_table);
    if (!valid_ptr(player)) {
        form_can_run = false;
        cadence_set = false;
        return;
    }
    const uint8_t form = rd_byte(rdram, form_addr);
    const RunForm* rf = find_form(form);
    form_can_run = rf != nullptr;
    const uint32_t state = player_state(rdram, player);
    const uint32_t ctrl = anim_ctrl(rdram, ctx, player);
    const uint32_t index = ctrl != 0 ? anim_index(rdram, ctx, ctrl) : 0;

    if (log_on()) {
        static auto last = Clock::now();
        if (Clock::now() - last > 250ms) {
            last = Clock::now();
            const uint32_t physics = rd_word(rdram, player + 0xC8);
            float target = 0, vx = 0, vz = 0;
            if (valid_ptr(physics)) {
                uint32_t bits = rd_word(rdram, physics + 0x3C);
                std::memcpy(&target, &bits, sizeof(target));
                bits = rd_word(rdram, physics + 0x10);
                std::memcpy(&vx, &bits, sizeof(vx));
                bits = rd_word(rdram, physics + 0x18);
                std::memcpy(&vz, &bits, sizeof(vz));
            }
            float duration = 0;
            if (ctrl != 0) {
                duration = as_float(rd_word(rdram, ctrl + 0xC)); // as anctrl_setDuration stores it
            }
            const uint32_t block = rd_word(rdram, player + 0x4);
            float map[4] = {};
            if (valid_ptr(block)) {
                for (int i = 0; i < 4; i++) {
                    map[i] = as_float(rd_word(rdram, block + 0x24 + 4 * i));
                }
            }
            std::printf("[run] form 0x%X state %u anim 0x%X target %.1f speed %.1f duration %.3f (map %.0f-%.0f to %.3f-%.3f) held %d\n",
                form, state, index, target, std::sqrt(vx * vx + vz * vz), duration, map[0], map[1], map[2], map[3], (int)run_held.load());
            std::fflush(stdout);
        }
    }

    const uint32_t anim = rd_word(rdram, player + 0x4);
    if (!valid_ptr(anim)) {
        cadence_set = false;
        return;
    }
    const bool want = rf != nullptr && state == rf->run_state && index == rf->run_anim && run_held.load();
    const uint32_t cur_speed = rd_word(rdram, anim + map_top_speed);
    const uint32_t cur_duration = rd_word(rdram, anim + map_top_duration);
    if (want) {
        // The run animation's duration follows the speed linearly from map_top_speed down to
        // map_top_duration. Stretching that end to the sprint speed, with the duration shortened as
        // much, keeps Banjo's steps the same length as in the normal run. The game may set the map
        // again (a new run), so it is checked every frame.
        if (!cadence_set || cur_speed != sprint_speed_bits || cur_duration != sprint_duration_bits) {
            saved_speed = cur_speed;
            saved_duration = cur_duration;
            sprint_speed_bits = as_bits(as_float(cur_speed) * sprint_scale);
            sprint_duration_bits = as_bits(as_float(cur_duration) / sprint_scale);
            wr_word(rdram, anim + map_top_speed, sprint_speed_bits);
            wr_word(rdram, anim + map_top_duration, sprint_duration_bits);
            cadence_set = true;
        }
    } else if (cadence_set) {
        if (cur_speed == sprint_speed_bits && cur_duration == sprint_duration_bits) {
            wr_word(rdram, anim + map_top_speed, saved_speed);
            wr_word(rdram, anim + map_top_duration, saved_duration);
        }
        cadence_set = false;
    }
}

// Hooked at the entry of baphysics_set_target_horizontal_velocity($a0 = PlayerState, $a1 = speed).
extern "C" void tooie_run_target_speed(uint8_t* rdram, recomp_context* ctx) {
    if (!run_held.load()) {
        return;
    }
    const uint32_t player = rd_word(rdram, player_table);
    if ((uint32_t)ctx->r4 != player || !valid_ptr(player)) {
        return;
    }
    const RunForm* rf = find_form(rd_byte(rdram, form_addr));
    if (rf == nullptr || player_state(rdram, player) != rf->run_state) {
        return;
    }
    uint32_t bits = (uint32_t)ctx->r5;
    float speed;
    std::memcpy(&speed, &bits, sizeof(speed));
    speed *= sprint_scale;
    std::memcpy(&bits, &speed, sizeof(bits));
    ctx->r5 = (int32_t)bits;
}
