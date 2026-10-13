// Stable matrix ids for frame interpolation (handoff 4.15).
//
// Above the Original frame rate RT64 draws extra frames between the game's own
// by blending each matrix from its previous value to its current one. Without
// help it has to guess which matrix of the last frame each new one continues,
// and for skinned characters such as Banjo, whose every bone is a separate
// world-space matrix with near-identical neighbours, it guesses wrong: limbs
// borrow each other's motion and the model tears or stretches between frames.
//
// After the game has written the 3D scene for a frame (hide_hud.cpp's first
// mark), this walks the scene's top-level display list. Each model the game
// draws starts by pointing segment 1 at its vertices and then loads one
// matrix per bone before calling its geometry. Every such matrix load is
// replaced by a call to a three-command list: an RT64 matrix group with an id
// made from the model (its first geometry list), which copy of that model it
// is, and the bone's position in the model, followed by the original load. A
// copy keeps its id from frame to frame by being matched to the nearest copy
// of the same model in the last frame; one that jumps further than a teleport
// distance gets a new id, so it is not smeared across the jump. Matrices
// outside a model, such as the camera's, keep RT64's automatic matching.
// On the game select screen every matrix is drawn as the game left it (see
// below), so the portraits shake as they do at 30 fps. Character shadows,
// which the game places through the projection matrix, are rewritten to
// place their bones instead (see ShadowScan).
//
// The small lists live in RDRAM above the game's 8 MB (which RT64 reads
// without its extended addressing) in eight rotating slots, so a slot is never
// rewritten while RT64 may still be reading the frame that uses it.
//
// Headless A/B hook: TOOIE_NO_MODEL_TAGS=1 turns the tagging off.

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <vector>

#include "recomp.h"
#include "ultramodern/config.hpp"
#include "tooie_debug.h"
#include "tooie_hooks.h"
#include "tooie_model_tagging.h"

namespace {
    constexpr uint32_t op_vtx = 0x01;
    constexpr uint32_t op_popmtx = 0xD8;
    constexpr uint32_t op_mtx = 0xDA;
    constexpr uint32_t op_moveword = 0xDB;
    constexpr uint32_t op_dl = 0xDE;
    constexpr uint32_t op_enddl = 0xDF;
    constexpr uint32_t moveword_segment = 0x06;
    // F3DEX2 stores G_MTX params with G_MTX_PUSH inverted.
    constexpr uint32_t mtx_projection = 0x04;
    constexpr uint32_t mtx_load = 0x02;
    // G_MTX loading the modelview without pushing (F3DEX2 encoding).
    constexpr uint32_t mtx_modelview_load = (op_mtx << 24) | 0x380000 | (mtx_load ^ 1);

    // RT64 extended GBI (lib/rt64/include/rt64_extended_gbi.h).
    constexpr uint32_t rt64_hook_word0 = 0xE0000000 | 0x525464;
    constexpr uint32_t rt64_extended_opcode = 0x64;
    constexpr uint32_t rt64_hook_op_enable = 0x1;
    constexpr uint32_t g_ex_matrixgroup_v1 = 0x00000C;
    constexpr uint32_t g_ex_id_auto = 0xFFFFFFFF;
    constexpr uint32_t component_skip = 0;
    constexpr uint32_t component_interpolate = 1;
    constexpr uint32_t component_auto = 2;
    constexpr uint32_t interpolate_simple = 0;
    constexpr uint32_t interpolate_decompose = 1;
    constexpr uint32_t order_linear = 0;
    constexpr uint32_t order_auto = 1;

    // Physical RDRAM for the small lists: 15-16 MB, above the game's 8 MB and
    // the runtime's data at 8 MB, below the mod heap at 16 MB.
    constexpr uint32_t list_area = 0x00F00000;
    // Two slots per frame (the scene and the 2D after it).
    constexpr uint32_t slot_size = 0x20000;
    constexpr uint32_t slot_count = 8;
    // Game units a model may move in one frame before it counts as a teleport.
    constexpr float teleport_distance = 250.0f;
    // Camera moves larger than this in one game frame (at 30 fps) count as a cut.
    constexpr float cut_distance = 150.0f;
    // ...and so do turns sharper than about 35 degrees.
    constexpr float cut_cosine = 0.82f;
    // ...or moves more than this per frame (or turns more than this many
    // degrees) all at once, from (nearly) still.
    constexpr float sudden_distance = 40.0f;
    constexpr float sudden_degrees = 10.0f;
    constexpr uint16_t game_select_map = 0x158;

    uint32_t slot = 0;
    uint32_t frame_start = 0;

    struct Copy {
        float pos[3];
        uint32_t instance;
    };
    // Copies drawn last frame, by model.
    std::unordered_map<uint32_t, std::vector<Copy>> previous;
    // The same for models placed through the projection (ShadowScan), in the
    // scene and in the 2D after it.
    std::unordered_map<uint32_t, std::vector<Copy>> previous_projected;
    std::unordered_map<uint32_t, std::vector<Copy>> previous_2d;
    uint32_t next_instance = 1;

    gpr kseg0(uint32_t phys) {
        return (int32_t)((phys & 0x1FFFFFFF) | 0x80000000);
    }

    uint32_t word(uint8_t* rdram, uint32_t phys) {
        return (uint32_t)MEM_W(0, kseg0(phys));
    }

    void put(uint8_t* rdram, uint32_t phys, uint32_t w0, uint32_t w1) {
        MEM_W(0, kseg0(phys)) = (int32_t)w0;
        MEM_W(4, kseg0(phys)) = (int32_t)w1;
    }

    // Matrix translation from an N64 fixed-point matrix (integer halfwords,
    // then fraction halfwords; translation is row 3).
    void read_translation(uint8_t* rdram, uint32_t phys, float out[3]) {
        gpr mtx = kseg0(phys);
        for (int i = 0; i < 3; i++) {
            int16_t whole = (int16_t)MEM_HU(24 + 2 * i, mtx);
            uint16_t frac = MEM_HU(56 + 2 * i, mtx);
            out[i] = (float)((int32_t)((uint32_t)(uint16_t)whole << 16 | frac)) / 65536.0f;
        }
    }

    uint32_t make_id(uint32_t model, uint32_t instance, uint32_t bone) {
        uint32_t hash = 2166136261u;
        for (uint32_t value : { model, instance, bone }) {
            for (int i = 0; i < 4; i++) {
                hash = (hash ^ ((value >> (i * 8)) & 0xFF)) * 16777619u;
            }
        }
        // 0 and 0xFFFFFFFF mean "ignore" and "automatic" to RT64.
        if (hash == 0 || hash == g_ex_id_auto) {
            hash = 1;
        }
        return hash;
    }

    // gEXMatrixGroup's projection flag.
    constexpr uint32_t group_projection = 1 << 1;

    struct Camera {
        float pos[3];
        float forward[3];
    };
    Camera last_camera;
    std::chrono::steady_clock::time_point last_camera_time;
    bool had_camera = false;
    uint32_t camera_generation = 0;
    // The camera's motion per game frame, last frame.
    float last_step = 0.0f;
    float last_turn = 0.0f;

    float matrix_element(uint8_t* rdram, uint32_t phys, int row, int column) {
        gpr mtx = kseg0(phys);
        int i = row * 4 + column;
        int16_t whole = (int16_t)MEM_HU(2 * i, mtx);
        uint16_t frac = MEM_HU(32 + 2 * i, mtx);
        return (float)((int32_t)((uint32_t)(uint16_t)whole << 16 | frac)) / 65536.0f;
    }

    // Camera position and facing from a view-projection matrix (row vectors,
    // clip = [x y z 1] M): the position is where clip x, y and w are all 0,
    // and w grows along the facing.
    bool read_camera(uint8_t* rdram, uint32_t phys, Camera& out) {
        float m[4][4];
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                m[r][c] = matrix_element(rdram, phys, r, c);
            }
        }
        const int cols[3] = { 0, 1, 3 };
        float a[3][3];
        float b[3];
        for (int e = 0; e < 3; e++) {
            for (int k = 0; k < 3; k++) {
                a[e][k] = m[k][cols[e]];
            }
            b[e] = -m[3][cols[e]];
        }
        float det = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) -
            a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) +
            a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
        if (std::fabs(det) < 1e-12f) {
            return false;
        }
        for (int k = 0; k < 3; k++) {
            float t[3][3];
            for (int e = 0; e < 3; e++) {
                for (int j = 0; j < 3; j++) {
                    t[e][j] = j == k ? b[e] : a[e][j];
                }
            }
            float dk = t[0][0] * (t[1][1] * t[2][2] - t[1][2] * t[2][1]) -
                t[0][1] * (t[1][0] * t[2][2] - t[1][2] * t[2][0]) +
                t[0][2] * (t[1][0] * t[2][1] - t[1][1] * t[2][0]);
            out.pos[k] = dk / det;
        }
        float length = std::sqrt(m[0][3] * m[0][3] + m[1][3] * m[1][3] + m[2][3] * m[2][3]);
        if (length < 1e-9f) {
            return false;
        }
        for (int k = 0; k < 3; k++) {
            out.forward[k] = m[k][3] / length;
        }
        return true;
    }

    void write_matrix(uint8_t* rdram, uint32_t phys, const float m[4][4]) {
        gpr mtx = kseg0(phys);
        for (int i = 0; i < 16; i++) {
            float scaled = std::min(std::max(m[i / 4][i % 4] * 65536.0f, -2147483648.0f), 2147483520.0f);
            int32_t value = (int32_t)std::lround(scaled);
            MEM_H(2 * i, mtx) = (int16_t)(value >> 16);
            MEM_H(32 + 2 * i, mtx) = (int16_t)(value & 0xFFFF);
        }
    }

    // Shadows. The game draws a character's shadow as a flattened copy of a
    // small shadow model: it multiplies the flattening and the character's
    // place into the projection matrix, points segment 5 at the shadow's bone
    // matrices, and calls the shadow's geometry, which loads each bone from
    // segment 5. RT64 blends only a frame's first projection and copies that
    // to the rest, so the place in the projection would move at the game's
    // own rate and the bones, hidden inside the geometry lists, would be
    // matched to each other by guesswork. Instead the shadow's matrix is
    // multiplied into copies of the bones and the projection is left alone;
    // the bones are then ordinary matrices, blended in the order the geometry
    // loads them under one id.
    struct ShadowScan {
        uint8_t* rdram;
        uint32_t bones = 0;
        int budget = 4096;
        // The matrix stack, true where a bone is loaded; the bottom is the
        // modelview in effect before the model.
        std::vector<bool> stack{false};
        // Whether vertices are loaded with that modelview (the pause menu's
        // panels stretch between a bone and it).
        bool base_vertices = false;

        // Walks one list; false if it does anything other than load bones
        // from segment 5.
        bool walk(uint32_t phys, uint32_t segments[16], int depth) {
            for (; budget > 0; budget--, phys += 8) {
                uint32_t w0 = word(rdram, phys);
                uint32_t w1 = word(rdram, phys + 4);
                uint32_t op = w0 >> 24;
                if (op == op_mtx) {
                    uint32_t params = (w0 & 0xFF) ^ 1;
                    if ((params & (mtx_projection | mtx_load)) != mtx_load || (w1 >> 24) != 5 || (w1 & 0x3F) != 0) {
                        return false;
                    }
                    bones = std::max(bones, (w1 & 0xFFFFFF) / 64 + 1);
                    if ((params & 1) != 0) {
                        stack.push_back(true);
                    }
                    else {
                        stack.back() = true;
                    }
                }
                else if (op == op_popmtx) {
                    for (uint32_t n = w1 / 64; n > 0; n--) {
                        if (stack.size() < 2) {
                            return false;
                        }
                        stack.pop_back();
                    }
                }
                else if (op == op_vtx && !stack.back()) {
                    base_vertices = true;
                }
                else if (op == op_moveword && ((w0 >> 16) & 0xFF) == moveword_segment) {
                    segments[((w0 & 0xFFFF) / 4) & 0xF] = w1 & 0x1FFFFFFF;
                }
                else if (op == op_dl) {
                    uint32_t target = (w1 & 0x80000000) != 0 ? (w1 & 0x1FFFFFFF) :
                        ((segments[(w1 >> 24) & 0xF] + (w1 & 0xFFFFFF)) & 0x1FFFFFFF);
                    // A segment the scan does not know (set before it
                    // started): leave that list alone.
                    if (target == 0) {
                        continue;
                    }
                    if (depth > 8 || !walk(target, segments, depth + 1)) {
                        return false;
                    }
                    if (((w0 >> 16) & 0xFF) != 0) {
                        return true;
                    }
                }
                else if (op == op_enddl) {
                    return true;
                }
            }
            return false;
        }
    };

    uint32_t group_word0() {
        return (rt64_extended_opcode << 24) | g_ex_matrixgroup_v1;
    }

    // Second word pair of gEXMatrixGroup, NOPUSH, model view stack.
    // vertices: whether RT64 also blends vertex positions that the game
    // rewrites itself each frame (Banjo bends his joints on the CPU).
    uint32_t group_params(uint32_t mode, uint32_t components, uint32_t order, uint32_t vertices = component_skip) {
        uint32_t c = components;
        return (mode << 2) | (c << 3) | (c << 5) | (c << 7) | (c << 9) | (c << 11) |
            (vertices << 13) | (component_auto << 15) | (order << 17) |
            (component_skip << 22) | (component_auto << 24);
    }

    struct Block {
        uint32_t first_list = 0;
        uint32_t textures = 0;
        uint32_t model = 0;
        uint32_t matrices = 0;
        bool have_pos = false;
        float pos[3] = {};
        uint32_t instance = 0;
    };

    bool interpolation_on() {
        static const bool disabled = std::getenv("TOOIE_NO_MODEL_TAGS") != nullptr;
        return !disabled && ultramodern::renderer::get_graphics_config().rr_option != ultramodern::renderer::RefreshRate::Original;
    }
}

// Start of func_800A73F4, with the graphics context in $s1: its first word is
// the display list pointer.
extern "C" void tooie_scene_begin(uint8_t* rdram, recomp_context* ctx) {
    frame_start = (uint32_t)MEM_W(0, ctx->r17) & 0x1FFFFFFF;
}

uint32_t tooie::model_tagging::scene_start() {
    return frame_start;
}

// overlay: the 2D drawn after the scene (pause menu, HUD, text boxes). Only
// its projected models (see ShadowScan) are tagged there, and the camera is
// left to the scene.
static uint32_t tag(uint8_t* rdram, uint32_t start, uint32_t end, bool overlay) {
    if (!interpolation_on() || end <= start) {
        return 0;
    }

    // Pass 1: find the models, the commands that belong to each, and the
    // camera.
    struct Command {
        uint32_t w0;
        uint32_t w1;
        int block;
    };
    std::vector<Command> commands;
    std::vector<Block> blocks;
    int current = -1;
    bool have_camera = false;
    Camera camera;
    for (uint32_t p = start; p < end; p += 8) {
        uint32_t w0 = word(rdram, p);
        uint32_t w1 = word(rdram, p + 4);
        uint32_t op = w0 >> 24;
        if (op == op_moveword && ((w0 >> 16) & 0xFF) == moveword_segment && (w0 & 0xFFFF) == 4) {
            blocks.emplace_back();
            current = (int)blocks.size() - 1;
        }
        else if (op == op_moveword && ((w0 >> 16) & 0xFF) == moveword_segment && (w0 & 0xFFFF) == 8 && current >= 0) {
            blocks[current].textures = w1;
        }
        else if (op == op_mtx) {
            uint32_t params = (w0 & 0xFF) ^ 1;
            if ((params & mtx_projection) != 0) {
                current = -1;
                if (!overlay && !have_camera && (params & mtx_load) != 0) {
                    have_camera = read_camera(rdram, w1 & 0x1FFFFFFF, camera);
                }
            }
            else if (current >= 0) {
                Block& block = blocks[current];
                if (!block.have_pos) {
                    read_translation(rdram, w1 & 0x1FFFFFFF, block.pos);
                    block.have_pos = true;
                }
                block.matrices++;
            }
        }
        else if (op == op_dl && current >= 0 && blocks[current].first_list == 0) {
            blocks[current].first_list = w1;
        }
        else if (op == op_enddl || (op == op_dl && ((w0 >> 16) & 0xFF) != 0)) {
            break;
        }
        commands.push_back({w0, w1, current});
    }
    for (Block& block : blocks) {
        block.model = block.first_list == 0 || overlay ? 0 : make_id(block.first_list, block.textures, 0);
    }

    // A camera cut: the camera jumps or turns sharply in one game frame.
    // Blending across it would slide everything (characters placed for the
    // new shot included) through the in-between frames.
    bool cut = false;
    if (have_camera) {
        if (had_camera) {
            float moved = 0.0f;
            float facing = 0.0f;
            for (int k = 0; k < 3; k++) {
                float d = camera.pos[k] - last_camera.pos[k];
                moved += d * d;
                facing += camera.forward[k] * last_camera.forward[k];
            }
            // The game moves things further per frame when it runs slowly
            // (it counts elapsed time), so allow for longer frames.
            auto now_time = std::chrono::steady_clock::now();
            float frames = std::chrono::duration<float>(now_time - last_camera_time).count() * 30.0f;
            frames = std::min(std::max(frames, 1.0f), 4.0f);
            float limit = cut_distance * frames;
            cut = moved > limit * limit || facing < cut_cosine;
            // Shots of the same place can be closer than that, so a sudden
            // move or turn also counts: much more than the camera's own
            // motion the frame before (a steady pan or dolly does not).
            float step = std::sqrt(moved) / frames;
            float turn = std::acos(std::min(std::max(facing, -1.0f), 1.0f)) * 57.29578f / frames;
            bool sudden = step > std::max(sudden_distance, 3.0f * last_step + 15.0f) ||
                turn > std::max(sudden_degrees, 3.0f * last_turn + 4.0f);
            cut = cut || sudden;
            last_step = step;
            last_turn = turn;
            // Headless aid: TOOIE_CUT_LOG=1 logs the camera's motion each frame.
            static const bool log_cuts = std::getenv("TOOIE_CUT_LOG") != nullptr;
            if (log_cuts) {
                std::fprintf(stderr, "[cut] moved %.1f turned %.1f frames %.2f%s\n", std::sqrt(moved), turn * frames, frames, cut ? " CUT" : "");
            }
        }
        last_camera = camera;
        last_camera_time = std::chrono::steady_clock::now();
        had_camera = true;
    }
    if (cut) {
        camera_generation++;
    }

    // Pass 2: match each copy of a model to last frame's nearest copy.
    std::unordered_map<uint32_t, std::vector<Copy>> now;
    std::unordered_map<uint32_t, std::vector<bool>> taken;
    for (Block& block : blocks) {
        if (block.model == 0 || block.matrices == 0) {
            continue;
        }
        auto& last = previous[block.model];
        auto& used = taken[block.model];
        used.resize(last.size(), false);
        int best = -1;
        float best_distance = teleport_distance * teleport_distance;
        for (size_t i = 0; i < last.size() && !cut; i++) {
            if (used[i]) {
                continue;
            }
            float d = 0.0f;
            for (int k = 0; k < 3; k++) {
                float diff = last[i].pos[k] - block.pos[k];
                d += diff * diff;
            }
            if (d < best_distance) {
                best_distance = d;
                best = (int)i;
            }
        }
        if (best >= 0) {
            used[best] = true;
            block.instance = last[best].instance;
        }
        else {
            block.instance = next_instance++;
        }
        Copy copy;
        copy.pos[0] = block.pos[0];
        copy.pos[1] = block.pos[1];
        copy.pos[2] = block.pos[2];
        copy.instance = block.instance;
        now[block.model].push_back(copy);
    }
    // The 2D has no models of its own; keep the scene's for next frame.
    if (!overlay) {
        previous = std::move(now);
    }

    // Bone ids. A model loads a varying number of matrices from frame to
    // frame (Banjo 48 or 68, depending on what he is doing), so a bone is
    // named by the geometry list it draws next and its place among the
    // matrices loaded since the list before, not by a running count.
    std::vector<uint32_t> bone_id(commands.size(), 0);
    {
        std::vector<size_t> pending;
        int pending_block = -1;
        auto settle = [&](uint32_t list) {
            for (size_t k = 0; k < pending.size(); k++) {
                bone_id[pending[k]] = make_id(list, (uint32_t)k, (uint32_t)pending.size() - (uint32_t)k);
            }
            pending.clear();
        };
        for (size_t i = 0; i < commands.size(); i++) {
            const Command& c = commands[i];
            if (c.block != pending_block) {
                settle(0);
                pending_block = c.block;
            }
            uint32_t op = c.w0 >> 24;
            if (op == op_mtx && c.block >= 0 && (((c.w0 & 0xFF) ^ 1) & mtx_projection) == 0) {
                pending.push_back(i);
            }
            else if (op == op_dl && c.block >= 0) {
                settle(c.w1);
            }
        }
        settle(0);
    }

    // On the game select screen the portraits and the hand shake by a random
    // small turn every game frame; blended, the shake turns into a slow wobble.
    // Its models are drawn at the game's own rate instead, as is everything
    // on the first frame after a camera cut.
    const bool snap = (cut && !overlay) || tooie::debug::current_map(rdram) == game_select_map;

    slot = (slot + 1) % slot_count;
    uint32_t cursor = list_area + slot * slot_size;
    uint32_t limit = cursor + slot_size;

    // Shadows (see ShadowScan): a model matrix multiplied into the projection,
    // then segment 5 and the calls that load the bones from it.
    std::vector<uint32_t> shadow(commands.size(), 0);
    std::vector<uint32_t> shadow_base(commands.size(), 0);
    std::vector<uint32_t> restore(commands.size(), 0);
    {
        // The overlay starts with the segments the scene left.
        static uint32_t scene_segments[16] = {};
        uint32_t segments[16] = {};
        if (overlay) {
            std::copy(scene_segments, scene_segments + 16, segments);
        }
        std::unordered_map<uint32_t, std::vector<Copy>>& last_copies = overlay ? previous_2d : previous_projected;
        std::unordered_map<uint32_t, std::vector<Copy>> now_copies;
        std::unordered_map<uint32_t, std::vector<bool>> used_copies;
        // The modelview stack as the top-level list leaves it (0 where
        // unknown), for models that also draw with the modelview before them.
        std::vector<uint32_t> modelview{0};
        for (size_t i = 0; i < commands.size(); i++) {
            const Command& c = commands[i];
            uint32_t op = c.w0 >> 24;
            if (op == op_mtx && (((c.w0 & 0xFF) ^ 1) & mtx_projection) == 0) {
                uint32_t params = (c.w0 & 0xFF) ^ 1;
                uint32_t address = (c.w1 & 0x80000000) != 0 || (c.w1 >> 24) == 0 ? (c.w1 & 0x1FFFFFFF) : 0;
                uint32_t top = (params & mtx_load) != 0 ? address : 0;
                if ((params & 1) != 0) {
                    modelview.push_back(top);
                }
                else {
                    modelview.back() = top;
                }
                continue;
            }
            if (op == op_popmtx) {
                for (uint32_t n = c.w1 / 64; n > 0 && modelview.size() > 1; n--) {
                    modelview.pop_back();
                }
                continue;
            }
            if (op == op_moveword && ((c.w0 >> 16) & 0xFF) == moveword_segment) {
                segments[((c.w0 & 0xFFFF) / 4) & 0xF] = c.w1 & 0x1FFFFFFF;
                if (!overlay) {
                    scene_segments[((c.w0 & 0xFFFF) / 4) & 0xF] = c.w1 & 0x1FFFFFFF;
                }
                continue;
            }
            if (op != op_mtx || (((c.w0 & 0xFF) ^ 1) & (mtx_projection | mtx_load)) != mtx_projection) {
                continue;
            }
            uint32_t local[16];
            std::copy(segments, segments + 16, local);
            ShadowScan scan{rdram};
            size_t segment_command = 0;
            size_t next_matrix = 0;
            uint32_t first_list = 0;
            bool ok = true;
            for (size_t j = i + 1; j < commands.size() && ok; j++) {
                uint32_t w0 = commands[j].w0;
                uint32_t w1 = commands[j].w1;
                uint32_t jop = w0 >> 24;
                if (jop == op_mtx) {
                    next_matrix = j;
                    break;
                }
                if (jop == op_popmtx) {
                    ok = false;
                    break;
                }
                if (jop == op_moveword && ((w0 >> 16) & 0xFF) == moveword_segment) {
                    uint32_t seg = ((w0 & 0xFFFF) / 4) & 0xF;
                    local[seg] = w1 & 0x1FFFFFFF;
                    if (seg == 5) {
                        segment_command = j;
                    }
                }
                else if (jop == op_dl) {
                    uint32_t target = (w1 & 0x80000000) != 0 ? (w1 & 0x1FFFFFFF) :
                        ((local[(w1 >> 24) & 0xF] + (w1 & 0xFFFFFF)) & 0x1FFFFFFF);
                    if (first_list == 0) {
                        first_list = target;
                    }
                    ok = segment_command != 0 && target != 0 && scan.walk(target, local, 0);
                }
            }
            uint32_t base = modelview.back();
            if (scan.base_vertices && (base == 0 || next_matrix == 0)) {
                ok = false;
            }
            uint32_t bytes = (scan.bones + (scan.base_vertices ? 1 : 0)) * 64;
            if (!ok || segment_command == 0 || scan.bones == 0 || cursor + bytes + 64 > limit) {
                continue;
            }
            float m[4][4];
            float bone[4][4];
            float product[4][4];
            uint32_t shadow_matrix = commands[i].w1 & 0x1FFFFFFF;
            uint32_t bones = commands[segment_command].w1 & 0x1FFFFFFF;
            for (int r = 0; r < 4; r++) {
                for (int k = 0; k < 4; k++) {
                    m[r][k] = matrix_element(rdram, shadow_matrix, r, k);
                }
            }
            for (uint32_t n = 0; n < scan.bones; n++) {
                for (int r = 0; r < 4; r++) {
                    for (int k = 0; k < 4; k++) {
                        bone[r][k] = matrix_element(rdram, bones + n * 64, r, k);
                    }
                }
                for (int r = 0; r < 4; r++) {
                    for (int k = 0; k < 4; k++) {
                        product[r][k] = bone[r][0] * m[0][k] + bone[r][1] * m[1][k] + bone[r][2] * m[2][k] + bone[r][3] * m[3][k];
                    }
                }
                write_matrix(rdram, cursor + n * 64, product);
            }
            put(rdram, start + (uint32_t)segment_command * 8, commands[segment_command].w0, cursor);
            if (scan.base_vertices) {
                // The modelview before the model gets the same treatment, and
                // is put back before the next matrix.
                for (int r = 0; r < 4; r++) {
                    for (int k = 0; k < 4; k++) {
                        bone[r][k] = matrix_element(rdram, base, r, k);
                    }
                }
                for (int r = 0; r < 4; r++) {
                    for (int k = 0; k < 4; k++) {
                        product[r][k] = bone[r][0] * m[0][k] + bone[r][1] * m[1][k] + bone[r][2] * m[2][k] + bone[r][3] * m[3][k];
                    }
                }
                shadow_base[i] = cursor + scan.bones * 64;
                write_matrix(rdram, shadow_base[i], product);
                restore[next_matrix] = base;
            }
            cursor += bytes;

            // Which copy this is: the nearest of last frame's copies of the
            // same model, as in pass 2, so one appearing or vanishing does
            // not shift the others' ids (the pause menu's panels).
            uint32_t key = make_id(first_list, local[2], 0x534844);
            auto& last = last_copies[key];
            auto& used = used_copies[key];
            used.resize(last.size(), false);
            int best = -1;
            float best_distance = teleport_distance * teleport_distance;
            for (size_t n = 0; n < last.size() && !snap; n++) {
                if (used[n]) {
                    continue;
                }
                float d = 0.0f;
                for (int k = 0; k < 3; k++) {
                    float diff = last[n].pos[k] - m[3][k];
                    d += diff * diff;
                }
                if (d < best_distance) {
                    best_distance = d;
                    best = (int)n;
                }
            }
            Copy copy;
            for (int k = 0; k < 3; k++) {
                copy.pos[k] = m[3][k];
            }
            if (best >= 0) {
                used[best] = true;
                copy.instance = last[best].instance;
            }
            else {
                copy.instance = next_instance++;
            }
            now_copies[key].push_back(copy);
            shadow[i] = make_id(key, copy.instance, camera_generation);
        }
        last_copies = std::move(now_copies);
    }

    // Pass 3: wrap the matrix loads.
    bool enabled = false;
    bool tagged = false;
    bool camera_tagged = false;
    std::unordered_map<uint32_t, uint32_t> repeats;
    // Headless aid: TOOIE_TAG_LOG=1 logs how many of each big model's ids
    // carry over from the last frame.
    static const bool log_ids = std::getenv("TOOIE_TAG_LOG") != nullptr;
    std::unordered_map<uint32_t, std::vector<uint32_t>> ids_now;
    uint32_t p = start;
    for (size_t index = 0; index < commands.size(); index++, p += 8) {
        const Command& c = commands[index];
        if ((c.w0 >> 24) != op_mtx) {
            continue;
        }
        int b = c.block;
        uint32_t params = (c.w0 & 0xFF) ^ 1;
        bool projection = (params & mtx_projection) != 0;
        bool model = b >= 0 && blocks[b].model != 0 && !projection;
        bool tag = model || (snap && !projection && !overlay);
        // The perspective camera gets an id that changes at each cut, so RT64
        // does not blend the camera across it.
        bool tag_camera = projection && (params & mtx_load) != 0 && !camera_tagged && have_camera;
        if (shadow[index]) {
            // Replaces the projection multiply: one id for all the shadow's
            // bones, matched in load order and blended element by element
            // (they are flat, so they cannot be split into turn and scale).
            if (cursor + 48 > limit) {
                break;
            }
            uint32_t list = cursor;
            if (!enabled) {
                put(rdram, cursor, rt64_hook_word0, (rt64_hook_op_enable << 28) | rt64_extended_opcode);
                cursor += 8;
                enabled = true;
            }
            uint32_t components = snap ? component_skip : component_interpolate;
            put(rdram, cursor, group_word0(), shadow[index]);
            put(rdram, cursor + 8, group_params(interpolate_simple, components, order_linear), 0);
            cursor += 16;
            if (shadow_base[index] != 0) {
                put(rdram, cursor, mtx_modelview_load, shadow_base[index]);
                cursor += 8;
            }
            put(rdram, cursor, op_enddl << 24, 0);
            cursor += 8;
            put(rdram, p, op_dl << 24, list);
            tagged = true;
            continue;
        }
        if (!tag && !tagged && !tag_camera && restore[index] == 0) {
            continue;
        }
        if (cursor + 72 > limit) {
            break;
        }
        uint32_t list = cursor;
        if (!enabled) {
            put(rdram, cursor, rt64_hook_word0, (rt64_hook_op_enable << 28) | rt64_extended_opcode);
            cursor += 8;
            enabled = true;
        }
        if (tag_camera) {
            put(rdram, cursor, group_word0(), make_id(0x43414D, camera_generation, 0));
            put(rdram, cursor + 8, group_params(interpolate_simple, component_interpolate, order_auto) | group_projection, 0);
            cursor += 16;
            camera_tagged = true;
        }
        if (tag) {
            uint32_t id;
            if (model) {
                uint32_t bone = bone_id[index];
                uint32_t key = make_id(blocks[b].model, blocks[b].instance, bone);
                // A list drawn twice in a model (both hands, say) gets a second id.
                id = make_id(key, repeats[key]++, camera_generation);
                if (log_ids) {
                    ids_now[blocks[b].model].push_back(id);
                }
            }
            else {
                id = make_id(0, camera_generation, (uint32_t)index);
            }
            uint32_t components = snap ? component_skip : component_interpolate;
            put(rdram, cursor, group_word0(), id);
            uint32_t vertices = snap ? component_skip : component_interpolate;
            put(rdram, cursor + 8, group_params(interpolate_decompose, components, order_linear, vertices), 0);
            cursor += 16;
        }
        else if (tagged) {
            // Back to RT64's defaults for matrices outside a model.
            put(rdram, cursor, group_word0(), g_ex_id_auto);
            put(rdram, cursor + 8, group_params(interpolate_decompose, component_auto, order_auto), 0);
            cursor += 16;
        }
        if (restore[index] != 0) {
            put(rdram, cursor, mtx_modelview_load, restore[index]);
            cursor += 8;
        }
        put(rdram, cursor, c.w0, c.w1);
        put(rdram, cursor + 8, op_enddl << 24, 0);
        cursor += 16;
        put(rdram, p, op_dl << 24, list);
        if (!projection) {
            tagged = tag;
        }
    }

    if (log_ids && !overlay) {
        // Per model: matrices this frame, and how many of their ids were also
        // used last frame (RT64 can only blend those).
        static std::unordered_map<uint32_t, std::vector<uint32_t>> ids_last;
        for (auto& [model_key, ids] : ids_now) {
            if (ids.size() < 20) {
                continue;
            }
            auto& last = ids_last[model_key];
            size_t kept = 0;
            for (uint32_t id : ids) {
                kept += std::find(last.begin(), last.end(), id) != last.end() ? 1 : 0;
            }
            std::fprintf(stderr, "[ids] model %08X matrices %zu kept %zu (last %zu)\n", model_key, ids.size(), kept, last.size());
        }
        ids_last = std::move(ids_now);
    }

    // Leave the rest of the frame with the defaults.
    if (tagged) {
        put(rdram, end, group_word0(), g_ex_id_auto);
        put(rdram, end + 8, group_params(interpolate_decompose, component_auto, order_auto), 0);
        return 16;
    }
    return 0;
}

uint32_t tooie::model_tagging::tag_scene(uint8_t* rdram, uint32_t start, uint32_t end) {
    return tag(rdram, start, end, false);
}

uint32_t tooie::model_tagging::tag_2d(uint8_t* rdram, uint32_t start, uint32_t end) {
    return tag(rdram, start, end, true);
}
