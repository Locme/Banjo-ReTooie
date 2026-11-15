//
// RT64
//

#pragma once

#include <cstddef>
#include <cstdint>
#include <array>
#include <vector>

#include "shared/rt64_critters.h"
#include "rt64_grass.h"

// Banjo-Tooie: small creatures in the 3D grass (shared/rt64_critters.h). Insects live over the grass of the land
// levels, each level its own (bees and butterflies in the meadows, dragonflies in Terrydactyland, frosty moths on
// Hailfire Peaks' icy side, flies and beetles in Glitter Gulch Mine, fireflies in Witchyworld's night); fish swim in
// schools under the sea. They keep to a ring round Banjo, grow in from nothing where they appear and shrink away
// where they go (so nothing pops in), scatter when he comes near and settle back once he has gone; a bee may buzz
// round him for a moment first.
//
// The ground they land on is picked from the grass ground draws' triangles as the grass first sees them (NoteGround),
// a spot every so often, so they need 3D grass on. Everything is on the CPU and small: at most CRITTER_MAX of them,
// and spots a few tens of thousands at the most (a dozen bytes each).

namespace RT64 {
    // The settings (SetSceneCritters): the land's creatures (insects, birds, frogs, crabs) and the sea's (fish, crabs,
    // turtles, rays) each on or off, and how many (0 to 2, 1 the default).
    struct CritterSettings {
        bool insects = true;
        bool fish = true;
        float amount = 1.0f;
    };
    void SetSceneCritters(bool insects, bool fish, float amount);
    // How light it is with Day and Night's cycle on (cycle; light 1 by day, about 0.45 at night): from dusk to dawn
    // the land levels' insects are fireflies and moths.
    void SetSceneCritterDaylight(bool cycle, float light);
    // Banjo's movement state each frame (his attacks knock creatures tumbling), and the hives bees live round (a map and
    // a place each, three floats a place; src/display/picture_filters.cpp's critter_hives.txt).
    void SetSceneCritterPlayerAction(uint32_t state);
    void SetSceneCritterHives(const uint32_t *hiveMaps, const float *places, size_t count);
    CritterSettings SceneCritterSettings();

    // For the console (critters): a line of what is about, and asking for some of a kind near Banjo (kind: a
    // CRITTER_* or -1 for the level's own, -2 for bees at the hives near him) or for them all to go and come back afresh.
    void SceneCrittersStatsText(char *out, size_t size);
    void SceneCrittersSpawn(int kind, int count);
    void SceneCrittersReset();
    // A list of every creature about (kind, state, where, how far from Banjo), for the console's critters list.
    void SceneCrittersListText(char *out, size_t size);

    namespace critters {
        // Starts a frame of the 3D world on the game's map (the spots are kept for each map).
        void BeginFrame(uint32_t map);
        // Whether a grass ground draw's triangles are wanted (not yet seen on this map, and a kind of creature on), and
        // then giving them: spots to land on are picked on its flat ones. key: the draw's grass key, so a draw seen
        // again adds nothing.
        bool WantsGround(uint64_t key);
        // bare: the level's flat ground that isn't grass, wanted only on a map with little grass (WantsBareGround,
        // once a frame); water: under the sea (the spots further apart there).
        bool WantsBareGround();
        void NoteGround(uint64_t key, const std::vector<GrassTriangle> &triangles, bool bare, bool water);

        // Once a frame with the 3D world's camera: moves every creature on and returns them to draw (empty for none).
        // player: Banjo's feet, when havePlayer; water: under the sea (fish instead of insects); plant: the level's
        // plants (rt64_grass_blades.h's GRASS_PLANT_*), which pick its insects; map: the game's map.
        // After Update: its creatures are sorted by kind, and each kind's run (kind, first, count) is drawn with that
        // kind's mesh.
        const std::vector<std::array<uint32_t, 3>> &KindDraws();
        const std::vector<interop::Critter> &Update(const float camera[3], const float player[3], bool havePlayer, bool water, uint32_t plant, uint32_t map);
    };
};
