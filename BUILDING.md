# Building

The recompiled game code (`RecompiledFuncs/` and `rsp/`) is committed, so
building the program needs no ROM. You only need your own Banjo-Tooie ROM
(NTSC-U 1.0) to play: the program asks for it the first time it starts.

## Windows (main target)

Install:

* Visual Studio 2022 or newer, with the "Desktop development with C++"
  workload and the individual component "C++ Clang tools for Windows".
  To add the component to an installed Visual Studio: open the Visual Studio
  Installer, click **Modify**, open the **Individual components** tab, search
  for "C++ Clang tools for Windows", tick it and click **Modify** again.
* [Git](https://git-scm.com/download/win).

The easy path is to double-click `build.bat`. It finds Visual Studio and the
Clang tools, fetches the submodules and builds. It stops with a message if
something is missing.

There are two Windows builds, each in its own `Release` subfolder:

| Build | `build.bat` argument | CMake option | Folder |
| --- | --- | --- | --- |
| Any 64-bit PC, 2008 and up (the default) | `compatible` | `-DTOOIE_CPU=compatible` | `Release\Any 64-bit PC (2008 and up)` |
| Optimized for newer CPUs, 2013 and up (AVX2, will not start on older CPUs) | `modern` | `-DTOOIE_CPU=modern` | `Release\Optimized for newer CPUs (2013 and up)` |

`build.bat` alone makes the first one; `build.bat modern` makes the second. Each
has its own build folder (`build-cmake-compatible`, `build-cmake-modern`), so
building one does not touch the other.

To update from GitHub and build, use `update_and_build.bat` (both builds),
`update_and_build_any_pc_2008.bat` (only the 2008 and up build) or
`update_and_build_newer_cpu_2013.bat` (only the 2013 and up build). If the new
code does not build, the game that failed is left as it was and the output is
saved in `build-log.txt`.

Saves, settings and mods used to sit directly in `Release\`. The first time a
build fills a new folder, it copies the saves, the settings files, `mods` and
`save_backups` from `Release\` into it if the folder does not have them yet. It
never moves or deletes the old files. `build-cmake` from older versions is no
longer used and can be deleted.

`clean_build.bat` deletes the build folders (`build-cmake-compatible`,
`build-cmake-modern`, and the old `build-cmake`) to free disk space. It shows their
sizes and asks first, and it never touches `Release\`. The next build after it
starts from scratch, so it takes as long as a first build.

To build by hand, open an "x64 Native Tools Command Prompt for VS 2022" (or
the version you have) and run:

```bat
git clone --recursive https://github.com/Locme/Banjo-Tooie-N64-Recomp.git
cd Banjo-Tooie-N64-Recomp
cmake -S . -B build-cmake -G Ninja -DCMAKE_BUILD_TYPE=RelWithDebInfo -DTOOIE_CPU=compatible -DCMAKE_C_COMPILER=clang-cl -DCMAKE_CXX_COMPILER=clang-cl -DCMAKE_CXX_FLAGS="-Xclang -fexceptions -Xclang -fcxx-exceptions"
cmake --build build-cmake --target BanjoTooieN64Recomp
```

If you use a normal Command Prompt instead, replace both `clang-cl` names with
the full path, `"C:\Program Files\Microsoft Visual Studio\2022\<edition>\VC\Tools\Llvm\x64\bin\clang-cl.exe"`
(adjust the path to your install).

`build.bat` puts the finished game in its `Release` subfolder (see the table
above): the exe, its DLLs, `assets\`, `recompcontrollerdb.txt` and
`built_from.txt`. Run `BanjoTooieN64Recomp.exe` from there.
If you build by hand, the program is `build-cmake\BanjoTooieN64Recomp.exe`;
run it from a folder that holds `assets\` and `recompcontrollerdb.txt` (copy
them from the repository, or run from a `Release` subfolder after `build.bat`).

### Troubleshooting

* **`clang-cl is not a full path and was not found in the PATH`**: CMake
  cannot find the Clang compiler. Either build from an "x64 Native Tools Command
  Prompt", or use `build.bat`, or give the full path to `clang-cl.exe` as shown
  above.
* **`clang-cl.exe was not found`** from `build.bat`: the "C++ Clang tools for
  Windows" component is not installed. Add it as described above, then run
  `build.bat` again.

## Linux

Needs clang, ninja and GTK 3 development packages, plus SDL3 with
[sdl2-compat](https://github.com/libsdl-org/sdl2-compat) on top (the game uses
the SDL2 API; SDL3's controller drivers report back buttons on more pads).
`.github/workflows/build.yml` shows how to build and install both.

```sh
cmake -S . -B build-cmake -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
cmake --build build-cmake --target BanjoTooieN64Recomp
```

## Android (early: aims to boot to the title screen)

The `android/` folder is an Android Studio project. It builds the same game code
for 64-bit ARM phones (`arm64-v8a`, Android 10 or newer with Vulkan) as
`libmain.so`, next to SDL2, and packs `assets/` into the APK.

Install:

* [Android Studio](https://developer.android.com/studio). In **Tools > SDK Manager >
  SDK Tools**, tick **NDK (Side by side)** 27.2.12479018 and **CMake** 3.22.1.
* Git, with the submodules fetched (`git submodule update --init --recursive`).
  The first build also downloads SDL 2.30.9 and FreeType 2.13.3 with Git.

Open the `android` folder in Android Studio, connect the phone with USB debugging
on, and press **Run**. Or build from a command line in `android/`:

```bat
gradlew assembleRelease
```

The APK is `android\app\build\outputs\apk\release\app-release.apk` (signed with
the debug key, so it installs without a release key).

The first time the app starts it asks for your Banjo-Tooie ROM (US release) and
copies it in. Saves, settings, mods and `logs\console.log` are in
`Android/data/io.github.locme.banjotooie/files` on the phone's storage.

Not done yet: touch controls (use a controller), and leaving the app while the
game runs (switching away may close or crash it).

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
