
## T1 Boots to the title screen
- Asked: 2026-10-13 14:01 UTC
- Build: Windows CI run 38416771448 (https://github.com/Locme/Banjo-Tooie-N64-Recomp/actions/runs/38416771448), artifact BanjoTooieN64Recomp-Windows-RelWithDebInfo
- Steps:
  1. Run BanjoTooieN64Recomp.exe, choose Start Game and pick your ROM
  2. Wait for the logo and title screen
- Look for: Does it reach the title screen with picture and sound, without a crash?
- Status: waiting for L

## T2 File select and new game
- Asked: 2026-10-13 14:01 UTC
- Build: Windows CI run 38416771448 (https://github.com/Locme/Banjo-Tooie-N64-Recomp/actions/runs/38416771448), artifact BanjoTooieN64Recomp-Windows-RelWithDebInfo
- Steps:
  1. Press Start at the title screen
  2. Pick a file and start a new game
  3. Play for a few minutes: walk, jump, open a menu, change area
- Look for: Does anything crash, freeze, look wrong or sound wrong?
- Status: waiting for L

## T3 Beak Barge sound
- Asked: 2026-10-13 14:01 UTC
- Build: Windows CI run 38416771448 (https://github.com/Locme/Banjo-Tooie-N64-Recomp/actions/runs/38416771448), artifact BanjoTooieN64Recomp-Windows-RelWithDebInfo
- XBLA history: report §4.66
- Steps:
  1. Load a save in Witchyworld and do the Beak Barge
  2. Run it once with the right stick held forward
  3. Run it once with the stick held backward
- Look for: Does the barge sound play to the end, and does its volume drop when the stick is forward?
- Status: waiting for L

## T4 Witchyworld music
- Asked: 2026-10-13 14:01 UTC
- Build: Windows CI run 38416771448 (https://github.com/Locme/Banjo-Tooie-N64-Recomp/actions/runs/38416771448), artifact BanjoTooieN64Recomp-Windows-RelWithDebInfo
- XBLA history: report §4.65
- Steps:
  1. Enter Witchyworld
  2. Walk around the park and into a couple of areas for a minute or two
- Look for: Does the music sound right (right notes, pitch and tempo)?
- Status: waiting for L

## T5 Cutscene audio sync
- Asked: 2026-10-13 14:01 UTC
- Build: Windows CI run 38416771448 (https://github.com/Locme/Banjo-Tooie-N64-Recomp/actions/runs/38416771448), artifact BanjoTooieN64Recomp-Windows-RelWithDebInfo
- XBLA history: report §4.30
- Steps:
  1. Start a new game to watch the intro cutscenes
  2. Watch to the end
- Look for: Do music and picture stay together, or does the picture run ahead or behind?
- Status: waiting for L

## T6 Intro text
- Asked: 2026-10-13 14:01 UTC
- Build: Windows CI run 38416771448 (https://github.com/Locme/Banjo-Tooie-N64-Recomp/actions/runs/38416771448), artifact BanjoTooieN64Recomp-Windows-RelWithDebInfo
- Steps:
  1. Start a new game
  2. Watch the intro text starting Two years have passed
- Look for: Are the letters clean, or do they overlap or get clipped?
- Status: waiting for L

## T8 Widescreen edges
- Asked: 2026-10-13
- Build: latest main
- XBLA history: report §4.22
- Steps:
  1. Settings > Graphics: Aspect Ratio = Expand, in a 16:9 (or wider) window
  2. Start a game and walk around Spiral Mountain and Jinjo Village, turning the camera
- Look for: Does the picture fill the window without looking stretched? Do things pop in or vanish at the left and right edges while still on screen?
- Status: waiting for L

## T9 Graphics settings live
- Asked: 2026-10-13 17:02 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Press Esc, open Graphics
  2. Switch Aspect Ratio between 4:3, Fill and Letterbox 16:9 with the game running behind
  3. Make the window very wide, then very tall
- Look for: Does the picture change at once each time? Does Letterbox show exactly 16:9 with black bars? Do things pop in or vanish at the screen edges in Fill?
- Status: waiting for L

## T10 Quick start
- Asked: 2026-10-13 17:10 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Start the game
  2. Press Start while the Rare, Nintendo and Dolby logos show
- Look for: Does it jump straight to the file select with the jigsaw wipe? With Settings > General > Skip intro logos off, do the logos play through?
- Status: waiting for L

## T11 HUD at the screen edges
- Asked: 2026-10-13 17:45 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.22
- Steps:
  1. Settings > Graphics: Aspect Ratio = Fill, HUD Placement = Expand, in a 16:9 (or wider) window
  2. Load a file, play a little, collect a note, then pause
  3. Switch HUD Placement between Original, 16:9 and Expand
- Look for: Do the honeycombs and air sit at the left edge, and the notes, feathers and eggs (with their numbers) at the right edge? Does the jiggy counter stay in the middle? Does Original put everything back in the middle?
- Status: waiting for L

## T12 Frame rate (interpolation)
- Asked: 2026-10-13 17:50 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.15
- Steps:
  1. Settings > Graphics > Framerate = Original, walk and turn the camera in Spiral Mountain
  2. Set Framerate = Manual 40, then 60, then 120 (and Display), and do the same
  3. Watch a cutscene with camera cuts, and go through a door to another area
- Look for: Does movement look smoother above Original? Does the game still run at normal speed? Do camera cuts or doors show a one-frame smear or stretch? Does the HUD or anything else wobble?
- Status: waiting for L
