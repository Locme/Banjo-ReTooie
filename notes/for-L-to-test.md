
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
- L's result: L, 2026-10-14: fixed

## T28 Controller back buttons
- Asked: 2026-10-13 19:50 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Plug in the controller with back buttons, start the game and open Esc > Controls
  2. Click a binding slot (for example Z) and press a back button
  3. Load a file and check the back button does what you bound
  4. Open logs/console.log and find the "Controller added" lines: they name the controller and list which back buttons it reports
- Look for: Does the slot show L4, R4, L5 or R5 (or a Steam-style icon for the fifth one) when you press a back button? If nothing happens, what is the controller's name and model, and what do the "Controller added" lines say?
- Status: closed by L (2026-10-14 11:02). The Ultimate 2 runs in X mode (XInput), which never sends back buttons or gyro; BT switch position over USB would, L keeps X mode.

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
- Asked: 2026-10-13 20:40 UTC, fixed 22:20 UTC (the first version made feathers, eggs and enemies vanish); 2026-10-14 the toggle now applies at once (before, it did nothing until Apply), and notes, eggs and other placed objects now also draw as far as characters; 19:50 UTC Doubloons and other objects with their own short draw distance reach further too
- Build: your local build of main from 2026-10-14 10:00 UTC or later
- XBLA history: report §4.26
- Steps:
  1. Settings (Esc) > Graphics > Extended Draw Distance = On (it is now off by default)
  2. Walk around Spiral Mountain and Jinjo Village, then a big area (Mayahem Temple, Witchyworld)
  3. Switch the option Off and On while looking, without pressing Apply
- Look for: Does it change straight away? Do far notes, eggs, feathers and honeycombs now show from much further away? Note anything that still pops in, and any slowdown in big levels (Witchyworld, Mayahem Temple). Are feathers, eggs and enemies all there again with it On? Do far-away characters stay drawn longer instead of popping in? Any slowdown?
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
  1. Run (don't stand still) into something that starts a talk or cutscene: Klungo going up Spiral Mountain on a new game, a sign where Jamjars or Bottles talks, or a pad
  2. Do it a few more times in different places
- Look for: Does Banjo stop where he is when the scene starts, and stay there until it ends? Does anything else about him look wrong in those scenes?
- Status: waiting for L
- Fix to test (2026-10-13 23:40 UTC, CI build after the "Banjo no longer slides" commit): the game's "stop moving" step for standing and talking was recompiled empty, so Banjo kept his walking speed through the talk at any frame rate. Headless at the Haunted Cavern sign he now stops where Jamjars starts talking, and in Klungo's Spiral Mountain scene started while running (before: he slid over 4000 units) he stops on the spot. Retest steps 1 and 2.

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
- Asked: 2026-10-13 23:25 UTC; 2026-10-14 20:35 UTC L: it never played on a real Jiggy, so the swap now happens inside the pose's own start
- Build: your local build of main from 2026-10-14 20:35 UTC or later
- Steps:
  1. Esc > General: Back-Port: Get Jiggy animation on
  2. Collect a Jiggy (as Banjo and Kazooie)
  3. Turn it off and collect another one
- Look for: With it on, does Banjo do BK's dance (fist pumps, Kazooie pops out at the end) under Tooie's black bars, and does the game carry on normally afterwards? Is it the right dance as you remember it from BK? Does any other item (Cheato page, Jinjo, Glowbo) wrongly get the dance too? Only checked here by starting the pose without a real Jiggy.
- Status: failed 2026-10-14 (never triggered); fix waiting for L

## T52 Game Frame Rate (Original / 30 FPS / 60 FPS)
- Asked: 2026-10-13 23:40 UTC
- Build: latest Windows CI build from main
- Commit: 6231d8b, 6736f06 (scene pacing fix)
- Steps:
  1. Esc > Graphics: turn on Frame rate overlay
  2. Play somewhere busy at Game Frame Rate = Original and watch the "Game ... fps" line
  3. Switch Game Frame Rate to 30 FPS, then 60 FPS, and play the same spot
- Look for: Does the Game line now sit at 30 at Original and 30 FPS (it used to flip 28/32 because it was counted over a quarter second), and at 60 with 60 FPS? Does 60 FPS feel smoother without anything running too fast (Banjo moved at the same speed here and the title intro kept its length; story cutscenes such as Klungo, signs, the file select screen, timers, animations, enemies, music sync and minigames are untested)? Does any place hitch or go slow-motion at 30 or 60?
- Status: waiting for L

## T53 Noclip
- Asked: 2026-10-13 23:45 UTC
- Build: latest Windows CI build from main
- Commit: cb79700
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
- Commit: a9b1817, 5fd696e
- Steps:
  1. Frame rate at your usual 170 fps
  2. Open the Save Game Select screen and watch the hand waving in picture 1, and the pictures
- Look for: Does the hand's wave look smooth now? The pictures' small shake should stay quick and crisp, as before (it is drawn at the game's own rate on purpose). Anything stretched or jumping?
- Status: waiting for L

## T55 Split up anywhere
- Asked: 2026-10-14 00:05 UTC
- Build: latest Windows CI build from main
- Commit: 065b633, 22ee63c
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
- Commit: a6d5d1d
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
- Commit: 098bb74
- Steps:
  1. Load a save and stand anywhere, e.g. Spiral Mountain
  2. Esc > Sound > Music player: pick a song (Jolly's jukebox songs by name, then Track 0 to 159)
  3. Pick another one, then Level music
  4. Pick a song again and go through a door to another area
- Look for: Does the level's music fade out and the song start? Does Level music bring the area's music back? Does going to another area end the song (the row goes back to Level music)? The names come from the decomp's jukebox switch names, so tell me any that are wrong. Some tracks are short jingles: the game brings its own music back after them.
- Status: waiting for L

## T58 D-pad control scheme
- Asked: 2026-10-14 01:30 UTC
- Build: latest Windows CI build from main
- Commit: 1bbfe86
- XBLA history: report §4.60
- Steps:
  1. Esc > General > Control scheme = D-pad
  2. In a level, walk with the D-pad (try diagonals), then push the left stick while holding the D-pad
  3. Hold LB and press the D-pad: up should go into first person (C-up), left/right turn the camera
  4. Set it back to Original: the D-pad cheats (Fly anywhere, Split up anywhere) work again
- Look for: Does Banjo run at full speed with the D-pad and the stick take over when pushed? Do LB + D-pad act as the C-buttons? Headless the D-pad ran Banjo at full tilt and LB + up reached the game as C-up.
- Status: waiting for L

## T59 Speed-up key
- Asked: 2026-10-14 01:45 UTC
- Build: latest Windows CI build from main
- Commit: af32c7a
- XBLA history: report §4.21
- Steps:
  1. Esc > Cheats: Enable cheats, Speed-up on, Speed-up factor 3
  2. In a level, hold F2 (bind a pad button under Controls > Cheats if you like)
  3. Turn Speed-up toggle on and tap F2 instead
- Look for: Does the game run 3x while held, with a "Speed-up x3" note, and "Speed-up off" when you let go? Headless it ran 180 frames a second instead of 60. Cutscenes speed up too for now; tell me if you want them kept at normal speed like the XBLA version.
- Status: waiting for L

## T60 Photo mode (first part)
- Asked: 2026-10-14 02:00 UTC
- Build: latest Windows CI build from main
- Commit: ce24995
- XBLA history: report §4.82
- Steps:
  1. In a level, press F10 (or your controller's Share button; you can bind another under Controls > Hotkeys > Photo Mode)
  2. Fly around: left stick moves, right stick looks, LT (Z) down, RT (R) up (holding a move for a second goes faster). LB hides Banjo and Kazooie
  3. Press A for a screenshot, D-pad up to show the HUD, Start to run time at 1/8 and 1/4 speed
  4. D-pad down circles Banjo (both sticks turn around him, LT/RT closer and further); D-pad down again flies freely. D-pad left/right zoom out and in
  5. While in photo mode, open the menu (Esc) > QOL and try Photo filter (Sepia, Noir, Dream...), exposure, contrast, saturation, warmth, vignette and film grain; close the menu and take a screenshot
  6. Press B (or F10) to go back to the game
- Look for: Does everything stop (Banjo, enemies, water) while the camera flies freely? Is the HUD and the area name gone? Does B put you back exactly where you were? The camera stops at the ground and walls and slides along them (QOL > Photo mode camera collision turns that off). The filters show only in photo mode and in its screenshots. Not built yet: depth of field and crop.
- Status: waiting for L

## T61 Bottles' Revenge (cut two-player mode)
- Asked: 2026-10-14 01:10 UTC
- Build: latest Windows CI build from main
- Commit: accf3f7
- XBLA history: report §4.77
- Steps:
  1. Plug in two controllers. Load a save and go into any level
  2. Esc > General > Cut Content: Bottles' Revenge: On. The area reloads
  3. Devil Bottles (red, with a pitchfork) should appear and follow Banjo. Player 2 uses the second controller: R near an enemy possesses it, then attack Banjo
  4. Turn the option Off: the area reloads without him
- Look for: Does the area reload when you toggle it? Does the first controller still only move Banjo (it should no longer also drive player 2), and does the keyboard stay with Banjo? Checked headless: Devil Bottles appears at Mayahem Temple with the option on and not with it off. Not checked headless: a real second pad, and the live reload.
- Status: waiting for L

## T62 Photo mode crop and grid
- Asked: 2026-10-14 01:15 UTC
- Build: latest Windows CI build from main
- Commit: d436740
- XBLA history: report §4.82
- Steps:
  1. In a level, press F10 for photo mode, then Esc > QOL
  2. Set Photo crop to 4:5 (or 2.39:1, 1:1, 9:16...) and turn on Photo grid. Close the menu
  3. Outside the frame should be darkened, with rule-of-thirds lines inside it. Press A for a screenshot
- Look for: The saved screenshot holds only the frame (no dark sides) and no grid lines. Leaving photo mode removes the frame and grid.
- Status: waiting for L

## T63 Save states
- Asked: 2026-10-14 01:50 UTC
- Build: latest Windows CI build from main
- Commit: c433c88
- XBLA history: report §4.14
- Steps:
  1. In a level, press Insert. "State saved" shows
  2. Run around, lose some health or collect something, then press Home. "State loaded" shows and you're back where you saved
  3. Press Home a few more times in a row
  4. Go into another area and press Home: the game should take you back to the saved area, then load
- Look for: Does the music and sound carry on normally after a load? Any freeze or crash? The keys can be changed under Controls > Hotkeys. The slot is lost when the game closes.
- Status: waiting for L

## T64 Mouse and gyro aiming
- Asked: 2026-10-14 02:05 UTC
- Build: latest Windows CI build from main
- Commit: 8888075
- XBLA history: report §4.58 and §4.59
- Steps:
  1. Esc > General: set Mouse Sensitivity to about 25% (it is off at 0). Gyro Sensitivity is 25% already
  2. In a level, press C-up for first person (egg aiming)
  3. Move the mouse: the view should turn with it, left/right and up/down. With a gyro controller (Switch Pro, DualSense), tilt and turn it
  4. Fire an egg and check it goes where you look. Try QOL > "Mouse and gyro aim: invert up/down"
- Look for: Does the mouse feel right at some setting? Is gyro drift a problem when the pad is still (set Gyro Sensitivity to 0 to turn it off)? While Mouse Sensitivity is above 0 the cursor is locked to the window while you play.
- Status: waiting for L

## T65 Photo mode depth of field and tilt
- Asked: 2026-10-14 02:15 UTC
- Build: latest Windows CI build from main
- Commit: 02a1f9a, ae1d780
- Steps:
  1. Esc > QOL: set "Photo depth of field" to about 60
  2. In a level, press the Photo Mode key (F10)
  3. Point the middle of the picture at Banjo (QOL > Photo grid helps): Banjo should be sharp, the background blurred. Point it at something far away and the near things blur instead
  4. Press A for a screenshot and check it has the blur too
  5. Set QOL > "Photo tilt" to 15: the picture turns clockwise; -15 turns it the other way
- Look for: Is the blur amount right at 100? Any flicker, dark edges, or a sharp halo around Banjo against the blurred background?
- Status: waiting for L

## T66 Sharpening, contrast, saturation, vignette and film grain while playing
- Asked: 2026-10-14 02:25 UTC
- Build: latest Windows CI build from main
- Commit: c0801d2
- XBLA history: report §4.35 (sharpening, colour grading) and §4.36 (vignette, grain)
- Steps:
  1. Esc > Graphics, scroll to the new rows: Sharpening, Contrast, Colour saturation, Vignette, Film grain
  2. Set Sharpening to 60 and look at grass and rock textures: they should look crisper, without bright halos on edges
  3. Try the others; each changes the picture at once
  4. With some set, press F10 for photo mode, then leave it: the Graphics settings come back afterwards
- Look for: Is sharpening too strong at 100? Does anything look wrong on the HUD or text?
- Status: waiting for L

## T67 Ambient occlusion
- Asked: 2026-10-14 02:45 UTC
- Build: latest Windows CI build from main
- Commit: 86f3937
- XBLA history: report §4.35 (AO had band lines and a disk around Bottles' glow on XBLA)
- Steps:
  1. Esc > Graphics: set "Ambient occlusion" to 100 to see it clearly
  2. Walk around Spiral Mountain and Jinjo Village: corners, the bottom of walls and posts, and the ground around Banjo should get soft shading
  3. Check the HUD, text boxes and the pause menu are not shaded
  4. Set it back to 0 and compare. Watch the frame rate with it on
- Look for: Any lines, flicker or dark outlines around Banjo against far away scenery? Is 100 too strong or too weak? Any slowdown?
- Status: waiting for L

## T68 Fog
- Asked: 2026-10-14 02:55 UTC
- Build: latest Windows CI build from main
- Commit: 3d5776b
- XBLA history: report §4.35 (you asked for clear distance, colour and tint controls for fog)
- Steps:
  1. Esc > Graphics: set "Fog" to 60. Try "Fog start distance" and "Fog colour" (Haze, Mist, Dusk, Gloom)
  2. Look across a big area (Spiral Mountain, Mayahem Temple): far things fade into the fog colour, the sky blends in, the HUD and text stay clear
- Look for: Is the start distance range useful? Do you want other colours, or a colour picker? Does the fog look wrong anywhere (water, the sky, indoors)?
- Status: waiting for L

## T69 Toon outlines
- Asked: 2026-10-14 03:00 UTC
- Build: latest Windows CI build from main
- Commit: 4f8b8d4
- XBLA history: report §4.36
- Steps:
  1. Esc > Graphics: set "Toon outlines" to 100
  2. Banjo, enemies, posts and ledges get dark outlines where they stand in front of something further away. The HUD and text don't
- Look for: Are the lines the right thickness at your resolution? Should flat creases (inner edges) get lines too?
- Status: waiting for L

## T70 Beak Barge volume with the right stick (check only)
- Asked: 2026-10-14 03:05 UTC
- Build: latest Windows CI build from main
- Commit: baeb352
- XBLA history: report §4.66 (on XBLA the Beak Barge whoosh got quieter with the right stick held forward, not backward)
- Steps:
  1. Do a Beak Barge (Z + B on the ground) a few times while holding the right stick forward, then backward, then not at all
- Look for: Does the whoosh get quieter with the stick forward here? If yes, the N64 game does it too and it stays. If not, it was the XBLA port and nothing needs doing
- Status: waiting for L

## T71 Effects preset
- Asked: 2026-10-14 03:15 UTC
- Build: latest Windows CI build from main
- Commit: f61ac36
- XBLA history: report §4.42 (Original / Enhanced / Retro / Custom)
- Steps:
  1. Esc > Graphics: set "Effects preset" to Enhanced. SMAA, Ambient occlusion and Sharpening rows should change in the menu at once
  2. Try Retro (16-bit colour and CRT) and Original (all off)
  3. Change Sharpening by hand: the preset should go back to Custom
- Look for: Do the rows update in the menu straight away? Should Enhanced include anything else (fog, outlines)?
- Status: waiting for L

## T72 Bloom
- Asked: 2026-10-14 03:30 UTC
- Build: latest Windows CI build from main
- Commit: a364434
- XBLA history: report §4.36
- Steps:
  1. Esc > Graphics: set "Bloom" to 60
  2. Bright parts (sky, sunlit rock, glowing things) get a soft glow. The HUD and text don't
  3. Watch the frame rate with it on
- Look for: Too strong or too weak? Should more of the picture glow (a lower brightness threshold)?
- Status: waiting for L

## T73 Cutscene depth of field
- Asked: 2026-10-14 05:25 UTC
- Build: latest Windows CI build from main
- Commit: aa21380
- XBLA history: report §4.36 (letterboxed scenes only)
- Steps:
  1. Esc > Graphics: set "Cutscene depth of field" to 70
  2. Watch the title flyby and a cutscene with the black bars (Jamjars, Bottles, a boss intro)
- Look for: Is the focus on the right thing (it focuses on the nearest thing at the middle of the picture)? Text boxes and subtitles should stay sharp. Any flicker when the camera cuts?
- Status: waiting for L

## T74 Eye adaptation
- Asked: 2026-10-14 05:30 UTC
- Build: latest Windows CI build from main
- Commit: a45ff11
- XBLA history: report §4.37
- Steps:
  1. Esc > Graphics: set "Eye adaptation" to 70
  2. Walk from Spiral Mountain into a dark place (Glitter Gulch Mine, a cave) and back out
- Look for: Dark places brighten over about a second and bright ones settle. Does it pump or flicker? The HUD should stay as it is.
- Status: waiting for L

## T75 Frame rate overlay: stutter, location, renderer, extras
- Asked: 2026-10-14 05:28 UTC
- Build: latest Windows CI build from main
- Commit: 5bd3bbd
- Steps:
  1. Esc > Graphics: turn on Frame rate overlay
  2. Walk around a level for a minute, then go through a door into another area
  3. Hold the Speed-Up key with cheats on, and turn a texture pack on and off in Mods
- Look for: Does the map line change to the new area, and do Banjo's numbers change as he walks? Does the renderer line say D3D12 or Vulkan as you set it, with your monitor's refresh rate? Does the 1% low drop and the hitch count go up when the game stutters (loading an area, say)? Does the last line show Speed-up, cheats and the texture pack by name?
- Status: waiting for L

## T76 Models stretching for a moment
- Asked: 2026-10-14 05:55 UTC
- Build: latest Windows CI build from main (after the "repeated parts" interpolation fix)
- Commit: 7a025d1
- Steps:
  1. Play at your usual frame rate above Original (170)
  2. Walk around the places where you saw meshes suddenly stretch, and the Cave of Horrors where the black artifacts were
- Look for: Do models still stretch into a broken shape for a moment? Do the black artifacts still appear? If yes, where, and on which model?
- Status: waiting for L

## T77 Detailed nests and Mayahem Temple stairs (4.27)
- Asked: 2026-10-14 05:45 UTC
- Build: latest Windows CI build from main
- Commit: b2f41b9, 98be7da
- XBLA history: report §4.27
- Steps:
  1. Esc > Graphics: Always High-Detail Models On
  2. In Mayahem Temple, walk far away from the temple stairs and from some nests, then turn the camera back to look at them
  3. Turn Always High-Detail Models Off and look again from the same spot
- Look for: With it On, do the stairs and nests keep their detailed 3D look from far away (nests with twiggy rims and three eggs)? Headless check: the nests near the start of Mayahem Temple use the detailed model with it On and a plainer one with it Off; neither turns into a flat sprite. The stairs were not checked yet.
- Status: waiting for L

## T78 The two Windows builds and the three update scripts
- Asked: 2026-10-14 05:50 UTC
- Build: main, after this change
- Commit: e49f23c, 3a25fe3
- Steps:
  1. Double-click update_and_build_any_pc_2008.bat. When it ends, open Release\Any 64-bit PC (2008 and up) and start the game there
  2. Double-click update_and_build_newer_cpu_2013.bat. When it ends, open Release\Optimized for newer CPUs (2013 and up) and start the game there
  3. Double-click update_and_build.bat (builds both)
  4. Check that your saves and settings are in both new folders, and that the files in Release itself are still there
- Look for: Does each script finish with a message that names the folder? Are your save and settings in both new folders? Is the second one faster, and does it start on your PC? Anything left in Release that vanished? I could only check the scripts for typos here; none of them has been run on Windows.
- Status: waiting for L

## T79 Underwater tint
- Asked: 2026-10-14 05:44 UTC
- Build: latest Windows CI build from main
- Commit: aabde0b, ac6613b
- XBLA history: report §4.45 (your defaults: strength 0.25, haze 0.150)
- Steps:
  1. Esc > Graphics: Underwater tint and Underwater haze are on by default (25 and 15)
  2. Dive in the Spiral Mountain pool, then swim in Jolly Roger's Lagoon and Atlantis
- Look for: The 3D turns light blue with a blue haze in the distance while under water, and goes back when you surface. Underwater distortion (default 30, added later) makes the distance wobble gently: too much or too little? Does it switch on and off at the right moments (for example with the camera above the water while Banjo is under)? The HUD should stay as it is.
- Status: waiting for L

## T80 F6 effect views and F8 compare
- Asked: 2026-10-14 05:55 UTC
- Build: latest Windows CI build from main
- Commit: c5a21ee
- XBLA history: report §4.43
- Steps:
  1. Turn on a few effects in Esc > Graphics (for example Effects preset Enhanced, plus Fog and Bloom)
  2. Press F8: effects on the left half, original on the right. Press F8 again to stop.
  3. Press F6 a few times: effects alone, depth, normals, then off.
- Look for: The split line sits in the middle and the right half matches the game with the effects off. The views change on each F6 press with a toast naming them.
- Status: waiting for L

## T81 Rim light
- Asked: 2026-10-14 05:37 UTC
- Build: latest Windows CI build from main
- Commit: 38942a7
- XBLA history: report §4.36
- Steps:
  1. Esc > Graphics: set "Rim light" to 100, then try 50
  2. Walk around Spiral Mountain and a level with dark backgrounds
- Look for: A soft light along the edges of Banjo and nearby objects. Is it too strong, too thin, or does it shimmer when moving? Ground edges should not light up.
- Status: waiting for L

## T82 Heat haze
- Asked: 2026-10-14 05:57 UTC
- Build: latest Windows CI build from main
- Commit: 160c285
- XBLA history: report §4.45
- Steps:
  1. Esc > Graphics: set "Heat haze" to 50, then try 100
  2. Go to Hailfire Peaks' lava side and inside the volcano
- Look for: The air shimmers, more in the distance, while Banjo and near things stay steady. Is it too strong, or too fast? It should not show on the icy side.
- Status: waiting for L

## T83 Achievements
- Asked: 2026-10-14 06:05 UTC
- Build: latest Windows CI build from main
- Commit: 8694d99, df684cf, 009573c, 965eb06, hooks 9fdef27, list scrolling 693a667
- XBLA history: report §4.85
- Steps:
  1. Turn cheats off (Cheats tab master switch), then restart the game
  2. Load a save that has beaten Klungo once, or play until you do
  3. Open Esc > Achievements
- Look for: A pop-up "Achievement unlocked: Knocked Out Klungo (20 G)" at the top right, and the tab shows it with the date. A save that already has the progress unlocks those achievements a moment after loading. With cheats on, nothing unlocks until you restart with cheats off. All Beaten Up counts defeats by Mumbo's wand, the washing machine's Pants Attack and Daddy T-Rex, and Calamari Bonanza counts each of the four Inky octopi in Atlantis once you freeze it (Ice Egg or sonar ping) (both counted from build 9fdef27 on). Shoot Em Up! counts Clinkers (Clinker's Cavern), mines (Ordnance Storage) and Ulcers (Chompa's Belly) over any number of games, and the tab shows "N of 20"; two Ulcers popped in the same instant count as one. Treasure Hunt unlocks once you have picked up one of each: Jiggy, note, glowbo, egg, red and gold feather, treble clef, health and empty honeycomb, Jinjo and cheato page. Points Make Prizes unlocks on the Balloon Burst Jiggy, which may not match XBLA's 60 points rule.
- Status: waiting for L

## T84 Frame rate overlay: Compact, Full, F3, audio, graph
- Asked: 2026-10-14 05:54 UTC
- Build: latest Windows CI build from main
- Commit: 435fe16
- Steps:
  1. Esc > Graphics: set Frame rate overlay to Compact, then Full (it starts Off again: the setting was renamed)
  2. Close the menu and press F3 a few times while you play
  3. With Full on, play for a minute and go through a door into another area
- Look for: Does F3 step Off, Compact, Full with a notice each time? Is F3 listed under Hotkeys in the Controls tab? In Full, does the graph at the bottom fill from right to left and show a red spike when the game hitches? Does the audio line stay at 0 dropouts while the sound is clean, and count up if it crackles? Does the build line match the CI build you downloaded?
- Status: waiting for L

## T85 Photo mode panel
- Asked: 2026-10-14 06:30 UTC
- Build: latest Windows CI build from main
- Commit: d3fdb80
- XBLA history: report §4.82 (the D-pad list)
- Steps:
  1. Press F10 (or Share) for photo mode: a list appears at the top left
  2. D-pad up and down pick a row, left and right change it. Try Zoom (hold), Camera, Time, Banjo, Filter, Depth of field, Tilt, Crop
  3. Press L to hide the list, and L again to show it. Press A for a screenshot.
- Look for: Is the list easy to read and use on your controller? The screenshot should have no list in it. Note: D-pad up/down used to toggle the HUD and orbit, and L used to hide Banjo; those are rows now.
- Status: waiting for L

## T86 Hold to run (sprint)
- Asked: 2026-10-14 06:45 UTC, updated 2026-10-14 19:55 (any stick tilt runs; no B or roll link; QOL > Running)
- Build: latest Windows CI build from main
- Commit: f4a8154, 64a95d0
- Steps:
  1. Esc > Controls > Movement > Run: it starts unbound. Bind it to a spare button (for example a shoulder or back button)
  2. As Banjo-Kazooie, run with the stick fully pushed, then hold Run: he sprints at once (no roll), about half again as fast, leaning forward with a longer stride and calmer arms, easing in and out over about a third of a second (updated after your 10:48 note)
  3. Let go: he drops back to the normal run. B still rolls as before
  4. Push the stick only a little and hold Run: he runs and sprints anyway (this is the "sometimes it refuses" fix)
  5. Try it as Banjo alone (same sprint) and as Kazooie alone (her own sprint: leant in, longer, bouncier stride)
  6. Esc > QOL > Running: Off. Holding Run does nothing; turn it back On
- Look for: Does the sprint look like Banjo/Kazooie sprinting? Too much or too little lean or swing? Feet keeping up with the ground?
- Status: waiting for L

## T87 HD Shadows (player)
- Asked: 2026-10-14 06:45 UTC
- Build: latest Windows CI build from main
- Commit: aa2351d
- XBLA history: report §4.51
- Steps:
  1. Esc > Graphics: HD Shadows On
  2. Stand in a bright place and look at Banjo's shadow while he idles, runs and jumps
  3. Turn HD Shadows Off and On a few times, then try a transformation or two
- Look for: With it On, does the shadow match Banjo's full shape (Kazooie, backpack, arms) and pose? Does it switch at once? Does it ever flicker or go missing? Checked headless only.
- Status: waiting for L

## T88 Water reflections
- Asked: 2026-10-14 06:46 UTC
- Build: latest Windows CI build from main
- Commit: eeadba0
- XBLA history: report §4.45 (XBLA's reflections didn't work on your PC)
- Steps:
  1. Esc > Graphics: set "Water reflections" to 60, then 100
  2. Look at water from different heights: the Spiral Mountain pool, Jolly Roger's Lagoon, the Glitter Gulch Mine water, and any lake
  3. Press F6 until "Effect view: water": red is what counts as water, yellow is where it reflects
- Look for: Banjo and the scenery mirrored in the water, with gentle ripples. Is anything that isn't water lighting up red or yellow (shadows, glass, smoke)? Any flicker at the screen edges? Frame rate fine?
- Status: waiting for L

## T89 Vulkan is the default Graphics API
- Commit: 3516154
- Do: Close the game, move graphics.json out of the game's folder (or delete it), start the game, press F3 until the overlay is in Full mode.
- Look for: the renderer line says Vulkan. In Settings > Graphics the Graphics API row shows Vulkan, and the choices are Vulkan and D3D12 (no Auto).
- Note: your saved graphics.json has Auto, which is not migrated. Open the Graphics API row and pick Vulkan once.
- Status: waiting for L

## T90 Bounce light
- Asked: 2026-10-14 06:52 UTC
- Build: latest Windows CI build from main
- Commit: f319872
- XBLA history: report §4.35 (GI)
- Steps:
  1. Esc > Graphics: set "Bounce light" to 50, then 100
  2. Walk around somewhere colourful: Jolly Roger's Lagoon town, Mayahem Temple, a cave
- Look for: Surfaces near colourful walls and grass pick up a little of their colour and light. Is there visible speckle or shimmer, especially when moving? Frame rate fine?
- Status: waiting for L

## T91 Texture upscaling
- Asked: 2026-10-14 07:10 UTC
- Build: latest Windows CI build from main
- Commit: 36bb76a
- XBLA history: report §4.50
- Steps:
  1. Esc > Graphics: set "Texture upscaling" to 2x, then 4x, then Off, while in a level
  2. Look at grass, rock walls, signs and the level title text up close
- Look for: Textures look sharper with smoother lines and edges, and switch at once. Any texture that looks wrong (seams at tile edges, odd colours on see-through edges), any stutter when entering a new area at 4x?
- Status: waiting for L

## T92 FXAA and FXAA Extreme
- Asked: 2026-10-14 07:15 UTC
- Build: your own build from main (CI isn't running)
- Commit: 61bd0ba
- XBLA history: report §4.34
- Steps:
  1. Esc > Graphics: set "FXAA Anti-Aliasing" to FXAA, then Extreme, then Off. It changes at once.
  2. Look at slanted edges, like the warp pad's rim, fences and Banjo's outline. Try it with MSAA off too.
- Look for: Jagged stair-steps on slanted edges get smoother with FXAA, and a bit more with Extreme. Is Extreme too blurry on text and the HUD? Does it cost frame rate?
- Status: waiting for L

## T93 Graphics API restart
- Asked: 2026-10-14 07:25 UTC
- Build: your own build from main
- XBLA history: report §4.10, §4.33
- Steps:
  1. Esc > Graphics: find Graphics API (it was hidden before). It shows Vulkan.
  2. Switch it to D3D12. A "Restart now?" box appears; press Later. Switch back to Vulkan: no box this time.
  3. Switch to D3D12 again and press Restart. The game closes and opens again by itself.
  4. Check Graphics API reads D3D12 and play a little, then switch back to Vulkan and Restart.
- Look for: Does the game reopen on its own both times, without a second window or an error? Does D3D12 look and run the same as Vulkan (black or wrong colours, crashes)? I could only run Vulkan here.
- Status: waiting for L

## T94 HD Shadows (enemies and NPCs)
- Asked: 2026-10-14 07:24 UTC
- Build: latest Windows CI build from main
- Commit: 8d1f242
- XBLA history: report §4.51
- Steps:
  1. Esc > Graphics: HD Shadows On
  2. Go to Klungo in Mayahem Temple and to a few enemies (Grublins, Ugger) in bright places
  3. Turn HD Shadows Off and On a few times
- Look for: With it On, does each enemy and NPC cast a shadow shaped like its model, on the floor below it? Any shadow floating, doubled with an old blob shadow, flickering, or cut off at a screen edge? Does the frame rate stay smooth with many enemies on screen? Checked headless at Klungo only.

## T95 Water waves
- Asked: 2026-10-14 07:27 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.46 (not built on XBLA)
- Steps:
  1. Esc > Graphics: set "Water waves" to 50, then 100; try "Water wave speed" 50 and 200
  2. Look at calm water: the Spiral Mountain pool behind the waterfall, Jolly Roger's Lagoon, Cloud Cuckooland's pools
- Look for: Waves roll across the water in one main direction, the water seen through bends with them, and their slopes catch the light. Do they stay put on the water when you turn the camera (they shouldn't slide with it)? Too strong, too busy, or shimmering far away?
- Status: waiting for L

## T96 FSR 1 Upscaling
- Asked: 2026-10-14 07:45 UTC
- Build: your own build from main (CI isn't running)
- XBLA history: report §4.34
- Steps:
  1. Esc > Graphics: set Resolution to Original (or Original 2x) and Apply
  2. Set "FSR 1 Upscaling" to On, then Sharp, then Off. It changes at once.
  3. Set Resolution back to Auto afterwards; FSR then does nothing.
- Look for: With FSR the picture is smooth and clean instead of blocky or blurry; Sharp is crisper. Does the picture line up the same as with FSR Off (no shift, no cut-off edges), also in widescreen? Do the HUD and menus look unchanged?
- Status: waiting for L

## T97 Sound > Mix rate High (44 kHz)
- Asked: 2026-10-14 07:32 UTC
- Build: main after this commit (build it yourself)
- Steps:
  1. Settings > Sound > Mix rate: High
  2. Close and restart the game
  3. Play a few minutes: Jinjo Village music, a level with echo (Glitter Gulch Mine or Cloud Cuckooland), jumps, notes and jiggies
  4. Make a save state and load it
- Look for: Do music and sounds play at the same pitch and speed as Original, with a bit more clarity in the high notes? Any crackle, wrong pitch, or broken echo? Does sound still work after loading the save state?
- Status: waiting for L

## T99 Settings menu tidy-up
- Do: Open Settings (Esc). Go through General, QOL, Graphics and Cheats. In Graphics open the Resolution row. In the Warp tab (Cheats > Warp tab) hold Down on a controller. Open the Search tab and type a word (for example shadow or speed).
- Look for: section headings in each tab; Cheato codes are in Cheats again; Resolution lists 3x (720p), 4.5x (1080p), 6x (1440p) and 9x (4K); Field of View and Game Frame Rate apply as soon as you change them (Apply stays grey); the Warp list scrolls with the selection; Search shows matching options from every tab and you can change them there; each Cheato code in Cheats has a fuller description; Texture upscaling's description says it uses an xBR-style filter.
- Not done: controller scrolling was only checked with the keyboard; the Cheato descriptions were written from the game's own cheat names, so check them against what each code does.
- Status: waiting for L

## T100 Crash in play (10:33 dump) and the boot crash
- Asked: 2026-10-14 10:00 UTC
- Build: your own build from main (ac1c6ec or later)
- Steps:
  1. Start the game 5 times in a row; each start should reach the title.
  2. Play as you did around 10:33 (whatever you were doing when it crashed).
  3. Afterwards, open logs/console.log next to the exe and search for "[rt64]".
- Look for: No crash at start or in play. If console.log has an "[rt64] Unknown microcode" line, send it: it says which graphics code the game used, so the picture glitch it may cause can be fixed too.
- Status: waiting for L

## T101 Underwater and water fixes (from your 09:15 list)
- Asked: 2026-10-14 10:05 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.45, §4.46
- Steps:
  1. Graphics: Underwater tint 25, Underwater haze 15, Underwater distortion 30, Water reflections 60, Water waves 50
  2. Spiral Mountain: swim in the stream and the pool behind the waterfall; float on top, dive (B), look around in first person under water (C-up)
- Look for:
  - The blue tint, haze and distortion only when the camera is under the water, not while you float on top or the camera looks down from above. The distortion stays on the whole time you're under.
  - The haze is visible in the pool.
  - Reflections cover the whole stream and pool, including looking straight down.
  - Rings spread from Banjo as he swims or floats. The effects no longer flicker between frames, which also affected the other effects at wide aspect ratios.
- Status: waiting for L

## T102 Fine aim (from your 09:15 list)
- Asked: 2026-10-14 10:10 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.57
- Steps:
  1. Esc > QOL > Fine aim = Hold key, Fine aim speed = Medium
  2. Esc > Controls > Hotkeys: Fine Aim is R and right trigger by default. Rebind it to a button you like
  3. Load a file, press C-up for first person and turn with the left stick, with and without the Fine Aim button held
  4. Try Fine aim = Always, and the Slow and Fast speeds
- Look for: With the button held (or Always), does the view turn clearly slower (about 40% at Medium) and still smoothly? Does it go back to normal speed when you let go?
- Status: waiting for L

## T103 Gyro aim (from your 09:15 list)
- Asked: 2026-10-14 10:10 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.59
- Steps:
  1. Connect the 8BitDo Ultimate 2 by Bluetooth or its 2.4G dongle with the switch on the Switch/BT position (X mode has no gyro), firmware 1.03 or later
  2. Esc > General > Gyro Sensitivity = 25
  3. Load a file, press C-up for first person and turn and tilt the controller
  4. Open logs/console.log and find the "Controller added" line: it now says "gyro yes" or "gyro no"
- Look for: Does turning the controller left turn the view left, and tilting the front up look up, about as far as you turned it? What does the "gyro" part of the log line say?
- Status: waiting for L

## T104 Light shafts (from your 09:15 list)
- Asked: 2026-10-14 10:20 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.45
- Steps:
  1. Graphics: Light shafts 100 (Bloom 0 so it's clear what is what)
  2. Spiral Mountain outside: turn the camera slowly all the way round and tilt it up a little. The sun sits low, to one side, at the same place in the sky wherever you stand
  3. With the sun in or near the picture, stand so posts, trees or Banjo are between the camera and the sky
- Look for: Pale beams fanning out from the sun past whatever is in the way, with darker streaks behind the posts and Banjo. Nothing when you face away from the sun. The sky itself shouldn't wash out. Is 100 strong enough, or too strong?
- Status: waiting for L

## T105 Frame rate overlay: input latency
- Asked: 2026-10-14 09:45 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Turn on the overlay (F3 or Esc > Graphics) in Compact, then Full
  2. Play a minute with Framerate at Original, then at Display (or Manual at your monitor's rate)
  3. If you can, try with V-Sync or a frame cap on and off in your GPU driver
- Look for: The first line ends with "input N ms", and Full has an "Input latency" line under the frame time. Does the number go down when the frame rate goes up, and up when the game stutters? A value near 2 to 3 frame times is normal. Does it feel like it matches how responsive the game feels? It leaves out your monitor's and controller's own delay.
- Status: waiting for L

## T106 Eye adaptation (from your 09:15 list)
- Asked: 2026-10-14 10:45 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.45
- Steps:
  1. Graphics: Eye adaptation 100, everything else as you like
  2. Spiral Mountain: walk from daylight into the tunnel behind the waterfall and stand there a few seconds, then walk back out into the light
  3. Go through a few doors or level entrances
- Look for: Going in, the tunnel is darker for a moment and opens up over a few seconds. Coming out, the daylight glares for a moment and settles in about half a second. No glare after a fade or door. Out in the open with nothing changing it should look close to Off.
- Status: waiting for L

## T107 Glow around Bottles takes the effects (from your 09:15 list)
- Asked: 2026-10-14 11:00 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.45
- Steps:
  1. Go to Bottles' ghost by his house in Spiral Mountain (where your photo was taken)
  2. Graphics: Fog 50, Bloom 50; then photo mode (F10) with Depth of field 40 and a filter, as in your photo
- Note: I couldn't reach Bottles headless, so the cause (his glow is drawn in 2D between world draws) is inferred, not seen. Checked headless: effects and HUD unchanged elsewhere in Spiral Mountain, 3 clean boots.
- Look for: The glow and Bottles now get the same fog, bloom and depth of field as the scenery around them (a blurred glow when the focus is elsewhere). The HUD still gets none of it. Tell me if anything else in the world now looks wrong, as the effects are now applied after any later 3D drawing with the world's camera, not before it.
- Status: waiting for L

## T108 Heat haze (from your 09:15 list)
- Asked: 2026-10-14 11:10 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.45
- Steps:
  1. Graphics: Heat haze 50, then 100
  2. Hailfire Peaks lava side, then its train station; also try a different resolution
- Look for: The air shimmers in smooth waves that rise, starting a short way from the camera and stronger further off. No blocky or stair-step shimmer, and the waves look the same size at any resolution. Banjo and nearby edges stay steady. None on the icy side.
- Status: waiting for L


## T109 Random crash right at game start (VI thread)
- Asked: 2026-10-14 10:19 UTC
- Build: main after this commit (build it yourself)
- Steps:
  1. Start the game 10 times in a row, closing it each time once the title or file select shows
- Look for: Does it ever crash or close by itself while starting? If so, attach the newest crash_*.dmp and logs/crashes.log.

## T110 Frame rate overlay: shader compiles and game CPU time
- Asked: 2026-10-14 10:24 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Turn the overlay to Full (F3 or Esc > Graphics)
  2. Enter a level you haven't visited this session, then walk around a busy part of one
- Look for: A "Shaders compiled: N in 5 s, M this session" line under the 1% low. It should jump when you enter somewhere new and fall back to 0 in 5 s; going back to the same place should add few or none. The "Game" line now ends with "CPU X ms per frame (busy Y%)". On a normal PC expect a few ms and a low busy %; tell me if it ever goes near the frame time (33 ms at 30 fps) or 100%.
- Status: waiting for L

## T111 Toon outlines: thickness and more edges (from your 09:15 list)
- Asked: 2026-10-14 11:45 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.45
- Steps:
  1. Graphics: Toon outlines 100, then the new Toon outline thickness 1, 2, 3 and 4
  2. Spiral Mountain: look at Banjo, the cliffs and the bridge posts
- Look for: Thickness 4 is clearly heavier than before; the lines keep their weight at any resolution. Lighter lines now also run along ridges and the top edges of cliffs, not only around silhouettes. Too many lines, or too few?
- Status: waiting for L

## T112 Film grain size (from your 09:15 list)
- Asked: 2026-10-14 11:45 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.45
- Steps:
  1. Graphics: Film grain 50, at your usual resolution
- Look for: Grain you can actually see: soft clumps about two pixels across at 1080p (bigger at higher resolutions), strongest in the mid tones.
- Status: waiting for L

## T113 Fog measured from Banjo (from your 09:15 list)
- Asked: 2026-10-14 11:45 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.45
- Steps:
  1. Graphics: Fog 60
  2. Stand still in Spiral Mountain and zoom the camera in and out, and swing it round
- Look for: How fogged things are stays the same as the camera moves; it only changes as Banjo moves. Things right by Banjo stay clear even with the camera far back.
- Status: waiting for L

## T114 "Only" debug views for the effects (from your 09:15 list)
- Asked: 2026-10-14 11:45 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.45
- Steps:
  1. Turn on the effects you want to look at (or none)
  2. Press F6 repeatedly (Shift+F6 goes back): after the four old views come "Only: ambient occlusion", "Only: bounce light", ... "Only: depth of field"
  3. Press F8 in any of them to split the picture with the original
- Look for: Each "Only" view shows the game with just that one effect, at your setting, or at half strength if it is off. The toast names the view.
- Status: waiting for L

## T115 Effect performance and bounce light (from your 09:15 list)
- Asked: 2026-10-14 11:45 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.45
- Steps:
  1. Frame rate overlay on. Graphics: Ambient occlusion 50, Bounce light 100, Light shafts 100, Rim light 50
  2. Jolly Roger's Lagoon town and Spiral Mountain; compare the frame time with each one on and off (or use F6 "Only" views)
- Look for: Headless (CPU renderer, so only the proportions count) the extra cost dropped by about 80% for light shafts, 40% for bounce light, 25% for ambient occlusion, 15% for rim light. Bounce light is stronger now: colourful walls and floors tint what is next to them, dark corners take on the colour around them. No speckle or shimmer?
- Status: waiting for L

## T116 Bloom rework (from your 09:15 list)
- Asked: 2026-10-14 12:05 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.45
- Steps:
  1. Graphics: Bloom 50, then 100
  2. Spiral Mountain in daylight (sky, clouds, waterfall), Hailfire Peaks lava side, Mayahem Temple
- Look for: A tight glow right around bright things plus a wide soft one, stronger than before at the same number. It eases in, so bright textures don't flicker between glowing and not. Strongly coloured things (pure red or blue) glow less than white. Too much at 100?
- Status: waiting for L


## T117 Achievements list scrolls with Down (from your 10:48 list)
- Asked: 2026-10-14 11:10 UTC
- Build: your local build of main from 2026-10-14 11:10 UTC or later
- Steps:
  1. Esc > Achievements
  2. Press Down on the controller (or the arrow key) until the last achievement
- Look for: Does a highlight move from one achievement to the next, and does the list scroll so the highlighted one stays on screen?
- Status: waiting for L

## T118 Depth of field while playing (from your 09:15 list)
- Asked: 2026-10-14 12:20 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.45
- Steps:
  1. Graphics: the new Depth of field 50, then 100 (Cutscene depth of field is separate and unchanged)
  2. Spiral Mountain: run around, zoom the camera in and out, then C-up for first person
- Look for: Banjo stays sharp and the far cliffs and anything close to the camera blur, more the further they are from him. In first person the middle of the picture is in focus instead. Cutscenes still use the cutscene setting.
- Status: waiting for L

## T119 Underwater look stays on while swimming fast (from your 10:48 list)
- Asked: 2026-10-14 12:35 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.45
- Steps:
  1. Graphics: Underwater tint 25, Underwater haze 15, Underwater distortion 30 (distortion now sits right under haze)
  2. A deep stretch of water where the camera follows Banjo under (Jolly Roger's Lagoon, the lake outside Atlantis): dive, then swim fast (tap A), turn, roll, and come back up
- Look for: The tint, haze and wobble stay on the whole time the camera is under the water, however Banjo swims, and go when it comes up. Note: in the small Spiral Mountain pool the game keeps the camera above the surface even when Banjo is at the bottom, so there is rightly no tint there.
- Status: waiting for L


## T120 Extras stop before the game's drawing memory is full
- Asked: 2026-10-14 11:25 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Graphics: HD Shadows On, Extended Draw Distance On
  2. Play Mayahem Temple and Witchyworld, turning the camera around
- Look for: No torn geometry, exploding models or crash. Far objects or extra shadows may now be left out in very busy views, as the game's own drawing comes first. If something still breaks, send the crashes.log or console lines starting with "[gfx]".

## T122 More game memory
- Asked: 2026-10-14 11:20 UTC
- Build: latest Windows build from main
- Steps:
  1. General > Developer: More game memory is on (the default). Start the game and play a few areas, including a busy one (Witchyworld, Grunty Industries).
  2. Switch it off, restart the game, and play the same areas.
- Look for: no crashes, slowdowns or missing models with it on, and the game plays as before with it off. Save states (if you use them) still load.
- Status: waiting for L


## T121 Water reflections stay on every frame
- Asked: 2026-10-14 11:35 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Graphics: Water reflections 100, Water waves on
  2. Spiral Mountain: walk into the stream by the tunnel and the pool below the cliff, turn the camera slowly
- Look for: Reflections and ripples hold steady instead of flickering on and off. Some frames drew the sky separately, and the effects ran once for the sky (without water) and again for the world; now they run once.
- Status: waiting for L

## T122 Interpolation rename, Game Frame Rate 120 FPS and Unlocked (from your 10:48 list)
- Asked: 2026-10-14 11:35 UTC
- Build: your local build of main
- Commit: 59eca7a
- Steps:
  1. Esc > Graphics, "Frame rate and overlay": Interpolation (was Framerate) now sits right under Game Frame Rate, with Off (was Original), Display and Manual. Your old choice should still be selected.
  2. Turn on the Frame rate overlay (F3), set Interpolation to Off, Game Frame Rate to 120 FPS (Experimental), and play a minute in Spiral Mountain and Mayahem Temple: run, jump, swim, watch the music and any cutscene
  3. Do the same with Unlocked (Experimental), then with Interpolation on Display
  4. Switch back to Original while playing
- Look for: Does the overlay's "Game" line reach about 120 with 120 FPS, and go higher with Unlocked (up to 240)? Does Banjo move at his normal speed, and do music and sound effects play at normal pace and pitch (headless the amount of sound made was the same in every mode)? Does anything move too fast (enemies, animations, timers, water, particles)? Do cutscenes and the intro keep their length? Does switching modes while playing glitch the picture or sound? If your PC can't hold 120, 120 FPS goes slow-motion (like 60 FPS does on a slow PC); Unlocked should not.
- Status: waiting for L

## T123 HD Shadows: crashes, vanishing objects, bright patches
- Asked: 2026-10-14 11:45 UTC
- Build: latest Windows CI build from main
- Commit: d92750a
- XBLA history: report §4.51 (L's 09:15 list: "HD Shadows often breaks and objects suddenly disappear, also it brightens the image")
- Steps:
  1. Esc > Graphics: HD Shadows On
  2. Play a few minutes in Mayahem Temple and Spiral Mountain, near Klungo, nests, honeycombs and enemies
  3. Turn HD Shadows Off and On a few times
- Look for: Any crash, object vanishing (honeycombs, eggs, enemies), or the image getting brighter in patches? Enemy shadows should be dark and shaped like the enemy. Checked headless: crashed within a minute before the fix, ran 40 minutes after it in Spiral Mountain, and 2 minutes in Mayahem Temple.

## T124 Toon outline thickness goes to 200
- Asked: 2026-10-14 11:40 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Graphics: Toon outlines 100, then Toon outline thickness 25, 100, 200
- Look for: 25 is the old thin line, 100 the old thickest, 200 a bold cartoon line twice that. Thin things like posts keep their line attached. A saved thickness of 1 to 4 carries over as 25 to 100.
- Status: waiting for L


## T125 Water waves react to Banjo; effects measure distance right
- Asked: 2026-10-14 12:20 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Graphics: Water waves 50 or more, Water reflections 100
  2. Spiral Mountain: jump into the stream by the tunnel, swim up and down it, stop, then wade in the shallow edge
  3. Also look over Fog, Depth of field and Ambient occlusion in a couple of places
- Look for: Rings spread from where Banjo is (not behind him), a big splash ring when he jumps in, a V-shaped wake with a little foam behind him while he swims, and a small ring bobbing round him when he stops. No rings when he walks on dry land. The effects were reading the depth about twice too far, so fog may now start a little further out and focus sits right on Banjo.
- Status: waiting for L

## T126 Exploding models and black flashes (frame read race)
- Asked: 2026-10-14 14:11 UTC
- Build: main @ e895a40
- Steps:
  1. Build main at e895a40 or later
  2. Load a save that starts in Jinjo Village, and play a while in Jinjo Village and Mayahem Temple with your usual settings (HD Shadows on)
  3. Warp to Cloud Cuckooland from the menu and spin the camera for a minute
- Look for: Do models still explode into giant shapes, and does the screen still flash black?
- Status: waiting for L

## T127 HD Shadows spikes at high refresh
- Asked: 2026-10-14 16:10 UTC
- Build: main @ next commit
- Steps:
  1. Graphics: HD Shadows on, Interpolation Display (your 175 Hz)
  2. Spiral Mountain: walk and stand around on the sloped grass by the molehills, where the shadows are long
  3. Also turn the camera so you see Banjo's shadow from the side
- Look for: The shadow keeps Banjo's shape and moves smoothly, with no long pointed spikes or broken triangles. The overlay's 'Interpolation on' line now counts the shadows (was 0 shadows).

## T130 Torn triangles and black patches for a frame (camera split)
- Asked: 2026-10-14 16:32 UTC
- Build: main @ (next commit)
- Steps:
  1. Build main at the commit below
  2. Warp to Cloud Cuckooland (or play Spiral Mountain) with your usual settings
  3. Spin the camera around Banjo for a minute, with the free camera and with the normal camera; try Interpolation Off and Display
  4. Also look at the places where you saw it before
- Look for: Do triangles still fly across the screen or do black patches and holes still show for a frame or two? Checked headless: the renderer split the camera wrongly 31 times in a 2-minute spin before the fix and 0 times after.
- Status: waiting for L

## T128 Underwater tint and haze turn things light blue
- Asked: 2026-10-14 16:15 UTC
- Build: main @ 7b163d1
- Steps:
  1. Graphics: Underwater tint 25, Underwater haze 15 (then try 5 and 100 for each)
  2. Spiral Mountain: dive deep into the moat (where your screenshot was) and swim along the bottom
  3. Also try a deep lake where the camera follows Banjo under (Jolly Roger's Lagoon)
- Look for: Under water the 3D world turns a lighter blue and far things fade into a light blue haze, getting stronger all the way to 100; it goes when Banjo comes up
- Status: waiting for L

## T129 Underwater distortion, tint and haze on D3D12 (no more coloured blob grid)
- Asked: 2026-10-14 16:29 UTC
- Build: main @ 076ce62 (also covers T128)
- Steps:
  1. Graphics: keep D3D12, Underwater tint 25, haze 15, distortion 30
  2. Spiral Mountain: dive where your blob screenshot was (Banjo at 1178, -377, 471) and in the moat
  3. Also turn on Water reflections and look at a pool from above
- Look for: The 3D world shows through, light blue and gently wobbling, with no grid of coloured blobs and no flat dark blue screen; reflections show the scenery
- Status: waiting for L

## T131 Skip cutscenes with Start instead of X
- Asked: 2026-10-14 16:45 UTC
- Build: main @ 8c66e22
- Steps:
  1. QOL: keep "Skip boss intros" on; turn "Skip other cutscenes" on too
  2. Warp to Chilly Willy (or any boss) and press Start during the intro
  3. Talk to any NPC and press Start during the conversation
  4. Press X during a cutscene, and Start during normal play
- Look for: Start shows "Skipping cutscene" and fast-forwards to the end without opening the pause menu; X no longer skips; Start in normal play still opens the pause menu
- Status: waiting for L

## T132 Game Frame Rate 120 / Unlocked go above 60 (retest of T122)
- Asked: 2026-10-14 16:45 UTC
- Build: your local build of main
- Commit: 23d8c23
- Steps:
  1. Graphics: Frame rate overlay on (F3), Interpolation Off, Game Frame Rate 120 FPS (Experimental); play a minute in Spiral Mountain
  2. Same with Unlocked (Experimental)
  3. Listen to the music and sound effects in both
- Look for: Does the overlay's "Game ... fps" line now reach about 120 (and above with Unlocked) instead of staying at 60? Is it still slow motion at 120? Do music and sound play smoothly, without gaps or crackles (headless, Unlocked had some gaps while the software renderer kept the CPU busy)? A 60 Hz monitor still only shows 60 pictures a second.
- Status: waiting for L

## T133 Bounce light without dotted noise
- Asked: 2026-10-14 17:11 UTC
- Build: main @ ada3c63
- Steps:
  1. Graphics: Bounce light 100, your usual resolution
  2. Look at Banjo up close and at a honeycomb against grass
- Look for: No fine grid of dots over Banjo's fur, skin or the background. Colours from nearby walls and floors still tint what is next to them.
- Status: waiting for L

## T134 Torn frames: renderer wait and interpolation id clashes
- Asked: 2026-10-14 17:15 UTC
- Build: main @ f709884
- Steps:
  1. Pull, build, play 10 minutes in Spiral Mountain and Cloud Cuckooland, spin the camera a lot, at Original FPS and at 60
  2. Do it once with Interpolation Off and once with your usual settings
  3. After any tear, hold F12 for a burst (let go after the tear) and look in the log for a line starting with [dl]
- Look for: Whether the 1-2 frame tears and black patches still happen, how often compared with before, and whether any [dl] line appears in the log
- Status: waiting for L

## T135 Water and underwater effects drawn once
- Asked: 2026-10-14 17:28 UTC
- Build: main @ bd142ac
- Steps:
  1. Graphics: Water reflections 50, Water waves 50, Underwater tint 25, haze 15, distortion 30
  2. Swim in the Spiral Mountain moat on top, then dive
  3. Watch the water from above and below
- Look for: The water and the underwater look show once, with no doubled or ghosted water and no tint that builds up; frame rate a little higher
- Status: waiting for L

## T136 Cutscene skip: title left alone, Start stops it, sound muted
- Asked: 2026-10-14 20:05 UTC
- Build: main @ a47965a (also covers T131)
- Steps:
  1. QOL: "Skip boss intros" and "Skip other cutscenes" on
  2. Start the game and press Start during the logos / title flight
  3. Warp to Chilly Willy, press Start during the intro, then Start again a second later
  4. Press Start once more and let the skip run to the fight
- Look for: Step 2 goes to the file select and does not pick a save by itself; in step 3 the second Start shows "Skip stopped" and the scene plays on at normal speed; while skipping there is silence (no sped-up sound) and the sound comes back when it ends
- Status: waiting for L

## T137 Ambient occlusion fits Banjo; water waves stay put
- Asked: 2026-10-14 19:59 UTC
- Build: main @ 46097d8
- Steps:
  1. Graphics: Ambient occlusion 50, Water waves 50, Water reflections 50
  2. Spiral Mountain: walk Banjo around, then swim and inch forward in the moat
  3. Watch the shading round Banjo and the wave pattern as the camera moves
- Look for: The shading hugs Banjo and the scenery and doesn't cut out now and then; the waves stay fixed on the water instead of the whole pattern sliding when you move a little
- Status: waiting for L

## T138 Unlocked / 120 FPS: sound keeps working, no sound crash
- Asked: 2026-10-14 20:30 UTC
- Build: your local build of main
- Commit: 1256297
- Steps:
  1. Graphics: Game Frame Rate Unlocked (Experimental), Interpolation Off; play for 10 minutes or more in a few levels (talk to someone, enter a level, a cutscene)
  2. Same for 5 minutes with 120 FPS (Experimental)
- Look for: Does the sound keep playing the whole time, and does the game no longer crash with "n_aspMain unhandled jump"? If it still breaks, send the session log and say roughly how many minutes in. Headless, Unlocked ran 3 minutes without a crash both before and after this fix, so I could not reproduce your crash here.
- Status: waiting for L

## T139 Noclip goes through walls; Tiptoe under Movement
- Asked: 2026-10-14 20:25 UTC
- Build: main after this commit
- Steps:
  1. Esc > Cheats: Enable cheats, Noclip = On, load a save
  2. Walk into a wall, a cliff and a closed door; hold LT (Z) to sink through the floor and RT (R) to rise
  3. Esc > Controls: look for Tiptoe under Movement (next to Run), not Hotkeys
- Look for: Banjo walks straight through walls and scenery instead of stopping at them. Cause was that the game keeps its own "last valid position" for collision, which Noclip did not write, so walls pulled Banjo back. Headless in Mumbo's Skull, Banjo walked through the back wall (before: stopped at it). Not tried in water, doors with locked rooms or with Kazooie split up.

## T140 Effect debug view: each filter on its own
- Asked: 2026-10-14 20:40 UTC
- Build: main @ 6776787
- Steps:
  1. Graphics, at the bottom: Debug > Effect debug view. Pick "All effects off" first, to see the plain picture
  2. Pick each "Only: ..." view in turn (or close the menu and press F6 to step, Shift+F6 back; a notice names each view)
  3. In a view that looks wrong, press F8 to split it: the effect on the left, the original on the right
  4. Screenshot (F12) each broken one and say which view it is
- Look for: Each view shows only that one effect (at your setting, or a default strength if it's off), and every other effect is gone. Report what looks wrong in each
- Status: waiting for L

## T141 Talking heads and blinking at 30 a second above 30 FPS
- Asked: 2026-10-14 21:30 UTC
- Build: your local build of main
- Commits: 4c7c6f1 (talking heads), d398d4c (blinking)
- Steps:
  1. Graphics: Game Frame Rate Unlocked (Experimental), then 60 FPS
  2. Talk to a character so the talking-head box opens; watch the mouth and the blinking in the portrait
  3. Watch a character's eyes in the world for a while (Bottles, Jamjars, Mumbo, villagers)
- Look for: Do the portrait mouths and blinks now move at the same speed as with Original? Do characters in the world blink as often and as fast as with Original? If one character still blinks too fast, tell me which one: it uses its own blink code.
- Status: waiting for L
