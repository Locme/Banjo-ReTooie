// Cut Content: Torch enemy (L, 2026-10-17).
//
// Banjo-Tooie still has an enemy that was cut before release: an angry torch, actor 0x2AE (overlay
// chstatictorch, model 0x0674). The Cutting Room Floor has concept art saying it was meant for the
// Flooded Caves in Glitter Gulch Mine (map 0xCC), to light up dark areas and chase the player; no map's
// setup places it. What is left of it only stands still: its update keeps a flame effect (suflamefx) on its
// head and a crackling sound loop (subaddieaudioloop) going, and its ActorData has no animation table.
// Its model has a five-bone skeleton (bone ids 3, 1, 18, 42, 43), and two unused animations in the asset
// table move exactly those bones.
//
// This file brings it back. While the option is on, torches are spawned at fixed spots in the Flooded
// Caves through the game's spawn by id (func_80108474, see src/gameplay/test_room.cpp), with an animation
// table patched into the torch's ActorData first (+0x08; entries are { f32 duration, u16 animation,
// u16 playback }, index = actor state), so func_80101FDC(actor, state) switches its animation as it does
// for any actor. The behaviour runs here, once a frame:
//   - Idle: the disguise. It stands on its spot like any lit mine torch, its eyes shut and tucked into the
//     wood (eye_write moves the model's 11 eye vertices), not moving or turning. It is the lure: when Banjo
//     walks right up to it, it wakes, its eyes open like eyelids over half a second as it turns to him, and it
//     springs. Banjo-Kazooie's Flotsam does the same (it rests in its bind pose and its move animation brings
//     its eyes out); this torch's eyes share the head bone, so the vertices are moved instead.
//   - Light: it glows the whole time. Each torch carries one of the game's point lights (the ones
//     Glowbos light dark rooms with: func_800C8A98 makes one, func_800C8E54 sets its inner and outer
//     radius, func_800C8CB8 moves it, func_800C8FB0 colours it, func_800C8B84 frees it), warm and
//     flickering, so the cave lights up around it.
//   - Chase: after the first lunge it goes after him, never further than a leash from its spot; when he
//     gets away it walks back, faces the way it stood and goes still again, eyes closing. It keeps to the ground (the camera's line test cast down,
//     tooie::free_camera::sweep_line): it takes stairs and slopes but never steps off a ledge or into water.
//   - Lunge: close up it lunges, and a lunge that reaches Banjo burns him for one honeycomb through the
//     game's own health change (func_800A17A8, as every enemy hit does) and knocks him back the way any
//     enemy's hit does: where the hit came from (func_800A34AC), the kind of hit (func_8009AD20, 1), then
//     bs_setState into the hurt state (0x0E, or 0x100 for Kazooie alone). It then backs off while he gets
//     up, and never burns him while he is still in the hurt state.
//   - Beaten: Banjo's attacks (rolls, pecks, swipes, Beak Barge, Beak Buster and the rest) or any egg put
//     it out (eggs are found by model, the seven from the egg actors' ActorData); it shrinks away in a puff. Torches come back the next time the area loads.
// The torch's flame and sound stay the game's own: the flame is drawn at actor +0x18 (its head, set by its
// init), so that point is moved along with the torch.
//
// Turning the option off in the caves puts the torches out at once; turning it on spawns them.
//
// Headless test aids:
//   TOOIE_TORCH=1               the option on whatever the setting says
//   TOOIE_TORCH_EGG_AT=<ms>     at that game time, puts a blue egg on the first torch (eggs put it out)
//   TOOIE_TORCH_NEAR=1          one more torch this far in front of Banjo, in any map (units, e.g. 300)
//   TOOIE_TORCH_AT=x,y,z;...    use these spots instead of the built-in ones (any map with TOOIE_TORCH_NEAR,
//                               otherwise the caves)
//   TOOIE_TORCH_ANIMS=a,b,c,d   animation ids (hex) for idle, chase, lunge and beaten
//   TOOIE_TORCH_SHOTS=1         screenshots on each state change and in the frames after a burn
//   TOOIE_TORCH_LOG=1           logs spawns, state changes, Banjo's state and the objects near a torch
//   TOOIE_MAP_FILE_DUMP=<dir>   once a file is loaded, writes every map's object list (the asset table's kind
//                               10 entries, which the game decrypts and unpacks in _gldbDll_entrypoint_0) to
//                               <dir>/map_<id>.bin; how the Flooded Caves and every other map were checked for a
//                               leftover torch. ROM data: keep it out of the repo.

#include <algorithm>
#include <atomic>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <span>
#include <sstream>
#include <string>
#include <variant>
#include <vector>

#include "recomp.h"
#include "funcs.h"
#include "librecomp/game.hpp"
#include "recompui/config.h"
#include "tooie_debug.h"
#include "tooie_free_camera.h"
#include "tooie_game.h"
#include "tooie_game_frame_rate.h"
#include "tooie_screenshot.h"
#include "tooie_torch_enemy.h"

extern "C" void heap_alloc(uint8_t* rdram, recomp_context* ctx);
extern "C" void heap_free(uint8_t* rdram, recomp_context* ctx);

namespace {
    constexpr uint16_t torch_actor = 0x2AE;
    constexpr uint16_t flooded_caves_map = 0xCC;

    // Spots in the Flooded Caves (x, y, z, facing).
    struct Spot {
        float pos[3];
        float yaw;
    };
    // Against the back wall of the dry chamber at the far end, the places L picked. Each is snapped to the floor
    // and faced out from the wall (the yaw here is only used when no wall is found).
    constexpr Spot cave_spots[] = {
        { { 2051.0f, 136.0f, -8708.0f }, 0.0f },
        { { 2649.0f, 136.0f, -8711.0f }, 0.0f },
    };

    // Actor states, which index the animation table below.
    // Idle is the disguise: it stands on its spot like any lit mine torch. Return is the walk back to it.
    enum State : uint8_t { state_none = 0, state_idle = 1, state_chase = 2, state_lunge = 3, state_beaten = 4, state_return = 5, state_wake = 6, state_count };
    // Animations (asset ids) for those states: the two unused ones that move the torch's five bones. Idle's runs
    // so slowly that the torch holds still on its first frame.
    uint16_t anims[state_count] = { 0, 0x78, 0x79, 0x79, 0x78, 0x79, 0x78 };
    constexpr float anim_durations[state_count] = { 0.0f, 1000.0f, 0.7f, 0.45f, 0.6f, 0.9f, 0.5f };

    // Behaviour (game units and seconds).
    constexpr float ambush_range = 230.0f;      // Banjo this close to a still torch: it wakes and springs at him
    constexpr float wake_time = 0.5f;           // eyes opening before it springs
    constexpr float eye_speed = 2.2f;           // how fast the eyes open or close (whole way per second)
    constexpr float notice_range = 500.0f;      // walking back home, Banjo this close: it chases again
    constexpr float give_up_range = 1100.0f;    // Banjo this far: it goes back
    constexpr float leash = 1200.0f;            // furthest it goes from its spot
    constexpr float lunge_range = 170.0f;       // starts a lunge
    constexpr float hit_range = 80.0f;          // a lunge that gets this close burns Banjo
    constexpr float chase_speed = 230.0f;
    constexpr float lunge_speed = 620.0f;
    constexpr float return_speed = 160.0f;
    constexpr float turn_speed = 360.0f;        // degrees a second
    constexpr float lunge_time = 0.45f;
    constexpr float lunge_rest = 1.1f;          // after a lunge before the next
    constexpr float hit_rest = 2.5f;            // after a lunge that burned Banjo
    constexpr float max_step = 90.0f;           // highest step up or down it takes in one move (stairs, not ledges)
    constexpr float back_off_speed = 140.0f;    // backing away while resting after a burn
    constexpr float beaten_time = 0.6f;
    constexpr float attack_range = 140.0f;      // Banjo's attacks reach this far
    constexpr float egg_range = 90.0f;
    // Light: radius inside which it is full and where it fades out, colour, and how high above the torch.
    constexpr float light_inner = 120.0f;
    constexpr float light_outer = 650.0f;
    constexpr int light_rgb[3] = { 255, 140, 50 };
    constexpr float light_height = 70.0f;

    // Objects (test_room.cpp): pointer to the array, first and last, 0x9C bytes each.
    constexpr uint32_t object_array_pointer = 0x80136EE0;
    constexpr uint32_t object_size = 0x9C;
    constexpr int max_objects = 2048;
    constexpr uint32_t object_pos = 0x04;
    constexpr uint32_t object_head = 0x18;
    constexpr uint32_t object_scale = 0x38;
    constexpr uint32_t object_yaw = 0x48;
    constexpr uint32_t marker_model = 0x14;
    // PlayerState pointers by player; +0xE4 points at the position, +0x120 at the state block (+4 state).
    constexpr uint32_t player_table = 0x80135490;
    constexpr gpr game_state_addr = (int32_t)0x80127630;
    // Frames to wait after the area loads before spawning.
    constexpr int settle_frames = 30;

    // Banjo's states (the game's state table in core2, ROM 0x1EF1800 on: { u16 state, u16, u32 flags, u32 state
    // functions }, one per state) whose moves hit an enemy: claw swipe 0x06, Beak Buster 0x0F, Rat-a-tat Rap 0x11,
    // Beak Barge 0x13, forward roll 0x31, Bill Drill 0xB6, Kazooie's Wing Whack 0xC2 and 0xC4, Banjo's Pack Whack 0xE4.
    const std::vector<uint32_t> attack_states = { 0x06, 0x0F, 0x11, 0x13, 0x31, 0xB6, 0xC2, 0xC4, 0xE4 };
    // Hurt states (bsow, bskazow) and the current form (0x8012704C: 1 Banjo and Kazooie, 0xA Banjo, 0xB Kazooie).
    constexpr uint32_t state_ow = 0x0E;
    constexpr uint32_t state_kazooie_ow = 0x100;
    constexpr uint32_t form_addr = 0x8012704C;
    constexpr uint32_t hit_kind = 1;
    constexpr uint8_t form_banjo_kazooie = 0x1;
    constexpr uint8_t form_banjo = 0xA;
    constexpr uint8_t form_kazooie = 0xB;
    // Models of Banjo's eggs in flight (from each egg's ActorData, +4): blue, fire, ice, grenade, clockwork,
    // golden, proximity.
    const std::vector<uint16_t> egg_models = { 0x09D7, 0x09C1, 0x09C0, 0x09C2, 0x09C4, 0x09C3, 0x09C5 };
    constexpr uint32_t blue_egg_actor = 0x15A;

    struct Torch {
        float home[3];
        float home_yaw;
        float pos[3];
        float yaw;
        uint32_t marker = 0;
        uint32_t light = 0;
        State state = state_idle;
        float timer = 0.0f;
        float rest = 0.0f;
        float flicker = 0.0f;
        float hop = 0.0f;                       // time into the current hop (one hop per chase animation loop)
        bool hit_this_lunge = false;
        bool gone = false;
    };

    std::vector<Torch> torches;
    uint32_t anim_table = 0;
    uint16_t spawned_in_map = 0;
    uint16_t last_map = 0;
    int frames_in_map = 0;
    uint32_t last_game_ms = 0;
    bool was_on = false;
    bool log_on = false;
    float near_distance = 0.0f;
    std::vector<Spot> env_spots;
    bool env_spots_set = false;
    uint32_t last_player_state = 0;
    bool shots_on = false;
    std::vector<int> shot_frames;

    bool valid_ptr(uint32_t p) {
        return p >= 0x80000000u && p < 0x81000000u;
    }

    uint32_t read_word(uint8_t* rdram, uint32_t addr) {
        return (uint32_t)MEM_W(0, (int32_t)addr);
    }

    float read_float(uint8_t* rdram, uint32_t addr) {
        const uint32_t bits = read_word(rdram, addr);
        float value;
        std::memcpy(&value, &bits, sizeof(value));
        return value;
    }

    uint16_t read_half(uint8_t* rdram, uint32_t addr) {
        const uint32_t word = read_word(rdram, addr & ~3u);
        return (uint16_t)((addr & 2) ? (word & 0xFFFF) : (word >> 16));
    }

    void write_word(uint8_t* rdram, uint32_t addr, uint32_t value) {
        MEM_W(0, (int32_t)addr) = (int32_t)value;
    }

    void write_float(uint8_t* rdram, uint32_t addr, float value) {
        uint32_t bits;
        std::memcpy(&bits, &value, sizeof(bits));
        write_word(rdram, addr, bits);
    }

    uint32_t float_bits(float value) {
        uint32_t bits;
        std::memcpy(&bits, &value, sizeof(bits));
        return bits;
    }

    // Calls a game function with up to four word arguments on a copy of the hook's context, with a scratch
    // area of 0x100 bytes below the stack (returned in scratch) for vectors. Returns $v0.
    struct GameCall {
        uint8_t* rdram;
        recomp_context* ctx;
        recomp_context saved;
        uint32_t scratch;

        GameCall(uint8_t* rdram_, recomp_context* ctx_) : rdram(rdram_), ctx(ctx_), saved(*ctx_) {
            scratch = (((uint32_t)ctx->r29) - 0x200u) & ~0xFu;
            ctx->r29 = (int32_t)(scratch - 0x80u);
        }
        ~GameCall() {
            *ctx = saved;
        }
        gpr operator()(void (*fn)(uint8_t*, recomp_context*), uint32_t a0 = 0, uint32_t a1 = 0, uint32_t a2 = 0, uint32_t a3 = 0) {
            ctx->r29 = (int32_t)(scratch - 0x80u);
            ctx->r4 = (int32_t)a0;
            ctx->r5 = (int32_t)a1;
            ctx->r6 = (int32_t)a2;
            ctx->r7 = (int32_t)a3;
            fn(rdram, ctx);
            return ctx->r2;
        }
        void vec(uint32_t offset, const float v[3]) {
            for (int i = 0; i < 3; i++) {
                write_float(rdram, scratch + offset + 4 * i, v[i]);
            }
        }
    };

    bool option_on() {
        static const bool forced = std::getenv("TOOIE_TORCH") != nullptr;
        if (forced) {
            return true;
        }
        try {
            return std::get<bool>(recompui::config::get_general_config().get_option_value(tooie::torch_enemy::option));
        } catch (...) {
            return false;
        }
    }

    void read_env() {
        static bool read = false;
        if (read) {
            return;
        }
        read = true;
        log_on = std::getenv("TOOIE_TORCH_LOG") != nullptr;
        shots_on = std::getenv("TOOIE_TORCH_SHOTS") != nullptr;
        if (const char* v = std::getenv("TOOIE_TORCH_NEAR")) {
            near_distance = (float)std::atof(v);
            if (near_distance <= 0.0f) {
                near_distance = 300.0f;
            }
        }
        if (const char* v = std::getenv("TOOIE_TORCH_AT")) {
            env_spots_set = true;
            std::stringstream list(v);
            std::string item;
            while (std::getline(list, item, ';')) {
                Spot spot{};
                if (std::sscanf(item.c_str(), "%f,%f,%f,%f", &spot.pos[0], &spot.pos[1], &spot.pos[2], &spot.yaw) >= 3) {
                    env_spots.push_back(spot);
                }
            }
        }
        if (const char* v = std::getenv("TOOIE_TORCH_ANIMS")) {
            std::stringstream list(v);
            std::string item;
            int state = state_idle;
            while (std::getline(list, item, ',') && state < state_count) {
                anims[state++] = (uint16_t)std::strtoul(item.c_str(), nullptr, 16);
            }
        }
    }

    uint32_t player_pointer(uint8_t* rdram) {
        const uint32_t player = read_word(rdram, player_table);
        return valid_ptr(player) ? player : 0;
    }

    bool banjo_position(uint8_t* rdram, float out[3]) {
        const uint32_t player = player_pointer(rdram);
        if (player == 0) {
            return false;
        }
        const uint32_t pos = read_word(rdram, player + 0xE4);
        if (!valid_ptr(pos)) {
            return false;
        }
        for (int i = 0; i < 3; i++) {
            out[i] = read_float(rdram, pos + 4 * i);
        }
        return true;
    }

    float banjo_yaw(uint8_t* rdram) {
        const uint32_t player = player_pointer(rdram);
        if (player == 0) {
            return 0.0f;
        }
        const uint32_t yaw = read_word(rdram, player + 0xF8);
        return valid_ptr(yaw) ? read_float(rdram, yaw) : 0.0f;
    }

    uint32_t banjo_state(uint8_t* rdram) {
        const uint32_t player = player_pointer(rdram);
        if (player == 0) {
            return 0;
        }
        const uint32_t block = read_word(rdram, player + 0x120);
        return valid_ptr(block) ? read_word(rdram, block + 4) : 0;
    }

    // Calls fn(object) for every live object.
    template <typename F>
    void for_each_object(uint8_t* rdram, F fn) {
        const uint32_t array = read_word(rdram, object_array_pointer);
        if (!valid_ptr(array)) {
            return;
        }
        const uint32_t first = read_word(rdram, array + 0x04);
        const uint32_t last = read_word(rdram, array + 0x08);
        if (!valid_ptr(first) || !valid_ptr(last) || last < first) {
            return;
        }
        const int count = (int)((last - first) / object_size) + 1;
        if (count > max_objects) {
            return;
        }
        for (int i = 0; i < count; i++) {
            fn(array + 0x10 + (uint32_t)i * object_size);
        }
    }

    // The object whose +0 is this marker, or 0 when it is gone. The object array moves as objects come and go.
    // The torch's model (asset 0x674) as the game loaded it, found by its header: { 0xB, geometry 0x3A70,
    // textures 0x50, type 2, display list 0x25A8 }. The display list's commands start 8 bytes in, the vertices
    // 0x18 bytes into the vertex block at 0x2F08.
    constexpr uint32_t model_header[4] = { 0x0000000B, 0x00003A70, 0x00500002, 0x000025A8 };
    constexpr uint32_t model_dl = 0x25A8 + 8;
    constexpr uint32_t model_vertices = 0x2F08 + 0x18;
    constexpr uint32_t model_size = 0x3A70;
    uint32_t model_addr = 0;

    bool is_model(uint8_t* rdram, uint32_t addr) {
        for (int i = 0; i < 4; i++) {
            if (read_word(rdram, addr + 4 * i) != model_header[i]) {
                return false;
            }
        }
        return true;
    }

    uint32_t find_model(uint8_t* rdram) {
        if (model_addr != 0 && is_model(rdram, model_addr)) {
            return model_addr;
        }
        model_addr = 0;
        // The game loads it when a torch is first drawn; until then look only now and then.
        static int wait = 0;
        if (wait > 0) {
            wait--;
            return 0;
        }
        wait = 30;
        for (uint32_t addr = 0x80000000; addr < 0x80800000 - model_size; addr += 4) {
            if (read_word(rdram, addr) == model_header[0] && is_model(rdram, addr)) {
                model_addr = addr;
                if (log_on) {
                    printf("[torch] model at 0x%08X\n", addr);
                    fflush(stdout);
                }
                break;
            }
        }
        return model_addr;
    }

    // The eyes: their own 11 vertices (0x710 into the vertices; the display list draws them with the 16x16 eye
    // texture), two little discs on the front of the head, left at x < 0 and right at x > 0, centred at
    // height 71. While a torch waits they are shut: flattened to a line and tucked into the wood. As it wakes
    // they open like eyelids. The model is shared, so the eyes follow the torch nearest Banjo (the torches
    // are thousands of units apart, never in view together).
    constexpr uint32_t eye_vertices = 0x710;
    constexpr int eye_vertex_count = 11;
    constexpr float eye_centre_y = 71.0f;
    constexpr float eye_centre_x = 9.0f;
    constexpr float eye_tuck = 7.0f;            // how far into the head a shut eye goes
    struct EyeVertex {
        int16_t x, y, z;
    };
    EyeVertex eye_original[eye_vertex_count];
    uint32_t eye_model = 0;                     // the model eye_original was read from
    float eye_open = 0.0f;
    float eye_written = -1.0f;

    void eye_write(uint8_t* rdram, float open) {
        if (find_model(rdram) == 0) {
            eye_model = 0;
            return;
        }
        const uint32_t base = model_addr + model_vertices + eye_vertices;
        if (eye_model != model_addr) {
            for (int i = 0; i < eye_vertex_count; i++) {
                const uint32_t w0 = read_word(rdram, base + 16 * i);
                const uint32_t w1 = read_word(rdram, base + 16 * i + 4);
                eye_original[i] = { (int16_t)(w0 >> 16), (int16_t)(w0 & 0xFFFF), (int16_t)(w1 >> 16) };
            }
            eye_model = model_addr;
            eye_written = -1.0f;
        }
        if (open == eye_written) {
            return;
        }
        eye_written = open;
        // Eased so they start opening slowly and widen quickly, like an eyelid.
        const float f = open * open * (3.0f - 2.0f * open);
        for (int i = 0; i < eye_vertex_count; i++) {
            const EyeVertex& v = eye_original[i];
            const float cx = v.x < 0 ? -eye_centre_x : v.x > 0 ? eye_centre_x : 0.0f;
            const float x = cx + (v.x - cx) * (0.4f + 0.6f * f);
            const float y = eye_centre_y + (v.y - eye_centre_y) * f;
            const float z = v.z - (1.0f - f) * eye_tuck;
            const uint32_t w0 = ((uint32_t)(uint16_t)(int16_t)std::lround(x) << 16) | (uint16_t)(int16_t)std::lround(y);
            const uint32_t w1 = read_word(rdram, base + 16 * i + 4);
            write_word(rdram, base + 16 * i, w0);
            write_word(rdram, base + 16 * i + 4, ((uint32_t)(uint16_t)(int16_t)std::lround(z) << 16) | (w1 & 0xFFFF));
        }
    }

    // Puts the eyes back as the model has them (the option turned off with the model still loaded).
    void eye_restore(uint8_t* rdram) {
        if (eye_model != 0 && eye_model == model_addr && is_model(rdram, model_addr)) {
            eye_write(rdram, 1.0f);
        }
        eye_model = 0;
        eye_open = 0.0f;
    }

    uint32_t find_object(uint8_t* rdram, uint32_t marker) {
        uint32_t found = 0;
        for_each_object(rdram, [&](uint32_t object) {
            if (found == 0 && read_word(rdram, object) == marker) {
                found = object;
            }
        });
        return found;
    }

    float distance_xz(const float a[3], const float b[3]) {
        const float dx = b[0] - a[0], dz = b[2] - a[2];
        return std::sqrt(dx * dx + dz * dz);
    }

    float distance(const float a[3], const float b[3]) {
        const float dx = b[0] - a[0], dy = b[1] - a[1], dz = b[2] - a[2];
        return std::sqrt(dx * dx + dy * dy + dz * dz);
    }

    // Yaw (degrees) facing from a to b, as the game measures it (0 faces +z).
    float yaw_towards(const float a[3], const float b[3]) {
        return std::atan2(b[0] - a[0], b[2] - a[2]) * 180.0f / 3.14159265f;
    }

    float turn_towards(float from, float to, float step) {
        float diff = std::fmod(to - from + 540.0f, 360.0f) - 180.0f;
        diff = std::clamp(diff, -step, step);
        return std::fmod(from + diff + 360.0f, 360.0f);
    }

    const char* state_name(State s) {
        switch (s) {
            case state_idle: return "idle";
            case state_chase: return "chase";
            case state_lunge: return "lunge";
            case state_beaten: return "beaten";
            case state_return: return "return";
            case state_wake: return "wake";
            default: return "?";
        }
    }

    // The torch's animation table, in the game's heap: { f32 duration, u16 animation, u16 playback } per
    // state. Made once per area; freed when the area changes.
    bool make_anim_table(uint8_t* rdram, recomp_context* ctx) {
        if (anim_table != 0) {
            return true;
        }
        GameCall call(rdram, ctx);
        const uint32_t table = (uint32_t)call(heap_alloc, 8 * state_count);
        if (!valid_ptr(table)) {
            return false;
        }
        for (int s = 0; s < state_count; s++) {
            write_float(rdram, table + 8 * s, anim_durations[s]);
            write_word(rdram, table + 8 * s + 4, (uint32_t)anims[s] << 16);
        }
        anim_table = table;
        return true;
    }

    void free_anim_table(uint8_t* rdram, recomp_context* ctx) {
        if (anim_table == 0) {
            return;
        }
        GameCall call(rdram, ctx);
        call(heap_free, anim_table);
        anim_table = 0;
    }

    void play_boing(uint8_t* rdram, recomp_context* ctx, const float pos[3], float volume);

    void set_state(uint8_t* rdram, recomp_context* ctx, Torch& t, uint32_t object, State s) {
        if (t.state == s) {
            return;
        }
        if (log_on) {
            printf("[torch] %u ms: %s -> %s at %.0f %.0f %.0f\n", tooie::game_frame_rate::game_ms(), state_name(t.state), state_name(s), t.pos[0], t.pos[1], t.pos[2]);
            fflush(stdout);
        }
        t.state = s;
        t.timer = 0.0f;
        if (shots_on) {
            tooie::screenshot::take();
        }
        {
            GameCall call(rdram, ctx);
            call(func_80101FDC, object, s);
        }
        if (s == state_chase || s == state_return || s == state_lunge) {
            t.hop = 0.0f;
            play_boing(rdram, ctx, t.pos, s == state_return ? 0.7f : 1.0f);
        }
    }

    void light_update(uint8_t* rdram, recomp_context* ctx, Torch& t, float scale) {
        if (t.light == 0) {
            return;
        }
        // A fire's flicker: two waves and a little noise.
        const float f = 0.82f + 0.10f * std::sin(t.flicker * 9.0f) + 0.06f * std::sin(t.flicker * 23.0f + 1.3f) +
            0.02f * (float)(std::rand() % 100) / 100.0f;
        GameCall call(rdram, ctx);
        const float at[3] = { t.pos[0], t.pos[1] + light_height * scale, t.pos[2] };
        call.vec(0, at);
        call(func_800C8CB8, t.light, call.scratch);
        call(func_800C8E54, t.light, float_bits(light_inner * scale * f), float_bits(light_outer * scale * f));
        call(func_800C8FB0, t.light, (uint32_t)(light_rgb[0] * f), (uint32_t)(light_rgb[1] * f), (uint32_t)(light_rgb[2] * f));
    }

    void free_light(uint8_t* rdram, recomp_context* ctx, Torch& t) {
        if (t.light == 0) {
            return;
        }
        GameCall call(rdram, ctx);
        call(func_800C8B84, t.light);
        t.light = 0;
    }

    void spawn_torch(uint8_t* rdram, recomp_context* ctx, const Spot& spot) {
        if (!make_anim_table(rdram, ctx)) {
            fprintf(stderr, "[torch] no room in the game's heap for the animation table\n");
            return;
        }
        GameCall call(rdram, ctx);
        // Loads the overlay if it is not loaded and returns its ActorData; give it the animation table.
        const uint32_t actor_data = (uint32_t)call(_chstatictorch_entrypoint_0);
        if (!valid_ptr(actor_data)) {
            fprintf(stderr, "[torch] torch overlay not found\n");
            return;
        }
        write_word(rdram, actor_data + 0x08, anim_table);
        if (log_on) {
            printf("[torch] ActorData 0x%08X, animation table 0x%08X\n", actor_data, anim_table);
            fflush(stdout);
        }
        call.vec(0, spot.pos);
        const uint32_t object = (uint32_t)call(func_80108474, torch_actor, call.scratch, (uint32_t)(int32_t)spot.yaw);
        if (!valid_ptr(object)) {
            fprintf(stderr, "[torch] the game did not spawn the torch\n");
            return;
        }
        Torch t;
        std::memcpy(t.home, spot.pos, sizeof(t.home));
        std::memcpy(t.pos, spot.pos, sizeof(t.pos));
        t.home_yaw = spot.yaw;
        t.yaw = spot.yaw;
        t.marker = read_word(rdram, object);
        t.flicker = (float)(torches.size() * 1.7);
        t.state = state_none;
        t.light = (uint32_t)call(func_800C8A98);
        if (log_on) {
            printf("[torch] object 0x%08X, marker 0x%08X, light %u\n", object, t.marker, t.light);
            fflush(stdout);
        }
        torches.push_back(t);
        set_state(rdram, ctx, torches.back(), object, state_idle);
        light_update(rdram, ctx, torches.back(), 1.0f);
        if (log_on) {
            const uint32_t anim_ctrl = (uint32_t)call(func_80101F24, object);
            printf("[torch] spawned at %.0f %.0f %.0f (object 0x%08X, marker 0x%08X, model 0x%04X, light %u, anim ctrl 0x%08X)\n",
                spot.pos[0], spot.pos[1], spot.pos[2], object, t.marker,
                valid_ptr(t.marker) ? (unsigned)read_half(rdram, t.marker + marker_model) : 0u,
                t.light, anim_ctrl);
            for (uint32_t i = 0; i < 0x30; i += 4) {
                printf("[torch] marker +0x%02X: 0x%08X\n", i, read_word(rdram, t.marker + i));
            }
            fflush(stdout);
        }
    }

    void despawn_all(uint8_t* rdram, recomp_context* ctx, bool objects_live) {
        for (Torch& t : torches) {
            if (objects_live && !t.gone) {
                const uint32_t object = find_object(rdram, t.marker);
                if (object != 0) {
                    GameCall call(rdram, ctx);
                    call(func_800FFAB0, object);
                }
                free_light(rdram, ctx, t);
            }
        }
        torches.clear();
        if (objects_live) {
            eye_restore(rdram);
        }
    }

    // Moves the torch: the object's position and its head (where the flame is drawn) by the same amount.
    void move_object(uint8_t* rdram, uint32_t object, Torch& t, const float to[3]) {
        for (int i = 0; i < 3; i++) {
            const float delta = to[i] - read_float(rdram, object + object_pos + 4 * i);
            write_float(rdram, object + object_pos + 4 * i, to[i]);
            write_float(rdram, object + object_head + 4 * i, read_float(rdram, object + object_head + 4 * i) + delta);
            t.pos[i] = to[i];
        }
        write_float(rdram, object + object_yaw, t.yaw);
    }

    bool banjo_hurt(uint8_t* rdram) {
        const uint32_t state = banjo_state(rdram);
        return state == state_ow || state == state_kazooie_ow;
    }

    // Floor under a point, by the game's camera line test: keeps the torch on the ground as it follows
    // Banjo down slopes. The test sweeps a 45-unit ball, so the hit point is that far above the floor.
    bool floor_below(uint8_t* rdram, recomp_context* ctx, const float at[3], float& floor_y) {
        const float from[3] = { at[0], at[1] + 120.0f, at[2] };
        float to[3] = { at[0], at[1] - 600.0f, at[2] };
        float normal[3];
        if (!tooie::free_camera::sweep_line(rdram, ctx, from, to, normal) || normal[1] < 0.5f) {
            return false;
        }
        floor_y = to[1] - 45.0f;
        return true;
    }

    // Faces a spot out from the wall behind it: line tests out in 32 directions at chest height, and the
    // normals of the walls they hit close by, the nearest counting most (in a corner it faces out between the
    // two walls). The spot itself stays where it is; it should already be up against the wall.
    bool face_off_wall(uint8_t* rdram, recomp_context* ctx, Spot& spot) {
        constexpr float reach = 300.0f;
        constexpr float close = 100.0f;
        constexpr float height = 80.0f;
        float sum_x = 0.0f;
        float sum_z = 0.0f;
        for (int i = 0; i < 32; i++) {
            const float rad = (float)i * 3.14159265f * 2.0f / 32.0f;
            const float from[3] = { spot.pos[0], spot.pos[1] + height, spot.pos[2] };
            float to[3] = { from[0] + std::sin(rad) * reach, from[1], from[2] + std::cos(rad) * reach };
            float normal[3];
            if (!tooie::free_camera::sweep_line(rdram, ctx, from, to, normal) || std::fabs(normal[1]) > 0.5f) {
                continue;
            }
            const float dx = to[0] - from[0];
            const float dz = to[2] - from[2];
            const float dist = std::sqrt(dx * dx + dz * dz);
            if (dist < close) {
                const float weight = 1.0f / (dist + 10.0f);
                sum_x += normal[0] * weight;
                sum_z += normal[2] * weight;
            }
        }
        if (sum_x * sum_x + sum_z * sum_z < 1e-6f) {
            return false;
        }
        spot.yaw = std::fmod(std::atan2(sum_x, sum_z) * 180.0f / 3.14159265f + 360.0f, 360.0f);
        return true;
    }

    bool banjo_attacking(uint8_t* rdram, const float torch_pos[3], const float banjo[3]) {
        if (distance(torch_pos, banjo) > attack_range) {
            return false;
        }
        const uint32_t state = banjo_state(rdram);
        return std::find(attack_states.begin(), attack_states.end(), state) != attack_states.end();
    }

    // An egg near the torch: removes the egg too, as hitting an enemy does.
    bool egg_hit(uint8_t* rdram, recomp_context* ctx, const float torch_pos[3]) {
        uint32_t egg = 0;
        for_each_object(rdram, [&](uint32_t object) {
            if (egg != 0) {
                return;
            }
            const uint32_t marker = read_word(rdram, object);
            if (!valid_ptr(marker)) {
                return;
            }
            const uint16_t model = read_half(rdram, marker + marker_model);
            if (std::find(egg_models.begin(), egg_models.end(), model) == egg_models.end()) {
                return;
            }
            float p[3];
            for (int i = 0; i < 3; i++) {
                p[i] = read_float(rdram, object + object_pos + 4 * i);
            }
            const float centre[3] = { torch_pos[0], torch_pos[1] + 40.0f, torch_pos[2] };
            if (distance(p, centre) < egg_range) {
                egg = object;
            }
        });
        if (egg == 0) {
            return false;
        }
        GameCall call(rdram, ctx);
        call(func_800FFAB0, egg);
        return true;
    }

    // One honeycomb, through the game's own health change, then the hurt state (it knocks Banjo back and
    // flashes him, as any enemy's hit does): 0x0E for Banjo and Kazooie together, 0x100 for Kazooie alone.
    // bs_setState(PlayerState, state) switches Banjo's state as the game's own moves do.
    // A boing as it hops, as Banjo-Kazooie's Flotsam boings on every bounce: the Springy Step Shoes' jump sound
    // (0x4598, as bskazshoesspringjump plays it), through func_800C401C(sound, pitch, volume, position, near,
    // far, 2), the game's sound at a place (func_800C4140 unpacks into it), heard up to boing_far away.
    constexpr uint32_t boing_sound = 0x4598;
    constexpr float boing_near = 150.0f;
    constexpr float boing_far = 1800.0f;

    uint32_t play_sound(uint8_t* rdram, recomp_context* ctx, uint32_t sound, const float pos[3], float pitch, float volume, float near_dist, float far_dist) {
        GameCall call(rdram, ctx);
        call.vec(0, pos);
        const uint32_t sp = call.scratch - 0x80u;
        write_float(rdram, sp + 0x10, near_dist);
        write_float(rdram, sp + 0x14, far_dist);
        write_word(rdram, sp + 0x18, 2);
        uint32_t pitch_bits;
        std::memcpy(&pitch_bits, &pitch, 4);
        return (uint32_t)call(func_800C401C, sound, pitch_bits, (uint32_t)(0x7FFF * std::clamp(volume, 0.0f, 1.0f)), call.scratch);
    }

    void play_boing(uint8_t* rdram, recomp_context* ctx, const float pos[3], float volume) {
        const float pitch = 0.95f + 0.15f * (float)(std::rand() % 100) / 100.0f;
        const uint32_t handle = play_sound(rdram, ctx, boing_sound, pos, pitch, volume, boing_near, boing_far);
        if (log_on) {
            printf("[torch] boing (sound handle %u)\n", handle);
            fflush(stdout);
        }
    }

    // DEV > Sound test: plays the game's sound (0x4000 | number) at Banjo whenever the number changes, to find
    // one by ear. It plays like func_800C401C but keeps the voice, so the last one is stopped (func_800C3CE8)
    // before the next starts; looping sounds would otherwise pile up.
    std::atomic<int> sound_test_pending{ -1 };
    uint32_t sound_test_voice = 0;

    void sound_test_tick(uint8_t* rdram, recomp_context* ctx) {
        const int number = sound_test_pending.exchange(-1);
        float at[3];
        if (number < 0 || !banjo_position(rdram, at)) {
            return;
        }
        GameCall call(rdram, ctx);
        if (sound_test_voice != 0) {
            call(func_800C3CE8, sound_test_voice);
        }
        sound_test_voice = (uint32_t)call(func_800C2E04) & 0xFF;
        if (sound_test_voice == 0) {
            return;
        }
        const float values[3] = { 1.0f, 5000.0f, 10000.0f };
        uint32_t bits[3];
        std::memcpy(bits, values, sizeof(bits));
        call(func_800C3418, sound_test_voice, 2);
        call(func_800C301C, sound_test_voice, 0x4000u | (uint32_t)number);
        call(func_800C3058, sound_test_voice, 0x7FFF);
        call(func_800C31DC, sound_test_voice, bits[0]);
        call(func_800C3584, sound_test_voice, bits[1], bits[2]);
        call.vec(0, at);
        call(func_800C35E8, sound_test_voice, call.scratch);
        call(func_800C330C, sound_test_voice, 1);
        call(func_800C33DC, sound_test_voice, 1);
        call(func_800C36F4, sound_test_voice, 0);
        printf("[sound test] 0x%04X\n", 0x4000 | number);
        fflush(stdout);
    }

    void burn_banjo(uint8_t* rdram, recomp_context* ctx, const float torch_pos[3]) {
        const uint32_t player = player_pointer(rdram);
        if (player == 0) {
            return;
        }
        {
            GameCall call(rdram, ctx);
            call(func_800A17A8, player, (uint32_t)-1);
        }
        const uint32_t block = read_word(rdram, player + 0x120);
        const uint8_t form = (uint8_t)(read_word(rdram, form_addr & ~3u) >> (8 * (3 - (form_addr & 3))));
        uint32_t hurt = 0;
        if (form == form_banjo_kazooie || form == form_banjo) {
            hurt = state_ow;
        }
        else if (form == form_kazooie) {
            hurt = state_kazooie_ow;
        }
        const uint32_t hit_info = read_word(rdram, player + 0xC0);
        if (valid_ptr(block) && hurt != 0) {
            GameCall call(rdram, ctx);
            // Where the hit came from (func_800A34AC, read back by the bounce in bsow): knocks him away from the torch.
            call.vec(0, torch_pos);
            call(func_800A34AC, player, call.scratch);
            // The kind of hit (func_8009AD20 writes it): sets how far bsow's bounce throws him. Left at 0 the
            // bounce never settles and Banjo stays frozen in the hurt pose.
            call(func_8009AD20, player, hit_kind);
            call(bs_setState, player, hurt);
        }
        if (shots_on) {
            shot_frames = { 3, 8, 14, 22 };
        }
        if (log_on) {
            printf("[torch] burned Banjo (form %u, now state %u, hit type %u)\n", form, valid_ptr(block) ? read_word(rdram, block + 4) : 0,
                valid_ptr(hit_info) ? read_word(rdram, hit_info + 0x18) : 0);
            fflush(stdout);
        }
    }

    void log_neighbours(uint8_t* rdram, const Torch& t) {
        static uint32_t last = 0;
        const uint32_t now = tooie::game_frame_rate::game_ms();
        if (now - last < 1000) {
            return;
        }
        last = now;
        for_each_object(rdram, [&](uint32_t object) {
            const uint32_t marker = read_word(rdram, object);
            if (!valid_ptr(marker) || marker == t.marker) {
                return;
            }
            float p[3];
            for (int i = 0; i < 3; i++) {
                p[i] = read_float(rdram, object + object_pos + 4 * i);
            }
            if (distance(p, t.pos) < 600.0f) {
                printf("[torch] near: model 0x%04X at %.0f %.0f %.0f\n", (unsigned)read_half(rdram, marker + marker_model), p[0], p[1], p[2]);
            }
        });
        fflush(stdout);
    }

    void update_torch(uint8_t* rdram, recomp_context* ctx, Torch& t, float dt, bool have_banjo, const float banjo[3]) {
        const uint32_t object = find_object(rdram, t.marker);
        if (object == 0) {
            // Gone by itself (the game removed it).
            free_light(rdram, ctx, t);
            t.gone = true;
            return;
        }
        t.timer += dt;
        // One boing per hop while it hops along (the chase and return animations loop once a hop).
        if (t.state == state_chase || t.state == state_return) {
            t.hop += dt;
            if (t.hop >= anim_durations[t.state]) {
                t.hop -= anim_durations[t.state];
                play_boing(rdram, ctx, t.pos, t.state == state_return ? 0.7f : 1.0f);
            }
        }
        t.flicker += dt;
        t.rest = std::max(0.0f, t.rest - dt);
        if (log_on) {
            log_neighbours(rdram, t);
            static uint32_t last = 0;
            const uint32_t now = tooie::game_frame_rate::game_ms();
            if (now - last >= 1000) {
                last = now;
                printf("[torch] at %.0f %.0f %.0f yaw %.0f (%s), Banjo %.0f %.0f %.0f, dt %.3f, scale %.2f\n", t.pos[0], t.pos[1], t.pos[2], t.yaw,
                    state_name(t.state), banjo[0], banjo[1], banjo[2], dt, read_float(rdram, object + object_scale));
                fflush(stdout);
            }
        }

        if (t.state == state_beaten) {
            const float left = 1.0f - t.timer / beaten_time;
            if (left <= 0.0f) {
                free_light(rdram, ctx, t);
                GameCall call(rdram, ctx);
                call(func_800FFAB0, object);
                t.gone = true;
                return;
            }
            write_float(rdram, object + object_scale, std::max(0.05f, left));
            light_update(rdram, ctx, t, left);
            return;
        }

        if (have_banjo && (banjo_attacking(rdram, t.pos, banjo) || egg_hit(rdram, ctx, t.pos))) {
            set_state(rdram, ctx, t, object, state_beaten);
            light_update(rdram, ctx, t, 1.0f);
            return;
        }

        float to[3] = { t.pos[0], t.pos[1], t.pos[2] };
        const float from_home = distance_xz(t.pos, t.home);
        const float to_banjo = have_banjo ? distance_xz(t.pos, banjo) : 1e9f;
        const float banjo_from_home = have_banjo ? distance_xz(t.home, banjo) : 1e9f;

        switch (t.state) {
            case state_idle:
            default:
                // Plays an ordinary torch: no movement, no turning, until Banjo walks right up to it. Then it
                // springs straight at him.
                if (have_banjo && to_banjo < ambush_range && std::fabs(banjo[1] - t.pos[1]) < 150.0f) {
                    set_state(rdram, ctx, t, object, state_wake);
                    if (shots_on) {
                        shot_frames = { 4, 8, 12 };
                    }
                }
                break;
            case state_wake:
                // Its eyes open (eye_update) as it turns to him; then it springs.
                if (have_banjo) {
                    t.yaw = turn_towards(t.yaw, yaw_towards(t.pos, banjo), turn_speed * 1.5f * dt);
                }
                if (t.timer >= wake_time) {
                    if (have_banjo) {
                        t.yaw = yaw_towards(t.pos, banjo);
                    }
                    t.hit_this_lunge = false;
                    set_state(rdram, ctx, t, object, state_lunge);
                }
                break;
            case state_return:
                if (have_banjo && to_banjo < notice_range && banjo_from_home < leash) {
                    set_state(rdram, ctx, t, object, state_chase);
                    break;
                }
                if (from_home > 5.0f) {
                    const float step = std::min(from_home, return_speed * dt);
                    t.yaw = turn_towards(t.yaw, yaw_towards(t.pos, t.home), turn_speed * dt);
                    to[0] += (t.home[0] - t.pos[0]) / from_home * step;
                    to[2] += (t.home[2] - t.pos[2]) / from_home * step;
                }
                else {
                    // Home: faces the way it stood and goes still again.
                    t.yaw = turn_towards(t.yaw, t.home_yaw, turn_speed * dt);
                    if (std::fabs(std::remainder(t.yaw - t.home_yaw, 360.0f)) < 1.0f) {
                        t.yaw = t.home_yaw;
                        set_state(rdram, ctx, t, object, state_idle);
                    }
                }
                break;
            case state_chase: {
                if (!have_banjo || to_banjo > give_up_range || banjo_from_home > leash + 200.0f) {
                    set_state(rdram, ctx, t, object, state_return);
                    break;
                }
                const float want = yaw_towards(t.pos, banjo);
                t.yaw = turn_towards(t.yaw, want, turn_speed * dt);
                if (to_banjo < lunge_range && t.rest <= 0.0f) {
                    t.yaw = want;
                    t.hit_this_lunge = false;
                    set_state(rdram, ctx, t, object, state_lunge);
                    break;
                }
                if (t.rest > lunge_rest) {
                    // Just burned him: backs away while he gets up.
                    const float rad = want * 3.14159265f / 180.0f;
                    to[0] -= std::sin(rad) * back_off_speed * dt;
                    to[2] -= std::cos(rad) * back_off_speed * dt;
                }
                else if (to_banjo > hit_range) {
                    const float step = std::min(to_banjo - hit_range, chase_speed * dt);
                    const float rad = t.yaw * 3.14159265f / 180.0f;
                    to[0] += std::sin(rad) * step;
                    to[2] += std::cos(rad) * step;
                }
                break;
            }
            case state_lunge: {
                if (t.timer >= lunge_time) {
                    t.rest = std::max(t.rest, lunge_rest);
                    set_state(rdram, ctx, t, object, state_chase);
                    break;
                }
                const float rad = t.yaw * 3.14159265f / 180.0f;
                to[0] += std::sin(rad) * lunge_speed * dt;
                to[2] += std::cos(rad) * lunge_speed * dt;
                if (have_banjo && !t.hit_this_lunge && distance_xz(to, banjo) < hit_range && std::fabs(banjo[1] - t.pos[1]) < 150.0f) {
                    t.hit_this_lunge = true;
                    // Not while he is still reeling from the last one.
                    if (!banjo_hurt(rdram)) {
                        burn_banjo(rdram, ctx, t.pos);
                        t.rest = hit_rest;
                        set_state(rdram, ctx, t, object, state_chase);
                        to[0] = t.pos[0];
                        to[2] = t.pos[2];
                    }
                }
                break;
            }
        }

        // Never past the leash.
        const float out = distance_xz(to, t.home);
        if (out > leash) {
            to[0] = t.home[0] + (to[0] - t.home[0]) / out * leash;
            to[2] = t.home[2] + (to[2] - t.home[2]) / out * leash;
        }
        // On the ground: down slopes with Banjo, never off a ledge or into the water.
        if (to[0] != t.pos[0] || to[2] != t.pos[2]) {
            float floor_y;
            const bool found = floor_below(rdram, ctx, to, floor_y);
            if (found && std::fabs(floor_y - t.pos[1]) < max_step) {
                to[1] = floor_y;
            }
            else {
                if (log_on) {
                    static uint32_t last = 0;
                    const uint32_t now = tooie::game_frame_rate::game_ms();
                    if (now - last >= 1000) {
                        last = now;
                        printf("[torch] no floor to step on at %.0f %.0f (found %d, floor %.0f)\n", to[0], to[2], found, found ? floor_y : 0.0f);
                    }
                }
                to[0] = t.pos[0];
                to[1] = t.pos[1];
                to[2] = t.pos[2];
            }
        }
        move_object(rdram, object, t, to);
        light_update(rdram, ctx, t, 1.0f);
    }

    // TOOIE_MAP_FILE_DUMP (see the top).
    void dump_map_files(uint8_t* rdram, recomp_context* ctx) {
        static bool done = false;
        const char* dir = std::getenv("TOOIE_MAP_FILE_DUMP");
        if (done || dir == nullptr) {
            return;
        }
        done = true;
        std::span<const uint8_t> rom = recomp::get_rom();
        auto word = [&](uint32_t at) -> uint32_t {
            return at + 4 <= rom.size() ? ((uint32_t)rom[at] << 24) | ((uint32_t)rom[at + 1] << 16) | ((uint32_t)rom[at + 2] << 8) | rom[at + 3] : 0;
        };
        constexpr uint32_t table_rom = 0x5180;
        const uint32_t count = word(table_rom);
        int written = 0;
        for (uint32_t id = 0; id + 1 < count && id < 0x4000; id++) {
            const uint32_t w = word(table_rom + 8 + id * 4);
            const uint32_t next = word(table_rom + 8 + (id + 1) * 4);
            if ((w & 0xF) != 10 || (next >> 6) <= (w >> 6)) {
                continue;
            }
            GameCall call(rdram, ctx);
            write_word(rdram, call.scratch, 0);
            const uint32_t data = (uint32_t)call(_gldbDll_entrypoint_0, id, call.scratch);
            const uint32_t size = read_word(rdram, call.scratch);
            if (!valid_ptr(data) || size == 0 || size > 0x100000) {
                continue;
            }
            char path[512];
            std::snprintf(path, sizeof(path), "%s/map_%04X.bin", dir, id);
            if (FILE* f = std::fopen(path, "wb")) {
                for (uint32_t i = 0; i < size; i++) {
                    std::fputc((uint8_t)MEM_B((int32_t)i, (int32_t)data), f);
                }
                std::fclose(f);
                written++;
            }
            call(heap_free, data);
        }
        printf("[torch] wrote %d map files to %s\n", written, dir);
        fflush(stdout);
    }

    std::vector<Spot> spots_for(uint8_t* rdram, uint16_t map) {
        std::vector<Spot> spots;
        if (env_spots_set) {
            // Test spots: in the caves, or anywhere when a torch is also put in front of Banjo.
            if (map == flooded_caves_map || near_distance > 0.0f) {
                spots = env_spots;
            }
        }
        else if (map == flooded_caves_map && near_distance <= 0.0f) {
            spots.assign(std::begin(cave_spots), std::end(cave_spots));
        }
        float banjo[3];
        if (near_distance > 0.0f && banjo_position(rdram, banjo)) {
            const float rad = banjo_yaw(rdram) * 3.14159265f / 180.0f;
            Spot spot{};
            spot.pos[0] = banjo[0] + std::sin(rad) * near_distance;
            spot.pos[1] = banjo[1];
            spot.pos[2] = banjo[2] + std::cos(rad) * near_distance;
            spot.yaw = std::fmod(banjo_yaw(rdram) + 180.0f, 360.0f);
            spots.push_back(spot);
        }
        return spots;
    }
}

void tooie::torch_enemy::add_option(recomp::config::Config& general) {
    general.add_bool_option(option, "Cut Content: Torch enemy",
        "Level: Glitter Gulch Mine. The angry torch cut from the game, back where it was meant to be. It stands "
        "still like an ordinary lit torch until Banjo walks up to it, then opens its eyes and springs at him to "
        "burn him, and chases him. Attacks and eggs put it out.",
        false);
}

void tooie::torch_enemy::add_sound_test_option(recomp::config::Config& dev) {
    dev.add_number_option(sound_test_option, "Sound test",
        "Plays one of the game's sound effects at Banjo each time the number changes, to find a sound by ear "
        "(step through with the arrows). Tell Claude the number. Only while playing in a level.",
        0, 2047, 1, 0, false, 0);
    dev.add_option_change_callback(sound_test_option,
        [](recomp::config::ConfigValueVariant value, recomp::config::ConfigValueVariant, recomp::config::OptionChangeContext context) {
            const auto* number = std::get_if<double>(&value);
            if (context != recomp::config::OptionChangeContext::Load && number != nullptr) {
                sound_test_pending = (int)*number;
            }
        });
}

void tooie::torch_enemy::tick(uint8_t* rdram, recomp_context* ctx) {
    read_env();
    const uint32_t now = tooie::game_frame_rate::game_ms();
    const float dt = std::clamp((float)(now - last_game_ms) / 1000.0f, 0.0f, 0.1f);
    last_game_ms = now;

    if (!tooie::debug::can_warp()) {
        // Title screen, file select or a reset: the objects and lights are gone with the area.
        torches.clear();
        anim_table = 0;
        spawned_in_map = 0;
        frames_in_map = 0;
        return;
    }
    sound_test_tick(rdram, ctx);

    dump_map_files(rdram, ctx);
    const bool on = option_on();
    const uint16_t map = tooie::debug::current_map(rdram);
    const bool changing = tooie::debug::map_change_busy(rdram);

    if (log_on) {
        const uint32_t state = banjo_state(rdram);
        if (state != last_player_state) {
            printf("[torch] Banjo state %u\n", state);
            fflush(stdout);
            last_player_state = state;
        }
    }

    // Leaving the area (or the option going off): the torches go, and with the area their lights and the table.
    if (map != last_map || changing) {
        if (!torches.empty() || anim_table != 0) {
            despawn_all(rdram, ctx, map == last_map);
            free_anim_table(rdram, ctx);
        }
        spawned_in_map = 0;
        frames_in_map = 0;
        last_map = map;
        if (changing) {
            return;
        }
    }
    if (on != was_on) {
        was_on = on;
        if (!on) {
            despawn_all(rdram, ctx, true);
            free_anim_table(rdram, ctx);
            spawned_in_map = 0;
        }
    }
    if (!on) {
        return;
    }

    frames_in_map++;
    if (spawned_in_map != map && frames_in_map >= settle_frames && !tooie::in_letterboxed_scene()) {
        spawned_in_map = map;
        for (Spot spot : spots_for(rdram, map)) {
            float floor_y;
            const bool found = floor_below(rdram, ctx, spot.pos, floor_y);
            if (log_on) {
                printf("[torch] spot %.0f %.0f %.0f: floor %s %.0f\n", spot.pos[0], spot.pos[1], spot.pos[2], found ? "at" : "not found", found ? floor_y : 0.0f);
            }
            if (found) {
                spot.pos[1] = floor_y;
            }
            if (!env_spots_set && face_off_wall(rdram, ctx, spot) && log_on) {
                printf("[torch] against the wall at %.0f %.0f %.0f, facing %.0f\n", spot.pos[0], spot.pos[1], spot.pos[2], spot.yaw);
            }
            spawn_torch(rdram, ctx, spot);
        }
    }
    if (torches.empty() || tooie::in_letterboxed_scene()) {
        return;
    }

    // Eyes: open while the torch nearest Banjo is awake, shut while it waits.
    {
        const Torch* nearest = nullptr;
        float best = 1e9f;
        float banjo_now[3];
        const bool banjo_known = banjo_position(rdram, banjo_now);
        for (const Torch& t : torches) {
            const float d = banjo_known ? distance(t.pos, banjo_now) : 0.0f;
            if (!t.gone && d < best) {
                best = d;
                nearest = &t;
            }
        }
        const float target = nearest != nullptr && nearest->state != state_idle ? 1.0f : 0.0f;
        const float step = eye_speed * dt;
        eye_open = std::clamp(target > eye_open ? std::min(target, eye_open + step) : std::max(target, eye_open - step), 0.0f, 1.0f);
        if (nearest != nullptr) {
            eye_write(rdram, eye_open);
        }
    }

    // TOOIE_TORCH_EGG_AT (see the top): a blue egg put down on the first torch, to test that eggs put it out.
    static const char* egg_at = std::getenv("TOOIE_TORCH_EGG_AT");
    static bool egg_done = false;
    if (egg_at != nullptr && !egg_done && now >= (uint32_t)std::atoi(egg_at) && !torches[0].gone) {
        egg_done = true;
        GameCall call(rdram, ctx);
        const float at[3] = { torches[0].pos[0], torches[0].pos[1] + 40.0f, torches[0].pos[2] };
        call.vec(0, at);
        const uint32_t egg = (uint32_t)call(func_80108474, blue_egg_actor, call.scratch, 0);
        printf("[torch] test egg at %.0f %.0f %.0f: object 0x%08X\n", at[0], at[1], at[2], egg);
        fflush(stdout);
    }

    for (int& f : shot_frames) {
        if (f > 0 && --f == 0) {
            tooie::screenshot::take();
        }
    }
    float banjo[3];
    const bool have_banjo = banjo_position(rdram, banjo);
    for (Torch& t : torches) {
        if (!t.gone) {
            update_torch(rdram, ctx, t, dt, have_banjo, banjo);
        }
    }
}
