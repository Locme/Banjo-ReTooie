<!-- Newest first: add new tests at the top, above the highest number. -->

## T299 Controller in the menu: leaving search, and RB to Mods
- Asked: 2026-10-16 19:37 UTC
- Build: main @ next Windows build
- Steps:
  1. Open the menu with a controller
  2. Go up to Search settings, press right and type something
  3. Press your menu Back button (X by default), then go back into the search box and press your menu Close button (Select by default)
  4. From inside any page press RB until you reach Mods
- Look for: Back leaves the search box for the sidebar, the close button closes the menu from the search box, and RB walks the tabs all the way to Mods (it skips the search page)
- Status: waiting for L

## T298 Start-up stutter with saved shaders
- Asked: 2026-10-16 19:25 UTC
- Build: latest Windows build from main
- Steps:
  1. Start the game the way you usually do (keep cache\shader_list.bin, do not delete it)
  2. Play the first minute
- Look for: The stutter at the start should be gone or much shorter. If it still stutters, open logs\console.log and tell me the number on the line '[shaders] compiling N shaders from the shader list'
- Status: waiting for L

## T297 Kazooie feathers (feather cards, like the NeuralVFX shader)
- Asked: 2026-10-16 19:17 UTC
- Build: main
- Steps:
  1. Graphics > Character Shaders: set Kazooie feathers to 100
  2. Look at Kazooie up close in a cutscene (the poker game in Jolly's works) and while playing
  3. Try Kazooie feather size between 50 and 200
- Look for: Her head, neck and body are covered in lots of little overlapping feathers that stick out a little, each in her own colour there, with her beak, legs and backpack left smooth. Does it look good? Also say if the frame rate drops.
- Status: waiting for L

## T296 Smash Banjo v11: slow blink
- Asked: 2026-10-16 UTC
- Build: main, plus mods/Smash Banjo v11.zip from project files (take v10 and its unpacked folder out of the mods folder)
- Steps:
  1. With Smash Banjo on, stand still close to his face and wait for him to blink; compare with vanilla Banjo
- Look for: The lid slides down over his eyes and back up over several frames, like vanilla's, instead of snapping shut for one frame. Smash has only an open eye and a shut lid, so the shut lid is turned up about the eyeballs for the in-between steps the game asks for. Checked with a posed render of all 8 eye steps (screens/smash-banjo/v11-blink-steps.png in project files) and the game loads v11 headless; the blink itself was not caught headless. Everything else as v10 (T295).
- Status: waiting for L

## T295 Smash Banjo v10: straps stretch with the backpack
- Asked: 2026-10-16 UTC
- Build: main, plus mods/Smash Banjo v10.zip from project files (take v9 and its unpacked folder out of the mods folder)
- Steps:
  1. With Smash Banjo on, jump, then beak barge (B while crouched: hold Z, press B), watching the straps from the side and front
  2. Stand still and look at the straps on his shoulders
- Look for: The straps stay on his shoulders and stretch to the pack wherever it swings (v9 moved the whole strap with the pack, off his shoulders). Everything else as v9 (T272). Checked headless: the beak barge, where the pack lifts over his head, shows the straps stretching from his shoulders up to it (screens/smash-banjo/v10.png and v10-poses.png in project files). Also fixed: his chest was drawn twice.
- Status: waiting for L

## T293 Sound freezes at Uncapped (texture sweep, Mumbo's Skull)
- Asked: 2026-10-16 15:01 UTC
- Build: main
- Steps:
  1. Graphics > Game Frame Rate: Uncapped; Sound > Mix rate: High
  2. Run the texture sweep again over the maps that froze before
  3. Play a while in Witchyworld and go in and out of Mumbo's Skull a few times
- Look for: No freeze and no hang dump. A [sound] line in console.log saying the game waited for a free sound handle or freed a sound slot is fine: it means the fix stepped in. The sweep should go past Tower of Tragedy (0x15F) without entering it. Any stuck-sound effect still playing after leaving a map?
- Status: waiting for L

## T292 Kazooie painted feathers
- Asked: 2026-10-16 14:59 UTC
- Build: main
- Steps:
  1. Graphics > Character Shaders: turn on Kazooie feather sheen, Kazooie painted feathers and Kazooie iridescence
  2. Look at Kazooie up close in a cutscene (the poker game in Jolly's works) and in Spiral Mountain
  3. Move Kazooie painted feathers strength between 5 and 200
- Look for: Soft scalloped outlines of overlapping feathers on her head, neck and body, with no raised bumps; the sheen still shows between them. Her beak, legs and backpack stay smooth. The outlines fade when she is far away instead of flickering. Does it look good?
- Status: dropped; L had the Kazooie shaders removed (2026-10-16)

## T291 Mumbo's Hut Recreation v5: doorway shadows and stronger shading
- Asked: 2026-10-16 14:50 UTC
- Build: main (pull and build), plus the v5 mod zip
- Steps:
  1. Put mods/Mumbo's Hut Recreation v5.zip (project files) in the game's mods folder in place of v4
  2. Load a file, then Warp > Glitter Gulch Mine > Outside Mumbo's Skull, look at the hut, then walk in
  3. Warp > Cloud Cuckooland > Skull on the cloud (straight ahead) and walk up to the hut
- Look for: The inside of the arch and the wall round the door darken into the doorway. The hut has a clear lit side (left) and shaded side (right), with darker teeth and underside. Checked headless with the models (screens/mumbos-hut/v5.png in project files): both huts drawn, GGM's door entered. Asked 2026-10-16 14:41 UTC (L: "Add shadows going Into the doorway, also add shading to the hut")
- Status: waiting for L

## T290 Banjo X Alt v7: no clipping at the straps, fur shader
- Asked: 2026-10-16 14:32 UTC
- Build: main, plus mods/Banjo X Alt v7.zip from project files (take v6 out of the mods folder)
- Steps:
  1. Put "Banjo X Alt v7.zip" in the mods folder as it is and turn on "Banjo X (alt rig)" (Smash Banjo and Banjo X off)
  2. Walk, jump, flap, crouch, Talon Trot, roll and attack, looking at his shoulders and face up close
  3. Turn on Banjo fur in Graphics > Character Shaders and look again
- Look for: The fur on his neck and shoulders no longer pokes through the backpack straps, and the straps no longer show across his cheeks when he lowers his head (that fur was on the neck and shoulder bones while the straps stay on the chest; it now rides with the straps). With fur on, his brown fur grows fur; his face, hands, feet, shorts, belt, backpack and Kazooie stay smooth. Checked headless on all those moves and in photo mode with fur on and off (screenshot screens/banjo-x/alt-v7.png).
- Status: waiting for L

## T289 Kazooie feathers look like feathers, not fur
- Asked: 2026-10-16 14:27 UTC
- Build: main
- Steps:
  1. Graphics > Character Shaders: turn on Kazooie's feather sheen, feathery edges and iridescence at 100
  2. Look at Kazooie up close in Spiral Mountain and in a cutscene (the poker game in Jolly's works)
- Look for: Her head, neck and wings show small rounded feathers overlapping each other, not fuzz like Banjo's fur. Her beak, legs and backpack stay smooth. The sheen is a clear glossy highlight that moves as she turns.
- Status: replaced by T292 (painted feathers)

## T287 3D grass: Chunk size and Pixel size sliders
- Asked: 2026-10-16 13:27 UTC
- Build: main
- Steps:
  1. Graphics > Grass: set 3D grass above 0, turn on Chunky 3D grass and Pixelated 3D grass
  2. Move Chunk size (100 to 400) and Pixel size (0.25 to 8) in Spiral Mountain
- Look for: Chunk size makes the chunky blades bigger and further apart; Pixel size makes the pixel blocks bigger. Both apply live, alone or together.
- Status: waiting for L

## T286 3D grass: Chunky and Pixelated toggles, own Grass section
- Asked: 2026-10-16 12:56 UTC
- Build: main
- Steps:
  1. Graphics: find the new Grass section (after Colour grading) and set 3D grass above 0
  2. Turn on Chunky 3D grass, then Pixelated 3D grass, then both, in Spiral Mountain
  3. Walk through the grass and move the camera
- Look for: Chunky: fewer, wider single-colour triangle blades. Pixelated: blades drawn in blocky N64-sized pixels with jagged edges. Both apply live. Say if the blocks shimmer badly while moving or if any blade edges look cut off.
- Status: waiting for L

## T281 Textures: mip bias 0 (RT64 sampler)
- Asked: 2026-10-16 12:34 UTC
- Build: main
- Steps:
  1. Run this build
  2. Look at ground and walls a few metres away and far off, e.g. Spiral Mountain grass and paths
  3. Move the camera slowly
- Look for: Distant textures may be a touch softer than before and should shimmer less. Say if anything looks blurrier than you want.
- Status: waiting for L

## T279 3D grass thickness and random length sliders
- Asked: 2026-10-16 12:22 UTC
- Build: main @ next push
- Steps:
  1. Graphics > 3D grass thickness: try 100, 200 and 400
  2. Graphics > 3D grass random length: try 0, 40 and 100
- Look for: Do the blades get wider with thickness, and do lengths go from all alike (0) to anything from very short to full length (100)? Both should change live.
- Status: waiting for L

## T278 3D grass: stays put while you move, grows over grass laid on dirt, not on the yellow road or stone
- Asked: 2026-10-16 12:22 UTC
- Build: main @ next push
- Steps:
  1. Turn on 3D grass (any amount) with your usual pack and settings
  2. In Spiral Mountain walk from Banjo's house past Bottles and the tree stumps, turning the camera now and then
  3. Look at the yellow road and the stone and brick walls with moss
  4. Stand still for a few seconds, then walk again
- Look for: Do blades stay where they are as you move (thinning out far away without jumping about)? Is there grass round the tree stumps and by Bottles, where it used to vanish? Is the yellow road and the stone free of blades?
## T277 Mumbo's Hut Recreation v4: shading
- Asked: 2026-10-16 12:25 UTC
- Build: main (pull and build), plus the v4 mod zip
- Steps:
  1. Put mods/Mumbo's Hut Recreation v4.zip (project files) in the game's mods folder in place of v3
  2. Load a file, then Warp > Glitter Gulch Mine > Outside Mumbo's Skull and look at the hut
  3. Warp > Cloud Cuckooland > Skull on the cloud (straight ahead) and walk up to the hut
- Look for: Does the hut look like it belongs now? It has its own shading: the top of the skull lit, the underside, the teeth's lower halves and the areas under the overhang darker, on top of the level's colour from v2. Checked headless with the models (screens/mumbos-hut/v4.png in project files). Asked 2026-10-16 12:14 UTC (L: "It still looks like it does not belong, maybe it's missing shading?")
- Status: replaced by T291 (v5)

## T274 Quit prompt takes the mouse after Alt+F4
- Asked: 2026-10-16 12:12 UTC
- Build: main (pull and build)
- Steps:
  1. Play with the controller for a moment, then press Alt+F4
  2. Without moving the mouse far, click Quit
  3. Try again after using the keyboard instead of the controller
- Look for: Quit closes the game every time. Before, a click used the menu's last known mouse position, which went stale after controller or key presses (small mouse moves weren't passed on), so it could miss the button. Checked headless with the keyboard: a click after a small move quits; the controller case needs your test.
- Status: waiting for L

## T273 Sun shadows fill the whole screen (sun shadow map)
- Asked: 2026-10-16 12:04 UTC
- Build: 86429fb
- Steps:
  1. Graphics > Photo Filters: Sun shadows on (60 or more)
  2. Stand in Spiral Mountain or a level with cliffs and trees, turn the camera so the sun is up and to one side
  3. Look at the edges of the screen towards the sun
- Look for: Shadows from cliffs, trees and walls outside the picture now reach into it, so the left and top are no longer left bright. Shadow edges stay steady when the camera moves, with no dark speckles on lit ground. Fences and leaves still use the old screen-space shadows.
- Status: waiting for L

## T272 Smash Banjo v9: fur, straps, wings, blink and wobble
- Asked: 2026-10-16 UTC
- Build: main, plus mods/Smash Banjo v9.zip from project files (take v8 and its unpacked folder out of the mods folder)
- Steps:
  1. Photo Filters on, Banjo fur at 100, Smash Banjo on. Look at his belt, feet and the soles of his feet close up
  2. Jump, then roll (B while running), watching the backpack, the straps and Kazooie's wings
  3. Stand still and watch him blink next to vanilla Banjo, then look closely at his face, the buckles on the back of the pack and Kazooie's eyes
- Look for: Step 1, no fur strands over the belt, on the feet or under them; the shins keep their fur. Step 2, the straps move with the pack, so it no longer floats free of them (the pack itself swings as vanilla's does; in the moves where it lifts over his head the straps go up with it). Kazooie's wings are 80% of v8's size and no longer make a wide ring in the roll. Step 3, one blink that closes and opens like vanilla's (v8 closed, opened and closed again in every blink). The face is smoother and the buckles and Kazooie's eyes don't flicker: vertex positions are now stored 8 times finer, as in Banjo X Alt v4. Checked headless in Mayahem Temple: belt and feet clear of fur, roll and jump posed from the game's own matrices (screens/smash-banjo/v9.png and v9-roll-before-after.png in project files). Not checked headless: the flicker itself, so please confirm it is gone. Replaces T261's zip.
- Status: waiting for L

## T270 Settings in the pause menu (empty page for now)
- Asked: 2026-10-16 11:36 UTC
- Build: main (pull and build)
- Steps:
  1. Load a file and press Start in any world
  2. Move down to SETTINGS (under View Totals) with the stick and press A
  3. On the SETTINGS page press B, then open it again and press Start
  4. If your file has Jinjos and items, check the menu scrolls to Save and Quit
- Look for: SETTINGS shows in the Start menu with the Jiggy icon. A opens a page titled SETTINGS with only the B button on it. B goes back to the menu with SETTINGS still picked; Start closes the menu. With Objects and Items and Jinjos showing the menu has six rows and scrolls down to Save and Quit. Nothing else in the pause menu changes. Checked headless in Mayahem Temple (4-row and 6-row menus; screens/pause-settings/ in project files).
- Status: waiting for L

## T269 Deep snow with footprints (Icy Side)
- Asked: 2026-10-16
- Build: main (pull and build)
- Steps:
  1. Graphics: turn on the Shaders switch, then Deep snow (Snow height starts at 100)
  2. Go to Hailfire Peaks' Icy Side and walk, run and stand still on the snow
  3. Move Snow height to 300 and to 25 while you play
  4. Jump around, then wait about a minute where you walked
- Look for: The snow ground is a soft layer with gentle drifts, about ankle deep at 100 and knee deep at 300, changing as you drag the slider. Banjo leaves a furrow with left and right footprints and the snow banks up either side; standing still prints both feet. Jumps leave no marks in the air. After about 6 seconds prints start to fill back in and are gone within about a minute. The ice should stay flat; tell me if any pale ice gets snow on it. Banjo's round shadow may be hidden under deep snow. On a slow GPU this costs more frame time than most effects. Checked headless on Icy Side.
- Status: waiting for L

## T267 No 'invalid UI context' error when quitting
- Asked: 2026-10-16 11:20 UTC
- Build: main (pull and build)
- Steps:
  1. Graphics > Performance > Frame rate overlay: Compact
  2. Play a little so a notice shows (for example toggle the overlay with F3)
  3. Quit the game from the menu, and once more by closing the window
- Look for: The game closes with no 'Fatal error in mod - Attempted to open an invalid UI context' box. The overlay, notices and the photo mode panel now stop touching the menu once it is torn down. Quit from the menu checked headless with the overlay on (no box); the error itself was a race, so it may not have shown every time before.
- Status: waiting for L

## T266 Controller: Back while typing in search, menu reopens where you left it
- Asked: 2026-10-16 11:20 UTC
- Build: main (pull and build)
- Steps:
  1. With the controller, pick Search settings, press A and type a few letters
  2. Press Back (the Back button the menu's footer shows)
  3. Go to Sound in the sidebar, close the menu with Select, open it again and press Left or Down
- Look for: Step 2: you leave the text box and land on the Search settings box in the sidebar, and the stick moves through the sidebar again. Step 3: the menu opens on Sound with the cursor there, not at the top of the list. Checked headless with the keyboard for step 3; step 2 needs a controller (the cause was Back trying to focus the hidden Search tab).
- Status: waiting for L

## T265 Default and Shaders labels
- Asked: 2026-10-16 11:20 UTC
- Build: main (pull and build)
- Steps:
  1. Graphics > Aspect Ratio and HUD Placement
  2. Graphics > the Shaders section
- Look for: Aspect Ratio reads 4:3, Default, Letterbox 16:9. HUD Placement reads Original, 16:9, Default. Your saved choice is unchanged. The Lighting, Water, Fog (Experimental) switch and its heading now say Shaders and still show and hide the same effects.
- Status: waiting for L

## T264 QOL tab: Fast Forward Cutscenes, Photo Filter, Balancing
- Asked: 2026-10-16 11:20 UTC
- Build: main (pull and build)
- Steps:
  1. Open QOL
  2. Look at Speed and skipping, Photo Filter and Balancing
  3. Turn Hide Settings off under Photo Filter
  4. With Fast Forward Cutscenes on, press Start in a boss intro and in a normal cutscene
- Look for: Speed and skipping ends with Fast Forward Cutscenes, then Press Start Anytime In Intro. The old two skip switches are one; if you had Skip other cutscenes on, the new one is on. Photo Filter is its own section with Hide Settings on; turning it off shows the photo filter, exposure, crop and the rest. Canary Mary races sits alone under Balancing at the bottom. Start fast-forwards both cutscene kinds. Checked headless (menu only).
- Status: waiting for L

## T263 Video memory no longer fills up (frame rate drops to 2 fps)
- Asked: 2026-10-16 10:57 UTC
- Build: main @ next push
- Steps:
  1. Play with your usual settings (Uncapped, 3440x1417, MSAA 2x, BT Reloaded) for 10 minutes or more
  2. Resize the window once or twice
  3. Send console.log
- Look for: Does the frame rate stay up? In the log, does 'descriptor sets' in the [vram] objects line stay about the same instead of climbing by thousands each line? An '[effects] replaced ...' line every 10 s is fine; it shows how often the effects pass switches pictures.
- Status: waiting for L

## T262 Performance tab under Graphics
- Asked: 2026-10-16 10:35 UTC
- Build: main (pull and build)
- Steps:
  1. Open the menu: Performance sits under Graphics
  2. Change Game Frame Rate, Interpolation or the Frame rate overlay there
  3. Restart the game and look again
  4. Type 'overlay' in Search settings
- Look for: Performance holds Game Frame Rate, Interpolation (with its Manual rate), Low Input Latency, Frame Read-Back and Frame rate overlay; Graphics no longer shows them. Changes apply at once and stay after a restart (they still save in graphics.json, so your old values carry over). Search labels them 'Performance tab'. Checked headless: the overlay change saved.
- Status: waiting for L

## T261 Smash Banjo v8: no fur out of his mouth
- Asked: 2026-10-16 UTC
- Build: main, plus mods/Smash Banjo v8.zip from project files (take v7 and its unpacked folder out of the mods folder)
- Steps:
  1. Graphics > Photo Filters on, Banjo fur at 100, with Smash Banjo on
  2. Look at Banjo's face close up from the side while he idles, talks and attacks, so his mouth opens
- Look for: No brown strands round his teeth, gums or lips. The mouth used the same texture as his body, so the fur shader grew strands on its brown texels; v8 gives the mouth its own copy of the texture with those texels slightly less saturated, which the fur test skips. The mouth looks the same otherwise, and the body fur is unchanged. Checked headless in Mayahem Temple at fur 100 against v7 (screens/smash-banjo/v8.png in project files). Replaces T256's zip; T256's checks still apply.
- Status: waiting for L

## T259 Mumbo's Hut Recreation v3: doorway fits the arch
- Asked: 2026-10-16 10:25 UTC
- Build: main (pull and build), plus the v3 mod zip
- Steps:
  1. Put mods/Mumbo's Hut Recreation v3.zip (project files) in the game's mods folder in place of v2
  2. Load a file, then Warp > Cloud Cuckooland > Skull on the cloud (straight ahead) and walk up to the hut
  3. Warp > Glitter Gulch Mine > Outside Mumbo's Skull, look at the door, then walk in
- Look for: The original doorway now fills the hut's arch, with no sky or gaps round the black in either world. Lighting as in v2, and the door still takes you inside. Checked headless with the zip (screens/mumbos-hut/v3.png in project files): both doorways fill the arch, GGM's door entered. Asked 2026-10-16 10:21 UTC (L: "In your second image, you can see the black doorway does not fit, make it fit")
- Status: replaced by T277 (v4)

## T257 Banjo fur on model mods
- Asked: 2026-10-16 10:30 UTC
- Build: main (next Windows build), plus mods/Smash Banjo v7.zip
- Steps:
  1. Graphics > Photo Filters on, Banjo fur at 100, with Smash Banjo on
  2. Look at Banjo close up, then flap so Kazooie comes out of the backpack
  3. Turn Smash Banjo off and look again
- Look for: Smash Banjo's fur gets the fur shells (arms, body, legs), but his muzzle, shorts, backpack and Kazooie don't. Before this, the fur shader looked for Kazooie at fixed places in the vanilla model, so with a model mod it picked the wrong parts. It now reads where Kazooie's parts are from the model itself, so this should also work for Banjo X and other player model mods. Vanilla Banjo looks the same as before. Checked headless in Mayahem Temple with Smash Banjo and vanilla.
- Status: waiting for L

## T256 Smash Banjo v7: animation clean-up
- Asked: 2026-10-16 10:30 UTC
- Build: main, plus mods/Smash Banjo v7.zip from project files (take v1 to v6 and their unpacked folders out of the mods folder)
- Steps:
  1. Load a save with Smash Banjo on and walk, run, jump, flap flip, roll and beak barge, watching his legs from the side
  2. Flap (A twice) and watch Kazooie's tail feathers under the backpack
- Look for: Step 1, no long brown spikes stretching out behind his legs or feet (v6 had them whenever he walked: a fur card at the ankles was tied to both feet). Step 2, the tail feathers stay in one piece when they fan out. Everything else is as v6. Checked headless with the game's own bone matrices from 101 frames of walking, jumping, flapping, backflip, roll, beak barge and talon trot: no spikes left. The backpack lifting up behind his head in some moves is what vanilla does too. Screenshot: screens/smash-banjo/v7.png. If you still see an animation problem, say which move.
- Status: waiting for L

## T255 Mumbo's Hut Recreation v2: original doorway and level lighting
- Asked: 2026-10-16 10:06 UTC (L: "The black part of the entrance need to be similar to vanilla entrence, so replace that entrance with vanilla. The lighting of the hut does not look right, like it does not belong")
- Build: main (pull and build), plus the mod: replace v1 with `mods/Mumbo's Hut Recreation v2.zip` (project files) in the game's mods folder and turn it on in the Mods menu
- Steps:
  1. Load a file, then Warp > Glitter Gulch Mine > Outside Mumbo's Skull and look at the hut, then walk into its door
  2. Warp > Cloud Cuckooland > Skull on the cloud (straight ahead) and walk up to the hut
- Look for: The flat black door is gone; the doorway is now the original skull's short tunnel, shading from the entrance to black inside. The hut takes its light from the level the way the old skull did: warm orange and darker in the mine, plain daylight on the cloud, instead of the same flat light everywhere. The door still takes you inside. Checked headless with the zip ([v2.png](screens/mumbos-hut/v2.png) in project files): both huts drawn, GGM's door entered.
- Status: replaced by T259 (v3)

## T254 Red square on Bottles' ghost talking head: texture pack or not
- Asked: 2026-10-16 10:14 UTC
- Build: main @ a211d4f
- Steps:
  1. Turn the texture pack off
  2. Load a file and go to Spiral Mountain, to the rock by Bottles' ghost near Banjo's house
  3. Talk to him and speed through his dialogue
- Look for: Does the red square still show on his talking head with the pack off? (No red square showed headless without a pack.)
- Status: waiting for L

## T253 Video memory log: what is using it
- Asked: 2026-10-16 10:25 UTC
- Build: main (pull and build)
- Steps:
  1. Play as when the frame rate dropped (4K or 3440x1440, MSAA 2x, your mods on) until VRAM has climbed a few GB, then send console.log
- Look for: each [vram] line (one every 512 MB of change) is now followed by "[vram] using it: N MB in textures and buffers; biggest: ..." naming the biggest groups of the game's textures and buffers with their size and count (for example "Render Target Color 3440x1440 MSAA 2x 760 MB (12)"), and "[vram] changed since the last line: ..." naming what grew or shrank. If VRAM climbs and these stay level, the memory is held by the graphics driver, not by textures or buffers; the "objects alive" line (T244) then says which kind of object. Checked headless: the lines print with names (render targets, scene effects, SMAA, texture cache) and follow the effects as they are made.
- Status: waiting for L

## T252 Boss rush starts from the switch (fix for T219)
- Asked: 2026-10-16 (L: "It never entered a arena")
- Build: main (pull and build)
- Commit: "Boss rush: the General switch starts the rush (T252)" on main
- Steps:
  1. Load a file, then General > Boss rush = On and close the menu
- Look for: a "Boss rush 1/13: Klungo" notice straight away and Klungo's fight starts (the file is saved first). Then carry on with T219's steps. Cause: the switch's change handler read the old value, so turning it on was taken as turning it off. Checked headless with a file open, through the switch's own change handler.
- Status: waiting for L

## T251 Day and night: raindrops on the screen
- Asked: 2026-10-16 UTC
- Build: main (pull and build)
- Commit: "Day and night: wet ground, rain rings on water, raindrops on screen" on main
- Steps:
  1. Weather: Rain, Raindrops on Screen on; look around, then point the camera up at the sky
- Look for: A few drops land on the screen, hold, then run down leaving a thin trail; each bends what is behind it with a dark rim and a glint. Many more when looking up. None under water or in snow. Off removes them.

## T250 Day and night: rain rings on water
- Asked: 2026-10-16 UTC
- Build: main (pull and build)
- Commit: "Day and night: wet ground, rain rings on water, raindrops on screen" on main
- Steps:
  1. Weather: Storm, swim in the Spiral Mountain moat or stand by the water in Jolly Roger's Lagoon
- Look for: Rings spreading over the water where the rain lands, two at a time, wider and slower than the splashes on the ground. Checked headless: [rain-rings-and-drops.png](screens/day-night/rain-rings-and-drops.png).

## T249 Day and night: wet ground in the rain
- Asked: 2026-10-16 UTC
- Build: main (pull and build)
- Commit: "Day and night: wet ground, rain rings on water, raindrops on screen" on main
- Steps:
  1. Graphics > Day and Night: Morning, Weather: Rain, Wet Ground on; stand in Spiral Mountain for 15 s or so, then set Weather: Clear
- Look for: The ground darkens and level ground turns shiny in patches, reflecting what is round it, more so looking along it. Banjo and water stay as they are. After the rain stops it dries over about a minute and a half. Wet Ground off keeps it dry. Checked headless: [wet-ground-rain.png](screens/day-night/wet-ground-rain.png).

## T248 Viva Mumbo Jumbo v2: polish pass
- Asked: 2026-10-16 10:00 UTC
- Build: main, plus mods/Viva Mumbo Jumbo v2.zip from project files (replaces v1; delete v1.zip and its unpacked "Viva Mumbo Jumbo v1" folder from the mods folder first)
- Steps:
  1. Put "Viva Mumbo Jumbo v2.zip" in the mods folder as it is and turn on "Viva Mumbo Jumbo" in the Mods menu
  2. Go into Mayahem Temple's Mumbo's Skull, look at Mumbo sitting and talk to him
  3. Play as Mumbo: walk, run, jump, crouch, swim, use the wand, and look at his feet and skirt close up (photo mode helps)
- Look for: closed, solid toes and feet (v1 showed orange holes on top of the toes), legs lit like the rest of the body instead of dark and flat, a skirt with its full colours, no eyelids showing through the eyes, thumbs and feet joined cleanly while moving, no orange rim round the soles, and the soles orange underneath when he sits with his feet up. The cause of the toes: the source model's legs, feet, skirt and feathers were built inside out, and the game hides the inside of a model. Checked headless with the zip, playing as Mumbo in Spiral Mountain and sitting in Mayahem Temple's skull: [v2.png](screens/viva-mumbo/v2.png). Swimming and the wand spell were not tried.
- Status: replaced by T260 (v3)

## T247 Uncapped and 240 FPS: the screen shows the frames the game makes
- Asked: 2026-10-16 10:10 UTC
- Build: your local build of main
- Steps:
  1. Your usual settings; Game Frame Rate Uncapped in Spiral Mountain, then 240, then 175
  2. Look at the overlay's screen frame rate next to the game frame rate
- Look for: In Uncapped and 240 the screen frame rate now follows the game frame rate, past your screen's refresh rate where your PC can, instead of dropping to 100. Above the refresh rate the picture is shown without vsync, so it may tear: tell me if that bothers you. 175 should still be 175 with no tearing. Send the session log if the screen still sits near 100.
- Status: waiting for L

## T246 Banjo X Alt v4: eyes, lids, smile and ears like the reference
- Asked: 2026-10-16 10:05 UTC
- Build: main, plus mods/Banjo X Alt v4.zip from project files (take v1 to v3 out of the mods folder)
- Steps:
  1. Put "Banjo X Alt v4.zip" in the mods folder as it is and turn on "Banjo X (alt rig)" (Smash Banjo and Banjo X off)
  2. Open photo mode and look at Banjo's face close up, then walk, jump, flap and roll
- Look for: half-closed eyelids over blue eyes, the brows, the smile and the peach insides of the ears, as in L's reference picture; the straps stay on the shoulders. The game stores model points as whole numbers, which crushed this model's fine detail (eyelids sank into the eyes, the smile closed). v4 stores the points 8 times larger and scales them back down while drawing. Checked headless in photo mode with the zip (screenshot screens/banjo-x/alt-v4.png: v4 close up, and v4 with HD textures).
- Status: failed (L, 2026-10-16: eyes mid-blink, strap bugged); replaced by T268

## T245 3D grass on edges
- Asked: 2026-10-16 09:45 UTC
- Build: main (pull and build)
- Steps:
  1. Graphics > 3D grass to 100; Graphics > 3D grass on edges is on by default
  2. Mayahem Temple's entrance courtyard: look at the foot of the stone walls, then turn 3D grass on edges off and on
  3. Spiral Mountain and Isle o' Hags: look along cliff tops and banks with a grass fringe
- Look for: blades also grow on the green parts of textures that are only partly grass (a grass fringe along a cliff top or bank, grass at the foot of a rock or wall), leaning out from slopes and walls; off goes back to grass only on the grass textures. 36 such textures, picked by eye from the same texture dump as T227; tell me any spot that should have edge grass and doesn't. Checked headless in Mayahem Temple: on, blades rise along the foot of the courtyard walls; off, none (screens/n64-3d-grass-edges-mayahem-on-off.png). Also fixed: Graphics > Sun shadow on Banjo was shown with the softness slider's name since 3860208.

## T244 What is filling video memory (log)
- Asked: 2026-10-16 09:25 UTC
- Build: main (pull and build)
- Steps:
  1. Same setup as your console.log of 09:41 (3440x1440, MSAA 2x, Vulkan, Spiral Mountain)
  2. Play until the 1 fps comes (or for 2 minutes), then send console.log
- Look for: every [vram] line now has a second line, "[vram] objects alive (made since the last line): ...", counting every kind of graphics object the game has alive, busiest first. Whatever climbs along with VRAM is what fills it (for example "descriptor sets 5000 (+2400)" would point at descriptor sets). This replaces the setting-by-setting check in T234 if you'd rather just send one log. Checked headless: the line prints, and nothing climbs here in Spiral Mountain with 3D grass on (the software renderer doesn't show your leak).
- Status: waiting for L

## T243 Day and night: mist settings and mist round water
- Asked: 2026-10-16 UTC
- Build: main (pull and build)
- Commit: "Day and night: more times of day, mist settings and mist round water" on main
- Steps:
  1. Graphics > Day and Night: Morning, Mist 50 (then 100 and 0), Mist Time: Mornings; go to Jolly Roger's Lagoon and Spiral Mountain's water
  2. Mist Time: Mornings and Nights, Day and Night: Night
- Look for: Mist lies in drifting patches over low ground rather than as an even haze, and is thickest just over water, also close to Banjo. Higher Mist is thicker; 0 turns it off. With Mornings and Nights, a cool grey mist hangs over the water at night too; Always keeps it all day. Checked headless: [mist-over-water-on-off.png](screens/day-night/mist-over-water-on-off.png) (moat, Mist 50 on and 0), [night-mist-over-low-ground.png](screens/day-night/night-mist-over-low-ground.png) (Night, Mist 100, Mornings and Nights).

## T242 Day and night: more times of day
- Asked: 2026-10-16 UTC
- Build: main (pull and build)
- Commit: "Day and night: more times of day, mist settings and mist round water" on main
- Steps:
  1. Graphics > Day and Night: try Dawn, Morning, Noon, Afternoon, Golden Hour, Sunset, Dusk and Night in Spiral Mountain
  2. Set it back to Cycle
- Look for: Ten choices in order of the day. Dawn is pink and dim with the sun just up, Noon is plain daylight with the sun high, Afternoon is daylight turning faintly warm, Golden Hour is warm and bright, Dusk is violet with the first stars. Cycle still runs the clock. A saved Morning, Sunset or Night setting is kept. Checked headless: [dawn-noon-dusk.png](screens/day-night/dawn-noon-dusk.png).

## T241 Mumbo's Hut Recreation mod (with Warp tab spots)
- Asked: 2026-10-16 09:55 UTC (L: "Add this replacement (with warp support) Mumbo Hut Recreation")
- Build: main (pull and build), plus the mod: put `mods/Mumbo's Hut Recreation v1.zip` (project files) in the game's mods folder and turn it on in the Mods menu
- Steps:
  1. Load a file, turn on Cheats > Enable cheats and Warp tab, then Warp > Glitter Gulch Mine > Outside Mumbo's Skull
  2. Walk into the hut's door
  3. Warp > Cloud Cuckooland > Skull on the cloud (straight ahead), and walk up to the skull on the cloud ahead
  4. Turn the mod off in the Mods menu while standing by either hut
- Look for: Step 1, Banjo stands at the door of Mumbo's hut from Banjo-Kazooie (cracked brown skull, window eyes, sandstone teeth, red feathers, bent metal pole), sharp HD textures, about the size of the old skull. Step 2, it takes you into Mumbo's Skull as before. Step 3, the same hut stands on the cloud platform. Step 4, the old skull comes back at once. Only these two skulls are separate models in the game; the other worlds build Mumbo's Skull into the level, so they stay as they were. The old skull's collision is kept, so Banjo may bump into its shape where the new hut is narrower. Checked headless with the mod zip ([v1.png](screens/mumbos-hut/v1.png) in project files): both huts drawn with HD textures and GGM's door entered; CCL's skull door didn't open headless with no file loaded, same as the original.
- Status: replaced by T255 (v2)

## T240 Banjo fur, reworked: fine fur, Banjo only
- Asked: 2026-10-16 09:45 UTC
- Build: main (pull and build)
- Steps:
  1. Graphics > Lighting, Water, Fog (Experimental) on, then set Banjo fur to 100 (Banjo fur length 100)
  2. Spiral Mountain: stand still until Kazooie pops out of the backpack, then walk, jump and roll with the camera close behind and beside Banjo
  3. Try Banjo fur length 50 and 200
- Look for: Step 2, Banjo's brown fur (head, arms, back, legs) looks like a fine fuzzy coat with thin hairs along his outline, not cones or pyramids, and the hairs stay on him as he moves. Kazooie has no fur, out of the backpack or in it; the yellow shorts, belt, backpack, gloves and boots stay smooth. Step 3, shorter or longer fur. Replaces T205's look. Checked headless in Spiral Mountain (screenshots/banjo-fur/rework-off-on.png in project files); not checked on Windows (D3D12), with the split-up Banjo, or with Smash Banjo.
- Status: waiting for L

## T239 Freeze on a map change (your hang of 2026-10-16 10:41)
- Asked: 2026-10-16 UTC
- Build: main (pull and build)
- Steps:
  1. Play as you were (boss rush on, cutscene skips on, mix rate High), changing maps a lot
  2. If the picture ever stops for about 2 seconds on a map change and then carries on, send console.log: it has a `[sound]` line saying which sound was stuck
  3. If it still freezes for good, wait 15 seconds, then send hangs.log and the newest hang_*.dmp
- Look for: no more permanent freezes when entering a new area. What happened: before every map change the game waits for each sound it is stopping to be let go by the sound engine. In your hang one sound (slot 6, the same slot each time) was never let go, so the game waited forever while the screen kept showing the last picture. Now the game waits at most 2 seconds, then frees that sound itself, as it would have, and logs it. Hang dumps now also hold the game's memory, so if it happens again I can see which sound it was and why it stuck. Checked headless: with that sound held on purpose (TOOIE_TEST_STUCK_SOUND=1), the warp to Jinjo Village paused 2 seconds, logged slot 6 and carried on, and two more warps after it worked. Why the sound engine did not let go is not found yet.
- Status: waiting for L

## T238 Uncapped past 100 FPS, 240 FPS no longer slower than 175
- Asked: 2026-10-16 09:20 UTC
- Build: your local build of main
- Steps:
  1. Same settings as when Uncapped gave about 100 FPS (keep your Interpolation setting)
  2. Game Frame Rate Uncapped: note the frame rate in Spiral Mountain
  3. Then 175 and 240 FPS in the same spot
- Look for: Uncapped is at least as high as 175 now. 240 shows 240 where your PC can, and where it can't, the game still runs at normal speed (before, it went into slow motion). Send the session log if Uncapped is still lower than 175.
- Status: waiting for L

## T237 Sun shadows steady, lined up and covering the whole scene
- Asked: 2026-10-16 08:52 UTC
- Build: 96ebfe6
- Steps:
  1. Sun shadows on, HD shadows on
  2. Run around Spiral Mountain in daylight, turning the camera
  3. Watch Banjo's shadow and the left and top of the picture
- Look for: Shadows stay on (no sudden stop), sit on Banjo rather than beside him, cover the whole picture, and Banjo's shadow no longer flickers
- Status: waiting for L

## T236 Interpolation Debug section in Controls
- Asked: 2026-10-16 08:50 UTC
- Build: main (pull and build)
- Steps:
  1. Controls tab, scroll to the bottom
  2. If you had keys bound to Pick Model or Tag Model, press them in game
- Look for: Debug now holds Effect Debug View, Effect Compare and Warp Again. Below it, Interpolation Debug holds Interpolation Check, Blend Mode, Pick Model, Tag Model, Save Tags, Unsave Tag and Model Effects. Bindings you already had still work. Checked headless.
- Status: waiting for L

## T235 Settings pages use less space
- Asked: 2026-10-16 08:50 UTC
- Build: main (pull and build)
- Steps:
  1. Open the menu and go to Graphics
  2. Scroll to the bottom (Frame rate overlay)
  3. Look at General and QOL too
- Look for: each option's name sits on the left with its switch, choices or slider on the same line, so about twice as many fit on screen. The description strip at the bottom is shorter but still fits three lines. Graphics has no Apply box and no doubled "Frame rate overlay" row with a white outline. Changes on Graphics still apply and stay after a restart. Checked headless.
- Status: waiting for L

## T234 Video memory filling up (the 1 fps spells): which setting
- Asked: 2026-10-16 08:50 UTC
- Build: your current build (423f2b2 or newer)
- Steps:
  1. Same setup as your console.log of 09:41 (3440x1440, MSAA 2x, Vulkan, Spiral Mountain), with the frame overlay on
  2. Stand on the meadow for 1 minute with Graphics > 3D grass at 0, then send console.log
  3. Do it again with 3D grass at 100, then with Banjo's fur off, then with Water set to Original, and send console.log after each (or one log, writing down the times you switched)
- Look for: the [vram] lines (every 2 seconds). In your log VRAM climbs by about 520 MB every 2 seconds, from 0.8 GB to 16 GB in a minute, while "ours" (the renderer's own memory) stays at about 1.5 GB. Once VRAM passes 100% the card has to swap, which is the 1 fps; when the driver frees it, the speed comes back. Shaders were not compiling then (0 in 5 s). The setting whose 0 or Off stops the climb is the leak.

## T233 Day and night: rain splashes on the ground
- Asked: 2026-10-16 08:30 UTC
- Build: main (pull and build)
- Commit: "Day and night: fireflies reworked, rain splashes on the ground" on main
- Steps:
  1. Graphics > Day and Night: Morning, Weather: Rain or Storm, in Spiral Mountain; look at the grass and paths near Banjo
- Look for: Small rings splashing up and spreading on level ground all round, with a bright drop where each lands, more in a storm, fading out further off. None on walls or slopes, none in snow. Checked headless: [rain-splashes.png](screens/day-night/rain-splashes.png).
- Status: waiting for L

## T232 Day and night: fireflies like Ocarina of Time's forest
- Asked: 2026-10-16 08:30 UTC
- Build: main (pull and build)
- Commit: "Day and night: fireflies reworked, rain splashes on the ground" on main
- Steps:
  1. Graphics > Day and Night: Night, Fireflies on, in Jinjo Village or Spiral Mountain; stand and look round
- Look for: More fireflies than before, small warm white-yellow points in a wide soft glow (no longer green), floating slowly in loops at all heights from the grass up into the trees, each glowing up and fading away over a few seconds instead of blinking. Closer to Ocarina of Time's forest at night? Too many, too few, too bright? Checked headless: [fireflies-oot-style.png](screens/day-night/fireflies-oot-style.png) (caught during the level's opening wipe; a still shows few at a time).
- Status: waiting for L

## T231 Photo mode: Home button is the default controller button
- Asked: 2026-10-16 08:29 UTC
- Build: main (pull and build)
- Steps:
  1. Start a new game, or load a save, and go to any level
  2. Press the Home button on your controller (not the Share or Misc button)
  3. Check that photo mode opens, the list appears, and the game freezes
  4. Press B to go back to the game
- Look for: Step 2, photo mode opens from Home with no remapping. Step 4, B returns to the game. Keyboard F10 still opens photo mode. Nothing else changes when you press Home. Checked in the code only: no other default uses the Home button.
- Status: waiting for L

## T230 Modern water: no blocky facets, no on/off, game's own waterfalls
- Asked: 2026-10-16 08:20 UTC
- Build: main (pull and build)
- Steps:
  1. Graphics > Water: Modern
  2. In Spiral Mountain, look at the pool round the tree trunk from the grass above it (your blocky water shot)
  3. Walk from the grass down towards the pool under the two waterfalls (your 10-03-10 burst)
  4. Look at the waterfalls themselves and the trunk-pool stream
- Look for: Step 2, the water is smooth with no triangle-shaped bright and dark blocks. Step 3, the water stays Modern (reflections) the whole way instead of switching from the game's grey water to Modern partway. Step 4, the falls are the game's own smooth-scrolling ones, a little thicker and brighter, with foam where they land; no stutter and no white wedges. Checked headless in Spiral Mountain and Mumbo's Skull.
- Status: waiting for L

## T229 Settings menu: controller moves the same way in every tab, Search ready to type
- Asked: 2026-10-16 08:30 UTC
- Build: main (pull and build)
- Steps:
  1. Open the settings menu with a controller and move up and down the sidebar
  2. Press A or Right on a tab, then move around the page with the stick, including Left and Right on switches and at the top and bottom of the list
  3. Press B, then L and R both from the sidebar and from inside a page
  4. Go up to Search settings at the top of the sidebar and press A (or click it with the mouse), then type
- Look for: Step 1, each tab opens as soon as you reach it. Step 2, the cursor goes to the page's first option; the stick never jumps out to the sidebar or to the quit button, and stops at the ends of the list. Step 3, B goes back to the sidebar on the open tab; L and R switch tabs and keep you where you were (in the sidebar, or in the new page's first option). Step 4, the cursor is already in the search box and typing works at once. Checked headless with the arrow keys and the mouse; B and a real controller not checked.
- Status: waiting for L

## T228 Banjo X Alt v3: face fixed
- Asked: 2026-10-16 08:40 UTC
- Build: main, plus mods/Banjo X Alt v3.zip from project files (take v1 and v2 out of the mods folder)
- Steps:
  1. Put "Banjo X Alt v3.zip" in the mods folder as it is and turn on "Banjo X (alt rig)" (Smash Banjo and Banjo X off)
  2. Stand still until Banjo looks around, then walk, jump, flap and talk to someone
- Look for: Banjo's face stays like L's reference picture: the muzzle, teeth, brows and tongue now move with his head, so the snout no longer stretches and the mouth no longer hangs open when he turns his head (in v2 they followed his chest). Still full detail, as v2. Checked headless in Spiral Mountain through the idle look-around (screenshot screens/banjo-x/alt-v3.png: v2 left, v3 right, v3 front below).
- Status: failed (L, 2026-10-16: still broken); replaced by T246

## T227 3D grass in patches, only on grass textures
- Asked: 2026-10-16 08:25 UTC
- Build: main (pull and build)
- Steps:
  1. Graphics > 3D grass to 100, then go to Spiral Mountain's meadow by Klungo, then Isle o' Hags, Mayahem Temple and Terrydactyland
  2. Move Graphics > 3D grass patches from 50 (the default) down to 5 and up to 100
  3. Look for green ground that isn't grass (moss, mossy stone, leaves, slime) and check no blades grow there
  4. Squares check: do the move that left the white square behind Banjo, and talk fast to the fish by the rock, first with 3D grass at 0, then at 100
- Look for: the grass grows in patches here and there, with shorter grass round their edges; lower numbers give fewer, smaller patches and 100 covers all the grass. Blades only on grass textures (50 of them, picked by eye from a dump of 22 outdoor levels); if a grassy area now has none, tell me where and I'll add its texture. For the squares: do they still come with 3D grass at 0? The grass only redraws the level's own opaque ground, never sprites or effects, and the squares in your burst look like the black squares from in-between frames (T38). Checked headless in Spiral Mountain at patches 20, 50 and 60.
- Status: waiting for L

## T226 Viva Mumbo Jumbo model mod (Viva Mumbo Jumbo v1)
- Asked: 2026-10-16 08:15 UTC
- Build: main, plus mods/Viva Mumbo Jumbo v1.zip from project files
- Steps:
  1. Put "Viva Mumbo Jumbo v1.zip" in the mods folder as it is (no unzipping). In the Mods menu, turn on "Viva Mumbo Jumbo"; it is its own entry, separate from the Banjo and honeycomb model mods, and works with any of them on
  2. Go into any Mumbo's Skull (Mayahem Temple's is closest) and talk to Mumbo
  3. Play as Mumbo (pay him a Glowbo, or Cheats > Transformation > Mumbo): walk, jump, swim, use the wand, stand still
  4. Turn the mod off and enter a new area
- Look for: Mumbo is the Viva Pinata Mumbo (yellow skull with dark markings, red feathers, pink body with the rainbow chest, patterned skirt) with the HD textures, moving with the game's own animations: his jaw moves when he talks, the three feathers sway, and the eyes keep the Viva half-closed lids with blue irises and blink. In his skull he sits with his eyes shut, as the original Mumbo does. The Viva model has no wand or bag, so he keeps the game's own wand and bag, held in the new hand. With the mod off the original Mumbo is back. Not replaced: Mumbo's cutscene-only models (the intro and story scenes use other models) and his shadow. Checked headless: playing as Mumbo in Spiral Mountain and Mumbo in Mayahem Temple's skull, including talking to him: [v1.png](screens/viva-mumbo/v1.png). Swimming and the wand spell were not tried.
- Status: replaced by T248 (v2)

## T225 Intro: only the cloud backdrop is stretched (replaces T189)
- Asked: 2026-10-16 08:30 UTC
- Build: next build from main
- Steps:
  1. Aspect Ratio Expand in your wide window (3440x1417)
  2. Watch the intro ("Two years have passed..") from the start
- Look for: The opening cloud shots fill the whole width with no panel ends or black at the sides. The castle, the rock, Grunty's grave and the text keep their normal shape (not stretched).

## T224 Refresh Mods in game
- Asked: 2026-10-16 08:15 UTC
- Build: main (next Windows build)
- Steps:
  1. Start the game and load a file, then open the Mods menu: the Refresh button (the circular arrow next to Open Mods Folder) is no longer greyed out
  2. Without closing the game, drop a model mod or texture pack zip into the mods folder (for example "Smash Banjo v6.zip"; delete its unpacked "Smash Banjo v6" folder first if it is already there)
  3. Press Refresh
- Look for: the new mod appears in the list straight away and is switched on, and the area reloads with it (Smash Banjo shows up without restarting). Mods that were already loaded stay as they were. Code mods (.nrm) also appear but stay off until you restart, as before. A zip whose folder already exists is not unpacked again in game (that still happens on the next start), and Install Mods stays greyed out in game. Checked headless: zip copied in mid-game in Spiral Mountain, refresh called directly, Smash Banjo unpacked, opened, switched on and loaded after the area reload. The button press itself was not clicked headless.
- Status: waiting for L

## T223 Bee Banjo model mod: replaces the Bee transformation
- Asked: 2026-10-16 08:00 UTC
- Build: main, plus mods/Bee Banjo v2.zip from project files (take Bee Banjo v1.zip out of the mods folder)
- Steps:
  1. Put "Bee Banjo v2.zip" in the mods folder as it is and turn on "Bee Banjo" in the Mods menu
  2. In Cloud Cuckooland, turn into the bee at Humba Wumba's (or with the transformation cheat)
  3. Look at the bee close up in photo mode, then walk, fly, shoot stingers and talk to someone
- Look for: the round Bee Banjo from your FBX (belt, shorts, backpack, HD textures) instead of the game's bee, the same size and in the same place. The wings are translucent and flap with the game's own animation; arms, legs and the mouth move too. Only the Bee transformation changes; Banjo himself is untouched. Checked headless in Cloud Cuckooland: loads from the zip, stands, turns and walks (screenshot screens/bee-banjo/v1.png).
- v2 (2026-10-16 09:30 UTC, L: "issues with eyes"): nothing was ever simplified. The game stores positions in whole units, which bent the small eyes and warped the irises; v2 re-fits the textures to the rounded shape so the irises are round again (screens/bee-banjo/v2.png). Do the eyes look right now?
- Status: waiting for L

## T222 Honeycomb Piece model mod (Honeycomb Recreation)
- Asked: 2026-10-16 07:45 UTC
- Build: main, plus mods/Honeycomb Piece v1.zip from project files
- Steps:
  1. Put "Honeycomb Piece v1.zip" in the mods folder as it is (no unzipping). In the Mods menu, turn on "Honeycomb Piece (Honeycomb Recreation)"; it is its own entry, separate from the Banjo model mods and from HoneyComb NB (T221, which replaces the health honeycomb; both can be on together)
  2. Find an Empty Honeycomb (the gold hexagon that adds health; Mayahem Temple has one by the entrance), or use Warp > Test > Test room, where the Empty Honeycomb stands next to the health honeycomb
  3. Watch it spin, then collect it
- Look for: the Empty Honeycomb is your FBX's gold frame with rounded edges, deeper than the game's own, in the game's shiny gold with its sparkles, the same height as before and standing in the same place. The FBX's honey texture was not in the zip, and its mesh only uses the plain Gold material, so the frame is gold all over. It replaces the Empty Honeycomb only, not the orange health honeycomb. Collecting it should work as before. Checked headless in the test room (screenshot screens/honeycomb-piece/v1.png).
- Status: waiting for L

## T221 HoneyComb NB model mod (HoneyComb NB v2)
- Asked: 2026-10-16 (L: "Add this replacement, HoneyComb NB")
- Build: any recent build, plus the mod zip from project files: mods/HoneyComb NB v2.zip
- Steps:
  1. Put "HoneyComb NB v2.zip" in the game's mods folder as it is (no unzipping), then turn on "HoneyComb NB" in the Mods menu
  2. Load a file and go to a health honeycomb (Spiral Mountain's cave has three), or enter a new area so the model loads
  3. Collect one, then turn the mod off and enter a new area
- Look for: the health honeycombs are the Nuts & Bolts style comb, a gold frame round a block of honey with the HD honey texture, spinning as usual, and collecting one still heals. With the mod off the original comb is back after the area reloads. v2 uses the exact gold from the FBX (lime-tinted, as in its own game; v1 had a warmer gold). Is the size right (same width as the original, a little taller)? Empty honeycombs are a different model and stay as they are. Checked headless: the three combs in Spiral Mountain's cave with the mod on: [v2.png](screens/honeycomb-nb/v2.png).

## T220 Windows build fixed: 3D grass shader
- Asked: 2026-10-16 07:40 UTC
- Build: main (pull and build)
- Steps:
  1. Pull main and build as usual
  2. Graphics > 3D grass to 100 and walk through Spiral Mountain's meadow
- Look for: the build finishes (it stopped in GrassGS.hlsl line 116 with "Declared output vertex count (70) ... equals 1190"). The grass should look as before; each pass now draws 12 blades per step instead of 14, with more passes allowed, so the same number of blades. Checked: the same DXC error reproduced on Linux with the Windows-style DXIL compile, the fixed shader validates, and the grass draws headless in Spiral Mountain.
- Status: waiting for L

## T219 Boss rush
- Asked: 2026-10-16 (L: "Make a boss rush mode")
- Build: main (pull and build)
- Commit: "Boss rush: the 13 bosses back to back" on main
- Steps:
  1. Load a file (any progress), then General > Boss rush = On and close the menu
  2. Beat Klungo; after a moment on the game select screen Targitzan's fight should start by itself. Carry on as far as you like
  3. Lose a fight on purpose: answer Yes to "Do you want to play again?" once, then lose again and answer No
  4. Load your file again
- Look for: Step 1, a "Boss rush 1/13: Klungo" notice and Klungo's fight starts, with the moves and eggs the fight needs. Step 2, each win hands over to the next boss (order: Klungo, Targitzan, Old King Coal, Mr. Patch, Lord Woo Fak Fak, Klungo 2, Terry, Weldar, Chilli Billi, Chilly Willy, Mingy Jongo, Klungo 3, Hag 1). Step 3, Yes restarts the same boss; No ends the rush with "Boss rush over: N of 13 bosses beaten" and the switch is off again. Step 4, your file is where you left it. Does a win ever end the rush by mistake, or a loss carry on? Is the order right? Checked headless: Klungo's fight handing over to Targitzan's, and a loss ending the rush; winning a fight can't be done headless, so wins are only tested through a stand-in: [klungo-to-targitzan-headless.png](screens/boss-rush/klungo-to-targitzan-headless.png).
- Status: failed (the switch never started a rush); fixed, retest with T252

## T218 Modern water: waterfalls remade, stronger waves from Banjo
- Asked: 2026-10-16 05:55 UTC
- Build: main (pull and build)
- Steps:
  1. Graphics > Water: Modern
  2. In Spiral Mountain, look at the stream that runs down past the tree trunk into the pool, and any other waterfall you know
  3. Swim around a pool, then stand still in it
  4. Go into Mumbo's Skull
- Look for: Step 2, the steep parts of the water have streaks pouring down them in the level's water colour, with white foam boiling where they land, and no hard white wedges. Step 3, Banjo pushes bigger waves out round him when swimming and gentle ones when still. Step 4, the light beams still look like the game's. Checked headless in Spiral Mountain and Mumbo's Skull.

## T217 Sidebar menu is the only settings layout
- Asked: 2026-10-16 05:10 UTC
- Build: main (pull and build)
- Steps:
  1. Open the settings menu (Esc, or Back / Select on a controller)
  2. Look in the DEV tab
  3. Type in the Search tab and look at a switch in the results
- Look for: Step 1, the menu opens with the brown and gold sidebar layout without turning anything on. Step 2, there is no Sidebar menu (preview) switch any more. Step 3, switches that are on are gold there too. Checked headless with keyboard and mouse.
- Status: waiting for L

## T216 Day and night: morning mist
- Asked: 2026-10-16 03:35 UTC
- Build: main (pull and build)
- Commit: "Day and night: morning mist" on main
- Steps:
  1. Graphics > Day and Night: Morning, Weather: Clear, in Terrydactyland, Spiral Mountain or the Isle o' Hags; look out over lower ground
  2. Day and Night: Cycle and watch it thin out as the sun climbs
- Look for: A pale haze lying low over the ground in the distance, warm towards the sun, gone by mid-morning and absent in the evening, at night and in rain. It is separate from the Fog setting. Too thick, too thin? Checked headless: [morning-mist.png](screens/day-night/morning-mist.png) (Terrydactyland left, Jinjo Village right).
- Status: waiting for L

## T215 Day and night: golden hour and morning dew
- Asked: 2026-10-16 03:15 UTC
- Build: main (pull and build)
- Commit: "Day and night: golden hour and morning dew" on main
- Steps:
  1. Graphics > Day and Night: Cycle with Day Length 4, Weather: Clear, in Spiral Mountain; watch from sunrise to mid-morning, and again in the late afternoon
  2. Day and Night: Morning, stand on the grass and turn the camera slowly
- Look for: Step 1, the warm light lasts a while after sunrise and before sunset, with richer colours, then fades to plain daylight. Step 2, tiny glints of dew twinkle on level grass while the sun is low in the morning, and go as it climbs (none in the evening or in rain). Too strong, too faint? Checked headless: [morning-dew-golden-hour.png](screens/day-night/morning-dew-golden-hour.png) (the dew is faint in a still screenshot).
- Status: waiting for L

## T214 Day and night: northern lights over the Icy Side
- Asked: 2026-10-16 02:50 UTC
- Build: main (pull and build)
- Commit: "Day and night: northern lights over Hailfire Peaks' Icy Side" on main
- Steps:
  1. Graphics > Day and Night: Night, Weather: Clear, go to Hailfire Peaks' Icy Side and look up at the sky (first person helps)
  2. Graphics > Northern Lights off and on
- Look for: Soft green curtains of light, violet at their tops, waving slowly across the night sky. Too faint, too strong? Hidden under rain or heavy snow. Checked headless with them forced on in Spiral Mountain, where the sky shows from the start: [northern-lights.png](screens/day-night/northern-lights.png).
- Status: waiting for L

## T213 Day and night: lit windows at night
- Asked: 2026-10-16 02:20 UTC
- Build: main (pull and build)
- Commit: "Day and night: lit windows at night" on main
- Steps:
  1. Graphics > Day and Night: Night, go to Jinjo Village and look at the houses
  2. Day and Night: Cycle with Day Length 4 and watch the windows as evening comes
- Look for: The house windows glow warm yellow at night and go back to their own look by day; the wooden frames stay dark. Any window that should light and doesn't (tell me where)? Also: fireflies no longer fill the screen when one drifts right by the camera. Checked headless in Jinjo Village: [lit-windows-off-on.png](screens/day-night/lit-windows-off-on.png) (top unlit, bottom lit).
- Status: waiting for L

## T212 Day and night: shooting stars and moon phases
- Asked: 2026-10-16 01:40 UTC
- Build: main (pull and build)
- Commit: "Day and night: shooting stars and moon phases" on main
- Steps:
  1. Graphics > Day and Night: Night, Weather: Clear, in Spiral Mountain; look at the starry sky for a minute
  2. Day and Night: Cycle with Day Length 4, and play through a few nights, finding the moon each night
- Look for: Step 1, now and then a short bright streak slides down part of the sky and fades (about one every 18 seconds, wherever you look, so not every one is in view). The moon is full. Step 2, the moon goes round its phases over eight days: full on the first night, then waning, new (dark) on the fifth, then waxing. Checked headless: [shooting-star.png](screens/day-night/shooting-star.png) (with one forced into view) and [moon-phases-first-and-last-quarter.png](screens/day-night/moon-phases-first-and-last-quarter.png).
- Status: waiting for L

## T211 Sun shadow softness
- Asked: 2026-10-16 00:32 UTC
- Build: 3860208
- Steps:
  1. Graphics > Photo Filters: Sun shadows on, Sun shadow softness at 60 (default)
  2. Stand near Klungo or a Grublin in Spiral Mountain in daylight
  3. Slide Sun shadow softness from 0 to 100
- Look for: Characters' shading gets smoother and less triangly as softness goes up, and shadow edges fade more gently
- Status: waiting for L

## T210 Day and night: snow on Hailfire Peaks' Icy Side
- Asked: 2026-10-16 01:00 UTC
- Build: main (pull and build)
- Commit: "Day and night: snow on Hailfire Peaks' Icy Side" on main
- Steps:
  1. Graphics > Day and Night: Morning (or Cycle), Weather: Changing, go to Hailfire Peaks' Icy Side
  2. Weather: Storm, then Clear
- Look for: Step 1, light snow drifting down slowly and swaying, under a pale sky. Step 2, Storm is heavy snow (no lightning or rain sound there); Clear stops it. Too many flakes, too few, too big? Checked headless: [snow-icy-side-light-and-storm.png](screens/day-night/snow-icy-side-light-and-storm.png) (light on the left, storm on the right).
- Status: waiting for L

## T209 Day and night: rain and thunderstorms
- Asked: 2026-10-16 00:40 UTC
- Build: main (pull and build)
- Commit: "Day and night: rain and thunderstorms" on main
- Steps:
  1. Graphics > Day and Night: Morning, Graphics > Weather: Rain, in Spiral Mountain or the Isle o' Hags; walk and turn the camera
  2. Graphics > Weather: Storm, wait for lightning; then Day and Night: Night
  3. Graphics > Weather: Changing and play a while (mostly clear, rain or a storm now and then for a few minutes)
- Look for: Step 1, a grey overcast sky with thick clouds, a darker greyer world, rain streaks falling that stay put as you turn and go behind walls, and the hiss of rain. Step 2, lightning flashes light up the sky and the world, then thunder a moment later, near or far. Too heavy, too light, too loud? The sun shadows, light shafts, lens flare, crickets and birds fade with the rain. No rain on Hailfire Peaks' Icy Side or in Cloud Cuckooland. Checked headless: [rain-morning.png](screens/day-night/rain-morning.png) and [rain-night-and-lightning.png](screens/day-night/rain-night-and-lightning.png) (a flash held on); sound preview previews/day-night/storm.wav (louder than in the game). Speed not measured.
- Status: waiting for L

## T208 Widescreen: NPCs and objects at the sides stay whole
- Asked: 2026-10-16 00:08 UTC
- Build: 5ff7408
- Steps:
  1. Aspect Expand in your wide window, HD shadows on
  2. Walk past NPCs and enemies so they sit at the left or right edge (Jiggywiggy's disciples, Bottles' corpse in Spiral Mountain)
  3. Try again with HD shadows off
- Look for: Nothing vanishes or gets cut by a straight line at the sides, with HD shadows on or off
- Status: waiting for L

## T207 Day and night: volumetric clouds
- Asked: 2026-10-16 00:10 UTC
- Build: main (pull and build)
- Commit: "Day and night: volumetric clouds" on main
- Steps:
  1. Graphics > Day and Night: Morning, then Sunset, then Night, in Spiral Mountain or the Isle o' Hags, and look up at the sky
  2. Stand still for a minute and watch them move
  3. Graphics > Clouds off and on, and check the frame rate with them on
- Look for: Soft, rounded clouds over the game's own sky, drifting slowly: white with grey undersides by day, orange and pink at sunset, dark and hiding the stars at night. Too many, too few, too dark? Does the frame rate drop with them on? None in Cloud Cuckooland. Known: the lens flare still shows when a cloud covers the sun. Checked headless at morning, sunset and night: [clouds-morning-on-off.png](screens/day-night/clouds-morning-on-off.png), [clouds-sunset-night.png](screens/day-night/clouds-sunset-night.png) in project files (the green sky is the no-save warp, not the clouds). Speed not measured.
- Status: waiting for L

## T206 Day and night: night sounds
- Asked: 2026-10-15 23:55 UTC
- Build: main (pull and build)
- Commit: "Day and night: crickets, owls and birdsong" on main
- Steps:
  1. Graphics > Day and Night: Night in Spiral Mountain or Jinjo Village, stand still for a minute
  2. Graphics > Day and Night: Morning, stand still for a minute
  3. Graphics > Night Sounds off and on
- Look for: Step 1, crickets chirping quietly under the music and now and then an owl's "hoo ... hu-hoooo". Step 2, birds singing short phrases. Too loud, too quiet, or do they sound fake? None on Hailfire Peaks' Icy Side; no crickets on Lava Side or in Cloud Cuckooland. They stop in the pause menu. The sounds are made in code (nothing taken from the game or elsewhere). Previews: previews/day-night/night.wav and morning.wav in project files (played louder than in the game). Checked headless: the cycle fades the crickets out and the birds in at dawn; the sound itself was not heard.
- Status: waiting for L

## T205 Banjo fur
- Asked: 2026-10-15 23:30 UTC
- Build: main (pull and build)
- Steps:
  1. Graphics > Photo Filters on, then set Banjo fur to 100 (Banjo fur length stays at 100)
  2. Walk round Spiral Mountain, turn the camera close behind Banjo and to his side, jump and roll
  3. Try Banjo fur length at 50 and 200, then Banjo fur at 0
  4. If you can, once more with Smash Banjo on (Mods menu)
- Look for: Step 2, his brown fur (head, arms, back, legs) looks fuzzy with short strands standing out of it, most visible along his outline, and the strands stay on him as he moves instead of crawling. Kazooie, the shorts, backpack, gloves, boots and muzzle stay smooth. Step 3, longer or shorter fur, then none. Step 4, whether the Smash model's fur also grows strands (its fur colours may differ). Checked headless in Spiral Mountain (screenshot in project files, screenshots/banjo-fur/off-vs-on-headless.png). Cost there, software Vulkan at Original resolution: GPU 25 to 37 ms per frame, so tell me if your frame rate drops. Not checked: Windows with D3D12 (the shader is built there at runtime), the split-up Banjo and Kazooie, transformations (no fur by design).
- Status: waiting for L

## T204 3D grass density slider
- Asked: 2026-10-15 23:35 UTC
- Build: main (pull and build)
- Steps:
  1. Graphics > 3D grass to 100, then go to Spiral Mountain's meadow by Klungo
  2. Move Graphics > 3D grass density from 100 down to 10 and up to 200 while watching the grass
- Look for: lower numbers grow fewer, more spread-out blades (the ground shows between them) and run faster; higher numbers grow a thicker carpet and cost more. It changes live, with no restart. The blades stay the same width at every density. Which number looks right to you? I can make it the default. Checked headless at 30, 50 and 200 in Spiral Mountain.
- Status: waiting for L

## T203 Smash Banjo v6: feet fur and backpack
- Asked: 2026-10-15 23:50 UTC
- Build: main, plus mods/Smash Banjo v6.zip from project files (take v1 to v5 out of the mods folder)
- Steps:
  1. Load a save with Smash Banjo on, look at his feet close up (photo mode), then walk and stop
  2. Run, jump, flap and roll, and watch the backpack
- Look for: Step 1, the fur round his ankles sits on his legs and turns with his feet, with no pink band under it. Step 2, the backpack stays on his back the way vanilla's does. Checked headless: no pink band at the ankles; backpack on his back in the flap; the run was not compared frame by frame with vanilla.

## T202 Day and night: fireflies
- Asked: 2026-10-15 UTC
- Build: latest Windows build from main
- Commit: "Day and night: fireflies at night" on main
- Steps:
  1. Graphics > Day and Night: Night (or Cycle) in Spiral Mountain, Jinjo Village, Mayahem Temple or Terrydactyland
  2. Walk round the open grass and look about
  3. Graphics > Fireflies off and on
- Look for: Small yellow-green glows drifting and blinking round Banjo, a little above the ground, hidden behind walls and hills. None by day or on Hailfire Peaks. Too many, too few, too big or too small?

## T201 Banjo X Alt v2: full detail, nothing simplified
- Asked: 2026-10-15 23:40 UTC
- Build: main, plus mods/Banjo X Alt v2.zip from project files (take Banjo X Alt v1.zip out of the mods folder)
- Steps:
  1. Put "Banjo X Alt v2.zip" in the mods folder as it is. Turn off Smash Banjo and Banjo X, turn on "Banjo X (alt rig)"
  2. Look at Banjo and Kazooie close up in photo mode, then walk, jump, Feathery Flap, Talon Trot and roll
- Look for: every triangle of the FBX (42,433 triangles, 32,015 vertices; v1 was cut down). Same rig, jaw, blink and HD textures as v1 (T192). The model was too big for the game's draw-list index, so the first commands are stored before the list and reached with negative indices; if Banjo is invisible or only his belt shows, that trick fails on Windows. Checked headless in Spiral Mountain: loads from the zip, walks, jumps, flaps with Kazooie and crouches (screenshot screens/banjo-x/alt-v2.png).
- Status: failed (L, 2026-10-16: face warped); replaced by T228

## T200 Day and night: sun, lens flare
- Asked: 2026-10-15 UTC
- Build: latest Windows build from main
- Commit: "Day and night: a sun in the sky and a lens flare" on main
- Steps:
  1. Graphics > Day and Night: Cycle (Day Length 4) or Morning / Sunset, in Spiral Mountain or Jinjo Village
  2. Turn the camera towards the sun (east in the morning, west at sunset)
  3. Graphics > Lens Flare off and on
- Look for: A bright sun disc in the sky (orange at sunset) that moves and sets below the horizon; soft coloured rings and a glare when you look at it, gone when a hill or wall hides it. No stars left over at sunset. Too strong or too weak?
- Status: waiting for L

## T199 Game Frame Rate 30 / 40 / 60 / 120 / 175 / 240 / Uncapped
- Asked: 2026-10-15 23:30 UTC
- Build: your local build of main
- Commit: cbb25e7
- Steps:
  1. Graphics: Game Frame Rate, try each of 40, 120, 175, 240 FPS and Uncapped (Interpolation Off, so the overlay shows the game's own rate)
  2. In each, run, jump and swim for a minute in Spiral Mountain, and talk to someone
  3. Uncapped: check the frame rate overlay goes past 240 where your PC can
  4. Send the session log afterwards
- Look for: The overlay holds the chosen rate (Uncapped as high as your PC goes); Banjo moves at the same speed in every mode; the sound stays right for 10 minutes or more (no crackle, no "[audio]" lines in the log); swimming behaves as at 60

## T198 Smash Banjo v5: full detail, Smash-size hands, no red fringe
- Asked: 2026-10-15 23:20 UTC
- Build: main, plus mods/Smash Banjo v5.zip from project files (take v1 to v4 out of the mods folder). No new code: no DEV setting is needed.
- Steps:
  1. Load a save with Smash Banjo on and compare him close up (photo mode) with the Smash render you sent: front, side and back
  2. Walk, jump, flap, roll and crouch
- Look for: every Smash vertex is in (17,957 vertices, 20,291 triangles, no simplifying), hands and arms at their Smash size (v2 to v4 shrank them), no red or pink fringe at the fur edges, fur shading smooth. Checked headless: loads and animates (walk, flap, crouch, roll) in Spiral Mountain.
- Status: waiting for L

## T197 3D grass as real blades (roadmap 4.47)
- Asked: 2026-10-15 23:00 UTC
- Build: main (pull and build)
- Steps:
  1. Graphics > 3D grass to 100 (3D grass height 100, 3D grass distance 2500)
  2. Spiral Mountain: stand on the meadow by Klungo and watch the grass, then walk and run through it and stop
  3. Isle o' Hags and Mayahem Temple's courtyard: look at it close up and far away
  4. Try 3D grass height 50, 150 and 200, and 3D grass distance 1000 and 5000, then set 3D grass to 0
- Look for: Every blade a real 3D blade (it stands up off the ground and sticks out over ledges), swaying in waves of wind, bending away from Banjo and springing back behind him. Closer to the examples you sent? Anything off (too thin, too dense, too much wind, blades on things that aren't grass)? Frame rate with it on and off: this way of drawing needs geometry shaders and costs more than the layered grass, and lowering 3D grass distance makes it cheaper. Checked headless: blades in Spiral Mountain and an Isle o' Hags area, standing up over the ledge edges. Not checked: the motion (the container runs at about 1 frame a second with it on).
- Status: waiting for L

## T196 Hang watchdog catches game freezes, not only screen freezes
- Asked: 2026-10-15 UTC
- Build: main (pull and build)
- Steps:
  1. Play as usual. When the game freezes, wait 15 seconds before closing it
  2. Send logs\hangs.log and the newest logs\hang_*.dmp
  3. Optional check without waiting for a real freeze: in a command prompt in the exe's folder run `set TOOIE_TEST_HANG=game:60:20` then start BanjoTooieN64Recomp.exe; one minute after start the game freezes for 20 seconds on purpose
- Look for: hangs.log names which part stopped: "the game sent no new frame" (the game itself, even while the picture still refreshes), "no frame was presented" (graphics or driver) or "the window stopped handling events". Under each entry are the named threads with the function each was in, and after 15 seconds a hang_*.dmp is written. Before, the watchdog only noticed the screen stopping, so a freeze inside the game, where the last picture keeps being shown, was never logged. Checked headless on Linux with fake game, screen and window freezes (each logged, and the "running again" line after) and 2 minutes of normal play with no false entries. The thread stacks and the dump are Windows only and were only compile-checked, not run.
- Status: waiting for L

## T195 Frame rate dropping after a while: what is filling video memory
- Asked: 2026-10-15 UTC
- Build: main (pull and build)
- Steps:
  1. Same setup as your log of 2026-10-15 (4K, 120 fps, MSAA 2x, BT Reloaded and Smash Banjo on)
  2. Play normally for 10 minutes, then send console.log
- Look for: the [vram] lines now also say "ours N MB in N allocations, N textures, N render targets". If "ours" climbs with VRAM, the renderer is leaking and the counts say what. If VRAM climbs and "ours" stays level, the graphics driver is holding the memory. Checked headless (software Vulkan, so not your NVIDIA driver): VRAM stays level for 3 minutes with the Enhanced preset, 4K, 120 fps, Smash Banjo, a test texture pack, cheats on, in Mayahem Temple and Isle o' Hags; your log climbs about 1 GB a minute in the same places.

## T194 Sidebar menu (preview), layout A steps 1 to 3
- Asked: 2026-10-15 22:50 UTC
- Build: main (pull and build)
- Steps:
  1. General > DEV tab on, then in the DEV tab turn on Sidebar menu (preview)
  2. Move through the tabs with L and R, and through the options with the stick (and with the mouse)
  3. Turn the switch off again
- Look for: Step 1, the tabs move into a list down the left side at once, with a "Search settings" box at the top (it opens the Search tab) and the quit and close buttons at the bottom; each page shows its tab's name as a heading, with a thin line under each option. It is styled after Banjo-Tooie: brown panels with a gold border, gold cartoon lettering, and the picked tab filled gold with a Jiggy. Switches that are on are gold too (blue again with the sidebar off). Step 2, the selected option's description shows in a strip along the bottom and changes as you move. Step 3, the tabs go back across the top as before. Checked headless with keyboard and mouse; not checked with a controller.
- Status: waiting for L

## T193 Smash Banjo v4: smoother surface
- Asked: 2026-10-15 22:40 UTC
- Build: main, plus mods/Smash Banjo v4.zip from project files (take v1 to v3 out of the mods folder)
- Steps:
  1. Load a save with Smash Banjo on and look at Banjo close up in photo mode (head, brow, chest, hands), as in your wobbly screenshot
  2. Walk, flap and roll
- Look for: the lumpy look is gone or much smaller. The head keeps more of its shape (85% of the Smash triangles instead of 65%), the arms and hands 80% instead of 65%, and the fur lighting comes from a smoothed copy of the surface, so the sculpted fur bumps no longer show as dark and light patches. Checked headless: loads and animates (walk, flap, crouch, roll); 15,714 of 16,000 vertices.
- Status: waiting for L

## T192 Banjo X model mod, second rig (Banjo X Alt v1)
- Asked: 2026-10-15 22:40 UTC
- Build: main (pull and build), plus the mod zip from project files: mods/Banjo X Alt v1.zip
- Steps:
  1. Put "Banjo X Alt v1.zip" in the game's mods folder as it is (no unzipping). Turn off Smash Banjo and Banjo X in the Mods menu, then turn on "Banjo X (alt rig)"
  2. Load a save and walk, run, jump, Feathery Flap, Talon Trot and roll; stand still to see Banjo blink; talk to someone or pick something up to see his mouth move
  3. Compare it with Banjo X v1 (T191): both convert the same FBX; keep whichever looks better
- Look for: the Banjo X model (from the FBX L supplied) with its full-size textures, moving with every animation. This rig also opens Banjo's lower jaw and Kazooie's lower beak, blinks Banjo's eyes (closed eyes are drawn in his fur colour), keeps the straps on the chest, and keeps the belt on the hips. Checked headless in Spiral Mountain: walking, Feathery Flap, Talon Trot and the beak attack animate (screenshot screens/banjo-x/alt-v1.png in project files). Kazooie's two tail-feather textures stay low resolution (the headless run never showed the tail, so their HD hashes are unknown). Solo Banjo, solo Kazooie, transformations and cutscene models are not replaced.

## T191 Banjo X model mod v1
- Asked: 2026-10-15 22:30 UTC
- Build: main, plus mods/Banjo X v1.zip from project files (take Smash Banjo out of the mods folder, or switch it off in the Mods menu)
- Steps:
  1. Load a save in Spiral Mountain with Banjo X on and look at Banjo and Kazooie from the front, side and back
  2. Walk, jump, flap, roll and crouch
  3. Let Banjo stand still for the idle animations
- Look for: the Banjo X look (colours, Kazooie's feathers, backpack, straps, belt), and anything that tears, pokes through or comes loose when he moves (straps and buckles most of all). His eyes stay open: the model has no blink. Checked headless: it loads and animates (walk, jump, flap, crouch, roll) with the HD textures matched; straps were only checked in motion at a distance.
- Status: waiting for L

## T190 Smash Banjo v3: face, straps, and switching it on or off
- Asked: 2026-10-15 22:15 UTC
- Build: main (pull and build), plus mods/Smash Banjo v3.zip from project files (take v1 and v2 out of the mods folder)
- Steps:
  1. Load a save in a level with Smash Banjo on and let Banjo stand still until his idle animations play (the one where his face went missing)
  2. Walk, roll and flap, and watch the backpack straps
  3. In a level, open the Mods menu and switch Smash Banjo off, then on again
- Look for: Step 1, his whole face stays (only the eyes blink). Step 2, the straps stay on his shoulders. Step 3, the area reloads straight away (Banjo back at the area's entrance) with the model switched. Checked headless: the model loads and animates with the face in place; the idle with the hidden eyes and the menu switch were not reproduced headless.
- Status: waiting for L

## T189 Intro backdrop stretched to widescreen (replaced by T225)
- Asked: 2026-10-15 22:10 UTC
- Build: next build from main
- Steps:
  1. Aspect Ratio Expand, a wide window (your 3440x1440)
  2. Start a new game, or warp to the intro ("Two years have passed..")
- Look for: The cloud backdrop fills the whole width, with no slanted panel ends and no black at the sides. Spiral Mountain afterwards looks normal (not stretched).
- Status: waiting for L

## T188 Sun shadow beside Banjo fixed, and a Sun shadow on Banjo switch
- Asked: 2026-10-15 21:44 UTC
- Build: 25724df (main)
- Steps:
  1. Sun shadows on (Graphics, Photo Filters)
  2. Stand Banjo on grass in sunlight and look from above
  3. Turn Sun shadow on Banjo off and on
- Look for: No dark streaky block beside Banjo; his sun shadow is a small soft shape. With the switch off he casts no sun shadow (HD shadows still give him one).
- Status: waiting for L

## T187 Light beams no longer drawn as water (Modern water)
- Asked: 2026-10-15 21:35 UTC
- Build: main (pull and build)
- Steps:
  1. Graphics > Water: Modern. Go into Mumbo's Skull in Terrydactyland, where your screenshot of 21:13 was
  2. Then check some real water still gets the new look (the Spiral Mountain pool)
- Look for: Step 1, the beams of sunlight look as the game draws them (soft, see-through light), with no waves, reflections or glassy bending on or under them. Step 2, the pool still has the Modern look. Checked headless: in Mumbo's Skull no draws count as water now; the Spiral Mountain pool still says "replacing" in the console.
- Status: waiting for L

## T186 Race Warps (Canary Mary's races from the Warp tab)
- Asked: 2026-10-15 21:17 UTC
- Build: main (pull and build)
- Steps:
  1. Turn on Cheats > Enable cheats and Cheats > Warp tab, then load any save
  2. Open the Warp tab and scroll to the bottom: Race Warps has four entries
  3. Pick Glitter Gulch Mine: first race. You land by Mary in Glitter Gulch Mine, then go straight into the race with the 3, 2, 1 countdown
  4. Race her (mash A), win or lose, and you come back to Glitter Gulch Mine
  5. Do the same for Glitter Gulch Mine: second race and both Cloud Cuckooland races
  6. Open the pause menu Totals: your Jiggies and Cheato pages have not changed
- Look for: Each of the four races starts and can be raced to the end without a crash. Winning gives no Jiggy or Cheato page (practice run), and if your file has not met Mary yet she is still caged afterwards. Checked headless from Spiral Mountain with no progress: all four start, and a scripted A mash won the GGM first race.
- Status: waiting for L

## T186 Texture sweep: video memory, freezes and the cutscene crash
- Asked: 2026-10-15 UTC
- Build: latest Windows build from main
- Steps:
  1. Same setup as before (BT Reloaded 4K pack, your usual graphics settings). Load a spare save file
  2. DEV > Texture dump: pick Sweep all maps and leave it running
  3. If it freezes or crashes, start the game again: the sweep should stay idle (a notice says so) until you pick it again, then carry on from the next map
- Look for: no freeze or crash for the whole sweep. It no longer stops at Star Spinner (Saucer) or at "Banjo's house is destroyed" (that cutscene is now skipped). console.log has `[vram]` lines (use, budget and texture pack size), and every `done` line in sweep.txt ends with the VRAM figures. Send console.log and sweep.txt either way.
- Status: waiting for L

## T185 Smash Banjo model mod
- Asked: 2026-10-15 21:15 UTC
- Build: main (pull and build), plus the mod zip from project files: mods/Smash Banjo v2.zip
- Steps:
  1. Put "Smash Banjo v2.zip" in the game's mods folder as it is (no unzipping) and start the game
  2. Open the Mods menu: Smash Banjo is listed. Turn it on
  3. Load a save and walk, run, jump, Feathery Flap, crouch and roll; let Banjo stand still to see him blink
  4. Turn the mod off in the Mods menu, then go through a door or loading zone
- Look for: Banjo and Kazooie use the Smash Ultimate model with its full-size textures, move with every animation, and blink. Step 4: the game's own model comes back after the next area load (the model is only read when an area loads). v2 (2026-10-15 21:40) fixes the gap on top of Banjo's head, smooths the fur edges, makes the hands smaller and the arms slimmer, and puts Kazooie's shoes and boots back (the game's own models on the new legs). Remove v1 from the mods folder first. Also look for: Kazooie's Springy Step Shoes, Turbo Trainers and Wading Boots on her feet; those were only checked offline, not in the game. Solo Banjo, solo Kazooie, transformations and cutscene models are not replaced. Checked headless in Spiral Mountain (screenshot screens/smash-banjo/v2.png in project files).

## T184 Transform anywhere
- Asked: 2026-10-15 21:20 UTC
- Build: main (pull and build)
- Steps:
  1. QOL > Transform anywhere: On. On a controller, bind Controls > Movement > Transform to a button (the keyboard has T)
  2. In a world where you have already changed in Humba's pool (Mayahem Temple, Stony, for example), stand anywhere outside and press Transform
  3. Press it again to change back, then change once more
  4. Press it while jumping, while swimming and in a world whose Humba you have not used yet
  5. If you have Terrydactyland: with Humba's tent big you get the Daddy T-Rex; try it out in the open and pressed against a wall
- Look for: Banjo spins up and comes down as the form where he stood, and back. Humba's "WUMBA CALL THIS..." line shows after the 1st change and not the 2nd, and her face goes away when the text ends. Step 4 plays a sound and does nothing: say whether that sound fits, or name one you would rather have. Step 5: the T-Rex against a wall is refused with the sound. Also say whether the change takes too long.
- Checked headless: Stony in Mayahem Temple and the Daddy T-Rex in Terrydactyland, both ways; the line on the 1st change only; refused when not unlocked, in the air, while the caveman talks, and with the T-Rex against a wall. Not checked headless: the submarine, bee, van, washer, snowball, detonator and baby T-Rex (same game call), and how the refusal sound sounds.
- Status: waiting for L

## T183 3D grass, Breath of the Wild style (roadmap 4.47)
- Asked: 2026-10-15 20:55 UTC
- Build: main (pull and build)
- Steps:
  1. Graphics > 3D grass to 100 (3D grass height 100, 3D grass distance 2500)
  2. Spiral Mountain: stand on the meadow by Klungo and watch the grass for a few seconds, then walk and run through it and stop
  3. Isle o' Hags (Jinjo Village) and Mayahem Temple's courtyard: look at it close up and far away
  4. Try 3D grass height 150 and 200, then set 3D grass to 0
- Look for: Knee-high tufts of thin blades arching out, dark at the roots and lighter at the tips. Waves of wind rolling across the field. Grass pressed down and out of the way round Banjo, with a trail behind him that springs back up over about a second. Is it close enough to Breath of the Wild, and is anything off (too dense, too thin, too tall, the wind too strong or too weak)? Frame rate with it on compared with off? It costs more than the T163 version (24 layers instead of 16); lower 3D grass distance if it is too slow. Checked headless: the look and the pressed-down patch round Banjo in Spiral Mountain. Not checked headless: the motion itself (the container runs at a few frames a second).
- Status: waiting for L

## T182 Totals checklist off by default, and the 8 FPS
- Asked: 2026-10-15 20:35 UTC
- Build: main (pull and build)
- Steps:
  1. Play as you did when the game ran at 8 FPS, with the frame rate overlay on
  2. Pause and go to View Totals: the pages look like the original game, with no LEFT HERE table (QOL > Totals checklist now starts Off, even if you had it On)
  3. If the game is still at 8 FPS: say where (only paused on Totals, in all of the pause menu, or while playing), then turn QOL > Totals checklist On and Off again and say whether the frame rate changes
- Look for: whether the 8 FPS is gone. Headless, the checklist on or off made no difference to the frame rate, paused or playing; the slow settings found there were Graphics > 3D grass (19 to 7 FPS), Sun shadows and Modern water.
- Status: resolved (L, 2026-10-16)

## T181 Modern water going back to the original
- Asked: 2026-10-15 20:55 UTC
- Build: main (pull and build)
- Steps:
  1. Graphics > Water: Modern. In Spiral Mountain, stand on the path by the pool next to the big tree trunk (where your burst of 22:05 was) and move the camera round the pool for a minute
  2. Do the same with frame smoothing on, as you had it
- Look for: the pool and the waterfalls keep the new water every frame (shore foam line, darker surface), never the game's own water. If it still goes back, send logs/console.log: lines starting with [modern water] say when it stopped replacing the water and why.
- Checked headless: the pool by the trunk stays Modern from above and from the bank, and the console line reads "replacing". Not reproduced headless: the switch back itself. Two things changed that can cause it: water drawn in an earlier part of a split picture is now left out there too (it showed the game's water under the new water), and T180 (merged before this) gives the effects the smoothed camera, the likely cause of the same on and off switching L saw with the fog.
- Status: waiting for L

## T180 Fog: black letterbox bars, and the fog switching on and off
- Asked: 2026-10-15 20:40 UTC
- Build: main (pull and build)
- Steps:
  1. Fog on (Graphics > Lighting, Water, Fog), then watch a cutscene with letterbox bars
  2. In Mayahem Temple (or where you saw it), walk and move the camera as in your burst of 21:40, with frame smoothing on as you had it
  3. If the fog still switches on and off: set Interpolation (frame smoothing) Off and watch the same spot again
- Look for: Step 1, the bars stay black. Step 2, distant scenery keeps its fog every frame. Step 3 tells whether the flicker comes from frame smoothing: say whether Off stops it. Checked headless: bars black with Fog 100 in the intro; fog steady in Mayahem Temple with smoothing on, zooming and orbiting. Not checked headless: the on and off flicker itself (not reproduced here).
- Status: waiting for L

## T179 Totals crash: video memory running out
- Asked: 2026-10-15 UTC
- Build: latest Windows build from main
- Commit: "Fix video memory filling up with Frame Read-Back off" on main
- Steps:
  1. Same settings as when it crashed (1440p, Frame Read-Back off, the default)
  2. Pause, View Totals, and leave it open for 5 minutes, turning pages now and then
  3. Watch the game's memory in Task Manager (Performance > GPU > Dedicated GPU memory): it should stay level instead of climbing
  4. Play for a while too: before the fix memory also crept up slowly in normal play, and the frame rate dropped the longer a session ran
- Look for: the crash in the NVIDIA driver (nvoglv64.dll) or "vmaCreateImage failed" lines in console.log
- Status: waiting for L

## T178 Smoke and water droplets with frame smoothing
- Asked: 2026-10-15 20:25 UTC
- Build: main (pull and build)
- Steps:
  1. Frame rate above Original, smoothing on, where the smoke and water droplets broke into stripes before
  2. Watch them as they were
  3. If they still stripe: Esc > WIP > Debug > Texture slide blending: Off, and watch again (it applies at once)
- Look for: Step 2, the smoke and droplets look as they do with smoothing off (the renderer no longer slides an animation's next frame across the texture). Step 3 tells whether what is left comes from texture sliding: say whether Off fixes it, and whether scrolling water (waterfalls, rivers) looks choppier with it Off. Checked headless: builds and renders Spiral Mountain with the option on and off. Not checked headless: the stripes themselves (not reproduced here).
- Status: waiting for L

## T177 Bottles' Revenge intro warp
- Asked: 2026-10-15 20:13 UTC
- Build: main (pull and build)
- Steps:
  1. Load a save file that has never had Bottles' Revenge on, and go to any area but Spiral Mountain
  2. Esc > General > Cut Content: Bottles' Revenge: On
  3. Watch the intro, then play on
  4. Turn it off and on again, and load the file again later
- Look for: Turning it on takes you to Spiral Mountain, where Bottles' ghost turns into Devil Bottles; when the scene ends you are back in the area you were in, at the entrance you came in by. After that (once the file is saved) it never warps you again. Checked headless: from Mayahem Temple the warp, the whole scene and the trip back all worked, and a second visit in the same run did not warp again. Not checked headless: a real save file over two sessions.
- Status: waiting for L

## T176 Modern water from below, and caustics
- Asked: 2026-10-15 19:28 UTC
- Build: main (this commit)
- Steps:
  1. Pull main and build, Graphics > Water: Modern
  2. In Atlantis or the Sea Bottom, swim near the floor
  3. In a pool you can dive in (Spiral Mountain pool, Jolly Roger's harbour), dive and look up at the surface
  4. Float on top and look down at the floor in shallow water
- Look for: Do bright moving light patterns (caustics) play on the floor under water, seen from above and from below? Looking up from under the surface: a bright, wobbling window onto the world above straight up, and a dark mirror further out? Anything that looks wrong at the edges of pools?
- Status: waiting for L

## T175 Modern water moves and reacts to Banjo
- Asked: 2026-10-15 19:13 UTC
- Build: main (this commit)
- Steps:
  1. Pull main and build, Graphics > Water: Modern
  2. Swim around the Spiral Mountain pool, then stop and float still
  3. Jump or fall into the water from the bank
  4. Look at the water from a low angle near the surface
- Look for: Does the surface visibly rise and fall, with ripples spreading from Banjo as he swims, a bigger splash when he lands in the water and a gentle bob when he floats still? Is Banjo's body under the water seen through it, without a white patch round him? Frame rate compared with Original?
- Status: waiting for L

## T174 Day and night cycle in the sunny outdoor levels
- Asked: 2026-10-15 UTC
- Build: latest Windows build from main
- Commit: "Day and night cycle" on main
- Steps:
  1. Graphics > Day and Night: pick Night, go to Spiral Mountain or Jinjo Village
  2. Then Sunset, then Morning, then Off (it changes at once, easing over half a second)
  3. Pick Cycle and set Day Length to 4 (the shortest) and play outside for 4 minutes to see a whole day: sunrise, day, sunset, night
  4. Go into a room (Bottles' house, a Jinjo house) and into Witchyworld or Cauldron Keep with Night picked
  5. With Photo Filters on, also try Sun shadows and Light shafts at Sunset and in Cycle
- Look for: Night should be dark blue with a starry sky and a moon, but still easy to play in; lamps and glowing things stay bright. Sunset should turn the light warm with an orange glow low in the sky. The HUD, rooms, underwater areas, Witchyworld and Cauldron Keep never change. Sun shadows and light shafts follow the sun as it moves; at night there are no light shafts. Is night too dark or too light, and is the 24-minute default day a good length?
- Status: waiting for L

## T173 Smooth talking heads toggle (4.20)
- Asked: 2026-10-15 19:00 UTC
- Build: main (this commit)
- Steps:
  1. Pull main and build, Game frame rate 60
  2. Talk to anyone with a talking head in the box (Klungo in Spiral Mountain, Bottles, Jamjars)
  3. Flip Graphics > Smooth talking heads on and off while the box is open (it applies live)
- Look for: The box, its opening and closing and the text already run at 60 either way. On, the head's mouth and blink move every frame but it also talks about twice as fast, because the mouth pictures are separate drawings. Tell me which you prefer, or whether the speed-up spoils it.
- Status: L 2026-10-15 19:49: did not work out; option removed

## T172 Modern water (first look)
- Asked: 2026-10-15 18:48 UTC
- Build: main (this commit)
- Steps:
  1. Pull main and build
  2. Graphics > Water: Modern (just under Water wave speed; it shows even with Photo Filters off)
  3. Swim in the Spiral Mountain pool by the waterfall cave and look around at low and steep angles
  4. Walk along the shore, then dive and come back up
  5. Visit other water you know (Jinjo Village, Jolly Roger's Lagoon, Terrydactyland) and flip Water back to Original to compare
- Look for: Is the water clear in the shallows and darker in deep parts, with reflections at low angles, a sun glint, foam on the shores and rings round Banjo? Tell me anything that disappeared (the game's own ripple rings are replaced by ours), anything that should not have turned into water, and how the frame rate compares with Original. The surface does not move yet; that is the next step.
- Status: waiting for L

## T171 Real-time sun shadows on everything
- Asked: 2026-10-15 18:35 UTC
- Build: c109431 (main)
- Steps:
  1. Graphics: turn on Photo Filters, set Sun shadows to 60 (or pick the Enhanced preset)
  2. Walk around Spiral Mountain and Plateau, then a cave level
- Look for: Do Banjo, enemies, posts and scenery cast shadows that move with them? Any flicker, dotted edges or shadows in odd places (caves)? Frame rate with it on vs off?
- Status: waiting for L

## T170 Frame rate overlay tidied (your "Overlay polish" pick)
- Asked: 2026-10-15 18:11 UTC
- Build: latest Windows build from main
- Steps:
  1. Overlay on Full (F3) and play a minute
- Look for: The lines are in four groups with a small gap between them: frames (fps, worst frame, 1% low, input latency), GPU (total, 3D effects, screen passes, shader compiles), the game (game fps and CPU, interpolation, map, Banjo), and the PC (renderer, extras, audio, build). GPU lines for passes that are all off are hidden. "Game ... CPU" no longer drops to 0 ms now and then (it counted some waits twice). Below 4 fps the first line keeps the last frame rate instead of vanishing. Anything you'd like moved, renamed or left out?
- Status: waiting for L

## T169 Models no longer cut off at the screen edge in Fill
- Asked: 2026-10-15 17:41 UTC
- Build: a63d67e (main)
- Steps:
  1. Set Aspect Ratio to Fill, HD shadows on
  2. Go to Spiral Mountain near Bottles' burnt body
  3. Turn the camera so the body, enemies or NPCs sit at the left, right and bottom edges, near and far
- Look for: Do they stay whole right up to the edge, with no shadow left behind without its object? Any drop in frame rate?

## T168 Totals checklist, step 3: the list behind each row
- Asked: 2026-10-15 UTC
- Build: latest Windows build from main
- Commit: "Totals checklist, step 3" on main
- Steps:
  1. Load a save part-way through, pause, View Totals, and go to a world you have visited
  2. The game's own blue A button (the same art as the green B button at the bottom) turns beside one row of the table. Move it with D-pad up/down, C-up/C-down or the stick up/down. The table fades and rises in with the page title, and goes out with it when you turn the page
  3. Press A: the table turns into a list of that row's items by name. Green is GET NOW, white is LATER, yellow is DONE; GET NOW comes first. The picked item is bright and the others are faded back, like the options in the pause menu. Notes are listed by spot ("SECOND STAIRS NOTES") with how many are left there
  4. Move down the list. On a white (LATER) item the bottom says what it still needs, for example "NEEDS GRIP GRAB", "NEEDS 15 MORE NOTES" or "NEEDS DETONATOR FORM". Hints only show for the item you pick
  5. Press B: back to the table, still on the Totals page. Press B again: the pause menu goes back as usual
  6. On Game Totals, A lists the row for every world you have visited (worlds you haven't been to stay hidden)
  7. Unpause with Start straight after, and check A and the stick work in the game right away
  8. QOL > Totals checklist off: no table, no A button, no list, and A, B and the stick act as before
- Look for: a hint that is wrong (tell me the world, the item and the hint). "NEEDS MORE THAN ONE THING" means no single move, form or area unlocks it on its own. Also tell me if the big counters on the left (4/10 and so on) ever vanish while a list is open: it happened in 2 of 6 headless runs at the same moment and not in the others, so I could not pin it to the list
- Status: waiting for L

## T167 Totals checklist, step 2: what you can get now (was T163, which 3D grass also uses)
- Asked: 2026-10-15 18:10 UTC
- Build: latest Windows build from main
- Commit: "Totals checklist, step 2" on main
- Steps:
  1. Load a save part-way through, pause, View Totals, and step through the worlds
  2. The table now has a green NOW column: how many of what is left you can get with the moves, transformations and areas you have now. "-" means none yet; Notes count in notes
  3. Under the table: "MORE TO GET HERE" (green) when something can be got, "MOVE ON FOR NOW" (yellow) when the rest needs something you don't have yet, "ALL DONE HERE" when the world is finished
  4. Game Totals shows "NEW WORLD READY" when you have the Jiggies for the next world Jiggywiggy hasn't opened
  5. Learn a move or pay Mumbo or Humba a Glowbo, then look again: rows that needed it gain NOW numbers
- Look for: A world that says MOVE ON FOR NOW while you know something there can be got (or the other way round): tell me the world and the item and I'll check its rule. Moves count as gettable when you have enough notes for Jamjars and can reach the silo. A Glowbo not yet given to Mumbo or Humba counts as one you can give
- Status: waiting for L

## T166 Android: build the APK and reach the title screen
- Asked: 2026-10-15 UTC
- Build: build it yourself from latest main in Android Studio (BUILDING.md, "Android" section). The cloud box cannot download Google's Android tools, so this APK has never been built yet.
- Steps:
  1. Install Android Studio. In Tools > SDK Manager > SDK Tools, tick NDK (Side by side) 27.2.12479018 and CMake 3.22.1
  2. Open the `android` folder in Android Studio, connect the phone with USB debugging on, and press Run (the first build takes a while)
  3. Pair a controller with the phone
  4. When the app asks, pick your Banjo-Tooie ROM
- Look for: Does the build finish? Does the game reach the title screen with picture and sound, and does Start on the controller work? If the build fails, send the first red error from Android Studio's Build window. If the app closes, send `logs/console.log` from Android/data/io.github.locme.banjotooie/files on the phone. Touch controls are on screen (first guess at the layout): does the stick and A/B/Start respond, and do they cover the picture badly? Tell me your phone model and Android version. Switching away from the app mid-game may close it.
- Status: waiting for L

## T165 Test room
- Asked: 2026-10-15 UTC
- Build: latest Windows build from main
- Steps:
  1. General > Developer > More game memory is On (the default)
  2. Load a save, open Warp, pick Test > Test room (the last entry)
  3. Stand still while the rows fill in front of Banjo (a few seconds), then walk along them; walk up to a statue in the front row to turn into that form
- Look for: rows of objects, characters and enemies, each idling on its spot, and 14 statues showing the transformations. Does the game stay up? Which ones look wrong, T-pose or float? 58 actors are left out because they crash outside their own level (list in notes/test-room.md and test_room_actors.inc).
- Status: waiting for L

## T164 Asset dump and model replacement (roadmap 4.88)
- Asked: 2026-10-15 UTC
- Build: latest Windows build from main
- Steps:
  1. General > Developer > Dump assets on. Wait for the "Assets dumped" notice, then open the `asset_dump` folder in the app-data folder (next to `screenshots`)
  2. Make a folder `mods/assets` in the app-data folder. Copy `asset_08C1.bin` from asset_dump into it and rename the copy `asset_065E.bin` (any model file renamed to another model's id works)
  3. Load a file in Spiral Mountain (or warp there)
- Look for: about 10,000 files in asset_dump plus assets.txt. In Spiral Mountain, part of the ground (model 065E) is drawn as water (model 08C1) instead. Remove the file afterwards. Tell me which model you want to replace first.
- Status: waiting for L

## T163 3D grass (roadmap 4.47)
- Asked: 2026-10-15 17:05 UTC
- Build: latest Windows build from main
- Commit: "3D grass" on main
- Steps:
  1. Graphics > Photo Filters on, then 3D grass to 100 (3D grass height 100, 3D grass distance 2500)
  2. Spiral Mountain: walk onto the meadow by Klungo and stand still, then walk around
  3. Isle o' Hags (Jinjo Village) and Mayahem Temple's courtyard: look at the grass from up close and far away
  4. Change 3D grass height and distance while playing, then set 3D grass to 0
- Look for: Short blades on the green ground that sway a little, flattened in a small circle round Banjo's feet. None on characters (Klungo, Grublins), walls, rock, paths or water. They shrink away with distance instead of popping. Changes apply at once and 0 is the plain ground again. Frame rate with it on? A few blades on paths with green in them (moss between Mayahem's cobbles) are expected.
- Status: waiting for L

## T162 Faster rendering (Frame Read-Back off)
- Asked: 2026-10-15 UTC
- Build: latest Windows build from main
- Steps:
  1. Set Frame rate overlay to Full and note the fps and Input latency in a busy spot (Spiral Mountain, Jinjo Village, Witchyworld)
  2. Graphics > Frame Read-Back is Off (the default). Compare with it On in the same spot (it changes live)
  3. With it Off, play through things that reuse the picture: pause menu, a level change (jigsaw), Bottles' revenge or any flashback, photo mode, a boss intro
- Look for: higher fps and lower Input latency with it Off? Anything black, frozen or showing an old picture with it Off that is right with it On? If so, where.

## T161 Benchmark key (F4)
- Asked: 2026-10-15 16:46 UTC
- Build: latest Windows build from main
- Steps:
  1. Stand somewhere busy (Spiral Mountain by the waterfall), press F4, play or stand still for about 30 s, press F4 again
  2. Change one setting (for example Bloom or SMAA) and do the same at the same spot
  3. Open the two .txt files in the benchmarks folder next to the exe
- Look for: A toast when it starts and one naming the saved file. The .txt shows the average fps, 1% low, GPU time with each pass, and your settings; the .csv opens in a spreadsheet with a row every quarter second. Do the two runs show the setting's cost? Send them over if you'd like me to read them.
- Status: waiting for L

## T160 Totals checklist, step 1: what is left
- Asked: 2026-10-15 16:55 UTC
- Build: latest Windows build from main
- Commit: "Totals checklist, step 1" on main
- Steps:
  1. Load a save, pause, View Totals
  2. Each world's page has a small "LEFT HERE" table in the middle: Jiggies, Honeycombs, Pages (Cheato), Glowbos, Notes, Jinjos and Moves (Jamjars), each with how many are left in that world, or a yellow DONE
  3. Game Totals has the same table as "LEFT IN THE GAME"
  4. Check one world against what you know you have: the numbers should be the world's total minus the page's own counters
  5. Esc > QOL > Totals checklist: Off. The table is gone; turn it back On
- Look for: Does the table cover any of the game's counters with your aspect ratio (widescreen on and off)? Is the text big enough to read?
- Next steps (not in this build): a "NOW" column with how many you can get with the moves you have, a "time to move on" line, and A on a row for the list with hints
- Status: waiting for L

## T159 Shaders kept between sessions (roadmap 4.32)
- Asked: 2026-10-15 16:32 UTC
- Build: latest Windows build from main
- Steps:
  1. Overlay on Full (F3). Start the game, play into two or three areas, quit
  2. Start again and go back to the same areas
- Look for: The second start, "Shaders compiled" jumps right at the start (the saved shaders compiling in the background) and then stays near 0 in the areas you visited before; first visits that hitched should hitch less. The list is cache\shader_list.bin next to the exe; deleting it starts over. Tell me if the game takes longer to start or anything looks different.
- Status: waiting for L

## T158 Low Input Latency
- Asked: 2026-10-15 UTC
- Build: latest Windows build from main
- XBLA history: report §4.31
- Steps:
  1. Graphics > Low Input Latency is On (the default). Set Frame rate overlay to Full
  2. Play for a minute at your usual settings: jump, turn the camera, run around
  3. Switch Low Input Latency Off and play the same minute, then back On (it changes live)
- Look for: does Banjo answer the buttons and stick a little quicker with it on? Any flicker, a frame jumping back, or a torn picture with it on that is not there with it off? (The overlay's Input latency figure can't show this change: it was measuring from the wrong frame before, so compare by feel.)

## T157 Frame rate overlay: GPU time of each effect (roadmap 4.43)
- Asked: 2026-10-15 16:07 UTC
- Build: latest Windows build from main
- Steps:
  1. Overlay on Full (F3)
  2. In Spiral Mountain, turn Bloom, SMAA and Eye adaptation on and off in Graphics, and open photo mode (F10) with a filter
- Look for: Two lines under the GPU time: "GPU 3D effects: ..." and "GPU screen passes: ..." (renamed from "GPU per frame shown"), each listing only the passes that ran, in ms. A pass you turn off should disappear from its line, and the numbers should add up to less than the GPU line. Tell me which one is biggest on your PC; that's the effect costing the most.
- Status: waiting for L

## T156 Texture dump and texture sweep
- Asked: 2026-10-15 UTC
- Build: latest Windows build from main
- Steps:
  1. Load a spare save file (the sweep warps everywhere and the game may save in odd places)
  2. General > Developer > Texture dump: While playing. Walk around for a minute, then open the `texture_dump` folder in the app-data folder (next to `screenshots`)
  3. Set it to Sweep all maps, close the menu and leave it running (about 40 minutes; a notice shows each map)
  4. Afterwards set it to Off
- Look for: `texture_dump/png` fills with PNGs that look like the game's textures, and `rt64.json` is there. During the sweep, each map loads, the camera turns around, and it moves on; at the end it says "Texture sweep finished" and goes back where you started. If the game crashes in a map, load the file again with the option still on: it should carry on from the next map. Send `texture_dump/sweep.txt` either way.

## T155 More game memory: 48 sound voices, 8x drawing buffers
- Asked: 2026-10-15 UTC
- Build: latest Windows build from main
- Steps:
  1. General > Developer > More game memory on (the default), start the game
  2. Play somewhere loud and busy (Witchyworld, a boss fight, lots of eggs and enemies at once), with Sound > Mix rate on Original, then on High (restart after changing it)
  3. Switch More game memory off, restart, and play the same spot
- Look for: with it on, sounds that used to cut out or skip in busy moments now play; music keeps all its instruments. No crackle, missing sounds or crashes. With it off, the game sounds as before.
- Status: waiting for L

## T154 Heap crash guard
- Asked: 2026-10-15 UTC
- Build: main @ 7c099f9
- Steps:
  1. Play the way you were when it crashed (120 FPS, Display interpolation, More game memory on)
  2. If the game carries on where it would have crashed, send logs/console.log
- Look for: no crash at func_8001C0A0 / find_free_block; any `[heap]` lines in console.log say where the damage was, which helps find what writes over the heap
- Status: waiting for L

## T153 HD Shadows off for Banjo only
- Asked: 2026-10-15 11:58 UTC
- Build: 8340566
- Steps:
  1. Graphics: HD Shadows on, HD Shadows: Banjo = Off
  2. Play a level with enemies (Spiral Mountain grublins)
  3. Switch Banjo between Off, Overhead and Tilt while playing
- Look for: With Off, Banjo has the game's simpler shadow while enemies keep their HD shadows; Overhead/Tilt bring his HD shadow back at once
- Status: waiting for L

## T152 Bottles' glow without the box, and a Model Effects key
- Asked: 2026-10-15 UTC
- Build: main @ 113fd0d
- Steps:
  1. Turn the effects on as you play (ambient occlusion, outlines, fog, bloom; any preset)
  2. Watch Bottles' ghost (the Bottles' Revenge intro in Spiral Mountain, or wherever you saw it)
  3. Controls > Debug: bind Pick Model and Model Effects; pick anything else that looks wrong under the effects and press Model Effects (the toast says effects off); Save Tags keeps it
- Look for: no box or straight edges around his glow and the picture behind it stays sharp, with the effects still on everywhere else; a model you turn off is drawn plain with nothing else changing; tell me if the box still flashes for a moment while the angel turns into the devil
- Status: waiting for L

## T151 Custom blend mode as the default: models snap, characters vertex blend, particles taggable
- Asked: 2026-10-15 10:51 UTC
- Build: main @ d085dcd
- Steps:
  1. Start the game: Graphics > Debug shows the blend mode on custom
  2. Play CCL and a busy level: props and the sky snap to the game's frames, the camera blends, and every character (NPCs, enemies, bosses, Banjo) blends smoothly with no stretched triangles
  3. Pick a fire or dust effect with Pick Model: it highlights green and the toast says particle; Tag Model gives it vertex or snap and the change shows at once
  4. Tag any character that still looks wrong and send interp_tags.txt
- Look for: Characters smooth, props crisp, no tears; whether the rule picked up every character (a 'character' is a model with two or more bones, so a one-piece enemy or NPC would snap: tag it and tell me which)
- Status: waiting for L

## T150 HD Shadows in widescreen: shadows land under characters
- Asked: 2026-10-15 00:56 UTC
- Build: main @ 75bfb6b
- Steps:
  1. Window or fullscreen at 21:9 (also try 16:9)
  2. Graphics: HD Shadows on
  3. Stand so Banjo is off to one side of the screen (turn the camera), and look at enemies near the left and right edges
- Look for: Banjo's and enemies' shadows are whole and sit under them anywhere on screen; no cut-off shadow or dotted light patch beside Banjo
- Status: waiting for L

## T149 Manual tags round 2: highlight fixed, custom blend mode, Save and Unsave Tags, Debug keys unbound
- Asked: 2026-10-14 23:03 UTC
- Build: main @ 6787f75
- Steps:
  1. Controls > Debug: every key there starts unbound; bind Pick Model, Tag Model, Save Tags, Unsave Tag (and any other debug key you use)
  2. Pick Banjo: the whole model goes green with nothing else drawn wrong, in default, snap or vertex alike
  3. Tag Model: the toast names the new tag and the blend mode goes to custom on the first press (Graphics > Debug shows it); normal shows the game without your tags
  4. Pick a tagged model again: the toast says saved, not saved yet, or saved as another tag
  5. Save Tags writes interp_tags.txt; Unsave Tag removes the picked model's tag from the game and the file
- Look for: No yellow quads or broken parts while a model is highlighted; the tags only show in custom; the saved note on the pick toast is right
- Status: waiting for L

## T148 Effect debug view list scrolls with a controller
- Asked: 2026-10-14 23:05 UTC
- Build: main @ 8519906
- Steps:
  1. Open the menu with the controller, Graphics, down to Debug > Effect debug view
  2. Open the list and hold down on the D-pad or stick to the bottom (Only: texture upscaling), then back up
- Look for: The list scrolls so the highlighted entry stays on screen all the way down and back up
- Status: waiting for L

## T147 Unlocked sound crash: does the game keep running now?
- Asked: 2026-10-14 22:45 UTC
- Build: your local build of main
- Commit: 0ba964f
- Steps:
  1. Graphics: Game Frame Rate Unlocked (Experimental); play as you did when it crashed (the music player too) for 10 minutes or more
  2. Send the session log afterwards, even if nothing went wrong
- Look for: Does the game keep running where it used to close with "Unhandled jump target ... in n_aspMain"? If the sound glitches, the log now has "[audio] A sound task failed" and maybe "[audio] A sound list changed between being queued and playing"; those lines tell me the cause. Does the sound recover after a glitch?
- Status: waiting for L

## T146 HD Shadows: Tilt or Overhead for enemies and for Banjo
- Asked: 2026-10-14 22:20 UTC
- Build: main @ 628ee89
- Steps:
  1. Graphics: HD Shadows on; the two new options HD Shadows: Enemies and HD Shadows: Banjo appear under it, both Overhead
  2. Set both to Tilt and stand near a Grublin in Pine Grove
  3. Turn the camera around, and switch each back to Overhead
- Look for: Tilt: shadows fall beside Banjo and the Grublin, in the same direction for both, and stay put when the camera turns. Overhead: as before. Each option only changes its own shadows
- Status: waiting for L

## T145 Manual interpolation tags: pick a model with F11, tag it with F4
- Asked: 2026-10-14 22:14 UTC
- Build: main @ db5eb54
- Steps:
  1. Above Original frame rate, stand near a model (the CCL sky dome, a character) and press F11: it turns green and a toast names it; F11 again steps to the next model on screen
  2. Press F4: the toast says the model's new tag (snap, vertex, untagged, back to default) and the game writes interp_tags.txt next to the save files
  3. Tag the sky dome snap and the model that tore before; check that the tag changes what you see at once, and that it is still applied after a restart
  4. Send interp_tags.txt here when a set of tags looks right, to be built in as the default
- Look for: The highlight follows the picked model (the backpack and textured parts go dark green), F4 steps the tag live, and the file lists each tag with the map and position it was made in
- Status: waiting for L

## T144 HD Shadows: eggs and objects no longer vanish (also ultrawide)
- Asked: 2026-10-14 22:05 UTC
- Build: main @ d47f9e7
- Steps:
  1. Graphics: HD Shadows on
  2. Play Mayahem Temple near egg nests, and Pine Grove at 21:9
  3. Walk around for a few minutes
- Look for: Eggs, notes, boxes and characters stay on screen; nothing pops out and back
- Status: waiting for L

## T143 Debug section and every F-key in Controls
- Asked: 2026-10-14 22:10 UTC
- Build: main after this commit
- Steps:
  1. Esc > Graphics, scroll to Debug: Effect debug view, Effect compare, Interpolation check, Interpolation blend mode
  2. Pick a blend mode from the list, turn the check on, and press F7 and F6 in game: the menu values should follow the keys
  3. Esc > Controls: look for Hide HUD (F1), Screenshot (F12) under Hotkeys and Effect Debug View, Effect Compare, Interpolation Check, Blend Mode, Warp Again under Debug; rebind one and try it
- Look for: Do the dropdowns and switches work and follow the keys? Do all the F keys show up and rebind? Changed: F8 is now only Effect Compare. The old F8 blend cycling moved to F5 (the Blend Mode key).
- Headless: F7 and F1 with their default keys showed their notices; the new options saved and applied. Not tried: rebinding, F6, F9, F12, controller bindings.
- Status: waiting for L

## T142 Interpolation without vertex blending: sky, close-up spins, characters
- Asked: 2026-10-14 21:19 UTC
- Build: main @ 2a0f638
- Steps:
  1. Pull, build, Interpolation on at your usual settings, F8 left at normal (press F7 once if anything is tinted red)
  2. Spiral Mountain and Cloud Cuckooland: free camera up to Banjo, spin, 2 minutes each; also walk around Jolly Roger's Lagoon
  3. Watch Banjo, Kazooie and a few enemies up close while they animate
- Look for: No torn sky, quads or black boxes during spins; characters still blend smoothly (no low-fps look); nothing that moved smoothly before now steps
- Status: answered 2026-10-14 21:54 UTC
- L's result: L (2026-10-14 21:53): resolved. Interpolation without vertex blending (2a0f638) fixed the tears.

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

## T139 Noclip goes through walls; Tiptoe under Movement
- Asked: 2026-10-14 20:25 UTC
- Build: main after this commit
- Steps:
  1. Esc > Cheats: Enable cheats, Noclip = On, load a save
  2. Walk into a wall, a cliff and a closed door; hold LT (Z) to sink through the floor and RT (R) to rise
  3. Esc > Controls: look for Tiptoe under Movement (next to Run), not Hotkeys
- Look for: Banjo walks straight through walls and scenery instead of stopping at them. Cause was that the game keeps its own "last valid position" for collision, which Noclip did not write, so walls pulled Banjo back. Headless in Mumbo's Skull, Banjo walked through the back wall (before: stopped at it). Not tried in water, doors with locked rooms or with Kazooie split up.

## T138 Unlocked / 120 FPS: sound keeps working, no sound crash
- Asked: 2026-10-14 20:30 UTC
- Build: your local build of main
- Commit: 1256297
- Steps:
  1. Graphics: Game Frame Rate Unlocked (Experimental), Interpolation Off; play for 10 minutes or more in a few levels (talk to someone, enter a level, a cutscene)
  2. Same for 5 minutes with 120 FPS (Experimental)
- Look for: Does the sound keep playing the whole time, and does the game no longer crash with "n_aspMain unhandled jump"? If it still breaks, send the session log and say roughly how many minutes in. Headless, Unlocked ran 3 minutes without a crash both before and after this fix, so I could not reproduce your crash here.
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

## T135 Water and underwater effects drawn once
- Asked: 2026-10-14 17:28 UTC
- Build: main @ bd142ac
- Steps:
  1. Graphics: Water reflections 50, Water waves 50, Underwater tint 25, haze 15, distortion 30
  2. Swim in the Spiral Mountain moat on top, then dive
  3. Watch the water from above and below
- Look for: The water and the underwater look show once, with no doubled or ghosted water and no tint that builds up; frame rate a little higher
- Status: waiting for L

## T134 Torn frames: renderer wait and interpolation id clashes
- Asked: 2026-10-14 17:15 UTC
- Build: main @ f709884
- Steps:
  1. Pull, build, play 10 minutes in Spiral Mountain and Cloud Cuckooland, spin the camera a lot, at Original FPS and at 60
  2. Do it once with Interpolation Off and once with your usual settings
  3. After any tear, hold F12 for a burst (let go after the tear) and look in the log for a line starting with [dl]
- Look for: Whether the 1-2 frame tears and black patches still happen, how often compared with before, and whether any [dl] line appears in the log
- Status: answered 2026-10-14 21:19 UTC
- L's result: 2026-10-14: still tore with interpolation on; L's F8 bisect found vertex blending at fault; fixed 2a0f638 (vertex blending off)

## T133 Bounce light without dotted noise
- Asked: 2026-10-14 17:11 UTC
- Build: main @ ada3c63
- Steps:
  1. Graphics: Bounce light 100, your usual resolution
  2. Look at Banjo up close and at a honeycomb against grass
- Look for: No fine grid of dots over Banjo's fur, skin or the background. Colours from nearby walls and floors still tint what is next to them.
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

## T129 Underwater distortion, tint and haze on D3D12 (no more coloured blob grid)
- Asked: 2026-10-14 16:29 UTC
- Build: main @ 076ce62 (also covers T128)
- Steps:
  1. Graphics: keep D3D12, Underwater tint 25, haze 15, distortion 30
  2. Spiral Mountain: dive where your blob screenshot was (Banjo at 1178, -377, 471) and in the moat
  3. Also turn on Water reflections and look at a pool from above
- Look for: The 3D world shows through, light blue and gently wobbling, with no grid of coloured blobs and no flat dark blue screen; reflections show the scenery
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

## T127 HD Shadows spikes at high refresh
- Asked: 2026-10-14 16:10 UTC
- Build: main @ next commit
- Steps:
  1. Graphics: HD Shadows on, Interpolation Display (your 175 Hz)
  2. Spiral Mountain: walk and stand around on the sloped grass by the molehills, where the shadows are long
  3. Also turn the camera so you see Banjo's shadow from the side
- Look for: The shadow keeps Banjo's shape and moves smoothly, with no long pointed spikes or broken triangles. The overlay's 'Interpolation on' line now counts the shadows (was 0 shadows).

## T126 Exploding models and black flashes (frame read race)
- Asked: 2026-10-14 14:11 UTC
- Build: main @ e895a40
- Steps:
  1. Build main at e895a40 or later
  2. Load a save that starts in Jinjo Village, and play a while in Jinjo Village and Mayahem Temple with your usual settings (HD Shadows on)
  3. Warp to Cloud Cuckooland from the menu and spin the camera for a minute
- Look for: Do models still explode into giant shapes, and does the screen still flash black?
- Status: answered 2026-10-15 15:59 UTC
- L's result: resolved

## T125 Water waves react to Banjo; effects measure distance right
- Asked: 2026-10-14 12:20 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Graphics: Water waves 50 or more, Water reflections 100
  2. Spiral Mountain: jump into the stream by the tunnel, swim up and down it, stop, then wade in the shallow edge
  3. Also look over Fog, Depth of field and Ambient occlusion in a couple of places
- Look for: Rings spread from where Banjo is (not behind him), a big splash ring when he jumps in, a V-shaped wake with a little foam behind him while he swims, and a small ring bobbing round him when he stops. No rings when he walks on dry land. The effects were reading the depth about twice too far, so fog may now start a little further out and focus sits right on Banjo.
- Status: waiting for L

## T124 Toon outline thickness goes to 200
- Asked: 2026-10-14 11:40 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Graphics: Toon outlines 100, then Toon outline thickness 25, 100, 200
- Look for: 25 is the old thin line, 100 the old thickest, 200 a bold cartoon line twice that. Thin things like posts keep their line attached. A saved thickness of 1 to 4 carries over as 25 to 100.
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

## T120 Extras stop before the game's drawing memory is full
- Asked: 2026-10-14 11:25 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Graphics: HD Shadows On, Extended Draw Distance On
  2. Play Mayahem Temple and Witchyworld, turning the camera around
- Look for: No torn geometry, exploding models or crash. Far objects or extra shadows may now be left out in very busy views, as the game's own drawing comes first. If something still breaks, send the crashes.log or console lines starting with "[gfx]".

## T119 Underwater look stays on while swimming fast (from your 10:48 list)
- Asked: 2026-10-14 12:35 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.45
- Steps:
  1. Graphics: Underwater tint 25, Underwater haze 15, Underwater distortion 30 (distortion now sits right under haze)
  2. A deep stretch of water where the camera follows Banjo under (Jolly Roger's Lagoon, the lake outside Atlantis): dive, then swim fast (tap A), turn, roll, and come back up
- Look for: The tint, haze and wobble stay on the whole time the camera is under the water, however Banjo swims, and go when it comes up. Note: in the small Spiral Mountain pool the game keeps the camera above the surface even when Banjo is at the bottom, so there is rightly no tint there.
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

## T117 Achievements list scrolls with Down (from your 10:48 list)
- Asked: 2026-10-14 11:10 UTC
- Build: your local build of main from 2026-10-14 11:10 UTC or later
- Steps:
  1. Esc > Achievements
  2. Press Down on the controller (or the arrow key) until the last achievement
- Look for: Does a highlight move from one achievement to the next, and does the list scroll so the highlighted one stays on screen?
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

## T115 Effect performance and bounce light (from your 09:15 list)
- Asked: 2026-10-14 11:45 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.45
- Steps:
  1. Frame rate overlay on. Graphics: Ambient occlusion 50, Bounce light 100, Light shafts 100, Rim light 50
  2. Jolly Roger's Lagoon town and Spiral Mountain; compare the frame time with each one on and off (or use F6 "Only" views)
- Look for: Headless (CPU renderer, so only the proportions count) the extra cost dropped by about 80% for light shafts, 40% for bounce light, 25% for ambient occlusion, 15% for rim light. Bounce light is stronger now: colourful walls and floors tint what is next to them, dark corners take on the colour around them. No speckle or shimmer?
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

## T113 Fog measured from Banjo (from your 09:15 list)
- Asked: 2026-10-14 11:45 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.45
- Steps:
  1. Graphics: Fog 60
  2. Stand still in Spiral Mountain and zoom the camera in and out, and swing it round
- Look for: How fogged things are stays the same as the camera moves; it only changes as Banjo moves. Things right by Banjo stay clear even with the camera far back.
- Status: waiting for L

## T112 Film grain size (from your 09:15 list)
- Asked: 2026-10-14 11:45 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.45
- Steps:
  1. Graphics: Film grain 50, at your usual resolution
- Look for: Grain you can actually see: soft clumps about two pixels across at 1080p (bigger at higher resolutions), strongest in the mid tones.
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

## T110 Frame rate overlay: shader compiles and game CPU time
- Asked: 2026-10-14 10:24 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Turn the overlay to Full (F3 or Esc > Graphics)
  2. Enter a level you haven't visited this session, then walk around a busy part of one
- Look for: A "Shaders compiled: N in 5 s, M this session" line under the 1% low. It should jump when you enter somewhere new and fall back to 0 in 5 s; going back to the same place should add few or none. The "Game" line now ends with "CPU X ms per frame (busy Y%)". On a normal PC expect a few ms and a low busy %; tell me if it ever goes near the frame time (33 ms at 30 fps) or 100%.
- Status: waiting for L

## T109 Random crash right at game start (VI thread)
- Asked: 2026-10-14 10:19 UTC
- Build: main after this commit (build it yourself)
- Steps:
  1. Start the game 10 times in a row, closing it each time once the title or file select shows
- Look for: Does it ever crash or close by itself while starting? If so, attach the newest crash_*.dmp and logs/crashes.log.

## T108 Heat haze (from your 09:15 list)
- Asked: 2026-10-14 11:10 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.45
- Steps:
  1. Graphics: Heat haze 50, then 100
  2. Hailfire Peaks lava side, then its train station; also try a different resolution
- Look for: The air shimmers in smooth waves that rise, starting a short way from the camera and stronger further off. No blocky or stair-step shimmer, and the waves look the same size at any resolution. Banjo and nearby edges stay steady. None on the icy side.
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

## T105 Frame rate overlay: input latency
- Asked: 2026-10-14 09:45 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Turn on the overlay (F3 or Esc > Graphics) in Compact, then Full
  2. Play a minute with Framerate at Original, then at Display (or Manual at your monitor's rate)
  3. If you can, try with V-Sync or a frame cap on and off in your GPU driver
- Look for: The first line ends with "input N ms", and Full has an "Input latency" line under the frame time. Does the number go down when the frame rate goes up, and up when the game stutters? A value near 2 to 3 frame times is normal. Does it feel like it matches how responsive the game feels? It leaves out your monitor's and controller's own delay.
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

## T100 Crash in play (10:33 dump) and the boot crash
- Asked: 2026-10-14 10:00 UTC
- Build: your own build from main (ac1c6ec or later)
- Steps:
  1. Start the game 5 times in a row; each start should reach the title.
  2. Play as you did around 10:33 (whatever you were doing when it crashed).
  3. Afterwards, open logs/console.log next to the exe and search for "[rt64]".
- Look for: No crash at start or in play. If console.log has an "[rt64] Unknown microcode" line, send it: it says which graphics code the game used, so the picture glitch it may cause can be fixed too.
- Status: waiting for L

## T99 Settings menu tidy-up
- Do: Open Settings (Esc). Go through General, QOL, Graphics and Cheats. In Graphics open the Resolution row. In the Warp tab (Cheats > Warp tab) hold Down on a controller. Open the Search tab and type a word (for example shadow or speed).
- Look for: section headings in each tab; Cheato codes are in Cheats again; Resolution lists 3x (720p), 4.5x (1080p), 6x (1440p) and 9x (4K); Field of View and Game Frame Rate apply as soon as you change them (Apply stays grey); the Warp list scrolls with the selection; Search shows matching options from every tab and you can change them there; each Cheato code in Cheats has a fuller description; Texture upscaling's description says it uses an xBR-style filter.
- Not done: controller scrolling was only checked with the keyboard; the Cheato descriptions were written from the game's own cheat names, so check them against what each code does.
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

## T95 Water waves
- Asked: 2026-10-14 07:27 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.46 (not built on XBLA)
- Steps:
  1. Esc > Graphics: set "Water waves" to 50, then 100; try "Water wave speed" 50 and 200
  2. Look at calm water: the Spiral Mountain pool behind the waterfall, Jolly Roger's Lagoon, Cloud Cuckooland's pools
- Look for: Waves roll across the water in one main direction, the water seen through bends with them, and their slopes catch the light. Do they stay put on the water when you turn the camera (they shouldn't slide with it)? Too strong, too busy, or shimmering far away?
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

## T89 Vulkan is the default Graphics API
- Commit: 3516154
- Do: Close the game, move graphics.json out of the game's folder (or delete it), start the game, press F3 until the overlay is in Full mode.
- Look for: the renderer line says Vulkan. In Settings > Graphics the Graphics API row shows Vulkan, and the choices are Vulkan and D3D12 (no Auto).
- Note: your saved graphics.json has Auto, which is not migrated. Open the Graphics API row and pick Vulkan once.
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

## T76 Models stretching for a moment
- Asked: 2026-10-14 05:55 UTC
- Build: latest Windows CI build from main (after the "repeated parts" interpolation fix)
- Commit: 7a025d1
- Steps:
  1. Play at your usual frame rate above Original (170)
  2. Walk around the places where you saw meshes suddenly stretch, and the Cave of Horrors where the black artifacts were
- Look for: Do models still stretch into a broken shape for a moment? Do the black artifacts still appear? If yes, where, and on which model?
- Status: answered 2026-10-15 15:59 UTC
- L's result: resolved

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

## T70 Beak Barge volume with the right stick (check only)
- Asked: 2026-10-14 03:05 UTC
- Build: latest Windows CI build from main
- Commit: baeb352
- XBLA history: report §4.66 (on XBLA the Beak Barge whoosh got quieter with the right stick held forward, not backward)
- Steps:
  1. Do a Beak Barge (Z + B on the ground) a few times while holding the right stick forward, then backward, then not at all
- Look for: Does the whoosh get quieter with the stick forward here? If yes, the N64 game does it too and it stays. If not, it was the XBLA port and nothing needs doing
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

## T54 Save Game Select smoothness
- Asked: 2026-10-13 23:55 UTC
- Build: latest Windows CI build from main
- Commit: a9b1817, 5fd696e
- Steps:
  1. Frame rate at your usual 170 fps
  2. Open the Save Game Select screen and watch the hand waving in picture 1, and the pictures
- Look for: Does the hand's wave look smooth now? The pictures' small shake should stay quick and crisp, as before (it is drawn at the game's own rate on purpose). Anything stretched or jumping?
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

## T51 Back-Port: Get Jiggy animation
- Asked: 2026-10-13 23:25 UTC; 2026-10-14 20:35 UTC L: it never played on a real Jiggy, so the swap now happens inside the pose's own start
- Build: your local build of main from 2026-10-14 20:35 UTC or later
- Steps:
  1. Esc > General: Back-Port: Get Jiggy animation on
  2. Collect a Jiggy (as Banjo and Kazooie)
  3. Turn it off and collect another one
- Look for: With it on, does Banjo do BK's dance (fist pumps, Kazooie pops out at the end) under Tooie's black bars, and does the game carry on normally afterwards? Is it the right dance as you remember it from BK? Does any other item (Cheato page, Jinjo, Glowbo) wrongly get the dance too? Only checked here by starting the pose without a real Jiggy.
- Status: failed 2026-10-14 (never triggered); fix waiting for L

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

## T49 SMAA Anti-Aliasing
- Asked: 2026-10-13 23:00 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Esc > Graphics: MS Anti-Aliasing None, SMAA Anti-Aliasing High, and close the menu
  2. Stand somewhere with straight edges against the sky or grass (Spiral Mountain's cliffs and posts) and switch SMAA between Off and High a few times
  3. Try Low and Ultra, then MSAA 2X or 4X together with SMAA High
- Look for: Are the stair-steps on edges smoothed with SMAA on, without the picture going blurry? Does it change at once when you switch it? Does it work with MSAA on, and does the frame rate drop noticeably at Ultra? Only checked here with software rendering on Vulkan; D3D12 wasn't tested.

## T48 Back-Port: Glittering honeycombs
- Asked: 2026-10-13 22:50 UTC; reworked 23:30 UTC to match Banjo-Kazooie (L: "it works, but its not good", then picked "Match BK")
- Build: latest Windows CI build from main
- XBLA history: report §4.63
- Steps:
  1. Settings (Esc) > General > Back-Port: Glittering honeycombs = On (off by default)
  2. Find a health honeycomb (Spiral Mountain has three in a cave; enemies and beehives drop more)
- Look for: The glints now flash on the comb itself, at its edges, like in Banjo-Kazooie, instead of in the air around it. Is that closer? Too many or too few? Does switching the option off stop it?
- Status: waiting for L

## T47 Resolution 720p, 1080p, 4K
- Asked: 2026-10-13 22:40 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Settings (Esc) > Graphics > Resolution: pick 720p, then 1080p, then 4K, then Auto
- Look for: Does the picture get sharper with each step (4K may be slow on weaker GPUs)? Does your choice stay after a restart? The window size itself does not change; this is the resolution the game is drawn at.
- Status: waiting for L

## T46 Back-Port: Old Banjo sounds
- Asked: 2026-10-13 22:40 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Esc > General: turn on Back-Port: Old Banjo sounds
  2. Load a save and jump a few times, then twirl-jump and flap
  3. Turn the option off and jump again
- Look for: With it on, are Banjo's jump grunts the Banjo-Kazooie ones? With it off, are they Banjo-Tooie's again? I could only check headless that the jump sound table holds the old ids; there is no audio here.
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

## T44 Fine aim
- Asked: 2026-10-13 22:31 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.57
- Steps:
  1. Esc > QOL > Fine aim = Always, Fine aim speed = Medium
  2. Load a file, press C-up for first person and turn with the left stick. Try a small and a full push
  3. Try Hold R (turn with and without R held), and the Slow and Fast speeds
- Look for: Is turning slower but still smooth, with no stick range where nothing happens? Does R do anything else in first person that this gets in the way of? Breegull Blaster sections weren't tested.

## T43 Picture shape jump when a cutscene starts (ultrawide)
- Asked: 2026-10-13 22:31 UTC
- Build: main after 8840cdc (next Windows CI build)
- Steps:
  1. Set Aspect Ratio to Expand on a 21:9 screen and Frame rate above Original
  2. Pick up an item whose first pickup starts a scene (a Cheato page, say), or start any cutscene with black bars
  3. Watch the first moment of the scene
  4. Do it once more with Frame rate at Original
- Look for: Does the picture keep its shape as the scene starts, or does it still squash or stretch for a moment (and at which frame rate setting)?

## T42 Frame rate overlay
- Asked: 2026-10-13 22:13 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Esc > Graphics: turn on Frame rate overlay and close the menu
  2. Play for a minute with Framerate on Display, then on Original, then on Manual at a few values
  3. Turn the overlay off and on a few times while you play
- Look for: Does the box sit in the top left corner and do its numbers change as you play? Does the frame rate it shows match your monitor (or the Manual value) and drop to about 30 or 20 with Original? Does "Game" stay at about 20 or 30 fps whatever Framerate says? Does turning the overlay on change how smooth the game feels? I could only check it with software rendering here, where it showed no difference beyond normal noise.
- Status: waiting for L

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

## T40 Banjo slides in cutscenes (top priority, L)
- Asked: 2026-10-13 22:11 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Run (don't stand still) into something that starts a talk or cutscene: Klungo going up Spiral Mountain on a new game, a sign where Jamjars or Bottles talks, or a pad
  2. Do it a few more times in different places
- Look for: Does Banjo stop where he is when the scene starts, and stay there until it ends? Does anything else about him look wrong in those scenes?
- Status: waiting for L
- Fix to test (2026-10-13 23:40 UTC, CI build after the "Banjo no longer slides" commit): the game's "stop moving" step for standing and talking was recompiled empty, so Banjo kept his walking speed through the talk at any frame rate. Headless at the Haunted Cavern sign he now stops where Jamjars starts talking, and in Klungo's Spiral Mountain scene started while running (before: he slid over 4000 units) he stops on the spot. Retest steps 1 and 2.

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

## T36 Faster Windows build (full inlining)
- Asked: 2026-10-13 20:40 UTC
- Build: main @ 85773ec or later
- Steps:
  1. Note your fps or how smooth it feels in a busy spot (e.g. Witchyworld or Mayahem Temple) on your current build
  2. Update and build again (update_and_build.bat), then go to the same spot with the same settings
- Look for: Is it the same or faster? Anything that broke or crashes that did not before?

## T35 Banjo's shadow in water
- Asked: 2026-10-13 20:40 UTC
- Build: latest Windows CI build from main (it has the shadow interpolation change from T20's thread)
- Steps:
  1. Load a file and walk into shallow water where Banjo wades (for example the pond in Mayahem Temple's Prison Compound), then swim into deeper water
  2. Stand still for a few seconds, then walk slowly in the water
  3. Do this at Esc > Graphics > Frame Rate = Original (30 fps), then again at your usual frame rate above 30
- Look for: Does the shadow still flicker? If it does: only above Original, or at Original too? Does it blink fully on and off, or do parts of it shimmer at the edges? Wading, swimming, or both?
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

## T27 Jiggy level wipe in ultrawide
- Asked: 2026-10-13 19:40 UTC
- Build: main after 30992ad (next Windows CI build)
- Steps:
  1. Set Graphics > Aspect Ratio to Expand and use a 21:9 (or wider) window or screen
  2. Load a file and enter or leave a level, or use the Warp tab
  3. Watch the Jiggy-shaped wipe that opens the picture
- Look for: Does the Jiggy hole grow until the whole wide screen is clear, with no black left at the sides when it disappears?
- L's result: L, 2026-10-14: fixed

## T26 Stop 'n' Swop items
- Asked: 2026-10-13 19:30 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.68
- Steps:
  1. Esc > Cheats, turn on Enable cheats, then Stop 'n' Swop items
  2. Load a file, go to Spiral Mountain and the Isle O' Hags, and look for the mystery eggs (blue and pink)
- Look for: Do the blue and pink mystery eggs appear or become collectable? This is only a flag set; I could confirm the flags but not that the game shows the eggs, so expect partial results.
- Status: waiting for L

## T25 Tiptoe key
- Asked: 2026-10-13 19:30 UTC, changed 19:55 UTC (now a hotkey in Controls, no longer a QOL setting)
- Build: latest Windows CI build from main
- XBLA history: report §4.56
- Steps:
  1. Load a file. Hold the left stick click (L3) and push the left stick fully in any direction
  2. Esc > Controls > Hotkeys: bind Tiptoe to another button or key and try it
- Look for: Does Banjo tiptoe at any tilt while L3 is held, and run again when you let go? Does the new binding work?
- Status: waiting for L

## T24 Audio glitch sounds
- Asked: 2026-10-13 19:21 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Play normally for 10 minutes or more, in places with music and lots of sound (Spiral Mountain, Mayahem Temple, Witchyworld)
  2. Try the Framerate mode you were on when you heard the glitch
- Look for: Do you still hear the short glitchy or sped-up sound now and then? If yes, which level and which Framerate mode?

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

## T19 Cheato cheats
- Asked: 2026-10-13 18:50 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.70
- Steps:
  1. Esc > Cheats, turn on Enable cheats, then switch on one Cheato row at a time (try SUPERBANJO, FEATHERS, HOMING)
  2. Load a file and play a little, then switch the row off again
- Look for: Does each code do what its name says while on, and stop when off? Does a code you typed in the Code Chamber stay on after the row is switched off? The flag numbers are the N64 ones from the decomp, so any row that does nothing is worth telling me.
- Status: waiting for L

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

## T17 Hide HUD (F1)
- Asked: 2026-10-13 18:25 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.84
- Steps:
  1. In game, press F1, walk around, talk to someone, pause; then press F1 again
- Look for: Do the HUD and text boxes vanish while hidden, and come back after the second F1? Does "HUD hidden" / "HUD shown" show? Anything else that vanishes or stays that should not?

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

## T14 Level warp
- Asked: 2026-10-13 18:05 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.80
- Steps:
  1. Settings > Cheats: turn on Enable cheats, then Warp tab. Load a file, press Esc, open the Warp tab and pick a few places in different levels
  2. Press F9 after leaving the area you warped to
- Look for: Does each warp land you standing in the right place, with the usual wipe? Does F9 take you back to the last pick? Any place that crashes or drops you in a wall? Picking a place from the launcher's Settings, the title screen or the game select should only show "Start the game and load a file first".

## T13 Screenshots (F12)
- Asked: 2026-10-13 17:55 UTC
- Build: latest Windows CI build from main
- XBLA history: report §4.83
- Steps:
  1. In game, press F12, then open the menu (Esc) and press F12 again
  2. Open the screenshots folder next to the exe
- Look for: Does "Screenshot saved" show each time? Is each PNG the game picture only (no menu, no notice), with the right colours and the same shape as the window?
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

## T10 Quick start
- Asked: 2026-10-13 17:10 UTC
- Build: latest Windows CI build from main
- Steps:
  1. Start the game
  2. Press Start while the Rare, Nintendo and Dolby logos show
- Look for: Does it jump straight to the file select with the jigsaw wipe? With Settings > QOL > Press Start Early in Intro off, do the logos play through?
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

## T8 Widescreen edges
- Asked: 2026-10-13
- Build: latest main
- XBLA history: report §4.22
- Steps:
  1. Settings > Graphics: Aspect Ratio = Expand, in a 16:9 (or wider) window
  2. Start a game and walk around Spiral Mountain and Jinjo Village, turning the camera
- Look for: Does the picture fill the window without looking stretched? Do things pop in or vanish at the left and right edges while still on screen?
- Status: waiting for L

## T6 Intro text
- Asked: 2026-10-13 14:01 UTC
- Build: Windows CI run 38416771448 (https://github.com/Locme/Banjo-Tooie-N64-Recomp/actions/runs/38416771448), artifact BanjoTooieN64Recomp-Windows-RelWithDebInfo
- Steps:
  1. Start a new game
  2. Watch the intro text starting Two years have passed
- Look for: Are the letters clean, or do they overlap or get clipped?
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

## T4 Witchyworld music
- Asked: 2026-10-13 14:01 UTC
- Build: Windows CI run 38416771448 (https://github.com/Locme/Banjo-Tooie-N64-Recomp/actions/runs/38416771448), artifact BanjoTooieN64Recomp-Windows-RelWithDebInfo
- XBLA history: report §4.65
- Steps:
  1. Enter Witchyworld
  2. Walk around the park and into a couple of areas for a minute or two
- Look for: Does the music sound right (right notes, pitch and tempo)?
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

## T2 File select and new game
- Asked: 2026-10-13 14:01 UTC
- Build: Windows CI run 38416771448 (https://github.com/Locme/Banjo-Tooie-N64-Recomp/actions/runs/38416771448), artifact BanjoTooieN64Recomp-Windows-RelWithDebInfo
- Steps:
  1. Press Start at the title screen
  2. Pick a file and start a new game
  3. Play for a few minutes: walk, jump, open a menu, change area
- Look for: Does anything crash, freeze, look wrong or sound wrong?
- Status: waiting for L

## T1 Boots to the title screen
- Asked: 2026-10-13 14:01 UTC
- Build: Windows CI run 38416771448 (https://github.com/Locme/Banjo-Tooie-N64-Recomp/actions/runs/38416771448), artifact BanjoTooieN64Recomp-Windows-RelWithDebInfo
- Steps:
  1. Run BanjoTooieN64Recomp.exe, choose Start Game and pick your ROM
  2. Wait for the logo and title screen
- Look for: Does it reach the title screen with picture and sound, without a crash?
- Status: waiting for L

## T258 Back-Port: Original honeycomb
- Asked: 2026-10-16 (L: "Are you able to backport the normal honeycomb from banjo kazooie?", "If it's included don't make it a mod, make it a backport toggle")
- Build: main (pull and build). The "Original Honeycomb v1" mod zip is gone; remove it from your mods folder if you added it.
- Steps:
  1. General > Back-Port: Original honeycomb = On (HoneyComb NB off in the Mods menu: a model mod of the comb wins over the switch)
  2. Go to a health honeycomb (Spiral Mountain's cave has three), then collect one
  3. Switch it off while standing there
- Look for: Step 2, the combs are Banjo-Kazooie's honeycomb (honey faces, a frame round the sides), bobbing and spinning as usual, and collecting one heals. The model is Banjo-Kazooie's own, still in Tooie's game files (unused), built when the comb loads and scaled to Tooie's comb size. Does the frame shine like in Banjo-Kazooie? Headless it reads as a flat pale gold. Step 3, the area reloads and Tooie's comb is back. Checked headless: on, with Glittering honeycombs on too: [backport-on.png](screens/original-honeycomb/backport-on.png); off: Tooie's comb.
- Status: waiting for L

## T255 Texture sweep: "Start the texture sweep?" popup, carries on after a restart
- Asked: 2026-10-16 UTC
- Build: latest Windows build from main
- Steps:
  1. Load a spare save file. DEV > Texture dump: pick Sweep all maps
  2. A popup asks "Start the texture sweep?" and warns that it keeps going after a restart. Press Cancel: the option goes back to what it was and nothing warps
  3. Pick it again and press Start sweep: it starts warping
  4. Close the game mid-sweep and start it again, then load a file
- Look for: after the restart a notice says the sweep carries on, and it goes on from the next map (the map it was in is skipped and listed as skipped in sweep.txt). Setting Texture dump to Off stops it for good.
- Status: waiting for L

## T260 Viva Mumbo Jumbo v3: face and full check
- Asked: 2026-10-16 10:40 UTC
- Build: main, plus mods/Viva Mumbo Jumbo v3.zip from project files (replaces v2; delete the v1/v2 zips and their unpacked folders from the mods folder first)
- Steps:
  1. Put "Viva Mumbo Jumbo v3.zip" in the mods folder as it is and turn on "Viva Mumbo Jumbo"
  2. Play as Mumbo and look at his face close up (photo mode, zoom in): stand still, walk, jump, cast a spell
  3. Go into Mayahem Temple's Mumbo's Skull and talk to him
- Look for: the face matches the Viva model: the grin with both rows of teeth shows while he stands (in v2 the jaw sat shut over the teeth), the striped rings sit round the eye sockets with dark sockets behind the lids, and the brow band and nose holes are where they are on the original. Nothing flickers or shows through round the eyes. Legs, feet and skirt as in v2. Cause: the game's own animations hold Mumbo's jaw about 9 degrees shut, so the jaw is now modelled that much open; the model is also stored 8 times finer, so the eyelids and socket rims keep their exact shape and texture instead of being rounded to whole units. Checked headless with the zip: photo-mode close-up playing as Mumbo, walking, jumping, a spell, and talking in the skull ([v3.png](screens/viva-mumbo/v3.png)). Swimming was not tried.
- Status: replaced by T294 (v4)

## T268 Banjo X Alt v5: eyes open and blinking, straps fixed
- Asked: 2026-10-16 11:30 UTC
- Build: main, plus mods/Banjo X Alt v5.zip from project files (take v1 to v4 out of the mods folder)
- Steps:
  1. Put "Banjo X Alt v5.zip" in the mods folder as it is and turn on "Banjo X (alt rig)" (Smash Banjo and Banjo X off)
  2. Stand still and watch Banjo's eyes, then walk, jump, flap and roll and watch the backpack straps
- Look for: his eyes are wide open and blink (the FBX has him mid-blink; v5 turns the lids open, closing and shut for the game's blink stages). The straps stay on his shoulders and no longer tear where they meet the bag; the buckles and spikes ride on the straps. Checked headless: open eyes in photo mode, shut lids with a test build, straps in the idle pose (screenshot screens/banjo-x/alt-v5.png). If a strap still looks wrong, a screenshot of it helps.
- Status: failed (L, 2026-10-16: yellow patch on the stomach, fur too dark, straps not over the shoulders); replaced by T275

## T271 Modern waterfalls look good again, Shore foam for Original water
- Asked: 2026-10-16 11:55 UTC
- Build: main (pull and build)
- Steps:
  1. Graphics > Water: Modern. Look at the two waterfalls in Spiral Mountain and the stream past the tree trunk
  2. Graphics > Water: Original, then turn Shore foam on (under Water)
  3. Look along the edges of the pool round the tree trunk, and of the other pools
- Look for: Step 1, the falls keep the game's own flowing texture, with soft white streaks pouring down them, sparkles when the sun is out and mist where they land, all moving smoothly. Steps 2 and 3, a thin broken white line of foam drifts along the water's edges, as in Modern. Shore foam off leaves the game's water as it was. Checked headless in Spiral Mountain.
- Status: waiting for L

## T275 Banjo X Alt v6: fur colour, stomach and straps
- Asked: 2026-10-16 12:20 UTC
- Build: main, plus mods/Banjo X Alt v6.zip from project files (take v1 to v5 out of the mods folder)
- Steps:
  1. Put "Banjo X Alt v6.zip" in the mods folder as it is and turn on "Banjo X (alt rig)" (Smash Banjo and Banjo X off)
  2. Look at Banjo in photo mode, then walk, jump, flap and roll
- Look for: the fur is the lighter brown of L's T-pose preview (the FBX's brown base colour had been multiplied onto the fur texture); no yellow shorts above the belt; the backpack straps go over his shoulders (they had followed his arms). Eyes open, and a blink now closes the lids smoothly (the game steps its eye options 1 3 5 7 7 5 3 1; v5 had options 5 and 6 half open, so a blink flickered). Checked headless in photo mode with the zip (screenshot screens/banjo-x/alt-v6.png).
- Status: passed apart from a little clipping (L, 2026-10-16: "Looks great, though I see a little clipping"); replaced by T290

## T280 Force Interpolation in cutscenes (DEV, on by default)
- Asked: 2026-10-16 12:45 UTC
- Build: your local build of main
- Steps:
  1. Game Frame Rate Uncapped (or 120 / 175 / 240), Interpolation Display; DEV > Force Interpolation in cutscenes on (the default)
  2. Start the game and watch the opening cutscene before the title screen
  3. Turn the toggle off and watch it again
- Look for: With Interpolation on and Game Frame Rate above Original, the cutscene plays at its own 20 FPS pace (same length as at Original), blended smooth by Interpolation; with Interpolation Original, or the toggle off, it runs at the chosen Game Frame Rate as before. Gameplay afterwards uses your Game Frame Rate again.
- Status: waiting for L

## T276 Banjo fur: not on feet, shorts or Mumbo; on cutscene Banjo; density and noisiness sliders
- Asked: 2026-10-16 12:30 UTC
- Build: main (pull and build)
- Steps:
  1. Graphics > Lighting, Water, Fog (Experimental) on, Banjo fur 100, BT Reloaded on as in your screenshot
  2. Spiral Mountain: look at Banjo from the front and behind
  3. Start a new game's poker cutscene (or any cutscene with Banjo and Mumbo)
  4. Try Banjo fur density at 50 and 200, and Banjo fur noisiness at 0 and 100
  5. Once more with Smash Banjo on
- Look for: Step 2, fur on his head, arms, body and the shins below the shorts, none on his feet, shorts or belt. Step 3, cutscene Banjo has fur too, Mumbo and Kazooie have none. Step 4, density: fewer thicker hairs, then more finer ones; noisiness 0 is an even coat, 100 is tufty with lighter and darker hairs. Step 5, the same on Smash Banjo's feet and shorts (not checked headless). Checked headless in Spiral Mountain and the poker cutscene, vanilla model, no texture pack.
- Status: waiting for L

## T285 Fog stays when the camera gets low (free camera tilt)
- Asked: 2026-10-16 12:55 UTC
- Build: main (pull and build)
- Steps:
  1. Your own settings, in Spiral Mountain where you took the burst of 10:16
  2. Free camera: tilt up until the camera drops to the grass and zooms in to Banjo, as before
  3. Then walk and move the camera near walls as in your burst of yesterday 21:40 (the fog switching on and off, T180)
- Look for: Step 2, the cliffs keep the same haze all the way down (they turned plain brown at the bottom of the tilt before). Step 3, the fog no longer switches on and off. Other effects (ambient occlusion, sun shadows, reflections, 3D grass) stay put too. Cause: the game shortens its near plane when the camera is close to something, and the effects read the depth as if the game's depth range were 1/2 when it is 511/1024; with a short near plane that put the world much nearer than it is. Checked headless: fog the same with the near plane forced to 5, 1 and 0.2 as with the game's own (before the fix it vanished at 5). Not checked headless: your exact spot and your burst's camera move.
- Status: waiting for L

## T288 Kazooie feather shaders and the Character Shaders section
- Asked: 2026-10-16 13:50 UTC
- Build: main (pull and build)
- Steps:
  1. Graphics: find the new Character Shaders section (after Shaders). Banjo fur and its settings are there now
  2. Turn on Kazooie feather sheen, Kazooie feathery edges and Kazooie iridescence one at a time, then all three
  3. Spiral Mountain: stand still until Kazooie pops out, turn the camera round her; then a cutscene with her (the poker one at the start)
  4. Try each strength at 50 and 200, and the Character Shaders switch off and on
- Look for: Sheen: a soft gloss sliding over her feathers and beak as she or the camera moves. Feathery edges: short feather tips along her outline, crest and wings (her beak and legs stay smooth). Iridescence: her feathers shift colour a little with the angle, most at her outline. None of it on Banjo or anyone else. The switch hides the section's settings without turning them off. Checked headless in the poker cutscene (screenshots/kazooie/off-on-poker.png in project files); not checked in Spiral Mountain up close, on Windows (D3D12) or with model mods.
- Status: Kazooie part dropped (L, 2026-10-16); the Character Shaders section with Banjo fur stays

## T294 Viva Mumbo Jumbo v4: textures match L's reference picture
- Asked: 2026-10-16 15:35 UTC
- Build: main, plus mods/Viva Mumbo Jumbo v4.zip from project files (delete the older Viva zips and their unpacked folders first)
- Steps:
  1. Put "Viva Mumbo Jumbo v4.zip" in the mods folder as it is and turn on "Viva Mumbo Jumbo"
  2. Play as Mumbo, open photo mode and zoom in on his face and body; then talk to him in Mayahem Temple's skull
- Look for: the face texture sits exactly on the shape, as in L's reference picture: the line over the top of his head runs smoothly, the striped rings hug the eye sockets all the way round, and the tan patch outlines the nose holes. The pink skin on his arms, body and legs has the faint scale pattern from the reference; the chest rainbow and the soles stay plain. Cause: every texture was drawn shifted by a small step (a texture-pack setting meant for upscaled N64 textures), and the scale pattern came in the upload but was not used. Checked headless with the zip: photo-mode close-up playing as Mumbo and talking in the skull ([v4.png](screens/viva-mumbo/v4.png)).
- Status: waiting for L
