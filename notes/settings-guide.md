# Settings guide

Every option in the game's own menus that this port adds or changes, in plain
words. Names and descriptions are the ones shown in the menu. Defaults are the
values the code starts with. Open settings with **Esc**, or **Back** / **Select**
on a controller.

## General

- **Back up saves**: copies your save file into the `save_backups` folder
  whenever it changes. Default: on.
- **Discord status**: shows the level you are playing in your Discord status
  while Discord is running. Default: on.
- **Back-Port: Old Banjo sounds**: Banjo-Kazooie's jump sounds instead of
  Banjo-Tooie's. Default: off.
- **Back-Port: Get Jiggy animation**: when Banjo collects a Jiggy he does
  Banjo-Kazooie's jiggy dance (fist pumps, Kazooie pops out at the end) instead
  of Tooie's pose. Tooie's jingle, camera and Jiggy count stay. The dance is
  still in Tooie's own data, unused. Default: off.
- **Save backups to keep**: how many of the newest save backups to keep.
  Range 1 to 100. Default: 10.
- **Timer save**: saves the game by itself after 5, 10, 30, 60 or 120 minutes of
  play in a level. Pauses, menus and cutscenes don't count, and it never saves
  during them. A "Game saved" notice shows. Default: Off.

The General tab also has a rumble strength option. It comes from the menu
framework, not from this port's code, so it is not described here.

## QOL

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
- **Running**: On or Off. On lets the Run key (Controls tab, Movement; not bound
  by default) run faster as Banjo-Kazooie, Banjo or Kazooie. Default: On.
- **Canary Mary races**: Fair, Easy or Original. In the original she speeds up
  past her normal pace whenever you lead; Fair removes that catch-up, Easy is
  Fair with her pace at 85%. She still slows down when you fall behind.
  Default: Fair.
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

## Controls: Movement

- **Tiptoe**: hold it to tiptoe at any left stick tilt. Default: Left stick
  click on a controller, nothing on the keyboard. Rebind it in the Controls tab
  under Movement. The game still sees every button as usual.
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
- **HD Shadows**: shadows are shaped like the full model on screen, with its
  pose. The player's uses the on-screen model instead of the game's simpler
  shadow model (works in every transformation); enemies and NPCs, which have
  no shadow on N64, get one too (up to 12 per frame, straight down onto the
  floor). Applies at once. Default: off.

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
  below (frame rate, frame time and input latency). **Full** shows:
  - the frame rate and frame time on screen (averaged over the last quarter
    second)
  - the worst frame time in that quarter second
  - input latency, averaged over the last 2 seconds, with the worst: the time
    from the game reading your controller to the first frame on screen that
    was made from that read. Your monitor's own delay and the controller's
    are not included.
  - the GPU time per game frame
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
  F6 steps to the next view (Shift+F6 back) with a notice naming it; F8 splits
  the picture, the effect on the left and the original on the right (SMAA,
  FXAA, FSR and the Retro filters aren't split). Brightness and N64 3-point
  filtering stay at their settings. Starts Off each launch. Default: Off.
- **Effect compare** (Graphics > Debug): the same split picture as F8, as a
  switch. Starts Off each launch.
- **Interpolation check** (Graphics > Debug): tints a model red for a moment
  when its blend between game frames looks wrong, and logs it. F7 switches it
  too. Shows nothing at Original. Starts Off each launch.
- **Interpolation blend mode** (Graphics > Debug): a list of the five ways
  in-between frames are blended (normal, no tags, tags with vertex blending,
  camera untagged, models snap). Starts on normal each launch. The Blend Mode
  key steps through them; it isn't bound by default (F8 is Effect Compare).

## Controls: Hotkeys and Debug

Every function key is bound in the Controls tab and can be changed there:
Hide HUD (F1), Speed-Up (F2, under Cheats), Frame Rate Overlay (F3), Photo Mode
(F10), Screenshot (F12) under Hotkeys; Effect Debug View (F6, Shift steps
back), Interpolation Check (F7), Effect Compare (F8), Blend Mode (unbound) and
Warp Again (F9, needs the Warp tab on) under Debug.

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
  in (missing animations or data). It is a drop-down. Off puts you back as
  Banjo-Kazooie (and reloads the area) if you had picked a form. Default: Off;
  the row goes back to Off when Enable cheats is turned off.
- **Warp tab**: shows the Warp tab in the menu, with a list of places to warp
  to. F9 repeats the last warp. Default: off.
- **Stop 'n' Swop items**: marks the blue and pink Stop 'n' Swop mystery eggs as
  collected, without a Banjo-Kazooie save. Only these two flags are set; the
  yellow egg and the other items are not covered yet.
- **Unlock all moves**: every move counts as learned. Your save file is not
  changed.
