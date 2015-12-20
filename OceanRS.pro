#-------------------------------------------------
#
# Project created by QtCreator 2015-10-14T19:14:00
#
#-------------------------------------------------

QT       += core gui multimedia
QT       += axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OceanRS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindlg.cpp \
    ronghe.cpp \
    pushbutton.cpp \
    forecast.cpp \
    display.cpp \
    selectfile.cpp \
    demo.cpp

HEADERS  += mainwindow.h \
    logindlg.h \
    ronghe.h \
    pushbutton.h \
    forecast.h \
    display.h \
    selectfile.h \
    demo.h

FORMS    += mainwindow.ui \
    logindlg.ui \
    ronghe.ui \
    forecast.ui \
    display.ui \
    selectfile.ui \
    demo.ui


RESOURCES += \
    res.qrc
