#-------------------------------------------------
#
# Project created by QtCreator 2015-05-26T10:17:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2048
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    result.cpp

HEADERS  += mainwindow.h \
    game.h \
    result.h

FORMS    += \
    mainwindow.ui \
    game.ui \
    result.ui

RESOURCES += \
    picture.qrc
