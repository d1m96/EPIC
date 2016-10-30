QT += core network widgets

CONFIG += c++11

TARGET = Client
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    client.cpp

HEADERS += \
    client.h
