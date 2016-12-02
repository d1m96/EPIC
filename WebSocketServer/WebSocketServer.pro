QT += core websockets sql
QT -= gui

CONFIG += c++11

TARGET = WebSocketServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    clientconnection.cpp\
    queries.cpp \
    processqueries.cpp \
    webserver.cpp

HEADERS += \
    clientconnection.h \
    queries.h \
    processqueries.h \
    webserver.h

#win32:
#{
#INCLUDEPATH += ../Lib/src
#LIBS += -L../../Lib/build/debug -llib
#}


win32:
{
INCLUDEPATH += ../DataBase
LIBS += -L../../DataBase/build/debug -lDataBase
}
unix: !macx
{
INCLUDEPATH += ../DataBase
LIBS += -L../../DataBase/build -lDataBase
}
