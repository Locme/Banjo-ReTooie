# Developer console

Ported from the Mario Party 3 port's console (`src/game/console.cpp`). Like the rest of this code it is written by AI
agents to Locme's direction, and it has only been compile-checked so far, not run.

## Ways in

* **In the game:** the `` ` `` key (left of 1, any keyboard layout) opens a prompt over the bottom of the window. Enter runs
  the line, Up and Down walk the history, Page Up and Page Down scroll the output, `` ` `` closes it. The settings menu
  (Esc) closes the prompt and the prompt cannot open while the menu is up.
* **Scripts:** each line on stdin is a command (`BanjoReTooie < test.txt`), also `--exec <file>` and
  `TOOIE_CONSOLE="cmd; cmd"`. Commands chain with `;`.

Results print to stdout as `[command] text`, failures as `[command] ERR text`. `READY launcher` appears when the launcher
is up, `READY game` on the first game update and `IDLE` when the queue has run dry. `console_state.txt` in the app folder
is rewritten about once a second (`ready`, `game_started`, `map`, `frames`, `queued`, `busy`, `errors`, `last`).
`quit [code]` ends the program; the exit code is 1 if any command failed, unless a code is given.

Binds and aliases are kept in `console.txt` in the app folder.

## Commands

`help` lists them all. In short: `start`, `quit`, `warp`, `list`, `status`, `settings`, `get`, `set`, `toggle`, `reset`,
`fps`, `dev`, `screenshot`, `press`, `release`, `wait`, `peek`, `poke`, `expect`, `find`, `freeze`, `unfreeze`, `watch`,
`unwatch`, `log`, `aspect`, `bind`, `unbind`, `alias`, `exec`, `echo`, `clear`, `close`.

* `warp <name>` searches the Warp tab's places and every map in `map_names.inc`; `warp place <n|name>`, `warp map <n|name>`,
  `warp id <map hex> [exit hex]` (the ids `TOOIE_WARP` uses). A save file has to be loaded.
* Addresses are hex (`80127630` or `0x80127630`); below `0x80000000` they are taken as physical.
* `dev` makes `dev.txt` next to the exe, which shows every hidden tab (DEV, Cheats, Warp, Achievements) from the next launch; `dev off` removes it.
* `wait <n>` counts game updates (the per-frame update the port hooks), not video frames.
* `set` and `toggle` go through the same config calls as the menu, so a setting changes the way it does there.

## Not ported yet

Needing addresses from the Banjo-Tooie decomp or hooks into the game: counters (`jiggies`, `notes`, `health`), `char`,
`transform`, `moves`, `noclip`, `camera`, `actors`/`hide`/`show`, `pause`/`resume`/`step`, `ff`, `seed`, `capture`,
`record`/`replay` (the `--pad-script` argument covers scripted input for now) and `hud`.
