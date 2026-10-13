@echo off
rem Pull the latest main (with submodules), then build the Windows version.
rem Same toolchain as the GitHub Actions build. Needs Git and Visual Studio 2022
rem with the C++ workload and "C++ Clang tools for Windows". See BUILDING.md.
setlocal
cd /d "%~dp0"

where git >nul 2>&1 || ( echo Git was not found in PATH. & goto :fail )

rem The lib-patches apply to LF sources, so keep LF line endings.
git config core.autocrlf false

git pull --ff-only origin main || goto :fail
git submodule sync --recursive || goto :fail
git submodule update --init --recursive || goto :fail

set NOPAUSE=1
call "%~dp0build.bat" || goto :fail

echo.
echo Update and build finished.
pause
exit /b 0

:fail
echo.
echo Update or build FAILED. The messages above say where.
echo If the pull failed, commit or stash local changes and try again.
pause
exit /b 1
