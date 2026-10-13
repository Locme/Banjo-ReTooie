@echo off
rem Pull the latest main (with submodules), then build the Windows version.
rem Same toolchain as the GitHub Actions build. Needs Git and Visual Studio 2022
rem with the C++ workload and "C++ Clang tools for Windows". See BUILDING.md.
rem
rem It repairs what usually breaks a build by itself: half-applied submodule
rem patches, a stale build folder and an update that cannot fast-forward. If the
rem new code itself does not build, the game in Release\ is left as it was and
rem the full output is saved in build-log.txt to send in.
setlocal

rem git pull can replace this file while cmd is still reading it, so run from a temporary copy.
if /i not "%~1"=="--from-copy" (
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
git diff --quiet --ignore-submodules
if errorlevel 1 (
    git diff --ignore-cr-at-eol --ignore-submodules --quiet
    if not errorlevel 1 (
        echo Resetting files that only differ in line endings...
        git checkout -- . || goto :fail
    ) else (
        echo You have local changes. Saving them with "git stash" so the update can continue.
        echo Get them back later with: git stash pop
        git stash push -m "auto-stash by update_and_build" || goto :fail
    )
)

call :retry git fetch origin main || goto :fail
git merge --ff-only FETCH_HEAD >nul 2>&1
if not errorlevel 1 goto :updated
rem Local commits on main: keep them on a backup branch, then follow origin/main.
for /f %%t in ('powershell -NoProfile -Command "Get-Date -Format yyyyMMdd-HHmmss"') do set "STAMP=%%t"
echo Your main has commits that are not on GitHub. Keeping them on branch backup-%STAMP%.
git branch "backup-%STAMP%" || goto :fail
git reset --hard FETCH_HEAD || goto :fail
:updated

rem Put every submodule back to its clean checkout. CMake re-applies lib-patches on the
rem next configure, so leftovers from an older patch can never block it.
git submodule sync --recursive >nul || goto :fail
git submodule foreach --recursive --quiet "git reset -q --hard && git clean -q -fd"
call :retry git submodule update --init --recursive --force || goto :fail

set NOPAUSE=1
call :build
if not errorlevel 1 goto :done

echo.
echo The build failed. Trying once more from a clean build folder...
if exist build-cmake rmdir /s /q build-cmake
call :build
if not errorlevel 1 goto :done

echo.
echo ============================================================
echo  The build FAILED twice, so this update has a real error.
echo  Your game in the Release folder was NOT changed and still works.
echo  Send build-log.txt from this folder in the project so it can be fixed.
echo ============================================================
pause
exit /b 1

:done
git rev-parse --short HEAD > Release\built_from.txt 2>nul
echo.
echo Update and build finished.
pause
exit /b 0

rem Runs build.bat, showing its output and saving it to build-log.txt.
:build
powershell -NoProfile -ExecutionPolicy Bypass -Command "cmd /c 'build.bat 2>&1' | Tee-Object -FilePath build-log.txt; exit $LASTEXITCODE"
exit /b %errorlevel%

rem Runs a git command up to 3 times, for network hiccups.
:retry
%* && exit /b 0
echo Retrying: %*
timeout /t 3 /nobreak >nul
%* && exit /b 0
timeout /t 6 /nobreak >nul
%*
exit /b %errorlevel%

:fail
echo.
echo Update FAILED before the build started. The messages above say where.
echo Your game in the Release folder was not changed.
pause
exit /b 1
