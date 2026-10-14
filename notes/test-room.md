# Test room (work in progress, paused 2026-10-14)

Warp > Test > Test room warps to Quagmire (placeholder area) and spawns the
line-up in `src/gameplay/test_room_actors.inc` in rows in front of Banjo, each
actor held on its spot. Transformations are Golden Goliath statues with the
form's model swapped in; walking up to one turns Banjo into that form (the
area reloads and the room fills again). Code: `src/gameplay/test_room.cpp`.

## How actors are spawned

`func_80108474(actor id, f32 pos[3], yaw)` spawns by id through gemarkersDll's
table (ids 0xB6 to 0x545, 767 used). The id-to-overlay-to-model list was built
from the decompressed ROM (gemarkersDll at ROM 0x0214CDC0, table at +0x90) and
ScriptHawk's model names. Generic data-driven enemies (Gruntlings and the like,
overlay chbaddieDll) are not in that table and cannot be spawned this way.

## Verified headless

- Objects row (39 entries) spawns without a crash in Quagmire.
- Transformation statues show the Van, Washing Machine, Bee, Snowball,
  Mumbo, Kazooie, Banjo-Kazooie and Golden Goliath models.
- Mumbo (0x190) alone spawns and stays.

## Crash sweep so far (characters)

Crash in their own update outside their home area (left out):
Humba 0x2A1, Klungo (Spiral Mountain) 0x4EC, Dilberta 0x117, Chief Bloatazin
0x115, Gobi 0x137, Mrs. Boggy 0x13F, Pawno 0x352, Tiptup 0x358/0x359,
Chris P. Bacon 0x1BE, Seemee 0x295, Loggo 0x435, Mr. Fit 0x477, Alien Dad 0x45A.

Not yet pinned down (the sweep may have blamed the wrong actor): crashes in
subaddierouteDll (an actor that follows a route; seen with Billy Bob 0x150 and
the Styracosaurus family 0x290-0x292 in the line-up), in
func_800B27A0 (with Gruntilda 0x528 last spawned), and heap_alloc_sided (the
game's heap running out when ~40 or more actors are spawned at once).

## Left to do

- Finish the sweep (characters, then enemies and objects), attributing route
  crashes properly, and split the room if the heap runs out.
- Pick a roomier, flat area than Quagmire.
- Headless check of the walk-up transformation switch.
