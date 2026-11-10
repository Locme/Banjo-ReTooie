# Tools

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

