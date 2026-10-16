// Hold to run (L, 2026-10-14): "press B and hold to run", rebindable in the controller options,
// with an animation that fits Banjo running. Only for Banjo-Kazooie, Banjo alone and Kazooie alone.
//
// The Run control is a game input in the Controls tab. It had no default binding at first (L, 2026-10-14:
// "its own bind ... but unbind it"); since L's "Make B the default run button" (2026-10-16) it defaults to the
// controller's B button (SDL's east face button), which then stops being a second C-right (the right stick
// still is one). Saved controls get the same change once (see give_run_the_b_button). While it is held in that form's run state, the target speed the run state asks for
// (baphysics_set_target_horizontal_velocity, hooked in banjotooie.us.toml) is raised by sprint_scale.
// The game ties its run animation's pace to the speed only up to the normal run speed, so at the
// higher speed the feet would slide (the steps get longer); the top of that speed map is stretched by
// the same factor, so Banjo's run (Banjo-Kazooie, and Banjo alone, who shares it) and Kazooie's run
// keep the same step length and simply step faster.
//
// Run has nothing to do with B or the roll (L, 2026-10-14: "i just want a toggle and a run button").
// Holding it while the stick is tilted at all runs at full speed: a partly tilted stick would
// otherwise walk, and the walk has no sprint. QOL > Running turns the whole feature off.
//
// Debug: TOOIE_RUN_HOLD=<from ms>:<to ms>[,...] acts as Run held between those times after the first pad
// read (headless); TOOIE_RUN_LOG=1 logs form, state, animation, speed, animation duration and sprint blend 10 times
// a second; TOOIE_RUN_REBIND=<SDL scancode> rebinds Run on the keyboard as the Controls tab does.

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <variant>
#include <utility>
#include <vector>

#ifdef _WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include "recomp.h"
#include "librecomp/addresses.hpp"
#include "librecomp/game.hpp"
#include "funcs.h"
#include "recompinput/recompinput.h"
#include "recompinput/input_binding.h"
#include "recompinput/profiles.h"

#include "recompui/config.h"
#include "tooie_game.h"
#include "tooie_hooks.h"
#include "tooie_hold_to_run.h"

namespace {
    using namespace std::chrono_literals;
    using Clock = std::chrono::steady_clock;

    constexpr auto run_input = recompinput::GameInput::RUN;

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
        uint32_t idle_state;
    };
    constexpr RunForm run_forms[] = {
        { 0x1, 4,   0x0C, 1 },    // Banjo-Kazooie
        { 0xA, 4,   0x0C, 1 },    // Banjo alone: the same run as Banjo-Kazooie
        { 0xB, 199, 0xA6, 187 },  // Kazooie alone
    };

    // anctrl -> the animation struct it plays (index at +0x18, as anctrl_setIndex sets on the anctrl).
    constexpr uint32_t anctrl_animation = 0x1C;

    // The sprint's length when shown on the spot (TOOIE_RUN_ANIM_TEST): the run's at its top speed, sped up.
    float in_place_duration(uint32_t run_anim) {
        return (run_anim == 0xA6 ? 0.376f : 0.44f) / 1.5f;
    }

    // PlayerState +0x4 -> animation block. In the speed-scaled animation mode (the run) the duration is
    // mapped linearly from the speed at +0x24 to the duration at +0x2C, and from +0x28 to +0x30
    // (__baanim_update_scaleToHorizontalVelocity; Banjo's run: 225 to 500 units/s, 0.54 to 0.44 s).
    constexpr uint32_t map_top_speed = 0x28;
    constexpr uint32_t map_top_duration = 0x30;

    // How much faster than the normal run.
    constexpr float sprint_scale = 1.5f;
    // The sprint eases in and out over this long (speed, step rate and pose together; L 2026-10-14:
    // starting and stopping were too sudden). The pose steps through blend_levels sprint files.
    constexpr float blend_seconds = 0.35f;
    constexpr int blend_levels = 8;
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
        return p >= 0x80000000u && p < 0x81000000u;
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
    void read_run(bool* held) {
        *held = false;
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
            }
        }
    }

    // Controls saved before Run had a default keep Run unbound and the B button on C-right. Once, the first
    // time the game reads input: when the controller profile's Run is unbound and the B button is bound to
    // nothing but C-right, the B button moves to Run and the controls are saved. A marker file in the config
    // folder records that it ran, so unbinding Run afterwards sticks.
    void give_run_the_b_button() {
        const std::filesystem::path marker = recomp::get_config_path() / "run_default_b.done";
        std::error_code ec;
        if (std::filesystem::exists(marker, ec)) {
            return;
        }
        const int profile = recompinput::profiles::get_sp_controller_profile_index();
        if (profile < 0) {
            return;
        }
        const recompinput::InputField b_button = recompinput::InputField::controller_digital(recompinput::SDL_CONTROLLER_BUTTON_EAST);
        bool run_bound = false;
        bool b_taken = false;
        for (size_t i = 0; i < recompinput::num_game_inputs; i++) {
            const auto input = static_cast<recompinput::GameInput>(i);
            for (size_t b = 0; b < recompinput::num_bindings_per_input; b++) {
                const recompinput::InputField& field = recompinput::profiles::get_input_binding(profile, input, b);
                if (input == run_input && field.input_type != recompinput::InputType::None) {
                    run_bound = true;
                }
                if (field == b_button && input != recompinput::GameInput::C_RIGHT && input != run_input) {
                    b_taken = true;
                }
            }
        }
        if (!run_bound && !b_taken) {
            for (size_t b = 0; b < recompinput::num_bindings_per_input; b++) {
                if (recompinput::profiles::get_input_binding(profile, recompinput::GameInput::C_RIGHT, b) == b_button) {
                    recompinput::profiles::set_input_binding(profile, recompinput::GameInput::C_RIGHT, b, recompinput::InputField{});
                }
            }
            recompinput::profiles::set_input_binding(profile, run_input, 0, b_button);
            recompinput::profiles::save_controls_config(recomp::get_config_path() / "controls.json");
            std::printf("[run] Run bound to the controller's B button (taken off C-right)\n");
        } else {
            std::printf("[run] Run kept as saved (%s)\n", run_bound ? "already bound" : "the B button is used for something else");
        }
        std::fflush(stdout);
        std::ofstream(marker) << "Run was given the controller's B button once (hold_to_run.cpp).\n";
    }

    // --- The sprint animations -------------------------------------------------------------------
    //
    // Tooie has no sprint, so the sprint is made from each form's own run animation in the player's
    // ROM, at runtime: an animation file is a list of tracks (bone, transform type), each a list of
    // keyframes (frame, value), as in Banjo-Kazooie. Rotations are in 1/64 degree, scales in 1/64,
    // translations in model units. Each rule below scales a track's swing about its average and adds
    // an offset, or adds a track the run does not have. The result is kept in the recomp heap and
    // handed to the game in place of the run file while the sprint plays.
    struct Rule {
        uint16_t bone;
        uint8_t type;   // 0-2 rotation x/y/z, 3-5 scale, 6-8 translation
        float scale;    // swing about the track's average
        float offset;   // added to every key (rotations: degrees)
    };

    struct Key {
        uint16_t frame; // frame and flags as stored
        int16_t value;
    };

    struct Track {
        uint16_t bone;
        uint8_t type;
        std::vector<Key> keys;
    };

    // Banjo's run (animation 0xC; Banjo alone uses it too): body leant 17 degrees forward (bone 3),
    // legs (chains 6-10 and 20-24) stride 40% further, arms (chains 12-16 and 26-30) swing 15% less
    // (L 2026-10-14: arms flailed too much at 40% more; 12 degrees leant too little, 22 too much).
    const std::vector<Rule> banjo_rules = {
        { 3, 0, 1.0f, 17.0f },
        { 6, 0, 1.4f, 0.0f }, { 6, 1, 1.4f, 0.0f }, { 6, 2, 1.4f, 0.0f },
        { 8, 0, 1.4f, 0.0f }, { 8, 1, 1.4f, 0.0f }, { 8, 2, 1.4f, 0.0f },
        { 10, 0, 1.4f, 0.0f }, { 10, 1, 1.4f, 0.0f }, { 10, 2, 1.4f, 0.0f },
        { 20, 0, 1.4f, 0.0f }, { 20, 1, 1.4f, 0.0f }, { 20, 2, 1.4f, 0.0f },
        { 22, 0, 1.4f, 0.0f }, { 22, 1, 1.4f, 0.0f }, { 22, 2, 1.4f, 0.0f },
        { 24, 0, 1.4f, 0.0f }, { 24, 1, 1.4f, 0.0f }, { 24, 2, 1.4f, 0.0f },
        { 12, 0, 0.85f, 0.0f }, { 12, 1, 0.85f, 0.0f }, { 12, 2, 0.85f, 0.0f },
        { 14, 0, 0.85f, 0.0f }, { 14, 1, 0.85f, 0.0f }, { 14, 2, 0.85f, 0.0f },
        { 16, 0, 0.85f, 0.0f }, { 16, 1, 0.85f, 0.0f }, { 16, 2, 0.85f, 0.0f },
        { 26, 0, 0.85f, 0.0f }, { 26, 1, 0.85f, 0.0f }, { 26, 2, 0.85f, 0.0f },
        { 28, 0, 0.85f, 0.0f }, { 28, 1, 0.85f, 0.0f }, { 28, 2, 0.85f, 0.0f },
        { 30, 0, 0.85f, 0.0f }, { 30, 1, 0.85f, 0.0f }, { 30, 2, 0.85f, 0.0f },
    };

    // Kazooie's run (animation 0xA6): legs (6-12, 20-26) stride 35% further, body (bone 106) leant
    // 10 degrees forward with 40% more bounce.
    const std::vector<Rule> kazooie_rules = {
        { 6, 0, 1.35f, 0.0f },
        { 10, 0, 1.35f, 0.0f },
        { 12, 0, 1.35f, 0.0f },
        { 20, 0, 1.35f, 0.0f },
        { 24, 0, 1.35f, 0.0f },
        { 26, 0, 1.35f, 0.0f },
        { 106, 0, 1.0f, 10.0f }, { 106, 7, 1.4f, 0.0f },
    };

    float rotation_units(uint8_t type) {
        return type <= 2 ? 64.0f : 1.0f;
    }

    // TOOIE_RUN_ANIM_TUNE=<file>: rules to use instead, for tuning headless. Lines: "<anim hex> <bone>
    // <type> <scale> <offset>"; # starts a comment; "@<ms>" starts a set of rules used from that long
    // after the first animation update (to compare several in one run). An animation listed in the
    // set in use takes only those rules.
    struct TuneSet {
        long from_ms = 0;
        std::vector<std::pair<uint32_t, Rule>> rules;
    };
    std::vector<TuneSet> tune_sets;
    size_t tune_active = 0;
    uint32_t tune_generation = 0;

    void reload_tune() {
        const char* path = std::getenv("TOOIE_RUN_ANIM_TUNE");
        if (path == nullptr) {
            return;
        }
        static const Clock::time_point began = Clock::now();
        static bool read = false;
        if (!read) {
            read = true;
            tune_sets.push_back({});
            if (FILE* f = std::fopen(path, "r")) {
                char line[256];
                while (std::fgets(line, sizeof(line), f)) {
                    unsigned anim = 0, bone = 0, type = 0;
                    float scale = 1, offset = 0;
                    long ms = 0;
                    if (std::sscanf(line, "@%ld", &ms) == 1) {
                        tune_sets.push_back({ ms, {} });
                    } else if (line[0] != '#' && std::sscanf(line, "%x %u %u %f %f", &anim, &bone, &type, &scale, &offset) == 5) {
                        tune_sets.back().rules.push_back({ anim, Rule{ (uint16_t)bone, (uint8_t)type, scale, offset } });
                    }
                }
                std::fclose(f);
            }
        }
        const long ms = (long)std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - began).count();
        size_t pick = 0;
        for (size_t i = 0; i < tune_sets.size(); i++) {
            if (tune_sets[i].from_ms <= ms) {
                pick = i;
            }
        }
        if (pick != tune_active || tune_generation == 0) {
            tune_active = pick;
            tune_generation++;
            std::printf("[run] tune set %zu (from %ld ms): %zu rules\n", pick, tune_sets[pick].from_ms, tune_sets[pick].rules.size());
            std::fflush(stdout);
        }
    }

    const std::vector<Rule>* tuned_rules(uint32_t index) {
        static std::vector<Rule> picked;
        if (tune_sets.empty()) {
            return nullptr;
        }
        picked.clear();
        for (const auto& [anim, rule] : tune_sets[tune_active].rules) {
            if (anim == index) {
                picked.push_back(rule);
            }
        }
        return &picked;
    }

    uint16_t rd_half(uint8_t* rdram, uint32_t addr) {
        return (uint16_t)MEM_H(0, (gpr)(int32_t)addr);
    }

    void wr_half(uint8_t* rdram, uint32_t addr, uint16_t value) {
        MEM_H(0, (gpr)(int32_t)addr) = (int16_t)value;
    }

    // Reads an animation file: header (start frame, end frame, track count, pad), then the tracks.
    // Returns its size in bytes, or 0 if it does not look like one.
    uint32_t read_anim(uint8_t* rdram, uint32_t file, uint16_t* start, uint16_t* end, std::vector<Track>* tracks) {
        *start = rd_half(rdram, file);
        *end = rd_half(rdram, file + 2);
        const uint16_t count = rd_half(rdram, file + 4);
        if (count == 0 || count > 512) {
            return 0;
        }
        uint32_t at = file + 8;
        for (uint16_t i = 0; i < count; i++) {
            const uint16_t head = rd_half(rdram, at);
            const uint16_t keys = rd_half(rdram, at + 2);
            if (keys > 2048) {
                return 0;
            }
            Track t{ (uint16_t)(head >> 4), (uint8_t)(head & 0xF), {} };
            at += 4;
            for (uint16_t k = 0; k < keys; k++) {
                t.keys.push_back({ rd_half(rdram, at), (int16_t)rd_half(rdram, at + 2) });
                at += 4;
            }
            tracks->push_back(std::move(t));
        }
        return at - file;
    }

    void apply_rules(std::vector<Track>& tracks, const std::vector<Rule>& rules, uint16_t start) {
        for (const Rule& r : rules) {
            Track* track = nullptr;
            for (Track& t : tracks) {
                if (t.bone == r.bone && t.type == r.type) {
                    track = &t;
                }
            }
            if (track == nullptr) {
                if (r.offset == 0.0f) {
                    continue;
                }
                // A track the run does not move: one key holding the offset (frame flags as the game's own).
                tracks.push_back({ r.bone, r.type, { Key{ (uint16_t)(0xC000 | start), 0 } } });
                track = &tracks.back();
            }
            double mean = 0;
            for (const Key& k : track->keys) {
                mean += k.value;
            }
            mean /= (double)track->keys.size();
            for (Key& k : track->keys) {
                const double v = mean + (k.value - mean) * r.scale + r.offset * rotation_units(r.type);
                k.value = (int16_t)std::clamp(v, -32768.0, 32767.0);
            }
        }
        // The game expects the tracks in bone order.
        std::stable_sort(tracks.begin(), tracks.end(), [](const Track& a, const Track& b) {
            return a.bone != b.bone ? a.bone < b.bone : a.type < b.type;
        });
    }

    struct Built {
        uint32_t source = 0;
        int level = 0;
        uint32_t vram = 0;
    };

    // The sprint file for the run animation `index` at blend `level` (1 to blend_levels, the full
    // sprint), made from the run file at `file` the first time.
    uint32_t sprint_file(uint8_t* rdram, uint32_t index, uint32_t file, int level) {
        static Built built[4 * blend_levels];
        static uint32_t built_generation = 0;
        if (built_generation != tune_generation) {
            built_generation = tune_generation;
            for (Built& b : built) {
                b = {};
            }
        }
        for (const Built& b : built) {
            if (b.source == index && b.level == level && b.vram != 0) {
                return b.vram;
            }
        }
        uint16_t start = 0, end = 0;
        std::vector<Track> tracks;
        if (read_anim(rdram, file, &start, &end, &tracks) == 0) {
            return 0;
        }
        const std::vector<Rule>* rules = tuned_rules(index);
        if (rules == nullptr) {
            rules = index == 0xA6 ? &kazooie_rules : &banjo_rules;
        }
        const float w = (float)level / blend_levels;
        std::vector<Rule> blended = *rules;
        for (Rule& r : blended) {
            r.scale = 1.0f + (r.scale - 1.0f) * w;
            r.offset *= w;
        }
        apply_rules(tracks, blended, start);
        uint32_t size = 8;
        for (const Track& t : tracks) {
            size += 4 + 4 * (uint32_t)t.keys.size();
        }
        void* mem = recomp::alloc(rdram, size + 16);
        if (mem == nullptr) {
            return 0;
        }
        const uint32_t vram = ((uint32_t)(static_cast<uint8_t*>(mem) - rdram) + 0x80000000u + 15u) & ~15u;
        wr_half(rdram, vram, start);
        wr_half(rdram, vram + 2, end);
        wr_half(rdram, vram + 4, (uint16_t)tracks.size());
        wr_half(rdram, vram + 6, 0);
        uint32_t at = vram + 8;
        for (const Track& t : tracks) {
            wr_half(rdram, at, (uint16_t)((t.bone << 4) | t.type));
            wr_half(rdram, at + 2, (uint16_t)t.keys.size());
            at += 4;
            for (const Key& k : t.keys) {
                wr_half(rdram, at, k.frame);
                wr_half(rdram, at + 2, (uint16_t)k.value);
                at += 4;
            }
        }
        for (Built& b : built) {
            if (b.vram == 0) {
                b = { index, level, vram };
                break;
            }
        }
        if (log_on()) {
            std::printf("[run] sprint animation made from 0x%X (blend %d/%d): %zu tracks, %zu rules, at 0x%08X\n",
                index, level, blend_levels, tracks.size(), rules->size(), vram);
            std::fflush(stdout);
        }
        return vram;
    }

    // TOOIE_RUN_ANIM_DUMP=<folder>: writes each animation file the game evaluates once, as anim_<index>.bin.
    void dump_anim(uint8_t* rdram, uint32_t index, uint32_t file) {
        static const char* dump = std::getenv("TOOIE_RUN_ANIM_DUMP");
        static bool done[0x1000] = {};
        if (dump == nullptr || index >= 0x1000 || done[index]) {
            return;
        }
        done[index] = true;
        uint16_t start = 0, end = 0;
        std::vector<Track> tracks;
        const uint32_t size = read_anim(rdram, file, &start, &end, &tracks);
        char name[512];
        std::snprintf(name, sizeof(name), "%s/anim_%03X.bin", dump, index);
        if (FILE* f = std::fopen(name, "wb")) {
            for (uint32_t i = 0; i < size; i++) {
                const uint8_t b = (uint8_t)MEM_BU(i, (gpr)(int32_t)file);
                std::fwrite(&b, 1, 1, f);
            }
            std::fclose(f);
        }
    }

    // The player's animation struct and the run animation the sprint replaces, while it plays.
    std::atomic<uint32_t> sprint_anim_struct{0};
    std::atomic<uint32_t> sprint_source{0};
    // How far into the sprint, 0 (normal run) to 1, eased in and out by tick().
    std::atomic<float> sprint_blend{0.0f};

    // Shared between the input and game threads.
    std::atomic<bool> run_held{false};
    std::atomic<bool> form_can_run{false};

    // Game thread only: the run animation's speed map while it is stretched, and what it was.
    bool cadence_set = false;
    uint32_t saved_speed = 0;
    uint32_t saved_duration = 0;
    uint32_t sprint_speed_bits = 0;
    uint32_t sprint_duration_bits = 0;
    Clock::time_point last_tick{};

    // 1 + (sprint_scale - 1) at full sprint, eased.
    float blend_factor() {
        const float w = sprint_blend.load();
        const float eased = w * w * (3.0f - 2.0f * w);
        return 1.0f + (sprint_scale - 1.0f) * eased;
    }

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

namespace {
    // QOL > Running, read a few times a second rather than on every pad read.
    bool enabled(Clock::time_point now) {
        static bool cached = true;
        static Clock::time_point cached_at{};
        if (cached_at == Clock::time_point{} || now - cached_at > 250ms) {
            cached_at = now;
            try {
                cached = std::get<bool>(recompui::config::get_config(tooie::qol_tab_id).get_option_value(tooie::hold_to_run::option));
            } catch (...) {
                cached = true;
            }
        }
        return cached;
    }
}

void tooie::hold_to_run::register_input() {
    recompinput::set_game_input_name(run_input, "Run");
    recompinput::set_game_input_description(run_input,
        "Hold to run faster as Banjo-Kazooie, Banjo or Kazooie. The controller's B button by default. QOL > Running turns it off.");
    recompinput::set_game_input_section(run_input, "Movement");
    recompinput::set_default_mapping_for_keyboard(run_input, {});
    recompinput::set_default_mapping_for_controller(run_input, { recompinput::InputField::controller_digital(recompinput::SDL_CONTROLLER_BUTTON_EAST) });
    // The B button was also C-right; the right stick keeps that.
    recompinput::set_default_mapping_for_controller(recompinput::GameInput::C_RIGHT,
        { recompinput::InputField::controller_analog(SDL_CONTROLLER_AXIS_RIGHTX, true) });
}

void tooie::hold_to_run::apply(float* x, float* y) {
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
    static const bool migrated = [] { give_run_the_b_button(); return true; }();
    (void)migrated;
    bool held = false;
    read_run(&held);
    TestHold& test = test_hold();
    if (!test.windows.empty()) {
        const long ms = (long)std::chrono::duration_cast<std::chrono::milliseconds>(now - test.begin).count();
        for (const auto& [from, to] : test.windows) {
            held = held || (ms >= from && ms < to);
        }
    }
    const float tilt = std::sqrt(*x * *x + *y * *y);
    const bool moving = tilt > move_tilt;
    const bool on = held && moving && enabled(now) && form_can_run.load();
    if (on) {
        // A full tilt the same way, so the game runs rather than walks.
        *x = std::clamp(*x / tilt, -1.0f, 1.0f);
        *y = std::clamp(*y / tilt, -1.0f, 1.0f);
    }
    run_held = on;
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
        if (Clock::now() - last > 100ms) {
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
            std::printf("[run] form 0x%X state %u anim 0x%X target %.1f speed %.1f duration %.3f (map %.0f-%.0f to %.3f-%.3f) held %d blend %.2f\n",
                form, state, index, target, std::sqrt(vx * vx + vz * vz), duration, map[0], map[1], map[2], map[3], (int)run_held.load(), sprint_blend.load());
            std::fflush(stdout);
        }
    }

    const uint32_t anim = rd_word(rdram, player + 0x4);
    if (!valid_ptr(anim)) {
        cadence_set = false;
        return;
    }
    const bool running = rf != nullptr && state == rf->run_state && index == rf->run_anim;
    const bool want = running && run_held.load();
    // Ease toward the sprint while it is wanted and back to the run when not; out of the run the
    // game plays another animation, so the blend starts again from nothing.
    const auto now = Clock::now();
    const float dt = last_tick == Clock::time_point{} ? 0.0f
        : std::min(std::chrono::duration<float>(now - last_tick).count(), 0.1f);
    last_tick = now;
    float blend = sprint_blend.load();
    if (!running) {
        blend = 0.0f;
    } else {
        blend = std::clamp(blend + (want ? dt : -dt) / blend_seconds, 0.0f, 1.0f);
    }
    sprint_blend = blend;
    // The sprint animation plays in place of the run while any of the sprint is on.
    const bool sprinting = running && blend > 0.0f;
    sprint_anim_struct = sprinting && ctrl != 0 ? ctrl + anctrl_animation : 0;
    sprint_source = sprinting ? rf->run_anim : 0;
    // TOOIE_RUN_ANIM_TEST=1: standing still plays the sprint animation on the spot, to look at it.
    static const bool in_place = std::getenv("TOOIE_RUN_ANIM_TEST") != nullptr;
    if (in_place && rf != nullptr && ctrl != 0 && state == rf->idle_state) {
        if (index != rf->run_anim) {
            recomp_context call = call_context(ctx, ctrl);
            call.r5 = (int32_t)rf->run_anim;
            anctrl_setIndex(rdram, &call);
            call.r4 = (int32_t)ctrl;
            call.r5 = (int32_t)as_bits(in_place_duration(rf->run_anim));
            anctrl_setDuration(rdram, &call);
            call.r4 = (int32_t)ctrl;
            call.r5 = 2; // loop
            anctrl_setPlaybackType(rdram, &call);
            call.r4 = (int32_t)ctrl;
            anctrl_start(rdram, &call);
        }
        sprint_anim_struct = ctrl + anctrl_animation;
        sprint_source = rf->run_anim;
        sprint_blend = 1.0f;
    }
    const uint32_t cur_speed = rd_word(rdram, anim + map_top_speed);
    const uint32_t cur_duration = rd_word(rdram, anim + map_top_duration);
    if (sprinting) {
        // The run animation's duration follows the speed linearly from map_top_speed down to
        // map_top_duration. Stretching that end to the sprint speed, with the duration shortened as
        // much, keeps Banjo's steps the same length as in the normal run. The game may set the map
        // again (a new run), so it is checked every frame; the stretch follows the blend.
        if (!cadence_set || cur_speed != sprint_speed_bits || cur_duration != sprint_duration_bits) {
            saved_speed = cur_speed;
            saved_duration = cur_duration;
        }
        const float f = blend_factor();
        sprint_speed_bits = as_bits(as_float(saved_speed) * f);
        sprint_duration_bits = as_bits(as_float(saved_duration) / f);
        wr_word(rdram, anim + map_top_speed, sprint_speed_bits);
        wr_word(rdram, anim + map_top_duration, sprint_duration_bits);
        cadence_set = true;
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
    if (sprint_blend.load() <= 0.0f) {
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
    speed *= blend_factor();
    std::memcpy(&bits, &speed, sizeof(bits));
    ctx->r5 = (int32_t)bits;
}

// Hooked in the animation update (func_8008BD94, func_8008BEB4) after the asset getter: $v0 is the
// animation file about to be evaluated for the animation struct in $s0 (its index at +0x18).
extern "C" void tooie_run_anim_file(uint8_t* rdram, recomp_context* ctx) {
    const uint32_t anim = (uint32_t)ctx->r16;
    const uint32_t file = (uint32_t)ctx->r2;
    if (!valid_ptr(anim) || !valid_ptr(file)) {
        return;
    }
    const uint32_t index = (uint32_t)(uint16_t)MEM_H(0x18, (gpr)(int32_t)anim);
    dump_anim(rdram, index, file);
    reload_tune();
    if (anim != sprint_anim_struct.load() || index != sprint_source.load()) {
        return;
    }
    // The pose eases in with the same curve as the speed.
    const float w = sprint_blend.load();
    const int level = (int)std::lround(w * w * (3.0f - 2.0f * w) * blend_levels);
    if (level <= 0) {
        return;
    }
    const uint32_t sprint = sprint_file(rdram, index, file, std::min(level, blend_levels));
    if (sprint != 0) {
        ctx->r2 = (gpr)(int32_t)sprint;
    }
}
