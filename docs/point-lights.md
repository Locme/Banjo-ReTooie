# Point Lights

Graphics > WIP > **Point Lights** (off by default; applies at once) and **Point Lights Strength** (10 to 200%,
default 50).

Lamps light what is near them. The walls, the floor, Banjo and everything else brighten in their own colours as they
get closer to a lit lamp, on top of the light the game gives them. The light is worked out every frame, so a character
walking past a lamp lights up as they pass it.

## Why not the N64's own lights

The Mario Party 3 port adds its lamps as extra lights for the N64's hardware lighting. Banjo-Tooie uses none: the game
colours every vertex itself on the CPU, and no vertex is drawn with `G_LIGHTING`. A count in RT64 found 0 lit
vertices in Wooded Hollow and Mayahem Temple, with Banjo on screen. So there are no lights to add to.

Brightening the vertex colours on the GPU was tried next (2026-11-03). It lit only what the game left dark. Much of
the level, such as the grass, the paths and the temple blocks, is drawn at full vertex colour with its colour in the
texture, and the colour combiner wraps a shade above full instead of capping it. So there is no room to brighten
there.

## How it works

The lamps light the finished picture, per pixel, in the scene effects pass (`rt64-ext/src/shaders/SceneEffectsPS.hlsl`,
`PointLampsAt`):

- each pixel's world position and the way its surface faces come from the depth;
- each lamp brightens the pixel's own colour by up to its colour times the strength, smoothly falling to nothing at
  its radius, and most on the side facing the lamp;
- the light goes in the same `lamp` term the traced lamps add to, so it shares their fog, toon shading and bloom.

The sky and the HUD are never lit.

The lamps (`rt64-ext/src/render/rt64_scene_lights.h`) are the 8 nearest the camera from:

- **the lit lamps RT64 finds by their textures**: the same list the traced lights use (`SetSceneLampTextures`). They
  are lit warm white out to 600 units, a frame behind, from where they were drawn;
- **this map's lamps from `Dev Files/point_lights.txt`**, placed with the console (below). The file is read again
  about once a second when it changes.

The game's own lights (Glowbos, torches) are left out. The game already lights the vertices around them itself.

Cost: a loop over up to 8 lamps per pixel in a pass that is already drawn whenever any scene effect is on. Point
Lights turns the pass on by itself when no other effect is on. Frame rate and window shape don't change it.

## Placing lamps

Use the console's `lights` command (`docs/console.md`). `lights add [r g b [radius [height]]]` puts a lamp above Banjo,
`lights undo`, `lights clear` and `lights list` manage this map's lamps, and every change is saved. The file holds
one lamp a line: `<map hex> x y z r g b radius` (world units, colour 0 to 255, `#` starts a comment).

`TOOIE_POINT_LIGHTS=<strength %>` turns Point Lights on at that strength whatever the settings say (headless tests).

## Tested

- Mayahem Temple (map 0xB8), on a real PC, at 1622x912 with Unlocked frame rate:
  - a lamp placed above Banjo lit a warm pool on the grass and the stone path and lit Banjo, and turning it off
    removed it.
- Not yet checked:
  - other aspect ratios or frame rates;
  - D3D12;
  - a map whose lamps are found by their textures;
  - the strength's default against dark and bright levels.
- No lamp lists ship yet.

Written for this port on RT64 (https://github.com/rt64/rt64), after the Mario Party 3 port's Point Lights.
