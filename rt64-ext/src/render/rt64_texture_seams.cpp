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
            // Each edge point by its cell, with its piece: a hash grid, one chain of points per bucket, built in one pass (a
            // hash multimap allocated a node per point every frame; a list sorted by cell then took the sort and a binary
            // search per lookup, still most of RT64's workload thread in the performance sweep, 2026-11-07). Points are
            // chained in reverse so each chain gives them in index order, the order the sorted list gave.
            thread_local std::vector<uint32_t> pointPiece;
            thread_local std::vector<uint64_t> pointCell;
            thread_local std::vector<uint32_t> pointNext;
            thread_local std::vector<uint32_t> bucketHead;
            constexpr uint32_t chainEnd = 0xFFFFFFFFu;
            pointPiece.assign(seamPoints.size(), 0);
            pointCell.assign(seamPoints.size(), 0);
            pointNext.assign(seamPoints.size(), chainEnd);
            uint32_t bucketBits = 4;
            while ((1u << bucketBits) < (seamPoints.size() * 2)) {
                bucketBits++;
            }
            bucketHead.assign(size_t(1) << bucketBits, chainEnd);
            auto bucketOf = [bucketBits](uint64_t cell) {
                return uint32_t((cell * 0x9E3779B97F4A7C15ull) >> (64 - bucketBits));
            };
            for (uint32_t i = 0; i < seamPieces.size(); i++) {
                for (uint32_t k = 0; k < seamPieces[i].pointCount; k++) {
                    const uint32_t pi = seamPieces[i].pointStart + k;
                    pointPiece[pi] = i;
                    pointCell[pi] = cellOf(seamPoints[pi].position.x, seamPoints[pi].position.y);
                }
            }
            {
                // Every point a piece covers, from the highest index down.
                thread_local std::vector<uint8_t> covered;
                covered.assign(seamPoints.size(), 0);
                for (const SeamPiece &piece : seamPieces) {
                    for (uint32_t k = 0; k < piece.pointCount; k++) {
                        covered[piece.pointStart + k] = 1;
                    }
                }
                for (uint32_t pi = uint32_t(seamPoints.size()); pi-- > 0; ) {
                    if (covered[pi]) {
                        uint32_t &head = bucketHead[bucketOf(pointCell[pi])];
                        pointNext[pi] = head;
                        head = pi;
                    }
                }
            }
            // Each piece's neighbour along each of its edges: the piece whose opposite edge meets it at two or more points.
            // One pass over the piece's points serves all four edges (it went over them once per edge, looking each point's
            // cells up four times: most of RT64's workload thread in the performance sweep, 2026-11-07).
            // Edges in the order of the result: right (s high meets the other's s low), below (t high), left and above.
            static constexpr uint32_t edgeBits[4] = { 2u, 8u, 1u, 4u };
            static constexpr uint32_t otherBits[4] = { 1u, 4u, 2u, 8u };
            for (uint32_t ai = 0; ai < seamPieces.size(); ai++) {
                const SeamPiece &a = seamPieces[ai];
                uint32_t candidates[4][8] = {};
                uint32_t counts[4][8] = {};
                uint32_t candidateCount[4] = {};
                for (uint32_t k = 0; k < a.pointCount; k++) {
                    const SeamPoint &pa = seamPoints[a.pointStart + k];
                    if ((pa.edges & 0xFu) == 0) {
                        continue;
                    }
                    // Only the cells a point within same()'s reach (2e-4 on x and y, with a margin) can be in, usually one (it was all nine around).
                    const int64_t x0 = int64_t(std::floor((pa.position.x - 2.5e-4f) * 2048.0f)), x1 = int64_t(std::floor((pa.position.x + 2.5e-4f) * 2048.0f));
                    const int64_t y0 = int64_t(std::floor((pa.position.y - 2.5e-4f) * 2048.0f)), y1 = int64_t(std::floor((pa.position.y + 2.5e-4f) * 2048.0f));
                    // Each piece is counted once per edge for this point.
                    uint32_t matchedHere[4][8] = {};
                    uint32_t matchedHereCount[4] = {};
                    for (int64_t cellX = x0; cellX <= x1; cellX++) {
                        for (int64_t cellY = y0; cellY <= y1; cellY++) {
                            const uint64_t cell = (uint64_t(uint32_t(int32_t(cellX))) << 32) | uint64_t(uint32_t(int32_t(cellY)));
                            for (uint32_t pbi = bucketHead[bucketOf(cell)]; pbi != chainEnd; pbi = pointNext[pbi]) {
                                if (pointCell[pbi] != cell) {
                                    continue;
                                }
                                const SeamPoint &pb = seamPoints[pbi];
                                const uint32_t bi = pointPiece[pbi];
                                if ((bi == ai) || !same(pa.position, pb.position)) {
                                    continue;
                                }
                                const SeamPiece &b = seamPieces[bi];
                                if ((b.format != a.format) || (b.shader != a.shader)) {
                                    continue;
                                }
                                for (uint32_t j = 0; j < 4; j++) {
                                    if (((pa.edges & edgeBits[j]) == 0) || ((pb.edges & otherBits[j]) == 0)) {
                                        continue;
                                    }
                                    const bool alongT = (edgeBits[j] & 3u) != 0;
                                    if (alongT ? ((b.height != a.height) || (std::abs(pb.t - pa.t) > 0.1f)) : ((b.width != a.width) || (std::abs(pb.u - pa.u) > 0.1f))) {
                                        continue;
                                    }
                                    bool already = false;
                                    for (uint32_t m = 0; m < matchedHereCount[j]; m++) {
                                        already = already || (matchedHere[j][m] == bi);
                                    }
                                    if (already || (matchedHereCount[j] == 8)) {
                                        continue;
                                    }
                                    matchedHere[j][matchedHereCount[j]++] = bi;
                                    uint32_t c = 0;
                                    while ((c < candidateCount[j]) && (candidates[j][c] != bi)) {
                                        c++;
                                    }
                                    if (c == candidateCount[j]) {
                                        if (candidateCount[j] == 8) {
                                            continue;
                                        }
                                        candidates[j][c] = bi;
                                        counts[j][c] = 0;
                                        candidateCount[j]++;
                                    }
                                    counts[j][c]++;
                                }
                            }
                        }
                    }
                }
                // Of pieces alike at the same place, the nearest in draw order.
                uint32_t best[4];
                for (uint32_t j = 0; j < 4; j++) {
                    best[j] = RASTER_SEAM_NONE;
                    uint32_t bestCount = 0, bestGap = 0xFFFFFFFFu;
                    for (uint32_t c = 0; c < candidateCount[j]; c++) {
                        const uint32_t bInstance = seamPieces[candidates[j][c]].instance;
                        const uint32_t gap = (bInstance > a.instance) ? (bInstance - a.instance) : (a.instance - bInstance);
                        if ((counts[j][c] >= 2) && ((counts[j][c] > bestCount) || ((counts[j][c] == bestCount) && (gap < bestGap)))) {
                            bestCount = counts[j][c];
                            bestGap = gap;
                            best[j] = seamPieces[candidates[j][c]].tile | (a.world ? 0x80000000u : 0u);
                        }
                    }
                }
                interop::uint4 &n = instanceSeamVector[a.instance];
                n.x = best[0];
                n.y = best[1];
                n.z = best[2];
                n.w = best[3];
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
