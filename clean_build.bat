@echo off
rem Deletes the build folders to free disk space. The games in Release\ are never touched:
rem your exe, saves, settings and mods all stay. Everything deleted here is remade by the next
rem build, but that next build starts from scratch, so it takes as long as the first one did.
rem
rem   clean_build.bat              asks first, then deletes both build folders
rem   clean_build.bat compatible   only build-cmake-compatible
rem   clean_build.bat modern       only build-cmake-modern
rem   clean_build.bat all /y       no question (also works with compatible or modern)
setlocal
cd /d "%~dp0"

set "WHICH=%~1"
set "ASK=1"
if /i "%~1"=="/y" (set "WHICH=all" & set "ASK=")
if /i "%~2"=="/y" set "ASK="
if "%WHICH%"=="" set "WHICH=all"

set "TARGETS="
if /i "%WHICH%"=="all" set "TARGETS=build-cmake-compatible build-cmake-modern build-cmake build-trace"
if /i "%WHICH%"=="compatible" set "TARGETS=build-cmake-compatible"
if /i "%WHICH%"=="modern" set "TARGETS=build-cmake-modern"
if not defined TARGETS (
    echo Unknown choice "%WHICH%". Use all, compatible or modern.
    goto :end
)

set "FOUND="
echo Build folders found:
for %%d in (%TARGETS%) do if exist "%%d\" (
    set "FOUND=1"
    powershell -NoProfile -Command "$s=(Get-ChildItem -LiteralPath '%%d' -Recurse -File -Force -ErrorAction SilentlyContinue | Measure-Object Length -Sum).Sum; '  {0,-24} {1,8:N2} GB' -f '%%d', ($s/1GB)"
)
if /i "%WHICH%"=="all" if exist "build-log.txt" (set "FOUND=1" & echo   build-log.txt)
if not defined FOUND (
    echo   none, nothing to clean.
    goto :end
)

if defined ASK (
    echo.
    echo The Release folder and everything in it stay as they are.
    choice /c YN /m "Delete these"
    if errorlevel 2 (echo Nothing was deleted. & goto :end)
)

for %%d in (%TARGETS%) do if exist "%%d\" (
    echo Deleting %%d...
    rmdir /s /q "%%d"
    if exist "%%d\" echo   Could not delete all of %%d. Close the game and any program using it, then try again.
)
if /i "%WHICH%"=="all" if exist "build-log.txt" del /q "build-log.txt"
echo Done.

:end
if not defined NOPAUSE pause
exit /b 0
