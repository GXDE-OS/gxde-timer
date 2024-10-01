#-------------------------------------------------
#
# Project created by QtCreator 2019-06-30T12:53:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gxde-timer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    widget.cpp \
    mainwindow.cpp

HEADERS  += mainwindow.h \
    widget.h

CONFIG += link_pkgconfig
PKGCONFIG += dtkwidget

CONFIG += c++11

FORMS += \
    widget.ui

RESOURCES +=

isEmpty(PREFIX){
    PREFIX = /usr
}

BINDIR = $$PREFIX/bin
APPSHAREDIR = $$PREFIX/share/

target.path = $$BINDIR

desktopOpt.path = /opt/apps/gxde-timer/entries/applications/
desktopOpt.files = $$PWD/gxde-timer.desktop

desktop.path = $$PREFIX/share/applications/
desktop.files = $$PWD/gxde-timer.desktop

# 支持在 GXDE 助手内显示
desktopAssistant.path = $$APPSHAREDIR/gxde/gxde-system-assistant/tool-extensions
desktopAssistant.files = $$PWD/gxde-timer.desktop

icons.path = $$APPSHAREDIR/icons
icons.files = $$PWD/gxde-timer.png

INSTALLS = target icons desktopAssistant #desktopOpt desktop 
