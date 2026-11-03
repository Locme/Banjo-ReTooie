//
// RT64
//
// Banjo-Tooie: Blend texture seams' neighbour search, moved here from FramebufferRenderer::addFramebuffer
// (lib-patches/rt64.patch keeps the collection of pieces and the call).

#include "rt64_texture_seams.h"

#include <algorithm>
#include <atomic>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <utility>

#include "shared/rt64_raster_params.h"

namespace RT64 {
    namespace {
        // NoteSnapDraw's counts since the last TOOIE_SEAM_LOG line (draws, framebuffer textures, wrapping one period, snapped).
        std::atomic<uint32_t> snapDraws{ 0 };
        std::atomic<uint32_t> snapFromFramebuffer{ 0 };
        std::atomic<uint32_t> snapWrapping{ 0 };
        std::atomic<uint32_t> snapSnapped{ 0 };
    }

    void NoteSnapDraw(bool fromFramebuffer, bool wrapsOnePeriod, bool snapped) {
        static const bool seamLog = (getenv("TOOIE_SEAM_LOG") != nullptr);
        if (!seamLog) {
            return;
        }
        snapDraws++;
        snapFromFramebuffer += fromFramebuffer ? 1u : 0u;
        snapWrapping += wrapsOnePeriod ? 1u : 0u;
        snapSnapped += snapped ? 1u : 0u;
    }

    void FindTextureSeams(const std::vector<SeamPiece> &seamPieces, const std::vector<SeamPoint> &seamPoints, size_t instanceCount,
        std::vector<interop::uint4> &instanceSeamVector)
    {
        // TOOIE_SEAM_LOG: the vertex snapping's counts (NoteSnapDraw), every 120 framebuffers: 0 snapped outside Jiggywiggy's puzzle.
        {
            static const bool snapLog = (getenv("TOOIE_SEAM_LOG") != nullptr);
            static uint32_t snapLogFramebuffers = 0;
            if (snapLog && ((++snapLogFramebuffers % 120) == 0)) {
                fprintf(stdout, "[seam] %u draws: %u sample a framebuffer, %u wrap with a period of exactly their tile, %u snapped to the N64's quarter-pixel grid and sampled at the game pixel's centre\n",
                    snapDraws.exchange(0), snapFromFramebuffer.exchange(0), snapWrapping.exchange(0), snapSnapped.exchange(0));
                fflush(stdout);
            }
        }
        // Banjo-Tooie: Blend texture seams: a piece's neighbour along an edge has at least two points of its opposite edge in
        // the same places as this one's (on the screen and at the same depth), at the same texels along the edge.
        if (seamPieces.size() > 1) {
            instanceSeamVector.resize(instanceCount, interop::uint4(RASTER_SEAM_NONE, RASTER_SEAM_NONE, RASTER_SEAM_NONE, RASTER_SEAM_NONE));
            auto cellOf = [](float x, float y) {
                return (uint64_t(uint32_t(int32_t(std::floor(x * 2048.0f)))) << 32) | uint64_t(uint32_t(int32_t(std::floor(y * 2048.0f))));
            };
            auto same = [](const interop::float3 &a, const interop::float3 &b) {
                return (std::abs(a.x - b.x) < 2e-4f) && (std::abs(a.y - b.y) < 2e-4f) && (std::abs(a.z - b.z) <= (std::max(std::abs(a.z), std::abs(b.z)) * 2e-3f + 1e-4f));
            };
            // Each edge point by its cell, with its piece: a list sorted by cell (a hash multimap allocated a node per point
            // every frame, which with the lookups below was most of the renderer's CPU time in Terrydactyland).
            thread_local std::vector<std::pair<uint64_t, uint32_t>> pointsByCell;
            thread_local std::vector<uint32_t> pointPiece;
            pointsByCell.clear();
            pointPiece.assign(seamPoints.size(), 0);
            for (uint32_t i = 0; i < seamPieces.size(); i++) {
                for (uint32_t k = 0; k < seamPieces[i].pointCount; k++) {
                    const uint32_t pi = seamPieces[i].pointStart + k;
                    pointPiece[pi] = i;
                    pointsByCell.emplace_back(cellOf(seamPoints[pi].position.x, seamPoints[pi].position.y), pi);
                }
            }
            std::sort(pointsByCell.begin(), pointsByCell.end());
            auto cellRange = [&](uint64_t cell) {
                auto first = std::lower_bound(pointsByCell.begin(), pointsByCell.end(), std::pair<uint64_t, uint32_t>(cell, 0));
                auto last = first;
                while ((last != pointsByCell.end()) && (last->first == cell)) {
                    last++;
                }
                return std::make_pair(first, last);
            };
            // The piece whose edge (other) meets a's edge (edge) at two or more points.
            auto find = [&](uint32_t ai, uint32_t edge, uint32_t other) -> uint32_t {
                const SeamPiece &a = seamPieces[ai];
                const bool alongT = (edge & 3u) != 0;
                uint32_t best = RASTER_SEAM_NONE, bestCount = 0;
                uint32_t candidates[8] = {};
                uint32_t counts[8] = {};
                uint32_t candidateCount = 0;
                for (uint32_t k = 0; k < a.pointCount; k++) {
                    const SeamPoint &pa = seamPoints[a.pointStart + k];
                    if ((pa.edges & edge) == 0) {
                        continue;
                    }
                    // Only the cells a point within same()'s reach (2e-4 on x and y, with a margin) can be in, usually one (it was all nine around).
                    const int64_t x0 = int64_t(std::floor((pa.position.x - 2.5e-4f) * 2048.0f)), x1 = int64_t(std::floor((pa.position.x + 2.5e-4f) * 2048.0f));
                    const int64_t y0 = int64_t(std::floor((pa.position.y - 2.5e-4f) * 2048.0f)), y1 = int64_t(std::floor((pa.position.y + 2.5e-4f) * 2048.0f));
                    uint32_t matchedHere[8] = {};
                    uint32_t matchedHereCount = 0;
                    for (int64_t cellX = x0; cellX <= x1; cellX++) {
                        for (int64_t cellY = y0; cellY <= y1; cellY++) {
                            auto range = cellRange((uint64_t(uint32_t(int32_t(cellX))) << 32) | uint64_t(uint32_t(int32_t(cellY))));
                            for (auto it = range.first; it != range.second; it++) {
                                const SeamPoint &pb = seamPoints[it->second];
                                const uint32_t bi = pointPiece[it->second];
                                if ((bi == ai) || ((pb.edges & other) == 0) || !same(pa.position, pb.position)) {
                                    continue;
                                }
                                const SeamPiece &b = seamPieces[bi];
                                if ((b.format != a.format) || (b.shader != a.shader)) {
                                    continue;
                                }
                                if (alongT ? ((b.height != a.height) || (std::abs(pb.t - pa.t) > 0.1f)) : ((b.width != a.width) || (std::abs(pb.u - pa.u) > 0.1f))) {
                                    continue;
                                }
                                // Count each piece once for this point.
                                bool already = false;
                                for (uint32_t m = 0; m < matchedHereCount; m++) {
                                    already = already || (matchedHere[m] == bi);
                                }
                                if (already || (matchedHereCount == 8)) {
                                    continue;
                                }
                                matchedHere[matchedHereCount++] = bi;
                                uint32_t c = 0;
                                while ((c < candidateCount) && (candidates[c] != bi)) {
                                    c++;
                                }
                                if (c == candidateCount) {
                                    if (candidateCount == 8) {
                                        continue;
                                    }
                                    candidates[candidateCount] = bi;
                                    counts[candidateCount] = 0;
                                    candidateCount++;
                                }
                                counts[c]++;
                            }
                        }
                    }
                }
                // Of pieces alike at the same place, the nearest in draw order.
                uint32_t bestGap = 0xFFFFFFFFu;
                for (uint32_t c = 0; c < candidateCount; c++) {
                    const uint32_t bInstance = seamPieces[candidates[c]].instance;
                    const uint32_t gap = (bInstance > a.instance) ? (bInstance - a.instance) : (a.instance - bInstance);
                    if ((counts[c] >= 2) && ((counts[c] > bestCount) || ((counts[c] == bestCount) && (gap < bestGap)))) {
                        bestCount = counts[c];
                        bestGap = gap;
                        best = seamPieces[candidates[c]].tile | (a.world ? 0x80000000u : 0u);
                    }
                }
                return best;
            };
            for (uint32_t ai = 0; ai < seamPieces.size(); ai++) {
                interop::uint4 &n = instanceSeamVector[seamPieces[ai].instance];
                // Right (s high meets the other's s low), below (t on), left and above.
                n.x = find(ai, 2u, 1u);
                n.y = find(ai, 8u, 4u);
                n.z = find(ai, 1u, 2u);
                n.w = find(ai, 4u, 8u);
            }
            static const bool seamLog = (getenv("TOOIE_SEAM_LOG") != nullptr);
            if (seamLog) {
                static uint32_t seamLogFrames = 0;
                if ((seamLogFrames++ % 120) == 0) {
                    uint32_t joined = 0;
                    for (const SeamPiece &a : seamPieces) {
                        const interop::uint4 &n = instanceSeamVector[a.instance];
                        joined += (n.x != RASTER_SEAM_NONE) + (n.y != RASTER_SEAM_NONE) + (n.z != RASTER_SEAM_NONE) + (n.w != RASTER_SEAM_NONE);
                    }
                    fprintf(stdout, "[seam] %zu pieces, %u joined edges\n", seamPieces.size(), joined);
                    fflush(stdout);
                }
            }
        }
    }
}
