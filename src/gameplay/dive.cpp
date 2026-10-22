#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <variant>

#include "recomp.h"
#include "recompui/config.h"

#include "tooie_dive.h"
#include "tooie_game.h"
#include "tooie_game_frame_rate.h"
#include "tooie_hold_to_run.h"
#include "tooie_rdram.h"

namespace {
    using namespace std::chrono_literals;
    using Clock = std::chrono::steady_clock;
    using tooie::rdram::read_float;
    using tooie::rdram::read_word;
    using tooie::rdram::valid_ptr;
    using tooie::rdram::write_float;

    // Player 0's PlayerState and the blocks the other features read (player_cheats.cpp, torch_enemy.cpp).
    constexpr uint32_t player_table = 0x80135490;
    constexpr uint32_t physics_offset = 0xC8;  // PlayerState -> physics block
    constexpr uint32_t vel_x_offset = 0x10;    // physics block -> velocity (f32 x, y, z)
    constexpr uint32_t vel_y_offset = 0x14;
    constexpr uint32_t vel_z_offset = 0x18;
    constexpr uint32_t state_offset = 0x120;   // PlayerState -> state block
    constexpr uint32_t state_current = 0x4;    // state block -> current state id
    constexpr uint32_t yaw_ptr_offset = 0xF8;  // PlayerState -> pointer to Banjo's yaw (degrees, 0 faces +z)
    constexpr uint32_t form_addr = 0x8012704C; // 1 Banjo-Kazooie (hold_to_run.cpp)
    constexpr uint8_t form_banjo_kazooie = 1;

    constexpr uint16_t button_b = 0x4000;

    // Player states measured by the other features (player_cheats.cpp, hold_to_run.cpp): jump 5, the
    // Feathery Flap 16, the Flap Flip 0x12, falling 47 and Bill Drill 0xB6, Banjo-Kazooie's ground pound.
    // The Feathery Flap is the double jump, so a dive works after it, and in the ground pound.
    bool in_air_state(uint32_t s) {
        return s == 5 || s == 16 || s == 0x12 || s == 47 || s == 0xB6;
    }
    // Standing, walking, running and landing: where the dive's slide plays out.
    bool slide_state(uint32_t s) {
        return s == 1 || s == 2 || s == 3 || s == 4 || s == 7 || s == 0x20;
    }

    // Tuning (units per second, like the game's run speed of 500; see notes/settings-guide.md).
    // The lunge starts at burst_speed, settles to glide_speed over burst_time, and the pop is the small lift
    // that keeps the dive from reading as a plain fall. Banjo-Kazooie's jump takes off at about 665.
    constexpr float burst_speed = 850.0f;  // 1.7x the run
    constexpr float glide_speed = 700.0f;  // 1.4x the run, held to the ground
    constexpr float burst_time = 0.25f;
    constexpr float pop_speed = 150.0f;
    // Falling faster than this during the dive is held back, so the lunge flies on instead of dropping.
    constexpr float max_fall = -450.0f;
    // After landing, the belly slide runs the speed from slide_speed down to nothing over slide_time; Banjo
    // then stays on his belly until a jump.
    constexpr float slide_speed = 600.0f;
    constexpr float slide_time = 0.4f;
    // The pose eases in over this long, so the lunge reads as a push rather than a snap.
    constexpr float pose_in_time = 0.16f;
    // The wings beat and the legs kick once this often in the air (and the legs while sliding).
    constexpr float beat_time = 0.45f;
    constexpr float pose_out_time = 0.15f;
    // Moving less than this share of the lunge's speed for a frame, after the first wall_grace seconds,
    // means a wall is in the way: the dive ends there instead of pushing into it.
    constexpr float wall_share = 0.3f;
    constexpr float wall_grace = 0.1f;
    constexpr uint32_t pos_ptr_offset = 0xE4;  // PlayerState -> pointer to the position (f32 x, y, z)

    enum class Phase { Idle, Air, Slide };
    Phase phase = Phase::Idle;
    float phase_time = 0.0f;
    float heading_x = 0.0f, heading_z = 0.0f; // unit vector of the dive, fixed at the start
    bool dived_this_jump = false;
    bool run_prev = false;
    uint32_t last_game_ms = 0;
    float last_dt = 0.0f;
    // The flat pose fades from this as Banjo gets up off his belly.
    float getup = 0.0f;
    bool have_last = false;

    // Where Banjo was last tick, to see a wall stop the lunge.
    float last_x = 0.0f, last_z = 0.0f;
    float last_speed = 0.0f;

    // The pad hook (another thread) reads these. last_tick_at is when the game last ran a state update:
    // in the pause menu it doesn't, and B must reach the menu.
    std::atomic<bool> can_dive{false};
    std::atomic<bool> diving{false};
    std::atomic<int64_t> last_tick_at{0};

    int64_t now_ms() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now().time_since_epoch()).count();
    }

    bool read_pos(uint8_t* rdram, uint32_t player, float* x, float* z) {
        const uint32_t pos = read_word(rdram, player + pos_ptr_offset);
        if (!valid_ptr(pos)) {
            return false;
        }
        *x = read_float(rdram, pos);
        *z = read_float(rdram, pos + 8);
        return true;
    }

    // WIP > Dive, read a few times a second rather than on every pad read.
    bool enabled(Clock::time_point now) {
        // TOOIE_DIVE=1 turns the dive on whatever the setting says, for headless runs.
        static const bool forced = std::getenv("TOOIE_DIVE") != nullptr;
        if (forced) {
            return true;
        }
        static bool cached = false;
        static Clock::time_point cached_at{};
        if (cached_at == Clock::time_point{} || now - cached_at > 250ms) {
            cached_at = now;
            try {
                cached = std::get<bool>(recompui::config::get_config(recompui::config::graphics::id).get_option_value(tooie::dive::option));
            } catch (...) {
                cached = false;
            }
        }
        return cached;
    }

    bool log_on() {
        static const bool on = std::getenv("TOOIE_DIVE_LOG") != nullptr;
        return on;
    }

    // TOOIE_DIVE_PRESS=<from ms>:<to ms> acts as the Run button pressed in that window (after the first tick),
    // for headless runs.
    bool test_press(Clock::time_point now) {
        static const char* spec = std::getenv("TOOIE_DIVE_PRESS");
        static const Clock::time_point begin = Clock::now();
        if (spec == nullptr) {
            return false;
        }
        int from = 0, to = 0;
        if (std::sscanf(spec, "%d:%d", &from, &to) != 2) {
            return false;
        }
        const auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now - begin).count();
        return ms >= from && ms < to;
    }

    void set_speed(uint8_t* rdram, uint32_t physics, float speed) {
        write_float(rdram, physics + vel_x_offset, heading_x * speed);
        write_float(rdram, physics + vel_z_offset, heading_z * speed);
    }

    void end(const char* why) {
        if (log_on() && phase != Phase::Idle) {
            std::printf("[dive] end (%s)\n", why);
            std::fflush(stdout);
        }
        phase = Phase::Idle;
        diving = false;
    }
}

void tooie::dive::apply(uint16_t* buttons) {
    // B is the Run button on a controller, and in the air also the game's own B. While a dive can start
    // (in the air, none yet this jump) or is under way and Run is held, the game doesn't see B, so its own
    // B move doesn't fire with the dive. With Run on another key B is left alone, and so it is whenever the
    // game has stopped updating (the pause menu), where B goes back.
    const bool fresh = now_ms() - last_tick_at.load() < 150;
    if (fresh && (can_dive.load() || diving.load()) && tooie::hold_to_run::held()) {
        *buttons &= (uint16_t)~button_b;
    }
}

static void tick_inner(uint8_t* rdram, recomp_context* ctx);

void tooie::dive::tick(uint8_t* rdram, recomp_context* ctx) {
    last_tick_at = now_ms();
    tick_inner(rdram, ctx);
    // The pose eases in over pose_in_time as the lunge starts and beats once every beat_time through the
    // air. On the belly it holds, the legs fluttering while he still slides, and when he jumps up it
    // fades over pose_out_time into the jump.
    float weight = 0.0f;
    float beat = 0.0f;
    if (phase == Phase::Air) {
        weight = std::clamp(phase_time / pose_in_time, 0.0f, 1.0f);
        beat = std::max(0.0f, phase_time - pose_in_time) / beat_time;
    } else if (phase == Phase::Slide) {
        weight = 1.0f;
        getup = 1.0f;
        // Any beat above 0 means still sliding; 0 is lying still.
        beat = phase_time < slide_time ? phase_time / beat_time + 0.001f : 0.0f;
    } else if (getup > 0.0f) {
        getup = std::max(0.0f, getup - last_dt / pose_out_time);
        weight = getup;
    }
    tooie::hold_to_run::set_dive_pose(rdram, ctx, weight, beat, phase == Phase::Slide);
}

static void tick_inner(uint8_t* rdram, recomp_context* ctx) {
    const auto now = Clock::now();
    // Game time, not real time, so the dive lasts the same however fast the game runs.
    const uint32_t game_ms = tooie::game_frame_rate::game_ms();
    const float dt = have_last ? std::min((game_ms - last_game_ms) / 1000.0f, 0.1f) : 0.0f;
    last_dt = dt;
    last_game_ms = game_ms;
    have_last = true;

    // The Run button as a fresh press.
    const bool run = tooie::hold_to_run::held() || test_press(now);
    const bool pressed = run && !run_prev;
    run_prev = run;

    const uint32_t player = read_word(rdram, player_table);
    const uint32_t physics = valid_ptr(player) ? read_word(rdram, player + physics_offset) : 0;
    const uint32_t block = valid_ptr(player) ? read_word(rdram, player + state_offset) : 0;
    if (!valid_ptr(physics) || !valid_ptr(block) || !enabled(now)
        || rdram[(form_addr - 0x80000000u) ^ 3u] != form_banjo_kazooie) {
        can_dive = false;
        end("off");
        getup = 0.0f;
        dived_this_jump = false;
        return;
    }
    const uint32_t cur = read_word(rdram, block + state_current);
    const bool in_air = in_air_state(cur);

    // One dive per jump: touching the ground (a state outside the air and the slide) gives it back.
    if (!in_air && phase == Phase::Idle) {
        dived_this_jump = false;
    }
    can_dive = in_air && !dived_this_jump && phase == Phase::Idle;

    if (phase == Phase::Idle) {
        if (!(pressed && in_air && !dived_this_jump)) {
            return;
        }
        // The lunge goes the way Banjo faces, which is the heading the game turns him to.
        const uint32_t yaw_ptr = read_word(rdram, player + yaw_ptr_offset);
        const float yaw = valid_ptr(yaw_ptr) ? read_float(rdram, yaw_ptr) : 0.0f;
        const float rad = yaw * 3.14159265f / 180.0f;
        heading_x = std::sin(rad);
        heading_z = std::cos(rad);
        phase = Phase::Air;
        phase_time = 0.0f;
        dived_this_jump = true;
        diving = true;
        can_dive = false;
        // The vertical speed is replaced with a small lift, as the lunge's start.
        write_float(rdram, physics + vel_y_offset, pop_speed);
        read_pos(rdram, player, &last_x, &last_z);
        last_speed = 0.0f;
        if (log_on()) {
            std::printf("[dive] start from state %u yaw %.0f\n", cur, yaw);
            std::fflush(stdout);
        }
    }

    phase_time += dt;
    if (phase == Phase::Air) {
        if (!in_air) {
            // Landed: slide out. A state that isn't a ground state (swim, hit, climb, talk) just ends it.
            if (!slide_state(cur)) {
                end("left the air");
                return;
            }
            phase = Phase::Slide;
            phase_time = 0.0f;
            if (log_on()) {
                std::printf("[dive] land in state %u\n", cur);
                std::fflush(stdout);
            }
        } else {
            // A wall in the way: last tick's speed moved Banjo far less than it should have.
            float x = 0.0f, z = 0.0f;
            if (dt > 0.0f && read_pos(rdram, player, &x, &z)) {
                const float moved = std::sqrt((x - last_x) * (x - last_x) + (z - last_z) * (z - last_z));
                last_x = x;
                last_z = z;
                if (phase_time > wall_grace && last_speed > 0.0f && moved < last_speed * dt * wall_share) {
                    write_float(rdram, physics + vel_x_offset, 0.0f);
                    write_float(rdram, physics + vel_z_offset, 0.0f);
                    end("hit a wall");
                    return;
                }
            }
            // Burst, then glide: the speed eases from burst_speed to glide_speed over burst_time.
            const float t = std::clamp(phase_time / burst_time, 0.0f, 1.0f);
            last_speed = burst_speed + (glide_speed - burst_speed) * t;
            set_speed(rdram, physics, last_speed);
            if (read_float(rdram, physics + vel_y_offset) < max_fall) {
                write_float(rdram, physics + vel_y_offset, max_fall);
            }
            return;
        }
    }
    if (phase == Phase::Slide) {
        // Banjo slides, then lies on his belly until a jump (or anything else that leaves the ground states:
        // a hit, water, a cutscene). A jump off the belly is a new jump, so it may dive again.
        if (!slide_state(cur)) {
            end("got up");
            dived_this_jump = false;
            return;
        }
        // The speed is held even once he has stopped, so the stick turns him but doesn't walk him off.
        const float t = std::min(phase_time / slide_time, 1.0f);
        set_speed(rdram, physics, slide_speed * (1.0f - t) * (1.0f - t));
    }
}
