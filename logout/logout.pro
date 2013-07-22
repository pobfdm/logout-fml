#-------------------------------------------------
#
# Project created by QtCreator 2013-06-21T10:06:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = logout-fml
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
TRANSLATIONS = logout-it_IT.ts

#Binary build dir
DESTDIR = ../bin/

#Install main binary
target.files = ../bin/logout-fml
target.path = /usr/bin
INSTALLS += target

#install share
data.files = ../share/*
data.path = /usr/share/
INSTALLS += data

#install .desktop
menu.files = ../logout.desktop
menu.path = /usr/share/applications
INSTALLS += menu

RESOURCES += \
    resource.qrc
