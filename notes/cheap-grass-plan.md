# Cheap 3D grass: plan (2026-11-12)

Goal: 3D grass blades on the grassy ground, and the game's tall grass replaced with the same blades, at a cost
small enough to leave on. Budget: **under 0.5 ms GPU at 1440p on L's card in Spiral Mountain, under 0.1 ms CPU a
frame**, measured with the console's `costcheck`. Nothing here is built or tested yet.

## Status (2026-11-12, branch grass-cheap)

Built and run headless on this PC (RTX 5080, 2534x1140, Vulkan); not yet played on L's PC or a Steam Deck.

- Steps 1 to 6 are in: the bake, near and mid bands, wind, Banjo's push, the tall grass and the four settings
  (Graphics > 3D Grass), with the `grass` console command.
- Measured with `costcheck`. Wooded Hollow at the defaults: 0.00 to 0.02 ms of GPU time (about 10,000 blades).
  Spiral Mountain: 0.02 to 0.05 ms. Density 200 and Distance 10000 (the frame budget reached): 0.13 ms. The CPU
  spends about 0.03 ms a frame on grass, and baking about 3 to 7 ms on a frame a patch first comes within reach.

What changed from the plan below, and why:

- **Colour.** Each blade's colour is worked out in the vertex shader: the ground's own texture, colour combiner and
  fog. The pixel shader returns it at once. The first try ran the full material per blade pixel: 0.53 ms for 10,000
  blades.
- **Blade shape.** Near blades are 9 vertices (one bend and a tip), not 15. The frame budget is 80,000 blades, not
  150,000. That halved the worst case.
- **Bake timing.** Blades are baked at the end of a frame and only for patches within reach (1.3 x Distance), at
  most about 3 ms a frame. Baking a whole level at once was a 98 ms stall.
- **Roads and paths.** These are the frame's flat non-grass draws. A decal covers the grass it lies on; other
  ground only covers grass when it sits above it.
- **Tufts.** Tufts of 4 blades fan out from one root, with one colour and one rank each, so a tuft thins out as one.
- **Edge-on blades.** A blade seen edge-on turns part of the way to the camera. Its widening to one pixel is capped
  at 3x: uncapped, edge-on far blades became giant slabs.
- **Tall grass.** It only grows on walls up to 90 units high.

Later the same day (L: "0.5 is also too high", "really good view distance", replace the long grass):

- **Distance.** Distance is 15000 by default (up to 40000). Past 900 units the share of blades kept falls with the
  square of the distance (about even spacing on screen), and kept blades widen up to 4x. A whole draw is passed over
  at once when its box is out of view or reach.
- **Replace Long Grass** (on by default). The strip's draw (one whose triangles are all wall) is drawn through the
  uber pixel shader with RASTER_GRASS_WALL: its texture averaged to a soft plain green. Skipping it left holes, since
  the strip is the lawn's side. Tall blades (half again the strip's height) have their own tiles, drawn whole
  wherever in reach.
- **Old against new**, same spot (Wooded Hollow start, RTX 5080, 2534x1140, the Effect Cost Check):

  | Version | Setting | GPU time |
  |---|---|---|
  | Old 3D grass (commit 792ef342) | amount 50, default 1800 reach | 0.81 and 1.01 ms (two runs) |
  | Old 3D grass | 6000 reach | 2.05 ms |
  | New 3D grass | defaults, 15000 reach | -0.12 to 0.02 ms (within the noise) |
  | New 3D grass | Density 200 (frame budget reached) | 0.13 ms |

  The old runs were noisy: no pipeline cache, and frame times of 33 to 36 ms against 8.3 ms.

Still to do:

- Re-add grass and tall-grass picks to Shader Effects pick mode.
- A trample map for Banjo's trail.
- Check more levels: Mayahem Temple, Witchyworld's edges, Cloud Cuckooland.

## The look: like EmmetOT/HDRPGrass

L's reference is https://github.com/EmmetOT/HDRPGrass, a stylised blade field after Roystan's grass tutorial:

- tapered blades with a root-to-tip colour gradient, and a field-wide tint from the ground texture;
- wind pushing the blades in waves;
- spheres that push the grass aside;
- the blades take the **ground's normal**. Its author says this "looks the best by far", and it is also the cheap
  choice, since a blade is lit exactly like the ground under it.

Its LODs are three distance bands, each with its own density and number of segments.

Its author's own conclusion matches this plan. They would not use tessellation again: it was hard to get working
and took a lot of video memory. Their faster version spreads a fixed number of points over the ground once and
keeps the generated blades.

The repo has **no licence**, so no code is copied from it, only the ideas above.

## Fitting Banjo-Tooie's art style

The game's ground is low-resolution, painterly textures lit by baked vertex colours: bright, saturated and soft,
with no realistic detail. Thin, realistic, photo-like blades would look pasted on. So:

- **Few, wide, chunky blades in tufts.** Short and broad, a gentle taper to a rounded or blunt tip, gathered in
  small clumps (cellular noise, as in Ghost of Tsushima) so the field reads as soft shapes rather than hair. This
  is also the cheap choice: fewer, wider blades mean fewer vertices and less shimmer.
- **Colour comes from the game, never from a palette of ours.**
  - The blade's root takes the grass texture's texel, filtered the way the game draws it, times the ground's
    **vertex colour**. Rare's baked shading and shadow then carry up the blade, and dark corners stay dark.
  - The tip is the same colour, slightly lighter and more saturated. There is no new hue.
- **Flat, soft shading.** No specular, no subsurface, no hard rim: the ground's own vertex colour and normal,
  plus a little darkening at the root. Lit like the ground, it sits in the ground.
- **Height** is about Banjo's ankle to knee on plain grass, and taller only on the tagged tall grass. The ground
  texture stays visible between tufts, so the game's painted detail is never buried.
- **Motion** is slow, rolling waves of wind, like the game's own swaying plants, not fast jitter.
- Each level's grass texture differs (Spiral Mountain, Mayahem Temple, Cloud Cuckooland), so taking colour from
  the texture keeps every level in its own palette without per-level tuning.

Check: a side-by-side screenshot of each test spot with the grass on and off. If the grass is the first thing
noticed, it is too tall, too dense or too far from the ground's colour.

## Making it usable: the last grass's problems and what stops each here

| Last time | This time |
|---|---|
| Blades through roads, paths, cobbles and stone floors (each fixed one at a time) | Tested once at bake and kept: the root's own texel must be grass-coloured, vertex alpha must be high, and no non-grass draw may cover the root. A `grass mask` debug view shows what was rejected. |
| Grass growing as Banjo walks up; whole patches switching detail; blades re-picked as the camera moved | Blades are baked at fixed world spots and never moved; distance only lowers the count by rank, and a blade shrinks away before it goes |
| Banjo's shadow flickering through the grass | Blades take the ground's normal and its shading, including its shadow, at their root, so they share whatever shadow the ground has |
| Vanishing with an unrelated draw's "no effects" mark, broken by occlusion culling, geometry shader output limits on D3D12 | No per-draw state carried across draws, no occlusion culling, no geometry shader |
| Shimmering far blades | Minimum width of one pixel, colour blended to the ground with distance, far band has no blades |
| A dozen-plus sliders and toggles (density, patches, thickness, length, edges, chunky, pixelated, chunk size, pixel size, blending, LOD, 30 FPS, three cull toggles, ray tracing) | Four settings: 3D Grass on/off, Density, Distance, Height. Everything else fixed or console-only. |

The plan's console commands:

- `grass stats`: blades baked, blades drawn and the time each takes;
- `grass view lod`: colours the near and mid bands, like HDRPGrass's LOD debug view;
- `grass view mask`: shows where blades were refused;
- `grass rebake`: bakes the grass again.

## Why the last grass was too expensive

The last 3D grass (removed in 8ef84106) redid everything every frame:

- a compute pass with one thread per *candidate* blade over all grass ground, placing each blade again, testing it
  against roads, the frustum and a depth pyramid, and appending the survivors;
- a two-level Hi-Z depth pyramid built each frame for that test;
- a road/path mask worked out per ground draw on the CPU (20 ms a frame, later cut to 1 ms with caching);
- an indirect draw per ground draw;
- with ray tracing on, a BLAS of up to 131072 blades rebuilt whenever the pass ran.

The research says most of that buys little. In Jahrmann & Wimmer 2017 (compute culling and tessellated blades,
398k blades), the culling and indirect setup cost 0.55 to 1.4 ms on their own. Occlusion culling removed only 6k
of 398k blades (1.5%); frustum and distance culling did nearly all the work.

## What the research says (sources at the end)

- **Jahrmann & Wimmer 2013** (the paper L linked): blades are quads that hardware tessellation subdivides by their
  height on screen, shaped by a Bezier curve. 137k to 348k blades at 12 to 15 ms on a GTX 680 at 1200x800. Worth
  taking: the LOD rules. Each blade has its own random number that is compared with its distance, so far blades
  drop out one at a time and stay put; there are fewer segments with distance, down to one quad; and far grass is
  darkened and blended to hide noise.
- **Hardware tessellation is not the cheap part.** Blades are thin, sub-8-pixel triangles, the case GPUs handle
  worst (NVIDIA's 2010 tessellation guidance; tiny triangles measured 10 to 20x slower than ideal). The hull and
  domain stages add cost at the low factors grass uses. We already pay for it on deep snow and sand. **Not used
  for blades.**
- **Ghost of Tsushima** (GDC 2021; the slides are behind GDC Vault's login, so second-hand write-ups only):
  - Blades are built in the vertex shader from SV_VertexID with no vertex buffer: 15 vertices near and 7 far.
  - Far tiles are twice the size with the same blade count; near tiles drop 3 of 4 blades before the switch, so
    density matches across it. This is the same idea as our rank prefix.
  - Voronoi clumps share height, lean and colour, and blades seen edge-on are widened in view space.
  - The often-quoted 83k blades on screen at about 2.5 ms (PS4, presumably) is **not verified**.
- **Fill rate is the real risk, not vertices** (Sarkosh 2026, a browser meadow write-up with shipped references):
  - About 430k grass triangles cost 0.2 to 0.5 ms of vertex work.
  - Grass covering 55 to 65% of the screen in 3 to 5 layers is what costs.
  - Dithered or alpha-tested blades added 10 to 20 ms in its test.
  - So the blades are opaque with no `discard`, and wide-but-few is the right trade.
- **No grass in shadow maps.** GodotGrass calls it "very high" cost. Ours takes the ground's shadow at the root.
- **Player interaction:**
  - Red Dead Redemption 2 keeps a trample render target (4096² texels over 48 m for mud).
  - A UE/Niagara grass breakdown draws the player's feet into one from below and fades it back.
  - It costs about the same as one sphere but also gives a trail. It's a later step.
- **Witcher 3 (REDengine 3):** blades take the ground's colour from a low-resolution colour map (the "pigment
  map"), the shipped form of our take-the-ground's-colour rule.
- **Horizon Zero Dawn** (GDC 2017): GPU placement of 100k+ objects in about 0.25 ms. Placement can be cheap if it
  is not redone needlessly.
- **Shells** (Lengyel's fur, as our deep snow does): work on any triangles but cost N times the ground's fill
  rate. Only worth it as a thin far layer, if at all.
- **Jahrmann 2016 master's thesis** (TU Wien; distance culling read in the PDF):
  - A blade is dropped when `id mod n < n·d/dmax`, the published form of our rank prefix. It only works when
    neighbouring blades have unrelated ids, which a hashed rank gives.
  - Going from 3 levels to 9 culls only 5 to 7.5% more, and they look the same.
  - Per-frame visibility compute cost 0.55 to 0.89 ms against 1.4 to 2 ms of drawing (GTX 780M, 1024x768): close
    to half again on top. That is why the last grass was slow, and why ours bakes.
- **Cook, Halstead, Planck, Ryu 2007, "Stochastic Simplification of Aggregate Detail"** (Pixar; seen through a
  summary and a later paper, not the PDF):
  - Remove a random share of elements and scale the rest so the total area stays the same.
  - So a tile drawn with a share f of its blades widens them by about 1/f. That keeps the field's colour and
    coverage as it thins, the "fewer but wider" rule, and it suits the chunky art style. Width is capped at 2x.
    Check the exact formula in the PDF before relying on it.
- **Persson's "phone-wire AA"** (Humus): clamp a thin shape's width to 1 pixel and fade it by how much it was
  widened. The fade needs blending or alpha-to-coverage, which costs fill rate, so we take only the width clamp
  and blend the colour toward the ground instead.
- **Franzin, Pozzer, Nascimento 2019** (SBGames, GTX 1070): instanced plants in 16 m cells with 3 discrete LODs of
  8/4/3 triangles, and per-cell LOD batching at 0.08 to 0.81 ms CPU. This supports 2 to 3 fixed bands per tile.
- **Habel 2007/2009** (volumetric grass ray-marched in the pixel shader, 2.6x faster than billboards on a GTX 280),
  **Boulanger 2009** (geometry, then lit slices, then texture) and **Decaudin & Neyret 2004** (volumetric
  textures) are far-distance techniques costing pixel work. Our far band has no grass at all, so none is needed
  now. Boulanger's thesis and Fan et al. 2015 (I3D, "Simulation and rendering for millions of grass blades")
  could not be downloaded.
- **No paper gives modern ms-per-blade figures** for our case. The budget is set by measuring: costcheck on L's
  PC, and a Steam Deck-class GPU if one is available.

## The design: bake once, draw prefixes

The key change: **blade placement is baked once per piece of ground and kept**, not worked out every frame. Each
frame, the CPU picks which baked tiles to draw and how many of their blades. The GPU only runs a vertex shader
over them. There is no compute pass, no depth pyramid and no road mask per frame.

### 1. Find the grass ground (exists)

Draws whose texture carries the **grass** Shader Effects pick, as now. The per-draw redraw hook that deep snow,
fur and feathers use (lib-patches/rt64.patch, after `drawCallTriangles`) is where grass draws are seen. The camera
terms come from `ComputeSceneGrass`, as for snow and parallax.

### 2. Bake (once per ground draw, cached)

When a grass draw is seen whose geometry has not been baked:

- Key it by its vertex data's address, count and a checksum of a few vertices, so a static level draw is
  recognised every frame for almost nothing.
- Run a small compute pass over its triangles, once. Lay blades on a world-space grid (stable as the camera
  moves), using `CellHash.hlsli` for jitter, height, lean and a rank number from 0 to 1.
- Drop a blade where the ground isn't grass: the texture's colour at the root isn't grass-like, or the vertex
  alpha fades the grass layer out (Spiral Mountain's cobbled road). Store the root's colour with the blade.
- Store blades in **world tiles** (about 512 units), each **sorted by rank**. Drawing the first N blades of a
  tile then gives an even, thinner spread of the same blades, so density and LOD are just counts.
- 16 bytes a blade: packed position, colour, rank, lean and height. Bake at the highest density the slider
  allows, so moving the Density slider never re-bakes and applies at once.
- Cap: about 1M blades a level (16 MB). The bake runs on load and when new ground first appears, not per frame.

Ground that moves (a platform, or a model rather than level geometry) re-bakes when its checksum changes, and is
left out if it changes every frame.

### 3. Per frame (CPU, a few hundred tiles)

For each baked tile near enough: test its box against the view frustum, pick the blade count from distance
(full near, falling off to 0 at the far limit), and pick the LOD band:

| Band | Distance | Blade |
|---|---|---|
| Near | 0 to ~15 m | 7 vertices (3 segments), full count |
| Mid | ~15 to ~40 m | 3 vertices (1 triangle), wider, fewer |
| Far | past ~40 m | no blades; the ground's own shading takes the colour |

A **hard frame budget** (about 150k blades) scales every tile's count down together when the view holds more.
That makes the cost flat however much grass is on screen. Each band is one instanced draw over a list of
(tile, count) pairs: 2 draws a frame, after the world's opaque draws.

### 4. Vertex shader only (GPU)

No vertex buffer. `SV_VertexID` picks the point along the blade and `SV_InstanceID` the blade. The blade
record gives its root.

- **Shape:** a quadratic curve bent by its lean.
- **Wind:** a sum of two moving sine waves through world space. No texture reads.
- **Banjo pushing it aside:** one sphere at his position.
- **Fading out, no popping:** a blade shrinks to zero height as its rank nears the tile's cut-off, so blades
  fade out one at a time instead of popping. The blades that remain widen by about 1/(share kept), capped at 2x
  (Cook et al. 2007), so the field keeps its colour and coverage as it thins.
- **Shimmer:** a minimum width of about one pixel stops far blades flickering, and a blade seen edge-on is widened
  in view space (Ghost of Tsushima), so a tuft never turns into a line.

Blades past the cut are collapsed to a point and cost only the vertex work.

The pixel shader is opaque, with no alpha test, so early depth rejection keeps working:

- **Colour:** the stored root colour, darker at the root and lighter at the tip, blended toward the ground's
  colour with distance.
- **Light:** the ground's normal at the root, with the Relighting sun as one N·L term, so a blade matches the
  ground it stands on.

### 5. Tall grass (the long grass in front of Jiggywiggy's Temple, Wooded Hollow, map 0x14F)

Found (2026-11-12, `warp id 14F 0`, headless pick, texture dump):

- It is the strip of long grass along the sides of the raised lawns, between the lawn and the path. It is level
  geometry: the upright riser faces of the lawn, textured with **opaque** blade textures `9ecdd16b47696c54` (32x32)
  and `8cba02d249bdd9ec` (16x16). The lawn's top is `37cf9756bf11bfcc`, already a grass texture.
- Since the strip is the lawn's wall, removing it would open a hole. So the original faces stay as a backing, and
  tall blades are baked along each face's **bottom** edge, as high as the face, leaning out a little, in front of it.
- Add a **tall grass** pick, with these two built in.

It costs nothing extra per frame: it is just more baked blades.

### What is left out on purpose

- Hardware tessellation for blades.
- Per-frame compute placement.
- Hi-Z occlusion.
- A per-frame road mask.
- Grass in the ray-traced scene: it doesn't cast traced shadows. It could come later as a cheap trick, such as
  darkening the blade by the traced shadow already in the frame at its root.
- Banjo's trail.

## Steps, each measured with `costcheck` before the next

1. **Find the tall grass:** in Wooded Hollow (map 0x14F), in front of Jiggywiggy's Temple, with the console; note its hashes and draw type.
2. **Bake and draw near band only, no wind:** check the blades stay put, the CPU cost, and the GPU cost at
   1440p with 150k blades.
3. **Mid band, distance fade, frame budget:** check for no pops and a flat cost when looking across a field.
4. **Wind, Banjo push, colour blend:** check the cost stays inside the budget.
5. **Tall grass replacement:** the area in front of Jiggywiggy's Temple.
6. **Settings:** under Graphics, a 3D Grass switch with Density, Distance and Height. All apply at once (density
   and distance are counts, so no re-bake).
7. **Spot checks:** Spiral Mountain, Mayahem Temple, Witchyworld's edges, Cloud Cuckooland, then L on a real PC.

If step 2 can't stay under 0.3 ms GPU for the near band alone, stop and rethink before building on it.

## Risks

- **Roads and paths laid over the grass as separate draws** (decals) aren't seen by the bake's own-texture test.
  The plan: at bake time, also read the non-grass draws that overlap the baked tile in that frame, once (the old
  road check, run once instead of every frame).
- **Ground the game re-uploads with new addresses each frame** would defeat the cache key. If so, fall back to a
  checksum of the vertex positions only.
- **The sub-pixel blade cost** is the real limit; the hard frame budget is the safety net.

## Sources

- Jahrmann & Wimmer 2013, Interactive Grass Rendering Using Real-Time Tessellation:
  https://www.cg.tuwien.ac.at/research/publications/2013/JAHRMANN-2013-IGR/JAHRMANN-2013-IGR-paper.pdf
- Jahrmann & Wimmer 2017, Responsive Real-Time Grass Rendering for General 3D Scenes:
  https://www.cg.tuwien.ac.at/research/publications/2017/JAHRMANN-2017-RRTG/JAHRMANN-2017-RRTG-draft.pdf
- Wohllaib, Procedural Grass in Ghost of Tsushima (GDC 2021):
  https://gdcvault.com/play/1027033/Advanced-Graphics-Summit-Procedural-Grass
- van Muijden, GPU-based procedural placement in Horizon Zero Dawn (GDC 2017):
  https://www.guerrilla-games.com/media/News/Files/GDC2017_VanMuijden_GPUBasedProceduralPlacementInHorizonZeroDawn.pdf
- NVIDIA, Tessellation performance (GDC 2010):
  https://developer.download.nvidia.com/presentations/2010/gdc/Tessellation_Performance.pdf
- Small-triangle cost: https://www.g-truc.net/post-0662.html
- Pelzer, Rendering Countless Blades of Waving Grass (GPU Gems 1, ch. 7):
  https://developer.nvidia.com/gpugems/gpugems/part-i-natural-effects/chapter-7-rendering-countless-blades-waving-grass
- Unity-Grass (compute and indirect blades): https://cainrademan.github.io/Unity-Grass/
- EmmetOT, HDRPGrass (no licence; ideas only): https://github.com/EmmetOT/HDRPGrass
- Sarkosh, Grass, wind and trails in a browser meadow (2026): https://csarko.sh/research/grass-and-trail-realism
- Ghost of Tsushima grass, second-hand: https://tigerabrodi.blog/what-we-can-learn-from-grass-in-ghost-of-tsushima-renders
  and https://jairsantana.com/posts/grass/ ; talk page https://gdcvault.com/play/1027033/Advanced-Graphics-Summit-Procedural-Grass
- GodotGrass (edge-on widening; shadow cost): https://github.com/2Retr0/GodotGrass
- Trample render target in UE/Niagara: https://pixelantgames.com/blog/rendering-millions-of-grass-blades-using-ue-and-niagara/
- Jahrmann 2016, master's thesis (distance culling, TU Wien):
  https://www.cg.tuwien.ac.at/research/publications/2016/JAHRMANN-2016-IGR/JAHRMANN-2016-IGR-thesis.pdf
- Cook, Halstead, Planck, Ryu 2007, Stochastic Simplification of Aggregate Detail:
  https://graphics.pixar.com/library/StochasticSimplification/paper.pdf
- Persson, Phone-wire AA: https://www.humus.name/index.php?page=3D&ID=89
- Franzin, Pozzer, Nascimento 2019, GPU-Based Rendering and Collision Simulation of Ground Vegetation:
  https://www.sbgames.org/sbgames2019/files/papers/ComputacaoFull/198047.pdf
- Habel 2009, Real-time Rendering and Animation of Vegetation (PhD):
  https://www.cg.tuwien.ac.at/research/publications/2009/Habel_2009_PhD/Habel_2009_PhD-Thesis.pdf
- Boulanger, Pattanaik, Bouatouch 2009, Rendering Grass in Real Time with Dynamic Lighting (IEEE CG&A), not read.
