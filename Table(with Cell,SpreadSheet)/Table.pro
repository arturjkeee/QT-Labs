#-------------------------------------------------
#
# Project created by QtCreator 2023-03-17T12:29:15
#
#-------------------------------------------------

QT       += core gui\
        core5compat

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Table
TEMPLATE = app


SOURCES += main.cpp\
       cell.cpp \
       mainwindow.cpp \
       spreadsheet.cpp

HEADERS  +=  mainwindow.h \
    cell.h \
    spreadsheet.h

FORMS    += mainwindow.ui

RESOURCES += \
    Resources.qrc
