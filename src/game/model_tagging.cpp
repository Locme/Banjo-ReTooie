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
// below), so the portraits shake as they do at 30 fps.
//
// The small lists live in RDRAM above the game's 8 MB (which RT64 reads
// without its extended addressing) in four rotating slots, so a slot is never
// rewritten while RT64 may still be reading the frame that uses it.
//
// Headless A/B hook: TOOIE_NO_MODEL_TAGS=1 turns the tagging off.

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
    constexpr float teleport_distance = 400.0f;
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

    uint32_t group_word0() {
        return (rt64_extended_opcode << 24) | g_ex_matrixgroup_v1;
    }

    // Second word pair of gEXMatrixGroup, NOPUSH, model view stack.
    uint32_t group_params(uint32_t mode, uint32_t components, uint32_t order) {
        uint32_t c = components;
        return (mode << 2) | (c << 3) | (c << 5) | (c << 7) | (c << 9) | (c << 11) |
            (component_skip << 13) | (component_auto << 15) | (order << 17) |
            (component_skip << 22) | (component_auto << 24);
    }

    struct Block {
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

    // Pass 1: find the models and the commands that belong to each.
    std::vector<Block> blocks;
    std::vector<int> owner;
    int current = -1;
    for (uint32_t p = start; p < end; p += 8) {
        uint32_t w0 = word(rdram, p);
        uint32_t w1 = word(rdram, p + 4);
        uint32_t op = w0 >> 24;
        owner.push_back(current);
        if (op == op_moveword && ((w0 >> 16) & 0xFF) == moveword_segment && (w0 & 0xFFFF) == 4) {
            blocks.emplace_back();
            current = (int)blocks.size() - 1;
            owner.back() = current;
        }
        else if (op == op_mtx) {
            if ((((w0 & 0xFF) ^ 1) & mtx_projection) != 0) {
                current = -1;
                owner.back() = -1;
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
        else if (op == op_dl && current >= 0 && blocks[current].model == 0) {
            blocks[current].model = w1;
        }
        else if (op == op_enddl || (op == op_dl && ((w0 >> 16) & 0xFF) != 0)) {
            break;
        }
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
        for (size_t i = 0; i < last.size(); i++) {
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

    // On the game select screen the portraits and the hand shake by a random
    // small turn every game frame; blended, the shake turns into a slow wobble.
    // Its models are drawn at the game's own rate instead.
    const bool snap = tooie::debug::current_map(rdram) == game_select_map;

    // Pass 3: wrap the matrix loads.
    slot = (slot + 1) % slot_count;
    uint32_t cursor = list_area + slot * slot_size;
    uint32_t limit = cursor + slot_size;
    bool enabled = false;
    bool tagged = false;
    std::vector<uint32_t> bone(blocks.size(), 0);
    size_t index = 0;
    for (uint32_t p = start; p < end && index < owner.size(); p += 8, index++) {
        uint32_t w0 = word(rdram, p);
        if ((w0 >> 24) != op_mtx) {
            continue;
        }
        int b = owner[index];
        bool projection = (((w0 & 0xFF) ^ 1) & mtx_projection) != 0;
        bool tag = (b >= 0 && blocks[b].model != 0) || (snap && !projection);
        if (!tag && !tagged) {
            continue;
        }
        if (cursor + 40 > limit) {
            break;
        }
        uint32_t w1 = word(rdram, p + 4);
        uint32_t list = cursor;
        if (!enabled) {
            put(rdram, cursor, rt64_hook_word0, (rt64_hook_op_enable << 28) | rt64_extended_opcode);
            cursor += 8;
            enabled = true;
        }
        if (tag && snap) {
            // Drawn as the game left it: no blending towards the next frame.
            uint32_t id = b >= 0 && blocks[b].model != 0 ? make_id(blocks[b].model, blocks[b].instance, bone[b]++) : make_id(0, 0, (uint32_t)index);
            put(rdram, cursor, group_word0(), id);
            put(rdram, cursor + 8, group_params(interpolate_simple, component_skip, order_linear), 0);
        }
        else if (tag) {
            const Block& block = blocks[b];
            uint32_t mode = block.matrices > 1 ? interpolate_simple : interpolate_decompose;
            put(rdram, cursor, group_word0(), make_id(block.model, block.instance, bone[b]++));
            put(rdram, cursor + 8, group_params(mode, component_interpolate, order_linear), 0);
        }
        else {
            // Back to RT64's defaults for matrices outside a model.
            put(rdram, cursor, group_word0(), g_ex_id_auto);
            put(rdram, cursor + 8, group_params(interpolate_decompose, component_auto, order_auto), 0);
        }
        put(rdram, cursor + 16, w0, w1);
        put(rdram, cursor + 24, op_enddl << 24, 0);
        cursor += 32;
        put(rdram, p, op_dl << 24, list);
        tagged = tag;
    }

    // Leave the rest of the frame with the defaults.
    if (tagged) {
        put(rdram, end, group_word0(), g_ex_id_auto);
        put(rdram, end + 8, group_params(interpolate_decompose, component_auto, order_auto), 0);
        return 16;
    }
    return 0;
}
