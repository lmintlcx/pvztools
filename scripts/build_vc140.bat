@echo off
title qmake and nmake build shell

:set_env
set "VC_DIR=C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC"
set "SDK_DIR=C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A"
set "QT_DIR=C:\Qt\5.6.3_msvc2015_x86_static"
set "SRC_DIR=D:\repo\pvz"
set "BUILD_DIR=D:\repo\pvz_build"
set "UPX_DIR=C:\tools\UPX"

set "PATH=%SDK_DIR%\Bin;%PATH%"
set "INCLUDE=%SDK_DIR%\Include;%INCLUDE%"
set "LIB=%SDK_DIR%\Lib;%LIB%"
set "CL=/D_USING_V110_SDK71_"

if not "%1" == "debug" (if not "%1" == "release" goto eof)
if not exist "%VC_DIR%" goto eof
if not exist "%SDK_DIR%" goto eof
if not exist "%QT_DIR%" goto eof
if not exist "%SRC_DIR%" goto eof
if not exist "%BUILD_DIR%" goto eof
if not exist "%UPX_DIR%" goto eof

:call_vs
D: && cd %BUILD_DIR%
call "%VC_DIR%\vcvarsall.bat" x86
if "%1" == "debug" ( goto make_debug ) else ( goto make_release )

:make_debug
%QT_DIR%\bin\qmake.exe %SRC_DIR%\pvz.pro -spec win32-msvc2015 "DEFINES+=_TARGET_XP_"
REM %QT_DIR%\bin\lupdate.exe %SRC_DIR%\pvz.pro
del %BUILD_DIR%\debug\pvz.exe
nmake Debug
goto eof

:make_release
%QT_DIR%\bin\qmake.exe %SRC_DIR%\pvz.pro -spec win32-msvc2015 "DEFINES+=_TARGET_XP_"
REM %QT_DIR%\bin\lrelease.exe %SRC_DIR%\pvz.pro
del %BUILD_DIR%\release\pvz.exe
nmake clean
nmake Release
%UPX_DIR%\upx.exe --brute %BUILD_DIR%\release\pvz.exe
rem %UPX_DIR%\upx.exe --ultra-brute %BUILD_DIR%\release\pvz.exe
goto eof

:eof
start pythonw %SRC_DIR%\scripts\+1s.py
REM exit
