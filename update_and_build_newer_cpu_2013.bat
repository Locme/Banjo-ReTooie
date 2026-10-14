@echo off
rem Update to the latest version, then build only the "Optimized for newer CPUs (2013 and up)" game.
rem The work is in update_and_build.bat. This is one line so it stays safe if git replaces it while it runs.
@call "%~dp0update_and_build.bat" modern & exit /b
