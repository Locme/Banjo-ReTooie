@echo off
rem Update to the latest version, then build only the "Any 64-bit PC (2008 and up)" game.
rem The work is in update_and_build.bat. This is one line so it stays safe if git replaces it while it runs.
@call "%~dp0update_and_build.bat" compatible & exit /b
