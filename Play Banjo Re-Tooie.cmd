@echo off
rem Starts Banjo Re-Tooie from the folder build.bat made, after checking the files it needs are there.
rem   "Play Banjo Re-Tooie.cmd"           the newer-CPU build if it is there, else the any-PC build
rem   "Play Banjo Re-Tooie.cmd" compatible  always the any-PC build
setlocal
cd /d "%~dp0"

set "DIR="
if /i not "%~1"=="compatible" if exist "Release\Optimized for newer CPUs (2013 and up)\BanjoReTooie.exe" set "DIR=Release\Optimized for newer CPUs (2013 and up)"
if not defined DIR if exist "Release\Any 64-bit PC (2008 and up)\BanjoReTooie.exe" set "DIR=Release\Any 64-bit PC (2008 and up)"
if not defined DIR (
    echo Banjo Re-Tooie is not built yet. Run update_and_build.bat first.
    pause
    exit /b 1
)

set "MISSING="
for %%f in (recompcontrollerdb.txt SDL2.dll) do if not exist "%DIR%\%%f" set "MISSING=%%f"
if not exist "%DIR%\assets\" set "MISSING=assets folder"
if defined MISSING (
    echo "%DIR%" is missing %MISSING%. Run build.bat again to repair it.
    pause
    exit /b 1
)

start "" /d "%DIR%" "%DIR%\BanjoReTooie.exe"
