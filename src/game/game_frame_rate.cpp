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
#include <string>
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
#include "tooie_gfx_budget.h"
#include "tooie_hooks.h"
#include "tooie_host_profiler.h"
#include "ultramodern/config.hpp"
#include "ultramodern/ultramodern.hpp"

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif

namespace RT64 {
    // lib/rt64/src/hle/rt64_vi.h (from lib-patches/rt64.patch).
    void SetFixedFrameRate(uint32_t rate);
    bool WaitForPresentBacklog(uint32_t maxBacklog, uint32_t timeoutMs);
    // rt64-ext/src/hle/rt64_present_queue_ext.h.
    struct PaceStats {
        uint64_t shown = 0, skipped = 0;
        double sleepMs = 0.0, presentCallMs = 0.0, workloadWaitMs = 0.0;
    };
    PaceStats TakePaceStats();
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

    // The game's replay mode (0x80127760, the byte func_800A9CD0 returns): 1 while a Jiggywiggy challenge plays,
    // 2 for the attract demos (func_800A9998). See tooie_replay_substep below.
    constexpr gpr replay_mode_addr = (int32_t)0x80127760;
    constexpr uint8_t replay_jiggy_challenge = 1;

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

    // Every 5 s in a paced mode: where the frames go, to tell a slow game from a slow screen. Game frames a
    // second, the presents shown and skipped, and the milliseconds a second each side spent waiting: the game for
    // the screen's backlog and for its own deadline, the present thread asleep to hold the rate, in the
    // present call and for the renderer to finish a frame.
    void log_pace(std::chrono::steady_clock::time_point start, std::chrono::steady_clock::time_point backlog_done,
        std::chrono::steady_clock::time_point end, int32_t rate) {
        using clock = std::chrono::steady_clock;
        static clock::time_point window_start = clock::now();
        static uint32_t frames = 0;
        static double backlog_ms = 0.0, deadline_ms = 0.0;
        frames++;
        backlog_ms += std::chrono::duration<double, std::milli>(backlog_done - start).count();
        deadline_ms += std::chrono::duration<double, std::milli>(end - backlog_done).count();
        const double seconds = std::chrono::duration<double>(end - window_start).count();
        if (seconds < 5.0) {
            return;
        }
        const RT64::PaceStats screen = RT64::TakePaceStats();
        std::printf("[pace] rate %d: game %.0f fps, presents shown %.0f/s skipped %.0f/s; per second: game waited %.0f ms for the screen backlog and %.0f ms for its deadline; present thread slept %.0f ms, in present %.0f ms, waited for the renderer %.0f ms\n",
            (int)rate, frames / seconds, screen.shown / seconds, screen.skipped / seconds, backlog_ms / seconds, deadline_ms / seconds,
            screen.sleepMs / seconds, screen.presentCallMs / seconds, screen.workloadWaitMs / seconds);
        std::fflush(stdout);
        window_start = end;
        frames = 0;
        backlog_ms = 0.0;
        deadline_ms = 0.0;
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
        const auto pace_start = std::chrono::steady_clock::now();
        wait_for_backlog_yielding(rdram, 2, 100);
        const auto pace_backlog_done = std::chrono::steady_clock::now();
        if (rate > 0) {
            pace_frame(rdram, rate);
        }
        log_pace(pace_start, pace_backlog_done, std::chrono::steady_clock::now(), rate);
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

// Jiggywiggy challenges above 30 FPS (L, 2026-11-03: "run uncapped at uncapped frames").
//
// A challenge's board shows a live render of a recorded run through a level. While the replay mode byte
// (replay_mode_addr) is 1, func_8001608C (the controller read, once per game frame after func_800A7D30 has set
// the frame's time step) takes the next entry of the recording with glrecord_entrypoint_0 (0x800160F0: 6 bytes
// per entry, stick x and y and buttons into controller 1 at 0x80079B40 and the entry's step in VIs at
// 0x50($sp), 2 = 1/30 s) and steps the whole game by it with func_800D8FA0 (0x80016110). One entry per game
// frame held the challenge at 30 updates a second whatever the Game Frame Rate.
//
// Above 30 FPS the recording is sub-stepped instead: each game frame keeps the time step the chosen rate gives it
// (1/60 s, 1/120 s, the real time of the last frame for Uncapped), and an entry is taken only when the game time
// since the last one has reached that entry's step; the frames in between get the same stick and buttons again.
// So the recording plays at its recorded speed (30 entries a second), and so does everything with it. The
// challenge's countdown counts real time (osGetCount in func_80802030_chjiggygamenew) either way. The game's
// physics take more, smaller steps than when the run was recorded, so the run in the picture can drift a little
// from the recording. Attract demos (mode 2), Original and 30 FPS keep the recorded pacing (tooie_demo_frame).
// TOOIE_DEMO_LOG=1 prints, once a second, the entries taken and the game updates in that second.
namespace {
    constexpr gpr controller_addr = (int32_t)0x80079B40;   // controller 1, as func_8001608C's $s0
    constexpr gpr record_state_addr = (int32_t)0x8012D5B0; // glrecord_entrypoint_0's state (0x80130000 - 0x2A50)

    struct ReplaySubstep {
        bool active = false;      // this call of func_8001608C sub-steps (set by tooie_replay_substep)
        bool have_entry = false;
        uint16_t buttons = 0;
        int8_t stick_x = 0;
        int8_t stick_y = 0;
        double entry_seconds = 2.0 / 60.0;
        double into_entry = 0.0;  // game time from the start of the current entry to the start of this frame
        uint32_t frame = UINT32_MAX;   // the game frame (game_frames_stepped) last seen
        // The recording being played (glrecord's state), to start fresh on a new one.
        uint32_t record_buffer = 0;
        int32_t record_index = 0;
        int32_t record_count = -1;
        // TOOIE_DEMO_LOG
        uint32_t entries = 0;
        uint32_t updates = 0;
        uint32_t calls = 0;       // calls of func_8001608C while sub-stepping (1 per update expected)
        std::chrono::steady_clock::time_point log_start = std::chrono::steady_clock::now();
    };
    ReplaySubstep substep;

    bool substep_wanted(uint8_t* rdram) {
        const Mode m = mode();
        return m != Mode::Original && m != Mode::Fps30 && MEM_BU(0, replay_mode_addr) == replay_jiggy_challenge;
    }

    void substep_log(uint8_t* rdram) {
        static const bool log_on = std::getenv("TOOIE_DEMO_LOG") != nullptr;
        if (!log_on) {
            return;
        }
        const auto now = std::chrono::steady_clock::now();
        const double seconds = std::chrono::duration<double>(now - substep.log_start).count();
        if (seconds < 1.0) {
            return;
        }
        // The N64 clock (osGetCount, ultramodern's game clock) against real time: x1.00 unless the speed-up
        // key or Fast Forward Cutscenes has sped the clock up (ultramodern::set_speed_multiplier).
        static double clock_before = -1.0;
        const double clock_now = game_seconds_now();
        const double clock_rate = clock_before >= 0.0 ? (clock_now - clock_before) / seconds : 1.0;
        clock_before = clock_now;
        // The game heap's block count: the heap guard and DEV > Heap check walk the whole list on every
        // allocation and every game update, so a heap that keeps growing slows each update down.
        uint32_t heap_blocks = 0;
        {
            const uint32_t heap_start = (uint32_t)MEM_W(0, (gpr)(int32_t)0x8007E990);
            const uint32_t heap_end = heap_start + (uint32_t)MEM_W(0, (gpr)(int32_t)0x8007BF00);
            uint32_t block = heap_start;
            while (heap_blocks < 200000 && block >= heap_start && block < heap_end && heap_start >= 0x80000000u && heap_end <= 0x81000000u) {
                heap_blocks++;
                const uint32_t next = (uint32_t)MEM_W(4, (gpr)(int32_t)block);
                if (next <= block) {
                    break;
                }
                block = next;
            }
        }
        // glrecord's state: the entry the recording is at, of how many.
        std::printf("[demo] challenge sub-stepped: %.1f entries/s (recorded pace 30), %.1f game updates/s, %.1f ms into the current entry, "
            "N64 clock x%.2f (speed multiplier %u), %.2f controller reads per update, recording entry %d of %d, heap %u blocks, replay bytes %02X %02X %02X %02X %02X\n",
            substep.entries / seconds, substep.updates / seconds, substep.into_entry * 1000.0, clock_rate,
            (unsigned)ultramodern::get_speed_multiplier(), substep.updates > 0 ? (double)substep.calls / substep.updates : 0.0,
            (int)MEM_W(0x8, record_state_addr), (int)MEM_W(0xC, record_state_addr),
            heap_blocks, MEM_BU(0, replay_mode_addr), MEM_BU(1, replay_mode_addr), MEM_BU(2, replay_mode_addr),
            MEM_BU(3, replay_mode_addr), MEM_BU(4, replay_mode_addr));
        std::fflush(stdout);
        substep.entries = 0;
        substep.updates = 0;
        substep.calls = 0;
        substep.log_start = now;
    }
}

// func_8001608C before it calls glrecord_entrypoint_0 (0x800160F0), only reached while a replay plays. Returns 1
// when this frame repeats the current entry: the hook then skips the call, the step and the end check
// (goto L_80016118). Returns 0 to let the game take the next entry.
extern "C" int tooie_replay_substep(uint8_t* rdram, recomp_context* ctx) {
    (void)ctx;
    substep.active = substep_wanted(rdram);
    if (!substep.active) {
        substep.have_entry = false;
        substep.into_entry = 0.0;
        substep.frame = UINT32_MAX;
        return 0;
    }
    substep.calls++;
    // A new recording (another challenge, or one started again after the last was left by a warp) starts fresh:
    // glrecord's state at 0x8012D5B0 is the buffer, +8 the next entry and +0xC the entry count.
    const uint32_t record_buffer = (uint32_t)MEM_W(0x0, record_state_addr);
    const int32_t record_index = (int32_t)MEM_W(0x8, record_state_addr);
    const int32_t record_count = (int32_t)MEM_W(0xC, record_state_addr);
    if (record_buffer != substep.record_buffer || record_count != substep.record_count || record_index < substep.record_index) {
        substep.have_entry = false;
        substep.into_entry = 0.0;
        substep.frame = UINT32_MAX;
        substep.record_buffer = record_buffer;
        substep.record_count = record_count;
    }
    substep.record_index = record_index;
    const uint32_t frame = game_frames_stepped.load();
    const bool new_frame = frame != substep.frame;
    bool repeat;
    if (!substep.have_entry) {
        repeat = false;
        substep.into_entry = 0.0;
    } else if (!new_frame) {
        // func_8001608C again in the same game frame: the same input as its first call.
        repeat = true;
    } else if (substep.into_entry + 1e-6 < substep.entry_seconds) {
        repeat = true;
    } else {
        // The next entry starts. A frame that came late (more than an entry behind) doesn't run the recording
        // ahead several entries at once: the debt is capped at one entry.
        repeat = false;
        substep.into_entry = std::clamp(substep.into_entry - substep.entry_seconds, 0.0, substep.entry_seconds);
    }
    if (new_frame) {
        substep.frame = frame;
        substep.updates++;
        // This frame's step, set by func_800A7D30 (and the paced modes' hooks) before func_8001608C runs.
        const float delta = read_float(rdram, delta_time_addr);
        substep.into_entry += (delta > 0.0f && delta < 0.5f) ? delta : 1.0 / 60.0;
    }
    if (repeat) {
        MEM_H(0x0, controller_addr) = (int16_t)substep.buttons;
        MEM_B(0x2, controller_addr) = substep.stick_x;
        MEM_B(0x3, controller_addr) = substep.stick_y;
        substep_log(rdram);
        return 1;
    }
    return 0;
}

// func_8001608C, as the game replays a frame's recorded time step: attract
// demos, the game select screen and the intro story cutscenes (seen headless).
// These run a fixed number of frames, so the game keeps its own pacing while
// one plays (at 60 FPS it would otherwise run twice as fast).
// $a0 is loaded in the delay slot, so the step is still at 0x50($sp).
// A Jiggywiggy challenge sub-stepped above 30 FPS (tooie_replay_substep) keeps the entry taken for the frames
// after it and returns 1: the hook then skips func_800D8FA0, so the frame keeps the chosen rate's step.
extern "C" int tooie_demo_frame(uint8_t* rdram, recomp_context* ctx) {
    static const bool log_steps = std::getenv("TOOIE_DEMO_LOG") != nullptr;
    const int32_t step = (int32_t)MEM_W(0x50, ctx->r29);
    if (substep.active) {
        substep.have_entry = true;
        substep.buttons = (uint16_t)MEM_HU(0x0, controller_addr);
        substep.stick_x = (int8_t)MEM_B(0x2, controller_addr);
        substep.stick_y = (int8_t)MEM_B(0x3, controller_addr);
        substep.entry_seconds = std::clamp(step, (int32_t)1, (int32_t)15) / 60.0;
        substep.entries++;
        substep_log(rdram);
        return 1;
    }
    demo_frames = 2;
    demo_step = step;
    if (log_steps) {
        std::printf("[demo] step %d\n", (int)demo_step.load());
        std::fflush(stdout);
    }
    return 0;
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
    StepGate vertex_flicker_gate;
    StepGate flame_flipbook_gate;
    StepGate fire_count_gate;
    StepGate fire_spawn_gate;
    StepGate light_effect_gate;
}

// Talking-head portraits (the zoombox overlay): func_8080156C_gczoombox moves a
// portrait's mouth (+0x1CF, following the mouth pattern at +0xF0 indexed by
// +0x1D0) and its blink one step per game frame ($a0 = the box).
extern "C" int tooie_portrait_step_skip(uint8_t* rdram, recomp_context* ctx) {
    return portrait_gate.skip(rdram, (uint32_t)ctx->r4) ? 1 : 0;
}

// Gravity. The game's physics (func_8009AE08 and the two copies at 0x8009B168 and 0x8009B1F8)
// adds gravity x frame time to the vertical speed, then moves the object by that new speed x
// frame time. That makes a fall or jump trace the true parabola minus gravity x step / 2 for
// each second gone by, so a 30 FPS jump peaks lower than one at a smaller step (Banjo's
// standing jump: +139 units at 30 FPS, +148 at 60 to 175). Above 30 FPS this takes the
// difference to a 1/30 s step off each frame's move, so jumps and falls match 30 FPS.
// The move is the vector at +0x28 of the physics block, its vertical part at +0x2C; gravity
// (negative) is at +0x34.
extern "C" void tooie_gravity_bias(uint8_t* rdram, recomp_context* ctx, uint32_t physics_owner) {
    static const bool off = std::getenv("TOOIE_NO_GRAVITY_BIAS") != nullptr;   // A/B for tests
    if (off || !above_30()) {
        return;
    }
    const uint32_t physics = (uint32_t)MEM_W(0xC8, (int32_t)physics_owner);
    const float dt = read_float(rdram, delta_time_addr);
    constexpr float step = 1.0f / 30.0f;
    if (physics < 0x80000000u || dt <= 0.0f || dt >= step) {
        return;
    }
    const float gravity = read_float(rdram, (int32_t)(physics + 0x34));
    float move = read_float(rdram, (int32_t)(physics + 0x2C));
    move += gravity * (step - dt) * 0.5f * dt;
    uint32_t bits;
    std::memcpy(&bits, &move, sizeof(bits));
    MEM_W(0x2C, (int32_t)physics) = (int32_t)bits;
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

// baswim_entrypoint_11, steering under water (Banjo and Kazooie, and Banjo alone): it turns
// the stick's left/right into a turn and adds it to Banjo's target heading once per game frame,
// with no delta time. The heading then follows the target at up to 250 degrees a second, so
// above 60 FPS the target ran ahead of him while the stick was held and he kept turning after
// it was let go (L: swimming over 60 FPS hard to control, 2026-10-17). $f8 holds the turn, just
// before it is scaled by the first-person zoom. Above 60 FPS it is scaled to the frame's time,
// so the turn per second is the same as at 60. 60 FPS and below are unchanged.
extern "C" void tooie_swim_turn(uint8_t* rdram, recomp_context* ctx) {
    static const bool off = std::getenv("TOOIE_NO_SWIM_TURN_FIX") != nullptr;   // A/B for tests
    const float dt = read_float(rdram, delta_time_addr);
    const float turn = ctx->f8.fl;
    if (!off && mode() != Mode::Original && dt > 0.0f && dt < 1.0f / 60.0f) {
        ctx->f8.fl *= dt * 60.0f;
    }
    // TOOIE_SWIM_LOG=1: each frame, game time, the step, the turn before and after, and
    // Banjo's heading and target heading (PlayerState $s0, +0xF8 points at the yaw block).
    static const bool log = std::getenv("TOOIE_SWIM_LOG") != nullptr;
    if (log) {
        const uint32_t yaw = (uint32_t)MEM_W(0xF8, ctx->r16);
        const float value = yaw >= 0x80000000u ? read_float(rdram, (int32_t)yaw) : 0.0f;
        const float ideal = yaw >= 0x80000000u ? read_float(rdram, (int32_t)(yaw + 4)) : 0.0f;
        std::printf("[swim] t %.3f dt %.4f turn %.3f -> %.3f yaw %.2f ideal %.2f\n",
            game_seconds_total.load(), dt, turn, ctx->f8.fl, value, ideal);
        std::fflush(stdout);
    }
}

// bafly_entrypoint_9, steering in flight: it turns the stick's left/right into a turn of up to 3
// degrees (6 with the sharp-turn key) and adds it to Banjo's target heading once per game frame,
// with no delta time. The heading follows the target at up to 500 degrees a second, so the turn
// grew with the frame rate: 90 degrees a second at 30, 360 at 120, and at 175 and up the target
// ran ahead of him and he kept turning after the stick was let go (L: flying at 120-175 FPS too
// fast, 2026-10-19). $f16 holds the turn, just before it is added. Above 30 FPS it is scaled to
// the frame's time, so it turns as in the original game at every rate (L chose 30, 2026-10-20).
extern "C" void tooie_fly_turn(uint8_t* rdram, recomp_context* ctx) {
    static const bool off = std::getenv("TOOIE_NO_FLY_TURN_FIX") != nullptr;   // A/B for tests
    const float dt = read_float(rdram, delta_time_addr);
    const float turn = ctx->f16.fl;
    if (!off && above_30() && dt > 0.0f && dt < 1.0f / 30.0f) {
        ctx->f16.fl *= dt * 30.0f;
    }
    // TOOIE_FLY_LOG=1: each frame, game time, the step, the turn before and after, and
    // Banjo's heading and target heading (PlayerState $s0, +0xF8 points at the yaw block).
    static const bool log = std::getenv("TOOIE_FLY_LOG") != nullptr;
    if (log) {
        const uint32_t yaw = (uint32_t)MEM_W(0xF8, ctx->r16);
        const float value = yaw >= 0x80000000u ? read_float(rdram, (int32_t)yaw) : 0.0f;
        const float ideal = yaw >= 0x80000000u ? read_float(rdram, (int32_t)(yaw + 4)) : 0.0f;
        std::printf("[fly] t %.3f dt %.4f turn %.3f -> %.3f yaw %.2f ideal %.2f\n",
            game_seconds_total.load(), dt, turn, ctx->f16.fl, value, ideal);
        std::fflush(stdout);
    }
}

// The first-person shooter (the bsfirstp overlay, e.g. Targitzan's Temple lobby). At Unlocked it
// turned too fast (565 degrees for 2 s of full stick, 344 at 30 FPS) and its view bob ran about 20
// times too fast, which looked like the view shaking (L, 2026-11-03). TOOIE_NO_SHOOTER_FIX=1 turns all three fixes below off,
// for A/B tests, and TOOIE_SHOOTER_LOG=1 prints what each one changes every frame.
namespace {
    bool shooter_fix_on() {
        static const bool off = std::getenv("TOOIE_NO_SHOOTER_FIX") != nullptr;
        return !off && above_30();
    }

    bool shooter_log() {
        static const bool log = std::getenv("TOOIE_SHOOTER_LOG") != nullptr;
        return log;
    }
}

// func_80809AF8_bsfirstp (the turn) and func_80806AD0_bsfirstp (the same for the other stick
// axis) move a speed toward the stick's speed and give how far it went, in two steps: a fixed
// step ($f12, 1/30 s) and then the rest of the frame's time ($f0 minus $f12), skipped when that
// is 0. Above 30 FPS the frame is shorter than the fixed step, so every frame still moved a full
// 1/30 s first, and the second step was given a time below 0. Here, before $f12 is taken away from $f0 and
// given as the first step's time, a frame shorter than the step uses its own time for the first
// step, which leaves nothing for the second. At 30 FPS and below nothing changes.
extern "C" void tooie_shooter_turn_step(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    const float dt = ctx->f0.fl;
    const float step = ctx->f12.fl;
    if (shooter_fix_on() && dt > 0.0f && dt < step) {
        ctx->f12.fl = dt;
    }
    if (shooter_log()) {
        std::printf("[shooter] t %.3f turn step dt %.4f step %.4f -> %.4f\n",
            game_seconds_total.load(), dt, step, ctx->f12.fl);
        std::fflush(stdout);
    }
}

// func_808006DC_bsfirstp, the view bob while walking: it adds 12.5 and 25 degrees, times how fast
// Banjo walks, to the two bob angles (+0x54 and +0x5C of the shooter's block) once per game frame,
// with no delta time. The degrees are in $f8 (which = 0) and $f6 (which = 1) just before they are
// multiplied by the walk speed; above 30 FPS they are scaled to the frame's time.
extern "C" void tooie_shooter_bob_step(uint8_t* rdram, recomp_context* ctx, int which) {
    const float dt = read_float(rdram, delta_time_addr);
    float& degrees = which == 0 ? ctx->f8.fl : ctx->f6.fl;
    const float before = degrees;
    if (shooter_fix_on() && dt > 0.0f && dt < 1.0f / 30.0f) {
        degrees *= dt * 30.0f;
    }
    if (shooter_log()) {
        std::printf("[shooter] t %.3f bob %d dt %.4f degrees %.3f -> %.3f\n",
            game_seconds_total.load(), which, dt, before, degrees);
        std::fflush(stdout);
    }
}

// func_8080056C_bsfirstp works out Banjo's speed from how far he moved this frame and moves the
// kept speed (+0x38 and +0x40, $f12) and another kept value (+0x4C, $f4) a fixed part of the way
// to the new one once per game frame. The walk speed it gives drives the view bob. Above 30 FPS
// the part is made the one that covers the same ground in 1/30 s: 1 - (1 - part) ^ (dt x 30).
extern "C" void tooie_shooter_follow(uint8_t* rdram, recomp_context* ctx, int which) {
    const float dt = read_float(rdram, delta_time_addr);
    float& part = which == 0 ? ctx->f12.fl : ctx->f4.fl;
    const float before = part;
    if (shooter_fix_on() && dt > 0.0f && dt < 1.0f / 30.0f && part > 0.0f && part < 1.0f) {
        part = 1.0f - std::pow(1.0f - part, dt * 30.0f);
    }
    if (shooter_log()) {
        std::printf("[shooter] t %.3f follow %d dt %.4f part %.4f -> %.4f\n",
            game_seconds_total.load(), which, dt, before, part);
        std::fflush(stdout);
    }
}

// Sput Sput (func_80800364_chstonedartgunhead, the stone dart head in Targitzan's Temple) turns with
// func_80102B2C(actor, 4): its yaw (+0x48) moves up to 4 whole degrees toward the target yaw (+0x54)
// once per game frame, or snaps to the target when the gap is 50 degrees or more and the actor asks for
// that. When it is shot, the target is kept 4 degrees ahead of the yaw, so it spins at 4 degrees a game
// frame: 120 a second at 30 FPS, and several times that above 30 FPS (L, 2026-11-12). The turn toward
// Banjo used the same step. tooie_sput_turn_before keeps the yaw before each of its two turn calls, and
// tooie_sput_turn_after puts the turn back to the frame's share of 4 degrees per 1/30 s, as a float so
// short frames still turn. A snap is left alone. TOOIE_NO_SPUT_FIX=1 turns it off for A/B tests.
namespace {
    float sput_yaw_before = 0.0f;
    gpr sput_actor = 0;

    float wrap_degrees_180(float d) {
        d = std::fmod(d, 360.0f);
        if (d > 180.0f) d -= 360.0f;
        if (d < -180.0f) d += 360.0f;
        return d;
    }
}

extern "C" void tooie_sput_turn_before(uint8_t* rdram, recomp_context* ctx) {
    sput_actor = ctx->r16;
    sput_yaw_before = read_float(rdram, ctx->r16 + 0x48);
}

extern "C" void tooie_sput_turn_after(uint8_t* rdram, recomp_context* ctx) {
    static const bool off = std::getenv("TOOIE_NO_SPUT_FIX") != nullptr;
    const float dt = read_float(rdram, delta_time_addr);
    if (off || ctx->r16 != sput_actor || !above_30() || !(dt > 0.0f && dt < 1.0f / 30.0f)) {
        return;
    }
    const float before = sput_yaw_before;
    const float after = read_float(rdram, ctx->r16 + 0x48);
    const float target = read_float(rdram, ctx->r16 + 0x54);
    constexpr float step = 4.0f;
    // The game's turn moved more than its step: it snapped to the target.
    if (std::fabs(wrap_degrees_180(after - before)) > step + 0.01f) {
        return;
    }
    const float limit = step * dt * 30.0f;
    const float turn = std::clamp(wrap_degrees_180(target - before), -limit, limit);
    float yaw = std::fmod(before + turn, 360.0f);
    if (yaw < 0.0f) yaw += 360.0f;
    write_float(rdram, ctx->r16 + 0x48, yaw);
}

// While Sput Sput is lined up on Banjo (within 15 degrees of its target), it adds 1.0 ($f4) to a count
// (+0x20) once per game frame and fires when the count reaches its limit (+0x1C): 0.2 s after it lines up at
// 30 FPS (measured in Targitzan's Temple). Above 30 FPS the count filled in
// far less time, so it fired before it had finished turning toward Banjo. The 1.0 becomes the frame's
// share of 1/30 s.
extern "C" void tooie_sput_aim_count(uint8_t* rdram, recomp_context* ctx) {
    static const bool off = std::getenv("TOOIE_NO_SPUT_FIX") != nullptr;
    const float dt = read_float(rdram, delta_time_addr);
    if (!off && above_30() && dt > 0.0f && dt < 1.0f / 30.0f) {
        ctx->f4.fl = dt * 30.0f;
    }
}

// Character blinking: func_80101A50 runs an object's blink ($a0, state in the
// bits of +0x78 and +0x7A): each frame a random chance to start a blink, then
// the eyelid frame goes 0 to 3 and back one step a frame. It ends by giving the
// eyelid frame to the model's texture slots 1 and 2 (func_800DF744); a skipped
// frame jumps there, so the eyes still show.
extern "C" int tooie_blink_step_skip(uint8_t* rdram, recomp_context* ctx) {
    return blink_gate.skip(rdram, (uint32_t)ctx->r4) ? 1 : 0;
}

// Talking mouths (the suexpress overlays, which about 50 characters share: Bottles, Jamjars, Mumbo and
// the rest). While a character speaks, the dialogue gives a mouth shape for each letter
// (func_800D52A4, 0x8012B430) and the speaker's id (func_800D52F4); each game frame the character's
// expression moves its face toward that shape. Both ways of doing it step once per game frame with no
// frame time, so above 30 FPS mouths snapped from shape to shape many times faster than at 30 FPS
// (L, 2026-11-10: "facial animations on every NPC run too fast", and should be smooth, not 30 FPS).
//
// - suexpressjoint_entrypoint_3 ($a3 = the expression): a talk weight (the byte at +0x8, 0 to 100)
//   steps toward 100 by max((100 - w) x K, 2) while the character speaks and falls by w x K otherwise;
//   then each pose channel (bytes from +0x20) moves a fixed part K of the way to the shape's value.
//   Both are whole numbers that lose their fraction each frame, and the channels give the pose
//   weights (floats from +0xC) that bend the jaw.
// - func_808000EC_suexpressmorph: each morph weight moves a part K (in $f20) of the way to its target.
//
// Above 30 FPS the morph's part K becomes 1 - (1 - K)^share for this frame's share of 1/30 s. The
// joint's values are kept here as floats for each byte's address: each frame works out where one 30
// FPS step would take the value, cut-off included, and moves this frame's share of the way there, so
// it keeps the 30 FPS pace. The pose weights are made from the float, so the jaw moves a little every
// frame instead of in whole steps. A kept float is dropped when its byte no longer matches it (the game set the byte
// itself). TOOIE_NO_MOUTH_FIX=1 turns this off for A/B tests. 30 FPS and Original are unchanged.
namespace {
    std::mutex mouth_mutex;
    std::unordered_map<uint32_t, float> mouth_values;

    bool mouth_fix_on() {
        static const bool off = std::getenv("TOOIE_NO_MOUTH_FIX") != nullptr;
        if (off || !above_30()) {
            std::lock_guard lock{ mouth_mutex };
            mouth_values.clear();
            return false;
        }
        return true;
    }

    // This frame's share of a 1/30 s game frame, 0 while paused.
    float mouth_share(uint8_t* rdram) {
        const float dt = read_float(rdram, delta_time_addr);
        return std::clamp(dt * 30.0f, 0.0f, 1.0f);
    }

    // The kept float for the byte at this address, or the byte itself when the two no longer match.
    float& mouth_value(uint32_t address, uint8_t byte) {
        if (mouth_values.size() > 4096) {
            mouth_values.clear();
        }
        auto [it, added] = mouth_values.try_emplace(address, (float)byte);
        if (!added && (uint8_t)std::trunc(it->second) != byte) {
            it->second = (float)byte;
        }
        return it->second;
    }

    // TOOIE_MOUTH_LOG=1: every 2 s of real time, for each kind of mouth value (0 talk weight while
    // talking, 1 talk weight while not, 2 pose channel weights, 3 morph weights), how many times a
    // second of game time the hooks ran, how far the values moved per second of game time and on how
    // many frames they moved, fix on or off.
    void mouth_log(uint8_t* rdram, int kind, uint32_t key, float value) {
        (void)rdram;
        static const bool log = std::getenv("TOOIE_MOUTH_LOG") != nullptr;
        if (!log) {
            return;
        }
        struct Kind { double moved = 0.0; uint32_t calls = 0, moving_frames = 0, last_frame = 0; };
        static std::mutex log_mutex;
        static std::unordered_map<uint32_t, float> last;
        static Kind kinds[4];
        static double game_start = game_seconds_total.load();
        static auto shown = std::chrono::steady_clock::now();
        std::lock_guard lock{ log_mutex };
        Kind& k = kinds[kind & 3];
        k.calls++;
        auto [it, added] = last.try_emplace(key ^ ((uint32_t)kind << 28), value);
        const float step = std::fabs(value - it->second);
        it->second = value;
        if (!added && step > 0.0f) {
            k.moved += step;
            if (k.last_frame != game_frames_stepped.load()) {
                k.last_frame = game_frames_stepped.load();
                k.moving_frames++;
            }
        }
        const auto now = std::chrono::steady_clock::now();
        if (now - shown < std::chrono::seconds(2)) {
            return;
        }
        const double game = game_seconds_total.load() - game_start;
        for (int i = 0; i < 4 && game > 0.0; i++) {
            if (kinds[i].calls > 0) {
                std::printf("[mouth] kind %d: %.0f calls/s, %.2f moved per s, moving on %.1f frames per s\n",
                    i, kinds[i].calls / game, kinds[i].moved / game, kinds[i].moving_frames / game);
            }
            kinds[i] = Kind{};
        }
        std::fflush(stdout);
        game_start = game_seconds_total.load();
        shown = now;
    }
}

// Before 0x8080034C: $f0 = the step toward 100 (at least 2), $v0 = the talk weight byte, $a3 = the
// expression. The game then moves the byte toward 100 by $f0 and cuts off the fraction, so $f0 is made
// the distance from the byte to the kept weight after this frame's share of the step.
extern "C" void tooie_mouth_open_step(uint8_t* rdram, recomp_context* ctx) {
    const uint8_t byte = (uint8_t)ctx->r2;
    if (mouth_fix_on()) {
        std::lock_guard lock{ mouth_mutex };
        float& weight = mouth_value((uint32_t)ctx->r7 + 0x8, byte);
        weight += (std::trunc(std::min(weight + ctx->f0.fl, 100.0f)) - weight) * mouth_share(rdram);
        ctx->f0.fl = std::max(weight - (float)byte, 0.0f);
    }
    mouth_log(rdram, 0, (uint32_t)ctx->r7 + 0x8, std::min((float)byte + ctx->f0.fl, 100.0f));
}

// Before 0x80800448: $f0 = the talk weight byte as a float, $f8 = the part it falls by, $f10 = $f0 x $f8,
// $a3 = the expression. The game keeps $f0 - $f10, so $f10 is made what takes it to the kept weight.
extern "C" void tooie_mouth_close_step(uint8_t* rdram, recomp_context* ctx) {
    if (mouth_fix_on()) {
        const uint8_t byte = (uint8_t)std::trunc(ctx->f0.fl);
        std::lock_guard lock{ mouth_mutex };
        float& weight = mouth_value((uint32_t)ctx->r7 + 0x8, byte);
        weight += (std::trunc(weight - weight * ctx->f8.fl) - weight) * mouth_share(rdram);
        ctx->f10.fl = ctx->f0.fl - weight;
    }
    mouth_log(rdram, 1, (uint32_t)ctx->r7 + 0x8, ctx->f0.fl - ctx->f10.fl);
}

// Before 0x8080056C: $f0 = a pose channel's byte as a float, $f6 = the shape's value for it, $f2 = the
// part of the way it moves, $f8 = ($f6 - $f0) x $f2, $t0 = the byte. The game keeps $f0 + $f8.
extern "C" void tooie_mouth_channel_step(uint8_t* rdram, recomp_context* ctx) {
    if (!mouth_fix_on()) {
        return;
    }
    const uint8_t byte = (uint8_t)std::trunc(ctx->f0.fl);
    std::lock_guard lock{ mouth_mutex };
    float& value = mouth_value((uint32_t)ctx->r8, byte);
    value += (std::trunc(value + (ctx->f6.fl - value) * ctx->f2.fl) - value) * mouth_share(rdram);
    ctx->f8.fl = value - ctx->f0.fl;
}

// Before 0x80800610: $f10 = the channel's new byte as a float, about to become its pose weight; $t0 =
// the byte. The kept float is used instead, so the weight changes smoothly.
extern "C" void tooie_mouth_channel_weight(uint8_t* rdram, recomp_context* ctx) {
    if (mouth_fix_on()) {
        std::lock_guard lock{ mouth_mutex };
        auto it = mouth_values.find((uint32_t)ctx->r8);
        if (it != mouth_values.end() && (uint8_t)std::trunc(it->second) == (uint8_t)std::trunc(ctx->f10.fl)) {
            ctx->f10.fl = it->second;
        }
    }
    mouth_log(rdram, 2, (uint32_t)ctx->r8, ctx->f10.fl);
}

// Before 0x80800180 in func_808000EC_suexpressmorph: $f20 = the part of the way each morph weight moves.
extern "C" void tooie_morph_follow(uint8_t* rdram, recomp_context* ctx) {
    const float part = ctx->f20.fl;
    if (mouth_fix_on() && part > 0.0f && part < 1.0f) {
        ctx->f20.fl = 1.0f - std::pow(1.0f - part, mouth_share(rdram));
    }
    // The weights as they were before this frame's move ($s0 = the first one; the log only).
    for (int i = 0; i < 4; i++) {
        mouth_log(rdram, 3, (uint32_t)ctx->r16 + 4 * i, read_float(rdram, (int32_t)((uint32_t)ctx->r16 + 4 * i)));
    }
}

// A factor the game applies once per game frame with no frame time: a multiplier (speed *= 0.98) when
// kind is 0, or the part of the way something eases to its target (x += (target - x) * 0.05) when kind
// is 1. Above 30 FPS it is made the one that does the same in this frame's share of 1/30 s:
// factor^share, or 1 - (1 - part)^share. 30 FPS and Original are unchanged.
extern "C" void tooie_frame_factor(uint8_t* rdram, float* factor, int kind) {
    static const bool off = std::getenv("TOOIE_NO_FRAME_FACTOR_FIX") != nullptr;   // A/B for tests
    if (off || !above_30() || !(*factor > 0.0f) || *factor >= 1.0f) {
        return;
    }
    const float share = std::clamp(read_float(rdram, delta_time_addr) * 30.0f, 0.0f, 1.0f);
    *factor = kind == 0 ? std::pow(*factor, share) : 1.0f - std::pow(1.0f - *factor, share);
}

// Characters turning their heads to look at Banjo (the suexpression overlay, shared by most
// characters). suexpression_entrypoint_15 ($a3 = the expression) moves the head's turn (s16 at +0x4,
// limit at +0x6) and tilt (s16 at +0x8, limit at +0xA) a fixed part of the way toward Banjo once per
// game frame, and back toward 0 by a fixed factor when he is out of reach; suexpression_entrypoint_16
// ($a0) lets both go back the same way. All of it with no frame time, on whole numbers that lose their
// fraction each frame, so above 30 FPS heads stalled and then snapped round. Above 30 FPS each frame
// works out where one 30 FPS step would take the angle, cut-off included, and moves this frame's share
// of 1/30 s of the way there. The angles are kept as floats here so they turn smoothly at the 30 FPS
// pace; the game's whole number is what the float cuts down to. which: 0 and 1 the turn toward
// Banjo (before the trunc at 0x8080085C, 0x808008BC), 2 and 3 the tilt (0x8080097C, 0x808009D4),
// 4 the tilt going back (0x80800A3C), 5 both going back (0x80800ABC), 6 entrypoint_16 (0x80800B18).
// TOOIE_NO_LOOK_FIX=1 turns it off for A/B tests.
namespace {
    std::mutex look_mutex;
    std::unordered_map<uint32_t, float> look_values;

    float& look_value(uint32_t address, float whole) {
        if (look_values.size() > 4096) {
            look_values.clear();
        }
        auto [it, added] = look_values.try_emplace(address, whole);
        if (!added && std::trunc(it->second) != whole) {
            it->second = whole;
        }
        return it->second;
    }
}

extern "C" void tooie_look_step(uint8_t* rdram, recomp_context* ctx, int which) {
    // TOOIE_LOOK_LOG=1: each head's turn and tilt as the game left them last frame, about every 1/30 s
    // of game time, fix on or off.
    static const bool log = std::getenv("TOOIE_LOOK_LOG") != nullptr;
    if (log && which != 6) {
        static std::unordered_map<uint32_t, double> last_shown;
        const uint32_t a3 = (uint32_t)ctx->r7;
        const double now = game_seconds_total.load();
        double& shown = last_shown[a3];
        if (now - shown >= 1.0 / 30.0 - 0.0005 || now < shown) {
            shown = now;
            std::printf("[look] t %.3f %08X turn %d tilt %d\n", now, a3,
                (int)(int16_t)MEM_H(0x4, (gpr)(int32_t)a3), (int)(int16_t)MEM_H(0x8, (gpr)(int32_t)a3));
        }
    }
    static const bool off = std::getenv("TOOIE_NO_LOOK_FIX") != nullptr;
    if (off || !above_30()) {
        std::lock_guard lock{ look_mutex };
        look_values.clear();
        return;
    }
    const float share = std::clamp(read_float(rdram, delta_time_addr) * 30.0f, 0.0f, 1.0f);
    // Where one 30 FPS step would take the angle, cut-off included, and this frame's share of the way
    // there: at 1/30 s it is the game's own step, and between it the angle moves smoothly.
    auto toward = [share](float& v, float step_result) {
        v += (std::trunc(step_result) - v) * share;
        return v;
    };
    const uint32_t a3 = (uint32_t)ctx->r7;
    std::lock_guard lock{ look_mutex };
    switch (which) {
        case 0: {   // turn += (target - turn) * K; $f2 = turn, $f8 = the way to go, $f10 = K, keeps $f18
            float& v = look_value(a3 + 0x4, ctx->f2.fl);
            ctx->f18.fl = toward(v, v + (ctx->f8.fl - (v - ctx->f2.fl)) * ctx->f10.fl);
            break;
        }
        case 1: {   // turn -= (turn - target) * K; $f10 = the way back, $f16 = K, keeps $f4
            float& v = look_value(a3 + 0x4, ctx->f2.fl);
            ctx->f4.fl = toward(v, v - (ctx->f10.fl + (v - ctx->f2.fl)) * ctx->f16.fl);
            break;
        }
        case 2: {   // tilt toward Banjo; $f4 = the way to go, $f6 = K, keeps $f10
            float& v = look_value(a3 + 0x8, ctx->f2.fl);
            ctx->f10.fl = toward(v, v + (ctx->f4.fl - (v - ctx->f2.fl)) * ctx->f6.fl);
            break;
        }
        case 3: {   // tilt back toward Banjo; $f4 = the way back, $f6 = K, keeps $f10
            float& v = look_value(a3 + 0x8, ctx->f2.fl);
            ctx->f10.fl = toward(v, v - (ctx->f4.fl + (v - ctx->f2.fl)) * ctx->f6.fl);
            break;
        }
        case 4: {   // tilt going back to 0: $f18 = tilt, $f2 = K, keeps $f4
            float& v = look_value(a3 + 0x8, ctx->f18.fl);
            ctx->f4.fl = toward(v, v * ctx->f2.fl);
            break;
        }
        case 5: {   // both going back to 0: $f10 = turn, $f18 = tilt, $f2 = K, keeps $f16 and $f8
            float& turn = look_value(a3 + 0x4, ctx->f10.fl);
            float& tilt = look_value(a3 + 0x8, ctx->f18.fl);
            ctx->f16.fl = toward(turn, turn * ctx->f2.fl);
            ctx->f8.fl = toward(tilt, tilt * ctx->f2.fl);
            break;
        }
        case 6: {   // entrypoint_16 ($a0): $f6 = turn, $f18 = tilt, $f0 = K, keeps $f8 and $f4
            const uint32_t a0 = (uint32_t)ctx->r4;
            float& turn = look_value(a0 + 0x4, ctx->f6.fl);
            float& tilt = look_value(a0 + 0x8, ctx->f18.fl);
            ctx->f8.fl = toward(turn, turn * ctx->f0.fl);
            ctx->f4.fl = toward(tilt, tilt * ctx->f0.fl);
            break;
        }
        default:
            break;
    }
}

// A move's root motion (batranslate_entrypoint_4, $a0 = the PlayerState) waits 2 game frames (the byte at
// +0x0 of the PlayerState's +0x140 block) before it starts: the Talon Torpedo and Banjo pulling himself up
// a ledge. Counted in game frames, so above 30 FPS the wait was a few milliseconds instead of 1/15 s. Above
// 30 FPS it counts down once per 1/30 s of game time (StepGate). TOOIE_NO_STEP_FIX=1 turns it off for A/B
// tests, and TOOIE_STEP_LOG=1 prints each count with the game time.
// (Checked and left alone, 2026-11-10: bsledge's scuffle-sound countdown is called at two points of the
// ledge shimmy animation, so it counts animation steps, not frames; anseq's frame wait is only ever 1, used
// by the intro's characters, which runs on the next call at any frame rate.)
namespace {
    StepGate translate_wait_gate;
}

// Before 0x80800190: $v0 = the root motion block, $v1 = its wait (not 0). 1 skips this frame's count.
extern "C" int tooie_translate_wait_skip(uint8_t* rdram, recomp_context* ctx) {
    static const bool off = std::getenv("TOOIE_NO_STEP_FIX") != nullptr;
    const bool skip = !off && translate_wait_gate.skip(rdram, (uint32_t)ctx->r4);
    static const bool log = std::getenv("TOOIE_STEP_LOG") != nullptr;
    if (log) {
        std::printf("[steps] t %.4f root motion wait %u%s\n", game_seconds_total.load(), (unsigned)(uint8_t)ctx->r3,
            skip ? " (held)" : "");
        std::fflush(stdout);
    }
    return skip ? 1 : 0;
}

// TOOIE_FACE_LOG=1: a log of the model texture slots (func_800DF744, $a0 = the slot, $a1 = the
// picture), which the game sets for eyes, mouths and other face pictures before a model is drawn.
// Every 2 s of real time it prints, for each calling function and slot, how many times the
// picture changed per second of game time, so a face that changes faster above 30 FPS shows up.
// Recompiled code does not set $ra, so the caller is taken from the host stack and named from
// BanjoReTooie.pdb. Windows only.
extern "C" void tooie_face_slot_log(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    static const bool log = std::getenv("TOOIE_FACE_LOG") != nullptr;
    if (!log) {
        return;
    }
#ifdef _WIN32
    void* frames[2] = { nullptr, nullptr };
    if (RtlCaptureStackBackTrace(1, 2, frames, nullptr) < 2) {
        return;
    }
    const uintptr_t caller = (uintptr_t)frames[1];
    struct Entry { uint32_t value = 0xFFFFFFFFu; uint32_t changes = 0; uint32_t calls = 0; };
    static std::mutex mutex;
    static std::unordered_map<uint64_t, Entry> entries;
    static std::unordered_map<uintptr_t, std::string> names;
    static auto last = std::chrono::steady_clock::now();
    static double game_start = game_seconds_total.load();
    static uint32_t frames_start = game_frames_stepped.load();
    std::lock_guard lock{ mutex };
    const uint64_t key = ((uint64_t)caller << 8) | ((uint32_t)ctx->r4 & 0xFF);
    Entry& e = entries[key];
    e.calls++;
    if (e.value != (uint32_t)ctx->r5) {
        e.value = (uint32_t)ctx->r5;
        e.changes++;
    }
    const auto now = std::chrono::steady_clock::now();
    if (now - last < std::chrono::seconds(2)) {
        return;
    }
    const double game = game_seconds_total.load() - game_start;
    const uint32_t frames_now = game_frames_stepped.load() - frames_start;
    std::printf("[face] %.2f s game time, %u game frames, map %X\n", game, frames_now,
        (unsigned)tooie::debug::current_map(rdram));
    for (auto& [k, v] : entries) {
        if (v.changes > 1 && game > 0.0) {
            const uintptr_t at = (uintptr_t)(k >> 8);
            auto found = names.find(at);
            if (found == names.end()) {
                found = names.emplace(at, tooie::host_profiler::function_name(at)).first;
            }
            std::printf("[face]   %s slot %u: %.1f changes/s, %.1f calls/s, now %u\n",
                found->second.c_str(), (uint32_t)(k & 0xFF), v.changes / game, v.calls / game, v.value);
        }
        v.changes = 0;
        v.calls = 0;
    }
    std::fflush(stdout);
    last = now;
    game_start = game_seconds_total.load();
    frames_start = game_frames_stepped.load();
#else
    (void)ctx;
#endif
}

// Fires (the chfirefx actor: the torches in Witchyworld's Haunted Cavern and others). chfirefx_entrypoint_3
// updates a fire's puffs ($s3 = the fire's data, 0x14 a puff from +0x20, $s0 = the puff). A puff's height
// (+0x4), size (+0xA) and sideways place (+0x8, +0xC) are whole numbers: each game frame the game adds its
// move for the frame's time and cuts off the fraction. At 30 FPS a frame's rise is many units, but above
// 30 FPS it is under one, so the puffs hardly rose and the fire burned short and flat (L, 2026-11-09).
// Above 30 FPS the cut-off fraction is kept for each puff and added to its next move, so a puff goes as
// far in a second as at 30 FPS. The fire's puff count also grows or shrinks by 2 each game frame as it
// lights or goes out; above 30 FPS that steps once per 1/30 s of game time for the fire.
namespace {
    std::mutex fire_mutex;
    std::unordered_map<uint32_t, float> fire_fractions;
}

extern "C" void tooie_fire_puff_whole(uint8_t* rdram, recomp_context* ctx, int which) {
    (void)rdram;
    if (!above_30()) {
        return;
    }
    float* value = which == 0 ? &ctx->f16.fl : which == 1 ? &ctx->f6.fl : which == 2 ? &ctx->f18.fl : &ctx->f8.fl;
    const uint32_t key = (uint32_t)ctx->r16 + (uint32_t)which;
    std::lock_guard lock{ fire_mutex };
    if (fire_fractions.size() > 8192) {
        fire_fractions.clear();
    }
    float& fraction = fire_fractions[key];
    const float total = *value + fraction;
    const float whole = std::trunc(total);
    fraction = total - whole;
    *value = whole;
}

extern "C" int tooie_fire_count_skip(uint8_t* rdram, recomp_context* ctx) {
    return fire_count_gate.skip(rdram, (uint32_t)ctx->r19) ? 1 : 0;
}

// A fire's light (chfirefx): func_80800C18_chfirefx moves the light with the fire, then multiplies its
// colour by a new random brightness (func_800DC178, $f0) and sets it ($s0 = the light's holder), once per
// game frame. The map's lit walls round the torch take that colour, so at Uncapped they flickered 300 or more
// times a second instead of 30 (Witchyworld's Haunted Cavern; L, 2026-11-12). Above 30 FPS a new brightness
// is taken once per 1/30 s of game time for each light, as at 30 FPS, and the light goes toward it by the
// frame's share of fire_light_settle, so it flickers at the 30 FPS pace a little more softly (L asked for a
// slight flicker: jumping straight there was "too aggressive", 0.1 s took the flicker away). At 30 FPS and
// Original the game's own brightness is used as it is.
namespace {
    struct FireLight {
        uint32_t frame;
        float time;
        float target;
        float now;
    };
    std::mutex fire_light_mutex;
    std::unordered_map<uint32_t, FireLight> fire_lights;
    constexpr float fire_light_settle = 0.05f;
}

extern "C" void tooie_fire_light_brightness(uint8_t* rdram, recomp_context* ctx) {
    std::lock_guard lock{ fire_light_mutex };
    if (!above_30()) {
        fire_lights.clear();
        return;
    }
    const uint32_t key = (uint32_t)ctx->r16;
    const float fresh = ctx->f0.fl;
    const uint32_t frame = game_frames_stepped.load();
    auto found = fire_lights.find(key);
    if (found == fire_lights.end()) {
        if (fire_lights.size() > 1024) {
            fire_lights.clear();
        }
        fire_lights.emplace(key, FireLight{ frame, 0.0f, fresh, fresh });
        return;
    }
    FireLight& light = found->second;
    // Called again in the same game frame (another of the fire's updates): the same brightness.
    if (light.frame != frame) {
        light.frame = frame;
        const float delta = read_float(rdram, delta_time_addr);
        light.time += delta;
        if (light.time >= 1.0f / 30.0f - 0.001f) {
            light.time = std::min(light.time - 1.0f / 30.0f, 1.0f / 30.0f);
            light.target = fresh;
        }
        light.now += (light.target - light.now) * std::clamp(delta / fire_light_settle, 0.0f, 1.0f);
    }
    ctx->f0.fl = light.now;
}

// A fire's new puffs (chfirefx): func_80800884_chfirefx makes up to 2 each game frame while the fire has fewer
// than it holds ($s1 = the fire's data). A puff lives 0.6 s of game time, so at 30 FPS the puffs are made a
// few frames apart and the fire burns as a steady stream. Above 30 FPS a puff that died was made again on the
// next frame, the puffs came to the same age, and the fire rose and died in waves and moved too fast (L,
// 2026-11-12: braziers in Witchyworld's Haunted Cavern). Above 30 FPS new puffs are made once per 1/30 s of
// game time for that fire.
// Flickering world light (the idlight overlay, an effect of the map's idworld), such as the green light at the
// mouth of Witchyworld's Haunted Cavern: idlight_entrypoint_3 adds a random step (func_800DC264, $f0) to the
// effect's brightness (+0x0, the effect saved at 0x18($sp)), holds it between its limits and colours the map by
// it, once per game frame, so above 30 FPS the light flickered 200 or more times a second instead of 30 (L,
// 2026-11-12). Above 30 FPS the step is 0 until 1/30 s of game time has gone by for that effect; the map is still
// coloured every frame.
extern "C" int tooie_light_effect_skip(uint8_t* rdram, recomp_context* ctx) {
    return light_effect_gate.skip(rdram, (uint32_t)MEM_W(0x18, ctx->r29)) ? 1 : 0;
}

// Enemies fading in and out (subaddiefade_entrypoint_7, $a0 = the enemy): unless the enemy enemy_fades by time, its
// alpha (+0x9B) goes up or down by 7 each game frame, and a fade-out that ends removes it. That is about 1.2 s at
// 30 FPS, but a beaten enemy vanished in a fraction of a second above it (L, 2026-11-12). Above 30 FPS the step is
// 7 for each 1/30 s of game time, with the fraction kept for that enemy, so the fade takes as long as at 30 FPS.
namespace {
    struct EnemyFade {
        uint32_t frame;
        float carry;
        int step;
    };
    std::mutex enemy_fade_mutex;
    std::unordered_map<uint32_t, EnemyFade> enemy_fades;
}

extern "C" int tooie_fade_step(uint8_t* rdram, recomp_context* ctx) {
    std::lock_guard lock{ enemy_fade_mutex };
    if (!above_30()) {
        enemy_fades.clear();
        return 7;
    }
    const uint32_t frame = game_frames_stepped.load();
    EnemyFade& fade = enemy_fades[(uint32_t)ctx->r4];
    if (enemy_fades.size() > 2048) {
        enemy_fades.clear();
        return 7;
    }
    if (fade.frame != frame) {
        fade.frame = frame;
        fade.carry += 7.0f * 30.0f * read_float(rdram, delta_time_addr);
        fade.step = (int)std::floor(fade.carry);
        fade.carry -= (float)fade.step;
    }
    return fade.step;
}

// TOOIE_FIRE_LOG=1 prints, twice a second, each fire's puff count, how many it holds and each puff's
// age (0 new, 9 gone)/height (+0x4)/+0xA/x (+0x8)/z (+0xC), for comparing the fires between frame rates.
extern "C" int tooie_fire_spawn_skip(uint8_t* rdram, recomp_context* ctx) {
    static const bool log = std::getenv("TOOIE_FIRE_LOG") != nullptr;
    if (log) {
        static std::mutex log_mutex;
        static std::unordered_map<uint32_t, std::chrono::steady_clock::time_point> last;
        std::lock_guard lock{ log_mutex };
        const uint32_t fire = (uint32_t)ctx->r17;
        const auto now = std::chrono::steady_clock::now();
        if (now - last[fire] >= std::chrono::milliseconds(500)) {
            last[fire] = now;
            const int count = std::clamp((int)MEM_H(0x8, (int32_t)fire), 0, 64);
            std::string ages;
            for (int i = 0; i < count; i++) {
                const int32_t puff = (int32_t)(fire + 0x20 + i * 0x14);
                char text[64];
                std::snprintf(text, sizeof(text), " %.1f/%d/%d/%d/%d", read_float(rdram, puff), (int)MEM_H(0x4, puff),
                    (int)MEM_H(0xA, puff), (int)MEM_H(0x8, puff), (int)MEM_H(0xC, puff));
                ages += text;
            }
            std::printf("[fire] %08X puffs %d of %d, ages%s\n", fire, count, (int)MEM_H(0xA, (int32_t)fire), ages.c_str());
            std::fflush(stdout);
        }
    }
    return fire_spawn_gate.skip(rdram, (uint32_t)ctx->r17) ? 1 : 0;
}

// Flames (the suflamefx overlay: torches and braziers, such as the ones in Witchyworld's Haunted Cavern
// and Hailfire Peaks). suflamefx_entrypoint_2 updates a flame's puffs ($s1 = the flame, 0x30 a puff from
// +0x20): each rises by its speed x the frame's time, but its width and depth are multiplied by the flame's
// shrink (+0x10) and its age goes up by the flame's ageing step (+0x14) once per game frame, and the flame's
// picture (a puff's +0x2C) steps once per game frame. Above 30 FPS the puffs shrank and died in a fraction of
// the time, so the flame stood short and flat (L, 2026-11-09). Above 30 FPS the shrink is raised to the
// power of the frame's share of 1/30 s and the age step is scaled by it, so a puff lives and shrinks as long
// as at 30 FPS; the picture steps once per 1/30 s of game time for that flame.
extern "C" void tooie_flame_puff_step(uint8_t* rdram, recomp_context* ctx, int which) {
    (void)rdram;
    if (!above_30()) {
        return;
    }
    const float share = read_float(rdram, delta_time_addr) * 30.0f;
    if (!(share > 0.0f) || share >= 1.0f) {
        return;
    }
    if (which == 0) {
        ctx->f18.fl = std::pow(ctx->f18.fl, share);
    } else if (which == 1) {
        ctx->f8.fl = std::pow(ctx->f8.fl, share);
    } else {
        ctx->f16.fl *= share;
    }
}

extern "C" int tooie_flame_picture_skip(uint8_t* rdram, recomp_context* ctx) {
    return flame_flipbook_gate.skip(rdram, (uint32_t)ctx->r17) ? 1 : 0;
}

// Flickering map light (the vpflicker overlay, one of the map's vertex effects), such as the green
// light in the mouth of Grunty's Lair in Spiral Mountain and inside it (map 0xAD): vpflicker_entrypoint_2
// ($a0 = the effect) adds a random step (func_800DC264) to the effect's brightness, holds it between its
// limits, and marks the map pieces it lights to be coloured again by that brightness. It runs once per game
// frame and takes no frame time, so the light took 30 random steps a second at 30 FPS but 400 or more at
// Uncapped, where the whole area flashed (L, 2026-11-09). Above 30 FPS the step is skipped until 1/30 s of
// game time has gone by for that effect, so the light flickers as it does at 30 FPS; between steps the
// pieces keep the colours they were given.
extern "C" int tooie_vertex_flicker_skip(uint8_t* rdram, recomp_context* ctx) {
    return vertex_flicker_gate.skip(rdram, (uint32_t)ctx->r4) ? 1 : 0;
}

// Flickering lights (the sulights overlay), such as the green light in the mouth of Grunty's
// Lair in Spiral Mountain and inside it (map 0xAD). sulights_entrypoint_9 adds the frame's time
// to each light effect's clock (+0x34, held at most at +0x38) and runs its update every game
// frame. The flicker's update, func_8080021C_sulights ($a0 = the effect), picks up or down at
// random and moves each colour channel by its range x rate (+0x38) x the clock, then sets the
// clock back to 0. So the light took a random step on every frame: 30 a second at 30 FPS, but
// 400 or more at Uncapped, where it flashed and shimmered (L, 2026-11-09). Above 30 FPS the
// update is skipped until the clock holds 1/30 s, so the steps come at the 30 FPS rate and are
// the same size. The clock keeps counting while skipped, as the effect's own fields do the rest.
extern "C" int tooie_light_flicker_skip(uint8_t* rdram, recomp_context* ctx) {
    if (!above_30()) {
        return 0;
    }
    const int32_t effect = (int32_t)ctx->r4;
    const float clock = read_float(rdram, effect + 0x34);
    const float most = read_float(rdram, effect + 0x38);
    // The clock never passes +0x38, so a light with a smaller +0x38 steps when it gets there.
    const float step = std::min(1.0f / 30.0f, most);
    return clock < step - 0.0001f ? 1 : 0;
}

// The underwater camera wobble (Jolly Roger's Lagoon's Sea Bottom and Atlantis, and other deep water).
// func_80114EEC ($s0 = the wobble) adds sin(phase) x 1.5 to the camera's field of view and
// sin(1.5 x phase) x 1.5 to its aspect for the frame (func_800C4B90; the camera update adds them and clears
// them, func_800C54F0), then moves the phase (+0x10) on by 2 degrees. That step takes no frame time, so
// the picture swayed 60 degrees of phase a second at 30 FPS but 800 or more at Uncapped, where the
// whole picture shook (L, 2026-11-10). $f18 holds the 2 just before it is added; above 30 FPS it is scaled
// by the frame's share of 1/30 s, so the wobble keeps the 30 FPS pace (and stands still while paused).
extern "C" void tooie_underwater_wobble_step(uint8_t* rdram, recomp_context* ctx) {
    if (!above_30()) {
        return;
    }
    const float share = read_float(rdram, delta_time_addr) * 30.0f;
    if (!(share >= 0.0f) || share >= 1.0f) {
        return;
    }
    ctx->f18.fl *= share;
}

// Thrust movement (the bamovethrust overlay): the Talon Torpedo and the Sub-Aqua transformation in Jolly
// Roger's Lagoon. bamovethrust_entrypoint_5 ($s0 = the player) sets the velocity to k x itself (k = the
// thrust's +0x84, 0.85 for the torpedo under water) plus a push of the thrust's speed along the way he
// faces, once per game frame with no frame time; only the step from velocity to position takes the
// frame's time. The top speed (push / (1 - k)) is the same at any rate, but at 30 FPS the velocity
// eases round to a new heading over about a fifth of a second, and at Uncapped in a hundredth: the
// torpedo snapped to every touch of the stick and could not be steered (L, 2026-11-10). Here, after
// the game has worked out k x velocity ($sp +0x2C) and the push ($sp +0x38), and above 30 FPS, k becomes
// k ^ (the frame's share of 1/30 s) and the push is scaled to keep the same top speed, so the torpedo
// turns and speeds up as at 30 FPS. While it winds up k is 1 and the push alone is scaled.
extern "C" void tooie_thrust_step(uint8_t* rdram, recomp_context* ctx) {
    static const bool off = std::getenv("TOOIE_NO_THRUST_FIX") != nullptr;   // A/B for tests
    // TOOIE_THRUST_LOG=1: each frame, game time, the step, and the velocity before this frame's update
    // (the thrust's +0x10) as its speed and heading across the ground.
    static const bool log = std::getenv("TOOIE_THRUST_LOG") != nullptr;
    const gpr thrust = (int32_t)MEM_W(0xC8, ctx->r16);
    if (log) {
        const float vx = read_float(rdram, thrust + 0x10), vy = read_float(rdram, thrust + 0x14), vz = read_float(rdram, thrust + 0x18);
        std::printf("[thrust] t %.3f dt %.4f speed %.1f heading %.1f\n", game_seconds_total.load(), read_float(rdram, delta_time_addr),
            std::sqrt(vx * vx + vy * vy + vz * vz), std::atan2(vx, vz) * 57.2958f);
        std::fflush(stdout);
    }
    if (off || !above_30()) {
        return;
    }
    const float share = read_float(rdram, delta_time_addr) * 30.0f;
    if (!(share >= 0.0f) || share >= 1.0f) {
        return;
    }
    // k is 1 while the torpedo winds up before it shoots off: the push then piles up once per frame
    // with nothing taken away (30 a second at 30 FPS, 500 at Uncapped), and the frame's share of it
    // is the push x the share.
    const float k = read_float(rdram, thrust + 0x84);
    if (!(k > 0.0f && k <= 1.0f)) {
        return;
    }
    const float kept = (k == 1.0f) ? 1.0f : std::pow(k, share);
    const float keep_scale = kept / k;
    float push_scale = (k == 1.0f) ? share : (1.0f - kept) / (1.0f - k);
    // The game sets some speeds for one frame only: as the torpedo shoots off it pushes at 225 for one
    // frame, then at 22.5. At 30 FPS that frame lasts 1/30 s and gives the kick (velocity 226 to 417);
    // above 30 FPS it lasted a few milliseconds and the kick was lost. So each new speed (the thrust's
    // +0x8C, which the push was made from) is held for 1/30 s of game time before the next one counts.
    {
        static uint32_t held_thrust = 0;
        static float held_speed = 0.0f;
        static float held_time = 0.0f;
        const float speed = read_float(rdram, thrust + 0x8C);
        const float dt = read_float(rdram, delta_time_addr);
        if ((uint32_t)thrust != held_thrust) {
            held_thrust = (uint32_t)thrust;
            held_speed = speed;
            held_time = 0.0f;
        }
        if (speed != held_speed && held_time >= 1.0f / 30.0f - 0.0001f) {
            held_speed = speed;
            held_time = 0.0f;
        }
        held_time += dt;
        if (speed != held_speed && speed != 0.0f) {
            push_scale *= held_speed / speed;
        }
    }
    const gpr velocity = ctx->r29 + 0x2C;
    const gpr push = ctx->r29 + 0x38;
    for (int i = 0; i < 3; i++) {
        write_float(rdram, velocity + 4 * i, read_float(rdram, velocity + 4 * i) * keep_scale);
        write_float(rdram, push + 4 * i, read_float(rdram, push + 4 * i) * push_scale);
    }
}

// Particles (func_800B4790, the update for every particle emitter: the Talon Torpedo's bubble trail,
// splashes, sparkles, smoke). Each particle keeps its place, speed and spin as whole numbers; every
// game frame the game adds speed x the frame's time (or acceleration x it, or spin x it) and cuts off
// the fraction. At 30 FPS a bubble at 60 units a second moves 2 a frame, but at Uncapped 0.12, cut to
// 0, so slow particles hardly left where they were made: the torpedo's bubbles stayed small and bunched
// (L, 2026-11-10). Above 30 FPS each part moves by what one 30 FPS frame would move it (cut the same
// way: trunc(place + speed / 30) - place, and so on) x the frame's share of 1/30 s, and the fraction
// left over is kept per particle and part (which: 0 and 1 the spin, 2 the place, 3 the speed) and added
// back next frame. So particles go as far in a second as at 30 FPS, smoothly. When a particle dies the
// last one is copied into its slot and takes over that slot's fractions, an error under one unit.
namespace {
    std::mutex particle_mutex;
    std::unordered_map<uint32_t, float> particle_fractions;
}

extern "C" void tooie_particle_whole(uint8_t* rdram, recomp_context* ctx, int which) {
    (void)rdram;
    if (!above_30()) {
        return;
    }
    const float dt = ctx->f20.fl;   // the frame's time step, as the update read it
    if (!(dt > 0.0f) || dt >= 1.0f / 30.0f) {
        return;
    }
    float* value = which == 0 ? &ctx->f4.fl : which == 1 ? &ctx->f18.fl : which == 2 ? &ctx->f6.fl : &ctx->f8.fl;
    // The 30 FPS frame's move. Spin: + trunc(spin speed / 30) ($f18 or $f10 holds the spin speed).
    // Place: trunc(place + speed / 30) - place ($f18 the speed). Speed: the same with the
    // acceleration ($f4 the speed, $f6 the acceleration).
    float step;
    if (which < 2) {
        step = std::trunc((which == 0 ? ctx->f18.fl : ctx->f10.fl) / 30.0f);
    } else {
        const float rate = which == 2 ? ctx->f18.fl : ctx->f6.fl;
        const float from = which == 2 ? std::round(*value - rate * dt) : ctx->f4.fl;
        step = std::trunc(from + rate / 30.0f) - from;
        *value = from;
    }
    const float move = step * dt * 30.0f;
    // $a1 is 4, 8 or 12 for x, y and z by the time the place and speed are cut.
    const uint32_t part = which < 2 ? 0x2C : (which == 2 ? 0x4 : 0x40) + (uint32_t)ctx->r5;
    const uint32_t key = (uint32_t)ctx->r16 + part;
    std::lock_guard lock{ particle_mutex };
    if (particle_fractions.size() > 16384) {
        particle_fractions.clear();
    }
    float& fraction = particle_fractions[key];
    const float total = move + fraction;
    const float whole = std::trunc(total);
    fraction = total - whole;
    *value = (which < 2 ? 0.0f : *value) + whole;
}

// The same update slows the speed and size of particles that have drag (the emitter's flags 0x2000 and
// 0x4000) by the emitter's factor (+0xD0) once per game frame, so above 30 FPS they slowed many times
// faster. The factor just loaded ($f16 or $f14, which 0 or 1) is raised to the frame's share of 1/30 s.
extern "C" void tooie_particle_drag(uint8_t* rdram, recomp_context* ctx, int which) {
    if (!above_30()) {
        return;
    }
    const float share = read_float(rdram, delta_time_addr) * 30.0f;
    if (!(share >= 0.0f) || share >= 1.0f) {
        return;
    }
    float* factor = which == 0 ? &ctx->f16.fl : &ctx->f14.fl;
    if (*factor > 0.0f) {
        *factor = std::pow(*factor, share);
    }
}

// The ice storm (chfireicestorm, Icy Side) spawns one to three snow puffs every game frame
// (func_80800DC8 and func_80800E08, each a new emitter), whatever the frame's time, while the
// puffs only age and die by that time. With time frozen (Photo Mode, the ESC menu's pause:
// delta 1e-7) they never died: L's hang of 2026-10-20 had about 2,400 of them at the storm,
// which filled the frame's display list and wrote over the heap. No new puffs while time
// stands still. Returns 1 to skip the spawn.
extern "C" int tooie_storm_spawn_skip(uint8_t* rdram, recomp_context* ctx) {
    (void)ctx;
    float dt;
    const uint32_t bits = (uint32_t)MEM_W(0, (int32_t)0x8012C760);
    std::memcpy(&dt, &bits, sizeof(dt));
    return (dt < 1.0e-5f) ? 1 : 0;
}

// func_800BBCB8 makes a particle emitter and returns it. The ice storm hook above stops only that
// storm's spawners; any other per-frame spawner has the same fault while time is frozen (Photo Mode
// in Icy Side at Uncapped filled the list, 2026-10-22). While time stands still and the last frame's
// display list was over 60% full, no emitter is made (the caller gets null: the memory guard passes
// over a caller that uses it). Logged once per map. Returns 1 to skip.
extern "C" int tooie_particle_spawn_skip(uint8_t* rdram, recomp_context* ctx) {
    (void)ctx;
    float dt;
    const uint32_t bits = (uint32_t)MEM_W(0, (int32_t)0x8012C760);
    std::memcpy(&dt, &bits, sizeof(dt));
    if (dt >= 1.0e-5f || tooie::gfx_budget::last_list_fraction() < 0.6f) {
        return 0;
    }
    static uint32_t skipped = 0;
    static int logged_map = -1;
    skipped++;
    const int map = MEM_HU(0, (gpr)(int32_t)0x80132DC2);
    if (map != logged_map) {
        logged_map = map;
        std::printf("[particles] time is frozen and the display list is %.0f%% full: no new particle emitters in map %03X (%u skipped so far)\n",
            tooie::gfx_budget::last_list_fraction() * 100.0f, map, skipped);
        std::fflush(stdout);
    }
    return 1;
}

// func_800B4790 ages the particles by the frame's time step ($f0 after func_800D8FF8). While time
// stands still and the last frame's list was over 60% full the step is 1/60 s, so the particles
// already there expire and the list stops growing (the spawn skip above stops new ones).
extern "C" void tooie_particle_age_floor(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    if (ctx->f0.fl < 1.0e-5f && tooie::gfx_budget::last_list_fraction() >= 0.6f) {
        ctx->f0.fl = 1.0f / 60.0f;
    }
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
        "Force Interpolation In Cutscenes",
        "While the opening cutscene plays, runs it at the game's own frame rate when Game Frame Rate is above Original, so its pacing is right, "
        "and Interpolation blends in-between frames up to its rate. Does nothing while Interpolation is Original.",
        true);
    dev.add_bool_option(
        force_demo_interpolation_option,
        "Force Interpolation In The Gameplay Demo",
        "The same for the gameplay demo that plays when you don't press Start (and the other recorded scenes): "
        "Interpolation blends it up to its rate. The demo keeps its own speed either way.",
        false);
}

uint32_t tooie::game_frame_rate::game_ms() {
    return (uint32_t)(game_seconds_total.load() * 1000.0);
}

double tooie::game_frame_rate::game_seconds() {
    return game_seconds_total.load();
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




// Swimming on the surface (Banjo's bsswim, and the same states for the van, the T-Rex, Mumbo and
// Kazooie's paddle) makes a ripple and a bubble, each on a coin flip, every 8th game frame, and under
// water (bsbswim) bubbles come every other game frame: the game's frame count at 0x800459C8 & 7 (or
// & 1) must be 0 (func_8001210C). Above 30 FPS there are many more game frames, so floating still made
// about ten times the bubbles (L, 2026-11-10; about 40 a second at Unlocked against 4 at 30 FPS).
// `value` is what func_8001210C gave at one of those spots and `site` names the spot. Above 30 FPS the
// frame count is swapped for a count that goes up once per 1/30 s of game time and is seen only on the
// first game frame of each step; on the other frames the mask comes back, which skips the spawn.
// Original and 30 FPS are unchanged.
namespace {
    struct PacedCount {
        uint32_t frame = UINT32_MAX;   // the game frame (game_frames_stepped) last seen
        float time = 0.0f;             // game time towards the next 1/30 s step
        bool stepped = false;          // this game frame starts a new step
        uint32_t steps = 0;
    };
    std::mutex paced_count_mutex;
    PacedCount paced_counts[8];
}

extern "C" uint32_t tooie_paced_frame_mask(uint8_t* rdram, uint32_t value, uint32_t mask, int site) {
    if (!above_30() || site < 0 || site >= 8) {
        return value;
    }
    constexpr float step = 1.0f / 30.0f;
    std::lock_guard lock{ paced_count_mutex };
    PacedCount& c = paced_counts[site];
    const uint32_t frame = game_frames_stepped.load();
    if (c.frame != frame) {
        c.frame = frame;
        c.time += read_float(rdram, delta_time_addr);
        c.stepped = c.time >= step - 0.001f;
        if (c.stepped) {
            c.time = std::min(c.time - step, step);
            c.steps++;
        }
    }
    return c.stepped ? (c.steps & mask) : mask;
}

// TOOIE_EMIT_LOG=1 prints once a second how many particles each emitter made (func_800BA22C: $a0 the
// emitter, $a1 how many) with the emitter's first three words (the low half of the first is the
// sprite), and how many emitters were made (func_800BBCB8). For comparing particle counts between
// frame rates.
namespace {
    std::mutex emit_mutex;
    std::unordered_map<uint32_t, uint32_t> emit_counts;
    uint32_t emitters_made = 0;
}

extern "C" void tooie_emit_log(uint8_t* rdram, recomp_context* ctx, int made) {
    static const bool on = std::getenv("TOOIE_EMIT_LOG") != nullptr;
    if (!on) {
        return;
    }
    std::lock_guard lock{ emit_mutex };
    static auto start = std::chrono::steady_clock::now();
    if (made) {
        emitters_made++;
    } else {
        emit_counts[(uint32_t)ctx->r4] += (uint32_t)ctx->r5;
    }
    const auto now = std::chrono::steady_clock::now();
    if (now - start < std::chrono::seconds(1)) {
        return;
    }
    start = now;
    std::printf("[emit] %u emitters made in the last second\n", emitters_made);
    for (auto& [e, n] : emit_counts) {
        std::printf("[emit]   %08X made %u, words %08X %08X %08X\n", e, n, (uint32_t)MEM_W(0x0, (int32_t)e),
            (uint32_t)MEM_W(0x4, (int32_t)e), (uint32_t)MEM_W(0x8, (int32_t)e));
    }
    std::fflush(stdout);
    emit_counts.clear();
    emitters_made = 0;
}
