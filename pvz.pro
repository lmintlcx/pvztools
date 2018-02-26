
QT += core gui widgets
CONFIG += qt thread warn_on

TEMPLATE = app
TARGET = "pvz"

QMAKE_CXXFLAGS += /MP

# # UAC
# QMAKE_LFLAGS += /MANIFESTUAC:\"level=\'requireAdministrator\' uiAccess=\'false\'\"

HEADERS += \
        src/window.h \
        src/pvz.h

SOURCES += \
        src/main.cpp \
        src/window.cpp \
        src/pvz.cpp

TRANSLATIONS += i18n/zh_CN.ts
# CODECFORTR = utf-8

RESOURCES += pvz.qrc

RC_FILE = res/version.rc

OTHER_FILES += \
            scripts/build_vc140.bat \
            scripts/build_vc141.bat \
            scripts/+1s.py \
            LICENSE \
            README.md

CONFIG(debug, debug|release) {
  CONFIG += console
}

contains(DEFINES, _TARGET_XP_){
  QMAKE_LFLAGS_WINDOWS = /SUBSYSTEM:WINDOWS,5.01
  QMAKE_LFLAGS_CONSOLE = /SUBSYSTEM:CONSOLE,5.01
  DEFINES += _ATL_XP_TARGETING
  QMAKE_CFLAGS += /D_USING_V110_SDK71_
  QMAKE_CXXFLAGS += /D_USING_V110_SDK71_
  INCLUDEPATH += $$quote(C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Include)
  LIBS += -L$$quote(C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Lib)
}
