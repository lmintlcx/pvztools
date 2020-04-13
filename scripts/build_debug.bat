@echo off

set QT_DIR=C:\Qt\Qt_5.14.2\msvc2017_x86\shared
set SRC_DIR=D:\work\pvztools
set BUILD_DIR=D:\tmp\pvztools_build

if not exist %QT_DIR% exit
if not exist %SRC_DIR% exit

if not exist %BUILD_DIR% md %BUILD_DIR%
cd /d %BUILD_DIR%

call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x86 10.0.17763.0

%QT_DIR%\bin\qmake.exe %SRC_DIR%\pvztools.pro -spec win32-msvc "CONFIG+=console"
REM %QT_DIR%\bin\lupdate.exe %SRC_DIR%\pvztools.pro
REM %QT_DIR%\bin\lrelease.exe %SRC_DIR%\pvztools.pro
if exist %BUILD_DIR%\debug\pvztools.exe del %BUILD_DIR%\debug\pvztools.exe
nmake Debug

start pythonw %SRC_DIR%\scripts\+1s.py

if not exist %BUILD_DIR%\debug\Qt5Cored.dll (
  %QT_DIR%\bin\windeployqt.exe %BUILD_DIR%\debug\pvztools.exe
  copy %QT_DIR%\bin\libcrypto-1_1.dll %BUILD_DIR%\debug\libcrypto-1_1.dll
  copy %QT_DIR%\bin\libssl-1_1.dll %BUILD_DIR%\debug\libssl-1_1.dll
)
