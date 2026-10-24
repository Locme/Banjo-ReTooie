# Banjo Re-Tooie

*Banjo-Tooie on PC. Keeping the N64 game as it was, and making room for what comes next.*

![The Banjo Re-Tooie start menu: Locme's art of Spiral Mountain, with the title dropping in](docs/media/start-menu.gif)

Banjo Re-Tooie is a native PC port of **Banjo-Tooie (USA, N64)**, with modern
graphics, smooth frame rates and quality-of-life options, made by statically recompiling the
game's MIPS code to C with [N64Recomp](https://github.com/N64Recomp/N64Recomp),
running it on [N64ModernRuntime](https://github.com/N64Recomp/N64ModernRuntime)
and rendering it with [RT64](https://github.com/rt64/rt64). There is no
emulator at runtime.

> ### Made by Locme with the assistance of AI
>
> Locme leads this port: they choose and design every feature, play-test each
> build, and drew the game's icon and the start menu art. The code is written
> by an AI (Claude) to Locme's direction. The port is **not** associated with,
> or endorsed by, the Banjo: Recompiled team, N64Recomp or RT64. Please do not
> take issues with this port to those projects.

> ### No game assets are included.
>
> You need your own Banjo-Tooie (USA) cartridge dump to build or run this. The
> ROM is never downloaded, bundled or committed here. The only ROM-derived
> material in the repository is the recompiled code (`RecompiledFuncs/`,
> `rsp/`), so that the game can be built with just a compiler. No art, audio,
> textures or models are included.

## Current Status

- The game boots, plays and saves natively on Windows.
  Linux builds too. An Android build (64-bit ARM phones with Vulkan, Android 10 or newer) is in its first stage.
- Graphics: widescreen and ultrawide, 60 FPS and higher with interpolation, any resolution, SMAA, FSR, DLSS,
  screen-space and ray-traced effects (shadows, reflections, ambient occlusion, light), 3D grass and fur.
- Quality of life: skip the intro, faster text and transitions, a free camera, save backups and save states,
  cheats, achievements, a level warp and a photo mode. Mods load from zip files.

What changed, newest first: [`notes/changelog.md`](notes/changelog.md).

## The Experience We Want to Build

- Banjo-Tooie exactly as it plays on the N64, with the same physics, timing and secrets, by default.
- Smooth play at your monitor's refresh rate without changing the game's own speed.
- Any window size and aspect ratio, with the HUD where you want it.
- Optional modern graphics that look like the game, not like a different one.
- Settings that apply at once, in a menu you can reach any time with Esc or Back.
- Mods and texture packs that are easy to install and turn on or off.

## How It Works

1. The [Banjo-Tooie decompilation](https://github.com/Mr-Wiseguy/banjo-tooie)
   (a submodule in `lib/bt-decomp`) splits your ROM and links a byte-matching
   ELF with full relocations.
2. N64Recomp turns that ELF into C (`RecompiledFuncs/`); RSPRecomp turns the
   audio microcode into C++ (`rsp/`).
3. CMake builds that code together with the runtime, RT64 and the menus into
   one executable.

There is no emulator at runtime: the game's own code runs as native code, and RT64 draws its display lists
with Direct3D 12 or Vulkan.

## Testing and Development

### Building

See [`BUILDING.md`](BUILDING.md). On Windows, `update_and_build.bat` pulls the latest code and builds;
`build.bat` builds what you have.

### Playing

You need your own legally obtained Banjo-Tooie (US) ROM. On Windows, `build.bat`
(or `update_and_build.bat`) leaves the finished game in a `Release` subfolder:
`Release\Any 64-bit PC (2008 and up)` works on any 64-bit PC from 2008 on, and
`Release\Optimized for newer CPUs (2013 and up)` is faster but needs a CPU from
2013 or newer. See [`BUILDING.md`](BUILDING.md). Run `BanjoReTooie.exe` in
the folder you want. The first time you
start the game, choose **Start Game** in the launcher and pick the ROM file;
it is remembered afterwards. To skip the launcher and go straight into the
game, start the exe with `--game bt`. Settings and saves are kept next to the
exe (in its `Release` subfolder after `build.bat`) when that folder is writable; otherwise they
go to your user profile.

If the game crashes or freezes, see [`notes/reporting-crashes.md`](notes/reporting-crashes.md) for which logs to send.

After a build, `Play Banjo Re-Tooie.cmd` checks the files the game needs and starts it.

### Settings

Press **Esc** on the keyboard, or **Back** / **Select** on a controller, to open
settings. The tabs are General, QOL, Graphics, Controls, Sound, Cheats and Mods.

- **General**: Back up saves, Save backups to keep, Timer save, Discord status,
  Speed-up factor and Speed-up toggle.
- **QOL**: Press Start Early to Skip Intro, Text speed and Level transitions.
- **Cheats**: Enable cheats, which must be on for the cheat options to show.
- **DEV** (shown with General > Developer Mode): its Additional Tabs section
  shows the Achievements, Cheats and Warp tabs.
- **Graphics**: changes apply at once, with no Apply button. Aspect Ratio offers
  4:3, Fill and Letterbox 16:9. Graphics API needs a restart.
- **F11** or **Alt+Enter** toggles fullscreen.

Every menu option, with its default, is in [`notes/settings-guide.md`](notes/settings-guide.md).
Every keyboard and controller shortcut is in [`notes/keys.md`](notes/keys.md).
What each cheat does is in [`notes/cheats.md`](notes/cheats.md).
What changed, newest first, is in [`notes/changelog.md`](notes/changelog.md).

### Reporting problems

Headless testing in a container is described in [`notes/headless-testing.md`](notes/headless-testing.md).
Notes for AI agents working on the code are in [`AGENTS.md`](AGENTS.md).

## Foundations, History, and Documentation

Banjo Re-Tooie stands on N64Recomp, N64ModernRuntime and RT64, and follows the structure of BanjoRecomp, the
Banjo-Kazooie port. An earlier attempt at a port started from the Xbox 360 (XBLA) version; it was dropped in
October 2026 and this port was restarted from the N64 game.

- [`BUILDING.md`](BUILDING.md): how to build on Windows, Linux and Android.
- [`docs/THIRD_PARTY.md`](docs/THIRD_PARTY.md): every third-party library, font and piece of art, its licence,
  and credits.
- [`notes/settings-guide.md`](notes/settings-guide.md), [`notes/keys.md`](notes/keys.md),
  [`notes/cheats.md`](notes/cheats.md): every option, shortcut and cheat.
- [`notes/changelog.md`](notes/changelog.md).

Banjo Re-Tooie is GPL-3.0, see [`COPYING`](COPYING). The DLSS and FSR 3 / FSR 4 DLLs that Windows builds ship
are under NVIDIA's and AMD's own licences; see [`docs/THIRD_PARTY.md`](docs/THIRD_PARTY.md).
