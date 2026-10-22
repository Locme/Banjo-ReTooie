@echo off
rem One-click Windows build of the barebone version. Needs the same tools as build.bat: Visual Studio
rem 2022 or newer with the C++ workload and "C++ Clang tools for Windows", and Git. See BUILDING.md.
rem
rem The barebone build is made from its own copies in barebone\files, never from the main files. This
rem script copies the project into build-barebone-src, puts the barebone copies over it, and builds
rem that copy. Its output goes to Release\Barebone. The normal builds are not touched.
rem
rem Keep barebone\files in step with main: see barebone\BASE.txt for the commit the copies were taken from.
setlocal
cd /d "%~dp0"

set "OUT=Release\Barebone"
set "SRC=build-barebone-src"
set "BUILD=build-cmake-barebone"

set VSWHERE="%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
if not exist %VSWHERE% (
    echo Visual Studio 2022 or newer was not found. Install it with the
    echo "Desktop development with C++" workload. See BUILDING.md.
    goto :fail
)

set VSPATH=
for /f "usebackq tokens=*" %%i in (`%VSWHERE% -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 Microsoft.VisualStudio.Component.VC.Llvm.Clang -property installationPath`) do set "VSPATH=%%i"
if "%VSPATH%"=="" (
    echo Visual Studio is installed, but without "C++ Clang tools for Windows".
    echo Add it in the Visual Studio Installer under Individual components, then run this again.
    goto :fail
)
call "%VSPATH%\VC\Auxiliary\Build\vcvars64.bat" >nul || goto :fail

set "CLANG_CL=%VSPATH%\VC\Tools\Llvm\x64\bin\clang-cl.exe"
if not exist "%CLANG_CL%" (
    echo clang-cl.exe was not found at "%CLANG_CL%". Install "C++ Clang tools for Windows".
    goto :fail
)
set "CLANG_CL=%CLANG_CL:\=/%"

git submodule update --init --recursive || goto :fail

rem Stage the project: everything except git, old build folders and the barebone's own folder.
echo Staging the barebone copy in %SRC%
robocopy . "%SRC%" /E /XD .git build-cmake-* build-barebone-src Release barebone /NFL /NDL /NJH /NJS /NP >nul
if %ERRORLEVEL% GEQ 8 goto :fail
rem Put the barebone copies over the staged project (main's files are only read, never written).
robocopy barebone\files "%SRC%" /E /NFL /NDL /NJH /NJS /NP >nul
if %ERRORLEVEL% GEQ 8 goto :fail

rem A cache from an earlier failed configure keeps the old compiler setting.
if exist "%BUILD%\CMakeCache.txt" (
    findstr /c:"%CLANG_CL%" "%BUILD%\CMakeCache.txt" >nul || (
        del /q "%BUILD%\CMakeCache.txt"
        rmdir /s /q "%BUILD%\CMakeFiles" 2>nul
    )
)

echo Building: barebone
cmake -S "%SRC%" -B "%BUILD%" -G Ninja -DCMAKE_BUILD_TYPE=RelWithDebInfo -DTOOIE_CPU=compatible -DCMAKE_C_COMPILER="%CLANG_CL%" -DCMAKE_CXX_COMPILER="%CLANG_CL%" -DCMAKE_CXX_FLAGS="-Xclang -fexceptions -Xclang -fcxx-exceptions" || goto :fail
cmake --build "%BUILD%" --target BanjoTooieN64Recomp || goto :fail

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
