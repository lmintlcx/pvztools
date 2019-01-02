@echo off

set QT_DIR=C:\Qt\v5.9.7_msvc2017_x86_shared
set SRC_DIR=D:\work\pvztools
set BUILD_DIR=D:\tmp\pvztools_build

if not exist %QT_DIR% exit
if not exist %SRC_DIR% exit

if not exist %BUILD_DIR% md %BUILD_DIR%

call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" x86

D: && cd %BUILD_DIR%
%QT_DIR%\bin\qmake.exe %SRC_DIR%\pvztools.pro -spec win32-msvc

%QT_DIR%\bin\lupdate.exe %SRC_DIR%\pvztools.pro

echo translating
pause

%QT_DIR%\bin\lrelease.exe %SRC_DIR%\pvztools.pro
