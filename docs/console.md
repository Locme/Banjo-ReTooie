# Developer console

Ported from the Mario Party 3 port's console (`src/game/console.cpp`). Like the rest of this code it is written by AI
agents to Locme's direction, and it has only been compile-checked so far, not run.

This page covers every command in the console's command table and every one-word shortcut. The same usage lines are
printed in the game by `help`.

## Ways in

* **In the game:** the `` ` `` key (left of 1, any keyboard layout) opens a prompt over the bottom of the window. Enter
  runs the line, Up and Down walk the history (the last 64 lines), Page Up and Page Down scroll the output, and `` ` ``
  closes the prompt. Backtick and tilde characters in a typed line are removed before it runs. The settings menu (Esc)
  closes the prompt, and the prompt cannot open while the menu is up.
* **Scripts:** each line on stdin is a command (`BanjoReTooie < test.txt`, or a pipe). `--exec <file>` and
  `TOOIE_CONSOLE="cmd; cmd"` do the same. No window focus is needed. Lines that start with `#` are comments, both on
  stdin and in a file run by `exec`.
* **Tools beside the game:** a program that did not start the game writes its commands, one per line, to
  `console_inbox.txt` in the game's config folder: the one with the `Dev Files` folder, `mods` and `saves` (for a
  portable install, the game's own folder; `console_state.txt` can be elsewhere). The game takes the file about five
  times a second: it renames it, runs its lines and deletes it. Write a `.tmp` file first and rename it to
  `console_inbox.txt`, so the game never reads half a line. Results go to stdout and the log as usual.
* **Tab:** in the prompt, Tab completes the first word of the line, while the line has no space yet. If one command name
  or alias starts with what is typed, it is filled in with a space after it. If several match, they are printed on one
  output line. Only command names and your own aliases are completed: not shortcuts, command aliases such as `ls`, or
  setting names. Tab may also move focus in the UI, which is untested.

## Output

Results print to stdout as `[command] text`, one line per line of text, and failures as `[command] ERR text`. The
prompt shows the newest 14 lines and keeps the newest 400. `clear` empties what the prompt keeps but not what was
already printed to stdout.

Three lines come from the console itself rather than a command. `READY launcher` appears when the launcher is on
screen, `READY game` on the first game update, and `IDLE` when the queue has run out of commands.

## console_state.txt

`console_state.txt` in the app folder is rewritten about once a second, for tools that cannot read stdout. It holds
these lines:

```
ready 1
game_started 0 or 1
map <map number, -1 before the game runs>
frames <game updates since the program started>
queued <commands waiting in the queue>
busy 0 or 1 (1 while commands are queued or the queue is held)
errors 0 or 1 (1 once any command has failed)
last <the last output line>
```

## Syntax

* Command names, keywords and names of settings, cheats, lists and enemies are not case sensitive.
* Put several commands on one line with `;`. An `alias`, `bind`, `repeat`, `if` or `break` line is the exception:
  the rest of the line is kept as one body, and the `;` split happens when that body runs.
* Commands run in order from one queue. A failed command prints `ERR`, and the commands after it still run.
* Numbers are decimal, or hex with `0x` in front. Addresses are always hex, with or without `0x`. An address below
  `0x80000000` is taken as a physical address, and `0x80000000` is added to it. An address has to be inside RAM and
  aligned to the size of the value.
* Sizes are `8`, `16` or `32` (bits), or the words `b`, `h` and `w`. The longer forms `byte`, `half`, `word`, `u8`,
  `u16`, `u32`, `s8`, `s16` and `s32` also work. Where a size is optional and not given, the console works it out from
  the value typed. Hex digits decide it: up to two digits is one byte, up to four is two bytes, more is four. A decimal
  value up to 255 is one byte, up to 65535 is two, and larger is four. A negative value is four bytes.
* Some commands need the game running. These are `status`, `savestate`, `spawn`, `diff`, `perf`,
  `press`, `peek`, `poke`, `expect`, `find`, `freeze`, `flag`, `pos`, `goto`, `walkto`, `face`, `look`, `transform`, `pause`,
  `resume`, `step`, `timescale`, `break`, `if`, `findptr`, `gfx`, `hang`, `sweep`, `photo`, `invincible`, `jiggies`, `challenge`, `lights`, `recall`, `play` and `input`. Until the game
  is running they wait at the front
  of the queue, so `start; status` works on one line. If the game never starts, they never run. The frame,
  control, map and until forms of `wait` report an error instead of waiting. `load`, `goload` and `warp` work in the launcher too, and start the
  game themselves.
* A length of time is a number with `ms` or `s` after it and no space (`200ms`, `1.5s`), counted on the clock. A plain
  number of frames is game updates, and at an Unlocked frame rate there can be 300 to 600 of those a second.
* Nothing runs until the launcher is on screen, or until the game has started some other way.

## Starting and quitting

### `start`

Usage: `start`

Presses Play in the launcher. The Banjo-Tooie ROM has to have been loaded once in the launcher, or `start` reports an
error. If the game is already running, it says so and does nothing. Otherwise it hides the launcher and the other
menus. The launcher's Play option also sets the picture preset. `start` does not.

```
start
start; warp place 1
```

Catch: `start` works before the game runs, so it can be the first line of a script.

### `quitprompt`

Usage: `quitprompt [open | close]`

Shows the prompt that closing the window or Alt+F4 opens ("Leaving so soon?", in the brown and gold look of the
game's menus), or shuts it. `open` is the default. Its Quit button exits the game, as from the window.

```
quitprompt
screenshot ui
quitprompt close
```

### `load`

Usage: `load [file 1-3] [timeout s]`

Gets into a save file with no hands, from the launcher, the logos and title (map 0x18B) or the file select (map 0x158).
The file is 1 when not given, and the timeout is 60 seconds (600 at most). In the launcher it starts the game as `start`
does. On the logos or the title it asks for the file select, as Start does with Quick start on. On the file select it
moves the cursor with the stick until the game's open-file byte (0x8012B3F1) shows the file, then presses A for 200 ms,
and again every 3 seconds while the file select is still up. Every press is timed on the clock, so the frame rate does
not matter. The queue is held until a save file is loaded (the same test as `wait save`) and the file's first map has
finished coming in. Then it prints `file 1 loaded after 9.3 s` with the map.

```
load
load 2
load 3 90
```

Catch: when another file is already loaded, or the game loads another one, it reports `ERR file 2 is loaded, not file 1`
and the queue goes on. It does not go back to the file select by itself. When the timeout passes, it reports `ERR file 1
did not load` with the map and the file the cursor was on, and lets go of the controller.

Catch: an empty file starts a new game, and its opening cutscene already counts as loaded.

Catch: how the cursor is read, and which way the stick moves it, come from the game's code and are learned while it
runs. This has not been run yet. If the cursor never gets to the file, the timeout ends it.

### `goload`

Usage: `goload <file 1-3> <map hex> [exit hex]`

`load` and a warp in one line, for test scripts. Once the file is loaded it runs `wait 30`, `warp id <map> <exit>`,
`wait map <map> 60` and `wait 30` at the front of the queue, so the script's next line runs with Banjo in the map. The
exit is 0 when not given. The load's timeout is 60 seconds.

```
goload 1 AF
goload 2 1A 1
```

Catch: when the load fails, the warp and its waits do not run, so a script does not sit through their timeouts. When the
file is already in that map, the warp does nothing and the `wait map` ends at once.

Catch: after a Jiggywiggy challenge the game no longer says which file is open, so `load` and `goload` take the save
that is loaded as the one asked for and say so, rather than stopping.

### `quit`

Usage: `quit [code]` (also `exit`)

Ends the program. Without a code, the exit code is 1 if any command has failed during the run, and 0 if none has. A
code given is used as it is. The code must be a whole number.

```
quit
quit 0
```

Catch: `quit 0` exits with 0 even after failures. The program ends at this point, so commands after `quit` do not run.

### `help`

Usage: `help [command]` (also `?`)

With no argument, prints the usage and description of every command. With a command name or alias, prints that
command's usage and description.

Any other word searches the commands. It matches the usage and the description of each command, ignoring case, spaces
and punctuation, and prints every command that contains it. Shortcuts are not searched.

```
help
help warp
help backup
```

Catch: the full list is long. `help <command>` is the quick way to check one command.

### `close`

Usage: `close`

Hides the prompt. The `` ` `` key does the same. It does not touch the game.

```
close
```

### `clear`

Usage: `clear` (also `cls`)

Empties the output the prompt keeps. Lines already printed to stdout and the session log are not changed.

```
clear
```

## Warping

### `warp`

Usage: `warp <list> <n|name> | warp <name> | warp id <map hex> [exit hex]` (also `go`)

Warps through the Warp tab's own code, and the prompt closes once the warp has been made. Before a save file is being
played (the launcher, the logos and title screen, the file select) it loads file 1 first, as `goload` does, then
warps and holds the queue until Banjo can move in the new map (`wait control`), so a script can start with a warp as
soon as the game boots.

* `warp <list> <n|name>` warps to an entry of a list. The lists are `place` (also `places`, `level`, `levels`), which
  is the Warp tab's places, meaning levels, areas and the test room, and `map` (also `maps`), which is every map in
  `map_names.inc`. A number after the list name is that entry's position in `list`.
* `warp <name>` looks for the name in both lists. An exact match wins. Otherwise a part of a name works when only one
  entry has it. A number without a list name is not a position, so it is searched as text.
* `warp id <map hex> [exit hex]` warps to a map by its id, with up to four hex digits. The exit is 0 to FF, and 0 when
  not given. The id is not checked against the map list, and a map with no name is shown as "unnamed map".

Names are compared without case, spaces or punctuation. If several entries match, the console lists up to 12 of them
and warps to none. A map warp uses exit 0.

```
warp place 3
warp place test room
warp id 1A 0
```

Catch: the load before it is file 1's, with `load`'s 60 second timeout; use `goload` for another file. When the load
fails, the warp is not made.

### `list`

Usage: `list [list] [filter]` (also `ls`)

With no argument, prints the two lists and how many entries each has. With a list name, prints that list's entries with
their numbers, which are the numbers `warp <list> <n>` takes. A filter after the list name shows only the entries whose
name contains it, compared the same way as names in `warp`.

```
list
list place test
```

Catch: a list name other than `place` or `map` (or their aliases) is an error.

## Settings

The settings commands reach the options of the settings tabs (`general`, `graphics`, `sound`, `qol`, `cheats` and
`wip`) that the menu shows. The `debug` tab has no settings in this build. Options the menu hides cannot be reached,
except `graphics.hpfb_option` (High Precision Framebuffer: `Auto`, `On` or `Off`), which the menu never shows.
A setting is changed the way the settings menu changes it. The option's change callbacks run and the tab is saved
straight away. A tab that waits for Apply in the menu, like Graphics, is applied at once here.

A setting is named by its id (`day_night`), by `tab.id` (`graphics.day_night`), or by its name with the spaces left in
or out (`Day Night`). A part of a name works when only one setting has it. If several match, the console lists up to 12.

A value is typed in the form the setting takes:

* On or off: `on`, `off`, `1`, `0`, `true`, `false`, `yes`, `no`, `enable`, `disable`, `enabled` or `disabled`.
* A number: it is limited to the setting's minimum and maximum, and moved to its step.
* A choice: its key, its name, its number, or a part of its name that only one choice has.
* A text setting takes any text.

A setting the menu greys out because another setting turns it off is refused, and the console says which setting does
that.

### `settings`

Usage: `settings [filter]` (also `options`)

Prints every setting as `tab.id = value   (Name)`. With a filter, only the settings whose full id or name contains it
are printed.

```
settings
settings graphics
```

Catch: with no filter the output is long.

### `get`

Usage: `get <setting>`

Prints the setting's value, and what the setting takes.

```
get msaa_option
```

### `set`

Usage: `set <setting> <value>`

Changes the value and saves the config.

```
set day_night off
set force_scene_interpolation on
set hpfb_option on
```

Catch: the value is checked against the setting. A value the setting does not take is an error, and `get` shows what
it takes.

### `toggle`

Usage: `toggle <setting>`

For an on/off setting, flips it. For a choice, moves to the next choice, skipping any that the menu greys out. Other
kinds of setting are an error, and `set` is used for them.

```
toggle day_night
```

### `reset`

Usage: `reset <setting>`

Sets the setting back to its default. The output ends with "(default)".

```
reset day_night
```

Catch: a setting that is greyed out is refused, as with `set`.

### `fps`

Usage: `fps [value]`

Without a value, prints the Game Frame Rate setting. With a value, sets it the same way `set` does. A number matches the
choice whose name contains it, because the frame rate choices are named such as "Original (30)".

```
fps
fps 30
```

Catch: only the values the setting offers are accepted.

### `aspect`

Usage: `aspect <w:h>`

Resizes the game window. The height stays the same and the width becomes the height times w divided by h. The ratio
can be written with `:`, `x` or `/`. Nothing is saved. A fullscreen window is refused, so this works in windowed mode
only.

```
aspect 4:3
aspect 21x9
```

### `dev`

Usage: `dev [on|off]`

`dev` or `dev on` writes `dev.txt` next to the exe. `dev off` removes it. While `dev.txt` is there, the hidden tabs (DEV,
Cheats, Warp and Achievements) show from the next launch, so the game has to be restarted. The settings commands do not
depend on `dev.txt`.

```
dev on
dev off
```

Catch: `dev.txt` is written next to the exe, not in the app folder.

### `mod`

Usage: `mod list | mod on <id> | mod off <id>` (also `mods`)

`mod list` prints the mods the launcher's Mods menu shows: on or off, the id, the display name and the version. A mod
that cannot be switched while the game runs is marked "needs a restart". `mod on` and `mod off` enable or disable a mod
by its id. An id that is not a mod is refused. The command does not restart the game.

```
mod list
mod off <id from mod list>
```

### `texpack`

Usage: `texpack reload`

Loads every enabled texture pack again from its folder: `rt64.json` and the image files, as switching a pack off and
on in the Mods menu does. For tools that change a pack's files while the game runs (`tools/texture_forge.py`). It
happens on the next frame. Every replacement is unloaded and streams back in, so the pack's textures show their
originals for a moment. A pack shipped as a `.zip` reloads from the folder it was unpacked into.

### `config`

Usage: `config export <folder> | config import <folder>`

`export` copies every settings file (the `.json` files in the config folder) into the folder. `import` copies the
`.json` files from the folder into the config folder, replacing any with the same name. A relative folder is taken from
the app folder, and the folder name can contain spaces. The output says how many files were copied.

```
config export settings-copy
config import settings-copy
```

Catch: import needs a restart, and the command says so. Files that are not in the source folder are left alone, so an
import does not clear the other settings. If no `.json` files are found, it is an error.

### `profile`

Usage: `profile save <name> | profile load <name> | profile list`

`profile save` writes the value of every setting into `console_profiles` in the app folder, as `<name>.txt`. Each line is
a `set` command. The name keeps only its letters and digits, in lower case, so `Fast Run` and `fastrun` are the same
profile. Settings on the Debug tab and text settings are left out, and so is any setting whose value the console cannot
read. `profile load` runs that file as `exec`, so each setting is set the way `set` sets it. `profile list` prints the
profile names.

```
profile save fast
profile load fast
```

Catch: a setting the menu greys out is refused when the profile loads. That shows as `ERR`, and the other lines still run.

## Quick testing

These commands set a test up in a few words and let you go back to it. A mark keeps a spot, a scenario is a file of
commands that sets a test up, and a recording plays controller 1 back. The rest work on the session and on the files
beside the game: a stopwatch, the autoexec file, the typed history, a search of the console's own lines, and the folders.

Worked example: mark a spot, save a scenario from where Banjo is, then boot straight into that test each time the game
starts. Mark the spot and save the scenario in the game:

```
mark ledge
scenario save ledge_test
```

Then put this line in `autoexec.txt` in the game folder (`autoexec` prints where that is):

```
scenario ledge_test
```

Each start runs the scenario. Its first line, `wait save`, holds it until you press Play and load a save file (warps
need one). Then the warp takes Banjo to the saved map and the `goto` puts him where he stood when `scenario save` ran.
The scenario sets the ten named item counters to their saved values on every start too. The mark is separate:
`scenario save` does not read it, and `recall ledge` uses it later.

Worked example: a whole test with no hands, from the launcher. Save it as `test.txt` and run `BanjoReTooie < test.txt`
(or `--exec test.txt`):

```
# into file 1, then Spiral Mountain (map AF)
goload 1 AF
# walk up to a spot, turn to what is there, and jump
pos
walkto 1200 -340 20 15
face 1300 -340
press a 200ms
wait 1s
# check where Banjo ended up and keep a picture
pos
screenshot
wait 500ms
quit
```

`goload` starts the game, gets through the title and the file select, loads file 1 and warps, and holds the queue until
Banjo is in the map. `walkto` holds it again until he is within 20 of the point, for 15 seconds at most. The jump's 200
ms is clock time, the same at any frame rate, where `press a 5` would be over in about 10 ms at an Unlocked frame rate.
A step that fails prints `ERR`, and `quit` then exits with code 1. The numbers are only an example: run `pos` where
Banjo should go to get real ones.

Worked example: a rendering sweep, the same spot from four sides. Entering Jiggywiggy's Temple (map 151) plays the
monolith scene every time, and a `goto` made during it is undone, so `wait control` comes first:

```
goload 1 151
wait control
goto 0 0 0
wait control
look 0 -20
wait 100ms
screenshot
look 90 -20
wait 100ms
screenshot
look 180 -20
wait 100ms
screenshot
look 270 -20
wait 100ms
screenshot
look off
```

Each `look` puts the camera 350 back from Banjo's head, on the side the view comes from, and points it at him, so he
is in the middle of all four pictures. A wall in the way pulls the camera in front of it. The `wait 100ms` lets the
game draw from the new angle before `screenshot` keeps the frame. Put real coordinates from `pos` in place of `0 0 0`,
and add a distance (`look 0 -20 600`) to take in more of the room.

### `mark`

Usage: `mark <name> | mark list | mark delete <name>`

Keeps Banjo's map and position under a name, in `marks.txt` in the game folder. The name is not case sensitive and is
kept in lower case. Marking a name that already exists replaces it. With no argument, `mark` lists the marks, the same as
`mark list`. `mark delete` also takes `del`.

```
mark ledge
mark list
mark delete ledge
```

Catch: a mark holds only the map and the position, not the rest of the game. Catch: needs the game running and a player.
Without them it reports `the game has to be running` or `there is no player yet`. In `marks.txt`, a line that does not
read as a name, a hex map and three numbers is skipped, and a line that starts with `#` is a comment.

### `recall`

Usage: `recall <name>`

Goes back to a mark. When the mark is in the map Banjo is in, it runs `goto` with the saved position. When it is in
another map, it runs `wait save`, `warp id <map>`, then `wait map <map>`, then `wait 30`, then the `goto`. The 30 game updates let the
game place the player once the map is in.

```
mark ledge
recall ledge
```

Catch: a warp to another map waits for a save file to be loaded (`wait save`). Catch: if the map does not arrive, the `wait map` gives up when its
timeout runs out, which is 120 seconds unless the wait is given another. Catch: `recall` waits at the front of the queue
until the game is running.

### `scenario`

Usage: `scenario <name> | scenario list | scenario save <name> | scenario delete <name>` (also `sc`)

`scenario <name>` runs `scenarios/<name>.txt` in the game folder, next to the exe, as `exec` does. `scenario list` prints
the names. `scenario save <name>` writes a file from where Banjo is now: `wait save`, `warp id` for his map, `wait map`, `wait 30`, a
`goto` to his position, then an `item` line for each of the ten named item counters with its value. Those counters are
the blue, fire, ice, grenade, clockwork and proximity eggs, the red and gold feathers, Glowbos and the ice keys.
`scenario delete <name>` removes the file.

```
scenario save ledge_test
sc ledge_test
scenario list
```

Catch: `scenario save` writes only the map, the position and those ten item counters. Any other command has to be added
by hand, by editing the file. A scenario file is a plain list of console lines, and `#` lines are comments.

Catch: running a scenario sets those ten item counters to the values saved, every time it runs.

Catch: `scenario save` needs the game running and a player.

### `record`

Usage: `record <name> | record stop | record list` (`record off` also stops)

`record <name>` starts recording controller 1 under that name. The recording keeps one line per game update: the update
number from when recording began, the buttons in hex, and the stick x and y. Input from `press` is recorded too, because
`press` is added to controller 1 before it is recorded. `record stop` ends the recording and writes
`inputs/<name>.txt` in the game folder. `record list` prints the recordings, and `record` alone does the same.

```
savestate save
record jump_test
# play the test in the game
record stop
```

Catch: the file is written only by `record stop`. If the program ends while a recording is running, the recording is lost.

Catch: only one recording can run at a time. `record <name>` while another is running reports `already recording`. The
timing is per game update, so read the `play` section before relying on a replay.

### `play`

Usage: `play <name> | play stop`

Plays `inputs/<name>.txt` back as controller 1, starting on the next game update. While it plays, the game's own
controller 1 input is ignored. When the last line has been played, it prints `playback finished`. `play stop` ends it
early. A press still adds on top: `press` adds its buttons to the playback, and a press with a stick replaces the stick.

```
savestate load
play jump_test
```

Catch: playback follows the game update count, not the frame, so a replay is not exact to the frame. Pair it with
`savestate save` before the `record` and `savestate load` before the `play` to start both from the same place.

Catch: needs the game running, so `play` waits in the queue until then. A recording with no lines reports `is empty`.

### `input`

Usage: `input`

Prints the buttons and stick the game got on controller 1 last. The buttons show as hex and by name, joined with `+`. The
stick shows as x and y in the range of 80, which is the range `press` takes, rounded to whole numbers. It reports
`no controller` when the last read had none. Because it shows what the game got, a value from `press` or `play` shows
here as well.

```
press a+b
input
```

Catch: needs the game running, so `input` waits in the queue until then.

### `timer`

Usage: `timer start | timer stop | timer show`

A stopwatch for practice runs. `timer start` starts it, clears any splits from before, and splits on every map change.
A split is named for the map Banjo left, and shows its seconds and game updates. `timer show`, the default with no word,
prints every split, a `so far` line for the map Banjo is in, and a total. `timer stop` prints the same and stops the
splits. After that, `timer show` prints the splits and `stopped`.

```
timer start
timer show
timer stop
```

Catch: a split waits until a map change that is still in progress has finished. Catch: the seconds are the console's own
clock, so they are wall-clock time. Catch: `timer start` needs the game running, and `timer show` before any start reports
`the timer has not run`.

### `autoexec`

Usage: `autoexec [run]`

With no argument, prints where `autoexec.txt` is in the game folder, and whether it exists. When it exists, its lines run
each time the program starts. They run before the `--exec` files and `TOOIE_CONSOLE`. `autoexec run` runs it now, as
`exec` does.

```
autoexec
autoexec run
```

Catch: `autoexec run` reports an error when the file does not exist. Catch: any line that needs the game, such as `warp`
or `press`, waits until the game has started, as it does anywhere in the console.

### `grep`

Usage: `grep <text>`

Prints the console's lines that hold the text, not case sensitive. The text is the rest of the line, so it can have spaces,
and it is plain text rather than a pattern. Lines typed at the prompt show with `> ` in front, as they were typed. The
`grep` line itself is left out.

```
grep ERR
grep warp id
```

Catch: `grep` searches only the console's own lines held in memory for this session: the newest 400 that the prompt keeps.
Lines that `clear` removed, or that have fallen out of those 400, are not found. It does not read any file, including
`console_history.txt`.

### `history`

Usage: `history [clear]`

Prints the commands typed at the prompt, oldest first. This is the list that Up and Down walk, and it keeps the last 64.
It is saved in `console_history.txt` in the game folder each time a line is typed, and loaded at the next start.
`history clear` empties the list and the file.

```
history
history clear
```

Catch: only lines typed at the prompt are kept. Lines piped in on stdin, run from a file, or run by a bind or an alias are
not. Catch: a line the same as the one before it is not added again.

### `open`

Usage: `open <config|game|mods|saves|backups|screenshots|scenarios|inputs>` (also `data`, `exe`, `app`, `save`, `shots`
and `recordings`)

Shows one of the game's folders in the file manager, and prints its path. A folder that is missing is created first. The
folders are:

* `config` (`data`): the config folder.
* `game` (`exe`, `app`): the game folder, where the exe and `autoexec.txt` are.
* `mods`: the mods folder.
* `saves` (`save`): the folder the save file is in, or the saves folder in the config folder when no save file is set.
* `backups`: `save_backups` in the config folder.
* `screenshots` (`shots`): `screenshots` in the config folder.
* `scenarios`: the `scenarios` folder in the game folder.
* `inputs` (`recordings`): the `inputs` folder in the game folder.

```
open game
open scenarios
```

Catch: the folder opens through the system's handling of a file link. If that call fails, the command prints `ERR` with the
message from SDL.

## Cheats and spawning

The Cheats tab's on/off cheats are the cheats that `cheat` lists. The master switch, `cheats_enabled`, is not one of
them. Cheats only work while the master switch is on. Setting a cheat on turns the master switch on, and that is saved.

### `cheat`

Usage: `cheat [name] [on|off]`

With no argument, prints whether the master switch is on, and then every cheat with its value and name. With a name, sets
that cheat. A cheat is named by its id (`noclip`), by its id with `cheat_` in front, by its name, or by a part of its id
or name that only one cheat has. With no value, the cheat is flipped.

```
cheat
cheat noclip on
cheat one_hit
```

Catch: turning a cheat off does not change the master switch. The master switch stays on until it is turned off with
`set cheats_enabled off` or in the Cheats tab.

### `unlock`

Usage: `unlock moves | unlock everything`

Turns on the Unlock all moves cheat (`all_moves`) or the Unlock everything cheat (`unlock_everything`). The master switch
is turned on as well. The save file is not changed. `unlock` only turns the cheat on. To turn it off, use
`cheat all_moves off`.

```
unlock moves
unlock everything
```

### `transformmenu`

Usage: `transformmenu [open|close]`

Opens or shuts the Transform Anywhere Menu (Graphics > WIP), as the Transform key does. An open waits until Banjo can
transform (no pause, scene, talk or map change under way, and the map change's wipe gone), so it can be given right
after a warp. With no word, it says
whether the menu is on and whether it is up. While it is up, `press` picks the form the stick or the d-pad points at
(`press up` the one ahead of Banjo, at the top of the ring), `a` changes form and `b` goes back.

```
set transform_menu on
transformmenu open
wait 1s
screenshot
transformmenu close
```

Catch: the menu shows only the forms the save file has been at least once, by the game's own "first time" flags, so
`unlock everything` adds none. `flag 345 on` to `flag 34D on` (Humba's forms) and `flag 4F5 on` (Banjo and Kazooie)
show them all; turn them off again after, or the save keeps them when the game saves. Needs the menu turned on and a
save file loaded.

### `savestate`

Usage: `savestate save | savestate load` (also `ss`)

Saves one snapshot in memory, or loads it. The save and load are taken on the next game update. A new save replaces the
old snapshot. The snapshot is lost when the program ends. The usage text says this works in a level only, but the code
checks only that a save file is loaded.

```
savestate save
ss load
```

Catch: needs a save file loaded.

### `spawn`

Usage: `spawn [enemy|number] [count]`

With no argument, prints the enemies with numbers. With an enemy name or number, spawns it in front of Banjo on the next
game update. The count is 1 to 20. A last word that is a number outside that range is read as part of the name, which
then matches nothing. The console turns on the cheats master switch, because the spawner is the Enemy Spawner cheat and
works only while cheats are on.

```
spawn
spawn 1
spawn 3 5
```

Catch: needs a save file loaded, and the game running.

### `transform`

Usage: `transform [form]`

Works with the Transformation row on the Cheats tab, which is the setting `cheats.cheat_transform`. With no argument,
prints the setting's value and what it takes. With a form, sets the setting in the same way `set` does.

```
transform
```

Catch: needs a save file loaded, and the game running. The command turns the cheats master switch on before it sets the
form, as `spawn` does. If the switch cannot be turned on, the form is not changed.

### `item`

Usage: `item [list] | item <name|n> [value|+n|-n]` (also `give` and `items`)

With no argument, or `list`, prints the game's 22 item counters, each with its place in the item table and its value.
The ten named places are the blue, fire, ice, grenade, clockwork and proximity eggs, the red and gold feathers, Glowbos
and the ice keys. The others show as `item N`, where N is the place. With a name or a number, prints that counter. A
name is compared the way `warp` compares names, and a part of a name works. If several names match, the first in the
table is used. A number from 0 to 21 is taken as the place, and is tried before the names. With a value, the counter is
set, and the output gives the value before and after. `+n` and `-n` add to or take away from the current value. A value
below 0 is set to 0. Setting a counter does not show the counter pop-up.

```
item list
item glowbos
item glowbos 100
item red feathers +10
item 19 1
```

Catch: item counts are kept XORed with code bytes, so `poke` cannot change them. Use `item` for them.

Catch: the game clamps a set to the item's limit, so the output shows the value the game kept, not the value typed. A
value of 999 means the item has no limit.

Catch: needs a game update running. Before the game runs it reports `no game update is running` and does not wait.

## Input

### `press`

Usage: `press <buttons> [stick <x> <y>] [frames|n ms|n s]`

Holds controller 1's buttons and stick. Buttons are `a`, `b`, `z`, `start`, `l`, `r`, the directions `up`, `down`, `left`
and `right`, the D-pad names `dup`, `ddown`, `dleft` and `dright`, and the C buttons `cup`, `cdown`, `cleft` and `cright`.
Join buttons with `+`, as in `a+b`. The stick's x and y run from -80 to 80, and larger values are limited to that range.
The length is a number of game updates, or a time with `ms` or `s` (`200ms`, `1.5s`, up to an hour), counted on the
clock. With no length, the buttons are held until `release`. A new `press` replaces what is held. The command returns
at once, so use `wait` to hold the queue while the buttons are down.

```
press a 200ms
press stick 0 80 1.5s
press a 30
press a+b 10
press start
release
```

Catch: needs the game running. Only controller 1 is affected. A count of game updates gets shorter as the frame rate
goes up: at an Unlocked frame rate `press a 5` lasts about 10 ms, and the title and the file select miss it. Use a time
in menus.

### `release`

Usage: `release`

Lets go of what `press` is holding.

```
release
```

### `mouse`

Usage: `mouse move <dx> <dy> [n ms|n s]`, `mouse stop`

Moves the mouse by `dx`, `dy` pixels (right and down are positive). The motion goes where the window's own mouse
motion goes, so General > Mouse Sensitivity scales it, and it turns the first-person view (mouse aim) and the free
camera as a real mouse would. With a time (`500ms`, `2s`) it is spread over that time on the clock, a share each game
update; with none it all arrives at once. A new `mouse move` replaces one still under way, and `mouse stop` drops what
is left. The command returns at once, so use `wait` while the motion runs.

```
mouse move 200 0
mouse move 0 -150 1s
wait 1s
mouse stop
```

Catch: needs the game running. The window's own checks come before this point, so it still moves the camera while
the cursor is shown (Tab) or a pick mode is on, which the real mouse does not. A sensitivity of 0 turns it off.

## Memory

Addresses and values are written as described under Syntax. The commands below read or write RAM in game updates.

### `peek`

Usage: `peek <address> [bytes]`

Reads RAM and prints it in rows of 16 bytes, starting with the address. The byte count is 1 to 256, and the default is 4.

```
peek 80127630
peek 0x80127630 32
```

Catch: a read past the end of RAM is an error. Needs the game running.

### `poke`

Usage: `poke <address> <value> [8|16|32]`

Writes the value once, and prints what RAM holds afterwards.

```
poke 80127630 0x05
poke 80127630 1000 16
```

Catch: the write happens once. `freeze` keeps writing a value. Needs the game running.

### `expect`

Usage: `expect <address> <value> [8|16|32]`

Checks that RAM holds the value. It prints `ok: ...` when it does, and `ERR ..., expected ...` when it does not.

```
expect 80127630 0x05
expect 80127630 0 8
```

Catch: a failed `expect` sets the error flag, so `quit` exits with 1 unless it is given a code. Needs the game running.

### `find`

Usage: `find <value> [8|16|32] [from] [to]`

Searches RAM for the value at addresses aligned to its size. Without a range, it searches the first 16 MB, from `80000000`
to `81000000`. The `to` address is the end of the range and is not searched. The output gives the number of matches,
the first 32 addresses, and `...` when there are more.

```
find 0x1234 16
find 5 8 80000000 80100000
```

Catch: needs the game running.

### `freeze`

Usage: `freeze <address> <value> [8|16|32]`

Writes the value at the start of every game update, until it is stopped with `unfreeze`. A second freeze of the same
address replaces the first. Freezes are kept in memory only, and they end when the program ends.

```
freeze 80127630 0x05
```

Catch: needs the game running.

### `unfreeze`

Usage: `unfreeze <address> | unfreeze all`

Stops one freeze, or all of them. With no argument it stops all of them.

```
unfreeze 80127630
unfreeze all
```

### `watch`

Usage: `watch [address] [8|16|32|f] [name]`

With no argument, lists the watched addresses. With an address, shows that RAM value live at the top right of the
window. The panel is refreshed every 6 game updates. The default size is a 32-bit word. `f` reads a float, shown with 4
decimal places. Other values are shown in hex with the signed decimal in brackets. A name, if given, is shown in place
of the address. Watching an address that is already watched replaces the old entry. The panel is hidden when nothing is
watched.

```
watch 80127630 8 flag
watch 80127630 f
```

Catch: the values are read during game updates, so the panel is not updated while the game is not running.

### `unwatch`

Usage: `unwatch <address> | unwatch all`

Stops watching one address, or all of them. With no argument it stops all of them.

```
unwatch 80127630
```

### `search`

Aliases: `ramsearch`, `s`

Usage: `search start [8|16|32|f] [from] [to]` | `search changed|unchanged|up|down` | `search up <n>` | `search down <n>` | `search =|!=|>|< <value>` | `search list [n]` | `search watch [n]` | `search trace [n]` | `search count`

Finds an address whose value you do not know yet. `search start` keeps every aligned value in the range, from `80000000`
to `81000000` by default. Then each filter keeps only the addresses whose value passes it, and remembers the value they
have now for the next step. After a filter it prints how many are left and the first 8.

- `changed` (or `ch`) and `unchanged` (or `same`) compare with the previous step.
- `up`, `increased` or `inc` and `down`, `decreased` or `dec` keep the addresses that went up or down at all. With a number, `up <n>` and `down <n>` keep only the ones that moved by exactly `n`.
- `=` (or `==`, `eq`), `!=` (or `ne`), `>` (or `gt`) and `<` (or `lt`) compare the current value with a number.

Values typed as `0x..` are hex, and others are decimal. The 8 and 16-bit values read as unsigned, the 32-bit values as
signed, and `f` reads floats. Float comparisons allow a difference of 0.0001.

`search list [n]` prints the remaining addresses with their values, 32 by default. `search count` prints how many are left
and how many steps were taken. `search watch [n]` and `search trace [n]` queue a `watch` or `trace` command for each of
the first `n` addresses, 8 by default and at most 32. Those run after this command.

Worked example: finding the egg count, which goes down by one each time an egg is fired.

```
search start 8
(fire an egg in the game)
search down 1
(fire another egg)
search down 1
search list
search trace
```

Each step should leave fewer addresses. When `search list` shows only a few, `search trace` prints each change to them,
so the one that moves with the egg count is the one to keep.

Catch: `list`, `watch` and `trace` refuse while more than 100000 addresses are left after `search start`. Narrow the search
first with another filter.

### `ramlog`

Usage: `ramlog <seconds> [from] [to]` | `ramlog stop`

Counts which RAM words change while you play. Every game update it compares each 32-bit word in the range with the
previous update, and counts the changes. The default range is `80000000` to `80800000`. When the time is up, or when
`ramlog stop` is given, it writes `traces/ramlog-<time>.csv` in the game folder. The file has one row per changed word:
`address,changes,of_updates,first,last`, sorted busiest first. It also prints the 8 busiest and the 8 quietest words.

```
ramlog 20
(do one thing in the game, then wait)
ramlog 60 80000000 80100000
ramlog stop
```

Only one ramlog can run at a time. It can slow the game a little.

Tip: a word that changed only a few times during one action is usually that action's state, so the quietest ones are
the ones to check first. The busiest are usually timers and the like.

Catch: only one ramlog can run at a time, so `ramlog` is refused until the running one ends.

### `trace`

Usage: `trace <address> [bytes] [8|16|32] [file <name>] [quiet]` | `trace list` | `trace stop <address>|all`

Prints every change in a RAM range as it happens. Every game update the range is compared with the previous update,
and each changed value is printed as `[frame] address old -> new`, where the frame is the game's update count. At most
16 lines are printed per update. Any others in that update are counted in a `... and N more changes this update` line.

`bytes` is decimal unless it has `0x`. It is rounded up to a whole number of values of the size. The default is one
32-bit word. The size, `8`, `16` or `32` bits, comes after `bytes`. The range can be at most `0x10000` bytes. The
address must be aligned to the size, and the range must stay inside RAM.

`file <name>` also writes every change to a CSV file as `update,address,old,new` lines. A relative name goes in the
`traces` folder of the game folder, and a name with no extension gets `.csv`. An absolute path is used as given.
`quiet` stops the printing, so it needs `file`. The output is then only in the file.

Tracing an address that is already traced replaces the old trace, and closes its file. `trace` with no argument, or
`trace list`, lists the traces with their size and number of changes. `trace stop <address>` ends one trace, and
`trace stop all` ends them all. Trace lines are also copied by `tee`.

```
trace 80127630
trace 80127630 16 16
trace 80127630 0x20 8 file run1
trace 80127630 quiet file flags
trace stop 80127630
```

Catch: the game has to be running to start a trace, and changes are only checked during game updates, so nothing is
printed while the game is paused or not running.

### `writewatch`

Usage: `writewatch <address> [seconds]` (also `ww`)

Finds what changes a value. For the given number of seconds (3 when not given, 0.5 to 60) the CPU stops the game
thread on every write to the 32-bit word at the address, and the program notes the host function that wrote it and
the two functions that called that one. Then it prints how many writes there were and the writers, most first, named
from `BanjoReTooie.pdb`: the recompiled game's own functions show as `func_<address>` or `<overlay>_entrypoint_<n>`,
the names the game's code has in `RecompiledFuncs`.

```
writewatch 80DA53FC
writewatch 0x8012AB08 10
```

Worked example: the lair's flickering light. `ramlog` showed map vertex colours at `80DA53F0` changing every update;
`writewatch 80DA53FC` printed `aligned8_memcpy <- vpmodule_entrypoint_3 <- func_800BE7F8 <- func_800BE9E4`: the map's
vertex effects copy the colours in, and the flicker is one of those effects.

Catch: only writes from the game thread are seen (the thread the console runs on). The value is read where the
program keeps the game's memory, so a write the game makes through a copy routine shows that routine first. One watch
at a time. Windows only. Needs the game running.

### `memview`

Usage: `memview <address> [rows]` | `memview off` | `memview`

Aliases: `hexview`, `mv`.

Shows a hex view of RAM in the panel at the top right of the window, the same panel as `watch`. Each row is 16 bytes,
shown as four 32-bit words after the address. `rows` is from 1 to 16 (default 4), and larger numbers are cut to 16.
The address is rounded down to a multiple of 16. The panel is refreshed every 6 game updates. `memview` with no
argument lists the ranges being shown. `memview off` removes all of them.

```
memview 80127630
memview 80127630 8
memview off
```

Catch: like `watch`, the values are read during game updates, so the panel is not updated while the game is not
running. Showing an address that is already shown replaces the old entry.

### `diff`

Usage: `diff snapshot | diff [compare] [n]` (`snapshot` can also be `snap` or `keep`)

`diff snapshot` keeps the first 16 MB of RAM, from `80000000` to `80FFFFFF`, as words. The old snapshot is replaced. `diff`
or `diff compare` then lists the words that have changed since the snapshot, as `address: old -> new`, up to `n` of them
(default 64). The output also gives the total number that changed.

```
diff snapshot
diff compare 20
```

Catch: `diff 20` is an error. The word `compare` is needed before the number. The snapshot is kept in memory only.
Needs the game running, and a snapshot taken first.

### `break`

Usage: `break <address> [value] [8|16|32] [pause] [then <commands>] | break list | break clear`

Watches one address and reports it when it hits. Without a value, it hits the first time the RAM value changes. With a
value, it hits when RAM holds that value. The check runs once per game update. A hit prints
`ADDR: old -> new at game update N`, and the break removes itself, so it hits only once. `pause` pauses the game, and
the commands after `then` run. The size is the one given, or the one the value implies. Without a value it is a word.
`break list` lists the breaks, and `break clear` removes them all.

```
break 80127630 0 16 pause
break 80127630 then echo it changed
```

Catch: everything after `then` is the body, `;` included. Set the break again to catch the next change. A value
that changes and changes back between two game updates is missed. Needs the game running.

### `findptr`

Usage: `findptr <address> [range]`

Looks through the first 16 MB of RAM (`80000000` to `80FFFFFF`), one word at a time, for the words that point at the
address. With a range, it counts the words that point at any address within the range bytes after it. The range
defaults to 4, which is an exact match. The output gives the count and the first 32 addresses found, with `...` when
there are more.

```
findptr 80127630
findptr 80127600 256
```

Catch: only words on 4-byte boundaries are checked. Needs the game running.

## Player and game state

### `flag`

Usage: `flag <hex id> [on|off]`

Reads or sets one of the game's progress flags, using the same getter and setter as the cheats. The id is hex, with or
without `0x`, and up to four digits. With no value, prints whether the flag is on or off. With `on` or `off`, sets it and
prints the result.

```
flag 0x1A
flag 1A on
```

Catch: a flag that is set stays set in the save file only if the game is saved. Needs the game running.

### `pos`

Usage: `pos`

Prints Banjo's position as x, y and z to two decimal places, the current map as hex, and the way he faces in degrees
(the yaw at PlayerState +0xF8 that `face` writes, 0 facing +z).

```
pos
```

Catch: needs a player in the game. Until there is one, it reports an error.

### `menu`

Usage: `menu open | menu close | menu tab <id> | menu expand <setting> [off]`

Opens or shuts the Esc menu, as the Esc key does. `menu tab` shows a settings tab (`general`, `graphics`, `sound`,
`qol`, `cheats`, `wip`). `menu expand` opens the arrow of a setting that has settings under it, as clicking the arrow
does, and `off` shuts it again. The row is scrolled into view. The setting is named as for `get` and `set`.

```
menu open
menu tab graphics
menu expand ground_displacement
screenshot ui
menu expand ground_displacement off
menupos 150 0
menu close
```

Catch: `menu tab` and `menu expand` need the Esc menu to have been made, which happens on its first opening. `menu
expand` refuses a setting with nothing under it.

### `menupos`

Usage: `menupos [<x> <y> | reset]`

Moves the Esc menu's box from its usual centred place by x and y, in dp (right and down are positive), at once, whether
the menu is open or not. `menupos reset` puts it back. With no words, it prints how far it is moved and where the box
is laid out now (from the window's top left, in the menu's own pixels). The place is kept
until the game is closed, not saved.

```
menupos 200 -40
menupos
menupos reset
```

Catch: a large move can put part of the menu off the screen. Works from the launcher on.

### `uimove`

Usage: `uimove list | uimove <entry> <x> <y> | uimove <entry> reset | uimove reset | uimove save`

Moves single parts of the Esc menu, not the whole box, by x and y in dp from where layout puts them (right and down are
positive), at once. The rest of the layout does not move. `uimove list` prints the entries and any offset they have:
`menu` (the box, as `menupos`), `tab.<id>` (the tabs), `row.<option id>` (the option rows of the tab that is open),
`button.quit` and `button.close` (the top right), and `action.<name>` (the hints along the bottom, once a controller
or keyboard has been used). `uimove <entry> reset` and `uimove reset` put one or all back.

`uimove save` writes the offsets, and the menu's place, to `assets/ui_layout.json` next to the exe and prints the full
path. That file is read at start, so the offsets come back. To make them the default, copy it over `assets/ui_layout.json`
in the repo and commit it. The file is `{ "menu": [x, y], "entries": { "row.foo": [x, y] } }` and can be edited by hand.

```
menu open
uimove list
uimove tab.qol 0 -20
uimove row.some_option 30 0
uimove save
```

Catch: rows exist only for the tab that is open (and the search page), so open a tab before moving its rows; offsets
are kept when it is closed and come back when it is opened again. A move of more than 4000 is refused.

### `cam`

Usage: `cam`

Prints the camera as the frame is drawn from it: its position, its pitch, yaw and roll in degrees (a positive pitch
looks up, yaw 0 looks along -z), and the camera controller's mode (2 is the gameplay camera).

```
cam
```

Catch: needs the game running.

### `playerfade`

Usage: `playerfade <0 to 1> | playerfade off`

Holds Banjo (and Kazooie) at a fade, the one the free camera's Smooth Walls gives him when the camera is pulled in
close: 0 is gone, 1 is whole. `playerfade off` gives the fade back to the camera. For checking how he, his fur and
Kazooie's feathers look while faded, without steering the camera into him.

```
playerfade 0.5
screenshot
playerfade off
```

Catch: the game's own fades (a cutscene's) are scaled by it too while it is held.

### `kill`

Usage: `kill [radius] [model hex]`

Removes the nearest object within the radius of Banjo (300 when not given), or the nearest one with that model (as
`objects` lists them), through the game's own removal (func_800FFAB0), the one a beaten enemy goes through. Banjo
himself is never picked. It prints what it removed. For testing Enemy Respawn and Minjos Stay Dead: a removal near
Banjo counts as a kill for both.

```
objects 400
kill 400 671
```

Catch: anything can be removed, not only enemies, and some objects may not like it. Needs a player in the game.

### `anim`

Usage: `anim`

Prints the animation Banjo's animation controller is playing (its asset id, in hex), its length in seconds, his form
(the form id the Cheats tab's Transformation row uses) and his player state. Standing still, it shows the form's idle
animation.

```
transform form_8
wait control
anim
```

Catch: needs a player in the game, and the game running.

### `objects`

Usage: `objects [radius]`

Lists the live objects within the radius of Banjo (1500 when not given), nearest first. Each line gives the object's
address, its marker (the word at +0), the marker's model id (+0x14), its actor entry (+0x10: the same for every object
of one actor id, `80086968` for a Minjo), where it is and how far away. The last line counts them.

```
objects
objects 400
objects 99999
```

Catch: the object array moves as objects come and go, so an address is good for that game update only; the marker is
what stays the same while the object lives. Needs a player in the game.

### `goto`

Usage: `goto <x> <y> <z>` (also `tp`)

Moves Banjo to the given position in the current map. The numbers can be decimal or fractions. Run `pos` first to see
where Banjo is.

```
goto 0 500 0
tp 120.5 300 -40
```

Catch: it moves Banjo within the map he is in. It does not change the map, and `warp` does that. Needs a player in the
game.

### `walkto`

Usage: `walkto <x> <z> [radius] [timeout s]` (also `walk`)

Walks Banjo to a point on the ground with controller 1's stick, as a player would, so the game's own movement and
collision take him there instead of placing him as `goto` does. Every game update it takes the way from Banjo to the
point and turns it into a stick direction by the way the camera looks: up on the stick is away from the camera. Near the
point the stick is pushed less, so he stops on it. The queue is held until Banjo is within the radius of the point
across the ground, or until the timeout passes, and then the stick is let go. The radius is 30 and the timeout 10
seconds when not given (600 at most). It prints how long it took and where Banjo stopped.

```
pos
walkto 1200 -340
walkto 1200 -340 15 20
```

Catch: when the timeout passes it reports `ERR still 140 away after 10 s` with where Banjo is, and the queue goes on.
Nothing in the way, such as a wall or a gap, is walked round.

Catch: the height is not checked, so a point above or below Banjo counts as reached once he is under or over it.

Catch: the camera's direction is worked out from the camera's position (0x8012D500) and Banjo's, so a fixed camera that
does not look at Banjo can steer him wrong. Mirror Mode is allowed for. Needs a player in the game.

### `face`

Usage: `face <x> <z>`

Turns Banjo to face a point on the ground at once. It writes his facing and the facing he turns to (the yaw at PlayerState
+0xF8 that the dive and the enemy spawner read), and prints the angle in degrees, 0 facing +z.

```
face 1200 -340
```

Catch: a point under Banjo's feet is an error. A move that sets the facing itself, such as swimming or flying, can turn
him again. Needs a player in the game.

### `look`

Usage: `look <yaw deg> [pitch deg] [distance] | look at <x> <y> <z> [distance] | look here <yaw> [pitch] | look here at <x> <y> <z> | look off`

Holds the gameplay camera looking at Banjo, for screenshots. `look <yaw> [pitch] [distance]` puts the camera `distance`
units back from Banjo's head (60 above his feet) against that view direction, so he is in the middle of the picture.
Yaw 0 looks along -z and grows turning left, and a positive pitch looks up, so `look 0 -20` looks along -z and down
at him from slightly above. The pitch is 0 and the distance 350 when not given. The pitch is kept between -89 and 89,
and the distance between 1 and 5000. `look at <x> <y> <z> [distance]` takes the view direction from Banjo's head to the
point, so the point is behind him in the picture. When a wall or floor is between Banjo's head and the place worked
out, the camera is pulled in to just in front of it, with the line test the free camera uses, and the output says
`pulled in front of a wall`.

`look here <yaw> [pitch]` and `look here at <x> <y> <z>` turn the camera where it stands instead, with no distance and
no wall test. It prints where the camera is and the angles. `look off` gives the camera back to the game.

The camera stays held until `look off` or a map change. It is held by stopping the game's dynamic camera (its +0x72)
and writing that camera's position and rotation every game update, which the game then draws from. The game keeps
running. Banjo can still move, but the camera stays where `look` put it.

```
look 0 -20
look 90 -20 500
look at 1200 150 -340
look here 180 0
look off
```

Catch: it only works while the gameplay camera is running, and not in a scene, with a fixed camera, or with no file
loaded. A scene that starts while it is held draws with its own camera. Photo mode, when on, places the camera over it.

Catch: the wall test runs once, when `look` runs, from Banjo's head to the camera. The camera is not moved again if
Banjo walks off. A camera pulled right up to a wall can still show a little of it.

Catch: give the camera an update before a screenshot (`wait 100ms`), so the frame saved is drawn from the new angle.
The distance and wall forms have not been run yet. Needs the game running, and a player for the forms without `here`.

### `invincible`

Usage: `invincible [on|off]` (also `god`)

Sets the game's own no-damage flag, 0x53C. It is a save-file flag, so saving the game keeps it. With no value, it prints
whether the flag is on. With `on` or `off`, it sets the flag and prints the result.

```
invincible on
god off
```

Catch: needs the game running, because the flag is read and set during a game update.

### `jiggies`

Usage: `jiggies [n]` (also `jiggy`)

With no number, prints the Jiggies the game counts and how many of Jiggywiggy's challenges are done, with the Jiggies
the next one asks for (for the first nine). The count is the one Jiggywiggy checks: the game counts the collected
Jiggy flags each time (func_800D035C), and Jiggies are not spent on challenges. With a number up to 90, it sets
Jiggy-collected flags (0x250 to 0x2A9) through the game's flag setter until the game counts at least that many, then
counts again and prints the new total. It never takes Jiggies away. The bosses' Jiggies and King Jingaling's are left
out of the ones it adds.

```
jiggies
jiggies 20
```

Catch: it changes the save once the game saves. The Jiggies it marks are the first ones not yet collected in flag
order, so they disappear from their worlds as if collected. If the game counts fewer than asked after the flags are
set, it reports `ERR`. Needs the game running and a save file loaded.

### `challenge`

Usage: `challenge [n]`

With no number, prints how many of Jiggywiggy's challenges are done. With a number from 0 to 11, sets that count, so
challenge n + 1 is the next one Jiggywiggy offers. The count is kept in 4 flags from 0x35C, which `challenge` writes
through the game's flag setter. 11 is all of them, which opens the Hag 1 battle.

```
challenge
challenge 1
jiggies 4; challenge 1
```

Catch: it changes the save once the game saves. It only sets the count. Whether a world whose challenge it skips
over opens from the count or from flags of its own has not been checked, and lowering the count lets a challenge be
played again. Use it on a test save. It has not been
run yet. Needs the game running and a save file loaded.

### `lights`

Usage: `lights [add [r g b [radius [height]]] | undo | clear | list]`

The lamps Point Lights (Graphics > WIP) uses in this map, besides the lit lamps it finds by their textures.
`lights add` puts one at Banjo, `height` units above his feet: warm white 255 190 110, radius 500 and 80 up unless
given. `lights undo` removes this map's last lamp, `lights clear` all of this map's, and `lights list` shows them.
Each change is saved at once to `Dev Files/point_lights.txt` (one lamp a line: `<map hex> x y z r g b radius`). With
no word it prints whether Point Lights is on and how many lamps this map has. It works with Point Lights off too, but
the lamps only show with it on (`set point_lights on`). Needs the game running and a save file loaded.

```
lights add
lights add 255 120 40 800 40
set point_lights on; set point_lights_strength 100
lights list
lights undo
```

### `ach`

Usage: `ach [filter]` (also `achievements`)

Prints how many achievements are unlocked, out of how many, then each achievement: `[x]` if unlocked or `[ ]` if not, its
name, its points, and its progress as `count of goal` when it has a goal. With a filter, only the names that contain it
are listed, but the count still covers all of them. The filter is compared the way `warp` compares names.

```
ach
ach jig
```

Catch: `ach` only reads the list. It does not unlock or reset achievements, which is not ported yet.

### `pause`

Usage: `pause`

Stops the game's movement without opening the pause menu. On each game update the frame's delta time is set to almost
zero, so everything the game moves by delta time stands still. Menus and the frame rate keep going, and console commands
still run. The pause is not saved, so the game starts unpaused. `break` with `pause` pauses the game the same way.

```
pause
step
resume
```

Catch: needs the game running.

### `resume`

Usage: `resume`

Ends a pause. It prints "resumed" even when the game was not paused.

```
resume
```

### `step`

Usage: `step`

While paused, lets one game update run normally, and then the game is paused again. When the game is not paused, it is
an error: "not paused (pause first)".

```
pause
step
step
resume
```

Catch: `timescale` still applies to the update that a `step` runs.

### `background`

Usage: `background [seconds]`

Does what the Android app does when it goes to the background and comes back (`src/main/app_state.cpp`), for the
given time (3 s by default, at most 600). The game stops where it is: no VIs are sent and the game clock stands still.
The save file is written out, and RT64 releases its swap chain and the window surface it was made on. Afterwards
both are made again and the game goes on from where it was. The console log shows `[app]` and `[present]` lines for
each step. Other commands queued meanwhile wait while they need the game.

```
background 5
```

Catch: with Direct3D 12 the swap chain is kept, and only the presents stop. The Vulkan swap chain is released.

### `timescale`

Usage: `timescale [0.05 to 4]` (also `ff`, `slowmo`)

With no value, prints the current scale. Otherwise it scales the frame's delta time for the game's movement: 1 is normal,
2 is double speed, and 0.5 is half speed. The frame rate does not change. A value above 4, or 0 and below, is refused. A
value below 0.05 is set to 0.05.

```
timescale 2
slowmo 0.5
timescale 1
```

Catch: the scale is kept in memory only, and starts at 1 each time the program starts. While the game is paused the scale
does not apply, except to the update that a `step` runs. Needs the game running.

## Waiting and scripting

### `wait`

Usage: `wait <frames> | wait <n>ms | wait <n>s | wait save [timeout s] | wait control [timeout s] | wait map <map hex> [timeout s] | wait until <address> <value> [8|16|32] [timeout s]`

Holds the queue, so the commands after it wait. A plain number is a count of game updates. `ms` and `s` are time, and
fractions are allowed. `wait save` waits until a save file is loaded, which is what warps need; its timeout is 600
seconds, so it also works from `autoexec.txt` while you get through the launcher and file select. `wait control` waits
until the player has Banjo: a file is loaded, no letterboxed scene is on (the test Skip cutscenes uses), no map change is
in progress, the pause menu is shut, and Banjo is not in one of the states where the game moves him. Those are door
walk-ins and the scripted walk characters call him over with (state 152), signposts, talking, cutscenes and dying. It
has to stay that way for half a second, because a scene can give control back for a moment between its shots. Its
timeout is 60 seconds. `wait map` waits until the current map is the given id and no map change is in progress. `wait
until` waits until RAM holds the value. The size is the one given, or the one the typed value implies. The default
timeout is 120 seconds. When the timeout passes, the console prints `ERR gave up waiting (timed out)`, and the queue goes
on.

```
wait 60
wait 500ms
wait 1.5s
wait save
wait control
wait map 0x1A 30
wait until 80127630 0x05 8 10
```

Catch: the frame, control, map and until forms need the game running and report an error without it. The `ms` and `s`
forms work before the game starts.

Catch: `wait control` does not look at the dialogue system itself, only at the talking states Banjo is put in. A text
box that leaves him in an ordinary state, if there is one, passes. This has not been run yet.

### `exec`

Usage: `exec <file>`

Runs the lines of a file. Blank lines and lines that start with `#` are skipped. The lines are put at the front of the
queue, so they run before anything already waiting. A relative path is tried from the current folder first, and then from
the app folder. The path can contain spaces.

```
exec test.txt
exec tests/jump.txt
```

Catch: there is no limit on how deeply `exec` nests, so a file that runs itself never stops.

### `echo`

Usage: `echo <text>`

Prints the text, and writes the same text to the session log between `[Console] ----` and `----` markers. Use it to mark
a point in a script's log.

```
echo start of the jump test
```

### `repeat`

Usage: `repeat <n> <command>`

Runs the command `n` times, with `n` from 1 to 1000. The command is the rest of the line, `;` included, so `repeat 3 press a 10; wait 20` repeats both. The copies are put at the front of the queue, so they run before anything
already waiting. The output prints how many times and the command.

```
repeat 3 press a 10
```

Catch: nesting is limited to 8 levels. A `repeat` deeper than that is an error.

### `if`

Usage: `if <address> ==|!= <value> [8|16|32] <commands>`

Checks RAM once, when the line runs. If the check is true, the commands go to the front of the queue and run next. If it
is false, nothing runs. The console prints `true: <commands>` or `false`. The size can follow the value. Without one, the
value decides it, as described under Syntax.

```
if 80127630 == 5 echo yes
if 80127630 != 0 16 press a 10
```

Catch: the body is the rest of the line, `;` included, so in `if 80127630 == 5 press a 10; wait 30` both commands
are conditional. The
body runs one level down, so `macro` and `last` do not record it.

## Diagnostics

### `status`

Usage: `status`

Prints the current map as hex and by name, the number of game updates since the program started, the updates per second
over the last second, whether a warp is pending or not, and whether a save file is loaded.

```
status
```

Catch: needs the game running.

### `perf`

Usage: `perf <seconds>`

Times the game updates for the given number of seconds, up to 600. The timing is the time between one update and the
next. The summary is printed at the first game update after the time has run out. It also writes
`perf-YYYYMMDD-HHMMSS.csv` in the app folder, with the rows `update,ms`. The summary gives the number of updates, the
average time in ms, the updates per second that average gives, the 99th percentile and the worst time. A second `perf`
restarts the timing.

```
perf 10
```

Catch: counts game updates, not video frames. Needs the game running.

### `sysinfo`

Usage: `sysinfo`

Prints the platform, the number of logical CPUs, the RAM in MB, the video driver and the window size. It is useful in
bug reports.

```
sysinfo
```

### `log`

Usage: `log list | log <name> on|off`

Lists the debug logs that the console can switch, and switches one on or off. None can be switched yet. `log list`
prints `no log can be switched from here yet`, and any name is refused. The `TOOIE_*_LOG` environment variables are read
when the program starts, and the console cannot change them yet.

```
log list
```

### `screenshot`

Usage: `screenshot [ui]` (also `shot`)

Saves the next frame as a PNG in the screenshots folder of the app-data folder, the same as F12: the game's picture
alone, without the Esc menu, the console or notices. `screenshot ui` saves the whole window as it is shown instead,
everything drawn over the picture included (the Esc menu, the start menu, the console, notices), at the window's size,
as `<time>-ui.png` in the same folder.

```
screenshot
menu open
screenshot ui
```

Catch: the plain form needs the game running; `ui` works from the launcher on. A `ui` shot of the console shows the
console with the screenshot command in it.

### `burst`

Usage: `burst start | burst stop`

Keeps every presented frame from `start` to `stop`, the same as holding F12. `stop` writes them as PNGs, shrunk 4x,
to `screenshots/burst-<stamp>/000.png` and on, and the log names the folder. For glitches that last a frame or two,
such as a picture that flickers black: a single `screenshot` can land on a good frame.

```
burst start
wait 2s
burst stop
```

Catch: only the last 150 frames are kept, so at high frame rates a long burst keeps only its end. `stop` without a
`start` does nothing. Needs the game running.

### `costcheck`

Usage: `costcheck` (also `cost`)

Starts the Effect Cost Check, the same as its key in the Controls tab. It measures the GPU time per game frame with
every effect as set, then with each effect that is on turned off in turn for a few seconds (the saved settings stay
as they are), then as set again. The list, heaviest first, shows in the frame rate overlay and goes to
`benchmarks/effect_cost_<date>.txt` in the app folder. A second `costcheck` while it runs stops it.

```
costcheck
wait 120s
```

Catch: it takes a few seconds per effect that is on (at least 2 s each, up to 30 s on a slow PC), so wait long
enough before reading the file. Keep the camera still: what is on screen changes the times. Needs the game running.

### `bench`

Usage: `bench [start|stop]`

Starts or stops a Benchmark recording, the same as the Benchmark key. It writes `benchmarks/benchmark_<date>.csv` in
the app folder, four rows a second: the frame rate and frame time, the worst frame, the GPU time per game frame and per
pass (the port's effects among them), the game's own updates per second and CPU time, input latency, shader compiles,
and the map and where Banjo is. Stopping writes a `.txt` summary with the settings beside it. With no word, prints
whether a recording runs.

```
bench start
wait 30s
bench stop
```

Catch: a crash leaves the `.csv` as far as it got, with no summary. `tools/perf_report.py` reads the csv by map.

### `hostprof`

Usage: `hostprof start [file] | hostprof label <text> | hostprof stop`

A sampling profiler of the whole program: every 2 ms it looks at each thread that used CPU time since the last look and
notes the function it is in, weighted by the CPU time the thread used since the last look (so waiting counts for nothing). `start` begins (or begins anew) and writes to the file given, or to
`profiles/profile-<date>.tsv` in the app folder; a relative file is put in the app folder. The file is written again
every 5 s and on `stop`, so a run that crashes keeps its profile. `label` counts what comes after under that text,
so one run through several maps splits by map. Each line is samples, label, thread, module and function, tab
separated, most samples first; 500 samples are a second of one core. Beside it, `<file>.callers.tsv` has the same samples by
function, its caller and its caller's caller. With no word, prints where it is writing.

```
hostprof start
hostprof label spiral mountain
warp id AF
wait 10s
hostprof stop
```

Catch: self time, with two callers in the `.callers.tsv` file: a function that calls heavy ones shows only its own
share in the main file. The names come
from `BanjoReTooie.pdb`, so keep it beside the exe. Windows only. `TOOIE_PROFILE=<file>` starts it with the program.

### `tee`

Usage: `tee <file> | tee off`

Copies everything the console prints to a file, one line at a time, and flushes each line. A relative file name is put in
the app folder. The file is opened for adding, so anything already in it is kept. A new `tee` closes the old file first.
`tee off` closes the file.

```
tee run.log
tee off
```

Catch: only output printed after `tee` starts is copied. The same text still goes to stdout and the prompt.

### `version`

Usage: `version`

Prints the build's name and version number. Works before the game starts.

```
version
```

### `vram`

Usage: `vram`

Prints the summary the VRAM log keeps, or "no VRAM figures yet" when it has none. The command only prints what the log
holds. It does not measure anything itself.

```
vram
```

### `gfx`

Usage: `gfx` (also `gfxbudget`)

Prints how full the last display list was, as a percentage of its buffer.

```
gfx
```

Catch: needs the game running.

### `crash`

Usage: `crash test confirm`

Crashes the game on purpose by writing to a null pointer, to check that the crash report is written. It prints
"crashing now", and the game ends at once. Any other form prints an error that says it really crashes the game.

```
crash test confirm
```

Catch: this is a real crash, and nothing is saved first. The command does not wait for the game, so in a script it
crashes as soon as it is reached.

### `hang`

Usage: `hang test <seconds>` (1 to 300)

Holds the thread that runs the command for the given number of seconds. It prints "holding the game thread for N seconds"
first and "going on" after. It is for checking the hang watchdog. Once the game runs, that thread is the game thread, so
the game stops responding for the time.

```
hang test 5
```

Catch: needs the game running. A number outside 1 to 300 is an error.

## Tools

### `save`

Usage: `save backup | save list`

`save backup` copies the save file into `save_backups` in the config folder. The copy goes in a folder named with the
date and time and `_console`, and the command prints where it went. `save list` prints the backup folders in name order,
so the oldest is first. The command does not put a backup back. Its error text says to copy a backup over the save file
with the game closed.

```
save backup
save list
```

Catch: `save backup` needs a save file already on disk. Without one it reports "no save file yet".

### `sweep`

Usage: `sweep [start|fast|more|stop]`

`sweep start` sets the Texture dump option to "Sweep all maps" and starts the texture sweep without the menu prompt. It
prints that the sweep takes about 40 minutes. `sweep stop` sets the Texture dump option to off. With no argument, it
prints whether a sweep is running.

`sweep fast` is a quicker first pass: entrance 0 of every map only, no camera turn, shorter waits, and the game runs at
twice its speed meanwhile (the `timescale` command's, multiplied). `sweep more` is the second pass: the other entrances,
only of the maps that gave new textures at entrance 0 in the fast pass (sweep.txt in texture_dump/ lists the count on
each `done`/`same` line). Run `sweep fast` first; `sweep more` adds to its sweep.txt. Both resume after a restart in the
same mode, like `sweep start`. A start from the console or the menu (`start`, `fast`) always begins anew; only `more` keeps
the record. When a sweep finishes, the Texture dump option goes back to Off and is saved.

Every texture also gets a `<hash>.json` beside its PNG (map, entrance, frame) for `tools/organize_textures.py`.

```
sweep fast
sweep more
sweep start
sweep stop
```

Catch: needs the game running, so `sweep start` waits in the queue until then.

### `photo`

Usage: `photo`

Turns photo mode on or off, as its key does. The change happens on the next frame, and the message gives the state it is
switching to.

```
photo
```

Catch: needs the game running.

### `sfx`

Usage: `sfx <hex id> [volume]`

Plays a sound effect on Banjo, the first player, through the game's own sound function (func_8009DE38). The id is hex,
with or without `0x`, and at most `FFFF`. The volume is from 0 to 2, and is 1 when not given. The output is `sound 0x`
and the id in upper-case hex.

```
sfx 1F
sfx 0x1F 0.5
```

Catch: the id is not checked against the game's sounds, so an unknown id may play nothing.

Catch: an id above `FFFF` or a volume outside 0 to 2 is an error. Playing needs a game update running and a player. With
no player yet, it reports `there is no player yet`.

## Binds and aliases

Binds and aliases are saved in `console.txt` in the app folder, and are loaded when the program starts.

### `bind`

Usage: `bind [key] [commands]`

With no argument, lists the binds. With a key and commands, runs the commands when the key is pressed. The rest of the
line after the key is the commands, including any `;`. A key is named by its SDL name, such as `F5`, `K` or `Keypad 1`.
The bind follows the key's place on the keyboard. The grave key (`` ` ``) and Escape cannot be bound. A bind runs once for
each press, and key repeat does not start it again. Binds do not run while the prompt is open, or while the menu or a
panel takes the keyboard. Binds are checked during game updates, so they do nothing before the game runs.

```
bind F5 screenshot
bind F6 press a 30; wait 30
```

### `unbind`

Usage: `unbind <key>`

Removes the bind on the key.

```
unbind F5
```

Catch: `unbind` prints "unbound" even when nothing was bound to the key, or when the key name is not known.

### `alias`

Usage: `alias [name] [commands]`

With no argument, lists the aliases. With a name and commands, makes the name run the commands. The commands can include
`;`. Typing the name runs them. The name is changed to lower case. A name that is the main name of a command is refused.
An alias with no commands is removed.

```
alias nightoff set day_night off; status
nightoff
```

Catch: an alias takes no arguments, and any words typed after its name are dropped. A name that is only a short form of a
command, such as `ls`, is accepted, but it never runs, because the command runs first. An alias runs up to 8 aliases
deep. Your own alias with the same name as a shortcut below replaces that shortcut.

### `macro`

Usage: `macro record <name> | macro stop`

`macro record <name>` starts recording. Each top-level line that runs after it is kept: lines typed, piped in, or run by
a bind. `macro stop` saves them as one alias, joined with `; `, in `console.txt`, so typing the name runs them again. The
name is lower case. Lines run by an alias, `if`, `repeat`, `exec` or `profile load` are not kept, and neither are `last`
and `macro` lines. Stopping with nothing recorded saves nothing.

```
macro record jumpwait
press a 10
wait 30
macro stop
jumpwait
```

Catch: nothing is saved until `macro stop`, so a recording is lost if the program ends first. A new `macro record` throws
away the lines recorded so far. A name that is also a command's name is saved, but it never runs.

### `last`

Usage: `last` (also `!!`)

Runs the last top-level line again, and prints it. A line counts when it was typed, piped in, or run by a bind. Lines run
by an alias, `if`, `repeat` or `exec` do not count, and neither do `last` and `macro` lines. With nothing yet to repeat, it
says "nothing to repeat yet".

```
press a 30
last
```

Catch: a `;` splits a line before it runs, so the last line is only the part that ran last. After `press a 10; wait 30`,
`last` runs `wait 30`.

### Shortcuts

A one-word shortcut runs a command, and any words typed after the shortcut are added to the end of it. For example,
`res 2` runs `set res_option 2`. Aliases you have made win over these. `help` does not list the shortcuts.

| Shortcut | Runs | Catch |
| --- | --- | --- |
| `noclip` | `cheat noclip` | With no value, flips the cheat. Only works if the build has that cheat. |
| `levitate` | `cheat infinite_jumps` | With no value, flips the cheat. |
| `fly` | `cheat fly_anywhere` | With no value, flips the cheat. |
| `onehit` | `cheat one_hit` | With no value, flips the cheat. |
| `msaa` | `set msaa_option` | Needs a value. `msaa` alone is a usage error. |
| `res` | `set res_option` | Needs a value. |
| `hdshadows` | `set hd_shadows` | Needs a value, such as `hdshadows on`. |
| `mirror` | `set mirror_mode` | Needs a value. |
| `daynight` | `set day_night` | Needs a value, such as `daynight off`. |
| `sunshadows` | `set sun_shadows` | Needs a value. |
| `upscale` | `set texture_upscale` | Needs a value. |
| `interp` | `set force_scene_interpolation` | Needs a value, such as `interp on`. |
| `testroom` | `warp place test room` | Needs a save file loaded. |
| `freecam` | `set free_camera` | Needs a value, such as `freecam on`. |
| `boss` | `set boss_rush` | Needs a value. |
| `cutscene` | `set cutscene_skip_all` | Needs a value. |
| `dive` | `set dive` | Needs a value. |
| `trot` | `set talon_trot` | Needs a value. |
| `fineaim` | `set fine_aim` | Needs a value. |
| `music` | `set music_player` | Needs a value. |
| `mem` | `set more_game_memory` | Needs a value. |
| `char` | `transform` | With no value, prints the form. Needs a save file loaded and the game running, as `transform` does. |

## Not ported yet

These commands are not in the console yet, because they need addresses from the Banjo-Tooie decomp or hooks into the
game: `jiggies`, `notes`, `jinjos`, `health`, `seed`, `camera` (save and
load), `disasm`, `screenshot compare`, achievement `unlock` and `reset`, `actors`, `hide`, `show`,
`capture`, `replay`, `hud`, and `moves` (`unlock moves` turns on the cheat for now). `pause`, `resume`, `step`,
`ff`, `record` and `play` are in the console now, as described above.
