# Tools

## bin_to_obj.py

Converts model assets (`asset_<id>.bin` from the DEV tab's Dump assets, or a model mod's `assets/` folder) to a
`.glb` (glTF, textures inside) and a Wavefront `.obj` + `.mtl` with the textures as PNGs in `<name>_textures/`.
Python 3, standard library only. Banjo is `asset_062A.bin`.

```
py tools/bin_to_obj.py <asset_XXXX.bin> [more ...] [-o <out folder>] [-f obj|glb|both]
```

The model is written in its rest pose (no bones or animation), one object per geo-layout part, named
`p<NN>_bone<MM>` (`_alt<K>` for a selector's other children, such as other eye states, which all show at once
outside the game; `loose` for blocks the geo layout never draws). Materials are named `tex<NN>` or `untextured`, with
`_2s` for double sided and `_lit`, `_env`, `_lin`, `_fog`, `_s<scale>` for the geometry mode the game draws them with;
`obj_to_bin.py` reads these back. Texture kinds CI4, CI8, RGBA16, RGBA32 and IA8 are decoded, external textures (in
separate files) from the asset files beside the model; others are reported and left out.

- `.glb`: the one to use. Vertex colours are in `COLOR_0`, which glTF multiplies with the texture, so it imports
  coloured with no setup (File > Import > glTF in Blender). Textures keep the game's mirror/clamp, and see-through
  textures get alpha mask or blend. The node scales the game units by 0.01, so Banjo is about 1.5 m tall.
- `.obj`: vertex colours go on the `v` lines, but an `.mtl` cannot use them, and much of a character (Banjo's fur,
  for one) has colour only there; in Blender plug a Color Attribute node into Base Color (multiplied with the
  texture where there is one) or those parts show white. Import with Forward -Z, Up Y; the positions are in game
  units, about 100 to a metre. Mirror/clamp is lost.

## obj_to_bin.py

The way back: rebuilds a model asset from an edited `.glb`/`.gltf` or `.obj`, on top of the original `.bin`, for
`mods/assets/asset_<id>.bin` (or a model mod's `assets/` folder). Python 3, standard library only (Pillow, when
installed, for textures that are not PNG).

```
py tools/obj_to_bin.py <edited.glb|.obj> -t <original asset_XXXX.bin> [-o <out .bin>] [--scale N]
```

The original keeps its bones, bone table, selectors and the rest of its geo layout; the textures, display list,
vertices and per-vertex normals are written new, and every geo-layout part is pointed at its new geometry.

- A triangle goes on the part its object is named for (`p<NN>...`); triangles in objects with other names go on the
  part of the original's nearest triangle (never on an `_alt` part). Keep the object names when editing.
- In a joint part (geo command 0x18) each vertex follows the bone or its parent, as the original's nearest vertex in
  that part does. Seam triangles get two vertex buffers (the command's two blocks); any beyond that follow the bone
  only, with a warning.
- Positions: `.glb`/`.gltf` in metres, with every node transform applied (as `bin_to_obj.py` writes it and Blender
  exports it), times 100; `.obj` in game units. Vertex colours come from `COLOR_0` (times the material's base
  colour); materials with no colours use the base colour.
- Textures become powers of two that fit TMEM (128 a side at most): CI4 when they have up to 16 colours, CI8 up to
  256, IA8 for grey in 4-bit steps, otherwise RGBA16. Textures with alpha are drawn cut out.
- Material names from `bin_to_obj.py` set double sided, lighting and environment mapping; materials made in Blender
  take the part's own geometry mode, and double sided from the material's Backface Culling setting.
- The template's collision (header 0x1C) and effects (0x24) are copied as they are, with a warning: they may still
  refer to the old vertices, so models that have them (objects and levels, not characters) may collide or animate
  wrongly once their geometry changes.

Checked: exporting and rebuilding every model in a full dump gives the same triangles, colours, UVs and bone/parent
vertex groups on 1141 of 1145 models (the other 4 have textures that are not a power of two, which are resized). A
rebuilt Banjo (`asset_062A`) with recoloured fur loaded and animated in the game. A remodelled mesh (new geometry
rather than the original's) has not been tried in the game yet.

## organize_textures.py

Sorts a texture dump by what each texture belongs to, with a searchable index. Python 3, standard library only.

```
py tools/organize_textures.py <png folder> <out folder> [--mode hardlink|copy] [--categories FILE] [--context DIR ...] [--allow-unlisted]
```

`<png folder>` is `texture_dump/png/` in the app-data folder: the PNGs, `rt64.json`, and a `<hash>.json` beside each
PNG. Dumps made from 2026-11-09 on record in that json what the texture belongs to (`src/game/texture_context.cpp`):
whether it was drawn in the HUD, the game asset it is in (found from the display-list command that loaded it, else
from the texture's own address, against the game's table of loaded assets and its heap) and whether that asset is a
map's own model. Use an empty `<out folder>`. The source folder is never changed.

Output:

- `Levels/<map>/`: the map's own models (for example `Levels/0B8 MT`).
- `Characters/<name>/`, `Objects/<name>/`, `Pickups/<name>/`, `FX/<name>/`, `HUD/Fonts/<name>/`, `HUD/Menus/<name>/`,
  ...: assets named in `tools/texture_categories.csv`, in the category given there (for example
  `Characters/Banjo-Kazooie`, `Pickups/Honeycomb`, `FX/Fire`, `HUD/Fonts/Small font`).
- `HUD/<asset>/`: other textures drawn in the HUD, menus and text.
- `Unsorted/Models/<id> (<map>)/`, `Unsorted/Assets/<kind> <id> (<map>)/`: assets with no name yet; give them one in
  the csv and run the script again (no new dump needed).
- `Unsorted/Not in an asset/<map>/`: textures loaded from outside the game's loaded assets.
- `Unsorted/By map/<map>/`: textures from dumps made before the "what it belongs to" fields existed.
- `Shared/`, `Unknown/`: as before (several `--context` dumps disagree on the map; no context json).
- `index.html`: every texture as a thumbnail, a folder tree with counts, a button per top category, and a search over
  category, name, asset id, map, size and format (several words narrow it). No outside files.
- `manifest.csv`: the same rows, with the folder, what it is and the asset id.

A file is named `<first 8 hex of the hash> <asset id> <width>x<height> <format>.png`.

`tools/texture_categories.csv` maps asset ids to names and categories. Its model names come from ScriptHawk (MIT,
credited in the file and in `docs/THIRD_PARTY.md`) and the categories were set by keyword, so some may be wrong: edit
the file freely. Sprites and other assets are added by hand after looking at their textures.

Files are hard-linked (no extra disk space; same drive only, NTFS) unless `--mode copy` is given, and copied
when linking fails. The script prints the count per folder and checks that every hash in `rt64.json` is in the
output exactly once and that the file count equals the number of unique hashes. It exits 1 if not.

## Quick sweeps for a dump

In the game's console: `sweep fast` (entrance 0 of every map, no camera turn, shorter waits, 2x game speed), then
`sweep more` (the other entrances of the maps that gave textures in the fast pass). See `docs/console.md`.

