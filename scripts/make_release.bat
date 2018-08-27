@echo off

set SCRIPT_DIR=C:\work\pvztools\scripts

call %SCRIPT_DIR%\build_release_gcc.bat
call %SCRIPT_DIR%\build_release_msvc.bat
call %SCRIPT_DIR%\build_release_clang.bat
