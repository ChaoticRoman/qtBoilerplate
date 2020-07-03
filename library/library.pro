TEMPLATE = lib

QT -= gui
QT += core

CONFIG += staticlib c++14 warn_on

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += exampleLibrary.cpp
HEADERS += exampleLibrary.h
