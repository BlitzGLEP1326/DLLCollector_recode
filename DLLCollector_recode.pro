#-------------------------------------------------
#
# Project created by QtCreator 2014-11-13T10:36:01
# Version 1.0
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DLLCollector_recode
TEMPLATE = app
CONFIG += C++11

LIBS+= -lpsapi

SOURCES += main.cpp\
        mainwindow.cpp \
    functions.cpp \
    selectprocess.cpp

HEADERS  += mainwindow.h \
    functions.h \
    selectprocess.h

FORMS    += mainwindow.ui \
    selectprocess.ui