@echo off

set QT_DIR=C:\Qt\Qt_5.6.3\msvc2017_x86\shared
set SRC_DIR=D:\work\pvztools
set BUILD_DIR=D:\tmp\pvztools_build

if not exist %QT_DIR% exit
if not exist %SRC_DIR% exit

if not exist %BUILD_DIR% md %BUILD_DIR%
cd /d %BUILD_DIR%

call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x86 10.0.10240.0

set PATH=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Bin;%PATH%
set INCLUDE=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Include;%INCLUDE%
set LIB=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Lib;%LIB%

%QT_DIR%\bin\qmake.exe %SRC_DIR%\pvztools.pro -spec win32-msvc2017 "CONFIG+=console"
REM %QT_DIR%\bin\lupdate.exe %SRC_DIR%\pvztools.pro
REM %QT_DIR%\bin\lrelease.exe %SRC_DIR%\pvztools.pro
if exist %BUILD_DIR%\debug\pvztools.exe del %BUILD_DIR%\debug\pvztools.exe
nmake Debug

start pythonw %SRC_DIR%\scripts\+1s.py

if not exist %BUILD_DIR%\debug\Qt5Cored.dll (
  %QT_DIR%\bin\windeployqt.exe %BUILD_DIR%\debug\pvztools.exe
  copy %QT_DIR%\bin\libeay32.dll %BUILD_DIR%\debug\libeay32.dll
  copy %QT_DIR%\bin\ssleay32.dll %BUILD_DIR%\debug\ssleay32.dll
)
