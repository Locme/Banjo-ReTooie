# Notes for AI agents

Banjo Re-Tooie's code is written by AI agents to Locme's direction. Read this before changing anything.

## Ground rules

- Work lands on `main`. Fetch `origin/main` and read its log before starting, so the same thing is not done twice.
- Bugs before features, and a bug gets a failing check first where one can be made.
- Never commit the ROM, anything extracted from it other than `RecompiledFuncs/` and `rsp/`, or any game art,
  audio, textures or models.
- Say plainly what was and was not tested. A headless run in a container is not a test on a real PC.
- Settings apply the moment they change; no Apply button and no restart unless there is no way round it.
- Keep `README.md` honest that the code is AI-written. Never present the port as BanjoRecomp's or open AI-written
  pull requests on BanjoRecomp, N64Recomp or RT64.
- Check the licence before copying code from anywhere, and add it to `docs/THIRD_PARTY.md`.

## Building

See `BUILDING.md`. The CMake target is `BanjoTooieN64Recomp`; it builds `BanjoReTooie(.exe)`. The saves and
settings folder is still named `BanjoTooieN64Recomp` (`program_id` in `include/tooie_game.h`); do not rename it.

## Code

- `banjotooie.us.toml` lists the hooks into the recompiled game. After changing it, run
  `./N64Recomp banjotooie.us.toml` and put back any hand edits in `RecompiledFuncs/` it overwrote.
- RT64 changes go in `rt64-ext/` through RT64's extension points where possible, and otherwise in
  `lib-patches/rt64.patch`. A CMake configure resets `lib/rt64` to the committed patch, so regenerate the patch
  before building after an edit there.
- Reading and writing game memory: `include/tooie_rdram.h` (`tooie::rdram::*`); keys held: `tooie::hotkeys::down`.
- Linux builds skip DXIL validation; check changed shaders with `dxc-linux` before pushing.
- Comments say what the code does and why, in plain sentences, like the code round them.
