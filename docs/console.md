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
* Some commands need the game running. These are `warp`, `status`, `savestate`, `spawn`, `diff`, `perf`,
  `screenshot`, `press`, `peek`, `poke`, `expect`, `find`, `freeze`, `flag`, `pos`, `goto`, `transform`, `pause`,
  `resume`, `step`, `timescale`, `break`, `if`, `findptr`, `gfx`, `hang`, `sweep`, `photo` and `invincible`. Until the game
  is running they wait at the front
  of the queue, so `start; warp place 1` works on one line. If the game never starts, they never run. The frame, map and
  until forms of `wait` report an error instead of waiting.
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

Needs a save file loaded. The launcher, the title screen and the file select do not count. The warp goes through the
Warp tab's own code, and the prompt closes once the warp has been made.

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

Catch: a warp needs a save file. Without one the console reports the error, and the warp is not made.

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
`wip`) that the menu shows. The `debug` tab has no settings in this build. Options the menu hides cannot be reached.
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

## Input

### `press`

Usage: `press <buttons> [stick <x> <y>] [frames]`

Holds controller 1's buttons and stick. Buttons are `a`, `b`, `z`, `start`, `l`, `r`, the directions `up`, `down`, `left`
and `right`, the D-pad names `dup`, `ddown`, `dleft` and `dright`, and the C buttons `cup`, `cdown`, `cleft` and `cright`.
Join buttons with `+`, as in `a+b`. The stick's x and y run from -80 to 80, and larger values are limited to that range.
Frames are game updates. With no frame count, the buttons are held until `release`. A new `press` replaces what is held.
The command returns at once, so use `wait` to hold the queue while the buttons are down.

```
press a 30
press a+b 10
press stick 80 0 60
press start
release
```

Catch: needs the game running. Only controller 1 is affected.

### `release`

Usage: `release`

Lets go of what `press` is holding.

```
release
```

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

Prints Banjo's position as x, y and z to two decimal places, and the current map as hex.

```
pos
```

Catch: needs a player in the game. Until there is one, it reports an error.

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

### `invincible`

Usage: `invincible [on|off]` (also `god`)

Sets the game's own no-damage flag, 0x53C. It is a save-file flag, so saving the game keeps it. With no value, it prints
whether the flag is on. With `on` or `off`, it sets the flag and prints the result.

```
invincible on
god off
```

Catch: needs the game running, because the flag is read and set during a game update.

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

Usage: `wait <frames> | wait <n>ms | wait <n>s | wait map <map hex> [timeout s] | wait until <address> <value> [8|16|32] [timeout s]`

Holds the queue, so the commands after it wait. A plain number is a count of game updates. `ms` and `s` are time, and
fractions are allowed. `wait map` waits until the current map is the given id and no map change is in progress. `wait
until` waits until RAM holds the value. The size is the one given, or the one the typed value implies. The default
timeout is 120 seconds. When the timeout passes, the console prints `ERR gave up waiting (timed out)`, and the queue goes
on.

```
wait 60
wait 500ms
wait 1.5s
wait map 0x1A 30
wait until 80127630 0x05 8 10
```

Catch: the frame, map and until forms need the game running and report an error without it. The `ms` and `s` forms work
before the game starts.

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

Usage: `screenshot` (also `shot`)

Saves the next frame as a PNG in the screenshots folder of the app-data folder, the same as F12.

```
screenshot
```

Catch: needs the game running.

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

Usage: `sweep [start|stop]`

`sweep start` sets the Texture dump option to "Sweep all maps" and starts the texture sweep without the menu prompt. It
prints that the sweep takes about 40 minutes. `sweep stop` sets the Texture dump option to off. With no argument, it
prints whether a sweep is running.

```
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
game: item counters (`jiggies`, `notes`, `jinjos`, `health`, `eggs`, `feathers`, `give`), `seed`, `camera` (save and
load), `sfx`, `trace`, `disasm`, `screenshot compare`, achievement `unlock` and `reset`, `actors`, `hide`, `show`,
`capture`, `record`, `replay`, `hud`, and `moves` (`unlock moves` turns on the cheat for now). `pause`, `resume`, `step`
and `ff` are in the console now, as described above.
