
TEMPLATE = app
TARGET = "pvztools"

CONFIG += qt
QT += core gui widgets network

DEFINES += UNICODE _UNICODE

win32-msvc*:QMAKE_CXXFLAGS += /std:c++17 /MP /utf-8

DEFINES += _WIN32_WINNT=0x0601

contains(CONFIG, static) {
  CONFIG -= import_plugins
  QTPLUGIN += qwindows qwindowsvistastyle qjpeg qico qgenericbearer
}

INCLUDEPATH += .

# zlib
INCLUDEPATH += $$quote(C:\Qt\zlib_1.2.11.1\msvc2019_x86\include)
LIBS += -L$$quote(C:\Qt\zlib_1.2.11.1\msvc2019_x86\lib) -lzdll

win32-msvc*:PRECOMPILED_HEADER = src/stable.h

HEADERS += src/version.h \
           src/process.h \
           src/code.h \
           src/pak.h \
           src/bot.h \
           src/pvz.h \
           src/list.h \
           src/pages.h \
           src/window.h \
           src/application.h

SOURCES += src/main.cpp \
           src/process.cpp \
           src/code.cpp \
           src/pak.cpp \
           src/bot.cpp \
           src/pvz.cpp \
           src/list.cpp \
           src/pages.cpp \
           src/window.cpp \
           src/application.cpp

RESOURCES += pvztools.qrc

RC_FILE = pvztools.rc

CODECFORSRC  = UTF-8
TRANSLATIONS += translations/pvztools_zh_CN.ts
