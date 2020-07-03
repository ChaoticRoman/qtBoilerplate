TEMPLATE = app

QT += core widgets gui
CONFIG += c++14 warn_on
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += main.cpp
SOURCES += mainwindow.cpp
HEADERS += mainwindow.h
FORMS += mainwindow.ui

INCLUDEPATH += ../library/
LIBS += -L../library/ -llibrary
