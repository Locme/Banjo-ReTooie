//
// RT64
//

#pragma once

#include <cstdint>
#include <vector>

#include "shared/rt64_grass_blades.h"

// Banjo-Tooie: 3D grass on the CPU (notes/cheap-grass-plan.md, rt64_grass_blades.h). A grass ground draw's blades
// are worked out once, at the end of the first frame the draw is seen (so everything that frame lays over the grass is
// known), and kept by the draw's shape in the world; each frame then only picks which of their tiles to draw and how
// much of each. Nothing here touches the GPU: the framebuffer renderer uploads Blades() as they grow and the frame's
// Slots() and Tiles(), and draws each slot after its ground draw.

namespace RT64 {
    // The settings (SetSceneGrass): on, how dense (0.25 to 2, 1 the default), how far blades reach (world units),
    // how tall they are (0.5 to 2), how hard the wind blows (0 to 1), and whether the game's long grass (the strip on
    // the lawns' sides) is replaced by tall blades.
    struct GrassSettings {
        bool on = false;
        float density = 1.0f;
        float distance = 20000.0f;
        float height = 1.0f;
        float wind = 0.5f;
        bool tall = true;
        bool flowers = true;
        // Grass Type (1 grass, 2 clover, 3 meadow: grass with clover patches, 4 wild, the default: taller, thinner
        // blades), Tall Grass Height (0.5 to 2) and Flower Amount (0 to 3, 1 the default) (SetSceneGrassStyle).
        int type = 4;
        float longHeight = 1.0f;
        float flowerAmount = 1.0f;
        // Grass Patches, 0 (an even lawn) to 1 (small patches far apart).
        float patches = 0.0f;
        // Flower Beds (0 to 3: how much of the grass is flower beds, 1 about a tenth) and Bed Size (0.25 to 4, times
        // the usual size) (SetSceneGrassFlowerBeds). Changing either bakes the grass again.
        float flowerBeds = 1.0f;
        float bedSize = 1.0f;
        // Each kind of grass and flower's Amount (SetSceneGrassKinds): a byte each, the grasses from 0 and the flowers
        // from 48 (GrassBladeVS.hlsl's GrassKindAmount), 85 its usual share (100%), 0 none, 255 three times.
        uint8_t kindAmounts[96] = {
            85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85,
            85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85,
            85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85
        };
        // The game's map (SetSceneGrassMap), and whether it is under the sea (Jolly Roger's Lagoon's Atlantis and Sea
        // Bottom), where the grass is seabed weed on the sand instead (no flowers there).
        uint32_t map = 0;
        bool water = false;
    };

    // How the grass looks in the level being played (SceneGrassLevelLook): a tint (multiplying its colour, more towards
    // the tips), its height (times the Grass Height setting) and its flowers (times Flower Amount). The levels each have
    // their own: dry in Terrydactyland, dusty in Glitter Gulch Mine, short and tidy in Witchyworld, and so on.
    struct GrassLevelLook {
        float tint[3] = { 1.0f, 1.0f, 1.0f };
        float height = 1.0f;
        float flowers = 1.0f;
        // The plants it grows (rt64_grass_blades.h's GRASS_PLANT_*).
        uint32_t plant = 0;
    };
    GrassLevelLook SceneGrassLevelLook();
    // The game's map, each frame (src/display/picture_filters.cpp).
    void SetSceneGrassMap(uint32_t map);
    // The textures seabed weed grows on under the sea (the sand textures).
    void SetSceneWeedTextures(const uint64_t *hashes, size_t count);

    void SetSceneGrass(bool on, float density, float distance, float height, float wind, bool tall, bool flowers);
    GrassSettings SceneGrassSettings();
    // The grass's type (bakes the blades again when it changes), the long grass's height and how many flowers there are.
    void SetSceneGrassStyle(int type, float longHeight, float flowerAmount, float patches);
    void SetSceneGrassFlowerBeds(float beds, float size);
    // (amounts: count bytes, as GrassSettings::kindAmounts.)
    void SetSceneGrassKinds(const uint8_t *amounts, size_t count);

    // The grass textures (blades grow on these) and the tall grass textures (tall blades grow along the foot of these
    // walls), each a sorted list of RT64 texture hashes (src/display/picture_filters.cpp).
    void SetSceneGrassTextures(const uint64_t *hashes, size_t count);
    void SetSceneTallGrassTextures(const uint64_t *hashes, size_t count);
    // Copies the two texture lists (sorted) into grass and tall when they changed since version, and updates version:
    // for the renderer's look at every draw, without taking the settings' lock each time.
    void SceneGrassTextureLists(uint32_t &version, std::vector<uint64_t> &grass, std::vector<uint64_t> &tall);
    bool SceneGrassTexture(uint64_t hash);
    bool SceneTallGrassTexture(uint64_t hash);

    // For the console (grass): a line of what the grass holds and drew last frame, and throwing every blade away so they
    // are baked again.
    void SceneGrassStatsText(char *out, size_t size);
    void SceneGrassRebake();

    // One of a draw's triangles in the world, its corners' vertex alpha (0 to 1), and for a cover whether it was drawn
    // as a decal over what lies under it.
    struct GrassTriangle {
        float p[3][3];
        float alpha[3];
        bool decal = false;
        // For a cover, its texture (for the console's list of what covers the most grass).
        uint64_t texture = 0;
    };

    namespace grass {
        // Starts a frame: the camera's world position and the view's frustum (world planes a x + b y + c z + d >= 0
        // inside).
        void BeginFrame(const float camera[3], const float planes[6][4]);

        // The baked blades of a draw's key (an index for AddSlot, -1 for a draw that grows none), or false when it has
        // not been baked yet.
        bool Find(uint64_t key, int32_t &baked);

        // Asks for a draw to be baked at the end of the frame (once a key; Queued tells whether it already is). ground:
        // blades grow on its flat triangles; tall: tall blades grow along its walls' feet; useAlpha: a grass layer the
        // game blends over the ground, which grows none where its vertex alpha fades it out; decal: drawn as a decal over
        // other ground (moss painted over a path), which grows none where that ground lies under it.
        bool Queued(uint64_t key);
        void Queue(uint64_t key, std::vector<GrassTriangle> &&triangles, bool ground, bool tall, bool useAlpha, bool decal);
        bool HasQueued();
        // Whether a queued draw is near enough to the camera to be baked this frame (the renderer then gathers the
        // frame's covers for BakeQueued).
        bool WantsBake();

        // Bakes the frame's queued draws that are within the Distance setting's reach (with a margin), for up to a few
        // milliseconds; the rest wait for a later frame, so a level's first frame doesn't stall on all its grass. covers: the frame's flat level ground that isn't grass (roads, paths, floors,
        // the dirt laid over the grass): no blade grows where a decal lies on the grass, or other ground lies a little
        // above it (ground level with the grass is what a grass layer is laid over, and stays under it).
        void BakeQueued(const std::vector<GrassTriangle> &covers);

        // Picks this frame's tiles of a baked draw (in view, near enough) and how much of each to draw. Returns the
        // slot (0 for none: nothing of it is drawn). faceIndicesStart: where the draw's triangles start in the frame's
        // index buffer.
        uint32_t AddSlot(int32_t baked, uint32_t faceIndicesStart);

        // After every slot of the frame is added: the frame's budget scales every tile's share down together when the
        // view holds more blades than it allows. Returns the blades asked for this frame.
        uint32_t EndFrame();

        // After EndFrame: how many near and mid-distance blades and flowers a slot's three instanced draws ask for.
        void SlotInstances(uint32_t slot, uint32_t &nearInstances, uint32_t &midInstances, uint32_t &flowerInstances);

        // What the GPU needs: the blades baked since the last call, appended to out (the renderer keeps them all; after
        // Generation changes, it starts its list again), and this frame's slots and tiles.
        void TakeBlades(std::vector<interop::GrassBlade> &out);
        const std::vector<interop::GrassSlot> &Slots();
        const std::vector<interop::GrassTileDraw> &Tiles();
        // Changes whenever every blade is thrown away (too many, the texture lists changed, or grass rebake): the GPU's
        // copy is then sent again from the start.
        uint32_t Generation();

        // Throws every blade away; they are baked again as their draws are seen (console grass rebake).
        void Rebake();
        // For the console: a draw with a grass texture was seen this frame, and whether it was level ground (only that
        // grows blades); whether the blades' pipeline is built and the frame's 3D world camera was found.
        void NoteTextureDraw(bool level);
        void NoteFrame(bool pipeline, bool camera);
        // For the console: CPU time the renderer spent on grass outside these functions this frame (finding draws' keys),
        // noted only on a frame Timed says is timed (one in eight), so the clock is not read twice for every draw.
        bool Timed();
        void NoteCpuTime(double ms);
        // The distance terms each blade thins by (FrameParams.grassLod, GrassBladeVS.hlsl).
        void LodTerms(float terms[4]);
        // The frame budget's scale (FrameParams.grassStyle.w): past FullReach the grass falls off as (reach / distance)
        // to the power of 2 over it.
        float BudgetScale();
    };
};
