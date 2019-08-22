QT += core
QT -= gui

TARGET = Percolation_Simulation
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    simulation.cpp \
    node.cpp \
    grid.cpp

HEADERS += \
    simulation.h \
    node.h \
    grid.h

