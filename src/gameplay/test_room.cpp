// Test room.
//
// Warp > Test > Test room warps to a quiet area and lines up the game's
// characters, enemies and objects in rows in front of Banjo, each one held on
// its spot so the rows stay put. The line-up is in test_room_actors.inc.
//
// Spawning: func_80108474(actor id, f32 pos[3], yaw) is the game's own
// spawn-by-id (used by e.g. the Glowbo for its sparkle). It looks the id up in
// gemarkersDll's table (ids 0xB6 to 0x545), loads the actor's overlay and
// returns the new object. The object array can move when objects are added or
// removed, so spawned actors are found again each frame by their id struct
// pointer (object +0), never by the object's address.
//
// Headless test aids:
//   TOOIE_TEST_ROOM=1             fill the room as soon as Banjo is in its area
//                                 (warp there with TOOIE_WARP)
//   TOOIE_TEST_ROOM_ONLY=a,b,...  spawn only these actor ids (hex)
//   TOOIE_TEST_ROOM_SKIP=a,b,...  leave these actor ids out (hex)
//   TOOIE_TEST_ROOM_RATE=n        spawn n actors a frame (default 4; 1 pins a crash on the actor just spawned)
//   TOOIE_TEST_ROOM_LOG=1         log each spawn and every 2 s which actors are still there

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "recomp.h"
#include "funcs.h"
#include "tooie_debug.h"
#include "tooie_test_room.h"
#include "tooie_transform_picker.h"
#include "tooie_rdram.h"

namespace {
    struct Entry {
        int row;
        uint16_t id;
        const char* name;
        // Transformations: the model drawn in place of the actor's own, and the form Banjo turns into
        // when he walks up to it.
        uint16_t model = 0;
        uint8_t form = 0;
    };

    constexpr Entry entries[] = {
#include "test_room_actors.inc"
    };
    constexpr size_t entry_count = sizeof(entries) / sizeof(entries[0]);

    constexpr uint32_t player_table = 0x80135490;
    constexpr uint32_t player_pos_ptr = 0xE4;
    constexpr uint32_t player_yaw_ptr = 0xF8;
    constexpr uint32_t object_array_pointer = 0x80136EE0;
    constexpr uint32_t object_first = 0x04;
    constexpr uint32_t object_last = 0x08;
    constexpr uint32_t object_base = 0x10;
    constexpr uint32_t object_size = 0x9C;
    constexpr uint32_t object_pos = 0x04;
    constexpr uint32_t object_yaw = 0x48;
    // The id struct an object's +0 points at holds the model id here.
    constexpr uint32_t marker_model = 0x14;
    constexpr int max_objects = 2048;
    constexpr gpr game_state_addr = (int32_t)0x80127630;

    // Layout: rows across Banjo's view, the first row this far ahead, each row further back.
    constexpr float first_row = 300.0f;
    constexpr float row_gap = 260.0f;
    constexpr float column_gap = 170.0f;
    constexpr int per_line = 14;
    // Frames to wait after the area has loaded before spawning, and how many to spawn each frame.
    constexpr int settle_frames = 45;
    constexpr int spawns_per_frame = 4;
    // How close Banjo has to come to a transformation to turn into it.
    constexpr float touch_radius = 60.0f;

    struct Slot {
        size_t entry;
        float pos[3];
        float yaw;
        uint32_t marker = 0;
        bool gone = false;
    };

    std::atomic<bool> requested{false};
    // Set when a transformation reloads the room, so it fills again after the reload.
    bool refill = false;
    bool filling = false;
    std::vector<Slot> slots;
    size_t next_spawn = 0;
    int frames_in_map = 0;
    uint16_t last_map = 0;
    std::set<uint16_t> only;
    std::set<uint16_t> skip;
    bool log_on = false;
    int spawn_rate = spawns_per_frame;
    bool heap_check_on = false;
    std::chrono::steady_clock::time_point last_log;

    using tooie::rdram::read_float;
    using tooie::rdram::read_word;
    using tooie::rdram::valid_ptr;
    using tooie::rdram::write_float;

    void write_half(uint8_t* rdram, uint32_t addr, uint16_t value) {
        *reinterpret_cast<uint16_t*>(rdram + ((addr ^ 2) - 0x80000000u)) = value;
    }

    void read_env() {
        static bool read = false;
        if (read) {
            return;
        }
        read = true;
        if (const char* v = std::getenv("TOOIE_TEST_ROOM"); v != nullptr && *v != '\0' && *v != '0') {
            requested = true;
        }
        auto read_ids = [](const char* name, std::set<uint16_t>& ids) {
            if (const char* v = std::getenv(name)) {
                std::stringstream list(v);
                std::string item;
                while (std::getline(list, item, ',')) {
                    ids.insert((uint16_t)std::strtoul(item.c_str(), nullptr, 16));
                }
            }
        };
        read_ids("TOOIE_TEST_ROOM_ONLY", only);
        read_ids("TOOIE_TEST_ROOM_SKIP", skip);
        log_on = std::getenv("TOOIE_TEST_ROOM_LOG") != nullptr;
        heap_check_on = std::getenv("TOOIE_TEST_ROOM_HEAPCHECK") != nullptr;
        if (const char* v = std::getenv("TOOIE_TEST_ROOM_RATE")) {
            spawn_rate = std::max(1, std::atoi(v));
        }
    }

    // Lays the slots out in rows facing Banjo, from his position and facing.
    bool plan(uint8_t* rdram) {
        const uint32_t player = read_word(rdram, player_table);
        if (!valid_ptr(player)) {
            return false;
        }
        const uint32_t pos_ptr = read_word(rdram, player + player_pos_ptr);
        const uint32_t yaw_ptr = read_word(rdram, player + player_yaw_ptr);
        if (!valid_ptr(pos_ptr) || !valid_ptr(yaw_ptr)) {
            return false;
        }
        const float px = read_float(rdram, pos_ptr), py = read_float(rdram, pos_ptr + 4), pz = read_float(rdram, pos_ptr + 8);
        const float yaw = read_float(rdram, yaw_ptr);
        const float rad = yaw * 3.14159265f / 180.0f;
        // Forward along the facing angle, and across it.
        const float fx = std::sin(rad), fz = std::cos(rad);
        const float rx = fz, rz = -fx;

        slots.clear();
        float depth = first_row;
        int last_row = -1;
        int column = 0;
        size_t row_start = 0;
        auto centre_line = [&](size_t from, size_t to) {
            // Centres the slots [from, to) on Banjo's line of sight.
            const float shift = (float)(to - from - 1) * column_gap * 0.5f;
            for (size_t i = from; i < to; i++) {
                slots[i].pos[0] -= rx * shift;
                slots[i].pos[2] -= rz * shift;
            }
        };
        for (size_t i = 0; i < entry_count; i++) {
            if ((!only.empty() && only.count(entries[i].id) == 0) || skip.count(entries[i].id) != 0) {
                continue;
            }
            if (last_row != -1 && (entries[i].row != last_row || column == per_line)) {
                centre_line(row_start, slots.size());
                row_start = slots.size();
                depth += row_gap;
                column = 0;
            }
            last_row = entries[i].row;
            Slot slot;
            slot.entry = i;
            slot.pos[0] = px + fx * depth + rx * column * column_gap;
            slot.pos[1] = py;
            slot.pos[2] = pz + fz * depth + rz * column * column_gap;
            // Facing back at Banjo.
            slot.yaw = std::fmod(yaw + 180.0f, 360.0f);
            slots.push_back(slot);
            column++;
        }
        centre_line(row_start, slots.size());
        printf("[test-room] %zu actors planned from %.0f %.0f %.0f facing %.0f\n", slots.size(), px, py, pz, yaw);
        fflush(stdout);
        return true;
    }

    // Spawns one actor through the game's spawner with a copy of the hook's context, so the caller's
    // registers stay untouched. The position goes in a scratch area below the stack.
    uint32_t spawn(uint8_t* rdram, recomp_context* ctx, uint16_t id, const float pos[3], float yaw) {
        recomp_context saved = *ctx;
        const uint32_t sp = (uint32_t)ctx->r29;
        const uint32_t vec = (sp - 0x100) & ~0xFu;
        write_float(rdram, vec + 0, pos[0]);
        write_float(rdram, vec + 4, pos[1]);
        write_float(rdram, vec + 8, pos[2]);
        ctx->r29 = (int32_t)(vec - 0x40);
        ctx->r4 = id;
        ctx->r5 = (int32_t)vec;
        ctx->r6 = (int32_t)yaw;
        func_80108474(rdram, ctx);
        const uint32_t object = (uint32_t)ctx->r2;
        *ctx = saved;
        return object;
    }

    // Calls fn(object) for every live object.
    template <typename F>
    void for_each_object(uint8_t* rdram, F fn) {
        const uint32_t array = read_word(rdram, object_array_pointer);
        if (!valid_ptr(array)) {
            return;
        }
        const uint32_t first = read_word(rdram, array + object_first);
        const uint32_t last = read_word(rdram, array + object_last);
        if (!valid_ptr(first) || !valid_ptr(last) || last < first) {
            return;
        }
        const int count = (int)((last - first) / object_size) + 1;
        if (count > max_objects) {
            return;
        }
        for (int i = 0; i < count; i++) {
            fn(array + object_base + (uint32_t)i * object_size);
        }
    }

    // Debug aid (TOOIE_TEST_ROOM_HEAPCHECK=1): walks the game's heap block list (decomp include/memory.h:
    // the heap pointer at 0x8007E990, its size at 0x8007BF00, each block header { prev, next, ... }) and
    // returns the address of the first broken link, or 0 if the list is whole.
    uint32_t heap_check(uint8_t* rdram) {
        const uint32_t start = read_word(rdram, 0x8007E990);
        const uint32_t end = start + read_word(rdram, 0x8007BF00);
        uint32_t cur = start;
        for (int n = 0; n < 200000; n++) {
            const uint32_t next = read_word(rdram, cur + 4);
            if (next == end) {
                // The free list: each empty block's prev_free (+0x10) must point back.
                uint32_t f = read_word(rdram, start + 0x14), prev = start;
                const uint32_t last = end - 0x20;
                for (int m = 0; m < 200000 && f != last; m++) {
                    if (f < start || f >= end || read_word(rdram, f + 0x10) != prev ||
                        ((read_word(rdram, f + 0xC) >> 6) & 3) != 0 || read_word(rdram, read_word(rdram, f) + 4) != f) {
                        return 0x1 | f;
                    }
                    prev = f;
                    f = read_word(rdram, f + 0x14);
                }
                return 0;
            }
            if (next <= cur || next > end || read_word(rdram, next) != cur) {
                return cur;
            }
            // An empty block (state 0, bits 6-7 of the word at +0xC) must be on the free list.
            if (cur != start && ((read_word(rdram, cur + 0xC) >> 6) & 3) == 0) {
                const uint32_t nf = read_word(rdram, cur + 0x14), pf = read_word(rdram, cur + 0x10);
                if (nf < start || nf >= end || pf < start || pf >= end || read_word(rdram, pf + 0x14) != cur) {
                    return 0x2 | cur;
                }
            }
            cur = next;
        }
        return cur;
    }

    // Debug aid: prints the broken block's header and the block before it.
    void heap_dump(uint8_t* rdram, uint32_t bad) {
        const uint32_t b = bad & ~3u;
        const uint32_t prev = read_word(rdram, b);
        for (uint32_t x : { prev, b }) {
            if (!valid_ptr(x)) {
                continue;
            }
            printf("[test-room]   block %08X: %08X %08X %08X %08X  %08X %08X\n", x, read_word(rdram, x), read_word(rdram, x + 4),
                read_word(rdram, x + 8), read_word(rdram, x + 12), read_word(rdram, x + 16), read_word(rdram, x + 20));
        }
        fflush(stdout);
    }

    // The largest free block, from the heap's free list (FIRST_BLOCK()->next_free, each empty block's
    // next_free at +0x14, until LAST_BLOCK() at the heap's end - 0x20), as heap_largest_free counts it.
    uint32_t largest_free(uint8_t* rdram) {
        const uint32_t start = read_word(rdram, 0x8007E990);
        const uint32_t last = start + read_word(rdram, 0x8007BF00) - 0x20;
        uint32_t largest = 0;
        uint32_t cur = read_word(rdram, start + 0x14);
        for (int n = 0; n < 200000 && cur != last && valid_ptr(cur); n++) {
            largest = std::max(largest, read_word(rdram, cur + 4) - cur);
            cur = read_word(rdram, cur + 0x14);
        }
        return largest;
    }

    // Banjo's position, if there is a player.
    bool player_position(uint8_t* rdram, float out[3]) {
        const uint32_t player = read_word(rdram, player_table);
        const uint32_t pos_ptr = valid_ptr(player) ? read_word(rdram, player + player_pos_ptr) : 0;
        if (!valid_ptr(pos_ptr)) {
            return false;
        }
        for (int k = 0; k < 3; k++) {
            out[k] = read_float(rdram, pos_ptr + 4 * k);
        }
        return true;
    }

    // Walking up to a transformation turns Banjo into it (the area reloads, and the room fills again).
    void touch_forms(uint8_t* rdram) {
        float p[3];
        if (!player_position(rdram, p)) {
            return;
        }
        for (const Slot& slot : slots) {
            const Entry& entry = entries[slot.entry];
            if (entry.form == 0 || slot.gone) {
                continue;
            }
            const float dx = p[0] - slot.pos[0], dz = p[2] - slot.pos[2];
            if (dx * dx + dz * dz < touch_radius * touch_radius && std::fabs(p[1] - slot.pos[1]) < 150.0f) {
                if (tooie::transform_picker::request_form(entry.form)) {
                    printf("[test-room] turning into %s\n", entry.name);
                    fflush(stdout);
                    refill = true;
                }
                return;
            }
        }
    }

    // Holds each spawned actor on its spot, so walkers, chasers and fliers stay in their row.
    void hold(uint8_t* rdram) {
        std::vector<int> seen(slots.size(), 0);
        for_each_object(rdram, [&](uint32_t object) {
            const uint32_t marker = read_word(rdram, object);
            for (size_t i = 0; i < slots.size(); i++) {
                if (slots[i].marker != 0 && slots[i].marker == marker) {
                    seen[i] = 1;
                    for (int k = 0; k < 3; k++) {
                        write_float(rdram, object + object_pos + 4 * k, slots[i].pos[k]);
                    }
                    break;
                }
            }
        });
        for (size_t i = 0; i < slots.size(); i++) {
            if (slots[i].marker != 0 && !seen[i] && !slots[i].gone) {
                slots[i].gone = true;
                if (log_on) {
                    printf("[test-room] 0x%X %s is gone\n", entries[slots[i].entry].id, entries[slots[i].entry].name);
                    fflush(stdout);
                }
            }
        }
    }
}

void tooie::test_room::request() {
    requested = true;
}

void tooie::test_room::tick(uint8_t* rdram, recomp_context* ctx) {
    read_env();
    const uint16_t map_now = tooie::debug::current_map(rdram);
    if (map_now != last_map) {
        last_map = map_now;
        frames_in_map = 0;
        // Leaving the area ends the room; the game removes its actors.
        slots.clear();
        filling = false;
        next_spawn = 0;
    }
    // A map change under way (a transformation reloads the same area): the game removes the actors.
    if (MEM_B(0x12, game_state_addr) != 0) {
        frames_in_map = 0;
        slots.clear();
        filling = false;
        return;
    }
    frames_in_map++;
    if (map_now != map) {
        refill = false;
        return;
    }
    if (refill) {
        refill = false;
        requested = true;
    }

    if (requested && frames_in_map >= settle_frames) {
        requested = false;
        // Already filled: picking the room again while in it changes nothing.
        if (slots.empty() && plan(rdram)) {
            filling = true;
            next_spawn = 0;
        }
    }

    if (filling) {
        for (int n = 0; n < spawn_rate && next_spawn < slots.size(); n++, next_spawn++) {
            Slot& slot = slots[next_spawn];
            const Entry& entry = entries[slot.entry];
            if (log_on) {
                printf("[test-room] spawning 0x%X %s\n", entry.id, entry.name);
                fflush(stdout);
            }
            if (heap_check_on) {
                if (uint32_t bad = heap_check(rdram)) {
                    printf("[test-room] heap broken at 0x%08X before spawning 0x%X %s\n", bad, entry.id, entry.name);
                    heap_dump(rdram, bad);
                    fflush(stdout);
                    heap_check_on = false;
                }
            }
            const uint32_t object = spawn(rdram, ctx, entry.id, slot.pos, slot.yaw);
            if (valid_ptr(object)) {
                slot.marker = read_word(rdram, object);
                write_float(rdram, object + object_yaw, slot.yaw);
                if (entry.model != 0 && valid_ptr(slot.marker)) {
                    write_half(rdram, slot.marker + marker_model, entry.model);
                }
            } else {
                slot.gone = true;
            }
            if (log_on) {
                printf("[test-room] spawned 0x%X %s -> 0x%08X\n", entry.id, entry.name, object);
                fflush(stdout);
            }
            if (heap_check_on) {
                if (uint32_t bad = heap_check(rdram)) {
                    printf("[test-room] heap broken at 0x%08X right after spawning 0x%X %s\n", bad, entry.id, entry.name);
                    heap_dump(rdram, bad);
                    fflush(stdout);
                    heap_check_on = false;
                }
            }
        }
        if (next_spawn >= slots.size()) {
            filling = false;
            if (log_on) {
                printf("[test-room] done\n");
                fflush(stdout);
            }
        }
    }

    if (heap_check_on && !slots.empty()) {
        if (uint32_t bad = heap_check(rdram)) {
            printf("[test-room] heap broken at 0x%08X at the start of a frame (last spawned: %zu)\n", bad, next_spawn);
            heap_dump(rdram, bad);
            fflush(stdout);
            heap_check_on = false;
        }
    }
    if (!slots.empty()) {
        hold(rdram);
        if (!filling) {
            touch_forms(rdram);
        }
    }

    if (log_on && !slots.empty()) {
        auto now = std::chrono::steady_clock::now();
        if (now - last_log > std::chrono::seconds(2)) {
            last_log = now;
            int alive = 0;
            for (const Slot& slot : slots) {
                alive += (slot.marker != 0 && !slot.gone) ? 1 : 0;
            }
            // The game's heap: bytes free and the largest free block.
            recomp_context saved = *ctx;
            heap_bytes_free(rdram, ctx);
            const uint32_t free_bytes = (uint32_t)ctx->r2;
            *ctx = saved;
            printf("[test-room] %d of %zu actors present, heap %u KB free (largest block %u KB)\n", alive, slots.size(),
                free_bytes / 1024, largest_free(rdram) / 1024);
            fflush(stdout);
        }
    }
}
