# Building

The recompiled game code (`RecompiledFuncs/` and `rsp/`) is committed, so
building the program needs no ROM. You only need your own Banjo-Tooie ROM
(NTSC-U 1.0) to play: the program asks for it the first time it starts.

## Windows (main target)

Install:

* Visual Studio 2022 with the "Desktop development with C++" workload and its
  "C++ Clang tools for Windows" component.
* [Git](https://git-scm.com/download/win).

Then double-click `build.bat`, or from a "x64 Native Tools Command Prompt for
VS 2022":

```bat
git clone --recursive https://github.com/Locme/Banjo-Tooie-N64-Recomp.git
cd Banjo-Tooie-N64-Recomp
cmake -S . -B build-cmake -G Ninja -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_C_COMPILER=clang-cl -DCMAKE_CXX_COMPILER=clang-cl -DCMAKE_CXX_FLAGS="-Xclang -fexceptions -Xclang -fcxx-exceptions"
cmake --build build-cmake --target BanjoTooieN64Recomp
```

The program is `build-cmake\BanjoTooieN64Recomp.exe`. Run it from the
repository folder so it finds `assets\`.

## Linux

Needs clang, ninja, SDL2 and GTK 3 development packages.

```sh
cmake -S . -B build-cmake -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
cmake --build build-cmake --target BanjoTooieN64Recomp
```

## Regenerating the recompiled code

Only needed after changing `banjotooie.us.toml`, `n_aspMain.us.toml`,
`extra_entries.us.txt` or the decomp. This step needs a ROM, and nothing it
reads or writes besides the generated C may be committed.

1. Build the decomp in `lib/bt-decomp` by following its README (it needs
   your `baserom.us.z64`). This produces
   `lib/bt-decomp/build/us/banjotooie_decompressed.elf` and
   `decompressed.us.z64`.
2. Build N64Recomp and RSPRecomp from `lib/N64Recomp` and copy both binaries
   to the repository root.
3. Link or copy `decompressed.us.z64` to the repository root.
4. `python3 tools/recomp_loop.py [path/to/banjotooie_decompressed.elf]` (the
   default is the one in `lib/bt-decomp`). It writes `overlays.us.txt`, the patched
   `banjotooie.us.elf` and the manual function list, then runs N64Recomp until
   it succeeds, adding any new jump targets to `extra_entries.us.txt`.
5. `./RSPRecomp n_aspMain.us.toml`

The tools need Python 3 with `pyelftools`.

## Running

Run the program from the folder that holds `assets\`. The first time, choose
**Start Game** and pick your ROM. After that, `--game bt` starts the game
straight away. An empty `portable.txt` next to the program keeps settings and
saves in that folder.

For scripted controller input (headless tests), pass `--pad-script` with steps
of the form `time_ms:action[:hold_ms]` separated by `;`, for example
`--pad-script "3000:start;6000:a;9000:x=1,y=0:2000;12000:quit"`. Buttons are
`a b z start l r du dd dl dr cu cd cl cr`, joined with `,`; `x=` and `y=` set the
stick; `quit` ends the program.

For headless test runs, see [`notes/headless-testing.md`](notes/headless-testing.md).
