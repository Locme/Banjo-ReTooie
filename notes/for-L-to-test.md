
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
- Look for: Does it jump straight to the file select with the jigsaw wipe? With Settings > QOL > Press Start Early in Intro off, do the logos play through?
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
  1. Settings > Cheats: turn on Enable cheats, then Warp tab. Load a file, press Esc, open the Warp tab and pick a few places in different levels
  2. Press F9 after leaving the area you warped to
- Look for: Does each warp land you standing in the right place, with the usual wipe? Does F9 take you back to the last pick? Any place that crashes or drops you in a wall? Picking a place from the launcher's Settings, the title screen or the game select should only show "Start the game and load a file first".

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

## T16 Infinite Jumps (Levitate) cheat
- Asked: 2026-10-13 18:30 UTC, changed 22:00 UTC (the separate Levitate cheat was removed, L's call)
- Build: latest Windows CI build from main
- XBLA history: report §4.73 and §4.79
- Steps:
  1. Esc > Cheats, turn on Enable cheats, then Infinite Jumps (Levitate). Load a file
  2. Jump, then press A again in the air several times, then hold A
  3. Also try it as Kazooie flutter, and in water and as a transformation
- Look for: Does each extra A press in the air jump again, and does holding A keep you rising? Does it stay off when the master switch is off?
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

## T19 Cheato cheats
- Asked: 2026-10-13 18:50 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.70
- Steps:
  1. Esc > Cheats, turn on Enable cheats, then switch on one Cheato row at a time (try SUPERBANJO, FEATHERS, HOMING)
  2. Load a file and play a little, then switch the row off again
- Look for: Does each code do what its name says while on, and stop when off? Does a code you typed in the Code Chamber stay on after the row is switched off? The flag numbers are the N64 ones from the decomp, so any row that does nothing is worth telling me.
- Status: waiting for L

## T21 Texture pack from a zip (BT Reloaded)
- Asked: 2026-10-13 19:05 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Put bt-reloaded-v0.1.1-gliden64-png-4k.zip (or the RT64 download) into the `mods` folder next to the exe
  2. Start the game and wait. The first start unpacks it, which can take a minute for the 4K pack
  3. Open settings (Esc) > Mods and check BT Reloaded is listed and on
- Look for: Do the title logo, the copyright text and the menus look sharp instead of pixelated? Any textures that look wrong?
- Status: L, 2026-10-13 19:13: "Tested texture pack, seemingly works"

## T20 Banjo's animation above Original
- Asked: 2026-10-13 19:05 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.15
- Steps:
  1. Settings > Graphics > Framerate = Manual 60 (then 120, and Display)
  2. Walk, run, jump and swim with Banjo, and turn the camera; then walk past a few enemies and Jinjos
  3. On the game select screen, watch the shaking portraits and the hand
  4. Watch a few cutscenes with camera cuts (start a new game for the intro)
  5. Do a few flutter jumps (jump, then hold A) and watch Banjo's shadow
  6. Press Start a few times in a level and watch the menu's dark panels open and close
- Look for: Does the shadow keep its shape and stay under Banjo during the flutter? Do the pause panels slide open smoothly, without jumping back? Does the portrait and hand shake look the same as at Original (quick jitter, not a slow wobble)? At each cutscene camera cut, does the picture switch at once, without Banjo or the camera sliding? Do Banjo's and Kazooie's arms, legs and heads stay attached and move smoothly? Any part that flickers, stretches or floats away for a moment? Do other characters look right?
- Status: waiting for L

## T22 Timer save
- Asked: 2026-10-13 19:15 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.13
- Steps:
  1. Settings (Esc) > General > Timer save = 5
  2. Play in a level for a bit over 5 minutes (pausing doesn't count)
  3. Quit without saving, start again and load the file
- Look for: Does "Game saved" show after about 5 minutes of play? Does the loaded file keep what you did before the notice? Does it ever save while paused or in a cutscene?
- Status: waiting for L

## T23 Free camera (right stick)
- Asked: 2026-10-13 19:25 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.55
- Steps:
  1. Settings (Esc) > QOL > Free camera = On
  2. In a level, turn the camera with the right stick, then walk with the left stick
  3. Hold the right stick down at the lowest tilt, then up at the highest
  4. Click the right stick for first person and again to leave it
  5. Walk next to walls, swim and fly
- Look for: Does the camera turn smoothly at a speed you like? Does walking go where the camera faces? Does the camera go through walls? Does anything feel wrong when flying, swimming or in first person?
- Status: waiting for L


## T24 Audio glitch sounds
- Asked: 2026-10-13 19:21 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Play normally for 10 minutes or more, in places with music and lots of sound (Spiral Mountain, Mayahem Temple, Witchyworld)
  2. Try the Framerate mode you were on when you heard the glitch
- Look for: Do you still hear the short glitchy or sped-up sound now and then? If yes, which level and which Framerate mode?

## T25 Tiptoe key
- Asked: 2026-10-13 19:30 UTC, changed 19:55 UTC (now a hotkey in Controls, no longer a QOL setting)
- Build: latest Windows CI build from main
- XBLA history: report §4.56
- Steps:
  1. Load a file. Hold the left stick click (L3) and push the left stick fully in any direction
  2. Esc > Controls > Hotkeys: bind Tiptoe to another button or key and try it
- Look for: Does Banjo tiptoe at any tilt while L3 is held, and run again when you let go? Does the new binding work?
- Status: waiting for L

## T26 Stop 'n' Swop items
- Asked: 2026-10-13 19:30 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.68
- Steps:
  1. Esc > Cheats, turn on Enable cheats, then Stop 'n' Swop items
  2. Load a file, go to Spiral Mountain and the Isle O' Hags, and look for the mystery eggs (blue and pink)
- Look for: Do the blue and pink mystery eggs appear or become collectable? This is only a flag set; I could confirm the flags but not that the game shows the eggs, so expect partial results.
- Status: waiting for L

## T27 Jiggy level wipe in ultrawide
- Asked: 2026-10-13 19:40 UTC
- Build: main after 30992ad (next Windows CI build)
- Steps:
  1. Set Graphics > Aspect Ratio to Expand and use a 21:9 (or wider) window or screen
  2. Load a file and enter or leave a level, or use the Warp tab
  3. Watch the Jiggy-shaped wipe that opens the picture
- Look for: Does the Jiggy hole grow until the whole wide screen is clear, with no black left at the sides when it disappears?

## T28 Controller back buttons
- Asked: 2026-10-13 19:50 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Plug in the controller with back buttons, start the game and open Esc > Controls
  2. Click a binding slot (for example Z) and press a back button
  3. Load a file and check the back button does what you bound
  4. Open logs/console.log and find the "Controller added" lines: they name the controller and list which back buttons it reports
- Look for: Does the slot show L4, R4, L5 or R5 (or a Steam-style icon for the fifth one) when you press a back button? If nothing happens, what is the controller's name and model, and what do the "Controller added" lines say?
- Status: waiting for L

## T29 Always High-Detail Models
- Asked: 2026-10-13 20:00 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.28
- Steps:
  1. Settings (Esc) > Graphics > Always High-Detail Models = On (the default)
  2. In a big area (Jinjo Village, Mayahem Temple, Witchyworld), look at things far away
  3. Switch the option Off and On while looking
  4. Turn the camera to look at Banjo from the front, from a normal distance
- Look for: With it On, do far-away objects keep their detailed look instead of turning simpler? Does Banjo wear his necklace and the white belt buckle even when the camera is not close (with it On)? Does anything flicker, vanish or slow down?
- Status: waiting for L

## T30 Extended draw distance
- Asked: 2026-10-13 20:40 UTC, fixed 22:20 UTC (the first version made feathers, eggs and enemies vanish)
- Build: latest Windows CI build from main
- XBLA history: report §4.26
- Steps:
  1. Settings (Esc) > Graphics > Extended Draw Distance = On (it is now off by default)
  2. Walk around Spiral Mountain and Jinjo Village, then a big area (Mayahem Temple, Witchyworld)
  3. Switch the option Off and On while looking
- Look for: Are feathers, eggs and enemies all there again with it On? Do far-away characters stay drawn longer instead of popping in? Any slowdown?
- Status: waiting for L

## T31 Transformation picker
- Asked: 2026-10-13 20:05 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.78
- Steps:
  1. Esc > Cheats > Enable cheats on, then Transformation: pick Bee
  2. The area reloads. Then pick Off: you should be Banjo-Kazooie again. Try a few more forms (Washing machine, Van, Snowball, Submarine, T-Rex) in different areas
- Checked headless: Mumbo, Bee, Stony and Kazooie show and hold in Spiral Mountain. The others are untested. Clockwork Kazooie was added later (crash fixed) and holds in Spiral Mountain.
- Look for: Does the new form show and play right after the reload? Which forms crash or look wrong, and where? Does pausing and leaving the area keep the form?
- Status: waiting for L

## T32 Talon Trot toggle
- Asked: 2026-10-13 20:13 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.54
- Steps:
  1. Settings (Esc) > QOL > Talon Trot = Toggle (the default)
  2. Load a file where Talon Trot is learned (or turn on Cheats > Unlock all moves). Hold Z, press C-left to trot, then let go of Z
  3. Trot around and jump with A, then press Z to stop. Start again and stop with C-left
  4. Trot into water, then set the option to Hold and check the trot ends when you let go of Z
- Look for: Does Banjo keep trotting after you let go of Z, and stop on Z or C-left? Does anything get stuck after the trot ends by itself (in water, when hit)? This was broken on the XBLA port on your PC, so please try it with your controller.
- Status: waiting for L

## T33 Field of view
- Asked: 2026-10-13 21:00 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.24
- Steps:
  1. Settings (Esc) > Graphics > Field of View = +20 (default 0, range -10 to +30)
  2. Walk around Spiral Mountain, then change the value while playing
  3. Watch a cutscene; set Cutscene Field of View to +10 and watch one again
- Look for: Does the view get wider during play and change as soon as you move the slider? Do cutscenes stay as they were until you change the cutscene setting? Is anything missing at the screen edges, or do the HUD icons look wrong?
- Status: waiting for L

## T34 Build and settings in the logs
- Asked: 2026-10-13 20:25 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Start the game, open Esc > Graphics and change Aspect Ratio or Frame Rate, apply, then quit normally
  2. Open logs/console.log next to the exe
  3. If you have crash_*.dmp files from earlier, count them in logs/ after starting the game once
- Look for: Does console.log start with a line naming the build and commit, then "Settings in effect:" with graphics, general, qol, cheats and sound lines? Is there a "Setting changed:" line for what you changed? Are at most 4 old crash_*.dmp files left in logs/? (The next crash entry in crashes.log will carry the same build and settings lines.)
- Status: waiting for L

## T35 Banjo's shadow in water
- Asked: 2026-10-13 20:40 UTC
- Build: latest Windows CI build from main (it has the shadow interpolation change from T20's thread)
- Steps:
  1. Load a file and walk into shallow water where Banjo wades (for example the pond in Mayahem Temple's Prison Compound), then swim into deeper water
  2. Stand still for a few seconds, then walk slowly in the water
  3. Do this at Esc > Graphics > Frame Rate = Original (30 fps), then again at your usual frame rate above 30
- Look for: Does the shadow still flicker? If it does: only above Original, or at Original too? Does it blink fully on and off, or do parts of it shimmer at the edges? Wading, swimming, or both?
- Status: waiting for L

## T36 Faster Windows build (full inlining)
- Asked: 2026-10-13 20:40 UTC
- Build: main @ 85773ec or later
- Steps:
  1. Note your fps or how smooth it feels in a busy spot (e.g. Witchyworld or Mayahem Temple) on your current build
  2. Update and build again (update_and_build.bat), then go to the same spot with the same settings
- Look for: Is it the same or faster? Anything that broke or crashes that did not before?

## T37 Brightness, colourblind and retro filters
- Asked: 2026-10-13 20:37 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.25, §4.40, §4.41
- Steps:
  1. Esc > Graphics: turn on Brightness test pattern, close the menu, then try Brightness -5, 0 and +5
  2. Turn the pattern off. Set Colourblind filter to each of the three types, and try Colourblind filter strength
  3. Set Retro: N64 16-bit colour to Console, then Raw dither (changed after your first look), then turn on Retro: CRT, then switch Retro: N64 3-point filtering off and on while looking at a close wall or the ground
  4. Do the same on D3D12 and Vulkan (Graphics API, needs a restart)
- Look for: Does each change show at once, with no restart? With the pattern on, can you set Brightness so box 1 just vanishes and box 2 just shows? Do the colourblind filters make reds and greens (or blues and yellows) easier to tell apart? Does Console or Raw dither look like 16-bit colour on a real N64 to you, and do the CRT lines look right at your screen size? Anything black, wrong colours or a crash on D3D12? I could only run Vulkan here.
- Status: waiting for L

## T38 Black squares: frame rate on or off
- Asked: 2026-10-13 20:42 UTC
- Build: your current build
- Steps:
  1. Go to Witchyworld's Cave of Horrors (Warp tab) and stand in front of the middle cell, then walk toward it, for about a minute at your usual 170 fps
  2. Press Esc > Graphics and set Frame rate to Original
  3. Do the same minute again
- Look for: Do the black squares show up at 170 fps but never at Original?
- Status: answered 2026-10-13 22:00 UTC
- L's result: Frame rate Original fixes it: the squares only come with the in-between frames (170 fps)

## T39 Skip boss intros
- Asked: 2026-10-13 22:10 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.62
- Steps:
  1. Settings (Esc) > QOL > Skip boss intros = On (the default)
  2. Warp to Chilly Willy (or any boss you haven't fought on this file) and press B once during the intro
  3. Press B while talking to someone, e.g. Jamjars or Mumbo: nothing should be skipped. Then turn on QOL > Skip other cutscenes and try again: the conversation should race through
- Look for: Does the intro fast-forward (a "Skipping cutscene" message, the scene racing through its dialogue) and stop right as the fight starts? Which bosses did you try, and did any intro not skip?
- Status: waiting for L

## T40 Banjo slides in cutscenes (top priority, L)
- Asked: 2026-10-13 22:11 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Start a new game and go up Spiral Mountain to the Klungo cutscene, or walk up to a spot where Jamjars talks to you (a sign, e.g. near the Haunted Tavern) and let him talk
  2. Do it again with Settings (Esc) > QOL > Free camera = Off
  3. If he still slides, do it again with Graphics > Frame rate = Original
- Look for: Which of the three runs does Banjo slide in? Does he end up somewhere else after the talk, or only look like he slides while it lasts?
- Status: waiting for L
- Fix to test (2026-10-13 23:40 UTC, CI build after the "Banjo no longer slides" commit): the game's "stop moving" step for standing and talking was recompiled empty, so Banjo kept his walking speed through the talk at any frame rate. Headless at the Haunted Cavern sign he now stops where Jamjars starts talking. Retest step 1 (sign and Klungo).

## T41 Canary Mary races
- Asked: 2026-10-13 22:14 UTC
- Build: the Windows CI build after the main thread regenerates with the Canary Mary hooks (the changelog will say so)
- XBLA history: report §4.53
- Steps:
  1. Esc > QOL > Canary Mary races = Fair (the default)
  2. Race Canary Mary in Glitter Gulch Mine (and in Cloud Cuckooland if you can reach it). Try to get ahead of her
  3. Try Easy, then Original, in a race you can restart
- Look for: With Fair, does she stop catching up when you lead, while still racing at her normal pace? Is Easy clearly easier? Does Original feel like the N64 race you know? I could not reach a race headless, so this is untested in play.
- Status: waiting for L

## T42 Frame rate overlay
- Asked: 2026-10-13 22:13 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Esc > Graphics: turn on Frame rate overlay and close the menu
  2. Play for a minute with Framerate on Display, then on Original, then on Manual at a few values
  3. Turn the overlay off and on a few times while you play
- Look for: Does the box sit in the top left corner and do its numbers change as you play? Does the frame rate it shows match your monitor (or the Manual value) and drop to about 30 or 20 with Original? Does "Game" stay at about 20 or 30 fps whatever Framerate says? Does turning the overlay on change how smooth the game feels? I could only check it with software rendering here, where it showed no difference beyond normal noise.
- Status: waiting for L

## T43 Picture shape jump when a cutscene starts (ultrawide)
- Asked: 2026-10-13 22:31 UTC
- Build: main after 8840cdc (next Windows CI build)
- Steps:
  1. Set Aspect Ratio to Expand on a 21:9 screen and Frame rate above Original
  2. Pick up an item whose first pickup starts a scene (a Cheato page, say), or start any cutscene with black bars
  3. Watch the first moment of the scene
  4. Do it once more with Frame rate at Original
- Look for: Does the picture keep its shape as the scene starts, or does it still squash or stretch for a moment (and at which frame rate setting)?

## T44 Fine aim
- Asked: 2026-10-13 22:31 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.57
- Steps:
  1. Esc > QOL > Fine aim = Always, Fine aim speed = Medium
  2. Load a file, press C-up for first person and turn with the left stick. Try a small and a full push
  3. Try Hold R (turn with and without R held), and the Slow and Fast speeds
- Look for: Is turning slower but still smooth, with no stick range where nothing happens? Does R do anything else in first person that this gets in the way of? Breegull Blaster sections weren't tested.

## T47 Resolution 720p, 1080p, 4K
- Asked: 2026-10-13 22:40 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Settings (Esc) > Graphics > Resolution: pick 720p, then 1080p, then 4K, then Auto
- Look for: Does the picture get sharper with each step (4K may be slow on weaker GPUs)? Does your choice stay after a restart? The window size itself does not change; this is the resolution the game is drawn at.
- Status: waiting for L

## T45 Interpolation check (F7)
- Asked: 2026-10-13 22:38 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Play at your usual frame rate above Original (170)
  2. Press F7 (a notice says "Interpolation check on")
  3. Play where you saw the graphics hitch; whenever something turns red, note where you were
  4. Send logs/console.log (next to the exe) afterwards
- Look for: Does the hitch line up with something turning red? Does anything turn red that looks fine? Do dust and feathers look smooth now?

## T46 Back-Port: Old Banjo sounds
- Asked: 2026-10-13 22:40 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Esc > General: turn on Back-Port: Old Banjo sounds
  2. Load a save and jump a few times, then twirl-jump and flap
  3. Turn the option off and jump again
- Look for: With it on, are Banjo's jump grunts the Banjo-Kazooie ones? With it off, are they Banjo-Tooie's again? I could only check headless that the jump sound table holds the old ids; there is no audio here.
- Status: waiting for L

## T48 Back-Port: Glittering honeycombs
- Asked: 2026-10-13 22:50 UTC; reworked 23:30 UTC to match Banjo-Kazooie (L: "it works, but its not good", then picked "Match BK")
- Build: latest Windows CI build from main
- XBLA history: report §4.63
- Steps:
  1. Settings (Esc) > General > Back-Port: Glittering honeycombs = On (off by default)
  2. Find a health honeycomb (Spiral Mountain has three in a cave; enemies and beehives drop more)
- Look for: The glints now flash on the comb itself, at its edges, like in Banjo-Kazooie, instead of in the air around it. Is that closer? Too many or too few? Does switching the option off stop it?
- Status: waiting for L

## T49 SMAA Anti-Aliasing
- Asked: 2026-10-13 23:00 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Esc > Graphics: MS Anti-Aliasing None, SMAA Anti-Aliasing High, and close the menu
  2. Stand somewhere with straight edges against the sky or grass (Spiral Mountain's cliffs and posts) and switch SMAA between Off and High a few times
  3. Try Low and Ultra, then MSAA 2X or 4X together with SMAA High
- Look for: Are the stair-steps on edges smoothed with SMAA on, without the picture going blurry? Does it change at once when you switch it? Does it work with MSAA on, and does the frame rate drop noticeably at Ultra? Only checked here with software rendering on Vulkan; D3D12 wasn't tested.

## T50 Fly anywhere
- Asked: 2026-10-13 23:00 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.74
- Steps:
  1. Esc > Cheats: Enable cheats, then Fly anywhere = On
  2. Load a save, stand anywhere and press D-pad up
  3. Fly around, then press B
  4. Try it as the bee too (Cheats > Transformation > Bee)
- Look for: Does D-pad up take off from the ground and from mid-jump? Does B stop flying and drop you, instead of a Beak Bomb? Stopping high up can splat you like any long fall.
- Status: waiting for L

## T51 Back-Port: Get Jiggy animation
- Asked: 2026-10-13 23:25 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Esc > General: Back-Port: Get Jiggy animation on
  2. Collect a Jiggy (as Banjo and Kazooie)
  3. Turn it off and collect another one
- Look for: With it on, does Banjo do BK's dance (fist pumps, Kazooie pops out at the end) under Tooie's black bars, and does the game carry on normally afterwards? Is it the right dance as you remember it from BK? Does any other item (Cheato page, Jinjo, Glowbo) wrongly get the dance too? Only checked here by starting the pose without a real Jiggy.
- Status: waiting for L

## T52 Game Frame Rate (Original / 30 FPS / 60 FPS)
- Asked: 2026-10-13 23:40 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Esc > Graphics: turn on Frame rate overlay
  2. Play somewhere busy at Game Frame Rate = Original and watch the "Game ... fps" line
  3. Switch Game Frame Rate to 30 FPS, then 60 FPS, and play the same spot
- Look for: Does the Game line now sit at 30 at Original and 30 FPS (it used to flip 28/32 because it was counted over a quarter second), and at 60 with 60 FPS? Does 60 FPS feel smoother without anything running too fast (Banjo moved at the same speed here; timers, animations, enemies, music sync and minigames are untested)? Does any place hitch or go slow-motion at 30 or 60?
- Status: waiting for L

## T53 Noclip
- Asked: 2026-10-13 23:45 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.75 (the XBLA version didn't clip and its D-pad didn't rise on your PC; this one is new and uses LT/RT as you asked)
- Steps:
  1. Esc > Cheats: Enable cheats, then Noclip = On
  2. Load a save, hold RT (R) to rise, let go, walk around in the air
  3. Hold LT (Z) to sink through the ground, then walk into a wall or cliff
  4. Turn Noclip off
- Look for: Do you rise and sink while held and stay at that height when you let go? Do you pass through walls, floors and ceilings? When you switch it off, do you fall normally? If you rebound LT/RT in Controls, the buttons follow the N64 Z and R bindings.
- Status: waiting for L

## T54 Save Game Select smoothness
- Asked: 2026-10-13 23:55 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Frame rate at your usual 170 fps
  2. Open the Save Game Select screen and watch the hand waving in picture 1, and the pictures
- Look for: Does the hand's wave look smooth now? The pictures' small shake should stay quick and crisp, as before (it is drawn at the game's own rate on purpose). Anything stretched or jumping?
- Status: waiting for L

## T55 Split up anywhere
- Asked: 2026-10-14 00:05 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.76
- Steps:
  1. Esc > Cheats: Enable cheats, then Split up anywhere = On
  2. Load a save that has learned Split Up, stand still somewhere and press D-pad down
  3. The first time, Jamjars explains splitting up; press A through it
  4. Walk Banjo right up to Kazooie: they should stay apart
  5. Press D-pad right (play Kazooie), walk her somewhere, then D-pad left (back to Banjo)
  6. Press D-pad down again
- Look for: Do they split where you stand, without a split-up pad? Do D-pad left/right switch who you play, with the camera following, while the other one waits? Do they stay apart until you press D-pad down, then join up again (even when far apart)? Try it somewhere cramped or on a slope too.
- Status: waiting for L

## T56 Unlock everything
- Asked: 2026-10-14 00:30 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.72 (you said the XBLA one was incomplete)
- Steps:
  1. Load an early save (or a new game past the intro)
  2. Esc > Cheats: Enable cheats, then Unlock everything = On. The area reloads once.
  3. Go around Isle o' Hags: world entrances, warp pads, Jamjars' silos (moves), Chuffy's stations, Pine Grove, the bridge to Hailfire Peaks, Cauldron Keep's drawbridge
  4. Check the Cheato codes in the Code Chamber
- Look for: Is anything still locked? Tell me which door or path, and I'll find its switch. Headless I only checked that the game reads the 134 switches as set and that the area reloads.
- Status: waiting for L

## T57 Music player
- Asked: 2026-10-14 01:10 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Load a save and stand anywhere, e.g. Spiral Mountain
  2. Esc > Sound > Music player: pick a song (Jolly's jukebox songs by name, then Track 0 to 159)
  3. Pick another one, then Level music
  4. Pick a song again and go through a door to another area
- Look for: Does the level's music fade out and the song start? Does Level music bring the area's music back? Does going to another area end the song (the row goes back to Level music)? The names come from the decomp's jukebox switch names, so tell me any that are wrong. Some tracks are short jingles: the game brings its own music back after them.
- Status: waiting for L
