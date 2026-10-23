//
// RT64
//

#pragma once
// Include guard as well as #pragma once: DXC on Windows reaches a file here by two spellings of its path
// (from a file beside it, and through -I), and #pragma once then lets it in twice.
#ifndef RT64_EXT_RENDER_RT64_SCENE_EFFECTS_H
#define RT64_EXT_RENDER_RT64_SCENE_EFFECTS_H

#include <vector>

#include "shared/rt64_hlsl.h"
#include "shared/rt64_frame_params.h"

#include <functional>

#include "rt64_render_worker.h"
#include "rt64_shader_library.h"

namespace RT64 {
    struct RenderTarget;

    // Banjo-Tooie: screen-space effects (ambient occlusion, fog, outlines, bloom, depth of field, eye adaptation, rim light, underwater tint, heat haze, water reflections, bounce light) drawn over the 3D world after its last perspective draw and
    // before the HUD, only into the framebuffer whose depth buffer is at depthAddress (the game's).
    // Debug views from this one on show the picture with one effect only, in this order: ambient occlusion,
    // bounce light, outlines, rim light, fog, bloom, light shafts, eye adaptation, water reflections, water
    // waves, underwater tint and haze, heat haze, depth of field.
    constexpr uint32_t SceneEffectsSoloFirst = 5;
    constexpr uint32_t SceneEffectsSoloCount = 13;
    // 18 keeps no scene effect. These show one effect's own result over the scene instead: GTAO's visibility, SSGI's
    // light, and screen-space reflections where they show (at half strength when the effect is off).
    constexpr uint32_t SceneEffectsViewGtao = 19;
    constexpr uint32_t SceneEffectsViewSsgi = 20;
    constexpr uint32_t SceneEffectsViewSsr = 21;
    // What the traced effects' rays see: green where they meet the drawn surface, blue where it isn't in the traced
    // scene (light goes through it), red where something traced stands in front of it.
    constexpr uint32_t SceneEffectsViewRayScene = 22;

    constexpr uint32_t SceneMaxLights = 32;

    struct SceneEffectsSettings {
        // Banjo-Tooie: the level's lights (lamps, fires) the traced shadows cast from: world x, y, z and the outer range of each.
        float lights[SceneMaxLights * 4] = {};
        uint32_t lightCount = 0;
        float ambientOcclusion = 0.0f;
        float ambientOcclusionRadius = 60.0f;
        uint32_t depthAddress = 0;
        float fog = 0.0f;
        float fogStart = 1000.0f;
        float fogLength = 3000.0f;
        float fogColor[3] = { 0.75f, 0.8f, 0.85f };
        float outlines = 0.0f;
        float outlineThickness = 1.0f;
        float bloom = 0.0f;
        float bloomThreshold = 0.7f;
        float depthOfField = 0.0f;
        bool depthOfFieldOnBanjo = false;
        float eyeAdaptation = 0.0f;
        float rimLight = 0.0f;
        float toonShading = 0.0f;
        float toonCharacters = 0.0f;
        float underwaterTint = 0.0f;
        float underwaterHaze = 0.0f;
        float heatHaze = 0.0f;
        bool heatHazeWarmOnly = false;
        float waterReflections = 0.0f;
        float iceReflections = 0.0f;
        bool shoreFoam = false; // Original water: Modern's shore foam on the game's water.
        float bounceLight = 0.0f;
        // Screen-space global illumination and screen-space reflections (0 off, 1 strongest).
        float screenSpaceGI = 0.0f;
        float screenSpaceReflections = 0.0f;
        float reflectionGlossiness = 0.0f; // Stochastic reflections: 0 the mirror ray, up to 1 the roughest lobe.
        float waterWaves = 0.0f;
        // Modern water: the game's water isn't drawn; the pass draws its own in its place.
        bool modernWater = false;
        // Stylised water (Graphics > Water Stylised): Modern water with the stylised look.
        bool stylisedWater = false;
        // Water detail (0 to 1): how finely Modern and Stylised water's surface is tessellated round the player (0 keeps it
        // flat, its waves only in the shading).
        float waterDetail = 0.0f;
        // Displaced ground (0 to 1; 0 off).
        float groundDisplacement = 0.0f;
        float groundReach = 8000.0f;
        // Modern water under the water: how far into the underwater look (0 to 1), the water's surface height and
        // whether the whole level is under water (Atlantis, the Sea Bottom).
        float modernUnderwater = 0.0f;
        float modernSurfaceY = 0.0f;
        bool modernWholeLevel = false;
        float lightShafts = 0.0f;
        float sunShadows = 0.0f;
        float sunShadowReach = 450.0f;
        // Banjo-Tooie: the Sun shadow distance setting, the sun shadow map's half width in world units.
        float sunShadowDistance = 3000.0f;
        bool sunShadowOnBanjo = true;
        float sunShadowSoftness = 0.6f;
        bool customSun = false;
        float sunDirection[3] = { 0.47f, 0.42f, -0.78f };
        // Banjo-Tooie: the day and night cycle's tint of the 3D world (off: none), and how much of the light
        // shafts' strength its sun gives.
        bool timeOfDay = false;
        float dayTint[3] = { 1.0f, 1.0f, 1.0f };
        float dayShafts = 1.0f;
        bool dayFlare = true;
        bool dayFireflies = false;
        bool dayClouds = false;
        float dayRain = 0.0f;
        float dayFlash = 0.0f;
        bool daySnow = false;
        bool dayAurora = false;
        uint32_t dayMoonPhase = 4;
        // WIP volumetric effects (off by default): mist and fog strength (0 off, 1 as designed), the fog's preset
        // (0 to 6), the forced cloud type (0 none, 1 to 7) and the mist layer's extra height in world units. The layer
        // follows a slow anchor under Banjo (volAnchor), so it doesn't bob as he jumps.
        float volMist = 0.0f;
        float volFog = 0.0f;
        uint32_t volFogPreset = 0;
        uint32_t volCloudType = 0;
        float volMistOffset = 0.0f;
        float volAnchor = 0.0f;
        bool volAnchorValid = false;
        // How wet the ground is (0 dry, 1 soaked), and whether raindrops land on the screen.
        float dayWet = 0.0f;
        bool dayDrops = false;
        // The clouds' cover, height, thickness and wind speed (packed into SceneEffectsCB::view.y).
        float dayCloudShape[4] = { 0.5f, 1.0f, 0.6f, 1.0f };
        float rippleX[3] = {};
        float rippleZ[3] = {};
        float rippleAge[3] = { -1.0f, -1.0f, -1.0f };
        float player[3] = { 0.0f, -1e9f, 0.0f };
        // Banjo stands on the ground (not jumping or falling): only then does he press a trail into deep snow.
        bool playerGrounded = true;
        float waveSpeed = 1.0f;
        float grass = 0.0f;
        float grassHeight = 1.0f;
        float grassDistance = 2500.0f;
        float grassDensity = 1.0f;
        float grassPatches = 1.0f;
        // 3D grass blades: width (1 as before) and how much their lengths differ (0 all alike, 1 from none to full).
        float grassThickness = 1.0f;
        float grassRandomLength = 0.4f;
        bool grassChunky = false;
        float grassChunkSize = 2.0f;
        bool grassPixelated = false;
        float grassPixelSize = 1.0f;
        float grassBlend = 0.5f;
        // Banjo-Tooie: instanced 3D grass's culling (GRASS_CULL_* in rt64_grass_instances.h): frustum culling,
        // occlusion culling and chunking.
        uint32_t grassCulling = 0x7;
        // 3D grass LOD (0 off: every blade out to the grass distance; 1 thins it from 150 units away) and whether the
        // instanced grass's culling pass runs every other frame.
        float grassLod = 0.0f;
        bool grassHalfRate = true;
        bool grassRayTracing = true;
        float fur = 0.0f;
        float furLength = 1.0f;
        float furDensity = 1.0f;
        float furNoisiness = 0.5f;
        // Banjo's fur jiggle: the tips' lag behind his movement, world units at full length (SetSceneFurSway).
        float furSway[3] = { 0.0f, 0.0f, 0.0f };
        float feathers = 0.0f;
        float featherSize = 1.0f;
        float featherLength = 1.0f;
        float featherDensity = 1.0f;
        float featherNoisiness = 0.5f;
        float featherTransparency = 0.0f;
        // NPCs' fur and feathers (the yetis, Canary Mary): their own sliders, as Banjo's and Kazooie's.
        float npcFur = 0.0f;
        float npcFurLength = 1.0f;
        float npcFurDensity = 1.0f;
        float npcFurNoisiness = 0.5f;
        float npcFeathers = 0.0f;
        float npcFeatherSize = 1.0f;
        float npcFeatherLength = 1.0f;
        float npcFeatherDensity = 1.0f;
        float npcFeatherNoisiness = 0.5f;
        float npcFeatherTransparency = 0.0f;
        float parallax = 0.0f;
        bool parallaxOriginal = true;
        bool parallaxAll = false;
        bool snow = false;
        float snowHeight = 1.0f;
        // How fine deep snow's trail is (0.25 to 1; SetSceneSnow).
        float snowDetail = 1.0f;
        // How many seconds prints stay before filling back in (0: they stay until Banjo leaves the map), the camera
        // distance the tessellated snow is cut coarser from, and the map and how many times it has changed (each change
        // clears the trail).
        float snowRefillAfter = 0.0f;
        float snowLodDistance = 1500.0f;
        uint32_t snowMap = 0;
        uint32_t snowMapVisit = 0;
        bool snowStrictColor = true;
        // Tessellated sand instead of snow: shallow, only on sand textures (SetSceneSandTextures), shaded as sand.
        bool snowSand = false;
        uint32_t view = 0;
        bool compare = false;
    };

    // ambientOcclusion: 0 off, 1 strongest. radius in world units. depthAddress is physical.
    void SetSceneEffects(float ambientOcclusion, float radius, uint32_t depthAddress);
    // fog: 0 off, 1 the most. start and length in world units; color in 0 to 1.
    void SetSceneFog(float fog, float start, float length, float red, float green, float blue);
    // Toon outlines where the depth jumps (silhouettes and creases): 0 off, 1 strongest; thickness 1 to 4.
    void SetSceneOutlines(float outlines, float thickness);
    // Bloom: a glow around the bright parts of the scene (0 off, 1 strongest), from the parts brighter
    // than the threshold (0 to 1).
    void SetSceneBloom(float bloom, float threshold);
    // Depth of field (0 off, 1 strongest), focused on the nearest thing at the middle of the picture.
    void SetSceneDepthOfField(float strength, bool onBanjo = false);
    // Eye adaptation (0 off, 1 strongest): dark scenes brighten and bright ones tone down over about a second.
    void SetSceneEyeAdaptation(float strength);
    // Rim light (0 off, 1 strongest): a soft light along the edges of nearby characters and objects.
    void SetSceneRimLight(float strength);
    // Toon shading (0 off, 1 strongest), apart for the level (world) and for characters and other models.
    void SetSceneToonShading(float world, float characters);
    // Whether characters are drawn into the water mask this frame (marked apart, for the character toon shading).
    bool SceneCharacterToonWanted();
    // Underwater look while the camera is under water: tint (0 off, 1 strongest) and distance haze (0 to 1).
    void SetSceneUnderwater(float tint, float haze);
    // Heat haze (0 off, 1 strongest): the 3D world shimmers, more with distance. With warmOnly, only where heat rises:
    // above hot-looking surfaces (glowing lava, fire) on screen.
    void SetSceneHeatHaze(float strength, bool warmOnly);
    // Water reflections (0 off, 1 strongest) on the game's water surfaces, which the framebuffer renderer
    // redraws into a mask (BeginSceneWaterMask) before the pass.
    void SetSceneWaterReflections(float strength);
    // Ice reflections (0 off, 1 strongest) on ice: Icy Side's frozen decals and anything drawn with an ice texture
    // (SetSceneIceTextures), which go into the same mask.
    void SetSceneIceReflections(float strength);
    // Bounce light (0 off, 1 strongest): nearby surfaces' colour lights what faces them.
    void SetSceneBounceLight(float strength);
    // Banjo-Tooie: screen-space global illumination (light bounced off the surfaces on the screen) and screen-space
    // reflections (the scene reflected in every surface, more at grazing angles), each 0 off, 1 strongest.
    void SetSceneScreenSpaceGI(float strength);
    void SetSceneScreenSpaceReflections(float strength, float glossiness = 0.0f);
    // Banjo-Tooie: water waves on the water mask's surfaces (0 off, 1 strongest), moving at speed (1 normal).
    void SetSceneWaterWaves(float strength, float speed);
    // Banjo-Tooie: Modern water (Graphics > Water): the game's water draws are left out of the 3D world and the
    // scene effects pass draws new water where they were, from the water mask and their colours.
    void SetSceneShoreFoam(bool enabled);
    // stylised: Graphics > Water is Stylised (Modern water with the stylised look).
    void SetSceneModernWater(bool enabled, bool stylised);
    // Whether the game's water draws are left out this frame (Modern water, with the effects pass drawing).
    bool SceneModernWater();
    // Banjo-Tooie: whether flat see-through level decals are ice that reflects (Icy Side only; elsewhere the same kind
    // of decal is dirt, grass or paths blended onto the ground).
    void SetSceneIcyLevel(bool enabled);
    bool SceneIcyLevel();
    // Modern water's caustics while under water: how far under (0 to 1), the surface's height, a whole level under water.
    void SetSceneModernUnderwater(float amount, float surfaceY, bool wholeLevel);
    // Banjo-Tooie: light shafts from the sun through gaps against the sky (0 off, 1 strongest).
    void SetSceneLightShafts(float strength);
    // Banjo-Tooie: sun shadows (0 off, 1 strongest): everything in the 3D world casts a shadow away from the
    // sun onto what is behind it, found in the depth buffer.
    // onBanjo false leaves Banjo's own sun shadow out (HD shadows can give him one instead).
    void SetSceneSunShadows(float strength, bool onBanjo = true, float softness = 0.6f);
    // Banjo-Tooie: how far round the camera the sun shadow map reaches (half its square's width, world units).
    void SetSceneSunShadowDistance(float distance);
    // Banjo-Tooie: the sun's world direction (towards it) for the sun shadows and light shafts; custom false
    // puts back the fixed sun. A sun below the horizon casts no shadows.
    void SetSceneSun(bool custom, float x, float y, float z);
    // Banjo-Tooie: the day and night cycle. The 3D world is multiplied by tint (0 to 1.27 each), its brightest
    // parts less so the darker it is; the sky darkens more, to stars and a moon (the SetSceneSun direction) at
    // night, and glows warm round the sun when the tint is warm. The fog takes the tint too. shafts (0 to 1)
    // scales the light shafts, so the moon gives none. By day the sun shows as a disc, with a lens flare when
    // flare is on and nothing hides it.
    // fireflies: small glowing fireflies drift round Banjo at night.
    // clouds: a layer of soft 3D clouds drifting across the sky, lit by the sun or the moon.
    void SetSceneTimeOfDay(bool enabled, const float tint[3], float shafts, bool flare, bool fireflies, bool clouds);
    // Banjo-Tooie: the day and night cycle's weather. rain (0 clear, 1 a downpour) greys and darkens the world
    // and sky, thickens the clouds and draws falling rain; flash (0 to 1) is lightning lighting everything up.
    // snow: it falls as snow.
    void SetSceneWeather(float rain, float flash, bool snow);
    // Volumetric mist, fog and clouds (WIP): see SceneEffectsPS.hlsl (VolSettings) and src/gameplay/volumetric.cpp.
    void SetSceneVolumetric(float mist, float fog, uint32_t fogPreset, uint32_t cloudType, float mistOffset);
    void SetSceneRainDetail(float wet, bool drops);
    void SetSceneClouds(float cover, float height, float thickness, float speed);
    // Banjo-Tooie: the moon's phase for the day and night cycle, 0 new, 2 first quarter, 4 full, 6 last quarter.
    void SetSceneMoonPhase(uint32_t phase);
    // Banjo-Tooie: northern lights across the night sky with the day and night cycle.
    void SetSceneAurora(bool enabled);
    // Banjo-Tooie: three ripples on the water (world x and z, age in seconds, below 0 for none).
    void SetSceneWaterRipples(const float x[3], const float z[3], const float age[3]);
    // Banjo-Tooie: the 3D world's camera, noted as each frame's draws are gathered, whatever effects are on.
    void NoteSceneCamera(const interop::float4x4 &projection, const interop::float4x4 &view);
    // The last noted camera's world height; false until there is one.
    bool GetSceneCameraHeight(float *height);
    // Banjo-Tooie: hardware ray tracing (Graphics > Ray tracing). SetSceneRayTracing is the setting; the renderer
    // notes whether the graphics device has ray tracing (NoteRayTracingSupport) when it is created. A traced pass
    // runs only when RayTracingActive() is true (setting on and device supported), so that is the one place a new
    // traced effect (reflections first, shadows later) checks. GetRayTracingSupport: 0 not known yet, 1 no, 2 yes.
    // BuildSceneBVH builds the traced reflections' acceleration structures from the world's solid triangles (runs of
    // the index buffer: first index, count; positions from the vertex processor's world position buffer); does nothing
    // while RayTracingActive() is false.
    // Banjo-Tooie: a draw the traced effects trace through: its indices, its first texture tile (into the frame's tiles) and
    // what it is: SceneRayDrawCutout (a cut-out or see-through draw: the rays read its texture's alpha and go through where
    // it is see-through), SceneRayDrawTextured (it has a texture to read; a lamp's casing lets light out where it is bright).
    struct SceneRayDraw {
        uint32_t indexStart;
        uint32_t indexCount;
        uint32_t tileIndex;
        uint32_t flags;
    };
    constexpr uint32_t SceneRayDrawCutout = 1;
    constexpr uint32_t SceneRayDrawTextured = 2;
    // A model (drawn with a transform of its own, not the level's geometry): it casts a soft shadow straight down.
    constexpr uint32_t SceneRayDrawModel = 4;
    // Banjo-Tooie: bits 8 to 15 of a ray draw's flags carry its material (SceneMaterialTexture), which the traced
    // effects read where they meet it (metal and tiles reflect, L 2026-10-21).
    constexpr uint32_t SceneRayDrawMaterialShift = 8;
    // Banjo-Tooie: a ray draw's material is Parallax's shape + 1 in its low byte and, above it (shifted by this), the index
    // of its Ray Tracing Material Pick Mode material (SetSceneRayMaterials), 0 for none.
    constexpr uint32_t SceneRayMaterialIndexShift = 8;
    // Most materials the picks can hold at once.
    constexpr uint32_t SceneMaxRayMaterials = 255;
    // The frame's buffers the traced effects read the textures of what they meet from: its index buffer, texture coordinates
    // (two floats a vertex), RDP and GPU tiles, and the texture cache's descriptor set.
    struct SceneRayTextures {
        const RenderBuffer *indices = nullptr;
        const RenderBuffer *texcoords = nullptr;
        const RenderBuffer *rdpTiles = nullptr;
        const RenderBuffer *gpuTiles = nullptr;
        RenderDescriptorSet *textureSet = nullptr;
    };
    // The 3D grass's blades near the camera as triangles (world positions, float4, three a triangle; unused ones NaN), and
    // a count that changes whenever they are written again. No vertices: no grass in the structures.
    struct SceneRayGrass {
        const RenderBuffer *vertices = nullptr;
        uint32_t vertexCount = 0;
        uint64_t generation = 0;
        float reach = 0.0f;
    };
    void BuildSceneBVH(RenderWorker *worker, const RenderBuffer *worldPos, uint32_t worldPosVertexCount, const RenderBuffer *indices,
        const SceneRayDraw *draws, size_t drawCount, const SceneRayTextures &textures, const SceneRayGrass &grass, uint64_t levelKey = 0);
    void SetSceneRayTracing(bool enabled);
    // Banjo-Tooie: Graphics > Ray tracing strength (0 to 1, 0.6 the default): the least each traced effect shows at while
    // ray tracing is active (see RefreshReflections).
    void SetSceneRayTracingStrength(float strength);
    // Banjo-Tooie: Graphics > Ray Tracing's reflection sliders (0 to 1): the least the reflections and water reflections show at
    // while ray tracing is active, and how much the Parallax materials Metal, Tiles and Smooth reflect of that.
    void SetSceneRayTracingReflections(float reflections, float water, float metal, float tiles, float smooth);
    // Banjo-Tooie: Graphics > Ray tracing hit colours: a ray that lands where the picture can't see finds the colour that
    // spot had when it was last on screen (a world radiance cache, written from the screen each frame).
    void SetSceneRayTracingHitColours(bool enabled);
    // Banjo-Tooie: Graphics > Ray tracing > Ray traced BRDF (the roughness, 0 to 1, of every traced reflection's GGX lobe; 0
    // keeps the mirror) and Ray traced subsurface scattering (its strength on leaves and grass, 0 to 1; 0 is off).
    void SetSceneRayTracingBrdfSubsurface(float brdfRoughness, float subsurface);
    // Banjo-Tooie: Ray tracing noise smoothing, 0 (the raw rays) to 1.
    void SetSceneRayTracingSmoothing(float smoothing);
    // Banjo-Tooie: Path tracing, its bounces after the first (0 off, up to 4).
    void SetScenePathTracing(uint32_t bounces);
    // Graphics > Ray tracing's "Traced shadows of the player": off, Banjo (whoever is played) casts no traced shadows.
    void SetSceneRayTracingPlayerShadows(bool enabled);
    // Graphics > Half-resolution ray tracing: the sun's traced shadows and the traced light beams at half size.
    void SetSceneRayTracingResolution(uint32_t resolution);
    void SetSceneRayTracingParallax(bool enabled);
    // Graphics > Ray detail distances: past the first, half the traced rays a pixel; past the second, a quarter (0 for never).
    void SetSceneRayDetailDistances(float half, float quarter);
    // Banjo-Tooie: Traced light beams, 0 off to 1; direction (world, towards the light) for a room whose light comes
    // in at its windows from a known way, or null for the sun.
    void SetSceneTracedBeams(float strength, const float *direction);
    // Banjo-Tooie: the level's lights, count of them (up to SceneMaxLights), four floats each: world x, y, z, outer range.
    // The traced pass shadows what each one lights (its rays go from the surface to the light).
    void SetSceneLights(const float *xyzr, uint32_t count);
    // Banjo-Tooie: the lit lamps the renderer found this frame (draws with a lamp texture, SetSceneLampTextures), four
    // floats each like SetSceneLights; the traced lights add them after the level's own, so a lantern the game gives no
    // light of its own (Bottles' house) still lights the room and its bars cast shadows (L, 2026-10-21).
    void SetSceneLampLights(const float *xyzr, uint32_t count);
    void SetSceneLampTextures(const uint64_t *hashes, size_t count);
    bool SceneLampTexture(uint64_t hash);
    // Banjo-Tooie: Banjo's fur jiggle, the tips' lag behind his movement (world x, y, z in shares of the fur's
    // length; zeros when off). The game steps the spring (src/gameplay/snout_jiggle.cpp).
    void SetSceneFurSway(float x, float y, float z);
    void NoteRayTracingSupport(bool supported);
    int GetRayTracingSupport();
    bool RayTracingActive();
    // Banjo-Tooie: Banjo's world position, which the fog is measured from (valid false: from the camera).
    void SetScenePlayer(bool valid, float x, float y, float z, bool grounded = true);
    // The game frames: the id of each workload as the game hands it over, and the workload whose effects are
    // being recorded next. Banjo and his ripples are kept for each handed-over frame, so the effects use the
    // ones the drawn frame had, not the game's newest (it can run frames ahead of what is drawn).
    void NoteSceneWorkloadSubmitted(uint64_t workloadId);
    void SetSceneEffectsWorkload(uint64_t workloadId);
    // Banjo-Tooie: 3D grass on green, level ground of the 3D world (0 off, 1 the most blades), blade height
    // (1 normal), the distance from the camera they fade out by, in world units, and how closely they grow (1 normal)
    // and how much of the green ground their patches cover (1 all of it).
    void SetSceneGrass(float amount, float height, float distance, float density, float patches);
    void SetSceneGrassBlades(float thickness, float randomLength, bool chunky, float chunkSize, bool pixelated, float pixelSize, float blend);
    // Instanced 3D grass's culling: blades out of view, blades hidden behind what was drawn in front of them last frame,
    // and whether the grass ground is grouped into world chunks that are culled whole first.
    void SetSceneGrassCulling(bool frustum, bool occlusion, bool chunking);
    uint32_t SceneGrassCulling();
    void SetSceneGrassLod(float lod, bool halfRate);
    bool SceneGrassHalfRate();
    // Whether the 3D grass near the camera is in the traced effects' structures (casting traced shadows, seen in traced
    // reflections), and how far from the camera it is (0 while ray tracing isn't active or this is off).
    void SetSceneGrassRayTracing(bool enabled);
    float SceneGrassRayReach();
    // The blades drawn over each grass draw: 0 when 3D grass is off.
    uint32_t SceneGrassShells();
    // Real blades: how many passes of blades a ground triangle spanning low to high (world x and z) this far from the
    // camera needs (GrassGS.hlsl grows up to 352 a pass), with the finest grid's cells baseCell wide, coarsening from lodNear on.
    uint32_t SceneGrassBladePasses(const float (&low)[2], const float (&high)[2], float distanceToCamera, float lodNear, float baseCell);
    // Fills the frame's grass terms from the 3D world's projection (as adjusted for the aspect ratio), view,
    // view-projection and viewport (as the RSP used them), the framebuffer's resolution in game pixels and
    // the size of its viewport in target pixels. False when there is no grass to draw this frame.
    bool ComputeSceneGrass(const interop::float4x4 &projection, const interop::float4x4 &view, const interop::float4x4 &viewProj,
        const interop::float3 &viewportScale, const interop::float3 &viewportTranslate, const interop::float2 &resolution,
        float viewportWidth, float viewportHeight, uint64_t workloadId, interop::FrameParams &frameParams);
    // Banjo-Tooie: Banjo's fur (0 off, 1 the thickest coat) and its length (1 normal). The game marks his
    // model's draws (G_EX_SETFURSHELLS_V1); each is drawn again as shells pushed out along its normals.
    void SetSceneFur(float amount, float length, float density, float noisiness);
    // The shells drawn over each of Banjo's draws: 0 when the fur is off.
    uint32_t SceneFurShells();
    // Banjo-Tooie: which of a model's vertices get fur or feathers, told by their own colours before the game
    // lights them (its lighting changes their colours every frame, so colour alone gave different coats in different
    // places, L). One byte per vertex of the block at RDRAM address `address` (16 bytes each): 0 to tell by the lit
    // colour as before, FUR_VERTEX_COVERED, FUR_VERTEX_BARE or FUR_VERTEX_FEATHERS. An empty list forgets the block.
    // anchorScale turns the block's vertex positions into the fur's units (a model mod stored bigger, Smash Banjo's 8
    // times, would otherwise get strands that much finer).
    // FUR_VERTEX_SHORTS is added on his shorts: the fur near them is cut short, so none comes out over them (L).
    enum : uint8_t { FUR_VERTEX_UNKNOWN = 0, FUR_VERTEX_COVERED = 1, FUR_VERTEX_BARE = 2, FUR_VERTEX_FEATHERS = 3, FUR_VERTEX_MARK_MASK = 0x3F,
        FUR_VERTEX_SHORTS = 0x40, FUR_VERTEX_IN_BLOCK = 0x80 };
    void SetFurVertexFlags(uint32_t address, const std::vector<uint8_t> &flags, float anchorScale = 1.0f);
    // The marks for `count` vertices of `stride` bytes from `address`, with FUR_VERTEX_IN_BLOCK on those a block covers
    // (all 0 elsewhere).
    void FurVertexFlags(uint32_t address, uint32_t stride, uint32_t count, uint8_t *out);
    // The anchor scale of the block set last (1 when there is none).
    float FurVertexAnchorScale();
    // Fills the frame's fur terms from the 3D world's projection and view-projection and viewport (as the RSP
    // used them) and the framebuffer's resolution in game pixels. False when there is no fur this frame.
    bool ComputeSceneFur(const interop::float4x4 &projection, const interop::float4x4 &viewProj, const interop::float3 &viewportScale,
        const interop::float3 &viewportTranslate, const interop::float2 &resolution, interop::FrameParams &frameParams);
    // Banjo-Tooie: Kazooie's feathers (0 off, 1 the fullest), their size, length and density (1 normal), how uneven
    // they are (0 to 1, 0.5 normal) and how see-through (0 solid to 1). The game marks her draws
    // (G_EX_SETFURSHELLS_V1 2); a geometry shader grows little feathers over them (GrassGS.hlsl).
    void SetSceneKazooieFeathers(float amount, float size, float length, float density, float noisiness, float transparency);
    // Banjo-Tooie: furry NPCs' white fur (G_EX_SETFURSHELLS_V1 3) and feathered NPCs' feathers (4), with their own
    // settings as Banjo's fur and Kazooie's feathers.
    void SetSceneNpcFur(float amount, float length, float density, float noisiness);
    void SetSceneNpcFeathers(float amount, float size, float length, float density, float noisiness, float transparency);
    // Whether Kazooie's feathers are on.
    bool SceneKazooieFeathers();
    // Banjo-Tooie: deep snow that Banjo leaves a trail in (Snow.hlsli), on the snowy ground of the 3D world; on is
    // only set on maps with snow. height: how deep it is (1 normal, about ankle deep). strictColor: only white with
    // hardly any blue counts as snow (a map with pale ice next to its snow); otherwise bluish white counts too. detail: how
    // fine its trail is, 1 the finest (cells 1.25 units across), 0.5 half as fine, down to 0.25 (less work for the GPU).
    // refillAfter: seconds prints stay before filling back in (less work: the snow is cut finely only where prints
    // still show); 0, they stay until the map changes. lodDistance: the camera distance the snow is cut coarser from. map: the
    // game's map (a new one clears the trail).
    void SetSceneSnow(bool on, float height, bool strictColor, float detail, float refillAfter, float lodDistance, uint32_t map, bool sand);
    // A triangle of a model drawn this frame (not the level's own ground), in the world (x y z three times): deep snow
    // is pressed down wherever one reaches into it (ComputeSceneSnow).
    void SceneSnowTouch(const float *triangle);
    // One model draw's triangles (count of them, nine floats each) that may press the snow: held back a frame, and left
    // out if the draw stands still.
    void SceneSnowTouchDraw(const float *triangles, size_t count);
    // The most shells drawn over a snow draw: 0 when there is no deep snow.
    uint32_t SceneSnowShells();
    // How much nearer the snow counts as being for the camera's zoom (1 for the usual camera, less zoomed in).
    float SceneSnowZoom(const interop::FrameParams &frameParams);
    // The snow round Banjo counts as no further off than this more than its distance from him, however far back the
    // camera is (Chilly Willy's fight watches from about 2500 away). The same in Snow.hlsli.
    static constexpr float SceneSnowNearBanjo = 600.0f;
    // How many shells a draw nearest the camera at distanceToCamera gets (0 beyond the snow's reach).
    uint32_t SceneSnowShellsAt(float distanceToCamera, const interop::FrameParams &frameParams);
    // A renderer's copy of the snow trail grid: only the rows pressed since its last copy are copied, and rowFirst to
    // rowEnd are the rows changed since its last upload (the renderer empties them after uploading).
    struct SceneSnowTrailCopy {
        std::vector<uint32_t> cells;
        uint64_t seen = 0;
        uint64_t fullAt = 0;
        uint32_t rowFirst = 0;
        uint32_t rowEnd = 0;
    };
    // Fills the frame's snow terms (as ComputeSceneGrass, which must have filled the camera's terms first) and brings
    // the renderer's trail grid up to date (two uints a cell, Snow.hlsli). False when there is no deep snow this frame.
    // Banjo-Tooie: Modern and Stylised water's tessellated surface (WaterTess.hlsl): the camera's terms, the player's place
    // and motion, and how finely to cut, into frameParams' water fields. False when it isn't tessellated this frame.
    // Returns bit 1 when the water is tessellated this frame, bit 2 when ground is displaced (0: neither).
    uint32_t ComputeSceneWater(const interop::float4x4 &projection, const interop::float4x4 &view, const interop::float4x4 &viewProj,
        const interop::float3 &viewportScale, const interop::float3 &viewportTranslate, const interop::float2 &resolution, uint64_t workloadId,
        interop::FrameParams &frameParams);
    void SetSceneWaterDetail(float detail);
    // Banjo-Tooie: Graphics > Displaced ground (0 to 1, 0 off): level ground with a parallax texture drawn as a tessellated,
    // displaced surface (GroundTess.hlsl).
    void SetSceneGroundDisplacement(float amount, float reach);
    float SceneGroundDisplacement();
    bool ComputeSceneSnow(const interop::float4x4 &projection, const interop::float4x4 &viewProj, const interop::float3 &viewportScale,
        const interop::float3 &viewportTranslate, const interop::float2 &resolution, uint64_t workloadId, interop::FrameParams &frameParams,
        SceneSnowTrailCopy &trail);
    // How many uints a row of the snow trail grid is.
    uint32_t SceneSnowTrailRowSize();
    // Banjo-Tooie: the textures (RT64 hashes) of windows and lamps that light up at night with the day and night cycle.
    void SetSceneNightLights(const uint64_t *hashes, size_t count);
    // Banjo-Tooie: the textures 3D grass grows on (RT64 texture hashes); with none set, any green ground.
    void SetSceneGrassTextures(const uint64_t *hashes, size_t count);
    // Textures with grass only along an edge (cliff tops, the foot of a wall): blades grow on their green parts
    // whatever way they face. None set, none.
    void SetSceneGrassEdgeTextures(const uint64_t *hashes, size_t count);
    // 1 for a grass texture, 2 for one with a grassy edge, 0 for neither.
    uint32_t SceneGrassTexture(uint64_t hash);
    // Banjo-Tooie: the ice textures (RT64 hashes): floors, walls and blocks drawn with them reflect with Ice reflections.
    void SetSceneIceTextures(const uint64_t *hashes, size_t count);
    // Banjo-Tooie: ice textures that reflect in any map, not only the icy ones (Shader Effects pick mode's Ice picks and
    // the ice found elsewhere, such as Glitter Gulch Mine's Waterfall Cavern).
    void SetSceneIceAnywhereTextures(const uint64_t *hashes, size_t count);
    // 0 not ice, 1 ice in the icy maps only, 2 ice anywhere.
    uint32_t SceneIceTexture(uint64_t hash);
    // Banjo-Tooie: the shiny textures (metal, tiles), whose draws go into the water mask marked apart (waterMask 5) so
    // screen-space reflections show only on them (and on water and ice); looked up only while those are on.
    void SetSceneShinyTextures(const uint64_t *hashes, size_t count);
    bool SceneShinyTexture(uint64_t hash);
    bool SceneShinyWanted();
    // Banjo-Tooie: textures deep snow never covers (Shader Effects pick mode's picks other than Deep Snow).
    void SetSceneSnowOffTextures(const uint64_t *hashes, size_t count);
    bool SceneSnowOffTexture(uint64_t hash);
    // Banjo-Tooie: the sand textures tessellated sand lies on (SetSceneSnow's sand).
    void SetSceneSandTextures(const uint64_t *hashes, size_t count);
    bool SceneSandTexture(uint64_t hash);
    // Fills the frame's night light terms. False when nothing lights up this frame (day, or the cycle is off).
    bool ComputeSceneNightLights(interop::FrameParams &frameParams);
    // Whether a texture lights up at night (only meaningful after ComputeSceneNightLights returned true).
    bool SceneNightLightTexture(uint64_t hash);
    // Banjo-Tooie: parallax mapping (0 off, 1 the deepest), on the textures a texture pack gives a height map and, with
    // original on, the game's own textures listed (RT64 hashes), by their brightness; all lets it on every textured
    // draw of the 3D world instead, to look for textures that suit it.
    void SetSceneParallax(float depth, bool original, bool all);
    // Banjo-Tooie: blends the seams of clamped textures, such as the lines between the pieces of the title's logo (DEV
    // option, on by default).
    void SetSceneTextureSeams(bool blend);
    bool SceneTextureSeams();
    // ranges: each texture's darkest and lightest brightness (0 to 255, two a texture), its deepest and highest parts.
    // styles (or none): each texture's shape (bits 0 to 2), depth (3 to 5) and no shadows (6), as
    // RASTER_PARALLAX_NO_SHADOWS and the bits beside it in rt64_raster_params.h.
    // fineDepths: 0 for the style's depth, else the depth in 10% steps (1 to 31).
    void SetSceneParallaxTextures(const uint64_t *hashes, const uint8_t *ranges, size_t count, const uint8_t *styles = nullptr, const uint8_t *fineDepths = nullptr);
    // Banjo-Tooie: parallax pick mode: the cursor (x, y from 0 to 1 across the window) picks the nearest textured
    // surface of the 3D world under it, or the one layer deeper, and draws with that texture are highlighted.
    void SetScenePick(bool on, float x, float y, uint32_t layer);
    // The texture last picked (0 for none) and how many textured surfaces lie under the cursor.
    void ScenePickResult(uint64_t &hash, uint32_t &layers);
    // Where the game's picture is drawn in the window (fractions of the window), set by the VI renderer.
    void SetSceneOutputRect(float x, float y, float width, float height);
    // For the frame being drawn: pick mode on, the cursor in normalized device coordinates, the texture to highlight.
    bool ScenePickCursor(float &ndcX, float &ndcY, uint64_t &highlight);
    // A textured surface under the cursor at that depth (w); FinishScenePick picks among those of the frame.
    void AddScenePickHit(float w, uint64_t hash, uint32_t matrixId = 0);
    // The matrix group id of the nearest hit (0 when unknown, G_EX_ID_AUTO when the game gave none) with the picked texture, for picking a model.
    uint32_t ScenePickMatrixId();
    // Whether the draws with the picked texture are highlighted (off while a model is picked, the game highlights it).
    void SetScenePickHighlight(bool on);
    void FinishScenePick();
    // Fills the frame's parallax terms (after ComputeSceneGrass filled the camera's). False when it is off.
    bool ComputeSceneParallax(interop::FrameParams &frameParams);
    // The camera terms parallax mapping finds a pixel's place with (FrameParams.parallaxCameras), for a draw's projection
    // and its framebuffer's viewport. False for a projection that isn't a perspective one.
    bool SceneParallaxCamera(const interop::float4x4 &projection, const interop::float3 &viewportScale, const interop::float3 &viewportTranslate,
        float viewportWidth, float viewportHeight, interop::float4 &depthTerms, interop::float4 &projectionTerms);
    // Displaced ground's camera terms for a draw's framebuffer (FrameParams.groundCameras): the world to clip space map's
    // four rows, then the camera's world position. False for a projection that isn't a perspective one.
    bool SceneGroundCamera(const interop::float4x4 &projection, const interop::float4x4 &view, const interop::float4x4 &viewProj,
        const interop::float3 &viewportScale, const interop::float3 &viewportTranslate, const interop::float2 &resolution, interop::float4 *terms);
    // A texture's brightness range for parallax mapping (darkest | lightest << 8), 0 for none or when the original
    // textures are off (only meaningful after ComputeSceneParallax returned true).
    uint32_t SceneParallaxTexture(uint64_t hash);
    // Banjo-Tooie: a texture's material from the parallax list and Parallax pick mode's picks (its shape + 1: metal 12,
    // tiles 14, smooth 16), whether or not Parallax is on; 0 for none.
    uint32_t SceneMaterialTexture(uint64_t hash);
    // Banjo-Tooie: Ray Tracing Material Pick Mode's materials for the traced pass (production PBR), one for each picked
    // texture. albedoRoughness: red | green << 8 | blue << 16 | roughness (0 to 100) << 24. metalnessEmissive: metalness (0 to
    // 100) | emissive (percent, 0 to 1000) << 8 | subsurface (0 to 100) << 24. A drawn surface carrying one has its albedo tinted, reflects by its
    // metalness through a lobe as wide as its roughness, and glows by its emissive, where the rays meet it too.
    void SetSceneRayMaterials(const uint64_t *hashes, const uint32_t *albedoRoughness, const uint32_t *metalnessEmissive, size_t count);
    // Whether the water mask should be drawn this frame (reflections on, or the F6 water view).
    bool SceneWaterWanted();
    // Banjo-Tooie: the flat water went into the water mask tessellated (WaterTess.hlsl) for this worker's next effects pass.
    void MarkSceneWaterTessellated(RenderWorker *worker);
    // Gets the water mask ready (cleared, with the depth target attached) and sets it as the framebuffer;
    // the caller then redraws the water's draw calls into it with RasterParams.waterMask set. The second
    // target (colors true) takes the same draws' own colours and blending alpha (RasterParams.waterMask 2),
    // which Modern water is tinted with.
    RenderFramebuffer *BeginSceneWaterMask(RenderWorker *worker, RenderTarget *colorTarget, RenderTarget *depthTarget, bool colors = false);
    // Debug views (0 none, 1 the effects alone as grey, 2 depth: near white, far dark, sky blue, 3 normals, 4 water mask),
    // and F8 compare (the effects only on the left half).
    void SetSceneEffectsView(uint32_t view, bool compare);
    SceneEffectsSettings GetSceneEffects();

    // Whether the effects should be drawn into a framebuffer with this depth target.
    // Banjo-Tooie: whether any picture effect that reads the scene's depth is on.
    bool SceneEffectsAnyOn();
    bool SceneEffectsWanted(const RenderTarget *depthTarget);

    // Draws the effects into the color target from the depth target, during a framebuffer's drawing.
    // Leaves the color target ready for color writes and the depth target ready for depth writes, with
    // no framebuffer set. projection is the 3D world's projection; when it isn't a perspective one
    // nothing is drawn. drawSunCasters draws the 3D world's solid triangles into the sun shadow map, with the
    // map's framebuffer, pipeline and constants already set (it binds its own descriptor set at 0 and index buffer).
    void RecordSceneEffects(RenderWorker *worker, RenderTarget *colorTarget, RenderTarget *depthTarget,
        const interop::float4x4 &projection, const interop::float4x4 &view, const ShaderLibrary *shaderLibrary, const RenderRect &area,
        float depthScale, float depthTranslate, const std::function<void(RenderCommandList *)> &drawSunCasters = {});
};

#endif // RT64_EXT_RENDER_RT64_SCENE_EFFECTS_H
