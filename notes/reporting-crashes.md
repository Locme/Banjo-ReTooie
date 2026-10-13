# Reporting a crash or a freeze

When the game crashes or freezes, send the logs from the folder that holds the
exe you ran. For a local build from `build.bat` that is `Release\`.

1. Open the folder with `BanjoTooieN64Recomp.exe`, then open `logs\`.
2. Drag these files into the thread:
   - `crashes.log`: one entry per crash. Since build 47ab4e6 it also has the
     last C++ error and the crashing code. Each entry now also lists the build
     (commit) and every setting in effect, including the frame rate and the
     aspect ratio (widescreen) with the window size.
   - `console.log`: everything the game printed. Since 227db85 it is kept here.
     It starts with the build and the settings, and notes each setting you
     change while playing.
   - `hangs.log`: freezes of 5 seconds or more, written by the watchdog.
   - the newest `crash_*.dmp` file, if there is one. The game keeps only the
     newest 5 dumps (about 40 MB each) and deletes older ones at start.
3. Keep `Release\BanjoTooieN64Recomp.pdb` next to the exe. Without it, crash
   logs show addresses instead of function names.

Only the files in `logs\` and the newest `.dmp` are needed. Nothing else in the
folder is needed for a report.
