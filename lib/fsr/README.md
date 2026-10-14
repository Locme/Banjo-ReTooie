# FSR 1

`ffx_a.h` and `ffx_fsr1.h` are unchanged copies from
[GPUOpen-Effects/FidelityFX-FSR](https://github.com/GPUOpen-Effects/FidelityFX-FSR)
(commit `a21ffb8`), AMD FidelityFX Super Resolution 1.0 by Advanced Micro Devices,
under the MIT licence in `LICENSE.txt`.

RT64 builds its FSR passes from them (`src/shaders/FsrPS.hlsl` and
`src/render/rt64_fsr.cpp`, added by `lib-patches/rt64.patch`): EASU upscales the
game image to the window's size and RCAS sharpens it. The Graphics tab's FSR 1
Upscaling option turns it on.
