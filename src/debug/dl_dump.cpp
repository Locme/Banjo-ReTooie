// Display list dump for headless investigations.
//
//     TOOIE_DLDUMP=20000        dump the 3D scene of the first frame drawn
//                               20 s after the game loop first runs
//     TOOIE_DLDUMP=20000,20100  several dumps
//
// Each dump goes to dl_<ms>.txt in the working directory: one line per
// command, following branches into called display lists (segments resolved),
// with matrices, vertex loads and segment changes spelled out and runs of
// triangles collapsed. hide_hud.cpp's first mark (after the 3D scene) calls
// tooie::dl_dump::scene_end; model_tagging.cpp knows where the frame starts.

#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <mutex>
#include <sstream>
#include <string>
#include <vector>

#include "recomp.h"
#include "tooie_debug.h"
#include "tooie_model_tagging.h"

namespace {
    std::once_flag env_flag;
    std::vector<uint32_t> times;
    size_t next_time = 0;
    std::chrono::steady_clock::time_point started;

    void read_env() {
        started = std::chrono::steady_clock::now();
        const char* env = std::getenv("TOOIE_DLDUMP");
        if (env == nullptr) {
            return;
        }
        std::stringstream stream{env};
        std::string item;
        while (std::getline(stream, item, ',')) {
            if (!item.empty()) {
                times.push_back((uint32_t)std::strtoul(item.c_str(), nullptr, 10));
            }
        }
    }

    struct Dumper {
        uint8_t* rdram;
        FILE* out;
        uint32_t segments[16] = {};
        int tris = 0;

        uint32_t resolve(uint32_t addr) {
            if ((addr & 0x80000000) != 0) {
                return addr & 0x1FFFFFFF;
            }
            return (segments[(addr >> 24) & 0xF] + (addr & 0xFFFFFF)) & 0x1FFFFFFF;
        }

        uint32_t word(uint32_t phys) {
            return (uint32_t)MEM_W(0, (int32_t)(0x80000000 | phys));
        }

        void flush_tris(int depth) {
            if (tris != 0) {
                std::fprintf(out, "%*s  tris %d\n", depth * 2, "", tris);
                tris = 0;
            }
        }

        // Walks one display list. Returns true at G_ENDDL or a branch.
        void walk(uint32_t phys, int depth, uint32_t end) {
            for (int n = 0; n < 20000; n++, phys += 8) {
                if (end != 0 && phys >= end) {
                    break;
                }
                uint32_t w0 = word(phys);
                uint32_t w1 = word(phys + 4);
                uint8_t op = w0 >> 24;
                if (op == 0x05 || op == 0x06 || op == 0x07) {
                    tris += op == 0x05 ? 1 : 2;
                    continue;
                }
                flush_tris(depth);
                const char* pad = "";
                switch (op) {
                case 0x01: {
                    uint32_t count = (w0 >> 12) & 0xFF;
                    uint32_t last = (w0 >> 1) & 0x7F;
                    std::fprintf(out, "%*s%06X VTX n=%u v0=%u src=%08X (%08X)\n", depth * 2, pad, phys, count, last - count, w1, resolve(w1));
                    break;
                }
                case 0xDA: {
                    uint32_t params = (w0 & 0xFF) ^ 1;
                    uint32_t src = resolve(w1);
                    std::fprintf(out, "%*s%06X MTX %s%s%s src=%08X (%08X) t=%d,%d,%d\n", depth * 2, pad, phys,
                        (params & 4) ? "PROJ" : "MV", (params & 2) ? " LOAD" : " MUL", (params & 1) ? " PUSH" : "",
                        w1, src, (int16_t)(word(src + 0x18) >> 16), (int16_t)(word(src + 0x1C) >> 16) ,(int16_t)(word(src + 0x1C) & 0xFFFF));
                    break;
                }
                case 0xD8:
                    std::fprintf(out, "%*s%06X POPMTX %u\n", depth * 2, pad, phys, w1 / 64);
                    break;
                case 0xDB:
                    if (((w0 >> 16) & 0xFF) == 0x06) {
                        uint32_t seg = (w0 & 0xFFFF) / 4;
                        segments[seg & 0xF] = w1 & 0x1FFFFFFF;
                        std::fprintf(out, "%*s%06X SEG %u = %08X\n", depth * 2, pad, phys, seg, w1);
                    }
                    break;
                case 0xDE: {
                    uint32_t target = resolve(w1);
                    bool branch = ((w0 >> 16) & 0xFF) != 0;
                    std::fprintf(out, "%*s%06X %s %08X (%08X)\n", depth * 2, pad, phys, branch ? "BRANCH" : "CALL", w1, target);
                    if (depth < 12 && target != 0) {
                        walk(target, depth + 1, 0);
                    }
                    if (branch) {
                        return;
                    }
                    break;
                }
                case 0xDF:
                    return;
                case 0x00:
                    if (w1 != 0) {
                        std::fprintf(out, "%*s%06X EX %08X %08X\n", depth * 2, pad, phys, w0, w1);
                    }
                    break;
                case 0xFD:
                    std::fprintf(out, "%*s%06X TIMG %08X\n", depth * 2, pad, phys, w1);
                    break;
                default:
                    break;
                }
            }
            flush_tris(depth);
        }
    };
}

void tooie::dl_dump::scene_end(uint8_t* rdram, uint32_t gfx_end) {
    std::call_once(env_flag, read_env);
    if (next_time >= times.size()) {
        return;
    }
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - started).count();
    if ((uint32_t)elapsed < times[next_time]) {
        return;
    }
    std::string name = "dl_" + std::to_string(times[next_time]) + ".txt";
    next_time++;
    FILE* out = std::fopen(name.c_str(), "w");
    if (out == nullptr) {
        return;
    }
    Dumper dumper{rdram, out};
    dumper.walk(tooie::model_tagging::scene_start(), 0, gfx_end & 0x1FFFFFFF);
    std::fclose(out);
    std::fprintf(stderr, "[dldump] wrote %s\n", name.c_str());
}
