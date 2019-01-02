@echo off

set QT_DIR=C:\Qt\v5.6.3_mingw810_x86_static
set SRC_DIR=D:\work\pvztools
set BUILD_DIR=D:\tmp\pvztools_build
set UPX_DIR=C:\tools\UPX

if not exist %QT_DIR% exit
if not exist %SRC_DIR% exit

if exist %BUILD_DIR% rd /q /s %BUILD_DIR%
if not exist %BUILD_DIR% md %BUILD_DIR%

set PATH=C:\MinGW-w64\810\bin;%PATH%

D: && cd %BUILD_DIR%
%QT_DIR%\bin\qmake.exe %SRC_DIR%\pvztools.pro -spec win32-g++
mingw32-make

start pythonw %SRC_DIR%\scripts\+1s.py

%UPX_DIR%\upx.exe --ultra-brute %BUILD_DIR%\release\pvztools.exe

del %SRC_DIR%\binaries\pvztools_gcc.exe
copy /y %BUILD_DIR%\release\pvztools.exe %SRC_DIR%\binaries\pvztools_gcc.exe

D: && cd %BUILD_DIR%\.. && if exist %BUILD_DIR% rd /q /s %BUILD_DIR%
