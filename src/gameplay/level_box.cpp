// The extent of the current level from the game's own collision: see include/tooie_level_box.h.
//
// The game's camera line test (tooie::free_camera::sweep_line, func_800FAB50) does the work. A ray is cast straight
// down at each point of a grid round Banjo, from well above him to well below. A hit on a surface facing down (an
// invisible ceiling over the level, or the underside of a ledge) is stepped past and the ray goes on, so the grid
// keeps the highest ground at each point. The level is the ground joined to the point under Banjo, gaps of up to a few
// grid steps allowed (Cloud Cuckooland's floating pieces); ground further off
// is left out of the box.

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <cstdio>
#include <vector>

#include "tooie_debug.h"
#include "tooie_free_camera.h"
#include "tooie_level_box.h"

namespace {
    // The grid reaches this far from Banjo each way, with points this far apart. The largest levels (Isle o' Hags,
    // Witchyworld) are about 20000 across, and Banjo can stand near one edge.
    constexpr float reach = 40000.0f;
    constexpr float step = 800.0f;
    // Each ray runs from this far above Banjo to this far below him.
    constexpr float ray_up = 20000.0f;
    constexpr float ray_down = 20000.0f;
    // The line test is a sphere this wide swept along the ray; it stops this far above the ground.
    constexpr float sweep_radius = 45.0f;
    // A surface whose normal points up less than this is not ground (a wall, a ceiling); the ray steps past it.
    constexpr float ground_normal_y = 0.3f;
    constexpr int max_steps_past = 6;

    // Ground points this many grid steps apart or closer count as joined.
    constexpr int join_gap = 3;
    // The ground point nearest Banjo is looked for this many grid steps round him.
    constexpr int seed_reach = 6;

    tooie::level_box::Box cached;

    // The highest ground under (x, z) between top and bottom, or no_ground.
    float ground_at(uint8_t* rdram, recomp_context* ctx, float x, float z, float top, float bottom) {
        float y = top;
        for (int i = 0; i <= max_steps_past; i++) {
            const float from[3] = { x, y, z };
            float to[3] = { x, bottom, z };
            float normal[3];
            if (!tooie::free_camera::sweep_line(rdram, ctx, from, to, normal)) {
                return tooie::level_box::no_ground;
            }
            if (normal[1] >= ground_normal_y) {
                return to[1] - sweep_radius;
            }
            y = to[1] - 2.0f * sweep_radius - 1.0f;
            if (y <= bottom) {
                break;
            }
        }
        return tooie::level_box::no_ground;
    }
}

bool tooie::level_box::measure(uint8_t* rdram, recomp_context* ctx, const float centre[3], Box& out) {
    const uint16_t map = tooie::debug::current_map(rdram);
    if (cached.map == map && cached.hits > 0) {
        out = cached;
        return true;
    }
    const auto start = std::chrono::steady_clock::now();
    Box b;
    b.map = map;
    b.step = step;
    b.cols = b.rows = int(2.0f * reach / step) + 1;
    b.origin_x = centre[0] - reach;
    b.origin_z = centre[2] - reach;
    b.heights.assign(size_t(b.cols) * size_t(b.rows), no_ground);
    const float top = centre[1] + ray_up;
    const float bottom = centre[1] - ray_down;
    for (int r = 0; r < b.rows; r++) {
        for (int c = 0; c < b.cols; c++) {
            b.heights[size_t(r) * b.cols + c] = ground_at(rdram, ctx, b.origin_x + c * step, b.origin_z + r * step, top, bottom);
        }
    }
    // The ground joined to Banjo's: a flood from the ground point nearest him, across gaps up to join_gap steps.
    const int centre_c = (b.cols - 1) / 2;
    const int centre_r = (b.rows - 1) / 2;
    int total = 0;
    for (float y : b.heights) {
        total += y != no_ground ? 1 : 0;
    }
    int seed = -1;
    for (int ring = 0; ring <= seed_reach && seed < 0; ring++) {
        for (int r = centre_r - ring; r <= centre_r + ring && seed < 0; r++) {
            for (int c = centre_c - ring; c <= centre_c + ring; c++) {
                if (std::max(std::abs(r - centre_r), std::abs(c - centre_c)) == ring && b.heights[size_t(r) * b.cols + c] != no_ground) {
                    seed = r * b.cols + c;
                    break;
                }
            }
        }
    }
    b.in_level.assign(b.heights.size(), 0);
    std::vector<int> todo;
    if (seed >= 0) {
        b.in_level[seed] = 1;
        todo.push_back(seed);
    }
    while (!todo.empty()) {
        const int at = todo.back();
        todo.pop_back();
        const int r0 = at / b.cols, c0 = at % b.cols;
        const float p[3] = { b.origin_x + c0 * step, b.heights[at], b.origin_z + r0 * step };
        for (int k = 0; k < 3; k++) {
            b.min[k] = b.hits == 0 ? p[k] : std::min(b.min[k], p[k]);
            b.max[k] = b.hits == 0 ? p[k] : std::max(b.max[k], p[k]);
        }
        b.hits++;
        for (int r = std::max(r0 - join_gap, 0); r <= std::min(r0 + join_gap, b.rows - 1); r++) {
            for (int c = std::max(c0 - join_gap, 0); c <= std::min(c0 + join_gap, b.cols - 1); c++) {
                const int i = r * b.cols + c;
                if (!b.in_level[i] && b.heights[i] != no_ground) {
                    b.in_level[i] = 1;
                    todo.push_back(i);
                }
            }
        }
    }
    // The grid only sees ground at its points, so the level reaches up to a step past the outermost ones.
    b.min[0] -= step;
    b.max[0] += step;
    b.min[2] -= step;
    b.max[2] += step;
    const double ms = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start).count();
    fprintf(stderr, "[levelbox] map 0x%X: %d of %d points have ground, %d of them joined to Banjo's, x %.0f to %.0f, y %.0f to %.0f, "
        "z %.0f to %.0f (%.0f ms)\n", map, total, b.cols * b.rows, b.hits, b.min[0], b.max[0], b.min[1], b.max[1], b.min[2], b.max[2], ms);
    if (b.hits == 0) {
        return false;
    }
    cached = b;
    out = b;
    return true;
}

bool tooie::level_box::save_picture(const Box& box, const char* path) {
    FILE* f = std::fopen(path, "wb");
    if (f == nullptr) {
        return false;
    }
    std::fprintf(f, "P5\n%d %d\n255\n", box.cols, box.rows);
    const float span = std::max(box.max[1] - box.min[1], 1.0f);
    std::vector<uint8_t> row(size_t(box.cols));
    for (int r = 0; r < box.rows; r++) {
        for (int c = 0; c < box.cols; c++) {
            const size_t i = size_t(r) * box.cols + c;
            const float y = box.heights[i];
            if (y == no_ground) {
                row[c] = 0;
            }
            else if (i < box.in_level.size() && box.in_level[i]) {
                row[c] = uint8_t(96.0f + 159.0f * std::clamp((y - box.min[1]) / span, 0.0f, 1.0f));
            }
            else {
                row[c] = 48;
            }
        }
        std::fwrite(row.data(), 1, row.size(), f);
    }
    return std::fclose(f) == 0;
}

float tooie::level_box::overview_height(const Box& box, float fov, float aspect, float margin) {
    const float tan_v = std::tan(fov * 0.5f * 3.14159265f / 180.0f);
    const float tan_h = tan_v * aspect;
    const float cx = (box.min[0] + box.max[0]) * 0.5f;
    const float cz = (box.min[2] + box.max[2]) * 0.5f;
    // Clear of the highest ground, then high enough that each point of the level's ground, a grid step wider, is in
    // the picture at its own height.
    float height = box.max[1] + 500.0f;
    for (int r = 0; r < box.rows; r++) {
        for (int c = 0; c < box.cols; c++) {
            const size_t i = size_t(r) * box.cols + c;
            if (i >= box.in_level.size() || !box.in_level[i]) {
                continue;
            }
            const float dx = std::fabs(box.origin_x + c * box.step - cx) + box.step;
            const float dz = std::fabs(box.origin_z + r * box.step - cz) + box.step;
            height = std::max(height, box.heights[i] + margin * std::max(dx / tan_h, dz / tan_v));
        }
    }
    return height;
}
