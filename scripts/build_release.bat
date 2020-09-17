@echo off

set QT_DIR=C:\Qt\Qt_5.15.1\msvc2017_x86\static
set SRC_DIR=D:\work\pvztools
set BUILD_DIR=D:\tmp\pvztools_build
set UPX_DIR=C:\tools\UPX

if not exist %QT_DIR% exit
if not exist %SRC_DIR% exit
if not exist %BUILD_DIR% md %BUILD_DIR%
cd /d %BUILD_DIR%

call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x86 10.0.17763.0

%QT_DIR%\bin\qmake.exe %SRC_DIR%\pvztools.pro -spec win32-msvc
nmake Release

start pythonw %SRC_DIR%\scripts\+1s.py

%UPX_DIR%\upx.exe --lzma --ultra-brute %BUILD_DIR%\release\pvztools.exe
