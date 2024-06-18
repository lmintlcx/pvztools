
# OpenSSL

```bat

call "C:\VisualStudio\2017\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" x86

set SRC_DIR=C:\Dev\OpenSSL_1.1.1w\openssl-1.1.1w
set INS_DIR=C:\Dev\OpenSSL_1.1.1w\msvc2017_x86\shared

cd /d %SRC_DIR%
perl Configure VC-WIN32 no-asm no-tests --prefix=%INS_DIR% --openssldir=%INS_DIR%

rem makefile
rem /O1 /utf-8

nmake
nmake install

```

```txt
INS_DIR *shared -> *static
perl Configure   + no-shared
```

# Qt

```bat

rem qtbase\qmake\Makefile.win32
rem CFLAGS_BARE /O1 /utf-8

rem qtbase\mkspecs\common\msvc-desktop.conf
rem QMAKE_CFLAGS /utf-8 -DNOMINMAX
rem QMAKE_CFLAGS_OPTIMIZE = -O1


call "C:\VisualStudio\2017\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" x86

set SRC_DIR=C:\Dev\Qt_5.15.14
set INS_DIR=C:\Dev\Qt_5.15.14\msvc2017_x86\shared


cd /d %SRC_DIR%\qtbase-everywhere-src-5.15.14

git apply ..\CVE-2023-32763-qtbase-5.15.diff
git apply ..\CVE-2023-34410-qtbase-5.15.diff
git apply ..\CVE-2023-37369-qtbase-5.15.diff
git apply ..\CVE-2023-38197-qtbase-5.15.diff
git apply ..\CVE-2023-43114-5.15.patch
git apply ..\0001-CVE-2023-51714-qtbase-5.15.diff
git apply ..\0002-CVE-2023-51714-qtbase-5.15.diff
git apply ..\CVE-2024-25580-qtbase-5.15.diff

configure.bat ^
-opensource -confirm-license -platform win32-msvc ^
-shared -debug-and-release -prefix %INS_DIR% ^
-make libs -make tools -nomake examples -nomake tests ^
-sql-sqlite -sql-odbc -qt-sqlite -gif -ico -qt-libpng -qt-libjpeg ^
-qt-doubleconversion -qt-pcre -qt-zlib -qt-freetype -qt-harfbuzz ^
-no-icu -no-dbus -no-opengl -openssl-linked ^
OPENSSL_PREFIX="C:\Dev\OpenSSL_1.1.1w\msvc2017_x86\shared" ^
OPENSSL_LIBS="-llibssl -llibcrypto -lcrypt32 -lws2_32 -ladvapi32 -luser32 -lgdi32" ^
-pch -mp -optimize-size -silent

nmake && nmake install


cd /d %SRC_DIR%\qttools-everywhere-src-5.15.14
%INS_DIR%\bin\qmake.exe qttools.pro
nmake && nmake install

cd /d %SRC_DIR%\qtimageformats-everywhere-src-5.15.14
%INS_DIR%\bin\qmake.exe qtimageformats.pro
nmake && nmake install

```

```txt
INS_DIR       *shared -> *static
OpenSSL       *shared -> *static
configure.bat -shared -> -static -static-runtime
```

# zlib

```bat

rem win32/Makefile.msc
rem /O1 /utf-8

call "C:\VisualStudio\2017\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" x86

set SRC_DIR=C:\Dev\zlib_1.3.1\zlib-1.3.1
set INS_DIR=C:\Dev\zlib_1.3.1\msvc2017_x86\shared

cd /d %SRC_DIR%
nmake -f win32/Makefile.msc


md %INS_DIR%\bin
md %INS_DIR%\include
md %INS_DIR%\lib

copy %SRC_DIR%\zlib.h %INS_DIR%\include
copy %SRC_DIR%\zconf.h %INS_DIR%\include

rem static
copy %SRC_DIR%\zlib.lib %INS_DIR%\lib
copy %SRC_DIR%\zlib.map %INS_DIR%\lib
copy %SRC_DIR%\zlib.pdb %INS_DIR%\lib

rem shared
copy %SRC_DIR%\zlib1.dll %INS_DIR%\bin
copy %SRC_DIR%\zlib1.pdb %INS_DIR%\bin
copy %SRC_DIR%\zdll.lib %INS_DIR%\lib
copy %SRC_DIR%\zdll.exp %INS_DIR%\lib

```

```txt
INS_DIR *shared -> *static
rem /MD -> /MT
```
