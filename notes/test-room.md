# Test room

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

## Verified headless (2026-10-15, More game memory on)

- The line-up is 104 entries: 14 transformation statues plus 90 objects,
  characters and enemies. Three full runs in Quagmire with no crash; about 94
  stay, and 10 leave on their own (Treble Clef nest, Wading Boots, Soggy,
  Captain Blubber, Captain Blackeye, Scrut, Dippy, Dingpot, Inky, Blubbul).
- 58 entries are commented out in `test_room_actors.inc` ("crashes here"):
  they crash outside their home area. Most are actors that follow a route
  through `subaddierouteDll` or `sucoaster`/`sucoasterfly` (their route data
  only exists in their own map), the rest crash in their own update (missing
  animation or prop data). Gruntydactyl, Guvnor and Keelhaul also write into
  heap headers.
- Crowd crashes (display list overflow, full animation caches) were fixed by
  More game memory; with it off the room may crash.

## Characters that start scenes (2026-10-16)

Six characters started a scene by themselves from across the room on a file
that hasn't met them yet (headless, no file loaded), so they are commented out
in `test_room_actors.inc`. Gruntilda (0x528) starts her Tower of Tragedy quiz
intro ("I'm Grunty, your host"). King Jingaling, Jolly Roger, Bullion Bill,
Conga and Biggafoot start talking. With them out, the full room ran 100 s
after filling with no scene. Two things were tried first and dropped. Fast-
forwarding the talk with the cutscene skip hit its 45 s limit on Jingaling.
Reading every FTT ("first time talk") flag as set left the screen black, and
Jingaling, Bill and Biggafoot don't use FTT flags anyway.
Not cutscenes: the "Isle O' Hags (Quagmire)" name card on arrival, and
Stomponadon's boss name card when Banjo gets near it.

## Finding which actor crashes

The headless sweep runs the room with `TOOIE_TEST_ROOM_ONLY=<ids>` (hex,
comma separated) under gdb and removes the actor whose overlay shows in the
crash backtrace. A crash in `subaddierouteDll` called from a shared helper
names no actor: blame the last spawned actor whose overlay calls the route
or coaster helpers (blaming the last spawned actor of any kind threw out ~20
innocent ones). `TOOIE_TEST_ROOM_HEAPCHECK=1` walks the heap every frame.

## Ideas not done

- A roomier, flat area than Quagmire (the kickball arena, map 0xC6).
- Spawning route actors in their home map, or with a stub route.
- Headless check of the walk-up transformation switch.
