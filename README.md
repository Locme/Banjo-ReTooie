# Banjo Re-Tooie

*Banjo-Tooie on PC. Keeping the N64 game as it was, and making room for what comes next.*

![The Banjo Re-Tooie start menu: Locme's art of Spiral Mountain, with the title dropping in](docs/media/start-menu.gif)

Banjo Re-Tooie is a native PC port of **Banjo-Tooie (USA, N64)**. It isn't an emulator. The game's own code was
recompiled to C with [N64Recomp](https://github.com/N64Recomp/N64Recomp), runs on
[N64ModernRuntime](https://github.com/N64Recomp/N64ModernRuntime), and is drawn by
[RT64](https://github.com/rt64/rt64). By default it plays like the N64 game. Every enhancement below is a setting
you can turn on or off, and it applies straight away.

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

## Features

### Play it your way
- **Any frame rate.** 60 FPS and above, with interpolation, while the game logic runs at its own speed, so physics and timing stay as on the N64.
- **Any screen.** Widescreen and ultrawide, any resolution, windowed or fullscreen (F11 / Alt+Enter), and HUD placement options.
- **Controller, keyboard and mouse.** Mouse aiming in first person, the mouse in the game's menus, and rebindable controls and hotkeys.
- **Settings that apply at once.** Press Esc (or Back / Select) at any time to open the menu. There's no Apply button.

### Modern graphics that still look like Banjo-Tooie
- **Upscaling and anti-aliasing:** DLSS and DLAA, FSR 1, FSR 3 and FSR 4, and SMAA.
- **Lighting:** Relighting, Ray Tracing and Path Tracing, with traced shadows, reflections and light, plus SSGI, screen-space reflections, ambient occlusion and Traced Light Beams. *Keep Game Look* holds the game's own colours and brightness while the light and shade change.
- **A living world:** Day and Night, weather, clouds, northern lights, wet ground, raindrops on the screen, mist, lens flare, fireflies and night sounds.
- **3D grass** with flower beds, and small creatures living in it: bees, butterflies, birds, frogs and crabs on land, and fish, turtles and rays under the sea. They scatter when Banjo comes close.
- **Characters:** Banjo's fur, Kazooie's feathers (also when she's on her own), high-detail models, toon style and tessellation.
- **Surfaces:** parallax and displaced ground, stylised water, and ice reflections.
- **Retro options:** N64 3-point filtering, 16-bit colour and a CRT filter, for a picture closer to the console's.
- **Accessibility:** brightness and colour grading, with colourblind filters for Deuteranopia, Protanopia and Tritanopia.

### Quality of life
- Skip the intro, faster text and level transitions.
- A free camera, a water camera, fine aim and running.
- Transform anywhere, from a ring menu of the forms you've unlocked.
- A Totals checklist of what's left to find in each level.
- Save backups, save states, and a timer save.
- A level warp, and replays of races and bosses (including a boss rush).

### Extras
- **Photo mode:** pick a character and a pose, mirror it, and set the face.
- **Achievements** and a **music player**, plus a sound test in Developer Mode.
- **Cheats:** infinite items, transformations, levitation, speed-up and Cheato codes. See [`notes/cheats.md`](notes/cheats.md).
- **Gameplay options:** harder enemies, enemy respawns, and back-ports from Banjo-Kazooie (old Banjo sounds, the Get Jiggy animation). Plus some cut content brought back.
- **Languages:** English, French, German and Spanish. See [`docs/translations.md`](docs/translations.md).

### Mods and texture packs
- Mods load from zip files and can be turned on or off on the Mods tab.
- Texture packs replace the game's textures, including the menu's portraits, and can carry height maps for parallax.
- Model mods replace characters, and the fur and feathers follow them.

### Work in progress
Still being built: Voxel Layer (the Bill Drill digs real holes), Dive, and volumetric mist, fog and clouds (all on
the WIP tab), and HD shadows (experimental).

Every option, with its default, is in [`notes/settings-guide.md`](notes/settings-guide.md). Every shortcut is
in [`notes/keys.md`](notes/keys.md). What changed, newest first, is in
[`notes/changelog.md`](notes/changelog.md).

## Platforms

- **Windows:** the main target. There are two builds: *Any 64-bit PC (2008 and up)*, and *Optimized for newer CPUs (2013 and up)*, which needs AVX2.
- **Linux:** builds too.
- **Android:** early stage. It needs a 64-bit ARM phone running Android 10 or newer with Vulkan, and aims to reach the title screen. Ray tracing, DLSS/FSR 3/4 and mouse options aren't available there.

## Getting started

1. Get a build: download one from [Releases](https://github.com/Locme/Banjo-ReTooie/releases), or build it yourself (see [`BUILDING.md`](BUILDING.md)). On Windows, `update_and_build.bat` pulls the latest code and builds it.
2. Run `BanjoReTooie.exe`, choose **Play** and pick your Banjo-Tooie (USA) ROM. It's remembered after the first time. `--game bt` skips the start menu.
3. Press **Esc** (or **Back** / **Select**) to open the settings at any time.

Settings and saves are kept next to the exe when that folder is writable, and in your user profile otherwise. An
empty `portable.txt` next to the exe keeps them there. If the game crashes or freezes,
[`notes/reporting-crashes.md`](notes/reporting-crashes.md) says which logs to send.

## How it works

1. The [Banjo-Tooie decompilation](https://github.com/Mr-Wiseguy/banjo-tooie) (a submodule in `lib/bt-decomp`)
   splits your ROM and links a byte-matching ELF with full relocations.
2. N64Recomp turns that ELF into C (`RecompiledFuncs/`), and RSPRecomp turns the audio microcode into C++ (`rsp/`).
3. CMake builds that code together with the runtime, RT64 and the menus into one executable.

The game's own code runs as native code, and RT64 draws its display lists with Direct3D 12 or Vulkan.

## Foundations and licence

Banjo Re-Tooie stands on N64Recomp, N64ModernRuntime and RT64, and follows the structure of BanjoRecomp, the
Banjo-Kazooie port. An earlier attempt at a port started from the Xbox 360 (XBLA) version. It was dropped in
October 2026, and this port was restarted from the N64 game.

- [`BUILDING.md`](BUILDING.md): how to build on Windows, Linux and Android.
- [`docs/THIRD_PARTY.md`](docs/THIRD_PARTY.md): every third-party library, font and piece of art, with its licence, and credits.
- [`docs/console.md`](docs/console.md): the developer console's commands.

Banjo Re-Tooie is GPL-3.0, see [`COPYING`](COPYING). The DLSS and FSR 3 / FSR 4 DLLs that Windows builds ship
are under NVIDIA's and AMD's own licences; see [`docs/THIRD_PARTY.md`](docs/THIRD_PARTY.md).
