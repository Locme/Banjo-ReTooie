# Keyboard and controller shortcuts

Every shortcut this port adds, checked against the code. A setting is noted
where one changes a shortcut. Keys are on the keyboard; the controller has no
extra shortcuts of this port's own, except the Tiptoe key (Left stick click by
default, under Hotkeys in the Controls tab) and the Speed-Up key if you bind it
(under Cheats in the Controls tab).

| Key | What it does | Setting that changes it |
| --- | --- | --- |
| **Esc** (keyboard), **Back** / **Select** (controller) | Opens the settings menu. The menu framework handles this key, so it is not in this port's code. | None. |
| **F1** | Hides or shows the HUD and text boxes (the 2D drawn over the picture). The pause menu's text is hidden too. A toast says "HUD hidden" or "HUD shown". | Rebind it (the **Hide HUD** key) under **Hotkeys** in the Controls tab. |
| **F2** (hold), the **Speed-Up** key | Speed-up: the game runs faster while the key is held. Works only while **Enable cheats** and **Speed-up** are both on (Cheats tab). | Rebind it (keyboard and controller) under **Cheats** in the Controls tab; the controller has no default. **Speed-up factor** (2 to 4, default 3) sets how fast. |
| **F2** (press), the **Speed-Up** key | With **Speed-up toggle** on, the key switches the speed-up on and off. | **Speed-up toggle** (Cheats tab, default off). Off means the key must be held. |
| **Left stick click** (L3, hold), the **Tiptoe** key | Tiptoe: while held, the left stick is capped to the tiptoe tilt, so Banjo tiptoes at any tilt. The game still sees every button as usual. | Rebind it (keyboard and controller) under **Hotkeys** in the Controls tab. The keyboard has no default. |
| The **Run** key (not bound by default) | Hold to run: Banjo-Kazooie, Banjo alone and Kazooie alone run 1.5 times as fast, with a sprint animation (Banjo leans forward with a longer stride and arms held in; Kazooie leans in with a longer, bouncier stride). Any stick tilt runs at full speed while it is held. It has nothing to do with B or the roll. | Bind it (keyboard and controller) under **Movement** in the Controls tab. QOL > Running turns it off. |
| **F3**, the **Frame Rate Overlay** key | Steps the frame rate overlay through Off, Compact and Full for this session. A toast names the new mode. | Rebind it (keyboard and controller) under **Hotkeys** in the Controls tab. **Frame rate overlay** (Graphics tab) sets how a session starts. |
| **F7** | Interpolation check, a debug view for frame interpolation: a model whose blend between frames looks wrong (a sudden jump, or parts that cannot be blended) turns red for about a third of a second, and a line naming it goes to `logs/console.log`. A toast says "Interpolation check on" or "off". Shows nothing with Interpolation Off, which does not blend. | Rebind it (the **Interpolation Check** key) under **Debug** in the Controls tab. **Interpolation check** (Graphics > Debug) switches it from the menu. |
| **F5**, the **Blend Mode** key | Steps through the five interpolation blend modes (normal, no tags, tags with vertex blending, camera untagged, models snap) for finding what blends wrong; a toast names the mode. Shows nothing at Original. | Rebind it under **Debug** in the Controls tab. **Interpolation blend mode** (Graphics > Debug) picks one from a list. |
| **F6** | Effect debug view (Graphics > Debug), for checking the picture effects: each press steps to the next view (Shift+F6 back): the effects pass's own views (the effects alone, with ambient occlusion and outlines grey, rim light lighter, fog blue, sky magenta; the depth, near white, far dark, sky blue; the surface directions worked out from the depth; the water, red where the game draws water, yellow where it reflects), then each effect and filter on its own with all the others off, then off. A toast names the view. The HUD is drawn as normal over it. | Rebind it (the **Effect Debug View** key) under **Debug** in the Controls tab. **Effect debug view** (Graphics > Debug) picks a view from a list. |
| **F8** | Compare: the picture effects (the Graphics tab's ambient occlusion, fog, outlines, rim light, bloom, eye adaptation, underwater tint, sharpening, contrast, saturation, vignette and grain) only on the left half, the original on the right, with a white line between. Press again to turn it off. SMAA and the Retro filters aren't split. | Rebind it (the **Effect Compare** key) under **Debug** in the Controls tab. **Effect compare** (Graphics > Debug) switches it from the menu. |
| **F9** | Repeats the last level warp. Does nothing until you have picked a place in the Warp tab. | Rebind it (the **Warp Again** key) under **Debug** in the Controls tab. Works only when **Enable cheats** and **Warp tab** are both on (both in the Cheats tab, default off). |
| **F12** | Saves a screenshot of the game picture to `screenshots\` next to the exe, named by date and time. A toast says "Screenshot saved" or "Screenshot not saved". | Rebind it (the **Screenshot** key) under **Hotkeys** in the Controls tab. |

The screenshot is the game picture only. Menus and notices are not in it.

