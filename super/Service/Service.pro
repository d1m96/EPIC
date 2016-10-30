QT += core network widgets
QT += sql

#изменить пути
#INCLUDEPATH += ../../EPIC-testi/EPIC-testi #тут было ../EPIC-testi
#LIBS += "../../EPIC-testi/build/debug/dblib.dll"

INCLUDEPATH += ../dblib
LIBS += "../Build_dblib/debug/dblib.dll"

CONFIG += c++11

TARGET = Service
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    server.cpp

HEADERS += \
    server.h
