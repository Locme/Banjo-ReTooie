@echo off
rem One-click Windows build. Needs Visual Studio 2022 or newer with the C++ workload and
rem "C++ Clang tools for Windows", and Git. See BUILDING.md.
setlocal
cd /d "%~dp0"

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
if exist build-cmake\CMakeCache.txt (
    findstr /c:"%CLANG_CL%" build-cmake\CMakeCache.txt >nul || (
        echo Clearing the old CMake cache in build-cmake.
        del /q build-cmake\CMakeCache.txt
        rmdir /s /q build-cmake\CMakeFiles 2>nul
    )
)

git submodule update --init --recursive || goto :fail

cmake -S . -B build-cmake -G Ninja -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_C_COMPILER="%CLANG_CL%" -DCMAKE_CXX_COMPILER="%CLANG_CL%" -DCMAKE_CXX_FLAGS="-Xclang -fexceptions -Xclang -fcxx-exceptions" || goto :fail
cmake --build build-cmake --target BanjoTooieN64Recomp || goto :fail

rem Gather everything the game needs to run into the Release folder.
if not exist Release mkdir Release
copy /y build-cmake\BanjoTooieN64Recomp.exe Release >nul || goto :fail
copy /y build-cmake\*.dll Release >nul || goto :fail
if exist build-cmake\BanjoTooieN64Recomp.pdb copy /y build-cmake\BanjoTooieN64Recomp.pdb Release >nul
copy /y recompcontrollerdb.txt Release >nul || goto :fail
xcopy /e /i /y /q assets Release\assets >nul || goto :fail
echo.
echo Built BanjoTooieN64Recomp.exe in %CD%\Release
if not defined NOPAUSE pause
exit /b 0

:fail
echo.
echo The build failed. The messages above say where.
if not defined NOPAUSE pause
exit /b 1
