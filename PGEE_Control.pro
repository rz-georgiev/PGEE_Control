#-------------------------------------------------
#
# Project created by QtCreator 2013-04-03T16:30:55
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport
QT       += sql
QT       += multimedia multimediawidgets

QMAKE_CXXFLAGS_WARN_OFF -= -Wunused-parameter

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PGEE_Control
TEMPLATE = app


SOURCES += main.cpp\
        logonmenu.cpp \
    mainwindow.cpp \
    nstudentdialog.cpp \
    cameraclass.cpp \
    listwithstudents.cpp \
    electronicaldiary.cpp \
    notesforstudents.cpp \
    electronicaldiary_write.cpp \
    forpgee.cpp \
    changeinformationdialog.cpp \
    timerencryptiondialog.cpp

HEADERS  += logonmenu.h \
    mainwindow.h \
    nstudentdialog.h \
    cameraclass.h \
    listwithstudents.h \
    electronicaldiary.h \
    notesforstudents.h \
    electronicaldiary_write.h \
    forpgee.h \
    changeinformationdialog.h \
    timerencryptiondialog.h

FORMS    += logonmenu.ui \
    mainwindow.ui \
    nstudentdialog.ui \
    cameraclass.ui \
    listwithstudents.ui \
    electronicaldiary.ui \
    notesforstudents.ui \
    electronicaldiary_write.ui \
    forpgee.ui \
    changeinformationdialog.ui \
    timerencryptiondialog.ui

RESOURCES += \
    MainResources.qrc



