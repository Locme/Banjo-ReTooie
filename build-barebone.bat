@echo off
rem One-click Windows build of the barebone version. Needs the same tools as build.bat: Visual Studio
rem 2022 or newer with the C++ workload and "C++ Clang tools for Windows", and Git. See BUILDING.md.
rem
rem   build-barebone.bat      Release\Barebone (no jiggle physics or extra shaders)
rem
rem The barebone build leaves out the snout, Kazooie, Mumbo and backpack jiggle, and the optional RT64
rem shader passes. SMAA and the sun shadow map stay. It has its own folder (build-cmake-barebone) and
rem output folder (Release\Barebone), so it never replaces the normal builds.
setlocal
cd /d "%~dp0"

set "OUT=Release\Barebone"
set "BUILD=build-cmake-barebone"

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

echo Building: barebone
cmake -S . -B "%BUILD%" -G Ninja -DCMAKE_BUILD_TYPE=RelWithDebInfo -DTOOIE_CPU=compatible -DTOOIE_BAREBONE=ON -DCMAKE_C_COMPILER="%CLANG_CL%" -DCMAKE_CXX_COMPILER="%CLANG_CL%" -DCMAKE_CXX_FLAGS="-Xclang -fexceptions -Xclang -fcxx-exceptions" || goto :fail
cmake --build "%BUILD%" --target BanjoTooieN64Recomp || goto :fail

rem Gather everything the game needs to run into its Barebone folder.
if not exist "%OUT%" mkdir "%OUT%"
copy /y "%BUILD%\BanjoTooieN64Recomp.exe" "%OUT%" >nul || goto :fail
copy /y "%BUILD%\*.dll" "%OUT%" >nul || goto :fail
if exist "%BUILD%\BanjoTooieN64Recomp.pdb" copy /y "%BUILD%\BanjoTooieN64Recomp.pdb" "%OUT%" >nul
copy /y recompcontrollerdb.txt "%OUT%" >nul || goto :fail
xcopy /e /i /y /q assets "%OUT%\assets" >nul || goto :fail
git rev-parse --short HEAD > "%OUT%\built_from.txt" 2>nul

echo.
echo Built BanjoTooieN64Recomp.exe in:
echo   %CD%\%OUT%
if not defined NOPAUSE pause
exit /b 0

:fail
echo.
echo The barebone build failed. The messages above say where.
if not defined NOPAUSE pause
exit /b 1
