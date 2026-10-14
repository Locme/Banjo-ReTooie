@echo off
rem Pull the latest main (with submodules), then build the Windows versions.
rem
rem   update_and_build.bat                      both builds (the two wrappers below pick one)
rem   update_and_build_any_pc_2008.bat          only Release\Any 64-bit PC (2008 and up)
rem   update_and_build_newer_cpu_2013.bat       only Release\Optimized for newer CPUs (2013 and up)
rem
rem Same toolchain as the GitHub Actions build. Needs Git and Visual Studio 2022
rem with the C++ workload and "C++ Clang tools for Windows". See BUILDING.md.
rem
rem It repairs what usually breaks a build by itself: half-applied submodule
rem patches, a stale build folder and an update that cannot fast-forward. If the
rem new code itself does not build, the games in Release\ are left as they were and
rem the full output is saved in build-log.txt to send in.
setlocal

rem Which builds to make: compatible, modern or both (the default).
set "WHICH=both"
if /i "%~1"=="compatible" set "WHICH=compatible"
if /i "%~1"=="modern" set "WHICH=modern"
if /i "%~1"=="--from-copy" (
    if /i "%~3"=="compatible" set "WHICH=compatible"
    if /i "%~3"=="modern" set "WHICH=modern"
)

rem git pull can replace this file while cmd is still reading it, so run from a temporary copy.
if /i not "%~1"=="--from-copy" (
    rem A fresh name each run: a newer version may start while an older copy is still running.
    for /f %%r in ("%RANDOM%%RANDOM%") do (
        copy /y "%~f0" "%TEMP%\tooie_update_and_build_%%r.bat" >nul
        call "%TEMP%\tooie_update_and_build_%%r.bat" --from-copy "%~dp0" %WHICH%
    )
    exit /b
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

rem If the update changed this script, start the new version (the copy running now is the old one).
fc /b "%~f0" "%~2update_and_build.bat" >nul 2>&1
if errorlevel 1 (
    echo update_and_build.bat was updated. Starting the new version...
    call "%~2update_and_build.bat" %WHICH%
    exit /b
)

rem Put every submodule back to its clean checkout. CMake re-applies lib-patches on the
rem next configure, so leftovers from an older patch can never block it.
git submodule sync --recursive >nul || goto :fail
git submodule foreach --recursive --quiet "git reset -q --hard && git clean -q -fd"
call :retry git submodule update --init --recursive --force || goto :fail

set NOPAUSE=1
if /i "%WHICH%"=="modern" goto :only_modern

call :build_variant compatible || goto :failed
if /i "%WHICH%"=="compatible" goto :done

:only_modern
call :build_variant modern || goto :failed
goto :done

:failed
echo.
echo The errors, without the warnings around them:
powershell -NoProfile -Command "Select-String -Path build-log.txt -Pattern 'error:','error [A-Z]+[0-9]+','FAILED:','CMake Error' | Select-Object -First 20 | ForEach-Object { $_.Line }"
echo.
echo ============================================================
echo  The build FAILED twice, so this update has a real error.
echo  The game that failed to build was NOT changed and still works.
echo  A build that finished before it, if any, is already updated.
echo  Send build-log.txt from this folder in the project so it can be fixed.
echo ============================================================
pause
exit /b 1

:done
echo.
echo Update and build finished. The games are in the Release folder:
if /i not "%WHICH%"=="modern" echo   Release\Any 64-bit PC (2008 and up)
if /i not "%WHICH%"=="compatible" echo   Release\Optimized for newer CPUs (2013 and up)
echo Saves, settings and mods from the old Release folder were copied into them, and the old ones are untouched.
pause
exit /b 0

rem Builds one variant (compatible or modern): once, then once more from a clean build folder.
:build_variant
set "V=%~1"
echo.
echo Building the %V% version...
call :build %V%
if not errorlevel 1 exit /b 0
echo.
echo The build failed. Trying once more from a clean build folder...
if exist "build-cmake-%V%" rmdir /s /q "build-cmake-%V%"
call :build %V%
exit /b %errorlevel%

rem Runs build.bat for one variant, showing its output and saving it to build-log.txt.
:build
powershell -NoProfile -ExecutionPolicy Bypass -Command "cmd /c 'build.bat %~1 2>&1' | Tee-Object -FilePath build-log.txt; exit $LASTEXITCODE"
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
echo Your games in the Release folder were not changed.
pause
exit /b 1
