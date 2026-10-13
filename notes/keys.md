# Keyboard and controller shortcuts

Every shortcut this port adds, checked against the code. A setting is noted
where one changes a shortcut. Keys are on the keyboard; the controller has no
extra shortcuts of this port's own.

| Key | What it does | Setting that changes it |
| --- | --- | --- |
| **Esc** (keyboard), **Back** / **Select** (controller) | Opens the settings menu. The menu framework handles this key, so it is not in this port's code. | None. |
| **F1** | Hides or shows the HUD and text boxes (the 2D drawn over the picture). The pause menu's text is hidden too. A toast says "HUD hidden" or "HUD shown". | None. |
| **F2** (hold) | Speed-up: the game runs faster while F2 is held. | **Speed-up factor** (2 to 4, default 3) sets how fast. |
| **F2** (press) | With **Speed-up toggle** on, F2 switches the speed-up on and off. | **Speed-up toggle** (default off). Off means F2 must be held. |
| **F9** | Repeats the last level warp. Does nothing until you have picked a place in Level warp. | Works only when **Debug tab** is on (General tab, default off). |
| **F12** | Saves a screenshot of the game picture to `screenshots\` next to the exe, named by date and time. A toast says "Screenshot saved" or "Screenshot not saved". | None. |

The screenshot is the game picture only. Menus and notices are not in it.
