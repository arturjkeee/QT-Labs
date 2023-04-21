#-------------------------------------------------
#
# Project created by QtCreator 2023-03-17T12:29:15
#
#-------------------------------------------------

QT       += core gui\
        core5compat

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = Table
TEMPLATE = app


SOURCES += main.cpp\
    dialog.cpp \
    finddialog.cpp \
    mainwindow.cpp \
    cell.cpp \
    sort.cpp \
    spreadsheet.cpp

HEADERS  += mainwindow.h \
    cell.h \
    dialog.h \
    finddialog.h \
    sort.h \
    spreadsheet.h

FORMS    += mainwindow.ui \
    dialog.ui \
    sort.ui

RESOURCES += \
    Resources.qrc
