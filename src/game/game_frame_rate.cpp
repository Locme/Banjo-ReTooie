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
// TOOIE_GAME_FPS=30|60 picks a mode whatever the setting says, for headless
// runs. TOOIE_GAME_FPS_LOG=1 prints, every 2 s, the game frames counted, the
// time steps the game asked for, the wait it asked for, how fast game time ran
// against real time and how far Banjo moved per second of game time.

#include <array>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <mutex>
#include <variant>

#include "recomp.h"
#include "recompui/config.h"

#include "tooie_game.h"
#include "tooie_game_frame_rate.h"
#include "tooie_hooks.h"

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
                return 1;
            default:
                return 0;
        }
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
        uint64_t total_vis = 0;
        uint64_t total_frames = 0;
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
        auto valid = [](uint32_t p) { return p >= 0x80000000u && p < 0x80800000u; };
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
        l.game_vis += used_step > 0 ? used_step : 0;
        l.total_vis += used_step > 0 ? used_step : 0;
        l.total_frames++;
        // Map changes and letterboxed scenes, stamped with game time, so a scene's
        // length in game time can be compared between modes.
        int map = MEM_HU(0, (gpr)(int32_t)0x80132DC2);
        bool scene = tooie::in_letterboxed_scene();
        if (map != l.map || scene != l.scene) {
            static const auto start = std::chrono::steady_clock::now();
            std::printf("[game-time] %.2f s game time, %.2f s real time, frame %llu: map %03X%s%s\n", l.total_vis / 60.0,
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
        }
        l.steps[asked_step <= 0 ? 0 : (asked_step >= 5 ? 5 : asked_step)]++;
        auto now = std::chrono::steady_clock::now();
        double seconds = std::chrono::duration<double>(now - l.last).count();
        if (seconds >= 2.0) {
            double game_seconds = l.game_vis / 60.0;
            std::printf("[game-fps] %.1f game fps | steps asked 0:%u 1:%u 2:%u 3:%u 4:%u 5+:%u | step used %d | wait asked %d | game time x%.2f | Banjo %.0f units per game second\n",
                l.frames / seconds, l.steps[0], l.steps[1], l.steps[2], l.steps[3], l.steps[4], l.steps[5], used_step, l.wait,
                game_seconds / seconds, game_seconds > 0.0 ? l.distance / game_seconds : 0.0);
            std::fflush(stdout);
            l.frames = 0;
            l.steps.fill(0);
            l.game_vis = 0;
            l.distance = 0.0f;
            l.last = now;
        }
    }
}

// func_800151BC, right after each call to func_80015184: $v0 holds the VIs the
// game wants to wait between frames.
extern "C" void tooie_frame_wait(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    if (logging()) {
        log().wait = (int32_t)ctx->r2;
    }
    int32_t vis = locked_vis();
    if (vis != 0) {
        ctx->r2 = vis;
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
    if (vis != 0) {
        ctx->r2 = vis;
    }
    if (logging()) {
        log_frame(rdram, asked, (int32_t)ctx->r2);
    }
}

// func_8001608C, as an attract demo replays a frame's recorded time step. Demos
// replay a fixed number of frames, so the game keeps its own pacing while one
// plays (at 60 FPS it would otherwise run twice as fast).
extern "C" void tooie_demo_frame(uint8_t* rdram, recomp_context* ctx) {
    (void)rdram;
    (void)ctx;
    demo_frames = 2;
}

void tooie::game_frame_rate::add_option(recomp::config::Config& graphics) {
    created = true;
    graphics.add_enum_option(
        option,
        "Game Frame Rate",
        "How often the game itself updates. <recomp-color primary>Original</recomp-color> follows the game's own timing, which moves between frame lengths. "
        "<recomp-color primary>30 FPS</recomp-color> and <recomp-color primary>60 FPS</recomp-color> keep every game frame the same length. "
        "This is not the Framerate option, which adds in-between frames without changing the game.",
        {
            {Mode::Original, "Original", "Original"},
            {Mode::Fps30, "Fps30", "30 FPS"},
            {Mode::Fps60, "Fps60", "60 FPS"},
        },
        Mode::Original);
}
