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
- **Save backups to keep**: how many of the newest save backups to keep.
  Range 1 to 100. Default: 10.
- **Speed-up factor**: how much faster the game runs while the speed-up key
  (F2) is active. Range 2 to 4. Default: 3.
- **Speed-up toggle**: press F2 to switch the speed-up on and off, instead of
  holding it. Default: off.

The General tab also has a rumble strength option. It comes from the menu
framework, not from this port's code, so it is not described here.

## QOL

- **Press Start Early to Skip Intro**: press Start during the logos and title flight to go
  straight to the file select. Default: on.
- **Text speed**: how fast dialogue text prints: 1x, 2x, 4x or Instant (a
  page at a time). Menus are not affected. Default: 1x.
- **Level transitions**: how fast the screen wipe plays when you go to another
  area: Original, Fast (4x) or Instant (16x). Cutscene fades are not affected.
  Default: Original.

## Graphics: Aspect Ratio

Sets how the picture fits the window. Default: Fill.

- **4:3**: keeps the game's original shape.
- **Fill**: widens the view to the window's shape.
- **Letterbox 16:9**: widens the view to 16:9 and adds black bars in windows of
  any other shape.

Graphics changes apply at once. Graphics API needs a restart.

## Cheats

Cheats are in their own tab. Turn on **Enable cheats** first. Every cheat below
is off by default and only shows while **Enable cheats** is on. Turning
**Enable cheats** off resets all the cheats below. Achievements cannot be earned
while cheats are on.

- **Infinite eggs**: blue, fire, ice, grenade, clockwork and mine eggs have no
  limit.
- **Infinite feathers**: red and gold feathers have no limit.
- **Infinite Glowbos**: Glowbos have no limit.
- **Infinite ice keys**: ice keys have no limit.
- **Levitate**: hold D-pad down to float upwards.
- **Infinite jumps**: press A again in mid-air to jump again, and hold A to keep
  rising.
- **Cheato: FEATHERS, EGGS, FALLPROOF, HONEYBACK, JUKEBOX, GETJIGGY,
  SUPERBANJO, SUPERBADDY, HONEYKING, NESTKING and HOMING**: the game's own
  Cheato codes, switched on directly without the Code Chamber. Turning one off
  only undoes what this setting switched on, so a code you typed in the game
  stays on. Close the game with them off if you do not want them in your
  save.
- **Unlock all moves**: every move counts as learned. Your save file is not
  changed.
