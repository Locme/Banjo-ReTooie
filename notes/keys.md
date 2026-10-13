# Keyboard and controller shortcuts

Every shortcut this port adds, checked against the code. A setting is noted
where one changes a shortcut. Keys are on the keyboard; the controller has no
extra shortcuts of this port's own unless you bind one (only the Speed-Up key
can be bound).

| Key | What it does | Setting that changes it |
| --- | --- | --- |
| **Esc** (keyboard), **Back** / **Select** (controller) | Opens the settings menu. The menu framework handles this key, so it is not in this port's code. | None. |
| **F1** | Hides or shows the HUD and text boxes (the 2D drawn over the picture). The pause menu's text is hidden too. A toast says "HUD hidden" or "HUD shown". | None. |
| **F2** (hold), the **Speed-Up** key | Speed-up: the game runs faster while the key is held. Works only while **Enable cheats** and **Speed-up** are both on (Cheats tab). | Rebind it (keyboard and controller) under **Hotkeys** in the Controls tab; the controller has no default. **Speed-up factor** (2 to 4, default 3) sets how fast. |
| **F2** (press), the **Speed-Up** key | With **Speed-up toggle** on, the key switches the speed-up on and off. | **Speed-up toggle** (Cheats tab, default off). Off means the key must be held. |
| **B** (hold) | Tiptoe: while held, the left stick is capped to the tiptoe tilt, so Banjo tiptoes at any tilt. B is hidden from the game while held; a tap under 0.2 seconds still counts as B. | **Tiptoe button** (QOL tab): Off, B, Left stick click or Right stick click. Default: B. |
| **F9** | Repeats the last level warp. Does nothing until you have picked a place in the Warp tab. | Works only when **Enable cheats** and **Warp tab** are both on (both in the Cheats tab, default off). |
| **F12** | Saves a screenshot of the game picture to `screenshots\` next to the exe, named by date and time. A toast says "Screenshot saved" or "Screenshot not saved". | None. |

The screenshot is the game picture only. Menus and notices are not in it.
