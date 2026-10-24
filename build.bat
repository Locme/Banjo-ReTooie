@echo off
rem One-click Windows build. Needs Visual Studio 2022 or newer with the C++ workload and
rem "C++ Clang tools for Windows", and Git. See BUILDING.md.
rem
rem   build.bat                 any 64-bit PC from 2008 and up   (same as "compatible")
rem   build.bat compatible      Release\Any 64-bit PC (2008 and up)
rem   build.bat modern          Release\Optimized for newer CPUs (2013 and up)
rem
rem "modern" is built for AVX2 CPUs (Intel Haswell and AMD Excavator, 2013 and up) and will not
rem start on older ones. Each build has its own folder (build-cmake-compatible, build-cmake-modern),
rem so building one never throws away the other.
setlocal
cd /d "%~dp0"

set "VARIANT=%~1"
if "%VARIANT%"=="" set "VARIANT=compatible"
if /i "%VARIANT%"=="compatible" goto :set_compatible
if /i "%VARIANT%"=="modern" goto :set_modern
echo Unknown build "%VARIANT%". Use "compatible" or "modern".
goto :fail

:set_compatible
set "VARIANT=compatible"
set "OUT=Release\Any 64-bit PC (2008 and up)"
goto :variant_ok

:set_modern
set "VARIANT=modern"
set "OUT=Release\Optimized for newer CPUs (2013 and up)"

:variant_ok
set "BUILD=build-cmake-%VARIANT%"

set VSWHERE="%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
if not exist %VSWHERE% (
    echo Visual Studio 2022 or newer was not found. Install it with the
    echo "Desktop development with C++" workload. See BUILDING.md.
    goto :fail
)

rem Pick a Visual Studio install that has both the C++ tools and the Clang tools.
set VSPATH=
for /f "usebackq tokens=*" %%i in (`%VSWHERE% -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 Microsoft.VisualStudio.Component.VC.Llvm.Clang -property installationPath`) do set "VSPATH=%%i"
if "%VSPATH%"=="" (
    echo.
    echo Visual Studio is installed, but without "C++ Clang tools for Windows".
    echo Open the Visual Studio Installer, click Modify, open the
    echo "Individual components" tab, search for "C++ Clang tools for Windows",
    echo tick it, click Modify, then run this script again.
    goto :fail
)
call "%VSPATH%\VC\Auxiliary\Build\vcvars64.bat" >nul || goto :fail

set "CLANG_CL=%VSPATH%\VC\Tools\Llvm\x64\bin\clang-cl.exe"
if not exist "%CLANG_CL%" (
    echo.
    echo clang-cl.exe was not found at "%CLANG_CL%".
    echo Install "C++ Clang tools for Windows" in the Visual Studio Installer
    echo ^(Modify, Individual components^), then run this script again.
    goto :fail
)
rem Use forward slashes so CMake takes the path as is.
set "CLANG_CL=%CLANG_CL:\=/%"

rem A cache from an earlier failed configure keeps the old compiler setting.
if exist "%BUILD%\CMakeCache.txt" (
    findstr /c:"%CLANG_CL%" "%BUILD%\CMakeCache.txt" >nul || (
        echo Clearing the old CMake cache in %BUILD%.
        del /q "%BUILD%\CMakeCache.txt"
        rmdir /s /q "%BUILD%\CMakeFiles" 2>nul
    )
)

git submodule update --init --recursive || goto :fail

echo Building: %VARIANT%
cmake -S . -B "%BUILD%" -G Ninja -DCMAKE_BUILD_TYPE=RelWithDebInfo -DTOOIE_CPU=%VARIANT% -DCMAKE_C_COMPILER="%CLANG_CL%" -DCMAKE_CXX_COMPILER="%CLANG_CL%" -DCMAKE_CXX_FLAGS="-Xclang -fexceptions -Xclang -fcxx-exceptions" || goto :fail
cmake --build "%BUILD%" --target BanjoTooieN64Recomp || goto :fail

rem Gather everything the game needs to run into its Release folder.
if not exist "%OUT%" mkdir "%OUT%"
copy /y "%BUILD%\BanjoReTooie.exe" "%OUT%" >nul || goto :fail
copy /y "%BUILD%\*.dll" "%OUT%" >nul || goto :fail
if exist "%BUILD%\BanjoReTooie.pdb" copy /y "%BUILD%\BanjoReTooie.pdb" "%OUT%" >nul
rem The exe was BanjoTooieN64Recomp.exe before the game was renamed Banjo Re-Tooie.
del /q "%OUT%\BanjoTooieN64Recomp.exe" "%OUT%\BanjoTooieN64Recomp.pdb" 2>nul
copy /y recompcontrollerdb.txt "%OUT%" >nul || goto :fail
xcopy /e /i /y /q assets "%OUT%\assets" >nul || goto :fail
git rev-parse --short HEAD > "%OUT%\built_from.txt" 2>nul

call :migrate
echo.
echo Built BanjoReTooie.exe in:
echo   %CD%\%OUT%
if not defined NOPAUSE pause
exit /b 0

rem Saves, settings and mods used to sit straight in Release\. Copy them (never move or delete)
rem into this build's folder, only what it does not have yet, so the old files stay where they were.
:migrate
if not exist "Release\" exit /b 0
for %%f in ("Release\*.json") do if not exist "%OUT%\%%~nxf" copy "%%f" "%OUT%\" >nul
for %%f in (portable.txt migrated_from.txt) do if exist "Release\%%f" if not exist "%OUT%\%%f" copy "Release\%%f" "%OUT%\" >nul
for %%d in (saves save_backups mods mod_config) do if exist "Release\%%d\" robocopy "Release\%%d" "%OUT%\%%d" /e /xc /xn /xo /njh /njs /ndl /nfl /np >nul
echo.
echo Your saves, settings and mods from the old Release folder were copied here if this
echo folder did not have them yet. The old files are still in Release, untouched.
exit /b 0

:fail
echo.
echo The build failed. The messages above say where.
if not defined NOPAUSE pause
exit /b 1
