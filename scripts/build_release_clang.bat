@echo off

set QT_DIR=C:\Qt\v5.11.1_clang601_x86_static
set SRC_DIR=C:\work\pvztools
set BUILD_DIR=C:\work\pvztools_build
set UPX_DIR=C:\tools\UPX

if not exist %QT_DIR% exit
if not exist %SRC_DIR% exit

if exist %BUILD_DIR% rd /q /s %BUILD_DIR%
if not exist %BUILD_DIR% md %BUILD_DIR%

call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" x86

C: && cd %BUILD_DIR%
%QT_DIR%\bin\qmake.exe %SRC_DIR%\pvztools.pro -spec win32-clang-msvc
nmake

start pythonw %SRC_DIR%\scripts\+1s.py

%UPX_DIR%\upx.exe --ultra-brute %BUILD_DIR%\release\pvztools.exe

del %SRC_DIR%\binaries\pvztools_clang.exe
copy /y %BUILD_DIR%\release\pvztools.exe %SRC_DIR%\binaries\pvztools_clang.exe

C: && cd %BUILD_DIR%\.. && if exist %BUILD_DIR% rd /q /s %BUILD_DIR%
