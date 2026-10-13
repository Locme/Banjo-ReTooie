@echo off
rem Pull the latest main (with submodules), then build the Windows version.
rem Same toolchain as the GitHub Actions build. Needs Git and Visual Studio 2022
rem with the C++ workload and "C++ Clang tools for Windows". See BUILDING.md.
setlocal

rem git pull can replace this file while cmd is still reading it, so run from a temporary copy.
if /i not "%~1"=="--from-copy" (
    set "REPO=%~dp0"
    copy /y "%~f0" "%TEMP%\tooie_update_and_build.bat" >nul
    call "%TEMP%\tooie_update_and_build.bat" --from-copy "%~dp0"
    exit /b %errorlevel%
)
cd /d "%~2"

where git >nul 2>&1 || ( echo Git was not found in PATH. & goto :fail )

rem The lib-patches apply to LF sources, so keep LF line endings.
git config core.autocrlf false

rem Local edits would stop the pull. Line-ending-only differences (left over from an
rem older autocrlf setting) are reset; real edits are stashed, never discarded.
git diff --quiet
if errorlevel 1 (
    git diff --ignore-cr-at-eol --quiet
    if not errorlevel 1 (
        echo Resetting files that only differ in line endings...
        git checkout -- . || goto :fail
    ) else (
        echo You have local changes. Saving them with "git stash" so the update can continue.
        echo Get them back later with: git stash pop
        git stash push -m "auto-stash by update_and_build" || goto :fail
    )
)

git pull --ff-only origin main || goto :fail
git submodule sync --recursive || goto :fail
git submodule update --init --recursive || goto :fail

set NOPAUSE=1
call "%~2build.bat" || goto :fail

echo.
echo Update and build finished.
pause
exit /b 0

:fail
echo.
echo Update or build FAILED. The messages above say where.
pause
exit /b 1
