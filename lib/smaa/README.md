# SMAA

`SMAA.hlsl`, `AreaTex.h` and `SearchTex.h` are unchanged copies from
[iryoku/smaa](https://github.com/iryoku/smaa) (commit `71c806a`), by Jorge
Jimenez, Jose I. Echevarria, Belen Masia, Fernando Navarro and Diego Gutierrez,
under the MIT licence in `LICENSE.txt`.

RT64 builds its SMAA passes from them (`src/shaders/SmaaPS.hlsl` and
`src/render/rt64_smaa.cpp`, added by `lib-patches/rt64.patch`). The Graphics
tab's Anti-Aliasing (SMAA) option picks the preset.
