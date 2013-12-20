#-------------------------------------------------
#
# Project created by QtCreator 2013-12-18T19:31:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Phy
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Edge.cpp \
    Gauss.cpp \
    Node.cpp

HEADERS  += mainwindow.h \
    Gauss.h \
    Edge.h \
    Node.h

FORMS    += mainwindow.ui
