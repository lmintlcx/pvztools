
TEMPLATE = app
TARGET = "pvztools"

CONFIG += qt
QT += core gui widgets network

# # 5.6
# contains(CONFIG, static) {
#   CONFIG -= import_plugins
# }

# 5.14
contains(CONFIG, static) {
  CONFIG -= import_plugins
  QTPLUGIN += qwindows qwindowsvistastyle qjpeg qico qgenericbearer
}

# DEFINES += UNICODE _UNICODE _WIN32_WINNT=0x0501 _USING_V110_SDK71_ _ATL_XP_TARGETING PSAPI_VERSION=1
DEFINES += UNICODE _UNICODE _WIN32_WINNT=0x0601

win32-msvc*:QMAKE_CXXFLAGS += /MP /utf-8

win32-g++:CONFIG += c++1z
win32-msvc*:QMAKE_CXXFLAGS += /std:c++17
win32-clang-msvc:QMAKE_CXXFLAGS += -Xclang -std=c++17

INCLUDEPATH += .

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
