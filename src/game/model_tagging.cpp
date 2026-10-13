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
// without its extended addressing) in four rotating slots, so a slot is never
// rewritten while RT64 may still be reading the frame that uses it.
//
// Headless A/B hook: TOOIE_NO_MODEL_TAGS=1 turns the tagging off.

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <unordered_map>
#include <vector>

#include "recomp.h"
#include "ultramodern/config.hpp"
#include "tooie_debug.h"
#include "tooie_hooks.h"
#include "tooie_model_tagging.h"

namespace {
    constexpr uint32_t op_mtx = 0xDA;
    constexpr uint32_t op_moveword = 0xDB;
    constexpr uint32_t op_dl = 0xDE;
    constexpr uint32_t op_enddl = 0xDF;
    constexpr uint32_t moveword_segment = 0x06;
    // F3DEX2 stores G_MTX params with G_MTX_PUSH inverted.
    constexpr uint32_t mtx_projection = 0x04;
    constexpr uint32_t mtx_load = 0x02;

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
    constexpr uint32_t slot_size = 0x40000;
    constexpr uint32_t slot_count = 4;
    // Game units a model may move in one frame before it counts as a teleport.
    constexpr float teleport_distance = 250.0f;
    // Camera moves larger than this in one game frame (at 30 fps) count as a cut.
    constexpr float cut_distance = 150.0f;
    // ...and so do turns sharper than about 35 degrees.
    constexpr float cut_cosine = 0.82f;
    constexpr uint16_t game_select_map = 0x158;

    uint32_t slot = 0;
    uint32_t frame_start = 0;

    struct Copy {
        float pos[3];
        uint32_t instance;
    };
    // Copies drawn last frame, by model.
    std::unordered_map<uint32_t, std::vector<Copy>> previous;
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
                }
                else if (op == op_moveword && ((w0 >> 16) & 0xFF) == moveword_segment) {
                    segments[((w0 & 0xFFFF) / 4) & 0xF] = w1 & 0x1FFFFFFF;
                }
                else if (op == op_dl) {
                    uint32_t target = (w1 & 0x80000000) != 0 ? (w1 & 0x1FFFFFFF) :
                        ((segments[(w1 >> 24) & 0xF] + (w1 & 0xFFFFFF)) & 0x1FFFFFFF);
                    if (depth > 8 || target == 0 || !walk(target, segments, depth + 1)) {
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

uint32_t tooie::model_tagging::tag_scene(uint8_t* rdram, uint32_t start, uint32_t end) {
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
                if (!have_camera && (params & mtx_load) != 0) {
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
        block.model = block.first_list == 0 ? 0 : make_id(block.first_list, block.textures, 0);
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
    previous = std::move(now);

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
    const bool snap = cut || tooie::debug::current_map(rdram) == game_select_map;

    slot = (slot + 1) % slot_count;
    uint32_t cursor = list_area + slot * slot_size;
    uint32_t limit = cursor + slot_size;

    // Shadows (see ShadowScan): a model matrix multiplied into the projection,
    // then segment 5 and the calls that load the bones from it.
    std::vector<bool> shadow(commands.size(), false);
    {
        uint32_t segments[16] = {};
        for (size_t i = 0; i < commands.size(); i++) {
            const Command& c = commands[i];
            uint32_t op = c.w0 >> 24;
            if (op == op_moveword && ((c.w0 >> 16) & 0xFF) == moveword_segment) {
                segments[((c.w0 & 0xFFFF) / 4) & 0xF] = c.w1 & 0x1FFFFFFF;
                continue;
            }
            if (op != op_mtx || (((c.w0 & 0xFF) ^ 1) & (mtx_projection | mtx_load)) != mtx_projection) {
                continue;
            }
            uint32_t local[16];
            std::copy(segments, segments + 16, local);
            ShadowScan scan{rdram};
            size_t segment_command = 0;
            bool ok = true;
            for (size_t j = i + 1; j < commands.size() && ok; j++) {
                uint32_t w0 = commands[j].w0;
                uint32_t w1 = commands[j].w1;
                uint32_t jop = w0 >> 24;
                if (jop == op_mtx) {
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
                    ok = segment_command != 0 && target != 0 && scan.walk(target, local, 0);
                }
            }
            uint32_t bytes = scan.bones * 64;
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
            cursor += bytes;
            shadow[i] = true;
        }
    }

    // Pass 3: wrap the matrix loads.
    bool enabled = false;
    bool tagged = false;
    bool camera_tagged = false;
    uint32_t shadows = 0;
    std::unordered_map<uint32_t, uint32_t> repeats;
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
        bool tag = model || (snap && !projection);
        // The perspective camera gets an id that changes at each cut, so RT64
        // does not blend the camera across it.
        bool tag_camera = projection && (params & mtx_load) != 0 && !camera_tagged && have_camera;
        if (shadow[index]) {
            // Replaces the projection multiply: one id for all the shadow's
            // bones, matched in load order and blended element by element
            // (they are flat, so they cannot be split into turn and scale).
            if (cursor + 40 > limit) {
                break;
            }
            uint32_t list = cursor;
            if (!enabled) {
                put(rdram, cursor, rt64_hook_word0, (rt64_hook_op_enable << 28) | rt64_extended_opcode);
                cursor += 8;
                enabled = true;
            }
            uint32_t components = snap ? component_skip : component_interpolate;
            put(rdram, cursor, group_word0(), make_id(0x534844, shadows++, camera_generation));
            put(rdram, cursor + 8, group_params(interpolate_simple, components, order_linear), 0);
            put(rdram, cursor + 16, op_enddl << 24, 0);
            cursor += 24;
            put(rdram, p, op_dl << 24, list);
            tagged = true;
            continue;
        }
        if (!tag && !tagged && !tag_camera) {
            continue;
        }
        if (cursor + 64 > limit) {
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
        put(rdram, cursor, c.w0, c.w1);
        put(rdram, cursor + 8, op_enddl << 24, 0);
        cursor += 16;
        put(rdram, p, op_dl << 24, list);
        if (!projection) {
            tagged = tag;
        }
    }

    // Leave the rest of the frame with the defaults.
    if (tagged) {
        put(rdram, end, group_word0(), g_ex_id_auto);
        put(rdram, end + 8, group_params(interpolate_decompose, component_auto, order_auto), 0);
        return 16;
    }
    return 0;
}
