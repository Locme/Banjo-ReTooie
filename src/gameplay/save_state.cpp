// Save states (handoff 4.14).
//
// One slot, in memory. A save copies the whole of RDRAM and the game thread's registers at the start of
// func_800A7D84, the game's per-frame update (tooie_warp_tick), where the game thread is between frames.
// A load copies them back at the same point, so the game carries on from the snapshot's frame.
//
// Game threads are host threads, so a snapshot can't hold where each one is in its code. It works
// because at that point every other game thread waits on a message queue in RDRAM, and a load is only
// done while each waits on the same queue as at the save, with the game thread at the same stack
// pointer and return address (it retries for a few seconds until they are).
//
// Runtime state that goes with RDRAM is saved and put back too (lib-patches/N64ModernRuntime.patch):
// the loaded overlay tables (and the game's own overlay map, src/game/overlays.cpp) so code the
// snapshot calls into is found, the RDP freeze with its held completions, the VI's framebuffers (the
// game's scheduler thread checks them against what it noted), the messages host threads have sent and
// the game hasn't taken yet, and the head of the ready-to-run thread queue. Both wait until no RSP or
// display list task is running, since those read and write RDRAM on threads of their own.
//
// Only in a level (tooie::debug::can_warp) and not during a map change. A load from another area first
// warps back to the snapshot's area with the game's own map change, then loads: restoring straight
// across areas could leave the game hung (seen headless, Mayahem Temple to Spiral Mountain).
//
// TOOIE_SAVESTATE=<save ms>:<load ms>[:<load ms>...] saves and loads at those times for headless runs.

#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <mutex>
#include <thread>
#include <vector>

#include "recomp.h"
#include "librecomp/overlays.hpp"
#include "ultramodern/ultramodern.hpp"
#include "recompinput/recompinput.h"
#include "recompinput/input_binding.h"
#include "recompinput/input_state.h"
#include "recompinput/profiles.h"
#include "tooie_mix_rate.h"
#include "tooie_debug.h"
#include "tooie_game.h"
#include "tooie_save_state.h"
#include "tooie_toast.h"

namespace {
    using namespace std::chrono_literals;

    // The game's memory up to the top of its heap (0x80E00000, raised from 0x80400000 in banjotooie.us.toml).
    constexpr size_t rdram_size = 0xE00000;
    constexpr auto save_input = recompinput::GameInput::SAVE_STATE;
    constexpr auto load_input = recompinput::GameInput::LOAD_STATE;
    // The game-state block: +0x12 is set while a map change is pending.
    constexpr gpr game_state_addr = (int32_t)0x80127630;

    std::atomic<bool> save_requested{false};
    std::atomic<bool> load_requested{false};

    struct Snapshot {
        bool valid = false;
        std::vector<uint8_t> rdram;
        // Sound memory above 8 MB while Sound > Mix rate is High (src/gameplay/mix_rate.cpp).
        std::vector<uint8_t> audio_rdram;
        recomp_context ctx;
        recomp::overlays::OverlayState overlays;
        std::unordered_map<uint32_t, int32_t> mapped_overlays;
        std::vector<ultramodern::GameThreadState> threads;
        std::pair<bool, int> dp_hold;
        std::pair<PTR(void), PTR(void)> vi_framebuffers;
        std::vector<ultramodern::ExternalMessage> external_messages;
        PTR(OSThread) running_queue = NULLPTR;
        uint16_t map = 0;
        uint8_t exit = 0;
    } snapshot;

    std::once_flag started;

    struct Test {
        std::vector<long> times;
        size_t next = 0;
        std::chrono::steady_clock::time_point begin;
    } test;

    bool input_down(recompinput::GameInput input) {
        if (recompinput::binding::is_binding()) {
            return false;
        }
        bool down = false;
        for (int profile : { recompinput::profiles::get_sp_keyboard_profile_index(), recompinput::profiles::get_sp_controller_profile_index() }) {
            if (profile < 0) {
                continue;
            }
            for (size_t b = 0; b < recompinput::num_bindings_per_input; b++) {
                down = down || recompinput::get_input_digital(0, recompinput::profiles::get_input_binding(profile, input, b));
            }
        }
        return down;
    }

    void worker() {
        bool save_was = false, load_was = false;
        for (;;) {
            std::this_thread::sleep_for(16ms);
            const bool save_down = input_down(save_input);
            const bool load_down = input_down(load_input);
            if (save_down && !save_was) {
                save_requested = true;
            }
            if (load_down && !load_was) {
                load_requested = true;
            }
            save_was = save_down;
            load_was = load_down;
        }
    }

    void test_tick() {
        if (test.next >= test.times.size()) {
            return;
        }
        const long ms = (long)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - test.begin).count();
        if (ms >= test.times[test.next]) {
            (test.next == 0 ? save_requested : load_requested) = true;
            test.next++;
        }
    }

    void log_threads(uint8_t* rdram) {
        static const bool log = std::getenv("TOOIE_SAVESTATE_LOG") != nullptr;
        if (!log) {
            return;
        }
        for (const auto& t : ultramodern::get_game_thread_states(rdram)) {
            fprintf(stderr, "[savestate]   thread %08X queue %08X\n", (uint32_t)t.thread, (uint32_t)t.queue);
        }
    }

    // Frames a save or load keeps trying for before giving up (about 5 s at 60 FPS).
    constexpr int max_tries = 300;
    int save_tries = 0;
    int load_tries = 0;
    const char* last_refusal = "";


    // TOOIE_RAMDUMP=<ms>[,<ms>...]: writes RDRAM (big-endian words as the game sees them) to
    // ramdump_<ms>.bin in the working folder at those times, for finding values by diffing.
    void ram_dump_tick(uint8_t* rdram) {
        static std::vector<long> times = [] {
            std::vector<long> t;
            if (const char* v = std::getenv("TOOIE_RAMDUMP")) {
                for (const char* p = v; *p;) {
                    char* end;
                    long ms = std::strtol(p, &end, 10);
                    if (end == p) {
                        break;
                    }
                    t.push_back(ms);
                    p = (*end == ',') ? end + 1 : end;
                }
            }
            return t;
        }();
        static size_t next = 0;
        static const auto begin = std::chrono::steady_clock::now();
        if (next >= times.size()) {
            return;
        }
        const long ms = (long)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - begin).count();
        if (ms < times[next]) {
            return;
        }
        char name[64];
        snprintf(name, sizeof(name), "ramdump_%ld.bin", times[next]);
        next++;
        std::vector<uint8_t> words(rdram_size);
        for (size_t i = 0; i < rdram_size; i += 4) {
            const uint32_t w = (uint32_t)MEM_W(0, (gpr)(int32_t)(0x80000000u + i));
            words[i] = w >> 24; words[i + 1] = w >> 16; words[i + 2] = w >> 8; words[i + 3] = w;
        }
        if (FILE* f = std::fopen(name, "wb")) {
            std::fwrite(words.data(), 1, words.size(), f);
            std::fclose(f);
            fprintf(stderr, "[savestate] wrote %s\n", name);
        }
    }

    enum class Result { done, retry };

    // The renderer and the RSP task thread read and write RDRAM: let what they have finish first.
    bool wait_for_tasks() {
        if (!ultramodern::wait_for_tasks_idle(2000)) {
            fprintf(stderr, "[savestate] tasks still running\n");
            return false;
        }
        return true;
    }

    Result save(uint8_t* rdram, recomp_context* ctx) {
        auto threads = ultramodern::get_game_thread_states(rdram);
        if (!wait_for_tasks()) {
            return Result::retry;
        }
        snapshot.rdram.resize(rdram_size);
        std::memcpy(snapshot.rdram.data(), rdram, rdram_size);
        snapshot.audio_rdram.assign(rdram + tooie::mix_rate::extra_region_start(),
            rdram + tooie::mix_rate::extra_region_start() + tooie::mix_rate::extra_region_size());
        snapshot.ctx = *ctx;
        snapshot.threads = std::move(threads);
        snapshot.dp_hold = ultramodern::get_dp_hold_state();
        snapshot.vi_framebuffers = ultramodern::get_vi_framebuffers();
        snapshot.external_messages = ultramodern::get_external_messages();
        snapshot.running_queue = ultramodern::get_running_queue_head();
        recomp::overlays::save_overlay_state(snapshot.overlays);
        snapshot.mapped_overlays = tooie::mapped_overlays();
        snapshot.map = tooie::debug::current_map(rdram);
        snapshot.exit = MEM_B(0x13, game_state_addr);
        snapshot.valid = true;
        log_threads(rdram);
        tooie::toast::show("State saved");
        fprintf(stderr, "[savestate] saved (map 0x%X, %zu threads, try %d)\n", snapshot.map, snapshot.threads.size(), save_tries + 1);
        return Result::done;
    }

    // A load from another area first warps to the snapshot's area (loading straight across areas can
    // leave the game hung), then waits this many frames for it to settle.
    constexpr int settle_frames = 20;
    bool warping = false;
    int settle = 0;

    Result load(uint8_t* rdram, recomp_context* ctx) {
        if (!snapshot.valid) {
            tooie::toast::show("No saved state yet");
            fprintf(stderr, "[savestate] load: nothing saved\n");
            return Result::done;
        }
        if (tooie::debug::current_map(rdram) != snapshot.map) {
            if (!warping) {
                warping = true;
                tooie::debug::request_warp(snapshot.map, snapshot.exit);
                fprintf(stderr, "[savestate] warping to map 0x%X first\n", snapshot.map);
            }
            last_refusal = "warping";
            return Result::retry;
        }
        if (warping) {
            warping = false;
            settle = settle_frames;
        }
        if (settle > 0) {
            settle--;
            last_refusal = "settling";
            return Result::retry;
        }
        // The game threads, the RDP freeze and the game thread's own stack must all be where they were.
        if (ctx->r29 != snapshot.ctx.r29 || ctx->r31 != snapshot.ctx.r31) {
            last_refusal = "stack";
            return Result::retry;
        }
        if (ultramodern::get_game_thread_states(rdram) != snapshot.threads) {
            last_refusal = "threads";
            return Result::retry;
        }
        if (!wait_for_tasks()) {
            last_refusal = "tasks";
            return Result::retry;
        }
        std::memcpy(rdram, snapshot.rdram.data(), rdram_size);
        if (!snapshot.audio_rdram.empty()) {
            std::memcpy(rdram + tooie::mix_rate::extra_region_start(), snapshot.audio_rdram.data(), snapshot.audio_rdram.size());
        }
        *ctx = snapshot.ctx;
        recomp::overlays::load_overlay_state(snapshot.overlays);
        tooie::set_mapped_overlays(snapshot.mapped_overlays);
        ultramodern::set_dp_hold_state(snapshot.dp_hold);
        ultramodern::set_vi_framebuffers(snapshot.vi_framebuffers);
        ultramodern::set_external_messages(snapshot.external_messages);
        ultramodern::set_running_queue_head(snapshot.running_queue);
        log_threads(rdram);
        tooie::toast::show("State loaded");
        fprintf(stderr, "[savestate] loaded (map 0x%X, try %d)\n", snapshot.map, load_tries + 1);
        return Result::done;
    }


}

void tooie::save_state::register_input() {
    recompinput::set_game_input_name(save_input, "Save State");
    recompinput::set_game_input_description(save_input,
        "Keeps a snapshot of the game in memory (one slot, in a level only). Load State goes back to it. "
        "Lost when the game closes.");
    recompinput::set_default_mapping_for_keyboard(save_input, { recompinput::InputField::keyboard(SDL_SCANCODE_INSERT) });
    recompinput::set_game_input_name(load_input, "Load State");
    recompinput::set_game_input_description(load_input, "Goes back to the snapshot Save State took.");
    recompinput::set_default_mapping_for_keyboard(load_input, { recompinput::InputField::keyboard(SDL_SCANCODE_HOME) });
}

void tooie::save_state::start() {
    std::call_once(started, [] {
        if (const char* v = std::getenv("TOOIE_SAVESTATE")) {
            const char* p = v;
            while (*p) {
                char* end;
                long t = std::strtol(p, &end, 10);
                if (end == p) {
                    break;
                }
                test.times.push_back(t);
                p = (*end == ':') ? end + 1 : end;
            }
            test.begin = std::chrono::steady_clock::now();
        }
        std::thread(worker).detach();
    });
}

void tooie::save_state::tick(uint8_t* rdram, recomp_context* ctx) {
    test_tick();
    ram_dump_tick(rdram);
    if (!save_requested.load() && !load_requested.load()) {
        return;
    }
    // Wait for a map change to finish.
    if (MEM_B(0x12, game_state_addr) != 0) {
        return;
    }
    const bool in_level = tooie::debug::can_warp();
    if (save_requested.load()) {
        if (!in_level) {
            save_requested = false;
            tooie::toast::show("Save states work in a level");
        }
        else if (save(rdram, ctx) == Result::done) {
            save_requested = false;
            save_tries = 0;
        }
        else if (++save_tries >= max_tries) {
            save_requested = false;
            save_tries = 0;
            tooie::toast::show("Couldn't save the state here");
            fprintf(stderr, "[savestate] save gave up (%s)\n", last_refusal);
            log_threads(rdram);
        }
    }
    if (load_requested.load()) {
        if (!in_level && !warping) {
            load_requested = false;
            tooie::toast::show("Save states work in a level");
        }
        else if (load(rdram, ctx) == Result::done) {
            load_requested = false;
            load_tries = 0;
        }
        else if (warping || settle > 0) {
            // The warp back to the snapshot's area doesn't count against the tries.
        }
        else if (++load_tries >= max_tries) {
            load_requested = false;
            load_tries = 0;
            tooie::toast::show("Couldn't load the state here");
            fprintf(stderr, "[savestate] load gave up (%s)\n", last_refusal);
            log_threads(rdram);
        }
    }
}
