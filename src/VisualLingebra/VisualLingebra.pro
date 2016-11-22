#-------------------------------------------------
#
# Project created by QtCreator 2016-11-21T01:47:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VisualLingebra
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

CONFIG(release, debug|release) {
  DESTDIR=$$top_srcdir/bin
}
CONFIG(debug, debug|release) {
  DESTDIR=$$top_srcdir/debug
}
 #Target file directory
OBJECTS_DIR=$$top_srcdir/build #Intermediate object files directory
MOC_DIR=$$top_srcdir/build #Intermediate moc files directory
