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
// the VI that shows the new picture). For 40, 120, 175, 240 FPS and Uncapped
// the port paces the frames itself: the wait hook holds the game until the
// frame's time comes (a fixed 1/40 to 1/240 s after the last one; Uncapped
// doesn't wait at all) and lets it through without waiting for VIs, and right
// after each swap a hook asks the runtime for an extra VI
// (ultramodern::request_vi), so the new picture is shown and the game can go
// on at once. The timed VIs stay at 60 a second, and the extra ones don't send
// the audio messages. A third hook, at the end of func_800A7D30, writes the
// frame's real delta time (0x8012C760: 1/40 to 1/240 s, or for Uncapped the
// time the last frame really took) and whole 60ths for the frame count
// (0x8012C764, which can be 0 on some frames, as the game's own pause path sets
// it). func_800D9004, which turns that count into seconds, is hooked to give
// the delta time instead. RT64 is told the fixed rate so the Interpolation
// option can still blend frames above it. Recorded scenes and demos keep the
// original pacing. The scheduler's VI handler runs its timers and time-outs
// (the sound among them) only on the timed VIs, so they keep their 60-a-second
// pace.
//
// TOOIE_GAME_FPS=30|40|60|120|175|240|uncapped picks a mode whatever the setting says, for headless
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
#include <thread>
#include <unordered_map>
#include <variant>
#include <vector>

#include "recomp.h"
#include "funcs.h"
#include "recompui/config.h"

#include "tooie_debug.h"
#include "tooie_game.h"
#include "tooie_game_frame_rate.h"
#include "tooie_hooks.h"
#include "ultramodern/config.hpp"
#include "ultramodern/ultramodern.hpp"

namespace RT64 {
    // lib/rt64/src/hle/rt64_vi.h (from lib-patches/rt64.patch).
    void SetFixedFrameRate(uint32_t rate);
    bool WaitForPresentBacklog(uint32_t maxBacklog, uint32_t timeoutMs);
    // lib/rt64/src/common/rt64_timer.h: short sleeps, then a spin for the last bit.
    struct Timer {
        static void preciseSleepUntil(const std::chrono::high_resolution_clock::time_point endTime);
    };
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
        if (std::strcmp(v, "40") == 0) {
            return Mode::Fps40;
        }
        if (std::strcmp(v, "120") == 0) {
            return Mode::Fps120;
        }
        if (std::strcmp(v, "175") == 0) {
            return Mode::Fps175;
        }
        if (std::strcmp(v, "240") == 0) {
            return Mode::Fps240;
        }
        if (std::strcmp(v, "uncapped") == 0 || std::strcmp(v, "unlocked") == 0) {
            return Mode::Uncapped;
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

    // Game frames stepped so far (tooie_frame_step_done).
    std::atomic<uint32_t> game_frames_stepped{ 0 };
    // Game time so far, in seconds (tooie_frame_step_done).
    std::atomic<double> game_seconds_total{ 0.0 };

    // Game frames left in which an attract demo counts as playing. Set by the
    // demo replay, counted down by each frame's time step.
    std::atomic<int> demo_frames{ 0 };
    // The recorded time step (VIs) of the demo frame playing, from func_8001608C.
    std::atomic<int32_t> demo_step{ 2 };

    // DEV > Force Interpolation in cutscenes (on by default): the opening
    // cutscene (map 18B, before the title screen; it waits 3 VIs, 20 a second)
    // and the recorded scenes (demos) run at the game's own pace whatever the
    // Game Frame Rate, and RT64 is told that rate so Interpolation blends up to
    // the screen's. Only when Interpolation is on. Worked out once per game frame.
    std::atomic<bool> scene_forced{ false };

    bool bool_option_on(const std::string& key, const char* env_name) {
        const char* env = std::getenv(env_name);
        if (env != nullptr) {
            return env[0] == '1';
        }
        if (!created) {
            return false;
        }
        try {
            return std::get<bool>(recompui::config::get_config(tooie::wip_tab_id).get_option_value(key));
        } catch (...) {
            return false;
        }
    }

    bool force_option_on() {
        return bool_option_on(tooie::game_frame_rate::force_scene_interpolation_option, "TOOIE_FORCE_SCENE_INTERP");
    }

    // DEV > Force Interpolation in the gameplay demo (off by default): the same for the
    // recorded scenes (demos), its own toggle at L's request (2026-10-16).
    bool force_demo_option_on() {
        return bool_option_on(tooie::game_frame_rate::force_demo_interpolation_option, "TOOIE_FORCE_DEMO_INTERP");
    }

    void update_scene_forced(uint8_t* rdram) {
        constexpr int opening_cutscene_map = 0x18B;
        int map = MEM_HU(0, (gpr)(int32_t)0x80132DC2);
        // Only with Interpolation on and a Game Frame Rate other than Original
        // (L, 2026-10-16): otherwise the scene already runs as the game made it.
        bool interpolating = ultramodern::renderer::get_graphics_config().rr_option != ultramodern::renderer::RefreshRate::Original;
        scene_forced = interpolating && mode() != Mode::Original &&
            ((force_option_on() && map == opening_cutscene_map) || (force_demo_option_on() && demo_frames.load() > 0));
    }

    // VIs per game frame for 30 and 60 FPS, or 0 for the other modes (and while a demo plays).
    int32_t locked_vis() {
        if (demo_frames.load() > 0 || scene_forced.load()) {
            return 0;
        }
        switch (mode()) {
            case Mode::Fps30:
                return 2;
            case Mode::Fps60:
                return 1;
            default:
                return 0;
        }
    }

    // Frames a second for the modes the port paces itself (40, 120, 175, 240),
    // -1 for Uncapped, 0 for the others (and while a demo plays).
    int32_t paced_rate() {
        if (demo_frames.load() > 0 || scene_forced.load()) {
            return 0;
        }
        switch (mode()) {
            case Mode::Fps40:
                return 40;
            case Mode::Fps120:
                return 120;
            case Mode::Fps175:
                return 175;
            case Mode::Fps240:
                return 240;
            case Mode::Uncapped:
                return -1;
            default:
                return 0;
        }
    }

    // True for the modes above 30 FPS (not while a demo plays).
    bool above_30() {
        return locked_vis() == 1 || paced_rate() != 0;
    }

    // Rate given to RT64 for Uncapped: above any screen, so RT64 neither blends
    // frames nor holds each present to the Interpolation rate, and presents
    // without vsync (as for any rate above the screen's). With 0 (frame
    // rate unknown) it held presents to that rate, which capped Uncapped at it
    // (L: Uncapped about 100 FPS where 175 FPS reached 175, 2026-10-16).
    constexpr int32_t uncapped_rt64_rate = 100000;

    // Tells RT64 the game's frame rate when the port paces the frames (0
    // otherwise, so RT64 works it out from the VIs), for the Interpolation option.
    void apply_fixed_rate(int32_t rate) {
        static int32_t applied = 0;
        int32_t wanted = rate > 0 ? rate : (rate < 0 ? uncapped_rt64_rate : 0);
        if (wanted != applied) {
            RT64::SetFixedFrameRate((uint32_t)wanted);
            applied = wanted;
        }
    }

    double game_seconds_now() {
        return std::chrono::duration<double>(ultramodern::game_time_now()).count();
    }

    // Holds the game until this frame's time: 1/rate s after the last frame's
    // (RT64's precise sleep: short sleeps, then a spin). A frame that comes
    // later than its time starts the schedule again from now and marks the
    // pacer behind, so the next step uses the time that really went by and a
    // PC that can't reach the rate doesn't run the game in slow motion.
    struct Pacer {
        double next = 0.0;
        int32_t rate = 0;
        bool done = false;   // already paced this frame
        bool behind = false;
    };
    Pacer pacer;

    // Waits until end without holding up the game's other threads. The runtime runs one game
    // thread at a time and only switches inside OS calls, so a plain sleep here kept the VI and
    // sound threads (higher priority) from running for up to a frame. Every half millisecond it
    // lets any thread that has a message waiting run, as preempt.cpp does for the game's own spin loops.
    void wait_yielding(uint8_t* rdram, std::chrono::high_resolution_clock::time_point end) {
        using clock = std::chrono::high_resolution_clock;
        constexpr auto slice = std::chrono::microseconds(500);
        for (;;) {
            tooie_preempt_point(rdram, nullptr);
            auto now = clock::now();
            if (now >= end) {
                return;
            }
            if (end - now <= slice) {
                RT64::Timer::preciseSleepUntil(end);
                tooie_preempt_point(rdram, nullptr);
                return;
            }
            RT64::Timer::preciseSleepUntil(now + slice);
        }
    }

    // RT64::WaitForPresentBacklog, a millisecond at a time, letting the other threads run between.
    void wait_for_backlog_yielding(uint8_t* rdram, uint32_t max_backlog, uint32_t timeout_ms) {
        for (uint32_t waited = 0; waited < timeout_ms; waited++) {
            if (RT64::WaitForPresentBacklog(max_backlog, 1)) {
                return;
            }
            tooie_preempt_point(rdram, nullptr);
        }
    }

    void pace_frame(uint8_t* rdram, int32_t rate) {
        if (pacer.done) {
            return;
        }
        pacer.done = true;
        double now = game_seconds_now();
        pacer.behind = rate == pacer.rate && now - pacer.next > 0.0005 && now - pacer.next <= 0.1;
        if (rate != pacer.rate || now - pacer.next > 0.0005 || pacer.next - now > 1.0) {
            // First paced frame, a new rate, or late: start again from now.
            pacer.next = now;
        } else if (pacer.next > now) {
            wait_yielding(rdram,
                ultramodern::game_time_to_real(std::chrono::microseconds((int64_t)(pacer.next * 1e6))));
        }
        pacer.next += 1.0 / rate;
        pacer.rate = rate;
    }

    // Paced modes: the delta time and frame count the step hook worked out, written
    // at the end of func_800A7D30 and given by func_800D9004 while they still hold.
    constexpr gpr delta_time_addr = (int32_t)0x8012C760;
    constexpr gpr frame_count_addr = (int32_t)0x8012C764;
    constexpr gpr max_delta_addr = (int32_t)0x80125D10;  // func_800D8F50's cap
    struct FineStep {
        bool pending = false;
        float delta = 0.0f;
        int32_t count = 0;
        double carry = 0.0;   // game time not yet counted as a whole 60th
        bool written = false;
        double last_step = -1.0;   // game clock at the last frame step (Uncapped)
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
        float banjo[3] = { 0, 0, 0 };
        float distance = 0.0f;    // how far Banjo moved
        bool has_banjo = false;
        // For timing scenes: game time since start, and the map and letterbox state last seen.
        uint64_t total_frames = 0;
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

    // used: the frame's time step in seconds.
    void log_frame(uint8_t* rdram, int32_t asked_step, double used) {
        Log& l = log();
        std::lock_guard lock{ l.mutex };
        l.frames++;
        l.game_seconds += used;
        l.total_seconds += used;
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
            if (std::getenv("TOOIE_POS_LOG")) { std::printf("[pos] t %.3f dt %.4f %.1f %.1f %.1f\n", l.total_seconds, used, pos[0], pos[1], pos[2]); }
        }
        l.steps[asked_step <= 0 ? 0 : (asked_step >= 5 ? 5 : asked_step)]++;
        auto now = std::chrono::steady_clock::now();
        double seconds = std::chrono::duration<double>(now - l.last).count();
        if (seconds >= 2.0) {
            double game_seconds = l.game_seconds;
            std::printf("[game-fps] %.1f game fps | steps asked 0:%u 1:%u 2:%u 3:%u 4:%u 5+:%u | step used %.2f ms | wait asked %d | game time x%.2f | Banjo %.0f units per game second\n",
                l.frames / seconds, l.steps[0], l.steps[1], l.steps[2], l.steps[3], l.steps[4], l.steps[5], used * 1000.0, l.wait,
                game_seconds / seconds, game_seconds > 0.0 ? l.distance / game_seconds : 0.0);
            std::fflush(stdout);
            l.frames = 0;
            l.steps.fill(0);
            l.game_seconds = 0.0;
            l.distance = 0.0f;
            l.last = now;
        }
    }
}

namespace {
    // Headless aid: TOOIE_UNCAPPED_FPS=<n>[,<n>...] makes Uncapped step as if
    // these frame rates were reached, in turn, whatever really went by, to test
    // frame rates a slow PC can't reach (use with TOOIE_PAD_GAME_TIME=1).
    double forced_uncapped_step(double step) {
        static const std::vector<double> steps = []() {
            std::vector<double> out;
            if (const char* v = std::getenv("TOOIE_UNCAPPED_FPS")) {
                for (const char* p = v; *p;) {
                    char* end = nullptr;
                    double n = std::strtod(p, &end);
                    if (end == p) {
                        break;
                    }
                    if (n > 0.0) {
                        out.push_back(1.0 / n);
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
// game wants to wait between frames (since the last swap, counted at 0x80079704;
// it waits while 0x80079138 < $v0 - that count).
extern "C" void tooie_frame_wait(uint8_t* rdram, recomp_context* ctx) {
    if (logging()) {
        log().wait = (int32_t)ctx->r2;
    }
    int32_t rate = paced_rate();
    bool force_interp = scene_forced.load();
    int32_t vis = locked_vis();
    if (demo_frames.load() > 0) {
        // A recorded scene steps by the time each frame took on the N64 (often 3 VIs)
        // but only waits the game's minimum, which the PC always makes: it ran up to
        // half again too fast (L, 2026-10-16). Each frame now lasts its recorded step.
        ctx->r2 = std::clamp(demo_step.load(), (int32_t)1, (int32_t)4);
    }
    if (force_interp) {
        // The game's own wait, and its rate for RT64 to blend from.
        int32_t wait = std::clamp((int32_t)ctx->r2, 1, 4);
        apply_fixed_rate(60 / wait);
        return;
    }
    apply_fixed_rate(rate);
    if (vis != 0) {
        ctx->r2 = vis;
    } else if (rate != 0) {
        // Don't run more than two frames ahead of the screen: frames the renderer
        // can't show in time took GPU time from the ones it shows (L: Uncapped
        // made 300+ game frames a second but showed 100, 2026-10-16).
        wait_for_backlog_yielding(rdram, 2, 100);
        if (rate > 0) {
            pace_frame(rdram, rate);
        }
        // No VI wait: the extra VI after the last swap has shown it already.
        ctx->r2 = (int32_t)MEM_W(0, (gpr)(int32_t)0x80079704) + (int32_t)MEM_W(0, (gpr)(int32_t)0x80079138);
    }
}

// func_800151BC, right after osViSwapBuffer: in the paced modes ask for a VI now,
// so the new picture is shown and the game can go on without waiting for one.
extern "C" void tooie_frame_swapped(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
    if (paced_rate() != 0) {
        ultramodern::request_vi();
    }
}

// func_800A7D30, before it calls func_800D8FA0: $v0 holds the VIs the last
// frame took, which becomes this frame's time step.
extern "C" void tooie_frame_step(uint8_t* rdram, recomp_context* ctx) {
    int32_t asked = (int32_t)ctx->r2;
    if (demo_frames.load() > 0) {
        demo_frames--;
    }
    update_scene_forced(rdram);
    int32_t vis = locked_vis();
    int32_t rate = paced_rate();
    double now = game_seconds_now();
    double since_last = fine.last_step >= 0.0 ? now - fine.last_step : 1.0 / 60.0;
    fine.last_step = now;
    if (rate != 0) {
        // A fixed 1/rate s, or for Uncapped the time the last frame really took,
        // up to 15/60 s as the game's own step.
        // A fixed mode that fell behind its rate steps by the real time too.
        // (TOOIE_FIXED_SLOW_MOTION=1 keeps the fixed step, for headless runs.)
        static const bool slow_motion = std::getenv("TOOIE_FIXED_SLOW_MOTION") != nullptr;
        double step = rate < 0 ? forced_uncapped_step(since_last)
            : (pacer.behind && !slow_motion) ? std::max(since_last, 1.0 / rate) : 1.0 / rate;
        step = std::clamp(step, 0.0, 0.25);
        fine.carry += step;
        fine.count = (int32_t)std::floor(fine.carry * 60.0 + 1e-6);
        fine.carry = std::max(0.0, fine.carry - fine.count / 60.0);
        fine.delta = (float)step;
        fine.pending = true;
        pacer.done = false;
        ctx->r2 = std::max(fine.count, 1);
        if (logging()) {
            log_frame(rdram, asked, step);
        }
        return;
    }
    fine.pending = false;
    fine.written = false;
    fine.carry = 0.0;
    pacer.rate = 0;
    if (vis != 0) {
        ctx->r2 = vis;
    }
    if (logging()) {
        log_frame(rdram, asked, (int32_t)ctx->r2 / 60.0);
    }
}

// func_800A7D30, after func_800D8FA0 has set the frame's delta time and count:
// in the paced modes, put in the finer ones.
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

// func_800D9004 before it returns: $f0 is the frame count times 1/60. In the
// paced modes give the delta time instead, while the values written above still hold
// (photo mode and the game's own pause path change them).
extern "C" void tooie_frame_seconds(uint8_t* rdram, recomp_context* ctx) {
    if (!fine.written) {
        return;
    }
    if (read_float(rdram, delta_time_addr) == fine.delta && (int32_t)MEM_W(0, frame_count_addr) == fine.count) {
        ctx->f0.fl = fine.delta;
    }
}

// func_8001546C, the game's VI thread, passes each VI to the frame queue and to
// its clients (0x80078F90: the scheduler, queue 0x800783D0, which hands back
// shown framebuffers and starts the sound timer, and the controller pak thread,
// queue 0x8007AEF0, which runs osPfsInit). In the paced modes the runtime also
// sends extra VIs right after each swap: the pak thread doesn't get those, and
// the scheduler gets them all, so it hands back the shown framebuffer at once,
// but skips its timers on them.
constexpr uint32_t pak_vi_queue = 0x8007AEF0;
constexpr uint32_t scheduler_queue = 0x800783D0;
// Whether the VI the game's VI thread is passing on is a timed one (60 a
// second), worked out once per VI from the runtime's count of timed VIs: the
// first VI message after a timed VI counts as it, so there is one a 60th.
bool vi_is_timed = true;
uint64_t timed_vis_seen = 0;
// For each VI message the scheduler was sent (in order): whether it is a timed
// one. The scheduler takes them in the same order, so each of its VI messages is
// matched to the VI it came from, even when it falls behind.
std::mutex scheduler_vis_mutex;
std::deque<bool> scheduler_vis;

// Before each client's osSendMesg ($a0 = its queue): drop the controller pak thread's on the extra VIs.
extern "C" void tooie_vi_client_filter(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    if ((uint32_t)ctx->r4 == pak_vi_queue) {
        // Headless: TOOIE_PAD_EVERY=<n> reads the controller on every n-th timed VI only, so a
        // slow-motion run gets the several game frames per controller read a fast PC has.
        static const int every = [] { const char* v = std::getenv("TOOIE_PAD_EVERY"); return v ? std::max(1, std::atoi(v)) : 1; }();
        static int count = 0;
        if (!vi_is_timed || (every > 1 && (count++ % every) != 0)) {
            ctx->r4 = 0;
        }
    }
}

// After each client's osSendMesg ($s0 = its entry, $v0 = 0 if the message went in):
// note the scheduler's VI messages in order.
extern "C" void tooie_vi_client_sent(uint8_t* rdram, recomp_context* ctx) {
    if ((uint32_t)MEM_W(0, ctx->r16) != scheduler_queue || (int32_t)ctx->r2 != 0) {
        return;
    }
    std::lock_guard lock{ scheduler_vis_mutex };
    if (paced_rate() == 0 && vi_is_timed) {
        scheduler_vis.clear();
        return;
    }
    scheduler_vis.push_back(vi_is_timed);
    while (scheduler_vis.size() > 64) {
        scheduler_vis.pop_front();
    }
}

// func_8001443C, the scheduler's VI handler, after it has handed back the shown
// framebuffer: the rest runs only for the timed VIs, so it keeps its pace.
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
    // TOOIE_SCHED_LOG=1: every 120 timed VIs, how many VI messages ran the timed part and how many skipped it.
    static const bool dbg = std::getenv("TOOIE_SCHED_LOG") != nullptr;
    static int n_run = 0, n_skip = 0, n_empty = 0;
    static uint64_t t0 = ultramodern::get_timed_vi_count();
    if (dbg && ultramodern::get_timed_vi_count() - t0 >= 120) {
        printf("[sched] timed %llu, ran %d, skipped %d, untracked %d\n", (unsigned long long)(ultramodern::get_timed_vi_count() - t0), n_run, n_skip, n_empty);
        fflush(stdout);
        t0 = ultramodern::get_timed_vi_count();
        n_run = n_skip = n_empty = 0;
    }
    if (scheduler_vis.empty()) {
        n_empty++;
        n_run++;
        return 0;
    }
    bool timed = scheduler_vis.front();
    scheduler_vis.pop_front();
    (timed ? n_run : n_skip)++;
    return timed ? 0 : 1;
}

// func_8001546C, once per VI, before it compares the VIs since the last frame with
// 600 (10 s, $s6): note whether this VI is a timed one.
extern "C" void tooie_vi_hang_limit(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
    // Timed VIs not yet passed on. When this thread falls behind, two timed VIs can come
    // before it handles the first one's message; each gets a message, so each counts as timed
    // when its turn comes. Comparing only with the last count made the second one an extra VI:
    // at 40 FPS about 15 of 120 timed VIs, each a lost sound frame (L: sound broken at 40 FPS,
    // 2026-10-16). Capped, so messages the runtime dropped can't make later extra VIs timed.
    static uint64_t pending = 0;
    uint64_t timed = ultramodern::get_timed_vi_count();
    pending = std::min<uint64_t>(pending + (timed - timed_vis_seen), 2);
    timed_vis_seen = timed;
    vi_is_timed = pending > 0;
    if (pending > 0) {
        pending--;
    }
}

// func_8001608C, as the game replays a frame's recorded time step: attract
// demos, the game select screen and the intro story cutscenes (seen headless).
// These run a fixed number of frames, so the game keeps its own pacing while
// one plays (at 60 FPS it would otherwise run twice as fast).
// $a0 is loaded in the delay slot, so the step is still at 0x50($sp).
extern "C" void tooie_demo_frame(uint8_t* rdram, recomp_context* ctx) {
    demo_frames = 2;
    demo_step = (int32_t)MEM_W(0x50, ctx->r29);
    static const bool log_steps = std::getenv("TOOIE_DEMO_LOG") != nullptr;
    if (log_steps) {
        std::printf("[demo] step %d\n", (int)demo_step.load());
        std::fflush(stdout);
    }
}

// Some animations step once per game frame instead of by the delta time, so
// above 30 FPS they ran too fast. Above 30 FPS these
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
            if (!above_30()) {
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
extern "C" int tooie_portrait_step_skip(uint8_t* rdram, recomp_context* ctx) {
    return portrait_gate.skip(rdram, (uint32_t)ctx->r4) ? 1 : 0;
}

// func_808005F4_chbanjocurrent, as it pushes Banjo along a water current (Jolly Roger's
// Lagoon): $f12 holds 8, the push per game frame. The game adds it to his position each frame
// with no delta time, so above 30 FPS the current grew stronger with the frame rate (headless
// at 240 FPS he drifted 240 units a second instead of about 10) and could push him back while
// he swam (L, 2026-10-16). Outside Original it is scaled to the frame's time, as at 30 FPS.
extern "C" void tooie_current_push(uint8_t* rdram, recomp_context* ctx) {
    if (mode() == Mode::Original) {
        return;
    }
    float dt = read_float(rdram, delta_time_addr);
    ctx->f12.fl = 8.0f * std::clamp(dt * 30.0f, 0.0f, 2.0f);
}

// Character blinking: func_80101A50 runs an object's blink ($a0, state in the
// bits of +0x78 and +0x7A): each frame a random chance to start a blink, then
// the eyelid frame goes 0 to 3 and back one step a frame. It ends by giving the
// eyelid frame to the model's texture slots 1 and 2 (func_800DF744); a skipped
// frame jumps there, so the eyes still show.
extern "C" int tooie_blink_step_skip(uint8_t* rdram, recomp_context* ctx) {
    return blink_gate.skip(rdram, (uint32_t)ctx->r4) ? 1 : 0;
}

// Klungo's fades (func_8080231C_chklungo out, func_808023A4_chklungo in; $a0 Klungo,
// $a1 the alpha to stop at, $a2 the speed per second, both floats): alpha +- speed x
// frame time, truncated to a whole number and stored, returning 1 once the stop is
// passed. At 30 FPS that is 5 a frame (150 a second); at 150 FPS and up a fade in
// adds under 1, which truncates away, so Klungo never came back from invisible (and
// fades ran at the wrong speed at 60 and 120). Above 30 FPS this runs the same fade
// but keeps the fraction between frames. Returns 1 when it ran the fade.
namespace {
    struct FadeCarry {
        int32_t alpha;
        float value;
    };
    std::mutex fade_mutex;
    std::unordered_map<uint32_t, FadeCarry> fade_carry;
}

extern "C" int tooie_klungo_fade(uint8_t* rdram, recomp_context* ctx, int fade_in) {
    if (!above_30()) {
        std::lock_guard lock{ fade_mutex };
        fade_carry.clear();
        return 0;
    }
    const uint32_t klungo = (uint32_t)ctx->r4;
    float stop, speed;
    const uint32_t stop_bits = (uint32_t)ctx->r5, speed_bits = (uint32_t)ctx->r6;
    std::memcpy(&stop, &stop_bits, sizeof(stop));
    std::memcpy(&speed, &speed_bits, sizeof(speed));

    recomp_context call = *ctx;
    _subaddiefade_entrypoint_0(rdram, &call);   // alpha (jal 0x80089C90)
    const int32_t alpha = (int32_t)call.r2;

    float value = (float)alpha;
    {
        std::lock_guard lock{ fade_mutex };
        auto found = fade_carry.find(klungo);
        if (found != fade_carry.end() && found->second.alpha == alpha) {
            value = found->second.value;
        }
    }
    const float step = read_float(rdram, delta_time_addr) * speed;
    value = fade_in ? value + step : value - step;
    bool reached = fade_in ? (stop < value) : (value < stop);
    if (reached) {
        value = stop;
    }
    const int32_t stored = (int32_t)value;
    {
        std::lock_guard lock{ fade_mutex };
        if (fade_carry.size() > 64) {
            fade_carry.clear();
        }
        fade_carry[klungo] = FadeCarry{ stored, value };
    }

    call = *ctx;
    call.r4 = ctx->r4;
    call.r5 = stored;
    _subaddiefade_entrypoint_1(rdram, &call);   // set alpha (jal 0x80089C98)
    ctx->r2 = reached ? 1 : 0;
    return 1;
}

void tooie::game_frame_rate::add_dev_options(recomp::config::Config& dev) {
    dev.add_bool_option(
        force_scene_interpolation_option,
        "Force Interpolation in cutscenes",
        "While the opening cutscene plays, runs it at the game's own frame rate when Game Frame Rate is above Original, so its pacing is right, "
        "and Interpolation blends in-between frames up to its rate. Does nothing while Interpolation is Original.",
        true);
    dev.add_bool_option(
        force_demo_interpolation_option,
        "Force Interpolation in the gameplay demo",
        "The same for the gameplay demo that plays when you don't press Start (and the other recorded scenes): "
        "Interpolation blends it up to its rate. The demo keeps its own speed either way.",
        false);
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
        "<recomp-color primary>30</recomp-color> to <recomp-color primary>240 FPS</recomp-color> keep every game frame the same length. "
        "<recomp-color primary>Uncapped</recomp-color> runs the game as fast as your PC can, with no limit. "
        "Above your screen's refresh rate (and always in Uncapped) the picture is shown without vsync, so it can tear. "
        "<recomp-color warning>Above 60 FPS is experimental: some objects may move at the wrong speed.</recomp-color> "
        "This is not the Interpolation option, which adds in-between frames without changing the game.",
        {
            {Mode::Original, "Original", "Original"},
            {Mode::Fps30, "Fps30", "30 FPS"},
            {Mode::Fps40, "Fps40", "40 FPS"},
            {Mode::Fps60, "Fps60", "60 FPS"},
            {Mode::Fps120, "Fps120", "120 FPS (Experimental)"},
            {Mode::Fps175, "Fps175", "175 FPS (Experimental)"},
            {Mode::Fps240, "Fps240", "240 FPS (Experimental)"},
            {Mode::Uncapped, "Unlocked", "Uncapped (Experimental)"},
        },
        Mode::Fps60);
}
