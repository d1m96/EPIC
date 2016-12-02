QT += core sql xml
QT -= gui

CONFIG += c++11

TARGET = DataBase
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = lib
CONFIG += shared

SOURCES += \
    database.cpp\
    checklist.cpp\
    param.cpp\
    specialist.cpp

HEADERS += \
    database.h\
    checklist.h\
    param.h\
    specialist.h

