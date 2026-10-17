// Per-frame drawing memory guard.
//
// The game builds each frame's display list, matrices and vertices in fixed
// double buffers (pointers at D_80127658: list head, matrix head, vertex
// head; buffers listed at D_8007BCD0, two of each, back to back, the one in use
// chosen by D_8007BEDA: lists
// 0x76D0 bytes each, matrices 0x12C10, vertices 0x1AF0). It never checks the
// ends, as the original game's own drawing always fits (at most about a
// third of each, measured headless). Extended draw distance and HD shadows
// draw more models into the same buffers: in Mayahem Temple both together
// filled 92% of the list buffer, and a busier scene can run past the end.
// Writing past the list buffer lands in the other frame's list or in the
// matrices, which shows as torn geometry, exploded models or a crash on a
// garbage display list command.
//
// room_for_extras() says whether the extras may still draw: they stop while
// enough is left for all of the game's own drawing (the margins below, about
// 1.3x the most the game used on its own). The game's own models are always
// drawn; only the extra far ones and extra shadows are skipped that frame.
//
// tooie_list_end_guard() runs twice as the game closes the frame's list: before
// func_800C940C, which draws the transition (fades, the warp's fade-in) and the
// viewport, and before func_800E7EF4, which adds the full sync and the end. L's
// crash of 2026-10-17 12:22:25 was one frame right after a warp into Icy Side
// that filled the whole 256 KB list buffer (normally about 10 KB there); the
// commands after it landed on the heap block that follows the buffer and broke
// the heap. What filled it is not known (it did not happen headless). The guard
// keeps the end of the list inside the buffer by moving the head back over the
// frame's last commands when it is within reach of the end: that frame loses a
// little of its drawing instead of the heap. Logged once per map as [gfx] list
// full, with the map and how full the buffer was, to find the cause next time.
// A head already past the end has damaged the heap; that is logged every time.
//
// What filled the list is reported, so one log is enough to find the cause: the
// first time in a map that a frame's list passes half its buffer, when the guard
// above cuts a frame, and the moment a model draw starts past the end (before the
// damage can crash the game), a [gfx] report lists the map, Banjo's position,
// Photo Mode and the game's time step, how the list grew over the last frames,
// the bytes frame interpolation's tags added, and the code that drew the most:
// each model draw (func_800DE498) is counted by model asset with the list bytes
// it wrote, and the bytes drawn outside model draws are added up. Written to
// the console and to crashes.log.
//
// TOOIE_GFX_LOG=1: every 2 s, the most of each buffer a frame used, and the report for that frame.
// TOOIE_GFX_FILL=<bytes>: test aid, on one frame in Icy Side (0x128) with models drawn moves the
// list head that far on before the guard runs, as a frame that drew that much
// more would.

#include <algorithm>
#include <chrono>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>

#include "recomp.h"
#include "tooie_game.h"
#include "tooie_gfx_budget.h"
#include "tooie_photo_mode.h"
#include "tooie_rdram.h"

namespace {
    constexpr gpr heads_addr = (int32_t)0x80127658;
    constexpr gpr buffers_addr = (int32_t)0x8007BCD0;
    // Bytes kept free for the game's own drawing: lists, matrices.
    constexpr uint32_t margin[2] = { 0x3000, 0x6000 };

    // The buffer this frame draws into (0 or 1), set by func_8001A4B8.
    constexpr gpr index_addr = (int32_t)0x8007BEDA;

    // Bytes used so far in this frame's buffer, and its size. False if the
    // head is not in it (not drawing yet).
    bool usage(uint8_t* rdram, int pool, uint32_t* used, uint32_t* size) {
        const uint32_t b0 = (uint32_t)MEM_W(8 * pool, buffers_addr);
        const uint32_t b1 = (uint32_t)MEM_W(8 * pool + 4, buffers_addr);
        const int index = MEM_H(0, index_addr);
        if (b1 <= b0 || (index != 0 && index != 1)) {
            return false;
        }
        *size = b1 - b0;
        const uint32_t start = index == 0 ? b0 : b1;
        const uint32_t head = (uint32_t)MEM_W(4 * pool, heads_addr);
        if (head < start || head >= start + *size * 2) {
            return false;
        }
        *used = head - start;
        return true;
    }

    const bool log_on = std::getenv("TOOIE_GFX_LOG") != nullptr;
    uint32_t peak[2] = {};
    uint32_t skipped = 0;

    constexpr uint32_t map_addr = 0x80132DC2;

    // This frame's list buffer: its start and end (the heap header after it left out). False
    // while no buffer is chosen.
    bool list_bounds(uint8_t* rdram, uint32_t* start, uint32_t* end) {
        const uint32_t b0 = (uint32_t)MEM_W(0, buffers_addr);
        const uint32_t b1 = (uint32_t)MEM_W(4, buffers_addr);
        const int index = MEM_H(0, index_addr);
        if (b1 <= b0 || (index != 0 && index != 1)) {
            return false;
        }
        *start = index == 0 ? b0 : b1;
        *end = *start + (b1 - b0) - 0x10;
        return true;
    }

    // This frame's model draws, by the model asset drawn (as func_800DE498 settles on it).
    struct Kind {
        uint32_t model;
        uint32_t models;
        uint32_t bytes;
    };
    constexpr int max_kinds = 64;
    Kind kinds[max_kinds];
    int kind_count = 0;
    uint32_t models = 0;
    uint32_t other = 0;          // List bytes outside model draws: level, particles, HUD...
    int last_kind = -1;          // The model being drawn, or -1 between models.
    bool in_model = false;
    uint32_t last_head = 0;
    uint32_t frame_start = 0;
    // The 2D is done; the counts stay for the list's closing guard until the next frame draws.
    bool frame_done = false;
    uint32_t tag_bytes[2] = {};  // Frame interpolation tags: 3D scene, 2D.
    // The whole list's size over the last frames, newest last.
    constexpr int history_size = 8;
    uint32_t history[history_size] = {};
    uint32_t frames = 0;
    uint16_t heavy_map = 0xFFFF;
    uint16_t past_map = 0xFFFF;

    void add_bytes(uint32_t head) {
        if (head > last_head) {
            const uint32_t bytes = head - last_head;
            if (in_model && last_kind >= 0) {
                kinds[last_kind].bytes += bytes;
            } else {
                other += bytes;
            }
        }
        last_head = head;
    }

    void reset_frame() {
        kind_count = 0;
        models = 0;
        other = 0;
        last_kind = -1;
        in_model = false;
        last_head = 0;
        frame_start = 0;
        frame_done = false;
    }

    // Adds one printf-formatted line to text.
    void add(std::string& text, const char* fmt, ...) {
        char line[256];
        va_list args;
        va_start(args, fmt);
        std::vsnprintf(line, sizeof(line), fmt, args);
        va_end(args);
        text += line;
        text += '\n';
    }

    void report(uint8_t* rdram, const char* why, uint32_t used, uint32_t size, bool to_crash_log) {
        using namespace tooie::rdram;
        const uint16_t map = (uint16_t)MEM_HU(0, (int32_t)map_addr);
        char line[256];
        std::string text;
        add(text, "[gfx] %s: map 0x%X, list %X of %X bytes used, %u models drawn so far", why, map, used, size, models);
        const uint32_t player = read_word(rdram, 0x80135490);
        const uint32_t transform = valid_ptr(player) ? read_word(rdram, player + 0xE4) : 0;
        if (valid_ptr(transform)) {
            add(text, "[gfx]   Banjo at %.0f, %.0f, %.0f", read_float(rdram, transform), read_float(rdram, transform + 4),
                read_float(rdram, transform + 8));
        } else {
            add(text, "%s", "[gfx]   Banjo not in play");
        }
        const float step = read_float(rdram, 0x8012C760);
        add(text, "[gfx]   Photo Mode %s, game time step %g s%s", tooie::photo_mode::active() ? "on" : "off", step,
            step < 1e-6f ? " (time frozen)" : "");
        std::string grown;
        for (int i = 0; i < history_size; i++) {
            const uint32_t v = history[(frames + i) % history_size];
            if (v != 0) {
                std::snprintf(line, sizeof(line), " %X", v);
                grown += line;
            }
        }
        add(text, "[gfx]   whole list, last frames (oldest first):%s", grown.empty() ? " none yet" : grown.c_str());
        add(text, "[gfx]   interpolation tags added last frame: %X (3D), %X (2D)", tag_bytes[0], tag_bytes[1]);
        add(text, "[gfx]   drawn outside models (level, particles, HUD, HD shadows): %X bytes", other);
        // The models that drew the most, by bytes, named by asset id where the game's asset
        // cache has them: ids at 0x80137800 (halfwords), pointers at 0x80137AD0, count at 0x8012B7E4
        // (func_800D5AB4 looks an id up there).
        const int slots = std::min<int>(read_word(rdram, 0x8012B7E4) >> 24, 0xF0);
        auto asset_id = [&](uint32_t model) {
            for (int i = 0; i < slots; i++) {
                if (read_word(rdram, 0x80137AD0 + 4 * i) == model) {
                    return (int)(uint16_t)read_half(rdram, 0x80137800 + 2 * i);
                }
            }
            return -1;
        };
        Kind sorted[max_kinds];
        std::copy(kinds, kinds + kind_count, sorted);
        std::sort(sorted, sorted + kind_count, [](const Kind& a, const Kind& b) { return a.bytes > b.bytes; });
        for (int i = 0; i < std::min(kind_count, 12); i++) {
            const int id = asset_id(sorted[i].model);
            char name[32];
            if (id >= 0) {
                std::snprintf(name, sizeof(name), "asset %04X", id);
            } else {
                std::snprintf(name, sizeof(name), "model at %08X", sorted[i].model);
            }
            add(text, "[gfx]   %s: drawn %u times, %X bytes", name, sorted[i].models, sorted[i].bytes);
        }
        if (kind_count == max_kinds) {
            add(text, "[gfx]   (more kinds of model than counted)");
        }
        std::fputs(text.c_str(), stderr);
        std::fflush(stderr);
        if (to_crash_log) {
            char when[32];
            const std::time_t now = std::time(nullptr);
            std::strftime(when, sizeof(when), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
            tooie::crash_log_line(when);
            size_t pos = 0;
            while (pos < text.size()) {
                const size_t nl = text.find('\n', pos);
                tooie::crash_log_line(text.substr(pos, nl - pos).c_str());
                pos = nl + 1;
            }
        }
    }
}

void tooie::gfx_budget::note_model(uint8_t* rdram, recomp_context* ctx) {
    // $a0 points at the list pointer the model draws with.
    const uint32_t gfx = (uint32_t)ctx->r4;
    uint32_t start, end;
    if (!tooie::rdram::valid_ptr(gfx) || (gfx & 3) != 0 || !list_bounds(rdram, &start, &end)) {
        return;
    }
    const uint32_t head = tooie::rdram::read_word(rdram, gfx);
    if (head < start || head >= start + 2 * (end + 0x10 - start)) {
        return;  // Not this frame's list (a shadow image or a room's own table).
    }
    if (frame_start != start || frame_done) {
        reset_frame();
        frame_start = start;
        last_head = start;
    }
    add_bytes(head);
    models++;
    // Its bytes go to its model once note_model_kind knows it.
    last_kind = -1;
    in_model = true;
    const uint16_t map = (uint16_t)MEM_HU(0, (int32_t)map_addr);
    if (head > end && map != past_map) {
        past_map = map;
        report(rdram, "list ran past its buffer while drawing", head - start, end - start, true);
    }
}

// func_800DE498's exit: the model's drawing is done. Its list pointer's address is at 0xF8($sp).
extern "C" void tooie_gfx_model_done(uint8_t* rdram, recomp_context* ctx) {
    if (!in_model) {
        return;
    }
    const uint32_t gfx = (uint32_t)MEM_W(0xF8, ctx->r29);
    uint32_t start, end;
    if (tooie::rdram::valid_ptr(gfx) && (gfx & 3) == 0 && list_bounds(rdram, &start, &end) && start == frame_start) {
        add_bytes(tooie::rdram::read_word(rdram, gfx));
    }
    in_model = false;
    last_kind = -1;
}

void tooie::gfx_budget::note_model_kind(uint8_t* rdram, uint32_t model) {
    (void)rdram;
    if (!in_model) {
        return;
    }
    int i = 0;
    while (i < kind_count && kinds[i].model != model) {
        i++;
    }
    if (i == kind_count) {
        if (kind_count == max_kinds) {
            return;
        }
        kinds[kind_count++] = { model, 0, 0 };
    }
    kinds[i].models++;
    last_kind = i;
}

void tooie::gfx_budget::note_tags(int part, uint32_t bytes) {
    tag_bytes[part & 1] = bytes;
}

extern "C" void tooie_list_end_guard(uint8_t* rdram, recomp_context* ctx, int step) {
    (void)ctx;
    const uint32_t b0 = (uint32_t)MEM_W(0, buffers_addr);
    const uint32_t b1 = (uint32_t)MEM_W(4, buffers_addr);
    const int index = MEM_H(0, index_addr);
    if (b1 <= b0 || (index != 0 && index != 1)) {
        return;
    }
    const uint32_t start = index == 0 ? b0 : b1;
    // The buffers are heap blocks: b1 - b0 is one buffer and the 16-byte heap header after it.
    const uint32_t end = start + (b1 - b0) - 0x10;
    // Step 0, before the transition: room for it, the viewport and the closing
    // commands (the transition normally adds under 0x100 bytes).
    // Step 1, after it: room for the full sync and end (0x10 bytes).
    const uint32_t tail = step == 0 ? 0x800 : 0x10;
    static const uint32_t test_fill = [] {
        const char* env = std::getenv("TOOIE_GFX_FILL");
        return env ? (uint32_t)std::strtoul(env, nullptr, 0) : 0u;
    }();
    uint32_t head = (uint32_t)MEM_W(0, heads_addr);
    static bool test_filled = false;
    if (step == 0 && test_fill != 0 && !test_filled && head >= start && head < end
        && MEM_HU(0, (int32_t)0x80132DC2) == 0x128 && models > 10) {
        test_filled = true;
        // Fill with no-ops (G_NOOP), as real drawing would, then move the head on.
        const uint32_t target = std::min(head + (test_fill & ~7u), end);
        for (uint32_t a = head; a < target; a += 8) {
            MEM_W(0, (int32_t)a) = 0;
            MEM_W(4, (int32_t)a) = 0;
        }
        head = target;
        MEM_W(0, heads_addr) = (int32_t)head;
    }
    if (head < start || head >= start + 2 * (b1 - b0) || head + tail <= end) {
        return;
    }
    static uint16_t logged_map = 0xFFFF;
    const uint16_t map = (uint16_t)MEM_HU(0, (int32_t)0x80132DC2);
    if (start == frame_start) {
        add_bytes(head);
    }
    if (head > end) {
        // Already past the end: the heap after the buffer is damaged. Pulling the
        // head back still keeps the closing commands off it.
        std::fprintf(stderr, "[gfx] list ran %X bytes past its buffer in map 0x%X (%s the transition); the heap after it is damaged\n",
            head - end, map, step == 0 ? "before" : "in");
        if (map != logged_map) {
            logged_map = map;
            report(rdram, "list ran past its buffer", head - start, end - start, true);
        }
    } else if (map != logged_map) {
        logged_map = map;
        std::fprintf(stderr, "[gfx] list full in map 0x%X: %X of %X used; the frame's last commands were dropped so the heap stays intact\n",
            map, head - start, end - start);
        report(rdram, "list full", head - start, end - start, true);
    }
    MEM_W(0, heads_addr) = (int32_t)(end - tail);
}

bool tooie::gfx_budget::room_for_extras(uint8_t* rdram) {
    for (int pool = 0; pool < 2; pool++) {
        uint32_t used, size;
        // Not in a known buffer (a few rooms draw into their own table at
        // D_8007BCE8, which this does not measure): no extras rather than
        // unguarded ones.
        if (!usage(rdram, pool, &used, &size) || used + margin[pool] > size) {
            skipped++;
            return false;
        }
    }
    return true;
}

void tooie::gfx_budget::frame_end(uint8_t* rdram) {
    static uint32_t sizes[2] = {};
    bool over = false;
    for (int pool = 0; pool < 2; pool++) {
        uint32_t used, size;
        if (usage(rdram, pool, &used, &size)) {
            peak[pool] = std::max(peak[pool], used);
            sizes[pool] = size;
            over = over || used > size;
        }
    }
    uint32_t start, end;
    if (list_bounds(rdram, &start, &end)) {
        const uint32_t head = (uint32_t)MEM_W(0, heads_addr);
        if (head >= start && head < start + 2 * (end + 0x10 - start)) {
            if (start == frame_start) {
                add_bytes(head);
            }
            history[frames++ % history_size] = head - start;
            const uint16_t map = (uint16_t)MEM_HU(0, (int32_t)map_addr);
            if (head - start > (end - start) / 2 && map != heavy_map) {
                heavy_map = map;
                report(rdram, "list over half full", head - start, end - start, false);
            }
        }
    }
    static auto last = std::chrono::steady_clock::now();
    static bool reported = false;
    if (over && !reported) {
        std::fprintf(stderr, "[gfx] The game's drawing memory overflowed (lists %X of %X, matrices %X of %X).\n",
            peak[0], sizes[0], peak[1], sizes[1]);
        reported = true;
    }
    if (log_on && std::chrono::steady_clock::now() - last > std::chrono::seconds(2)) {
        last = std::chrono::steady_clock::now();
        std::printf("[gfx] most used: lists %X of %X, matrices %X of %X; extras skipped %u times\n",
            peak[0], sizes[0], peak[1], sizes[1], skipped);
        std::fflush(stdout);
        if (uint32_t start, end; list_bounds(rdram, &start, &end) && start == frame_start) {
            report(rdram, "this frame", last_head - start, end - start, false);
        }
        peak[0] = peak[1] = 0;
        skipped = 0;
    }
    frame_done = true;
}
