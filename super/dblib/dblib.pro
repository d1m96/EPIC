#-------------------------------------------------
#
# Project created by QtCreator 2016-10-26T17:08:47
#
#-------------------------------------------------

QT       += sql

QT       -= gui

TARGET = dblib
TEMPLATE = lib

DEFINES += DBLIB_LIBRARY

SOURCES += dblib.cpp

HEADERS += dblib.h\
        dblib_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
