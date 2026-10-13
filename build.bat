@echo off
rem One-click Windows build. Needs Visual Studio 2022 with the C++ workload and
rem "C++ Clang tools for Windows", and Git. See BUILDING.md.
setlocal
cd /d "%~dp0"

set VSWHERE="%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
if not exist %VSWHERE% (
    echo Visual Studio 2022 was not found. See BUILDING.md.
    pause
    exit /b 1
)
for /f "usebackq tokens=*" %%i in (`%VSWHERE% -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set VSPATH=%%i
if "%VSPATH%"=="" (
    echo The Visual Studio C++ tools are not installed. See BUILDING.md.
    pause
    exit /b 1
)
call "%VSPATH%\VC\Auxiliary\Build\vcvars64.bat" >nul || goto :fail

git submodule update --init --recursive || goto :fail

cmake -S . -B build-cmake -G Ninja -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_C_COMPILER=clang-cl -DCMAKE_CXX_COMPILER=clang-cl -DCMAKE_CXX_FLAGS="-Xclang -fexceptions -Xclang -fcxx-exceptions" || goto :fail
cmake --build build-cmake --target BanjoTooieN64Recomp || goto :fail

copy /y build-cmake\BanjoTooieN64Recomp.exe . >nul
copy /y build-cmake\*.dll . >nul
echo.
echo Built BanjoTooieN64Recomp.exe in %CD%
pause
exit /b 0

:fail
echo.
echo The build failed. The messages above say where.
pause
exit /b 1
