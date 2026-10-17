// Cheats > Size (L, 2026-10-17): Big head, Small head, Big body and Tiny body for Banjo and Kazooie.
//
// Drawn only: collision, the camera, the blob shadow and the points things are held or fired from keep
// their normal size. Called from the two hooks Snout jiggle already has (src/gameplay/snout_jiggle.cpp):
// func_800DE498 once it knows the model it draws, and func_800DCF48 (one bone node) after func_800ADE2C
// returned the bone's matrix in $v0, before it is pushed. Each bone's matrix there is a row-vector 4x4
// taking bind-pose points straight to model space, so scaling one bone doesn't carry to its children:
// a head scale is applied to the head bone and every bone under it, about the head's root, and a body
// scale to every bone, about the model's origin (the feet). The scaled copy goes to a slot of our own and
// $v0 points at it.
//
// The player's models (062A, and 0838 with Dragon Kazooie) are found as Snout jiggle finds them: bone 9
// has id 18 and bone 10 id 42 under bone 9 (68 bones on a new file, 60 on a loaded one). Banjo's head is bone 9, Kazooie's bone 21. The other forms and Kazooie alone use other
// models and stay as they are.
//
// Bone table: model + *(model + 0x18): count at +4, then 16-byte entries from +8 (pivot as 3 floats, id at
// +12, parent at +14). The frame's bone matrices: *(0x8012C968) + 0x50 + bone * 64.
//
// Headless: TOOIE_SIZE_HEAD=<f>, TOOIE_SIZE_BODY=<f> force those scales.

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "recomp.h"
#include "tooie_cheats.h"
#include "tooie_size_cheats.h"

namespace {
    constexpr float big_head = 2.5f, small_head = 0.5f, big_body = 1.6f, tiny_body = 0.5f;
    constexpr int banjo_head = 9, kazooie_head = 21;
    constexpr int max_bones = 128;
    constexpr uint32_t slots = 0x80EF9000;          // 64 bytes per bone, after Snout jiggle's copies
    constexpr uint32_t matrix_list_ptr = 0x8012C968;

    struct Vec { float x, y, z; };

    uint32_t read_word(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<uint32_t*>(rdram + (addr - 0x80000000u));
    }
    int16_t read_half(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<int16_t*>(rdram + ((addr ^ 2) - 0x80000000u));
    }
    float read_float(uint8_t* rdram, uint32_t addr) {
        uint32_t bits = read_word(rdram, addr);
        float value;
        std::memcpy(&value, &bits, sizeof(value));
        return value;
    }
    void write_float(uint8_t* rdram, uint32_t addr, float value) {
        uint32_t bits;
        std::memcpy(&bits, &value, sizeof(bits));
        *reinterpret_cast<uint32_t*>(rdram + (addr - 0x80000000u)) = bits;
    }
    bool valid_ptr(uint32_t p) {
        return p >= 0x80000000u && p < 0x81000000u;
    }
    Vec transform(const float m[16], Vec p) {
        return { p.x * m[0] + p.y * m[4] + p.z * m[8] + m[12],
                 p.x * m[1] + p.y * m[5] + p.z * m[9] + m[13],
                 p.x * m[2] + p.y * m[6] + p.z * m[10] + m[14] };
    }

    struct State {
        bool active = false;
        int count = 0;
        int parent[max_bones]{};
        Vec pivot[max_bones]{};
        float head = 1.0f, body = 1.0f;
    } st;

    float env_float(const char* name) {
        const char* v = std::getenv(name);
        return v != nullptr ? (float)std::atof(v) : 0.0f;
    }

    bool under(int b, int root) {
        for (int guard = 0; b >= 0 && b < st.count && guard < max_bones; guard++) {
            if (b == root) {
                return true;
            }
            b = st.parent[b];
        }
        return false;
    }
}

void tooie::size_cheats::model(uint8_t* rdram, uint32_t model) {
    st.active = false;
    static const float env_head = env_float("TOOIE_SIZE_HEAD");
    static const float env_body = env_float("TOOIE_SIZE_BODY");
    float head = env_head > 0.0f ? env_head
        : tooie::cheats::is_on("cheat_big_head") ? big_head
        : tooie::cheats::is_on("cheat_small_head") ? small_head : 1.0f;
    float body = env_body > 0.0f ? env_body
        : tooie::cheats::is_on("cheat_big_body") ? big_body
        : tooie::cheats::is_on("cheat_tiny_body") ? tiny_body : 1.0f;
    if ((head == 1.0f && body == 1.0f) || !valid_ptr(model)) {
        return;
    }
    const uint32_t bones_off = read_word(rdram, model + 0x18);
    if (bones_off == 0 || bones_off >= 0x200000) {
        return;
    }
    const uint32_t bones = model + bones_off;
    const int count = (uint16_t)read_half(rdram, bones + 4);
    auto entry = [&](int i) { return bones + 8 + 16 * i; };
    static const bool log = std::getenv("TOOIE_SIZE_LOG") != nullptr;
    static uint32_t logged = 0;
    if (log && logged != model && count > 10) {
        logged = model;
        std::fprintf(stderr, "[size] model %08X bones %d ids %d %d parent %d\n", model, count,
            read_half(rdram, entry(9) + 12), read_half(rdram, entry(10) + 12), read_half(rdram, entry(10) + 14));
    }
    if (count <= 10 || count > max_bones || read_half(rdram, entry(9) + 12) != 18 ||
        read_half(rdram, entry(10) + 12) != 42 || read_half(rdram, entry(10) + 14) != 9) {
        return;
    }
    st.count = count;
    for (int i = 0; i < count; i++) {
        st.pivot[i] = { read_float(rdram, entry(i)), read_float(rdram, entry(i) + 4), read_float(rdram, entry(i) + 8) };
        st.parent[i] = read_half(rdram, entry(i) + 14);
    }
    st.head = head;
    st.body = body;
    st.active = true;
}

void tooie::size_cheats::bone(uint8_t* rdram, recomp_context* ctx, int bone) {
    if (!st.active || bone < 0 || bone >= st.count) {
        return;
    }
    const uint32_t src = (uint32_t)ctx->r2;
    const uint32_t list = read_word(rdram, matrix_list_ptr);
    if (!valid_ptr(src) || !valid_ptr(list)) {
        return;
    }
    float m[16];
    for (int i = 0; i < 16; i++) {
        m[i] = read_float(rdram, src + 4 * i);
    }
    // p' = c + (p - c) * s: the 3x3 rows scale and the translation moves about c.
    auto scale_about = [&](Vec c, float s) {
        for (int i = 0; i < 12; i++) {
            if ((i & 3) != 3) {
                m[i] *= s;
            }
        }
        m[12] = c.x + (m[12] - c.x) * s;
        m[13] = c.y + (m[13] - c.y) * s;
        m[14] = c.z + (m[14] - c.z) * s;
    };
    auto root_of = [&](int b) {
        float h[16];
        for (int i = 0; i < 16; i++) {
            h[i] = read_float(rdram, list + 0x50 + 64 * b + 4 * i);
        }
        return transform(h, st.pivot[b]);
    };
    if (st.head != 1.0f) {
        if (under(bone, banjo_head)) {
            scale_about(root_of(banjo_head), st.head);
        } else if (kazooie_head < st.count && under(bone, kazooie_head)) {
            scale_about(root_of(kazooie_head), st.head);
        }
    }
    if (st.body != 1.0f) {
        scale_about(Vec{ 0, 0, 0 }, st.body);
    }
    const uint32_t dst = slots + 64 * bone;
    for (int i = 0; i < 16; i++) {
        write_float(rdram, dst + 4 * i, m[i]);
    }
    ctx->r2 = (gpr)(int32_t)dst;
}
