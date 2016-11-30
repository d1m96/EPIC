QT += core sql
QT -= gui

CONFIG += c++11

TARGET = test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../EPIC/build/release/ -llib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../EPIC/build/debug/ -llib
else:unix: LIBS += -L$$PWD/../EPIC/build/ -llib

INCLUDEPATH += $$PWD/../EPIC/src
DEPENDPATH += $$PWD/../EPIC/src
