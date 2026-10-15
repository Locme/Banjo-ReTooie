// Game frame rate: one Graphics option that holds the game's own update rate
// at a steady 30 or 60 frames a second, instead of letting it follow how many
// video interrupts (VIs, 60 a second) went by.
//
// The game paces itself in func_800151BC, its buffer swap: it waits until at
// least func_80015184() VIs (2 normally, 3 or 4 set by a few objects such as
// the Hailfire Peaks cannon and the cable car) have gone by since the last
// frame, swaps, and keeps the number of VIs that really went by as the next
// frame's time step. func_800A7D30 hands that count to func_800D8FA0, which
// clamps it to 1..15 and turns it into the frame's delta time (count / 60 s).
// (Attract demos call func_800D8FA0 again with their recorded steps, and run a
// fixed number of frames; while one plays nothing is changed.)
// So a frame that ran one VI late moves the whole game a step further, and
// the next one may be a step shorter.
//
// With 30 or 60 FPS chosen, two hooks in banjotooie.us.toml replace the wait
// (2 or 1 VIs, whatever the game asked for) and the time step (always 2 or 1
// VIs), so every game frame is the same length. Original leaves both alone.
//
// The game can't go faster than one frame per VI (after a swap it waits for
// the VI that shows the new picture). For 120 FPS and Unlocked the runtime
// sends VIs 2 or 4 times as often (ultramodern::set_vi_rate_multiplier; the
// audio messages stay at 60 a second) and RT64 is told the new VI rate. The
// game's step is then in 120ths or 240ths of a second, so a third hook, at the
// end of func_800A7D30, writes the frame's real delta time (0x8012C760) and
// whole 60ths for the frame count (0x8012C764, which can be 0 on some frames,
// as the game's own pause path sets it). func_800D9004, which turns that count
// into seconds, is hooked to give the delta time instead. 120 FPS waits one VI
// (1/120 s) per frame and always steps 1/120 s; Unlocked waits one VI (1/240 s)
// and steps by the VIs that really went by, so it runs as fast as the PC can
// up to 240. Recorded scenes and demos keep the original pacing (their waits
// are scaled by the multiplier). The scheduler's VI handler runs its timers and
// time-outs (the sound among them) only on every second or fourth VI, so they
// keep their 60-a-second pace.
//
// TOOIE_GAME_FPS=30|60|120|unlocked picks a mode whatever the setting says, for headless
// runs. TOOIE_GAME_FPS_LOG=1 prints, every 2 s, the game frames counted, the
// time steps the game asked for, the wait it asked for, how fast game time ran
// against real time and how far Banjo moved per second of game time.

#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <mutex>
#include <unordered_map>
#include <variant>
#include <vector>

#include "recomp.h"
#include "recompui/config.h"

#include "tooie_debug.h"
#include "tooie_game.h"
#include "tooie_game_frame_rate.h"
#include "tooie_hooks.h"
#include "ultramodern/ultramodern.hpp"

namespace RT64 {
    // lib/rt64/src/hle/rt64_vi.h (from lib-patches/rt64.patch).
    void SetVIRate(uint32_t rate);
}

namespace {
    using Mode = tooie::game_frame_rate::Mode;

    bool created = false;

    Mode forced_mode(bool& forced) {
        const char* v = std::getenv("TOOIE_GAME_FPS");
        forced = v != nullptr;
        if (!forced) {
            return Mode::Original;
        }
        if (std::strcmp(v, "60") == 0) {
            return Mode::Fps60;
        }
        if (std::strcmp(v, "30") == 0) {
            return Mode::Fps30;
        }
        if (std::strcmp(v, "120") == 0) {
            return Mode::Fps120;
        }
        if (std::strcmp(v, "unlocked") == 0) {
            return Mode::Unlocked;
        }
        return Mode::Original;
    }

    Mode mode() {
        static bool forced = false;
        static const Mode forced_value = forced_mode(forced);
        if (forced) {
            return forced_value;
        }
        if (!created) {
            return Mode::Original;
        }
        try {
            return static_cast<Mode>(std::get<uint32_t>(
                recompui::config::get_graphics_config().get_option_value(tooie::game_frame_rate::option)));
        } catch (...) {
            return Mode::Original;
        }
    }

    bool smooth_talking_heads() {
        if (!created) {
            return false;
        }
        try {
            return std::get<bool>(recompui::config::get_graphics_config().get_option_value(tooie::game_frame_rate::smooth_talking_heads_option));
        } catch (...) {
            return false;
        }
    }

    // Game frames stepped so far (tooie_frame_step_done).
    std::atomic<uint32_t> game_frames_stepped{ 0 };
    // Game time so far, in seconds (tooie_frame_step_done).
    std::atomic<double> game_seconds_total{ 0.0 };

    // Game frames left in which an attract demo counts as playing. Set by the
    // demo replay, counted down by each frame's time step.
    std::atomic<int> demo_frames{ 0 };

    // VIs per game frame for the chosen mode, or 0 for Original (and while a demo plays).
    int32_t locked_vis() {
        if (demo_frames.load() > 0) {
            return 0;
        }
        switch (mode()) {
            case Mode::Fps30:
                return 2;
            case Mode::Fps60:
            case Mode::Fps120:
            case Mode::Unlocked:
                return 1;
            default:
                return 0;
        }
    }

    // VIs a 60th of a second for the mode: 2 for 120 FPS, 4 for Unlocked.
    uint32_t multiplier_for(Mode m) {
        switch (m) {
            case Mode::Fps120:
                return 2;
            case Mode::Unlocked:
                return 4;
            default:
                return 1;
        }
    }

    // Sets the runtime's and RT64's VI rate when the mode changes. The game's VI
    // counts are in these VIs from then on.
    uint32_t apply_multiplier() {
        static uint32_t applied = 1;
        uint32_t wanted = multiplier_for(mode());
        if (wanted != applied) {
            ultramodern::set_vi_rate_multiplier(wanted);
            RT64::SetVIRate(60 * wanted);
            applied = wanted;
        }
        return applied;
    }

    // Above 60 FPS: the delta time and frame count the step hook worked out, written
    // at the end of func_800A7D30 and given by func_800D9004 while they still hold.
    constexpr gpr delta_time_addr = (int32_t)0x8012C760;
    constexpr gpr frame_count_addr = (int32_t)0x8012C764;
    constexpr gpr max_delta_addr = (int32_t)0x80125D10;  // func_800D8F50's cap
    struct FineStep {
        bool pending = false;
        float delta = 0.0f;
        int32_t count = 0;
        uint32_t carry = 0;   // VIs not yet counted as a whole 60th
        bool written = false;
    };
    FineStep fine;

    float read_float(uint8_t* rdram, gpr addr) {
        uint32_t bits = MEM_W(0, addr);
        float f;
        std::memcpy(&f, &bits, sizeof(f));
        return f;
    }

    void write_float(uint8_t* rdram, gpr addr, float f) {
        uint32_t bits;
        std::memcpy(&bits, &f, sizeof(f));
        MEM_W(0, addr) = bits;
    }

    // TOOIE_GAME_FPS_LOG=1.
    struct Log {
        std::mutex mutex;
        std::chrono::steady_clock::time_point last = std::chrono::steady_clock::now();
        uint32_t frames = 0;
        std::array<uint32_t, 6> steps{};  // time steps the game asked for: 0, 1..4, 5+
        int32_t wait = 0;
        uint32_t game_vis = 0;    // sum of the time steps used
        float banjo[3] = { 0, 0, 0 };
        float distance = 0.0f;    // how far Banjo moved
        bool has_banjo = false;
        // For timing scenes: game time since start, and the map and letterbox state last seen.
        uint64_t total_vis = 0;   // in VIs at 60 * multiplier a second
        uint64_t total_frames = 0;
        uint32_t multiplier = 1;
        double game_seconds = 0.0;   // game time in the last 2 s
        double total_seconds = 0.0;
        int map = -1;
        bool scene = false;
    };

    bool logging() {
        static const bool on = std::getenv("TOOIE_GAME_FPS_LOG") != nullptr;
        return on;
    }

    Log& log() {
        static Log l;
        return l;
    }

    // Banjo's position (PlayerState pointers at 0x80135490, +0xE4 points at the
    // position; see src/gameplay/free_camera.cpp), so the log can show how fast
    // he moves per second of game time.
    bool banjo_position(uint8_t* rdram, float out[3]) {
        auto word = [&](uint32_t addr) { return *reinterpret_cast<uint32_t*>(rdram + (addr - 0x80000000u)); };
        auto valid = [](uint32_t p) { return p >= 0x80000000u && p < 0x81000000u; };
        uint32_t player = word(0x80135490);
        uint32_t transform = valid(player) ? word(player + 0xE4) : 0;
        if (!valid(transform)) {
            return false;
        }
        for (int i = 0; i < 3; i++) {
            uint32_t bits = word(transform + 4 * i);
            std::memcpy(&out[i], &bits, sizeof(float));
        }
        return true;
    }

    void log_frame(uint8_t* rdram, int32_t asked_step, int32_t used_step) {
        Log& l = log();
        std::lock_guard lock{ l.mutex };
        l.frames++;
        l.game_seconds += used_step > 0 ? used_step / (60.0 * ultramodern::get_vi_rate_multiplier()) : 0.0;
        l.total_seconds += used_step > 0 ? used_step / (60.0 * ultramodern::get_vi_rate_multiplier()) : 0.0;
        l.game_vis += used_step > 0 ? used_step : 0;
        l.total_vis += used_step > 0 ? used_step : 0;
        l.multiplier = ultramodern::get_vi_rate_multiplier();
        l.total_frames++;
        // Map changes and letterboxed scenes, stamped with game time, so a scene's
        // length in game time can be compared between modes.
        int map = MEM_HU(0, (gpr)(int32_t)0x80132DC2);
        bool scene = tooie::in_letterboxed_scene();
        if (map != l.map || scene != l.scene) {
            static const auto start = std::chrono::steady_clock::now();
            std::printf("[game-time] %.2f s game time, %.2f s real time, frame %llu: map %03X%s%s\n", l.total_seconds,
                std::chrono::duration<double>(std::chrono::steady_clock::now() - start).count(),
                (unsigned long long)l.total_frames, map, scene ? ", letterboxed scene" : "", demo_frames.load() > 0 ? ", demo" : "");
            std::fflush(stdout);
            l.map = map;
            l.scene = scene;
        }
        float pos[3];
        if (banjo_position(rdram, pos)) {
            if (l.has_banjo) {
                float dx = pos[0] - l.banjo[0], dz = pos[2] - l.banjo[2];
                float d = std::sqrt(dx * dx + dz * dz);
                if (d < 500.0f) {  // not a warp
                    l.distance += d;
                }
            }
            std::memcpy(l.banjo, pos, sizeof(pos));
            l.has_banjo = true;
            if (std::getenv("TOOIE_POS_LOG")) { std::printf("[pos] t %.3f dt %.4f %.1f %.1f %.1f\n", l.total_seconds, used_step / (60.0 * ultramodern::get_vi_rate_multiplier()), pos[0], pos[1], pos[2]); }
        }
        l.steps[asked_step <= 0 ? 0 : (asked_step >= 5 ? 5 : asked_step)]++;
        auto now = std::chrono::steady_clock::now();
        double seconds = std::chrono::duration<double>(now - l.last).count();
        if (seconds >= 2.0) {
            double game_seconds = l.game_seconds;
            std::printf("[game-fps] %.1f game fps | VIs x%u | steps asked 0:%u 1:%u 2:%u 3:%u 4:%u 5+:%u | step used %d | wait asked %d | game time x%.2f | Banjo %.0f units per game second\n",
                l.frames / seconds, l.multiplier, l.steps[0], l.steps[1], l.steps[2], l.steps[3], l.steps[4], l.steps[5], used_step, l.wait,
                game_seconds / seconds, game_seconds > 0.0 ? l.distance / game_seconds : 0.0);
            std::fflush(stdout);
            l.frames = 0;
            l.steps.fill(0);
            l.game_vis = 0;
            l.game_seconds = 0.0;
            l.distance = 0.0f;
            l.last = now;
        }
    }
}

namespace {
    // Headless aid: TOOIE_UNLOCKED_STEPS=<n>[,<n>...] makes Unlocked step by
    // these VIs (1/240 s each) in turn, whatever really went by, to test frame
    // rates a slow PC can't reach (use with TOOIE_PAD_GAME_TIME=1).
    int32_t forced_unlocked_step(int32_t step) {
        static const std::vector<int32_t> steps = []() {
            std::vector<int32_t> out;
            if (const char* v = std::getenv("TOOIE_UNLOCKED_STEPS")) {
                for (const char* p = v; *p;) {
                    char* end = nullptr;
                    long n = std::strtol(p, &end, 10);
                    if (end == p) {
                        break;
                    }
                    if (n > 0) {
                        out.push_back((int32_t)n);
                    }
                    p = (*end == ',') ? end + 1 : end;
                }
            }
            return out;
        }();
        static size_t next = 0;
        if (steps.empty()) {
            return step;
        }
        return steps[next++ % steps.size()];
    }
}

// func_800151BC, right after each call to func_80015184: $v0 holds the VIs the
// game wants to wait between frames.
extern "C" void tooie_frame_wait(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    if (logging()) {
        log().wait = (int32_t)ctx->r2;
    }
    uint32_t multiplier = apply_multiplier();
    int32_t vis = locked_vis();
    if (vis != 0) {
        ctx->r2 = vis;
    } else if (multiplier > 1) {
        // A demo or recorded scene: its own wait, in the faster VIs.
        ctx->r2 = (int32_t)ctx->r2 * (int32_t)multiplier;
    }
}

// func_800A7D30, before it calls func_800D8FA0: $v0 holds the VIs the last
// frame took, which becomes this frame's time step.
extern "C" void tooie_frame_step(uint8_t* rdram, recomp_context* ctx) {
    int32_t asked = (int32_t)ctx->r2;
    if (demo_frames.load() > 0) {
        demo_frames--;
    }
    int32_t vis = locked_vis();
    uint32_t multiplier = ultramodern::get_vi_rate_multiplier();
    if (multiplier > 1) {
        // Steps in VIs at 60 * multiplier a second: 1 for 120 FPS, the VIs that
        // went by for Unlocked (and while a demo plays, which replaces it anyway).
        int32_t step = (vis != 0 && mode() == Mode::Fps120) ? 1 : std::max(asked, 1);
        if (vis != 0 && mode() == Mode::Unlocked) {
            step = forced_unlocked_step(step);
        }
        step = std::min<int32_t>(step, 15 * (int32_t)multiplier);
        fine.carry += (uint32_t)step;
        fine.count = (int32_t)(fine.carry / multiplier);
        fine.carry %= multiplier;
        fine.delta = step / (60.0f * multiplier);
        fine.pending = true;
        ctx->r2 = std::max(fine.count, 1);
        if (logging()) {
            log_frame(rdram, asked, step);
        }
        return;
    }
    fine.pending = false;
    fine.written = false;
    fine.carry = 0;
    if (vis != 0) {
        ctx->r2 = vis;
    }
    if (logging()) {
        log_frame(rdram, asked, (int32_t)ctx->r2);
    }
}

// func_800A7D30, after func_800D8FA0 has set the frame's delta time and count:
// above 60 FPS, put in the finer ones.
extern "C" void tooie_frame_step_done(uint8_t* rdram, recomp_context* ctx) {
    (void)ctx;
    tooie::debug::heap_check(rdram, "frame step");
    game_frames_stepped++;
    if (!fine.pending) {
        game_seconds_total.store(game_seconds_total.load() + read_float(rdram, delta_time_addr));
        return;
    }
    fine.pending = false;
    float cap = read_float(rdram, max_delta_addr);
    float delta = (cap > 0.0f && fine.delta > cap) ? cap : fine.delta;
    write_float(rdram, delta_time_addr, delta);
    MEM_W(0, frame_count_addr) = fine.count;
    fine.delta = delta;
    fine.written = true;
    game_seconds_total.store(game_seconds_total.load() + delta);
}

// func_800D9004 before it returns: $f0 is the frame count times 1/60. Above 60
// FPS give the delta time instead, while the values written above still hold
// (photo mode and the game's own pause path change them).
extern "C" void tooie_frame_seconds(uint8_t* rdram, recomp_context* ctx) {
    if (!fine.written || ultramodern::get_vi_rate_multiplier() <= 1) {
        return;
    }
    if (read_float(rdram, delta_time_addr) == fine.delta && (int32_t)MEM_W(0, frame_count_addr) == fine.count) {
        ctx->f0.fl = fine.delta;
    }
}

// func_8001546C, the game's VI thread, passes each VI to the frame queue and to
// its clients (0x80078F90: the scheduler, queue 0x800783D0, which hands back
// shown framebuffers and starts the sound timer, and the controller pak thread,
// queue 0x8007AEF0, which runs osPfsInit). Above 60 FPS that thread only gets every second or fourth
// VI; the scheduler gets them all, or the game could not get a free framebuffer
// more than 60 times a second, but skips its timers on the extra ones.
constexpr uint32_t pak_vi_queue = 0x8007AEF0;
constexpr uint32_t scheduler_queue = 0x800783D0;
std::atomic<uint32_t> vi_tick{ 0 };
// For each VI message the scheduler was sent (in order): whether it is one of the
// 60-a-second ones. The scheduler takes them in the same order, so each of its VI
// messages is matched to the VI it came from, even when it falls behind.
std::mutex scheduler_vis_mutex;
std::deque<bool> scheduler_vis;

// Before each client's osSendMesg ($a0 = its queue): drop the controller pak thread's on the skipped VIs.
extern "C" void tooie_vi_client_filter(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    uint32_t multiplier = ultramodern::get_vi_rate_multiplier();
    if (multiplier > 1 && (uint32_t)ctx->r4 == pak_vi_queue && (vi_tick.load() % multiplier) != 0) {
        ctx->r4 = 0;
    }
}

// After each client's osSendMesg ($s0 = its entry, $v0 = 0 if the message went in):
// note the scheduler's VI messages in order.
extern "C" void tooie_vi_client_sent(uint8_t* rdram, recomp_context* ctx) {
    uint32_t multiplier = ultramodern::get_vi_rate_multiplier();
    if ((uint32_t)MEM_W(0, ctx->r16) != scheduler_queue || (int32_t)ctx->r2 != 0) {
        return;
    }
    std::lock_guard lock{ scheduler_vis_mutex };
    if (multiplier <= 1) {
        scheduler_vis.clear();
        return;
    }
    scheduler_vis.push_back((vi_tick.load() % multiplier) == 0);
    while (scheduler_vis.size() > 64) {
        scheduler_vis.pop_front();
    }
}

// func_8001443C, the scheduler's VI handler, after it has handed back the shown
// framebuffer: the rest runs only for the 60-a-second VIs, so it keeps its pace.
// That rest counts down two time-outs in VIs, starts the sound timer every
// second VI (osStopTimer, then osSetTimer about 6 ms on) and sets one more timer.
// Run twice close together, it restarts the sound timer before it fires and a
// sound frame is lost, so it must follow the VI messages one for one: an earlier
// version counted them separately, and headless made about 29 sound frames a
// second instead of 30 (L: the sound broke after a while, then the sound
// microcode crashed, 2026-10-14).
extern "C" int tooie_scheduler_vi_skip(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
    std::lock_guard lock{ scheduler_vis_mutex };
    if (scheduler_vis.empty()) {
        return 0;
    }
    bool full = scheduler_vis.front();
    scheduler_vis.pop_front();
    return full ? 0 : 1;
}

// func_8001546C, once per VI, before it compares the VIs since the last frame with
// 600 (10 s, $s6): keep that 10 s at the faster VI rate, and count the VI.
extern "C" void tooie_vi_hang_limit(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    vi_tick++;
    ctx->r22 = 600 * (int32_t)ultramodern::get_vi_rate_multiplier();
}

// func_8001608C, as the game replays a frame's recorded time step: attract
// demos, the game select screen and the intro story cutscenes (seen headless).
// These run a fixed number of frames, so the game keeps its own pacing while
// one plays (at 60 FPS it would otherwise run twice as fast).
extern "C" void tooie_demo_frame(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
    demo_frames = 2;
}

// Some animations step once per game frame instead of by the delta time, so
// above 30 FPS they ran 2 to 8 times too fast. At 60, 120 and Unlocked these
// gates let each one step only once per 1/30 s of game time, counted for each
// object (by address) and once per game frame however often it is called.
// Original and 30 FPS are unchanged.
namespace {
    struct Gate {
        uint32_t frame;
        float time;
        bool run;
    };

    class StepGate {
    public:
        // True when the object at this address should skip its step this frame.
        bool skip(uint8_t* rdram, uint32_t address) {
            std::lock_guard lock{ mutex };
            if (locked_vis() != 1) {
                gates.clear();
                return false;
            }
            uint32_t frame = game_frames_stepped.load();
            auto found = gates.find(address);
            if (found == gates.end()) {
                if (gates.size() > 4096) {
                    gates.clear();
                }
                found = gates.emplace(address, Gate{ frame, 0.0f, true }).first;
                return false;
            }
            Gate& g = found->second;
            if (g.frame == frame) {
                return !g.run;
            }
            g.frame = frame;
            g.time += read_float(rdram, delta_time_addr);
            g.run = g.time >= step - 0.001f;
            if (g.run) {
                g.time = std::min(g.time - step, step);
            }
            return !g.run;
        }

    private:
        static constexpr float step = 1.0f / 30.0f;
        std::mutex mutex;
        std::unordered_map<uint32_t, Gate> gates;
    };

    StepGate portrait_gate;
    StepGate blink_gate;
}

// Talking-head portraits (the zoombox overlay): func_8080156C_gczoombox moves a
// portrait's mouth (+0x1CF, following the mouth pattern at +0xF0 indexed by
// +0x1D0) and its blink one step per game frame ($a0 = the box).
// Smooth talking heads (default off): they step every game frame instead of 30
// times a second. The mouth pattern (+0x1D0) moves on when the mouth reaches
// its frame, so they also talk faster (twice at 60 FPS).
extern "C" int tooie_portrait_step_skip(uint8_t* rdram, recomp_context* ctx) {
    if (smooth_talking_heads()) {
        return 0;
    }
    return portrait_gate.skip(rdram, (uint32_t)ctx->r4) ? 1 : 0;
}

// Character blinking: func_80101A50 runs an object's blink ($a0, state in the
// bits of +0x78 and +0x7A): each frame a random chance to start a blink, then
// the eyelid frame goes 0 to 3 and back one step a frame. It ends by giving the
// eyelid frame to the model's texture slots 1 and 2 (func_800DF744); a skipped
// frame jumps there, so the eyes still show.
extern "C" int tooie_blink_step_skip(uint8_t* rdram, recomp_context* ctx) {
    return blink_gate.skip(rdram, (uint32_t)ctx->r4) ? 1 : 0;
}

uint32_t tooie::game_frame_rate::game_ms() {
    return (uint32_t)(game_seconds_total.load() * 1000.0);
}

bool tooie::game_frame_rate::pad_on_game_time() {
    static const bool on = std::getenv("TOOIE_PAD_GAME_TIME") != nullptr;
    return on;
}

void tooie::game_frame_rate::add_option(recomp::config::Config& graphics) {
    created = true;
    graphics.add_enum_option(
        option,
        "Game Frame Rate",
        "How often the game itself updates. <recomp-color primary>Original</recomp-color> follows the game's own timing, which moves between frame lengths. "
        "<recomp-color primary>30 FPS</recomp-color>, <recomp-color primary>60 FPS</recomp-color> and <recomp-color primary>120 FPS</recomp-color> keep every game frame the same length. "
        "<recomp-color primary>Unlocked</recomp-color> runs the game as fast as your PC can, up to 240. "
        "<recomp-color warning>120 FPS and Unlocked are experimental: some objects may move at the wrong speed.</recomp-color> "
        "This is not the Interpolation option, which adds in-between frames without changing the game.",
        {
            {Mode::Original, "Original", "Original"},
            {Mode::Fps30, "Fps30", "30 FPS"},
            {Mode::Fps60, "Fps60", "60 FPS"},
            {Mode::Fps120, "Fps120", "120 FPS (Experimental)"},
            {Mode::Unlocked, "Unlocked", "Unlocked (Experimental)"},
        },
        Mode::Fps60);
    graphics.add_bool_option(
        smooth_talking_heads_option,
        "Smooth talking heads",
        "Above 30 FPS, the talking heads in dialogue boxes move their mouths and blink every frame instead of 30 times a second. "
        "Their pictures are separate drawings, so this also makes them talk faster (twice as fast at 60 FPS). "
        "The box, its opening and closing, and the text already run at the full frame rate either way.",
        false);
}

