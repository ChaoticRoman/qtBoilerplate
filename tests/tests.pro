TEMPLATE = app

QT += core testlib

CONFIG += c++14 warn_on

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += testExampleLibrary.cpp testExampleLibrary2.cpp main.cpp

HEADERS += testExampleLibrary.h testExampleLibrary2.h

LIBS += -L../library/ -llibrary
PRE_TARGETDEPS = ../library
