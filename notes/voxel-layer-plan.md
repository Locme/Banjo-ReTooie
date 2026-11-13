# Destructible voxel layer: plan (2026-11-12, redesigned 2026-11-13)

Goal (L, 2026-11-12): a destructible voxel layer that reacts to the world and to
Banjo's moves: dirt, stone and the like that his attacks break. It does not need to be deep. Code:
`src/gameplay/voxel_layer.cpp`, `include/tooie_voxel_layer.h`.

## Behind the level's own geometry (L, 2026-11-13): the plan now

L, 2026-11-13: "It has to be behind the actual Geometry as we can't alter the game design of the level", 1-2 m
thick for most things and 2-4 m in real sand or dirt. The first build put blocks **in front of** the level (crusts
standing out of walls, mounds and pillars on floors), which changes the level's layout. That is replaced by the
plan below. Sections further down describe the first build. What it proved still holds: the floor hook,
standing on blocks, the materials and moves, eggs, breaking, debris and drawing in world space.

### L's rules (2026-11-13)

- **Reset on level exit.** Leaving a map puts its blocks back; nothing is kept between visits.
- **Later the same day:** sand and dirt break at one blow (dirt, grass-dirt, clay, sand); metal is unbreakable, and
  what is close to it (within 100); nothing within 300 of water breaks, so there is no water to make flow; a cell hit
  once but not yet broken has a cracked texture (made in code, the grain lighter with dark cracks); blue eggs break
  only sand, only the special eggs dig (grenade, clockwork, proximity: power 4, wide; fire 2, melting ice and snow;
  golden 3; ice 2).
- **A blow is a punch.** Every block takes at least two hits: no single blow does more than half a
  block's health. The first blow cracks the spot: the level's surface there gives way to cracked blocks in the
  same place (a dent). The next one breaks it open, with debris.
- **Only the needed blocks are drawn**: blocks struck, cracked, or next to a hole. The rest stay hidden behind
  the level's surface and cost nothing.
- **The gaps and risks below are dealt with**, not left as known gaps (shadows and ray tracing see the holes).

### The idea

The level looks and plays exactly as it does now until Banjo digs. The voxels fill the ground and the walls
**behind** their surface, 1-2 m deep (2-4 m in sand and dirt). A blow on the level's surface breaks the blocks
behind it. Where blocks are gone, the level's own surface is cut away, both in the picture and in its collision.
The hole's sides and floor are the blocks round it, drawn by us. So Banjo digs into the level.

### Blocks

- **World cells**, not patches. One grid of 18-unit cells, square to the world's axes (no yaw), so the GPU can
  test a pixel's cell with a hash lookup. They are stored as sparse 8x8x8 chunks, keyed by chunk.
  Material, damage, wet flag and a dug flag per cell.
- **Made when first struck, not up front.** Nothing shows until something is struck, so cells are filled only
  round a blow, and round each cell that is broken or cracked (so a hole's sides are always known). A cell is
  filled from its column: one line test with the map's own `func_800BEF00` (kind 0x20020, solid surfaces only,
  no objects or water) along the axis nearest the struck surface's normal, from outside in. The column's cells
  behind the surface, down to the layer's depth, are solid; those in front are air. Columns are cached, so a
  column costs one test. No tests are spent on parts of the map nobody touches, and the whole map can be dug.
- **Cell states:** unknown (not filled yet), air (in front of the level), solid, cracked (solid and damaged:
  shown), dug (broken), bedrock (the layer's deepest cell: never breaks).
- **Depth and material.** Depth is 1-2 m, and 2-4 m where the surface is sand or dirt. The material comes from
  the world's palette (as now). Open question: whether the floor triangle's flags (the word at +8, the one the
  game uses for footstep sounds) can say sand, grass or stone. If they can, they decide the material.
- **Bedrock.** The deepest layer of every column cannot be broken, so nothing digs out of the bottom of the
  world. A hole always has a floor and sides of blocks.

### Holes in the picture (RT64)

- The level's own draws are already known in our RT64 patch: `levelGeometry()` in `lib-patches/rt64.patch`
  (one world matrix, the identity). The deep snow and sand already change those draws per pixel with world
  positions and a cell grid (`Snow.hlsli`, `snowTrail` in `rt64_scene_effects.cpp`).
- **New:** a per-instance flag for level draws, and in `RasterPS` a test of the pixel's world position against a
  hashed set of cut cells (dug and cracked ones, and the solid ones next to a hole, whose own faces are drawn) (a structured buffer of packed cell keys, open addressing). A pixel inside a dug cell
  is discarded. The position is first moved half a block into the surface (the normal from `ddx`/`ddy` of the
  world position), so the surface is cut by the cell behind it, not the one in front.
- The game passes the set with a new `RT64::SetSceneVoxelCuts(keys, count)`, as the other `SetScene*` calls do.
  It is sent only when the set changes.
- Models (Banjo, enemies, objects) are never cut.
- **Shadows and ray tracing see the holes too** (L: the gaps are to be dealt with): the sun shadow maps' pixel
  shader discards the same way, and the ray-traced passes reject level hits inside cut cells. Where exactly is
  being worked out from the RT64 patch (`notes/voxel-layer-plan.md` will say).
- **Cost:** only level draws whose world bounds touch a cut cell get the flag (worked out from the draw's
  vertices, which are in world space for the level), so early depth stays on everywhere else.

### Drawing the blocks

- Only cut cells are drawn: a cracked cell's faces toward air or dug cells, and the faces of solid cells round a
  hole. Same meshing, ambient occlusion, grain texture and colours as now, with damage as cracks. An untouched
  layer draws nothing and costs nothing.
- Meshes are per chunk, rebuilt when a chunk changes, in the same arena and slots as now.

### Collision

- **Floors and ceilings:** the existing hook at the exit of `func_800C6A7C` (0x800C6B4C), with a second hook at
  its entry that keeps the line's own end. When the providers' nearest hit lies in a dug cell, it is dropped and
  the test is run again from just past it to the kept end (guarded against recursion), so Banjo falls into the
  hole. A block's top is a floor (and its bottom a ceiling) only where the cell above (below) it is dug: intact
  ground keeps the level's own surface, even where a cell's top stands a little above it.
- **Walls:** `func_800C6C94(centre, radius, push_out, kind)` asks each provider's sphere push in turn (provider
  table at 0x8012AA40, slot +8). A hook at 0x800C6D14, right after each provider returns, drops a contact
  (sets `v0` to 0) whose contact point (centre minus the push direction times the radius) lies in a dug cell.
  The caller, `func_800FAE44` (Banjo's sphere push from `func_800D4584`), then ignores that push. The hole's own
  sides push him as `collide()` does now.
- **Swept walls:** `func_800C6B78` (slot +4), used by `func_800D4584`'s second pass, gets the same treatment at
  0x800C6C0C.
- The game keeps triangle pointers across frames, so contacts are dropped every time, consistently. No fake
  triangles are made for walls.
- Other actors use the same tests, so enemies and eggs fall into holes too. If that misbehaves, the hooks check
  that the probe is Banjo's.

### What goes

- Crusts standing out of walls, and mounds, boulders and pillars on floors: removed (they change the layout).
- The ring-of-cells generator and the per-patch yaw: replaced by world cells made when first struck.
- What stays: materials and palettes, hardness and health, moves and their power, eggs, damage and wetness,
  falling loose blocks (now within the layer), debris, sounds, persistence per map, the settings and console.

### Order of work

1. World-cell store and lazy chunk filling from rays; the console `voxel hit` digs into a wall or floor (log only).
2. Floor hook: drop hits in dug cells and run again; Banjo falls into a dug hole in the floor.
3. Wall hooks at 0x800C6D14 and 0x800C6C0C; Banjo walks into a dug hole in a wall.
4. Chunk meshes of the hole's sides and floor.
5. RT64: the level-draw flag, the dug-cell buffer, the discard in `RasterPS`, `SetSceneVoxelCuts`.
6. Remove the old crusts and floor pieces; settings and docs.
7. Test each step in game; check the shaders with `dxc-linux` for the Linux build.

### Risks

- Discarding in `RasterPS` turns off early depth for level draws that are flagged. Flag only level draws that
  have a dug cell on screen, or only those near a hole.
- The swept sphere's arguments (which pointer is the start and which the end) are read from the code but not
  checked in game.
- A hole the game's own scenery covers (a decal, a second surface just behind) shows that surface; it is not cut
  unless it is level geometry too.
- The game's camera may not see into a deep hole. The free camera's own sweep (`func_800FAB50`) may need the
  same cut.

### Later on 2026-11-13: L's look and the known flaws

- **Smooth, not cubes** (L: "smooth, not Minecraft squares"): Surface Nets over the cells'
  middles. An edge from a solid cell to open air along its column crosses at the level's own surface, so a dent's
  rim lies on the old ground. A whole cell beside a hole is drawn but keeps the level's surface over it; only dug
  and cracked cells are cut out.
- **Rounder cut edges:** RasterPS blends the four nearest cells of the row under a surface point and cuts where 65%
  of the blend is cut, so the cut curves between the cells' middles and the smooth rim reaches under it.
- **Plain colour, no texture** (L: textures didn't suit the game's look): only cracked cells keep the cracked
  texture (white with dark cracks, times the cell's colour).
- **The struck surface's colour:** RT64 keeps each texture's average colour (from its TMEM bytes as it is queued)
  and answers a colour asked for at a place from the next frame's level draws (texture average times the
  triangle's vertex colours). Each blow's new columns take it: 85% near the surface and in a pile, 55% deeper, 20%
  in a seam, the rest the world's material. A green floor is grass, and grass is dirt inside (L).
- **The rim** (L's drawing): digging down into sand or dirt piles two cells on the columns beside the hole and one
  beyond, rounded by the smooth surface. Not in walls or upward.
- **Debris:** rounded stones (an icosahedron with its corners pushed in and out), stretched differently each piece.
- **The void** (L's picture): a cell the blow's column put in open air is checked against the floor's column and the
  four sideways ones too, so ground under a floor beside a dug wall is solid and drawn. A dark backstop face sits
  where a dug cell meets open air, turned toward the dug cell (culled from the hole's mouth).
- **Loose cells fall:** a flood fill from the edges of a box round each blow, from bedrock and from ground not yet
  filled; what it doesn't reach breaks out as debris.
- **Out of bounds** (L): more than three cells under the lowest cut cell, everything is put back and Banjo returns
  to the last place he stood away from any hole.
- **Checked in game (Jinjo Village):** a dug crater with its rim, plain dirt colour, grass dirt inside; a hole in the
  cliff with rounded edges, green-grey inside; out of bounds caught and put back. A blow costs 0.1-0.9 ms.
  `dxc-linux` compiles all twelve changed shaders (RasterPS and RasterVS variants, SceneEffectsPS, the sun maps).
- **Still open:** break sounds (need picking by ear, `voxel sound`); no metal floor type found.

### Later still on 2026-11-13: the level's own textures, and the void

- **The level's own texture inside** (L: plain colour "doesn't fit in the texture style"; "the mountain is green so
  the insides should reflect on that"). RT64 keeps a 32 x 32 RGBA16 copy of each texture as it is queued, and the
  colour answer gives that texture's hash and how many world units its width covers on the triangle. The arena
  holds up to 15 a map, each with a cracked copy (darkened along the crack texture's lines). The faces take it at
  the grain's density, 16 texels a cell: the level's own size (RT64 works it out; the log prints it) looked plainer,
  and L liked the denser look better. A green floor is still dirt inside (grain in the dirt colour); a green wall
  and the floor and roof of a hole in it take the wall's texture, and its seams stay stone (L likes the bits of
  stone). A column that never got an answer takes the last one found on the map.
- **The wrong texture at a wall's foot** (L's picture: the zigzag path inside a cliff hole): the first triangle within
  16 units answered, so the floor answered for the wall. The ask now carries the struck surface's facing; only a
  triangle turned that way answers, the nearest of them.
- **Void at a hole's inner corner:** the cut's four-cell blend reached into the corner of a whole cell beside three
  cut ones, so that cell's surface went with nothing drawn behind it. The cell the point is over must now be cut too.
- **Slivers across a wall:** a backstop face filled a whole cell's side and stuck out in front of a wall; it is now
  trimmed to behind the level's surface, and none is put across a hole's mouth. A cracked cell's faces to open air
  are drawn only on its side to the level's surface.
- **False out of bounds:** standing on the ground below a hole high in a wall put everything back. Out of bounds now
  also needs a cut cell within four cells sideways above him and no ground of the level under him (a line test 2000
  down).
- **Settings (L):** Voxel Strength (blow power times it, reach times its square root) and a depth slider for each
  kind of ground, by the hardness of the level's ground: soft (sand, dirt, grass, clay, snow), stone, rock.
- **Inside the ground** (L: he really did fall out of bounds): feet and middle both more than a cell and a half behind
  the level's surface by a line-tested column, neither in a dug cell, for a sixth of a second: everything is put back.
  Checked: put inside the ground under a dig, he was put back on the ground.
- **`voxel void on`** (L: "make the whole sky magenta"): a scene effects view (23) that keeps the picture and paints
  every pixel nothing was drawn on magenta, so a gap shows as sky-magenta. It replaced a magenta box round the camera,
  which the level's own draws covered.
- **Cheaper to run (L):** the cut table's header (now twelve words) carries the lowest and highest cut cell, so
  RasterPS, the sun shadow map and the traced passes skip every point outside them without a look in the table (most
  of a level draw's pixels); RT64 reads the bounds from the header instead of walking the table, and a draw's check
  stops at its first vertex inside them. A colour answer remakes only the meshes within 14 cells of the blows it was
  asked for (it remade every mesh on the map). Not timed; checked that wall and floor holes still cut and draw.
- **`voxel voidscan`** looks for what the eye would call void (see docs/console.md). It follows the cells, not the
  smooth surface's own triangles, so a gap the smoothing opens could still slip past it. On the cliff hole and a dig
  in Jinjo Village it finds none.

### Where it stands (2026-11-13, tested in game)

- **Works in game** (Jinjo Village, Grunty Industries Floor 1, Jolly Roger's Lagoon, from a scratch copy driven
  by the console):
  - `voxel dig`: the level's floor is cut away over the dug cells and the hole's sides and floor are drawn; Banjo
    drops in, digs deeper with each blow, and jumps out.
  - `voxel hit ... wall`: a hole in Jinjo Village's cliff, with debris.
  - Grass-dirt and sand go at one blow; brick and stone crack first (the cracked texture shows), then break with a
    burst of debris.
  - Grunty Industries' walls are kept (metal). Leaving a map clears everything.
- **Learned on the way:**
  - The game's level draws use a world matrix that moves them without turning: the identity in Jinjo Village and
    Grunty Industries, a move by (-9000, 9000, -8000) in Jolly Roger's Lagoon, where its sections are even tagged
    objects. RT64's cut therefore takes any one-matrix draw with no turn or scale, except Banjo's and Kazooie's and
    the layer's own cells (`voxelLevelDraw`); the sun maps take the same.
  - A solid cell must be wholly behind the surface, or a dent stands up as a ledge.
  - Walls carry surface type 1, the same as plain ground, so metal walls can't be told by type: in Grunty
    Industries every wall counts as metal (`metal_walls`).
  - Floor surface types seen: 1 grass (Jinjo Village), 8 dirt path (Jinjo Village), 4 concrete or stone (Grunty
    Industries, Jolly Roger's Lagoon).
  - `TOOIE_VOXEL_RT_LOG=1` prints the draws near the cut cells with their matrices (a test aid).
- **Not yet checked in game:** the water rule (nothing within 300 of water breaks); eggs in this build; the traced
  passes and sun shadows through holes; a performance check.
- **Known flaws:** thin slivers at some hole edges (the level shows between faces); break sounds not picked; cells
  cut loose don't fall; no metal floor type found yet; not checked with `dxc-linux` for the Linux build.

## What voxel games do (sources at the end)

- **Everything is voxels**, and each voxel has one material, a density, a damage value and a wetness value.
  Voxels are stored in sparse 8x8x8 chunks. Empty chunks take no memory.
- **The mesh is generated from the voxels**, with Dual Contouring and triplanar textures, so players do not see
  cubes. Smooth-surface voxel meshing was not new. The work went into making it look real.
- **Materials behave differently.** Sand is soft and slippery, rock cracks before it breaks (damage), and ground
  near water darkens as it gets wet (wetness). Layers stack: grass over soil over rock.
- **Destruction drives the feedback.** Each break reports where it happened, how much broke and which material,
  and the game picks effects, sounds and the character's voice from that. Sounds are recorded Foley with many variations and
  random pitch, kept soft, because rock breaking is heard thousands of times.
- **Collision is not voxel against voxel.** Moving things are simple primitive shapes against the voxel mesh. The
  team accepted clipping where it favoured the player.
- **60 fps mattered.** At 30 fps the punch, the break and the debris did not read.
- Nintendo gives no hardness table and no move-against-material rules, so those are designed here.
- Other games: Teardown keeps a piece standing while one voxel joins it to the ground, and breaks off whatever
  is cut loose (a connectivity flood fill). Deep Rock Galactic carves meshes and uses the same carving for level
  generation as for digging. Minecraft-style meshes get their soft look cheaply from per-vertex ambient
  occlusion: two side neighbours and one corner neighbour per vertex (0fps.net), and the quad's diagonal is
  flipped to match.

## Fitting it into this port

The port can't add voxels to the game's own collision or level models, so the layer sits **on top of** them.

- **Not deep.** Wall crusts are 1-2 m thick, and 2-4 m where they are sand or dirt (L, 2026-11-13; a metre
  taken as 100 units, Banjo being about 105). That is 6-11 blocks, or 11-22. A crust is full depth in the middle
  and thins to its edges like a heap against the wall, with a smooth swell on its face. Rays out of the wall
  cut it back where needed to leave 260 units of open ground in front of it, so it narrows a passage but never
  closes one. Deep sand is sand half way in, over its base material. Floor pieces are mounds, rock piles,
  boulders and pillars standing on the game's floors, 1-2.3 m high. Breaking a crust shows the game's own wall behind it, as
  grass shows the soil.
- **Cubes, not Dual Contouring.** Chunky cubes with face culling, per-vertex AO, a per-voxel colour jitter and a
  small grain texture we make at run time (no game art) suit the N64 look and cost little. Each patch is meshed
  once and remeshed only when it changes.
- **Size.** A voxel is 18 units, about a sixth of Banjo's height. That is big enough to read as blocks and small
  enough that a swipe takes a bite rather than a wall.

### Drawing

- Each patch is a small 3D grid with its own origin and yaw. Wall patches are turned to face out of the wall.
- **The game's matrices.** The camera is all in the projection, and each model's modelview holds its world
  place (seen in game on 2026-11-13; place minus camera, as planned from Banjo-Kazooie, drew nothing). Each patch
  gets one `G_MTX` (its origin, then yaw) and a call to its mesh.
- **Where it goes in.** At `tooie_players_draw` (the entry of func_800F5008, inside the 3D scene, where
  `pose_puppets.cpp` already draws its copies) one `G_DL` goes into the game's list, behind
  `gfx_budget::room_for_extras`. Everything else lives in an arena of our own taken from the game heap, as
  `pose_puppets` takes its film. That covers the per-frame list, the matrices, the patch meshes and the grain
  texture.
- **Not rewritten while RT64 may read it.** The per-frame list and its matrices go round 8 slots, as
  `model_tagging.cpp` does. A remeshed patch gets a new block of the arena, and the old one is freed only 8
  frames later.
- **Interpolation.** Each patch's matrix gets an RT64 matrix group with an id of its own, so frames drawn between
  the game's own blend it smoothly. Each debris cube has its own matrix and id for the same reason.
- **Look.** Vertex colour = material colour x face shade (top 1.0, sides 0.82/0.7, bottom 0.55) x AO x jitter x
  cracks (damage darkens) x wetness. Combiner: grain texel x shade. Opaque, z-buffered, back faces culled. RT64's
  lighting and ray tracing see it as any other geometry.

### Placing it ("reacts to the world")

- **From the level's own collision.** Patches are placed with the game's swept line test
  (`free_camera::sweep_line`), in cells of 1200 x 1200 round Banjo, each seeded by the map and the cell so a
  map always gets the same layout. A few rays a frame do this, so the cost is spread out.
  - Each spot is found with a ray down to the ground, then 8 rays out from it.
    - A wall within reach gets a **wall crust**. Its every column is found with its own ray into the wall, so
      the crust follows a curved or stepped wall.
    - Open, level ground gets a **mound, boulder or pillar**. Each column's base is the ground under it.
  - Spots are left out under water, on steep ground and too near Banjo when found mid-play (no pop-in).
- **Materials by world**, from the map's name prefix:
  - Spiral Mountain and Isle o' Hags get dirt and stone.
  - Mayahem Temple gets sandstone. Glitter Gulch Mine gets rock with gold seams.
  - Jolly Roger's gets sand, Terrydactyland dirt and clay, Grunty Industries brick.
  - Hailfire Peaks gets ice and snow on one side and ash rock on the other.
  - Cloud Cuckooland gets cheese (after Odyssey's cheese rocks), and Cauldron Keep dark stone.
  - Crusts are layered. A soft top layer (grass-dirt, snow) sits over a harder one.
- **Wetness.** Voxels below a water surface near the patch are wet: darker, and a little softer.
- **Gravity.** After a break, a flood fill from the anchored voxels (those touching the game's wall or floor)
  finds what was cut loose, and that falls as debris.
- **Fire melts ice**, and grenade and clockwork eggs blow holes.

### Moves against materials

Each move hits with a power and a sphere placed by Banjo's position, yaw and state. Each voxel takes
`power x 10` damage when its material's hardness is no more than the power, and none otherwise. A blow that does
nothing makes a clink and a spark of dust, so the player learns what is hard. A voxel breaks when its damage
reaches its material's health.

| Move (state)                                    | Power | Hit                               |
| ----------------------------------------------- | ----- | --------------------------------- |
| Claw swipe (0x06), Pack/Wing Whack (0xE4/0xC2/C4) | 1     | small, in front                   |
| Forward roll (0x31)                             | 1     | in front, low                     |
| Rat-a-tat Rap (0x11)                            | 2     | in front, high                    |
| Beak Barge (0x13), Talon Torpedo (237)          | 3     | in front                          |
| Beak Buster (0x0F), Bill Drill (0xB6)           | 3     | under him, larger on landing      |
| Blue egg / fire egg                             | 1 / 2 | where it hits (fire melts ice x3) |
| Grenade / clockwork egg                         | 4     | a wide blast where it goes off    |

| Material                    | Hardness | Health | Note                          |
| --------------------------- | -------- | ------ | ----------------------------- |
| Snow, sand, cheese          | 1        | 10     | crumbles                      |
| Dirt, grass-dirt, clay      | 1        | 20     |                               |
| Ice                         | 2        | 20     | fire x3                       |
| Stone, sandstone, brick     | 2        | 30     | cracks show                   |
| Rock, dark stone, ash rock  | 3        | 40     | Beak Barge, Buster, eggs      |
| Gold seam                   | 3        | 60     |                               |

Continuous moves (roll, rap, drill) hit every 0.12 s while the state lasts. One-shot moves hit once when the state
starts. Eggs are found in the game's object list by model id, and an egg that hits a voxel is removed there.

### Banjo against voxels

- **Walls.** In the draw hook (after the game's physics, before Banjo is drawn), his body (a vertical capsule,
  radius 35, 110 high) is pushed out of any voxel taller than a step. His speed into it is cancelled. All the
  position copies are written, including +0x29C (the game's collision restarts from it).
- **Standing on top** (2026-11-13). The game finds every floor with `func_800C6A7C(from, to, normal, kind)`,
  which asks up to 8 collision providers (a table at 0x8012AA40) in turn. Each provider that hits moves `to` up
  to the hit, writes the normal and returns its triangle; the nearest hit wins. Banjo's ground goes through it
  (func_800C6060 -> func_800C5CC0 -> func_800C5BE4, floor height at +0x74 of his collision block), and so do
  enemies, eggs and shadows.
  - A hook at its exit (0x800C6B4C) answers the same test against the block tops. It only answers steep downward
    lines.
  - When a top is nearer than what the providers found, it writes `to` and an up normal, returns a fake triangle
    from the arena with the flags of the ground under the patch (for footstep sounds), and clears the hit's
    owner (+0x84).
  - A line that starts up to 12 units inside a block still finds its top, so he walks up a one-block step. The
    sideways push leaves blocks no higher than a step alone.
  - Four points 12 units round the line are tried too, so he doesn't drop off an edge while his middle is just
    past it.
  - To check in game: whether the game reads more of a floor triangle than its flags (the fake one has no
    vertices), which `kind`s reach the blocks (`TOOIE_VOXEL_LOG` prints each new one), and whether a one-block
    step lifts him or stops him.

### Debris and feedback

- Broken voxels fly out as small spinning cubes in the material's colour, away from the blow and up. They
  bounce once on the patch's ground and shrink away within about 1.5 s. There are at most 400.
- The sound is the game's own, at the place of the break, with pitch varied ±10%. Several breaks in one frame
  make one sound, louder. The material's sound id table is filled in by ear with `voxel sound <id>`.
- **Persistence.** Damage stays per map for the session. `voxel restore` puts the map back.

### Settings and console

- Gameplay > **Voxel Layer** (off by default). It applies at once: on generates patches round Banjo, off
  removes them and frees the arena.
- Gameplay > **Voxel Amount** (0-100, default 50), which sets how many spots get a patch. It also applies at once.
- Console `voxel`:
  - `on`/`off` and `info`.
  - `place <material> [wall|mound|boulder|pillar]` puts a patch in front of Banjo.
  - `hit <power> [radius]` and `restore`.
  - `regen`, and `sound <id>` to audition a sound.

## Risks and checks

- Heap room: the arena is 2 MB, or less when the heap's largest free block is short, with fewer patches then.
- Display list room: one `G_DL` and a few RT64 commands in the game's list, behind `room_for_extras`.
- The matrix convention, checked in Jinjo Village on 2026-11-13: the game's modelview holds the world place (the
  camera is all in the projection). Matrices of place minus camera drew nothing.
- Standing on top goes through the game's own floor test, so the game's ground snap lands him on the tops.
  The fake triangle is the risk: if some floor code reads its vertices, the triangle needs real ones.
- Cutscenes and locked states: no pushes or hits while the state is locked or the player is not in control.

## Sources

- Classmethod's CEDEC 2026 session report: https://dev.classmethod.jp/en/articles/cedec-2026-voxel/
- 0fps, Ambient occlusion for Minecraft-like worlds: https://0fps.net/2013/07/03/ambient-occlusion-for-minecraft-like-worlds/
- Unreal Engine spotlight on Deep Rock Galactic: https://www.unrealengine.com/spotlights/how-ghost-ship-games-found-success-with-deep-rock-galactic
- PC Gamer on Teardown: https://www.pcgamer.com/teardown-review/
