# Banjo-Tooie N64 Recomp

A native PC port of **Banjo-Tooie (USA, N64)** made by statically recompiling the
game's MIPS code to C with [N64Recomp](https://github.com/N64Recomp/N64Recomp),
running it on [N64ModernRuntime](https://github.com/N64Recomp/N64ModernRuntime)
and rendering it with [RT64](https://github.com/rt64/rt64). There is no
emulator at runtime.

> ### This port is AI-written.
>
> The code in this repository is written by an AI (Claude), directed and
> play-tested by Locme. It is **not** associated with, or endorsed by, the
> Banjo: Recompiled team, N64Recomp or RT64. Please do not take issues with
> this port to those projects.

> ### No game assets are included.
>
> You need your own Banjo-Tooie (USA) cartridge dump to build or run this. The
> ROM is never downloaded, bundled or committed here. The only ROM-derived
> material in the repository is the recompiled code (`RecompiledFuncs/`,
> `rsp/`), so that the game can be built with just a compiler. No art, audio,
> textures or models are included.

## Status

Early bring-up. See [`notes/roadmap-checklist.md`](notes/roadmap-checklist.md)
for the feature roadmap and [`BUILDING.md`](BUILDING.md) for how to build.

## Running

You need your own legally obtained Banjo-Tooie (US) ROM. On Windows, `build.bat`
(or `update_and_build.bat`) leaves the finished game in the `Release` folder; run
`Release\BanjoTooieN64Recomp.exe`. The first time you
start the game, choose **Start Game** in the launcher and pick the ROM file;
it is remembered afterwards. To skip the launcher and go straight into the
game, start the exe with `--game bt`. Settings and saves are kept next to the
exe (in `Release` after `build.bat`) when that folder is writable; otherwise they
go to your user profile.

If the game crashes or freezes, see [`notes/reporting-crashes.md`](notes/reporting-crashes.md) for which logs to send.

## Settings

Press **Esc** on the keyboard, or **Back** / **Select** on a controller, to open
settings. There are five tabs: General, Graphics, Controls, Sound and Mods.

- Graphics changes apply at once, with no Apply button. Aspect Ratio offers
  4:3, Fill and Letterbox 16:9.
- **F11** or **Alt+Enter** toggles fullscreen.
- Graphics API needs a restart.
- General has **Skip intro logos** (on by default) and **Back up saves**.

## How it works

1. The [Banjo-Tooie decompilation](https://github.com/Mr-Wiseguy/banjo-tooie)
   (a submodule in `lib/bt-decomp`) splits your ROM and links a byte-matching
   ELF with full relocations.
2. N64Recomp turns that ELF into C (`RecompiledFuncs/`); RSPRecomp turns the
   audio microcode into C++ (`rsp/`).
3. CMake builds that code together with the runtime, RT64 and the menus into
   one executable.

## Licence

GPL-3.0, see [`COPYING`](COPYING). N64ModernRuntime is GPL-3.0; N64Recomp and
RT64 are MIT; RecompFrontend ships no licence file and is used only as a
submodule. Inter and Noto Emoji are under the SIL Open Font License; PromptFont
ships its own terms in `assets/promptfont/LICENSE.txt`. The menu icons in
`assets/icons/` come from BanjoRecomp (GPL-3.0).

## Credits

* [N64Recomp](https://github.com/N64Recomp/N64Recomp),
  [N64ModernRuntime](https://github.com/N64Recomp/N64ModernRuntime) and
  [RT64](https://github.com/rt64/rt64) by Wiseguy and contributors.
* [RecompFrontend](https://github.com/N64Recomp/RecompFrontend): menus, input
  and settings UI.
* [BanjoRecomp](https://github.com/BanjoRecomp/BanjoRecomp): the Banjo-Kazooie
  port whose project structure and front-end setup this port follows.
* The [Banjo-Tooie decompilation](https://github.com/Mr-Wiseguy/banjo-tooie)
  by Mr-Wiseguy and contributors.
* [Vidanox/BanjoTooieRecompiled](https://github.com/Vidanox/BanjoTooieRecompiled):
  its engineering notes documented several Tooie-specific facts used here.
* [ScriptHawk](https://github.com/Isotarge/ScriptHawk) by Isotarge: map and flag
  data.
* retroben, illusion and wedarobi: facts from the Xenia Banjo-Tooie game patch.
* PromptFont by Yukari "Shinmera" Hafner.
