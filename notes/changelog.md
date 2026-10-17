# Changelog

What landed on main, newest first. Only changes you can see or use are listed;
regenerated code, CI, notes and tooling are left out.

## Since 2026-10-13 23:00 UTC (L away)

Every item below is untested on a real PC unless L's test list says otherwise
(see notes/for-L-to-test.md, T52 onward; none is confirmed yet).

### Cheats and controls

- Kazooie feathers: none on her beak, eyes or mouth any more, fuller wings, and new Kazooie feather length, density, noisiness and transparency sliders in Character Shaders (L). Untested on PC (T347).
- Settings menu: General > DEV tab is now called Developer Mode. The DEV tab has a new Additional Tabs section with Achievements tab (off by default), Cheats tab (moved from General) and Warp tab (moved from Cheats > Tabs; it no longer needs Enable cheats). Saved Cheats tab and Warp tab values carry over (L). Untested on PC (T344).
- New cheat: Learn Every Move learns every move for real, once each time it is switched on; the area reloads, saving keeps them (L). Untested on PC (T344).
- Graphics: HUD Placement's choice is called Expand again and is the default (a saved 16:9 changes to Expand once); Aspect Ratio's choice is called Fill again (L). Untested on PC (T344).
- General > Snout jiggle (on/off, default off): Banjo's snout wobbles on a spring as he runs, turns, jumps and lands, like Mario's nose in Super Mario Odyssey; with Smash Banjo the front of his muzzle moves, on vanilla Banjo his nose (L). Untested on PC (T343).
  Seven sliders under it (wobble, bounce, speed, exaggeration, stretch, snout size, reach); the wobble freezes in Photo Mode; on vanilla Banjo the whole front of the snout bends now, not only the nose (L). Untested on PC (T349).
- Graphics > Character Shaders > Enemy fur (on/off, default off): the yetis on Hailfire Peaks' Icy Side grow white fur like Banjo's (L). Untested on PC (T336).
- Banjo fur: his knees (the brown between his shorts and boots) now have fur too; the shorts stay bare (L). Untested on PC (T332).
- Kazooie feathers: on her wings they now point out along the wing to the tips instead of down, each feather shows the texture colours under it (yellow tips on the wings), and the top of her head is feathered (L). Untested on PC (T331).
- Start menu: Start Game is now Play, with the effects preset beside it (< Vanilla >, Enhanced, Retro, Custom); left and right or the arrows change it, and Play applies it (L). Vanilla (the Effects preset once called Original) turns every shader effect off, also FXAA, FSR and Kazooie feathers. Untested on PC (T327).
- New cheats: 100% complete (everything done except the last boss, Hag 1: all Jiggies, notes, Jinjos, honeycombs, Cheato pages, Glowbos, doubloons, moves, worlds and bosses; saving keeps it) and Dragon Kazooie (on: Kazooie is Dragon Kazooie, off: she is Kazooie again). Untested on PC (T326).
- Fixed: scrolling the Graphics menu with a controller lagged on every step. The option description now shows a moment after you stop on an option instead of on every step. Untested on PC (T319).
- Run is now on the controller's B button by default (the button labelled B on an Xbox pad, Circle on PlayStation). That button was a second C-right; the right stick still turns the camera. Saved controls get the change once if Run was unbound and B was only C-right. On Android the touch B button now does the game's B instead of C-right. Untested on PC (T305).
- The Start menu has an ACHIEVEMENTS entry under View Totals (first called Settings, renamed by L). Its page lists the twelve XBLA achievements with how many are unlocked and the G earned; unlocked ones are yellow, up and down pick one and show its description and when it was unlocked (or the count so far for the counted ones). B goes back, Start closes the menu. Untested on PC (T270, T344).
- Warp tab: Glitter Gulch Mine > Outside Mumbo's Skull, and Cloud Cuckooland > Skull on the cloud (straight ahead), for the Mumbo's Hut Recreation mod (the mod itself is a separate download for the Mods menu). Untested on PC (T241).
- Graphics > Shaders off now also turns its section's effects off, so the game plays plain; their settings are kept (L). Untested on PC (T321).
- QOL > Totals checklist is on by default; saved settings keep their value (L). Untested on PC (T322).
- Fixed: after Alt+F4 (or any controller or key press), a click on the quit prompt could miss Quit, because the menu still had an old mouse position; a click now moves the menu's cursor to where you clicked first (L). Untested on PC (T274).
- QOL: Skip boss intros and Skip other cutscenes are one switch, Fast Forward Cutscenes; Press Start Anytime In Intro (renamed) sits at the bottom of Speed and skipping; photo mode's settings have their own Photo Filter section behind a Hide Settings switch; Canary Mary races moved to a new Balancing section (L). Untested on PC (T264).
- Graphics: Aspect Ratio's Fill and HUD Placement's Expand are now called Default, and the Lighting, Water, Fog (Experimental) switch is called Shaders (L). Untested on PC (T265).
- Settings menu with a controller: Back while typing in the search box returns to the Search settings box, and the menu reopens on the tab you left instead of the top of the list (L). Untested on PC (T266).
- Fixed: quitting could show "Fatal error in mod - Attempted to open an invalid UI context" when the frame rate overlay, a notice or the photo mode panel updated while the menu was being torn down (L). Untested on PC (T267).
- A Performance tab under Graphics holds Game Frame Rate, Interpolation, Low Input Latency, Frame Read-Back and the Frame rate overlay (L). Saved values carry over. Untested on PC (T262).
- Controls: the interpolation hotkeys (Interpolation Check, Blend Mode, Pick Model, Tag Model, Save Tags, Unsave Tag, Model Effects) have their own Interpolation Debug section below Debug (L). Untested on PC (T236).
- The settings menu has a new layout in Banjo-Tooie's style: the tabs as a list down the left side with a search box on top, and the selected option's description in a strip along the bottom (layout A). It replaces the old layout; there is no switch (L). Each option's name and control share one line, the description strip is smaller, and Graphics no longer shows an Apply box (it saves live), which also removes the doubled row at the bottom. Untested on PC (T194, T217, T235).
- Warp > Race Warps (at the bottom of the Warp tab): starts any of Canary Mary's four races, Glitter Gulch Mine first and second and Cloud Cuckooland first and second, whatever your file has done. It goes to Mary's spot in that world first, then straight into the race with the countdown. Practice runs: your file is left as it was and no Jiggy or Cheato page is given. Untested on PC (T186).
- QOL > Transform anywhere (off by default): the Transform key (T; bind a controller button in Controls > Movement) changes Banjo into the world's Humba Wumba form where he stands, with the game's own spin-up, and back. A world's form works once you have changed in its Humba pool, and only in that world. Terrydactyland gives the Daddy T-Rex once Humba's tent is big (refused where it has no room), the baby T-Rex before. Humba says her line on the 1st, 3rd, 5th change. Refused with a sound in the air, swimming, while talking or in a cutscene; the submarine changes in water only. Untested on PC (T184).
- QOL > Totals checklist is now off by default, and a saved On from an earlier build starts Off too. Turn it on in QOL to get the table and lists back.
- Fixed: with Frame Read-Back off (the default) the renderer made a new copy of the frame for every frame drawn and never freed it, so video memory filled up: fastest on the pause menu's Totals pages (about 5 MB a second), slowly in play, until the graphics driver crashed. Memory now stays level. Untested on PC (T179).
- Totals checklist: press A on a row of a world's Totals table to list its items by name as GET NOW, LATER or DONE; a LATER item says what it still needs (a move, a transformation, Mumbo, notes, a world opened). B goes back to the table. Game Totals lists only worlds you have visited. The game's own A button sprite marks the picked row, the table fades and rises in with the page title, and items not picked are faded back like the pause menu's options. Untested on PC (T168).
- Totals checklist: a green NOW column says how many of what is left in a world you can get with the moves, transformations and areas you have now, and a line under the table says MORE TO GET HERE, MOVE ON FOR NOW or ALL DONE HERE; Game Totals says NEW WORLD READY when Jiggywiggy can open the next world. The rules come from the Banjo-Tooie Archipelago randomizer (MIT). Untested on PC (T167).
- Warp > Test > Test room: rows of 90 objects, characters and enemies doing their idle animations, plus statues for the 14 transformations (walk up to one to turn into it). 58 actors that crash outside their own level are left out. Untested on PC (T165). Gruntilda (her Tower of Tragedy quiz intro) and five characters who start talking on their own (King Jingaling, Jolly Roger, Bullion Bill, Conga, Biggafoot) are left out too, so the room no longer starts a cutscene.
- QOL > Totals checklist (on by default): each world's Totals page in the pause menu has a "LEFT HERE" table with how many Jiggies, Honeycombs, Cheato pages, Glowbos, Notes, Jinjos and Jamjars moves are still to find there; Game Totals has the same for the whole game. Untested on PC (T160).
- Noclip now passes through walls, scenery and floors; the game was pulling Banjo back to a collision position that Noclip did not write (T139).
- Tiptoe's key binding is under Movement in the Controls tab, with Run (T139).
- Graphics > Debug has Effect compare, Interpolation check and an Interpolation blend mode list beside the Effect debug view (T143).
- F1, F6, F7, F8, F9 and F12 are bound in the Controls tab and can be changed; F8 is only Effect Compare now, and blend modes moved to their own Blend Mode key, F5 (T143).

### Gameplay

- Above 60 FPS the water in Jolly Roger's Lagoon no longer pushes Banjo back so he can't swim. Untested on PC (T340).

### Graphics
- Parallax is about twice as deep, and the deep parts are now shaded: the gaps and cracks are darker and the raised parts cast shadows into them from above. A second sweep added 475 more textures (1,690 in all), including plank walls, crates, roof tiles, scales and carved panels. New switch Parallax on original textures (on by default) turns the game's own textures on or off. Texture packs can give any texture parallax with a height map named like the texture plus `_height` (`wall.png` and `wall_height.png`, white high and black deep), which works with the switch off too (L). Untested on PC (T354).
- Saved shaders compile faster at start: every compile thread works through the saved shader list while the game needs nothing new (was half), so the save select's shaders are ready sooner and the first Jiggy wipe into it doesn't stutter (L). Untested on PC (T342).
- New Parallax setting (Graphics, under Shaders, 0 to 100, off by default): stone walls, paving and rock get depth, with the stones standing out and the gaps and cracks sunk in, shifting as the camera moves. The N64 textures have no depth of their own, so it comes from how dark each part of the texture is. On 1,215 stone, brick, rock and cliff textures picked by eye from a dump of every level (L). Untested on PC (T341).
- Fixed: above 30 FPS Klungo's fades ran at the wrong speed, and at 150 FPS and up he never faded back in behind his shield, so some phials started from his middle instead of his raised hand. Untested on PC (T331).
- Shader speed pass 2: every material's shader is a third of its size for ordinary draws (the grass, snow and fur shells have their own), the night's fireflies and the depth of field's focus are worked out once a frame instead of in every pixel, bounce light reads a half-size copy of the scene (a touch smoother), and the output pass skips its gamma at 1.0. Nothing should look different; night with fireflies and busy scenes should run faster. Untested on PC (T328).
- 3D grass now reads the textures of what the game lays over the ground: wherever a road, path or dirt patch with a non-grass texture is drawn over grass ground, no blades grow under it (L). Untested on PC (T323).
- Shader speed pass: 3D grass blades, the water mask, ambient occlusion and sun shadows each do less repeated work on the GPU; nothing should look different. Every shader also compiles clean for both Vulkan and DirectX (QA write-up in notes/shader-qa-2026-10-16.md). Untested on PC (T315).
- Fixed: with Ambient Occlusion, Fog, Bloom or the other shaders on, the Jiggy-shaped level wipe was grey instead of black; the shaders now go on before the wipe is drawn (L). Untested on PC (T317).
- 3D grass no longer grows on Spiral Mountain's cobbled road: the grass layer the game blends over the road fades out by its vertices' alpha, which the blades ignored (L). Untested on PC (T309).

- The gameplay demo (when you don't press Start) no longer runs too fast. DEV > Force Interpolation in the gameplay demo (off by default) blends it like the opening cutscene. Untested on PC (T307).

- 3D grass blending slider (0 to 100, default 50): the blades take on the ground's colour, most at the roots and further away, so the grass blends in (L). Untested on PC (T301).
- 3D grass (and the other screen effects) no longer vanish across the level while Bottles' ghost is drawn in Spiral Mountain: the ghost's "no effects" mark stayed on for everything drawn after it when it was the last model of its list (L). Untested on PC (T300).
- 3D grass: Chunk size (100 to 400%) and Pixel size (0.25 to 8 N64 pixels) sliders for Chunky and Pixelated 3D grass (L). Untested on PC (T287).
- 3D grass has its own Grass section in Graphics, with two new toggles (L): Chunky 3D grass (fewer, wider, flat-coloured single-triangle blades) and Pixelated 3D grass (blades drawn in blocks the size of N64 pixels). Untested on PC (T286).
- Textures use mip LOD bias 0 instead of RT64's -0.25 (L), in both the native samplers and the shader path, so distant textures pick the matching mip level: slightly softer, less shimmer. Untested on PC (T281).
- Fog and the other picture effects (ambient occlusion, sun shadows, water reflections, 3D grass) no longer go wrong when the camera gets close to the ground or a wall, as at the bottom of a free camera tilt: the effects now read the game's depth the way it was written, so distant scenery keeps its fog. Untested on PC (T285).
- Day and Night: no rain under water, and no rain rings on waterfalls (T324).
- Day and Night: Cloud Amount, Cloud Height, Cloud Thickness and Cloud Speed settings (T314).
- Day and Night: rain splashes reach well past Banjo and are lit like the ground they land on (T310).
- Day and Night: clouds show again by day; with Fireflies on, a rounding step in the shader dropped the clouds flag (T302).
- Day and Night: Wet Ground (shiny, drying after rain), rain rings on water and Raindrops on Screen (T249, T250, T251).
- Day and Night: five more times of day (Dawn, Noon, Afternoon, Golden Hour, Dusk), and Mist and Mist Time settings; the mist lies in patches and gathers round water (T242, T243).
- Day and Night: fireflies reworked after Ocarina of Time's forest at night: more of them, warm soft glows floating at all heights and fading in and out (T232). Rain now splashes on the ground (T233). Untested on PC.
- Day and Night: morning mist lying low over the ground until mid-morning. Untested on PC (T216).
- Day and Night: golden hour (warm light with richer colours for a while after sunrise and before sunset) and morning dew glinting on the grass. Untested on PC (T215).
- Day and Night: northern lights over Hailfire Peaks' Icy Side at night (Graphics > Northern Lights, on). Untested on PC (T214).
- Day and Night: house windows light up warm at night (Jinjo Village and others using the same windows), and fireflies fade out right by the camera. Untested on PC (T213).
- Day and Night: shooting stars now and then on clear nights, and the moon goes round its phases over eight days with Cycle (full when a time of day is held). Untested on PC (T212).
- Day and Night: snow on Hailfire Peaks' Icy Side, light unless Weather is Clear and heavy in a storm. Untested on PC (T210).
- Day and Night: rain and thunderstorms, with an overcast sky, falling rain, lightning, the sound of rain and thunder (Graphics > Weather: Clear, Changing, Rain, Storm; Changing by default). Untested on PC (T209).
- Day and Night: soft 3D clouds drift across the sky, white by day, orange at sunset and dark at night (Graphics > Clouds, on; not in Cloud Cuckooland). Untested on PC (T207).
- Day and Night: night sounds, crickets and the odd owl at night and birdsong in the morning, quietly under the music (Graphics > Night Sounds, on). Untested on PC (T206).
- Day and Night: fireflies drift and blink round Banjo at night (Graphics > Fireflies, on; not on Hailfire Peaks). Untested on PC (T202).
- Day and Night: the sun shows in the sky as a disc that moves and sets, with a lens flare when you look towards it (Graphics > Lens Flare, on). Sun shadows now fade out as it sets, and the moon rises a little after. Untested on PC (T200).
- 3D grass is now made of real blades, like the Godot grass shaders L pointed to: each blade is its own small 3D shape grown on the green ground, swaying in noise-driven wind, bending away from Banjo and his trail, dark at the root and bright at the tip. Untested on PC (T197).
- New Graphics > 3D grass density slider (10 to 200, default 100): how closely the 3D grass blades grow. Untested on PC (T204).
- Fixed the Windows build stopping in the 3D grass shader (GrassGS.hlsl went over D3D12's 1024 output values once Banjo's fur added an output). Untested on PC (T220).
- 3D grass grows in patches (new Graphics > 3D grass patches slider, 5 to 100, default 50) and only on grass textures, not on other green surfaces. Untested on PC (T227).
- 3D grass blades keep their places as you move: each blade belongs to a fixed spot, and further away blades only thin out, shrinking away first, instead of the whole field being picked again. Grass now also grows where the game lays a grass layer over dirt (round the Spiral Mountain tree stumps, where it vanished), and no longer on the yellow road or mossy stone and brick. Untested on PC (T278).
- New Graphics > 3D grass thickness (50-400 %, default 100) and 3D grass random length (0-100 %, default 40). Untested on PC (T279).
- New Graphics > 3D grass on edges (on by default): blades also grow on the grassy parts of part-grass textures, such as cliff-top fringes and the foot of walls. Untested on PC (T245).
- Kazooie feathers (Graphics > Character Shaders, 0 is off) with Kazooie feather size: lots of little flat feathers grow over her red feathers, overlapping down her body like a bird's, in the spirit of NeuralVFX's feather geometry shader. Needs geometry shaders (not on Mac). Untested on PC (T297).
- Kazooie feathers also grow on her wings and the crest on her head (parts cut out by their textures), never on dark texture spots. Untested on PC (T306).
- Character Shaders (Graphics, after Shaders): Banjo's fur settings moved here. Untested on PC (T288).
- Banjo fur: no fur on his feet and shorts (picked by bone, so model mods are covered), none on Mumbo or anyone else (Banjo is picked by his skeleton), and cutscene Banjo gets fur too. New Banjo fur density and Banjo fur noisiness sliders. Untested on PC (T276).
- Banjo fur reworked after L's screenshot: the strands now follow Sorumi's UnityFurShader (a fine noise thinned out shell by shell, darker at the roots), so the coat reads as fine fur instead of pyramids, and Kazooie no longer gets fur. Untested on PC (T240).
- Banjo fur (Graphics, Photo Filters, 0 is off): Banjo's brown fur grows short strands that stand out of his model and move with him, darker at the roots, with Banjo fur length beside it. Kazooie, the shorts, backpack, gloves and boots stay as they are. Untested on PC (T205).
- The intro ("Two years have passed..") stretches only its cloud backdrop shots across a wide window, instead of showing the backdrop's ends and black past them; the castle and characters keep their shape (T189, T225).
- Asset mods: a mod with an assets.json and an assets/ folder of asset_<id>.bin files (a model mod) can be dropped in the mods folder as a .zip and turned on and off in the Mods menu; its files load in place of the game's from the next area load. Smash Banjo (project files, mods/Smash Banjo v1.zip) is the first: the Smash Ultimate Banjo and Kazooie model with HD textures. Untested on PC (T185).
- 3D grass, Breath of the Wild style: knee-high tufts of thin, arching blades, dark at the roots and lighter and yellower at the tips, with waves of wind rolling across the field. Banjo parts the grass round him and leaves a trail that springs back up over about a second. Untested on PC (T183).
- Picture effects (Fog and the other scene effects) no longer cover the letterbox bars, which turned gray with Fog on; they stay inside the 3D picture. With frame smoothing, fog uses the same in-between camera the picture is drawn with. Untested on PC (T180).
- Smoke and water droplets should no longer break into stripes with frame smoothing: an animation's next frame snaps instead of sliding across the texture. WIP > Debug > Texture slide blending turns all texture sliding off, to test. Untested on PC (T178).

- Graphics > Day and Night (off by default): a day and night cycle in Spiral Mountain, the Isle o' Hags outside, Mayahem Temple, Jolly Roger's Lagoon, Terrydactyland, Hailfire Peaks and Cloud Cuckooland. Sunrise and sunset turn the light warm, night is dark blue with stars and a moon, and the sun moves for sun shadows and light shafts. Cycle runs a day in Day Length minutes (24 by default); Morning, Sunset and Night hold one time. Rooms, underwater areas, Witchyworld and Cauldron Keep keep their own look. Untested on PC (T174).
- Frame rate overlay: lines in four groups; game CPU time no longer drops to 0 ms (a wait was counted twice); the first line keeps the last frame rate below 4 fps (T170).
- Benchmark key (F4): records the frame rate overlay's figures to benchmarks\ with a summary and the settings, for comparing settings or builds (T161).
- Shaders met in earlier sessions are kept in cache\shader_list.bin and compile in the background at start, so first visits stutter less (roadmap 4.32, T159).
- The saved shaders no longer hold up the shaders the current scene needs (stutter at the start, T298). "Compiling shaders N%" shows in the bottom-right corner while they compile, and on Windows the compiled shaders are kept in cache\shaders so later starts skip the compiler (T320).
- Frame rate overlay (Full): GPU time of each extra pass (water mask, eye adaptation, bloom, effects, SMAA, FXAA, photo filters, FSR, output, UI); roadmap 4.43's F3 timings (T157).
- Faster rendering: the renderer no longer copies every frame back into the game's memory and waits for the graphics card (Graphics > Frame Read-Back, off by default; turn it on if a picture effect shows black or frozen), and it sleeps instead of keeping a CPU core busy while the graphics card catches up. Headless in Bottles' House: 28 fps instead of 14, controller-to-screen 64 ms instead of about 165 ms. Untested on PC (T162).
- DEV > Force Interpolation in cutscenes (on by default): the opening cutscene before the title screen, and the attract demos, run at the game's own pace (20 a second for the opening) when Game Frame Rate is above Original, and Interpolation blends them up to its rate; it does nothing while Interpolation is Original. Untested on PC (T280).
- Game Frame Rate Uncapped, and any rate above the screen's refresh rate, show the picture without vsync, so the screen can keep up with the game (L saw the game at 300+ but only 100 on screen). The game also stays at most two frames ahead of the screen, so the GPU no longer draws frames nobody sees. Untested on PC (T247).
- Game Frame Rate Uncapped is no longer held to the Interpolation rate (about 100 FPS for L); 40 to 240 FPS run at normal speed when the PC can't reach the rate, instead of going into slow motion. Untested on PC (T238).
- Game Frame Rate has 30, 40, 60, 120, 175, 240 FPS and Uncapped (Unlocked renamed; a saved Unlocked becomes Uncapped). Uncapped has no limit: it runs the game as fast as the PC can, where Unlocked stopped at 240. From 40 FPS up the port now times each frame itself and shows it at once, instead of running the screen refreshes 2 or 4 times as fast; the sound's timing stays on the normal 60 a second. Untested on PC (T199).
- Graphics > Low Input Latency (on by default): each finished frame shows at the next screen refresh, as on the N64, instead of one refresh later, so controls react about 17 ms sooner at Original, 30 and 60 FPS (4 ms at Unlocked). Headless, every frame now shows 1 VI after the game swaps it in instead of 2. Untested on PC (T158).
- The frame rate overlay's two Interpolation lines are one: "Interpolation: Display, on: 6 models, 47 bones, 0 shadows, 1 camera cuts" or ", off".

- Long drop-down lists in the menu (Effect debug view) scroll, and follow the pick when moving with a pad or the arrow keys; before, entries past the window edge couldn't be seen (T148).
- Graphics > Debug > Effect debug view: shows any picture effect or filter on its own (all 13 scene effects plus sharpening, contrast, saturation, vignette, grain, SMAA, FXAA, FSR, CRT, 16-bit colour, colourblind and texture upscaling), or all of them off; F6 steps through the same list. Untested on PC (T140).
- HD Shadows and Extended Draw Distance stop adding to a frame when the game's fixed drawing memory is nearly full (both together filled up to 87% of it headless, and past the end it tears or explodes models). Untested on PC (T120).
- A broken link in the game's memory heap, as in L's crash of 2026-10-15 in the allocator (a link that lost its top bit), is repaired before the game follows it, instead of crashing; a "HEAP error" notice shows in game and the session log notes each repair (`[heap] ... repaired`); the heap check's first damage also shows a "HEAP error" notice. Untested on PC (T154).
- The session log now notes the first sign of damage to the game's memory heap (`[heap] damage found`), to find the cause of a 120 FPS crash in the memory allocator.
- A broken sound frame no longer closes the game with "Unhandled jump target ... in n_aspMain": that frame is skipped (a short sound glitch) and logged. The session log also says when a sound list changed before it played, to find the cause of the Unlocked crash. Untested on PC (T147).
- Game Frame Rate above 30 FPS: talking-head portraits talk and blink, and characters blink, at their normal speed again instead of 2 to 8 times too fast. Untested on PC (T141).
- Game Frame Rate Unlocked and 120 FPS: the sound no longer slowly falls behind, which is the likely cause of the sound breaking and then the "n_aspMain" crash after a while. Not reproduced headless; untested on PC (T138).
- Game Frame Rate: 120 FPS and Unlocked (up to 240), both experimental; the sound stays at its normal pace. The Framerate option is now Interpolation (Original is now Off) and sits under Game Frame Rate. Untested on PC (T122).
- Frame rate overlay: shows input latency (controller read to screen), in Compact and Full.
- Frame rate overlay (Full): shader compiles in the last 5 s, and the game's CPU time per frame.
- Extended Draw Distance now takes effect as soon as it is switched (before, it did nothing until Apply), and notes, eggs and other placed objects draw as far as characters. Untested on PC (T30).
- Game Frame Rate (Original, 30 FPS, 60 FPS) holds the game's own update rate; attract demos keep their pacing (6231d8b, 6736f06). Untested on PC (T52).
- Save Game Select: the waving hand is blended above Original, pictures keep their quick shake (a9b1817, 5fd696e). Untested on PC (T54).
- Frame rate overlay: 1% low, hitches, map and Banjo's position, renderer, speed-up/cheats/mods (5bd3bbd); Off, Compact and Full with F3 (435fe16). Untested on PC (T75, T84).
- Interpolation: repeated model parts paired with last frame's nearest (7a025d1, fc5fb28); swapped bone keeps its id (ac39168, e075788). Untested on PC (T76).
- Effects: sharpening, contrast, saturation, vignette, film grain (c0801d2); ambient occlusion under the HUD (86f3937); fog with start distance and colour (3d5776b); toon outlines (4f8b8d4); effects preset Original/Enhanced/Retro (f61ac36); bloom under the HUD (a364434); depth of field in letterboxed cutscenes (aa21380); eye adaptation (a45ff11); rim light (38942a7); heat haze by lava (160c285); underwater tint and distortion (ac6613b, aabde0b); water reflections (eeadba0); bounce light (f319872). Untested on PC (T66–T69, T71–T74, T79, T81, T82, T88, T90).
- Photo mode: orbit and zoom (3ef2fb1), camera collision (24d1721), hide Banjo (758ef8e), filters (1740a93), crop and rule-of-thirds grid (d436740), depth of field and tilt (02a1f9a, ae1d780), panel (d3fdb80). Untested on PC (T60, T62, T65, T85).
- F6 effect views and F8 compare (c5a21ee). Untested on PC (T80).
- FXAA and FXAA Extreme (61bd0ba). Untested on PC (T92).
- Texture upscaling, live 2x/4x (36bb76a). Untested on PC (T91).
- HD Shadows for the player (aa2351d). Untested on PC (T87).
- Always High-Detail Models keeps Banjo's close-up necklace model (b2f41b9). Untested on PC (T77).
- Graphics API: Vulkan is the default and Auto is removed (3516154). Untested on PC (T89).
- Glittering honeycombs sparkle on the comb (e482297). Untested on PC.

### Controls

- Button combinations: with Combo binding On (Controls tab footer), a binding slot takes two inputs, held one then pressed the other (for example a back button + Y). A combination wins over the second button's own binding while the first is held. Untested on PC (T338).
- Fine aim now really slows first-person turning (headless: 44% of the normal turn at the 40% setting; before, about 89%). Its key is bindable: Controls tab, Hotkeys, Fine Aim (R or right trigger by default). Untested on PC (T102).
- Gyro aim: the controller's turn now moves the view the right way (left/right and up/down were swapped) and by the right amount (it was a rate, not degrees). Untested on PC (T103).
- Split up anywhere: D-pad left plays Banjo, right plays Kazooie (065b633, 22ee63c). Untested on PC (T55).
- D-pad control scheme in General (1bbfe86). Untested on PC (T58).
- Mouse and gyro aiming in first person (8888075). Untested on PC (T64).
- Hold B to run, with a faster run animation (f4a8154, 64a95d0). Untested on PC (T86).
- Speed-up key test notes and 4.21 marked done (af32c7a). Untested on PC (T59).

### Audio

- Sound no longer drops out at Uncapped and other high frame rates, or in cutscene skips ("Unhandled jump target ... n_aspMain" in the log). Untested on PC (T339).
- Sound > Mix rate now switches at once, without restarting the game. Untested on PC (T335).

- Sound no longer breaks up with Game Frame Rate at 40 FPS (and the other rates the port paces itself). Untested on PC (T325).

- Music player in the Sound tab (098bb74). Untested on PC (T57).
- Back-Port: Get Jiggy animation, off by default (0c63fd2). Untested on PC.
- Old Banjo sounds (4.64 marked done, da43b51). Untested on PC.

### Cheats

- Noclip (cb79700). Untested on PC (T53).
- Unlock everything (a6d5d1d). Untested on PC (T56).
- Cheato effects written up from fan wiki pages (7e1ab37), shown in the cheat menu (d9ada2c), and moved to their own Cheato tab (b64fd23). Effects are not checked in this port.
- Cut Content: Bottles' Revenge, the cut two-player mode (accf3f7). Untested on PC (T61).
- Bottles' Revenge: a save file that has not seen the mode's intro is taken to Spiral Mountain to watch it once, then brought back. Untested on PC (T177).
- Save states (c433c88). Untested on PC (T63).
- Split up anywhere, as above.

### Achievements

- The Xbox Live Arcade twelve, with pop-ups and an Achievements tab (8694d99). Untested on PC (T83).
- Treasure Hunt, one of each collectible (df684cf). Untested on PC (T83).
- Shoot Em Up!, 20 targets in the shooting games (009573c). Untested on PC (T83).
- All Beaten Up and Calamari Bonanza counters (965eb06). Untested on PC (T83).

### Stability

- Fixed the GPU being lost (window freezes, the log fills with 0xFFFFFFFC) on NVIDIA cards since the cloud sliders were added: the screen effects' settings were too big for the driver. Untested on PC (T351).
- Fixed the frame rate falling to about 2 fps after a few minutes: the screen effects kept every descriptor set they replaced, and the driver's memory for them filled the graphics card. They are now freed a few frames later. Untested on PC (T263).
- General > More game memory (on by default): a bigger game heap (2.8 MB to 12.8 MB), about 4x the per-frame display list, matrix and vertex buffers, and room for 240 animation files and 1023 animations instead of 130 and 135, so scenes crowded with characters no longer crash. Takes effect at the next start. Untested on PC (T122).
- More game memory also gives the game 48 sound voices instead of 24 (with 180 sample buffers and a 512 KB sound heap), so fewer sounds cut out in busy scenes, and its drawing buffers grow to about 8x. Untested on PC (T155).

### Tools and build

- Two Windows builds: Any 64-bit PC (2008 and up) and Optimized for newer CPUs (2013 and up), with three update scripts (e49f23c, 3a25fe3). Untested on PC (T78).
- Turn ThinLTO on for optimised builds (5eac701). Untested on PC.
- Warp tab: Down goes down and Right goes right (b5550b0). Untested on PC.
- F7 skips first moves in the interpolation check (e075788). Untested on PC.
- Headless TOOIE_SET script changes Graphics options live (5fd696e). For testing only.

## 2026-10-14

- Back-Port: Get Jiggy animation now switches the dance inside the Jiggy pose's own start, since it never played on a real Jiggy before (T51).
- Extended Draw Distance also reaches objects that set their own short draw distance, such as Jolly Roger's Doubloons (T30).
- Graphics: MS Anti-Aliasing is now in the Anti-aliasing and scaling section, above SMAA.
- Achievements: Down on a controller or the arrow keys now moves through the list and scrolls it (T117).
- Settings search: every settings tab (General, QOL, Graphics, Sound, Cheats) has a Search box at the top that filters that tab's options by name and description as you type. It searches one tab at a time and needs a keyboard or mouse to type.
- Settings search: a Search tab finds options in every tab (name, description or tab name); you can change them right there. It needs a keyboard or mouse to type. The per-tab search boxes are gone.
- Cheats: each Cheato code now says what it does in detail (the "from wiki pages" line is gone).
- Graphics tab: section headings (Display, Picture and effects, Lighting water and fog, Colour grading, Game view, Anti-aliasing and scaling, Frame rate and overlay). Game Frame Rate and the Frame rate overlay rows moved to the end, under their own heading.
- Graphics > Texture upscaling: the description now says what each option uses (2x is one pass of an xBR-style edge filter, 4x is two passes).
- Menus: moving the selection down a list with a controller or the arrow keys now scrolls the list with it (the Warp list used to keep the selection out of view).
- Settings: the Cheato codes are back in Cheats (under a Cheato codes heading); the separate Cheato tab is gone. Cheato switches you had on are read from the Cheats settings again.
- Graphics > Resolution: 720p, 1080p and 4K are now named 3x, 4.5x and 9x with the pixel height in brackets, and 6x (1440p) is new. Every Graphics option (including Field of View and Game Frame Rate) applies the moment you change it; the Apply button is not needed.
- Fixed a crash in play when the game hands the renderer graphics code it doesn't recognize (your 10:33 crash). The renderer keeps going and writes the details to logs/console.log.
- Fixed a crash at startup ("string too long") when the game was started from another folder, for example by the Graphics API restart. It now finds its files next to the exe.
- Graphics API now shows in Graphics. Picking the other one asks "Restart now?" and the game reopens itself with it; Later keeps it for the next start.
- Cheats and General tabs: section headings (Infinite items, Moves, Unlocks, Tabs; Saves, Back-Ports and cut content, Developer). In General the Control scheme, save and timer-save rows moved next to related rows; headings in Cheats hide while Enable cheats is off.
- QOL tab: split into Speed and skipping, Camera, and Moves and aiming, with a heading for each. The two cutscene-skip options moved up next to the speed options.
- Graphics: FSR 1 Upscaling (On or Sharp), AMD's upscaler for when Resolution is below the window's, as on Xbox Live Arcade.
- Graphics: FXAA Anti-Aliasing (FXAA or Extreme), the Xbox Live Arcade version's quick edge smoothing; it works with MSAA and SMAA.
- Graphics API: Auto is gone and Vulkan is the default (D3D12 is still a choice on Windows). If you have Auto saved, switch the row once.
- Settings: the eleven Cheato codes moved from Cheats to their own Cheato tab, shown while Enable cheats is on (Cheats is much shorter). Your old Cheato switches start off.
- Hold to run: a new Run control (Controls tab, Movement), not bound by default. Hold it while moving and Banjo-Kazooie, Banjo alone or Kazooie alone runs half again as fast, with a new sprint animation: Banjo leans forward with a longer stride and arms held in, Kazooie leans in with a longer, bouncier stride. Starting and stopping the sprint eases over about a third of a second. Holding Run with the stick only partly pushed now runs too (before, Banjo walked and Run did nothing). Run no longer has anything to do with B or the roll. QOL > Running turns it off.
- Frame rate overlay: Off, Compact or Full, with F3 to step through them; Full adds audio queue and dropouts, the build, and a frame time graph.
- Above Original, a part of Banjo that changes its look (his face when he blinks) no longer jumps for a frame.
- Achievements: the Xbox Live Arcade version's twelve achievements (200 G), with a pop-up when one unlocks and an Achievements tab listing them. Eight are tracked so far; nothing is awarded while cheats are on.
- Warp tab: Down on a controller or keyboard now goes down a line, and Right goes right (before, both went to the next place).
- Windows builds: build.bat makes two games in Release: "Any 64-bit PC (2008 and up)" and "Optimized for newer CPUs (2013 and up)". update_and_build_any_pc_2008.bat and update_and_build_newer_cpu_2013.bat build one each, update_and_build.bat both; saves and settings from the old Release folder are copied into each new folder.
- Above Original, models made of one repeated part (chains, rows of plants, swarms) no longer stretch for a moment when the game drops one of the parts.
- Frame rate overlay: adds the 1% low and hitches, the map and Banjo's position, the renderer and resolution, and whether speed-up, cheats or mods are on.

## 2026-10-13

- Save Game Select: above Original, the waving hand is smooth again while the pictures keep their quick shake.
- Banjo no longer slides when Jamjars (or anyone) starts talking to him: talking now stops him on the spot, as on N64. A function that stops Banjo was recompiled empty.
- Graphics: Game Frame Rate (Original, 30 FPS, 60 FPS) holds the game's own update rate steady.
- Frame rate overlay: the game's frame rate is averaged over 2 seconds, so a steady 30 no longer reads as 28 and 32.
- General: Back-Port: Get Jiggy animation, Banjo does Banjo-Kazooie's jiggy dance when he collects a Jiggy (off by default).
- Graphics: SMAA Anti-Aliasing (Low, Medium, High or Ultra) smooths jagged edges, with or without MSAA.
- Transformation drop-down: moving through the list with a controller or the arrow keys no longer applies every entry on the way; the pick applies when you confirm.
- F7 turns on an interpolation check: models whose blend between frames looks wrong turn red for a moment and are logged.
- Fire, dust, feathers and other particles are blended above Original, each paired with itself from the frame before (they were drawn at 30 fps, then could swap places between frames).
- Above Original frame rate, a cutscene's black bars coming in no longer blend the picture's shape (likely cause of the brief squash in ultrawide, not yet tested).
- Fine aim: the first-person view turns slower, always or while R is held (QOL).
- General: Back-Port: Old Banjo sounds swaps in Banjo-Kazooie's jump sounds (off by default).
- Canary Mary races: Fair (default), Easy or Original in QOL (works once the game code is regenerated with its hooks).
- Graphics: Frame rate overlay shows frame rate, frame time, the worst frame, GPU time and frame interpolation figures in the top left corner.
- Graphics: Brightness with a test pattern, Colourblind filters, and Retro N64 16-bit colour, CRT and a 3-point filtering switch.
- Controller support now comes from SDL 3 (through sdl2-compat): back buttons work on more pads, including 8BitDo Pro 2, Pro 3, Ultimate 2 Wireless and Ultimate 3.
- Talon Trot can be a toggle (QOL, on by default): let go of Z and Banjo keeps trotting until you press Z or C-left.
- Controller back buttons that SDL doesn't name can now be bound in Controls (they show as L4, R4, L5, R5).
- Fixed the Jiggy level wipe ending early in wide pictures: it now opens the whole screen.
- Fixed Banjo's limbs coming apart when the frame rate is above Original.
- Texture packs can be dropped into the mods folder as a .zip.
- The Warp tab switch is in Cheats, and needs Enable cheats on.
- Skip intro logos is renamed Press Start Early to Skip Intro.
- Cheato codes are live toggles in Cheats. Unlock all moves is added (first part, not yet tested).
- Fixed missing terrain at the edges of wide windows.
- Text speed and level transitions moved to the QOL tab.
- Level transition speed: Original, Fast 4x or Instant 16x.
- Skip intro logos moved to a new QOL tab.
- F1 hides the HUD and text boxes.
- Cheats: Infinite Jumps (Levitate) (A in mid-air; the separate D-pad down Levitate was removed).
- Dialogue text speed: 1x, 2x, 4x or instant.
- Level warp list is in a Warp tab, shown by Cheats > Warp tab (with Enable cheats on). F9 repeats the last warp.
- Level warp tab with 42 places.
- F12 takes screenshots, with a "Screenshot saved" notice.
- The HUD is at the screen edges in wide pictures.
- Speed-up key: hold F2 for 2x, 3x or 4x.
- The crash log names the last C++ error and lists the crashing code.
- Windows: the game's console output is kept in logs/console.log.
- build.bat puts the finished game in a Release folder.
- Discord status shows the level you are playing in.
- Start skips the boot logos to the file select.
- Cheats tab, with an Enable cheats switch: infinite eggs, feathers, Glowbos and ice keys.
- Notice toasts appear at the top right and fade after 3 seconds.
- Graphics settings apply live, and Aspect Ratio has a Letterbox 16:9 choice.
- A hang watchdog writes logs/hangs.log when no frame is shown for 5 seconds.
- Save backups, and a crash handler that writes crash dumps.
- Fill also widens what the game draws, not just the picture.
- Settings and saves are kept next to the exe by default.
- Fixed a freeze in the intro after the Klungo scene.
- The game boots to the title screen.
