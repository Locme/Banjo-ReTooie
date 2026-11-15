//
// RT64
//

#include "rt64_grass.h"

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <condition_variable>
#include <cstring>
#include <deque>
#include <memory>
#include <mutex>
#include <thread>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>

// Banjo-Tooie: 3D grass on the CPU (rt64_grass.h). The plan and the research behind it: notes/cheap-grass-plan.md.
// The last 3D grass worked every blade out again each frame on the GPU and was too slow; here a draw's blades are
// worked out once and only the choice of what to draw is made each frame, over a few hundred tiles.
//
// The look follows the game's: few, broad blades in tufts that fan out from one root, each tuft one colour (the
// ground's under it), rather than a fine, realistic lawn.

namespace RT64 {
    namespace {
        std::mutex settingsMutex;
        GrassSettings settings;
        std::vector<uint64_t> grassTextures;
        std::vector<uint64_t> tallGrassTextures;
        // Seabed weed's textures (SetSceneWeedTextures), grown on as well as the grass textures under the sea.
        std::vector<uint64_t> weedTextures;
        // Changes whenever either list does (SceneGrassTextureLists).
        std::atomic<uint32_t> textureListsVersion{ 1 };

        // Tufts are laid one to a cell of a grid over the world (x and z), at the most the Density setting allows, so a
        // tuft's place depends only on where it is and stays put however the draws come and the camera moves.
        constexpr float BakeDensityMax = 2.0f;
        constexpr float CellSize = 26.0f / 1.41421356f;
        // The blades of a tuft, and how far from its centre their roots are.
        constexpr int TuftBlades = 4;
        constexpr float TuftRadius = 3.0f;
        // Tufts in a clump share a height and a lean: clumps are this wide.
        constexpr float ClumpSize = 60.0f;
        // Flowers grow in sections: a smooth, uneven noise about FlowerSectionSize across (times Bed Size) marks out
        // where they grow (FlowerSection), about a tenth of the ground at Flower Beds 100, and in a section up to this share of tufts carry one, fewest at
        // its edge and most in its middle, so it reads as a bed of flowers with a soft edge. Outside them only a lone
        // flower now and then. Each clump of a section is in the patch's colour, now and then the next one in the
        // palette (GrassBladeVS.hlsl has GrassFlowerColors), so a section is drifts of a few colours. Drawn as far as the
        // grass, thinning out with distance as the blades do. (Before, a sixth of all 60-unit clumps were patches,
        // scattered evenly over every lawn, which looked like flowers everywhere.)
        constexpr float FlowerSectionSize = 420.0f;
        // Where the noise starts being a bed for Flower Beds 0, 25, 50, 100, 150, 200, 250 and 300%: measured from the
        // noise's spread so that beds cover 0, about 2.75, 5.5, 11, 16.5, 22, 27.5 and 33% of the ground. A bed is full
        // this much above where it starts.
        constexpr float FlowerSectionFrom[8] = { 1.0f, 0.8f, 0.76f, 0.709f, 0.671f, 0.638f, 0.609f, 0.581f };
        constexpr float FlowerSectionEdge = 0.11f;
        constexpr float FlowerInSection = 0.22f;
        constexpr float FlowerElsewhere = 0.0015f;
        constexpr uint32_t FlowerColors = 6;
        // Flowers are baked at this many times the usual amount, and Flower Amount draws a share of them (each flower's
        // own random amount rank, GrassBladeVS.hlsl), so the slider applies at once.
        constexpr float FlowerAmountMax = 3.0f;
        // A third of flowers are big ones.
        constexpr float FlowerBig = 0.33f;
        // The kind number of a clover (after the six flower colours).
        constexpr uint32_t CloverKind = 7;
        // Meadow (Grass Type 3): this share of clumps are clover patches.
        constexpr float MeadowClover = 0.35f;
        // Wild grass (Grass Type 4): blades this much taller.
        constexpr float WildHeight = 1.5f;
        // Tiles of the world the blades are kept and picked in.
        constexpr float TileSize = 256.0f;
        // A ground triangle steeper than this (its normal's y) grows no blades; a wall (for tall grass) is one whose
        // normal's y is under WallSteep.
        constexpr float GroundFlat = 0.35f;
        constexpr float WallSteep = 0.4f;
        // How high a blade can reach over its root, for the tiles' boxes (blade heights are shares of the base height,
        // GrassBladeVS.hlsl, up to the Height setting's 2).
        constexpr float TileReach = 160.0f;
        // How far a blade can lean out across x and z (bent flat by Banjo, at the tallest Height).
        constexpr float TileLean = 64.0f;
        // Long grass along a lawn's side (BakeFoot): blades this far apart, on sides no higher than this (the same
        // texture on a cliff is left as it is), this many times the side's height and at least this many ground blades
        // high.
        constexpr float TallSpacing = 3.0f;
        constexpr float SideMaxRise = 90.0f;
        // How far a long grass side's triangles may lean back (their normal's y, as WallSteep), and the renderer's
        // grassAllWalls the same.
        constexpr float SideSteep = 0.7f;
        constexpr float LongRise = 1.4f;
        constexpr float LongLeast = 1.6f;
        // A blade's height is a share of this (world units; FrameParams.grassParams.w is it times the Height setting).
        constexpr float BaseHeight = 22.0f;
        // A cover (a road, path or floor that isn't grass) hides the grass under it from this far above the grass (a
        // decal: from this far below it, it lies on it) to this far above it (world units), and covers are found through
        // a grid of cells this wide.
        constexpr float CoverRaised = 0.5f;
        constexpr float CoverBelow = 3.0f;
        constexpr float CoverAbove = 12.0f;
        constexpr float CoverCell = 64.0f;
        // Thrown away and baked again when more than this many blades are kept (32 bytes each).
        constexpr size_t MaxBlades = 2500000;
        // Past this nothing more is baked until the next map's clear.
        constexpr size_t HardMaxBlades = 4000000;
        // The most blades a frame draws: past it every tile's share is scaled down together.
        constexpr uint32_t FrameBudget = 120000;
        // Where a tile is drawn as near blades (world units from the camera; past it, one triangle a blade).
        constexpr float NearReach = 1600.0f;
        // Every blade is drawn up to this far from the camera; past it the share kept falls with the square of the
        // distance, so blades stay about as far apart on screen however far off they are, and a whole level's grass is
        // a bounded number of blades. The last part of the Distance setting fades out to none.
        constexpr float FullReach = 1600.0f;
        constexpr float FadeShare = 0.15f;
        // GrassBladeVS.hlsl's GrassGrow: blades ranked up to this many times the share kept are drawn (growing in).
        constexpr float GrowShare = 1.8f;
        // A tall grass tile's share (over 1.5: kept whole wherever in reach, GrassBladeVS.hlsl).
        constexpr float TallShare = 2.0f;

        struct Tile {
            float low[3];
            float high[3];
            uint32_t first;
            uint32_t count;
            // Tall grass's own tiles: drawn whole wherever in reach (they are few, and stand out from far off).
            bool tall;
            // Flowers' own tiles: drawn in their own pass near the camera only, with Flowers on.
            bool flower;
            // A flower tile's clovers, which go first in it (its flowers after them, in the order of their amount ranks).
            uint32_t clovers = 0;
            // The corner its blades' places count from, and its height range (GrassTileDraw.origin).
            float origin[4] = {};
        };

        struct Baked {
            std::vector<Tile> tiles;
            // The box round all its tiles, to pass over the whole draw at once.
            float low[3];
            float high[3];
            // The frame (framesOpened) the game last drew it in.
            uint64_t drawnFrame = 0;
        };

        struct FrameTile {
            uint32_t blades;
            float keep;
        };

        struct QueuedDraw {
            uint64_t key;
            std::vector<GrassTriangle> triangles;
            bool ground;
            bool tall;
            bool useAlpha;
            // Drawn as a decal over other ground (moss and grass painted over a path or dirt): grows blades only where
            // no other ground lies under it.
            bool decal;
            // The draw's box in the world.
            float low[3];
            float high[3];
            // Grass Type, Flower Beds and Bed Size when it was queued.
            int type;
            float flowerBeds;
            float bedSize;
        };

        // A queued draw is baked once the camera comes within the Distance setting times this.
        constexpr float BakeReach = 1.3f;
        // More new draws than this in one frame is an area arriving (BakeQueued bakes all of it at once).
        constexpr size_t ArrivalDraws = 8;

        // Blades baked and not yet taken by the renderer (TakeBlades), which keeps every blade itself for the GPU;
        // they aren't kept here as well, a level's being tens of megabytes. And how many there are in all.
        std::vector<interop::GrassBlade> newBlades;
        size_t bladeCount = 0;
        std::vector<Baked> bakedDraws;
        std::unordered_map<uint64_t, int32_t> bakedByKey;
        std::vector<QueuedDraw> queued;
        std::unordered_set<uint64_t> queuedKeys;
        std::atomic<uint32_t> generation{ 1 };
        std::atomic<bool> rebakeAsked{ false };
        std::chrono::steady_clock::time_point lastClear{};

        float camera[3] = {};
        float planes[6][4] = {};
        GrassSettings frameSettings;

        std::vector<interop::GrassSlot> slots;
        std::vector<interop::GrassTileDraw> tiles;
        std::vector<FrameTile> frameTiles;
        // The frame budget's scale on every tile's share, eased from frame to frame.
        float budgetScale = 1.0f;

        // For the console.
        std::mutex statsMutex;
        uint64_t framesOpened = 0;
        // The grass's CPU time is timed one frame in TimedEvery (Timed): reading the clock twice for each of the
        // thousand or so draws a frame looks at cost about as much as the work it timed.
        constexpr uint64_t TimedEvery = 8;
        bool timedFrame = false;
        bool pipelineReady = false;
        bool cameraFound = false;
        uint32_t textureDraws[2] = {};
        uint32_t lastTextureDraws[2] = {};
        // (The bake's counters, its covers' tally and grownTufts belong to the bake thread (BakeWorker below), which
        // holds bakeMutex while it bakes; the console reads them under it.)
        std::mutex bakeMutex;
        size_t tallBlades = 0;
        size_t coveredTufts = 0;
        // For the console: how many tufts each cover texture has left out.
        std::unordered_map<uint64_t, uint32_t> coverTextures;
        double lastBakeMs = 0.0;
        // The bake thread's time on every draw baked since the grass was last thrown away (ms).
        double lastWorkerMs = 0.0;
        double frameMs = 0.0;
        uint32_t lastDrawn = 0;
        size_t lastSlots = 0;
        // Baked draws whose grass is in view but which the game left out of the last frame, and the nearest of them.
        size_t lastMissed = 0;
        float lastMissedNearest = 0.0f;
        size_t lastTiles = 0;
        // The frame's CPU time on grass: picking tiles, the budget, and the renderer's keys (NoteCpuTime).
        double frameCpuMs = 0.0;
        double frameCpuAverage = 0.0;
        // Of it, the time picking tiles (AddSlot) and the tiles looked at, this frame and the last (for the console).
        double framePickMs = 0.0;
        uint32_t frameTilesLooked = 0;
        double lastPickMs = 0.0;
        uint32_t lastTilesLooked = 0;
        // The renderer's own share (NoteCpuTime: its checks and keys on each draw it looks at) and how many draws.
        double frameDrawsMs = 0.0;
        uint32_t frameDrawsTimed = 0;
        double lastDrawsMs = 0.0;
        uint32_t lastDrawsTimed = 0;

        uint32_t Hash(uint32_t x) {
            x ^= x >> 16;
            x *= 0x7feb352dU;
            x ^= x >> 15;
            x *= 0x846ca68bU;
            x ^= x >> 16;
            return x;
        }

        uint32_t Hash2(int32_t a, int32_t b, uint32_t salt) {
            return Hash(uint32_t(a) * 0x9E3779B1U ^ Hash(uint32_t(b) + salt * 0x85EBCA77U));
        }

        float Unit(uint32_t h) {
            return float(h >> 8) * (1.0f / 16777216.0f);
        }

        float Fract(float x) {
            return x - std::floor(x);
        }

        // Smooth value noise over a grid of this size: 0 to 1, the same at a place whatever bakes it.
        float ValueNoise(float x, float z, float size, uint32_t salt) {
            const float gx = x / size, gz = z / size;
            const int32_t ix = int32_t(std::floor(gx)), iz = int32_t(std::floor(gz));
            const float fx = gx - float(ix), fz = gz - float(iz);
            const float sx = fx * fx * (3.0f - 2.0f * fx), sz = fz * fz * (3.0f - 2.0f * fz);
            const float n00 = Unit(Hash2(ix, iz, salt)), n10 = Unit(Hash2(ix + 1, iz, salt));
            const float n01 = Unit(Hash2(ix, iz + 1, salt)), n11 = Unit(Hash2(ix + 1, iz + 1, salt));
            return (n00 + (n10 - n00) * sx) + ((n01 + (n11 - n01) * sx) - (n00 + (n10 - n00) * sx)) * sz;
        }

        // How far into a flower section a place is: 0 outside, rising to 1 in its middle. Two layers of noise, the
        // second half the size, so the sections are uneven blobs rather than the grid's squares. (beds: Flower Beds,
        // 0 to 3; size: Bed Size, times FlowerSectionSize.)
        float FlowerSection(float x, float z, float beds, float size) {
            if (beds <= 0.0f) {
                return 0.0f;
            }
            const float sectionSize = FlowerSectionSize * size;
            const float n = 0.7f * ValueNoise(x, z, sectionSize, 41) + 0.3f * ValueNoise(x, z, sectionSize * 0.5f, 43);
            // (FlowerSectionFrom's steps: 0, 0.25 and 0.5, then every 0.5 up to 3.)
            const float step = (beds < 0.5f) ? (beds * 4.0f) : (1.0f + beds * 2.0f);
            const int i = std::clamp(int(step), 0, 6);
            const float from = FlowerSectionFrom[i] + (FlowerSectionFrom[i + 1] - FlowerSectionFrom[i]) * std::clamp(step - float(i), 0.0f, 1.0f);
            return std::clamp((n - from) / FlowerSectionEdge, 0.0f, 1.0f);
        }

        // Where tufts already grow: each tuft's spot is a world grid cell (BakeGround), so two ground draws lying on
        // each other (a grass layer the game blends over a hill, or the same ground drawn twice) would grow the very
        // same blades in the very same places, each coloured by its own draw, and the two would fight over the pixels
        // and flicker. The first draw baked keeps a cell; another draw's tuft within a few units of the same height
        // in it is left out. Keyed by the cell and its size; the height and the draw (its key) that grew it.
        struct GrownTuft {
            float y;
            uint64_t draw;
        };
        std::unordered_map<uint64_t, GrownTuft> grownTufts;
        size_t doubledTufts = 0;
        // Draws whose grass was already drawn this frame (the same ground drawn again): left out the second time.
        uint32_t doubledDraws = 0;
        uint32_t lastDoubledDraws = 0;

        // Throws every baked blade away. The bake thread drops its waiting draws, throws its results of the old
        // generation away, and clears its own state (grownTufts and the counters) when it starts on the new one.
        void ClearWorker();
        void Clear() {
            std::vector<interop::GrassBlade>().swap(newBlades);
            bladeCount = 0;
            bakedDraws.clear();
            bakedByKey.clear();
            queued.clear();
            queuedKeys.clear();
            generation++;
            lastWorkerMs = 0.0;
            ClearWorker();
        }

        // A blade being baked, before it is packed into its 16 bytes (interop::GrassBlade) once its tile is known.
        struct LooseBlade {
            float root[3];
            float height;
            uint32_t triangle;
            float u, v, turn, lean, width;
        };

        // The blades of one tile of a draw being baked, each with the rank of its tuft (a tuft thins out as one).
        struct Pending {
            bool tall = false;
            bool flower = false;
            std::vector<std::pair<float, LooseBlade>> ranked;
            float low[3] = { 1e30f, 1e30f, 1e30f };
            float high[3] = { -1e30f, -1e30f, -1e30f };
        };

        using PendingTiles = std::unordered_map<uint64_t, Pending>;

        // A draw's bake in three steps, so draws can be baked on several threads at once and come out the same as one
        // at a time (BakeBatch): first each draw's tufts and blades are worked out (Collect, any number at once, into a
        // BakeSink each); then, one draw after another in the order sent, each tuft is checked against those already
        // grown (Dedupe, grownTufts: the first draw baked keeps a spot); then each draw's tiles are built from the
        // blades kept (Finish, any number at once).
        struct AddedBlade {
            LooseBlade blade;
            float rank;
            bool tall;
            bool flower;
            // Its tuft in the sink (-1: a long grass blade, which is always kept).
            int32_t tuft;
        };

        struct TuftMark {
            uint64_t spot;
            float y;
        };

        struct BakeSink {
            std::vector<AddedBlade> blades;
            std::vector<TuftMark> tufts;
            int32_t tuft = -1;
            // The slope of the ground the next blades stand on, in their GrassBlade.info.x bits (rt64_grass_blades.h):
            // set by BakeGround for each triangle, none for the long grass along a lawn's side.
            uint32_t slope = 0;
            size_t covered = 0;
            size_t tall = 0;
            // How many tufts each cover texture left out (for the console).
            std::unordered_map<uint64_t, uint32_t> coverTally;
        };

        // The sink Covers::Covered tallies its covers in (each bake thread its own).
        thread_local BakeSink *tallySink = nullptr;

        void Add(BakeSink &sink, uint32_t triangle, const float root[3], float u, float v, float height, float turn, float lean,
            float width, float rank, bool tall = false, bool flower = false)
        {
            sink.blades.push_back({ { { root[0], root[1], root[2] }, height, triangle | sink.slope, u, v, Fract(turn), lean, width }, rank, tall, flower, sink.tuft });
        }

        // The tile the last blade went to (AddPending): the next nearly always goes to the same one. Reset for each draw
        // (Finish), its tiles being new. (An unordered_map's elements stay where they are as it grows.)
        thread_local uint64_t lastPendingKey = 0;
        thread_local Pending *lastPending = nullptr;

        void AddPending(PendingTiles &pending, const AddedBlade &added) {
            const float *root = added.blade.root;
            const bool tall = added.tall;
            const bool flower = added.flower;
            const float rank = added.rank;
            const int32_t tx = int32_t(std::floor(root[0] / TileSize));
            const int32_t tz = int32_t(std::floor(root[2] / TileSize));
            const uint64_t key = ((uint64_t(uint32_t(tx)) << 32) | uint32_t(tz)) ^ (tall ? 0x8000000000000000ULL : 0ULL) ^ (flower ? 0x4000000000000000ULL : 0ULL);
            if ((lastPending == nullptr) || (key != lastPendingKey)) {
                lastPending = &pending[key];
                lastPendingKey = key;
            }
            Pending &p = *lastPending;
            p.tall = tall;
            p.flower = flower;
            p.ranked.emplace_back(rank, added.blade);
            for (int k = 0; k < 3; k++) {
                p.low[k] = std::min(p.low[k], root[k]);
                p.high[k] = std::max(p.high[k], root[k]);
            }
        }

        // The frame's covers (rt64_grass.h's BakeQueued), found by the cells of a grid over x and z.
        struct Covers {
            const std::vector<GrassTriangle> *triangles = nullptr;
            std::unordered_map<uint64_t, std::vector<uint32_t>> cells;

            static uint64_t Cell(int32_t x, int32_t z) {
                return (uint64_t(uint32_t(x)) << 32) | uint32_t(z);
            }

            void Build(const std::vector<GrassTriangle> &list) {
                triangles = &list;
                cells.clear();
                for (uint32_t i = 0; i < list.size(); i++) {
                    const GrassTriangle &t = list[i];
                    const float minX = std::min(t.p[0][0], std::min(t.p[1][0], t.p[2][0])), maxX = std::max(t.p[0][0], std::max(t.p[1][0], t.p[2][0]));
                    const float minZ = std::min(t.p[0][2], std::min(t.p[1][2], t.p[2][2])), maxZ = std::max(t.p[0][2], std::max(t.p[1][2], t.p[2][2]));
                    const int32_t x0 = int32_t(std::floor(minX / CoverCell)), x1 = int32_t(std::floor(maxX / CoverCell));
                    const int32_t z0 = int32_t(std::floor(minZ / CoverCell)), z1 = int32_t(std::floor(maxZ / CoverCell));
                    // (A huge triangle would fill the grid: those are left out, a cover is a road or a path's piece.)
                    if ((int64_t(x1 - x0 + 1) * int64_t(z1 - z0 + 1)) > 4096) {
                        continue;
                    }
                    for (int32_t z = z0; z <= z1; z++) {
                        for (int32_t x = x0; x <= x1; x++) {
                            cells[Cell(x, z)].push_back(i);
                        }
                    }
                }
            }

            // Whether any cover could lie within reach of a point across x and z: whether any grid cell the square round
            // it touches holds one. Most tufts are nowhere near a road or path, and this spares them the ring of
            // checks EdgeHeight makes.
            bool AnyNear(float x, float z, float reach) const {
                if ((triangles == nullptr) || cells.empty()) {
                    return false;
                }
                const int32_t x0 = int32_t(std::floor((x - reach) / CoverCell)), x1 = int32_t(std::floor((x + reach) / CoverCell));
                const int32_t z0 = int32_t(std::floor((z - reach) / CoverCell)), z1 = int32_t(std::floor((z + reach) / CoverCell));
                for (int32_t cz = z0; cz <= z1; cz++) {
                    for (int32_t cx = x0; cx <= x1; cx++) {
                        if (cells.count(Cell(cx, cz)) != 0) {
                            return true;
                        }
                    }
                }
                return false;
            }

            // Whether a cover lies on the grass at a point (from a little below it to a little above). With level, ground
            // level with the grass counts too (a path beside it, or under a grass decal).
            bool Covered(float x, float y, float z, bool level = false) const {
                if ((triangles == nullptr) || cells.empty()) {
                    return false;
                }
                auto found = cells.find(Cell(int32_t(std::floor(x / CoverCell)), int32_t(std::floor(z / CoverCell))));
                if (found == cells.end()) {
                    return false;
                }
                for (uint32_t i : found->second) {
                    const GrassTriangle &t = (*triangles)[i];
                    const float *a = t.p[0], *b = t.p[1], *c = t.p[2];
                    const float d = (b[2] - c[2]) * (a[0] - c[0]) + (c[0] - b[0]) * (a[2] - c[2]);
                    if (std::abs(d) < 1e-6f) {
                        continue;
                    }
                    const float u = ((b[2] - c[2]) * (x - c[0]) + (c[0] - b[0]) * (z - c[2])) / d;
                    const float v = ((c[2] - a[2]) * (x - c[0]) + (a[0] - c[0]) * (z - c[2])) / d;
                    const float w = 1.0f - u - v;
                    if ((u < 0.0f) || (v < 0.0f) || (w < 0.0f)) {
                        continue;
                    }
                    const float coverY = u * a[1] + v * b[1] + w * c[1];
                    if ((coverY > y + ((t.decal || level) ? -CoverBelow : CoverRaised)) && (coverY < y + CoverAbove)) {
                        if (!level && (tallySink != nullptr)) {
                            tallySink->coverTally[t.texture]++;
                        }
                        return true;
                    }
                }
                return false;
            }
        };

        // Tufts on a ground triangle: a cell's tuft grows where its centre falls inside the triangle seen from above, isn't
        // faded out and has no cover over it. Its blades stand round the centre and fan outwards, all with the colour of
        // the ground at the centre.
        // How much shorter a tuft is by a road or path (any cover, level with the grass too): much shorter within the first
        // ring, less within the second and a little within the third, so the grass thins and shortens towards the path's
        // edge instead of standing over it (BakeGround also gives a tuft there fewer, thinner blades; L 2026-11-13).
        constexpr float EdgeNear = 9.0f;
        constexpr float EdgeMid = 19.0f;
        constexpr float EdgeFar = 34.0f;
        float EdgeHeight(const Covers &covers, float x, float y, float z) {
            // (No cover near at all: nothing to look at. A little past the far ring, to be sure of every point on it.)
            if (!covers.AnyNear(x, z, EdgeFar + 1.0f)) {
                return 1.0f;
            }
            // The rings' points round the tuft, worked out once (the same values as working them out each time).
            static const std::array<std::array<float, 2>, 24> ringPoints = []() {
                std::array<std::array<float, 2>, 24> points;
                for (int ring = 0; ring < 3; ring++) {
                    const float radius = (ring == 0) ? EdgeNear : ((ring == 1) ? EdgeMid : EdgeFar);
                    for (int k = 0; k < 8; k++) {
                        const float angle = float(k) * (6.2831853f / 8.0f) + float(ring) * 0.39f;
                        points[ring * 8 + k] = { std::cos(angle) * radius, std::sin(angle) * radius };
                    }
                }
                return points;
            }();
            for (int ring = 0; ring < 3; ring++) {
                for (int k = 0; k < 8; k++) {
                    const std::array<float, 2> &point = ringPoints[ring * 8 + k];
                    if (covers.Covered(x + point[0], y, z + point[1], true)) {
                        return (ring == 0) ? 0.3f : ((ring == 1) ? 0.55f : 0.8f);
                    }
                }
            }
            return 1.0f;
        }

        void BakeGround(BakeSink &sink, uint32_t index, const GrassTriangle &t, bool useAlpha, bool decal, int type, float beds, float bedSize, const Covers &covers) {
            const float *a = t.p[0], *b = t.p[1], *c = t.p[2];
            const float e1[3] = { b[0] - a[0], b[1] - a[1], b[2] - a[2] };
            const float e2[3] = { c[0] - a[0], c[1] - a[1], c[2] - a[2] };
            const float n[3] = { e1[1] * e2[2] - e1[2] * e2[1], e1[2] * e2[0] - e1[0] * e2[2], e1[0] * e2[1] - e1[1] * e2[0] };
            const float length = std::sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
            if ((length < 1e-3f) || (std::abs(n[1]) / length < GroundFlat)) {
                return;
            }
            {
                // The way up the slope and how steep it is, for the shader to keep a bent blade's tip above the ground.
                const float flip = (n[1] < 0.0f) ? -1.0f : 1.0f;
                const float across = std::sqrt(n[0] * n[0] + n[2] * n[2]);
                const float steep = across / std::max(std::abs(n[1]), 1e-3f);
                const uint32_t way = uint32_t(std::lround(std::atan2(-n[2] * flip, -n[0] * flip) * (16.0f / 6.2831853f))) & 15u;
                sink.slope = (way << 20) | (uint32_t(std::min(std::lround(steep * 4.0f), 15l)) << 28);
            }

            // Barycentric weights from x and z.
            const float d = (b[2] - c[2]) * (a[0] - c[0]) + (c[0] - b[0]) * (a[2] - c[2]);
            if (std::abs(d) < 1e-6f) {
                return;
            }
            auto weights = [&](float x, float z, float &u, float &v) {
                u = ((b[2] - c[2]) * (x - c[0]) + (c[0] - b[0]) * (z - c[2])) / d;
                v = ((c[2] - a[2]) * (x - c[0]) + (a[0] - c[0]) * (z - c[2])) / d;
            };

            const float minX = std::min(a[0], std::min(b[0], c[0])), maxX = std::max(a[0], std::max(b[0], c[0]));
            const float minZ = std::min(a[2], std::min(b[2], c[2])), maxZ = std::max(a[2], std::max(b[2], c[2]));
            // (The grid is laid from above, so a slope gets fewer tufts for its area: its cells are made smaller by the
            // slope, so it is as full as flat ground.)
            const float cell = CellSize * std::sqrt(std::abs(n[1]) / length);
            const int32_t x0 = int32_t(std::floor(minX / cell)), x1 = int32_t(std::floor(maxX / cell));
            const int32_t z0 = int32_t(std::floor(minZ / cell)), z1 = int32_t(std::floor(maxZ / cell));
            for (int32_t iz = z0; iz <= z1; iz++) {
                for (int32_t ix = x0; ix <= x1; ix++) {
                    const uint32_t h = Hash2(ix, iz, 3);
                    const float x = (float(ix) + 0.15f + 0.7f * Unit(h)) * cell;
                    const float z = (float(iz) + 0.15f + 0.7f * Unit(Hash(h + 1))) * cell;
                    float u, v;
                    weights(x, z, u, v);
                    const float w = 1.0f - u - v;
                    if ((u < 0.0f) || (v < 0.0f) || (w < 0.0f)) {
                        continue;
                    }

                    // A grass layer the game fades out by its vertices' alpha (Spiral Mountain's cobbled road) grows none
                    // where it has faded.
                    if (useAlpha && ((u * t.alpha[0] + v * t.alpha[1] + w * t.alpha[2]) < 0.5f)) {
                        continue;
                    }

                    const float y = u * a[1] + v * b[1] + w * c[1];
                    if (covers.Covered(x, y, z, decal)) {
                        sink.covered++;
                        continue;
                    }
                    // (Whether another draw already grew this spot is checked after, in order: Dedupe.)
                    sink.tufts.push_back({ (uint64_t(uint32_t(ix)) << 40) ^ (uint64_t(uint32_t(iz)) << 16) ^ uint64_t(uint32_t(cell * 64.0f) & 0xFFFFu), y });
                    sink.tuft = int32_t(sink.tufts.size() - 1);
                    const float edge = EdgeHeight(covers, x, y, z);

                    // The tuft's clump: its height and lean, shared with its neighbours.
                    const int32_t cx = int32_t(std::floor(x / ClumpSize));
                    const int32_t cz = int32_t(std::floor(z / ClumpSize));
                    const float clumpHeight = 0.75f + 0.5f * Unit(Hash2(cx, cz, 7));
                    const float clumpLean = Unit(Hash2(cx, cz, 13));
                    const float rank = Unit(Hash(h + 2));
                    const float spin = Unit(Hash(h + 3));
                    // A flower at the tuft's centre, in patches (not by a path's edge, where the grass is trimmed). Baked at
                    // FlowerAmountMax times the usual amount, each with its own amount rank (Flower Amount draws those under
                    // it) and a third of them big.
                    uint32_t flower = 0;
                    // (Test aid: TOOIE_GRASS_FLOWER_TEST=1 puts a flower on a third of all tufts, to look at them up close.)
                    static const bool flowerTest = (std::getenv("TOOIE_GRASS_FLOWER_TEST") != nullptr);
                    const float section = FlowerSection(x, z, beds, bedSize);
                    const float flowerChance = flowerTest ? 0.33f : (std::max(FlowerInSection * section * (2.0f - section), FlowerElsewhere) * FlowerAmountMax);
                    const float flowerRoll = Unit(Hash(h + 5));
                    if ((edge >= 1.0f) && (flowerRoll < flowerChance)) {
                        const uint32_t patchColor = Hash2(cx, cz, 31) % FlowerColors;
                        const uint32_t color = (Unit(Hash(h + 6)) < 0.25f) ? ((patchColor + 1) % FlowerColors) : patchColor;
                        flower = (color + 1) << 24;
                    }
                    // Clover (Grass Type 2 everywhere, with no blades; 3 in patches, with one): clovers round the centre.
                    const bool clover = (type == 2) || ((type == 3) && (Unit(Hash2(cx, cz, 37)) < MeadowClover));
                    // (By a path's edge fewer blades: two right by it, three a little further.)
                    const int edgeBlades = (edge < 0.4f) ? 2 : ((edge < 0.6f) ? 3 : TuftBlades);
                    const int tuftBlades = clover ? ((type == 2) ? 0 : 1) : edgeBlades;
                    const float typeHeight = (type == 4) ? WildHeight : 1.0f;
                    for (int k = 0; k < tuftBlades; k++) {
                        const uint32_t own = Hash(h + 16 + uint32_t(k));
                        // Round the centre, a quarter turn apart and a little uneven, each facing out from it.
                        const float turn = spin + (float(k) + 0.6f * (Unit(own) - 0.5f)) / float(TuftBlades);
                        const float angle = turn * 6.2831853f;
                        const float out = TuftRadius * (0.5f + 0.5f * Unit(Hash(own + 1)));
                        const float bx = x + std::cos(angle) * out;
                        const float bz = z + std::sin(angle) * out;
                        float bu, bv;
                        weights(bx, bz, bu, bv);
                        const float root[3] = { bx, bu * a[1] + bv * b[1] + (1.0f - bu - bv) * c[1], bz };
                        const float height = edge * typeHeight * clumpHeight * (0.8f + 0.4f * Unit(Hash(own + 2)));
                        // (Thinner and a little more bent over the nearer the path's edge.)
                        const float lean = std::min(0.45f + 0.35f * clumpLean + 0.2f * Unit(Hash(own + 3)) + 0.35f * (1.0f - edge), 1.0f);
                        Add(sink, index, root, u, v, height, turn, lean, Unit(Hash(own + 4)) * (0.45f + 0.55f * edge), rank);
                    }
                    if (flower != 0) {
                        const float centre[3] = { x, y, z };
                        const float big = (Unit(Hash(h + 8)) < FlowerBig) ? 1.0f : 0.0f;
                        Add(sink, index | flower, centre, u, v, clumpHeight, spin, big, flowerRoll / flowerChance, rank, false, true);
                    }
                    if (clover) {
                        for (int k = 0; k < 4; k++) {
                            const uint32_t own = Hash(h + 40 + uint32_t(k));
                            const float angle = (spin + float(k) / 4.0f + 0.2f * Unit(own)) * 6.2831853f;
                            const float out = 1.5f + 5.0f * Unit(Hash(own + 1));
                            const float cxp = x + std::cos(angle) * out;
                            const float czp = z + std::sin(angle) * out;
                            float cu, cv;
                            weights(cxp, czp, cu, cv);
                            const float spot[3] = { cxp, cu * a[1] + cv * b[1] + (1.0f - cu - cv) * c[1], czp };
                            Add(sink, index | (CloverKind << 24), spot, u, v, clumpHeight * (0.8f + 0.4f * Unit(Hash(own + 2))), Unit(Hash(own + 3)),
                                Unit(Hash(own + 4)), 0.0f, rank, false, true);
                        }
                    }
                }
            }
        }

        // Long grass along a lawn's side (Replace Long Grass): blades along the bottom edge of the side, standing out a
        // little in front of it and somewhat taller than the side (Long Grass Height scales them as they are drawn). The
        // bottom edges are found from the draw's shape: the edges of its wall triangles that no other wall triangle
        // shares, with their triangle above them; so a side whose foot runs down a slope gets its blades all along it.
        // Each blade takes the side's colour most of the way up, where its painted blades are green.
        void BakeFoot(BakeSink &sink, const std::vector<GrassTriangle> &triangles) {
            sink.tuft = -1;
            sink.slope = 0;
            // (Only a low side: a tall, narrow draw with the same texture is something else, a climbing vine, and keeps its
            // look. A side running up a slope beside a path is low all along it though it climbs: no triangle of it is
            // tall, and it is at least twice as long as it climbs; the renderer's grassAllWalls judges the same.)
            float low = 1e30f, high = -1e30f, tallest = 0.0f;
            float across[4] = { 1e30f, -1e30f, 1e30f, -1e30f };
            for (const GrassTriangle &t : triangles) {
                float triangleLow = 1e30f, triangleHigh = -1e30f;
                for (int c = 0; c < 3; c++) {
                    low = std::min(low, t.p[c][1]);
                    high = std::max(high, t.p[c][1]);
                    triangleLow = std::min(triangleLow, t.p[c][1]);
                    triangleHigh = std::max(triangleHigh, t.p[c][1]);
                    across[0] = std::min(across[0], t.p[c][0]);
                    across[1] = std::max(across[1], t.p[c][0]);
                    across[2] = std::min(across[2], t.p[c][2]);
                    across[3] = std::max(across[3], t.p[c][2]);
                }
                tallest = std::max(tallest, triangleHigh - triangleLow);
            }
            const float length = std::sqrt((across[1] - across[0]) * (across[1] - across[0]) + (across[3] - across[2]) * (across[3] - across[2]));
            const bool climbs = (tallest <= SideMaxRise * 1.7f) && ((high - low) * 2.0f <= length);
            if (((high - low) > SideMaxRise * 1.7f) && !climbs) {
                return;
            }

            struct EdgeUse {
                uint32_t triangle;
                int a;
                int b;
                int count;
            };
            auto corner = [](const float p[3]) {
                return std::array<int32_t, 3>{ int32_t(std::lround(p[0] * 4.0f)), int32_t(std::lround(p[1] * 4.0f)), int32_t(std::lround(p[2] * 4.0f)) };
            };
            std::map<std::pair<std::array<int32_t, 3>, std::array<int32_t, 3>>, EdgeUse> edges;
            std::vector<std::array<float, 3>> normals(triangles.size());
            for (uint32_t i = 0; i < triangles.size(); i++) {
                const GrassTriangle &t = triangles[i];
                const float e1[3] = { t.p[1][0] - t.p[0][0], t.p[1][1] - t.p[0][1], t.p[1][2] - t.p[0][2] };
                const float e2[3] = { t.p[2][0] - t.p[0][0], t.p[2][1] - t.p[0][1], t.p[2][2] - t.p[0][2] };
                float n[3] = { e1[1] * e2[2] - e1[2] * e2[1], e1[2] * e2[0] - e1[0] * e2[2], e1[0] * e2[1] - e1[1] * e2[0] };
                const float length = std::sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
                // (A side may lean back a little more than a wall elsewhere: the banks beside Wooded Hollow's paths do.)
                if ((length < 1e-3f) || (std::abs(n[1]) / length > SideSteep)) {
                    continue;
                }
                normals[i] = { n[0] / length, n[1] / length, n[2] / length };
                for (int e = 0; e < 3; e++) {
                    const int ea = e, eb = (e + 1) % 3;
                    auto ka = corner(t.p[ea]), kb = corner(t.p[eb]);
                    const auto key = (ka < kb) ? std::make_pair(ka, kb) : std::make_pair(kb, ka);
                    auto found = edges.find(key);
                    if (found == edges.end()) {
                        edges[key] = { i, ea, eb, 1 };
                    }
                    else {
                        found->second.count++;
                    }
                }
            }

            for (const auto &entry : edges) {
                const EdgeUse &use = entry.second;
                if (use.count != 1) {
                    continue;
                }
                const GrassTriangle &t = triangles[use.triangle];
                const int third = 3 - use.a - use.b;
                const float *pa = t.p[use.a], *pb = t.p[use.b], *pc = t.p[third];
                const float dx = pb[0] - pa[0], dz = pb[2] - pa[2];
                const float span = std::sqrt(dx * dx + dz * dz);
                // Running along the ground (sloped, not steep), with its triangle standing above it.
                if ((span < 1.0f) || (std::abs(pb[1] - pa[1]) > 0.8f * span)) {
                    continue;
                }
                const float along = std::clamp(((pc[0] - pa[0]) * dx + (pc[2] - pa[2]) * dz) / (span * span), 0.0f, 1.0f);
                const float rise = pc[1] - (pa[1] + (pb[1] - pa[1]) * along);
                if ((rise < 4.0f) || (rise > SideMaxRise * 1.7f)) {
                    continue;
                }

                const float *n = normals[use.triangle].data();
                const float facing = Fract(std::atan2(n[2], n[0]) / 6.2831853f);
                // (No taller than a side SideMaxRise high would give: a taller piece of a bank grows the same grass.)
                const float height = std::max(std::min(rise, SideMaxRise) * LongRise, BaseHeight * LongLeast) / BaseHeight;
                const float along0 = (pa[0] * dx + pa[2] * dz) / span;
                const int32_t s0 = int32_t(std::floor(along0 / TallSpacing));
                const int32_t s1 = int32_t(std::floor((along0 + span) / TallSpacing));
                const uint32_t wallSalt = uint32_t(int32_t(std::floor(n[0] * 8.0f + 9.0f)) * 17 + int32_t(std::floor(n[2] * 8.0f + 9.0f)));
                for (int32_t step = s0; step <= s1; step++) {
                    const uint32_t h = Hash2(step, int32_t(std::floor(pa[1])), wallSalt);
                    const float at = ((float(step) + Unit(h)) * TallSpacing - along0) / span;
                    if ((at < 0.0f) || (at > 1.0f)) {
                        continue;
                    }
                    // Two rows, the back one against the side and taller, the front one further out and shorter, each
                    // blade turned its own way (up to about 60 degrees off the side's), so the long grass reads as a
                    // bank of grass and not a flat fence.
                    float w[3] = {};
                    w[use.a] = (1.0f - at) * 0.15f;
                    w[use.b] = at * 0.15f;
                    w[third] = 0.85f;
                    for (int row = 0; row < 2; row++) {
                        const uint32_t own = Hash(h + 11 * uint32_t(row));
                        const float shift = (row == 0) ? 0.0f : (0.5f * TallSpacing / span);
                        const float rowAt = std::clamp(at + shift, 0.0f, 1.0f);
                        const float out = (row == 0) ? (1.0f + 3.0f * Unit(Hash(own + 1))) : (5.0f + 5.0f * Unit(Hash(own + 1)));
                        const float root[3] = { pa[0] + dx * rowAt + n[0] * out, pa[1] + (pb[1] - pa[1]) * rowAt, pa[2] + dz * rowAt + n[2] * out };
                        const float turn = facing + (Unit(Hash(own + 3)) - 0.5f) * 2.1f / 6.2831853f * 3.0f;
                        const float rowHeight = (row == 0) ? (0.8f + 0.45f * Unit(Hash(own + 2))) : (0.5f + 0.35f * Unit(Hash(own + 2)));
                        Add(sink, use.triangle, root, w[0], w[1], height * rowHeight, turn, 0.35f + 0.45f * Unit(Hash(own + 5)),
                            Unit(Hash(own + 6)), Unit(Hash(own + 4)), true);
                        sink.tall++;
                    }
                }
            }
        }

        // Whether a queued draw is near enough to bake (its box's nearest point within reach of the camera).
        bool Near(const QueuedDraw &draw) {
            float d2 = 0.0f;
            for (int k = 0; k < 3; k++) {
                const float c = std::clamp(camera[k], draw.low[k], draw.high[k]) - camera[k];
                d2 += c * c;
            }
            const float reach = frameSettings.distance * BakeReach;
            return d2 < reach * reach;
        }

        // Whether a queued draw is close enough to the camera that its grass would be seen growing in (within 4000).
        bool NearNow(const QueuedDraw &draw) {
            float d2 = 0.0f;
            for (int k = 0; k < 3; k++) {
                const float c = std::clamp(camera[k], draw.low[k], draw.high[k]) - camera[k];
                d2 += c * c;
            }
            return d2 < 4000.0f * 4000.0f;
        }

        // A draw's tufts and blades, before any is checked against other draws'.
        void Collect(const QueuedDraw &draw, const Covers &covers, BakeSink &sink) {
            tallySink = &sink;
            // (A blade keeps its triangle in 20 bits: rt64_grass_blades.h.)
            if (draw.triangles.size() >= (1u << 20)) {
                return;
            }
            for (uint32_t i = 0; i < draw.triangles.size(); i++) {
                if (draw.ground) {
                    BakeGround(sink, i, draw.triangles[i], draw.useAlpha, draw.decal, draw.type, draw.flowerBeds, draw.bedSize, covers);
                }
            }
            if (draw.tall) {
                BakeFoot(sink, draw.triangles);
            }
            tallySink = nullptr;
        }

        // Which of a draw's tufts are kept: a spot no draw has grown yet is this draw's; one another draw grew at about
        // the same height is left out. (With bakeMutex held, draws in the order sent.)
        void Dedupe(uint64_t key, const BakeSink &sink, std::vector<uint8_t> &keep) {
            keep.assign(sink.tufts.size(), 1);
            for (size_t k = 0; k < sink.tufts.size(); k++) {
                const TuftMark &mark = sink.tufts[k];
                const auto found = grownTufts.find(mark.spot);
                if (found == grownTufts.end()) {
                    grownTufts.emplace(mark.spot, GrownTuft{ mark.y, key });
                }
                else if ((found->second.draw != key) && (std::abs(found->second.y - mark.y) < 12.0f)) {
                    doubledTufts++;
                    keep[k] = 0;
                }
            }
            coveredTufts += sink.covered;
            tallBlades += sink.tall;
            for (const auto &entry : sink.coverTally) {
                coverTextures[entry.first] += entry.second;
            }
        }

        // Builds a draw's tiles from its blades kept into out (its tiles' first blades counted from out's start) and
        // baked; false when it grows none.
        bool Finish(const BakeSink &sink, const std::vector<uint8_t> &keep, std::vector<interop::GrassBlade> &out, Baked &baked) {
            PendingTiles pending;
            lastPending = nullptr;
            for (const AddedBlade &added : sink.blades) {
                if ((added.tuft < 0) || (keep[size_t(added.tuft)] != 0)) {
                    AddPending(pending, added);
                }
            }

            if (pending.empty()) {
                return false;
            }

            for (int k = 0; k < 3; k++) {
                baked.low[k] = 1e30f;
                baked.high[k] = -1e30f;
            }
            for (auto &entry : pending) {
                Pending &p = entry.second;
                // A tile's blades in the order of their tufts' ranks (a tuft's blades together), and each blade's rank then
                // its place in that order, so the first part of a tile is an even spread of whole tufts.
                std::stable_sort(p.ranked.begin(), p.ranked.end(), [](const auto &x, const auto &y) { return x.first < y.first; });
                // A flower tile instead has its clovers first, then its flowers in the order of their own amount ranks
                // (their width share), so a frame draws only the flowers Flower Amount shows (AddSlot) instead of all
                // FlowerAmountMax times as many, each of 27 corners, and leaving the rest out corner by corner.
                uint32_t clovers = 0;
                if (p.flower) {
                    auto amountRank = [](const LooseBlade &b) {
                        return (((b.triangle >> 24) & 0xFu) == CloverKind) ? -1.0f : b.width;
                    };
                    std::stable_sort(p.ranked.begin(), p.ranked.end(), [&amountRank](const auto &x, const auto &y) { return amountRank(x.second) < amountRank(y.second); });
                    for (const auto &entry : p.ranked) {
                        clovers += (amountRank(entry.second) < 0.0f) ? 1u : 0u;
                    }
                }
                const float n = float(p.ranked.size());
                Tile tile;
                tile.tall = p.tall;
                tile.flower = p.flower;
                tile.clovers = clovers;
                tile.first = uint32_t(out.size());
                tile.count = uint32_t(p.ranked.size());
                const float ySpan = std::max(p.high[1] - p.low[1], 1e-3f);
                tile.origin[0] = p.low[0];
                tile.origin[1] = p.low[1];
                tile.origin[2] = p.low[2];
                tile.origin[3] = ySpan;
                auto bits = [](float value, uint32_t most) {
                    return uint32_t(std::clamp(value, 0.0f, 1.0f) * float(most) + 0.5f);
                };
                for (size_t k = 0; k < p.ranked.size(); k++) {
                    const LooseBlade &l = p.ranked[k].second;
                    interop::GrassBlade b;
                    b.info.x = l.triangle;
                    b.info.y = bits((l.root[0] - p.low[0]) / GRASS_TILE_SIZE, 1023) | (bits((l.root[2] - p.low[2]) / GRASS_TILE_SIZE, 1023) << 10) |
                        (bits((l.root[1] - p.low[1]) / ySpan, 4095) << 20);
                    b.info.z = bits(l.u, 255) | (bits(l.v, 255) << 8) | (bits(l.turn, 255) << 16) | (bits(l.lean, 255) << 24);
                    b.info.w = bits(std::min(float(k) / n, 1.0f), 4095) | (bits(l.width, 255) << 12) | (bits(l.height / GRASS_HEIGHT_MAX, 4095) << 20);
                    out.push_back(b);
                }
                for (int k = 0; k < 3; k++) {
                    tile.low[k] = p.low[k];
                    tile.high[k] = p.high[k];
                }
                tile.high[1] += TileReach;
                // (Wider by as far as a blade can lean out of the tile, so one leaning into view from outside it is drawn
                // too and never appears at the screen's edge.)
                for (int k = 0; k < 3; k += 2) {
                    tile.low[k] -= TileLean;
                    tile.high[k] += TileLean;
                }
                for (int k = 0; k < 3; k++) {
                    baked.low[k] = std::min(baked.low[k], tile.low[k]);
                    baked.high[k] = std::max(baked.high[k], tile.high[k]);
                }
                baked.tiles.push_back(tile);
            }

            return true;
        }

        // The bake runs on its own thread, so a map's grass (about 200 ms of baking for Jinjo Village) is worked out
        // while the game goes on drawing instead of stopping it for that long when the map is entered (L asked for
        // cheaper grass, 2026-11-13). Draws are baked in batches, each batch's on several threads at once, in steps that
        // keep the order sent where it matters (Collect, Dedupe, Finish above), so the grass comes out the same; BeginFrame takes the finished ones in. A draw the frame can't do without (near
        // and in view as a map is entered, or appearing close to Banjo in play) is sent to the front, and BakeQueued
        // waits for it, so grass still never grows in where it can be seen.
        struct CoverSet {
            std::vector<GrassTriangle> triangles;
            Covers covers;
        };

        struct BakeJob {
            QueuedDraw draw;
            std::shared_ptr<const CoverSet> covers;
            uint32_t generation;
            // Waited for by the frame (BakeQueued): baked in a batch of its own, ahead of the rest.
            bool urgent;
        };

        struct BakeResult {
            uint64_t key;
            uint32_t generation;
            bool any;
            Baked baked;
            std::vector<interop::GrassBlade> blades;
            double ms;
        };

        struct BakeWorker {
            std::mutex mutex;
            std::condition_variable wake;
            std::condition_variable finished;
            std::deque<BakeJob> jobs;
            std::vector<BakeResult> results;
            // The draw being baked (0: none).
            uint64_t baking = 0;
        };

        // Runs work(0) to work(count - 1) on up to eight threads (this one among them) and returns when all are done.
        template <typename Work>
        void ParallelFor(size_t count, const Work &work) {
            const size_t cores = std::max<size_t>(std::thread::hardware_concurrency(), 2);
            const size_t threads = std::min<size_t>(std::min<size_t>(cores - 1, 8), count);
            std::atomic<size_t> next{ 0 };
            auto run = [&]() {
                for (size_t k = next++; k < count; k = next++) {
                    work(k);
                }
            };
            std::vector<std::thread> helpers;
            for (size_t t = 1; t < threads; t++) {
                helpers.emplace_back(run);
            }
            run();
            for (std::thread &helper : helpers) {
                helper.join();
            }
        }

        // The most draws in a batch not waited for (a map's many draws are baked a batch at a time, so a draw waited for
        // in play never sits behind the whole map).
        constexpr size_t BatchDraws = 16;

        void RunBakeWorker(BakeWorker *worker) {
            uint32_t workerGeneration = 0;
            for (;;) {
                // The next batch: every urgent draw at the front, or else up to BatchDraws of the rest.
                std::vector<BakeJob> batch;
                {
                    std::unique_lock lock{ worker->mutex };
                    worker->wake.wait(lock, [worker]() { return !worker->jobs.empty(); });
                    const bool urgent = worker->jobs.front().urgent;
                    while (!worker->jobs.empty() && (worker->jobs.front().urgent == urgent) && (urgent || (batch.size() < BatchDraws))) {
                        batch.push_back(std::move(worker->jobs.front()));
                        worker->jobs.pop_front();
                    }
                    worker->baking = batch.front().draw.key;
                }

                const auto start = std::chrono::steady_clock::now();
                std::vector<BakeSink> sinks(batch.size());
                ParallelFor(batch.size(), [&](size_t k) {
                    Collect(batch[k].draw, batch[k].covers->covers, sinks[k]);
                });
                std::vector<std::vector<uint8_t>> keeps(batch.size());
                {
                    std::lock_guard lock{ bakeMutex };
                    for (size_t k = 0; k < batch.size(); k++) {
                        if (batch[k].generation != workerGeneration) {
                            workerGeneration = batch[k].generation;
                            grownTufts.clear();
                            doubledTufts = 0;
                            tallBlades = 0;
                            coveredTufts = 0;
                        }
                        Dedupe(batch[k].draw.key, sinks[k], keeps[k]);
                    }
                }
                std::vector<BakeResult> results(batch.size());
                ParallelFor(batch.size(), [&](size_t k) {
                    BakeResult &result = results[k];
                    result.key = batch[k].draw.key;
                    result.generation = batch[k].generation;
                    result.any = Finish(sinks[k], keeps[k], result.blades, result.baked);
                    result.ms = 0.0;
                    // (Its blades as worked out let go of here, on its own thread.)
                    BakeSink().blades.swap(sinks[k].blades);
                });
                results.front().ms = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start).count();

                {
                    std::lock_guard lock{ worker->mutex };
                    for (BakeResult &result : results) {
                        worker->results.push_back(std::move(result));
                    }
                    worker->baking = 0;
                }
                worker->finished.notify_all();
            }
        }

        // (Made once and never destroyed: the thread runs until the game closes.)
        BakeWorker &Worker() {
            static BakeWorker *worker = []() {
                BakeWorker *w = new BakeWorker();
                std::thread(RunBakeWorker, w).detach();
                return w;
            }();
            return *worker;
        }

        void ClearWorker() {
            BakeWorker &worker = Worker();
            std::lock_guard lock{ worker.mutex };
            worker.jobs.clear();
            worker.results.clear();
        }

        // Takes in the bake thread's finished draws (of this generation), appending their blades.
        void MergeBaked() {
            BakeWorker &worker = Worker();
            std::vector<BakeResult> done;
            {
                std::lock_guard lock{ worker.mutex };
                done.swap(worker.results);
            }
            double ms = 0.0;
            for (BakeResult &result : done) {
                if (result.generation != generation.load()) {
                    continue;
                }
                ms += result.ms;
                int32_t index = -1;
                if (result.any) {
                    const uint32_t first = uint32_t(bladeCount);
                    for (Tile &tile : result.baked.tiles) {
                        tile.first += first;
                    }
                    newBlades.insert(newBlades.end(), result.blades.begin(), result.blades.end());
                    bladeCount += result.blades.size();
                    bakedDraws.push_back(std::move(result.baked));
                    index = int32_t(bakedDraws.size() - 1);
                }
                bakedByKey[result.key] = index;
                queuedKeys.erase(result.key);
            }
            lastWorkerMs += ms;
        }

        // Whether a queued draw's box is at least partly inside the frame's view.
        bool InView(const QueuedDraw &draw) {
            for (int p = 0; p < 6; p++) {
                const float *pl = planes[p];
                const float x = (pl[0] >= 0.0f) ? draw.high[0] : draw.low[0];
                const float y = (pl[1] >= 0.0f) ? draw.high[1] : draw.low[1];
                const float z = (pl[2] >= 0.0f) ? draw.high[2] : draw.low[2];
                if ((pl[0] * x + pl[1] * y + pl[2] * z + pl[3]) < 0.0f) {
                    return false;
                }
            }
            return true;
        }
    };

    void SetSceneGrass(bool on, float density, float distance, float height, float wind, bool tall, bool flowers) {
        std::lock_guard lock{ settingsMutex };
        settings.on = on;
        settings.tall = tall;
        settings.flowers = flowers;
        settings.density = std::clamp(density, 0.1f, BakeDensityMax);
        settings.distance = std::clamp(distance, 500.0f, 40000.0f);
        settings.height = std::clamp(height, 0.25f, 3.0f);
        settings.wind = std::clamp(wind, 0.0f, 1.0f);
    }

    void SetSceneGrassStyle(int type, float longHeight, float flowerAmount, float patches) {
        std::lock_guard lock{ settingsMutex };
        const int clamped = std::clamp(type, 1, 4);
        if (clamped != settings.type) {
            settings.type = clamped;
            rebakeAsked = true;
        }
        settings.longHeight = std::clamp(longHeight, 0.25f, 3.0f);
        settings.flowerAmount = std::clamp(flowerAmount, 0.0f, FlowerAmountMax);
        settings.patches = std::clamp(patches, 0.0f, 1.0f);
    }

    // (The beds are baked into the grass, so a change works the grass out again.)
    void SetSceneGrassFlowerBeds(float beds, float size) {
        std::lock_guard lock{ settingsMutex };
        beds = std::clamp(beds, 0.0f, 3.0f);
        size = std::clamp(size, 0.25f, 4.0f);
        if ((beds != settings.flowerBeds) || (size != settings.bedSize)) {
            settings.flowerBeds = beds;
            settings.bedSize = size;
            rebakeAsked = true;
        }
    }

    // (Read by the blades' shader each frame: no bake.)
    void SetSceneGrassKinds(const uint8_t *amounts, size_t count) {
        std::lock_guard lock{ settingsMutex };
        std::memcpy(settings.kindAmounts, amounts, std::min(count, sizeof(settings.kindAmounts)));
    }

    GrassSettings SceneGrassSettings() {
        std::lock_guard lock{ settingsMutex };
        GrassSettings out = settings;
        // (No flowers or clover on the seabed.)
        out.flowers = out.flowers && !out.water;
        return out;
    }

    void SetSceneGrassMap(uint32_t map) {
        std::lock_guard lock{ settingsMutex };
        if (map == settings.map) {
            return;
        }
        settings.map = map;
        const bool water = (map == 0x1A8) || (map == 0x1A9);
        if (water != settings.water) {
            settings.water = water;
            textureListsVersion++;
            rebakeAsked = true;
        }
    }

    void SetSceneWeedTextures(const uint64_t *hashes, size_t count) {
        std::vector<uint64_t> list(hashes, hashes + count);
        std::sort(list.begin(), list.end());
        std::lock_guard lock{ settingsMutex };
        if (list != weedTextures) {
            weedTextures = std::move(list);
            if (settings.water) {
                textureListsVersion++;
                rebakeAsked = true;
            }
        }
    }

    GrassLevelLook SceneGrassLevelLook() {
        uint32_t map;
        bool water;
        {
            std::lock_guard lock{ settingsMutex };
            map = settings.map;
            water = settings.water;
        }
        GrassLevelLook look;
        auto set = [&look](float r, float g, float b, float height, float flowers, uint32_t plant) {
            look.plant = plant;
            look.tint[0] = r;
            look.tint[1] = g;
            look.tint[2] = b;
            look.height = height;
            look.flowers = flowers;
        };
        if (water) {
            // Seabed weed: the sand's colour turned an olive kelp green, tall and in clumps; kelp ribbons and eelgrass.
            set(0.5f, 0.85f, 0.45f, 1.9f, 0.0f, GRASS_PLANT_KELP);
        }
        else if ((map >= 0x112) && (map <= 0x11B)) {
            // Terrydactyland: dry, straw-coloured grass, a little taller, with ferns, horsetails and tussocks among it, and
            // cycads and magnolias.
            set(1.14f, 1.0f, 0.62f, 1.12f, 0.7f, GRASS_PLANT_FERN);
        }
        else if ((map == 0xC7) || (map == 0xD7) || (map == 0xD8)) {
            // Glitter Gulch Mine: dusty and short, stiff dry straw with yucca spikes and tumbleweed tufts, and barrel
            // cacti and crystal sprouts.
            set(1.06f, 0.94f, 0.74f, 0.8f, 0.8f, GRASS_PLANT_DESERT);
        }
        else if ((map == 0xD6) || (map == 0xEC)) {
            // Witchyworld: a short, tidy, mown lawn with pennant-tipped grass and clipped topiary tufts, and carnival
            // pinwheel blooms and toadstools.
            set(1.0f, 1.05f, 0.95f, 0.7f, 1.0f, GRASS_PLANT_LAWN);
        }
        else if ((map >= 0x100) && (map <= 0x111)) {
            // Grunty Industries: short, greyish, weedy straw with rusty dock leaves and wire grass, and dandelions and
            // dandelion clocks.
            set(0.9f, 0.93f, 0.84f, 0.75f, 0.7f, GRASS_PLANT_INDUSTRY);
        }
        else if (map == 0x127) {
            // Hailfire Peaks' lava side: scorched straw with charred, ember-tipped stalks and ash grass, and fire lilies
            // and flame poppies.
            set(1.12f, 0.88f, 0.6f, 0.8f, 0.7f, GRASS_PLANT_LAVA);
        }
        else if ((map == 0x128) || (map == 0x168)) {
            // Hailfire Peaks' icy side: stiff frosted spikes with ice shards and frozen tufts, and snowdrops and ice
            // crystal clusters.
            set(0.94f, 1.02f, 1.14f, 0.8f, 0.7f, GRASS_PLANT_FROST);
        }
        else if ((map == 0xB8) || (map == 0xC4)) {
            // Mayahem Temple: lush and taller, with broad jungle leaves, palm fronds and cattail reeds among it, and orchids
            // and bromeliads.
            set(0.94f, 1.06f, 0.92f, 1.15f, 1.1f, GRASS_PLANT_JUNGLE);
        }
        else if ((map == 0x136) || (map == 0x13A)) {
            // Cloud Cuckooland: lush and taller, with pastel-tipped candy grass and white cloud tufts, and candy puffs and
            // lollipop swirls.
            set(0.94f, 1.06f, 0.92f, 1.15f, 1.1f, GRASS_PLANT_CANDY);
        }
        else if ((map == 0x1A7) || (map == 0xED)) {
            // Jolly Roger's Lagoon by the sea: a little sandy, long curling dune grass with sea oats and beach succulents,
            // and sea pinks and sea holly.
            set(1.04f, 1.02f, 0.86f, 0.9f, 0.7f, GRASS_PLANT_DUNE);
        }
        return look;
    }

    // (The lists are sent again whenever any setting changes: only a list that is really different bakes again.)
    void SetSceneGrassTextures(const uint64_t *hashes, size_t count) {
        std::vector<uint64_t> list(hashes, hashes + count);
        std::sort(list.begin(), list.end());
        std::lock_guard lock{ settingsMutex };
        if (list != grassTextures) {
            grassTextures = std::move(list);
            textureListsVersion++;
            rebakeAsked = true;
        }
    }

    void SetSceneTallGrassTextures(const uint64_t *hashes, size_t count) {
        std::vector<uint64_t> list(hashes, hashes + count);
        std::sort(list.begin(), list.end());
        std::lock_guard lock{ settingsMutex };
        if (list != tallGrassTextures) {
            tallGrassTextures = std::move(list);
            textureListsVersion++;
            rebakeAsked = true;
        }
    }

    void SceneGrassTextureLists(uint32_t &version, std::vector<uint64_t> &grass, std::vector<uint64_t> &tall) {
        if (version == textureListsVersion.load()) {
            return;
        }
        std::lock_guard lock{ settingsMutex };
        version = textureListsVersion.load();
        grass = grassTextures;
        if (settings.water) {
            grass.insert(grass.end(), weedTextures.begin(), weedTextures.end());
            std::sort(grass.begin(), grass.end());
        }
        tall = tallGrassTextures;
    }

    bool SceneGrassTexture(uint64_t hash) {
        std::lock_guard lock{ settingsMutex };
        return std::binary_search(grassTextures.begin(), grassTextures.end(), hash) ||
            (settings.water && std::binary_search(weedTextures.begin(), weedTextures.end(), hash));
    }

    bool SceneTallGrassTexture(uint64_t hash) {
        std::lock_guard lock{ settingsMutex };
        return std::binary_search(tallGrassTextures.begin(), tallGrassTextures.end(), hash);
    }

    void SceneGrassStatsText(char *out, size_t size) {
        const GrassSettings g = SceneGrassSettings();
        size_t textures = 0, tallTextures = 0;
        {
            std::lock_guard lock{ settingsMutex };
            textures = grassTextures.size();
            tallTextures = tallGrassTextures.size();
        }
        std::lock_guard lock{ statsMutex };
        std::lock_guard bakeLock{ bakeMutex };
        std::snprintf(out, size, "3D grass %s: %zu blades kept (%zu tall, %zu tufts left out under roads and paths) from %zu draws; last frame %zu slots, "
            "%zu tiles, %u blades drawn; last bake %.2f ms waited, %.2f ms on the bake thread in all, CPU %.3f ms a frame (timed one frame in 8; %.3f on average; picking %.3f ms over %u tiles; the renderer's checks %.3f ms over %u draws, picking included); %llu frames, %zu + %zu textures, grass texture draws %u level, %u other; "
            "pipeline %s, camera %s; in view but not drawn by the game %zu (nearest %.0f); tufts left out as another draw's %zu; draws drawn twice last frame %u", g.on ? "on" : "off", bladeCount, tallBlades, coveredTufts, bakedDraws.size(), lastSlots, lastTiles, lastDrawn,
            lastBakeMs, lastWorkerMs, frameMs, frameCpuAverage, lastPickMs, lastTilesLooked, lastDrawsMs, lastDrawsTimed, (unsigned long long)framesOpened, textures, tallTextures, lastTextureDraws[1], lastTextureDraws[0],
            pipelineReady ? "ready" : "not built", cameraFound ? "found" : "not found", lastMissed, lastMissedNearest, doubledTufts, lastDoubledDraws);
        // The covers that left out the most tufts.
        std::vector<std::pair<uint32_t, uint64_t>> top;
        for (const auto &entry : coverTextures) {
            top.emplace_back(entry.second, entry.first);
        }
        std::sort(top.rbegin(), top.rend());
        for (size_t k = 0; (k < top.size()) && (k < 5); k++) {
            const size_t used = std::strlen(out);
            std::snprintf(out + used, (size > used) ? (size - used) : 0, "%s%016llx %u", (k == 0) ? "; covers: " : ", ", (unsigned long long)top[k].second, top[k].first);
        }
    }

    void SceneGrassRebake() {
        grass::Rebake();
    }

    namespace grass {
        void BeginFrame(const float cameraPosition[3], const float framePlanes[6][4]) {
            {
                std::lock_guard lock{ statsMutex };
                framesOpened++;
                timedFrame = (framesOpened % TimedEvery) == 0;
                lastTextureDraws[0] = textureDraws[0];
                lastTextureDraws[1] = textureDraws[1];
                textureDraws[0] = textureDraws[1] = 0;
                // Baked grass is kept from map to map; when it nears MaxBlades and a new area wants its own, everything
                // is thrown away and the area here is baked fresh, all at once (it arrives as one batch). Not again within
                // ten seconds, so a map that is too big on its own keeps what it has instead of being baked over and over.
                const auto now = std::chrono::steady_clock::now();
                // (Only when a whole area arrives, which is a map being entered behind its fade: a draw or two coming
                // into view later is baked on top, up to HardMaxBlades, so the grass never blinks out in play.)
                const bool full = (bladeCount > (MaxBlades * 4) / 5) && (queued.size() > ArrivalDraws) && ((now - lastClear) > std::chrono::seconds(10));
                if (rebakeAsked.exchange(false) || full) {
                    Clear();
                    lastClear = now;
                }
                MergeBaked();
            }

            std::memcpy(camera, cameraPosition, sizeof(camera));
            std::memcpy(planes, framePlanes, sizeof(planes));
            frameSettings = SceneGrassSettings();
            frameCpuMs = 0.0;
            framePickMs = 0.0;
            frameTilesLooked = 0;
            frameDrawsMs = 0.0;
            frameDrawsTimed = 0;
            slots.clear();
            tiles.clear();
            frameTiles.clear();
        }

        bool Find(uint64_t key, int32_t &baked) {
            auto found = bakedByKey.find(key);
            if (found == bakedByKey.end()) {
                return false;
            }
            baked = found->second;
            return true;
        }

        bool Queued(uint64_t key) {
            return queuedKeys.count(key) != 0;
        }

        void Queue(uint64_t key, std::vector<GrassTriangle> &&triangles, bool ground, bool tall, bool useAlpha, bool decal) {
            if (queuedKeys.insert(key).second) {
                QueuedDraw draw = { key, std::move(triangles), ground, tall, useAlpha, decal, { 1e30f, 1e30f, 1e30f }, { -1e30f, -1e30f, -1e30f }, 0, 1.0f, 1.0f };
                {
                    const GrassSettings now = SceneGrassSettings();
                    draw.type = now.type;
                    draw.flowerBeds = now.flowerBeds;
                    draw.bedSize = now.bedSize;
                }
                for (const GrassTriangle &t : draw.triangles) {
                    for (int c = 0; c < 3; c++) {
                        for (int k = 0; k < 3; k++) {
                            draw.low[k] = std::min(draw.low[k], t.p[c][k]);
                            draw.high[k] = std::max(draw.high[k], t.p[c][k]);
                        }
                    }
                }
                queued.push_back(std::move(draw));
            }
        }

        bool WantsBake() {
            if (bladeCount >= HardMaxBlades) {
                return false;
            }
            if (queued.size() > ArrivalDraws) {
                return true;
            }
            for (const QueuedDraw &draw : queued) {
                if (Near(draw)) {
                    return true;
                }
            }
            return false;
        }

        bool HasQueued() {
            return !queued.empty();
        }

        void BakeQueued(const std::vector<GrassTriangle> &coverTriangles) {
            if (queued.empty()) {
                return;
            }

            const auto start = std::chrono::steady_clock::now();
            auto covers = std::make_shared<CoverSet>();
            covers->triangles = coverTriangles;
            covers->covers.Build(covers->triangles);
            std::lock_guard lock{ statsMutex };
            // A whole area arriving (a map just entered, more than ArrivalDraws new draws at once) is all sent to the
            // bake thread at once, the draws near and in view first, and the frame waits for those, so the grass in
            // sight is there from the first frame; the rest of the map is baked behind it while the screen fades in.
            // In play, ground that comes into view near the camera is waited for too (its grass never grows in in
            // front of Banjo), and ground further off is baked in the background once in reach.
            const bool arrival = queued.size() > ArrivalDraws;
            const uint32_t jobGeneration = generation.load();
            std::vector<QueuedDraw> waiting;
            std::vector<BakeJob> urgent;
            std::vector<BakeJob> later;
            std::unordered_set<uint64_t> waitFor;
            for (QueuedDraw &draw : queued) {
                const bool needed = NearNow(draw) && (!arrival || InView(draw));
                if (needed) {
                    waitFor.insert(draw.key);
                    urgent.push_back({ std::move(draw), covers, jobGeneration, true });
                }
                else if (arrival || Near(draw)) {
                    later.push_back({ std::move(draw), covers, jobGeneration, false });
                }
                else {
                    waiting.push_back(std::move(draw));
                }
            }
            queued = std::move(waiting);

            BakeWorker &worker = Worker();
            {
                std::lock_guard workerLock{ worker.mutex };
                // (The ones waited for go ahead of anything already waiting, in their own order.)
                for (auto it = urgent.rbegin(); it != urgent.rend(); ++it) {
                    worker.jobs.push_front(std::move(*it));
                }
                for (BakeJob &job : later) {
                    worker.jobs.push_back(std::move(job));
                }
            }
            worker.wake.notify_all();
            if (!waitFor.empty()) {
                std::unique_lock workerLock{ worker.mutex };
                worker.finished.wait(workerLock, [&worker, &waitFor]() {
                    size_t found = 0;
                    for (const BakeResult &result : worker.results) {
                        found += waitFor.count(result.key);
                    }
                    return found >= waitFor.size();
                });
                workerLock.unlock();
                MergeBaked();
            }
            lastBakeMs = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start).count();
        }

        uint32_t AddSlot(int32_t baked, uint32_t faceIndicesStart) {
            if ((baked < 0) || (size_t(baked) >= bakedDraws.size())) {
                return 0;
            }

            // (Its time is counted in the renderer's, which takes in the whole of the grass's work on a draw; and on its
            // own for the console.)
            // (Only on a timed frame, Timed.)
            struct PickTimer {
                bool on;
                std::chrono::steady_clock::time_point start;
                ~PickTimer() {
                    if (on) {
                        framePickMs += std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start).count();
                    }
                }
            } pickTimer{ timedFrame, timedFrame ? std::chrono::steady_clock::now() : std::chrono::steady_clock::time_point{} };
            const float reach = frameSettings.distance;
            const float share = frameSettings.density / BakeDensityMax;
            const float fadeFrom = reach * (1.0f - FadeShare);
            if (bakedDraws[baked].drawnFrame == framesOpened) {
                doubledDraws++;
                return 0;
            }
            bakedDraws[baked].drawnFrame = framesOpened;
            const Baked &draw = bakedDraws[baked];
            auto boxOut = [](const float low[3], const float high[3]) {
                // Too far: the box's nearest point. Out of view: wholly outside one of the frustum's planes.
                float d2 = 0.0f;
                for (int k = 0; k < 3; k++) {
                    const float c = std::clamp(camera[k], low[k], high[k]) - camera[k];
                    d2 += c * c;
                }
                if (d2 >= frameSettings.distance * frameSettings.distance) {
                    return -1.0f;
                }
                for (int p = 0; p < 6; p++) {
                    const float *pl = planes[p];
                    const float x = (pl[0] >= 0.0f) ? high[0] : low[0];
                    const float y = (pl[1] >= 0.0f) ? high[1] : low[1];
                    const float z = (pl[2] >= 0.0f) ? high[2] : low[2];
                    if ((pl[0] * x + pl[1] * y + pl[2] * z + pl[3]) < 0.0f) {
                        return -1.0f;
                    }
                }
                return std::sqrt(d2);
            };
            if (boxOut(draw.low, draw.high) < 0.0f) {
                return 0;
            }
            const uint32_t firstTile = uint32_t(tiles.size());
            uint32_t nearTiles = 0;
            // (Mid-distance tiles go after the near ones, and flower tiles after those: kept aside until the draw's tiles
            // are all looked at.)
            thread_local std::vector<std::pair<interop::GrassTileDraw, FrameTile>> mids;
            thread_local std::vector<std::pair<interop::GrassTileDraw, FrameTile>> flowers;
            mids.clear();
            flowers.clear();
            frameTilesLooked += uint32_t(draw.tiles.size());
            for (const Tile &t : draw.tiles) {
                // (Flower tiles hold the clovers too: Flowers and Flower Amount pick which flowers show, GrassBladeVS.hlsl.)
                const float distance = boxOut(t.low, t.high);
                if (distance < 0.0f) {
                    continue;
                }

                // The most any blade of the tile keeps (at its nearest point; GrassBladeVS.hlsl works out each blade's own),
                // and the blades that many ranks reach, with those growing in.
                // (The frame budget thins only beyond FullReach, by falling off faster there, never near Banjo:
                // GrassBladeVS.hlsl works out the same.)
                static const bool noFade = (std::getenv("TOOIE_GRASS_NOFADE") != nullptr);
                const float far = ((distance <= FullReach) || noFade) ? 1.0f : std::pow(FullReach / distance, 2.0f / std::max(budgetScale, 0.2f));
                const float fade = (distance <= fadeFrom) ? 1.0f : std::max(1.0f - (distance - fadeFrom) / (reach - fadeFrom), 0.0f);
                const float tileShare = t.tall ? TallShare : share;
                const float keep = (t.tall ? 1.0f : (far * tileShare)) * fade;
                uint32_t drawn = std::min(uint32_t(std::ceil(std::min(keep * GrowShare, 1.0f) * float(t.count))), t.count);
                if (t.flower) {
                    // Only the clovers and the flowers Flower Amount shows (none with Flowers off), with a few over: the
                    // shader still leaves out any over the amount (GrassBladeVS.hlsl).
                    const float amount = frameSettings.flowers ? (frameSettings.flowerAmount / FlowerAmountMax) : 0.0f;
                    const uint32_t shown = (amount > 0.0f) ? uint32_t(std::ceil(float(t.count - t.clovers) * amount * 1.1f)) + 2u : 0u;
                    drawn = std::min(drawn, std::min(t.clovers + shown, t.count));
                }
                if (drawn == 0) {
                    continue;
                }

                interop::GrassTileDraw draw;
                uint32_t bits;
                std::memcpy(&bits, &tileShare, sizeof(bits));
                draw.info = { t.first, drawn, 0, bits };
                draw.origin = { t.origin[0], t.origin[1], t.origin[2], t.origin[3] };
                const FrameTile frameTile = { t.count, keep };
                if (t.flower) {
                    flowers.emplace_back(draw, frameTile);
                }
                else if (distance > NearReach) {
                    mids.emplace_back(draw, frameTile);
                }
                else {
                    tiles.push_back(draw);
                    frameTiles.push_back(frameTile);
                    nearTiles++;
                }
            }

            for (const auto &m : mids) {
                tiles.push_back(m.first);
                frameTiles.push_back(m.second);
            }
            for (const auto &f : flowers) {
                tiles.push_back(f.first);
                frameTiles.push_back(f.second);
            }

            const uint32_t midTiles = uint32_t(mids.size());
            const uint32_t flowerTiles = uint32_t(flowers.size());
            if ((nearTiles + midTiles + flowerTiles) == 0) {
                return 0;
            }

            interop::GrassSlot slot;
            slot.info = { firstTile, nearTiles, midTiles, faceIndicesStart };
            slot.flowers = { flowerTiles, 0, 0, 0 };
            slots.push_back(slot);
            return uint32_t(slots.size());
        }

        uint32_t EndFrame() {
            const auto start = std::chrono::steady_clock::now();
            // The blades asked for: a frame far over the budget (twice) is cut straight away, as a safety net only.
            double asked = 0.0;
            for (const FrameTile &f : frameTiles) {
                asked += std::min(f.keep * GrowShare, 1.0f) * float(f.blades);
            }
            // (No easing budget any more: it overshot to and fro and the far grass flickered, L 2026-11-12. The grass
            // thins with distance by its square, so a frame's blades stay bounded anyway; budgetScale stays 1.)
            const float scale = (asked > 2.0 * double(FrameBudget)) ? float(2.0 * double(FrameBudget) / asked) : 1.0f;

            // Each slot's instances: where each tile's blades start in its near and mid groups.
            uint32_t drawn = 0;
            for (const interop::GrassSlot &slot : slots) {
                for (uint32_t group = 0; group < 3; group++) {
                    const uint32_t first = slot.info.x + ((group == 0) ? 0 : ((group == 1) ? slot.info.y : (slot.info.y + slot.info.z)));
                    const uint32_t count = (group == 0) ? slot.info.y : ((group == 1) ? slot.info.z : slot.flowers.x);
                    uint32_t offset = 0;
                    for (uint32_t k = first; k < first + count; k++) {
                        FrameTile &f = frameTiles[k];
                        interop::GrassTileDraw &draw = tiles[k];
                        if (scale < 1.0f) {
                            draw.info.y = std::min(uint32_t(std::ceil(float(draw.info.y) * scale)), f.blades);
                        }
                        draw.info.z = offset;
                        offset += draw.info.y;
                    }
                    drawn += offset;
                }
            }

            std::lock_guard lock{ statsMutex };
            lastDrawn = drawn;
            lastSlots = slots.size();
            lastDoubledDraws = doubledDraws;
            doubledDraws = 0;
            lastMissed = 0;
            lastMissedNearest = 0.0f;
            for (const Baked &b : bakedDraws) {
                if (b.tiles.empty() || (b.drawnFrame == framesOpened)) {
                    continue;
                }
                float d2 = 0.0f;
                for (int k = 0; k < 3; k++) {
                    const float c = std::clamp(camera[k], b.low[k], b.high[k]) - camera[k];
                    d2 += c * c;
                }
                bool out = d2 >= frameSettings.distance * frameSettings.distance;
                for (int p = 0; (p < 6) && !out; p++) {
                    const float *pl = planes[p];
                    out = (pl[0] * ((pl[0] >= 0.0f) ? b.high[0] : b.low[0]) + pl[1] * ((pl[1] >= 0.0f) ? b.high[1] : b.low[1]) + pl[2] * ((pl[2] >= 0.0f) ? b.high[2] : b.low[2]) + pl[3]) < 0.0f;
                }
                if (!out) {
                    const float d = std::sqrt(d2);
                    lastMissedNearest = (lastMissed == 0) ? d : std::min(lastMissedNearest, d);
                    lastMissed++;
                }
            }
            lastTiles = tiles.size();
            // (The times are those of the last timed frame, and the average of the timed frames.)
            if (timedFrame) {
                lastPickMs = framePickMs;
                lastTilesLooked = frameTilesLooked;
                lastDrawsMs = frameDrawsMs;
                lastDrawsTimed = frameDrawsTimed;
                frameCpuMs += std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start).count();
                frameMs = frameCpuMs;
                frameCpuAverage = (frameCpuAverage <= 0.0) ? frameCpuMs : (frameCpuAverage * 0.8 + frameCpuMs * 0.2);
            }
            return drawn;
        }

        void SlotInstances(uint32_t slot, uint32_t &nearInstances, uint32_t &midInstances, uint32_t &flowerInstances) {
            nearInstances = 0;
            midInstances = 0;
            flowerInstances = 0;
            if ((slot == 0) || (slot > slots.size())) {
                return;
            }
            const interop::GrassSlot &s = slots[slot - 1];
            for (uint32_t k = s.info.x; k < s.info.x + s.info.y; k++) {
                nearInstances += tiles[k].info.y;
            }
            for (uint32_t k = s.info.x + s.info.y; k < s.info.x + s.info.y + s.info.z; k++) {
                midInstances += tiles[k].info.y;
            }
            for (uint32_t k = s.info.x + s.info.y + s.info.z; k < s.info.x + s.info.y + s.info.z + s.flowers.x; k++) {
                flowerInstances += tiles[k].info.y;
            }
        }

        void TakeBlades(std::vector<interop::GrassBlade> &out) {
            if (out.empty()) {
                out.swap(newBlades);
            }
            else {
                out.insert(out.end(), newBlades.begin(), newBlades.end());
            }
            // (Its memory let go of, not only emptied.)
            std::vector<interop::GrassBlade>().swap(newBlades);
        }

        const std::vector<interop::GrassSlot> &Slots() {
            return slots;
        }

        const std::vector<interop::GrassTileDraw> &Tiles() {
            return tiles;
        }

        uint32_t Generation() {
            return generation.load();
        }

        void Rebake() {
            rebakeAsked = true;
        }

        void NoteTextureDraw(bool level) {
            std::lock_guard lock{ statsMutex };
            textureDraws[level ? 1 : 0]++;
        }

        float BudgetScale() {
            return budgetScale;
        }

        void LodTerms(float terms[4]) {
            const float reach = SceneGrassSettings().distance;
            terms[0] = FullReach;
            terms[1] = reach;
            terms[2] = reach * (1.0f - FadeShare);
            terms[3] = NearReach;
        }

        bool Timed() {
            return timedFrame;
        }

        void NoteCpuTime(double ms) {
            frameCpuMs += ms;
            frameDrawsMs += ms;
            frameDrawsTimed++;
        }

        void NoteFrame(bool pipeline, bool camera) {
            std::lock_guard lock{ statsMutex };
            pipelineReady = pipeline;
            cameraFound = camera;
        }
    };
};
