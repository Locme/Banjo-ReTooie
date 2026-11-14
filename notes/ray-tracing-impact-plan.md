# Ray tracing: why it looks underwhelming, and the plan (2026-11-14)

Asked by L: "ray tracing still seems underwhelming, make a plan to address this first". This is the plan only; nothing
here is built yet. Read against `origin/main` at `80f34f83`.

## What the code does today

Ray tracing is a pass over the game's finished picture (`rt64-ext/src/shaders/SceneEffectsPS.hlsl`, settings in
`src/display/picture_filters.cpp` ~5375-5470 and ~4600-4640). The game has already painted its own lighting into the
picture (vertex colours), and the traced pass mostly **darkens** that picture. Six things keep the result faint:

1. **The effects that make it look traced are off by default.** With Graphics > Lighting at Ray Tracing:
   Traced Relighting 0, SSGI 0 (and since `82eaca82` the SSGI slider alone decides the traced bounce light, so there is
   **no traced bounce or sky light at all** out of the box), Ray Traced Denoising off, Path Tracing off, Ray Traced
   BRDF 0, Subsurface 0, Parallax materials off. What is left is darker shadows, occlusion and mirror reflections on a
   few surfaces.
2. **Shadows are capped and laid on top of painted shading.** `SunShadow` returns
   `1 - strength * 0.55 * blocked`: at the default strength 60 a full shadow takes off only 33% (45% at 100). The game's
   painted shade is still under it, so a shadow is a grey film over an already-shaded surface, not a change of light.
3. **Relighting stops at every roof.** Traced Relighting is the one setting that swaps the game's lighting for the
   traced light, and it is turned off wherever `Enclosed` says the spot is shut in (caves, rooms, under big roofs).
   Much of Banjo-Tooie is inside, so even with it on, those places get only the darkening.
4. **No room above white.** The pass works on the game's 8-bit picture: bounce light is capped at 0.6 and cut back on
   bright surfaces so sand and snow don't go white. Sunlit ground can't get brighter than the game painted it, so the
   gap between sun and shade, which is most of what reads as "ray traced", stays small.
5. **Far shadows fade out** between about 4000 and 7000 units (`ShadowFadeScale`), so wide views look flat, where a
   traced shadow (which doesn't need the depth buffer) could carry on.
6. **Few surfaces reflect.** Stone, wood and dirt never reflect (on purpose, `398ea4c3`), Parallax materials are off,
   and BRDF is 0, so reflections are sharp mirrors on a handful of textures and nothing in between (no soft sheen on
   wet rock, polished floors or water edges).

## Plan, in order

### 0. A check to judge against (first)

- A console script (`autoexec`-style, run from a scratch copy of the Release game per the testing notes) that warps to
  about 10 fixed views and takes a `screenshot` of each with Lighting None, today's Ray Tracing defaults, and the
  candidate settings: Spiral Mountain and Jinjo Village (outdoor sun), Glitter Gulch Mine (cave with lamps),
  Witchyworld at night, a Mayahem Temple interior, Hailfire Peaks (snow, bright), Grunty Industries (inside, metal),
  Jolly Roger's Lagoon (water), Terrydactyland (wide view), Cloud Cuckooland.
- A side-by-side page of the three columns, plus `costcheck` milliseconds per view.
- Done when L can look at the page and say which column is better. Every step below is judged on that page.

### 1. Defaults that show what is already built (settings only, small)

- Give ray tracing its own bounce light default instead of hanging on SSGI's 0 (for example traced bounce at 50 when
  Lighting is Ray Tracing, SSGI slider still wins when higher).
- Traced Relighting default 100 outdoors; Ray Traced Denoising on (it also halves the shadow and lamp rays, so it pays
  for the rest); BRDF at a low value (about 15) now that denoising calms its grain; Parallax materials on.
- Check `costcheck` stays near today's cost on a mid card; if not, Half resolution with denoising as the default.
- Ships if the page says yes. Existing `graphics.json` files keep what the player set; only fresh defaults change.

### 2. Relighting indoors and in caves (the biggest change)

- Today `Enclosed` turns Relit off. Instead, inside, relight from the lamps and fires (already traced, with shadows)
  and the traced bounce, with the sky term off and a small ambient floor taken from the game's own painted level of
  that room, so a room never ends up darker on average than the game made it.
- Rooms with no lamp in the lamp list keep the game's lighting (today's behaviour) so nothing goes black.
- Check on the cave and interior views from step 0.

### 3. Shadows that change the light, not grey it

- Where Relit runs, the shadow already comes from the light; drop the 0.55 cap there.
- Where it does not (Relighting below 100, enclosed rooms without lamps), raise the cap and scale it by how much light
  the game painted on that spot, so a sunlit spot loses a lot and an already-shaded one little (no double shadows).
- Let traced sun shadows carry on past the depth-buffer fade distance (only the screen-space and shadow-map paths need
  it), at Half resolution far off to keep the cost.

### 4. Room above white

- Work the composite in linear light with headroom: the sun may light a surface above what the game painted, and a
  soft roll-off at the end (the pass already has an exposure curve near line 159) brings it back into range, instead
  of the 0.6 cap and the cut on bright surfaces.
- Per-level exposure stays near the game's look on average; only the spread between sun and shade grows. Snow and sand
  views from step 0 are the test for blow-out.

### 5. Bounce light that carries colour

- With denoising on, one path-traced bounce by default (Path Tracing on, 1 bounce) so green grass tints the walls
  beside it and a lamp-lit wall lights the floor; remove the bounce cap once step 4 is in.

### 6. Reflections between mirror and matte

- A middle class of materials: a faint, rough sheen (high roughness, low Fresnel) for wet rock, polished wood floors,
  ice edges and puddles, through the built-in material list, so more of the scene answers to the light without
  bringing back the shiny rock `398ea4c3` took out.

### 7. Cost and settings clean-up

- `costcheck` on every view after each step; if a step costs a lot for little on the page, it is cut or made optional.
- Fold the many ray tracing sliders into a few that say what they do (pairs with "Ray tracing fine tune" and "Menu
  cleanup" in `TODO.md`); keep the detailed ones under Ray Trace Debug.

## Progress, 2026-11-14

- Step 0 done: `tools/rt_shots.py` (on branch `rt-impact` in the `tooie-bisect` worktree) takes 15 views across 12 maps
  under several setups from a copy of L's game. Shot sheet: https://claude.ai/artifact/VTQZ4J8K4AErD3GCmQ6Ktf.
- What it showed with L's settings: ray tracing mostly darkens; sun shadows are hard to see; SSGI 0 leaves no traced
  bounce light; caves and rooms gain nothing, and lanterns cast no pool of light.
- Step 1 (defaults) does not help L, whose settings are near the top already, so it waits.
- Candidate 1 (same branch, not committed): traced sun and model shadows take up to 80% of the light (`ShadowDepth`,
  55% for shadow maps and screen-space shadows and for lamps); Traced Relighting's sun 1.2 and sky 0.75 of before.
  Contrast up 5 to 20% at the same brightness. Shot except for the lamp line, which went back to 0.55 after the shots
  (built, not shot again).
- Candidate 2 (lamps light the texture's colour) showed no change in Gloomy Caverns and was taken out. Next for caves:
  check whether those lanterns are in the traced lamp list at all.
- Bounce + full relighting brightens 30 to 50% and turns grass neon: step 4 (exposure with headroom) before more light.
- Step 4, first part (same branch, not committed): `RelitLight` puts flat ground in full sun at `RelitSunlit` (1.0)
  times its texture's colour and scales the rest with it. Bounce + full relighting is now within about 15% of the
  game's brightness, as saturated as the game, with more contrast (Mayahem Temple 0.20 against 0.14). Jolly Roger's
  Lagoon comes out a little dark. The shot sheet's "after" columns show this build. Relighting without ray tracing is
  untouched, so it no longer matches Traced Relighting's level.
- Step 2, first part (same branch, not committed): why lanterns lit nothing. The traced lamps are the game's own level
  lights (`send_level_lights`, `TOOIE_LIGHT_LOG=1`), and their range is how far the game's painted lamplight goes,
  300 units in Gloomy Caverns, so the traced light only redid that glow. `LightShadows` now lets a lamp's traced light
  reach `LampReach` (2.5) times that range, while its darkening keeps the game's range, and the composite takes the lamp
  light from the texture's own colour where that is brighter than the picture (`LampAlbedoShare`, `LampLift`). Gloomy
  Caverns went from 0.12 mean brightness (game 0.14) to 0.17, with the steps, wall and mine door lamp-lit; outdoor views
  changed by 0.01 or less. Rooms and caves still keep the game's shading under it (Traced Relighting stays off there).
- Step 2, second part (same branch, not committed): Traced Relighting in rooms and caves. Where `Enclosed` says a spot
  is shut in, relighting (at its slider) keeps `IndoorKeep` (0.5) of the game's painted light, drops the lamps'
  darkening, and the traced lamps shine `IndoorLampGain` (3) times as bright, but only as far as a traced lamp reaches
  (`IndoorLampFull`): with no lamp in reach the game's picture stays. A first try without that limit left Jolly's
  (0.12 against the game's 0.19) and Grunty Industries darker and flatter. Gloomy Caverns with full relighting: 0.23
  brightness and 0.17 contrast against the game's 0.14 and 0.10, but the wall by a lantern flared orange. A roll-off on
  indoor lamp light (`lamp / (1 + lamp * IndoorLampSoft)`) tamed it: at 0.6 the pools went too (contrast 0.10, flat), at
  0.3 (kept) the brightest 1% drops from 0.83 to 0.57 with the pools kept (0.18 brightness, 0.11 contrast).
- `tools/rt_shots.py` puts Banjo back on his spot (`SPOTS`, from `pos` after each warp) and aims the camera again
  before every shot: between shots he drifted and some frames showed a wall. It warms up on another map first.
- `tools/rt_shots.py` warms up on the first map before shooting: the first shot after a start came out as if ray
  tracing were off. Unstable views: Glitter Gulch Mine (an enemy walks through), Grunty Industries (Banjo lands in
  different spots).

## What is not known yet

- How each step looks: nothing here is tested. The page from step 0 is the test, and only L's eye on a real PC counts.
- Whether step 2's lamp list covers enough rooms; some may need lamps picked with the Shader Effects pick mode first.
- The cost of steps 3 to 5 on cards weaker than the dev machine.
