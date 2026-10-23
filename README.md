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
An Android build (64-bit ARM phones with Vulkan, Android 10 or newer) is in its
first stage: see the Android section of [`BUILDING.md`](BUILDING.md).

## Running

You need your own legally obtained Banjo-Tooie (US) ROM. On Windows, `build.bat`
(or `update_and_build.bat`) leaves the finished game in a `Release` subfolder:
`Release\Any 64-bit PC (2008 and up)` works on any 64-bit PC from 2008 on, and
`Release\Optimized for newer CPUs (2013 and up)` is faster but needs a CPU from
2013 or newer. See [`BUILDING.md`](BUILDING.md). Run `BanjoTooieN64Recomp.exe` in
the folder you want. The first time you
start the game, choose **Start Game** in the launcher and pick the ROM file;
it is remembered afterwards. To skip the launcher and go straight into the
game, start the exe with `--game bt`. Settings and saves are kept next to the
exe (in its `Release` subfolder after `build.bat`) when that folder is writable; otherwise they
go to your user profile.

If the game crashes or freezes, see [`notes/reporting-crashes.md`](notes/reporting-crashes.md) for which logs to send.

## Settings

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

## How it works

1. The [Banjo-Tooie decompilation](https://github.com/Mr-Wiseguy/banjo-tooie)
   (a submodule in `lib/bt-decomp`) splits your ROM and links a byte-matching
   ELF with full relocations.
2. N64Recomp turns that ELF into C (`RecompiledFuncs/`); RSPRecomp turns the
   audio microcode into C++ (`rsp/`).
3. CMake builds that code together with the runtime, RT64 and the menus into
   one executable.

## Licence

The DLSS runtime `nvngx_dlss.dll` that Windows builds fetch and ship beside the game is NVIDIA's, under NVIDIA's own
licence (`third-party/nvidia-dlss/LICENSE.txt`), not the GPL.
The FSR 3 / FSR 4 DLLs (`amd_fidelityfx_loader_dx12.dll`, `amd_fidelityfx_upscaler_dx12.dll`) that Windows builds fetch and ship are
AMD's, redistributed in binary form under AMD's licence (`third-party/amd-fsr/LICENSE.txt`), not the GPL.
Android builds include Qualcomm's Snapdragon GSR 1 shader (`third-party/snapdragon-gsr`, BSD 3-Clause).

GPL-3.0, see [`COPYING`](COPYING). N64ModernRuntime is GPL-3.0; N64Recomp and
RT64 are MIT; RecompFrontend ships no licence file and is used only as a
submodule. Inter and Noto Emoji are under the SIL Open Font License; PromptFont
ships its own terms in `assets/promptfont/LICENSE.txt`. The menu icons in
`assets/icons/` come from BanjoRecomp (GPL-3.0). SMAA in `lib/smaa/` is
MIT (`lib/smaa/LICENSE.txt`), and AMD FidelityFX FSR 1 in `lib/fsr/` is MIT
(`lib/fsr/LICENSE.txt`). The Totals checklist's rules
(`src/gameplay/totals_rules.inc`) are translated from the Archipelago
randomizer's Banjo-Tooie world, MIT (licence text at the top of that file). The SSGI and screen-space
reflections' ray march (in RT64's `SceneEffectsPS.hlsl`, through
`lib-patches/rt64.patch`) is ported from 0beqz's realism-effects, MIT (licence
text beside that code). The Stochastic reflections setting (GGX-sampled rays weighted by
the BRDF) is ported from Simeon Radivoev's ComputeStochasticReflections, MIT (licence text beside that code in
`SceneEffectsPS.hlsl`). The ambient occlusion is Ground Truth Ambient
Occlusion written from Jimenez et al.'s 2016 paper; no code is copied from
MaxwellGengYF's Unity GTAO, which has no licence.

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
* The [Banjo-Tooie Archipelago world](https://github.com/jjjj12212/AP_Banjo-Tooie)
  and its authors: the rules behind the Totals checklist's NOW column.
* PromptFont by Yukari "Shinmera" Hafner.
* Luckiest Guy by Astigmatic (Apache 2.0, `assets/LuckiestGuy-LICENSE.txt`): the
  lettering of the settings menu's sidebar layout.
* [SDL](https://www.libsdl.org/) (zlib licence): windows, input and sound; the
  Android build also uses SDL's Android Java code (`android/app/src/main/java/org/libsdl/app`).
* [FreeType](https://freetype.org/): menu fonts (built from source for Android).
* [SMAA](https://github.com/iryoku/smaa) by Jorge Jimenez, Jose I. Echevarria,
  Belen Masia, Fernando Navarro and Diego Gutierrez: the SMAA Anti-Aliasing option.
* [FidelityFX Super Resolution 1](https://github.com/GPUOpen-Effects/FidelityFX-FSR)
  by Advanced Micro Devices: the FSR 1 Upscaling option.
