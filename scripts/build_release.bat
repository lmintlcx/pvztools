@echo off

set QT_DIR=C:\Qt\Qt_5.15.1\msvc2019_x86\shared
set OPENSSL_DIR=C:\Qt\OpenSSL_1.1.1h\msvc2019_x86\shared
set ZLIB_DIR=C:\Qt\zlib_1.2.11.1\msvc2019_x86

set SRC_DIR=D:\work\pvztools
set BUILD_DIR=D:\tmp\pvztools_build
set UPX_DIR=C:\tools\UPX

if not exist %QT_DIR% exit
if not exist %SRC_DIR% exit
if not exist %BUILD_DIR% md %BUILD_DIR%
cd /d %BUILD_DIR%

call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" x86 10.0.19041.0

%QT_DIR%\bin\qmake.exe %SRC_DIR%\pvztools.pro -spec win32-msvc
nmake Release

start pythonw %SRC_DIR%\scripts\+1s.py

if not exist %BUILD_DIR%\release\Qt5Core.dll (
  %QT_DIR%\bin\windeployqt.exe %BUILD_DIR%\release\pvztools.exe
  copy %OPENSSL_DIR%\bin\libcrypto-1_1.dll %BUILD_DIR%\release
  copy %OPENSSL_DIR%\bin\libssl-1_1.dll %BUILD_DIR%\release
  copy %ZLIB_DIR%\bin\zlib1.dll %BUILD_DIR%\release
  copy %SRC_DIR%\res\splash.jpg %BUILD_DIR%\release
  copy %SRC_DIR%\res\lineup_string.json %BUILD_DIR%\release
  copy %SRC_DIR%\translations\qt_zh_CN.qm %BUILD_DIR%\release\translations
  copy %SRC_DIR%\translations\widgets_zh_CN.qm %BUILD_DIR%\release\translations
  copy %SRC_DIR%\translations\pvztools_zh_CN.qm %BUILD_DIR%\release\translations
)

REM %UPX_DIR%\upx.exe --lzma --ultra-brute %BUILD_DIR%\release\pvztools.exe
rem dumpbin /dependents %BUILD_DIR%\release\pvztools.exe
