#-------------------------------------------------
#
# Project created by QtCreator 2014-11-07T11:44:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets core

TARGET = qsteg
TEMPLATE = app


SOURCES += src/main.cpp\
           src/qsteg.cpp \
           src/aboutwindow.cpp

HEADERS  += src/qsteg.h \
            src/aboutwindow.h

FORMS    += res/qsteg.ui \
            res/aboutwindow.ui
