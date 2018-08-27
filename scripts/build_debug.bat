@echo off

set QT_DIR=C:\Qt\v5.9.6_msvc2017_x86_shared
set SRC_DIR=C:\work\pvztools
set BUILD_DIR=C:\work\pvztools_build

if not exist %QT_DIR% exit
if not exist %SRC_DIR% exit

if not exist %BUILD_DIR% md %BUILD_DIR%

call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" x86

C: && cd %BUILD_DIR%
%QT_DIR%\bin\qmake.exe %SRC_DIR%\pvztools.pro -spec win32-msvc "CONFIG+=console"
if exist %BUILD_DIR%\debug\pvztools.exe del %BUILD_DIR%\debug\pvztools.exe
nmake Debug

start pythonw %SRC_DIR%\scripts\+1s.py

if not exist %BUILD_DIR%\debug\Qt5Cored.dll %QT_DIR%\bin\windeployqt.exe %BUILD_DIR%\debug\pvztools.exe

REM nmake Release
REM if not exist %BUILD_DIR%\release\Qt5Core.dll %QT_DIR%\bin\windeployqt.exe %BUILD_DIR%\release\pvztools.exe
