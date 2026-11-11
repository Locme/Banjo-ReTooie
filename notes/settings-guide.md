# Settings guide

Every option in the game's own menus that this port adds or changes, in plain
words. Names and descriptions are the ones shown in the menu. Defaults are the
values the code starts with. Open settings with **Esc**, or **Back** / **Select**
on a controller.

## General

- **Back up saves**: copies your save file into the `save_backups` folder
  whenever it changes. Default: on.
- **Discord Status (Non-functional ATM)**: shows the level you are playing in your Discord status
  while Discord is running. Default: on.
- **Back-Port: Old Banjo sounds**: Banjo-Kazooie's jump sounds instead of
  Banjo-Tooie's. Default: off.
- **Back-Port: Get Jiggy animation**: when Banjo collects a Jiggy he does
  Banjo-Kazooie's jiggy dance (fist pumps, Kazooie pops out at the end) instead
  of Tooie's pose. Tooie's jingle, camera and Jiggy count stay. The dance is
  still in Tooie's own data, unused. Default: off.
- **Boss rush** (Features): fights all 13 bosses one after another, in the order the game
  meets them (Klungo, Targitzan, Old King Coal, Mr. Patch, Lord Woo Fak Fak,
  Klungo again, Terry, Weldar, Chilli Billi, Chilly Willy, Mingy Jongo, Klungo a
  third time, Hag 1), whatever your file has reached. It uses the game's own
  Boss Replay, which gives each fight the moves and eggs it needs and leaves
  your file as it was; the open file is saved first. Between fights you pass
  through the game select screen. If you lose, Yes on "Do you want to play
  again?" retries that boss and No ends the rush; a notice says how far you got,
  or your total time when all 13 are beaten. Turning it on starts a rush, it
  turns itself off when the rush ends, and turning it off stops after the
  current fight. Not with Bottles' Revenge on. Default: off.
- **Cut Content: Torch enemy** (Back-Ports and cut content): brings back the
  angry torch cut from the game. Level: Glitter Gulch Mine (the menu names only
  the level, to keep where they hide a surprise). Each one stands still like an
  ordinary lit torch, eyes shut, lighting up the dark around it. When Banjo
  walks up to it, its eyes open and it springs at him to burn him for one
  honeycomb and knock him back, then chases him; if he gets away it walks back
  to its spot and goes still again. Any attack (claw swipe, roll, peck, Beak
  Barge, Beak Buster and the rest) or any egg puts it out; it comes back the
  next time the area loads. Applies at once.
  Default: off.
- **Save backups to keep**: how many of the newest save backups to keep.
  Range 1 to 100. Default: 10.
- **Timer save**: saves the game by itself after 5, 10, 30, 60 or 120 minutes of
  play in a level. Pauses, menus and cutscenes don't count, and it never saves
  during them. A "Game saved" notice shows. Default: Off.

- **Texture dump** (Developer): for making texture packs. Saves every texture
  the game draws to the `texture_dump` folder in the app-data folder:
  `texture_dump/png/<hash>.png` with an `rt64.json`, so that folder loads as an
  RT64 texture pack, and RT64's raw dump files in `texture_dump/raw/` (feed them
  to RT64's `texture_hasher` for Rice hashes). **While playing** saves what you
  see. **Sweep all maps** warps through every map by itself (multiplayer maps
  left out, cutscenes last) and turns the camera around in each, about 40
  minutes; load a spare save file first. `texture_dump/sweep.txt` lists each map
  and how many new textures it gave. If the game stops during a sweep, it
  carries on after that map the next time a file is loaded; picking Sweep all
  maps again starts a new one. Timer save waits while a sweep runs. Default: Off.

- **Dump assets** (Developer): writes every game asset (models, animations,
  sprites, text and the rest, 10,266 files) to the `asset_dump` folder in the
  app-data folder as `asset_<id>.bin` (id in hex), with `assets.txt` listing
  id, kind and size (kind 0 is a model). Takes a few seconds; files already
  there are kept. To **replace** an asset, put an edited `asset_<id>.bin` in
  `mods/assets/`: it loads in place of the game's, at any size, the next time
  the game loads that asset (another area, or a restart). A model has to be in
  the game's own model format, and a character's model needs the bones its
  animations expect, or the game can crash. Default: off. A model mod packs the same files as a
  mod: a folder (or .zip) with mod.json, an `assets.json` and an `assets/`
  folder of `asset_<id>.bin` files. It shows in the Mods menu and turns on and off
  there; in a level the area reloads (back at its entrance) so the change shows at once, and wins over `mods/assets/` (the mod higher in the list wins when two
  replace the same asset).

- **Developer Mode** (Developer): shows the DEV tab. Default: off.

- **Sound test** (DEV): plays one of the game's sound effects at Banjo each
  time the number changes (0 to 2047, sound 0x4000 + the number), to find a
  sound by ear, for example a voice for the torch enemy. Only while playing in
  a level. Default: 0 (nothing plays until it changes).

- **Blend texture seams** (DEV): smooths the lines where the pieces of a
  texture drawn in parts meet: the title screen's logo, the pads the player
  stands on, wall panels and the like. The game clamps each piece at its edge,
  which on the N64 is a fraction of a pixel but shows as a line at high
  resolutions; this blends each piece into the piece drawn beside it. Every
  such texture is found while drawing, so there is no list; an edge with no
  matching neighbour, or (in the 3D world) a sharp colour change at it, stays
  as it was. `TOOIE_TEXTURE_SEAMS=0` or `1` sets it for a headless run.
  Default: on.

- **Hide Unnecessary Settings Entry** (DEV; first named Hide Vanilla Widescreen
  Entry in the Game Menu): hides Wide-screen Mode and Screen Alignment in the
  game's global settings on the save select screen (the TV), so it lists Speaker
  Mode only. While it is on, the game's own
  widescreen mode is kept off and the picture centred, also on saves that had
  them changed. The game's widescreen squashes the picture for a stretched TV;
  this port's widescreen is Aspect Ratio in the Graphics tab. The menu change
  shows the next time it opens. The Start menu's SETTINGS page follows it too:
  with it off, that page also has Wide-screen Mode. Default: on.

The DEV tab's **Additional Tabs** section shows or hides tabs:

- **Achievements tab**: the settings menu's Achievements tab (the twelve XBLA
  achievements, with counts). Achievements are earned whether it shows or not,
  and the Start menu's ACHIEVEMENTS page always lists them. Default: off.
- **Cheats tab**: the Cheats tab (it was in General). Hiding it leaves cheats
  that are on as they are. Default: on.
- **Warp tab**: the Warp tab (it was in the Cheats tab and needed Enable
  cheats; it no longer does). See Warp tab under Cheats below. Default: off.

The General tab also has a rumble strength option. It comes from the menu
framework, not from this port's code, so it is not described here.

## QOL

- **Pause Special Menu** (Menu section): while this menu (Esc) is open during
  play, the game is paused as if you pressed Start, but without the pause menu
  or anything else drawn over it, and the pause menu's music plays and the picture's effects keep moving. Cutscenes, map
  changes, the title screen and the file select carry on as before.
  Default: On (L, 2026-10-19).
- **Menu Slide** (Menu section): this menu (Esc) slides in from the left as it
  opens, past its place and back, its tabs following one after another, and slides
  out to the left as it closes, as the Start menu's rows do. It plays the Start
  menu's sounds for a row sliding in and out (the game's own, so none in the
  launcher). Esc while it slides out brings it back. Off opens and closes it at
  once, without sounds. Default: On (2026-11-10).
- **Mouse in the game's menus** (Menu section; was in WIP until 2026-10-23): the pause menu
  and the save select follow the mouse; the row under the cursor is picked and a left click
  presses A, a right click B. Default: on.
- **Press Start Early in Intro**: press Start during the logos and title flight to go
  straight to the file select. Default: on.
- **Text speed**: how fast dialogue text prints: 1x, 2x, 4x or Instant (a
  page at a time). Menus are not affected. Default: 1x.
- **Level transitions**: how fast the screen wipe plays when you go to another
  area: Original, Fast (4x) or Instant (16x). Cutscene fades are not affected.
  Default: Original.
- **Talon Trot**: Toggle or Hold. With Toggle, once Z + C-left starts the trot,
  Banjo keeps trotting after you let go of Z; press Z or C-left to stop. The
  toggle also ends by itself when the trot does (water, a hit, a cutscene).
  Hold is the original: hold Z to keep trotting. Default: Toggle.
- **Totals checklist** (Menu section): On or Off. On adds a "LEFT HERE" table to every
  world's page in the pause menu's Totals (and "LEFT IN THE GAME" to Game
  Totals): how many Jiggies, Honeycombs, Cheato pages, Glowbos, Notes, Jinjos
  and Jamjars moves are still to find, or DONE, and in green how many of those
  you can get now with what you have. A line under the table says MORE TO GET
  HERE, MOVE ON FOR NOW or ALL DONE HERE. Up/down moves the A button beside a
  row and A lists
  its items by name: GET NOW (green), LATER (white, with what it still needs
  when picked) and DONE (yellow); B goes back to the table. Default: Off (L, 2026-10-15).
- **Running**: On or Off. On lets the Run key (Controls tab, Movement; the
  controller's B button by default, which is then no longer a second C-right;
  not bound on the keyboard) run faster as Banjo-Kazooie, Banjo or Kazooie.
  Default: On.
- **Transform anywhere**: On or Off. On lets the Transform key (Controls tab,
  Movement; T on the keyboard, LT + Y on a controller) change Banjo-Kazooie
  into the world's Humba Wumba form where he stands, with the game's own spin-up
  transformation, and change him back. A world's form works only after you have
  jumped in that world's Humba pool and changed at least once, and only in that
  world. Terrydactyland gives the Daddy T-Rex once Mumbo has made Humba's tent
  big, the baby T-Rex before that; the Daddy T-Rex is refused where it has no
  room. Humba says her line for the form on the 1st, 3rd, 5th change. Refused,
  with a sound, in the air, swimming, while talking or in a cutscene (the
  submarine is the other way round: it changes in water only). Golden Goliath
  and Dragon Kazooie are not part of it. Default: On (since 2026-10-19; a
  saved Off turns on once).
- **Fine aim**: Off, Hold key or Always. In first person (C-up) the left stick
  turns the view slower, for aiming eggs. The key is Fine Aim in Controls >
  Hotkeys (R or right trigger by default). **Fine aim speed**: 25%, 40% or 60%
  of the normal speed. Default: Off, 40%.
- **Free camera**: the right stick turns the camera smoothly around Banjo and
  tilts it, instead of the game's stepped camera swings. Push it on past the
  top or bottom of the tilt to move the camera in or out. Clicking the right
  stick is first person, as before. The camera stays where you turned it until
  a cutscene or another area. Default: on.
  - **Free camera speed**: Slow, Normal or Fast. Default: Normal.
  - **Free camera: invert left/right** and **invert up/down**. Default: off.
  - **Free camera: ease back**: a second after you let go of the right stick,
    the camera drifts back behind Banjo. Flying only does it while flying,
    Always also while running or swimming; standing still leaves the camera
    where you turned it. Default: Off.
  - **Free camera: smooth walls**: the camera glides in when a wall gets
    between it and Banjo and glides back out afterwards, instead of jumping,
    and Banjo fades out when the camera comes very close to him. Default: off.

## Gameplay

The Gameplay tab's Difficulty section. These are General options shown on their
own tab, so they are saved in general.json and apply as soon as they change.

- **Enemies do double damage**: every hit from an enemy or hazard takes twice the
  honeycombs. Falls hurt as they always do. Default: off.
- **Direct First Banjo Shooter Analog Aim** (default off) and its **Speed**: in first
  person (C-up) the left stick turns the view faster the further you tilt it
  (90, 150 or 240 degrees a second at full tilt), like a modern shooter, and the
  view stays where you leave it: the game is given a centred stick then, so it
  no longer turns Banjo and the view on its own. Stick up looks up (the game's
  own aiming looks down); Mouse And Gyro Aim: Invert Up/Down flips it. Off keeps
  the game's own aiming. Fine aim still slows it, and mouse and gyro aim still
  add to it. In the first-person shooter sections (Targitzan's Temple) the stick
  walks as before; there the mouse and gyro turn Banjo left and right.
- **Enemy aim**: Original, Better or Sharp. Enemies and shots that aim ahead of
  you aim half a second (Better) or a full second (Sharp) of your running ahead.
  **Enemy aim: aimed shots** (percent of shots aimed ahead, default 75) and
  **Enemy aim: homing shots** (Klungo's potion steers while it flies, default
  on) show when it is not Original. Default: Original.
- **Enemy dynamic positioning**: a curated list of enemies slide sideways while
  they close in and sidestep your roll. Default: off.
- **Lower Enemy Attack Cooldown**: the same enemies wait half as long between
  attacks. Default: off.
- **Enemy Respawn**: Original or Never. The game spawns a map's enemies again
  each time the map loads, with no timer. With Never, an enemy you have killed
  stays gone. Remembered until the game is closed, not in the save file.
  Default: Original.
- **Minjos Stay Dead**: the same as Never, for Minjos only. Default: off.
- **Canary Mary races** (was in QOL > Balancing until 2026-10-23): Fair, Easy or Original. In the original she speeds up
  past her normal pace whenever you lead; Fair removes that catch-up, Easy is
  Fair with her pace at 85%. She still slows down when you fall behind.
  Default: Fair.

## WIP

Features still being worked on, in the WIP tab's WIP section. When one is done it
moves back to its own tab (the Dive to QOL > Moves and aiming, Mouse in the game's
menus is already in QOL > Menu). The tab is a page of Graphics
options: all of them save in graphics.json. 


- **Dive** (off by default): press the Run key (B on a controller) in the air as
  Banjo-Kazooie for a fast forward lunge. On landing Banjo slides on his belly and stays
  lying on it until you jump (the stick can't walk him off it). Works from a jump, after the
  Feathery Flap and in the ground pound (Bill Drill), once per jump (the jump off the belly is
  a new jump); a wall ends it. Banjo alone, Kazooie alone and the transformations are
  unchanged. While it is on and Run is held, B in the air belongs to the dive (not in the
  pause menu, and not when Run is on another key). Tuning (src/gameplay/dive.cpp, units per
  second; the run is 500): starts at 850 (1.7x), settles to 700 (1.4x) over 0.25 s, a 150
  lift at the start, falling held to 450, then the slide slows from 600 to a stop over 0.4 s.
  Pose (rules in src/gameplay/hold_to_run.cpp): a push-off as it eases in over 0.16 s, then
  Banjo flat with arms forward and legs trailing, wings beating and legs kicking every 0.45 s;
  on the belly his legs flutter while he slides; the pose fades into the jump over 0.15 s.
  Kazooie shows when the game shows her (after the Feathery Flap).
  `TOOIE_DIVE_POSE_TUNE=<file>` replaces the pose rules, lines
  `<bone> <type> <scale> <offset degrees> [set]`.

- **Honeycombs stay (untested)**: the health honeycombs that enemies and
  breakables drop no longer vanish after 20 seconds. The game's own limit of 10
  on the ground at once stays; the oldest goes when another drops. Leaving the
  area clears them. Default: off.

## Controls: Movement

- **Tiptoe**: hold it to tiptoe at any left stick tilt. Default: Left stick
  click on a controller, nothing on the keyboard. Rebind it in the Controls tab
  under Movement. The game still sees every button as usual.
- **Transform**: with QOL > Transform anywhere on, changes Banjo into the
  world's Humba Wumba form where he stands, and back. Default: T on the
  keyboard, LT + Y on a controller. Rebind it in the Controls tab under
  Movement.
- **Run**: hold it while moving to run faster as Banjo-Kazooie, Banjo or
  Kazooie, with a sprint animation. Not bound by default: bind it in the
  Controls tab under Movement. Any stick tilt runs at full speed while it is
  held. QOL > Running turns it off.

## Controls: Cheats

- **Speed-Up**: the speed-up key. Default: F2 on the keyboard, nothing on a
  controller. Rebind it in the Controls tab under Cheats. It only works while
  **Enable cheats** and **Speed-up** are on in the Cheats tab (see Cheats below).

## Graphics: Aspect Ratio

Sets how the picture fits the window. Default: Fill.

- **4:3**: keeps the game's original shape.
- **Fill**: widens the view to the window's shape.
- **Letterbox 16:9**: widens the view to 16:9 and adds black bars in windows of
  any other shape.

HUD Placement: **Original**, **16:9** or **Expand** (the HUD follows the
window's shape). Default: Expand; a saved 16:9 from the old default changes to
Expand once.

Graphics changes apply at once. Graphics API needs a restart: changing it asks "Restart now?", and Restart closes the game and opens it again with the new API. The choices are Vulkan (the default) and, on Windows, D3D12; there is no Auto. A saved Auto is not migrated, so switch it once.

## Graphics: picture filters

- **Brightness**: -5 to +5. Brightens or darkens the dark and middle tones;
  black and white stay as they are. Default: 0.
- **Brightness test pattern**: shows ten grey boxes (2% to 20%) over the game.
  Close the menu and set Brightness so the first box just disappears and the
  second is just visible, then turn the pattern off. Default: off.
- **Colourblind filter**: Off, Deuteranopia, Protanopia (both red-green) or
  Tritanopia (blue-yellow). It moves the colours you can't tell apart into ones
  you can. **Colourblind filter strength** (0% to 100%) shows when a filter is
  on. Default: Off, 100%.
- **Retro: N64 3-point filtering**: the N64's own texture smoothing. Off uses
  plain bilinear smoothing. Default: on.
- **Retro: N64 16-bit colour**: the N64's 16-bit colour with its dither pattern,
  at the game's original resolution. **Console** smooths the dither the way the
  N64 does on its way to the TV, so it looks close to Off with a little colour
  banding. **Raw dither** shows the dither pattern itself, as emulators do with
  the N64's dither filter turned off. Default: Off.
- **Retro: CRT**: 240 scanlines and the stripes of a CRT TV. Default: off.

F12 screenshots are taken before these filters, so they don't show them.

## Graphics: Parallax

- **Parallax** (under Shaders): 0 to 100. Stone, brick, rock, plank walls,
  roof tiles and carved panels get depth: the raised parts stand out, the gaps
  and cracks sink in and fall into shadow (lit from above), and it all shifts
  as the camera moves. Higher is deeper; 100 is about 16 world units (Banjo is
  about 150 tall). Fades out on walls seen edge on and in the distance.
  Default: 0 (off).
- **Parallax on original textures**: the game's own textures (3,517 of them,
  picked by eye, each with its own shape and depth: stone, brick, metal, wood,
  bark, leaves, sand, ice and the rest), whose depth is worked out from how dark each
  part is. Off,
  only texture pack textures that come with a height map get parallax.
  Default: on.
- **Parallax smoothness** (under Parallax): 0 to 100. Each parallax texture's
  height is worked out once as it loads, from the texture that is drawn (the
  game's own, its upscale or a texture pack's, which takes its own brightness
  range), and blurred by up to two of the game's texels at 100. Higher stops the
  specks and fine detail of a texture, an HD pack's most of all, from standing
  up as thin spikes that streak like hairs as the camera moves; lower keeps
  sharper edges between stones. Displaced ground uses the same height.
  Default: 25.

### Displaced ground

- **Displaced ground** (under Shaders): 0 to 100. The ground's cracks, gaps and
  grooves become real dips instead of a painted-on look: floors drawn with a
  Parallax texture of a floor-like shape (cracks, terraced slabs, rounded
  cobbles, bumpy dirt, brick, tiles, smooth stone) are cut into fine triangles
  (by their size, so they stay put as the camera moves) and the dark parts of the
  texture pushed straight down by up to
  16 world units at 100 (times the texture's own Parallax depth). The ground's
  outline and depth change, not only its shading, and the deeper parts are a
  little darker. Walls and the ground within about 24 units of each triangle's
  edge are left as they are, so no gaps open between pieces of ground, and so is
  the ground under other draws laid over it (the grass edging painted over dirt).
  The depth is blurred to the spacing of the new triangles, so it never gets
  noisier than the mesh can show. It takes
  Parallax's list of textures, shapes and depths (including those picked in
  Parallax pick mode) and needs Parallax on original textures to be on, but the
  Parallax setting itself can stay at 0. Needs a graphics card with tessellation;
  without it the ground is drawn as the game did. Drawn on the picture, so
  nothing in the game changes. Default: 0 (off).
- **Displaced ground distance** (under Shaders): 2000 to 20000 world units. How
  far from the camera the ground is displaced; the dips fade out over the last
  quarter. Further costs more. Default: 8000.

### Parallax pick mode

Bind **Parallax Pick Mode** (Controls, Pick Modes) and press it in a level. The mouse
becomes a crosshair, the texture under it pulses light blue, and a label beside
the cursor names the texture and its parallax ("yours" or "built-in").

- **Left click**: the shape, in turn Stone (only the dark gaps sink), Bumpy (the
  whole surface follows its brightness), Inverted (the light parts sink),
  Cracks (only the darkest lines sink), Terraced (a few flat steps), Rounded
  (faces bulge like cobbles), Grass (blade tips up, ground between them deep),
  Wood (shallow grain, deep gaps between planks), Bark (deep furrows), Brick
  (flat bricks, wide sunk mortar), Dirt (soft shallow lumps), Metal (flat
  plates, only the seams sink), Leaves (rounded, the shade under each sunk),
  Tiles (flat tiles, a narrow sharp grout line), Sand (low soft ripples),
  Smooth (Bumpy's depth with no stair steps) and Ice (a clear top layer with the
  frost and bubbles just under it and the dark parts deep inside; Sand, Smooth
  and Ice blur the texture's brightness first, which hides the jaggies of small
  textures), then Off. 25% depth is kept as 30%.
- **Right click**: the depth, as a share of the Parallax slider: 100, 150, 200,
  300, 25 and 50%.
- **Middle click**: its shadows off or on.
- **Shift + left click**: back to the built-in choice.
- **Mouse wheel**: the surface behind it (when several are under the cursor).

Every change shows at once. The **Save Pick** key (Controls, Pick Modes) writes
the texture under the cursor, only that one, to `parallax_tags.txt` in the `Dev
Files` folder next to the save files; the label says "not saved" until then.
The **Delete Saved Pick** key puts the texture under the cursor back to the
built-in choice and takes it out of the file (one line a texture: `<hash> <shape> <depth>% shadows|noshadows`, or
`<hash> off`). Picks override the built-in list and load again next time; send
the file in to have them added to the port. Parallax must be above 0 to see the
result. Press the key again for the normal mouse.

**Ray Tracing Material Pick Mode** (Controls, Pick Modes, no default) gives a
texture a production PBR material for Graphics > Ray tracing: **Albedo** (the
base colour it is tinted by, red, green and blue), **Roughness** (0 a mirror, 100
a wide brushed lobe: its reflection rays are scattered over a GGX lobe that
wide), **Metalness** (0 a plain dielectric with a faint Fresnel reflection, 100 a
metal with almost no diffuse that reflects in its albedo colour) and
**Emissive** (percent of its own colour added as light the shadows don't dim; the
traced light bounces pick it up, and it lights the scene like a Light Source) and
**Subsurface** (how much of a lamp's or the sun's light behind the surface comes
through it).
**Left click** gives the texture a material (the default one) or takes it off,
**middle click** steps through presets (Mirror, Brushed metal, Gold, Plastic,
Rubber, Glowing, Wax, Leaf, Default), **Shift + wheel** changes the chosen property
(**Ctrl** for fine steps), **right click** or the **number keys 1 to 7** choose
which property (albedo red, green, blue, roughness, metalness, emissive,
subsurface), key **8** steps the preset and key **9** turns Show All on or off. Save Pick, Delete
Saved Pick, Copy, Paste and Undo work as in the other modes; the picks are kept in
`rt_material_tags.txt` in the Dev Files folder (one line a texture:
`<hash> albedo=RRGGBB roughness=N metalness=N emissive=N subsurface=N`). Without Ray tracing
the picks do nothing.

Graphics > Ray Tracing also has **Ray traced BRDF** (0 to 100: every traced
reflection is scattered over a GGX lobe that rough; above 0 it turns the
screen-space Stochastic reflections off) and **Ray traced subsurface scattering**
(0 to 100: sun and lamp light carried through leaves, with a soft coloured glow
in their shade).

**Traced relighting** (Graphics > Ray Tracing, 0 to 100, off by default, experimental)
lights the outdoor levels again with the traced light instead of only darkening
the game's picture. Where the camera's ray meets a surface it reads the
surface's texture; how much darker or lighter the picture is than that texture
is the game's painted shading, which is divided out. The traced sun (by how
squarely the surface faces it, and only where its rays get through) and the sky
then light it again. Sunlit ground comes out brighter, and the side turned away
and what is in shadow come out darker. Traced shadows no longer land on top of
painted ones. Rooms and caves, the sky and water keep the game's shading.

**Ray traced denoising** (Graphics > Ray Tracing, off by default, experimental)
keeps the traced light from frame to frame: the sun's and lamps' shadows, the
bounce light and the occlusion. Each new frame's rays are blended into what the
same spot of the world had, followed as the camera moves. A spot is taken only
from where it was the same surface, so newly seen ground and whatever moves
across it start from their new rays. Round the player less is kept, as his own
shadow moves with him. With it on, the shadows and lamps are traced at half
size, as at Ray tracing resolution Half: a quarter of the rays, with softer edges.

**Shader Effects Pick Mode** (Controls, Pick Modes, no default) works the
same way for the texture effects. A texture can have several effects at once.
The label lists the texture's effects ("yours" or "built-in") and the effect
you have chosen. **Right click** chooses the effect (Disable, Deep Snow,
Ice Reflection, Shiny Reflection, Text, Lamp, Slight Glow, Light Source, Disable RT; **Shift +
right click** goes back one) and **left click** turns it on or off for the
texture under the cursor. The **number keys 1 to 9** choose effect 1 to 9 in
that order and turn it on or off in one press; **Shift + 1 to 9** do the same
for effects 10 to 18 once there are that many (a key with no effect does
nothing). **Hold left click and sweep** to paint the same change (on or off, as
the first click did) over every texture the cursor passes. **Middle click**
turns Show All on or off: every texture with the chosen effect, built-in ones
included, pulses orange between the cursor texture's blue pulses. **Slight
Glow** draws the texture a little brighter, most on its lighter parts, as if
lit from inside. **Light Source** lights the scene from the texture like a Lamp
(needs Graphics > Ray tracing), with no glow in the air round it; **Shift +
mouse wheel** over it sets its strength from 10% to 500% (up is stronger; 100%
reaches as far as a lamp), saved as `light:<percent>`; on a built-in Light
Source it makes your own pick at the new strength. **Disable RT** (Shift + 1)
leaves the texture out of the ray traced scene: it casts no traced shadow and
blocks no traced light. The port ships some picks of its own (L's tag file of
2026-10-22: explosions, lamps, the lanterns' glass); your own pick of a texture
replaces them. The first left click starts from the built-in effects, so adding Ice
to built-in grass keeps the grass. Disable (no texture effect on it) turns the
others off, and any other effect turns Disable off; turning the last effect off
leaves Disable, and turning Disable off puts the built-in choice back. **Shift + left
click** puts the built-in choice back at once and the **mouse wheel** picks the
surface behind. Deep Snow is only recorded for now, as deep snow goes by level
and colour, not texture. Save Pick writes the texture under the cursor to
`shader_effect_tags.txt` in the `Dev Files` folder (one line a texture: the
hash, then its effects, for example `<hash> grass ice`; files from before keep
working); send it in to have them added to the port.

**Interpolation Pick Mode** (Controls, Pick Modes, no default) does the
same for models and characters, NPCs and enemies included: the label names the
model under the cursor and its interpolation tag. **Left click** steps how it
blends between game frames (snap, vertex, untagged, then default), **middle
click** turns its screen effects off or on and **Shift + left click** puts it
back to default. Save Pick writes the model under the cursor to `interp_tags.txt`
in the `Dev Files` folder (the same file as the Save Tags key), and Delete Saved
Pick takes it back out. It finds models at any Interpolation setting, but the
blend tags only show with Graphics > Interpolation above Original. Level pieces
such as the ground are not models, so they say "No model here".

Save Pick and Delete Saved Pick work in all three modes, on whatever is under
the cursor, and only touch that mode's file. The label beside the cursor shows
what each is bound to (keyboard, then controller), or Unbinded.

Also in Controls, Pick Modes: **Copy Pick** copies the hovered texture's or
model's pick and **Paste Pick** gives it to whatever you hover next (unsaved
until you save it); **Undo Pick** takes back the last change (clicks, pastes,
depth steps, Delete Saved Pick), one at a time. In Parallax pick mode,
**Shift + mouse wheel** steps the hovered texture's depth by 10% (10 to 310%,
wheel down deeper); right click goes back to the fixed steps. At the top left each mode shows
how many of its picks are unsaved, a **Save All** button that writes them all,
and a **Delete All Changes** button that puts every pick back as its file has
it. Only one pick mode is on at a time: turning one
on turns the others off.

### Height maps in texture packs

A texture pack (an RT64 `.rtz` or folder pack) can give any texture its own
depth: put a height map beside the replacement, named like it with `_height`
added: `textures/wall.png` gets `textures/wall_height.png` (`.png` or `.dds`).
White is the top of the surface and black the deepest part; it can be any size
(it is stretched over the texture). Grey is read from the red channel. A pack
texture with a height map gets parallax whenever Parallax is above 0, whether
or not Parallax on original textures is on, and its height map wins over the
game's brightness for that texture. Height maps are loaded the first time
their texture is drawn.

## Graphics: SMAA Anti-Aliasing

- **SMAA Anti-Aliasing**: Off, Low, Medium, High or Ultra. Smooths jagged edges
  by finding them in the finished picture (SMAA 1x by Jimenez et al.). It works
  on top of MS Anti-Aliasing and also smooths edges MSAA can't, such as
  see-through leaves and fences. Higher settings find fainter edges and
  diagonals and cost a little more GPU time. Applies at once. F12 screenshots
  show it. Default: Off.

## Graphics: models

- **Always High-Detail Models**: models that switch to a simpler version far
  away always use the detailed one, and Banjo always uses his close-up model
  (with his necklace and belt buckle). Applies at once. Default: on.
- **HD Shadows (Experimental)**: shadows are shaped like the full model on screen, with its
  pose. The player's uses the on-screen model instead of the game's simpler
  shadow model (works in every transformation); enemies and NPCs, which have
  no shadow on N64, get one too (up to 12 per frame, straight down onto the
  floor). Applies at once. Default: off.
- **Sun shadow distance**: how far from the camera Sun shadows are sharp, 1500
  to 20000 game units; past it the level's own shadows carry on, softer, over the
  whole level. The whole level casts, plus characters and objects within the
  distance, whether on screen or not, so shadows don't come and go as the camera
  turns. Past 6000 shadows get a little blurrier, and higher costs more. Applies
  at once. Default: 3000.
- **Relighting** (experimental): Traced Relighting without ray tracing, for
  graphics cards and phones without it. The sun and the sky light the level
  again from the sun shadow map: ground facing the sun is brighter, the side
  turned from it and what is in shadow darker. With no rays to read each
  texture, the game's painted shading stays under it, so it is darker and less
  even than Traced Relighting. Needs Sun shadows on; outdoors only. With Ray
  tracing on, Traced Relighting is used instead. 0 to 100. Applies at once.
  Default: 0 (off).
- **Window Light Beams** (Graphics, Vanilla Enhancements): see-through beams of light, shaped like their windows,
  fall from the windows and light a patch of the floor in Bottles' house, Banjo's house and King Jingaling's throne room,
  like the beams under the windows in Mumbo's Skull. Switching it in one of
  those rooms reloads the room. Default: on.
- **Day and Night**: a day and night cycle in the levels that are daytime under
  an open sky (Spiral Mountain, Isle o' Hags outside, Mayahem Temple, Jolly
  Roger's Lagoon, Terrydactyland, Hailfire Peaks, Cloud Cuckooland). Cycle runs
  the clock on game time; Dawn, Morning, Noon, Afternoon, Golden Hour, Sunset, Dusk and Night hold one time of day. The 3D
  world and sky are tinted (not the HUD), night has stars and a moon, and the
  sun moves for Sun shadows and Light shafts. Rooms, underwater areas,
  Witchyworld and Cauldron Keep never change. Applies at once. Default: Off.
- **Day Length**: minutes of play for a whole day with Cycle, 4 to 60.
  Default: 24.
- **Lens Flare**: with Day and Night on, soft rings of light and a glare when
  you look towards the sun and nothing hides it. Default: on.
- **Fireflies**: with Day and Night on, small glowing fireflies drift round
  Banjo at night (not on Hailfire Peaks). Default: on.
- **Weather**: with Day and Night on, Clear, Changing (mostly clear, with rain
  or a thunderstorm now and then for a few minutes), Rain or Storm. No rain in
  Cloud Cuckooland; on Hailfire Peaks' Icy Side it snows instead (a little unless
  Clear, heavy in a storm). Default: Changing.
- **Northern Lights**: with Day and Night on, green and violet northern lights
  over Hailfire Peaks' Icy Side at night. Default: on.
- **Clouds**: with Day and Night on, soft 3D clouds drift across the sky, lit
  by the sun and the moon (not in Cloud Cuckooland). Default: on.
- **Cloud Amount / Height / Thickness / Speed**: with Day and Night and Clouds
  on, 0 to 100 each (50 the usual): how much sky they cover, how high they
  float, how deep the layer is (flat to puffy) and how fast the wind moves
  them (0 holds them still).
- **Wet Ground**: with Day and Night on, the ground darkens and turns shiny in
  the rain, reflecting what is round it, and dries over about a minute and a
  half after. Default: on.
- **Raindrops on Screen**: with Day and Night on, raindrops land on the screen
  in the rain (more when looking up) and run down it. Default: on.
- **Mist** and **Mist Time**: with Day and Night on, the Volumetric Mist (see the Volumetric section) drifts in
  mornings (the sun low in the east), also at night, or all day; not in the rain. 0 to 100; 0 turns it off. Default:
  50, Mornings. With the cycle off, Volumetric Mist's own setting is used.
- **Night Sounds**: with Day and Night on, crickets and the odd owl at night
  and birdsong in the morning, quietly under the music. Default: on.

## Graphics: WIP > Volumetric (mist, fog and clouds)

All off by default; they sit in the WIP tab. Drawn on the picture after the scene, so nothing in the game changes.

- **Volumetric Mist**: pale banks along the ground as a real volume, marched along each pixel's ray: thickest at the
  ground Banjo stands on (a slow anchor, so it doesn't bob when he jumps) and gone about 300 units above it, drifting
  slowly, lit by the sun and warmer looking towards it. Not tied to Banjo's position sideways. 0 to 100; 0 is off.
- **Volumetric Fog**: an even fog through the whole scene with slow patches in it, lit by the sun. 0 to 100 (100 the
  preset as designed); 0 is off.
- **Volumetric Fog Preset**: Default, Bright, Hell, Murky, Poison, Sponza, Pillar: the settings of Vapor's presets.
- **Volumetric Clouds**: Off, Fair, Scattered, Overcast, Stormy, Wispy, Sunset, Thunderstorm. The cycle's 3D clouds on
  the sky of any level, day or night cycle or not (with the cycle, they replace its clouds).
- **Volumetric Level File**: reads `Dev Files/volumetric.txt`, one level a line, overriding the options for that
  level (cloud type and shape, mist, fog, preset, mist height). Made the first time any option is on, with the format
  in its comments; read again within a second of a change. The **Save Volumetric Settings** key (Controls >
  Volumetric, no default binding) frees the mouse and shows buttons down the left: Cloud Type, Cloud Shape, Mist, Fog,
  Fog Preset and Save All. A click writes that setting, as showing now, into this level's line (a setting already
  saved shows "(saved)"); press the key again to close them. Test aid: `TOOIE_VOL=<mist>,<fog>,<preset 0-6>,<clouds 0-7>`.

## Graphics: Game Frame Rate and Interpolation

Both sit in the "Frame rate and overlay" section, Interpolation right under
Game Frame Rate.

- **Game Frame Rate**: how often the game itself updates, not the in-between
  frames that Interpolation adds. Applies from the next frame.
  - **Original** (default): the game's own timing. It waits for at least two
    screen refreshes (a few places, such as the title screen and the
    Hailfire Peaks cannon, ask for three or four), and a frame that ran late
    moves the whole game a bigger step.
  - **30 FPS**: every game frame is exactly two refreshes long with the same
    step, everywhere, including the places that asked for 20 or 15 fps.
  - **60 FPS**: the game updates every refresh with half the step. Movement
    keeps its speed; anything the game counts in frames rather than time
    would run twice as fast.
  - **120 FPS (Experimental)**: every game frame is 1/120 s. The runtime sends
    screen refreshes (VIs) 120 times a second for this, while the sound is
    still made 60 times a second. A 60 Hz monitor still only shows 60 of them.
  - **Unlocked (Experimental)**: the game makes frames as fast as the PC can,
    up to 240 a second, and each step is the time that really went by (in
    240ths of a second).
  - With 120 FPS and Unlocked anything the game counts in whole frames rather
    than time is kept at 60 a second where the game uses its frame count, but
    objects that move a fixed amount every frame would move too fast.
  - With 30, 60 or 120 FPS, a PC that cannot keep up slows the game down
    instead of taking bigger steps.
  - Scenes the game plays from recorded frames keep its own pacing: the
    attract demos, the game select screen and the intro story cutscenes
    (checked headless; they run at the game's 20 fps whatever this is set to).
- **Interpolation** (was "Framerate"): draws in-between frames so motion
  looks smoother than the game's own frame rate. It does not change the game.
  - **Off** (was "Original"; saved as Original): only the frames the game makes.
  - **Display**: your screen's refresh rate.
  - **Manual**: the number you set (20 to 240).

## Graphics: Frame rate overlay

- **Frame rate overlay**: Off, Compact or Full. A small box in the top left
  corner, updated four times a second. **Compact** shows only the first line
  below (frame rate, frame time and input latency). **Full** shows, in four
  groups with a small gap between them (frames; GPU; the game and where Banjo
  is; the PC and the build):
  - the frame rate and frame time on screen (averaged over the last quarter
    second)
  - the worst frame time in that quarter second
  - input latency, averaged over the last 2 seconds, with the worst: the time
    from the game reading your controller to the first frame on screen that
    was made from that read. Your monitor's own delay and the controller's
    are not included.
  - the GPU time per game frame
  - the GPU time of each of the port's extra passes that ran, in ms: on
    the game's frame the sun shadow map, the water mask, bloom, eye
    adaptation, AO and bounce light (the half-size pass for ambient
    occlusion, bounce light and SSGI, traced or not) and the effects pass
    (fog, outlines, rim light and the other scene effects share that one
    pass, so they show as one figure; the Effect Cost Check key splits it
    up); with Ray tracing on, a "GPU ray tracing" line with the ray tracing
    build (the structures rebuilt each frame) and the traced effects (the
    effects pass while it traces: reflections, shadows, light beams and path
    tracing together); on each frame
    shown SMAA, FXAA, photo filters, FSR, the output to the window and the UI
    (menus, notices and this overlay). The rest of the GPU time is the game's
    own drawing.
  - the game's own frame rate (the frames it really makes; with Interpolation
    on, the rest are in-between frames), counted over the last
    2 seconds (over a quarter second a 30 fps game read as 28 and 32)
  - on the same line, the game's CPU time per game frame and how busy it kept
    the CPU: the time its own code ran (everything but its idle wait) over
    the same 2 seconds. High CPU time with a low GPU time means a slowdown
    comes from the game, not from drawing.
  - the Interpolation setting
  - frame interpolation: off, or on with how many models, bones and shadows
    it tracked in the last frame, and how many camera cuts it has seen
  - the 1% low over the last 5 seconds (the frame time 99 frames in 100
    beat, and the frame rate it works out to) and how many hitches there
    were: frames that took more than twice the usual time
  - shader compiles in the last 5 seconds and this session. A new mix of
    effects needs a shader the first time it is seen; until it is ready a
    slower general shader draws it, so a burst often lines up with a hitch on
    entering a new area.
  - the map number (as used by the Warp tab and bug reports) and name, and
    Banjo's position
  - the renderer (Vulkan or D3D12), the internal resolution and the
    Resolution setting, MSAA and the display's refresh rate
  - whether Speed-up is running, whether cheats are on, and which mods
    (texture packs included) are on
  - audio: how much sound was queued (normal is about 10 to 50 ms), how many
    dropouts there were (the queue ran dry: a gap you can hear) and how many
    chunks were sped up to cut lag, over the last 2 seconds
  - the build: its commit and date
  - a graph of the last 100 frame times, newest on the right. Twice the usual
    frame time fills it; a hitch is drawn in red.
  Default: Off.
- **Benchmark key** (no default key, bind it under Hotkeys in the Controls tab): records
  the overlay's figures to `benchmarks\` next to the exe until pressed again, then
  writes a summary with the settings (notes/keys.md). Use it to compare two
  settings or two builds on the same spot.
- **Effect Cost Check key** (no default key, bind it under Hotkeys in the
  Controls tab): finds which effects cost the most on your PC. It measures
  the GPU time with everything as set, then turns each effect that is on
  off in turn for a few seconds (your settings are not changed or saved),
  then measures as set again, and lists the effects heaviest first, with
  each one's ms and share of the GPU time, in the overlay (shown for the
  check even when the overlay is off) and in `benchmarks\effect_cost_<date>.txt`.
  Ray tracing is one entry (its effects fall back to their screen-space
  forms), then path tracing, traced light beams and hit colours on their
  own. Stand still for it: about 3 seconds an effect. Press again to stop.
  SMAA, FXAA and FSR are not in it: the overlay times them on their own.
- **Frame Rate Overlay key** (F3, rebindable under Hotkeys in the Controls
  tab): steps the overlay through Off, Compact and Full while you play, with
  a notice. It lasts for the session; the setting decides how the next
  session starts, and changing the setting takes over from the key.

## Graphics: Debug

- **Effect debug view**: for testing. Shows one picture effect or filter on
  its own, with every other one off: at its setting, or at a default
  strength when it is off (half for the scene effects and sharpening,
  saturation, vignette and grain; 30 contrast; SMAA High; FXAA; FSR On;
  16-bit Console; Deuteranopia; 2x texture upscaling). The list:
  - Off, then the scene effects' own views: Effects alone, Depth, Normals,
    Water (red, yellow where it reflects)
  - Only: ambient occlusion, bounce light, toon outlines, rim light, fog,
    bloom, light shafts, eye adaptation, water reflections, water waves,
    underwater tint and haze, heat haze and underwater distortion, depth of
    field
  - All effects off (the picture with none of them, to compare against)
  - Only: sharpening, contrast, colour saturation, vignette, film grain,
    SMAA, FXAA, FSR, CRT, N64 16-bit colour, colourblind filter, texture
    upscaling
  The Effect Debug View key steps to the next view (with Shift back) with a
  notice naming it; the Effect Compare key splits the picture, the effect on the left and the original on the right (SMAA,
  FXAA, FSR and the Retro filters aren't split). Brightness and N64 3-point
  filtering stay at their settings. Starts Off each launch. Default: Off.
- **Effect compare** (Graphics > Debug): the same split picture as the Effect
  Compare key, as a switch. Starts Off each launch.
- **Interpolation check** (Graphics > Debug): tints a model red for a moment
  when its blend between game frames looks wrong, and logs it. The
  Interpolation Check key switches it too. Shows nothing at Original. Starts Off each launch.
- **Interpolation blend mode** (Graphics > Debug): a list of the six ways
  in-between frames are blended (normal, no tags, tags with vertex blending,
  camera untagged, models snap, custom). Custom is the default: models snap
  to the game's own frames and the camera blends, but characters (models
  with bones: NPCs, enemies, bosses, the player) blend with their vertices,
  and a model or particle you tagged in the game (see the Pick Model and Tag
  Model keys in keys.md) does as its tag says; the tags live in
  `interp_tags.txt` in the `Dev Files` folder next to the save files. Normal blends every model
  without vertex blending. Starts on custom each launch. The Blend Mode key
  steps through them.

## Controls: Hotkeys and Debug

Every function key is bound in the Controls tab and can be changed there:
Hide HUD (F1), Speed-Up (F2, under Cheats), Frame Rate Overlay (F3), Photo Mode
(F10), Screenshot (F12) under Hotkeys. The Debug section has no default keys;
bind what you use: Effect Debug View (Shift steps back), Interpolation Check,
Effect Compare, Blend Mode, Freeze, Warp Again (needs the Warp tab on), Pick Model,
Tag Model, Save Tags, Unsave Tag and Model Effects (the picked model skips the
screen effects).

## Cheats

Cheats are in their own tab. Turn on **Enable cheats** first. Every cheat below
is off by default and only shows while **Enable cheats** is on. Turning
**Enable cheats** off resets all the cheats below. Achievements cannot be earned
while cheats are on.

The three speed-up rows are the exception: **Speed-up** is on by default (it
still needs **Enable cheats**), and turning **Enable cheats** off leaves them
as they are.

- **Speed-up**: lets the Speed-Up key run the game faster. Off means the key
  does nothing. Default: on.
- **Speed-up factor**: how much faster the game runs while the speed-up is
  active. Range 2 to 4. Default: 3. Greyed out while **Speed-up** is off.
- **Speed-up toggle**: press the Speed-Up key to switch the speed-up on and
  off, instead of holding it. Default: off. Greyed out while **Speed-up** is off.
- **Infinite eggs**: blue, fire, ice, grenade, clockwork and mine eggs have no
  limit.
- **Infinite feathers**: red and gold feathers have no limit.
- **Infinite Glowbos**: Glowbos have no limit.
- **Infinite ice keys**: ice keys have no limit.
- **Infinite Jumps (Levitate)**: press A again in mid-air to jump again, and
  hold A to keep rising.
- **Cheato: FEATHERS, EGGS, FALLPROOF, HONEYBACK, JUKEBOX, GETJIGGY,
  SUPERBANJO, SUPERBADDY, HONEYKING, NESTKING and HOMING**: the game's own
  Cheato codes, switched on directly without the Code Chamber. Turning one off
  only undoes what this setting switched on, so a code you typed in the game
  stays on. Close the game with them off if you do not want them in your
  save.
- **Transformation**: play as any of Mumbo's or Humba's forms (Banjo, Kazooie,
  Mumbo, Bee, Stony, Washing machine, Snowball, Submarine, Golden Goliath,
  Detonator, Van, small or large T-Rex, Banjo-Kazooie).
  Picking one reloads the area you are in, at the entrance you came in by, so
  the new model shows. Some forms break in areas the game never expects them
  in (missing animations or data). It is a drop-down. The row goes back to
  Off by itself once the area reloads with the new form; pick Banjo-Kazooie to
  change back. Default: Off; the row also goes back to Off when Enable cheats
  is turned off.
- **Warp tab** (now in DEV > Additional Tabs): shows the Warp tab in the menu, with a list of places to warp
  to. The Warp Again key (Debug section of the Controls tab) repeats the last
  warp. Its last group, Race Warps (Replay Race), starts one of Canary Mary's four races as
  a practice run (your file is not changed and no prize is given). Default: off.
- **Stop 'n' Swop items**: marks the blue and pink Stop 'n' Swop mystery eggs as
  collected, without a Banjo-Kazooie save. Only these two flags are set; the
  yellow egg and the other items are not covered yet.
- **Unlock all moves**: every move counts as learned. Your save file is not
  changed.
