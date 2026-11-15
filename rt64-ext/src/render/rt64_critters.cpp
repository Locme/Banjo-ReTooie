//
// RT64
//

#include "rt64_critters.h"

#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <list>
#include <mutex>
#include <unordered_map>
#include <unordered_set>

#include "shared/rt64_grass_blades.h"

// Banjo-Tooie: small creatures in the 3D grass (rt64_critters.h). The insects each go between resting on the grass
// and flying to another spot; birds rest on the ground or wheel high overhead; frogs hop and crabs scuttle sideways;
// fish swim in schools round a moving middle, with a sea turtle and a ray gliding past and bubbles rising. Everything
// keeps to a ring round Banjo, drifts with the grass's wind, and is knocked tumbling by his attacks.

namespace RT64 {
    namespace {
        // How far apart the spots to land on are picked (one a square this wide, on average), and the grid they are
        // kept in to find those near a place.
        constexpr float SpotSpacing = 110.0f;
        constexpr float SpotCell = 512.0f;
        // The most spots kept for one map, and for every map kept (the oldest map's are let go of first).
        // (Past the most for a map, new spots take the place of old ones at random, so a big map's spots stay spread
        // over all of it rather than only the first ground seen.)
        constexpr size_t MapSpotsMost = 60000;
        constexpr size_t SpotsMost = 150000;
        // A map with fewer grass spots than this (Hailfire Peaks' icy side, Glitter Gulch Mine) also takes spots on its
        // bare flat ground, further apart, so it has insects too.
        constexpr size_t BareWhenUnder = 3000;
        constexpr float BareSpacing = 220.0f;
        // Under the sea the ground is the whole level's: spots further apart there.
        constexpr float WaterSpacing = 170.0f;
        // The ring round Banjo they live in: they appear between Near and Appear away (past FleeRadius of him), and go
        // once they are further than Leave. They shrink away with the camera's distance from FadeFrom to FadeTo too.
        constexpr float AppearNear = 260.0f;
        constexpr float AppearFar = 1100.0f;
        constexpr float LeaveDistance = 1500.0f;
        constexpr float FadeFrom = 1500.0f;
        constexpr float FadeTo = 1900.0f;
        // How long one takes to grow in from nothing, and to shrink away, in seconds.
        constexpr float GrowSeconds = 1.4f;
        constexpr float ShrinkSeconds = 0.9f;
        // How many insects a level has (times Amount), and how many fish schools under the sea and fish in each.
        constexpr int InsectsUsual = 18;
        constexpr int SchoolsUsual = 4;
        constexpr int SchoolFishLeast = 4;
        constexpr int SchoolFishMost = 8;
        constexpr int SchoolsMost = 10;
        // How many birds, frogs and crabs a land level has (times Amount), crabs on the seabed, and the sea's big gliders
        // (a turtle and a ray) and bubbles at the most.
        constexpr int AnimalsUsual = 6;
        constexpr int SeaCrabsUsual = 3;
        constexpr int GlidersMost = 4;
        constexpr int BubblesMost = 40;
        // Bees of a hive (SetSceneCritterHives): how many, how near Banjo the hive must be for them to be about, and how
        // far from it they go for the flowers.
        constexpr int HiveBees = 7;
        constexpr float HiveReach = 1300.0f;
        constexpr float HiveForage = 550.0f;
        // Banjo's attacks that knock creatures tumbling (his movement state, as damage_mods.cpp reads it: the roll,
        // the claw swipe or peck, and Kazooie's wing whack), and how near.
        constexpr float KnockReach = 160.0f;

        // Perched: resting (a bird or frog on the ground); Hopping: a frog's hop or a crab's scuttle, from hop0 to target;
        // Soaring: a bird wheeling high overhead; Tumbling: knocked by one of Banjo's attacks.
        enum class State { Perched, Flying, Fleeing, Buzzing, Hovering, Hopping, Soaring, Tumbling };

        struct Spot {
            float p[3];
            // On the level's bare ground (picked only where a map has little grass), not on the grass.
            bool bare = false;
            // How roomy its triangle is: the widest circle that fits in it, in world units (255 at the most). A beam or
            // trim along a wall is flat too, but narrow: frogs and crabs keep off those.
            uint8_t roomy = 255;
        };
        // The least room a frog or crab takes a spot with (about its own width).
        constexpr uint8_t GroundRoom = 20;

        // A map's spots, in cells of the grid.
        struct MapSpots {
            uint32_t map = 0;
            std::vector<Spot> spots;
            std::unordered_map<int64_t, std::vector<uint32_t>> cells;
            std::unordered_set<uint64_t> keys;
            size_t grassSpots = 0;
            // Every spot offered so far, kept or not (for the spots taking each other's place).
            uint64_t offered = 0;
        };

        struct Insect {
            bool live = false;
            int kind = 0;
            int variant = 0;
            State state = State::Perched;
            float pos[3] = {};
            float vel[3] = {};
            float target[3] = {};
            float home[3] = {};
            float timer = 0.0f;
            float grow = 0.0f;
            bool leaving = false;
            float yaw = 0.0f;
            float pitch = 0.0f;
            float bank = 0.0f;
            float wingPhase = 0.0f;
            float seed = 0.0f;
            float cooldown = 0.0f;
            float buzzAngle = 0.0f;
            bool spawned = false;
            // A hive bee's hive (-1: none) and whether it is on its way back to it.
            int hive = -1;
            bool toHive = false;
            // A hop or scuttle: where it started, how far through it is and how long and high it is, and how many more
            // hops a fleeing frog makes.
            float hop0[3] = {};
            float hopT = 0.0f;
            float hopTime = 0.0f;
            float hopHeight = 0.0f;
            int hopsLeft = 0;
            // A soaring bird's circle: its angle and radius round home, and which way round.
            float soarAngle = 0.0f;
            float soarRadius = 0.0f;
            float soarTurn = 1.0f;
            // Spin while tumbling.
            float spin = 0.0f;
            // Its own temperament, 0.8 to 1.25: how fast it goes, how near Banjo may come before it goes, and how long it
            // rests (so a crowd of one kind doesn't move as one).
            float temper = 1.0f;
        };

        // A big, slow sea creature (a turtle or a ray), circling round a middle that keeps near Banjo.
        struct Glider {
            bool live = false;
            int kind = CRITTER_TURTLE;
            float pos[3] = {};
            float vel[3] = {};
            float middle[3] = {};
            float angle = 0.0f;
            float radius = 450.0f;
            float turn = 1.0f;
            float yaw = 0.0f;
            float pitch = 0.0f;
            float bank = 0.0f;
            float phase = 0.0f;
            float flee = 0.0f;
            float grow = 0.0f;
            bool leaving = false;
            float seed = 0.0f;
            float size = 70.0f;
            float bubbleIn = 2.0f;
        };

        // A bubble rising through the water, popping after a while.
        struct Bubble {
            bool live = false;
            float pos[3] = {};
            float age = 0.0f;
            float life = 3.0f;
            float rise = 50.0f;
            float size = 4.0f;
            float seed = 0.0f;
        };

        struct School {
            bool live = false;
            int variant = 0;
            int count = 0;
            float center[3] = {};
            float vel[3] = {};
            float target[3] = {};
            float timer = 0.0f;
            float grow = 0.0f;
            bool leaving = false;
            float flee = 0.0f;
            float spread = 1.0f;
            float yaw = 0.0f;
            float pitch = 0.0f;
            float swish = 0.0f;
            float seed = 0.0f;
            float size = 16.0f;
            float bubbleIn = 1.5f;
        };

        // A kind of insect a level has, with its colour variant and how often it is picked.
        struct Mix {
            int kind;
            int variant;
            float weight;
        };

        std::mutex mutex;
        CritterSettings settings;
        // Day and Night's light (SetSceneCritterDaylight), and whether the insects about are the night's.
        bool dayCycle = false;
        float daylight = 1.0f;
        bool nightMix = false;
        // Below this light it is dusk or night.
        constexpr float NightLight = 0.6f;
        std::list<MapSpots> maps;
        size_t spotTotal = 0;
        uint32_t frameMap = 0;
        bool frameMapKnown = false;
        std::vector<Insect> insects;
        std::vector<School> schools;
        std::vector<Glider> gliders;
        std::vector<Bubble> bubbles;
        // The hives (SetSceneCritterHives): map and place.
        struct Hive {
            uint32_t map;
            float p[3];
        };
        std::vector<Hive> hives;
        // Banjo's movement state (SetSceneCritterPlayerAction), and how hard the grass's wind blows (0 to 1).
        uint32_t playerAction = 0;
        float windStrength = 0.5f;
        std::vector<interop::Critter> drawn;
        // The drawn creatures' runs of one kind: kind, first, count.
        std::vector<std::array<uint32_t, 3>> kindDraws;
        std::chrono::steady_clock::time_point lastUpdate{};
        bool haveLast = false;
        float clock = 0.0f;
        uint32_t randomState = 0x9E3779B9u;
        // How far above or below the place it is looked for round a spot may be (FindSpot): further under the sea, where
        // the fish swim well above the seabed.
        float findRise = 250.0f;
        // How many grass triangles faced up and down as wound (NoteGround), to tell floors from undersides.
        uint64_t windingUp = 0;
        uint64_t windingDown = 0;
        // The camera this frame, and how far from it a spot must be (FindSpot): a creature never appears, nor lands, right
        // in front of the camera, in the player's face. Far for new ones (they then come in from out in the scene), less
        // for the spots they fly on to.
        float frameCamera[3] = {};
        float cameraClear = 0.0f;
        // Where the creatures are and are heading, in cells CrowdCell wide (rebuilt each frame, and a spot added as soon as
        // FindSpot gives it out): FindSpot passes over a spot in or beside a taken cell, so two creatures never land on
        // the same spot or on top of each other.
        constexpr float CrowdCell = 26.0f;
        std::unordered_set<int64_t> crowd;

        int64_t CrowdKey(int64_t cx, int64_t cz) {
            return (cx << 32) ^ (cz & 0xFFFFFFFFll);
        }

        void MarkCrowd(const float p[3]) {
            crowd.insert(CrowdKey(int64_t(std::floor(p[0] / CrowdCell)), int64_t(std::floor(p[2] / CrowdCell))));
        }

        bool Crowded(const float p[3]) {
            const int64_t cx = int64_t(std::floor(p[0] / CrowdCell)), cz = int64_t(std::floor(p[2] / CrowdCell));
            for (int64_t dx = -1; dx <= 1; dx++) {
                for (int64_t dz = -1; dz <= 1; dz++) {
                    if (crowd.count(CrowdKey(cx + dx, cz + dz)) != 0) {
                        return true;
                    }
                }
            }
            return false;
        }

        // Whether FindSpot takes the bare ground's spots before the grass's (crabs on sand, frogs on paths, where they are
        // not hidden in the grass).
        bool preferBare = false;
        constexpr float AppearCameraClear = 900.0f;
        constexpr float LandCameraClear = 320.0f;
        // Anything nearer the camera than NearFadeTo shrinks away, and is gone by NearFadeFrom, so one that wanders up to
        // the lens never fills the screen.
        constexpr float NearFadeFrom = 90.0f;
        constexpr float NearFadeTo = 240.0f;
        uint32_t lastMap = 0xFFFFFFFFu;
        bool lastWater = false;
        // Console requests: insects of a kind to set down near Banjo (-1 the level's own), and starting afresh.
        struct SpawnAsk {
            int kind;
            int count;
        };
        std::vector<SpawnAsk> spawnAsks;
        bool resetAsked = false;
        // For the console: how often they have fled from Banjo, the bees buzzed him, the CPU time of the last update.
        uint64_t fleeCount = 0;
        uint64_t buzzCount = 0;
        uint64_t schoolFleeCount = 0;
        uint64_t knockCount = 0;
        double updateMs = 0.0;
        float lastPlayer[3] = {};
        bool lastHavePlayer = false;

        float Random() {
            randomState ^= randomState << 13;
            randomState ^= randomState >> 17;
            randomState ^= randomState << 5;
            return float(randomState & 0xFFFFFFu) / float(0x1000000u);
        }

        float RandomIn(float low, float high) {
            return low + (high - low) * Random();
        }

        int64_t CellKey(float x, float z) {
            const int64_t cx = int64_t(std::floor(x / SpotCell));
            const int64_t cz = int64_t(std::floor(z / SpotCell));
            return (cx << 32) ^ (cz & 0xFFFFFFFFll);
        }

        float Distance2D(const float a[3], const float b[3]) {
            const float dx = a[0] - b[0], dz = a[2] - b[2];
            return std::sqrt(dx * dx + dz * dz);
        }

        float Distance3D(const float a[3], const float b[3]) {
            const float dx = a[0] - b[0], dy = a[1] - b[1], dz = a[2] - b[2];
            return std::sqrt(dx * dx + dy * dy + dz * dz);
        }

        // A map's spots (made when it is first seen; the oldest map is let go of when there are too many).
        MapSpots &SpotsOf(uint32_t map) {
            for (auto it = maps.begin(); it != maps.end(); it++) {
                if (it->map == map) {
                    if (it != maps.begin()) {
                        maps.splice(maps.begin(), maps, it);
                    }
                    return maps.front();
                }
            }
            maps.emplace_front();
            maps.front().map = map;
            return maps.front();
        }

        void TrimSpots() {
            while ((spotTotal > SpotsMost) && (maps.size() > 1)) {
                spotTotal -= maps.back().spots.size();
                maps.pop_back();
            }
        }

        MapSpots *FrameSpots() {
            if (!frameMapKnown) {
                return nullptr;
            }
            for (MapSpots &m : maps) {
                if (m.map == frameMap) {
                    return &m;
                }
            }
            return nullptr;
        }

        // A spot between low and high away from around (across the ground), and at least avoidDistance from avoid
        // (nullptr: anywhere). Tries a few places at random; false when none of them had one.
        bool FindSpot(const MapSpots *m, const float around[3], float low, float high, const float *avoid, float avoidDistance, float out[3]) {
            if ((m == nullptr) || m->spots.empty()) {
                return false;
            }
            // Every spot in the cells the ring reaches is looked at, and one picked at random (reservoir sampling), from
            // the grass's spots when there are any there and from the bare ground's otherwise. (Picking places at random
            // and looking in their cell missed levels with patchy grass, or none near where Banjo arrives.)
            const int64_t x0 = int64_t(std::floor((around[0] - high) / SpotCell)), x1 = int64_t(std::floor((around[0] + high) / SpotCell));
            const int64_t z0 = int64_t(std::floor((around[2] - high) / SpotCell)), z1 = int64_t(std::floor((around[2] + high) / SpotCell));
            const Spot *picked[2] = { nullptr, nullptr };
            uint32_t seen[2] = { 0, 0 };
            for (int64_t cx = x0; cx <= x1; cx++) {
                for (int64_t cz = z0; cz <= z1; cz++) {
                    const auto cell = m->cells.find((cx << 32) ^ (cz & 0xFFFFFFFFll));
                    if (cell == m->cells.end()) {
                        continue;
                    }
                    for (uint32_t index : cell->second) {
                        const Spot &s = m->spots[index];
                        const float d = Distance2D(s.p, around);
                        // (Not far up or down from where it is looked for round: a ledge high above or a pit far below.)
                        if ((d < low) || (d > high) || (std::abs(s.p[1] - around[1]) > findRise)) {
                            continue;
                        }
                        if ((cameraClear > 0.0f) && (Distance3D(s.p, frameCamera) < cameraClear)) {
                            continue;
                        }
                        if (Crowded(s.p)) {
                            continue;
                        }
                        if (preferBare && (s.roomy < GroundRoom)) {
                            continue;
                        }
                        if ((avoid != nullptr) && (Distance2D(s.p, avoid) < avoidDistance)) {
                            continue;
                        }
                        const int which = s.bare ? 1 : 0;
                        seen[which]++;
                        if (Random() * float(seen[which]) < 1.0f) {
                            picked[which] = &s;
                        }
                    }
                }
            }
            const int first = preferBare ? 1 : 0;
            const Spot *s = (picked[first] != nullptr) ? picked[first] : picked[1 - first];
            if (s == nullptr) {
                return false;
            }
            out[0] = s->p[0];
            out[1] = s->p[1];
            out[2] = s->p[2];
            MarkCrowd(out);
            return true;
        }

        // Each kind: its size (its length in world units), how fast it flies (units a second), how near Banjo may come
        // before it flees, how high above the ground it rests (the grass's tips), and how long it rests at the least and
        // most (seconds).
        struct KindInfo {
            float size;
            float speed;
            float flee;
            float perchUp;
            float restLeast;
            float restMost;
        };

        KindInfo InfoOf(int kind) {
            switch (kind) {
            case CRITTER_BEE: return { 9.0f, 120.0f, 190.0f, 1.0f, 2.0f, 6.0f };
            case CRITTER_BUTTERFLY: return { 8.0f, 75.0f, 210.0f, 1.0f, 3.0f, 8.0f };
            case CRITTER_DRAGONFLY: return { 13.0f, 280.0f, 240.0f, 1.1f, 2.0f, 5.0f };
            case CRITTER_MOTH: return { 8.0f, 85.0f, 180.0f, 0.9f, 3.0f, 8.0f };
            case CRITTER_FIREFLY: return { 8.5f, 40.0f, 150.0f, 1.0f, 0.0f, 0.0f };
            case CRITTER_BEETLE: return { 7.0f, 55.0f, 130.0f, 0.75f, 6.0f, 14.0f };
            case CRITTER_FLY: return { 5.5f, 210.0f, 170.0f, 0.9f, 1.0f, 3.5f };
            case CRITTER_BIRD: return { 20.0f, 260.0f, 320.0f, 0.0f, 3.0f, 8.0f };
            case CRITTER_FROG: return { 24.0f, 0.0f, 180.0f, 0.0f, 3.0f, 9.0f };
            case CRITTER_CRAB: return { 22.0f, 90.0f, 170.0f, 0.0f, 2.0f, 6.0f };
            case CRITTER_TURTLE: return { 70.0f, 55.0f, 280.0f, 0.0f, 0.0f, 0.0f };
            case CRITTER_RAY: return { 105.0f, 80.0f, 280.0f, 0.0f, 0.0f, 0.0f };
            case CRITTER_BUBBLE: return { 4.0f, 50.0f, 0.0f, 0.0f, 0.0f, 0.0f };
            default: return { 16.0f, 70.0f, 240.0f, 0.0f, 0.0f, 0.0f };
            }
        }

        // The insects of a level, by its plants (rt64_grass.cpp's SceneGrassLevelLook) and map.
        std::vector<Mix> MixOf(uint32_t plant, uint32_t map, bool night) {
            // From dusk to dawn (Day and Night): fireflies and moths, in the level's own colours where it has some.
            if (night && (plant != GRASS_PLANT_FROST) && (plant != GRASS_PLANT_LAVA) && (plant != GRASS_PLANT_LAWN)) {
                const int moth = (plant == GRASS_PLANT_INDUSTRY) ? 2 : ((plant == GRASS_PLANT_DESERT) ? 0 : 1);
                return { { CRITTER_FIREFLY, 0, 6.0f }, { CRITTER_MOTH, moth, 3.0f } };
            }
            switch (plant) {
            case GRASS_PLANT_FERN:
                // Terrydactyland: dragonflies by the water, big blue butterflies and green beetles.
                return { { CRITTER_DRAGONFLY, 0, 3.0f }, { CRITTER_DRAGONFLY, 1, 2.0f }, { CRITTER_BUTTERFLY, 2, 2.0f }, { CRITTER_BEETLE, 1, 1.5f } };
            case GRASS_PLANT_STRAW:
                return { { CRITTER_FLY, 0, 3.0f }, { CRITTER_BEETLE, 2, 2.0f }, { CRITTER_BUTTERFLY, 1, 1.0f } };
            case GRASS_PLANT_DESERT:
                // Glitter Gulch Mine: flies and dusty beetles, and the odd brown moth.
                return { { CRITTER_FLY, 0, 5.0f }, { CRITTER_BEETLE, 2, 3.0f }, { CRITTER_MOTH, 0, 1.0f } };
            case GRASS_PLANT_LAWN:
                // Witchyworld, by night: fireflies and pale moths.
                return { { CRITTER_FIREFLY, 0, 6.0f }, { CRITTER_MOTH, 1, 3.0f } };
            case GRASS_PLANT_INDUSTRY:
                return { { CRITTER_FLY, 0, 5.0f }, { CRITTER_MOTH, 2, 3.0f } };
            case GRASS_PLANT_LAVA:
                // Hailfire Peaks' lava side: ember-glowing fireflies and fiery moths.
                return { { CRITTER_FIREFLY, 1, 4.0f }, { CRITTER_MOTH, 3, 3.0f }, { CRITTER_FLY, 0, 1.0f } };
            case GRASS_PLANT_FROST:
                // Hailfire Peaks' icy side: frosty moths and frost-white butterflies.
                return { { CRITTER_MOTH, 4, 6.0f }, { CRITTER_BUTTERFLY, 4, 2.0f } };
            case GRASS_PLANT_JUNGLE:
                // Mayahem Temple: bright butterflies, red dragonflies, bees and green beetles.
                return { { CRITTER_BUTTERFLY, 2, 2.0f }, { CRITTER_BUTTERFLY, 5, 2.0f }, { CRITTER_DRAGONFLY, 2, 2.0f }, { CRITTER_BEE, 0, 2.0f }, { CRITTER_BEETLE, 1, 1.0f } };
            case GRASS_PLANT_DUNE:
                // Jolly Roger's Lagoon by the sea: white butterflies, flies and blue dragonflies.
                return { { CRITTER_BUTTERFLY, 3, 2.0f }, { CRITTER_FLY, 0, 2.0f }, { CRITTER_DRAGONFLY, 0, 2.0f }, { CRITTER_BEE, 0, 1.0f } };
            case GRASS_PLANT_CANDY:
                // Cloud Cuckooland: bees, and pastel butterflies.
                return { { CRITTER_BEE, 0, 5.0f }, { CRITTER_BUTTERFLY, 6, 2.0f }, { CRITTER_BUTTERFLY, 7, 2.0f } };
            default:
                // The meadows (Spiral Mountain, the Isle o' Hags and the rest): bees, butterflies of every colour and ladybirds.
                (void)map;
                return { { CRITTER_BEE, 0, 4.0f }, { CRITTER_BUTTERFLY, 0, 1.5f }, { CRITTER_BUTTERFLY, 1, 1.0f }, { CRITTER_BUTTERFLY, 2, 1.0f },
                    { CRITTER_BUTTERFLY, 3, 1.0f }, { CRITTER_BEETLE, 0, 1.0f } };
            }
        }

        // The birds, frogs and crabs of a level (none on Hailfire Peaks, no birds by night).
        std::vector<Mix> AnimalsOf(uint32_t plant, bool night) {
            std::vector<Mix> mix;
            switch (plant) {
            case GRASS_PLANT_FERN: mix = { { CRITTER_BIRD, 3, 1.0f }, { CRITTER_FROG, 0, 2.0f }, { CRITTER_FROG, 1, 1.0f } }; break;
            case GRASS_PLANT_JUNGLE: mix = { { CRITTER_BIRD, 0, 2.0f }, { CRITTER_FROG, 2, 2.0f } }; break;
            case GRASS_PLANT_DUNE: mix = { { CRITTER_BIRD, 1, 3.0f }, { CRITTER_CRAB, 0, 3.0f }, { CRITTER_CRAB, 1, 1.0f } }; break;
            case GRASS_PLANT_INDUSTRY: mix = { { CRITTER_BIRD, 2, 3.0f } }; break;
            case GRASS_PLANT_DESERT: mix = { { CRITTER_BIRD, 2, 2.0f } }; break;
            case GRASS_PLANT_CANDY: mix = { { CRITTER_BIRD, 0, 2.0f }, { CRITTER_BIRD, 3, 1.0f } }; break;
            case GRASS_PLANT_LAWN: mix = { { CRITTER_FROG, 1, 2.0f } }; break;
            case GRASS_PLANT_STRAW: mix = { { CRITTER_BIRD, 3, 1.0f } }; break;
            case GRASS_PLANT_FROST:
            case GRASS_PLANT_LAVA:
            case GRASS_PLANT_KELP:
                break;
            default: mix = { { CRITTER_BIRD, 0, 2.0f }, { CRITTER_BIRD, 3, 2.0f }, { CRITTER_FROG, 0, 2.0f } }; break;
            }
            if (night) {
                mix.erase(std::remove_if(mix.begin(), mix.end(), [](const Mix &m) { return m.kind == CRITTER_BIRD; }), mix.end());
            }
            return mix;
        }

        bool IsAnimal(int kind) {
            return (kind == CRITTER_BIRD) || (kind == CRITTER_FROG) || (kind == CRITTER_CRAB);
        }

        // The grass's wind where a creature is (GrassBladeVS.hlsl's GrassWind, its sway at full): two slow waves rolling
        // across the world, the gusts along (0.8, 0.45), in the grass's own terms (0 to about 1).
        void WindAt(const float pos[3], float out[2]) {
            const float a = std::sin(pos[0] * 0.0061f + pos[2] * 0.0023f - clock * 1.1f);
            const float b = std::sin(-pos[0] * 0.0019f + pos[2] * 0.0047f - clock * 0.7f + 1.7f);
            const float gust = ((a * 0.6f + b * 0.4f) + 0.35f) * windStrength;
            out[0] = 0.8f * gust;
            out[1] = 0.45f * gust;
        }

        // How much the wind carries a kind while in the air (units a second at a gust of 1).
        float WindCarry(int kind) {
            switch (kind) {
            case CRITTER_BUTTERFLY: case CRITTER_MOTH: return 70.0f;
            case CRITTER_FIREFLY: return 55.0f;
            case CRITTER_BEE: return 30.0f;
            case CRITTER_FLY: case CRITTER_DRAGONFLY: case CRITTER_BEETLE: return 20.0f;
            case CRITTER_BIRD: return 25.0f;
            default: return 0.0f;
            }
        }

        bool Attacking() {
            return (playerAction == 49) || (playerAction == 6) || (playerAction == 0xC2) || (playerAction == 0xC4);
        }

        Mix PickMix(const std::vector<Mix> &mix) {
            float total = 0.0f;
            for (const Mix &m : mix) {
                total += m.weight;
            }
            float pick = Random() * total;
            for (const Mix &m : mix) {
                if (pick < m.weight) {
                    return m;
                }
                pick -= m.weight;
            }
            return mix.back();
        }

        // The variant a kind takes when asked for from the console where the level has none of it.
        int VariantFor(int kind, const std::vector<Mix> &mix) {
            for (const Mix &m : mix) {
                if (m.kind == kind) {
                    return m.variant;
                }
            }
            return 0;
        }

        // How high above its spot an insect rests (on the grass's tips; the birds, frogs and crabs on the ground).
        float PerchHeight(int kind) {
            if (InfoOf(kind).perchUp <= 0.0f) {
                return 0.0f;
            }
            const GrassSettings grass = SceneGrassSettings();
            const float tips = 22.0f * grass.height * SceneGrassLevelLook().height * 0.7f;
            return std::max(tips * InfoOf(kind).perchUp, 3.0f);
        }

        void StartFlight(Insect &b, const MapSpots *m, const float player[3], bool havePlayer, float low, float high) {
            const KindInfo info = InfoOf(b.kind);
            float spot[3];
            const float *avoid = havePlayer ? player : nullptr;
            if (FindSpot(m, b.pos, low, high, avoid, info.flee + 120.0f, spot)) {
                b.target[0] = spot[0];
                b.target[1] = spot[1] + PerchHeight(b.kind);
                b.target[2] = spot[2];
            }
            else {
                // (Nowhere found: on to a point in the air a little way off.)
                const float angle = RandomIn(0.0f, 6.2831853f);
                b.target[0] = b.pos[0] + std::cos(angle) * high * 0.5f;
                b.target[1] = b.pos[1];
                b.target[2] = b.pos[2] + std::sin(angle) * high * 0.5f;
            }
            b.home[0] = b.target[0];
            b.home[1] = b.target[1];
            b.home[2] = b.target[2];
            b.state = (b.kind == CRITTER_FIREFLY) ? State::Hovering : State::Flying;
            b.timer = (b.kind == CRITTER_FIREFLY) ? RandomIn(5.0f, 12.0f) : 12.0f;
        }

        // A new insect at a spot round centre (or between low and high of it), resting or, a firefly, hovering.
        bool SpawnInsect(const MapSpots *m, const Mix &mix, const float centre[3], const float player[3], bool havePlayer, float low, float high, bool fromConsole) {
            Insect *slot = nullptr;
            for (Insect &b : insects) {
                if (!b.live) {
                    slot = &b;
                    break;
                }
            }
            if (slot == nullptr) {
                return false;
            }
            const KindInfo info = InfoOf(mix.kind);
            float spot[3];
            // (From the console, they may land near him, to see them flee.)
            const float *avoid = (havePlayer && !fromConsole) ? player : nullptr;
            preferBare = (mix.kind == CRITTER_FROG) || (mix.kind == CRITTER_CRAB);
            const bool found = FindSpot(m, centre, low, high, avoid, info.flee + 60.0f, spot);
            preferBare = false;
            if (!found) {
                return false;
            }
            Insect b;
            b.live = true;
            b.kind = mix.kind;
            b.variant = mix.variant;
            b.seed = Random() * 100.0f;
            b.temper = RandomIn(0.8f, 1.25f);
            b.yaw = RandomIn(0.0f, 6.2831853f);
            b.pos[0] = spot[0];
            b.pos[1] = spot[1] + PerchHeight(b.kind);
            b.pos[2] = spot[2];
            b.home[0] = b.pos[0];
            b.home[1] = b.pos[1];
            b.home[2] = b.pos[2];
            b.spawned = fromConsole;
            if (b.kind == CRITTER_FIREFLY) {
                b.pos[1] += RandomIn(15.0f, 70.0f);
                b.state = State::Hovering;
                b.timer = RandomIn(5.0f, 12.0f);
            }
            else if ((b.kind == CRITTER_BIRD) && !fromConsole && (Random() < 0.5f)) {
                // Half the birds start wheeling high overhead (round Banjo's place, well above him).
                const float lift = RandomIn(450.0f, 750.0f);
                b.home[0] = centre[0] + RandomIn(-300.0f, 300.0f);
                b.home[1] = centre[1] + lift;
                b.home[2] = centre[2] + RandomIn(-300.0f, 300.0f);
                b.soarRadius = RandomIn(350.0f, 750.0f);
                b.soarAngle = RandomIn(0.0f, 6.2831853f);
                b.soarTurn = (Random() < 0.5f) ? -1.0f : 1.0f;
                b.pos[0] = b.home[0] + std::cos(b.soarAngle) * b.soarRadius;
                b.pos[1] = b.home[1];
                b.pos[2] = b.home[2] + std::sin(b.soarAngle) * b.soarRadius;
                b.state = State::Soaring;
                b.timer = RandomIn(12.0f, 30.0f);
            }
            else {
                b.state = State::Perched;
                b.timer = RandomIn(info.restLeast, info.restMost) * b.temper;
            }
            *slot = b;
            return true;
        }

        // A bee of a hive, hovering round it.
        bool SpawnHiveBee(int hive, bool fromConsole) {
            Insect *slot = nullptr;
            for (Insect &b : insects) {
                if (!b.live) {
                    slot = &b;
                    break;
                }
            }
            if (slot == nullptr) {
                return false;
            }
            Insect b;
            b.live = true;
            b.kind = CRITTER_BEE;
            b.temper = RandomIn(0.8f, 1.25f);
            b.hive = hive;
            b.spawned = fromConsole;
            b.seed = Random() * 100.0f;
            const float angle = RandomIn(0.0f, 6.2831853f);
            for (int i = 0; i < 3; i++) {
                b.home[i] = hives[hive].p[i];
            }
            b.pos[0] = b.home[0] + std::cos(angle) * 50.0f;
            b.pos[1] = b.home[1] + RandomIn(-20.0f, 30.0f);
            b.pos[2] = b.home[2] + std::sin(angle) * 50.0f;
            b.state = State::Hovering;
            b.timer = RandomIn(2.0f, 9.0f);
            *slot = b;
            return true;
        }

        // A frog's hop or a crab's scuttle to target (a hop's height 0 for a scuttle), taking seconds.
        void StartHop(Insect &b, const float target[3], float height, float seconds) {
            for (int i = 0; i < 3; i++) {
                b.hop0[i] = b.pos[i];
                b.target[i] = target[i];
            }
            b.hopT = 0.0f;
            b.hopTime = std::max(seconds, 0.1f);
            b.hopHeight = height;
            b.state = State::Hopping;
            const float dx = target[0] - b.pos[0], dz = target[2] - b.pos[2];
            if ((dx * dx + dz * dz) > 1.0f) {
                // (A crab goes sideways: it faces across the way it goes.)
                b.yaw = std::atan2(dz, dx) + ((b.kind == CRITTER_CRAB) ? 1.5707963f : 0.0f);
            }
        }

        // A spot on the ground near a place (for a hop's landing), or the place itself at the creature's height.
        // A spot of real ground between low and high of a place (away from avoid, when given), for a hop or scuttle to
        // land on. False when there is none: then it doesn't go (a hop to where no ground was found would leave it in
        // the air, off a ledge).
        bool GroundNear(const MapSpots *m, const float place[3], float low, float high, const float *avoid, float avoidDistance, float out[3]) {
            preferBare = true;
            const float saveClear = cameraClear;
            cameraClear = 0.0f;
            const bool found = FindSpot(m, place, low, high, avoid, avoidDistance, out);
            cameraClear = saveClear;
            preferBare = false;
            return found;
        }

        // A frog hops away from Banjo (a few hops) or a crab scuttles away, fast.
        void FleeOnGround(Insect &b, const MapSpots *m, const float player[3], bool knocked) {
            float away[2] = { b.pos[0] - player[0], b.pos[2] - player[2] };
            float length = std::sqrt(away[0] * away[0] + away[1] * away[1]);
            if (length < 1e-3f) {
                away[0] = 1.0f;
                away[1] = 0.0f;
                length = 1.0f;
            }
            const float turn = RandomIn(-0.5f, 0.5f);
            const float ax = away[0] / length, az = away[1] / length;
            const float fx = ax * std::cos(turn) - az * std::sin(turn);
            const float fz = ax * std::sin(turn) + az * std::cos(turn);
            const float reach = knocked ? 220.0f : ((b.kind == CRITTER_FROG) ? RandomIn(100.0f, 150.0f) : RandomIn(200.0f, 300.0f));
            const float place[3] = { b.pos[0] + fx * reach, b.pos[1], b.pos[2] + fz * reach };
            // Ground near where it is going; else any ground near it away from Banjo; else it stays where it is (a frog
            // jumping up on the spot, a crab bracing itself).
            float land[3];
            if (!GroundNear(m, place, 0.0f, 70.0f, nullptr, 0.0f, land) &&
                !GroundNear(m, b.pos, 50.0f, 300.0f, player, InfoOf(b.kind).flee, land)) {
                land[0] = b.pos[0];
                land[1] = b.pos[1] - PerchHeight(b.kind);
                land[2] = b.pos[2];
            }
            land[1] += PerchHeight(b.kind);
            if (b.kind == CRITTER_FROG) {
                StartHop(b, land, knocked ? 90.0f : RandomIn(30.0f, 45.0f), knocked ? 0.8f : 0.45f);
                b.hopsLeft = knocked ? 2 : int(RandomIn(1.0f, 3.99f));
            }
            else {
                StartHop(b, land, knocked ? 70.0f : 0.0f, knocked ? 0.7f : (reach / 240.0f));
                b.hopsLeft = 0;
            }
            b.spin = knocked ? 1.0f : 0.0f;
            fleeCount++;
        }

        void Flee(Insect &b, const float player[3]) {
            const KindInfo info = InfoOf(b.kind);
            float away[2] = { b.pos[0] - player[0], b.pos[2] - player[2] };
            float length = std::sqrt(away[0] * away[0] + away[1] * away[1]);
            if (length < 1e-3f) {
                const float angle = RandomIn(0.0f, 6.2831853f);
                away[0] = std::cos(angle);
                away[1] = std::sin(angle);
                length = 1.0f;
            }
            // (Off to one side a little, so a crowd of them fans out.)
            const float turn = RandomIn(-0.6f, 0.6f);
            const float ax = away[0] / length, az = away[1] / length;
            float fx = ax * std::cos(turn) - az * std::sin(turn);
            float fz = ax * std::sin(turn) + az * std::cos(turn);
            // (One between Banjo and the camera would flee straight at the lens: it veers off to the side instead.)
            {
                const float cx = frameCamera[0] - b.pos[0], cz = frameCamera[2] - b.pos[2];
                const float cl = std::sqrt(cx * cx + cz * cz);
                if ((cl > 1e-3f) && (cl < 700.0f) && ((fx * cx + fz * cz) / cl > 0.3f)) {
                    const float side = ((fx * cz - fz * cx) >= 0.0f) ? 1.0f : -1.0f;
                    const float sx = -cz / cl * side, sz = cx / cl * side;
                    fx = sx;
                    fz = sz;
                }
            }
            const float speed = (b.kind == CRITTER_BIRD) ? 360.0f : (info.speed * ((b.kind == CRITTER_BEETLE) ? 2.5f : 2.0f) + 60.0f);
            b.vel[0] = fx * speed;
            b.vel[1] = speed * RandomIn(0.35f, 0.7f);
            b.vel[2] = fz * speed;
            b.state = State::Fleeing;
            b.timer = RandomIn(1.1f, 1.9f);
            fleeCount++;
        }

        // Knocked by one of Banjo's attacks: off tumbling, away and up, spinning, then off as it would flee.
        void Knock(Insect &b, const MapSpots *m, const float player[3]) {
            knockCount++;
            if ((b.kind == CRITTER_FROG) || (b.kind == CRITTER_CRAB)) {
                FleeOnGround(b, m, player, true);
                return;
            }
            float away[3] = { b.pos[0] - player[0], 0.0f, b.pos[2] - player[2] };
            const float length = std::max(std::sqrt(away[0] * away[0] + away[2] * away[2]), 1e-3f);
            b.vel[0] = away[0] / length * 420.0f;
            b.vel[1] = 260.0f;
            b.vel[2] = away[2] / length * 420.0f;
            b.state = State::Tumbling;
            b.timer = 0.9f;
            b.spin = RandomIn(14.0f, 22.0f) * ((Random() < 0.5f) ? -1.0f : 1.0f);
        }

        // Turns a velocity into the way it faces: yaw, nose up or down, and a bank into its turns.
        void FaceAlong(float &yaw, float &pitch, float &bank, const float vel[3], float dt, float bankScale) {
            const float flat = std::sqrt(vel[0] * vel[0] + vel[2] * vel[2]);
            if (flat > 2.0f) {
                const float want = std::atan2(vel[2], vel[0]);
                float turn = want - yaw;
                while (turn > 3.14159265f) turn -= 6.2831853f;
                while (turn < -3.14159265f) turn += 6.2831853f;
                const float step = turn * std::min(1.0f, dt * 8.0f);
                yaw += step;
                bank = bank + ((std::clamp(-step / std::max(dt, 1e-3f) * 0.08f * bankScale, -0.6f, 0.6f)) - bank) * std::min(1.0f, dt * 6.0f);
            }
            const float wantPitch = std::clamp(std::atan2(vel[1], std::max(flat, 1.0f)), -0.6f, 0.6f);
            pitch += (wantPitch - pitch) * std::min(1.0f, dt * 6.0f);
        }

        void Steer(float vel[3], const float want[3], float dt, float rate) {
            const float k = 1.0f - std::exp(-dt * rate);
            for (int i = 0; i < 3; i++) {
                vel[i] += (want[i] - vel[i]) * k;
            }
        }

        void GrowOrShrink(Insect &b, float dt) {
            if (b.leaving) {
                b.grow -= dt / ShrinkSeconds;
                if (b.grow <= 0.0f) {
                    b.live = false;
                }
            }
            else {
                b.grow = std::min(1.0f, b.grow + dt / GrowSeconds);
            }
        }

        // A bird resting on the ground (pecking), flying from spot to spot or up to wheel overhead, and back down; a frog
        // sitting and hopping; a crab sitting, snapping its claws, and scuttling sideways.
        void UpdateAnimal(Insect &b, const MapSpots *m, const float player[3], bool havePlayer, bool near, float dt) {
            const KindInfo info = InfoOf(b.kind);
            b.timer -= dt;
            switch (b.state) {
            case State::Perched: {
                b.vel[0] = b.vel[1] = b.vel[2] = 0.0f;
                b.bank = 0.0f;
                if (b.kind == CRITTER_BIRD) {
                    // Pecking at the ground now and then.
                    b.pitch = -0.45f * std::max(0.0f, std::sin(clock * 3.0f + b.seed)) * ((std::fmod(clock * 0.3f + b.seed, 1.0f) < 0.4f) ? 1.0f : 0.0f);
                }
                else {
                    b.pitch = 0.0f;
                }
                if (near && (b.cooldown <= 0.0f)) {
                    if (b.kind == CRITTER_BIRD) {
                        Flee(b, player);
                    }
                    else {
                        FleeOnGround(b, m, player, false);
                    }
                }
                else if (b.timer <= 0.0f) {
                    if (b.kind == CRITTER_BIRD) {
                        if (Random() < 0.4f) {
                            // Up to wheel overhead for a while.
                            b.state = State::Soaring;
                            b.home[0] = b.pos[0];
                            b.home[1] = b.pos[1] + RandomIn(400.0f, 650.0f);
                            b.home[2] = b.pos[2];
                            b.soarRadius = RandomIn(350.0f, 700.0f);
                            b.soarAngle = std::atan2(-1.0f, 0.0f);
                            b.timer = RandomIn(10.0f, 25.0f);
                        }
                        else {
                            StartFlight(b, m, player, havePlayer, 150.0f, 600.0f);
                        }
                    }
                    else {
                        // A little hop or scuttle to somewhere near.
                        float spot[3];
                        preferBare = true;
                        const bool found = FindSpot(m, b.pos, 40.0f, (b.kind == CRITTER_FROG) ? 120.0f : 180.0f, havePlayer ? player : nullptr, info.flee + 40.0f, spot);
                        preferBare = false;
                        if (found) {
                            spot[1] += PerchHeight(b.kind);
                            const float d = Distance3D(spot, b.pos);
                            StartHop(b, spot, (b.kind == CRITTER_FROG) ? RandomIn(18.0f, 30.0f) : 0.0f, (b.kind == CRITTER_FROG) ? 0.4f : (d / info.speed));
                            b.hopsLeft = 0;
                        }
                        b.timer = RandomIn(info.restLeast, info.restMost) * b.temper;
                    }
                }
                break;
            }
            case State::Hopping: {
                // Along from where it started to where it lands, up in an arc for a hop (spinning if knocked).
                b.hopT = std::min(1.0f, b.hopT + dt / b.hopTime);
                const float t = b.hopT;
                for (int i = 0; i < 3; i++) {
                    b.pos[i] = b.hop0[i] + (b.target[i] - b.hop0[i]) * t;
                }
                b.pos[1] += 4.0f * b.hopHeight * t * (1.0f - t);
                b.bank = (b.spin != 0.0f) ? (t * 6.2831853f) : 0.0f;
                b.pitch = (b.kind == CRITTER_FROG) ? (0.5f - t) * 0.6f : 0.0f;
                b.wingPhase += dt * ((b.kind == CRITTER_CRAB) ? 30.0f : 0.0f);
                if (t >= 1.0f) {
                    b.bank = 0.0f;
                    b.pitch = 0.0f;
                    b.spin = 0.0f;
                    if ((b.hopsLeft > 0) && havePlayer) {
                        const int left = b.hopsLeft - 1;
                        FleeOnGround(b, m, player, false);
                        fleeCount--;
                        b.hopsLeft = left;
                    }
                    else {
                        b.state = State::Perched;
                        b.timer = RandomIn(info.restLeast, info.restMost) * b.temper;
                        b.cooldown = 1.0f;
                    }
                }
                break;
            }
            case State::Soaring: {
                // Wheeling round home, high up, gliding with a flap now and then, drifting with the wind; then down to
                // land somewhere well away from Banjo.
                const float speed = 150.0f;
                b.soarAngle += b.soarTurn * speed / std::max(b.soarRadius, 100.0f) * dt;
                float wind[2];
                WindAt(b.pos, wind);
                b.home[0] += wind[0] * WindCarry(b.kind) * dt;
                b.home[2] += wind[1] * WindCarry(b.kind) * dt;
                const float aim[3] = { b.home[0] + std::cos(b.soarAngle) * b.soarRadius, b.home[1] + 25.0f * std::sin(clock * 0.5f + b.seed),
                    b.home[2] + std::sin(b.soarAngle) * b.soarRadius };
                float want[3];
                for (int i = 0; i < 3; i++) {
                    want[i] = (aim[i] - b.pos[i]) * 2.0f;
                }
                Steer(b.vel, want, dt, 3.0f);
                for (int i = 0; i < 3; i++) {
                    b.pos[i] += b.vel[i] * dt;
                }
                FaceAlong(b.yaw, b.pitch, b.bank, b.vel, dt, 2.0f);
                if (b.timer <= 0.0f) {
                    StartFlight(b, m, havePlayer ? player : b.pos, havePlayer, info.flee + 200.0f, info.flee + 900.0f);
                    b.timer = 20.0f;
                }
                break;
            }
            case State::Fleeing: {
                // A bird: up and away, then wheeling overhead.
                b.vel[1] += dt * 60.0f;
                for (int i = 0; i < 3; i++) {
                    b.pos[i] += b.vel[i] * dt;
                }
                FaceAlong(b.yaw, b.pitch, b.bank, b.vel, dt, 1.0f);
                if (b.timer <= 0.0f) {
                    b.state = State::Soaring;
                    b.home[0] = b.pos[0];
                    b.home[1] = b.pos[1] + 250.0f;
                    b.home[2] = b.pos[2];
                    b.soarRadius = RandomIn(350.0f, 650.0f);
                    b.soarAngle = std::atan2(b.pos[2] - b.home[2], b.pos[0] - b.home[0]) + 1.0f;
                    b.timer = RandomIn(8.0f, 18.0f);
                }
                break;
            }
            default: {
                // A bird flying down to land (Flying), like an insect's flight but higher over the way.
                if (near && (b.cooldown <= 0.0f)) {
                    Flee(b, player);
                    break;
                }
                float to[3] = { b.target[0] - b.pos[0], b.target[1] - b.pos[1], b.target[2] - b.pos[2] };
                const float flat = std::sqrt(to[0] * to[0] + to[2] * to[2]);
                to[1] += std::min(flat * 0.4f, 200.0f);
                const float distance = std::sqrt(to[0] * to[0] + to[1] * to[1] + to[2] * to[2]);
                const float speed = info.speed * std::clamp(distance / 80.0f, 0.3f, 1.0f) * b.temper;
                float want[3];
                for (int i = 0; i < 3; i++) {
                    want[i] = to[i] / std::max(distance, 1e-3f) * speed;
                }
                Steer(b.vel, want, dt, 3.0f);
                for (int i = 0; i < 3; i++) {
                    b.pos[i] += b.vel[i] * dt;
                }
                FaceAlong(b.yaw, b.pitch, b.bank, b.vel, dt, 1.5f);
                if ((Distance3D(b.pos, b.target) < 10.0f) || (b.timer <= 0.0f)) {
                    b.state = State::Perched;
                    b.timer = RandomIn(info.restLeast, info.restMost) * b.temper;
                    b.pitch = 0.0f;
                    b.bank = 0.0f;
                    for (int i = 0; i < 3; i++) {
                        b.pos[i] = b.target[i];
                    }
                }
                break;
            }
            }
            b.cooldown = std::max(0.0f, b.cooldown - dt);
            // A bird's wings beat fast flying, slowly soaring (a few flaps between glides), folded resting.
            const float rate = (b.kind == CRITTER_BIRD) ? ((b.state == State::Soaring) ? 5.0f : ((b.state == State::Perched) ? 0.0f : 15.0f)) : 0.0f;
            if (b.kind != CRITTER_CRAB) {
                b.wingPhase = std::fmod(b.wingPhase + dt * rate, 6.2831853f * 64.0f);
            }
            else if (b.state == State::Perched) {
                b.wingPhase = std::fmod(b.wingPhase + dt * 3.0f, 6.2831853f * 64.0f);
            }
            GrowOrShrink(b, dt);
        }

        void UpdateInsect(Insect &b, const MapSpots *m, const float player[3], bool havePlayer, float dt) {
            const KindInfo info = InfoOf(b.kind);
            b.cooldown = std::max(0.0f, b.cooldown - dt);
            const float playerDistance = havePlayer ? Distance3D(b.pos, player) : 1e9f;
            const bool near = playerDistance < info.flee * (2.0f - b.temper);
            // Banjo's attacks knock anything near him tumbling.
            if (havePlayer && Attacking() && (playerDistance < KnockReach) && (b.state != State::Tumbling) && (b.spin == 0.0f)) {
                Knock(b, m, player);
            }
            // The birds, frogs and crabs.
            if (IsAnimal(b.kind) && (b.state != State::Tumbling)) {
                UpdateAnimal(b, m, player, havePlayer, near, dt);
                return;
            }
            switch (b.state) {
            case State::Perched: {
                b.vel[0] = b.vel[1] = b.vel[2] = 0.0f;
                b.timer -= dt;
                b.bank *= std::max(0.0f, 1.0f - dt * 4.0f);
                b.pitch *= std::max(0.0f, 1.0f - dt * 4.0f);
                if (near && (b.cooldown <= 0.0f)) {
                    // A bee may buzz round Banjo for a moment before it goes.
                    if ((b.kind == CRITTER_BEE) && (Random() < 0.4f)) {
                        b.state = State::Buzzing;
                        b.timer = RandomIn(2.2f, 3.8f);
                        b.buzzAngle = std::atan2(b.pos[2] - player[2], b.pos[0] - player[0]);
                        buzzCount++;
                    }
                    else {
                        Flee(b, player);
                    }
                }
                else if (b.timer <= 0.0f) {
                    if ((b.hive >= 0) && (b.hive < int(hives.size()))) {
                        // Back to the hive with what it gathered.
                        for (int i = 0; i < 3; i++) {
                            b.target[i] = hives[b.hive].p[i];
                        }
                        b.toHive = true;
                        b.state = State::Flying;
                        b.timer = 12.0f;
                    }
                    else {
                        StartFlight(b, m, player, havePlayer, 90.0f, (b.kind == CRITTER_BEETLE) ? 220.0f : 420.0f);
                    }
                }
                break;
            }
            case State::Flying:
            case State::Hovering: {
                b.timer -= dt;
                if (near && (b.cooldown <= 0.0f) && (b.state == State::Flying || (playerDistance < info.flee * 0.8f))) {
                    if ((b.kind == CRITTER_BEE) && (Random() < 0.3f)) {
                        b.state = State::Buzzing;
                        b.timer = RandomIn(2.0f, 3.2f);
                        b.buzzAngle = std::atan2(b.pos[2] - player[2], b.pos[0] - player[0]);
                        buzzCount++;
                    }
                    else {
                        Flee(b, player);
                    }
                    break;
                }
                float to[3] = { b.target[0] - b.pos[0], b.target[1] - b.pos[1], b.target[2] - b.pos[2] };
                const float flat = std::sqrt(to[0] * to[0] + to[2] * to[2]);
                float want[3];
                if (b.state == State::Hovering) {
                    if ((b.hive >= 0) && (b.hive < int(hives.size()))) {
                        // A hive bee buzzes in a loose cloud round the hive's mouth, then goes out to the flowers.
                        const float t = clock * 2.6f + b.seed;
                        const float drift[3] = { b.home[0] + std::cos(t) * 55.0f, b.home[1] + std::sin(t * 1.9f) * 25.0f, b.home[2] + std::sin(t * 1.3f) * 55.0f };
                        for (int i = 0; i < 3; i++) {
                            want[i] = (drift[i] - b.pos[i]) * 3.0f;
                        }
                        Steer(b.vel, want, dt, 5.0f);
                        if (b.timer <= 0.0f) {
                            float spot[3];
                            const float saveRise = findRise;
                            findRise = 700.0f;
                            const bool found = FindSpot(m, b.home, 80.0f, HiveForage, havePlayer ? player : nullptr, info.flee + 60.0f, spot);
                            findRise = saveRise;
                            if (found) {
                                b.target[0] = spot[0];
                                b.target[1] = spot[1] + PerchHeight(b.kind);
                                b.target[2] = spot[2];
                                b.toHive = false;
                                b.state = State::Flying;
                                b.timer = 12.0f;
                            }
                            else {
                                b.timer = RandomIn(2.0f, 5.0f);
                            }
                        }
                        break;
                    }
                    // A firefly drifts slowly round its home in the air, bobbing.
                    const float t = clock * 0.35f + b.seed;
                    const float drift[3] = { b.home[0] + std::cos(t) * 60.0f, b.home[1] + 35.0f + std::sin(t * 1.7f) * 22.0f, b.home[2] + std::sin(t * 1.3f) * 60.0f };
                    for (int i = 0; i < 3; i++) {
                        want[i] = (drift[i] - b.pos[i]) * 0.8f;
                    }
                    Steer(b.vel, want, dt, 2.0f);
                    if (b.timer <= 0.0f) {
                        StartFlight(b, m, player, havePlayer, 60.0f, 300.0f);
                    }
                    break;
                }
                // Up over the way and down onto the spot, wobbling as it goes (a butterfly or moth flutters a lot).
                const float lift = std::min(flat * 0.35f, 70.0f);
                to[1] += lift;
                const float distance = std::sqrt(to[0] * to[0] + to[1] * to[1] + to[2] * to[2]);
                const float slow = std::clamp(distance / 40.0f, 0.25f, 1.0f);
                const float speed = info.speed * slow * b.temper;
                for (int i = 0; i < 3; i++) {
                    want[i] = to[i] / std::max(distance, 1e-3f) * speed;
                }
                const float wobbleSize = ((b.kind == CRITTER_BUTTERFLY) || (b.kind == CRITTER_MOTH)) ? 0.9f : ((b.kind == CRITTER_FLY) ? 0.7f : 0.3f);
                const float wobbleRate = (b.kind == CRITTER_FLY) ? 9.0f : 4.0f;
                want[0] += std::sin(clock * wobbleRate + b.seed) * speed * wobbleSize;
                want[1] += std::sin(clock * wobbleRate * 1.37f + b.seed * 2.0f) * speed * wobbleSize * 0.6f;
                want[2] += std::cos(clock * wobbleRate * 0.83f + b.seed * 3.0f) * speed * wobbleSize;
                Steer(b.vel, want, dt, (b.kind == CRITTER_DRAGONFLY) ? 7.0f : 4.0f);
                if ((Distance3D(b.pos, b.target) < (b.toHive ? 40.0f : 8.0f)) || (b.timer <= 0.0f)) {
                    // Landed (a dragonfly may hover a moment and go on instead; a hive bee home again buzzes round it).
                    if (b.toHive) {
                        b.toHive = false;
                        b.state = State::Hovering;
                        b.timer = RandomIn(4.0f, 10.0f);
                    }
                    else if ((b.kind == CRITTER_DRAGONFLY) && (Random() < 0.4f)) {
                        StartFlight(b, m, player, havePlayer, 120.0f, 500.0f);
                    }
                    else {
                        b.state = State::Perched;
                        b.timer = RandomIn(info.restLeast, info.restMost) * b.temper;
                        if (b.timer > 0.0f) {
                            b.pos[0] = b.target[0];
                            b.pos[1] = b.target[1];
                            b.pos[2] = b.target[2];
                        }
                    }
                }
                break;
            }
            case State::Fleeing: {
                b.timer -= dt;
                // Away and up, slowing as it goes.
                b.vel[1] -= dt * 40.0f;
                for (int i = 0; i < 3; i++) {
                    b.vel[i] *= std::max(0.0f, 1.0f - dt * 0.6f);
                }
                if ((b.timer <= 0.0f) && (b.hive >= 0) && (b.hive < int(hives.size()))) {
                    // A hive bee heads home.
                    b.cooldown = 1.5f;
                    for (int i = 0; i < 3; i++) {
                        b.target[i] = hives[b.hive].p[i];
                    }
                    b.toHive = true;
                    b.state = State::Flying;
                    b.timer = 12.0f;
                }
                else if (b.timer <= 0.0f) {
                    // Somewhere well away from him to settle (once he has gone, they come back to rest near again).
                    b.cooldown = 1.5f;
                    StartFlight(b, m, havePlayer ? player : b.pos, havePlayer, info.flee + 150.0f, info.flee + 600.0f);
                    if (havePlayer) {
                        // (Looked for round him, so the spot is away from him whichever way it fled.)
                        float spot[3];
                        if (FindSpot(m, player, info.flee + 180.0f, info.flee + 650.0f, player, info.flee + 150.0f, spot)) {
                            b.target[0] = spot[0];
                            b.target[1] = spot[1] + PerchHeight(b.kind);
                            b.target[2] = spot[2];
                        }
                    }
                }
                break;
            }
            case State::Tumbling: {
                // Knocked: flung away and up, spinning, slowing, then fleeing as usual.
                b.timer -= dt;
                b.vel[1] -= dt * 350.0f;
                for (int i = 0; i < 3; i++) {
                    b.vel[i] *= std::max(0.0f, 1.0f - dt * 1.2f);
                }
                b.bank += b.spin * dt;
                b.pitch += b.spin * 0.6f * dt;
                if (b.timer <= 0.0f) {
                    b.spin = 0.0f;
                    b.bank = 0.0f;
                    b.pitch = 0.0f;
                    if (IsAnimal(b.kind)) {
                        b.state = State::Soaring;
                        b.home[0] = b.pos[0];
                        b.home[1] = b.pos[1] + 400.0f;
                        b.home[2] = b.pos[2];
                        b.soarRadius = RandomIn(350.0f, 650.0f);
                        b.timer = RandomIn(8.0f, 15.0f);
                    }
                    else {
                        Flee(b, player);
                        b.cooldown = 3.0f;
                    }
                }
                break;
            }
            case State::Buzzing: {
                b.timer -= dt;
                // Round and round his head, a little up and down.
                b.buzzAngle += dt * 5.0f;
                const float r = 55.0f + 10.0f * std::sin(clock * 3.1f + b.seed);
                const float aim[3] = { player[0] + std::cos(b.buzzAngle) * r, player[1] + 70.0f + 12.0f * std::sin(clock * 4.3f + b.seed), player[2] + std::sin(b.buzzAngle) * r };
                float want[3];
                for (int i = 0; i < 3; i++) {
                    want[i] = (aim[i] - b.pos[i]) * 6.0f;
                }
                Steer(b.vel, want, dt, 8.0f);
                if (b.timer <= 0.0f) {
                    Flee(b, player);
                    b.cooldown = 4.0f;
                }
                break;
            }
            }
            for (int i = 0; i < 3; i++) {
                b.pos[i] += b.vel[i] * dt;
            }
            // The wind carries what is in the air a little, more the lighter it is (a butterfly most).
            if ((b.state != State::Perched) && (b.state != State::Tumbling)) {
                float wind[2];
                WindAt(b.pos, wind);
                const float carry = WindCarry(b.kind);
                b.pos[0] += wind[0] * carry * dt;
                b.pos[2] += wind[1] * carry * dt;
            }
            if ((b.state != State::Perched) && (b.state != State::Tumbling)) {
                FaceAlong(b.yaw, b.pitch, b.bank, b.vel, dt, 1.0f);
            }
            // The wings: a bee's, fly's and dragonfly's a fast blur, a butterfly's and moth's slow beats, all of them still
            // (and a butterfly's held up together, opening and closing now and then) while it rests.
            const bool resting = (b.state == State::Perched);
            float rate = 0.0f;
            switch (b.kind) {
            case CRITTER_BUTTERFLY: {
                // (Resting, its wings open and close faster in a gust.)
                float wind[2];
                WindAt(b.pos, wind);
                rate = resting ? (1.2f + 4.0f * std::sqrt(wind[0] * wind[0] + wind[1] * wind[1])) : 13.0f;
                break;
            }
            case CRITTER_MOTH: rate = resting ? 0.0f : 20.0f; break;
            case CRITTER_BEETLE: rate = resting ? 0.0f : 40.0f; break;
            default: rate = resting ? 0.0f : 46.0f; break;
            }
            b.wingPhase = std::fmod(b.wingPhase + dt * rate, 6.2831853f * 64.0f);
            // Growing in, or shrinking away when leaving.
            if (b.leaving) {
                b.grow -= dt / ShrinkSeconds;
                if (b.grow <= 0.0f) {
                    b.live = false;
                }
            }
            else {
                b.grow = std::min(1.0f, b.grow + dt / GrowSeconds);
            }
        }

        float WingAngle(const Insect &b) {
            const bool resting = (b.state == State::Perched);
            const float s = std::sin(b.wingPhase);
            switch (b.kind) {
            case CRITTER_BIRD:
                // Soaring: held out flat, a quick flap now and then.
                if (b.state == State::Soaring) {
                    return 0.08f + 0.5f * std::max(0.0f, s) * ((std::fmod(clock * 0.25f + b.seed, 1.0f) < 0.3f) ? 1.0f : 0.0f);
                }
                return resting ? 0.0f : (0.25f + 0.85f * s);
            case CRITTER_FROG: {
                // How far its back legs are kicked out: all the way through most of a hop, tucked again as it lands.
                if (b.state != State::Hopping) {
                    return 0.0f;
                }
                return (b.hopT < 0.65f) ? 1.0f : std::max(0.0f, 1.0f - (b.hopT - 0.65f) / 0.35f);
            }
            case CRITTER_CRAB:
                return b.wingPhase;
            case CRITTER_BUTTERFLY: return resting ? (1.25f + 0.25f * s) : (0.35f + 0.85f * s);
            case CRITTER_MOTH: return resting ? -0.15f : (0.2f + 0.7f * s);
            case CRITTER_DRAGONFLY: return resting ? -0.05f : (0.05f + 0.35f * s);
            case CRITTER_BEE: return resting ? 0.05f : (0.25f + 0.6f * s);
            default: return resting ? 0.0f : (0.2f + 0.6f * s);
            }
        }

        void EmitBubble(const float from[3], float size) {
            for (Bubble &u : bubbles) {
                if (!u.live) {
                    u.live = true;
                    for (int i = 0; i < 3; i++) {
                        u.pos[i] = from[i];
                    }
                    u.age = 0.0f;
                    u.life = RandomIn(2.5f, 4.5f);
                    u.rise = RandomIn(45.0f, 75.0f);
                    u.size = size * RandomIn(0.7f, 1.3f);
                    u.seed = Random() * 100.0f;
                    return;
                }
            }
        }

        // How high a school swims over a spot of seabed: a little way above it, but not far below Banjo (the seabed may be a
        // long way down), so they swim where he is.
        float FishHeight(float ground, float near) {
            float y = ground + RandomIn(70.0f, 200.0f);
            if (y < near - 300.0f) {
                y = near - RandomIn(0.0f, 250.0f);
            }
            return std::max(y, ground + 40.0f);
        }

        bool SpawnSchool(const MapSpots *m, const float centre[3], const float player[3], bool havePlayer, float low, float high) {
            School *slot = nullptr;
            for (School &s : schools) {
                if (!s.live) {
                    slot = &s;
                    break;
                }
            }
            if (slot == nullptr) {
                return false;
            }
            float spot[3];
            if (!FindSpot(m, centre, low, high, havePlayer ? player : nullptr, 450.0f, spot)) {
                return false;
            }
            // (Not over seabed far above him: a school there would swim out of his sight.)
            if (spot[1] > centre[1] + 350.0f) {
                return false;
            }
            School s;
            s.live = true;
            s.variant = int(Random() * 6.0f) % 6;
            // (Now and then a big one on its own.)
            const bool lone = Random() < 0.2f;
            s.count = lone ? 1 : int(RandomIn(float(SchoolFishLeast), float(SchoolFishMost) + 0.99f));
            s.size = lone ? RandomIn(24.0f, 32.0f) : RandomIn(13.0f, 19.0f);
            s.center[0] = spot[0];
            s.center[1] = FishHeight(spot[1], centre[1]);
            s.center[2] = spot[2];
            s.target[0] = s.center[0];
            s.target[1] = s.center[1];
            s.target[2] = s.center[2];
            s.yaw = RandomIn(0.0f, 6.2831853f);
            s.seed = Random() * 100.0f;
            s.timer = 0.0f;
            *slot = s;
            return true;
        }

        void UpdateSchool(School &s, const MapSpots *m, const float player[3], bool havePlayer, float dt) {
            const float playerDistance = havePlayer ? Distance3D(s.center, player) : 1e9f;
            // (The edge of the school, not only its middle, is what he comes near.)
            const float fleeAt = 240.0f + 18.0f * float(s.count);
            // A fish now and then lets a bubble go.
            s.bubbleIn -= dt;
            if (s.bubbleIn <= 0.0f) {
                s.bubbleIn = RandomIn(1.2f, 3.0f);
                const float from[3] = { s.center[0] + RandomIn(-30.0f, 30.0f), s.center[1] + RandomIn(-10.0f, 15.0f), s.center[2] + RandomIn(-30.0f, 30.0f) };
                EmitBubble(from, 3.5f);
            }
            const bool knocked = havePlayer && Attacking() && (playerDistance < KnockReach + 60.0f);
            if (knocked && (s.flee > 0.0f) && (s.spread < 2.4f)) {
                s.spread = 2.6f;
                knockCount++;
            }
            if (havePlayer && ((playerDistance < fleeAt) || knocked) && (s.flee <= 0.0f)) {
                // Darts away from him, spreading out, and on somewhere well away after.
                float away[3] = { s.center[0] - player[0], (s.center[1] - player[1]) * 0.4f, s.center[2] - player[2] };
                const float length = std::max(std::sqrt(away[0] * away[0] + away[1] * away[1] + away[2] * away[2]), 1e-3f);
                for (int i = 0; i < 3; i++) {
                    s.vel[i] = away[i] / length * 420.0f;
                }
                s.flee = RandomIn(1.0f, 1.6f);
                schoolFleeCount++;
                float spot[3];
                if (FindSpot(m, player, 600.0f, 1000.0f, player, 550.0f, spot)) {
                    s.target[0] = spot[0];
                    s.target[1] = FishHeight(spot[1], havePlayer ? player[1] : s.center[1]);
                    s.target[2] = spot[2];
                }
                else {
                    s.target[0] = s.center[0] + away[0] / length * 600.0f;
                    s.target[1] = s.center[1];
                    s.target[2] = s.center[2] + away[2] / length * 600.0f;
                }
                s.timer = 8.0f;
            }
            if (s.flee > 0.0f) {
                s.flee -= dt;
                for (int i = 0; i < 3; i++) {
                    s.vel[i] *= std::max(0.0f, 1.0f - dt * 0.9f);
                }
                s.spread += (1.8f - s.spread) * std::min(1.0f, dt * 5.0f);
            }
            else {
                // Cruising on to its next place, slowly, in a gentle weave.
                s.timer -= dt;
                float to[3] = { s.target[0] - s.center[0], s.target[1] - s.center[1], s.target[2] - s.center[2] };
                const float distance = std::sqrt(to[0] * to[0] + to[1] * to[1] + to[2] * to[2]);
                if ((distance < 50.0f) || (s.timer <= 0.0f)) {
                    float spot[3];
                    const float *around = havePlayer ? player : s.center;
                    if (FindSpot(m, around, 300.0f, 1000.0f, havePlayer ? player : nullptr, 350.0f, spot)) {
                        s.target[0] = spot[0];
                        s.target[1] = FishHeight(spot[1], havePlayer ? player[1] : s.center[1]);
                        s.target[2] = spot[2];
                    }
                    s.timer = RandomIn(8.0f, 16.0f);
                }
                const float speed = 75.0f * std::clamp(distance / 80.0f, 0.4f, 1.0f);
                float want[3];
                for (int i = 0; i < 3; i++) {
                    want[i] = to[i] / std::max(distance, 1e-3f) * speed;
                }
                want[0] += std::sin(clock * 0.9f + s.seed) * 25.0f;
                want[2] += std::cos(clock * 0.7f + s.seed) * 25.0f;
                Steer(s.vel, want, dt, 1.5f);
                s.spread += (1.0f - s.spread) * std::min(1.0f, dt * 1.5f);
            }
            for (int i = 0; i < 3; i++) {
                s.center[i] += s.vel[i] * dt;
            }
            float bank = 0.0f;
            FaceAlong(s.yaw, s.pitch, bank, s.vel, dt, 0.0f);
            const float speed = std::sqrt(s.vel[0] * s.vel[0] + s.vel[1] * s.vel[1] + s.vel[2] * s.vel[2]);
            s.swish = std::fmod(s.swish + dt * (5.0f + speed * 0.05f), 6.2831853f * 64.0f);
            if (s.leaving) {
                s.grow -= dt / ShrinkSeconds;
                if (s.grow <= 0.0f) {
                    s.live = false;
                }
            }
            else {
                s.grow = std::min(1.0f, s.grow + dt / GrowSeconds);
            }
        }

        bool SpawnGlider(const MapSpots *m, int kind, const float centre[3], const float player[3], bool havePlayer, float low, float high) {
            Glider *slot = nullptr;
            for (Glider &g : gliders) {
                if (!g.live) {
                    slot = &g;
                    break;
                }
            }
            if (slot == nullptr) {
                return false;
            }
            float spot[3];
            if (!FindSpot(m, centre, low, high, havePlayer ? player : nullptr, 500.0f, spot)) {
                return false;
            }
            if (spot[1] > centre[1] + 350.0f) {
                return false;
            }
            Glider g;
            g.live = true;
            g.kind = kind;
            g.seed = Random() * 100.0f;
            g.size = InfoOf(kind).size * RandomIn(0.85f, 1.15f);
            g.radius = RandomIn(350.0f, 600.0f);
            g.turn = (Random() < 0.5f) ? -1.0f : 1.0f;
            g.angle = RandomIn(0.0f, 6.2831853f);
            g.middle[0] = spot[0] - std::cos(g.angle) * g.radius;
            g.middle[1] = FishHeight(spot[1], centre[1]) + 60.0f;
            g.middle[2] = spot[2] - std::sin(g.angle) * g.radius;
            g.pos[0] = spot[0];
            g.pos[1] = g.middle[1];
            g.pos[2] = spot[2];
            *slot = g;
            return true;
        }

        // A turtle or ray: round and round its middle, slowly, rowing or waving its wings, its middle drifting towards
        // Banjo so it stays about; when he comes near it speeds off away from him for a while.
        void UpdateGlider(Glider &g, const float player[3], bool havePlayer, float dt) {
            const KindInfo info = InfoOf(g.kind);
            const float playerDistance = havePlayer ? Distance3D(g.pos, player) : 1e9f;
            if (havePlayer && (g.flee <= 0.0f) && ((playerDistance < info.flee) || (Attacking() && (playerDistance < KnockReach + 80.0f)))) {
                g.flee = 3.0f;
                schoolFleeCount++;
                // (Its middle moves away from him, and it turns the way that takes it off.)
                const float ax = g.pos[0] - player[0], az = g.pos[2] - player[2];
                const float al = std::max(std::sqrt(ax * ax + az * az), 1e-3f);
                g.middle[0] = g.pos[0] + ax / al * g.radius * 0.8f;
                g.middle[2] = g.pos[2] + az / al * g.radius * 0.8f;
                g.angle = std::atan2(g.pos[2] - g.middle[2], g.pos[0] - g.middle[0]);
            }
            g.flee = std::max(0.0f, g.flee - dt);
            const float speed = info.speed * ((g.flee > 0.0f) ? 2.6f : 1.0f);
            g.angle += g.turn * speed / g.radius * dt;
            if (havePlayer && (g.flee <= 0.0f)) {
                // (Drifting towards Banjo's place, slowly, so it keeps coming past.)
                for (int i = 0; i < 3; i += 2) {
                    g.middle[i] += (player[i] - g.middle[i]) * std::min(1.0f, dt * 0.03f);
                }
            }
            const float aim[3] = { g.middle[0] + std::cos(g.angle) * g.radius, g.middle[1] + 30.0f * std::sin(clock * 0.3f + g.seed),
                g.middle[2] + std::sin(g.angle) * g.radius };
            float want[3];
            for (int i = 0; i < 3; i++) {
                want[i] = (aim[i] - g.pos[i]) * 1.5f;
            }
            Steer(g.vel, want, dt, 1.2f);
            for (int i = 0; i < 3; i++) {
                g.pos[i] += g.vel[i] * dt;
            }
            FaceAlong(g.yaw, g.pitch, g.bank, g.vel, dt, (g.kind == CRITTER_RAY) ? 1.5f : 0.6f);
            g.phase = std::fmod(g.phase + dt * ((g.kind == CRITTER_RAY) ? 1.6f : 1.9f) * ((g.flee > 0.0f) ? 2.2f : 1.0f), 6.2831853f * 64.0f);
            // A turtle breathes out a bubble now and then.
            g.bubbleIn -= dt;
            if ((g.kind == CRITTER_TURTLE) && (g.bubbleIn <= 0.0f)) {
                g.bubbleIn = RandomIn(1.5f, 4.0f);
                const float head[3] = { g.pos[0] + std::cos(g.yaw) * g.size * 0.5f, g.pos[1] + g.size * 0.1f, g.pos[2] + std::sin(g.yaw) * g.size * 0.5f };
                EmitBubble(head, 6.0f);
            }
            if (g.leaving) {
                g.grow -= dt / ShrinkSeconds;
                if (g.grow <= 0.0f) {
                    g.live = false;
                }
            }
            else {
                g.grow = std::min(1.0f, g.grow + dt / (GrowSeconds * 1.5f));
            }
        }

        void UpdateBubble(Bubble &u, float dt) {
            u.age += dt;
            u.pos[1] += u.rise * dt;
            u.pos[0] += std::sin(clock * 3.0f + u.seed) * 12.0f * dt;
            u.pos[2] += std::cos(clock * 2.6f + u.seed) * 12.0f * dt;
            if (u.age >= u.life) {
                u.live = false;
            }
        }

        // The size a creature is drawn at: grown in, and shrunk away towards the edge of the camera's reach.
        float DrawnScale(float size, float grow, const float pos[3], const float camera[3]) {
            const float distance = Distance3D(pos, camera);
            const float fade = std::clamp((FadeTo - distance) / (FadeTo - FadeFrom), 0.0f, 1.0f) *
                std::clamp((distance - NearFadeFrom) / (NearFadeTo - NearFadeFrom), 0.0f, 1.0f);
            const float g = grow * grow * (3.0f - 2.0f * grow);
            return size * g * fade;
        }

        // The level's light on them: a little dimmer in the night levels and under the sea.
        uint32_t BrightnessOf(uint32_t plant, bool water) {
            if (water) {
                return 225;
            }
            return (plant == GRASS_PLANT_LAWN) ? 175 : 255;
        }

        const char *KindName(int kind) {
            static const char *names[CRITTER_KINDS] = { "bee", "butterfly", "dragonfly", "moth", "firefly", "beetle", "fly", "fish", "bird", "frog", "crab", "turtle", "ray", "bubble", "eye" };
            return ((kind >= 0) && (kind < CRITTER_KINDS)) ? names[kind] : "?";
        }

        const char *StateName(State s) {
            switch (s) {
            case State::Perched: return "resting";
            case State::Flying: return "flying";
            case State::Fleeing: return "fleeing";
            case State::Buzzing: return "buzzing";
            case State::Hovering: return "hovering";
            case State::Hopping: return "hopping";
            case State::Soaring: return "soaring";
            default: return "tumbling";
            }
        }
    }

    void SetSceneCritters(bool insectsOn, bool fishOn, float amount) {
        std::lock_guard lock{ mutex };
        settings.insects = insectsOn;
        settings.fish = fishOn;
        settings.amount = std::clamp(amount, 0.0f, 2.0f);
    }

    void SetSceneCritterDaylight(bool cycle, float light) {
        std::lock_guard lock{ mutex };
        dayCycle = cycle;
        daylight = light;
    }

    void SetSceneCritterPlayerAction(uint32_t state) {
        std::lock_guard lock{ mutex };
        playerAction = state;
    }

    void SetSceneCritterHives(const uint32_t *hiveMaps, const float *places, size_t count) {
        std::lock_guard lock{ mutex };
        hives.clear();
        for (size_t i = 0; i < count; i++) {
            hives.push_back({ hiveMaps[i], { places[i * 3 + 0], places[i * 3 + 1], places[i * 3 + 2] } });
        }
        // (The bees of a hive that is gone go too.)
        for (Insect &b : insects) {
            if (b.live && (b.hive >= int(hives.size()))) {
                b.hive = -1;
                b.leaving = true;
            }
        }
    }

    CritterSettings SceneCritterSettings() {
        std::lock_guard lock{ mutex };
        return settings;
    }

    void SceneCrittersSpawn(int kind, int count) {
        std::lock_guard lock{ mutex };
        spawnAsks.push_back({ kind, std::clamp(count, 1, CRITTER_MAX) });
    }

    void SceneCrittersReset() {
        std::lock_guard lock{ mutex };
        resetAsked = true;
    }

    void SceneCrittersStatsText(char *out, size_t size) {
        std::lock_guard lock{ mutex };
        int byKind[CRITTER_KINDS] = {};
        int byState[8] = {};
        for (const Insect &b : insects) {
            if (b.live) {
                byKind[b.kind]++;
                byState[int(b.state)]++;
            }
        }
        int schoolCount = 0;
        for (const School &s : schools) {
            if (s.live) {
                schoolCount++;
                byKind[CRITTER_FISH] += s.count;
            }
        }
        for (const Glider &g : gliders) {
            if (g.live) {
                byKind[g.kind]++;
            }
        }
        for (const Bubble &u : bubbles) {
            if (u.live) {
                byKind[CRITTER_BUBBLE]++;
            }
        }
        int hiveCount = 0;
        for (const Hive &h : hives) {
            hiveCount += (h.map == frameMap) ? 1 : 0;
        }
        const MapSpots *m = FrameSpots();
        // (The nearest spot to Banjo across the ground, and how far above or below him it is, to see why none land.)
        float nearest = 1e9f, nearestRise = 0.0f;
        if ((m != nullptr) && lastHavePlayer) {
            for (const Spot &spot : m->spots) {
                const float d = Distance2D(spot.p, lastPlayer);
                if (d < nearest) {
                    nearest = d;
                    nearestRise = spot.p[1] - lastPlayer[1];
                }
            }
        }
        // (Resting frogs and crabs with no ground under them, to catch any left in the air.)
        int offGround = 0;
        if (m != nullptr) {
            for (const Insect &b : insects) {
                if (!b.live || ((b.kind != CRITTER_FROG) && (b.kind != CRITTER_CRAB)) || (b.state != State::Perched)) {
                    continue;
                }
                bool ground = false;
                for (const Spot &spot : m->spots) {
                    if ((Distance2D(spot.p, b.pos) < 40.0f) && (std::abs(spot.p[1] + PerchHeight(b.kind) - b.pos[1]) < 15.0f)) {
                        ground = true;
                        break;
                    }
                }
                offGround += ground ? 0 : 1;
            }
        }
        std::snprintf(out, size,
            "critters (land %s, sea %s, amount %d%%): %d bees, %d butterflies, %d dragonflies, %d moths, %d fireflies, %d beetles, %d flies, "
            "%d birds, %d frogs, %d crabs; %d fish in %d schools, %d turtles, %d rays, %d bubbles; %d resting, %d flying, %d fleeing, %d buzzing, "
            "%d hovering, %d hopping, %d soaring, %d tumbling; %zu drawn; fled %llu times, bees buzzed Banjo %llu, sea creatures darted off %llu, "
            "knocked by Banjo %llu; %d frogs or crabs resting off the ground; %d hives here; %zu spots on map 0x%X (%zu kept on %zu maps), the nearest %.0f from Banjo, %.0f up; %.3f ms CPU last frame; Banjo %s",
            settings.insects ? "on" : "off", settings.fish ? "on" : "off", int(std::lround(settings.amount * 100.0f)),
            byKind[CRITTER_BEE], byKind[CRITTER_BUTTERFLY], byKind[CRITTER_DRAGONFLY], byKind[CRITTER_MOTH], byKind[CRITTER_FIREFLY], byKind[CRITTER_BEETLE], byKind[CRITTER_FLY],
            byKind[CRITTER_BIRD], byKind[CRITTER_FROG], byKind[CRITTER_CRAB],
            byKind[CRITTER_FISH], schoolCount, byKind[CRITTER_TURTLE], byKind[CRITTER_RAY], byKind[CRITTER_BUBBLE],
            byState[0], byState[1], byState[2], byState[3], byState[4], byState[5], byState[6], byState[7], drawn.size(),
            (unsigned long long)fleeCount, (unsigned long long)buzzCount, (unsigned long long)schoolFleeCount, (unsigned long long)knockCount,
            offGround, hiveCount, (m != nullptr) ? m->spots.size() : size_t(0), frameMap, spotTotal, maps.size(), nearest, nearestRise, updateMs, lastHavePlayer ? "found" : "not found");
    }

    void SceneCrittersListText(char *out, size_t size) {
        std::lock_guard lock{ mutex };
        size_t used = 0;
        auto add = [&](const char *line) {
            const size_t length = std::strlen(line);
            if (used + length + 1 < size) {
                std::memcpy(out + used, line, length);
                used += length;
                out[used] = '\0';
            }
        };
        out[0] = '\0';
        char line[256];
        for (const Insect &b : insects) {
            if (!b.live) {
                continue;
            }
            std::snprintf(line, sizeof(line), "%s %d %s at %.0f %.0f %.0f, %.0f from Banjo, %.0f from the camera%s\n", KindName(b.kind), b.variant, StateName(b.state),
                b.pos[0], b.pos[1], b.pos[2], lastHavePlayer ? Distance3D(b.pos, lastPlayer) : 0.0f, Distance3D(b.pos, frameCamera), b.leaving ? " (leaving)" : "");
            add(line);
        }
        for (const School &s : schools) {
            if (!s.live) {
                continue;
            }
            std::snprintf(line, sizeof(line), "school of %d fish (colour %d) %s at %.0f %.0f %.0f, %.0f from Banjo%s\n", s.count, s.variant, (s.flee > 0.0f) ? "darting off" : "cruising",
                s.center[0], s.center[1], s.center[2], lastHavePlayer ? Distance3D(s.center, lastPlayer) : 0.0f, s.leaving ? " (leaving)" : "");
            add(line);
        }
        for (const Glider &g : gliders) {
            if (!g.live) {
                continue;
            }
            std::snprintf(line, sizeof(line), "%s %s at %.0f %.0f %.0f, %.0f from Banjo, %.0f from the camera%s\n", KindName(g.kind), (g.flee > 0.0f) ? "swimming off" : "gliding",
                g.pos[0], g.pos[1], g.pos[2], lastHavePlayer ? Distance3D(g.pos, lastPlayer) : 0.0f, Distance3D(g.pos, frameCamera), g.leaving ? " (leaving)" : "");
            add(line);
        }
        if (used == 0) {
            add("no critters about\n");
        }
    }

    namespace critters {
        void BeginFrame(uint32_t map) {
            std::lock_guard lock{ mutex };
            frameMap = map;
            frameMapKnown = true;
        }

        bool WantsGround(uint64_t key) {
            std::lock_guard lock{ mutex };
            if (!frameMapKnown || (!settings.insects && !settings.fish)) {
                return false;
            }
            const MapSpots *m = FrameSpots();
            return (m == nullptr) || (m->keys.count(key) == 0);
        }

        bool WantsBareGround() {
            std::lock_guard lock{ mutex };
            if (!frameMapKnown || (!settings.insects && !settings.fish)) {
                return false;
            }
            // (By the sea the sand is wanted for the crabs, under it for the sea's crabs, and paths for the frogs to sit
            // on out of the grass: every map takes its bare ground's spots now, sparser than the grass's.)
            return true;
        }

        void NoteGround(uint64_t key, const std::vector<GrassTriangle> &triangles, bool bare, bool water) {
            std::lock_guard lock{ mutex };
            if (!frameMapKnown) {
                return;
            }
            MapSpots &m = SpotsOf(frameMap);
            if (!m.keys.insert(key).second) {
                return;
            }
            // Spots on its flat triangles, one a SpotSpacing square on average (a small triangle now and then one), each
            // at random on its triangle.
            const float spacing = bare ? BareSpacing : (water ? WaterSpacing : SpotSpacing);
            const float spotArea = spacing * spacing;
            for (const GrassTriangle &t : triangles) {
                const float e1[3] = { t.p[1][0] - t.p[0][0], t.p[1][1] - t.p[0][1], t.p[1][2] - t.p[0][2] };
                const float e2[3] = { t.p[2][0] - t.p[0][0], t.p[2][1] - t.p[0][1], t.p[2][2] - t.p[0][2] };
                const float n[3] = { e1[1] * e2[2] - e1[2] * e2[1], e1[2] * e2[0] - e1[0] * e2[2], e1[0] * e2[1] - e1[1] * e2[0] };
                const float length = std::sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
                if ((length < 1e-3f) || (std::abs(n[1]) < 0.75f * length)) {
                    continue;
                }
                // Only ground facing up: the underside of a ledge or a doorway's top is flat too, and a creature set on
                // one would hang in the air. The level's triangles all wind one way; which way is learnt from the
                // grass's, which are always floors (until enough are seen, either is taken).
                if (!bare) {
                    ((n[1] > 0.0f) ? windingUp : windingDown)++;
                }
                if ((windingUp + windingDown) >= 50) {
                    const bool upIsPositive = windingUp >= windingDown;
                    if ((n[1] > 0.0f) != upIsPositive) {
                        continue;
                    }
                }
                // (A grass layer faded out by its vertex alpha has no grass there. Bare ground's vertex alpha may mean
                // anything, as in Jolly Roger's Lagoon's town, and is left alone.)
                if (!bare && ((t.alpha[0] + t.alpha[1] + t.alpha[2]) < 0.6f)) {
                    continue;
                }
                const float area = 0.5f * length;
                // (The widest circle in it: twice its area over its edges' length.)
                const float e3[3] = { t.p[2][0] - t.p[1][0], t.p[2][1] - t.p[1][1], t.p[2][2] - t.p[1][2] };
                const float edges = std::sqrt(e1[0] * e1[0] + e1[1] * e1[1] + e1[2] * e1[2]) + std::sqrt(e2[0] * e2[0] + e2[1] * e2[1] + e2[2] * e2[2]) +
                    std::sqrt(e3[0] * e3[0] + e3[1] * e3[1] + e3[2] * e3[2]);
                const uint8_t roomy = uint8_t(std::min(2.0f * area / std::max(edges, 1e-3f), 255.0f));
                float want = area / spotArea;
                int count = int(want);
                if (Random() < (want - float(count))) {
                    count++;
                }
                for (int i = 0; i < count; i++) {
                    float a = Random(), b = Random();
                    if (a + b > 1.0f) {
                        a = 1.0f - a;
                        b = 1.0f - b;
                    }
                    Spot s;
                    s.bare = bare;
                    s.roomy = roomy;
                    m.grassSpots += bare ? 0 : 1;
                    for (int j = 0; j < 3; j++) {
                        s.p[j] = t.p[0][j] + e1[j] * a + e2[j] * b;
                    }
                    m.offered++;
                    if (m.spots.size() < MapSpotsMost) {
                        m.cells[CellKey(s.p[0], s.p[2])].push_back(uint32_t(m.spots.size()));
                        m.spots.push_back(s);
                        spotTotal++;
                    }
                    else {
                        // Full: this one takes an old one's place with the chance that keeps every spot offered
                        // equally likely to be kept.
                        const uint64_t pick = uint64_t(double(Random()) * double(m.offered));
                        if (pick < MapSpotsMost) {
                            Spot &old = m.spots[size_t(pick)];
                            std::vector<uint32_t> &oldCell = m.cells[CellKey(old.p[0], old.p[2])];
                            const auto found = std::find(oldCell.begin(), oldCell.end(), uint32_t(pick));
                            if (found != oldCell.end()) {
                                *found = oldCell.back();
                                oldCell.pop_back();
                            }
                            old = s;
                            m.cells[CellKey(s.p[0], s.p[2])].push_back(uint32_t(pick));
                        }
                    }
                }
            }
            TrimSpots();
        }

        const std::vector<std::array<uint32_t, 3>> &KindDraws() {
            return kindDraws;
        }

        const std::vector<interop::Critter> &Update(const float camera[3], const float player[3], bool havePlayer, bool water, uint32_t plant, uint32_t map) {
            const auto start = std::chrono::steady_clock::now();
            std::lock_guard lock{ mutex };
            const float dt = haveLast ? std::clamp(std::chrono::duration<float>(start - lastUpdate).count(), 0.0f, 0.1f) : 0.0f;
            lastUpdate = start;
            haveLast = true;
            clock = std::fmod(clock + dt, 10000.0f);
            if (insects.size() != CRITTER_MAX) {
                insects.resize(CRITTER_MAX);
            }
            if (schools.size() != SchoolsMost) {
                schools.resize(SchoolsMost);
            }
            if (gliders.size() != GlidersMost) {
                gliders.resize(GlidersMost);
            }
            if (bubbles.size() != BubblesMost) {
                bubbles.resize(BubblesMost);
            }
            windStrength = SceneGrassSettings().wind;
            lastHavePlayer = havePlayer;
            if (havePlayer) {
                std::memcpy(lastPlayer, player, sizeof(lastPlayer));
            }

            // A new map, or under the sea and back: every creature is gone at once (the view has changed anyway).
            if ((map != lastMap) || (water != lastWater) || resetAsked) {
                for (Insect &b : insects) {
                    b.live = false;
                }
                for (School &s : schools) {
                    s.live = false;
                }
                for (Glider &g : gliders) {
                    g.live = false;
                }
                for (Bubble &u : bubbles) {
                    u.live = false;
                }
                lastMap = map;
                lastWater = water;
                resetAsked = false;
            }

            const MapSpots *m = FrameSpots();
            const float *centre = havePlayer ? player : camera;
            findRise = water ? 2500.0f : 250.0f;
            std::memcpy(frameCamera, camera, sizeof(frameCamera));
            cameraClear = LandCameraClear;
            // (At dusk, or when day comes, the insects about go and the others come.)
            const bool night = dayCycle && (daylight < NightLight);
            if (night != nightMix) {
                nightMix = night;
                for (Insect &b : insects) {
                    if (b.live && !b.spawned) {
                        b.leaving = true;
                    }
                }
            }
            const std::vector<Mix> mix = MixOf(plant, map, night);
            const bool insectsOn = settings.insects && !water;
            const bool fishOn = settings.fish && water;
            // The land's birds, frogs and crabs (with Land Creatures), or the seabed's crabs (with Sea Creatures).
            const std::vector<Mix> animalMix = water ? std::vector<Mix>{ { CRITTER_CRAB, 0, 2.0f }, { CRITTER_CRAB, 1, 1.0f } } : AnimalsOf(plant, night);
            const bool animalsOn = (water ? settings.fish : settings.insects) && !animalMix.empty();

            // How many there should be, and those too many or too far away shrink away (the ones spawned from the
            // console are kept until they wander off; a hive's bees stay while their hive is near).
            const int insectWant = insectsOn ? int(std::lround(float(InsectsUsual) * settings.amount)) : 0;
            const int animalWant = animalsOn ? int(std::lround(float(water ? SeaCrabsUsual : AnimalsUsual) * settings.amount)) : 0;
            const int hiveWant = insectsOn ? int(std::lround(float(HiveBees) * settings.amount)) : 0;
            int insectLive = 0;
            int animalLive = 0;
            std::vector<int> hiveLive(hives.size(), 0);
            for (Insect &b : insects) {
                if (!b.live) {
                    continue;
                }
                const bool animal = IsAnimal(b.kind);
                if (animal ? !animalsOn : !insectsOn) {
                    b.live = false;
                    continue;
                }
                if ((b.hive >= 0) && (b.hive < int(hives.size()))) {
                    const Hive &h = hives[b.hive];
                    if (!b.leaving && ((h.map != map) || (Distance2D(h.p, centre) > HiveReach + 300.0f))) {
                        b.leaving = true;
                    }
                    if (!b.leaving) {
                        hiveLive[b.hive]++;
                        if (hiveLive[b.hive] > hiveWant) {
                            b.leaving = true;
                        }
                    }
                    continue;
                }
                // (A soaring bird is well above and may be further off.)
                const float leave = (b.state == State::Soaring) ? (LeaveDistance + 600.0f) : LeaveDistance;
                if (!b.leaving && (Distance2D(b.pos, centre) > leave)) {
                    b.leaving = true;
                }
                if (!b.leaving && !b.spawned) {
                    int &live = animal ? animalLive : insectLive;
                    live++;
                    if (live > (animal ? animalWant : insectWant)) {
                        b.leaving = true;
                    }
                }
            }
            // (One or two new ones a frame at the most, so a level's lot come in over a moment.)
            for (int added = 0; (insectLive < insectWant) && (added < 2); added++) {
                cameraClear = AppearCameraClear;
                const bool spawned = SpawnInsect(m, PickMix(mix), centre, player, havePlayer, AppearNear, AppearFar, false);
                cameraClear = LandCameraClear;
                if (!spawned) {
                    break;
                }
                insectLive++;
            }
            if (animalLive < animalWant) {
                cameraClear = AppearCameraClear;
                SpawnInsect(m, PickMix(animalMix), centre, player, havePlayer, AppearNear, AppearFar, false);
                cameraClear = LandCameraClear;
            }
            // A hive's bees, while it is near Banjo (one a frame).
            for (size_t h = 0; h < hives.size(); h++) {
                if ((hives[h].map == map) && (Distance2D(hives[h].p, centre) < HiveReach) && (hiveLive[h] < hiveWant)) {
                    SpawnHiveBee(int(h), false);
                    break;
                }
            }
            // From the console: just past Banjo as the camera looks (so they are in the picture), far enough from him not
            // to flee at once, near enough to be walked into; round him when nothing is found there.
            float ahead[3] = { centre[0], centre[1], centre[2] };
            {
                const float dx = centre[0] - camera[0], dz = centre[2] - camera[2];
                const float length = std::sqrt(dx * dx + dz * dz);
                if (length > 1.0f) {
                    ahead[0] += dx / length * 330.0f;
                    ahead[2] += dz / length * 330.0f;
                }
            }
            for (const SpawnAsk &ask : spawnAsks) {
                if ((ask.kind == CRITTER_TURTLE) || (ask.kind == CRITTER_RAY)) {
                    // (Straight into the water ahead of Banjo, at his height, circling there.)
                    for (int i = 0; i < std::min(ask.count, GlidersMost); i++) {
                        for (Glider &g : gliders) {
                            if (g.live) {
                                continue;
                            }
                            g = Glider();
                            g.live = true;
                            g.kind = ask.kind;
                            g.seed = Random() * 100.0f;
                            g.size = InfoOf(ask.kind).size;
                            g.radius = RandomIn(250.0f, 400.0f);
                            g.angle = RandomIn(0.0f, 6.2831853f);
                            g.pos[0] = ahead[0] + RandomIn(-80.0f, 80.0f);
                            g.pos[1] = centre[1] + RandomIn(0.0f, 80.0f);
                            g.pos[2] = ahead[2] + RandomIn(-80.0f, 80.0f);
                            g.middle[0] = g.pos[0] - std::cos(g.angle) * g.radius;
                            g.middle[1] = g.pos[1];
                            g.middle[2] = g.pos[2] - std::sin(g.angle) * g.radius;
                            break;
                        }
                    }
                    continue;
                }
                if (ask.kind == CRITTER_BUBBLE) {
                    for (int i = 0; i < ask.count; i++) {
                        const float from[3] = { ahead[0] + RandomIn(-60.0f, 60.0f), centre[1] + RandomIn(0.0f, 60.0f), ahead[2] + RandomIn(-60.0f, 60.0f) };
                        EmitBubble(from, 5.0f);
                    }
                    continue;
                }
                if (ask.kind == -2) {
                    // The bees of every hive near Banjo, now.
                    for (size_t h = 0; h < hives.size(); h++) {
                        if ((hives[h].map == map) && (Distance2D(hives[h].p, centre) < HiveReach)) {
                            for (int i = 0; i < ask.count; i++) {
                                SpawnHiveBee(int(h), true);
                            }
                        }
                    }
                    continue;
                }
                if (ask.kind == CRITTER_FISH) {
                    for (int i = 0; i < std::max(1, ask.count / SchoolFishLeast); i++) {
                        if (!SpawnSchool(m, ahead, player, false, 0.0f, 200.0f)) {
                            SpawnSchool(m, centre, player, false, 250.0f, 500.0f);
                        }
                    }
                    continue;
                }
                for (int i = 0; i < ask.count; i++) {
                    const Mix pick = (ask.kind < 0) ? PickMix(mix) : Mix{ ask.kind, VariantFor(ask.kind, mix), 1.0f };
                    if (!SpawnInsect(m, pick, ahead, player, havePlayer, 0.0f, 260.0f, true)) {
                        SpawnInsect(m, pick, centre, player, havePlayer, 220.0f, 420.0f, true);
                    }
                }
            }
            spawnAsks.clear();

            int schoolWant = fishOn ? std::clamp(int(std::lround(float(SchoolsUsual) * settings.amount)), 0, SchoolsMost) : 0;
            int schoolLive = 0;
            for (School &s : schools) {
                if (!s.live) {
                    continue;
                }
                if (!fishOn) {
                    s.live = false;
                    continue;
                }
                if (!s.leaving && (Distance2D(s.center, centre) > LeaveDistance)) {
                    s.leaving = true;
                }
                if (!s.leaving) {
                    schoolLive++;
                    if (schoolLive > schoolWant) {
                        s.leaving = true;
                    }
                }
            }
            if (schoolLive < schoolWant) {
                cameraClear = AppearCameraClear;
                SpawnSchool(m, centre, player, havePlayer, 450.0f, 1100.0f);
                cameraClear = LandCameraClear;
            }

            // The sea's gliders: a turtle and a ray (another turtle at a high Amount).
            {
                const int want = fishOn ? ((settings.amount > 0.0f) ? ((settings.amount >= 1.5f) ? 3 : 2) : 0) : 0;
                int turtles = 0, rays = 0;
                for (Glider &g : gliders) {
                    if (!g.live) {
                        continue;
                    }
                    if (!fishOn) {
                        g.live = false;
                        continue;
                    }
                    if (!g.leaving && (Distance2D(g.pos, centre) > LeaveDistance + 400.0f)) {
                        g.leaving = true;
                    }
                    if (!g.leaving) {
                        ((g.kind == CRITTER_RAY) ? rays : turtles)++;
                        if ((turtles + rays) > want) {
                            g.leaving = true;
                        }
                    }
                }
                if ((turtles + rays) < want) {
                    cameraClear = AppearCameraClear;
                    SpawnGlider(m, (rays == 0) ? CRITTER_RAY : CRITTER_TURTLE, centre, player, havePlayer, 600.0f, 1100.0f);
                    cameraClear = LandCameraClear;
                }
                for (Glider &g : gliders) {
                    if (g.live) {
                        UpdateGlider(g, player, havePlayer, dt);
                    }
                }
                for (Bubble &u : bubbles) {
                    if (u.live) {
                        if (!water) {
                            u.live = false;
                        }
                        else {
                            UpdateBubble(u, dt);
                        }
                    }
                }
            }

            // (Where each one is, and where each going somewhere is going.)
            crowd.clear();
            for (const Insect &b : insects) {
                if (b.live) {
                    MarkCrowd(b.pos);
                    if ((b.state == State::Flying) || (b.state == State::Hopping)) {
                        MarkCrowd(b.target);
                    }
                }
            }
            for (Insect &b : insects) {
                if (b.live) {
                    UpdateInsect(b, m, player, havePlayer, dt);
                }
            }
            for (School &s : schools) {
                if (s.live) {
                    UpdateSchool(s, m, player, havePlayer, dt);
                }
            }

            // What is drawn.
            drawn.clear();
            const uint32_t brightness = BrightnessOf(plant, water);
            for (const Insect &b : insects) {
                if (!b.live) {
                    continue;
                }
                float scale = DrawnScale(InfoOf(b.kind).size, b.grow, b.pos, camera);
                // A firefly is a point of light: drawn no smaller than about 1/90th of its distance (a few pixels), so far
                // ones still twinkle instead of shrinking to nothing (still grown in and faded out as the rest).
                if ((b.kind == CRITTER_FIREFLY) && (scale > 0.01f)) {
                    const float fit = scale / InfoOf(b.kind).size;
                    scale = std::max(scale, Distance3D(b.pos, camera) * (1.0f / 90.0f) * fit);
                }
                if (scale <= 0.01f) {
                    continue;
                }
                interop::Critter c;
                // (A bug resting bobs a touch; one flying bobs with its wingbeat.)
                const float bob = ((b.state == State::Perched) || IsAnimal(b.kind)) ? 0.0f : 0.6f * std::sin(b.wingPhase * 0.25f);
                c.position = { b.pos[0], b.pos[1] + bob, b.pos[2], scale };
                c.pose = { b.yaw, b.pitch, WingAngle(b), b.bank };
                uint32_t glow = 0;
                if (b.kind == CRITTER_FIREFLY) {
                    // A slow pulse, each its own, from a dim glow (never out, so they stay easy to see) to full; now and then
                    // a quick double flash.
                    const float blink = 0.5f + 0.5f * std::sin(clock * 2.2f + b.seed * 7.0f);
                    const float flash = std::max(0.0f, std::sin(clock * 9.0f + b.seed * 3.0f)) * ((std::fmod(clock * 0.37f + b.seed, 1.0f) < 0.12f) ? 1.0f : 0.0f);
                    glow = uint32_t(std::clamp(0.6f + 0.4f * blink * blink + flash, 0.0f, 1.0f) * 255.0f);
                }
                const uint32_t folded = (((b.kind == CRITTER_BEETLE) || (b.kind == CRITTER_BIRD)) && (b.state == State::Perched)) ? 1u : 0u;
                c.look = { uint32_t(b.kind), uint32_t(b.variant), brightness, glow | (folded << 8) };
                drawn.push_back(c);
                if (drawn.size() >= CRITTER_MAX) {
                    break;
                }
            }
            for (const School &s : schools) {
                if (!s.live) {
                    continue;
                }
                const float cy = std::cos(s.yaw), sy = std::sin(s.yaw);
                for (int i = 0; (i < s.count) && (drawn.size() < CRITTER_MAX); i++) {
                    // Each fish keeps its own place in the school (a loose ball round the middle), drifting a little.
                    const float fi = float(i) + s.seed;
                    const float along = (s.count == 1) ? 0.0f : (std::sin(fi * 2.3f) * 38.0f + std::sin(clock * 0.8f + fi) * 6.0f);
                    const float across = (s.count == 1) ? 0.0f : (std::cos(fi * 3.7f) * 42.0f + std::cos(clock * 0.6f + fi * 1.3f) * 6.0f);
                    const float up = (s.count == 1) ? 0.0f : (std::sin(fi * 5.1f) * 22.0f + std::sin(clock * 1.1f + fi * 0.7f) * 5.0f);
                    float pos[3] = {
                        s.center[0] + (cy * along - sy * across) * s.spread,
                        s.center[1] + up * s.spread,
                        s.center[2] + (sy * along + cy * across) * s.spread
                    };
                    const float fishSize = s.size * (0.85f + 0.3f * (0.5f + 0.5f * std::sin(fi * 9.7f)));
                    const float scale = DrawnScale(fishSize, s.grow, pos, camera);
                    if (scale <= 0.01f) {
                        continue;
                    }
                    interop::Critter c;
                    c.position = { pos[0], pos[1], pos[2], scale };
                    // (Each turned a little its own way, and swishing out of step with the rest.)
                    const float jitter = 0.18f * std::sin(clock * 1.3f + fi * 2.0f) * ((s.flee > 0.0f) ? 2.0f : 1.0f);
                    c.pose = { s.yaw + jitter, s.pitch, s.swish * ((s.flee > 0.0f) ? 1.8f : 1.0f) + fi * 1.7f, 0.0f };
                    c.look = { uint32_t(CRITTER_FISH), uint32_t(s.variant), brightness, 0u };
                    drawn.push_back(c);
                }
            }

            for (const Glider &g : gliders) {
                if (!g.live || (drawn.size() >= CRITTER_MAX)) {
                    continue;
                }
                const float scale = DrawnScale(g.size, g.grow, g.pos, camera);
                if (scale <= 0.01f) {
                    continue;
                }
                interop::Critter c;
                c.position = { g.pos[0], g.pos[1], g.pos[2], scale };
                c.pose = { g.yaw, g.pitch * 0.5f, g.phase, g.bank * 0.5f };
                c.look = { uint32_t(g.kind), 0u, brightness, 0u };
                drawn.push_back(c);
            }
            for (const Bubble &u : bubbles) {
                if (!u.live || (drawn.size() >= CRITTER_MAX)) {
                    continue;
                }
                // (Swelling as it leaves, and popping at the end.)
                const float swell = std::clamp(u.age / 0.15f, 0.0f, 1.0f) * std::clamp((u.life - u.age) / 0.25f, 0.0f, 1.0f);
                const float scale = DrawnScale(u.size * (0.5f + 0.5f * swell) * ((swell > 0.0f) ? 1.0f : 0.0f), 1.0f, u.pos, camera);
                if (scale <= 0.01f) {
                    continue;
                }
                interop::Critter c;
                c.position = { u.pos[0], u.pos[1], u.pos[2], scale };
                c.pose = { 0.0f, 0.0f, 0.0f, 0.0f };
                c.look = { uint32_t(CRITTER_BUBBLE), 0u, 255u, 0u };
                drawn.push_back(c);
            }

            // Sorted by kind, each kind's run a draw of its own mesh (KindDraws).
            std::stable_sort(drawn.begin(), drawn.end(), [](const interop::Critter &a, const interop::Critter &b) { return a.look.x < b.look.x; });
            kindDraws.clear();
            for (uint32_t i = 0; i < uint32_t(drawn.size()); i++) {
                if (kindDraws.empty() || (kindDraws.back()[0] != drawn[i].look.x)) {
                    kindDraws.push_back({ drawn[i].look.x, i, 0u });
                }
                kindDraws.back()[2]++;
            }

            updateMs = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start).count();
            return drawn;
        }
    };
};
