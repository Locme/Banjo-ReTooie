
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
- Look for: Does it jump straight to the file select with the jigsaw wipe? With Settings > QOL > Skip intro logos off, do the logos play through?
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

## T13 Screenshots (F12)
- Asked: 2026-10-13 17:55 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.83
- Steps:
  1. In game, press F12, then open the menu (Esc) and press F12 again
  2. Open the screenshots folder next to the exe
- Look for: Does "Screenshot saved" show each time? Is each PNG the game picture only (no menu, no notice), with the right colours and the same shape as the window?
- Status: waiting for L

## T14 Level warp
- Asked: 2026-10-13 18:05 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.80
- Steps:
  1. Settings > General: turn on Debug tab. Load a file, press Esc, open the Debug tab and pick a few places in different levels
  2. Press F9 after leaving the area you warped to
- Look for: Does each warp land you standing in the right place, with the usual wipe? Does F9 take you back to the last pick? Any place that crashes or drops you in a wall?

## T15 Text speed
- Asked: 2026-10-13 18:10 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.52
- Steps:
  1. Settings (Esc) > QOL > Text speed = 2x, then talk to someone (or start a new game and watch Klungo's intro)
  2. Repeat with 4x and Instant, then Normal
  3. Open the pause menu and the file select with each setting
- Look for: Does text print faster at 2x and 4x, and appear a page at a time on Instant? Do the pauses after commas and full stops shrink too? Are menus unchanged? Does the change apply without restarting?
- Status: waiting for L

## T16 Levitate and Infinite jumps cheats
- Asked: 2026-10-13 18:30 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.73 and §4.79
- Steps:
  1. Esc > Cheats, turn on Enable cheats, then Levitate. Load a file, hold D-pad down
  2. Turn Levitate off and Infinite jumps on. Jump, then press A again in the air several times, then hold A
  3. Compare the two. Also try it as Kazooie flutter, and in water and as a transformation
- Look for: Does Levitate lift you smoothly while D-pad down is held, and stop when released? Does each extra A press in the air jump again, and does holding A keep you rising? Does it stay off when the master switch is off? Do you want to keep both or drop Levitate?
- Status: waiting for L

## T17 Hide HUD (F1)
- Asked: 2026-10-13 18:25 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.84
- Steps:
  1. In game, press F1, walk around, talk to someone, pause; then press F1 again
- Look for: Do the HUD and text boxes vanish while hidden, and come back after the second F1? Does "HUD hidden" / "HUD shown" show? Anything else that vanishes or stays that should not?
## T18 Level transition speed
- Asked: 2026-10-13 18:40 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.29
- Steps:
  1. Settings (Esc) > QOL > Level transitions = Fast, then walk through a few doors and level entrances
  2. Repeat with Instant, then Original
  3. Watch a cutscene that fades to black
- Look for: Are the wipes clearly faster on Fast and nearly gone on Instant? Does anything look cut off or flash? Do cutscene fades keep their normal speed?
- Status: waiting for L
