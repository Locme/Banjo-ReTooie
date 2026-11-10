# Third-party code, licences and credits

Banjo Re-Tooie is GPL-3.0 (see [`COPYING`](../COPYING)). This page lists the code, fonts and art from
other projects that it uses or learned from, and the licence of each.

## Licences

The DLSS runtime `nvngx_dlss.dll` that Windows builds fetch and ship beside the game is NVIDIA's, under NVIDIA's own
licence (`third-party/nvidia-dlss/LICENSE.txt`), not the GPL.
The FSR 3 / FSR 4 DLLs (`amd_fidelityfx_loader_dx12.dll`, `amd_fidelityfx_upscaler_dx12.dll`) that Windows builds fetch and ship are
AMD's, redistributed in binary form under AMD's licence (`third-party/amd-fsr/LICENSE.txt`), not the GPL.
Android builds include Qualcomm's Snapdragon GSR 1 shader (`third-party/snapdragon-gsr`, BSD 3-Clause).

GPL-3.0, see [`COPYING`](../COPYING). N64ModernRuntime is GPL-3.0; N64Recomp and
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

The volumetric fog's presets (Default, Bright, Hell, Murky, Poison, Sponza, Pillar) use the settings (albedo,
extinction, emissive, ambient light) of the presets in Arthur Brussee's
[Vapor](https://github.com/ArthurBrussee/Vapor), MIT (licence text beside that code in `SceneEffectsPS.hlsl`);
the march itself is our own, written from Wronski's 2014 and Hillaire's 2015 volumetric scattering papers. The
Unity Asset Store package "Aero - Volumetric Fog and Mist" is under Unity's Asset Store EULA, which does not let its
source go into another project, so none of it is used.

The volumetric shadows (WIP) are written from Billeter, Sintorn and Assarsson's paper "Real Time Volumetric Shadows
using Polygonal Light Volumes" (High Performance Graphics 2010): a mesh round the lit air is raised from a depth map
drawn from the light, and its faces add and take away the light gathered along each pixel's ray. No code is copied
from anywhere.

## Credits

* Locme: direction, design and play-testing, the game's icon (`icons/`) and the
  start menu art (`assets/launcher/`).
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
  data, and the model names in `tools/texture_categories.csv` (MIT, licence text at the top of that file).
* retroben, illusion and wedarobi: facts from the Xenia Banjo-Tooie game patch.
* The [Banjo-Tooie Archipelago world](https://github.com/jjjj12212/AP_Banjo-Tooie)
  and its authors: the rules behind the Totals checklist's NOW column.
* PromptFont by Yukari "Shinmera" Hafner.
* u/Plebian_Donkey_Konga on Reddit: the Banjo-Tooie style lettering used for the
  start menu's BANJO RE-TOOIE title.
* Luckiest Guy by Astigmatic (Apache 2.0, `assets/LuckiestGuy-LICENSE.txt`): the
  lettering of the settings menu's sidebar layout.
* [SDL](https://www.libsdl.org/) (zlib licence): windows, input and sound; the
  Android build also uses SDL's Android Java code (`android/app/src/main/java/org/libsdl/app`).
* [FreeType](https://freetype.org/): menu fonts (built from source for Android).
* [SMAA](https://github.com/iryoku/smaa) by Jorge Jimenez, Jose I. Echevarria,
  Belen Masia, Fernando Navarro and Diego Gutierrez: the SMAA Anti-Aliasing option.
* [FidelityFX Super Resolution 1](https://github.com/GPUOpen-Effects/FidelityFX-FSR)
  by Advanced Micro Devices: the FSR 1 Upscaling option.
* The Mario Party 3 recomp (GPLv3, same author): the sampling profiler behind the console's
  `hostprof` (`src/debug/host_profiler.cpp`).
