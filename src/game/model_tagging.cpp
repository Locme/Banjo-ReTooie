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
//
// Models picked for no screen effects (the Model Effects key, see
// tooie_interp_tags.h) are marked here too, with interpolation on or off:
// the command that starts the model (its segment 1) and the one after its
// last are each wrapped in a small list that sets RT64's exclude flag first.

#include <atomic>
#include <algorithm>
#include <array>
#include <tuple>
#include <functional>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iterator>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "recomp.h"
#include "ultramodern/config.hpp"
#include "tooie_asset_mods.h"
#include "tooie_debug.h"
#include "tooie_frame_overlay.h"
#include "tooie_hooks.h"
#include "tooie_interp_check.h"
#include "tooie_interp_tags.h"
#include "tooie_parallax_pick.h"
#include "tooie_model_tagging.h"
#include "tooie_picture_filters.h"
#include "tooie_snout_jiggle.h"
#include "tooie_toast.h"

namespace RT64 {
    void SetFurVertexFlags(uint32_t address, const std::vector<uint8_t> &flags, float anchorScale);
}

namespace {
    // When the program started, for the headless list cycles below.
    const std::chrono::steady_clock::time_point program_start = std::chrono::steady_clock::now();
    constexpr uint32_t op_vtx = 0x01;
    constexpr uint32_t op_popmtx = 0xD8;
    constexpr uint32_t op_mtx = 0xDA;
    constexpr uint32_t op_moveword = 0xDB;
    constexpr uint32_t op_dl = 0xDE;
    constexpr uint32_t op_enddl = 0xDF;
    constexpr uint32_t op_setcimg = 0xFF;
    // G_SETCIMG's pixel size field (bits 19-20), and its value for 8-bit images.
    constexpr uint32_t cimg_size_mask = 0x3 << 19;
    constexpr uint32_t cimg_size_8b = 0x1 << 19;
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
    // Banjo-Tooie's own (lib-patches/rt64.patch): the draws after it are left
    // out of the screen effects (drawn after them) or not.
    constexpr uint32_t g_ex_scene_effects_exclude_v1 = 0x000034;
    // ...and the draws after it get Banjo's fur shells (1) or not (0).
    constexpr uint32_t g_ex_fur_shells_v1 = 0x000035;
    // Kazooie's parts in the Banjo-Kazooie model, by where their lists are from the model's first list: no fur.
    struct FurSpan {
        uint32_t from, to;
    };
    constexpr FurSpan kazooie_parts[] = { { 0x25C8, 0x32B0 } };
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
    constexpr uint32_t slot_size = 0x1E000;
    constexpr uint32_t slot_count = 8;
    // The interpolation check's tint: 64 KB of red after the slots, put in
    // place of a flagged model's textures (red in 16-bit colour, and a red
    // palette entry for colour-indexed ones).
    constexpr uint32_t tint_texture = list_area + slot_size * slot_count;
    constexpr uint32_t tint_size = 0x10000;
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
    // ...and changes of the picture's shape (width over height) by more than
    // this, such as the black bars of a cutscene coming in.
    constexpr float cut_shape = 0.02f;
    constexpr uint16_t game_select_map = 0x158;

    uint32_t slot = 0;
    uint32_t frame_start = 0;

    // For the frame rate overlay: what the last scene tagged.
    std::atomic<uint32_t> stat_models{0};
    std::atomic<uint32_t> stat_bones{0};
    std::atomic<uint32_t> stat_shadows{0};
    std::atomic<uint32_t> stat_cuts{0};
    std::atomic<uint64_t> stat_scenes{0};

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
    struct Particle {
        float pos[3];
        uint32_t instance;
    };
    std::vector<Particle> last_particles;
    // Furthest a particle may move in one game frame and still be paired.
    constexpr float particle_distance = 40.0f;
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

    // Which of Banjo's model's vertices get his fur or her feathers, told by their own colours in the model as loaded
    // (the game lights the vertices in place every frame, so their colours as drawn change with each level's light,
    // and with them the coat: bald in the Flooded Caves and Stomping Plains, fur on his skin in Witchyworld, no
    // feathers under her wings, L). For RT64's SetFurVertexFlags; the marks' values are RT64's FUR_VERTEX_*.
    // His fur: the browns the fur grew on under Spiral Mountain's light (hue 19-34, saturation 0.58 and up), not his
    // skin (hue 9-15, saturation about 0.5) or shorts (hue 39 and up). Her feathers: her reds. White and grey (his eyes,
    // her textured wings) are left to the colour as lit; anything else stays bare.
    enum : uint8_t { mark_unknown = 0, mark_covered = 1, mark_bare = 2, mark_feathers = 3 };
    uint8_t fur_vertex_mark(uint8_t r8, uint8_t g8, uint8_t b8) {
        const float r = r8 / 255.0f, g = g8 / 255.0f, b = b8 / 255.0f;
        const float high = std::max(r, std::max(g, b));
        const float chroma = high - std::min(r, std::min(g, b));
        const float saturation = high > 0.0f ? chroma / high : 0.0f;
        if (saturation < 0.15f) {
            return mark_unknown;
        }
        float hue = 0.0f;
        if (high == r) {
            hue = 60.0f * (g - b) / chroma;
        }
        else if (high == g) {
            hue = 60.0f * (2.0f + (b - r) / chroma);
        }
        else {
            hue = 60.0f * (4.0f + (r - g) / chroma);
        }
        if (hue < 0.0f) {
            hue += 360.0f;
        }
        if (hue >= 19.0f && hue <= 34.0f && saturation >= 0.58f && high >= 0.1f) {
            return mark_covered;
        }
        if ((hue <= 10.0f || hue >= 345.0f) && saturation >= 0.85f && high >= 0.15f) {
            return mark_feathers;
        }
        return mark_bare;
    }

    // The player's model (asset 0x062A, or the model mod that replaces it).
    constexpr uint32_t player_model_asset = 0x062A;

    // How tall a model is in its own units (its vertices' heights), from the model as loaded; 0 if it can't be read.
    float model_height(const std::vector<uint8_t>& asset) {
        auto rd32 = [&](size_t o) { return o + 4 <= asset.size() ? (uint32_t(asset[o]) << 24) | (uint32_t(asset[o + 1]) << 16) | (uint32_t(asset[o + 2]) << 8) | asset[o + 3] : 0u; };
        const size_t vertices = rd32(0x10) + 0x18;
        const size_t count = (rd32(vertices - 4) & 0xFFFF) / 2;
        if (count == 0 || vertices + count * 16 > asset.size()) {
            return 0.0f;
        }
        int low = INT32_MAX, high = INT32_MIN;
        for (size_t v = 0; v < count; v++) {
            const int y = (int16_t)((asset[vertices + v * 16 + 2] << 8) | asset[vertices + v * 16 + 3]);
            low = std::min(low, y);
            high = std::max(high, y);
        }
        return float(high - low);
    }

    // Kazooie's lists in a player model, found from the model's own geo tree rather than fixed offsets, so a
    // model mod (Smash Banjo, Banjo X) keeps fur off Kazooie too. The model is found back from its vertices
    // (segment 1 = model + its vertex block offset + 0x18; the header starts with 0x0B and holds that offset at
    // +0x10). Every draw (geo node 0x11, or a joint draw 0x18) on bone 18, Kazooie's root, or a bone under it
    // is hers; her lists are one run in the model's list (vanilla: commands 1209-2904, Smash Banjo: 6555-14713).
    struct KazooieLists {
        uint32_t vertex_base = 0;
        uint32_t model = 0;
        uint32_t header[3] = {}; // geo tree, list and vertex offsets, to notice another model loaded in its place
        bool found = false;
        uint32_t from = 0, to = 0; // physical addresses of her first and last list
        uint32_t bone_count = 0;
        int32_t kazooie_parent = -1; // bone 18's parent: 13 in Banjo's skeleton
        std::vector<uint32_t> bare; // lists that get no fur or feathers (his feet and hips, her crest), sorted
        std::vector<uint32_t> lists; // her lists (physical addresses), sorted: a model mod can put his among them
    };

    // Banjo-Kazooie's skeletons: the player's (68 bones) and the cutscenes' double (62 bones), told apart from
    // other models by the bone count and the parent of Kazooie's root (bone 18). Model mods keep them. Each has the
    // bones that get no fur: his feet and his hips. The thighs keep theirs, for his knees (L); their shorts stay bare
    // by colour (FurColor in Fur.hlsli). Kazooie's crest gets no feathers (L): the second bone of the chain on her
    // head (head 20 -> 21 -> 22 in the player's, head 25 -> 26 -> 27 in the cutscenes'). TOOIE_FUR_BARE_BONES=<n>,...
    // picks his bare bones instead and TOOIE_KAZOOIE_BARE_BONES=<n>,... hers (headless aids).
    struct BanjoSkeleton {
        uint32_t bone_count;
        int32_t kazooie_parent;
        std::vector<uint32_t> bare;
        std::vector<uint32_t> kazooie_bare; // Kazooie's bones that get no feathers: her crest (L)
    };

    const BanjoSkeleton* banjo_skeleton(uint32_t bone_count, int32_t kazooie_parent) {
        static const std::vector<BanjoSkeleton> skeletons = [] {
            std::vector<BanjoSkeleton> out = {
                { 68, 13, { 1, 62, 63, 66, 67 }, { 22 } },
                { 62, 17, { 1, 53, 54, 57, 58 }, { 27 } },
            };
            if (const char* text = std::getenv("TOOIE_FUR_BARE_BONES")) {
                std::vector<uint32_t> bones;
                char* p = const_cast<char*>(text);
                while (*p != 0) {
                    char* next = p;
                    const uint32_t bone = (uint32_t)std::strtoul(p, &next, 10);
                    if (next == p) {
                        break;
                    }
                    bones.push_back(bone);
                    p = *next == ',' ? next + 1 : next;
                }
                for (BanjoSkeleton& skeleton : out) {
                    skeleton.bare = bones;
                }
            }
            if (const char* text = std::getenv("TOOIE_KAZOOIE_BARE_BONES"); text != nullptr && *text != 0) {
                std::vector<uint32_t> bones;
                char* p = const_cast<char*>(text);
                while (*p != 0) {
                    char* next = p;
                    const uint32_t bone = (uint32_t)std::strtoul(p, &next, 10);
                    if (next == p) {
                        break;
                    }
                    bones.push_back(bone);
                    p = *next == ',' ? next + 1 : next;
                }
                for (BanjoSkeleton& skeleton : out) {
                    skeleton.kazooie_bare = bones;
                }
            }
            return out;
        }();
        for (const BanjoSkeleton& skeleton : skeletons) {
            if (skeleton.bone_count == bone_count && skeleton.kazooie_parent == kazooie_parent) {
                return &skeleton;
            }
        }
        return nullptr;
    }

    uint16_t half(uint8_t* rdram, uint32_t phys) {
        return (uint16_t)MEM_HU(0, kseg0(phys));
    }

    uint8_t byte(uint8_t* rdram, uint32_t phys) {
        return (uint8_t)MEM_BU(0, kseg0(phys));
    }

    // A model's header, found back from its vertices (segment 1 = model + its vertex block offset + 0x18; the header
    // starts with 0x0B and holds that offset at +0x10); 0 if not found.
    uint32_t find_model(uint8_t* rdram, uint32_t vertex_base, uint32_t first_list) {
        constexpr uint32_t ram_size = 0x00800000;
        if (vertex_base < 0x1000 || vertex_base >= ram_size) {
            return 0;
        }
        uint32_t model = 0;
        for (uint32_t back = 0x18; back <= 0x60000 && back + 0x60 <= vertex_base; back += 8) {
            const uint32_t m = vertex_base - back;
            if (word(rdram, m) == 0x0B && word(rdram, m + 0x10) == back - 0x18) {
                model = m;
                break;
            }
        }
        // A model whose vertices are copied for each copy of it (a cutscene's Banjo, his face moving) draws them from
        // elsewhere: then it is found back from its first list, which lies between its list and vertex blocks.
        if (model == 0 && first_list >= 0x1000 && first_list < ram_size) {
            for (uint32_t back = 0x20; back <= 0x80000 && back + 0x60 <= first_list; back += 8) {
                const uint32_t m = first_list - back;
                if (word(rdram, m) == 0x0B && word(rdram, m + 0x0C) + 8 <= back && back < word(rdram, m + 0x10) + 0x18 &&
                    word(rdram, m + 0x10) < 0x80000) {
                    model = m;
                    break;
                }
            }
        }
        return model;
    }

    void read_kazooie_lists(uint8_t* rdram, uint32_t vertex_base, uint32_t first_list, KazooieLists& out) {
        constexpr uint32_t ram_size = 0x00800000;
        constexpr uint32_t kazooie_root = 18;
        out = {};
        out.vertex_base = vertex_base;
        if (vertex_base < 0x1000 || vertex_base >= ram_size) {
            return;
        }
        const uint32_t model = find_model(rdram, vertex_base, first_list);
        if (model == 0) {
            return;
        }
        const uint32_t geo = word(rdram, model + 0x04), list = word(rdram, model + 0x0C), bones = word(rdram, model + 0x18);
        out.model = model;
        out.header[0] = geo;
        out.header[1] = list;
        out.header[2] = word(rdram, model + 0x10);
        if (geo == 0 || list == 0 || bones == 0 || model + geo >= ram_size || model + bones >= ram_size) {
            return;
        }
        const uint32_t bone_count = half(rdram, model + bones + 4);
        if (bone_count <= kazooie_root || bone_count > 256) {
            return;
        }
        out.bone_count = bone_count;
        out.kazooie_parent = (int16_t)half(rdram, model + bones + 8 + kazooie_root * 16 + 14);
        std::vector<bool> bare(bone_count, false);
        if (const BanjoSkeleton* skeleton = banjo_skeleton(bone_count, out.kazooie_parent)) {
            for (uint32_t b : skeleton->bare) {
                if (b < bone_count) {
                    bare[b] = true;
                }
            }
            for (uint32_t b : skeleton->kazooie_bare) {
                if (b < bone_count) {
                    bare[b] = true;
                }
            }
        }
        std::vector<bool> kazooie(bone_count, false);
        for (uint32_t b = 0; b < bone_count; b++) {
            int guard = 0;
            for (int32_t c = (int32_t)b; c >= 0 && c < (int32_t)bone_count && guard++ < 64; c = (int16_t)half(rdram, model + bones + 8 + c * 16 + 14)) {
                if ((uint32_t)c == kazooie_root) {
                    kazooie[b] = true;
                    break;
                }
            }
        }
        // Walk the geo tree (as the game does: 0x02 bone with a child list, 0x0C select with option lists).
        int32_t lo = INT32_MAX, hi = INT32_MIN;
        struct Item { uint32_t node; int32_t bone; };
        std::vector<Item> todo{ { model + geo, -1 } };
        int visited = 0;
        while (!todo.empty() && visited < 20000) {
            Item item = todo.back();
            todo.pop_back();
            for (uint32_t node = item.node; node + 16 < ram_size && visited < 20000; visited++) {
                const uint32_t cmd = word(rdram, node), size = word(rdram, node + 4);
                if (cmd == 0x02) {
                    const uint8_t child = byte(rdram, node + 8);
                    if (child != 0) {
                        todo.push_back({ node + child, byte(rdram, node + 9) });
                    }
                }
                else if (cmd == 0x0C) {
                    const uint16_t count = half(rdram, node + 8);
                    for (uint32_t k = 0; k < count && k < 16; k++) {
                        const uint32_t option = word(rdram, node + 12 + 4 * k);
                        if (option != 0) {
                            todo.push_back({ node + option, item.bone });
                        }
                    }
                }
                else if ((cmd == 0x11 || cmd == 0x18) && item.bone >= 0 && (uint32_t)item.bone < bone_count && kazooie[item.bone]) {
                    // Read signed, as the game does (a big model may put lists before the list header).
                    const int32_t index = (int16_t)half(rdram, node + 8);
                    lo = std::min(lo, index);
                    hi = std::max(hi, index);
                    out.lists.push_back((uint32_t)((int32_t)(model + list + 8) + index * 8));
                    if (bare[item.bone]) {
                        out.bare.push_back((uint32_t)((int32_t)(model + list + 8) + index * 8));
                    }
                    if (std::getenv("TOOIE_KAZOOIE_LIST_CYCLE") != nullptr) {
                        std::fprintf(stderr, "[fur] %u-bone model: Kazooie's bone %d (parent %d) draws list %X\n", bone_count, item.bone,
                            (int16_t)half(rdram, model + bones + 8 + item.bone * 16 + 14), (uint32_t)((int32_t)(model + list + 8) + index * 8));
                    }
                }
                else if ((cmd == 0x11 || cmd == 0x18) && item.bone >= 0 && (uint32_t)item.bone < bone_count && bare[item.bone]) {
                    const int32_t index = (int16_t)half(rdram, node + 8);
                    out.bare.push_back((uint32_t)((int32_t)(model + list + 8) + index * 8));
                }
                if (size == 0 || size > 0x10000) {
                    break;
                }
                node += size;
            }
        }
        if (lo > hi) {
            return;
        }
        std::sort(out.bare.begin(), out.bare.end());
        std::sort(out.lists.begin(), out.lists.end());
        out.found = true;
        out.from = (uint32_t)((int32_t)(model + list + 8) + lo * 8);
        out.to = (uint32_t)((int32_t)(model + list + 8) + hi * 8);
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

    // Ids given out this frame. make_id is a 32-bit hash of models,
    // particles, shadows and the camera in one space, so with a couple of
    // thousand ids a frame two unrelated bones collide now and then; a
    // colliding pair is stable while both are drawn, and RT64 then blends one
    // of them from the other's matrix every frame. A repeat gets a fresh id.
    std::unordered_set<uint32_t> ids_given;
    uint32_t stat_id_repeats = 0;

    uint32_t unique_id(uint32_t id) {
        for (uint32_t n = 1; !ids_given.insert(id).second; n++) {
            id = make_id(id, 0x445550, n);
            stat_id_repeats++;
        }
        return id;
    }

    // gEXMatrixGroup's projection flag.
    constexpr uint32_t group_projection = 1 << 1;

    // A model's print: FNV-1a over the commands of its first list and the
    // lists that one calls (addresses left out, since a model is loaded
    // somewhere else each time; vertex indices, geometry and combiner words
    // kept), so the same model prints the same in every run.
    uint32_t model_print(uint8_t* rdram, uint32_t first) {
        uint32_t hash = 0x811C9DC5u;
        auto mix = [&](uint32_t v) {
            for (int i = 0; i < 4; i++) {
                hash = (hash ^ ((v >> (8 * i)) & 0xFF)) * 0x01000193u;
            }
        };
        int budget = 160;
        std::function<void(uint32_t, int)> walk = [&](uint32_t phys, int depth) {
            for (; budget > 0; budget--, phys += 8) {
                uint32_t w0 = word(rdram, phys);
                uint32_t w1 = word(rdram, phys + 4);
                uint32_t op = w0 >> 24;
                // Texture words change as a texture animates (fire, water),
                // and colours as a thing flashes: only their opcodes count.
                bool texture = op == 0xF5 || op == 0xF2 || op == 0xF3 || op == 0xF4 || op == 0xF0 || op == 0xFA || op == 0xFB;
                bool address = op == op_vtx || op == op_dl || op == op_mtx || op == op_moveword || op == 0xDC || op == 0xFD || op == 0xFE || op == op_setcimg || op == 0x04;
                mix(texture ? op << 24 : w0);
                if (!address && !texture) {
                    mix(w1);
                }
                if (op == op_dl) {
                    if ((w1 & 0x80000000) != 0 && depth < 3) {
                        walk(w1 & 0x1FFFFFFF, depth + 1);
                    }
                    if (((w0 >> 16) & 0xFF) != 0) {
                        return;
                    }
                }
                else if (op == op_enddl) {
                    return;
                }
            }
        };
        walk(first, 0);
        return hash == 0 ? 1 : hash;
    }

    struct Camera {
        float pos[3];
        float forward[3];
        // The projection's width over height.
        float shape;
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
        // The view only turns, so the lengths of the x and y columns are the
        // projection's x and y scales, whose ratio is the picture's shape.
        float x_scale = std::sqrt(m[0][0] * m[0][0] + m[1][0] * m[1][0] + m[2][0] * m[2][0]);
        float y_scale = std::sqrt(m[0][1] * m[0][1] + m[1][1] * m[1][1] + m[2][1] * m[2][1]);
        out.shape = x_scale > 1e-9f ? y_scale / x_scale : 0.0f;
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
        // Drawn into the 8-bit shadow buffer (a model flattened onto the floor
        // by HD Shadows, see ShadowScan); pos is then the mean of its bones.
        bool shadow = false;
        float sum[3] = {};
        // Index of its SEG 2 command, for the interpolation check's tint.
        size_t texture_command = SIZE_MAX;
        // Index of its SEG 1 command (its vertices).
        size_t vertex_command = SIZE_MAX;
        // Its first list as a physical address, and the model's print: a hash
        // of that list's commands (segment-relative, so the same in every
        // run), for the manual tags (tooie_interp_tags.h).
        uint32_t first_phys = 0;
        uint32_t print = 0;
        int tag_mode = 0;
        // Matrix ids given this frame (filled in pass 3).
        std::vector<uint32_t> ids;
    };

    // Interpolation check (F7, see tooie_interp_check.h): what each copy of a
    // model did last frame, by model and copy.
    struct Track {
        float pos[3];
        float step;
        std::vector<uint32_t> ids;
        uint32_t tint_frames;
        bool seen;
        // Seen for two frames, so `step` is a real move.
        bool step_known;
    };
    std::unordered_map<uint64_t, Track> tracks;
    uint64_t check_frame = 0;
    // Game frames a flagged model stays tinted.
    constexpr uint32_t tint_length = 10;
    // A move counts as a jump above this many units per frame and over three
    // times the copy's own move the frame before.
    constexpr float jump_distance = 60.0f;
    // Game units a drawing of a repeated list may move in one frame and
    // still be paired with last frame's.
    constexpr float repeat_distance = 150.0f;
    // ...or, among drawings that mostly moved little, this much.
    constexpr float repeat_close = 40.0f;
    // Game units a bone that swapped its list may be from where it was.
    constexpr float swap_distance = 40.0f;
    // Above this many drawings now times last frame's, they keep draw order.
    constexpr size_t repeat_pairs_max = 16384;

    // Pairs things drawn this frame with last frame's (copies of a model,
    // drawings of a repeated list): the closest pairs first, each used once,
    // none further apart than `limit`. When three or more pair up, one that
    // moved over four times as far as the median (and over `close`) took a
    // vanished neighbour's place rather than moving, so it is left unpaired.
    // Returns, for each of now, the index into last or -1.
    template <typename Now, typename Last>
    std::vector<int> pair_nearest(const std::vector<Now>& now, const std::vector<Last>& last,
                                  const float* (*now_pos)(const Now&), const float* (*last_pos)(const Last&),
                                  float limit, float close) {
        std::vector<int> result(now.size(), -1);
        if (now.empty() || last.empty()) {
            return result;
        }
        std::vector<std::tuple<float, size_t, size_t>> pairs;
        pairs.reserve(now.size() * last.size());
        for (size_t i = 0; i < now.size(); i++) {
            const float* a = now_pos(now[i]);
            for (size_t j = 0; j < last.size(); j++) {
                const float* b = last_pos(last[j]);
                float d = 0.0f;
                for (int k = 0; k < 3; k++) {
                    d += (a[k] - b[k]) * (a[k] - b[k]);
                }
                if (d <= limit * limit) {
                    pairs.emplace_back(d, i, j);
                }
            }
        }
        std::sort(pairs.begin(), pairs.end());
        std::vector<bool> last_taken(last.size(), false);
        std::vector<std::tuple<float, size_t, size_t>> chosen;
        for (const auto& [d, i, j] : pairs) {
            if (result[i] < 0 && !last_taken[j]) {
                result[i] = (int)j;
                last_taken[j] = true;
                chosen.emplace_back(d, i, j);
            }
        }
        if (chosen.size() >= 3) {
            float median = std::get<0>(chosen[chosen.size() / 2]);
            float gate = std::max(close * close, 16.0f * median);
            for (const auto& [d, i, j] : chosen) {
                if (d > gate) {
                    result[i] = -1;
                }
            }
        }
        return result;
    }

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
    if (!overlay) {
        // The 2D overlay is tagged after the scene, in the same frame.
        ids_given.clear();
    }
    // F8 blend modes (interp_check.cpp) for finding what blends wrong on a real PC.
    const int blend_mode = tooie::interp_check::blend_mode();
    static const bool log_ids = std::getenv("TOOIE_TAG_LOG") != nullptr;
    // Manual tags: the Pick Model and Tag Model keys, read once per scene.
    const bool pick_now = !overlay && tooie::interp_tags::take_pick();
    const bool tag_now = !overlay && tooie::interp_tags::take_tag();
    // Interpolation pick mode: the model whose bone RT64 found under the cursor (by last scene's ids) is the picked one.
    static std::unordered_map<uint32_t, uint32_t> mouse_id_models;
    uint32_t mouse_matrix = 0;
    const bool mouse = !overlay && tooie::interp_tags::mouse_pick(mouse_matrix);
    if (!overlay) {
        if (mouse) {
            const auto found = mouse_id_models.find(mouse_matrix);
            const uint32_t model = found == mouse_id_models.end() ? 0 : found->second;
            tooie::interp_tags::set_hovered(model);
            if (model == 0) {
                tooie::interp_tags::set_picked(0, "");
            } else if (model != tooie::interp_tags::picked()) {
                char note[32];
                std::snprintf(note, sizeof(note), " map %X (mouse)", tooie::debug::current_map(rdram));
                tooie::interp_tags::set_picked(model, note);
            }
        }
        mouse_id_models.clear();
    }
    if (!overlay && tooie::interp_tags::take_save()) {
        char text[64];
        std::snprintf(text, sizeof(text), "%zu tags saved to Dev Files/interp_tags.txt", tooie::interp_tags::save());
        tooie::toast::show(text);
    }
    if (!overlay && tooie::interp_tags::take_unsave()) {
        uint32_t current_pick = tooie::interp_tags::picked();
        if (current_pick == 0) {
            tooie::toast::show("Pick a model first (Pick Model key)");
        } else {
            tooie::interp_tags::unsave_picked();
            char text[96];
            std::snprintf(text, sizeof(text), "Model %08X: tag removed from Dev Files/interp_tags.txt", current_pick);
            tooie::toast::show(text);
        }
    }
    const bool effects_now = !overlay && tooie::interp_tags::take_effects();
    const bool interpolating = interpolation_on() && end > start && blend_mode != 1;
    // Without interpolation the scene is still read for the models drawn
    // without effects and for the Pick Model and Model Effects keys.
    const bool excluding = !overlay && end > start && (tooie::interp_tags::any_no_effects() || effects_now || pick_now || mouse);
    // Banjo's fur (Graphics > Banjo fur) needs his model found in the scene.
    const bool banjo_fur = tooie::picture_filters::banjo_fur_on();
    const bool kazooie_feathers = tooie::picture_filters::kazooie_feathers_on();
    const bool npc_fur = tooie::picture_filters::npc_fur_on();
    const bool npc_feathers = tooie::picture_filters::npc_feathers_on();
    const bool fur = !overlay && end > start && (banjo_fur || kazooie_feathers || npc_fur || npc_feathers);
    if (!interpolating && !excluding && !fur) {
        if (!overlay) {
            stat_models = 0;
            stat_bones = 0;
            stat_shadows = 0;
        }
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
    // Whether the commands end with the list's own end (G_ENDDL or a branch), right after the last of them.
    bool ends_list = false;
    std::vector<Block> blocks;
    int current = -1;
    bool have_camera = false;
    bool shadow_buffer = false;
    Camera camera;
    std::array<uint32_t, 16> segments{};
    for (uint32_t p = start; p < end; p += 8) {
        uint32_t w0 = word(rdram, p);
        uint32_t w1 = word(rdram, p + 4);
        uint32_t op = w0 >> 24;
        if (op == op_setcimg) {
            shadow_buffer = (w0 & cimg_size_mask) == cimg_size_8b;
        }
        if (op == op_moveword && ((w0 >> 16) & 0xFF) == moveword_segment) {
            segments[((w0 & 0xFFFF) / 4) & 0xF] = w1 & 0x1FFFFFFF;
        }
        if (op == op_moveword && ((w0 >> 16) & 0xFF) == moveword_segment && (w0 & 0xFFFF) == 4) {
            blocks.emplace_back();
            current = (int)blocks.size() - 1;
            blocks[current].vertex_command = commands.size();
            blocks[current].shadow = shadow_buffer;
        }
        else if (op == op_moveword && ((w0 >> 16) & 0xFF) == moveword_segment && (w0 & 0xFFFF) == 8 && current >= 0) {
            blocks[current].textures = w1;
            blocks[current].texture_command = commands.size();
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
                if (block.shadow) {
                    float t[3];
                    read_translation(rdram, w1 & 0x1FFFFFFF, t);
                    for (int k = 0; k < 3; k++) {
                        block.sum[k] += t[k];
                    }
                }
                block.matrices++;
            }
        }
        else if (op == op_dl && current >= 0 && blocks[current].first_list == 0) {
            blocks[current].first_list = w1;
            blocks[current].first_phys = (w1 & 0x80000000) != 0 ? (w1 & 0x1FFFFFFF) :
                ((segments[(w1 >> 24) & 0xF] + (w1 & 0xFFFFFF)) & 0x1FFFFFFF);
        }
        else if (op == op_enddl || (op == op_dl && ((w0 >> 16) & 0xFF) != 0)) {
            ends_list = true;
            break;
        }
        commands.push_back({w0, w1, current});
    }
    for (Block& block : blocks) {
        // Particles (fire, dust, feathers) set no texture segment and draw
        // from lists the game builds anew every frame, one matrix per
        // particle; they are paired one by one below instead.
        block.model = block.first_list == 0 || block.textures == 0 || overlay ? 0 : make_id(block.first_list, block.textures, 0);
        // HD Shadows draws a character's own model flattened into the shadow
        // buffer, right next to the character: its root is on the same floor
        // point, so the shadow (one per light) and the character were matched
        // to each other's copies. A shadow is its own model, placed by the
        // middle of its bones, which differs with the light's direction.
        if (block.model != 0 && block.shadow && block.matrices != 0) {
            block.model = make_id(block.model, 0x534844, 0);
            for (int k = 0; k < 3; k++) {
                block.pos[k] = block.sum[k] / (float)block.matrices;
            }
        }
    }

    // Manual tags (tooie_interp_tags.h): each model's print, and its tag.
    // The tags only count in the custom blend mode (normal plus the tags).
    const bool custom = blend_mode == tooie::interp_check::blend_custom;
    // (Furry enemies and feathered NPCs are known by their prints too.)
    const bool tags_wanted = !overlay && ((custom && tooie::interp_tags::any()) || tooie::interp_tags::picked() != 0 || pick_now || tag_now || mouse || log_ids ||
        excluding || (end > start && (npc_fur || npc_feathers)));
    if (tags_wanted) {
        for (Block& block : blocks) {
            // Particles (fire, say) have a print too: their lists are built
            // each frame but read the same with the addresses left out.
            if ((block.model != 0 || (block.textures == 0 && block.matrices != 0)) && block.first_phys != 0) {
                block.print = model_print(rdram, block.first_phys);
                block.tag_mode = custom ? tooie::interp_tags::mode_of(block.print) : tooie::interp_tags::mode_default;
                if (log_ids && block.tag_mode != tooie::interp_tags::mode_default) {
                    static std::unordered_map<uint32_t, int> logged;
                    if (logged[block.print] != block.tag_mode) {
                        logged[block.print] = block.tag_mode;
                        std::fprintf(stderr, "[interp-tags] model %08X drawn as %s\n", block.print, tooie::interp_tags::mode_name(block.tag_mode));
                    }
                }
                if (log_ids) {
                    // Headless: each print once, with where it was seen.
                    static std::unordered_set<uint32_t> printed;
                    if (printed.insert(block.print).second) {
                        std::fprintf(stderr, "[print] %s %08X list %08X map %X at %.0f,%.0f,%.0f (%u matrices)\n", block.model != 0 ? "model" : "particle",
                            block.print, block.first_phys, tooie::debug::current_map(rdram), block.pos[0], block.pos[1], block.pos[2], block.matrices);
                    }
                }
            }
        }
    }

    // A camera cut: the camera jumps or turns sharply in one game frame, or
    // the picture changes shape. Blending across it would slide everything
    // (characters placed for the new shot included) through the in-between
    // frames. A shape change comes with a new viewport, which RT64 does not
    // blend, so a blended projection would squash or stretch the picture for
    // an in-between frame (the black bars of a cutscene coming in, say).
    if (pick_now) {
        // The models on screen, nearest the middle of the picture first (by
        // the angle from the camera's facing); the pick steps through them.
        struct Candidate {
            uint32_t print;
            float cosine;
            const Block* block;
        };
        std::vector<Candidate> candidates;
        for (const Block& block : blocks) {
            if (block.matrices == 0 || block.shadow || block.print == 0 || !block.have_pos) {
                continue;
            }
            bool seen = false;
            for (const Candidate& c : candidates) {
                seen = seen || c.print == block.print;
            }
            if (seen) {
                continue;
            }
            float cosine = 1.0f;
            if (have_camera) {
                float d[3];
                float length = 0.0f;
                for (int k = 0; k < 3; k++) {
                    d[k] = block.pos[k] - camera.pos[k];
                    length += d[k] * d[k];
                }
                length = std::sqrt(length);
                cosine = 0.0f;
                for (int k = 0; k < 3; k++) {
                    cosine += length > 1e-3f ? d[k] * camera.forward[k] / length : 0.0f;
                }
            }
            candidates.push_back({block.print, cosine, &block});
        }
        std::stable_sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) { return a.cosine > b.cosine; });
        if (candidates.empty()) {
            tooie::toast::show("No model to pick");
        } else {
            size_t next = 0;
            uint32_t current_pick = tooie::interp_tags::picked();
            for (size_t i = 0; i < candidates.size(); i++) {
                if (candidates[i].print == current_pick) {
                    next = (i + 1) % candidates.size();
                }
            }
            const Candidate& c = candidates[next];
            char note[96];
            std::snprintf(note, sizeof(note), " map %X at %.0f,%.0f,%.0f (%u matrices%s)", tooie::debug::current_map(rdram),
                c.block->pos[0], c.block->pos[1], c.block->pos[2], c.block->matrices, c.block->model == 0 ? ", particle" : "");
            tooie::interp_tags::set_picked(c.print, note);
            char text[128];
            std::snprintf(text, sizeof(text), "Picked model %08X (%zu of %zu): %s", c.print, next + 1, candidates.size(),
                tooie::interp_tags::describe(c.print).c_str());
            tooie::toast::show(text);
            std::printf("[interp-tags] picked %08X:%s\n", c.print, note);
        }
    }
    if (tag_now) {
        uint32_t current_pick = tooie::interp_tags::picked();
        if (current_pick == 0) {
            tooie::toast::show("Pick a model first (Pick Model key)");
        } else {
            int mode = tooie::interp_tags::step_picked();
            char text[96];
            std::snprintf(text, sizeof(text), "Model %08X: %s%s", current_pick, tooie::interp_tags::mode_name(mode),
                custom ? "" : " (blend mode set to custom)");
            tooie::toast::show(text);
            if (!custom) {
                // Tags only show in the custom mode; the next scene runs in it.
                tooie::interp_check::set_blend_mode(tooie::interp_check::blend_custom);
            }
            for (Block& block : blocks) {
                if (block.print == current_pick) {
                    block.tag_mode = mode;
                }
            }
        }
    }

    if (effects_now) {
        uint32_t current_pick = tooie::interp_tags::picked();
        if (current_pick == 0) {
            tooie::toast::show("Pick a model first (Pick Model key)");
        } else {
            bool off = tooie::interp_tags::toggle_picked_effects();
            char text[96];
            std::snprintf(text, sizeof(text), "Model %08X: effects %s", current_pick, off ? "off" : "on");
            tooie::toast::show(text);
        }
    }

    // The command a flag set just before index lands on: texture rectangles (their coordinates follow them) are
    // passed over. SIZE_MAX when there is none (the list's own end only counts when the walk stopped at it).
    auto flag_slot = [&](size_t index) -> size_t {
        for (; index < commands.size(); index++) {
            const uint32_t op = word(rdram, start + (uint32_t)index * 8) >> 24;
            if (op != 0xE4 && op != 0xE5 && op != 0xE1 && op != 0xF1) {
                return index;
            }
        }
        return (index == commands.size() && ends_list) ? index : SIZE_MAX;
    };
    // Sets one of RT64's extended flags (G_EX opcode and value) just before command slot (from flag_slot): that
    // command is called through a small list that sets the flag first. The list's own end (G_ENDDL or a branch) is
    // branched to the small list instead, which then ends the list as before. Without that, a flag turned on for
    // the last model of a list (Bottles' ghost: effects off) stayed on for everything drawn after it, the level
    // included, and the 3D grass and other effects vanished (L, 2026-10-16).
    auto set_flag = [&](uint32_t& cursor, size_t slot, uint32_t ex_opcode, uint32_t value) {
        const uint32_t p = start + (uint32_t)slot * 8;
        const uint32_t w0 = word(rdram, p);
        const bool end = (slot == commands.size());
        const uint32_t list = cursor;
        put(rdram, cursor, rt64_hook_word0, (rt64_hook_op_enable << 28) | rt64_extended_opcode);
        put(rdram, cursor + 8, (rt64_extended_opcode << 24) | ex_opcode, value);
        put(rdram, cursor + 16, w0, word(rdram, p + 4));
        put(rdram, cursor + 24, op_enddl << 24, 0);
        cursor += 32;
        put(rdram, p, (op_dl << 24) | (end ? (1u << 16) : 0u), list);
    };

    // Models without the screen effects: the command that starts each one
    // (its segment 1) and the command after its last are called through a
    // small list that first sets RT64's exclude flag (on, then off). Reads the
    // commands as they are now, so after the interpolation tags. A model is
    // only marked when both its on and its off have a place and room.
    auto mark_no_effects = [&](uint32_t& cursor, uint32_t limit) {
        if (!tooie::interp_tags::any_no_effects()) {
            return;
        }
        std::vector<int> mark(commands.size() + 1, -1);
        for (size_t b = 0; b < blocks.size(); b++) {
            const Block& block = blocks[b];
            if (block.print == 0 || block.shadow || block.vertex_command == SIZE_MAX) {
                continue;
            }
            // 1: drawn after the effects; 2: drawn in place without writing depth.
            const int value = tooie::interp_tags::no_effects_for(block.print) ? 1 : (tooie::interp_tags::no_depth_for(block.print) ? 2 : 0);
            if (value == 0) {
                continue;
            }
            size_t last = block.vertex_command;
            for (size_t i = block.vertex_command; i < commands.size(); i++) {
                if (commands[i].block == (int)b) {
                    last = i;
                }
            }
            const size_t on = flag_slot(block.vertex_command);
            const size_t off = flag_slot(last + 1);
            if (on == SIZE_MAX || off == SIZE_MAX || on >= off) {
                continue;
            }
            mark[on] = value;
            if (mark[off] <= 0) {
                mark[off] = 0;
            }
        }
        // In order, each change of the flag; an on is only set with room for the off after it.
        int state = 0;
        for (size_t i = 0; i < mark.size(); i++) {
            if (mark[i] < 0 || mark[i] == state) {
                continue;
            }
            if (cursor + (mark[i] > 0 ? 64 : 32) > limit) {
                if (mark[i] > 0) {
                    break;
                }
                continue;
            }
            set_flag(cursor, i, g_ex_scene_effects_exclude_v1, (uint32_t)mark[i]);
            state = mark[i];
        }
    };
    auto mark_fur = [&](uint32_t& cursor, uint32_t limit) {
        if (!fur) {
            return;
        }
        static const bool log_fur = std::getenv("TOOIE_FUR_LOG") != nullptr;
        // Each model's skeleton and lists, cached by where its vertices are (read again when another model is
        // loaded there).
        static std::unordered_map<uint32_t, KazooieLists> models;
        auto lists_of = [&](int b) -> const KazooieLists& {
            if (models.size() > 64) {
                models.clear();
            }
            const uint32_t vertex_base = commands[blocks[b].vertex_command].w1 & 0x1FFFFFFF;
            auto found = models.find(vertex_base);
            KazooieLists& lists = models[vertex_base];
            const bool same = found != models.end() && (lists.model == 0 ||
                (word(rdram, lists.model) == 0x0B && word(rdram, lists.model + 0x04) == lists.header[0] &&
                 word(rdram, lists.model + 0x0C) == lists.header[1] && word(rdram, lists.model + 0x10) == lists.header[2]));
            if (!same) {
                read_kazooie_lists(rdram, vertex_base, blocks[b].first_phys, lists);
                if (log_fur) {
                    std::fprintf(stderr, "[fur] model at %X: %u bones, Kazooie's lists %s: %X-%X\n", vertex_base, lists.bone_count,
                        lists.found ? "found" : "not found", lists.from, lists.to);
                }
            }
            return lists;
        };
        // Banjo is a model with one of Banjo-Kazooie's skeletons (banjo_skeleton: the player's, or his double in
        // cutscenes), nearest the player if there are more; others with many bones (Mumbo, say) have another.
        // Failing that (Banjo alone), the model with many bones nearest to where Banjo stands.
        float at[3] = {};
        bool have_player = false;
        const uint32_t player = (uint32_t)MEM_W(0, (int32_t)0x80135490);
        if (player >= 0x80000000u && player < 0x80800000u) {
            const uint32_t transform = (uint32_t)MEM_W(0xE4, (int32_t)player);
            if (transform >= 0x80000000u && transform < 0x80800000u) {
                for (int k = 0; k < 3; k++) {
                    const uint32_t bits = (uint32_t)MEM_W(4 * k, (int32_t)transform);
                    std::memcpy(&at[k], &bits, sizeof(float));
                }
                have_player = at[0] != 0.0f || at[1] != 0.0f || at[2] != 0.0f;
            }
        }
        // The form byte (ScriptHawk's character_state): 1 Banjo-Kazooie, 10 Banjo alone.
        const uint8_t form = (uint8_t)MEM_B(0, (int32_t)0x80136F63);
        int best = -1;
        bool skeleton = false;
        float best_distance = 150.0f * 150.0f;
        for (size_t b = 0; b < blocks.size(); b++) {
            const Block& block = blocks[b];
            if (block.shadow || block.model == 0 || !block.have_pos || block.matrices < 20 || block.vertex_command == SIZE_MAX) {
                continue;
            }
            float d = 0.0f;
            for (int k = 0; k < 3; k++) {
                d += (block.pos[k] - at[k]) * (block.pos[k] - at[k]);
            }
            const KazooieLists& lists = lists_of((int)b);
            const bool banjo = lists.found && banjo_skeleton(lists.bone_count, lists.kazooie_parent) != nullptr;
            if (banjo && (!skeleton || d < best_distance)) {
                skeleton = true;
                best_distance = d;
                best = (int)b;
            }
            else if (!skeleton && !banjo && have_player && form == 10 && d < best_distance) {
                best_distance = d;
                best = (int)b;
            }
        }
        if (log_fur) {
            static uint32_t logged = 0;
            if ((logged++ % 60) == 0) {
                std::fprintf(stderr, "[fur] form %u, Banjo at %.0f,%.0f,%.0f, model %s", form, at[0], at[1], at[2], best < 0 ? "not found" : skeleton ? "found by skeleton" : "found nearby");
                if (best >= 0) {
                    std::fprintf(stderr, " %.0f units off (%u matrices)", std::sqrt(best_distance), blocks[best].matrices);
                }
                std::fprintf(stderr, "\n");
            }
        }
        // Furry enemies get white fur all over (RT64's kind 3): Hailfire Peaks' yetis (L). Feathered NPCs get feathers
        // like Kazooie's in their own colours (kind 4): Canary Mary (L). Known by their model's print (Block::print),
        // the same in every run, and where another model prints the same (Mary's race cart does), by how many
        // matrices it has (0: any). Lists that stay bare are listed for each, by where they are from the model's first
        // own list (Mary: her crest, beak and face; the yeti: his face, eyes and hands, L).
        // TOOIE_FEATHER_PRINTS=<hex>,... adds feathered ones and TOOIE_NPC_BARE_LISTS=<hex>[-<hex>],... sets every
        // one's bare lists (headless aids, with TOOIE_FUR_LOG listing a model's lists).
        struct Covered {
            uint32_t print;
            uint32_t kind;
            uint32_t matrices;
            std::vector<uint32_t> bare; // its lists that stay bare, by where they are from its first own list
        };
        static const std::vector<Covered> covered = [] {
            std::vector<Covered> out = {
                { 0xE23CADDF, 3, 0, {} }, // the yeti on Hailfire Peaks' Icy Side
                { 0x765B856B, 4, 41, { 0x160, 0x538 } }, // Canary Mary (her races); her crest, and her face and beak
            };
            if (const char* text = std::getenv("TOOIE_FEATHER_PRINTS")) {
                char* p = const_cast<char*>(text);
                while (*p != 0) {
                    out.push_back({ (uint32_t)std::strtoul(p, &p, 16), 4, 0, {} });
                    if (*p != ',') {
                        break;
                    }
                    p++;
                }
            }
            if (const char* text = std::getenv("TOOIE_NPC_BARE_LISTS"); text != nullptr && *text != 0) {
                std::vector<uint32_t> bones;
                char* p = const_cast<char*>(text);
                while (*p != 0) {
                    const uint32_t from = (uint32_t)std::strtoul(p, &p, 16);
                    const uint32_t to = *p == '-' ? (uint32_t)std::strtoul(p + 1, &p, 16) : from;
                    for (uint32_t o = from; o <= to && bones.size() < 4096; o += 8) {
                        bones.push_back(o);
                    }
                    if (*p != ',') {
                        break;
                    }
                    p++;
                }
                std::sort(bones.begin(), bones.end());
                for (Covered& c : out) {
                    c.bare = bones;
                }
            }
            return out;
        }();
        if (npc_fur || npc_feathers) {
            for (size_t b = 0; b < blocks.size(); b++) {
                const Block& block = blocks[b];
                if (block.shadow || block.vertex_command == SIZE_MAX) {
                    continue;
                }
                const Covered* match = nullptr;
                for (const Covered& c : covered) {
                    if (c.print == block.print && (c.matrices == 0 || c.matrices == block.matrices) && ((c.kind == 3) ? npc_fur : npc_feathers)) {
                        match = &c;
                    }
                }
                if (match == nullptr) {
                    continue;
                }
                // Its first own list (Mary's first call is a list other models share, which gives her print).
                uint32_t own = 0;
                for (size_t i = block.vertex_command; i < commands.size() && own == 0; i++) {
                    const uint32_t target = commands[i].w1 & 0x1FFFFFFF;
                    if (commands[i].block == (int)b && (commands[i].w0 >> 24) == op_dl && target > block.first_phys) {
                        own = target;
                    }
                }
                if (log_fur) {
                    static std::unordered_set<uint32_t> dumped;
                    if (dumped.insert(block.print * 31 + block.matrices).second) {
                        std::fprintf(stderr, "[fur] model %08X (%u matrices) lists from its first:", block.print, block.matrices);
                        for (size_t i = block.vertex_command; i < commands.size(); i++) {
                            if (commands[i].block == (int)b && (commands[i].w0 >> 24) == op_dl) {
                                std::fprintf(stderr, " %X", (commands[i].w1 & 0x1FFFFFFF) - own);
                            }
                        }
                        std::fprintf(stderr, "\n");
                    }
                }
                // TOOIE_NPC_LIST_CYCLE=<from ms>:<every ms>[:<calls>] covers only one of its calls at a time, the next every so
                // often, logged, to tell which call draws which part (headless aid).
                static const struct Cycle { bool on = false; long from = 0, every = 1000, count = 64; } cycle = [] {
                    Cycle c;
                    if (const char* text = std::getenv("TOOIE_NPC_LIST_CYCLE")) {
                        c.on = std::sscanf(text, "%ld:%ld:%ld", &c.from, &c.every, &c.count) >= 2 && c.every > 0 && c.count > 0;
                    }
                    return c;
                }();
                long only = -1;
                if (cycle.on) {
                    const long ms = (long)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - program_start).count();
                    only = ms < cycle.from ? -2 : ((ms - cycle.from) / cycle.every) % cycle.count;
                    static long logged_only = -3;
                    if (only != logged_only) {
                        logged_only = only;
                        std::fprintf(stderr, "[fur] cycle: only call %ld\n", only);
                    }
                }
                long call = 0;
                uint32_t on = 0;
                size_t last = block.vertex_command;
                bool marked = false;
                for (size_t i = block.vertex_command; i < commands.size(); i++) {
                    if (commands[i].block != (int)b) {
                        continue;
                    }
                    last = i;
                    if ((commands[i].w0 >> 24) != op_dl) {
                        continue;
                    }
                    uint32_t want = std::binary_search(match->bare.begin(), match->bare.end(), (commands[i].w1 & 0x1FFFFFFF) - own) ? 0 : match->kind;
                    if (cycle.on && call++ != only) {
                        want = 0;
                    }
                    if (want != on) {
                        const size_t slot = flag_slot(i);
                        if (slot == SIZE_MAX || cursor + 64 > limit) {
                            if (log_fur) {
                                static uint32_t logged_miss = 0;
                                if ((logged_miss++ % 120) == 0) {
                                    std::fprintf(stderr, "[fur] model %08X: no room to mark list %X (%s)\n", block.print, (commands[i].w1 & 0x1FFFFFFF) - own, slot == SIZE_MAX ? "no slot" : "area full");
                                }
                            }
                            continue;
                        }
                        set_flag(cursor, slot, g_ex_fur_shells_v1, want);
                        on = want;
                        marked = true;
                    }
                }
                if (on != 0) {
                    const size_t off_slot = flag_slot(last + 1);
                    if (off_slot != SIZE_MAX && cursor + 32 <= limit) {
                        set_flag(cursor, off_slot, g_ex_fur_shells_v1, 0);
                    }
                }
                if (log_fur) {
                    static uint32_t logged_covered = 0;
                    if ((logged_covered++ % 120) == 0) {
                        std::fprintf(stderr, "[fur] model %08X gets kind %u (%s)\n", block.print, match->kind, marked ? "marked" : "no slot");
                    }
                }
            }
        }
        if (best < 0) {
            return;
        }
        // His vertices' marks, from the player's model as loaded (once each time it is loaded); none for another model
        // (his cutscene double), which keeps the colour test. TOOIE_FUR_MARKS=0 leaves them all to it (headless aid).
        {
            static const bool marks_off = [] { const char* text = std::getenv("TOOIE_FUR_MARKS"); return text != nullptr && *text == '0'; }();
            static uint32_t sent_block = 0;
            static uint32_t sent_header[3] = {};
            const KazooieLists& model = lists_of(best);
            const uint32_t block = skeleton && model.model != 0 && !marks_off ? model.model + model.header[2] + 0x18 : 0;
            if (block != sent_block || (block != 0 && std::memcmp(sent_header, model.header, sizeof(sent_header)) != 0)) {
                if (sent_block != 0) {
                    RT64::SetFurVertexFlags(sent_block, {}, 1.0f);
                }
                sent_block = block;
                std::memcpy(sent_header, model.header, sizeof(sent_header));
                if (block != 0) {
                    const std::vector<uint8_t> asset = tooie::asset_mods::asset_bytes(player_model_asset);
                    auto rd32 = [&](size_t o) { return o + 4 <= asset.size() ? (uint32_t(asset[o]) << 24) | (uint32_t(asset[o + 1]) << 16) | (uint32_t(asset[o + 2]) << 8) | asset[o + 3] : 0u; };
                    std::vector<uint8_t> marks;
                    // A model mod made at another scale (Smash Banjo's vertices are 8 times Tooie's) gets the fur's
                    // strands as thick as on Tooie's Banjo, by its height against his.
                    static const float vanilla_height = model_height(tooie::asset_mods::rom_asset_bytes(player_model_asset));
                    const float height = model_height(asset);
                    const float anchor_scale = (vanilla_height > 0.0f && height > 0.0f) ? std::clamp(vanilla_height / height, 0.01f, 100.0f) : 1.0f;
                    if (rd32(0x04) == model.header[0] && rd32(0x0C) == model.header[1] && rd32(0x10) == model.header[2]) {
                        const size_t vertices = model.header[2] + 0x18;
                        const size_t count = (rd32(model.header[2] + 0x14) & 0xFFFF) / 2;
                        if (vertices + count * 16 <= asset.size()) {
                            marks.resize(count);
                            for (size_t v = 0; v < count; v++) {
                                const size_t at = vertices + v * 16 + 12;
                                marks[v] = fur_vertex_mark(asset[at], asset[at + 1], asset[at + 2]);
                            }
                        }
                    }
                    RT64::SetFurVertexFlags(block, marks, anchor_scale);
                    if (log_fur) {
                        std::fprintf(stderr, "[fur] vertex marks at %X: %zu vertices, anchor scale %.3f%s\n", block, marks.size(), anchor_scale,
                            marks.empty() ? " (not the player's model)" : "");
                    }
                }
            }
        }
        // Fur goes on Banjo's own parts only, not Kazooie's: RT64's fur flag is turned off round the model's
        // calls to Kazooie's parts and on again after. A part is known by where its list is in the model, from the
        // model's first list (the same however the model is placed in memory; Kazooie's parts are only called when
        // she is out of the backpack). TOOIE_FUR_SKIP=<from>-<to>[,...] (hex) picks them instead (headless aid).
        struct Span {
            uint32_t from, to;
        };
        static const bool fur_skip_set = std::getenv("TOOIE_FUR_SKIP") != nullptr;
        static const std::vector<Span> skip = [] {
            std::vector<Span> spans;
            if (const char* text = std::getenv("TOOIE_FUR_SKIP")) {
                char* p = const_cast<char*>(text);
                while (*p != 0) {
                    const uint32_t from = (uint32_t)std::strtoul(p, &p, 16);
                    const uint32_t to = *p == '-' ? (uint32_t)std::strtoul(p + 1, &p, 16) : from;
                    spans.push_back({from, to});
                    if (*p != ',') {
                        break;
                    }
                    p++;
                }
            }
            else {
                for (const FurSpan& span : kazooie_parts) {
                    spans.push_back({span.from, span.to});
                }
            }
            return spans;
        }();
        auto wrap = [&](size_t index, uint32_t kind) {
            const size_t slot = flag_slot(index);
            if (slot == SIZE_MAX || cursor + 32 > limit) {
                return;
            }
            set_flag(cursor, slot, g_ex_fur_shells_v1, kind);
        };
        uint32_t base = blocks[best].first_phys;
        const KazooieLists& kazooie = lists_of(best);
        const Span model_skip[1] = { { kazooie.from, kazooie.to } };
        const bool use_model_skip = !fur_skip_set && kazooie.found;
        if (use_model_skip) {
            base = 0; // the spans below are physical addresses
        }
        const Span* spans_begin = use_model_skip ? model_skip : skip.data();
        const Span* spans_end = use_model_skip ? model_skip + 1 : skip.data() + skip.size();
        // TOOIE_KAZOOIE_LIST_CYCLE=<from ms>:<every ms>[:<calls>] feathers only one of Kazooie's calls at a time, the next every
        // so often, logged with its list's address, to tell which call draws which part (headless aid).
        static const struct KazooieCycle { bool on = false; long from = 0, every = 1000, count = 64; } kazooie_cycle = [] {
            KazooieCycle c;
            if (const char* text = std::getenv("TOOIE_KAZOOIE_LIST_CYCLE")) {
                c.on = std::sscanf(text, "%ld:%ld:%ld", &c.from, &c.every, &c.count) >= 2 && c.every > 0 && c.count > 0;
            }
            return c;
        }();
        long kazooie_only = -1, kazooie_call = 0;
        if (kazooie_cycle.on) {
            const long ms = (long)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - program_start).count();
            kazooie_only = ms < kazooie_cycle.from ? -2 : ((ms - kazooie_cycle.from) / kazooie_cycle.every) % kazooie_cycle.count;
            static long logged_only = -3;
            if (kazooie_only != logged_only) {
                logged_only = kazooie_only;
                std::fprintf(stderr, "[fur] Kazooie cycle: only call %ld\n", kazooie_only);
            }
        }
        // Each list's kind: 1 Banjo's fur, 2 Kazooie's feathers, 0 neither (his feet and shorts, or one that is off).
        uint32_t on = 0;
        size_t last = blocks[best].vertex_command;
        for (size_t i = blocks[best].vertex_command; i < commands.size(); i++) {
            if (commands[i].block != best) {
                continue;
            }
            last = i;
            if ((commands[i].w0 >> 24) != op_dl || (commands[i].w1 & 0x1FFFFFFF) < base) {
                continue;
            }
            const uint32_t offset = (commands[i].w1 & 0x1FFFFFFF) - base;
            bool banjo = true;
            if (use_model_skip) {
                // Her lists themselves, not the span from her first to her last: Smash Banjo v13 has his lists
                // among hers, which left him with no fur at all (L).
                banjo = !std::binary_search(kazooie.lists.begin(), kazooie.lists.end(), commands[i].w1 & 0x1FFFFFFF);
            }
            else {
                for (const Span* span = spans_begin; span != spans_end; span++) {
                    banjo = banjo && (offset < span->from || offset > span->to);
                }
            }
            uint32_t want = banjo ? 1 : (kazooie.found ? 2 : 0);
            if (use_model_skip &&
                std::binary_search(kazooie.bare.begin(), kazooie.bare.end(), commands[i].w1 & 0x1FFFFFFF)) {
                want = 0;
            }
            if ((want == 1 && !banjo_fur) || (want == 2 && !kazooie_feathers)) {
                want = 0;
            }
            if (want == 2 && kazooie_cycle.on && kazooie_call++ != kazooie_only) {
                want = 0;
            }
            else if (want == 2 && kazooie_cycle.on) {
                static long logged_call = -3;
                if (logged_call != kazooie_only) {
                    logged_call = kazooie_only;
                    std::fprintf(stderr, "[fur] Kazooie cycle: call %ld is list %X\n", kazooie_only, commands[i].w1 & 0x1FFFFFFF);
                }
            }
            if (want != on) {
                wrap(i, want);
                on = want;
            }
        }
        if (on != 0) {
            wrap(last + 1, 0);
        }
    };
    if (!interpolating) {
        slot = (slot + 1) % slot_count;
        uint32_t cursor = list_area + slot * slot_size;
        mark_no_effects(cursor, cursor + slot_size);
        mark_fur(cursor, cursor + slot_size);
        if (!overlay) {
            stat_models = 0;
            stat_bones = 0;
            stat_shadows = 0;
        }
        return 0;
    }

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
            bool reshaped = std::fabs(camera.shape - last_camera.shape) > cut_shape * last_camera.shape;
            cut = moved > limit * limit || facing < cut_cosine || reshaped;
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
        stat_cuts++;
    }

    // Pass 2: match each copy of a model to last frame's nearest copy, the
    // closest pairs first (in draw order, an early copy could take a later
    // one's match). Any copy may move alone (a note being collected), so
    // none is left unpaired for moving more than the rest.
    std::unordered_map<uint32_t, std::vector<Copy>> now;
    {
        std::unordered_map<uint32_t, std::vector<Block*>> by_model;
        for (Block& block : blocks) {
            if (block.model != 0 && block.matrices != 0) {
                by_model[block.model].push_back(&block);
            }
        }
        for (auto& [model, copies] : by_model) {
            static const std::vector<Copy> none;
            auto found = previous.find(model);
            const std::vector<Copy>& last = cut || found == previous.end() ? none : found->second;
            std::vector<int> match = pair_nearest<Block*, Copy>(copies, last,
                [](Block* const& block) -> const float* { return block->pos; },
                [](const Copy& copy) -> const float* { return copy.pos; },
                teleport_distance, teleport_distance);
            for (size_t i = 0; i < copies.size(); i++) {
                Block& block = *copies[i];
                block.instance = match[i] >= 0 ? last[match[i]].instance : next_instance++;
                Copy copy;
                copy.pos[0] = block.pos[0];
                copy.pos[1] = block.pos[1];
                copy.pos[2] = block.pos[2];
                copy.instance = block.instance;
                now[model].push_back(copy);
            }
        }
    }
    // The 2D has no models of its own; keep the scene's for next frame.
    if (!overlay) {
        previous = std::move(now);
    }

    // Particles (fire, dust, feathers): one matrix each, in lists the game
    // rebuilds every frame. Left to RT64's automatic matching, look-alike
    // flames got paired with each other and jumped about between frames.
    // Each is paired with the nearest particle of last frame instead, and one
    // with none near enough is drawn as it is.
    std::vector<uint32_t> particle_id(commands.size(), 0);
    if (!overlay) {
        struct Candidate {
            float distance;
            size_t now;
            size_t last;
        };
        std::vector<Particle> current;
        std::vector<size_t> current_command;
        for (size_t i = 0; i < commands.size(); i++) {
            const Command& c = commands[i];
            if ((c.w0 >> 24) != op_mtx || c.block < 0 || (((c.w0 & 0xFF) ^ 1) & mtx_projection) != 0) {
                continue;
            }
            const Block& block = blocks[c.block];
            if (block.first_list == 0 || block.textures != 0) {
                continue;
            }
            Particle particle;
            read_translation(rdram, c.w1 & 0x1FFFFFFF, particle.pos);
            particle.instance = 0;
            current.push_back(particle);
            current_command.push_back(i);
        }
        std::vector<Candidate> candidates;
        if (!cut) {
            for (size_t a = 0; a < current.size(); a++) {
                for (size_t b = 0; b < last_particles.size(); b++) {
                    float d = 0.0f;
                    for (int k = 0; k < 3; k++) {
                        float diff = current[a].pos[k] - last_particles[b].pos[k];
                        d += diff * diff;
                    }
                    if (d < particle_distance * particle_distance) {
                        candidates.push_back({d, a, b});
                    }
                }
            }
        }
        std::sort(candidates.begin(), candidates.end(), [](const Candidate& x, const Candidate& y) { return x.distance < y.distance; });
        std::vector<bool> last_used(last_particles.size(), false);
        for (const Candidate& candidate : candidates) {
            if (current[candidate.now].instance != 0 || last_used[candidate.last]) {
                continue;
            }
            current[candidate.now].instance = last_particles[candidate.last].instance;
            last_used[candidate.last] = true;
        }
        for (size_t a = 0; a < current.size(); a++) {
            if (current[a].instance == 0) {
                current[a].instance = next_instance++;
            }
            particle_id[current_command[a]] = make_id(0x504152, current[a].instance, camera_generation);
        }
        static const bool log_particles = std::getenv("TOOIE_TAG_LOG") != nullptr;
        if (log_particles && !current.empty()) {
            std::printf("[particles] %zu, %zu paired with last frame's\n", current.size(), (size_t)std::count(last_used.begin(), last_used.end(), true));
        }
        last_particles = std::move(current);
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
    // Their places are drawn at the game's own rate instead, as is everything
    // on the first frame after a camera cut. Their bones (the hand waving)
    // are still blended, see below.
    const bool game_select = !overlay && tooie::debug::current_map(rdram) == game_select_map;
    const bool snap = (cut && !overlay) || game_select || blend_mode == 4;
    // The custom blend mode's baseline (L, 2026-10-15): models snap and the
    // camera blends, as mode 4, except that characters (models with bones,
    // two matrices or more) blend with their vertex positions, and a tag
    // from interp_tags.txt decides for its model.
    const bool snap_rest = snap || custom;

    slot = (slot + 1) % slot_count;
    uint32_t cursor = list_area + slot * slot_size;
    uint32_t limit = cursor + slot_size;

    // Shadows (see ShadowScan): a model matrix multiplied into the projection,
    // then segment 5 and the calls that load the bones from it.
    std::vector<uint32_t> shadow(commands.size(), 0);
    // Game select: the same models are left as the game draws them, place
    // (and shake) in the projection, and only their bones get an id, set
    // with segment 5.
    std::vector<uint32_t> bones_group(commands.size(), 0);
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
            if (!game_select) {
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
            }

            // Which copy this is: the nearest of last frame's copies of the
            // same model, as in pass 2, so one appearing or vanishing does
            // not shift the others' ids (the pause menu's panels).
            uint32_t key = make_id(first_list, local[2], 0x534844);
            auto& last = last_copies[key];
            auto& used = used_copies[key];
            used.resize(last.size(), false);
            int best = -1;
            float best_distance = teleport_distance * teleport_distance;
            for (size_t n = 0; n < last.size() && !(game_select ? cut : snap); n++) {
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
            if (game_select) {
                bones_group[segment_command] = make_id(key, copy.instance, camera_generation);
            }
            else {
                shadow[i] = make_id(key, copy.instance, camera_generation);
            }
        }
        last_copies = std::move(now_copies);
    }

    // A list drawn more than once in a model (both hands, the links of a
    // chain, the segments of a long body) gets one id per drawing. Counting
    // them in draw order went wrong when the game left one out for a frame
    // (out of view, or a part that comes and goes): the ids after it moved
    // one drawing along, and RT64 blended each part towards its neighbour's
    // place, so the mesh stretched across the gap for the in-between frames.
    // Each drawing keeps the number of last frame's nearest one instead.
    std::vector<uint32_t> repeat_slot(commands.size(), 0);
    if (!overlay) {
        struct Drawing {
            float pos[3];
            uint32_t slot;
        };
        static std::unordered_map<uint32_t, std::vector<Drawing>> last_drawings;
        std::unordered_map<uint32_t, std::vector<std::pair<size_t, Drawing>>> now;
        for (size_t index = 0; index < commands.size(); index++) {
            const Command& c = commands[index];
            int b = c.block;
            if ((c.w0 >> 24) != op_mtx || b < 0 || blocks[b].model == 0 ||
                (((c.w0 & 0xFF) ^ 1) & mtx_projection) != 0 || shadow[index] != 0 || bones_group[index] != 0) {
                continue;
            }
            uint32_t key = make_id(blocks[b].model, blocks[b].instance, bone_id[index]);
            Drawing d{};
            read_translation(rdram, c.w1 & 0x1FFFFFFF, d.pos);
            now[key].push_back({index, d});
        }
        std::unordered_map<uint32_t, std::vector<Drawing>> drawings;
        for (auto& [key, list] : now) {
            auto found = last_drawings.find(key);
            std::vector<Drawing> empty;
            const std::vector<Drawing>& last = found != last_drawings.end() ? found->second : empty;
            std::vector<bool> slot_used;
            auto use = [&](uint32_t slot) {
                if (slot >= slot_used.size()) {
                    slot_used.resize(slot + 1, false);
                }
                slot_used[slot] = true;
            };
            std::vector<bool> done(list.size(), false);
            if (list.size() == 1 && last.size() == 1) {
                list[0].second.slot = last[0].slot;
                use(last[0].slot);
                done[0] = true;
            }
            else if (list.size() * last.size() > repeat_pairs_max) {
                // Too many to compare each with each every frame: draw order.
                for (size_t i = 0; i < list.size(); i++) {
                    list[i].second.slot = (uint32_t)i;
                    use((uint32_t)i);
                    done[i] = true;
                }
            }
            else {
                std::vector<int> match = pair_nearest<std::pair<size_t, Drawing>, Drawing>(list, last,
                    [](const std::pair<size_t, Drawing>& d) -> const float* { return d.second.pos; },
                    [](const Drawing& d) -> const float* { return d.pos; },
                    repeat_distance, repeat_close);
                for (size_t i = 0; i < list.size(); i++) {
                    if (match[i] >= 0) {
                        list[i].second.slot = last[match[i]].slot;
                        use(list[i].second.slot);
                        done[i] = true;
                    }
                }
            }
            // New drawings take numbers no drawing had last frame either, so
            // RT64 finds nothing to blend them from.
            for (const Drawing& d : last) {
                use(d.slot);
            }
            uint32_t next = 0;
            for (size_t i = 0; i < list.size(); i++) {
                if (!done[i]) {
                    while (next < slot_used.size() && slot_used[next]) {
                        next++;
                    }
                    list[i].second.slot = next;
                    use(next);
                }
                repeat_slot[list[i].first] = list[i].second.slot;
                drawings[key].push_back(list[i].second);
            }
        }
        last_drawings = std::move(drawings);
    }

    // A bone is named by the list it draws next, but some bones swap their
    // list from frame to frame (Banjo's face: eyes open, half shut, shut).
    // Such a bone's name changes, so RT64 found nothing to blend it with and
    // it popped. Each copy's new names are paired with its names that are
    // gone since last frame, by where the bones are, and keep that bone's id.
    struct Named {
        uint32_t id;
        float pos[3];
    };
    static std::unordered_map<uint64_t, std::unordered_map<uint32_t, Named>> last_named;
    std::unordered_map<uint64_t, std::unordered_map<uint32_t, Named>> named;
    std::unordered_map<size_t, uint32_t> carried_id;
    if (cut && !overlay) {
        last_named.clear();
    }
    auto bone_name = [&](size_t index) {
        int b = commands[index].block;
        return make_id(make_id(blocks[b].model, blocks[b].instance, bone_id[index]), repeat_slot[index], 0);
    };
    auto copy_key = [&](int b) {
        return ((uint64_t)blocks[b].model << 32) | blocks[b].instance;
    };
    if (!overlay) {
        struct Fresh {
            size_t index;
            float pos[3];
        };
        std::unordered_map<uint64_t, std::vector<Fresh>> fresh;
        std::unordered_map<uint64_t, std::unordered_map<uint32_t, bool>> names_now;
        for (size_t index = 0; index < commands.size(); index++) {
            const Command& c = commands[index];
            int b = c.block;
            if ((c.w0 >> 24) != op_mtx || b < 0 || blocks[b].model == 0 || (((c.w0 & 0xFF) ^ 1) & mtx_projection) != 0) {
                continue;
            }
            uint64_t copy = copy_key(b);
            uint32_t name = bone_name(index);
            names_now[copy][name] = true;
            auto last = last_named.find(copy);
            if (last == last_named.end()) {
                continue;
            }
            auto at = last->second.find(name);
            if (at != last->second.end()) {
                carried_id[index] = at->second.id;
            }
            else {
                Fresh f{index, {}};
                read_translation(rdram, c.w1 & 0x1FFFFFFF, f.pos);
                fresh[copy].push_back(f);
            }
        }
        for (auto& [copy, list] : fresh) {
            std::vector<Named> gone;
            for (const auto& [name, n] : last_named[copy]) {
                if (names_now[copy].count(name) == 0) {
                    gone.push_back(n);
                }
            }
            std::vector<int> match = pair_nearest<Fresh, Named>(list, gone,
                [](const Fresh& f) -> const float* { return f.pos; },
                [](const Named& n) -> const float* { return n.pos; },
                swap_distance, swap_distance);
            for (size_t i = 0; i < list.size(); i++) {
                if (match[i] >= 0) {
                    carried_id[list[i].index] = gone[match[i]].id;
                }
            }
        }
    }

    // Pass 3: wrap the matrix loads.
    uint32_t bones_tagged = 0;
    uint32_t shadows_tagged = 0;
    bool enabled = false;
    bool tagged = false;
    bool camera_tagged = false;
    // Headless aid: TOOIE_TAG_LOG=1 logs how many of each big model's ids
    // carry over from the last frame.
    std::unordered_map<uint32_t, std::vector<uint32_t>> ids_now;
    uint32_t p = start;
    for (size_t index = 0; index < commands.size(); index++, p += 8) {
        const Command& c = commands[index];
        if (bones_group[index] != 0) {
            // Game select: one id for the bones the model's lists load from
            // segment 5, matched in load order, set with the segment.
            if (cursor + 40 > limit) {
                break;
            }
            uint32_t list = cursor;
            if (!enabled) {
                put(rdram, cursor, rt64_hook_word0, (rt64_hook_op_enable << 28) | rt64_extended_opcode);
                cursor += 8;
                enabled = true;
            }
            uint32_t components = cut ? component_skip : component_interpolate;
            put(rdram, cursor, group_word0(), unique_id(bones_group[index]));
            put(rdram, cursor + 8, group_params(interpolate_decompose, components, order_linear), 0);
            put(rdram, cursor + 16, c.w0, c.w1);
            put(rdram, cursor + 24, op_enddl << 24, 0);
            cursor += 32;
            put(rdram, p, op_dl << 24, list);
            tagged = true;
            bones_tagged++;
            continue;
        }
        if ((c.w0 >> 24) != op_mtx) {
            continue;
        }
        int b = c.block;
        uint32_t params = (c.w0 & 0xFF) ^ 1;
        bool projection = (params & mtx_projection) != 0;
        // A model tagged "untagged" is left to RT64's own matching.
        bool model = b >= 0 && blocks[b].model != 0 && !projection && blocks[b].tag_mode != tooie::interp_tags::mode_untagged;
        bool particle = particle_id[index] != 0 && !(b >= 0 && blocks[b].tag_mode == tooie::interp_tags::mode_untagged);
        bool tag = model || particle || (snap_rest && !projection && !overlay);
        // The perspective camera gets an id that changes at each cut, so RT64
        // does not blend the camera across it.
        bool tag_camera = projection && (params & mtx_load) != 0 && !camera_tagged && have_camera && blend_mode != 3;
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
            put(rdram, cursor, group_word0(), unique_id(shadow[index]));
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
            shadows_tagged++;
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
            put(rdram, cursor, group_word0(), unique_id(make_id(0x43414D, camera_generation, 0)));
            put(rdram, cursor + 8, group_params(interpolate_simple, component_interpolate, order_auto) | group_projection, 0);
            cursor += 16;
            camera_tagged = true;
        }
        if (tag) {
            uint32_t id;
            if (model) {
                uint32_t bone = bone_id[index];
                uint32_t key = make_id(blocks[b].model, blocks[b].instance, bone);
                // A list drawn twice in a model (both hands, say) gets a second id
                // (see repeat_slot).
                id = make_id(key, repeat_slot[index], camera_generation);
                auto carried = carried_id.find(index);
                if (carried != carried_id.end()) {
                    id = carried->second;
                }
                id = unique_id(id);
                if (!overlay) {
                    Named& n = named[copy_key(b)][bone_name(index)];
                    n.id = id;
                    read_translation(rdram, c.w1 & 0x1FFFFFFF, n.pos);
                }
                if (log_ids) {
                    ids_now[blocks[b].model].push_back(id);
                }
                bones_tagged++;
                blocks[b].ids.push_back(id);
                if (mouse) {
                    mouse_id_models[id] = blocks[b].print;
                }
            }
            else if (particle) {
                id = unique_id(particle_id[index]);
            }
            else {
                id = unique_id(make_id(0, camera_generation, (uint32_t)index));
            }
            // The model's manual tag (interp_tags.txt): snap draws it at the
            // game's rate, vertex blends its vertex positions too.
            int tag_mode = (model || particle) && b >= 0 ? blocks[b].tag_mode : tooie::interp_tags::mode_default;
            if (custom && tag_mode == tooie::interp_tags::mode_default) {
                // The custom rule: characters blend with vertices, the rest
                // (props, particles) snaps; a tag overrides it.
                tag_mode = model && blocks[b].matrices >= 2 ? tooie::interp_tags::mode_vertex : tooie::interp_tags::mode_snap;
            }
            const bool model_snap = snap || tag_mode == tooie::interp_tags::mode_snap || (!model && !particle && snap_rest);
            uint32_t components = model_snap ? component_skip : component_interpolate;
            put(rdram, cursor, group_word0(), id);
            // A particle's quad is rebuilt each frame; only its place blends.
            // Vertex blending is off: RT64 blends vertex positions by index
            // when a bone loads the same number of vertices as last frame,
            // and models whose vertex set changes with the view (the sky
            // dome's parts) then tear for a game frame (L, 2026-10-14, F8
            // bisect). Blend mode 2 turns it back on for comparison.
            // Snout jiggle rewrites Banjo's muzzle and jaw vertices each game frame: blend them too.
            const bool jiggle = model && b >= 0 && tooie::snout_jiggle::blend_vertices(blocks[b].first_phys);
            uint32_t vertices = model_snap || (blend_mode != 2 && tag_mode != tooie::interp_tags::mode_vertex && !jiggle) ?
                component_skip : component_interpolate;
            // A shadow's bones are flat, so they cannot be split into turn and
            // scale (that put spikes in the shadow between frames): blended
            // element by element, as the game's own shadows are.
            uint32_t mode = model && blocks[b].shadow ? interpolate_simple : interpolate_decompose;
            put(rdram, cursor + 8, group_params(mode, components, order_linear, vertices), 0);
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

    // How many bytes of segment 1 a model's vertex loads reach (its lists
    // walked as the top-level list calls them).
    auto vertex_extent = [](uint8_t* rdram, const std::vector<Command>& list, std::array<uint32_t, 16> segments, size_t model) {
        uint32_t extent = 0;
        int budget = 20000;
        std::function<void(uint32_t, int)> walk = [&](uint32_t phys, int depth) {
            for (; budget > 0; budget--, phys += 8) {
                uint32_t w0 = word(rdram, phys);
                uint32_t w1 = word(rdram, phys + 4);
                uint32_t op = w0 >> 24;
                if (op == op_vtx && (w1 >> 24) == 1) {
                    extent = std::max(extent, (w1 & 0xFFFFFF) + ((w0 >> 12) & 0xFF) * 16);
                }
                else if (op == op_moveword && ((w0 >> 16) & 0xFF) == moveword_segment) {
                    segments[((w0 & 0xFFFF) / 4) & 0xF] = w1 & 0x1FFFFFFF;
                }
                else if (op == op_dl) {
                    uint32_t target = (w1 & 0x80000000) != 0 ? (w1 & 0x1FFFFFFF) :
                        ((segments[(w1 >> 24) & 0xF] + (w1 & 0xFFFFFF)) & 0x1FFFFFFF);
                    if (target != 0 && depth < 8) {
                        walk(target, depth + 1);
                    }
                    if (((w0 >> 16) & 0xFF) != 0) {
                        return;
                    }
                }
                else if (op == op_enddl) {
                    return;
                }
            }
        };
        for (const Command& c : list) {
            if (c.block != (int)model) {
                continue;
            }
            uint32_t op = c.w0 >> 24;
            if (op == op_moveword && ((c.w0 >> 16) & 0xFF) == moveword_segment) {
                segments[((c.w0 & 0xFFFF) / 4) & 0xF] = c.w1 & 0x1FFFFFFF;
            }
            else if (op == op_dl && budget > 0) {
                uint32_t target = (c.w1 & 0x80000000) != 0 ? (c.w1 & 0x1FFFFFFF) :
                    ((segments[(c.w1 >> 24) & 0xF] + (c.w1 & 0xFFFFFF)) & 0x1FFFFFFF);
                // Lists in the small-list area are this file's own.
                if (target != 0 && (target < list_area || target >= list_area + slot_size * slot_count)) {
                    walk(target, 0);
                }
            }
        }
        return extent;
    };

    const uint32_t picked_print = overlay ? 0 : tooie::interp_tags::picked();
    if (!overlay && (tooie::interp_check::enabled() || picked_print != 0)) {
        // Flag the copies whose blend will look wrong: a sudden jump (smeared
        // over the in-between frames), or bones RT64 cannot pair with last
        // frame's (drawn at the game's rate). Flagged copies are tinted red
        // for a moment and logged. The picked model (manual tags) is drawn
        // green the same way, its textures kept.
        const bool checking = tooie::interp_check::enabled();
        if (checking) {
            check_frame++;
        }
        // The segments as the top-level list leaves them at each model.
        std::vector<std::array<uint32_t, 16>> block_segments(blocks.size());
        {
            std::array<uint32_t, 16> segments{};
            for (const Command& c : commands) {
                if ((c.w0 >> 24) == op_moveword && ((c.w0 >> 16) & 0xFF) == moveword_segment) {
                    segments[((c.w0 & 0xFFFF) / 4) & 0xF] = c.w1 & 0x1FFFFFFF;
                }
                if (c.block >= 0) {
                    block_segments[c.block] = segments;
                }
            }
        }
        for (auto& [key, track] : tracks) {
            track.seen = false;
        }
        // Draws a model from a copy of its vertices coloured rgb (most
        // characters are coloured by their vertices rather than textures).
        auto recolor = [&](size_t bi, uint32_t rgb) {
            const Block& block = blocks[bi];
            if (block.vertex_command == SIZE_MAX) {
                return;
            }
            uint32_t vertices = commands[block.vertex_command].w1 & 0x1FFFFFFF;
            // The whole of the model's vertices or nothing: a copy cut short
            // leaves vertex loads past it reading the list area (a huge
            // yellow quad on Banjo, L 2026-10-14).
            uint32_t bytes = vertex_extent(rdram, commands, block_segments[bi], bi);
            if (bytes != 0 && cursor + bytes <= limit) {
                for (uint32_t offset = 0; offset < bytes; offset += 16) {
                    for (uint32_t w = 0; w < 12; w += 4) {
                        MEM_W(0, kseg0(cursor + offset + w)) = MEM_W(0, kseg0(vertices + offset + w));
                    }
                    uint32_t color = (uint32_t)MEM_W(0, kseg0(vertices + offset + 12));
                    MEM_W(0, kseg0(cursor + offset + 12)) = (int32_t)(rgb | (color & 0xFF));
                }
                put(rdram, start + (uint32_t)block.vertex_command * 8, commands[block.vertex_command].w0, cursor);
                cursor += bytes;
            }
        };
        for (size_t bi = 0; bi < blocks.size(); bi++) {
            Block& block = blocks[bi];
            if (block.matrices == 0) {
                continue;
            }
            if (picked_print != 0 && block.print == picked_print && !block.shadow) {
                recolor(bi, 0x00FF0000);
            }
            if (!checking || block.model == 0) {
                continue;
            }
            uint64_t key = ((uint64_t)block.model << 32) | block.instance;
            auto found = tracks.find(key);
            bool fresh = found == tracks.end();
            Track& track = tracks[key];
            float step = 0.0f;
            if (!fresh) {
                for (int k = 0; k < 3; k++) {
                    float d = block.pos[k] - track.pos[k];
                    step += d * d;
                }
                step = std::sqrt(step);
                // A copy's first move is not compared: something that appears and
                // then falls or flies off has no move the frame before.
                bool jump = !cut && !snap && track.step_known && step > std::max(jump_distance, 3.0f * track.step + 20.0f);
                size_t lost = 0;
                if (!cut && !snap && block.ids.size() == track.ids.size()) {
                    for (uint32_t id : block.ids) {
                        lost += std::find(track.ids.begin(), track.ids.end(), id) == track.ids.end() ? 1 : 0;
                    }
                }
                if (jump || lost != 0) {
                    track.tint_frames = tint_length;
                    std::printf("[interp-check] frame %llu map %X model %08X (list %08X textures %08X) copy %u at %.0f,%.0f,%.0f: %s",
                        (unsigned long long)check_frame, tooie::debug::current_map(rdram), block.model, block.first_list, block.textures, block.instance,
                        block.pos[0], block.pos[1], block.pos[2], jump ? "jumped" : "");
                    if (jump) {
                        std::printf(" %.0f units (moved %.0f the frame before)", step, track.step);
                    }
                    if (lost != 0) {
                        std::printf("%s%zu of %zu bones not blended", jump ? ", " : "", lost, block.ids.size());
                    }
                    std::printf("\n");
                }
            }
            for (int k = 0; k < 3; k++) {
                track.pos[k] = block.pos[k];
            }
            track.step = step;
            track.ids = std::move(block.ids);
            track.step_known = !fresh;
            track.seen = true;
            if (track.tint_frames > 0) {
                track.tint_frames--;
                if (block.texture_command != SIZE_MAX) {
                    put(rdram, start + (uint32_t)block.texture_command * 8, commands[block.texture_command].w0, tint_texture);
                }
                recolor(bi, 0xFF000000);
            }
        }
        if (checking) {
            for (auto it = tracks.begin(); it != tracks.end();) {
                it = it->second.seen ? std::next(it) : tracks.erase(it);
            }
        }
    }

    if (!overlay) {
        last_named = std::move(named);
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
        if (stat_id_repeats != 0) {
            std::fprintf(stderr, "[ids] %u ids given out twice this frame, renamed\n", stat_id_repeats);
            stat_id_repeats = 0;
        }
    }
    if (!overlay) {
        uint32_t models = 0;
        for (const auto& [model, copies] : previous) {
            models += (uint32_t)copies.size();
        }
        // HD Shadows' flattened models count as shadows, not models.
        uint32_t model_shadows = 0;
        for (const Block& block : blocks) {
            if (block.model != 0 && block.shadow && block.matrices != 0) {
                model_shadows++;
            }
        }
        stat_models = models - std::min(models, model_shadows);
        stat_bones = bones_tagged;
        stat_shadows = shadows_tagged + model_shadows;
    }

    if (!overlay) {
        mark_no_effects(cursor, limit);
        mark_fur(cursor, limit);
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
    stat_scenes.fetch_add(1, std::memory_order_relaxed);
    tooie::frame_overlay::note_scene_done();
    tooie::interp_check::start();
    tooie::interp_tags::start();
    tooie::parallax_pick::start();
    if (tooie::interp_check::enabled()) {
        static bool filled = false;
        if (!filled) {
            for (uint32_t offset = 0; offset < tint_size; offset += 4) {
                MEM_W(0, kseg0(tint_texture + offset)) = (int32_t)0xF801F801;
            }
            filled = true;
        }
    }
    return tag(rdram, start, end, false);
}

uint32_t tooie::model_tagging::tag_2d(uint8_t* rdram, uint32_t start, uint32_t end) {
    return tag(rdram, start, end, true);
}

tooie::model_tagging::Stats tooie::model_tagging::last_stats() {
    Stats stats;
    stats.interpolating = interpolation_on();
    stats.models = stat_models;
    stats.bones = stat_bones;
    stats.shadows = stat_shadows;
    stats.camera_cuts = stat_cuts;
    stats.scenes = stat_scenes.load(std::memory_order_relaxed);
    return stats;
}
