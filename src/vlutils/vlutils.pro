#-------------------------------------------------
#
# Project created by QtCreator 2016-11-22T02:34:20
#
#-------------------------------------------------

QT       += widgets

TARGET = vlutils
TEMPLATE = lib

DEFINES += VLUTILS_LIBRARY

SOURCES += vlutils.cpp \
    mainwindow.cpp \
    tabbar.cpp \
    menubar.cpp \
    newtab.cpp \
    selectiontreemodel.cpp \
    selectiontreeitem.cpp

HEADERS += vlutils.h\
        vlutils_global.h \
    mainwindow.h \
    tabbar.h \
    menubar.h \
    newtab.h \
    selectiontreemodel.h \
    selectiontreeitem.h

OBJECTS_DIR=$$top_srcdir/build/vlutils #Intermediate object files directory
MOC_DIR=$$top_srcdir/build/vlutils #Intermediate moc files directory

DESTDIR=$$top_srcdir/lib

unix {
    target.path = /usr/lib
    INSTALLS += target
}
